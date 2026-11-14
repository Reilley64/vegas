// Keeps the NiPointer of layout_support.h, which gives every member a body: on
// fnv/ni_pointer.h this unit's object changes. It uses the destructor and
// operator=(T*).
#define FNV_KEEPS_OWN_NIPOINTER

#include "nitransformcontroller_nimemobject_decl.h"
#include "nitransformcontroller_types_NiCloningProcess.h"
#include "nitransformcontroller_types_NiBoolInterpController.h"
#include "nitransformcontroller_types_NiTransformInterpolator.h"
#include "nitransformcontroller_types_NiControllerSequence__IDTag.h"
#include "nitransformcontroller_stream_decl.h"
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00a39030_cls.h"
#include "fnv/decl/fnv_00a3fa30__FUN_00a3fa30.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/decl/CloneableObj.h"
#include "fnv/decl/FUN_00a40980.h"
#include "fnv/decl/FUN_00a6d290.h"
#include "fnv/decl/Holder00a390a0.h"
#include "fnv/decl/TargetA35.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a39000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_011a8000.h"
#include "fnv/symbols_011f3000.h"
#include <math.h>


struct FUN_00a38e00 : NiSingleInterpController
{
    FUN_00a38e00() throw();
public:
};

class ObjectA36810 : public FUN_00a38e00
{
  public:
    virtual void Dummy();
};

// @fnv 0x00a36810
NiObject* __cdecl FUN_00a36810()
{
    return new ObjectA36810;
}

// FUN_00a360b0 - forwards its single argument to a helper and reports the
// helper's byte sized result as a bool.


// @fnv 0x00a360b0
bool FUN_00a360b0(void* pObject)
{
    return ((unsigned char)(reinterpret_cast<::FUN_00a39030_cls *>((pObject))->IsCompatibleWith({})));
}

class NiTransformData;

// Constructor NiTransformInterpolator::NiTransformInterpolator(NiTransformData*)
struct NiTransformInterpolatorMem
{
};

// NiInterpolator virtual table up to Collapse (slot 47)
struct NiInterpolatorVirtuals
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Collapse();
};

struct FUN_00a361c0_cls : public NiSingleInterpController
{
    void FUN_00a361c0(NiStream& kStream);
};

// @fnv 0x00a361c0
void FUN_00a361c0_cls::FUN_00a361c0(NiStream& kStream)
{
    ::FUN_00a35850();

    unsigned int uiFileVersion = *(unsigned int*)((char*)&kStream + 0xd8);
    if (uiFileVersion < 0x0a010068)
    {
        NiTransformData* pkData = (NiTransformData*)kStream.GetLoadedObject();
        void* pMem = ::operator new(0x48);
        m_spControllerInterpolator = pMem ? ((::NiTransformInterpolator *)(new ((void *)(((NiTransformInterpolatorMem*)pMem))) ::fnv_00a3fa30::FUN_00a3fa30(pkData))) : 0;
        ((NiInterpolatorVirtuals*)m_spControllerInterpolator.m_pObject)->Collapse();
    }
}

struct FUN_00a367c0_helper
{
};
struct FUN_00a38ef0_Class : NiInterpController
{
    NiInterpolator* m_spControllerInterpolator;
    void FUN_00a38ef0(FUN_00a38ef0_Class* pkDest, CloningProcess& kCloning);
};

// @fnv 0x00a367c0
ObjectA36810* FUN_00a367c0(ObjectA36810* pThis, void*, CloningProcess& cloning)
{
    ObjectA36810* pNewInstance = new ObjectA36810;
    reinterpret_cast<::FUN_00a38ef0_Class *>((((FUN_00a367c0_helper*)pThis)))->FUN_00a38ef0((::FUN_00a38ef0_Class *)(pNewInstance), cloning);
    return pNewInstance;
}


struct RefObj
{
    virtual void vf0();
    virtual void vf4();
    volatile long refCount;
};
struct Unknown
{
    void FUN_00a360d0();
};
// @fnv 0x00a360d0
void Unknown::FUN_00a360d0()
{
    RefObj* p = *(RefObj**)((char*)this + 0x34);
    if (p)
    {
        if (InterlockedDecrement(&p->refCount) == 0)
            p->vf4();
    }
    reinterpret_cast<struct ::FUN_00a6d290 *>((this))->FUN_00a6d290::~FUN_00a6d290();
}

struct FakeTransformController : NiSingleInterpController
{
    void FUN_00a36190(NiStream&);
};
// @fnv 0x00a36190
void FakeTransformController::FUN_00a36190(NiStream& kStream)
{
    NiSingleInterpController::LoadBinary(kStream);
    if (*(unsigned int*)((char*)&kStream + 0xD8) < 0x0A010068)
        reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
}


// @fnv 0x00a36480
int* __cdecl FUN_00a36480()
{
    return &(*reinterpret_cast<int *>(&::g_011f371c));
}

void __cdecl _delete(void*, unsigned int);
struct S_00a36490
{
    void* FUN_00a36490(unsigned int);
};
// @fnv 0x00a36490
void* S_00a36490::FUN_00a36490(unsigned int flag)
{
    ::FUN_00a39290(this, {});
    if (flag & 1)
        _delete(this, 0x58);
    return this;
}


// @fnv 0x00a36580
void* __cdecl FUN_00a36580()
{
    return &(*reinterpret_cast<void * *>(&::g_011f36ec));
}

namespace fnv_00a36840 {
struct StrArr
{
    char _pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usPad;
    unsigned short m_usGrowBy;
};
// @fnv 0x00a36840
void FUN_00a36840(StrArr* pkStrings)
{
    reinterpret_cast<::Holder00a390a0 *>((pkStrings))->FUN_00a390a0({});
    char* pszString = ::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f36ec)));
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiSize + pkStrings->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiSize, pszString);
}
}  // namespace fnv_00a36840

struct ThreeByThreeMatrix
{
  private:
    float m_afEntries[3][3];
};

class NiAVObject
{
  public:
    char _pad[0x34];
    ThreeByThreeMatrix m_kRotate;
    NiPoint3 m_kTranslate;
    float m_fScale;
};

struct BSFadeNode
{
};

struct S00a36100
{
    char _pad[0x2c];
    NiAVObject* m_spReferencedObject;

    NiTransformInterpolator* FUN_00a36100(unsigned short usIndex);
};

// @fnv 0x00a36100
NiTransformInterpolator* S00a36100::FUN_00a36100(unsigned short usIndex)
{
    NiAVObject* pkTarget = m_spReferencedObject;
    NiQuaternion kRotate;
    kRotate.FromRotationMatrix(pkTarget->m_kRotate);
    NiQuatTransform kTransform;
    kTransform.m_fScale = pkTarget->m_fScale;
    kTransform.m_kTranslate = pkTarget->m_kTranslate;
    kTransform.m_kRotate = kRotate;

    NiTransformInterpolator* pInterp =
        (NiTransformInterpolator*)::operator new(sizeof(NiTransformInterpolator));
    if (pInterp)
    {
        typedef NiTransformInterpolator* (NiTransformInterpolator::*CtorFn)(NiQuatTransform);
        CtorFn pfn = reinterpret_cast<CtorFn>(&NiTransformInterpolator::FUN_00a3fae0);
        return (pInterp->*pfn)(kTransform);
    }
    return 0;
}

struct FUN_00a2f8a0_Holder
{
    void FUN_00a2f8a0(NiInterpController* pkDest, CloningProcess& kCloning);
};


// @fnv 0x00a38ef0
void FUN_00a38ef0_Class::FUN_00a38ef0(FUN_00a38ef0_Class* pkDest, CloningProcess& kCloning)
{
    reinterpret_cast<::CloneableObj *>((((FUN_00a2f8a0_Holder*)this)))->FUN_00a2f8a0((::CloneableObj *)(pkDest), (void *)&(kCloning));

    if (m_spControllerInterpolator != 0)
    {
        NiInterpolator* pkNew = (NiInterpolator*)&((NiControllerSequence__IDTag*)m_spControllerInterpolator)
                                    ->
                                    operator=(*(const NiControllerSequence__IDTag*)&kCloning);
        NiInterpolator* pkOld = pkDest->m_spControllerInterpolator;
        if (pkOld != pkNew)
        {
            if (pkOld != 0)
                pkOld->DecRefCount();
            pkDest->m_spControllerInterpolator = pkNew;
            if (pkNew != 0)
                pkNew->IncRefCount();
        }
    }
}

extern int DAT_0109687c;
struct NiTimeController_Call
{
    void SetControllerActive();
};
struct S_00a36560
{
    void* FUN_00a36560();
};
// @fnv 0x00a36560
void* S_00a36560::FUN_00a36560()
{
    new ((void *)(((NiTimeController_Call*)this))) ::FUN_00a38e00();
    *(void**)this = &DAT_0109687c;
    return this;
}

struct NiSingleInterpControllerBase
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
    NiSingleInterpControllerBase();
};
struct FUN_00a35a80_Obj
{
    void FUN_00a35a80(int a1, int a2);
};
struct FUN_00a36070 : NiSingleInterpControllerBase
{
    void* m_spControllerInterpolator;
    unsigned short unk38;
    int unk3c;
    unsigned short unk40;
    FUN_00a36070(int a1, int a2);
};
// @fnv 0x00a36070
FUN_00a36070::FUN_00a36070(int a1, int a2)
{
    m_spControllerInterpolator = 0;
    unk38 = 0;
    unk3c = 0;
    *(int**)this = &(*reinterpret_cast<int *>(&::DAT_01096694));
    unk40 = 0;
    reinterpret_cast<::TargetA35 *>((((FUN_00a35a80_Obj*)this)))->FUN_00a35a80(a1, a2);
}

extern "C" void _ReadWriteBarrier(void);

struct Tgt
{
    void FUN_00a4e2e0(unsigned int a, unsigned int b, unsigned int c);
    void FUN_00a4e3b0(unsigned int a, unsigned int b, unsigned int c);
    void FUN_00a4e350(unsigned int a, unsigned int b, unsigned int c);
};

struct V3
{
    float f0;
    float f1;
    float f2;
};

struct V4
{
    float f0;
    float f1;
    float f2;
    float f3;
};

struct FUN_00a364b0_cls
{
    virtual void vf00();
    unsigned int unk04;
    unsigned int unk08;
    V3 m_t;
    V4 m_r;
    float unk28;
    Tgt* unk2c;

    void FUN_00a364b0(V3 aT0, V4 aR0, float fScale);
};

// @fnv 0x00a364b0
void FUN_00a364b0_cls::FUN_00a364b0(V3 aT0, V4 aR0, float fScale)
{
    if (aR0.f1 != ::DAT_010241b0)
    {
        m_r = aR0;
        _ReadWriteBarrier();
        if (unk2c)
            unk2c->FUN_00a4e2e0(0, 0, 0);
    }
    if (fScale != ::DAT_010241b0)
    {
        unk28 = fScale;
        if (unk2c)
            unk2c->FUN_00a4e3b0(0, 0, 0);
    }
    if (aT0.f0 != ::DAT_010241b0)
    {
        m_t = aT0;
        _ReadWriteBarrier();
        if (unk2c)
            unk2c->FUN_00a4e350(0, 0, 0);
    }
}

// Apply the source object's local transform (as a quaternion transform) to the given node.

class A36590RTTI;

struct A36590Point3
{
    float x;
    float y;
    float z;
};

struct A36590Matrix3
{
    float m_pEntry00;
    float m_pEntry01;
    float m_pEntry02;
    float m_pEntry10;
    float m_pEntry11;
    float m_pEntry12;
    float m_pEntry20;
    float m_pEntry21;
    float m_pEntry22;
};

struct A36590Quaternion
{
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

struct A36590QuatTransform
{
    A36590Point3 m_kTranslate;
    A36590Quaternion m_kRotate;
    float m_fScale;
};

class A36590Object
{
  public:
};

class A36590AVObject : public A36590Object
{
  public:
    void* m_pVtbl;
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
    A36590Matrix3 m_kRotate;
    A36590Point3 m_kTranslate;
    float m_fScale;
};

class A36590Node : public A36590Object
{
  public:
};

class A36590Controller
{
  public:
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
    A36590AVObject* m_pkSource;

    void FUN_00a36590(A36590Object* pkObject, int iUnused);
};

// @fnv 0x00a36590
void A36590Controller::FUN_00a36590(A36590Object* pkObject, int iUnused)
{
    A36590Node* pkNode = !pkObject ? 0 : (A36590Node*)((::A36590Object *)(reinterpret_cast<::NiObject *>((pkObject))->DynamicCast((const ::NiRTTI *)(const ::A36590RTTI *)(&(*reinterpret_cast<const ::A36590RTTI *>(&::g_011f3e50))))));
    A36590AVObject* pkSource = m_pkSource;

    A36590Quaternion kRotate;
    reinterpret_cast<::NiQuaternion *>(&(kRotate))->FromRotationMatrix((const ::ThreeByThreeMatrix &)(pkSource->m_kRotate));

    A36590QuatTransform kTransform;
    kTransform.m_kTranslate = pkSource->m_kTranslate;
    kTransform.m_kRotate = kRotate;
    kTransform.m_fScale = pkSource->m_fScale;
    reinterpret_cast<::FUN_00a364b0_cls *>((pkNode))->FUN_00a364b0((*(::V3 *)&(const ::A36590QuatTransform &)(kTransform)), {}, {});
}



class NiTransformInitA
{
  public:
    void* InitA(int a, float b, int c);
};

class NiTransformInitB
{
  public:
};

// @fnv 0x00a36620
void* FUN_00a36620(int a1, int a2, unsigned char a3, float a4, int a5)
{
    void* obj;
    if (a3 != 0)
    {
        obj = ::operator new(0x58);
        if (obj != 0)
        {
            return ((NiTransformInitA*)obj)->InitA(a2, a4, a5);
        }
    }
    else
    {
        obj = ::operator new(0x30);
        if (obj != 0)
        {
            return ((void *)(new ((void *)(((NiTransformInitB*)obj))) ::FUN_00a40980(a2, a4, a5)));
        }
    }
    return 0;
}
struct Interp_00a36680
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual bool Update(float, void*, void*);
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual bool AlwaysUpdate();
};
struct UpdData_00a36680
{
    float fTime;
};
struct QuatXf_00a36680
{
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
};
struct Flags_00a36680
{
    bool b0 : 1;
    bool b1 : 1;
    bool b2 : 1;
    bool b3 : 1;
    bool b4 : 1;
    bool bManager : 1;
};

struct TransformCtl_t : NiTimeController
{
    void FUN_00a36680(UpdData_00a36680&);
    unsigned short GetField(unsigned short uMask, unsigned short uPos) const
    {
        return (*(const unsigned short*)((const char*)this + 8) & uMask) >> uPos;
    }
    bool GetManagerControlled() const
    {
        return (bool)GetField(0x20, 5);
    }
};

// @fnv 0x00a36680
void TransformCtl_t::FUN_00a36680(UpdData_00a36680& UpdateData)
{
    Interp_00a36680*& spInterp = *(Interp_00a36680**)((char*)this + 0x34);
    if (GetManagerControlled())
    {
        this->m_fControllerTime = DAT_01096324;
    }
    else if (reinterpret_cast<::NiTimeControllerA362 *>(this)->FUN_00a36250(UpdateData.fTime) && (!spInterp || !spInterp->AlwaysUpdate()))
    {
        return;
    }
    if (spInterp)
    {
        QuatXf_00a36680 kTransform;
        kTransform.m_kTranslate = DAT_011a8400;
        kTransform.m_kRotate = DAT_011f3704;
        kTransform.m_fScale = DAT_01096b8c;
        if (spInterp->Update(this->m_fControllerTime, *(void**)&this->m_pkTarget, &kTransform))
        {
            NiAVObject* pkTarget = *(NiAVObject**)&this->m_pkTarget;
            if (kTransform.m_kTranslate.x != -3.4028234663852886e+38)
                pkTarget->m_kTranslate = kTransform.m_kTranslate;
            if (kTransform.m_kRotate.m_fVectorY != -3.4028234663852886e+38)
                reinterpret_cast<::FUN_004f0180_Class *>(&(kTransform.m_kRotate))->FUN_004f0180((::M3_ *)&(pkTarget->m_kRotate));
            if (kTransform.m_fScale != -3.4028234663852886e+38)
                pkTarget->m_fScale = fabs(kTransform.m_fScale);
        }
    }
}
