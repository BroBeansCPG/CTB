params ["_className"];

_upperClassName = toUpper _className;

_map = createHashMap;

_splitClassName = _upperClassName splitString "_";

_splitClassNameLength = count _splitClassName;

_lastEntry = _splitClassName # (_splitClassNameLength - 1);

if ((_lastEntry find "MRAD") != -1) then {
    _map set ["Focus", _lastEntry];
    _map set ["MasterMode", _splitClassName # (_splitClassNameLength - 2)];
} else {
    if (_lastEntry in ["VIS", "DVIS", "LIGHT", "AL"]) then {
        _map set ["MasterMode", _lastEntry];
    } else {
        _map set ["MasterMode", "AH"];
    };
};

_map;