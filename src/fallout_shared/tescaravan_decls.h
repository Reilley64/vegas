// Layout asserts are preserved; the member declarations used by
// fallout_shared/tescaravan.cpp are added below each class.
#ifndef FNV_TASK_TESCARAVAN_COPY_H
#define FNV_TASK_TESCARAVAN_COPY_H

#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00489000.h"
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "TESTexture.h"

class TESFormList;
class TESSound;
class Script;
class DistantTreeTextureInfo;
class BSFileEntry;
class TESCaravanCard;
class TESCaravanMoney;

class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
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
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
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
    // base BaseFormComponent at +0x0, size 4
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void SetModelFilePath(const char*);
    static void LoadModelData(TESModel*, TESFile*);
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};

class TESModelTextureSwap : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
    void InitItem(TESForm* form);
};

class BGSMessageIcon : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESIcon Icon;  // +0x4, 12 bytes
};

class TESValueForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned int iValue;  // +0x4, 4 bytes
    ~TESValueForm();
};

class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;  // +0x4
    bool m_bHasScript;      // +0x8
    unsigned char layoutPadding9[3];
    void InitItem(TESForm* form);
};

class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESSound* m_pPickupSound;   // +0x4, 4 bytes
    TESSound* m_pPutdownSound;  // +0x8, 4 bytes
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm* form);
};

class UnsignedValuePair
{
  public:
    unsigned int m_uiFirstValue;   // +0x0, 4 bytes
    unsigned int m_uiSecondValue;  // +0x4, 4 bytes
};

class TESCaravanCard : public TESBoundObject,
                       public TESFullName,
                       public TESModelTextureSwap,
                       public TESIcon,
                       public BGSMessageIcon,
                       public TESValueForm,
                       public TESScriptableForm,
                       public BGSPickupPutdownSounds
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModelTextureSwap at +0x3C, size 32
    // base TESIcon at +0x5C, size 12
    // base BGSMessageIcon at +0x68, size 16
    // base TESValueForm at +0x78, size 8
    // base TESScriptableForm at +0x80, size 12
    // base BGSPickupPutdownSounds at +0x8C, size 12
    bool bIsActive;  // +0x98, 1 bytes
    unsigned char layoutPadding99[3];
    TESTexture m_kFrontTexture;  // +0x9C, 12 bytes
    TESTexture m_kBackTexture;   // +0xA8, 12 bytes
    UnsignedValuePair data;      // +0xB4, 8 bytes
    TESCaravanCard();
    virtual bool Load(TESFile*);
    void ResetFormData();
    void InitItem();
};

class TESCaravanMoney : public TESBoundObject,
                        public TESFullName,
                        public TESModelTextureSwap,
                        public TESIcon,
                        public BGSMessageIcon,
                        public TESValueForm,
                        public BGSPickupPutdownSounds
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModelTextureSwap at +0x3C, size 32
    // base TESIcon at +0x5C, size 12
    // base BGSMessageIcon at +0x68, size 16
    // base TESValueForm at +0x78, size 8
    // base BGSPickupPutdownSounds at +0x80, size 12
    TESModelTextureSwap m_kModelTextureSwaps[2];  // +0x8C, 64 bytes
    virtual bool Load(TESFile*);
    void ResetFormData();
    void InitItem();
};

// Unit-local shim: TESFormInitFlag declares IsFormInitialized used by InitItem.
struct TESFormInitFlag : public TESForm
{
};

class CaravanDeckData
{
  public:
    int m_iValue;  // +0x0, 4 bytes
};

class TESCaravanDeck : public TESForm, public TESFullName
{
  public:
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    BSSimpleList<TESCaravanCard*>* m_pCardListHeadCur;  // +0x24, 4 bytes
    CaravanDeckData data;                  // +0x28, 4 bytes
    TESCaravanDeck();
    void ResetFormData();
    virtual bool Load(TESFile* file);
};
#endif

class TESFileFormVersion
{
  public:
};
class TESTextureLoader
{
  public:
};
