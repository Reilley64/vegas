// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESBIPEDMODELFORM_H
#define FNV_TESBIPEDMODELFORM_H
#include "fnv/decl/TESActorBase.h"
#include "layout_support.h"
#include "tesbipedmodelform_types_BIPED_OBJECT.h"
#include "tesbipedmodelform_types_SEX.h"
#include "BaseFormComponent.h"
#include "layout_support.h"
class BGSMessageIcon;
class BipedModelForm;
class BSFileEntry;
class BSFaceGenModel;
class TESBipedModelForm;
class TESModel;
class TESModelRDT;
class TESModelTextureSwap;
class FileEntryList;
class DistantTreeTextureInfo;
class TESForm;
class TESIcon : public BaseFormComponent
{
  public:
    unsigned int iconData[2];
    TESIcon();
    ~TESIcon();
};
class BGSBipedModelList;
class BipedAnim;
class BipedModelForm
{
  public:
    unsigned int m_uiBipedModelFlags;  // +0x0, 4 bytes
    union
    {
        unsigned int sFlagsAndPadding;  // +0x4, 4 bytes
        struct
        {
            unsigned char m_ucBipedModelData;
            unsigned char layoutPadding5[3];
        };
    };
    // void __cdecl BipedModelForm::*()
};
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // void __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*()
    // bool __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*(CHUNK_ID, const char*)
    // void __cdecl FileEntryList::*(TESFile*, TESForm*, const char*)
    // void __cdecl FileEntryList::*(FileEntryList*)
    // unsigned char __cdecl FileEntryList::*()
    // BSFileEntry** __cdecl FileEntryList::*()
    // void* __cdecl FileEntryList::*(unsigned int)
};
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    TESModel();
    virtual void vfn_10();
    virtual BSFaceGenModel* vfn_14();
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    unsigned int GetModelLength() const;
    // GetModelLength
    // bool __cdecl TESModel::*(CHUNK_ID)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // bool __cdecl TESModel::*()
    // char __cdecl TESModel::*()
    // void __cdecl TESModel::*(char)
    // bool __cdecl TESModel::*()
    // void __cdecl TESModel::*(bool)
    // unsigned int __cdecl TESModel::*()
    // void __cdecl TESModel::*(unsigned int)
    // bool __cdecl TESModel::*()
    // FileEntryList* __cdecl TESModel::*()
    // TESModel& __cdecl TESModel::*(const TESModel&)
    // void __cdecl TESModel::*()
};
class TESModelTextureSwap : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
    // TESModelTextureSwap
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*(CHUNK_ID, CHUNK_ID, CHUNK_ID)
    // bool __cdecl TESModelTextureSwap::*(void*&, unsigned int&)
    // bool __cdecl TESModelTextureSwap::*(void*, unsigned int, unsigned int)
    // void __cdecl TESModelTextureSwap::*(TESModelTextureSwap*, TESFile*)
    // void __cdecl TESModelTextureSwap::*(TESForm*)
    // void __cdecl TESModelTextureSwap::*(BaseFormComponent*)
    // bool __cdecl TESModelTextureSwap::*(BaseFormComponent*)
    // BSSimpleList<DistantTreeTextureInfo *>* __cdecl TESModelTextureSwap::*()
    // DistantTreeTextureInfo* __cdecl TESModelTextureSwap::*(int)
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*(const char*, int, BGSTextureSet*)
    // void __cdecl TESModelTextureSwap::*(int)
    // int __cdecl TESModelTextureSwap::*(NiAVObject*, const NiFixedString&)
    // void __cdecl TESModelTextureSwap::*(NiAVObject*)
    // bool __cdecl TESModelTextureSwap::*(NiAVObject*, BSMap<int,DistantTreeTextureInfo *>*, int&)
    // bool __cdecl TESModelTextureSwap::*(TESForm*, TESObjectREFR*)
    // TESModelTextureSwap* __cdecl TESModelTextureSwap::*()
    // TESModelTextureSwap& __cdecl TESModelTextureSwap::*(const TESModelTextureSwap&)
    // void __cdecl TESModelTextureSwap::*()
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    void InitItem(TESForm*);
};
class BGSMessageIcon : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BGSMessageIcon();
    ~BGSMessageIcon();
    TESIcon Icon;  // +0x4, 12 bytes
    // BGSMessageIcon
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*(CHUNK_ID)
    // void __cdecl BGSMessageIcon::*(BGSMessageIcon*, TESFile*)
    // void __cdecl BGSMessageIcon::*(BaseFormComponent*)
    // bool __cdecl BGSMessageIcon::*(BaseFormComponent*)
    // TESIcon* __cdecl BGSMessageIcon::*()
    // const char* __cdecl BGSMessageIcon::*()
    // unsigned int __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*(const char*)
    // BGSMessageIcon& __cdecl BGSMessageIcon::*(const BGSMessageIcon&)
    // void* __cdecl BGSMessageIcon::*(unsigned int)
};
class TESModelRDT : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    TESModelRDT();
    // TESModelRDT
    // void __cdecl TESModelRDT::*()
    // TESModelRDT& __cdecl TESModelRDT::*(const TESModelRDT&)
    // void __cdecl TESModelRDT::*()
};
class TESBipedModelFormBase
{
  public:
    TESBipedModelFormBase();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent*);
    virtual bool CompareWithBase(BaseFormComponent*);
};
class TESForm;
class TESBipedModelForm : public TESBipedModelFormBase
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BipedModelForm m_kBipedModelForm;   // +0x4, 8 bytes
    TESModelTextureSwap bipedModel[2];  // +0xC, 64 bytes
    TESModelTextureSwap worldModel[2];  // +0x4C, 64 bytes
    TESIcon m_kIcon[2];                 // +0x8C, 24 bytes
    BGSMessageIcon messageIcon[2];      // +0xA4, 32 bytes
    TESModelRDT m_kFaceGenModel;        // +0xC4, 24 bytes
    // TESBipedModelForm
    // void __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*(TESForm*)
    // void __cdecl TESBipedModelForm::*(BaseFormComponent*)
    // bool __cdecl TESBipedModelForm::*(BaseFormComponent*)
    // bool __cdecl TESBipedModelForm::*(TESBipedModelForm*)
    // bool __cdecl TESBipedModelForm::*(BIPED_OBJECT, bool, BGSBipedModelList*)
    // void __cdecl TESBipedModelForm::*(BIPED_OBJECT, bool)
    // void __cdecl TESBipedModelForm::*(BipedAnim*, SEX, BIPED_OBJECT)
    // bool __cdecl TESBipedModelForm::*()
    // bool __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*(bool)
    // bool __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*(bool)
    // bool __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*(bool)
    // bool __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*(bool)
    // TESBipedModelForm* __cdecl TESBipedModelForm::*(TESForm*)
    // const char* __cdecl TESBipedModelForm::*()
    // GetIcon
    // GetMessageIcon
    // GetWorldModel
    // const char* __cdecl TESBipedModelForm::*()
    // const char* __cdecl TESBipedModelForm::*()
    // const char* __cdecl TESBipedModelForm::*(SEX)
    // void __cdecl TESBipedModelForm::*(SEX, const char*)
    // void __cdecl TESBipedModelForm::*(SEX, const char*)
    // void __cdecl TESBipedModelForm::*(const char*, BSStringT<char>&)
    // bool __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*(bool)
    // bool __cdecl TESBipedModelForm::*()
    // void __cdecl TESBipedModelForm::*(bool)
    // TESBipedModelForm& __cdecl TESBipedModelForm::*(const TESBipedModelForm&)
    // void* __cdecl TESBipedModelForm::*(unsigned int)
    TESBipedModelForm();
    bool IsPowerArmor();
    void InitItem(TESForm*);
    bool HasBipedModel(BIPED_OBJECT, bool, BGSBipedModelList*);
    void SetBipedModel(BipedAnim*, SEX, BIPED_OBJECT);
    void InitializeComponent();
    BSFaceGenModel* FUN_00480ce0();
public:
    static ::TESBipedModelForm *GetFormAsBipedModel(const ::TESForm *);
};
#endif
