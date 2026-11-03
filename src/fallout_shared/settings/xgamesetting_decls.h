// fallout_shared/settings/xgamesetting_decls.h: declares Setting, GameSettingCollection
#ifndef FNV_XGAMESETTING_DECLS_H
#define FNV_XGAMESETTING_DECLS_H


#include "fnv/decl/FUN_004f8940_class.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_004f8a30_shell2.h"
#include "fnv/decl/FUN_004f8a60_class.h"
#include "fnv/decl/SettingS.h"
#include "fnv/symbols_00464000.h"
#include "TESFile.h"
#include "SETTING_VALUE.h"

// The canonical Setting layout, with declarations for the two unresolved
// helpers used by the game-setting reader. No shared header is modified.
class Setting
{
  public:
    SETTING_VALUE uValue;
    const char* pKey;
    Setting(const char* key, float value);
    Setting(const char* key, int value);
    Setting(const char* key, char* value);
    virtual ~Setting();
    virtual bool IsPrefSetting();
    unsigned int FUN_004f8940();
};

template <class T> class SettingCollectionMap
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual bool ReadSetting(T& setting);
    virtual bool Open(bool create);
    virtual bool Close();
    virtual void vfn_20();
    virtual void vfn_24();
    char szFileName[260];
    TESFile* pFile;
};

class GameSettingCollection : public SettingCollectionMap<Setting>
{
  public:
    virtual bool ReadSetting(Setting& setting);
    virtual bool Open(bool create);
    virtual bool Close();
    virtual bool ReadSetting(TESFile* file, const char* key);

    // Actor::IsFleeing(bool) candidate is incompatible with this call site.
};


extern "C" void* __cdecl _alloca(unsigned int size);

#endif
