
// src/fallout_shared/havok/foislandactivationlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/foislandactivationlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

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

// @fnv 0x00624ad0
NiTransform* FUN_00624ad0(NiTransform* arNiTran, TopicH* arTopicH)
{
    ::FUN_00624b10((::FUN_004769c0_shell *)(arNiTran), (::FUN_004b4cf0_shell *)(::NiPoint3 *)(&(*(::NiPoint3 *)(new ((void *)(arTopicH)) ::Vec3()))));
    SetNiPoint3FromHkVector4(*(NiPoint3*)((char*)arNiTran + 0x24), *(const hkVector4*)((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((arTopicH))->GetAddTopicList())));
    return arNiTran;
}

struct NiTArray
{
};
struct FUN_006228e0_shell
{
    unsigned short m_iElementCount;
    unsigned short m_cap;
    unsigned int FUN_006228e0(unsigned int, void*);
};
// @fnv 0x006228e0
unsigned int FUN_006228e0_shell::FUN_006228e0(unsigned int n, void* p)
{
    if (n >= *(unsigned short*)((char*)this + 8))
        reinterpret_cast<::NiTObjectArrayA47 *>((((NiTArray*)this)))->FUN_0060bef0(*(unsigned short*)((char*)this + 0xe) + n);
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
    int blood = ::FUN_00c7fa90((::S_Obj *)((int)p));
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
unsigned int GetBSXFlags(unsigned int a, unsigned int uiFlags)
{
    BSXFlags* p = (BSXFlags*)((unsigned int)(::GetExtraDataChecked((::NiAVObjectX *)(a))));
    return p ? reinterpret_cast<::FUN_00448a60_struct *>((p))->GetMaskedValue(uiFlags) : 0;
}

struct FUN_00c91840_shell
{
};
struct FUN_00c917a0_shell
{
};
struct FUN_006242f0_shell
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
        reinterpret_cast<::hkWorldC917 *>((((FUN_00c917a0_shell*)listener)))->FUN_00c917a0(this ? (char*)this + 4 : 0);
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
            if (reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::CF845 &)(CF845(((int)(::FUN_0043b540((char *)(((::Type8 *)(::FUN_00460140((int)(apArg)))))))))))->FUN_0043b4d0() == 0x14)
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
    int iItemCount = ((int)(reinterpret_cast<::Callees *>((count))->FUN_00726070()));
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
