params ["_composableMap"];

_masterMode = _composableMap get "MasterMode";
_focus = _composableMap getOrDefault ["Focus", "100MRAD"];
_macro = _composableMap get "__BETTIR_MACRO";
_device = _composableMap get "Device";

// if the device is flashlight, in our case it's the same as the macroClass + "_light" suffix
if (_device == "Flashlight") exitWith { (_macro + "_light") };

// as mentioned above, Aim High mode is not listed in the className, and the macro matches the base class anyways
if (_masterMode == "AH") exitWith { _macro };

// create an array with the segments of the className
_finalClassNameArray = [
    _macro,
    _masterMode
];

// if the mastermode has an illuminator, append the divergence
if (_masterMode in ["IH", "DH", "DL"]) then {
    _finalClassNameArray pushBack _focus;
};

// join the string into a className
_finalClassName = _finalClassNameArray joinString "_";

// return
_finalClassName;
