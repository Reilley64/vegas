
// src/havok/common/visualize/serialize/hkdisplayserializeostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkdisplayserializeostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dda830
#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/Archive.h"
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/D60590Object.h"
#include "fnv/decl/FNVFloatGetter_cls.h"
#include "fnv/decl/FUN_00827200_class.h"
#include "fnv/decl/FUN_00d605b0_class.h"
#include "fnv/decl/FUN_00d60b00_class.h"
#include "fnv/decl/FUN_00dda6b0_Class.h"
#include "fnv/decl/FUN_00de48f0_cls.h"
#include "fnv/decl/FUN_00de4910_cls.h"
#include "fnv/decl/FUN_00de4e10_cls.h"
#include "fnv/decl/FUN_00de5350_cls.h"
#include "fnv/decl/FUN_00de5360_cls.h"
#include "fnv/decl/FnvCpu_FUN_00de1150_CpuObject.h"
#include "fnv/decl/FnvCpu_FUN_00de1160_CpuObject.h"
#include "fnv/decl/FnvCpu_FUN_00de4de0_CpuObject.h"
#include "fnv/decl/fnv_00de4e00__CpuObject.h"
#include "fnv/decl/fnv_00de5340__CpuObject.h"
#include "fnv/decl/hkOArchive_2.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00d60000.h"
#include "fnv/symbols_00dda000.h"
#include "fnv/symbols_00de4000.h"
#include "fnv/symbols_010d7000.h"
unsigned int FUN_00dda830(const unsigned int* puiValues)
{
    return 4 * (3 * (puiValues[4] + puiValues[1])) + 8;
}

// @fnv 0x00dda730
void FUN_00dda730(uintptr_t p)
{
    reinterpret_cast<::FUN_00d60b00_class *>((p))->WriteFloatArray((const float *)(3), {});
}

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    hkBool(const hkBool& o)
    {
        m_cBooleanValue = o.m_cBooleanValue;
    }
};

struct RefObj
{
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct FUN_00d27460 : RefObj
{
    int pad[(0x1c - 8) / 4];
    __declspec(nothrow) FUN_00d27460(intptr_t a, int b);
};

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().AllocateMemoryBlock(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}


struct FUN_00d60830 : RefObj
{
    RefObj* m_8;
    __declspec(nothrow) FUN_00d60830(RefObj* o, hkBool b);
};


struct FUN_00dda6e0 : FUN_00d60830
{
    FUN_00dda6e0(intptr_t a);
};

// Constructs a FUN_00d60830 base with a newly allocated FUN_00d27460(a, 0x2000), sets the vtable, and calls FUN_00c905b0 on m_8.
// @fnv 0x00dda6e0
FUN_00dda6e0::FUN_00dda6e0(intptr_t a) : FUN_00d60830(new(hkAlloc(sizeof(FUN_00d27460))) FUN_00d27460(a, 0x2000), false)
{
    m_vtbl = (*reinterpret_cast<char (*)[]>(&::DAT_010d7db8));
    reinterpret_cast<::hkReferencedObjectC905 *>((m_8))->FUN_00c905b0();
}

struct DDA7C0Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct DDA7C0Triangle
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
};

template <class T> struct DDA7C0Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct DDA7C0Geometry
{
    DDA7C0Array<DDA7C0Vector4> m_kVertices;
    DDA7C0Array<DDA7C0Triangle> m_uiTriangleCount;
};

struct DDA7C0OStream
{

    void WriteGeometry(const DDA7C0Geometry& geometry);
};

// Writes the vertex count and vertices, then the triangle count and triangles, of a geometry to the stream.
// @fnv 0x00dda7c0
void DDA7C0OStream::WriteGeometry(const DDA7C0Geometry& geometry)
{
    int numVertices = geometry.m_kVertices.m_iElementCount;
    reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(numVertices);
    for (int i = 0; i < numVertices; i++)
        ::FUN_00dda730((uintptr_t)this);
    int numTriangles = geometry.m_uiTriangleCount.m_iElementCount;
    reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(numTriangles);
    for (int i = 0; i < numTriangles; i++)
        reinterpret_cast<::FUN_00dda6b0_Class *>(this)->WriteUInt32Triple((const unsigned int *)&(geometry.m_uiTriangleCount.m_data[i]));
}

namespace fnv_00ddabb0 {
struct Allocator
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void Free(void* block, unsigned int size);
};
struct AllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Allocator* allocator;
};
AllocatorHolder* __cdecl FUN_00c85750();
struct FUN_00ddabb0_shell
{
    void* unk00;
    unsigned short size;
    FUN_00ddabb0_shell* FUN_00ddabb0(unsigned int flags);
};
// Calls FUN_00d60590, then if bit 0 of flags is set frees this through the allocator from FUN_00c85750, and returns this.
// @fnv 0x00ddabb0
FUN_00ddabb0_shell* FUN_00ddabb0_shell::FUN_00ddabb0(unsigned int flags)
{
    reinterpret_cast<::D60590Object *>(this)->FUN_00d60590();
    if (flags & 1)
    {
        AllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Free(this, size);
    }
    return this;
}
}  // namespace fnv_00ddabb0

// Stand-in for the class that owns WriteUInt16 (the game's own class name for
// the neighbourhood is hkOArchive; no layout information is needed here because
// the function never touches a member).
//
// The original is a member with ONE 4-byte stack argument (the
// callers do `mov ecx,<object> / push <arg> / call WriteUInt16`, and the body
// ends in `ret 4`).  It forwards `this` (ECX) unchanged to WriteSwapped and
// passes the ADDRESS of its own incoming argument as the first argument of
// that call, followed by the constants 2 and 1:
//
//     push 1
//     push 2
//     lea eax, [esp+0xc]      ; &argument  (the incoming stack slot)
//     push eax
//     call 0x00d60600
//     ret 4
//
// WriteSwapped is a member of its own (it uses ECX as `this` and
// pops three 4-byte arguments), so it is only DECLARED here: the call target
// is then bound by the checker from the original's own bytes.

struct hkOArchiveStandIn
{
      // declared, never defined
    void WriteUInt16(uintptr_t value);
};

// @fnv 0x00d60920
void hkOArchiveStandIn::WriteUInt16(uintptr_t value)
{
    reinterpret_cast<::Archive *>(this)->WriteSwapped(&value, 2, 1);
}

#include <xmmintrin.h>
struct S_00dda740_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};

struct S_00dda740_Matrix3
{
    S_00dda740_Vector4 m_kColumn0;
    S_00dda740_Vector4 m_kColumn1;
    S_00dda740_Vector4 m_kColumn2;
    S_00dda740_Matrix3(const S_00dda740_Matrix3& o)
    {
        m_kColumn0.q() = o.m_kColumn0.q();
        m_kColumn1.q() = o.m_kColumn1.q();
        m_kColumn2.q() = o.m_kColumn2.q();
    }
};

struct S_00dda740_Transform
{
    S_00dda740_Matrix3 m_rotation;
    S_00dda740_Vector4 m_vTranslation;
};

struct S_00dda740_Quaternion
{
    S_00dda740_Vector4 m_vec;
};

struct S_00dda740
{
    void WriteTransform(const S_00dda740_Transform& t);
};

// Converts the rotation matrix to a quaternion and writes the translation and quaternion components to the stream.
// @fnv 0x00dda740
void S_00dda740::WriteTransform(const S_00dda740_Transform& t)
{
    S_00dda740_Vector4 trans = t.m_vTranslation;
    __declspec(align(16)) S_00dda740_Matrix3 rot = t.m_rotation;
    __declspec(align(16)) S_00dda740_Quaternion q;
    reinterpret_cast<::FUN_00827200_class *>(&(q))->FUN_00cb26e0((intptr_t)&(rot));
    reinterpret_cast<::FUN_00d60b00_class *>(this)->WriteFloatArray(&trans.x, 3);
    reinterpret_cast<::FUN_00d60b00_class *>(this)->WriteFloatArray(&q.m_vec.x, 4);
}


// Returns a constant chosen by the int at param+0x50 (0x1d plus FUN_00dda830(param+8) for 6), or 1 for other values.
// @fnv 0x00dda850
int FUN_00dda850(intptr_t param)
{
    int result = 1;
    switch (*(int*)(param + 0x50))
    {
    case 6:
        result = ((int)(::FUN_00dda830((const unsigned int *)(*(intptr_t*)(param + 8)))));
        return result + 0x1d;
    case 1:
    case 5:
        return 0x35;
    case 8:
    case 9:
        return 0x41;
    case 3:
        return 0x19;
    case 4:
        return 0x25;
    case 2:
    case 7:
        result = 0x29;
        break;
    }
    return result;
}

struct __declspec(align(16)) Vec4A
{
    union
    {
        __m128 quad;
        float f[4];
    };
    Vec4A& operator=(const Vec4A& o)
    {
        _mm_store_ps(f, _mm_load_ps(o.f));
        return *this;
    }
};
struct Shape
{
    int unk00, unk04;
    DDA7C0Geometry* geom;
    int unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int tag;
    int unk54, unk58, unk5c;
    Vec4A vec60;
    int i70, i74, i78, i7c;
    float f80;
    int i84, i88;
    void* GetValue(void* out);
    void* GetVec4At70(void* out);
    void* CopyVec4ToBuffer(void* out);
    void* GetQuad16(void* out);
    void* CopyStatsTo(void* out);
};
struct DDA8C0Writer
{
    void WriteShape(Shape* p);
};
// Writes a Shape to the stream by dispatching on its tag and serializing the tag-specific fields via the writer's hash and write helpers.
// @fnv 0x00dda8c0
void DDA8C0Writer::WriteShape(Shape* p)
{
    Vec4A t[6];
    int tag = p->tag;
    reinterpret_cast<::FUN_00d605b0_class *>(this)->FUN_00d605b0(tag);
    switch (tag)
    {
    case 6: {
        reinterpret_cast<::S_00dda740 *>(this)->WriteTransform((*(const ::S_00dda740_Transform *)(&p->unk10)));
        reinterpret_cast<::DDA7C0OStream *>(this)->WriteGeometry(*p->geom);
        break;
    }
    case 1: {
        reinterpret_cast<::S_00dda740 *>(this)->WriteTransform((*(const ::S_00dda740_Transform *)(&p->unk10)));
        t[0] = p->vec60;
        ::HashUInt((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(p->i70);
        reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(p->i74);
        break;
    }
    case 8: {
        reinterpret_cast<::S_00dda740 *>(this)->WriteTransform((*(const ::S_00dda740_Transform *)(&p->unk10)));
        ::HashUInt((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(p->i84);
        reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(p->i88);
        break;
    }
    case 9: {
        reinterpret_cast<::S_00dda740 *>(this)->WriteTransform((*(const ::S_00dda740_Transform *)(&p->unk10)));
        ::HashUInt((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(p->i84);
        reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(p->i88);
        break;
    }
    case 2: {
        reinterpret_cast<::S_00dda740 *>(this)->WriteTransform((*(const ::S_00dda740_Transform *)(&p->unk10)));
        ::FUN_00dda730((uintptr_t)this);
        break;
    }
    case 3: {
        ::FUN_00dda730((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        break;
    }
    case 4: {
        ::FUN_00dda730((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        ::HashUInt((uintptr_t)this);
        ::HashUInt((uintptr_t)this);
        reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(((intptr_t)(reinterpret_cast<::FUN_00de5360_cls *>((p))->FUN_00de5360())));
        break;
    }
    case 5: {
        ::FUN_00dda730((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        ::HashUInt((uintptr_t)this);
        ::HashUInt((uintptr_t)this);
        ::HashUInt((uintptr_t)this);
        reinterpret_cast<::hkOArchive_2 *>(this)->WriteInt(reinterpret_cast<::FUN_00de4910_cls *>((p))->FUN_00de4910());
        break;
    }
    case 7: {
        ::FUN_00dda730((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        ::FUN_00dda730((uintptr_t)this);
        ::HashUInt((uintptr_t)this);
        break;
    }
    }
}
