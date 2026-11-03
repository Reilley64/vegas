
// src/havok/physics/utilities/charactercontrol/statemachine/hkpcharactercontext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/statemachine/hkpcharactercontext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpCharacterStateView.h"
#include "fnv/symbols_0102e000.h"
extern int DAT_010c8198;
struct hkReferencedObject
{
};
struct FUN_00ca95e0_class
{
    int m_p;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    void FUN_00ca95e0();
};
// @fnv 0x00ca95e0
void FUN_00ca95e0_class::FUN_00ca95e0()
{
    m_p = (int)&DAT_010c8198;
    reinterpret_cast<::hkReferencedObjectC905 *>((((hkReferencedObject*)m_uiZ)))->FUN_00c905b0();
    m_p = (int)&(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct FUN_00ca9670_cls
{
    void FUN_00ca9670(float a, float b, float c);
};
// @fnv 0x00ca9670
void FUN_00ca9670_cls::FUN_00ca9670(float a, float b, float c)
{
    *(float*)((char*)this + 0x24) = a;
    *(float*)((char*)this + 0x20) = b;
    *(float*)((char*)this + 0x1c) = c;
}

struct FUN_00ca9660_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned char m_18;

    void FUN_00ca9660(unsigned char value);
};

// @fnv 0x00ca9660
void FUN_00ca9660_cls::FUN_00ca9660(unsigned char value)
{
    m_18 = value;
}

struct FUN_00ca9690_cls
{
    int unk00;
    int unk04;
    int m_08;

    void FUN_00ca9690(int value);
};

// @fnv 0x00ca9690
void FUN_00ca9690_cls::FUN_00ca9690(int value)
{
    m_08 = value;
}

extern int DAT_010c8198;

struct hkpCharacterContext
{
    int* vtbl;
    short unk04;
    short unk06;
    int unk08;
    void* unk0C;
    int unk10;
    int unk14;
    unsigned char unk18;
    float unk1C;
    float unk20;
    float unk24;

    hkpCharacterContext* Initialize(void* arg0, int arg1);
};

// @fnv 0x00ca9580
hkpCharacterContext* hkpCharacterContext::Initialize(void* arg0, int arg1)
{
    unk06 = 1;
    unk0C = arg0;
    vtbl = &DAT_010c8198;
    unk10 = arg1;
    unk14 = arg1;
    unk08 = 0;
    unk18 = 1;

    float& f20 = unk20;
    f20 = 20.0f;
    unk1C = 625.0f;
    unk24 = 1.0f;
    reinterpret_cast<::FUN_00c90510_class *>((unk0C))->FUN_00c90510();

    return this;
}

// @fnv 0x00ca9600
int FUN_00ca9600(char* object)
{
    return *reinterpret_cast<int*>(object + 0x10);
}

class hkpCharacterContextCA96;
struct hkpCharacterInputCA96;
struct hkpCharacterOutputCA96;

class hkpCharacterStateCA96
{
  public:
    virtual ~hkpCharacterStateCA96() throw();
    virtual int getType() const throw();
    virtual void update(hkpCharacterContextCA96& kContext, const hkpCharacterInputCA96& kInput,
                        hkpCharacterOutputCA96& kOutput) throw();
    virtual void change(hkpCharacterContextCA96& kContext, const hkpCharacterInputCA96& kInput,
                        hkpCharacterOutputCA96& kOutput) throw();
    virtual void enterState(hkpCharacterContextCA96& kContext, int iPrevState, const hkpCharacterInputCA96& kInput,
                            hkpCharacterOutputCA96& kOutput) throw();
    virtual void leaveState(hkpCharacterContextCA96& kContext, int iNextState, const hkpCharacterInputCA96& kInput,
                            hkpCharacterOutputCA96& kOutput) throw();
};

class hkpCharacterStateManagerCA96
{
  public:
};

class hkpCharacterContextCA96
{
  public:
    int unk00;
    int unk04;
    int m_iCurrentState;
    const hkpCharacterStateManagerCA96* pCharacterStateManager;
    int m_iPreviousState;

    void SetState(int iState, const hkpCharacterInputCA96& kInput, hkpCharacterOutputCA96& kOutput);
};

// Leaves the current state, stores the new state id, then enters the new state via the state manager.
// @fnv 0x00ca9610
void hkpCharacterContextCA96::SetState(int iState, const hkpCharacterInputCA96& kInput, hkpCharacterOutputCA96& kOutput)
{
    int iPrevState = m_iPreviousState;
    ((::hkpCharacterStateCA96 *)(reinterpret_cast<::hkpCharacterStateView *>((void *)(pCharacterStateManager))->FUN_00cbc510(m_iPreviousState)))->leaveState(*this, iState, kInput, kOutput);
    m_iPreviousState = iState;
    ((::hkpCharacterStateCA96 *)(reinterpret_cast<::hkpCharacterStateView *>((void *)(pCharacterStateManager))->FUN_00cbc510(iState)))->enterState(*this, iPrevState, kInput, kOutput);
}

struct FnvCpu_FUN_00ca9810_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00ca9810_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00ca9810_CpuAllocator* allocator;
};
static inline FnvCpu_FUN_00ca9810_CpuAllocatorHolder* getMemoryRouter() { return static_cast<FnvCpu_FUN_00ca9810_CpuAllocatorHolder*>(::FUN_00c85750()); }
struct FnvCpu_FUN_00ca9810_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00ca9810_CpuObject* Destroy(unsigned int flags);
};
// Calls FUN_00ca95e0, then if bit 0 of flags is set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00ca9810
FnvCpu_FUN_00ca9810_CpuObject* FnvCpu_FUN_00ca9810_CpuObject::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00ca95e0_class *>(this)->FUN_00ca95e0();
    if (flags & 1)
    {
        FnvCpu_FUN_00ca9810_CpuAllocatorHolder* pAllocatorHolder = getMemoryRouter();
        pAllocatorHolder->allocator->Invoke(this, size);
    }
    return this;
}

#include <xmmintrin.h>
class VectorComponentValue
{
  public:
    __m128 m_vValue;
    inline VectorComponentValue()
    {}
    inline VectorComponentValue(__m128 x) : m_vValue(x)
    {}
    inline VectorComponentValue(const float& x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    inline float getReal() const
    {
        float r;
        _mm_store_ss(&r, m_vValue);
        return r;
    }
    inline operator float() const
    {
        return getReal();
    }
};

typedef const VectorComponentValue& hkSimdRealParameter;

class hkVector4
{
  public:
    __m128 m_vComponents;
    inline hkVector4()
    {}
    inline hkVector4(__m128 q) : m_vComponents(q)
    {}
    inline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    inline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    inline void mul4(hkSimdRealParameter r)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), m_vComponents);
    }
    inline void addMul4(hkSimdRealParameter r, const hkVector4& a)
    {
        m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), a.m_vComponents), m_vComponents);
    }
    inline VectorComponentValue length3() const
    {
        __m128 mul = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_shuffle_ps(mul, mul, 0x55);
        __m128 z = _mm_shuffle_ps(mul, mul, 0xaa);
        __m128 sum = _mm_add_ss(z, _mm_add_ss(y, mul));
        return _mm_sqrt_ss(sum);
    }
};

struct PhysicsDataBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    float m_pStepInfo;
    float m_fSecondScalar;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    hkVector4 m_fVelocity;
};

struct Vector4Data
{
    hkVector4 m_fVelocity;
};

struct Context;

struct State
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void change(Context* ctx, const PhysicsDataBlock& input, Vector4Data& output);
    virtual void update(Context* ctx, const PhysicsDataBlock& input, Vector4Data& output);
};

struct StateManager
{
};

struct Context
{
    int unk00;
    int unk04;
    int unk08;
    StateManager* pCharacterStateManager;
    int m_iPreviousState;
    int m_iStateIndex;
    char m_filterParameters;
    char pad19;
    char pad1A;
    char pad1B;
    float m_characterWidth;
    float m_fSurfaceFriction;
    float m_fGain;

    void FUN_00ca96a0(const PhysicsDataBlock& input, Vector4Data& output);
};

// @fnv 0x00ca96a0
void Context::FUN_00ca96a0(const PhysicsDataBlock& input, Vector4Data& output)
{
    output.m_fVelocity = input.m_fVelocity;

    ((::State *)(reinterpret_cast<::hkpCharacterStateView *>((pCharacterStateManager))->FUN_00cbc510(m_iPreviousState)))->update(this, input, output);

    if (m_iPreviousState == m_iStateIndex)
    {
        ((::State *)(reinterpret_cast<::hkpCharacterStateView *>((pCharacterStateManager))->FUN_00cbc510(m_iPreviousState)))->change(this, input, output);
    }

    m_iStateIndex = m_iPreviousState;

    if (m_filterParameters)
    {
        float length = output.m_fVelocity.length3();
        if (length > m_fSurfaceFriction)
        {
            float fClampScale = m_fSurfaceFriction / length;
            output.m_fVelocity.mul4(fClampScale);
        }

        float grav = input.m_fSecondScalar;
        hkVector4 vDelta;
        vDelta.setSub4(output.m_fVelocity, input.m_fVelocity);
        vDelta.mul4(grav);
        float fDeltaLength = vDelta.length3();
        float fDeltaRatio = fDeltaLength / m_characterWidth;
        output.m_fVelocity = input.m_fVelocity;

        float fBlendFactor;
        if (fDeltaRatio > 1.0f && m_iPreviousState != 1)
        {
            fBlendFactor = (input.m_pStepInfo * m_fGain) / fDeltaRatio;
        }
        else
        {
            fBlendFactor = input.m_pStepInfo * m_fGain;
        }

        output.m_fVelocity.addMul4(fBlendFactor, vDelta);
    }
}

// Moved from hkpcharactercontext_od_oy_noo2_variant.cpp (VEGAS-15).
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00ca9000.h"
#include "fnv/symbols_011ac000.h"

// FUN_00716440 (11 bytes)
//
//   push ebp / mov ebp,esp / fld dword ptr [0x11ac3a0] / pop ebp / ret
//
// A one-line float getter.  The full push ebp / mov ebp,esp / ... / pop ebp frame
// is what an UNOPTIMISED (/Od) build emits for every function, even one with no
// locals at all - it is NOT evidence of a local, a volatile or an address-taken
// global.  Under /O2 the very same source compiles to the frameless 7-byte
// `fld dword ptr [g] / ret`, which is why this module needs the /Od flag.
//
// The global lives in the game's .data section (RVA 0x00DAC3A0), so it is a real
// writable variable.  It is declared `extern` and never defined: a definition
// would create a data symbol that the checker's literal-content check compares
// against the original image.
//
// The global's name deliberately does NOT contain the tag "FUN_00716440", so that
// exactly one DEFINED function symbol carries the tag.

// @fnv 0x00716440
float __cdecl FUN_00716440()
{
    return ::DAT_011ac3a0;
}

namespace s008e2680 {

struct Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int m_iValue;

    void FUN_008e2680(int iValue);
};

// @fnv 0x008e2680
void Owner::FUN_008e2680(int iValue)
{
    m_iValue = iValue;
}

}
