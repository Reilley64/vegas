// fallout_shared/tesclass_decls.h: declares FormChangeMask, BGSLoadFormBuffer, TESFullName, TESDescription, TESTexture and more

#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_00480130_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_005b5000.h"
#include "tesclass_form_decls.h"
namespace ActorValue {
enum Index
{
    None = -1
};
}
class FormChangeMask
{
    unsigned int flags;

  public:
    operator bool() const;
};
class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int);
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> name;
};
class TESDescription : public BaseFormComponent
{
  public:
    unsigned int offset;
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> name;
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESAttributes : public BaseFormComponent
{
  public:
    unsigned char attrs[7];
};
class BGSImpactData
{
  public:
};
class LegacyActorBaseData
{
  public:
    ActorValue::Index skills[3];
    char flags;
    int services;
    unsigned char trainingSkill, trainingLevel;
    void SwapEndianData();
};
class TESClassData
{
  public:
    ActorValue::Index skills[4];
    char flags;
    int services;
    unsigned char trainingSkill, trainingLevel;
};
class TESClass : public TESForm, public TESFullName, public TESDescription, public TESTexture, public TESAttributes
{
  public:
    TESClassData data;
    void SetClassSkillAtIndex(int, ActorValue::Index);
    void ResetFormData();
    void LoadGame(BGSLoadFormBuffer*);
    bool Load(TESFile*);
};
extern "C" void* __cdecl memset(void*, int, unsigned int);

extern "C" void* __cdecl _alloca(unsigned int);
class TESFileFormInt
{
  public:
};
