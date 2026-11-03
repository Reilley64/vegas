
// src/fallout_shared/pathfinding/pathingrequestcoveredmove.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestcoveredmove.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/BGSSaveGameBuffer.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_005076c0Class.h"
#include "fnv/decl/FUN_00613fb0_C.h"
#include "fnv/decl/FUN_006d2c00_shell.h"
#include "fnv/decl/FUN_006d30b0_Class2.h"
#include "fnv/decl/FUN_006e3230_shell.h"
#include "fnv/decl/FUN_006e4320_Class.h"
#include "fnv/decl/FUN_006e5ee0_Class.h"
#include "fnv/decl/FUN_00705b10_Dummy.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0069cea0__FUN_0069cea0_class.h"
#include "fnv/decl/fnv_006dae90__FUN_006dae90_shell.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0101e000.h"
struct FUN_006e4f90_shell
{
    void* FUN_006e4f90();
};

// @fnv 0x006e4f90
void* FUN_006e4f90_shell::FUN_006e4f90()
{
    return reinterpret_cast<char*>(this) + 0xE4;
}

struct FUN_006e4fb0_shell
{
    void* GetOffsetF4();
};

// @fnv 0x006e4fb0
void* FUN_006e4fb0_shell::GetOffsetF4()
{
    return reinterpret_cast<char*>(this) + 0xF4;
}

struct FUN_006e4d00_shell
{
    void CallMemberFunction();
};

struct FUN_006dae90_shell
{
};

// @fnv 0x006e4d00
void FUN_006e4d00_shell::CallMemberFunction()
{
    reinterpret_cast<::fnv_006dae90::FUN_006dae90_shell *>((((FUN_006dae90_shell*)((char*)this + 0x20))))->FUN_006dae90();
}

struct FUN_006e4ef0_shell
{
    void FUN_006e4ef0(float value);
};

// @fnv 0x006e4ef0
void FUN_006e4ef0_shell::FUN_006e4ef0(float value)
{
    *(float*)((char*)this + 0xb8) = value;
}

struct FUN_006e4bf0_shell
{
    void FUN_006e4bf0();
};


struct FUN_006e4bb0_shell
{
    void* FUN_006e4bb0(unsigned int flags);
};

void __cdecl Deallocate(void* p)
{
    ::FUN_00401030(p);
}

struct FUN_006e4cd0_shell
{
    void* FUN_006e4cd0(unsigned int flags);
};

// Calls CallMemberFunction on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006e4cd0
void* FUN_006e4cd0_shell::FUN_006e4cd0(unsigned int flags)
{
    ((FUN_006e4d00_shell*)this)->CallMemberFunction();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    static const ::NiPoint3 ZERO;
};
struct FUN_006e4f50_shell
{
    void FUN_006e4f50();
};
// Sets the NiPoint3 at offset 0xd4 to NiPoint3_ZERO and clears the byte at offset 0xe0.
// @fnv 0x006e4f50
void FUN_006e4f50_shell::FUN_006e4f50()
{
    *(NiPoint3*)((char*)this + 0xd4) = ::NiPoint3::ZERO;
    *(char*)((char*)this + 0xe0) = 0;
}

struct Owner;

struct BaseObject
{
    virtual void Virt0();
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
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    BaseObject(Owner* apOwner);
    ~BaseObject();
};

struct MemberA
{
    int unk00;
    int unk04;
    int unk08;
    MemberA();
};

struct MemberB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemberB();
};

struct MemberC
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemberC();
    ~MemberC();
};

struct MemberD
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemberD();
    ~MemberD();
};

struct BaseObject_d006e2620 : BaseObject
{
    BaseObject_d006e2620(Owner* o) : BaseObject(o)
    {}
    ~BaseObject_d006e2620();
};
struct FUN_006e4d20 : BaseObject_d006e2620
{
    MemberA m_kA;
    MemberB m_kB;
    MemberC m_kC;
    MemberD m_kCubicCoefficient;
    FUN_006e4d20(Owner* apOwner);
};

struct Owner
{
};

struct E4BF0OwnedA
{
    ~E4BF0OwnedA();

    int unk00;
};

struct E4BF0OwnedB
{
    ~E4BF0OwnedB();

    int unk00;
};

struct E4BF0MemberA
{
    ~E4BF0MemberA();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct E4BF0MemberB
{
    ~E4BF0MemberB();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class E4BF0Base
{
  public:
    virtual ~E4BF0Base();

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
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
};

class FUN_006e4bf0 : public E4BF0Base
{
  public:
    virtual ~FUN_006e4bf0();

    E4BF0MemberA m_kMemberA;
    E4BF0MemberB m_kMemberB;
    E4BF0OwnedA* m_pkOwnedA;
    E4BF0OwnedB* m_pkOwnedB;
};
// Calls FUN_006e4bf0 on this, frees this with size 0x10c when flags has bit 0 set, and returns this.
// @fnv 0x006e4bb0
void* FUN_006e4bb0_shell::FUN_006e4bb0(unsigned int flags)
{
    reinterpret_cast<::FUN_006e4bf0 *>((reinterpret_cast<FUN_006e4bf0_shell*>(this)))->::FUN_006e4bf0::~FUN_006e4bf0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10c);
    return this;
}

// Destructor that deletes the two owned objects m_pkOwnedA and m_pkOwnedB.
// @fnv 0x006e4bf0
FUN_006e4bf0::~FUN_006e4bf0()
{
    delete m_pkOwnedA;
    delete m_pkOwnedB;
}

struct FUN_006e4dd0_cls
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
    int unkA4;
    int unkA8;
    int unkAC;
    float m_b0;
    float m_b4;
    float m_b8;
    float m_bc;
    float m_c0;
    int m_c4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    unsigned char m_e0;
    unsigned char m_e1;
    unsigned char unkE2;
    unsigned char unkE3;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;

    void CopyTo(void* pTarget);
};
// Constructs the object with its owner and registers it by calling the owner's CopyTo.
// Constructs a cubic coefficient object by delegating to BaseObject_d006e2620 and then copying data from apOwner via CopyTo.
// @fnv 0x006e4d20
FUN_006e4d20::FUN_006e4d20(Owner* apOwner) : BaseObject_d006e2620(apOwner)
{
    reinterpret_cast<::FUN_006e4dd0_cls *>((apOwner))->CopyTo(this);
}

struct FUN_006e2750_cls
{
};
struct FUN_00507610_cls
{
};
struct FUN_006e5ee0_cls
{
};
struct FUN_006e4320_cls
{
};
struct FUN_005076c0_cls
{
};
struct FUN_00705b10_cls
{
};
struct FUN_006d30b0_cls
{
};
struct FUN_006e4f10_cls
{
};
struct FUN_00613fb0_cls
{
};
struct FUN_006e5330_cls
{
    void FUN_006e5330(void* p);
};
struct FUN_0069cfe0_Dst;
struct FUN_0069cfe0_cls
{
public:
    void CopyElementsTo(::FUN_0069cfe0_Dst *);
};

struct FUN_006e4f10_class
{
    char pad[0xd4];
    NiPoint3 m_afExtents;
    bool m_flag;

    void FUN_006e4f10(const NiPoint3& pt);
};
// Copies this object's float, int and byte members and the unkC8/unkD4/unkE4/unkF4 sub-objects into pTarget via its setter methods.
// @fnv 0x006e4dd0
void FUN_006e4dd0_cls::CopyTo(void* arg)
{
    void* pTarget = arg;
    reinterpret_cast<::PathingRequest *>((((FUN_006e2750_cls*)this)))->CopyTo((::PathingRequest *)(pTarget));

    reinterpret_cast<::FUN_00507610_Class *>((((FUN_00507610_cls*)pTarget)))->FUN_00507610(m_b0);
    reinterpret_cast<::FUN_006e5ee0_Class *>((((FUN_006e5ee0_cls*)pTarget)))->FUN_006e5ee0(m_b4);
    ((FUN_006e4ef0_shell*)pTarget)->FUN_006e4ef0(m_b8);
    reinterpret_cast<::FUN_006e4320_Class *>((((FUN_006e4320_cls*)pTarget)))->FUN_006e4320(m_bc);
    reinterpret_cast<::FUN_005076c0Class *>((((FUN_005076c0_cls*)pTarget)))->FUN_005076c0(m_c0);
    reinterpret_cast<::FUN_00705b10_Dummy *>((((FUN_00705b10_cls*)pTarget)))->Set(m_c4);
    reinterpret_cast<::FUN_006d30b0_Class2 *>((((FUN_006d30b0_cls*)pTarget)))->FUN_006d30b0((*(const ::NiPoint3 *)(&unkC8)));

    if (m_e0)
    {
        reinterpret_cast<::FUN_006e4f10_class *>((((FUN_006e4f10_cls*)pTarget)))->FUN_006e4f10((*(const ::NiPoint3 *)(&unkD4)));
    }
    else
    {
        ((FUN_006e4f50_shell*)pTarget)->FUN_006e4f50();
    }

    reinterpret_cast<::FUN_00613fb0_C *>((((FUN_00613fb0_cls*)pTarget)))->Set(m_e1);
    ((FUN_006e5330_cls*)&unkE4)->FUN_006e5330(((FUN_006e4f90_shell*)pTarget)->FUN_006e4f90());
    ((FUN_0069cfe0_cls*)&unkF4)->CopyElementsTo((::FUN_0069cfe0_Dst *)(void *)(((FUN_006e4fb0_shell*)pTarget)->GetOffsetF4()));
}

// Stores pt into the NiPoint3 member and sets m_flag to true.
// @fnv 0x006e4f10
void FUN_006e4f10_class::FUN_006e4f10(const NiPoint3& aPoint)
{
    m_afExtents = aPoint;
    m_flag = true;
}

struct FNVInputStream
{
};
struct FNVElements4
{
};
struct FNVElements12
{
    void* FUN_006a7af0(unsigned int index);
};
struct FUN_006e51a0_shell
{
    void LoadFromStream(FNVInputStream* stream);
};
// @fnv 0x006e51a0
void FUN_006e51a0_shell::LoadFromStream(FNVInputStream* stream)
{
    reinterpret_cast<::PathingRequest *>(this)->LoadGame((::BGSLoadFormBuffer *)(stream));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xb0), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xb4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xb8), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xbc), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xc0), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xc4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xc8), 12);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xd4), 12);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<char*>(this) + 0xe0), 1);

    unsigned int count4 = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((stream))->FUN_00864a60()));
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((reinterpret_cast<FNVElements4*>(reinterpret_cast<char*>(this) + 0xe4)))->FUN_006f2290(count4, 1);
    for (unsigned int i = 0; i < count4; ++i)
    {
        void* item = ((void *)(reinterpret_cast<::S3e60 *>((reinterpret_cast<FNVElements4*>(reinterpret_cast<char*>(this) + 0xe4)))->FUN_006a7ad0(i)));
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(item), 4);
    }
    {
        unsigned int count12 = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((stream))->FUN_00864a60()));
        reinterpret_cast<::fnv_0069cea0::FUN_0069cea0_class *>((reinterpret_cast<FNVElements12*>(reinterpret_cast<char*>(this) + 0xf4)))->FUN_0069cea0(count12, 1);
        for (unsigned int uiIndex12 = 0; uiIndex12 < count12; ++uiIndex12)
        {
            void* item =
                reinterpret_cast<FNVElements12*>(reinterpret_cast<char*>(this) + 0xf4)->FUN_006a7af0(uiIndex12);
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((stream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(item), 12);
        }
    }
}

extern char DAT_0106d32c;

struct BaseEmpty
{
    virtual void Virt0();
    BaseEmpty();
    ~BaseEmpty();
};

struct SubA34
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
};

struct SubB0
{
    SubB0();
    ~SubB0();
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
};

struct FUN_006e5510_cls : public BaseEmpty
{
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
    SubA34 m_a34;
    SubB0 m_b0;
    float m_fd8;
    FUN_006e5510_cls();
};

// Sets m_fd8 to DAT_0101e704 and calls m_a34.Init().
// @fnv 0x006e5510
FUN_006e5510_cls::FUN_006e5510_cls()
{
    m_fd8 = DAT_0101e704;
    reinterpret_cast<::FUN_006d2c00_shell *>(&(m_a34))->FUN_006d2c00();
}

struct SaveBuffer6e4
{
};
struct Elements4Ex : FNVElements4
{
    int m_kNextStreamField[4];
};
struct Elements12Ex : FNVElements12
{
    int m_kNextStreamField[4];
};
struct Base6e3230
{
};

struct Saver6e4 : Base6e3230
{
    char m_acPad[0xb0];
    int m_iB0;
    int m_iB4;
    int m_iB8;
    int m_iBC;
    int m_iC0;
    int m_iC4;
    NiPoint3 m_kC8;
    NiPoint3 m_kD4;
    bool m_bE0;
    Elements4Ex m_kList4;
    Elements12Ex m_kList12;

    void SaveToBuffer(SaveBuffer6e4* pkBuffer);
};

// Serializes the base object, six ints, two NiPoint3s, a bool, and two element lists (counts plus 4- and 12-byte items) into pkBuffer.
// @fnv 0x006e4fd0
void Saver6e4::SaveToBuffer(SaveBuffer6e4* pkBuffer)
{
    reinterpret_cast<::FUN_006e3230_shell *>(this)->FUN_006e3230((::BGSSaveFormBuffer *)(pkBuffer));
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_iB0, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_iB4, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_iB8, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_iBC, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_iC0, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_iC4, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_kC8, 0xc, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_kD4, 0xc, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_bE0, 1, 0);
    {
        unsigned int ItemUpdateArray = &m_kList4 ? ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kList4))->GetName())) : 0;
        reinterpret_cast<::BGSSaveGameBuffer *>((pkBuffer))->FUN_00865f60(ItemUpdateArray);
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            void* pItem = ((void *)(reinterpret_cast<::S3e60 *>(&(m_kList4))->FUN_006a7ad0(i)));
            reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(pItem, 4, 0);
        }
    }
    {
        unsigned int ItemUpdateArray = &m_kList12 ? ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kList12))->GetName())) : 0;
        reinterpret_cast<::BGSSaveGameBuffer *>((pkBuffer))->FUN_00865f60(ItemUpdateArray);
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            void* pItem = m_kList12.FUN_006a7af0(i);
            reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(pItem, 0xc, 0);
        }
    }
}
