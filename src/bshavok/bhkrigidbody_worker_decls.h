// bshavok/bhkrigidbody_worker_decls.h: declares hkpMotion, WorldPhysicsSettings, hkpRigidBody, bhkRigidBodyPrefix, BhkRigidBody
#ifndef FNV_BHKRIGIDBODY_WORKER_DECLS_H
#define FNV_BHKRIGIDBODY_WORKER_DECLS_H

#include <xmmintrin.h>
#include "fnv/decl/CA8830Object.h"
#include "fnv/decl/FUN_00ca8800_Class.h"
#include "fnv/decl/FUN_00ca8860_cls.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "NiPoint3.h"
class NiQuaternion;

extern float DAT_010c60d8;

class hkpMotion
{
  public:
};

class WorldPhysicsSettings
{
  public:
    char layoutPadding000[0xa8];
    float m_fSurfaceFriction;
    float m_fRestitution;
    char layoutPaddingB0[7];
    unsigned char m_iAutoRemoveLevel;
    char layoutPaddingB8[8];
    WorldPhysicsSettings();
};

FNV_STATIC_ASSERT(sizeof(WorldPhysicsSettings) == 0xc0);
FNV_STATIC_ASSERT(offsetof(WorldPhysicsSettings, m_fSurfaceFriction) == 0xa8);
FNV_STATIC_ASSERT(offsetof(WorldPhysicsSettings, m_fRestitution) == 0xac);
FNV_STATIC_ASSERT(offsetof(WorldPhysicsSettings, m_iAutoRemoveLevel) == 0xb7);

class hkpRigidBody
{
  public:
    char layoutPadding000[0x120];
    __m128 m_vContactPosition;
    char layoutPadding130[0x10];
    __m128 m_vCenterOfMass1;
    char layoutPadding150[0x10];
    __m128 m_rotation;
    __m128 m_vCenterOfMassLocal;
};

class bhkRigidBodyPrefix
{
  public:
    volatile unsigned int field0;
    volatile unsigned int field4;
    union
    {
        hkpRigidBody* m_pHavokObject;
        volatile unsigned char initialized;
    };
    volatile unsigned int fieldC;
    volatile unsigned int field10;
    volatile unsigned int field14;
    volatile unsigned char field18;
    unsigned char padding19;
    volatile unsigned short field1a;
    volatile unsigned int field1c;

    ~bhkRigidBodyPrefix();
    __forceinline bhkRigidBodyPrefix()
    {
        fieldC = 0;
        field10 = 0;
        field14 = 0x80000000;
        initialized = 1;
        field0 = 0;
        field4 = 0;
        field18 = 1;
        field1a = 0xffff;
    }
};

FNV_STATIC_ASSERT(sizeof(bhkRigidBodyPrefix) == 0x20);
FNV_STATIC_ASSERT(offsetof(bhkRigidBodyPrefix, m_pHavokObject) == 8);
struct __declspec(align(16)) bhkrigidbody_vector
{
    __m128 v;
    __forceinline bhkrigidbody_vector& operator=(const bhkrigidbody_vector& other)
    {
        v = other.v;
        return *this;
    }
};
class BhkRigidBody : public bhkRigidBodyPrefix
{
  public:
    WorldPhysicsSettings rigidBody;
    BhkRigidBody();
};
class NiD3DDefaultShader
{
  public:
};
#endif
