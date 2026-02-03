
params ["_unit"];
_reg = 0;
_spesh = 0;


_reg = {_x in BB_intelItems} count (magazines _unit);
_spesh = {_x in BB_specialIntelItems} count (magazines _unit);

_intelCount = _reg + _spesh;
if (_intelCount == 0) exitWith {
	systemChat "You don't have any intel!";
};
{
	_unit removeMagazineGlobal _x;
} forEach BB_intelItems + BB_specialIntelItems;

if !(_reg == 0) then {
	for "_i" from 1 to _reg do {
		_add = selectRandomWeighted [1, bb_intelProb, 0, (1 - bb_intelProb)];
		systemChat format ["%1", _add];
		bb_intelCount = bb_intelCount + _add;
	};
};

bb_intelCount = bb_intelCount + _spesh;

if (_intelCount > 1) then {
	SystemChat format ["You handed in %1 pieces of intel, that's now a total of %2 useable pieces.",_intelCount, bb_intelCount]; 
} else {
	SystemChat format ["You handed in %1 piece of intel, that's now a total of %2 useable pieces.",_intelCount, bb_intelCount]; 
};




//Do shit at thresholds after 5 minutes to simulate processing intel
sleep 300;
_n = bb_intelCount;
switch true do {
	case (_n >= 5 && _n < 10): {systemChat "Spawning mission 1."}; 
	case (_n >= 10 && _n < 15): {systemChat "Spawning mission 2."};
	case (_n >= 15 && _n < 20): {systemChat "Spawning mission 3."};
	case (_n >= 20 && _n < 25): {systemChat "Spawning mission 4."}
};