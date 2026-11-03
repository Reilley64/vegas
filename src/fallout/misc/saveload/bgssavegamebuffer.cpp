
// src/fallout/misc/saveload/bgssavegamebuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgssavegamebuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include <cstring>
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00853570_shell.h"
#include "fnv/decl/FUN_008660b0_shell.h"
#include "fnv/decl/FUN_00866140_cls.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_0084e000.h"
#include "fnv/symbols_011de000.h"
struct BGSSaveFormBuffer
{
    void SerializeFormData(void* apForm, int aFlags);
};

struct FUN_0043aa40_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_0043aa40(BGSSaveFormBuffer* apBuffer);
};

struct FUN_00424940_shell
{
    unsigned char FUN_00424940(void);
};

struct BGSSaveLoadManager
{
    unsigned char FUN_00424940(void);
};


struct FUN_00846330_shell
{
public:
    unsigned int WriteToFile(const void *, unsigned int);
};

struct FUN_00865c80_shell
{
    int m_auiShapeKeys;
    int m_ptr;
    void FUN_00865c80(FUN_00846330_shell* a1, int a2);
};

// @fnv 0x00865c80
void FUN_00865c80_shell::FUN_00865c80(FUN_00846330_shell* a1, int a2)
{
    if (DAT_011de134->FUN_00424940())
    {
        if (a2)
        {
            a1->WriteToFile((const void *)(0), a2);
        }
    }
    else
    {
        if (m_ptr && a2)
        {
            a1->WriteToFile((const void *)(m_ptr), a2);
        }
    }
}

struct BGSSaveGameBuffer
{
    void FUN_00865f60(unsigned int aiVariableValue);
    void WriteAtOffset(void* data, unsigned int size, unsigned int offset);
};


// @fnv 0x00865f60
void BGSSaveGameBuffer::FUN_00865f60(unsigned int aiVariableValue)
{
    unsigned char cvalue3;
    unsigned short svalue9;
    unsigned int ivalue;

    if (aiVariableValue < 0x40)
    {
        cvalue3 = (unsigned char)(aiVariableValue << 2);
        WriteAtOffset(&cvalue3, 1, 0);
    }
    else if (aiVariableValue < 0x4000)
    {
        svalue9 = (unsigned short)((aiVariableValue << 2) | 1);
        WriteAtOffset(&svalue9, 2, 0);
    }
    else if (aiVariableValue < 0x40000000)
    {
        ivalue = (aiVariableValue << 2) | 2;
        WriteAtOffset(&ivalue, 4, 0);
    }
    else
    {
        ::FUN_00845cc0("SAVELOAD: Variable-sized value %08X is too large to be stored.", aiVariableValue);
    }
}

struct FUN_00835f10_shell
{
    void FUN_00835f10(BGSSaveFormBuffer* apBuffer);
};

struct FUN_009f3850_shell
{
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    void FUN_009f3850(BGSSaveFormBuffer* apBuffer);
};

struct FUN_006e2350_shell
{
    void FUN_006e2350(BGSSaveFormBuffer* apBuffer);
};

struct FUN_006f50b0_shell
{
    int m_00;
    int m_04;
    void FUN_006f50b0(BGSSaveFormBuffer* apBuffer);
};

struct Flt
{
    operator unsigned int();
};

struct BGSSaveGameBufferSaveStringHelper
{
};

struct FUN_0083d690_shell
{
    void FUN_0083d690(BGSSaveFormBuffer* apBuffer);
};

struct FUN_00857bd0
{
    void Init(unsigned int);
};
struct FUN_008579b0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_008579b0(void* a1, unsigned int a2);
};
// Copies a2 bytes from a1 into the buffer at this+0x14, then calls Init with a2.
// @fnv 0x008579b0
void FUN_008579b0_shell::FUN_008579b0(void* apSource, unsigned int uiSize)
{
    __memcpy(*(void**)((char*)this + 0x14), apSource, uiSize);
    ((FUN_00857bd0*)this)->Init(uiSize);
}

struct S00865ce0
{
    void FUN_00865ce0(void* a1, unsigned int a2, unsigned int a3, unsigned char a4);
};
// Writes size bytes from data into the buffer at the given offset, using the buffer's stored base position.
// @fnv 0x00865570
void BGSSaveGameBuffer::WriteAtOffset(void* data, unsigned int size, unsigned int offset)
{
    ((S00865ce0*)this)->FUN_00865ce0(data, size, *(unsigned int*)((char*)this + 12), offset);
}

extern int DAT_01082324;
struct FUN_00865c10_shell
{
    int m_00;
    void* m_04;
    void FUN_00865c10();
};
// Sets m_00 to the address of DAT_01082324, then deallocates the pointer stored in m_04.
// @fnv 0x00865c10
void FUN_00865c10_shell::FUN_00865c10()
{
    m_00 = (int)&DAT_01082324;
    void* p = m_04;
    ::FUN_00401030(p);
}

struct FUN_00865c40_shell : FUN_00865c80_shell
{
    void FUN_00865c40(FUN_00846330_shell*);
};
// @fnv 0x00865c40
void FUN_00865c40_shell::FUN_00865c40(FUN_00846330_shell* a1)
{
    ::ForwardToShell(a1, (int)((char*)this + 0xc), 4);
    this->FUN_00865c80(a1, *(int*)((char*)this + 0xc));
}

struct Dummy84eaf0
{
    int m_auiShapeKeys;
};
struct FUN_00865db0_shell
{
    void FUN_00865db0(unsigned int a, unsigned int b);
};
// @fnv 0x00865db0
void FUN_00865db0_shell::FUN_00865db0(unsigned int a, unsigned int uiUnused)
{
    Dummy84eaf0 p;
    ::ClearNumericIDIndex((::BGSNumericIDIndex3 *)&(p));
    reinterpret_cast<::FUN_00853570_shell *>(&(p))->WriteFormIDBytes(a);
    ((BGSSaveGameBuffer*)this)->WriteAtOffset(&p, 3, 0);
}

namespace fnv_00865df0 {
struct TESForm
{
};
struct Dummy84eaf0
{
};
struct PackedFormID : Dummy84eaf0
{
    unsigned m_iOwnerObjectOffset;
};
struct FUN_00865df0_holder : BGSSaveGameBuffer
{
    void FUN_00865df0(TESForm*, unsigned);
};
// @fnv 0x00865df0
void FUN_00865df0_holder::FUN_00865df0(TESForm* apForm, unsigned aiUnusuedMetaDataArg)
{
    unsigned formID;
    PackedFormID formIDIndex;
    formID = apForm ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apForm))->FUN_0084e3a0())) : 0;
    ::ClearNumericIDIndex((::BGSNumericIDIndex3 *)&(formIDIndex));
    reinterpret_cast<::FUN_00853570_shell *>(&(formIDIndex))->WriteFormIDBytes(formID);
    WriteAtOffset(&formIDIndex, 3, 0);
}
}  // namespace fnv_00865df0

struct FUN_00865e50_shell : BGSSaveGameBuffer
{
    void FUN_00865e50(void* data, unsigned int size, unsigned int offset);
};
// Writes three ranges of this object (offsets 4, 0x10, 0x1c) and the form at m_00 into the save buffer.
// @fnv 0x0043aa40
void FUN_0043aa40_shell::FUN_0043aa40(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((void*)((char*)&this->m_04), 0xc, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((void*)((char*)&this->m_10), 0xc, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((void*)((char*)&this->m_1c), 1, 0);
    apBuffer->SerializeFormData((void*)this->m_00, 0);
}
// Writes the object's pointer to the save buffer, then saves four consecutive one-byte fields at offsets 0x1c through 0x1f.
// @fnv 0x00835f10
void FUN_00835f10_shell::FUN_00835f10(BGSSaveFormBuffer* apBuffer)
{
    apBuffer->SerializeFormData(*(void**)this, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x1c, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x1d, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x1e, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x1f, 1, 0);
}
// @fnv 0x009f3850
void FUN_009f3850_shell::FUN_009f3850(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&m_04, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&m_08, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&m_0c, 4, 0);
    apBuffer->SerializeFormData(m_00, 0);
}
// @fnv 0x006e2350
void FUN_006e2350_shell::FUN_006e2350(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(this, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x2c, 12, 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x38), 0);
    ((void(*)(void*, BGSSaveFormBuffer*))(*(void***)(*(void***)((char*)this + 4))))((char*)this + 4,
                                                                                              apBuffer);
}
// Saves 4 bytes of this object, saves the pointer at offset 0x2c, then calls the virtual save on the sub-object at offset 4.
// @fnv 0x006f50b0
void FUN_006f50b0_shell::FUN_006f50b0(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(this, 4, 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x2c), 0);
    ((void(*)(FUN_006f50b0_shell*, BGSSaveFormBuffer*))(*(void**)(*(void**)((char*)this + 4))))(
        (FUN_006f50b0_shell*)((char*)this + 4), apBuffer);
}
// @fnv 0x00865e50
void FUN_00865e50_shell::FUN_00865e50(void* data, unsigned int size, unsigned int offset)
{
    WriteAtOffset(data, size, 0);
}

struct ThreeByThreeMatrix
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
};
struct NiQuaternion
{
    float x;
    float y;
    float z;
    float w;
    void FromRotationMatrix(ThreeByThreeMatrix const&);
};
struct FUN_00865ee0_shell
{
    void SaveQuaternion(ThreeByThreeMatrix const&, int, int);
};
// Builds a NiQuaternion from aMatrix and writes its 16 bytes into the save buffer.
// @fnv 0x00865ee0
void FUN_00865ee0_shell::SaveQuaternion(ThreeByThreeMatrix const& aMatrix, int aiUnused1, int aiUnused2)
{
    NiQuaternion quat;
    BGSSaveFormBuffer* pkBuffer;
    quat.FromRotationMatrix(aMatrix);
    pkBuffer = (BGSSaveFormBuffer*)this;
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&quat, 16, 0);
}

struct FUN_00865f20_shell
{
    int _00;
    int _04;
    int _08;
    unsigned int m_0c;
    unsigned int FUN_00865f20();
};
// Appends a single '#' character at offset m_0c and returns the previous offset.
// @fnv 0x00865f20
unsigned int FUN_00865f20_shell::FUN_00865f20()
{
    char cvalue;
    unsigned int iposition;
    iposition = m_0c;
    cvalue = 0x23;
    reinterpret_cast<::S00865ce0 *>(this)->FUN_00865ce0(&cvalue, 1, m_0c, 0);
    return iposition;
}

struct FUN_0083fb10_shell
{
    void FUN_0083fb10(BGSSaveFormBuffer* apBuffer);
};

struct FUN_00865e70_shell : BGSSaveGameBuffer
{
    void FUN_00865e70(const char* apString, unsigned int aiUnusedMetaDataArg);
};
// @fnv 0x0083d690
void FUN_0083d690_shell::FUN_0083d690(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00865e70_shell *>((((BGSSaveGameBufferSaveStringHelper*)apBuffer)))->FUN_00865e70((const char*)((Flt*)this)->operator unsigned int(), 0);
    reinterpret_cast<::FUN_00865e70_shell *>((((BGSSaveGameBufferSaveStringHelper*)apBuffer)))->FUN_00865e70((const char*)((Flt*)((char*)this + 0x10))->operator unsigned int(), 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 8, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0xc, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x24, 1, 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x18), 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x1c), 0);
    apBuffer->SerializeFormData(*(void**)((char*)this + 0x20), 0);
}
// @fnv 0x0083fb10
void FUN_0083fb10_shell::FUN_0083fb10(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00865e70_shell *>((((BGSSaveGameBufferSaveStringHelper*)apBuffer)))->FUN_00865e70((const char*)(unsigned int)*(Flt*)this, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 8, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x24, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x25, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 9, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0xa, 1, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)((char*)this + 0x14)), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)((char*)this + 0x28)), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)((char*)this + 0x1c)), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)((char*)this + 0x18)), 0);
}
// Writes a string to the save buffer: computes its length, writes the 2-byte length, then the string bytes if non-empty.
// @fnv 0x00865e70
void FUN_00865e70_shell::FUN_00865e70(const char* apString, unsigned int aiUnusedMetaDataArg)
{
    unsigned short usLength = apString ? std::strlen(apString) : 0;
    unsigned short usSavedLength = usLength;
    WriteAtOffset(&usLength, 2, 0);
    if (usSavedLength)
        WriteAtOffset((void*)apString, usSavedLength, 0);
}

struct FUN_00865ff0_shell : FUN_00865f20_shell
{
    void FUN_00865ff0(unsigned int a1, unsigned int a2);
};

extern const char $SG2649[];

// @fnv 0x00865ff0
void FUN_00865ff0_shell::FUN_00865ff0(unsigned int uiValue, unsigned int a2)
{
    if (uiValue < 0x40)
    {
        char value8 = static_cast<char>(uiValue << 2);
        reinterpret_cast<::S00865ce0 *>((this))->FUN_00865ce0(&value8, 1, a2, 0);
    }
    else if (uiValue < 0x4000)
    {
        reinterpret_cast<::FUN_00866140_cls *>((this))->FUN_00866140(a2, 1);
        unsigned short value16 = static_cast<unsigned short>((uiValue << 2) | 1);
        reinterpret_cast<::S00865ce0 *>((this))->FUN_00865ce0(reinterpret_cast<char*>(&value16), 2, a2, 0);
    }
    else if (uiValue < 0x40000000)
    {
        reinterpret_cast<::FUN_00866140_cls *>((this))->FUN_00866140(a2, 3);
        unsigned int value32 = (uiValue << 2) | 2;
        reinterpret_cast<::S00865ce0 *>((this))->FUN_00865ce0(reinterpret_cast<char*>(&value32), 4, a2, 0);
    }
    else
    {
        ::FUN_00845cc0($SG2649, uiValue);
    }
}

class FUN_00847dd0_cls
{
  public:
    void FUN_00847dd0();
};

// @fnv 0x00847dd0
void FUN_00847dd0_cls::FUN_00847dd0()
{
    reinterpret_cast<::FUN_00865c10_shell *>((this))->FUN_00865c10();
}

struct FUN_008660b0_Obj
{
};

struct FUN_00865ce0_state
{
    int m_00;
    char* m_04;
    int m_08;
    int m_0c;
    int m_10;
};


// Grows the buffer until it fits a3+a2 (+1 if a4==0), copies a2 bytes from a1 to m_04+a3, appends a 0x7c terminator when a4==0, and updates m_0c/m_10.
// @fnv 0x00865ce0
void S00865ce0::FUN_00865ce0(void* pSource, unsigned int uiLength, unsigned int a3, unsigned char a4)
{
    int iTerminator = (a4 == 0);

    while (a3 + uiLength + iTerminator > reinterpret_cast<FUN_00865ce0_state*>(this)->m_08)
    {
        reinterpret_cast<::FUN_008660b0_shell *>((reinterpret_cast<FUN_008660b0_Obj*>(this)))->GrowBuffer();
    }

    if (!DAT_011de134->FUN_00424940())
    {
        ::__memcpy(reinterpret_cast<FUN_00865ce0_state*>(this)->m_04 + a3, pSource, uiLength);
    }

    if (a4 == 0)
    {
        if (!DAT_011de134->FUN_00424940())
        {
            reinterpret_cast<FUN_00865ce0_state*>(this)->m_04[a3 + uiLength] = 0x7c;
        }

        if (a3 == reinterpret_cast<FUN_00865ce0_state*>(this)->m_0c)
        {
            reinterpret_cast<FUN_00865ce0_state*>(this)->m_10 += 1;
        }
    }

    if (a3 + uiLength + iTerminator > reinterpret_cast<FUN_00865ce0_state*>(this)->m_0c)
    {
        reinterpret_cast<FUN_00865ce0_state*>(this)->m_0c = a3 + uiLength + iTerminator;
    }
}

// Interface dispatch: when owned by a menu item, refresh it directly; otherwise refresh the item its owner reports.

class F54C0Item;

class F54C0Interface
{
  public:
    virtual void Unk00();
    virtual F54C0Item* GetItem();
    virtual void Unk08();
    virtual bool IsItem();

    void RefreshItem();
};

class F54C0ItemBase
{
  public:
    virtual ~F54C0ItemBase();
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
};

class F54C0Item : public F54C0ItemBase, public F54C0Interface
{
  public:
};

class F54C0OwnerBase
{
  public:
    virtual ~F54C0OwnerBase();
    int unk04;
    int unk08;
};

class F54C0Owner : public F54C0OwnerBase, public F54C0Interface
{
};

// If this is an item, refreshes it directly; otherwise gets the owner's item and refreshes that.
// @fnv 0x008254c0
void F54C0Interface::RefreshItem()
{
    F54C0Owner* pkOwner;
    F54C0Item* pkItem;

    if (IsItem())
    {
        pkItem = static_cast<F54C0Item*>(this);
        reinterpret_cast<::FUN_0084e3a0_Class *>((pkItem))->FUN_0084e3a0();
    }
    else
    {
        pkOwner = static_cast<F54C0Owner*>(this);
        reinterpret_cast<::FUN_0084e3a0_Class *>((pkOwner->GetItem()))->FUN_0084e3a0();
    }
}
