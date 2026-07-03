class cfgVehicles {
    class Helicopter_Base_F;
	class RHS_MELB_base: Helicopter_Base_F {
		class Components;
		class Turrets;
		class AnimationSources;
		class Attributes;
	};
	class RHS_MELB_AH6M: RHS_MELB_base {
		editorPreview="rhsusf\addons\rhsusf_editorPreviews\data\rhs_MELB_AH6M.paa";
		scope=2;
		forceInGarage=1;
		author="$STR_RHSUSF_AUTHOR_FULL";
		dlc="RHS_USAF";
		picture="rhsusf\addons\rhsusf_melb\Data\ui\melb_ah_6m_ca.paa";
		icon="rhsusf\addons\rhsusf_melb\Data\ui\map_melb_ah_6m_l_ca.paa";
		displayName="AH-6M Little Bird 1TRP";
		class Components: Components
		{
			class TransportPylonsComponent
			{
				UIPicture="\rhsusf\addons\rhsusf_melb\data\loadouts\RHS_AH6M_EDEN_CA.paa";
				class pylons
				{
					class pylon1
					{
						hardpoints[]=
						{
							"RHS_HP_MELB",
							"RHS_HP_MELB_L",
							"HSC_hydra70_A",
							"HSC_hellfire_L"
						};
						priority=2;
						attachment="rhs_mag_M151_7";
						maxweight=1200;
						UIposition[]={0.625,0.2};
						bay=-1;
						turret[]={};
						hitpoint="HitPylon1";
					};
					class pylon2: pylon1
					{
						hardpoints[]=
						{
							"RHS_HP_MELB_M134",
							"RHS_HP_MELB"
						};
						UIposition[]={0.56199998,0.30000001};
						priority=1;
						attachment="RS_MH6V3_mag_m134_pylon_3000";
						turret[]={};
						hitpoint="HitPylon2";
					};
					class pylon3: pylon2
					{
						UIposition[]={0.103,0.30000001};
						mirroredMissilePos=2;
						attachment="RS_MH6V3_mag_m134_pylon_3000";
						turret[]={};
						hitpoint="HitPylon3";
					};
					class pylon4: pylon1
					{
						hardpoints[]=
						{
							"RHS_HP_MELB",
							"RHS_HP_MELB_R",
              				"HSC_hydra70_A",
							"HSC_hellfire_R"
						};
						UIposition[]={0.039999999,0.2};
						mirroredMissilePos=1;
						turret[]={};
						hitpoint="HitPylon4";
					};
					class pylon5: pylon1
					{
						hardpoints[]=
						{
			  				"HSC_hydra70_B",
							"HSC_hellfire_R"
						};
						UIposition[]={0.625,0.25};
						mirroredMissilePos=1;
						turret[]={};
						hitpoint="HitPylon1";
					};
					class pylon6: pylon5
					{
						hardpoints[]=
						{
							"HSC_hydra70_B",
							"HSC_hellfire_L"
						};
						UIposition[]={0.039999999,0.25};
						mirroredMissilePos=1;
						turret[]={};
						hitpoint="HitPylon4";
					};
				};
				class Presets
				{
					class Light
					{
						attachment[]=
						{
							"rhs_mag_M151_7",
							"RS_MH6V3_mag_m134_pylon_3000",
							"RS_MH6V3_mag_m134_pylon_3000",
							"rhs_mag_M151_7"
						};
						displayname="Light";
					};
					class Medium
					{
						attachment[]=
						{
							"rhsusf_mag_gau19_melb_left",
							"",
							"",
							"rhs_mag_M151_19"
						};
						displayname="Medium";
					};
					class HEAT
					{
						attachment[]=
						{
							"RS_MH6V3_mag_Hydra_HEAT_7",
							"RS_MH6V3_mag_m134_pylon_3000",
							"RS_MH6V3_mag_m134_pylon_3000",
							"RS_MH6V3_mag_Hydra_HEAT_7"
						};
						displayname="HEAT";
					};
					class Heavy
					{
						attachment[]=
						{
							"rhsusf_mag_gau19_melb_left",
							"",
							"",
							"rhs_mag_AGM114K_2"
						};
						displayname="Heavy";
					};
				};
			};
		};
	};
};