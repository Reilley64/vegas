
// src/havok/physics/dynamics/motion/rigid/hkpfixedrigidmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpfixedrigidmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00c86660_cls.h"
#include "fnv/decl/FUN_00d1dfa0.h"
#include "havok/hkpFixedRigidMotion.h"

extern int DAT_010c6cdc;
struct FUN_00d1e160_t : hkpFixedRigidMotion
{
    void* InitFixedRigidMotion(const ::hkVector4D1DF& a, const ::hkQuaternionD1DF& b);
};
// Calls FUN_00d1dfa0, sets the vtable to &DAT_010c6cdc, sets the motion type to 5, and returns this.
// @fnv 0x00d1e160
void* FUN_00d1e160_t::InitFixedRigidMotion(const ::hkVector4D1DF& a, const ::hkQuaternionD1DF& b)
{
    new ((void *)this) ::FUN_00d1dfa0(a, b);
    *(void**)this = &DAT_010c6cdc;
    m_type = 5;
    return this;
}

// @fnv 0x00d1e130
void FUN_00d1e130(int, int)
{}

// @fnv 0x00d1e140
void FUN_00d1e140(void* a)
{}

// 0x00d1e150  /MT /O2 /GS /EHsc /Gy   target: C2 04 00  (ret 4, empty thiscall with one stack arg)
struct C00d1e150
{
    int unk00;
    void FUN_00d1e150(int arg);
};

// @fnv 0x00d1e150
void C00d1e150::FUN_00d1e150(int arg)
{}

#include <xmmintrin.h>
struct FUN_00c86660_Obj
{
};

struct FUN_00d1e190_Obj : hkpMotion
{
    void FUN_00d1e190(int* motion);
};

// Copies this motion state into motion's via FUN_00c86660, then zeroes motion's linear and angular velocity.
// @fnv 0x00d1e190
void FUN_00d1e190_Obj::FUN_00d1e190(int* motion)
{
    hkpMotion* dst = reinterpret_cast<hkpMotion*>(motion);
    reinterpret_cast<::FUN_00c86660_cls *>(&dst->m_kMotionState)->FUN_00c86660((const ::FUN_00c86660_cls *)(const void *)(&m_kMotionState));

    __m128 zero = _mm_setzero_ps();
    _mm_store_ps(reinterpret_cast<float*>(&dst->m_kTranslationalVelocity), zero);
    _mm_store_ps(reinterpret_cast<float*>(&dst->m_kAngularVelocity), zero);
}
