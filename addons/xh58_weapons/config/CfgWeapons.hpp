class CfgWeapons {
    class HMG_127;
    class ace_hellfire_launcher;
    class RocketPods;
    class Missile_AA_04_Plane_CAS_01_F;

    class HSC_m3p: HMG_127
    {
        displayName      = "FN M3P";
        scope            = 1;
        maxZeroing       = 6500;
        magazines[]      = {"HSC_127_500"};
        reloadTime       = 0.075;
    };

    class HSC_hellfire: ace_hellfire_launcher
    {
        scope                 = 0;
        ace_laser_showHud     = 0;
        displayName           ="AGM-114";
        cursor                = "EmptyCursor";
        cursorAim             = "EmptyCursor";
        ace_overpressure_angle  = 50;
        ace_overpressure_range  = 12;
        ace_overpressure_damage = 0.7;
        ace_overpressure_offset = 1;
    };
    #define HELLFIRE_MAGAZINES(ammoName) QUOTE(ammoName##_L), QUOTE(ammoName##_R)
    #define HELLFIRE_WEAPON_CONFIG(ammoName,prettyName) \
        class ammoName##_wep : HSC_hellfire {\
            scope        = 1;\
            displayName  = QUOTE(prettyName);\
            magazines[]  = {HELLFIRE_MAGAZINES(ammoName)};\
            HSC_ammoType = QUOTE(ammoName);\
        };
    HELLFIRE_WEAPON_CONFIG(HSC_agm114k,AGM-114K)
    HELLFIRE_WEAPON_CONFIG(HSC_agm114n,AGM-114N)
    
    class HSC_hydra70: RocketPods
    {
        scope       = 0;
        displayName ="M261";
        magazines[] ={};
        modes[]     = {"Single"};
        canLock     = 0;
        cursor      = "EmptyCursor";
        cursorAim   = "EmptyCursor";
        weight      = 80;

        //ACE CFG
        ace_overpressure_angle = 50;
        ace_overpressure_range = 5;
        ace_overpressure_damage = 0.4;
        ace_overpressure_offset = 1;

        class Single: RocketPods
        {
            displayName="M261";
            soundContinuous = 0;
            autoFire = 0;
            dispersion = 0.0025;
            textureType = "semi";
        };
    };
    #define ROCKET_MAGAZINES(ammoName) QUOTE(ammoName##_zoneA), QUOTE(ammoName##_zoneB)
    #define ROCKET_WEAPON_CONFIG(ammoName,prettyName) \
        class ammoName##_wep : HSC_hydra70 {\
            scope = 1;\
            displayName = QUOTE(prettyName);\
            magazines[] = {ROCKET_MAGAZINES(ammoName)};\
            HSC_ammoType = QUOTE(ammoName);\
        };
    ROCKET_WEAPON_CONFIG(HSC_275_m151,M151HEDP)
    ROCKET_WEAPON_CONFIG(HSC_275_m255a1,M255A1FLEC)
    ROCKET_WEAPON_CONFIG(HSC_275_m257,M257IL)
    ROCKET_WEAPON_CONFIG(HSC_275_m261,M261MPSM)
    ROCKET_WEAPON_CONFIG(HSC_275_m278,M278IRIL)

    class HSC_atas: Missile_AA_04_Plane_CAS_01_F
    {
        displayname          = "FIM-92E Stinger";
        magazines[]          = {"HSC_atas"};
        cursor               = "EmptyCursor";
        cursorAim            = "EmptyCursor";
        weaponLockDelay      = 0;
        weaponLockSystem     = 2;
        cmImmunity           = 0.7;
        lockedtargetsound[]  = {"", 1, 1};
        lockingtargetsound[] = {"", 1, 1};
    };
};