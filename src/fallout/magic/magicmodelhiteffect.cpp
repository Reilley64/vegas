// fallout/magic/magicmodelhiteffect.cpp: MagicModelHitEffect, Candidate (22 functions)

#include "fnv/av_object_fields.h"
#include "fnv/effect_item_fields.h"
#include "fnv/active_effect_fields.h"
#include "fnv/save_load_game_view.h"
#include <cstdint>
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BF20RefFormCall.h"
#include "fnv/decl/BSFaceGenMorphData.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00435b20_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_00453700_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00600ab0_shell.h"
#include "fnv/decl/FUN_0081b860_cls.h"
#include "fnv/decl/FUN_0081bc70_s.h"
#include "fnv/decl/FUN_0081bd30_s.h"
#include "fnv/decl/FUN_0081be80_s.h"
#include "fnv/decl/FUN_0081bed0_s.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00865e70_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_008d05e0_s.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESNPC.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0081bd80__FUN_0081bd80_s.h"
#include "fnv/decl/fnv_0081bde0__FUN_0081bde0_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008646f0__FUN_008646f0_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00a328b0__SeqExt.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0055f000.h"
#include "fnv/symbols_00563000.h"
#include "fnv/symbols_00564000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_0081e000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0103b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "magicmodelhiteffect_decls.h"
#include "magicmodelhiteffect_layout.h"

// @fnv 0x0081c950
bool MagicModelHitEffect::Init()
{
    if (((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(this)))->FUN_009611e0())))
    {
        this->m_fFirstFloatValue = reinterpret_cast<::TimeoutTimer *>((reinterpret_cast<ActiveEffect*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(this)))->FUN_009611e0())))))->FUN_006b9130();
        this->bWasPlaying = !reinterpret_cast<::S3e60 *>((reinterpret_cast<ActiveEffect*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(this)))->FUN_009611e0())))->GetEffectSetting()))->FUN_00403e60(0x400);
    }

    if (this->pTarget)
    {
        if (this->pTarget->GetNiNode())
        {
            if (this->pTarget == reinterpret_cast<TESObjectREFR*>(::_g_thePlayer))
                this->b3rdPerson = reinterpret_cast<::FUN_004eaf60_shell *>((::_g_thePlayer))->FUN_004eaf60();

            if (this->pFilename)
            {
                if (*this->pFilename)
                {
                    NiNode* model = reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((g_modelLoader))->FUN_00447080((char *)(this->pFilename), 0, true, false, false, false);
                    if (model)
                    {
                        NiControllerManager* manager = reinterpret_cast<NiControllerManager*>(((::SkyShaderProperty *)(::FUN_00653270(
                            &(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)),
                            (::NiObject *)(::NiProperty *)(reinterpret_cast<NiProperty*>(((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(reinterpret_cast<NiObjectNET*>(model)))))))))));
                        if (manager)
                        {
                            NiControllerSequence* sequence;
                            sequence = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((manager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString(::fnv_00808680::kMagicModelHitEffectName)))));
                            if (!sequence)
                                return false;
                        }
                    }

                    this->spRetainedObject = ::LoadAndCloneModel(this->pFilename);
                    reinterpret_cast<::FUN_00445300_shell *>((g_modelLoader))->FUN_00445300((char *)(this->pFilename), false, 1);
                    if (reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())
                    {
                        if (this->pTarget->GetNiNode())
                        {
                            this->AttachToTarget();
                            ::fnv_00c4b500::FUN_00c4b500((::fnv_00c4b500::Node *)(::NiAVObject *)(reinterpret_cast<NiAVObject*>(
                                reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())));

                            {
                                NiUpdateData map(
                                    static_cast<float>(static_cast<double>(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00()) / 1000.0), true,
                                    false);
                                reinterpret_cast<::FUN_00a59c60_cls *>((reinterpret_cast<NiAVObject*>(
                                    reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())))->FUN_00a59c60((std::intptr_t)&(map));
                            }

                            NiControllerManager* targetManager = reinterpret_cast<NiControllerManager*>(((::SkyShaderProperty *)(::FUN_00653270(
                                &(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)),
                                (::NiObject *)(::NiProperty *)(reinterpret_cast<NiProperty*>(
                                    ((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(reinterpret_cast<NiObjectNET*>(
                                        reinterpret_cast<NiPointer<NiNode>*>(&this->spRetainedObject)->operator->())))))))))));
                            if (targetManager)
                            {
                                NiControllerSequence* targetSequence;
                                targetSequence =
                                    ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((targetManager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString(::fnv_00808680::kMagicModelHitEffectName)))));
                                if (targetSequence)
                                {
                                    targetManager->DeactivateAllSequences(0.0f);
                                    targetManager->ActivateControllerSequence(targetSequence, 0, false, 1.0f, 0.0f, 0);
                                    reinterpret_cast<::TaskQueueInterface *>((targetManager))->QueueReferenceStateTask(true);
                                    if (this->m_fFirstFloatValue > 0.0f)
                                        reinterpret_cast<::fnv_00a328b0::SeqExt *>((targetSequence))->FUN_00a328b0(this->m_fFirstFloatValue, false);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

struct S_0081c600
{
    char pad[0x3c];
    void FUN_0081c810();
    S_0081c600* DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x0081c600
S_0081c600* S_0081c600::DestroyIfFlagged(unsigned int flags)
{
    FUN_0081c810();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x3c);
    return this;
}

struct Sub_0081c630
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
};
struct ES_0081c630
{
    char pad[0x18];
    Sub_0081c630 sub;
};
struct MI_0081c630
{
    ES_0081c630* GetEffectSettingForRange(int);
};
struct AE_0081c630
{
};
struct NP_0081c630
{
    void* p;
    NP_0081c630(int);
    ~NP_0081c630();
    NP_0081c630& operator=(void*);
};
struct CF_0081c630
{
    int f;
    CF_0081c630();
};
struct Base_0081c630
{
    char pad[0x24];
    Base_0081c630(TESObjectREFR*, AE_0081c630*);
    virtual ~Base_0081c630();
};
struct FUN_0081c630 : Base_0081c630
{
    bool b28;
    bool b29;
    int f2c;
    NP_0081c630 spA;
    NP_0081c630 spB;
    CF_0081c630 flags;
    FUN_0081c630(TESObjectREFR* ref, AE_0081c630* ae);
    virtual ~FUN_0081c630();
};
// Initialises the base with ref and ae, clears spA/spB, b29 and b28, and stores the magic item's sub.v5() result in f2c.
// @fnv 0x0081c630
FUN_0081c630::FUN_0081c630(TESObjectREFR* ref, AE_0081c630* ae) : Base_0081c630(ref, ae), spA(0), spB(0)
{
    spA = 0;
    spB = 0;
    b29 = false;
    f2c = 0;
    f2c = ((::MI_0081c630 *)(reinterpret_cast<::Twin_0044ddc0 *>((ae))->GetName()))->GetEffectSettingForRange(0)->sub.v5();
    b28 = false;
}

struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    void SetChangeFlags(struct blob4);
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
struct FUN_0081db90_shell : public BGSLoadFormBuffer
{
    void FUN_0081db90();
};


// @fnv 0x0081db90
void FUN_0081db90_shell::FUN_0081db90()
{
    reinterpret_cast<::fnv_008646f0::FUN_008646f0_shell *>((this))->FUN_008646f0();
}


struct FUN_0081c5f0_shell
{
    const NiRTTI* GetRTTI();
};

// @fnv 0x0081c5f0
const NiRTTI* FUN_0081c5f0_shell::GetRTTI()
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011dc724));
}

namespace fnv_0081c720 {
struct GO
{
    GO(int);
    ~GO();
    NiNode* m_pObject;
};
struct NP
{
    NP& operator=(void*);
};
struct CF_0081c630
{
    CF_0081c630();
    char* pBuffer;
};
struct Base_0081c630 : public MagicHitEffect
{
    Base_0081c630(TESObjectREFR* apTarget, ActiveEffect* apEffect);
};
struct FUN_0081c720 : public Base_0081c630
{
    bool m_bFirstPerson;
    bool b3rdPerson;
    const char* pFilename;
    GO m_pRenderedNodeEntry;
    GO spClone;
    CF_0081c630 kSubBuffer;
    FUN_0081c720(TESObjectREFR* apTarget, const char* apFilename, float afLifetime);
    ~FUN_0081c720();
};
// Initialises the effect with the target, filename and lifetime (clamped to FLT_MAX when negative), clearing the object and clone pointers.
// @fnv 0x0081c720
FUN_0081c720::FUN_0081c720(TESObjectREFR* apTarget, const char* apFilename, float afLifetime)
    : Base_0081c630(apTarget, 0), m_pRenderedNodeEntry(0), spClone(0)
{
    (NP&)m_pRenderedNodeEntry = 0;
    (NP&)spClone = 0;
    b3rdPerson = false;
    pFilename = apFilename;
    m_bFirstPerson = false;
    if (afLifetime < ::_DAT_01012060)
    {
        m_fParticleParameter5 = 3.402823466e+38F;
    }
    else
    {
        m_fParticleParameter5 = afLifetime;
    }
}
}  // namespace fnv_0081c720

struct ActiveEffect;
struct TESObjectREFR;
struct Flt
{
    operator unsigned int() const;
};
struct FUN_0081d0b0_t
{
    unsigned short GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);
    unsigned short FUN_0081d0b0(ActiveEffect* apEffect, TESObjectREFR* apTarget);
};
// @fnv 0x0081d0b0
unsigned short FUN_0081d0b0_t::FUN_0081d0b0(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_0081bd30_s *>(this)->GetSaveSize(apEffect, apTarget);
    isize += 2;
    if (*(Flt*)((char*)this + 0x30))
    {
        NiControllerManager* pmanager = (NiControllerManager*)((::SkyShaderProperty *)(::FUN_00653270(
            &(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(::NiProperty *)((NiProperty*)((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(((NiObjectNET*)(uintptr_t)*(Flt*)((char*)this + 0x30))))))))));
        if (pmanager)
        {
            isize += ::FUN_0055fdb0((::AnimationInterpolatorNode *)(pmanager));
        }
    }
    return isize;
}

struct FUN_0081be50_s
{
    void SetTargetCell(ActiveEffect*, TESObjectREFR*);
};

struct FUN_0081d390_s
{
    void FUN_0081d390(ActiveEffect* apEffect, TESObjectREFR* apRefr);
};

// @fnv 0x0081d390
void FUN_0081d390_s::FUN_0081d390(ActiveEffect* apEffect, TESObjectREFR* apRefr)
{
    ((FUN_0081be50_s*)this)->SetTargetCell(apEffect, apRefr);
}

struct FUN_0081d5a0_Holder
{
    char _00[24];
    int _18;
    int _1c;
    char _20[12];
    const char* _2c;
    bool FUN_0081d5a0();
};
// Returns true when _18 is zero and both _1c and _2c are non-zero; otherwise returns false.
// @fnv 0x0081d5a0
bool FUN_0081d5a0_Holder::FUN_0081d5a0()
{
    if (_18)
        return false;
    if (!_1c || !_2c)
        return false;
    return true;
}

namespace fnv_0081c810 {
struct Flt
{
    operator unsigned int();
};
struct GO
{
    void* p;
    ~GO();
    void operator=(void*);
};
struct FUN_00435b20_shell
{
    int d[3];
};
struct FUN_0081b6d0_s
{
    virtual ~FUN_0081b6d0_s();
    int pad[9];
};
struct SNode
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
    virtual void InsertChild(void*);
};
void __cdecl _Deallocate(void*);
struct FUN_0081c810 : FUN_0081b6d0_s
{
    bool m_bFirstPerson;
    char* pPath;
    GO m_pRenderedNodeEntry;
    GO spAttach;
    FUN_00435b20_shell kList;
    ~FUN_0081c810();
};
// @fnv 0x0081c810
FUN_0081c810::~FUN_0081c810()
{
    if (m_pRenderedNodeEntry.p)
    {
        NiNode* pparent = reinterpret_cast<::NiAVObjectFields *>(m_pRenderedNodeEntry.p)->m_pkParent;
        if (pparent)
            ((SNode*)pparent)->InsertChild(m_pRenderedNodeEntry.p);
        m_pRenderedNodeEntry = 0;
    }
    spAttach = 0;
    if (pPath && *pPath)
    {
        reinterpret_cast<::FUN_00445300_shell *>((g_modelLoader))->FUN_00445300((char *)(pPath), false, 1);
        if (m_bFirstPerson)
            delete pPath;
    }
    pPath = 0;
    reinterpret_cast<::FUN_00435b20_shell *>(&(kList))->FUN_00435b20();
}
}  // namespace fnv_0081c810

namespace fnv_0081d800 {
struct NiControllerManager;
struct BGSSaveFormBuffer
{
};
struct Animation
{
};
struct Actor_0081d800
{
    virtual void av000();
    virtual void av001();
    virtual void av002();
    virtual void av003();
    virtual void av004();
    virtual void av005();
    virtual void av006();
    virtual void av007();
    virtual void av008();
    virtual void av009();
    virtual void av010();
    virtual void av011();
    virtual void av012();
    virtual void av013();
    virtual void av014();
    virtual void av015();
    virtual void av016();
    virtual void av017();
    virtual void av018();
    virtual void av019();
    virtual void av020();
    virtual void av021();
    virtual void av022();
    virtual void av023();
    virtual void av024();
    virtual void av025();
    virtual void av026();
    virtual void av027();
    virtual void av028();
    virtual void av029();
    virtual void av030();
    virtual void av031();
    virtual void av032();
    virtual void av033();
    virtual void av034();
    virtual void av035();
    virtual void av036();
    virtual void av037();
    virtual void av038();
    virtual void av039();
    virtual void av040();
    virtual void av041();
    virtual void av042();
    virtual void av043();
    virtual void av044();
    virtual void av045();
    virtual void av046();
    virtual void av047();
    virtual void av048();
    virtual void av049();
    virtual void av050();
    virtual void av051();
    virtual void av052();
    virtual void av053();
    virtual void av054();
    virtual void av055();
    virtual void av056();
    virtual void av057();
    virtual void av058();
    virtual void av059();
    virtual void av060();
    virtual void av061();
    virtual void av062();
    virtual void av063();
    virtual void av064();
    virtual void av065();
    virtual void av066();
    virtual void av067();
    virtual void av068();
    virtual void av069();
    virtual void av070();
    virtual void av071();
    virtual void av072();
    virtual void av073();
    virtual void av074();
    virtual void av075();
    virtual void av076();
    virtual void av077();
    virtual void av078();
    virtual void av079();
    virtual void av080();
    virtual void av081();
    virtual void av082();
    virtual void av083();
    virtual void av084();
    virtual void av085();
    virtual void av086();
    virtual void av087();
    virtual void av088();
    virtual void av089();
    virtual void av090();
    virtual void av091();
    virtual void av092();
    virtual void av093();
    virtual void av094();
    virtual void av095();
    virtual void av096();
    virtual void av097();
    virtual void av098();
    virtual void av099();
    virtual void av100();
    virtual void av101();
    virtual void av102();
    virtual void av103();
    virtual void av104();
    virtual void av105();
    virtual void av106();
    virtual void av107();
    virtual void av108();
    virtual void av109();
    virtual void av110();
    virtual void av111();
    virtual void av112();
    virtual void av113();
    virtual void av114();
    virtual void av115();
    virtual void av116();
    virtual void av117();
    virtual void av118();
    virtual void av119();
    virtual void av120();
    virtual Animation* GetAnimation();
};
struct BGSSaveGameBuffer
{
    virtual void sv0();
    virtual void sv1();
    virtual Actor_0081d800* GetActor();
};
struct FUN_0081be80_s
{
};
struct Flt
{
    operator unsigned int();
};
struct FUN_0081d800_t
{
    void FUN_0081d800(BGSSaveGameBuffer* apSaveGameBuffer);
};
// @fnv 0x0081d800
void FUN_0081d800_t::FUN_0081d800(BGSSaveGameBuffer* apSaveGameBuffer)
{
    NiControllerManager* pmanager;
    reinterpret_cast<::FUN_0081be80_s *>((((FUN_0081be80_s*)this)))->FUN_0081be80((::BGSSaveFormBuffer *)(::fnv_0081d800::BGSSaveFormBuffer *)((BGSSaveFormBuffer*)apSaveGameBuffer));
    reinterpret_cast<::FUN_00865e70_shell *>((apSaveGameBuffer))->FUN_00865e70(*(const char**)((char*)this + 0x2c), 0);
    pmanager = 0;
    if (*(Flt*)((char*)this + 0x30))
        pmanager = (NiControllerManager*)((::SkyShaderProperty *)(::FUN_00653270(
            &(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(::NiProperty *)((NiProperty*)((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(((NiObjectNET*)(uintptr_t)*(Flt*)((char*)this + 0x30))))))))));
    {
        unsigned int uiStartPosition = reinterpret_cast<::FUN_00865f20_shell *>((((BGSSaveFormBuffer*)apSaveGameBuffer)))->FUN_00865f20();
        unsigned int uiFormIdBefore = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)apSaveGameBuffer)))->FUN_0084e3a0()));
        if (pmanager)
        {
            Actor_0081d800* pactor = apSaveGameBuffer->GetActor();
            Animation* panim = pactor ? pactor->GetAnimation() : 0;
            float ftime = panim ? reinterpret_cast<::FUN_00453700_shell *>((panim))->FUN_00453700() : -1.0f;
            ::fnv_00563f30::FUN_00563f30((::fnv_00563f30::AnimationInterpolatorNode *)(pmanager), (::fnv_00563f30::BGSSaveFormBuffer *)(apSaveGameBuffer), -1.0f);
        }
        unsigned int uiFormIdAfter = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)apSaveGameBuffer)))->FUN_0084e3a0()));
        reinterpret_cast<::FUN_00865ff0_shell *>((((BGSSaveFormBuffer*)apSaveGameBuffer)))->FUN_00865ff0(uiFormIdAfter - uiFormIdBefore, uiStartPosition);
    }
}
}  // namespace fnv_0081d800


struct FUN_0081d5d0_Class
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
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
    virtual void v37()
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
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual unsigned short v52(int, int)
    {
        return 0;
    }

    char pad00[0x18];
    int unk1c;
    char pad20[0x0c];
    const char* unk2c;

    unsigned short FUN_0081d5d0();
};

// @fnv 0x0081d5d0
unsigned short FUN_0081d5d0_Class::FUN_0081d5d0()
{
    unsigned short usSize = 0;

    usSize += 4;
    usSize += 1;
    usSize += FUN_0044a670(unk2c);
    usSize += v52(0, unk1c);

    return usSize;
}

struct FUN_0081d640_target
{
};

struct FUN_0081d640_mgr
{
    void Add(void* p, unsigned int n);
};


struct FUN_0081d640_cls
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
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void* m_1c;
    int unk20;
    int unk24;
    int unk28;
    uintptr_t m_2c;

    void FUN_0081d640();
};

// Reads the key of the object at m_1c, adds it to g_mgr, queries m_2c for a flag, sets it, and calls v53(0, m_1c).
// @fnv 0x0081d640
void FUN_0081d640_cls::FUN_0081d640()
{
    unsigned int uiKey = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((FUN_0081d640_target*)m_1c)))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::FUN_0081d640_mgr * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&uiKey), 4);
    unsigned char flag = ((unsigned char)(::FUN_0044a670((const char *)(m_2c))));
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::FUN_0081d640_mgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&flag, 1);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::FUN_0081d640_mgr * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((void*)m_2c, flag);
    v53(0, m_1c);
}

class B81D920LoadBuffer
{
  public:
};

class B81D920SubBuffer
{
  public:
    void LoadGame(B81D920LoadBuffer* pkBuffer);
};

class B81D920Loadable
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void* GetModelFilePath();
};

class B81D920Primary
{
  public:
    virtual ~B81D920Primary();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class B81D920Object
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B81D920Loadable m_kLoadable;
};

class B81D920Handle
{
  public:
};

class B81D920Ref
{
  public:
};

class B81D920ModelLoader
{
  public:
};


class B81D920Base
{
  public:
    void LoadGame(B81D920LoadBuffer* pkBuffer);
};

class FUN_0081d920_cls : public B81D920Base
{
  public:
    void FUN_0081d920(B81D920LoadBuffer* pkBuffer);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B81D920Ref* m_pkRef;
    int unk1C;
    int unk20;
    int unk24;
    bool m_bLoadComplete;
    char* m_pcName;
    int unk30;
    int unk34;
    B81D920SubBuffer m_kSubBuffer;
};

// @fnv 0x0081d920
void FUN_0081d920_cls::FUN_0081d920(B81D920LoadBuffer* pkBuffer)
{
    reinterpret_cast<::FUN_0081bed0_s *>(this)->LoadFormData((::BGSLoadFormBuffer *)(pkBuffer));
    m_pcName = reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((pkBuffer))->FUN_008649a0(0);
    m_bLoadComplete = true;
    reinterpret_cast<::BGSLoadGameSubBuffer *>(&(m_kSubBuffer))->LoadGame((::BGSLoadGameBuffer *)(pkBuffer));
    if (m_pkRef && ((::B81D920Object *)(reinterpret_cast<::EffectItemFields *>(reinterpret_cast<::ActiveEffectFields *>(m_pkRef)->effect)->setting))->m_kLoadable.GetModelFilePath())
        reinterpret_cast<::QueueHelper *>(((*reinterpret_cast<::B81D920ModelLoader * *>(&::g_modelLoader))))->FUN_00444040((int)(((::B81D920Object *)(reinterpret_cast<::EffectItemFields *>(reinterpret_cast<::ActiveEffectFields *>(m_pkRef)->effect)->setting))->m_kLoadable.GetModelFilePath()),
                                                    5, 0, 0, 1, 0, 0);
}

struct D9D0Effect
{
    void ApplyEffect(void* pkTarget);
};

// @fnv 0x0081d9d0
void D9D0Effect::ApplyEffect(void* pkTarget)
{
    reinterpret_cast<::BF20RefFormCall *>(this)->FUN_0081bf20((uintptr_t)(pkTarget));
}

class FUN_0081cc70_refvt
{
  public:
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035();
    virtual void s036();
    virtual void s037();
    virtual void s038();
    virtual void s039();
    virtual void s040();
    virtual void s041();
    virtual void s042();
    virtual void s043();
    virtual void s044();
    virtual void s045();
    virtual void s046();
    virtual void s047();
    virtual void s048();
    virtual void s049();
    virtual void s050();
    virtual void s051();
    virtual void s052();
    virtual void s053();
    virtual void s054();
    virtual void s055();
    virtual void s056();
    virtual void s057();
    virtual void s058();
    virtual void s059();
    virtual void s060();
    virtual void s061();
    virtual void s062();
    virtual void s063();
    virtual void s064();
    virtual void s065();
    virtual void s066();
    virtual void s067();
    virtual void s068();
    virtual void s069();
    virtual void s070();
    virtual void s071();
    virtual void s072();
    virtual void s073();
    virtual void s074();
    virtual void s075();
    virtual void s076();
    virtual void s077();
    virtual void s078();
    virtual void s079();
    virtual void s080();
    virtual void s081();
    virtual void s082();
    virtual void s083();
    virtual void s084();
    virtual void s085();
    virtual void s086();
    virtual void s087();
    virtual void s088();
    virtual void s089();
    virtual void s090();
    virtual void s091();
    virtual void s092();
    virtual void s093();
    virtual void s094();
    virtual void s095();
    virtual void s096();
    virtual void s097();
    virtual void s098();
    virtual void s099();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual int s116();
};
class FUN_0081cc70_thisvt
{
  public:
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035();
    virtual void s036();
    virtual void s037();
    virtual void s038();
    virtual void s039();
    virtual void s040();
    virtual void s041();
    virtual void s042();
    virtual void s043();
    virtual void s044();
    virtual void s045();
    virtual void s046();
    virtual void s047();
    virtual void s048();
    virtual void s049();
    virtual void s050();
    virtual void s051();
};
class FUN_0081cc70_seqvt
{
  public:
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035(float, bool);
};

struct FUN_0081cc70_helper
{
};

struct FUN_0081cc70_helper2
{
};

struct FUN_0081cc70_seqm
{
};

class FUN_0081cc70_cls : public MagicModelHitEffect
{
  public:
    bool FUN_0081cc70(float afTime);
};

// @fnv 0x0081cc70
bool FUN_0081cc70_cls::FUN_0081cc70(float afTime)
{
    if (pTarget == 0 || ((FUN_0081cc70_refvt*)pTarget)->s116() == 0 || !reinterpret_cast<::FUN_0081b860_cls *>(this)->UpdateMagicHitEffect(afTime))
    {
        return false;
    }
    if (((::NiAVObject *)(::FUN_00559450((int *)(((FUN_0081cc70_helper*)&spRetainedObject))))) != 0)
    {
        ((FUN_0081cc70_thisvt*)this)->s051();
        SkyShaderProperty* prop = ((::SkyShaderProperty *)(::FUN_00653270(
            &(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)),
            (::NiObject *)(::NiProperty *)(((::NiProperty *)(::fnv_0043b230::FUN_0043b230((const char *)(((FUN_0081cc70_helper2*)((::NiAVObject *)(::FUN_00559450((int *)(((FUN_0081cc70_helper*)&spRetainedObject))))))))))))));
        if (prop != 0)
        {
            NiControllerSequence* seq =
                ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((((NiControllerManager*)prop)))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("SpecialIdle_HitEffect")))));
            if (seq != 0)
            {
                if (reinterpret_cast<::BSFaceGenMorphData *>((((FUN_0081cc70_seqm*)seq)))->FUN_00508120() > reinterpret_cast<::FUN_00508100_shell *>((((FUN_0081cc70_seqm*)seq)))->FUN_00508100() &&
                    ((intptr_t)(reinterpret_cast<::LowProcess *>((((FUN_0081cc70_seqm*)seq)))->GetActiveCombatTarget())))
                {
                    if (((int)(reinterpret_cast<::ActorMover *>((((FUN_0081cc70_seqm*)seq)))->GetCurrentMoveModeType())) == 2 || bWasPlaying != 0)
                    {
                        bWasPlaying = 1;
                        ((FUN_0081cc70_seqvt*)seq)->s035(0.0f, false);
                        m_fParticleParameter5 = m_fFirstFloatValue;
                    }
                }
            }
        }
    }
    if (bWasPlaying != 0)
    {
        if ((double)m_fParticleParameter5 + 2.0 < m_fFirstFloatValue)
        {
            return false;
        }
    }
    return true;
}

struct B006815c0
{
    float x, y, z;
    B006815c0();
};
struct Node505
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node505* IsSceneNode();
    unsigned int FUN_0043b480();
    const B006815c0& FUN_0045bb80();
};
struct Form505
{
    int FUN_00401170();
};
struct Player505
{
};
struct Holder505
{
};
struct Shell505 : MagicModelHitEffect
{
    void UpdateHitEffectNode();
};
// @fnv 0x0081ce20
void Shell505::UpdateHitEffectNode()
{
    Node505* node = 0;
    if (pTarget == reinterpret_cast<TESObjectREFR*>(::_g_thePlayer))
    {
        b3rdPerson = reinterpret_cast<::FUN_004eaf60_shell *>((::_g_thePlayer))->FUN_004eaf60();
        node = ((::Node505 *)(reinterpret_cast<::FUN_00950bb0_shell *>((reinterpret_cast<Player505*>(::_g_thePlayer)))->FUN_00950bb0(false)));
    }
    else
    {
        node = reinterpret_cast<Node505*>(pTarget->GetNiNode());
    }
    reinterpret_cast<::FUN_0081bc70_s *>(this)->FUN_0081bc70((::Node *)(::Node505 *)(((::Node505 *)(::FUN_00559450((int *)(reinterpret_cast<Holder505*>(&spRetainedObject)))))));
    if (node)
    {
        B006815c0 vecPosition;
        if ((pTarget->IsActor() && pTarget->Unk_8B(false)) || pTarget->Unk_8C())
        {
            bool lower = true;
            Node505* root = node->IsSceneNode();
            if (root && root->FUN_0043b480() > 0)
            {
                Node505* pBranchNode = ((::Node505 *)(reinterpret_cast<::NiNode *>((root))->GetAt(0)));
                Node505* pChildNode = pBranchNode ? pBranchNode->IsSceneNode() : 0;
                if (pChildNode && pChildNode->FUN_0043b480() > 0)
                {
                    pBranchNode = ((::Node505 *)(reinterpret_cast<::NiNode *>((pChildNode))->GetAt(0)));
                    Node505* pLeafNode = pBranchNode ? pBranchNode->IsSceneNode() : 0;
                    if (pLeafNode && reinterpret_cast<::NiPlane *>(&((*(::B006815c0 *)&(reinterpret_cast<::NiAVObject *>((pLeafNode))->FUN_0043c490()))))->operator==((const ::NiPlane &)((*reinterpret_cast<::B006815c0 *>((void *)&::NiPoint3::ZERO)))))
                        lower = false;
                }
            }
            vecPosition = node->FUN_0045bb80();
            if (lower)
                vecPosition.z -= 64.0;
        }
        else if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pTarget))->FUN_007af430())) &&
                 reinterpret_cast<Form505*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pTarget))->FUN_007af430())))->FUN_00401170() == 28)
        {
            vecPosition = (*(::B006815c0 *)(static_cast<void *>(((::Node505 *)(reinterpret_cast<::FUN_0043d450_Owner *>((node))->FUN_0043d450())))));
            vecPosition.z = node->FUN_0045bb80().z;
        }
        else
        {
            vecPosition = node->FUN_0045bb80();
        }
        if (((::Node505 *)(::FUN_00559450((int *)(reinterpret_cast<Holder505*>(&spRetainedObject))))))
        {
            reinterpret_cast<::FUN_00440460_S *>((((::Node505 *)(::FUN_00559450((int *)(reinterpret_cast<Holder505*>(&spRetainedObject)))))))->FUN_00440460((const ::V3 *)&(vecPosition));
            reinterpret_cast<::FUN_0043fa80_s *>((((::Node505 *)(::FUN_00559450((int *)(reinterpret_cast<Holder505*>(&spRetainedObject)))))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(::FUN_006a9540((char *)(node)))));
        }
    }
}

class AnimationLocal
{
  public:
};
class BaseProcess
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
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
    virtual AnimationLocal* GetAnimation();
};
class MiddleHighProcess : public BaseProcess
{
};
struct ActorLocal : TESObjectREFR
{
};
struct EffectItemLocal
{
};
struct EffectLocal
{
};
struct ObjectPtrLocal
{
    NiAVObject* object;
};
struct SaveManagerLocal
{
};
struct Candidate : MagicModelHitEffect
{
    void SetFilenameAndInit(EffectLocal*, TESObjectREFR*, const char*);
};
// @fnv 0x0081d3b0
void Candidate::SetFilenameAndInit(EffectLocal* effect, TESObjectREFR* target, const char* pFilenameArg)
{
    reinterpret_cast<::FUN_008d05e0_s *>(this)->FUN_008d05e0((intptr_t)(effect), (intptr_t)(target), 0);
    const char* previous = pFilename;
    if (effect)
    {
        pFilename = reinterpret_cast<const char*>(((::ES_0081c630 *)(reinterpret_cast<::EffectItemFields *>(reinterpret_cast<::ActiveEffectFields *>(effect)->effect)->setting))->sub.v5());
    }
    else
    {
        pFilename = pFilenameArg;
    }
    float age = MagicHitEffect::m_fFirstFloatValue;
    bool finished = bWasPlaying;
    Init();
    MagicHitEffect::m_fFirstFloatValue = age;
    bWasPlaying = finished;
    const char* saved = ((const char *)(reinterpret_cast<::SaveLoadGameView *>(::g_TESSaveLoadGame)->pBufferCursor));
    reinterpret_cast<::FUN_00600ab0_shell *>(((*reinterpret_cast<::SaveManagerLocal * *>(&::g_TESSaveLoadGame))))->FUN_00600ab0((int)(previous));
    unsigned short version3;
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveManagerLocal * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&version3, 2);
    if (((::NiAVObject *)(::FUN_00559450((int *)(reinterpret_cast<ObjectPtrLocal*>(&spRetainedObject))))))
    {
        void* controller4 = ((void *)(::FUN_00653270(
            &(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)),
            (::NiObject *)(::NiTimeController *)(((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(reinterpret_cast<NiObjectNET*>(((::NiAVObject *)(::FUN_00559450((int *)(reinterpret_cast<ObjectPtrLocal*>(&spRetainedObject))))))))))))));
        if (controller4)
        {
            float time_ = DAT_01012054;
            ActorLocal* actor4 = target && target->IsActor() ? reinterpret_cast<ActorLocal*>(target) : 0;
            MiddleHighProcess* aProcess;
            if (actor4 && effect && (aProcess = dynamic_cast<MiddleHighProcess*>(((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor4))->GetBaseTexture())))) &&
                aProcess->GetAnimation())
                time_ = reinterpret_cast<::FUN_00453700_shell *>((aProcess->GetAnimation()))->FUN_00453700();
            ::FUN_0055ffa0((::AnimationInterpolatorNode *)(controller4), (::NiNode *)(::NiAVObject *)(((::NiAVObject *)(::FUN_00559450((int *)(reinterpret_cast<ObjectPtrLocal*>(&spRetainedObject)))))), time_);
        }
    }
    reinterpret_cast<::FUN_00600ab0_shell *>(((*reinterpret_cast<::SaveManagerLocal * *>(&::g_TESSaveLoadGame))))->FUN_00600ab0((intptr_t)(saved));
    FUN_00401030(const_cast<char*>(previous));
    Update(0.0f);
}

struct AnimDataStub
{
};
struct ActorStub
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual AnimDataStub* GetAnimData();
};
struct LoadFormBufferStub : public BGSLoadFormBuffer
{
    ~LoadFormBufferStub();
};
struct SubBufferAccess
{
    char* pBuffer;
    operator char*() const;
};
struct ModelObjectStub
{
};
struct ModelPtrAccess
{
    ModelObjectStub* m_pObject;
    operator ModelObjectStub*() const;
};

struct FUN_0081d9f0_shell : public MagicModelHitEffect
{
    void LoadMagicModelHitEffect(BGSLoadGameBuffer* apBuffer);
};

// @fnv 0x0081d9f0
void FUN_0081d9f0_shell::LoadMagicModelHitEffect(BGSLoadGameBuffer* apBuffer)
{
    reinterpret_cast<::TESNPC *>(this)->Revert((::BGSLoadFormBuffer *)(apBuffer));
    float fSavedAge = m_fFirstFloatValue;
    bool bSavedFinished5 = bWasPlaying;
    Init();
    m_fFirstFloatValue = fSavedAge;
    bWasPlaying = bSavedFinished5;
    if (*(SubBufferAccess*)&m_kLoadGameSubBuffer)
    {
        NiNode* pNodeX = 0;
        if (*(ModelPtrAccess*)&spRetainedObject)
            pNodeX =
                ((::NiNode *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), ((::NiObject *)(::fnv_0043b230::FUN_0043b230((const char *)(((ModelObjectStub*)*(ModelPtrAccess*)&spRetainedObject))))))));
        if (pNodeX)
        {
            ActorStub* pActor4 = (ActorStub*)apBuffer->GetActor();
            AnimDataStub* pAnim2 = pActor4 ? pActor4->GetAnimData() : 0;
            float fTime = pAnim2 ? reinterpret_cast<::FUN_00453700_shell *>((pAnim2))->FUN_00453700() : -1.0f;
            LoadFormBufferStub* pLoadBuffer = ((::LoadFormBufferStub *)(reinterpret_cast<::BGSLoadGameSubBuffer *>((((SubBufferAccess*)&m_kLoadGameSubBuffer)))->CreateFormBuffer((::TESForm *)(0))));
            ::fnv_00564010::UpdatePackagesFromBuffer((::fnv_00564010::Mgr *)(pNodeX), (::fnv_00564010::Buf *)(pLoadBuffer), fTime);
            delete pLoadBuffer;
        }
    }
    reinterpret_cast<::FUN_00435b20_shell *>((((SubBufferAccess*)&m_kLoadGameSubBuffer)))->FUN_00435b20();
    Update(0.0f);
}

struct FUN_0081bd80_shell
{
};
struct TESSaveLoadGame
{
};
struct Animation
{
};
struct RefV_0081d150
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
    virtual bool IsActor();
};
struct TES
{
};

struct FUN_0081d150_t
{
    void FUN_0081d150(ActiveEffect* apEffect, TESObjectREFR* apTarget);
};

// Calls the base helper, passes a 16-bit value to g_TESSaveLoadGame, and may update a controller manager using an actor's animation time.
// @fnv 0x0081d150
void FUN_0081d150_t::FUN_0081d150(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    reinterpret_cast<::fnv_0081bd80::FUN_0081bd80_s *>((((FUN_0081bd80_shell*)this)))->FUN_0081bd80((::fnv_0081bd80::ActiveEffect *)(apEffect), apTarget);
    NiControllerManager* pmanager = 0;
    if ((unsigned int)*(Flt*)((char*)this + 0x30))
        pmanager = (NiControllerManager*)((::SkyShaderProperty *)(::FUN_00653270(
            &(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(::NiProperty *)((NiProperty*)((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(((NiObjectNET*)(uintptr_t)*(Flt*)((char*)this + 0x30))))))))));
    unsigned short usState = 0;
    if (pmanager)
        usState = ::FUN_0055fdb0((::AnimationInterpolatorNode *)(pmanager));
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&usState, 2);
    if (usState)
    {
        float ftime = -1.0f;
        TES* pactor = (apTarget && ((RefV_0081d150*)apTarget)->IsActor()) ? (TES*)apTarget : 0;
        if (pactor && apEffect)
        {
            MiddleHighProcess* pprocess = dynamic_cast<MiddleHighProcess*>((BaseProcess*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pactor))->GetBaseTexture())));
            if (pprocess && pprocess->GetAnimation())
                ftime = reinterpret_cast<::FUN_00453700_shell *>((pprocess->GetAnimation()))->FUN_00453700();
        }
        ::fnv_0055fe70::FUN_0055fe70((::AnimationInterpolatorNode *)(pmanager), ftime);
    }
}

#include <string.h>
namespace fnv_0081d2a0 {
class TESModel : public BaseFormComponent
{
  public:
    virtual ~TESModel();
    virtual const char* GetModelFilePath();
};
struct QueueHelper
{
};
struct TESSaveLoadGame
{
};
struct FUN_0081d2a0_t
{
    void FUN_0081d2a0(ActiveEffect* apEffect, TESObjectREFR* apTarget);
};
// Calls SaveLoad, queues the effect model for loading if present, and reads a size-prefixed buffer from the save stream into the object.
// @fnv 0x0081d2a0
void FUN_0081d2a0_t::FUN_0081d2a0(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    unsigned short isize;
    char* pbuffer;
    reinterpret_cast<::fnv_0081bde0::FUN_0081bde0_shell *>(this)->SaveLoad(apEffect, apTarget);
    if (apEffect &&
        ((TESModel*)(reinterpret_cast<char *>(reinterpret_cast<::EffectItemFields *>(reinterpret_cast<::ActiveEffectFields *>(apEffect)->effect)->setting) + 0x18))->GetModelFilePath())
    {
        reinterpret_cast<::QueueHelper *>((((QueueHelper*)g_modelLoader)))->FUN_00444040((int)((TESModel*)(reinterpret_cast<char *>(reinterpret_cast<::EffectItemFields *>(reinterpret_cast<::ActiveEffectFields *>(apEffect)->effect)->setting) + 0x18))
                               ->GetModelFilePath(),
                           5, 0, 0, true, false, false);
    }
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0081d2a0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&isize, 2);
    if (isize)
    {
        pbuffer = (char*)::FUN_00401000(isize + 2);
        memcpy(pbuffer, &isize, 2);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0081d2a0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(pbuffer + 2, isize);
        *(char**)((char*)this + 0x2c) = pbuffer;
    }
}
}  // namespace fnv_0081d2a0

namespace fnv_0081d6c0 {
class TESSaveLoadGame
{
  public:
};

struct FUN_0081d6c0_shell : public MagicModelHitEffect
{
    bool FUN_0081d6c0();
};

// MagicModelHitEffect::LoadGame (vB4)
// Validates a form ID and target cell, reads a string, then calls LoadGame, InitLoadGame and FinishLoadGameTES on the target.
// @fnv 0x0081d6c0
bool FUN_0081d6c0_shell::FUN_0081d6c0()
{
    bool bSuccess = true;
    unsigned int iformID;
    reinterpret_cast<::FUN_00857aa0 *>(((*reinterpret_cast<::fnv_0081d6c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->ValidateFormIDArray(&iformID, 4);
    pTarget = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(iformID));
    if (!pTarget || !((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pTarget))->GetTarget())) || !::FUN_00450ff0((void *)(((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pTarget))->GetTarget())))))
        bSuccess = false;
    {
        unsigned char isize;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0081d6c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&isize, 1);
        char* pBuffer = new char[isize + 1];
        memset(pBuffer, 0, isize + 1);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0081d6c0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(pBuffer, isize);
        m_bFirstPerson = true;
        LoadGame(0, pTarget);
        if (bSuccess)
        {
            InitLoadGame(0, pTarget);
            FinishLoadGameTES(0, pTarget, pBuffer);
        }
    }
    return bSuccess;
}
}  // namespace fnv_0081d6c0

#include "generated/data/fallout/magic/magicmodelhiteffect.inc"
