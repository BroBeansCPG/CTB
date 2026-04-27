

params ["_state", "_puc", "_side"];
if !(_state) exitWith {};

_currentIntel = _puc getVariable ["BB_intelLevel", 0];
if (_currentIntel > 0.6) exitWith {};

_nearest = [BB_Caches, _puc] call BIS_fnc_nearestPosition;
_dis = _puc distance _nearest;
private _intelModifer = (_dis / 500);

private _intelLevel = -1;
if (_side == EAST) then {
	_intelLevel = [0, 1, 2] selectRandomWeighted [0.7 - bb_intelProb, bb_intelProb / _intelModifer, 0.05];
} else {
	_intelLevel = [0, 1, 2] selectRandomWeighted [0.95 - bb_intelProb, bb_intelProb / _intelModifer, 0];
};

if (BB_debug) then {systemChat format ["Intel Level of PUC: %1", _intelLevel]};
_puc setVariable ["BB_intelLevel", _intelLevel];
_intelLevel