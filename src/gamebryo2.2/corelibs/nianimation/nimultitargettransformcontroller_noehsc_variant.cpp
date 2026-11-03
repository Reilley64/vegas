
// src/gamebryo2.2/corelibs/nianimation/nimultitargettransformcontroller_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nianimation/nimultitargettransformcontroller.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include <windows.h>
#include <cstring>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f6000.h"
class NiInterpolator;
class NiAVObject;
class ThreeByThreeMatrix
{
  public:
    float m[9];
};
class NiQuaternion
{
  public:
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    void FromRotationMatrix(const ThreeByThreeMatrix&) throw();
};
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
};
class NiQuatTransform
{
  public:
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
};
class NiTransformInterpolator : public NiMemObject
{
  public:
    char m_data[0x48];
    NiTransformInterpolator(NiQuatTransform) throw();
};
class NiMultiTargetTransformController
{
  public:
    virtual NiInterpolator* GetInterpolatorAtIndex(unsigned short);
    char m_ucUnknownByte[0x30];
    void* m_pkBlendInterpolators;
    NiAVObject** m_ppTargetObjects;
};
struct NiMultiTargetTransformController__PoseSource
{
    unsigned char m_ucUnknownByte[0x34];
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};

class MemoryManager
{
  public:
};



inline void* operator new(unsigned int n)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(n);
}

class BlendInterp
{
  public:
    BlendInterp() throw();
    virtual ~BlendInterp();
    static void* operator new[](unsigned int);
    static void operator delete[](void*);
    unsigned int m_uiRefCount;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
};

class Controller
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    BlendInterp* m_pkBlendInterpolators;
    void** m_ppTargetObjects;
    unsigned short m_usNumTargets;
    void FUN_00a2feb0(unsigned short n);
};

// @fnv 0x00a2feb0
void Controller::FUN_00a2feb0(unsigned short n)
{
    m_usNumTargets = n;
    if (n == 0)
        return;

    m_pkBlendInterpolators = new BlendInterp[n];
    for (unsigned short i = 0; i < n; i++)
        m_pkBlendInterpolators[i].IncRefCount();

    m_ppTargetObjects = (void**)::FUN_00aa1070((unsigned int)n * 4);
    std::memset(m_ppTargetObjects, 0, (unsigned int)n * 4);
}

struct MMDealloc : public MemoryManager
{
};

inline void operator delete(void* p) throw()
{
    reinterpret_cast<::FNV_MemoryManager *>((((MMDealloc*)&::g_memoryManager)))->FUN_00aa4060(p);
}

struct SNAEntry
{
    static void* operator new[](unsigned int size) throw();
};

struct FUN_00a409b0_class : public SNAEntry
{
    virtual ~FUN_00a409b0_class() throw();
    void* m_pkUnk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    FUN_00a409b0_class() throw();
};

extern void(* DAT_00fdf1c0)(void*);

struct FUN_00a30160_cls : public NiMultiTargetTransformController
{
    unsigned short m_usNumTargets;
    void FUN_00a30160();
};

// @fnv 0x00a30160
void FUN_00a30160_cls::FUN_00a30160()
{
    if (m_usNumTargets == 0)
        return;
    if (m_pkBlendInterpolators == 0)
        return;

    delete[] (FUN_00a409b0_class*)m_pkBlendInterpolators;

    m_pkBlendInterpolators = new FUN_00a409b0_class[m_usNumTargets];

    unsigned short i = 0;
    if (i < m_usNumTargets)
    {
        void(* fn)(void*) = DAT_00fdf1c0;
        do
        {
            fn((char*)m_pkBlendInterpolators + 4 + i * 0x30);
            ++i;
        } while (i < m_usNumTargets);
    }

    std::memset(m_ppTargetObjects, 0, m_usNumTargets * 4);
}

#include "generated/data/gamebryo2.2/corelibs/nianimation/nimultitargettransformcontroller_noehsc_variant.inc"
