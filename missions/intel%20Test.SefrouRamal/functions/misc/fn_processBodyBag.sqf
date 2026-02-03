params ["_objects"];

{
	systemChat format ["running on %1", _x];
	if (typeOf _x isEqualTo "ACE_bodyBagObject") then {
	_name = _x getVariable ["bodyBag_deceasedName", "error"]; //grab patient
	if (_x getVariable ["bodyBag_isPlayer", false]) then {_updateHashmap = BB_playerStatusList set [_name, true]; if (BB_debug) then {systemChat format ["%1", BB_playerStatusList]}} else {if (BB_debug) then {systemChat format ["Check ID of: %1", _name]}};
	deleteVehicle _x;
	};
} forEach _objects;
