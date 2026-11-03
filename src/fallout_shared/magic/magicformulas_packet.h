// fallout_shared/magic/magicformulas_packet.h: declares FlaggedData, InterfaceManager
#ifndef MAGICFORMULAS_PACKET_H
#define MAGICFORMULAS_PACKET_H

#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00874000.h"
class FlaggedData
{
    unsigned char padding[0x40];
    unsigned char flags;

  public:
    int ContainsAnyFlag(unsigned int mask);
    static int GetPlayerValue();
};
class QuestStage
{
  public:
};
class InterfaceManager
{
  public:
};
#endif
