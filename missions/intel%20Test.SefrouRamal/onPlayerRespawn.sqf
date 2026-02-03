_name = [player] call ace_common_fnc_getName;
_canRespawn = BB_playerStatusList getOrDefault [_name, true];

if (_canRespawn) exitWith {};
systemChat format ["%1 you're being kicked until your body can be recovered", _name];
serverCommand format ["#kick %1", _name]; //Kick 