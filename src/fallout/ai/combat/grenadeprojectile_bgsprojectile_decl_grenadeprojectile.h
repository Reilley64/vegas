// Declaration-only interface; no BGSProjectile object is created or laid out here.
// Public PC signatures and address annotations: JohnnyGuitarNVSE
// JG/internal/Game/Bethesda/BGSProjectile.hpp and BGSProjectile.cpp.
#ifndef FNV_GRENADEPROJECTILE_BGSPROJECTILE_H
#define FNV_GRENADEPROJECTILE_BGSPROJECTILE_H

#include "fnv/decl/FUN_005de080_shell.h"
#include "fnv/decl/FUN_006d2c20_Class.h"
#include "fnv/symbols_0069e000.h"
class BGSProjectile
{
  public:
      // declared for the original code (decl_variants.py)

  public:
    bool GetHasExplosionAltTrigger() const;
    float GetExplosionProximity() const;
public:
    bool FUN_004fd360();
};
#endif
