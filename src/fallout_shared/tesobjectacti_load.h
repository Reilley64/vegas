// fallout_shared/tesobjectacti_load.h: declares TESScriptableForm, TESObject, ShortPoint3, TESBoundObject__BOUND_DATA, TESBoundObject and more
#ifndef FNV_TESOBJECTACTI_H
#define FNV_TESOBJECTACTI_H

#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/symbols_00478000.h"
#include "tesobjectacti_layout.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#define FNV_TESSCRIPTABLEFORM_H
class Script;
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;
    bool m_bHasScript;
    char padding[3];
    void InitItem(TESForm*);
};
#include "tesobjectacti_layout.h"
class BGSDestructibleObjectForm;
class BGSOpenCloseForm;
class BGSTalkingActivator;
class BSFileEntry;
class CollisionComponent;
class ShortPoint3;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESMagicTargetForm;
class TESModel;
class TESModelTextureSwap;
class TESObjectACTI;
class TESFormList;
class FileEntryList;
class TESWaterForm;
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
class TESForm;
class TESModelTextureSwap : public TESModel
{
  public:
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
public:
    void InitItem(::TESForm *);
};
class TESMagicTargetForm
{
  public:
};
class TESForm;
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    CollisionComponent* pData;  // +0x4, 4 bytes
public:
    void InitItem(::TESForm *);
};
class BGSOpenCloseForm
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
};
class TESSound;
class TESObjectACTI : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public BGSDestructibleObjectForm,
                      public BGSOpenCloseForm,
                      public TESMagicTargetForm
{
  public:
    TESSound* m_pSoundEffect;                  // +0x74, 4 bytes
    TESSound* m_pLoopSound;                    // +0x78, 4 bytes
    TESSound* pRadioTemplate;                  // +0x7C, 4 bytes
    TESWaterForm* m_pWaterForm;                // +0x80, 4 bytes
    BGSTalkingActivator* m_pTalkingActivator;  // +0x84, 4 bytes
    BSStringT<char> m_kActivationPrompt;       // +0x88, 8 bytes
    void ResetFormData();
    virtual bool Load(TESFile*);
    void SetLoopingSound(TESSound*);
public:
    void SetActivateSound(::TESSound *);
};
#endif

class TESEffectShader;
class EffectSetting
{
  public:
    void SetEnchantEffectShader(TESEffectShader*);
    void SetBoltSound(TESSound*);
};
class CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};
class TESFileFormVersion
{
  public:
};
