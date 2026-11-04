
// src/fallout_shared/havok/foislandactivationlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/foislandactivationlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_00448a60_struct.h"
#include "fnv/decl/FUN_0047b4d0_Class.h"
#include "fnv/decl/FUN_00622920_Array.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_00c9bff0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiShader.h"
#include "fnv/decl/NiTObjectArrayA47.h"
#include "fnv/decl/ObjectTable.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00c93820__hkpWorldC938.h"
#include "fnv/decl/fnv_00c938a0__hkpWorldXc938a0.h"
#include "fnv/decl/hkWorldC917.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_0054a000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00c43000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/decl/FUN_0042e250_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/S00b5d9f0_Owner.h"
#include "fnv/decl/_dummy_476a80.h"
#include "fnv/decl/_dummy_4d9fa0.h"
#include "fnv/decl/fnv_00548880__FNV_Cell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_011ca000.h"
#include <xmmintrin.h>
struct hkpIslandActivationListener
{
    void* FUN_006241e0(unsigned int);
};


struct FUN_00624210_shell
{
    int* m_ptr;
    void InitPtr();
};
// Calls InitPtr, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006241e0
void* hkpIslandActivationListener::FUN_006241e0(unsigned int flags)
{
    reinterpret_cast<::FUN_00624210_shell *>(this)->InitPtr();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00624210
void FUN_00624210_shell::InitPtr()
{
    m_ptr = &DAT_0104de10;
}

extern int DAT_011f942c;

// @fnv 0x00624bd0
void FUN_00624bd0()
{
    DAT_011f942c = 0;
}

struct NiPoint3
{
    float x, y, z;
};
struct hkVector4;
struct NiTransform;
struct TopicH
{
};

// NiTransform is incomplete here: the rotation matrix comes before the translation.
struct NiTransformView
{
    char kRotate[0x24];
    char kTranslation[0xc];
};
// @fnv 0x00624ad0
NiTransform* FUN_00624ad0(NiTransform* arNiTran, TopicH* arTopicH)
{
    ::FUN_00624b10((::FUN_004769c0_shell *)(arNiTran), (::FUN_004b4cf0_shell *)(::NiPoint3 *)(&(*(::NiPoint3 *)((void *)(arTopicH)))));
    SetNiPoint3FromHkVector4(*reinterpret_cast<NiPoint3*>(reinterpret_cast<NiTransformView*>(arNiTran)->kTranslation), *(const hkVector4*)((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((arTopicH))->GetAddTopicList())));
    return arNiTran;
}

struct NiTArray
{
};
struct FUN_006228e0_shell
{
    const void* pVtable;
    void* pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int FUN_006228e0(unsigned int, void*);
};
// @fnv 0x006228e0
unsigned int FUN_006228e0_shell::FUN_006228e0(unsigned int n, void* p)
{
    if (n >= m_usMaxSize)
        reinterpret_cast<::NiTObjectArrayA47 *>((((NiTArray*)this)))->FUN_0060bef0(m_usGrowBy + n);
    reinterpret_cast<::FUN_00622920_Array *>(this)->SetAt(n, (*(const ::NiPointer< ::NiAVObject> *)(p)));
    return n;
}

struct FUN_00624190_shell
{
    void FUN_00624230();
    void* FUN_00624190(unsigned int flags);
};
struct FUN_006241c0_shell
{
    int* m_ptr;
    FUN_006241c0_shell();
};

// @fnv 0x006241c0
FUN_006241c0_shell::FUN_006241c0_shell()
{
    m_ptr = &DAT_0104de10;
}

struct TESObjectREFR
{
};
struct FUN_00807730_shell
{
    TESObjectREFR* FUN_00807730(void* p);
};
// Calls FUN_00c7fa90 on p; if it returns non-zero, resolves that value to a TESObjectREFR and returns it, otherwise returns null.
// @fnv 0x00807730
TESObjectREFR* FUN_00807730_shell::FUN_00807730(void* p)
{
    TESObjectREFR* result = 0;
    std::intptr_t blood = ::FUN_00c7fa90((::S_Obj *)(p));
    if (blood)
        result = ::FUN_0056f930((::NiAVObject *)(void *)((void*)blood));
    return result;
}

extern int DAT_011f942c;

// @fnv 0x00624560
void __cdecl FUN_00624560()
{
    DAT_011f942c = DAT_011f942c + 1;
}

struct FUN_00573eb0_Class
{
    int FUN_0047b4d0(int);
    int FUN_00624bb0();
};

int FUN_00573eb0_Class::FUN_0047b4d0(int)
{
    return ((int)(reinterpret_cast<::FUN_0047b4d0_Class *>(this)->FUN_0047b4d0(8)));
}

// @fnv 0x00624bb0
int FUN_00573eb0_Class::FUN_00624bb0()
{
    return ((int)(reinterpret_cast<::FUN_0047b4d0_Class *>(this)->FUN_0047b4d0(8)));
}

struct BSXFlags
{
};
// @fnv 0x00624b70
unsigned int GetBSXFlags(std::uintptr_t a, unsigned int uiFlags)
{
    BSXFlags* p = (BSXFlags*)((::GetExtraDataChecked((::NiAVObjectX *)(a))));
    return p ? reinterpret_cast<::FUN_00448a60_struct *>((p))->GetMaskedValue(uiFlags) : 0;
}

struct FUN_00c91840_shell
{
};
struct FUN_00c917a0_shell
{
};
// The island activation listener's primary base and the listener base the havok world keeps.
struct IslandListenerPrimaryView
{
    const void* pVtable;
};
struct IslandListenerSecondaryView
{
    const void* pListenerVtable;
};
struct FUN_006242f0_shell : IslandListenerPrimaryView, IslandListenerSecondaryView
{
    void NotifyListener(void*);
};
// If listener is non-null, calls its RemovePointer with this and its FUN_00c917a0 with this+4.
// @fnv 0x006242f0
void FUN_006242f0_shell::NotifyListener(void* listener)
{
    if (listener)
    {
        reinterpret_cast<::ObjectTable *>((((FUN_00c91840_shell*)listener)))->RemovePointer(this);
        reinterpret_cast<::hkWorldC917 *>((((FUN_00c917a0_shell*)listener)))->FUN_00c917a0(this ? static_cast<IslandListenerSecondaryView*>(this) : 0);
    }
}

struct BaseDtor_b4091
{
    virtual void unk00();
    ~BaseDtor_b4091();
};

struct MemberDtor_b4091
{
    virtual void unk00();
    ~MemberDtor_b4091();
};

struct FUN_00624230 : BaseDtor_b4091, MemberDtor_b4091
{
    virtual void unk08();
    ~FUN_00624230();
};
// Calls FUN_00624230, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00624190
void* FUN_00624190_shell::FUN_00624190(unsigned int flags)
{
    reinterpret_cast<::FUN_00624230 *>(this)->FUN_00624230::~FUN_00624230();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00624230
FUN_00624230::~FUN_00624230()
{}

struct hkVector4;

struct NiPoint3_local
{
    float x, y, z;
    NiPoint3_local();
};


struct FUN_004b4cf0_shell
{
    hkVector4* FUN_004b4cf0(unsigned int i);
};

struct FUN_004769c0_shell
{
    void FUN_004769c0(unsigned int i, float* p);
};

// @fnv 0x00624b10
FUN_004769c0_shell* FUN_00624b10(FUN_004769c0_shell* dest, FUN_004b4cf0_shell* src)
{
    NiPoint3_local vec;

    for (unsigned int i = 0; i < 3; i++)
    {
        ::FUN_004a3970(vec, *src->FUN_004b4cf0(i));
        dest->FUN_004769c0(i, (float*)&vec);
    }

    return dest;
}

struct ActivationBaseA
{
    int value;
};
struct ActivationBaseB
{
    int value;
};
struct ActivationListener
{
};
struct FUN_006242a0_cls : ActivationBaseA, ActivationBaseB
{
    void NotifyActivation(ActivationListener* listener);
};
// If listener is non-null, calls its FUN_00c938a0 with this and its FUN_00c93820 with this cast to ActivationBaseB.
// @fnv 0x006242a0
void FUN_006242a0_cls::NotifyActivation(ActivationListener* listener)
{
    if (listener)
    {
        reinterpret_cast<::fnv_00c938a0::hkpWorldXc938a0 *>((listener))->FUN_00c938a0((::fnv_00c938a0::hkpEntityListenerXc938a0 *)(void *)(this));
        reinterpret_cast<::fnv_00c93820::hkpWorldC938 *>((listener))->FUN_00c93820((::fnv_00c93820::hkpEntityListenerC938 *)(::ActivationBaseB *)(static_cast<ActivationBaseB*>(this)));
    }
}

struct FUN_005609f0_shell
{
    char m_val;
    FUN_005609f0_shell(const FUN_005609f0_shell&);
    bool FUN_005609f0();
};

struct Type8
{
};

struct ArgType
{
};

struct CF845
{
    int m_val;
    CF845(int);
};

class NiRTTI;

struct Type2;
struct Type5;

struct Type4
{
};

struct Type3
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool vfunc_100();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual bool vfunc_150();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void* vfunc_1d0(int);

};

struct Type5
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void vfunc_dc(void*);
};

struct Type7
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void vfunc_e4(int);
};

struct Type1
{
};


struct FUN_00624340_shell
{
    void ProcessArgType(ArgType* arg1);
};

// @fnv 0x00624340
void FUN_00624340_shell::ProcessArgType(ArgType* apArg)
{
    if (apArg)
    {
        Type3* kVar4;
        Type2* _var8;
        Type1* varC6;
        Type4* varX;
        Type5* var5;
        Type3* var18;
        Type2* var1C8;
        Type1* var2;
        void* varVal;
        Type7* var3;

        if ((*(::FUN_005609f0_shell *)(reinterpret_cast<::FUN_00c9bff0_Class *>((apArg))->FUN_00c9bff0({}))).FUN_005609f0())
        {
            varC6 = ((::Type1 *)(::NiShader::DynamicCast((::NiAVObject *)(apArg))));
            _var8 = varC6 ? ((::Type2 *)(reinterpret_cast<::Twin_0044ddc0 *>((varC6))->GetName())) : 0;
            kVar4 = _var8 ? ((::Type3 *)(::FUN_0056f930((::NiAVObject *)(_var8)))) : 0;
            if (kVar4 && !kVar4->vfunc_100())
            {
                varX = ((::Type4 *)(reinterpret_cast<::LowProcess *>((kVar4))->GetTarget()));
                var5 = varX ? ((::Type5 *)(reinterpret_cast<::TESObjectCELL *>((varX))->GetDynamicNode())) : 0;
                if (var5)
                {
                    if (FUN_008c7aa0())
                    {
                        ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(kVar4), (::NiNode *)(var5));
                    }
                    else
                    {
                        var5->vfunc_dc(kVar4->vfunc_1d0(1));
                    }
                }
                if (kVar4->vfunc_150())
                {
                    FUN_00624560();
                }
            }
        }
        else
        {
            if (reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::CF845 &)(CF845(((int)(::FUN_0043b540((char *)(((::Type8 *)(::FUN_00460140((std::intptr_t)(apArg)))))))))))->FUN_0043b4d0() == 0x14)
            {
                var2 = ((::Type1 *)(::NiShader::DynamicCast((::NiAVObject *)(apArg))));
                var1C8 = var2 ? ((::Type2 *)(reinterpret_cast<::Twin_0044ddc0 *>((var2))->GetName())) : 0;
                var18 = var1C8 ? ((::Type3 *)(::FUN_0056f930((::NiAVObject *)(var1C8)))) : 0;
                if (var18 && !var18->vfunc_100())
                {
                    varVal = ::FUN_004b5a80(apArg);
                    if (varVal && ::FUN_0043b300(&(*reinterpret_cast<::NiRTTI *>(&::g_012681c0)), (::NiAVObject *)(varVal)))
                    {
                        var3 = (Type7*)varVal;
                        var3->vfunc_e4(4);
                    }
                }
            }
        }
    }
}

namespace fnv_00624580 {
struct SceneList
{
};
struct Geometry
{
};
struct SceneObject
{
};
struct FUN_00624580_Class
{
    void FUN_00624580(SceneList* object);
};
// @fnv 0x00624580
void FUN_00624580_Class::FUN_00624580(SceneList* pSceneList)
{
    if (!pSceneList)
        return;
    SceneList* count = ((::fnv_00624580::SceneList *)(reinterpret_cast<::FUN_00624700_shell *>((pSceneList))->FUN_00624700()));
    std::intptr_t iItemCount = ((std::intptr_t)(reinterpret_cast<::Callees *>((count))->FUN_00726070()));
    void* pEntry;
    for (int sceneObject = 0; sceneObject < iItemCount; ++sceneObject)
    {
        pEntry = *((void **)&(reinterpret_cast<::FUN_00629ab0_shell *>((count))->FUN_00629ab0(sceneObject)));
        Geometry* handle = ((::fnv_00624580::Geometry *)(::NiShader::DynamicCast((::NiAVObject *)(pEntry))));
        Geometry* geometry = handle ? ((::fnv_00624580::Geometry *)(reinterpret_cast<::Twin_0044ddc0 *>((handle))->GetName())) : 0;
        SceneObject* parent = geometry ? ((::fnv_00624580::SceneObject *)(::FUN_0056f930((::NiAVObject *)(geometry)))) : 0;
        if (parent)
        {
            typedef unsigned char(* Predicate)(SceneObject*);
            typedef void(* Dispatch)(SceneObject*, int);
            typedef int(* Retrieve)(SceneObject*, int);
            if (!reinterpret_cast<Predicate>((*reinterpret_cast<void***>(parent))[64])(parent))
            {
                reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(parent))[18])(parent, 4);
                Geometry* target;
                Geometry* owner = ((::fnv_00624580::Geometry *)(reinterpret_cast<::LowProcess *>((parent))->GetTarget()));
                target = owner ? ((::fnv_00624580::Geometry *)(reinterpret_cast<::TESObjectCELL *>((owner))->GetDynamicNode())) : 0;
                if (target)
                {
                    if (::FUN_008c7aa0())
                        ::fnv_0054abd0::FUN_0054abd0((::TESObjectREFR *)(parent), (::NiNode *)(target));
                    else
                        reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(target))[55])(
                            reinterpret_cast<SceneObject*>(target),
                            reinterpret_cast<Retrieve>((*reinterpret_cast<void***>(parent))[116])(parent, 1));
                }
                if (reinterpret_cast<Predicate>((*reinterpret_cast<void***>(parent))[84])(parent))
                    ::FUN_00624560();
            }
        }
    }
}
}  // namespace fnv_00624580

void FUN_00624bd0();

// FUN_00624be0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x4 ; jmp FUN_00624190
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is therefore the size of the primary base, which here
// is just a vtable pointer (4 bytes).  Both bases declare the same virtual
// function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the
// adjusting thunk.
struct IslandPrimaryBase
{
    virtual void FUN_00624be0();
};

struct IslandSecondaryBase
{
    virtual void FUN_00624be0();
};

struct IslandDerived : IslandPrimaryBase, IslandSecondaryBase
{
    IslandDerived();
// @fnv 0x00624be0
    virtual void FUN_00624be0();
};

IslandDerived::IslandDerived()
{}

struct Node96;

struct Ref96;

struct Physics96;

struct Geometry96;

struct Input96
{
};

struct Array96
{
};

struct Extra96
{
};

struct Cell96
{
};

struct Ref96
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual bool IsDisabled();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual bool NeedsUpdate();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual std::uintptr_t GetNode();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual bool NeedsReset();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void Reset();
};

struct FUN_0056ded0
{
    __m128 x, y, z, position;
    FUN_0056ded0();
};

struct NiTransform
{
    float a00, a01, a02, a10, a11, a12, a20, a21, a22;
    NiPoint3 translation;
    float scale;
};

struct Geometry96
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void SetFlags(int);
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void GetTransform(FUN_0056ded0*);
};

struct Physics96
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void SetTransform(NiTransform*);
};

struct Descriptor96
{
};

struct Node96
{
};

struct Filter96
{
    int value;
    Filter96(int);
};

struct Shadow96
{
};

struct Manager96
{
    void FUN_00624720(Input96*);
};

// @fnv 0x00624720
void Manager96::FUN_00624720(Input96* input)
{
    if (!input)
        return;
    Array96* items = ((::Array96 *)(reinterpret_cast<::FUN_00624700_shell *>((input))->FUN_00624700()));
    std::intptr_t count = ((std::intptr_t)(reinterpret_cast<::Callees *>((items))->FUN_00726070()));
    for (int i = 0; i < count; i++)
    {
        Node96* node = ((::Node96 *)&(reinterpret_cast<::FUN_00629ab0_shell *>((items))->FUN_00629ab0(i)));
        Physics96* physics = ((::Physics96 *)(::NiShader::DynamicCast((::NiAVObject *)(node))));
        Node96* linked = physics ? ((::Node96 *)(reinterpret_cast<::Twin_0044ddc0 *>((physics))->GetName())) : 0;
        Ref96* ref = linked ? ((::Ref96 *)(::FUN_0056f930((::NiAVObject *)(linked)))) : 0;
        void* model = ref ? ((void *)(reinterpret_cast<::FUN_0042e250_shell *>((((::Extra96 *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->FUN_0042e250())) : 0;
        bool flag8 = ref && GetBSXFlags(ref->GetNode(), 8) ? true : false;
        bool flag128 = ref && GetBSXFlags(ref->GetNode(), 128) ? true : false;
        if (ref)
        {
            if (ref->NeedsReset())
                ref->Reset();
            if (!ref->IsDisabled() && !model && ((flag8 && flag128) || !flag8))
            {
                Cell96* cell = ((::Cell96 *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget()));
                if (cell)
                    reinterpret_cast<::fnv_00548880::FNV_Cell *>((cell))->FUN_00548880((::fnv_00548880::FNV_Ref *)(ref), 0);
                if (ref->NeedsUpdate())
                    FUN_00624bd0();
            }
            else
            {
                if (!ref->IsDisabled())
                    reinterpret_cast<::S00b5d9f0_Owner *>((((::Shadow96 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))))->FUN_00b5d9f0((::S00b5d9f0_Obj *)(ref->GetNode()), 0);
            }
            if (((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == (*reinterpret_cast<void * *>(&::DAT_011ca27c)) || ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())) == (*reinterpret_cast<void * *>(&::DAT_011ca280)))
                ::FUN_00c6a350((::NiAVObject *)(linked), 5, true, false, true);
        }
        if (reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::Filter96 &)(Filter96(((int)(::FUN_0043b540((char *)(((::Descriptor96 *)(::FUN_00460140((std::intptr_t)(node)))))))))))->FUN_0043b4d0() == 20 && ref && !ref->IsDisabled())
        {
            Geometry96* geometry = ((::Geometry96 *)(::FUN_004b5a80(node)));
            if (geometry && ::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012681c0))), (::NiAVObject *)(geometry)))
            {
                Geometry96* target = geometry;
                target->SetFlags(4);
                Physics96* body = ((::Physics96 *)(::NiShader::DynamicCast((::NiAVObject *)(node))));
                if (body && !((bool)(reinterpret_cast<::FUN_00573eb0_Class *>((body))->FUN_00624bb0())))
                {
                    reinterpret_cast<::_dummy_4d9fa0 *>((body))->FUN_00573f00(true);
                    FUN_0056ded0 transform;
                    NiTransform niTransform;
                    reinterpret_cast<::_dummy_476a80 *>(&(niTransform))->FUN_00476a80();
                    target->GetTransform(&transform);
                    FUN_00624ad0(&niTransform, (TopicH*)&transform);
                    body->SetTransform(&niTransform);
                    reinterpret_cast<::_dummy_4d9fa0 *>((body))->FUN_00573f00(false);
                }
            }
        }
    }
}

#include "generated/data/fallout_shared/havok/foislandactivationlistener.inc"
