
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00501c90_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e70_shell.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_0048cca0.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01011000.h"
#include "tesobjectacti_load.h"
#include <malloc.h>
#include "fnv/symbols_00472000.h"

template <> BSStringT<char>::~BSStringT()
{
    reinterpret_cast<::TextString *>(this)->FUN_004037f0(0, 0);
}

// Resets several fields to zero and sets the prompt pointer to g_emptyTopicInfoPrompt.
// @fnv 0x00510710
void TESObjectACTI::ResetFormData()
{
    m_pSoundEffect = 0;
    m_pLoopSound = 0;
    m_pWaterForm = 0;
    m_pTalkingActivator = 0;
    pRadioTemplate = 0;
    m_kActivationPrompt = ::DAT_01011584;
}
class TESSound;
struct FUN_004fd3a0_shell : public TESObjectACTI
{
    TESSound* FUN_004fd3a0();
};

// @fnv 0x004fd3a0
TESSound* FUN_004fd3a0_shell::FUN_004fd3a0()
{
    return this->m_pSoundEffect;
}

extern int DAT_01029ee0;

// @fnv 0x00510620
void* FUN_00510620(void** pThis)
{
    *pThis = &DAT_01029ee0;
    return pThis;
}

struct SH
{
    bool Set(BSStringT<char> const&);
};
struct FloatValueProvider : public TESObjectACTI
{
    void FUN_00510ea0(BSStringT<char> s);
};
// @fnv 0x00510a90
bool TESObjectACTI::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunk;
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            struct TextureChunk
            {
                int size;
                char* data;
            } textureChunk;
            textureChunk.size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            textureChunk.data = (char*)_alloca(textureChunk.size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureChunk.data), textureChunk.size);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(textureChunk.data, textureChunk.size,
                                 reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((reinterpret_cast<TESFileFormVersion*>(file)))->FUN_00403570());
            break;
        }
        case 0x49524353: {
            unsigned int script = 0;
            file->GetChunkData(&script);
            reinterpret_cast<CombatProcedure*>(static_cast<TESScriptableForm *>(this))
                ->Initialize(reinterpret_cast<CombatController*>(script));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            ::FUN_004781e0(this, file);
            break;
        case 0x4d414e53: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            SetLoopingSound(reinterpret_cast<TESSound*>(sound));
            break;
        }
        case 0x4d414e56: {
            unsigned int water = 0;
            file->GetChunkData(&water);
            reinterpret_cast<::TESObjectACTI *>((reinterpret_cast<EffectSetting*>(this)))->SetActivateSound((::TESSound *)(::TESEffectShader *)(reinterpret_cast<TESEffectShader*>(water)));
            break;
        }
        case 0x4d414e49: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader(reinterpret_cast<TESEffectShader*>(sound));
            break;
        }
        case 0x4d414e57: {
            unsigned int station = 0;
            file->GetChunkData(&station);
            reinterpret_cast<::FUN_008ac890_shell *>((reinterpret_cast<EffectSetting*>(this)))->SetWaterForm((::TESWaterForm *)(::TESSound *)(reinterpret_cast<TESSound*>(station)));
            break;
        }
        case 0x4d414e52: {
            unsigned int radioTemplate = 0;
            file->GetChunkData(&radioTemplate);
            reinterpret_cast<EffectSetting*>(this)->SetBoltSound(reinterpret_cast<TESSound*>(radioTemplate));
            break;
        }
        case 0x4f544158: {
            int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            if (size > 1)
            {
                char* text = new char[size];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(text), size);
                reinterpret_cast<::FloatValueProvider *>(this)->FUN_00510ea0(BSStringT<char>(text));
                delete[] text;
            }
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
// Calls Set on the SH object at offset 0x88 with the given string.
// @fnv 0x00510ea0
void FloatValueProvider::FUN_00510ea0(BSStringT<char> s)
{
    ((SH*)((char*)this + 0x88))->Set(s);
}

struct TESFullName_ext : TESFullName
{
};

// @fnv 0x00511840
const char* FUN_00511840(char* apObject)
{
    return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((TESFullName_ext*)(apObject + 0x30))))->FUN_00408da0()));
}

struct Holder005105F0 : TESObjectACTI
{
    void* FUN_005105f0(unsigned int);
};
class FormChangeMask
{
  public:
    int flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(int);
};
struct BGSSaveFormBuffer
{
};
struct FUN_00484d60_holder
{
};
struct BGSSaveGameBuffer
{
};
struct FNStub
{
};
struct FUN_00511860_holder : ::TESObjectACTI
{
    void FUN_00511860(BGSSaveFormBuffer* apSaveGameBuffer);
};
// @fnv 0x00511860
void FUN_00511860_holder::FUN_00511860(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FakeForm *>((((FUN_00484d60_holder*)this)))->SaveIfChanged(apSaveGameBuffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(((BGSLoadFormBuffer*)apSaveGameBuffer)->GetChangeFlags(4)))->FUN_004280f0(4))
    {
        const char* pfullname = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(((FNStub*)static_cast<TESFullName *>(this))))->FUN_00408da0()));
        reinterpret_cast<::FUN_00865e70_shell *>((((BGSSaveGameBuffer*)apSaveGameBuffer)))->FUN_00865e70(pfullname, 0);
    }
}

struct QBase
{
    virtual void Foo();
    char _pad[44];
    QBase(int);
};
struct FUN_00837250 : QBase
{
    int field_30;
    FUN_00837250(unsigned int iflags);
};
// Calls the QBase constructor with 0 and stores the given flags in field_30.
// @fnv 0x00837250
FUN_00837250::FUN_00837250(unsigned int auiFlags) : QBase(0)
{
    field_30 = auiFlags;
}

struct FUN_005110e0_Holder
{
    char _pad[0x88];
    BSStringT<char> m_88;
    BSStringT<char> GetString();
};
// Returns the BSStringT<char> member at offset 0x88 of the holder.
// @fnv 0x005110e0
BSStringT<char> FUN_005110e0_Holder::GetString()
{
    return m_88;
}

struct FUN_00510770_shell : public TESObjectACTI
{
    void FUN_00510770();
};

class TESSound : public TESForm
{
  public:
};

struct TESWaterForm : public TESForm
{
  public:
};

class BGSTalkingActivator : public TESForm
{
  public:
    bool IsRadioStation(void);
};

struct BGSDestructibleObjectFormInitItemProxy
{
    void InitItem(TESForm* form);
};

struct TESModelTextureSwapInitItemProxy
{
    void InitItem(TESForm* form);
};


void BGSDestructibleObjectFormInitItemProxy::InitItem(TESForm* form)
{}

void TESModelTextureSwapInitItemProxy::InitItem(TESForm* form)
{}

// Resolves the activator's sound, water and radio-station form IDs, warns when a lookup fails, and initializes the scriptable, destructible and model sub-forms.
// @fnv 0x00510770
void FUN_00510770_shell::FUN_00510770()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;

    static_cast<TESScriptableForm *>(this)->InitItem(this);
    reinterpret_cast<::BGSDestructibleObjectForm *>((reinterpret_cast<BGSDestructibleObjectFormInitItemProxy*>(static_cast<BGSDestructibleObjectForm *>(this))))->InitItem(this);
    reinterpret_cast<::TESModelTextureSwap *>((reinterpret_cast<TESModelTextureSwapInitItemProxy*>(static_cast<TESModelTextureSwap *>(this))))->InitItem(this);

    std::uintptr_t itempint = reinterpret_cast<std::uintptr_t>(m_pSoundEffect);
    if (itempint)
    {
        ::ResolveFormID((unsigned int *)&(itempint), GetFile(-1));
        m_pSoundEffect = dynamic_cast<TESSound*>(::FUN_004839c0(itempint));
        if (!m_pSoundEffect)
            ::FUN_005b5e40();
    }

    itempint = reinterpret_cast<std::uintptr_t>(m_pLoopSound);
    if (itempint)
    {
        ::ResolveFormID((unsigned int *)&(itempint), GetFile(-1));
        m_pLoopSound = dynamic_cast<TESSound*>(::FUN_004839c0(itempint));
        if (!m_pLoopSound)
            ::FUN_005b5e40();
    }

    itempint = reinterpret_cast<std::uintptr_t>(pRadioTemplate);
    if (itempint)
    {
        ::ResolveFormID((unsigned int *)&(itempint), GetFile(-1));
        pRadioTemplate = dynamic_cast<TESSound*>(::FUN_004839c0(itempint));
        if (!pRadioTemplate)
            ::FUN_005b5e40();
    }

    itempint = reinterpret_cast<std::uintptr_t>(m_pWaterForm);
    if (itempint)
    {
        ::ResolveFormID((unsigned int *)&(itempint), GetFile(-1));
        m_pWaterForm = dynamic_cast<TESWaterForm*>(::FUN_004839c0(itempint));
        if (!m_pWaterForm)
            ::FUN_005b5e40();
    }

    itempint = reinterpret_cast<std::uintptr_t>(m_pTalkingActivator);
    if (itempint)
    {
        ::ResolveFormID((unsigned int *)&(itempint), GetFile(-1));
        m_pTalkingActivator = dynamic_cast<BGSTalkingActivator*>(::FUN_004839c0(itempint));
        if (!m_pTalkingActivator || !m_pTalkingActivator->IsRadioStation())
        {
            ::FUN_005b5e40();
            m_pTalkingActivator = 0;
        }
    }

    SetInitializationState(true);
}

struct ACTIStr : public BSStringT<char>
{
};

struct ACTIView : public TESObjectACTI
{
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual TESForm* Unk_50();
    ACTIStr GetPromptA();
    bool FUN_005111e0(TESForm* apForm);
};

// @fnv 0x005111e0
bool ACTIView::FUN_005111e0(TESForm* apForm)
{
    int iCompare;
    ACTIView* pOther = (ACTIView*)dynamic_cast<TESObjectACTI*>(apForm);
    if (!pOther)
        return true;
    if (reinterpret_cast<::FUN_004fd3a0_shell *>(this)->FUN_004fd3a0() != reinterpret_cast<::FUN_004fd3a0_shell *>((pOther))->FUN_004fd3a0())
        return true;
    if (((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>(this)->FUN_00407820())) != ((::TESForm *)(reinterpret_cast<::FUN_00407820_shell *>((pOther))->FUN_00407820())))
        return true;
    if (((::TESForm *)(std::uintptr_t)(reinterpret_cast<::TESPackage *>(this)->GetRefCount())) != ((::TESForm *)(std::uintptr_t)(reinterpret_cast<::TESPackage *>((pOther))->GetRefCount())))
        return true;
    if (Unk_50() != pOther->Unk_50())
        return true;
    if (((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)this))) != ((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(pOther)))))
        return true;
    {
        ACTIStr kPrompt = GetPromptA();
        ACTIStr kOtherPrompt = pOther->GetPromptA();
        iCompare = reinterpret_cast<::FUN_00501c90_shell *>((void *)&kPrompt)->CompareString(&kOtherPrompt, true);
    }
    if (iCompare)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(pOther))
        return true;
    return false;
}

struct StrLen
{
};
struct StrOut : BSStringT<char>
{
};
struct SoundId
{
};
struct Chunk487010
{
    int unk00;
    int unk04;
    int unk08;
};
struct Chunk48a520
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct Chunk48cca0
{
    int unk00;
    int unk04;
    int unk08;
};
struct Chunk477f20
{
    int unk00;
    int unk04;
    int unk08;
};

struct ActiSave
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    Chunk487010 name30;
    Chunk48a520 model3c;
    Chunk48cca0 script5c;
    Chunk477f20 destruct68;
    SoundId* m_pSoundEffect;
    SoundId* m_pLoopSound;
    SoundId* pRadioTemplate;
    SoundId* m_pWaterForm;
    SoundId* m_pTalkingActivator;
    BSStringT<char> m_kActivationPrompt;

    StrOut GetString();
    void Save();
};

// Runs the base save, saves the name, model, script and destruction chunks, writes each sound id under its tag, then writes the text chunk and finishes the save.
// @fnv 0x00510f00
void ActiSave::Save()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(&(name30))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>(&(model3c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::S_0048cca0 *>(&(script5c))->FUN_0048cca0();
    reinterpret_cast<::FUN_00477f20_shell *>(&(destruct68))->FUN_00477f20();
    if (m_pSoundEffect)
    {
        unsigned int uiSoundId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pSoundEffect))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e53, uiSoundId);
    }
    if (m_pLoopSound)
    {
        unsigned int uiSoundId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pLoopSound))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e56, uiSoundId);
    }
    if (pRadioTemplate)
    {
        unsigned int uiSoundId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pRadioTemplate))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e49, uiSoundId);
    }
    if (m_pWaterForm)
    {
        unsigned int uiSoundId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWaterForm))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e57, uiSoundId);
    }
    if (m_pTalkingActivator)
    {
        unsigned int uiSoundId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pTalkingActivator))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e52, uiSoundId);
    }
    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((StrLen*)&m_kActivationPrompt)))->FUN_004048e0())) > 0)
    {
        StrOut kText = GetString();
        StrOut kTextForLength = GetString();
        ::FUN_004856f0((void *)(std::uintptr_t)0x4f544158, (void *)kText.pString,
                       (void *)(std::uintptr_t)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&kTextForLength)->FUN_004048e0())) + 1));
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct FUN_004280f0_cls
{
};
struct FUN_00428110_cls
{
    FUN_004280f0_cls* FUN_00428110(void* dst, unsigned int size);
};
struct FUN_00489100_cls
{
};
struct S_005118c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    FUN_00489100_cls unk30;
    void FUN_005118c0(FUN_00428110_cls* stream);
};
// Reads a flag from the stream, and if set reads a string into buf and stores it in unk30.
// @fnv 0x005118c0
void S_005118c0::FUN_005118c0(FUN_00428110_cls* stream)
{
    int flag;
    char buf[260];
    reinterpret_cast<::TESForm *>(this)->LoadGame(stream);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((stream->FUN_00428110(&flag, 4)))->FUN_004280f0({}))
    {
        reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((stream))->FUN_008649a0(buf);
        reinterpret_cast<::TESFullName *>(&(unk30))->SetFullName(buf);
    }
}

// TESObjectACTI destructor with natural TESBoundAnimObject, TESFullName,
// TESModelTextureSwap, script/destructible/open-close bases and BSString member.
struct FUN_0050f740
{
    virtual ~FUN_0050f740();
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};
struct FUN_00591300
{
    virtual ~FUN_00591300();
    char* name;
    unsigned short length, capacity;
};
struct FUN_0048a490
{
    virtual ~FUN_0048a490();
    char* model;
    unsigned short length, capacity;
    unsigned char textureCount;
    void* textures;
    unsigned char modelFlags;
    void* swaps;
    void* nextSwap;
};
struct Scriptable476
{
    virtual void Method();
    void* script;
    bool initialized;
};
struct FUN_00475380
{
    virtual ~FUN_00475380();
    void* data;
};
struct OpenClose476
{
    virtual void Method();
};
struct FUN_004037d0
{
    char* data;
    unsigned short length, capacity;
    ~FUN_004037d0();
};
struct FUN_00510640 : FUN_0050f740, FUN_00591300, FUN_0048a490, Scriptable476, FUN_00475380, OpenClose476
{
    void* loopingSound;
    void* activationSound;
    void* radioTemplate;
    void* water;
    void* radioStation;
    FUN_004037d0 activationPrompt;
    virtual ~FUN_00510640();
};
// Destructs the TESObjectACTI base and, when flags has bit 0 set, deallocates this object; returns this.
// @fnv 0x005105f0
void* Holder005105F0::FUN_005105f0(unsigned int flags)
{
    reinterpret_cast<::FUN_00510640 *>((this))->FUN_00510640::~FUN_00510640();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00510640
FUN_00510640::~FUN_00510640()
{}

class TESEffectShader;

class ActiV511
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual TESWaterForm* GetWaterForm();



    void FUN_00511120(TESForm* pkForm);
};

// @fnv 0x00511120
void ActiV511::FUN_00511120(TESForm* pkForm)
{
    ActiV511* pkActi = (ActiV511*)dynamic_cast<TESObjectACTI*>(pkForm);
    if (!pkActi)
        return;

    reinterpret_cast<::TESObjectACTI *>(this)->SetLoopingSound(reinterpret_cast<::FUN_004fd3a0_shell *>((pkActi))->FUN_004fd3a0());
    reinterpret_cast<::EffectSetting *>(this)->SetEnchantEffectShader(((::TESEffectShader *)(std::uintptr_t)(reinterpret_cast<::TESPackage *>((pkActi))->GetRefCount())));
    reinterpret_cast<::TESObjectACTI *>(this)->SetActivateSound(((::TESSound *)(reinterpret_cast<::FUN_00407820_shell *>((pkActi))->FUN_00407820())));
    reinterpret_cast<::FUN_008ac890_shell *>(this)->SetWaterForm(pkActi->GetWaterForm());
    reinterpret_cast<::EffectSetting *>(this)->SetBoltSound(((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(pkActi)))));
    reinterpret_cast<::FloatValueProvider *>((((TESObjectACTI*)this)))->FUN_00510ea0(reinterpret_cast<::FUN_005110e0_Holder *>((pkActi))->GetString());
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(pkForm);
}

// Adjustor thunk.
//
// The most derived form class inherits two different base sub-objects that
// both provide the same virtual slot (FUN_00511940).  One of those bases sits
// 0x3C bytes into the complete object, so the entry stored in that base's
// vtable slot has to move `this` back by 0x3C before it can jump to the
// implementation that expects the complete object pointer.
//
// MSVC emits such a thunk as
//     sub ecx, 0x3C
//     jmp <implementation>

// First base of the complete object: 0x3C bytes long (vtable pointer plus the
// state that precedes the second base sub-object).
struct ThunkPrimary_00511940
{
    virtual void FUN_00511940();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

// Second base of the complete object, placed at offset 0x3C.
struct ThunkSecondary_00511940
{
    virtual void FUN_00511940();
};

// Complete object: the virtual is overridden here, so the vtable slot of the
// second base needs a `this` adjusting thunk.
struct ThunkDerived_00511940 : public ThunkPrimary_00511940, public ThunkSecondary_00511940
{
// @fnv 0x00511940
    virtual void FUN_00511940();
    ThunkDerived_00511940();
};

ThunkDerived_00511940::ThunkDerived_00511940()
{}
