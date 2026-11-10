
// src/fallout_shared/tempeffects/bstempeffectparticle.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tempeffects/bstempeffectparticle.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/game_timer.h"
#include <new>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_004472a0_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_0045aba0_cls.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004d7d50_StandIn.h"
#include "fnv/decl/FUN_004f0180_Class.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_006828a0_shell.h"
#include "fnv/decl/FUN_006828e0_shell.h"
#include "fnv/decl/FUN_00682920_shell.h"
#include "fnv/decl/FUN_00682990_shell.h"
#include "fnv/decl/FUN_0068aa50_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857bd0.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/NiQuaternion.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0087ac00__Owner0087ac00.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0055f000.h"
#include "fnv/symbols_00578000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
struct SndX
{
};

struct FUN_0068a850_shell
{
    SndX m_snd0;  // +0x5c
    SndX m_snd1;  // +0x68
    void StopSounds();
};

// @fnv 0x0068a850
void FUN_0068a850_shell::StopSounds()
{
    if (reinterpret_cast<::SoundPlaybackHandle *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x5c)))->IsValid())
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x5c)))->FUN_00ad88f0();
        if (reinterpret_cast<::SoundPlaybackHandle *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x5c)))->IsValid())
            reinterpret_cast<::SoundPlaybackHandle *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x5c)))->Release();
    }
    if (reinterpret_cast<::SoundPlaybackHandle *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x68)))->IsValid())
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x68)))->FUN_00ad88f0();
        if (reinterpret_cast<::SoundPlaybackHandle *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x68)))->IsValid())
            reinterpret_cast<::SoundPlaybackHandle *>((reinterpret_cast<SndX*>(reinterpret_cast<char*>(this) + 0x68)))->Release();
    }
}


// @fnv 0x00891350
int* __cdecl FUN_00891350()
{
    return (*reinterpret_cast<int * *>(&::DAT_011c61ec));
}

struct NiRTTI
{
    virtual ~NiRTTI();
};
struct GlobalObject_00a7b610 : public NiRTTI
{
};

struct FUN_00688f80_shell
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x00688f80
const NiRTTI* FUN_00688f80_shell::GetRTTI() const
{
    return &::g_011d6b84;
}


struct FUN_00688f90_shell
{
    void FUN_00689720();
    void* FUN_00688f90(unsigned int flags);
};

struct Flt
{
    operator std::uintptr_t() const;
};

struct BSTempEffectParticle
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;
    unsigned int m_usTrailingValue;
    unsigned int m_f;
    Flt m_flt;              // +0x18
    const char* pFilename;  // +0x1c
    bool FUN_00689af0();
};

// Returns true when pFilename is non-null and m_flt converts to a non-zero unsigned int, otherwise false.
// @fnv 0x00689af0
bool BSTempEffectParticle::FUN_00689af0()
{
    if (!(pFilename && (unsigned int)m_flt))
        return false;
    return true;
}

class NiAVObject;
class NiNode
{
  public:
    virtual ~NiNode();
    virtual void f1();
    virtual void f2();
    virtual NiNode* f3();
public:
    ::NiAVObject *GetAt(unsigned int);
};
struct DetachHost : BSTempEffectParticle
{
    void FUN_006896c0();
};
// Gets the node from m_flt via f3 and, if non-null, passes it to FUN_00578170.
// @fnv 0x006896c0
void DetachHost::FUN_006896c0()
{
    NiNode* pnode = m_flt ? ((NiNode*)(std::uintptr_t)m_flt)->f3() : 0;
    if (pnode)
        ::fnv_00578170::FUN_00578170(pnode);
}

extern "C" void __cdecl InitLoopSounds(void*);

struct FUN_0068a8d0_shell
{
    char pad[0x58];
    void* m_58;
    void FUN_0068a8d0(void* a);
};

// @fnv 0x0068a8d0
void FUN_0068a8d0_shell::FUN_0068a8d0(void* pValue)
{
    m_58 = pValue;
    ((void(*)(void*))InitLoopSounds)(this);
}

class NiFixedString
{
  public:
    const char* m_pString;
    NiFixedString(const char*);
    ~NiFixedString();
};

struct BSFadeNode : public NiFixedString
{
    BSFadeNode(const char*);
};

struct Model
{
};

class NiControllerSequence
{
};

struct NiControllerManager
{
    bool ActivateControllerSequence(NiControllerSequence*, int, bool, float, float, NiControllerSequence*);
};



struct FUN_00689920_shell
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    float m_iThirdValue;
    unsigned int m_iFourthElementInteger;
    unsigned int m_usTrailingValue;
    unsigned int m_f;
    Flt m_flt;

    void FUN_00689920(const char*);
};

// @fnv 0x00689920
void FUN_00689920_shell::FUN_00689920(const char* name)
{
    NiControllerManager* controllerManager =
        ((::NiControllerManager *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(::NiNode *)(((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)(reinterpret_cast<Model*>(m_flt.operator std::uintptr_t())))))))));

    if (controllerManager)
    {
        NiControllerSequence* controllerSequence = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((controllerManager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(BSFadeNode(name)))));

        if (controllerSequence)
        {
            controllerManager->ActivateControllerSequence(controllerSequence, 0, 0, 1.0f, 0.0f, 0);

            float duration = reinterpret_cast<::FUN_00508100_shell *>((controllerSequence))->FUN_00508100();
            if (duration > m_iThirdValue)
            {
                m_iThirdValue = duration;
            }
        }
    }
}

struct Tgt;
struct Yv
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
    virtual void v3a(Tgt*);
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
};
struct Tgt;
struct Sub18
{
    int m0;
    Tgt* m1;
    ~Sub18();
    void FUN_0066b0d0(int);
};
struct Sub5c
{
    char p[12];
    ~Sub5c();
};
struct Mgr
{
};
struct Fn
{
};
struct Base
{
    int b4, b8, bc, b10, b14;
    virtual ~Base();
};
struct FUN_00689720 : Base
{
    Sub18 a;
    Sub18 b;
    char pad[0x5c - 0x28];
    Sub5c c;
    Sub5c d;
    virtual ~FUN_00689720();
};
// Calls FUN_00689720, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00688f90
void* FUN_00688f90_shell::FUN_00688f90(unsigned int flags)
{
    reinterpret_cast<::FUN_00689720 *>((this))->FUN_00689720::~FUN_00689720();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x74);
    return this;
}
// @fnv 0x00689720
FUN_00689720::~FUN_00689720()
{
    reinterpret_cast<::FUN_0068a850_shell *>(this)->StopSounds();
    if (a.m1)
        reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::Mgr * *>(&::g_modelLoader))))->FUN_00445300((char *)(a.m1), 0, 1);
    if (((::Tgt *)(::FUN_00559450((int *)&(a)))))
    {
        if (((::Yv *)(reinterpret_cast<::FUN_009611e0_shell *>((((Fn*)((::Tgt *)(::FUN_00559450((int *)&(a)))))))->FUN_009611e0())))
        {
            ((::Yv *)(reinterpret_cast<::FUN_009611e0_shell *>((((Fn*)((::Tgt *)(::FUN_00559450((int *)&(a)))))))->FUN_009611e0()))->v3a(((::Tgt *)(::FUN_00559450((int *)&(a)))));
        }
    }
    a.FUN_0066b0d0(0);
}


struct TrailEntry
{
};

struct TraversalItem
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual TraversalItem* v3();
};

struct FUN_00689840_Class
{
    float ComputeTraversalValue(TraversalItem* entry);
};

// @fnv 0x00689840
float FUN_00689840_Class::ComputeTraversalValue(TraversalItem* entry)
{
    float accumulator = DAT_01012054;
    TrailEntry* pTrail = ((::TrailEntry *)(::fnv_0043b230::FUN_0043b230((const char *)(entry))));
    while (pTrail != 0)
    {
        accumulator = FUN_00404010(accumulator, static_cast<float>(((double)(reinterpret_cast<::BSMultiBoundSphere *>((pTrail))->GetRadius())) - ((double)(reinterpret_cast<::TESActorBaseData *>((pTrail))->GetHealthRegeneration()))));
        pTrail = ((::TrailEntry *)(::fnv_004a8a90::FUN_004a8a90((char *)(pTrail))));
    }

    TraversalItem* children = entry->v3();
    if (children != 0)
    {
        int iChildCount = reinterpret_cast<::FUN_00453470_shell *>((children))->FUN_00453470();
        for (int i = 0; i < iChildCount; ++i)
        {
            TraversalItem* child = ((::TraversalItem *)(reinterpret_cast<::NiNode *>((children))->GetAt(i)));
            if (child != 0)
                accumulator = FUN_00404010(accumulator, ComputeTraversalValue(child));
        }
    }
    return accumulator;
}

struct DataModel
{
};
struct DataHandle
{
};
struct GlobalState
{
};
struct LoggingFlag
{
    unsigned char* FUN_00408d60();
};
struct LoggingObject
{
    void** vtable;
};
struct ParticleEffect
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;
    unsigned int m_usTrailingValue;
    unsigned int m_f;
    DataHandle handle;
    char const* filename;
    unsigned short FUN_00689b20();
};
extern char DAT_01069d20[];
typedef void*(* LogMethod)(LoggingObject*);
// @fnv 0x00689b20
unsigned short ParticleEffect::FUN_00689b20()
{
    unsigned short previous = 0;
    unsigned short total = previous;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        previous += 4;
        previous += 2;
    }
    previous += reinterpret_cast<::FUN_006828e0_shell *>(this)->FUN_006828e0();
    previous += 1;
    previous += ((int)(::FUN_0044a670(filename)));
    previous += 0x10;
    previous += 0xc;
    previous += 4;
    previous += 2;
    void* active = ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac))), (::NiObject *)(void *)(((void *)(::fnv_0043b230::FUN_0043b230((const char *)(((::DataModel *)(::FUN_00559450((int *)&(handle))))))))))));
    if (active != 0)
    {
        previous += ::FUN_0055fdb0((::AnimationInterpolatorNode *)(active));
    }
    if (*(*reinterpret_cast<::LoggingFlag *>(&::g_011de4e8)).FUN_00408d60())
    {
        void* entry = ((void *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (entry)
        {
            LoggingObject* writer = ((::LoggingObject *)(::FUN_004839c0((unsigned int)(std::uintptr_t)(*(void**)entry))));
            ::FUN_0040fbe0(::DAT_01012cb0, previous - total, *(void**)entry, ((LogMethod*)writer->vtable)[76](writer),
                         *(void**)((char*)entry + 5), 0x174, DAT_01069d20);
        }
        else
        {
            ::FUN_0040fbe0(::DAT_01012c78, previous - total, 0x174, DAT_01069d20);
        }
    }
    return previous;
}

struct Vec3
{
    float x, y, z;
public:
    Vec3();
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_0043f8d0(Matrix&, const Matrix&);
};
struct NiPoint3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3();
};
struct Rotation
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Rotation();
    void FUN_0043f8d0(Matrix&, const NiPoint3&);
};
Rotation __cdecl FUN_00c4b8a0(Vec3);
struct World
{
};
struct Effect
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70;
    Effect(World*, float, int, int);
    void AttachModel(void*, Matrix, Vec3, float, int);
};
struct Manager
{
};
// @fnv 0x006890b0
Effect* __cdecl FUN_006890b0(World* world, float duration, std::intptr_t kind, Vec3 rotation, Vec3 position, float scale,
                             int flags, int extra)
{
    Effect* pEffect = 0;
    if (world)
    {
        pEffect = new Effect(world, duration, kind, extra);
        float node = ((float)(::FUN_004a4240()));
        NiPoint3 matrix2;
        reinterpret_cast<::FUN_004a0c90_shell *>(&(matrix2))->FUN_004a0c90(node);
        Matrix a;
        FUN_00c4b8a0(rotation).FUN_0043f8d0(a, matrix2);
        void* transform = ((void *)(reinterpret_cast<::TESObjectCELL *>((world))->GetCellChildAt(4)));
        pEffect->AttachModel(transform, a, position, scale, flags);
        reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::Manager *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(pEffect));
    }
    return pEffect;
}

struct Block9
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned int i;
};
struct Block3
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
struct FUN_00c335d0
{
};
struct FUN_00456fc0_cls
{
};
struct FUN_00688fc0 : FUN_00c335d0
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
    FUN_00688fc0(void* a, float b, unsigned int c, unsigned int d);
    void AttachModel(void* a, Block9 b, Block3 c, float d, unsigned int f);
};
struct GlobalObject_0096d020
{
};

// @fnv 0x00689210
void* __cdecl FUN_00689210(void* a, float fValue, unsigned int uiFlags, Block9 d, Block3 e, float fParam,
                           unsigned int uiParam, unsigned int uiExtra)
{
    FUN_00688fc0* pNewObject = 0;
    if (a != 0)
    {
        pNewObject = new FUN_00688fc0(a, fValue, uiFlags, uiExtra);
        void* pArgument = ((void *)(reinterpret_cast<::TESObjectCELL *>((((FUN_00456fc0_cls*)a)))->GetCellChildAt(4)));
        pNewObject->AttachModel(pArgument, d, e, fParam, uiParam);
        reinterpret_cast<::FUN_00973fd0_cls *>(&(::g_011e0e80))->FUN_00973fd0((::FnvArgObj *)(pNewObject));
    }
    return pNewObject;
}

namespace fnv_00689310 {
struct Vec
{
    float x, y, z;
};
struct Mat
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
};
struct Transform
{
    Mat rotation;
    Vec position;
    float scale;
    Transform();
    void Invert(Transform*);
    Transform operator*(const Transform&) const;
};
struct CloneData
{
    int a, b, c, d, e, f, g;
    CloneData(float);
    ~CloneData();
};
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Obj* asNode();
    Transform& World();
};
struct Parent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Attach(Obj*, bool);
};
struct Ptr
{
    Obj* p;
    Ptr(Obj*);
    ~Ptr();
    operator Obj*() const;
    Ptr& operator=(Obj*);
    Ptr& operator=(const Ptr&);
};
struct Loader
{
};
struct WorldMgr
{
};
struct Queue
{
    void Attach(Obj*, Parent*, bool, bool);
};
struct Effect
{
    int unk00, unk04;
    float scale;
    int unk0c, unk10, unk14;
    Ptr model;
    const char* filename;
    Ptr parent;
    Transform relative;
    void AttachModel(Parent*, Mat, Vec, float, unsigned int);
};
// Loads the model file, resolves or clones it, applies position/rotation/scale, attaches it to dest or the queue, then computes the relative transform to parent.
// @fnv 0x00689310
void Effect::AttachModel(Parent* apParent, Mat rotation, Vec position, float afScale, unsigned int flags)
{
    Ptr loaded6(((::fnv_00689310::Obj *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((((Loader*)(*reinterpret_cast<::Mgr * *>(&::g_modelLoader)))))->FUN_00447080((char *)(filename), 0, true, false, false, true))));
    if (!(Obj*)loaded6)
        return;
    model = (Obj*)0;
    int success = 0;
    if ((flags & 1) && (*reinterpret_cast<::fnv_00689310::WorldMgr * *>(&::g_TES)))
        success = reinterpret_cast<::FUN_0045aba0_cls *>(((*reinterpret_cast<::fnv_00689310::WorldMgr * *>(&::g_TES))))->FindMatchingNode(loaded6, (::ObjC *)(::fnv_00689310::Ptr *)(&model));
    if (!success)
    {
        if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((Obj*)loaded6)))->FUN_00726070())) <= 2)
            model = loaded6;
        else if (flags & 2)
        {
            CloneData clone2(1.0f);
            model = ((::fnv_00689310::Obj *)(reinterpret_cast<::A5D2C0Object *>((((Obj*)loaded6)))->FUN_00a5d2c0((*(::A5D2C0CloningProcess *)(&clone2)))));
        }
    }
    if (!(Obj*)model)
        return;
    if (flags & 4)
    {
        float value5 = reinterpret_cast<::FUN_00689840_Class *>(this)->ComputeTraversalValue((::TraversalItem *)(::fnv_00689310::Obj *)(model));
        if (value5 != -1.0)
        {
            if (value5 < 0.1f)
                value5 = 0.1f;
            scale = value5;
        }
    }
    Obj* node_ = ((Obj*)model)->asNode();
    if (node_)
        ::FUN_00578060((::NodeView *)(node_));
    reinterpret_cast<::FUN_00440460_S *>((((Obj*)model)))->FUN_00440460((const ::V3 *)&(position));
    reinterpret_cast<::FUN_0043fa80_s *>((((Obj*)model)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation)));
    reinterpret_cast<::FUN_00440490_shell *>((((Obj*)model)))->FUN_00440490(afScale);
    if (::FUN_008c7aa0())
        reinterpret_cast<::fnv_0087ac00::Owner0087ac00 *>((((::fnv_00689310::Queue *)(::TaskQueueInterface::GetSingleton()))))->QueueTaskWithTwoObjects((::fnv_0087ac00::G00559a40 *)(::fnv_00689310::Obj *)(model), (::fnv_0087ac00::G00559a40 *)(apParent), true, true);
    else
    {
        apParent->Attach(model, true);
        reinterpret_cast<::FUN_00a5a040_Class *>((((Obj*)model)))->FUN_00a5a040();
    }
    reinterpret_cast<::FUN_0068aa50_shell *>(this)->FUN_0068aa50(model);
    ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(::fnv_00689310::Obj *)(model));
    if ((Obj*)parent)
    {
        Transform local;
        local.scale = afScale;
        local.rotation = rotation;
        local.position = position;
        Transform world3 = ((Obj*)parent)->World();
        Transform inverseTmp;
        world3.Invert(&inverseTmp);
        relative = inverseTmp * local;
    }
}
}  // namespace fnv_00689310

struct NodeX
{
    unsigned int FUN_0043b480();
};
struct ArrP
{
};
struct ObjQ
{
};
struct ArrQ
{
    int* FUN_00877a30(int);
};
struct ThisT
{
    void CollectUniqueChildValues(NiNode* a0, ArrQ* a1, int* a2);
};

// @fnv 0x0068a8f0
void ThisT::CollectUniqueChildValues(NiNode* apNode, ArrQ* apValues, int* apiCount)
{
    if (apNode)
    {
        ArrP* p = (ArrP*)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<::NiRTTI *>(&::g_012024e0))), (::NiObject *)(apNode))));
        if (p)
        {
            unsigned int i;
            for (i = 0; i < reinterpret_cast<::FUN_004d7d50_StandIn *>((p))->FUN_004d7d50(); ++i)
            {
                ObjQ* pObj = (ObjQ*)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<::NiRTTI *>(&::g_01202548))), (::NiObject *)(void *)(reinterpret_cast<::Owner *>((p))->GetByIndex(i)))));
                if (pObj)
                {
                    bool bUnique = true;
                    int iExisting;
                    for (iExisting = *apiCount - 1; bUnique && iExisting >= 0; --iExisting)
                    {
                        if (*apValues->FUN_00877a30(iExisting) == reinterpret_cast<::FUN_009611e0_shell *>((pObj))->FUN_009611e0())
                            bUnique = false;
                    }
                    if (bUnique)
                    {
                        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apValues))->SetAt(*apiCount, (char *&)((const int &)(reinterpret_cast<::FUN_009611e0_shell *>((pObj))->FUN_009611e0())));
                        ++*apiCount;
                    }
                }
            }
        }
        NiNode* pChild = apNode->f3();
        if (pChild)
        {
            unsigned int uiChildIndex;
            for (uiChildIndex = 0; uiChildIndex < ((NodeX*)pChild)->FUN_0043b480(); ++uiChildIndex)
            {
                CollectUniqueChildValues(((::NiNode *)(reinterpret_cast<::NiNode *>((((NodeX*)pChild)))->GetAt(uiChildIndex))), apValues, apiCount);
            }
        }
    }
}

struct R01Diagnostic
{
    int m_formID;
    unsigned char m_type;
    unsigned char m_payload0, m_payload1, m_payload2, m_payload3;
    unsigned char m_grade;
};

struct R01SaveReader
{
};

struct R01Matrix3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    void Init();
};

struct R01Point3
{
    float x, y, z;
    void Init();
};

struct R01ParticleTransform
{
    float x, y, z, w;
    void Init();
};

struct NiUpdateData
{
    float m_uiCommandId;
    int m_unk04;
    int m_unk08;
    NiUpdateData(float);
};

struct R01Node
{
};

struct R01NodeRef
{
    void FUN_0066b0d0(R01Node*);
};

struct R01SceneRoot
{
};

struct R01SceneLink
{
    void* m_ptr;
    R01SceneLink(int);
    ~R01SceneLink();
};

struct R01Scene
{
};

struct R01CellDynamicNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual unsigned int AttachChildInAvailableSlot(R01Node*, int);
};

struct R01Cell
{
};

struct R01Form
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetDebugName();
};

struct R01Rand
{
};


struct R01FxPlayer
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    R01Cell* m_cell;
    int m_flags;
    int m_iValueAfterFlags;
    R01NodeRef m_nodeRef;
    R01Node* m_node;

    bool LoadFromSave();
};

// Reads a particle temp effect from the save buffer, rebuilds its scene node and transform, and reports block header or buffer size errors.
// @fnv 0x00689f80
bool R01FxPlayer::LoadFromSave()
{
    bool aA4 = true;
    unsigned char aAF8;
    R01Matrix3 aAccuracy5;
    float aAction2;
    unsigned short a3_2;
    R01ParticleTransform a1c4_2;
    R01Point3 aAPGeom;
    {
        unsigned short aA2 = 0;
        unsigned int a1c2 = 0;
        if (reinterpret_cast<::FUN_00862110_cls *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
        {
            unsigned int aA1c4;
            reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&aA1c4, 4);
            if (aA1c4 != 0x424c4f4b)
            {
                R01Diagnostic* diag = ((::R01Diagnostic *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))));
                if (diag)
                {
                    R01Form* form = ((::R01Form *)(::FUN_004839c0(diag->m_formID)));
                    ::FUN_005b5e40(
                        );
                }
                else
                {
                    ::FUN_005b5e40(
                        );
                }
            }
            a1c2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
            reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&aA2, 2);
        }
        aA4 = reinterpret_cast<::FUN_00682990_shell *>(this)->FUN_00682990();
        reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&aAF8, 1);
        char aActive8[0x104];
        ::FUN_00403d30(aActive8, 0, sizeof(aActive8));
        reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(aActive8, aAF8);
        reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&a1c4_2, 0x10);
        reinterpret_cast<::FUN_004f0180_Class *>(&(a1c4_2))->FUN_004f0180((::M3_ *)(::R01Matrix3 *)(&aAccuracy5));
        reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&aAPGeom, 0xc);
        reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&aAction2, 4);
        reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&a3_2, 2);
        if (aA4)
        {
            R01SceneRoot* a4_2 = ((::R01SceneRoot *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((reinterpret_cast<R01Scene*>((*reinterpret_cast<::Mgr * *>(&::g_modelLoader)))))->FUN_00447080(aActive8, 0, 1, 0, 0, 0)));
            if (a4_2)
            {
                m_nodeRef.FUN_0066b0d0(((::R01Node *)(reinterpret_cast<::CloneSourceA5d6 *>((a4_2))->FUN_00a5d680())));
                if (((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef)))))
                {
                    R01SceneLink aActorPos6(0);
                    reinterpret_cast<::FUN_004472a0_shell *>((reinterpret_cast<R01Scene*>((*reinterpret_cast<::Mgr * *>(&::g_modelLoader)))))->FUN_004472a0(aActive8, &aActorPos6);
                    m_node = ((::R01Node *)(::FUN_00559450((int *)(((::R01Node *)(::FUN_00559450((int *)&(aActorPos6))))))));
                    reinterpret_cast<::FUN_00440460_S *>((((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef))))))->FUN_00440460((const ::V3 *)(::R01Point3 *)(&aAPGeom));
                    reinterpret_cast<::FUN_0043fa80_s *>((((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef))))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&aAccuracy5)));
                    reinterpret_cast<::FUN_00440490_shell *>((((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef))))))->FUN_00440490(aAction2);
                    R01CellDynamicNode* aAFlags = ((::R01CellDynamicNode *)(reinterpret_cast<::TESObjectCELL *>((m_cell))->GetDynamicNode()));
                    aAFlags->AttachChildInAvailableSlot(((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef)))), 1);
                    reinterpret_cast<::FUN_00a5a040_Class *>((((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef))))))->FUN_00a5a040();
                    NiUpdateData aA148((float)((double)::fnv::timer::Time() / ::DAT_01017b70));
                    reinterpret_cast<::FUN_00a59c60_cls *>((((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef))))))->FUN_00a59c60((std::intptr_t)(&aA148));
                    ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(::R01Node *)(((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef))))));
                    if (a3_2)
                    {
                        void* a1c4 = ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac))), (::NiObject *)(void *)(((void *)(::fnv_0043b230::FUN_0043b230((const char *)(((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef))))))))))));
                        if (a1c4)
                        {
                            ::FUN_0055ffa0((::AnimationInterpolatorNode *)(a1c4), (::NiNode *)(::R01Node *)(((::R01Node *)(::FUN_00559450((int *)&(m_nodeRef))))), DAT_01012054);
                        }
                        else
                        {
                            aA4 = false;
                        }
                    }
                }
                else
                {
                    aA4 = false;
                }
            }
            else
            {
                aA4 = false;
            }
        }
        if (!aA4 && a3_2)
        {
            reinterpret_cast<::FUN_00857bd0 *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->Init(a3_2);
        }
        if (reinterpret_cast<::FUN_00862110_cls *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
        {
            unsigned int a1cTmp = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
            R01Diagnostic* diag = ((::R01Diagnostic *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(reinterpret_cast<R01SaveReader*>((*reinterpret_cast<::GlobalState * *>(&::g_TESSaveLoadGame)))))));
            if (diag)
            {
                R01Form* form = ((::R01Form *)(::FUN_004839c0(diag->m_formID)));
                if (a1cTmp > a1c2 + (unsigned int)aA2)
                {
                    ::FUN_005b5e40(
                        );
                }
                else if (a1cTmp < a1c2 + (unsigned int)aA2)
                {
                    ::FUN_005b5e40(
                        );
                }
            }
            else
            {
                if (a1cTmp > a1c2 + (unsigned int)aA2)
                {
                    ::FUN_005b5e40(
                        );
                }
                else if (a1cTmp < a1c2 + (unsigned int)aA2)
                {
                    ::FUN_005b5e40(
                        );
                }
            }
        }
    }
    return aA4;
}

class NiPoint3Value
{
  public:
    float x, y, z;
};
class NiMatrix3Value
{
  public:
    float r00, r01, r02, r10, r11, r12, r20, r21, r22;
};
class NiTransform
{
  public:
    NiMatrix3Value rotate;
    NiPoint3Value translate;
    float scale;
    NiTransform operator*(const NiTransform&) const;
public:
    void ResetToIdentity();
};
struct NiPoint3;
class NiAVObject
{
  public:
    const NiTransform& FUN_00461130() const;
public:
    ::NiPoint3 &FUN_0043c490();
};
template <class T> class NiPointer
{
  public:
    T* pointer;
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};
class ParticleUpdate
{
  public:
    int unk00, unk04;
    float duration;
    int unk0c;
    float elapsed;
    int unk14;
    NiPointer<NiAVObject> object;
    const char* filename;
    NiPointer<NiAVObject> parent;
    NiTransform localTransform;
    bool UpdateTransform(float);
};
// Calls FUN_006828a0, clears parent when its refcount is 1, and applies the parent's transform multiplied by localTransform to object.
// @fnv 0x00689a10
bool ParticleUpdate::UpdateTransform(float time)
{
    bool result = reinterpret_cast<::FUN_006828a0_shell *>(this)->FUN_006828a0(time);
    if (parent && ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((void *)((parent).operator->()))->FUN_00726070())) == 1)
        parent = 0;
    if (object && parent)
    {
        NiTransform transform = parent->FUN_00461130() * localTransform;
        reinterpret_cast<::FUN_00440460_S *>(((object).operator->()))->FUN_00440460((const ::V3 *)&(transform.translate));
        reinterpret_cast<::FUN_0043fa80_s *>(((object).operator->()))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(transform.rotate));
        reinterpret_cast<::FUN_00440490_shell *>(((object).operator->()))->FUN_00440490(transform.scale);
    }
    return result;
}

namespace fnv_00688fc0 {
class TESObjectCELL;

extern int DAT_01069c5c;

struct SoundPlaybackHandle
{
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    unsigned char m_auiShapeKeys[0x0c];
};

class NiTransform
{
  public:
    NiTransform();
    unsigned char m_auiShapeKeys[0x34];
};

struct GO
{
    GO(int value);
    ~GO();
    void operator=(void* value);
    void* m_ptr;
};

struct BSTempEffect
{
    BSTempEffect(TESObjectCELL* cell, float radius);
    ~BSTempEffect();
    std::uintptr_t m_kPointA;
    unsigned char m_auiShapeKeys[0x14];
};

struct FUN_00688fc0_shell : public BSTempEffect
{
    FUN_00688fc0_shell(TESObjectCELL* cell, float radius, const char* filename, void* node);
    ~FUN_00688fc0_shell();

    GO m_18;
    const char* pFilename;
    GO m_20;
    NiTransform m_kMotionTransform;
    void* m_58;
    SoundPlaybackHandle m_5c;
    SoundPlaybackHandle m_68;
};

// Constructs a temporary effect that stores a node pointer, a filename, and an identity motion transform.
// @fnv 0x00688fc0
FUN_00688fc0_shell::FUN_00688fc0_shell(TESObjectCELL* cell, float radius, const char* filename, void* node)
    : BSTempEffect(cell, radius), m_18((m_kPointA = (std::uintptr_t)&DAT_01069c5c, 0)), m_20(0), m_kMotionTransform(), m_5c(),
      m_68()
{
    m_18 = 0;
    m_20 = node;
    reinterpret_cast<::NiTransform *>(&(m_kMotionTransform))->ResetToIdentity();
    pFilename = filename;
    m_58 = 0;
}
}  // namespace fnv_00688fc0

namespace fnv_00689cb0 {
struct SGBaseFormComponent
{
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(SGBaseFormComponent* component);
    virtual bool CompareWithBase(SGBaseFormComponent* component);
};

struct SGForm : public SGBaseFormComponent
{
    virtual ~SGForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool Load(void* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(void* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(void* modInfo);
    virtual void WriteFormInfo(void* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(void* form);
    virtual void* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(void* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(void* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(void* form);
    virtual bool Compare(void* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
};

struct SGChangeRecord
{
    unsigned int auiFormId;
    unsigned char cType;
    unsigned char ucChangeFlags[4];
};

struct SGSaveLoadGame
{
};

struct SGSettingBool
{
    unsigned char* FUN_00408d60();
};

struct SGPoint3
{
    float x;
    float y;
    float z;
};

struct SGMatrix3;

struct SGQuaternion
{
    float w;
    float x;
    float y;
    float z;
    SGQuaternion();
};

struct SGObject
{
};
struct SGControllerManager;

struct SGAVObject
{
};

struct SGNodePtr
{
    operator SGAVObject*() const;
};


static const char s_szParticleFile[] =
    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectParticle.cpp";

struct SGTempEffectParticle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    SGNodePtr spParticle;
    const char* pFilename;
    void FUN_00689cb0();
};

// Writes particle effect state (filename, transform, controller sequence) to the save stream and logs the block size.
// @fnv 0x00689cb0
void SGTempEffectParticle::FUN_00689cb0()
{
    unsigned short usBlockLen = 0;
    unsigned short* pSizeLoc = 0;
    char* pBeginPos = ((char *)(std::uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
    if (*(*reinterpret_cast<::fnv_00689cb0::SGSettingBool *>(&::g_011de4e8)).FUN_00408d60())
    {
        pBeginPos = ((char *)(std::uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        unsigned int uiMarker = 'BLOK';
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&uiMarker, 4);
        pSizeLoc = (unsigned short*)((char *)(std::uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&usBlockLen, 2);
    }

    reinterpret_cast<::FUN_00682920_shell *>(this)->FUN_00682920();
    unsigned char ucLength = (unsigned char)::FUN_0044a670(pFilename);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&ucLength, 1);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((void*)pFilename, ucLength);

    SGQuaternion kQuaternion;
    reinterpret_cast<::NiQuaternion *>(&(kQuaternion))->FromRotationMatrix((const ::ThreeByThreeMatrix &)((*(const ::fnv_00689cb0::SGMatrix3 *)(::FUN_006a9540((char *)(((SGAVObject*)spParticle)))))));
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&kQuaternion, 16);
    SGPoint3 kLocalTranslate = (*(::fnv_00689cb0::SGPoint3 *)&(reinterpret_cast<::NiAVObject *>((((SGAVObject*)spParticle)))->FUN_0043c490()));
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&kLocalTranslate, 12);
    float fLocScale = reinterpret_cast<::FUN_009cdae0_shell *>((((SGAVObject*)spParticle)))->GetFloatAt64();
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&fLocScale, 4);

    unsigned short usSequence = 0;
    SGControllerManager* pController = ((::fnv_00689cb0::SGControllerManager *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(::fnv_00689cb0::SGObject *)(((::fnv_00689cb0::SGObject *)(::fnv_0043b230::FUN_0043b230((const char *)(((SGAVObject*)spParticle)))))))));
    if (pController)
    {
        usSequence = ::FUN_0055fdb0((::AnimationInterpolatorNode *)(pController));
    }
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&usSequence, 2);
    if (usSequence)
    {
        ::fnv_0055fe70::FUN_0055fe70((::AnimationInterpolatorNode *)(pController), ::DAT_01012054);
    }

    if (*(*reinterpret_cast<::fnv_00689cb0::SGSettingBool *>(&::g_011de4e8)).FUN_00408d60())
    {
        char* pDebugEnd = ((char *)(std::uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
        SGChangeRecord* pChange = ((::fnv_00689cb0::SGChangeRecord *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (pChange)
        {
            SGForm* pForm = ((::fnv_00689cb0::SGForm *)(::FUN_004839c0(pChange->auiFormId)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        std::uintptr_t uiEnd = (std::uintptr_t)((char *)(std::uintptr_t)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_00689cb0::SGSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
        std::uintptr_t uiStart = (std::uintptr_t)pSizeLoc;
        if (uiEnd > uiStart + 0xFFFF)
        {
            ::FUN_005b5e40();
        }
        *pSizeLoc = (unsigned short)(uiEnd - uiStart);
    }
}
}  // namespace fnv_00689cb0

#include "generated/data/fallout_shared/tempeffects/bstempeffectparticle.inc"
