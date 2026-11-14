// fallout/ai/guardpackage_decls.h: declares TESForm, Actor, TESObjectREFRHelper, GuardActorPackageData, BGSLoadFormBuffer
#ifndef GUARDPACKAGE_DECLS_H
#define GUARDPACKAGE_DECLS_H

#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00483000.h"
namespace std {
double abs(float);
}
class TESForm
{
  public:
    virtual ~TESForm();
};
class Actor : public TESForm
{
};
class TESObjectREFRHelper
{
  public:
};
struct BGSLoadFormBuffer;
class GuardActorPackageData
{
  public:
    void* vtable;
    unsigned int eState;
    Actor* pWarningTarget;
    int iWarningCount;
    float m_fWarningTimer;
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
};
struct BGSLoadFormBuffer
{
  public:
};
#endif
