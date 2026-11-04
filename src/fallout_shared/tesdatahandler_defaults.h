// fallout_shared/tesdatahandler_defaults.h: declares ActorValue, CameraPathManager, TESGlobalMap, Sky, MagicSystem and more
#ifndef FNV_TESDATAHANDLER_DEFAULTS_H
#define FNV_TESDATAHANDLER_DEFAULTS_H


#include "fnv/symbols_00409000.h"
#include "fnv/symbols_0066f000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cb000.h"
class CameraPathManager
{
  public:
    void UpdateCameraPaths();
    void InitializeCameraPaths();
};
class TESGlobalMap
{
  public:
};
class Sky
{
  public:
    static Sky* GetInstance();
    void SetCurrentClimate(TESClimate*, bool);
};
class MagicSystem
{
  public:
    static void InitializeMagicSystem();
};
class TESForm;
enum DEFAULT_OBJECT;
class BGSDefaultObjectManager : public TESForm
{
  public:
    static BGSDefaultObjectManager* Instance();
public:
    static ::TESForm *GetDefaultObjectByIndex(::DEFAULT_OBJECT);
};
void CreateDefaultTopics();
void FUN_00479570();
template <class T> unsigned int BSStringLength(const T*);
extern TESEyes* DAT_011cb600;
extern TESFaction* DAT_011cb550;
#endif
