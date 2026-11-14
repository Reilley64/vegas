// include/havok/hkpWeldingUtility.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1.
#ifndef FNV_HAVOK_HKPWELDINGUTILITY_H
#define FNV_HAVOK_HKPWELDINGUTILITY_H
#include "hkBase.h"
class hkpWeldingUtility
{
  public:
    enum WeldingType
    {
        WELDING_TYPE_ANTICLOCKWISE = 0,
        WELDING_TYPE_CLOCKWISE = 4,
        WELDING_TYPE_TWO_SIDED = 5,
        WELDING_TYPE_NONE = 6
    };
    enum SectorType
    {
        ACCEPT_0 = 1,
        SNAP_0 = 0,
        REJECT = 2,
        SNAP_1 = 4,
        ACCEPT_1 = 3
    };
    enum NumAngles
    {
        NUM_ANGLES = 31
    };
    char pad0[0x1];
};
#endif
