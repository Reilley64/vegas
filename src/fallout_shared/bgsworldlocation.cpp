
// src/fallout_shared/bgsworldlocation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsworldlocation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00527000.h"
#include "fnv/symbols_011de000.h"
struct TESObjectCELL
{
public:
    bool IsCellInterior() const;
};
struct CoordinateTriple
{
    bool FUN_00527a00();
};
struct TES
{
};

namespace fnv_00527a40 {
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& rhs) const;
    float UpdateCombatStyle();
};

struct CoordinateTriple
{
    NiPoint3 pos;
    // +0x0c
    void* m_pPathingCell;
    float FUN_00527a40(const CoordinateTriple& arWorldLocation);
};

// @fnv 0x00527a40
float CoordinateTriple::FUN_00527a40(const CoordinateTriple& arWorldLocation)
{
    if (this->m_pPathingCell != arWorldLocation.m_pPathingCell)
    {
        return 3.4028234663852886e+38f;
    }
    return (arWorldLocation.pos - this->pos).UpdateCombatStyle();
}
}  // namespace fnv_00527a40

struct Pt
{
    float x, y, z;
};
struct NiPoint3 : Pt
{
    NiPoint3 operator-(NiPoint3 const&) const;
public:
    float ComputeMagnitude() const;
};
struct FUN_00527a80_shell
{
    NiPoint3 pos;
    int cell;
    float DistanceTo(FUN_00527a80_shell*);
};
// Returns the distance between this position and p's position if both are in the same cell, otherwise returns FLT_MAX.
// @fnv 0x00527a80
float FUN_00527a80_shell::DistanceTo(FUN_00527a80_shell* apOther)
{
    if (cell != apOther->cell)
        return 3.4028234663852886e+38F;
    return reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::Pt &)((apOther->pos - pos)))->ComputeMagnitude();
}

struct BGSSaveFormBuffer
{
};
struct BGSSaveGameBuffer : BGSSaveFormBuffer
{
};
struct FUN_00527b70_shell
{
    char _pad[12];
    void* m_pPathingCell;
    void FUN_00527b70(BGSSaveGameBuffer*);
};
// @fnv 0x00527b70
void FUN_00527b70_shell::FUN_00527b70(BGSSaveGameBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(this, 0xC, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pPathingCell), 0);
}

struct BGSLoadFormBuffer
{
};
struct BGSLoadGameBuffer : BGSLoadFormBuffer
{
};
struct FUN_00527ba0_This
{
    char _pad[12];
    void* m_pPathingCell;
    void FUN_00527ba0(BGSLoadGameBuffer* apLoadGameBuffer);
};
// @fnv 0x00527ba0
void FUN_00527ba0_This::FUN_00527ba0(BGSLoadGameBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(this), 12);
    m_pPathingCell = ((void *)(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apLoadGameBuffer))->FUN_008648a0())));
    if (!::FUN_00527b20((::TESForm *)(m_pPathingCell)))
        m_pPathingCell = 0;
}

struct TESForm
{
    int FNV_GetFormType();
};
struct FUN_00527990_shell
{
    char _pad[12];
    TESForm* pForm;
    bool FUN_00527990(intptr_t* apID, intptr_t* apType);
};
// @fnv 0x00527990
bool FUN_00527990_shell::FUN_00527990(intptr_t* apID, intptr_t* apType)
{
    if (!pForm)
        return false;
    int iType = pForm->FNV_GetFormType();
    if (iType == 0x41)
    {
        *apType = (intptr_t)pForm;
        *apID = 0;
        return true;
    }
    else if (iType == 0x39)
    {
        *apID = (intptr_t)pForm;
        *apType = 0;
        return true;
    }
    return false;
}

struct P3
{
    float x, y, z;
    P3 operator-(P3 const&) const;
};
struct TESCombatStyle
{
    float UpdateCombatStyle();
};

struct FUN_00527ac0_shell
{
    char _pad[12];
    float ComputeWeightedDistance(FUN_00527ac0_shell* apOther, P3* apDir);
};

// @fnv 0x00527ac0
float FUN_00527ac0_shell::ComputeWeightedDistance(FUN_00527ac0_shell* apOther, P3* apDir)
{
    if (*(int*)((char*)this + 0xc) != *(int*)((char*)apOther + 0xc))
        return 3.4028234663852886e+38f;
    P3 diff;
    reinterpret_cast<::FUN_00439ef0_class *>((void *)(((P3*)apOther)))->FUN_00439ef0((::NiPoint3 *)&diff, *(const ::NiPoint3 *)this);
    diff.x = diff.x * apDir->x;
    diff.y = diff.y * apDir->y;
    diff.z = diff.z * apDir->z;
    return ((TESCombatStyle*)&diff)->UpdateCombatStyle();
}

struct FUN_00425fd0_shell
{
};

// Returns true if form is null, has form type 0x41, or is a cell whose FUN_00425fd0 check succeeds; otherwise false.
// @fnv 0x00527b20
bool __cdecl FUN_00527b20(TESForm* form)
{
    if (form == 0)
        return true;

    switch (form->FNV_GetFormType())
    {
    case 0x41:
        return true;
    case 0x39: {
        FUN_00425fd0_shell* cell = (FUN_00425fd0_shell*)form;
        if (reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
            return true;
        break;
    }
    }
    return false;
}


struct FUN_00527900_Cell
{
};

struct FUN_00527900_shell
{
    float m_f0;
    float m_f4;
    int unk8;
    TESForm* pForm;

    TESObjectCELL* FUN_00527900();
};
// @fnv 0x00527a00
bool CoordinateTriple::FUN_00527a00()
{
    TESObjectCELL* pcell = reinterpret_cast<::FUN_00527900_shell *>(this)->FUN_00527900();
    if (!pcell)
        return false;
    return reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->IsCellBuffered(pcell, false);
}

// Returns pForm for type 0x39, resolves type 0x41 using m_f0 and m_f4, and otherwise returns null.
// @fnv 0x00527900
TESObjectCELL* FUN_00527900_shell::FUN_00527900()
{
    if (pForm == 0)
        return 0;

    int type = pForm->FNV_GetFormType();
    if (type == 0x39)
        return (TESObjectCELL*)pForm;
    else if (type == 0x41)
    {
        TESObjectCELL* pCell = (TESObjectCELL*)pForm;
        int cellX = ::FUN_00406d90(m_f0) >> 12;
        int y = ::FUN_00406d90(m_f4) >> 12;
        return reinterpret_cast<::TESWorldSpace *>((((FUN_00527900_Cell*)pCell)))->GetCellAtGridPosition(cellX, y);
    }
    return 0;
}
