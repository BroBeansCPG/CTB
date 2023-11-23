#include "script_component.hpp"

class CfgPatches {
	class SUBADDON {
		name = CSTRING(component);
    addonRootClass = QUOTE(COMPONENT);
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"ctb_main", "data_f_lxWS_Loadorder"};
		author = "CTBois";
    skipWhenMissingDependencies = 1;
		VERSION_CONFIG;
	};
};

class CfgMainMenuSpotlight
{
  class ctb_joinServer_1;
  class ctb_joinServer_ws: ctb_joinServer_1
	{
		picture = QPATHTOF(data\airborne.paa);
    video = "lxws\missions_f_lxws\Video\spotlight_extraction.ogv";
	};
  delete Extraction_lxWS;
	delete Showcase_Alchemist_lxWS;
	delete Showcase_VR_lxWS;
};