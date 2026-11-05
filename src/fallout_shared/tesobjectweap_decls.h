// fallout_shared/tesobjectweap_decls.h: declares TESFullName, TESTexture, TESIcon, TESScriptableForm, TESHealthForm and more
#ifndef TESOBJECTWEAP_DECLS_H
#define TESOBJECTWEAP_DECLS_H

#include <cstring>
#include <malloc.h>
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004ad010_shell.h"
#include "fnv/decl/FUN_004bcf60_shell.h"
#include "fnv/decl/FUN_0051f4b0_shell.h"
#include "fnv/decl/FUN_0051f4d0_class.h"
#include "fnv/decl/FUN_0051f4f0_Class.h"
#include "fnv/decl/FUN_0051f530_class.h"
#include "fnv/decl/FUN_00524b60_shell.h"
#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0067ff10__FUN_0067ff10_Class.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "layout_support.h"

#include "TESObjectWEAPOwner.h"

class TESFileFormVersion : public TESFile
{
  public:
};
class TESFileChunkData16 : public TESFile
{
  public:
};

class TESAmmo : public TESBoundObject
{
  public:
};
class BGSProjectile : public TESBoundObject, public TESFullName, public TESModel, public BGSPreloadable
{
};
class BGSImpactDataSet : public TESForm, public BGSPreloadable
{
};
class TESEffectShader : public TESForm
{
};
class SpellItem : public TESForm
{
};
class TESSound : public TESBoundObject
{
};
class TESObjectSTAT : public TESBoundObject
{
};
class TESObjectIMOD : public TESBoundObject
{
};
class ModelLoader
{
  public:
};
class TES
{
  public:
};
class TESFormInitFlag : public TESForm
{
  public:
};
class BGSImpactData : public TESForm
{
  public:
};
namespace ActorValue
{
}
bool FUN_0066eba0(ActorValue__Index);
union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    char* s;
};
class INISettingCollection;
template <class Collection> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
#endif
