// fallout_shared/bgsmovablestatic.cpp: BGSMovableStatic, MovableRecord, MovableStaticFormComparison (11 functions)

#include "fnv/decl/DialogueItem.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/TESModel.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00864000.h"
#include "fnv/symbols_01183000.h"
#include "bgsmovablestatic_decls.h"

// @fnv 0x004fbb50
void BGSMovableStatic::ResetFormData()
{
    m_pSoundEffect = 0;
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESSound;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob36
{
    char b[36];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_004fbf00_shell : public BGSMovableStatic
{
    void FUN_004fbf00(TESSound*);
};

// @fnv 0x004fbf00
void FUN_004fbf00_shell::FUN_004fbf00(TESSound* apSound)
{
    *reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x6c) = apSound;
}

struct TESFullName
{
    int a[3];
    TESFullName();
    ~TESFullName();
};
struct BGSDestructibleObjectForm
{
    int a[2];
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
};
struct TESObjectSTAT
{
    TESObjectSTAT();
    ~TESObjectSTAT();
};
struct SFTX
{
};
extern void* DAT_01024cc8[];
extern void* DAT_01024cec[];
extern void* DAT_01024e70[];
extern void* DAT_01024e84[];

struct FUN_004fba00_obj : public TESFullName, public BGSDestructibleObjectForm, public TESObjectSTAT
{
    FUN_004fba00_obj();
};

// @fnv 0x004fba00
FUN_004fba00_obj::FUN_004fba00_obj()
{
    *(void***)this = DAT_01024e84;
    *(void***)((char*)this + 0xc) = DAT_01024e70;
    *(void***)((char*)this + 0x14) = DAT_01024cec;
    *(void***)((char*)this + 0x44) = DAT_01024cc8;
    FUN_00864490((char*)this + 0x70);
    reinterpret_cast<::FUN_004f15a0_shell *>((((SFTX*)((char*)this + 0x14))))->FUN_004f15a0(0x22);
    ((BGSMovableStatic*)((char*)this + 0x14))->ResetFormData();
}

struct FUN_004fc060_shell
{
    void SetByteFromPtr(const unsigned char* src);
};

// @fnv 0x004fc060
void FUN_004fc060_shell::SetByteFromPtr(const unsigned char* src)
{
    ((unsigned char*)this)[0] = *src;
}

struct Unk004fc130
{
    unsigned char m0;
    bool IsByteDifferent(unsigned char* p);
};
// Compares m0 with the byte pointed to by p and returns true if they differ.
// @fnv 0x004fc130
bool Unk004fc130::IsByteDifferent(unsigned char* pucByte)
{
    if (m0 != *pucByte)
        return true;
    return false;
}

struct Unk004fc170
{
    void FUN_004fbac0();
    void* DestroyIfFlagged(unsigned int);
};
struct Date
{
    ~Date();
};
struct DoorPart30
{
};
struct DoorPart68
{
};
struct DoorPart3c
{
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_00485e00_shell
{
};
struct SoundH
{
};
struct FUN_004fbf20_shell
{
    void Destroy();
};
struct S_004fbac0_P
{
    virtual ~S_004fbac0_P();
    int unk04;
    int unk08;
};
struct S_004fbac0_B
{
    virtual void b0();
    ~S_004fbac0_B();
    int unk04;
};
struct S_004fbac0_C
{
    virtual void c0();
    ~S_004fbac0_C();
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
struct S_004fbac0_E
{
    virtual void e0();
};
struct FUN_004fbac0 : S_004fbac0_P, S_004fbac0_B, S_004fbac0_C, S_004fbac0_E
{
    virtual ~FUN_004fbac0();
};
// Calls FUN_004fbac0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004fc170
void* Unk004fc170::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004fbac0 *>(this)->FUN_004fbac0::~FUN_004fbac0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Empty destructor for the class; performs no work.
// @fnv 0x004fbac0
FUN_004fbac0::~FUN_004fbac0()
{}

extern "C" void* __cdecl _alloca(unsigned int);
class TESFile
{
  public:
    bool GetChunkData(unsigned int*);
public:
    bool NextChunk();
};
struct AlchTexSwap
{
    unsigned int modelPath;
    unsigned int textureCount;
    unsigned int textures;
    unsigned int modelFlags;
    unsigned int modelBounds;
    unsigned int alternateTextures;
    unsigned int i;
    unsigned int modelSize;
    unsigned int modelUnknown;
    unsigned int modelReserved;
    unsigned int modelState;
};
struct AlchDestr
{
};
struct TESFullNameLoader
{
};
struct MovableRecord;
struct StaticRecord
{
    virtual bool LoadRecordChunks(TESFile*);
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void LoadBounds(TESFile*);
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void SetEditorID(const char*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
};
struct RecordName
{
    virtual void nameSlot();
    unsigned int name;
    unsigned int nameLength;
};
struct RecordDestruct
{
    virtual void destructSlot();
    unsigned int destructible;
};
struct MovableRecord : RecordName, RecordDestruct, StaticRecord, AlchTexSwap
{
    unsigned char data;
    virtual bool LoadRecordChunks(TESFile* file);
};
// Reads the record header, then loops over chunks dispatching editor ID, bounds, full name, models, destruction, data and sound chunks, returning true.
// @fnv 0x004fbc70
bool MovableRecord::LoadRecordChunks(TESFile* file)
{
    unsigned char p = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int h;
    char* a;
    void* i;
    unsigned int s;
    unsigned int f;
    while (h = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())
    {
        switch (h)
        {
        case 0x44494445:
            a = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(a), 512);
            SetEditorID(a);
            break;
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(reinterpret_cast<TESFullName*>(this), file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            ::TESModel::LoadModelData((::TESModel *)(::AlchTexSwap *)(this), file);
            break;
        case 0x53444f4d:
            s = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            i = _alloca(s);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(i), s);
            reinterpret_cast<::FUN_0048a7b0_shell *>((this))->LoadTextureSwapList(i, s, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570());
            break;
        case 0x54534544:
        case 0x44545344:
            ::FUN_004781e0((::BGSDestructibleObjectForm *)(::AlchDestr *)(reinterpret_cast<AlchDestr*>(static_cast<RecordDestruct*>(this))), file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &this->data, 1);
            break;
        case 0x4d414e53:
            f = 0;
            file->GetChunkData(&f);
            reinterpret_cast<FUN_004fbf00_shell*>(this)->FUN_004fbf00(reinterpret_cast<TESSound*>(f));
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

namespace fnv_004fbfe0 {
class TESForm;
struct FUN_004fbf00_shell
{
};
struct FUN_004fc060_shell
{
};
extern void* DAT_01189d4c;

void* __cdecl FUN_00ec43fb(int, int, void*, void*, int);

struct TESChallenge
{
};

struct FUN_005e78f0_t
{
};

struct FUN_004fbfe0_shell : public BGSMovableStatic
{
    void FUN_004fbfe0(int);
};

// @fnv 0x004fbfe0
void FUN_004fbfe0_shell::FUN_004fbfe0(int arg)
{
    int result = (int)FUN_00ec43fb(arg, 0, &(*reinterpret_cast<void * *>(&::DAT_01183028)), &DAT_01189d4c, 0);

    if (result == 0)
        return;
    {
        reinterpret_cast<::FUN_004fbf00_shell *>((reinterpret_cast<FUN_004fbf00_shell*>(reinterpret_cast<char*>(this) - 0x14)))->FUN_004fbf00(reinterpret_cast<TESSound*>(((int)(reinterpret_cast<::DialogueItem *>((reinterpret_cast<TESChallenge*>(result)))->SelectDefaultResponseList()))));

        reinterpret_cast<::FUN_004fc060_shell *>((reinterpret_cast<FUN_004fc060_shell*>(this->_pdbpad_5c)))->SetByteFromPtr(reinterpret_cast<const unsigned char*>(reinterpret_cast<BGSMovableStatic*>(result)->data));

        reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<FUN_005e78f0_t*>(this)))->FUN_004851b0(
            result ? reinterpret_cast<TESForm*>(reinterpret_cast<char*>(result) + 0x14) : 0);
    }
}
}  // namespace fnv_004fbfe0

class TESForm
{
  public:
    virtual void unk004();
    virtual void unk008();
    virtual void unk00C();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01C();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02C();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03C();
    virtual void unk040();
    virtual void unk044();
    virtual void unk048();
    virtual void unk04C();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05C();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06C();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07C();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void unk08C();
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09C();
    virtual void unk0A0();
    virtual void unk0A4();
    virtual void unk0A8();
    virtual void unk0AC();
    virtual void unk0B0();
    virtual void unk0B4();
    virtual void unk0B8();
    virtual void unk0BC();
    virtual void unk0C0();
    virtual void unk0C4();
    virtual void unk0C8();
    virtual void unk0CC();
    virtual void unk0D0();
    virtual void unk0D4();
    virtual void unk0D8();
    virtual void unk0DC();
    virtual void unk0E0();
    virtual void unk0E4();
    virtual void unk0E8();
    virtual void unk0EC();
    virtual void unk0F0();
    virtual void unk0F4();
    virtual void unk0F8();
    virtual void unk0FC();
    virtual void unk100();
    virtual void unk104();
    virtual void unk108();
    virtual void unk10C();
    virtual void unk110();
    virtual void unk114();
    virtual void unk118();
    virtual void unk11C();
    virtual void unk120();
    virtual void unk124();
    virtual void unk128();
    virtual void unk12C();
    virtual void unk130();
    virtual const char* GetName();
    TESFile* GetFile(int a);
    void SetInitializationState(bool b);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
public:
    bool GetInitialized() const;
public:
    void ClearData();
};
// @fnv 0x004fbf20
void FUN_004fbf20_shell::Destroy()
{
    unsigned int itempint;
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((DoorPart30*)((char*)this - 0x14))))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((((DoorPart3c*)((char*)this + 0x30))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::FUN_00477f20_shell *>((((DoorPart68*)((char*)this - 8))))->FUN_00477f20();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::TESForm *>((((Date*)((char*)this + 0x5c))))->ClearData();
    reinterpret_cast<::SDSaveForm *>((((FUN_00485e00_shell*)this)))->FUN_00485e20((Date*)((char*)this + 0x5c), 1);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::TESForm *>((((Date*)((char*)this + 0x5c))))->ClearData();
    if (*(void**)((char*)this + 0x58))
    {
        itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*(SoundH**)((char*)this + 0x58))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e53, itempint);
    }
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct MovableStaticComponentComparison
{
};
struct MovableStaticDataComparison
{
};
struct MovableStaticSoundComparison
{
};
struct MovableStaticFormComparison : ::BGSMovableStatic
{
    bool FUN_004fc080(::TESForm* apCompare);
};
// Returns true if apCompare is not a BGSMovableStatic, either comparison helper returns true, or the sound results differ.
// @fnv 0x004fc080
bool MovableStaticFormComparison::FUN_004fc080(::TESForm* apCompare)
{
    ::BGSMovableStatic* pMovableStatic = dynamic_cast< ::BGSMovableStatic*>(apCompare);
    if (!pMovableStatic)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((MovableStaticComponentComparison*)this)))->FUN_00485270(pMovableStatic ? (::TESForm*)((char*)pMovableStatic + 0x14) : 0))
        return true;
    if (reinterpret_cast<::Unk004fc130 *>((((MovableStaticDataComparison*)this->_pdbpad_5c)))->IsByteDifferent((unsigned char*)pMovableStatic->data))
        return true;
    if (((::TESSound *)(reinterpret_cast<::DialogueItem *>((((MovableStaticSoundComparison*)((char*)this - 0x14))))->SelectDefaultResponseList())) !=
        ((::TESSound *)(reinterpret_cast<::DialogueItem *>((((MovableStaticSoundComparison*)pMovableStatic)))->SelectDefaultResponseList())))
        return true;
    return false;
}
