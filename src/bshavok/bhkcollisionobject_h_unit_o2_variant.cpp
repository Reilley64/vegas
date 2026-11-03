
// src/bshavok/bhkcollisionobject_h_unit_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bshavok/bhkcollisionobject_h_unit.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004f0180_Class.h"
#include "fnv/decl/FUN_00c6b670_cls.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiObject.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/OwnerProxy.h"
#include "fnv/decl/QueryOwner.h"
#include "fnv/decl/S00560c20_Object.h"
#include "fnv/decl/ViewerCollision.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/bhkRigidBody_shell.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c6b000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01204000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "bhkcollisionobject.h"

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct MyType : BSFadeNode
{
    char d[0x14];
    MyType()
    {
        FUN_00c6b910(this);
        *(void**)this = (void*)&DAT_0103046c;
    }
};
// @fnv 0x00c65830
void* FUN_00c65830()
{
    return new MyType;
}

struct hkVector4
{
    float x, y, z, w;
};
struct WeaponObject
{
    void* FUN_00c65ef0(void*);
};
// @fnv 0x00c65ef0
void* WeaponObject::FUN_00c65ef0(void* a1)
{
    void* p = *(void**)((char*)this + 0x10);
    if (p)
    {
        void* q = *(void**)((char*)p + 8);
        const hkVector4* r;
        if (q)
            r = (const hkVector4*)((char*)q + 0x1B0);
        else
            r = (const hkVector4*)&DAT_01267e30;
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(a1)), *r);
        return a1;
    }
    ((int*)a1)[0] = (*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO));
    ((int*)a1)[1] = ::_DAT_011f4270;
    ((int*)a1)[2] = ::_DAT_011f4274;
    return a1;
}

struct AudioTlsState
{
    char pad[0x2b4];
    int m_uiMemoryContext;
};


struct ScopedMemoryContext
{
    int oldVal;
    ScopedMemoryContext(int newVal)
    {
        oldVal = (*reinterpret_cast<::AudioTlsState *>(&::g_tlsBlock)).m_uiMemoryContext;
        (*reinterpret_cast<::AudioTlsState *>(&::g_tlsBlock)).m_uiMemoryContext = newVal;
    }
    ~ScopedMemoryContext()
    {
        (*reinterpret_cast<::AudioTlsState *>(&::g_tlsBlock)).m_uiMemoryContext = oldVal;
    }
};

struct FUN_00c659d0_shell : bhkCollisionObject
{
    MyType* FUN_00c659d0(void* param);
};

// @fnv 0x00c659d0
MyType* FUN_00c659d0_shell::FUN_00c659d0(void* param)
{
    ScopedMemoryContext scope(0x10);
    MyType* obj = new MyType;
    reinterpret_cast<::OwnerProxy *>(this)->FUN_00c6ba30((::OwnerProxy *)(obj), (::CloneProcess *)(param));
    return obj;
}

struct FUN_00c65890_Tgt
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_flags;
};

struct FUN_00c65890_Callee
{
};

struct FUN_00c65890_cls
{
    int unk00;
    int unk04;
    FUN_00c65890_Callee* m_08;
    int unk0c;
    FUN_00c65890_Tgt* m_10;
    void FUN_00c65890(int param);
};

// @fnv 0x00c65890
void FUN_00c65890_cls::FUN_00c65890(int param)
{
    FUN_00c65890_Tgt* tgt = m_10;
    if (tgt != 0)
    {
        unsigned int flags = tgt->m_flags;
        flags >>= 6;
        if (((unsigned char)flags & 1) != 0)
        {
            FUN_00c65890_Callee* p = m_08;
            if (p != 0)
            {
                reinterpret_cast<::NiAVObject *>((p))->UpdateWorldLoc();
            }
            return;
        }
    }
    reinterpret_cast<::FUN_00c6b670_cls *>(this)->UpdateState(param);
}

struct CollisionNode
{
    int unk00;
    int unk04;
    unsigned char* status;
};
struct CollisionState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CollisionNode* node;
    bool FUN_00c659a0();
};
// @fnv 0x00c659a0
bool CollisionState::FUN_00c659a0()
{
    if (node)
    {
        unsigned char* status = node->status;
        unsigned int kind = status ? status[0xE8] : 4;
        return kind == 4 || kind == 5;
    }
    return false;
}

struct SpinLock_c65f40
{
    int owner;
    int count;
    void Unlock()
    {
        if (--count == 0)
            owner = 0;
    }
};


inline bool Check(int t)
{
    return FUN_00c8cce0(&t) != 0;
}

struct WorldObj_c65f40
{
};

struct HkObj_c65f40
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char motionType;
};

struct RTTI_c65f40;

struct RigidBody_c65f40
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    int unk04;
    HkObj_c65f40* hkObj;
    virtual bool SetMotion(int type);
};

struct NiObj_c65f40
{
};

struct ColObj_c65f40
{
    void* vtbl;
    int unk04;
    int unk08;
    unsigned short flags;
    short unk0E;
    RigidBody_c65f40* body;
    void FUN_00c65f40(int type, NiObj_c65f40* obj, bool update);
};

// @fnv 0x00c65f40
void ColObj_c65f40::FUN_00c65f40(int type, NiObj_c65f40* obj, bool update)
{
    RigidBody_c65f40* rb;
    int t;
    if (!obj || (rb = ((::RigidBody_c65f40 *)(reinterpret_cast<::NiObject *>((obj))->DynamicCast((const ::NiRTTI *)(const ::RTTI_c65f40 *)(&(*reinterpret_cast<::RTTI_c65f40 *>(&::g_012681c0))))))) == 0)
    {
        rb = body;
        if (!rb)
            return;
    }
    int cur = rb->hkObj ? rb->hkObj->motionType : 5;
    if (cur == type)
        return;
    if (type == 1 && FUN_00c8cce0(&cur))
        return;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::SpinLock_c65f40 *>(&::DAT_01267b80))))->FUN_0040fbf0((char *)(0));
    bool ok = rb->SetMotion(type);
    (*reinterpret_cast<::SpinLock_c65f40 *>(&::DAT_01267b80)).Unlock();
    if (!ok)
        return;
    if (Check(rb->hkObj ? rb->hkObj->motionType : 5))
        flags |= 8;
    else
        flags &= ~8;
    if (update)
    {
        t = reinterpret_cast<::bhkRigidBody_shell *>((rb))->FUN_00517630();
        if (FUN_00c8cce0(&t))
        {
            WorldObj_c65f40* w = (WorldObj_c65f40*)rb->hkObj;
            if (w)
            {
                ::FUN_00a29680();
                reinterpret_cast<::hkpEntityC9C *>((w))->FUN_00c9c1d0();
                ::FUN_00a29680();
            }
        }
    }
}

struct TlsBlock
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_uiMemoryContext;
};

struct MemContextGuard
{
    int oldVal;
    MemContextGuard(int newVal)
    {
        oldVal = (*reinterpret_cast<::TlsBlock *>(&::g_tlsBlock)).m_uiMemoryContext;
        (*reinterpret_cast<::TlsBlock *>(&::g_tlsBlock)).m_uiMemoryContext = newVal;
    }
    ~MemContextGuard()
    {
        (*reinterpret_cast<::TlsBlock *>(&::g_tlsBlock)).m_uiMemoryContext = oldVal;
    }
};

struct StrAllocator
{
};
template <class T, class A> class StrArray
{
  public:
    virtual ~StrArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, T& element);
    unsigned int Add(T element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
        return uiIndex;
    }
};
typedef StrArray<char*, StrAllocator> ViewerStrings;

struct RttiStub
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};


class CollisionParent
{
  public:
};

class CollisionObj : public CollisionParent
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    bool GetUseVel() const
    {
        return (m_usFlags & 0x20) && !(bool)((m_usFlags >> 6) & 1);
    }
    void FUN_00c66060(ViewerStrings* apViewerStrings);
};

// @fnv 0x00c66060
void CollisionObj::FUN_00c66060(ViewerStrings* apViewerStrings)
{
    MemContextGuard guard(0x10);
    reinterpret_cast<::ViewerCollision *>(this)->AppendDebugInfo((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(apViewerStrings));
    apViewerStrings->Add(::FUN_00a7d330((*reinterpret_cast<::RttiStub *>(&::g_012043f8)).GetName()));
    apViewerStrings->Add(::FUN_00a7d370("bUseVel", GetUseVel()));
}

struct Mat3
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct Pt3
{
    float x, y, z;
};
struct Xform
{
    Mat3 m_kOrientation;
    Pt3 m_kTranslation;
    float m_fScale;
};
struct Quat
{
    float w, x, y, z;
};
struct HkEntity
{
    int unk00;
    int unk04;
    int* unk08;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
};

struct SceneObj
{
};

struct BhkBody
{
    int unk00;
    int unk04;
    HkEntity* pNode08;
};

struct CollObj
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46(const Xform& a1);
    int unk04;
    SceneObj* pObj08;
    int unk0C;
    BhkBody* pBody10;
    void FUN_00c65a80();
};

// @fnv 0x00c65a80
void CollObj::FUN_00c65a80()
{
    BhkBody* pBody = pBody10;
    if (pBody == 0)
        return;
    HkEntity* pNode = pBody->pNode08;
    if (pNode == 0)
        return;
    if (pNode->unkE8 == 5 && pNode->unk08 != 0)
    {
        if (pObj08 != 0)
            reinterpret_cast<::NiAVObject *>((pObj08))->UpdateWorldLoc();
        return;
    }
    Quat q;
    Xform t;
    reinterpret_cast<::S00560c20_Object *>((pBody))->FUN_00560c20((::S00560c20_Target *)&(q));
    reinterpret_cast<::FUN_004f0180_Class *>((void *)&(q))->FUN_004f0180((::M3_ *)&(t.m_kOrientation));
    reinterpret_cast<::QueryOwner *>((pBody))->FUN_00560bc0((int)&(t.m_kTranslation));
    s46(t);
}
