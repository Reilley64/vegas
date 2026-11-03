// fallout_shared/tesobjectanio.cpp: TESObjectANIO (6 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "tesobjectanio_decls.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/symbols_00472000.h"
#include "fnv/decl/FUN_00511a10_cls.h"

// @fnv 0x00511a90
void TESObjectANIO::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    static_cast<TESModelTextureSwap *>(this)->InitItem(this);
    if (pObject)
    {
        unsigned int formID = (unsigned int)pObject;
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pObject = dynamic_cast<TESObjectANIO*>(::FUN_004839c0(formID));
    }
    SetInitializationState(true);
}

// @fnv 0x00511b20
bool TESObjectANIO::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x4d)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int chunk;
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            void* textureData = _alloca(size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureData), size);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(textureData, size, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570());
            break;
        }
        case 0x41544144: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            pObject = (TESObjectANIO*)formID;
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct SFTX
{
};
struct B2_4fe
{
    B2_4fe();
    virtual ~B2_4fe();
    unsigned char pad[0x1c];
};

struct FUN_00511950 : public TESForm, public B2_4fe
{
    int pAnim;
    FUN_00511950();
    virtual ~FUN_00511950();
};

// Sets the form type to 0x4d and initializes pAnim to 0.
// @fnv 0x00511950
FUN_00511950::FUN_00511950()
{
    reinterpret_cast<::FUN_004f15a0_shell *>((((SFTX*)this)))->FUN_004f15a0(0x4d);
    pAnim = 0;
}


struct FUN_005119e0_obj
{
    void* Destroy(unsigned int flags);
};

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct S_0048a520
{
};
struct _ref_0084e3a0_t
{
};

struct FUN_00511d10_shell
{
    void FUN_00511d10();
};

// @fnv 0x00511d10
void FUN_00511d10_shell::FUN_00511d10()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)((char*)this + 0x18))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    if (((int*)this)[0x38 / 4])
    {
        unsigned int iid = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((_ref_0084e3a0_t*)(((int*)this)[0x38 / 4]))))->FUN_0084e3a0()));
        ::FUN_00485910(0x41544144, iid);
    }
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

class B511A10Form
{
  public:
    virtual ~B511A10Form();

    unsigned char m_cFormType;
    unsigned int m_iFormFlags;
    unsigned int m_iFormID;
    void* m_pkSourceFile;
    void* m_pkNextSourceFile;
};

class B511A10TextureSwap
{
  public:
    virtual ~B511A10TextureSwap();

    const char* m_pcModel;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
    float m_fBound;
    void* m_pkTextures;
    unsigned int m_uiValue1;
    void* m_pkSwapItem;
    void* m_pkSwapNext;
};

class FUN_00511a10_cls : public B511A10Form, public B511A10TextureSwap
{
  public:
    virtual ~FUN_00511a10_cls();
};
// Calls FUN_00511a10, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x005119e0
void* FUN_005119e0_obj::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00511a10_cls *>(this)->FUN_00511a10_cls::~FUN_00511a10_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00511a10
FUN_00511a10_cls::~FUN_00511a10_cls()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

struct AnimationObjectComparison : TESObjectANIO
{
    bool FUN_00511dc0(TESForm* otherForm);
};

// @fnv 0x00511dc0
bool AnimationObjectComparison::FUN_00511dc0(TESForm* otherForm)
{
    TESObjectANIO* otherAnimation = dynamic_cast<TESObjectANIO*>(otherForm);
    if (!otherAnimation)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(otherAnimation))
        return true;
    if (pObject != otherAnimation->pObject)
        return true;
    return false;
}

struct FUN_005e78f0_t
{
};

struct AnimationCopyEntry : TESObjectANIO
{
    void FUN_00511d70(TESForm* apCopy);
};

// @fnv 0x00511d70
void AnimationCopyEntry::FUN_00511d70(TESForm* apCopy)
{
    TESObjectANIO* panimObj = dynamic_cast<TESObjectANIO*>(apCopy);
    if (panimObj == 0)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
    pObject = panimObj->pObject;
}

// sub ecx,0x18; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x18).
struct PrimaryBase
{
    virtual void FUN_00511e30();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondaryBase
{
    virtual void FUN_00511e30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00511e30
    virtual void FUN_00511e30();
};

Derived::Derived()
{}
