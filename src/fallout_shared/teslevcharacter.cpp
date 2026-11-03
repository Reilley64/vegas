// fallout_shared/teslevcharacter.cpp: TESLevCreature, TESLevItem, TESLevCharacter, Entry (8 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0046dce0_class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0050a850.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Owner487a60.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TmpEndian.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "teslevcharacter_unit.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/symbols_00472000.h"

// @fnv 0x0050ad40
void TESLevCreature::InitItem()
{
    if (GetInitialized())
        return;
    TESLeveledList::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    SetInitializationState(true);
}

// Loads the leveled item's base form data and its leveled list data from the given load buffer.
// @fnv 0x0050b390
void TESLevItem::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    TESLeveledList::LoadGame(buffer);
}

// @fnv 0x0050a930
bool TESLevCharacter::Load(TESFile* file)
{
    unsigned char ucFormType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (ucFormType != 45)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    do
    {
        switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
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
        case 0x4f4c564c:
        case 0x44454f43:
            switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
            {
            case 0x4f4c564c: {
                struct Entry
                {
                    unsigned short level;
                    unsigned short pad;
                    TESForm* form;
                    unsigned short count;
                    unsigned short pad2;
                } levelEntry;
                memset(&levelEntry, 0, 12);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&levelEntry), 12);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::TmpEndian *>((((LeveledObject*)&levelEntry)))->SwapEndian();
                DAT_011c8e64 = ((::LeveledObject *)(reinterpret_cast<::Owner487a60 *>(this)->InsertEntryByPriority(levelEntry.level, levelEntry.count, (int)(levelEntry.form), (int)(0))));
                break;
            }
            case 0x44454f43:
                if (DAT_011c8e64)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(file);
                    DAT_011c8e64->extra = extra;
                    DAT_011c8e64 = 0;
                }
                break;
            }
            break;
        case 0x444c564c: {
            unsigned char chance = 0;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&chance), 0);
            FUN_0042e680(chance);
            break;
        }
        case 0x464c564c:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_ucChanceNone), 0);
            break;
        case 0x474c564c: {
            unsigned int global = 0;
            file->GetChunkData(&global);
            m_pLevelGlobal = (TESGlobal*)global;
            break;
        }
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44534f4d:
        case 0x44444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            void* textureData;
            unsigned int chunkSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            textureData = _alloca(chunkSize);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureData), chunkSize);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(textureData, chunkSize, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570());
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

namespace fnv_0050b3c0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
struct FUN_0050b3c0_shell : public TESLevItem
{
    void FUN_0050b3c0(BGSLoadFormBuffer*);
};

struct TESLeveledList_Revert_Access
{
};

// Reverts the TESForm base and then the leveled list at offset 0x30 using the load game buffer.
// @fnv 0x0050b3c0
void FUN_0050b3c0_shell::FUN_0050b3c0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(reinterpret_cast<unsigned int>(apLoadGameBuffer));
    reinterpret_cast<::TESLeveledList *>((reinterpret_cast<TESLeveledList_Revert_Access*>(static_cast<TESLeveledList *>(this))))->Revert((::BGSLoadFormBuffer *)(apLoadGameBuffer));
}
}  // namespace fnv_0050b3c0

struct FUN_00487650
{
    FUN_00487650();
    ~FUN_00487650();
    virtual void vf();
    int v[6];
};
struct B2_4fe
{
    B2_4fe();
    ~B2_4fe();
    virtual void vf2();
    int w;
};
struct FUN_0050a770 : public TESBoundAnimObject, public FUN_00487650, public B2_4fe
{
    FUN_0050a770();
    ~FUN_0050a770();
};
// @fnv 0x0050a770
FUN_0050a770::FUN_0050a770()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x2d)));
    ClearData();
    SetInitializationState(true);
}

struct FUN_0050a820_shell
{
    void* FUN_0050a820(unsigned int);
};
// Calls FUN_0050a850, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0050a820
void* FUN_0050a820_shell::FUN_0050a820(unsigned int flags)
{
    reinterpret_cast<::FUN_0050a850 *>(this)->FUN_0050a850::~FUN_0050a850();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005e78f0_t
{
    void FUN_0050acb0(TESForm*);
};
// Casts apCopy to TESLevCharacter and, if the cast succeeds, calls FUN_004851b0 with apCopy.
// @fnv 0x0050acb0
void FUN_005e78f0_t::FUN_0050acb0(TESForm* apCopy)
{
    TESLevCharacter* pllcopy = dynamic_cast<TESLevCharacter*>(apCopy);
    if (!pllcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(apCopy);
}

namespace LevCharacterComparison {
class Entry : public TESLevCharacter
{
  public:
    bool FUN_0050acf0(TESForm*);
};

// Returns true if the cast fails or FUN_00485270 returns true for the compared object.
// @fnv 0x0050acf0
bool Entry::FUN_0050acf0(TESForm* other)
{
    TESLevCharacter* compared = dynamic_cast<TESLevCharacter*>(other);
    if (!compared)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(compared))
        return true;
    return false;
}
}

// Adjustor thunk for FUN_0050ade0: sub ecx,0x4c; jmp FUN_0050a820.
// The derived class overrides a virtual that both of its bases declare, so the
// secondary base's vtable slot holds a thunk that moves `this` back by the size
// of the primary base.
// sizeof(PrimaryBase) = vptr (4) + 18 int fields (72) = 0x4c.
struct PrimaryBase
{
    virtual void FUN_0050ade0();
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
};

struct SecondaryBase
{
    virtual void FUN_0050ade0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0050ade0
    virtual void FUN_0050ade0();
};

Derived::Derived()
{}

// FUN_0050b3f0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x4c ; jmp FUN_0050aea0
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is the size of the primary base: a vtable pointer plus
// 18 int members (4 + 72 = 0x4c bytes).  Both bases declare the same virtual
// function; the derived class redeclares it and defines only its constructor,
// which is what makes the compiler emit the vtables and the adjusting thunk.
struct LevCharPrimaryBase
{
    virtual void FUN_0050b3f0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
};

struct LevCharSecondaryBase
{
    virtual void FUN_0050b3f0();
};

struct LevCharDerived : LevCharPrimaryBase, LevCharSecondaryBase
{
    LevCharDerived();
// @fnv 0x0050b3f0
    virtual void FUN_0050b3f0();
};

LevCharDerived::LevCharDerived()
{}

#include "generated/data/fallout_shared/teslevcharacter.inc"
