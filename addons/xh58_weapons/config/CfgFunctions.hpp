#ifdef __A3_DEBUG__
#define RECOMPILE_FLAG recompile = 1
#else
#define RECOMPILE_FLAG recompile = 0
#endif
class CfgFunctions
{
    class HSC_weapons {
        tag="HSC_weapons";
        class functions {
            file = "\xh85_weapons\functions";
            //class funcName {RECOMPILE_FLAG;};
        };
    };
};