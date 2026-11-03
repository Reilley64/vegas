// fallout_shared/pathfinding/pathingrequest.cpp: PathingRequest, PathingAvoidNodeArray, PathingRequestDebugView (24 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/DebugLocation.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include "fnv/decl/FUN_006d3ac0_Class.h"
#include "fnv/decl/FUN_006d3ae0.h"
#include "fnv/decl/FUN_006dc910_shell.h"
#include "fnv/decl/FUN_006e29b0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiPtr.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESObjectTREE.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/_Dummy_0069e390.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_006780e0__TESPackageExt.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011de000.h"
#include "pathingrequest_types_PathingRequest.h"
#include "pathingrequest_types_TESPackage.h"
#include "TESObjectREFR.h"
#include "pathingrequest_decls.h"
#include "fnv/decl/FUN_006a7910_shell.h"

// @fnv 0x006e38d0
void PathingRequest::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    if (reinterpret_cast<BGSLoadFormBufferView*>(buffer)->GetVersion() < 14)
    {
        m_bCanWalk = false;
        Actor* actor = reinterpret_cast<BGSLoadFormBufferView*>(buffer)->GetActor();
        if (actor)
        {
            TESPackage* package = reinterpret_cast<::FUN_009344a0_shell *>((reinterpret_cast<MobileObject*>(actor)))->FUN_009344a0();
            if (package &&
                ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<Calendar*>(package)))->FUN_009611e0())) ==
                    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_ESCORT_ACTOR &&
                ((::TESObjectREFR *)(reinterpret_cast<::fnv_006780e0::TESPackageExt *>((package))->FUN_006780e0((::fnv_006780e0::V *)(actor), false))) == reinterpret_cast<TESObjectREFR*>(::_g_thePlayer))
                m_bCanWalk = true;
        }
    }
}

// Creates and returns a new pathing request object matching the given type, warning and returning null for unknown types.
// @fnv 0x006e2f80
PathingRequest* PathingRequest::CreateRequestForType(PATHING_REQUEST_TYPE type)
{
    switch (type)
    {
    case 0:
        return new PathingRequest;
    case 1:
        return new FUN_006e4080;
    case 2:
        return new PathingRequestClosePoint;
    case 3:
        return new PathingRequestFlee;
    case 4:
        return new PathingRequestCoveredMove;
    case 5:
        return new PathingRequestLOS;
    case 7:
        return new PathingRequestOptimalLocation;
    case 8:
        return new FUN_006e4a50;
    default:
        ::FUN_005b5e40();
        return 0;
    }
}

// @fnv 0x006e2420
PathingRequest::PathingRequest() : m_pPathingAvoidNodeArray(0)
{
    m_fFirstValueAfterActorData = runtimeFloatSettingDefault65;
    m_fSecondValueAfterActorData = 1.0f;
    PathingActorSpatialData = 180.0f;
    fWeaponSpread = TESPackage::GetPackageDefaultFloat();
    m_fCenterRadius = 0.0f;
    static_cast<NiPoint3&>(Center) = ::NiPoint3::ZERO;
    m_fPathingRadius = 0.0f;
    m_fAvoidanceRadius = 0.0f;
    bCantOpenDoors = false;
    bFaceTargetAtGoal = false;
    PathingOptions = false;
    bAllowIncompletePath = true;
    m_bAllowDoorTraversal = true;
    bCanSwim = true;
    bCanFly = false;
    m_bCanWalk = false;
    m_bCanJump = false;
    m_bCanClimb = false;
    m_bCanUseDoors = false;
    m_bCanRun = false;
    bIgnoreLocks = false;
    m_iRequestType = 3;
    m_bCanOpenDoors = false;
    m_fFloatAfterCenter = 0.0f;
}

// Calls Destruct on this, frees the object with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006e3880
PathingAvoidNodeArray* PathingAvoidNodeArray::Destroy(unsigned int flags)
{
    reinterpret_cast<::PathingAvoidNodeArray *>((reinterpret_cast<PathingAvoidNodeArrayDestructionView*>(this)))->::PathingAvoidNodeArray::~PathingAvoidNodeArray();
    if (flags & 1)
        ::FUN_00aa1460(this, 24);
    return this;
}

struct FUN_006db090_shell
{
    void FreeBuffer(void* apBuffer);
};

// @fnv 0x006db090
void FUN_006db090_shell::FreeBuffer(void* apBuffer)
{
    ::FUN_00401030(apBuffer);
}

void FUN_006e2620(void*);

struct FUN_006e25e0_impl
{
    void* FUN_006e25e0(unsigned int flags);
};

struct FUN_006e2980_shell : public PathingRequest
{
    void FUN_006e2980(NiPoint3*, float);
};
// Copies origin, destination, radii, smoothing and flag fields from this PathingRequest into the given request.
// @fnv 0x006e2750
void PathingRequest::CopyTo(PathingRequest* request)
{
    reinterpret_cast<::FUN_006d3ac0_Class *>((request))->AssignPathingLocation((*(const ::PathingLocation *)(((::PathingLocation *)(::GetOffsetC((int)this))))));
    request->SetDestination(((::PathingLocation *)(::FUN_006a9540((char *)this))));
    request->SetActorRadius(GetActorRadius());
    reinterpret_cast<::FUN_006d3ae0 *>((request))->SetValue(::GetFloatAtOffset68((const char *)this));
    reinterpret_cast<::FUN_006e29b0_Class *>((request))->FUN_006e29b0((const ::Copy9 *)(::PathingActorData *)(reinterpret_cast<::FUN_006c9900_shell *>(this)->FUN_006c9900()));
    request->SetCenterRadius(GetCenterRadius());
    NiPoint3 center = FUN_006a7910();
    reinterpret_cast<::FUN_006e2980_shell *>((request))->FUN_006e2980((::NiPoint3 *)&(center), GetTargetRadius());
    request->SetSmoothingRandomness(GetSmoothingRandomness());
    request->SetAvoidNodeArray(((::BSSimpleArray<void *, 1024> *)(reinterpret_cast<::_Dummy_0069e390 *>(this)->GetString())));
    request->SetSmoothingRandomness(GetSmoothingRandomness());
    reinterpret_cast<::TESObjectTREE *>((request))->UpdateRustleSpeed(GetGoalZDelta());
    request->bCantOpenDoors = bCantOpenDoors;
    request->m_fPathingRadius = m_fPathingRadius;
    request->m_fAvoidanceRadius = m_fAvoidanceRadius;
    request->bFaceTargetAtGoal = bFaceTargetAtGoal;
    request->bAllowIncompletePath = bAllowIncompletePath;
    request->m_bAllowDoorTraversal = m_bAllowDoorTraversal;
    request->bCanSwim = bCanSwim;
    request->bCanFly = bCanFly;
    request->m_bCanWalk = m_bCanWalk;
    request->m_bCanJump = m_bCanJump;
    request->m_bCanClimb = m_bCanClimb;
    request->m_bCanUseDoors = m_bCanUseDoors;
    request->m_bCanRun = m_bCanRun;
    request->bIgnoreLocks = bIgnoreLocks;
    request->m_iRequestType = m_iRequestType;
    request->m_bCanOpenDoors = m_bCanOpenDoors;
}

// Stores arCenter at offset 0x7c and afOriginRadius at offset 0x78 of this object.
// @fnv 0x006e2980
void FUN_006e2980_shell::FUN_006e2980(NiPoint3* apCenter, float afOriginRadius)
{
    (*static_cast<NiPoint3 *>(&this->Center)) = *apCenter;
    this->m_fCenterRadius = afOriginRadius;
}

struct FUN_006e2b50_shell : public PathingRequest
{
    void SetCantOpenDoors(bool);
};

// @fnv 0x006e2b50
void FUN_006e2b50_shell::SetCantOpenDoors(bool abCantOpenDoors)
{
    this->bCantOpenDoors = abCantOpenDoors;
}

struct FUN_006e2b70_shell : public PathingRequest
{
    void SetCanSwim(bool);
};

// @fnv 0x006e2b70
void FUN_006e2b70_shell::SetCanSwim(bool abCanSwim)
{
    this->bCanSwim = abCanSwim;
}

struct FUN_006e2bb0_shell : public PathingRequest
{
    void SetInitialPathHeading(float);
};

// Stores afInitialPathHeading at offset 0x90 and sets the bool at offset 0xa0 to true.
// @fnv 0x006e2bb0
void FUN_006e2bb0_shell::SetInitialPathHeading(float afInitialPathHeading)
{
    this->m_fAvoidanceRadius = afInitialPathHeading;
    this->m_bCanJump = true;
}

struct FUN_006e3a80
{
    virtual void va();
    char pad[12];
    FUN_006e3a80();
    ~FUN_006e3a80();
};
struct FUN_006e3960 : public FUN_006e3a80, public PathingInfo
{
    FUN_006e3960();
    ~FUN_006e3960();
};
// @fnv 0x006e3850
PathingAvoidNodeArray::PathingAvoidNodeArray()
{
    new ((void *)this) ::FUN_006e3960();
    *reinterpret_cast<void**>(data) = &DAT_0106d1e4;
    *reinterpret_cast<void**>(data + 16) = &DAT_0106d1d8;
}
// @fnv 0x006e3960
FUN_006e3960::FUN_006e3960()
{}

struct FUN_006e3ab0
{
    virtual void va();
    char pad[12];
    ~FUN_006e3ab0();
};
struct FUN_00496910
{
    virtual void vb();
    ~FUN_00496910();
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006e39d0 : public FUN_006e3ab0, public FUN_00496910
{
    ~FUN_006e39d0();
};
// @fnv 0x006e38b0
PathingAvoidNodeArray::~PathingAvoidNodeArray()
{
    reinterpret_cast<::FUN_006e39d0 *>(this)->::FUN_006e39d0::~FUN_006e39d0();
}
// Destructor that calls Clear(true) on the object at this address.
// @fnv 0x006e39d0
FUN_006e39d0::~FUN_006e39d0()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}

struct EBase
{
    unsigned char ebasePad[8];
    virtual void vfn0();
    ~EBase();
};
struct _Mem_2064
{
    unsigned char data[0x28];
    ~_Mem_2064();
};
struct PathingRequestMember94
{
    unsigned char data[4];
    ~PathingRequestMember94();
};
class FUN_006e2620 : public EBase
{
  public:
    _Mem_2064 m0c;
    _Mem_2064 m34;
    unsigned char pad5c[0x38];
    PathingRequestMember94 m94;
    ~FUN_006e2620();
};
// Calls FUN_006e2620 on this, then if bit 0 of flags is set calls FUN_00aa1460 with size 0xb0, and returns this.
// @fnv 0x006e25e0
void* FUN_006e25e0_impl::FUN_006e25e0(unsigned int flags)
{
    reinterpret_cast<class ::FUN_006e2620 *>((this))->FUN_006e2620::~FUN_006e2620();
    if (flags & 1)
        FUN_00aa1460(this, 0xb0);
    return this;
}
// @fnv 0x006e2620
FUN_006e2620::~FUN_006e2620()
{}

struct BSSimpleArray_PathingAvoidNode_1024
{
    PathingAvoidanceNode* AllocateBuffer(unsigned int aiSizeInItem);
public:
    void SetSize(unsigned int, bool);
};
// Loads a PathingRequest from a BGSLoadFormBuffer, reading origin/destination, flags, and version-gated fields, then a count-driven array of avoid nodes.
// @fnv 0x006e34f0
void PathingRequest::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<PathingLocationLoadView*>(&Origin)->LoadGame(buffer);
    reinterpret_cast<PathingLocationLoadView*>(&Destination)->LoadGame(buffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fFirstValueAfterActorData), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fSecondValueAfterActorData), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&PathingActorSpatialData), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&fWeaponSpread), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fCenterRadius), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fFloatAfterCenter), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fPathingRadius), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bFaceTargetAtGoal), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bCantOpenDoors), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&PathingOptions), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bAllowIncompletePath), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bAllowDoorTraversal), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bCanSwim), 1);
    if (buffer->GetVersion() >= 13)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bCanWalk), 1);
    }
    if (buffer->GetVersion() >= 15)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fAvoidanceRadius), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bCanJump), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bCanClimb), 1);
    }
    if (buffer->GetVersion() >= 18)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&Center), 12);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bCanUseDoors), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bCanRun), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bIgnoreLocks), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_iRequestType), 4);
    }
    if (buffer->GetVersion() >= 20)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bCanFly), 1);
    }
    if (buffer->GetVersion() >= 21)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bCanOpenDoors), 1);
    }
    unsigned int count = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
    if (count)
    {
        reinterpret_cast<::NiPtr *>((reinterpret_cast<PathingAvoidPointerView*>(&m_pPathingAvoidNodeArray)))->Assign((char *)(::PathingAvoidNodeArray *)(new PathingAvoidNodeArray));
        reinterpret_cast<::BSSimpleArray_PathingAvoidNode_1024 *>((((::PathingAvoidNodeArray *)(::FUN_00559450((int *)(reinterpret_cast<PathingAvoidPointerView*>(&m_pPathingAvoidNodeArray)))))))->SetSize(count, true);
        for (unsigned int i = 0; i < count; ++i)
        {
            PathingAvoidanceNode* node =
                ((::PathingAvoidanceNode *)(reinterpret_cast<::S3e60 *>((((::PathingAvoidNodeArray *)(::FUN_00559450((int *)(reinterpret_cast<PathingAvoidPointerView*>(&m_pPathingAvoidNodeArray)))))))->FUN_006a1400(i)));
            reinterpret_cast<::FUN_006dc910_shell *>((node))->LoadPathingAvoidNode(buffer);
        }
    }
}

// Allocates a buffer of aiSizeInItem elements of 0x24 bytes each and returns the pointer.
// @fnv 0x006e3c10
PathingAvoidanceNode* BSSimpleArray_PathingAvoidNode_1024::AllocateBuffer(unsigned int aiSizeInItem)
{
    PathingAvoidanceNode* pBuffer = static_cast<PathingAvoidanceNode*>(::FUN_00401000(aiSizeInItem * 0x24));
    return pBuffer;
}


struct FUN_006e3c40_shell
{
    void* FUN_006e3c40(void* apBuffer, unsigned int aiNewSizeInItem);
};

// @fnv 0x006e3c40
void* FUN_006e3c40_shell::FUN_006e3c40(void* apBuffer, unsigned int aiNewSizeInItem)
{
    return ::Reallocate(apBuffer, aiNewSizeInItem * 0x24);
}

struct FUN_006dad70_shell : public PathingRequest
{
    void DestroyPathingRequest();
};

// @fnv 0x006dad70
void FUN_006dad70_shell::DestroyPathingRequest()
{
    reinterpret_cast<class ::FUN_006e2620 *>(this)->FUN_006e2620::~FUN_006e2620();
}

struct FUN_006e2b90
{
    void SetFlag(unsigned char value);
};

// @fnv 0x006e2b90
void FUN_006e2b90::SetFlag(unsigned char value)
{
    ((unsigned char*)this)[0x9e] = value;
}

struct BGSSaveGameBuffer
{
    void FUN_00865f60(unsigned int);
};

struct BGSSaveFormBuffer : public BGSSaveGameBuffer
{
};

struct ArrSI
{
};

struct FUN_006dc890_Class
{
    void FUN_006dc890(BGSSaveFormBuffer*);
};

struct PathingLocationStandIn
{
    virtual void SaveGame(BGSSaveFormBuffer*) = 0;
};

struct FUN_006e3230_shell
{
    void FUN_006e3230(BGSSaveFormBuffer*);
};

// Serializes this object's fields and two embedded pathing locations into the save buffer, then saves each avoid node referenced at offset 0x94.
// @fnv 0x006e3230
void FUN_006e3230_shell::FUN_006e3230(BGSSaveFormBuffer* buffer)
{
    unsigned int i;
    unsigned int isaveGameCount;
    PathingAvoidanceNode* avoidNode;

    reinterpret_cast<PathingLocationStandIn*>(reinterpret_cast<char*>(this) + 0x0c)->SaveGame(buffer);
    reinterpret_cast<PathingLocationStandIn*>(reinterpret_cast<char*>(this) + 0x34)->SaveGame(buffer);

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x68), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x6c), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x70), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x74), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x78), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x88), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x8c), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x99), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x98), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9a), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9b), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9c), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9d), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9f), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x90), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa0), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa1), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x7c), 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa2), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa3), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa4), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa8), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9e), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xac), 1, 0);

    i = ((::PathingAvoidNodeArray *)(::FUN_00559450((int *)(reinterpret_cast<PathingAvoidPointerView*>(reinterpret_cast<char*>(this) + 0x94)))))
            ? ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(
                  ((::PathingAvoidNodeArray *)(::FUN_00559450((int *)(reinterpret_cast<PathingAvoidPointerView*>(reinterpret_cast<char*>(this) + 0x94))))))))->GetName()))
            : 0;

    buffer->FUN_00865f60(i);

    for (isaveGameCount = 0; isaveGameCount < i; ++isaveGameCount)
    {
        avoidNode = ((::PathingAvoidanceNode *)(reinterpret_cast<::S3e60 *>((((::PathingAvoidNodeArray *)(::FUN_00559450((int *)(reinterpret_cast<PathingAvoidPointerView*>(reinterpret_cast<char*>(this) + 0x94)))))))->FUN_006a1400(isaveGameCount)));
        reinterpret_cast<FUN_006dc890_Class*>(avoidNode)->FUN_006dc890(buffer);
    }
}

struct Base_006e26a0
{
    virtual void v00();
    int unk04;
    int unk08;

    Base_006e26a0();
    ~Base_006e26a0();
};

struct Member28_006e26a0
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

    Member28_006e26a0();
    ~Member28_006e26a0();
};

struct Member20_006e26a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    Member20_006e26a0();
};

struct Member18_006e26a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    Member18_006e26a0();
};

struct Member4_006e26a0
{
    int unk00;

    Member4_006e26a0(int aValue);
    ~Member4_006e26a0();
};

struct Owner_006e26a0
{
};

struct FUN_006e26a0 : Base_006e26a0
{
    Member28_006e26a0 m_0C;
    Member28_006e26a0 m_34;
    Member20_006e26a0 m_5C;
    Member18_006e26a0 m_7C;
    Member4_006e26a0 m_94;

    FUN_006e26a0(Owner_006e26a0* owner);
    virtual void v00();
};

// Constructs the object with m_94 set to 0 and attaches it to the given owner.
// @fnv 0x006e26a0
FUN_006e26a0::FUN_006e26a0(Owner_006e26a0* owner) : m_94(0)
{
    reinterpret_cast<::PathingRequest *>((owner))->CopyTo((::PathingRequest *)(::FUN_006e26a0 *)(this));
}

struct PathingLocationTextView
{
};
struct PathingDebugOutput
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void __cdecl Print(unsigned int, unsigned int, const char*, ...);
};
struct PathingRequestDebugView : PathingRequest
{
    void PrintDebugInfo(PathingDebugOutput* output);
};
// Formats the request's origin, destination and pathing parameters into text and prints each line through the debug output.
// @fnv 0x006e2be0
void PathingRequestDebugView::PrintDebugInfo(PathingDebugOutput* output)
{
    char text[256];
    reinterpret_cast<::DebugLocation *>((((PathingLocationTextView*)&Origin)))->FormatDebugString(text, 256);
    output->Print(0, 1, "Origin: %s", text);
    reinterpret_cast<::DebugLocation *>((((PathingLocationTextView*)&Destination)))->FormatDebugString(text, 256);
    output->Print(0, 1, "Destination: %s", text);
    output->Print(0, 1, "Actor Radius: %f", m_fFirstValueAfterActorData);
    output->Print(0, 1, "Goal Z Delta: %f", PathingActorSpatialData);
    output->Print(0, 1, "Target Radius: %f", fWeaponSpread);
    output->Print(0, 1, "Allow Incomplete Path: %s", bAllowIncompletePath ? "true" : "false");
    if (m_fCenterRadius != 0.0)
        output->Print(0, 1, "Center Radius: (%.2f,%.2f,%.2f) %f", Center.x, Center.y, Center.z, m_fCenterRadius);
    output->Print(0, 1, "Face Target at Goal: %s", bFaceTargetAtGoal ? "true" : "false");
    if (bFaceTargetAtGoal)
        output->Print(0, 1, "Goal Angle: %f", m_fPathingRadius);
    if (m_bCanJump)
        output->Print(0, 1, "Initial Path Heading: %f", m_fAvoidanceRadius);
    output->Print(0, 1, "Allow Direct Path If Pathing Fails: %s", m_bCanClimb ? "true" : "false");
    output->Print(0, 1, "Using Curved path: %s", m_bCanUseDoors ? "true" : "false");
    output->Print(0, 1, "Ignoring Locks: %s", bIgnoreLocks ? "true" : "false");
    output->Print(0, 1, "Pathsmoothing retry count: %i", m_iRequestType);
}

// sub ecx,0x10; jmp FUN_006e3880  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_006e3f20();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_006e3f20();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x006e3f20
    virtual void FUN_006e3f20();
};

Derived::Derived()
{}

#include "generated/data/fallout_shared/pathfinding/pathingrequest.inc"
