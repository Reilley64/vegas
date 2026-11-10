// fallout_shared/bgscamerashot_decls.h: declares VATS, StateNode, CameraTargetResetFields, TESFileFormInt, CombatProcedure and more
#ifndef FNV_BGSCAMERASHOT_DECLS_H
#define FNV_BGSCAMERASHOT_DECLS_H

#include <cstring>
#include <malloc.h>
#include "fnv/decl/CameraState.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_009ca410_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00529000.h"
#include "fnv/symbols_005b5000.h"
class BSExtraData;
struct InventoryChanges;
class TESBoundObject;
class TESObjectCELL;
class CellDataNode;
class AnimData;
class ValidBip01Names;
struct ScriptLocals;
class NiAVObject;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
class VATS
{
  public:
};
class StateNode
{
  public:
};
class ImageSpaceModifierInstanceDOF;
struct CameraTargetResetFields
{
    char pad[12];
    void* field0c;
    StateNode* node;
    float f14, f18;
    char pad1c[12];
    ImageSpaceModifierInstanceDOF* a;
    ImageSpaceModifierInstanceDOF* b;
};
class TESFileFormInt
{
  public:
};
struct CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};
class TESFile;
class BGSImpactData
{
  public:
};
struct CameraShotLegacyData
{
    int action, location, target;
    unsigned int flags;
    float playerMult, globalMult, maxTime, minTime;
};
#pragma intrinsic(_alloca)
#endif
