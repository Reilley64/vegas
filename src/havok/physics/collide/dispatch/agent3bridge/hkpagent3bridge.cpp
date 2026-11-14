
// src/havok/physics/collide/dispatch/agent3bridge/hkpagent3bridge.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/agent3bridge/hkpagent3bridge.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00cfbd60_cls.h"
#include "fnv/symbols_00d92000.h"
typedef void (*Callback)();
struct __declspec(align(16)) CallbackTable
{
    Callback callback00;
    Callback callback04;
    Callback callback08;
    Callback callback0c;
    Callback callback10;
    Callback callback14;
    Callback callback18;
    Callback callback1c;
    Callback callback20;
    Callback callback24;
    Callback callback28;
    Callback callback2c;
    unsigned char flag30;
    unsigned char flag31;
    unsigned char flag32;
    unsigned char flag33;
    Callback unk34;
    Callback unk38;
    Callback unk3c;
};
struct Context
{
};
// Fills a CallbackTable with the callback functions and flags, then passes it to AddEntry with -1, -1.
// @fnv 0x00d923b0
void __cdecl FUN_00d923b0(void* context)
{
    CallbackTable table;
    table.flag31 = 0;
    table.flag32 = 0;
    table.callback28 = 0;
    table.callback08 = 0;
    table.callback10 = ((void (&)())::FUN_00d922c0);
    table.callback14 = ((void (&)())::CallIfaceMethod);
    table.callback0c = ((void (&)())::FUN_00d922a0);
    table.callback00 = ((void (&)())::CreateAgent);
    table.callback2c = ((void (&)())::CallVirtualWithVectorArgs);
    table.callback04 = ((void (&)())::InvokeDispatch);
    table.callback18 = ((void (&)())::FUN_00d92200);
    table.callback1c = ((void (&)())::AddChildAgent2ToCollector);
    table.callback20 = ((void (&)())::CallObjectVirtual);
    table.callback24 = ((void (&)())::DispatchVirtualCall);
    table.flag30 = 1;
    reinterpret_cast<::FUN_00cfbd60_cls *>((((Context*)context)))->AddEntry((::SrcRec *)(::CallbackTable *)(&table), -1, -1);
}
