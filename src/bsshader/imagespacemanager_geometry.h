// bsshader/imagespacemanager_geometry.h: declares NiUpdateData, NiGlobalStringTable, NiScreenElementsData, NiAVObject, NiScreenElements and more
#ifndef IMAGESPACEMANAGER_GEOMETRY_H
#define IMAGESPACEMANAGER_GEOMETRY_H
#include <cstddef>

#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a87900_class.h"
#include "fnv/decl/NiScreenElementsDataShell.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0104a000.h"
#include "fnv/symbols_0109b000.h"
#include "NiObject.h"
#include "NiFixedString.h"
class NiUpdateData
{
  public:
    float time;
    bool a, b, c, d, e;
};
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
class NiScreenElementsData : public NiObject
{
  public:
    char padding[0x70 - 8];
    static void* operator new(std::size_t) throw();
    static void operator delete(void*);
    NiScreenElementsData(bool, bool, unsigned short, int, int, int, int, int, int);
public:
    bool SetRectangle(int, float, float, float, float);
public:
    bool SetRectangleBounds(int, unsigned short, float, float, float, float);
};
class NiAVObject : public NiObject
{
  public:
};
class NiScreenElements : public NiAVObject
{
  public:
    char padding[0xb8 - 8];
    NiScreenElementsData* data;
    char tail[8];
    static void* operator new(std::size_t) throw();
    static void operator delete(void*);
    NiScreenElements(NiScreenElementsData*);
    NiScreenElementsData* GetData()
    {
        return data;
    }
};
template <class T> class GeometryPointer
{
  public:
    T* m_pObject;
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
    GeometryPointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
class GeometryString : public NiFixedString
{
  public:
    GeometryString(const char* s)
    {
        m_kHandle = NiGlobalStringTable::AddString(s);
    }
    ~GeometryString()
    {
        if (m_kHandle != (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220)).m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(m_kHandle - 8));
    }
};
#endif

