
// src/fallout_shared/bgsdecalmanager_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/bgsdecalmanager.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv/decl/CameraPass__Camera.h"
#include "fnv/decl/DecalSetup.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004a0350_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_0068de30_holder.h"
#include "fnv/decl/FUN_0068dea0_cls.h"
#include "fnv/decl/FUN_00c46270_Class.h"
#include "fnv/decl/NavEntryOwner.h"
#include "fnv/decl/S694a0.h"
#include "fnv/decl/S_00a59e00.h"
#include "fnv/decl/TreeEvaluator.h"
#include "fnv/decl/WorkerS694a0.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004a0330__FUN_004a0330_shell.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/decl/fnv_00c49100__ActorTable.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_011c5000.h"
#include "bgsdecalmanager_decls.h"
#include "bgsdecalmanager_types_BGSDecalManager.h"
#include "bgsdecalmanager_types_BSTempEffectSimpleDecal.h"

struct HostV;
struct ObjV
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(), v32(), v33(),
        v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49(), v50(), v51(), v52();
    virtual void Attach(HostV* pkHost);
    char pad04[0x2c];
    unsigned int m_uiValue1;
    bool TestFlag(unsigned int uiMask) const
    {
        return (m_uiValue1 & uiMask) != 0;
    }
};
struct CtrlV
{
    char pad[0x28];
    int m_i28;
    bool IsEmpty() const
    {
        return m_i28 == 0;
    }
};
struct HostV
{
    char pad[0x8c];
    void* m_pv8c;
    int m_iFadeIndex;
    char pad94[0x2c];
    CtrlV* m_pkCtrl;
    bool HasX() const
    {
        return (bool)m_pv8c;
    }
    void FUN_00c4ee90(ObjV* pkObj);
};
// @fnv 0x00c4ee90
void HostV::FUN_00c4ee90(ObjV* pkObj)
{
    if (m_iFadeIndex != 2 && m_iFadeIndex != 1)
    {
        ObjV* pkTmp = pkObj;
        if (pkTmp->TestFlag(0x1000))
        {
            if (!pkTmp->TestFlag(0x100000))
                pkObj->Attach(this);
        }
        else if (!m_pkCtrl || m_pkCtrl->IsEmpty() || m_iFadeIndex == 3)
        {
            if (pkObj->TestFlag(0x800) || !HasX())
                pkObj->Attach(this);
            else
                reinterpret_cast<::WorkerS694a0 *>(this)->FUN_00a694e0((::NiAVObject *)(pkObj));
        }
        else if (pkObj->TestFlag(0x800) || ((!m_pkCtrl || m_pkCtrl->IsEmpty()) && !HasX()))
        {
            pkObj->Attach(this);
        }
        else
        {
            int iState = ((int)(reinterpret_cast<::NavEntryOwner *>((m_pkCtrl))->BuildEntryValueArray()));
            if (reinterpret_cast<::TreeEvaluator *>((m_pkCtrl))->FUN_00c491a0((::TreeQuery *)(pkObj)))
                pkObj->Attach(this);
            reinterpret_cast<::fnv_00c49100::ActorTable *>((m_pkCtrl))->SetActorList((int *)(iState));
        }
    }
    else if (m_iFadeIndex == 1)
    {
        pkObj->Attach(this);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiCullingProcess;
class NiNodeX;
class NiObj
{
  public:
    virtual void vf00();
    virtual void DeleteThis();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c(NiNodeX* n);
    long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class NiNodeX : public NiObj
{
  public:
};
class NiAVObject
{
  public:
};
class SceneMgr;
class SceneMgr
{
  public:
    int unk00;
    int unk04;
    NiNodeX* unk08;
};
inline NiNodeX* GetRoot()
{
    SceneMgr* m = (*reinterpret_cast<::SceneMgr * *>(&::NiRenderer::ms_pRenderer));
    int u1;
    int u2;
    return m->unk08;
}
class Accum : public NiObj
{
};
class AccPtr
{
  public:
    NiObj* m_pObject;
    __forceinline AccPtr(NiObj* o = 0)
    {
        m_pObject = o;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~AccPtr()
    {
        int u3;
        int u4;
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    __forceinline NiObj* operator->()
    {
        return m_pObject;
    }
    __forceinline operator NiObj*()
    {
        return m_pObject;
    }
    AccPtr& FUN_0066b0d0(NiNodeX* p);
};
class NiCullingProcess
{
  public:
    virtual void vf00();
    int unk04;
    int unk08;
    NiNodeX* unk0c;
    void FUN_00c4f070(NiNodeX* a, NiAVObject* b, int c);
};

// @fnv 0x00c4f070
void NiCullingProcess::FUN_00c4f070(NiNodeX* a, NiAVObject* b, int c)
{
    if (!a || !b)
        return;
    unk0c = a;
    reinterpret_cast<::S694a0 *>(this)->FUN_00a694a0((char*)unk0c + 0xdc);
    int saved = 0;
    if (c)
    {
        saved = unk08;
        unk08 = c;
    }
    AccPtr sp;
    if (!unk08)
    {
        reinterpret_cast<::FUN_00c46270_Class *>(&(sp))->AssignRefCounted((*(const ::FUN_00c46270_Class *)((char*)this + 0xc4)));
        if (!sp)
            sp.FUN_0066b0d0(GetRoot());
        if (sp)
            sp->vf8c(a);
    }
    reinterpret_cast<::S_00a59e00 *>((b))->FUN_00a59e00((::S_00a59e00_Arg *)&(*this));
    if (c)
        unk08 = saved;
}


class NiFixedString
{
  public:
    const char* m_kHandle;
    operator const char*() const
    {
        return m_kHandle;
    }
};

class NiGeometry
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    NiFixedString m_kName;
    const char* GetName() const
    {
        return m_kName;
    }
};

class NiAccumulator
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual bool RegisterObject(NiGeometry* pkGeom);
};

template <class T> class NiPtr
{
  public:
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

class BSCullingProcess : public NiCullingProcess
{
  public:
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAc, unkB0, unkB4, unkB8, unkBc;
    int unkC0;
    NiPtr<NiAccumulator> m_acRendererDataA;

    void FUN_00c4f1d0(NiGeometry& kVisible);
};

// @fnv 0x00c4f1d0
void BSCullingProcess::FUN_00c4f1d0(NiGeometry& kVisible)
{
    bool bRegistered = false;
    if (m_acRendererDataA)
    {
        if (m_acRendererDataA->RegisterObject(&kVisible))
            bRegistered = true;
    }
    if (!bRegistered)
    {
        ::FUN_00a29680();
    }
}
