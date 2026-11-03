// gamebryo2.2/corelibs/nimain/nismartpointer_decls.h: declares WaitableObject, KFModel, LoadedFile, NavMeshPtr, PathingLocation and more
#ifndef FNV_NISMARTPOINTER_DECLS_H
#define FNV_NISMARTPOINTER_DECLS_H


#include <windows.h>
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_0042fdc0_class.h"
#include "fnv/decl/NiPtr.h"
#include "fnv/decl/fnv_0044b010__FUN_0044b010_shell.h"
#include "fnv/decl/fnv_0044b050__FUN_0044b050_shell.h"
#include "fnv/decl/fnv_0044b0f0__FUN_0044b0f0_shell.h"
#include "fnv/decl/fnv_0044b180__FUN_0044b180_shell.h"

#define FNV_REFCOUNTED_TYPE(T)                                                                                         \
    class T                                                                                                            \
    {                                                                                                                  \
      public:                                                                                                          \
        virtual ~T();                                                                                                  \
        virtual void DeleteThis();                                                                                     \
        unsigned long m_uiRefCount;                                                                                    \
    }
FNV_REFCOUNTED_TYPE(NiD3DPixelShader);
FNV_REFCOUNTED_TYPE(NiGPUProgram);
#undef FNV_REFCOUNTED_TYPE

class WaitableObject
{
  public:
    void FUN_00401970();
};

class KFModel
{
  public:
};

class LoadedFile
{
  public:
};

template <class T> struct NiPointerRefOps
{
    static void Dec(T* object)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
            object->DeleteThis();
    }
    static void Inc(T* object)
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
    }
};

class PathingAvoidNodeArray;
template <class T, unsigned int N> class BSSimpleArray;
class NavMeshPtr
{
  public:
    void* object;
    NavMeshPtr& operator=(const NavMeshPtr&);
};

class PathingLocation
{
  public:
    PathingLocation& operator=(const PathingLocation&);
};

class PathingAvoidPointerView
{
  public:
};

class PathingRequest
{
  public:
    char prefix[0x34];
    PathingLocation destination;
    char padding[0x94 - 0x35];
    PathingAvoidPointerView avoid;
    void SetDestination(PathingLocation*);
    void SetAvoidNodeArray(BSSimpleArray<void*, 1024>*);
};

class KFModelLookupTable
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual bool Lookup(const char* key, KFModel*& result);
};

class KFModelLookup
{
  public:
    void* unknown;
    KFModelLookupTable* table;
    KFModel* Lookup(const char* key);
};

class NiGPUProgramOwner
{
  public:
    char prefix[0x30];
    NiGPUProgram* program;
    void SetProgram(NiGPUProgram*);
};

class GlobalObject_006ece90;
extern GlobalObject_006ece90 g_011d77f0;
class QueuedMessage;
template <class T> class BSTFreeList;
template <class T> class BSTCommonLLMessageQueue
{
  public:
    virtual void vfn_00();
    char storage[0x10];
    BSTCommonLLMessageQueue(GlobalObject_006ece90*);
    ~BSTCommonLLMessageQueue();
};

class PathingSolutionBase
{
  public:
    virtual void vfn_00();
    long refcount;
    PathingSolutionBase();
};

class ActorPathingMessageQueue : public BSTCommonLLMessageQueue<QueuedMessage>, public PathingSolutionBase
{
  public:
    ActorPathingMessageQueue();
    virtual void vfn_00();
};

#endif
