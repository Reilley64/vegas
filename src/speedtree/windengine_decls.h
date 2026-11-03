// speedtree/windengine_decls.h: declares Matrix4f
#ifndef FNV_WINDENGINE_DECLS_H
#define FNV_WINDENGINE_DECLS_H
#include <cstddef>


#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
#include "MemoryManager.h"


class Matrix4f
{
  public:
    float m_fComponents[4][4];

    Matrix4f();
    void InitializeIdentity();

    static __forceinline void* operator new[](std::size_t size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
    }

    static __forceinline void operator delete[](void* pointer)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pointer);
    }
};


#endif
