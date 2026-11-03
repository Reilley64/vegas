// fallout/magic/magicshaderhiteffect.cpp: MagicShaderHitEffect, Effect, ThisHolder, Outer and more (45 functions)

#include "fnv/simple_list_node_view.h"
#include <cstdint>
#include <new>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/B8C4890Actor.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/EffectShaderShell.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0042fc00_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_004472a0_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_004aaf30_Holder.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00506370Class.h"
#include "fnv/decl/FUN_00506390Class.h"
#include "fnv/decl/FUN_005063b0Class.h"
#include "fnv/decl/FUN_00507040Class.h"
#include "fnv/decl/FUN_005077c0Class.h"
#include "fnv/decl/FUN_00507810Class.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00761540_cls.h"
#include "fnv/decl/FUN_008133b0_class.h"
#include "fnv/decl/FUN_0081b860_cls.h"
#include "fnv/decl/FUN_0081bc70_s.h"
#include "fnv/decl/FUN_00821600_shell.h"
#include "fnv/decl/FUN_00821620_Class.h"
#include "fnv/decl/FUN_00821640_shell.h"
#include "fnv/decl/FUN_00821660_shell.h"
#include "fnv/decl/FUN_00821680_Class.h"
#include "fnv/decl/FUN_008216a0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_008d05e0_s.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d00_shell.h"
#include "fnv/decl/FUN_00ad8570_S.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FUN_00ba8560_cls.h"
#include "fnv/decl/GO.h"
#include "fnv/decl/LookupHandler.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/ParticleInitializer.h"
#include "fnv/decl/ParticleUpdater.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_00507c90_Cls.h"
#include "fnv/decl/ShaderSource.h"
#include "fnv/decl/ShaderUpdate.h"
#include "fnv/decl/TESNPC.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_FUN_0052aa80_shell.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0081bd80__FUN_0081bd80_s.h"
#include "fnv/decl/fnv_0081bde0__FUN_0081bde0_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0087ac00__Owner0087ac00.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00490000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00567000.h"
#include "fnv/symbols_005a0000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_0080d000.h"
#include "fnv/symbols_00820000.h"
#include "fnv/symbols_00822000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/symbols_0106d000.h"
#include "fnv/symbols_0107b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f9000.h"
#include "magicshaderhiteffect_decls.h"

struct DummyClass_006a8500
{
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2(void*);
    void* pBuffer;
};

// Calls the object's vfunc2 with pBuffer, then clears pBuffer to null.
// @fnv 0x006a8500
void FUN_006a8500(DummyClass_006a8500* pThis)
{
    pThis->vfunc2(pThis->pBuffer);
    pThis->pBuffer = 0;
}

struct NavMeshPtr
{
    void* p;
    NavMeshPtr& operator=(const NavMeshPtr&);
};
struct S2f850
{
    int pad0;
    NavMeshPtr* data;
    unsigned int FUN_006c61b0(const NavMeshPtr& aValue);
};
struct NavMeshSearchLOSArray
{
};
struct Elem4;
struct FUN_006c6200_cls : public NavMeshSearchLOSArray
{
    int vt;
    Elem4* data;
    unsigned int count;
    int extra;
    void FUN_006c6200(bool flag);
};
void FUN_0081f770(void* pThis);

struct FUN_0081f320_helper
{
    void* FUN_0081f320(unsigned int flags);
};


struct Dummy0042f800
{
};

namespace fnv_00822860 {
struct UW
{
    unsigned int v;
};
}  // namespace fnv_00822860

// @fnv 0x00822580
void* FUN_00822580(int** ppObject)
{
    *ppObject = &DAT_010159d4;
    ::fnv_00822860::FUN_00822860((::fnv_00822860::AX *)(reinterpret_cast<Dummy0042f800*>(ppObject)), ::fnv_00822860::UW{0}, ::fnv_00822860::UW{0});
    return ppObject;
}

struct Elem4
{
    int v;
};
struct FUN_00822820_cls
{
    void FUN_00822820(Elem4* p, unsigned int n);
};
// @fnv 0x006c6200
void FUN_006c6200_cls::FUN_006c6200(bool abFreeStorage)
{
    if (data)
    {
        reinterpret_cast<::FUN_00822820_cls *>(this)->FUN_00822820(data, count);
        if (abFreeStorage)
        {
            ::FUN_006a8500((::DummyClass_006a8500 *)this);
            data = 0;
            extra = 0;
        }
        count = 0;
    }
}
// Calls FUN_008228f0(0) on each of the n Elem4 elements starting at p.
// @fnv 0x00822820
void FUN_00822820_cls::FUN_00822820(Elem4* apElems, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
        reinterpret_cast<::GO *>(&(apElems[i]))->FUN_008228f0(0);
}

namespace fnv_00822860 {
struct NavMeshInfo;
struct S2f850
{
    void FUN_0042fa60(NavMeshInfo**, unsigned int);
};
struct AX
{
    virtual void* v0(unsigned int);
    virtual NavMeshInfo** Allocate(unsigned int);
    NavMeshInfo** data;
    unsigned int size;
    unsigned int alloc;
};
// @fnv 0x00822860
void FUN_00822860(AX* self, UW uiMaxSize, UW uiSize)
{
    self->data = 0;
    self->size = 0;
    self->alloc = 0;
    if (uiSize.v > uiMaxSize.v)
        uiMaxSize.v = uiSize.v;
    if (uiMaxSize.v > 0)
    {
        self->data = self->Allocate(uiMaxSize.v);
        self->alloc = uiMaxSize.v;
    }
    if (uiSize.v > 0)
    {
        ((S2f850*)self)->FUN_0042fa60(self->data, uiSize.v);
        self->size = uiSize.v;
    }
}
}  // namespace fnv_00822860


// @fnv 0x0081f310
int* GetGlobalIntPtr(int* thisPtr)
{
    return &(*reinterpret_cast<int *>(&::g_011dc804));
}

struct FUN_00820b70_shell
{
    char m_auiShapeKeys[0x64];
    int m_0x64;
    float m_0x68;

    void FUN_00820b70(float a);
};

// Sets m_0x64 to 2 and stores the float argument in m_0x68.
// @fnv 0x00820b70
void FUN_00820b70_shell::FUN_00820b70(float afValue)
{
    m_0x64 = 2;
    m_0x68 = afValue;
}

// @fnv 0x00820b90
void FUN_00820b90(void* pObject)
{
    reinterpret_cast<FUN_00820b70_shell*>(pObject)->m_0x64 = 1;
}

// @fnv 0x00820bb0
void ClearField64(void* apObject)
{
    reinterpret_cast<FUN_00820b70_shell*>(apObject)->m_0x64 = 0;
}

struct Arr3520
{
};

extern int DAT_0107b824;

// @fnv 0x00822560
void FUN_00822560(Arr3520* pArray)
{
    *(intptr_t*)pArray = (intptr_t)&DAT_0107b824;
    reinterpret_cast<::FUN_006c6200_cls *>((pArray))->FUN_006c6200(true);
}

struct FUN_00820b50_shell
{
    void* GetFieldAt11C();
    char pad00[0x11c];
    unsigned int unk11c;
};

// @fnv 0x00820b50
void* FUN_00820b50_shell::GetFieldAt11C()
{
    return &unk11c;
}

struct FUN_00820bf0_shell
{
    int GetField6A4();
    unsigned int pad00[0x1a9];
    int unk6a4;
};

// The player's magic shader hit effect, the field 0x00820bf0 returns.
struct PlayerShaderHitEffectView
{
    char pad00[0x6a4];
    MagicShaderHitEffect* pShaderHitEffect;
};
// @fnv 0x00820C10
void MagicShaderHitEffect::GetSceneGraphData(bool& isActor, bool& isWeapon, float& extent, NiAVObject*& shaderObject,
                                             NiAVObject*& particleObject)
{
    bool bParticles = false;
    bool bArmor = false;
    NiAVObject* pObject = 0;
    bool bWeapon = false;
    Actor* pTargetActor = dynamic_cast<Actor*>(pTarget);
    BipedAnim* pBiped = 0;
    if (pTargetActor)
    {
        if (pTargetActor != ::_g_thePlayer)
            pBiped = pTargetActor->GetBipedAnim();
        else if (((::fnv_00490f80::FUN_00490f80((char *)(::_g_thePlayer)))) && reinterpret_cast<::PlayerShaderHitEffectView *>(::_g_thePlayer)->pShaderHitEffect == this)
            bWeapon = true;
        else
            pBiped = ((::BipedAnim *)(::_g_thePlayer->FUN_00950b00(!b3rdPerson)));
    }
    if (m_bUseActorParticleEffects || bParticles)
    {
        if (pTarget && pTarget->IsActor())
        {
            Actor* targetActor = (Actor*)pTarget;
            BaseProcess* process = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((targetActor))->GetBaseTexture()));
            if (process)
                process->vfn_148();
        }
    }
    else if (bArmor)
    {
        DisintegrateArmorEffect* effect = dynamic_cast<DisintegrateArmorEffect*>(((::ActiveEffect *)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0())));
        if (effect)
        {
            InventoryItem* item = effect->GetItem();
            if (item)
                m_pAffectedArmorObject = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()));
        }
        if (pTarget && pTarget->IsActor() && m_pAffectedArmorObject && pBiped)
        {
            BipedObject* worn = ((::BipedObject *)(reinterpret_cast<::FUN_004aaf30_Holder *>((pBiped))->FindEntry(m_pAffectedArmorObject)));
            if (worn)
                pObject = worn->object;
        }
    }
    else if (pTarget)
    {
        pObject = pTarget->GetNiNode_v();
        if (pTarget->IsActor())
        {
            if (pTarget == ::_g_thePlayer)
                pObject = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(!b3rdPerson)));
            isActor = true;
        }
        else
        {
            TESObjectWEAP* weapon = dynamic_cast<TESObjectWEAP*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pTarget))->FUN_007af430())));
            if (weapon && pObject)
            {
                isWeapon = true;
                if (reinterpret_cast<::Twin_0084d030 *>(&((*(::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((pObject))->FUN_0043d450()))))->GetStoredFloatValue() <= 0.0)
                {
                    NiUpdateData update(0.0f, false, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((pObject))->FUN_00a59c60((std::intptr_t)&(update));
                }
                NiPoint3 offset = (*(::NiPoint3 *)static_cast<void *>(&((*(::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((pObject))->FUN_0043d450()))))) - pObject->FUN_0045bb80();
                extent = reinterpret_cast<::NiPoint3 *>(&(offset))->ComputeMagnitude() + reinterpret_cast<::Twin_0084d030 *>(&((*(::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((pObject))->FUN_0043d450()))))->GetStoredFloatValue();
            }
        }
    }
    shaderObject = pObject;
    particleObject = pObject;
}

// @fnv 0x00820bf0
int FUN_00820bf0_shell::GetField6A4()
{
    return this->unk6a4;
}

struct FUN_0081bd30_s
{
    unsigned short GetSaveSize(ActiveEffect*, TESObjectREFR*);
};

struct TESSaveLoadGame
{
};
class ShaderLoadView : public MagicShaderHitEffect
{
  public:
    void FUN_00821ed0(ActiveEffect* effect, TESObjectREFR* target);
};


struct FUN_00821dd0_shell
{
    unsigned short GetEffectSaveSize(ActiveEffect*, TESObjectREFR*);
};

// Computes the save size for an active effect: base size from GetSaveSize plus 4, and if the save version is at least 0x37, adds 1 and 4 more.
// @fnv 0x00821dd0
unsigned short FUN_00821dd0_shell::GetEffectSaveSize(ActiveEffect* aEffect, TESObjectREFR* aRefr)
{
    unsigned short isize = 0;
    isize += ((FUN_0081bd30_s*)this)->GetSaveSize(aEffect, aRefr);
    isize += 4;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x37)
    {
        isize += 1;
        isize += 4;
    }
    return isize;
}

namespace fnv_008225b0 {
struct Arr3520
{
    void* m_data;
};

struct FUN_008225b0_shell : Arr3520
{
    void FUN_008225b0();
};

// @fnv 0x008225b0
void FUN_008225b0_shell::FUN_008225b0()
{
    m_data = &::DAT_010159d4;
    reinterpret_cast<::FUN_006c6200_cls *>(this)->FUN_006c6200(true);
}
}  // namespace fnv_008225b0

struct FUN_008225d0_shell
{
    void* FUN_008225d0(unsigned int param_1);
};

// Allocates a block of param_1 * 4 bytes via operator new and returns the pointer.
// @fnv 0x008225d0
void* FUN_008225d0_shell::FUN_008225d0(unsigned int param_1)
{
    void* result = ::FUN_00401000(param_1 * 4);
    return result;
}

struct AX
{
    uintptr_t vtable;
    void FUN_006b3eb0(unsigned int, unsigned int);
};

void AX::FUN_006b3eb0(unsigned int, unsigned int)
{}


struct FUN_00822600_shell : AX
{
    AX* InitVtable();
};

// Sets the object's vtable to DAT_0107b84c, calls FUN_006b3eb0 with 0, 0, and returns this as an AX pointer.
// @fnv 0x00822600
AX* FUN_00822600_shell::InitVtable()
{
    vtable = (uintptr_t)&(*reinterpret_cast<unsigned int *>(&::fnv_00822630::DAT_0107b84c));
    FUN_006b3eb0(0, 0);
    return (AX*)this;
}

namespace fnv_00822630 {
struct GlobalObject_00869f00
{
    int* m_data;
    void FUN_00822630();
};


// @fnv 0x00822630
void GlobalObject_00869f00::FUN_00822630()
{
    m_data = &DAT_0107b84c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_00822630

struct FUN_00822010_S
{
    char _p0[24];
    int _m18;
    int _m1c;
    char _p1[8];
    bool _b28;
    char _p2[7];
    TESEffectShader* _p30;
    bool FUN_00822010();
};
// @fnv 0x00822010
bool FUN_00822010_S::FUN_00822010()
{
    if (_m18 != 0)
        return false;
    if (_m1c == 0 || _p30 == 0 || _b28 || _p30 == ::FUN_0080d0d0())
        return false;
    return true;
}

extern int DAT_0107b824;
struct Caller00822860
{
};
struct FUN_00822530_shell
{
    void* vtable;
    FUN_00822530_shell* FUN_00822530();
};
// Sets the object's vtable to DAT_0107b824, calls FUN_00822860 with 0 and false, and returns this.
// @fnv 0x00822530
FUN_00822530_shell* FUN_00822530_shell::FUN_00822530()
{
    vtable = &DAT_0107b824;
    ::fnv_00822860::FUN_00822860((::fnv_00822860::AX *)(reinterpret_cast<Caller00822860*>(this)), ::fnv_00822860::UW{0}, ::fnv_00822860::UW{0});
    return this;
}

struct S008226F0
{
    void* FUN_008226f0(unsigned int);
};
// @fnv 0x008226f0
void* S008226F0::FUN_008226f0(unsigned int flags)
{
    ::FUN_00822560((::Arr3520 *)(void *)(this));
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct ThisHolder
{
    void FUN_008225b0();
    void* FUN_00822720(unsigned int);
};
// Calls FUN_008225b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00822720
void* ThisHolder::FUN_00822720(unsigned int flags)
{
    reinterpret_cast<::fnv_008225b0::FUN_008225b0_shell *>(this)->FUN_008225b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Struct00822750
{
    void* FUN_00822750(unsigned int);
};
// Calls FUN_00822630, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00822750
void* Struct00822750::FUN_00822750(unsigned int flags)
{
    reinterpret_cast<::fnv_00822630::GlobalObject_00869f00 *>(this)->FUN_00822630();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_0087d230 {
struct Arr3520
{
    virtual ~Arr3520();
};
struct FUN_008225b0 : Arr3520
{
    virtual ~FUN_008225b0();
};
struct FUN_0087d230 : FUN_008225b0
{
    virtual ~FUN_0087d230();
};
// @fnv 0x0087d230
FUN_0087d230::~FUN_0087d230()
{
    reinterpret_cast<::FUN_006c6200_cls *>(this)->FUN_006c6200(true);
}
}  // namespace fnv_0087d230

struct FUN_00820bd0_shell
{
    void SetByteAtOffset6C(unsigned char a);
    char pad00[0x6c];
    unsigned char unk6c;
    char pad6d[0x3];
};

// @fnv 0x00820bd0
void FUN_00820bd0_shell::SetByteAtOffset6C(unsigned char aucValue)
{
    this->unk6c = aucValue;
}

struct BGSSaveFormBuffer
{
};
struct FUN_0081be80_s
{
    void FUN_0081be80(BGSSaveFormBuffer*);
};
struct FUN_00822250_shell
{
    void FUN_00822250(BGSSaveFormBuffer*);
    unsigned int pad00[0xa];
    unsigned char unk28;
    unsigned char pad29[0x3];
    int unk2c;
    int unk30;
    unsigned int unk34;
    unsigned int pad38[0x5];
    unsigned char unk4c;
    unsigned char pad4d[0x3];
    unsigned int pad50[0x4];
    unsigned int unk60;
    unsigned int unk64;
};
// @fnv 0x00822250
void FUN_00822250_shell::FUN_00822250(BGSSaveFormBuffer* pBuffer)
{
    reinterpret_cast<FUN_0081be80_s*>(this)->FUN_0081be80(pBuffer);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50(&this->unk28, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50(&this->unk34, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50(&this->unk60, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50(&this->unk64, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50(&this->unk4c, 1, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(void *)(reinterpret_cast<void*>(this->unk2c)), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(void *)(reinterpret_cast<void*>(this->unk30)), 0);
}

struct Shell00822060
{
    int _p[6];
    int _f;
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
    virtual unsigned short v52(int, int);
    unsigned short FUN_00822060();
};
// Computes a size: starts at 0, adds 4 twice, then adds the result of v52(0, _f), and returns it.
// @fnv 0x00822060
unsigned short Shell00822060::FUN_00822060()
{
    unsigned short isize;
    isize = 0;
    isize += 4;
    isize += 4;
    isize += v52(0, _f);
    return isize;
}

struct Inner
{
    virtual float d0();
    virtual float d1();
    virtual float d2();
    virtual float d3();
    virtual float d4();
    virtual float d5();
    virtual float d6();
    virtual float d7();
    virtual float d8();
    virtual float d9();
    virtual float d10();
    virtual float d11();
    virtual float d12();
    virtual float d13();
    virtual float d14();
    virtual float d15();
    virtual float d16();
    virtual float d17();
    virtual float d18();
    virtual float d19();
    virtual float d20();
    virtual float d21();
    virtual float d22();
    virtual float d23();
    virtual float d24();
    virtual float d25();
    virtual float d26();
    virtual float d27();
    virtual float d28();
    virtual float d29();
    virtual float d30();
    virtual float d31();
    virtual float d32();
    virtual float d33();
    virtual float d34();
    virtual float d35();
    virtual float d36();
    virtual float d37();
    virtual float d38();
    virtual float d39();
    virtual float d40();
    virtual float d41();
    virtual float d42();
    virtual float d43();
    virtual float d44();
    virtual float d45();
    virtual float d46();
    virtual float d47();
    virtual float d48();
    virtual float d49();
    virtual float d50();
    virtual float d51();
    virtual float d52();
    virtual float d53();
    virtual float d54();
    virtual float d55();
    virtual float d56();
    virtual float d57();
    virtual float d58();
    virtual float d59();
    virtual float d60();
    virtual float d61();
    virtual float d62();
    virtual float d63();
    virtual float d64();
    virtual float d65();
    virtual float d66();
    virtual float d67();
    virtual float d68();
    virtual float d69();
    virtual float d70();
    virtual float d71();
    virtual float d72();
    virtual float d73();
    virtual float d74();
    virtual float d75();
    virtual float d76();
    virtual float d77();
    virtual float d78();
    virtual float d79();
    virtual float d80();
    virtual float d81();
    virtual float d82();
    virtual float d83();
    virtual float d84();
    virtual float d85();
    virtual float d86();
    virtual float d87();
    virtual float d88();
    virtual float d89();
    virtual float d90();
    virtual float d91();
    virtual float d92();
    virtual float d93();
    virtual float d94();
    virtual float d95();
    virtual float d96();
    virtual float d97();
    virtual float d98();
    virtual float d99();
    virtual float d100();
    virtual float d101();
    virtual float d102();
    virtual float d103();
    virtual float d104();
    virtual float d105();
    virtual float d106();
    virtual float d107();
    virtual float d108();
    virtual float d109();
    virtual float d110();
    virtual float d111();
    virtual float d112();
    virtual float d113();
    virtual float d114();
    virtual float d115();
    virtual float d116();
    virtual float d117();
    virtual float d118();
    virtual float d119();
    virtual float d120();
    virtual float d121();
    virtual float d122();
    virtual float d123();
    virtual float d124();
    virtual float d125();
    virtual float d126();
    virtual float d127();
    virtual float d128();
    virtual float d129();
    virtual float d130();
    virtual float d131();
    virtual float d132();
    virtual float d133();
    virtual float d134();
    virtual float d135();
    virtual float d136();
    virtual float d137();
    virtual float d138();
    virtual float d139();
    virtual float d140();
    virtual float d141();
    virtual float d142();
    virtual float d143();
    virtual float d144();
    virtual float d145();
    virtual float d146();
    virtual float d147();
    virtual float d148();
    virtual float d149();
    virtual float d150();
    virtual float d151();
    virtual float d152();
    virtual float d153();
    virtual float d154();
    virtual float d155();
    virtual float d156();
    virtual float d157();
    virtual float d158();
    virtual float d159();
    virtual float d160();
    virtual float d161();
    virtual float d162();
    virtual float d163();
    virtual float d164();
    virtual float d165();
    virtual float d166();
    virtual float d167();
    virtual float d168();
    virtual float d169();
    virtual float d170();
    virtual float d171();
    virtual float d172();
    virtual float d173();
    virtual float d174();
    virtual float d175();
    virtual float d176();
    virtual float d177();
    virtual float d178();
    virtual float d179();
    virtual float d180();
    virtual float d181();
    virtual float d182();
    virtual float d183();
    virtual float d184();
    virtual float d185();
    virtual float d186();
    virtual float d187();
    virtual float d188();
    virtual float d189();
    virtual float d190();
    virtual float d191();
    virtual float d192();
    virtual float d193();
    virtual float d194();
    virtual float d195();
    virtual float d196();
    virtual float d197();
    virtual float d198();
    virtual float d199();
    virtual float d200();
    virtual float d201();
    virtual float d202();
    virtual float d203();
    virtual float d204();
    virtual float d205();
    virtual float d206();
    virtual float d207();
    virtual float d208();
    virtual float d209();
    virtual float d210();
    virtual float d211();
    virtual float d212();
    virtual float d213();
    virtual float d214();
    virtual float d215();
    virtual float d216();
    virtual float d217();
    virtual float d218();
    virtual float d219();
    virtual float d220();
    virtual float d221();
    virtual float d222();
    virtual float d223();
    virtual float d224();
    virtual float d225();
    virtual float d226();
    virtual float d227();
    virtual float d228();
    virtual float d229();
    virtual float d230();
    virtual float d231();
    virtual float d232();
    virtual float d233();
    virtual float d234();
    virtual float d235();
    virtual float d236();
    virtual float d237();
    virtual float d238();
    virtual float d239();
    virtual float d240();
    virtual float d241();
    virtual float d242();
    virtual float d243();
    virtual float d244();
    virtual float d245();
    virtual float d246();
    virtual float d247();
    virtual float d248();
    virtual float d249();
    virtual float d250();
    virtual float d251();
    virtual float d252();
    virtual float d253();
    virtual float d254();
    virtual float d255();
    virtual float d256();
    virtual float d257();
    virtual float d258();
    virtual float d259();
    virtual float d260();
    virtual float d261();
    virtual float d262();
    virtual float d263();
    virtual float d264();
    virtual float d265();
    virtual float d266();
    virtual float d267();
    virtual float d268();
    virtual float d269();
    virtual float d270();
    virtual float d271();
    virtual float d272();
    virtual float d273();
    virtual float d274();
    virtual float d275();
    virtual float d276();
    virtual float d277();
    virtual float d278();
    virtual float d279();
    virtual float d280();
    virtual float d281();
    virtual float d282();
    virtual float d283();
    virtual float d284();
    virtual float d285();
    virtual float d286();
    virtual float d287();
    virtual float d288();
    virtual float d289();
    virtual float d290();
    virtual float d291();
    virtual float d292();
    virtual float d293();
    virtual float d294();
    virtual float d295();
    virtual float d296();
    virtual float d297();
    virtual float d298();
    virtual float d299();
    virtual float d300();
    virtual float d301();
    virtual float d302();
    virtual float d303();
    virtual float d304();
    virtual float d305();
    virtual float d306();
    virtual float d307();
    virtual float d308();
    virtual float d309();
    virtual float d310();
    virtual float d311();
    virtual float d312();
    virtual float d313();
    virtual float d314();
    virtual float d315();
    virtual float d316();
    virtual float d317();
    virtual float d318();
    virtual float d319();
    virtual float d320();
    virtual float d321();
    virtual float d322();
    virtual float d323();
    virtual float d324();
    virtual float d325();
    virtual float d326();
    virtual float d327();
    virtual float d328();
    virtual float d329();
    virtual float d330();
    virtual float d331();
    virtual float d332();
    virtual float d333();
    virtual float d334();
    virtual float d335();
    virtual float d336();
    virtual float d337();
    virtual float d338();
    virtual float d339();
    virtual float d340();
    virtual float d341();
    virtual float d342();
    virtual float d343();
    virtual float d344();
    virtual float d345();
    virtual float d346();
    virtual float d347();
    virtual float d348();
    virtual float d349();
    virtual float d350();
    virtual float d351();
    virtual float d352();
    virtual float d353();
    virtual float d354();
    virtual float d355();
    virtual float d356();
    virtual float d357();
    virtual float d358();
    virtual float d359();
    virtual float d360();
    virtual float d361();
    virtual float d362();
    virtual float Target();
};
struct Outer
{
    char _pad[0x68];
    Inner* p;
    float FUN_008c4850();
};
// Returns p->Target() when p is set, otherwise returns 1.0f.
// @fnv 0x008c4850
float Outer::FUN_008c4850()
{
    return p ? p->Target() : 1.0f;
}

namespace fnv_00821e40 {
struct TESSaveLoadGame
{
};

struct FUN_00821e40_shell
{
    char base[0x2c];
    TESForm* m_pAffectedArmorObject;
    void FUN_00821e40(ActiveEffect* a1, TESObjectREFR* a2);
    unsigned int pad30[0x1];
    unsigned int unk34;
};

// @fnv 0x00821e40
void FUN_00821e40_shell::FUN_00821e40(ActiveEffect* pEffect, TESObjectREFR* a2)
{
    reinterpret_cast<::fnv_0081bd80::FUN_0081bd80_s *>(this)->FUN_0081bd80((::fnv_0081bd80::ActiveEffect *)(pEffect), a2);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00821e40::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&this->unk34, 4);
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_00821e40::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x37)
    {
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00821e40::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((char*)&this->base[40], 1);
        int v = 0;
        if (m_pAffectedArmorObject)
            v = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pAffectedArmorObject))->FUN_0084e3a0()));
        reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::fnv_00821e40::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(int *)(&v), 4);
    }
}
}  // namespace fnv_00821e40

struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
};
struct BGSLoadFormBuffer
{
};
struct FUN_0081bed0_s
{
    void LoadFormData(BGSLoadFormBuffer*);
};
struct TESBoundObject;
struct TESEffectShader;
struct FUN_008222f0_s : public FUN_0081bed0_s
{
    void FUN_008222f0(BGSLoadGameBuffer*);
    char pad00[0x28];
    bool m_bUseActorParticleEffects;
    char pad29[0x3];
    TESBoundObject* m_pAffectedArmorObject;
    TESEffectShader* m_pEffectShader;
    float m_fEffectShaderScale;
    char pad38[0x14];
    bool b3rdPerson;
    char pad4d[0x13];
    float m_fAddonModelTimer;
    float m_fAddonModelScale;
};
// Loads the base form data, then reads several fields from the buffer and resolves two form IDs into a TESBoundObject and a TESEffectShader.
// @fnv 0x008222f0
void FUN_008222f0_s::FUN_008222f0(BGSLoadGameBuffer* buffer)
{
    LoadFormData((BGSLoadFormBuffer*)buffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&this->m_bUseActorParticleEffects), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&this->m_fEffectShaderScale), 4);
    if (buffer->GetVersion() >= 8)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&this->m_fAddonModelTimer), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&this->m_fAddonModelScale), 4);
    }
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBuffer*)buffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&this->b3rdPerson), 1);
    this->m_pAffectedArmorObject =
        dynamic_cast<TESBoundObject*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
    this->m_pEffectShader =
        dynamic_cast<TESEffectShader*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
}


struct FUN_00822650_shell : InventoryItem
{
    uintptr_t FindFirstItemExceedingRemaining();
};
// @fnv 0x0081FC70
bool MagicShaderHitEffect::Init()
{
    if (((::ActiveEffect *)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0())))
    {
        m_fFirstFloatValue = reinterpret_cast<::TimeoutTimer *>((((::ActiveEffect *)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0()))))->FUN_006b9130();
        bWasPlaying = !reinterpret_cast<::S3e60 *>((((::ActiveEffect *)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0()))->GetEffectSetting()))->FUN_00403e60(0x400);
        if (((::ActiveEffect *)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0()))->HasFlag(0x10))
            m_fEffectShaderScale = 100.0f;
    }
    struct ScenegraphData
    {
        float extent;
        NiAVObject* particles;
        NiAVObject* shaders;
    } scenegraph;
    bool bWeapon = false;
    bool bTargetIsActor = false;
    scenegraph.extent = 0.0f;
    bool bResetParticles = false;
    if (pTarget == ::_g_thePlayer && ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false))))
    {
        bool bThirdPerson = !reinterpret_cast<::FUN_00456630_helper *>((((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false)))))->FUN_00456610();
        bResetParticles = m_fFirstFloatValue > 0.0 && bThirdPerson != b3rdPerson;
        b3rdPerson = bThirdPerson;
    }
    scenegraph.shaders = 0;
    scenegraph.particles = 0;
    GetSceneGraphData(bTargetIsActor, bWeapon, scenegraph.extent, scenegraph.shaders, scenegraph.particles);
    if (scenegraph.shaders && scenegraph.particles && m_pEffectShader)
    {
        if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pEffectShader))->FUN_0084e3a0())) == 0x852fe || ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pEffectShader))->FUN_0084e3a0())) == 0x84a51)
        {
            SoundPlaybackHandle sound = ::FUN_00453a70()->GetSoundHandleByEditorID("AMBFireMediumLP", 0x12);
            NiPoint3 position = pTarget->GetPos();
            reinterpret_cast<::FUN_00ad8b60_h *>(&(sound))->FUN_00ad8b60(position.x, position.y, position.z);
            reinterpret_cast<::FUN_00ad89e0_shell *>(&(sound))->FUN_00ad89e0(1.0f);
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(true);
            reinterpret_cast<::FUN_00ad8f20_shell *>(&(sound))->FUN_00ad8f20(pTarget->GetNiNode_v());
        }
        bool bParticles = true;
        if (m_bUseActorParticleEffects && pTarget->IsActor() && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)pTarget)))->GetBaseTexture())))
        {
            if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)pTarget)))->GetBaseTexture()))->vfn_1b0())
                bParticles = false;
            if (!((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Actor*)pTarget)))->GetBaseTexture()))->vfn_454() && reinterpret_cast<::PlayerShaderHitEffectView *>(::_g_thePlayer)->pShaderHitEffect != this)
                bParticles = false;
        }
        if (bParticles && !reinterpret_cast<::FUN_00507040Class *>((m_pEffectShader))->FUN_00507040(8))
        {
            if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::NiPointer< ::NiNode> &)(m_pParticleShaderNode))->operator==((intptr_t)((NiNode*)0)))
            {
                m_pParticleShaderNode = new NiNode(0);
                ::AssignFixedString((char *)((m_pParticleShaderNode).operator->()), (intptr_t)&(const ::NiFixedString &)(NiFixedString("ParticleShader Geometry")), {});
                reinterpret_cast<::FUN_0043fa80_s *>(((m_pParticleShaderNode).operator->()))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&(*reinterpret_cast<unsigned char *>(&::DAT_011a9448)))));
            }
            if (!m_kParticleShaderProperties.iSize)
            {
                NiPointer<NiSourceTexture> texture(0);
                if (((::BGSTESTexture *)(reinterpret_cast<::FUN_00506390Class *>((m_pEffectShader))->GetFieldAt158()))->GetModelLength() > 0)
                {
                    char path[260];
                    ::FUN_00406d00(path, 260, "%s\\%s", "Textures",
                              ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::BGSTESTexture *)(reinterpret_cast<::FUN_00506390Class *>((m_pEffectShader))->GetFieldAt158()))))->FUN_00408da0())));
                    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_004568c0(path, (::TexPtr< ::NiSourceTexture> &)(texture), false, false);
                    struct ParticleCounts
                    {
                        int total;
                        int perShader;
                    } counts;
                    counts.total = (int)FUN_00404010(reinterpret_cast<::FUN_00644930_shell *>((m_pEffectShader))->FUN_00644930(), reinterpret_cast<::FUN_008d01e0_Class *>((m_pEffectShader))->FUN_008d01e0());
                    counts.perShader = ParticleShader::GetShaderParticleCount();
                    for (int i = 0; i * counts.perShader < counts.total; ++i)
                    {
                        NiPointer<ParticleShaderProperty> particleProperty =
                            reinterpret_cast<::FUN_005077c0Class *>((m_pEffectShader))->FUN_005077c0(m_pParticleShaderNode, scenegraph.particles,
                                                                          texture, m_fEffectShaderScale);
                        reinterpret_cast<::S2f850 *>(&(m_kParticleShaderProperties))->FUN_006c61b0((const ::NavMeshPtr &)(particleProperty));
                    }
                }
            }
            for (unsigned int i = 0; i < m_kParticleShaderProperties.iSize; ++i)
            {
                ParticleShaderProperty* property = m_kParticleShaderProperties.GetAt(i);
                if (bWeapon)
                    reinterpret_cast<::FUN_00820b70_shell *>((property))->FUN_00820b70(scenegraph.extent);
                if (m_bUseActorParticleEffects)
                    reinterpret_cast<::FUN_00820bd0_shell *>((property))->SetByteAtOffset6C(0);
                if (pTarget)
                {
                    TESObjectACTI* activator = dynamic_cast<TESObjectACTI*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pTarget))->FUN_007af430())));
                    if (bTargetIsActor || activator)
                    {
                        if (pTarget == ::_g_thePlayer && !b3rdPerson)
                            ::ClearField64((void *)(property));
                        else
                            ::FUN_00820b90(property);
                    }
                }
                reinterpret_cast<::FUN_00ba8560_cls *>((property))->DispatchRefOp((::ImgRef *)(scenegraph.particles));
                if (bResetParticles)
                {
                    reinterpret_cast<::ParticleInitializer *>((property))->InitParticles(0.0f);
                    reinterpret_cast<::ParticleUpdater *>((property))->FUN_00ba7b60((float)(m_fEffectShaderScale - 0.16599999368190765), false, true);
                    reinterpret_cast<::ParticleUpdater *>((property))->FUN_00ba7b60(m_fEffectShaderScale, false, true);
                }
            }
            vfn_cc();
        }
        else if (m_kParticleShaderProperties.iSize && (NiNode*)m_pParticleShaderNode)
        {
            for (unsigned int i = 0; i < m_kParticleShaderProperties.iSize; ++i)
                reinterpret_cast<::FUN_00507810Class *>((m_pEffectShader))->FUN_00507810(m_pParticleShaderNode.object, m_kParticleShaderProperties.GetAt(i).object);
            reinterpret_cast<::FUN_006c6200_cls *>(&(m_kParticleShaderProperties))->FUN_006c6200(true);
            if ((NiNode*)m_pParticleShaderNode)
                reinterpret_cast<::FUN_00a59d00_shell *>(((m_pParticleShaderNode).operator->()))->SetParent(0);
            m_pParticleShaderNode = (NiNode*)0;
        }
        if (!reinterpret_cast<::FUN_00507040Class *>((m_pEffectShader))->FUN_00507040(1))
        {
            if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::NiPointer< ::BSShaderPPLightingProperty::TextureEffectData> &)(spTexEffectData))->operator==((intptr_t)((BSShaderPPLightingProperty::TextureEffectData*)0)))
            {
                NiPointer<NiSourceTexture> fillTexture(0);
                if (((::BGSTESTexture *)(reinterpret_cast<::FUN_00506370Class *>((m_pEffectShader))->GetFieldAt14C()))->GetModelLength() > 0)
                {
                    char path[260];
                    ::FUN_00406d00(path, 260, "%s\\%s", "Textures",
                              ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::BGSTESTexture *)(reinterpret_cast<::FUN_00506370Class *>((m_pEffectShader))->GetFieldAt14C()))))->FUN_00408da0())));
                    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_004568c0(path, (::TexPtr< ::NiSourceTexture> &)(fillTexture), false, false);
                }
                NiPointer<NiSourceTexture> holesTexture(0);
                if (((::BGSTESTexture *)(reinterpret_cast<::FUN_005063b0Class *>((m_pEffectShader))->GetFieldAt164()))->GetModelLength() > 0)
                {
                    char path[260];
                    ::FUN_00406d00(path, 260, "%s\\%s", "Textures",
                              ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::BGSTESTexture *)(reinterpret_cast<::FUN_005063b0Class *>((m_pEffectShader))->GetFieldAt164()))))->FUN_00408da0())));
                    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_004568c0(path, (::TexPtr< ::NiSourceTexture> &)(holesTexture), false, false);
                }
                spTexEffectData = ((::BSShaderPPLightingProperty::TextureEffectData *)(reinterpret_cast<::ShaderSource *>((m_pEffectShader))->CreateEffectData((::SceneValue *)(scenegraph.shaders), fillTexture, holesTexture)));
                if ((BSShaderPPLightingProperty::TextureEffectData*)spTexEffectData &&
                    (NiSourceTexture*)spTexEffectData->spTexture && pTarget && pTarget->IsActor() &&
                    reinterpret_cast<::Outer *>((((Actor*)pTarget)))->FUN_008c4850() > 0.9900000095367432)
                {
                    reinterpret_cast<::B8C4890Actor *>((((Actor*)pTarget)))->SetProcessValue(0.99f);
                    ((Actor*)pTarget)->UpdateActorPresentation();
                }
            }
            reinterpret_cast<::EffectShaderShell *>((m_pEffectShader))->ApplyShaderToTree(scenegraph.shaders, spTexEffectData);
        }
        if (!bResetParticles && !m_kAddonModelObjects.iSize && m_pEffectShader &&
            m_pEffectShader->GetAddonModels() && m_kParticleShaderProperties.iSize > 0 &&
            (ParticleShaderProperty*)m_kParticleShaderProperties.GetAt(0) &&
            reinterpret_cast<::FUN_00658930_class *>(&((*(::NiTArray< ::NiPointer< ::NiAVObject>> *)(reinterpret_cast<::FUN_00820b50_shell *>(((m_kParticleShaderProperties.GetAt(0)).operator->()))->GetFieldAt11C()))))->GetShortAtOffsetA() > 0)
        {
            ParticleShaderProperty* property;
            BSSimpleList<DebrisModelEntry*>* entry;
            {
                WeightedResultList<const char*> weightedModels;
                entry = m_pEffectShader->GetAddonModels()->GetDataList();
                while (entry && !entry->IsEmpty())
                {
                    reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)((*((::DebrisModelEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(entry)->m_item)))->filename), 0, true, false, false, false);
                    weightedModels.AddWeightedItem((*((::DebrisModelEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(entry)->m_item)))->filename, (*((::DebrisModelEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(entry)->m_item)))->chance);
                    entry = ((::BSSimpleList< ::DebrisModelEntry *> *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070()));
                }
                property = m_kParticleShaderProperties.GetAt(0);
                for (unsigned int i = 0; i < reinterpret_cast<::FUN_00658930_class *>(&((*(::NiTArray< ::NiPointer< ::NiAVObject>> *)(reinterpret_cast<::FUN_00820b50_shell *>((property))->GetFieldAt11C()))))->GetShortAtOffsetA(); ++i)
                {
                    NiAVObject* object = (*(::NiTArray< ::NiPointer< ::NiAVObject>> *)(reinterpret_cast<::FUN_00820b50_shell *>((property))->GetFieldAt11C())).GetAt(i);
                    if (object->IsSceneNode())
                    {
                        NiPointer<Model> model(0);
                        reinterpret_cast<::FUN_004472a0_shell *>((g_modelLoader))->FUN_004472a0((char *)(((const char *)(reinterpret_cast<::FUN_00822650_shell *>((void *)&(weightedModels))->FindFirstItemExceedingRemaining()))), (void *)&(model));
                        if ((Model*)model && ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)((model).operator->())))))
                        {
                            CloningProcess cloneProcess(1.0f);
                            NiAVObject* clone = ((::NiAVObject *)(reinterpret_cast<::A5D2C0Object *>((((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)((model).operator->()))))))->FUN_00a5d2c0((::A5D2C0CloningProcess &)(cloneProcess))));
                            if (::FUN_008c7aa0())
                                reinterpret_cast<::fnv_0087ac00::Owner0087ac00 *>((TaskQueueInterface::GetSingleton()))->QueueTaskWithTwoObjects(
                                    (::fnv_0087ac00::G00559a40 *)(clone), (::fnv_0087ac00::G00559a40 *)(::NiNode *)(object->IsSceneNode()), true, false);
                            else
                                object->IsSceneNode()->AddObject(clone, true);
                            m_fAddonModelTimer = 0.0f;
                            m_fAddonModelScale = FUN_00404010(0.01f, ::FUN_00567470((char *)(m_pEffectShader)));
                            reinterpret_cast<::FUN_00440490_shell *>((clone))->FUN_00440490(m_fAddonModelScale);
                            ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(clone));
                            reinterpret_cast<::S2f850 *>(&(m_kAddonModelObjects))->FUN_006c61b0((const ::NavMeshPtr &)((const ::NiPointer< ::NiAVObject> &)(clone)));
                        }
                    }
                }
            }
        }
        if (m_kParticleShaderProperties.iSize <= 0 &&
            !(BSShaderPPLightingProperty::TextureEffectData*)spTexEffectData)
            return false;
        else
            return true;
    }
    return false;
}

// The weighted result list: its items, their weights and the total weight.
struct WeightedResultListView
{
    BSSimpleArray<void*> kItems;
    BSSimpleArray<unsigned int> kWeights;
    unsigned int uiTotalWeight;
};

// @fnv 0x00822650
uintptr_t FUN_00822650_shell::FindFirstItemExceedingRemaining()
{
    WeightedResultListView* pList = reinterpret_cast<WeightedResultListView*>(this);
    uintptr_t result = 0;
    bool found = false;
    unsigned int remaining = ::FUN_005a00a0(pList->uiTotalWeight);
    for (unsigned int i = 0; i < pList->kItems.iSize && !found; ++i)
    {
        if (remaining < pList->kWeights.pBuffer[i])
        {
            result = reinterpret_cast<uintptr_t>(pList->kItems.pBuffer[i]);
            found = true;
        }
        remaining -= pList->kWeights.pBuffer[i];
    }
    return result;
}

namespace fnv_00695230 {
typedef void* NavMeshPtr;

struct Elem4
{
    unsigned int value;
};

struct Arr3520
{
};

struct S2f850
{
    void FUN_0042fa60(NavMeshPtr*, int);
};

struct FUN_0042fc00_shell
{
};

struct FUN_006c6200_cls
{
};

struct FUN_00695230_shell
{
    virtual void unused()
    {}
    virtual void* allocate(unsigned int)
    {
        return 0;
    }

    void* data;
    unsigned int count;
    unsigned int capacity;

    void FUN_00695230(unsigned int, bool);
};

// Resizes the container to index elements: clears when index is 0, grows or shrinks the buffer and adjusts count and capacity.
// @fnv 0x00695230
void FUN_00695230_shell::FUN_00695230(unsigned int uiNewSize, bool flag)
{
    if (uiNewSize == 0)
    {
        reinterpret_cast<::FUN_006c6200_cls *>((reinterpret_cast<Arr3520*>(this)))->FUN_006c6200(flag);
        return;
    }

    if (uiNewSize > capacity)
    {
        if (capacity == 0)
        {
            data = reinterpret_cast<Elem4*>(allocate(uiNewSize));
            capacity = uiNewSize;
        }
        else
        {
            reinterpret_cast<::FUN_0042fc00_shell *>((reinterpret_cast<FUN_0042fc00_shell*>(this)))->FUN_0042fc00(reinterpret_cast<void*>(uiNewSize), count);
            capacity = uiNewSize;
        }

        reinterpret_cast<S2f850*>(this)->FUN_0042fa60(
            reinterpret_cast<NavMeshPtr*>(static_cast<unsigned char*>(data) + count * sizeof(Elem4)),
            uiNewSize - count);
        count = uiNewSize;
    }
    else if (uiNewSize < count)
    {
        reinterpret_cast<::FUN_00822820_cls *>((reinterpret_cast<FUN_006c6200_cls*>(this)))->FUN_00822820(
            (::Elem4 *)(::fnv_00695230::Elem4 *)(reinterpret_cast<Elem4*>(static_cast<unsigned char*>(data) + uiNewSize * sizeof(Elem4))), count - uiNewSize);
        count = uiNewSize;

        if (flag && uiNewSize <= capacity / 4)
        {
            reinterpret_cast<::FUN_0042fc00_shell *>((reinterpret_cast<FUN_0042fc00_shell*>(this)))->FUN_0042fc00(reinterpret_cast<void*>(uiNewSize), uiNewSize);
            capacity = uiNewSize;
        }
    }
    else
    {
        reinterpret_cast<S2f850*>(this)->FUN_0042fa60(
            reinterpret_cast<NavMeshPtr*>(static_cast<unsigned char*>(data) + count * sizeof(Elem4)),
            uiNewSize - count);
        count = uiNewSize;
    }
}
}  // namespace fnv_00695230

struct TESChallenge
{
};

struct ES_0081c630 : public TESChallenge
{
};

struct MI_0081c630
{
    ES_0081c630* GetEffectSettingForRange(int);
};

namespace FUN_00821f70_shell {
struct MagicShaderHitEffect
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37(float)
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}

    unsigned char padding0[0x1c];
    float fDuration;
    bool bWasPlaying;
    unsigned char padding1[0xb];
    void* m_pEffectShader;

    void InitHitEffect(ActiveEffect*, TESObjectREFR*, void*);
};

// @fnv 0x00821f70
void MagicShaderHitEffect::InitHitEffect(ActiveEffect* apEffect, TESObjectREFR* apTarget, void* apData)
{
    bool btempFinished;
    float ftempAge;

    reinterpret_cast<::FUN_008d05e0_s *>(this)->FUN_008d05e0((intptr_t)(apEffect), (intptr_t)(apTarget), (int)(0));

    if (apEffect != 0)
    {
        m_pEffectShader = ((void *)(reinterpret_cast<::FUN_00407820_shell *>((reinterpret_cast<MI_0081c630*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<InventoryItem*>(apEffect)))->GetName())))
                              ->GetEffectSettingForRange(0)))->FUN_00407820()));
    }
    else
    {
        m_pEffectShader = apData;
    }

    ftempAge = fDuration;
    btempFinished = bWasPlaying;

    v49();

    fDuration = ftempAge;
    bWasPlaying = btempFinished;

    v37(0.0f);
}
}

class MagicHitEffect
{
  public:
    MagicHitEffect(TESObjectREFR* apTarget, ActiveEffect* apEffect);
    virtual ~MagicHitEffect();
    unsigned int refCount;
    float m_fParticleParameter5;
    void* pCell;
    float tempAge;
    bool bInitialized;
    ActiveEffect* pEffect;
    TESObjectREFR* pTarget;
    float m_fFirstFloatValue;
    bool bWasPlaying;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    bool m_bUseActorParticleEffects;
    TESBoundObject* m_pAffectedArmorObject;
};

struct ShaderPropArray
{
    ShaderPropArray();
    ~ShaderPropArray();
    void** m_ppVirtualMethodTable;
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
};

struct AddOnArray
{
    AddOnArray();
    ~AddOnArray();
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int uiGrow;
};

class FUN_0081f580 : public MagicHitEffect
{
  public:
    TESEffectShader* m_pEffectShader;
    float m_fEffectShaderScale;
    ShaderPropArray m_kParticleShaderProperties;
    NiPointer<NiNode> m_pParticleShaderNode;
    bool b3rdPerson;
    AddOnArray m_kAddonModelObjects;
    float m_fAddonModelTimer;
    float m_fAddonModelScale;
    NiPointer<BSShaderPPLightingProperty::TextureEffectData> spTexEffectData;

    FUN_0081f580(TESObjectREFR* apTarget, TESEffectShader* apShader, float afDuration);
    virtual ~FUN_0081f580();
};

// Initializes an effect-shader hit effect: stores the shader and duration, sets up third-person state for the player, and loads the shader's addon models.
// @fnv 0x0081f580
FUN_0081f580::FUN_0081f580(TESObjectREFR* apTarget, TESEffectShader* apShader, float afDuration)
    : MagicHitEffect(apTarget, 0), m_pParticleShaderNode(0), spTexEffectData(0)
{
    m_pEffectShader = apShader;
    m_fEffectShaderScale = 0.0f;
    spTexEffectData = 0;
    m_pParticleShaderNode = 0;
    m_bUseActorParticleEffects = false;
    m_pAffectedArmorObject = 0;
    m_fAddonModelTimer = 1.0f;
    m_fAddonModelScale = 1.0f;
    if (pTarget == ::_g_thePlayer)
    {
        b3rdPerson = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false))) && !reinterpret_cast<::FUN_00456630_helper *>((((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false)))))->FUN_00456610();
    }
    else
    {
        b3rdPerson = false;
    }
    if (afDuration < 0.0)
    {
        m_fParticleParameter5 = 3.402823466e+38f;
    }
    else
    {
        m_fParticleParameter5 = afDuration;
    }
    if (m_pEffectShader && m_pEffectShader->GetAddonModels())
    {
        BSSimpleList<DebrisModelEntry*>* pIter = m_pEffectShader->GetAddonModels()->GetDataList();
        while (pIter && !pIter->IsEmpty())
        {
            reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)((*((::DebrisModelEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item)))->filename), 0, true, false, false, false);
            pIter = ((::BSSimpleList< ::DebrisModelEntry *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
    }
}

struct FUN_008220c0_cls;
struct FUN_008220c0_mgr
{
};

struct FUN_008220c0_cls
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
    virtual void v53(unsigned int a, void* b);
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    void* m_1c;
    unsigned int unk20, unk24, unk28, unk2c;
    void* m_30;
    void FUN_008220c0();
};

// Writes the values returned by FUN_0084e3a0 for m_1c and m_30 to DAT_011de45c, then calls v53(0, m_1c).
// @fnv 0x008220c0
void FUN_008220c0_cls::FUN_008220c0()
{
    unsigned int a = (unsigned int)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_1c))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::FUN_008220c0_mgr * *>(&::g_TESSaveLoadGame))))->FUN_00857a10(&a, 4);
    unsigned int b = (unsigned int)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_30))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::FUN_008220c0_mgr * *>(&::g_TESSaveLoadGame))))->FUN_00857a10(&b, 4);
    v53(0, m_1c);
}

struct FUN_008223d0_cls
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94(float);
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float m_20;
    unsigned char m_24;
    void FUN_008223d0(uintptr_t a1);
};

// Calls FUN_009dace0 with a1, saves m_20 and m_24, calls vfn_c4, restores both fields, then calls vfn_94(0.0f).
// @fnv 0x008223d0
void FUN_008223d0_cls::FUN_008223d0(uintptr_t a1)
{
    float saved;
    unsigned char savedFlag;
    reinterpret_cast<::TESNPC *>((this))->Revert((::BGSLoadFormBuffer *)(void *)((void*)a1));
    saved = m_20;
    savedFlag = m_24;
    vfn_c4();
    m_20 = saved;
    m_24 = savedFlag;
    vfn_94(0.0f);
}

struct HitEffShaderSource
{
};

struct HitEffEffectSetting : EffectSetting
{
    HitEffShaderSource* GetShaderSource(int aiIndex);
};

struct HitEffActiveEffect : ActiveEffect
{
};

struct HitEffParticleArray
{
    void** m_ppVirtualMethodTable;
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;

    HitEffParticleArray();
    ~HitEffParticleArray();
};

struct HitEffAddOnArray
{
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int uiGrow;

    HitEffAddOnArray();
    ~HitEffAddOnArray();
};

class FUN_0081f350 : public MagicHitEffect
{
  public:
    TESEffectShader* m_pEffectShader;
    float m_fEffectShaderScale;
    HitEffParticleArray m_kParticleShaderProperties;
    NiPointer<NiNode> m_pParticleShaderNode;
    bool b3rdPerson;
    HitEffAddOnArray m_kAddonModelObjects;
    float m_fAddonModelTimer;
    float m_fAddonModelScale;
    NiPointer<BSShaderPPLightingProperty::TextureEffectData> spTexEffectData;

    FUN_0081f350(TESObjectREFR* apTarget, ActiveEffect* apEffect);
    virtual ~FUN_0081f350();
};

// @fnv 0x0081f350
FUN_0081f350::FUN_0081f350(TESObjectREFR* apTarget, ActiveEffect* apEffect)
    : MagicHitEffect(apTarget, apEffect), m_pParticleShaderNode(0), spTexEffectData(0)
{
    m_pEffectShader = 0;
    m_pEffectShader =
        reinterpret_cast<::FUN_00407820_shell *>((((::HitEffEffectSetting *)(reinterpret_cast<::Twin_0044ddc0 *>((static_cast<HitEffActiveEffect*>(apEffect)))->GetName()))->GetShaderSource(0)))->FUN_00407820();
    m_fEffectShaderScale = 0.0f;
    spTexEffectData = 0;
    m_pParticleShaderNode = 0;
    m_bUseActorParticleEffects = false;
    m_pAffectedArmorObject = 0;
    m_fAddonModelTimer = 1.0f;
    m_fAddonModelScale = 1.0f;
    if (pTarget == (TESObjectREFR*)::_g_thePlayer)
        b3rdPerson = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false))) && !reinterpret_cast<::FUN_00456630_helper *>((((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false)))))->FUN_00456610();
    else
        b3rdPerson = false;

    if (false)
    {
        DisintegrateArmorEffect* pDisintegrate = dynamic_cast<DisintegrateArmorEffect*>(((::ActiveEffect *)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0())));
        if (pDisintegrate)
        {
            InventoryItem* pItem = pDisintegrate->GetItem();
            if (pItem)
                m_pAffectedArmorObject = ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pItem))->GetName()));
        }
    }

    if (m_pEffectShader && m_pEffectShader->GetAddonModels())
    {
        BSSimpleList<DebrisModelEntry*>* pIter = m_pEffectShader->GetAddonModels()->GetDataList();
        while (pIter && !pIter->IsEmpty())
        {
            reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)((*((::DebrisModelEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item)))->filename), 0, true, false, false, false);
            pIter = ((::BSSimpleList< ::DebrisModelEntry *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
    }
}

struct xNiNode
{
    void Detach(int a);
};

struct xDays
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void Detach(struct xProc* p);
};

struct xProc
{
};

template <class T> struct xPtr
{
    T* m_pObject;
    operator T*() const;
    bool operator!=(T* p) const;
    void operator=(T* p);
    ~xPtr();
};

template <class T> struct xArr
{
    void** m_ppVirtualMethodTable;
    T* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiAlloc;
    unsigned int GetSize();
    T& GetAt(int i);
    void RemoveAll(bool b);
    ~xArr();
};

template <class T> struct xArr2
{
    void** m_ppVirtualMethodTable;
    T* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiAlloc;
    int m_iPad[2];
    unsigned int GetSize();
    T& GetAt(int i);
    ~xArr2();
};

struct xEntry
{
    int m_iWordAt00;
    const char* m_pPath;
};

struct xCond
{
    bool IsDone();
};

struct xAddon
{
};

struct xModel
{
    unsigned int GetLength();
};

struct xForm
{
};

struct xAudio
{
};

struct xTES
{
};

struct xLoader
{
};

struct xRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual xNiNode* Get3D();
};

struct xEffectBase
{
    virtual void v000();
    char _pad04[0x18];
    xRef* m_pReference;
    char _pad20[0x10];
    xForm* m_pForm;
    int m_34;
    ~xEffectBase();
};

struct FUN_0081f770 : xEffectBase
{
    xArr<xPtr<xNiNode> > m_kNodeArray;
    xPtr<xNiNode> m_spNode;
    int m_4c;
    xArr2<xPtr<xProc> > m_kProcs;
    xPtr<xNiNode> m_spRootNode;
    ~FUN_0081f770();
};
// Calls FUN_0081f770 on this, then deletes this with NiMemObject::operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0081f320
void* FUN_0081f320_helper::FUN_0081f320(unsigned int flags)
{
    reinterpret_cast<struct ::FUN_0081f770 *>((this))->FUN_0081f770::~FUN_0081f770();
    if (flags & 1)
    {
        reinterpret_cast<void(__cdecl*)(void*, unsigned int)>(&((void (&)(void *) noexcept)::FUN_00aa1460))(this, 0x6c);
    }
    return this;
}


// @fnv 0x0081f770
FUN_0081f770::~FUN_0081f770()
{
    if (!reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0() & (m_pReference != (*reinterpret_cast<::xRef * *>(&::_g_thePlayer))))
        m_pReference = 0;
    if (m_spRootNode)
    {
        if (m_pReference == (*reinterpret_cast<::xRef * *>(&::_g_thePlayer)))
        {
            xNiNode* pkNode = ((::xNiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::xRef * *>(&::_g_thePlayer))))->FUN_00950bb0(1)));
            if (pkNode)
                reinterpret_cast<::S_00507c90_Cls *>((m_pForm))->ClearItemRef((::S_00507c90_Obj *)(pkNode), (::S_00507c90_Ptr *)(::xNiNode *)(m_spRootNode));
            pkNode = ((::xNiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::xRef * *>(&::_g_thePlayer))))->FUN_00950bb0(0)));
            if (pkNode)
                reinterpret_cast<::S_00507c90_Cls *>((m_pForm))->ClearItemRef((::S_00507c90_Obj *)(pkNode), (::S_00507c90_Ptr *)(::xNiNode *)(m_spRootNode));
        }
        else if (m_pReference)
        {
            xNiNode* pk3D = m_pReference->Get3D();
            if (pk3D)
                reinterpret_cast<::S_00507c90_Cls *>((m_pForm))->ClearItemRef((::S_00507c90_Obj *)(pk3D), (::S_00507c90_Ptr *)(::xNiNode *)(m_spRootNode));
        }
    }
    if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)&(const ::xPtr< ::xNiNode> &)(m_spNode))->operator!=((int)(0)))
    {
        for (unsigned int i = 0; i < m_kNodeArray.m_uiSize; i++)
            reinterpret_cast<::FUN_00507810Class *>((m_pForm))->FUN_00507810(m_spNode.m_pObject, m_kNodeArray.GetAt(i).m_pObject);
    }
    if (m_kProcs.m_uiSize > 0)
    {
        for (unsigned int j = 0; j < m_kProcs.m_uiSize; j++)
        {
            xProc* pkProc = m_kProcs.GetAt(j);
            if (((::xDays *)(reinterpret_cast<::FUN_009611e0_shell *>((pkProc))->FUN_009611e0())))
                ((::xDays *)(reinterpret_cast<::FUN_009611e0_shell *>((pkProc))->FUN_009611e0()))->Detach(pkProc);
        }
    }
    reinterpret_cast<::FUN_006c6200_cls *>(&(m_kNodeArray))->FUN_006c6200(true);
    if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)&(const ::xPtr< ::xNiNode> &)(m_spNode))->operator!=((int)(0)))
        reinterpret_cast<::FUN_00a59d00_shell *>((((xNiNode*)m_spNode)))->SetParent((::NiNode *)(0));
    m_spNode = 0;
    m_spRootNode = 0;
    if (m_pForm)
    {
        if (m_pReference && (reinterpret_cast<::FUN_0084e3a0_Class *>((m_pForm))->FUN_0084e3a0() == 0x852fe || reinterpret_cast<::FUN_0084e3a0_Class *>((m_pForm))->FUN_0084e3a0() == 0x84a51))
            reinterpret_cast<::FUN_00ad8570_S *>((((::xAudio *)(::FUN_00453a70()))))->FUN_00ad8570((intptr_t)(m_pReference->Get3D()), 1.0f, 0);
        char acPath[260];
        if (((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::xModel *)(reinterpret_cast<::FUN_00506390Class *>((m_pForm))->GetFieldAt158()))))->FUN_00408da0())))
        {
            ::FUN_00406d00(acPath, 0x104, "%s\\%s", "Textures", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::xModel *)(reinterpret_cast<::FUN_00506390Class *>((m_pForm))->GetFieldAt158()))))->FUN_00408da0())));
            reinterpret_cast<::LookupHandler *>(((*reinterpret_cast<::xTES * *>(&::g_TES))))->FUN_00456800((void *)(acPath), 0);
        }
        if (((::xModel *)(reinterpret_cast<::FUN_00506370Class *>((m_pForm))->GetFieldAt14C()))->GetLength() > 0)
        {
            ::FUN_00406d00(acPath, 0x104, "%s\\%s", "Textures", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::xModel *)(reinterpret_cast<::FUN_00506370Class *>((m_pForm))->GetFieldAt14C()))))->FUN_00408da0())));
            reinterpret_cast<::LookupHandler *>(((*reinterpret_cast<::xTES * *>(&::g_TES))))->FUN_00456800((void *)(acPath), 0);
        }
        if (m_pForm && ((::xAddon *)(reinterpret_cast<::TESEffectShader *>((m_pForm))->GetAddonModels())))
        {
            xCond* pkCond = ((::xCond *)(reinterpret_cast<::BGSDebris *>((((::xAddon *)(reinterpret_cast<::TESEffectShader *>((m_pForm))->GetAddonModels()))))->GetDataList()));
            while (pkCond && !pkCond->IsDone())
            {
                reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::xLoader * *>(&::g_modelLoader))))->FUN_0045a5e0((char *)((*((::xEntry **)(&reinterpret_cast<::SimpleListNodeView*>(pkCond)->m_item)))->m_pPath));
                pkCond = ((::xCond *)(reinterpret_cast<::Callees *>((pkCond))->FUN_00726070()));
            }
        }
    }
}

namespace ParticleUpdate {
struct Scene
{
};
struct Actor
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void v8c();
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
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual Scene* SceneGraph();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual float Scale();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void Finish(bool, bool, bool);
};
struct Texture;
template <class T> struct Ref
{
    T* value;
    T* FUN_00559450();
};
struct Texture
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    float alpha;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    float scale;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    float first;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    float second;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    Ref<void> source;
};
struct Property
{
};
struct Node
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual Node* AsNode();
};
template <class T> struct Array
{
    void** m_ppVirtualMethodTable;
    T* data;
    unsigned int count;
    unsigned int capacity;
    unsigned int FUN_0044ddc0();
    T& FUN_006a7ad0(unsigned int);
};
struct TestRef
{
    void* value;
    unsigned int unk4;
};
struct Data
{
    float FUN_00507da0(float, float, float, bool);
};
extern float DAT_0106682c;
struct Effect
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
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
    virtual void v8c();
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
    virtual void Finish();
    virtual void Refresh();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    Actor* target;
    float age;
    bool finished;
    unsigned char unk25, unk26, unk27;
    unsigned int unk28;
    unsigned int unk2c;
    Data* data;
    float timer;
    Array<Ref<Property> > properties;
    TestRef node;
    Array<Ref<Node> > addons;
    float alpha;
    float scale;
    Ref<Texture> texture;
    bool FUN_00820f30(float);
};
// Advances the effect timer, updates properties, addons and texture, and finishes the effect when all parts are done.
// @fnv 0x00820f30
bool Effect::FUN_00820f30(float afDeltaTime)
{
    if (!reinterpret_cast<::FUN_0081b860_cls *>(this)->UpdateMagicHitEffect(afDeltaTime) || !target || !target->SceneGraph())
    {
        Finish();
        return false;
    }
    timer += afDeltaTime;
    bool done = finished;
    Refresh();
    float multiplier = 1.0f;
    if (target->IsActor() && data != ((::ParticleUpdate::Data *)(::FUN_0080d0d0())))
    {
        if (((::ParticleUpdate::Texture *)(::FUN_00559450((int *)&(texture)))) && ((void *)(::FUN_00559450((int *)&(((::ParticleUpdate::Texture *)(::FUN_00559450((int *)&(texture))))->source)))) && target->IsActor() &&
            reinterpret_cast<::Outer *>((target))->FUN_008c4850() > ::CombatRegion::DAT_0106d508)
        {
            reinterpret_cast<::B8C4890Actor *>((target))->SetProcessValue(DAT_0106682c);
            reinterpret_cast<::Actor *>((target))->UpdateActorPresentation();
        }
        Scene* scene = target->SceneGraph();
        if (::FUN_0043b300((const ::NiRTTI *)(void *)(&(*reinterpret_cast<unsigned int *>(&::g_011f9140))), (::NiAVObject *)(scene)))
        {
            Scene* castScene = scene;
            multiplier = ::GetFieldB4Float((char *)(castScene));
        }
        else
            multiplier = target->Scale();
        float actorScale = reinterpret_cast<::Outer *>((target))->FUN_008c4850();
        if (actorScale > ::_DAT_01012060)
            multiplier /= actorScale;
    }
    if (properties.count > 0 && reinterpret_cast<::_FUN_0052aa80_shell *>(&(node))->operator!=(0))
    {
        float total = 0.0f;
        for (unsigned int index = 0; index < properties.count; index++)
            total += reinterpret_cast<::PathingRequest *>((((::ParticleUpdate::Property *)(::FUN_00559450((int *)&(properties.FUN_006a7ad0(index)))))))->GetTargetRadius() * ::ParticleShader::GetShaderParticleCount();
        float available = data->FUN_00507da0(total, afDeltaTime, timer, finished);
        if (available > ::_DAT_01012060)
            done = false;
        for (unsigned int index2 = 0; index2 < properties.count; index2++)
        {
            float amount = ::FUN_0040ebd0(available, float(::ParticleShader::GetShaderParticleCount()));
            available -= amount;
            Property* propertySlot1 = ((::ParticleUpdate::Property *)(::FUN_00559450((int *)&(properties.FUN_006a7ad0(index2)))));
            reinterpret_cast<::FUN_00821600_shell *>((propertySlot1))->FUN_00821600(amount / ::ParticleShader::GetShaderParticleCount());
            reinterpret_cast<::FUN_00821620_Class *>((propertySlot1))->FUN_00821620(multiplier);
            reinterpret_cast<::ParticleUpdater *>((propertySlot1))->FUN_00ba7b60(timer, false, true);
            if (((intptr_t)(reinterpret_cast<::FUN_004fd380_shell *>((propertySlot1))->FUN_004fd380())) > 0)
                done = false;
        }
        if (addons.count > 0)
        {
            float delta = afDeltaTime / (!finished ? reinterpret_cast<::FUN_00821640_shell *>((data))->FUN_00821640() : reinterpret_cast<::FUN_00821660_shell *>((data))->FUN_00821660() * ::DAT_0101a6b0);
            alpha = ::FUN_00404010(0.0f, ::FUN_0040ebd0(1.0f, alpha + delta));
            if (alpha > ::_DAT_01012060)
                done = false;
            delta = afDeltaTime / (!finished ? reinterpret_cast<::FUN_008133b0_class *>((data))->GetFloatAt144() : reinterpret_cast<::FUN_008216a0_class *>((data))->GetValue() * ::DAT_0101a6b0);
            scale = ::FUN_00404010(0.0f, ::FUN_0040ebd0(1.0f, scale + delta));
            float maximumSlot16 = 1.0f;
            float minimum = !finished ? ::FUN_00404010(::DAT_01013ea4, ::FUN_00567470((char *)(data)))
                                      : ::FUN_00404010(::DAT_01013ea4, reinterpret_cast<::FUN_00821680_Class *>((data))->FUN_00821680());
            float factorSlot13 = minimum + (maximumSlot16 - minimum) * scale;
            for (unsigned int index3 = 0; index3 < addons.count; index3++)
            {
                ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::ParticleUpdate::Node *)(((::ParticleUpdate::Node *)(::FUN_00559450((int *)&(addons.FUN_006a7ad0(index3)))))->AsNode()), alpha);
                reinterpret_cast<::FUN_00440490_shell *>((((::ParticleUpdate::Node *)(::FUN_00559450((int *)&(addons.FUN_006a7ad0(index3)))))))->FUN_00440490(factorSlot13);
            }
        }
    }
    if (((::ParticleUpdate::Texture *)(::FUN_00559450((int *)&(texture)))))
    {
        reinterpret_cast<::ShaderUpdate *>((data))->UpdateShaderState((::ShaderState *)(::ParticleUpdate::Texture *)(((::ParticleUpdate::Texture *)(::FUN_00559450((int *)&(texture))))), afDeltaTime, timer, age, finished);
        ((::ParticleUpdate::Texture *)(::FUN_00559450((int *)&(texture))))->alpha *= multiplier;
        ((::ParticleUpdate::Texture *)(::FUN_00559450((int *)&(texture))))->scale *= multiplier;
        if (((::ParticleUpdate::Texture *)(::FUN_00559450((int *)&(texture))))->second > ::_DAT_01012060 || ((::ParticleUpdate::Texture *)(::FUN_00559450((int *)&(texture))))->first > ::_DAT_01012060)
            done = false;
    }
    if (finished && done)
    {
        if (target->IsActor() && ((::ParticleUpdate::Actor *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture())))
            ((::ParticleUpdate::Actor *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->Finish(true, true, false);
        Finish();
        return false;
    }
    return true;
}
}

template <class T> struct PtrX_821bd0
{
    T* object;
    operator T*() const;
    PtrX_821bd0& operator=(T*);
    bool operator!=(int) const;
};
struct NodeX_821bd0
{
};
struct TexEffX_821bd0;
struct EffShaderX_821bd0
{
};
struct BSAudioX_821bd0
{
};

struct MagicShaderHitEffect_821bd0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    TESObjectREFR* pTarget;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    EffShaderX_821bd0* m_pEffectShader;
    float m_fEffectShaderScale;
    BSSimpleArray<NiPointer<ParticleShaderProperty> > m_kParticleShaderProperties;
    PtrX_821bd0<NodeX_821bd0> m_pParticleShaderNode;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    PtrX_821bd0<TexEffX_821bd0> spTexEffectData;
    void ApplyAndCleanup();
};

// Applies the shader effect to the target's nodes, plays a sound for certain shader types, then clears the effect data and target.
// @fnv 0x00821bd0
void MagicShaderHitEffect_821bd0::ApplyAndCleanup()
{
    if (pTarget && m_pEffectShader &&
        (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pEffectShader))->FUN_0084e3a0())) == 0x852fe || ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pEffectShader))->FUN_0084e3a0())) == 0x84a51))
        reinterpret_cast<::FUN_00ad8570_S *>((((BSAudioX_821bd0*)::FUN_00453a70())))->FUN_00ad8570((intptr_t)(pTarget->GetNiNode_v()), 1.0f, false);

    if (spTexEffectData)
    {
        if (pTarget == ::_g_thePlayer)
        {
            NiNode* pNode = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)));
            if (pNode)
                reinterpret_cast<::S_00507c90_Cls *>((m_pEffectShader))->ClearItemRef((::S_00507c90_Obj *)(pNode), (::S_00507c90_Ptr *)(::TexEffX_821bd0 *)(spTexEffectData));
            pNode = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false)));
            if (pNode)
                reinterpret_cast<::S_00507c90_Cls *>((m_pEffectShader))->ClearItemRef((::S_00507c90_Obj *)(pNode), (::S_00507c90_Ptr *)(::TexEffX_821bd0 *)(spTexEffectData));
        }
        else if (pTarget)
        {
            NiNode* pRoot = pTarget->GetNiNode_v();
            if (pRoot)
                reinterpret_cast<::S_00507c90_Cls *>((m_pEffectShader))->ClearItemRef((::S_00507c90_Obj *)(pRoot), (::S_00507c90_Ptr *)(::TexEffX_821bd0 *)(spTexEffectData));
        }
    }

    if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)&(const ::PtrX_821bd0< ::NodeX_821bd0> &)(m_pParticleShaderNode))->operator!=(0))
    {
        for (unsigned int i = 0; i < m_kParticleShaderProperties.iSize; i++)
            reinterpret_cast<::FUN_00507810Class *>((m_pEffectShader))->FUN_00507810(m_pParticleShaderNode.object, m_kParticleShaderProperties.GetAt(i).object);
    }
    reinterpret_cast<::FUN_006c6200_cls *>(&(m_kParticleShaderProperties))->FUN_006c6200(true);
    if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)&(const ::PtrX_821bd0< ::NodeX_821bd0> &)(m_pParticleShaderNode))->operator!=(0))
        reinterpret_cast<::FUN_00a59d00_shell *>((((NodeX_821bd0*)m_pParticleShaderNode)))->SetParent(0);
    m_pParticleShaderNode = 0;
    spTexEffectData = 0;
    pTarget = 0;
}


struct ThreeByThreeMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix& rhs) const;
    NiPoint3 operator*(const NiPoint3& pt) const;
public:
    ::ThreeByThreeMatrix operator+(const ::ThreeByThreeMatrix &) const;
public:
    ::ThreeByThreeMatrix *FUN_004b45b0(::ThreeByThreeMatrix *);
};

struct MyAVObject : NiAVObject
{
    const ThreeByThreeMatrix& GetWorldRotate();
};

struct PtrCheck
{
    bool operator!=(int) const;
};

struct Target3DHelper
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void* v8();
    virtual void* v9();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29();
    virtual void* v30();
    virtual void* v31();
    virtual void* v32();
    virtual void* v33();
    virtual void* v34();
    virtual void* v35();
    virtual void* v36();
    virtual void* v37();
    virtual void* v38();
    virtual void* v39();
    virtual void* v40();
    virtual void* v41();
    virtual void* v42();
    virtual void* v43();
    virtual void* v44();
    virtual void* v45();
    virtual void* v46();
    virtual void* v47();
    virtual void* v48();
    virtual void* v49();
    virtual void* v50();
    virtual void* v51();
    virtual void* v52();
    virtual void* v53();
    virtual void* v54();
    virtual void* v55();
    virtual void* v56();
    virtual void* v57();
    virtual void* v58();
    virtual void* v59();
    virtual void* v60();
    virtual void* v61();
    virtual void* v62();
    virtual void* v63();
    virtual void* v64();
    virtual void* v65();
    virtual void* v66();
    virtual void* v67();
    virtual void* v68();
    virtual void* v69();
    virtual void* v70();
    virtual void* v71();
    virtual void* v72();
    virtual void* v73();
    virtual void* v74();
    virtual void* v75();
    virtual void* v76();
    virtual void* v77();
    virtual void* v78();
    virtual void* v79();
    virtual void* v80();
    virtual void* v81();
    virtual void* v82();
    virtual void* v83();
    virtual void* v84();
    virtual void* v85();
    virtual void* v86();
    virtual void* v87();
    virtual void* v88();
    virtual void* v89();
    virtual void* v90();
    virtual void* v91();
    virtual void* v92();
    virtual void* v93();
    virtual void* v94();
    virtual void* v95();
    virtual void* v96();
    virtual void* v97();
    virtual void* v98();
    virtual void* v99();
    virtual void* v100();
    virtual void* v101();
    virtual void* v102();
    virtual void* v103();
    virtual void* v104();
    virtual void* v105();
    virtual void* v106();
    virtual void* v107();
    virtual void* v108();
    virtual void* v109();
    virtual void* v110();
    virtual void* v111();
    virtual void* v112();
    virtual void* v113();
    virtual void* v114();
    virtual void* v115();
    virtual NiAVObject* v116();
};

class EffView : public MagicShaderHitEffect
{
  public:
};

// @fnv 0x008217e0
void UpdateEffectNode(EffView* pEffectView)
{
    bool bInitTmp = (pEffectView->pTarget == ::_g_thePlayer);
    bool pTargetObj5 = (bInitTmp && ::_g_thePlayer != 0 && reinterpret_cast<::PlayerShaderHitEffectView *>(::_g_thePlayer)->pShaderHitEffect == pEffectView) ? 1 : 0;
    bool pActor1 = (bInitTmp && ::_g_thePlayer != 0 && ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false))) != 0 &&
                    reinterpret_cast<::FUN_00456630_helper *>((((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false)))))->FUN_00456610())
                       ? 1
                       : 0;
    NiAVObject* pRef4 = 0;
    if (!pEffectView->m_bUseActorParticleEffects)
    {
        if (bInitTmp)
        {
            pRef4 = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(false)));
        }
        else
        {
            pRef4 = ((Target3DHelper*)pEffectView->pTarget)->v116();
        }
    }
    else
    {
        float f_j;
        bool b_k;
        NiAVObject* p1_j;
        NiAVObject* p2_c;
        pEffectView->GetSceneGraphData(b_k, b_k, f_j, p1_j, p2_c);
        pRef4 = p2_c;
    }

    if (((PtrCheck*)&pEffectView->m_pParticleShaderNode)->operator!=(0) && pRef4 != 0)
    {
        ThreeByThreeMatrix mat = pEffectView->m_bUseActorParticleEffects ? ((MyAVObject*)pRef4)->GetWorldRotate()
                                                                : *(const ThreeByThreeMatrix*)&(*reinterpret_cast<unsigned char *>(&::DAT_011a9448));
        if (pTargetObj5)
        {
        }
        else
        {
            if (pActor1 && ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true))) != 0)
            {
                NiNode* pCastNode = ((::NiNode *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<unsigned char *>(&::g_011f4428))), (::NiObject *)(::NiAVObject *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((::_g_thePlayer))->FUN_00950bb0(true)))))));
                if (pCastNode != 0 && pCastNode != ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(((pEffectView->m_pParticleShaderNode).operator->()))->FUN_009611e0())))
                {
                    pCastNode->AddObject(pEffectView->m_pParticleShaderNode, true);
                }
                if (pActor1)
                {
                    ThreeByThreeMatrix parentTranspose;
                    reinterpret_cast<ThreeByThreeMatrix *>((void *)&(((MyAVObject*)((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(((pEffectView->m_pParticleShaderNode).operator->()))->FUN_009611e0())))->GetWorldRotate()))->FUN_004b45b0(reinterpret_cast<::ThreeByThreeMatrix *>(&parentTranspose));
                    ThreeByThreeMatrix rotation = parentTranspose * mat;
                    reinterpret_cast<::FUN_0043fa80_s *>(((pEffectView->m_pParticleShaderNode).operator->()))->FUN_0043fa80(reinterpret_cast<const ::ThreeByThreeMatrix &>(rotation));
                    NiPoint3 localOffset = parentTranspose * (pRef4->FUN_0045bb80() - ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>(((pEffectView->m_pParticleShaderNode).operator->()))->FUN_009611e0()))->FUN_0045bb80());
                    reinterpret_cast<::FUN_00440460_S *>((((MyAVObject*)(NiAVObject*)pEffectView->m_pParticleShaderNode)))->FUN_00440460((const ::V3 *)&localOffset);
                    NiUpdateData updateData(0.0f, false, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>(((pEffectView->m_pParticleShaderNode).operator->()))->FUN_00a59c60((std::intptr_t)&(updateData));
                }
                else
                {
                    reinterpret_cast<::FUN_0043fa80_s *>(((pEffectView->m_pParticleShaderNode).operator->()))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&mat)));
                    reinterpret_cast<::FUN_00440460_S *>((((MyAVObject*)(NiAVObject*)pEffectView->m_pParticleShaderNode)))->FUN_00440460((const ::V3 *)&(pRef4->FUN_0045bb80()));
                }
            }
            else
            {
                reinterpret_cast<::FUN_00440460_S *>((((MyAVObject*)(NiAVObject*)pEffectView->m_pParticleShaderNode)))->FUN_00440460((const ::V3 *)&(pRef4->FUN_0045bb80()));
                reinterpret_cast<::FUN_0043fa80_s *>(((pEffectView->m_pParticleShaderNode).operator->()))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&mat)));
            }
        }
    }

    if (pActor1 || pTargetObj5)
    {
        reinterpret_cast<::FUN_0081bc70_s *>((pEffectView))->FUN_0081bc70((::Node *)(::NiAVObject *)(0));
    }
    else
    {
        reinterpret_cast<::FUN_0081bc70_s *>((pEffectView))->FUN_0081bc70((::Node *)(::NiAVObject *)(pEffectView->m_pParticleShaderNode));
    }
}

namespace fnv_00822130 {
struct Node
{
};
struct Ref
{
};
struct Manager
{
};
extern char DAT_011841cc, DAT_01183918, DAT_01183028;
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
class Effect
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3c();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4c();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5c();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6c();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7c();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8c();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9c();
    virtual void vfna0();
    virtual void vfna4();
    virtual void vfna8();
    virtual void vfnac();
    virtual void vfnb0();
    virtual void vfnb4();
    virtual void vfnb8();
    virtual void vfnbc();
    virtual void vfnc0();
    virtual void vfnc4();
    virtual void vfnc8();
    virtual void vfncc();
    virtual void vfnd0();
    virtual void vfnd4();
    virtual void vfnd8(int, Ref*);
    virtual void vfndc(int, Ref*);
    virtual void vfne0(int, Ref*, TESEffectShader*);
    int unk04;
    float unk08;
    void* unk0c;
    float unk10;
    bool unk14;
    void* unk18;
    Ref* unk1c;
    bool FUN_00822130();
};
// Reads two 4-byte values, resolves reference and shader forms, calls vfnd8, and calls vfndc and vfne0 when both resolve.
// @fnv 0x00822130
bool Effect::FUN_00822130()
{
    bool result2 = true;
    void* firstB;
    reinterpret_cast<::FUN_00857aa0 *>(((*reinterpret_cast<::fnv_00822130::Manager * *>(&::g_TESSaveLoadGame))))->ValidateFormIDArray((unsigned int *)(void **)(&firstB), 4);
    unk1c = reinterpret_cast<Ref*>(dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(std::uintptr_t)(firstB))));
    if (!unk1c || !((::fnv_00822130::Node *)(reinterpret_cast<::LowProcess *>((unk1c))->GetTarget())) || !::FUN_00450ff0((void *)(((::fnv_00822130::Node *)(reinterpret_cast<::LowProcess *>((unk1c))->GetTarget())))))
        result2 = false;
    void* second;
    reinterpret_cast<::FUN_00857aa0 *>(((*reinterpret_cast<::fnv_00822130::Manager * *>(&::g_TESSaveLoadGame))))->ValidateFormIDArray((unsigned int *)(void **)(&second), 4);
    TESEffectShader* other7 = dynamic_cast<TESEffectShader*>(::FUN_004839c0((unsigned int)(std::uintptr_t)(second)));
    if (!other7)
        result2 = false;
    vfnd8(0, unk1c);
    if (result2)
    {
        vfndc(0, unk1c);
        vfne0(0, unk1c, other7);
    }
    return result2;
}
}  // namespace fnv_00822130

struct FUN_006e6da0
{
    int a;
};
class FUN_00633c90
{
  public:
    FUN_00633c90(int iArg);
    int unk0;
};
class ArrX
{
  public:
    void ConstructElements(FUN_006e6da0* pData, unsigned int ItemUpdateArray);
};
// @fnv 0x006c61b0
unsigned int S2f850::FUN_006c61b0(const NavMeshPtr& aValue)
{
    unsigned int uiIndex = reinterpret_cast<::FUN_00761540_cls *>(this)->FUN_00761540();
    reinterpret_cast<::ArrX *>(this)->ConstructElements((struct ::FUN_006e6da0 *)(::NavMeshPtr *)(&data[uiIndex]), 1);
    data[uiIndex] = aValue;
    return uiIndex;
}
// @fnv 0x00822780
void ArrX::ConstructElements(FUN_006e6da0* pData, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        new (&pData[i]) FUN_00633c90(0);
    }
}



// Reads effect shader scale, particle effects flag, and affected armor object ID from the save stream.
// @fnv 0x00821ed0
void ShaderLoadView::FUN_00821ed0(ActiveEffect* effect, TESObjectREFR* target)
{
    reinterpret_cast<::fnv_0081bde0::FUN_0081bde0_shell *>(this)->SaveLoad(effect, target);
    reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&m_fEffectShaderScale, 4);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x37)
    {
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&m_bUseActorParticleEffects, 1);
        unsigned int objectID;
        reinterpret_cast<::FUN_00857aa0 *>((g_TESSaveLoadGame))->ValidateFormIDArray(&objectID, 4);
        if (objectID)
            m_pAffectedArmorObject = dynamic_cast<TESBoundObject*>(::FUN_004839c0(objectID));
    }
}

#include "generated/data/fallout/magic/magicshaderhiteffect.inc"
