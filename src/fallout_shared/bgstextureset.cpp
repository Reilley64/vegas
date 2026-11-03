
// Fallout: New Vegas decompilation: fallout_shared/bgstextureset.cpp.
#include "fnv/decl/Date.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00402d50.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_00485c10_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00591170.h"
#include "fnv/decl/FUN_005923c0.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/TextureLoader.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00593000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_00afd000.h"
#include "fnv/symbols_011c3000.h"
#include "bgstextureset_packet.h"
#include <cstdint>
#include <windows.h>
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_011f9000.h"

// @fnv 0x005922e0
BGSTextureSet::BGSTextureSet()
{
    ResetFormData();
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_TXST_ID)));
}

// @fnv 0x00592450
void BGSTextureSet::ResetFormData()
{
    for (int i = 0; i < 6; i++)
        pTextures[i].Init();
    m_pDecalData = 0;
    iFlags = 0;
    ::FUN_00403d30(m_ppTextureFileEntries, 0, sizeof(m_ppTextureFileEntries));
}

// Frees all six textures, deletes the decal data object if present, and clears the flags.
// @fnv 0x005924d0
void BGSTextureSet::ClearData()
{
    int i;
    for (i = 0; i < 6; i++)
        reinterpret_cast<::FUN_00402d50 *>(&(pTextures[i]))->FUN_00402d50::~FUN_00402d50();
    void* pX;
    void* pY = this->m_pDecalData;
    pX = pY;
    pX ? reinterpret_cast<::Date *>((((DecalDataDeleter*)pX)))->FUN_007b3fa0(1) : 0;
    iFlags = 0;
}

// @fnv 0x00592e70
const char* BGSTextureSet::GetTextureFilePath(int aeTextureType)
{
    const char* pTextureFilePath = 0;
    switch (aeTextureType)
    {
    case 0:
        pTextureFilePath = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pTextures[0]))->FUN_00408da0()));
        break;
    case 1:
        pTextureFilePath = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pTextures[1]))->FUN_00408da0()));
        break;
    case 2:
        pTextureFilePath = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pTextures[3]))->FUN_00408da0()));
        break;
    case 3:
        pTextureFilePath = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pTextures[4]))->FUN_00408da0()));
        break;
    case 4:
        pTextureFilePath = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pTextures[5]))->FUN_00408da0()));
        break;
    case 5:
        pTextureFilePath = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pTextures[2]))->FUN_00408da0()));
        break;
    }
    if (pTextureFilePath && *pTextureFilePath == '\0')
        pTextureFilePath = 0;
    return pTextureFilePath;
}

// Queues each non-null texture in the set to the model loader with the given priority and queued file.
// @fnv 0x005930e0
void BGSTextureSet::LoadTextures(int aePriority, QueuedFile* apQueuedFile, bool abFlag)
{
    for (int i = 0; i < 6; i++)
    {
        if (m_ppTextureFileEntries[i])
            reinterpret_cast<::TextureLoader *>((::g_modelLoader))->QueueTextureLoad(m_ppTextureFileEntries[i], aePriority, apQueuedFile);
    }
}

// Creates the null texture set once, assigns it ref ID 40 and editor ID "NullTextureSet", and registers it with the data handler.
// @fnv 0x00593140
void BGSTextureSet::InitializeNullTextureSet()
{
    if (!s_pNullTextureSet)
    {
        s_pNullTextureSet = new BGSTextureSet;
        s_pNullTextureSet->SetRefID(40, true);
        s_pNullTextureSet->SetEditorID_AtRuntime("NullTextureSet");
        reinterpret_cast<::TESDataHandler *>((((TESDataHandlerForms*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->AddFormToDataHandler(s_pNullTextureSet);
    }
}

// @fnv 0x005928a0
bool BGSTextureSet::Load(TESFile* file)
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
        case 0x30305854:
            ::TESTexture::ReadTextureData(&pTextures[0], file);
            break;
        case 0x31305854:
            ::TESTexture::ReadTextureData(&pTextures[1], file);
            break;
        case 0x32305854:
            ::TESTexture::ReadTextureData(&pTextures[2], file);
            break;
        case 0x33305854:
            ::TESTexture::ReadTextureData(&pTextures[3], file);
            break;
        case 0x34305854:
            ::TESTexture::ReadTextureData(&pTextures[4], file);
            break;
        case 0x35305854:
            ::TESTexture::ReadTextureData(&pTextures[5], file);
            break;
        case 0x4d414e44:
            reinterpret_cast<::FUN_00472840_impl *>((((TESFileChunkData16*)file)))->ReadChunkData(&iFlags);
            break;
        case 0x54444f44:
            if (!m_pDecalData)
                m_pDecalData = new DecalData;
            m_pDecalData->Load(file);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    for (int i = 0; i < 6; i++)
    {
        const char* pTexturePath = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(pTextures[i]))->FUN_00408da0()));
        if (pTexturePath && *pTexturePath)
        {
            char fullPath[260];
            TaskQueueInterface::CopyStringToBuffer(fullPath, 260, "Data\\Textures\\");
            strcat_s(fullPath, 260, pTexturePath);
            char path[260];
            CleanPath(fullPath, path, 260);
            NiPoint2 kDirHash;
            NiPoint2 fileHash;
            ::HashPathComponents(path, (::FileNameHash *)&((FileNameHash&)kDirHash), (::FileNameHash *)&((FileNameHash&)fileHash));
            m_ppTextureFileEntries[i] =
                ((::BSFileEntry *)(::fnv_00af6540::FindFileEntryInArchives((*(int *)&(const ::ArchiveType &)(ARCHIVE_TEXTURES)), (::fnv_00af6540::FileNameHash &)((FileNameHash&)kDirHash), (::fnv_00af6540::FileNameHash &)((FileNameHash&)fileHash), path)));
        }
    }
    return true;
}

// @fnv 0x00593210
void FUN_00593210()
{
    BGSTextureSet::s_pNullTextureSet = 0;
}

// @fnv 0x00593220
BGSTextureSet* __cdecl FUN_00593220()
{
    return BGSTextureSet::s_pNullTextureSet;
}

struct S591140
{
    void* FUN_00591140(unsigned int);
};
// Calls FUN_00591170, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x00591140
void* S591140::FUN_00591140(unsigned int flags)
{
    reinterpret_cast<::FUN_00591170 *>(this)->FUN_00591170::~FUN_00591170();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Holder
{
    void* FUN_00592380(unsigned int flags);
public:
    void FUN_00485680();
};
// Calls FUN_005923c0, frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00592380
void* Holder::FUN_00592380(unsigned int flags)
{
    reinterpret_cast<::FUN_005923c0 *>((this))->FUN_005923c0::~FUN_005923c0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xa0);
    return this;
}

struct FullNameEx
{
    int _m0;
    int _m1;
    int _m2;
};
struct Holder00592cc0
{
    char _pad[56];
    FullNameEx _arr[6];
    void SetFullNameByType(int, char const*);
};
// If aeType is below 6, calls SetFullName(apFilename) on the _arr entry at index aeType.
// @fnv 0x00592cc0
void Holder00592cc0::SetFullNameByType(int aeType, char const* apFilename)
{
    if (aeType < 6)
        reinterpret_cast<::TESFullName *>(&(_arr[aeType]))->SetFullName(apFilename);
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_0048e370_obj
{
};
struct FUN_00593320_shell
{
    void FUN_00593320(void*);
};
extern unsigned int DAT_0118c574[6];
struct FUN_00592810_shell
{
    void FUN_00592810();
};
// @fnv 0x00592810
void FUN_00592810_shell::FUN_00592810()
{
    int i;
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    for (i = 0; i < 6; ++i)
        reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_obj*)((char*)this + 0x38 + i * 0xc))))->FUN_0048e370(DAT_0118c574[i]);
    if (*(void**)((char*)this + 0x80))
        ((FUN_00593320_shell*)*(void**)((char*)this + 0x80))->FUN_00593320((void*)0x54444f44);
    ::FUN_00485950((void *)(0x4d414e44), *(unsigned short*)((char*)this + 0x84));
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct FUN_005e79a0_t : public TESForm
{
};

struct FUN_005932e0_shell
{
    bool Compare(void*);
};

struct FUN_005926f0_entry
{
    virtual void FUN_0() = 0;
    virtual void FUN_1() = 0;
    virtual void FUN_2() = 0;
    virtual bool Compare(void*) = 0;
};

struct FUN_005926f0_texture
{
    char _pad[0x80];
    FUN_005932e0_shell* _compareObject;
    unsigned short _flags;
};

struct FUN_005926f0_shell
{
    char _pad[0x80];
    FUN_005932e0_shell* _compareObject;
    unsigned short _flags;

    bool CompareTextureSet(TESForm* apCompare);
};

// @fnv 0x005926f0
bool FUN_005926f0_shell::CompareTextureSet(TESForm* apCompare)
{
    BGSTextureSet* pcompare = dynamic_cast<BGSTextureSet*>(apCompare);
    int i;

    if (!pcompare)
        return true;

    for (i = 0; i < 6; ++i)
    {
        if (reinterpret_cast<FUN_005926f0_entry*>(reinterpret_cast<char*>(this) + 0x38 + i * 0xc)
                ->Compare(reinterpret_cast<void*>(reinterpret_cast<char*>(&pcompare->pTextures) + i * 0xc)))
            return true;
    }

    if (reinterpret_cast<FUN_005926f0_texture*>(pcompare)->_compareObject)
    {
        if (!_compareObject)
            return true;

        if (_compareObject->Compare(reinterpret_cast<FUN_005926f0_texture*>(pcompare)->_compareObject))
            return true;
    }
    else if (_compareObject)
    {
        return true;
    }

    if (_flags != reinterpret_cast<FUN_005926f0_texture*>(pcompare)->_flags)
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(pcompare))
        return true;

    return false;
}

struct DecalDataOwned : public DecalData
{
    ~DecalDataOwned();
};

struct BoundObjectCopier
{
};

struct BGSTextureSetCopy : public BGSTextureSet
{
    void CopyFromTextureSet(TESForm* apForm);
};

struct DecalDataCopier
{
};

// Copies the six texture entries, the decal data and the flags from another BGSTextureSet, then copies the bound object.
// @fnv 0x00592560
void BGSTextureSetCopy::CopyFromTextureSet(TESForm* apForm)
{
    BGSTextureSet* pSourceTextureSet = dynamic_cast<BGSTextureSet*>(apForm);
    if (!pSourceTextureSet)
        return;
    for (int i = 0; i < 6; i++)
        ((BaseFormComponent*)&pTextures[i])->CopyFromBase(&pSourceTextureSet->pTextures[i]);
    if (pSourceTextureSet->m_pDecalData)
    {
        if (!m_pDecalData)
            m_pDecalData = new DecalData;
        reinterpret_cast<::DecalData *>((((DecalDataCopier*)m_pDecalData)))->Copy(pSourceTextureSet->m_pDecalData);
    }
    else if (m_pDecalData)
    {
        delete (DecalDataOwned*)m_pDecalData;
        m_pDecalData = 0;
    }
    iFlags = pSourceTextureSet->iFlags;
    reinterpret_cast<::FormCloneOperation *>((((BoundObjectCopier*)this)))->FUN_004851b0(pSourceTextureSet);
}

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* object = 0);
    ~NiPointer();
    NiPointer<T>& operator=(const NiPointer<T>& other);
};
class NiTexture
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class BSShaderManager
{
  public:
    static void GetTexture(const char* apPath, bool abFlag, NiPointer<NiTexture>& arspTexture, bool abFlag2,
                           bool abFlag3);
};

struct TexSetIface
{
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
    virtual const char* GetTextureFilePath(int aeTextureType);
    virtual void GetTextureByType(int aeTextureType, NiPointer<NiTexture>& arspTexture);
};
struct FormBase9
{
    virtual void f00();
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
};
struct TexSetB : FormBase9, TexSetIface
{
    virtual void GetTextureByType(int aeTextureType, NiPointer<NiTexture>& arspTexture);
};
// Looks up the texture filename for aeTextureType, builds a Data\Textures\ path, loads the texture via BSShaderManager::GetTexture and stores it in arspTexture.
// @fnv 0x00592f30
void TexSetB::GetTextureByType(int aeTextureType, NiPointer<NiTexture>& arspTexture)
{
    const char* pFilename;
    {
        NiPointer<NiTexture> spTexture = 0;
        char acPath[0x104];
        pFilename = GetTextureFilePath(aeTextureType);
        if (pFilename && *pFilename)
        {
            ::TaskQueueInterface::CopyStringToBuffer(acPath, 0x104, "Data\\Textures\\");
            strcat_s(acPath, 0x104, pFilename);
            BSShaderManager::GetTexture(acPath, true, spTexture, true, false);
        }
        arspTexture = spTexture;
    }
}

namespace s593030 {

struct ValueList
{
    int unk00;
    int unk04;
    int unk08;

};

struct Owner
{
    int unk00;
    int unk04;
    ValueList m_kList0;
    ValueList m_kList1;
    ValueList m_kList5;
    ValueList m_kList2;
    ValueList m_kList3;
    ValueList m_kList4;

    void FUN_00593030(unsigned int uiType, int iValue);
};

// Dispatches iValue to the ValueList member selected by uiType, calling FUN_00489100 on the matching list.
// @fnv 0x00593030
void Owner::FUN_00593030(unsigned int uiType, int iValue)
{
    switch (uiType)
    {
    case 0:
        reinterpret_cast<::TESFullName *>(&(m_kList0))->SetFullName((const char *)(iValue));
        break;
    case 1:
        reinterpret_cast<::TESFullName *>(&(m_kList1))->SetFullName((const char *)(iValue));
        break;
    case 2:
        reinterpret_cast<::TESFullName *>(&(m_kList2))->SetFullName((const char *)(iValue));
        break;
    case 3:
        reinterpret_cast<::TESFullName *>(&(m_kList3))->SetFullName((const char *)(iValue));
        break;
    case 4:
        reinterpret_cast<::TESFullName *>(&(m_kList4))->SetFullName((const char *)(iValue));
        break;
    case 5:
        reinterpret_cast<::TESFullName *>(&(m_kList5))->SetFullName((const char *)(iValue));
        break;
    }
}

}

struct Holder_iso
{
    void FUN_005923c0_iso();
    void* FUN_00592380(unsigned int flags);
public:
    void FUN_00485680();
};

struct S_005923c0_Base0
{
    virtual ~S_005923c0_Base0();
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
};

struct S_005923c0_Sec
{
    virtual void unk00();
    int unk04;
    ~S_005923c0_Sec();
};

struct S_005923c0_Elem
{
    int unk00;
    int unk04;
    int unk08;
    ~S_005923c0_Elem();
};

struct FUN_005923c0_iso : S_005923c0_Base0, S_005923c0_Sec
{
    S_005923c0_Elem m_38[6];
    virtual ~FUN_005923c0_iso();
    virtual void ClearData();
};

// @fnv 0x005923c0
FUN_005923c0_iso::~FUN_005923c0_iso()
{
    ClearData();
}

struct Holder_o2
{
    void* FUN_00592380(unsigned int flags);
};

struct FUN_00b66c40_t
{
    char pad00[0x20];
    unsigned int uiFlags;
    unsigned int uiFlags2;
    char pad28[0xc];
    float fTime;
    float FUN_00b66c40();
};

// @fnv 0x00b66c40
float FUN_00b66c40_t::FUN_00b66c40()
{
    bool bFadeInActive = (uiFlags & 0x80) > 0 && !((uiFlags2 & 0x800000) > 0) && DAT_011f9460 > 0.0f;
    bool bFadeOut = (uiFlags & 0x20000) > 0 && !((uiFlags2 & 0x800000) > 0) && DAT_011f9468 > 0.0f;
    float fResult = 1.0f;
    if (bFadeOut)
    {
        if (fTime < DAT_011f9464)
            fResult = 1.0f;
        else if (fTime >= DAT_011f9468)
            fResult = 0.0f;
        else
        {
            fResult = (fTime - DAT_011f9464) / (DAT_011f9468 - DAT_011f9464);
            fResult = 1.0f - (1.0f < fResult ? 1.0f : fResult);
        }
    }
    else if (bFadeInActive)
    {
        if (fTime < DAT_011f945c)
            fResult = 1.0f;
        else if (fTime >= DAT_011f9460)
            fResult = 0.0f;
        else
        {
            fResult = (fTime - DAT_011f945c) / (DAT_011f9460 - DAT_011f945c);
            fResult = 1.0f - FUN_0040ebd0(1.0f, fResult);
        }
    }
    return fResult;
}

struct NiRenderer
{
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
    virtual void v56(void*, int, int);
    static NiRenderer* ms_pRenderer;
};

struct FUN_00b66db0_Object
{
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
    virtual unsigned short v58();
    virtual void v59();
    virtual void v60();
    virtual void* v61(int, int);
    void FUN_00b66db0();
};

// @fnv 0x00b66db0
void FUN_00b66db0_Object::FUN_00b66db0()
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < v58(); ++j)
        {
            void* pkItem = v61(i, j);
            if (pkItem)
                pkRenderer->v56(pkItem, 0, 0);
        }
    }
}

class FUN_00b66b80_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned char m_20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned int m_24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    float m_34;

    float FUN_00b66b80();
};

// @fnv 0x00b66b80
float FUN_00b66b80_cls::FUN_00b66b80()
{
    bool ok = (m_20 & 1u) > 0 && !((m_24 & 0x800000u) > 0) && DAT_011f9458 > 0.0f;
    float result = 1.0f;
    if (ok)
    {
        if (m_34 < DAT_011f9454)
            result = 1.0f;
        else if (m_34 >= DAT_011f9458)
            result = 0.0f;
        else
        {
            float t = (m_34 - DAT_011f9454) / (DAT_011f9458 - DAT_011f9454);
            result = 1.0f - (1.0f < t ? 1.0f : t);
        }
    }
    return result;
}

// FUN_00593230 : sub ecx,0x30 ; jmp FUN_00592380
// MSVC this-adjusting (adjustor) thunk. A derived class inherits a secondary
// base at offset 0x30 inside the primary base; the vftable slot inherited from
// the secondary base still refers to the implementation living in the primary
// base, so the compiler emits a thunk that walks `this` back by the primary
// base's size (0x30) and tail-jumps to that implementation.
struct ThunkPrimaryBase
{
    virtual void* FUN_00593230(unsigned int flags);
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
};

struct ThunkSecondaryBase
{
    virtual void* FUN_00593230(unsigned int flags);
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x00593230
    virtual void* FUN_00593230(unsigned int flags);
};

ThunkDerived::ThunkDerived()
{}

struct FnvRefObj
{
    virtual void Init();
    virtual void Free();
    volatile LONG refs;  // +0x04
};

struct FnvTarget
{
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
    virtual void v35(int a);
    virtual void v36(int idx, FnvRefObj** slot);
};

struct FUN_00b66ad0_cls
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    FnvTarget* m_a4;  // +0xa4
    int unkA8;
    FnvRefObj** m_ac[6];  // +0xac

    void FUN_00b66ad0(std::intptr_t a1, FnvTarget* target);
};

// @fnv 0x00b66ad0
void FUN_00b66ad0_cls::FUN_00b66ad0(std::intptr_t a1, FnvTarget* target)
{
    if (target == 0)
    {
        target = m_a4;
    }
    FnvTarget* t = target;
    FnvRefObj*** base = m_ac;
    FnvRefObj*** cur = base;
    for (int i = 0; i < 6; ++i)
    {
        FnvRefObj** slot = *cur;
        FnvRefObj* obj = *slot;
        if (obj != 0)
        {
            if (InterlockedDecrement(&obj->refs) == 0)
            {
                obj->Free();
            }
            *slot = 0;
        }
        ++cur;
    }
    if (base != 0 && t != 0)
    {
        int j = 0;
        FnvRefObj*** p = base;
        for (; j < 6; ++j, ++p)
        {
            t->v36(j, *p);
        }
        if (*base[0] != 0)
        {
            t->v35(0);
        }
    }
}

#include "generated/data/fallout_shared/bgstextureset.inc"
#include "generated/data/fallout_shared/bgstextureset_o2_variant.inc"
