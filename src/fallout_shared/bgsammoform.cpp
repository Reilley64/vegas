
// src/fallout_shared/bgsammoform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsammoform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00474a40__FUN_00474a40_shell.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct BGSAmmoForm : BaseFormComponent
{
    void* m_pAmmo;
    bool FUN_00474b70(BaseFormComponent* apCompareFC);
};

// @fnv 0x00474b70
bool BGSAmmoForm::FUN_00474b70(BaseFormComponent* apCompareFC)
{
    BGSAmmoForm* pcompare = dynamic_cast<BGSAmmoForm*>(apCompareFC);
    if (!pcompare)
        return true;
    if (m_pAmmo != pcompare->m_pAmmo)
        return true;
    return false;
}

struct DeallocHolder
{
};
struct Shell474af0 : BGSAmmoForm
{
    void FUN_00474af0();
};
// @fnv 0x00474af0
void Shell474af0::FUN_00474af0()
{
    if (m_pAmmo != 0)
    {
        unsigned int uiRet = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((DeallocHolder*)m_pAmmo)))->FUN_0084e3a0()));
        ::FUN_00485910(0x304D414E, uiRet);
    }
}

struct FUN_00474b30_Holder : BaseFormComponent
{
    void* ammo;
    void CopyAmmoFrom(BaseFormComponent* apCopyFC);
};
// @fnv 0x00474b30
void FUN_00474b30_Holder::CopyAmmoFrom(BaseFormComponent* apCopyFC)
{
    BGSAmmoForm* pcopy = dynamic_cast<BGSAmmoForm*>(apCopyFC);
    if (!pcopy)
        return;
    ammo = pcopy->m_pAmmo;
}

extern int __cdecl FUN_00ec43fb(int target, int zero, const char* first, const char* second, int finalValue);
struct RangeHolder
{
};
struct GroupHolder
{
};
struct FUN_00474a80_Class
{
    bool FUN_00474a80();
};
// @fnv 0x00474a80
bool FUN_00474a80_Class::FUN_00474a80()
{
    if (((::GroupHolder *)(reinterpret_cast<::fnv_00474a40::FUN_00474a40_shell *>(this)->FUN_00474a40())))
    {
        int value = *((int *)(new ((void *)(((::RangeHolder *)(reinterpret_cast<::BGSCameraPath *>((((::GroupHolder *)(reinterpret_cast<::fnv_00474a40::FUN_00474a40_shell *>(this)->FUN_00474a40()))))->GetConditions())))) ::Vec3()));
        if (value != 0)
        {
            int result = FUN_00ec43fb(value, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &DAT_011840c4, 0);
            if (result == 0)
                return true;
        }
    }
    return false;
}

struct AmmoRecord
{
    int FUN_00401170();
};
struct ComparisonInfo
{
    unsigned int FUN_0084e3a0();
};
extern const char str_0101a3c8[];
extern const char str_0101a404[];
extern const char str_0101a444[];

struct FUN_00474bc0_shell : BaseFormComponent
{
    void* m_pAmmo;
    void CompareAmmo(BaseFormComponent*);
};
// @fnv 0x00474bc0
void FUN_00474bc0_shell::CompareAmmo(BaseFormComponent* apCompareFC)
{
    if (m_pAmmo)
    {
        void* oldAmmo = m_pAmmo;
        ::ResolveFormID((unsigned int *)(void **)(&oldAmmo), (::TESFile *)(((int)(reinterpret_cast<::TESForm *>((reinterpret_cast<ComparisonInfo*>(apCompareFC)))->GetFile(-1)))));
        m_pAmmo = ((void *)(::FUN_004839c0((unsigned int)(oldAmmo))));
        if (m_pAmmo && reinterpret_cast<AmmoRecord*>(m_pAmmo)->FUN_00401170() != 0x29 &&
            reinterpret_cast<AmmoRecord*>(m_pAmmo)->FUN_00401170() != 0x55)
        {
            m_pAmmo = 0;
        }
        if (!m_pAmmo)
        {
            if (apCompareFC)
            {
                if (reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<ComparisonInfo*>(apCompareFC)))->HasNameForWarning())
                {
                    ::FUN_005b5e40();
                }
                else
                {
                    ::FUN_005b5e40();
                }
            }
            else
            {
                ::FUN_005b5e40();
            }
        }
    }
}
