
// src/fallout/ai/combat/projectile_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout/ai/combat/projectile.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv/decl/FUN_00978f10_shell.h"
#include "fnv/decl/RefLoad.h"
#include "fnv/decl/fnv_00ae5a50__Mgr_00ae5a50.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01272000.h"
#include "projectile_decls.h"


inline int GetMemContext()
{
    return (*reinterpret_cast<int *>(&::currentAllocationContext));
}
inline void SetMemContext(int aiMemoryContext)
{
    (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
}

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = GetMemContext();
        SetMemContext(aiMemoryContext);
    }
    ~MemContextGuard()
    {
        SetMemContext(m_iSaved);
    }
};

class SoundResult
{
  public:
    unsigned int uiID;
    ~SoundResult();
};

class SoundSystem
{
  public:
    SoundResult FUN_00ae5a50(int a, int b, int c);
};


class SoundWrapper
{
  public:
    SoundResult FUN_00ad7480(int a, int b, int c);
};

// @fnv 0x00ad7480
SoundResult SoundWrapper::FUN_00ad7480(int a, int b, int c)
{
    MemContextGuard kGuard(11);
    return ((::SoundSystem *)(::FUN_00ad9060()))->FUN_00ae5a50(a, b, c);
}
