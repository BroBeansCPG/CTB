#include "\BettIR_Attachments\compat\core\macros.hpp"

#define BETTIR_DEFAULT_PEQ15(BASECLASS) \
    class BASECLASS##_al: BASECLASS { \
        scope = 1; \
        class itemInfo: itemInfo { \
            class pointer: pointer { \
                BETTIR_IR_LASER_PRESET_DBAL_A2_LO \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_vis: BASECLASS { \
        scope = 1; \
        class itemInfo: itemInfo { \
            class pointer: pointer { \
                BETTIR_VIS_LASER_PRESET_DBAL_A2_RED \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_ih_25MRAD: BASECLASS { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer {}; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(25,"laser pos","laser dir",1) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_ih_50MRAD: BASECLASS { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer {}; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(50,"laser pos","laser dir",1) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_ih_75MRAD: BASECLASS { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer {}; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(75,"laser pos","laser dir",1) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_ih_100MRAD: BASECLASS { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer {}; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(100,"laser pos","laser dir",1) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_dh_25MRAD: BASECLASS { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(25,"laser pos","laser dir",1) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_dh_50MRAD: BASECLASS { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(50,"laser pos","laser dir",1) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_dh_75MRAD: BASECLASS { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(75,"laser pos","laser dir",1) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_dh_100MRAD: BASECLASS { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(100,"laser pos","laser dir",1) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_dl_25MRAD: BASECLASS { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer: Pointer { \
                BETTIR_IR_LASER_PRESET_DBAL_A2_LO \
            }; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(25,"laser pos","laser dir",0) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_dl_50MRAD: BASECLASS##_dl_25MRAD { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(50,"laser pos","laser dir",0) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_dl_75MRAD: BASECLASS##_dl_25MRAD { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(75,"laser pos","laser dir",0) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_dl_100MRAD: BASECLASS##_dl_25MRAD { \
        scope = 1; \
        class ItemInfo: ItemInfo { \
            class Pointer; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_PEQ15(100,"laser pos","laser dir",0) \
            }; \
        }; \
    }; \
 \
    class BASECLASS##_light: BASECLASS { \
        scope = 1; \
        class ItemInfo: InventoryFlashLightItem_Base_F { \
            mass=5; \
            class FlashLight {\
                color[]={7000,7500,10000}; \
                ambient[]={6,9,9}; \
                intensity=1.5; \
                size=1; \
                innerAngle=20; \
                outerAngle=75; \
                coneFadeCoef=10; \
                position="flash dir"; \
                direction="flash"; \
                useFlare=1; \
                flareSize=1.5; \
                flareMaxDistance="500.0f"; \
                dayLight=1; \
                class Attenuation {\
                    start=0.5; \
                    constant=0; \
                    linear=0; \
                    quadratic=1; \
                    hardLimitStart=200; \
                    hardLimitEnd=300; \
                }; \
                scale[]={0}; \
            }; \
        }; \
    };