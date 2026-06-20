#include "script_component.hpp"
#include "macros.hpp"

class CfgPatches {
	class ADDON {
		name = CSTRING(component);
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {"BettIR_Attachments","rho_rar_attachments_F"};
		author = "CTBois";
		skipWhenMissingDependencies = 1;
		VERSION_CONFIG;
	};
};

class CfgFunctions {
    class ctb_rho_rar {
        class Core {
            class composeClass {
                file = QPATHTOF(functions\fnc_composeClass.sqf);
            };

            class parseClass {
                file = QPATHTOF(functions\fnc_parseClass.sqf);
            };
        };
    };
};

class BettIR_Config {
    class CompatibleAttachments {
        // provide some inheritance information
        class BettIR_Base_PEQ15;
        class BettIR_Base_PEQ15_GenericFlashlightCombo: BettIR_Base_PEQ15 {
            class Configurable;
        };

        class rho_rar_nad_ir : BettIR_Base_PEQ15_GenericFlashlightCombo {
            macroClass = "rho_rar_nad_ir";

            classParser="ctb_rho_rar_fnc_parseClass";
            classComposer="ctb_rho_rar_fnc_composeClass";
        };
        class rho_rar_nad_ir_light: rho_rar_nad_ir {};

        class rho_rar_nad_ir_DL_25MRAD: rho_rar_nad_ir {};
        class rho_rar_nad_ir_IH_25MRAD: rho_rar_nad_ir {};
        class rho_rar_nad_ir_DH_25MRAD: rho_rar_nad_ir {};

        class rho_rar_nad_ir_DL_50MRAD: rho_rar_nad_ir {};
        class rho_rar_nad_ir_IH_50MRAD: rho_rar_nad_ir {};
        class rho_rar_nad_ir_DH_50MRAD: rho_rar_nad_ir {};

        class rho_rar_nad_ir_DL_75MRAD: rho_rar_nad_ir {};
        class rho_rar_nad_ir_IH_75MRAD: rho_rar_nad_ir {};
        class rho_rar_nad_ir_DH_75MRAD: rho_rar_nad_ir {};

        class rho_rar_nad_ir_DL_100MRAD: rho_rar_nad_ir {};
        class rho_rar_nad_ir_IH_100MRAD: rho_rar_nad_ir {};
        class rho_rar_nad_ir_DH_100MRAD: rho_rar_nad_ir {};

    };
};

class cfgWeapons {
    class ItemCore;
    class acc_flashlight;

    class InventoryFlashLightItem_Base_F {
        class Flashlight;
        class Pointer;
    };

    class acc_pointer_IR: ItemCore {
        class ItemInfo: InventoryFlashLightItem_Base_F {
            class Pointer;
        };
    };

    class rho_rar_nad_ir: acc_pointer_IR {
        class ItemInfo: ItemInfo {
            class Pointer: Pointer {
                BETTIR_IR_LASER_PRESET_DBAL_A2
            };
        };
    };
    BETTIR_DEFAULT_PEQ15(rho_rar_nad_ir)
};

class asdg_slotInfo;
class asdg_FrontSideRail: asdg_slotInfo
{
	class compatibleItems
	{
		rho_rar_nad_ir=1;
        rho_rar_nad_ir_light=1;
        rho_rar_nad_ir_DL_25MRAD=1;
        rho_rar_nad_ir_IH_25MRAD=1;
        rho_rar_nad_ir_DH_25MRAD=1;
        rho_rar_nad_ir_DL_50MRAD=1;
        rho_rar_nad_ir_IH_50MRAD=1;
        rho_rar_nad_ir_DH_50MRAD=1;
        rho_rar_nad_ir_DL_75MRAD=1;
        rho_rar_nad_ir_IH_75MRAD=1;
        rho_rar_nad_ir_DH_75MRAD=1;
        rho_rar_nad_ir_DL_100MRAD=1;
        rho_rar_nad_ir_IH_100MRAD=1;
        rho_rar_nad_ir_DH_100MRAD=1;
	};
};