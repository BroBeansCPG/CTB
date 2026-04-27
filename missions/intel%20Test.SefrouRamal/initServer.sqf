//Global stores
bb_debug = true;

BB_intelProb = 0.25;
BB_intelCount = profileNamespace getVariable [("BB_intelCount" + missionName), 0];
BB_intelItems = ["PropCamera_lxWS", "FlashDisk", "Files", "DocumentsSecret", "Wallet_ID", "Money_roll", "Money_stack", "Money", "MobilePhone", "SmartPhone", "Keys"];
BB_specialIntelItems = ["Laptop_Unfolded", "Laptop_Closed"];
BB_caches = profileNamespace getVariable [("BB_Caches" + missionName), []]; //Loads cache locations from previous session to insure caches aren't respawned.
if (BB_debug) then {systemChat format ["Loaded caches, %1", BB_Caches]};


BB_Veh = 
[
	"O_SFIA_Offroad_lxWS", 
	"O_Tura_Offroad_armor_lxWS"
];
BB_Enemy = 
[
	"O_Tura_enforcer_lxWS", 
	"O_Tura_deserter_lxWS", 
	"O_Tura_watcher_lxWS", 
	"O_Tura_medic2_lxWS", 
	"O_Tura_defector_lxWS", 
	"O_Tura_thug_lxWS"
];

//Do mission setup
if (count BB_Caches < 1) then { //Change this to use cache locations instead of objects, then find nearest crate to cash and add destroyed event handler to remove cache after players destroy it. 
	_caches = entities "Box_FIA_Support_F";
	BB_Caches = BB_Caches + _caches;
	_update = profileNamespace setVariable [("BB_Caches" + missionName), BB_caches];
	if (BB_DEBUG) then {systemChat format ["Updated Cache Items", BB_Caches]};
};

//Detect/Create cache items in cache zones & add event handler to handle mission update when destroyed. 
//
//

//Add pilot restrictions
{
	[_x] call bb_fnc_addPilotRestrictions;
} forEach entities "AIR";
if (BB_DEBUG) then {systemChat format ["Added Pilot Restrictions"]};

//Add interaction to intel lappy
_intelAction = ["HandoverIntel","Handover Intel","",{[_player] call bb_fnc_processIntel},{true},{}] call ace_interact_menu_fnc_createAction; 
[intelLaptop, 0, ["ACE_MainActions"], _intelAction] call ace_interact_menu_fnc_addActionToObject;

//add captive event handler
_puc = ["ace_captives_setHandcuffed", 
{ 
    params ["_puc", "_state"]; 
    _side = side group _puc;
    if (_state) then {
    [_state, _puc, _side] call bb_fnc_addIntelToPUC};
}] call cba_fnc_addEventHandler;

//add respawn blocker
_bodies = ["ace_placedInBodyBag", 
{
    params ["_patient", "_bag"]; 
    _name = [_patient] call ace_common_fnc_getName;
	if (BB_debug) then {systemChat format ["%1 is placed in the bag", _name]};
    _bag setVariable ["bodyBag_deceasedName", _name];
	if (isPlayer _patient) then {_bag setVariable ["bodyBag_isPlayer", true];};
}] call CBA_fnc_addEventHandler;

//create respawn hashmap
BB_playerStatusList = createHashMap;