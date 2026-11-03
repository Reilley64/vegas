#pragma once

class TESObjectREFR;

// The reference that fired a projectile, as Projectile code reads it directly. The release build reads it through the
// folded 4-byte getter at 0x009b4440. The padding keeps the 32-bit offset (+0x100) until the MobileObject layout is
// modelled.
struct ProjectileFields
{
    char pad000[0x100];
    TESObjectREFR* pSourceRef;
};
