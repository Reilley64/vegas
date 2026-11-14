// include/havok/hkpHingeConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xA0.
#ifndef FNV_HAVOK_HKPHINGECONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPHINGECONSTRAINTDATAATOMS_H
#include "hkBase.h"
#include "hkpSetLocalTransformsConstraintAtom.h"
#include "hkp2dAngConstraintAtom.h"
#include "hkpBallSocketConstraintAtom.h"
class hkpHingeConstraintDataAtoms
{
  public:
    enum Axis
    {
        AXIS_AXLE = 0
    };
    hkpSetLocalTransformsConstraintAtom m_transforms;  // +0x0
    hkp2dAngConstraintAtom m_2dAng;                    // +0x90
    hkpBallSocketConstraintAtom m_ballSocket;          // +0x94
    char pad9C[0x4];
};
#endif
