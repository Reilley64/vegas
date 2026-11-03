// fallout/ai/highactorculler_decls.h: declares NiBound, TESObjectREFR, MobileObject, HighActorCullerCell, TESWorldSpace and more
#ifndef FNV_HIGHACTORCULLER_DECLS_H
#define FNV_HIGHACTORCULLER_DECLS_H

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00819a50_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_009d9f20__FUN_009d9f20_shell.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_011de000.h"
#include "NiPoint3.h"

class NiAVObject;
class NiNode;
class BSFadeNode;
class BSOcclusionPlane;
class BSMultiBoundNode;
class BSMultiBound;
class BSMultiBoundSphere;
class NiCullingProcess;
class NiCamera;
class BSPortalGraph;

class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
};

// Only the methods used by this unit are declared for pointer receivers.
class TESObjectREFR
{
  public:
};
class MobileObject : public TESObjectREFR
{
};
class HighActorCullerCell : public TESObjectCELL
{
  public:
};
class TESWorldSpace
{
  public:
    BSPortalGraph* FUN_006698d0();
};
class TES
{
  public:
};

class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void* GetType();
    virtual NiNode* GetNiNode();
    virtual BSFadeNode* GetFadeNode();
};
class BSFadeNode : public NiAVObject
{
  public:
    bool FUN_00552470() const;
};
class NiCamera : public NiAVObject
{
  public:
    const NiPoint3& FUN_0045bb80() const;
};

class NiFrustum
{
  public:
    float m_fLeftBound, m_fRightBound, m_fTopBound, m_fBottomBound, m_fNearPlane, m_fFarPlane;
    bool m_bOrthographic;
};
class NiPlane
{
  public:
    NiPoint3 m_kPlaneNormal;
    float m_fPlaneConstant;
};
class NiFrustumPlanes
{
  public:
    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
};
class NiCullingProcess
{
  public:
    virtual void* GetRTTI();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void Process(NiAVObject* object);
    const bool m_bUseFrustum;
    void* m_pVisibleSet;
    const NiCamera* m_pkAccumulationCamera;
    NiFrustum m_kCameraFrustum;
    NiFrustumPlanes m_kFrustumPlanes;
};
class BSFadeNodeCuller : public NiCullingProcess
{
};

class BSMultiBoundSphere
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void SetGridPosition(const NiPoint3& center);
    char _pdbpad_4[8];
    char Center[12];
    float Radius;
};
class BSMultiBoundNode
{
  public:
    bool CheckProcStateAndPlane(NiPoint3 viewPoint, NiCullingProcess& culler, BSOcclusionPlane* plane);
};
template <> class NiPointer<BSMultiBoundSphere>
{
  public:
    BSMultiBoundSphere* m_pObject;
    BSMultiBoundSphere* operator->() const;
};
template <> class NiPointer<BSMultiBoundNode>
{
  public:
    BSMultiBoundNode* m_pObject;
    BSMultiBoundNode* operator->() const;
};
template <>
class NiTPointerListBase<NiTPointerAllocator<unsigned int>, BSOcclusionPlane*>
    : public NiTListBase<NiTPointerAllocator<unsigned int>, BSOcclusionPlane*>
{
  public:
};
template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
};
class BSPortalGraph
{
  public:
};
class BSOcclusionPlane
{
  public:
};
class MobIterOperator
{
  public:
    virtual void Operate(MobileObject* mobile);
    PROCESS_TYPE eType;
};
class HighActorCuller : public MobIterOperator
{
  public:
    virtual void Operate(MobileObject* mobile);
    BSFadeNodeCuller m_kFadeNodeCuller;
    NiPointer<BSMultiBoundNode> m_pMultiBoundNode;
    NiPointer<BSMultiBound> m_pMultiBound;
    NiPointer<BSMultiBoundSphere> m_spMultiBoundSphere;
};
#endif
