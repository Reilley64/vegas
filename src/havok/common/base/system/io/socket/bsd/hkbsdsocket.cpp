
// src/havok/common/base/system/io/socket/bsd/hkbsdsocket.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/socket/bsd/hkbsdsocket.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00d2b850.h"
#include "fnv/decl/StringBuf.h"
#include <winsock2.h>
#include <windows.h>
#include <new>
#include <cstdint>
#include "fnv/decl/BufferOwner.h"
#include "fnv/decl/CC0280Writer.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/RequestReceiver.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_01268000.h"

// hkBsdSocket's data (32-bit offsets): hkReferencedObject at +0x0, hkSocket's reader and writer adapters at +0x8 and
// +0x14, the socket handle at +0x20. The per-function classes below derive from it; their virtual calls go through
// m_vtable with Callback.
struct hkBsdSocketLayout
{
    struct Adapter
    {
        void* m_vtable;
        unsigned short m_memSizeAndFlags;
        short m_referenceCount;
        hkBsdSocketLayout* m_socket;
    };

    void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    Adapter m_reader;
    Adapter m_writer;
    SOCKET m_pSocket;

    typedef void (*Callback)(hkBsdSocketLayout*);
    Callback virtualSlot(int index)
    {
        return static_cast<Callback*>(m_vtable)[index];
    }
};

struct FUN_00da2dc0_class : hkBsdSocketLayout
{
    void CloseSocket();
};
// @fnv 0x00da2dc0
void FUN_00da2dc0_class::CloseSocket()
{
    if (m_pSocket != INVALID_SOCKET)
    {
        closesocket(m_pSocket);
        m_pSocket = INVALID_SOCKET;
    }
}

extern int DAT_010d5030;

struct hkBsdSocket : hkBsdSocketLayout
{
    void Destroy();
};

// @fnv 0x00da3080
void hkBsdSocket::Destroy()
{
    m_vtable = &DAT_010d5030;
    reinterpret_cast<::FUN_00da2dc0_class *>((this))->CloseSocket();
    m_writer.m_vtable = &::DAT_0102e388;
    m_reader.m_vtable = &::DAT_0102e388;
    m_vtable = &::DAT_0102e388;
}

extern "C" void __cdecl FUN_00d2b850(void);
extern "C" void __cdecl FUN_00da2de0(void*);
extern int DAT_010d5030;

struct FUN_00da30a0_cls : hkBsdSocketLayout
{
    void FUN_00da2de0();
    void* InitWithParam(SOCKET param);
};

struct FUN_00da2db0_cls : hkBsdSocketLayout
{
    bool* FUN_00da2db0(bool* pOut);
};

// @fnv 0x00da2db0
bool* FUN_00da2db0_cls::FUN_00da2db0(bool* pOut)
{
    *pOut = (m_pSocket != INVALID_SOCKET);
    return pOut;
}


struct FUN_00da2e60_cls : hkBsdSocketLayout
{
    int FUN_00da2e60(intptr_t, int);
};

// @fnv 0x00da2e60
int FUN_00da2e60_cls::FUN_00da2e60(intptr_t a, int b)
{
    int r;
    if (m_pSocket != INVALID_SOCKET)
    {
        r = send(m_pSocket, (const char *)(a), b, 0);
        if (r > 0 && r != -1)
            return r;
        if (WSAGetLastError() != 0x2733)
            virtualSlot(4)(this);
    }
    return 0;
}


struct FUN_00da2de0_class : hkBsdSocketLayout
{
    int FUN_00da2de0();
};
// Calls FUN_00d2b850, sets the vtable to DAT_010d5030 and m_field_0x20 to param, calls FUN_00da2de0 if param is -1, and returns this.
// @fnv 0x00da30a0
void* FUN_00da30a0_cls::InitWithParam(SOCKET param)
{
    FUN_00d2b850();
    m_vtable = &DAT_010d5030;
    m_pSocket = param;
    if (param == INVALID_SOCKET)
        reinterpret_cast<::FUN_00da2de0_class *>(this)->FUN_00da2de0();
    return this;
}

// @fnv 0x00da2de0
int FUN_00da2de0_class::FUN_00da2de0()
{
    virtualSlot(4)(this);

    SOCKET result = socket(2, 1, 0);
    bool success = result == INVALID_SOCKET;
    m_pSocket = result;
    return success;
}

struct FUN_00da2f90_cls : hkBsdSocketLayout
{
    bool FUN_00da2f90(intptr_t a, int b, int c);
};
// @fnv 0x00da2f90
bool FUN_00da2f90_cls::FUN_00da2f90(intptr_t aiArg1, int aiArg2, int c)
{
    return WSAAsyncSelect(m_pSocket, (HWND)(aiArg1), aiArg2, ((c & 3) | ((c & 0xc) << 2))) != 0;
}



struct FUN_00da2e10_cls : hkBsdSocketLayout
{
    int Read(void* buf, int len);
};

// @fnv 0x00da2e10
int FUN_00da2e10_cls::Read(void* buf, int len)
{
    if (m_pSocket != INVALID_SOCKET)
    {
        int res = recv(m_pSocket, (char *)(buf), len, 0);
        if (res > 0 && res != -1)
        {
            return res;
        }
        if (WSAGetLastError() != 0x2733)
        {
            virtualSlot(4)(this);
        }
    }
    return 0;
}

struct FUN_00cbbd40_router
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*, int);
};
struct FUN_00cbbd40_holder
{
    int unk0;
    int unk4;
    int unk8;
    FUN_00cbbd40_router* unkC;
};
struct FUN_00cbbd40_cls
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void FUN_00cbbd40();
};
// @fnv 0x00cbbd40
void FUN_00cbbd40_cls::FUN_00cbbd40()
{
    FUN_00cbbd40_holder* pHolder = static_cast<FUN_00cbbd40_holder*>(::FUN_00c85750());
    FUN_00cbbd40_router* r = pHolder->unkC;
    int iOldValue = m_8;
    m_iWordAt04 = 0;
    if (!(iOldValue & 0x80000000))
        r->f4(m_iWordAt00, iOldValue & 0x3fffffff);
    m_iWordAt00 = 0;
    m_8 = 0x80000000;
}


class SocketDA2F : public hkBsdSocketLayout
{
  public:

    bool SetNonBlocking(bool m_bCombatItemSearchActive);
};

// Sets the socket to non-blocking mode via FUN_00ee6d80 and returns whether the call succeeded.
// @fnv 0x00da2fc0
bool SocketDA2F::SetNonBlocking(bool m_bCombatItemSearchActive)
{
    bool* pBlocking = &m_bCombatItemSearchActive;
    volatile unsigned long ulNonBlocking;

    ulNonBlocking = (*pBlocking == 0);

    int result = ioctlsocket(m_pSocket, 0x8004667e, const_cast<unsigned long*>(&ulNonBlocking));

    return !!result;
}

extern char DAT_01269acc;
extern const char str_010d5004[];
extern const char str_010d4fdc[];

struct S00da2ff0_Msg
{
    int unk00;
    int unk04;
    int unk08;
};

struct S00da2ff0_Err
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int, int, void*, const char*, int);
};

// When the flag is clear, calls FUN_00ee6d86 with 0x202, reports failure, and sets the flag.
// @fnv 0x00da2ff0
void InitWinsock()
{
    if (DAT_01269acc == 0)
    {
        struct
        {
            WSADATA wsa;
            int buf[0x80];
        } L;
        if (WSAStartup(0x202, &L.wsa) == -1)
        {
            S00da2ff0_Msg ostr;
            new ((void *)&(ostr)) ::FUN_00cb1600(L.buf, 0x200);
            reinterpret_cast<::SinkOwner *>(&(ostr))->FUN_00cc01c0(str_010d5004);
            if ((*reinterpret_cast<::S00da2ff0_Err * *>(&::DAT_01268360))->v3(3, 0x321825f8, L.buf, str_010d4fdc, 0x48))
                __debugbreak();
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(ostr))->FUN_00cc00e0::~FUN_00cc00e0();
        }
        DAT_01269acc = 1;
    }
}


static __declspec(noinline) bool* FUN_00da2eb0(int c, bool* out)
{
    *out = false;
    if (c >= '0' && c <= '9')
        *out = true;
    return out;
}

struct IPv4SocketAddress
{
    unsigned short family;
    unsigned short port;
    unsigned int address;
    unsigned int sin_zero_low;
    unsigned int sin_zero_high;
};
struct HostEntry
{
    char* name;
    char** aliases;
    short address_type;
    short address_length;
    char** addresses;
};
struct SocketConnector : hkBsdSocketLayout
{
    int FUN_00da2de0();
    int FUN_00da2ec0(const char* host, int port);
};

// Resolves the host to an IPv4 address, ensures a socket exists, and calls the connection routine with the address and port.
// @fnv 0x00da2ec0
int SocketConnector::FUN_00da2ec0(const char* host, int port)
{
    IPv4SocketAddress target;
    ::FUN_00cb1280(&target, 0, sizeof(target));
    target.family = 2;
    target.port = (unsigned short)htons(port);

    if (*FUN_00da2eb0(host[0], (bool*)&port))
    {
        target.address = inet_addr(host);
    }
    else
    {
        HostEntry* pHostEntry = (HostEntry*)(gethostbyname(host));
        if (!pHostEntry)
            return 1;
        ::FUN_00cb1260(&target.address, pHostEntry->addresses[0], pHostEntry->address_length);
    }

    if (m_pSocket == INVALID_SOCKET && reinterpret_cast<::FUN_00da2de0_class *>(this)->FUN_00da2de0())
        return 1;
    int iResult = connect(m_pSocket, (const sockaddr *)(&target), sizeof(target));
    if (iResult != -1)
        goto success;
    if (WSAGetLastError() == 0x2733)
        goto success;
    virtualSlot(4)(this);
    return 1;
success:
    return 0;
}


extern const char str_010d505c[];
extern const char str_010d5070[];

struct sockaddr_inDA30
{
    short sin_family;
    unsigned short sin_port;
    unsigned long sin_addr;
    unsigned long sin_zero[2];
};

class hkStringBufDA30
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[32];

    void FUN_00d61c10(const char* pcString) throw();

    hkStringBufDA30()
    {
        reinterpret_cast<::BufferOwner *>(this)->InitBuffer();
    }
    ~hkStringBufDA30()
    {
        reinterpret_cast<::FUN_00cbbd40_cls *>(this)->FUN_00cbbd40();
    }
    void operator=(const char* pcString)
    {
        FUN_00d61c10(pcString);
    }
};

class hkOstreamDA30
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;


    hkOstreamDA30(void* pvBuffer, int iSize)
    {
        new ((void *)this) ::FUN_00cb1600(pvBuffer, iSize);
    }
    ~hkOstreamDA30()
    {
        reinterpret_cast<struct ::FUN_00cc00e0 *>(this)->FUN_00cc00e0::~FUN_00cc00e0();
    }
};

class hkBsdSocketDA30 : public hkBsdSocketLayout
{
  public:

    int FUN_00da2de0() throw();
    int FUN_00da30d0(int iPort) throw();
};

// Binds the socket to the given port, sets it to listen with backlog 2, and logs the host name and port.
// @fnv 0x00da30d0
int hkBsdSocketDA30::FUN_00da30d0(int iPort) throw()
{
    if (reinterpret_cast<::FUN_00da2de0_class *>(this)->FUN_00da2de0() != 0)
        return 1;

    sockaddr_inDA30 kName;
    kName.sin_family = 2;
    kName.sin_addr = 0;
    kName.sin_port = htons((unsigned short)iPort);

    int iOn = 1;
    setsockopt(m_pSocket, 0xffff, 4, (const char*)&iOn, sizeof(int));

    if (bind(m_pSocket, (const sockaddr*)&kName, sizeof(kName)) == -1)
    {
        virtualSlot(4)(this);
        return 1;
    }
    if (listen(m_pSocket, 2) == -1)
    {
        virtualSlot(4)(this);
        return 1;
    }

    hkStringBufDA30 kHost;
    unsigned int auiHostName[64];
    gethostname((char*)auiHostName, sizeof(auiHostName));
    kHost = (const char*)auiHostName;
    {
        unsigned int auiReportBuf[128];
        hkOstreamDA30 kReportStream(auiReportBuf, sizeof(auiReportBuf));
        reinterpret_cast<::CC0280Writer *>(&((*(::hkOstreamDA30 *)(reinterpret_cast<::SinkOwner *>(&((*(::hkOstreamDA30 *)(reinterpret_cast<::RequestReceiver *>(&((*(::hkOstreamDA30 *)(reinterpret_cast<::SinkOwner *>(&(kReportStream))->FUN_00cc01c0(str_010d505c)))))->InvokeFromRequest((void *)&(kHost))))))->FUN_00cc01c0(str_010d5070)))))->WriteInt(iPort);
        (*reinterpret_cast<::S00da2ff0_Err * *>(&::DAT_01268360))->v3(0, -1, auiReportBuf, str_010d4fdc, 364);
    }
    return 0;
}

struct FUN_00da33d0_client
{
    virtual void FUN_00da33d0_a();
    virtual void FUN_00da33d0_b();
    virtual void FUN_00da33d0_c(void*, unsigned short);
};

struct FUN_00da33d0_router
{
    void* m_vft;
    char m_auiShapeKeys[0x0c];
    FUN_00da33d0_client* m_client;
};

struct FUN_00da33d0_cls : hkBsdSocket
{
    int m_kPointA;
    unsigned short m_kPointB;

    FUN_00da33d0_cls* FUN_00da33d0(bool flag);
};

// @fnv 0x00da33d0
FUN_00da33d0_cls* FUN_00da33d0_cls::FUN_00da33d0(bool flag)
{
    reinterpret_cast<::hkBsdSocket *>((this))->Destroy();
    if (flag & 1)
    {
        FUN_00da33d0_router* router = (FUN_00da33d0_router*)static_cast<FUN_00cbbd40_holder*>(::FUN_00c85750());
        router->m_client->FUN_00da33d0_c(this, m_kPointB);
    }
    return this;
}


namespace fnv_00da3230 {
struct StrBufD32
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_kStorage[0x80];

};

struct OstreamD32
{
    int unk00;
    int unk04;
    int unk08;

};

struct ErrorD32
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int message(int eType, int aiSoundId, const char* pcDesc, const char* pcFile, int iLine);
};

struct AllocD32
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};
struct RouterD32
{
    int unk00, unk04, unk08, unk0C;
    AllocD32* m_pStreamAllocator;

    AllocD32& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD32 {
}

struct SockD32 : hkBsdSocketLayout
{
    void* FUN_00da3230();
};

// @fnv 0x00da3230
void* SockD32::FUN_00da3230()
{
    if (m_pSocket != INVALID_SOCKET)
    {
        fd_set readFds;
        FD_ZERO(&readFds);
        FD_SET(m_pSocket, &readFds);
        fd_set exceptFds;
        FD_ZERO(&exceptFds);
        FD_SET(m_pSocket, &exceptFds);
        timeval t;
        t.tv_sec = 0;
        t.tv_usec = 0;
        int nfds = int(m_pSocket);
        nfds++;
        int numHits = select(nfds, &readFds, 0, &exceptFds, &t);
        if ((numHits > 0) && FD_ISSET(m_pSocket, &readFds))
        {
            sockaddr_in from;
            int iFromLen = sizeof(from);
            SOCKET s = accept(m_pSocket, (sockaddr*)&from, &iFromLen);
            StrBufD32 kMsg;
            reinterpret_cast<::BufferOwner *>(&(kMsg))->InitBuffer();
            reinterpret_cast<::StringBuf *>((&kMsg))->FUN_00d61d00("Socket got connection from [%s:%d]\n", inet_ntoa(from.sin_addr),
                         ntohs(from.sin_port));
            {
                char acBuf[512];
                OstreamD32 kOstr;
                new ((void *)&(kOstr)) ::FUN_00cb1600(acBuf, sizeof(acBuf));
                reinterpret_cast<::RequestReceiver *>(&(kOstr))->InvokeFromRequest((void *)&(kMsg));
                (*reinterpret_cast<::fnv_00da3230::ErrorD32 * *>(&::DAT_01268360))->message(0, -1, acBuf, ".\\System\\Io\\Socket\\Bsd\\hkBsdSocket.cpp", 0x193);
                reinterpret_cast<struct ::FUN_00cc00e0 *>(&(kOstr))->FUN_00cc00e0::~FUN_00cc00e0();
            }
            if (s == INVALID_SOCKET)
            {
                reinterpret_cast<::FUN_00cbbd40_cls *>(&(kMsg))->FUN_00cbbd40();
                return 0;
            }
            int iNoDelay = 1;
            setsockopt(s, 6, 1, (const char*)&iNoDelay, 4);
            hkBsdSocketLayout* p =
                (hkBsdSocketLayout*)(*static_cast<RouterD32*>(::FUN_00c85750())).heap().AllocateMemoryBlock(sizeof(hkBsdSocketLayout));
            p->m_memSizeAndFlags = sizeof(hkBsdSocketLayout);
            void* pkSocket = ((FUN_00da30a0_cls*)p)->InitWithParam(s);
            reinterpret_cast<::FUN_00cbbd40_cls *>(&(kMsg))->FUN_00cbbd40();
            return pkSocket;
        }
    }
    return 0;
}
}

#include "generated/data/havok/common/base/system/io/socket/bsd/hkbsdsocket.inc"
