#include "script_component.hpp"

class CfgPatches {
	class SUBADDON {
		name = CSTRING(component);
    addonRootClass = QUOTE(COMPONENT);
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"ctb_main", "gm_characters_xx_revolutionaries"};
		author = "CTBois";
    skipWhenMissingDependencies = 1;
		VERSION_CONFIG;
	};
};

class CfgMainMenuSpotlight
{
  delete gm_campaign_01;
};