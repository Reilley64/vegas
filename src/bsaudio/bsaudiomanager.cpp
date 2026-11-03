
// src/bsaudio/bsaudiomanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsaudio/bsaudiomanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <cstdlib>
#include "fnv/decl/AE8150_List.h"
#include "fnv/decl/AE91F0Map.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_00ae78a0_cls.h"
#include "fnv/decl/FUN_00ae78e0_Class.h"
#include "fnv/decl/FUN_00ae8010_cls.h"
#include "fnv/decl/FUN_00aea100_cls.h"
#include "fnv/decl/FUN_00c3cee0_shell.h"
#include "fnv/decl/QRequest.h"
#include "fnv/decl/S_00a0c9f0.h"
#include "fnv/decl/S_00ae8370_List.h"
#include "fnv/decl/fnv_00aa6590__FUN_00aa6590_cls.h"
#include "fnv/decl/fnv_00ad7fa0__AudioUpdateStand.h"
#include "fnv/decl/fnv_00c3cea0__FUN_00c3cea0.h"
#include "fnv/decl/fnv_00c3cf60__FUN_00c3cf60_shell.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_010a3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include <new>
#include <cstdio>
#include <cstring>
#include <malloc.h>
#include "runtime/crt.h"
#include "fnv/decl/BSGameSound.h"
#include "fnv/decl/BSSoundInfo.h"
#include "fnv/decl/E60Map.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_00a0c6c0_cls.h"
#include "fnv/decl/FUN_00aa64f0_t.h"
#include "fnv/decl/FUN_00ae8090_Class.h"
#include "fnv/decl/FUN_00ae8b40_cls.h"
#include "fnv/decl/FUN_00ae8b90_cls.h"
#include "fnv/decl/FUN_00ae8bf0_t.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MersenneTwister.h"
#include "fnv/decl/Node185.h"
#include "fnv/decl/RMapBase.h"
#include "fnv/decl/RecursiveLock.h"
#include "fnv/decl/SoundRange_00ae9b50.h"
#include "fnv/decl/TemplateList_00a0ae70.h"
#include "fnv/decl/nae7__Map.h"
#include "fnv/symbols_0072f000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01063000.h"
#include "fnv/symbols_01088000.h"
#include "fnv/symbols_011ac000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01272000.h"
#include <math.h>

namespace fnv_00adb1a0 {
inline void Dead1()
{
    int a[1];
}
}

namespace fnv_00adbb30 {
inline void Dead1()
{
    int a[1];
}
}


namespace fnv_00ada330 {
inline void Dead2()
{
    int a[2];
}
}

namespace fnv_00adb1a0 {
inline void Dead2()
{
    int a[2];
}
}

namespace fnv_00adbb30 {
inline void Dead2()
{
    int a[2];
}
}


struct RefObject
{
    void* m_pVtable;
    volatile long m_iRefCount;

    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_iRefCount);
    }
};

namespace fnv_00adddd0 {
struct RefObject
{
    virtual void unused();
    virtual void Destroy();
    long refs;
    void AddRef()
    {
        InterlockedIncrement(&refs);
    }
    void ReleaseRef()
    {
        if (!InterlockedDecrement(&refs))
            Destroy();
    }
    void Inc()
    {
        InterlockedIncrement(&refs);
    }
    void Dec()
    {
        if (!InterlockedDecrement(&refs))
            Destroy();
    }
};
}

namespace fnv_00adb1a0 {
struct RefObject
{
    virtual void v00();
    virtual void v04();
    long m_04;
    void AddRef()
    {
        InterlockedIncrement(&m_04);
    }
    void Release()
    {
        if (!InterlockedDecrement(&m_04))
            v04();
    }
};
}

namespace fnv_00adb3e0 {
struct RefObject
{
    virtual void v00();
    virtual void v04();
    long m_04;
    void AddRef()
    {
        InterlockedIncrement(&m_04);
    }
    void Release()
    {
        if (!InterlockedDecrement(&m_04))
            v04();
    }
};
}

namespace fnv_00adbb30 {
struct RefObject
{
    int vtable;
    long references;
    __forceinline void AcquireReference()
    {
        InterlockedIncrement(&references);
    }
};
}

struct CritSecA : CRITICAL_SECTION
{
};

template <int N> inline void ReserveFrame();

template <int Pad> struct ListCleanup
{
    ~ListCleanup()
    {
        ReserveFrame<Pad>();
    }
};

template <int Pad> struct ListView : ListCleanup<Pad>
{
    int offset_00, offset_04, offset_08;
    void FUN_00ae8370();
    ~ListView()
    {
        reinterpret_cast<::S_00ae8370_List *>(this)->FUN_00ae8370();
    }
};

namespace fnv_00adb1a0 {
struct NavMeshPtr
{
    RefObject* m_00;
    NavMeshPtr(RefObject* p)
    {
        m_00 = p;
        if (m_00)
            m_00->AddRef();
    }
    NavMeshPtr(const NavMeshPtr& p)
    {
        m_00 = p.m_00;
        if (m_00)
            m_00->AddRef();
    }
    ~NavMeshPtr()
    {
        if (m_00)
            m_00->Release();
    }
    NavMeshPtr& operator=(const NavMeshPtr&);
};
}

namespace fnv_00adb1a0 {
struct Point
{
    float m_00, m_04, m_08;
};
}

namespace fnv_00adb1a0 {
struct Record
{
    int m_00, m_04;
    std::intptr_t m_08, m_0c;
    NavMeshPtr m_10;
    float m_14, m_18, m_1c;
    void Set(int a, int b, std::intptr_t c, std::intptr_t d, NavMeshPtr n, Point p)
    {
        m_00 = a;
        m_04 = b;
        m_08 = c;
        m_0c = d;
        m_10 = n;
        m_14 = p.m_00;
        m_18 = p.m_04;
        m_1c = p.m_08;
        Dead2();
    }
};
}

namespace fnv_00adb1a0 {
struct ListView
{
    char m_00[12];
};
}

namespace fnv_00adb1a0 {
struct Host
{
    int m_00, m_04, m_08;
    ListView m_0c[13];
    char m_a8[4];
    CritSecA m_ac;
    Record* FUN_00adad60();
    void FUN_00adb1a0(int, int, std::intptr_t, std::intptr_t, NavMeshPtr, Point);
};
}

namespace fnv_00adb3e0 {
struct NavMeshPtr
{
    RefObject* m_00;
    NavMeshPtr(RefObject* p)
    {
        m_00 = p;
        if (m_00)
            m_00->AddRef();
    }
    NavMeshPtr(const NavMeshPtr& p)
    {
        m_00 = p.m_00;
        if (m_00)
            m_00->AddRef();
    }
    ~NavMeshPtr()
    {
        if (m_00)
            m_00->Release();
    }
};
}

namespace fnv_00adb3e0 {
struct Point
{
    float m_00, m_04, m_08;
};
}

namespace fnv_00adb3e0 {
struct Host
{
    bool FUN_00adb3e0(unsigned int id, bool flag);
};
}




namespace fnv_00adddd0 {

}

struct SoundMessageRecord;

namespace fnv_00adf080 {
struct SoundMessageRecord;
}

namespace fnv_00adaf80 {
struct SoundMessageRecord;
}

namespace fnv_00adad60 {
struct BottomlessStack
{
};
}

struct SoundMessageRecord;

struct BottomlessStack
{
    void Push(SoundMessageRecord*);
    SoundMessageRecord* Pop();
    void SetBottomless(bool);
    void* __vecDelDtor(unsigned int);
    unsigned int iCount;
    bool m_bBottomless;
    char _pad_5[3];
    SoundMessageRecord* pTop;
    unsigned int m_uiStackLimit;
};

struct SoundMessageRecord;

// namespace fnv_00ae7050
struct SoundMessageRecord
{
    int unk00;
    int unk04;
    int unk08;
    SoundMessageRecord* pNext;

    void FUN_00ae86d0();
    ~SoundMessageRecord()
    {
        int a;
        int b;
        int c;
        int d;
        FUN_00ae86d0();
    }
};

struct NiPoint3
{
    float x, y, z;
    static const NiPoint3 ZERO;
};

namespace fnv_00ada0f0 {
struct NiPoint3
{
    float x, y, z;
    static const NiPoint3 ZERO;
};
}

struct NiAVObject;

struct NiRefObject
{
    void* m_pVtbl;
    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};

struct NiAVObject : NiRefObject
{
};

struct NiPointer
{
    NiAVObject* m_pObject;

    NiPointer(NiAVObject* pkObject = 0) : m_pObject(pkObject)
    {
        int scratch;
        if (m_pObject)
            m_pObject->IncRefCount();
    }

    ~NiPointer()
    {
        if (m_pObject)
            InterlockedDecrement(&m_pObject->m_uiRefCount);
    }
};

namespace fnv_00adb4e0 {
struct NiRefObject
{
    virtual ~NiRefObject();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};
}

extern float DAT_010a3484;

struct Pos3
{
    float x, y, z;
    Pos3()
    {}
    Pos3(int) : x(DAT_010a3484), y(0.0f), z(0.0f)
    {}
};

struct ObjT
{
    virtual void vfn_0();
    virtual void DeleteThis();
    void AcquireReference()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRef()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int GetRefCount() const
    {
        return m_uiRefCount;
    }
    Pos3& GetPos()
    {
        return m_pos;
    }
    long m_uiRefCount;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    int unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88;
    Pos3 m_pos;
};

extern float DAT_010a3484;

void __cdecl FUN_00c45830(ObjT* p);

namespace fnv_00adddd0 {
void __cdecl FUN_00c45830(RefObject*);
}

namespace fnv_00adad80 {
struct NiAVObject
{
    virtual ~NiAVObject();
    virtual void DeleteThis();
    unsigned int refs;
};
}

namespace fnv_00adad80 {
template <class T> struct NiPointer
{
    T* object;
    NiPointer(T* p);
    NiPointer();
    NiPointer(T* p, int);
    ~NiPointer()
    {
        if (object)
        {
            T* value = object;
            if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&value->refs)))
                value->DeleteThis();
        }
    }
    NiPointer& operator=(const NiPointer&);
    NiPointer& operator=(T*);
    bool IsSet() const
    {
        return object != 0;
    }
};
}

namespace fnv_00adad80 {
struct NiPoint3
{
    float x, y, z;
    static const NiPoint3 ZERO;
};
}

namespace fnv_00adad80 {
void __cdecl FUN_00c45830(NiAVObject*);
}

struct BSAudioManager
{
    static BSAudioManager& __cdecl GetRandomGenerator(void);
};

// The file name of a BSGameSound; the pad stands for the members before it.
struct GameSoundFilenameView
{
    char pad00[0x36];
    char m_acFilename[262];
};

// The reference count of a NiRefObject (after its vtable).
struct RefCountView
{
    void* m_pVtbl;
    long m_lRefCount;
};

// The value of a Setting (after its vtable).
struct SettingValueView
{
    void* m_pVtbl;
    unsigned char m_ucValue;
};

namespace fnv_00adad60 {
struct BSAudioManager
{
    char pad00[0x24];
    BottomlessStack m_aiEntries;
    void FUN_00adad60();
};
}

struct BSAudioManager;

namespace fnv_00adf080 {
typedef unsigned int UInt32;
}

namespace fnv_00adf080 {
typedef unsigned short UInt16;
}

namespace fnv_00adf080 {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    __forceinline NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az)
    {}
};
}

namespace fnv_00adf080 {
typedef NiPoint3 AudioVector_adf080;
}

namespace fnv_00adf080 {
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void AcquireReference()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRef()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int GetRefCount() const
    {
        return m_uiRefCount;
    }
};
}

namespace fnv_00adf080 {
class NiObject : public NiRefObject
{
};
}

namespace fnv_00adf080 {
class NiAVObject : public NiObject
{
};
}

namespace fnv_00adf080 {
template <class T> class NiPointer
{
  public:
    T* p;
    NiPointer(T* object = 0) : p(object)
    {
        if (p)
            p->AcquireReference();
    }
    NiPointer(const NiPointer& rhs) : p(rhs.p)
    {
        if (p)
            p->AcquireReference();
    }
    ~NiPointer()
    {
        if (p)
            p->DecRef();
    }
    NiPointer& operator=(const NiPointer&);
    NiPointer& operator=(T* object)
    {
        if (p != object)
        {
            if (p)
                p->DecRef();
            p = object;
            if (p)
                p->AcquireReference();
        }
        return *this;
    }
    T* operator->() const
    {
        return p;
    }
    operator T*() const
    {
        return p;
    }
    bool operator==(const NiPointer& rhs) const
    {
        return p == rhs.p;
    }
};
}

namespace fnv_00adf080 {
typedef NiPointer<NiAVObject> AudioRef_adf080;
}

namespace fnv_00adf080 {
void __cdecl FUN_00c45830(NiAVObject*);
}

namespace fnv_00adf080 {
enum AudioMessageType_adf080
{
    AudioFirst_adf080 = 1,
    AudioLast_adf080 = 66
};
}

namespace fnv_00adf080 {
struct SoundMessageRecord
{
    AudioMessageType_adf080 type;
    int id;
    std::intptr_t argument1;
    std::uintptr_t argument2;
    AudioRef_adf080 object;
    union
    {
        float floats[3];
        UInt16 shorts[5];
    };
    __forceinline void SetObject(AudioRef_adf080 value)
    {
        object = value;
    }
    __forceinline AudioMessageType_adf080 GetType() const
    {
        return type;
    }
    __forceinline int GetID() const
    {
        return id;
    }
    __forceinline std::intptr_t GetArgument1() const
    {
        return argument1;
    }
    __forceinline std::uintptr_t GetArgument2() const
    {
        return argument2;
    }
    __forceinline void SetArgument1(std::intptr_t value)
    {
        argument1 = value;
    }
    __forceinline void SetArgument2(std::uintptr_t value)
    {
        argument2 = value;
    }
    __forceinline UInt16 GetShort(unsigned int index) const
    {
        return shorts[index];
    }
    __forceinline AudioVector_adf080 GetAudioPosition() const
    {
        return AudioVector_adf080(floats[0], floats[1], floats[2]);
    }
};
}

namespace fnv_00adaf80 {
struct SoundMessageRecord;
}

namespace fnv_00adaf80 {
struct BottomlessStack
{
    SoundMessageRecord* Pop();
};
}

namespace fnv_00adaf80 {
struct BSAudioManager
{
    char pad00[0x34];
    BottomlessStack m_kRecordPool;
    SoundMessageRecord* FUN_00adaf80();
};
}

namespace fnv_00ae7050 {
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount();
    long m_uiRefCount;
};
}

namespace fnv_00ae7050 {
template <class T> class NiPointer
{
  public:
    NiPointer(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
}

namespace fnv_00adafa0 {
class NiAVObject
{
  public:
    virtual void v0();
    virtual void DeleteThis();
    long refs;
    void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
}

namespace fnv_00adafa0 {
template <class T> class NiPointer
{
  public:
    T* p;
    NiPointer(T* q = 0) : p(q)
    {
        if (p)
            p->IncRefCount();
    }
    NiPointer(const NiPointer& q) : p(q.p)
    {
        if (p)
            p->IncRefCount();
    }
    ~NiPointer()
    {
        if (p)
            p->DecRefCount();
    }
    NiPointer& operator=(const NiPointer& q)
    {
        if (p != q.p)
        {
            if (q.p)
                q.p->IncRefCount();
            if (p)
                p->DecRefCount();
            p = q.p;
        }
        return *this;
    }
    NiPointer& operator=(T* q)
    {
        if (p != q)
        {
            T* old = p;
            p = q;
            if (p)
                p->IncRefCount();
            if (old)
                old->DecRefCount();
        }
        return *this;
    }
    bool operator!=(T* q) const
    {
        return p != q;
    }
};
}

namespace fnv_00adafa0 {
struct NP : NiPointer<NiAVObject>
{
    NP(NiAVObject* q) : NiPointer<NiAVObject>(q)
    {}
    __declspec(noinline) ~NP()
    {}
};
}

namespace fnv_00adafa0 {
void __cdecl FUN_00c45830(NiAVObject*);
}

namespace fnv_00adb1a0 {

}

namespace fnv_00adb3e0 {

}

namespace fnv_00adb610 {
struct NiPoint3
{
    float x, y, z;
};
}

namespace fnv_00adb610 {
  // NiPoint3::ZERO
struct NiRefObject
{
    void* m_vtbl;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};
}

namespace fnv_00adb610 {
template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {}
};
}

namespace fnv_00adb970 {
struct NiRefObject
{
    void* vtbl;
    unsigned int m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        InterlockedDecrement((long volatile*)&m_uiRefCount);
    }
};
}

namespace fnv_00adb970 {
template <class T> struct NiPointer
{
    T* m_pObject;
    __forceinline NiPointer(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};
}

namespace fnv_00adb970 {
struct NiPoint3
{
    float x, y, z;
};
}

namespace fnv_00adb9f0 {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    __forceinline NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az)
    {}
};
}

namespace fnv_00adb9f0 {
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void AcquireReference()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRef()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
}

namespace fnv_00adb9f0 {
class NiObject : public NiRefObject
{
};
}

namespace fnv_00adb9f0 {
class NiAVObject : public NiObject
{
};
}

namespace fnv_00adb9f0 {
template <class T> class NiPointer
{
  public:
    T* p;
    NiPointer(T* object = 0) : p(object)
    {
        if (p)
            p->AcquireReference();
    }
    NiPointer(const NiPointer& rhs) : p(rhs.p)
    {
        if (p)
            p->AcquireReference();
    }
    ~NiPointer()
    {
        if (p)
            p->DecRef();
    }
};
}

namespace fnv_00adbb30 {

}

namespace fnv_00adbb30 {
struct NP
{
    RefObject* object;
    __forceinline NP(RefObject* p = 0) : object(p)
    {
        if (object)
            object->AcquireReference();
    }
    ~NP();
    NP& operator=(const NP& rhs);
};
}

namespace fnv_00adbb30 {
struct Vector3
{
    float x, y, z;
};
}

namespace fnv_00adbb30 {
struct FUN_00ae86d0
{
    int type;
    int id;
    int data0;
    int data1;
    NP node;
    union
    {
        Vector3 position;
        unsigned short values[5];
    };
    __forceinline FUN_00ae86d0(int soundId, NP src, Vector3 zero)
    {
        type = 0x24;
        id = soundId;
        data0 = 0;
        data1 = 0;
        node = src;
        position.x = zero.x;
        position.y = zero.y;
        position.z = zero.z;
    }
    ~FUN_00ae86d0();
    __forceinline void SetValue(int index, unsigned short value)
    {
        values[index] = value;
    }
};
}

namespace fnv_00adc4e0 {
struct NiPoint3
{
    float x, y, z;
};
}

namespace fnv_00adc4e0 {
  // NiPoint3::ZERO
struct NiRefObject
{
    void* m_vtbl;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};
}

namespace fnv_00adc4e0 {
template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {}
};
}

namespace fnv_00ae7550 {
struct NiAVObject_ae7550
{
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};
}

namespace fnv_00ae7550 {
template <class T> struct NiPointer_ae7550
{
    ~NiPointer_ae7550()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
}

namespace fnv_00ae7550 {
void __cdecl FUN_00c45830(NiAVObject_ae7550* pkObject);
}

namespace fnv_00ae7550 {
struct Pool_ae7550
{
    void FUN_00aa4060(void* p);
};
}

namespace fnv_00ae7550 {
struct FUN_00ae86d0
{
    ~FUN_00ae86d0()
    {
        if (m_pReferencedObject)
            FUN_00c45830(m_pReferencedObject);
    }
    FUN_00ae86d0* GetNext() const
    {
        return m_pNext;
    }
    int unk00;
    int unk04;
    int unk08;
    FUN_00ae86d0* m_pNext;
    NiPointer_ae7550<NiAVObject_ae7550> m_pReferencedObject;
    float unk14;
    float unk18;
    float unk1C;
};
}




namespace fnv_00adddd0 {

}

struct FUN_00a1b940
{
    int state, count, data;
    FUN_00a1b940();
    ~FUN_00a1b940();
};

struct SoundMapBase
{
    virtual ~SoundMapBase();
    unsigned int count, capacity;
    void* entries;
    SoundMapBase(unsigned int = 37);
};

struct SoundMap : SoundMapBase
{
    virtual ~SoundMap();
};

namespace fnv_00adddd0 {
struct SoundPtr
{
    RefObject* ptr;
    __forceinline SoundPtr(RefObject* value = 0) : ptr(value)
    {
        if (ptr)
            ptr->Inc();
    }
    __forceinline ~SoundPtr()
    {
        if (ptr)
            ptr->Dec();
    }
    SoundPtr& Assign(const SoundPtr&);
    SoundPtr& FUN_0066b0d0(RefObject* value)
    {
        if (ptr != value)
        {
            if (ptr)
                ptr->ReleaseRef();
            ptr = value;
            if (ptr)
                ptr->AddRef();
        }
        return *this;
    }
};
}

namespace fnv_00adddd0 {
struct Message
{
    unsigned int type;
    unsigned int Type()
    {
        return type;
    }
};
}

namespace fnv_00adddd0 {
struct MsgNode
{
    MsgNode* next;
    MsgNode* prev;
    Message* value;
};
}

namespace fnv_00adddd0 {
struct AudioPoolLock
{
    void Lock(const char*);
    void Unlock();
};
}

namespace fnv_00adddd0 {
extern AudioPoolLock poolLock;
}

namespace fnv_00adddd0 {
extern MsgNode* poolFree;
}

namespace fnv_00adddd0 {
void ReplenishPool();
}

namespace fnv_00adddd0 {
struct NodePoolView
{
    unsigned int count;
    ~NodePoolView()
    {}
    MsgNode* AddHead()
    {
        poolLock.Lock(0);
        if (!poolFree)
            ReplenishPool();
        MsgNode* item = poolFree;
        MsgNode* next = item->next;
        poolFree = next;
        item->value = 0;
        item->next = 0;
        item->prev = 0;
        poolLock.Unlock();
        return item;
    }
    void Deallocate(MsgNode*);
};
}

namespace fnv_00adddd0 {
struct AudioListBase
{
    MsgNode* head;
    MsgNode* tail;
    NodePoolView pool;
    ~AudioListBase()
    {
        reinterpret_cast<::S_00ae8370_List *>(this)->FUN_00ae8370();
    }
    void FUN_00ae8370()
    {
        MsgNode* item = head;
        while (item)
        {
            MsgNode* old = item;
            item = item->next;
            old->value = 0;
            pool.Deallocate(old);
        }
        pool.count = 0;
        head = 0;
        tail = 0;
    }
};
}

namespace fnv_00adddd0 {
struct FUN_00a1b940 : AudioListBase
{
    FUN_00a1b940();
    ~FUN_00a1b940()
    {}
    Message* FUN_00ae7f90()
    {
        MsgNode* item = head;
        head = head->next;
        if (head)
            head->prev = 0;
        else
            tail = 0;
        Message* value = item->value;
        item->value = 0;
        pool.Deallocate(item);
        --pool.count;
        return value;
    }
    void FUN_00a11db0(MsgNode* item)
    {
        item->next = 0;
        item->prev = tail;
        if (tail)
            tail->next = item;
        else
            head = item;
        tail = item;
        ++pool.count;
    }
    Message*& GetNext(MsgNode*& item)
    {
        Message*& value = item->value;
        item = item->next;
        return value;
    }
    MsgNode* NewNode()
    {
        return ((::fnv_00adddd0::MsgNode *)(reinterpret_cast<::FUN_0043a010_shell *>(&(pool))->FUN_0043a010()));
    }
    __forceinline bool Empty()
    {
        return pool.count == 0;
    }
    __forceinline void Push(Message* const& message)
    {
        MsgNode* node = ((::fnv_00adddd0::MsgNode *)(reinterpret_cast<::FUN_0043a010_shell *>(&(pool))->FUN_0043a010()));
        node->value = message;
        FUN_00a11db0(node);
    }
};
}

namespace fnv_00adddd0 {
struct GameSound
{
    virtual ~GameSound();
    virtual bool Playing();
    virtual void v08();
    virtual bool Paused();
    virtual void v10();
    virtual void Pause(bool);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void Prepare();
    virtual void v2c();
    virtual void Resume(bool);
    virtual void v34();
    virtual void Stop();
    virtual void v3c();
    virtual void v40();
    virtual void Update(int);
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void SetVolume(float);
    virtual float GetVolume();
    unsigned int id, flags, unk0c, state;
    char pad014[0x50];

    char pad064[0x30];

    char pad094[0xa8];
    float duration;
    char pad140[0x10];
    float position;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int delay;
    void(__cdecl* callback)(unsigned int, bool);
    unsigned int unk168, callbackArg;
    char pad170[0x1c];
    FUN_00a1b940 messages;
    __forceinline bool Has(unsigned int mask)
    {
        return (state & mask) != 0;
    }
    __forceinline bool Flag(unsigned int mask)
    {
        return (flags & mask) != 0;
    }
    __forceinline void Mark(unsigned int mask, bool enabled)
    {
        state = enabled ? state | mask : state & ~mask;
    }
    __forceinline bool HasMessages()
    {
        return !messages.Empty();
    }
    bool Looping()
    {
        return (flags & 0x10) || (flags & 0x4000000) || (flags & 0x2000000);
    }
    unsigned int ID()
    {
        return id;
    }
    unsigned int Delay()
    {
        return delay;
    }
    unsigned int Flags()
    {
        return flags;
    }
    float Position()
    {
        return position;
    }
    float Duration()
    {
        return duration;
    }
    void SetDelay(unsigned int value)
    {
        delay = value;
    }
    void SetRange(bool enabled)
    {
        state = enabled ? state | 0x10000 : state & ~0x10000;
    }
    void SetStopped(bool enabled)
    {
        state = enabled ? state | 0x10 : state & ~0x10;
    }
    void(__cdecl* Callback())(unsigned int, bool)
    {
        return callback;
    }
    unsigned int CallbackArg()
    {
        return callbackArg;
    }
};
}

namespace fnv_00adddd0 {
struct SoundEntry
{
    SoundEntry* next;
    unsigned int key;
    SoundPtr value;
};
}

namespace fnv_00adddd0 {
struct SoundMap
{
    virtual void v00();
    virtual unsigned int Hash(unsigned int);
    virtual bool Equal(unsigned int, unsigned int);
    virtual void v0c();
    virtual void Clear(SoundEntry*);
    virtual void v14();
    virtual void Free(SoundEntry*);
    unsigned int capacity;
    SoundEntry** entries;
    unsigned int count;
    SoundEntry* First()
    {
        for (unsigned int index = 0; index < capacity; index++)
            if (entries[index])
                return entries[index];
        return 0;
    }
    void FUN_00a0c850(SoundEntry** position, unsigned int* key, GameSound** sound)
    {
        SoundEntry* item = *position;
        *key = item->key;
        *sound = (GameSound*)item->value.ptr;
        if (item->next)
            *position = item->next;
        else
        {
            unsigned int index = Hash(item->key);
            ++index;
            for (; index < capacity; ++index)
            {
                item = entries[index];
                if (item)
                {
                    *position = item;
                    return;
                }
            }
            *position = 0;
        }
    }
    bool FUN_00a1e240(unsigned int key)
    {
        unsigned int hash = Hash(key);
        SoundEntry* first = entries[hash];
        if (first)
        {
            if (Equal(key, first->key))
            {
                entries[hash] = first->next;
                Clear(first);
                Free(first);
                --count;
                return true;
            }
            SoundEntry* previous = first;
            SoundEntry* current = first->next;
            while (current && !Equal(key, current->key))
            {
                previous = current;
                current = current->next;
            }
            if (current)
            {
                previous->next = current->next;
                Clear(current);
                Free(current);
                --count;
                return true;
            }
        }
        return false;
    }
    bool LookupValue(unsigned int key, SoundPtr* result)
    {
        unsigned int hash = Hash(key);
        SoundEntry* item = entries[hash];
        while (item)
        {
            if (Equal(key, item->key))
            {
                result->Assign(item->value);
                return true;
            }
            item = item->next;
        }
        return false;
    }
};
}

namespace fnv_00adddd0 {
struct AudioUpdate
{
    char pad000[0x54];
    SoundMap sounds;

    char pad064[0x20];
    SoundMap nodes;

    char pad094[0x14];
    float range;
    char pad0ac[0x84];
    unsigned int lastTick;
    unsigned char unk134, dirty, unk136, unk137;
    char pad138[0x4c];
    bool forceVolume;
    void FUN_00ada5d0(unsigned int, GameSound*);
    void FUN_00adddd0();
};
}


struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};

template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};

typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;

namespace fnv_00adef80 {
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
}

namespace fnv_00adef80 {
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
}

namespace fnv_00adef80 {
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
}

namespace fnv_00ae76b0 {
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
}

namespace fnv_00ae76b0 {
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
}

namespace fnv_00ae76b0 {
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
}

struct DetectPoint3
{
    float x;
    float y;
    float z;
};

extern DetectPoint3 DAT_011f426c;

struct NiPoint3_audio
{
    NiPoint3_audio()
    {}
    NiPoint3_audio(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    float x, y, z;
};

namespace fnv_00adef80 {
struct NiPoint3_audio
{
    float x, y, z;
};
}

namespace fnv_00ae76b0 {
struct NiPoint3_audio
{
    float x, y, z;
};
}

// namespace fnv_00adca20

namespace fnv_00adcaa0 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adcaa0_cls
{
    void FUN_00adcaa0(int a, int b);
};
// @fnv 0x00adcaa0
void FUN_00adcaa0_cls::FUN_00adcaa0(int a, int b)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x19, 0, a, b, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adcaa0::NiPointer_audio< ::fnv_00adcaa0::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adcaa0::NiPoint3_audio &)(DAT_011f426c)));
}
}

namespace fnv_00adddd0 {
extern unsigned int DAT_011f426c;
}

namespace fnv_00adad80 { struct Message501; }



namespace fnv_00adf080 {

}

namespace fnv_00adaf80 {

}

namespace fnv_00adad60 {

}







// 

struct Stack75f0 : BottomlessStack
{
    void PushOne(SoundMessageRecord* param_2)
    {
        SoundMessageRecord* top = pTop;
        param_2->pNext = top;
        pTop = param_2;
        iCount = iCount + 1;
    }
    void FUN_00ae75f0(SoundMessageRecord* param_2);
};



namespace fnv_00ada0f0 {

}











namespace fnv_00adb4e0 {

}











namespace fnv_00adddd0 {

}

namespace fnv_00adddd0 {

}

// namespace fnv_00ada330

namespace fnv_00adad80 {


struct NP501 : NiPointer<NiAVObject>
{
    NP501(NiAVObject* p) : NiPointer<NiAVObject>(p, 0)
    {}
    ~NP501();
};

struct Message501
{
    unsigned int id, type;
    std::uintptr_t data, flags;
    NiPointer<NiAVObject> node;
    NiPoint3 position;
    void SetObj(NP501 sp);
    __forceinline void Reset(NiPoint3 pt, NiPointer<NiAVObject> sp);
};

struct FreeList501
{
};
struct Manager501
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    FreeList501 messages;
    void FUN_00adad80(Message501*);
};
template <class T> inline NiPointer<T>::NiPointer(T* p)
{
    object = p;
    int dq[2];
    if (object)
    {
        T* value = object;
        InterlockedIncrement(reinterpret_cast<volatile long*>(&value->refs));
    }
}
template <class T> inline NiPointer<T>::NiPointer(T* p, int)
{
    object = p;
    if (object)
    {
        T* value = object;
        InterlockedIncrement(reinterpret_cast<volatile long*>(&value->refs));
    }
}
template <class T> inline NiPointer<T>::NiPointer()
{
    object = 0;
    if (object)
    {
        int dq[2];
        T* value = object;
        InterlockedIncrement(reinterpret_cast<volatile long*>(&value->refs));
    }
}
inline void Message501::SetObj(NP501 sp)
{
    node = sp;
    int dq2[2];
}
__forceinline void Message501::Reset(NiPoint3 pt, NiPointer<NiAVObject> sp)
{
    int dqB[2];
    id = 0;
    type = 0;
    data = 0;
    flags = 0;
    node = sp;
    position.x = pt.x;
    position.y = pt.y;
    position.z = pt.z;
}
// @fnv 0x00adad80
void Manager501::FUN_00adad80(Message501* message)
{
    NiPointer<NiAVObject> old;
    old = message->node;
    if (old.IsSet())
    {
        message->SetObj(0);
        FUN_00c45830(old.object);
        old = static_cast<NiAVObject*>(0);
    }
    message->Reset(NiPoint3::ZERO, 0);
    reinterpret_cast<::Stack75f0 *>(&(messages))->FUN_00ae75f0((::SoundMessageRecord *)(message));
}
}




struct S_00adc830_Entry;

struct S_00adc830_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iValue;

    int GetValue() const
    {
        return m_iValue;
    }
};

struct S_00adc830_MapItem
{
    S_00adc830_MapItem* m_pkNext;
    unsigned int m_key;
    S_00adc830_Entry* m_val;
};

struct S_00adc830_Map
{
    virtual unsigned int KeyToHashIndex(unsigned int key) const;
    virtual bool IsKeysEqual(unsigned int a, unsigned int b) const;
    unsigned int m_uiHashSize;
    S_00adc830_MapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    bool GetAt(unsigned int key, S_00adc830_Entry*& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        S_00adc830_MapItem* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(pkItem->m_key, key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};

// namespace fnv_00ada0f0

namespace fnv_00ada330 {
inline void Dead8()
{
    int a[8];
}
inline void Dead5()
{
    int a[5];
}

struct FUN_00ae8af0
{
    int m0;
    int Get() const
    {
        return m0;
    }
    ~FUN_00ae8af0();
};
struct MapQ
{
    void* vt;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    bool IsEmpty() const
    {
        return m_uiCount == 0;
    }
    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    bool FUN_00a1e380(unsigned int key, FUN_00ae8af0*& val) const;
};
struct OwnerQ
{
    char p00[0x64];
    MapQ m64;
    MapQ m74;
    char p84[0x40];
    CritSecA cs;
    void FUN_00ada330();
};
// @fnv 0x00ada330
void OwnerQ::FUN_00ada330()
{
    EnterCriticalSection(&cs);
    if (!m74.IsEmpty())
    {
        FUN_00ae8af0* SoundAssetTmp;
        void* kPos = m74.GetFirstPos();
        SoundAssetTmp = 0;
        while (kPos)
        {
            unsigned int uiID;
            FUN_00ae8af0* pVal;
            reinterpret_cast<::RecursiveLock *>((void *)&(m74))->Unlock((::BSCriticalSectionEntry **)&(kPos), (unsigned int *)&(uiID), (void **)&(pVal));
            while (reinterpret_cast<::S_00adc830_Map *>((void *)&(m64))->GetAt(uiID, (::S_00adc830_Entry *&)(SoundAssetTmp)))
            {
                while (reinterpret_cast<::RMapBase *>(&(m64))->FUN_00a1e240(uiID))
                    ;
                delete SoundAssetTmp;
            }
            Dead8();
            if (pVal->Get())
                reinterpret_cast<::FUN_00a0c6c0_cls *>(&(m64))->InsertOrUpdate(uiID, (::AnimSequenceBase *)(pVal));
            else
                delete pVal;
        }
        reinterpret_cast<::AE91F0Map *>(&(m74))->ClearAll();
    }
    bool bReport = false;
    if (bReport && !m64.IsEmpty())
    {
        Dead5();
        void* pos = m64.GetFirstPos();
        Dead2();
        while (pos)
        {
            unsigned int uiID;
            FUN_00ae8af0* pVal;
            reinterpret_cast<::RecursiveLock *>((void *)&(m64))->Unlock((::BSCriticalSectionEntry **)&(pos), (unsigned int *)&(uiID), (void **)&(pVal));
            ::FUN_005b5e40();
        }
        reinterpret_cast<::AE91F0Map *>(&(m74))->ClearAll();
    }
    LeaveCriticalSection(&cs);
}
}

namespace fnv_00ae76b0 { struct FUN_00ae8650; }

struct PoolX
{
};

struct FUN_00ae8650
{
    int m[8];
    FUN_00ae8650();
};







namespace fnv_00adef80 {

}

namespace fnv_00adef80 {

}

namespace fnv_00adef80 {

}

namespace fnv_00ae76b0 {

}

namespace fnv_00ae76b0 {

}

namespace fnv_00ae76b0 {

}

namespace fnv_00ae76b0 {
struct MemoryManager_ae76b0
{
    void FUN_00aa4060(void* p);
};
}

namespace fnv_00ae76b0 {
struct FUN_00ae8650
{
    FUN_00ae8650()
    {
        m_uiID = 0;
        m_uiValue1 = 0;
        m_uiState = 0;
        m_pNext = 0;
        m_fPlaybackVolume = 0.0f;
        m_fFrequency = 0.0f;
        m_fPan = 0.0f;
    }
    FUN_00ae8650* GetNext() const
    {
        return m_pNext;
    }
    unsigned int m_uiID;
    unsigned int m_uiValue1;
    unsigned int m_uiState;
    FUN_00ae8650* m_pNext;
    NiRefObjectPtr_audio m_spSound;
    float m_fPlaybackVolume;
    float m_fFrequency;
    float m_fPan;
};
}

namespace fnv_00ae76b0 {
struct Pool_ae76b0
{
    unsigned int m_uiCount;
    bool m_bCanGrow;
    FUN_00ae8650* pAudioItems;
    unsigned int m_uiLastAlloc;
    FUN_00ae8650* FUN_00ae76b0();
};
}



namespace fnv_00adf080 {

}

namespace fnv_00adaf80 {

}

namespace fnv_00adad60 {

}











namespace fnv_00adf080 {  }











namespace fnv_00adaf80 {

}



namespace fnv_00adad60 {

}

namespace fnv_00adad60 {

}













namespace fnv_00ada0f0 {

}

struct Item;

struct Sound;

struct Setting_00ad9da0
{
    void* vtbl;
    float fValue;
    const char* pKey;
};

struct FUN_00ae6d30_shell
{
    bool HasMatchingEntry(unsigned int mask);
};

struct FUN_00ae6e60_shell
{
    bool FUN_00ae6e60(int param_2, unsigned char param_3);
};

struct BSAudioManagerThread;

struct BSGameSound;



struct Snd_
{
};

struct BSAudio : Snd_
{
    unsigned char _pad[6];
    bool bIsMultiThreaded;
};

struct AE6DE0Slot
{
    unsigned int m_uiMask;
    unsigned short m_usState;
    unsigned short unk06;
};

// The pad stands for the BSAudioManager members before the slot table.
class AE6DE0Table
{
  public:
    char pad000[0x178];
    AE6DE0Slot* m_pkSlots;
    unsigned int m_uiSlotCount;

    bool AddSlot(unsigned int uiMask, bool bPrimary);
};

class BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;

    BaseObj_b5112(int aValue);
    ~BaseObj_b5112();
};

class FUN_00ae6f50 : public BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    void* m_30;

    FUN_00ae6f50(void* aValue);
};

struct Ptr_6e5cc0
{
    void* p;
    Ptr_6e5cc0& operator=(const Ptr_6e5cc0& rhs);
};

struct Msg_ae7990
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Ptr_6e5cc0 ptr10;
    union
    {
        float f14[3];
        unsigned short s14[5];
    };
    Msg_ae7990& CopyFrom(const Msg_ae7990& rhs);
};

struct Sound
{
    virtual ~Sound();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual Sound* Create(int);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void Copy(Sound*, int);
    int p4;
    unsigned int flags;
    char padding[0x138];
    unsigned int id;
    int p148;
    unsigned int size;
};

struct Node
{
    Node* next;
    int p4;
    Sound* sound;
};

struct LinkedSoundQueue
{
    Node* head;
    int p4;
    unsigned int count;
};

struct Owner
{
    char pad[0x94];
    LinkedSoundQueue list;
    unsigned int total;
    char more[0x38];
    CritSecA cs;
    void AddSound(Sound*);
};

namespace fnv_00addc70 {
struct LinkedSoundQueue
{
    void* pHead;
    void* pTail;
    int iCount;
};
}

struct SyncSemaphore
{

    volatile long count;

    void* handle;
};

struct AudioWorker
{

    unsigned int unk00;

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

    SyncSemaphore waitSemaphore;

    unsigned int unk38;

    SyncSemaphore signalSemaphore;

    unsigned int unk44;

    bool processing;

    void FUN_00ae7a50();
};

struct BSSemaphore_adf080
{
    long count;
    void* semaphore;
};

struct BSAudioManagerThread
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    BSSemaphore_adf080 doneSemaphore30;
    unsigned int unk38;
    BSSemaphore_adf080 workSemaphore3c;
    unsigned int unk44;
    bool waiting48;

    void FUN_00ae7ac0();
};

extern const NiPoint3 NiPoint3_ZERO;



namespace fnv_00adcb20 {
struct S_adcb20_Point3
{
    float x;
    float y;
    float z;
};
}

namespace fnv_00adcb20 {
extern S_adcb20_Point3 NiPoint3_ZERO;
}







namespace fnv_00adb4e0 {

}











// namespace fnv_00adef80

namespace fnv_00adf080 {
struct AudioListener_adf080;



typedef unsigned char UInt8;

struct MemoryManagerAllocHelper
{
};

namespace AudioTask_adf080 {
class FUN_00ae6f50 : public BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    void* m_30;
    unsigned int m_34;
    FUN_00ae6f50(void* value);
};
}

struct AudioSystem_adf080
{
    UInt32 unk00;
    UInt16 unk04;
    bool bIsMultiThreaded;
    UInt8 unk07;
    UInt32 unk08;
    UInt32 unk0c;
    AudioListener_adf080* listener;
    __forceinline bool IsMultithreaded() const
    {
        return bIsMultiThreaded;
    }
    __forceinline AudioListener_adf080* GetListener()
    {
        return listener;
    }
};



extern const AudioVector_adf080 NiPoint3_ZERO;
extern char DAT_010a3488[];
static __forceinline float& AudioSettingValue_adf080(Setting_00ad9da0* setting)
{
    return setting ? setting->fValue : (*(float*)&DAT_01202800 = 0.0f);
}

struct AudioTls_adf080
{
    char pad000[0x2b4];
    UInt32 m_uiMemoryContext;
};
static __forceinline UInt32 AudioGetContext_adf080()
{
    return (*reinterpret_cast<::fnv_00adf080::AudioTls_adf080 *>(&::g_tlsBlock)).m_uiMemoryContext;
}
static __forceinline void AudioSetContext_adf080(UInt32 context)
{
    (*reinterpret_cast<::fnv_00adf080::AudioTls_adf080 *>(&::g_tlsBlock)).m_uiMemoryContext = context;
}
struct AudioMemoryContext_adf080
{
    UInt32 previous;
    __forceinline AudioMemoryContext_adf080(UInt32 value) : previous(AudioGetContext_adf080())
    {
        AudioSetContext_adf080(value);
    }
    __forceinline ~AudioMemoryContext_adf080()
    {
        AudioSetContext_adf080(previous);
    }
};











struct AudioMessageNode_adf080
{
    AudioMessageNode_adf080* next;
    AudioMessageNode_adf080* previous;
    SoundMessageRecord* data;
};
struct AudioNodeAllocator_adf080
{
};
struct AudioMessageList_adf080
{
    AudioMessageNode_adf080* first;
    AudioMessageNode_adf080* last;
    AudioNodeAllocator_adf080 allocator;
    void FUN_00a11db0(AudioMessageNode_adf080*);
    __forceinline void AddHead(SoundMessageRecord* const& message)
    {
        AudioMessageNode_adf080* node = ((::fnv_00adf080::AudioMessageNode_adf080 *)(reinterpret_cast<::FUN_0043a010_shell *>(&(allocator))->FUN_0043a010()));
        node->data = message;
        FUN_00a11db0(node);
    }
    __forceinline AudioMessageNode_adf080* GetHead() const
    {
        return first;
    }
    __forceinline SoundMessageRecord*& GetNext(AudioMessageNode_adf080*& position)
    {
        SoundMessageRecord*& data = position->data;
        position = position->next;
        return data;
    }
};

struct BSGameSound
{
    virtual ~BSGameSound();
    virtual bool v04();
    virtual bool v08();
    virtual bool v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30(bool);
    virtual void v34();
    virtual void v38();
    virtual void v3c(float);
    virtual void v40();
    virtual void v44();
    virtual void v48(int);
    virtual void v4c(AudioVector_adf080);
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c(float, float);
    virtual void v60(UInt16, UInt16, UInt16, UInt16, UInt16);
    virtual void v64(float);
    virtual float v68();
    virtual void v6c(int);
    UInt32 id;
    UInt32 flags;
    UInt32 flags0c;
    UInt32 state;
    UInt32 unk014;
    UInt16 attenuation18;
    UInt16 attenuation1a;
    UInt16 attenuation1c;
    UInt16 unk01e;
    UInt16 attenuation20;
    UInt16 unk022;
    float volume;
    float value28;
    float value2c;
    UInt32 unk030;
    UInt16 frequency34;
    char fileName[260];
    UInt16 unk13a;
    UInt32 unk13c;
    UInt32 unk140;
    void* resource144;
    void* resource148;
    UInt32 unk14c;
    UInt32 unk150;
    UInt32 unk154;
    UInt8 randomPercent158;
    UInt8 unk159;
    UInt16 frequency15a;
    int value15c;
    UInt32 unk160;
    std::uintptr_t value164;
    std::uintptr_t value168;
    std::intptr_t value16c;
    std::intptr_t value170;
    UInt32 unk174;
    UInt32 unk178;
    AudioVector_adf080 vector17c;
    int value188;
    AudioMessageList_adf080 messages;
    __forceinline UInt32 GetID() const
    {
        return id;
    }
    __forceinline void SetID(UInt32 value)
    {
        id = value;
    }
    __forceinline UInt32 GetFlags() const
    {
        return flags;
    }
    __forceinline void SetFlags(UInt32 value)
    {
        flags = value;
    }
    __forceinline void* GetResource144() const
    {
        return resource144;
    }
    __forceinline void* GetResource148() const
    {
        return resource148;
    }
    __forceinline bool SameResource144(void* value) const
    {
        return value == resource144;
    }
    __forceinline bool SameResource148(void* value) const
    {
        return value == resource148 && resource148 != 0;
    }
    __forceinline bool Ready800() const
    {
        return (state & 0x800) != 0;
    }
    __forceinline bool Ready100() const
    {
        return (state & 0x100) != 0;
    }
    __forceinline bool Pending1() const
    {
        return (state & 1) != 0;
    }
    __forceinline bool Stopped10() const
    {
        return (state & 0x10) != 0;
    }
    __forceinline bool Alternate0c() const
    {
        return (flags0c & 1) != 0;
    }
    __forceinline bool Alternate1000() const
    {
        return (flags & 0x1000) != 0;
    }
    __forceinline bool Random40() const
    {
        return (flags & 0x40) != 0;
    }
    __forceinline bool SpecialCategory() const
    {
        return (flags & 0x10) || (flags & 0x4000000) || (flags & 0x2000000);
    }
    __forceinline void Set1000(bool b)
    {
        state = b ? (state | 0x1000) : (state & ~0x1000);
    }
    __forceinline void Set10(bool b)
    {
        state = b ? (state | 0x10) : (state & ~0x10);
    }
    __forceinline void Set200(bool b)
    {
        state = b ? (state | 0x200) : (state & ~0x200);
    }
    __forceinline void Set10000(bool b)
    {
        state = b ? (state | 0x10000) : (state & ~0x10000);
    }
    __forceinline void Set2000(bool b)
    {
        state = b ? (state | 0x2000) : (state & ~0x2000);
    }
    __forceinline void SetRandom40(bool b)
    {
        b ? flags |= 0x40 : flags &= ~0x40;
    }
    __forceinline void SetRandomPercent(UInt8 value)
    {
        randomPercent158 = value;
    }
    __forceinline UInt8 GetRandomPercent() const
    {
        return randomPercent158;
    }
    __forceinline void SetAttenuation18(UInt16 value)
    {
        attenuation18 = value;
        v3c(volume);
    }
    __forceinline void SetAttenuation1a(UInt16 value)
    {
        attenuation1a = value;
        v3c(volume);
    }
    __forceinline void SetAttenuation1c(UInt16 value)
    {
        attenuation1c = value;
        v3c(volume);
    }
    __forceinline void SetFade20(double value)
    {
        attenuation20 = (UInt16)value;
        v3c(volume);
    }
    __forceinline void SetFade1c(double fraction)
    {
        attenuation1c = (UInt16)(fraction * ::DAT_01088f48);
        v3c(volume);
    }
    __forceinline void SetAttenuation20(UInt16 value)
    {
        attenuation20 = value;
        v3c(volume);
    }
    __forceinline void RefreshVolume()
    {
        v3c(volume);
    }
    __forceinline void Set164(std::uintptr_t value)
    {
        value164 = value;
    }
    __forceinline void Set168(std::uintptr_t value)
    {
        value168 = value;
    }
    __forceinline void Set16c(std::intptr_t value)
    {
        value16c = value;
    }
    __forceinline void Set170(std::intptr_t value)
    {
        value170 = value;
    }
    __forceinline void Set188(int value)
    {
        value188 = value;
    }
    __forceinline void SetFrequencyScale(float scale)
    {
        frequency15a = (UInt16)(frequency34 * scale);
    }
    __forceinline void Set28(int value)
    {
        value28 = (float)(value * 0.09375);
    }
    __forceinline void Set2c(UInt16 value)
    {
        value2c = (float)(value * 0.09375);
    }
    __forceinline void Set15c(int value)
    {
        value15c = value;
        flags |= 0x1000000;
    }
    __forceinline void Clear15c()
    {
        value15c = 0;
        flags &= ~0x1000000;
    }
    __forceinline void Set8000(bool b)
    {
        state = b ? (state | 0x8000) : (state & ~0x8000);
    }
    __forceinline void SetReferenceVector(AudioVector_adf080 value)
    {
        vector17c = value;
        Set8000(true);
    }
    __forceinline void QueueTail(SoundMessageRecord* message)
    {
        reinterpret_cast<::FUN_00ae8bf0_t *>(&(messages))->AddItem((const void *)&(message));
    }
    __forceinline void QueueHead(SoundMessageRecord* message)
    {
        messages.AddHead(message);
    }
};

template <class TVAL> struct AudioMapItem_adf080
{
    AudioMapItem_adf080* next;
    UInt32 key;
    TVAL val;
};
template <class TVAL> struct AudioMap_adf080
{
    typedef AudioMapItem_adf080<TVAL> Item;
    virtual ~AudioMap_adf080();
    virtual UInt32 KeyToHashIndex(UInt32 key);
    virtual bool IsKeysEqual(UInt32 key1, UInt32 key2);
    virtual void SetValue(Item* item, UInt32 key, TVAL val);
    virtual void ClearValue(Item* item);
    virtual Item* NewItem();
    virtual void DeleteItem(Item* item);
    UInt32 size;
    Item** buckets;
    UInt32 count;
    inline bool GetAt(UInt32 key, TVAL& val)
    {
        UInt32 index = KeyToHashIndex(key);
        Item* item = buckets[index];
        while (item)
        {
            if (IsKeysEqual(key, item->key))
            {
                val = item->val;
                return true;
            }
            item = item->next;
        }
        return false;
    }
    inline void SetAt(UInt32 key, TVAL val)
    {
        UInt32 index = KeyToHashIndex(key);
        Item* item = buckets[index];
        UInt32 depth = 0;
        while (item)
        {
            depth++;
            if (IsKeysEqual(key, item->key))
            {
                item->val = val;
                return;
            }
            item = item->next;
        }
        item = NewItem();
        SetValue(item, key, val);
        item->next = buckets[index];
        buckets[index] = item;
        count++;
    }
    inline bool RemoveAt(UInt32 key)
    {
        UInt32 index = KeyToHashIndex(key);
        Item* item = buckets[index];
        if (item)
        {
            if (IsKeysEqual(key, item->key))
            {
                buckets[index] = item->next;
                ClearValue(item);
                DeleteItem(item);
                count--;
                return true;
            }
            else
            {
                Item* prev = item;
                Item* cur = prev->next;
                while (cur && !IsKeysEqual(key, cur->key))
                {
                    prev = cur;
                    cur = cur->next;
                }
                if (cur)
                {
                    prev->next = cur->next;
                    ClearValue(cur);
                    DeleteItem(cur);
                    count--;
                    return true;
                }
            }
        }
        return false;
    }
    __forceinline Item* GetFirst() const
    {
        for (UInt32 i = 0; i < size; i++)
            if (buckets[i])
                return buckets[i];
        return 0;
    }
    inline void GetNext(Item*& pos, UInt32& key, TVAL& val)
    {
        Item* item = pos;
        key = item->key;
        val = item->val;
        if (item->next)
        {
            pos = item->next;
            return;
        }
        UInt32 i = KeyToHashIndex(item->key);
        for (++i; i < size; i++)
        {
            item = buckets[i];
            if (item)
            {
                pos = item;
                return;
            }
        }
        pos = 0;
    }
};
typedef AudioMap_adf080<BSGameSound*> AudioSoundMap_adf080;
typedef AudioMap_adf080<AudioRef_adf080> AudioRefMap_adf080;
typedef AudioMapItem_adf080<BSGameSound*> AudioSoundItem_adf080;
typedef AudioMapItem_adf080<AudioRef_adf080> AudioRefItem_adf080;
struct AudioMessageStack_adf080
{
    UInt32 count;
    bool bottomless;
    UInt8 unk005;
    UInt16 unk006;
    SoundMessageRecord* top;
    UInt32 lastAllocation;
    void FUN_00ae75f0(SoundMessageRecord*);
};
struct BSSemaphore_adf080
{
    long count;
    void* semaphore;
    void Signal()
    {
        ReleaseSemaphore(semaphore, 1, 0);
        InterlockedIncrement(&count);
    }
    void Wait()
    {
        WaitForSingleObject(semaphore, 0xffffffff);
        InterlockedDecrement(&count);
    }
};
struct BSAudioManagerThread
{
    UInt32 unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    BSSemaphore_adf080 doneSemaphore30;
    UInt32 unk38;
    BSSemaphore_adf080 workSemaphore3c;
    UInt32 unk44;
    bool waiting48;
    void FUN_00aa6590(int, int);
    void FUN_00ae7ac0()
    {
        waiting48 = true;
        workSemaphore3c.Signal();
        FUN_00aa6590(0, 0);
    }
    void FUN_00ae7a50()
    {
        waiting48 = true;
        workSemaphore3c.Signal();
        doneSemaphore30.Wait();
        waiting48 = false;
    }
};
struct AudioListener_adf080
{
    virtual void v00();
    virtual void v04();
    virtual void v08(const AudioVector_adf080&);
};
struct IOManager
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48(AudioTask_adf080::FUN_00ae6f50*);
};

struct FUN_00aa5140
{
    unsigned int state[624];
    unsigned int index;
    unsigned int seed;
    unsigned int mode;
    FUN_00aa5140();
};
static __forceinline float AudioRandomRange_adf080(float minimum, float maximum)
{
    static FUN_00aa5140 generator;
    UInt32 random = reinterpret_cast<::MersenneTwister *>(&(generator))->GetRandomUInt(0xffffffff);
    return (float)(minimum + random * (maximum - minimum) / 4294967296.0);
}

static __forceinline BSAudio* GetAudio_adf080()
{
    return DAT_011f6d98;
}
static __forceinline bool IsMultiThreaded_adf080(BSAudio* audio)
{
    return audio->bIsMultiThreaded;
}
static __forceinline AudioListener_adf080* GetListener_adf080(BSAudio* audio)
{
    return ((AudioSystem_adf080*)audio)->listener;
}
static __forceinline UInt32 GetThreadID_adf080()
{
    return GetCurrentThreadId();
}

struct BSAudioManager_adf080
{
    char pad000[0x44];
    AudioMessageStack_adf080 messageStack44;
    AudioSoundMap_adf080 sounds54;
    char pad064[0x20];
    AudioRefMap_adf080 objects84;
    char pad094[0x14];
    float value0a8;
    char pad0ac[0x30];
    CritSecA critical0dc;
    CritSecA critical0f4;
    char pad10c[0x28];
    bool precache134;
    bool listenerDirty135;
    UInt16 unk136;
    UInt32 threadId138;
    BSAudioManagerThread* thread13c;
    char pad140[0x30];
    UInt32 flags170;
    bool focus174;
    bool alternate175;
    UInt16 unk176;
    AE6DE0Slot* slots178;
    UInt32 slotCount17c;
    bool FUN_00adf080(SoundMessageRecord*);
    void FUN_00adb1a0(int, UInt32, std::intptr_t, std::uintptr_t, AudioRef_adf080, AudioVector_adf080);
    BSGameSound* FUN_00add1e0(void*, void*, UInt32);
    void FUN_00add960(BSGameSound*);
    void FUN_00ada5d0(UInt32, BSGameSound*);
    void FUN_00adbb30(UInt32, UInt16, UInt16, UInt16, UInt16, UInt16);
};

// @fnv 0x00adf080
bool BSAudioManager_adf080::FUN_00adf080(SoundMessageRecord* message)
{
    AudioMemoryContext_adf080 m_uiMemoryContext(11);
    BSGameSound* pkSound = 0;
    UInt32 now = GetTickCount();
    bool bWasPlaying = false;
    AudioSoundItem_adf080* pkItem;
    UInt32 uId;
    {
        switch (message->GetType())
        {
        case 37: {
            pkSound = (BSGameSound*)message->GetArgument2();
            if (!(*reinterpret_cast<::fnv_00adf080::IOManager * *>(&::DAT_01202d98)))
            {
                FUN_00adb1a0(37, message->GetID(), message->GetArgument1(), message->GetArgument2(), AudioRef_adf080(),
                             NiPoint3_ZERO);
            }
            else if (pkSound)
            {
                bool alternate = !reinterpret_cast<::BSGameSound *>((pkSound))->LoadFromFilename(0);
                BSGameSound* prior = 0;
                if (!(pkSound->GetFlags() & 0x10000))
                    prior = FUN_00add1e0(pkSound->GetResource144(), pkSound->GetResource148(), pkSound->GetFlags());
                if (!prior)
                {
                    if (!pkSound->fileName[0])
                        ::FUN_005b5e40();
                    AudioTask_adf080::FUN_00ae6f50* task = new AudioTask_adf080::FUN_00ae6f50(pkSound);
                    pkSound->Set1000(true);
                    (*reinterpret_cast<::fnv_00adf080::IOManager * *>(&::DAT_01202d98))->v48(task);
                    reinterpret_cast<::FUN_00a0c6c0_cls *>(&(sounds54))->InsertOrUpdate(message->GetID(), (::AnimSequenceBase *)(pkSound));
                }
                else
                {
                    prior->flags = pkSound->GetFlags();
                    if (!alternate && prior->SameResource144(pkSound->GetResource144()))
                    {
                        delete pkSound;
                    }
                    else if (prior->SameResource148(pkSound->GetResource148()))
                    {
                        FUN_00add960(pkSound);
                    }
                    pkSound = prior;
                    pkSound->SetID(message->GetID());
                    reinterpret_cast<::FUN_00a0c6c0_cls *>(&(sounds54))->InsertOrUpdate(message->GetID(), (::AnimSequenceBase *)(pkSound));
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
            }
            break;
        }
        case 38: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                pkSound->Set10(true);
                pkSound->Set200(false);
            }
            break;
        }
        case 58: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                std::intptr_t value = message->GetArgument1();
                pkSound->Set164(message->GetArgument2());
                pkSound->Set16c(value);
            }
            break;
        }
        case 59: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                std::intptr_t value = message->GetArgument1();
                pkSound->Set168(message->GetArgument2());
                pkSound->Set170(value);
            }
            break;
        }
        case 39: {
            AudioRef_adf080 incoming;
            incoming.operator=(message->object);
            AudioRef_adf080 previous;
            if (reinterpret_cast<::E60Map *>(&(objects84))->LookupValue(message->GetID(), (::E60Val &)(previous)))
            {
                reinterpret_cast<::RMapBase *>(&(objects84))->FUN_00a1e240(message->GetID());
                if (previous->GetRefCount() == 1)
                    FUN_00c45830(previous);
                previous = 0;
            }
            objects84.SetAt(message->GetID(), incoming);
            message->SetObject(0);
            break;
        }
        case 64: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                bool enabled = message->GetArgument1();
                if (enabled)
                    pkSound->SetFlags(pkSound->GetFlags() | 0x40000);
                else
                    pkSound->SetFlags(pkSound->GetFlags() & ~0x40000);
            }
            break;
        }
        case 63: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v6c(message->GetArgument1());
                }
                else
                {
                    SoundMessageRecord* queued = ((::fnv_00adf080::SoundMessageRecord *)(reinterpret_cast<::fnv_00adaf80::BSAudioManager *>(this)->FUN_00adaf80()));
                    reinterpret_cast<::Msg_ae7990 *>((void *)&(const ::fnv_00adf080::SoundMessageRecord &)(*queued))->CopyFrom((const ::Msg_ae7990 &)(*message));
                    pkSound->QueueTail(queued);
                }
            }
            break;
        }
        case 1: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {

                    if (!reinterpret_cast<::SoundRange_00ae9b50 *>((pkSound))->FUN_00ae9b50(0, value0a8))
                        pkSound->Set10000(true);
                    if ((pkSound->GetFlags() & flags170) && !(pkSound->GetFlags() & 0x800))
                        pkSound->SetAttenuation1c(10000);
                    if (focus174 && !(pkSound->GetFlags() & 0x20) && !(pkSound->GetFlags() & 4) &&
                        !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                    {
                        pkSound->SetAttenuation20((UInt16)(AudioSettingValue_adf080(&(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e80))) * 100.0));
                    }
                    if (pkSound->Random40())
                    {
                        float frequency = pkSound->v68();
                        float variation = (float)(pkSound->GetRandomPercent() / 100.0);
                        frequency += AudioRandomRange_adf080(0.0f, (float)(2.0 * variation)) - variation;
                        pkSound->v64(frequency);
                    }
                    if (pkSound->Alternate0c() || pkSound->Alternate1000())
                        reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(alternate175);
                    pkSound->RefreshVolume();
                    pkSound->v30(false);
                    bool paused = false;
                    if (reinterpret_cast<::FUN_00ae6d30_shell *>(this)->HasMatchingEntry(pkSound->GetFlags()))
                        paused = true;
                    if (paused && !(pkSound->GetFlags() & 0x400000) && !(pkSound->GetFlags() & 0x2000) &&
                        !(pkSound->GetFlags() & 0x1000))
                    {
                        pkSound->v34();
                    }
                    else if (paused && (pkSound->GetFlags() & 0x400000))
                    {
                        reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(true);
                    }
                    else if (paused && !pkSound->SpecialCategory() &&
                             ((pkSound->GetFlags() & 0x2000) || (pkSound->GetFlags() & 0x1000)))
                    {
                        pkSound->v38();
                        pkSound->Set10(true);
                    }
                    pkSound->Set2000(true);
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
                else if (pkSound->Pending1())
                {
                    SoundMessageRecord* queued = ((::fnv_00adf080::SoundMessageRecord *)(reinterpret_cast<::fnv_00adaf80::BSAudioManager *>(this)->FUN_00adaf80()));
                    reinterpret_cast<::Msg_ae7990 *>((void *)&(const ::fnv_00adf080::SoundMessageRecord &)(*queued))->CopyFrom((const ::Msg_ae7990 &)(*message));
                    pkSound->QueueTail(queued);
                }
                else
                {
                    FUN_00adb1a0(1, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                 AudioRef_adf080(), NiPoint3_ZERO);
                }
            }
            break;
        }
        case 2: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v30(true);
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
                else
                {
                    SoundMessageRecord* queued = ((::fnv_00adf080::SoundMessageRecord *)(reinterpret_cast<::fnv_00adaf80::BSAudioManager *>(this)->FUN_00adaf80()));
                    reinterpret_cast<::Msg_ae7990 *>((void *)&(const ::fnv_00adf080::SoundMessageRecord &)(*queued))->CopyFrom((const ::Msg_ae7990 &)(*message));
                    pkSound->QueueTail(queued);
                }
            }
            break;
        }
        case 3: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v34();
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
                else
                {
                    SoundMessageRecord* queued = ((::fnv_00adf080::SoundMessageRecord *)(reinterpret_cast<::fnv_00adaf80::BSAudioManager *>(this)->FUN_00adaf80()));
                    reinterpret_cast<::Msg_ae7990 *>((void *)&(const ::fnv_00adf080::SoundMessageRecord &)(*queued))->CopyFrom((const ::Msg_ae7990 &)(*message));
                    pkSound->QueueTail(queued);
                }
            }
            break;
        }
        case 4: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v38();
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
                else
                {
                    SoundMessageRecord* queued = ((::fnv_00adf080::SoundMessageRecord *)(reinterpret_cast<::fnv_00adaf80::BSAudioManager *>(this)->FUN_00adaf80()));
                    reinterpret_cast<::Msg_ae7990 *>((void *)&(const ::fnv_00adf080::SoundMessageRecord &)(*queued))->CopyFrom((const ::Msg_ae7990 &)(*message));
                    pkSound->QueueTail(queued);
                }
            }
            break;
        }
        case 5: {
            if ((UInt32)message->GetArgument1() <= now)
            {
                if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
                {
                    if (pkSound->Ready800() && pkSound->Ready100())
                    {

                        if (!reinterpret_cast<::SoundRange_00ae9b50 *>((pkSound))->FUN_00ae9b50(0, value0a8))
                            pkSound->Set10000(true);
                        if ((pkSound->GetFlags() & flags170) && !(pkSound->GetFlags() & 0x800))
                            pkSound->SetAttenuation1c(10000);
                        if (focus174 && !(pkSound->GetFlags() & 0x20) && !(pkSound->GetFlags() & 4) &&
                            !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                        {
                            pkSound->SetAttenuation20((UInt16)(AudioSettingValue_adf080(&(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e80))) * 100.0));
                        }
                        if (pkSound->Random40())
                        {
                            float frequency = pkSound->v68();
                            float variation = (float)(pkSound->GetRandomPercent() / 100.0);
                            frequency += AudioRandomRange_adf080(0.0f, (float)(2.0 * variation)) - variation;
                            pkSound->v64(frequency);
                        }
                        if (pkSound->Alternate0c() || pkSound->Alternate1000())
                            reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(alternate175);
                        pkSound->RefreshVolume();
                        if (!pkSound->v0c())
                            pkSound->v30(false);
                        bool paused = false;
                        if (reinterpret_cast<::FUN_00ae6d30_shell *>(this)->HasMatchingEntry(pkSound->GetFlags()))
                            paused = true;
                        if (paused && !(pkSound->GetFlags() & 0x400000) && !(pkSound->GetFlags() & 0x2000) &&
                            !(pkSound->GetFlags() & 0x1000))
                        {
                            pkSound->v34();
                        }
                        else if (paused && (pkSound->GetFlags() & 0x400000))
                        {
                            reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(true);
                        }
                        else if (paused && !pkSound->SpecialCategory() &&
                                 ((pkSound->GetFlags() & 0x2000) || (pkSound->GetFlags() & 0x1000)))
                        {
                            pkSound->v38();
                            pkSound->Set10(true);
                        }
                        pkSound->Set2000(true);
                        FUN_00ada5d0(pkSound->GetID(), pkSound);
                    }
                    else
                    {
                        FUN_00adb1a0(1, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                     AudioRef_adf080(), NiPoint3_ZERO);
                    }
                }
            }
            else
            {
                FUN_00adb1a0(5, message->GetID(), message->GetArgument1(), message->GetArgument2(), AudioRef_adf080(),
                             NiPoint3_ZERO);
            }
            break;
        }
        case 6: {
            break;
        }
        case 9: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    if (message->GetArgument1() == 0)
                    {
                        message->SetArgument1(now);
                        message->SetArgument2(message->GetArgument2() + now);
                    }
                    UInt32 start = message->GetArgument1();
                    int uiEndTime = message->GetArgument2();
                    if (now >= uiEndTime)
                    {
                        pkSound->SetAttenuation1c(10000);
                        pkSound->Set200(false);
                        int followup = (UInt32)message->GetAudioPosition().x;
                        if (followup > 0)
                            FUN_00adb1a0(followup, pkSound->GetID(), 0, 0, AudioRef_adf080(), NiPoint3_ZERO);
                    }
                    else if (now < uiEndTime)
                    {
                        pkSound->Set200(true);
                        pkSound->SetFade1c(1.0 - (double)(uiEndTime - now) / (uiEndTime - start));
                        FUN_00adb1a0(9, pkSound->GetID(), message->GetArgument1(), message->GetArgument2(),
                                     AudioRef_adf080(), message->GetAudioPosition());
                    }
                    pkSound->RefreshVolume();
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
                else
                {
                    if (now >= message->GetArgument2())
                    {
                        pkSound->SetAttenuation1c(10000);
                        pkSound->Set200(false);
                        int followup = (UInt32)message->GetAudioPosition().x;
                        if (followup > 0)
                            FUN_00adb1a0(followup, pkSound->GetID(), 0, 0, AudioRef_adf080(), NiPoint3_ZERO);
                    }
                    else
                    {
                        FUN_00adb1a0(9, pkSound->GetID(), message->GetArgument1(), message->GetArgument2(),
                                     AudioRef_adf080(), message->GetAudioPosition());
                    }
                }
            }
            break;
        }
        case 11: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    if (message->GetArgument1() == 0)
                    {
                        message->SetArgument1(now);
                        message->SetArgument2(message->GetArgument2() + now);
                    }
                    UInt32 start = message->GetArgument1();
                    int uiEndTime = message->GetArgument2();
                    if (now >= uiEndTime)
                    {
                        pkSound->SetAttenuation1c(0);
                        pkSound->Set200(false);
                    }
                    else if (now < uiEndTime)
                    {
                        pkSound->Set200(true);
                        pkSound->SetFade1c((double)(uiEndTime - now) / (uiEndTime - start));
                        FUN_00adb1a0(11, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                     AudioRef_adf080(), NiPoint3_ZERO);
                    }
                    pkSound->RefreshVolume();
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
                else if (pkSound->Ready800() && now >= message->GetArgument2())
                {
                    pkSound->SetAttenuation1c(0);
                    pkSound->Set200(false);
                    FUN_00adb1a0(8, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                 AudioRef_adf080(), NiPoint3_ZERO);
                }
                else
                {
                    FUN_00adb1a0(11, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                 AudioRef_adf080(), NiPoint3_ZERO);
                }
            }
            break;
        }
        case 13: {
            focus174 = message->GetID() != 0;
            UInt32 duration = focus174 ? (UInt32)(AudioSettingValue_adf080(&(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e98))) * 1000.0)
                                       : (UInt32)(AudioSettingValue_adf080(&(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e8c))) * 1000.0);
            AudioSoundItem_adf080* iterator = sounds54.GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(iterator), (unsigned int *)&(soundHandle), (void **)&(pkSound));
                if (!(pkSound->GetFlags() & 0x20) && !(pkSound->GetFlags() & 4) && !(pkSound->GetFlags() & 0x800) &&
                    !(pkSound->GetFlags() & 0x100000))
                {
                    if (focus174)
                    {
                        FUN_00adb1a0(10, pkSound->GetID(), now, now + duration, AudioRef_adf080(),
                                     AudioVector_adf080(AudioSettingValue_adf080(&(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e80))), 0.0f, 0.0f));
                    }
                    else
                    {
                        FUN_00adb1a0(12, pkSound->GetID(), now, now + duration, AudioRef_adf080(),
                                     AudioVector_adf080(AudioSettingValue_adf080(&(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e80))), 0.0f, 0.0f));
                    }
                }
            }
            break;
        }
        case 10: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    UInt32 attenuation = (UInt32)(message->GetAudioPosition().x * 100.0);
                    UInt32 start = message->GetArgument1();
                    int uiEndTime = message->GetArgument2();
                    if (now >= uiEndTime)
                    {
                        pkSound->SetAttenuation20((UInt16)attenuation);
                    }
                    else if (now < uiEndTime)
                    {
                        pkSound->SetFade20((1.0 - (double)(uiEndTime - now) / (uiEndTime - start)) * attenuation);
                        FUN_00adb1a0(10, pkSound->GetID(), message->GetArgument1(), message->GetArgument2(),
                                     AudioRef_adf080(), message->GetAudioPosition());
                    }
                    pkSound->RefreshVolume();
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
                else if (!pkSound->Stopped10())
                {
                    FUN_00adb1a0(10, pkSound->GetID(), message->GetArgument1(), message->GetArgument2(),
                                 AudioRef_adf080(), message->GetAudioPosition());
                }
            }
            break;
        }
        case 12: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    UInt32 attenuation = (UInt32)(message->GetAudioPosition().x * 100.0);
                    UInt32 start = message->GetArgument1();
                    int uiEndTime = message->GetArgument2();
                    if (now >= uiEndTime)
                    {
                        pkSound->SetAttenuation20(0);
                    }
                    else if (now < uiEndTime)
                    {
                        pkSound->SetFade20((double)(uiEndTime - now) / (uiEndTime - start) * attenuation);
                        FUN_00adb1a0(12, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                     AudioRef_adf080(), message->GetAudioPosition());
                    }
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
                else if (!pkSound->Stopped10())
                {
                    FUN_00adb1a0(12, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                 AudioRef_adf080(), message->GetAudioPosition());
                }
            }
            break;
        }
        case 14: {
            pkItem = sounds54.GetFirst();
            while (pkItem)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(pkItem), (unsigned int *)&(uId), (void **)&(pkSound));
                if (pkSound)
                    pkSound->RefreshVolume();
            }
            break;
        }
        case 15: {
            break;
        }
        case 16: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v3c((float)(message->GetArgument1() / 1000.0));
                    FUN_00ada5d0(pkSound->GetID(), pkSound);
                }
                else if (!pkSound->Stopped10())
                {
                    FUN_00adb1a0(16, message->GetID(), message->GetArgument1(), 0, AudioRef_adf080(), NiPoint3_ZERO);
                }
            }
            break;
        }
        case 17: {
            break;
        }
        case 18: {
            break;
        }
        case 19: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                pkSound->v64((float)(message->GetArgument1() / 1000.0));
            }
            break;
        }
        case 66: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                pkSound->SetFrequencyScale((float)(message->GetArgument1() / 1000.0));
            }
            break;
        }
        case 20: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                pkSound->SetRandom40(true);
                pkSound->SetRandomPercent((UInt8)message->GetArgument1());
            }
            break;
        }
        case 21: {
            break;
        }
        case 22: {
            break;
        }
        case 7: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->SetAttenuation1c(10000);
                }
                else
                {
                    SoundMessageRecord* queued = ((::fnv_00adf080::SoundMessageRecord *)(reinterpret_cast<::fnv_00adaf80::BSAudioManager *>(this)->FUN_00adaf80()));
                    reinterpret_cast<::Msg_ae7990 *>((void *)&(const ::fnv_00adf080::SoundMessageRecord &)(*queued))->CopyFrom((const ::Msg_ae7990 &)(*message));
                    pkSound->QueueHead(queued);
                }
            }
            break;
        }
        case 8: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->SetAttenuation1c(0);
                }
                else
                {
                    SoundMessageRecord* queued = ((::fnv_00adf080::SoundMessageRecord *)(reinterpret_cast<::fnv_00adaf80::BSAudioManager *>(this)->FUN_00adaf80()));
                    reinterpret_cast<::Msg_ae7990 *>((void *)&(const ::fnv_00adf080::SoundMessageRecord &)(*queued))->CopyFrom((const ::Msg_ae7990 &)(*message));
                    pkSound->QueueHead(queued);
                }
            }
            break;
        }
        case 23: {
            break;
        }
        case 24: {
            UInt32 uiThreshold = message->GetID();
            UInt32 mask = message->GetArgument1();
            flags170 |= mask;
            int duration = message->GetArgument2();
            AudioSoundItem_adf080* iterator = sounds54.GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(iterator), (unsigned int *)&(soundHandle), (void **)&(pkSound));
                if ((pkSound->GetFlags() & mask) && !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                {
                    if (duration && uiThreshold > 5000)
                    {
                        FUN_00adb1a0(9, pkSound->GetID(), now, now + duration, AudioRef_adf080(), NiPoint3_ZERO);
                    }
                    else if (duration)
                    {
                        duration = duration;
                    }
                    else
                    {
                        reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(true);
                        pkSound->RefreshVolume();
                    }
                }
            }
            break;
        }
        break;
        case 25: {
            UInt32 mask = message->GetArgument1();
            flags170 &= ~mask;
            int duration = message->GetArgument2();
            AudioSoundItem_adf080* iterator = sounds54.GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(iterator), (unsigned int *)&(soundHandle), (void **)&(pkSound));
                if ((pkSound->GetFlags() & mask) && !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                {
                    if (duration)
                    {
                        FUN_00adb1a0(11, pkSound->GetID(), now, now + duration, AudioRef_adf080(), NiPoint3_ZERO);
                    }
                    else
                    {
                        reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(false);
                        pkSound->RefreshVolume();
                    }
                }
            }
            break;
        }
        break;
        case 26: {
            UInt32 mask = message->GetArgument1();
            reinterpret_cast<::AE6DE0Table *>(this)->AddSlot(mask, false);
            AudioSoundItem_adf080* iterator = sounds54.GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(iterator), (unsigned int *)&(soundHandle), (void **)&(pkSound));
                if (pkSound->v04() && (pkSound->GetFlags() & mask) && !(pkSound->GetFlags() & 0x800) &&
                    !(pkSound->GetFlags() & 0x100000) && !(pkSound->GetFlags() & 0x400000))
                {
                    pkSound->v34();
                }
                else if ((pkSound->GetFlags() & mask) && (pkSound->GetFlags() & 0x400000))
                {
                    reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(true);
                }
            }
            break;
        }
        break;
        case 27: {
            UInt32 mask = message->GetArgument1();
            AudioSoundItem_adf080* iterator = sounds54.GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(iterator), (unsigned int *)&(soundHandle), (void **)&(pkSound));
                if (!pkSound->Stopped10() && pkSound->v0c() && (pkSound->GetFlags() & mask) &&
                    !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000) &&
                    !(pkSound->GetFlags() & 0x400000))
                {
                    pkSound->v30(false);
                }
                else if ((pkSound->GetFlags() & mask) && (pkSound->GetFlags() & 0x400000))
                {
                    reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(false);
                }
            }
            reinterpret_cast<::FUN_00ae6e60_shell *>(this)->FUN_00ae6e60(mask, 0);
            break;
        }
        break;
        case 28: {
            UInt32 mask = message->GetArgument1();
            AudioSoundItem_adf080* iterator = sounds54.GetFirst();
            UInt32 soundHandle;
            reinterpret_cast<::AE6DE0Table *>(this)->AddSlot(mask, true);
            while (iterator)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(iterator), (unsigned int *)&(soundHandle), (void **)&(pkSound));
                if (!pkSound->v08() && pkSound->v04() && (pkSound->GetFlags() & mask) == mask &&
                    !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000) &&
                    !(pkSound->GetFlags() & 0x400000) && !(pkSound->GetFlags() & 0x2000) &&
                    !(pkSound->GetFlags() & 0x1000) && !pkSound->Stopped10())
                {
                    pkSound->v34();
                }
                else if ((pkSound->GetFlags() & mask) == mask &&
                         ((pkSound->GetFlags() & 0x400000) || (pkSound->GetFlags() & 0x1000) ||
                          (pkSound->GetFlags() & 0x2000)))
                {
                    reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(true);
                }
            }
            break;
        }
        break;
        case 29: {
            UInt32 mask = message->GetArgument1();
            AudioSoundItem_adf080* iterator = sounds54.GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(iterator), (unsigned int *)&(soundHandle), (void **)&(pkSound));
                if (!pkSound->Stopped10() && pkSound->v0c() && (pkSound->GetFlags() & mask) == mask &&
                    !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000) &&
                    !(pkSound->GetFlags() & 0x400000) && !(pkSound->GetFlags() & 0x1000) &&
                    !(pkSound->GetFlags() & 0x2000) && !(pkSound->GetFlags() & 0x1000))
                {
                    pkSound->v30(false);
                }
                else if ((pkSound->GetFlags() & mask) == mask &&
                         ((pkSound->GetFlags() & 0x400000) || (pkSound->GetFlags() & 0x1000) ||
                          (pkSound->GetFlags() & 0x1000) || (pkSound->GetFlags() & 0x2000)))
                {
                    reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(false);
                }
            }
            reinterpret_cast<::FUN_00ae6e60_shell *>(this)->FUN_00ae6e60(mask, 1);
            break;
        }
        break;
        case 30: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                AudioVector_adf080 value = message->GetAudioPosition();
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v4c(value);
                }
                else
                {
                    SoundMessageRecord* queued4 = 0;
                    AudioMessageList_adf080* kQueued = &pkSound->messages;
                    AudioMessageNode_adf080* iterator = 0;
                    bool foundTmp = false;
                    iterator = kQueued->GetHead();
                    while (iterator && !foundTmp)
                    {
                        queued4 = kQueued->GetNext(iterator);
                        if (queued4 && queued4->GetType() == 30)
                        {
                            reinterpret_cast<::Msg_ae7990 *>((void *)&(const ::fnv_00adf080::SoundMessageRecord &)(*queued4))->CopyFrom((const ::Msg_ae7990 &)(*message));
                            foundTmp = true;
                        }
                    }
                    if (!foundTmp)
                    {
                        queued4 = ((::fnv_00adf080::SoundMessageRecord *)(reinterpret_cast<::fnv_00adaf80::BSAudioManager *>(this)->FUN_00adaf80()));
                        reinterpret_cast<::Msg_ae7990 *>((void *)&(const ::fnv_00adf080::SoundMessageRecord &)(*queued4))->CopyFrom((const ::Msg_ae7990 &)(*message));
                        pkSound->QueueHead(queued4);
                    }
                }
            }
            break;
        }
        case 31: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                AudioVector_adf080 value = message->GetAudioPosition();
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->SetReferenceVector(value);
                }
                else if (!pkSound->Stopped10())
                {
                    AudioRef_adf080 object;
                    object.operator=(message->object);
                    FUN_00adb1a0(31, message->GetID(), message->GetArgument1(), message->GetArgument2(), object,
                                 message->GetAudioPosition());
                    message->SetObject(0);
                }
            }
            break;
        }
        case 32: {
            break;
        }
        case 33: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                UInt16 value = (UInt16)message->GetArgument1();
                pkSound->SetAttenuation18(value);
            }
            break;
        }
        case 34: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                UInt16 value = (UInt16)message->GetArgument1();
                pkSound->SetAttenuation1a(value);
            }
            break;
        }
        case 35: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                float duration = (float)(message->GetArgument2() / 1000.0);
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v5c((float)(message->GetArgument1() / 1000.0), duration);
                }
                else if (!pkSound->Stopped10())
                {
                    FUN_00adb1a0(35, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                 AudioRef_adf080(), NiPoint3_ZERO);
                }
            }
            break;
        }
        case 36: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v60(message->GetShort(0), message->GetShort(1), message->GetShort(2), message->GetShort(3),
                                 message->GetShort(4));
                }
                else
                {
                    FUN_00adbb30(message->GetID(), message->GetShort(0), message->GetShort(1), message->GetShort(2),
                                 message->GetShort(3), message->GetShort(4));
                }
            }
            break;
        }
        case 40: {
            NiPoint3 origin;
            AudioRef_adf080 object;
            AudioRefItem_adf080* iterator = objects84.GetFirst();
            UInt32 uiID;
            while (iterator)
            {
                reinterpret_cast<::nae7::Map *>(&(objects84))->FUN_00ae7ee0((::nae7::Item *&)(iterator), uiID, (::nae7::Val &)(object));
                reinterpret_cast<::RMapBase *>(&(objects84))->FUN_00a1e240(uiID);
                if (object->GetRefCount() == 1)
                    FUN_00c45830(object);
                object.operator=(0);
                reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(uiID, (::S_00adc830_Entry *&)(pkSound));
                if (pkSound)
                {
                    pkSound->v38();
                    pkSound->Set10(true);
                    pkSound->Set200(false);
                }
            }
            break;
        }
        case 41: {
            NiPoint3 navPos;
            AudioRef_adf080 target;
            target.operator=(message->object);
            AudioRef_adf080 object;
            int mask = message->GetArgument2();
            AudioRefItem_adf080* aPos = objects84.GetFirst();
            UInt32 uiID;
            while (aPos)
            {
                reinterpret_cast<::nae7::Map *>(&(objects84))->FUN_00ae7ee0((::nae7::Item *&)(aPos), uiID, (::nae7::Val &)(object));
                if (object == target)
                {
                    reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(uiID, (::S_00adc830_Entry *&)(pkSound));
                    if (pkSound)
                    {
                        if (!mask || (mask && (mask & pkSound->GetFlags())))
                            pkSound->v38();
                        if ((pkSound->GetFlags() && 0x2000000) || (pkSound->GetFlags() && 0x4000000))
                            pkSound->SetFlags(pkSound->GetFlags() | 0x100);
                    }
                }
            }
            break;
        }
        case 42: {
            UInt32 mask = message->GetArgument1();
            AudioSoundItem_adf080* iterator = sounds54.GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(iterator), (unsigned int *)&(soundHandle), (void **)&(pkSound));
                if ((pkSound->GetFlags() & mask) && !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                {
                    pkSound->v38();
                    pkSound->Set200(false);
                    pkSound->Set10(true);
                }
            }
            break;
        }
        case 43: {
            break;
        }
        case 44: {
            break;
        }
        case 45: {
            break;
        }
        case 46: {
            break;
        }
        case 47: {
            break;
        }
        case 48: {
            break;
        }
        case 49: {
            break;
        }
        case 50: {
            break;
        }
        case 51: {
            pkSound = (BSGameSound*)message->GetArgument2();
            if (pkSound)
            {
                reinterpret_cast<::Owner *>(this)->AddSound((::Sound *)(pkSound));
                delete pkSound;
            }
            break;
        }
        case 52: {
            messageStack44.FUN_00ae75f0(message);
            if (IsMultiThreaded_adf080(GetAudio_adf080()) && GetThreadID_adf080() == threadId138 && thread13c)
            {
                DAT_011f6d98->bIsMultiThreaded = false;
                reinterpret_cast<::BSAudioManagerThread *>((thread13c))->FUN_00ae7ac0();
            }
            break;
        }
        case 53: {
            messageStack44.FUN_00ae75f0(message);
            if (IsMultiThreaded_adf080(GetAudio_adf080()) && GetThreadID_adf080() == threadId138 && thread13c)
            {
                DAT_011f6d98->bIsMultiThreaded = false;
                LeaveCriticalSection(&critical0f4);
                reinterpret_cast<::AudioWorker *>((thread13c))->FUN_00ae7a50();
                EnterCriticalSection(&critical0f4);
                bWasPlaying = true;
            }
            else if (GetThreadID_adf080() != threadId138)
            {
                DebugBreak();
            }
            break;
        }
        break;
        case 54: {
            break;
        }
        case 55: {
            AudioSoundItem_adf080* iterator = sounds54.GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                reinterpret_cast<::RecursiveLock *>(&(sounds54))->Unlock((::BSCriticalSectionEntry **)&(iterator), (unsigned int *)&(soundHandle), (void **)&(pkSound));
                if (!pkSound->Stopped10() && (pkSound->Alternate0c() || pkSound->Alternate1000()))
                    reinterpret_cast<::FUN_00ae8b90_cls *>((pkSound))->SetFlagAndApplyValue(alternate175);
            }
            break;
        }
        break;
        case 56: {
            AudioVector_adf080 value = message->GetAudioPosition();
            if (GetListener_adf080(GetAudio_adf080()))
            {
                GetListener_adf080(GetAudio_adf080())->v08(value);
                listenerDirty135 = true;
            }
            break;
        }
        case 57: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v48(message->GetArgument1());
                }
                else if (!pkSound->Stopped10())
                {
                    FUN_00adb1a0(57, message->GetID(), message->GetArgument1(), 0, AudioRef_adf080(), NiPoint3_ZERO);
                }
            }
            break;
        }
        case 65: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
                pkSound->Set188(message->GetArgument1());
            break;
        }
        case 60: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready100())
                {
                    pkSound->Set15c(message->GetArgument1());
                }
                else if (!pkSound->Stopped10())
                {
                    FUN_00adb1a0(60, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                 AudioRef_adf080(), NiPoint3_ZERO);
                }
            }
            break;
        }
        case 61: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                if (pkSound->Ready100())
                {
                    pkSound->Clear15c();
                }
                else if (!pkSound->Stopped10())
                {
                    FUN_00adb1a0(61, message->GetID(), message->GetArgument1(), message->GetArgument2(),
                                 AudioRef_adf080(), NiPoint3_ZERO);
                }
            }
            break;
        }
        case 62: {
            if (reinterpret_cast<::S_00adc830_Map *>(&(sounds54))->GetAt(message->GetID(), (::S_00adc830_Entry *&)(pkSound)) && pkSound)
            {
                pkSound->Set28(message->GetArgument1());
                pkSound->Set2c((UInt16)message->GetArgument2());
            }
            break;
        }
        }
    }
    return bWasPlaying;
}
}

namespace fnv_00adddd0 {

}

namespace fnv_00adddd0 {

}




struct ObjEntry
{
    char unk0[0x144];
    int m_144;
    int m_148;
};

struct ObjNode
{
    ObjNode* m_pNext;
    int unk4;
    ObjEntry* m_pEntryObject;
};

struct ObjRegistry
{
    char unk0[0x94];
    ObjNode* m_pHead;
    char unk98[0xdc - 0x98];
    CritSecA m_kCS;

    bool FUN_00add480(int m_uiSoundID, bool bCheckAlt);
};

struct OwnerQ3 : ObjRegistry
{
    char padf4[0x180 - 0xf4];
    int m_iNextID;
    void FUN_00add6f0(const char* pPath, int iFlags, std::intptr_t iArg);
};

struct BSSoundMsg70;

struct MemoryManager
{
    void Deallocate(void*);
};

template <typename T> struct NiTPointerAllocator
{
    void Deallocate(void*);
};

namespace fnv_00ae8f20 {
struct MemoryManager
{
};
}

struct BSSoundMsg70
{
    int m_iWordAt00;
    void FUN_00ae86d0();
    ~BSSoundMsg70()
    {
        FUN_00ae86d0();
    }
};

struct StackNode70
{
    StackNode70* next;
    StackNode70* prev;
    BSSoundMsg70* value;
};

struct SndStack70
{
    StackNode70* head;
    StackNode70* tail;
    unsigned int count;
    bool IsEmpty()
    {
        return count == 0;
    }
    BSSoundMsg70* FUN_00ae7f90()
    {
        StackNode70* node = head;
        head = head->next;
        if (head)
            head->prev = 0;
        else
            tail = 0;
        BSSoundMsg70* value = node->value;
        node->value = 0;
        reinterpret_cast<::FUN_0045cee0_shell *>((((NiTPointerAllocator<unsigned int>*)&count)))->FUN_0045cee0(node);
        --count;
        return value;
    }
};


struct V;

extern int DAT_010a3328, DAT_010a3348;

extern "C" void __cdecl FUN_00a1bbd0();

struct StackView
{
    int offset_00, offset_04, offset_08, offset_0c;
    void FUN_00ae7550();
    ~StackView()
    {
        FUN_00ae7550();
    }
};







struct CSView : CRITICAL_SECTION
{
    ~CSView()
    {
        DeleteCriticalSection(this);
    }
};

template <int* V, int Pad> struct ContainerBase
{
    int offset_04;
    void* offset_08;
    int offset_0c;
    void ClearAll();
    virtual ~ContainerBase()
    {
        ReserveFrame<Pad>();
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(offset_08);
    }
};

template <int* V, int* B, int Pad = 1> struct ContainerView : ContainerBase<B, Pad>
{
    virtual ~ContainerView()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

struct ArrayView
{
    int offset_00, offset_04, offset_08, offset_0c, offset_10, offset_14;
    ~ArrayView()
    {
        fnv::crt::vector_destructor(this, 12, 2, (void (*)(void *))(FUN_00a1bbd0));
    }
};

struct FUN_00ad93f0
{
    int offset_04, offset_08;
    ArrayView offset_0c;
    StackView offset_24, offset_34, offset_44;
    ContainerView<&DAT_010a3348, &DAT_010a3370> offset_54;
    ContainerView<&DAT_010a3328, &DAT_010a3390, 2> offset_64;
    ContainerView<&DAT_010a3328, &DAT_010a3390> offset_74;
    ContainerView<&DAT_010a3308, &DAT_010a33b0> offset_84;
    ListView<1> offset_94;
    int offset_a0, offset_a4, offset_a8;
    CSView offset_ac, offset_c4, offset_dc, offset_f4, offset_10c;
    ListView<0> offset_124;
    virtual ~FUN_00ad93f0();
};










namespace fnv_00adaf80 {

}



namespace fnv_00adad60 {

}

namespace fnv_00adad60 {

}











struct NiRefObjStub
{
    void* vtbl;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};

struct NiAVObjPtr
{
    NiRefObjStub* m_pObject;
    NiAVObjPtr(NiRefObjStub* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiAVObjPtr();
};

struct BSAudioMgr : BSAudioManager
{
    bool IsPlaying(unsigned int);
    void PostMsg(int eMsg, unsigned int id, int a3, int a4, NiAVObjPtr obj, NiPoint3 pos);
    void FUN_00adc670(int id, int param);
};



namespace fnv_00ada0f0 {

}

namespace fnv_00ada0f0 {
struct NiRefObjStub
{
    void* vtbl;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};
}

namespace fnv_00ada0f0 {
struct NiAVObjPtr
{
    NiRefObjStub* m_pObject;
    NiAVObjPtr(NiRefObjStub* p = 0)
    {
        int m_uiChunkSize;
        m_pObject = p;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiAVObjPtr();
};
}

struct ContactList;
struct Entry48;
struct Entry;
struct Flt;
struct Groups;
struct Input;

struct Link;
struct Param;
struct Sink;

struct TESIdleForm;
template <class, class> struct NiTPrimitiveArray;
template <class> struct NiTMallocInterface;
struct M;
struct R;
struct StrArray;
struct Tile;

namespace fnv_00adaf80 {  }

// @fnv 0x0072fa80
int __cdecl FUN_0072fa80(int param_1)
{
    return std::abs(param_1);
}



struct FUN_00ad8d60_shell
{
    int m_uiSoundResourceID;
    int pad;
    int eState;
    bool FUN_00ad8d60(int param2);
};

// @fnv 0x00ad8d60
bool FUN_00ad8d60_shell::FUN_00ad8d60(int aiParam)
{
    if (m_uiSoundResourceID == 0xffffffff)
    {
        return false;
    }
    eState = 1;
    reinterpret_cast<::BSAudioMgr *>(&(BSAudioManager::GetRandomGenerator()))->FUN_00adc670(m_uiSoundResourceID, aiParam);
    return true;
}

// The pad stands for the BSAudioManager members before these two.
struct FUN_00ada300_shell
{
    char pad00[0xa4];
    int m_iA4;
    float m_fA8;
    void FUN_00ada300(float fval, int param);
};

// Stores param in m_iA4 and fval in m_fA8.
// @fnv 0x00ada300
void FUN_00ada300_shell::FUN_00ada300(float fval, int param)
{
    m_iA4 = param;
    m_fA8 = fval;
}

namespace fnv_00adad60 {



// @fnv 0x00adad60
void BSAudioManager::FUN_00adad60()
{
    reinterpret_cast<::fnv_00ae76b0::Pool_ae76b0 *>(&m_aiEntries)->FUN_00ae76b0();
}
}  // namespace fnv_00adad60

namespace fnv_00adaf80 {






// @fnv 0x00adaf80
SoundMessageRecord* BSAudioManager::FUN_00adaf80()
{
    return ((::fnv_00adaf80::SoundMessageRecord *)(reinterpret_cast<::fnv_00ae76b0::Pool_ae76b0 *>((&m_kRecordPool))->FUN_00ae76b0()));
}
}  // namespace fnv_00adaf80

struct FUN_00adb960_shell
{
    bool FUN_00adb960(int arg1, int arg2);
};

// @fnv 0x00adb960
bool FUN_00adb960_shell::FUN_00adb960(int arg1, int arg2)
{
    return false;
}

struct FUN_00adbf40_shell
{
    bool FUN_00adbf40(float f1, float f2, float f3, float f4);
};

// @fnv 0x00adbf40
bool FUN_00adbf40_shell::FUN_00adbf40(float f1, float f2, float f3, float f4)
{
    return false;
}

struct FUN_00c3d0e0_stub
{
};

struct FUN_00ae7480_shell : FUN_00c3d0e0_stub
{
    bool FUN_00ae7480(char* apDescription, unsigned int aiBufferSize);
};

// @fnv 0x00ae7480
bool FUN_00ae7480_shell::FUN_00ae7480(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>((this))->FUN_00c3d0e0(apDescription, aiBufferSize, "audio load task");
}

struct FUN_00adcaa0_shell
{
};

struct FUN_00ad84b0_shell
{
    void FUN_00ad84b0(int param_2, int param_3);
};

// Forwards the two arguments to BSAudioManager's FUN_00adcaa0.
// @fnv 0x00ad84b0
void FUN_00ad84b0_shell::FUN_00ad84b0(int param_2, int param_3)
{
    reinterpret_cast<::fnv_00adcaa0::FUN_00adcaa0_cls *>((((FUN_00adcaa0_shell*)&BSAudioManager::GetRandomGenerator())))->FUN_00adcaa0(param_2, param_3);
}

struct FUN_00adcc10_shell
{
    void FUN_00adcc10(int, int);
};
struct FUN_00ad8540_shell
{
    void FUN_00ad8540(int param1, bool param2);
};
// Forwards param1 and param2 to the BSAudioManager method FUN_00adcc10.
// @fnv 0x00ad8540
void FUN_00ad8540_shell::FUN_00ad8540(int param1, bool param2)
{
    ((FUN_00adcc10_shell*)&BSAudioManager::GetRandomGenerator())->FUN_00adcc10(param1, param2);
}

struct S_00ae5f70
{
    int f0;
    char f4;
    int f8;
};
struct C_00ae5f70
{
    S_00ae5f70* Init(S_00ae5f70* p, int a2, int a3, int a4, int a5, int a6, int a7);
};
// Initializes the object: sets f0 to -1, f4 and f8 to 0, and returns the object pointer.
// @fnv 0x00ae5f70
S_00ae5f70* C_00ae5f70::Init(S_00ae5f70* pObject, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int i = 0;
    pObject->f0 = -1;
    pObject->f4 = 0;
    pObject->f8 = 0;
    i |= 1;
    return pObject;
}

// Compares the unsigned ints pointed to by a and b, returning -1 if the first is smaller, 1 if larger, else 0.
// @fnv 0x00ae5fb0
int __cdecl FUN_00ae5fb0(unsigned int* puiLeft, unsigned int* puiRight)
{
    unsigned int v1 = *puiLeft;
    unsigned int v2 = *puiRight;
    return v1 < v2 ? -1 : v1 > v2;
}

extern int DAT_011f6ecc;
struct FUN_00ae6c60_shell
{
    int FUN_00ae6c60();
};
// @fnv 0x00ae6c60
int FUN_00ae6c60_shell::FUN_00ae6c60()
{
    int* p = &(*reinterpret_cast<int *>(&::g_011f6ec8)) ? &DAT_011f6ecc : (DAT_01202800 = 0, &DAT_01202800);
    return *p;
}

namespace fnv_00ae6ca0 {
struct BSAudioManager_shell : BSAudioManager
{
    void AddSound(int arg2);
    void FUN_00ae6ca0(bool enable);
};
// Stores enable into a global flag and, when disabling, calls AddSound(0).
// @fnv 0x00ae6ca0
void BSAudioManager_shell::FUN_00ae6ca0(bool enable)
{
    char* target = &(*reinterpret_cast<int *>(&::g_011f6ebc)) ? (char*)&(*reinterpret_cast<int *>(&::fnv_00ae6cf0::DAT_011f6ec0)) : ((void)((*reinterpret_cast<char *>(&::DAT_01202800)) = 0), (char*)&(*reinterpret_cast<char *>(&::DAT_01202800)));
    *target = enable;
    if (!enable)
        AddSound(0);
}
}  // namespace fnv_00ae6ca0

namespace fnv_00ae6cf0 {
struct FUN_00ae6cf0_shell
{
    bool FUN_00ae6cf0();
};
// @fnv 0x00ae6cf0
bool FUN_00ae6cf0_shell::FUN_00ae6cf0()
{
    bool* mode = &(*reinterpret_cast<int *>(&::g_011f6ebc)) ? &DAT_011f6ec0 : ((*reinterpret_cast<bool *>(&::DAT_01202800)) = 0, &(*reinterpret_cast<bool *>(&::DAT_01202800)));
    return *mode;
}
}  // namespace fnv_00ae6cf0

extern int DAT_010a3718;

struct _Base_00441d20
{
    _Base_00441d20();
    ~_Base_00441d20();
};

// The pad stands for members not named yet.
struct FUN_00ae7020_shell : _Base_00441d20
{
    void* m_pVtbl;
    char pad04[0x2c];
    int m_i30;
    void FUN_00ae7020();
};

// Sets the vtable pointer to DAT_010a3718, touches m_i30, then calls the base destructor.
// @fnv 0x00ae7020
void FUN_00ae7020_shell::FUN_00ae7020()
{
    m_pVtbl = &DAT_010a3718;
    m_i30 = m_i30;
    reinterpret_cast<::fnv_00c3cea0::FUN_00c3cea0 *>(this)->fnv_00c3cea0::FUN_00c3cea0::~FUN_00c3cea0();
}



struct FUN_00ae7510_shell : public BottomlessStack
{
    void FUN_00ae7510();
};

struct FUN_00ae7510 : public BottomlessStack
{
    FUN_00ae7510();
};
// Initializes the stack: clears the count, top pointer, bottomless flag and the extra field.
// @fnv 0x00ae7510
FUN_00ae7510::FUN_00ae7510()
{
    iCount = 0;
    pTop = 0;
    m_bBottomless = false;
    m_uiStackLimit = 0;
}


struct FUN_00ad93f0_shell
{
    void FUN_00ad93f0(void);
};
struct FUN_00ae77a0_shell : FUN_00ae7480_shell
{
    void* FUN_00ae77a0(unsigned int flags);
};
// Calls FUN_00ad93f0 on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00ae77a0
void* FUN_00ae77a0_shell::FUN_00ae77a0(unsigned int flags)
{
    reinterpret_cast<::FUN_00ad93f0 *>((((FUN_00ad93f0_shell*)this)))->FUN_00ad93f0::~FUN_00ad93f0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::MemoryManager * *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

namespace fnv_00ae7870 {
struct P03MM
{
    void DeallocateAlias(void*);
};

struct FUN_00ae7870_shell
{
    void* FUN_00ae7870(unsigned int flags);
};

// @fnv 0x00ae7870
void* FUN_00ae7870_shell::FUN_00ae7870(unsigned int flags)
{
    reinterpret_cast<::FUN_00ae78a0_cls *>(this)->FUN_00ae78a0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((P03MM*)&(*reinterpret_cast<::fnv_00ae7870::P03MM * *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00ae7870

namespace fnv_00ae7b10 {
struct MemoryManager
{
};
void __cdecl DeallocateAlias(void*);
struct FUN_00ae7020_shell
{
};
struct AudioLoadTask : FUN_00ae7020_shell
{
    void* FUN_00ae7b10(unsigned int flags);
};
// Calls FUN_00ae7020, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00ae7b10
void* AudioLoadTask::FUN_00ae7b10(unsigned int flags)
{
    reinterpret_cast<::FUN_00ae7020_shell *>(this)->FUN_00ae7020();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae7b10::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00ae7b10

struct GO
{
    void* m_pObject;
    GO& operator=(void*);
};
// A list node whose item FUN_00ae8ef0 clears.
struct GONode
{
    void* m_pNext;
    void* m_pPrev;
    GO m_kItem;
};

struct Host00ae8ef0
{
    char _p[12];
    NiTPointerAllocator<unsigned int> alloc;
    void FUN_00ae8ef0(void* p);
};
// Clears the item of node p, then deallocates p through the allocator.
// @fnv 0x00ae8ef0
void Host00ae8ef0::FUN_00ae8ef0(void* p)
{
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    ((GONode*)p)->m_kItem.operator=(0);
    reinterpret_cast<::FUN_0045cee0_shell *>(&(alloc))->FUN_0045cee0(p);
}

namespace fnv_00ae8f20 {

struct S00a0d390
{
    int _0;
    int _4;
    void* _8;
    void* FUN_00ae8f20(int);
};
// @fnv 0x00ae8f20
void* S00a0d390::FUN_00ae8f20(int aiFlags)
{
    int _u1;
    int _u2;
    *(void**)this = (void*)&::DAT_010a3370;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(_8);
    if (aiFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae8f20::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    (void)_u1;
    (void)_u2;
    return this;
}
}  // namespace fnv_00ae8f20

namespace fnv_00ae9010 {
struct MemoryManager
{
};
struct S00a0d390
{
};
struct FUN_00ae9010Owner
{
    void* f0;
    int f4;
    void* f8;
    void* DestroyOwner(int);
};
// @fnv 0x00ae9010
void* FUN_00ae9010Owner::DestroyOwner(int aiFlags)
{
    int x;
    int y;
    *(void**)this = (void*)&::DAT_010a3390;
    reinterpret_cast<::AE91F0Map *>((((S00a0d390*)this)))->ClearAll();
    ::FUN_00aa10f0(f8);
    if (aiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae9010::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00ae9010

namespace fnv_00ae9100 {
struct S00a0d390
{
    void* _00;
    int _04;
    void* _08;
    void* FUN_00ae9100(unsigned int);
};
struct MemoryManager
{
};
// Sets the vtable, calls ClearAll, frees _08 via _NiFreeAlias, and deallocates this when flag bit 0 is set.
// @fnv 0x00ae9100
void* S00a0d390::FUN_00ae9100(unsigned int auiFlags)
{
    int d1;
    int d2;
    *(void**)this = (void*)&::DAT_010a33b0;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(_08);
    if (auiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae9100::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00ae9100

struct AudioLoadTask
{
    int _pad[12];
    void* SoundAssetTmp;
    void FUN_00ae7360();
};
struct Helper
{
};
struct BSAudioDefinition
{
    BSAudioDefinition();
    ~BSAudioDefinition();
public:
    ::BSAudioDefinition &operator=(const ::BSAudioDefinition &);
};
struct FUN_00ae89f0
{
    unsigned int m_uiSoundID;
    float m_fSoundVolume;
    int _08;
    unsigned int m_uiValueAt0C;
    unsigned int m_uiPlaybackFlags;
    bool m_bValueAt14;
    char _pad[3];
    BSAudioDefinition _18;
    FUN_00ae89f0();
};
// @fnv 0x00ae89f0
FUN_00ae89f0::FUN_00ae89f0()
{
    m_uiSoundID = 0;
    m_fSoundVolume = 0.0f;
    m_uiValueAt0C = 0;
    m_uiPlaybackFlags = 0;
    m_bValueAt14 = 0;
}


struct AudioVolumes_00ad9da0
{
    float fVal[6];
    float fMult[6];
};
// The pad stands for the BSAudioManager members before the volumes.
struct FUN_00ad9da0_t
{
    char pad00[0x140];
    AudioVolumes_00ad9da0 m_kVolumes;
    void InitAudioVolumes();
};

// Copies the six setting values into m_kVolumes.fVal and sets all six fMult entries to 1.0.
// @fnv 0x00ad9da0
void FUN_00ad9da0_t::InitAudioVolumes()
{
    float* r0 = &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e14)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e14)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
    m_kVolumes.fVal[0] = *r0;
    {
        float* r1 = &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e20)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e20)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
        m_kVolumes.fVal[1] = *r1;
        {
            float* r2 = &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e2c)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e2c)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
            m_kVolumes.fVal[2] = *r2;
            {
                float* r3 = &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e38)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e38)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                m_kVolumes.fVal[3] = *r3;
                {
                    float* r4 =
                        &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e44)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e44)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                    m_kVolumes.fVal[4] = *r4;
                    {
                        float* r5 =
                            &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e50)) ? &(*reinterpret_cast<::Setting_00ad9da0 *>(&::g_011f6e50)).fValue : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                        m_kVolumes.fVal[5] = *r5;
                    }
                }
            }
        }
    }
    m_kVolumes.fMult[0] = 1.0f;
    m_kVolumes.fMult[1] = 1.0f;
    m_kVolumes.fMult[2] = 1.0f;
    m_kVolumes.fMult[3] = 1.0f;
    m_kVolumes.fMult[4] = 1.0f;
    m_kVolumes.fMult[5] = 1.0f;
}


// @fnv 0x00ae6d30
bool FUN_00ae6d30_shell::HasMatchingEntry(unsigned int mask)
{
    AE6DE0Table* table = reinterpret_cast<AE6DE0Table*>(this);
    unsigned int i = 0;
    for (; i < table->m_uiSlotCount; ++i)
    {
        if (table->m_pkSlots[i].m_usState == 1 && (mask & table->m_pkSlots[i].m_uiMask) == table->m_pkSlots[i].m_uiMask)
            return true;
        else if (table->m_pkSlots[i].m_usState == 2 && (mask & table->m_pkSlots[i].m_uiMask))
            return true;
    }
    return false;
}


// @fnv 0x00ae6e60
bool FUN_00ae6e60_shell::FUN_00ae6e60(int param_2, unsigned char abMatchStateOne)
{
    AE6DE0Table* table = reinterpret_cast<AE6DE0Table*>(this);
    int i = 0;
    for (; i < table->m_uiSlotCount; ++i)
    {
        if (param_2 == (int)table->m_pkSlots[i].m_uiMask &&
            ((!abMatchStateOne && table->m_pkSlots[i].m_usState == 2) ||
             (abMatchStateOne && table->m_pkSlots[i].m_usState == 1)))
        {
            table->m_pkSlots[i].m_usState = 0;
            table->m_pkSlots[i].m_uiMask = 0;
            return true;
        }
    }
    return false;
}

struct SoundEmitter;
struct AudioLoadTask;





struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};





extern char $SG6265[];

struct FUN_00ada330_shell
{
};

struct FUN_00addc00_shell
{
};

struct FUN_00ada1d0_shell
{
    unsigned char _pad[0x134];
    bool m_bUISoundsEnabled;
    void InitUISounds(bool);
};

struct BADC7D0Item
{
    unsigned int m_uiKey;
};

class BADC7D0Map
{
  public:
};

class BADC7D0Cache
{
  public:
    bool ContainsKey(unsigned int uiKey);

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
    BADC7D0Map m_kUnsortedGeometryList;
};

// Looks up uiKey in the map and returns true if an item is found whose key equals uiKey.
// @fnv 0x00adc7d0
bool BADC7D0Cache::ContainsKey(unsigned int uiKey)
{
    bool bFound4 = false;
    BADC7D0Item* pkItem9 = 0;
    reinterpret_cast<::S_00adc830_Map *>(&(m_kUnsortedGeometryList))->GetAt(uiKey, (::S_00adc830_Entry *&)(pkItem9));
    if (pkItem9)
    {
        void* pvX;
        void* pvUnusedB;
        unsigned int uiItemKey = pkItem9->m_uiKey;
        if (uiItemKey == uiKey)
            bFound4 = true;
    }
    if (!bFound4)
        bFound4 = bFound4;
    return bFound4;
}









// @fnv 0x00add480
bool ObjRegistry::FUN_00add480(int m_uiSoundID, bool bCheckAlt)
{
    if (m_uiSoundID == 0)
        return false;
    EnterCriticalSection(&m_kCS);
    bool bFound = false;
    ObjNode* pNode = m_pHead;
    while (pNode)
    {
        ObjEntry* pEntry = pNode->m_pEntryObject;
        if (pEntry)
        {
            if ((bool)(int)(m_uiSoundID == pEntry->m_144) ||
                (bCheckAlt && (int)(unsigned char)(m_uiSoundID == pEntry->m_148 && pEntry->m_148 ? 1 : 0)))
            {
                bFound = true;
                break;
            }
        }
        pNode = pNode ? pNode->m_pNext : 0;
    }
    LeaveCriticalSection(&m_kCS);
    return bFound;
}


extern int DAT_011f6ecc;

struct AudioCacheOwner
{
    void SetAudioCacheSize(int size);
};

// Sets the audio cache size when it is below 0x1000, otherwise logs an error; a size of 0 also calls FUN_00ae6ca0(0).
// @fnv 0x00ae6bf0
void AudioCacheOwner::SetAudioCacheSize(int size)
{
    if (size == 0)
    {
        reinterpret_cast<::fnv_00ae6ca0::BSAudioManager_shell *>(this)->FUN_00ae6ca0(0);
    }
    if ((unsigned int)size < 0x1000)
    {
        int* piCacheSize = (&(*reinterpret_cast<int *>(&::g_011f6ec8)) != 0) ? &DAT_011f6ecc : (DAT_01202800 = 0, &DAT_01202800);
        *piCacheSize = size;
    }
    else
    {
        ::FUN_005b5e40();
    }
}





// Finds the first slot with state 0, sets its state to 1 or 2 depending on bPrimary, stores uiMask in it, and returns true; returns false if no free slot exists.
// @fnv 0x00ae6de0
bool AE6DE0Table::AddSlot(unsigned int uiMask, bool bPrimary)
{
    for (unsigned int i = 0; i < m_uiSlotCount; i++)
    {
        if (m_pkSlots[i].m_usState == 0)
        {
            m_pkSlots[i].m_usState = bPrimary ? 1 : 2;
            m_pkSlots[i].m_uiMask = uiMask;
            return true;
        }
    }
    return false;
}






// @fnv 0x00ae6f50
FUN_00ae6f50::FUN_00ae6f50(void* aValue) : BaseObj_b5112(0)
{
    m_30 = aValue;
    char buf[0x104];
    ::CopyRelativeDataPath(((const GameSoundFilenameView*)m_30)->m_acFilename, buf, 0x104);
    reinterpret_cast<::FUN_00c3cee0_shell *>(this)->FUN_00c3cee0(buf);
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>(this)->LookupFileEntryByArchive(3);
}

struct Sound7390
{
    virtual void* ScalarDeletingDestructor(unsigned int);
    int unk04;
    unsigned int uiFlags08;
    int unk0C;
    unsigned int uiFlags10;
};
struct AudioLoadTask7390
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    Sound7390* SoundAssetTmp;
    void ReleaseSound(int, int);
};
struct AudioHelper7390
{
};




// @fnv 0x00ae7990
Msg_ae7990& Msg_ae7990::CopyFrom(const Msg_ae7990& aOther)
{
    int j;
    int e;
    unsigned int uiShortIndex;
    unsigned int p;
    unk00 = aOther.unk00;
    unk04 = aOther.unk04;
    unk08 = aOther.unk08;
    unk0c = aOther.unk0c;
    ptr10 = aOther.ptr10;
    for (p = 0; p < 3; ++p)
    {
        f14[p] = aOther.f14[p];
    }
    for (uiShortIndex = 0; uiShortIndex < 5; ++uiShortIndex)
    {
        s14[uiShortIndex] = aOther.s14[uiShortIndex];
    }
    return *this;
}

struct AE8470Item;

struct AE8470List
{
    AE8470Item* m_pkItem;
    AE8470List* m_pkNext;

    void SortList(int(__cdecl* pfnCompare)(AE8470Item*, AE8470Item*));
};

// Bubble-sorts the linked list by swapping item pointers using pfnCompare, counting non-null items to bound the passes.
// @fnv 0x00ae8470
void AE8470List::SortList(int(__cdecl* pfnCompare)(AE8470Item*, AE8470Item*))
{
    AE8470List* pkCur8 = this;
    AE8470List* pkPrev4 = 0;
    if (pkCur8)
    {
        int iPasses;
        AE8470Item* pkCurItem;
        AE8470Item* pkPrevItemTmp;
        {
            int iCount = 0;
            AE8470List* pkIter3 = pkCur8;
            while (pkIter3)
            {
                if (pkIter3->m_pkItem)
                    iCount++;
                pkIter3 = pkIter3->m_pkNext;
            }
            iPasses = iCount;
        }
        bool bSwapped = true;
        while (iPasses && bSwapped)
        {
            bSwapped = false;
            while (pkCur8)
            {
                if (pkPrev4)
                {
                    pkCurItem = pkCur8->m_pkItem;
                    pkPrevItemTmp = pkPrev4->m_pkItem;
                    if (pfnCompare(pkPrevItemTmp, pkCurItem) > 0)
                    {
                        if (!pkPrevItemTmp)
                        {
                        }
                        else
                        {
                            pkCur8->m_pkItem = pkPrevItemTmp;
                        }
                        if (!pkCurItem)
                        {
                        }
                        else
                        {
                            pkPrev4->m_pkItem = pkCurItem;
                        }
                        bSwapped = true;
                    }
                }
                pkPrev4 = pkCur8;
                pkCur8 = pkCur8->m_pkNext;
            }
            iPasses--;
        }
    }
}

struct FUN_00ae8550_shell
{
    void FUN_00ae8550(int* values, int(__cdecl* compare)(int, int), int count);
};

// Sorts the values array in place using a Shell sort with a Knuth gap sequence and the given comparison function.
// @fnv 0x00ae8550
void FUN_00ae8550_shell::FUN_00ae8550(int* values, int(__cdecl* compare)(int, int), int count)
{
    int offset;
    {
        int last;
        int gap;
        {
            int index;
            {
                int value;
                {
                    int position;

                    gap = 0;
                    offset = 0;
                    last = count - 1;
                    gap = 1;

                    for (; gap <= (last - offset) / 9; gap = gap * 3 + 1)
                    {
                    }

                    for (; gap > 0; gap /= 3)
                    {
                        for (index = offset + gap; index <= last; ++index)
                        {
                            position = index;
                            value = values[index];

                            while (position >= offset + gap && compare(value, values[position - gap]) < 0)
                            {
                                values[position] = values[position - gap];
                                position -= gap;
                            }

                            values[position] = value;
                        }
                    }
                }
            }
        }
    }
}

struct Setting_01017720_011f96a0
{
    void* m_pVtbl;
    int m_iValue;
};

struct BSThread
{
    enum StackSize
    {
        kDefaultStack = 0x8000
    };

    void Initialize(StackSize eStackSize, const char* apName, bool abSuspended);
    void SetName(const char* apName);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int m_iThreadId;
public:
    void SetSchedulingPriority(unsigned int);
};


class AudioThreadHost_00ad9f30
{
  public:
    void FUN_00ad9f30(void);

    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134;
    unsigned int m_uiThreadID;
    BSThread* m_pAudioThread;
};

// @fnv 0x00ad9f30
void AudioThreadHost_00ad9f30::FUN_00ad9f30(void)
{
    if (m_pAudioThread)
    {
        int iHandle = m_pAudioThread->m_iThreadId;
        if (iHandle == 0)
        {
            m_pAudioThread->Initialize(BSThread::kDefaultStack, "LibAudioUpdate", false);

            int iHandleAfterInit = m_pAudioThread->m_iThreadId;
            m_uiThreadID = iHandleAfterInit;

            int* pSettingValue = &::g_011f6ee0 ? &::g_011f6ee0.m_iValue : &(DAT_01202800 = 0);
            int iSetPriority = *pSettingValue;
            m_pAudioThread->SetSchedulingPriority(iSetPriority);

            m_pAudioThread->SetName("LibAudioUpdate");
            int iThreadIdentifier = m_pAudioThread->m_iThreadId;
            int iPrioritySave;  // the original source declares this and never uses it; the slot is part of its frame
            ::SetDebuggerThreadName(iThreadIdentifier, "LibAudioUpdate");
        }
        reinterpret_cast<::FUN_00ae78e0_Class *>((m_pAudioThread))->ReleaseSemaphoreAndIncrement();
    }
}

namespace fnv_00add630 {
typedef bool(__cdecl* ADD630ResolveFunc)(const char* pcName, char* pcPath, unsigned int* puiFlags,
                                         unsigned int* puiExtra);

class ADD630Audio
{
  public:
    int unk00;
    bool m_bEnableState;
    char unk05;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ADD630ResolveFunc m_pfnResolve;
};


class ADD630Manager
{
  public:
    void FUN_00add630(const char* pcName, unsigned int uiFlags);
};

// @fnv 0x00add630
void ADD630Manager::FUN_00add630(const char* pcName, unsigned int uiFlags)
{
    unsigned int uiResolvedFlags3 = uiFlags;
    ADD630Audio* pkAudio5 = (*reinterpret_cast<::fnv_00add630::ADD630Audio * *>(&::DAT_011f6d98));
    ADD630ResolveFunc pfnResolve4 = pkAudio5->m_pfnResolve;
    unsigned int _uiExtra = 0;
    ADD630Audio* pkAudio2 = (*reinterpret_cast<::fnv_00add630::ADD630Audio * *>(&::DAT_011f6d98));
    bool bEnabled6 = pkAudio2->m_bEnableState;
    char acPath4[260];
    if (!bEnabled6 || !pfnResolve4 || !pfnResolve4(pcName, acPath4, &uiResolvedFlags3, &_uiExtra))
        return;
    uiFlags |= uiResolvedFlags3;
    reinterpret_cast<::OwnerQ3 *>(this)->FUN_00add6f0(acPath4, uiFlags, _uiExtra);
}
}  // namespace fnv_00add630

struct Sub
{
};

struct S
{
    int f0;
    float f4;
    float f8;
    int fc;
    int f10;
    unsigned char f14;
    char pad15[3];
    Sub sub;
    S* AssignFrom(const S* src);
    void Reset();
};

// Copies the scalar fields from src into this and forwards src's sub object to sub.FUN_00ae88c0, returning this.
// @fnv 0x00ae7920
S* S::AssignFrom(const S* apSource)
{
    int u1, u2, u3, u4;
    f0 = apSource->f0;
    f4 = apSource->f4;
    f8 = apSource->f8;
    fc = apSource->fc;
    f10 = apSource->f10;
    f14 = apSource->f14;
    reinterpret_cast<::BSAudioDefinition *>(&(sub))->operator=((*(const ::BSAudioDefinition *)(&apSource->sub)));
    return this;
}


struct AudioMgr_adac30
{
    char pad000[0x140];
    float m_f140;
    float m_f144;
    float m_f148;
    float m_f14C;
    float m_f150;
    float m_f154;
    float m_f158;
    float m_f15C;
    float m_f160;
    float m_f164;
    float m_f168;
    float m_f16C;

    float FUN_00adac30(float a1, unsigned int a2);
};

// Scales a1 by m_f140*m_f158 and a setting value, then applies a further gain pair chosen by the flags in a2 and returns the result.
// @fnv 0x00adac30
float AudioMgr_adac30::FUN_00adac30(float afBase, unsigned int auiFlags)
{
    float f6 = afBase;
    float* pSettingValue = &::g_011f6e74 ? (float*)&::g_011f6e74.m_iValue : &(*(float*)& DAT_01202800 = 0.0f);
    f6 = m_f140 * m_f158 * *pSettingValue * f6;
    if (auiFlags & 0x800000)
    {
        return f6 * m_f150 * m_f168;
    }
    if (auiFlags & 8)
    {
        f6 = m_f144 * m_f15C * f6;
    }
    else if (auiFlags & 4)
    {
        f6 = m_f148 * m_f160 * f6;
    }
    else if (auiFlags & 0x800)
    {
        f6 = m_f150 * m_f168 * f6;
    }
    else if (auiFlags & 0x100000)
    {
        f6 = m_f154 * m_f16C * f6;
    }
    else
    {
        f6 = m_f14C * m_f164 * f6;
    }
    return f6;
}





struct DeleteView
{
    virtual void* Destroy(unsigned int);
};
// Locks the critical section, rejects duplicate or oversized sounds, clones the input into the list, then evicts entries while total exceeds the limit.
// @fnv 0x00adcd80
void Owner::AddSound(Sound* apSound)
{
    Sound* v35 = 0;
    Sound* v16;
    Sound* v2;
    Sound* v13;
    Sound* v9;
    EnterCriticalSection(&cs);
    int count;
    {
        unsigned int n = list.count;
        count = n;
    }
    {
        unsigned char* p = &(*reinterpret_cast<char *>(&::g_011f6ebc)) ? &((SettingValueView*)&::g_011f6ebc)->m_ucValue
                                         : (*(unsigned char*)& DAT_01202800 = 0, (unsigned char*)&DAT_01202800);
        if (!*p && count > 0)
        {
            struct U8
            {
                int a, b;
            };
            U8 unused;
            while (!(unsigned char)(int)(list.count == 0))
            {
                v35 = ((::Sound *)(reinterpret_cast<::SndStack70 *>(&(list))->FUN_00ae7f90()));
                if (v35)
                {
                    v2 = v35;
                    v16 = v2;
                    v16 ? ((DeleteView*)v16)->Destroy(1) : 0;
                }
            }
            LeaveCriticalSection(&cs);
            return;
        }
        else
        {
            unsigned char* p = &(*reinterpret_cast<char *>(&::g_011f6ebc)) ? &((SettingValueView*)&::g_011f6ebc)->m_ucValue
                                             : (*(unsigned char*)& DAT_01202800 = 0, (unsigned char*)&DAT_01202800);
            {
                unsigned int n;
                {
                    unsigned int* pi;
                    {
                        unsigned int f;
                        if (!*p || !apSound ||
                            (n = apSound->size,
                             pi = &(*reinterpret_cast<char *>(&::g_011f6ed4)) ? (unsigned int*)(&(*reinterpret_cast<char *>(&::g_011f6ed4)) + 4)
                                                : (*(unsigned int*)& DAT_01202800 = 0, (unsigned int*)&DAT_01202800),
                             n > (*pi << 10)) ||
                            (f = apSound->flags, f & 0x10000))
                        {
                            LeaveCriticalSection(&cs);
                            return;
                        }
                    }
                }
            }
        }
    }
    Node* v3 = list.head;
    while (v3)
    {
        v35 = v3->sound;
        if ((unsigned char)(int)(apSound->id == v35->id))
        {
            LeaveCriticalSection(&cs);
            return;
        }
        v3 = v3 ? v3->next : 0;
    }
    Sound* v15 = (*(Sound* volatile*)&DAT_011f6d98)->Create(0);
    {
        unsigned int f = apSound->flags;
        {
            Sound* p = v15;
            p->flags = f;
        }
    }
    v15->Copy(apSound, 0);
    {
        unsigned int f = apSound->flags;
        {
            Sound* p = v15;
            p->flags = f | 0x8000;
        }
    }
    reinterpret_cast<::S_00a0c9f0 *>(&(list))->FUN_00a0c9f0((int *)&(v15));
    {
        struct U4
        {
            int a;
        };
        U4 unused;
    }
    {
        unsigned int f = apSound->flags;
        if (!(f & 0x20000000))
        {
            unsigned int n = v15->size;
            total += n;
        }
    }
    v35 = 0;
    int v1 = 0;
    {
        unsigned int* p;
        {
            struct U12
            {
                int a, b, c;
            };
            U12 unused;
        }
        {
            unsigned int f;
            {
                unsigned int g;
                {
                    unsigned int n;
                    while ((p = &(*reinterpret_cast<char *>(&::g_011f6ec8)) ? (unsigned int*)(&(*reinterpret_cast<char *>(&::g_011f6ec8)) + 4)
                                              : (*(unsigned int*)& DAT_01202800 = 0, (unsigned int*)&DAT_01202800),
                            total > (*p << 10)) &&
                           !(unsigned char)(int)(list.count == 0))
                    {
                        v35 = ((::Sound *)(reinterpret_cast<::FUN_00ae8010_cls *>(&(list))->PopFront()));
                        if (v35 &&
                            (((f = v35->flags, !(f & 0x20000)) && (g = v35->flags, !(g & 0x20000000))) || v1 > 30))
                        {
                            n = v35->size;
                            total -= n;
                            v9 = v35;
                            v13 = v9;
                            v13 ? ((DeleteView*)v13)->Destroy(1) : 0;
                        }
                        else
                        {
                            if (v35)
                                reinterpret_cast<::S_00a0c9f0 *>(&(list))->FUN_00a0c9f0((int *)&(v35));
                        }
                        v1++;
                    }
                }
            }
        }
    }
    {
        struct U16
        {
            int a, b, c, d;
        };
        U16 unused;
    }
    LeaveCriticalSection(&cs);
}

namespace fnv_00addc70 {

struct FUN_00ae76b0_shell
{
};
struct AudioThreadData
{
    int unk00;
    int iWriteIndex;
    int iReadIndex;
    LinkedSoundQueue kLists0;
    LinkedSoundQueue kLists1;
    char pad24[0x20];
    FUN_00ae76b0_shell kQueue;
    char pad48[0x64];
    CritSecA kLock;
    void ProcessAudioQueue();
};
// @fnv 0x00addc70
void AudioThreadData::ProcessAudioQueue()
{
    void* item9 = 0;
    LinkedSoundQueue* pListU = &kLists0 + iReadIndex;
    void* aPHead;
    void* kPTail;
    void* pHead2;
    void* pTail2;
    char padA[0x14];
    int aUnk;
    int unk2;
    int unk6;
    if (pListU == 0)
        return;
    while (!(bool)(int)(pListU->iCount == 0) && (aPHead = pListU->pHead) != 0 && (kPTail = pListU->pTail) != 0)
    {
        item9 = reinterpret_cast<::SndStack70 *>((pListU))->FUN_00ae7f90();
        if (reinterpret_cast<::fnv_00adf080::BSAudioManager_adf080 *>(this)->FUN_00adf080((::fnv_00adf080::SoundMessageRecord *)(item9)))
            return;
        reinterpret_cast<::Stack75f0 *>(&(kQueue))->FUN_00ae75f0((::SoundMessageRecord *)(item9));
    }
    if (!(bool)(int)(pListU->iCount == 0) && ((pHead2 = pListU->pHead) == 0 || (pTail2 = pListU->pTail) == 0))
        reinterpret_cast<::S_00ae8370_List *>((pListU))->FUN_00ae8370();
    EnterCriticalSection(&kLock);
    iWriteIndex = (iWriteIndex + 1) % 2;
    iReadIndex = (iWriteIndex + 1) % 2;
    item9 = reinterpret_cast<::fnv_00ae76b0::Pool_ae76b0 *>(&(kQueue))->FUN_00ae76b0();
    while (item9)
    {
        reinterpret_cast<::fnv_00adad80::Manager501 *>(this)->FUN_00adad80((::fnv_00adad80::Message501 *)(item9));
        item9 = reinterpret_cast<::fnv_00ae76b0::Pool_ae76b0 *>(&(kQueue))->FUN_00ae76b0();
    }
    LeaveCriticalSection(&kLock);
}
}  // namespace fnv_00addc70

struct Handle_ae5680
{
    int f0;
    char f4;
    int f8;
};

typedef bool(__cdecl* Resolver_ae5680)(int, void*, unsigned int*, int*);

struct AudioMgr_011f6d98
{
    void* vtbl;
    bool bReady;
    char pad[0x1f];
    Resolver_ae5680 pfnResolve;
};

struct AudioClass_ae5680
{
    Handle_ae5680 FUN_00ae5a50(const void* pPath, unsigned int uiFlags, int iExtra);
    Handle_ae5680* ResolveAudioHandle(Handle_ae5680* pOut, int aiSoundId, unsigned int uiFlags);
};

// @fnv 0x00ae5680
Handle_ae5680* AudioClass_ae5680::ResolveAudioHandle(Handle_ae5680* pOut, int aiSoundId, unsigned int uiFlags)
{
    int iState = 0;
    unsigned int uiOutFlags = 0;
    AudioMgr_011f6d98* pMgrJ = reinterpret_cast<AudioMgr_011f6d98*>(DAT_011f6d98);
    bool bReady_ = pMgrJ->bReady;
    AudioMgr_011f6d98* pMgr4;
    Resolver_ae5680 pfn3;
    char path3[260];
    int aIExtra;
    if (!bReady_)
    {
        pOut->f0 = -1;
        pOut->f4 = 0;
        pOut->f8 = 0;
        iState |= 1;
        return pOut;
    }
    pMgr4 = reinterpret_cast<AudioMgr_011f6d98*>(DAT_011f6d98);
    pfn3 = pMgr4->pfnResolve;
    aIExtra = 0;
    if (pfn3 == 0 || !pfn3(aiSoundId, path3, &uiOutFlags, &aIExtra))
    {
        pOut->f0 = -1;
        pOut->f4 = 0;
        pOut->f8 = 0;
        iState |= 1;
        return pOut;
    }
    if (uiOutFlags & 0x08000000)
    {
        uiFlags |= 1;
        uiFlags |= 0x08000000;
    }
    if (uiOutFlags & 0x02000000)
    {
        uiFlags |= 0x02000000;
        uiFlags &= ~0x10;
    }
    else if (uiOutFlags & 0x04000000)
    {
        uiFlags |= 0x04000000;
        uiFlags &= ~0x10;
    }
    if (path3[0] == 0)
    {
        pOut->f0 = -1;
        pOut->f4 = 0;
        pOut->f8 = 0;
        iState |= 1;
        return pOut;
    }
    Handle_ae5680 h7 = FUN_00ae5a50(path3, uiFlags, aIExtra);
    pOut->f0 = h7.f0;
    pOut->f4 = h7.f4;
    pOut->f8 = h7.f8;
    iState |= 1;
    return pOut;
}

struct FUN_00ae8650_cls
{
    unsigned int m_00, m_04, m_08, m_0c;
    void* m_10;
    float m_14, m_18, m_1c;
    FUN_00ae8650_cls* FUN_00ae8650();
};
// Initializes all members to zero and increments the reference count of the object stored in m_10 if it is non-null.
// @fnv 0x00ae8650
FUN_00ae8650_cls* FUN_00ae8650_cls::FUN_00ae8650()
{
    void* pTarget;
    {
        void** slot = &m_10;
        *slot = 0;
        if (*slot != 0)
        {
            pTarget = *slot;
            InterlockedIncrement(&((RefCountView*)pTarget)->m_lRefCount);
        }
    }
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_1c = 0.0f;
    return this;
}

void __cdecl FUN_00fdbfd0();
extern int DAT_011f6ef0;
struct FUN_00ad90e0_shell
{
    FUN_00ad90e0_shell();
    ~FUN_00ad90e0_shell();
};
// Returns a pointer to a static singleton instance of FUN_00ad90e0_shell.
// @fnv 0x00ad9060
FUN_00ad90e0_shell* __cdecl FUN_00ad9060()
{
    static FUN_00ad90e0_shell sInstance;
    return &sInstance;
}


struct AudioHelperA
{
};

struct AudioHelperB
{
};

struct AudioSystemUpdate
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    AudioHelperA m_14;
};

struct AudioManagerUpdate
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8;
    CritSecA critical0dc;
    CritSecA m_cs;
    void FUN_00addc00();
};
// @fnv 0x00ada1d0
void FUN_00ada1d0_shell::InitUISounds(bool abPlayGameWorldSounds)
{
    if (!m_bUISoundsEnabled)
    {
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)($SG6265), 0);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuFocus"), 0x20000);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuCancel"), 0x20001);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuTab"), 0x20000);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuOK"), 0x20001);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UIMenuPrevNext"), 1);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("WPNRifleAssaultFire3D"), 0x102);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("FXBulletImpactConc"), 0x102);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UILoadScreenMicroFiche01"), 0x101);
        reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((DAT_011f6d98))->FUN_00ad7fa0((char *)("UILoadScreenInitial"), 0x101);
        m_bUISoundsEnabled = true;
    }

    reinterpret_cast<::fnv_00ada330::OwnerQ *>((reinterpret_cast<FUN_00ada330_shell*>(this)))->FUN_00ada330();

    BSAudio* pAudio = DAT_011f6d98;
    volatile bool bAudioMultiThreaded = pAudio->bIsMultiThreaded;
    if (!bAudioMultiThreaded)
    {
        reinterpret_cast<::AudioManagerUpdate *>(&(reinterpret_cast<FUN_00addc00_shell&>(BSAudioManager::GetRandomGenerator())))->FUN_00addc00();
    }
}

// Calls the audio system update helper, then acquires m_cs and invokes two AudioHelperB methods if the lock is obtained.
// @fnv 0x00addc00
void AudioManagerUpdate::FUN_00addc00()
{
    AudioSystemUpdate* p = reinterpret_cast<AudioSystemUpdate*>(DAT_011f6d98);
    reinterpret_cast<::FUN_00aea100_cls *>(&(p->m_14))->UpdateAccumulatedTime();
    bool locked = TryEnterCriticalSection(&m_cs) != 0;
    if (locked)
    {
        reinterpret_cast<::fnv_00addc70::AudioThreadData *>((reinterpret_cast<AudioHelperB*>(FUN_00ad9060())))->ProcessAudioQueue();
        reinterpret_cast<::fnv_00adddd0::AudioUpdate *>((reinterpret_cast<AudioHelperB*>(FUN_00ad9060())))->FUN_00adddd0();
        LeaveCriticalSection(&m_cs);
    }
}

struct S_00ae77d0_Sem
{
    long initial;
    void* h;
    long max;
};
struct S_00ae77d0_Base
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
    S_00ae77d0_Base();
    virtual void v0();
};
struct FUN_00ae77d0 : S_00ae77d0_Base
{
    S_00ae77d0_Sem sem0;
    S_00ae77d0_Sem sem1;
    char unk48;
    FUN_00ae77d0();
    virtual void v0();
};
// Initializes two binary semaphores with initial count 0 and max 1, and sets unk48 to 1.
// @fnv 0x00ae77d0
FUN_00ae77d0::FUN_00ae77d0()
{
    S_00ae77d0_Sem* a = &sem0;
    a->initial = 0;
    a->max = 1;
    a->h = CreateSemaphoreA(0, a->initial, a->max, 0);
    S_00ae77d0_Sem* b = &sem1;
    b->initial = 0;
    b->max = 1;
    b->h = CreateSemaphoreA(0, b->initial, b->max, 0);
    unk48 = 1;
}






// Sets processing, signals signalSemaphore, waits on waitSemaphore, then clears processing.
// @fnv 0x00ae7a50
void AudioWorker::FUN_00ae7a50()
{

    processing = true;

    SyncSemaphore* signal = &signalSemaphore;

    ReleaseSemaphore(signal->handle, 1, 0);

    InterlockedIncrement(&signal->count);

    SyncSemaphore* waiting = &waitSemaphore;

    WaitForSingleObject(waiting->handle, 0xFFFFFFFF);

    InterlockedDecrement(&waiting->count);

    processing = false;
}






// Sets waiting48, releases workSemaphore3c, increments its count, and calls FUN_00aa6590.
// @fnv 0x00ae7ac0
void BSAudioManagerThread::FUN_00ae7ac0()
{
    waiting48 = true;
    BSSemaphore_adf080* semaphore = &workSemaphore3c;
    ReleaseSemaphore(semaphore->semaphore, 1, 0);
    InterlockedIncrement(&semaphore->count);
    reinterpret_cast<::fnv_00aa6590::FUN_00aa6590_cls *>(this)->FUN_00aa6590(0, 0);
}

struct S00ae6f10_SubObj_00ae6f10
{
};
struct S00ae6f10_FUN_00ae6f10_cls
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
    CritSecA m_10c;
    S00ae6f10_SubObj_00ae6f10 m_124;
    void FUN_00ae6f10(std::intptr_t arg);
};
// Calls a helper on the BSAudioManager singleton with this task, then assigns the task's pointer field to itself.
// @fnv 0x00ae7360
void AudioLoadTask::FUN_00ae7360()
{
    reinterpret_cast<::S00ae6f10_FUN_00ae6f10_cls *>((((Helper*)&BSAudioManager::GetRandomGenerator())))->FUN_00ae6f10((std::intptr_t)(this));
    SoundAssetTmp = SoundAssetTmp;
}
// @fnv 0x00ae7390
void AudioLoadTask7390::ReleaseSound(int, int)
{
    reinterpret_cast<::S00ae6f10_FUN_00ae6f10_cls *>((((::AudioHelper7390 *)(::FUN_00ad9060()))))->FUN_00ae6f10({});
    unsigned int uiSoundFlags;
    Sound7390* pDeleteFirst;
    Sound7390* pSoundToDelete;
    if (SoundAssetTmp && ((uiSoundFlags = SoundAssetTmp->uiFlags08) & 0x8000))
    {
        pDeleteFirst = SoundAssetTmp;
        pSoundToDelete = pDeleteFirst;
        pSoundToDelete ? pSoundToDelete->ScalarDeletingDestructor(1) : 0;
    }
    else if (SoundAssetTmp)
    {
        Sound7390* nodeToClear = SoundAssetTmp;
        nodeToClear->uiFlags10 = false ? nodeToClear->uiFlags10 | 0x200u : nodeToClear->uiFlags10 & ~0x200u;
        Sound7390* nodeToSet = SoundAssetTmp;
        nodeToSet->uiFlags10 = true ? nodeToSet->uiFlags10 | 0x10u : nodeToSet->uiFlags10 & ~0x10u;
    }
}

struct S00ae6f10_FUN_00ae6f10_frame
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
};

// Locks m_10c, passes the address of arg to m_124.FUN_00ae8150, then unlocks m_10c.
// @fnv 0x00ae6f10
void S00ae6f10_FUN_00ae6f10_cls::FUN_00ae6f10(std::intptr_t aValue)
{
    S00ae6f10_FUN_00ae6f10_frame frame;
    EnterCriticalSection(&m_10c);
    reinterpret_cast<::AE8150_List *>(&(m_124))->FUN_00ae8150((*(void *const *)((void*)&aValue)));
    LeaveCriticalSection(&m_10c);
}


struct AudioThreadEntry : BSAudioManagerThread
{
    int FUN_00ae74b0();
};

// Waits on doneSemaphore30, then loops calling FUN_00addc00 on the update object when DAT_01202d98 is set, sleeping 1 ms each iteration.
// @fnv 0x00ae74b0
int AudioThreadEntry::FUN_00ae74b0()
{
    BSSemaphore_adf080* semaphore = &doneSemaphore30;
    WaitForSingleObject(semaphore->semaphore, 0xFFFFFFFF);
    InterlockedDecrement(&semaphore->count);
    waiting48 = false;
    while (1)
    {
        if ((*reinterpret_cast<int *>(&::DAT_01202d98)) != 0)
        {
            reinterpret_cast<AudioManagerUpdate*>(FUN_00ad9060())->FUN_00addc00();
        }
        Sleep(1);
    }
    return 0;
}

struct ScrapHeapBuffer;
struct BSMapBase
{
};
// The volume map and its lock; the pads stand for members not named yet.
struct FUN_00adc8b0_shell
{
    char pad00[0x64];
    BSMapBase m_kVolumeMap;
    char pad65[0xc4 - 0x64 - sizeof(BSMapBase)];
    CritSecA m_kVolumeLock;
    float FUN_00adc8b0(unsigned long);
};
// A volume map entry.
struct VolumeEntryView
{
    char pad00[0x8];
    float m_fVolume;
};
// @fnv 0x00adc8b0
float FUN_00adc8b0_shell::FUN_00adc8b0(unsigned long auiKey)
{
    float fVol;
    {
        ScrapHeapBuffer* pBuffer;
        {
            int iUnusedA;
            int iUnusedB;
            pBuffer = 0;
            fVol = 0.0f;
            EnterCriticalSection(&m_kVolumeLock);
            reinterpret_cast<::S_00adc830_Map *>(&m_kVolumeMap)->GetAt(auiKey, (::S_00adc830_Entry *&)(pBuffer));
            LeaveCriticalSection(&m_kVolumeLock);
            if (pBuffer != 0)
            {
                fVol = ((VolumeEntryView*)pBuffer)->m_fVolume;
            }
        }
    }
    return fVol;
}

extern "C" int __cdecl FUN_00ec7d40(int);

int __cdecl FUN_00ae5fb0(unsigned int* a, unsigned int* b);

class DetectRefObject
{
  public:
    int unk00;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount();
};

class DetectRefPtr
{
  public:
    DetectRefPtr(DetectRefObject* pkObject = 0) : m_pPointer(pkObject)
    {
        if (m_pPointer)
            m_pPointer->IncRefCount();
    }
    DetectRefPtr(const DetectRefPtr& kPtr) : m_pPointer(kPtr.m_pPointer)
    {
        if (m_pPointer)
            m_pPointer->IncRefCount();
    }
    ~DetectRefPtr()
    {
        if (m_pPointer)
            m_pPointer->DecRefCount();
    }
    DetectRefObject* m_pPointer;
};

class DetectOwner
{
  public:
    bool FUN_00adb1a0(int iType, int iParam, int iUnk0, int iUnk1, DetectRefPtr spRetainedObject, DetectPoint3 kPoint);
    bool FUN_00adb590(int iParam);
};

// @fnv 0x00adb590
bool DetectOwner::FUN_00adb590(int iParam)
{
    FUN_00adb1a0(3, iParam, 0, 0, DetectRefPtr(0), DAT_011f426c);
    return false;
}















class C_00adc830
{
  public:
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

    S_00adc830_Map m_kFormatEntries;

    char pad74[0x50];

    CritSecA m_kCS;

    int FUN_00adc830(unsigned int uiKey);
};

// @fnv 0x00adc830
int C_00adc830::FUN_00adc830(unsigned int uiKey)
{
    int iValue = 0;
    S_00adc830_Entry* pkEntry = 0;
    EnterCriticalSection(&m_kCS);
    m_kFormatEntries.GetAt(uiKey, pkEntry);
    LeaveCriticalSection(&m_kCS);
    iValue = pkEntry ? pkEntry->GetValue() : 0;
    return iValue;
}

extern void* __cdecl fnv_zlib_memset(void*, int, unsigned int);



struct MessageStackMember : BottomlessStack
{
    MessageStackMember();
    ~MessageStackMember();
};





struct PointerMapBase
{
    virtual ~PointerMapBase();
    unsigned int capacity;
    void* entries;
    unsigned int count;
    PointerMapBase(unsigned int size = 37);
};

struct PointerMap : PointerMapBase
{
    PointerMap() : PointerMapBase(37)
    {}
    virtual ~PointerMap();
};

struct CachedPointerMapBase
{
    virtual ~CachedPointerMapBase();
    unsigned int capacity;
    void* entries;
    unsigned int count;
    CachedPointerMapBase(unsigned int size = 37)
    {
        capacity = size;
        count = 0;
        unsigned int bytes = capacity * sizeof(void*);
        entries = ::FUN_00aa1070(bytes);
        unsigned int clearBytes = capacity * sizeof(void*);
        void* clearEntries = entries;
        fnv_zlib_memset(clearEntries, 0, clearBytes);
    }
};

struct CachedPointerMap : CachedPointerMapBase
{
    CachedPointerMap() : CachedPointerMapBase(37)
    {}
    virtual ~CachedPointerMap();
};

struct TaskMapBase
{
    virtual void Release();
    unsigned int count, capacity;
    void* entries;
    TaskMapBase(unsigned int = 37);
};

struct TaskMap : TaskMapBase
{
    virtual void Release();
};

struct AudioList
{
    void* head;
    void* tail;
    unsigned int count;
    AudioList()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
};

struct AudioCriticalSection : CRITICAL_SECTION
{
    AudioCriticalSection()
    {
        InitializeCriticalSection(this);
    }
};

struct FUN_00ad90e0
{
    virtual void Update();
    unsigned int state, enabled;
    FUN_00a1b940 channels[2];
    MessageStackMember incoming, outgoing, freeMessages;
    SoundMap sounds;
    PointerMap activeSounds;
    CachedPointerMap cachedSounds;
    TaskMap tasks;
    AudioList pending;
    unsigned int pendingFlags, unknownA4;
    float elapsed;
    AudioCriticalSection messageLock, soundLock, cacheLock, taskLock, listenerLock;
    AudioList completed;
    unsigned long lastTick;
    bool precacheCompleted, updating;
    unsigned int unknown138, unknown13C;
    float volume140, volume144, volume148, volume14C, volume150, volume154;
    float volume158, volume15C, volume160, volume164, volume168, volume16C;
    unsigned int unknown170;
    bool muted, paused;
    unsigned int unknown178, unknown17C, initialized;
    FUN_00ad90e0();
};

// @fnv 0x00ad90e0
FUN_00ad90e0::FUN_00ad90e0()
{
    unknown138 = 0;
    volume140 = 0.0f;
    volume144 = 0.0f;
    volume148 = 0.0f;
    volume14C = 0.0f;
    volume150 = 0.0f;
    volume154 = 0.0f;
    volume158 = 0.0f;
    volume15C = 0.0f;
    volume160 = 0.0f;
    volume164 = 0.0f;
    volume168 = 0.0f;
    volume16C = 0.0f;
    precacheCompleted = false;
    unknownA4 = 0;
    initialized = 1;
    state = 0;
    enabled = 1;
    pendingFlags = 0;
    unknown13C = 0;
    unknown170 = 0;
    updating = false;
    unknownA4 = 0;
    elapsed = 0.0f;
    lastTick = GetTickCount();
    muted = false;
    paused = false;
}



struct StrSetX
{
    int a;
    char buf[4];
};

struct Ent8
{
    int a, b;
};



struct ListX
{
    int m0;
};

struct MgrX
{
    char p0[0x24];
    ListX l24;
    int p28[3];
    ListX l34;
    int p38[4];
    char b48;
    char p49[0xa4 - 0x49];
    int ma4;
    char pa8[0x13c - 0xa8];
    FUN_00ae77d0* m13c;
    char p140[0x178 - 0x140];
    Ent8* m178;
    unsigned m17c;
    void FUN_00ad9640();
};

inline const unsigned char* GetName()
{
    const unsigned char* r = &(*reinterpret_cast<::StrSetX *>(&::g_011f6d9c)) ? (unsigned char*)(*reinterpret_cast<::StrSetX *>(&::g_011f6d9c)).buf
                                             : ((*reinterpret_cast<char (*)[]>(&::DAT_01202800))[0] = 0, (unsigned char*)(*reinterpret_cast<char (*)[]>(&::DAT_01202800)));
    return r;
}

inline void ClearX(void* p, unsigned n)
{
    std::memset(p, 0, n);
}

inline void DbgX()
{
    const char* a;
    const char* b;
    const char* c;
    const char* d;
    const char* e;
    const char* f;
}





struct RefPointer
{
    RefObject* m_pObject;

    RefPointer(RefObject* object) throw() : m_pObject(object)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    RefPointer(const RefPointer&) throw();
    ~RefPointer() throw();
};

struct AudioMessageSender
{
    void FUN_00adb1a0(int message, int id, unsigned short volume, int zero, RefPointer object,
                                 NiPoint3 point);
};

struct BSAudioManagerCall : AudioMessageSender
{
    bool FUN_00adb720(unsigned int id, unsigned short volume);
};

// @fnv 0x00adb720
bool BSAudioManagerCall::FUN_00adb720(unsigned int id, unsigned short volume)
{
    volume = volume > 10000 ? 10000 : volume;
    FUN_00adb1a0(0x21, id, volume, 0, RefPointer(0), NiPoint3_ZERO);
    return false;
}

struct RefObject405
{
    virtual ~RefObject405();
    virtual void DeleteThis();
    unsigned references;
    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&references));
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&references)))
            DeleteThis();
    }
};

struct RefPointer405
{
    RefObject405* object;
    RefPointer405(RefObject405* value) : object(value)
    {
        if (object)
            object->IncRefCount();
    }
    RefPointer405(const RefPointer405& other) : object(other.object)
    {
        if (object)
            object->IncRefCount();
    }
    ~RefPointer405()
    {
        if (object)
            object->DecRefCount();
    }
};

struct Point405
{
    float x, y, z;
};

extern "C" Point405 _NiPoint3_ZERO;

struct FUN_00adb850_cls
{
    void FUN_00adb1a0(int message, int soundID, int milliseconds, int flags, RefPointer405 target, Point405 position);
    bool FUN_00adb850(int soundID, float seconds);
};

// @fnv 0x00adb850
bool FUN_00adb850_cls::FUN_00adb850(int soundID, float seconds)
{
    FUN_00adb1a0(0x42, soundID, static_cast<int>(seconds * 1000.0), 0, RefPointer405(0), _NiPoint3_ZERO);
    return false;
}

namespace fnv_00adcb20 {
extern long(* DAT_00fdf1c0)(volatile long*);

struct S_adcb20_Ref
{
    int unk00;
    long unk04;
    __forceinline void Inc()
    {
        DAT_00fdf1c0(&unk04);
    }
};

struct S_adcb20_Ptr
{
    S_adcb20_Ref* m_p;
    __forceinline S_adcb20_Ptr(S_adcb20_Ref* p = 0)
    {
        m_p = p;
        if (m_p)
            m_p->Inc();
    }
    __forceinline S_adcb20_Ptr(const S_adcb20_Ptr& other)
    {
        m_p = other.m_p;
        if (m_p)
            m_p->Inc();
    }
    __forceinline ~S_adcb20_Ptr()
    {}
};





struct S_adcb20
{
    void FUN_00adb1a0(int a1, int a2, int a3, int a4, S_adcb20_Ptr a5, S_adcb20_Point3 a6);
    void FUN_00adcb20(int a1, bool a2);
};

// @fnv 0x00adcb20
void S_adcb20::FUN_00adcb20(int a1, bool a2)
{
    if (a2)
        FUN_00adb1a0(0x1c, 0, a1, 0, S_adcb20_Ptr(0), NiPoint3_ZERO);
    else
        FUN_00adb1a0(0x1a, 0, a1, 0, S_adcb20_Ptr(0), NiPoint3_ZERO);
}
}

// namespace fnv_00adcb20

struct IdentifierState
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    IdentifierState()
    {
        uiID = 0xffffffff;
        m_bLooping = false;
        uiState = 0;
    }
    IdentifierState(const IdentifierState& r)
    {
        uiID = r.uiID;
        m_bLooping = r.m_bLooping;
        uiState = r.uiState;
    }
    ~IdentifierState()
    {}
};

typedef bool(__cdecl* FileCB)(const char*, char*, unsigned int*, unsigned int*);

struct AudioX
{
    char _p4[4];
    bool bReady;
    char _p5[0x1b];
    FileCB pCallback;
    bool IsReady()
    {
        return bReady;
    }
};

inline AudioX* GetAudioX()
{
    AudioX* p = (AudioX*)DAT_011f6d98;
    return p;
}

struct FUN_00ae5870_t
{
    IdentifierState FUN_00ae5a50(char*, unsigned int, unsigned int);
    IdentifierState FUN_00ae5870(const char* pName, unsigned int uiFlags);
};

// @fnv 0x00ae5870
IdentifierState FUN_00ae5870_t::FUN_00ae5870(const char* pName, unsigned int uiFlags)
{
    unsigned int uiFileFlags_hk = 0;
    if (!GetAudioX()->IsReady())
        return IdentifierState();
    FileCB pfnCB_fi = GetAudioX()->pCallback;
    unsigned int uiExtra_mh = 0;
    char acPath_kmt[260];
    if (!pfnCB_fi || !pfnCB_fi(pName, acPath_kmt, &uiFileFlags_hk, &uiExtra_mh))
        return IdentifierState();
    if ((uiFileFlags_hk & 1) && (uiFlags & 2))
    {
        uiFlags &= ~2;
        uiFlags |= 1;
    }
    if (uiFileFlags_hk & 0x8000000)
    {
        uiFlags |= 0x8000000;
        uiFlags |= 1;
        uiFlags &= ~2;
    }
    if (uiFileFlags_hk & 0x2000000)
    {
        uiFlags |= 0x2000000;
        uiFlags &= ~0x10;
    }
    else if (uiFileFlags_hk & 0x4000000)
    {
        uiFlags |= 0x4000000;
        uiFlags &= ~0x10;
    }
    IdentifierState kHandle_nhzv = FUN_00ae5a50(acPath_kmt, uiFlags, uiExtra_mh);
    return kHandle_nhzv;
}

extern int DAT_010a3368;







struct FramePair
{
    int offset_00, offset_04;
};



template <> inline void ReserveFrame<0>()
{}

template <> inline void ReserveFrame<1>()
{
    FramePair frame;
    (void)&frame;
}

template <> inline void ReserveFrame<2>()
{
    FramePair frame, other;
    (void)&frame;
    (void)&other;
}















// @fnv 0x00ad93f0
FUN_00ad93f0::~FUN_00ad93f0()
{}

// 0x00ad9870 -- BSAudioManager::Update

struct H70
{
    char* v;
};


class SetObj_70
{
  public:
    void* m_pVtbl;
    char m_cValue;
    char& GetPtr()
    {
        return this ? m_cValue : (*(char*)&DAT_01202800 = 0, *(char*)&DAT_01202800);
    }
};

inline BSAudio* GetAudio70()
{
    return DAT_011f6d98;
}

inline bool IsMultiThreaded70(BSAudio* p)
{
    return p->bIsMultiThreaded;
}

class MemMgr70
{
  public:
    void Deallocate(void* p)
    {
        DeallocateAlias(p);
    }
    void DeallocateAlias(void* p);
};

extern MemMgr70* g_memMgr70;

struct BSSoundInfo70
{
    int m_iWordAt00;
    int m_iWordAt04;
    void FUN_00ae8af0();
    ~BSSoundInfo70()
    {
        reinterpret_cast<::BSSoundInfo *>(this)->BSSoundInfo::~BSSoundInfo();
    }
};



struct BSSoundMsgV70
{
    int m_iWordAt04;
    int GetID() const
    {
        return m_iWordAt04;
    }
    virtual ~BSSoundMsgV70();
};

inline void Free70(void* const& p)
{
    reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::MemoryManager * *>(&::g_memoryManager)))))->FUN_00aa4060(p);
}





struct MapNode70
{
    MapNode70* next;
    int key;
    void* value;
};

struct MsgQueue70
{
    virtual void v0();
    virtual unsigned int Hash(int);
    virtual bool Equal(int, int);
    virtual void v3();
    virtual void ClearValue(MapNode70*);
    virtual void v5();
    virtual void DeleteItem(MapNode70*);
    unsigned int m_uiItemCount;
    MapNode70** m_items;
    unsigned int size;
    void FUN_00a0c850(void** pos, int* key, void** value)
    {
        MapNode70* node = (MapNode70*)*pos;
        *key = node->key;
        *value = node->value;
        if (node->next)
            *pos = node->next;
        else
        {
            unsigned int index = Hash(node->key);
            for (++index; index < m_uiItemCount; ++index)
            {
                node = m_items[index];
                if (node)
                {
                    *pos = node;
                    return;
                }
            }
            *pos = 0;
        }
    }
    bool FUN_00a1e240(int key)
    {
        unsigned int index = Hash(key);
        MapNode70* node = m_items[index];
        if (node)
        {
            if (Equal(key, node->key))
            {
                m_items[index] = node->next;
                ClearValue(node);
                DeleteItem(node);
                --size;
                return true;
            }
            else
            {
                MapNode70* prev = node;
                MapNode70* current = prev->next;
                while (current && !Equal(key, current->key))
                {
                    prev = current;
                    current = current->next;
                }
                if (current)
                {
                    prev->next = current->next;
                    ClearValue(current);
                    DeleteItem(current);
                    --size;
                    return true;
                }
            }
        }
        return false;
    }
    bool FUN_00a1e380(int key, BSSoundInfo70** out)
    {
        unsigned int index = Hash(key);
        MapNode70** bucket = &m_items[index];
        MapNode70* node = *bucket;
        while (node)
        {
            int nodeKey = node->key;
            bool equal = Equal(key, nodeKey);
            if (equal)
            {
                BSSoundInfo70* info = (BSSoundInfo70*)node->value;
                *out = info;
                return true;
            }
            node = node->next;
        }
        return false;
    }
    void* First()
    {
        for (unsigned int i = 0; i < m_uiItemCount; i++)
            if (m_items[i])
                return m_items[i];
        return 0;
    }
};

struct InfoQueue70
{
    virtual void v0();
    virtual unsigned int Hash(int);
    virtual bool Equal(int, int);
    virtual void v3();
    virtual void ClearValue(MapNode70*);
    virtual void v5();
    virtual void DeleteItem(MapNode70*);
    unsigned int m_uiItemCount;
    MapNode70** m_items;
    unsigned int size;
    void FUN_00a0c850(void** pos, int* key, void** value)
    {
        MapNode70* node = (MapNode70*)*pos;
        *key = node->key;
        *value = node->value;
        if (node->next)
            *pos = node->next;
        else
        {
            unsigned int index = Hash(node->key);
            for (++index; index < m_uiItemCount; ++index)
            {
                node = m_items[index];
                if (node)
                {
                    *pos = node;
                    return;
                }
            }
            *pos = 0;
        }
    }
    bool FUN_00a1e240(int key)
    {
        unsigned int index = Hash(key);
        MapNode70* node = m_items[index];
        if (node)
        {
            if (Equal(key, node->key))
            {
                m_items[index] = node->next;
                ClearValue(node);
                DeleteItem(node);
                --size;
                return true;
            }
            else
            {
                MapNode70* prev = node;
                MapNode70* current = prev->next;
                while (current && !Equal(key, current->key))
                {
                    prev = current;
                    current = current->next;
                }
                if (current)
                {
                    prev->next = current->next;
                    ClearValue(current);
                    DeleteItem(current);
                    --size;
                    return true;
                }
            }
        }
        return false;
    }
    bool FUN_00a1e380(int key, BSSoundInfo70** out)
    {
        unsigned int index = Hash(key);
        MapNode70** bucket = &m_items[index];
        MapNode70* node = *bucket;
        while (node)
        {
            bool equal = Equal(key, node->key);
            if (equal)
            {
                *out = (BSSoundInfo70*)node->value;
                return true;
            }
            node = node->next;
        }
        return false;
    }
    void* First()
    {
        MapNode70* current;
        MapNode70* previous;
        for (unsigned int i = 0; i < m_uiItemCount; i++)
            if (m_items[i])
                return m_items[i];
        return 0;
    }
};

class AudioMgr70
{
  public:
    bool IsEmpty1()
    {
        return m_0c.count == 0;
    }
    bool IsEmpty2()
    {
        return m_18.count == 0;
    }

    void FUN_00ad9870();

    int m_00;
    int unk004;
    int unk008;
    SndStack70 m_0c;
    SndStack70 m_18;
    char pad024[0x30];
    MsgQueue70 m_54;
    InfoQueue70 m_64;
    InfoQueue70 m_74;
    MsgQueue70 m_84;
    char pad094[0xa8];
    BSSoundMsgV70* m_13c;
    char pad140[0x38];
    H70 m_178;
};







struct WaitHandleReference
{
    long m_iArrayLength;
    void* m_hHandle;
    int unk08;

    void Wait()
    {
        WaitForSingleObject(m_hHandle, 0xFFFFFFFF);
        InterlockedDecrement(&m_iArrayLength);
    }
};

struct BSAudioThread
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
    WaitHandleReference m_kRelease;
    WaitHandleReference m_kWait;
    bool m_bSignalled;

    void WaitForSound()
    {
        m_kWait.Wait();
    }

};

struct BSAudioManager_
{
    char pad000[0x13c];
    BSAudioThread* m_pAudioThread;

    void FUN_00ada020();
    void FUN_00adb1a0(int a1, int a2, int a3, int a4, NiPointer ptr, NiPoint3 kPos);
};

// @fnv 0x00ada020
void BSAudioManager_::FUN_00ada020()
{
    if (m_pAudioThread)
        reinterpret_cast<::FUN_00ae78e0_Class *>((m_pAudioThread))->ReleaseSemaphoreAndIncrement();

    FUN_00adb1a0(0x35, 0, 0, 0, 0, NiPoint3::ZERO);

    if (m_pAudioThread)
        m_pAudioThread->WaitForSound();
}

namespace fnv_00adb4e0 {



struct NiPtrB4E0
{
    NiRefObject* m_pObject;
    NiPtrB4E0(NiRefObject* p = 0)
    {
        m_pObject = p;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPtrB4E0(const NiPtrB4E0&);
    ~NiPtrB4E0();
};

struct BSAudioMgrB4E0
{
    bool IsPlaying(unsigned int);
    void PostMsg(int eMsg, unsigned int uiID, unsigned int ulFadeStartTimeTick, int iArg, NiPtrB4E0 kObj, NiPoint3 kPos);
    bool FUN_00adb4e0(unsigned int id, unsigned int delay, int flags);
};

inline unsigned int AddDelayB4E0(unsigned int delay)
{
    unsigned int t = GetTickCount();
    return t + delay;
}

// @fnv 0x00adb4e0
bool BSAudioMgrB4E0::FUN_00adb4e0(unsigned int id, unsigned int delay, int)
{
    if (IsPlaying(id))
        return true;
    if (delay > 0x2710)
        delay = 0x2710;
    PostMsg(5, id, AddDelayB4E0(delay), 0, NiPtrB4E0(), NiPoint3_ZERO);
    return true;
}
}

// namespace fnv_00adb4e0


inline long NiAtomicIncrementB7C0(long& lValue)
{
    return InterlockedIncrement(&lValue);
}

inline long NiAtomicDecrementB7C0(long& lValue)
{
    return InterlockedDecrement(&lValue);
}

class RefObjectB7C0
{
  public:
    virtual ~RefObjectB7C0();
    virtual void DeleteThis();
    void IncRefCount()
    {
        NiAtomicIncrementB7C0(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (NiAtomicDecrementB7C0(m_uiRefCount) == 0)
            DeleteThis();
    }
    long m_uiRefCount;
};

template <class T> class NiPointerB7C0
{
  public:
    NiPointerB7C0(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerB7C0()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};

class NiPoint3B7C0
{
  public:
    float x, y, z;
    static const NiPoint3B7C0 ZERO;
};

class MessageSenderB7C0
{
  public:
    bool FUN_00adb1a0(int iType, unsigned int uiTarget, int iDelayMs, int iFlags,
                      NiPointerB7C0<RefObjectB7C0> spRetainedObject, NiPoint3B7C0 kPos);
    bool FUN_00adb7c0(unsigned int uiTarget, float m_fDelay);
};

// @fnv 0x00adb7c0
bool MessageSenderB7C0::FUN_00adb7c0(unsigned int uiTarget, float m_fDelay)
{
    FUN_00adb1a0(0x13, uiTarget, (int)(m_fDelay * 1000.0), 0, 0, NiPoint3B7C0::ZERO);
    return false;
}









struct FUN_00adc560_cls
{
    bool FUN_00adb1a0(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3_audio kPos);
    void FUN_00adc560(int a, int b, unsigned int c);
};

// @fnv 0x00adc560
void FUN_00adc560_cls::FUN_00adc560(int a, int b, unsigned int c)
{
    FUN_00adb1a0(9, a, 0, b, 0, NiPoint3_audio((float)c, 0.0f, 0.0f));
}

struct Item_adc910
{
    Item_adc910* m_pkNext;
    unsigned int m_uiKey;
    BADC7D0Item* m_pkVal;
};

class Map_adc910
{
  public:
    virtual ~Map_adc910();
    virtual unsigned int KeyToHashIndex(unsigned int uiKey) const;
    virtual bool IsKeysEqual(unsigned int uiKey1, unsigned int uiKey2) const;
    unsigned int m_uiHashSize;
    Item_adc910** m_ppkHashTable;
    bool FUN_00a1e380(unsigned int uiKey, BADC7D0Item*& pkVal) const
    {
        unsigned int uiIndex = KeyToHashIndex(uiKey);
        Item_adc910* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(uiKey, pkItem->m_uiKey))
            {
                pkVal = pkItem->m_pkVal;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};

struct Loaded_adc910 : BADC7D0Item
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    bool m_bLoadComplete;
    bool IsLoaded() const
    {
        return m_bLoadComplete;
    }
};

struct Cache_adc910
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
    Map_adc910 m_kUnsortedGeometryList;
    char pad70[0x54];
    CritSecA m_kCS;
    bool FUN_00adc910(unsigned int uiKey);
};

// @fnv 0x00adc670
void BSAudioMgr::FUN_00adc670(int id, int param)
{
    if (reinterpret_cast<::Cache_adc910 *>(this)->FUN_00adc910(id))
        return;
    PostMsg(7, id, 0, 0, 0, NiPoint3::ZERO);
    PostMsg(1, id, 0, 0, 0, NiPoint3::ZERO);
    PostMsg(0xb, id, 0, param, 0, NiPoint3::ZERO);
}

// @fnv 0x00adc910
bool Cache_adc910::FUN_00adc910(unsigned int uiKey)
{
    BADC7D0Item* pkItem = 0;
    EnterCriticalSection(&m_kCS);
    bool bResult;
    if (reinterpret_cast<::S_00adc830_Map *>((void *)&(m_kUnsortedGeometryList))->GetAt(uiKey, (::S_00adc830_Entry *&)(pkItem)))
        bResult = pkItem && static_cast<Loaded_adc910*>(pkItem)->IsLoaded();
    else
        bResult = false;
    LeaveCriticalSection(&m_kCS);
    return bResult;
}

struct ScrapHeapBuffer
{
    int unk00, unk04, unk08;
    int used;
    int GetUsed()
    {
        return used;
    }
};

template <class TKey, class TValue> struct BSMapBaseT
{
    struct Item
    {
        Item* next;
        TKey key;
        TValue value;
    };
    virtual unsigned int Hash(TKey key);
    virtual bool Equal(TKey first, TKey second);
    unsigned int bucketCount;
    Item** buckets;
    unsigned int count;
    bool GetAt(TKey key, TValue& value)
    {
        unsigned int bucket = Hash(key);
        Item* item = buckets[bucket];
        while (item)
        {
            if (Equal(key, item->key))
            {
                value = item->value;
                return true;
            }
            item = item->next;
        }
        return false;
    }
};

struct FUN_00adc9a0_shell
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    BSMapBaseT<unsigned long, ScrapHeapBuffer*> heaps;
    int unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90;
    int unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0;
    int unkB4, unkB8, unkBC, unkC0;
    CritSecA criticalSection;
    int FUN_00adc9a0(unsigned long param_2);
};

// @fnv 0x00adc9a0
int FUN_00adc9a0_shell::FUN_00adc9a0(unsigned long param_2)
{
    int uStack2 = 0;
    ScrapHeapBuffer* iStack_c;
    EnterCriticalSection(&criticalSection);
    if (reinterpret_cast<::S_00adc830_Map *>(&(heaps))->GetAt(param_2, (::S_00adc830_Entry *&)(iStack_c)))
    {
        uStack2 = iStack_c == 0 ? 0 : iStack_c->GetUsed();
    }
    else
    {
        uStack2 = 0;
    }
    LeaveCriticalSection(&criticalSection);
    return uStack2;
}

typedef bool(__cdecl* AudioFileResolverD570)(const char* pcName, char* pcPath, unsigned int* puiFlags,
                                             unsigned int* puiExtra);

class AudioSystemD570
{
  public:
    bool IsReady()
    {
        return m_bReady;
    }
    AudioFileResolverD570 GetResolver()
    {
        return m_pfnResolve;
    }

    void* m_pVTable;
    bool m_bReady;
    char m_cUnk05;
    char m_cUnk06;
    char m_cUnk07;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    AudioFileResolverD570 m_pfnResolve;
};

inline AudioSystemD570* GetAudioSystemD570()
{
    return (*reinterpret_cast<::AudioSystemD570 * *>(&::DAT_011f6d98));
}

class AudioManagerD570
{
  public:
    void FUN_00add570(const char* pcName, unsigned int uiFlags);
};

struct SndHandleQ
{
    int m_uiSoundID;
    char bFlag;
    int iData;
    SndHandleQ(int id) : m_uiSoundID(id), bFlag(0), iData(0)
    {}
    ~SndHandleQ()
    {}
};

struct SoundQ3
{
    int unk0;
    int m_uiSoundID;
    int iFlags;
    int iExtra;
    char pad10[0x174 - 0x10];
    int iA;
    int iB;
    void SetAB(int a, int b)
    {
        iA = a;
        iB = b;
    }
    void SetExtra(int e)
    {
        iExtra = e;
    }
};

typedef void(__cdecl* PfnA_Q)(SndHandleQ*, int, int*);

typedef bool(__cdecl* PfnB_Q)(int, int*, int*);

struct AudioQ3
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual PfnB_Q GetPfnB();
    virtual SoundQ3* Create(const char*);
    virtual void Normalize(char*);
    bool bReady;
    char pad5[0x2c - 5];
    PfnA_Q pfnA;
    bool IsReady() const
    {
        return bReady;
    }
    PfnA_Q GetPfnA() const
    {
        return pfnA;
    }
};

inline AudioQ3* GetAudioQ3()
{
    return (AudioQ3*)DAT_011f6d98;
}









struct MgrT
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual Pos3* vfn_3();
};

struct EvtT
{
    virtual void vfn_0();
    virtual bool vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19(Pos3 p);
    int GetID() const
    {
        return f4;
    }
    int GetFlags() const
    {
        return f8;
    }
    bool HasFlag20000() const
    {
        return (f10 & 0x20000) != 0;
    }
    int f4;
    int f8;
    int fc;
    int f10;
};

struct Ptr
{
    ObjT* m_p;
    Ptr(ObjT* p = 0) : m_p(p)
    {
        if (m_p)
            m_p->AcquireReference();
    }
    ~Ptr()
    {
        if (m_p)
            m_p->DecRef();
    }
    operator ObjT*() const
    {
        return m_p;
    }
    ObjT* operator->() const
    {
        return m_p;
    }
    ObjT* Get() const
    {
        return m_p;
    }
    bool IsValid() const
    {
        return m_p != 0;
    }
    void DebugCheck() const
    {
        int a, b;
    }
    void FUN_0066b0d0(ObjT* p);
};





struct BSAudioBig
{
    int unk00, unk04, unk08, unk0C;
    MgrT* m_10;
    static BSAudioBig* GetInstance()
    {
        return (BSAudioBig*)DAT_011f6d98;
    }
    MgrT* GetMgr()
    {
        return m_10;
    }
};

struct MapItem54
{
    MapItem54* next;
    unsigned int key;
    EvtT* val;
};

struct M54
{
    virtual void vfn_0();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int k1, unsigned int k2);
    unsigned int m_uiHashSize;
    MapItem54** m_ppkHashTable;
    unsigned int m_uiCount;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    bool FUN_00a1e380(unsigned int n, EvtT** out)
    {
        unsigned int idx = KeyToHashIndex(n);
        MapItem54* item = m_ppkHashTable[idx];
        while (item)
        {
            if (IsKeysEqual(n, item->key))
            {
                *out = item->val;
                return true;
            }
            item = item->next;
        }
        return false;
    }
};

struct MapItem84
{
    MapItem84* next;
    unsigned int key;
    Ptr val;
};

struct M84
{
    virtual void vfn_0();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int k1, unsigned int k2);
    virtual void vfn_3();
    virtual void ClearValue(MapItem84* item);
    virtual void vfn_5();
    virtual void DeleteItem(MapItem84* item);
    unsigned int n;
    MapItem84** data;
    unsigned int m_uiCount;
    void FUN_00ae7ee0(void** out, unsigned int* pn, Ptr* psp)
    {
        MapItem84* item = (MapItem84*)*out;
        *pn = item->key;
        if (item->next)
        {
            *out = item->next;
            return;
        }
        unsigned int idx = KeyToHashIndex(item->key);
        for (++idx; idx < n; ++idx)
        {
            item = data[idx];
            if (item)
            {
                *out = item;
                return;
            }
        }
        *out = 0;
    }
    bool FUN_00a1e240(unsigned int key)
    {
        unsigned int idx = KeyToHashIndex(key);
        MapItem84* item = data[idx];
        if (item)
        {
            if (IsKeysEqual(key, item->key))
            {
                data[idx] = item->next;
                ClearValue(item);
                DeleteItem(item);
                --m_uiCount;
                return true;
            }
            else
            {
                MapItem84* prev = item;
                MapItem84* curr = prev->next;
                while (curr && !IsKeysEqual(key, curr->key))
                {
                    prev = curr;
                    curr = curr->next;
                }
                if (curr)
                {
                    prev->next = curr->next;
                    ClearValue(curr);
                    DeleteItem(curr);
                    --m_uiCount;
                    return true;
                }
            }
        }
        return false;
    }
    void* FindFirst()
    {
        for (unsigned int k = 0; k < n; k++)
            if (data[k])
                return data[k];
        return 0;
    }
};

struct C_00adea90
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50;
    M54 m54;
    M84 m84;
    void FUN_00adea90();
    void FUN_00adb1a0(int, int, int, int, Ptr, Pos3);
};

// @fnv 0x00adea90
void C_00adea90::FUN_00adea90()
{
    EvtT* pEvt = 0;
    Ptr sp8;
    if (!BSAudioBig::GetInstance()->GetMgr())
        return;
    Pos3 pos4 = *(BSAudioBig::GetInstance()->GetMgr())->vfn_3();
    Pos3 unusedPos;
    Pos3 n3;
    void* objTmp = m84.FindFirst();
    unsigned int v2 = 0;
    unsigned int val4 = 0;
    while (objTmp)
    {
        pEvt = 0;
        reinterpret_cast<::nae7::Map *>(&(m84))->FUN_00ae7ee0((*(::nae7::Item * *)(&objTmp)), (*(unsigned int *)(&v2)), (*(::nae7::Val *)(&sp8)));
        reinterpret_cast<::S_00adc830_Map *>(&(m54))->GetAt(v2, (*(::S_00adc830_Entry * *)(&pEvt)));
        val4 = sp8.IsValid() ? sp8->GetRefCount() : 0;
        if (pEvt && (pEvt->vfn_1() || pEvt->HasFlag20000()) && sp8 && val4 > 2)
        {
            unusedPos = sp8->GetPos();
            if (pEvt->GetFlags() & 4)
                unusedPos.z = (float)(unusedPos.z + DAT_010179e0);
            pEvt->vfn_19(unusedPos);
        }
        else if (pEvt == 0)
        {
            reinterpret_cast<::RMapBase *>(&(m84))->FUN_00a1e240(v2);
            if (sp8)
            {
                Ptr g(sp8.Get());
                sp8.DebugCheck();
                FUN_00c45830(sp8);
                sp8.FUN_0066b0d0(0);
            }
        }
        else if (!sp8)
        {
            FUN_00adb1a0(9, pEvt->GetID(), 0, 1000, 0, Pos3(0));
            reinterpret_cast<::RMapBase *>(&(m84))->FUN_00a1e240(v2);
            if (sp8)
            {
                Ptr p(sp8.Get());
                FUN_00c45830(sp8);
                sp8.FUN_0066b0d0(0);
            }
        }
    }
}

namespace fnv_00adef80 {




struct FUN_00adef80_cls
{
    bool FUN_00adb1a0(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3_audio kPos);
    void FUN_00adef80(NiPoint3_audio kPos);
};
// @fnv 0x00adef80
void FUN_00adef80_cls::FUN_00adef80(NiPoint3_audio kPos)
{
    FUN_00adb1a0(0x38, 0, 0, 0, 0, kPos);
}
}



// namespace fnv_00adf080

namespace fnv_00ae7050 {





class BSGameSound7050
{
  public:
    virtual ~BSGameSound7050();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual bool v09();

    unsigned int GetAudioFlags() const
    {
        return m_uiAudioFlags;
    }
    unsigned int GetID() const
    {
        return m_uiID;
    }
    int Get148() const
    {
        return m_i148;
    }
    void SetPaused(bool bSet)
    {
        m_uiStateFlags = bSet ? (m_uiStateFlags | 0x200) : (m_uiStateFlags & ~0x200);
    }
    void SetStopping(bool bSet)
    {
        m_uiStateFlags = bSet ? (m_uiStateFlags | 0x1000) : (m_uiStateFlags & ~0x1000);
    }
    void SetStopped(bool bSet)
    {
        m_uiStateFlags = bSet ? (m_uiStateFlags | 0x10) : (m_uiStateFlags & ~0x10);
    }

    int unk04;
    unsigned int m_uiAudioFlags;
    int unk0C;
    unsigned int m_uiStateFlags;
    char pad14[0x130];
    unsigned int m_uiID;
    int m_i148;
};

struct BSAudioManager7050
{
    void FUN_00adb1a0(int iMsg, int i1, int i2, BSGameSound7050* SoundAssetTmp, NiPointer<NiRefObject> spRetainedObject,
                      NiPoint3 kPos);
};

inline unsigned int GetCurrentTime7050()
{
    return GetTickCount();
}

extern unsigned int DAT_011f6e0c;
extern unsigned int DAT_011f6e10;

struct AudioLoadTask7050
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    BSGameSound7050* m_pGameSound;

    void FUN_00ae7050();
};

// @fnv 0x00ae7050
void AudioLoadTask7050::FUN_00ae7050()
{
    bool bLoopSound = (m_pGameSound->GetAudioFlags() & 0x8000) != 0;
    bool bResult = false;

    if (m_pGameSound->GetID() == 0 && m_pGameSound->Get148() != 0)
    {
        reinterpret_cast<::BSGameSound *>((m_pGameSound))->LoadFromFilename(true);
        if (reinterpret_cast<::ObjRegistry *>((((::fnv_00ae7050::BSAudioManager7050 *)(::FUN_00ad9060()))))->FUN_00add480(m_pGameSound->GetID(), false))
        {
            if (bLoopSound)
            {
                delete m_pGameSound;
            }
            else
            {
                m_pGameSound->SetPaused(false);
                m_pGameSound->SetStopping(false);
                m_pGameSound->SetStopped(true);
            }
            return;
        }
    }

    if (bLoopSound && DAT_011f6e0c == m_pGameSound->GetID() && GetCurrentTime7050() - DAT_011f6e10 < 1000)
    {
        delete m_pGameSound;
        return;
    }

    bResult = m_pGameSound->v09();
    if (bLoopSound)
    {
        if (bResult)
        {
            DAT_011f6e0c = m_pGameSound->GetID();
            DAT_011f6e10 = GetTickCount();
            ((::fnv_00ae7050::BSAudioManager7050 *)(::FUN_00ad9060()))->FUN_00adb1a0(0x33, 0, 0, m_pGameSound, 0, NiPoint3_ZERO);
        }
        else
        {
            delete m_pGameSound;
        }
    }
}
}





// @fnv 0x00ad9640
void MgrX::FUN_00ad9640()
{
    if (!*GetName())
        return;
    // ? (unsigned char*)g_str_011f6d9c.buf : (g_empty_01202800[0] = 0, (unsigned char*)g_empty_01202800);
    {
        ma4 = 0;
        m17c = 8;
        m178 = new Ent8[m17c];
        ClearX(m178, m17c * 8);
        reinterpret_cast<::FUN_00ad9da0_t *>(this)->InitAudioVolumes();
        unsigned uiCount2 = 0x100;
        unsigned i;
        for (i = 0; i < uiCount2; i++)
            reinterpret_cast<::Stack75f0 *>(&(l24))->FUN_00ae75f0((::SoundMessageRecord *)(::FUN_00ae8650 *)(new FUN_00ae8650));
        *(char*)&p28[0] = 1;
        unsigned j2;
        for (j2 = 0; j2 < uiCount2; j2++)
            reinterpret_cast<::Stack75f0 *>(&(l34))->FUN_00ae75f0((::SoundMessageRecord *)(::FUN_00ae8650 *)(new FUN_00ae8650));
        *(char*)&p38[0] = 1;
        b48 = 0;
        m13c = new FUN_00ae77d0;
        DbgX();
    }
}

inline unsigned int NowA()
{
    unsigned int tick = GetTickCount();
    return tick;
}

// @fnv 0x00ae75f0
void Stack75f0::FUN_00ae75f0(SoundMessageRecord* param_2)
{
    if (param_2 != 0)
    {
        if (this->m_bBottomless && this->iCount > 0x200)
        {
            if ((unsigned int)(NowA() - this->m_uiStackLimit) > 0x3E8)
            {
                delete param_2;
                return;
            }
        }
        PushOne(param_2);
    }
}

namespace fnv_00ae76b0 {







// @fnv 0x00ae76b0
FUN_00ae8650* Pool_ae76b0::FUN_00ae76b0()
{
    FUN_00ae8650* pkNode = 0;
    if (pAudioItems)
    {
        pkNode = pAudioItems;
        pAudioItems = pAudioItems->GetNext();
        pkNode->m_pNext = 0;
        m_uiCount--;
    }
    else if (m_bCanGrow)
    {
        pkNode = new FUN_00ae8650;
        pkNode->m_pNext = 0;
        m_uiLastAlloc = GetTickCount();
    }
    return pkNode;
}
}

// namespace fnv_00ae76b0

namespace fnv_00ae81e0 {

struct MemoryManagerAllocHelper
{
    void Deallocate(void* block);
};

template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList<T>* m_pkNext;

    BSSimpleList(const T& item)
    {
        m_item = item;
        m_pkNext = 0;
    }
    ~BSSimpleList()
    {
        reinterpret_cast<::Node185 *>(this)->FUN_00ae83e0();
    }

    int Count()
    {
        int count = 0;
        BSSimpleList<T>* iterA = this;
        while (iterA)
        {
            if (iterA->m_item)
                count++;
            iterA = iterA->m_pkNext;
        }
        return count;
    }
    void RemoveAll()
    {
        while (m_pkNext)
        {
            BSSimpleList<T>* next = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            delete m_pkNext;
            m_pkNext = next;
        }
        m_item = 0;
    }
    void SetItem(T item)
    {
        if (!item)
            return;
        m_item = item;
    }
    void SortList(int(__cdecl* cmp)(T, T))
    {
        BSSimpleList<T>* current = this;
        BSSimpleList<T>* previous = 0;
        if (current)
        {
            int count = current->Count();
            bool swapped = true;
            while (count && swapped)
            {
                swapped = false;
                while (current)
                {
                    if (previous)
                    {
                        T item = current->m_item;
                        T prevItem = previous->m_item;
                        if (cmp(prevItem, item) > 0)
                        {
                            current->SetItem(prevItem);
                            previous->SetItem(item);
                            swapped = true;
                        }
                    }
                    previous = current;
                    current = current->m_pkNext;
                }
                count--;
            }
        }
    }
    void FUN_00ae8550(T* arr, int(__cdecl* cmp)(T, T), int count)
    {
        int gap = 0;
        int left = 0;
        int right = count - 1;
        for (gap = 1; gap <= (right - left) / 9; gap = 3 * gap + 1)
        {
        }
        for (; gap > 0; gap /= 3)
        {
            for (int i = left + gap; i <= right; i++)
            {
                int j = i;
                T value = arr[i];
                while (j >= left + gap && cmp(value, arr[j - gap]) < 0)
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = value;
            }
        }
    }
    void FUN_00ae81e0(int(__cdecl* cmp)(T, T));
};

// @fnv 0x00ae81e0
template <> void BSSimpleList<unsigned char*>::FUN_00ae81e0(int(__cdecl* cmp)(unsigned char*, unsigned char*))
{
    unsigned char** arr5;
    BSSimpleList<unsigned char*>* node2;
    int i;
    BSSimpleList<unsigned char*>* prev6;
    int j;
    int _num;
    _num = Count();
    arr5 = (unsigned char**)_alloca(_num * 4 + 4);
    if (!arr5)
    {
        reinterpret_cast<::AE8470List *>(this)->SortList((int (*)(AE8470Item *, AE8470Item *))(cmp));
        return;
    }
    node2 = this;
    for (i = 0; i < _num; i++, node2 = node2->m_pkNext)
        arr5[i] = node2->m_item;
    reinterpret_cast<::FUN_00ae8550_shell *>(this)->FUN_00ae8550((int *)(arr5), (int (*)(int, int))(cmp), _num);
    reinterpret_cast<::Node185 *>(this)->FUN_00ae83e0();
    node2 = this;
    prev6 = 0;
    for (j = 0; j < _num; j++)
    {
        if (j > 0)
        {
            node2 = new BSSimpleList<unsigned char*>(arr5[j]);
        }
        else
        {
            node2->m_item = arr5[j];
            node2->m_pkNext = 0;
        }
        if (prev6)
            prev6->m_pkNext = node2;
        prev6 = node2;
    }
}
}

// namespace fnv_00ae81e0


struct MemoryManager8F70
{
    void Deallocate(void* pvMem);
};

struct MapItem8F70
{
    MapItem8F70* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBase8F70
{
  public:
    virtual ~MapBase8F70()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItem8F70* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItem8F70* pkItem);
    virtual MapItem8F70* NewItem();
    virtual void DeleteItem(MapItem8F70* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItem8F70* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItem8F70** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00ae8f70 : public MapBase8F70
{
// @fnv 0x00ae8f70
  public:
    __forceinline FUN_00ae8f70()
    {}
    virtual ~FUN_00ae8f70()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

void* MakeMap8F70()
{
    return new FUN_00ae8f70;
}

struct MemoryManager9060
{
    void Deallocate(void* pvMem);
};

struct MapItem9060
{
    MapItem9060* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBase9060
{
  public:
    virtual ~MapBase9060()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItem9060* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItem9060* pkItem);
    virtual MapItem9060* NewItem();
    virtual void DeleteItem(MapItem9060* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItem9060* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItem9060** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00ae9060 : public MapBase9060
{
// @fnv 0x00ae9060
  public:
    __forceinline FUN_00ae9060()
    {}
    virtual ~FUN_00ae9060()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

void* MakeMap9060()
{
    return new FUN_00ae9060;
}

struct NiRefObjectStub
{
    void* m_pVtbl;
    long m_iRefCount;
    void AddRef()
    {
        InterlockedIncrement(&m_iRefCount);
    }
};

struct NiPointerStub
{
    NiRefObjectStub* m_pObject;
    NiPointerStub(NiRefObjectStub* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->AddRef();
    }
    ~NiPointerStub();
};

struct BSAudioManagerAda
{
    void FUN_00adb1a0(int mode, int a1, int a2, int a3, NiPointerStub sp, NiPoint3 pos);
};

// @fnv 0x00adcc10
void FUN_00adcc10_shell::FUN_00adcc10(int param1, int param2)
{
    if ((unsigned char)param2)
        ((BSAudioManagerAda*)this)->FUN_00adb1a0(0x1d, 0, param1, 0, 0, NiPoint3_ZERO);
    else
        ((BSAudioManagerAda*)this)->FUN_00adb1a0(0x1b, 0, param1, 0, 0, NiPoint3_ZERO);
}

namespace fnv_00ada0f0 {







struct BSSemA0
{
    long m_iArrayLength;
    void* m_pSemaphore;
};

struct AudioThreadA0
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
    BSSemA0 m_kDone;


    void WaitDone()
    {
        BSSemA0* pSem = &m_kDone;
        WaitForSingleObject(pSem->m_pSemaphore, 0xFFFFFFFF);
        InterlockedDecrement(&pSem->m_iArrayLength);
    }
};

struct BSAudioMgrA0
{
    char pad000[0x13c];
    AudioThreadA0* m_pAudioThread;

    void FUN_00adb1a0(int eMsg, unsigned int id, int a3, int a4, NiAVObjPtr obj, NiPoint3 pos);
    void FUN_00ada0f0();
};

// @fnv 0x00ada0f0
void BSAudioMgrA0::FUN_00ada0f0()
{
    if (m_pAudioThread != 0)
    {
        reinterpret_cast<::FUN_00ae78e0_Class *>((m_pAudioThread))->ReleaseSemaphoreAndIncrement();
    }
    FUN_00adb1a0(0x34, 0, 0, 0, 0, NiPoint3::ZERO);
    if (m_pAudioThread != 0)
    {
        m_pAudioThread->WaitDone();
        reinterpret_cast<::FUN_00aa64f0_t *>((m_pAudioThread))->StopAndCloseHandle();
    }
}
}





// namespace fnv_00adad80

namespace fnv_00adafa0 {



struct VectorA
{
    float x, y, z;
};
extern VectorA DAT_011f426c;
struct MessageA
{
    int a, b, c, d;
    NiPointer<NiAVObject> obj;
    VectorA pos;
    __forceinline void SetObj(NP ptr)
    {
        obj = ptr;
    }
    __forceinline void Reset(VectorA position, NiPointer<NiAVObject> empty)
    {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        obj = empty;
        pos.x = position.x;
        pos.y = position.y;
        pos.z = position.z;
    }
};

struct StackA
{
};
struct HostA
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30;
    StackA stack;
    void FUN_00adafa0(MessageA*);
};
// @fnv 0x00adafa0
void HostA::FUN_00adafa0(MessageA* msg)
{
    NiPointer<NiAVObject> object;
    object = msg->obj;
    if (object != 0)
    {
        msg->SetObj(0);
        FUN_00c45830(object.p);
        object = (NiAVObject*)0;
    }
    msg->Reset(DAT_011f426c, 0);
    reinterpret_cast<::Stack75f0 *>(&(stack))->FUN_00ae75f0((::SoundMessageRecord *)(msg));
}
}

// namespace fnv_00adafa0

namespace fnv_00adb1a0 {




struct AudioView
{
    char m_00[5];
    bool m_05;
    bool Ready()
    {
        return m_05;
    }
};
inline bool Ready()
{
    AudioView* a = (AudioView*)DAT_011f6d98;
    bool b = a->m_05;
    return b;
}
inline void SetState(int s)
{
    (*reinterpret_cast<int *>(&::currentAllocationContext)) = s;
}
struct StateGuard
{
    int m_00;
    StateGuard(int s) : m_00(s)
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 11;
    }
    ~StateGuard()
    {
        Dead1();
        SetState(m_00);
    }
};




// @fnv 0x00adb1a0
void Host::FUN_00adb1a0(int a, int b, std::intptr_t c, std::intptr_t d, NavMeshPtr n, Point p)
{
    if (Ready())
    {
        StateGuard guard((*reinterpret_cast<int *>(&::currentAllocationContext)));
        EnterCriticalSection(&m_ac);
        Record* result2 = FUN_00adad60();
        if (result2)
        {
            result2->Set(a, b, c, d, n, p);
            reinterpret_cast<::FUN_00ae8bf0_t *>(&(m_0c[m_04]))->AddItem(&result2);
        }
        LeaveCriticalSection(&m_ac);
    }
    return;
}
}

// namespace fnv_00adb1a0

namespace fnv_00adb3e0 {



extern Point DAT_011f426c;

// @fnv 0x00adb3e0
bool Host::FUN_00adb3e0(unsigned int id, bool flag)
{
    if (reinterpret_cast<::Cache_adc910 *>(this)->FUN_00adc910(id))
        return true;
    if (flag)
        reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x2d, id, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adb3e0::NavMeshPtr &)((RefObject*)0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adb3e0::Point &)(DAT_011f426c)));
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(1, id, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adb3e0::NavMeshPtr &)((RefObject*)0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adb3e0::Point &)(DAT_011f426c)));
    return true;
}
}

// namespace fnv_00adb3e0

namespace fnv_00adb610 {


extern NiPoint3 DAT_011f426c; 



struct Handler_adb610
{
    bool FUN_00adb610(int iArg);
};

// @fnv 0x00adb610
bool Handler_adb610::FUN_00adb610(int iArg)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(4, iArg, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adb610::NiPointer< ::fnv_00adb610::NiRefObject> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adb610::NiPoint3 &)(DAT_011f426c)));
    return false;
}
}

// namespace fnv_00adb610

namespace fnv_00adb690 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adb690_cls
{
    void FUN_00adb690(NiRefObject_audio* pObj, float fSeconds, int c);
};
// @fnv 0x00adb690
void FUN_00adb690_cls::FUN_00adb690(NiRefObject_audio* pObj, float fSeconds, int c)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x29, 0, (int)(fSeconds * 1000.0), c, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adb690::NiPointer_audio< ::fnv_00adb690::NiRefObject_audio> &)(pObj)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adb690::NiPoint3_audio &)(DAT_011f426c)));
}
}

// namespace fnv_00adb690

namespace fnv_00adb970 {







struct FUN_00adb970_cls
{
    bool FUN_00adb970(int a1, float x, float y, float z);
};

// @fnv 0x00adb970
bool FUN_00adb970_cls::FUN_00adb970(int a1, float x, float y, float z)
{
    NiPoint3 kPos;
    kPos.x = x;
    kPos.y = y;
    kPos.z = z;
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x1e, a1, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adb970::NiPointer< ::fnv_00adb970::NiRefObject> &)(NiPointer<NiRefObject>(0))), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adb970::NiPoint3 &)(kPos)));
    return false;
}
}

// namespace fnv_00adb970

namespace fnv_00adb9f0 {





struct AudioManagerTarget
{
    bool FUN_00adb9f0(unsigned int id, float x, float y, float z);
};
// @fnv 0x00adb9f0
bool AudioManagerTarget::FUN_00adb9f0(unsigned int id, float x, float y, float z)
{
    NiPoint3 position(x, y, z);
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(31, id, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adb9f0::NiPointer< ::fnv_00adb9f0::NiAVObject> &)(NiPointer<NiAVObject>())), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adb9f0::NiPoint3 &)(position)));
    return false;
}
}

// namespace fnv_00adb9f0

namespace fnv_00adba70 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adba70_cls
{
    void FUN_00adba70(int a, float fB, float fC);
};
// @fnv 0x00adba70
void FUN_00adba70_cls::FUN_00adba70(int a, float fB, float fC)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x23, a, (unsigned int)(fB * 1000.0), (unsigned int)(fC * 1000.0), (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adba70::NiPointer_audio< ::fnv_00adba70::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adba70::NiPoint3_audio &)(DAT_011f426c)));
}
}

// namespace fnv_00adba70

namespace fnv_00adbb30 {


inline void Dead6()
{
    int a[6];
}
inline void Dead8()
{
    int a[8];
}






extern Vector3 NiPoint3_ZERO;



__forceinline const FUN_00ae86d0& Pass(const FUN_00ae86d0& m)
{
    return m;
}
__forceinline int GetCtx()
{
    return (*reinterpret_cast<int *>(&::currentAllocationContext));
}
__forceinline void SetCtx(int value)
{
    (*reinterpret_cast<int *>(&::currentAllocationContext)) = value;
}

struct AutoMemContext
{
    int previous;
    __forceinline AutoMemContext(int value)
    {
        previous = GetCtx();
        SetCtx(value);
    }
    __forceinline ~AutoMemContext()
    {
        SetCtx(previous);
    }
};

struct Queue12
{
    int unk00, unk04, unk08;
};

struct AudioState
{
    int unk00;
    bool unk04;
    bool threaded;
};

__forceinline bool IsThreaded()
{
    AudioState* audio = (AudioState*)DAT_011f6d98;
    return audio->threaded;
}
struct AudioOwner
{
    int unk00;
    int queueIndex;
    int unk08;
    Queue12 queue0, queue1, queue2, queue3, queue4, queue5, queue6, queue7, queue8, queue9, queue10, queue11, queue12;
    int unkA8;
    CritSecA critical;
    FUN_00ae86d0* FUN_00adad60();
    void FUN_00adbb30(int id, unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e);
};

// @fnv 0x00adbb30
void AudioOwner::FUN_00adbb30(int id, unsigned short a, unsigned short b, unsigned short c, unsigned short d,
                              unsigned short e)
{
    unsigned short contour[5];
    contour[0] = a <= 100 ? a : 100;
    contour[1] = b <= 100 ? b : 100;
    contour[2] = c <= 100 ? c : 100;
    contour[3] = d <= 100 ? d : 100;
    contour[4] = e <= 100 ? e : 100;
    if (IsThreaded())
    {
        AutoMemContext context(11);
        EnterCriticalSection(&critical);
        FUN_00ae86d0* message = FUN_00adad60();
        reinterpret_cast<::Msg_ae7990 *>((message))->CopyFrom((const ::Msg_ae7990 &)(static_cast<const FUN_00ae86d0&>(FUN_00ae86d0(id, (RefObject*)0, NiPoint3_ZERO))));
        Dead6();
        message->SetValue(0, contour[0]);
        message->SetValue(1, contour[1]);
        message->SetValue(2, contour[2]);
        message->SetValue(3, contour[3]);
        message->SetValue(4, contour[4]);
        reinterpret_cast<::FUN_00ae8bf0_t *>(&((&queue0)[queueIndex]))->AddItem(&message);
        LeaveCriticalSection(&critical);
        Dead2();
    }
}
}

// namespace fnv_00adbb30

namespace fnv_00adbec0 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adbec0_cls
{
    void FUN_00adbec0(int a, unsigned short b);
};
// @fnv 0x00adbec0
void FUN_00adbec0_cls::FUN_00adbec0(int a, unsigned short b)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x22, a, b, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adbec0::NiPointer_audio< ::fnv_00adbec0::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adbec0::NiPoint3_audio &)(DAT_011f426c)));
}
}

// namespace fnv_00adbec0

namespace fnv_00adbf50 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adbf50_cls
{
    bool FUN_00adbf50(int a);
};
// @fnv 0x00adbf50
bool FUN_00adbf50_cls::FUN_00adbf50(int a)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x26, a, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adbf50::NiPointer_audio< ::fnv_00adbf50::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adbf50::NiPoint3_audio &)(DAT_011f426c)));
    return true;
}
}

// namespace fnv_00adbf50

namespace fnv_00adbfd0 {
struct NiPoint3_adbfd0
{
    float x, y, z;
};
extern NiPoint3_adbfd0 DAT_011f426c;
struct NiRefObject_adbfd0
{
    virtual ~NiRefObject_adbfd0();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_adbfd0
{
    NiPointer_adbfd0(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_adbfd0()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
struct FUN_00adbfd0_cls
{
    bool FUN_00adbfd0(intptr_t a, std::intptr_t b, std::intptr_t c);
};
// @fnv 0x00adbfd0
bool FUN_00adbfd0_cls::FUN_00adbfd0(intptr_t a, std::intptr_t b, std::intptr_t c)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x3a, a, c, b, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adbfd0::NiPointer_adbfd0< ::fnv_00adbfd0::NiRefObject_adbfd0> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adbfd0::NiPoint3_adbfd0 &)(DAT_011f426c)));
    return true;
}
}

// namespace fnv_00adbfd0

namespace fnv_00adc050 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adc050_cls
{
    bool FUN_00adc050(intptr_t a, std::intptr_t b, std::intptr_t c);
};
// @fnv 0x00adc050
bool FUN_00adc050_cls::FUN_00adc050(intptr_t a, std::intptr_t b, std::intptr_t c)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x3b, a, c, b, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adc050::NiPointer_audio< ::fnv_00adc050::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adc050::NiPoint3_audio &)(DAT_011f426c)));
    return true;
}
}

// namespace fnv_00adc050

namespace fnv_00adc0d0 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adc0d0_cls
{
    bool FUN_00adc0d0(int a, float fSeconds);
};
// @fnv 0x00adc0d0
bool FUN_00adc0d0_cls::FUN_00adc0d0(int a, float fSeconds)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x10, a, (int)(fSeconds * 1000.0), 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adc0d0::NiPointer_audio< ::fnv_00adc0d0::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adc0d0::NiPoint3_audio &)(DAT_011f426c)));
    return true;
}
}

// namespace fnv_00adc0d0

namespace fnv_00adc160 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adc160_cls
{
    void FUN_00adc160();
};
// @fnv 0x00adc160
void FUN_00adc160_cls::FUN_00adc160()
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0xe, 0, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adc160::NiPointer_audio< ::fnv_00adc160::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adc160::NiPoint3_audio &)(DAT_011f426c)));
}
}

// namespace fnv_00adc160

namespace fnv_00adc1e0 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adc1e0_cls
{
    void FUN_00adc1e0(int a, NiRefObject_audio* pObj);
};
// @fnv 0x00adc1e0
void FUN_00adc1e0_cls::FUN_00adc1e0(int a, NiRefObject_audio* pObj)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x27, a, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adc1e0::NiPointer_audio< ::fnv_00adc1e0::NiRefObject_audio> &)(pObj)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adc1e0::NiPoint3_audio &)(DAT_011f426c)));
}
}

// namespace fnv_00adc1e0

namespace fnv_00adc360 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adc360_cls
{
    void FUN_00adc360(int a, int b);
};
// @fnv 0x00adc360
void FUN_00adc360_cls::FUN_00adc360(int a, int b)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x3c, a, b, b, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adc360::NiPointer_audio< ::fnv_00adc360::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adc360::NiPoint3_audio &)(DAT_011f426c)));
}
}

// namespace fnv_00adc360

namespace fnv_00adc3e0 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adc3e0_cls
{
    void FUN_00adc3e0(int a);
};
// @fnv 0x00adc3e0
void FUN_00adc3e0_cls::FUN_00adc3e0(int a)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x3d, a, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adc3e0::NiPointer_audio< ::fnv_00adc3e0::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adc3e0::NiPoint3_audio &)(DAT_011f426c)));
}
}

// namespace fnv_00adc3e0

namespace fnv_00adc460 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adc460_cls
{
    void FUN_00adc460(int a, int b);
};
// @fnv 0x00adc460
void FUN_00adc460_cls::FUN_00adc460(int a, int b)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x41, a, b, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adc460::NiPointer_audio< ::fnv_00adc460::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adc460::NiPoint3_audio &)(DAT_011f426c)));
}
}

// namespace fnv_00adc460

namespace fnv_00adc4e0 {


extern NiPoint3 DAT_011f426c; 



struct Handler_adb610
{
    void FUN_00adc4e0(int iArg, bool bFlag1, bool bFlag2);
};

// @fnv 0x00adc4e0
void Handler_adb610::FUN_00adc4e0(int iArg, bool bFlag1, bool bFlag2)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x3e, iArg, bFlag1, bFlag2, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adc4e0::NiPointer< ::fnv_00adc4e0::NiRefObject> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adc4e0::NiPoint3 &)(DAT_011f426c)));
}
}

// namespace fnv_00adc4e0

namespace fnv_00adc5f0 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adc5f0_cls
{
    void FUN_00adc5f0(int a, int b, int c);
};
// @fnv 0x00adc5f0
void FUN_00adc5f0_cls::FUN_00adc5f0(int a, int b, int c)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0xb, a, 0, b, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adc5f0::NiPointer_audio< ::fnv_00adc5f0::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adc5f0::NiPoint3_audio &)(DAT_011f426c)));
}
}

// namespace fnv_00adc5f0

namespace fnv_00adca20 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adca20_cls
{
    void FUN_00adca20(int a, int b, int c);
};
// @fnv 0x00adca20
void FUN_00adca20_cls::FUN_00adca20(int a, int b, int c)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x18, c, a, b, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adca20::NiPointer_audio< ::fnv_00adca20::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adca20::NiPoint3_audio &)(DAT_011f426c)));
}
}



// namespace fnv_00adcaa0

namespace fnv_00adcd00 {
struct NiPoint3_audio
{
    float x, y, z;
};
struct NiRefObject_audio
{
    virtual ~NiRefObject_audio();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount();
};
template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject_audio> NiRefObjectPtr_audio;
extern NiPoint3_audio DAT_011f426c;
struct FUN_00adcd00_cls
{
    void FUN_00adcd00(int a, int b);
};
// @fnv 0x00adcd00
void FUN_00adcd00_cls::FUN_00adcd00(int a, int b)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x2a, 0, a, b, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00adcd00::NiPointer_audio< ::fnv_00adcd00::NiRefObject_audio> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00adcd00::NiPoint3_audio &)(DAT_011f426c)));
}
}

namespace fnv_00adddd0 {
extern "C" double __cdecl fabs(double);














struct AudioDevice
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Update();
};
struct AudioView
{
    unsigned int unk00, unk04, unk08, unk0c;
    AudioDevice* device;
    AudioDevice* GetDevice()
    {
        return device;
    }
};
inline AudioView* Instance()
{
    return (*reinterpret_cast<::fnv_00adddd0::AudioView * *>(&::DAT_011f6d98));
}
struct PointAudio
{
    unsigned int x, y, z;
};


inline void SafeDelete(GameSound* value)
{
    delete value;
}

// @fnv 0x00adddd0
void AudioUpdate::FUN_00adddd0()
{
    PointAudio origin41;
    GameSound* sound1;
    SoundEntry* entry24;
    unsigned int cursor5;
    unsigned int previousVal4 = lastTick;
    float difference5 = 0.0f;
    float volume2 = 1.0f;
    if (!Instance()->GetDevice())
        return;
    lastTick = GetTickCount() - previousVal4;
    float target2 = ::DAT_011ac3a0;
    if (target2 < 0.25)
        target2 = 0.25f;
    if (forceVolume)
        target2 = 1.0f;
    SoundPtr node2A = 0;
    {
        bool result = true;
        sound1 = 0;
        origin41.x = DAT_011f426c;
        origin41.y = (*reinterpret_cast<unsigned int *>(&::_DAT_011f4270));
        origin41.z = (*reinterpret_cast<unsigned int *>(&::_DAT_011f4274));
        cursor5 = 0;
        entry24 = sounds.First();
        while (entry24)
        {
            reinterpret_cast<::RecursiveLock *>(&(sounds))->Unlock((::BSCriticalSectionEntry **)(::fnv_00adddd0::SoundEntry **)(&entry24), &cursor5, (void **)(::fnv_00adddd0::GameSound **)(&sound1));
            if (sound1->Has(1) && !sound1->Has(0x800) && sound1->Has(0x100))
            {
                sound1->Prepare();
                reinterpret_cast<::Owner *>(this)->AddSound((::Sound *)(sound1));
                if (sound1->Has(0x800) && sound1->Has(0x100) && sound1->HasMessages())
                {
                    Message* message10 = 0;
                    FUN_00a1b940* source9 = &sound1->messages;
                    FUN_00a1b940 temporary;
                    MsgNode* item9 = 0;
                    while (!source9->Empty())
                    {
                        temporary.Push(((::fnv_00adddd0::Message *)(reinterpret_cast<::SndStack70 *>((source9))->FUN_00ae7f90())));
                    }
                    item9 = temporary.head;
                    while (item9)
                    {
                        message10 = temporary.GetNext(item9);
                        if (message10)
                        {
                            if (message10->Type() == 30)
                                reinterpret_cast<::fnv_00adf080::BSAudioManager_adf080 *>(this)->FUN_00adf080((::fnv_00adf080::SoundMessageRecord *)(message10));
                        }
                    }
                    while (!temporary.Empty())
                    {
                        message10 = ((::fnv_00adddd0::Message *)(reinterpret_cast<::SndStack70 *>(&(temporary))->FUN_00ae7f90()));
                        result = reinterpret_cast<::fnv_00adf080::BSAudioManager_adf080 *>(this)->FUN_00adf080((::fnv_00adf080::SoundMessageRecord *)(message10));
                        reinterpret_cast<::fnv_00adafa0::HostA *>(this)->FUN_00adafa0((::fnv_00adafa0::MessageA *)(message10));
                        message10 = 0;
                    }
                }
            }
            if (sound1->Has(1) && sound1->Has(0x800) && sound1->Has(0x100))
            {
                if (!sound1->Has(0x10000) && !reinterpret_cast<::SoundRange_00ae9b50 *>((sound1))->FUN_00ae9b50(0, range))
                {
                    sound1->SetRange(true);
                }
                else if (sound1->Has(0x10000) && reinterpret_cast<::SoundRange_00ae9b50 *>((sound1))->FUN_00ae9b50(0, range))
                {
                    sound1->SetRange(false);
                }
                sound1->Update(0);
            }
            if (sound1->Has(0x2000) && !sound1->Playing())
            {
                if ((sound1->Flags() & 0x100) && !sound1->Paused() && sound1->Has(0x800))
                {
                    sound1->SetStopped(true);
                }
            }
            if (sound1->Has(0x10) && !sound1->Has(0x200) && !sound1->Has(0x1000))
            {
                if (sound1->Delay() > 0)
                {
                    unsigned int remaining = sound1->Delay() > lastTick ? sound1->Delay() - lastTick : 0;
                    sound1->SetDelay(remaining);
                }
            }
            if (sound1->Has(0x10) && !sound1->Has(0x200) && !sound1->Has(0x1000) && sound1->Delay() == 0)
            {
                sound1->Update(0);
                void(__cdecl * callback)(unsigned int, bool) = sound1->Callback();
                if (callback)
                {
                    callback(sound1->CallbackArg(), sound1->Has(0x100));
                }
                reinterpret_cast<::RMapBase *>(&(sounds))->FUN_00a1e240(sound1->ID());
                reinterpret_cast<::E60Map *>(&(nodes))->LookupValue(sound1->ID(), (*(::E60Val *)(&node2A)));
                reinterpret_cast<::RMapBase *>(&(nodes))->FUN_00a1e240(sound1->ID());
                if (node2A.ptr)
                {
                    FUN_00c45830(node2A.ptr);
                    node2A.FUN_0066b0d0(0);
                }
                if (sound1->HasMessages())
                {
                    Message* message10 = 0;
                    FUN_00a1b940* source9 = &sound1->messages;
                    while (source9 && !source9->Empty())
                    {
                        message10 = ((::fnv_00adddd0::Message *)(reinterpret_cast<::SndStack70 *>((source9))->FUN_00ae7f90()));
                        reinterpret_cast<::fnv_00adafa0::HostA *>(this)->FUN_00adafa0((::fnv_00adafa0::MessageA *)(message10));
                        message10 = 0;
                    }
                }
                FUN_00ada5d0(sound1->ID(), 0);
                GameSound* doomed = sound1;
                delete doomed;
                sound1 = 0;
                continue;
            }
            else if (sound1->Has(0x800))
                FUN_00ada5d0(sound1->ID(), sound1);
            if ((reinterpret_cast<::BSGameSound *>((sound1))->HasSoundFlagTwo() || reinterpret_cast<::BSGameSound *>((sound1))->CanStartPlayback()) && !sound1->Flag(0x100) && !sound1->Has(0x20000) &&
                sound1->Playing() && sound1->Looping() && !sound1->Flag(0x2000000) &&
                sound1->Position() > sound1->Duration() * 1.05)
            {
                sound1->Stop();
                sound1->Pause(true);
            }
            else if (sound1->Has(0x20000) && !sound1->Paused() && sound1->Position() < sound1->Duration())
            {
                sound1->Pause(false);
                sound1->Resume(true);
            }
            volume2 = sound1->GetVolume();
            difference5 = target2 - volume2;
            bool fixed9 = sound1->Flag(0x80);
            bool increase = difference5 < 0.0;
            if ((float)fabs(difference5) > 0.01f && (!fixed9 || increase) && sound1->Has(0x800))
            {
                if (!(sound1->Flags() & 0x400000))
                {
                    if (!(sound1->Flags() & 0x100000))
                    {
                        if (!(sound1->Flags() & 0x800))
                        {
                            if (!(sound1->Flags() & 0x20))
                            {
                                if (!(sound1->Flags() & 0x200000))
                                    sound1->SetVolume(target2);
                            }
                        }
                    }
                }
            }
        }
    }
    dirty = false;
    reinterpret_cast<::C_00adea90 *>(this)->FUN_00adea90();
    Instance()->GetDevice()->Update();
    lastTick = GetTickCount();
}
}

// namespace fnv_00adddd0

namespace fnv_00ae5a50 {
// reconstruction of 0x00ae5a50
  // MemoryManager singleton
struct AudioSetting_00ae5a50
{
    void* vtable;
    float value;
    const char* name;
};
  // Setting<float> object

inline float& GetVolume_00ae5a50()
{
    return &(*reinterpret_cast<::fnv_00ae5a50::AudioSetting_00ae5a50 *>(&::g_011f6e68)) ? (*reinterpret_cast<::fnv_00ae5a50::AudioSetting_00ae5a50 *>(&::g_011f6e68)).value : (*(float*)&DAT_01202800 = 0.0f, *(float*)&DAT_01202800);
}

struct Pos3_00ae5a50
{
    float x, y, z;
};
extern Pos3_00ae5a50 DAT_011f426c;

struct R_00ae5a50
{
    int f0;
    char f4;
    int f8;
    inline R_00ae5a50(int id) : f0(id), f4(0), f8(0)
    {}
    inline R_00ae5a50(const R_00ae5a50& r) : f0(r.f0), f4(r.f4), f8(r.f8)
    {}
    ~R_00ae5a50()
    {}
};

struct MemPool_00ae5a50
{
};

struct Sub18_00ae5a50
{
    char* name;
    char nameBuf[260];
    char* source;
    char sourceBuf[260];
    float f210;
    float f214;
    Pos3_00ae5a50 position;
    int f224;
    float f228;
    float f22c;
    int f230;
    int f234;
    int f238;
    inline void FUN_00ae8770()
    {
        nameBuf[0] = 0;
        sourceBuf[0] = 0;
        name = nameBuf;
        source = sourceBuf;
        f210 = 0.0f;
        f214 = 0.0f;
        position = DAT_011f426c;
        f224 = 0;
        f228 = 0.0f;
        f22c = 0.0f;
        f230 = 0;
        f234 = 0;
        f238 = 0;
    }
};

struct Msg_00ae5a50
{
    int f0;
    int unk04;
    int unk08;
    int fC;
    int f10;
    char f14;

    Sub18_00ae5a50 sub18;
    inline void SetC(int v)
    {
        fC = v;
    }
    inline void Set10(int v)
    {
        f10 = v;
    }
    inline void Set14(char v)
    {
        f14 = v;
    }
    inline Msg_00ae5a50(int id)
    {
        new ((void *)&(sub18)) ::BSAudioDefinition();
        f0 = id;
        SetC(0);
        Set10(0);
        Set14(0);
    }
};

struct RefObj_00ae5a50
{
    virtual void v0();
    long m_iObjectReferenceCount;
};

struct PtrArg_00ae5a50
{
    RefObj_00ae5a50* m_p;
    inline PtrArg_00ae5a50(RefObj_00ae5a50* p) : m_p(p)
    {
        if (m_p)
        {
            RefObj_00ae5a50* ref = m_p;
            InterlockedIncrement(&ref->m_iObjectReferenceCount);
        }
    }
    inline PtrArg_00ae5a50(const PtrArg_00ae5a50& rhs) : m_p(rhs.m_p)
    {
        if (m_p)
        {
            RefObj_00ae5a50* ref = m_p;
            InterlockedIncrement(&ref->m_iObjectReferenceCount);
        }
    }
    inline ~PtrArg_00ae5a50()
    {
        if (m_p)
            InterlockedDecrement(&m_p->m_iObjectReferenceCount);
    }
};

struct Sound10_00ae5a50
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual int v11();
};

struct Sound_00ae5a50
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int);
    int m_04;
    int m_08;
    unsigned int m_0c;
    char pad010[0x150];
    unsigned int m_160;
    char pad164[0x10];
    unsigned int m_174;
    unsigned int m_178;
    inline void SetFreq(unsigned int v)
    {
        m_160 = v;
    }
    inline void SetMeta(unsigned int v)
    {
        m_0c = v;
    }
    inline int ID()
    {
        return m_04;
    }
    inline void SetPair(unsigned int a, unsigned int b)
    {
        m_174 = a;
        m_178 = b;
    }
};

struct AudioBig_00ae5a50
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* v04();
    virtual Sound_00ae5a50* v05(char*);
    inline bool IsMT()
    {
        return bIsMultiThreaded;
    }
    inline void* Get10()
    {
        return m_10;
    }
    inline void* GetCallback()
    {
        return m_2c;
    }
    bool bIsMultiThreaded;
    int unk08;
    int unk0c;
    void* m_10;
    char pad14[0x18];
    void* m_2c;
};

inline AudioBig_00ae5a50* AudioInstance_00ae5a50()
{
    return (AudioBig_00ae5a50*)DAT_011f6d98;
}
inline bool AudioMT_00ae5a50()
{
    AudioBig_00ae5a50* pa = (AudioBig_00ae5a50*)DAT_011f6d98;
    return pa->bIsMultiThreaded;
}
inline void* Audio10_00ae5a50()
{
    AudioBig_00ae5a50* pa = (AudioBig_00ae5a50*)DAT_011f6d98;
    return pa->m_10;
}
inline void* AudioCB_00ae5a50()
{
    AudioBig_00ae5a50* pa = (AudioBig_00ae5a50*)DAT_011f6d98;
    return pa->m_2c;
}

struct AudioMapNode_00ae5a50
{
    AudioMapNode_00ae5a50* next;
    int key;
    Msg_00ae5a50* value;
};
struct MsgStack_00ae5a50
{
    virtual void Destroy();
    virtual unsigned int Hash(int key);
    virtual bool Equal(int key, int other);
    virtual void SetValue(AudioMapNode_00ae5a50*, int, Msg_00ae5a50*);
    virtual void ClearValue(AudioMapNode_00ae5a50*);
    virtual AudioMapNode_00ae5a50* NewNode();
    unsigned int hashSize;
    AudioMapNode_00ae5a50** buckets;
    unsigned int count;
    inline void InsertOrUpdate(int key, Msg_00ae5a50* value)
    {
        unsigned int hash = Hash(key);
        AudioMapNode_00ae5a50* node = buckets[hash];
        unsigned int scanned = 0;
        for (; node; node = node->next)
        {
            ++scanned;
            if (Equal(key, node->key))
            {
                node->value = value;
                return;
            }
        }
        node = NewNode();
        SetValue(node, key, value);
        node->next = buckets[hash];
        buckets[hash] = node;
        ++count;
    }
};

struct Mgr_00ae5a50
{
    char pad000[0x64];
    MsgStack_00ae5a50 stack;
    char pad074[0x50];
    CritSecA m_cs;
    char pad0dc[0xa4];
    int m_180;

    R_00ae5a50 FUN_00ae5a50(char* apName, int aiFlags, void* ap5);
};

typedef int(__cdecl* PFn1_00ae5a50)(R_00ae5a50*, void*, int*);
typedef bool(__cdecl* PFn2_00ae5a50)(void*, int*, int*);

// @fnv 0x00ae5a50
R_00ae5a50 Mgr_00ae5a50::FUN_00ae5a50(char* apName, int aiFlags, void* ap5)
{
    if (!AudioInstance_00ae5a50()->IsMT())
    {
        return R_00ae5a50(-1);
    }
    int iID4 = this->m_180++;
    if (!*apName)
    {
        ::FUN_005b5e40();
        return R_00ae5a50(-1);
    }
    if (!(aiFlags & 1) && !(aiFlags & 2))
    {
        ::FUN_005b5e40();
        aiFlags |= 1;
    }
    Sound_00ae5a50* local1417 = (*(AudioBig_00ae5a50* volatile*)&DAT_011f6d98)->v05(apName);
    local1417->m_08 = aiFlags;
    local1417->m_04 = iID4;
    local1417->SetFreq((unsigned int)(GetVolume_00ae5a50() * 1000.0));
    if (AudioInstance_00ae5a50()->Get10())
    {
        local1417->v06(((Sound10_00ae5a50*)AudioInstance_00ae5a50()->Get10())->v11());
    }
    R_00ae5a50 result300(iID4);
    EnterCriticalSection(&this->m_cs);
    Msg_00ae5a50* local12 = 0;
    local12 = new Msg_00ae5a50(iID4);
    reinterpret_cast<::FUN_00a0c6c0_cls *>(&(this->stack))->InsertOrUpdate(iID4, (::AnimSequenceBase *)(local12));
    LeaveCriticalSection(&this->m_cs);
    int iResult3 = 0;
    int iOut5 = 0;
    void* local141 = AudioInstance_00ae5a50()->GetCallback();
    if (ap5 && local141)
    {
        iResult3 = ((PFn1_00ae5a50)local141)(&result300, ap5, &iOut5);
    }
    local1417->SetMeta(iOut5);
    if (iResult3)
    {
        if (iResult3 & 0x8000000)
        {
            aiFlags &= ~2;
            aiFlags |= 1;
            aiFlags |= 0x8000000;
        }
        if ((iResult3 & 0x10) || (iResult3 & 0x2000000) || (iResult3 & 0x4000000))
        {
            aiFlags &= ~0x6000010;
            aiFlags |= iResult3 & 0x6000010;
        }
        local1417->m_08 = aiFlags;
    }
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x25, local1417->ID(), 0, (std::intptr_t)(local1417), (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::fnv_00ae5a50::PtrArg_00ae5a50 &)(PtrArg_00ae5a50((RefObj_00ae5a50*)0))), (*(::fnv_00adb1a0::Point *)&(const ::fnv_00ae5a50::Pos3_00ae5a50 &)(DAT_011f426c)));
    if (ap5 && local141)
    {
        iResult3 = ((PFn1_00ae5a50)local141)(&result300, ap5, 0);
    }
    void* local14 = (*(AudioBig_00ae5a50* volatile*)&DAT_011f6d98)->v04();
    int iA2 = 0;
    int local13 = 0;
    if (local14)
    {
        if (((PFn2_00ae5a50)local14)(ap5, &iA2, &local13))
        {
            local1417->SetPair(iA2, local13);
        }
    }
    return result300;
}
}

// namespace fnv_00ae5a50

namespace fnv_00ae7550 {





struct List_ae7550
{
    unsigned int m_uiCount;
    int unk04;
    FUN_00ae86d0* m_pHead;
    void FUN_00ae7550();
};
// @fnv 0x00ae7550
void List_ae7550::FUN_00ae7550()
{
    FUN_00ae86d0* pkNode = 0;
    while (m_pHead)
    {
        pkNode = m_pHead;
        m_pHead = m_pHead->GetNext();
        m_uiCount--;
        pkNode->m_pNext = 0;
        delete pkNode;
    }
}
}

// namespace fnv_00ae7550

namespace fnv_00ae9150 {


struct S00ae9150_Pool
{
    void FUN_00aa4060(void* apMemory);
};

struct S00ae9150_Guard
{
    int unk00;
    inline S00ae9150_Guard()
    {}
    inline ~S00ae9150_Guard()
    {}
};

struct S00ae9150_Obj
{
    void* m_vptr;
    int unk04;
    void* m_08;

    S00ae9150_Obj* FUN_00ae9150(unsigned int aFlags);
};

// @fnv 0x00ae9150
S00ae9150_Obj* S00ae9150_Obj::FUN_00ae9150(unsigned int aFlags)
{
    int u1;
    int u2;
    int u3;
    m_vptr = &(*reinterpret_cast<char *>(&::DAT_010a3308));
    {
        S00ae9150_Guard guard;
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
    m_vptr = &(*reinterpret_cast<char *>(&::DAT_010a33b0));
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(m_08);
    if (aFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ae9150::S00ae9150_Pool *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}
}

// namespace fnv_00ae9150

struct FUN_00adb8e0_cls
{
    bool FUN_00adb8e0(int a, bool b);
};

// @fnv 0x00adb8e0
bool FUN_00adb8e0_cls::FUN_00adb8e0(int a, bool b)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>((((DetectOwner*)this)))->FUN_00adb1a0(0x14, a, b, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::DetectRefPtr &)(DetectRefPtr(0))), (*(::fnv_00adb1a0::Point *)&(const ::DetectPoint3 &)(DAT_011f426c)));
    return false;
}

struct S00adc260_NiRefObjectA
{
    void* vtbl;
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
};

template <class T> struct S00adc260_NiPointerA
{
    T* m_pObject;
    ~S00adc260_NiPointerA()
    {}
    S00adc260_NiPointerA(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
};

struct S00adc260_SoundOwnerA
{
    void FUN_00adc260(int a, int b);
};

// @fnv 0x00adc260
void S00adc260_SoundOwnerA::FUN_00adc260(int a, int b)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x3f, a, b, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::S00adc260_NiPointerA< ::S00adc260_NiRefObjectA> &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::DetectPoint3 &)(DAT_011f426c)));
}

struct FUN_00adeff0_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    unsigned char unk174;
    unsigned char m_bState;
    void FUN_00adeff0(unsigned char bNew);
};

// @fnv 0x00adeff0
void FUN_00adeff0_cls::FUN_00adeff0(unsigned char bNew)
{
    if (bNew != m_bState)
    {
        m_bState = bNew;
        reinterpret_cast<::fnv_00adb1a0::Host *>((((DetectOwner*)this)))->FUN_00adb1a0(0x37, 0, 0, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::DetectRefPtr &)(DetectRefPtr(0))), (*(::fnv_00adb1a0::Point *)&(const ::DetectPoint3 &)(DAT_011f426c)));
    }
}

struct Param2Ada;

extern float DAT_01094c4c;

extern double DAT_010a3470;

struct SettingQ
{
    void* m_pVtbl;
    int m_iValue;
};

struct Vec3
{
    float x, y, z;
    __forceinline Vec3()
    {}
};

struct DebugInit
{
};

struct DebugInfo
{
    char pad000[0x108];
    char* pSelf;
    char name[0x104];
    float f210, f214, f218, f21c, f220;
    int unk224, unk228, unk22c;
    int i230, i234, i238;
    void SetName(Param2Ada* sound);
    __forceinline DebugInfo()
    {
        new ((void *)(((DebugInit*)this))) ::BSAudioDefinition();
    }
    __forceinline ~DebugInfo()
    {
        reinterpret_cast<::BSAudioDefinition *>((((DebugInit*)this)))->BSAudioDefinition::~BSAudioDefinition();
    }
};

struct InfoHead
{
    int d0;
    float d4, d8;
    int d12, d16;
    bool d20;
};

struct SoundDtor
{
    void FUN_00ae8af0();
};

struct DebugPlain
{
    char pad000[0x108];
    char* pSelf;
    char name[0x104];
    float f210, f214, f218, f21c, f220;
    int unk224, unk228, unk22c;
    int i230, i234, i238;
};

struct SoundInfoWrap
{
    FUN_00ae89f0 head;
    char pad01c[0x238];
    __forceinline ~SoundInfoWrap()
    {
        reinterpret_cast<::BSSoundInfo *>((((SoundDtor*)this)))->BSSoundInfo::~BSSoundInfo();
    }
};

struct TempInfo
{
    int b0;
    float b4, b8;
    int b12, b16;
    bool b20;
    DebugPlain debug;
    __forceinline TempInfo(bool debug3, float debug4, int debugB, int debugRoll4, int debug_2)
    {
        new ((void *)&(debug)) ::BSAudioDefinition();
        b0 = debugB;
        b4 = 1.0f;
        b8 = debug4;
        b12 = debugRoll4;
        b16 = debug_2;
        b20 = debug3;
    }
    __forceinline ~TempInfo()
    {
        reinterpret_cast<::BSSoundInfo *>((((SoundDtor*)this)))->BSSoundInfo::~BSSoundInfo();
    }
};

struct SoundInfoOps
{
};

struct Sub18Ada
{
};

struct EntryInfo : InfoHead
{
    Sub18Ada sub;
    __forceinline void SetDebug(DebugInfo src)
    {
        reinterpret_cast<::BSAudioDefinition *>(&(sub))->operator=((*(const ::BSAudioDefinition *)(&src)));
    }
    __forceinline void Assign(SoundInfoWrap* info)
    {
        d0 = info->head.m_uiSoundID;
        d4 = info->head.m_fSoundVolume;
        d8 = *(float*)&info->head._08;
        d12 = info->head.m_uiValueAt0C;
        d16 = info->head.m_uiPlaybackFlags;
        d20 = info->head.m_bValueAt14;
    }
};

struct Mgr74Ada
{
    bool FUN_00a1e380(int, EntryInfo**);
};

struct BSSoundInfoC
{
    InfoHead head;
    DebugPlain debug;
    BSSoundInfoC(SoundInfoWrap*);
};

struct AllocatorAda
{
};



struct MemContext
{
    int saved;
    __forceinline MemContext()
    {
        int tlsTemp = (*reinterpret_cast<int *>(&::currentAllocationContext));
        saved = tlsTemp;
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 11;
    }
    __forceinline ~MemContext()
    {
        int restore = saved;
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = restore;
    }
};

__forceinline void LockCS(CritSecA* p)
{
    int a, b;
    EnterCriticalSection(p);
}
__forceinline void UnlockCS(CritSecA* p)
{
    int a, b, c;
    LeaveCriticalSection(p);
}

struct Param2Ada
{
    virtual void s0();
    virtual bool v4();
    virtual void s2();
    virtual void s3();
    virtual float v10();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual float* v54(Vec3* arg);
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    unsigned short w18;
    unsigned short w1a;
    unsigned short w1c;
    unsigned short w1e;
    int unk20, unk24, unk28, unk2c, unk30;
    short unk34;
    char name[0x104];
    float f13c;
    float f140;
    int unk144, unk148, unk14c;
    float f150;
    __forceinline int Read14()
    {
        return f14;
    }
    __forceinline int Read08()
    {
        return f08;
    }
    __forceinline int Read04()
    {
        return f04;
    }
    __forceinline float Get150()
    {
        return f150;
    }
    __forceinline float Get140()
    {
        return f140;
    }
    __forceinline float Get13c()
    {
        return f13c;
    }
    __forceinline float Read150()
    {
        float t9a0 = f150;
        return (t9a0 > 3.4028234663852886e+37) ? ::DAT_01012054 : Get150();
    }
    __forceinline float Read140()
    {
        float t9a4 = f140;
        return (t9a4 > 3.4028234663852886e+37) ? ::DAT_01012054 : Get140();
    }
    __forceinline float Read13c()
    {
        float t9a8 = f13c;
        return (t9a8 > 3.4028234663852886e+37) ? ::DAT_01012054 : Get13c();
    }
    __forceinline unsigned short Read18()
    {
        return w18;
    }
    __forceinline unsigned short Read1c()
    {
        return w1c;
    }
    __forceinline unsigned short Read1e()
    {
        return w1e;
    }
};

__forceinline void DebugInfo::SetName(Param2Ada* sound)
{
    if (sound->name)
    {
        char* dst = pSelf;
        fnv::crt::strcpy_s(dst, 0x104, sound->name);
    }
    else
    {
        char* dst = pSelf;
        fnv::crt::strcpy_s(dst, 0x104, "NotTESSound");
    }
}
__forceinline bool ReadDebugSetting()
{
    char* pSel = &(*reinterpret_cast<::SettingQ *>(&::g_011f6e5c)) ? (char*)&(*reinterpret_cast<::SettingQ *>(&::g_011f6e5c)).m_iValue : (*(char*)& DAT_01202800 = 0, (char*)&DAT_01202800);
    return *(bool*)pSel;
}

struct ThisClsAda
{
    char pad000[0x74];
    Mgr74Ada mgr;
    char pad078[0x4c];
    CritSecA cs;
    void FUN_00ada5d0(int param1, Param2Ada* param2);
};

// @fnv 0x00ad9870
void AudioMgr70::FUN_00ad9870()
{
    if (!IsMultiThreaded70(GetAudio70()))
    {
        reinterpret_cast<::FUN_00ada1d0_shell *>(this)->InitUISounds(false);
        reinterpret_cast<::FUN_00ada1d0_shell *>(this)->InitUISounds(false);
        reinterpret_cast<::FUN_00ada1d0_shell *>(this)->InitUISounds(false);
    }

    BSSoundMsg70* pInfo = 0;
    while (!m_0c.IsEmpty())
    {
        pInfo = m_0c.FUN_00ae7f90();
        delete pInfo;
    }
    while (!m_18.IsEmpty())
    {
        pInfo = m_18.FUN_00ae7f90();
        delete pInfo;
    }
    pInfo = 0;
    if (m_13c)
    {
        delete m_13c;
        m_13c = 0;
    }

    BSSoundMsgV70* pMsg = 0;
    int iVal7 = 0;
    void* pFirst5 = m_54.First();
    while (pFirst5)
    {
        reinterpret_cast<::RecursiveLock *>(&(m_54))->Unlock((::BSCriticalSectionEntry **)(void **)(&pFirst5), (unsigned int *)(int *)(&iVal7), (void **)((void**)&pMsg));
        reinterpret_cast<::RMapBase *>(&(m_54))->FUN_00a1e240(pMsg->GetID());
        reinterpret_cast<::ThisClsAda *>(this)->FUN_00ada5d0(pMsg->GetID(), (::Param2Ada *)(0));
        BSSoundMsgV70* pDelete3 = pMsg;
        delete pDelete3;
    }

    reinterpret_cast<::AE91F0Map *>(&(m_84))->ClearAll();
    void* pFound4 = m_74.First();
    BSSoundInfo70* pOut9 = 0;
    BSSoundInfo70* pDel;
    iVal7 = 0;
    while (pFound4)
    {
        reinterpret_cast<::RecursiveLock *>(&(m_74))->Unlock((::BSCriticalSectionEntry **)(void **)(&pFound4), (unsigned int *)(int *)(&iVal7), (void **)((void**)&pDel));
        while (reinterpret_cast<::S_00adc830_Map *>(&(m_64))->GetAt(iVal7, (*(::S_00adc830_Entry * *)(&pOut9))))
        {
            while (reinterpret_cast<::RMapBase *>(&(m_64))->FUN_00a1e240(iVal7))
            {
            }
            delete pOut9;
        }
        delete pDel;
    }
    reinterpret_cast<::AE91F0Map *>(&(m_74))->ClearAll();

    char cSave3 = (*reinterpret_cast<::SetObj_70 *>(&::g_011f6ebc)).GetPtr();
    (*reinterpret_cast<::SetObj_70 *>(&::g_011f6ebc)).GetPtr() = 0;
    reinterpret_cast<::Owner *>(this)->AddSound((::Sound *)(0));
    (*reinterpret_cast<::SetObj_70 *>(&::g_011f6ebc)).GetPtr() = cSave3;

    delete[] m_178.v;
}

// @fnv 0x00ada5d0
void ThisClsAda::FUN_00ada5d0(int param1, Param2Ada* param2)
{
    MemContext context4_2;
    SoundInfoWrap info15;
    DebugInfo descB_;
    DebugInfo debug4;
    void* pSavedB = 0;
    bool flag11_2 = ReadDebugSetting();
    if (param2)
    {
        reinterpret_cast<::S *>((((SoundInfoOps*)&info15)))->AssignFrom(
                (const ::S *)(::TempInfo *)(&static_cast<const TempInfo&>(TempInfo(param2->v4(), param2->v10(), param2->Read04(), param2->Read08(), param2->Read14()))));
        if (flag11_2)
        {
            std::memset(&descB_, 0, 0x23c);
            if (descB_.pSelf != descB_.name)
                descB_.pSelf = descB_.name;
            descB_.SetName(param2);
            if (reinterpret_cast<::BSGameSound *>((param2))->HasSoundFlagTwo() || reinterpret_cast<::BSGameSound *>((param2))->CanStartPlayback())
            {
                descB_.f220 = param2->Read150();
                Vec3 kFirst = Vec3();
                descB_.f218 = param2->v54(&kFirst)[0];
                Vec3 kSecond = Vec3();
                descB_.f21c = param2->v54(&kSecond)[1];
                descB_.f210 = param2->Read140();
                descB_.f214 = param2->Read13c();
            }
            else
            {
                descB_.f220 = 0.0f;
                descB_.f218 = 0.0f;
                descB_.f21c = 0.0f;
                descB_.f210 = 0.0f;
                descB_.f214 = 0.0f;
            }
            descB_.i230 = param2->Read18();
            descB_.i234 = param2->Read1c();
            descB_.i238 = param2->Read1e();
        }
    }
    LockCS(&cs);
    EntryInfo* pInfo = 0;
    if (reinterpret_cast<::S_00adc830_Map *>(&(mgr))->GetAt(param1, (*(::S_00adc830_Entry * *)(&pInfo))))
    {
        if (flag11_2)
            pInfo->SetDebug(descB_);
        pInfo->Assign(&info15);
    }
    else
    {
        pSavedB = new BSSoundInfoC(&info15);
        if (flag11_2)
            ((EntryInfo*)pSavedB)->SetDebug(descB_);
        reinterpret_cast<::FUN_00a0c6c0_cls *>(&(mgr))->InsertOrUpdate(param1, (::AnimSequenceBase *)(pSavedB));
    }
    UnlockCS(&cs);
}

struct SoundOwnerA
{
    void FUN_00adc2e0(int a, bool b);
};

// @fnv 0x00adc2e0
void SoundOwnerA::FUN_00adc2e0(int a, bool b)
{
    reinterpret_cast<::fnv_00adb1a0::Host *>(this)->FUN_00adb1a0(0x40, a, b, 0, (*(::fnv_00adb1a0::NavMeshPtr *)&(const ::NiAVObjPtr &)(0)), (*(::fnv_00adb1a0::Point *)&(const ::DetectPoint3 &)(DAT_011f426c)));
}

inline void DeadN()
{
    int a[4];
}

struct SoundQ4
{
    virtual ~SoundQ4();
    int unk04;
    unsigned int uiFlags;
    int unk0C;
    unsigned int uiFlags2;
    char pad14[0x36 - 0x14];
    char cEnabled;
    char pad37[0x144 - 0x37];
    unsigned int uiID;
    int iAlt;
    unsigned int GetFlags() const
    {
        return uiFlags;
    }
    unsigned int GetID() const
    {
        return uiID;
    }
    int GetAlt() const
    {
        return iAlt;
    }
    void SetFlag1000(bool b)
    {
        uiFlags2 = b ? (uiFlags2 | 0x1000) : (uiFlags2 & ~0x1000);
    }
};

struct WrapQ4
{
    char pad[0x30];
    SoundQ4* SoundAssetTmp;
    SoundQ4* GetSoundByEditorID() const
    {
        return SoundAssetTmp;
    }
};

struct NodeQ4
{
    NodeQ4* pNext;
    int unk4;
    WrapQ4* pData;
};

inline void* operator new(std::size_t, PoolX& kMgr)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&(kMgr))->FUN_00aa3e40(0x38);
}

inline void operator delete(void* p, PoolX& kMgr)
{
    reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&kMgr)))->FUN_00aa4060(p);
}

typedef FUN_00ae6f50 TaskQ4;

struct TaskListQ4
{
    NodeQ4* pHead;
};

struct TaskMgrQ4
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17();
    virtual void AddTask(TaskQ4*);
};

struct AudioQ4
{
    void* vtbl;
    bool bReady;
    bool IsReady() const
    {
        return bReady;
    }
};

inline AudioQ4* GetAudioQ4()
{
    return (AudioQ4*)DAT_011f6d98;
}

struct OwnerQ4 : ObjRegistry
{
    char padf4[0x10c - 0xf4];
    CritSecA m_kCS2;
    TaskListQ4 m_kTasks;
    void FUN_00add960(SoundQ4* SoundAssetTmp);
};

// @fnv 0x00add570
void AudioManagerD570::FUN_00add570(const char* pcName, unsigned int uiFlags)
{
    unsigned int uiFlagsCopy = uiFlags;
    AudioFileResolverD570 pfnResolve = GetAudioSystemD570()->GetResolver();
    unsigned int uiExtra = 0;
    {
        char acPath[264];
        if (!GetAudioSystemD570()->IsReady() || !pfnResolve || !pfnResolve(pcName, acPath, &uiFlagsCopy, &uiExtra))
            return;
        reinterpret_cast<::OwnerQ3 *>(this)->FUN_00add6f0(acPath, uiFlags, uiExtra);
    }
}

// @fnv 0x00add6f0
void OwnerQ3::FUN_00add6f0(const char* pPath, int iFlags, std::intptr_t iArg)
{
    if (!pPath || !GetAudioQ3()->IsReady())
        return;
    int iFlags9 = iFlags;
    int iID_2 = m_iNextID++;
    SndHandleQ kHandle3(iID_2);
    char acPath3[0x104];
    fnv::crt::strcpy_s(acPath3, 0x104, pPath);
    GetAudioQ3()->Normalize(acPath3);
    unsigned int uiHash3 = ::BSGameSound::ComputeSoundNameHash(acPath3);
    if (FUN_00add480(uiHash3, true))
        return;
    SoundQ3* pSound7 = GetAudioQ3()->Create(pPath);
    pSound7->m_uiSoundID = iID_2;
    pSound7->iFlags = iFlags9;
    reinterpret_cast<::BSGameSound *>((pSound7))->LoadFromFilename(0);
    PfnA_Q pfnA = GetAudioQ3()->GetPfnA();
    int iExtraTmp = 0;
    if (pfnA)
        pfnA(&kHandle3, iArg, &iExtraTmp);
    PfnB_Q pfnB4 = GetAudioQ3()->GetPfnB();
    int a9 = 0;
    int b2 = 0;
    if (pfnB4 && pfnB4(iArg, &a9, &b2))
        pSound7->SetAB(a9, b2);
    pSound7->SetExtra(iExtraTmp);
    reinterpret_cast<::OwnerQ4 *>(this)->FUN_00add960((::SoundQ4 *)(pSound7));
}

// @fnv 0x00add960
void OwnerQ4::FUN_00add960(SoundQ4* SoundAssetTmp)
{
    if (GetAudioQ4()->IsReady() && SoundAssetTmp->cEnabled && !(SoundAssetTmp->GetFlags() & 0x10000) &&
        !FUN_00add480(SoundAssetTmp->GetID(), false))
    {
        TaskQ4* pTask;
        EnterCriticalSection(&m_kCS2);
        bool bFound;
        NodeQ4* e = m_kTasks.pHead;
        bFound = false;
        while (e)
        {
            WrapQ4* pWrap = e->pData;
            if (pWrap->GetSoundByEditorID()->GetID() == SoundAssetTmp->GetID() && pWrap->GetSoundByEditorID()->GetAlt() == SoundAssetTmp->GetAlt())
            {
                bFound = true;
                break;
            }
            e = e ? e->pNext : 0;
        }
        if (bFound)
        {
            LeaveCriticalSection(&m_kCS2);
            delete SoundAssetTmp;
            return;
        }
        SoundAssetTmp->uiFlags = SoundAssetTmp->GetFlags() | 0x8000;
        DeadN();
        pTask = new ((*reinterpret_cast<::PoolX *>(&::g_memoryManager))) TaskQ4(SoundAssetTmp);
        SoundAssetTmp->SetFlag1000(true);
        (*reinterpret_cast<::TaskMgrQ4 * *>(&::DAT_01202d98))->AddTask(pTask);
        reinterpret_cast<::FUN_00ae8bf0_t *>(&(m_kTasks))->AddItem((const void *)&(pTask));
        LeaveCriticalSection(&m_kCS2);
    }
    else
    {
        delete SoundAssetTmp;
    }
}

inline void DeadM()
{
    int a[7];
}

struct SoundQ
{
    virtual ~SoundQ();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void Copy(SoundQ*, int);
    unsigned int pad04;
    unsigned int flags;
    char pad0c[0x144 - 0xc];
    unsigned int id;
    int p148;
};

struct NodeQ
{
    NodeQ* next;
    int p4;
    SoundQ* sound;
};

struct SndFactQ
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual SoundQ* Create(int);
};

struct SoundListQ
{
    NodeQ* head;
    int p4;
    unsigned int count;
    NodeQ* GetHead() const
    {
        return head;
    }
};

struct OwnerQ2
{
    char pad[0x94];
    SoundListQ list;
    unsigned int total;
    char more[0x38];
    CritSecA cs;
    SoundQ* FUN_00add1e0(unsigned int id, int alt, unsigned int flags);
};

inline SndFactQ* GetFQ()
{
    return (SndFactQ*)DAT_011f6d98;
}

inline SoundQ* NewSoundQ()
{
    return GetFQ()->Create(0);
}

inline unsigned int GetFlagsQ(SoundQ* s)
{
    return s->flags;
}

inline bool IsIDQ(SoundQ* s, unsigned int id)
{
    return id == s->id;
}

inline bool IsAltQ(SoundQ* s, int alt)
{
    return alt == s->p148 && s->p148 != 0;
}

// @fnv 0x00add1e0
SoundQ* OwnerQ2::FUN_00add1e0(unsigned int id, int alt, unsigned int flags)
{
    bool bRandom5 = false;
    if (alt && !id)
        bRandom5 = true;
    EnterCriticalSection(&cs);
    NodeQ* pNodeB = list.GetHead();
    DeadN();
    NodeQ* pPrev_ = 0;
    NodeQ* pSavedPrev = 0;
    SoundQ* pResult = 0;
    SoundQ* pMatch = 0;
    SoundQ* pSaved = 0;
    while (pNodeB)
    {
        SoundQ* SoundAssetTmp = pNodeB->sound;
        if (IsIDQ(SoundAssetTmp, id))
        {
            pResult = NewSoundQ();
            pResult->flags = flags;
            pResult->Copy(SoundAssetTmp, 1);
            pResult->flags = flags;
            reinterpret_cast<::FUN_00ae8090_Class *>(&(list))->FUN_00ae8090((::FUN_00ae8090_Node **)&(pNodeB));
            if (!(GetFlagsQ(SoundAssetTmp) & 0x20000000))
                reinterpret_cast<::S_00a0c9f0 *>(&(list))->FUN_00a0c9f0((int *)&(SoundAssetTmp));
            else
                delete SoundAssetTmp;
            LeaveCriticalSection(&cs);
            DeadM();
            return pResult;
        }
        else if (IsAltQ(SoundAssetTmp, alt))
        {
            if (pMatch && bRandom5 && std::rand() % 3 == 0)
            {
                pSaved = pMatch;
                pSavedPrev = pPrev_;
            }
            pMatch = SoundAssetTmp;
            pPrev_ = pNodeB;
        }
        pNodeB = pNodeB ? pNodeB->next : 0;
    }
    if (bRandom5 && pSaved && pMatch && std::rand() % 2 == 0)
    {
        pMatch = pSaved;
        pPrev_ = pSavedPrev;
    }
    if (pMatch)
    {
        reinterpret_cast<::FUN_00ae8090_Class *>(&(list))->FUN_00ae8090((::FUN_00ae8090_Node **)&(pPrev_));
        reinterpret_cast<::S_00a0c9f0 *>(&(list))->FUN_00a0c9f0((int *)&(pMatch));
        pResult = NewSoundQ();
        pResult->flags = flags;
        pResult->Copy(pMatch, 1);
        pResult->flags = flags;
    }
    LeaveCriticalSection(&cs);
    return pResult;
}

extern char str_010a36c0[];

extern char str_010a36b4[];

extern char str_010a36a8[];

extern char str_010a3694[];

extern char str_010a3684[];

extern char str_010a3670[];

extern char str_010a3660[];

extern char str_010a3650[];

extern char str_010a3638[];

extern char str_010a3624[];

extern char str_010a3608[];

extern char str_010a35f8[];

extern char str_010a35c0[];

extern char str_010a35a0[];

extern char str_010a3560[];

extern char str_010a353c[];

extern char str_010a3524[];

extern char str_010a352c[];

extern char str_010a3534[];

extern char str_01063958[];


struct SoundNode;

struct DebugList
{
    SoundNode* item;
    DebugList* next;
    DebugList()
    {
        item = 0;
        next = 0;
    }
    DebugList(SoundNode* const& value)
    {
        item = value;
        next = 0;
    }
    void FUN_00af25b0(SoundNode* const& value)
    {
        if (!value)
            return;
        DebugList* tail = this;
        while (tail->next)
            tail = tail->next;
        if (tail->item)
            tail->next = new DebugList(value);
        else
            tail->item = value;
    }
    ~DebugList()
    {
        RemoveAll();
    }
    int Count()
    {
        int result = 0;
        DebugList* entry = this;
        while (entry)
        {
            if (entry->item)
                ++result;
            entry = entry->next;
        }
        return result;
    }
    void RemoveAll()
    {
        while (next)
        {
            DebugList* following = next->next;
            next->next = 0;
            delete next;
            next = following;
        }
        item = 0;
    }
    void SetItem(SoundNode* value)
    {
        if (!value)
            return;
        item = value;
    }
    void SortNodes(int(__cdecl* compare)(SoundNode*, SoundNode*))
    {
        DebugList* cursor = this;
        DebugList* prior = 0;
        if (cursor)
        {
            int left = Count();
            bool changed = true;
            while (left && changed)
            {
                changed = false;
                while (cursor)
                {
                    if (prior)
                    {
                        SoundNode* value = cursor->item;
                        SoundNode* previous = prior->item;
                        if (compare(previous, value) > 0)
                        {
                            cursor->SetItem(previous);
                            prior->SetItem(value);
                            changed = true;
                        }
                    }
                    prior = cursor;
                    cursor = cursor->next;
                }
                --left;
            }
        }
    }
    void SortItemsRecursive(SoundNode** items, int(__cdecl* compare)(SoundNode*, SoundNode*), int count)
    {
        int step = 0;
        int first = 0;
        int last = count - 1;
        for (step = 1; step <= (last - first) / 9; step = step * 3 + 1)
        {
        }
        for (; step > 0; step /= 3)
        {
            for (int index = first + step; index <= last; ++index)
            {
                int at = index;
                SoundNode* value = items[index];
                while (at >= first + step && compare(value, items[at - step]) < 0)
                {
                    items[at] = items[at - step];
                    at -= step;
                }
                items[at] = value;
            }
        }
    }
    void FUN_00ae81e0(int(__cdecl* compare)(SoundNode*, SoundNode*))
    {
        SoundNode** items;
        DebugList* node;
        int index;
        DebugList* previous;
        int output;
        int count;
        count = Count();
        items = (SoundNode**)_alloca(count * 4 + 4);
        if (!items)
        {
            SortNodes(compare);
            return;
        }
        node = this;
        for (index = 0; index < count; ++index, node = node->next)
            items[index] = node->item;
        SortItemsRecursive(items, compare, count);
        RemoveAll();
        node = this;
        previous = 0;
        for (output = 0; output < count; ++output)
        {
            if (output > 0)
                node = new DebugList(items[output]);
            else
            {
                node->item = items[output];
                node->next = 0;
            }
            if (previous)
                previous->next = node;
            previous = node;
        }
    }
};

struct SoundNode
{
    SoundNode()
    {
        index = 0;
        description = 0;
    }
    SoundNode(unsigned int n, char* text)
    {
        index = n;
        description = text;
    }
    unsigned int index;
    char* description;
};

int __cdecl FUN_00ae5fb0(unsigned int*, unsigned int*);

struct SoundDebugDescription
{
    char* message;
    char messageBuffer[260];
    char* fullName;
    char fullNameBuffer[260];
    float volume;
    float frequency;
    unsigned int unknown218;
    unsigned int unknown21c;
    float attenuation;
    unsigned int unknown224;
    unsigned int unknown228;
    unsigned int unknown22c;
    unsigned int currentTime;
    unsigned int maxTime;
    unsigned int duration;
    SoundDebugDescription()
    {
        messageBuffer[0] = 0;
        fullNameBuffer[0] = 0;
        message = messageBuffer;
        fullName = fullNameBuffer;
        volume = 0.0f;
        frequency = 0.0f;
        unknown218 = *(unsigned int*)&NiPoint3_ZERO.x;
        unknown21c = *(unsigned int*)&NiPoint3_ZERO.y;
        attenuation = NiPoint3_ZERO.z;
        unknown224 = 0;
        unknown228 = 0;
        unknown22c = 0;
        currentTime = 0;
        maxTime = 0;
        duration = 0;
    }
    ~SoundDebugDescription()
    {
        message = 0;
        fullName = 0;
        volume = 0.0f;
        frequency = 0.0f;
        unknown224 = 0;
        unknown228 = 0;
        unknown22c = 0;
        currentTime = 0;
        maxTime = 0;
        duration = 0;
    }
    SoundDebugDescription& FUN_00ae88c0(const SoundDebugDescription& other)
    {
        messageBuffer[0] = 0;
        fullNameBuffer[0] = 0;
        if (other.message)
        {
            const char* source = other.message;
            char* dest = message;
            strcpy(dest, source);
        }
        if (other.fullName)
        {
            const char* source = other.fullName;
            char* dest = fullName;
            strcpy(dest, source);
        }
        volume = other.volume;
        frequency = other.frequency;
        unknown218 = other.unknown218;
        unknown21c = other.unknown21c;
        attenuation = other.attenuation;
        unknown224 = other.unknown224;
        unknown228 = other.unknown228;
        unknown22c = other.unknown22c;
        currentTime = other.currentTime;
        maxTime = other.maxTime;
        duration = other.duration;
        return *this;
    }
    char* GetName()
    {
        return fullName;
    }
};

struct SoundRecord
{
    unsigned int id;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int flags;
    unsigned int unknown10;
    bool isPlaying;
    unsigned int GetID()
    {
        unsigned int value = id;
        return value;
    }
    unsigned int GetFlags()
    {
        return flags;
    }
    bool IsPlaying()
    {
        return isPlaying;
    }
};

struct SoundMapItem
{
    SoundMapItem* next;
    unsigned int key;
    SoundRecord* value;
};

struct SoundEntries
{
    virtual void Destroy();
    virtual unsigned int Hash(unsigned int);
    unsigned int count;
    SoundMapItem** data;
    SoundMapItem* GetFirst()
    {
        for (unsigned int i = 0; i < count; ++i)
        {
            if (data[i] != 0)
                return data[i];
        }
        return 0;
    }
    void FUN_00a0c850(SoundMapItem** position, unsigned int* key, SoundRecord** value)
    {
        SoundMapItem* entry = *position;
        *key = entry->key;
        *value = entry->value;
        if (entry->next)
        {
            *position = entry->next;
            return;
        }
        unsigned int index = Hash(entry->key);
        for (++index; index < count; ++index)
        {
            entry = data[index];
            if (entry)
            {
                *position = entry;
                return;
            }
        }
        *position = 0;
    }
};

struct AudioSystem
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    SoundEntries sounds;
    unsigned int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    unsigned int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    unsigned int unkb0, unkb4, unkb8, unkbc, unkc0;
    CritSecA criticalSection;
    DebugList* FUN_00ae5ff0(unsigned int);
};

// @fnv 0x00ae5ff0
DebugList* AudioSystem::FUN_00ae5ff0(unsigned int filter)
{
    DebugList* head8 = new DebugList;
    unsigned int filterFlags_2 = ~0u;
    reinterpret_cast<::fnv_00ada330::OwnerQ *>((reinterpret_cast<FUN_00ada330_shell*>(this)))->FUN_00ada330();
    bool includeSpecial = false;
    char* buffer_ = 0;
    char _copy[260];
    char* last2;
    SoundRecord* currentSound6;
    char formatted[260];
    if (filter < 99)
    {
        buffer_ = new char[260];
        sprintf(buffer_, str_010a36c0, filter + 1);
        if (filter == 1)
        {
            strcat(buffer_, str_010a36b4);
            filterFlags_2 = 2;
        }
        else if (filter == 2)
        {
            strcat(buffer_, str_010a36a8);
            filterFlags_2 = 1;
        }
        else if (filter == 3)
        {
            strcat(buffer_, str_010a3694);
            filterFlags_2 = 0x08000000;
        }
        else if (filter == 4)
        {
            strcat(buffer_, str_010a3684);
            filterFlags_2 = 4;
        }
        else if (filter == 5)
        {
            strcat(buffer_, str_010a3670);
            filterFlags_2 = 8;
        }
        else if (filter == 6)
        {
            strcat(buffer_, str_010a3660);
            filterFlags_2 = 0x20;
        }
        else if (filter == 7)
        {
            strcat(buffer_, str_010a3650);
            filterFlags_2 = 0x1000;
        }
        else if (filter == 8)
        {
            strcat(buffer_, str_010a3638);
            filterFlags_2 = 0x40000000;
        }
        else if (filter == 9)
        {
            strcat(buffer_, str_010a3624);
            filterFlags_2 = 0x10000000;
        }
        else if (filter == 10)
        {
            strcat(buffer_, str_010a3608);
            includeSpecial = true;
        }
        reinterpret_cast<::TemplateList_00a0ae70 *>((head8))->AddTail((::TileTemplate_00a0ae70 **)&(const ::SoundNode *const &)(new SoundNode(0, buffer_)));
        buffer_ = new char[260];
        sprintf(buffer_, str_010a35f8);
        reinterpret_cast<::TemplateList_00a0ae70 *>((head8))->AddTail((::TileTemplate_00a0ae70 **)&(const ::SoundNode *const &)(new SoundNode(1, buffer_)));
    }
    else if (filter == 99)
    {
        filterFlags_2 = 0x800;
    }
    EnterCriticalSection(&criticalSection);
    SoundMapItem* current = sounds.GetFirst();
    SoundDebugDescription description;
    int entries4 = 1;
    unsigned int nextIndex4;
    unsigned int soundID2 = 0;
    int totalTime3 = 0;
    for (; current != 0 && entries4 < 20;)
    {
        reinterpret_cast<::RecursiveLock *>(&(sounds))->Unlock((::BSCriticalSectionEntry **)(::SoundMapItem **)(&current), &nextIndex4, (void **)(::SoundRecord **)(&currentSound6));
        buffer_ = new char[260];
        totalTime3 = 0;
        if (currentSound6 != 0)
        {
            reinterpret_cast<::BSAudioDefinition *>(&(description))->operator=((const ::BSAudioDefinition &)((const ::SoundDebugDescription &)((*(::SoundDebugDescription *)(reinterpret_cast<::FUN_00ae8b40_cls *>((currentSound6))->GetPayload({}))))));
            totalTime3 = (unsigned int)totalTime3 > description.currentTime ? totalTime3 : description.currentTime;
            totalTime3 = (unsigned int)totalTime3 > description.maxTime ? totalTime3 : description.maxTime;
            totalTime3 = (unsigned int)totalTime3 > description.duration ? totalTime3 : description.duration;
        }
        if (((includeSpecial && currentSound6 && (!currentSound6->IsPlaying() || totalTime3 > 3000)) ||
             (!includeSpecial && currentSound6 && currentSound6->IsPlaying() && totalTime3 <= 3000)) &&
            (filterFlags_2 & currentSound6->GetFlags()))
        {
            reinterpret_cast<::BSAudioDefinition *>(&(description))->operator=((const ::BSAudioDefinition &)((const ::SoundDebugDescription &)((*(::SoundDebugDescription *)(reinterpret_cast<::FUN_00ae8b40_cls *>((currentSound6))->GetPayload({}))))));
            soundID2 = currentSound6->GetID();
            if (nextIndex4 != soundID2)
                soundID2 = soundID2;
            if (description.fullName != 0)
            {
                if (description.fullName != description.fullNameBuffer)
                {
                    description.fullName = description.fullNameBuffer;
                }
                fnv::crt::strcpy_s(_copy, 260, description.GetName());
                last2 = strstr(_copy, ::DAT_01013444);
                while (last2 && strstr(last2 + 1, ::DAT_01013444))
                {
                    last2++;
                    last2 = strstr(last2, ::DAT_01013444);
                }
                if (last2 && last2[1] != 0)
                {
                    fnv::crt::strcpy_s(description.GetName(), 260, last2);
                }
                else
                {
                    delete[] buffer_;
                    continue;
                }
                if (currentSound6->GetFlags() & 2)
                {
                    sprintf(formatted, str_010a35c0, soundID2, description.fullName,
                            (currentSound6->IsPlaying() ? str_01063958 : ::str_010639ec), (double)description.attenuation,
                            (double)description.volume, (double)description.frequency, description.currentTime,
                            description.maxTime, description.duration);
                }
                else if ((currentSound6->GetFlags() & 1) && !(currentSound6->GetFlags() & 0x8000000))
                {
                    sprintf(formatted, str_010a35a0, soundID2, description.fullName,
                            (currentSound6->IsPlaying() ? str_01063958 : ::str_010639ec), description.currentTime,
                            description.maxTime);
                }
                else if ((currentSound6->GetFlags() & 1) && (currentSound6->GetFlags() & 0x8000000))
                {
                    sprintf(formatted, str_010a3560, soundID2, description.fullName,
                            (currentSound6->IsPlaying() ? str_01063958 : ::str_010639ec), (double)description.attenuation,
                            (double)description.volume, (double)description.frequency, description.currentTime,
                            description.maxTime, description.duration);
                }
                else
                {
                    sprintf(formatted, str_010a353c, soundID2, description.fullName,
                            (currentSound6->IsPlaying() ? str_01063958 : ::str_010639ec), description.currentTime,
                            description.maxTime);
                }
                fnv::crt::strcpy_s(buffer_, 260, formatted);
            }
            else
            {
                sprintf(formatted, str_010a3524, soundID2, currentSound6->IsPlaying() ? str_010a3534 : str_010a352c);
                strcat(buffer_, formatted);
            }
            reinterpret_cast<::TemplateList_00a0ae70 *>((head8))->AddTail((::TileTemplate_00a0ae70 **)&(const ::SoundNode *const &)(new SoundNode(soundID2 + 2, buffer_)));
            ++entries4;
        }
    }
    LeaveCriticalSection(&criticalSection);
    head8->FUN_00ae81e0((int(__cdecl*)(SoundNode*, SoundNode*))FUN_00ae5fb0);
    return head8;
}

#include "generated/data/bsaudio/bsaudiomanager.inc"
#include "generated/data/bsaudio/bsaudiomanager_ob1_variant.inc"
