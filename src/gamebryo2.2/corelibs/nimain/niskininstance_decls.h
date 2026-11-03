// gamebryo2.2/corelibs/nimain/niskininstance_decls.h: declares NiObject, NiStream, NiSkinInstance
#pragma once

#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/symbols_00aa1000.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiStream;
class NiObject
{
  public:
    virtual ~NiObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
};
class NiStream
{
  public:
    char padding[0xd8];
    unsigned int m_uiNifVersion;
    NiObject* GetLoadedObject();
};
template <class T> class NiPointer
{
  public:
    T* p;
    __forceinline void operator=(T* value)
    {
        if (p != value)
        {
            T* old = p;
            if (old && InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
                old->DeleteThis();
            p = value;
            if (value)
                InterlockedIncrement((volatile long*)&value->m_uiRefCount);
        }
    }
};
class NiSkinInstance : public NiObject
{
  public:
    NiPointer<NiObject> m_pSkinData;
    NiPointer<NiObject> m_pkSkinMeshPartition;
    NiObject* m_pRootParent;
    NiObject** m_ppBones;
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
};
