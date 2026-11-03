
// src/bscore/bssimplelist_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bscore/bssimplelist.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011f6000.h"
#include "InventoryStackRecord.h"
template class BSSimpleList<InventoryStackRecord*>;

struct Memory185
{
};
struct Node185
{
    InventoryStackRecord* item;
    Node185* next;
    void FUN_00ae83e0();
// @fnv 0x00ae83e0
    inline ~Node185()
    {
        FUN_00ae83e0();
    }
};
void Node185::FUN_00ae83e0()
{
    while (next)
    {
        Node185* successor = next->next;
        next->next = 0;
        delete next;
        next = successor;
    }
    item = 0;
}

struct Mem_00a0cbe0
{
};

template <class T> struct List_00a0cbe0
{
    T m_item;
    List_00a0cbe0<T>* m_pkNext;

    ~List_00a0cbe0()
    {
        int u1, u2, u3;
        reinterpret_cast<::Node185 *>(this)->FUN_00ae83e0();
    }
    bool IsEmpty()
    {
        return m_pkNext == 0 && m_item == 0;
    }
    void RemoveAll();
    void FUN_00a0cbe0(const T& item);
};

// @fnv 0x00a0cbe0
template <class T> void List_00a0cbe0<T>::FUN_00a0cbe0(const T& item)
{
    if (!item || IsEmpty())
        return;

    List_00a0cbe0<T>* pkCur = this;
    List_00a0cbe0<T>* pkPrev = this;
    while (pkCur && pkCur->m_item != item)
    {
        pkPrev = pkCur;
        pkCur = pkCur->m_pkNext;
    }
    if (pkCur)
    {
        if (pkCur == this)
        {
            if (m_pkNext)
            {
                pkPrev = m_pkNext;
                m_pkNext = pkPrev->m_pkNext;
                m_item = pkPrev->m_item;
                pkPrev->m_pkNext = 0;
                delete pkPrev;
            }
            else
            {
                m_item = 0;
            }
        }
        else
        {
            pkPrev->m_pkNext = pkCur->m_pkNext;
            pkCur->m_pkNext = 0;
            delete pkCur;
        }
    }
}

template struct List_00a0cbe0<InventoryStackRecord*>;
