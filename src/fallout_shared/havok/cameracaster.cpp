
// src/fallout_shared/havok/cameracaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/cameracaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00621c90_Class.h"
#include "fnv/decl/FUN_00622570_Class.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/S6281a0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00621000.h"
#include "fnv/symbols_0104d000.h"
extern int DAT_0104da3c;

struct FUN_00621100_shell
{
    void SetVtable();
};

// @fnv 0x00621100
void __thiscall FUN_00621100_shell::SetVtable()
{
    *(int*)this = (int)&DAT_0104da3c;
}

struct bhkCharacterListener
{
    unsigned int FUN_00621270(unsigned int aiFlags);
};

// @fnv 0x00621270
unsigned int bhkCharacterListener::FUN_00621270(unsigned int aiFlags)
{
    return *(unsigned int*)((char*)this + 4) & aiFlags;
}


struct FUN_00621290_shell
{
    void* InitFloats();
};

// Calls _ref_006815c0, then stores DAT_0104da4c into the floats at offsets 0x10 and 0x14 and returns this.
// @fnv 0x00621290
void* FUN_00621290_shell::InitFloats()
{
    new ((void *)this) ::Vec3();
    *(float*)((char*)this + 0x10) = ::DAT_0104da4c;
    *(float*)((char*)this + 0x14) = ::DAT_0104da4c;
    return this;
}

extern int DAT_0104da3c;
struct FUN_00621060_shell
{
    int* vtbl;
    void __thiscall SetValue();
    FUN_00621060_shell* __thiscall FUN_00621060();
};
// @fnv 0x00621060
FUN_00621060_shell* __thiscall FUN_00621060_shell::FUN_00621060()
{
    vtbl = &DAT_0104da3c;
    SetValue();
    return this;
}

struct BSAudio
{
};
struct TopicObj
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void Func(void* a, int b)
    {}
};
BSAudio* __cdecl _FUN_00c85750();
// If a1 is non-null, gets the object from _FUN_00c85750 and calls its Func with a1 and 8.
// @fnv 0x006210d0
void FUN_006210d0(void* a1)
{
    if (a1 != 0)
    {
        TopicObj* t = (TopicObj*)((void *)(reinterpret_cast<::MagicCaster_shell *>((_FUN_00c85750()))->FUN_0044edb0()));
        t->Func(a1, 8);
    }
}

namespace fnv_00621170 {
struct BSAudio
{
};
BSAudio* __cdecl _FUN_00c85750();
struct Caller
{
    virtual void f0();
    virtual void f1();
    virtual void Foo(void*, int);
};
// @fnv 0x00621170
void FUN_00621170(void* apArg)
{
    if (apArg != 0)
    {
        void* b = ((void *)(reinterpret_cast<::MagicCaster_shell *>((_FUN_00c85750()))->FUN_0044edb0()));
        ((Caller*)b)->Foo(apArg, 0x3a0);
    }
}
}  // namespace fnv_00621170

struct RootContactPoint
{
    char m_kPoint[32];
    void* m_pRootCollidableA;
    unsigned int m_uiShapeKeyA;
    char m_kContactPointB[32];
    void* m_pRootCollidableB;
    unsigned int m_uiShapeKeyB;
    char m_kContactPointC[32];
};
typedef char _sizecheck_hkpRootCdPoint[sizeof(RootContactPoint) == 112 ? 1 : -1];
struct FUN_006212c0_shell : public RootContactPoint
{
    RootContactPoint* FUN_006212c0(void*);
};

struct FUN_006281a0_shell
{
};

// @fnv 0x006212c0
RootContactPoint* FUN_006212c0_shell::FUN_006212c0(void* apSource)
{
    reinterpret_cast<::S6281a0 *>((((FUN_006281a0_shell*)this)))->FUN_006281a0((*(const ::S6281a0 *)(apSource)));
    m_pRootCollidableA = ((RootContactPoint*)apSource)->m_pRootCollidableA;
    m_uiShapeKeyA = ((RootContactPoint*)apSource)->m_uiShapeKeyA;
    for (unsigned int uiIndex = 0; uiIndex < 8; ++uiIndex)
        ((unsigned int*)m_kContactPointB)[uiIndex] =
            ((unsigned int*)((RootContactPoint*)apSource)->m_kContactPointB)[uiIndex];
    m_pRootCollidableB = ((RootContactPoint*)apSource)->m_pRootCollidableB;
    m_uiShapeKeyB = ((RootContactPoint*)apSource)->m_uiShapeKeyB;
    for (unsigned int S2 = 0; S2 < 8; ++S2)
        ((unsigned int*)m_kContactPointC)[S2] = ((unsigned int*)((RootContactPoint*)apSource)->m_kContactPointC)[S2];
    return this;
}

// @fnv 0x00621080
void __thiscall FUN_00621060_shell::SetValue()
{
    *(float*)((char*)this + 4) = ::DAT_0104da48;
}


struct FUN_00621120_shell : public FUN_00621060_shell
{
    void __thiscall FUN_00621120();
};

// @fnv 0x00621120
void __thiscall FUN_00621120_shell::FUN_00621120()
{
    reinterpret_cast<::FUN_00621c90_Class *>((reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10)))->FUN_00626870();
    SetValue();
}

struct Cnt621210
{
};
struct Rcv621210
{
};
struct Hld621210
{
    char _pad[16];
    Cnt621210 _c;
    Rcv621210* FUN_00621210(Rcv621210* p);
};
// Calls FUN_00622570 on p with whether _c._ref_00726070() is greater than zero, then returns p.
// @fnv 0x00621210
Rcv621210* Hld621210::FUN_00621210(Rcv621210* apReceiver)
{
    reinterpret_cast<::FUN_00622570_Class *>((apReceiver))->FUN_00622570(((int)(reinterpret_cast<::Callees *>(&(_c))->FUN_00726070())) > 0);
    return apReceiver;
}

struct DummyFlags
{
};

struct DummyFlagsShell
{
    char _pad[0x410];
    DummyFlags _flags;
    bool FUN_00621240();
};

// @fnv 0x00621240
bool DummyFlagsShell::FUN_00621240()
{
    return ((int)(reinterpret_cast<::bhkCharacterListener *>(&(_flags))->FUN_00621270(0x800))) != 0;
}

struct FUN_006210a0_shell : FUN_00621100_shell
{
    void* __thiscall FUN_006210a0(unsigned int flags);
};

// @fnv 0x006210a0
void* __thiscall FUN_006210a0_shell::FUN_006210a0(unsigned int flags)
{
    SetVtable();
    if (flags & 1)
        FUN_006210d0(this);
    return this;
}

void FUN_006211b0(void*);
struct hkpAllCdPointCollector
{
    void FUN_006211b0();
    void* FUN_00621140(unsigned int aiFlags);
};
struct Base_620ff0
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;

    Base_620ff0();
    ~Base_620ff0();
};

struct Sub_620ff0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    Sub_620ff0(int aValue);
    ~Sub_620ff0();
};

struct FUN_00620ff0 : Base_620ff0
{
    Sub_620ff0 m_10;

    FUN_00620ff0();
    virtual void v00();
};

// @fnv 0x00620ff0
FUN_00620ff0::FUN_00620ff0() : m_10(0)
{
    reinterpret_cast<::FUN_00621120_shell *>(this)->FUN_00621120();
}

extern int DAT_0104da28;

class CdPointSubObj
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~CdPointSubObj();
};

class CdPointCollectorBase
{
  public:
    virtual void Update();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~CdPointCollectorBase();
};

class FUN_006211b0_cls : public CdPointCollectorBase
{
  public:
    CdPointSubObj m_sub10;
    ~FUN_006211b0_cls();
};
// @fnv 0x00621140
void* hkpAllCdPointCollector::FUN_00621140(unsigned int aiFlags)
{
    reinterpret_cast<::FUN_006211b0_cls *>(this)->FUN_006211b0_cls::~FUN_006211b0_cls();
    if (aiFlags & 1)
        ::fnv_00621170::FUN_00621170(this);
    return this;
}

// Destructor for a CdPointCollectorBase-derived collector that owns a CdPointSubObj member; the body is empty.
// @fnv 0x006211b0
FUN_006211b0_cls::~FUN_006211b0_cls()
{}
