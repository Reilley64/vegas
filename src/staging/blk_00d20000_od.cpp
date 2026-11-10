
// src/staging/blk_00d20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include <intrin.h>
#include <xmmintrin.h>
#include <new>
#include <windows.h>
#include <cmath>
#include "fnv/decl/Agent378.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BvTreeAgentD3.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00cfbd60_cls.h"
#include "fnv/decl/Manifold__NDetector.h"
#include "fnv/decl/S00d369a0_ListAgent.h"
#include "fnv/decl/fnv_00d324e0__AgentD.h"
#include "fnv/decl/fnv_00d3f080__hkpSphereCapsuleAgent.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00d31000.h"
#include "fnv/symbols_00d36000.h"
#include "fnv/symbols_00d39000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010ce000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_00cd6000.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00d28000.h"
#include "fnv/symbols_00d2c000.h"
#include "fnv/symbols_simd.h"
#include "fnv/decl/FUN_004b4ab0_Class.h"
#include "fnv/decl/S00da8180_AabbCastMachine.h"
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_010c4000.h"
#include <cstddef>
#include "fnv/decl/FUN_005609f0_shell.h"

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline float lengthSquared3() const
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        __m128 z = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), y);
        float r;
        _mm_store_ss(&r, z);
        return r;
    }
};

struct ContactBody
{
    char unk00[0xa];
    unsigned char m_qualityA;
    unsigned char unk0b;
    unsigned char m_qualityC;
    char unk0d[0xb0 - 0xd];
    float m_uiCommandId;
    char unkb4[0xd0 - 0xb4];
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    char unkf0[0xfc - 0xf0];
    float m_limitA;
    char unk100[0x10c - 0x100];
    float m_limitC;
};

// @fnv 0x00d28560
bool FUN_00d28560(void* unused, char** items, int count, int offset)
{
    for (int i = count - 1; i >= 0; i--)
    {
        ContactBody* body = (ContactBody*)(*items + offset);
        float t0 = body->m_uiCommandId;
        float t = (1.0f < t0) ? 1.0f : t0;
        float lin = body->m_kTranslationalVelocity.lengthSquared3();
        float ang = body->m_kAngularVelocity.lengthSquared3();
        float r = t * t * ang + lin;
        r = r * 0.25 - 0.010000000298023226;
        if ((body->m_qualityA & 0x7f) > (body->m_qualityC & 0x7f))
        {
            if (r > body->m_limitA)
            {
                return false;
            }
        }
        else if (r > body->m_limitC)
        {
            return false;
        }
        items++;
    }
    return true;
}

namespace fnv_00d31610 {

extern __m128 DAT_010c4c00;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setBroadcast3(const hkVector4q& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void addMul4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4q& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00);
    }
    __forceinline void setNeg4b(const hkVector4q& v)
    {
        m_vComponents = _mm_xor_ps(DAT_010c4c00, v.m_vComponents);
    }
};

struct LinearCastVertex
{
    hkVector4q m_vContactPosition;
    hkVector4q m_direction;
    hkVector4q m_unk20;
};

struct GskVertexIds
{
    unsigned char m_numA : 4;
    unsigned char m_numB : 4;
};

struct GskCache
{
    unsigned short m_ausVertexIds[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    GskVertexIds m_counts;
    unsigned char m_unk304b;

    __forceinline void flip()
    {
        unsigned char lo = m_counts.m_numA;
        m_counts.m_numA = m_counts.m_numB;
        m_counts.m_numB = lo;

        unsigned char dimA = m_ucDimensionA;
        m_ucDimensionA = m_ucDimensionB;
        m_ucDimensionB = dimA;

        int last = m_ucDimensionA + m_ucDimensionB - 1;
        unsigned short t = m_ausVertexIds[0];
        m_ausVertexIds[0] = m_ausVertexIds[last];
        m_ausVertexIds[last] = t;

        if ((m_ucDimensionB & m_ucDimensionA) == 2)
        {
            unsigned short t1 = m_ausVertexIds[1];
            m_ausVertexIds[1] = m_ausVertexIds[2];
            m_ausVertexIds[2] = t1;
        }
    }
};

struct LinearCastState
{
    LinearCastVertex* m_kRayEnd;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    LinearCastVertex m_v000;
    LinearCastVertex m_v001;
    LinearCastVertex m_v002;
    LinearCastVertex m_v003;
    LinearCastVertex m_v004;
    LinearCastVertex m_v005;
    LinearCastVertex m_v006;
    LinearCastVertex m_v007;
    LinearCastVertex m_v008;
    LinearCastVertex m_v009;
    LinearCastVertex m_v010;
    LinearCastVertex m_v011;
    LinearCastVertex m_v012;
    LinearCastVertex m_v013;
    LinearCastVertex m_v014;
    LinearCastVertex m_v015;
    LinearCastVertex m_v016;
    LinearCastVertex m_v017;
    LinearCastVertex m_v018;
    LinearCastVertex m_v019;
    LinearCastVertex m_v020;
    LinearCastVertex m_v021;
    LinearCastVertex m_v022;
    LinearCastVertex m_v023;
    LinearCastVertex m_v024;
    LinearCastVertex m_v025;
    LinearCastVertex m_v026;
    LinearCastVertex m_v027;
    LinearCastVertex m_v028;
    LinearCastVertex m_v029;
    LinearCastVertex m_v030;
    LinearCastVertex m_v031;
    LinearCastVertex m_v032;
    LinearCastVertex m_v033;
    LinearCastVertex m_v034;
    LinearCastVertex m_v035;
    LinearCastVertex m_v036;
    LinearCastVertex m_v037;
    LinearCastVertex m_v038;
    LinearCastVertex m_v039;
    LinearCastVertex m_v040;
    LinearCastVertex m_v041;
    LinearCastVertex m_v042;
    LinearCastVertex m_v043;
    LinearCastVertex m_v044;
    LinearCastVertex m_v045;
    LinearCastVertex m_v046;
    LinearCastVertex m_v047;
    LinearCastVertex m_v048;
    LinearCastVertex m_v049;
    LinearCastVertex m_v050;
    LinearCastVertex m_v051;
    LinearCastVertex m_v052;
    LinearCastVertex m_v053;
    LinearCastVertex m_v054;
    LinearCastVertex m_v055;
    LinearCastVertex m_v056;
    LinearCastVertex m_v057;
    LinearCastVertex m_v058;
    LinearCastVertex m_v059;
    LinearCastVertex m_v060;
    LinearCastVertex m_v061;
    LinearCastVertex m_v062;
    LinearCastVertex m_v063;
    LinearCastVertex m_v064;
    LinearCastVertex m_v065;
    LinearCastVertex m_v066;
    LinearCastVertex m_v067;
    LinearCastVertex m_v068;
    LinearCastVertex m_v069;
    LinearCastVertex m_v070;
    LinearCastVertex m_v071;
    LinearCastVertex m_v072;
    LinearCastVertex m_v073;
    LinearCastVertex m_v074;
    LinearCastVertex m_v075;
    LinearCastVertex m_v076;
    LinearCastVertex m_v077;
    LinearCastVertex m_v078;
    LinearCastVertex m_v079;
    LinearCastVertex m_v080;
    LinearCastVertex m_v081;
    LinearCastVertex m_v082;
    LinearCastVertex m_v083;
    LinearCastVertex m_v084;
    LinearCastVertex m_v085;
    LinearCastVertex m_v086;
    LinearCastVertex m_v087;
    LinearCastVertex m_v088;
    LinearCastVertex m_v089;
    LinearCastVertex m_v090;
    LinearCastVertex m_v091;
    LinearCastVertex m_v092;
    LinearCastVertex m_v093;
    LinearCastVertex m_v094;
    LinearCastVertex m_v095;
    LinearCastVertex m_v096;
    LinearCastVertex m_v097;
    LinearCastVertex m_v098;
    LinearCastVertex m_v099;
    LinearCastVertex m_v100;
    LinearCastVertex m_v101;
    LinearCastVertex m_v102;
    LinearCastVertex m_v103;
    LinearCastVertex m_v104;
    LinearCastVertex m_v105;
    LinearCastVertex m_v106;
    LinearCastVertex m_v107;
    LinearCastVertex m_v108;
    LinearCastVertex m_v109;
    LinearCastVertex m_v110;
    LinearCastVertex m_v111;
    LinearCastVertex m_v112;
    LinearCastVertex m_v113;
    LinearCastVertex m_v114;
    LinearCastVertex m_v115;
    LinearCastVertex m_v116;
    LinearCastVertex m_v117;
    LinearCastVertex m_v118;
    LinearCastVertex m_v119;
    LinearCastVertex m_v120;
    LinearCastVertex m_v121;
    LinearCastVertex m_v122;
    LinearCastVertex m_v123;
    LinearCastVertex m_v124;
    LinearCastVertex m_v125;
    LinearCastVertex m_v126;
    LinearCastVertex m_v127;
    LinearCastVertex m_v128;
    LinearCastVertex m_v129;
    LinearCastVertex m_v130;
    LinearCastVertex m_v131;
    LinearCastVertex m_v132;
    LinearCastVertex m_v133;
    LinearCastVertex m_v134;
    LinearCastVertex m_v135;
    LinearCastVertex m_v136;
    LinearCastVertex m_v137;
    LinearCastVertex m_v138;
    LinearCastVertex m_v139;
    LinearCastVertex m_v140;
    LinearCastVertex m_v141;
    LinearCastVertex m_v142;
    LinearCastVertex m_v143;
    LinearCastVertex m_v144;
    LinearCastVertex m_v145;
    LinearCastVertex m_v146;
    LinearCastVertex m_v147;
    LinearCastVertex m_v148;
    LinearCastVertex m_v149;
    LinearCastVertex m_v150;
    LinearCastVertex m_v151;
    LinearCastVertex m_v152;
    LinearCastVertex m_v153;
    LinearCastVertex m_v154;
    LinearCastVertex m_v155;
    LinearCastVertex m_v156;
    LinearCastVertex m_v157;
    LinearCastVertex m_v158;
    LinearCastVertex m_v159;
    LinearCastVertex m_v160;
    LinearCastVertex m_v161;
    LinearCastVertex m_v162;
    LinearCastVertex m_v163;
    LinearCastVertex m_v164;
    LinearCastVertex m_v165;
    LinearCastVertex m_v166;
    LinearCastVertex m_v167;
    LinearCastVertex m_v168;
    LinearCastVertex m_v169;
    LinearCastVertex m_v170;
    LinearCastVertex m_v171;
    LinearCastVertex m_v172;
    LinearCastVertex m_v173;
    LinearCastVertex m_v174;
    LinearCastVertex m_v175;
    LinearCastVertex m_v176;
    LinearCastVertex m_v177;
    LinearCastVertex m_v178;
    LinearCastVertex m_v179;
    LinearCastVertex m_v180;
    LinearCastVertex m_v181;
    LinearCastVertex m_v182;
    LinearCastVertex m_v183;
    LinearCastVertex m_v184;
    LinearCastVertex m_v185;
    LinearCastVertex m_v186;
    LinearCastVertex m_v187;
    LinearCastVertex m_v188;
    LinearCastVertex m_v189;
    LinearCastVertex m_v190;
    LinearCastVertex m_v191;
    LinearCastVertex m_v192;
    LinearCastVertex m_v193;
    LinearCastVertex m_v194;
    LinearCastVertex m_v195;
    LinearCastVertex m_v196;
    LinearCastVertex m_v197;
    LinearCastVertex m_v198;
    LinearCastVertex m_v199;
    LinearCastVertex m_v200;
    LinearCastVertex m_v201;
    LinearCastVertex m_v202;
    LinearCastVertex m_v203;
    LinearCastVertex m_v204;
    LinearCastVertex m_v205;
    LinearCastVertex m_v206;
    LinearCastVertex m_v207;
    LinearCastVertex m_v208;
    LinearCastVertex m_v209;
    LinearCastVertex m_v210;
    LinearCastVertex m_v211;
    LinearCastVertex m_v212;
    LinearCastVertex m_v213;
    LinearCastVertex m_v214;
    LinearCastVertex m_v215;
    LinearCastVertex m_v216;
    LinearCastVertex m_v217;
    LinearCastVertex m_v218;
    LinearCastVertex m_v219;
    LinearCastVertex m_v220;
    LinearCastVertex m_v221;
    LinearCastVertex m_v222;
    LinearCastVertex m_v223;
    LinearCastVertex m_v224;
    LinearCastVertex m_v225;
    LinearCastVertex m_v226;
    LinearCastVertex m_v227;
    LinearCastVertex m_v228;
    LinearCastVertex m_v229;
    LinearCastVertex m_v230;
    LinearCastVertex m_v231;
    LinearCastVertex m_v232;
    LinearCastVertex m_v233;
    LinearCastVertex m_v234;
    LinearCastVertex m_v235;
    LinearCastVertex m_v236;
    LinearCastVertex m_v237;
    LinearCastVertex m_v238;
    LinearCastVertex m_v239;
    LinearCastVertex m_v240;
    LinearCastVertex m_v241;
    LinearCastVertex m_v242;
    LinearCastVertex m_v243;
    LinearCastVertex m_v244;
    LinearCastVertex m_v245;
    LinearCastVertex m_v246;
    LinearCastVertex m_v247;
    LinearCastVertex m_v248;
    LinearCastVertex m_v249;
    LinearCastVertex m_v250;
    LinearCastVertex m_v251;
    LinearCastVertex m_v252;
    LinearCastVertex m_v253;
    LinearCastVertex m_v254;
    LinearCastVertex m_v255;
    int m_unk3010;
    int m_unk3014;
    int m_unk3018;
    int m_unk301c;
    hkVector4q m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int m_unk3034;
    int m_unk3038;
    int m_unk303c;
    GskCache m_pAccessManager;
};

struct CastObj
{
    void FUN_00d31610(intptr_t a1, intptr_t a2, intptr_t a3, LinearCastState& st);
};

// @fnv 0x00d31610
void CastObj::FUN_00d31610(intptr_t a1, intptr_t a2, intptr_t a3, LinearCastState& st)
{
    LinearCastState* s = &st;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    LinearCastVertex* v = s->m_kRayEnd;
    reinterpret_cast<::BvTreeAgentD3 *>(this)->FUN_00d302d0((*(const ::CdBodyD3 *)(a2)), (*(const ::CdBodyD3 *)(a1)), (*(const ::ProcessInputD3 *)(a3)), (::ProcessOutputD3 &)(st));
    for (; v < s->m_kRayEnd; v++)
    {
        hkVector4q w;
        w.setBroadcast3(v->m_direction);
        v->m_vContactPosition.addMul4(w, v->m_direction);
        v->m_direction.setNeg4(v->m_direction);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        s->m_vHitNormal.setNeg4b(s->m_vHitNormal);

        s->m_pAccessManager.flip();
    }
}
}

// namespace fnv_00d31610

namespace fnv_00d36d60 {

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

class SimplexProcessor
{
  public:
    void FUN_00d36d60(intptr_t a, intptr_t b, intptr_t c, Simplex* s);
};

// @fnv 0x00d36d60
void SimplexProcessor::FUN_00d36d60(intptr_t a, intptr_t b, intptr_t c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    reinterpret_cast<::S00d369a0_ListAgent *>(this)->FUN_00d369a0((::S00d369a0_Body *)(b), (::S00d369a0_Body *)(a), (::S00d369a0_Config *)(c), (intptr_t)(s));
    for (; v < s->m_kRayEnd; v++)
    {
        const __m128* pb = &v->m_kPointB;
        __m128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        __m128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}
}

// namespace fnv_00d36d60

namespace fnv_00d23380 {

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline float lengthSquared3() const
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s);
        float r;
        _mm_store_ss(&r, s);
        return r;
    }
};

struct SortObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    hkVector4 m_vContactPosition;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    int m_priority;
};

struct SortEntry
{
    unsigned int m_data;
    SortObject* m_object;
    unsigned int m_extra;
};

struct SortList
{
    SortEntry m_entries[4];
    int m_iNumberOfEntries;
};

// @fnv 0x00d23380
void FUN_00d23380(SortList* list)
{
    for (int i = 0; i < list->m_iNumberOfEntries - 1; i++)
    {
        for (int j = i + 1; j < list->m_iNumberOfEntries; j++)
        {
            SortEntry& a = list->m_entries[i];
            SortEntry& b = list->m_entries[j];
            if (a.m_object->m_priority < b.m_object->m_priority)
                continue;
            if (a.m_object->m_priority == b.m_object->m_priority &&
                a.m_object->m_vContactPosition.lengthSquared3() < b.m_object->m_vContactPosition.lengthSquared3())
                continue;
            SortEntry t = a;
            a = b;
            b = t;
        }
    }
}
}

// namespace fnv_00d23380


struct FinishingFlag
{
    int m_bFinishing;
};

static inline FinishingFlag NotFinishing()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    return flag;
}

class S00d2c8a0_Base
{
  public:
    S00d2c8a0_Base(FinishingFlag flag);  // FUN_00d2c7e0
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class S00d2c8a0_Derived : public S00d2c8a0_Base
{
  public:
    S00d2c8a0_Derived(FinishingFlag flag) : S00d2c8a0_Base(flag)
    {}
    virtual void vf04();
    __m128 m_kScaleFactors;
};

// Havok getVtable helper: placement-construct into a local buffer with the finish-loading flag.
// @fnv 0x00d2c8a0
const void* __cdecl FUN_00d2c8a0()
{
    __declspec(align(16)) char buffer[sizeof(S00d2c8a0_Derived)];
    S00d2c8a0_Derived* pObject = new (buffer) S00d2c8a0_Derived(NotFinishing());
    return *reinterpret_cast<const void**>(pObject);
}

namespace fnv_00d32850 {

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
};

struct Agent : AgentBase
{
    void FUN_00d32850(intptr_t a, intptr_t b, intptr_t c, Simplex* s);
};

// @fnv 0x00d32850
void Agent::FUN_00d32850(intptr_t a, intptr_t b, intptr_t c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    reinterpret_cast<::fnv_00d324e0::AgentD *>(this)->FUN_00d324e0((*(const ::fnv_00d324e0::BodyD *)(b)), (*(const ::fnv_00d324e0::BodyD *)(a)), (*(const ::fnv_00d324e0::InputD *)(c)), (*(::fnv_00d324e0::OutputD *)(s)));
    for (; v < s->m_kRayEnd; v++)
    {
        const __m128* pb = &v->m_kPointB;
        __m128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        __m128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}
}

// namespace fnv_00d32850

struct SortPair
{
    unsigned int key;
    unsigned int val;
};

// @fnv 0x00d36520
extern "C" void FUN_00d36520(SortPair* arr, int lo, int hi, unsigned int extra)
{
    int i;
    int j;
    __declspec(align(16)) SortPair pivot;
    __declspec(align(16)) SortPair tmp;

    for (;;)
    {
        i = lo;
        j = hi;
        pivot = arr[(lo + hi) >> 1];
        do
        {
            while (arr[i].key < pivot.key || (arr[i].key == pivot.key && arr[i].val < pivot.val))
            {
                ++i;
            }
            while (pivot.key < arr[j].key || (pivot.key == arr[j].key && pivot.val < arr[j].val))
            {
                --j;
            }
            if (j < i)
            {
                break;
            }
            if (j != i)
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            --j;
            ++i;
        } while (i <= j);
        if (lo < j)
        {
            FUN_00d36520(arr, lo, j, extra);
        }
        if (i >= hi)
        {
            break;
        }
        lo = i;
    }
}

struct hkpAgent3FuncsD367
{
    hkpAgent3FuncsD367()
    {
        m_bIsPredictive = false;
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction7 = 0;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};

class hkpCollisionDispatcherD367
{
  public:
    void AddEntry(const hkpAgent3FuncsD367& kFuncs, int iTypeA, int iTypeB);
};

// @fnv 0x00d367d0
void __cdecl FUN_00d367d0(hkpCollisionDispatcherD367* pkDispatcher)
{
    __declspec(align(16)) hkpAgent3FuncsD367 kFuncs;
    ::FUN_00d367b0((intptr_t)&(kFuncs));
    reinterpret_cast<::FUN_00cfbd60_cls *>((pkDispatcher))->AddEntry((::SrcRec *)&(kFuncs), 0x12, 7);
}

namespace fnv_00d36e80 {


class hkpCdBody;

struct hkVector4
{
    __m128 m_vComponents;
};

struct ShapeSweepParameters
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
    hkVector4 m_path;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

class hkpCdPointCollector
{
  public:
    hkpCdPointCollector()
    {
        m_fEarlyOutDistance = 3.40282e+38f;
    }
    virtual void AddCdPoint(const void* point);
    float m_fEarlyOutDistance;
};

class hkpSymmetricAgentFlipCastCollector : public hkpCdPointCollector
{
  public:
    hkpSymmetricAgentFlipCastCollector(const hkVector4& path, hkpCdPointCollector& collector)
        : m_path(path), m_kCollector(collector)
    {}
    virtual void AddCdPoint(const void* point);
    hkVector4 m_path;
    hkpCdPointCollector& m_kCollector;
};

struct AgentBase
{
};

struct Agent : AgentBase
{
    void FUN_00d36e80(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ShapeSweepParameters& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

// @fnv 0x00d36e80
void Agent::FUN_00d36e80(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ShapeSweepParameters& input,
                         hkpCdPointCollector& collector, hkpCdPointCollector* startCollector)
{
    ShapeSweepParameters flippedInput = input;
    flippedInput.m_path.m_vComponents = _mm_xor_ps(input.m_path.m_vComponents, DAT_010c44d0);
    hkpSymmetricAgentFlipCastCollector flippedCollector(input.m_path, collector);
    if (startCollector)
    {
        hkpSymmetricAgentFlipCastCollector flippedStartCollector(input.m_path, *startCollector);
        ::FUN_00d36960((intptr_t)this, (intptr_t)&(bodyB), (intptr_t)&(bodyA), (intptr_t)&(flippedInput), (intptr_t)&(flippedCollector));
    }
    else
    {
        ::FUN_00d36960((intptr_t)this, (intptr_t)&(bodyB), (intptr_t)&(bodyA), (intptr_t)&(flippedInput), (intptr_t)&(flippedCollector));
    }
}
}

// namespace fnv_00d36e80

namespace fnv_00d37c10 {

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
};

struct Agent : AgentBase
{
    void FUN_00d37c10(intptr_t a, intptr_t b, intptr_t c, Simplex* s);
};

// @fnv 0x00d37c10
void Agent::FUN_00d37c10(intptr_t a, intptr_t b, intptr_t c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    reinterpret_cast<::Agent378 *>(this)->FUN_00d378e0((::Body378 *)(b), (::Body378 *)(a), (void *)(c), (::ContactBuffer378 *)(s));
    for (; v < s->m_kRayEnd; v++)
    {
        const __m128* pb = &v->m_kPointB;
        __m128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        __m128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}
}

// namespace fnv_00d37c10

struct hkpAgent3FuncsD398
{
    hkpAgent3FuncsD398()
    {
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
        m_pAgentFunction7 = 0;
        m_bIsPredictive = false;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};

class hkpCollisionDispatcherD398
{
  public:
    void AddEntry(const hkpAgent3FuncsD398& kFuncs, int iTypeA, int iTypeB);
};

void FUN_00d39090();

// @fnv 0x00d39840
void __cdecl FUN_00d39840(hkpCollisionDispatcherD398* pkDispatcher)
{
    __declspec(align(16)) hkpAgent3FuncsD398 kFuncs;
    kFuncs.m_pCreateFunc = ((void (&)())::InitOutputDefaults);
    kFuncs.m_setCollisionQualityFunc = ((void (&)())::FUN_00d39390);
    kFuncs.m_pAgentFunction11 = (void*)&::FUN_00d39150;
    kFuncs.m_pAgentFunction3 = ((void (&)())::ReleaseHandles);
    kFuncs.m_pAgentFunction4 = ((void (&)())::RemoveKeyFromTable);
    kFuncs.m_pAgentFunction5 = ((void (&)())::InsertIntoSlotArray);
    kFuncs.m_createZeroContactFunc = FUN_00d39090;
    kFuncs.m_pAgent3DestroyFuncs = ((void (&)())::FUN_00d39130);
    reinterpret_cast<::FUN_00cfbd60_cls *>((pkDispatcher))->AddEntry((::SrcRec *)&(kFuncs), 5, 3);
}

namespace fnv_00d3f500 {

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
};

struct Agent : AgentBase
{
    void FUN_00d3f500(intptr_t a, intptr_t b, intptr_t c, Simplex* s);
};

// @fnv 0x00d3f500
void Agent::FUN_00d3f500(intptr_t a, intptr_t b, intptr_t c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    reinterpret_cast<::fnv_00d3f080::hkpSphereCapsuleAgent *>(this)->FUN_00d3f080((*(const ::fnv_00d3f080::hkpCdBody *)(b)), (*(const ::fnv_00d3f080::hkpCdBody *)(a)), (*(const ::fnv_00d3f080::GskAgentInput *)(c)), (*(::fnv_00d3f080::WorldOperationEntry *)(s)));
    for (; v < s->m_kRayEnd; v++)
    {
        const __m128* pb = &v->m_kPointB;
        __m128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        __m128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}
}

// namespace fnv_00d3f500

namespace fnv_00d3fe90 {
extern "C"
{
    unsigned __int64 __rdtsc();
    void _ReadWriteBarrier();
}
struct ProfileSample
{
    const char* name;
    unsigned int time, unk08;
};
struct ProfileBuffer
{
    unsigned int unk00;
    ProfileSample* current;
    unsigned int unk08;
    ProfileSample* end;
};
struct Vector
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct Matrix
{
    Vector c0, c1, c2, c3;
};
struct ShapeBase
{
    unsigned int unk00, unk04, unk08, unk0c;
    float radius;
};
struct Shape : ShapeBase
{
    unsigned int unk14, unk18, unk1c;
    __m128 halfExtents;
};
struct Body
{
    ShapeBase* shape;
    unsigned int unk04;
    Matrix* transform;
};
struct CollisionInput
{
    unsigned int unk00, unk04;
    float tolerance;
};
struct Params
{
    Body* a;
    Body* b;
    unsigned int unk08;
    CollisionInput* input;
    unsigned int unk10, unk14, unk18, unk1c;
    Matrix relative;
};
struct Processor
{
    const Body* a;
    const Body* b;
    CollisionInput* input;
    unsigned int manager;
    int output;
    const Matrix* worldA;
    const Matrix* worldB;
    unsigned int unk1c;
    Matrix relative;
    Vector halfA, halfB, tolerance, expandedA, expandedB;
    float scalarTolerance, constant;
    unsigned int unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    unsigned int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    __forceinline Processor(const Body& aa, const Body& bb, CollisionInput* ii, unsigned int mm, int oo,
                            const Matrix& rr, const Matrix& wa, const Vector& ha, const Matrix& wb, const Vector& hb,
                            float tol)
    {
        a = &aa;
        b = &bb;
        input = ii;
        manager = mm;
        output = oo;
        worldA = &wa;
        worldB = &wb;
        Vector c0 = rr.c0;
        Vector c1 = rr.c1;
        Vector c2 = rr.c2;
        Vector c3 = rr.c3;
        relative.c0.quad = c0.quad;
        relative.c1.quad = c1.quad;
        relative.c2.quad = c2.quad;
        relative.c3.quad = c3.quad;
        halfA = ha;
        halfB = hb;
        __m128 t = _mm_set_ps1(tol);
        tolerance.quad = t;
        expandedA.quad = _mm_add_ps(tolerance.quad, ha.quad);
        expandedB.quad = _mm_add_ps(tolerance.quad, hb.quad);
        scalarTolerance = tol;
        constant = 0.01f;
    }
};
// @fnv 0x00d3fe90
void* __cdecl FUN_00d3fe90(Params* p, unsigned char* out, unsigned char* obj, int unused, int z)
{
    ProfileBuffer* buf = (ProfileBuffer*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    if (buf->current < buf->end)
    {
        ProfileSample* rec = buf->current;
        rec->name = "TtBoxBox3";
        _ReadWriteBarrier();
        volatile unsigned int tick = (unsigned int)__rdtsc();
        rec->time = tick;
        buf->current = rec + 1;
    }
    Body* a = p->a;
    Shape* shapeA = static_cast<Shape*>(a->shape);
    float radiusA = *(volatile float*)&shapeA->radius;
    Shape* shapeB = static_cast<Shape*>(p->b->shape);
    __m128 ba = _mm_set_ps1(radiusA);
    Vector halfA;
    halfA.quad = _mm_add_ps(ba, shapeA->halfExtents);
    float radiusB = shapeB->radius;
    __m128 bb = _mm_set_ps1(radiusB);
    Vector halfB;
    halfB.quad = _mm_add_ps(bb, shapeB->halfExtents);
    CollisionInput* input = p->input;
    float tol = input->tolerance;
    Processor state(*a, *p->b, input, p->unk10, z, p->relative, *a->transform, halfA, *p->b->transform, halfB, tol);
    reinterpret_cast<::Manifold::NDetector *>(&(state))->FUN_00db2960((*(::Manifold::NManifold *)(obj)));
    out[2] = obj[0x21];
    buf = (ProfileBuffer*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    if (buf->current < buf->end)
    {
        ProfileSample* rec = buf->current;
        rec->name = "Et";
        _ReadWriteBarrier();
        volatile unsigned int tick = (unsigned int)__rdtsc();
        rec->time = tick;
        buf->current = rec + 1;
    }
    return obj + 0x40;
}
}

// namespace fnv_00d3fe90


struct ClosestPointResult
{
    float distSq;
    float s;
    float t;
    float unk0C;
    __m128 p1;
    __m128 p2;
};

static __forceinline void Dot3(float& result, __m128 u, __m128 v)
{
    __m128 m = _mm_mul_ps(u, v);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    _mm_store_ss(&result, _mm_add_ss(z, _mm_add_ss(y, m)));
}

// @fnv 0x00d231b0
int FUN_00d231b0(const __m128* pa, const __m128* pb, const __m128* pc, const __m128* pd, ClosestPointResult* out)
{
    const __m128& d = *pd;
    const __m128& b = *pb;
    __m128 a = *pa;
    __m128 c = *pc;

    __m128 ca = _mm_sub_ps(c, a);
    float p;
    Dot3(p, d, b);
    float q;
    Dot3(q, b, ca);
    float r;
    Dot3(r, d, ca);
    float bb;
    Dot3(bb, b, b);
    float dd;
    Dot3(dd, d, d);

    float denom = dd * bb - p * p;
    int result;
    float s;
    if ((float)fabs(denom) > (float)((p * p + (float)fabs((float)(dd * bb))) * 9.5367431640625e-07))
    {
        s = (dd * q - r * p) / denom;
        result = 0;
    }
    else
    {
        s = 0.0f;
        result = 1;
    }
    float t = (p * s - r) / dd;

    __m128 p1 = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(s), b), a);
    __m128 p2 = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(t), d), c);
    __m128 diff = _mm_sub_ps(p1, p2);
    float distSq;
    Dot3(distSq, diff, diff);

    out->distSq = distSq;
    _mm_store_ps(reinterpret_cast<float*>(&out->p1), p1);
    _mm_store_ps(reinterpret_cast<float*>(&out->p2), p2);
    out->s = s;
    out->t = t;
    return result;
}


struct D2fVector4
{
    __declspec(align(16)) float m_vComponents[4];
    void setNeg4(const D2fVector4& v)
    {
        _mm_store_ps(m_vComponents, _mm_xor_ps(*(const __m128*)v.m_vComponents, DAT_010c44d0));
    }
};

struct __declspec(align(16)) D2fInput
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
    D2fVector4 m_vec;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct D2fRayHitCollector
{
    virtual void CollectRayHit(const void* a, const void* b) = 0;
    float m_fHitDistance;
    D2fRayHitCollector() throw() : m_fHitDistance(::DAT_0104da48)
    {}
};

struct __declspec(align(16)) D2fCollector : D2fRayHitCollector
{
    D2fVector4 m_vec;
    void* m_user;

    D2fCollector(const D2fVector4& v, void* user) throw() : m_vec(v), m_user(user)
    {}
    virtual void CollectRayHit(const void* a, const void* b);
};

struct D2fWorld
{
    void FUN_00d2f460(intptr_t a1, intptr_t a2, const D2fInput* a3, intptr_t a4, void* a5);
};

// @fnv 0x00d2f460
void D2fWorld::FUN_00d2f460(intptr_t a1, intptr_t a2, const D2fInput* a3, intptr_t a4, void* a5)
{
    D2fInput tmp = *a3;
    tmp.m_vec.setNeg4(a3->m_vec);
    D2fCollector c1(a3->m_vec, (void*)a4);
    if (a5)
    {
        D2fCollector c2(a3->m_vec, a5);
        ::FUN_00d315a0((void *)this, (void *)(a2), (void *)(a1), &tmp, &c1);
    }
    else
    {
        ::FUN_00d315a0((void *)this, (void *)(a2), (void *)(a1), &tmp, &c1);
    }
}

class S00d2c910_Base
{
  public:
    S00d2c910_Base(void* a, int b);  // FUN_00d2b260
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class FUN_00d2c910 : public S00d2c910_Base
{
  public:
    FUN_00d2c910(void* a, int b);
    virtual void vf00();
    __m128 m_kScaleFactors;
};

// @fnv 0x00d2c910
FUN_00d2c910::FUN_00d2c910(void* a, int b) : S00d2c910_Base(a, b)
{
    m_kScaleFactors = _mm_setr_ps(0.0f, 0.0f, 0.0f, 0.0f);
}

struct FourFloatVector
{
    float x, y, z, w;
};

union AlignedVector
{
    FourFloatVector value;
    __m128 simd;
};

struct Transform4
{
    FourFloatVector x, y, z, translation;
};

struct ShapeGeometry
{
    void* vtable;
    int userData;
    int type;
    int flags;
    float radius;
    float welding;
    int material;
    int extra;
    __m128 vertices[3];
};

struct CollisionBody
{
    ShapeGeometry* shape;
    int key;
    Transform4* transform;
};

struct BodyPair
{
    CollisionBody* a;
    CollisionBody* b;
};

struct QueryInput
{
    int flags;
    int mode;
    FourFloatVector direction;
};

struct ContactResult
{
    __m128 normal;
    FourFloatVector first;
    __m128 firstAux;
    FourFloatVector second;
    __m128 secondAux;
    __m128 extra;
};

// @fnv 0x00d39150
void __cdecl FUN_00d39150(BodyPair* bodies, void* unused, QueryInput* input, __m128* output)
{
    ShapeGeometry* shapeA = bodies->a->shape;
    CollisionBody* bodyB = bodies->b;
    ShapeGeometry* shapeB = bodyB->shape;
    __m128 pointsA[2];
    __m128 pointsB[3];
    ContactResult result;
    {
        Transform4* transform = bodies->a->transform;
        AlignedVector axisX;
        axisX.value = transform->x;
        AlignedVector axisY;
        axisY.value = transform->y;
        AlignedVector axisZ;
        axisZ.value = transform->z;
        AlignedVector translation;
        translation.value = transform->translation;
        int i = 1;
        do
        {
            __m128 p = shapeA->vertices[i];
            __m128 y = _mm_shuffle_ps(p, p, 0x55);
            __m128 x = _mm_shuffle_ps(p, p, 0);
            x = _mm_mul_ps(x, axisX.simd);
            y = _mm_mul_ps(y, axisY.simd);
            y = _mm_add_ps(y, x);
            __m128 z = _mm_shuffle_ps(p, p, 0xaa);
            z = _mm_mul_ps(z, axisZ.simd);
            z = _mm_add_ps(z, translation.simd);
            pointsA[i] = _mm_add_ps(y, z);
        } while (--i >= 0);
    }
    {
        Transform4* transform = bodyB->transform;
        AlignedVector axisX;
        axisX.value = transform->x;
        AlignedVector axisY;
        axisY.value = transform->y;
        AlignedVector axisZ;
        axisZ.value = transform->z;
        AlignedVector translation;
        translation.value = transform->translation;
        int i = 2;
        do
        {
            __m128 p = shapeB->vertices[i];
            __m128 y = _mm_shuffle_ps(p, p, 0x55);
            __m128 x = _mm_shuffle_ps(p, p, 0);
            x = _mm_mul_ps(x, axisX.simd);
            y = _mm_mul_ps(y, axisY.simd);
            y = _mm_add_ps(y, x);
            __m128 z = _mm_shuffle_ps(p, p, 0xaa);
            z = _mm_mul_ps(z, axisZ.simd);
            z = _mm_add_ps(z, translation.simd);
            pointsB[i] = _mm_add_ps(y, z);
        } while (--i >= 0);
    }
    ::FUN_00cd6520((const ::ContactVector *)(pointsA), shapeA->radius, (const ::ContactVector *)(pointsB), shapeB->radius, (const float *)(const ::FourFloatVector *)(&input->direction), ::DAT_0104da48, 0, (::ContactRecord *)(::ContactResult *)(&result), (::Feature *)(void *)(0));
    if (result.first.w < result.second.w)
        *output = *reinterpret_cast<__m128*>(&result.first);
    else
        *output = *reinterpret_cast<__m128*>(&result.second);
}

struct S00d2c960_Info
{
    float unk00;
    float unk04;
    float m_fTime;
};

class S00d2c960_Motion
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58(float fTime, void* pTarget, const __m128* pPosition);
};

class S00d2c960_Body
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    S00d2c960_Motion m_kMotion;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    __m128 m_kPathOffset;
};

class FUN_00d2c960_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    S00d2c960_Body* m_pkBody;
    unsigned int unk1C;
    unsigned int m_kRoomNode;

    void FUN_00d2c960(const S00d2c960_Info* pkInfo);
};

// @fnv 0x00d2c960
void FUN_00d2c960_cls::FUN_00d2c960(const S00d2c960_Info* pkInfo)
{
    float fTime = pkInfo->m_fTime;
    S00d2c960_Body* pkBody = m_pkBody;
    __m128 kPosition = pkBody->m_kPathOffset;
    reinterpret_cast<::hkpEntityC9C *>((pkBody))->FUN_00c9c1d0();
    pkBody->m_kMotion.vf58(fTime, &m_kRoomNode, &kPosition);
}

extern "C" void _ReadWriteBarrier(void);

extern "C" unsigned __int64 __rdtsc(void);

extern char DAT_010ce8e8[];

struct MoppCastProfRec
{
    const char* name;
    unsigned long tick;
    unsigned long unk08;
};

struct MoppCastProfBuf
{
    unsigned long unk00;
    MoppCastProfRec* cur;
    unsigned long unk08;
    MoppCastProfRec* end;
};

struct MoppCastQuad
{
    union
    {
        __m128 v;
        struct
        {
            float x, y, z, w;
        };
    };
};

struct MoppCastMatrix
{
    MoppCastQuad col0, col1, col2, translation;
};

struct MoppCastVector
{
    MoppCastQuad quad;
};

struct MoppCastBounds
{
    MoppCastQuad min, max;
};

struct MoppCastInner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Eval(const MoppCastMatrix*, float, MoppCastBounds*);
};

struct MoppCastBody
{
    MoppCastInner* shape;
    int unk04;
    MoppCastMatrix* transform;
};

struct MoppCastInput
{
    void* unk00;
    int unk04;
    float tolerance;
    int unk0c;
    MoppCastMatrix transform;
    MoppCastVector direction;
};

struct MoppCastQuery
{
    MoppCastQuad start, end, radius;
    MoppCastInput* input;
    MoppCastBody* a;
    MoppCastBody* b;
    int unk3c;
};

struct MoppCastCollector
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    MoppCastInner* shape;
    float inverse;
    void* unk18;
    float unk1c;
    float unk20;
    int d, e;
    MoppCastQuery* query;
    int unk30;
};

static void ProfMark(const char* name)
{
    MoppCastProfBuf* buf = (MoppCastProfBuf*)TlsGetValue(DAT_0126835c);
    if (buf->cur < buf->end)
    {
        MoppCastProfRec* rec = buf->cur;
        rec->name = name;
        _ReadWriteBarrier();
        volatile unsigned long tick = (unsigned long)__rdtsc();
        rec->tick = tick;
        buf->cur = rec + 1;
    }
}

struct MoppCastCastGeometry
{
    MoppCastBounds bounds;
    MoppCastQuery query;
    MoppCastVector direction;
    int unk70;
    int unk74;
    int unk78;
    MoppCastCollector collector;
    MoppCastMatrix relative;
};

// @fnv 0x00d2f0d0
void __cdecl FUN_00d2f0d0(MoppCastBody* a, MoppCastBody* b, MoppCastInput* c, intptr_t d, intptr_t e)
{
    ProfMark(DAT_010ce8e8);
    MoppCastCastGeometry ls;
    reinterpret_cast<::hkTransformCB22 *>(&(ls.relative))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(b->transform)), (*(const ::hkTransformCB22 *)(a->transform)));

    a->shape->Eval(&ls.relative, c->tolerance, &ls.bounds);

    reinterpret_cast<::FUN_004b4ab0_Class *>(&(ls.direction))->FUN_004b4ab0((intptr_t)(b->transform), (intptr_t)(&c->direction));

    float tolerance = c->tolerance;
    __m128 scalarHalf = _mm_load_ss(&::fnv_00c88020::DAT_01016248);
    __m128 half = _mm_shuffle_ps(_mm_load_ss(&::fnv_00c88020::DAT_01016248), scalarHalf, 0);
    (__m128&)ls.query.start = _mm_add_ps(
        _mm_mul_ps(_mm_sub_ps((*reinterpret_cast<__m128 *>((void *)&::DAT_010ec7f0)), half), (__m128&)ls.bounds.min),
        _mm_mul_ps(half, (__m128&)ls.bounds.max));
    (__m128&)ls.query.end =
        _mm_add_ps((__m128&)ls.direction.quad, (__m128&)ls.query.start);
    __m128 radius = _mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(scalarHalf, scalarHalf, 0),
                             _mm_sub_ps((__m128&)ls.bounds.max, (__m128&)ls.bounds.min)),
        _mm_shuffle_ps(_mm_load_ss(&tolerance), _mm_load_ss(&tolerance), 0));
    ls.query.a = a;
    ls.query.b = b;
    (__m128&)ls.query.radius = radius;
    ls.query.input = c;
    reinterpret_cast<::S00da8180_AabbCastMachine *>(&(ls.collector))->FUN_00da8180((*(const ::AabbCastInput *)(&ls.query)), (void *)(d), (void *)(e));
    ProfMark(DAT_010c41f8);
}

bool FUN_00d28560(void* unused, char** items, int count, int offset);

const void* __cdecl FUN_00d2c8a0();

void __cdecl FUN_00d367b0(hkpAgent3FuncsD367& kFuncs);


void __cdecl FUN_00d367d0(hkpCollisionDispatcherD367* pkDispatcher);


void InitOutputDefaults();

void FUN_00d39130();

void ReleaseHandles();

void RemoveKeyFromTable();

void InsertIntoSlotArray();

void FUN_00d39390();

void __cdecl FUN_00d39840(hkpCollisionDispatcherD398* pkDispatcher);

typedef float hkReal;

typedef unsigned char hkUchar;

typedef unsigned char hkUint8;

typedef unsigned short hkUint16;

typedef unsigned int hkUint32;

typedef uintptr_t hkUlong;

typedef unsigned __w64 hk_size_t;

class hkClass;

typedef int hkBool32;

class hkBool
{
public:
typedef char CompileTimeTrueType;inline hkBool(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};

template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
hkEnum(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
private:
STORAGE m_kStorage;};

template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_kStorage;};

template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};

class hkMemoryAllocator
{
public:
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};

struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;};

class NineIntegerRecord
{
public:
typedef hkMemoryAllocator Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pStreamAllocator;
Allocator*m_pDebugAllocator;};

class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline virtual ~hkBaseObject(){}
public:
__forceinline hkBaseObject(){}
};

class hkStatisticsCollector;

class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
virtual const hkClass*GetClassType()const;
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(struct FinishingFlag flag){}
};

typedef __m128 hkQuadReal;

struct hkVec4X;

typedef const hkVec4X&hkVector4Parameter;

class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
VectorComponentValue(hkReal x)
{
m_vValue=_mm_load_ss(&x);
}
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
private:
hkQuadReal m_vValue;};

typedef const VectorComponentValue&hkSimdRealParameter;

class Vector4Comparison;

typedef const Vector4Comparison&hkVector4ComparisonParameter;

class hkTransform;

struct hkVec4X
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVec4X&v);
__forceinline void setAddMul4(const hkVec4X&a,const hkVec4X&b,hkSimdRealParameter r);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVec4X&b);
__forceinline hkReal&operator()(int i);
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};

class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkVec4X&getColumn(int i);
__forceinline const hkVec4X&getColumn(int i)const;
protected:
hkVec4X m_kColumn0;
hkVec4X m_kColumn1;
hkVec4X m_kColumn2;};

class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};

class hkTransform
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkTransform(const hkTransform&r);
__forceinline const hkVec4X&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVec4X m_vTranslation;};

inline void hkVec4X::operator=(const hkVec4X&v)
{
m_vComponents=v.m_vComponents;
}

inline void hkVec4X::setAddMul4(const hkVec4X&a,const hkVec4X&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}

inline void hkVec4X::_setTransformedPos(const hkTransform&t,const hkVec4X&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}

inline hkReal&hkVec4X::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}

inline hkVec4X&hkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
}

inline const hkVec4X&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}

const hkVec4X&hkTransform::getTranslation()const
{
return m_vTranslation;
}

const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
hkTransform::hkTransform(const hkTransform&t)
{
const hkVec4X r0=t.m_rotation.getColumn(0);
const hkVec4X r1=t.m_rotation.getColumn(1);
const hkVec4X r2=t.m_rotation.getColumn(2);
const hkVec4X r3=t.m_rotation.getColumn(3);
m_rotation.getColumn(0)=r0;
m_rotation.getColumn(1)=r1;
m_rotation.getColumn(2)=r2;
m_rotation.getColumn(3)=r3;}

class StringCursor
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
return*(*reinterpret_cast<::hkThreadLocalData< ::StringCursor *> *>(&::DAT_0126835c)).getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
hkBool m_bFlag;
public:
struct Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime();
};};

void StringCursor::CommandTimingEntry::setTime()
{
hkUint32 ticks;
ticks = (unsigned int)__rdtsc();
m_uiStartTicks=ticks;
}

class ScopedTimer
{
public:
__forceinline ~ScopedTimer(){{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};}
};

class hkAabb
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVec4X m_kMinimumCorner;};

class hkSphere
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
protected:
hkVec4X m_pos;};

typedef hkUint16 hkContactPointId;

class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkVec4X&getPosition();
inline hkVec4X&getSeparatingNormal();
inline void setSeparatingNormal(const hkVec4X&normal,hkReal dist);
inline void setNormal(const hkVec4X&normal);
protected:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVec4X m_vContactPosition;
hkVec4X m_vSeparatingNormal;};

inline hkVec4X&hkContactPoint::getPosition()
{
return m_vContactPosition;
}

inline hkVec4X&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}

inline void hkContactPoint::setSeparatingNormal(const hkVec4X&normal,hkReal dist)
{
m_vSeparatingNormal=normal;
m_vSeparatingNormal(3)=dist;
}

class Vector4WithInt24W:public hkVec4X
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};

enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};

class hkpCollisionDispatcher;

struct ShapeRayCastQuery;

struct ShapeRayCastOutput;

struct ShapeRayBundleCastInput;

struct ShapeRayCastOutputArray;

class hkpRayHitCollector;

class hkpCdBody;

class hkpShapeContainer;

typedef hkUint16 hkpVertexId;

typedef hkUint32 hkpShapeKey;

class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape::PhysicsShape));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32>m_type;
public:
hkpShape(struct FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};

class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};

const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}

const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}

struct GskAgentInput;

class hkpContactMgr;

struct WorldOperationEntry;

class hkpConstraintOwner;

class hkpCollisionAgent;

struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;};

class hkpContactMgrFactory;

class hkpCdPointCollector;

class hkpCdBodyPairCollector;

struct ShapeSweepParameters;

class hkpCollisionDispatcher:public hkReferencedObject
{
public:
enum{
HK_MAX_RESPONSE_TYPE=8,
HK_MAX_SHAPE_TYPE=32,
HK_MAX_AGENT2_TYPES=64,
HK_MAX_AGENT3_TYPES=16,
HK_MAX_COLLISION_QUALITIES=8
};
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
typedef hkpCollisionAgent*(__cdecl*CreateFunc)(const hkpCdBody&collA,const hkpCdBody&collB,const CollisionAgentContext&env,hkpContactMgr*mgr);
typedef void(__cdecl*GetPenetrationsFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
typedef void(__cdecl*GetClosestPointsFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&output);
typedef void(__cdecl*LinearCastFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector);
struct CollisionAgentFunctionTable
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(CollisionAgentFunctionTable));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
CreateFunc m_pCreateFunc;
GetPenetrationsFunc m_pQueryPenetrationsFunc;
GetClosestPointsFunc m_pGetPenetrationsFunc;
LinearCastFunc m_pLinearCastFunc;
hkBool m_bIsFlipped;
hkBool m_bIsPredictive;
CollisionAgentFunctionTable():m_bIsFlipped(false),m_bIsPredictive(false){}
};
public:
hkpCollisionDispatcher(CreateFunc defaultCreationFunction,hkpContactMgrFactory*defaultContactMgrFactory);
public:
struct IntegerPair
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(IntegerPair));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
CollisionShapeType m_iSecond;
CollisionShapeType m_iFirst;
};
struct AgentTypePairPriority
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(AgentTypePairPriority));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
char m_iAgentTypeA;
char m_iAgentTypeB;
char m_priority;
};
typedef AgentTypePairPriority DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
protected:
void internalRegisterCollisionAgent(hkUchar agentTypesTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE],int agentType,CollisionShapeType typeA,CollisionShapeType typeB,CollisionShapeType origA,CollisionShapeType origB,DebugTable*debugTable,int recursionDepth);
public:
enum CollisionQualityLevel
{
COLLISION_QUALITY_INVALID,
COLLISION_QUALITY_PSI,
COLLISION_QUALITY_SIMPLIFIED_TOI,
COLLISION_QUALITY_TOI,
COLLISION_QUALITY_TOI_HIGHER,
COLLISION_QUALITY_TOI_FORCED,
COLLISION_QUALITY_CHARACTER,
COLLISION_QUALITY_TMP_EXPAND_MANIFOLD
};
public:
hkReal m_fExpectedMaxLinearVelocity;};

struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};

class hkpCdPointCollector
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
inline virtual ~hkpCdPointCollector();
virtual void AddCdPoint(const ContactPointPair&point)=0;
protected:
hkReal m_fEarlyOutDistance;};

class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void ProcessAgent(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
protected:
inline virtual ~hkpCollisionAgent();
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();};

namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVec4X*vectorsIn,int numVectors,hkVec4X*vectorsOut);}

inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVec4X*vectorsIn,int numVectors,hkVec4X*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}

class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}};

struct MaterialIndexedTriangle
{
hkUint8 m_uiMaterialIndex;
hkpVertexId m_auiVertexIds[3];
};

class TriangleDistanceUtility
{
public:
static void __cdecl calcBarycentricCoordinates(hkVector4Parameter pos,hkVector4Parameter t0,hkVector4Parameter t1,hkVector4Parameter t2,ValueWrapper<hkReal>result[3]);
struct FourRealValueRecord
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(TriangleDistanceUtility::FourRealValueRecord));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal m_fFirstValue;
hkReal m_fSecondValue;
hkReal m_fThirdValue;
hkReal m_fFourthValue;
};
struct CollisionDistanceInfo
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(TriangleDistanceUtility::CollisionDistanceInfo));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVec4X m_kNearestPoint;
ValueWrapper<hkReal>distance;
void calcClosestPoint(hkVector4Parameter point,hkVec4X&closestPoint)
{
closestPoint.setAddMul4(point,m_kNearestPoint,distance.val());
}
};
static void __cdecl setupClosestPointTriangleCache(const hkVec4X*triangle,FourRealValueRecord&cache);
enum ClosestPointTriangleStatus
{
HIT_TRIANGLE_FACE=0,
HIT_TRIANGLE_EDGE
};
static ClosestPointTriangleStatus __cdecl GetClosestPointOnTriangle(hkVector4Parameter position,const hkVec4X*tri,const FourRealValueRecord&cache,CollisionDistanceInfo&result,MaterialIndexedTriangle*featureOutput=0);protected:
TriangleDistanceUtility();};

class hkpSphereTriangleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl InitAgentFunc(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl initAgentFuncInverse(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
static void __cdecl registerAgent2(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
virtual void cleanup(hkpConstraintOwner&info);
protected:
__forceinline hkpSphereTriangleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl CreateSphereTriangleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createTriangleSphereAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
public:
enum ClosestPointResult
{
ST_CP_MISS,
ST_CP_FACE,
ST_CP_EDGE
};
static ClosestPointResult __cdecl ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::FourRealValueRecord&m_pAccessManager,hkContactPoint&cpoint);
static __forceinline ClosestPointResult getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::FourRealValueRecord&m_pAccessManager,hkContactPoint&cpoint,MaterialIndexedTriangle*featureOutput=0);
hkContactPointId m_usContactPointId;
TriangleDistanceUtility::FourRealValueRecord m_kTriangleAccessData;
};

class hkpSphereRepShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
virtual const hkSphere*GetCollisionSpheres(hkSphere*sphereBuffer)const=0;
public:
hkpSphereRepShape(CollisionShapeType type):hkpShape(type){}
hkpSphereRepShape(FinishingFlag flag):hkpShape(flag){m_type=HK_SHAPE_SPHERE_REP;}
};

class hkpConvexShape:public hkpSphereRepShape
{
public:
static const struct ClassMemberDescriptor Members[];
virtual void GetFirstVertex(hkVec4X&v)const=0;
inline hkReal getRadius()const;enum WeldResult
{
WELD_RESULT_REJECT_CONTACT_POINT,
WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
};
__forceinline hkpConvexShape::WeldResult weldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,
hkVec4X&contactPointWs,const hkTransform*thisObjTransform,
const hkpConvexShape*collidingShape,const hkTransform*collidingTransform,hkVec4X&separatingNormalInOut)const;
virtual hkReal getMaximumProjection(const hkVec4X&direction)const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
virtual void GetVerticesFromIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*vertixArrayOut)const=0;
virtual int WeldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,hkVec4X&contactPointWs,const hkTransform*thisObjTransform,const hkpConvexShape*collidingShape,const hkTransform*collidingTransform,hkVec4X&separatingNormalInOut)const;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};

inline hkReal hkpConvexShape::getRadius()const
{
return m_fSphereRadius;
}
hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,
hkVec4X&contactPointWs,const hkTransform*thisObjTransform,
const hkpConvexShape*collidingShape,const hkTransform*collidingTransform,hkVec4X&separatingNormalInOut)const
{
return(WeldResult)this->WeldContactPoint(featurePoints,numFeaturePoints,
contactPointWs,thisObjTransform,
collidingShape,collidingTransform,separatingNormalInOut);}

class hkpTriangleShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline const hkVec4X*GetIndexedVertices()const;
protected:
hkUint16 m_kWeldingInfo;
hkVec4X m_kVertexA;
public:
void setType(){m_type=HK_SHAPE_TRIANGLE;}
};

const hkVec4X*hkpTriangleShape::GetIndexedVertices()const
{
return&m_kVertexA;
}

class hkpSphereShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
public:
hkpSphereShape(FinishingFlag flag):hkpConvexShape(flag){m_type=HK_SHAPE_SPHERE;}
};

hkpSphereTriangleAgent::ClosestPointResult __cdecl hkpSphereTriangleAgent::getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::FourRealValueRecord&cache,hkContactPoint&cpoint,MaterialIndexedTriangle*featureOutput)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
const hkVec4X&posA=bodyA.getTransform().getTranslation();
hkVec4X triVertices[3];
hkVector4Util_S::TransformPointArray(bodyB.getTransform(),triB->GetIndexedVertices(),3,triVertices);
TriangleDistanceUtility::CollisionDistanceInfo cptr;
TriangleDistanceUtility::ClosestPointTriangleStatus res=TriangleDistanceUtility::GetClosestPointOnTriangle(posA,triVertices,cache,cptr,featureOutput);
const hkReal radiusSum=sphereA->getRadius()+triB->getRadius();
if(cptr.distance<radiusSum+input.getTolerance())
{
cpoint.getPosition().setAddMul4(posA,cptr.m_kNearestPoint,triB->getRadius()-cptr.distance);
cpoint.setSeparatingNormal(cptr.m_kNearestPoint,cptr.distance-radiusSum);
if(res==TriangleDistanceUtility::HIT_TRIANGLE_FACE)
{
return ST_CP_FACE;
}
else
{
return ST_CP_EDGE;
}
}
return ST_CP_MISS;}

// @fnv 0x00d3d8c0
void __cdecl FUN_00d3d8c0(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "SphereTri";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock47;
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
TriangleDistanceUtility::FourRealValueRecord cache;
TriangleDistanceUtility::setupClosestPointTriangleCache(triB->GetIndexedVertices(),cache);
ContactPointPair event(bodyA,bodyB);
MaterialIndexedTriangle featureOutput;
if(hkpSphereTriangleAgent::getClosestPointInl(bodyA,bodyB,input,cache,event.m_kPoint,&featureOutput))
{
hkUchar m_uiMaterialIndex=featureOutput.m_uiMaterialIndex;
if(input.m_collisionQuality.val()&&m_uiMaterialIndex>0)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
hkVec4X weldedNormal=event.m_kPoint.getSeparatingNormal();
hkVec4X pointPos=event.m_kPoint.getPosition();
hkpConvexShape::WeldResult weldResult=triB->weldContactPoint(&featureOutput.m_auiVertexIds[0],m_uiMaterialIndex,pointPos,&bodyB.getTransform(),sphereA,&bodyA.getTransform(),weldedNormal);
if(weldResult==hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT)
{
return;
}
else if(weldResult==hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED)
{
event.m_kPoint.setNormal(weldedNormal);
}
}
collector.AddCdPoint(event);
}
}

#include "generated/data/staging/blk_00d20000_od_o2_nood_variant.inc"
#include "generated/data/staging/blk_00d20000_od_o2_nood_variant_rtm_variant.inc"
