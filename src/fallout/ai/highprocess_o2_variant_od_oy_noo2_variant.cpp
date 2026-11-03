
// src/fallout/ai/highprocess_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/highprocess_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/highprocess_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/highprocess.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "fnv/decl/Actor87.h"
#include "fnv/decl/Actor897.h"
#include "fnv/decl/B968730Actor.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C.h"
#include "fnv/decl/C901C50Object.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Date.h"
#include "fnv/decl/DialogueItem_shell.h"
#include "fnv/decl/ExtraDataListRemoveTrespassPackage.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_0041cd70_shell.h"
#include "fnv/decl/FUN_00422820_shell.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00437b90_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047d7c0_Class.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00497f20_shell.h"
#include "fnv/decl/FUN_00498d30_t.h"
#include "fnv/decl/FUN_0049bb50_shell.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004b4e50_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_0050ead0_cls.h"
#include "fnv/decl/FUN_0050eb90_Class.h"
#include "fnv/decl/FUN_00544490_Class.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_0059f610Class.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005ff160_shell.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_0067a480_shell.h"
#include "fnv/decl/FUN_0067a770_shell.h"
#include "fnv/decl/FUN_0067efd0_shell.h"
#include "fnv/decl/FUN_0067f1c0_shell.h"
#include "fnv/decl/FUN_0083d0d0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_00884f80_shell.h"
#include "fnv/decl/FUN_0088c570_shell.h"
#include "fnv/decl/FUN_008a7570_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008adcb0_shell.h"
#include "fnv/decl/FUN_008b0bd0_shell.h"
#include "fnv/decl/FUN_008b2010_shell.h"
#include "fnv/decl/FUN_008b39f0_shell.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_008bc700_shell.h"
#include "fnv/decl/FUN_008c0050_cls.h"
#include "fnv/decl/FUN_008c51c0_shell.h"
#include "fnv/decl/FUN_008ce390_shell.h"
#include "fnv/decl/FUN_008d72e0_Class.h"
#include "fnv/decl/FUN_008d7340StandIn.h"
#include "fnv/decl/FUN_008d7420.h"
#include "fnv/decl/FUN_008d74a0.h"
#include "fnv/decl/FUN_008dade0_shell.h"
#include "fnv/decl/FUN_008ff080_shell.h"
#include "fnv/decl/FUN_008ffdc0_Class.h"
#include "fnv/decl/FUN_009003e0_shell.h"
#include "fnv/decl/FUN_00900400_shell.h"
#include "fnv/decl/FUN_00903cd0_shell.h"
#include "fnv/decl/FUN_00905450_StandIn.h"
#include "fnv/decl/FUN_00915400_shell.h"
#include "fnv/decl/FUN_0091fe80_shell.h"
#include "fnv/decl/FUN_009280f0_Class.h"
#include "fnv/decl/FUN_0092bf20_cls.h"
#include "fnv/decl/FUN_0092ce00_shell.h"
#include "fnv/decl/FUN_00953c20_shell.h"
#include "fnv/decl/FUN_00953c50_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009865b0_shell.h"
#include "fnv/decl/FUN_00992530_shell.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/FormNode.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/Owner0092cec0.h"
#include "fnv/decl/Owner8ffe50.h"
#include "fnv/decl/Ref.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/S0056e810_Object.h"
#include "fnv/decl/ST_008c8bb0.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/Self.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESNPC_Sub.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/UpdateOwner.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0041cc90__ExtraDataListStandIn.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_004985f0__FUN_004985f0_s.h"
#include "fnv/decl/fnv_00498f80__FUN_00498f80_cls.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00567490__ScaleReference.h"
#include "fnv/decl/fnv_005710c0__ModelRef.h"
#include "fnv/decl/fnv_00572380__Fn572380.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0084a810__FUN_0084a810_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_0089f580__ActorStub.h"
#include "fnv/decl/fnv_008a5e80__FakeActor.h"
#include "fnv/decl/fnv_008a7870__FUN_008a7870_shell.h"
#include "fnv/decl/fnv_008a78f0__FUN_008a78f0_shell.h"
#include "fnv/decl/fnv_008ac6f0__ActorS_008ac6f0.h"
#include "fnv/decl/fnv_008acbe0__FUN_008acbe0_shell.h"
#include "fnv/decl/fnv_008b8e90__FUN_008b8e90_shell.h"
#include "fnv/decl/fnv_008bcc80__FUN_008bcc80_shell.h"
#include "fnv/decl/fnv_008bffc0__FUN_008bffc0_shell.h"
#include "fnv/decl/fnv_008ffd10__FUN_008ffdc0_Class.h"
#include "fnv/decl/fnv_00903de0__FUN_00903de0_shell.h"
#include "fnv/decl/fnv_00903e00__FUN_00903e00_shell.h"
#include "fnv/decl/fnv_00903e20__FUN_00903e20_shell.h"
#include "fnv/decl/fnv_00904160__FUN_00904160_shell.h"
#include "fnv/decl/fnv_009278d0__Target.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00972570__FUN_00972570_shell.h"
#include "fnv/decl/fnv_00992480__CombatOwner_SV.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0047e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00546000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_005cc000.h"
#include "fnv/symbols_005d9000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00642000.h"
#include "fnv/symbols_00669000.h"
#include "fnv/symbols_008d7000.h"
#include "fnv/symbols_00903000.h"
#include "fnv/symbols_00a6e000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01268000.h"
#include "highprocess_decls.h"

struct xPoint3
{
    float x, y, z;
};
struct xHeaderOwner
{
};
struct xBuf;
struct xProcess
{
    void* vtbl;
public:
    void FUN_00927000(::xBuf *);
};
struct xFilter
{
    xFilter(int);
    unsigned int m_uiFilterValue;
};
struct xHasFilter
{
    xFilter FUN_0070c440();
};
struct xVec4
{
    float m_q[4];
};
struct __declspec(align(16)) xCinfo
{
    xCinfo();
    ~xCinfo();
    unsigned int m_uiFilterInfo;
    int m_pCollisionShape;
    int m_pad08[18];
    xVec4 m_vContactPosition;
};
struct xNiAlloc
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct xShape : xNiAlloc
{
    xShape(xPoint3*);
    int m_auiShapeKeys[5];
};
struct xBody : xNiAlloc
{
    xBody(xCinfo*);
    int m_auiShapeKeys[6];
};
struct xBodyV;
struct xPtr
{
    xBodyV* operator->();
    void FUN_0066b0d0(void*);
};
struct xWorldUser
{
    virtual void v0();
};
struct xBodyV
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void FUN_9c(void*);
};
struct xCell
{
    void* FUN_008d6f30();
};
struct xSetting
{
};
struct xMiddle
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
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual xHeaderOwner* FUN_5f0();
};
struct xP3;
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
    virtual xPoint3* FUN_1f4();
    char m_pad04[0x64];
    xMiddle* m_68;
    xCell* FUN_008d6f30();
public:
    bool FUN_0088c240(const ::xP3 &, bool, bool);
};
struct xController
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
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual xHasFilter* FUN_28c();
    char m_pad04[0x430];
    xPtr m_434;
    float m_438;
    void FUN_008e4e50(xActor* apActor);
};

// @fnv 0x008e4e50
void xController::FUN_008e4e50(xActor* apActor)
{
    if (apActor->m_68->FUN_5f0())
    {
        if (!((unsigned int)(::FUN_00559450((int *)&(m_434)))))
        {
            xPoint3 HALF = *((::xPoint3 *)(reinterpret_cast<::BGSCameraPath *>((apActor->m_68->FUN_5f0()))->GetConditions()));
            float fActorScale = reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((apActor))->FUN_00567400();
            if (HALF.y > HALF.z)
                HALF.y = HALF.y * fActorScale;
            else
                HALF.y = HALF.y * 2.5 * fActorScale;
            HALF.x = HALF.x * 0.5 * fActorScale;
            HALF.z = HALF.z * fActorScale;
            xShape* SHAPE = new xShape(&HALF);
            xFilter FILTER(0);
            reinterpret_cast<::FUN_004a39f0_shell *>(&(FILTER))->FUN_004a39f0(0x22);
            xHasFilter* OWNER = FUN_28c();
            if (OWNER)
                reinterpret_cast<::FUN_0059ce80_shell *>(&(FILTER))->FUN_0059ce80(((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::xFilter &)(OWNER->FUN_0070c440()))->FUN_004a3a20())));
            xCinfo CINFO;
            CINFO.m_uiFilterInfo = ((unsigned int)(::FUN_00559450((int *)&(FILTER))));
            CINFO.m_pCollisionShape = ::FUN_004ae750(SHAPE);
            reinterpret_cast<::FUN_004b4e50_shell *>(&(CINFO.m_vContactPosition))->SetFromScaledVector3((void *)(apActor->FUN_1f4()));
            m_434.FUN_0066b0d0(new xBody(&CINFO));
            m_438 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::g_011e029c))))));
        }
        void* WORLD = reinterpret_cast<::FUN_004543c0_cls *>((((::xCell *)(reinterpret_cast<::LowProcess *>((apActor))->GetTarget()))))->FUN_004543c0();
        m_434->FUN_9c(WORLD);
    }
}

namespace fnv_008e5100 {
struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4();
};
struct xConvexShape
{
    xConvexShape();
    virtual ~xConvexShape();
    int m_iWordAt04, m_8, m_iThirdValue;
};
struct xBoxShape : xConvexShape
{
    xBoxShape(const xP3& akHalfExtents);
    virtual ~xBoxShape();
    int m_10;
};
// @fnv 0x008e5100
xBoxShape::xBoxShape(const xP3& akHalfExtents)
{
    ++::DAT_0126825c;
    xVec4 HALF;
    reinterpret_cast<::S0056e810_Object *>(this)->FUN_0056e810((*(const ::S0056e810_Vector *)(((::fnv_008e5100::xVec4 *)&(::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&HALF)), (const ::fnv_004a3e00::NiPoint3 &)(akHalfExtents)))))));
}
}  // namespace fnv_008e5100
