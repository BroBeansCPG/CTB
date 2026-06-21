#include "..\..\include\presets\dbal_a2.hpp"
#include "..\..\include\presets\peq15.hpp"

#define BETTIR_ITEM_DBALA2_ILLUMINATOR_HI(MRAD) \
    class acc_pointer_IR_Illuminator_HI_##MRAD##mrad : acc_pointer_IR { \
        baseWeapon="acc_pointer_IR"; \
        model="BettIR_Attachments\data\models\DBAL_illum_hi.p3d"; \
        displayName=Steiner DBAL A2 (Illuminator, HI, ##MRAD## mrad); \
        class ItemInfo: ItemInfo { \
            class Pointer {}; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_DBAL_A2((MRAD),"illum pos","illum dir",1) \
            }; \
        }; \
    };

#define BETTIR_ITEM_DBALA2_ILLUMINATOR_LO(MRAD) \
    class acc_pointer_IR_Illuminator_LO_##MRAD##mrad: acc_pointer_IR { \
        baseWeapon="acc_pointer_IR"; \
        model="BettIR_Attachments\data\models\DBAL_illum_lo.p3d"; \
        displayName=Steiner DBAL A2 (Illuminator, LO, ##MRAD## mrad); \
         class ItemInfo: ItemInfo { \
            class Pointer {}; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_DBAL_A2((MRAD),"illum pos","illum dir",0) \
            }; \
        }; \
    };

#define BETTIR_ITEM_DBALA2_ILLUMINATOR_HI_LASER(MRAD) \
    class acc_pointer_IR_Illuminator_HI_##MRAD##mrad_LASER: acc_pointer_IR { \
        baseWeapon="acc_pointer_IR"; \
        model="BettIR_Attachments\data\models\DBAL_dual_hi.p3d"; \
        displayName=Steiner DBAL A2 (Illuminator & Laser, HI, ##MRAD## mrad); \
         class ItemInfo: ItemInfo { \
            class Pointer: Pointer { \
                irLaserEnd = "laser dir"; \
                irLaserPos = "laser pos"; \
                irDistance=-1; \
                isIR=1; \
                irDotSize=0.025;\
                beamThickness=0.015;\
                beamColor[]={50000000,50000000,50000000};\
                dotColor[]={1000,1000,1000};\
            }; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_DBAL_A2((MRAD),"illum pos","illum dir",1) \
            }; \
        }; \
    };

#define BETTIR_ITEM_DBALA2_ILLUMINATOR_LO_LASER(MRAD) \
    class acc_pointer_IR_Illuminator_LO_##MRAD##mrad_LASER: acc_pointer_IR { \
        baseWeapon="acc_pointer_IR"; \
        model="BettIR_Attachments\data\models\DBAL_dual_lo.p3d"; \
        displayName=Steiner DBAL A2 (Illuminator & Laser, LO, ##MRAD## mrad); \
        class ItemInfo: ItemInfo { \
            class Pointer: Pointer { \
                irLaserEnd = "laser dir"; \
                irLaserPos = "laser pos"; \
                isIR=1; \
                beamThickness=0.0; \
                irDotSize=0.005; \
                irDistance=0; \
                beamColor[] = {0,0,0}; \
                dotColor[] = {100,100,100}; \
            }; \
            class Flashlight: Flashlight { \
                BETTIR_ILLUMINATOR_PRESET_DBAL_A2((MRAD),"illum pos","illum dir",0) \
            }; \
        }; \
    };

#define BETTIR_ITEM_DBALA2_RAIL_COMPAT(MRAD) \
    acc_pointer_IR_Illuminator_HI_##MRAD##mrad = 1; \
    acc_pointer_IR_Illuminator_HI_##MRAD##mrad_Laser = 1; \
    acc_pointer_IR_Illuminator_LO_##MRAD##mrad = 1; \
    acc_pointer_IR_Illuminator_LO_##MRAD##mrad_Laser = 1;

#define BETTIR_DBALA2_MACRO_COMPAT(MRAD) \
    class acc_pointer_IR_Illuminator_HI_##MRAD##mrad : acc_pointer_ir {}; \
    class acc_pointer_IR_Illuminator_HI_##MRAD##mrad_Laser : acc_pointer_ir {}; \
    class acc_pointer_IR_Illuminator_LO_##MRAD##mrad : acc_pointer_ir {}; \
    class acc_pointer_IR_Illuminator_LO_##MRAD##mrad_Laser : acc_pointer_ir {};
