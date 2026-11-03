
// src/fallout_shared/tempeffects/bstempeffectgeometrydecal_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tempeffects/bstempeffectgeometrydecal.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/tempeffects/bstempeffectgeometrydecal.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tempeffects/bstempeffectgeometrydecal.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/NiRenderer.h"
#include "fnv/symbols_00683000.h"
#include "fnv/symbols_00685000.h"
#include "fnv/symbols_00688000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109e000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011d6000.h"
struct NiRTTI
{
};
struct BSTempEffectGeometryDecal
{
    const NiRTTI* FUN_006838a0() const;
};
extern unsigned char* DAT_011f5b04;
struct NiFixedString;
struct GlobalObjectO2_00a7b610
{
    int dummy;
};
GlobalObjectO2_00a7b610 g_011f5b2c;
struct FUN_00688590_shell
{
    GlobalObjectO2_00a7b610* GetRTTI() const;
};
struct BSDismemberSkinInstance
{
    void* FUN_006885e0(unsigned int);
    void FUN_00688610();
};
struct FUN_00685e60_shell
{
    void FUN_00685e60(unsigned int, unsigned int);
};
struct NiSkinInstance
{
    void FUN_00a85580();
    void* FUN_006885a0(unsigned int flags);
};

extern "C" void __cdecl _Call_a5d3a0();
struct FUN_00a81f90_class
{
    void* FUN_00a81f90();
};
// @fnv 0x00a81f90
void* FUN_00a81f90_class::FUN_00a81f90()
{
    _Call_a5d3a0();
    *(int*)this = (int)&DAT_0109e47c;
    *(int*)((char*)this + 0xc) = 0;
    return this;
}

#include <windows.h>
struct S_00a85580_RefObject
{
    virtual ~S_00a85580_RefObject() throw();
    virtual void DeleteThis() throw();
    volatile LONG m_uiRefCount;
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <class T> struct S_00a85580_Pointer
{
    T* m_pObject;
    ~S_00a85580_Pointer() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};
struct S_00a85580_Object
{
    virtual ~S_00a85580_Object() throw();
    int m_uiRefCount;
};
struct S_00a85580_Renderer;
struct FUN_00a85580;
struct S_00a85580_Renderer
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void PurgeSkinInstance(FUN_00a85580* skin) throw();
};
struct FUN_00a85580 : S_00a85580_Object
{
    S_00a85580_Pointer<S_00a85580_RefObject> unk8;
    S_00a85580_Pointer<S_00a85580_RefObject> unkC;
    int unk10;
    void* unk14;
    ~FUN_00a85580() throw();
};
// @fnv 0x00a85580
FUN_00a85580::~FUN_00a85580() throw()
{
    FUN_00aa10f0(unk14);
    if ((*reinterpret_cast<::S_00a85580_Renderer * *>(&::NiRenderer::ms_pRenderer)))
        (*reinterpret_cast<::S_00a85580_Renderer * *>(&::NiRenderer::ms_pRenderer))->PurgeSkinInstance(this);
}
