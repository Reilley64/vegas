// fallout_shared/teswater_decls.h: declares NiRefObject, NiObject, BSMultiBoundShape, BSMultiBound
#ifndef FNV_TESWATER_DECLS_H
#define FNV_TESWATER_DECLS_H

#include <windows.h>
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
};
class NiObject : public NiRefObject
{
  public:
    NiObject();
};
class BSMultiBoundShape : public NiObject
{
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const;
    __forceinline NiPointer(T* object = 0) : m_pObject(object)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
class BSMultiBound : public NiObject
{
  public:
    BSMultiBound();
    virtual ~BSMultiBound();
    unsigned int m_uiBoundFlags;
    NiPointer<BSMultiBoundShape> pShape;
};
#endif
