#ifndef FNV_ACTORPACKAGE_H
#define FNV_ACTORPACKAGE_H

#include "fnv/decl/FUN_00621b00_shell.h"
#include "processlists_layout_support.h"
class ActorPackageContext
{
  public:
    TESPackage* pPackage;     // +0x0
    ActorPackageData* pData;  // +0x4
    TESObjectREFR* pTarget;   // +0x8
    int m_iPackageValue;      // +0xC
    float m_fPackageValue;    // +0x10
    unsigned int iFlags;      // +0x14
};
#endif
