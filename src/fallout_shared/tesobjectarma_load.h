// fallout_shared/tesobjectarma_load.h: declares TESFile, TESFileFormVersion, ArmorData, BIPED_MODEL_OLD, RegionDataEntry and more
#ifndef TESOBJECTARMA_LOAD_H
#define TESOBJECTARMA_LOAD_H

#include <malloc.h>
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0047a380_shell.h"
#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
class TESFile
{
  public:
    bool GetChunkData(unsigned int*);
    bool IsEndianConversionRequired();
    bool NextChunk();
};
class TESFileFormVersion
{
  public:
};
enum ENUM_FORM_ID
{
    FORM_ARMO = 24
};
struct ArmorData
{
    unsigned char bytes[12];
};
struct BIPED_MODEL_OLD
{
    unsigned short m_uiBipedModelFlags;
    unsigned char m_ucBipedModelData;
};
class RegionDataEntry
{
  public:
};
class TESFullName;
class TESFullNameLoader
{
  public:
};
class TESModel
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void SetModelFilePath(const char*);
    unsigned char storage[20];
    static void LoadModelData(TESModel*, TESFile*);
};
class TESModelTextureSwap : public TESModel
{
  public:
    unsigned char textureSwapList[8];
    static void ReadTextureSwapChunk(TESModelTextureSwap*, TESFile*);
};
class TESTexture1024
{
  public:
    unsigned char storage[12];
};
class BGSMessageIcon
{
  public:
    unsigned char storage[16];
};
class BGSEquipType
{
  public:
    unsigned char storage[8];
};
// The equipment setter is folded with this canonically bound scalar setter.
class TESResponse
{
  public:
};
#endif
