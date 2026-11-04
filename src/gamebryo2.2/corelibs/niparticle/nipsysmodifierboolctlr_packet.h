// gamebryo2.2/corelibs/niparticle/nipsysmodifierboolctlr_packet.h: declares NiFixedString, NiTimeController
#ifndef NIPSYSMODIFIERBOOLCTLR_PACKET_H
#define NIPSYSMODIFIERBOOLCTLR_PACKET_H


#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010c0000.h"
#include "fnv/symbols_01202000.h"
class NiFixedString
{
  public:
    const char* value;
};

class NiTimeController
{
  public:
    void SetControllerActive(bool);
};


#endif
