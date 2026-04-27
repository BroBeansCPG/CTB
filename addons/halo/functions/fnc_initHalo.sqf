params ["_logic", "_alt", "_terminal"];

_logicPos = getPos _logic;

private _helper = createVehicle ["VR_3DSelector_01_default_F", [_logicPos # 0, _logicPos #1, _alt]];
_helper setVectorDirAndUp [[0,1,0], [0,0,1]];
_helper hideObjectGlobal true;

private _plane = (synchronizedObjects _logic) # 0;

_plane setPosASL [_logicPos # 0, _logicPos #1, _alt];

_plane attachTo [_helper, [0,0,0]];

_action = [
    "CTB_Halo", 
    "Transport Group to Aircraft", 
    "", 
    {
        // _target is the terminal, _player is the user, _params is what we passed below
        params ["_target", "_player", "_params"];
        _params params ["_plane"]; 
        [_plane, _player] call ctb_halo_fnc_sendToPlane;
    }, 
    {true},
    {},
    [_plane] // Passing the plane reference into the action scope
] call ace_interact_menu_fnc_createAction;
[_terminal, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;