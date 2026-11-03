
// src/havok/unplaced/havokstream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/havokstream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include <new>
#include <cstring>
#include "fnv/decl/C626680Array.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Cls.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_00473180_shell.h"
#include "fnv/decl/FUN_00538e10_class.h"
#include "fnv/decl/FUN_00622570_Class.h"
#include "fnv/decl/FUN_006264f0.h"
#include "fnv/decl/FUN_00626660_Class.h"
#include "fnv/decl/FUN_00cb1a60_Class.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00462000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00538000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00626000.h"
#include "fnv/symbols_00890000.h"
#include "fnv/symbols_00cb0000.h"
struct B1
{
    virtual ~B1();
};

struct FUN_0056d6c0_class : B1
{
    void FUN_0056d6c0();
};

// @fnv 0x0056d6c0
void FUN_0056d6c0_class::FUN_0056d6c0()
{
    reinterpret_cast<::FUN_00538e10_class *>(this)->FUN_00538e10();
}

struct hkFileSystem
{
    unsigned char* m_base;
    int FUN_00624e70(const char*, void*);
};
// @fnv 0x00624e70
int hkFileSystem::FUN_00624e70(const char*, void*)
{
    return 1;
}

struct FUN_006264d0
{
};
struct HavokError
{
    void FUN_00625650();
};
// @fnv 0x00625650
void HavokError::FUN_00625650()
{
    reinterpret_cast<::FUN_00cb1a60_Class *>((((FUN_006264d0*)((char*)this + 0x14))))->FUN_006264d0();
}

namespace fnv_00625a80 {
struct MessageHandler
{
    static MessageHandler& Handler();
};
struct HavokError
{
    void FUN_00625a80(const char* str);
};
// @fnv 0x00625a80
void HavokError::FUN_00625a80(const char* pcMessage)
{
    MessageHandler::Handler();
    ::FUN_005b5e40();
}
}  // namespace fnv_00625a80

struct FUN_00625bd0_class
{
    void FUN_00625bd0();
};

// @fnv 0x00625bd0
void FUN_00625bd0_class::FUN_00625bd0()
{
    reinterpret_cast<::FUN_006264f0 *>(this)->FUN_006264f0::~FUN_006264f0();
}

extern int DAT_0104dfb4;
struct FUN_00538ef0_class
{
    void* FUN_00538ef0();
};
struct FUN_00625fc0_class : FUN_00538ef0_class
{
    void* vtbl;
    FUN_00625fc0_class();
};
// @fnv 0x00625fc0
FUN_00625fc0_class::FUN_00625fc0_class()
{
    FUN_00538ef0();
    vtbl = (void*)&DAT_0104dfb4;
}

namespace fnv_00625fe0 {
extern int DAT_0104dfe8;
struct FUN_00538ef0_class
{
    void* FUN_00625fe0();
};
// @fnv 0x00625fe0
void* FUN_00538ef0_class::FUN_00625fe0()
{
    reinterpret_cast<::FUN_00538ef0_class *>(this)->FUN_00538ef0();
    *(int**)this = &DAT_0104dfe8;
    return this;
}
}  // namespace fnv_00625fe0

extern "C" void __cdecl FUN_00625fc0();

struct FUN_00626000_Class
{
    const char* pStr;
    unsigned char b;
    unsigned char pad[3];
    unsigned char flag;
    void FUN_00625fc0();
    FUN_00626000_Class* FUN_00626000(int);
};

// Calls FUN_00625fc0, sets pStr to "0`b", writes 1 at offset 0xc, and returns this.
// @fnv 0x00626000
FUN_00626000_Class* FUN_00626000_Class::FUN_00626000(int)
{
    new ((void *)this) ::FUN_00625fc0_class();
    pStr = "0`b";
    *(unsigned char*)((char*)this + 0xc) = 1;
    return this;
}

struct NiBinaryStream
{
};

struct FUN_00626100_shell
{
    void* pad0;
    void* pad1;
    NiBinaryStream* m_stream;
    unsigned int ReadFromStream(void* buffer, unsigned int size);
};

// Reads size bytes from m_stream into buffer and returns the result of the stream's Read call.
// @fnv 0x00626100
unsigned int FUN_00626100_shell::ReadFromStream(void* buffer, unsigned int size)
{
    return reinterpret_cast<::FUN_00462d80_shell *>((m_stream))->ReadBytes(buffer, size);
}

struct BSFile
{
};

struct FUN_00626320
{
    void* p;
    void* unused;
    BSFile* file;
    void Method(const void* data, unsigned int size);
};

// @fnv 0x00626320
void FUN_00626320::Method(const void* data, unsigned int size)
{
    reinterpret_cast<::FUN_00473180_shell *>((file))->FUN_00473180((void *)(data), size);
}

struct BSAudio
{
};
void __cdecl FUN_00c856c0(void* a, void* b);
// @fnv 0x00626760
void __cdecl FUN_00626760(void* a)
{
    BSAudio* p = static_cast<BSAudio*>(::FUN_00c85750());
    FUN_00c856c0(((void *)(reinterpret_cast<::MagicCaster_shell *>((p))->FUN_0044edb0())), a);
}

struct FUN_005609f0_shell
{
    bool FUN_005609f0();
};
struct FUN_006264b0_Class
{
    void FUN_006264b0(int);
};
struct FUN_00626470_Class
{
    void FUN_00626470(int, int);
};
struct FUN_006255d0_class
{
    char pad[0x14];
    void FUN_006255d0(int a, int b);
};
// Calls FUN_005609f0 on b; if true forwards a to FUN_006264b0 at this+0x14, otherwise calls FUN_00626470 with a and 1.
// @fnv 0x006255d0
void FUN_006255d0_class::FUN_006255d0(int a, int b)
{
    if (((FUN_005609f0_shell*)&b)->FUN_005609f0())
        ((FUN_006264b0_Class*)((char*)this + 0x14))->FUN_006264b0(a);
    else
        ((FUN_00626470_Class*)((char*)this + 0x14))->FUN_00626470(a, 1);
}

struct FUN_00625f80_class : FUN_0056d6c0_class
{
    FUN_00625f80_class* FUN_00625f80(unsigned int flags);
};
// @fnv 0x00625f80
FUN_00625f80_class* FUN_00625f80_class::FUN_00625f80(unsigned int flags)
{
    FUN_0056d6c0();
    if (flags & 1)
        ::FUN_00538eb0((::Prm *)(void *)(this));
    return this;
}

struct FUN_00626030_class
{
    void FUN_00626060();
    void* FUN_00626030(unsigned int flags);
};
struct FUN_00626250_class
{
    void* FUN_00626250(unsigned int flags);
};

struct FUN_00626390_class
{
    void* pad0;
    void* pad1;
    BSFile* pFile;
    int FUN_00626390();
};

// Returns the result of FUN_004720a0 on pFile, or 0 when pFile is null.
// @fnv 0x00626390
int FUN_00626390_class::FUN_00626390()
{
    return pFile ? FUN_004720a0(reinterpret_cast<char*>(pFile)) : 0;
}

char* __cdecl FUN_00cb1410(const char*);
struct FUN_00626420_shell
{
    char* p;
    int aiLine;
};
struct FUN_00625e70_class
{
    void FUN_00625e70(const char* apFile, int aiLine);
};
// @fnv 0x00625e70
void FUN_00625e70_class::FUN_00625e70(const char* apFile, int aiLine)
{
    char pfile[128];
    char pext[32];
    FUN_00626420_shell ap;
    ::FUN_00462d40(apFile, (char *)(0), 0, (char *)(0), 0, pfile, 128, pext, 32);
    strcat_s(pfile, 128, pext);
    ap.p = FUN_00cb1410(pfile);
    ap.aiLine = aiLine;
    reinterpret_cast<::Cls *>((((FUN_00625e70_class*)((char*)this + 8))))->FUN_00626420((intptr_t)(&ap));
}

struct $SG2686
{
    virtual ~$SG2686();
};
struct FUN_00626060 : FUN_0056d6c0_class
{
    void* pad;
    void* p;
    unsigned char flag;
    virtual ~FUN_00626060();
};
// Calls FUN_00626060, then if the low flag bit is set calls FUN_00538eb0 on this, and returns this.
// @fnv 0x00626030
void* FUN_00626030_class::FUN_00626030(unsigned int flags)
{
    reinterpret_cast<::FUN_00626060 *>(this)->FUN_00626060::~FUN_00626060();
    if (flags & 1)
        ::FUN_00538eb0((::Prm *)(void *)(this));
    return this;
}
// @fnv 0x00626060
FUN_00626060::~FUN_00626060()
{
    if (p && flag)
        delete static_cast<$SG2686*>(p);
}

struct FUN_00626280_shell : FUN_0056d6c0_class
{
    const char* pStr;
    void* p;
    unsigned char b;
    virtual ~FUN_00626280_shell();
};
// Calls FUN_00626280, then if bit 0 of flags is set calls FUN_00538eb0 on this, and returns this.
// @fnv 0x00626250
void* FUN_00626250_class::FUN_00626250(unsigned int flags)
{
    reinterpret_cast<::FUN_00626280_shell *>(this)->FUN_00626280_shell::~FUN_00626280_shell();
    if (flags & 1)
        ::FUN_00538eb0((::Prm *)(void *)(this));
    return this;
}
// If p is set and b is true, deletes the object pointed to by p.
// @fnv 0x00626280
FUN_00626280_shell::~FUN_00626280_shell()
{
    if (p && b)
        delete (FUN_00626280_shell*)p;
}

struct MessageHandler
{
    static MessageHandler& Handler();
    void vprintf(const char*, ...);
};
struct FUN_006259b0_shell
{
    void ReportWarning(const char*, int, const char*, const char*, int);
};
// @fnv 0x006259b0
void FUN_006259b0_shell::ReportWarning(const char* apWhat, int aiID, const char* apDescription, const char* apFile,
                                       int aiLine)
{
    MessageHandler::Handler();
    ::FUN_005b5e40();
}

namespace fnv_00625a40 {
struct MessageHandler
{
    static MessageHandler& Handler();
};
struct FUN_00625a40_shell : HavokError
{
    void ReportError(const char* apWhat, int aiID, const char* apDescription, const char* apFile,
                                int aiLine);
};
// Reports a Havok error by calling _FNV_Warning with the file, line, description and what text.
// @fnv 0x00625a40
void FUN_00625a40_shell::ReportError(const char* apDescription, int aiID, const char* apWhat,
                                                const char* apFile, int aiLine)
{
    MessageHandler::Handler();
    ::FUN_005b5e40();
}
}  // namespace fnv_00625a40

struct FUN_00625b40_class : HavokError
{
    virtual ~FUN_00625b40_class();
    void* FUN_00625b10(unsigned int flags);
};
struct CalleeObj
{
    void FUN_00622570(bool);
};
struct FUN_00626160
{
    void* pad0;
    void* pad1;
    void* pFile;
    CalleeObj* Method(CalleeObj*);
};
// Calls FUN_00622570 on o with the result of FUN_008905f0 on pFile, or false when pFile is null, and returns o.
// @fnv 0x00626160
CalleeObj* FUN_00626160::Method(CalleeObj* apCallee)
{
    reinterpret_cast<::FUN_00622570_Class *>((apCallee))->FUN_00622570(pFile ? ::FUN_008905f0((bool *)(((FUN_00626160*)pFile))) : false);
    return apCallee;
}

extern "C" void* __cdecl FUN_0056d280(unsigned int size);

struct FUN_00626000
{
    static void operator delete(void*);
    unsigned int source;
    unsigned int flags;
    unsigned int counter;
    unsigned int state;
    FUN_00626000(int index);
    static __forceinline void* operator new(std::size_t size)
    {
        return FUN_0056d280(size);
    }
};

struct FUN_00624e90_Class
{
    FUN_00626000* FUN_00624e90(int index);
};

// Allocates and constructs a FUN_00626000 object with the given index, returning the new object.
// @fnv 0x00624e90
FUN_00626000* FUN_00624e90_Class::FUN_00624e90(int index)
{
    return new FUN_00626000(index);
}

class B625F10Base
{
  public:
    B625F10Base();
    virtual ~B625F10Base();

    int unk04;
};

class B625F10List
{
  public:
    B625F10List();

    void* m_pvItem;
    B625F10List* m_pkNext;
};

class FUN_00625f10_cls : public B625F10Base, public B625F10List
{
  public:
    FUN_00625f10_cls();
    virtual ~FUN_00625f10_cls();
};

// @fnv 0x00625f10
FUN_00625f10_cls::FUN_00625f10_cls()
{}

extern void __cdecl FUN_00c66670();

// @fnv 0x00625fb0
void __cdecl FUN_00625fb0()
{
    FUN_00c66670();
}

struct FUN_00626120_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10();
};

struct FUN_00626120_cls
{
    void* pad0;
    void* pad1;
    FUN_00626120_obj* m_08;
    int GetV10OrMinusOne();
};
// Returns the result of calling v10 on m_08 if m_08 is non-null, otherwise returns -1.
// @fnv 0x00626120
int FUN_00626120_cls::GetV10OrMinusOne()
{
    return m_08 != 0 ? m_08->v10() : -1;
}

struct FUN_00625fe0
{
    FUN_00625fe0();
    ~FUN_00625fe0();
};

struct FUN_00b00260
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
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    FUN_00b00260(void* a, int b, int c, int d);
};

struct FUN_006261a0 : FUN_00625fe0
{
    const char* pStr;
    int unk04;
    FUN_00b00260* m_08;
    unsigned char m_0c;

    FUN_006261a0(void* arg);
};

// Initializes the object: sets pStr to a string literal, sets m_0c to 1, and allocates a FUN_00b00260 with arg, 1, 0x4000, 0.
// @fnv 0x006261a0
FUN_006261a0::FUN_006261a0(void* arg)
{
    pStr = "Pbb";
    m_0c = 1;
    m_08 = new FUN_00b00260(arg, 1, 0x4000, 0);
}

class C626340Handler
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void Handle(int iA, int iB);
};

class C626340Dispatcher
{
  public:
    int unk00;
    int unk04;
    C626340Handler* m_pkHandler;

    int DispatchToHandler(int iA, int iB);
};

// Calls m_pkHandler->Handle(iA, iB) if the handler is set and returns 0, otherwise returns 1.
// @fnv 0x00626340
int C626340Dispatcher::DispatchToHandler(int iA, int iB)
{
    int iResult = 1;
    if (m_pkHandler)
    {
        m_pkHandler->Handle(iA, iB);
        iResult = 0;
    }
    return iResult;
}

struct FUN_00625a00_shell
{
    void WarnWithLocation(const char* message, int unused, const char* type, const char* file, int line);
};
// Calls MessageHandler::Handler, then logs a warning with file, line, message and type via FNV_Warning.
// @fnv 0x00625a00
void FUN_00625a00_shell::WarnWithLocation(const char* message, int unused, const char* type, const char* file, int line)
{
    MessageHandler::Handler();
    ::FUN_005b5e40();
}

class C624F90Base
{
  public:
    C624F90Base();
    virtual ~C624F90Base();

    int unk04;
};

class C624F90HandlerList
{
  public:
    C624F90HandlerList();
    ~C624F90HandlerList();

    int unk00;
    int unk04;
    int unk08;
};

class C624F90HandlerMap
{
  public:
    C624F90HandlerMap();
    ~C624F90HandlerMap();

    int unk00;
    int unk04;
    int unk08;
};

class C624F90Handler
{
  public:
    C624F90Handler(bool bEnabled);
    C624F90Handler(const C624F90Handler& kOther);

    int m_iFadeIndex;
};

extern const char g_ac624F90EventName[];

class FUN_00624f90 : public C624F90Base
{
  public:
    FUN_00624f90();
    virtual ~FUN_00624f90();


    C624F90HandlerList m_kHandlers;
    C624F90HandlerMap m_kEvents;
    bool m_bModifierActive;
};

// @fnv 0x00624f90
FUN_00624f90::FUN_00624f90()
{
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x6E8D163B, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x6CEE9071, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF0DE4355, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x2FF8C16F, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF0FE4356, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x275EC1FD, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x1ADAAD0E, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x70DC41CB, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x1FF88F0E, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x475D86B1, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x6FE84A9B, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x21C8AB2A, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x309314D9, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xAD67FA3A, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xAD67FA3A, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF032DE34, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x34DF5494, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF02E32E1, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF02E32E2, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF02E32DF, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF043D534, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF02184ED, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF02DE43E, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF02E32E0, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF02132DF, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF02132FF, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x54006467, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x717C3B1D, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF032DF30, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x0F0213DE, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xAD8966AA, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x2A1DB936, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x68C4E1DC, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x38F1276D, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xF03243DF, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x2FF8C16D, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0xABBAEFBF, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x761EC287, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x53FE2EBC, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x1F0690F0, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_006255d0_class *>(this)->FUN_006255d0(0x56F80833, (*(int *)&(const ::C624F90Handler &)(C624F90Handler(false))));
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 38);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 86);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 93);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 106);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 110);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 115);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 126);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 133);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 191);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 246);
    reinterpret_cast<::FUN_00625e70_class *>(this)->FUN_00625e70(g_ac624F90EventName, 277);
    m_bModifierActive = false;
}

struct FUN_00626490_Class
{
    int FUN_00626490(int a, int b);
};

struct FUN_00625610_Class
{
    char unk00[0x14];
    FUN_00626490_Class m_sub;
    CalleeObj* FUN_00625610(CalleeObj* obj, int b);
};

// Calls FUN_00626490(b, 0) on m_sub, passes whether the result equals 0 to obj->FUN_00622570, and returns obj.
// @fnv 0x00625610
CalleeObj* FUN_00625610_Class::FUN_00625610(CalleeObj* obj, int b)
{
    reinterpret_cast<::FUN_00622570_Class *>((obj))->FUN_00622570(m_sub.FUN_00626490(b, 0) == 0);
    return obj;
}

struct hkBool6256 : FUN_005609f0_shell
{
    char m_cValue;
};

struct ErrorHandler6256
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual hkBool6256 IsEnabled(int aiSoundId);
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void ShowAssert(const char* pcType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
    virtual void ShowError(const char* pcType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
    virtual void ShowWarning(const char* pcType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
    virtual void ShowReport(const char* pcType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
    int ReportMessage(int iType, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
};

int __cdecl FUN_00406d50(char* pcDest, unsigned int uiSize, const char* pcSrc);

struct LogStub6257
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int __cdecl Report(const char* pcFile, int iLine, const char* pcMessage);
};


struct FUN_00622570
{
    FUN_00622570(bool bValue);
    FUN_00622570(const FUN_00622570& kOther);
    int m_iValue;
};

struct ErrorHandler6257
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void Raise(int aiSoundId, FUN_00622570 kResult);
    char m_acPad4[0x1c];
    char m_acSdkPath[0x104];
    void FUN_00625790(const char* pcPrefix, int aiSoundId, const char* pcMessage, const char* pcFile, int iLine);
};

// Builds a prefix/message string, resolves the report file path against m_acSdkPath, reports it with the line number, and raises on result 5.
// @fnv 0x00625790
void ErrorHandler6257::FUN_00625790(const char* pcPrefix, int aiSoundId, const char* pcMessage, const char* pcFile,
                                    int iLine)
{
    char acMsg[0x400];
    if (pcPrefix)
        ::TaskQueueInterface::CopyStringToBuffer(acMsg, 0x400, pcPrefix);
    else
        acMsg[0] = 0;
    if (pcMessage)
    {
        FUN_00406d50(acMsg, 0x400, " : ");
        FUN_00406d50(acMsg, 0x400, pcMessage);
    }
    int iLineNo = iLine;
    char acFileName[0x104];
    const char* pcReportFile = 0;
    if (m_acSdkPath[0])
    {
        pcReportFile = std::strstr((char *)(pcFile), "TES4");
        if (!pcReportFile)
            pcReportFile = std::strstr((char *)(pcFile), "tes4");
        if (pcReportFile)
        {
            ::TaskQueueInterface::CopyStringToBuffer(acFileName, 0x104, m_acSdkPath);
            FUN_00406d50(acFileName, 0x104, pcReportFile);
            pcReportFile = acFileName;
        }
        else if (pcFile[0] == '.' && pcFile[1] == '.')
        {
            ::TaskQueueInterface::CopyStringToBuffer(acFileName, 0x104, m_acSdkPath);
            FUN_00406d50(acFileName, 0x104, "TES4\\Havok\\SDK\\Include\\");
            FUN_00406d50(acFileName, 0x104, pcFile + 3);
            pcReportFile = acFileName;
        }
    }
    if (!pcReportFile)
    {
        pcReportFile = pcFile;
        iLineNo = iLine;
    }
    if (((::LogStub6257 *)(::fnv_0043bd00::FUN_0043bd00()))->Report(pcReportFile, iLineNo, acMsg) == 5)
        Raise(aiSoundId, FUN_00622570(false));
}

const char* __cdecl FUN_00cb1150(const char*, int);

struct FUN_00625aa0_shell
{
    const char* FUN_00625aa0(const char* apPath);
};

// @fnv 0x00625aa0
const char* FUN_00625aa0_shell::FUN_00625aa0(const char* apPath)
{
    const char* pSeparators = "/\\";
    for (int iIndex = 0; iIndex < 2; ++iIndex)
    {
        const char* pSeparatorPos = FUN_00cb1150(apPath, pSeparators[iIndex]);
        if (!pSeparatorPos)
            apPath = pSeparatorPos;
        else
            apPath = pSeparatorPos + 1;
    }
    return apPath;
}

struct FUN_00625bf0_Item
{
    void* unk00;
    void* unk04;
};
struct FUN_00625bf0_Container
{
};
void __cdecl FUN_00626760(void* object);
struct FUN_00625bf0_Class
{
    void FUN_00625bf0(FUN_00625bf0_Container* container);
};
// Iterates the container's items and calls FUN_00626760 on each item's unk00 pointer.
// @fnv 0x00625bf0
void FUN_00625bf0_Class::FUN_00625bf0(FUN_00625bf0_Container* container)
{
    for (int index = 0; index < ((intptr_t)(reinterpret_cast<::Callees *>((container))->FUN_00726070())); ++index)
    {
        FUN_00625bf0_Item item = *((::FUN_00625bf0_Item *)(reinterpret_cast<::FUN_00626660_Class *>((container))->FUN_00626660(index)));
        FUN_00626760(item.unk00);
    }
}


struct FileEntry625c
{
    const char* m_pcName;
    int m_iValue;
};

struct FileList625c
{
};

struct FileFilter625c
{
    int unk00;
    int unk04;
    FileList625c m_kList;

    bool FUN_00625c50(const char* pcPath, int iValue);
};
// @fnv 0x00625670
int ErrorHandler6256::ReportMessage(int iType, int iMessageId, const char* pcMessage, const char* pcFile, int iLine)
{
    if (iMessageId == -1)
    {
        if (!reinterpret_cast<::FileFilter625c *>(this)->FUN_00625c50(pcFile, iLine))
            return 0;
    }
    else if (!IsEnabled(iMessageId).FUN_005609f0())
        return 0;
    switch (iType)
    {
    case 0:
        ShowReport("Report", iMessageId, pcMessage, pcFile, iLine);
        break;
    case 1:
        ShowWarning("Warning", iMessageId, pcMessage, pcFile, iLine);
        break;
    case 2:
    case 3:
        ShowAssert("Assert", iMessageId, pcMessage, pcFile, iLine);
        break;
    default:
        ShowError("Error", iMessageId, pcMessage, pcFile, iLine);
        break;
    }
    return 1;
}

// Builds a name-plus-extension string from pcPath, then returns false if any list entry matches it and has the same iValue; otherwise returns true.
// @fnv 0x00625c50
bool FileFilter625c::FUN_00625c50(const char* pcPath, int iValue)
{
    if (((intptr_t)(reinterpret_cast<::Callees *>(&(m_kList))->FUN_00726070())))
    {
        char acExtBuf[32];
        char acName[128];
        ::FUN_00462d40(pcPath, (char *)(0), 0, (char *)(0), 0, acName, 0x80, acExtBuf, 0x20);
        strcat_s(acName, 0x80, acExtBuf);
        for (int i3 = 0; i3 < ((intptr_t)(reinterpret_cast<::Callees *>(&(m_kList))->FUN_00726070())); i3++)
        {
            FileEntry625c kEntry = *((::FileEntry625c *)(reinterpret_cast<::FUN_00626660_Class *>(&(m_kList))->FUN_00626660(i3)));
            if (!::fnv_00cb0fe0::CompareStringsCaseInsensitive(acName, kEntry.m_pcName) && iValue == kEntry.m_iValue)
                return false;
        }
    }
    return true;
}

namespace fnv_00625d60 {

struct FileEntry625c
{
    const char* m_pcName;
    int m_iValue;
};

struct FileList625c
{
};

struct FileFilter625c
{
    int unk00;
    int unk04;
    FileList625c m_kList;

    void RemoveEntryByPathAndValue(const char* pcPath, int iValue);
};

// Builds a name from the path and extension, then removes the first list entry whose name matches and whose value equals iValue.
// @fnv 0x00625d60
void FileFilter625c::RemoveEntryByPathAndValue(const char* pcPath, int iValue)
{
    char acExtBuf[32];
    char acName[128];
    ::FUN_00462d40(pcPath, (char *)(0), 0, (char *)(0), 0, acName, 0x80, acExtBuf, 0x20);
    strcat_s(acName, 0x80, acExtBuf);
    for (int i3 = 0; i3 < ((intptr_t)(reinterpret_cast<::Callees *>(&(m_kList))->FUN_00726070())); i3++)
    {
        FileEntry625c kEntry = *((::fnv_00625d60::FileEntry625c *)(reinterpret_cast<::FUN_00626660_Class *>(&(m_kList))->FUN_00626660(i3)));
        if (!::fnv_00cb0fe0::CompareStringsCaseInsensitive(acName, kEntry.m_pcName) && iValue == kEntry.m_iValue)
        {
            ::FUN_00626760((void*)kEntry.m_pcName);
            reinterpret_cast<::C626680Array *>(&(m_kList))->RemoveAt(i3);
            break;
        }
    }
}
}  // namespace fnv_00625d60

// Representative of the native reference-counted stream base subobject.
struct StreamBase
{
    virtual void DestructorEntry();
    unsigned short memorySizeAndFlags;
    unsigned short referenceCount;
};
struct StreamObject : StreamBase
{
    BSFile* file;
    bool ownsFile;
    StreamObject(void* path);
    static __forceinline void* operator new(std::size_t size)
    {
        return FUN_0056d280(size);
    }
};
struct StreamFactory
{
    StreamObject* CreateStreamObject(void* path);
};
// Allocates and returns a new StreamObject constructed from the given path.
// @fnv 0x00624f10
StreamObject* StreamFactory::CreateStreamObject(void* path)
{
    return new StreamObject(path);
}

class FUN_0056d6c0
{
  public:
    virtual ~FUN_0056d6c0();

    int unk04;
};

class FUN_0057c530
{
  public:
    ~FUN_0057c530();

    int unk00;
    int unk04;
    int unk08;
};

class FUN_00625bd0
{
  public:
    ~FUN_00625bd0();

    int unk00;
};

class FUN_00625b40 : public FUN_0056d6c0
{
  public:
    virtual ~FUN_00625b40();


    FUN_0057c530 m_kList;
    FUN_00625bd0 m_kRef;
};
// @fnv 0x00625b10
void* FUN_00625b40_class::FUN_00625b10(unsigned int flags)
{
    reinterpret_cast<::FUN_00625b40 *>((this))->FUN_00625b40::~FUN_00625b40();
    if (flags & 1)
        ::FUN_00538eb0((::Prm *)(void *)(this));
    return this;
}

// Destructor that calls FUN_00625bf0 on m_kList before returning.
// @fnv 0x00625b40
FUN_00625b40::~FUN_00625b40()
{
    reinterpret_cast<::FUN_00625bf0_Class *>(this)->FUN_00625bf0((::FUN_00625bf0_Container *)(::FUN_0057c530 *)(&m_kList));
}

#include "generated/data/havok/unplaced/havokstream.inc"
