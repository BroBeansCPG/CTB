#include "script_component.hpp"

class CfgPatches {
	class SUBADDON {
		name = CSTRING(component);
    addonRootClass = QUOTE(COMPONENT);
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"ctb_main", "loadorder_f_vietnam"};
		author = "CTBois";
    skipWhenMissingDependencies = 1;
		VERSION_CONFIG;
	};
};

class CfgMainMenuSpotlight
{
  delete vn_showcase_macv;
  delete vn_showcase_macv_13;
  delete vn_showcase_pavn;
  delete vn_showcase_pavn_13;
  delete vn_sogba;
};