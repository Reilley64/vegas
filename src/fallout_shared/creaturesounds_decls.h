// fallout_shared/creaturesounds_decls.h: declares TESCreature, TESSound, SoundListEntry, SoundListView
#ifndef CREATURESOUNDS_DECLS_H
#define CREATURESOUNDS_DECLS_H


#include "fnv/decl/Callees.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e3000.h"
#include "creaturesounds_types_CREATURE_SOUND_TYPE.h"
#include "TESForm.h"

class TESCreature : public TESForm
{
};

class TESSound : public TESForm
{
  public:
};

class SoundListEntry
{
  public:
    TESSound* SoundAssetTmp;
    unsigned char m_ucSortOrder;
    unsigned char pad[3];
};

class SoundListView
{
  public:
    bool IsEmpty();
    void AddHead(SoundListEntry*& item);
};

extern const char DAT_010475a0[];

#endif
