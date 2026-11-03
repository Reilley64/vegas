#ifndef FNV_TESOBJECTCONT_MATCH_DECLS_H
#define FNV_TESOBJECTCONT_MATCH_DECLS_H

#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/symbols_005b5000.h"
class TESObjectCONT_TESScriptableInitCall
{
  public:
    void InitItem(TESForm*);
};

class TESSound : public TESForm
{
};

class TESFileFormVersion
{
  public:
};

class ContainerItemExtra
{
  public:
    unsigned int opaque0;
    unsigned int opaque4;
    unsigned int opaque8;
    ContainerItemExtra();
    bool Load(TESFile*);
};

struct ContainerItemExtraOwner
{
    unsigned int opaque0;
    unsigned int opaque4;
    ContainerItemExtra* item;
};

class CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};

class EffectSetting
{
  public:
};

class BGSVoiceType;
class BGSTalkingActivator
{
  public:
    void SetVoiceType(BGSVoiceType*);
};

struct CNTOChunkData
{
    unsigned int formID;
    unsigned int count;
};

extern "C" ContainerItemExtraOwner* DAT_011c9348;


#endif
