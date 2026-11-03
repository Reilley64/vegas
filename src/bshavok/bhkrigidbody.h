#ifndef FNV_BHKRIGIDBODY_WORKER_H
#define FNV_BHKRIGIDBODY_WORKER_H

#include "fnv/decl/CA8830Object.h"
#include "fnv/decl/FUN_005d3d10_This.h"
#include "fnv/decl/FUN_00c87a50_t.h"
#include "fnv/decl/FUN_00ca8800_Class.h"
#include "fnv/decl/FUN_00ca8860_cls.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_01268000.h"
#include "bhkrigidbody_types_NiRTTI.h"
#include "bhkrigidbody_types_bhkRigidBody.h"

#include "bhkrigidbody_worker_decls.h"

#pragma optimize("", off)
// @fnv 0x0056d530
const NiRTTI* bhkRigidBody::GetRTTI()
{
    return &(*reinterpret_cast<::NiRTTI *>(&::g_012681c0));
}

// @fnv 0x0056d540
unsigned int bhkRigidBody::GetInstanceSize()
{
    return 0xe0;
}

#pragma optimize("", on)
// @fnv 0x00c8d170
void bhkRigidBody::SetPosition(const NiPoint3& p)
{
    if (this)
    {
        hkpRigidBody* body = (hkpRigidBody*)m_pHavokObject;
        if (body)
        {
            ((void(__thiscall*)(bhkRigidBody*))((void (&)(const char *))::FUN_00a29680))(this);
            reinterpret_cast<::FUN_00ca8800_Class *>((body))->FUN_00ca8800((int)&(p));
            ((void(__thiscall*)(bhkRigidBody*))((void (&)(const char *))::FUN_00a29680))(this);
        }
    }
}
// @fnv 0x00c8d1a0
void bhkRigidBody::SetRotation(const NiQuaternion& p)
{
    if (this)
    {
        hkpRigidBody* body = (hkpRigidBody*)m_pHavokObject;
        if (body)
        {
            ((void(__thiscall*)(bhkRigidBody*))((void (&)(const char *))::FUN_00a29680))(this);
            reinterpret_cast<::CA8830Object *>((body))->FUN_00ca8830((int)&(p));
            ((void(__thiscall*)(bhkRigidBody*))((void (&)(const char *))::FUN_00a29680))(this);
        }
    }
}

#pragma optimize("", off)
// @fnv 0x0062ab20
float bhkRigidBody::GetBodyMass()
{
    hkpMotion* motion = ((::hkpMotion *)(reinterpret_cast<::FUN_005d3d10_This *>(this)->FUN_005d3d10()));
    return motion ? reinterpret_cast<::MotionMassView *>((motion))->FUN_00c86430() : ::FUN_004b5400((void *)this);
}
#pragma optimize("", on)
__forceinline const __m128& bhkRigidBody::PositionVector()
{
    if (this && m_pHavokObject)
        return ((hkpRigidBody*)m_pHavokObject)->m_vContactPosition;
    return *(__m128*)&DAT_01267e30;
}
#pragma optimize("t", on)
// @fnv 0x00c8d0f0
NiPoint3& bhkRigidBody::GetPosition(NiPoint3& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)PositionVector();
    return p;
}
__forceinline const __m128& bhkRigidBody::RotationVector()
{
    if (this && m_pHavokObject)
        return ((hkpRigidBody*)m_pHavokObject)->m_rotation;
    return *(__m128*)&DAT_012683b0;
}
#pragma optimize("t", on)
// @fnv 0x00c8d130
NiQuaternion& bhkRigidBody::GetRotation(NiQuaternion& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)RotationVector();
    return p;
}

// @fnv 0x00c8f510
BhkRigidBody::BhkRigidBody()
{
    rigidBody.m_fSurfaceFriction = DAT_01022958;
    rigidBody.m_iAutoRemoveLevel = 0xff;
    rigidBody.m_fRestitution = DAT_010c60d8;
}
// @fnv 0x00c8d1d0
void bhkRigidBody::FUN_00c8d1d0(const NiPoint3& p, const NiQuaternion& q)
{
    if (this)
    {
        hkpRigidBody* body = (hkpRigidBody*)m_pHavokObject;
        if (body)
        {
            reinterpret_cast<::FUN_00c87a50_t *>(this)->FUN_00c87a50();
            reinterpret_cast<::FUN_00ca8860_cls *>((body))->FUN_00ca8860((int)&(p), (int)&(q));
        }
    }
}
__forceinline const __m128& bhkRigidBody::FUN_00c8d240Vector()
{
    if (this && m_pHavokObject)
        return ((hkpRigidBody*)m_pHavokObject)->m_vCenterOfMass1;
    return *(__m128*)&DAT_01267e30;
}
#pragma optimize("t", on)
// @fnv 0x00c8d240
NiPoint3& bhkRigidBody::GetVec(NiPoint3& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)FUN_00c8d240Vector();
    return p;
}
__forceinline const __m128& bhkRigidBody::FUN_00c8d200Vector()
{
    if (this && m_pHavokObject)
        return ((hkpRigidBody*)m_pHavokObject)->m_vCenterOfMassLocal;
    return *(__m128*)&DAT_01267e30;
}
#pragma optimize("t", on)
// @fnv 0x00c8d200
NiPoint3& bhkRigidBody::FUN_00c8d200(NiPoint3& p)
{
    *(bhkrigidbody_vector*)&p = (const bhkrigidbody_vector&)FUN_00c8d200Vector();
    return p;
}
#endif
