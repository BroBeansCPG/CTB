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
            class peq15_composeClass {
                file = QPATHTOF(functions\fnc_peq15_composeClass.sqf);
            };

            class peq15_parseClass {
                file = QPATHTOF(functions\fnc_peq15_parseClass.sqf);
            };

            class peq16_fnc_composeClass {
                file = QPATHTOF(functions\fnc_peq16_composeClass.sqf);
            };

            class peq16_fnc_parseClass {
                file = QPATHTOF(functions\fnc_peq16_parseClass.sqf);
            };
        };
    };
};

class BettIR_Config {
    class CompatibleAttachments {
        // provide some inheritance information
        class BettIR_Base_DBALA2;
        class BettIR_Base_PEQ15: BettIR_Base_DBALA2 {
            class configurable;
        };
        class BettIR_Base_PEQ15_GenericFlashlightCombo: BettIR_Base_PEQ15 {
            class configurable;
        };

        class rho_rar_nad_ir : BettIR_Base_PEQ15_GenericFlashlightCombo {
            macroClass = "rho_rar_nad_ir";

            classParser="ctb_rho_rar_fnc_peq15_parseClass";
            classComposer="ctb_rho_rar_fnc_peq15_composeClass";
        };

        BETTIR_DEFAULT_PEQ15_BETTIRCONFIG(rho_rar_nad_ir)

        class rho_rar_peq16b_top_ir : BettIR_Base_PEQ15 {
            macroClass = "rho_rar_peq16b_top_ir";
            classParser = "ctb_rho_rar_fnc_peq16_fnc_parseClass";
            classComposer = "ctb_rho_rar_fnc_peq16_fnc_composeClass";
        
            class configurable : configurable {
                class MasterMode {
                    displayName = "Master Mode";
                    defaultValue = "AH";
                    class VIS   { displayName = "VIS Laser HI"; };
                    class LIGHT { displayName = "VIS Light"; };
                    class DVIS  { displayName = "VIS Dual"; };
                    class AL    { displayName = "Aim Low"; };
                    class DL    { displayName = "Dual Low"; };
                    class AH    { displayName = "Aim High"; };
                    class DH    { displayName = "Dual High"; };
                };
                class Focus {
                    displayName = "Illuminator Divergence";
                    defaultValue = "100RAD";
                    class 25MRAD  { displayName = "25 MRAD"; };
                    class 50MRAD  { displayName = "50 MRAD"; };
                    class 75MRAD  { displayName = "75 MRAD"; };
                    class 100RAD { displayName = "100 MRAD"; };
                };
            };
        };
        BETTIR_DEFAULT_PEQ15_BETTIRCONFIG(rho_rar_peq16b_top_ir)
        class rho_rar_peq16b_top_ir_dvis: rho_rar_peq16b_top_ir_light {};
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
    BETTIR_DEFAULT_PEQ15_CFGWEAPONS(rho_rar_nad_ir)
    class rho_rar_peq16b_top_ir: acc_pointer_IR {
        class ItemInfo: ItemInfo {
            class Pointer: Pointer {
                BETTIR_IR_LASER_PRESET_DBAL_A2
            };
        };
    };
    BETTIR_DEFAULT_PEQ15_CFGWEAPONS(rho_rar_peq16b_top_ir)
    class rho_rar_peq16b_top_ir_dvis: rho_rar_peq16b_top_ir_light {
        class ItemInfo: ItemInfo {
            // no pointer to inherit from in the light config
            class Pointer: Pointer {
                irLaserPos="laser pos";
                irLaserEnd="laser dir";
                BETTIR_VIS_LASER_PRESET_DBAL_A2_RED
            };
            class Flashlight;
        };
    };
};

class asdg_slotInfo;
class asdg_FrontSideRail: asdg_slotInfo
{
	class compatibleItems
	{
		BETTIR_DEFAULT_PEQ15_RAILS(rho_rar_nad_ir)
        BETTIR_DEFAULT_PEQ15_RAILS(rho_rar_peq16b_top_ir)
        rho_rar_peq16b_top_ir_dvis=1;
	};
};