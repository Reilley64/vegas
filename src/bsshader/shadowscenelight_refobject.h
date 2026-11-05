// bsshader/shadowscenelight_refobject.h: declares NiRefObject
#ifndef SHADOWSCENELIGHT_REFOBJECT_H
#define SHADOWSCENELIGHT_REFOBJECT_H

#include "NiRefObject.h"
template <class T> class ShadowScenePointer
{
  public:
    T* m_pObject;
    ShadowScenePointer() : m_pObject(0)
    {}
    ~ShadowScenePointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    ShadowScenePointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (p)
                p->IncRefCount();
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
        }
        return *this;
    }
};
template <class T> class ShadowSceneArray
{
  public:
    virtual ~ShadowSceneArray();
    T* pBuffer;
    unsigned int iSize, SimpleArrayStorage;
    ShadowSceneArray() : pBuffer(0), iSize(0), SimpleArrayStorage(0)
    {}
};
#endif
