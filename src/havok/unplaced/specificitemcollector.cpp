
// src/havok/unplaced/specificitemcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/specificitemcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include <cstdint>
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_00624020_Class.h"
#include "fnv/decl/FUN_00ca9440_cls.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0059c000.h"
struct FUN_0062a2f0
{
    void* DeleteThis(unsigned int flags);
};

// Calls FUN_0059cee0 on this, frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0062a2f0
void* FUN_0062a2f0::DeleteThis(unsigned int flags)
{
    FUN_0059cee0(this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct S_0062a320_Key
{
    unsigned int m_uiFilterValue;
    S_0062a320_Key(uintptr_t v);
};

struct S_0062a320_Node
{
};

struct S_0062a320_Arg
{
};

struct S_0062a320_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
};

struct S_0062a320
{
    char pad[0x70];
    S_0062a320_Key unk70;
    float unk74;
    void FUN_0062a320(S_0062a320_Arg* arg, S_0062a320_Data* data);
};

// @fnv 0x0062a320
void S_0062a320::FUN_0062a320(S_0062a320_Arg* arg, S_0062a320_Data* data)
{
    S_0062a320_Node* node = ((::S_0062a320_Node *)(reinterpret_cast<::FUN_00624020_Class *>((arg))->GetLastNode()));
    if (node)
    {
        S_0062a320_Key nodeKey(::FUN_0043b540((char *)(node)));
        if (((unsigned int)(reinterpret_cast<::FUN_0043b4d0_shell *>(&(nodeKey))->FUN_0043b4d0())) != ((unsigned int)(reinterpret_cast<::FUN_0043b4d0_shell *>(&(unk70))->FUN_0043b4d0())) || reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(nodeKey))->FUN_004a3a20() == reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(unk70))->FUN_004a3a20())
        {
            if (unk74 <= data->unk10)
            {
                reinterpret_cast<::FUN_00ca9440_cls *>(this)->FUN_00ca9440((::HKPCloseNode *)(arg), (::FUN_00ca9440_src *)(data));
            }
        }
    }
}
