params ["_composableMap"];

_masterMode = _composableMap get "MasterMode";
_focus = _composableMap getOrDefault ["Focus", "100MRAD"];
_macro = _composableMap get "__BETTIR_MACRO";

if (_masterMode == "AH") exitWith { _macro };

_finalClassNameArray = [
    _macro,
    _masterMode
];

if (_masterMode in ["DL", "DH"]) then {
    _finalClassNameArray pushBack _focus;
};

_finalClassName = _finalClassNameArray joinString "_";

_finalClassName;