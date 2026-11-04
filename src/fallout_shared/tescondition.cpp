// fallout_shared/tescondition.cpp: free functions (14 functions)

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/ConditionSerializer.h"
#include "fnv/decl/Date.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_005ec040_stand.h"
#include "fnv/decl/S00681590.h"
#include "fnv/decl/S_006815d0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/s5693d0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "tescondition_decls.h"

// Runs the condition on subject and target references, discarding the result and passing false.
// @fnv 0x00680c30
bool PerkEntryConditionSet::ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target)
{
    bool result;
    return ContainsTrait(subject, target, result, false);
}

// Calls InitItem(form) on each TESConditionItem in the list obtained from GetItem(), walking the list until it is empty.
// @fnv 0x00680a20
void PerkEntryConditionSet::InitItem(TESForm* form)
{
    BSSimpleList<TESConditionItem*>* current = (BSSimpleList<TESConditionItem*>*)&(m_kConditionItems.m_item);
    while (current && !current->IsEmpty())
    {
        (current->m_item)->InitItem(form);
        current = ((::BSSimpleList< ::TESConditionItem *> *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
    }
}

// Deletes each TESConditionItem in the list obtained from GetItem and removes the head until the list is empty.
// @fnv 0x00680fe0
void PerkEntryConditionSet::InitializeConditionItems()
{
    BSSimpleList<TESConditionItem*>* current = (BSSimpleList<TESConditionItem*>*)&(m_kConditionItems.m_item);
    while (current && !current->IsEmpty())
    {
        delete (current->m_item);
        current->RemoveHead();
    }
}

// @fnv 0x00680960
void PerkEntryConditionSet::Load(TESFile* file)
{
    if (file)
    {
        TESConditionItem* item = 0;
        switch (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
        {
        case 0x41445443:
            item = new TESConditionItem;
            item->Load(file);
            ((PackageList*)this)->AddPackage((TESPackage*)item);
            break;
        }
    }
}

// @fnv 0x00680b70
bool PerkEntryConditionSet::Compare(PerkEntryConditionSet* other)
{
    BSSimpleList<TESConditionItem*>* left = (BSSimpleList<TESConditionItem*>*)&(m_kConditionItems.m_item);
    BSSimpleList<TESConditionItem*>* right = (BSSimpleList<TESConditionItem*>*)&(other->m_kConditionItems.m_item);
    struct ItemPair
    {
        TESConditionItem* leftItem;
        TESConditionItem* rightItem;
    } items;
    while (right && !right->IsEmpty())
    {
        if (!left || left->IsEmpty())
            return true;
        items.leftItem = (left->m_item);
        items.rightItem = (right->m_item);
        if (reinterpret_cast<::S_006815d0 *>((items.leftItem))->IsDifferentFrom(items.rightItem))
            return true;
        left = ((::BSSimpleList< ::TESConditionItem *> *)(reinterpret_cast<::Callees *>((left))->FUN_00726070()));
        right = ((::BSSimpleList< ::TESConditionItem *> *)(reinterpret_cast<::Callees *>((right))->FUN_00726070()));
    }
    if (left && !left->IsEmpty())
        return true;
    return false;
}

// @fnv 0x00680c60
bool PerkEntryConditionSet::ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target, bool& result, bool filter)
{
    struct EvaluationState
    {
        char padding00, padding01, padding02;
        bool unknown;
        TESConditionItem* item;
        char padding10, padding11, padding12;
        bool skip;
        TESObjectREFR* replacement;
        char padding20, padding21;
        bool inOr;
        bool all;
        BSSimpleList<TESConditionItem*>* current;
        bool value;
        bool orFalse;
        bool definiteFalse;
        bool orUnknown;
    } state;
    state.current = (BSSimpleList<TESConditionItem*>*)&(m_kConditionItems.m_item);
    if (state.current->IsEmpty())
    {
        result = false;
        return true;
    }
    state.all = true;
    state.value = false;
    state.inOr = false;
    state.orUnknown = false;
    state.orFalse = false;
    result = false;
    state.definiteFalse = false;
    if (target)
    {
        state.replacement = ((::TESObjectREFR *)(std::uintptr_t)(reinterpret_cast<::s5693d0::Owner *>((target))->FUN_005693d0()));
        if (state.replacement)
            target = state.replacement;
    }
    while (state.current && !state.current->IsEmpty())
    {
        state.item = (state.current->m_item);
        state.skip = false;
        if (filter)
        {
            switch ((int)*(unsigned short*)((TESTopicInfoData*)state.item)->GetLinkToList())
            {
            case 68:
            case 69:
            case 70:
            case 71:
            case 72:
            case 372:
                break;
            default:
                state.skip = true;
            }
        }
        state.unknown = false;
        if (!state.inOr)
        {
            if (!((bool)(reinterpret_cast<::FUN_005ec040_stand *>((state.item))->IsFlagSet())))
            {
                state.value = state.skip ? true : state.item->ContainsTrait(subject, target, state.unknown);
                state.all = state.all && state.value;
                if (state.unknown)
                    result = true;
                else if (!state.value)
                    state.definiteFalse = true;
            }
            else
            {
                state.value = state.item->ContainsTrait(subject, target, state.unknown);
                state.inOr = true;
                state.orFalse = false;
                state.orUnknown = state.unknown;
                if (!state.unknown && !state.value)
                    state.orFalse = true;
            }
        }
        else
        {
            if (!state.value)
            {
                state.value = state.skip ? state.skip : state.item->ContainsTrait(subject, target, state.unknown);
                state.orUnknown = state.orUnknown || state.unknown;
                if (!state.unknown && !state.value)
                    state.orFalse = true;
            }
            if (!((bool)(reinterpret_cast<::FUN_005ec040_stand *>((state.item))->IsFlagSet())))
            {
                state.inOr = false;
                state.all = state.all && state.value;
                if (!state.all)
                {
                    if (state.orUnknown && !state.orFalse)
                        result = true;
                    else
                        state.definiteFalse = true;
                }
            }
        }
        if (!state.all && !state.inOr && !result)
            break;
        state.current = ((::BSSimpleList< ::TESConditionItem *> *)(reinterpret_cast<::Callees *>((state.current))->FUN_00726070()));
    }
    if (state.inOr)
    {
        state.all = state.all && state.value;
        if (!state.all)
        {
            if (state.orUnknown && !state.orFalse)
                result = true;
            else
                state.definiteFalse = true;
        }
    }
    if (state.all || state.definiteFalse)
        result = false;
    return state.all;
}

extern int DAT_01046b48;

struct FUN_005e9530_Obj
{
    void* vftable;
    unsigned char b4;
    unsigned char b5;
    FUN_005e9530_Obj();
};

// Sets the object's vftable to DAT_01046b48 and clears bytes b4 and b5, then returns the object.
// @fnv 0x005e9530
void* FUN_005e9530(FUN_005e9530_Obj* pThis)
{
    pThis->vftable = &DAT_01046b48;
    pThis->b4 = 0;
    pThis->b5 = 0;
    return pThis;
}

class FUN_006808b0
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;
    ~FUN_006808b0();
};

// @fnv 0x006808b0
FUN_006808b0::~FUN_006808b0()
{
    ((PerkEntryConditionSet*)this)->InitializeConditionItems();
}

// Evaluates a comparison condition code (0-5) between two floats and returns true if the comparison holds.
// @fnv 0x00681050
bool __cdecl CompareFloatsByCondition(int aiCondition, float afVal1, float afVal2)
{
    switch (aiCondition)
    {
    case 0:
        if (afVal1 != afVal2)
            return false;
        break;
    case 1:
        if (afVal1 == afVal2)
            return false;
        break;
    case 2:
        if (afVal1 <= afVal2)
            return false;
        break;
    case 3:
        if (afVal1 < afVal2)
            return false;
        break;
    case 4:
        if (afVal1 >= afVal2)
            return false;
        break;
    case 5:
        if (afVal1 > afVal2)
            return false;
        break;
    }
    return true;
}

struct TESItem_680910
{
};
struct ListNode_680910
{
    TESItem_680910* item;
    bool _ref_008256d0();
};
struct FUN_00680910_shell : ListNode_680910
{
    void ProcessItems();
};
// @fnv 0x00680910
void FUN_00680910_shell::ProcessItems()
{
    ListNode_680910* pNode = ((::ListNode_680910 *)((void *)(this)));
    while (pNode != 0 && !pNode->_ref_008256d0())
    {
        reinterpret_cast<::ConditionSerializer *>((((::ListNode_680910 *)((void *)(pNode)))->item))->SerializeCondition();
        pNode = ((::ListNode_680910 *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
}

struct FUN_00680a70_shell
{
    void CopyConditions(PerkEntryConditionSet*, PerkEntryConditionSet*);
};
struct FUN_00404760_shell
{
    void FUN_00404760(PerkEntryConditionSet*);
};
// Passes source to the object at this+0x1c, or an empty value when source is null.
// @fnv 0x00404760
void FUN_00404760_shell::FUN_00404760(PerkEntryConditionSet* source)
{
    if (source)
        ((FUN_00680a70_shell*)((char*)this + 0x1c))->CopyConditions(source, 0);
    else
    {
        PerkEntryConditionSet empty;
        ((FUN_00680a70_shell*)((char*)this + 0x1c))->CopyConditions(&empty, 0);
    }
}

struct FUN_005ea2c0_cls
{
    void FUN_006808b0();
    void* FUN_005ea2c0(unsigned int flags);
};

extern "C" void FUN_00ec5fce(void* object, int elementSize, int count, void (FUN_005ea2c0_cls::*callback)());


// @fnv 0x005ea2c0
void* FUN_005ea2c0_cls::FUN_005ea2c0(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 0x8, reinterpret_cast<int*>(this)[-1], &FUN_005ea2c0_cls::FUN_006808b0);

        if (flags & 1)
        {
            ::FUN_00401030(reinterpret_cast<char*>(this) - 4);
        }

        return reinterpret_cast<char*>(this) - 4;
    }

    reinterpret_cast<::FUN_006808b0 *>(this)->FUN_006808b0::~FUN_006808b0();

    if (flags & 1)
    {
        ::FUN_00401030(this);
    }

    return this;
}

struct ListOps_680a70
{
    bool FUN_008256d0();
};

// Clears this list, then walks the nodes of a1, appending a new TESConditionItem built from each node's form to the destination list.
// @fnv 0x00680a70
void FUN_00680a70_shell::CopyConditions(PerkEntryConditionSet* apSourceList, PerkEntryConditionSet* a2)
{
    reinterpret_cast<::PerkEntryConditionSet *>((((ListOps_680a70*)this)))->InitializeConditionItems();
    ListOps_680a70* dst = ((::ListOps_680a70 *)((void *)(((ListOps_680a70*)this))));
    ListOps_680a70* src3 = ((::ListOps_680a70 *)((void *)(((ListOps_680a70*)apSourceList))));
    while (src3 != 0 && !src3->FUN_008256d0())
    {
        TESConditionItem* item = new TESConditionItem();
        reinterpret_cast<::S00681590 *>((((ListOps_680a70*)item)))->CopyFromRefObj((::RefObj *)(*((::TESForm **)((void *)(src3)))), {});
        reinterpret_cast<::Callees *>((dst))->FUN_00905820(&item);
        if (((::ListOps_680a70 *)(reinterpret_cast<::Callees *>((dst))->FUN_00726070())) != 0)
        {
            dst = ((::ListOps_680a70 *)(reinterpret_cast<::Callees *>((dst))->FUN_00726070()));
        }
        src3 = ((::ListOps_680a70 *)(reinterpret_cast<::Callees *>((src3))->FUN_00726070()));
    }
}

struct FUN_00680f70_cls : ListNode_680910
{
    TESItem_680910* GetItemByIndex(int index);
};

// Walks the node list from _ref_006815c0, skipping nodes where _ref_008256d0 is true, and returns the TESItem_680910 at the given index or 0.
// @fnv 0x00680f70
TESItem_680910* FUN_00680f70_cls::GetItemByIndex(int index)
{
    int iCurrent = 0;
    ListNode_680910* pNode = ((::ListNode_680910 *)((void *)this));
    while (pNode != 0 && !pNode->_ref_008256d0())
    {
        if (iCurrent == index)
        {
            return *(TESItem_680910**)((::ListNode_680910 *)((void *)(pNode)));
        }
        iCurrent = iCurrent + 1;
        pNode = ((::ListNode_680910 *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return 0;
}
