// fallout_shared/tescombatstyle_decls.h: declares StatsChunkData, TESCombatStyle, NiAVObject, BGSHungerStage, CombatStyleAccess and more

#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSMultiBoundRoom.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/symbols_00505000.h"
#include "TESForm.h"
struct UnsignedIntArray16
{
    unsigned int data[16];
    void FUN_00505610();
};
struct StatsChunkData
{
    unsigned int data[23];
    void SwapEndianFields();
};
struct UInt32ChunkData
{
    unsigned int data[21];
};
class TESCombatStyle : public TESForm
{
  public:
    UnsignedIntArray16 m_kUnsignedIntArray16;
    StatsChunkData Data;
    UInt32ChunkData m_kUInt32ChunkData;
    TESCombatStyle();
    void ResetFormData();
    bool Load(TESFile*);
};
struct NiPoint3;
class NiAVObject
{
  public:
    NiPoint3& FUN_0043c490();
};
class HungerStageData;
class BGSHungerStage
{
  public:
};
class CombatStyleAccess
{
  public:
};
class TESFileFormVersion
{
  public:
};
class TESFileExtra
{
  public:
};
