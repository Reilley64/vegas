
// src/bsshader/bsshaderutil_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00b6bee0: the skeleton of src/bsshader/bsshaderutil.cpp
// with declarations corrected to what the original code does (bsshaderutil_decls.h: virtual void vfn_48() = 0; -> virtual void vfn_48(void* a, void* b, int c) =; bsshaderutil_decls.h: virtual void Unk_2A() = 0; virtual void Un -> virtual void Unk_2A() = 0; virtual void Un). Move the function to its real unit once
// that unit declares it this way.

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/CameraState4E9.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004dc540_shell.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00b54000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_01272000.h"
#include "bsshaderutil_decls_decl_bsshaderutil.h"
#pragma optimize("", off)
#pragma optimize("", on)
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct AccumulatorContext
{
    int unk00, unk04;
    NiRefObject* object;
};
struct NiNodeHolder
{
    NiRefObject* value;
    NiNodeHolder(NiRefObject* p) : value(p)
    {
        if (value)
            value->IncRefCount();
    }
    ~NiNodeHolder();
};
// @fnv 0x00b6bee0
void FUN_00b6bee0(void* first, void* second, BSShaderAccumulator* accumulator)
{
    if ((*reinterpret_cast<::AccumulatorContext * *>(&::NiRenderer::ms_pRenderer)) && first && second)
    {
        if (!DAT_012722bc)
        {
            NiNodeHolder guard((*reinterpret_cast<::AccumulatorContext * *>(&::NiRenderer::ms_pRenderer))->object);
            reinterpret_cast<::FUN_004dc540_shell *>(((*reinterpret_cast<::AccumulatorContext * *>(&::NiRenderer::ms_pRenderer))))->FUN_004dc540((::NiAVObject *)(::NiRefObject *)(accumulator->texture));
        }
        ::FUN_00b54ac0((::NiTexture *)(::NiRefObject *)(accumulator->texture));
        accumulator->vfn_48(first, second, 0);
    }
}
