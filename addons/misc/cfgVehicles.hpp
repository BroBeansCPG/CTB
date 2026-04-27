class cfgVehicles {
  class Tank;
  class Car_F;
  class rhs_bmp_base;
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
};