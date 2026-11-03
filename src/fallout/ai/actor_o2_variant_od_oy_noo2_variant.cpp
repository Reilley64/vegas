
// src/fallout/ai/actor_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/actor_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/actor_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/actor.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <new>
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/B441420Owner.h"
#include "fnv/decl/B5474B0Cell.h"
#include "fnv/decl/B930700Actor.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BlendController.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/Cls.h"
#include "fnv/decl/Controller.h"
#include "fnv/decl/ControllerLocal.h"
#include "fnv/decl/Dispatch_00c89dd0.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/Dummy.h"
#include "fnv/decl/FNVAnimationController.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00418800_shell.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_0041d6d0_shell.h"
#include "fnv/decl/FUN_00421e40_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_004523c0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004893c0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_004ae700_S.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_005475b0_shell.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/FUN_005610f0_cls.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_00586260_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005a9140_shell.h"
#include "fnv/decl/FUN_005a9290_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f90c0_shell.h"
#include "fnv/decl/FUN_005f90e0_shell.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_00629670_Class.h"
#include "fnv/decl/FUN_0062d4b0.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_006e2b50_shell.h"
#include "fnv/decl/FUN_00810510_Class.h"
#include "fnv/decl/FUN_00810550_class.h"
#include "fnv/decl/FUN_00810640_class.h"
#include "fnv/decl/FUN_00810660_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/FUN_0087ea60_Class.h"
#include "fnv/decl/FUN_0087eeb0_shell.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_00891130_class.h"
#include "fnv/decl/FUN_00891150_Class.h"
#include "fnv/decl/FUN_0089f4e0_shell.h"
#include "fnv/decl/FUN_008a50f0_class.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008ae480_Class.h"
#include "fnv/decl/FUN_008ae4a0_Class.h"
#include "fnv/decl/FUN_008e5700_cls.h"
#include "fnv/decl/FUN_009314f0.h"
#include "fnv/decl/FUN_00931510_Class.h"
#include "fnv/decl/FUN_00931560_cls.h"
#include "fnv/decl/FUN_00931580_Class.h"
#include "fnv/decl/FUN_009315a0Class.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_0093a7a0_Class.h"
#include "fnv/decl/FUN_00947d80_cls.h"
#include "fnv/decl/FUN_009480c0_shell.h"
#include "fnv/decl/FUN_0094db80_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_0098adb0_shell.h"
#include "fnv/decl/FUN_009c8d60_t.h"
#include "fnv/decl/FUN_00a305e0_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00c6e0b0_Class.h"
#include "fnv/decl/FUN_00c7d900.h"
#include "fnv/decl/FUN_00c7dc40.h"
#include "fnv/decl/FUN_00cb7550_cls.h"
#include "fnv/decl/FUN_00cc58c0.h"
#include "fnv/decl/FUN_00cd9fe0_cls.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FootIKDetail__Controller.h"
#include "fnv/decl/GList.h"
#include "fnv/decl/Holder00807080.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Manager.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiObject.h"
#include "fnv/decl/Obj_930.h"
#include "fnv/decl/Owner274.h"
#include "fnv/decl/Owner623.h"
#include "fnv/decl/P09A.h"
#include "fnv/decl/P103Controller.h"
#include "fnv/decl/P3.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/Polygon.h"
#include "fnv/decl/PoseOwner.h"
#include "fnv/decl/RagdollUpdateController.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/RelationUpdater.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S0062aea0_Vector.h"
#include "fnv/decl/S008910c0_Vector.h"
#include "fnv/decl/S_00422b90.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_00c6d7a0_Obj.h"
#include "fnv/decl/S_c7a730.h"
#include "fnv/decl/ScreenSplatter.h"
#include "fnv/decl/Sky.h"
#include "fnv/decl/SoundPlaybackManager.h"
#include "fnv/decl/TESEffectShader.h"
#include "fnv/decl/TESRegionList.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/V.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/cell547__C5Cell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00451530__FUN_00451530_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_00561580__FUN_00561580_Class.h"
#include "fnv/decl/fnv_005617c0__FUN_005617c0_.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_0056f110__FUN_0056f110_class.h"
#include "fnv/decl/fnv_00571530__FUN_00571530_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_0057b520__FUN_0057b520_shell.h"
#include "fnv/decl/fnv_005ac6a0__FUN_005ac6a0.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00810610__FUN_00810610_Class.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_0087e130__Projectile.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_0088e8d0__EActor.h"
#include "fnv/decl/fnv_00895110__PickActor.h"
#include "fnv/decl/fnv_0089d5e0__FUN_0089d5e0_shell.h"
#include "fnv/decl/fnv_0089f580__ActorStub.h"
#include "fnv/decl/fnv_008a50d0__bhkCharacterController.h"
#include "fnv/decl/fnv_008a7d50__ActorHitOwner.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009314d0__FUN_009314d0_class.h"
#include "fnv/decl/fnv_00931530__Dummy629670.h"
#include "fnv/decl/fnv_00c79a50__PoseControllerLocal.h"
#include "fnv/decl/fnv_00cda340__SkeletonPoseData.h"
#include "fnv/decl/hkaPoseCDA.h"
#include "fnv/decl/hkaSkeletonMapper.h"
#include "fnv/decl/xController.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004ba000.h"
#include "fnv/symbols_004f2000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_0056e000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005a1000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00622000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_0062f000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_00891000.h"
#include "fnv/symbols_008a5000.h"
#include "fnv/symbols_008b6000.h"
#include "fnv/symbols_0094d000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00c59000.h"
#include "fnv/symbols_00c68000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6c000.h"
#include "fnv/symbols_00c74000.h"
#include "fnv/symbols_00c76000.h"
#include "fnv/symbols_00c7b000.h"
#include "fnv/symbols_00c7d000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c9b000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb9000.h"
#include "fnv/symbols_00ce4000.h"
#include "fnv/symbols_00d6b000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01084000.h"
#include "fnv/symbols_0108f000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c5000.h"
#include "fnv/symbols_01196000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01204000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "Actor.h"
struct MemoryManager
{
    void* Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct bhkRagdollController
{
    void* FUN_00c7de30(unsigned int);
};
void* __cdecl FUN_00c7fa60();
struct FUN_00c7fa70_Class
{
    void* FUN_00c7fa70(int);
};
struct FUN_00cb9900_cls
{
    void FUN_00cb9900();
};
struct FUN_00cda4b0_cls
{
    void FUN_00cda4b0();
};
struct FUN_00cda8d0_class
{
    void* FUN_00cda8d0();
};
struct StateResetPart;
struct FUN_00cdb290
{
    void* GetPlus4();
public:
    ::StateResetPart *FUN_00cdb0a0();
};
struct VObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, unsigned int);
};
struct Holder
{
    char pad[16];
    VObj* p;
};
Holder* _FUN_00c85750();
struct Outer
{
    int _0;
    unsigned short _4;
    Outer* FUN_00c7e970(unsigned int);
};
struct MyNode
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int Pred();
    char _pad0[0x18];
    MyNode* field_1c;
    char _pad1[0x80];
    MyNode** children;
    char _pad2[2];
    unsigned short count;
};
struct MyRef
{
    virtual ~MyRef();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};
struct Target;
struct Target18
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
    virtual void v55();
    virtual void v56();
    virtual void MethodE4(Target* p, NiPointer<MyRef>& sp);
};
struct Target
{
    char pad[0x18];
    Target18* field_18;
};
struct FUN_00c6ffc0_Class
{
    void FUN_00c6ffc0();
};
struct FixedStr
{
    char* h;
    FixedStr(const FixedStr& o)
    {
        if (o.h != ::DAT_0109b220)
            InterlockedIncrement((long volatile*)(o.h - 8));
        h = o.h;
    }
    ~FixedStr()
    {
        if (h != ::DAT_0109b220)
            InterlockedDecrement((long volatile*)(h - 8));
    }
};
struct Mat3
{
    float m[9];
};
struct Pt3
{
    float x, y, z;
};
struct Xform
{
    Mat3 rot;
    Pt3 trans;
    float scale;
};
struct RNode;
struct RObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual RNode* GetAsNode();
    int _4;
    FixedStr name;
    char _c[0xc];
    RObj* parent;
    char _1c[0x18];
    Xform local;
};
struct RNode
{
    char _0[0xa0];
    RObj** children;
    unsigned short _a4;
    unsigned short count;
};
struct RKey
{
    FixedStr name;
    RObj* obj;
    RKey(const FixedStr& n) : name(n)
    {}
};
struct RElem
{
    RObj* obj;
    Xform x;
};
struct RArr
{
    int _0;
    RElem* data;
};
struct RCtx;
struct NiUpdateData
{
    float m_fTime;
    bool b0;
    bool b1;
    bool b2;
    bool b3;
    bool b4;
};
class NiAVObject;
struct NiNode : NiAVObject
{
    void Update(NiUpdateData const&);
public:
    ::NiAVObject *GetAt(unsigned int);
};
struct Creature
{
};
inline unsigned char GetFlag6(unsigned short w)
{
    return (unsigned char)(w >> 6) & 1;
}
struct ThreeByThreeMatrix
{
    float m[9];
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    float m_kTranslation[3];
    float m_fScale;
    NiTransform operator*(const NiTransform&) const;
};
extern bool DAT_01267c28;
extern bool DAT_01267c34;
extern bool DAT_01267c40;
extern bool DAT_01267c4c;
extern bool DAT_01267c58;
extern bool DAT_01267c64;
struct RagScrapMarker
{
    char* p;
    unsigned int size;
    RagScrapMarker(unsigned int count)
    {
        char** top = (char**)_FUN_00c85750();
        unsigned int size = (count * 48 + 0x7f) & ~0x7fu;
        char* old = *top;
        *top = old + size;
        p = old;
    }
    ~RagScrapMarker()
    {
        *(char**)_FUN_00c85750() = p;
    }
};
struct RagNode
{
    char pad0[0x18];
    RagNode* m_pParentNode;
    char pad1c[0x34 - 0x1c];
    NiTransform m_kLocalTransform;
    NiTransform m_kWorldSpaceTransform;
    RagNode* GetParent() const
    {
        return m_pParentNode;
    }
};
struct RagInner
{
    char pad[0x1c];
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
};
struct RagMid
{
    char pad[0x2c];
    RagInner* inner;
    RagInner* GetInner() const
    {
        return inner;
    }
};
struct FUN_00c7d630_t
{
    char pad0[0x48];
    RagMid* m_48;
    char pad4c[0x58 - 0x4c];
    RagNode* m_pkNode;
    char pad5c[4];
    ThreeByThreeMatrix m_kRot;
    void FUN_00c7d630(float);
};
struct FUN_00cb0c00_class
{
};
struct VObjExt : VObj
{
    virtual void v3();
    virtual void v4(void*, unsigned int);
};
struct FUN_00c7d890_cls
{
    void* _0;
    int _4;
    unsigned int _8;
    void FUN_00c7d890();
};
void* __cdecl FUN_00ec7230(char*, char const*, unsigned int);
struct FUN_00cdb3e0_cls
{
    char pad[0x2c];
    void FUN_00cdb3e0();
};
struct S_c6a200_Info
{
    int unk00, unk04, unk08, unk0c;
};
struct S_c6a200_Ev
{
    int unk00;
    unsigned char unk04;
    int unk08;
    int unk0c;
    int unk10, unk14, unk18;
};
extern void* DAT_011afecc;
struct FlagController
{
    void FUN_00c7ba10(bool);
};
struct HkAllocator
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Deallocate(void*, int);
};
struct HkMemHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HkAllocator* allocator;
    HkAllocator* GetAllocator()
    {
        return allocator;
    }
};
HkMemHolder* GetHkMemHolder();
template <class T> inline void HkDeallocT(HkAllocator* a, T* p, int n)
{
    a->Deallocate(p, n * (int)sizeof(T));
}
struct HkElem30
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
};
template <class T> struct HkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    ~HkArray()
    {
        HkAllocator* alloc = GetHkMemHolder()->GetAllocator();
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            HkDeallocT<T>(alloc, m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct FUN_00c7c030
{
    int unk00;
    HkArray<HkElem30> arr04;
    HkArray<HkElem30> arr10;
    HkArray<int> arr1C;
    int unk28;
    HkArray<int> arr2C;
    ~FUN_00c7c030();
};
struct FreeIface
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void Free(void* p, unsigned int size);
};
struct FUN_00c7d480_cls
{
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void FUN_00c7d480();
};
struct ScopeGuard
{
    FUN_00c7d480_cls* owner;
// @fnv 0x00c7d480
    ScopeGuard(void* p) : owner((FUN_00c7d480_cls*)p)
    {}
    __forceinline ~ScopeGuard()
    {
        Holder* h = _FUN_00c85750();
        FreeIface* a = (FreeIface*)h->p;
        unsigned int flags = owner->m_08;
        owner->m_04 = 0;
        if (!(flags & 0x80000000))
        {
            a->Free(owner->m_00, (flags & 0x3fffffff) * 4);
        }
        owner->m_08 = 0x80000000;
        owner->m_00 = 0;
    }
};
void FUN_00c7d480_cls::FUN_00c7d480()
{
    ScopeGuard guard(this);
    unsigned int count = m_0c;
    bool differs = count != (unsigned int)m_00;
    if (!differs)
    {
        m_04 = 0;
    }
    *(unsigned int*)_FUN_00c85750() = count;
}
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};
struct FUN_00c7d5c0_elem
{
    int unk00;
};
struct FUN_00c7d5c0_cls
{
    FUN_00c7d5c0_elem* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void FUN_00c7d5c0();
};
struct BaseObject
{
    const char* classTable;
    unsigned int unknown04;
    unsigned int unknown08;
    BaseObject();
};
struct MiddleObject : BaseObject
{
    unsigned int initialized0c;
    MiddleObject() : initialized0c(0)
    {
        classTable = (*reinterpret_cast<const char (*)[]>(&::DAT_0108febc));
        ++(*reinterpret_cast<unsigned int *>(&::DAT_01268188));
    }
    ~MiddleObject();
};
struct FUN_00c7f9e0 : MiddleObject
{
    FUN_00c7f9e0(void* context);
};
struct BCB9810AllocTagScope
{
    int m_iSaved;

    BCB9810AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~BCB9810AllocTagScope()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};
struct BCB9810Node
{
    int unk00;
    int unk04;
    int unk08;
    BCB9810Node* m_pParentNode;
};
struct BCB9810Entry
{
    int unk00;
    int unk04;
    BCB9810Node* m_pkTreeNode;
    int unk0C;
};
class BCB9810Registry
{
  public:
    void FUN_00cb9810(void* pvOwner, BCB9810Node* pkNode);

    int unk00;
    int unk04;
    BCB9810Entry* m_pkEntryArray;
    int m_iArrayLength;
};
struct CE4360Iter
{
};
struct CE4360Context
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
    int m_iMode;
};
void __cdecl FUN_00ce4360(CE4360Context* pkContext, CE4360Iter* pkFrom, CE4360Iter* pkTo, int iValue);
struct RTTI_c9b
{
    const char* m_pcName;
    RTTI_c9b* m_pBaseRTTI;
};
class GlobalObjectO2_00a7b610;
struct S
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
    virtual void SetMode(int iMode);
    void FUN_00561690(std::intptr_t);
};
struct Cast_c9b
{
    char pad[0x10];
    S* m_10;
};
struct Ctrl_c9b
{
};
class Obj_c9b
{
  public:
    virtual void v00();
    virtual void v01();
    virtual RTTI_c9b* GetRTTI();
    char padCur[0x1c - 4];
    Ctrl_c9b* m_1c;
    char kad[0xa0 - 0x20];
    Obj_c9b** m_ppChildren;
    unsigned short m_usMax;
    unsigned short m_usElementCount;
};
__forceinline bool IsNode_c9b(Obj_c9b* pkObj)
{
    RTTI_c9b* pkRTTI = pkObj->GetRTTI();
    while (pkRTTI)
    {
        if (pkRTTI == (RTTI_c9b*)&(*reinterpret_cast<unsigned char *>(&::g_011f4428)))
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}
class FUN_00c7f970_cls
{
  public:
    virtual void vfn_0();
    virtual char* Alloc(unsigned int n);
    virtual void Free(char* p);
    virtual char* Realloc(char* p, unsigned int n);

    char* m_pData;
    void* unk;
    unsigned int m_uiSize;
    void FUN_00c7f970(unsigned int uiNew, unsigned int uiOld);
};

#include <xmmintrin.h>

struct __declspec(align(16)) ScratchVec
{
    __m128 m_vComponents;
    ScratchVec();
};

struct QueryOwner
{
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
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual int vfn_d4(ScratchVec* out);

    int FUN_00560bc0(std::intptr_t param);
};

// @fnv 0x00560bc0
int QueryOwner::FUN_00560bc0(std::intptr_t param)
{
    ScratchVec v;
    return ((int)(::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(param)), (*(const ::hkVector4 *)(vfn_d4(&v))))));
}

class NiPoint3T8
{
  public:
    NiPoint3T8();
    NiPoint3T8 operator+(const NiPoint3T8& kPt) const;
    NiPoint3T8 operator-(const NiPoint3T8& kPt) const;
    NiPoint3T8 operator*(float fScale) const;
    NiPoint3T8& operator*=(float fScale);
    float x;
    float y;
    float z;
};

class hkSimdRealT8
{
  public:
    hkSimdRealT8(float fValue);
    __m128 m_vValue;
};

class hkVector4T8
{
  public:
    hkVector4T8();
    hkVector4T8 Copy() const;
    float& operator()(int i);
    __m128 m_vComponents;
};

class ScriptVarsT8
{
  public:
};

class LocalsT8
{
  public:
};

class ScriptHostT8
{
  public:
};

class GlobalT8
{
  public:
};
extern GlobalT8 g_kTrapMultT8;

class ShapeT8;
class ObjT8
{
  public:
    const void* GetPos();
};

class HitSubT8
{
  public:
};

class HitT8
{
  public:
    int m_iUnused;
    HitSubT8 m_kSub;
};

class TrapFlagsT8
{
  public:
    TrapFlagsT8(int iValue);
    int m_iValue;
};

class BodyT8
{
  public:
    const void* GetNavMeshData();
};

class WeapT8
{
  public:
    const void* GetPos();
};

class ProjT8
{
  public:
};

class NodeT8
{
  public:
    const NiPoint3T8& GetWorldTranslate();
};

class ImpulseT8
{
  public:
    ImpulseT8();
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_aiPad[9];
    NiPoint3T8 m_kFrom;
    NiPoint3T8 m_kTo;
    __m128 m_kPad;
};

class EventT8
{
  public:
    EventT8();
    NiPoint3T8 m_kPos;
    float m_fAngleZ;
    float m_fScale;
    unsigned char m_ucType;
    unsigned char m_ucForm;
    void* m_pvTarget;
    int m_i1c;
    int m_iFirstValue;
};

class AVOwnerT8
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetActorValue(int iAV);
};

class RefT8
{
  public:
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual void r040();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual NodeT8* Get3D();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual const NiPoint3T8* GetPos();
    virtual void r07e();
    virtual void r07f();
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual void r086();
    virtual void r087();
    virtual void r088();
    virtual void r089();
    virtual void r08a();
    virtual bool IsDead(int iValue);
    virtual void r08c();
    virtual void r08d();
    virtual void r08e();
    virtual void r08f();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r09a();
    virtual void r09b();
    virtual void r09c();
    virtual void r09d();
    virtual void r09e();
    virtual void r09f();
    virtual void r0a0();
    virtual void r0a1();
    virtual void r0a2();
    virtual void r0a3();
    virtual void r0a4();
    virtual void r0a5();
    virtual void r0a6();
    virtual void r0a7();
    virtual void r0a8();
    virtual void r0a9();
    virtual void r0aa();
    virtual void r0ab();
    virtual void r0ac();
    virtual void r0ad();
    virtual void r0ae();
    virtual void r0af();
    virtual void r0b0();
    virtual void r0b1();
    virtual void r0b2();
    virtual void r0b3();
    virtual void r0b4();
    virtual void r0b5();
    virtual void r0b6();
    virtual void r0b7();
    virtual void r0b8();
    virtual void r0b9();
    virtual void r0ba();
    virtual void r0bb();
    virtual void r0bc();
    virtual void r0bd();
    virtual void r0be();
    virtual void r0bf();
    virtual void r0c0();
    virtual void r0c1();
    virtual void r0c2();
    virtual void r0c3();
    virtual void r0c4();
    virtual void r0c5();
    virtual void r0c6();
    virtual void r0c7();
    virtual void r0c8();
    virtual void r0c9();
    virtual void r0ca();
    virtual void r0cb();
    virtual void r0cc();
    virtual void r0cd();
    virtual void DamageHealth(float afDamageAmount, float fUnused, int iFlags);
    char m_acPad[0xa4 - 4];
    AVOwnerT8 m_kAVOwner;
    void FUN_00890610(HitT8* pkHit, WeapT8* pkWeap);
};

// @fnv 0x00890610
void RefT8::FUN_00890610(HitT8* pkHit, WeapT8* pkWeap)
{
    float afDamageAmount = 0.0f;
    float fPushBack = 0.0f;
    float fDeathPushBack = 0.0f;
    float fMinVelocity = 0.0f;
    bool bContinuous = false;
    float fVelocityMult = 1.0f;
    RefT8* pkAttacker = ((::RefT8 *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(pkHit->m_kSub))->FUN_0084e3a0()));
    ScriptHostT8* pkHost = ((::ScriptHostT8 *)(reinterpret_cast<::FUN_005d43c0_ *>((pkAttacker))->FUN_005d43c0()));
    ScriptVarsT8* pkVars = ((::ScriptVarsT8 *)(reinterpret_cast<::FUN_00418800_shell *>((pkHost))->FUN_00418800()));
    if (this == (*reinterpret_cast<::RefT8 * *>(&::_g_thePlayer)) && pkAttacker && pkAttacker == ((::RefT8 *)(reinterpret_cast<::FUN_0089f4e0_shell *>(((*reinterpret_cast<::RefT8 * *>(&::_g_thePlayer))))->FUN_0089f4e0())))
        return;
    if (pkVars)
    {
        LocalsT8* pkLocals = ((::LocalsT8 *)(reinterpret_cast<::FUN_00418830_shell *>((pkHost))->FUN_00418830()));
        if (pkLocals)
        {
            unsigned int uiDamage;
            if (reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((pkVars))->Method_005ac6a0("fTrapDamage", &uiDamage))
                afDamageAmount = reinterpret_cast<::FUN_005a9140_shell *>((pkLocals))->FUN_005a9140(uiDamage, (::Script *)(0));
            unsigned int uiLevelled;
            if (reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((pkVars))->Method_005ac6a0("fLevelledDamage", &uiLevelled))
                afDamageAmount += reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(this)->FUN_0087f9f0() * (float)reinterpret_cast<::FUN_005a9140_shell *>((pkLocals))->FUN_005a9140(uiLevelled, (::Script *)(0));
            unsigned int uiPushBack;
            if (reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((pkVars))->Method_005ac6a0("fTrapPushBack", &uiPushBack))
                fPushBack = reinterpret_cast<::FUN_005a9140_shell *>((pkLocals))->FUN_005a9140(uiPushBack, (::Script *)(0));
            unsigned int uiMinVelocity;
            if (reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((pkVars))->Method_005ac6a0("fTrapMinVelocity", &uiMinVelocity))
            {
                fMinVelocity = reinterpret_cast<::FUN_005a9140_shell *>((pkLocals))->FUN_005a9140(uiMinVelocity, (::Script *)(0));
                if (fMinVelocity < 0.0)
                    fMinVelocity = 0.0f;
                else
                    fMinVelocity = FUN_004a3e90(fMinVelocity);
            }
            unsigned int uiContinuous;
            if (reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((pkVars))->Method_005ac6a0("bTrapContinuous", &uiContinuous))
                bContinuous = reinterpret_cast<::FUN_005a9140_shell *>((pkLocals))->FUN_005a9140(uiContinuous, (::Script *)(0)) != 0.0;
            unsigned int uiDeathPushBack;
            if (reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((pkVars))->Method_005ac6a0("fTrapDeathPushBack", &uiDeathPushBack))
                fDeathPushBack = reinterpret_cast<::FUN_005a9140_shell *>((pkLocals))->FUN_005a9140(uiDeathPushBack, (::Script *)(0));
            else
                fDeathPushBack = fPushBack / 10.0;
        }
    }
    if (bContinuous || !reinterpret_cast<::FUN_00891150_Class *>((pkWeap))->FUN_00891150())
    {
        ProjT8* pkProj = ((::ProjT8 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
        BodyT8* pkBody = ((::BodyT8 *)(::FUN_004b59f0(((::ObjT8 *)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkHit->m_kSub))->GetName())))));
        hkVector4T8 kMotionVelocity;
        hkVector4T8 kSource;
        if (pkBody)
        {
            if (!reinterpret_cast<::FUN_00891150_Class *>((pkWeap))->FUN_00891150())
            {
                reinterpret_cast<::AlignedVector *>(&(kMotionVelocity))->FUN_004a3f10((*(const ::AlignedVector *)(((const void *)(reinterpret_cast<::TESTopicInfo *>((pkWeap))->GetAddTopicList())))));
                reinterpret_cast<::AlignedVector *>(&(kSource))->FUN_004a3f10((*(const ::AlignedVector *)(((const void *)(reinterpret_cast<::BGSCameraPath *>((pkWeap))->GetShotList())))));
            }
            else
            {
                reinterpret_cast<::AlignedVector *>(&(kMotionVelocity))->FUN_004a3f10((*(const ::AlignedVector *)(((const void *)(::FUN_00560dc0((::TESDataHandler *)(pkBody)))))));
                reinterpret_cast<::AlignedVector *>(&(kSource))->FUN_004a3f10((*(const ::AlignedVector *)(pkBody->GetNavMeshData())));
            }
            hkVector4T8 kProjVel;
            if (fMinVelocity == 0.0 || reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::hkVector4T8 &)(kMotionVelocity.Copy()))->FUN_004586d0() >= fMinVelocity)
            {
                if (pkProj)
                {
                    reinterpret_cast<::AlignedVector *>(&(kProjVel))->FUN_004a3f10((*(const ::AlignedVector *)(((const void *)(reinterpret_cast<::Holder00807080 *>((pkProj))->FUN_00807080())))));
                    reinterpret_cast<::V *>(&(kProjVel))->FUN_00961190((const ::V &)(kMotionVelocity));
                    float fMin = fMinVelocity != 0.0 ? fMinVelocity : 10.0f;
                    fVelocityMult = reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::hkVector4T8 &)(kProjVel.Copy()))->FUN_004586d0() / fMin;
                    if (fVelocityMult > 2.0)
                        fVelocityMult = 2.0f;
                }
            }
            else
            {
                afDamageAmount = 0.0f;
            }
        }
        else
        {
            if (!reinterpret_cast<::FUN_00891150_Class *>((pkWeap))->FUN_00891150())
            {
                reinterpret_cast<::AlignedVector *>(&(kSource))->FUN_004a3f10((*(const ::AlignedVector *)(((const void *)(reinterpret_cast<::BGSCameraPath *>((pkWeap))->GetShotList())))));
            }
            else
            {
                ObjT8* pkObj = ((::ObjT8 *)(reinterpret_cast<::Twin_0044ddc0 *>((((::ObjT8 *)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkHit->m_kSub))->GetName()))))->GetName()));
                reinterpret_cast<::AlignedVector *>(&(kSource))->FUN_004a3f10((*(const ::AlignedVector *)(((const void *)(reinterpret_cast<::TESTopicInfo *>((pkObj))->GetAddTopicList())))));
            }
            ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(kMotionVelocity), (const ::fnv_004a3e00::NiPoint3 &)(*GetPos()));
            reinterpret_cast<::V *>(&(kMotionVelocity))->FUN_00961190((const ::V &)(kSource));
            float& rfZ = reinterpret_cast<::bhkCharacterController *>((void *)&(const ::hkVector4T8 &)(kMotionVelocity))->GetVectorElement(2);
            rfZ += FUN_004a3e90(reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>(this)->GetActorHeight() / 2.0);
        }
        bool bWasAlive = !IsDead(0);
        TrapFlagsT8 kFlags(((int)(::FUN_0043b540((char *)(((::ObjT8 *)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkHit->m_kSub))->GetName())))))));
        if (reinterpret_cast<::FUN_0043b4d0_shell *>(&(kFlags))->FUN_0043b4d0() == 0x10)
        {
            float fResist = m_kAVOwner.GetActorValue(0x13) / 100.0;
            fResist = 1.0f - FUN_0040ebd0(fResist, 1.0f);
            afDamageAmount *= fResist;
        }
        else
        {
            float fResist = 0.0f;
            fResist = 1.0f - FUN_0040ebd0(fResist, 1.0f);
            afDamageAmount *= fResist;
        }
        if (afDamageAmount > 0.0)
        {
            if (bContinuous)
                afDamageAmount *= reinterpret_cast<::Twin_0084d030 *>(&(g_kTrapMultT8))->GetStoredFloatValue() * fVelocityMult;
            DamageHealth(afDamageAmount, 0.0f, 0);
            NiPoint3T8 kTargetCenter = Get3D()->GetWorldTranslate() + (*reinterpret_cast<::NiPoint3T8 *>((void *)&::DAT_011a9484)) * (reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>(this)->GetActorHeight() * 0.5);
            NiPoint3T8 kWorldPosition;
            ::SetNiPoint3FromHkVector4((::NiPoint3 &)(kWorldPosition), (const ::hkVector4 &)(kSource));
            if (reinterpret_cast<::FUN_0043b4d0_shell *>(&(kFlags))->FUN_0043b4d0() != 0x10)
            {
                ImpulseT8 kImpulse;
                kImpulse.m_i08 = 0;
                kImpulse.m_kFrom = kTargetCenter;
                kImpulse.m_kTo = kTargetCenter - kWorldPosition;
                kImpulse.m_i00 = 0;
                kImpulse.m_i10 = -1;
                reinterpret_cast<::fnv_0088e8d0::EActor *>(this)->FUN_0088e8d0(afDamageAmount * 2.0, (::fnv_0088e8d0::ERequest *)(::ImpulseT8 *)(&kImpulse));
                if (!bContinuous && pkBody && ((int)(reinterpret_cast<::LowProcess *>((pkWeap))->GetTarget())) != 0x24)
                {
                    NiPoint3T8 kPos = (*(::NiPoint3T8 *)&(::SetNiPoint3FromHkVector4((::NiPoint3 &)(kPos), (const ::hkVector4 &)(kSource))));
                    int iOffset = ((int)(::FUN_004b5a80(pkBody)));
                    EventT8 kEvent;
                    kEvent.m_fScale = 0.5f;
                    kEvent.m_i1c = 0;
                    kEvent.m_iFirstValue = iOffset;
                    kEvent.m_ucType = 0x24;
                    kEvent.m_ucForm = ((int)(reinterpret_cast<::LowProcess *>((pkWeap))->GetTarget()));
                    kEvent.m_kPos = kPos;
                    kEvent.m_fAngleZ = reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::hkVector4T8 &)((*(::hkVector4T8 *)(::FUN_00891060((::Vec4Dst *)&(const ::hkVector4T8 &)(kMotionVelocity.Copy()), (::Vec4Src *)&(const ::hkSimdRealT8 &)(hkSimdRealT8(3.0f)), {})))))->FUN_004586d0();
                    kEvent.m_pvTarget = (char*)this + iOffset;
                    ::ImpactSound::FUN_00837550((::ImpactSound::ImpactData *)(::EventT8 *)(&kEvent));
                }
            }
            reinterpret_cast<::fnv_008a7d50::ActorHitOwner *>(this)->FUN_008a7d50(1, 1);
            bool bKilled = bWasAlive && IsDead(0);
            if (fPushBack > 0.0)
            {
                if (fDeathPushBack > ::DAT_010179e0)
                    fDeathPushBack = 200.0f;
                if (bKilled && this != (*reinterpret_cast<::RefT8 * *>(&::_g_thePlayer)))
                {
                    ::FUN_00c6a350((::NiAVObject *)(void *)(Get3D()), 1, 1, 0, 1);
                    ::FUN_00cb9650((::FUN_00cb9650_Object *)(void *)(Get3D()));
                    reinterpret_cast<::S0062aea0_Vector *>(&(kMotionVelocity))->FUN_0062aea0();
                    hkSimdRealT8 kScale(1024.0f);
                    reinterpret_cast<::S008910c0_Vector *>(&(kSource))->FUN_008910c0((const ::S008910c0_Vector *)&(kScale), (const ::S008910c0_Vector *)&(kMotionVelocity));
                    ::SetCollisionScale((::SceneNode *)(void *)(Get3D()), (unsigned int)(&kSource), fDeathPushBack, (::MaterialSelector *)(0));
                }
                else if (pkProj)
                {
                    if (fPushBack > 1000.0)
                        fPushBack = 1000.0f;
                    if (bContinuous)
                        fPushBack *= reinterpret_cast<::Twin_0084d030 *>(&(g_kTrapMultT8))->GetStoredFloatValue() * fVelocityMult;
                    ObjT8* pkObj = ((::ObjT8 *)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkHit->m_kSub))->GetName()));
                    if (pkObj)
                    {
                        NiPoint3T8 kImpulse;
                        ::SetNiPoint3FromHkVector4((::NiPoint3 &)(kImpulse), (const ::hkVector4 &)(kMotionVelocity));
                        reinterpret_cast<::FUN_004a0c10_s *>(&(kImpulse))->FUN_004a0c10();
                        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3T8 &)(kImpulse))->FUN_00439180(fPushBack);
                        reinterpret_cast<::Owner274 *>((pkProj))->UpdateMaxVelocity((const float *)&(kImpulse), 0.5f);
                    }
                }
            }
            if (pkVars)
            {
                LocalsT8* pkLocals = ((::LocalsT8 *)(reinterpret_cast<::FUN_00418830_shell *>((pkHost))->FUN_00418830()));
                if (pkLocals)
                {
                    unsigned int uiHasHit;
                    if (reinterpret_cast<::fnv_005ac6a0::FUN_005ac6a0 *>((pkVars))->Method_005ac6a0("bTrapHasHit", &uiHasHit))
                        reinterpret_cast<::FUN_005a9290_shell *>((pkLocals))->SetScriptVariable(uiHasHit, 1.0);
                }
            }
        }
        reinterpret_cast<::FUN_00891130_class *>((pkWeap))->FUN_00891130(1);
    }
}

struct ImpactPoint
{
    float x, y, z;
    ImpactPoint();
    ImpactPoint operator-(const ImpactPoint&) const;
    ImpactPoint operator*(float) const;
};
// FUN_008a4af0 v04 - pack types used directly; shells only for callees the pack does not declare
struct GhostH
{
};
struct SettingString
{
};
struct GetterObj
{
};
struct NormObj
{
    void FUN_004a0c10();
};
struct NodeObj
{
    struct Pair;
    Pair FUN_00461130(int arg);
};
struct NodeObj::Pair
{
    float x, y, z;
    ImpactPoint* FUN_00524c40();
};
struct ParamObj
{
    virtual void z000();
    virtual void z001();
    virtual void z002();
    virtual void z003();
    virtual void z004();
    virtual void z005();
    virtual void z006();
    virtual void z007();
    virtual void z008();
    virtual void z009();
    virtual void z010();
    virtual void z011();
    virtual void z012();
    virtual void z013();
    virtual void z014();
    virtual void z015();
    virtual void z016();
    virtual void z017();
    virtual void z018();
    virtual void z019();
    virtual void z020();
    virtual void z021();
    virtual void z022();
    virtual void z023();
    virtual void z024();
    virtual void z025();
    virtual void z026();
    virtual void z027();
    virtual void z028();
    virtual void z029();
    virtual void z030();
    virtual void z031();
    virtual void z032();
    virtual void z033();
    virtual void z034();
    virtual void z035();
    virtual void z036();
    virtual void z037();
    virtual void z038();
    virtual void z039();
    virtual void z040();
    virtual void z041();
    virtual void z042();
    virtual void z043();
    virtual void z044();
    virtual void z045();
    virtual void z046();
    virtual void z047();
    virtual void z048();
    virtual void z049();
    virtual void z050();
    virtual void z051();
    virtual void z052();
    virtual void z053();
    virtual void z054();
    virtual void z055();
    virtual void z056();
    virtual void z057();
    virtual void z058();
    virtual void z059();
    virtual void z060();
    virtual void z061();
    virtual void z062();
    virtual void z063();
    virtual void z064();
    virtual void z065();
    virtual void z066();
    virtual void z067();
    virtual void z068();
    virtual void z069();
    virtual void z070();
    virtual void z071();
    virtual void z072();
    virtual void z073();
    virtual void z074();
    virtual void z075();
    virtual void z076();
    virtual void z077();
    virtual void z078();
    virtual void z079();
    virtual void z080();
    virtual void z081();
    virtual void z082();
    virtual void z083();
    virtual void z084();
    virtual void z085();
    virtual void z086();
    virtual void z087();
    virtual void z088();
    virtual void z089();
    virtual void z090();
    virtual void z091();
    virtual void z092();
    virtual void z093();
    virtual void z094();
    virtual void z095();
    virtual void z096();
    virtual void z097();
    virtual void z098();
    virtual void z099();
    virtual void z100();
    virtual void z101();
    virtual void z102();
    virtual void z103();
    virtual void z104();
    virtual void z105();
    virtual void z106();
    virtual void z107();
    virtual void z108();
    virtual void z109();
    virtual void z110();
    virtual void z111();
    virtual void z112();
    virtual void z113();
    virtual void z114();
    virtual void z115();
    virtual void* GetNode116();
    virtual void q117();
    virtual void q118();
    virtual void q119();
    virtual void q120();
    virtual void q121();
    virtual void q122();
    virtual void q123();
    virtual void q124();
    virtual void q125();
    virtual void q126();
    virtual void q127();
    virtual void q128();
    virtual void q129();
    virtual void q130();
    virtual void q131();
    virtual void q132();
    virtual void q133();
    virtual void q134();
    virtual void q135();
    virtual void q136();
    virtual void q137();
    virtual void q138();
    virtual void q139();
    virtual void q140();
    virtual void q141();
    virtual void q142();
    virtual void q143();
    virtual void q144();
    virtual void q145();
    virtual void q146();
    virtual void q147();
    virtual void q148();
    virtual void q149();
    virtual void q150();
    virtual void q151();
    virtual void q152();
    virtual void q153();
    virtual void q154();
    virtual void q155();
    virtual void q156();
    virtual void q157();
    virtual void q158();
    virtual void q159();
    virtual void q160();
    virtual void q161();
    virtual void q162();
    virtual void q163();
    virtual void q164();
    virtual void q165();
    virtual void q166();
    virtual void q167();
    virtual void q168();
    virtual void q169();
    virtual void q170();
    virtual void q171();
    virtual void q172();
    virtual void q173();
    virtual void q174();
    virtual void q175();
    virtual void q176();
    virtual void q177();
    virtual void q178();
    virtual void q179();
    virtual void q180();
    virtual void q181();
    virtual void q182();
    virtual void q183();
    virtual void q184();
    virtual void q185();
    virtual void q186();
    virtual void q187();
    virtual void q188();
    virtual void q189();
    virtual void q190();
    virtual void q191();
    virtual void q192();
    virtual void q193();
    virtual void q194();
    virtual void q195();
    virtual void q196();
    virtual void q197();
    virtual void q198();
    virtual void q199();
    virtual void q200();
    virtual void q201();
    virtual void q202();
    virtual void q203();
    virtual void q204();
    virtual void q205();
    virtual void q206();
    virtual void q207();
    virtual void q208();
    virtual void q209();
    virtual void q210();
    virtual void q211();
    virtual void q212();
    virtual void q213();
    virtual void q214();
    virtual void q215();
    virtual bool IsSpecial();
};
struct SubObjSrc
{
};
struct Sub410
{
};
struct GlobalCount
{
};

struct __declspec(align(16)) ImpactVector
{
    __m128 value;
    ImpactVector();
};
struct ImpactQuery
{
    float x, y, z, radius;
    ImpactQuery();
};
struct ImpactColor
{
    float r, g, b, a;
    ImpactColor(float, float, float, float);
};
struct ImpactEffect
{
};
struct ImpactEffectManager
{
    void Add(ImpactEffect*, float);
};
struct HitObject
{
    void* GetIdentity();
};
struct HitIdentity
{
};
struct HitQueryResult
{
    void* GetIdentity();
};
struct HitName
{
    char const* GetName();
};
struct HitPart
{
};
struct ImpactNode
{
};
struct HostShell : Actor
{
    void FUN_008a4af0(ParamObj* source, float strength, float secondary, int start, int end);
};
// @fnv 0x008a4af0
void HostShell::FUN_008a4af0(ParamObj* source, float strength, float secondary, int start, int end)
{
    void* scene = ((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((((ImpactNode*)this)))->FUN_0043fcd0()));
    if (reinterpret_cast<::FUN_008ace90_shell *>((((ImpactNode*)this)))->FUN_008ace90())
        return;
    void* manager = FUN_004aae30((NiAVObject*)scene, (NiFixedString*)((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::SettingString *>(&::g_011cc83c))))->IsDLCAvailable())));
    ImpactPoint origin;
    ImpactPoint target;
    NodeObj* node = (NodeObj*)source->GetNode116();
    if (node)
    {
        origin = *node->FUN_00461130(start).FUN_00524c40();
        target = *node->FUN_00461130(end).FUN_00524c40();
    }
    ImpactPoint direction;
    direction = target - origin;
    reinterpret_cast<::FUN_004a0c10_s *>(&(direction))->FUN_004a0c10();
    int part = 0;
    if (manager)
    {
        if (strength > 100.0)
            strength = 100.0f;
        float difference = reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GetterObj *>(&::g_011cc77c))))->FUN_00450410() - reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GetterObj *>(&::g_011cc86c))))->FUN_00450410();
        float primary = difference * strength * 0.009999999776482582 + reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GetterObj *>(&::g_011cc86c))))->FUN_00450410();
        difference = reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GetterObj *>(&::g_011cc860))))->FUN_00450410() - reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GetterObj *>(&::g_011cc7dc))))->FUN_00450410();
        float amount = difference * secondary + reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GetterObj *>(&::g_011cc7dc))))->FUN_00450410();
        if (secondary > 75.0)
            primary = 0.0f;
        if (primary != 0.0 || amount != 0.0)
        {
            bool enabled = true;
            if (this == (*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))
                enabled = reinterpret_cast<::FUN_004eaf60_shell *>((((ImpactNode*)this)))->FUN_004eaf60();
            if (!Unk_8C() && enabled)
            {
                bool special = false;
                void* sub = ((void *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((((SubObjSrc*)this)))->FUN_009306d0()));
                if (sub)
                    special = ::FUN_008a5170((const ::_Dummy_008a5170 *)(((Sub410*)((char*)sub + 0x410))));
                ::FUN_00c9b250((::SceneObject *)(manager), 0.0f, special);
            }
            if (primary != 0.0)
            {
                ImpactPoint impulse = direction * primary;
                if (reinterpret_cast<::TESObjectCELL *>(&((*reinterpret_cast<::GlobalCount *>(&::g_011df838))))->GetCellStandValue() > 0)
                {
                    ImpactColor color(0.0f, 0.0f, 0.0f, 0.0f);
                    if (source->IsSpecial())
                        color = ImpactColor(0.0f, 0.0f, 1.0f, 1.0f);
                    else
                        color = ImpactColor(1.0f, 0.0f, 0.0f, 1.0f);
                    ImpactEffect* effect = ((::ImpactEffect *)(::FUN_00c59a50((const ::ArrowPoint &)((const ::ImpactPoint &)(impulse * 0.1f)), (const ::ArrowColor *)&(color))));
                    reinterpret_cast<::FUN_00440460_S *>((effect))->FUN_00440460((const ::V3 *)&(target));
                    reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::ImpactEffectManager * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(effect), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GetterObj *>(&::g_011df754))))->FUN_00450410());
                }
                if (enabled)
                {
                    ImpactVector worldImpulse;
                    ::CopyCharacterControllerVector((::bhkCharacterController *)(::ImpactVector *)(&worldImpulse), (*(const ::NiPoint3 *)(&impulse)));
                    ImpactQuery query;
                    __declspec(align(16)) ImpactPoint position;
                    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&position)), (*(const ::fnv_004a3e00::NiPoint3 *)(&target)));
                    reinterpret_cast<::FUN_008a50f0_class *>(&(query))->FUN_008a50f0((int)&(position));
                    reinterpret_cast<::fnv_008a50d0::bhkCharacterController *>(&(query))->FUN_008a50d0(30.0f);
                    HitQueryResult* result = ((::HitQueryResult *)(::FUN_00c806b0(scene, &query, 0)));
                    if (result)
                    {
                        HitIdentity* identity = ((::HitIdentity *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(void *)(((void *)(::FUN_004ae750((void *)(result))))))));
                        if (identity)
                            part = ((int)(reinterpret_cast<::Twin_0044ddc0 *>((identity))->GetName()));
                    }
                    if (!part)
                        part = (int)FUN_004aae30((NiAVObject*)scene,
                                                 (NiFixedString*)((const char *)(reinterpret_cast<::DownloadableContentManager *>((((SettingString*)&(*reinterpret_cast<::SettingString *>(&::g_011cc8cc)))))->IsDLCAvailable())));
                    if (part)
                    {
                        const char* name = ((::HitName *)(reinterpret_cast<::TESTopicInfoData *>((((HitPart*)part)))->GetLinkToList()))->GetName();
                        ::FUN_0040fbe0();
                    }
                    ::FUN_00cb9320((::NiAVObject *)(manager), &worldImpulse, (::NiAVObject *)(part));
                }
            }
            if (amount != 0.0 && enabled)
            {
                direction.x = (float)(direction.x + 1.0);
                direction.y = (float)(direction.y + 1.0);
                reinterpret_cast<::FUN_004a0c10_s *>(&(direction))->FUN_004a0c10();
                ImpactPoint impulse = direction * primary;
                ImpactVector worldImpulse;
                ::CopyCharacterControllerVector((::bhkCharacterController *)(::ImpactVector *)(&worldImpulse), (*(const ::NiPoint3 *)(&impulse)));
                part = ((int)(reinterpret_cast<::fnv_00571530::FUN_00571530_shell *>((((ImpactNode*)this)))->FUN_00571530((::fnv_00571530::NiAVObject *)(scene), (::fnv_00571530::NiFixedString *)(((int)(::FUN_008a5190()))))));
                ::FUN_00cb9320((::NiAVObject *)(manager), &worldImpulse, (::NiAVObject *)(part));
            }
        }
    }
}

struct VectorXYZ
{
    __m128 vector;
    void FUN_008a5110(const __m128*);
};
// @fnv 0x008a5110
void VectorXYZ::FUN_008a5110(const __m128* source)
{

    vector = _mm_shuffle_ps(*source, _mm_unpackhi_ps(*source, vector), 0xc4);
}

class NiPoint3H
{
  public:
    float x, y, z;
    NiPoint3H operator-(const NiPoint3H& kPt) const;
    NiPoint3H& operator*=(float fScalar);
    NiPoint3H& operator+=(const NiPoint3H& kPt);
};

class NiMatrix3H
{
  public:
};

class hkVector4H
{
  public:
    hkVector4H();
    __m128 m_vComponents;
};

class TargetInfoH
{
  public:
    TargetInfoH(float fValue, int a, int b);
    float m_f00;
    int m_i04;
    int m_i08;
};

class BSFixedStringH
{
  public:
    const char* m_pcString;
    int m_iReferenceCount;
    int m_iHash;
};

class NiNodeRefH
{
  public:
    NiPoint3H& GetWorldTranslate();
    void* m_pkNode;
    int m_iIndex;
    int m_iFlags;
};

class NiNodeH
{
  public:
    NiNodeRefH GetObjectByName(const BSFixedStringH& kName);
};

class ProcessH
{
  public:
    virtual void vp000();
    virtual void vp004();
    virtual void vp008();
    virtual void vp00c();
    virtual void vp010();
    virtual void vp014();
    virtual void vp018();
    virtual void vp01c();
    virtual void vp020();
    virtual void vp024();
    virtual void vp028();
    virtual void vp02c();
    virtual void vp030();
    virtual void vp034();
    virtual void vp038();
    virtual void vp03c();
    virtual void vp040();
    virtual void vp044();
    virtual void vp048();
    virtual void vp04c();
    virtual void vp050();
    virtual void vp054();
    virtual void vp058();
    virtual void vp05c();
    virtual void vp060();
    virtual void vp064();
    virtual void vp068();
    virtual void vp06c();
    virtual void vp070();
    virtual void vp074();
    virtual void vp078();
    virtual void vp07c();
    virtual void vp080();
    virtual void vp084();
    virtual void vp088();
    virtual void vp08c();
    virtual void vp090();
    virtual void vp094();
    virtual void vp098();
    virtual void vp09c();
    virtual void vp0a0();
    virtual void vp0a4();
    virtual void vp0a8();
    virtual void vp0ac();
    virtual void vp0b0();
    virtual void vp0b4();
    virtual void vp0b8();
    virtual void vp0bc();
    virtual void vp0c0();
    virtual void vp0c4();
    virtual void vp0c8();
    virtual void vp0cc();
    virtual void vp0d0();
    virtual void vp0d4();
    virtual void vp0d8();
    virtual void vp0dc();
    virtual void vp0e0();
    virtual void vp0e4();
    virtual void vp0e8();
    virtual void vp0ec();
    virtual void vp0f0();
    virtual void vp0f4();
    virtual void vp0f8();
    virtual void vp0fc();
    virtual void vp100();
    virtual void vp104();
    virtual void vp108();
    virtual void vp10c();
    virtual void vp110();
    virtual void vp114();
    virtual void vp118();
    virtual void vp11c();
    virtual void vp120();
    virtual void vp124();
    virtual void vp128();
    virtual void vp12c();
    virtual void vp130();
    virtual void vp134();
    virtual void vp138();
    virtual void vp13c();
    virtual void vp140();
    virtual void vp144();
    virtual void vp148();
    virtual void vp14c();
    virtual void vp150();
    virtual void vp154();
    virtual void vp158();
    virtual void vp15c();
    virtual void vp160();
    virtual void vp164();
    virtual void vp168();
    virtual void vp16c();
    virtual void vp170();
    virtual void vp174();
    virtual void vp178();
    virtual void vp17c();
    virtual void vp180();
    virtual void vp184();
    virtual void vp188();
    virtual void vp18c();
    virtual void vp190();
    virtual void vp194();
    virtual void vp198();
    virtual void vp19c();
    virtual void vp1a0();
    virtual void vp1a4();
    virtual void vp1a8();
    virtual void vp1ac();
    virtual void vp1b0();
    virtual void vp1b4();
    virtual void vp1b8();
    virtual void vp1bc();
    virtual void vp1c0();
    virtual void vp1c4();
    virtual void vp1c8();
    virtual void vp1cc();
    virtual void vp1d0();
    virtual void vp1d4();
    virtual void vp1d8();
    virtual void vp1dc();
    virtual void vp1e0();
    virtual void vp1e4();
    virtual void vp1e8();
    virtual void vp1ec();
    virtual void vp1f0();
    virtual void vp1f4();
    virtual void vp1f8();
    virtual void vp1fc();
    virtual void vp200();
    virtual void vp204();
    virtual void vp208();
    virtual void vp20c();
    virtual void vp210();
    virtual void vp214();
    virtual void vp218();
    virtual void vp21c();
    virtual void vp220();
    virtual void vp224();
    virtual void vp228();
    virtual void vp22c();
    virtual void vp230();
    virtual void vp234();
    virtual void vp238();
    virtual void vp23c();
    virtual void vp240();
    virtual void vp244();
    virtual void vp248();
    virtual void vp24c();
    virtual void vp250();
    virtual void vp254();
    virtual void vp258();
    virtual void vp25c();
    virtual void vp260();
    virtual void vp264();
    virtual void vp268();
    virtual void vp26c();
    virtual void vp270();
    virtual void vp274();
    virtual void vp278();
    virtual void vp27c();
    virtual void vp280();
    virtual void vp284();
    virtual void vp288();
    virtual void vp28c();
    virtual void vp290();
    virtual void vp294();
    virtual void vp298();
    virtual void vp29c();
    virtual void vp2a0();
    virtual void vp2a4();
    virtual void vp2a8();
    virtual void vp2ac();
    virtual void vp2b0();
    virtual void vp2b4();
    virtual void vp2b8();
    virtual void vp2bc();
    virtual void vp2c0();
    virtual void vp2c4();
    virtual void vp2c8();
    virtual void vp2cc();
    virtual void vp2d0();
    virtual void vp2d4();
    virtual void vp2d8();
    virtual void vp2dc();
    virtual void vp2e0();
    virtual void vp2e4();
    virtual void vp2e8();
    virtual void vp2ec();
    virtual void vp2f0();
    virtual void vp2f4();
    virtual void vp2f8();
    virtual void vp2fc();
    virtual void vp300();
    virtual void vp304();
    virtual void vp308();
    virtual void vp30c();
    virtual void vp310();
    virtual void vp314();
    virtual void vp318();
    virtual void vp31c();
    virtual void vp320();
    virtual void vp324();
    virtual void vp328();
    virtual void vp32c();
    virtual void vp330();
    virtual void vp334();
    virtual void vp338();
    virtual void vp33c();
    virtual void vp340();
    virtual void vp344();
    virtual void vp348();
    virtual void vp34c();
    virtual void vp350();
    virtual void vp354();
    virtual void vp358();
    virtual void vp35c();
    virtual void vp360();
    virtual void vp364();
    virtual void vp368();
    virtual void vp36c();
    virtual void vp370();
    virtual void vp374();
    virtual void vp378();
    virtual void vp37c();
    virtual void vp380();
    virtual void vp384();
    virtual void vp388();
    virtual void vp38c();
    virtual void vp390();
    virtual void vp394();
    virtual void vp398();
    virtual void vp39c();
    virtual void vp3a0();
    virtual void vp3a4();
    virtual void vp3a8();
    virtual void vp3ac();
    virtual void vp3b0();
    virtual void vp3b4();
    virtual void vp3b8();
    virtual void vp3bc();
    virtual void vp3c0();
    virtual void vp3c4();
    virtual void vp3c8();
    virtual void vp3cc();
    virtual void vp3d0();
    virtual void vp3d4();
    virtual void vp3d8();
    virtual void vp3dc();
    virtual void vp3e0();
    virtual void vp3e4();
    virtual void vp3e8();
    virtual void vp3ec();
    virtual void vp3f0();
    virtual void vp3f4();
    virtual void vp3f8();
    virtual void vp3fc();
    virtual void vp400();
    virtual void vp404();
    virtual void vp408();
    virtual void vp40c();
    virtual void vp410();
    virtual void vp414();
    virtual void vp418();
    virtual void vp41c();
    virtual void vp420();
    virtual void vp424();
    virtual void vp428();
    virtual void vp42c();
    virtual void vp430();
    virtual void vp434();
    virtual void vp438();
    virtual void vp43c();
    virtual void vp440();
    virtual void vp444();
    virtual void vp448();
    virtual void vp44c();
    virtual void vp450();
    virtual void vp454();
    virtual void vp458();
    virtual void vp45c();
    virtual const BSFixedStringH& GetWeaponNodeName();
};

class WeaponH
{
  public:
};

class HavokObjectH
{
  public:
    const NiPoint3H& GetPosition();
};

class TESObjectREFRH
{
  public:
    virtual void vr000();
    virtual void vr004();
    virtual void vr008();
    virtual void vr00c();
    virtual void vr010();
    virtual void vr014();
    virtual void vr018();
    virtual void vr01c();
    virtual void vr020();
    virtual void vr024();
    virtual void vr028();
    virtual void vr02c();
    virtual void vr030();
    virtual void vr034();
    virtual void vr038();
    virtual void vr03c();
    virtual void vr040();
    virtual void vr044();
    virtual void vr048();
    virtual void vr04c();
    virtual void vr050();
    virtual void vr054();
    virtual void vr058();
    virtual void vr05c();
    virtual void vr060();
    virtual void vr064();
    virtual void vr068();
    virtual void vr06c();
    virtual void vr070();
    virtual void vr074();
    virtual void vr078();
    virtual void vr07c();
    virtual void vr080();
    virtual void vr084();
    virtual void vr088();
    virtual void vr08c();
    virtual void vr090();
    virtual void vr094();
    virtual void vr098();
    virtual void vr09c();
    virtual void vr0a0();
    virtual void vr0a4();
    virtual void vr0a8();
    virtual void vr0ac();
    virtual void vr0b0();
    virtual void vr0b4();
    virtual void vr0b8();
    virtual void vr0bc();
    virtual void vr0c0();
    virtual void vr0c4();
    virtual void vr0c8();
    virtual void vr0cc();
    virtual void vr0d0();
    virtual void vr0d4();
    virtual void vr0d8();
    virtual void vr0dc();
    virtual void vr0e0();
    virtual void vr0e4();
    virtual void vr0e8();
    virtual void vr0ec();
    virtual void vr0f0();
    virtual void vr0f4();
    virtual void vr0f8();
    virtual void vr0fc();
    virtual void vr100();
    virtual void vr104();
    virtual void vr108();
    virtual void vr10c();
    virtual void vr110();
    virtual void vr114();
    virtual void vr118();
    virtual void vr11c();
    virtual void vr120();
    virtual void vr124();
    virtual void vr128();
    virtual void vr12c();
    virtual void vr130();
    virtual void vr134();
    virtual void vr138();
    virtual void vr13c();
    virtual void vr140();
    virtual void vr144();
    virtual void vr148();
    virtual void vr14c();
    virtual void vr150();
    virtual void vr154();
    virtual void vr158();
    virtual void vr15c();
    virtual void vr160();
    virtual void vr164();
    virtual void vr168();
    virtual void vr16c();
    virtual void vr170();
    virtual void vr174();
    virtual void vr178();
    virtual void vr17c();
    virtual void vr180();
    virtual void vr184();
    virtual void vr188();
    virtual void vr18c();
    virtual void vr190();
    virtual void vr194();
    virtual void vr198();
    virtual void vr19c();
    virtual void vr1a0();
    virtual void vr1a4();
    virtual void vr1a8();
    virtual void vr1ac();
    virtual void vr1b0();
    virtual void vr1b4();
    virtual void vr1b8();
    virtual void vr1bc();
    virtual void vr1c0();
    virtual void vr1c4();
    virtual void vr1c8();
    virtual void vr1cc();
    virtual void vr1d0();
    virtual void vr1d4();
    virtual void vr1d8();
    virtual void vr1dc();
    virtual void vr1e0();
    virtual void vr1e4();
    virtual void vr1e8();
    virtual void vr1ec();
    virtual void vr1f0();
    virtual void vr1f4();
    virtual void vr1f8();
    virtual void vr1fc();
    virtual void vr200();
    virtual void vr204();
    virtual void vr208();
    virtual void vr20c();
    virtual void vr210();
    virtual void vr214();
    virtual void vr218();
    virtual bool IsDead();
    virtual void vr220();
    virtual bool IsActor();
    virtual void vs228();
    virtual void vs22c();
    virtual void vs230();
    virtual void vs234();
    virtual void vs238();
    virtual void vs23c();
    virtual void vs240();
    virtual void vs244();
    virtual void vs248();
    virtual void vs24c();
    virtual void vs250();
    virtual void vs254();
    virtual void vs258();
    virtual void vs25c();
    virtual void vs260();
    virtual void vs264();
    virtual void vs268();
    virtual void vs26c();
    virtual void vs270();
    virtual void vs274();
    virtual void vs278();
    virtual void vs27c();
    virtual void vs280();
    virtual void vs284();
    virtual void vs288();
    virtual void vs28c();
    virtual void vs290();
    virtual void vs294();
    virtual void vs298();
    virtual void vs29c();
    virtual void vs2a0();
    virtual void vs2a4();
    virtual void vs2a8();
    virtual void vs2ac();
    virtual void vs2b0();
    virtual void vs2b4();
    virtual void vs2b8();
    virtual void vs2bc();
    virtual void vs2c0();
    virtual void vs2c4();
    virtual void vs2c8();
    virtual void vs2cc();
    virtual void vs2d0();
    virtual void vs2d4();
    virtual void vs2d8();
    virtual void vs2dc();
    virtual void vs2e0();
    virtual void vs2e4();
    virtual void vs2e8();
    virtual void vs2ec();
    virtual void vs2f0();
    virtual void vs2f4();
    virtual void vs2f8();
    virtual void vs2fc();
    virtual void vs300();
    virtual void vs304();
    virtual void vs308();
    virtual void vs30c();
    virtual void vs310();
    virtual void vs314();
    virtual void vs318();
    virtual void vs31c();
    virtual void vs320();
    virtual void vs324();
    virtual void vs328();
    virtual void vs32c();
    virtual void vs330();
    virtual void vs334();
    virtual void vs338();
    virtual void vs33c();
    virtual void vs340();
    virtual void vs344();
    virtual void vs348();
    virtual void vs34c();
    virtual void vs350();
    virtual void vs354();
    virtual void vs358();
    virtual void vs35c();
    virtual void vs360();
    virtual void vs364();
    virtual void vs368();
    virtual void vs36c();
    virtual void vs370();
    virtual void vs374();
    virtual void vs378();
    virtual void vs37c();
    virtual void vs380();
    virtual void vs384();
    virtual void vs388();
    virtual bool IsRagdollable();
};

class HitDataH
{
  public:
    int unk00;
    TESObjectREFRH* m_pkTarget;
    TESObjectREFRH* m_pkSource;
    int unk0c;
    int unk10;
    float m_fForce;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    WeaponH* m_pkWeapon;
    int unk34;
    NiPoint3H m_kHitPos;
    NiMatrix3H m_kRotationMatrix;
};


class ActorH
{
  public:
    virtual void va000();
    virtual void va004();
    virtual void va008();
    virtual void va00c();
    virtual void va010();
    virtual void va014();
    virtual void va018();
    virtual void va01c();
    virtual void va020();
    virtual void va024();
    virtual void va028();
    virtual void va02c();
    virtual void va030();
    virtual void va034();
    virtual void va038();
    virtual void va03c();
    virtual void va040();
    virtual void va044();
    virtual void va048();
    virtual void va04c();
    virtual void va050();
    virtual void va054();
    virtual void va058();
    virtual void va05c();
    virtual void va060();
    virtual void va064();
    virtual void va068();
    virtual void va06c();
    virtual void va070();
    virtual void va074();
    virtual void va078();
    virtual void va07c();
    virtual void va080();
    virtual void va084();
    virtual void va088();
    virtual void va08c();
    virtual void va090();
    virtual void va094();
    virtual void va098();
    virtual void va09c();
    virtual void va0a0();
    virtual void va0a4();
    virtual void va0a8();
    virtual void va0ac();
    virtual void va0b0();
    virtual void va0b4();
    virtual void va0b8();
    virtual void va0bc();
    virtual void va0c0();
    virtual void va0c4();
    virtual void va0c8();
    virtual void va0cc();
    virtual void va0d0();
    virtual void va0d4();
    virtual void va0d8();
    virtual void va0dc();
    virtual void va0e0();
    virtual void va0e4();
    virtual void va0e8();
    virtual void va0ec();
    virtual void va0f0();
    virtual void va0f4();
    virtual void va0f8();
    virtual void va0fc();
    virtual void va100();
    virtual void va104();
    virtual void va108();
    virtual void va10c();
    virtual void va110();
    virtual void va114();
    virtual void va118();
    virtual void va11c();
    virtual void va120();
    virtual void va124();
    virtual void va128();
    virtual void va12c();
    virtual void va130();
    virtual void va134();
    virtual void va138();
    virtual void va13c();
    virtual void va140();
    virtual void va144();
    virtual void va148();
    virtual void va14c();
    virtual void va150();
    virtual void va154();
    virtual void va158();
    virtual void va15c();
    virtual void va160();
    virtual void va164();
    virtual void va168();
    virtual void va16c();
    virtual void va170();
    virtual void va174();
    virtual void va178();
    virtual void va17c();
    virtual void va180();
    virtual void va184();
    virtual void va188();
    virtual void va18c();
    virtual void va190();
    virtual void va194();
    virtual void va198();
    virtual void va19c();
    virtual void va1a0();
    virtual void va1a4();
    virtual void va1a8();
    virtual void va1ac();
    virtual void va1b0();
    virtual void va1b4();
    virtual void va1b8();
    virtual void va1bc();
    virtual void va1c0();
    virtual void va1c4();
    virtual void va1c8();
    virtual void va1cc();
    virtual NiNodeH* Get3D();
    BSFixedStringH GetTorsoNodeName(int iFlag);

    void FUN_008ae000(HitDataH* pkHit);
};

// @fnv 0x008ae000
void ActorH::FUN_008ae000(HitDataH* pkHit)
{
    TESObjectREFRH* pkTarget = pkHit->m_pkTarget;
    float fForce = pkHit->m_fForce;
    bool bActorSource = pkHit->m_pkSource && pkHit->m_pkSource->IsActor();
    NiNodeH* pk3D = Get3D();
    NiPoint3H kFrom = (*reinterpret_cast<const ::NiPoint3H *>((void *)&::NiPoint3::ZERO));
    NiPoint3H kTo = (*reinterpret_cast<const ::NiPoint3H *>((void *)&::NiPoint3::ZERO));
    if (pk3D)
    {
        ProcessH* pkProcess = ((::ProcessH *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()));
        kFrom = pk3D->GetObjectByName(pkProcess->GetWeaponNodeName()).GetWorldTranslate();
    }
    if (pkTarget)
    {
        if (!pkTarget->IsDead() || pkTarget->IsRagdollable())
        {
            HavokObjectH* pkObject = ((::HavokObjectH *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((pkTarget))->FUN_0043fcd0()));
            if (pkObject)
            {
                NiPoint3H kWorldPosition = (*reinterpret_cast<const ::NiPoint3H *>((void *)&::NiPoint3::ZERO));
                if (bActorSource)
                {
                    kWorldPosition = (*(::NiPoint3H *)(reinterpret_cast<::P3 *>((void *)&(pkHit->m_kRotationMatrix))->FUN_004a0bd0({})));
                    reinterpret_cast<::FUN_004a0c10_s *>(&(kWorldPosition))->FUN_004a0c10();
                    reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3H &)(kWorldPosition))->FUN_00439180(2048.0f);
                    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3H &)(kWorldPosition))->FUN_0063c8a0((void *)&(pkHit->m_kHitPos));
                }
                else
                {
                    if (pk3D)
                        kTo = pk3D->GetObjectByName(GetTorsoNodeName(0)).GetWorldTranslate();
                    kWorldPosition = kFrom - kTo;
                    reinterpret_cast<::FUN_004a0c10_s *>(&(kWorldPosition))->FUN_004a0c10();
                    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3H &)(kWorldPosition))->FUN_0063c8a0((void *)&(const ::NiPoint3H &)((*(::NiPoint3H *)(reinterpret_cast<::P3 *>((void *)&(pkHit->m_kRotationMatrix))->FUN_004a0bd0({})))));
                    reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3H &)(kWorldPosition))->FUN_00439180(1024.0f);
                    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3H &)(kWorldPosition))->FUN_0063c8a0((void *)&(kFrom));
                }
                float fImpulse = RemapValueBySettings(fForce, bActorSource);
                if (pkHit->m_pkWeapon)
                {
                    fImpulse = reinterpret_cast<::FUN_008ae480_Class *>((pkHit->m_pkWeapon))->GetField1A8() * 2.5;
                    if (bActorSource && reinterpret_cast<::FUN_008ae4a0_Class *>((pkHit->m_pkWeapon))->GetField1B8() > 0.0)
                    {
                        NiPoint3H kPos = pkObject->GetPosition();
                        NiPoint3H kDelta = kPos - kFrom;
                        float fImpulseRadiusSquared = reinterpret_cast<::FUN_008ae4a0_Class *>((pkHit->m_pkWeapon))->GetField1B8();
                        fImpulseRadiusSquared = fImpulseRadiusSquared * fImpulseRadiusSquared;
                        float fDistSq = kDelta.x * kDelta.x + kDelta.y * kDelta.y;
                        if (fDistSq > fImpulseRadiusSquared)
                        {
                            if (2.0 * reinterpret_cast<::FUN_008ae4a0_Class *>((pkHit->m_pkWeapon))->GetField1B8() < fDistSq)
                            {
                                fImpulse = fImpulse * (double)0.1f;
                            }
                            else
                            {
                                float fScale = (2.0 * fImpulseRadiusSquared - fDistSq) / fImpulseRadiusSquared * (double)0.9f + (double)0.1f;
                                fScale = FUN_00404010(fScale, 0.1f);
                                fImpulse = fImpulse * fScale;
                            }
                        }
                    }
                }
                ::FUN_00cb9650((::FUN_00cb9650_Object *)(pkObject));
                ::FUN_00c6a350((::NiAVObject *)(pkObject), 1, 1, 0, 1);
                TargetInfoH kInfo(0.0f, 0, 0);
                reinterpret_cast<::FUN_00a59c60_cls *>((pkObject))->FUN_00a59c60((std::intptr_t)(&kInfo));
                hkVector4H kImpulse;
                ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&kImpulse)), (*(const ::fnv_004a3e00::NiPoint3 *)(&kWorldPosition)));
                ::SetCollisionScale((::SceneNode *)(pkObject), (unsigned int)(&kImpulse), fImpulse, (::MaterialSelector *)(pkHit));
            }
        }
    }
}

struct xP3
{
    xP3();
    float x, y, z;
    xP3 operator+(const xP3&) const;
    void FUN_004a0c10();
};
struct xMat
{
    xMat();
    float m[9];
};
xP3 xFUN_004a3760(float, const xP3&);
struct xFltSetting
{
};
struct xBoolSetting
{
    unsigned char* FUN_00408d60();
};
struct xFilter
{
    xFilter(int);
    unsigned int m_uiFilterValue;
};
struct xAllHits
{
    xAllHits();
    virtual ~xAllHits();
    int m_q[0xc9];
};
struct xHitInfo
{
    xHitInfo(const xHitInfo*);
    int m_iWordAt00[4];
    float m_10;
    int m_14[15];
    void* m_50;
    int m_54[5];
};
struct xHitList
{
};
struct xHitOwner
{
};
struct __declspec(align(16)) xPick
{
    xPick();
    void FUN_004a3f70(xFilter);
    char m_buf[0xb0];
};
struct xWorld
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
    virtual void FUN_c8(xPick*);
};

struct xCell;
struct xPlayer
{
};
struct xActor;
struct xISParam
{
    xISParam(float, float, float, float);
    float m[4];
};
struct xTES
{
};
struct xActor
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
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float FUN_2bc(int);
    xFilter FUN_00931ed0();
    float FUN_008bd830(int aiUnused, float afHeight);
};

// @fnv 0x008bd830
float xActor::FUN_008bd830(int aiUnused, float afHeight)
{
    xP3 POS = *FUN_1f4();
    POS.z = POS.z + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1072))))));
    xP3 DIR;
    xMat MAT;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(MAT))->FUN_004a0c90(FUN_2bc(0) + afHeight);
    reinterpret_cast<::FUN_00439f50_class *>(&(MAT))->FUN_00439f50(1, (::NiPoint3 *)&(DIR));
    reinterpret_cast<::FUN_004a0c10_s *>(&(DIR))->FUN_004a0c10();
    float DIST = ::DAT_01022958;
    xP3 END = POS + xFUN_004a3760(DIST, DIR);
    bool HIT = false;
    float BEST = 3.402823466e+38F;
    xPick PICK;
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(PICK))->FUN_004a3da0(&POS);
    reinterpret_cast<::FUN_004a3eb0_shell *>(&(PICK))->FUN_004a3eb0((void *)&(END));
    xFilter FILTER(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(FILTER))->FUN_004a39f0(0x23);
    reinterpret_cast<::FUN_0059ce80_shell *>(&(FILTER))->FUN_0059ce80(((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::xFilter &)(FUN_00931ed0()))->FUN_004a3a20())));
    PICK.FUN_004a3f70(FILTER);
    xAllHits HITS;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(PICK))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::xAllHits *)(&HITS));
    xWorld* WORLD = ((::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::xCell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::xPlayer * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
    WORLD->FUN_c8(&PICK);
    for (int I = 0; !HIT && I < ((int)(reinterpret_cast<::Callees *>((((::xHitList *)(::FUN_00460140((int)(((::xHitOwner *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(PICK))->FUN_008cdd90()))))))))->FUN_00726070())); I++)
    {
        xHitInfo INFO(((::xHitInfo *)(reinterpret_cast<::FUN_004a46b0_class *>((((::xHitList *)(::FUN_00460140((int)(((::xHitOwner *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(PICK))->FUN_008cdd90()))))))))->GetEntryAt(I))));
        void* OBJ = ((void *)(::FUN_004b5820((::FormLike *)(INFO.m_50))));
        xActor* ACTOR = ((::xActor *)(::FUN_0056f930((::NiAVObject *)(OBJ))));
        void* OTHER = ::FUN_004b59f0(INFO.m_50);
        if (OBJ && OTHER && ACTOR != this)
        {
            HIT = true;
            BEST = INFO.m_10 * DIST;
        }
    }
    if (*(*reinterpret_cast<::xBoolSetting *>(&::g_011df868)).FUN_00408d60())
    {
        xISParam COLOR(1.0f, 1.0f, 0.0f, 1.0f);
        void* LINE = ((void *)(::fnv_004b3890::FUN_004b3890((const class ::FUN_006815c0 &)(POS), (const ::fnv_004b3890::FUN_004a7800 &)(COLOR), (const class ::FUN_006815c0 &)((const ::xP3 &)(POS + xFUN_004a3760(BEST, DIR))), (const ::fnv_004b3890::FUN_004a7800 &)(COLOR), 1)));
        reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::xTES * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(LINE), 10.0f);
    }
    return BEST;
}

namespace fnv_008bdbd0 {
struct xP3
{
    xP3();
    float x, y, z;
    xP3 operator+(const xP3&) const;
    xP3 operator-(const xP3&) const;
    xP3* FUN_006815c0();
    void FUN_004a0c10();
};
struct xMat
{
    xMat();
    float m[9];
};
xP3 xFUN_004a3760(float, const xP3&);
struct xFltSetting
{
};
struct xBoolSetting
{
    unsigned char* FUN_00408d60();
};
struct xBound
{
    xP3* FUN_006815c0();
};
struct xAVObj
{
};
struct xFilter
{
    xFilter(int);
    unsigned int m_uiFilterValue;
};
struct __declspec(align(16)) xAllHits
{
    xAllHits();
    virtual ~xAllHits();
    int m_q[0xc7];
};
struct __declspec(align(16)) xHitInfo
{
    xHitInfo(const xHitInfo*);
    int m_iWordAt00[4];
    float m_10;
    int m_14[15];
    void* m_50;
    int m_54[3];
};
struct xHitList
{
};
struct xHitOwner
{
};
struct __declspec(align(16)) xPick
{
    xPick();
    void FUN_004a3f70(xFilter);
    char m_buf[0xb0];
};
struct xWorld
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
    virtual void FUN_c8(xPick*);
};

struct xCell;
struct xPlayer
{
};
struct xActor;
struct xISParam
{
    xISParam(float, float, float, float);
    float m[4];
};
struct xTES
{
};
struct xActor
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
    virtual bool FUN_100();
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
    virtual void v114();
    virtual void v115();
    virtual xAVObj* FUN_1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float FUN_2bc(int);
    xFilter FUN_00931ed0();
    float FUN_008bdbd0(xActor* apTarget, float afHeight);
};

// @fnv 0x008bdbd0
float xActor::FUN_008bdbd0(xActor* apTarget, float afHeight)
{
    if (!apTarget || !apTarget->FUN_1d0())
        return 0.0f;
    xP3 POS = *FUN_1f4();
    POS.z = POS.z + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_008bdbd0::xFltSetting *>(&::originalRuntimeFloatSetting1072))))));
    xP3 DIR;
    xMat MAT;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(MAT))->FUN_004a0c90(FUN_2bc(0) + afHeight);
    reinterpret_cast<::FUN_00439f50_class *>(&(MAT))->FUN_00439f50(1, (::NiPoint3 *)&(DIR));
    reinterpret_cast<::FUN_004a0c10_s *>(&(DIR))->FUN_004a0c10();
    xP3 TPOS = *((::fnv_008bdbd0::xP3 *)(new ((void *)(((::fnv_008bdbd0::xBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((apTarget->FUN_1d0()))->FUN_0043d450())))) ::Vec3()));
    bool DONE = false;
    float RESULT = 0.0f;
    for (int I = 0; !DONE && I < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_008bdbd0::xFltSetting *>(&::originalRuntimeFloatSetting1071)))))); I++)
    {
        float DIST = (I + 1) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_008bdbd0::xFltSetting *>(&::originalRuntimeFloatSetting1070))))));
        xP3 START = POS + xFUN_004a3760(DIST, DIR);
        xPick PICK;
        reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(PICK))->FUN_004a3da0(&START);
        reinterpret_cast<::FUN_004a3eb0_shell *>(&(PICK))->FUN_004a3eb0((void *)&(TPOS));
        xFilter FILTER(0);
        reinterpret_cast<::FUN_004a39f0_shell *>(&(FILTER))->FUN_004a39f0(0x23);
        reinterpret_cast<::FUN_0059ce80_shell *>(&(FILTER))->FUN_0059ce80(((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::fnv_008bdbd0::xFilter &)(FUN_00931ed0()))->FUN_004a3a20())));
        PICK.FUN_004a3f70(FILTER);
        xAllHits HITS;
        reinterpret_cast<::FUN_004a3fb0_shell *>(&(PICK))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::fnv_008bdbd0::xAllHits *)(&HITS));
        if (*(*reinterpret_cast<::fnv_008bdbd0::xBoolSetting *>(&::g_011df868)).FUN_00408d60())
        {
            xISParam COLOR(1.0f, 1.0f, 0.0f, 1.0f);
            void* LINE = ((void *)(::fnv_004b3890::FUN_004b3890((const class ::FUN_006815c0 &)(TPOS), (const ::fnv_004b3890::FUN_004a7800 &)(COLOR), (const class ::FUN_006815c0 &)(START), (const ::fnv_004b3890::FUN_004a7800 &)(COLOR), 1)));
            reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::fnv_008bdbd0::xTES * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(LINE), 10.0f);
        }
        xWorld* WORLD = ((::fnv_008bdbd0::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_008bdbd0::xCell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_008bdbd0::xPlayer * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
        WORLD->FUN_c8(&PICK);
        for (int J = 0; !DONE && J < ((int)(reinterpret_cast<::Callees *>((((::fnv_008bdbd0::xHitList *)(::FUN_00460140((int)(((::fnv_008bdbd0::xHitOwner *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(PICK))->FUN_008cdd90()))))))))->FUN_00726070())); J++)
        {
            xHitInfo INFO(((::fnv_008bdbd0::xHitInfo *)(reinterpret_cast<::FUN_004a46b0_class *>((((::fnv_008bdbd0::xHitList *)(::FUN_00460140((int)(((::fnv_008bdbd0::xHitOwner *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(PICK))->FUN_008cdd90()))))))))->GetEntryAt(J))));
            void* OBJ = ((void *)(::FUN_004b5820((::FormLike *)(INFO.m_50))));
            xActor* ACTOR = ((::fnv_008bdbd0::xActor *)(::FUN_0056f930((::NiAVObject *)(OBJ))));
            void* OTHER = ::FUN_004b59f0(INFO.m_50);
            if (OBJ && OTHER && ACTOR != apTarget)
            {
                DONE = true;
                if (INFO.m_10 > 0.8500000238418579)
                    DONE = false;
                if (ACTOR && ACTOR->FUN_100())
                {
                    float D = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_008bdbd0::xP3 &)((TPOS - START)))->ComputeMagnitude() * INFO.m_10;
                    if (D > ::DAT_010231d8)
                        DONE = false;
                }
            }
        }
        if (!DONE)
            RESULT = (I + 1) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_008bdbd0::xFltSetting *>(&::originalRuntimeFloatSetting1070))))));
    }
    return RESULT;
}
}  // namespace fnv_008bdbd0

class NiPoint3C7
{
  public:
    NiPoint3C7(float fX, float fY, float fZ);
    float x;
    float y;
    float z;
};

class NiQuaternionC7
{
  public:
    NiQuaternionC7(float fW, float fX, float fY, float fZ);
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

class NameC7
{
  public:
    NameC7(const char* pcName);
    ~NameC7();
    const char* m_pcName;
};

class ModelC7
{
  public:
};

class ClipC7
{
  public:
    unsigned int GetCount();
    void* GetAt(unsigned int uiIndex);
};

struct SlotC7
{
    unsigned char m_ucValue;
};

class AnimDataC7
{
  public:
    unsigned int GetCount();
    SlotC7* GetAt(unsigned int uiIndex);
};

class LinkC7
{
  public:
    AnimDataC7* GetAnimData();
};

class HandleC7
{
  public:
    unsigned int m_uiHandle;
};

class FlagsC7
{
  public:
    FlagsC7();
    int m_iValue;
};

class ListenerC7
{
  public:
    FlagsC7 GetFlags();
    void SetFlags(FlagsC7 kFlags);
};

class BitsC7
{
  public:
};

class ProjC7;
template <class T> class NiPointerC7
{
  public:
    NiPointerC7(T* pkObject);
    ~NiPointerC7();
    T* m_pPointer;
};

class ProcessC7
{
  public:
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p00a();
    virtual void p00b();
    virtual void p00c();
    virtual void p00d();
    virtual void p00e();
    virtual void p00f();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p01a();
    virtual void p01b();
    virtual void p01c();
    virtual void p01d();
    virtual void p01e();
    virtual void p01f();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p02a();
    virtual void p02b();
    virtual void p02c();
    virtual void p02d();
    virtual void p02e();
    virtual void p02f();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p03a();
    virtual void p03b();
    virtual void p03c();
    virtual void p03d();
    virtual void p03e();
    virtual void p03f();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p04a();
    virtual void p04b();
    virtual void p04c();
    virtual void p04d();
    virtual void p04e();
    virtual void p04f();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p05a();
    virtual void p05b();
    virtual void p05c();
    virtual void p05d();
    virtual void p05e();
    virtual void p05f();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p06a();
    virtual void p06b();
    virtual void p06c();
    virtual void p06d();
    virtual void p06e();
    virtual void p06f();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p07a();
    virtual void p07b();
    virtual void p07c();
    virtual void p07d();
    virtual void p07e();
    virtual void p07f();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p08a();
    virtual void p08b();
    virtual void p08c();
    virtual void p08d();
    virtual void p08e();
    virtual void p08f();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p09a();
    virtual void p09b();
    virtual void p09c();
    virtual void p09d();
    virtual void p09e();
    virtual void p09f();
    virtual void p0a0();
    virtual void p0a1();
    virtual void p0a2();
    virtual void p0a3();
    virtual void SetProjectile(NiPointerC7<ProjC7> spProj);
    virtual void p0a5();
    virtual void p0a6();
    virtual void p0a7();
    virtual void p0a8();
    virtual void p0a9();
    virtual void p0aa();
    virtual void p0ab();
    virtual void p0ac();
    virtual void p0ad();
    virtual void p0ae();
    virtual void p0af();
    virtual void p0b0();
    virtual void p0b1();
    virtual void p0b2();
    virtual void p0b3();
    virtual void p0b4();
    virtual void p0b5();
    virtual void p0b6();
    virtual void p0b7();
    virtual void p0b8();
    virtual void p0b9();
    virtual void p0ba();
    virtual void p0bb();
    virtual void p0bc();
    virtual void p0bd();
    virtual void p0be();
    virtual void p0bf();
    virtual void p0c0();
    virtual void p0c1();
    virtual void p0c2();
    virtual void p0c3();
    virtual void p0c4();
    virtual void p0c5();
    virtual void p0c6();
    virtual void p0c7();
    virtual void p0c8();
    virtual void p0c9();
    virtual void p0ca();
    virtual void p0cb();
    virtual void p0cc();
    virtual void p0cd();
    virtual void p0ce();
    virtual void p0cf();
    virtual void p0d0();
    virtual void p0d1();
    virtual void p0d2();
    virtual void p0d3();
    virtual void p0d4();
    virtual void p0d5();
    virtual void p0d6();
    virtual void p0d7();
    virtual void p0d8();
    virtual void p0d9();
    virtual void p0da();
    virtual void p0db();
    virtual void p0dc();
    virtual void p0dd();
    virtual void p0de();
    virtual void p0df();
    virtual void p0e0();
    virtual void p0e1();
    virtual void p0e2();
    virtual void p0e3();
    virtual void p0e4();
    virtual void p0e5();
    virtual void p0e6();
    virtual void p0e7();
    virtual void p0e8();
    virtual void p0e9();
    virtual void p0ea();
    virtual void p0eb();
    virtual void p0ec();
    virtual void p0ed();
    virtual void p0ee();
    virtual void p0ef();
    virtual void p0f0();
    virtual void p0f1();
    virtual void p0f2();
    virtual void p0f3();
    virtual void p0f4();
    virtual void p0f5();
    virtual void p0f6();
    virtual void p0f7();
    virtual void p0f8();
    virtual void p0f9();
    virtual void p0fa();
    virtual void p0fb();
    virtual void p0fc();
    virtual void p0fd();
    virtual void p0fe();
    virtual void p0ff();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p10a();
    virtual void p10b();
    virtual void p10c();
    virtual void p10d();
    virtual void p10e();
    virtual void p10f();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p11a();
    virtual void p11b();
    virtual void p11c();
    virtual void p11d();
    virtual void p11e();
    virtual void p11f();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p12a();
    virtual void p12b();
    virtual void p12c();
    virtual void p12d();
    virtual void p12e();
    virtual void p12f();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p13a();
    virtual void p13b();
    virtual void p13c();
    virtual void p13d();
    virtual void p13e();
    virtual void p13f();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p14a();
    virtual void p14b();
    virtual void p14c();
    virtual void p14d();
    virtual void p14e();
    virtual void p14f();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p15a();
    virtual void p15b();
    virtual void p15c();
    virtual void p15d();
    virtual void p15e();
    virtual void p15f();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p16a();
    virtual void p16b();
    virtual void p16c();
    virtual void p16d();
    virtual void p16e();
    virtual void p16f();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p17a();
    virtual void p17b();
    virtual void p17c();
    virtual void p17d();
    virtual void p17e();
    virtual void p17f();
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void p18a();
    virtual void p18b();
    virtual void p18c();
    virtual void p18d();
    virtual void p18e();
    virtual void p18f();
    virtual void p190();
    virtual void p191();
    virtual void p192();
    virtual void p193();
    virtual void p194();
    virtual void p195();
    virtual void p196();
    virtual void p197();
    virtual void p198();
    virtual void p199();
    virtual void p19a();
    virtual void p19b();
    virtual void p19c();
    virtual void p19d();
    virtual void p19e();
    virtual void p19f();
    virtual void p1a0();
    virtual void p1a1();
    virtual void p1a2();
    virtual void p1a3();
    virtual void p1a4();
    virtual void p1a5();
    virtual void p1a6();
    virtual void p1a7();
    virtual void p1a8();
    virtual void p1a9();
    virtual void p1aa();
    virtual void p1ab();
    virtual void p1ac();
    virtual void p1ad();
    virtual void p1ae();
    virtual void p1af();
    virtual void p1b0();
    virtual void p1b1();
    virtual void p1b2();
    virtual void p1b3();
    virtual ClipC7* GetClip(unsigned char m_ucClipIdentifier);
};

class InitC7
{
  public:
    InitC7(int iType);
    ~InitC7();
    __m128 m_akData[12];
};

class ProjC7
{
  public:
    static void* operator new(std::size_t uiSize);
    static void operator delete(void* pv);
    ProjC7(const InitC7& kInit);
    virtual void j000();
    virtual void j001();
    virtual void j002();
    virtual void j003();
    virtual void j004();
    virtual void j005();
    virtual void j006();
    virtual void j007();
    virtual void j008();
    virtual void j009();
    virtual void j00a();
    virtual void j00b();
    virtual void j00c();
    virtual void j00d();
    virtual void j00e();
    virtual void j00f();
    virtual void j010();
    virtual void j011();
    virtual void j012();
    virtual void j013();
    virtual void j014();
    virtual void j015();
    virtual void j016();
    virtual void j017();
    virtual void j018();
    virtual void j019();
    virtual void j01a();
    virtual void j01b();
    virtual void j01c();
    virtual void j01d();
    virtual void j01e();
    virtual void j01f();
    virtual void j020();
    virtual void j021();
    virtual void j022();
    virtual void j023();
    virtual void j024();
    virtual void j025();
    virtual void j026();
    virtual void j027();
    virtual void j028();
    virtual void j029();
    virtual void j02a();
    virtual void j02b();
    virtual void j02c();
    virtual void j02d();
    virtual void j02e();
    virtual void j02f();
    virtual void j030();
    virtual void j031();
    virtual void j032();
    virtual void j033();
    virtual void Reset(int iValue);
    HandleC7 GetHandle();
    char m_acPad[0x410 - 4];
    BitsC7 m_kBits;
    char m_acPad2[0x650 - 0x411];
};

class WorldC7
{
  public:
};

class CellC7
{
  public:
};

class SubC7
{
  public:
};

class OwnerC7
{
  public:
    char m_acPad[0x30];
    SubC7 m_kSub;
};

class ControllerC7
{
  public:
};

class MiddleC7
{
  public:
    void SetMode(int iMode);
};

class RagdollC7
{
  public:
};

class RefC7
{
  public:
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void* Get3D();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual void r07d();
    virtual void r07e();
    virtual void SetUpdate(int iValue);
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual void r086();
    virtual bool IsMoving();
    virtual void r088();
    virtual void r089();
    virtual void r08a();
    virtual bool IsDead(int iValue);
    virtual void r08c();
    virtual void r08d();
    virtual void r08e();
    virtual void r08f();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r09a();
    virtual void r09b();
    virtual void r09c();
    virtual void r09d();
    virtual void r09e();
    virtual void r09f();
    virtual void r0a0();
    virtual void r0a1();
    virtual void r0a2();
    virtual void r0a3();
    virtual void r0a4();
    virtual void r0a5();
    virtual void r0a6();
    virtual void r0a7();
    virtual void r0a8();
    virtual void r0a9();
    virtual void r0aa();
    virtual void r0ab();
    virtual void r0ac();
    virtual void r0ad();
    virtual void r0ae();
    virtual void r0af();
    virtual void r0b0();
    virtual void r0b1();
    virtual void r0b2();
    virtual void r0b3();
    virtual void r0b4();
    virtual void r0b5();
    virtual void r0b6();
    virtual void r0b7();
    virtual void r0b8();
    virtual float GetScaleV();
    void* GetParent();
    char m_acPad[0x68 - 4];
    ProcessC7* m_pkProcess;
    void FUN_00930c70();
};

class ActorC7 : public RefC7
{
  public:
    HandleC7 GetHandle();
    char m_acPad2[0xac - 0x6c];
    MiddleC7* m_pkMiddle;
    RagdollC7* m_pkRagdoll;
};

// @fnv 0x00930c70
void RefC7::FUN_00930c70()
{
    reinterpret_cast<::fnv_0057b520::FUN_0057b520_shell *>(this)->FUN_0057b520(0);
    if (!m_pkProcess || (((int)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pkProcess))->FUN_0045cd60())) && ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pkProcess))->FUN_0045cd60())) != 1))
        return;
    CellC7* pkCell = ((::CellC7 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    ProcessC7* pkProcess = !((int)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pkProcess))->FUN_0045cd60())) ? m_pkProcess : 0;
    if (pkCell && !::FUN_00450ff0((void *)(pkCell)) && !reinterpret_cast<::FUN_004523c0_shell *>((pkCell))->FUN_004523c0())
        return;
    WorldC7* pkWorld = pkCell ? ((::WorldC7 *)(reinterpret_cast<::FUN_004543c0_cls *>((pkCell))->FUN_004543c0())) : 0;
    ActorC7* pkActor = IsActor() ? (ActorC7*)this : 0;
    bool bCombat;
    if (pkActor)
    {
        switch (((int)(reinterpret_cast<::TESEffectShader *>((pkActor))->GetAddonModels())))
        {
        case 2:
        case 4:
            return;
        }
        bCombat = reinterpret_cast<::FUN_004f8960_shell *>((pkActor))->FUN_004f8960() == 2 || reinterpret_cast<::P09A *>((pkActor))->FUN_008aad40(-1);
        ::PropagateNameToHavokEntity((::C6C210AVObject *)(void *)(((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()))));
    }
    else
    {
        bCombat = false;
    }
    AnimDataC7* pkAnim = ((::AnimDataC7 *)(reinterpret_cast<::ExtraDataList *>((((::LinkC7 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->GetDismemberedLimbs()));
    if (pkAnim && m_pkProcess && Get3D())
    {
        unsigned int ItemUpdateArray = ::GetObjectFlags((char *)(pkAnim));
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            SlotC7* pkSlot = ((::SlotC7 *)(reinterpret_cast<::B441420Owner *>((pkAnim))->GetInfoAt(i)));
            ClipC7* pkClip = m_pkProcess->GetClip(pkSlot->m_ucValue);
            ModelC7* pkModel = ((::ModelC7 *)(reinterpret_cast<::FUN_009611e0_shell *>((pkClip))->FUN_009611e0()));
            NameC7 kName(::DAT_01196d6c[pkSlot->m_ucValue]);
            if (pkModel && ::FUN_009a3830((const int *)(const char *)(((const char *)(reinterpret_cast<::TESTopicInfoData *>((pkModel))->GetLinkToList()))), (const int *)&(kName)))
                continue;
            for (unsigned int j = 0; j < pkClip->GetCount(); j++)
            {
                void* pvItem = ((void *)(reinterpret_cast<::NiNode *>((pkClip))->GetAt(j)));
                if (pvItem)
                    ::FUN_00c6a200(pvItem, 1, 1, 1);
            }
        }
    }
    ProjC7* pkProj = ((::ProjC7 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    if (!pkProj)
    {
        InitC7 kInit(1);
        reinterpret_cast<::FUN_008ac890_shell *>(&(kInit))->SetWaterForm((::TESWaterForm *)(void *)(((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()))));
        reinterpret_cast<::FUN_00810510_Class *>(&(kInit))->FUN_00810510((*(const ::NiPoint3 *)(((void *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList())))));
        reinterpret_cast<::FUN_00857230_shell *>(&(kInit))->SetSound((::TESSound *)(0));
        reinterpret_cast<::FUN_00810550_class *>(&(kInit))->FUN_00810550(GetScaleV());
        if (pkActor && ((::ControllerC7 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) && pkActor->IsMoving())
        {
            reinterpret_cast<::FUN_009314f0 *>(&(kInit))->SetField(reinterpret_cast<::FUN_005f90c0_shell *>((((::ControllerC7 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkActor))->FUN_007af430()))))->FUN_005f90c0());
            reinterpret_cast<::FUN_006e2b50_shell *>(&(kInit))->SetCantOpenDoors(reinterpret_cast<::FUN_005f90e0_shell *>((((::ControllerC7 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pkActor))->FUN_007af430()))))->FUN_005f90e0());
            reinterpret_cast<::fnv_009314d0::FUN_009314d0_class *>(&(kInit))->FUN_009314d0(reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>(this)->FUN_00567400());
        }
        else
        {
            reinterpret_cast<::FUN_00931510_Class *>(&(kInit))->SetByteAtOffset96(1);
        }
        pkProj = new ProjC7(kInit);
        if (pkActor && ((::ControllerC7 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())))
            reinterpret_cast<::FUN_00629670_Class *>(&(pkProj->m_kBits))->FUN_00629670(0x10004000, reinterpret_cast<::fnv_0089d5e0::FUN_0089d5e0_shell *>(&(((::OwnerC7 *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))->m_kSub))->FUN_0089d5e0());
        m_pkProcess->SetProjectile(pkProj);
        reinterpret_cast<::FUN_00810640_class *>((pkProj))->FUN_00810640((int)(this));
        reinterpret_cast<::FUN_00931560_cls *>((pkProj))->FUN_00931560(reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>(this)->FUN_00567400());
        reinterpret_cast<::fnv_00810610::FUN_00810610_Class *>((pkProj))->FUN_00810610(((bool)(::FUN_00525420())));
        reinterpret_cast<::FUN_00629670_Class *>(&(pkProj->m_kBits))->FUN_00629670(0x200000, true);
        if (pkProcess)
        {
            ListenerC7* pkListener = ((::ListenerC7 *)(reinterpret_cast<::FUN_00931580_Class *>((pkProcess))->FUN_00931580()));
            if (pkListener)
            {
                FlagsC7 kFlags = pkListener->GetFlags();
                reinterpret_cast<::FUN_0059ce80_shell *>(&(kFlags))->FUN_0059ce80((unsigned int)(((void *)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::HandleC7 &)(pkProj->GetHandle()))->FUN_004a3a20()))));
                pkListener->SetFlags(kFlags);
            }
        }
    }
    if (pkWorld && reinterpret_cast<::Obj_930 *>((pkWorld))->HasEntries())
        reinterpret_cast<::fnv_00931530::Dummy629670 *>((pkProj))->FUN_00931530(1);
    if (pkActor && bCombat)
        reinterpret_cast<::Manager *>((pkActor->m_pkRagdoll))->FUN_00ca2ad0(pkActor->Get3D(), (unsigned int)(((void *)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::HandleC7 &)(pkActor->GetHandle()))->FUN_004a3a20()))));
    void* pvOld = ((void *)(reinterpret_cast<::FUN_00810660_Class *>((pkProj))->FUN_00810660()));
    void* pvTarget = ((void *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()));
    if (pvOld != pvTarget)
    {
        reinterpret_cast<::S_00c6d7a0_Obj *>((pkProj))->FUN_00c6d7a0((int)(pvTarget));
        NiQuaternionC7 kRot(0.0f, 0.0f, 0.0f, 0.0f);
        kRot.m_fVectorX = 1.0f;
        kRot.m_fVectorY = 0.0f;
        kRot.m_fVectorZ = 0.0f;
        kRot.m_fScalarPart = 0.25f;
        CellC7* pkCell2 = ((::CellC7 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
        WorldC7* pkWorld2 = pkCell2 ? ((::WorldC7 *)(reinterpret_cast<::FUN_004543c0_cls *>((pkCell2))->FUN_004543c0())) : 0;
        if (pkWorld2 && ::FUN_004bae00((const char *)(pkWorld2)))
        {
            pkProj->Reset(0);
            ::CopyBlock48(((void *)(reinterpret_cast<::FUN_00810660_Class *>((pkProj))->FUN_00810660())), (const void *)(1));
        }
        ::FUN_00c6a350((::NiAVObject *)(pvTarget), bCombat ? 1 : 4, 1, 0, 0);
        if (pkActor && !pkActor->IsDead(0))
        {
            reinterpret_cast<::fnv_0087e130::Projectile *>((pkActor))->InitRagdollController(pvTarget, 1, 1, 0);
            if (this == (*reinterpret_cast<::RefC7 * *>(&::_g_thePlayer)) && pkActor->m_pkMiddle)
            {
                reinterpret_cast<::FUN_0087ea60_Class *>((pkActor->m_pkMiddle))->FUN_0087ea60(0);
                reinterpret_cast<::FUN_009315a0Class *>((pkActor->m_pkMiddle))->SetByteAt241(1);
            }
        }
    }
    if (m_pkProcess && !((int)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pkProcess))->FUN_0045cd60())) && this != (*reinterpret_cast<::RefC7 * *>(&::_g_thePlayer)) && pkActor && ((::OwnerC7 *)(reinterpret_cast<::Actor *>((pkActor))->GetActorBase())) &&
        !reinterpret_cast<::FUN_0087eeb0_shell *>((pkActor))->FUN_0087eeb0())
    {
        ProcessC7* pkHigh = m_pkProcess;
        if (!reinterpret_cast<::FUN_008e5700_cls *>((pkHigh))->HasString())
            reinterpret_cast<::xController *>((pkHigh))->FUN_008e4e50((::xActor *)(pkActor));
    }
    SetUpdate(0);
    if (bCombat && !((void *)(reinterpret_cast<::S_00422b90 *>((((::LinkC7 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00422b90())) && !((void *)(reinterpret_cast<::FUN_0041d6d0_shell *>((((::LinkC7 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041d6d0())))
    {
        NiPoint3C7 kWorldPosition(0.0f, 0.0f, -1.0f);
        ::FUN_0062b8d0(pvTarget, (const void *)&(kWorldPosition), 1);
    }
}

namespace fnv_0094cae0 {
struct kRef;
struct kShape;
struct kActor;

template <class T> struct kNodeT
{
    T** Get();
    kNodeT* Next();
    void FUN_00470470();
    bool FUN_008256d0();
};

struct kP3
{
    float x, y, z;
    kP3();
};

struct kP4
{
    __m128 v;
    kP4();
};

struct kP2
{
    float x, y;
    kP2(float a, float b);
    kP2(kP3* p);
};

struct kE
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual int v2c();
    virtual int v30();
};

struct kExt
{
};

struct kRef
{
};

struct kShape
{
    bool FUN_008256d0();
};

struct kRefList
{
    int unk0;
    kNodeT<kRef> head;
};

struct kPA2
{
};
struct kPA
{
};
struct kU2
{
};
struct kU
{
    kU2* FUN_00547680();
};
struct kCell
{
};
struct kProc
{
};

struct kActor
{
    kU2* FUN_00547680();
};

struct kQ2
{
};

struct kZ
{
    int unk0, unk4, unk8, unkC, unk10;
    kZ();
};

struct __declspec(align(16)) kH
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
    kH();
    ~kH();
    void FUN_0056f0f0(int f);
};

struct kW
{
    int unk0, unk4, unk8, unkC, unk10, unk14, unk18;
    kW(kH* h);
};

struct kVV
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v9c(kPA* a);
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void ve4(int a);
};
struct kVV3
{
};

struct kDec
{
    void FUN_0066b0d0(kW* w);
};

struct kG1
{
};
struct kG2
{
    unsigned char* FUN_00408d60();
};
struct kG3
{
};

struct kO
{
    virtual ~kO();
    int unk4, unk8, unkC;
    kO(int a, int b);
};

struct kTyped
{
    int FUN_00401170();
};

struct kRList
{
    bool FUN_008256d0();
    void FUN_005ae3d0(kRef** r);
};

struct kRList2
{
    kNodeT<kRef> head;
    int unk4;
    kRList2();
    ~kRList2();
    void FUN_005ae3d0(kRef** r);
    bool FUN_008256d0();
};

struct kContainer
{
    int unk0;
    kNodeT<kRef> head;
};

struct kS8
{
    int a, b;
    kS8(int v);
    kS8(const kS8& o);
    ~kS8();
};
void __cdecl FUN_00705420(kRef* r, kS8 s, int a);

struct kArea
{
    int unk00, unk04, unk08, unk0c;
    kP3 pos;
};

struct kSelf
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual kP3* v1f4();
    virtual void v1f8();
    virtual void v1fc(int a);
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool v22c(int a);
    virtual bool v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual bool v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    kRef* m760;
    kContainer m764;
    int unk76C;
    int unk770;
    kRList m774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    char m79c;
    char m79d;
    short unk79e;
    kP3 m7a0;
    kTyped* m7ac;
    kO* m7b0;
    int m7b4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    int unkC24;
    int unkC28;
    int unkC2C;
    int unkC30;
    int unkC34;
    int unkC38;
    int unkC3C;
    int unkC40;
    int unkC44;
    int unkC48;
    int unkC4C;
    int unkC50;
    int unkC54;
    int unkC58;
    int unkC5C;
    int unkC60;
    int unkC64;
    int unkC68;
    int unkC6C;
    int unkC70;
    int unkC74;
    int unkC78;
    int unkC7C;
    int unkC80;
    int unkC84;
    int unkC88;
    int unkC8C;
    int unkC90;
    int unkC94;
    int unkC98;
    int unkC9C;
    int unkCA0;
    int unkCA4;
    int unkCA8;
    int unkCAC;
    int unkCB0;
    int unkCB4;
    int unkCB8;
    int unkCBC;
    int unkCC0;
    int unkCC4;
    int unkCC8;
    int unkCCC;
    int unkCD0;
    int unkCD4;
    int unkCD8;
    int unkCDC;
    int unkCE0;
    int unkCE4;
    int unkCE8;
    int unkCEC;
    int unkCF0;
    int unkCF4;
    int unkCF8;
    int unkCFC;
    int unkD00;
    int unkD04;
    int unkD08;
    int unkD0C;
    int unkD10;
    int unkD14;
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
    int unkD40;
    int unkD44;
    int unkD48;
    int unkD4C;
    int unkD50;
    int unkD54;
    int unkD58;
    int unkD5C;
    int unkD60;
    int unkD64;
    int unkD68;
    int unkD6C;
    int unkD70;
    int unkD74;
    int unkD78;
    int unkD7C;
    int unkD80;
    int unkD84;
    int unkD88;
    int unkD8C;
    int unkD90;
    int unkD94;
    int unkD98;
    int unkD9C;
    int unkDA0;
    int unkDA4;
    int unkDA8;
    int unkDAC;
    int unkDB0;
    int unkDB4;
    int unkDB8;
    int unkDBC;
    int unkDC0;
    int unkDC4;
    int unkDC8;
    int unkDCC;
    int unkDD0;
    int unkDD4;
    int unkDD8;
    int unkDDC;
    int unkDE0;
    int unkDE4;
    int unkDE8;
    kDec mdec;

    struct X5
    {
    };
    void FUN_0094cae0(kActor* p);
};

// @fnv 0x0094cae0
void kSelf::FUN_0094cae0(kActor* p)
{
    if (p == ((::fnv_0094cae0::kActor *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())))
        return;
    if (!((bool)(::FUN_0094dba0())))
        ::FUN_0062f8f0((p && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((p))->FUN_004518e0()) ? reinterpret_cast<::FUN_005471e0_shell *>((p))->FUN_005471e0() : ::DAT_01015f5c);
    reinterpret_cast<::FUN_00421e40_shell *>((((::fnv_0094cae0::kSelf::X5 *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00421e40({});
    reinterpret_cast<::B930700Actor *>(this)->SetParentCellAndUpdateController((::B930700Cell *)(p));
    if (p)
    {
        if (!reinterpret_cast<::TESObjectCELL *>((p))->IsCellInterior())
            reinterpret_cast<::FUN_0093a7a0_Class *>(this)->FUN_0093a7a0((int)(0));
        ::FUN_005743f0();
        m7b4 = ((int)(reinterpret_cast<::B5474B0Cell *>((p))->FUN_005474b0(0)));
        kPA* pa = ((::fnv_0094cae0::kPA *)(reinterpret_cast<::FUN_004543c0_cls *>((p))->FUN_004543c0()));
        if (pa)
        {
            kPA2* pa2 = ((::fnv_0094cae0::kPA2 *)(reinterpret_cast<::FUN_0045cd60_shell *>((pa))->FUN_0045cd60()));
            reinterpret_cast<::FUN_004893c0_class *>((pa2))->FUN_004893c0(1);
        }
        v1fc(0);
        if (((::fnv_0094cae0::kActor *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::fnv_0094cae0::kPA *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_0094cae0::kActor *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())) && ((::fnv_0094cae0::kQ2 *)(::ScreenSplatter::Activate(::FUN_00622bb0(), 0))))
            reinterpret_cast<::Owner623 *>((((::fnv_0094cae0::kQ2 *)(::ScreenSplatter::Activate(::FUN_00622bb0(), 1)))))->FUN_006231a0((::NiNode623 *)(::fnv_0094cae0::kPA *)(((::fnv_0094cae0::kPA *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_0094cae0::kActor *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()))));
        if (((::fnv_0094cae0::kActor *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::fnv_0094cae0::kPA *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_0094cae0::kActor *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())) && ((::fnv_0094cae0::kQ2 *)(::ScreenSplatter::Activate(::FUN_00622ba0(), 0))))
            reinterpret_cast<::Owner623 *>((((::fnv_0094cae0::kQ2 *)(::ScreenSplatter::Activate(::FUN_00622ba0(), 1)))))->FUN_006231a0((::NiNode623 *)(::fnv_0094cae0::kPA *)(((::fnv_0094cae0::kPA *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_0094cae0::kActor *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()))));
        if (reinterpret_cast<::_FUN_00822510_Class *>(&(mdec))->operator==(0))
        {
            kZ* z = new kZ;
            ::FUN_0056ea00((::_bhkSphereShape_vtbl_helper *)(z), ::AngularDashpotApplyD4DCB0::DAT_01017d00);
            kH h;
            reinterpret_cast<::fnv_0056f110::FUN_0056f110_class *>(&(h))->FUN_0056f110((::fnv_0056f110::ScriptLocalsX *)(z));
            int flags = 0x30000;
            flags |= 0x21;
            h.FUN_0056f0f0(flags);
            mdec.FUN_0066b0d0(new kW(&h));
            reinterpret_cast<::fnv_00561580::FUN_00561580_Class *>((((::fnv_0094cae0::kVV *)(::FUN_00559450((int *)&(mdec))))))->FUN_00561580(1);
            ((::fnv_0094cae0::kVV *)(::FUN_00559450((int *)&(mdec))))->ve4(4);
            reinterpret_cast<::FUN_0094db80_shell *>((((::fnv_0094cae0::kVV3 *)(reinterpret_cast<::FUN_004ae700_S *>((((::fnv_0094cae0::kVV *)(::FUN_00559450((int *)&(mdec))))))->FUN_004ae700()))))->FUN_0094db80(9);
            kP4 q;
            kP3 r = *v1f4();
            ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&q)), (*(const ::fnv_004a3e00::NiPoint3 *)(&r)));
            reinterpret_cast<::FUN_005610f0_cls *>((((::fnv_0094cae0::kVV *)(::FUN_00559450((int *)&(mdec))))))->FUN_005610f0((int)(&r));
        }
        ((::fnv_0094cae0::kVV *)(::FUN_00559450((int *)&(mdec))))->v9c(((::fnv_0094cae0::kPA *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_0094cae0::kActor *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())));
        bool busy = ((bool)(reinterpret_cast<::FUN_00437bd0_stub *>(this)->FUN_00437bd0())) || v22c(0) || v2e8() || v230();
        bool idle = !busy && !::FUN_005a1e50((const bool *)this);
        if (idle)
            v494();
        reinterpret_cast<::RelationUpdater *>(((*reinterpret_cast<::fnv_0094cae0::kG1 * *>(&::g_modelLoader))))->UpdateRelationStates((::RelationTarget *)(0));
        reinterpret_cast<::Sky *>((((::fnv_0094cae0::kProc *)(::Sky::GetInstance()))))->SetCurrentClimate({}, {});
        ::FUN_00b4f430(((int)(reinterpret_cast<::BGSCameraPath *>((((::fnv_0094cae0::kU2 *)(reinterpret_cast<::cell547::C5Cell *>((p))->FUN_00547680()))))->GetConditions())));
        kCell* cell = ((::fnv_0094cae0::kCell *)(reinterpret_cast<::TESObjectCELL *>((p))->GetParentWorldSpace()));
        bool found = false;
        m79c = 0;
        if (m7b0)
        {
            ::FUN_005e03d0((::NiTArray_Layout *)(m7b0));
            delete m7b0;
            m7b0 = 0;
        }
        int ix = reinterpret_cast<::TESObjectCELL *>((p))->GetCellGridX();
        int iy = reinterpret_cast<::TESObjectCELL *>((p))->GetCellGridY();
        float x0 = ix << 12;
        float x1 = x0 + ::DAT_01017a10;
        float y0 = iy << 12;
        float y1 = y0 + ::DAT_01017a10;
        kP2 c0(x0, y0);
        kP2 c1(x0, y1);
        kP2 c2(x1, y0);
        kP2 c3(x1, y1);
        reinterpret_cast<::FileMatchList *>(&(m774))->RemoveAll();
        (*reinterpret_cast<::fnv_0094cae0::kE * *>(&::DAT_011dd380)) = 0;
        kRList2 list;
        kNodeT<kRef>* n = &m764 ? &m764.head : 0;
        while (n && *((::fnv_0094cae0::kRef **)(new ((void *)(n)) ::Vec3())))
        {
            kRef* x = *((::fnv_0094cae0::kRef **)(new ((void *)(n)) ::Vec3()));
            if (x)
                list.FUN_005ae3d0(&x);
            n = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kRef> *)(reinterpret_cast<::Callees *>((n))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>(&(m764.head))->RemoveAll();
        kE* best = 0;
        kRefList* rl = ((::fnv_0094cae0::kRefList *)(reinterpret_cast<::TESObjectCELL *>((p))->GetRegionList(1)));
        kRef* ref;
        for (kNodeT<kRef>* it = rl ? &rl->head : 0; it && (ref = *((::fnv_0094cae0::kRef **)(new ((void *)(it)) ::Vec3()))) != 0; it = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kRef> *)(reinterpret_cast<::Callees *>((it))->FUN_00726070())))
        {
            kP2 pos(&((::fnv_0094cae0::kArea *)(reinterpret_cast<::BGSCameraPath *>(this)->GetShotList()))->pos);
            kNodeT<kRef>* sub = 0;
            if (reinterpret_cast<::FUN_00440d80_shell *>((ref))->FUN_00440d80() || (((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) && ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) != ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(this)->FUN_00575d70()))) ||
                !((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kShape> *)(reinterpret_cast<::BGSTerrainManager *>((ref))->GetMinLevel())) || ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kShape> *)(reinterpret_cast<::BGSTerrainManager *>((ref))->GetMinLevel()))->FUN_008256d0())
                continue;
            bool done = false;
            kShape* sh;
            for (kNodeT<kShape>* m = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kShape> *)(reinterpret_cast<::BGSTerrainManager *>((ref))->GetMinLevel())); !done && m && (sh = *((::fnv_0094cae0::kShape **)(new ((void *)(m)) ::Vec3()))) != 0; m = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kShape> *)(reinterpret_cast<::Callees *>((m))->FUN_00726070())))
            {
                if (reinterpret_cast<::Polygon *>((sh))->FUN_004f8360((::PolygonPoint *)(::fnv_0094cae0::kP2 *)(&pos)))
                {
                    reinterpret_cast<::TESRegionList *>(&(m764))->AddRegion((::TESRegion *)(ref));
                    if (reinterpret_cast<::RefList *>(&(list))->FUN_005f65d0((void **)(::fnv_0094cae0::kRef **)(&ref)))
                        reinterpret_cast<::ItemChangeListNode *>(&(list))->FUN_00905330((*(::InventoryStackRecord *const *)(&ref)));
                    kE* e = ((::fnv_0094cae0::kE *)(reinterpret_cast<::GList *>((((::fnv_0094cae0::kExt *)(reinterpret_cast<::FUN_009611e0_shell *>((ref))->FUN_009611e0()))))->FUN_004f35b0({})));
                    if (e)
                    {
                        if (reinterpret_cast<::PatrolActorPackageData *>((e))->IsPatrolling() && (!best || (best != e && ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((best))->FUN_005bb4d0())) < ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((e))->FUN_005bb4d0())))))
                        {
                            reinterpret_cast<::FileMatchList *>(&(m774))->RemoveAll();
                            best = e;
                        }
                        if (!best || best == e)
                        {
                            sub = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kRef> *)(::GetOffsetC((int)(e))));
                            while (sub && *((::fnv_0094cae0::kRef **)(new ((void *)(sub)) ::Vec3())))
                            {
                                m774.FUN_005ae3d0(((::fnv_0094cae0::kRef **)(new ((void *)(sub)) ::Vec3())));
                                sub = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kRef> *)(reinterpret_cast<::Callees *>((sub))->FUN_00726070()));
                            }
                            if (e->v30())
                                (*reinterpret_cast<::fnv_0094cae0::kE * *>(&::DAT_011dd380)) = e;
                        }
                    }
                    if (reinterpret_cast<::FUN_00549580_shell *>((ref))->FUN_00549580())
                    {
                        found = true;
                        if (reinterpret_cast<::Polygon *>((sh))->FUN_004f8360((::PolygonPoint *)(::fnv_0094cae0::kP2 *)(&c0)) && reinterpret_cast<::Polygon *>((sh))->FUN_004f8360((::PolygonPoint *)(::fnv_0094cae0::kP2 *)(&c1)) && reinterpret_cast<::Polygon *>((sh))->FUN_004f8360((::PolygonPoint *)(::fnv_0094cae0::kP2 *)(&c2)) &&
                            reinterpret_cast<::Polygon *>((sh))->FUN_004f8360((::PolygonPoint *)(::fnv_0094cae0::kP2 *)(&c3)))
                            m79c = 1;
                    }
                    if (m760)
                    {
                        kE* a = ((::fnv_0094cae0::kE *)(reinterpret_cast<::GList *>((((::fnv_0094cae0::kExt *)(reinterpret_cast<::FUN_009611e0_shell *>((m760))->FUN_009611e0()))))->FUN_004f35b0({})));
                        kE* b = ((::fnv_0094cae0::kE *)(reinterpret_cast<::GList *>((((::fnv_0094cae0::kExt *)(reinterpret_cast<::FUN_009611e0_shell *>((ref))->FUN_009611e0()))))->FUN_004f35b0({})));
                        if (b && (!a || (reinterpret_cast<::PatrolActorPackageData *>((b))->IsPatrolling() && !reinterpret_cast<::PatrolActorPackageData *>((a))->IsPatrolling()) ||
                                  (reinterpret_cast<::PatrolActorPackageData *>((b))->IsPatrolling() == reinterpret_cast<::PatrolActorPackageData *>((a))->IsPatrolling() && ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((b))->FUN_005bb4d0())) > ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a))->FUN_005bb4d0())))))
                            reinterpret_cast<::FUN_0093a7a0_Class *>(this)->FUN_0093a7a0((int)(ref));
                    }
                    else
                    {
                        reinterpret_cast<::FUN_0093a7a0_Class *>(this)->FUN_0093a7a0((int)(ref));
                    }
                    done = true;
                }
            }
            if (reinterpret_cast<::FUN_00549580_shell *>((ref))->FUN_00549580())
            {
                if (!m7b0)
                    m7b0 = new kO(1, 1);
                reinterpret_cast<::S_0060ba10 *>((m7b0))->FUN_0096a610((int)(&ref));
            }
        }
        if (*(*reinterpret_cast<::fnv_0094cae0::kG2 *>(&::g_011e08e0)).FUN_00408d60() && cell && reinterpret_cast<::FUN_00586260_shell *>((cell))->IsFlag8Set() && !reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(((*reinterpret_cast<::fnv_0094cae0::kG3 * *>(&::g_TES))))->FUN_00451530() && !found)
        {
            kTyped* t39 = 0;
            kTyped* t41 = 0;
            if (m7ac)
            {
                switch (m7ac->FUN_00401170())
                {
                case 0x39:
                    t39 = m7ac;
                    break;
                case 0x41:
                    t41 = m7ac;
                    break;
                }
            }
            if (t39 && t39 != (kTyped*)p)
                m79d = 1;
            else if (t41 && t41 != (kTyped*)((::fnv_0094cae0::kCell *)(reinterpret_cast<::TESObjectCELL *>((p))->GetParentWorldSpace())))
                m79d = 1;
            else
            {
                kP3 d = *v1f4();
                reinterpret_cast<::NiPoint3 *>(&(d))->Subtract((*(const ::NiPoint3 *)(&m7a0)));
                if (reinterpret_cast<::NiPoint3 *>(&(d))->ComputeMagnitude() > ::DAT_01016968)
                    m79d = 1;
            }
        }
        kE* e4 = m760 ? ((::fnv_0094cae0::kE *)(reinterpret_cast<::GList *>((((::fnv_0094cae0::kExt *)(reinterpret_cast<::FUN_009611e0_shell *>((m760))->FUN_009611e0()))))->FUN_004f35b0({}))) : 0;
        FUN_00705420(m760, e4 ? e4->v2c() : 0, 1);
        reinterpret_cast<::FUN_00947d80_cls *>(this)->FUN_00947d80();
        reinterpret_cast<::FUN_009480c0_shell *>(this)->FUN_009480c0();
        kNodeT<kRef>* n2 = &list.head;
        while (n2 && *((::fnv_0094cae0::kRef **)(new ((void *)(n2)) ::Vec3())))
        {
            kRef* x = *((::fnv_0094cae0::kRef **)(new ((void *)(n2)) ::Vec3()));
            if (x)
            {
                kE* e = ((::fnv_0094cae0::kE *)(reinterpret_cast<::GList *>((((::fnv_0094cae0::kExt *)(reinterpret_cast<::FUN_009611e0_shell *>((x))->FUN_009611e0()))))->FUN_004f35b0({})));
                if (e)
                {
                    kE* e2 = e;
                    reinterpret_cast<::Dummy *>((e2))->FUN_004f2480(0, 0);
                }
            }
            n2 = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kRef> *)(reinterpret_cast<::Callees *>((n2))->FUN_00726070()));
        }
        n2 = &m764 ? &m764.head : 0;
        while (n2 && *((::fnv_0094cae0::kRef **)(new ((void *)(n2)) ::Vec3())))
        {
            kRef* x = *((::fnv_0094cae0::kRef **)(new ((void *)(n2)) ::Vec3()));
            if (x)
            {
                kE* e = ((::fnv_0094cae0::kE *)(reinterpret_cast<::GList *>((((::fnv_0094cae0::kExt *)(reinterpret_cast<::FUN_009611e0_shell *>((x))->FUN_009611e0()))))->FUN_004f35b0({})));
                if (e)
                {
                    kE* e2 = e;
                    kNodeT<kRef>* k = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kRef> *)(reinterpret_cast<::TESTopicInfoData *>((e2))->GetLinkToList()));
                    while (k)
                    {
                        if (*((::fnv_0094cae0::kRef **)(new ((void *)(k)) ::Vec3())))
                        {
                            reinterpret_cast<::CellView *>((((::fnv_0094cae0::kActor *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00548230((::RefView *)(*((::fnv_0094cae0::kRef **)(new ((void *)(k)) ::Vec3()))), 0);
                            ::FUN_004f24e0((::TESSound *)(*((::fnv_0094cae0::kRef **)(new ((void *)(k)) ::Vec3()))), 1, 0);
                        }
                        k = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kRef> *)(reinterpret_cast<::Callees *>((k))->FUN_00726070()));
                    }
                }
            }
            n2 = ((::fnv_0094cae0::kNodeT< ::fnv_0094cae0::kRef> *)(reinterpret_cast<::Callees *>((n2))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>(&(list))->RemoveAll();
    }
    else
    {
        reinterpret_cast<::FileMatchList *>(&(m774))->RemoveAll();
        ::SoundPlaybackManager::ProcessPendingSounds();
    }
}
}  // namespace fnv_0094cae0

#include "generated/data/fallout/ai/actor_o2_variant_od_oy_noo2_variant.inc"
