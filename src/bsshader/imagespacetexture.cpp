#include <cstddef>
// bsshader/imagespacetexture.cpp: free functions (1 function)

#include "fnv/decl/Manager.h"
#include "fnv/symbols_011f9000.h"
#include "imagespacetexture_decls.h"
#include <windows.h>
#include "fnv/decl/E7DE90Owner.h"
#include "fnv/decl/E7DEF0TextureStage.h"
#include "fnv/decl/FUN_004bc320_shell.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/HolderForAccum.h"
#include "fnv/decl/ISKernelEffect.h"
#include "fnv/decl/ImageSpaceShaderParam.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiRenderer.h"
#include "fnv/decl/Pool.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01200000.h"
#include "fnv/symbols_01272000.h"

class BA3760Object
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_iValue;

    void FUN_00ba3760(int iValue);
};


struct R_00ba39a0
{
    virtual void f0();
    virtual void f1();
    long m_rc;
};

struct H_00ba39a0
{
    bool b0;
    bool b1;
    bool b2;
    R_00ba39a0* p;
    int i1;
    int i2;
    void FUN_00ba39a0();
};

struct Tex00ba37f0;

struct Tex00ba37f0
{
    virtual void F0();
    virtual void F1();
    long m_Ref;
    void IncRefCount()
    {
        InterlockedIncrement(&m_Ref);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_Ref) == 0)
            F1();
    }
};

struct Holder00ba37f0
{
    bool b0;
    bool b1;
    Tex00ba37f0* pTileTexture;
    void FUN_00ba37f0(Tex00ba37f0* apTex);
};


struct EnchantmentItem;
struct TESForm;
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESEnchantableForm : public BaseFormComponent
{
    virtual int GetCastingType();
    void SetCastingType(int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    void InitItem(TESForm*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static EnchantmentItem* FindFormEnchantment(TESForm*);
    EnchantmentItem* FindFormEnchantment();
    void SetFormEnchanting(EnchantmentItem*);
    static unsigned short GetFormEnchantmentAmount(TESForm*);
    unsigned short GetFormEnchantmentAmount();
    void SetFormEnchantmentAmount(unsigned short);
    EnchantmentItem* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    char _pad_a[2];
    int m_eCastingType;
};
struct FUN_0041fd00_shell : public TESEnchantableForm
{
    void FUN_0041fd00(int);
};

// @fnv 0x0041fd00
void FUN_0041fd00_shell::FUN_0041fd00(int aeCastingType)
{
    m_eCastingType = aeCastingType;
}

struct FUN_00ba3770_struct
{
    int FUN_00ba3770();
};

// @fnv 0x00ba3770
int FUN_00ba3770_struct::FUN_00ba3770()
{
    if (reinterpret_cast<char*>(this)[1])
        return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4);
    return 0;
}





// @fnv 0x00ba37f0
void Holder00ba37f0::FUN_00ba37f0(Tex00ba37f0* apTex)
{
    if (pTileTexture != apTex)
    {
        if (pTileTexture)
            pTileTexture->DecRefCount();
        pTileTexture = apTex;
        if (apTex)
            apTex->IncRefCount();
    }
    b1 = 0;
}

struct BeamStage
{
    char _0[8];
    void* m_8;
};

struct TextureReceiver
{
};

struct UnkBA38F0
{
    unsigned char m_iWordAt00;
    bool m_cByteAtOffset1;
    unsigned char m_auiShapeKeys[2];
    UnkBA38F0* volatile m_iWordAt04;
    unsigned int m_8;
    unsigned int m_C;
    void FUN_00ba38f0(BeamStage*);
};

// @fnv 0x00ba38f0
void UnkBA38F0::FUN_00ba38f0(BeamStage* pkStage)
{
    UnkBA38F0* pThis = this;
    reinterpret_cast<::E7DE90Owner *>((pkStage))->ApplyPairToState(pThis->m_C);
    reinterpret_cast<::E7DEF0TextureStage *>((pkStage))->FUN_00e7def0(pThis->m_8);
    if (pThis->m_cByteAtOffset1)
    {
        pkStage->m_8 = ((::TextureReceiver *)(reinterpret_cast<::FUN_004bc320_shell *>((((TextureReceiver*)pThis->m_iWordAt04)))->FUN_004bc320(0)));
    }
    else
    {
        pThis = pThis->m_iWordAt04;
        pkStage->m_8 = pThis;
    }
}





// @fnv 0x00ba39a0
void H_00ba39a0::FUN_00ba39a0()
{
    if (!b2)
        return;
    b2 = false;
    reinterpret_cast<::Manager *>((DAT_011f91a8))->FUN_00b6da10((::Item *)(::BSRenderedTexture *)(b1 ? (BSRenderedTexture*)p : 0));
    R_00ba39a0* tex = p;
    if (tex)
    {
        if (InterlockedDecrement(&tex->m_rc) == 0)
            tex->f1();
        p = 0;
    }
    b1 = false;
    i1 = 0;
    i2 = 0;
}

struct RefBase
{
    virtual void vf0();
    virtual void vf1();
    long m_iObjectReferenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_iObjectReferenceCount) == 0)
            vf1();
    }
};

struct OwnerStandIn
{
    unsigned char unk0;
    unsigned char flag;
    unsigned char pad[2];
    RefBase* ptr;
    void FUN_00ba37a0(RefBase* p);
};

// @fnv 0x00ba37a0
void OwnerStandIn::FUN_00ba37a0(RefBase* p)
{
    if (ptr != p)
    {
        if (ptr)
            ptr->DecRefCount();
        ptr = p;
        if (ptr)
            ptr->IncRefCount();
    }
    flag = 1;
}

struct RefObj
{
    virtual void F0();
    virtual void F1();
    long m_ref;
};

struct Holder
{
    char _0;
    unsigned char _1;
    char _pad[2];
    RefObj* _4;
    int _8;
    int _c;
    void FUN_00ba38b0();
};

// @fnv 0x00ba38b0
void Holder::FUN_00ba38b0()
{
    RefObj* tmp = _4;
    if (tmp)
    {
        if (InterlockedDecrement(&tmp->m_ref) == 0)
            tmp->F1();
        _4 = 0;
    }
    _1 = 0;
    _8 = 0;
    _c = 0;
}

struct NiRenderer;

struct TexMgr00ba3840
{
};

struct H_00ba3840
{
    char _0;
    bool b1;
    bool b2;
    char _pad;
    Tex00ba37f0* pTileTexture;
    void FUN_00ba3840(int arg);
};

// @fnv 0x00ba3840
void H_00ba3840::FUN_00ba3840(int arg)
{
    Tex00ba37f0* pNew = ((::Tex00ba37f0 *)(reinterpret_cast<::Pool *>((((TexMgr00ba3840*)DAT_011f91a8)))->FUN_00b6e110((unsigned int)(::DAT_011f9508), arg, 0, (unsigned int)(0), 0)));
    if (pTileTexture != pNew)
    {
        if (pTileTexture)
            pTileTexture->DecRefCount();
        pTileTexture = pNew;
        if (pTileTexture)
            pTileTexture->IncRefCount();
    }
    b1 = true;
    b2 = true;
}

struct FUN_00ba2590_struct
{
};

struct ISTex
{
};

struct FUN_00ba26f0_struct
{
    char _0[0x58];
    ISTex a;
    char _70[0x8];
    ISTex b;
    char _88[0x8];
    ISTex c;
    char _a0[0x8];
    ISTex d;
    void FUN_00ba26f0();
};

struct FUN_00ba3780_struct
{
    unsigned char unk0;
    bool flag;
    unsigned char pad[2];
    TextureReceiver* ptr;
    TextureReceiver* FUN_00ba3780();
};

// @fnv 0x00ba26f0
void FUN_00ba26f0_struct::FUN_00ba26f0()
{
    if (!((void *)(reinterpret_cast<::FUN_00ba3780_struct *>((((ISTex*)((char*)this + 0x88))))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba3840 *>((((ISTex*)((char*)this + 0x88))))->FUN_00ba3840(0xd);
    if (!((void *)(reinterpret_cast<::FUN_00ba3780_struct *>((((ISTex*)((char*)this + 0x78))))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba3840 *>((((ISTex*)((char*)this + 0x78))))->FUN_00ba3840(0xe);
    if (!((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(((&this->a)))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba3840 *>(((&this->a)))->FUN_00ba3840(0xf);
    if (!((void *)(reinterpret_cast<::FUN_00ba3780_struct *>((((ISTex*)&this->_88[6])))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba3840 *>((((ISTex*)&this->_88[6])))->FUN_00ba3840(0x10);
    reinterpret_cast<::ISKernelEffect *>((((FUN_00ba2590_struct*)this)))->FUN_00ba2590();
}

// @fnv 0x00ba3780
TextureReceiver* FUN_00ba3780_struct::FUN_00ba3780()
{
    if (flag)
        return ((::TextureReceiver *)(reinterpret_cast<::FUN_004bc320_shell *>((ptr))->FUN_004bc320(0)));
    return ptr;
}



// @fnv 0x00ba3760
void BA3760Object::FUN_00ba3760(int iValue)
{
    m_iValue = iValue;
}

struct RefObj3940
{
    virtual void vf0();
    virtual void vf1();
    long m_ref;
    void AcquireReference()
    {
        InterlockedIncrement(&m_ref);
    }
    void DecRef()
    {
        if (InterlockedDecrement(&m_ref) == 0)
            vf1();
    }
};

struct FUN_00ba3940_cls
{
    unsigned char unk00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char unk03;
    RefObj3940* m_04;
    unsigned int m_08;
    FUN_00ba3940_cls* FUN_00ba3940(FUN_00ba3940_cls* src);
};

// @fnv 0x00ba3940
FUN_00ba3940_cls* FUN_00ba3940_cls::FUN_00ba3940(FUN_00ba3940_cls* src)
{
    *(volatile unsigned char*)&m_01 = src->m_01;
    *(volatile unsigned char*)&m_02 = src->m_02;
    RefObj3940* old = *(RefObj3940* volatile*)&m_04;
    if (old != src->m_04)
    {
        if (old != 0)
        {
            old->DecRef();
        }
        m_04 = src->m_04;
        if (m_04 != 0)
        {
            m_04->AcquireReference();
        }
    }
    m_08 = src->m_08;
    src->m_02 = 0;
    return this;
}

struct TLSTagGuard
{
    unsigned int uiOld;
    TLSTagGuard(unsigned int uiTag)
    {
        uiOld = ::currentAllocationContext;
        ::currentAllocationContext = uiTag;
    }
    ~TLSTagGuard()
    {
        ::currentAllocationContext = uiOld;
    }
};

struct ISTexture
{
    bool b0;
    bool b1;
    bool b2;
    void* pTileTexture;
    int i8;
    int iC;
    ISTexture() : b0(false), b1(false), b2(false), pTileTexture(0), i8(0), iC(0)
    {}
    ~ISTexture();
};

struct ISEffectShader
{
    virtual void vf0();
    virtual void Render(void* apGeom, void* apArg2, void* apArg5, void* apArg6);
};

struct ImageSpaceOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    void* pGeom1f0;
    int unk1f4;
    void* pGeom1f8;
    bool bUseAlt;
    void FUN_00b8c980(ISEffectShader* apShader, void* apArg2, NiTexture* apSource, BSRenderedTexture* apDest,
                      void* apArg5, void* apArg6);
};

// @fnv 0x00b8c980
void ImageSpaceOwner::FUN_00b8c980(ISEffectShader* apShader, void* apArg2, NiTexture* apSource,
                                   BSRenderedTexture* apDest, void* apArg5, void* apArg6)
{
    TLSTagGuard kGuard(0x27);
    ISTexture kSource;
    ISTexture kDest;
    reinterpret_cast<::Holder00ba37f0 *>(&(kSource))->FUN_00ba37f0((::Tex00ba37f0 *)(apSource));
    reinterpret_cast<::OwnerStandIn *>(&(kDest))->FUN_00ba37a0((::RefBase *)(apDest));
    if (apShader)
    {
        reinterpret_cast<::HolderForAccum *>((apShader))->SetAccumulatorAt(0, (::NiAccumulator *)(::ISTexture *)(&kDest), (const ::NiCamera *)(0));
        reinterpret_cast<::HolderForAccum *>((apShader))->SetAccumulatorAt(1, (::NiAccumulator *)(::ISTexture *)(&kSource), (const ::NiCamera *)(0));
        void** ppGeom = bUseAlt ? &pGeom1f8 : &pGeom1f0;
        void* pGeom = *ppGeom;
        apShader->Render(pGeom, apArg2, apArg5, apArg6);
        reinterpret_cast<::HolderForAccum *>((apShader))->SetAccumulatorAt(0, (::NiAccumulator *)(::ISTexture *)(0), (const ::NiCamera *)(0));
        reinterpret_cast<::HolderForAccum *>((apShader))->SetAccumulatorAt(1, (::NiAccumulator *)(::ISTexture *)(0), (const ::NiCamera *)(0));
    }
}

struct TexObj
{
};

struct WorkObj
{
    virtual void V0();
    virtual void Vf1(int a, int b, TexObj* tex, int c);
};

struct ElemHeader
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
};

struct ElemObj
{
    ElemHeader header;
    WorkObj work_6c;
};

struct StagePtrs
{
    WorkObj* p0;
    WorkObj* p1;
    WorkObj* p2;
    WorkObj* p3;
    WorkObj* p4;
    WorkObj* p5;
    WorkObj* p6;
};

struct TexPtrs
{
    TexObj* t0;
    TexObj* t1;
    TexObj* t2;
    TexObj* t3;
    TexObj* t4;
    TexObj* t5;
    TexObj* t6;
};

struct M2C
{
    void* p0;
    void* p1;
};

struct Sub10
{
    int f0;
    int f4;
    int f8;
    int fc;
};

struct HolderX
{
    bool b0;
    bool b1;
    bool b2;
    void* p;
    int i1;
    int i2;
    HolderX() : b0(0), b1(0), b2(0), p(0), i1(0), i2(0)
    {}
    ~HolderX();
};

extern int DAT_01200050;

extern float DAT_0120004c;

struct Owner
{
    virtual void W0();
    virtual void W1();
    virtual void W2();
    virtual void W3();
    virtual void W4();
    virtual void W5();
    virtual void W6();
    virtual bool W7(int arg);
    unsigned char f4;
    bool flag;
    unsigned char f6;
    unsigned char f7;
    int unk8;
    StagePtrs* m_iThirdValue;
    int unk10;
    int unk14;
    int unk18;
    TexPtrs* m_1c;
    int unk20;
    int unk24;
    int unk28;
    M2C* m_2c;
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
    Sub10 s58;
    Sub10 s68;
    Sub10 s78;
    Sub10 s88;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    float m_b0;
    float m_b4;
    bool m_b8;
    void FUN_00ba2760(int a1, int a2, int a3, int a4);
};

static __forceinline WorkObj* ToWork(WorkObj* p)
{
    ElemObj* e = p ? (ElemObj*)((ElemHeader*)p - 1) : 0;
    return e ? &e->work_6c : 0;
}

// @fnv 0x00ba2760
void Owner::FUN_00ba2760(int a1, int a2, int a3, int a4)
{
    if (!m_b8)
        reinterpret_cast<::FUN_00ba26f0_struct *>(this)->FUN_00ba26f0();
    int count = DAT_01200050;
    int a2v = a2;
    int j;
    if (flag)
        flag = W7(a3);
    HolderX d;
    HolderX b;
    HolderX a;
    reinterpret_cast<::H_00ba3840 *>(&(d))->FUN_00ba3840(7);
    reinterpret_cast<::H_00ba3840 *>(&(a))->FUN_00ba3840(7);
    reinterpret_cast<::H_00ba3840 *>(&(b))->FUN_00ba3840(7);
    HolderX c;
    WorkObj* w = ToWork(m_iThirdValue->p0);
    TexObj* tex = m_1c->t0;
    reinterpret_cast<::ImageSpaceShaderParam *>((tex))->SetShaderConstantVector4(0, m_b0, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(0, (::NiAccumulator *)(void *)(&d), (const ::NiCamera *)(0));
    reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(1, (::NiAccumulator *)(void *)(&s68), (const ::NiCamera *)(0));
    reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(2, (::NiAccumulator *)(void *)(&s58), (const ::NiCamera *)(0));
    w->Vf1(a1, a2v, tex, 1);
    w = ToWork(m_iThirdValue->p3);
    tex = m_1c->t3;
    reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(0, (::NiAccumulator *)(void *)(&a), (const ::NiCamera *)(0));
    reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(1, (::NiAccumulator *)(void *)(&s88), (const ::NiCamera *)(0));
    reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(2, (::NiAccumulator *)(void *)(&d), (const ::NiCamera *)(0));
    w->Vf1(a1, a2v, tex, 1);
    reinterpret_cast<::FUN_00ba3940_cls *>(&(c))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&b));
    reinterpret_cast<::FUN_00ba3940_cls *>(&(b))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&a));
    reinterpret_cast<::FUN_00ba3940_cls *>(&(a))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&c));
    w = ToWork(m_iThirdValue->p1);
    tex = m_1c->t1;
    int i;
    for (i = 0; i < count; i++)
    {
        m_b4 = (float)(i * 0.0625 + 0.03125);
        reinterpret_cast<::ImageSpaceShaderParam *>((tex))->SetShaderConstantVector4(1, m_b4, ::DAT_0101e570, 0.0f, 0.0f);
        reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(0, (::NiAccumulator *)(void *)(&a), (const ::NiCamera *)(0));
        reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(1, (::NiAccumulator *)(void *)(&s78), (const ::NiCamera *)(0));
        reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(2, (::NiAccumulator *)(void *)(&b), (const ::NiCamera *)(0));
        w->Vf1(a1, a2v, tex, 1);
        reinterpret_cast<::FUN_00ba3940_cls *>(&(c))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&b));
        reinterpret_cast<::FUN_00ba3940_cls *>(&(b))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&a));
        reinterpret_cast<::FUN_00ba3940_cls *>(&(a))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&c));
    }
    w = ToWork(m_iThirdValue->p4);
    tex = m_1c->t4;
    reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(0, (::NiAccumulator *)(void *)(&a), (const ::NiCamera *)(0));
    reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(1, (::NiAccumulator *)(void *)(&s88), (const ::NiCamera *)(0));
    reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(2, (::NiAccumulator *)(void *)(&b), (const ::NiCamera *)(0));
    w->Vf1(a1, a2v, tex, 1);
    reinterpret_cast<::FUN_00ba3940_cls *>(&(c))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&b));
    reinterpret_cast<::FUN_00ba3940_cls *>(&(b))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&a));
    reinterpret_cast<::FUN_00ba3940_cls *>(&(a))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&c));
    w = ToWork(m_iThirdValue->p2);
    TexObj* t2p = m_1c->t2;
    for (j = 0; j < count; j++)
    {
        m_b4 = (float)(j * 0.0625 + 0.03125);
        reinterpret_cast<::ImageSpaceShaderParam *>((t2p))->SetShaderConstantVector4(1, m_b4, ::DAT_0101e570, 0.0f, 0.0f);
        if (j == count - 1)
            reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(0, (::NiAccumulator *)(m_2c->p1), (const ::NiCamera *)(0));
        else
            reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(0, (::NiAccumulator *)(void *)(&a), (const ::NiCamera *)(0));
        reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(1, (::NiAccumulator *)(void *)(&s78), (const ::NiCamera *)(0));
        reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(2, (::NiAccumulator *)(void *)(&b), (const ::NiCamera *)(0));
        w->Vf1(a1, a2v, t2p, 1);
        if (j != count - 1)
        {
            reinterpret_cast<::FUN_00ba3940_cls *>(&(c))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&b));
            reinterpret_cast<::FUN_00ba3940_cls *>(&(b))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&a));
            reinterpret_cast<::FUN_00ba3940_cls *>(&(a))->FUN_00ba3940((::FUN_00ba3940_cls *)(::HolderX *)(&c));
        }
    }
    if ((*reinterpret_cast<unsigned char *>(&::DAT_01200058)))
    {
        w = ToWork(m_iThirdValue->p5);
        tex = m_1c->t5;
        reinterpret_cast<::ImageSpaceShaderParam *>((tex))->SetShaderConstantVector4(2, DAT_0120004c, ::DAT_0101e570, 0.0f, 0.0f);
        reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(0, (::NiAccumulator *)(m_2c->p0), (const ::NiCamera *)(0));
        reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(1, (::NiAccumulator *)(m_2c->p1), (const ::NiCamera *)(0));
        w->Vf1(a1, a2v, tex, 1);
    }
    else
    {
        w = ToWork(m_iThirdValue->p6);
        tex = m_1c->t6;
        reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(0, (::NiAccumulator *)(m_2c->p0), (const ::NiCamera *)(0));
        reinterpret_cast<::HolderForAccum *>((w))->SetAccumulatorAt(1, (::NiAccumulator *)(m_2c->p1), (const ::NiCamera *)(0));
        w->Vf1(a1, a2v, tex, 1);
    }
    if (((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(d))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba39a0 *>(&(d))->FUN_00ba39a0();
    if (((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(a))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba39a0 *>(&(a))->FUN_00ba39a0();
    if (((void *)(reinterpret_cast<::FUN_00ba3780_struct *>(&(b))->FUN_00ba3780())))
        reinterpret_cast<::H_00ba39a0 *>(&(b))->FUN_00ba39a0();
}

struct TextureRenderedViewB63
{
};

struct TextureSlotB63
{
    int unk00;
    int unk04;
    OwnerStandIn* receiver;
};

struct TextureContainerB63
{
    int unk00;
    TextureSlotB63* node;
};

struct TextureAllocationManagerB63
{
};

inline void* operator new(std::size_t bytes)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::TextureAllocationManagerB63 *>(&::g_memoryManager))))->FUN_00aa3e40(bytes);
}

struct TextureManagerB63
{
};

struct TextureOwnerB63
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    TextureContainerB63 container;
    int FUN_00b63c60();
};

// @fnv 0x00b63c60
int TextureOwnerB63::FUN_00b63c60()
{
    if (!container.node->receiver)
    {
        ISTexture* created = new ISTexture;
        reinterpret_cast<::FUN_00a41520_cls *>(&(container))->FUN_00ba3aa0(2, (::KeyPair **)(void *)(&created));
    }
    OwnerStandIn** getterSlot = &container.node->receiver;
    if (!reinterpret_cast<::FUN_00ba3770_struct *>((reinterpret_cast<TextureRenderedViewB63*>(*getterSlot)))->FUN_00ba3770())
    {
        OwnerStandIn** receiverSlot = &container.node->receiver;
        (*receiverSlot)
            ->FUN_00ba37a0(((::RefBase *)(reinterpret_cast<::Pool *>((reinterpret_cast<TextureManagerB63*>(DAT_011f91a8)))->FUN_00b6e110((unsigned int)((*reinterpret_cast<void * *>(&::NiRenderer::ms_pRenderer))), 32, (unsigned int)(0), (unsigned int)(0), (unsigned int)(0)))));
    }
    OwnerStandIn** finalSlot = &container.node->receiver;
    return reinterpret_cast<::FUN_00ba3770_struct *>((reinterpret_cast<TextureRenderedViewB63*>(*finalSlot)))->FUN_00ba3770();
}

struct RenderedGetterB63D
{
};

struct TextureNodeB63D
{
    int unk00;
    int unk04;
    OwnerStandIn* texture;
};

struct ReturnManagerB63D
{
};

struct TextureOwnerB63D
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    TextureNodeB63D* node;
    void FUN_00b63d10();
};

// @fnv 0x00b63d10
void TextureOwnerB63D::FUN_00b63d10()
{
    TextureNodeB63D* current = node;
    if (!node->texture)
        return;
    if (!reinterpret_cast<::FUN_00ba3770_struct *>((reinterpret_cast<RenderedGetterB63D*>(current->texture)))->FUN_00ba3770())
        return;
    ReturnManagerB63D* manager = reinterpret_cast<ReturnManagerB63D*>(DAT_011f91a8);
    OwnerStandIn** slot = &node->texture;
    int rendered = reinterpret_cast<::FUN_00ba3770_struct *>((reinterpret_cast<RenderedGetterB63D*>(*slot)))->FUN_00ba3770();
    reinterpret_cast<::Manager *>((manager))->FUN_00b6da10((::Item *)(rendered));
    node->texture->FUN_00ba37a0(0);
}
