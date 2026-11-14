// fallout_shared/magic/effectarchetype_decls.h: declares EffectSetting, AnimIdle, EffectArchetypeEntry

#include "fnv/decl/FUN_008041c0_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
class MagicCaster;
class MagicItem;
class EffectItem;
class TESBoundObject;
class EffectSetting
{
  public:
    int GetArchetype();
};
class AnimIdle
{
  public:
};
class ActiveEffect
{
  public:
};
typedef ActiveEffect*(__cdecl* EffectFactory)(MagicCaster*, MagicItem*, EffectItem*);
struct EffectArchetypeEntry
{
    EffectFactory factory;
    unsigned int reserved[3];
};
extern EffectArchetypeEntry DAT_01183324[];
class MagicEffectSystem
{
  public:
    static ActiveEffect* Activate(MagicCaster*, MagicItem*, EffectItem*, TESBoundObject*);
};
