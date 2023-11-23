#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		name = CSTRING(component);
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"CBA_main"};
		author = "CTBois";
		VERSION_CONFIG;
	};
};