// gamebryo2.2/corelibs/nimain/nitribasedgeom.cpp: BSTextureSet, NiGeometry, NiTriBasedGeom (5 functions)
#include "fnv/decl/FUN_0051d1c0.h"
#include "fnv/decl/S_0051d080.h"
#include "fnv/symbols_00aa1000.h"
#include "nitribasedgeom_decls.h"
#pragma optimize("", off)
// @fnv 0x0051d190
BSTextureSet::BSTextureSet()
{
    vtable = BSTextureSet_vtable;
}
#pragma optimize("", on)
// Initializes the NiGeometry object by setting model, skin and shader pointers to null.
// @fnv 0x00a80540
NiGeometry::NiGeometry()
{
    model = 0;
    skin = 0;
    shader = 0;
}

#pragma optimize("", off)
// @fnv 0x0051d020
void NiTriBasedGeom::SetBitfield(unsigned short value, unsigned short mask, unsigned short shift)
{
    flags = (flags & ~mask) | (value << shift);
}

struct DummyClass
{
};

struct StackByte
{
    unsigned char v;
};

// @fnv 0x0051d060
void __fastcall FUN_0051d060(DummyClass* _this, StackByte aByteValue)
{
    reinterpret_cast<::S_0051d080 *>((_this))->FUN_0051d080(aByteValue.v, 8);
}

class NiMemObject
{
  public:
    static void __cdecl operator delete(void*, size_t);
};


struct Dummy_0051d160
{
    // Calls FUN_0051d1c0 on this, then frees this (0x38 bytes) via NiMemObject::operator delete when bit 0 of flags is set, returning this.
// @fnv 0x0051d160
    void* __thiscall FUN_0051d160(unsigned int flags)
    {
        reinterpret_cast<struct ::FUN_0051d1c0 *>((this))->FUN_0051d1c0::~FUN_0051d1c0();
        if ((flags & 1) != 0)
        {
            ::FUN_00aa1460(this, 0x38);
        }
        return this;
    }
};

static void* (__thiscall Dummy_0051d160::*p_0051d160)(unsigned int) = &Dummy_0051d160::FUN_0051d160;
