
// src/havok/common/base/types/geometry/localframe/hklocalframeclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/geometry/localframe/hklocalframeclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include "fnv/decl/FUN_00df67d0.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_0102e000.h"
struct FUN_00df67d0_Base
{
    virtual void v0();
};
struct FUN_00da0860_manager
{
    virtual void v0();
    virtual void v1();
    virtual void FUN_00da0860_release(void*, unsigned short);
};
struct BSAudio
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00da0860_manager* unk10;
};
struct FUN_00da0860_class : FUN_00df67d0_Base
{
    unsigned short unk04;
    FUN_00da0860_class* FUN_00da0860(unsigned int flags);
};
// @fnv 0x00da0860
FUN_00da0860_class* FUN_00da0860_class::FUN_00da0860(unsigned int flags)
{
    reinterpret_cast<::FUN_00df67d0 *>(this)->FUN_00df67d0::~FUN_00df67d0();
    if (flags & 1)
    {
        BSAudio* audio = static_cast<BSAudio*>(::FUN_00c85750());
        audio->unk10->FUN_00da0860_release(this, unk04);
    }
    return this;
}

struct DA0890Object
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    uintptr_t m_taggedPointer;

    void* GetUntaggedPointer() const;
};

// Returns m_taggedPointer with its low bit cleared, as a void pointer.
// @fnv 0x00da0890
void* DA0890Object::GetUntaggedPointer() const
{
    return (void*)(m_taggedPointer & ~1u);
}


struct FUN_00cb0c00_class
{
};


struct SomeClass
{
    void* vptr;
    unsigned short unk04;
    void* FUN_00da0800(unsigned int flags);
};

// Calls a virtual method on the object at offset 8, sets the vtable, and if flags bit 0 is set releases this via the audio manager using unk04.
// @fnv 0x00da0800
void* SomeClass::FUN_00da0800(unsigned int flags)
{
    ::FUN_00cb0c00((intptr_t)(((FUN_00cb0c00_class*)((char*)this + 8))));
    this->vptr = (void*)&(*reinterpret_cast<int *>(&::DAT_0102e388));
    if (flags & 1)
    {
        BSAudio* a = static_cast<BSAudio*>(::FUN_00c85750());
        unsigned short d = this->unk04;
        ((FUN_00da0860_manager*)a->unk10)->FUN_00da0860_release(this, d);
    }
    return this;
}

struct DA0850Object
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int m_uiFilterValue;

    void FUN_00da0850(int value);
};

// @fnv 0x00da0850
void DA0850Object::FUN_00da0850(int value)
{
    m_uiFilterValue = value;
}

struct FUN_00da0840_Obj
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;

    int FUN_00da0840();
};

// @fnv 0x00da0840
int FUN_00da0840_Obj::FUN_00da0840()
{
    return unk5C;
}
