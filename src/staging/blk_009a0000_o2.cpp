
// src/staging/blk_009a0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "fnv/decl/Actor.h"
#include "fnv/decl/BSFadeNode.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C00624070.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a51b0_shell.h"
#include "fnv/decl/FUN_006212c0_shell.h"
#include "fnv/decl/FUN_009b0c50_Class.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/S_9b3080_Class.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/fnv_009b0cf0__FUN_009b0cf0_class.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_009b2000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include <xmmintrin.h>

struct NiPoint3B09
{
    float x, y, z;
    NiPoint3B09();
    NiPoint3B09(float fX, float fY, float fZ);
    NiPoint3B09 operator-(const NiPoint3B09& kPt) const;
    NiPoint3B09 operator*(float fScalar) const;
    float& operator[](int i);
};

struct hkVector4B09
{
    __m128 m_vComponents;
    hkVector4B09();
};

struct SettingB09
{
};

struct HandleB09
{
    int m_iValue;
};

struct FormB09
{
};

struct ProcessB09
{
};

struct RefB09
{
    virtual void vr000();
    virtual void vr001();
    virtual void vr002();
    virtual void vr003();
    virtual void vr004();
    virtual void vr005();
    virtual void vr006();
    virtual void vr007();
    virtual void vr008();
    virtual void vr009();
    virtual void vr00a();
    virtual void vr00b();
    virtual void vr00c();
    virtual void vr00d();
    virtual void vr00e();
    virtual void vr00f();
    virtual void vr010();
    virtual void vr011();
    virtual void vr012();
    virtual void vr013();
    virtual void vr014();
    virtual void vr015();
    virtual void vr016();
    virtual void vr017();
    virtual void vr018();
    virtual void vr019();
    virtual void vr01a();
    virtual void vr01b();
    virtual void vr01c();
    virtual void vr01d();
    virtual void vr01e();
    virtual void vr01f();
    virtual void vr020();
    virtual void vr021();
    virtual void vr022();
    virtual void vr023();
    virtual void vr024();
    virtual void vr025();
    virtual void vr026();
    virtual void vr027();
    virtual void vr028();
    virtual void vr029();
    virtual void vr02a();
    virtual void vr02b();
    virtual void vr02c();
    virtual void vr02d();
    virtual void vr02e();
    virtual void vr02f();
    virtual void vr030();
    virtual void vr031();
    virtual void vr032();
    virtual void vr033();
    virtual void vr034();
    virtual void vr035();
    virtual void vr036();
    virtual void vr037();
    virtual void vr038();
    virtual void SetFlagE4(int iValue);
    virtual void vr03a();
    virtual void vr03b();
    virtual hkVector4B09* GetPosF0(hkVector4B09* pOut);
    HandleB09* FUN_0043b4f0(HandleB09* pOut);
};

struct OwnerB09
{
    virtual void vo000();
    virtual void vo001();
    virtual void vo002();
    virtual void vo003();
    virtual void vo004();
    virtual void vo005();
    virtual void vo006();
    virtual void vo007();
    virtual void vo008();
    virtual void vo009();
    virtual void vo00a();
    virtual void vo00b();
    virtual void vo00c();
    virtual void vo00d();
    virtual void vo00e();
    virtual void vo00f();
    virtual void vo010();
    virtual void vo011();
    virtual void vo012();
    virtual void vo013();
    virtual void vo014();
    virtual void vo015();
    virtual void vo016();
    virtual void vo017();
    virtual void vo018();
    virtual void vo019();
    virtual void vo01a();
    virtual void vo01b();
    virtual void vo01c();
    virtual void vo01d();
    virtual void vo01e();
    virtual void vo01f();
    virtual void vo020();
    virtual void vo021();
    virtual void vo022();
    virtual void vo023();
    virtual void vo024();
    virtual void vo025();
    virtual void vo026();
    virtual void vo027();
    virtual void vo028();
    virtual void vo029();
    virtual void vo02a();
    virtual void vo02b();
    virtual void vo02c();
    virtual void vo02d();
    virtual void vo02e();
    virtual void vo02f();
    virtual void vo030();
    virtual void vo031();
    virtual void vo032();
    virtual void vo033();
    virtual void vo034();
    virtual void vo035();
    virtual void vo036();
    virtual void vo037();
    virtual void vo038();
    virtual void vo039();
    virtual void vo03a();
    virtual void vo03b();
    virtual void vo03c();
    virtual void vo03d();
    virtual void vo03e();
    virtual void vo03f();
    virtual void vo040();
    virtual void vo041();
    virtual void vo042();
    virtual void vo043();
    virtual void vo044();
    virtual void vo045();
    virtual void vo046();
    virtual void vo047();
    virtual void vo048();
    virtual void vo049();
    virtual void vo04a();
    virtual void vo04b();
    virtual void vo04c();
    virtual void vo04d();
    virtual void vo04e();
    virtual void vo04f();
    virtual void vo050();
    virtual void vo051();
    virtual void vo052();
    virtual void vo053();
    virtual void vo054();
    virtual void vo055();
    virtual void vo056();
    virtual void vo057();
    virtual void vo058();
    virtual void vo059();
    virtual void vo05a();
    virtual void vo05b();
    virtual void vo05c();
    virtual void vo05d();
    virtual void vo05e();
    virtual void vo05f();
    virtual void vo060();
    virtual void vo061();
    virtual void vo062();
    virtual void vo063();
    virtual void vo064();
    virtual void vo065();
    virtual void vo066();
    virtual void vo067();
    virtual void vo068();
    virtual void vo069();
    virtual void vo06a();
    virtual void vo06b();
    virtual void vo06c();
    virtual void vo06d();
    virtual void vo06e();
    virtual void vo06f();
    virtual void vo070();
    virtual void vo071();
    virtual void vo072();
    virtual void vo073();
    virtual void vo074();
    virtual void vo075();
    virtual void vo076();
    virtual void vo077();
    virtual void vo078();
    virtual void vo079();
    virtual void vo07a();
    virtual void vo07b();
    virtual void vo07c();
    virtual NiPoint3B09* GetPos1F4();
    void FUN_009b0920(RefB09* pRef);
};

struct S009b0bf0_Box
{
    __m128 q;
    S009b0bf0_Box();
};

struct S009b0bf0_Obj
{
    void FUN_009b0bf0(const void* a0);
};

// @fnv 0x009b0bf0
void S009b0bf0_Obj::FUN_009b0bf0(const void* a0)
{
    S009b0bf0_Box box;
    reinterpret_cast<::FUN_009b0c50_Class *>(this)->FUN_009b0c50((&(::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&box)), (*(const ::fnv_004a3e00::NiPoint3 *)(a0))))));
}

struct __declspec(align(16)) hkVec4S_9b0c90
{
    __m128 m_vComponents;
    hkVec4S_9b0c90();
};

struct S_009b0c90
{
    int unk00;
    void FUN_009b0c90(const NiPoint3& p);
};

// @fnv 0x009b0920
void OwnerB09::FUN_009b0920(RefB09* pRef)
{
    if (pRef)
    {
        float fForce = reinterpret_cast<::PathingRequest *>((((::ProcessB09 *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetCenterRadius();
        if (fForce > 0.0)
        {
            hkVector4B09 kPos;
            NiPoint3B09 kRefPos;
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&kRefPos)), (*(const ::hkVector4 *)(pRef->GetPosF0(&kPos))));
            NiPoint3B09 kWorldPosition = kRefPos - *GetPos1F4();
            reinterpret_cast<::FUN_004a0c10_s *>(&(kWorldPosition))->FUN_004a0c10();
            HandleB09 kHandle;
            if (reinterpret_cast<::C00624070 *>((pRef->FUN_0043b4f0(&kHandle)))->FUN_00624070())
                *const_cast<float *>(reinterpret_cast<::FUN_004a51b0_shell *>((void *)&(const ::NiPoint3B09 &)(kWorldPosition))->FUN_004a51b0(2)) += *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingB09 *>(&::originalRuntimeFloatSetting1028))))));
            bool bMatched = false;
            if (((void *)(std::uintptr_t)(reinterpret_cast<::BSFadeNode *>(this)->FUN_009ad610())))
            {
                FormB09* pForm = ((::FormB09 *)(::bhkCollisionObject::GetFromRigidBody((const ::hkpRigidBody *)(void *)(((void *)(::FUN_004ae750((void *)(pRef))))))));
                void* pBase = pForm ? ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((pForm))->GetName())) : 0;
                void* pOther = ((void *)(::FUN_0056f930((::NiAVObject *)(pBase))));
                if (pOther && pOther == ((void *)(std::uintptr_t)(reinterpret_cast<::BSFadeNode *>(this)->FUN_009ad610())))
                {
                    HandleB09 kHandle2;
                    if (reinterpret_cast<::FUN_0043b4d0_shell *>((pRef->FUN_0043b4f0(&kHandle2)))->FUN_0043b4d0() == 20)
                        pRef->SetFlagE4(1);
                    fForce *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingB09 *>(&::g_011d0dbc))))));
                    bMatched = true;
                }
            }
            fForce = ::FUN_0062b520(fForce, (::bhkWorldObject *)(pRef), 1);
            if (!bMatched)
                fForce = FUN_0040ebd0(fForce, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingB09 *>(&::originalRuntimeFloatSetting1031)))))));
            reinterpret_cast<::S009b0bf0_Obj *>((pRef))->FUN_009b0bf0(&(const ::NiPoint3B09 &)(kWorldPosition * fForce * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingB09 *>(&::g_011cff64))))))));
            NiPoint3B09 kRandom(::RandomFloat(-1.0f, 1.0f), ::RandomFloat(-1.0f, 1.0f), ::RandomFloat(-1.0f, 1.0f));
            reinterpret_cast<::S_009b0c90 *>((pRef))->FUN_009b0c90((const ::NiPoint3 &)((const ::NiPoint3B09 &)(kRandom * fForce * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingB09 *>(&::g_011d02ec)))))))));
        }
    }
}

// @fnv 0x009b0c90
void S_009b0c90::FUN_009b0c90(const NiPoint3& p)
{
    hkVec4S_9b0c90 v;
    reinterpret_cast<::fnv_009b0cf0::FUN_009b0cf0_class *>(this)->FUN_009b0cf0((int)&((*(::hkVec4S_9b0c90 *)&(::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(v), (const ::fnv_004a3e00::NiPoint3 &)(p))))));
}

typedef __m128 ContactVector369;

// A 112-byte root contact: two vectors and each root body / shape-key path.
struct FUN_00621c40
{
    ContactVector369 position, normal;
    void* rootA;
    unsigned int keyA;
    unsigned int shapePathA[8];
    void* rootB;
    unsigned int keyB;
    unsigned int shapePathB[8];
    FUN_00621c40();
};

struct Predicate369
{
    bool flag;
};

// @fnv 0x009b2ed0
void FUN_009b2ed0(FUN_00621c40* base, int lo, int hi, Predicate369 predicate)
{
    FUN_00621c40 pivot;
// Reuse the pivot while iterating the right partition (tail recursion).
restart: {
    int j = hi;
    int i = lo;
    reinterpret_cast<::FUN_006212c0_shell *>(&(pivot))->FUN_006212c0((void *)&(base[(lo + hi) >> 1]));
    do
    {
        while (reinterpret_cast<::S_9b3080_Class *>((void *)&(predicate))->CompareBool((::S_9b3080_A *)&(base[i]), (::S_9b3080_A *)&(pivot)))
            ++i;
        while (reinterpret_cast<::S_9b3080_Class *>((void *)&(predicate))->CompareBool((::S_9b3080_A *)&(pivot), (::S_9b3080_A *)&(base[j])))
            --j;
        if (j >= i)
        {
            if (j != i)
            {
                FUN_00621c40 temp;
                FUN_00621c40* high = &base[j];
                FUN_00621c40* low = &base[i];
                reinterpret_cast<::FUN_006212c0_shell *>(&(temp))->FUN_006212c0((void *)&(*high));
                reinterpret_cast<::FUN_006212c0_shell *>((high))->FUN_006212c0((void *)&(*low));
                reinterpret_cast<::FUN_006212c0_shell *>((low))->FUN_006212c0((void *)&(temp));
            }
            --j;
            ++i;
        }
    } while (i <= j);
    if (lo < j)
        FUN_009b2ed0(base, lo, j, predicate);
    if (i < hi)
    {
        lo = i;
        goto restart;
    }
}
}
