#ifndef FNV_ACTORPACKAGE_H
#define FNV_ACTORPACKAGE_H

#include "fnv/decl/FUN_00621b00_shell.h"
#include "fnv/decl/FUN_008c6130_shell.h"
#include "lowprocess_support.h"
class TESObjectREFR;
class TESPackage;
class ActorPackageContext
{
  public:
    TESPackage* pPackage;     // +0x0
    ActorPackageData* pData;  // +0x4
    TESObjectREFR* pTarget;   // +0x8
    int m_iPackageValue;      // +0xC
    float m_fPackageValue;    // +0x10
    unsigned int iFlags;      // +0x14
public:
    void SetPackageAndTarget(::TESPackage *, ::TESObjectREFR *);
};
#endif
