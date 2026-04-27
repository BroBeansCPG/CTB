params ["_vehicle"];
if !(_vehicle isKindOf "Air") exitWith {systemChat "not air vehicle"};

_vehicle addEventHandler ["GetIn",  { 
	params ["_vehicle", "_seat", "_unit"];

	if (_seat == "cargo") exitWith {};
	if (_seat == "driver" && !(_unit isKindOf 'B_Pilot_F')) then {  
		moveOut _unit;
		hint "Skill issue!";
	} else { 
		_copilot = [_unit] call bb_fnc_isCopilot;
		if (_copilot) then {moveOut _unit;
		hint "Skill issue!";};
	};  
}];  