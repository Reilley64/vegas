
// src/havok/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkppredgskfagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00cfbd60_cls.h"
#include "fnv/symbols_00d41000.h"
struct __declspec(align(16)) FUN_00d41f00_Local
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
};


class SpawnedObject
{
  public:
};

// @fnv 0x00d41f00
void __cdecl FUN_00d41f00(SpawnedObject* self, int aiArg1, int aiArg2)
{
    FUN_00d41f00_Local local;
    local.unk30 = 0;
    local.unk31 = 0;
    local.unk32 = 0;
    local.unk18 = 0;
    local.unk1C = 0;
    local.unk20 = 0;
    local.unk24 = 0;
    local.unk28 = 0;
    ::FUN_00d41ec0((void **)(::FUN_00d41f00_Local *)(&local));
    reinterpret_cast<::FUN_00cfbd60_cls *>((self))->AddEntry((::SrcRec *)(::FUN_00d41f00_Local *)(&local), aiArg1, aiArg2);
}
