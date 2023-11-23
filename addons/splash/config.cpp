#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		name = CSTRING(component);
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"ctb_main", "A3_Data_F_AoW_Loadorder"};
		author = "CTBois";
		VERSION_CONFIG;
	};
};

class CfgMainMenuSpotlight
{
	class ctb_joinServer_1
	{
		text = "";
        picture = QPATHTOF(data\MissionPlanLogo.paa);
		action = "connectToServer ['103.62.51.7', 2652, 'pizza']";
		actionText = "Join the CTB Mission Server";
		condition = "true";
	};
	class ctb_joinServer_2: ctb_joinServer_1
	{
        picture = QPATHTOF(data\fukfuk.paa);
	};
	//Hide others
	delete Tanks_Campaign_01;
	delete Bootcamp;
	delete EastWind;
	delete ApexProtocol;
	delete OldMan;
	delete SP_FD14;
	delete Orange_CampaignGerman;
	delete Orange_Campaign;
	delete Orange_Showcase_IDAP;
	delete Orange_Showcase_LoW;
	delete Contact_Campaign;
	delete AoW_Showcase_AoW;
	delete AoW_Showcase_Future;
	delete Tacops_Campaign_03;
	delete Tacops_Campaign_02;
	delete Tacops_Campaign_01;
};