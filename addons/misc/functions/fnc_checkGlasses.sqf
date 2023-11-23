if !(hasInterface) exitWith {};

_blacklist = ctb_noGlasses;
_blacklist = toLower _blacklist; 
_blacklist = _blacklist splitString "[,""']";
_goggles = goggles player;
_goggles = toLower _goggles;

if (_goggles in _blacklist) then {removeGoggles player;};