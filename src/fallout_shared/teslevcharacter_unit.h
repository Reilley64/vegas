// fallout_shared/teslevcharacter_unit.h: declares TESObject, ShortPoint3, TESBoundObject__BOUND_DATA, TESBoundObject, TESBoundAnimObject and more
#ifndef FNV_TESLEVCHARACTER_UNIT_H
#define FNV_TESLEVCHARACTER_UNIT_H

#include <cstring>
#include <malloc.h>
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/Owner487a60.h"
#include "fnv/decl/TmpEndian.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "teslevcharacter_TESForm.h"
#include "TESGlobal.h"
#include "layout_support.h"
class TESActorBase;
struct BGSLoadFormBuffer;
class BSFileEntry;
class LeveledObject;
class ContainerItemExtra;
class ShortPoint3;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESLevCharacter;
class TESLeveledList;
class TESModel;
class TESModelTextureSwap;
class TESFormList;
class FileEntryList;
class DistantTreeTextureInfo;
class TESObject : public TESForm
{
  public:
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
};
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
class TESBoundObject : public TESObject
{
  public:
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
};
class TESBoundAnimObject : public TESBoundObject
{
  public:
};
struct BGSLoadFormBuffer;
class TESLeveledList : public BaseFormComponent
{
  public:
    void FUN_0042e680(unsigned char);
    void InitItem(TESForm* form);
    void LoadGame(BGSLoadFormBuffer* buffer);
    BSSimpleList<LeveledObject*> leveledList;  // +0x4, 8 bytes
    unsigned char m_pChanceGlobal;             // +0xC, 1 bytes
    unsigned char m_ucChanceNone;              // +0xD, 1 bytes
    unsigned char layoutPaddingE[2];
    TESGlobal* m_pLevelGlobal;                       // +0x10, 4 bytes
    BSSimpleList<LeveledObject*> m_kLeveledObjects;  // +0x14, 8 bytes
public:
    void Revert(::BGSLoadFormBuffer *);
};
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
};
class TESModel : public BaseFormComponent
{
  public:
    static void LoadModelData(TESModel*, TESFile*);
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
class TESModelTextureSwap : public TESModel
{
  public:
    void InitItem(TESForm* form);
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
};
class TESLevCharacter : public TESBoundAnimObject, public TESLeveledList, public TESModelTextureSwap
{
  public:
    bool Load(TESFile*);
    TESActorBase* pTemplate;  // +0x6C, 4 bytes
};
class TESLevCreature : public TESBoundObject, public TESLeveledList, public TESModelTextureSwap
{
  public:
    TESActorBase* pTemplate;
    virtual void InitItem();
};
class TESLevItem : public TESBoundObject, public TESLeveledList
{
  public:
    void LoadGame(BGSLoadFormBuffer* buffer);
};
class TESFileFormVersion
{
  public:
};
class ContainerItemExtra
{
  public:
    ContainerItemExtra();
    bool Load(TESFile*);
    unsigned char data[12];
};
class LeveledObject
{
  public:
    unsigned short level;
    unsigned short pad;
    TESForm* form;
    ContainerItemExtra* extra;
};
extern LeveledObject* DAT_011c8e64;
#pragma intrinsic(_alloca)
#endif
