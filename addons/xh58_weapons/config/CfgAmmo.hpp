class CfgAmmo {
    class ammo_Penetrator_Base;
    class M_Scalpel_AT;
    class ACE_Hellfire_AGM114K: M_Scalpel_AT {
        class Components;
    };
    class Missile_AA_04_F;

    class HSC_Penetrator_9KG_Tandem: ammo_Penetrator_Base
    {
        caliber                       = 60;
        warheadName                   = "TandemHEAT";
        hit                           = 1650;
        ace_vehicle_damage_incendiary = 1;
    };
    class HSC_agm114base : ACE_Hellfire_AGM114K {

        ace_frag_enabled              = 1;
        ace_frag_skip                 = 0;
        ace_frag_force                = 1;
        ace_vehicle_damage_incendiary = 0.3;

        airFriction     = 0.056;
        sideAirFriction = 0.03;
        initTime        = 0.1;
        thrustTime      = 2.5;
        thrust          = 200;
        timeToLive      = 40;
        explosionTime   = 39;

        //Penetrator
        submunitionAmmo             ="HSC_Penetrator_9KG_Tandem";
        submunitionDirectionType    ="SubmunitionModelDirection";
        submunitionInitSpeed        =1000;
        submunitionParentSpeedCoef  =1;
        submunitionInitialOffset[]  ={0,0,-0.2};
        triggerOnImpact             =1;
        deleteParentWhenTriggered   =0;

        //effectsmissile              = "HSC_hellfiresmoke";
        muzzleEffect                = "BIS_fnc_effectFiredHeliRocket";
        effectsMissileInit          = "MissileDAR1";
        explosionEffects            = "ATMissileExplosion";
        whistledist                 = 300;
        soundFly[] = {"A3\Sounds_F\weapons\Rockets\rocket_fly_2",0.5011872,1,1700};

        class CamShakeExplode
        {
            power     = 22;
            duration  = 2;
            frequency = 20;
        };
        class CamShakeHit
        {
            power     = 110;
            duration  = 0.6;
            frequency = 20;
        };
        class ace_missileguidance {
            enabled               = 1;
            minDeflection         = 0.0005; // Not used in ace currently
            maxDeflection         = 0.01;   // Not used in ace currently
            incDeflection         = 0.0005; // Not used in ace currently
            canVanillaLock        = 0; // guidance will utilise cursortarget func with no lock
            defaultSeekerType     = "HSC_SALH";
            seekerTypes[]         = { "HSC_SALH" };
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[]     = { "LOAL", "LOBL" };
            seekLastTargetPos     = 1;
            seekerAngle           = 45;
            seekerAccuracy        = 1;
            seekerMinRange        = 1;
            seekerMaxRange        = 8100;
            defaultAttackProfile  = "hellfire";
            attackProfiles[]      = {"hellfire", "hellfire_hi", "hellfire_lo"};
        };
    };
    class HSC_agm114k : HSC_agm114base
    {
        displayName       = "AGM-114K";
        //model            = "\xh58_weapons\HSC_agm114K";
        //proxyShape       = "\xh58_weapons\HSC_agm114K";
        model = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
        proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
        hit               = 600;
        indirectHit       = 200;
        indirectHitRange  = 4;
        class ace_missileguidance: ace_missileguidance {
            enabled       = 1;
        };
    };
    class HSC_agm114n : HSC_agm114base
    {
        displayName      = "AGM-114N";
        //model            = "\xh58_weapons\HSC_agm114K";
        //proxyShape       = "\xh58_weapons\HSC_agm114K";
        model = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
        proxyShape = "z\vtx\addons\uh60_weapons\fza_agm114l.p3d";
        hit              = 300;
        indirecthit      = 300;
        indirecthitrange = 20;
        explosionEffects = "HeavyBombExplosion";
        submunitionAmmo  = "";
        class ace_missileguidance: ace_missileguidance {
            enabled      = 1;
        };
    };


    class RocketBase;
    class GrenadeBase;
    class FlareCore;
    class B_9x21_Ball;

    class HSC_275_base: RocketBase 
    {
        simulation                  = "shotRocket";
        ace_frag_enabled            = 0;
        ace_frag_skip               = 1;
        model                       = "";
        effectsMissileInit          = "MissileDAR1";
        hit                         = 210;
        indirectHit                 = 55;
        indirectHitRange            = 15;
        weaponType                  = "rocket";
        dangerRadiusHit             = 40;
        maxSpeed                    = 840;
        thrustTime                  = 0.5;
        thrust                      = 1700;
        fuseDistance                = 75;
        airFriction                 = 0.05;
        sideAirFriction             = 0.004;
        whistleDist                 = 24;
        suppressionRadiusHit        = 20;
        soundFly[] = {"A3\Sounds_F\weapons\Rockets\rocket_fly_1",0.63095737,1.2,1700};

        class CamShakeExplode
        {
            power = 16;
            duration = 1.8;
            frequency = 20;
        };
        class CamShakeHit
        {
            power = 80;
            duration = 0.6;
            frequency = 20;
        };
    };
    class HSC_275_m151: HSC_275_base
    {
        ace_frag_enabled            = 1;
        ace_frag_skip               = 0;
        model                       = "z\ctb\addons\xh58_weapons\HSC_hydra_m151_wep.p3d";
        proxyShape                  = "z\ctb\addons\xh58_weapons\HSC_hydra_m151.p3d";
    };
    class HSC_275_m255a1: HSC_275_base 
    {
        model                       = "z\ctb\addons\xh58_weapons\HSC_hydra_m261_wep.p3d";
        proxyShape                  = "z\ctb\addons\xh58_weapons\HSC_hydra_m261.p3d";
        CraterEffects               = "ATMissileCrater";

        submunitionDirectionType    ="SubmunitionModelDirection";
        submunitionAmmo             = "HSC_flec_cluster";
        submunitionConeType[]       = {"randomcenter",100};
        submunitionConeAngle        = 12;
        triggerDistance             = 200;
        submunitionInitSpeed        = 500;
        deleteParentWhenTriggered   = 1;
        submunitionInitialOffset[]  = {0,0,2};

        soundHit1[]                 = {"A3\sounds_f\dummysound",2.5118864,1,5};
        multiSoundHit[]             = {"soundHit1",1};
    };
    class HSC_275_m257: HSC_275_base 
    {
        model                       = "z\ctb\addons\xh58_weapons\HSC_hydra_m261_wep.p3d";
        proxyShape                  = "z\ctb\addons\xh58_weapons\HSC_hydra_m261.p3d";
        CraterEffects               = "ATMissileCrater";

        submunitionAmmo             = "HSC_m257_flare";
        submunitionCount            = 1;
        submunitionConeAngle        = 0;
        deleteParentWhenTriggered   = 1;

        triggerTime                 = 5.5;
        soundHit1[]                 = {"A3\sounds_f\dummysound",2.5118864,1,5};
        multiSoundHit[]             = {"soundHit1",1};
    };
    class HSC_275_m261: HSC_275_base 
    {
        model                       = "z\ctb\addons\xh58_weapons\HSC_hydra_m261_wep.p3d";
        proxyShape                  = "z\ctb\addons\xh58_weapons\HSC_hydra_m261.p3d";

        submunitionDirectionType    = "SubmunitionModelDirection";
        submunitionAmmo             = "HSC_m73mpsm";
        submunitionConeType[]       = {"randomcenter",9};
        submunitionConeAngle        = 2;
        triggerDistance             = 500;
        submunitionInitSpeed        = 500;
        deleteParentWhenTriggered   = 1;
    };
    class HSC_275_m278: HSC_275_base 
    {
        model                       = "z\ctb\addons\xh58_weapons\HSC_hydra_m261_wep.p3d";
        proxyShape                  = "z\ctb\addons\xh58_weapons\HSC_hydra_m261.p3d";
        CraterEffects               = "ATMissileCrater";

        submunitionAmmo             = "HSC_m278_flare";
        submunitionCount            = 1;
        submunitionConeAngle        = 0;
        deleteParentWhenTriggered   = 1;

        triggerTime                 = 5.5;
        soundHit1[]                 = {"A3\sounds_f\dummysound",2.5118864,1,5};
        multiSoundHit[]             = {"soundHit1",1};
    };

    class HSC_m73mpsm: GrenadeBase
    {
        ace_frag_enabled            = 1;
        ace_frag_skip               = 0;

        simulation                  = "shotShell";
        model                       = "\A3\weapons_f\ammo\UGL_slug"; //M73 model needed.
        explosionEffects            = "ExploAmmoExplosion";
        CraterEffects               = "ExploAmmoCrater";
        muzzleEffect                = "BIS_fnc_effectFiredHeliRocket";
        dangerRadiusHit             = 60;
        suppressionRadiusHit        = 30;
        airFriction                 = -0.001;
        fuseDistance                = 30;
        typicalSpeed                = 300;
        caliber                     = 3.7;
        soundHit1[] = {"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_01",1.7782794,1,1600};
        soundHit2[] = {"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_02",1.7782794,1,1600};
        soundHit3[] = {"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_03",1.7782794,1,1600};
        soundHit4[] = {"A3\Sounds_F\arsenal\explosives\shells\30mm40mm_shell_explosion_04",1.7782794,1,1600};
        multiSoundHit[] = {"soundHit1",0.25,"soundHit2",0.25,"soundHit3",0.25,"soundHit4",0.25};
    };
    class HSC_m257_flare: FlareCore
    {
        timeToLive                  = 100;
        model                       = "\A3\Weapons_F\Ammo\UGL_Flare.p3d";
        lightColor[]                = {1,0.8,0.7,0.5};
        smokeColor[]                = {1,1,1,0.4};
        effectFlare                 = "CounterMeasureFlare";
        brightness                  = 0.1;
        size                        = 3;
        triggerTime                 = 0.25;
        triggerSpeedCoef            = 1;
        audibleFire                 = 20;
        intensity                   = 1000000;
    };
    class HSC_m278_flare: HSC_m257_flare
    {
        irLight                     = 1;
        intensity                   = 300000;
    };
    class HSC_flec_cluster: B_9x21_Ball
    {
        ace_frag_enabled            = 0;
        ace_frag_skip               = 1;
        
        hit                         = 6;
        indirectHit                 = 6;
        indirectHitRange            = 4;
        deflecting                  = 0;
        fuseDistance                = 50;
        //effectFly                   = "fza_ah64_deploysmoke";
    };

    class HSC_fim92: Missile_AA_04_F
    {
        //model         = "\xh58_weapons\HSC_fim92";
        //proxyShape    = "\xh58_weapons\HSC_fim92";
        model         = "\A3\Weapons_F_EPC\Ammo\Missile_AA_04_fly_F.p3d";
        proxyShape    = "\A3\Weapons_F_EPC\Ammo\Missile_AA_04_F.p3d";
        maxSpeed      = 750;
        class CamShakeExplode
        {
            power     = 22;
            duration  = 2;
            frequency = 20;
            distance  = 163.905;
        };
        class CamShakeHit
        {
            power     = 110;
            duration  = 0.6;
            frequency = 20;
            distance  = 1;
        };
    };
};