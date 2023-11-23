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