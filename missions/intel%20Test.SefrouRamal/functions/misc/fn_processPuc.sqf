params ["_puc"];

_side = side group _puc;
if (_side isEqualTo West) exitWith {}; //exit if blufor

_val = _puc getVariable ["bb_intelLevel", 0]; //grab intel value
systemChat format ["called process prisoner for %1", _puc];

deleteVehicle _puc;

if (_val > 0.9) then {
	systemChat format ["intel value: %1", _val];
} else {
	systemChat "no intel value";
};
BB_intelCount = BB_intelCount + _val;
BB_intelCount