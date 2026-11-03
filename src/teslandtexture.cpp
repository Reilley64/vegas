// teslandtexture.cpp: TESLandTexture, BGSTextureSet, LTCopy (11 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "teslandtexture_decls.h"

// @fnv 0x00540c50
TESLandTexture::TESLandTexture()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(FORM_ID_LTEX)));
    SetInitializationState(true);
    ResetFormData();
}

// @fnv 0x00540d80
void TESLandTexture::ResetFormData()
{
    m_pTextureSet = 0;
    LandTextureParameters.m_ucParameter1 = 2;
    LandTextureParameters.m_ucParameter2 = 30;
    LandTextureParameters.m_ucParameter3 = 30;
    m_ucTextureTiling = 30;
}

// @fnv 0x005412a0
bool TESLandTexture::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != FORM_ID_LTEX)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    do
    {
        switch (static_cast<int>(((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))))
        {
        case 'DIDE': {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'MANT': {
            unsigned int textureID = 0;
            file->GetChunkData(&textureID);
            m_pTextureSet = reinterpret_cast<BGSTextureSet*>(textureID);
            break;
        }
        case 'MANH':
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&LandTextureParameters), 3);
            break;
        case 'MANS':
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_ucTextureTiling), 1);
            break;
        case 'MANG': {
            unsigned int grassID = 0;
            file->GetChunkData(&grassID);
            if (grassID)
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::BGSCameraPath *>(this)->GetShotList()))))->FUN_00905820((void *)&(const ::TESGrass *const &)(reinterpret_cast<TESGrass*>(grassID)));
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

// Resolves the grass list and texture set form IDs, warns about missing entries, and marks the item initialized.
// @fnv 0x00540fe0
void TESLandTexture::InitItem()
{
    if (GetInitialized())
        return;
    BSSimpleList<TESGrass*>* current = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::BGSCameraPath *>(this)->GetShotList()));
    BSSimpleList<TESGrass*>* previous = 0;
    while (current && !current->IsEmpty())
    {
        struct GrassResolution
        {
            unsigned int formID;
            TESGrass* grass;
        } grassEntry;
        grassEntry.formID = reinterpret_cast<unsigned int>(((::TESGrass *)(new ((void *)(current)) ::Vec3())));
        ::ResolveFormID((unsigned int *)&(grassEntry.formID), GetFile(-1));
        grassEntry.grass = dynamic_cast<TESGrass*>(::FUN_004839c0(grassEntry.formID));
        if (!grassEntry.grass)
        {
            ::FUN_005b5e40();
            if (previous)
            {
                reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330((::InventoryStackRecord *const &)((const ::TESGrass *const &)(reinterpret_cast<TESGrass*>(grassEntry.formID))));
                current = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
            }
            else
            {
                current->RemoveHead();
            }
        }
        else
        {
            current->SetItem(grassEntry.grass);
            previous = current;
            current = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
        }
    }
    if (m_pTextureSet)
    {
        unsigned int textureID = reinterpret_cast<unsigned int>(m_pTextureSet);
        ::ResolveFormID((unsigned int *)&(textureID), GetFile(-1));
        m_pTextureSet = dynamic_cast<BGSTextureSet*>(::FUN_004839c0(textureID));
        if (!m_pTextureSet)
            ::FUN_005b5e40();
        if (m_pTextureSet)
        {
            if (!m_pTextureSet->GetTexturePath(BSShaderProperty::BASE))
                ::FUN_005b5e40();
            if (!m_pTextureSet->GetTexturePath(BSShaderProperty::NORMAL))
                ::FUN_005b5e40();
            m_pTextureSet->SetHasSpecular(false);
        }
    }
    SetInitializationState(true);
}

// Sets or clears bit 0 of textureFlags according to hasSpecular.
// @fnv 0x00541250
void BGSTextureSet::SetHasSpecular(bool hasSpecular)
{
    if (hasSpecular)
        textureFlags &= ~1;
    else
        textureFlags |= 1;
}

struct Dummy
{
    void* FUN_00540ce0(unsigned int);
};
struct List_009e03e0
{
};
struct FUN_00540dc0_shell : TESFile
{
    void FUN_00540dc0();
};
// @fnv 0x00540dc0
void FUN_00540dc0_shell::FUN_00540dc0()
{
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)(void*)((const char *)(reinterpret_cast<::BGSCameraPath *>(this)->GetShotList())))))->RemoveAll();
}

class FUN_00540d10_base
{
  public:
    virtual ~FUN_00540d10_base();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class FUN_00540d10_member
{
  public:
    ~FUN_00540d10_member();
};

class FUN_00540d10_cls : public FUN_00540d10_base
{
  public:
    virtual ~FUN_00540d10_cls();
    FUN_00540d10_member m_20;
};
// @fnv 0x00540ce0
void* Dummy::FUN_00540ce0(unsigned int flags)
{
    reinterpret_cast<::FUN_00540d10_cls *>(this)->FUN_00540d10_cls::~FUN_00540d10_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00540d10
FUN_00540d10_cls::~FUN_00540d10_cls()
{
    reinterpret_cast<::FUN_00540dc0_shell *>(this)->FUN_00540dc0();
}

struct GrassHelper
{
};
struct LTHelper
{
};
struct LTCopy : TESLandTexture
{
    void FUN_00540de0(TESForm* pForm);
};
// Copies land texture data from pForm into this object, clearing and rebuilding the grass list from the source's grass entries.
// @fnv 0x00540de0
void LTCopy::FUN_00540de0(TESForm* pForm)
{
    TESLandTexture* src = dynamic_cast<TESLandTexture*>(pForm);
    if (!src)
        return;
    BSSimpleList<TESGrass*>* node = 0;
    reinterpret_cast<::FileMatchList *>((((GrassHelper*)((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::BGSCameraPath *>(this)->GetShotList())))))->RemoveAll();
    reinterpret_cast<::FormCloneOperation *>((((LTHelper*)this)))->FUN_004851b0(src);
    ::__memcpy(&LandTextureParameters, &src->LandTextureParameters, 3);
    m_ucTextureTiling = src->m_ucTextureTiling;
    m_pTextureSet = ((::BGSTextureSet *)(reinterpret_cast<::FUN_009611e0_shell *>((((LTHelper*)src)))->FUN_009611e0()));
    node = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::BGSCameraPath *>((src))->GetShotList()));
    while (node && !node->IsEmpty())
    {
        TESGrass* g = ((::TESGrass *)(new ((void *)(node)) ::Vec3()));
        reinterpret_cast<::Callees *>(&(m_kGrassList))->FUN_00905820((void *)&(g));
        node = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
}


struct FUN_00541440_cls : public TESLandTexture
{
    void WriteToStream();
};

// @fnv 0x00541440
void FUN_00541440_cls::WriteToStream()
{
    unsigned int formId;
    BSSimpleList<TESGrass*>* node3;
    {
        TESGrass* grass;
        unsigned int grassId;

        reinterpret_cast<::fnv_004855a0::ArrSI *>((this))->FUN_004855a0();
        reinterpret_cast<::TESForm *>((this))->ClearData();
        if (m_pTextureSet != 0)
        {
            formId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pTextureSet))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e54, formId);
        }
        if (((bool)(::FUN_00401500())))
        {
            reinterpret_cast<::TESForm *>((&LandTextureParameters))->ClearData();
        }
        ::AppendChunk(0x4d414e48, &LandTextureParameters, 3);
        if (((bool)(::FUN_00401500())))
        {
            reinterpret_cast<::TESForm *>((&LandTextureParameters))->ClearData();
        }
        ::FUN_004858f0(0x4d414e53, m_ucTextureTiling);
        node3 = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::BGSCameraPath *>(this)->GetShotList()));
        while (node3 != 0 && !node3->IsEmpty())
        {
            grass = ((::TESGrass *)(new ((void *)(node3)) ::Vec3()));
            grassId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((grass))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e47, grassId);
            node3 = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::Callees *>((node3))->FUN_00726070()));
        }
    }
    reinterpret_cast<::Holder *>((this))->FUN_00485680();
}

#include <string.h>
struct TextureGetter
{
};
struct FUN_00540ec0_shell : TESLandTexture
{
    bool IsDifferentFrom(TESForm*);
};
// Returns true if form is not a TESLandTexture or differs in base compare, parameters, tiling, texture set or grass list.
// @fnv 0x00540ec0
bool FUN_00540ec0_shell::IsDifferentFrom(TESForm* apOther)
{
    TESLandTexture* other = dynamic_cast<TESLandTexture*>(apOther);
    if (!other)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(other))
        return true;
    if (memcmp(&LandTextureParameters, &other->LandTextureParameters, 3))
        return true;
    if (m_ucTextureTiling != other->m_ucTextureTiling)
        return true;
    if (m_pTextureSet != ((::BGSTextureSet *)(reinterpret_cast<::FUN_009611e0_shell *>((((TextureGetter*)other)))->FUN_009611e0())))
        return true;
    BSSimpleList<TESGrass*>* pGrassList = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::BGSCameraPath *>(this)->GetShotList()));
    BSSimpleList<TESGrass*>* pOtherGrassList = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::BGSCameraPath *>((other))->GetShotList()));
    while (pGrassList && pOtherGrassList)
    {
        if (((::TESGrass *)(new ((void *)(pGrassList)) ::Vec3())) != ((::TESGrass *)(new ((void *)(pOtherGrassList)) ::Vec3())))
            return true;
        pOtherGrassList = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::Callees *>((pOtherGrassList))->FUN_00726070()));
        pGrassList = ((::BSSimpleList< ::TESGrass *> *)(reinterpret_cast<::Callees *>((pGrassList))->FUN_00726070()));
    }
    if ((!pGrassList && pOtherGrassList) || (!pOtherGrassList && pGrassList))
        return true;
    return false;
}
