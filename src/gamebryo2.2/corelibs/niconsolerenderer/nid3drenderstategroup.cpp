// gamebryo2.2/corelibs/niconsolerenderer/nid3drenderstategroup.cpp: D3DRenderStateGroup, RenderOwner, StateGroup, StateGroupE7F5 (12 functions)

#include <cstring>
#include "fnv/decl/ActiveArray.h"
#include "fnv/decl/FUN_00e7ef80_List.h"
#include "fnv/decl/FUN_00e7efc0_List.h"
#include "fnv/decl/fnv_00e7f210__FUN_00e7f210_cls.h"
#include "fnv/symbols_00e7f000.h"
#include "fnv/symbols_010a9000.h"
#include "fnv/symbols_010b0000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_0126f000.h"
#include "nid3drenderstategroup_decls.h"
// Returns the render state group from DAT_0126f718, setting its flag to true if it was false.
// @fnv 0x00e7f5d0
D3DRenderStateGroup* D3DRenderStateGroup::GetCurrentRenderStateGroup()
{
    D3DRenderStateGroup* group = DAT_0126f718->Get();
    if (!group->m_bHasBeenApplied)
        group->m_bHasBeenApplied = true;
    return group;
}

struct Entry00e7ef40
{
    int m_iFadeIndex;
    int m_iPad;
    Entry00e7ef40* m_pkNext;
};
struct Renderer00e7ef40
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void Set(int, int, int, int);
    char _pad[288];
    struct Val
    {
        int m_iVal;
        int m_iPad;
    } m_kVals[64];
};
struct Group00e7ef40
{
    char _pad0[16];
    Entry00e7ef40* m_pkSaved;
    unsigned int FUN_00e7ef40();
};
// @fnv 0x00e7ef40
unsigned int Group00e7ef40::FUN_00e7ef40()
{
    Entry00e7ef40* pkRSEntry = m_pkSaved;
    while (pkRSEntry)
    {
        int iState = pkRSEntry->m_iFadeIndex;
        Renderer00e7ef40* pRenderer = (*reinterpret_cast<::Renderer00e7ef40 * *>(&::DAT_0126f714));
        int iVal = pRenderer->m_kVals[iState].m_iVal;
        pRenderer->Set(iState, iVal, 0, 0);
        pkRSEntry = pkRSEntry->m_pkNext;
    }
    return 0;
}

struct Group00e7eed0
{
    char _pad0[0x8];
    void* unk08;
    char pad0c[0x4];
    Entry00e7ef40* m_pkSaved;
    unsigned int ApplyGroupEntries();
};
// Iterates the group's entry list calling DAT_0126f714->Set with flag 0, then the saved list with flag 1, and returns 0.
// @fnv 0x00e7eed0
unsigned int Group00e7eed0::ApplyGroupEntries()
{
    Entry00e7ef40* entry = *(Entry00e7ef40**)&this->unk08;
    while (entry)
    {
        (*reinterpret_cast<::Renderer00e7ef40 * *>(&::DAT_0126f714))->Set(entry->m_iFadeIndex, entry->m_iPad, 0, 0);
        entry = entry->m_pkNext;
    }
    entry = m_pkSaved;
    while (entry)
    {
        (*reinterpret_cast<::Renderer00e7ef40 * *>(&::DAT_0126f714))->Set(entry->m_iFadeIndex, entry->m_iPad, 1, 0);
        entry = entry->m_pkNext;
    }
    return 0;
}

struct Helper00b8d460;

struct Helper00b8d460
{
};

struct Sub00b8d460
{
    char _pad0[0x30];
    Helper00b8d460* m_pHelper;
};

struct Owner00b8d460
{
    char _pad0[0x5c];
    Sub00b8d460* m_pSub;

    void FUN_00b8d460();
};

extern "C" char str_010b5c70;
extern "C" char str_010b5c64;

struct RenderBuffer
{
    void* typeInfo;
    unsigned int state;
    unsigned int state08;
    unsigned int state0c;
    unsigned int state10;
    unsigned int state14;
    unsigned int state18;
    unsigned int state1c;
    unsigned int state20;
    unsigned int state24;
    unsigned int state28;
    unsigned int state2c;
    unsigned int state30;
    unsigned int state34;
    unsigned int state38;
    unsigned int state3c;
    unsigned int state40;
    unsigned int state44;
    unsigned int state48;
};

struct RenderState
{
};

struct GroupState
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    RenderState* state;
};

struct RenderOwner
{
    void** virtualTable;
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
    GroupState* group;
    void ApplyRenderState();
};

typedef void(* ApplyState)(RenderOwner*, RenderBuffer*, RenderBuffer*, const void*, const void*, const void*);
typedef void(* CommitState)(RenderOwner*);

struct StateNode
{
    unsigned int key;
    unsigned int value;
    StateNode* prev;
    StateNode* next;
};
struct StateGroup
{
    int unk00;
    unsigned int countA;
    StateNode* tailA;
    unsigned int countB;
    StateNode* tailB;
    void AddA(StateNode* node)
    {
        if (tailA)
        {
            tailA->next = node;
            node->prev = tailA;
        }
        node->next = 0;
        ++countA;
        tailA = node;
    }
    void AddB(StateNode* node)
    {
        if (tailB)
        {
            tailB->next = node;
            node->prev = tailB;
        }
        node->next = 0;
        ++countB;
        tailB = node;
    }
    void SetNodeValue(unsigned int, unsigned int, bool);
};
// Ensures m_pSub->m_pHelper exists, then initialises it three times with (0x34,1,1), (0x38,3,1) and (0x39,1,1).
// @fnv 0x00b8d460
void Owner00b8d460::FUN_00b8d460()
{
    Sub00b8d460* pSub = m_pSub;
    if (pSub->m_pHelper == 0)
    {
        pSub->m_pHelper = ((::Helper00b8d460 *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    }
    reinterpret_cast<::StateGroup *>((pSub->m_pHelper))->SetNodeValue(0x34, 1, 1);

    pSub = m_pSub;
    if (pSub->m_pHelper == 0)
    {
        pSub->m_pHelper = ((::Helper00b8d460 *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    }
    reinterpret_cast<::StateGroup *>((pSub->m_pHelper))->SetNodeValue(0x38, 3, 1);

    pSub = m_pSub;
    if (pSub->m_pHelper == 0)
    {
        pSub->m_pHelper = ((::Helper00b8d460 *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    }
    reinterpret_cast<::StateGroup *>((pSub->m_pHelper))->SetNodeValue(0x39, 1, 1);
}
// Builds two RenderBuffers, applies and commits them via virtual calls, then sets render states 0x1b, 0x13 and 0x14 on the group's state.
// @fnv 0x00b925b0
void RenderOwner::ApplyRenderState()
{
    RenderBuffer currentBuffer;
    currentBuffer.typeInfo = &str_010b0158;
    currentBuffer.state = 0;
    std::memset(&currentBuffer.state08, 0, 0x44);

    RenderBuffer fallbackBuffer;
    fallbackBuffer.typeInfo = &str_010b5c70;
    fallbackBuffer.state = 0;
    std::memset(&fallbackBuffer.state08, 0, 0x44);

    reinterpret_cast<ApplyState>(virtualTable[0x13c / sizeof(void*)])(this, &currentBuffer, &fallbackBuffer,
                                                                      &str_010b5c64, &str_010a93ec, &str_010a93cc);
    reinterpret_cast<CommitState>(virtualTable[0x14c / sizeof(void*)])(this);

    GroupState* stateOwner = group;
    if (!stateOwner->state)
        stateOwner->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((stateOwner->state))->SetNodeValue(0x1b, 1, 1);

    GroupState* nextOwner = group;
    if (!nextOwner->state)
        nextOwner->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((nextOwner->state))->SetNodeValue(0x13, 5, 1);

    if (!nextOwner->state)
        nextOwner->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((nextOwner->state))->SetNodeValue(0x14, 6, 1);
}
// @fnv 0x00e7f430
void StateGroup::SetNodeValue(unsigned int key, unsigned int value, bool target)
{
    bool foundType = false;
    StateNode* node = ((::StateNode *)(::FindNodeByKey((::Self_00e7f000 *)this, key, (int)&(foundType), *(bool *)nullptr)));
    if (node)
    {
        bool currentType = foundType;
        node->value = value;
        if (currentType != target)
        {
            if (currentType)
            {
                reinterpret_cast<::FUN_00e7efc0_List *>(this)->FUN_00e7efc0((::FUN_00e7efc0_Node *)(node));
                AddA(node);
            }
            else
            {
                reinterpret_cast<::FUN_00e7ef80_List *>(this)->FUN_00e7ef80((::FUN_00e7ef80_Node *)(node));
                AddB(node);
            }
        }
    }
    else
    {
        StateNode* fresh = (*reinterpret_cast<::ObjectPool< ::StateNode, ::NiTNewInterface< ::StateNode>> * *>(&::fnv_00e7f2b0::DAT_0126f71c))->Get();
        fresh->prev = 0;
        fresh->next = 0;
        fresh->key = key;
        fresh->value = value;
        if (target)
            AddB(fresh);
        else
            AddA(fresh);
    }
}

struct Holder_b92d20
{
    char pad[0x30];
    RenderState* pState;
    RenderState* Get()
    {
        if (!pState)
            pState = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
        return pState;
    }
};
struct B92D20Obj
{
    char pad[0x5c];
    Holder_b92d20* pHolder;
    void ConfigureRenderState();
};
// @fnv 0x00b92d20
void B92D20Obj::ConfigureRenderState()
{
    if ((*reinterpret_cast<char *>(&::fnv_004e8ec0::DAT_011ad832)))
    {
        reinterpret_cast<::StateGroup *>((pHolder->Get()))->SetNodeValue(0x34, 1, 1);
        reinterpret_cast<::StateGroup *>((pHolder->Get()))->SetNodeValue(0x38, 3, 1);
        reinterpret_cast<::StateGroup *>((pHolder->Get()))->SetNodeValue(0x39, 1, 1);
    }
}

struct StateNodePoolE7F5
{
    void ReleaseObject(StateNode* pkNode)
    {
        reinterpret_cast<::ActiveArray *>(this)->FindOrAdd((void *const &)(pkNode));
    }
};

struct StateGroupE7F5 : public StateGroup
{
    void RemoveA(StateNode* pkNode)
    {
        StateNode* pkPrev = pkNode->prev;
        StateNode* pkNext = pkNode->next;
        if (pkPrev)
        {
            pkPrev->next = pkNext;
        }
        if (pkNext)
        {
            pkNext->prev = pkPrev;
        }
        if (pkNode == tailA)
        {
            tailA = pkPrev;
        }
        --countA;
        pkNode->prev = 0;
        pkNode->next = 0;
    }
    void RemoveB(StateNode* pkNode)
    {
        StateNode* pkPrev = pkNode->prev;
        StateNode* pkNext = pkNode->next;
        if (pkPrev)
        {
            pkPrev->next = pkNext;
        }
        if (pkNext)
        {
            pkNext->prev = pkPrev;
        }
        if (pkNode == tailB)
        {
            tailB = pkPrev;
        }
        --countB;
        pkNode->prev = 0;
        pkNode->next = 0;
    }
    void RemoveNodeByKey(unsigned int uiKey);
};

// Finds a node by uiKey, removes it from list A or B, and releases it back to the pool.
// @fnv 0x00e7f550
void StateGroupE7F5::RemoveNodeByKey(unsigned int uiKey)
{
    bool bInB = false;
    StateNode* pkNode = ((::StateNode *)(::FindNodeByKey((::Self_00e7f000 *)this, uiKey, (int)&(bInB), *(bool *)nullptr)));
    if (pkNode)
    {
        if (bInB)
        {
            RemoveB(pkNode);
        }
        else
        {
            RemoveA(pkNode);
        }
        reinterpret_cast<StateNodePoolE7F5*>((*reinterpret_cast<::ObjectPool< ::StateNode, ::NiTNewInterface< ::StateNode>> * *>(&::fnv_00e7f2b0::DAT_0126f71c)))->ReleaseObject(pkNode);
    }
}

struct RenderPassB71 : GroupState
{
    void FUN_00b71a10(unsigned int stateKey, unsigned int value, int);
};

// Ensures state is initialized via FUN_00e7f5d0, then calls SetNodeValue on state with stateKey, value, and true.
// @fnv 0x00b71a10
void RenderPassB71::FUN_00b71a10(unsigned int stateKey, unsigned int value, int)
{
    if (!state)
        state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((state))->SetNodeValue(stateKey, value, true);
}

struct RenderStateCallB8F160
{
};

struct RenderOwnerEntryB8F160 : RenderOwner
{
    void FUN_00b8f160();
};

// Ensures the group's state object exists, then sets render states 0xA8 to 0 and 0xBE to 0xF with save enabled.
// @fnv 0x00b8f160
void RenderOwnerEntryB8F160::FUN_00b8f160()
{
    GroupState* pass = group;
    if (!pass->state)
        pass->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((((RenderStateCallB8F160*)pass->state)))->SetNodeValue(0xA8, 0, true);

    pass = group;
    if (!pass->state)
        pass->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((((RenderStateCallB8F160*)pass->state)))->SetNodeValue(0xBE, 0xF, true);
}

extern int DAT_011ae680;

// Ensures the owner's group state exists and sets node values 0x34, 0x38, and 0x39 to 1, 4, and DAT_011ae680 respectively.
// @fnv 0x00b8f2f0
void FUN_00b8f2f0(RenderOwner* owner)
{
    GroupState* group = owner->group;
    if (!group->state)
        group->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((group->state))->SetNodeValue(0x34, 1, true);

    group = owner->group;
    if (!group->state)
        group->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((group->state))->SetNodeValue(0x38, 4, true);

    group = owner->group;
    int reference = DAT_011ae680;
    if (!group->state)
        group->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((group->state))->SetNodeValue(0x39, reference, true);
}

// If owner->group->state is null, assigns FUN_00e7f5d0() to it, then sets node values 14, 52, and 56.
// @fnv 0x00b8f4b0
void FUN_00b8f4b0(RenderOwner* owner)
{
    GroupState* group = owner->group;
    if (!group->state)
        group->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((group->state))->SetNodeValue(14, 0, true);

    group = owner->group;
    if (!group->state)
        group->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((group->state))->SetNodeValue(52, 1, true);

    group = owner->group;
    if (!group->state)
        group->state = ((::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((group->state))->SetNodeValue(56, 3, true);
}
