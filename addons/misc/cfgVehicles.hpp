class cfgVehicles {
  class Tank;
  class Car_F;
  class rhs_bmp_base;
  class rhsusf_stryker_base;
  class APC_Tracked_03_base_F;
  class APC_Tracked_02_base_F;

  class Tank_F: Tank {
	  ace_hunterkiller = 1;
  };
  class Wheeled_APC_F: Car_F {
	  ace_hunterkiller = 1;
  };
  class APC_Tracked_01_base_F: Tank_F {
	  ace_hunterkiller = 1;
  };
  class rhs_bmp1_vdv: rhs_bmp_base {
    ace_hunterkiller[] = {{{0}, 1}, {{0,0}, 1}};
  };
  class rhsusf_stryker_m1126_base: rhsusf_stryker_base {
	cargoDoors[] = {};
  };
  class RHS_M2A2_Base: APC_Tracked_03_base_F {
	cargoDoors[] = {};
  };
  class rhsusf_m113tank_base: APC_Tracked_02_base_F {
	cargoDoors[] = {};
  };
};
class cfgAmmo {
  class Sh_125mm_APFSDS;
  class rhs_ammo_30x113mm_M789_HEDP_penetrator: Sh_125mm_APFSDS
	{
		CraterEffects="30mmSmoke";
		explosionEffects="30mmExplode";
		class HitEffects
		{
			hitVirtual="ImpactMetalSabotBig";
			hitMetal="ImpactMetalSabotBig";
			hitMetalPlate="ImpactMetalSabotBig";
			hitBuilding="BCImpactConcrete_30mm";
			hitConcrete="BCImpactConcrete_30mm";
			hitGroundSoft="BCImpactDirt_30mm";
			hitGroundHard="BCImpactDirt_30mm";
			default_mat="BCImpactDirt_30mm";
			Hit_Foliage_green="BCImpactDirt_30mm";
			Hit_Foliage_Dead="BCImpactDirt_30mm";
			Hit_Foliage_Green_big="BCImpactDirt_30mm";
			Hit_Foliage_Palm="BCImpactDirt_30mm";
			Hit_Foliage_Pine="BCImpactDirt_30mm";
		};
	};
	class missileBase;
	class rhs_ammo_DAGR: missileBase
	{
		class ace_missileguidance {
			enabled = 1;
			attackProfiles[] = {"LIN","DIR","MID","HI"};
			canVanillaLock = 0;
			defaultAttackProfile = "LIN";
			defaultNavigationType = "AugmentedProportionalNavigation";
			defaultSeekerLockMode = "LOAL";
			defaultSeekerType = "SALH";
			navigationTypes[] = {"AugmentedProportionalNavigation"};
			pitchRate = 40;
			seekerAccuracy = 1;
			seekerAngle = 90;
			seekerLockModes[] = {"LOAL","LOBL"};
			seekerMaxRange = 3500;
			seekerMinRange = 1;
			seekerTypes[] = {"SALH"};
			yawRate = 40;
		};
	};
};
