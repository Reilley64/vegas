// fallout_shared/teslight.cpp: TESObjectLIGH, TESFullName, Owner, LightLoader and more (29 functions)

#include <new>
#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDehydrationStage.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004036b0_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0041f810_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00484a70_shell.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_0048ea80_Class.h"
#include "fnv/decl/FUN_004bc280_S.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00693dc0_class.h"
#include "fnv/decl/FUN_006e5ee0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/Obj50DDB0.h"
#include "fnv/decl/P3.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_0048cca0.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_0048e9b0__TESValueForm.h"
#include "fnv/decl/fnv_0048e9e0__TESValueForm.h"
#include "fnv/decl/fnv_0048ea10__TESValueForm.h"
#include "fnv/decl/fnv_0048ea40__TESValueForm.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_0050fe50__ModelOwner.h"
#include "fnv/decl/fnv_00568cb0__FUN_00568cb0_shell.h"
#include "fnv/decl/fnv_00572610__FUN_00572610_cls.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00b5c940__SSNode.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_0050c000.h"
#include "fnv/symbols_0050d000.h"
#include "fnv/symbols_00578000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_011c8000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "teslight_TESFullName.h"
#include "teslight_TESForm.h"
#include "teslight_TESScriptableForm.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/symbols_00472000.h"

class TESSound : public TESForm
{
};
#include "teslight_r2d_types_TESObjectLIGH.h"
#include "teslight_scene.h"

extern "C" const char DAT_01029064[];

// Returns the reference's model node, or a new NiSortAdjustNode when the model name is empty or the node has no children.
// @fnv 0x0050d4c0
NiAVObject* TESObjectLIGH::Get3DObject(TESObjectREFR* reference)
{
    NiAVObject* result = 0;
    if (::FUN_0044a670(GetModelName()))
        result = ((::NiAVObject *)(reinterpret_cast<::fnv_0050fe50::ModelOwner *>(this)->GetModelNode((::fnv_0050fe50::ModelReference *)(reference))));
    else
        result = new NiSortAdjustNode(0);

    if (result && !result->IsSceneNode())
    {
        NiSortAdjustNode* node = new NiSortAdjustNode(0);
        node->vfn_00dc(result, true);
        result = node;
    }
    return result;
}

// Recursively searches a NiNode's children for the first NiAVObject matching DAT_011f4a28 and returns it as a NiLight, or null.
// @fnv 0x0050d6d0
NiLight* FindLightInNode(NiNode* node)
{
    NiLight* result = 0;
    if (!node)
        return result;

    for (unsigned int index = 0; index < node->FUN_0043b480(); ++index)
    {
        NiPointer<NiAVObject> child(node->GetAt(index));
        if (child)
        {
            if (static_cast<NiAVObject*>(child)->IsSceneNode())
            {
                result = FindLightInNode(static_cast<NiNode*>(static_cast<NiAVObject*>(child)));
                if (result)
                    return result;
            }
            else if (FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4a28)), static_cast<NiAVObject*>(child)))
            {
                return static_cast<NiLight*>(static_cast<NiAVObject*>(child));
            }
        }
    }
    return result;
}

// @fnv 0x00489100
void TESFullName::SetFullName(const char* name)
{
    reinterpret_cast<::TextString *>(&(m_kName))->FUN_004037f0(name, 0);
}

// @fnv 0x0050c990
void TESObjectLIGH::ResetFormData()
{
    reinterpret_cast<::TESObjectLIGH *>(this)->SetSound((::TESSound *)(0));
    memset(&data, 0, 0x18);
    fFadeAmount = 1.0f;
    data.fFOV = DAT_010249d8;
}

// @fnv 0x0050ca00
void TESObjectLIGH::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(reinterpret_cast<const TESFormInitFlag*>(this)))->GetInitialized())
        return;

    TESScriptableForm::InitItem(static_cast<TESForm*>(this));
    BGSDestructibleObjectForm::InitItem(static_cast<TESForm*>(this));
    TESModelTextureSwap::InitItem(static_cast<TESForm*>(this));

    if (m_pGameSound)
    {
        unsigned int formID = (unsigned int)(std::uintptr_t)(m_pGameSound);
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pGameSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!m_pGameSound)
            ::FUN_005b5e40();
    }
    SetInitializationState(true);
}

// @fnv 0x0050c9e0
void TESObjectLIGH::SetSound(TESSound* sound)
{
    m_pGameSound = sound;
}

class NiDynamicEffect
{
  public:
    void IncRevisionID();
};

struct FUN_0050c630_helper : public NiDynamicEffect
{
    void FUN_0050c630(float fC);
};

// Stores fC at offset 0xf0 of this object and calls IncRevisionID to mark the effect as changed.
// @fnv 0x0050c630
void FUN_0050c630_helper::FUN_0050c630(float fC)
{
    *(float*)((char*)this + 0xf0) = fC;
    IncRevisionID();
}

namespace fnv_0050c660 {
struct NiDynamicEffect
{
};

struct FUN_0050c660_shell
{
    void FUN_0050c660(float fL);
};

// Stores fL at offset 0xf4 of this and calls IncRevisionID on the object as a NiDynamicEffect.
// @fnv 0x0050c660
void FUN_0050c660_shell::FUN_0050c660(float fL)
{
    *(float*)((char*)this + 0xf4) = fL;
    reinterpret_cast<::NiDynamicEffect *>((((NiDynamicEffect*)this)))->IncRevisionID();
}
}  // namespace fnv_0050c660

struct FUN_0050d4a0_shell : public TESForm
{
    bool FUN_0050d4a0();
};

// @fnv 0x0050d4a0
bool FUN_0050d4a0_shell::FUN_0050d4a0()
{
    return (m_uiFormFlags & 0x10) ? true : false;
}

struct FUN_0050dd90_shell : public TESObjectLIGH
{
    bool FUN_0050dd90();
};

// @fnv 0x0050dd90
bool FUN_0050dd90_shell::FUN_0050dd90()
{
    return (this->data.flags & 1) ? true : false;
}

// Stores fQ at offset 0xf8 of the object and increments its revision ID.
// @fnv 0x0050c690
void FUN_0050c690(NiDynamicEffect* this_ptr, float fQ)
{
    *(float*)((char*)this_ptr + 0xf8) = fQ;
    this_ptr->IncRevisionID();
}

struct FUN_0050dd50_color
{
    float r;
    float g;
    float b;
};
struct FUN_0050dd50_arg
{
    FUN_0050dd50_color* c;
};
// Copies the color from a.c into the effect's field at offset 0xe0 and bumps the revision ID.
// @fnv 0x0050dd50
void FUN_0050dd50(NiDynamicEffect* this_ptr, FUN_0050dd50_arg aColorArg)
{
    *(FUN_0050dd50_color*)((char*)this_ptr + 0xe0) = *aColorArg.c;
    this_ptr->IncRevisionID();
}

struct FUN_0050c820_shell : TESObjectLIGH
{
    NiColor* GetLightColor();
};

// @fnv 0x0050c820
NiColor* FUN_0050c820_shell::GetLightColor()
{
    return &this->m_kDiffuseColor;
}

struct FUN_0050d100_shell
{
    void* FUN_0050d100();
};

// @fnv 0x0050d100
void* FUN_0050d100_shell::FUN_0050d100()
{
    return reinterpret_cast<char*>(this) + 0x9C;
}

struct FUN_00484bf0_stub
{
};
struct FUN_0048e9b0_stub
{
};

struct FUN_0050e4f0_shell
{
    unsigned short GetSize(unsigned int aiFlags);
};

// Returns the sum of the sizes reported by FUN_00484bf0 on this and FUN_0048e9b0 on the object at offset 0x8c, both called with aiFlags.
// @fnv 0x0050e4f0
unsigned short FUN_0050e4f0_shell::GetSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_00484bf0_shell *>((((FUN_00484bf0_stub*)this)))->FUN_00484bf0(aiFlags);
    isize += reinterpret_cast<::fnv_0048e9b0::TESValueForm *>((((FUN_0048e9b0_stub*)((char*)this + 0x8c))))->FUN_0048e9b0(aiFlags);
    return isize;
}

struct FUN_0051b070_shell
{
};

struct FUN_0050e550_shell : ::TESObjectLIGH
{
    void FUN_0050e550(unsigned int);
};

// Forwards aiFlags to FUN_00484c20 on this and to FUN_0048e9e0 on the object at offset 0x8c.
// @fnv 0x0050e550
void FUN_0050e550_shell::FUN_0050e550(unsigned int aiFlags)
{
    reinterpret_cast<::PC7d *>((reinterpret_cast<FUN_0051b070_shell*>(this)))->FUN_00484c20(aiFlags);
    reinterpret_cast<::fnv_0048e9e0::TESValueForm *>((reinterpret_cast<FUN_0051b070_shell*>(static_cast<TESValueForm *>(this))))->FUN_0048e9e0(aiFlags);
}

struct TESFormStub
{
};
struct TESValueFormStub
{
};

struct FUN_0050e580_shell : ::TESObjectLIGH
{
    void FUN_0050e580(unsigned int a1, unsigned int a2);
};

// @fnv 0x0050e580
void FUN_0050e580_shell::FUN_0050e580(unsigned int a1, unsigned int a2)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>((((TESFormStub*)this)))->FUN_00484c50(a1, a2);
    reinterpret_cast<::fnv_0048ea10::TESValueForm *>((((TESValueFormStub*)static_cast<TESValueForm *>(this))))->FUN_0048ea10(a1, a2);
}

struct FUN_00484d60_holder
{
};
struct FUN_0048ea40_holder
{
};

struct FUN_0050e5c0_shell : ::TESObjectLIGH
{
    void FUN_0050e5c0(std::uintptr_t aiFlags);
};

// @fnv 0x0050e5c0
void FUN_0050e5c0_shell::FUN_0050e5c0(std::uintptr_t aiFlags)
{
    reinterpret_cast<::FakeForm *>((reinterpret_cast<FUN_00484d60_holder*>(this)))->SaveIfChanged((::BGSSaveFormBuffer *)(aiFlags));
    reinterpret_cast<::fnv_0048ea40::TESValueForm *>((reinterpret_cast<FUN_0048ea40_holder*>(static_cast<TESValueForm *>(this))))->FUN_0048ea40((::fnv_0048ea40::BGSSaveFormBuffer *)(aiFlags));
}

struct BGSLoadFormBuffer;

struct TESValueFormLoadGame
{
};

struct FUN_0050e5f0_shell : ::TESObjectLIGH
{
    void LoadGame(BGSLoadFormBuffer* arg);
};

// Loads the TESForm base and the TESValueFormLoadGame subobject at offset 0x8c from the buffer.
// @fnv 0x0050e5f0
void FUN_0050e5f0_shell::LoadGame(BGSLoadFormBuffer* pBuffer)
{
    reinterpret_cast<TESForm*>(this)->TESForm::LoadGame(pBuffer);
    reinterpret_cast<::FUN_0048ea80_Class *>((reinterpret_cast<TESValueFormLoadGame*>(static_cast<TESValueForm *>(this))))->FUN_0048ea80(pBuffer);
}

struct Owner
{
    void FUN_0050c870();
    void* DestroyIfFlagged(unsigned int);
};
namespace stand {
struct TESBoundAnimObject
{
    TESBoundAnimObject();
    ~TESBoundAnimObject();
    virtual void v0();
    char pad[0x2c];
};
class TESFullName
{
  public:
    TESFullName();
    ~TESFullName();
    virtual void v0();
    char pad[0x8];
};
class TESModelTextureSwap
{
  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    virtual void v0();
    char pad[0x1c];
};
struct TESIcon
{
    TESIcon();
    ~TESIcon();
    virtual void v0();
    char pad[0x8];
};
struct BGSMessageIcon
{
    BGSMessageIcon();
    ~BGSMessageIcon();
    virtual void v0();
    char pad[0xc];
};
struct TESScriptableForm
{
    TESScriptableForm();
    virtual void v0();
    char pad[0x8];
};
struct TESWeightForm
{
    TESWeightForm();
    ~TESWeightForm();
    virtual void v0();
    char pad[0x4];
};
struct TESValueForm
{
    TESValueForm();
    ~TESValueForm();
    virtual void v0();
    char pad[0x4];
};
class BGSDestructibleObjectForm
{
  public:
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    virtual void v0();
    char pad[0x4];
};
struct NiPoint3
{
    NiPoint3(float, float, float);
    float x, y, z;
};
}

struct FUN_0050c6c0 : public stand::TESBoundAnimObject,
                      public stand::TESFullName,
                      public stand::TESModelTextureSwap,
                      public stand::TESIcon,
                      public stand::BGSMessageIcon,
                      public stand::TESScriptableForm,
                      public stand::TESWeightForm,
                      public stand::TESValueForm,
                      public stand::BGSDestructibleObjectForm
{
    char data[0x18];
    float fFadeAmount;
    void* m_pGameSound;
    stand::NiPoint3 m_kDiffuseColor;
    FUN_0050c6c0();
};

// @fnv 0x0050c6c0
FUN_0050c6c0::FUN_0050c6c0() : m_kDiffuseColor(0.0f, 0.0f, 0.0f)
{
    reinterpret_cast<::FUN_004f15a0_shell *>((((TESForm*)this)))->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x1e)));
    ((TESObjectLIGH*)this)->ResetFormData();
}

struct TESObjectLIGH;
struct TESLevItem;
struct BGSTerrainManager
{
    std::uintptr_t GetMinLevel();
};
struct RegionPointList
{
};
struct TESActorBaseData
{
};
struct CGBase
{
};
struct GetNextObj
{
};
struct FUN_00510130_shell
{
    void RemoveNode(NiNode* pNode);
};
// @fnv 0x00510130
void FUN_00510130_shell::RemoveNode(NiNode* pNode)
{
    if (pNode == *(NiNode**)((char*)this + 4))
    {
        *(NiNode**)((char*)this + 4) = (NiNode*)((std::uintptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((GetNextObj*)(*(NiNode**)((char*)this + 4)))))->FUN_007af430()));
    }
    if (pNode == *(NiNode**)((char*)this + 8))
    {
        *(NiNode**)((char*)this + 8) = (NiNode*)((BGSTerrainManager*)(*(NiNode**)((char*)this + 8)))->GetMinLevel();
    }
    std::uintptr_t n = ((BGSTerrainManager*)pNode)->GetMinLevel();
    if (n)
    {
        reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((((RegionPointList*)n)))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(((std::uintptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((GetNextObj*)pNode)))->FUN_007af430()))));
    }
    n = ((std::uintptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((GetNextObj*)pNode)))->FUN_007af430()));
    if (n)
    {
        reinterpret_cast<::BGSDehydrationStage *>((((TESActorBaseData*)n)))->FUN_0050f9a0((::SpellItem *)(::TESLevItem *)((TESLevItem*)((BGSTerrainManager*)pNode)->GetMinLevel()));
    }
    reinterpret_cast<::TESPackage *>((((CGBase*)pNode)))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(0));
    *(unsigned int*)this -= 1;
}

namespace fnv_0050d060 {
struct S_004036b0
{
};

struct SetterB
{
};

struct FUN_0050d100_shell
{
};

struct FUN_005e78f0_t
{
    struct Data
    {
        unsigned int value0;
        unsigned int value1;
        unsigned int value2;
        unsigned int value3;
        unsigned int value4;
        unsigned int value5;
    };

    unsigned char padding[0x9c];
    Data data;

    void CopyFromLight(TESForm* form);
};


// Copies light data from apCopy after casting it to TESObjectLIGH, then sets a float value and the sound from the source light.
// @fnv 0x0050d060
void FUN_005e78f0_t::CopyFromLight(TESForm* apCopy)
{
    TESObjectLIGH* ligh = dynamic_cast<TESObjectLIGH*>(apCopy);

    if (!ligh)
        return;

    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(apCopy);

    data = *reinterpret_cast<Data*>(reinterpret_cast<::FUN_0050d100_shell *>((reinterpret_cast<FUN_0050d100_shell*>(ligh)))->FUN_0050d100());

    reinterpret_cast<::FUN_006e5ee0_Class *>((reinterpret_cast<SetterB*>(this)))->FUN_006e5ee0(::GetFieldB4Float(reinterpret_cast<char*>(ligh)));

    reinterpret_cast<TESObjectLIGH*>(this)->SetSound(
        reinterpret_cast<TESSound*>(((int)(reinterpret_cast<::FUN_004036b0_Class *>((reinterpret_cast<S_004036b0*>(ligh)))->FUN_004036b0()))));
}
}  // namespace fnv_0050d060

struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct DoorPart3c
{
};

struct DoorPart5c
{
};

struct DoorPart68
{
};

struct DoorPart30
{
};

struct FUN_0048e370_obj
{
};

struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};

struct FUN_00485e00_shell
{
};


struct FUN_0050cf20_shell
{
    unsigned char pad_0000[0x9c];
    unsigned int value_009c;
    unsigned char pad_00a0[8];
    unsigned int flags_00a8;
    unsigned char pad_00ac[8];
    float fade_00b4;
    TESForm* sound_00b8;

    void FUN_0050cf20();
};

// @fnv 0x0050cf20
void FUN_0050cf20_shell::FUN_0050cf20()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();

    reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<DoorPart3c*>(reinterpret_cast<char*>(this) + 0x3c)))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::S_0048cca0 *>((reinterpret_cast<DoorPart5c*>(reinterpret_cast<char*>(this) + 0x78)))->FUN_0048cca0();
    reinterpret_cast<::FUN_00477f20_shell *>((reinterpret_cast<DoorPart68*>(reinterpret_cast<char*>(this) + 0x94)))->FUN_00477f20();

    if (flags_00a8 & 2)
    {
        reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<DoorPart30*>(reinterpret_cast<char*>(this) + 0x30)))->FUN_00487010();
        reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x5c)))->FUN_0048e370(0x4e4f4349);
        reinterpret_cast<FUN_0047a240_shell*>(reinterpret_cast<char*>(this) + 0x68)->FUN_0047a240(0x4f43494d);
    }
    else
    {
        flags_00a8 &= 0xffffffdf;
        value_009c = 0xffffffff;
    }

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00693dc0_class *>((&value_009c))->SwapEndian();

    reinterpret_cast<::SDSaveForm *>((reinterpret_cast<FUN_00485e00_shell*>(this)))->FUN_00485e20((const void *)(reinterpret_cast<std::intptr_t>(&value_009c)), 0x18);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00693dc0_class *>((&value_009c))->SwapEndian();

    ::FUN_00485910(0x4d414e46, fade_00b4);

    if (sound_00b8)
    {
        unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((sound_00b8))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e53, formID);
    }

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

struct FUN_0050c870 : stand::TESBoundAnimObject,
                      stand::TESFullName,
                      stand::TESModelTextureSwap,
                      stand::TESIcon,
                      stand::BGSMessageIcon,
                      stand::TESScriptableForm,
                      stand::TESWeightForm,
                      stand::TESValueForm,
                      stand::BGSDestructibleObjectForm
{
    virtual ~FUN_0050c870();
};
// Calls FUN_0050c870, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0050c840
void* Owner::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0050c870 *>(this)->FUN_0050c870::~FUN_0050c870();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0050c870
FUN_0050c870::~FUN_0050c870()
{}

struct NextFile
{
};

struct LightFileExtra
{
};
struct ModelLoad : TESModelTextureSwap
{
};
struct ComponentID : TESScriptableForm
{
};
struct LightLoader : TESBoundAnimObject,
                     TESFullName,
                     ModelLoad,
                     TESIcon,
                     BGSMessageIcon,
                     ComponentID,
                     TESWeightForm,
                     TESValueForm,
                     BGSDestructibleObjectForm
{
    LightSourceData data;
    float fFadeAmount;
    TESSound* m_pGameSound;
    bool LoadLight(TESFile*);
};
struct LightData
{
};
// @fnv 0x0050caf0
bool LightLoader::LoadLight(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 30)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(0);
    data.fFOV = 0.0f;
    data.m_fLightFalloff = 0.0f;
    int chunk;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44534f4d:
        case 0x44444f4d:
            ::TESModel::LoadModelData((::TESModel *)(::TESModelTextureSwap *)(this), file);
            break;
        case 0x53444f4d: {
            unsigned int dataSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            void* swapData = _alloca(dataSize);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(swapData), dataSize);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(swapData, dataSize, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((LightFileExtra*)file)))->FUN_00403570());
            break;
        }
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData((::TESTexture *)(::TESIcon *)(this), file);
            break;
        case 0x4f43494d:
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this), file);
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(std::uintptr_t)(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            ::FUN_004781e0(this, file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data, 24);
            break;
        case 0x4d414e46:
            file->GetChunkData((unsigned int*)&fFadeAmount);
            break;
        case 0x4d414e53: {
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            m_pGameSound = (TESSound*)(std::uintptr_t)soundID;
            break;
        }
        }
        if (chunk == 0x41544144)
        {
            if (reinterpret_cast<::TESFile *>((((LightFileExtra*)file)))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00693dc0_class *>((((LightData*)&data)))->SwapEndian();
            if (data.fFOV == 0.0)
                data.fFOV = DAT_010249d8;
            if (data.m_fLightFalloff == 0.0)
                data.m_fLightFalloff = 1.0f;
        }
        if (!reinterpret_cast<::TESFile *>((((NextFile*)file)))->NextChunk())
            break;
    }
    return true;
}

namespace LightCreation {
struct Color
{
    float r, g, b;
    Color(float, float, float);
};
struct FixedString
{
    const char* text;
    FixedString(const char*);
    ~FixedString();
};
struct FUN_00a7d670
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;

    FUN_00a7d670();
    void FUN_0050dd20(float);
};
typedef FUN_00a7d670 Light;
void* __cdecl FUN_00aa13e0(unsigned int);
struct Parent;
struct Scene;
struct Extra
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual Scene* GetScene();
};
struct Scene
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual Extra* GetExtra(const char*);
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void Attach(Light*, bool);
};
struct Parent
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual bool IsSpecial();
};
struct BaseForm
{
    int FUN_00401170();
};
struct Position
{
    float x, y, z;
};
struct EntryListNode
{
    bool FUN_008256d0();
};
struct ObjectPointerProvider
{
};
struct Reference
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual bool IsPersistent();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual Position* GetPosition();
};
struct Manager
{
};
extern const char DAT_010290a4[];
struct LightForm
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual const char* Name();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int radius;
    unsigned int color;
    unsigned int flags;
    unsigned int unkac, unkb0;
    float fade;
    Light* FUN_0050d810(Reference*, Scene*, bool);
};
// @fnv 0x0050d810
Light* LightForm::FUN_0050d810(Reference* reference, Scene* pScene, bool force)
{
    if (!pScene)
        return 0;
    BaseForm* base;
    if (reference)
    {
        base = ((::LightCreation::BaseForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
        if ((flags & 0x20) || (((std::intptr_t)(reinterpret_cast<::LowProcess *>((reference))->GetTarget())) && reference->GetPosition()->z < reinterpret_cast<::FUN_0057b0a0_shell *>((reference))->FUN_0057b0a0()))
        {
            if (base->FUN_00401170() == 30 && ::fnv_00578400::FUN_00578400((::fnv_00578400::_FakeNiNode *)(pScene)))
            {
                reinterpret_cast<::FUN_00484a70_shell *>((reference))->FUN_00484a70(true);
                ::ProcessListItems((::List *)(pScene));
            }
            if (!reference->IsPersistent() && (flags & 0x20))
                return 0;
        }
    }
    Light* lightSlot12 = 0;
    Color tintSlot1(0.0f, 0.0f, 0.0f);
    tintSlot1.r = (unsigned char)(color & 0xff) / ::DAT_0101e568;
    tintSlot1.g = (unsigned char)(((unsigned short)color >> 8) & 0xff) / ::DAT_0101e568;
    tintSlot1.b = (unsigned char)((color >> 16) & 0xff) / ::DAT_0101e568;
    if (flags & 4)
        tintSlot1 = (*(::LightCreation::Color *)(reinterpret_cast<::P3 *>(&(tintSlot1))->FUN_004a0bd0({})));
    Scene* rootSlot19 = 0;
    Extra* extra = pScene->GetExtra(((const char *)(std::uintptr_t)(::FUN_0050de10())));
    if (extra)
        rootSlot19 = extra->GetScene();
    if (!rootSlot19)
        rootSlot19 = pScene;
    lightSlot12 = ((::LightCreation::FUN_00a7d670 *)(::FindLightInNode((::NiNode *)(rootSlot19))));
    if (!lightSlot12)
    {
        char name[260];
        ::FUN_00406d00(name, 260, DAT_010290a4, Name());
        lightSlot12 = new Light;
        ::AssignFixedString((char *)(lightSlot12), (std::intptr_t)&(const ::LightCreation::FixedString &)(FixedString(name)), {});
        rootSlot19->Attach(lightSlot12, true);
    }
    if (reference)
        reinterpret_cast<::fnv_00572610::FUN_00572610_cls *>((reference))->FUN_00572610(lightSlot12);
    reinterpret_cast<::FUN_004bc280_S *>((lightSlot12))->FUN_004bc280((const ::C3 *)&((*reinterpret_cast<const ::LightCreation::Color *>(&::DAT_011f4998))));
    ::FUN_0050dd50((::NiDynamicEffect *)(lightSlot12), (*(::FUN_0050dd50_arg *)&((*reinterpret_cast<const ::LightCreation::Color *>(&::DAT_011f4998)))));
    float radiusValueSlot21 = (float)radius;
    if (reference)
        radiusValueSlot21 = reinterpret_cast<::fnv_00568cb0::FUN_00568cb0_shell *>((reference))->FUN_00568cb0();
    ::FUN_0050dd50((::NiDynamicEffect *)(lightSlot12), (*(::FUN_0050dd50_arg *)&(const ::LightCreation::Color &)(Color(radiusValueSlot21, radiusValueSlot21, radiusValueSlot21))));
    reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((lightSlot12))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(tintSlot1));
    Parent* parentSlot6;
    for (parentSlot6 = ((::LightCreation::Parent *)(::fnv_0043b230::FUN_0043b230((const char *)(pScene)))); parentSlot6; parentSlot6 = ((::LightCreation::Parent *)(::fnv_004a8a90::FUN_004a8a90((char *)(parentSlot6)))))
    {
        if (parentSlot6->IsSpecial())
        {
            reinterpret_cast<::Obj50DDB0 *>(this)->FUN_0050ddb0(true);
            break;
        }
    }
    if (!(reference && ((::LightCreation::EntryListNode *)(reinterpret_cast<::FUN_0041f810_shell *>((((::LightCreation::ObjectPointerProvider *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041f810()))) ||
        (reference && ((::LightCreation::EntryListNode *)(reinterpret_cast<::FUN_0041f810_shell *>((((::LightCreation::ObjectPointerProvider *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041f810())) &&
         ((::LightCreation::EntryListNode *)(reinterpret_cast<::FUN_0041f810_shell *>((((::LightCreation::ObjectPointerProvider *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041f810()))->FUN_008256d0()))
        reinterpret_cast<::fnv_00b5c940::SSNode *>((((::LightCreation::Manager *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5c940((::fnv_00b5c940::NiLightObj *)(lightSlot12), force ? true : reinterpret_cast<::FUN_0050dd90_shell *>(this)->FUN_0050dd90());
    if (lightSlot12)
    {
        ::ConfigurePointLight((::NiAVObject *)(lightSlot12), (unsigned int)radiusValueSlot21);
        lightSlot12->FUN_0050dd20(fade);
    }
    return lightSlot12;
}
}

// 0x0050c350  unit_0e65a86e7dd7.cpp  /MT /Od /Oy- /GS /EHsc /Gy
struct NiRTTI
{
  public:
    int m;
};
class TESObjectCELL;

class NiPointLight
{
  public:
};

class GlobalObject_0044f440
{
  public:
};
struct GlobalObject_0045cfe0
{
  public:
};
class GlobalObject_0045cf30
{
  public:
    bool FUN_0050e620(bool b);
};

extern GlobalObject_0044f440 g_011c9000;
extern GlobalObject_0044f440 g_011c9040;
extern GlobalObject_0044f440 g_011c908c;
extern GlobalObject_0045cf30 g_011c8fc0;
extern unsigned char DAT_011c8fa0;

class TES
{
  public:
};


// @fnv 0x0050c350
void ConfigurePointLight(NiAVObject* object, unsigned int count)
{
    NiPointLight* light = (NiPointLight*)((::NiAVObject *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f4a98)), (::NiObject *)(object))));
    if (light)
    {
        reinterpret_cast<::FUN_0050c630_helper *>((light))->FUN_0050c630((DAT_011c8fa0 & 1) ? *((float *)&(::FUN_00403e20((float *)&(g_011c9000)))) : 0.0f);
        reinterpret_cast<::fnv_0050c660::FUN_0050c660_shell *>((light))->FUN_0050c660(0.0f);
        ::FUN_0050c690((::NiDynamicEffect *)(light), 0.0f);

        if ((DAT_011c8fa0 & 2) || (((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetPrevPath())) != 0 && g_011c8fc0.FUN_0050e620(true)))
        {
            float a = (double)count * *((float *)&(::FUN_00403e20((float *)&(g_011c8fb0))));
            switch (*((int *)&(::FUN_0043d4d0((int *)&(g_011c9054)))))
            {
            case 0:
                reinterpret_cast<::fnv_0050c660::FUN_0050c660_shell *>((light))->FUN_0050c660(*((float *)&(::FUN_00403e20((float *)&(g_011c908c)))));
                break;
            default:
                reinterpret_cast<::fnv_0050c660::FUN_0050c660_shell *>((light))->FUN_0050c660((a != 0.0) ? ((1.0 / a) * *((float *)&(::FUN_00403e20((float *)&(g_011c908c))))) : 0.01f);
                break;
            case 2:
                reinterpret_cast<::fnv_0050c660::FUN_0050c660_shell *>((light))->FUN_0050c660((a != 0.0) ? (*((float *)&(::FUN_00403e20((float *)&(g_011c908c)))) / (a * a)) : 0.01f);
                break;
            }
        }

        if ((DAT_011c8fa0 & 4) || (((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetPrevPath())) == 0 && g_011c8fc0.FUN_0050e620(true)))
        {
            float b = (double)count * *((float *)&(::FUN_00403e20((float *)&(g_011c906c))));
            switch (*((int *)&(::FUN_0043d4d0((int *)&(g_011c907c)))))
            {
            case 0:
                ::FUN_0050c690((::NiDynamicEffect *)(light), *((float *)&(::FUN_00403e20((float *)&(g_011c9040)))));
                break;
            case 1:
                ::FUN_0050c690((::NiDynamicEffect *)(light), (b != 0.0) ? ((1.0 / (double)count) * reinterpret_cast<::FUN_00450410_Class *>(&(g_011c9040))->FUN_00450410()) : 0.01f);
                break;
            default:
                ::FUN_0050c690((::NiDynamicEffect *)(light), (b != 0.0) ? (reinterpret_cast<::FUN_00450410_Class *>(&(g_011c9040))->FUN_00450410() / (b * b)) : 0.01f);
                break;
            }
        }
    }
}

struct LightSoundAccess
{
};
struct LightComponentComparison
{
};
struct LightDataAccess
{
};

struct LightComparison : TESObjectLIGH
{
    bool FUN_0050d120(TESForm* form);
};

// Returns true if this light fails the component, sound, data, or computed-value comparisons.
// @fnv 0x0050d120
bool LightComparison::FUN_0050d120(TESForm* form)
{
    TESObjectLIGH* pOtherLight = dynamic_cast<TESObjectLIGH*>(form);
    if (!pOtherLight)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<LightComponentComparison*>(this)))->FUN_00485270(pOtherLight))
        return true;
    if (m_pGameSound != ((::TESSound *)(reinterpret_cast<::FUN_004036b0_Class *>((reinterpret_cast<LightSoundAccess*>(pOtherLight)))->FUN_004036b0())))
        return true;
    if (std::memcmp(&data, ((::LightSourceData *)(reinterpret_cast<::FUN_0050d100_shell *>((reinterpret_cast<LightDataAccess*>(pOtherLight)))->FUN_0050d100())), sizeof(data)))
        return true;
    if (GetFieldB4Float(reinterpret_cast<char*>(this)) != GetFieldB4Float(reinterpret_cast<char*>(pOtherLight)))
        return true;
    return false;
}

struct PrimaryBase_0050e680
{
    virtual void FUN_0050e680();
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
};

struct SecondaryBase_0050e680
{
    virtual void FUN_0050e680();
};

struct Derived_0050e680 : PrimaryBase_0050e680, SecondaryBase_0050e680
{
    Derived_0050e680();
// @fnv 0x0050e680
    virtual void FUN_0050e680();
};

Derived_0050e680::Derived_0050e680()
{}

namespace fnv_0050e690 {
// Adjustor thunk for FUN_0050e690: "sub ecx, 0x3c; jmp DestroyIfFlagged".
//
// This is the MSVC "this adjusting thunk" emitted for a virtual function that a
// class inherits from a secondary base: the thunk converts the secondary base
// sub-object pointer (this + 0x3c) back into the derived object pointer
// (sub ecx, 0x3c) and then tail jumps to the final overrider.
//
// The subtracted constant is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 14 int members (4 + 14 * 4 = 0x3c
// bytes).  Both bases declare the same virtual function, the derived class
// redeclares it and defines only its constructor, which is what makes the
// compiler emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0050e690();
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
};

struct SecondaryBase
{
    virtual void FUN_0050e690();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0050e690
    virtual void FUN_0050e690();
};

Derived::Derived()
{}
}

// namespace fnv_0050e690

// FUN_0050e6a0 is an MSVC this-adjusting (adjustor) thunk:
//     sub ecx, 0x8c ; jmp FUN_0050e580
// It is emitted for a virtual that lives in the first base of a multiply
// inherited class but is reached through the second base's vtable slot: the
// slot holds a thunk that walks `this` back to the derived object (the size of
// the primary base, 0x8c) and tail-jumps to the derived override.
struct ThunkPrimaryBase_0050e6a0
{
    virtual void* FUN_0050e6a0(unsigned int flags);
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
};

struct ThunkSecondaryBase_0050e6a0
{
    virtual void* FUN_0050e6a0(unsigned int flags);
};

struct ThunkDerived_0050e6a0 : ThunkPrimaryBase_0050e6a0, ThunkSecondaryBase_0050e6a0
{
    ThunkDerived_0050e6a0();
// @fnv 0x0050e6a0
    virtual void* FUN_0050e6a0(unsigned int flags);
};

ThunkDerived_0050e6a0::ThunkDerived_0050e6a0()
{}

namespace fnv_0050e6b0 {
// sub ecx,0x8c; jmp FUN_0050e550
// MSVC this-adjusting (adjustor) thunk: a derived class declares a virtual that
// both of its bases declare, so the secondary base's vtable slot holds a thunk
// that walks `this` back to the secondary base subobject (the size of the
// primary base, 0x8c) and tail-jumps to the base implementation.
struct ThunkPrimaryBase
{
    virtual void FUN_0050e6b0();
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
};

struct ThunkSecondaryBase
{
    virtual void FUN_0050e6b0();
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x0050e6b0
    virtual void FUN_0050e6b0();
};

ThunkDerived::ThunkDerived()
{}
}

#include "generated/data/fallout_shared/teslight.inc"
