#pragma once

#include <cstddef>
#include <windows.h>
#include "fnv/symbols_00aa1000.h"

// Family-scoped view of the inherited Gamebryo scalar allocation owner.
namespace water {
struct NiMemObject
{
    static void* operator new(std::size_t size)
    {
        return ::FUN_00aa13e0(size);
    }

    static void operator delete(void* memory, std::size_t size)
    {
        ::FUN_00aa1460(memory, static_cast<unsigned int>(size));
    }
};
}

struct CmObject
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount();
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct CmPointer
{
    T* m_pObject;
    CmPointer() : m_pObject(0)
    {}
    ~CmPointer();
    CmPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (pObject)
                pObject->IncRefCount();
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }
};

struct CmPoint3
{
    float x, y, z;
    CmPoint3() : x(0.0f), y(0.0f), z(0.0f)
    {}
};

struct CmList
{
    void* m_pHead;
    void* m_pTail;
    unsigned int m_uiCount;
    CmList()
    {
        m_uiCount = 0;
        m_pHead = 0;
        m_pTail = 0;
    }
    ~CmList();
};

struct CmBase : water::NiMemObject
{
    CmBase();
    virtual ~CmBase();
    char pad04[0x1c - 4];
    int m_i1c;
    char pad20[0x58 - 0x20];
    int m_i58;
    char pad5c[0x60 - 0x5c];
};

struct FUN_00b6abb0 : CmBase
{
    bool m_b60, m_b61, m_b62, m_b63;
    int m_i64;
    int m_i68;
    float m_f6c;
    float m_f70;
    float m_f74;
    float m_f78;
    bool m_b7c, m_b7d, m_b7e, m_b7f, m_b80, m_b81, m_b82, m_b83;
    int m_i84;
    CmPoint3 m_kPt0;
    CmPoint3 m_kPt1;
    CmPoint3 m_kPt2;
    CmPoint3 m_kPt3;
    CmPoint3 m_kPt4;
    CmPoint3 m_kPt5;
    CmPoint3 m_kPt6;
    CmPoint3 m_kPt7;
    CmPoint3 m_kPt8;
    CmPoint3 m_kPt9;
    CmPoint3 m_kPt10;
    CmPoint3 m_kPt11;
    float m_f118;
    float m_f11c;
    float m_f120;
    float m_f124;
    CmList m_kList;
    CmPointer<CmObject> m_sp134;
    CmPointer<CmObject> m_sp138;
    CmPointer<CmObject> m_sp13c;
    CmPointer<CmObject> m_sp140;
    CmPointer<CmObject> m_sp144;
    CmPointer<CmObject> m_sp148;
    int m_i14c;

    FUN_00b6abb0();
    virtual ~FUN_00b6abb0();
};

static_assert(sizeof(FUN_00b6abb0) <= 0xffffffffu);
