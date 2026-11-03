// fallout_shared/magic/enchantmentitem.cpp: EnchantmentItem, MagicShaderHitEffect, SpellItem, Unnamed and more (11 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00409210.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_0040e500_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FlaggedData.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S_004063e0.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/fnv_00406340__EffectItemList.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_009e3000.h"
#include "enchantmentitem.h"

// @fnv 0x009d6b60
TEMP_EFFECT_TYPE MagicShaderHitEffect::GetType()
{
    return MAGIC_HIT_EFFECT_SHADER;
}

#include "enchantmentitem_packet.h"
// @fnv 0x00409340
void SpellItem::ClearData()
{
    reinterpret_cast<::fnv_00406340::EffectItemList *>(&(effects))->FUN_00406340();
}
// @fnv 0x00409310
void EnchantmentItem::ResetFormData()
{
    cost = 0xffffffff;
    charge = 0xffffffff;
    flags = 0;
    type = 2;
}

// @fnv 0x00409080
EnchantmentItem::EnchantmentItem()
{
    formVtable = DAT_01012ea4;
    nameVtable = DAT_01012e5c;
    effects.vtable = DAT_01012e44;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(FORM_ENCHANTMENT)));
    ResetFormData();
}

struct FUN_00409160_Class
{
    void FUN_004092a0();
    void* DestroyIfFlagged(unsigned int);
};
struct Unnamed
{
    void* FUN_00409270(unsigned int);
};
// Calls FUN_00409210, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00409270
void* Unnamed::FUN_00409270(unsigned int flags)
{
    reinterpret_cast<::FUN_00409210 *>(this)->FUN_00409210::~FUN_00409210();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct TESActorBase
{
    virtual ~TESActorBase();
};
struct TESSound;
struct TESTopicInfoData;
struct MagicItem
{
    virtual ~MagicItem();
};
struct TESTopicInfo
{
    virtual ~TESTopicInfo();
};
struct EP_008c48d0
{
};
struct CP_008c48d0
{
};
struct BGSAcousticSpace
{
};
struct TES
{
};
struct FUN_00409400_shell
{
    void CopySoundAndSpeakerData(MagicItem*);
};
// Casts actor to EnchantmentItem, then copies its conversation data, entry point, prev path and byte at 0x40 into fields of the object at this-0x18.
// @fnv 0x00409400
void FUN_00409400_shell::CopySoundAndSpeakerData(MagicItem* apItem)
{
    EnchantmentItem* info = dynamic_cast<EnchantmentItem*>(apItem);
    if (!info)
        return;
    reinterpret_cast<::FUN_0040e500_shell *>((((BGSAcousticSpace*)((char*)this - 0x18))))->SetValue((std::intptr_t)(((::TESSound *)(::GetField38((char *)(((TESTopicInfo*)info)))))));
    reinterpret_cast<::FUN_00409480_shell *>((((TESTopicInfo*)((char*)this - 0x18))))->FUN_00409480((::TESActorBase *)(::MagicItem *)(((::MagicItem *)(reinterpret_cast<::Twin_00639b40 *>((((EP_008c48d0*)info)))->GetEntryPoint()))));
    reinterpret_cast<::LowProcess *>((((TES*)((char*)this - 0x18))))->SetCurrentBoundObject((::TESBoundObject *)(::TESSound *)(((::TESSound *)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)info)))->GetPrevPath()))));
    ((char*)this)[0x28] = (*(char*)&info->flags);
}

namespace fnv_004094a0 {
struct FlaggedData
{
};
struct EP_008c48d0
{
};
struct S_004063e0
{
};

struct FUN_004094a0_Class
{
    float FUN_004094a0(int);
};

// Returns the entry point value as a float if the check on the object at this-0x24 passes, otherwise calls GetTotalCost(0).
// @fnv 0x004094a0
float FUN_004094a0_Class::FUN_004094a0(int apActor)
{
    if (((bool)(reinterpret_cast<::FlaggedData *>((((FlaggedData*)((char*)this - 0x24))))->ContainsAnyFlag(1))))
    {
        return (float)(std::intptr_t)((void *)(reinterpret_cast<::Twin_00639b40 *>((((EP_008c48d0*)((char*)this - 0x24))))->GetEntryPoint()));
    }
    else
    {
        return reinterpret_cast<::S_004063e0 *>((((S_004063e0*)this)))->GetTotalCost((::Actor *)(0));
    }
}
}  // namespace fnv_004094a0

struct IMH
{
};

struct IngredientItem : MagicItem
{
};

struct FUN_00409fd0_shell : EnchantmentItem
{
    bool FUN_00409fd0(MagicItem* apCompare);
};

// Returns true unless apCompare is an IngredientItem with the same FUN_00586150 value and matching byte at offset 0xa0 as this object.
// @fnv 0x00409fd0
bool FUN_00409fd0_shell::FUN_00409fd0(MagicItem* apCompare)
{
    EnchantmentItem* penchantment = (EnchantmentItem*)dynamic_cast<IngredientItem*>(apCompare);
    if (!penchantment)
        return true;
    if (((std::intptr_t)(reinterpret_cast<::InterfaceManager *>((((IMH*)((char*)penchantment))))->FUN_00586150())) != ((int)(std::uintptr_t)(reinterpret_cast<::InterfaceManager *>((((IMH*)((char*)this - 0x30))))->FUN_00586150())) ||
        *(unsigned char*)((char*)penchantment + 0xa0) != *(unsigned char*)((char*)this + 0x70))
        return true;
    return false;
}

struct PrimaryBase
{
    virtual ~PrimaryBase();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
};
struct SecondaryBase
{
    virtual void access();
    unsigned int unk1c, unk20;
};
struct TertiaryBase
{
    virtual void access();
};
struct FUN_004092a0 : PrimaryBase, SecondaryBase, TertiaryBase
{
    ~FUN_004092a0();
};
// Calls FUN_004092a0, frees this when flags has bit 1 set, and returns this.
// @fnv 0x00409160
void* FUN_00409160_Class::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004092a0 *>(this)->FUN_004092a0::~FUN_004092a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that calls FUN_00409340 before the object is destroyed.
// @fnv 0x004092a0
FUN_004092a0::~FUN_004092a0()
{
    reinterpret_cast<::SpellItem *>(this)->ClearData();
}

struct EnchantmentMagicPart : MagicItem
{
    unsigned int nameData04;
    unsigned int nameData08;
    EffectItemList effects;
    virtual bool FUN_00409360(MagicItem* object) = 0;
};

struct EnchantmentComparison : PrimaryBase, EnchantmentMagicPart
{
    unsigned int type;
    unsigned int charge;
    unsigned int cost;
    unsigned char flags;
    virtual bool FUN_00409360(MagicItem* object);
};

// Returns true if the cast fails or any of three accessor results or flags differ; otherwise returns false.
// @fnv 0x00409360
bool EnchantmentComparison::FUN_00409360(MagicItem* apMagicItem)
{
    EnchantmentItem* pEnchantmentItem = dynamic_cast<EnchantmentItem*>(apMagicItem);
    if (pEnchantmentItem == 0)
        return true;

    if (((unsigned int)(::GetField38((char *)(reinterpret_cast<EnchantmentComparison*>(pEnchantmentItem))))) != ((unsigned int)(::GetField38((char *)this))) ||
        ((std::uintptr_t)(reinterpret_cast<::Twin_00639b40 *>((reinterpret_cast<EnchantmentComparison*>(pEnchantmentItem)))->GetEntryPoint())) != ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_00639b40 *>(this)->GetEntryPoint())) ||
        ((std::uintptr_t)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<EnchantmentComparison*>(pEnchantmentItem)))->GetPrevPath())) != ((unsigned int)(std::uintptr_t)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())) ||
        pEnchantmentItem->flags != flags)
        return true;
    return false;
}
