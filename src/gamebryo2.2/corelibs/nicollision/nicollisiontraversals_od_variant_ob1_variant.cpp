
// src/gamebryo2.2/corelibs/nicollision/nicollisiontraversals_od_variant_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/gamebryo2.2/corelibs/nicollision/nicollisiontraversals_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nicollision/nicollisiontraversals_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nicollision/nicollisiontraversals.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/gamebryo2.2/corelibs/nicollision/nicollisiontraversals.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicollisiontraversals.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstring>
#include "fnv/decl/Builder.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FnvCpu_FUN_00a7b850_CpuObject.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01050000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_01203000.h"
extern int DAT_0126fa68;
extern int DAT_0126fa6c;
extern int DAT_0126fa70;
extern int DAT_0126fa74;
extern float DAT_0126fa78;
int* __cdecl FUN_00e9c7d0(float f, int* p);

struct Vec4
{
    float x;
    float y;
    float z;
    float w;
    __forceinline Vec4()
    {}
    __forceinline Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d)
    {}
};
struct PairB
{
    unsigned char a;
    unsigned char b;
};
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    __forceinline NiPoint3()
    {}
    inline NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    inline NiPoint3 operator-(const NiPoint3& o) const
    {
        return NiPoint3(x - o.x, y - o.y, z - o.z);
    }
    inline NiPoint3 operator+(const NiPoint3& o) const
    {
        return NiPoint3(x + o.x, y + o.y, z + o.z);
    }
    inline NiPoint3 operator*(float s) const
    {
        return NiPoint3(s * x, s * y, s * z);
    }
    float Length() const;
    inline void FUN_004a0c10()
    {
        float len = Length();
        if (len > ::DAT_01017cf8)
        {
            float inv = 1.0f / len;
            x *= inv;
            y *= inv;
            z *= inv;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
public:
    static const ::NiPoint3 ZERO;
};
struct PtOp
{
    NiPoint3 operator-(const NiPoint3& o) const;
};
struct NiPoint3Ex
{
    NiPoint3 operator+(const NiPoint3& o) const;
};
struct NiPoint3_helper
{
    NiPoint3 operator*(float s) const;
};
typedef NiPoint3 Pt;
struct Sub
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    Pt* m20;
    int u24;
    Vec4* m28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    struct PairB* m40;
    __forceinline Pt* GetVertices()
    {
        return m20;
    }
    __forceinline Vec4* GetColors()
    {
        return m28;
    }
    __forceinline PairB* GetFlags()
    {
        return m40;
    }
};
struct Obj
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    Sub* m_b8;
    __forceinline Sub* GetMesh()
    {
        return m_b8;
    }
    __forceinline Pt* GetVertices()
    {
        return GetMesh()->GetVertices();
    }
    __forceinline Vec4* GetColors()
    {
        return GetMesh()->GetColors();
    }
    __forceinline PairB* GetFlags()
    {
        return GetMesh()->GetFlags();
    }
    __forceinline short* GetIndices()
    {
        return ((short *)(reinterpret_cast<::FnvCpu_FUN_00a7b850_CpuObject *>((GetMesh()))->FUN_00a7b850()));
    }
};
struct VObj
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual int vt08();
};
struct FloatMatrix3
{
    Pt rows[3];
    NiPoint3 FUN_004b4500(const NiPoint3* p);
};
struct Host
{
    int u00;
    int u04;
    Pt center;
    float width;
    float height;
    FloatMatrix3 m1c;
    int m40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    Pt cached[4];
    int ud8;
    int udc;
    int ue0;
    unsigned char dirty;
    unsigned char ue5;
    unsigned char m_e6[16];
    void FUN_00c35c10(Pt* v);
    __forceinline int GetMode()
    {
        return m40;
    }
    __forceinline void GetColumn(int column, Pt& out)
    {
        Pt* rows = m1c.rows;
        out.x = rows[column].x;
        out.y = rows[column].y;
        out.z = rows[column].z;
    }
    __forceinline bool IsType()
    {
        if (this == 0)
            return false;
        return ((VObj*)this)->vt08() == (int)&(*reinterpret_cast<int *>(&::g_012030b0));
    }
    void FUN_00c34ad0(Pt p0, Obj* pA, Obj* pB, Vec4 color, unsigned char flag);
};
inline void Host::FUN_00c35c10(Pt* v)
{
    Pt* output = v;
    unsigned int byteCount = 4 * sizeof(Pt);
    if (!dirty)
    {
        memmove(output, cached, byteCount);
    }
    else
    {
        float halfWidth = width;
        float halfHeight = height;
        FloatMatrix3* rotation = &m1c;
        const Pt* origin = &center;
        Pt side(halfWidth, 0.0f, 0.0f);
        Pt up(0.0f, 0.0f, halfHeight);
        side = rotation->FUN_004b4500(&side);
        up = rotation->FUN_004b4500(&up);
        output[3] = (*origin - side) + up;
        output[2] = (*origin - side) - up;
        output[1] = (*origin + side) - up;
        output[0] = (*origin + side) + up;
        memmove(cached, output, byteCount);
        dirty = 0;
    }
}
// @fnv 0x00c34ad0
void Host::FUN_00c34ad0(Pt p0, Obj* pA, Obj* pB, Vec4 color, unsigned char flag)
{
    int count30 = 4;
    int n21 = 2;
    Pt aCorners[8];
    Pt tmp4c;
    reinterpret_cast<::Builder *>(this)->FUN_00c35c10((::Point *)(aCorners));
    tmp4c = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)((&aCorners[0])))->FUN_00439ef0-((::NiPoint3 *)&(p0), *(const ::NiPoint3 *)nullptr)));
    reinterpret_cast<::FUN_004a0c10_s *>(&(tmp4c))->FUN_004a0c10();
    aCorners[4] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)((&aCorners[0])))->ProjectileLaunched+((::NiPoint3 *)&(const ::NiPoint3 &)((&tmp4c)->operator*(::g_011deba0_arg1)), {})));
    tmp4c = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)((&aCorners[1])))->FUN_00439ef0-((::NiPoint3 *)&(p0), *(const ::NiPoint3 *)nullptr)));
    reinterpret_cast<::FUN_004a0c10_s *>(&(tmp4c))->FUN_004a0c10();
    aCorners[5] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)((&aCorners[1])))->ProjectileLaunched+((::NiPoint3 *)&(const ::NiPoint3 &)((&tmp4c)->operator*(::g_011deba0_arg1)), {})));
    tmp4c = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)((&aCorners[2])))->FUN_00439ef0-((::NiPoint3 *)&(p0), *(const ::NiPoint3 *)nullptr)));
    reinterpret_cast<::FUN_004a0c10_s *>(&(tmp4c))->FUN_004a0c10();
    aCorners[6] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)((&aCorners[2])))->ProjectileLaunched+((::NiPoint3 *)&(const ::NiPoint3 &)((&tmp4c)->operator*(::g_011deba0_arg1)), {})));
    tmp4c = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)((&aCorners[3])))->FUN_00439ef0-((::NiPoint3 *)&(p0), *(const ::NiPoint3 *)nullptr)));
    reinterpret_cast<::FUN_004a0c10_s *>(&(tmp4c))->FUN_004a0c10();
    aCorners[7] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)((&aCorners[3])))->ProjectileLaunched+((::NiPoint3 *)&(const ::NiPoint3 &)((&tmp4c)->operator*(::g_011deba0_arg1)), {})));
    unsigned short t13[8][2];
    t13[0][0] = 0;
    t13[0][1] = 1;
    t13[1][0] = 3;
    t13[1][1] = 2;
    t13[2][0] = 0;
    t13[2][1] = 3;
    t13[3][0] = 2;
    t13[3][1] = 1;
    t13[4][0] = 0;
    t13[4][1] = 4;
    t13[5][0] = 1;
    t13[5][1] = 5;
    t13[6][0] = 2;
    t13[6][1] = 6;
    t13[7][0] = 3;
    t13[7][1] = 7;
    unsigned short t23[10][3];
    t23[0][0] = 0;
    t23[0][1] = 1;
    t23[0][2] = 2;
    t23[1][0] = 2;
    t23[1][1] = 3;
    t23[1][2] = 0;
    t23[2][0] = 5;
    t23[2][1] = 0;
    t23[2][2] = 4;
    t23[3][0] = 5;
    t23[3][1] = 1;
    t23[3][2] = 0;
    t23[4][0] = 5;
    t23[4][1] = 2;
    t23[4][2] = 1;
    t23[5][0] = 6;
    t23[5][1] = 2;
    t23[5][2] = 5;
    t23[6][0] = 6;
    t23[6][1] = 7;
    t23[6][2] = 2;
    t23[7][0] = 7;
    t23[7][1] = 3;
    t23[7][2] = 2;
    t23[8][0] = 0;
    t23[8][1] = 3;
    t23[8][2] = 7;
    t23[9][0] = 7;
    t23[9][1] = 4;
    t23[9][2] = 0;
    Vec4 colObj;
    Vec4 colorA;
    Vec4 colorB;
    colObj = color;
    colorA = (*reinterpret_cast<::Vec4 *>(&::DAT_011a9be0));
    colorA.x = colObj.w;
    colorA.y = colObj.w;
    colorA.z = colObj.w;
    colorB.x = 1.0f;
    colorB.y = 0.7f;
    colorB.z = 0.7f;
    colorB.w = color.w;
    Pt* pVertsTmp;
    Vec4* colors8;
    PairB* flags0;
    pVertsTmp = pA->GetVertices();
    colors8 = pA->GetColors();
    flags0 = pA->GetFlags();
    unsigned short fillA;
    unsigned short idx46;
    idx46 = 0;
    for (; idx46 < count30; idx46++)
    {
        pVertsTmp[idx46 * 2] = aCorners[t13[idx46][0]];
        colors8[idx46 * 2] = GetMode() == 1
                                 ? (m_e6[idx46] ? Vec4(1.0f, 1.0f, 0.1f, color.w) : Vec4(0.1f, 1.0f, 0.1f, color.w))
                                 : Vec4(0.7f, 0.15f, 0.15f, color.w);
        pVertsTmp[idx46 * 2 + 1] = aCorners[t13[idx46][1]];
        colors8[idx46 * 2 + 1] = GetMode() == 1
                                     ? (m_e6[idx46] ? Vec4(1.0f, 1.0f, 0.1f, color.w) : Vec4(0.1f, 1.0f, 0.1f, color.w))
                                     : Vec4(0.7f, 0.15f, 0.15f, color.w);
        flags0[idx46].a = 1;
        flags0[idx46].b = 0;
    }
    if (IsType())
    {
        Pt vec128 = ::NiPoint3::ZERO;
        GetColumn(1, vec128);
        pVertsTmp[idx46 * 2] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)((&aCorners[0])))->ProjectileLaunched+((::NiPoint3 *)&(const ::NiPoint3 &)((&vec128)->operator*(30.0f)), {})));
        colors8[idx46 * 2] = colorA;
        pVertsTmp[idx46 * 2 + 1] = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)((&aCorners[0])))->FUN_00439ef0-((::NiPoint3 *)&(const ::NiPoint3 &)((&vec128)->operator*(30.0f)), *(const ::NiPoint3 *)nullptr)));
        colors8[idx46 * 2 + 1] = colorA;
        flags0[idx46].a = 1;
        flags0[idx46].b = 0;
        idx46++;
        pVertsTmp[idx46 * 2] = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)((&aCorners[3])))->ProjectileLaunched+((::NiPoint3 *)&(const ::NiPoint3 &)((&vec128)->operator*(30.0f)), {})));
        colors8[idx46 * 2] = colorA;
        pVertsTmp[idx46 * 2 + 1] = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)((&aCorners[3])))->FUN_00439ef0-((::NiPoint3 *)&(const ::NiPoint3 &)((&vec128)->operator*(30.0f)), *(const ::NiPoint3 *)nullptr)));
        colors8[idx46 * 2 + 1] = colorA;
        flags0[idx46].a = 1;
        flags0[idx46].b = 0;
        idx46++;
        count30++;
    }
    for (; idx46 < 8; idx46++)
    {
        flags0[idx46].a = 0;
        flags0[idx46].b = 0;
    }
    pVertsTmp = pB->GetVertices();
    colors8 = pB->GetColors();
    if (flag)
        colObj.w = 0.2f;
    else
        colObj.w = 0.1f;
    short* indices_35;
    indices_35 = pB->GetIndices();
    idx46 = 0;
    for (; idx46 < n21; idx46++)
    {
        pVertsTmp[idx46 * 3] = aCorners[t23[idx46][0]];
        colors8[idx46 * 3] = colObj;
        pVertsTmp[idx46 * 3 + 1] = aCorners[t23[idx46][1]];
        colors8[idx46 * 3 + 1] = colObj;
        pVertsTmp[idx46 * 3 + 2] = aCorners[t23[idx46][2]];
        colors8[idx46 * 3 + 2] = colObj;
        indices_35[idx46 * 3] = idx46 * 3;
        indices_35[idx46 * 3 + 1] = idx46 * 3 + 1;
        indices_35[idx46 * 3 + 2] = idx46 * 3 + 2;
    }
    {
        fillA = (idx46 - 1) * 3 + 2;
        for (; idx46 < 10; idx46++)
        {
            indices_35[idx46 * 3] = fillA;
            indices_35[idx46 * 3 + 1] = fillA;
            indices_35[idx46 * 3 + 2] = fillA;
        }
    }
}

#include "generated/data/gamebryo2.2/corelibs/nicollision/nicollisiontraversals_od_variant_ob1_variant.inc"
