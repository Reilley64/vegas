// fallout/ai/modifierlist.cpp: ModifierListCalc (21 functions)

#include "fnv/simple_list_node_view.h"
#include "fnv/save_load_game_view.h"
#include <cstdint>
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FUN_00937f40_Class.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ModifierRoutingList.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00937000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "modifierlist_decls.h"


// Deletes every Modifier returned by GetItem while removing list heads, then deletes and nulls the stored object.
// @fnv 0x009370b0
void ActorValueModifierList::RemoveAllModifiers()
{
    Modifier* modifier;
    while ((modifier = ((::Modifier *)(((::Vec3 *)(void *)this)))) != 0)
    {
        Modifier* node = modifier;
        ::FUN_00401030(node);
        RemoveHead();
    }

    if (m_ppModifiedActorValues)
    {
        delete m_ppModifiedActorValues;
        m_ppModifiedActorValues = 0;
    }
}

// Removes any existing modifier for key, then stores modifier in the fast-modifier table unless it is null or the zero value with no override.
// @fnv 0x00937280
void ActorValueModifierList::AddFastModifier(char key, Modifier* modifier)
{
    if (!modifier && !m_ppModifiedActorValues)
        return;

    if (m_ppModifiedActorValues)
        m_ppModifiedActorValues->RemoveModifier(key);

    if (!modifier || (reinterpret_cast<::TimeoutTimer *>((modifier))->FUN_006b9130() == ::_DAT_01012060 && !m_bAllowZeroValueModifiers))
        return;

    if (!m_ppModifiedActorValues)
        m_ppModifiedActorValues = new ModifierPointerList();

    m_ppModifiedActorValues->m_ppModifiers[gModifierListIndex[key]] = modifier;
}

// @fnv 0x00937760
Modifier* ActorValueModifierList::GetModifierItem(char key)
{
    struct SearchState
    {
        ActorValueModifierList* current;
        Modifier* modifier;
    } searchState;
    searchState.modifier = 0;
    if (m_ppModifiedActorValues && gModifierListIndex[key] < 0x4d)
    {
        searchState.modifier = m_ppModifiedActorValues->m_ppModifiers[gModifierListIndex[key]];
    }
    else
    {
        searchState.current = this;
        while (searchState.current && ((::Modifier *)(((::Vec3 *)(void *)(searchState.current)))) != 0 && !searchState.modifier)
        {
            Modifier* item = ((::Modifier *)(((::Vec3 *)(void *)(searchState.current))));
            if (item && ((char)(reinterpret_cast<::FUN_009373f0_shell *>((item))->FUN_009373f0())) == key)
                searchState.modifier = item;
            searchState.current = (ActorValueModifierList*)((::BSSimpleList< ::Modifier *> *)(reinterpret_cast<::Callees *>((searchState.current))->FUN_00726070()));
        }
    }
    return searchState.modifier;
}

// Calls the two-argument overload with a fresh found flag and returns its float result for the given key.
// @fnv 0x00937730
float ActorValueModifierList::GetActorValueModifierAmount(char key)
{
    bool found = false;
    return GetActorValueModifierAmount(key, found);
}

// Looks up the modifier for key, sets found based on whether it exists, and returns its value or 0.0f.
// @fnv 0x009376e0
float ActorValueModifierList::GetActorValueModifierAmount(char key, bool& found)
{
    Modifier* modifier = GetModifierItem(key);
    found = (unsigned char)(modifier != 0);
    return modifier ? reinterpret_cast<::TimeoutTimer *>((modifier))->FUN_006b9130() : 0.0f;
}

// @fnv 0x00937160
void ActorValueModifierList::CopyModifierListFrom(ActorValueModifierList* apSource)
{
    RemoveAllModifiers();
    if (!apSource)
        return;
    if (apSource->m_ppModifiedActorValues)
        m_ppModifiedActorValues = new ModifierPointerList(apSource->m_ppModifiedActorValues);
    ActorValueModifierList* current = apSource;
    while (current && ((::Modifier *)(((::Vec3 *)(void *)(current)))) != 0)
    {
        Modifier* item = ((::Modifier *)(((::Vec3 *)(void *)(current))));
        reinterpret_cast<::ModifierRoutingList *>(this)->FUN_00937380((::ModifierEntryView *)(::Modifier *)(new Modifier(item)));
        current = (ActorValueModifierList*)((::BSSimpleList< ::Modifier *> *)(reinterpret_cast<::SimpleListNodeView *>((current))->m_pkNext));
    }
}

struct FUN_009375b0_shell : Modifier
{
    Modifier* SetKeyAndValue(char key, float value);
};

// Stores the key character, applies the float value via SetValue, and returns this modifier.
// @fnv 0x009375b0
Modifier* FUN_009375b0_shell::SetKeyAndValue(char key, float value)
{
    cKey = key;
    reinterpret_cast<::FUN_004f5d90_shell *>(this)->FUN_004f5d90(value);
    return this;
}

void __cdecl FUN_00937fd0();

// Calls FUN_00937fd0, then allocates an int array of DAT_011e0750 elements, zeroes it, and stores the pointer through pThis.
// @fnv 0x00937d70
int** FUN_00937d70(int** apArrayOut)
{
    FUN_00937fd0();
    if (DAT_011e0750)
    {
        *apArrayOut = DAT_011e0750 ? new int[DAT_011e0750] : 0;
        for (int i = 0; i < DAT_011e0750; ++i)
        {
            (*apArrayOut)[i] = 0;
        }
    }
    else
    {
        *apArrayOut = 0;
    }
    return apArrayOut;
}

struct FUN_009375e0_shell : public ActorValueModifierList
{
    void FUN_009375e0(char key, float value);
};

// Adds param1 and param2, then clamps the sum to 0.0f when param3 is 0 (if above _gModifierZero) or 1 (if below), returning the result.
// @fnv 0x00937810
float __cdecl ClampSumByMode(float afValueA, float afValueB, intptr_t aiMode)
{
    float result = afValueA + afValueB;
    switch (aiMode)
    {
    case 0:
        if (result > ::_DAT_01012060)
            result = 0.0f;
        break;
    case 1:
        if (result < ::_DAT_01012060)
            result = 0.0f;
        break;
    default:
        break;
    }
    return result;
}

struct FUN_00937b30_shell : ActorValueModifierList
{
    void FUN_00937b30();
};

// @fnv 0x00937b30
void FUN_00937b30_shell::FUN_00937b30()
{
    RemoveAllModifiers();
}

struct FUN_00936fd0_shell
{
    char cKey;
    FUN_00936fd0_shell* CopyFrom(Modifier*);
};
// Copies the key and value from another Modifier into this one and returns this.
// @fnv 0x00936fd0
FUN_00936fd0_shell* FUN_00936fd0_shell::CopyFrom(Modifier* other)
{
    cKey = other->cKey;
    reinterpret_cast<::FUN_004f5d90_shell *>((((Modifier*)this)))->FUN_004f5d90(reinterpret_cast<::TimeoutTimer *>((other))->FUN_006b9130());
    return this;
}

struct Unk3713
{
    void* ReleaseIfFlagged(unsigned int);
};
// @fnv 0x00937130
void* Unk3713::ReleaseIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00937f40_Class *>(this)->FreeArrayItems();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct TESSaveLoadGame
{
};
struct Host37870
{
    bool FUN_00937870(Modifier* p);
};
// @fnv 0x00937870
bool Host37870::FUN_00937870(Modifier* apModifier)
{
    if (apModifier == 0)
        return false;
    char key = ((char)(reinterpret_cast<::FUN_009373f0_shell *>((apModifier))->FUN_009373f0()));
    float value = reinterpret_cast<::TimeoutTimer *>((apModifier))->FUN_006b9130();
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&key, 1);
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&value, 4);
    return true;
}

namespace fnv_009379c0 {
struct TESSaveLoadGame
{
};
struct FUN_009379c0_shell : ActorValueModifierList
{
    void LoadModifiers();
};
// @fnv 0x009379c0
void FUN_009379c0_shell::LoadModifiers()
{
    unsigned short count;
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_009379c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&count, 2);
    for (unsigned int i = 0; i < count; i++)
    {
        char key;
        float value;
        Modifier* modifier = 0;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_009379c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&key, 1);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_009379c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&value, 4);
        modifier = new Modifier(key, value);
        reinterpret_cast<::ModifierRoutingList *>(this)->FUN_00937380((::ModifierEntryView *)(modifier));
    }
}
}  // namespace fnv_009379c0

namespace fnv_009378d0 {
struct Modifier;

struct BSSimpleList_helper
{
};

struct GameTimerRecord
{
};

struct TESSaveLoadGame : GameTimerRecord
{
};

struct Host37870
{
};


struct FUN_009378d0_shell : Host37870
{
    void CountModifiers();
    unsigned int pad00[0x3];
    void* unk0c;
};

// @fnv 0x009378d0
void FUN_009378d0_shell::CountModifiers()
{
    unsigned short icount = 0;
    unsigned short* pusCount = (unsigned short*)reinterpret_cast<::SaveLoadGameView *>((void *)((*reinterpret_cast<::fnv_009378d0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->pBufferCursor;
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_009378d0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&icount, 2);

    BSSimpleList<Modifier*>* pmodlist = (BSSimpleList<Modifier*>*)this;
    while (pmodlist && *((::fnv_009378d0::Modifier **)(((::Vec3 *)(void *)(((BSSimpleList_helper*)pmodlist))))))
    {
        Modifier* pmod = *((::fnv_009378d0::Modifier **)(((::Vec3 *)(void *)(((BSSimpleList_helper*)pmodlist)))));
        if (reinterpret_cast<::Host37870 *>(this)->FUN_00937870((::Modifier *)(pmod)))
            icount++;
        pmodlist = ((::BSSimpleList< ::fnv_009378d0::Modifier *> *)(reinterpret_cast<::SimpleListNodeView *>((pmodlist))->m_pkNext));
    }

    int ifastCount = this->unk0c ? ::DAT_011e0750 : 0;
    if (ifastCount)
    {
        for (int i = 0; i < ifastCount; i++)
        {
            reinterpret_cast<::Host37870 *>(this)->FUN_00937870((::Modifier *)((*(Modifier***)this->unk0c)[i]));
            icount++;
        }
    }

    *pusCount = icount;
}
}  // namespace fnv_009378d0

namespace fnv_00938060 {
struct FUN_00938060_s
{
    void** m_pEntries;
    void FreeModifierEntry(int aiIndex);
};


// @fnv 0x00938060
void FUN_00938060_s::FreeModifierEntry(int aiIndex)
{
    if (aiIndex >= 0 && aiIndex < 77 && m_pEntries)
    {
        if (gModifierListIndex[aiIndex] < 77 && m_pEntries[gModifierListIndex[aiIndex]])
        {
            void* pv = m_pEntries[gModifierListIndex[aiIndex]];
            ::FUN_00401030(pv);
            m_pEntries[gModifierListIndex[aiIndex]] = 0;
        }
    }
}
}  // namespace fnv_00938060

extern unsigned int _data_011c16bc;

struct FUN_00937e10
{
    Modifier** m_ppModifiers;

    FUN_00937e10(FUN_00937e10* other);
};

// Copy constructor: allocates an array of DAT_011e0750 Modifier pointers and deep-copies each non-null element from other, or stores null.
// @fnv 0x00937e10
FUN_00937e10::FUN_00937e10(FUN_00937e10* other)
{
    if (other->m_ppModifiers)
    {
        m_ppModifiers = DAT_011e0750 ? new Modifier*[DAT_011e0750] : 0;

        for (int i = 0; i < DAT_011e0750; ++i)
        {
            if (other->m_ppModifiers[i])
            {
                m_ppModifiers[i] = new Modifier(other->m_ppModifiers[i]);
            }
            else
            {
                m_ppModifiers[i] = 0;
            }
        }
    }
    else
    {
        m_ppModifiers = 0;
    }
}


struct ModifierListCalc : public ActorValueModifierList
{
    int GetSlotCount();
    unsigned short FUN_00937ab0();
};

// Computes a total from key4 times GetSlotCount() plus 2, plus key4 times a mask derived from DAT_011e0750, and returns it.
// @fnv 0x00937ab0
unsigned short ModifierListCalc::FUN_00937ab0()
{
    unsigned short total = 0;
    int mask;
    unsigned short key4 = 0;
    key4 = 5;
    if (key4 == 0)
    {
        return 0;
    }
    total += key4 * GetSlotCount() + 2;
    mask = ((m_ppModifiedActorValues != 0) ? -1 : 0) & DAT_011e0750;
    total += key4 * mask;
    return total;
}

class ActorValueInfo
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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned int uiFlags;
};
namespace ActorValue {
}

class FUN_00937400_ModifierList : public BSSimpleList<Modifier*>
{
  public:
    bool m_bAllowZeroValueModifiers;
    ModifierPointerList* m_ppModifiedActorValues;

    void FUN_00937400(Modifier* modifier);
};
// @fnv 0x00937480
void ActorValueModifierList::ModifyModifier(char key, float delta, ClampStyle clamp)
{
    Modifier* modifier = GetModifierItem(key);
    if (!modifier)
    {
        if (delta != ::_DAT_01012060 || m_bAllowZeroValueModifiers)
        {
            modifier = new Modifier(key, delta);
            reinterpret_cast<::ModifierRoutingList *>(this)->FUN_00937380((::ModifierEntryView *)(modifier));
        }
    }
    else
    {
        float value = ::ClampSumByMode(reinterpret_cast<::TimeoutTimer *>((modifier))->FUN_006b9130(), delta, (*(int *)&(clamp)));
        reinterpret_cast<::FUN_004f5d90_shell *>((modifier))->FUN_004f5d90(value);
        if (reinterpret_cast<::TimeoutTimer *>((modifier))->FUN_006b9130() == ::_DAT_01012060 && !m_bAllowZeroValueModifiers)
            reinterpret_cast<::FUN_00937400_ModifierList *>(this)->FUN_00937400(modifier);
    }
}
// @fnv 0x009375e0
void FUN_009375e0_shell::FUN_009375e0(char key, float value)
{
    Modifier* modifier = GetModifierItem(key);
    if (!modifier)
    {
        if (value != ::_DAT_01012060 || m_bAllowZeroValueModifiers)
        {
            modifier = new Modifier(key, value);
            reinterpret_cast<::ModifierRoutingList *>(this)->FUN_00937380((::ModifierEntryView *)(modifier));
        }
    }
    else if (value == ::_DAT_01012060 && !m_bAllowZeroValueModifiers)
    {
        reinterpret_cast<::FUN_00937400_ModifierList *>(this)->FUN_00937400(modifier);
    }
    else
    {
        reinterpret_cast<::FUN_004f5d90_shell *>((modifier))->FUN_004f5d90(value);
    }
}

// Removes a modifier from the list, or from m_ppModifiedActorValues when the actor value is flagged and tracked there.
// @fnv 0x00937400
void FUN_00937400_ModifierList::FUN_00937400(Modifier* modifier)
{
    if (!modifier)
        return;
    ActorValueInfo* pkInfo = ((::ActorValueInfo *)(::FUN_0066e920((*(int *)&(const ::ActorValue::Index &)((ActorValue::Index)((char)(reinterpret_cast<::FUN_009373f0_shell *>((modifier))->FUN_009373f0())))))));
    if (pkInfo && (pkInfo->uiFlags & 1) && m_ppModifiedActorValues)
    {
        reinterpret_cast<::fnv_00938060::FUN_00938060_s *>((m_ppModifiedActorValues))->FreeModifierEntry(((char)(reinterpret_cast<::FUN_009373f0_shell *>((modifier))->FUN_009373f0())));
        return;
    }
    reinterpret_cast<::ItemChangeListNode *>(this)->FUN_00905330((::InventoryStackRecord *const &)(modifier));
    delete modifier;
}

#include "generated/data/fallout/ai/modifierlist.inc"
