#include "script_component.hpp"

class CfgPatches {
  class ADDON {
    name = CSTRING(component);
    units[] = {};
    weapons[] = {};
    requiredVersion = REQUIRED_VERSION;
    requiredAddons[] = {"ctb_main", "RS_MH6V3"};
    author = "CTBois";
    VERSION_CONFIG;
  };
};

class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};

#include "config\CfgAmmo.hpp"
#include "config\CfgFunctions.hpp"
#include "config\CfgNonAIVehicles.hpp"
#include "config\CfgMagazines.hpp"
#include "config\CfgWeapons.hpp"
#include "config\cfgVehicles.hpp"