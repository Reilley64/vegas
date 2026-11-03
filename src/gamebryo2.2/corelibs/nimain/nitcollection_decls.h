// gamebryo2.2/corelibs/nimain/nitcollection_decls.h: declares MemoryManager
#ifndef FNV_NITCOLLECTION_DECLS_H
#define FNV_NITCOLLECTION_DECLS_H
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
class MemoryManager
{
  public:
};
class NiGeometry;
class NiTexture;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer();
    ~NiPointer()
    {}
    static void* operator new[](size_t size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
    }
};
template <class T> class NiTNewInterface
{
  public:
    static T* Allocate(unsigned int count);
};
#endif
