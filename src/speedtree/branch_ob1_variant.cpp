#include <cstddef>

// src/speedtree/branch_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/branch.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/branch.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/branch.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cmath>
#include <cstdlib>
#include <cstring>
#include "fnv/decl/CoordinateWriter.h"
#include "fnv/decl/FUN_00b0cf90_class.h"
#include "fnv/decl/FUN_00b12b50_class.h"
#include "fnv/decl/FUN_00b13040_class.h"
#include "fnv/decl/FUN_00b15600_cls.h"
#include "fnv/decl/FUN_00b18320_Class.h"
#include "fnv/decl/FUN_00b30020_Class.h"
#include "fnv/decl/FUN_00b300c0_cls.h"
#include "fnv/decl/FUN_00b30190_shell.h"
#include "fnv/decl/FUN_00b30560_cls.h"
#include "fnv/decl/FUN_00b37ad0_class.h"
#include "fnv/decl/FUN_00b3f130_shell.h"
#include "fnv/decl/FUN_00b404c0_cls.h"
#include "fnv/decl/FrondGuideFinalizer.h"
#include "fnv/decl/FrondPointAppend.h"
#include "fnv/decl/Mat3Rot.h"
#include "fnv/decl/MatrixOwner.h"
#include "fnv/decl/NiD3DHLSLPixelShader.h"
#include "fnv/decl/RandomNumberGenerator.h"
#include "fnv/decl/RotationMatrix.h"
#include "fnv/decl/S00b30660_Obj.h"
#include "fnv/decl/SBranchOwner.h"
#include "fnv/decl/SplineSampler.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/V3cdd0.h"
#include "fnv/decl/addb18__GvOwner.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/decl/fnv_00b13100__Effect.h"
#include "fnv/decl/fnv_00b1fca0__tidyb1f__T1Vector.h"
#include "fnv/decl/fnv_00b305f0__FUN_00b305f0_cls.h"
#include "fnv/decl/fnv_00b30f80__ptb30__PtOwner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00b15000.h"
#include "fnv/symbols_00b16000.h"
#include "fnv/symbols_00b36000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_01066000.h"
#include "fnv/symbols_0108c000.h"
#include "fnv/symbols_010a4000.h"
#include "fnv/symbols_010a5000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011f8000.h"
struct FUN_00b14ae0_class
{
    float FUN_00b14ae0(int id, float a, float b);
};
struct FUN_00b15170
{
    char m_00[0xc];
    char* m_0c;
    char* m_10;
    char* GetElement(unsigned int a);
};
struct NiPoint3
{
    float x, y, z;
};
struct FUN_00b2a180
{
    float a;
    float b;
    float c;
    float Dot(const NiPoint3& point);
};
double __cdecl FUN_00ec6054(double);
struct FUN_00b12790_class
{
    float x, y, z;
    void FUN_00b12790();
};
struct FUN_00b0cff0_class
{
    float x;
    float y;
    float z;
    NiPoint3* ScaleSwizzled(NiPoint3* output, float factor);
};
extern double __cdecl FUN_00eca190(double value);
struct This : FUN_00b2a180
{
    float FUN_00b12720(const NiPoint3& point);
};
struct State
{
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
    float threshold;
    float upper;
    int count;
};
struct GlobalObject_00b3f100
{
};
struct Link
{
    Link* next;
    float value;
};
struct Owner
{
    bool FUN_00b13b50(Link* link, float input);
};
struct B4230Point3
{
    float x;
    float y;
    float z;

    float FastSqrt() const;
};
// FUN_00b14b10 - blends the first argument towards zero by the second one
// (value - value * factor).  The double literal 0.0 is what makes MSVC 2008
// build the x87 register-to-register multiply instead of the memory-operand one.
struct FUN_00b14b10_class
{
    float FUN_00b14b10(float value, float factor);
};
struct b14_sub
{
    float x, y, z;
};
struct b14_elem
{
    char unk00[0xc];
    b14_sub sub;
    float unk18;
    char unk1c[0x2c];
};
struct b14_ctx
{
    char unk00[0x20];
    b14_elem* unk20;
    int unk24;
    char unk28[8];
    float unk30;
    void FUN_00b14b40();
};
struct FUN_00b14be0_cls;
struct SegmentEntry
{
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
    int unk34;
    int unk38;
    int unk3c;
    float f40;
    int unk44;
};
struct OutPair
{
    int idx;
    float t;
};
struct FUN_00b14be0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SegmentEntry* m_20;
    int m_24;
    void FindSegment(OutPair* out, float v);
};
// Stand-in for the game's vector type: three floats plus the vector helpers
// the original calls (difference, normalisation, scaling, sum and dot product).
struct Vec
{
    float x, y, z;
                             // normalise in place
       // *out = *this - *p
      // *out = *this * factor
      // *out = *this + *other
    float Dot(const Vec& p);
};
// The class that owns ProjectOntoLine (in the game it derives from the vector
// class, so `this` points at the three floats a, b and c).
struct MyThis
{
    float a, b, c;
    Vec* ProjectOntoLine(Vec* out, Vec* a, Vec* b, Vec* c);
};
struct NiPoint3x
{
    float x, y, z;
};
struct S_00b14280_Entry
{
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    float m_ucLowNibble;
    float m_ucHighNibble;
    int unk50;
};
struct S_00b14280_Entries
{
    int unk00;
    int unk04;
    int unk08;
    S_00b14280_Entry* m_pRayStart;
    S_00b14280_Entry* m_kRayEnd;
};
struct S_00b14280_Obj
{
    int unk00;
    NiPoint3x m_pos;
};
struct S_00b14280_List
{
    int unk00;
    int unk04;
    int unk08;
    S_00b14280_Obj** m_pRayStart;
    S_00b14280_Obj** m_kRayEnd;
};
struct S_00b14280_State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00b14280_Entries m_entries;
    int unk24;
    float m_threshold;
};
struct S_00b14280_This
{
    bool IsPointClearOfEntries(const NiPoint3x& pt, unsigned int index, S_00b14280_List* list);
};

struct Pt3
{
    float x, y, z;
    Pt3()
    {}
    Pt3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
};
struct CrossPt
{
    float x, y, z;
    Pt3 FUN_00b12810(const Pt3& pt) const;
};
// @fnv 0x00b12810
Pt3 CrossPt::FUN_00b12810(const Pt3& pt) const
{
    return Pt3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
}

extern int __cdecl FUN_00ecadb8();
inline float __cdecl FUN_00b14e90(float lower, float upper)
{
    float fraction = FUN_00ecadb8() / ::DAT_01029790;
    float range = upper - lower;
    return fraction * range + lower;
}

inline float radians(float degrees)
{
    return degrees / DAT_010a4d90;
}

struct CreationValues
{
    float angle;
    float spread;
    float forward;
    float vertical;
    float magnitude;
    float sideways;
};

struct CreationValuesVector;
struct IteratorProxy
{
    CreationValuesVector* container;
};
struct OutputIterator
{
    IteratorProxy* owner;
    CreationValues* position;
    OutputIterator(CreationValues* ptr, CreationValuesVector* object);
    int operator-(const OutputIterator& other) const
    {
        if (!owner || owner != other.owner)
            std::abort();
        return position - other.position;
    }
    OutputIterator& operator+=(int offset);
    OutputIterator operator+(int offset) const
    {
        OutputIterator copy = *this;
        copy += offset;
        return copy;
    }
};
struct CreationValuesVector
{
    IteratorProxy* owner;
    int unk04;
    int allocator;
    CreationValues* first;
    CreationValues* last;
    CreationValues* limit;
    unsigned size() const
    {
        return last - first;
    }
    unsigned capacity() const
    {
        return first ? limit - first : 0;
    }
    static void construct(CreationValues* dest, const CreationValues& value, int* alloc)
    {
        *dest = value;
    }
    static void fill(CreationValues* dest, unsigned count, const CreationValues& value, int* alloc)
    {
        CreationValues* finish = dest + count;
        for (; dest != finish; ++dest)
            construct(dest, value, alloc);
    }
    void insert_many(OutputIterator, unsigned, const CreationValues&);
    OutputIterator begin()
    {
        return OutputIterator(first, this);
    }
    OutputIterator end()
    {
        return OutputIterator(last, this);
    }
    OutputIterator insert(OutputIterator where, const CreationValues& value)
    {
        int offset = size() == 0 ? 0 : where - begin();
        insert_many(where, 1, value);
        return begin() + offset;
    }
    void FUN_00b15280(CreationValues* values)
    {
        unsigned used = size();
        if (used < capacity())
        {
            fill(last, 1, *values, &allocator);
            ++last;
        }
        else
        {
            insert(end(), *values);
        }
    }
};
inline OutputIterator::OutputIterator(CreationValues* ptr, CreationValuesVector* object) : owner(0), position(ptr)
{
    if (!object || ptr < object->first || ptr > object->last)
        std::abort();
    owner = object->owner;
}

inline OutputIterator& OutputIterator::operator+=(int offset)
{
    IteratorProxy* proxy = owner;
    CreationValuesVector* container = proxy ? proxy->container : 0;
    if (!container)
        std::abort();
    CreationValues* candidate = position + offset;
    CreationValues* lower = container->first;
    CreationValues* upper = container->last;
    if (candidate < lower || candidate > upper)
        std::abort();
    position = candidate;
    return *this;
}

struct CreationSettings
{
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
    int count;
    float interval;
    float spread;
    float deviation;
    float forward;
    float tilt;
    float sideways;
    float vertical;
    float verticalRange;
    float verticalDeviation;
};

struct ParticleEmitter
{
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
    int unk34;
    CreationValuesVector channel;
    void FUN_00b14ca0(CreationSettings* settings);
};

// @fnv 0x00b14ca0
void ParticleEmitter::FUN_00b14ca0(CreationSettings* settings)
{
    if (settings->count != 0)
    {
        float initial = FUN_00b14e90(0.0f, runtimeInitializationFloat4160);
        float perStep = runtimeInitializationFloat4160 / (float)settings->count;
        for (int i = 0; i < settings->count; ++i)
        {
            CreationValues values = {0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
            values.angle = (float)i * FUN_00b14e90(settings->interval * perStep, perStep) + initial;
            if (values.angle > runtimeInitializationFloat4160)
                values.angle -= runtimeInitializationFloat4160;
            values.forward = settings->forward;
            values.magnitude = settings->verticalDeviation;
            values.spread =
                radians(FUN_00b14e90(settings->spread - settings->deviation, settings->spread + settings->deviation));
            values.vertical = FUN_00b14e90(settings->vertical - settings->verticalRange,
                                           settings->vertical + settings->verticalRange);
            values.sideways = FUN_00b14e90(settings->tilt - settings->sideways, settings->tilt + settings->sideways);
            channel.FUN_00b15280(&values);
        }
    }
}

// Stand-in for the game class whose member function lives at 0x00b151a0.
//
// The original is an UNOPTIMISED (/Od) member function with an /EHsc frame:
//
//   push ebp / mov ebp,esp
//   push -1 / push __ehhandler$ / mov eax,fs:[0] / push eax
//   sub esp,0x28
//   mov eax,[__security_cookie] / xor eax,ebp / push eax
//   lea eax,[ebp-0xc] / mov fs:[0],eax
//   mov dword ptr [ebp-0x34],ecx      <- the `this` home
//   mov dword ptr [ebp-4],0           <- EH state: the cleanup action is armed
//   mov ecx,dword ptr [ebp-0x34]
//   call <member>                     <- the only call into the class
//   mov dword ptr [ebp-4],-1          <- EH state: the cleanup action is disarmed
//   mov eax,dword ptr [ebp-0x34]
//   mov ecx,dword ptr [eax]           <- this->m_p00
//   mov dword ptr [ebp-0x30],ecx      <- a named local copy of that pointer
//   mov edx,dword ptr [ebp-0x30]
//   push edx / call operator delete
//
// The cleanup action belongs to a 32-byte local whose destructor is defined in
// the class body and is EMPTY.  With the front end's class-body expansion
// (/Ob1 or /Ob2 - plain /Od turns the inliner off completely) that destructor
// is expanded in place and produces NO code at all, so only the two EH state
// stores survive; the local's frame slot (32 bytes) still reserves the space
// that makes the frame 0x28 bytes long.
//
// The frame layout under /Od is: named locals (declaration order) first, then
// the implicit `this` home at the bottom of the frame, so the pointer local has
// to live in an inner block to end up directly above `this` at [ebp-0x30].
void __cdecl operator delete(void* p);

struct FNV_scratch_t
{
    ~FNV_scratch_t()
    {}
    int a00, a04, a08, a0c, a10, a14, a18, a1c;
};

struct FUN_00b151a0_class
{
    void* m_p00;
    void FUN_00b151a0();
};

// @fnv 0x00b151a0
void FUN_00b151a0_class::FUN_00b151a0()
{
    {
        FNV_scratch_t tmp;
        reinterpret_cast<::fnv_00b1fca0::tidyb1f::T1Vector *>((this))->FUN_00b1fca0();
    }
    {
        void* q = this->m_p00;
        ::FUN_00401030(q);
    }
}

extern double __cdecl FUN_00eca190(double);
extern float DAT_010a54a0, DAT_010a549c, DAT_010a5498;
inline float BranchPower(float a, float b)
{
    return (float)(double)(float)std::pow(a, b);
}
inline float BranchAbsolute(float a)
{
    return ((float)std::fabs((double)a));
}
inline float BranchFalloff(float p)
{
    return 1.0f - DAT_010a5498 * p;
}
inline float BranchInterpolate(float a, float b, float t)
{
    return a + (b - a) * t;
}
inline float BranchDegrees(float a)
{
    return a * DAT_010a4d90;
}
struct BranchMatrix;
struct BranchPoint
{
    float x, y, z;
    BranchPoint()
    {}
    BranchPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    void FUN_00b12790()
    {
        float magnitude = x * x + y * y + z * z;
        float inverse = 1.0f / (float)FUN_00ec6054(magnitude);
        x *= inverse;
        y *= inverse;
        z *= inverse;
    }
    float Dot(const BranchPoint& p)
    {
        return x * p.x + y * p.y + z * p.z;
    }
    float FUN_00b12720(const BranchPoint& p)
    {
        float dot = Dot(p);
        if (dot < -1.0)
            dot = -1.0f;
        if (dot > 1.0)
            dot = 1.0f;
        return (float)FUN_00eca190(dot);
    }
    BranchPoint FUN_00b12810(const BranchPoint& p)
    {
        return BranchPoint(p.y * z - p.z * y, p.z * x - p.x * z, p.x * y - p.y * x);
    }
    BranchPoint operator*(float f) const
    {
        float qqtISP = f * x;
        float qIpA = f * y;
        float qXMUYT = f * z;
        return BranchPoint(qqtISP, qIpA, qXMUYT);
    }
    BranchPoint operator-(const BranchPoint& p) const
    {
        float a = x - p.x;
        float b = y - p.y;
        float c = z - p.z;
        return BranchPoint(a, b, c);
    }
    __forceinline BranchPoint operator+(const BranchPoint& p) const
    {
        float qqtISP = p.x + x;
        float qIpA = p.y + y;
        float qXMUYT = p.z + z;
        return BranchPoint(qqtISP, qIpA, qXMUYT);
    }
};
struct BranchMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    BranchMatrix()
    {
        m00 = 1.0f;
        m01 = 0.0f;
        m02 = 0.0f;
        m10 = 0.0f;
        m11 = 1.0f;
        m12 = 0.0f;
        m20 = 0.0f;
        m21 = 0.0f;
        m22 = 1.0f;
    }
    BranchMatrix(float a, float b, float c, float d, float e, float f, float g, float h, float i)
        : m00(a), m01(b), m02(c), m10(d), m11(e), m12(f), m20(g), m21(h), m22(i)
    {}
    BranchPoint TransformVector(const BranchPoint& p) const
    {
        return BranchPoint(p.z * m02 + (p.y * m01 + p.x * m00), p.z * m12 + (p.y * m11 + p.x * m10),
                           p.z * m22 + (p.y * m21 + p.x * m20));
    }
    inline void FUN_00b12d50(float, BranchPoint);
    inline void FUN_00b12c00(float, float);
    inline void SetRotationAxisAngle(float, BranchPoint);
    inline BranchMatrix Multiply(const BranchMatrix&);
};
struct BranchCurve
{
};
struct BranchCurvePtr
{
    BranchCurve* ptr;
    BranchCurve* operator->() const
    {
        return ptr;
    }
};
struct BranchConfig
{
    int sides, segments;
    float lower, upper, children, width, height;
    bool fixedWidth, fixedHeight, animate;
    char unk1f;
    float twist, exponent;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    BranchCurvePtr orientation, bend, material, variation, length, thickness, radius, base, noise;
};
struct BranchMesh
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    float diameter, start;
    unsigned short unk20, vertices, unk24, groups;
    unsigned short GetVertices() const
    {
        return vertices;
    }
    void SetVertices(unsigned short n)
    {
        vertices = n;
    }
    void SetDiameter(float f)
    {
        diameter = f;
    }
    void SetStart(float f)
    {
        start = f;
    }
};
struct FUN_00b130a0
{
    BranchPoint direction, position;
    float radius;
    BranchMatrix matrix;
    float distance, weight;
    FUN_00b130a0()
    {
        direction.x = direction.y = direction.z = 0.0f;
        BranchPoint* point = &position;
        point->x = point->y = point->z = 0.0f;
    }
};
struct BranchRandom
{
};
extern BranchPoint DAT_011f8c08;
struct BranchTransform
{
    float x, y, z;
    BranchPoint FUN_00b12890(const BranchMatrix& a)
    {
        return BranchPoint(a.m20 * z + (a.m10 * y + a.m00 * x), a.m21 * z + (a.m11 * y + a.m01 * x),
                           a.m22 * z + (a.m12 * y + a.m02 * x));
    }
};
struct BranchManager
{
};
extern BranchConfig** DAT_011f8c5c;
extern BranchConfig** DAT_011f8c60;
struct BranchConfigList
{
    int unk00, unk04, unk08;
    BranchConfig** begin;
    BranchConfig** end;
    BranchConfig** capacity;
    BranchConfig*& GetElement(unsigned int index)
    {
        if (index >= (unsigned int)(end - begin))
            std::abort();
        return begin[index];
    }
};
extern float DAT_010a54a0, DAT_010a549c, DAT_010a5498;
extern float DAT_010a54a0, DAT_010a549c, DAT_010a5498;
struct FUN_00b10dc0;
struct BranchChild
{
    int idx;
    float t;
    FUN_00b10dc0* object;
};
struct BranchChildren;
struct BranchIterator
{
    int proxy;
    BranchChild* position;
    BranchIterator(BranchChild* p, BranchChildren* v);
    BranchIterator operator+(int offset) const
    {
        BranchIterator copy = *this;
        copy.position += offset;
        return copy;
    }
    int operator-(const BranchIterator& other) const
    {
        if (!proxy || proxy != other.proxy)
            std::abort();
        return position - other.position;
    }
};
struct BranchTag
{
};
BranchChild* __cdecl FUN_00b244a0(BranchChild*, unsigned int, const BranchChild&, int*, BranchTag, bool);
struct BranchChildren
{
    int unk00, unk04, unk08;
    BranchChild* begin;
    BranchChild* end;
    BranchChild* capacity;
    unsigned int size() const
    {
        return end - begin;
    }
    unsigned int allocated() const
    {
        return begin ? capacity - begin : 0;
    }
    BranchIterator Begin()
    {
        return BranchIterator(begin, this);
    }
    BranchIterator End()
    {
        return BranchIterator(end, this);
    }
    void FUN_00b21e00(BranchIterator, unsigned int, const BranchChild&);
    BranchIterator FUN_00b1fab0(BranchIterator where, const BranchChild& value)
    {
        int offset = size() == 0 ? 0 : where - Begin();
        FUN_00b21e00(where, 1, value);
        return Begin() + offset;
    }
    void FUN_00b1e4c0(const BranchChild& value)
    {
        int qPad[32];
        if (size() < allocated())
        {
            BranchChild* oldEnd = end;
            BranchTag tag;
            FUN_00b244a0(oldEnd, 1, value, &unk08, tag, false);
            end = oldEnd + 1;
        }
        else
            FUN_00b1fab0(End(), value);
    }
};
inline BranchIterator::BranchIterator(BranchChild* p, BranchChildren* v) : proxy(0), position(p)
{
    if (!v || v->begin > p || p > v->end)
        std::abort();
    proxy = v->unk00;
}
struct BranchLeaves
{
};
inline BranchPoint* __cdecl FUN_00b13000(BranchPoint* out, const BranchPoint* a, const BranchPoint* b, float t)
{
    float dx = b->x - a->x, dy = b->y - a->y, dz = b->z - a->z;
    float sx = dx * t, sy = dy * t, sz = dz * t;
    float rx = a->x + sx, ry = a->y + sy, rz = a->z + sz;
    out->x = rx;
    out->y = ry;
    out->z = rz;
    return out;
}
struct FUN_00b10dc0
{
    int unk00;
    float time;
    BranchChildren childList;
    FUN_00b130a0* entries;
    int entryCount;
    unsigned short type, unk2a;
    unsigned int firstVertex;
    float unk30;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    FUN_00b10dc0(FUN_00b10dc0*);
    ~FUN_00b10dc0();
    void FUN_00b14ed0(BranchMesh*, unsigned short);
    void FUN_00b11050(unsigned int, float, int, const BranchPoint&, float, float, const BranchMatrix&,
                      const BranchPoint&, BranchMesh*, void*, float, unsigned int, float);
};
inline BranchMatrix BranchMatrix::Multiply(const BranchMatrix& a)
{
    BranchMatrix result;
    result.m00 = m00 * a.m00 + m01 * a.m10 + m02 * a.m20;
    result.m01 = m00 * a.m01 + m01 * a.m11 + m02 * a.m21;
    result.m02 = m00 * a.m02 + m01 * a.m12 + m02 * a.m22;
    result.m10 = m10 * a.m00 + m11 * a.m10 + m12 * a.m20;
    result.m11 = m10 * a.m01 + m11 * a.m11 + m12 * a.m21;
    result.m12 = m10 * a.m02 + m11 * a.m12 + m12 * a.m22;
    result.m20 = m20 * a.m00 + m21 * a.m10 + m22 * a.m20;
    result.m21 = m20 * a.m01 + m21 * a.m11 + m22 * a.m21;
    result.m22 = m20 * a.m02 + m21 * a.m12 + m22 * a.m22;
    return result;
}
inline void BranchMatrix::SetRotationAxisAngle(float angle, BranchPoint axis)
{
    float sine = (float)std::sin((float)(angle / DAT_010a4d90));
    float cosine = (float)std::cos((float)(angle / DAT_010a4d90));
    float complement = 1.0f - cosine;
    float x = axis.x, y = axis.y, z = axis.z;
    m00 = complement * x * x + cosine;
    m01 = complement * x * y + sine * z;
    m02 = complement * x * z - sine * y;
    m10 = complement * x * y - sine * z;
    m11 = complement * y * y + cosine;
    m12 = complement * y * z + sine * x;
    m20 = complement * x * z + sine * y;
    m21 = complement * y * z - sine * x;
    m22 = complement * z * z + cosine;
}
inline void BranchMatrix::FUN_00b12d50(float angle, BranchPoint axis)
{
    BranchMatrix rotation;
    float sine = (float)std::sin((float)(angle / DAT_010a4d90));
    float cosine = (float)std::cos((float)(angle / DAT_010a4d90));
    float complement = 1.0f - cosine;
    float x = axis.x, y = axis.y, z = axis.z;
    rotation.m00 = complement * x * x + cosine;
    rotation.m01 = complement * x * y + sine * z;
    rotation.m02 = complement * x * z - sine * y;
    rotation.m10 = complement * x * y - sine * z;
    rotation.m11 = complement * y * y + cosine;
    rotation.m12 = complement * y * z + sine * x;
    rotation.m20 = complement * x * z + sine * y;
    rotation.m21 = complement * y * z - sine * x;
    rotation.m22 = complement * z * z + cosine;
    *this = rotation.Multiply(*this);
}
inline void BranchMatrix::FUN_00b12c00(float first, float second)
{
    BranchMatrix rotation;
    float c1 = (float)std::cos((float)(first / DAT_010a4d90));
    float s1 = (float)std::sin((float)(first / DAT_010a4d90));
    float c2 = (float)std::cos((float)(second / DAT_010a4d90));
    float s2 = (float)std::sin((float)(second / DAT_010a4d90));
    rotation.m00 = c1 * c2;
    rotation.m01 = c1 * s2;
    rotation.m02 = -s1;
    rotation.m10 = -s2;
    rotation.m11 = c2;
    rotation.m12 = 0.0f;
    rotation.m20 = s1 * c2;
    rotation.m21 = s1 * s2;
    rotation.m22 = c1;
    *this = rotation.Multiply(*this);
}
struct S_00b13a40_Elem
{
    unsigned char m_flag;
};


struct S_00b13a40_Vec
{
    int unk00;
    int unk04;
    int unk08;
    char* m_pRayStart;
    char* m_kRayEnd;

    unsigned int Size() const
    {
        return (m_kRayEnd - m_pRayStart) / 0x54;
    }
    S_00b13a40_Elem& At(unsigned int i)
    {
        if (i >= Size())
        {
            std::abort();
        }
        return *(S_00b13a40_Elem*)(m_pRayStart + i * 0x54);
    }
};

struct S_00b13a40_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00b13a40_Vec m_vec;
};

struct IndexSet;
struct IndexAllocator
{
};
struct ScalarIteratorTag
{
};
struct RangeIteratorTag
{
};
inline ScalarIteratorTag pointer_category(unsigned*&, unsigned*&)
{
    ScalarIteratorTag category;
    return category;
}
struct InputIteratorTag
{
};
struct ForwardIteratorTag : InputIteratorTag
{
};
struct BidirectionalIteratorTag : ForwardIteratorTag
{
};
struct RandomIteratorTag : BidirectionalIteratorTag
{
};
inline RandomIteratorTag iterator_category(unsigned* const&)
{
    RandomIteratorTag category;
    return category;
}
inline void fill_loop(unsigned* first, unsigned count, const unsigned& value, RangeIteratorTag)
{
    for (; 0 < count; --count, ++first)
        *first = value;
}
inline void fill_dispatch(unsigned* first, unsigned count, const unsigned& value, RandomIteratorTag, RangeIteratorTag)
{
    fill_loop(first, count, value, RangeIteratorTag());
}
inline void unchecked_fill(unsigned* first, unsigned count, const unsigned& value)
{
    fill_dispatch(first, count, value, iterator_category(first), RangeIteratorTag());
}
inline void scalar_uninitialized_fill(unsigned* first, unsigned count, const unsigned& value, IndexAllocator&,
                                      ScalarIteratorTag, RangeIteratorTag)
{
    unchecked_fill(first, count, value);
}
inline void unchecked_uninitialized_fill(unsigned* first, unsigned count, const unsigned& value, IndexAllocator& alloc)
{
    scalar_uninitialized_fill(first, count, value, alloc, pointer_category(first, first), RangeIteratorTag());
}
struct IndexProxy
{
    IndexSet* container;
    IndexSet* get_container() const
    {
        return container;
    }
};
struct IndexIteratorBase
{
    IndexProxy* owner;
    IndexIteratorBase() : owner(0)
    {}
    void set_container(IndexSet* object);
    IndexSet* get_container() const
    {
        return owner ? owner->get_container() : 0;
    }
    bool has_container() const
    {
        return owner != 0;
    }
    bool same_container(const IndexIteratorBase& other) const
    {
        return owner == other.owner;
    }
};
struct ConstIndexIterator : IndexIteratorBase
{
    unsigned* position;
    ConstIndexIterator(unsigned* ptr, IndexSet* object);
    int operator-(const ConstIndexIterator& other) const
    {
        {
            if (!(owner != 0 && same_container(other)))
            {
                {
                    std::abort();
                }
            }
        }
        return position - other.position;
    }
    ConstIndexIterator& operator+=(int offset);
};
struct IndexIterator : ConstIndexIterator
{
    IndexIterator(unsigned* ptr, IndexSet* object) : ConstIndexIterator(ptr, object)
    {}
    IndexIterator& operator+=(int offset)
    {
        (*(ConstIndexIterator*)this) += offset;
        return *this;
    }
    IndexIterator operator+(int offset) const
    {
        IndexIterator copy = *this;
        return copy += offset;
    }
};
struct IndexValues
{
    IndexProxy* owner;
    int unk04;
    IndexAllocator allocator;
};
struct IndexSet : IndexValues
{
    unsigned* first;
    unsigned* last;
    unsigned* limit;
    unsigned size() const
    {
        return last - first;
    }
    unsigned capacity() const
    {
        return first == 0 ? 0 : limit - first;
    }
    unsigned* fill(unsigned* dest, unsigned count, const unsigned& value)
    {
        unsigned* finish = dest + count;
        unchecked_uninitialized_fill(dest, count, value, allocator);
        return finish;
    }
    void insert_many(ConstIndexIterator, unsigned, const unsigned&);
    IndexIterator begin()
    {
        return IndexIterator(first, this);
    }
    IndexIterator end()
    {
        return IndexIterator(last, this);
    }
    IndexIterator erase(ConstIndexIterator, ConstIndexIterator);
    IndexIterator insert(ConstIndexIterator where, const unsigned& value)
    {
        unsigned offset = size() == 0 ? 0 : where - begin();
        insert_many(where, 1, value);
        return begin() + offset;
    }
    void FUN_00b32350()
    {
        erase(begin(), end());
    }
    void FUN_00b15390(const unsigned& value)
    {
        if (size() < capacity())
        {
            last = fill(last, 1, value);
        }
        else
        {
            insert(end(), value);
        }
    }
};
inline void IndexIteratorBase::set_container(IndexSet* object)
{
    owner = object->owner;
}
inline ConstIndexIterator::ConstIndexIterator(unsigned* ptr, IndexSet* object)
{
    {
        if (!(object != 0 && object->first <= ptr && ptr <= object->last))
        {
            {
                std::abort();
            }
        }
    }
    set_container(object);
    position = ptr;
}
inline ConstIndexIterator& ConstIndexIterator::operator+=(int offset)
{
    {
        if (!(has_container()))
        {
            {
                std::abort();
            }
        }
    }
    {
        if (!(position + offset <= get_container()->last && position + offset >= get_container()->first))
        {
            {
                std::abort();
            }
        }
    }
    position += offset;
    return *this;
}
extern IndexSet DAT_011f8c68;
extern IndexSet DAT_011f8c18;

struct S_00b13a40_Obj
{
    void FUN_00b13a40();
};

// @fnv 0x00b13a40
void S_00b13a40_Obj::FUN_00b13a40()
{
    DAT_011f8c68.FUN_00b32350();
    DAT_011f8c18.FUN_00b32350();
    for (unsigned int i = 0; i < ((S_00b13a40_Holder*)DAT_011f8bf4)->m_vec.Size(); i++)
    {
        if (((S_00b13a40_Holder*)DAT_011f8bf4)->m_vec.At(i).m_flag)
        {
            DAT_011f8c68.FUN_00b15390(i * 2);
            DAT_011f8c68.FUN_00b15390(i * 2 + 1);
        }
        else
        {
            DAT_011f8c18.FUN_00b15390(i * 2);
            DAT_011f8c18.FUN_00b15390(i * 2 + 1);
        }
    }
}

namespace fnv_00b13c10 {
// FUN_00b13c10 v1 - worker20 full transcription (from worker2 v1 head + tail blocks 5-8)
struct Vec54
{
    int m_00;
    int m_04;
    int m_08;
    char* m_0c;
    char* m_10;
    inline unsigned size()
    {
        return (m_10 - m_0c) / 0x54;
    }
    inline bool empty()
    {
        return size() == 0;
    }
    inline void* at(unsigned index)
    {
        if (index >= size())
            std::abort();
        return m_0c + index * 0x54;
    }
};
struct Obj80
{
};
struct Elem54
{
    int m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    char m_40;
    char m_41;
    short m_42;
    int m_44;
    float m_48;
    float m_4c;
    int m_50;
};
struct ResObj
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    NiPoint3 m_1c;
    NiPoint3 m_28;
    NiPoint3 m_34;
    char m_40;
    char m_41;
    short m_42;
    int m_44;
    int m_48;
    inline void setId(int id)
    {
        m_40 = (char)id;
    }
    inline void setA(const NiPoint3& pT)
    {
        m_1c = pT;
    }
    inline void setB(const NiPoint3& pT)
    {
        m_28 = pT;
    }
    inline void setC(const NiPoint3& pT)
    {
        m_34 = pT;
    }
};
struct FUN_00b40070 : ResObj
{
    FUN_00b40070(int a, int b, int c);
};
struct ResHolder
{
    ResObj* ptr;
    ~ResHolder();
};
struct MathPoint : NiPoint3
{
    inline float FastSqrt()
    {
        float sum = z * z + y * y + x * x;
        union Bits
        {
            float f;
            int i;
        } approx;
        approx.i = 0x1fc00000 + (((Bits*)&sum)->i >> 1);
        return approx.f;
    }
    inline void FUN_00b12790()
    {
        float sum = x * x + y * y + z * z;
        float scale = 1.0f / (float)FUN_00ec6054(sum);
        x *= scale;
        y *= scale;
        z *= scale;
    }
    MathPoint FUN_00b13040(const MathPoint& p);
    MathPoint ScaleSwizzled(float f);
};
struct CrossObj
{
    float x, y, z;
    inline void FUN_00b12810(NiPoint3* out, NiPoint3* p)
    {
        float a = y * p->z - z * p->y;
        float b = z * p->x - x * p->z;
        float c = x * p->y - y * p->x;
        out->x = a;
        out->y = b;
        out->z = c;
    }
};
struct G4Obj
{
};
struct Host : Owner
{
    inline bool IsPointClearOfEntries(int a, int b, void* c);
    void FUN_00b13c10(int p0, float p1, Link* p2, MathPoint* p3, MathPoint* p4, float p5, int p6, void* p7);
};
struct IndexList
{
    int* begin;
    int* end;
    inline unsigned size() const
    {
        return end - begin;
    }
    inline bool empty() const
    {
        return size() == 0;
    }
    inline int at(unsigned index)
    {
        if (index >= size())
            std::abort();
        return begin[index];
    }
};
extern int* DAT_011f8c74;
extern int* DAT_011f8c78;
extern int* DAT_011f8c24;
extern int* DAT_011f8c28;
inline unsigned sizeA()
{
    return DAT_011f8c78 - DAT_011f8c74;
}
inline unsigned sizeB()
{
    return DAT_011f8c28 - DAT_011f8c24;
}
inline bool emptyA()
{
    return sizeA() == 0;
}
inline bool emptyB()
{
    return sizeB() == 0;
}
inline int atB(unsigned i)
{
    if (i >= sizeB())
        std::abort();
    return i[DAT_011f8c24];
}
struct IntVecG
{
    int unk00;
    int* _Myfirst;
    int* _Mylast;
    int* _Myend;
    inline unsigned size() const
    {
        return _Mylast - _Myfirst;
    }
    inline int& operator[](unsigned _Pos)
    {
        if (!(_Pos < size()))
            std::abort();
        return *(_Myfirst + _Pos);
    }
};
extern IntVecG DAT_011f8c70;
extern IntVecG DAT_011f8c20;

struct LocalPoint : NiPoint3
{
    inline LocalPoint(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};
inline MathPoint interpolate(MathPoint* a, MathPoint* b, float f)
{
    return (*(::fnv_00b13c10::MathPoint *)(reinterpret_cast<::FUN_00b0cf90_class *>((b))->AddVector((float *)&(const ::fnv_00b13c10::MathPoint &)(a->FUN_00b13040(*b).ScaleSwizzled(f)), {})));
}
struct Settings
{
    bool enabled;
    float factor;
    int unk08;
    int mode;
    Vec54 elements;
    int unk24;
    float unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int count;
};
struct ObjectRef
{
    ResObj* ptr;
    inline ResObj* operator->()
    {
        return ptr;
    }
};
struct ReferenceListNode
{
    int unk00, unk04, unk08;
    ObjectRef* begin;
    ObjectRef* end;
    inline unsigned size()
    {
        return end - begin;
    }
    inline ObjectRef& at(unsigned i)
    {
        if (i >= size())
            std::abort();
        return begin[i];
    }
};
inline bool Host::IsPointClearOfEntries(int a, int b, void* c)
{
    bool allowed = true;
    if (!((Vec54*)&DAT_011f8bf4->unk10)->empty())
    {
        Elem54* e = (Elem54*)((Vec54*)&DAT_011f8bf4->unk10)->at(b);
        float radius = e->m_48 > e->m_4c ? e->m_48 : e->m_4c;
        radius *= ((Settings*)DAT_011f8bf4)->unk28;
        for (unsigned i = 0; i < ((ReferenceListNode*)c)->size() && allowed; ++i)
        {
            NiPoint3* pos = (NiPoint3*)&((ReferenceListNode*)c)->at(i)->m_04;
            if (((NiPoint3*)a)->x < pos->x + radius && ((NiPoint3*)a)->x > pos->x - radius &&
                ((NiPoint3*)a)->y < pos->y + radius && ((NiPoint3*)a)->y > pos->y - radius &&
                ((NiPoint3*)a)->z < pos->z + radius && ((NiPoint3*)a)->z > pos->z - radius)
                allowed = false;
        }
    }
    else
        allowed = false;
    return allowed;
}
// @fnv 0x00b13c10
void Host::FUN_00b13c10(int p0, float p1, Link* p2, MathPoint* p3, MathPoint* p4, float p5, int p6, void* p7)
{
    if (!((Vec54*)&DAT_011f8bf4->unk10)->empty())
    {
        int id = 0;
        bool flag20 = emptyA() ? false : FUN_00b13b50(p2, p1);
        if (flag20)
        {
            unsigned idx = 0;
            if (sizeA() > 1)
            {
                idx = (int)((unsigned int)reinterpret_cast<::FUN_00b3f130_shell *>(&(::g_011f8c05))->FUN_00b3f130(0.0f, ::DAT_01017130) % sizeA());
            }
            id = DAT_011f8c70[idx];
        }
        else
        {
            unsigned idx = 0;
            if (sizeB() > 1)
            {
                float fr = reinterpret_cast<::FUN_00b3f130_shell *>(&(::g_011f8c05))->FUN_00b3f130(0.0f, ::DAT_0108cb00);
                idx = (int)((unsigned int)fr % sizeB());
                id = DAT_011f8c20[idx];
            }
            else
            {
                if (emptyB())
                    return;
                else
                {
                    id = DAT_011f8c20[0];
                }
            }
        }
        bool ok = true;
        switch (DAT_011f8bf4->unk0c)
        {
        default:
            break;
            break;
        case 1:
            ok = reinterpret_cast<::S_00b14280_This *>(this)->IsPointClearOfEntries((*(const ::NiPoint3x *)(p0)), id / 2, (::S_00b14280_List *)(void *)(&(*reinterpret_cast<::fnv_00b13c10::Obj80 *>(&::DAT_011f8c80))));
            break;
        case 2:
            ok = reinterpret_cast<::S_00b14280_This *>(this)->IsPointClearOfEntries((*(const ::NiPoint3x *)(p0)), id / 2, (::S_00b14280_List *)(p7));
            break;
        }
    switchDone:
        if (ok)
        {
            float scale7 = 1.0f;
            float vZ = p1;
            if (((Settings*)DAT_011f8bf4)->enabled != 0)
            {
                vZ = ::FUN_00b15110((::Link *)((int)p2));
                vZ = vZ + (1.0f - vZ) * p1;
                vZ = vZ * vZ * vZ;
                scale7 = (float)(1.0 - ((Settings*)DAT_011f8bf4)->factor) * (1.0f - vZ) + vZ;
            }
            ResObj* res = new FUN_00b40070(p0, (unsigned short)(int)(scale7 * 255.0),
                                           (int)reinterpret_cast<::FUN_00b3f130_shell *>((((G4Obj*)&::g_011f8c05)))->FUN_00b3f130(0.0f, ::DAT_01022958) %
                                               ((Settings*)DAT_011f8bf4)->count);
            reinterpret_cast<::IndexSet *>((((Obj80*)p7)))->FUN_00b15390((*(const unsigned int *)(&res)));
            if (DAT_011f8bf4->unk0c == 1)
            {
                reinterpret_cast<::IndexSet *>(&((*reinterpret_cast<::fnv_00b13c10::Obj80 *>(&::DAT_011f8c80))))->FUN_00b15390((*(const unsigned int *)(&res)));
            }
            Elem54* elem4 = (Elem54*)((Vec54*)&DAT_011f8bf4->unk10)->at(id / 2);
            res->setId(id);
            NiPoint3 pT;
            pT.z = 0.0f;
            pT.y = 0.0f;
            pT.x = 0.0f;
            if (reinterpret_cast<::B4230Point3 *>((p3))->FastSqrt() < ::DAT_01030f28)
            {
                pT = *p4;
            }
            else
            {
                pT = interpolate(p3, p4, elem4->m_10);
            }
            reinterpret_cast<::FUN_00b12790_class *>((((MathPoint*)&pT)))->FUN_00b12790();
            res->setA(pT);
            NiPoint3 varCX = pT;
            res->setB(varCX);
            NiPoint3 cross2;
            reinterpret_cast<::CrossPt *>((((CrossObj*)&varCX)))->FUN_00b12810((*(const ::Pt3 *)(&cross2)));
            reinterpret_cast<::FUN_00b12790_class *>((((MathPoint*)&cross2)))->FUN_00b12790();
            res->setC(cross2);
            float w = reinterpret_cast<::FUN_00b3f130_shell *>(&(::g_011f8c05))->FUN_00b3f130(-elem4->m_10, elem4->m_10);
            LocalPoint fp(elem4->m_04 + w, elem4->m_08 + w, elem4->m_0c + w);
            reinterpret_cast<::FUN_00b404c0_cls *>((res))->FUN_00b404c0((const ::FUN_00b28440_Class *)(::NiPoint3 *)(&fp), 1);
        }
    }
}
}  // namespace fnv_00b13c10


struct RingSettings
{
    int unk00, unk04;
    float strength;
};
double __cdecl FUN_00ec6054(double);
double __cdecl FUN_00ec6cde(double);
inline double ringCos(float a)
{
    return (float)std::cos(a);
}
inline double ringSin(float a)
{
    return (float)std::sin(a);
}

struct RingPoint
{
    float x, y, z;
    RingPoint()
    {
        x = y = z = 0.0f;
    }
    RingPoint(float px, float py, float pz) : x(px), y(py), z(pz)
    {}
    operator const float*() const
    {
        return &x;
    }
    float& operator[](int index)
    {
        return (&x)[index];
    }
    void FUN_00b12790()
    {
        float fLengthSq = x * x + y * y + z * z;
        float fInvLength = 1.0f / (float)FUN_00ec6054(fLengthSq);
        x *= fInvLength;
        y *= fInvLength;
        z *= fInvLength;
    }
    RingPoint FUN_00b12810(const RingPoint& rhs)
    {
        float fX = y * rhs.z - z * rhs.y;
        float fY = z * rhs.x - x * rhs.z;
        float fZ = x * rhs.y - y * rhs.x;
        return RingPoint(fX, fY, fZ);
    }
};
struct PlainPoint
{
    float x, y, z;
};
struct RingUV
{
    float u, v;
};
struct RingColor
{
    float r, g, b, a;
};
struct RingGeometry
{
    RingPoint origin;
    RingPoint center;
    float radius;
    int unk1c, unk20, unk24;
    RingPoint axisU, axisV;
};
struct RingModifier
{
    float fAngleDifference, fImpulseRadiusSquared, fAngleFalloff, fDuration, fTimeFalloff, fWaterLevelItem;
    float FUN_00b14980(float afAngle, float afTime)
    {
        float fResult = 0.0f;
        float m_kCenter = fAngleDifference;
        float fTimeSinceScaleStart = (float)FUN_00ec6cde(afAngle - m_kCenter);
        if (::runtimeInitializationFloat2066 < fTimeSinceScaleStart)
        {
            if (m_kCenter > afAngle)
                afAngle += ::runtimeInitializationFloat4160;
            else
                m_kCenter += ::runtimeInitializationFloat4160;
        }
        fTimeSinceScaleStart = (float)FUN_00ec6cde(afAngle - m_kCenter);
        if (fImpulseRadiusSquared > fTimeSinceScaleStart)
        {
            float fRemaining = fDuration - afTime;
            if (fRemaining > 0.0)
            {
                float fAngleWeight = 1.0f - fTimeSinceScaleStart / fImpulseRadiusSquared;
                float fAngleExponent = fAngleFalloff;
                fAngleWeight = (float)std::pow(fAngleWeight, fAngleExponent);
                float fTimeWeight = fRemaining / fDuration;
                float fTimeExponent = fTimeFalloff;
                fTimeWeight = (float)std::pow(fTimeWeight, fTimeExponent);
                fResult = fWaterLevelItem * fAngleWeight * fTimeWeight;
            }
        }
        return fResult;
    }
};
struct RingModifiers
{
    int unk00, unk04, unk08;
    RingModifier* first;
    RingModifier* last;
    RingModifier* capacity;
    unsigned int size() const
    {
        return last - first;
    }
    RingModifier& operator[](unsigned int index)
    {
        if (index >= (unsigned int)(last - first))
            std::abort();
        return first[index];
    }
};
struct RingBuilder
{
    int unk00, unk04;
    bool enabled;
    unsigned char unk09;
    unsigned short unk0a;
    int unk0c, unk10, unk14, unk18, unk1c;
    unsigned short unk20;
    unsigned short count;
    bool isEnabled() const
    {
        return enabled;
    }
};
struct RingOwner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    RingModifiers modifiers;
    void FUN_00b14450(RingGeometry* geometry, float amount, float fade, int segments, RingBuilder* builder,
                      RingPoint* uvScale, float value, bool flag, float uvOffset, int linear);
};
// @fnv 0x00b11050
void FUN_00b10dc0::FUN_00b11050(unsigned int seed, float scale, int level, const BranchPoint& origin, float age,
                                float parentFactor, const BranchMatrix& transform, const BranchPoint& axis,
                                BranchMesh* mesh, void* context, float weight, unsigned int id, float cap)
{
    bool animation = ((bool)(reinterpret_cast<::FUN_00b18320_Class *>((DAT_011f8c00))->GetByteAtOffset4C())) && level >= ((int)(reinterpret_cast<::NiD3DHLSLPixelShader *>((DAT_011f8c00))->FUN_00b18300()));
    if (level == DAT_011ad14c)
        id = (*reinterpret_cast<unsigned int *>(&::fnv_00b2af80::DAT_011f8bfc))++;
    if (level == 0)
        reinterpret_cast<::S_00b13a40_Obj *>(this)->FUN_00b13a40();
    float thickness;
    BranchConfig* material = DAT_011f8c50.GetElement(level);
    if (!animation)
        firstVertex = mesh->GetVertices();
    time = age;
    if (!animation)
        reinterpret_cast<::ParticleEmitter *>(this)->FUN_00b14ca0((::CreationSettings *)(material));
    float angle = reinterpret_cast<::FUN_00b37ad0_class *>(((material->length).operator->()))->FUN_00b37ad0(age) * scale;
    float radius = angle / material->segments;
    float base = reinterpret_cast<::FUN_00b3f130_shell *>(&((*reinterpret_cast<::BranchRandom *>(&::g_011f8c05))))->FUN_00b3f130(DAT_010a54a0, 180.0f);
    float config = reinterpret_cast<::FUN_00b37ad0_class *>(((material->base).operator->()))->FUN_00b37ad0(age);
    float managed = reinterpret_cast<::FUN_00b37ad0_class *>(((material->bend).operator->()))->FUN_00b37ad0(age);
    float length = reinterpret_cast<::FUN_00b37ad0_class *>(((material->thickness).operator->()))->FUN_00b37ad0(age) * scale;
    thickness = reinterpret_cast<::FUN_00b37ad0_class *>(((material->material).operator->()))->FUN_00b37ad0(age);
    type = (unsigned short)material->sides;
    float step = material->animate ? base + 0.5 + age : 0.0;
    BranchPoint shape(material->fixedWidth ? material->width : material->width * length * ::runtimeInitializationFloat4160,
                      material->fixedHeight ? material->height : angle / scale * material->height,
                      (childList.size() + seed) % 2 == 0 ? material->twist : -material->twist);
    float bend = reinterpret_cast<::FUN_00b37ad0_class *>(((material->radius).operator->()))->FUN_00b37ad0(0.0f) * length;
    if (cap > 0.0 && bend > cap * DAT_010a549c)
    {
        bend = cap * DAT_010a549c;
        length = bend;
    }
    entryCount = material->segments + 1;
    if (entryCount >= 2)
    {
        entries = new FUN_00b130a0[entryCount];
        if (!animation)
        {
            unsigned short index = (entryCount - 1) * (material->sides * 2 + 4);
            unsigned short* indices = new unsigned short[index];
            unsigned short column = mesh->GetVertices();
            int vertex = 0;
            int numIndices = 0;
            for (int row = 0; row < entryCount - 1; row++)
            {
                int first = numIndices;
                for (int side = 0; side < material->sides + 1; side++)
                {
                    indices[vertex] = column + (numIndices + (material->sides + 1));
                    vertex++;
                    indices[vertex] = column + numIndices;
                    vertex++;
                    numIndices++;
                }
                indices[vertex] = column + (first + (material->sides + 1));
                vertex++;
                indices[vertex] = column + (first + (material->sides + 1));
                vertex++;
            }
            reinterpret_cast<::Target *>((mesh))->FUN_00b2fdc0(0, (unsigned int)(indices), index);
            mesh->groups++;
        }
        FUN_00b130a0* qhxpxJd = entries;
        qhxpxJd->position = origin;
        float qSVM = reinterpret_cast<::SplineSampler *>(((material->orientation).operator->()))->Sample(0.0f);
        float qrEZrs = reinterpret_cast<::SplineSampler *>(((material->orientation).operator->()))->Sample(0.0f);
        qhxpxJd->matrix = transform;
        BranchPoint qsSDDgz = (*(::BranchPoint *)(reinterpret_cast<::FUN_00b12b50_class *>((void *)&(transform))->TransformVector((float *)&(axis), {})));
        reinterpret_cast<::MatrixOwner *>(&(qhxpxJd->matrix))->FUN_00b12d50(base, (*(float *)&(const ::BranchPoint &)(qsSDDgz)), {}, {});
        reinterpret_cast<::Mat3Rot *>(&(qhxpxJd->matrix))->FUN_00b12c00(config + qrEZrs, qSVM);
        qhxpxJd->direction = DAT_011f8c40.FUN_00b12890(qhxpxJd->matrix);
        qhxpxJd->radius = reinterpret_cast<::FUN_00b37ad0_class *>(((material->radius).operator->()))->FUN_00b37ad0(0.0f) * length;
        float qfTOqo = reinterpret_cast<::FUN_00b37ad0_class *>(((material->variation).operator->()))->FUN_00b37ad0(0.0f) * thickness;
        float qbGYp = BranchDegrees(reinterpret_cast<::This *>(&(qhxpxJd->direction))->FUN_00b12720((const ::NiPoint3 &)(DAT_011f8c08)));
        float qSuoDt = BranchFalloff((float)(double)(float)std::fabs((float)(DAT_01066808 - qbGYp)));
        BranchPoint qkbsJ = qhxpxJd->direction.FUN_00b12810(DAT_011f8c08);
        reinterpret_cast<::FUN_00b12790_class *>(&(qkbsJ))->FUN_00b12790();
        float qdqWL = (reinterpret_cast<::FUN_00b37ad0_class *>(((material->noise).operator->()))->FUN_00b37ad0(0.0f) - 0.5) * 2.0 * -1.0;
        BranchMatrix qnuVZg;
        reinterpret_cast<::RotationMatrix *>(&(qnuVZg))->SetRotationAxisAngle(qdqWL * managed * qbGYp * qSuoDt, (*(float *)&(const ::BranchPoint &)(qkbsJ)), {}, {});
        qhxpxJd->matrix = qhxpxJd->matrix.Multiply(qnuVZg);
        qhxpxJd->direction = DAT_011f8c40.FUN_00b12890(qhxpxJd->matrix);
        if (mesh && level == 0)
        {
            mesh->SetDiameter(qhxpxJd->radius * 2.0f);
            mesh->SetStart(material->lower * angle);
        }
        float qHXYKT = weight;
        if (level <= DAT_011ad14c)
        {
            qhxpxJd->weight = reinterpret_cast<::FUN_00b14ae0_class *>(this)->FUN_00b14ae0(level, 0.0f, qfTOqo);
            qHXYKT = qhxpxJd->weight;
        }
        else if (DAT_011f8c04)
        {
            qhxpxJd->weight = reinterpret_cast<::FUN_00b14b10_class *>(this)->FUN_00b14b10(weight, qfTOqo);
            qHXYKT = qhxpxJd->weight;
        }
        if (!animation)
        {
            float factor = 0.0f;
            if (level != 0)
                factor = parentFactor;
            reinterpret_cast<::RingOwner *>(this)->FUN_00b14450((::RingGeometry *)(qhxpxJd), 0.0f, factor, type, (::RingBuilder *)(mesh), (::RingPoint *)&(shape), qHXYKT, id, step, level);
        }
        else
        {
            reinterpret_cast<::addb18::GvOwner *>((DAT_011f8c00))->FUN_00b188d0();
            reinterpret_cast<::SBranchOwner *>((DAT_011f8c00))->FUN_00b18a60(qhxpxJd->position);
        }
        float qvyWyw = 0.0f;
        entries->distance = 0.0f;
        FUN_00b130a0* qpqRa = qhxpxJd;
        for (int segment = 1; segment < entryCount; segment++)
        {
            FUN_00b130a0* qGfbX = &entries[segment];
            float qAhbO = (float)segment / (entryCount - 1);
            float qZAdkzg = BranchPower(qAhbO, material->exponent);
            radius = qZAdkzg * angle - qvyWyw;
            qGfbX->radius = reinterpret_cast<::FUN_00b37ad0_class *>(((material->radius).operator->()))->FUN_00b37ad0(qZAdkzg) * length;
            float qrKBG = reinterpret_cast<::FUN_00b37ad0_class *>(((material->variation).operator->()))->FUN_00b37ad0(qZAdkzg) * thickness;
            qGfbX->matrix = qpqRa->matrix;
            qGfbX->direction = DAT_011f8c40.FUN_00b12890(qGfbX->matrix);
            float qbXcw = BranchDegrees(reinterpret_cast<::This *>(&(qGfbX->direction))->FUN_00b12720((const ::NiPoint3 &)(DAT_011f8c08)));
            float qRqUtp = BranchFalloff((float)(double)(float)std::fabs((float)(DAT_01066808 - qbXcw)));
            BranchPoint qArxcFu = qGfbX->direction.FUN_00b12810(DAT_011f8c08);
            reinterpret_cast<::FUN_00b12790_class *>(&(qArxcFu))->FUN_00b12790();
            float qsTDDg = (reinterpret_cast<::FUN_00b37ad0_class *>(((material->noise).operator->()))->FUN_00b37ad0(qZAdkzg) - 0.5) * 2.0 * -1.0;
            reinterpret_cast<::RotationMatrix *>(&(qnuVZg))->SetRotationAxisAngle(qsTDDg * managed * qbXcw * qRqUtp, (*(float *)&(const ::BranchPoint &)(qArxcFu)), {}, {});
            qGfbX->matrix = qGfbX->matrix.Multiply(qnuVZg);
            float qBCzzXA = reinterpret_cast<::SplineSampler *>(((material->orientation).operator->()))->Sample(qZAdkzg);
            float qxQHW = reinterpret_cast<::SplineSampler *>(((material->orientation).operator->()))->Sample(qZAdkzg);
            reinterpret_cast<::Mat3Rot *>(&(qGfbX->matrix))->FUN_00b12c00(qxQHW, qBCzzXA);
            qGfbX->direction = DAT_011f8c40.FUN_00b12890(qGfbX->matrix);
            qGfbX->position = qpqRa ? qpqRa->position + qpqRa->direction * radius : origin;
            float qrzAir = weight;
            if (level <= DAT_011ad14c)
            {
                qGfbX->weight = reinterpret_cast<::FUN_00b14ae0_class *>(this)->FUN_00b14ae0(level, qZAdkzg, qrKBG);
                qrzAir = qGfbX->weight;
            }
            else if (DAT_011f8c04)
            {
                qGfbX->weight = reinterpret_cast<::FUN_00b14b10_class *>(this)->FUN_00b14b10(weight, qrKBG);
                qrzAir = qGfbX->weight;
            }
            if (!animation)
            {
                float currentFactor = 0.0f;
                if (level == 0)
                {
                    float position = qZAdkzg;
                    if (material->lower > position)
                        currentFactor = 1.0f;
                    else
                        currentFactor = material->lower * -1.0 / (1.0 - material->lower);
                }
                else
                    currentFactor = parentFactor;
                reinterpret_cast<::RingOwner *>(this)->FUN_00b14450((::RingGeometry *)(qGfbX), qZAdkzg, currentFactor, type, (::RingBuilder *)(mesh), (::RingPoint *)&(shape), qrzAir, id, step, level);
            }
            else
                reinterpret_cast<::SBranchOwner *>((DAT_011f8c00))->FUN_00b18a60(qGfbX->position);
            qpqRa = qGfbX;
            qvyWyw += radius;
            entries[segment].distance = qvyWyw;
        }
        if (animation)
            reinterpret_cast<::FrondGuideFinalizer *>((DAT_011f8c00))->FUN_00b18b70(bend);
        else
        {
            mesh->SetVertices((unsigned short)firstVertex);
            FUN_00b14ed0(mesh, type);
        }
        int qpTd = (int)(material->children / scale * angle);
        level++;
        bool qzzQr = level >= (int)(DAT_011f8c60 - DAT_011f8c5c) - 1;
        if (!qzzQr || DAT_011ad148)
        {
            for (int child = 0; child < qpTd; child++)
            {
                BranchChild qHVMR;
                qHVMR.idx = 0;
                qHVMR.t = 0.0f;
                qHVMR.object = 0;
                if (!qzzQr)
                {
                    seed += 3;
                    reinterpret_cast<::RandomNumberGenerator *>(&((*reinterpret_cast<::BranchRandom *>(&::g_011f8c05))))->SeedRandomGenerator(seed);
                }
                float qDdzMIp = 0.0f;
                if (!qzzQr && child == 0)
                {
                    qDdzMIp = reinterpret_cast<::FUN_00b3f130_shell *>(&((*reinterpret_cast<::BranchRandom *>(&::g_011f8c05))))->FUN_00b3f130(BranchInterpolate(material->lower, material->upper, 0.85f),
                                                        BranchInterpolate(material->lower, material->upper, 0.95f));
                }
                else
                    qDdzMIp = reinterpret_cast<::FUN_00b3f130_shell *>(&((*reinterpret_cast<::BranchRandom *>(&::g_011f8c05))))->FUN_00b3f130(material->lower, material->upper);
                reinterpret_cast<::FUN_00b14be0_cls *>(this)->FindSegment((::OutPair *)(::BranchChild *)(&qHVMR), qDdzMIp * angle);
                float qQMZREG = weight;
                if (level - 1 == DAT_011ad14c || DAT_011f8c04)
                {
                    qQMZREG = BranchInterpolate(entries[qHVMR.idx].weight, entries[qHVMR.idx + 1].weight, qHVMR.t);
                }
                if (!qzzQr)
                {
                    reinterpret_cast<::RandomNumberGenerator *>(&((*reinterpret_cast<::BranchRandom *>(&::g_011f8c05))))->SeedRandomGenerator(seed);
                    reinterpret_cast<::FUN_00b3f130_shell *>(&((*reinterpret_cast<::BranchRandom *>(&::g_011f8c05))))->FUN_00b3f130(0.0f, 100.0f);
                }
                BranchPoint qJDuOZ;
                FUN_00b13000(&qJDuOZ, &entries[qHVMR.idx].position, &entries[qHVMR.idx + 1].position, qHVMR.t);
                float qxWmVch = 1.0f;
                if (material->upper != material->lower)
                    qxWmVch = (qDdzMIp - material->lower) / (material->upper - material->lower);
                if (qzzQr)
                {
                    reinterpret_cast<::fnv_00b13100::Effect *>(this)->FUN_00b13100((::fnv_00b13100::ParentNode *)(::FUN_00b10dc0 *)(this), scale, level, (*(const ::fnv_00b13100::Vector3 *)(&qJDuOZ)), qxWmVch, (*(const ::fnv_00b13100::FloatMatrix3 *)(&entries[qHVMR.idx].matrix)), (*(const ::fnv_00b13100::Vector3 *)(&entries[qHVMR.idx])),
                                 (int)(context), qQMZREG, id);
                }
                else
                {
                    float qZWI = BranchInterpolate(entries[qHVMR.idx].radius, entries[qHVMR.idx + 1].radius, qHVMR.t);
                    qHVMR.object = new FUN_00b10dc0(this);
                    float qpia = parentFactor + (1.0f - parentFactor) * qxWmVch;
                    if (level <= 1)
                        qpia *= qpia;
                    qHVMR.object->FUN_00b11050(seed, scale, level, qJDuOZ, qxWmVch, qpia, entries[qHVMR.idx].matrix,
                                               entries[qHVMR.idx].direction, mesh, context, qQMZREG, id, qZWI);
                    if (!((bool)(reinterpret_cast<::FUN_00b18320_Class *>((DAT_011f8c00))->GetByteAtOffset4C())) || level < ((int)(reinterpret_cast<::NiD3DHLSLPixelShader *>((DAT_011f8c00))->FUN_00b18300())))
                        reinterpret_cast<::FrondPointAppend *>(&(childList))->FUN_00b1e4c0((const ::FrondPoint &)(qHVMR));
                    else
                    {
                        delete qHVMR.object;
                        qHVMR.object = 0;
                    }
                }
            }
        }
        if (qzzQr)
            reinterpret_cast<::IndexSet *>(&(DAT_011f8c80))->FUN_00b32350();
        reinterpret_cast<::b14_ctx *>(this)->FUN_00b14b40();
    }
}

// @fnv 0x00b14450
void RingOwner::FUN_00b14450(RingGeometry* geometry, float amount, float fade, int segments, RingBuilder* builder,
                             RingPoint* uvScale, float value, bool flag, float uvOffset, int linear)
{
    float fProgress = 0.0f;
    float aIncrement = 1.0f / segments;
    float intensity5;
    if (DAT_011f8bf4)
    {
        intensity5 = (1.0f - fade) * amount + fade;
        if (!linear)
            intensity5 *= intensity5;
        intensity5 = intensity5 * reinterpret_cast<RingSettings*>(DAT_011f8bf4)->strength +
                     (1.0f - reinterpret_cast<RingSettings*>(DAT_011f8bf4)->strength);
    }
    else
    {
        intensity5 = 1.0f;
    }
    RingColor color;
    color.b = intensity5;
    color.g = color.b;
    color.r = color.g;
    color.a = 1.0f;
    for (int i = 0; i <= segments; ++i)
    {
        float angle5 = ::runtimeInitializationFloat4160 * fProgress;
        RingUV uv_;
        uv_.u = fProgress * uvScale->x;
        uv_.u += uvScale->z * amount;
        uv_.v = (amount + uvOffset) * uvScale->y;
        reinterpret_cast<::CoordinateWriter *>((builder))->FUN_00b301f0((const float *)(const ::RingUV *)(&uv_), -1);
        float cosine6 = ringCos(angle5);
        float fSin = ringSin(angle5);
        RingPoint direction3;
        direction3[0] = cosine6 * geometry->axisU.x + fSin * geometry->axisV.x;
        direction3[1] = cosine6 * geometry->axisU.y + fSin * geometry->axisV.y;
        direction3[2] = cosine6 * geometry->axisU.z + fSin * geometry->axisV.z;
        cosine6 = ringCos(angle5 + ::runtimeInitializationFloat4161);
        fSin = ringSin(angle5 + ::runtimeInitializationFloat4161);
        RingPoint tangentTmp;
        tangentTmp[0] = cosine6 * geometry->axisU.x + fSin * geometry->axisV.x;
        tangentTmp[1] = cosine6 * geometry->axisU.y + fSin * geometry->axisV.y;
        tangentTmp[2] = cosine6 * geometry->axisU.z + fSin * geometry->axisV.z;
        reinterpret_cast<::fnv_00b305f0::FUN_00b305f0_cls *>((builder))->FUN_00b305f0((const float *)(const ::RingPoint *)(&tangentTmp));
        reinterpret_cast<::S00b30660_Obj *>((builder))->FUN_00b30660(tangentTmp.FUN_00b12810(direction3));
        float fScale = 1.0f;
        float displacement = 0.0f;
        for (unsigned int uiModifier = 0; uiModifier < modifiers.size(); ++uiModifier)
        {
            displacement += modifiers[uiModifier].FUN_00b14980(angle5, amount);
        }
        fScale += displacement;
        PlainPoint kPosition;
        kPosition.x = direction3[0] * geometry->radius + geometry->center.x;
        kPosition.y = direction3[1] * geometry->radius + geometry->center.y;
        kPosition.z = direction3[2] * geometry->radius + geometry->center.z;
        if (fScale != 1.0)
        {
            PlainPoint delta4;
            delta4.x = direction3[0] * geometry->radius * fScale + geometry->center.x;
            delta4.y = direction3[1] * geometry->radius * fScale + geometry->center.y;
            delta4.z = direction3[2] * geometry->radius * fScale + geometry->center.z;
            RingPoint kIntersectionOffset(delta4.x - kPosition.x, delta4.y - kPosition.y, delta4.z - kPosition.z);
            reinterpret_cast<::FUN_00b12790_class *>(&(kIntersectionOffset))->FUN_00b12790();
            direction3 = kIntersectionOffset;
            std::memmove(&kPosition, &delta4, sizeof(kPosition));
        }
        reinterpret_cast<::FUN_00b300c0_cls *>((builder))->FUN_00b300c0((const float *)(const ::PlainPoint *)(&kPosition));
        reinterpret_cast<::FUN_00b30020_Class *>((builder))->FUN_00b30020((float *)(&color));
        if (builder->isEnabled())
            reinterpret_cast<::FUN_00b30560_cls *>((builder))->FUN_00b30560(value, flag);
        ++builder->count;
        fProgress += aIncrement;
    }
}

struct ElemB25210
{
    int unk00;
    int unk04;
};
struct AuxB25210
{
    int unk00;
};
struct NonscalarTagB25210
{
};
inline NonscalarTagB25210 PtrCatB25210(ElemB25210*&, ElemB25210*&)
{
    NonscalarTagB25210 kCat;
    return kCat;
}
template <class T> inline void DestroyB25210(T* pkPtr)
{
    pkPtr->~T();
}
inline void DestroyRangeB25210(ElemB25210* pkCurrentObject, ElemB25210* pkLast, NonscalarTagB25210)
{
    for (; pkCurrentObject != pkLast; ++pkCurrentObject)
        DestroyB25210(pkCurrentObject);
}
inline void DestroyRangeB25210(ElemB25210* pkCurrentObject, ElemB25210* pkLast)
{
    DestroyRangeB25210(pkCurrentObject, pkLast, PtrCatB25210(pkCurrentObject, pkCurrentObject));
}
struct AuxBaseB25210
{
    ~AuxBaseB25210()
    {
        delete m_pkAux;
    }
    AuxB25210* m_pkAux;
};
class VectorValB25210 : public AuxBaseB25210
{
  public:
    void Destroy(ElemB25210* pkCurrentObject, ElemB25210* pkLast)
    {
        DestroyRangeB25210(pkCurrentObject, pkLast);
    }
    void Deallocate(ElemB25210* pkPtr, unsigned int)
    {
        delete pkPtr;
    }
    void Tidy()
    {
        if (m_pkFirst != 0)
        {
            Destroy(m_pkFirst, m_pkLast);
            Deallocate(m_pkFirst, m_pkEnd - m_pkFirst);
        }
        m_pkFirst = 0;
        m_pkLast = 0;
        m_pkEnd = 0;
    }
    int unk04;
    int unk08;
    ElemB25210* m_pkFirst;
    ElemB25210* m_pkLast;
    ElemB25210* m_pkEnd;
};
class FUN_00b15210 : public VectorValB25210
{
  public:
    ~FUN_00b15210();
};

// @fnv 0x00b15210
FUN_00b15210::~FUN_00b15210()
{
    reinterpret_cast<::FUN_00b15600_cls *>(this)->FUN_00b15600();
}

struct ElQ_acda90
{
    int m[6];
};
struct AlQ_acda90
{
};
struct CatQ_acda90
{
};
struct TagQ_acda90
{
};
struct ElQ_acda90;
inline CatQ_acda90 PtrCat_acda90(ElQ_acda90*&, ElQ_acda90*&)
{
    CatQ_acda90 c;
    return c;
}
inline void UFillN_acda90(ElQ_acda90* _First, unsigned int _Count, const ElQ_acda90& _Val, AlQ_acda90& _Al)
{
    ::CopyStructArray((::S_b16cd0 *)(_First), _Count, (::S_b16cd0 *)&(_Val));
}
struct VecQ_acda90;
struct CItQ_acda90
{
    void* _Myaux;
    ElQ_acda90* _Myptr;
    CItQ_acda90()
    {}
    CItQ_acda90(ElQ_acda90* _Ptr, const VecQ_acda90* _Pvector);
};
struct ItQ_acda90 : CItQ_acda90
{
    ItQ_acda90()
    {}
    ItQ_acda90(ElQ_acda90* _Ptr, const VecQ_acda90* _Pvector) : CItQ_acda90(_Ptr, _Pvector)
    {}
};
struct VecQ_acda90
{
    void* _Myownedaux;
    int m04;
    AlQ_acda90 _Alval;
    char p09[3];
    ElQ_acda90* _Myfirst;
    ElQ_acda90* _Mylast;
    ElQ_acda90* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_acda90 end()
    {
        return ItQ_acda90(_Mylast, this);
    }
    ElQ_acda90* _Ufill(ElQ_acda90* _Ptr, unsigned int _Count, const ElQ_acda90& _Val)
    {
        UFillN_acda90(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_acda90 FUN_00b154d0(CItQ_acda90 _Where, const ElQ_acda90& _Val);
    void FUN_00b15280(const ElQ_acda90& _Val);
};
inline CItQ_acda90::CItQ_acda90(ElQ_acda90* _Ptr, const VecQ_acda90* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        std::abort();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
inline void Dead12_acda90()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
}
// @fnv 0x00b15280
void VecQ_acda90::FUN_00b15280(const ElQ_acda90& _Val)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, _Val);
    else
    {
        FUN_00b154d0(end(), _Val);
        Dead12_acda90();
    }
}

inline void Dead8_acad60()
{
    int a[8];
}
inline void Dead11_acad60()
{
    int a[11];
}
struct AlQ_acad60
{
};
struct CatQ_acad60
{
};
struct TagQ_acad60
{
};
inline CatQ_acad60 PtrCat_acad60(int*&, int*&)
{
    CatQ_acad60 c;
    return c;
}
inline void UFill2_acad60(int* _First, unsigned int _Count, const int& _Val, AlQ_acad60& _Al, CatQ_acad60, TagQ_acad60)
{
    Dead8_acad60();
    ::fnv_00b36b10::FUN_00b36b10((unsigned int *)(_First), _Count, (const unsigned int &)(_Val));
}
inline void UFillN_acad60(int* _First, unsigned int _Count, const int& _Val, AlQ_acad60& _Al)
{
    UFill2_acad60(_First, _Count, _Val, _Al, PtrCat_acad60(_First, _First), TagQ_acad60());
}
struct VecQ_acad60;
struct CItQ_acad60
{
    void* _Myaux;
    int* _Myptr;
    CItQ_acad60()
    {}
    CItQ_acad60(int* _Ptr, const VecQ_acad60* _Pvector);
};
struct ItQ_acad60 : CItQ_acad60
{
    ItQ_acad60()
    {}
    ItQ_acad60(int* _Ptr, const VecQ_acad60* _Pvector) : CItQ_acad60(_Ptr, _Pvector)
    {}
};
struct VecQ_acad60
{
    void* _Myownedaux;
    int m04;
    AlQ_acad60 _Alval;
    char p09[3];
    int* _Myfirst;
    int* _Mylast;
    int* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    ItQ_acad60 end()
    {
        return ItQ_acad60(_Mylast, this);
    }
    int* _Ufill(int* _Ptr, unsigned int _Count, const int& _Val)
    {
        UFillN_acad60(_Ptr, _Count, _Val, _Alval);
        return _Ptr + _Count;
    }
    ItQ_acad60 FUN_00b156b0(CItQ_acad60 _Where, const int& _Val);
    void FUN_00b15390(const int& _Val);
};
inline CItQ_acad60::CItQ_acad60(int* _Ptr, const VecQ_acad60* _Pvector) : _Myaux(0)
{
    if (!(_Pvector != 0 && _Pvector->_Myfirst <= _Ptr && _Ptr <= _Pvector->_Mylast))
        std::abort();
    _Myaux = _Pvector->_Myownedaux;
    _Myptr = _Ptr;
}
// @fnv 0x00b15390
void VecQ_acad60::FUN_00b15390(const int& _Val)
{
    if (size() < capacity())
        _Mylast = _Ufill(_Mylast, 1, _Val);
    else
    {
        FUN_00b156b0(end(), _Val);
        Dead11_acad60();
    }
}

namespace fnv_00b32350 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            std::abort();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            std::abort();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            std::abort();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            std::abort();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            std::abort();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
class FUN_00b32350_Vector : public vectorS<int>
{
  public:
    void FUN_00b32350();
};

// @fnv 0x00b32350
void FUN_00b32350_Vector::FUN_00b32350()
{
    erase(begin(), end());
}
}  // namespace fnv_00b32350

struct B13970Tmp
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    ~B13970Tmp()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(1, 0);
    }
};
struct FUN_00b37660
{
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    FUN_00b37660(const B13970Tmp& t);
    static void* operator new(std::size_t size)
    {
        return FUN_00401000(size);
    }
    static void* operator new(std::size_t size, void* p)
    {
        return p;
    }
    static void operator delete(void* p)
    {}
};
static __forceinline void Dead5()
{
    int aiD[5];
}
struct B13970Self
{
    B13970Tmp FUN_00b3ee40();
    FUN_00b37660* FUN_00b13970();
};
// @fnv 0x00b13970
FUN_00b37660* B13970Self::FUN_00b13970()
{
    FUN_00b37660* p = new FUN_00b37660(FUN_00b3ee40());
    Dead5();
    return p;
}

inline float difference(float a, float b)
{
    return a - b;
}
struct ParticleFalloff
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float FUN_00b14980(float a, float b);
};
// @fnv 0x00b14980
float ParticleFalloff::FUN_00b14980(float a, float b)
{
    float result2 = 0.0f;
    float loTmp;
    float x = (float)(double)(float)std::fabs((double)(float)(a - (loTmp = unk00)));
    if (x > ::runtimeInitializationFloat2066)
    {
        if (a < loTmp)
        {
            a = a + ::runtimeInitializationFloat4160;
        }
        else
        {
            loTmp = loTmp + ::runtimeInitializationFloat4160;
        }
    }
    x = (float)(double)(float)std::fabs((double)(float)difference(a, loTmp));
    if (x < unk04)
    {
        float d8 = unk0c - b;
        if (d8 > 0.0)
        {
            float p2 = 1.0f - x / unk04;
            float e8 = unk08;
            p2 = (float)(double)(float)pow((double)p2, (double)e8);
            float q = d8 / unk0c;
            float e9 = unk10;
            q = (float)(double)(float)pow((double)q, (double)e9);
            result2 = unk14 * p2 * q;
        }
    }
    return result2;
}

struct Pt3X
{
    float x, y, z;
    Pt3X()
    {}
    __forceinline Pt3X(float fx, float fy, float afDepth)
    {
        x = fx;
        y = fy;
        z = afDepth;
    }
    __forceinline Pt3X operator-(const Pt3X& p) const
    {
        return Pt3X(x - p.x, y - p.y, z - p.z);
    }
    void FUN_00b12790()
    {
        float fScaleMultiplier = x * x + y * y + z * z;
        if (fScaleMultiplier > 0.0f)
        {
            float fRecip = 1.0f / fScaleMultiplier;
            x *= fRecip;
            y *= fRecip;
            z *= fRecip;
        }
    }
    Pt3X FUN_00b12810(const Pt3X& p) const
    {
        return Pt3X(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
    }
};
struct StripDataX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    short unk20;
    unsigned short m_22;
};

// @fnv 0x00b14ed0
void FUN_00b10dc0::FUN_00b14ed0(BranchMesh* data, unsigned short cols)
{
    for (int i = 0; i < entryCount; i++)
    {
        int rowStart2 = (cols + 1) * i;
        for (int j3 = 0; j3 <= cols; j3++)
        {
            int left4;
            if (j3 == 0)
                left4 = rowStart2 + cols - 1;
            else
                left4 = rowStart2 + j3 - 1;
            int right;
            if (j3 == cols)
                right = rowStart2 + 1;
            else
                right = rowStart2 + j3 + 1;
            left4 += firstVertex;
            right += firstVertex;
            Pt3X* a5 = ((::Pt3X *)(reinterpret_cast<::fnv_00b30f80::ptb30::PtOwner *>((((StripDataX*)data)))->FUN_00b30f80(left4)));
            Pt3X* b_ = ((::Pt3X *)(reinterpret_cast<::fnv_00b30f80::ptb30::PtOwner *>((((StripDataX*)data)))->FUN_00b30f80(right)));
            Pt3X dx = *b_ - *a5;
            reinterpret_cast<::FUN_00b12790_class *>(&(dx))->FUN_00b12790();
            int up3;
            if (i == 0)
                up3 = rowStart2 + j3;
            else
                up3 = (i - 1) * (cols + 1) + j3;
            int down2;
            if (i == entryCount - 1)
                down2 = rowStart2 + j3;
            else
                down2 = (i + 1) * (cols + 1) + j3;
            up3 += firstVertex;
            down2 += firstVertex;
            Pt3X* c5 = ((::Pt3X *)(reinterpret_cast<::fnv_00b30f80::ptb30::PtOwner *>((((StripDataX*)data)))->FUN_00b30f80(up3)));
            Pt3X* d2 = ((::Pt3X *)(reinterpret_cast<::fnv_00b30f80::ptb30::PtOwner *>((((StripDataX*)data)))->FUN_00b30f80(down2)));
            Pt3X dy3 = *d2 - *c5;
            reinterpret_cast<::FUN_00b12790_class *>(&(dy3))->FUN_00b12790();
            Pt3X n3 = dx.FUN_00b12810(dy3);
            reinterpret_cast<::FUN_00b30190_shell *>((((StripDataX*)data)))->FUN_00b30190((const float *)&(n3));
            ((StripDataX*)data)->m_22++;
        }
    }
}

#include "generated/data/speedtree/branch_ob1_variant.inc"
