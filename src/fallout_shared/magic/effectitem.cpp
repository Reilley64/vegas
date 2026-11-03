// fallout_shared/magic/effectitem.cpp: EffectItem, EffectItemList, ScriptEffect, Setting and more (52 functions)

#include <cstring>
#include "fnv/decl/BGSDebris.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004046b0_cls.h"
#include "fnv/decl/FUN_00404950.h"
#include "fnv/decl/FUN_00404c00.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004d6490_Class.h"
#include "fnv/decl/FUN_00680910_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00c33280_Class.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/Node406.h"
#include "fnv/decl/OpaqueData.h"
#include "fnv/decl/Owner64.h"
#include "fnv/decl/TreeCtrl4d63.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01272000.h"
#include "effectitem_decls.h"

// @fnv 0x00404650
int EffectItem::GetEffectID()
{
    return ((int)(::FUN_0070ec90((char *)(m_pEffectSetting))));
}

// @fnv 0x00405e40
bool EffectItem::IsDetrimental()
{
    return m_pEffectSetting->IsDetrimental();
}

// Returns whether GetEffectSetting() equals GetUsageMonitorEffectSetting().
// @fnv 0x00404730
bool EffectItem::IsScriptBasedEffect()
{
    return ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) == ((::EffectSetting *)(::FUN_00408b50()));
}

// Returns the effect name by delegating to the effect's GetEffectName method.
// @fnv 0x00404670
BSStringT<char> EffectItem::GetEffectName()
{
    return (*(::BSStringT<char> *)(reinterpret_cast<::FUN_004046b0_cls *>((void *)(m_pEffectSetting))->AssignFromSub({})));
}

// @fnv 0x00405d20
void EffectItemList::AddItem(EffectItem* item)
{
    if (item->IsScriptBasedEffect() && ((::EffectItem *)(reinterpret_cast<::Node406 *>(this)->FindEntryByTimeStamp())))
        return;

    reinterpret_cast<::Callees *>(&(Items))->FUN_00905820((void *)&(item));
    if (item->IsHostile())
        ++hostileCount;
}

// Constructs a ScriptEffect from caster, item and effect, initializing the base ActiveEffect and storing the effect's script with unknown set to 0.
// @fnv 0x00827740
ScriptEffect::ScriptEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect)
    : ActiveEffect(caster, item, effect)
{
    script = effect->GetScript();
    unknown = 0;
}

// Zeroes the first four ints of this_ptr, sets the fifth to -1, and returns this_ptr.
// @fnv 0x00403ba0
int* FUN_00403ba0(int* this_ptr)
{
    this_ptr[0] = 0;
    this_ptr[1] = 0;
    this_ptr[2] = 0;
    this_ptr[3] = 0;
    this_ptr[4] = -1;
    return this_ptr;
}

struct MagicEffectSystem
{
};
struct S3c60
{
    bool HasFlag2();
};
// @fnv 0x00403c60
bool S3c60::HasFlag2()
{
    return ::HasEffectArchetypeFlag(reinterpret_cast<::EffectSetting *>(this)->GetArchetype(), 2);
}

struct EffectArchetypeEntry
{
    unsigned int uiFlags;
    unsigned int pad[3];
};

extern EffectArchetypeEntry DAT_01183328[];

// @fnv 0x00403c80
bool __cdecl HasEffectArchetypeFlag(int aiIndex, unsigned int aiFlag)
{
    return (DAT_01183328[aiIndex].uiFlags & aiFlag) != 0;
}


// @fnv 0x00403d30
void __cdecl FUN_00403d30(void* apDest, int aiValue, unsigned int aCount)
{
    std::memset(apDest, aiValue, aCount);
}

struct FUN_00403db0_shell : public EffectItem
{
    void FUN_00403db0(TESForm*);
};

// If apForm is not initialized, initializes the item's conditions with apForm.
// @fnv 0x00403db0
void FUN_00403db0_shell::FUN_00403db0(TESForm* apForm)
{
    if (apForm->GetInitialized())
        return;
    if (((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>(this)->GetDataList())))
        ((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>(this)->GetDataList()))->InitItem(apForm);
}

struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool FUN_00403e60(unsigned int f);
};
// @fnv 0x00404710
bool EffectItem::IsHostile()
{
    return reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00()))))->FUN_00403e60(1);
}
// @fnv 0x00403e60
bool S3e60::FUN_00403e60(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}

struct FUN_00403e80_shell : public EffectSetting
{
    bool FUN_00403e80();
};
// Loads an EffectItem from a TESFile chunk: reads the 20-byte effect data (with endian conversion) or loads its conditions, returning false on unknown chunk IDs.
// @fnv 0x00404120
bool EffectItem::Load(TESFile* file, const char* actorEffect)
{
    switch (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
    case 0x54494645:
        memset(this, 0, 20);
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(this), 20);
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::OpaqueData *>((reinterpret_cast<BGSImpactData__IMPACT_DATA_DATA*>(this)))->SwapEndian();
        if (!m_pEffectSetting)
            ::FUN_005b5e40();
        else if (reinterpret_cast<::S3c60 *>((m_pEffectSetting))->HasFlag2() && reinterpret_cast<::FUN_00403e80_shell *>((m_pEffectSetting))->FUN_00403e80())
            data.m_eAssociatedActorValue =
                reinterpret_cast<int>(reinterpret_cast<InterfaceManager*>(m_pEffectSetting)->FUN_00586150());
        break;
    case 0x41445443:
        ((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>(this)->GetDataList()))->Load(file);
        break;
    default:
        return false;
    }
    return true;
}

// @fnv 0x00403e80
bool FUN_00403e80_shell::FUN_00403e80()
{
    return (int)((InterfaceManager*)this)->FUN_00586150() != -1;
}

struct FUN_00403ee0_shell : public EffectItem
{
    bool FUN_00403ee0();
};

// @fnv 0x00403ee0
bool FUN_00403ee0_shell::FUN_00403ee0()
{
    return reinterpret_cast<::S3c60 *>(((this->m_pEffectSetting)))->HasFlag2();
}

struct FUN_00403f00_shell : public EffectItem
{
    float FUN_00403f00();
};

class TESGrass
{
  public:
    float GetLowestAllowedSlope();
};

float __cdecl CalcEffectCost(float, int, int, int, bool);

struct Actor;
struct AlchemyItem;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct NiNode;
struct SpellItem;
struct TESBoundObject;
struct TESObjectCELL;
struct TESObjectREFR;
struct hkpRigidBody;
struct blob12
{
    char b[12];
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
namespace ActorValue { enum Index; }
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
public:
    int GetActorValueAsInteger(::ActorValue::Index);
public:
    float GetActorValueFloatByIndex(::ActorValue::Index);
};
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
struct FUN_00403f80_shell : public EffectItem
{
    float GetModifiedCost(Actor*);
};

float __cdecl FUN_00404040(float);
float __cdecl FUN_00404010(float, float);

// @fnv 0x00403f80
float FUN_00403f80_shell::GetModifiedCost(Actor* apActor)
{
    float fcost = reinterpret_cast<::FUN_00403f00_shell *>((this))->FUN_00403f00();
    if (apActor != 0)
    {
        fcost = ::ScaleBySettingBlend(fcost,
                                    ((ActorValueOwner*)((char*)apActor + 0xa4))->GetActorValueAsInteger((::ActorValue::Index)(GetEffectID())));
    }
    fcost = FUN_00404040(fcost);
    return FUN_00404010(fcost, 1.0f);
}

// Returns the larger of the two float arguments.
// @fnv 0x00404010
float __cdecl FUN_00404010(float fA, float fB)
{
    return (fA > fB) ? fA : fB;
}

float __cdecl TruncateToInt(float);

// @fnv 0x00404040
float __cdecl FUN_00404040(float aIn)
{
    float droundToZero = TruncateToInt(aIn);
    return (aIn - droundToZero >= ::_DAT_01012060) ? droundToZero : (droundToZero - 1.0);
}

struct FUN_004042a0_shell : public EffectItem
{
    bool IsDifferentFrom(EffectItem*);
};

struct FUN_00404390_shell : public EffectItem
{
    int FUN_00404390();
};

// Returns 0 if the EffectSetting at offset 0x14 has flag 0x100 set, otherwise returns the int at offset 0 of this EffectItem.
// @fnv 0x00404390
int FUN_00404390_shell::FUN_00404390()
{
    return reinterpret_cast<::S3e60 *>(((this->m_pEffectSetting)))->FUN_00403e60(0x100) ? 0 : *(int*)this;
}

struct FUN_00404420_shell : public EffectItem
{
    int FUN_00404420();
};

// @fnv 0x00404420
int FUN_00404420_shell::FUN_00404420()
{
    return (!reinterpret_cast<::S3e60 *>((m_pEffectSetting))->FUN_00403e60(0x200) && reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0() != 0) ? data.m_iArea : 0;
}

struct FUN_004044d0_shell : public EffectItem
{
    int FUN_004044d0();
};
// @fnv 0x00403f00
float FUN_00403f00_shell::FUN_00403f00()
{
    if (m_fCost < 0.0)
    {
        m_fCost = CalcEffectCost(((TESGrass*)((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())))->GetLowestAllowedSlope(), reinterpret_cast<::FUN_00404420_shell *>(this)->FUN_00404420(), reinterpret_cast<::FUN_004044d0_shell *>(this)->FUN_004044d0(),
                                 reinterpret_cast<::FUN_00404390_shell *>(this)->FUN_00404390(), reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0() == 2);
    }
    return m_fCost;
}
// @fnv 0x004042a0
bool FUN_004042a0_shell::IsDifferentFrom(EffectItem* apCompare)
{
    bool bDifferent = ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((apCompare))->FUN_00825c00())) != ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())) ||
                      reinterpret_cast<::FUN_00404390_shell *>((apCompare))->FUN_00404390() != reinterpret_cast<::FUN_00404390_shell *>(this)->FUN_00404390() || reinterpret_cast<::FUN_00404420_shell *>((apCompare))->FUN_00404420() != reinterpret_cast<::FUN_00404420_shell *>(this)->FUN_00404420() ||
                      reinterpret_cast<::FUN_004044d0_shell *>((apCompare))->FUN_004044d0() != reinterpret_cast<::FUN_004044d0_shell *>(this)->FUN_004044d0() || reinterpret_cast<::FUN_0084e3a0_Class *>((apCompare))->FUN_0084e3a0() != reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0() ||
                      apCompare->GetAffectedActorValue() != GetAffectedActorValue();

    if (((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>(this)->GetDataList())))
    {
        if (((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>(this)->GetDataList()))->Compare(((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>((apCompare))->GetDataList()))))
            return true;
    }
    else if (((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>((apCompare))->GetDataList())))
    {
        return true;
    }

    return bDifferent;
}

// Returns 0 if the EffectSetting at offset 0x14 has flag 0x80 set, otherwise returns the int at offset 0x8.
// @fnv 0x004044d0
int FUN_004044d0_shell::FUN_004044d0()
{
    return reinterpret_cast<::S3e60 *>(((this->m_pEffectSetting)))->FUN_00403e60(0x80) ? 0 : this->data.m_iPayloadInteger;
}

namespace fnv_004045e0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ExtraDataList;
struct ScriptHeaderData;
struct ScriptReferencedObject;
struct Script;
struct CStringArgument;
struct ScriptCompiler;
struct ScriptLocals;
struct TESObject;
struct TESObjectREFR;
struct TESQuest;
struct FUN_004045e0_shell : public EffectItem
{
    Script* GetScriptFromEffectSetting();
};

int _FNV_GetFormType(int);
__pragma(comment(
    linker, "/alternatename:?EffectSetting_GetArchetype@@YIHPAUEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ"))
    __pragma(comment(
        linker,
        "/alternatename:?EffectSetting_GetArchetype@@YIHAAVEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ"))

        class MagicEffectSystem
{
  public:
    struct _Type
    {
        enum Type
        {
        };
    };
};

class TESChallenge
{
  public:
    int GetInterval();
};

// @fnv 0x004045e0
Script* FUN_004045e0_shell::GetScriptFromEffectSetting()
{
    Script* pscript = 0;
    EffectSetting* psetting = ((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00()));
    if (::HasEffectArchetypeFlag((*(int *)&(const ::fnv_004045e0::MagicEffectSystem::_Type::Type &)((MagicEffectSystem::_Type::Type)reinterpret_cast<::EffectSetting *>((psetting))->GetArchetype())), 0x40))
    {
        if (((TESChallenge*)psetting)->GetInterval())
        {
            if (_FNV_GetFormType(((TESChallenge*)psetting)->GetInterval()) == 0x11)
            {
                pscript = (Script*)((TESChallenge*)((::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00())))->GetInterval();
            }
        }
    }
    return pscript;
}
}  // namespace fnv_004045e0


// @fnv 0x004046f0
void __cdecl FUN_004046f0(char* apStrDest, const char* apStrSource)
{
    std::strcpy(apStrDest, apStrSource);
}

struct S4eb0
{
    int a;
    unsigned int b;
    int c;
    S4eb0* FUN_00404eb0(int, bool, char*, int);
};
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct FUN_00404f00_shell : public AutoMemContext
{
    void FUN_00404f00(int, bool, char*, int);
};
// Calls FUN_00404f00 with the given arguments and returns this.
// @fnv 0x00404eb0
S4eb0* S4eb0::FUN_00404eb0(int m, bool o, char* f, int l)
{
    reinterpret_cast<::FUN_00404f00_shell *>(this)->FUN_00404f00(m, o, f, l);
    return this;
}

int __cdecl GetTlsField();

// @fnv 0x00404f00
void FUN_00404f00_shell::FUN_00404f00(int memContext, bool overridable, char* apFile, int aiLine)
{
    m_eMemoryContext = GetTlsField();
    ::fnv_00404f30::FUN_00404f30(memContext);
}

namespace fnv_00404f70 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct FUN_00404f70_shell : public AutoMemContext
{
    void FUN_00404f70();
};


// @fnv 0x00404f70
void FUN_00404f70_shell::FUN_00404f70()
{
    ::fnv_00404f30::FUN_00404f30(m_eMemoryContext);
}
}  // namespace fnv_00404f70


// @fnv 0x0044a670
unsigned int __cdecl FUN_0044a670(const char* apString)
{
    return std::strlen(apString);
}

namespace fnv_005f5f80 {
struct Actor;
struct ActorMover;
struct ActorPathHandler;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct DetailedActorPathHandler;
struct IDebugText;
struct NiPoint3;
struct PathingRequest;
struct TESObjectREFR;
struct blob12
{
    char b[12];
};
struct FUN_005f5f80_shell : public EffectSetting
{
    TESForm* FUN_005f5f80();
};

// @fnv 0x005f5f80
TESForm* FUN_005f5f80_shell::FUN_005f5f80()
{
    return *(TESForm**)((char*)this + 0x60);
}
}  // namespace fnv_005f5f80

// Returns the larger of the two integer arguments.
// @fnv 0x00647b70
int __cdecl FUN_00647b70(int iA, int iB)
{
    return iA > iB ? iA : iB;
}

extern "C" int __tls_index;

__declspec(thread) int DAT_tls_field = 0x3b;

// @fnv 0x00404f50
int __cdecl GetTlsField()
{
    return (*reinterpret_cast<int *>(&::currentAllocationContext));
}

struct MagicCaster;
struct FUN_0045cd60_shell : public ActiveEffect
{
    MagicCaster* FUN_0045cd60();
};

// @fnv 0x0045cd60
MagicCaster* FUN_0045cd60_shell::FUN_0045cd60()
{
    return *(MagicCaster**)((char*)this + 0x28);
}

struct FUN_004040b0_shell : BGSImpactData__IMPACT_DATA_DATA, EffectItem
{
    void Save();
};


struct TESConditionSave
{
};

// @fnv 0x004040b0
void FUN_004040b0_shell::Save()
{
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::OpaqueData *>(this)->SwapEndian();
    ::AppendChunk(0x54494645, this, 0x14);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::OpaqueData *>(this)->SwapEndian();
    if (((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>(this)->GetDataList())))
        reinterpret_cast<::FUN_00680910_shell *>((reinterpret_cast<TESConditionSave*>(((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>(this)->GetDataList())))))->ProcessItems();
}

struct EffectItem_shell : EffectItem
{
    bool FUN_00404470(int range);
};

// @fnv 0x00404470
bool EffectItem_shell::FUN_00404470(int range)
{
    bool result = false;
    if (!reinterpret_cast<::S3e60 *>((m_pEffectSetting))->FUN_00403e60(0x200))
    {
        if (reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0() != 0 && range >= 0)
        {
            data.m_iArea = range;
            m_fCost = -1.0f;
            result = true;
        }
    }
    return result;
}

namespace fnv_00404f30 {
extern "C" unsigned int __tls_index;

__declspec(thread) int tlsVar[0x2b4 / 4 + 1];

// @fnv 0x00404f30
void __cdecl FUN_00404f30(int aiValue)
{
    (*reinterpret_cast<int (*)[174]>(&::g_tlsBlock))[0x2b4 / 4] = aiValue;
}
}  // namespace fnv_00404f30

struct FUN_006808b0
{
    ~FUN_006808b0();
};
struct MyCondProxy
{
};
struct FUN_00403d50
{
    char _pad[0x1c];
    FUN_006808b0 _c;
    ~FUN_00403d50();
};
// Destroys the effect item's contents and, if flags has bit 0 set, deallocates the object; returns this.
// @fnv 0x004059d0
EffectItem* EffectItem::Delete(unsigned int flags)
{
    reinterpret_cast<::FUN_00403d50 *>(this)->FUN_00403d50::~FUN_00403d50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00403d50
FUN_00403d50::~FUN_00403d50()
{
    reinterpret_cast<::PerkEntryConditionSet *>((((MyCondProxy*)((::PerkEntryConditionSet *)(reinterpret_cast<::BGSDebris *>((((EffectItem*)this)))->GetDataList())))))->InitializeConditionItems();
}

struct Unk004043d0
{
    bool FUN_004043d0(int);
};
// @fnv 0x004043d0
bool Unk004043d0::FUN_004043d0(int a)
{
    bool result = false;
    if (!reinterpret_cast<::S3e60 *>(((*(EffectSetting**)((char*)this + 0x14))))->FUN_00403e60(0x100))
    {
        if (a >= 0)
        {
            *(int*)this = a;
            *(float*)((char*)this + 0x18) = -1.0f;
            result = true;
        }
    }
    return result;
}

struct S00404510
{
    char _00[8];
    int m08;
    char _0C[8];
    EffectSetting* m14;
    float m18;
    bool FUN_00404510(int);
};
// If m14 lacks flag 0x80 and a is non-negative, stores a in m08 and sets m18 to -1.0f, returning true; otherwise returns false.
// @fnv 0x00404510
bool S00404510::FUN_00404510(int aiValue)
{
    bool b = false;
    if (!reinterpret_cast<::S3e60 *>((m14))->FUN_00403e60(0x80) && aiValue >= 0)
    {
        m08 = aiValue;
        m18 = -1.0f;
        b = true;
    }
    return b;
}

struct Setting
{
    void* FUN_004049a0(unsigned int);
};
// @fnv 0x004049a0
void* Setting::FUN_004049a0(unsigned int flags)
{
    reinterpret_cast<::FUN_00404950 *>(this)->FUN_00404950::~FUN_00404950();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Dummy
{
    void* FUN_00404ca0(unsigned int);
};
// Calls FUN_00404c00, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00404ca0
void* Dummy::FUN_00404ca0(unsigned int flags)
{
    reinterpret_cast<::FUN_00404c00 *>(this)->FUN_00404c00::~FUN_00404c00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct ArrSI
{
};

struct MapH
{
};

struct FUN_00404f90_shell
{
    unsigned char _pad[0x10c];
    MapH _map;
    void RemoveSettingFromMap(ArrSI* apSetting);
};

// If apSetting is non-null and has flags set, removes the entry keyed by those flags from _map.
// @fnv 0x00404f90
void FUN_00404f90_shell::RemoveSettingFromMap(ArrSI* apSetting)
{
    if (apSetting && ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apSetting))->GetName())))
    {
        reinterpret_cast<::NiTMap_S *>(&(_map))->RemoveKey(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apSetting))->GetName())));
    }
}

namespace fnv_00404fd0 {
struct AutoMemHelper
{
    int padding;

    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
};

template <class T> struct NiTPrimitiveArray
{
};

struct Setting
{
};

struct MapX
{
};

struct NiTMap
{
};

template <class T> struct SettingCollectionMap
{
    unsigned int FUN_00404fd0(NiTPrimitiveArray<char*>*);
};

int _data_011c16bc;

// Iterates the map at offset 0x10c, calls FUN_00c33280 on each non-null Setting with apStringsA, and returns the count processed.
// @fnv 0x00404fd0
template <> unsigned int SettingCollectionMap<Setting>::FUN_00404fd0(NiTPrimitiveArray<char*>* apStringsA)
{
    unsigned int I;
    unsigned int cpkey;
    void* IT;
    AutoMemHelper tempMemContext(9, true, "..\\BSMain\\Setting.h", 0x239);
    Setting* pval;

    I = 0;
    IT = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((reinterpret_cast<MapX*>(reinterpret_cast<char*>(this) + 0x10c)))->GetFirstPos();
    while (IT != 0)
    {
        reinterpret_cast<::C6b7f20_Map *>((reinterpret_cast<NiTMap*>(reinterpret_cast<char*>(this) + 0x10c)))->FUN_006b7f20((::C6b7f20_Node **)&(IT), (unsigned int *)&(cpkey), (void **)&(reinterpret_cast<void*&>(pval)));

        if (pval != 0)
        {
            reinterpret_cast<::FUN_00c33280_Class *>((pval))->FUN_00c33280((::NiTPrimitiveArray_unsigned_int_ *)(apStringsA));
            ++I;
        }
    }

    return I;
}
}  // namespace fnv_00404fd0

class FUN_00403b30_base
{
  public:
    FUN_00403b30_base();
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
};

class FUN_00403b30_member
{
  public:
    FUN_00403b30_member();
    ~FUN_00403b30_member();
    unsigned int m_00;
};

class FUN_00403b30_cls : public FUN_00403b30_base
{
  public:
    FUN_00403b30_member m_1c;
    FUN_00403b30_cls(int a);
};


struct FUN_00403be0_target
{
};

class FUN_00403be0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int m_iResult;
    InterfaceManager* m_pManager;
    float m_fValue;

    void FUN_00403be0(InterfaceManager* manager);
};
// Initializes the base and member subobjects, then calls Init with the given value.
// @fnv 0x00403b30
FUN_00403b30_cls::FUN_00403b30_cls(int aiValue) : FUN_00403b30_base(), m_1c()
{
    reinterpret_cast<::FUN_00403be0_cls *>(this)->FUN_00403be0((::InterfaceManager *)(aiValue));
}

// Stores manager, zeroes three fields, sets m_iResult from HasFlag2/FUN_00586150 or -1, and sets m_fValue to DAT_01012054.
// @fnv 0x00403be0
void FUN_00403be0_cls::FUN_00403be0(InterfaceManager* manager)
{
    m_pManager = manager;
    unk04 = 0;
    unk08 = 0;
    unk00 = 0;
    m_iResult = reinterpret_cast<::S3c60 *>((reinterpret_cast<FUN_00403be0_target*>(m_pManager)))->HasFlag2() ? (int)m_pManager->FUN_00586150() : -1;
    m_fValue = ::DAT_01012054;
}

// @fnv 0x00404090
float TruncateToInt(float fValue)
{
    return (float)(int)fValue;
}

struct MapAccess
{
};
struct EffectProcess
{
    virtual void unknown00() = 0;
    virtual void unknown04() = 0;
    virtual void unknown08() = 0;
    virtual void unknown0c() = 0;
    virtual bool ProcessEffect(void* effect) = 0;
    bool FUN_00404d30();
    bool ProcessAllEffects();
};
// If FUN_00404d30 succeeds, iterates the map at this+0x10c and ANDs ProcessEffect over each non-null effect; returns the result.
// @fnv 0x004050a0
bool EffectProcess::ProcessAllEffects()
{
    bool result = FUN_00404d30();
    if (result)
    {
        int key;
        {
            void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapAccess*)((char*)this + 0x10c))))->GetFirstPos();
            while (position != 0)
            {
                void* effect;
                reinterpret_cast<::C6b7f20_Map *>((((MapAccess*)((char*)this + 0x10c))))->FUN_006b7f20((::C6b7f20_Node **)(void **)(&position), (unsigned int *)(int *)(&key), &effect);
                if (effect != 0)
                    result &= ProcessEffect(effect);
            }
        }
    }
    return result;
}

namespace fnv_00404560 {

struct FUN_00404210_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S3e60* unk14;
    float unk18;

    bool FUN_00404560(unsigned int value);
};

// @fnv 0x00404560
bool FUN_00404210_t::FUN_00404560(unsigned int value)
{
    bool result = false;

    if ((value == 1 && this->unk14->FUN_00403e60(0x20)) || (value == 2 && this->unk14->FUN_00403e60(0x40)) ||
        (value == 0 && this->unk14->FUN_00403e60(0x10)))
    {
        this->unk0C = value;
        this->unk18 = ::DAT_01012054;
        result = true;
    }

    return result;
}
}  // namespace fnv_00404560

struct SettingMap
{
};
struct SettingRegistry
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual bool HandleSetting(int);
    bool FUN_00405120();
};
extern "C" bool FUN_00404d30(SettingRegistry*);
extern "C" void FUN_00404ee0(S4eb0*);
struct ScopedContext
{
    int previousContext;
    __forceinline ScopedContext(int context, bool temporary, char* file, int line)
    {
        reinterpret_cast<S4eb0*>(this)->FUN_00404eb0(context, temporary, file, line);
    }
    __forceinline ~ScopedContext()
    {
        FUN_00404ee0(reinterpret_cast<S4eb0*>(this));
    }
};
// @fnv 0x00405120
bool SettingRegistry::FUN_00405120()
{
    int key;
    ScopedContext memoryGuard(9, true, str_01012220, 0x278);
    bool isValid = FUN_00404d30(this);
    if (isValid)
    {
        int iterator = ((int)(reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((reinterpret_cast<SettingMap*>(reinterpret_cast<char*>(this) + 0x10c)))->GetFirstPos()));
        while (iterator != 0)
        {
            int value;
            reinterpret_cast<::C6b7f20_Map *>((reinterpret_cast<SettingMap*>(reinterpret_cast<char*>(this) + 0x10c)))->FUN_006b7f20((::C6b7f20_Node **)(int *)(&iterator), (unsigned int *)(int *)(&key), (void **)(int *)(&value));
            if (value != 0)
                isValid = isValid & HandleSetting(value);
        }
    }
    return isValid;
}


struct FUN_004d61b0_sub
{
    FUN_004d61b0_sub(int aValue);
    ~FUN_004d61b0_sub();
};

class FUN_004d61b0
{
  public:
    int m00;
    int m04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_004d61b0_sub m18;
    int unk1C;
    int unk20;
    int unk24;
    int m28;
    char* m2c;

    FUN_004d61b0(int a1, int a2, int a3, const char* a4, int a5, int a6, int a7, int a8);
};

// @fnv 0x004d61b0
FUN_004d61b0::FUN_004d61b0(int a1, int a2, int a3, const char* apName, int a5, int a6, int a7, int a8) : m18(0x25)
{
    m00 = a1;
    m04 = a2;
    m28 = a3;
    char* pNameBuffer = ((char *)(::FUN_00401000(FUN_0044a670(apName) + 1)));
    m2c = pNameBuffer;
    FUN_004046f0(m2c, ((const char *)(::FUN_00464f30((int)(apName)))));
    reinterpret_cast<::TreeCtrl4d63 *>(this)->CreateTreeWindows(a5, a6, a7, a8);
    reinterpret_cast<::FUN_004d6490_Class *>(this)->FUN_004d6490();
    if (a3 != 0)
    {
        reinterpret_cast<::Owner64 *>(this)->FUN_004d64c0(a3, (const char *)(0));
    }
}

#include "generated/data/fallout_shared/magic/effectitem.inc"
