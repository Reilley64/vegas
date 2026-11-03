
// src/fallout_shared/pathfinding/navmeshsearchhide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchhide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv_result_slot.h"
#include "fnv/decl/AvoidNodeList.h"
#include "fnv/decl/B690770Object.h"
#include "fnv/decl/DoorAccessData.h"
#include "fnv/decl/Dummy698030.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_0068f0a0_shell.h"
#include "fnv/decl/FUN_0068f230_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_006a5b30_shell.h"
#include "fnv/decl/FUN_006a6b00__NavMeshSearch.h"
#include "fnv/decl/FUN_006a94f0_shell.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_00885bd0_St.h"
#include "fnv/decl/GetCenterX_006a6eb0.h"
#include "fnv/decl/NavMesh.h"
#include "fnv/decl/NavMeshTriangleReference.h"
#include "fnv/decl/TESObjectDOOR.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/_Dummy_0069e390.h"
#include "fnv/decl/fnv_006dc990__Sdc990.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_00533000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006b9000.h"
#include "fnv/symbols_00984000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011d6000.h"
struct NavMeshSearchHide
{
    void FUN_006a9d60();
    void* DestroyIfFlagged(unsigned int flags);
};


// Calls FUN_006a9d60, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x006a9d30
void* NavMeshSearchHide::DestroyIfFlagged(unsigned int flags)
{
    FUN_006a9d60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct A9F60Point3
{
    float x;
    float y;
    float z;

    A9F60Point3 operator-(const A9F60Point3& pt) const;
};


struct A9F60Actor
{
    A9F60Point3 GetNodePosition(unsigned short usNode);
};

struct A9F60Entry
{
    int unk00;
    float m_fScore;
    A9F60Actor* m_pkActor;
    unsigned short m_usNode;
    unsigned short unk0E;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

struct A9F60Block256
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
};

struct A9F60Tracker
{
    A9F60Block256 unk0000;
    A9F60Block256 unk0100;
    A9F60Block256 unk0200;
    A9F60Block256 unk0300;
    A9F60Block256 unk0400;
    A9F60Block256 unk0500;
    A9F60Block256 unk0600;
    A9F60Block256 unk0700;
    A9F60Block256 unk0800;
    A9F60Block256 unk0900;
    A9F60Block256 unk0A00;
    A9F60Block256 unk0B00;
    A9F60Block256 unk0C00;
    A9F60Block256 unk0D00;
    A9F60Block256 unk0E00;
    A9F60Block256 unk0F00;
    A9F60Block256 unk1000;
    A9F60Block256 unk1100;
    A9F60Block256 unk1200;
    A9F60Block256 unk1300;
    A9F60Block256 unk1400;
    A9F60Block256 unk1500;
    A9F60Block256 unk1600;
    A9F60Block256 unk1700;
    A9F60Block256 unk1800;
    A9F60Block256 unk1900;
    A9F60Block256 unk1A00;
    A9F60Block256 unk1B00;
    A9F60Block256 unk1C00;
    A9F60Block256 unk1D00;
    A9F60Block256 unk1E00;
    A9F60Block256 unk1F00;
    int unk2000;
    int unk2004;
    int unk2008;
    int unk200C;
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201C;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202C;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203C;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204C;
    int unk2050;
    int unk2054;
    int unk2058;
    int unk205C;
    int unk2060;
    int unk2064;
    int unk2068;
    int unk206C;
    int unk2070;
    int unk2074;
    int unk2078;
    int unk207C;
    int unk2080;
    int unk2084;
    int unk2088;
    int unk208C;
    int unk2090;
    int unk2094;
    int unk2098;
    int unk209C;
    int unk20A0;
    int unk20A4;
    int unk20A8;
    int unk20AC;
    int unk20B0;
    int unk20B4;
    int unk20B8;
    A9F60Point3 m_kStartPoint;
    float m_fFirstLightParameter;

    void InitEntry(A9F60Entry* pkEntry, A9F60Actor* pkActor, unsigned short usNode);
};

struct NiPoint3
{
    float x, y, z;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};
// @fnv 0x006a9f60
void A9F60Tracker::InitEntry(A9F60Entry* pkEntry, A9F60Actor* pkActor, unsigned short usNode)
{
    pkEntry->m_pkActor = pkActor;
    pkEntry->m_usNode = usNode;
    A9F60Point3 kPos4 = pkActor->GetNodePosition(usNode);
    pkEntry->m_fVectorY = kPos4.x;
    pkEntry->m_fVectorZ = kPos4.y;
    pkEntry->m_fScalarPart = kPos4.z;
    A9F60Point3 kDiff = kPos4 - m_kStartPoint;
    float fScore6 = m_fFirstLightParameter - reinterpret_cast<::NiPoint3 *>((void *)&(kDiff))->ComputeMagnitude();
    FUN_005330e0(&fScore6, 0.0f, m_fFirstLightParameter);
    pkEntry->m_fScore = fScore6;
}

struct NavMeshTriangle
{
};

struct NavMeshStandIn
{
};

struct NavMeshTriRef
{
    NavMeshStandIn* m_pMesh;
    unsigned short m_usTri;
};

struct NavSearchNodeInfo
{
    float m_fCost;
    int unk04;
    NavMeshTriRef m_kRef;
};

struct NavSearchNode
{
    char pad00[0x1c];
    NavMeshStandIn* m_pMesh;
    unsigned short m_usTri;
    int m_iSide;
};

struct NavSearchNodeList
{
};

struct ActorPosSource
{
};

struct HideTarget
{
};

struct ActorStandIn
{
};

struct FloatSetting
{
};

struct TESForm;

struct DoorCheckSource
{
};

struct DoorFormStandIn;
struct DoorBase
{
};
struct TESFormStandIn
{
};

struct DoorCheck
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DoorCheck(TESForm* pkForm);
    ~DoorCheck();
};


struct HideSearch
{
    char pad0000[0x2058];
    DoorCheckSource* unk2058;
    char pad205c[0x20a4 - 0x205c];
    ActorStandIn* m_pActor;
    char pad20a8[0x20cc - 0x20a8];
    NiPoint3 m_kTargetPos;

    int FUN_006a7e00(int iResult);
    bool ExpandNeighbors(NavSearchNodeInfo* pkInfo, NavSearchNodeList* pkList);
};

struct HideTgtx
{
};

struct ActorX
{
};

struct MeshX
{
public:
    bool FindAdjacentEdge(unsigned short, int, ::MeshX **, unsigned short *, int *);
};
// @fnv 0x006aa000
bool HideSearch::ExpandNeighbors(NavSearchNodeInfo* pkInfo, NavSearchNodeList* pkList)
{
    NiPoint3 kPosX = ((std::uintptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((pkInfo))->FUN_0045cd60())) ? (*(::NiPoint3 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>(&(pkInfo->m_kRef))->FUN_006a6eb0({}))) : reinterpret_cast<::TaskQueueInterface *>((((::ActorPosSource *)(::GetOffsetC((std::intptr_t)(m_pActor))))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>());
    for (int i9 = 0; i9 < 3; i9++)
    {
        NavMeshStandIn* pMesh5;
        unsigned short usTriZ;
        int iUnkZ;
        if (reinterpret_cast<::MeshX *>((pkInfo->m_kRef.m_pMesh))->FindAdjacentEdge(pkInfo->m_kRef.m_usTri, i9, (::MeshX **)(::NavMeshStandIn **)(&pMesh5), &usTriZ, &iUnkZ))
        {
            int* pEdgeWork = ((int *)(reinterpret_cast<::FUN_0068f230_shell *>((pkInfo->m_kRef.m_pMesh))->FUN_0068f230(pkInfo->m_kRef.m_usTri, i9)));
            if (pEdgeWork && *pEdgeWork == 1)
                continue;
            float fMultY = 1.0f;
            if (reinterpret_cast<::FUN_00691140_shell *>((reinterpret_cast<::NavMesh *>((pMesh5))->GetTriangle(usTriZ)))->FUN_00691140(0x1000))
            {
                if (reinterpret_cast<::DoorAccessData *>((m_pActor))->ReadState98())
                    continue;
                else
                {
                    unsigned int uiFormIDOut = *((unsigned int *)(reinterpret_cast<::NavMesh *>((pMesh5))->GetClosedDoorInfo(usTriZ)));
                    TESForm* pForm2 = ::FUN_004839c0(uiFormIDOut);
                    if (pForm2)
                    {
                        DoorCheck kCheck_2(pForm2);
                        void* pSource_2 = ((void *)(reinterpret_cast<::FUN_006c9900_shell *>((unk2058))->FUN_006c9900()));
                        bool bResultZ;
                        if (!reinterpret_cast<::DoorAccessData *>(&(kCheck_2))->CanUnlockDoor((const ::PathingActorData *)(pSource_2), (::TESObjectREFR *)(pForm2), (*(bool *)(&bResultZ))))
                            continue;
                        if (reinterpret_cast<::TESObjectDOOR *>((((::DoorBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESFormStandIn*)pForm2)))->FUN_007af430()))))->IsTeleportDoor())
                            fMultY = 100.0f;
                    }
                }
            }
            if (::GetFloatAtOffset68((const char *)(m_pActor)) > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting1308)))))) &&
                reinterpret_cast<::FUN_00691140_shell *>((reinterpret_cast<::NavMesh *>((pMesh5))->GetTriangle(usTriZ)))->FUN_00691140(0x10))
                continue;
            NiPoint3 kCenterTmp = reinterpret_cast<::NavMesh *>((pMesh5))->GetNavMeshData(usTriZ);
            NiPoint3 kDeltaW = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCenterTmp))->FUN_00439ef0(&::ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)((::NiPoint3 *)&(kPosX)))));
            float fCost_ = reinterpret_cast<::FUN_00589850_Class *>((void *)&(kDeltaW))->FUN_00589850() * fMultY + pkInfo->m_fCost;
            float fExtraZ = 0.0f;
            if (((::HideTarget *)(reinterpret_cast<::_Dummy_0069e390 *>((m_pActor))->GetString())))
                fExtraZ = reinterpret_cast<::fnv_006dc990::Sdc990 *>((((::HideTarget *)(reinterpret_cast<::_Dummy_0069e390 *>((m_pActor))->GetString()))))->SumNodeValues((std::intptr_t)(&kCenterTmp));
            float fDist6 = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCenterTmp))->FUN_00439ef0(&::ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)((::NiPoint3 *)&(m_kTargetPos)))))))->FUN_00589850();
            float fNearOut = 1.0f - fDist6 / 512.0;
            fExtraZ += FUN_00404010(fNearOut, 0.0f);
            NiPoint3 kToTargetWork = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(m_kTargetPos))->FUN_00439ef0(&::ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)((::NiPoint3 *)&(kPosX)))));
            float fDot_2 = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kToTargetWork))->DotProduct((void *)&(kDeltaW));
            float fLenA_2 = reinterpret_cast<::NiPoint3 *>((void *)&(kToTargetWork))->ComputeMagnitude();
            float fLenBY = reinterpret_cast<::NiPoint3 *>((void *)&(kDeltaW))->ComputeMagnitude();
            if (fLenA_2 == 0.0 || fLenBY == 0.0)
                fDot_2 = 0.0f;
            else
                fDot_2 = fDot_2 / (fLenA_2 * fLenBY);
            fExtraZ += FUN_00404010(fDot_2, 0.0f);
            fCost_ = (1.0f + fExtraZ) * fCost_;
            NavSearchNode* pNode;
            switch (FUN_006a7e00(((int)(reinterpret_cast<::FUN_006a94f0_shell *>(this)->FUN_006a94f0((::NavMesh *)(pMesh5), usTriZ)))))
            {
            case 0:
                reinterpret_cast<::A9F60Tracker *>(this)->InitEntry((::A9F60Entry *)(pNode), (::A9F60Actor *)(pMesh5), usTriZ);
            case 1:
                pNode->m_pMesh = pkInfo->m_kRef.m_pMesh;
                pNode->m_usTri = pkInfo->m_kRef.m_usTri;
                pNode->m_iSide = i9;
                reinterpret_cast<::FUN_00438690 *>((pkList))->FUN_007cb2e0((unsigned int *)(::NavSearchNode **)(&pNode));
                break;
            }
        }
    }
    return true;
}

struct TriRef20
{
    MeshX* m_pMesh;
    unsigned short m_usTri;
    unsigned short unk06;
    NiPoint3 m_kPt;
};

struct InfoF
{
    MeshX* m_pMesh;
    unsigned short m_usTri;
    unsigned short unk06;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;

};

struct ParamX
{
};



struct Block256x
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
};

struct HideSearchX
{
    Block256x m_kBlocks[32];
    int unk2000;
    int unk2004;
    int unk2008;
    int unk200C;
    int unk2010;
    int unk2014;
    int unk2018;
    int unk201C;
    int unk2020;
    int unk2024;
    int unk2028;
    int unk202C;
    int unk2030;
    int unk2034;
    int unk2038;
    int unk203C;
    int unk2040;
    int unk2044;
    int unk2048;
    int unk204C;
    int unk2050;
    int unk2054;
    ActorX* unk2058;
    int unk205C;
    int unk2060;
    int unk2064;
    int unk2068;
    int unk206C;
    int unk2070;
    int unk2074;
    int unk2078;
    int unk207C;
    int unk2080;
    int unk2084;
    int unk2088;
    int unk208C;
    int unk2090;
    int unk2094;
    int unk2098;
    int unk209C;
    int unk20A0;
    ActorX* m_pActor;
    TriRef20 m_kInfo;
    NiPoint3 m_kStartPoint;
    float m_fFirstLightParameter;
    NiPoint3 m_kTargetPos;

    void FUN_006a7c90(int iPacked, InfoF* pkInfo, float fVal);
    void FUN_006a7d60(ParamX* pkObj, int iArg, int iOne);
    int SetupActorTarget(ActorX* pkActor, TriRef20* pkInfo, ParamX* pkObj, std::intptr_t iArg);
};

// @fnv 0x006a9d80
int HideSearchX::SetupActorTarget(ActorX* pkActor, TriRef20* pkInfo, ParamX* pkObj, std::intptr_t iArg)
{
    unk2058 = pkActor;
    m_pActor = pkActor;
    m_kInfo = *pkInfo;

    NiPoint3 kActorPos5 = reinterpret_cast<::TaskQueueInterface *>((((::ActorPosSource *)(::GetOffsetC((std::intptr_t)(pkActor))))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>());
    m_kStartPoint = ::NiPoint3::ZERO;
    m_fFirstLightParameter = 0.0f;
    if (((::HideTgtx *)(reinterpret_cast<::_Dummy_0069e390 *>((m_pActor))->GetString())))
    {
        m_fFirstLightParameter = reinterpret_cast<::AvoidNodeList *>((((::HideTgtx *)(reinterpret_cast<::_Dummy_0069e390 *>((m_pActor))->GetString()))))->FUN_006dc9f0((*(const ::NiPoint3 *)(&kActorPos5)), (*(::NiPoint3 *)(&m_kStartPoint)));
    }

    InfoF kInfo3;
    kInfo3.m_pMesh = pkInfo->m_pMesh;
    kInfo3.m_usTri = pkInfo->m_usTri;
    NiPoint3 kTmp_2 = reinterpret_cast<::NavMesh *>((kInfo3.m_pMesh))->GetNavMeshData(kInfo3.m_usTri);
    kInfo3.m_fVectorY = kTmp_2.x;
    kInfo3.m_fVectorZ = kTmp_2.y;
    kInfo3.m_fScalarPart = kTmp_2.z;

    NiPoint3 kTriPt2;
    NiPoint3 kDiff = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((::NiPoint3 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>(&(kInfo3))->FUN_006a6eb0((::P3 *)(::NiPoint3 *)(&kTriPt2))))))->FUN_00439ef0(&::ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)((::NiPoint3 *)&(m_kStartPoint)))));
    float fVal6 = m_fFirstLightParameter - reinterpret_cast<::NiPoint3 *>((void *)&(kDiff))->ComputeMagnitude();
    FUN_005330e0(&fVal6, 0.0f, m_fFirstLightParameter);

    FUN_006a7c90(((int)(reinterpret_cast<::FUN_006a94f0_shell *>(this)->FUN_006a94f0((::NavMesh *)(kInfo3.m_pMesh), kInfo3.m_usTri))), &kInfo3, fVal6);

    m_kTargetPos = reinterpret_cast<::TaskQueueInterface *>((((::ActorPosSource *)(::FUN_00984230((char *)(m_pActor))))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>());

    FUN_006a7d60(pkObj, iArg, 1);
    return !reinterpret_cast<::FUN_0076b610_Class *>((pkObj))->FUN_0076b610();
}


struct FUN_006815c0
{
    FUN_006815c0();
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
};


struct NavMesh6aa4
{
};

struct NavInfo6aa4
{
};

struct NavList6aa4
{
    NavMesh6aa4* m_pkMesh;
};

struct NavData6aa4
{
    float m_fCost;
    int unk04;
    NavMeshTriRef m_kRef;
};

struct Target6aa4
{
};

struct Range6aa4
{
};

struct FUN_006aa470_cls
{
    char pad0000[0x20a4];
    Range6aa4* m_pkActor;
    char pad20a8[0x20cc - 0x20a8];
    NiPoint3 m_kTargetPos;

    bool FUN_006aa470(NavData6aa4* pkData);
};

// @fnv 0x006aa470
bool FUN_006aa470_cls::FUN_006aa470(NavData6aa4* pkData)
{
    NavList6aa4* pkList = ((::NavList6aa4 *)(reinterpret_cast<::TESTopicInfoData *>((pkData))->GetLinkToList()));
    NavInfo6aa4* pkInfo7 = ((::NavInfo6aa4 *)(reinterpret_cast<::NavMeshTriangleReference *>((pkList))->FUN_006a78d0()));
    if (!reinterpret_cast<::B690770Object *>((pkInfo7))->HasFlags())
        return false;

    NiPoint3 kPos = (*(::NiPoint3 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>(&(pkData->m_kRef))->FUN_006a6eb0({})));
    float aFLength = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(m_kTargetPos))->FUN_00439ef0(&::ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)((::NiPoint3 *)&(kPos)))))))->FUN_00589850();
    if (aFLength < reinterpret_cast<::FUN_00885bd0_St *>((m_pkActor))->FUN_00885bd0())
        return false;

    NavMesh6aa4* pkMesh6 = pkList->m_pkMesh;
    unsigned short usA5, usB, usC;
    reinterpret_cast<::FUN_006a5b30_shell *>((pkInfo7))->GetTripleShorts((short *)(unsigned short *)(&usA5), (short *)(unsigned short *)(&usB), (short *)(unsigned short *)(&usC));
    FUN_006815c0 kOut3;
    bool bFound8 = false;
    ::FUN_006b9790((*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((pkMesh6))->FUN_0068f0a0(usA5))), (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((pkMesh6))->FUN_0068f0a0(usB))), (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((pkMesh6))->FUN_0068f0a0(usC))), m_kTargetPos,
                 (::NiPoint3Out *)(class ::FUN_006815c0 *)(&kOut3));
    if (kOut3.m_fCoefficientA < ::_DAT_01012060 && ((unsigned short)(reinterpret_cast<::Dummy698030 *>((pkInfo7))->FUN_00698030(1))) > 0)
        bFound8 = true;
    else if (kOut3.m_fC < ::_DAT_01012060 && ((unsigned short)(reinterpret_cast<::Dummy698030 *>((pkInfo7))->FUN_00698030(0))) > 0)
        bFound8 = true;
    if (!bFound8)
        return false;

    float fDist_2 = 0.0f;
    if (((::Target6aa4 *)(reinterpret_cast<::_Dummy_0069e390 *>((m_pkActor))->GetString())))
        fDist_2 = reinterpret_cast<::fnv_006dc990::Sdc990 *>((((::Target6aa4 *)(reinterpret_cast<::_Dummy_0069e390 *>((m_pkActor))->GetString()))))->SumNodeValues((std::intptr_t)(&kPos));
    return fDist_2 <= ::_DAT_01012060;
}

struct NavMeshSearch
{
};
extern int DAT_0106b7dc;

// @fnv 0x006a9d60
void NavMeshSearchHide::FUN_006a9d60()
{
    *reinterpret_cast<void**>(this) = &DAT_0106b7dc;
    reinterpret_cast<::FUN_006a6b00::NavMeshSearch *>((reinterpret_cast<NavMeshSearch*>(this)))->FUN_006a6b00::NavMeshSearch::~NavMeshSearch();
}
