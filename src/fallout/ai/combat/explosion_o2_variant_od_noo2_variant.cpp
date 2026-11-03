
// src/fallout/ai/combat/explosion_o2_variant_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy (unit src/fallout/ai/combat/explosion_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/explosion_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/explosion.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstdint>
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSXFlags_shell.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004dfec0_Class.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_005076c0Class.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_0056d360_Class.h"
#include "fnv/decl/FUN_00622290_cls.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_006e4340_Class.h"
#include "fnv/decl/FUN_00810550_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009ae0f0.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00c6b980_cls.h"
#include "fnv/decl/FUN_00c867d0_cls.h"
#include "fnv/decl/FUN_00c86800_Class.h"
#include "fnv/decl/FUN_00c868b0_cls.h"
#include "fnv/decl/FUN_00cbc740.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MersenneTwister.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiObject.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SceneC8E.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/Wrapper86b80.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_0056f110__FUN_0056f110_class.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c86790__Holder.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/s005468d0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00578000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c1000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01204000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
struct ActorCause
{
};
struct NiPointer
{
    NiPointer& operator=(ActorCause*);
};
struct FUN_009ac170_shell
{
    char m_auiShapeKeys[0xd0];
    NiPointer m_actorCause;
    void FUN_009ac170(ActorCause* apActorCause);
};
struct Explosion
{
    virtual ~Explosion();
    void* Destroy(unsigned int flags);
};
struct NiRTTI;
struct bhkLiquidAction
{
    const NiRTTI* GetRTTI() const;
};
struct NavMesh;
struct NavMeshPtr
{
};
struct FUN_009afc30_shell
{
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};
struct BSOcclusionPlane
{
    int IsNotCulled();
};
struct FUN_009afbb0_shell
{
    virtual ~FUN_009afbb0_shell();
    void* FUN_009afbb0(unsigned int flags);
};
extern "C" void __cdecl FUN_009afbe0(void*);
struct FUN_00621100_shell
{
    void SetVtable(void);
};
struct FUN_009afc10_shell
{
    void FUN_009afc10();
};
struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};
struct P03MM
{
};
struct FUN_00cbd4e0_shell
{
    char m_auiShapeKeys[0x14];
    void* FUN_00cbd4e0(unsigned char flag);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct FUN_00cbc650_obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
};
struct FUN_00cbc650_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual FUN_00cbc650_obj* vGet(FUN_00cbc650_obj* volatile* pp);
    void FUN_00cbc650(FUN_00cbc650_obj* volatile a1);
};
struct FUN_00cbc6a0_Data
{
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0C;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
};
struct FUN_00cbc6a0_Class
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void FUN_00cbc6a0(unsigned char* arg);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual FUN_00cbc6a0_Data* vf45(int* value);
};
void* __cdecl FUN_00aa13e0(unsigned int size);
struct AutoMemContext
{
    int oldContext;
    AutoMemContext()
    {
        oldContext = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 16;
    }
    ~AutoMemContext()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = oldContext;
    }
};
struct FUN_00cbc550_class
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
    FUN_00cbc550_class();
};
struct FUN_00cbca20_class
{
    FUN_00cbc550_class* FUN_00cbca20(int flags);
};
struct HavokAllocator
{
    virtual void vf00();
    virtual void* allocate(int size);
    virtual void deallocate(void* p, int size);
};
struct HavokAllocatorContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HavokAllocator* m_alloc;
};
extern "C" HavokAllocatorContext* __cdecl FUN_00c85750();
struct HavokObj
{
    int unk00;
    short m_flags;
    short m_ref;
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

    static void* operator new(size_t size)
    {
        HavokAllocatorContext* tm = FUN_00c85750();
        HavokObj* p = (HavokObj*)tm->m_alloc->allocate(size);
        p->m_flags = (short)size;
        return p;
    }
    static void operator delete(void* p);

    HavokObj(void* a1, int a2);
};
struct DynCastHelper2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* unk18;
};
struct DynCastHelper1
{
    int unk00;
    int unk04;
    DynCastHelper2* unk08;
};
struct DynCastObj
{
};
struct GarbageCollectorObjectPtr
{
    DynCastObj* m_ptr;
    int m_unk04;
};
GarbageCollectorObjectPtr* __cdecl FUN_00c85ef0(GarbageCollectorObjectPtr* out, void* obj, const void* rtti);
struct ArgStruct
{
    int unk00;
    void* unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
};
struct TargetClass
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf8c(HavokObj* obj);
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vfbc(ArgStruct* arg);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;

    void FUN_00cbcbd0(void* p);
    void FUN_00cbd520(ArgStruct* arg);
};
class NiViewerStringArray
{
  public:
    virtual ~NiViewerStringArray();
    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class FUN_00cbd650_base
{
  public:
};
class FUN_00cbd650_cls : public FUN_00cbd650_base
{
  public:
    void FUN_00cbd650(NiViewerStringArray* pkStrings);
};
struct SmallAlignedState
{
    unsigned int unk00;
    void* unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    SmallAlignedState() : unk00(0), unk04(0), unk08(5000.0f), unk0c(15.0f), unk10(64.0f), unk14(15.0f)
    {}
};
struct StateAllocator
{
};
struct StateOwner
{
    unsigned int unk00;
    unsigned int unk04;
    void* unk08;
    SmallAlignedState* unk0c;
    unsigned int unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    SmallAlignedState* FUN_00cbcad0(bool* created);
};

#include <xmmintrin.h>
struct BSFadeNode
{
public:
    void SetRange(float, float);
};
struct NiPoint3
{
    float x, y, z;
public:
    float ComputeMagnitude() const;
};
struct Upd;
struct Obj;
struct Sub
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Obj* V0c();
    virtual void* V10();
};
struct Chain
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void* V0c();
};
struct Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Chain* V0c();
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
    virtual void Vd0(Obj* a, int b, int c, int d, int e);
    virtual void v53();
    virtual void Vd8(Obj* a, int b);
    virtual void Vdc(void* a, int b);
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
    virtual void* V130();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void V1c8();
    virtual void v115();
    virtual Obj* V1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* V1f4();
    bool FUN_004bae00();
    void Update(Upd* a);
};
struct SoundFile
{
    char* Get();
};
struct Proj
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
    SoundFile name;
};
struct Cell
{
};
struct This
{
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
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    float f8c;
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void W1c8(int a);
    virtual void v115();
    virtual Obj* W1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* W1f4();
    void FUN_009ad670();
};
struct SettingColl
{
};
extern char DAT_0108f1a8;
extern char DAT_0108f16c;
struct FixedStr
{
};
struct Eyes
{
};
struct Handler
{
    Eyes* Get();
};
struct TObj
{
};
void* __cdecl _ref_0084e3a0(Proj* a);
struct Local70
{
    float m0;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float m6;
    float m7;
    float m8;
};
struct Extra
{
};
struct FloatConfiguredObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FloatConfiguredObject(float);
    ~FloatConfiguredObject();
};
void* __cdecl FUN_00aa13e0(unsigned int n);
struct BigObj : BSFadeNode
{
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
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    BigObj(int);
    void* FUN_00a5ecb0(int a);
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
    virtual void Vdc(void* a, int b);
};
struct Rnd
{
    float F();
    float F(float a);
};
struct PathReq
{
};
struct InitObj : BSFadeNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    InitObj(void*);
    void* Init(void* a);
    void FUN_00c6b980(void* a);
};
struct Sphere : BSFadeNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Sphere(float, bool);
    void* Ctor(float a, int b);
};
struct __declspec(align(16)) Big
{
    __m128 unk00;
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
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    Big();
    void FUN_0056f0f0(void* a);
    ~Big();
};
struct FilterValue
{
};
struct Temp622
{
    int unk00;
    FilterValue* Ctor(int a, void* b, int c);
};
struct Body : BSFadeNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Body(Big*);
    void* FUN_0056d380(Big* a);
    void FUN_00c6b980(void* a);
};
struct Acc : BSFadeNode
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
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    Acc();
    void* Ctor();
};
struct S1fc
{
    int unk00;
    void Ctor();
    void* m04;
    float fa, fb, fc, fd;
};
extern float DAT_011a57fc;
extern float DAT_011a5800;
extern float DAT_011a5804;
extern float DAT_011a5808;
extern float DAT_011a580c;
extern float DAT_011a5810;
struct A140 : BSFadeNode
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
    A140(S1fc*);
    void* Ctor(S1fc* a);
};
struct Upd
{
    float time;
    bool updateControllers;
    bool isMultithreaded;
    int flags;
    void Ctor(float a, int b, int c);
};
struct NodeU
{
    void Update(Upd* a);
};
bool __cdecl FUN_004bae00(void* a);
struct Ctrl
{
};
struct Seq
{
};
struct Fade
{
};
// @fnv 0x009ad670
void This::FUN_009ad670()
{
    W1c8(0);
    Obj* obj = W1d0();
    if (obj)
    {
        float scale = 1.0f;
        if (((bool)(reinterpret_cast<::BSOcclusionPlane *>(this)->IsNotCulled())))
        {
            Chain* node = obj->V0c();
            Fade* fade = node ? (Fade*)((Sub*)node)->V10() : 0;
            if (fade)
                reinterpret_cast<::BSFadeNode *>((fade))->SetRange(DAT_01016970, DAT_01016970);
        }
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingColl *>(&::g_011d0fe4)))))) == 0)
        {
            TObj* named = (TObj*)((::Obj *)(::FUN_004aae30((::NiAVObject *)(obj), (::NiFixedString *)(void *)(&DAT_0108f1a8))));
            if (named)
            {
                scale = reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930() / reinterpret_cast<::NiPoint3 *>((((::Eyes *)&(reinterpret_cast<::NiAVObject *>((named))->FUN_0043c490()))))->ComputeMagnitude();
            }
            else
            {
                const char* name;
                if (reinterpret_cast<::BGSCameraPath *>((((::Proj *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->HasNameForWarning())
                {
                    Obj* base = (Obj*)((::Proj *)(reinterpret_cast<::Actor *>(this)->GetActorBase()));
                    name = (const char*)base->V130();
                }
                else
                    name = ((char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::Proj *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))->name))->FUN_00408da0()));
                ::FUN_005b5e40();
                scale = 1.0f;
            }
        }
        reinterpret_cast<::FUN_00440490_shell *>((obj))->FUN_00440490(scale);
        reinterpret_cast<::FUN_00440460_S *>((obj))->FUN_00440460((const ::V3 *)(::NiPoint3 *)(W1f4()));
        NiPoint3 angles = *((::NiPoint3 *)(reinterpret_cast<::TESRecipe *>(this)->GetData()));
        Local70 rotation;
        new ((void *)&(rotation)) ::Vec3();
        reinterpret_cast<::ThreeByThreeMatrix *>(&(rotation))->FUN_00a59780(angles.z, angles.y, angles.x);
        reinterpret_cast<::FUN_0043fa80_s *>((obj))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation)));
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingColl *>(&::g_011d0fe4)))))) > 1)
        {
            reinterpret_cast<::PathingRequest *>((((PathReq*)((::Proj *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))))->SetCenterRadius(DAT_011a5810);
            f8c = DAT_011a580c;
            NiPoint3 position = *W1f4();
            void* extra = ((void *)(reinterpret_cast<::NiAVObject *>((obj))->GetExtraData((*(const ::NiFixedString *)((void*)&(*(const ::FixedStr *)&(::FUN_00448a80())))))));
            if (extra)
            {
                Extra* flags = (Extra*)extra;
                reinterpret_cast<::BSXFlags_shell *>((flags))->FUN_00519230(0x10, 1);
            }
            for (int i = 0; i < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingColl *>(&::g_011d0fe4)))))); ++i)
            {
                FloatConfiguredObject guard(1.0f);
                BigObj* node = new BigObj(0);
                reinterpret_cast<::FUN_004bc1f0_S *>((node))->FUN_004bc1f0((float)(reinterpret_cast<::FUN_004dfec0_Class *>((((Rnd*)((void *)(::MersenneTwister::GetRandomGenerator())))))->FUN_004dfec0() * 10.0),
                                   (float)(reinterpret_cast<::FUN_004dfec0_Class *>((((Rnd*)((void *)(::MersenneTwister::GetRandomGenerator())))))->FUN_004dfec0() * 10.0),
                                   (float)(reinterpret_cast<::FUN_004dfec0_Class *>((((Rnd*)((void *)(::MersenneTwister::GetRandomGenerator())))))->FUN_004dfec0() * 10.0 + 32.0));
                InitObj* collision = new InitObj(node);
                Sphere* shape = new Sphere(8.0f, 1);
                Big info;
                reinterpret_cast<::FUN_00507610_Class *>(&(info))->FUN_00507610(5.0f);
                reinterpret_cast<::FUN_006e4340_Class *>(&(info))->FUN_006e4340(0.0f);
                reinterpret_cast<::FUN_0056d360_Class *>(&(info))->FUN_0056d360(1);
                reinterpret_cast<::FUN_005076c0Class *>(&(info))->FUN_005076c0(1.0f);
                Temp622 filter;
                info.FUN_0056f0f0(((void *)(::FUN_00559450((int *)(((::FilterValue *)(reinterpret_cast<::FUN_00622290_cls *>(&(filter))->FUN_00622290(4, (int)(((void *)(::FUN_005dbe10()))), 0))))))));
                reinterpret_cast<::fnv_0056f110::FUN_0056f110_class *>(&(info))->FUN_0056f110((::fnv_0056f110::ScriptLocalsX *)(shape));
                Body* body = new Body(&info);
                reinterpret_cast<::FUN_00c6b980_cls *>((collision))->FUN_00c6b980((::World_c6b *)(body));
                obj->Vdc(node, 1);
                Acc* accumulator = new Acc;
                reinterpret_cast<::s005468d0::Owner *>((accumulator))->FUN_005468d0(0xe);
                node->Vdc(accumulator, 1);
                S1fc actionInfo;
                new ((void *)&(actionInfo)) ::FUN_009ae0f0();
                actionInfo.m04 = ((void *)(::FUN_004ae750((void *)(body))));
                actionInfo.fa = DAT_011a5808;
                actionInfo.fb = DAT_011a5804;
                actionInfo.fc = DAT_011a5800;
                actionInfo.fd = DAT_011a57fc;
                A140* action = new A140(&actionInfo);
                reinterpret_cast<::SceneC8E *>((body))->FUN_00c8ef80((::NiObjectC8E *)(action));
            }
            if (((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
            {
                reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0();
                ::FUN_00c69f50((::S_00c69f50_Obj *)(obj), 1, 1);
                Upd update;
                new ((void *)&(update)) ::NiUpdateData(0.0f, 0, 0);
                reinterpret_cast<::FUN_00a59c60_cls *>((obj))->FUN_00a59c60((std::intptr_t)(&update));
                Obj* world = (Obj*)((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                world->Vd0(obj, 1, 1, 0, 1);
            }
        }
        if (((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
        {
            reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0();
            ::FUN_00c69f50((::S_00c69f50_Obj *)(obj), 1, 1);
            Upd update;
            new ((void *)&(update)) ::NiUpdateData(0.0f, 0, 0);
            reinterpret_cast<::FUN_00a59c60_cls *>((obj))->FUN_00a59c60((std::intptr_t)(&update));
            Obj* world = (Obj*)((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
            world->Vd0(obj, 1, 1, 0, 1);
        }
        if (obj->V0c() && ::FUN_005784b0((::NiNode *)(void *)(obj->V0c())))
            ::FUN_00578060((::NodeView *)(void *)(obj->V0c()));
        if (((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())) && ((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()))->FUN_004bae00())
        {
            Obj* world = (Obj*)((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
            world->Vd8(obj, 1);
            ::EnsureLightingProperty((::AVObjectEx *)(obj));
        }
        Ctrl* ctrl = (Ctrl*)((void *)(::fnv_0043b230::FUN_0043b230((const char *)(obj))));
        if (!ctrl)
        {
            Ctrl* node = (Ctrl*)obj->V0c();
            if (node && ((int)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0))))
                ctrl = (Ctrl*)((void *)(::fnv_0043b230::FUN_0043b230((const char *)(((Obj*)((void *)(reinterpret_cast<::NiNode *>((node))->GetAt(0))))))));
        }
        Ctrl* manager = 0;
        while (ctrl)
        {
            if (::FUN_0043b300((const ::NiRTTI *)(void *)(&(*reinterpret_cast<void * *>(&::g_011f36ac))), (::NiAVObject *)(ctrl)))
            {
                manager = ctrl;
                break;
            }
            ctrl = (Ctrl*)((void *)(::fnv_004a8a90::FUN_004a8a90((char *)(ctrl))));
        }
        Seq* sequence;
        if (manager && (sequence = (Seq*)((void *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((manager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)(::FixedStr *)(((::FixedStr *)(::FUN_005c1490()))))))) != 0)
        {
            reinterpret_cast<::NiControllerManager *>((manager))->DeactivateAllSequences(0.0f);
            reinterpret_cast<::NiControllerManager *>((manager))->ActivateControllerSequence((::NiControllerSequence *)(sequence), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            reinterpret_cast<::TaskQueueInterface *>((manager))->QueueReferenceStateTask(1);
            ::SetNegatedGlobal((void *)(sequence));
            if (reinterpret_cast<::FUN_00507e10_shell *>(this)->FUN_00507e10() < reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100())
                reinterpret_cast<::FUN_00810550_class *>(this)->FUN_00810550(reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100());
        }
        else
            ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(obj));
    }
}

#include "generated/data/fallout/ai/combat/explosion_o2_variant_od_noo2_variant.inc"
