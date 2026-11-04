
//
// fallout_shared/tempeffects/bstempeffectdebris.cpp
//
// Out-of-line definitions for BSTempEffectDebris. The foreground-element
// flag is stored in the object itself, so the accessor is a plain field
// read and the setter a plain field write.
//

#include <cstdint>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/AbstractHeap.h"
#include "fnv/decl/B683670List.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045aba0_cls.h"
#include "fnv/decl/FUN_0050e640_Holder.h"
#include "fnv/decl/FUN_00621b00_shell.h"
#include "fnv/decl/FUN_0062e0a0_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_006828a0_shell.h"
#include "fnv/decl/FUN_007b5300_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/RTTIEntry.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_007e6580.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_0087b140__FUN_0087b140_Holder.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_0069b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f9000.h"
#include "bstempeffectdebris.h"

// @fnv 0x00619b40
bool BSTempEffectDebris::ShouldDelete(void)
{
    return m_bShouldDelete;
}

void BSTempEffectDebris::SetIsForegroundEffect(bool foregroundElement)
{
    m_bShouldDelete = foregroundElement;
}

struct FUN_0050e620_S
{
    void FUN_0050e620(unsigned char p);
};
// @fnv 0x0050e620
void FUN_0050e620_S::FUN_0050e620(unsigned char p)
{
    reinterpret_cast<::FUN_0050e640_Holder *>(this)->MatchesValue(p);
}


// @fnv 0x00618940
void FUN_00618940(void* thisPtr)
{
    reinterpret_cast<::RTTIEntry *>((thisPtr))->FUN_0061bcf0();
}

struct BGSEntryPointFunctionData;
struct TESFile;
struct TESForm;
struct FUN_009b3120_shell : public BSTempEffectDebris
{
    int FUN_009b3120();
};

// @fnv 0x009b3120
int FUN_009b3120_shell::FUN_009b3120()
{
    return 2;
}


struct FUN_00682ac0_shell
{
    void* GetGlobalPtr() const;
};

// @fnv 0x00682ac0
void* FUN_00682ac0_shell::GetGlobalPtr() const
{
    return &(*reinterpret_cast<void * *>(&::g_011d6a90));
}

struct GlobalObject_006836f0
{
    void FUN_006834e0(void** p);
};


// @fnv 0x00683310
void FUN_00683310(void* p)
{
    if (p)
        ::g_011d6a74.FUN_006834e0(&p);
}

struct FUN_00683460_shell
{
    unsigned char m[0x21];
    void SetFlag(unsigned char aFlag);
};

// @fnv 0x00683460
void FUN_00683460_shell::SetFlag(unsigned char aFlag)
{
    m[0x21] = aFlag;
}

struct FUN_006834a0_shell
{
    int m_000;
    int m_004;
    bool MatchesValue(int arg);
};

// Returns true when the object exists and its m_004 field equals arg, otherwise false.
// @fnv 0x006834a0
bool FUN_006834a0_shell::MatchesValue(int aiValue)
{
    return this ? m_004 == aiValue : 0;
}

struct FUN_00683480_shell
{
    bool FUN_00683480(int);
};

// @fnv 0x00683480
bool FUN_00683480_shell::FUN_00683480(int aiValue)
{
    return reinterpret_cast<::FUN_006834a0_shell *>(this)->MatchesValue(aiValue);
}

struct StandIn
{
    void FUN_00682f40();
    void* FUN_00682ad0(unsigned int);
};
struct Limit
{
    int f0;
    int f1;
    int f2;
};
struct Holder
{
    virtual Limit* f0();
    virtual Limit* f1();
    void FUN_006834e0(int* p);
};
// Gets a Limit via f1(), stores the int pointed to by a into its f2 field, then passes it to AppendBlock.
// @fnv 0x006834e0
void Holder::FUN_006834e0(int* aiValue)
{
    Limit* p = f1();
    p->f2 = *aiValue;
    reinterpret_cast<::AbstractHeap *>(this)->AppendBlock((::MemoryBlockHeader *)(p));
}

class EffectBase
{
  public:
    EffectBase(int iArg, float fArg);
    ~EffectBase();
    virtual void v0();
    char m_04[0x14];
};

class MemberPtr
{
  public:
    MemberPtr(int p);
    ~MemberPtr();
    void FUN_0066b0d0(std::intptr_t p);
    int m_p;
};

class FUN_00682c40 : public EffectBase
{
  public:
    FUN_00682c40(int iArg, float fArg, int iVal, int a4, int a5, int a6, int a7, int a8, float f9, bool b10, char c11);
    virtual void v0();

    MemberPtr m_18;
    std::intptr_t m_1c;
    char m_20;
    char m_21;
};

class B83330Item;

class B83330List
{
  public:
    void RemovePos(void*& pkPos);
    B83330Item*& GetNext(void*& pkPos);
};


// Removes pkItem from g_kB83330Menus by scanning the list until the matching entry is found and erased.
// @fnv 0x00683330
void __cdecl RemoveMenuEntry(B83330Item* pkItem)
{
    if (pkItem && !::IsFieldCZero((::Dummy_0069b080 *)&((*reinterpret_cast<::B83330List *>(&::g_011d6a74)))))
    {
        void* pkPos2;
        bool bRemoved = false;
        pkPos2 = ((void *)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::B83330List *>(&::g_011d6a74))))->GetName()));
        while (pkPos2 && !bRemoved)
        {
            if (((::B83330Item *)(reinterpret_cast<::FUN_006317a0_struct *>(&((*reinterpret_cast<::B83330List *>(&::g_011d6a74))))->AddEight((std::intptr_t)(pkPos2)))) == pkItem)
            {
                (*reinterpret_cast<::B83330List *>(&::g_011d6a74)).RemovePos(pkPos2);
                bRemoved = true;
            }
            else
            {
                (*reinterpret_cast<::B83330List *>(&::g_011d6a74)).GetNext(pkPos2);
            }
        }
    }
}

struct C683550Item
{
    C683550Item* m_pkNext;
    C683550Item* m_pkPrev;
    void* m_element;
};

typedef void* C683550Iterator;

class C683550PointerList
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void DeleteItem(C683550Item* pkItem);

    void* RemoveAt(C683550Iterator& kPos);

    C683550Item* m_pkHead;
    C683550Item* m_pkTail;
    unsigned int m_uiCount;
};

// RemovePos
// Removes the node at the given iterator position, advancing the iterator, and returns the stored element.
// @fnv 0x00683550
void* C683550PointerList::RemoveAt(C683550Iterator& kPos)
{
    C683550Item* pkNode = (C683550Item*)kPos;

    if (pkNode == m_pkHead)
    {
        kPos = pkNode->m_pkNext;
        return reinterpret_cast<::FUN_0062e0a0_shell *>(this)->RemoveFirstNode();
    }
    if (pkNode == m_pkTail)
    {
        kPos = 0;
        return reinterpret_cast<::B683670List *>(this)->RemoveHead();
    }

    C683550Item* pkPrev = pkNode->m_pkPrev;
    C683550Item* pkNext = pkNode->m_pkNext;
    kPos = pkNext;
    if (pkPrev)
        pkPrev->m_pkNext = pkNext;
    if (pkNext)
        pkNext->m_pkPrev = pkPrev;

    void* element = pkNode->m_element;
    DeleteItem(pkNode);
    m_uiCount--;
    return element;
}

struct FUN_006827b0
{
    virtual ~FUN_006827b0();
    unsigned int unk04;
    float unk08;
    TESObjectCELL* unk0c;
    float unk10;
    unsigned char unk14;
    FUN_006827b0(TESObjectCELL*, float);
};
struct Ptr682
{
    void* value;
    Ptr682(void*);
    ~Ptr682();
    void FUN_0066b0d0(void*);
};
struct Vec682
{
    float x, y, z;
};
struct B006815c0
{
    float m00, m01, m02, m03, m04, m05, m06, m07, m08;
    B006815c0();
};
struct FUN_00682b00 : FUN_006827b0
{
    Ptr682 node;
    const char* filename;
    bool useCounter;
    bool forceDelete;
    virtual ~FUN_00682b00();
    FUN_00682b00(TESObjectCELL*, float, const char*, void*, void*, Vec682*, void*, void*, float, unsigned char, bool);
};
struct CloneContext
{
    void* mapVtable;
    unsigned int bucketCount;
    void* buckets;
    unsigned int entryCount;
    void* processHead;
    void* processTail;
    float scale;
    CloneContext(float);
    ~CloneContext();
};
struct UpdateContext
{
    float time;
    bool updateControllers;
    bool multithreaded;
    bool updateGeomorphs;
    bool updateShadow;
    bool updateBound;
    UpdateContext(float, bool, bool);
};
struct SceneObject;
struct SceneNode
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
    virtual void AttachChildInAvailableSlot(SceneObject*, bool);
};
struct CellContext
{
};
struct SceneObject
{
};
struct ScenePointer : MemberPtr
{
};
struct ModelService
{
};
struct QueueService
{
};
struct EffectRegistry
{
};
void FUN_006833b0();
struct DebrisEffect : FUN_00682c40
{
    void SpawnDebris(std::intptr_t a4, std::intptr_t a5, std::intptr_t a6, std::intptr_t a7, std::intptr_t a8, float f9, bool b10);
};
class DebrisNode;

struct DebrisManager
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void RemoveDebris(DebrisNode* node);
};

class DebrisNode : public NiAVObject
{
  public:
};

template <class T> class DebrisPtr
{
  public:
    ~DebrisPtr();
    operator T*() const;
    DebrisPtr<T>& operator=(T* object);
    T* m_pObject;
};

struct ModelLoader
{
};

struct DebrisCounter
{
};

struct TaskQueueInterface
{
public:
    static ::TaskQueueInterface *GetSingleton();
};


class FUN_00682f40 : public BSTempEffect
{
  public:
    virtual ~FUN_00682f40();

    DebrisPtr<DebrisNode> m_pSceneObject;
    const char* pFilename;
    bool m_bForegroundEffect;
    bool bForceDelete;
    bool m_bShouldDelete;
};
// Calls FUN_00682f40, then if the low bit of flags is set frees this with _delete and returns this.
// @fnv 0x00682ad0
void* StandIn::FUN_00682ad0(unsigned int flags)
{
    reinterpret_cast<::FUN_00682f40 *>((this))->FUN_00682f40::~FUN_00682f40();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x24);
    return this;
}

// @fnv 0x00682f40
FUN_00682f40::~FUN_00682f40()
{
    if (pFilename)
        reinterpret_cast<::FUN_00445300_shell *>((::g_modelLoader))->FUN_00445300((char*)pFilename, false, 1);
    if (m_pSceneObject && ((::DebrisManager *)(reinterpret_cast<::FUN_009611e0_shell *>((((DebrisNode*)m_pSceneObject)))->FUN_009611e0())))
    {
        ((::DebrisManager *)(reinterpret_cast<::FUN_009611e0_shell *>((((DebrisNode*)m_pSceneObject)))->FUN_009611e0()))->RemoveDebris(m_pSceneObject);
    }
    if (reinterpret_cast<::FUN_00683480_shell *>(&((*reinterpret_cast<::DebrisCounter *>(&::g_011c3ea4))))->FUN_00683480(1))
    {
        ::FUN_00c6a270((std::intptr_t)(m_pSceneObject.m_pObject), true, true, 0);
        ::FUN_00c69ee0(m_pSceneObject, true, 0);
    }
    else
    {
        reinterpret_cast<::fnv_0087b140::FUN_0087b140_Holder *>((::TaskQueueInterface::GetSingleton()))->QueueTaskIfPresent((::fnv_0087b140::G00559a40 *)(::NiAVObject *)(m_pSceneObject));
    }
    if (m_bForegroundEffect)
        RemoveMenuEntry((B83330Item*)this);
    m_pSceneObject = 0;
}

struct GlobalObject_0040e0b0
{
};

struct FaceGenForm
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* GetForm();
};

class BSFaceGenKeyframe
{
  public:
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
    virtual FaceGenForm* vf98();

    double GetTime();
    bool FUN_006830a0(float fArg);

    unsigned int unk04;
    float unk08;
    float unk0C;
    int unk10;
    int unk14;
    void* unk18;
    void* unk1C;
    unsigned char byte20;
    unsigned char byte21;
};


// @fnv 0x006830a0
bool BSFaceGenKeyframe::FUN_006830a0(float fArg)
{
    bool result5 = reinterpret_cast<::FUN_006828a0_shell *>(this)->FUN_006828a0(fArg);
    if (byte21)
    {
        result5 = false;
    }
    if (result5)
    {
        float delta8 = GetTime() - ((double)(reinterpret_cast<::FUN_00621b00_shell *>(this)->FUN_00621b00()));
        if (delta8 >= ::_DAT_01012060)
        {
            if (delta8 <= *((float *)&(::FUN_00403e20((float *)&(::g_011cfbfc)))))
            {
                FaceGenForm* obj2 = vf98();
                void* b = obj2 ? obj2->GetForm() : 0;
                if (b)
                {
                    float v_ = delta8 / *((float *)&(::FUN_00403e20((float *)&(::g_011cfbfc))));
                    ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(b), v_);
                }
            }
        }
    }
    return result5;
}

struct WorldObj;
struct WorldNode
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual WorldNode* IsSceneNode();
    unsigned int FUN_0043b480();
};
struct WorldFade
{
};
struct WorldFilter
{
    unsigned int iFilter;
    WorldFilter();
};
struct WorldActor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool IsCollidable();
    WorldFilter FUN_00931ed0();
};
struct WorldHavok
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void AddObject(WorldObj* pkObj, WorldNode* pk3D);
};
struct WorldCell;
struct FUN_00683190_shell
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual WorldNode* Get3D();
    void AttachCollisionObject(WorldActor* pkActor);
};
// Constructs the effect: initialises the base and member pointer, stores iVal and c11, clears m_21, then calls SpawnDebris with the remaining arguments.
// @fnv 0x00682c40
FUN_00682c40::FUN_00682c40(int iArg, float fArg, int iVal, int a4, int a5, int a6, int a7, int a8, float f9, bool b10,
                           char c11)
    : EffectBase(iArg, fArg), m_18(0)
{
    m_18.FUN_0066b0d0(0);
    m_1c = iVal;
    m_20 = c11;
    m_21 = 0;
    reinterpret_cast<::DebrisEffect *>(this)->SpawnDebris(a4, a5, a6, a7, a8, f9, b10);
}
// @fnv 0x00682b00
FUN_00682b00::FUN_00682b00(TESObjectCELL* cell, float duration, const char* name, void* p4, void* p5, Vec682* direction,
                           void* p7, void* p8, float f, unsigned char flag, bool abUseCounter)
    : FUN_006827b0(cell, duration), node(0)
{
    node.FUN_0066b0d0(0);
    filename = name;
    useCounter = abUseCounter;
    forceDelete = false;
    Vec682 scene = *direction;
    B006815c0 existing;
    float owner = scene.z;
    scene.z = 0.0f;
    float active = reinterpret_cast<::NiPoint3 *>(&(scene))->ComputeMagnitude();
    reinterpret_cast<::ThreeByThreeMatrix *>(&(existing))->FUN_00a59780(FUN_004b5550(scene.x, scene.y), 0.0f, -FUN_004b5550(owner, active));
    reinterpret_cast<::DebrisEffect *>(this)->SpawnDebris((std::intptr_t)(p4), (std::intptr_t)(p5), (std::intptr_t)(&existing), (std::intptr_t)(p7), (std::intptr_t)(p8), f, flag);
}
// @fnv 0x00682d10
void DebrisEffect::SpawnDebris(std::intptr_t a4, std::intptr_t a5, std::intptr_t a6, std::intptr_t a7, std::intptr_t a8, float f9, bool abUseQueue)
{
    reinterpret_cast<::Twin_007e6580 *>(this)->SetIsForegroundEffect(false);
    SceneObject* update = ((::SceneObject *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::ModelService * *>(&::g_modelLoader))))->FUN_00447080((char *)(m_1c), 0, true, false, false, false)));
    if (abUseQueue)
    {
        if ((*reinterpret_cast<::QueueService * *>(&::g_TES)))
            reinterpret_cast<::FUN_0045aba0_cls *>(((*reinterpret_cast<::QueueService * *>(&::g_TES))))->FindMatchingNode(update, (::ObjC *)(::MemberPtr *)(&m_18));
        else
            m_18.FUN_0066b0d0(0);
    }
    else
    {
        CloneContext clone(1.0f);
        m_18.FUN_0066b0d0((std::intptr_t)((::SceneObject *)(reinterpret_cast<::A5D2C0Object *>((update))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(clone)))));
    }
    if (!((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18))))) || !((::CellContext *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())))
        return;
    SceneNode* model = ((::SceneNode *)(reinterpret_cast<::TESObjectCELL *>((((::CellContext *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->GetDynamicNode()));
    if (model)
        model->AttachChildInAvailableSlot(((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18))))), true);
    reinterpret_cast<::FUN_00440460_S *>((((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18)))))))->FUN_00440460((const ::V3 *)(a5));
    reinterpret_cast<::FUN_0043fa80_s *>((((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18)))))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(a6)));
    reinterpret_cast<::FUN_00440490_shell *>((((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18)))))))->FUN_00440490(f9);
    ::ProcessPropertyTree((::PropHelper *)(::SceneObject *)(((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18)))))), 5);
    reinterpret_cast<::FUN_00683190_shell *>(this)->AttachCollisionObject((::WorldActor *)(a4));
    reinterpret_cast<::FUN_00a5a040_Class *>((((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18)))))))->FUN_00a5a040();
    UpdateContext node(::fnv_00563f30::DAT_011c3c08, true, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18)))))))->FUN_00a59c60((std::intptr_t)&(node));
    ::FUN_0062b8d0(((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18))))), (const void *)(a7), true);
    ::FUN_0062ba80(((::SceneObject *)(::FUN_00559450((int *)&(static_cast<ScenePointer&>(m_18))))), (*(const ::NiPoint3 *)(a8)), true);
    reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::EffectRegistry *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(::FUN_00682c40 *)(this));
    if ((unsigned char)m_20)
    {
        FUN_00683310(this);
        FUN_006833b0();
    }
}
// Resolves the object from the 3D node (via fade or child nodes), then adds it to the cell's havok world with the actor's collision filter.
// @fnv 0x00683190
void FUN_00683190_shell::AttachCollisionObject(WorldActor* pkActor)
{
    WorldNode* pk3D = Get3D();
    WorldObj* pkObj = (WorldObj*)pk3D;
    if (pk3D)
    {
        WorldNode* pkNode = (WorldNode*)((::WorldFade *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const void *const *>(&::g_011f9140))), (::NiObject *)(pk3D))));
        if (pkNode)
        {
            pkObj = ((::WorldObj *)(reinterpret_cast<::S_FUN_0045bc00 *>((((WorldFade*)pkNode)))->FUN_0045bc00(false)));
        }
        else
        {
            pkNode = pk3D->IsSceneNode();
            unsigned int uiObjType = ::FUN_004a8b00((::BGSBodyPart *)(pkObj));
            if (!uiObjType && pkNode && pkNode->FUN_0043b480() && ((::WorldObj *)(reinterpret_cast<::NiNode *>((pkNode))->GetAt(0))))
            {
                pkObj = ((::WorldObj *)(reinterpret_cast<::NiNode *>((pkNode))->GetAt(0)));
                unsigned int uiChildType = ::FUN_004a8b00((::BGSBodyPart *)(pkObj));
                if (!uiChildType && pkNode && pkNode->FUN_0043b480() > 1 && ((::WorldObj *)(reinterpret_cast<::NiNode *>((pkNode))->GetAt(1))))
                    pkObj = ((::WorldObj *)(reinterpret_cast<::NiNode *>((pkNode))->GetAt(1)));
            }
        }
        if (pkObj)
        {
            WorldCell* pkCell = ((::WorldCell *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
            if (pkCell)
            {
                WorldHavok* pkWorld = ((::WorldHavok *)(reinterpret_cast<::FUN_004543c0_cls *>((pkCell))->FUN_004543c0()));
                if (pkWorld)
                {
                    if (pkActor && pkActor->IsCollidable())
                    {
                        WorldActor* pkCollider = pkActor;
                        ::FUN_00c6a3d0(pkObj, ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::WorldFilter &)(pkCollider->FUN_00931ed0()))->FUN_004a3a20())), 1, 1);
                    }
                    pkWorld->AddObject(pkObj, pk3D);
                }
            }
        }
    }
}


struct FUN_006833b0_glob
{
};

struct FUN_006833b0_cf
{
};

struct FUN_006833b0_item
{
};

// @fnv 0x006833b0
void FUN_006833b0()
{
    int n;
    void* p2;
    void* r;

    if (!::IsFieldCZero((::Dummy_0069b080 *)(reinterpret_cast<FUN_006833b0_glob*>(&::g_011d6a74))))
    {
        if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<FUN_006833b0_glob*>(&::g_011d6a74)))->FUN_0084e3a0())) >
            *((unsigned int *)&(::FUN_0043d4d0((int *)(reinterpret_cast<FUN_006833b0_cf*>(&(*reinterpret_cast<void * *>(&::g_011cf3e4))))))))
        {
            n = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<FUN_006833b0_glob*>(&::g_011d6a74)))->FUN_0084e3a0())) -
                *((unsigned int *)&(::FUN_0043d4d0((int *)(reinterpret_cast<FUN_006833b0_cf*>(&(*reinterpret_cast<void * *>(&::g_011cf3e4)))))));
            for (p2 = ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<FUN_006833b0_glob*>(&::g_011d6a74)))->GetName())); p2 != 0 && n > 0;
                 p2 = ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_007b5300_shell *>((reinterpret_cast<FUN_006833b0_glob*>(&::g_011d6a74)))->GetSecondField((::FUN_007b5300_param *)(p2)))))
            {
                r = *((void **)(reinterpret_cast<::FUN_006317a0_struct *>((reinterpret_cast<FUN_006833b0_glob*>(&::g_011d6a74)))->AddEight((std::intptr_t)(p2))));
                if (r != 0)
                {
                    reinterpret_cast<::FUN_00683460_shell *>((reinterpret_cast<FUN_006833b0_item*>(r)))->SetFlag(1);
                    n = n - 1;
                }
            }
        }
    }
}
