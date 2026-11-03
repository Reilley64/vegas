
// src/fallout/ai/creature_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/creature.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00494300_shell.h"
#include "fnv/decl/fnv_00897910__AnimOwner.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c68000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_010c5000.h"
#include "creature_decls.h"

struct DAT_010c53b4_t
{
    void* vtable;
    void*(* Alloc)(void*, unsigned int);
    void(* Free)(void*, void*);
};


struct LocalObj
{
    void* vptr;
    void* data;
    int size;
    int capacity;

    LocalObj()
    {
        vptr = &(*reinterpret_cast<::DAT_010c53b4_t *>(&::DAT_010c53b4));
        data = 0;
        size = 0;
        capacity = 0;
        data = (*reinterpret_cast<::DAT_010c53b4_t *>(&::DAT_010c53b4)).Alloc(this, 0x20);
        capacity = 0x20;
    }

    ~LocalObj()
    {
        vptr = &(*reinterpret_cast<::DAT_010c53b4_t *>(&::DAT_010c53b4));
        if (data)
        {
            (*reinterpret_cast<::DAT_010c53b4_t *>(&::DAT_010c53b4)).Free(this, data);
        }
    }
};

// @fnv 0x00c812d0
int __cdecl FUN_00c812d0(void* a1, void* a2)
{
    LocalObj local;
    return ((int)(::FUN_00c80c00((::WorkNode_cls *)(a1), (::WorkStack_cls *)(void *)(&local), (unsigned int)(a2), 0)));
}

class NiAVObject;
class NiCollisionObject;

struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iValue;
    int iOption;
    int uNewnk;
    int uTmpnk;
};

struct C6A350Properties
{
    int unk;
    int unkCur;
    int unkValue;
    unsigned int m_uiValue1;
};
static inline unsigned int C6A350IsEnabled(NiAVObject* pkObject)
{
    C6A350Properties* pkProps = ((::C6A350Properties *)(::GetExtraDataChecked((::NiAVObjectX *)(pkObject))));
    return pkProps ? (pkProps->m_uiValue1 & 2) : 0;
}

typedef void (*CollisionObjectCountCallback)(NiCollisionObject*, CollisionObjectCountContext*);
extern CollisionObjectCountCallback DAT_011afe9c;

// @fnv 0x00c6a350
bool FUN_00c6a350(NiAVObject* pkObject, int iValue, bool bRecurse, bool bForce, bool bOption)
{
    bool bResult = false;
    if (pkObject && (bForce || C6A350IsEnabled(pkObject)))
    {
        CollisionObjectCountContext kContext;
        bResult = true;
        kContext.pCurrentObject = 0;
        kContext.bRecurse = bRecurse;
        kContext.uiTraversalFlags = 5;
        kContext.iValue = iValue;
        kContext.iOption = bOption;
        if (DAT_011afe9c)
            ::FUN_00c68900((::S_00c68900_Node *)(pkObject), (::S_00c68900_Context *)(::CollisionObjectCountContext *)(&kContext), (void (*)(void *, S_00c68900_Context *))(DAT_011afe9c));
    }
    return bResult;
}
