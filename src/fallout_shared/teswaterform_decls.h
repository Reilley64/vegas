// fallout_shared/teswaterform_decls.h: declares TESSound, EffectItem, WaterListPrefix, WaterEffectList, WaterSpellPrefix and more
#ifndef FNV_TESWATERFORM_DECLS_H
#define FNV_TESWATERFORM_DECLS_H


#include "fnv/decl/FUN_00404390_shell.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01031000.h"
#define IsFormInitialized                                                                                              \
    unusedWaterDeclaration();                                                                                          \
    unsigned int GetDataSizeAdjustment();                                                                              \
    bool IsFormInitialized
#include "TESForm.h"
#undef IsFormInitialized

class SpellItem;
class TESConditionItem;
class TESEffectShader;
class TESSound : public TESForm
{
};
class EffectItem
{
  public:
    int GetAffectedActorValue();
};
struct WaterListPrefix
{
    unsigned int prefix;
};
class WaterEffectList : public WaterListPrefix, public BSSimpleList<EffectItem*>
{
};
struct WaterSpellPrefix
{
    unsigned int prefix[3];
};
class SpellItem : public TESForm, public WaterSpellPrefix, public WaterEffectList
{
};
namespace ActorValue {
enum Index
{
    ActorValue__Index_VALUE_NONE = -1
};
}
typedef ActorValue::Index ActorValue__Index;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};
class EffectSetting
{
  public:
    void SetEnchantEffectShader(TESEffectShader*);
};
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern int DAT_01184118;

extern float DAT_010231a4;

class BGSImpactData
{
  public:
};
class TESFullName;
class TESTexture;
class TESTextureLoader
{
  public:
};
template <int N> struct EndianSizeTag
{
};
#include <malloc.h>
#endif
