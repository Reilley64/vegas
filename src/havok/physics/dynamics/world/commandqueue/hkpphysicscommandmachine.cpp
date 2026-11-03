
// src/havok/physics/dynamics/world/commandqueue/hkpphysicscommandmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/commandqueue/hkpphysicscommandmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00cb3000.h"

struct CommandFlags
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    short unk10;
    unsigned char flags12;
};
struct CommandObject
{
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
    CommandFlags* state30;
};
struct CommandRecord
{
    unsigned char tag;
    CommandObject* x;
    int y;
    int unk0C;
};

static __declspec(noinline) void SetOwnerStateFlags(void* a, CommandObject* x, int b)
{
    FUN_00cb3c80(a, x);
    x->state30->flags12 |= (unsigned char)b;
}

static __forceinline void AddFwd(void* a, const volatile int& y, CommandObject* x)
{
    SetOwnerStateFlags(a, x, y);
}
// Iterates a range of CommandRecord entries and dispatches each by tag to AddFwd or FUN_00cb3da0, stopping on an unknown tag.
// @fnv 0x00df25f0
void FUN_00df25f0(void* aiContext, CommandRecord* apRecords, int c)
{
    CommandRecord* pEnd = (CommandRecord*)((char*)apRecords + c);
    if (apRecords < pEnd)
    {
        void* ctx = *(void* volatile*)&aiContext;
        do
        {
            switch (apRecords->tag)
            {
            case 0: {
                CommandObject* x;
                AddFwd(ctx, apRecords->y, x = apRecords->x);
            }
            break;
            case 1:
                ::FUN_00cb3da0((::S_00cb3da0_Ctx *)(ctx), apRecords->x);
                break;
            default:
                return;
            }
        } while (++apRecords < pEnd);
    }
}
