// fallout/magic/scripteffect_decls.h: declares BGSLoadFormBuffer, ScriptLocals, Script, ActorMover, MagicTarget and more

#include "fnv/decl/fnv_005a9f20__FUN_005a9f20_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
class TESObjectREFR;
struct BGSLoadFormBuffer
{
  public:
};
struct ScriptLocals
{
  public:
    void* master;
    char flags;
    void* action;
    void* local;
    void* effect;
    ScriptLocals();
    ~ScriptLocals();
};
class Script
{
  public:
    void AdvanceScript(TESObjectREFR*, ScriptLocals*, float);
};
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
class MagicTarget
{
  public:
    virtual void vfn_0();
    virtual TESObjectREFR* GetActor();
};
class ActiveEffect
{
  public:
    char data[0x4];
    void* unk08;
    void* unk0c;
    char pad10[0x18];
    void* unk28;
    char pad2c[0x1c];
    virtual void LoadGame(BGSLoadFormBuffer*);
public:
    void CopyData(::ActiveEffect *);
};
class ScriptEffect : public ActiveEffect
{
  public:
    Script* pScript;
    ScriptLocals* m_pScriptLocals;
    virtual void Update(float);
    void LoadGame(BGSLoadFormBuffer*);
};
