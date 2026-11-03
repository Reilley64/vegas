
// src/havok/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/contact/hkpsimplecontactconstraintinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00d6f000.h"
#include "fnv/symbols_00d72000.h"
struct StateD72090
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
};

// @fnv 0x00d72090
void FUN_00d72090(StateD72090* out)
{
    out->unk0C = 0.0f;
    out->unk14 = 0.0f;
    out->unk1C = 0.0f;
}

#include <string.h>
struct Node
{
    unsigned short unk00;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short unk10;
    unsigned short unk12;
    Node* unk14;
};

struct __declspec(align(16)) Buffer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};

extern "C" Buffer* __cdecl GetSharedBuffer();

// Copies source to a local buffer, follows unk14 links while unk00 >= 0x17, then calls FUN_00d72190 if that node's unk00 is 0x16, else FUN_00d6f460.
// @fnv 0x00d6c5a0
static void __cdecl FUN_00d6c5a0(Node* self, int* counter, Buffer* source)
{
    Buffer buffer;
    union Flag
    {
        unsigned char byte;
        int value;
    } flag;

    *counter -= 0x10;

    memcpy(&buffer, source, sizeof(buffer));

    Node* node = self;
    unsigned int value = self->unk12;
    do
    {
        node = node->unk14;
    } while (node->unk00 >= 0x17);

    ::FUN_00d72090((::StateD72090 *)(void *)(&node->unk10));

    node = self->unk14;
    if (node->unk00 == 0x16)
    {
        flag.byte = 1;
        FUN_00d72190(node, &buffer, flag.value, counter);
    }
    else
    {
        ::FUN_00d6f460((const ::Atom *)(node), (unsigned short)value, (const ::QueryIn *)(::Buffer *)(&buffer), (::QueryOut *)(counter));
    }
}

void __cdecl Caller(Node* self, int* counter)
{
    FUN_00d6c5a0(self, counter, GetSharedBuffer());
}
