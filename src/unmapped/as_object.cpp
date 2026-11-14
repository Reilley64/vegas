#include "AutoMemContext.h"

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_00551110_Cell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/NavMeshArray_bc50.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/SLGameShell.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WorldReference.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00558ba0__FUN_00558ba0_shell.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/n547__Cell.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
class TESFile
{
  public:
    bool IsMasterFile();
};
class TESForm
{
  public:
    TESFile* GetFile(int);
    int FNV_GetFormType();
};
class NavMesh;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    ~NiPointer();
    operator T*() const;
    void* FUN_00458b50();
};
class TESObjectREFR
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
};
class TESObjectCELL;
struct S00561ef0
{
};
struct P01ObjA
{
};
class MobileObject
{
  public:
    unsigned int GetCurrentProcessLevel();
};
struct FUN_00881d10
{
    void SetHoursPassed();
};
struct FUN_00452440_shell
{
    bool FUN_00452440();
};
class BSSimpleList
{
  public:
    TESObjectREFR* m_item;
    BSSimpleList* m_pkNext;
    bool FUN_008256d0();
    void FUN_0063f7b0();
};
struct CF845
{
    int flags;
    CF845(int);
    CF845(const CF845&);
};
struct BGSSaveLoadGame
{
};
struct Class_0084a700
{
    bool HasChangeForForm(TESObjectREFR*, CF845);
};
class TESForm;
struct FUN_008d0370_shell
{
public:
    bool FUN_008d0370(::TESForm *);
};
class BGSLoadedReferenceCollection
{
  public:
    void FUN_005270b0(TESObjectREFR*);
};
struct NavMeshCollection
{
    NiPointer<NavMesh> GetNavMeshAt(unsigned int);
};
using AutoMemHelper = ::AutoMemContext;
class TESObjectLAND;
struct FUN_009604f0_shell
{
    BSSimpleList* FUN_009604f0();
};
struct FakeCell
{
};
class EffectSetting
{
};
struct S00551440
{
    void FUN_00551440(bool);
};
class TESObjectCELL
{
  public:
    char pad00[0x64];
    NavMeshCollection* m_pNavMeshArray;
    char pad68[0x40];
    unsigned short m_usA8;
    unsigned short m_usAA;
    void CellRefLockEnter();
    void RemoveNonPersistentRefs();
};

// @fnv 0x005508b0
void TESObjectCELL::RemoveNonPersistentRefs()
{
    TESObjectLAND* pLand;
    {
        BSSimpleList* pPrevNode;
        NavMeshCollection* pNavMeshArray;
        CellRefLockEnter();
        m_usA8 = 0;
        m_usAA = 0;
        {
            BSSimpleList* pNode;
            bool bOldAllow = reinterpret_cast<::FUN_004623f0_shell *>((g_BGSSaveLoadGame))->FUN_004623f0(false);
            reinterpret_cast<::FUN_00551110_Cell *>(this)->FUN_005576c0();
            pNode = ((FUN_009604f0_shell*)this)->FUN_009604f0();
            pPrevNode = 0;
            while (pNode && !pNode->FUN_008256d0())
            {
                TESObjectREFR* pRef = pNode->m_item;
                if (!reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((pRef))->FUN_005653d0() &&
                    (!((TESForm*)pRef)->GetFile(-1) || ((TESForm*)pRef)->GetFile(-1)->IsMasterFile()))
                {
                    if (pPrevNode)
                    {
                        reinterpret_cast<::ItemChangeListNode *>((pPrevNode))->FUN_00905330((::InventoryStackRecord *const &)(pRef));
                        pNode = ((::BSSimpleList *)(reinterpret_cast<::Callees *>((pPrevNode))->FUN_00726070()));
                    }
                    else
                    {
                        pNode->FUN_0063f7b0();
                    }
                    ::DAT_011c95c8->FUN_005270b0(pRef);
                    if (pRef->IsActor())
                    {
                        MobileObject* pActor = (MobileObject*)pRef;
                        if (pActor->GetCurrentProcessLevel() == 0)
                            ((FUN_00881d10*)pActor)->SetHoursPassed();
                    }
                    (*reinterpret_cast<::FUN_008d0370_shell * *>(&::g_TESSaveLoadGame))->FUN_008d0370((::TESForm *)(pRef));
                    reinterpret_cast<::SLGameShell *>((g_BGSSaveLoadGame))->FUN_00849730((::TESForm *)(pRef), 0);
                    bool bPrint = true;
                    if (reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((g_BGSSaveLoadGame))->FUN_0042ce10() &&
                        ((Class_0084a700*)g_BGSSaveLoadGame)->HasChangeForForm(pRef, CF845(8)) &&
                        reinterpret_cast<::WorldReference *>((((S00561ef0*)pRef)))->FUN_00561ef0(this))
                        bPrint = false;
                    if (((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)pRef)))->FUN_007af430())) && ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)pRef)))->FUN_007af430()))->FNV_GetFormType() == 0x23)
                    {
                        FUN_00452440_shell* pBase = (FUN_00452440_shell*)((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)pRef)))->FUN_007af430()));
                        if (pBase->FUN_00452440())
                            reinterpret_cast<::fnv_00558ba0::FUN_00558ba0_shell *>(this)->FUN_00558ba0(reinterpret_cast<std::intptr_t>(pRef));
                    }
                    if (bPrint && pRef != (*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)))
                        ::FUN_00867f90((::GcRef *)(pRef));
                }
                else
                {
                    pPrevNode = pNode;
                    pNode = ((::BSSimpleList *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                }
            }
            reinterpret_cast<::FUN_004623f0_shell *>((g_BGSSaveLoadGame))->FUN_004623f0(bOldAllow);
        }
        ::FUN_00541ae0((char *)this);
        pLand = reinterpret_cast<::S00546fb0_Cell *>((((FakeCell*)this)))->FUN_00546fb0();
        if (pLand)
        {
            TESFile* pFile = ((TESForm*)pLand)->GetFile(-1);
            if (!pFile || pFile->IsMasterFile())
            {
                reinterpret_cast<::n547::Cell *>(this)->SetObj((::n547::Obj *)(::TESObjectLAND *)(0));
                pLand = 0;
            }
        }
        pNavMeshArray = m_pNavMeshArray;
        if (pNavMeshArray)
        {
            AutoMemHelper memHelper(
                0x2e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp", 0x2769);
            for (unsigned int i = 0; i < ((int)(reinterpret_cast<::FUN_00620b80_shell *>((pNavMeshArray))->GetReferenceFlags())); i++)
            {
                TESFile* pNavFile = ((TESForm*)(NavMesh*)pNavMeshArray->GetNavMeshAt(i))->GetFile(-1);
                if (!pNavFile || pNavFile->IsMasterFile())
                {
                    NiPointer<NavMesh> apSearchNavMesh = pNavMeshArray->GetNavMeshAt(i);
                    reinterpret_cast<::SLGameShell *>((g_BGSSaveLoadGame))->FUN_00849730((::TESForm *)(void *)(apSearchNavMesh.FUN_00458b50()), 0);
                    reinterpret_cast<::NavMeshArray_bc50 *>((pNavMeshArray))->RemoveAndCollect(i);
                    i--;
                }
            }
        }
    }
    ((S00551440*)this)->FUN_00551440(false);
}
