
// src/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <xmmintrin.h>
#include "generated/data/vtables.h"
#include <windows.h>
#include <new>
#include "fnv/decl/Cls_dafcd0.h"
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/decl/FUN_00dabeb0_cls.h"
#include "fnv/decl/FUN_00dabed0_cls.h"
#include "havok/hkpGskfAgent.h"
#include "havok/hkpShapeCollectionAgent.h"
#include "fnv/decl/hkObjDACB.h"
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/decl/hkpGskBaseAgent_S.h"
#include "fnv/symbols_00d33000.h"
#include "fnv/symbols_00d34000.h"
#include "fnv/symbols_00d43000.h"
#include "fnv/symbols_00d97000.h"
#include "fnv/symbols_00da3000.h"
#include "fnv/symbols_00da4000.h"
#include "fnv/symbols_00dac000.h"
#include "fnv/symbols_00dad000.h"
#include "fnv/symbols_00daf000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_01076000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010ce000.h"
#include "fnv/symbols_01268000.h"
struct ConvexListAgentInput
{
    void* m_unk00;
    void* m_unk04;
    char** m_unk08;  // +0x8
};

// hkArray<hkpAgent1nSector*>, the agent track (AgentSectorPointerArray, BlockPoolArray and Hdr in the callees' declarations).
struct ConvexListAgentTrack
{
    void** m_sectors;
    int m_size;
    int m_capacityAndFlags;
};

struct hkpCdBodyD33D;

// The deprecated convex list agent (hkpConvexListAgent, 0x90 bytes on 32-bit), a predictive gskf agent whose manifold
// holds the agent track while it is in stream mode. Offsets are the 32-bit release's.
struct hkpConvexListAgent : ::hkpGskfAgent
{
    struct StreamData
    {
        ConvexListAgentTrack m_agentTrack;  // +0x30
        float m_timeStamp;                  // +0x3c
    };

    ::S_00da40e0_Dispatcher* m_dispatcher;  // +0x80
    bool m_inStreamModus;                   // +0x84
    bool m_processFunctionCalled;           // +0x85
    unsigned short m_unk86;                 // +0x86

    StreamData& stream()
    {
        return *reinterpret_cast<StreamData*>(&m_manifold);
    }

    void FUN_00d33770(const void* a);
    void FUN_00d337f0(int a);
    void FUN_00d33810(int a);
    void FUN_00d33830(int a);
    void FUN_00d33740(ConvexListAgentInput* a, int b);
    void FUN_00d33850(::S_00da40e0_ConstraintOwner* a);
    void FUN_00d33ef0(void* arg);
    hkpConvexListAgent* FUN_00d33940(const hkpCdBodyD33D* a, const hkpCdBodyD33D* b, const struct hkpCollisionInputD33D* c, void* d);
};

// @fnv 0x00d33770
void hkpConvexListAgent::FUN_00d33770(const void* a)
{
    if (m_inStreamModus)
        reinterpret_cast<::FUN_00dabeb0_cls *>(this)->Reset(a != nullptr);
    else
        ::FUN_00da3510(reinterpret_cast<::AgentSectorPointerArray &>(stream().m_agentTrack), *const_cast<::CollisionAgentContext *>(static_cast<const ::CollisionAgentContext *>(a)));
}

extern "C" void __cdecl FUN_00d339d0(const void*, const void*, const void*, void*);

struct FUN_00d33b70_cls
{
    void FUN_00d33b70(const void* a, const void* b, const void* c, void* d);
};

// @fnv 0x00d33b70
void FUN_00d33b70_cls::FUN_00d33b70(const void* aiArg1, const void* aiArg2, const void* aiArg3, void* aiArg4)
{
    FUN_00d339d0(aiArg1, aiArg2, aiArg3, aiArg4);
}

extern "C"
{
    void __cdecl FUN_00d33b90(void* a, void* b, void* c, void* d);
}

struct FUN_00d33c80_class
{
    void FUN_00d33c80(void* a, void* b, void* c, void* d);
};

// @fnv 0x00d33c80
void FUN_00d33c80_class::FUN_00d33c80(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00d33b90(apArg1, apArg2, apArg3, apArg4);
}

struct hkpCollisionDispatcher
{
    struct CollisionAgentFunctionTable
    {
        void* pfnA;
        void* pfnB;
        void* pfnC;
        void* pfnD;
        char b1;
        char b2;
    };
};
// Fills a collision-function table three times and registers it with the dispatcher for the 0x16/0x12, 0x12/0x16 and 0x16/0x16 type pairs.
// @fnv 0x00d346b0
void __cdecl RegisterConvexListAgentCollisionFuncs(hkpConvexListAgent* self)
{
    hkpCollisionDispatcher::CollisionAgentFunctionTable funcTable;
    funcTable.pfnA = (void*)((void *(&)())::CreateConvexListAgent);
    funcTable.pfnB = (void*)((void *(&)())::InitSpawnedBuffer);
    funcTable.pfnC = (void*)((void *(&)())::FUN_00d34970);
    funcTable.pfnD = (void*)((void *(&)())::fnv_00d349b0::FUN_00d349b0);
    funcTable.b1 = 1;
    funcTable.b2 = 1;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((((hkpCollisionDispatcher*)self)))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::hkpCollisionDispatcher::CollisionAgentFunctionTable *)(&funcTable), 0x16, 0x12);
    funcTable.pfnA = (void*)((void *(&)())::fnv_00d343f0::FUN_00d343f0);
    funcTable.pfnB = (void*)((void *(&)())::FUN_00d33b90);
    funcTable.pfnC = (void*)((void *(&)())::FUN_00d339d0);
    funcTable.pfnD = (void*)((void *(&)())::fnv_00d33ca0::FUN_00d33ca0);
    funcTable.b1 = 0;
    funcTable.b2 = 1;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((((hkpCollisionDispatcher*)self)))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::hkpCollisionDispatcher::CollisionAgentFunctionTable *)(&funcTable), 0x12, 0x16);
    funcTable.pfnA = (void*)((void *(&)())::fnv_00d34510::FUN_00d34510);
    funcTable.pfnB = (void*)((void *(&)())::FUN_00d33b90);
    funcTable.pfnC = (void*)((void *(&)())::FUN_00d339d0);
    funcTable.pfnD = (void*)((void *(&)())::fnv_00d33ca0::FUN_00d33ca0);
    funcTable.b1 = 0;
    funcTable.b2 = 1;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((((hkpCollisionDispatcher*)self)))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::hkpCollisionDispatcher::CollisionAgentFunctionTable *)(&funcTable), 0x16, 0x16);
}

// @fnv 0x00d337f0
void hkpConvexListAgent::FUN_00d337f0(int a)
{
    if (m_inStreamModus)
        FUN_00dacb20(a);
}

// @fnv 0x00d33810
void hkpConvexListAgent::FUN_00d33810(int a)
{
    if (m_inStreamModus)
        AddPotential(a);
}

// @fnv 0x00d33830
void hkpConvexListAgent::FUN_00d33830(int aiArg)
{
    if (m_inStreamModus)
        reinterpret_cast<::hkObjDACB *>(this)->ClearSlotById(aiArg);
}


// If the agent is not in stream mode, calls FUN_00d97250 with its agent track, the input's +0x8 field and the input.
// @fnv 0x00d33740
void hkpConvexListAgent::FUN_00d33740(ConvexListAgentInput* a, int iUnused)
{
    if (!m_inStreamModus)
    {
        ::FUN_00d97250(reinterpret_cast<::Hdr *>(&stream().m_agentTrack), a->m_unk08, reinterpret_cast<::Logger *>(a));
    }
}

// Hands the agent track to FUN_00da42b0 with the dispatcher, contact manager and constraint owner, then clears it and switches to stream mode.
// @fnv 0x00d33850
void hkpConvexListAgent::FUN_00d33850(::S_00da40e0_ConstraintOwner* a)
{
    ::FUN_00da42b0(reinterpret_cast<::BlockPoolArray *>(&stream().m_agentTrack), m_dispatcher, static_cast<::S_00da40e0_ContactMgr*>(m_contactMgr), *a);
    stream().m_agentTrack.m_sectors = nullptr;
    m_inStreamModus = true;
}

// Forwards all five arguments to FUN_00d33ca0 and returns its result.
// @fnv 0x00d33da0
void* FUN_00d33da0(void* a, void* b, void* c, void* d, void* e)
{
    return ((void*(__cdecl*)(void*, void*, void*, void*, void*))((void *(&)())::fnv_00d33ca0::FUN_00d33ca0))(a, b, c, d, e);
}

struct hkpSimpleClosestContactCollector
{
    const void* m_vtable;          // +0x0
    float m_earlyOutDistance;      // +0x4
    bool m_hasHit;                 // +0x8
    __m128 m_position;             // +0x10
    __m128 m_separatingNormal;     // +0x20, w is the distance
    void Reset();
};

// @fnv 0x00d34770
void hkpSimpleClosestContactCollector::Reset()
{
    float max = 3.402820018375656e+38f;
    m_hasHit = 0;
    reinterpret_cast<float*>(&m_separatingNormal)[3] = max;
    m_earlyOutDistance = max;
}

struct D338e0Agent
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};

inline void D338e0Agent::vf00()
{}
inline void D338e0Agent::vf04()
{}
inline void D338e0Agent::vf08()
{}
inline void D338e0Agent::vf0C()
{}
inline int D338e0Agent::vf10()
{
    return 0;
}

struct D338e0Local
{
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
};

struct D338e0Owner
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
    unsigned char unk84;

    void FUN_00d338e0(int param1, int param2, int param3, int param4);
};


inline void D338e0Dispatch(D338e0Local* local, int* ownerField, int result)
{
    local->field0C = result;
    ::FUN_00da48e0((ownerField), (local));
}

// If unk84 is zero, fills a D338e0Local from the parameters and unk08, calls vf10 on the agent at param2, and dispatches the result with unk30.
// @fnv 0x00d338e0
void D338e0Owner::FUN_00d338e0(int aiArg1, int apAgentPtr, int aiArg3, int aiArg4)
{
    if (unk84 == 0)
    {
        D338e0Local local;
        local.field00 = aiArg1;
        local.field04 = apAgentPtr;
        local.field10 = aiArg3;
        local.field14 = unk08;
        local.field18 = aiArg4;

        D338e0Agent** ppAgent = reinterpret_cast<D338e0Agent**>(apAgentPtr);
        int result = (*ppAgent)->vf10();

        D338e0Dispatch(&local, &unk30, result);
    }
}



struct Node;
struct hkTransformCB22;
struct hkpCdBodyD33D
{
    ::Node* m_shape;                      // +0x0
    unsigned int m_shapeKey;              // +0x4
    const ::hkTransformCB22* m_motion;    // +0x8
};
struct hkpContactMgrD33D;
struct hkpCollisionInputD33D;

class hkpConvexListFilterD33D
{
  public:
    virtual ~hkpConvexListFilterD33D() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int ShouldBodiesCollide(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                    const hkpCollisionInputD33D& kInput) const throw();
};

struct hkpCollisionInputD33D
{
    ::S_00da40e0_Dispatcher* m_dispatcher;  // +0x0
    int m_unk04;
    int m_unk08;
    const void* m_filter;                   // +0xc
    hkpConvexListFilterD33D* m_pConvexListCollisionFilter;
};

// Allocate the agents FUN_00d34510, FUN_00d343f0 and CreateConvexListAgent build. Each records its size in the
// agent's memory size field, as hkpCollisionAgent's operator new does.
static hkpConvexListAgent* newConvexListAgent(const void* bodyA, const void* bodyB, const void* input, void* mgr)
{
    hkpConvexListAgent* agent =
        static_cast<hkpConvexListAgent*>(hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(hkpConvexListAgent)));
    agent->m_memSizeAndFlags = sizeof(hkpConvexListAgent);
    return agent->FUN_00d33940(static_cast<const hkpCdBodyD33D*>(bodyA), static_cast<const hkpCdBodyD33D*>(bodyB),
                               static_cast<const hkpCollisionInputD33D*>(input), mgr);
}

static ::FUN_00d440f0* newShapeCollectionAgent(const void* bodyA, const void* bodyB, const void* input, void* mgr)
{
    void* mem = hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(::FUN_00d440f0));
    ::FUN_00d440f0* agent = new (mem) ::FUN_00d440f0(*static_cast<const ::CdBodyS*>(bodyA), *static_cast<const ::CdBodyS*>(bodyB),
                                                     *static_cast<const ::CollisionInputS*>(input), static_cast<::ContactMgrS*>(mgr));
    agent->m_usMemSizeAndFlags = sizeof(::FUN_00d440f0);
    return agent;
}

static ::GskNode* asGskNode(const void* body);

static ::hkpGskfAgent* newGskfAgent(const void* bodyA, const void* bodyB, void* mgr)
{
    void* mem = hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(::hkpGskfAgent));
    ::hkpGskfAgent* agent = new (mem) ::hkpGskfAgent(asGskNode(bodyA), asGskNode(bodyB), mgr);
    agent->m_memSizeAndFlags = sizeof(::hkpGskfAgent);
    return agent;
}

// Creates a collision agent for the two bodies: picks the agent class from the convex list filter's result, or a default agent when pkMgr is null.
// @fnv 0x00d33dd0
void* __cdecl CreateConvexListAgent(const hkpCdBodyD33D& kBodyA, const hkpCdBodyD33D& kBodyB,
                                    const hkpCollisionInputD33D& kInput, hkpContactMgrD33D* pkMgr) throw()
{
    if (pkMgr)
    {
        switch (kInput.m_pConvexListCollisionFilter->ShouldBodiesCollide(kBodyA, kBodyB, kInput))
        {
        case 0: {
            hkpConvexListAgent* agent = newConvexListAgent(&kBodyB, &kBodyA, &kInput, pkMgr);
            agent->m_vtable = fnv_vftable_hkpSymmetricConvexListAgentD33D;
            return agent;
        }
        case 1:
            return newShapeCollectionAgent(&kBodyA, &kBodyB, &kInput, pkMgr);
        case 2: {
            ::hkpGskfAgent* agent = newGskfAgent(&kBodyA, &kBodyB, pkMgr);
            agent->m_vtable = fnv_vftable_hkpPredGskfAgentD33D;
            return agent;
        }
        }
        return 0;
    }
    return newShapeCollectionAgent(&kBodyA, &kBodyB, &kInput, 0);
}


// Releases the manifold's contact points, clears the mode flag and the stream time stamp, starts an empty agent track and
// sets m_unk86 to 0x19.
// @fnv 0x00d33ef0
void hkpConvexListAgent::FUN_00d33ef0(void* arg)
{
    ::ReleaseAllEntries((::S_00dad640_Set *)(void *)(&m_manifold), (::S_00dad640_Target *)(m_contactMgr), arg);
    m_inStreamModus = false;
    StreamData& data = stream();
    data.m_agentTrack.m_sectors = nullptr;
    data.m_agentTrack.m_size = 0;
    data.m_agentTrack.m_capacityAndFlags = 0x80000000;
    ::InitBlockPool((::BlockPoolArray *)(void *)(&data.m_agentTrack));
    data.m_timeStamp = 0.0f;
    m_unk86 = 0x19;
}

namespace fnv_00d343f0 {


struct hkpCdBodyD343;
struct hkpContactMgrD343;
struct hkpCollisionInputD343;

class hkpConvexListFilterD343
{
  public:
    virtual ~hkpConvexListFilterD343() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int ShouldBodiesCollide(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB,
                                    const hkpCollisionInputD343& kInput) const throw();
};

struct hkpCollisionInputD343
{
    ::S_00da40e0_Dispatcher* m_dispatcher;  // +0x0
    int m_unk04;
    int m_unk08;
    const void* m_filter;                   // +0xc
    hkpConvexListFilterD343* m_pConvexListCollisionFilter;
};

// @fnv 0x00d343f0
void* __cdecl FUN_00d343f0(const hkpCdBodyD343& kBodyA, const hkpCdBodyD343& kBodyB,
                           const hkpCollisionInputD343& kInput, hkpContactMgrD343* pkMgr) throw()
{
    if (pkMgr)
    {
        switch (kInput.m_pConvexListCollisionFilter->ShouldBodiesCollide(kBodyB, kBodyA, kInput))
        {
        case 0:
            return newConvexListAgent(&kBodyA, &kBodyB, &kInput, pkMgr);
        case 1: {
            ::FUN_00d440f0* agent = newShapeCollectionAgent(&kBodyB, &kBodyA, &kInput, pkMgr);
            *(void* volatile*)agent = (void*)fnv_vftable_fnv_00d442c0_D442C0ShapeAgent;
            return agent;
        }
        case 2: {
            ::hkpGskfAgent* agent = newGskfAgent(&kBodyA, &kBodyB, pkMgr);
            agent->m_vtable = fnv_vftable_hkpPredGskfAgentD33D;
            return agent;
        }
        }
        return 0;
    }
    ::FUN_00d440f0* agent = newShapeCollectionAgent(&kBodyB, &kBodyA, &kInput, 0);
    *(void* volatile*)agent = (void*)fnv_vftable_fnv_00d442c0_D442C0ShapeAgent;
    return agent;
}
}  // namespace fnv_00d343f0

class hkCollectorBaseD347
{
  public:
    hkCollectorBaseD347() : m_bHasHit(false)
    {}
    virtual void AddHit(void* hit) = 0;

    bool m_bHasHit;
};

class hkCollectorD347 : public hkCollectorBaseD347
{
  public:
    hkCollectorD347(void* filter) : m_iFilter(filter)
    {}
    virtual void AddHit(void* hit);

    void* m_iFilter;
};


// Constructs an hkCollectorD347 with the given filter and passes it to FUN_00d43dc0 along with a, b and c.
// @fnv 0x00d34790
void __cdecl FUN_00d34790(void* b, void* a, void* c, void* filter)
{
    hkCollectorD347 collector(filter);
    ::FUN_00d43dc0((*(const ::S_00d43dc0_CdBody *)(a)), (*(const ::S_00d43dc0_CdBody *)(b)), (*(const ::S_00d43dc0_CollisionInput *)(c)), (::S_00d43dc0_CdBodyPairCollector &)(collector));
}

// @fnv 0x00d36930
extern "C" void __cdecl FUN_00d36930()
{
    ::fnv_00d34810::FUN_00d34810({}, {}, {}, {}, {});
}

struct hkMemberD337
{
    int unk00;
};


class hkObjD337
{
  public:
    int unk00[12];
    hkMemberD337 m_30;
    int unk34[20];
    bool m_84;

    void SetValue(float a, float b, const void* c);
};

// Sets a value on the object, calling SetValueIfExpected when m_84 is true, otherwise delegating to FUN_00da35f0 on m_30.
// @fnv 0x00d337a0
void hkObjD337::SetValue(float a, float b, const void* c)
{
    if (m_84)
        reinterpret_cast<::FUN_00dabed0_cls *>(this)->SetValueIfExpected(a, b, c);
    else
        ::FUN_00da35f0((::Da35Stream ***)(::hkMemberD337 *)(&m_30), a, b, (void **)const_cast<void *>(c));
}

// @fnv 0x00d33890
struct ContactAgent
{
    virtual void Invalidate(int);
    int unk04;
    void* collidable08;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int contact30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    ::S_00da40e0_Dispatcher* state80;
    unsigned char flag84;
    void FUN_00d33890(void*);
};
void ContactAgent::FUN_00d33890(void* input)
{
    if (flag84)
    {
        ::ReleaseAllEntries((::S_00dad640_Set *)(void *)(&contact30), static_cast<::S_00dad640_Target *>(collidable08), input);
    }
    else
    {
        ::FUN_00da42b0((::BlockPoolArray *)(void *)(&contact30), state80, static_cast<::S_00da40e0_ContactMgr *>(collidable08), *static_cast<::S_00da40e0_ConstraintOwner *>(input));
    }
    Invalidate(1);
}

extern char DAT_010cebf0[];

struct __declspec(align(16)) S00d33940_Out
{
    float x;
    float y;
    float z;
    float w;
    float x1;
    float y1;
    float z1;
    float w1;
    float x2;
    float y2;
    float z2;
    float w2;
    float x3;
    float y3;
    float z3;
    float w3;
public:
    void FUN_00cb22f0(int a, int b);
};

static ::GskNode* asGskNode(const void* body)
{
    return static_cast<::GskNode*>(const_cast<void*>(body));
}

// Builds the gskf agent part, sets the convex list vtable, the dispatcher and the mode flags, fills the gsk cache from
// the two shapes and sets the separating normal's time and distance to DAT_01012054.
// @fnv 0x00d33940
hkpConvexListAgent* hkpConvexListAgent::FUN_00d33940(const hkpCdBodyD33D* a, const hkpCdBodyD33D* b,
                                                     const hkpCollisionInputD33D* c, void* d)
{
    ::new ((void *)this) ::hkpGskfAgent(asGskNode(a), asGskNode(b), d);
    m_vtable = DAT_010cebf0;
    m_dispatcher = c->m_dispatcher;
    m_inStreamModus = true;
    m_processFunctionCalled = false;

    S00d33940_Out o;
    reinterpret_cast<::hkTransformCB22 *>(&(o))->FUN_00cb22f0(*a->m_motion, *b->m_motion);
    reinterpret_cast<::Cls_dafcd0 *>(&(m_cache))->FUN_00dafcd0(a->m_shape, b->m_shape, (const ::Vec4Blk *)(::S00d33940_Out *)(&o));
    m_separatingNormal[3] = ::DAT_01012054;
    m_timeOfSeparatingNormal = m_separatingNormal[3];
    return this;
}

#include <windows.h>
extern DWORD DAT_0126835c;
extern char DAT_010cebd0;

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
    const char* m_pName2;
};

struct ProfBuf
{
    DWORD unk00;
    char* m_pCur;
    DWORD unk08;
    char* m_pRecordEnd;
};

struct HitCollector
{
    void* m_vtbl;
    bool m_bHit;
};


// Writes timer entries (LtCvxList/StcheckHull, Stchildren, lt), calls TestGsk with a collector, and calls FUN_00d34790 if the collector registered a hit.
// @fnv 0x00d33b90
extern "C" void __cdecl FUN_00d33b90(void* a, void* b, void* c, void* d)
{
    volatile DWORD tick;
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = (ProfRec*)pBuf->m_pCur;
        pRec->m_pName = "LtCvxList";
        pRec->m_pName2 = "StcheckHull";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = (char*)(pRec + 1);
    }

    HitCollector col;
    col.m_vtbl = &DAT_010cebd0;
    col.m_bHit = false;
    ::TestGsk((*(const ::S_00dac2b0_Body *)(a)), (*(const ::S_00dac2b0_Body *)(b)), c, (*(::S_00dac2b0_Collector *)(&col)));
    if (col.m_bHit)
    {
        pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            ProfRec* pRec = (ProfRec*)pBuf->m_pCur;
            pRec->m_pName = "Stchildren";
            _ReadWriteBarrier();
            tick = (DWORD)__rdtsc();
            pRec->m_iTick = tick;
            pBuf->m_pCur = (char*)&pRec->m_pName2;
        }
        ::FUN_00d34790(a, b, c, d);
    }

    pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = (ProfRec*)pBuf->m_pCur;
        pRec->m_pName = "lt";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = (char*)&pRec->m_pName2;
    }
}


extern unsigned long DAT_0126835c;
extern const char str_010cec28[];



struct StringCursor
{
    int unk00;
    char* m_commandPointer;
    int unk08;
    char* m_endCommandPointer;
};


struct hkVector4
{
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& other)
    {
        m_vComponents = other.m_vComponents;
        return *this;
    }
};

class hkContactPoint
{
  public:
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    float getDistance() const
    {
        return m_vSeparatingNormal.m_vComponents[3];
    }
    hkContactPoint& operator=(const hkContactPoint& other)
    {
        m_vContactPosition = other.m_vContactPosition;
        m_vSeparatingNormal = other.m_vSeparatingNormal;
        return *this;
    }
};

struct RootContactPoint
{
    hkContactPoint m_kPoint;
    const void* m_pRootCollidableA;
    unsigned int m_uiShapeKeyA;
    const void* m_pRootCollidableB;
    unsigned int m_uiShapeKeyB;
};

struct hkpFlagCdBodyPairCollector
{
    const void* vtbl;
    bool m_flag;
    hkpFlagCdBodyPairCollector() : vtbl(&DAT_010cebd0), m_flag(false)
    {}
    bool DidHit() const
    {
        return m_flag;
    }
};

struct hkpClosestCdPointCollector
{
    const void* vtbl;
    float m_fEarlyOutDistance;
    int unk08;
    int unk0C;
    RootContactPoint m_kHitPoint;
    RootContactPoint m_unweldedHitPoint;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    hkpClosestCdPointCollector()
    {
        m_kHitPoint.m_kPoint.m_vSeparatingNormal.m_vComponents[3] = ::DAT_0104da48;
        m_fEarlyOutDistance = ::DAT_0104da48;
        vtbl = &DAT_010c476c;
        m_kHitPoint.m_pRootCollidableA = 0;
    }

    bool DidHit() const
    {
        return m_kHitPoint.m_pRootCollidableA != 0;
    }
};

class hkpCdBody
{
  public:
    const void* m_pCollisionShape;
};

struct hkpConvexListShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float m_minDistanceToUseConvexHull;
};

struct ContactPointPair
{
    hkContactPoint m_kPoint;
    const void* m_pBodyA;
    const void* m_pBodyB;
};

struct hkpCdPointCollector
{
    virtual void unk00() = 0;
    virtual void AddCdPoint(const ContactPointPair& point) = 0;
};

// If TestGsk reports a hit calls QueryClosestPoints; else adds the closest point to a4 when its distance exceeds b's shape threshold, otherwise calls QueryClosestPoints.
// @fnv 0x00d339d0
extern "C" void __cdecl FUN_00d339d0(const void* apBodyA, const void* apBodyB, const void* a3, void* apCollector)
{
    {
        StringCursor* pForm = (StringCursor*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_commandPointer;
        if (p < pForm->m_endCommandPointer)
        {
            *(const char**)p = "LtCvxList";
            *(const char**)(p + 12) = "StcheckHull";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = t;
            pForm->m_commandPointer = p + 16;
        }
    }

    hkpFlagCdBodyPairCollector flagCollector;
    ::TestGsk(*static_cast<const ::S_00dac2b0_Body *>(apBodyA), *static_cast<const ::S_00dac2b0_Body *>(apBodyB), a3, (*(::S_00dac2b0_Collector *)(&flagCollector)));
    if (flagCollector.DidHit())
    {
        StringCursor* pForm = (StringCursor*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_commandPointer;
        if (p < pForm->m_endCommandPointer)
        {
            *(const char**)p = "Stchildren";
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            // Keep this timer read separate from the child-path timer read.
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = t;
            pForm->m_commandPointer = p + 12;
        }
        ::QueryClosestPoints(const_cast<void *>(apBodyA), const_cast<void *>(apBodyB), const_cast<void *>(a3), apCollector);
    }
    else
    {
        hkpClosestCdPointCollector x;
        ::hkpGskBaseAgent_S::FUN_00dac450(*static_cast<const ::hkpCdBody_S *>(apBodyA), *static_cast<const ::hkpCdBody_S *>(apBodyB), *static_cast<const ::hkpCollisionInput_S *>(a3), (*(::hkpCdPointCollector_S *)(&x)));
        if (!x.DidHit())
        {
            goto timer_end;
        }
        const hkpConvexListShape* shapeB = (const hkpConvexListShape*)static_cast<const hkpCdBody*>(apBodyB)->m_pCollisionShape;
        if (x.m_kHitPoint.m_kPoint.getDistance() > shapeB->m_minDistanceToUseConvexHull)
        {
            ContactPointPair point;
            point.m_pBodyA = apBodyA;
            point.m_pBodyB = apBodyB;
            point.m_kPoint = x.m_kHitPoint.m_kPoint;
            static_cast<hkpCdPointCollector*>(apCollector)->AddCdPoint(point);
            goto timer_end;
        }
        StringCursor* pForm = (StringCursor*)TlsGetValue(DAT_0126835c);
        char* p = pForm->m_commandPointer;
        if (p < pForm->m_endCommandPointer)
        {
            *(const char**)p = str_010cec28;
            _ReadWriteBarrier();
            volatile unsigned int t = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = t;
            pForm->m_commandPointer = p + 12;
        }
        ::QueryClosestPoints(const_cast<void *>(apBodyA), const_cast<void *>(apBodyB), const_cast<void *>(a3), apCollector);
    }

timer_end: {
    StringCursor* pForm = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* p = pForm->m_commandPointer;
    if (p < pForm->m_endCommandPointer)
    {
        *(const char**)p = str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(p + 4) = t;
        pForm->m_commandPointer = p + 12;
    }
}
}

namespace fnv_00d33ca0 {
#include <intrin.h>


extern int DAT_0126835c;
extern char str_010cec54[];
extern char str_010cec34[];

// A monitor-stream timer record; records without a detail name end at `detail`.
struct S00d33ca0_Timer
{
    const char* volatile name;
    unsigned int time;
    int unk08;
    const char* volatile detail;
};

struct S00d33ca0_Buf
{
    int unk00;
    S00d33ca0_Timer* cur;
    int unk08;
    S00d33ca0_Timer* limit;
};

static S00d33ca0_Timer* S00d33ca0_After(S00d33ca0_Timer* p, size_t bytes)
{
    return reinterpret_cast<S00d33ca0_Timer*>(reinterpret_cast<char*>(p) + bytes);
}

struct __declspec(align(16)) S00d33ca0_Local
{
    void* unk00;
    float unk04;
    char unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    volatile float unk2c;
};

// Writes a timer entry, calls FUN_00daf8e0, and if local.unk08 is set writes another entry and calls FUN_00d34810; then writes a closing timer entry.
// @fnv 0x00d33ca0
extern "C" void __cdecl FUN_00d33ca0(const void* a, const void* b, const void* c, void* d, void* e)
{
    S00d33ca0_Buf* buf;
    S00d33ca0_Timer* p;
    volatile unsigned int ts;

    buf = (S00d33ca0_Buf*)TlsGetValue(DAT_0126835c);
    p = buf->cur;
    if (p < buf->limit)
    {
        p->name = &str_010cec54[0];
        p->detail = &str_010cec34[0];
        _ReadWriteBarrier();
        ts = __rdtsc();
        p->time = ts;
        buf->cur = p + 1;
    }

    {
        S00d33ca0_Local local;
        local.unk2c = ::DAT_0104da48;
        local.unk04 = ::DAT_0104da48;
        local.unk00 = &(*reinterpret_cast<int *>(&::DAT_010cebe0));
        local.unk08 = 0;
        ::FUN_00daf8e0(static_cast<const ::IterativeSweep_hkpCdBody *>(a), static_cast<const ::IterativeSweep_hkpCdBody *>(b), static_cast<const ::IterativeSweep_hkpLinearCastCollisionInput *>(c), (::IterativeSweep_hkpCdPointCollector *)(void *)(&local), (::IterativeSweep_hkpCdPointCollector *)(void *)(&local));
        if (local.unk08 != 0)
        {
            buf = (S00d33ca0_Buf*)TlsGetValue(DAT_0126835c);
            p = buf->cur;
            if (p < buf->limit)
            {
                p->name = &::DAT_010cec4c[0];
                _ReadWriteBarrier();
                ts = __rdtsc();
                p->time = ts;
                buf->cur = S00d33ca0_After(p, offsetof(S00d33ca0_Timer, detail));
            }
            ::fnv_00d34810::FUN_00d34810(a, b, static_cast<const ::fnv_00d34810::Input_d2e9 *>(c), d, e);
        }
    }

    buf = (S00d33ca0_Buf*)TlsGetValue(DAT_0126835c);
    p = buf->cur;
    if (p < buf->limit)
    {
        p->name = &::str_01076f38[0];
        _ReadWriteBarrier();
        ts = __rdtsc();
        p->time = ts;
        buf->cur = S00d33ca0_After(p, offsetof(S00d33ca0_Timer, detail));
    }
}
}  // namespace fnv_00d33ca0

namespace fnv_00d34510 {

struct AgentCollisionDispatcher
{
    virtual void* vfunc0();
    virtual void* vfunc1();
    virtual void* vfunc2();
    virtual int getCollisionType(void* bodyA, void* bodyB, void* input);
};

struct AgentCollisionInput
{
    ::S_00da40e0_Dispatcher* m_dispatcher;  // +0x0
    int unk04;
    int unk08;
    const void* m_filter;                   // +0xc
    AgentCollisionDispatcher* m_pCollisionDispatcher;
};

// Dispatches on collision type to allocate and initialize the appropriate agent object for the given body pair and contact manager.
// @fnv 0x00d34510
void* __cdecl FUN_00d34510(void* bodyA, void* bodyB, AgentCollisionInput* input, void* contactMgr)
{
    if (contactMgr)
    {
        switch (input->m_pCollisionDispatcher->getCollisionType(bodyA, bodyB, input))
        {
        case 0: {
            hkpConvexListAgent* agent = newConvexListAgent(bodyB, bodyA, input, contactMgr);
            agent->m_vtable = fnv_vftable_hkpSymmetricConvexListAgentD33D;
            return agent;
        }
        case 1:
            return newShapeCollectionAgent(bodyA, bodyB, input, contactMgr);
        case 2: {
            switch (input->m_pCollisionDispatcher->getCollisionType(bodyB, bodyA, input))
            {
            case 0:
                return newConvexListAgent(bodyA, bodyB, input, contactMgr);
            case 1: {
                ::FUN_00d440f0* agent = newShapeCollectionAgent(bodyB, bodyA, input, contactMgr);
                *(void* volatile*)agent = (void*)fnv_vftable_fnv_00d442c0_D442C0ShapeAgent;
                return agent;
            }
            case 2: {
                ::hkpGskfAgent* agent = newGskfAgent(bodyA, bodyB, contactMgr);
                agent->m_vtable = fnv_vftable_hkpPredGskfAgentD33D;
                return agent;
            }
            }
            break;
        }
        }
        return 0;
    }
    else
    {
        return newShapeCollectionAgent(bodyA, bodyB, input, 0);
    }
}
}  // namespace fnv_00d34510

// Moved from hkpconvexlistagent_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/Container.h"
#include "fnv/decl/FUN_00d33670.h"
#include "fnv/decl/hkpPredGskfAgent.h"

struct ProfileIndex
{
    unsigned long value;
    __forceinline ProfileIndex(unsigned long v) : value(v)
    {}
};
static __forceinline void* profileBuffer(const ProfileIndex& index)
{
    return TlsGetValue(index.value);
}
static __forceinline __m128 Splat(const float& f)
{
    __m128 r = _mm_load_ss(&f);
    return _mm_shuffle_ps(r, r, 0);
}
static __forceinline float ParseFloatValue(__m128 v)
{
    float f;
    _mm_store_ss(&f, v);
    return f;
}

extern const char str_010ceb84[], str_010ceb7c[], str_010ceb70[], str_010ceca0[];

union Vec4
{
    __m128 quad;
    struct
    {
        float x, y, z, w;
    };
};
struct L16
{
    Vec4 v;
};
struct L64
{
    L16 a, b, c, d;
};
struct L256
{
    L64 a, b, c, d;
};
struct L1024
{
    L256 a, b, c, d;
};
struct L4096
{
    L1024 a, b, c, d;
};
struct L128
{
    L64 a, b;
};
struct Arg4;
struct Shape;  // Collision-output snapshot: 0x1080 bytes consumed by the snapshot/reset methods.
struct Workspace
{
    L4096 contacts;
    L128 state;
    void FUN_00d33670(Arg4&);
    void FUN_00d33600(const Shape&, const Shape&, Arg4&, void*);
};

struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    Vec4 m_40;
    Vec4 m_50;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    float m_9c;
    float m_a0;
};
struct ShapeHead
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int count;
};
struct Shape
{
    ShapeHead* m_00;
    int unkp04;
    Obj* m_08;
    Shape* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    float m_4c;
};
struct Arg3
{
    int unk00;
    int unk04;
    float m_08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    float m_58;
};
struct Arg4
{
    int unkp00;
    void* m_04;
};
struct CollObj
{
    Vec4 a, b, c, d;
    void FUN_00cb22f0(Obj*, Obj*);
};
struct SStruct
{
    void* pCo;
    void* pObjA;
    void* a0;
    void* b0;
    float f;
};
struct StackObj
{
    void* vptr;
    short unkp04;
    short m_06s;
    int kind;
    void* saved;
    char flag;
    char unkp19a;
    short unkp20;
};
struct Big
{
    const Shape* a;
    const Shape* b;
    int zero;
    const Arg3* c;
    void* agent08;
    int unkp14, unk18, unk1c;
    CollObj co;
    int p60, p64, p68, p6c;
    Vec4 vec;
};
struct D33ProfBuf
{
    int unkp00;
    char* cursor;
    int unkp08;
    char* end;
};
struct Rec16
{
    const char* name;
    unsigned int tick;
    void* unk;
    const char* name2;
};
struct Rec12
{
    const char* name;
    unsigned int tick;
    void* unk;
};

void FUN_00d33600(void* a, void* b, void* c, void* d);
void* FUN_00cb22f0(void* a, void* b);
int FUN_00dabca0(SStruct* a, void* b, void* c, void* d);
void FUN_00d33ef0(void* a);
void FUN_00d42020(void* a, void* b, void* c, void* d);
struct AddressValue
{
    void* value;
    __forceinline AddressValue(void* p) : value(p)
    {}
};

typedef void(* Ws70Fn)(void*, const void*);
typedef void(* Ws00Fn)(void*, const void*, const void*, const void*, void*);
typedef void*(* CbFn)(void*, void*, void*);
typedef void(* Ag1Fn)(void*, void*);
typedef void(* Ag4Fn)(void*, const void*, const void*, const void*, void*);

struct StreamState
{
    short flags;
    char count;
    char unknown;
    int field04, field08;
    float distance;
};
struct ScalarScratch;
struct Agent
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4 m_20w;
    short unkp30;
    char m_32;
    char unkp33;
    int unk34;
    int unk38;
    float m_3c;
    __forceinline StreamState& streaming()
    {
        return *reinterpret_cast<StreamState*>(&unkp30);
    }
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    char m_84;
    char m_85;
    short m_86;
    void FUN_00d33850(void*);
    void FUN_00d33ef0(void*);
    void FUN_00d42020(const Shape&, const Shape&, const Arg3&, Arg4&);
    __forceinline void processCached(const Shape&, const Shape&, const Arg3&, Arg4&, const Vec4&, Workspace&, StackObj&,
                                     ScalarScratch&, bool&);
    void streamCollision(const Shape&, const Shape&, const Arg3&, Arg4&, const Vec4&, ShapeHead*);
    void FUN_00d33f40(const Shape& a, const Shape& b, const Arg3& c, Arg4& d);
};

__forceinline void projectDistance(Vec4& normal, const Vec4& vec)
{
    __m128 p = _mm_mul_ps(normal.quad, vec.quad);
    __m128 v = vec.quad;
    __m128 s3 = _mm_shuffle_ps(v, v, 0xff);
    __m128 s2 = _mm_shuffle_ps(p, p, 0xaa);
    __m128 s1 = _mm_shuffle_ps(p, p, 0x55);
    __m128 rr = _mm_add_ps(_mm_add_ss(s2, s3), _mm_add_ss(s1, p));
    float dot;
    _mm_store_ss(&dot, rr);
    normal.w -= dot;
}
// Keep the two rounded scale values together for x87 and SIMD consumers.
struct MotionScales
{
    float a, b;
};
struct ScalarScratch
{
    union
    {
        float dt;
        D33ProfBuf* volatile monitor;
        float minimum;
    } first;
    union
    {
        float factor;
        volatile unsigned stamp;
    } a;
    float radius;
    union
    {
        float factor;
        volatile unsigned stamp;
    } b;
    union
    {
        ShapeHead* shape;
        volatile unsigned stamp;
    } last;
};
__forceinline void calculateMotion(const Obj& oa, const Obj& ob, ScalarScratch& scratch, Vec4& vec)
{
    scratch.a.factor = scratch.first.dt * oa.m_50.w;
    scratch.b.factor = scratch.first.dt * ob.m_50.w;
    __m128 scaleA = Splat(scratch.a.factor);
    __m128 scaleB = Splat(scratch.b.factor);
    __m128 vc = ob.m_40.quad;
    __m128 vd = ob.m_50.quad;
    __m128 va = oa.m_40.quad;
    __m128 vb = oa.m_50.quad;
    vec.quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(vd, vc), scaleB), _mm_mul_ps(_mm_sub_ps(va, vb), scaleA));
    vec.w = oa.m_9c * scratch.a.factor * oa.m_a0 + ob.m_9c * scratch.b.factor * ob.m_a0;
}

__forceinline void Agent::streamCollision(const Shape& a, const Shape& b, const Arg3& c, Arg4& d, const Vec4& vec,
                                          ShapeHead* bHead)
{
    Big big;
    big.zero = 0;
    big.a = &a;
    big.b = &b;
    big.agent08 = m_08;
    __m128 motion = vec.quad;
    big.c = &c;
    big.vec.quad = motion;
    reinterpret_cast<::hkTransformCB22 *>(&(big.co))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(a.m_08)), (*(const ::hkTransformCB22 *)(b.m_08)));
    int count = bHead->count;
    int* arr = static_cast<int*>(hkMemoryRouter::getInstance().allocateStack((static_cast<unsigned int>((count + 1) * sizeof(int)) + 0x7f) & ~0x7fu));
    for (int i = 0; i < count; i++)
        arr[i] = i;
    arr[count] = -1;
    ::fnv_00da4aa0::FUN_00da4aa0((*(::fnv_00da4aa0::Q30 *)(&streaming())), (*(const ::fnv_00da4aa0::Q14 *)(&big)), (*(const ::fnv_00da4aa0::Q24 * *)&(const ::AddressValue &)(AddressValue(&bHead->unk14))), (const unsigned int *)(arr), (*(::fnv_00da4aa0::Q6 *)(&d)));
    hkMemoryRouter::getInstance().deallocateStack(arr);
}
__forceinline void Agent::processCached(const Shape& a, const Shape& b, const Arg3& c, Arg4& d, const Vec4& vec,
                                        Workspace& ws, StackObj& so, ScalarScratch& scratch, bool& retry)
{
    if (m_20w.w > c.m_08)
    {
        projectDistance(m_20w, vec);
        if (m_20w.w > c.m_08)
        {
            if (m_32 != 0)
                ::ReleaseAllEntries((::S_00dad640_Set *)(void *)(&unkp30), (::S_00dad640_Target *)(m_08), d.m_04);
            return;
        }
    }
    {
        D33ProfBuf* pBuf;
        pBuf = (D33ProfBuf*)TlsGetValue(DAT_0126835c);
        scratch.first.monitor = pBuf;
        Rec12* pRec = (Rec12*)pBuf->cursor;
        if (pRec < (Rec12*)pBuf->end)
        {
            pRec->name = str_010ceca0;
            _ReadWriteBarrier();
            scratch.a.stamp = (unsigned int)__rdtsc();
            pRec->tick = scratch.a.stamp;
            scratch.first.monitor->cursor = (char*)(pRec + 1);
        }
        so.kind = 2;
        so.m_06s = 1;
        so.vptr = &DAT_010ceb44;
        so.flag = 0;
        so.saved = m_08;
        m_08 = &so;
        reinterpret_cast<::hkpPredGskfAgent *>(this)->FUN_00d42020((const ::hkpCdBody &)(a), (const ::hkpCdBody &)(b), (const ::GskAgentInput &)(c), (::WorldOperationEntry &)(d));
        m_08 = so.saved;
        if (so.flag == 0)
        {
            if (m_32 == 0)
                return;
            if (m_85 != 0)
                return;
            const Shape* pa = &b;
            while (pa->m_0c)
                pa = pa->m_0c;
            scratch.radius = pa->m_4c;
            const Shape* pb = &a;
            while (pb->m_0c)
                pb = pb->m_0c;
            scratch.first.minimum = pb->m_4c;
            double cachedDistance;
            if (scratch.first.minimum < scratch.radius)
            {
                scratch.first.minimum = (const float&)(scratch.first.minimum * 1.0f);
                cachedDistance = m_20w.w;
            }
            else
            {
                scratch.first.minimum = scratch.radius;
                cachedDistance = m_20w.w;
            }
            scratch.radius = 2.0f * scratch.first.minimum;
            if (!(cachedDistance < -scratch.radius))
                return;
        }
        reinterpret_cast<::Container *>(&(ws))->FUN_00d33600((void *)&(a), (void *)&(b), (char *)&(d), (struct ::Callback *)(m_08));
        reinterpret_cast<::hkpConvexListAgent *>(this)->FUN_00d33ef0(d.m_04);
        retry = true;
        return;
    }
}
// @fnv 0x00d33f40
void Agent::FUN_00d33f40(const Shape& a, const Shape& b, const Arg3& c, Arg4& d)
{
    Workspace ws;
    Vec4 vec;

    ScalarScratch scratch;
    CollObj co;
    union
    {
        SStruct query;
        StackObj manager;
    } temp;

    {
        D33ProfBuf* pBuf;
        Rec16* pRec = (Rec16*)(pBuf = (D33ProfBuf*)TlsGetValue(DAT_0126835c))->cursor;
        if (pRec < (Rec16*)pBuf->end)
        {
            pRec->name = str_010ceb84;
            pRec->name2 = str_010ceb7c;
            _ReadWriteBarrier();
            scratch.a.stamp = (unsigned int)__rdtsc();
            pRec->tick = scratch.a.stamp;
            pBuf->cursor = (char*)(pRec + 1);
        }
    }
    scratch.last.shape = b.m_00;
    scratch.first.dt = c.m_58;
    calculateMotion(*a.m_08, *b.m_08, scratch, vec);
    ::new ((void *)&(ws)) ::FUN_00d33670((const ::LargeOutput &)(d));
    if (m_84 != 0)
        goto project;
stream: {
    D33ProfBuf* pBuf;
    pBuf = (D33ProfBuf*)TlsGetValue(DAT_0126835c);
    scratch.first.monitor = pBuf;
    Rec12* pRec = (Rec12*)pBuf->cursor;
    if (pRec < (Rec12*)pBuf->end)
    {
        pRec->name = str_010ceb70;
        _ReadWriteBarrier();
        scratch.b.stamp = (unsigned int)__rdtsc();
        pRec->tick = scratch.b.stamp;
        scratch.first.monitor->cursor = (char*)(pRec + 1);
    }
    short oc = m_86;
    m_86 = (short)(oc - 1);
    if (oc >= 0)
        goto sqrtpath;
    m_86 = 0x19;
    {
        reinterpret_cast<::hkTransformCB22 *>(&(co))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(a.m_08)), (*(const ::hkTransformCB22 *)(b.m_08)));
        SStruct& s = temp.query;
        Vec4 objD;
        s.a0 = a.m_00;
        s.b0 = b.m_00;
        s.pCo = &co;
        s.pObjA = a.m_08;
        s.f = c.m_08;
        int res = FUN_00dabca0(&s, &m_0c, &m_20w, &objD);
        if (res == 0)
        {
            streaming().distance = -m_20w.w;
            goto sqrtpath;
        }
        reinterpret_cast<::hkpConvexListAgent *>(this)->FUN_00d33850(static_cast<::S_00da40e0_ConstraintOwner *>(d.m_04));
        reinterpret_cast<::Container *>(&(ws))->FUN_00d33600((void *)&(a), (void *)&(b), (char *)&(d), (struct ::Callback *)(m_08));
    }
}
// Update cached separation before choosing GSK or cached-contact export.
project: {
    bool retry = false;
    processCached(a, b, c, d, vec, ws, temp.manager, scratch, retry);
    if (retry)
        goto stream;
    goto tail;
}
// Streaming path: reduce cached distance by motion length, then visit all shape keys.
sqrtpath: {
    __m128 vv = vec.quad;
    __m128 sq = _mm_mul_ps(vv, vv);
    __m128 sh1 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 s1 = _mm_add_ss(sh1, sq);
    __m128 sh2 = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 s2 = _mm_add_ss(sh2, s1);
    __m128 len = _mm_sqrt_ss(s2);
    _mm_store_ss(&scratch.radius, len);
    streaming().distance -= scratch.radius;
    streamCollision(a, b, c, d, vec, scratch.last.shape);
}
tail:
    m_85 = 1;
    {
        D33ProfBuf* pBuf;
        unsigned long index = DAT_0126835c;
        Rec12* pRec = (Rec12*)(pBuf = (D33ProfBuf*)profileBuffer(ProfileIndex(index)))->cursor;
        if (pRec < (Rec12*)pBuf->end)
        {
            pRec->name = str_01076f38;
            _ReadWriteBarrier();
            scratch.last.stamp = (unsigned int)__rdtsc();
            pRec->tick = scratch.last.stamp;
            pBuf->cursor = (char*)(pRec + 1);
        }
    }
}
#include "generated/data/havok/physics/collide/agent/deprecated/convexlist/hkpconvexlistagent.inc"
