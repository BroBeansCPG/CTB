#include "script_component.hpp"

class CfgPatches {
	class SUBADDON {
		name = CSTRING(component);
    addonRootClass = QUOTE(COMPONENT);
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"ctb_main", "WW2_SPE_Missions_p_Cutscene_p"};
		author = "CTBois";
    skipWhenMissingDependencies = 1;
		VERSION_CONFIG;
	};
};

class CfgMainMenuSpotlight
{
  delete SPE_Arsenal;
  delete SPE_Campagin_OperationCobra_04;
  delete SPE_Coop_Der_Zahnarzt;
  delete SPE_Coop_Attack_on_Mortain;
  delete SPE_Coop_Battle_of_St_Barthelemy;
  delete SPE_Coop_Panzerkampfwagen;
  delete SPE_Coop_Prizefighter;
  delete SPE_Faction_Showcase_GER;
  delete SPE_Faction_Showcase_US;
};