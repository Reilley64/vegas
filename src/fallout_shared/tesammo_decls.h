// fallout_shared/tesammo_decls.h: declares BGSProjectile, TESAmmoEffect, MiddleLowProcess, TESAmmoInitCalls
#ifndef TESAMMO_DECLS_H
#define TESAMMO_DECLS_H

#include <cstdint>
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0097a000.h"
class Script;
#include "tesammo_types.h"

class BGSProjectile : public TESForm
{
};
class TESAmmoEffect : public TESForm
{
};

class MiddleLowProcess
{
  public:
    int GetProcessInteger();
    void SetProcessInteger(std::intptr_t);
};

class TESAmmoInitCalls
{
  public:
    void* FUN_00923000();
};

extern "C"
{
    extern const char DAT_01026288[];
    extern const char DAT_01026238[];
    extern const char DAT_010261e8[];
}


#endif
