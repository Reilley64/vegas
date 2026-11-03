
// src/fallout_shared/bsanimnotereceiver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bsanimnotereceiver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_004b0480_cls.h"
#include "fnv/decl/FUN_004b0530_Class.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/symbols_00401000.h"
struct IBSAnimNoteReceiver
{
    virtual ~IBSAnimNoteReceiver();
    void* FUN_004b0550(unsigned int flags);
};

// Calls FUN_004b0530, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x004b0550
void* IBSAnimNoteReceiver::FUN_004b0550(unsigned int flags)
{
    reinterpret_cast<::FUN_004b0530_Class *>(this)->FUN_004b0530();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BSAnimNoteReceiver
{
    void* FUN_004b0580(unsigned int);
};

// Calls FUN_004b0480, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004b0580
void* BSAnimNoteReceiver::FUN_004b0580(unsigned int flags)
{
    reinterpret_cast<::FUN_004b0480_cls *>(this)->FUN_004b0480_cls::~FUN_004b0480_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00658930_class
{
    unsigned int GetShortAtOffsetA() const;
};
struct NiFormArray
{
    void*& FUN_00877a30(unsigned int index);
};
struct ReceiverEntry
{
    unsigned int type;
    void(__cdecl* callback)(void*, void*);
};
struct FUN_004b0730_class
{
    int unk00;
    void* unk04;
    int unk08;
    void DispatchNoteToReceivers(void* note);
};
// @fnv 0x004b0730
void FUN_004b0730_class::DispatchNoteToReceivers(void* note)
{
    for (int i = 0; i < ((FUN_00658930_class*)&this->unk08)->GetShortAtOffsetA(); ++i)
    {
        if (((ReceiverEntry*)((NiFormArray*)&this->unk08)->FUN_00877a30(i))->type == ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((note))->GetName())))
        {
            ((ReceiverEntry*)((NiFormArray*)&this->unk08)->FUN_00877a30(i))->callback(unk04, note);
        }
    }
}
