
// src/staging/blk_006e0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/PathingLocation.h"
#include "fnv/decl/Script.h"
#include "fnv/decl/ScriptLocals.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004a3000.h"
#include <xmmintrin.h>

struct S006e6ae0_Vector
{
    __m128 m_vComponents;
};

struct S006e6ae0_Point3
{
    float x, y, z;
};

class S006e6ae0_Aabb
{
  public:
    S006e6ae0_Aabb();  // FUN_00437c10
    S006e6ae0_Vector m_kMinimumCorner;
    S006e6ae0_Vector m_kMaximumCorner;
};

class S006e6ae0_Shape
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual int vf60();
    virtual void vf64();
    virtual void vf68(const S006e6ae0_Aabb* pAabb, int iHandle);
};

class S006e6ae0_Body
{
  public:
};

class S006e6ae0_World
{
  public:
};

class S006e6ae0_Owner2
{
  public:
};

class S006e6ae0_Owner1
{
  public:
};

class S006e6ae0_Node
{
  public:
};

int __cdecl FUN_006e7620(int iValue, int iFlags);

class S006e6ae0_Object
{
  public:
    void FUN_006e6ae0();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    S006e6ae0_Node* m_pkNode;
    unsigned int unk58;
    S006e6ae0_Point3 m_kMin;
    S006e6ae0_Point3 m_kMax;
    unsigned int unk74;
    int m_iHandle;
};

// @fnv 0x006e6ae0
void S006e6ae0_Object::FUN_006e6ae0()
{
    S006e6ae0_Aabb kAabb;
    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&kAabb.m_kMinimumCorner)), (*(const ::fnv_004a3e00::NiPoint3 *)(&m_kMin)));
    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&kAabb.m_kMaximumCorner)), (*(const ::fnv_004a3e00::NiPoint3 *)(&m_kMax)));
    S006e6ae0_World* pkWorld = ((::S006e6ae0_World *)(reinterpret_cast<::FUN_004543c0_cls *>((((::S006e6ae0_Owner2 *)(reinterpret_cast<::PathingLocation *>((((::S006e6ae0_Owner1 *)(::GetOffsetC((int)(m_pkNode))))))->GetContainingCell()))))->FUN_004543c0()));
    reinterpret_cast<::Script *>((pkWorld))->GetLocalData();
    S006e6ae0_Shape* pkShape = ((::S006e6ae0_Shape *)(reinterpret_cast<::LowProcess *>((((::S006e6ae0_Body *)(reinterpret_cast<::ScriptLocals *>((pkWorld))->GetLocalData()))))->GetPackageObjectType()));
    int iValue = pkShape->vf60();
    m_iHandle = FUN_006e7620(iValue, 0);
    S006e6ae0_Shape* pkShape2 = ((::S006e6ae0_Shape *)(reinterpret_cast<::LowProcess *>((((::S006e6ae0_Body *)(reinterpret_cast<::ScriptLocals *>((pkWorld))->GetLocalData()))))->GetPackageObjectType()));
    pkShape2->vf68(&kAabb, m_iHandle);
    reinterpret_cast<::Script *>((pkWorld))->GetLocalData();
}
