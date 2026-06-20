#include "..\core.hpp"

// Intensity in low mode, 50 MRAD
#define PEQ15_ILLUMINATOR_BASE_INTENSITY 300

// TODO: tweak power settings, right now they are a copy of DBAL A2
#define BETTIR_ILLUMINATOR_PRESET_PEQ15(MRAD,POS,DIR,HIPWR) \
    ambient[] = {1,1,1}; \
    color[] = {1,1,1}; \
    coneFadeCoef = 64 * (1 - (MRAD / 200)); \
    dayLight = 0; \
    position = POS ; \
    direction = DIR ; \
    flareMaxDistance = 400 + (HIPWR * 600); \
    flareSize = 1.4; \
    intensity =  ((1.4 * HIPWR) + 1) * (PEQ15_ILLUMINATOR_BASE_INTENSITY * (50 / MRAD) * (50 / MRAD)) ; \
    innerAngle = MRADTODEG(MRAD) ; \
    outerAngle = (MRADTODEG(MRAD) / 0.85); \
    irLight=1; \
    scale[] = {1,1,1}; \
    size = 1; \
    useFlare = 1; \
    class Attenuation { \
        constant = 4; \
        linear = 0; \
        quadratic = 0.065; \
        start = 10; \
        hardLimitStart = 160 + (HIPWR * 40); \
        hardLimitEnd = 240 + (HIPWR * 60); \
    };