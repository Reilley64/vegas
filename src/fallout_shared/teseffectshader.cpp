// fallout_shared/teseffectshader.cpp: TESEffectShader, EffectShaderData, EffectShaderShell, ShaderSettings and more (26 functions)

#include <new>
#include <cstring>
#include <malloc.h>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/B5081D0Actor.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/C508240Ref.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004a0d90_Class.h"
#include "fnv/decl/FUN_004e3d00_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fd3a0_shell.h"
#include "fnv/decl/FUN_00507550_Class.h"
#include "fnv/decl/FUN_00507570_Class.h"
#include "fnv/decl/FUN_005075f0_class.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_005076c0Class.h"
#include "fnv/decl/FUN_005076e0_Class.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00507720_Class.h"
#include "fnv/decl/FUN_00507740_Class.h"
#include "fnv/decl/FUN_00507760_Class.h"
#include "fnv/decl/FUN_00507780.h"
#include "fnv/decl/FUN_005077a0_Class.h"
#include "fnv/decl/FUN_00507d80_Class.h"
#include "fnv/decl/FUN_00508050_Class.h"
#include "fnv/decl/FUN_00508070_class.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0051b8c0_shell.h"
#include "fnv/decl/FUN_005f9b10_class.h"
#include "fnv/decl/FUN_00639aa0_shell.h"
#include "fnv/decl/FUN_0068a830_shell.h"
#include "fnv/decl/FUN_006d30e0_Class.h"
#include "fnv/decl/FUN_006e4320_Class.h"
#include "fnv/decl/FUN_006e4ef0_shell.h"
#include "fnv/decl/FUN_006e5ee0_Class.h"
#include "fnv/decl/FUN_00733fd0_shell.h"
#include "fnv/decl/FUN_00810550_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/ParticleInitializer.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/TESObjectTREE.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_009314d0__FUN_009314d0_class.h"
#include "fnv/decl/fnv_00b675c0__FUN_00b675c0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_00ba6000.h"
#include "../teseffectshader.h"
#include "TESFile.h"

// @fnv 0x00506510
void EffectShaderData::Initialize()
{
    cFlags = 0;
    m_eDestinationBlend = static_cast<_D3DBLEND>(5);
    m_eBlendOperation = static_cast<_D3DBLENDOP>(1);
    m_eDepthCompareFunction = static_cast<_NDLZCMPFUNC>(3);
    BlendDepthState = 0;
    BlendDepthParameters = 0.0f;
    DepthCompareParameters = 0.0f;
    IndexedFloatParameters = 0.0f;
    ShaderFloatParameterSet = 0.0f;
    ShaderParameterFormatSet = 0.0f;
    SevenFloatParameterRecord = 1.0f;
    SixFloatAndUnsignedIntegerRecord = 0.0f;
    SixFloatUnsignedIntegerAndFloatRecord = 0.0f;
    ExtendedFloatFlagParameters = 1.0f;
    ShaderFloatParameterBlock = 0;
    SixFloatRecordWithMiddleFlag = 0.0f;
    FloatFlagParameters = 0.0f;
    SixFloatRecordWithLeadingFlag = 0.0f;
    BlendFloatParameters = 0.0f;
    AlphaBlendParameters = 0.0f;
    BlendStateParameters = 1.0f;
    m_eSourceBlend = static_cast<_D3DBLEND>(6);
    BlendFactorState = 1.0f;
    BlendModeConfiguration = 1.0f;
    m_eAlphaSourceBlend = static_cast<_D3DBLEND>(5);
    m_eAlphaDestinationBlend = static_cast<_D3DBLEND>(6);
    m_eAlphaBlendOperation = static_cast<_D3DBLENDOP>(1);
    m_eAlphaDepthCompareFunction = static_cast<_NDLZCMPFUNC>(4);
    AlphaBlendSettings = 0.0f;
    m_fAlphaBlendParameter = 0.0f;
    BlendFactorParameters = 0.0f;
    m_fShaderFloatParameter1 = 1.0f;
    m_fShaderFloatParameter2 = 1.0f;
    m_fShaderFloatParameter3 = 1.0f;
    m_fShaderFloatParameter4 = 0.0f;
    m_fShaderFloatParameter5 = 0.0f;
    m_fShaderFloatParameter6 = 0.0f;
    VelocityState = NiPoint3(0.0f, 0.0f, 0.0f);
    m_kVectorState2 = NiPoint3(0.0f, 0.0f, 0.0f);
    m_fShaderFloatParameter7 = 1.0f;
    m_fShaderFloatParameter8 = 1.0f;
    m_fShaderFloatParameter9 = 0.0f;
    m_fShaderFloatParameter10 = 1.0f;
    m_uiColorParameter1 = 16777215;
    m_uiColorParameter2 = 16777215;
    m_uiColorParameter3 = 16777215;
    m_fShaderFloatParameter11 = 1.0f;
    m_fShaderFloatParameter12 = 1.0f;
    m_fShaderFloatParameter13 = 1.0f;
    m_fShaderFloatParameter14 = 0.0f;
    m_fShaderFloatParameter15 = 0.5f;
    m_fShaderFloatParameter16 = 1.0f;
    m_fShaderFloatParameter17 = 0.0f;
    m_fShaderFloatParameter18 = 0.0f;
    m_fShaderFloatParameter19 = 0.0f;
    m_fShaderFloatParameter20 = 0.0f;
    m_fShaderFloatParameter21 = 0.0f;
    DebrisModelSettings = 0.0f;
    EffectShaderAddonData = 10.0f;
    DebrisColorSettings = 255.0f;
    EffectShaderColorData = 0.0f;
    EffectShaderParameters = 0.0f;
    m_uiBaseColor = 16777215;
    m_fFloatAfterDefaultColor = 0.0f;
    m_uiIntegerParameter1 = 1;
    m_uiIntegerParameter2 = 1;
    m_fFirstValueAfterIntegerFields = 1.0f;
    m_fSecondValueAfterIntegerFields = 1.0f;
    UnsignedIntAndSixFloatData = 1.0f;
    SixFloatValueSet = 1.0f;
    FiveFloatData = 1.0f;
    FourFloatValueSet = 1.0f;
}

// @fnv 0x00505db0
void TESEffectShader::ResetFormData()
{
    ((::EffectShaderData *)(reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()))->Initialize();
}

// @fnv 0x00505dd0
void TESEffectShader::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    unsigned int formID = (unsigned int)(std::uintptr_t)(GetAddonModels());
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        reinterpret_cast<::MiddleHighProcess *>(this)->SetCurrentIdle((::TESIdleForm *)(::BGSDebris *)(dynamic_cast<BGSDebris*>(::FUN_004839c0(formID))));
    }
    SetInitializationState(true);
}

struct FUN_00507040Class
{
    bool FUN_00507040(unsigned int mask);
};
// @fnv 0x00507040
bool FUN_00507040Class::FUN_00507040(unsigned int mask)
{
    return *(unsigned char*)((::EffectShaderData *)(reinterpret_cast<::BGSCameraPath *>(this)->GetConditions())) & mask;
}

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_005050b0 : Base5a
{
    ~FUN_005050b0();
};
// @fnv 0x005050b0
FUN_005050b0::~FUN_005050b0()
{}

struct FUN_00506370Class
{
    void* GetFieldAt14C();
};
// @fnv 0x00506370
void* FUN_00506370Class::GetFieldAt14C()
{
    return reinterpret_cast<char*>(this) + 0x14c;
}

struct FUN_00506390Class
{
    char* GetFieldAt158();
};
// @fnv 0x00506390
char* FUN_00506390Class::GetFieldAt158()
{
    return reinterpret_cast<char*>(this) + 0x158;
}

struct FUN_005063b0Class
{
    void* GetFieldAt164();
};

// @fnv 0x005063b0
void* FUN_005063b0Class::GetFieldAt164()
{
    return reinterpret_cast<char*>(this) + 0x164;
}


struct FUN_00507810Class
{
    void FUN_00507810(std::intptr_t a, std::intptr_t b);
};

// @fnv 0x00507810
void FUN_00507810Class::FUN_00507810(std::intptr_t aiArg1, std::intptr_t aiArg2)
{
    ::FUN_00ba6290((::Fn6290Object *)(aiArg1), (::Fn6290Result *)(aiArg2));
}

struct FUN_00507b00Class
{
    float GetField4C();
};
// @fnv 0x00507b00
float FUN_00507b00Class::GetField4C()
{
    return *(float*)((char*)this + 0x4c);
}

struct FUN_00507b20Class
{
    float FUN_00507b20();
};

// @fnv 0x00507b20
float FUN_00507b20Class::FUN_00507b20()
{
    return *(float*)((char*)this + 0x118);
}

struct TESEffectShader;
struct FUN_00505cf0Class
{
    void FUN_00505d20();
    void* DestroyIfFlagged(unsigned int flags);
};
struct NiAVObject;
struct NiSourceTexture;
struct ParticleShaderProperty
{
};
struct FUN_00507060Class
{
};
struct FUN_005077c0Class
{
    ParticleShaderProperty* FUN_005077c0(NiAVObject* apRootObject, NiAVObject* apTargetObject, NiSourceTexture* apTex,
                                         float afTime);
};
extern int DAT_0102685c;

struct FUN_00505d20 : Base5a
{
    char pad[0x147];
    TESTexture m1;
    TESTexture m2;
    TESTexture m3;
    ~FUN_00505d20();
};
// Calls FUN_00505d20, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00505cf0
void* FUN_00505cf0Class::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00505d20 *>(this)->FUN_00505d20::~FUN_00505d20();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00505d20
FUN_00505d20::~FUN_00505d20()
{}

struct FUN_005e78f0_t
{
};
struct FUN_005062a0Class : ::TESEffectShader
{
    void CopyFrom(TESForm* apCopy);
};
// Copies a TESEffectShader's data, base component and three textures into this object after a dynamic_cast check.
// @fnv 0x005062a0
void FUN_005062a0Class::CopyFrom(TESForm* apCopy)
{
    TESEffectShader* pcopy = dynamic_cast<TESEffectShader*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pcopy);
    ::__memcpy(((::EffectShaderData *)(reinterpret_cast<::BGSCameraPath *>((((TESEffectShader*)this)))->GetConditions())), ((::EffectShaderData *)(reinterpret_cast<::BGSCameraPath *>((pcopy))->GetConditions())), 0x134);
    (&this->m_kFillTexture)
        ->CopyFromBase((BaseFormComponent*)((FUN_00506370Class*)pcopy)->GetFieldAt14C());
    (&this->m_kParticleShaderTexture)
        ->CopyFromBase((BaseFormComponent*)((FUN_00506390Class*)pcopy)->GetFieldAt158());
    (&this->m_kHolesTexture)
        ->CopyFromBase((BaseFormComponent*)((FUN_005063b0Class*)pcopy)->GetFieldAt164());
}

struct FUN_005e79a0_t
{
};

struct FUN_005063d0Shell : public TESEffectShader
{
    bool FUN_005063d0(TESForm* apCompare);
};
// Compares this effect shader with apCompare: returns true if apCompare is not a TESEffectShader or any component or the shader data differs.
// @fnv 0x005063d0
bool FUN_005063d0Shell::FUN_005063d0(TESForm* apCompare)
{
    TESEffectShader* pOtherShader = dynamic_cast<TESEffectShader*>(apCompare);
    if (!pOtherShader)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pOtherShader))
        return true;
    if (m_kFillTexture.CompareWithBase((BaseFormComponent*)((FUN_00506370Class*)pOtherShader)->GetFieldAt14C()))
        return true;
    if (m_kParticleShaderTexture.CompareWithBase(
            (BaseFormComponent*)((FUN_00506390Class*)pOtherShader)->GetFieldAt158()))
        return true;
    if (m_kHolesTexture.CompareWithBase((BaseFormComponent*)((FUN_005063b0Class*)pOtherShader)->GetFieldAt164()))
        return true;
    if (std::memcmp(&Data, ((::EffectShaderData *)(reinterpret_cast<::BGSCameraPath *>((pOtherShader))->GetConditions())), sizeof(EffectShaderData)))
        return true;
    return false;
}

struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct FUN_0048e370_obj
{
};

struct FUN_00485e00_shell
{
};

struct TESModel
{
    unsigned int GetModelLength();
};

struct FNStub
{
};

struct FUN_005060f0Class : ::TESEffectShader
{
    void FUN_005060f0();
};



struct FUN_005060f0Data
{
    char pad[0x10c];
    BGSDebris* mAddon;
};

struct BGSPerk;
struct BSSimpleListT
{
};
struct FUN_005064d0
{
    FUN_005064d0* Init();
};
// @fnv 0x005064d0
FUN_005064d0* FUN_005064d0::Init()
{
    (void *)(((BSSimpleListT*)((char*)this + 0x94)));
    (void *)(((BSSimpleListT*)((char*)this + 0xa0)));
    ((EffectShaderData*)this)->Initialize();
    return this;
}

struct FUN_005074e0_vec4
{
    float x;
    float y;
    float z;
    float w;
};

class FUN_005074e0_cls
{
  public:
    FUN_005074e0_vec4 m_v;
    FUN_005074e0_vec4* DivideByScalar(FUN_005074e0_vec4* out, float s);
};

// Copies m_v into a local vector, divides each of its four components by s, stores the result in out and returns out.
// @fnv 0x005074e0
FUN_005074e0_vec4* FUN_005074e0_cls::DivideByScalar(FUN_005074e0_vec4* out, float s)
{
    FUN_005074e0_vec4 vDivided = m_v;
    vDivided.x = vDivided.x / s;
    vDivided.y = vDivided.y / s;
    vDivided.z = vDivided.z / s;
    vDivided.w = vDivided.w / s;
    *out = vDivided;
    return out;
}

struct NiFixedStr
{
    operator const char*() const;
};

struct ShaderPropStub
{
};

struct NiPropStub
{
};

struct NiAVObject;

struct NiNodeStub
{
    unsigned int GetChildCount();
};

struct NiAVObject
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual NiNodeStub* IsSceneNode();
    virtual void V10();
    virtual void V14();
    virtual void* IsGeometry();
};


struct EffectShaderShell : public TESEffectShader
{
    void ApplyShaderToTree(NiAVObject* apObject, void* apData);
};

// @fnv 0x00507b40
void EffectShaderShell::ApplyShaderToTree(NiAVObject* apObject, void* apData)
{
    if (apObject)
    {
        if (apObject->IsGeometry())
        {
            NiPropStub* pProp = ((::NiPropStub *)(reinterpret_cast<::FUN_00a59d30_C *>((apObject))->FUN_00a59d30(3)));
            ShaderPropStub* pShader;
            if ((pShader = (!pProp ? 0 : (((int)(reinterpret_cast<::BGSTerrainManager *>((pProp))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((pProp))->GetMinLevel())) <= 12))
                               ? (ShaderPropStub*)pProp
                               : 0) != 0)
            {
                bool bApply = true;
                if (reinterpret_cast<::FUN_00507040Class *>(this)->FUN_00507040(0x20))
                {
                    NiPropStub* pNameProp = ((::NiPropStub *)(reinterpret_cast<::FUN_00a59d30_C *>((apObject))->FUN_00a59d30(2)));
                    if (!(const char*)(*(::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((pNameProp))->GetLinkToList())) || FUN_00408b20((*(::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((pNameProp))->GetLinkToList())), "skin"))
                    {
                        bApply = false;
                    }
                }
                if (bApply)
                {
                    reinterpret_cast<::fnv_00b675c0::FUN_00b675c0_shell *>((pShader))->AssignRefObj((::fnv_00b675c0::RefObj *)(apData));
                }
            }
        }
        else
        {
            NiNodeStub* pNode = apObject->IsSceneNode();
            if (pNode)
            {
                for (unsigned int i = 0; i < pNode->GetChildCount(); i++)
                {
                    ApplyShaderToTree(reinterpret_cast<::NiNode *>((pNode))->GetAt(i), apData);
                }
            }
        }
    }
}

struct S_00507c90_Ptr;
struct S_00507c90_List;
struct S_00507c90_Item
{
};
struct S_00507c90_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00507c90_List* v3();
    virtual void v4();
    virtual void v5();
    virtual S_00507c90_Item* v6();
};
struct S_00507c90_List
{
    int FUN_0043b480();
};
struct S_00507c90_Cls
{
    void ClearItemRef(S_00507c90_Obj* obj, S_00507c90_Ptr* ref);
};
// Recursively walks obj's list, and for items whose value is 8..12 clears the reference if it equals ref.
// @fnv 0x00507c90
void S_00507c90_Cls::ClearItemRef(S_00507c90_Obj* obj, S_00507c90_Ptr* ref)
{
    if (obj)
    {
        if (obj->v6())
        {
            S_00507c90_Item* t_ = ((::S_00507c90_Item *)(reinterpret_cast<::FUN_00a59d30_C *>((obj))->FUN_00a59d30(3)));
            S_00507c90_Item* s;
            if ((s = (!t_ ? 0 : (((int)(reinterpret_cast<::BGSTerrainManager *>((t_))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((t_))->GetMinLevel())) <= 12)) ? t_ : 0) != 0)
            {
                if (((::S_00507c90_Ptr *)(reinterpret_cast<::FUN_00507d80_Class *>((s))->FUN_00507d80())) == ref)
                    reinterpret_cast<::fnv_00b675c0::FUN_00b675c0_shell *>((s))->AssignRefObj((::fnv_00b675c0::RefObj *)(::S_00507c90_Ptr *)(0));
            }
        }
        else
        {
            S_00507c90_List* list = obj->v3();
            if (list)
            {
                for (unsigned int i2 = 0; i2 < (unsigned int)list->FUN_0043b480(); i2++)
                    ClearItemRef(((::S_00507c90_Obj *)(reinterpret_cast<::NiNode *>((list))->GetAt(i2))), ref);
            }
        }
    }
}

struct Color
{
    float r, g, b, a;
    Color(float, float, float, float);
    Color operator/(float);
};
struct Destination
{
    void SetData(NiPoint3);
    void FUN_005075c0(NiPoint3);
    void SetPoint(Color);
    void FUN_00507660(Color);
    void FUN_00507690(Color);
};
struct ShaderSettings : TESEffectShader
{
    void CopySettingsTo(Destination*, void*);
};
// @fnv 0x005077c0
ParticleShaderProperty* FUN_005077c0Class::FUN_005077c0(NiAVObject* apRootObject, NiAVObject* apTargetObject,
                                                        NiSourceTexture* apTex, float afTime)
{
    ParticleShaderProperty* pProp;
    if (apTex)
    {
        pProp = ((::ParticleShaderProperty *)(::FUN_00ba68d0(apRootObject, (::ArgObj *)(apTargetObject))));
        reinterpret_cast<::ShaderSettings *>((((FUN_00507060Class*)this)))->CopySettingsTo((::Destination *)(pProp), apTex);
        reinterpret_cast<::ParticleInitializer *>((pProp))->InitParticles(afTime);
        return pProp;
    }
    return 0;
}
// Copies the effect shader's Data fields into dest via its setters, converting three packed RGB values into normalized Colors with separate alpha values.
// @fnv 0x00507060
void ShaderSettings::CopySettingsTo(Destination* apDestination, void* apTexture)
{
    reinterpret_cast<::FUN_00507550_Class *>((apDestination))->FUN_00507550(apTexture);
    reinterpret_cast<::TESWorldSpace *>((apDestination))->FUN_00584150(Data.m_fShaderFloatParameter3);
    reinterpret_cast<::FUN_00507570_Class *>((apDestination))->FUN_00507570(Data.m_fShaderFloatParameter4);
    reinterpret_cast<::FUN_0051b8c0_shell *>((apDestination))->FUN_0051b8c0(Data.m_fShaderFloatParameter5);
    reinterpret_cast<::FUN_00810550_class *>((apDestination))->FUN_00810550(Data.m_fShaderFloatParameter6);
    reinterpret_cast<::TESObjectTREE *>((apDestination))->UpdateRustleSpeed(Data.m_fShaderFloatParameter17);
    apDestination->SetData(Data.VelocityState);
    apDestination->FUN_005075c0(Data.m_kVectorState2);
    reinterpret_cast<::FUN_005075f0_class *>((apDestination))->FUN_005075f0(Data.m_fShaderFloatParameter18);
    reinterpret_cast<::fnv_009314d0::FUN_009314d0_class *>((apDestination))->FUN_009314d0(Data.m_fShaderFloatParameter19);
    reinterpret_cast<::FUN_00507610_Class *>((apDestination))->FUN_00507610(Data.m_fShaderFloatParameter20);
    reinterpret_cast<::FUN_006e5ee0_Class *>((apDestination))->FUN_006e5ee0(Data.m_fShaderFloatParameter21);
    reinterpret_cast<::FUN_00507780 *>((apDestination))->SetBoltsRadiusStrength(Data.m_uiIntegerParameter1);
    reinterpret_cast<::FUN_005f9b10_class *>((apDestination))->SetBoltSmallWidth(Data.m_uiIntegerParameter2);
    reinterpret_cast<::FUN_005077a0_Class *>((apDestination))->FUN_005077a0(Data.m_fFloatAfterDefaultColor);
    Color color1 = Color((unsigned char)(Data.m_uiColorParameter1 & 255),
                         (unsigned char)(((unsigned short)Data.m_uiColorParameter1 >> 8) & 255),
                         (unsigned char)((Data.m_uiColorParameter1 >> 16) & 255), 0.0f) /
                   255.0f;
    Color color2 = Color((unsigned char)(Data.m_uiColorParameter2 & 255),
                         (unsigned char)(((unsigned short)Data.m_uiColorParameter2 >> 8) & 255),
                         (unsigned char)((Data.m_uiColorParameter2 >> 16) & 255), 0.0f) /
                   255.0f;
    Color color3 = Color((unsigned char)(Data.m_uiColorParameter3 & 255),
                         (unsigned char)(((unsigned short)Data.m_uiColorParameter3 >> 8) & 255),
                         (unsigned char)((Data.m_uiColorParameter3 >> 16) & 255), 0.0f) /
                   255.0f;
    color1.a = Data.m_fShaderFloatParameter11;
    color2.a = Data.m_fShaderFloatParameter12;
    color3.a = Data.m_fShaderFloatParameter13;
    apDestination->SetPoint(color1);
    apDestination->FUN_00507660(color2);
    apDestination->FUN_00507690(color3);
    reinterpret_cast<::FUN_006e4ef0_shell *>((apDestination))->FUN_006e4ef0(Data.m_fShaderFloatParameter14);
    reinterpret_cast<::FUN_006e4320_Class *>((apDestination))->FUN_006e4320(Data.m_fShaderFloatParameter15);
    reinterpret_cast<::FUN_005076c0Class *>((apDestination))->FUN_005076c0(Data.m_fShaderFloatParameter16);
    reinterpret_cast<::FUN_005076e0_Class *>((apDestination))->FUN_005076e0(Data.m_fShaderFloatParameter7);
    reinterpret_cast<::FUN_00733fd0_shell *>((apDestination))->FUN_00733fd0(Data.m_fShaderFloatParameter8);
    reinterpret_cast<::FUN_00507700_cls *>((apDestination))->FUN_00507700(Data.m_fShaderFloatParameter9);
    reinterpret_cast<::FUN_00507720_Class *>((apDestination))->FUN_00507720(Data.m_fShaderFloatParameter10);
    reinterpret_cast<::FUN_006d30e0_Class *>((apDestination))->FUN_006d30e0(Data.m_eAlphaSourceBlend);
    reinterpret_cast<::MiddleHighProcess *>((apDestination))->SetCurrentIdle((::TESIdleForm *)(Data.m_eAlphaDestinationBlend));
    reinterpret_cast<::FUN_00507740_Class *>((apDestination))->FUN_00507740(Data.m_eAlphaBlendOperation);
    reinterpret_cast<::FUN_00507760_Class *>((apDestination))->FUN_00507760(Data.m_eAlphaDepthCompareFunction);
}

struct ColorValue
{
    float x, y, z, w;
    ColorValue(float, float, float, float);
    ColorValue Normalize(float);
};
struct RefValue
{
    void* value;
    RefValue& operator=(void*);
};
struct EffectData
{
    int unk00, unk04;
    RefValue root;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    ColorValue fill, edge;
    float unk4c, unk50, scale, diameter;
    std::uintptr_t unk5c, unk60, unk64, unk68;
    RefValue target;
    unsigned int unk70;
    EffectData();
};
struct BoundValue
{
};
struct SceneValue
{
};
struct ShaderSource
{
    EffectData* CreateEffectData(SceneValue*, void*, void*);
};
// @fnv 0x00507830
EffectData* ShaderSource::CreateEffectData(SceneValue* scene, void* root, void* target)
{
    EffectData* data2 = new EffectData;
    std::uintptr_t fill = ((std::uintptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60()));
    std::uintptr_t edge = ((std::uintptr_t)(reinterpret_cast<::FUN_0068a830_shell *>(this)->GetGrass()));
    data2->root = 0;
    data2->fill =
        ColorValue((float)(unsigned char)(fill & 255), (float)(unsigned char)((unsigned short)fill >> 8 & 255),
                   (float)(unsigned char)(fill >> 16 & 255), 0.0f)
            .Normalize(255.0f);
    data2->edge =
        ColorValue((float)(unsigned char)(edge & 255), (float)(unsigned char)((unsigned short)edge >> 8 & 255),
                   (float)(unsigned char)(edge >> 16 & 255), 0.0f)
            .Normalize(255.0f);
    data2->unk4c = 0.0f;
    data2->unk50 = 0.0f;
    data2->scale = reinterpret_cast<::FUN_00507b00Class *>(this)->GetField4C();
    data2->diameter = reinterpret_cast<::Twin_0084d030 *>((((::BoundValue *)(reinterpret_cast<::FUN_0043d450_Owner *>((scene))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
    data2->unk5c = reinterpret_cast<::BGSTerrainManager *>(this)->GetMinLevel();
    data2->unk60 = ((std::uintptr_t)(reinterpret_cast<::FUN_004fd3a0_shell *>(this)->FUN_004fd3a0()));
    data2->unk64 = ((std::uintptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()));
    data2->unk68 = reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType();
    data2->root = root;
    data2->target = target;
    data2->unk70 = (unsigned int)reinterpret_cast<::FUN_00507b20Class *>(this)->FUN_00507b20();
    if (reinterpret_cast<::FUN_00507040Class *>(this)->FUN_00507040(16))
    {
        data2->edge.x += -1.0;
        data2->edge.y += -1.0;
        data2->edge.z += -1.0;
    }
    return data2;
}

struct Color4
{
    float x, y, z, w;
};
struct ShaderState
{
    int unk00, unk04, unk08;
    Color4 fill, edge, baseFill, baseEdge;
    float u, v;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned int alpha;
};
struct ShaderUpdate
{
    float UpdateFill(float, float, float, unsigned char);
    float UpdateEdge(float, float, float, unsigned char);
    void UpdateShaderState(ShaderState*, float, float, float, unsigned char);
};
// Advances a ShaderState's fill/edge alpha, UV offsets and alpha from delta, duration, time and mode.
// @fnv 0x00507e30
void ShaderUpdate::UpdateShaderState(ShaderState* state, float delta, float duration, float time, unsigned char mode)
{
    if (state)
    {
        state->baseFill.w = UpdateFill(state->baseFill.w, delta, duration, mode);
        state->fill = state->baseFill;
        state->fill.w = reinterpret_cast<::C508240Ref *>(this)->FUN_00508240(time) * state->fill.w + state->fill.w;
        state->fill.w = FUN_0040ebd0(1.0f, FUN_00404010(0.0f, state->fill.w));
        state->baseEdge.w = UpdateEdge(state->baseEdge.w, delta, duration, mode);
        state->edge = state->baseEdge;
        state->edge.w = reinterpret_cast<::B5081D0Actor *>(this)->FUN_005081d0(time) * state->edge.w + state->edge.w;
        state->edge.w = FUN_0040ebd0(1.0f, FUN_00404010(0.0f, state->edge.w));
        state->u = reinterpret_cast<::FUN_00508050_Class *>(this)->FUN_00508050() * delta + state->u;
        state->v = reinterpret_cast<::FUN_00639aa0_shell *>(this)->FUN_00639aa0() * delta + state->v;
        float boundedTime = FUN_0040ebd0(reinterpret_cast<::FUN_004e3d00_shell *>(this)->FUN_004e3d00(), FUN_00404010(reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070(), time));
        state->alpha = (unsigned int)LinearInterpolate(reinterpret_cast<::FUN_00507b20Class *>(this)->FUN_00507b20(), reinterpret_cast<::FUN_004a0d90_Class *>(this)->GetField11C(), reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070(), reinterpret_cast<::FUN_004e3d00_shell *>(this)->FUN_004e3d00(), boundedTime);
    }
}

struct SwapFlag
{
    bool value;
};
struct EffectShaderDataEndian : EffectShaderData
{
    void FUN_00506850();
};
// @fnv 0x00505e70
bool TESEffectShader::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x4f)
        return false;
    ClearData();
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int iChunkID;
    while (iChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (iChunkID)
        {
        case 0x44494445: {
            char* pChunkBuffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pChunkBuffer), 0x200);
            SetEditorID_AtRuntime(pChunkBuffer);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(&m_kFillTexture, file);
            break;
        case 0x324f4349:
            ::TESTexture::ReadTextureData(&m_kParticleShaderTexture, file);
            break;
        case 0x374d414e:
            ::TESTexture::ReadTextureData(&m_kHolesTexture, file);
            break;
        case 0x41544144:
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::EffectShaderDataEndian *>(&(Data))->FUN_00506850();
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &Data, sizeof(Data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::EffectShaderDataEndian *>(&(Data))->FUN_00506850();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (Data.m_fShaderFloatParameter1 <= 1.0 && Data.m_fShaderFloatParameter1 > 0.0)
        Data.m_fShaderFloatParameter1 *= ParticleShader::GetShaderParticleCount();
    if (Data.m_fShaderFloatParameter2 <= 1.0 && Data.m_fShaderFloatParameter2 > 0.0)
        Data.m_fShaderFloatParameter2 *= ParticleShader::GetShaderParticleCount();
    return true;
}
// @fnv 0x005060f0
void FUN_005060f0Class::FUN_005060f0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();

    if (reinterpret_cast<TESModel*>(&this->m_kFillTexture)->GetModelLength() == 0)
    {
        ::FUN_004856f0((void *)(0x4e4f4349), ((char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(&this->m_kFillTexture)))->FUN_00408da0())),
                     (void *)(reinterpret_cast<TESModel*>(&this->m_kFillTexture)->GetModelLength() + 1));
    }
    else
    {
        reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_obj*>(&this->m_kFillTexture)))->FUN_0048e370(0x4e4f4349);
    }

    if (reinterpret_cast<TESModel*>(&this->m_kParticleShaderTexture)->GetModelLength() == 0)
    {
        ::FUN_004856f0((void *)(0x324f4349), ((char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(&this->m_kParticleShaderTexture)))->FUN_00408da0())),
                     (void *)(reinterpret_cast<TESModel*>(&this->m_kParticleShaderTexture)->GetModelLength() + 1));
    }
    else
    {
        reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_obj*>(&this->m_kParticleShaderTexture)))->FUN_0048e370(0x324f4349);
    }

    if (reinterpret_cast<TESModel*>(&this->m_kHolesTexture)->GetModelLength() == 0)
    {
        ::FUN_004856f0((void *)(0x374d414e), ((char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(&this->m_kHolesTexture)))->FUN_00408da0())),
                     (void *)(reinterpret_cast<TESModel*>(&this->m_kHolesTexture)->GetModelLength() + 1));
    }
    else
    {
        reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_obj*>(&this->m_kHolesTexture)))->FUN_0048e370(0x374d414e);
    }

    BGSDebris* psaveAddon = reinterpret_cast<FUN_005060f0Data*>(this)->mAddon;

    reinterpret_cast<FUN_005060f0Data*>(this)->mAddon =
        reinterpret_cast<FUN_005060f0Data*>(this)->mAddon
            ? reinterpret_cast<BGSDebris*>(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<FUN_005060f0Data*>(this)->mAddon))->FUN_0084e3a0())))
            : 0;

    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::EffectShaderDataEndian *>((&this->Data))->FUN_00506850();
    }

    reinterpret_cast<::SDSaveForm *>((reinterpret_cast<FUN_00485e00_shell*>(this)))->FUN_00485e20(reinterpret_cast<char*>(&this->Data), 0x134);

    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::EffectShaderDataEndian *>((&this->Data))->FUN_00506850();
    }

    reinterpret_cast<FUN_005060f0Data*>(this)->mAddon = psaveAddon;

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}
// @fnv 0x00506850
void EffectShaderDataEndian::FUN_00506850()
{
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_eDestinationBlend));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_eBlendOperation));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_eDepthCompareFunction));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&BlendDepthState));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&BlendDepthParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&DepthCompareParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&IndexedFloatParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&ShaderFloatParameterSet));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&ShaderParameterFormatSet));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&SevenFloatParameterRecord));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&SixFloatAndUnsignedIntegerRecord));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&SixFloatUnsignedIntegerAndFloatRecord));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&ExtendedFloatFlagParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&ShaderFloatParameterBlock));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&SixFloatRecordWithMiddleFlag));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&FloatFlagParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&SixFloatRecordWithLeadingFlag));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&BlendFloatParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&AlphaBlendParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&BlendStateParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&BlendFactorState));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&BlendModeConfiguration));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_eSourceBlend));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_eAlphaSourceBlend));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_eAlphaBlendOperation));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_eAlphaDepthCompareFunction));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_eAlphaDestinationBlend));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&AlphaBlendSettings));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fAlphaBlendParameter));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&BlendFactorParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter1));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter2));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter3));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter4));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter5));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter6));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&VelocityState.x));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&VelocityState.y));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&VelocityState.z));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_kVectorState2.x));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_kVectorState2.y));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_kVectorState2.z));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter7));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter8));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter9));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter10));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_uiColorParameter1));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_uiColorParameter2));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_uiColorParameter3));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter11));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter12));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter13));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter14));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter15));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter16));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter17));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter18));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter19));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter20));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fShaderFloatParameter21));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&DebrisModelSettings));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&EffectShaderAddonData));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&DebrisColorSettings));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&EffectShaderColorData));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&EffectShaderParameters));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_uiBaseColor));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fFloatAfterDefaultColor));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_uiIntegerParameter1));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_uiIntegerParameter2));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fFirstValueAfterIntegerFields));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&m_fSecondValueAfterIntegerFields));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&UnsignedIntAndSixFloatData));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&SixFloatValueSet));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&FiveFloatData));
    }
    {
        SwapFlag needsEndianSwap = {};
        ::FUN_00401080((int *)(void *)(&FourFloatValueSet));
    }
}
