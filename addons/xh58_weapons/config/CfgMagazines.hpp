class CfgMagazines {
    class 500Rnd_127x99_mag;
    class PylonRack_4Rnd_ACE_Hellfire_AGM114K;
    class 6Rnd_Missile_AGM_02_F;
    class PylonRack_1Rnd_Missile_AA_04_F;

    class HSC_127_500 :500Rnd_127x99_mag
    {
        displayName      = "FN M3P";
        descriptionShort = "FN M3P is a 50. machine gun with a fire rate almost twice that of the M2 Browning, comes with 500 rounds of ammo";
        pylonWeapon      = "HSC_m3p";
        model            = "\A3\Weapons_F\DynamicLoadout\PylonPod_Twin_Cannon_20mm.p3d"; //temp
        hardpoints[]     = {"HSC_M3P"}; \
    };

    #define HELLFIRE_MAGAZINE_CONFIG(ammoname, disp, descShort) \
        class ammoname##_base: PylonRack_4Rnd_ACE_Hellfire_AGM114K {\
            descriptionShort = QUOTE(descShort);\
            ammo             = QUOTE(ammoname);\
            displayName      = QUOTE(disp); \
            count            = 1; \
            pylonWeapon      = QUOTE(ammoname##_wep); \
            muzzlePos        = "muzzlepos"; \
            muzzleEnd        = "muzzleend"; \
            sound[]          = {"A3\sounds_f\dummysound", 3.16228, 1}; \
            reloadSound[]    = {"A3\sounds_f\dummysound", 0.000316228, 1}; \
            weight           = 62.94; \
            HSC_pylonType    = "hellfire"; \
        };\
        class ammoname##_L: ammoname##_base { \
            scope        = 2;\
            model        = "\xh58_weapons\HSC_m310_l.p3d"; \
            hardpoints[] = {"HSC_hellfire_L"}; \
        }; \
        class ammoname##_R: ammoname##_base { \
            scope        = 2;\
            model        = "\xh58_weapons\HSC_m310_r.p3d"; \
            hardpoints[] = {"HSC_hellfire_R"}; \
        };
    HELLFIRE_MAGAZINE_CONFIG(HSC_agm114k,   AGM-114K, SAL 2 Guidance Max range - 8km. This is the most advanced model of all the laser guided hellfires available.)
    HELLFIRE_MAGAZINE_CONFIG(HSC_agm114n,   AGM-114N, SAL 2 Guidance Max range - 8km. The N variant is a K model with a thermobaric warhead. It is very deadly when used against hardened targets.)

    #define ROCKET_MAGAZINE_CONFIG(ammoname, disp, dispShort) \
        class ammoname##_zoneA: 6Rnd_Missile_AGM_02_F { \
            scope            = 2;\
            ammo             = QUOTE(ammoname); \
            displayName      = QUOTE(disp); \
            descriptionShort = QUOTE(dispShort); \
            model            = "\xh58_weapons\HSC_m260_zoneA.p3d"; \
            count            = 4; \
            hardpoints[]     = {"HSC_hydra70_A"}; \
            pylonWeapon      = QUOTE(ammoname##_wep); \
            muzzlePos        = "muzzlepos"; \
            muzzleEnd        = "muzzleend"; \
            sound[]          = {"A3\sounds_f\weapons\rockets\explosion_missile_01", 1, 1, 1200};\
            reloadSound[]    = {"A3\sounds_f\dummysound", 0.000316228, 1}; \
            weight           = 50.02; \
            HSC_pylonType    = "rocket"; \
        }; \
        class ammoname##_zoneB: ammoname##_zoneA { \
            scope        = 2;\
            model        = "\xh58_weapons\HSC_m260_zoneB.p3d"; \
            hardpoints[] = {"HSC_hydra70_B"}; \
            count        = 3; \
            weight       = 37.51;\
        }; \
    
    ROCKET_MAGAZINE_CONFIG(HSC_275_m151, M151 HEDP, The M151 warhead is a 10 pound warhead with a pre-fragmented shell. It is effective against light armored vehicles and personnel. It is mounted to a Mark 66 Mod 6 rocket motor with an effective range of 5km.)
    ROCKET_MAGAZINE_CONFIG(HSC_275_m255a1, M255A1 FLEC, The M255 warhead is a submunition rocket with over 1000 60 grain flechettes. These are effective against personnel with moderate effectiveness against unarmored vehicles. It is mounted to a Mark 66 Mod 6 rocket motor with an effective range of 5km.)
    ROCKET_MAGAZINE_CONFIG(HSC_275_m261, M261 MPSM, The M261 warhead is a submunition rocket with 9 parachute-retarded munitions. These are effective against both personnel and light armored vehicles. It is mounted to a Mark 66 Mod 6 rocket motor with an effective range of 5km.)
    ROCKET_MAGAZINE_CONFIG(HSC_275_m257, M257 IL, The M257 is an illumination warhead containing a parachute flare. It can illuminate an area of a square kilometer for approximately 100 seconds. It is mounted to a Mark 66 Mod 6 rocket motor with a trigger distance of 3.5km.)
    ROCKET_MAGAZINE_CONFIG(HSC_275_m278, M278 IR IL, The M278 is an IR illumination warhead containing a parachute flare. It can illuminate an area of a square kilometer for approximately 100 seconds. It is mounted to a Mark 66 Mod 6 rocket motor with a trigger distance of 3.5km.)
    
    class HSC_atas: PylonRack_1Rnd_Missile_AA_04_F
    {
        scope            = 2;
        count            = 2;
        displayName      = "FIM-92E";
        descriptionShort = "IR Guidance, Max range - 8km";
        ammo             = "HSC_fim92";
        sound[]          = {"A3\sounds_f\dummysound", 3.16228, 1};
        reloadSound[]    = {"A3\sounds_f\dummysound", 0.000316228, 1};
        weight           = 60;		
        hardpoints[]     = {"HSC_ATAS"};
        pylonWeapon      = "HSC_atas";
    };
};