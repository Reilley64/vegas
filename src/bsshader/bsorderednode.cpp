#include <cstdint>
#include <cstddef>
// bsshader/bsorderednode.cpp: BSOrderedNode, NiBound (6 functions)

#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_00a5dbe0_shell.h"
#include "fnv/decl/FUN_00a5ea70_t.h"
#include "fnv/decl/FUN_00b63090_shell.h"
#include "fnv/decl/FUN_00b63500_shell.h"
#include "fnv/decl/FUN_00bc2c50_class.h"
#include "fnv/decl/NodeA5E8.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a5dd40__FUN_00a5dd40_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01201000.h"
#include "bsorderednode_decls.h"
// Calls NiNode::LoadBinary, loads bound from the stream, and reads staticBound when stream.version > 23, otherwise sets it to true.
// @fnv 0x00bc2e80
void BSOrderedNode::LoadBinary(NiStream& stream)
{
    reinterpret_cast<::fnv_00a5dd40::FUN_00a5dd40_shell *>(this)->FUN_00a5dd40((::NiStream *)&(stream));
    bound.LoadBinary(stream);
    if (stream.version > 23)
    {
        reinterpret_cast<::FUN_00462d80_shell *>((stream.input))->ReadBytes(&staticBound, 1);
    }
    else
    {
        staticBound = true;
    }
}

struct NiBound
{
    float c0;
    float c1;
    float c2;
    float c3;
    bool operator==(const NiBound& b) const
    {
        return c0 == b.c0 && c1 == b.c1 && c2 == b.c2 && c3 == b.c3;
    }
    bool FUN_00a926b0(const NiBound& b);
public:
    char *FUN_00a7fb20(const char *);
};
// Returns true when this NiBound differs from b, i.e. the negation of operator==.
// @fnv 0x00a926b0
bool NiBound::FUN_00a926b0(const NiBound& b)
{
    return !(*this == b);
}

// ---------------------------------------------------------------------------
// UpdateCullingBound - the culling helper of a BSOrderedNode.
//
// The node hands its bound over to the accumulator of the culling process.
// A node with a static bound transforms the centre of its bound sphere with
// its own transform and scales the radius of the sphere; every other node
// just passes the bound it keeps itself (or the default bound when it has
// none).  Afterwards the node is notified about the culling process and the
// accumulator is closed.
// ---------------------------------------------------------------------------

// The centre of a bound.
struct NiPoint3
{
    float x;
    float y;
    float z;
};

// The bound of a node.  The pack's NiBound is a flat structure of four
// floats, so the centre is overlaid on it.
union NiBoundOverlay
{
    NiBound bound;
    NiPoint3 centre;
};

// The fields of a bound sphere.  The pack's NiSphere only gives its size, so
// the fields are overlaid on it.
struct NiSphereFields
{
    float x;
    float y;
    float z;
    float radius;
};

// The bound sphere of a node.
union BoundSphere
{
    NiSphere sphere;
    NiSphereFields fields;
};

// The transform of a node: a 3x3 matrix, a pointer and the uniform scale
// that is applied to the radii of the node's bound.
class NiTransform
{
  public:
    float m00, m01, m02;     // +0x00
    float m10, m11, m12;     // +0x0c
    float m20, m21, m22;     // +0x18
    void* unk24;             // +0x24
    unsigned char unk28[8];  // +0x28
    float scale;             // +0x30
    void FUN_00524c40(NiPoint3* centre, const NiSphere* sphere);
};

// The accumulator of the culling process.
class DummyAccum
{
  public:
};

// The culling process; the accumulator it collects the bounds in sits at
// the end of it.
class NiCullingProcess
{
  public:
    unsigned char unk00[0xc4];  // +0x00
    DummyAccum* pAccumulator;   // +0xc4
};

// The node the culling code works on.  Its layout is the one of a
// BSOrderedNode: the data of the node, the bound sphere and the flag that
// tells whether the bound is static.
class DummyNode
{
  public:
    unsigned char unk00[0x20];  // +0x00
    NiBound* pBound;            // +0x20  bound of a node without a static bound
    unsigned char unk24[0x44];  // +0x24
    NiTransform xform;          // +0x68
    unsigned char unk9c[0x10];  // +0x9c
    BoundSphere bound;          // +0xac
    bool staticBound;           // +0xbc
    void UpdateCullingBound(NiCullingProcess* culling);
};

// The bound a node without a bound of its own is given.
NiBound g_defaultBound;

// @fnv 0x00bc2d70
void DummyNode::UpdateCullingBound(NiCullingProcess* culling)
{
    DummyAccum* accum = culling->pAccumulator;

    if (staticBound)
    {
        NiPoint3 centre;
        xform.FUN_00524c40(&centre, &bound.sphere);

        NiBoundOverlay out;
        out.centre = centre;
        out.bound.c3 = bound.fields.radius * xform.scale;
        reinterpret_cast<::FUN_00b63500_shell *>((accum))->RenderBound((void *)&(out.bound), 0);
    }
    else
    {
        NiBound* b = pBound;
        if (!b)
            b = &g_defaultBound;
        reinterpret_cast<::FUN_00b63500_shell *>((accum))->RenderBound((void *)&(*b), 0);
    }

    reinterpret_cast<::FUN_00a5dbe0_shell *>(this)->FUN_00a5dbe0(culling);
    reinterpret_cast<::FUN_00b63090_shell *>((accum))->DispatchBatchRenderer();
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedObject
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;


    SpawnedObject();
};

class FUN_00bc2e00_cls
{
  public:
    SpawnedObject* CreateSpawnedObject(void* arg);
};

// Allocates a SpawnedObject, initialises it via CopyTailFields with arg, and returns the new object.
// @fnv 0x00bc2e00
SpawnedObject* FUN_00bc2e00_cls::CreateSpawnedObject(void* arg)
{
    SpawnedObject* obj = 0;
    obj = new SpawnedObject();
    reinterpret_cast<::FUN_00bc2c50_class *>((this))->CopyTailFields((::FUN_00bc2c50_class *)(obj), (std::intptr_t)(arg));
    return obj;
}

typedef unsigned int(__cdecl* BinaryReadFn)(NiBinaryStream*, void*, unsigned int, const unsigned int*, unsigned int);

struct LoadBoundSphere
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;

};

struct LoadBinaryStreamView
{
    void* vtable;
    unsigned int position;
    unsigned int unk08;
    BinaryReadFn readFn;

    unsigned int Read(void* buffer, unsigned int bytes)
    {
        unsigned int size = 1;
        unsigned int result = readFn((NiBinaryStream*)this, buffer, bytes, &size, 1);
        position += result;
        return result;
    }
};

struct LoadStreamView : NiStream
{
    LoadBinaryStreamView* m_pInput;
};

struct FUN_00bc2ee0_cls : NiNode
{
    LoadBoundSphere bound;
    bool staticBound;

    void LoadBoundSphereAndStaticBound(NiStream& aStream);
};

// Calls the base loader, loads the bound sphere from the stream, then reads one byte into staticBound.
// @fnv 0x00bc2ee0
void FUN_00bc2ee0_cls::LoadBoundSphereAndStaticBound(NiStream& aStream)
{
    reinterpret_cast<::NodeA5E8 *>(this)->FUN_00a5e880((::NiStreamA5E8 &)(aStream));
    reinterpret_cast<::NiSphere *>(&(bound))->SaveBinary(aStream);

    LoadStreamView& view = (LoadStreamView&)aStream;
    view.m_pInput->Read(&staticBound, 1);
}

struct S_00bc2f30_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short unk0c;
    unsigned short growBy;
};
struct S_00bc2f30_Vec
{
    int x;
    int y;
    int z;
};
struct S_00bc2f30_Bound
{
    int x;
    int y;
    int z;
    float w;
};
struct S_00bc2f30_Xf
{
    int xf0;
    void FUN_00524c40(S_00bc2f30_Vec* out, void* in);
};
struct S_00bc2f30_Base
{
};
struct S_00bc2f30_Cls : S_00bc2f30_Base
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
    S_00bc2f30_Xf m68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    float m98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    float mB8;
    unsigned char mBC;
    void AppendAlphaSortBound(S_00bc2f30_Arr* a);
};
__forceinline void S_00bc2f30_Add(S_00bc2f30_Arr* a, char* s)
{
    unsigned int i = a->esize;
    if (i >= a->size)
        reinterpret_cast<::ViewerStrings *>((a))->SetSize(i + a->growBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((a))->SetAt(i, s);
}
// @fnv 0x00bc2f30
void S_00bc2f30_Cls::AppendAlphaSortBound(S_00bc2f30_Arr* a)
{
    reinterpret_cast<::FUN_00a5ea70_t *>(this)->FUN_00a5ea70((::StrArr *)(a));
    S_00bc2f30_Add(a, FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01201f84))));
    S_00bc2f30_Add(a, ::FUN_00a7d370("bHasStaticBound", mBC));
    S_00bc2f30_Vec sortVec;
    m68.FUN_00524c40(&sortVec, &unkAC);
    S_00bc2f30_Bound b;
    b.w = mB8 * m98;
    b.x = sortVec.x;
    b.y = sortVec.y;
    b.z = sortVec.z;
    S_00bc2f30_Add(a, reinterpret_cast<::NiBound *>(&(b))->FUN_00a7fb20("Alpha Sort Bound"));
}
