// fallout_shared/tesobjectimod.cpp: TESObjectIMOD (14 functions)

#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_0047a240_shell.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_0048ea80_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047b560__FUN_0047b560_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_0048e9b0__TESValueForm.h"
#include "fnv/decl/fnv_0048e9e0__TESValueForm.h"
#include "fnv/decl/fnv_0048ea10__TESValueForm.h"
#include "fnv/decl/fnv_0048ea40__TESValueForm.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00487000.h"
#include "tesobjectimod_decls.h"
#include "fnv/symbols_00472000.h"

class TESFormInitFlag : public TESObjectIMODVirtuals
{
  public:
};

enum ENUM_FORM_ID
{
    kIMOD = 0x67
};

class TESForm : public TESFormInitFlag
{
  private:
    unsigned char fields[0x14];

  public:
    void SetInitializationState(bool initialized);
public:
    bool GetInitialized() const;
public:
    void ClearData();
public:
    void LoadGame(void *);
};

class TESBoundObject : public TESForm
{
  private:
    unsigned char fields[0x18];

  public:
    TESBoundObject();
    ~TESBoundObject();
};

class TESFullName : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    TESFullName();
    ~TESFullName();
};

class TESModel : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x14];

  public:
    static void LoadModelData(TESModel*, TESFile*);
};

class TESModelTextureSwap : public TESModel
{
  private:
    unsigned char fields[0x08];

  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    void InitItem(TESForm* form);
};

class TESTexture : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    static void ReadTextureData(TESTexture*, TESFile*);
};

class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};

class TESScriptableForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    TESScriptableForm();
    void InitItem(TESForm* form);
};

class TESDescription : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESDescription();
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};

class TESValueForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESValueForm();
    ~TESValueForm();
};

class TESWeightForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    TESWeightForm();
    ~TESWeightForm();
};

class BGSDestructibleObjectForm : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    void InitItem(TESForm* form);
};

class BGSMessageIcon : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x0c];

  public:
    BGSMessageIcon();
    ~BGSMessageIcon();
};

class BGSPickupPutdownSounds : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm* form);
};

class TESObjectIMOD : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESDescription,
                      public TESValueForm,
                      public TESWeightForm,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
  public:
    TESObjectIMOD();
    bool Load(TESFile*);
    void InitItem();
};

// @fnv 0x00519fc0
void TESObjectIMOD::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    TESScriptableForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// Loads a TESObjectIMOD record: reads the header, then dispatches each chunk to its loader until no chunks remain, returning true.
// @fnv 0x0051a030
bool TESObjectIMOD::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunkID;
    while ((chunkID = (int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {  // EDID
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            reinterpret_cast<TESObjectIMODVirtuals*>(this)->SetEditorID(editorID);
            break;
        }
        case 0x444e424f:  // OBND
            reinterpret_cast<TESObjectIMODVirtuals*>(this)->readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:  // FULL
            ::ReadFullName(this, file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x44444f4d:  // MODD
        case 0x54444f4d:  // MODT
        case 0x44534f4d:  // MOSD
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {  // MODS
            struct TextureSwapChunk
            {
                unsigned int size;
                void* data;
            } swaps;
            swaps.size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            swaps.data = _alloca(swaps.size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(swaps.data), swaps.size);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(swaps.data, swaps.size, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570());
            break;
        }
        case 0x4e4f4349:  // ICON
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4f43494d:  // MICO
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this), file);
            break;
        case 0x49524353: {  // SCRI
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::Script *)(reinterpret_cast<Script*>(scriptID)));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x43534544:  // DESC
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 0x54534544:  // DEST
        case 0x44545344:  // DSTD
            ::FUN_004781e0(this, file);
            break;
        case 0x4d414e59: {  // YNAM
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::TESSound *)(reinterpret_cast<TESSound*>(soundID)));
            break;
        }
        case 0x4d414e5a: {  // ZNAM
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            reinterpret_cast<::TESRegionGrassObject *>(this)->AssignLandTexture((::TESLandTexture *)(::TESSound *)(reinterpret_cast<TESSound*>(soundID)));
            break;
        }
        case 0x41544144:  // DATA
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, 0, 0);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x00519cc0
TESObjectIMOD::TESObjectIMOD()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(kIMOD)));
    SetInitializationState(true);
}

struct FUN_0051a5d0_shell
{
    void FUN_0051a5d0(unsigned int, unsigned int);
};

struct TESFormStub
{
};
struct TESValueFormStub
{
};

// @fnv 0x0051a5d0
void FUN_0051a5d0_shell::FUN_0051a5d0(unsigned int arg1, unsigned int arg2)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>((reinterpret_cast<TESFormStub*>(this)))->FUN_00484c50(arg1, arg2);
    reinterpret_cast<::fnv_0048ea10::TESValueForm *>((reinterpret_cast<TESValueFormStub*>(reinterpret_cast<char*>(this) + 0x7c)))->FUN_0048ea10(arg1, arg2);
}

struct BGSLoadFormBuffer;

struct FUN_0051a630_shell : public TESObjectIMOD
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

struct TESFormLoadGame
{
};

struct TESValueFormLoadGame
{
};

// @fnv 0x0051a630
void FUN_0051a630_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::TESForm *>((reinterpret_cast<TESFormLoadGame*>(this)))->LoadGame(buffer);
    reinterpret_cast<::FUN_0048ea80_Class *>((reinterpret_cast<TESValueFormLoadGame*>(static_cast<TESValueForm *>(this))))->FUN_0048ea80(buffer);
}

struct FUN_00519e40_shell : public TESObjectIMOD
{
    void* FUN_00519e40(unsigned int flags);
};

struct FUN_00519e70_stub
{
    void FUN_00519e70();
};

struct FUN_00484bf0
{
};

struct FUN_0048e9b0
{
};

struct FUN_0051a550_shell
{
    unsigned short FUN_0051a550(unsigned int aiFlags);
};

// Returns the sum of the save sizes reported by this object and the object at offset 0x7c, both queried with aiFlags.
// @fnv 0x0051a550
unsigned short FUN_0051a550_shell::FUN_0051a550(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_00484bf0_shell *>((((FUN_00484bf0*)this)))->FUN_00484bf0(aiFlags);
    isize += reinterpret_cast<::fnv_0048e9b0::TESValueForm *>((((FUN_0048e9b0*)((char*)this + 0x7c))))->FUN_0048e9b0(aiFlags);
    return isize;
}

struct FUN_0051b070_shell
{
};

struct FUN_0051a5a0_shell
{
    void FUN_0051a5a0(unsigned int aiFlags);
};

// @fnv 0x0051a5a0
void FUN_0051a5a0_shell::FUN_0051a5a0(unsigned int aiFlags)
{
    reinterpret_cast<::PC7d *>((reinterpret_cast<FUN_0051b070_shell*>(this)))->FUN_00484c20(aiFlags);
    reinterpret_cast<::fnv_0048e9e0::TESValueForm *>((reinterpret_cast<FUN_0051b070_shell*>(reinterpret_cast<char*>(this) + 0x7c)))->FUN_0048e9e0(aiFlags);
}

struct BGSSaveFormBuffer;
struct FUN_00484d60_holder
{
};
struct FUN_0048ea40_holder
{
};
struct FUN_0051a600_shell
{
    void FUN_0051a600(BGSSaveFormBuffer* buffer);
};

// Calls SaveIfChanged on this and FUN_0048ea40 on the sub-object at offset 0x7c, passing the save buffer to both.
// @fnv 0x0051a600
void FUN_0051a600_shell::FUN_0051a600(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FakeForm *>((reinterpret_cast<FUN_00484d60_holder*>(this)))->SaveIfChanged(buffer);
    reinterpret_cast<::fnv_0048ea40::TESValueForm *>((reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x7c)))->FUN_0048ea40((::fnv_0048ea40::BGSSaveFormBuffer *)(buffer));
}

struct S_00477f20
{
};
struct S_00487010
{
};
struct S_0048a520
{
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_00482cb0_shell
{
    void FUN_00482cb0();
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct FUN_0047a240_holder
{
};
struct FUN_0047b560_holder
{
};
struct FUN_0048e370_holder
{
};

struct FUN_0051a420_shell : public TESObjectIMOD
{
    void FUN_0051a420();
};

// @fnv 0x0051a420
void FUN_0051a420_shell::FUN_0051a420()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)static_cast<TESFullName *>(this))))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)static_cast<TESModelTextureSwap *>(this))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_holder*)static_cast<TESIcon *>(this))))->FUN_0048e370(0x4e4f4349);
    reinterpret_cast<::FUN_0047a240_shell *>((((FUN_0047a240_holder*)static_cast<BGSMessageIcon *>(this))))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)static_cast<TESScriptableForm *>(this))->FUN_0048cca0();
    ((FUN_00482cb0_shell*)static_cast<TESDescription *>(this))->FUN_00482cb0();
    reinterpret_cast<::FUN_00477f20_shell *>((((S_00477f20*)static_cast<BGSDestructibleObjectForm *>(this))))->FUN_00477f20();
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>((((FUN_0047b560_holder*)static_cast<BGSPickupPutdownSounds *>(this))))->LogFormIDs();
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct FUN_005e78f0_t
{
};
struct S_0051a4c0
{
    void CopyFrom(TESForm* apCopy);
};
// Casts apCopy to TESObjectIMOD and, if the cast succeeds, forwards it to FUN_004851b0 on this object.
// @fnv 0x0051a4c0
void S_0051a4c0::CopyFrom(TESForm* apCopy)
{
    TESObjectIMOD* pmisc = dynamic_cast<TESObjectIMOD*>(apCopy);
    if (!pmisc)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
}

struct FUN_005e79a0_t
{
};
struct FUN_0051a500_holder
{
    bool FUN_0051a500(TESForm* apCompare);
};
// Casts apCompare to TESObjectIMOD; returns true if the cast fails or if FUN_00485270 reports a match, otherwise false.
// @fnv 0x0051a500
bool FUN_0051a500_holder::FUN_0051a500(TESForm* apCompare)
{
    TESObjectIMOD* pcomp;
    pcomp = dynamic_cast<TESObjectIMOD*>(apCompare);
    if (!pcomp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pcomp))
        return true;
    return false;
}

class FUN_00519e70 : public TESBoundObject,
                     public TESFullName,
                     public TESModelTextureSwap,
                     public TESIcon,
                     public TESScriptableForm,
                     public TESDescription,
                     public TESValueForm,
                     public TESWeightForm,
                     public BGSDestructibleObjectForm,
                     public BGSMessageIcon,
                     public BGSPickupPutdownSounds
{
  public:
    ~FUN_00519e70();
};
// Calls FUN_00519e70 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00519e40
void* FUN_00519e40_shell::FUN_00519e40(unsigned int flags)
{
    reinterpret_cast<::FUN_00519e70 *>((((FUN_00519e70_stub*)this)))->FUN_00519e70::~FUN_00519e70();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00519e70
FUN_00519e70::~FUN_00519e70()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

struct FUN_0051a840 : TESBoundObject,
                      TESFullName,
                      TESModelTextureSwap,
                      TESIcon,
                      TESScriptableForm,
                      TESValueForm,
                      TESWeightForm,
                      BGSDestructibleObjectForm,
                      BGSMessageIcon,
                      BGSPickupPutdownSounds
{
    virtual ~FUN_0051a840();
};
// @fnv 0x0051a840
FUN_0051a840::~FUN_0051a840()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

class TESForm_o2 : public TESFormInitFlag
{
  private:
    unsigned char fields[0x14];

  public:
    void SetInitializationState(bool initialized);
public:
    bool GetInitialized() const;
public:
    void LoadGame(void *);
};

class TESBoundObject_o2 : public TESForm_o2
{
  private:
    unsigned char fields[0x18];

  public:
    TESBoundObject_o2();
    ~TESBoundObject_o2();
};

class TESModelTextureSwap_o2 : public TESModel
{
  private:
    unsigned char fields[0x08];

  public:
    TESModelTextureSwap_o2();
    ~TESModelTextureSwap_o2();
    void InitItem(TESForm_o2* form);
};

class TESScriptableForm_o2 : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    TESScriptableForm_o2();
    void InitItem(TESForm_o2* form);
};

class BGSDestructibleObjectForm_o2 : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x04];

  public:
    BGSDestructibleObjectForm_o2();
    ~BGSDestructibleObjectForm_o2();
    void InitItem(TESForm_o2* form);
};

class BGSPickupPutdownSounds_o2 : public TESObjectIMODComponentVirtuals
{
  private:
    unsigned char fields[0x08];

  public:
    BGSPickupPutdownSounds_o2();
    ~BGSPickupPutdownSounds_o2();
    void InitItem(TESForm_o2* form);
};

class TESObjectIMOD_o2 : public TESBoundObject_o2,
                      public TESFullName,
                      public TESModelTextureSwap_o2,
                      public TESIcon,
                      public TESScriptableForm_o2,
                      public TESDescription,
                      public TESValueForm,
                      public TESWeightForm,
                      public BGSDestructibleObjectForm_o2,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds_o2
{
  public:
    TESObjectIMOD_o2();
    bool Load(TESFile*);
    void InitItem();
};

struct FUN_0051a630_shell_o2 : public TESObjectIMOD_o2
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

struct FUN_00519e40_shell_o2 : public TESObjectIMOD_o2
{
    void* FUN_00519e40(unsigned int flags);
};

struct FUN_00519e70_stub_o2
{
};

struct FUN_0051a420_shell_o2 : public TESObjectIMOD_o2
{
    void FUN_0051a420();
};

struct B1
{
    virtual void FUN_0051a680(unsigned int);
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
    int unk30;
    int unk34;
    int unk38;
};

struct B2
{
    virtual void FUN_0051a680(unsigned int);
};

struct Derived : B1, B2
{
    Derived();
// @fnv 0x0051a680
    virtual void FUN_0051a680(unsigned int);
};

Derived::Derived()
{}
