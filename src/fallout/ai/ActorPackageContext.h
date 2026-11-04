// the end are the canonical generated-header additions requested for
// The shared FNV_ACTORPACKAGE_H guard keeps this copy conflict-free until the
// canonical header is regenerated and this file retires.
#ifndef FNV_ACTORPACKAGE_H
#define FNV_ACTORPACKAGE_H
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "layout_support.h"
class BGSLoadFormBuffer;
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
    // Canonical additions requested:
public:
    void Clear();
public:
    void SetPackageAndTarget(::TESPackage *, ::TESObjectREFR *);
public:
    void LoadGame(::BGSLoadFormBuffer *);
public:
    void ApplyLoadBuffer(::BGSLoadFormBuffer *);
};
#endif
