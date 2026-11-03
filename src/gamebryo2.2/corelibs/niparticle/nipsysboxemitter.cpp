// gamebryo2.2/corelibs/niparticle/nipsysboxemitter.cpp: NiPSysEmitter, NiPSysBoxEmitter, EmitterHack, BoxViewer and more (13 functions)

#include <new>
#include <cstdlib>
#include "fnv/decl/FUN_00c31af0.h"
#include "fnv/decl/FUN_00c31b80_This.h"
#include "fnv/decl/FUN_00c31c90_shell.h"
#include "fnv/decl/FUN_00c31db0_cls.h"
#include "fnv/decl/NiPSysBoxEmitterWrapper.h"
#include "fnv/decl/PositionState.h"
#include "fnv/decl/Stub_00c31b60.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_01202000.h"
#include "nipsysboxemitter_decls.h"
// Constructs a NiPSysEmitter, initializing speed, declination, planar angle, color, radius, lifespan and unknown to their defaults.
// @fnv 0x00c21f00
NiPSysEmitter::NiPSysEmitter()
    : speed(0.0f), speedVar(0.0f), declination(0.0f), declinationVar(0.0f), planarAngle(0.0f), planarAngleVar(0.0f),
      color((*reinterpret_cast<::RgbaColor *>(&::DAT_011a9be0))), radius(1.0f), radiusVar(0.0f), lifespan(0.0f), lifespanVar(0.0f), unknown(1.0f)
{}
// Loads the box emitter's width, height and depth floats from the stream after the base volume emitter data.
// @fnv 0x00c203b0
void NiPSysBoxEmitter::LoadBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::LoadBinary(stream);
    stream.input->ReadFloat(width);
    stream.input->ReadFloat(height);
    stream.input->ReadFloat(depth);
}

struct GlobalObjectO2_00a7b618
{
};

// @fnv 0x00c201c0
GlobalObjectO2_00a7b618* __cdecl FUN_00c201c0()
{
    return &(*reinterpret_cast<::GlobalObjectO2_00a7b618 *>(&::g_01202518));
}

extern int DAT_010bda2c;
struct BSFadeNode
{
};
// Allocates a 100-byte BSFadeNode, runs its constructor, zeroes the floats at offsets 0x58-0x60, sets its vtable, and returns it (or null).
// @fnv 0x00c20350
BSFadeNode* __cdecl FUN_00c20350()
{
    BSFadeNode* node = (BSFadeNode*)::operator new(100);
    if (node)
    {
        new ((void *)(node)) ::FUN_00c31af0();
        *(float*)((char*)node + 0x58) = 0.0f;
        *(void**)((char*)node + 0) = &DAT_010bda2c;
        *(float*)((char*)node + 0x5c) = 0.0f;
        *(float*)((char*)node + 0x60) = 0.0f;
        return node;
    }
    return 0;
}

struct S
{
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00c20390
void* S::DestroyIfFlagged(unsigned int uiFlags)
{
    static_cast<::PositionState *>(nullptr)->FUN_00c31750();
    if (uiFlags & 1)
        ::FUN_00aa1460(this, 0x64);
    return this;
}

struct NiObject;
struct BaseHack
{
};
struct EmitterHack
{
    char _pad[0x58];
    float m_fValueAtOffset58;
    float m_fCylinderHeight;
    float m_fValueAtOffset60;
    bool IsEqual(NiObject* pkObject);
};
// Calls FUN_00c31b80 on pkObject and returns true only if that succeeds and the three floats at offsets 0x58, 0x5c and 0x60 match the other object's.
// @fnv 0x00c20170
bool EmitterHack::IsEqual(NiObject* pkObject)
{
    EmitterHack* pkDest = (EmitterHack*)pkObject;
    if (reinterpret_cast<::FUN_00c31b80_This *>((((BaseHack*)this)))->FUN_00c31b80(pkObject) && m_fValueAtOffset58 == pkDest->m_fValueAtOffset58 &&
        m_fCylinderHeight == pkDest->m_fCylinderHeight && m_fValueAtOffset60 == pkDest->m_fValueAtOffset60)
        return true;
    return false;
}

struct NiObject
{
};

struct CloningProcess
{
};

struct A51BF0Base
{
};

struct FUN_00c1ffa0_s
{
};

struct NiPSysBoxEmitter_shell
{
    char _pad[0x58];
    float m_fValueAtOffset58;
    float m_fCylinderHeight;
    float m_fValueAtOffset60;
    NiObject* Clone(CloningProcess& kCloning);
};

// @fnv 0x00c202f0
NiObject* NiPSysBoxEmitter_shell::Clone(CloningProcess& kCloning)
{
    BSFadeNode* pkObject = (BSFadeNode*)::operator new(0x64);
    if (pkObject)
    {
        new ((void *)(pkObject)) ::FUN_00c31af0();
        *(float*)((char*)pkObject + 0x58) = 0.0f;
        *(void**)pkObject = (void*)&DAT_010bda2c;
        *(float*)((char*)pkObject + 0x5c) = 0.0f;
        *(float*)((char*)pkObject + 0x60) = 0.0f;
    }
    else
    {
        pkObject = 0;
    }
    reinterpret_cast<::NiPSysBoxEmitterWrapper *>((((FUN_00c1ffa0_s*)this)))->FUN_00c31b10((::NiPSysModifier *)(pkObject), (*(::CloningProcess *)(&kCloning)));
    *(float*)((char*)pkObject + 0x58) = m_fValueAtOffset58;
    *(float*)((char*)pkObject + 0x5c) = m_fCylinderHeight;
    *(float*)((char*)pkObject + 0x60) = m_fValueAtOffset60;
    return (NiObject*)pkObject;
}

struct BoxEmitterBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(BoxEmitterBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct BoxEmitterStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    BoxEmitterBinaryStreamView* m_pUnderlyingStream;
};

struct NiPSysVolumeEmitterStand
{
    void* vtable;
    char unk04[0x50];
};

struct FUN_00c20440_cls : NiPSysBoxEmitter
{
    void FUN_00c20440(NiStream& stream);
};

// Loads the volume emitter base stream, then reads width, height and depth from the stream.
// @fnv 0x00c20440
void FUN_00c20440_cls::FUN_00c20440(NiStream& stream)
{
    reinterpret_cast<::Stub_00c31b60 *>((reinterpret_cast<NiPSysVolumeEmitterStand*>(this)))->FUN_00c31b60((void *)&(stream));
    BoxEmitterStreamView* s = reinterpret_cast<BoxEmitterStreamView*>(&stream);
    s->m_pUnderlyingStream->Load(&width);
    s->m_pUnderlyingStream->Load(&height);
    s->m_pUnderlyingStream->Load(&depth);
}

struct StrArr
{
    void* vtable;
    char** data;
    unsigned short capacity, size, used, grow;
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + grow);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, value);
    }
};
extern const char DAT_0109dc8c[];
extern const char DAT_0109dc84[];
extern const char DAT_010a0eb4[];
struct VolumeViewer : NiPSysVolumeEmitter
{
};
struct BoxViewer : NiPSysBoxEmitter
{
    void FUN_00c204d0(StrArr*);
};
// Appends the base volume emitter's debug strings, then the box emitter's width, height and depth values to the string array.
// @fnv 0x00c204d0
void BoxViewer::FUN_00c204d0(StrArr* strings)
{
    reinterpret_cast<::FUN_00c31db0_cls *>((((VolumeViewer*)this)))->FUN_00c31db0((::NameArray_b9457 *)(strings));
    strings->Add(FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01202518))));
    strings->Add(FUN_00a7d550(DAT_0109dc8c, width));
    strings->Add(FUN_00a7d550(DAT_0109dc84, height));
    strings->Add(FUN_00a7d550(DAT_010a0eb4, depth));
}

struct FUN_00c61f60_class
{
    void FUN_00c2f4f0(int);
};
struct FUN_00c1fdd0
{
    void FUN_00c2f4f0(int);
};
// @fnv 0x00c1fdd0
void FUN_00c1fdd0::FUN_00c2f4f0(int a)
{
    ((FUN_00c61f60_class*)this)->FUN_00c2f4f0(a);
}

// @fnv 0x00c20150
void __cdecl FUN_00c20150()
{
    static_cast<::FUN_00c31c90_shell *>(nullptr)->FUN_00c31c90({});
}


// @fnv 0x00c20160
void __cdecl FUN_00c20160()
{
    static_cast<::NiPSysVolumeEmitter *>(nullptr)->LinkObject(*(::NiStream *)nullptr);
}

namespace fnv_00c201d0 {

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    float Dot(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
};

struct ThreeByThreeMatrix
{
    NiPoint3 m_aRows[3];
    NiPoint3 operator*(const NiPoint3& pt) const;
};

struct BoxEmitterInit : NiPSysBoxEmitter
{
    void FUN_00c201d0(const ThreeByThreeMatrix& kRot, NiPoint3& kPos, NiPoint3& kWorldPosition);
};

// Generates a random point from the box dimensions, rotates it with kRot, and computes row dot products of kRot with kWorldPosition.
// @fnv 0x00c201d0
void BoxEmitterInit::FUN_00c201d0(const ThreeByThreeMatrix& kRot, NiPoint3& kPos, NiPoint3& kWorldPosition)
{
    float fX = std::rand() / ::DAT_01029790;
    float fY = std::rand() / ::DAT_01029790;
    float fZ = std::rand() / ::DAT_01029790;
    kPos = NiPoint3((fZ - 0.5f) * width, (fY - 0.5f) * height, (fX - 0.5f) * depth);
    kPos = kRot * kPos;
    kWorldPosition = NiPoint3(kRot.m_aRows[0].Dot(kWorldPosition),
                              kRot.m_aRows[1].x * kWorldPosition.x + kRot.m_aRows[1].y * kWorldPosition.y +
                                  kRot.m_aRows[1].z * kWorldPosition.z,
                              kRot.m_aRows[2].Dot(kWorldPosition));
}
}  // namespace fnv_00c201d0

#include "generated/data/gamebryo2.2/corelibs/niparticle/nipsysboxemitter.inc"
