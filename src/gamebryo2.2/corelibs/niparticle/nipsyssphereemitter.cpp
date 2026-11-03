// gamebryo2.2/corelibs/niparticle/nipsyssphereemitter.cpp: NiPSysSphereEmitter, PSysSphereEmitter (10 functions)

#include <new>
#include "fnv/decl/FUN_00c31b80_This.h"
#include "fnv/decl/FUN_00c31db0_cls.h"
#include "fnv/decl/NiPSysBoxEmitterWrapper.h"
#include "fnv/decl/PositionState.h"
#include "fnv/decl/Stub_00c31b60.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_01202000.h"
#include "nipsyssphereemitter_decls.h"
// Calls the base LoadBinary, then reads a 4-byte value from the stream into a member and advances the stream position.
// @fnv 0x00c20040
void NiPSysSphereEmitter::LoadBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::LoadBinary(stream);
    NiBinaryStream* __restrict input = stream.input;
    unsigned int size = 4;
    input->position += input->read(input, &m_fBoundRadius, 4, &size, 1);
}

struct GlobalObjectO2_00a7b610;

// @fnv 0x00c1fe10
GlobalObjectO2_00a7b610* __cdecl FUN_00c1fe10()
{
    return &::g_01202510;
}

extern int DAT_010bd974;
struct BSFadeNode
{
    void* operator new(unsigned int size);
    void FUN_00c31af0();
    void* m_pvt;
    char m_auiShapeKeys[0x54];
    float m_f58;
};
// @fnv 0x00c1fff0
BSFadeNode* __cdecl FUN_00c1fff0()
{
    BSFadeNode* p = static_cast<BSFadeNode*>(BSFadeNode::operator new(0x5c));
    if (p)
    {
        p->FUN_00c31af0();
        p->m_f58 = 0.0f;
        p->m_pvt = &DAT_010bd974;
        return p;
    }
    return 0;
}

struct Holder31750
{
};
struct Holder20020
{
    void* FUN_00c20020(unsigned int);
};
// Calls FUN_00c31750 on this, then deletes this with size 0x5c when bit 0 of f is set, and returns this.
// @fnv 0x00c20020
void* Holder20020::FUN_00c20020(unsigned int auiFlags)
{
    reinterpret_cast<::PositionState *>((((Holder31750*)this)))->FUN_00c31750();
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0x5c);
    return this;
}

struct Base00c1fde0
{
    char _pad[0x58];
};
struct Holder00c1fde0 : Base00c1fde0
{
    float m_fCylinderRadius;
    bool __thiscall FUN_00c1fde0(void* pkObject);
};
// @fnv 0x00c1fde0
bool __thiscall Holder00c1fde0::FUN_00c1fde0(void* pkObject)
{
    Holder00c1fde0* pkDest = (Holder00c1fde0*)pkObject;
    if (!reinterpret_cast<::FUN_00c31b80_This *>(this)->FUN_00c31b80(pkObject))
        return false;
    if (m_fCylinderRadius != pkDest->m_fCylinderRadius)
        return false;
    return true;
}

struct FUN_00c1ffa0_s
{
    float m_f58;
    BSFadeNode* CreateFadeNode(void* pkCloningProcess);
};

// FUN_00c20080 - the sphere emitter's stream loader.
//
// The pack's NiStream / NiBinaryStream declarations do not match the original
// code: the original takes the binary stream from stream+0x250 (the pack says
// +0x24c) and the reader function pointer from stream+0x0c (the pack says
// +0x08), so both objects are modelled here with the offsets read out of the
// original code.
//
// The original does, in this order:
//   push esi / mov esi,[esp+8] / push edi / push esi / mov edi,ecx
//   call <base loader>                    ; NiPSysVolumeEmitter::LoadBinary
//   mov esi,[esi+0x250]                   ; the binary stream
//   mov ecx,[esi+0xc]                     ; its reader
//   push 1 / lea eax,[esp+0x10] / push eax / push 4
//   add edi,0x58 / push edi / push esi
//   mov dword ptr [esp+0x20],4            ; the element size
//   call ecx
//   add dword ptr [esi+4],eax             ; position += bytes read
//   add esp,0x14 / pop edi / pop esi / ret 4

struct BinaryStream
{
    unsigned int unk00;
    unsigned int position;  // +0x04
    unsigned int unk08;
    unsigned int(__cdecl* read)(BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);  // +0x0c
};

struct GameStream
{
    char padding[0x250];
    BinaryStream* input;  // +0x250
};

// The emitter object: its vtable pointer sits at +0x00, so the sphere
// emitter's radius float lands at +0x58.
struct PSysVolumeEmitter
{
    void* vtable;  // +0x00
    char padding[0x54];
};

struct PSysSphereEmitter : PSysVolumeEmitter
{
    float m_fBoundRadius;  // +0x58
    void FUN_00c20080(GameStream& stream);
};

// @fnv 0x00c20080
void PSysSphereEmitter::FUN_00c20080(GameStream& stream)
{
    reinterpret_cast<::Stub_00c31b60 *>(this)->FUN_00c31b60((void *)&(stream));
    BinaryStream* input = stream.input;
    {
        unsigned int size = 4;
        input->position += input->read(input, &m_fBoundRadius, 4, &size, 1);
    }
}

struct FUN_00c200c0_Arr
{
    int unk00;
    int unk04;
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short unk0c;
    unsigned short m_usGrow;
};


struct Emitter00c200c0
{
    char pad[0x58];
    float m_f58;
    void __thiscall AppendTwoValues(FUN_00c200c0_Arr* p);
};

// Appends a value derived from DAT_01202510 and a value computed from m_f58 into the array p, growing it when full.
// @fnv 0x00c200c0
void __thiscall Emitter00c200c0::AppendTwoValues(FUN_00c200c0_Arr* p)
{
    reinterpret_cast<::FUN_00c31db0_cls *>((p))->FUN_00c31db0({});
    unsigned int uiValue = ((unsigned int)(::FUN_00a7d330((const char *)((*reinterpret_cast<unsigned int *>(&::g_01202510))))));
    unsigned int n = p->m_usSize;
    if (n >= p->m_usMax)
    {
        reinterpret_cast<::ViewerStrings *>((p))->SetSize(p->m_usGrow + n);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((p))->SetAt(n, (*(char * *)(&uiValue)));
    uiValue = ((unsigned int)(::FUN_00a7d550((const char *)(const void *)(&UNK_01015a9c), m_f58)));
    n = p->m_usSize;
    if (n >= p->m_usMax)
    {
        reinterpret_cast<::ViewerStrings *>((p))->SetSize(p->m_usGrow + n);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((p))->SetAt(n, (*(char * *)(&uiValue)));
}

struct S_00c31af0_Base
{
    virtual void vf00();
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
    S_00c31af0_Base();
};
struct FUN_00c31af0 : S_00c31af0_Base
{
    int unk54;
    FUN_00c31af0();
};
// @fnv 0x00c1ffa0
BSFadeNode* FUN_00c1ffa0_s::CreateFadeNode(void* pkCloningProcess)
{
    BSFadeNode* pkObject = new BSFadeNode;
    if (pkObject)
    {
        new ((void *)(pkObject)) ::FUN_00c31af0();
        pkObject->m_f58 = 0.0f;
        pkObject->m_pvt = &DAT_010bd974;
    }
    else
    {
        pkObject = 0;
    }
    reinterpret_cast<::NiPSysBoxEmitterWrapper *>(this)->FUN_00c31b10((::NiPSysModifier *)(pkObject), (*(::CloningProcess *)(pkCloningProcess)));
    pkObject->m_f58 = ((float*)((char*)this + 0x58))[0];
    return pkObject;
}
// @fnv 0x00c31af0
FUN_00c31af0::FUN_00c31af0() : S_00c31af0_Base()
{
    unk54 = 0;
}

extern "C" int __cdecl rand();
  // sin table, 512 entries
  // cos table, 512 entries
extern float g_fTwoPi;

struct SpherePoint3
{
    float x, y, z;
};

struct SphereMatrix3
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    SpherePoint3 Multiply(const SpherePoint3& p) const;
};

struct SphereEmitter00c1fe20 : NiPSysSphereEmitter
{
    void GenerateSpherePoint(SphereMatrix3& kRotate, SpherePoint3& kPosition, SpherePoint3& kMotionVelocity);
};

static inline float UnitRandom()
{
    return (float)(rand() / 32767.0);
}

// @fnv 0x00c1fe20
void SphereEmitter00c1fe20::GenerateSpherePoint(SphereMatrix3& kRotate, SpherePoint3& kPosition,
                                                SpherePoint3& kMotionVelocity)
{
    float fRadius = m_fBoundRadius * UnitRandom();
    float fAngle1 = g_fTwoPi * UnitRandom();
    float fAngle2 = g_fTwoPi * UnitRandom();
    int i1 = (int)(fAngle1 * (512.0 / g_fTwoPi)) & 0x1ff;
    float fCos1 = DAT_011f52e0[i1];
    int i2 = (int)(fAngle2 * (512.0 / g_fTwoPi)) & 0x1ff;
    float fCos2 = DAT_011f52e0[i2];
    float fSin2 = DAT_011f4ae0[i2];
    float fSin1 = DAT_011f4ae0[i1];

    kPosition.x = fRadius * fCos2 * fSin1;
    kPosition.y = fRadius * fCos2 * fCos1;
    kPosition.z = fRadius * fSin2;

    kPosition = kRotate.Multiply(kPosition);

    SpherePoint3 v;
    v.x = kRotate.m00 * kMotionVelocity.x + kRotate.m01 * kMotionVelocity.y + kRotate.m02 * kMotionVelocity.z;
    v.y = kRotate.m10 * kMotionVelocity.x + kRotate.m11 * kMotionVelocity.y + kRotate.m12 * kMotionVelocity.z;
    v.z = kRotate.m20 * kMotionVelocity.x + kRotate.m21 * kMotionVelocity.y + kRotate.m22 * kMotionVelocity.z;
    kMotionVelocity = v;
}
