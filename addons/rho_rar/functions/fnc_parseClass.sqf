params ["_className"];

// convert to uppercase for easier comparison
_upperClassName = toUpper _className;
_map = createHashMap;

_splitClassName = _upperClassName splitString "_";
_splitClassNameLength = count _splitClassName;
_lastEntry = _splitClassName # (_splitClassNameLength - 1);

// account for the flashlight variant first
if (_lastEntry == "LIGHT") then {
    _map set ["Device", "Flashlight"]; 
} else {
    // otherwise, we know the device is Laser
    _map set ["Device", "Laser"];
    // if the word MRAD exists at the end, it's surely a Focus setting, and the mastermode precedes it
    if ((_lastEntry find "MRAD") != -1) then {
        _map set ["Focus", _lastEntry];
        _map set ["MasterMode", _splitClassName # (_splitClassNameLength - 2)];
    } else {
        // check if mastermode is the last entry, otherwise assume aim high
        if (_lastEntry in ["VIS", "AL"]) then {
            _map set ["MasterMode", _lastEntry];
        } else {
            _map set ["MasterMode", "AH"];
        };
    };
};

// return the map to BettIR
_map;
