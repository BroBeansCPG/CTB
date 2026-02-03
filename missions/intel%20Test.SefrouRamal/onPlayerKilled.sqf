_name = [player] call ace_common_fnc_getName;
_updateHashmap = BB_playerStatusList set [_name, false];
if (BB_Debug) then {
	systemChat format ["%1", _updateHashmap];
	systemChat format ["%1", BB_playerStatusList];
};