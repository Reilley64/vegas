
// tesobjectcell_ctx3_variant.cpp: context variant of src/fallout_shared/tesobjectcell.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <new>
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_004867a0_cls.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_005516c0.h"
#include "fnv/decl/FUN_00557760_cls.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/NavShell2.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_005340e0__TESObjectLAND.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00565480__RefPersistsStandin.h"
#include "fnv/decl/n547__Cell.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();

struct TESForm
{
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual TESForm* DuplicateForm(bool abCreateEditorID, void* apCopyMap);
    virtual void v17();
    virtual void v18();
    virtual void v19();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50(bool);
};
struct TESObjectLAND
{
};
struct NavMesh
{
};
struct RefH
{
};
struct Flt
{
    operator unsigned int();
};
struct NavMeshPtr : Flt
{
    NavMesh* m_pObject;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NavMeshPtr&);
};
template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(const NavMeshPtr&);
    ~NiPointer();
};
struct NavMeshCollection
{
    char data[0x10];
    NavMeshCollection();
    NavMeshPtr GetNavMeshAt(unsigned int);
};
NavMeshPtr __cdecl MakeNavMeshPointer(NavMesh*);
struct S004867a0
{
};
struct CellX
{
};
struct CellH
{
};
struct RefX
{
};
struct TempIsTemp
{
};
struct SL
{
    void* m_item;
    void* m_next;
    SL();
};
struct ListX : SL
{
    ~ListX();
};
struct List_009e03e0
{
};
struct G2
{
    void AddHead(int*);
};
struct LNode
{
    bool FUN_008256d0();
};

struct FUN_005436e0_shell : TESObjectCELL
{
    TESForm* FUN_005436e0(bool abCreateEditorID, void* apCopyMap);
};

// @fnv 0x005436e0
TESForm* FUN_005436e0_shell::FUN_005436e0(bool abCreateEditorID, void* apCopyMap)
{
    TESObjectCELL* pdupcell = 0;
    if (IsCellInterior())
    {
    }
    else
    {
        BSSimpleList<TESObjectREFR*>* pCurrentElementNext;
        pdupcell = dynamic_cast<TESObjectCELL*>(((::TESForm *)(reinterpret_cast<::FUN_004867a0_cls *>((((S004867a0*)this)))->FUN_004867a0((void *)(false), apCopyMap))));
        TESObjectLAND* pland;
        pland = *(TESObjectLAND**)((char*)this + 0x4c);
        if (pland)
        {
            TESObjectLAND* pdupland = dynamic_cast<TESObjectLAND*>(((TESForm*)pland)->DuplicateForm(false, apCopyMap));
            if (pdupland)
            {
                reinterpret_cast<::n547::Cell *>((((CellX*)pdupcell)))->SetObj((::n547::Obj *)(pdupland));
                reinterpret_cast<::fnv_005340e0::TESObjectLAND *>((pdupland))->FUN_005340e0((::fnv_005340e0::TESObjectCELL *)(pdupcell));
                ((TESForm*)pdupland)->v50(true);
            }
        }
        if (*(NavMeshCollection**)((char*)this + 0x64))
        {
            reinterpret_cast<::FUN_00557760_cls *>((((CellX*)pdupcell)))->SetHelper((::Helper_cls *)(::NavMeshCollection *)(new NavMeshCollection));
            NavMeshPtr spmesh;
            for (unsigned int i = 0; i < ((int)(reinterpret_cast<::FUN_00620b80_shell *>((*(NavMeshCollection**)((char*)this + 0x64)))->GetReferenceFlags())); i++)
            {
                NavMesh* pmesh = (NavMesh*)(unsigned int)(*(NavMeshCollection**)((char*)this + 0x64))->GetNavMeshAt(i);
                if (pmesh && !reinterpret_cast<::FUN_00440d80_shell *>((void *)(((RefH*)pmesh)))->FUN_00440d80())
                {
                    NavMesh* pdupMesh = dynamic_cast<NavMesh*>(((TESForm*)pmesh)->DuplicateForm(false, apCopyMap));
                    if (pdupMesh)
                    {
                        *(TESObjectCELL**)((char*)pdupMesh + 0x24) = pdupcell;
                        spmesh = MakeNavMeshPointer(pdupMesh);
                        reinterpret_cast<::NavShell2 *>(((*(NavMeshCollection**)((char*)pdupcell + 0x64))))->FUN_00469500((*(::NavMeshPtr *)&(const ::NiPointer< ::NavMesh> &)(spmesh)));
                    }
                }
            }
        }
        CellRefLockEnter();
        ListX templist;
        pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        while (pCurrentElementNext && !((LNode*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)*((void **)(new ((void *)(((LNode*)pCurrentElementNext))) ::Vec3()));
            if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)(((TempIsTemp*)pref)))->FUN_004077c0())
            {
                if (IsCellInterior() || reinterpret_cast<::FUN_005516c0 *>((((CellH*)this)))->IsCellPersistent() || !reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((((RefX*)pref)))->FUN_005653d0())
                    ((G2*)&templist)->AddHead((int*)&pref);
            }
            pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((::LNode *)(reinterpret_cast<::Callees *>((((LNode*)pCurrentElementNext)))->FUN_00726070()));
        }
        ::FUN_00541ae0((char *)this);
        pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)&templist;
        while (pCurrentElementNext && !((LNode*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)*((void **)(new ((void *)(((LNode*)pCurrentElementNext))) ::Vec3()));
            TESObjectREFR* pdupref = dynamic_cast<TESObjectREFR*>(((TESForm*)pref)->DuplicateForm(false, apCopyMap));
            if (pdupref)
            {
                reinterpret_cast<::fnv_00565480::RefPersistsStandin *>((((RefX*)pdupref)))->FUN_00565480(reinterpret_cast<::FUN_005516c0 *>((((CellH*)pdupcell)))->IsCellPersistent());
                reinterpret_cast<::CellView *>((((CellX*)pdupcell)))->FUN_00548230((::RefView *)(pdupref), false);
                ((TESForm*)pdupref)->v50(true);
            }
            pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((::LNode *)(reinterpret_cast<::Callees *>((((LNode*)pCurrentElementNext)))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>((((List_009e03e0*)&templist)))->RemoveAll();
    }
    return (TESForm*)pdupcell;
}
