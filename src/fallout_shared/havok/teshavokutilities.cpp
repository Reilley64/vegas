
// src/fallout_shared/havok/teshavokutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teshavokutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include <cstdint>
#include <new>
#include "fnv/decl/BSFadeNode.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043b5f0_cls.h"
#include "fnv/decl/FUN_004589c0_cls.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_005dbf20.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_00c7be20_cls.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/S0062aea0_Vector.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/V.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkFilter.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_0062c000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_00cb5000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0056ded0.h"
#include "fnv/decl/FUN_00c8d280_cls.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiPosData.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/WorldObject_c8d3.h"
#include "fnv/decl/_dummy_476a80.h"
#include "fnv/decl/fnv_00437c10__FUN_00437c10.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_004a3000.h"
struct FUN_006295a0_shell
{
    void FUN_006295a0();
};

// Calls FUN_004589c0 with DAT_0104da48 on this object and with DAT_0104e148 on the object at offset 0x10.
// @fnv 0x006295a0
void FUN_006295a0_shell::FUN_006295a0()
{
    reinterpret_cast<::FUN_004589c0_cls *>(this)->FUN_004589c0(::DAT_0104da48);
    reinterpret_cast<::FUN_004589c0_cls *>((((FUN_006295a0_shell*)((char*)this + 0x10))))->FUN_004589c0(::DAT_0104e148);
}

struct NiAVObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* GetAsNiNode();
};
struct NiObjectNET
{
};
struct NiNode : public NiAVObject
{
    NiAVObject* GetAt(unsigned int);
    unsigned int GetNumChildren();
};
struct bhkWorldObject
{
};
struct bhkCollisionObject
{
    static bhkCollisionObject* GetFromNiAVObject(NiAVObject*);
};
float FUN_0062c300(NiAVObject* object);
// @fnv 0x0062c300
float FUN_0062c300(NiAVObject* object)
{
    float fmass = 0.0f;
    if (object)
    {
        bhkCollisionObject* pCollisionObject = bhkCollisionObject::GetFromNiAVObject(object);
        bhkWorldObject* pWorldObject = pCollisionObject ? ((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(pCollisionObject)))) : 0;
        if (pWorldObject)
            fmass += ::FUN_004b5400((void *)(pWorldObject));
        NiNode* pnode = (NiNode*)object->GetAsNiNode();
        if (pnode && pnode->GetNumChildren())
        {
            for (unsigned int i = 0; i < pnode->GetNumChildren(); ++i)
                fmass += FUN_0062c300(pnode->GetAt(i));
        }
    }
    return fmass;
}

struct CombatNode
{
};

struct FUN_0062be70_shell
{
    char pad[0x30];
    CombatNode m_node;
    void FUN_0062be70();
};

// @fnv 0x0062be70
void FUN_0062be70_shell::FUN_0062be70()
{
    reinterpret_cast<::Callees *>(&(m_node))->FUN_00726070();
}

struct TESObjectREFR
{
};

// @fnv 0x0062b4e0
TESObjectREFR* __cdecl FUN_0062b4e0(void* object)
{
    TESObjectREFR* result = 0;
    if (object)
    {
        void* reference = ((void *)(::FUN_00c7fa90((::S_Obj *)(object))));
        if (reference)
            result = ::FUN_0056f930((::NiAVObject *)(reference));
    }
    return result;
}

struct Setting_S
{
};
struct H0043b4d0
{
    int m_uiFilterValue;
    H0043b4d0();
};
struct W_0043b4f0
{
    H0043b4d0 FUN_0043b4f0();
};

// @fnv 0x0062b520
float FUN_0062b520(float value, bhkWorldObject* object, bool scale)
{
    if (!object)
        return value;
    float fMultiplier = 1.0f;
    H0043b4d0 layer = ((W_0043b4f0*)object)->FUN_0043b4f0();
    switch (reinterpret_cast<::FUN_0043b4d0_shell *>(&(layer))->FUN_0043b4d0())
    {
    case 14:
        fMultiplier *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1035))))));
        break;
    case 8:
    case 29:
        fMultiplier *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1036))))));
        break;
    case 10:
        fMultiplier *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1037))))));
        break;
    case 20:
        fMultiplier *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::g_011d0f30))))));
        break;
    default:
        fMultiplier *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::g_011d0d2c))))));
        break;
    }
    if (scale)
    {
        float f = FUN_004b5400(object);
        if (f < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1038)))))))
            fMultiplier *= f / *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1038))))));
    }
    fMultiplier *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1034))))));
    return fMultiplier * value;
}

struct FUN_0043b5b0_shell
{
    void FUN_0043b5b0();
};
struct TgtOps
{
};
struct FUN_0043b5f0_shell
{
};
struct FUN_0043b560_shell
{
    void* GetSourceFilesFromObject();
};
// Calls GetReferenceFlags on this, then if non-null runs FUN_0043b5b0, GetSourceFiles and FUN_0043b5f0, returning the source files pointer.
// @fnv 0x0043b560
void* FUN_0043b560_shell::GetSourceFilesFromObject()
{
    void* result = 0;
    {
        FUN_0043b5b0_shell* obj = reinterpret_cast<FUN_0043b5b0_shell*>(((int)(reinterpret_cast<::FUN_00620b80_shell *>((this))->GetReferenceFlags())));
        if (obj)
        {
            obj->FUN_0043b5b0();
            result = ((void *)(::FUN_00460140((std::intptr_t)(reinterpret_cast<TgtOps*>(obj)))));
            reinterpret_cast<::FUN_0043b5f0_cls *>((reinterpret_cast<FUN_0043b5f0_shell*>(obj)))->FUN_0043b5f0();
        }
    }
    return result;
}

struct FUN_0062bc10_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    void AttachTarget(int);
    unsigned int FUN_0043b480();
    void* FUN_0043b4a0(unsigned int);
};

// @fnv 0x0062bc10
void __cdecl FUN_0062bc10(FUN_0062bc10_obj* pObject)
{
    if (pObject != 0)
    {
        void* r = ((void *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((pObject))->FUN_006838b0()));
        if (r != 0)
        {
            pObject->AttachTarget(0);
        }
        if (pObject->v3() != 0)
        {
            FUN_0062bc10_obj* self = pObject;
            for (unsigned int i = 0; i < self->FUN_0043b480(); i++)
            {
                FUN_0062bc10((FUN_0062bc10_obj*)self->FUN_0043b4a0(i));
            }
        }
    }
}

struct ShapeContainer
{
    virtual void Reserved();
    virtual unsigned int Count();
};

struct CollisionShape
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
    virtual unsigned int Count();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ShapeContainer container;
    CollisionShape* GetChild();
};

struct ShapeWrapper
{
};

struct WorldShapeView : bhkWorldObject
{
};

struct ChildNodeView : NiNode
{
    unsigned int GetChildCount();
};

// Recursively walks an NiAVObject tree, adding collision shape counts to firstCount or secondCount depending on shape type.
// @fnv 0x0062bd00
void CountCollisionShapes(NiAVObject* object, unsigned int* firstCount, unsigned int* secondCount)
{
    if (object)
    {
        bhkCollisionObject* collision4 = bhkCollisionObject::GetFromNiAVObject(object);
        if (collision4)
        {
            bhkWorldObject* world7 = ((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(collision4))));
            if (world7)
            {
                ShapeWrapper* wrapper_2 = ((::ShapeWrapper *)(reinterpret_cast<::FUN_004ae6a0_shell *>((static_cast<WorldShapeView*>(world7)))->FUN_004ae6a0()));
                CollisionShape* shape5 = wrapper_2 ? ((::CollisionShape *)(reinterpret_cast<::FUN_00620b80_shell *>((wrapper_2))->GetReferenceFlags())) : 0;
                if (shape5)
                {
                    if (((int)(::fnv_0043b230::FUN_0043b230((const char *)(shape5)))) == 23)
                    {
                        CollisionShape* list7 = shape5;
                        *secondCount += list7->container.Count();
                    }
                    else if (((int)(::fnv_0043b230::FUN_0043b230((const char *)(shape5)))) == 6)
                    {
                        CollisionShape* collection = shape5;
                        *firstCount += collection->Count();
                    }
                    else if (((int)(::fnv_0043b230::FUN_0043b230((const char *)(shape5)))) == 10)
                    {
                        CollisionShape* parent = shape5;
                        CollisionShape* child9 = parent->GetChild();
                        if (child9)
                            *secondCount += child9->container.Count();
                    }
                }
            }
        }
        if (object->GetAsNiNode())
        {
            ChildNodeView* node5 = static_cast<ChildNodeView*>(object);
            for (unsigned int index2 = 0; index2 < node5->GetChildCount(); ++index2)
                CountCollisionShapes(node5->GetAt(index2), firstCount, secondCount);
        }
    }
}

class GameSettingCollection;
union SETTING_VALUE
{
    float f;
};
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting722;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting723;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting724;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting725;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting726;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting728;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting729;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting730;
class GlobalObject_0040e0b0
{
  public:
};
extern GlobalObject_0040e0b0 g_011cf600;
extern GlobalObject_0040e0b0 g_011cf2fc;
// Selects a factor and threshold from value against several float settings, then returns factor times a distance-scaled multiplier or zero.
// @fnv 0x0062be90
float __cdecl ComputeDistanceFactor(float value, float distance)
{
    float factor = 0.0f;
    float threshold = DAT_01013974;
    if (value < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting721))))->f)
        factor = 0.0f;
    else if (value < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting722))))->f)
    {
        factor = *((float *)&(::FUN_00403e20((float *)&(g_011cf600))));
        threshold = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting728))))->f;
    }
    else if (value < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting723))))->f)
    {
        factor = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting724))))->f;
        threshold = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting729))))->f;
    }
    else
    {
        factor = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting725))))->f;
        threshold = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting730))))->f;
    }
    float scale =
        distance > threshold ? *((float *)&(::FUN_00403e20((float *)&(g_011cf2fc)))) + distance * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting726))))->f : 0.0;
    return factor * scale;
}

class Owner62B;

class Target62B
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void SetOwner(Owner62B* pkOwner);

};

class Handle62B
{
  public:
    void Reset(void* pvObject);

    Target62B* m_pPointer;
};

class Owner62B
{
  public:
    void AttachTarget(void* pvTarget);

    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Handle62B m_kRoomNode;
};

// @fnv 0x0062bc90
void Owner62B::AttachTarget(void* pvTarget)
{
    m_kRoomNode.Reset(pvTarget);
    if (((::Target62B *)(::FUN_00559450((int *)&(m_kRoomNode)))) && ((::Owner62B *)(reinterpret_cast<::Twin_0044ddc0 *>((((::Target62B *)(::FUN_00559450((int *)&(m_kRoomNode))))))->GetName())) != this)
        ((::Target62B *)(::FUN_00559450((int *)&(m_kRoomNode))))->SetOwner(this);
}

struct BGSAcousticSpace;
struct SoundPlaybackManager
{
    static void __cdecl ResetAcousticSpace(BGSAcousticSpace*);
};
struct MapH
{
};
struct Ref
{
};
struct FUN_0061f890_shell
{
    char pad[0x18];
    MapH m_map;
    bool FUN_0061f890(NiAVObject* object, bool flag);
};
// @fnv 0x0061f890
bool FUN_0061f890_shell::FUN_0061f890(NiAVObject* object, bool flag)
{
    bool removed = reinterpret_cast<::NiTMap_S *>(&(m_map))->RemoveKey((unsigned int)object);
    if (removed && flag)
        SoundPlaybackManager::ResetAcousticSpace(((::BGSAcousticSpace *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((Ref*)object)))->FUN_007af430())));
    return removed;
}


class Refr62C3C0
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual bool vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual bool vfn22C(unsigned int unk);
    virtual bool vfn230();
};

// Returns true if refr is non-null and passes vfn100/vfn22C/vfn230 checks, or if GetBSXFlags(handle, 0x48) equals 0x48.
// @fnv 0x0062c3c0
bool FUN_0062c3c0(Refr62C3C0* refr, unsigned int handle)
{
    if (refr != 0 && refr->vfn100() && (refr->vfn22C(0) || refr->vfn230()))
    {
        return true;
    }
    if (GetBSXFlags(handle, 0x48) == 0x48)
    {
        return true;
    }
    return false;
}

#include <xmmintrin.h>
struct RuntimeNode;
struct Children;
struct CollisionInfo
{
    unsigned int filterFlags;
};
struct SceneNode
{
    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual Children* GetChildren();
};
struct Children
{
    unsigned int FUN_0043b480();
    SceneNode* FUN_0043b4a0(unsigned int at);
};
struct __declspec(align(16)) PhysicsTransform
{
    __m128 vector;
};
struct __declspec(align(16)) PhysicsData
{
    __m128 vector;
};
struct PhysicsState
{
};
struct PhysicsObject
{
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Unknown47();
    virtual void Unknown48();
    virtual void Unknown49();
    virtual void Unknown50();
    virtual void Unknown51();
    virtual void Unknown52();
    virtual void Unknown53();
    virtual void Unknown54();
    virtual void Unknown55();
    virtual void Unknown56();
    virtual void Unknown57();
    virtual void Unknown58();
    virtual void Unknown59();
    virtual void UpdateTransform(PhysicsTransform* out);
    CollisionInfo* FUN_0043b4f0(CollisionInfo* out);
};
struct RuntimeNode
{
};
struct MaterialSelector
{
    int form;
    int index;
    int family;
    int region;
    int kind;
};
extern float DAT_0119acc8[];
extern "C" RuntimeNode* __cdecl FUN_0043b610(SceneNode* node);

// Recursively updates the physics collision scale of a scene node and its children based on a size coefficient and material type.
// @fnv 0x0062b660
void __cdecl SetCollisionScale(SceneNode* node, unsigned int operation, float size, MaterialSelector* material)
{
    if (node)
    {
        RuntimeNode* runtime = FUN_0043b610(node);
        if (runtime)
        {
            PhysicsObject* body = ((::PhysicsObject *)(::fnv_006fa820::FUN_006fa820((const char *)(runtime))));
            if (body)
            {
                CollisionInfo collisionInfo;
                int code = reinterpret_cast<::bhkFilter *>((body->FUN_0043b4f0(&collisionInfo)))->FUN_006240b0();
                float coefficient = DAT_0119acc8[code];
                if (material && material->kind != -1)
                {
                    if ((material->kind == 1 || material->kind == 2) && code == 1)
                        coefficient = DAT_01016088;
                    if ((material->kind == 3 || material->kind == 4) && (code == 5 || code == 6 || code == 7))
                        coefficient = DAT_01016088;
                    if ((material->kind == 5 || material->kind == 6) && (code == 11 || code == 12 || code == 13))
                        coefficient = DAT_01016088;
                    if ((material->kind == 7 || material->kind == 8 || material->kind == 9) &&
                        (code == 8 || code == 9 || code == 10))
                        coefficient = DAT_01016088;
                    if ((material->kind == 10 || material->kind == 11 || material->kind == 12) &&
                        (code == 14 || code == 15 || code == 16))
                        coefficient = DAT_01016088;
                }
                float scale = size * coefficient;
                PhysicsTransform transform;
                body->UpdateTransform(&transform);
                reinterpret_cast<::V *>(&(transform))->FUN_00961190((*(const ::V *)(operation)));
                reinterpret_cast<::S0062aea0_Vector *>(&(transform))->FUN_0062aea0();
                PhysicsState* state = ((::PhysicsState *)(reinterpret_cast<::FUN_00620b80_shell *>((body))->GetReferenceFlags()));
                PhysicsData volume;
                new ((void *)&(volume)) ::FUN_005dbf20(scale);
                reinterpret_cast<::S_00627920 *>(&(transform))->FUN_00627920((::S_00561240 *)(void *)(&volume));
                reinterpret_cast<::V *>(&(transform))->FUN_00553f70((*(const ::V *)(::FUN_00560dc0((::TESDataHandler *)(state)))));
                reinterpret_cast<::FUN_005616d0_Owner *>((state))->OnTrigger((::TriggerContext *)(::PhysicsTransform *)(&transform));
            }
        }
        Children* children = node->GetChildren();
        if (children)
        {
            for (unsigned int i = 0; i < children->FUN_0043b480(); ++i)
            {
                SceneNode* child = children->FUN_0043b4a0(i);
                SetCollisionScale(child, operation, size, material);
            }
        }
    }
}

struct SeqArray;
struct Inner62c;
struct NiSeq;

struct Inner62c
{
};

struct NiSeq
{
};

struct SeqArray
{
    int m0;
    int m4;
    int m8;
    SeqArray();
    ~SeqArray();
};

struct UnkACobj
{
};

class VtObj
{
  public:
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
    virtual Inner62c* v116();

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
    UnkACobj* unkAC;
};


// Copies or collects entries into a local array, then compares each later entry’s owner and value with the first entry.
// @fnv 0x0062c430
void __cdecl FUN_0062c430(VtObj* apVtObj)
{
    if (apVtObj != 0)
    {
        SeqArray arr5;

        if (apVtObj->unkAC != 0)
            reinterpret_cast<::FUN_00c7be20_cls *>((apVtObj->unkAC))->CopySourceArray((::FUN_00c7be20_arr *)(::SeqArray *)(&arr5));
        else
            ::CollectTreeResultValues((::TreeNode_cls *)(::Inner62c *)(apVtObj->v116()), (::SpawnedPtrArray *)(::SeqArray *)(&arr5));

        if (((int)(reinterpret_cast<::Callees *>(&(arr5))->FUN_00726070())) != 0)
        {
            Inner62c* owner3 = ((::Inner62c *)(reinterpret_cast<::Twin_0044ddc0 *>((((::NiSeq *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(arr5))->FUN_00629ab0(0)))))->GetName()));

            if (owner3 != 0)
            {
                reinterpret_cast<::TESForm *>((owner3))->ClearData();

                for (int i = 1; i < ((int)(reinterpret_cast<::Callees *>(&(arr5))->FUN_00726070())); i++)
                {
                    unsigned int b;
                    unsigned int a2;
                    a2 = reinterpret_cast<::BSFadeNode *>((((::NiSeq *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(arr5))->FUN_00629ab0(0)))))->FUN_009ad610();
                    b = reinterpret_cast<::BSFadeNode *>((((::NiSeq *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(arr5))->FUN_00629ab0(i)))))->FUN_009ad610();
                    if (owner3 == ((::Inner62c *)(reinterpret_cast<::Twin_0044ddc0 *>((((::NiSeq *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(arr5))->FUN_00629ab0(i)))))->GetName())) && a2 != b)
                        ::FUN_00cb5570((::ObjA *)(owner3), (::ObjB *)(((::NiSeq *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(arr5))->FUN_00629ab0(0)))), (::ObjB *)(((::NiSeq *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(arr5))->FUN_00629ab0(i)))));
                }

                reinterpret_cast<::TESForm *>((owner3))->ClearData();
            }
        }
    }
}



struct Point3
{
    float x, y, z;
};

struct Aabb
{
    __m128 minimum, maximum;
};

struct HavokTransform
{
    __m128 rotation0, rotation1, rotation2, translation;
};

struct Transform
{
    float rotation[3][3];
    Point3 translation;
    float scale;
    Transform* FUN_0062c250(Transform* out, const Transform* other) const;
    Point3* FUN_00524c40(Point3* out, const Point3* point) const;
};

struct Node
{
};

struct WorldObject
{
};

struct CollisionObject
{
};

struct RTTI;

// @fnv 0x0062bfb0
Point3* FUN_0062bfb0(Point3* out, Node* node)
{
    Point3 chosen = (*reinterpret_cast<::Point3 *>((void *)&::NiPoint3::ZERO));
    CollisionObject* collision = ((::CollisionObject *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(node))));
    if (collision)
    {
        WorldObject* body = ((::WorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(collision))));
        if (body)
        {
            Aabb bounds;
            new ((void *)&(bounds)) ::fnv_00437c10::FUN_00437c10();
            reinterpret_cast<::WorldObject_c8d3 *>((body))->GetAabb((*(::Aabb_c8d3 *)(&bounds)));
            Point3 minimum;
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&minimum)), (*(const ::hkVector4 *)(&bounds.minimum)));
            Point3 maximum;
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&maximum)), (*(const ::hkVector4 *)(&bounds.maximum)));
            Point3 lower, upper, minTermA, maxTermA, minTermB, maxTermB;
            reinterpret_cast<::Point3Offset *>((void *)(((::Point3 *)(::NiPosData::ComputePositionAtTime((::NiPoint3 *)(::Point3 *)(&maxTermA), .55f, (const ::NiPoint3 *)(const ::Point3 *)(&maximum))))))->ProjectileLaunched((::NiPoint3 *)(::Point3 *)(&upper), (::NiPoint3 *)(((::Point3 *)(::NiPosData::ComputePositionAtTime((::NiPoint3 *)(::Point3 *)(&minTermA), .45f, (const ::NiPoint3 *)(const ::Point3 *)(&minimum))))));
            reinterpret_cast<::Point3Offset *>((void *)(((::Point3 *)(::NiPosData::ComputePositionAtTime((::NiPoint3 *)(::Point3 *)(&maxTermB), .45f, (const ::NiPoint3 *)(const ::Point3 *)(&maximum))))))->ProjectileLaunched((::NiPoint3 *)(::Point3 *)(&lower), (::NiPoint3 *)(((::Point3 *)(::NiPosData::ComputePositionAtTime((::NiPoint3 *)(::Point3 *)(&minTermB), .55f, (const ::NiPoint3 *)(const ::Point3 *)(&minimum))))));
            Point3 random;
            chosen = *((::Point3 *)(reinterpret_cast<::FUN_00416870_t *>(&(random))->FUN_00416870(::RandomFloat(lower.x, upper.x), ::RandomFloat(lower.y, upper.y),
                                          ::RandomFloat(lower.z, upper.z))));
            if (::FUN_0043b300((const ::NiRTTI *)(const ::RTTI *)(&(*reinterpret_cast<::RTTI *>(&::g_012683c8))), (::NiAVObject *)(body)) || ((::Node *)(reinterpret_cast<::Twin_0044ddc0 *>((collision))->GetName())) != node)
            {
                HavokTransform bodyHavok;
                new ((void *)&(bodyHavok)) ::FUN_0056ded0();
                reinterpret_cast<::FUN_00c8d280_cls *>((body))->FUN_00c8d280((::S8d280_Mat *)(::HavokTransform *)(&bodyHavok));
                Transform bodyWorld;
                reinterpret_cast<::_dummy_476a80 *>(&(bodyWorld))->FUN_00476a80();
                ::FUN_00624ad0((::NiTransform *)(struct ::Transform *)(&bodyWorld), (::TopicH *)(&bodyHavok));
                bodyWorld.scale = 1.0f;
                Transform inverse;
                reinterpret_cast<::_dummy_476a80 *>(&(inverse))->FUN_00476a80();
                reinterpret_cast<::NiTransform *>((void *)(((const struct ::Transform *)(::FUN_00461130((std::intptr_t)(node))))))->CalculateInverse((*(::NiTransform *)(&inverse)));
                Transform composed;
                Point3 transformed;
                chosen = *inverse.FUN_0062c250(&composed, &bodyWorld)->FUN_00524c40(&transformed, &chosen);
            }
        }
    }
    *out = chosen;
    return out;
}

struct __declspec(align(16)) V_0062b8d0
{
    char buf[16];

    V_0062b8d0();
};

// @fnv 0x0062b8d0
void __cdecl FUN_0062b8d0(void* object, const void* in, unsigned char flag)
{
    V_0062b8d0 v;

    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&v)), (*(const ::fnv_004a3e00::NiPoint3 *)(in)));
    ::FUN_0062b930((::NiAVObject *)(object), (::Vec3Arg *)(::V_0062b8d0 *)(&v), flag);
}

#include "generated/data/fallout_shared/havok/teshavokutilities.inc"
