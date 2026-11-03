
// src/gamebryo2.2/corelibs/nianimation/niflipcontroller_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/FUN_004b0460_class.h"
#include "fnv/decl/FUN_00a4f820.h"
#include "fnv/symbols_00a4f000.h"
#include "fnv/symbols_011f3000.h"
struct FUN_00a4f300_shell
{
    void* GetEntryAt(int idx);
};
const void* __cdecl FUN_00a4f5d0();
struct BSFadeNode
{
    static void* __cdecl operator new(size_t);
};
struct NiFlipController
{
};

struct StaticKey
{
    StaticKey(int v);
    ~StaticKey();
    unsigned int m_00;
};

struct SlotTarget
{
    unsigned int m_00;
    void FUN_006e5cc0(SlotTarget* a);
};

class FUN_0060c120_cls
{
  public:
    unsigned int unk00;
    SlotTarget* m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void FUN_0060c120(unsigned int idx, SlotTarget* a2);
};

// @fnv 0x0060c120
void FUN_0060c120_cls::FUN_0060c120(unsigned int idx, SlotTarget* a2)
{
    static StaticKey key(0);
    if (idx >= m_0a)
    {
        m_0a = (unsigned short)(idx + 1);
        if (reinterpret_cast<::DummyStruct_00631820 *>((a2))->IsNotEqual((*(const ::DummyStruct_00631820 *)(&key))))
        {
            m_0c++;
        }
    }
    else
    {
        if (reinterpret_cast<::DummyStruct_00631820 *>((a2))->IsNotEqual((*(const ::DummyStruct_00631820 *)(&key))))
        {
            if (reinterpret_cast<::FUN_004b0460_class *>(((m_04 + idx)))->FUN_004b0460((const void **)(::StaticKey *)(&key)))
            {
                m_0c++;
            }
        }
        else
        {
            if (reinterpret_cast<::DummyStruct_00631820 *>(((m_04 + idx)))->IsNotEqual((*(const ::DummyStruct_00631820 *)(&key))))
            {
                m_0c--;
            }
        }
    }
    (m_04 + idx)->FUN_006e5cc0(a2);
}
