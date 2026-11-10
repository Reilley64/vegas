// bsshader/bsfadenode.cpp: BSFadeNode, NiFixedString, BSShaderManager, FadeViewer and more (22 functions)

#include <cstdint>
#include "fnv/game_timer.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00a5dbe0_shell.h"
#include "fnv/decl/FUN_00a5ea70_t.h"
#include "fnv/decl/FUN_00b4e1e0.h"
#include "fnv/decl/FUN_00b63090_shell.h"
#include "fnv/decl/FUN_00b63500_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiNodeEq.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiRenderer.h"
#include "fnv/decl/NodeA5E8.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a5dd40__FUN_00a5dd40_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00a5e000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b4d000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_01202000.h"
#include "bsfadenode_decls.h"

// @fnv 0x00b4e270
void BSFadeNode::InitializeMultiBounds()
{
    ms_pAlphaProperty = new NiAlphaProperty;
    ms_pAlphaProperty->m_uiObjectFlags |= 1;
    ms_pFadeNodeAnimationName = new NiFixedString("FadeNode Anim");
}

// Allocates and returns a new BSFadeNode instance.
// @fnv 0x00b4eaa0
NiObject* BSFadeNode::CreateObject()
{
    return new BSFadeNode;
}

// Clamps nearDistance to the INI setting's integer value and raises farDistance to twice that minimum, then stores both into fNearDistSqr and fFarDistSqr.
// @fnv 0x00b4dfd0
void BSFadeNode::SetRange(float nearDistance, float farDistance)
{
    float minDistance =
        (float)static_cast<const volatile SettingT<INISettingCollection>&>((*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011f9148))).uValue.i;
    if (nearDistance < minDistance)
    {
        nearDistance = minDistance;
        if (farDistance < minDistance * 2.0f)
            farDistance = minDistance * 2.0f;
    }
    fNearDistSqr = nearDistance;
    fFarDistSqr = farDistance;
}

// @fnv 0x00b4f530
BSRenderedTexture* BSShaderManager::GetSceneDepthRenderedTexture()
{
    return ::DAT_011f91ac->GetDepthRenderedTexture();
}

struct BSTreeModel;
struct CSpeedTreeRT;
struct NiBinaryStream;
struct NiCullingProcess;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiTexturingProperty;
struct NiThread;
struct NiTriBasedGeom;
struct NiUpdateData;
struct bhkSimpleShapePhantom;
struct BSTreeNode : public BSFadeNode
{
    virtual void __vslot_0();
    virtual BSTreeModel* GetModelFilePath();
    virtual NiNode* GetBranchesNode();
    virtual NiNode* GetFrondNode();
    virtual NiNode* GetLeavesNode();
    virtual NiTriBasedGeom* GetBranchMesh(unsigned short);
    virtual NiTriBasedGeom* GetFrondMesh(unsigned short);
    virtual NiTriBasedGeom* GetLeafMesh();
    virtual bool SetBranchGeometry(unsigned short, NiTriBasedGeom*);
    virtual bool SetFrondGeometry(unsigned short, NiTriBasedGeom*);
    virtual void SetBillboardObject(NiTriBasedGeom*);
    virtual bool SetBranchVisible(bool);
    virtual bool SetFrondVisible(bool);
    virtual bool SetLeavesVisible(bool);
    virtual bool SetBranchTextureVariant(unsigned short, unsigned char);
    virtual bool SetFrondTextureVariant(unsigned short, unsigned char);
    virtual bool SetLeafTextureVariant(unsigned char);
    virtual bool SetTexturingProperty(NiTexturingProperty*);
    virtual void SetWindAmplitude(float);
    virtual void* GetRTTI();
    virtual void GetViewerStrings(void*);
    virtual void OnVisible(NiCullingProcess*);
    virtual void UpdateDownwardPass(NiUpdateData*, unsigned int);
    virtual void UpdateSelectedDownwardPass(NiUpdateData*, unsigned int);
    void UpdateSpeedTree(CSpeedTreeRT*, float);
    bhkSimpleShapePhantom* GetLeafObject();
    bool CheckForCollision(float);
    char _pad_e4[44];
    char m_pRenderedNodeEntry[4];
    void* m_pSpeedTreeData;
    void* m_pTreeModelData;
    char m_ucTreeFlags[4];
    float m_fTreeWindTime;
    char _pad_124[12];
};
struct FUN_00b4def0_shell : public BSFadeNode
{
    bool FUN_00b4def0(NiStream*);
};

struct FUN_00a5e5b0_helper
{
};

// @fnv 0x00b4def0
bool FUN_00b4def0_shell::FUN_00b4def0(NiStream* arStream)
{
    if (!((unsigned char)(::fnv_00a5e5b0::RegisterChildStreamables((::NiNode *)(((FUN_00a5e5b0_helper*)this)), (std::intptr_t)(arStream), *(::fnv_00a5e5b0::NiStream *)nullptr))))
        return false;
    return true;
}

struct Dummy
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual char* v4();
};

// @fnv 0x00b4dfb0
void __cdecl SetFlagOnVirtualResult(Dummy* apDummy)
{
    if (apDummy)
    {
        NiAVObject* r = reinterpret_cast<NiAVObject*>(apDummy->v4());
        if (r)
        {
            r->m_uiFlags |= 0x20000;
        }
    }
}

class P03MM
{
  public:
};

// Recursively frees the nodes linked after this list node, deallocating each one, then clears its item.
// @fnv 0x00b4df30
void FUN_00b4df30(void* p)
{
    BSSimpleList<void*>* self = (BSSimpleList<void*>*)p;
    if (self->m_pkNext)
    {
        BSSimpleList<void*>* next;
        do
        {
            BSSimpleList<void*>* node = self->m_pkNext;
            next = node->m_pkNext;
            node->m_pkNext = 0;
            BSSimpleList<void*>* pCurrent = self->m_pkNext;
            if (pCurrent)
            {
                FUN_00b4df30(pCurrent);
                reinterpret_cast<::FNV_MemoryManager *>((((P03MM*)&::g_memoryManager)))->FUN_00aa4060(pCurrent);
            }
            self->m_pkNext = next;
        } while (next);
    }
    self->m_item = 0;
}

double(__cdecl* DAT_011f9134)(void*);

// Returns the result of calling the DAT_011f9134 function pointer on param_1, or 1.0f if the pointer is null.
// @fnv 0x00b4df80
float FUN_00b4df80(void* param_1)
{
    float f;
    if (DAT_011f9134)
        f = DAT_011f9134(param_1);
    else
        f = 1.0f;
    return f;
}

struct FUN_00b4dec0_shell : public BSFadeNode
{
    void FUN_00b4dec0(int);
};

// @fnv 0x00b4dec0
void FUN_00b4dec0_shell::FUN_00b4dec0(int aeMultType)
{
    this->eMultType = aeMultType;
}

struct NiNode_Helper : public NiNode
{
};

// @fnv 0x00b4e3f0
void* FUN_00b4e3f0(void* apSource, int dummy, void* kCloning)
{
    BSFadeNode* pSource = (BSFadeNode*)apSource;
    BSFadeNode* pFadeNode = new BSFadeNode();
    reinterpret_cast<::NiNode *>((((NiNode_Helper*)apSource)))->CopyMemberData((NiNode*)pFadeNode, (*(::CloningProcess *)(kCloning)));
    pFadeNode->m_uiFlags &= 0xfffd3fff;
    pFadeNode->fNearDistSqr = pSource->fNearDistSqr;
    pFadeNode->fFarDistSqr = pSource->fFarDistSqr;
    pFadeNode->eMultType = pSource->eMultType;
    return pFadeNode;
}

struct FUN_00b4ed40_t
{
    FUN_00b4ed40_t* FUN_00b4ed40(unsigned char flags);
};
// Calls FUN_00b4e1e0, then if bit 0 of flags is set calls __Dummy_00b6fef0 on this with size 0xe4, and returns this.
// @fnv 0x00b4ed40
FUN_00b4ed40_t* FUN_00b4ed40_t::FUN_00b4ed40(unsigned char flags)
{
    reinterpret_cast<::FUN_00b4e1e0 *>(this)->FUN_00b4e1e0::~FUN_00b4e1e0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xe4);
    return this;
}


struct MM_Dealloc_b4e380
{
};

// @fnv 0x00b4e380
void __cdecl ReleaseFadeNodeResources()
{
    if (BSFadeNode::ms_pAlphaProperty.m_pObject)
    {
        BSFadeNode::ms_pAlphaProperty.m_pObject->DecRefCount();
        BSFadeNode::ms_pAlphaProperty.m_pObject = 0;
    }
    NiFixedString* animName = BSFadeNode::ms_pFadeNodeAnimationName;
    if (BSFadeNode::ms_pFadeNodeAnimationName)
    {
        char* handle = BSFadeNode::ms_pFadeNodeAnimationName->m_kHandle;
        if (handle != DAT_0109b220)
        {
            // the interned string block keeps its long refcount 8 bytes before the handle
            InterlockedDecrement((long*)handle - 2);
        }
        reinterpret_cast<::FNV_MemoryManager *>((((MM_Dealloc_b4e380*)&::g_memoryManager)))->FUN_00aa4060(animName);
    }
    BSFadeNode::ms_pFadeNodeAnimationName = 0;
}



struct FUN_00b4ea20_child
{
    unsigned char unk00[0xc];
};

struct FUN_00b4ea20_mid
{
    unsigned char unk00[0xc];
    FUN_00b4ea20_child* m_pChildObject;
};

struct FUN_00b4ea20_holder
{
    FUN_00b4ea20_mid* m_pMid;
};

class FUN_00b4ea20_cls
{
  public:
    unsigned char unk00[0xa0];
    FUN_00b4ea20_holder* m_pHolder;
    unsigned char unkA4[2];
    unsigned short m_uA6;
    unsigned char unkA8[0x18];
    float m_fC0;
    void FUN_00b4ea20(float* p, int v);
};

// @fnv 0x00b4ea20
void FUN_00b4ea20_cls::FUN_00b4ea20(float* apValue, int aiValue)
{
    if (DAT_011ad7b4 == 0)
    {
        m_fC0 = *apValue;
        if (*apValue > 0.0f)
        {
            bool notSet = (::FUN_00c80090((struct ::ProbeObj *)(void *)(this)) == false);
            if (notSet)
            {
                if (m_uA6 > 0 && notSet)
                {
                    FUN_00b4ea20_mid* pMid = m_pHolder->m_pMid;
                    if (pMid != 0)
                    {
                        FUN_00b4ea20_child* pChild = pMid->m_pChildObject;
                        if (pChild != 0)
                        {
                            reinterpret_cast<::NiObject *>((pChild))->DynamicCast((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f36ac))));
                        }
                    }
                }
            }
        }
    }
    reinterpret_cast<::NiNode *>(this)->UpdateSelectedDownwardPass((*(::NiUpdateData *)(apValue)), aiValue);
}

struct Strings
{
    void* vtable;
    char** data;
    unsigned short capacity, size, count, grow;
    void Add(char*& text)
    {
        unsigned int index = size;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + grow);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, text);
    }
};
struct Extra
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
    virtual void Viewer(Strings*);
};
struct ViewerBool
{
    bool value;
};
struct Allocator
{
};
struct FadeViewer
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    float nearDist, farDist, lastFade, currentFade, boundRadius, timeSinceUpdate;
    int multType, frameCounter;
    void FUN_00b4ed70(Strings* strings);
};
// Appends formatted fade-viewer fields and bit flags from field30 to the strings list, then forwards to an Extra viewer if found.
// @fnv 0x00b4ed70
void FadeViewer::FUN_00b4ed70(Strings* strings)
{
    reinterpret_cast<::FUN_00a5ea70_t *>(this)->FUN_00a5ea70((::StrArr *)(strings));
    {
        char* text = FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f9140)));
        strings->Add(text);
        float fNearDist = nearDist;
        float fFarDist = farDist;
        text = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::Allocator *>(&::g_memoryManager))))->FUN_00aa3e40(64);
        if (fNearDist == 3.4028234663852886e38)
            ::FUN_00406d00(text, 64, "fNearDistSqr = DISABLED");
        else
            ::FUN_00406d00(text, 64, "fNearDistSqr = %.2f", fNearDist);
        strings->Add(text);
        text = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::Allocator *>(&::g_memoryManager))))->FUN_00aa3e40(64);
        if (fFarDist == 3.4028234663852886e38)
            ::FUN_00406d00(text, 64, "fFarDistSqr = DISABLED");
        else
            ::FUN_00406d00(text, 64, "fFarDistSqr = %.2f", fFarDist);
        strings->Add(text);
        text = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::Allocator *>(&::g_memoryManager))))->FUN_00aa3e40(64);
        ::FUN_00406d00(text, 64, "eMultType = %d", multType);
        strings->Add(text);
        text = FUN_00a7d550("fLastFade", lastFade);
        strings->Add(text);
        text = FUN_00a7d550("fCurrentFade", currentFade);
        strings->Add(text);
        text = FUN_00a7d550("fTimeSinceUpdate", timeSinceUpdate);
        strings->Add(text);
        text = FUN_00a7d4d0("iFrameCounter", frameCounter);
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 14) & 1;
        char* text = ::FUN_00a7d370("bFadedIn", (*(bool *)&(const ::ViewerBool &)(flag)));
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 15) & 1;
        char* text = ::FUN_00a7d370("bIgnoreFade", (*(bool *)&(const ::ViewerBool &)(flag)));
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 16) & 1;
        char* text = ::FUN_00a7d370("bLODFadingOut", (*(bool *)&(const ::ViewerBool &)(flag)));
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 17) & 1;
        char* text = ::FUN_00a7d370("bHasMovingSound", (*(bool *)&(const ::ViewerBool &)(flag)));
        strings->Add(text);
    }
    {
        ViewerBool flag;
        flag.value = (field30 >> 24) & 1;
        char* text = ::FUN_00a7d370("bHighDetail", (*(bool *)&(const ::ViewerBool &)(flag)));
        strings->Add(text);
    }
    Extra* extra = ((::Extra *)(reinterpret_cast<::NiAVObject *>(this)->GetExtraData((*(const ::NiFixedString *)((*reinterpret_cast<void * *>(&::DAT_01202ddc)))))));
    if (extra)
        extra->Viewer(strings);
}


// @fnv 0x00b4ded0
void FUN_00b4ded0()
{
    static_cast<::NiNode *>(nullptr)->UpdateDownwardPass(*(::NiUpdateData *)nullptr, {});
}

// @fnv 0x00b4dee0
void FUN_00b4dee0()
{
    static_cast<::fnv_00a5dd40::FUN_00a5dd40_shell *>(nullptr)->FUN_00a5dd40({});
}

struct Cls00b4df20
{
    bool FUN_00b4df20(Cls00b4df20* other);
};

// @fnv 0x00b4df20
bool Cls00b4df20::FUN_00b4df20(Cls00b4df20* other)
{
    return reinterpret_cast<::NiNodeEq *>(this)->FUN_00a5e600((::NiAVObject *)(other));
}

struct Vec
{
    float x, y, z;
};
struct Bound
{
    int unk00, unk04, unk08;
    float unk0c;
};
struct Fade
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Bound* unk20;
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
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    float unk8c;
    float unk90;
    float unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    float unkac;
    float unkb0;
    float unkb4;
    float unkb8;
    float unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    float unk110;
    bool UpdateFade(Fade* camera, int unused);
};
// @fnv 0x00b4eb10
bool Fade::UpdateFade(Fade* camera, int unused)
{
    float alpha = 1.0f;
    if (DAT_011ad7b4)
    {
        float scale = camera->unk110;
        Vec vDelta;
        vDelta.x = unk8c - camera->unk8c;
        vDelta.y = unk90 - camera->unk90;
        vDelta.z = unk94 - camera->unk94;
        float mult = 1.0f;
        if (unkc4 > 0 && unkc4 < 11)
            mult = DAT_011ad7b8[unkc4];
        if (unkc4 == 6)
        {
            unk30 &= ~0x4000;
            unkb4 = unkb8 = 0.0f;
        }
        else
        {
            if (unkc4 == 10)
                return true;
            if (unkb0 > 2600.0f)
            {
                unkb0 = 2600.0f;
                unkac = 1300.0f;
                if (unkc8 < DAT_011f9138 - 20)
                {
                    unk30 &= ~0x4000;
                    unkb4 = unkb8 = 0.0f;
                }
            }
        }
        if (unk20)
            unkbc = unk20->unk0c;
        if (unkc4 == 1 || unkc4 == 5 || unkc4 == 4 || unkc4 == 6)
        {
            unkc8 = DAT_011f9138;
            return false;
        }
        if (mult > 0.0f)
        {
            scale /= mult;
            float dist = reinterpret_cast<::NiPoint3 *>(&(vDelta))->ComputeMagnitude();
            if (dist < 0.0f)
                dist = 0.0f;
            dist *= scale;
            float nearDist = unkac * DAT_011ad7f4;
            float farDist = unkb0 * DAT_011ad7f4;
            if (dist > farDist)
                return false;
            if (dist > nearDist)
            {
                float range = farDist - nearDist;
                float fade = 1.0f - (dist - nearDist) / range;
                if (fade < DAT_011ad7f0)
                    return false;
            }
        }
        else if (mult == 0.0f)
        {
            unk30 |= 0x4000;
            unkb4 = unkb8 = 1.0f;
            ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::Fade *)(this), 1.0f);
            return true;
        }
    }
    unk30 |= 0x4000;
    unkb4 = unkb8 = alpha;
    ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::Fade *)(this), alpha);
    return true;
}

#include <math.h>
struct NiCamera : NiAVObject
{
    unsigned char cameraData[0x110 - 0x9c];
    float m_fLODAdjust;
};
struct CloningProcess;
struct NiPoint2;
struct NiPoint3;
struct NiStream;
struct NiUpdateData;
struct blob12
{
    char b[12];
};
struct FUN_00b4e030_shell : public BSFadeNode
{
    bool IsWithinFadeDistance(NiCamera*, float);
};


struct Pt3
{
    float x, y, z;
    Pt3(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
    {}
    float Dot(const Pt3& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};

// Checks whether the camera is within the node's fade distance, adjusted by a per-state factor, and returns true if the scaled distance is below the fade limit.
// @fnv 0x00b4e030
bool FUN_00b4e030_shell::IsWithinFadeDistance(NiCamera* apCamera, float afDistMult)
{
    float ffadeAdjust = apCamera->m_fLODAdjust;
    if (this->eMultType == 9)
        return false;
    if (this->eMultType >= 0 && this->eMultType < 11)
    {
        float fdiff = DAT_011ad7b8[this->eMultType];
        if (fdiff != 0.0f)
            ffadeAdjust = ffadeAdjust / fdiff;
    }
    const float* kA = m_afWorldTranslate;
    const float* kB = apCamera->m_afWorldTranslate;
    Pt3 kDiff(kA[0] - kB[0], kA[1] - kB[1], kA[2] - kB[2]);
    float fDist = sqrtf(reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kDiff))->DotProduct((void *)&(kDiff))) * afDistMult;
    if (fDist < 0.0f)
        fDist = 0.0f;
    float fadeMult = fDist * ffadeAdjust;
    if (fadeMult > this->fFarDistSqr * DAT_011ad7f4)
        return false;
    return true;
}

namespace fnv_00b4e490 {
struct FadePt3
{
    float x, y, z;
    FadePt3()
    {}
    FadePt3(float ax, float ay, float az) : x(ax), y(ay), z(az)
    {}
    FadePt3 operator-(const FadePt3& o) const
    {
        return FadePt3(x - o.x, y - o.y, z - o.z);
    }
    float Length() const
    {
        return sqrtf(x * x + y * y + z * z);
    }
};

struct FadeCamera
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    FadePt3 m_kWorldTranslate;  // 0x8c
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    float m_fTrailingValue;  // 0x110
};

struct FadeCuller
{
    int unk00;
    int unk04;
    int unk08;
    FadeCamera* m_pCamera;  // 0x0c
};

struct FadeQueue
{
};

struct FadeQueueHolder
{
    int unk00;
    int unk04;
    FadeQueue* m_pQueue;
};

extern float DAT_011ad7f8;


struct FadeNodeObj;

struct FadeNodeObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    const char* m_pcName;  // 0x20
    int unk24;
    int unk28;
    int unk2C;
    unsigned int m_uiValue1;  // 0x30
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
    FadePt3 m_kWorldTranslate;  // 0x8c
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    float fNearDistSqr;      // 0xac
    float fFarDistSqr;       // 0xb0
    float fLastFade;         // 0xb4
    float fCurrentFade;      // 0xb8
    float m_fFadeDelta;      // 0xbc
    float fTimeSinceUpdate;  // 0xc0
    int eMultType;           // 0xc4
    int iFrameCounter;       // 0xc8

    bool IsCulledFlag() const
    {
        return (m_uiValue1 >> 15) & 1;
    }
    bool IsFadedIn() const
    {
        return (m_uiValue1 >> 14) & 1;
    }
    bool IsAlwaysFade() const
    {
        return (m_uiValue1 >> 28) & 1;
    }
    void FUN_00b4e490(FadeCuller& culler);
};

// Updates the fade state of a FadeNodeObj based on camera distance and fade thresholds, queueing a batch render when the fade target is in progress.
// @fnv 0x00b4e490
void FadeNodeObj::FUN_00b4e490(FadeCuller& culler)
{
    if (!(*reinterpret_cast<char *>(&::DAT_011ad7b4)) || IsCulledFlag())
    {
        reinterpret_cast<::FUN_00a5dbe0_shell *>(this)->FUN_00a5dbe0((::NiCullingProcess *)&(culler));
        return;
    }
    float fFadeAmount;
    if (eMultType == 6)
    {
        if (!IsFadedIn())
        {
            fFadeAmount = ::FUN_0040ebd0(1.0f, ::FUN_0040ebd0(::fnv::timer::Seconds() / ::DAT_011ad7e4, DAT_011ad7f8) + fCurrentFade);
            fCurrentFade = fFadeAmount;
            ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::fnv_00b4e490::FadeNodeObj *)(this), fFadeAmount);
            fLastFade = fCurrentFade;
            if (fCurrentFade >= 1.0f)
                m_uiValue1 |= 0x4000;
        }
        reinterpret_cast<::FUN_00a5dbe0_shell *>(this)->FUN_00a5dbe0((::NiCullingProcess *)&(culler));
        return;
    }

    float fMult = (*reinterpret_cast<float (*)[11]>(&::DAT_011ad7b8))[eMultType];
    FadeCamera* pCamera = culler.m_pCamera;
    float fDist;
    FadePt3 kDiff;
    if (fMult > 0.0f)
    {
        fDist = pCamera->m_fTrailingValue / fMult;
    }
    else
    {
        fDist = 0.2f;
        m_uiValue1 |= 0x4000;
        fLastFade = fCurrentFade = 1.0f;
        ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::fnv_00b4e490::FadeNodeObj *)(this), *(volatile float*)&fCurrentFade);
    }

    kDiff = m_kWorldTranslate - pCamera->m_kWorldTranslate;
    fDist = kDiff.Length() * fDist;
    fFadeAmount = 1.0f;
    float fNear = fNearDistSqr * ::DAT_011ad7f4;
    if (fDist > fNear)
    {
        float fFar = fFarDistSqr * ::DAT_011ad7f4;
        fFadeAmount = 1.0f - (fDist - fNear) / (fFar - fNear);
    }
    if (eMultType == 10)
    {
        if (IsAlwaysFade())
            fFadeAmount = 1.0f;
        else
            fFadeAmount = 0.0f;
    }

    if (eMultType != 8 && iFrameCounter < ::DAT_011f9138 - 20 && m_fFadeDelta < 600.0f)
    {
        if (fFadeAmount > ::DAT_011ad7ec || (IsFadedIn() && fFadeAmount > ::DAT_011ad7f0))
        {
            ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::fnv_00b4e490::FadeNodeObj *)(this), 1.0f);
            fLastFade = fCurrentFade = 1.0f;
            m_uiValue1 |= 0x4000;
        }
        else
        {
            ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::fnv_00b4e490::FadeNodeObj *)(this), 0.0f);
            fLastFade = fCurrentFade = 0.0f;
            m_uiValue1 &= ~0x4000;
        }
    }
    iFrameCounter = ::DAT_011f9138;

    float fTarget = ::FUN_00b4df80((void *)this);
    bool bFadeQueuedCur = false;
    if (IsFadedIn() && fTarget > 0.0f && fTarget < 1.0f)
    {
        FadeQueue* m_pPrimaryTaskProcessor = (*reinterpret_cast<::fnv_00b4e490::FadeQueueHolder * *>(&::NiRenderer::ms_pRenderer))->m_pQueue;
        if (::FUN_0043b300((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011fa000))), (::NiAVObject *)(m_pPrimaryTaskProcessor)))
        {
            reinterpret_cast<::FUN_00b63500_shell *>((m_pPrimaryTaskProcessor))->RenderBound((void *)(m_pcName ? m_pcName : (*reinterpret_cast<char (*)[]>(&::g_defaultBound))), 1);
            bFadeQueuedCur = true;
            ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::fnv_00b4e490::FadeNodeObj *)(this), fTarget);
            fLastFade = fCurrentFade = fTarget;
        }
    }
    else if ((!IsFadedIn() && fFadeAmount > ::DAT_011ad7ec) ||
             (fCurrentFade > 0.0f && fCurrentFade < 1.0f && fFadeAmount > ::DAT_011ad7ec))
    {
        fFadeAmount = ::FUN_0040ebd0(1.0f, ::FUN_0040ebd0(::fnv::timer::Seconds() / ::DAT_011ad7e4, DAT_011ad7f8) + fCurrentFade);
        fCurrentFade = fFadeAmount;
        ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::fnv_00b4e490::FadeNodeObj *)(this), fFadeAmount);
        fLastFade = fCurrentFade;
        if (fCurrentFade >= 1.0f)
            m_uiValue1 |= 0x4000;
    }
    else if ((IsFadedIn() && fFadeAmount < ::DAT_011ad7f0) ||
             (fCurrentFade < 1.0f && fCurrentFade > 0.0f && fFadeAmount < ::DAT_011ad7f0))
    {
        fCurrentFade = ::FUN_00404010(0.0f, fCurrentFade - ::FUN_0040ebd0(::fnv::timer::Seconds() / ::DAT_011ad7e8, DAT_011ad7f8));
        ::BSShaderRenderUtility::SetAlphaOnNode((::NiNode *)(::fnv_00b4e490::FadeNodeObj *)(this), fCurrentFade);
        fLastFade = fCurrentFade;
        if (fCurrentFade <= 0.0f)
            m_uiValue1 &= ~0x4000;
    }

    if (fCurrentFade > 0.0f && fTarget != 0.0f)
        reinterpret_cast<::FUN_00a5dbe0_shell *>(this)->FUN_00a5dbe0((::NiCullingProcess *)&(culler));
    if (bFadeQueuedCur)
        reinterpret_cast<::FUN_00b63090_shell *>(((*reinterpret_cast<::fnv_00b4e490::FadeQueueHolder * *>(&::NiRenderer::ms_pRenderer))->m_pQueue))->DispatchBatchRenderer();
}
}  // namespace fnv_00b4e490

// @fnv 0x00b4df10
void __cdecl FUN_00b4df10()
{
    static_cast<::NodeA5E8 *>(nullptr)->FUN_00a5e880(*(::NiStreamA5E8 *)nullptr);
}

#include "generated/data/bsshader/bsfadenode.inc"
