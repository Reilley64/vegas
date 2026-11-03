
// src/staging/blk_009c0000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_009c0000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_009c0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "fnv/decl/Actor.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_009795c0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009c5af0__FUN_009c5af0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0070c000.h"
#include "fnv/symbols_009c0000.h"
#include "fnv/symbols_011de000.h"
#include "../../include/layout_support.h"

struct xP3
{
    xP3();
    float x, y, z;
    xP3 operator-(const xP3&) const;
};
struct xFilter
{
    xFilter(int);
    unsigned int m_uiFilterValue;
};
struct xAllHits
{
    xAllHits();
    virtual ~xAllHits();
    int m_q[0xc7];
};
struct __declspec(align(16)) xPick
{
    xPick();
    void FUN_004a3f70(xFilter);
    char m_buf[0xb0];
};
struct xWorld
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual bool FUN_c8(xPick*);
};

struct xCell;
struct xOwner
{
    xFilter FUN_0070c440();
};
struct xActor;
struct xActor
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
    char m_pad04[0xf8];
    xActor* m_fc;
    xFilter FUN_00931ed0();
    bool FUN_009c40c0();
};

// @fnv 0x009c40c0
bool xActor::FUN_009c40c0()
{
    if (m_fc != (*reinterpret_cast<::xActor * *>(&::_g_thePlayer)))
        return false;
    xPick PICK;
    xP3 PLPOS;
    xP3 MYPOS;
    xP3 DIR;
    MYPOS = *FUN_1f4();
    PLPOS = *(*reinterpret_cast<::xActor * *>(&::_g_thePlayer))->FUN_1f4();
    PLPOS.z = PLPOS.z + ::FUN_0070c3b0((::FUN_0070c3b0_Dummy *)((*reinterpret_cast<::xActor * *>(&::_g_thePlayer)))) * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>(((*reinterpret_cast<::xActor * *>(&::_g_thePlayer))))->FUN_00567400();
    DIR = MYPOS - PLPOS;
    xOwner* OWNER = ((::xOwner *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    xFilter FILTER(0);
    if (OWNER)
        FILTER = OWNER->FUN_0070c440();
    else
        FILTER = (*reinterpret_cast<::xActor * *>(&::_g_thePlayer))->FUN_00931ed0();
    reinterpret_cast<::FUN_004a39f0_shell *>(&(FILTER))->FUN_004a39f0(6);
    PICK.FUN_004a3f70(FILTER);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(PICK))->FUN_004a3da0(&PLPOS);
    reinterpret_cast<::Class_007f68a0 *>(&(PICK))->FUN_007f68a0((*(const ::NiPoint3 *)(&DIR)));
    xAllHits HITS;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(PICK))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::xAllHits *)(&HITS));
    xWorld* WORLD = ((::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::xCell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::xActor * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
    bool RES = WORLD->FUN_c8(&PICK);
    float DIST = 3.402823466e+38F;
    RES = RES | reinterpret_cast<::fnv_009c5af0::FUN_009c5af0_shell *>(this)->GetWaterPlaneIntersection((::fnv_009c5af0::Proxy *)(::xPick *)(&PICK), &DIST);
    if (RES)
        RES = ::FUN_009c0d80((::Scene *)(::xPick *)(&PICK), (::Controller *)(::xActor *)(this), (int)(((void *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))), (float *)(0), 1, DIST) != 0;
    if (RES)
        reinterpret_cast<::FUN_009795c0_shell *>(this)->FUN_009795c0(0.0f);
    return RES;
}
