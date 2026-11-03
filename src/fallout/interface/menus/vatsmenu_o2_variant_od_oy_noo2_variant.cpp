
// src/fallout/interface/menus/vatsmenu_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF /Oy- (unit src/fallout/interface/menus/vatsmenu_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/interface/menus/vatsmenu_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/menus/vatsmenu.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include <new>
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CameraWindowRay.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_0070ec70_class.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S50.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/VatsQueueText__VATSMenuQueue.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_004a3f90__T_.h"
#include "fnv/decl/fnv_007f07a0__Owner7.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_007eb000.h"
#include "fnv/symbols_007f3000.h"
#include "fnv/symbols_007f4000.h"
#include "fnv/symbols_007f6000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "vatsmenu_decls.h"
struct ItemListElement;
struct ItemList
{
    void FUN_0063f7b0();
};
struct ItemListContainer
{
    char pad[8];
    ItemList items;
    ~ItemListContainer();
};
struct TargetList
{
    void FUN_0063f7b0();
};
struct GlobalObject2_0096a2d0
{
    int x;
};
struct FUN_007ebd30_This
{
    char pad[0x374];
    float fValue;
    float FUN_007ebd30();
};
struct ArrSI
{
};
struct Caller007efa10
{
};
struct FUN_007ef710_This
{
    char _pad[0xF8];
    bool m_bFirstFlag;
    bool HandleKey(int aiKey);
};
struct Tile;
struct FUN_0070ec70_This
{
};
struct FUN_007ef760_Owner
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(int, int);
    void FUN_007ef760(int aiID, Tile* apTarget);
};
struct Vec2Tmp
{
    float x;
    float y;
    Vec2Tmp DivideBy(float) const;
};
struct TESObjectREFR
{
};
struct BSSimpleList
{
    bool FUN_008256d0();
};
struct StandIn
{
    BSSimpleList* FindListEntryForTarget(TESObjectREFR* apTarget);
};
struct Tile;
struct Menu
{
};
struct Tile;
struct AnimIdle
{
};
class GameTimerRecord
{
    char _d;
};
struct DAT_Pointee_7f4bb0
{
    char pad[0x10F];
    unsigned char flag;
    char pad2[4];
    int t;
};
struct Tile;
struct ListBox
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile* v5(int);
    Tile* FUN_007f6fb0();
};

struct NiPoint3
{
};

struct __declspec(align(16)) B006815c0
{
    char pad[16];
    B006815c0();
};


class Class_007f68a0
{
  public:
    void FUN_007f68a0(const NiPoint3& pt);
};

// @fnv 0x007f68a0
void Class_007f68a0::FUN_007f68a0(const NiPoint3& pt)
{
    B006815c0 vec;
    reinterpret_cast<::fnv_004a3f90::T_ *>(this)->ForwardToSubObject(((::B006815c0 *)&(::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&vec)), (const ::fnv_004a3e00::NiPoint3 &)(pt)))));
}

struct Point007f6af0
{
    float x, y, z;
    Point007f6af0();
    Point007f6af0 operator*(float) const;
};
struct Quest007f6af0
{
};
struct Light007f6af0
{
};
struct Anim007f6af0
{
};
struct Node007f6af0
{
};
extern float DAT_011a0b74;
struct Filter007f6af0
{
    int field_00;
    Filter007f6af0()
    {}
    Filter007f6af0(int);
    unsigned FUN_004a3a20();
};
struct Hit007f6af0
{
    int field_00[20];
    void* field_50;
    int field_54[3];
};
struct Hits007f6af0
{
};
struct Response007f6af0
{
};
struct __declspec(align(16)) Collector007f6af0
{
    int field_00[198];
    Collector007f6af0();
    virtual ~Collector007f6af0();
};
struct __declspec(align(16)) Ray007f6af0
{
    char field_00[176];
    Ray007f6af0();
    void FUN_004a3f70(int);
};
struct World007f6af0
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
    virtual void v50(Ray007f6af0*);
};
struct PlayerFilter007f6af0
{
    int field_00;
    unsigned FUN_004a3a20();
};
struct Player007f6af0
{
    void FUN_00931ed0(PlayerFilter007f6af0*);
};
struct Owner007f6af0
{
    char field_00[0x10e];
    unsigned char field_10e;
};
// @fnv 0x007f6af0
bool FUN_007f6af0(Owner007f6af0* self)
{
    if (self->field_10e)
        return false;
    float distance = DAT_011a0b74;
    Point007f6af0 origin;
    Point007f6af0 direction;
    reinterpret_cast<::CameraWindowRay *>((((::Anim007f6af0 *)(reinterpret_cast<::BSFaceGenNiNode *>((((::Node007f6af0 *)(::FUN_0045c670()))))->GetAnimationData()))))->MapScreenToRay((int)reinterpret_cast<::BGSImpactData *>((((Light007f6af0*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_009a9350(),
                                                   (int)reinterpret_cast<::FUN_00792760_shell *>((((Quest007f6af0*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00792760(), (*(::NiPoint3 *)(&origin)),
                                                   (*(::NiPoint3 *)(&direction)), (const ::NiRenderTargetGroup *)(0));
    Ray007f6af0 ray;
    unsigned int mask = 0x140;
    ::ShadowLightData::SetTargetMaskForSelection(0x27, mask);
    PlayerFilter007f6af0 playerFilter;
    (*reinterpret_cast<::Player007f6af0 * *>(&::_g_thePlayer))->FUN_00931ed0(&playerFilter);
    Filter007f6af0 filter(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(filter))->FUN_004a39f0(0x27);
    reinterpret_cast<::FUN_0059ce80_shell *>(&(filter))->FUN_0059ce80(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(playerFilter))->FUN_004a3a20());
    ray.FUN_004a3f70(filter.field_00);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(ray))->FUN_004a3da0(&origin);
    reinterpret_cast<::Class_007f68a0 *>(&(ray))->FUN_007f68a0((const ::NiPoint3 &)((const ::Point007f6af0 &)(direction * distance)));
    Collector007f6af0 collector;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(ray))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::Collector007f6af0 *)(&collector));
    World007f6af0* world = ((::World007f6af0 *)(reinterpret_cast<::FUN_004543c0_cls *>((((void *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::Player007f6af0 * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
    world->v50(&ray);
    int unused = 0;
    for (int i = 0; i < ((int)(reinterpret_cast<::Callees *>((((::Hits007f6af0 *)(::FUN_00460140((int)(((::Response007f6af0 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->FUN_00726070())); ++i)
    {
        Hit007f6af0 hit;
        reinterpret_cast<::S50 *>(&(hit))->FUN_00696c30((::S50 *)(::Hit007f6af0 *)(((::Hit007f6af0 *)(reinterpret_cast<::FUN_004a46b0_class *>((((::Hits007f6af0 *)(::FUN_00460140((int)(((::Response007f6af0 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->GetEntryAt(i)))));
        void* object = ((void *)(::FUN_004b5820((::FormLike *)(hit.field_50))));
        TESObjectREFR* ref = ::FUN_0056f930((::NiAVObject *)(object));
        if (object)
        {
            BSSimpleList* entry = ((StandIn*)self)->FindListEntryForTarget(ref);
            if (entry && *(ItemListContainer**)*((::ItemListContainer **)(new ((void *)(entry)) ::Vec3())) == (*reinterpret_cast<::ItemListContainer * *>(&::DAT_011f21cc)))
            {
                return false;
            }
            else if (entry)
            {
                FUN_007f3bd0(0);
                reinterpret_cast<::fnv_007f07a0::Owner7 *>((self))->UpdateLimbHighlight();
                (*reinterpret_cast<::ItemListContainer * *>(&::DAT_011f21cc)) = *(ItemListContainer**)*((::ItemListContainer **)(new ((void *)(entry)) ::Vec3()));
                return true;
            }
            ref = 0;
        }
    }
    return false;
}
