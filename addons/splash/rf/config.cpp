#include "script_component.hpp"

class CfgPatches {
	class SUBADDON {
		name = CSTRING(component);
    	addonRootClass = QUOTE(COMPONENT);
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"ctb_main", "RF_Data_Loadorder"};
		author = "CTBois";
    	skipWhenMissingDependencies = 1;
		VERSION_CONFIG;
	};
};

class CfgMainMenuSpotlight
{
  delete Scenario_AirControl_RF;
  delete Scenario_FireSeason_RF;
  delete Scenario_TrainingDay_RF;
};