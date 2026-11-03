#pragma once
#include <xmmintrin.h>

// hkpConstraintDrawer, the base the constraint drawers share. Offsets in the comments are 32-bit.
class hkpConstraintDrawer
{
  public:
    unsigned char m_unk00[0x20];
    __m128 m_bodyAWPos;  // +0x20
    __m128 m_bodyBWPos;  // +0x30
    __m128 m_unk40[2];
    __m128 m_RA[3];      // +0x60
    __m128 m_RB[3];      // +0x90

    // 0x00de47e0: copies the world transforms (hkTransform, four __m128) of the constraint's two bodies into the
    // outputs and keeps their translations and rotations.
    void FUN_00de47e0(const void* constraint, void* refLocalToWorld, void* attLocalToWorld);
};
