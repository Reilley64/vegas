
// src/staging/blk_00620000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_00620000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00620000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include <new>
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BoundaryOwner.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DummyFlagsShell.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043b560_shell.h"
#include "fnv/decl/FUN_00450fd0_class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458990_Holder.h"
#include "fnv/decl/FUN_004589c0_cls.h"
#include "fnv/decl/FUN_0045c650_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0049c5d0_cls.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_004b4cf0_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00560e10_cls.h"
#include "fnv/decl/FUN_0056d300_S.h"
#include "fnv/decl/FUN_0056e120_shell.h"
#include "fnv/decl/FUN_0057b700_class.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_006205a0_Class.h"
#include "fnv/decl/FUN_006205c0_Class.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_006218d0_Class.h"
#include "fnv/decl/FUN_006218f0_Owner.h"
#include "fnv/decl/FUN_006219f0_Class.h"
#include "fnv/decl/FUN_00621b00_shell.h"
#include "fnv/decl/FUN_00621b20_Class.h"
#include "fnv/decl/FUN_00623070_Class.h"
#include "fnv/decl/FUN_006233c0.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_00626da0_Class.h"
#include "fnv/decl/FUN_006286a0_Holder.h"
#include "fnv/decl/FUN_006288a0_Class.h"
#include "fnv/decl/FUN_00628d10_cls.h"
#include "fnv/decl/FUN_00628df0_class.h"
#include "fnv/decl/FUN_00629560_Class.h"
#include "fnv/decl/FUN_006295a0_shell.h"
#include "fnv/decl/FUN_006299c0_cls.h"
#include "fnv/decl/FUN_00629a20_Class.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_00629cf0_cls.h"
#include "fnv/decl/FUN_00629d70_cls.h"
#include "fnv/decl/FUN_00629f10_Class.h"
#include "fnv/decl/FUN_0062e120_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00cb21e0_shell.h"
#include "fnv/decl/FnCls.h"
#include "fnv/decl/GridCellArray.h"
#include "fnv/decl/Hld621210.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Me.h"
#include "fnv/decl/Mover628.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiObject.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/ObjHelper.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/S00458a10_Vector.h"
#include "fnv/decl/S0062aea0_Vector.h"
#include "fnv/decl/S219c0.h"
#include "fnv/decl/S6281a0.h"
#include "fnv/decl/S_00538f40.h"
#include "fnv/decl/S_00620260_C.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/S_00629c10_Map.h"
#include "fnv/decl/ScriptLocals.h"
#include "fnv/decl/ScriptX.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/SortableArray.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/V.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaterZoneRemoval.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/bhkRigidBody_2.h"
#include "fnv/decl/bhkUnaryAction.h"
#include "fnv/decl/fnv_00437c10__FUN_00437c10.h"
#include "fnv/decl/fnv_0054cfd0__TESObjectCELL_Ext.h"
#include "fnv/decl/fnv_005617c0__FUN_005617c0_.h"
#include "fnv/decl/fnv_00622f20__FUN_00622f20_Class.h"
#include "fnv/decl/fnv_00623310__FUN_00623310_Class.h"
#include "fnv/decl/fnv_00628da0__LoadedAreaBound.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00517000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_006d9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00984000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "../../include/layout_support.h"

// Collision object initialization with two filter descriptions.
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class bhkSphereShape : public NiMemObject
{
  public:
    void* vtable;
    unsigned int references;
    void* shape;
    unsigned int flags;
    float radius;
    bhkSphereShape(float, bool);
};
struct __declspec(align(16)) CollisionTransform
{
    float xx, xy, xz, xw;
    float yx, yy, yz, yw;
    float zx, zy, zz, zw;
    float tx, ty, tz, tw;
};
struct __declspec(align(16)) CollisionInfo
{
    void* filter;
    void* shape;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c;
    CollisionTransform transform;
    CollisionInfo();
    ~CollisionInfo();
};
struct CollisionFilter
{
    unsigned int value;
    CollisionFilter(int);
};
class FUN_0056e2d0 : public NiMemObject
{
  public:
    void* vtable;
    unsigned int references;
    void* object;
    unsigned int flags, unk10, unk14;
    FUN_0056e2d0(const void*);
};
struct CollisionPointer
{
    FUN_0056e2d0* object;
    void operator=(FUN_0056e2d0*);
};
struct CollisionPair
{
    CollisionPointer first;
    CollisionPointer second;
    void FUN_00620930(float radius, unsigned int filter);
};
// @fnv 0x00620930
void CollisionPair::FUN_00620930(float radius, unsigned int filter)
{
    bhkSphereShape* sphere = new bhkSphereShape(radius, true);
    CollisionInfo firstInfo;
    CollisionInfo secondInfo;
    CollisionFilter firstFilter(0);
    CollisionFilter secondFilter(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(firstFilter))->FUN_004a39f0(35);
    reinterpret_cast<::FUN_0059ce80_shell *>(&(firstFilter))->FUN_0059ce80(filter);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(secondFilter))->FUN_004a39f0(35);
    reinterpret_cast<::FUN_0059ce80_shell *>(&(secondFilter))->FUN_0059ce80(FUN_005dbe10());
    firstInfo.filter = ((void *)(::FUN_00559450((int *)&(firstFilter))));
    firstInfo.shape = ((void *)(::FUN_004ae750((void *)(sphere))));
    reinterpret_cast<::FUN_0056e120_shell *>(&(firstInfo.transform))->FUN_0056e120();
    first = new FUN_0056e2d0(&firstInfo);
    secondInfo.filter = ((void *)(::FUN_00559450((int *)&(secondFilter))));
    secondInfo.shape = ((void *)(::FUN_004ae750((void *)(sphere))));
    reinterpret_cast<::FUN_0056e120_shell *>(&(secondInfo.transform))->FUN_0056e120();
    second = new FUN_0056e2d0(&secondInfo);
}

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    unsigned __int32 m128_u32[4];
} __m128;

struct xMemObj
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* p, unsigned int);
};
class xSphereShape : public xMemObj
{
  public:
    int m_ai[5];
    xSphereShape(float fRadius, bool b);
};
class __declspec(align(16)) xSub20
{
  public:
    float m_fVectorY, m_fVectorZ, m_fScalarPart, m_fVectorX;
};
class xCinfo
{
  public:
    unsigned int m_uiFilter;
    void* m_pShape;
    int m_aiPad[6];
    xSub20 m_kSub;
    int m_aiPad2[12];
    xCinfo* Construct();
    xCinfo()
    {
        Construct();
    }
    void Destroy();
    ~xCinfo()
    {
        Destroy();
    }
};
class xFilter
{
  public:
    unsigned int m_ui;
    xFilter(int i);
    operator unsigned int();
};
class xPhantom : public xMemObj
{
  public:
    int m_ai[6];
    xPhantom(const void* pInfo);
};
template <class T> class xSP
{
  public:
    T* m_pObject;
    xSP& operator=(T* p);
};

class xPick
{
  public:
    int m_aiPad[0xe8];
    xSP<xPhantom> m_spPhantom;
    bool m_b3a4;
    unsigned int m_ui3a8;
    void FUN_006269a0(float fRadius, unsigned int uiLayer);
};

// @fnv 0x006269a0
void xPick::FUN_006269a0(float fRadius, unsigned int uiLayer)
{
    xSphereShape* qfTOqo = new xSphereShape(fRadius, true);
    xCinfo qsSDDgz;
    xFilter qrEZrs(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(qrEZrs))->FUN_004a39f0(0x27);
    reinterpret_cast<::FUN_0059ce80_shell *>(&(qrEZrs))->FUN_0059ce80(uiLayer);
    m_ui3a8 = uiLayer;
    qsSDDgz.m_uiFilter = qrEZrs;
    qsSDDgz.m_pShape = ((void *)(::FUN_004ae750((void *)(qfTOqo))));
    reinterpret_cast<::FUN_0056e120_shell *>(&(qsSDDgz.m_kSub))->FUN_0056e120();
    m_spPhantom = new xPhantom(&qsSDDgz);
    m_b3a4 = true;
}


struct Vec_006286f0
{
    __m128 v;
    Vec_006286f0();
};

struct Half_006286f0
{
    float x;
    float y;
    float z;
    float w;
};

struct __declspec(align(16)) Box_006286f0
{
    Half_006286f0 lo;
    Half_006286f0 hi;
    Box_006286f0();
};

struct Shape_006286f0
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
    float unk28[3];
    float unk34[3];
};

struct Node_006286f0
{
};

struct Obj_006286f0
{
};

struct Src_006286f0
{
};

struct Ptr_006286f0
{
    Src_006286f0* p;
    Src_006286f0* operator->() const;
};

struct Main_006286f0
{
    int unk00;
    int unk04;
    Ptr_006286f0 sources[6];
    Obj_006286f0* unk20;
    void FUN_006286f0();
};

struct VMin_006286f0 : Vec_006286f0
{
};

namespace fnv_00631370 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    signed char m128_i8[16];
};
struct __declspec(align(16)) FUN_00437c10
{
    __m128 minimum, maximum;
    FUN_00437c10();
    float& FUN_00560d30(int index);
};
struct ItemPos
{
    float x, y, z;
};
struct WorkActor
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
    virtual void GetBounds(FUN_00437c10* bounds);
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual int IsValid();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual ItemPos* GetPos();
};
struct WorkItem
{
    WorkActor* actor;
    WorkActor* src;
    WorkActor* target;
};
struct WorkList
{
};
class WorkOwner
{
  public:
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
    WorkList list;
    void FUN_00631370(WorkActor* actor, bool checkDist, bool skip);
};
// @fnv 0x00631370
void WorkOwner::FUN_00631370(WorkActor* actor, bool checkDist, bool skip)
{
    void* it = ((void *)(::FUN_00559450((int *)&(list))));
    void* next = 0;
    while (it)
    {
        next = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(list))->DereferenceIfNotNull((int **)(it))));
        if (it)
        {
            WorkItem* item = ((::fnv_00631370::WorkItem *)(reinterpret_cast<::FUN_006317a0_struct *>(&(list))->AddEight((int)(it))));
            if (!item->actor->IsValid())
            {
                reinterpret_cast<::WaterZoneRemoval *>(this)->FUN_0062fc70((::ParamStruct *)(item));
                reinterpret_cast<::FUN_0049c5d0_cls *>(&(list))->RemoveNode((::ListLink_b5187 **)(void **)(&it));
                delete item;
            }
            else
            {
                bool match = !actor || item->actor == actor || item->target == actor;
                if (checkDist)
                {
                    FUN_00437c10 bounds;
                    item->src->GetBounds(&bounds);
                    match = reinterpret_cast<::bhkCharacterController *>(&(bounds))->GetVectorElement(2) > ::FUN_004a3e90(item->target->GetPos()->z);
                }
                if (match)
                {
                    if (!skip)
                        reinterpret_cast<::WaterZoneRemoval *>(this)->FUN_0062fc70((::ParamStruct *)(item));
                    reinterpret_cast<::FUN_0049c5d0_cls *>(&(list))->RemoveNode((::ListLink_b5187 **)(void **)(&it));
                    delete item;
                }
            }
        }
        it = next;
    }
}
}  // namespace fnv_00631370

class TESForm620;
class bhkWorldObject620;

class hkVector4620
{
  public:
    hkVector4620();
    __m128 m_vComponents;
};

class CollisionInfo620
{
  public:
    CollisionInfo620* GetCollision();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    void* m_pvBodyA;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    void* m_pvBodyB;
    int m_iBodyIndex;
};

class TESObjectREFR620
{
  public:
    const void* GetPosition();
};

class bhkCharacter620
{
  public:
    virtual void vc000();
    virtual void vc004();
    virtual void vc008();
    virtual void vc00c();
    virtual void vc010();
    virtual void vc014();
    virtual void vc018();
    virtual void vc01c();
    virtual void vc020();
    virtual void vc024();
    virtual void vc028();
    virtual void vc02c();
    virtual void vc030();
    virtual void vc034();
    virtual void vc038();
    virtual void vc03c();
    virtual void vc040();
    virtual void vc044();
    virtual void vc048();
    virtual void vc04c();
    virtual void vc050();
    virtual void vc054();
    virtual void vc058();
    virtual void vc05c();
    virtual void vc060();
    virtual void vc064();
    virtual void vc068();
    virtual void vc06c();
    virtual void vc070();
    virtual void vc074();
    virtual void vc078();
    virtual void vc07c();
    virtual void vc080();
    virtual void vc084();
    virtual void vc088();
    virtual void vc08c();
    virtual void vc090();
    virtual void vc094();
    virtual void vc098();
    virtual void vc09c();
    virtual void vc0a0();
    virtual void vc0a4();
    virtual void vc0a8();
    virtual void vc0ac();
    virtual void vc0b0();
    virtual void vc0b4();
    virtual void vc0b8();
    virtual void vc0bc();
    virtual void vc0c0();
    virtual void vc0c4();
    virtual void vc0c8();
    virtual void vc0cc();
    virtual void vc0d0();
    virtual void vc0d4();
    virtual void vc0d8();
    virtual void vc0dc();
    virtual void* GetBody(int iIndex);
};

class bhkNode620
{
  public:
    virtual void vn000();
    virtual void vn004();
    virtual void vn008();
    virtual void vn00c();
    virtual void vn010();
    virtual void vn014();
    virtual void vn018();
    virtual void vn01c();
    virtual void vn020();
    virtual void vn024();
    virtual void vn028();
    virtual void vn02c();
    virtual void vn030();
    virtual void vn034();
    virtual void vn038();
    virtual void vn03c();
    virtual void vn040();
    virtual void vn044();
    virtual void vn048();
    virtual void vn04c();
    virtual void vn050();
    virtual void vn054();
    virtual void vn058();
    virtual void vn05c();
    virtual void vn060();
    virtual void vn064();
    virtual void vn068();
    virtual void vn06c();
    virtual void vn070();
    virtual void vn074();
    virtual void vn078();
    virtual void vn07c();
    virtual void vn080();
    virtual void vn084();
    virtual void vn088();
    virtual void vn08c();
    virtual void vn090();
    virtual void vn094();
    virtual void vn098();
    virtual void vn09c();
    virtual void vn0a0();
    virtual void vn0a4();
    virtual void vn0a8();
    virtual void vn0ac();
    virtual void vn0b0();
    virtual void vn0b4();
    virtual void vn0b8();
    virtual void vn0bc();
    virtual void vn0c0();
    virtual void vn0c4();
    virtual void vn0c8();
    virtual bhkCharacter620* GetCharacter();
    void* GetBody();
};

class Actor620
{
  public:
};

class ImpactEvent620
{
  public:
};

class FormRef620
{
  public:
};

class ImpactHandler620
{
  public:
    virtual ImpactEvent620* CreateEvent(void* pvTarget, void* pvBody, void* pvInfo);
    FormRef620 m_kSource;
};


class ImpactManager620
{
  public:
    ImpactHandler620* FUN_00620340(CollisionInfo620* pkInfo, void* pvSource, void* pvTarget, void* pvData,
                                   bool bDirect);
};

// @fnv 0x00620340
ImpactHandler620* ImpactManager620::FUN_00620340(CollisionInfo620* pkInfo, void* pvSource, void* pvTarget, void* pvData,
                                                 bool bDirect)
{
    void* pvObjA = ((void *)(::FUN_004b5820((::FormLike *)(pkInfo->m_pvBodyA))));
    void* pvObjB = ((void *)(::FUN_004b5820((::FormLike *)(pkInfo->m_pvBodyB))));
    void* pvRefA = ((void *)(::FUN_0056f930((::NiAVObject *)(pvObjA))));
    void* pvRefB = ((void *)(::FUN_0056f930((::NiAVObject *)(pvObjB))));
    void* pvSourceBody = pvRefA == pvSource ? pkInfo->m_pvBodyA : (pvRefB == pvSource ? pkInfo->m_pvBodyB : 0);
    void* pvTargetBody = pvRefA == pvTarget ? pkInfo->m_pvBodyA : (pvRefB == pvTarget ? pkInfo->m_pvBodyB : 0);
    ImpactHandler620* pkHandler = ((::ImpactHandler620 *)(reinterpret_cast<::S_00620260_C *>(this)->FUN_00620260((int)(pvSource), (int)(pvSourceBody))));
    if (pkHandler)
    {
        ImpactEvent620* pkEvent = 0;
        if (bDirect)
            pkEvent = ((::ImpactEvent620 *)(reinterpret_cast<::FUN_0057b700_class *>((pkHandler))->FUN_0061fd70((unsigned int)(pvTarget), (unsigned int)(pvTargetBody), (unsigned int)(pvData))));
        else
            pkEvent = pkHandler->CreateEvent(pvTarget, pvTargetBody, pvData);
        if (pkEvent)
        {
            reinterpret_cast<::FUN_006205c0_Class *>((pkEvent))->ForwardToMember(((::CollisionInfo620 *)(new ((void *)(pkInfo)) ::Vec3())));
            TESObjectREFR620* pkRef = ((::TESObjectREFR620 *)(::FUN_004b59f0(((void *)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkHandler->m_kSource))->GetName())))));
            hkVector4620 kPos;
            int iSize = 0x24;
            if (pkRef)
            {
                reinterpret_cast<::AlignedVector *>(&(kPos))->FUN_004a3f10((*(const ::AlignedVector *)(((const void *)(::FUN_00560dc0((::TESDataHandler *)(pkRef)))))));
                Actor620* pkActor = (Actor620*)FUN_004b5a80(pkRef);
                bhkNode620* pkNode = pkActor ? ((::bhkNode620 *)(reinterpret_cast<::FUN_004ae6a0_shell *>((pkActor))->FUN_004ae6a0())) : 0;
                bhkCharacter620* pkCharacter = pkNode ? pkNode->GetCharacter() : 0;
                if (pkCharacter && pkInfo->m_iBodyIndex != -1)
                    reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>((pkEvent))->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(void *)(pkCharacter->GetBody(pkInfo->m_iBodyIndex)));
                else if (pkNode)
                    reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>((pkEvent))->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(void *)(((void *)(reinterpret_cast<::FUN_006205a0_Class *>((pkNode))->FUN_006205a0()))));
            }
            else
            {
                reinterpret_cast<::S_00538f40 *>(&(kPos))->FUN_00538f40();
            }
            reinterpret_cast<::FUN_0056d300_S *>((pkEvent))->FUN_0056d300(&kPos);
        }
    }
    return pkHandler;
}

struct xP3
{
    float x, y, z;
    xP3 operator-(const xP3&) const;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4();
    float& FUN_00560d30(int);
};
struct xFltSetting
{
};
struct xMid
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
    virtual void v125();
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
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual void v436();
    virtual void* FUN_6d4();
};

struct xPlayer
{
};
struct xQty
{
    int m_q[3];
};
struct xEvent
{
    xEvent();
    xQty m_iWordAt00;
    xQty m_iThirdValue;
    int m_rest[14];
};
struct xTag
{
    xTag();
    char m_iThirdValue;
};
struct xCollector
{
    xCollector();
    ~xCollector();
    int m_q[0xe8];
};
struct xNode;
struct xModel
{
};
struct xModelPtr
{
};
struct xBody
{
};
struct xMotion
{
};
typedef void (*xCastFn)(xModelPtr*, xModelPtr*, xEvent*, xCollector*);
struct xEffect
{
    unsigned int FUN_00407840();
};
struct xEffItem
{
    unsigned int FUN_00407840();
};
struct xCaster2
{
};
struct xSrc
{
};
struct xRef
{
    xCaster2* FUN_00621ad0();
};
struct xBodyPtr
{
    int m_iWordAt00;
};
struct xCaster
{
    xBodyPtr m_iWordAt00;
    xBodyPtr m_iWordAt04;
    bool FUN_006214d0(xRef* apRef, const xP3& akPos, float afA, float afB);
};
namespace fnv_00622d60 {
struct xFilter
{
    xFilter(int);
    unsigned int m_uiFilterValue;
};
struct xCinfoSub
{
    int m_q[12];
};
struct __declspec(align(16)) xCinfo
{
    xCinfo();
    ~xCinfo();
    unsigned int m_uiFilterInfo;
    int m_pCollisionShape;
    int m_pad08[6];
    xCinfoSub m_20;
    int m_pad50[4];
};
struct xNiAlloc
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct xShape : xNiAlloc
{
    xShape(float, bool);
    int m_auiShapeKeys[5];
};
struct xBody : xNiAlloc
{
    xBody(xCinfo*);
    int m_auiShapeKeys[6];
};
struct xPhantom
{
};
struct xPtr
{
    void FUN_0066b0d0(void*);
    xPhantom* operator->();
    int m_iWordAt00;
};
struct xCaster
{
    char m_auiShapeKeys[0x3a0];
    xPtr m_3a0;
    void FUN_00622d60(float afRadius, unsigned int auiLayer);
};
// @fnv 0x00622d60
void xCaster::FUN_00622d60(float afRadius, unsigned int auiLayer)
{
    xShape* SHAPE = new xShape(afRadius, true);
    xCinfo CINFO;
    xFilter FILTER(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(FILTER))->FUN_004a39f0(0x27);
    reinterpret_cast<::FUN_0059ce80_shell *>(&(FILTER))->FUN_0059ce80(auiLayer);
    CINFO.m_uiFilterInfo = ((unsigned int)(::FUN_00559450((int *)&(FILTER))));
    CINFO.m_pCollisionShape = ::FUN_004ae750(SHAPE);
    reinterpret_cast<::FUN_0056e120_shell *>(&(CINFO.m_20))->FUN_0056e120();
    m_3a0.FUN_0066b0d0(new xBody(&CINFO));
    reinterpret_cast<::fnv_00622f20::FUN_00622f20_Class *>(((m_3a0).operator->()))->FUN_00622f20("DecalCaster");
    __int64 KEY = 0xfffffd471fe3f637;
    ::ShadowLightData::SetTargetMaskForSelection(0x27, KEY);
}
}  // namespace fnv_00622d60

struct __declspec(align(16)) MotionVector
{
    __m128 value;
    MotionVector();
};
struct __declspec(align(16)) MotionFrame
{
    __m128 value;
    float first, second;
    MotionFrame();
};
struct MotionOwner;
struct MotionWorld
{
};
struct MotionPointer
{
};
struct MotionStatus
{
};
struct MotionOwner
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Update();
    int unk004, unk008, unk00c, unk010;
    int unk014, unk018, unk01c, unk020;
    int unk024, unk028, unk02c, unk030;
    int unk034, unk038, unk03c, unk040;
    int unk044, unk048, unk04c, unk050;
    int unk054, unk058, unk05c, unk060;
    int unk064, unk068, unk06c, unk070;
    int unk074, unk078, unk07c, unk080;
    int unk084, unk088, unk08c, unk090;
    int unk094, unk098, unk09c, unk0a0;
    int unk0a4, unk0a8, unk0ac, unk0b0;
    int unk0b4, unk0b8, unk0bc, unk0c0;
    int unk0c4, unk0c8, unk0cc, unk0d0;
    int unk0d4, unk0d8, unk0dc, unk0e0;
    int unk0e4, unk0e8, unk0ec, unk0f0;
    int unk0f4, unk0f8, unk0fc, unk100;
    int unk104, unk108, unk10c, unk110;
    int unk114, unk118, unk11c, unk120;
    int unk124, unk128, unk12c, unk130;
    int unk134, unk138, unk13c, unk140;
    int unk144, unk148, unk14c, unk150;
    int unk154, unk158, unk15c, unk160;
    int unk164, unk168, unk16c, unk170;
    int unk174, unk178, unk17c, unk180;
    int unk184, unk188, unk18c, unk190;
    int unk194, unk198, unk19c, unk1a0;
    int unk1a4, unk1a8, unk1ac, unk1b0;
    int unk1b4, unk1b8, unk1bc, unk1c0;
    int unk1c4, unk1c8, unk1cc, unk1d0;
    int unk1d4, unk1d8, unk1dc, unk1e0;
    int unk1e4, unk1e8, unk1ec, unk1f0;
    int unk1f4, unk1f8, unk1fc, unk200;
    int unk204, unk208, unk20c, unk210;
    int unk214, unk218, unk21c, unk220;
    int unk224, unk228, unk22c, unk230;
    int unk234, unk238, unk23c, unk240;
    int unk244, unk248, unk24c, unk250;
    int unk254, unk258, unk25c, unk260;
    int unk264, unk268, unk26c, unk270;
    int unk274, unk278, unk27c, unk280;
    int unk284, unk288, unk28c, unk290;
    int unk294, unk298, unk29c, unk2a0;
    int unk2a4, unk2a8, unk2ac, unk2b0;
    int unk2b4, unk2b8, unk2bc, unk2c0;
    int unk2c4, unk2c8, unk2cc, unk2d0;
    int unk2d4, unk2d8, unk2dc, unk2e0;
    int unk2e4, unk2e8, unk2ec, unk2f0;
    int unk2f4, unk2f8, unk2fc, unk300;
    int unk304, unk308, unk30c, unk310;
    int unk314, unk318, unk31c, unk320;
    int unk324, unk328, unk32c, unk330;
    int unk334, unk338, unk33c, unk340;
    int unk344, unk348, unk34c, unk350;
    int unk354, unk358, unk35c, unk360;
    int unk364, unk368, unk36c, unk370;
    int unk374, unk378, unk37c, unk380;
    int unk384, unk388, unk38c, unk390;
    int unk394, unk398, unk39c;
    MotionPointer world;
    void FUN_00622f80(const void*, const void*, float);
};
// @fnv 0x00622f80
void MotionOwner::FUN_00622f80(const void* origin, const void* rotation, float time)
{
    bool result = false;
    if (time != 0.0)
        reinterpret_cast<::fnv_00623310::FUN_00623310_Class *>(this)->FUN_00623310(time);
    reinterpret_cast<::FUN_006233c0 *>(this)->GetImpactDataForMaterial(0);
    Update();
    if (((::MotionWorld *)(::FUN_00559450((int *)&(world)))))
    {
        MotionVector vector;
        MotionFrame frame;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&vector)), (*(const ::fnv_004a3e00::NiPoint3 *)(origin)));
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&frame)), (*(const ::fnv_004a3e00::NiPoint3 *)(rotation)));
        reinterpret_cast<::ScriptX *>((((::MotionWorld *)(::FUN_00559450((int *)&(world))))))->InvokeInterfaceCall((int)&(vector), (int)&(frame), (int)(this), 0);
        bool temporary;
        result = reinterpret_cast<::FUN_005609f0_shell *>((((::MotionStatus *)(reinterpret_cast<::Hld621210 *>(this)->FUN_00621210((::Rcv621210 *)&(temporary))))))->FUN_005609f0();
    }
    reinterpret_cast<::FUN_00623070_Class *>(this)->FUN_00623070();
}

class S006230f0_Vector
{
  public:
    S006230f0_Vector();  // FUN_006815c0
    __m128 m_vComponents;
};

class S006230f0_Source;

class S006230f0_Object
{
  public:
    void FUN_006230f0(const S006230f0_Source* pSource);
};

// @fnv 0x006230f0
void S006230f0_Object::FUN_006230f0(const S006230f0_Source* pSource)
{
    S006230f0_Vector kValue;
    reinterpret_cast<::FUN_006219f0_Class *>(this)->FUN_006219f0((::hkpRigidBody *)(((const ::S006230f0_Vector *)&(::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&kValue)), (*(const ::fnv_004a3e00::NiPoint3 *)(pSource)))))));
}

namespace fnv_006271b0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    signed char m128_i8[16];
};
struct __declspec(align(16)) FUN_00437c10
{
    __m128 minimum, maximum;
    FUN_00437c10();
    FUN_00437c10* FUN_004a3c90(FUN_00437c10*);
    void FUN_00627920(FUN_00437c10*);
    float& FUN_00560d30(int);
};
struct __declspec(align(16)) FUN_005dbf20
{
    __m128 value;
    FUN_005dbf20(float);
    FUN_005dbf20* FUN_004a3c90(FUN_005dbf20*);
    void FUN_00627920(FUN_005dbf20*);
    float& FUN_00560d30(int);
};
struct __declspec(align(16)) FUN_004a3c90
{
    __m128 value;
    FUN_004a3c90(FUN_005dbf20*);
    void FUN_00627920(FUN_005dbf20*);
    float& FUN_00560d30(int);
};
struct Cell
{
};
struct Node;
struct Ref
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
    virtual bool IsValid();
};
struct Node
{
};
struct Filter
{
    int value;
    Filter(int);
};
struct FilterData
{
};
struct ObjArray
{
    int a, b, c;
    ObjArray();
    ~ObjArray();
};
struct ItemList
{
};
struct Test
{
};
struct Layer
{
};
struct Ptr
{
    void* value;
};
struct Map
{
    int a, b, c, d;
    Map(int);
    ~Map();
};
struct Scrap
{
    int a, b, c, d;
    Scrap();
    ~Scrap();
    Node*& FUN_00877a30(unsigned);
};
struct Owner
{
    int unk00, unk04;
    Ptr layers[6];
    Cell* cell;
    Map map;
    int unk34, unk38, unk3c;
    float distance;
    bool FUN_006281d0(Cell*, int, FUN_00437c10*);
    void FUN_006271b0(Cell*, int);
};
// @fnv 0x006271b0
void Owner::FUN_006271b0(Cell* next, int flag)
{
    if (next != cell && next)
    {
        FUN_00437c10 bounds;
        if (!FUN_006281d0(next, flag, &bounds))
            return;
        reinterpret_cast<::BoundaryOwner *>(this)->BuildWalls((::TESObjectCELL *)(next), (const ::BoundaryBox *)(::fnv_006271b0::FUN_00437c10 *)(&bounds));
        cell = next;
        reinterpret_cast<::Main_006286f0 *>(this)->FUN_006286f0();
    }
    if (!next)
    {
        cell = next;
        reinterpret_cast<::fnv_00628da0::LoadedAreaBound *>(this)->FUN_00628da0();
        return;
    }
    unsigned short mask = 1;
    Map fresh(0x25);
    for (unsigned i = 0; i < 6; i++, mask <<= 1)
    {
        bool interior = reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior() || i == 0;
        Layer* layer = ((::fnv_006271b0::Layer *)(reinterpret_cast<::FUN_00620b80_shell *>((((::fnv_006271b0::Layer *)(::FUN_00559450((int *)&(layers[i]))))))->GetReferenceFlags()));
        ItemList* list = ((::fnv_006271b0::ItemList *)(reinterpret_cast<::FUN_0045c650_shell *>((layer))->FUN_0045c650()));
        char dummy;
        if (!reinterpret_cast<::FUN_005609f0_shell *>((((Test*)reinterpret_cast<::FUN_0062e120_shell *>((list))->FUN_0062e120(&dummy))))->FUN_005609f0())
        {
            int count = ((int)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
            ObjArray first;
            ObjArray second;
            reinterpret_cast<::FUN_00629a20_Class *>(&(second))->FUN_00629a20(((int)(reinterpret_cast<::Callees *>((list))->FUN_00726070())));
            for (int j = 0; j < count; j++)
            {
                Node* a = ((::fnv_006271b0::Node *)(::FUN_004b59f0(((::fnv_006271b0::Node *)&(reinterpret_cast<::FUN_00629ab0_shell *>((list))->FUN_00629ab0(j))))));
                if (a)
                    reinterpret_cast<::FUN_006299c0_cls *>(&(second))->FUN_006299c0((int)(&a));
                else
                {
                    Node* b = ((::fnv_006271b0::Node *)(::FUN_004b5950(((::fnv_006271b0::Node *)&(reinterpret_cast<::FUN_00629ab0_shell *>((list))->FUN_00629ab0(j))))));
                    if (b)
                        reinterpret_cast<::FUN_006299c0_cls *>(&(first))->FUN_006299c0((int)(&b));
                }
            }
            for (int j = 0; j < ((int)(reinterpret_cast<::Callees *>(&(first))->FUN_00726070())); j++)
            {
                if (interior)
                {
                    Filter filter(((int)(::FUN_0043b540((char *)(((FilterData*)((void *)(::FUN_00460140((int)(((::fnv_006271b0::Node *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(first))->FUN_00629ab0(j)))))))))))));
                    Ref* ref = ((::fnv_006271b0::Ref *)(::FUN_0062b4e0(((void *)(::FUN_00460140((int)(((::fnv_006271b0::Node *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(first))->FUN_00629ab0(j))))))))));
                    if (reinterpret_cast<::FUN_0043b4d0_shell *>(&(filter))->FUN_0043b4d0() == 30 && ref && ref->IsValid())
                    {
                        Ref* r = ref;
                        reinterpret_cast<::Me *>(this)->FUN_006295e0((::Ref *)(r));
                    }
                }
            }
            ObjArray seen;
            for (int j = 0; j < ((int)(reinterpret_cast<::Callees *>(&(second))->FUN_00726070())); j++)
            {
                Node* node = ((::fnv_006271b0::Node *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(second))->FUN_00629ab0(j)));
                if (reinterpret_cast<::FUN_00629f10_Class *>(&(seen))->FUN_00629f10((int *)(::fnv_006271b0::Node **)(&node), 0, -1) == -1)
                {
                    Ref* ref = ((::fnv_006271b0::Ref *)(::FUN_0062b4e0(((void *)(::FUN_00460140((int)(node)))))));
                    if (node && ::FUN_00517670((::TESDataHandler *)(node)) != 4 && ::FUN_00517670((::TESDataHandler *)(node)) != 5 && ::FUN_00517670((::TESDataHandler *)(node)) != 7)
                    {
                        Node* other = ((::fnv_006271b0::Node *)(::FUN_004b5a80(node)));
                        if (!interior)
                        {
                            unsigned short old;
                            bool found = reinterpret_cast<::FUN_00629cf0_cls *>(&(map))->LookupValue((int)(other), &old);
                            if (!found || !(old & mask))
                            {
                                FUN_004a3c90 box(((::fnv_006271b0::FUN_005dbf20 *)&(::fnv_00560d80::FUN_00560d80((void *)(other)))));
                                float d = i != 1 ? distance * -1.0 : distance;
                                FUN_005dbf20 v(d);
                                reinterpret_cast<::S_00627920 *>(&(box))->FUN_00627920((::S_00561240 *)(::fnv_006271b0::FUN_005dbf20 *)(&v));
                                float& z = reinterpret_cast<::bhkCharacterController *>(&(box))->GetVectorElement(2);
                                z = z * -1.0;
                                reinterpret_cast<::S *>((other))->FUN_00561690((int)(&box));
                            }
                            unsigned short bits = mask;
                            if (reinterpret_cast<::FUN_00629cf0_cls *>(&(fresh))->LookupValue((int)(other), &bits))
                                bits |= mask;
                            reinterpret_cast<::S_00629c10_Map *>(&(fresh))->SetKeyValue((int)(other), bits);
                        }
                        else
                        {
                            ObjArray more;
                            reinterpret_cast<::Mover628 *>(this)->MoveToDestination((::Body628 *)(other), (::Group628 *)(::fnv_006271b0::ObjArray *)(&more));
                            for (int k = 0; k < ((int)(reinterpret_cast<::Callees *>(&(more))->FUN_00726070())); k++)
                                reinterpret_cast<::FUN_006299c0_cls *>(&(seen))->FUN_006299c0((int)(&((::fnv_006271b0::Node *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(more))->FUN_00629ab0(k)))));
                        }
                    }
                }
            }
        }
    }
    void* pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(fresh))->GetFirstPos();
    Node* key;
    unsigned short bits;
    while (pos)
    {
        reinterpret_cast<::FUN_00629d70_cls *>(&(fresh))->GetNextEntry((::FUN_00629d70_entry **)(void **)(&pos), (unsigned int *)(::fnv_006271b0::Node **)(&key), &bits);
        reinterpret_cast<::S_00629c10_Map *>(&(map))->SetKeyValue((int)(key), bits);
    }
    Scrap removals;
    pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(map))->GetFirstPos();
    while (pos)
    {
        reinterpret_cast<::FUN_00629d70_cls *>(&(map))->GetNextEntry((::FUN_00629d70_entry **)(void **)(&pos), (unsigned int *)(::fnv_006271b0::Node **)(&key), &bits);
        if (!reinterpret_cast<::FUN_00629cf0_cls *>(&(fresh))->LookupValue((int)(key), &bits))
            reinterpret_cast<::FUN_00438690 *>(&(removals))->FUN_007cb2e0((unsigned int *)(::fnv_006271b0::Node **)(&key));
    }
    for (unsigned i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(removals))->GetName())); i++)
        reinterpret_cast<::NiTMap_S *>(&(map))->RemoveKey((unsigned int)(removals.FUN_00877a30(i)));
}
}  // namespace fnv_006271b0

class hkVector4B
{
  public:
    hkVector4B();
    float& operator()(int i);
    __m128 m_vComponents;
};

class hkAabbB
{
  public:
    hkAabbB();
    hkVector4B m_kMinimumCorner;
    hkVector4B m_kMaximumCorner;
};

class hkTransformB
{
  public:
    hkTransformB();
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_kColumn3;
};

class bhkShapeB;
class bhkWorldB
{
  public:
    virtual void vw000();
    virtual void vw004();
    virtual void vw008();
    virtual void vw00c();
    virtual void vw010();
    virtual void vw014();
    virtual void vw018();
    virtual void vw01c();
    virtual void vw020();
    virtual void vw024();
    virtual void vw028();
    virtual void vw02c();
    virtual void vw030();
    virtual void vw034();
    virtual void vw038();
    virtual void AddAabb(void* pvAabb);
};

class NiObjectB
{
  public:
    void* GetCollision();
};

class bhkCollisionB
{
  public:
};

class bhkRigidBodyB
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
    virtual int IsFixed();
    virtual void vs098();
    virtual void vs09c();
    virtual void vs0a0();
    virtual void vs0a4();
    virtual void vs0a8();
    virtual void vs0ac();
    virtual void vs0b0();
    virtual void vs0b4();
    virtual void vs0b8();
    virtual void vs0bc();
    virtual void vs0c0();
    virtual void vs0c4();
    virtual void vs0c8();
    virtual void vs0cc();
    virtual void vs0d0();
    virtual void vs0d4();
    virtual void vs0d8();
    virtual void vs0dc();
    virtual void vs0e0();
    virtual void vs0e4();
    virtual void vs0e8();
    virtual void vs0ec();
    virtual void vs0f0();
    virtual void GetTransform(hkTransformB* pkOut);
};

class bhkShapeB
{
  public:
};

class ShapeOwnerB
{
  public:
};

class NiPointerB
{
  public:
    void* operator->();
};

class RefPtrB
{
  public:
    NiPointerB* Get(unsigned int i);
};

class BodyRefB
{
  public:
    bhkRigidBodyB* Get();
};

class BodyListB
{
  public:
    BodyRefB* GetAt(unsigned int i);
};

class CellObjectB
{
  public:
};

class CellB
{
  public:
};

class GridB
{
  public:
    unsigned int GetSize();
};

class PartB
{
  public:
    bhkCollisionB* GetCollision();
};

class PartRefB
{
  public:
    PartB* Get();
};

class PartListB
{
  public:
    PartB** GetAt(int i);
};

class SkeletonB
{
  public:
};

class Node3DB
{
  public:
};

class RootB
{
  public:
};

class TESObjectREFRB
{
  public:
    bool IsActor();
};

class SpawnAreaB
{
  public:
    bool FUN_006281d0(TESObjectREFRB* pkRef, GridB* pkGrid, hkAabbB* pkOut);
};

struct S006288c0_Vector
{
    __m128 m_vComponents;
};

const S006288c0_Vector& FUN_00458b20();  // shared zero vector

struct S006288c0_Aabb
{
    S006288c0_Aabb(const S006288c0_Vector& min, const S006288c0_Vector& max);  // FUN_00628950
    S006288c0_Vector m_kMinimumCorner;
    S006288c0_Vector m_kMaximumCorner;
};

class S006288c0_Shape
{
  public:
};

class S006288c0_Bounds
{
  public:
};

class S006288c0_Object
{
  public:
    void FUN_006288c0(S006288c0_Bounds* bounds);
};

// @fnv 0x006288c0
void S006288c0_Object::FUN_006288c0(S006288c0_Bounds* bounds)
{
    S006288c0_Shape* shape = ((::S006288c0_Shape *)(::FUN_004ae750((void *)this)));
    if (shape)
    {
        ::FUN_00a29680();
        reinterpret_cast<::S6281a0 *>((bounds))->FUN_006281a0((const ::S6281a0 &)((*(const ::S006288c0_Aabb *)(::FUN_00984230((char *)(shape))))));
        ::FUN_00a29680();
    }
    else
    {
        reinterpret_cast<::S6281a0 *>((bounds))->FUN_006281a0((const ::S6281a0 &)((const ::S006288c0_Aabb &)(S006288c0_Aabb(FUN_00458b20(), FUN_00458b20()))));
    }
}

struct __declspec(align(16)) Text628980
{
    char field_00[32];
};
struct List628980
{
    int field_00, field_04, field_08;
    List628980();
    ~List628980();
};
struct Topic628980
{
};
struct Response628980
{
};
struct Voice628980
{
};
struct Threshold628980
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
    virtual void Format(void*, Text628980*);
};
struct Challenge628980
{
};
struct Predicate628980
{
    bool Test();
};
struct Filter628980
{
};
struct Owner628980
{
    void FUN_00628980(Filter628980*, List628980*);
};

struct S00628c50_Vector
{
    __m128 m_vComponents;
    void FUN_00628cc0(const S00628c50_Vector* a, const S00628c50_Vector* b);  // setAnd
};

class S00628c50_Box
{
  public:
    void FUN_00458a60(S00628c50_Vector* out, const S00628c50_Vector* point) const;
    bool FUN_00628c50(const S00628c50_Box* other) const;

    __m128 unk00;
    S00628c50_Vector m_kCenter;
};
// @fnv 0x00628980
void Owner628980::FUN_00628980(Filter628980* filter, List628980* input)
{
    Text628980 text;
    new ((void *)&(text)) ::fnv_00437c10::FUN_00437c10();
    Challenge628980* topic = 0;
    List628980 collected;
    for (int i = 0; i < ((int)(reinterpret_cast<::Callees *>((input))->FUN_00726070())); ++i)
    {
        topic = (Challenge628980*)((void *)(reinterpret_cast<::FUN_009611e0_shell *>((((Topic628980*)((void *)&(reinterpret_cast<::FUN_00629ab0_shell *>((input))->FUN_00629ab0(i))))))->FUN_009611e0()));
        List628980* responses = ((::List628980 *)(reinterpret_cast<::FUN_00624700_shell *>((((Topic628980*)((void *)&(reinterpret_cast<::FUN_00629ab0_shell *>((input))->FUN_00629ab0(i))))))->FUN_00624700()));
        for (int j = 0; j < ((int)(reinterpret_cast<::Callees *>((responses))->FUN_00726070())); ++j)
        {
            Voice628980* voice = (Voice628980*)((void *)(::FUN_00460140((int)(((Response628980*)((void *)&(reinterpret_cast<::FUN_00629ab0_shell *>((responses))->FUN_00629ab0(j))))))));
            if (::FUN_00559450((int *)(voice)))
            {
                Threshold628980* threshold = ((::Threshold628980 *)(reinterpret_cast<::LowProcess *>((topic))->GetPackageObjectType()));
                threshold->Format(((void *)(reinterpret_cast<::NonActorMagicTarget *>((voice))->GetActiveEffectList())), &text);
                char tag;
                if (!reinterpret_cast<::FUN_005609f0_shell *>((((::Predicate628980 *)(reinterpret_cast<::FUN_00628d10_cls *>((filter))->FUN_00628d10((::FUN_00628d10_cls *)(char *)(&tag), (::FUN_00628d10_cls *)(::Text628980 *)(&text))))))->FUN_005609f0() || !((int)(reinterpret_cast<::S00628c50_Box *>((filter))->FUN_00628c50((const ::S00628c50_Box *)(::Text628980 *)(&text)))))
                {
                    void* item = ((::TESObjectREFR620 *)(::FUN_004b59f0(voice)));
                    if (item && ::FUN_00517670((::TESDataHandler *)(item)) != 4 && ::FUN_00517670((::TESDataHandler *)(item)) != 5 && ::FUN_00517670((::TESDataHandler *)(item)) != 7)
                        reinterpret_cast<::FUN_006299c0_cls *>(&(collected))->FUN_006299c0((int)(&item));
                }
            }
        }
    }
    List628980 visited;
    for (int k = 0; k < ((int)(reinterpret_cast<::Callees *>(&(collected))->FUN_00726070())); ++k)
    {
        if (reinterpret_cast<::FUN_00629f10_Class *>(&(visited))->FUN_00629f10((int *)(void **)(&((void *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(collected))->FUN_00629ab0(k)))), 0, -1) == -1)
        {
            void* item = FUN_004b5a80(((void *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(collected))->FUN_00629ab0(k))));
            List628980 expanded;
            reinterpret_cast<::Mover628 *>(this)->MoveToDestination((::Body628 *)(item), (::Group628 *)(::List628980 *)(&expanded));
            for (int n = 0; n < ((int)(reinterpret_cast<::Callees *>(&(expanded))->FUN_00726070())); ++n)
                reinterpret_cast<::FUN_006299c0_cls *>(&(visited))->FUN_006299c0((int)(&((void *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(expanded))->FUN_00629ab0(n)))));
        }
    }
}

// @fnv 0x00628c50
bool S00628c50_Box::FUN_00628c50(const S00628c50_Box* other) const
{
    S00628c50_Vector a;
    FUN_00458a60(&a, &other->m_kCenter);
    S00628c50_Vector b;
    other->FUN_00458a60(&b, &m_kCenter);
    S00628c50_Vector c;
    c.FUN_00628cc0(&a, &b);
    return ((bool)(reinterpret_cast<::FUN_00458990_Holder *>((void *)&(c))->FUN_00458990(7)));
}

class NiPoint3P
{
  public:
    NiPoint3P();
    float x, y, z;
};

class hkVector4P
{
  public:
    hkVector4P();
    __m128 m_vComponents;
};


class TESObjectCELLP;

class TESObjectREFRP
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
    virtual bool IsActor();
    virtual void vs000();
    virtual void vs004();
    virtual void vs008();
    virtual void vs00c();
    virtual void vs010();
    virtual void vs014();
    virtual void vs018();
    virtual void vs01c();
    virtual void vs020();
    virtual void vs024();
    virtual void vs028();
    virtual void vs02c();
    virtual void vs030();
    virtual bool PickPoint(NiPoint3P* pkPos, NiPoint3P* pkNormal, int* piCell, int iFlags);
    virtual void vt000();
    virtual void vt004();
    virtual void vt008();
    virtual void vt00c();
    virtual void vt010();
    virtual void vt014();
    virtual void vt018();
    virtual void vt01c();
    virtual void vt020();
    virtual void vt024();
    virtual void vt028();
    virtual void vt02c();
    virtual void vt030();
    virtual void vt034();
    virtual void vt038();
    virtual void vt03c();
    virtual void vt040();
    virtual void vt044();
    virtual void vt048();
    virtual void vt04c();
    virtual void vt050();
    virtual void vt054();
    virtual void vt058();
    virtual void vt05c();
    virtual void vt060();
    virtual void vt064();
    virtual void vt068();
    virtual void vt06c();
    virtual void vt070();
    virtual void vt074();
    virtual void vt078();
    virtual void vt07c();
    virtual void vt080();
    virtual void vt084();
    virtual void vt088();
    virtual void vt08c();
    virtual void vt090();
    virtual void vt094();
    virtual void vt098();
    virtual void vt09c();
    virtual void vt0a0();
    virtual void vt0a4();
    virtual void vt0a8();
    virtual void vt0ac();
    virtual void vt0b0();
    virtual void vt0b4();
    virtual void vt0b8();
    virtual void vt0bc();
    virtual void vt0c0();
    virtual void vt0c4();
    virtual void vt0c8();
    virtual void vt0cc();
    virtual void vt0d0();
    virtual void vt0d4();
    virtual void vt0d8();
    virtual void vt0dc();
    virtual void vt0e0();
    virtual void vt0e4();
    virtual void vt0e8();
    virtual void vt0ec();
    virtual void vt0f0();
    virtual void vt0f4();
    virtual void vt0f8();
    virtual void vt0fc();
    virtual void vt100();
    virtual void vt104();
    virtual void vt108();
    virtual void vt10c();
    virtual void vt110();
    virtual void vt114();
    virtual void vt118();
    virtual void vt11c();
    virtual void vt120();
    virtual void vt124();
    virtual void vt128();
    virtual void vt12c();
    virtual void vt130();
    virtual void vt134();
    virtual void vt138();
    virtual void vt13c();
    virtual void vt140();
    virtual void vt144();
    virtual void vt148();
    virtual void vt14c();
    virtual void vt150();
    virtual void vt154();
    virtual void vt158();
    virtual TESObjectCELLP* GetParentCell();
    virtual NiPoint3P GetPosition();
};

class TESObjectCELLP
{
  public:
};


class RegionP
{
  public:
};

class RegionListP
{
  public:
};

struct ShapeTransformP
{
    float m_afRow[4];
};

class ShapeP
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ShapeTransformP m_kTransform;
};

class NodeP
{
  public:
};

class BodyP
{
  public:
};

class BodyPtrP
{
  public:
    BodyP* operator->();
};

class ShapeCastP
{
  public:
    ShapeCastP();
    __m128 m_kFrom;
    __m128 m_kTo;
};

class SpawnPlacerP
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    BodyPtrP m_spBodyA;
    unsigned int unk14;
    unsigned int unk18;
    BodyPtrP m_spBodyB;
    TESObjectCELLP* m_pkCell;

    void FUN_006296d0(TESObjectREFRP* pkRef, const NiPoint3P* pkPos, NiPoint3P* pkOut);
};

struct S00629930_Vector
{
    __m128 m_vComponents;
    void FUN_00628cc0(const S00629930_Vector* a, const S00629930_Vector* b);  // setAnd
};

class S00629930_Box
{
  public:
    void FUN_00458a60(S00629930_Vector* out, const S00629930_Vector* point) const;
    bool FUN_00629930(const S00629930_Box* other) const;

    S00629930_Vector m_kStartPoint;
    S00629930_Vector m_kCenter;
};
// @fnv 0x006296d0
void SpawnPlacerP::FUN_006296d0(TESObjectREFRP* pkRef, const NiPoint3P* pkPos, NiPoint3P* pkOut)
{
    int iCell = 0;
    TESObjectCELLP* pkCell = m_pkCell;
    TESObjectREFRP* pkActor = (pkRef && pkRef->IsActor()) ? pkRef : 0;
    NiPoint3P kNormal;
    bool bFound = false;
    NiPoint3P kPos = *pkPos;
    float fZ;
    if (pkRef && ::FUN_006d97b0((*(const ::NiPoint3 *)(&kPos)), (::TESObjectCELL *)(pkCell), (::TESWorldSpace *)(void *)(((void *)(reinterpret_cast<::TESObjectCELL *>((pkCell))->GetParentWorldSpace()))), &fZ))
    {
        kPos.z = fZ;
        *pkOut = kPos;
        bFound = true;
    }
    else if (pkActor && pkActor->GetParentCell() == m_pkCell)
    {
        *pkOut = pkActor->GetPosition();
        bFound = true;
    }
    else if (!pkActor && pkRef && pkRef->PickPoint(&kPos, &kNormal, &iCell, 0))
    {
        RegionP* pkRegion = ((::RegionP *)(reinterpret_cast<::FnCls *>(((*reinterpret_cast<::RegionListP * *>(&::g_TES))))->FUN_004519d0((*(float *)&(const ::NiPoint3P &)(kPos)), {}, {})));
        if (pkRegion && ((int)(reinterpret_cast<::FUN_00450fd0_class *>((pkRegion))->GetByteAtOffset38())) == 6)
        {
            *pkOut = kPos;
            bFound = true;
        }
    }

    if (bFound)
    {
        hkVector4P kFrom;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&kFrom)), (*(const ::fnv_004a3e00::NiPoint3 *)(pkOut)));
        ShapeCastP kCast;
        reinterpret_cast<::FUN_006295a0_shell *>(&(kCast))->FUN_006295a0();
        reinterpret_cast<::FUN_00629560_Class *>(&(kCast))->FUN_00629560((int)(&((::ShapeP *)(::FUN_00984230((char *)(((::NodeP *)(reinterpret_cast<::FUN_00620b80_shell *>(((m_spBodyA).operator->()))->GetReferenceFlags()))))))->m_kTransform));
        reinterpret_cast<::FUN_00629560_Class *>(&(kCast))->FUN_00629560((int)(((::ShapeP *)(::FUN_00984230((char *)(((::NodeP *)(reinterpret_cast<::FUN_00620b80_shell *>(((m_spBodyB).operator->()))->GetReferenceFlags()))))))));
        bFound = ((int)(reinterpret_cast<::S00629930_Box *>(&(kCast))->FUN_00629930((const ::S00629930_Box *)(::hkVector4P *)(&kFrom))));
    }
    if (!bFound)
        reinterpret_cast<::fnv_0054cfd0::TESObjectCELL_Ext *>((pkCell))->FUN_0054cfd0((::fnv_0054cfd0::NiPoint3 *)(pkOut), (::fnv_0054cfd0::NiPoint3 *)(::NiPoint3P *)(&kNormal));
}

// @fnv 0x00629930
bool S00629930_Box::FUN_00629930(const S00629930_Box* other) const
{
    S00629930_Vector a;
    FUN_00458a60(&a, &other->m_kStartPoint);
    S00629930_Vector b;
    other->FUN_00458a60(&b, &m_kCenter);
    S00629930_Vector c;
    c.FUN_00628cc0(&a, &b);
    return ((bool)(reinterpret_cast<::FUN_00458990_Holder *>((void *)&(c))->FUN_00458990(7)));
}

class hkSimdRealV
{
  public:
    hkSimdRealV(float f);
    __m128 m_vValue;
};

class hkVector4V
{
  public:
    hkVector4V();
    hkVector4V(const hkVector4V& v);
    void setSub4(const hkVector4V& a, const hkVector4V& b);
    __m128 m_vComponents;
};

class hkQuaternionV
{
  public:
    __m128 m_vec;
};
const hkQuaternionV& __cdecl FUN_0062aad0();

class hkTransformV
{
  public:
    hkTransformV();
    hkTransformV(const hkQuaternionV& kRot, const hkVector4V& kPos);
    void SetProduct(const hkTransformV& a, const hkTransformV& b);
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_kColumn3;
};

class SettingV
{
  public:
};

class MotionV
{
  public:
    void Activate();
};

class BodyV
{
  public:
    virtual void vb000();
    virtual void vb004();
    virtual void vb008();
    virtual void vb00c();
    virtual void vb010();
    virtual void vb014();
    virtual void vb018();
    virtual void vb01c();
    virtual void vb020();
    virtual void vb024();
    virtual void vb028();
    virtual void vb02c();
    virtual void vb030();
    virtual void vb034();
    virtual void vb038();
    virtual void vb03c();
    virtual void vb040();
    virtual void vb044();
    virtual void vb048();
    virtual void vb04c();
    virtual void vb050();
    virtual void vb054();
    virtual void vb058();
    virtual void vb05c();
    virtual void vb060();
    virtual void vb064();
    virtual void vb068();
    virtual void vb06c();
    virtual void vb070();
    virtual void vb074();
    virtual void vb078();
    virtual void vb07c();
    virtual void vb080();
    virtual void vb084();
    virtual void vb088();
    virtual void vb08c();
    virtual void vb090();
    virtual void vb094();
    virtual void vb098();
    virtual void vb09c();
    virtual void vb0a0();
    virtual void vb0a4();
    virtual void vb0a8();
    virtual void vb0ac();
    virtual void vb0b0();
    virtual void vb0b4();
    virtual void vb0b8();
    virtual void vb0bc();
    virtual void vb0c0();
    virtual void vb0c4();
    virtual void vb0c8();
    virtual void vb0cc();
    virtual void vb0d0();
    virtual void vb0d4();
    virtual void vb0d8();
    virtual void vb0dc();
    virtual void vb0e0();
    virtual void vb0e4();
    virtual void vb0e8();
    virtual void GetLinearVelocityVector(hkVector4V& kOut);
    virtual void vbf0();
    virtual void GetTransform(hkTransformV& kOut);
    float GetTime();
};

class NodeV
{
  public:
    BodyV* GetBody();
};

struct SmoothEntryV
{
    static void* operator new(unsigned int uiSize);
    BodyV* m_pkBody;
    void* m_pvRef;
    float m_fTime;
    int m_iArrayLength;
};

class SmoothListV
{
  public:
    bool IsEmpty();
    void AddHead(SmoothEntryV* const& rpkEntry);
};

// @fnv 0x0062a7e0
void __cdecl FUN_0062a7e0(const hkVector4V& kTarget, void* pvRef)
{
    NodeV* pkNode = pvRef ? ((::NodeV *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(pvRef)))) : 0;
    BodyV* pkBody = pkNode ? ((::BodyV *)(::fnv_006fa820::FUN_006fa820((const char *)(pkNode)))) : 0;
    if (!pkBody)
        return;
    SmoothEntryV* pkEntry = 0;
    if (!(*reinterpret_cast<::SmoothListV *>(&::g_011cc408)).IsEmpty())
    {
        SmoothListV* pkIter = &(*reinterpret_cast<::SmoothListV *>(&::g_011cc408));
        while (pkIter && !pkIter->IsEmpty() && !pkEntry)
        {
            SmoothEntryV* pkItem = *((::SmoothEntryV **)(new ((void *)(pkIter)) ::Vec3()));
            if (pkItem && pkItem->m_pkBody == pkBody)
                pkEntry = pkItem;
            pkIter = ((::SmoothListV *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070()));
        }
    }
    if (!pkEntry)
    {
        pkEntry = new SmoothEntryV;
        pkEntry->m_pkBody = pkBody;
        pkEntry->m_pvRef = pvRef;
        pkEntry->m_fTime = reinterpret_cast<::bhkRigidBody *>((pkBody))->GetBodyMass();
        pkEntry->m_iArrayLength = 0;
        (*reinterpret_cast<::SmoothListV *>(&::g_011cc408)).AddHead(pkEntry);
    }
    float fTime = pkEntry->m_fTime;
    hkTransformV kBodyTransform;
    hkTransformV kInverse;
    hkTransformV kTargetTransform(FUN_0062aad0(), kTarget);
    hkTransformV kDelta;
    pkBody->GetTransform(kBodyTransform);
    reinterpret_cast<::FUN_00cb21e0_shell *>(&(kInverse))->FUN_00cb21e0((const ::Matrix44 *)&(kBodyTransform));
    kDelta.SetProduct(kInverse, kTargetTransform);
    hkVector4V kIntersectionOffset((*(const ::hkVector4V *)(reinterpret_cast<::TESTopicInfo *>((void *)&(kDelta))->GetAddTopicList())));
    hkSimdRealV kSmooth(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingV *>(&::originalRuntimeFloatSetting676)))));
    reinterpret_cast<::S_00627920 *>(&(kIntersectionOffset))->FUN_00627920((::S_00561240 *)&(kSmooth));
    hkVector4V kMotionVelocity;
    pkBody->GetLinearVelocityVector(kMotionVelocity);
    hkSimdRealV kTime(fTime);
    reinterpret_cast<::S_00627920 *>(&(kMotionVelocity))->FUN_00627920((::S_00561240 *)&(kTime));
    hkVector4V kNewVelocity;
    kNewVelocity.setSub4(kMotionVelocity, kIntersectionOffset);
    hkSimdRealV kInv(1.0f / (fTime + ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingV *>(&::originalRuntimeFloatSetting676))))));
    reinterpret_cast<::S_00627920 *>(&(kNewVelocity))->FUN_00627920((::S_00561240 *)&(kInv));
    reinterpret_cast<::Owner *>((((::MotionV *)(::FUN_004ae750((void *)(pkBody))))))->FUN_00ca85f0((unsigned int)&(kNewVelocity));
    reinterpret_cast<::hkpEntityC9C *>((((::MotionV *)(::FUN_004ae750((void *)(pkBody))))))->FUN_00c9c1d0();
    pkEntry->m_fTime = fTime + ::FUN_00403e20((float *)&((*reinterpret_cast<::SettingV *>(&::originalRuntimeFloatSetting676))));
    pkEntry->m_iArrayLength++;
}

namespace fnv_0062ab60 {
class hkSimdRealV
{
  public:
    hkSimdRealV(float f);
    __m128 m_vValue;
};

class hkVector4V
{
  public:
    hkVector4V();
    hkVector4V(const hkVector4V& v);
    void setSub4(const hkVector4V& a, const hkVector4V& b);
    __m128 m_vComponents;
};

class hkQuaternionV
{
  public:
    __m128 m_vec;
};
const hkQuaternionV& __cdecl FUN_0062aad0();

class hkTransformV
{
  public:
    hkTransformV();
    hkTransformV(const hkQuaternionV& kRot, const hkVector4V& kPos);
    void SetProduct(const hkTransformV& a, const hkTransformV& b);
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_kColumn3;
};

class SettingV
{
  public:
};

class MotionV
{
  public:
    void Activate();
};

class BodyV
{
  public:
    virtual void vb000();
    virtual void vb004();
    virtual void vb008();
    virtual void vb00c();
    virtual void vb010();
    virtual void vb014();
    virtual void vb018();
    virtual void vb01c();
    virtual void vb020();
    virtual void vb024();
    virtual void vb028();
    virtual void vb02c();
    virtual void vb030();
    virtual void vb034();
    virtual void vb038();
    virtual void vb03c();
    virtual void vb040();
    virtual void vb044();
    virtual void vb048();
    virtual void vb04c();
    virtual void vb050();
    virtual void vb054();
    virtual void vb058();
    virtual void vb05c();
    virtual void vb060();
    virtual void vb064();
    virtual void vb068();
    virtual void vb06c();
    virtual void vb070();
    virtual void vb074();
    virtual void vb078();
    virtual void vb07c();
    virtual void vb080();
    virtual void vb084();
    virtual void vb088();
    virtual void vb08c();
    virtual void vb090();
    virtual void vb094();
    virtual void vb098();
    virtual void vb09c();
    virtual void vb0a0();
    virtual void vb0a4();
    virtual void vb0a8();
    virtual void vb0ac();
    virtual void vb0b0();
    virtual void vb0b4();
    virtual void vb0b8();
    virtual void vb0bc();
    virtual void vb0c0();
    virtual void vb0c4();
    virtual void vb0c8();
    virtual void vb0cc();
    virtual void vb0d0();
    virtual void vb0d4();
    virtual void vb0d8();
    virtual void vb0dc();
    virtual void vb0e0();
    virtual void vb0e4();
    virtual void vb0e8();
    virtual void GetLinearVelocityVector(hkVector4V& kOut);
    virtual void vbf0();
    virtual void GetTransform(hkTransformV& kOut);
    float GetTime();
    const hkVector4V& GetPosition();
};

class NodeV
{
  public:
    BodyV* GetBody();
};

struct SmoothEntryV
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pv);
    BodyV* m_pkBody;
    void* m_pvRef;
    float m_fTime;
    int m_iArrayLength;
};

class SmoothListV
{
  public:
    bool IsEmpty();
    void AddHead(SmoothEntryV* const& rpkEntry);
};

// @fnv 0x0062ab60
void __cdecl FUN_0062ab60(const hkVector4V& kTarget, void* pvRef)
{
    SmoothEntryV* pkEntry = 0;
    if (!(*reinterpret_cast<::fnv_0062ab60::SmoothListV *>(&::g_011cc408)).IsEmpty())
    {
        SmoothListV* pkIter = &(*reinterpret_cast<::fnv_0062ab60::SmoothListV *>(&::g_011cc408));
        while (pkIter && !pkIter->IsEmpty() && !pkEntry)
        {
            SmoothEntryV* pkItem = *((::fnv_0062ab60::SmoothEntryV **)(new ((void *)(pkIter)) ::Vec3()));
            if (pkItem && pkItem->m_pvRef == pvRef)
                pkEntry = pkItem;
            pkIter = ((::fnv_0062ab60::SmoothListV *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070()));
        }
    }
    if (!pkEntry)
        return;
    NodeV* pkNode = pvRef ? ((::fnv_0062ab60::NodeV *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(pvRef)))) : 0;
    BodyV* pkBody = pkNode ? ((::fnv_0062ab60::BodyV *)(::fnv_006fa820::FUN_006fa820((const char *)(pkNode)))) : 0;
    if (!pkBody)
        return;
    float fTime = pkEntry->m_fTime;
    hkTransformV kBodyTransform;
    hkTransformV kInverse;
    hkTransformV kTargetTransform(FUN_0062aad0(), kTarget);
    hkTransformV kDelta;
    pkBody->GetTransform(kBodyTransform);
    reinterpret_cast<::FUN_00cb21e0_shell *>(&(kInverse))->FUN_00cb21e0((const ::Matrix44 *)&(kBodyTransform));
    kDelta.SetProduct(kInverse, kTargetTransform);
    hkVector4V kIntersectionOffset((*(const ::fnv_0062ab60::hkVector4V *)(reinterpret_cast<::TESTopicInfo *>((void *)&(kDelta))->GetAddTopicList())));
    hkSimdRealV kSmooth(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0062ab60::SettingV *>(&::originalRuntimeFloatSetting676)))));
    reinterpret_cast<::S_00627920 *>(&(kIntersectionOffset))->FUN_00627920((::S_00561240 *)&(kSmooth));
    hkVector4V kMotionVelocity;
    pkBody->GetLinearVelocityVector(kMotionVelocity);
    hkSimdRealV kTime(fTime);
    reinterpret_cast<::S_00627920 *>(&(kMotionVelocity))->FUN_00627920((::S_00561240 *)&(kTime));
    hkVector4V kNewVelocity;
    reinterpret_cast<::S00458a10_Vector *>(&(kNewVelocity))->FUN_00458a10((const ::S00458a10_Vector *)&(kMotionVelocity), (const ::S00458a10_Vector *)&(kIntersectionOffset));
    hkSimdRealV kInv(1.0f / (fTime - ::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0062ab60::SettingV *>(&::originalRuntimeFloatSetting676))))));
    reinterpret_cast<::S_00627920 *>(&(kNewVelocity))->FUN_00627920((::S_00561240 *)&(kInv));
    reinterpret_cast<::Owner *>((((::fnv_0062ab60::MotionV *)(::FUN_004ae750((void *)(pkBody))))))->FUN_00ca85f0((unsigned int)&(kNewVelocity));
    hkVector4V kWorldPosition;
    reinterpret_cast<::S00458a10_Vector *>(&(kWorldPosition))->FUN_00458a10((const ::S00458a10_Vector *)&(kMotionVelocity), (const ::S00458a10_Vector *)&(kIntersectionOffset));
    reinterpret_cast<::S0062aea0_Vector *>(&(kWorldPosition))->FUN_0062aea0();
    hkSimdRealV kStep(1.5f);
    reinterpret_cast<::S_00627920 *>(&(kWorldPosition))->FUN_00627920((::S_00561240 *)&(kStep));
    reinterpret_cast<::V *>(&(kWorldPosition))->FUN_00553f70((const ::V &)((*(const ::fnv_0062ab60::hkVector4V *)&(::fnv_00560d80::FUN_00560d80((void *)(pkBody))))));
    reinterpret_cast<::S *>((pkBody))->FUN_00561690((int)&(kWorldPosition));
    pkEntry->m_fTime = fTime - ::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0062ab60::SettingV *>(&::originalRuntimeFloatSetting676))));
    pkEntry->m_iArrayLength--;
    if (pkEntry->m_iArrayLength <= 0)
    {
        delete pkEntry;
        reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::fnv_0062ab60::SmoothListV *>(&::g_011cc408))))->FUN_00905330((::InventoryStackRecord *const &)(pkEntry));
    }
}
}  // namespace fnv_0062ab60

struct hkVector4
{
    __m128 m_vComponents;
    hkVector4();
};


// @fnv 0x0062ba80
void FUN_0062ba80(void* obj, const NiPoint3& pos, bool flag)
{
    hkVector4 v;
    ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(v), (const ::fnv_004a3e00::NiPoint3 &)(pos));
    ::FUN_0062bae0((::Object62BAE0 *)(obj), (::Point62BAE0 *)&(v), flag);
}

struct Vector62BAE0
{
    Vector62BAE0();
    __m128 m_vComponents;
};
struct Point62BAE0
{
    float& FUN_00560d30(int i);
};
struct WorldObject62BAE0
{
};
struct Collision62BAE0
{
};
struct Node62BAE0;
struct Object62BAE0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node62BAE0* GetAsNode();
};
struct Node62BAE0 : public Object62BAE0
{
    unsigned int FUN_0043b480();
};

// @fnv 0x0062bae0
void __cdecl FUN_0062bae0(Object62BAE0* pkObject, Point62BAE0* pkPoint, bool bLocal)
{
    if (pkObject)
    {
        Collision62BAE0* pkCollision = ((::Collision62BAE0 *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(pkObject))));
        if (pkCollision)
        {
            WorldObject62BAE0* pkWorldObject = ((::WorldObject62BAE0 *)(::fnv_006fa820::FUN_006fa820((const char *)(pkCollision))));
            if (pkWorldObject)
            {
                Vector62BAE0 kVector;
                reinterpret_cast<::bhkUnaryAction *>(&(kVector))->Set(reinterpret_cast<::bhkCharacterController *>((pkPoint))->GetVectorElement(0), reinterpret_cast<::bhkCharacterController *>((pkPoint))->GetVectorElement(1), reinterpret_cast<::bhkCharacterController *>((pkPoint))->GetVectorElement(2), 0.0f);
                if (!bLocal)
                    reinterpret_cast<::V *>(&(kVector))->FUN_00553f70((*(const ::V *)(reinterpret_cast<::FUN_00560e10_cls *>((pkWorldObject))->FUN_00560e10())));
                reinterpret_cast<::fnv_005617c0::FUN_005617c0_ *>((pkWorldObject))->FUN_005617c0((int)&(kVector));
            }
        }
        Node62BAE0* pkNode = pkObject->GetAsNode();
        if (pkNode)
        {
            for (unsigned int i = 0; i < pkNode->FUN_0043b480(); i++)
            {
                Object62BAE0* pkChild = ((::Object62BAE0 *)(reinterpret_cast<::NiNode *>((pkNode))->GetAt(i)));
                FUN_0062bae0(pkChild, pkPoint, bLocal);
            }
        }
    }
}

namespace fnv_00631ab0 {
struct xAutoMem
{
    xAutoMem(int, bool, const char*, int);
    ~xAutoMem();
    int m_iWordAt00;
};
struct xFilter
{
    xFilter(int);
    unsigned int m_uiFilterValue;
};
struct xCinfoSub
{
    int m_q[12];
};
struct __declspec(align(16)) xCinfo
{
    xCinfo();
    ~xCinfo();
    unsigned int m_uiFilterInfo;
    int m_pCollisionShape;
    int m_pad08[6];
    xCinfoSub m_20;
    int m_pad50[4];
};
struct xNiAlloc
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct xShape : xNiAlloc
{
    xShape(float, bool);
    int m_auiShapeKeys[5];
};
struct xBody : xNiAlloc
{
    xBody(xCinfo*);
    int m_auiShapeKeys[6];
};
struct xPtr
{
    void FUN_0066b0d0(void*);
    int m_iWordAt00;
};
struct xCaster
{
    xPtr m_iWordAt00;
    bool m_iWordAt04;
    unsigned int m_8;
    void FUN_00631ab0(float afRadius, unsigned int auiLayer);
};
// @fnv 0x00631ab0
void xCaster::FUN_00631ab0(float afRadius, unsigned int auiLayer)
{
    xAutoMem MEM(0x10, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Havok\\ViewCaster.cpp", 0x49);
    xShape* SHAPE = new xShape(afRadius, true);
    xCinfo CINFO;
    xFilter FILTER(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(FILTER))->FUN_004a39f0(0x28);
    reinterpret_cast<::FUN_0059ce80_shell *>(&(FILTER))->FUN_0059ce80(auiLayer);
    m_8 = auiLayer;
    CINFO.m_uiFilterInfo = ((unsigned int)(::FUN_00559450((int *)&(FILTER))));
    CINFO.m_pCollisionShape = ::FUN_004ae750(SHAPE);
    reinterpret_cast<::FUN_0056e120_shell *>(&(CINFO.m_20))->FUN_0056e120();
    m_iWordAt00.FUN_0066b0d0(new xBody(&CINFO));
    m_iWordAt04 = true;
}
}  // namespace fnv_00631ab0

class S00632b40_Vector
{
  public:
    S00632b40_Vector();                                      // FUN_006815c0
    S00632b40_Vector(const S00632b40_Vector& v);             // FUN_004a3c90
    S00632b40_Vector& operator=(const S00632b40_Vector& v);  // FUN_004a3f10
    __m128 m_vComponents;
};

class S00632b40_Rotation
{
  public:
    S00632b40_Rotation();  // FUN_0056df00
    S00632b40_Vector m_kColumn0;
    S00632b40_Vector m_kColumn1;
    S00632b40_Vector m_kColumn2;
};

class FUN_00632b40 : public S00632b40_Rotation
{
  public:
    FUN_00632b40(const FUN_00632b40& t);
      // FUN_004b4cf0

    S00632b40_Vector m_vTranslation;
};

// @fnv 0x00632b40
FUN_00632b40::FUN_00632b40(const FUN_00632b40& t)
{
    S00632b40_Vector c0((*(::S00632b40_Vector *)(reinterpret_cast<::FUN_004b4cf0_shell *>((void *)&(t))->FUN_004b4cf0(0))));
    S00632b40_Vector c1((*(::S00632b40_Vector *)(reinterpret_cast<::FUN_004b4cf0_shell *>((void *)&(t))->FUN_004b4cf0(1))));
    S00632b40_Vector c2((*(::S00632b40_Vector *)(reinterpret_cast<::FUN_004b4cf0_shell *>((void *)&(t))->FUN_004b4cf0(2))));
    S00632b40_Vector c3((*(::S00632b40_Vector *)(reinterpret_cast<::FUN_004b4cf0_shell *>((void *)&(t))->FUN_004b4cf0(3))));
    reinterpret_cast<::AlignedVector *>((void *)&(const ::S00632b40_Vector &)((*(::S00632b40_Vector *)(reinterpret_cast<::FUN_004b4cf0_shell *>((void *)this)->FUN_004b4cf0(0)))))->FUN_004a3f10((const ::AlignedVector &)(c0));
    reinterpret_cast<::AlignedVector *>((void *)&(const ::S00632b40_Vector &)((*(::S00632b40_Vector *)(reinterpret_cast<::FUN_004b4cf0_shell *>((void *)this)->FUN_004b4cf0(1)))))->FUN_004a3f10((const ::AlignedVector &)(c1));
    reinterpret_cast<::AlignedVector *>((void *)&(const ::S00632b40_Vector &)((*(::S00632b40_Vector *)(reinterpret_cast<::FUN_004b4cf0_shell *>((void *)this)->FUN_004b4cf0(2)))))->FUN_004a3f10((const ::AlignedVector &)(c2));
    reinterpret_cast<::AlignedVector *>((void *)&(const ::S00632b40_Vector &)((*(::S00632b40_Vector *)(reinterpret_cast<::FUN_004b4cf0_shell *>((void *)this)->FUN_004b4cf0(3)))))->FUN_004a3f10((const ::AlignedVector &)(c3));
}

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator*(float f) const;
    NiPoint3 operator+(const NiPoint3& k) const;
public:
    float ComputeMagnitude() const;
};
// @fnv 0x006214d0
bool xCaster::FUN_006214d0(xRef* apRef, const xP3& akPos, float afA, float afB)
{
    bool RESULT = false;
    xVec4 POSV;
    xVec4 DIRV;
    if (reinterpret_cast<::DummyFlagsShell *>((apRef))->FUN_00621240() && (*reinterpret_cast<::xPlayer * *>(&::_g_thePlayer)) && ((::xMid *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::xPlayer * *>(&::_g_thePlayer))))->GetBaseTexture())) &&
        ((::xMid *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::xPlayer * *>(&::_g_thePlayer))))->GetBaseTexture()))->FUN_6d4())
    {
        xP3 DIFF = akPos - *((const ::xP3 *)(::FUN_0045bb80((int)(((::xMid *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::xPlayer * *>(&::_g_thePlayer))))->GetBaseTexture()))->FUN_6d4()))));
        if (reinterpret_cast<::NiPoint3 *>((void *)&(DIFF))->ComputeMagnitude() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011cc188)))))))
            RESULT = true;
        return RESULT;
    }
    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&POSV)), (const ::fnv_004a3e00::NiPoint3 &)(akPos));
    reinterpret_cast<::AlignedVector *>(&(DIRV))->FUN_004a3f10((*(const ::AlignedVector *)(reinterpret_cast<::NiObject *>((apRef))->FUN_00621a40())));
    xBody* BODY = 0;
    if (apRef == ((void *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(((*reinterpret_cast<::xPlayer * *>(&::_g_thePlayer))))->FUN_009306d0())))
    {
        BODY = ((::xBody *)(::FUN_00559450((int *)&(m_iWordAt00))));
        if (reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::xVec4 &)((*(::xVec4 *)(reinterpret_cast<::Holder *>((void *)&(POSV))->FUN_00458700((::Holder *)(2), {})))))->FUN_004586d0() > reinterpret_cast<::S004586d0_Obj *>((void *)(void *)&(const ::xVec4 &)((*(::xVec4 *)(reinterpret_cast<::Holder *>((void *)&(DIRV))->FUN_00458700((::Holder *)(2), {})))))->FUN_004586d0())
        {
            reinterpret_cast<::bhkCharacterController *>(&(POSV))->GetVectorElement(2) -= ::FUN_004a3e90(afB);
            reinterpret_cast<::bhkCharacterController *>(&(DIRV))->GetVectorElement(2) -= ::FUN_004a3e90(afB);
        }
    }
    else
        BODY = ((::xBody *)(::FUN_00559450((int *)&(m_iWordAt04))));
    xEvent EV;
    xCollector COL;
    reinterpret_cast<::FUN_006218d0_Class *>(&(EV))->FUN_006218d0(0.0f);
    xModelPtr* WMODEL = ((::xModelPtr *)(reinterpret_cast<::FUN_0043b560_shell *>((BODY))->GetSourceFilesFromObject()));
    xModelPtr* SMODEL = ((::xModelPtr *)(::FUN_00460140((int)(((::xSrc *)(reinterpret_cast<::ObjHelper *>((apRef))->FUN_00621a90()))))));
    xCaster2* CAST = apRef->FUN_00621ad0();
    if (CAST)
    {
        reinterpret_cast<::S219c0 *>((CAST))->DestroyDate();
        xEffect* EFF = ((::xEffect *)(reinterpret_cast<::EffectSetting *>((((::xEffItem *)(reinterpret_cast<::ScriptLocals *>((CAST))->GetLocalData()))))->GetCastSound()));
        reinterpret_cast<::S219c0 *>((CAST))->DestroyDate();
        if (EFF)
        {
            reinterpret_cast<::FUN_00537e90 *>(&(EV.m_iWordAt00))->SetQuantity((unsigned int)EFF);
            reinterpret_cast<::S219c0 *>((CAST))->DestroyDate();
            reinterpret_cast<::FUN_00537e90 *>(&(EV.m_iThirdValue))->SetQuantity(reinterpret_cast<::TESPackage *>((((::xEffItem *)(reinterpret_cast<::ScriptLocals *>((CAST))->GetLocalData()))))->GetRefCount());
            reinterpret_cast<::S219c0 *>((CAST))->DestroyDate();
            reinterpret_cast<::FUN_006219f0_Class *>((BODY))->FUN_006219f0((::hkpRigidBody *)(::xVec4 *)(&POSV));
            xMotion* MOTION = ((::xMotion *)(::GetStringCStr((::Dummy_004ae6c0 *)(BODY))));
            xCastFn FN =
                ((void (*)(xModelPtr *, xModelPtr *, xEvent *, xCollector *))(reinterpret_cast<::FUN_006218f0_Owner *>((EFF))->GetIndexedValue((int)(((::xNode *)(::fnv_0043b230::FUN_0043b230((const char *)(((::xModel *)(::FUN_00559450((int *)(WMODEL))))))))), (int)(((::xNode *)(::fnv_0043b230::FUN_0043b230((const char *)(((::xModel *)(::FUN_00559450((int *)(SMODEL))))))))))));
            if (FN)
            {
                float SAVED = reinterpret_cast<::FUN_00621b00_shell *>((MOTION))->FUN_00621b00();
                reinterpret_cast<::FUN_00621b20_Class *>((MOTION))->FUN_00621b20(afA);
                FN(WMODEL, SMODEL, &EV, &COL);
                RESULT = reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::xTag &)((*(::xTag *)(reinterpret_cast<::Hld621210 *>(&(COL))->FUN_00621210({})))))->FUN_005609f0();
                reinterpret_cast<::FUN_00621b20_Class *>((MOTION))->FUN_00621b20(SAVED);
            }
        }
    }
    return RESULT;
}
class InitFloats
{
  public:
    hkVector4 m_kTo;
    float m_fCoefficientA;
    float m_fB;

    InitFloats();
};
struct xHitFlag
{
    char c;
};
struct xHitRes
{
};
class ShapePhantom;
template <class T> class ShapeCastPointer
{
  public:
    T* m_pObject;
    T* FUN_00559450() const;
};
class ShapePhantom
{
  public:
};

class ShapeCaster
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void Reset2();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    ShapeCastPointer<ShapePhantom> m_spWorld;
    bool FUN_00626b30(const NiPoint3& kFrom, const NiPoint3& kWorldPosition, float fDist);
};

// @fnv 0x00626b30
bool ShapeCaster::FUN_00626b30(const NiPoint3& kFrom, const NiPoint3& kWorldPosition, float fDist)
{
    NiPoint3 qfTOqo = kFrom + kWorldPosition * fDist;
    reinterpret_cast<::FUN_00626da0_Class *>(this)->FUN_00626da0();
    if (((::ShapePhantom *)(::FUN_00559450((int *)&(m_spWorld)))))
    {
        hkVector4 qxQHW;
        InitFloats qAhbO;
        qAhbO.m_fB = 0.0099999998f;
        qAhbO.m_fCoefficientA = 0.0099999998f;
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&qxQHW)), (const ::fnv_004a3e00::NiPoint3 &)(kFrom));
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&qAhbO)), (const ::fnv_004a3e00::NiPoint3 &)(qfTOqo));
        Reset2();
        reinterpret_cast<::ScriptX *>((((::ShapePhantom *)(::FUN_00559450((int *)&(m_spWorld))))))->InvokeInterfaceCall((int)(&qxQHW), (int)(&qAhbO), (int)(this), 0);
        xHitFlag qArxcFu;
        if (reinterpret_cast<::FUN_005609f0_shell *>((((::xHitRes *)(reinterpret_cast<::Hld621210 *>(this)->FUN_00621210((::Rcv621210 *)(::xHitFlag *)(&qArxcFu))))))->FUN_005609f0())
        {
            reinterpret_cast<::SortableArray *>(this)->FUN_00cabad0();
            return true;
        }
    }
    else
        Reset2();
    return false;
}

extern "C" __m128 _mm_min_ps(__m128, __m128);


struct VecHolder
{
    __m128 m_uiFilterValue;

    void FUN_006285e0(const void* a, const void* b);
};

// @fnv 0x006285e0
void VecHolder::FUN_006285e0(const void* a, const void* b)
{
    m_uiFilterValue = _mm_min_ps(*((const ::__m128 *)(new ((void *)(a)) ::Vec3())), *((const ::__m128 *)(new ((void *)(b)) ::Vec3())));
}

extern "C" __m128 __cdecl _mm_set_ss(float);
extern "C" __m128 __cdecl _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 __cdecl _mm_rsqrt_ss(__m128);
extern "C" __m128 __cdecl _mm_mul_ss(__m128, __m128);
extern "C" __m128 __cdecl _mm_sub_ss(__m128, __m128);
extern "C" __m128 __cdecl _mm_andnot_ps(__m128, __m128);


struct Vec
{
    __m128 q;
    Vec* FUN_004a3c90(const Vec* src);
    Vec* FUN_0062b0a0(Vec* out, Vec* other);
    Vec* FUN_0062af00(Vec* target);
};

// @fnv 0x0062af00
Vec* Vec::FUN_0062af00(Vec* target)
{
    __m128 first = _mm_set_ss(::fnv_00c88020::DAT_01016248);
    __m128 second = _mm_set_ss(::DAT_01017718);
    __m128 third = _mm_set_ss(::DAT_01011d78);
    Vec local;
    __m128 value = *((const ::__m128 *)(new ((void *)(FUN_0062b0a0(&local, this))) ::Vec3()));
    __m128 mask = _mm_cmpeq_ss(value, third);
    __m128 reciprocal = _mm_rsqrt_ss(value);
    __m128 multiply = _mm_mul_ss(_mm_mul_ss(first, reciprocal),
                                 _mm_sub_ss(second, _mm_mul_ss(_mm_mul_ss(value, reciprocal), reciprocal)));
    new ((void *)(target)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)((const Vec*)&_mm_andnot_ps(mask, multiply))));
    return target;
}

extern "C" __m128 _mm_max_ps(__m128, __m128);

class S00628640_Source
{
  public:
};

struct S00628640_Vector
{
    __m128 m_vComponents;
    void FUN_00628640(const S00628640_Source* a, const S00628640_Source* b);
};
// @fnv 0x006286f0
void Main_006286f0::FUN_006286f0()
{
    Box_006286f0 box;
    VMin_006286f0 mn;
    VMin_006286f0 mx;
    reinterpret_cast<::FUN_004589c0_cls *>(&(mx))->FUN_004589c0(::DAT_0104e148);
    reinterpret_cast<::FUN_004589c0_cls *>(&(mn))->FUN_004589c0(::DAT_0104da48);
    for (unsigned int i = 0; i < 6; i++)
    {
        Box_006286f0 b;
        reinterpret_cast<::S006288c0_Object *>(((sources[i]).operator->()))->FUN_006288c0((::S006288c0_Bounds *)(::Box_006286f0 *)(&b));
        reinterpret_cast<::S00628640_Vector *>(&(mx))->FUN_00628640((const ::S00628640_Source *)&(mx), (const ::S00628640_Source *)&(b.hi));
        reinterpret_cast<::VecHolder *>(&(mn))->FUN_006285e0((const void *)&(mn), (const void *)&(b));
    }
    reinterpret_cast<::AlignedVector *>(&(box.lo))->FUN_004a3f10((const ::AlignedVector &)(mn));
    reinterpret_cast<::AlignedVector *>(&(box.hi))->FUN_004a3f10((const ::AlignedVector &)(mx));
    Obj_006286f0* obj = unk20;
    Node_006286f0* node = ((::Node_006286f0 *)(reinterpret_cast<::FUN_004543c0_cls *>((obj))->FUN_004543c0()));
    Shape_006286f0* shape = node ? ((::Shape_006286f0 *)(reinterpret_cast<::ScriptLocals *>((node))->GetLocalData())) : 0;
    if (shape)
    {
        float* p28 = shape->unk28;
        float* p34 = shape->unk34;
        unsigned int kind = ((unsigned int)(reinterpret_cast<::FUN_006288a0_Class *>((shape))->GetOffset110()));
        reinterpret_cast<::FUN_00628df0_class *>(this)->FUN_00628df0((::Arg1 *)(::Box_006286f0 *)(&box), (::Arg2 *)(kind), (::Arg3 *)(shape));
        reinterpret_cast<::Owner628980 *>(this)->FUN_00628980((::Filter628980 *)(::Box_006286f0 *)(&box), (::List628980 *)(p28));
        reinterpret_cast<::Owner628980 *>(this)->FUN_00628980((::Filter628980 *)(::Box_006286f0 *)(&box), (::List628980 *)(p34));
    }
}
// @fnv 0x006281d0
bool SpawnAreaB::FUN_006281d0(TESObjectREFRB* pkRef, GridB* pkGrid, hkAabbB* pkOut)
{
    bool bResult = false;
    RootB* pkRoot = ((::RootB *)(reinterpret_cast<::FUN_004543c0_cls *>((pkRef))->FUN_004543c0()));
    Node3DB* pk3D = pkRoot ? ((::Node3DB *)(reinterpret_cast<::ScriptLocals *>((pkRoot))->GetLocalData())) : 0;
    if (pk3D)
    {
        hkAabbB kAabb;
        hkVector4B kMinBoundsCur;
        hkVector4B kMaxPoint;
        reinterpret_cast<::FUN_004589c0_cls *>(&(kMaxPoint))->FUN_004589c0(-3.40282e38f);
        reinterpret_cast<::FUN_004589c0_cls *>(&(kMinBoundsCur))->FUN_004589c0(3.40282e38f);
        if (reinterpret_cast<::TESObjectCELL *>((pkRef))->IsCellInterior())
        {
            SkeletonB* pkSkeleton = ((::SkeletonB *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pk3D))->FUN_007af430()));
            PartListB* pkParts = ((::PartListB *)(reinterpret_cast<::FUN_00624700_shell *>((pkSkeleton))->FUN_00624700()));
            for (int i = 0; i < ((int)(reinterpret_cast<::Callees *>((pkParts))->FUN_00726070())); i++)
            {
                bhkCollisionB* pkCollision = ((::bhkCollisionB *)(::FUN_00460140((int)((*((::PartB **)&(reinterpret_cast<::FUN_00629ab0_shell *>((pkParts))->FUN_00629ab0(i))))))));
                if (((NiPointerB*)pkCollision)->operator->())
                {
                    bhkWorldB* pkWorld = ((::bhkWorldB *)(reinterpret_cast<::LowProcess *>((pk3D))->GetPackageObjectType()));
                    pkWorld->AddAabb(((void *)(reinterpret_cast<::NonActorMagicTarget *>((pkCollision))->GetActiveEffectList())));
                    reinterpret_cast<::S00628640_Vector *>(&(kMaxPoint))->FUN_00628640((const ::S00628640_Source *)&(kMaxPoint), (const ::S00628640_Source *)&(kAabb.m_kMaximumCorner));
                    reinterpret_cast<::VecHolder *>(&(kMinBoundsCur))->FUN_006285e0((const void *)&(kMinBoundsCur), (const void *)&(kAabb.m_kMinimumCorner));
                }
            }
        }
        else if (pkGrid)
        {
            unsigned int uiSize = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkGrid))->FUN_0084e3a0()));
            for (unsigned int i = 0; i < uiSize; i++)
            {
                for (unsigned int j = 0; j < uiSize; j++)
                {
                    CellB** ppkCell = ((::CellB **)(reinterpret_cast<::GridCellArray *>((pkGrid))->Get(i, j)));
                    if (*ppkCell)
                    {
                        CellObjectB* pkObject = ((::CellObjectB *)(::GetCellMopp((char *)((*ppkCell)))));
                        BodyListB* pkBodies = ((::BodyListB *)(reinterpret_cast<::TESTopicInfoData *>((pkObject))->GetLinkToList()));
                        for (unsigned int k = 0; k < reinterpret_cast<::FUN_00658930_class *>((pkBodies))->GetShortAtOffsetA(); k++)
                        {
                            bhkCollisionB* pkCollision = ((::bhkCollisionB *)(reinterpret_cast<::FUN_0043b560_shell *>((((::bhkRigidBodyB *)(::FUN_00559450((int *)(pkBodies->GetAt(k)))))))->GetSourceFilesFromObject()));
                            if (((NiPointerB*)pkCollision)->operator->())
                            {
                                bhkRigidBodyB* pkBody = ((::bhkRigidBodyB *)(::FUN_00559450((int *)(pkBodies->GetAt(k)))));
                                if (pkBody->IsFixed())
                                {
                                    bhkWorldB* pkWorld = ((::bhkWorldB *)(reinterpret_cast<::LowProcess *>((pk3D))->GetPackageObjectType()));
                                    pkWorld->AddAabb(((void *)(reinterpret_cast<::NonActorMagicTarget *>((pkCollision))->GetActiveEffectList())));
                                }
                                else
                                {
                                    hkTransformB kTransform;
                                    bhkRigidBodyB* pkRigid = ((::bhkRigidBodyB *)(::FUN_00559450((int *)(pkBodies->GetAt(k)))));
                                    pkRigid->GetTransform(&kTransform);
                                    bhkShapeB* pkShape = ((::bhkShapeB *)(reinterpret_cast<::FUN_00620b80_shell *>((((::ShapeOwnerB *)(reinterpret_cast<::FUN_004ae6a0_shell *>((((::bhkRigidBodyB *)(::FUN_00559450((int *)(pkBodies->GetAt(k)))))))->FUN_004ae6a0()))))->GetReferenceFlags()));
                                    reinterpret_cast<::FUN_006286a0_Holder *>((pkShape))->ForwardToTarget((int)(&kTransform), 0.1f, (int)(&kAabb));
                                }
                                reinterpret_cast<::S00628640_Vector *>(&(kMaxPoint))->FUN_00628640((const ::S00628640_Source *)&(kMaxPoint), (const ::S00628640_Source *)&(kAabb.m_kMaximumCorner));
                                reinterpret_cast<::VecHolder *>(&(kMinBoundsCur))->FUN_006285e0((const void *)&(kMinBoundsCur), (const void *)&(kAabb.m_kMinimumCorner));
                            }
                        }
                    }
                }
            }
        }
        reinterpret_cast<::AlignedVector *>(&(pkOut->m_kMinimumCorner))->FUN_004a3f10((*(const ::AlignedVector *)(&kMinBoundsCur)));
        reinterpret_cast<::AlignedVector *>(&(pkOut->m_kMaximumCorner))->FUN_004a3f10((*(const ::AlignedVector *)(&kMaxPoint)));
        bResult = reinterpret_cast<::bhkCharacterController *>((void *)&(const ::hkVector4B &)(kMaxPoint))->GetVectorElement(0) != (double)-3.40282e38f && reinterpret_cast<::bhkCharacterController *>((void *)&(const ::hkVector4B &)(kMinBoundsCur))->GetVectorElement(0) != (double)3.40282e38f;
    }
    return bResult;
}

// @fnv 0x00628640
void S00628640_Vector::FUN_00628640(const S00628640_Source* a, const S00628640_Source* b)
{
    m_vComponents = _mm_max_ps(*((const ::__m128 *)(new ((void *)(a)) ::Vec3())), *((const ::__m128 *)(new ((void *)(b)) ::Vec3())));
}

namespace N {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    unsigned __int32 m128_u32[4];
};
extern "C"
{
    __m128 _mm_and_ps(__m128, __m128);
}
}

struct S_00628cc0_Class
{
    N::__m128 unk00;

    void FUN_00628cc0(N::__m128* arg1, N::__m128* arg2);
};

// @fnv 0x00628cc0
void S_00628cc0_Class::FUN_00628cc0(N::__m128* arg1, N::__m128* arg2)
{
    unk00 = N::_mm_and_ps(*arg1, *arg2);
}
