
// src/fallout_shared/tesvalueform_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesvalueform.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/tesvalueform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesvalueform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/symbols_00421000.h"
#include "fnv/symbols_011de000.h"
struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};

struct TESValueForm : BaseFormComponent
{
    void SetFormValue(unsigned int);
    void FUN_0048e7f0(BaseFormComponent*);
};

// @fnv 0x0048e7f0
void TESValueForm::FUN_0048e7f0(BaseFormComponent* component)
{
    TESValueForm* form = dynamic_cast<TESValueForm*>(component);
    if (!form)
        return;
    SetFormValue(((unsigned int)(reinterpret_cast<::Callees *>((form))->FUN_00726070())));
}

namespace fnv_0048e9b0 {
struct TESValueForm
{
    unsigned short FUN_0048e9b0(unsigned int aiFlags);
};

// @fnv 0x0048e9b0
unsigned short TESValueForm::FUN_0048e9b0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    if (aiFlags & 2)
        isize += 4;
    return isize;
}
}  // namespace fnv_0048e9b0

namespace fnv_0048e9e0 {
struct TESSaveLoadGame
{
};

struct TESValueForm
{
    void FUN_0048e9e0(unsigned int flags);
};

// @fnv 0x0048e9e0
void TESValueForm::FUN_0048e9e0(unsigned int flags)
{
    if (flags & 2)
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0048e9e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(reinterpret_cast<char*>(this) + 4, 4);
}
}  // namespace fnv_0048e9e0

namespace fnv_0048ea10 {
struct TESSaveLoadGame
{
};

struct TESValueForm
{
    void FUN_0048ea10(unsigned int a, unsigned int b);
};

// @fnv 0x0048ea10
void TESValueForm::FUN_0048ea10(unsigned int a, unsigned int b)
{
    if (a & 2)
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0048ea10::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0((char*)this + 4, 4);
}
}  // namespace fnv_0048ea10

namespace fnv_0048ea40 {
struct FormChangeMask
{
    int flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(int);
};
struct BGSSaveFormBuffer
{
};
struct TESValueForm
{
    void FUN_0048ea40(BGSSaveFormBuffer*);
};
// @fnv 0x0048ea40
void TESValueForm::FUN_0048ea40(BGSSaveFormBuffer* aBuffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_0048ea40::FormChangeMask &)(((BGSLoadFormBuffer*)aBuffer)->GetChangeFlags(2)))->FUN_004280f0())
        reinterpret_cast<::FUN_00865e50_shell *>((aBuffer))->FUN_00865e50((char*)this + 4, 4, 0);
}
}  // namespace fnv_0048ea40

struct FormChangeMask
{
    unsigned int flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};
struct FUN_0048ea80_Class
{
    void FUN_0048ea80(BGSLoadFormBuffer* buffer);
};
// @fnv 0x0048ea80
void FUN_0048ea80_Class::FUN_0048ea80(BGSLoadFormBuffer* buffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(2)))->FUN_004280f0())
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 4), 4);
}

struct BaseData
{
};
struct Item
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
    virtual bool v64();
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
    virtual bool v134();
};
struct Collection
{
    int unk00;
};
struct Holder
{
    int unk00;
    Collection items;
    Item* FUN_00970a20(void*, int);
};
// @fnv 0x00970a20
Item* Holder::FUN_00970a20(void* key, int unused)
{
    Item* current = 0;
    Item* result = 0;
    for (unsigned int index = 0; index < reinterpret_cast<::FUN_005be5c0_shell *>(&(items))->FUN_005be5c0(0); index++)
    {
        result = ((::Item *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>(&(items))->FUN_00968670(index)));
        if (result && !current && !reinterpret_cast<::FUN_00576d30_shell *>((result))->FUN_00576d30())
        {
            Item* actor = 0;
            if (result && result->v64())
                actor = result;
            if (actor)
            {
                void* target = 0;
                if (actor->v134())
                    target = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((actor))->FUN_007af430()));
                if (target && key == target)
                    current = actor;
                else if (((void *)(::FUN_004216f0((::BaseExtraList *)(((::BaseData *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0())))))) == key)
                    current = actor;
            }
        }
    }
    return current;
}

struct FUN_0048e840_shell
{
    bool FUN_0048e840(BaseFormComponent* other);
};

// @fnv 0x0048e840
bool FUN_0048e840_shell::FUN_0048e840(BaseFormComponent* other)
{
    TESValueForm* form = dynamic_cast<TESValueForm*>(other);
    if (!form)
        return true;
    if (((unsigned int)(reinterpret_cast<::Callees *>((reinterpret_cast<TESValueForm*>(this)))->FUN_00726070())) != ((unsigned int)(reinterpret_cast<::Callees *>((form))->FUN_00726070())))
        return true;
    return false;
}
