// gamebryo2.2/corelibs/nianimation/nigeommorphercontroller_decls.h: declares NiGeomMorpherController, InterpItem, MorphData
#ifndef FNV_NIGEOMMORPHERCONTROLLER_DECLS_H
#define FNV_NIGEOMMORPHERCONTROLLER_DECLS_H

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
#include "NiRefObject.h"
#include "MemoryManager.h"
class NiGeomMorpherController
{
  public:
    struct InterpItem
    {
        NiRefObject* m_spControllerInterpolator;
        float m_fWeight;
        __declspec(nothrow) InterpItem();
        __declspec(nothrow) __forceinline ~InterpItem()
        {
            if (m_spControllerInterpolator)
                m_spControllerInterpolator->DecRefCount();
        }
        static void* operator new[](size_t size) throw()
        {
            return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
        }
        static void operator delete[](void* p) throw()
        {
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(p);
        }
    };
    unsigned char padding[0x38];
    struct MorphData
    {
        unsigned char padding[8];
        unsigned int m_uiNumTargets;
    };
    MorphData* m_spMorphTargetData;
    InterpItem* m_pInterpolatorItems;
    void ClearInterpolatorArray();
};
#endif
