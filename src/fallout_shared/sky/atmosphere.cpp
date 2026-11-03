
// src/fallout_shared/sky/atmosphere.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/sky/atmosphere.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSMultiBoundRoom.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/F940Owner.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004e45e0_shell.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_0050d100_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005bfbd0_Class.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_00633bf0_Class.h"
#include "fnv/decl/FUN_00633c20_Class.h"
#include "fnv/decl/FUN_00633c40_Class.h"
#include "fnv/decl/FUN_00633c60_Class.h"
#include "fnv/decl/FUN_00634930_cls.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_009a5480_class.h"
#include "fnv/decl/FUN_009c1a50_shell.h"
#include "fnv/decl/FUN_00c3a8a0_cls.h"
#include "fnv/decl/ImageSpaceEffectParam.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/TESAmmoInitCalls.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_00633d90__FUN_00633d90_Class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005bf000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_00b89000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011ff000.h"
struct Atmosphere
{
    void FUN_00633190();
};


struct FUN_00633160_shell : Atmosphere
{
    void* FUN_00633160(unsigned int flags);
};

struct PathingRefStandIn
{
    void* m_pObject;

    ~PathingRefStandIn();
    void Reset(void* pObject);
};

struct PathingStandInBase
{
    virtual ~PathingStandInBase();

    int unk04;
};

struct FUN_00633190 : PathingStandInBase
{
    PathingRefStandIn m_kRefA;
    PathingRefStandIn m_kRefB;
    PathingRefStandIn m_kRefC;
    PathingRefStandIn m_kRefD;

    virtual ~FUN_00633190();
};
// @fnv 0x00633160
void* FUN_00633160_shell::FUN_00633160(unsigned int flags)
{
    reinterpret_cast<::FUN_00633190 *>(this)->FUN_00633190::~FUN_00633190();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that resets the four PathingRefStandIn members (m_kRefB, m_kRefA, m_kRefD, m_kRefC) to null.
// @fnv 0x00633190
FUN_00633190::~FUN_00633190()
{
    m_kRefB.Reset(0);
    m_kRefA.Reset(0);
    m_kRefD.Reset(0);
    m_kRefC.Reset(0);
}

void* __cdecl FUN_00aa13e0(unsigned int uiSize);
void __cdecl AtmoFree(void* pvMem);

struct AtmoObject;

struct AtmoNode
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
    virtual void AttachChildInAvailableSlot(AtmoNode* pkChild, int abFirstAvailableSlot);

    int unk04[0xac / 4 - 1];
    AtmoNode(int iChildren);
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void* pvMem, unsigned int)
    {
        AtmoFree(pvMem);
    }
};

template <class T> struct AtmoPtr
{
    T* m_pObject;
    AtmoPtr& FUN_0066b0d0(T* pObject);
    T* FUN_00559450() const;
};

struct AtmoProperty;
struct AtmoPropertyList
{
};
struct AtmoShaderMgr
{
};

struct AtmoObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int IsGeometry();
};

struct AtmoStream
{
    char unk000[0x5cc];
    AtmoStream();
    ~AtmoStream();
};

struct AtmoLoadedModel
{
    int unk00[4];
    AtmoLoadedModel(const char* pPath, AtmoStream* pkStream, int a3, int a4);
    ~AtmoLoadedModel();
};

struct AtmosphereImpl
{
    int unk00;
    AtmoPtr<AtmoNode> m_spRootNode;
    AtmoPtr<AtmoNode> m_spAtmosphere;
    AtmoPtr<AtmoProperty> m_spFog;
    AtmoPtr<AtmoNode> m_spSkyNode;
    AtmoPtr<AtmoNode> m_spSkyShape;

    void SetAtmosphere(AtmoNode* pkRoot, AtmoProperty* pkFog);
};

// @fnv 0x00633260
void AtmosphereImpl::SetAtmosphere(AtmoNode* pkRoot, AtmoProperty* pkFog)
{
    reinterpret_cast<::F940Owner *>(this)->CreateSortAdjustNode((::F940Parent *)(pkRoot));
    if (!(*reinterpret_cast<unsigned char *>(&::DAT_011f941e)))
    {
        ::FUN_00b899a0((*(::ShapePtr_b899a0 *)(&m_spSkyShape)));
        reinterpret_cast<::TaskQueueInterface *>((((::AtmoNode *)(::FUN_00559450((int *)&(m_spSkyShape))))))->FUN_004902f0(true);
        reinterpret_cast<::FUN_00440460_S *>((((::AtmoNode *)(::FUN_00559450((int *)&(m_spSkyShape))))))->FUN_00440460((const ::V3 *)(void *)(((void *)&(reinterpret_cast<::NiAVObject *>((((::AtmoPropertyList *)(::FUN_00558310((::NiNode_00558310 *)(((::AtmoShaderMgr *)(::FUN_0045c670()))))))))->FUN_0043c490()))));
        m_spSkyNode.FUN_0066b0d0(new AtmoNode(0));
        reinterpret_cast<::TaskQueueInterface *>((((::AtmoNode *)(::FUN_00559450((int *)&(m_spSkyNode))))))->FUN_004902f0(true);
        ((::AtmoNode *)(::FUN_00559450((int *)&(m_spSkyNode))))->AttachChildInAvailableSlot(((::AtmoNode *)(::FUN_00559450((int *)&(m_spSkyShape)))), 1);
        ((::AtmoNode *)(::FUN_00559450((int *)&(m_spRootNode))))->AttachChildInAvailableSlot(((::AtmoNode *)(::FUN_00559450((int *)&(m_spSkyNode)))), 1);
    }

    AtmoStream kStream;
    if (reinterpret_cast<::FUN_00c3a8a0_cls *>(&(kStream))->FUN_00c3a8a0((unsigned int)("Meshes\\Sky\\Atmosphere.nif"), 0))
    {
        AtmoLoadedModel kModel_("Meshes\\Sky\\Atmosphere.nif", &kStream, 0, 0);
        AtmoObject* pkFirstVal2 = ((::AtmoObject *)(::fnv_0043b230::FUN_0043b230((const char *)&(kModel_))));
        AtmoNode* pkMeshRes = 0;
        AtmoObject* pkObjectOut = ((::AtmoObject *)(::fnv_0043b230::FUN_0043b230((const char *)&(kModel_))));
        if (pkObjectOut)
        {
            if (pkObjectOut->IsGeometry())
                pkMeshRes = ((::AtmoNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((pkObjectOut))->FUN_0045bc00(0)));
            else if (::FUN_0043b300((const ::NiRTTI *)((*reinterpret_cast<char (*)[]>(&::g_011f4a40))), (::NiAVObject *)(pkObjectOut)))
                pkMeshRes = (AtmoNode*)pkObjectOut;
        }
        if (!pkMeshRes)
        {
            ::FUN_005b5e40();
            return;
        }
        m_spAtmosphere.FUN_0066b0d0(pkMeshRes);
        reinterpret_cast<::TaskQueueInterface *>((((::AtmoNode *)(::FUN_00559450((int *)&(m_spAtmosphere))))))->FUN_004902f0(true);
        ((::AtmoNode *)(::FUN_00559450((int *)&(m_spRootNode))))->AttachChildInAvailableSlot(((::AtmoNode *)(::FUN_00559450((int *)&(m_spAtmosphere)))), 1);
    }
    m_spFog.FUN_0066b0d0(pkFog);
    ::BSShaderManager::SetFogPropertyForIndex(0, (::BSFogProperty *)(pkFog));
}

namespace fnv_006335d0 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct Param
{
    float a;
    float b;
    float c;
    float d;
};
struct NiFrustum
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
};
struct NiCamera
{
};
struct FUN_00507700_cls : NiCamera
{
};
struct Stub_00a6faf0 : FUN_00507700_cls
{
};
struct BSFaceGenAnimationData : Stub_00a6faf0
{
};
struct Light
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
};
struct FUN_00633bf0_Class
{
};
struct FUN_00633c20_Class : FUN_00633bf0_Class
{
};
struct FUN_00633c40_Class : FUN_00633c20_Class
{
};
struct FUN_00633c60_Class : FUN_00633c40_Class
{
};
struct Fog : FUN_00633c60_Class
{
};
struct Ref
{
    int unk00;
};
struct FUN_009a5480_class
{
};
struct BSMultiBoundRoom : FUN_009a5480_class
{
};
struct Node : BSMultiBoundRoom
{
};
struct Probe
{
};
struct Info
{
    float unk00;
    float unk04;
    float unk08;
};
struct BSFaceGenNiNode
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
    virtual float v40();
};
struct Atm
{
    int unk00;
    int unk04;
    Ref unk08;
    Ref unk0c;
    int unk10;
    int unk14;
    unsigned char unk18;
    void UpdateAtmosphere(Node* node, float f);
};
// Updates the atmosphere for a node: refreshes the fog reference, computes fog positions, and syncs the face-gen animation frustum far plane.
// @fnv 0x006335d0
void Atm::UpdateAtmosphere(Node* node, float f)
{
    float len;
    {
        float p3;
        Light* p1;
        {
            BSFaceGenAnimationData* u;
            {
                float farv;
                {
                    NiFrustum tmp;
                    {
                        Param pData;
                        {
                            Param light;
                            Param p0;
                            {
                                Param k;
                                {
                                    Param p4;
                                    Param t;
                                    {
                                        NiPoint3 pNode;

                                        if (!node)
                                            return;
                                        if (((::fnv_006335d0::Fog *)(::FUN_00b55520(0))) != ((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c)))))
                                            ::BSShaderManager::SetFogPropertyForIndex(0, (::BSFogProperty *)(::fnv_006335d0::Fog *)(((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c))))));
                                        reinterpret_cast<::FUN_008d0600_s *>(this)->FUN_008d0600((int)(node), f);
                                        if (((int)(reinterpret_cast<::FUN_00476c90_Class *>((node))->FUN_00476c90())) == 3 || 2 == ((int)(reinterpret_cast<::FUN_00476c90_Class *>((node))->FUN_00476c90())))
                                        {
                                            if (!(((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk08))))))
                                                return;
                                            if ((*reinterpret_cast<::fnv_006335d0::Probe * *>(&::_g_thePlayer)) != 0 && ((int)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_006335d0::Probe * *>(&::_g_thePlayer))))->GetTarget())) &&
                                                ((::fnv_006335d0::Info *)(::FUN_0045bb80((int)(((void *)(::FUN_00558310((::NiNode_00558310 *)(::fnv_006335d0::BSFaceGenNiNode *)(((::fnv_006335d0::BSFaceGenNiNode *)(::FUN_0045c670()))))))))))->unk08 <
                                                    reinterpret_cast<::FUN_0057b0a0_shell *>(((*reinterpret_cast<::fnv_006335d0::Probe * *>(&::_g_thePlayer))))->FUN_0057b0a0())
                                            {
                                                (*reinterpret_cast<::fnv_006335d0::Param *>(&::DAT_011ff8e0)) = *((::fnv_006335d0::Param *)(new ((void *)&(pData)) ::ImageSpaceEffectParam(((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))->x,
                                                                                   ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))->y,
                                                                                   ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))->z, 1.0f)));
                                                (*reinterpret_cast<::fnv_006335d0::Param *>(&::DAT_011ff8f0)) =
                                                    *((::fnv_006335d0::Param *)(new ((void *)&(p0)) ::ImageSpaceEffectParam(((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))->x, ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))->y,
                                                                     ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))->z, 1.0f)));
                                                (*reinterpret_cast<::fnv_006335d0::Param *>(&::DAT_011ff900)) = *((::fnv_006335d0::Param *)(new ((void *)&(light)) ::ImageSpaceEffectParam(((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))->x,
                                                                                   ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))->y,
                                                                                   ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))->z, 1.0)));
                                            }
                                            else
                                            {
                                                (*reinterpret_cast<::fnv_006335d0::Param *>(&::DAT_011ff8e0)) =
                                                    *((::fnv_006335d0::Param *)(new ((void *)&(k)) ::ImageSpaceEffectParam(((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_0050d100_shell *>((node))->FUN_0050d100()))->x, ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_0050d100_shell *>((node))->FUN_0050d100()))->y,
                                                                    ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_0050d100_shell *>((node))->FUN_0050d100()))->z, 1.0)));
                                                (*reinterpret_cast<::fnv_006335d0::Param *>(&::DAT_011ff8f0)) =
                                                    *((::fnv_006335d0::Param *)(new ((void *)&(p4)) ::ImageSpaceEffectParam(((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_009c1a50_shell *>((node))->FUN_009c1a50()))->x, ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_009c1a50_shell *>((node))->FUN_009c1a50()))->y,
                                                                     ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_009c1a50_shell *>((node))->FUN_009c1a50()))->z, 1.0)));
                                                (*reinterpret_cast<::fnv_006335d0::Param *>(&::DAT_011ff900)) =
                                                    *((::fnv_006335d0::Param *)(new ((void *)&(t)) ::ImageSpaceEffectParam(((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<struct ::FUN_005a8080 *>((node))->GetField()))->x, ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<struct ::FUN_005a8080 *>((node))->GetField()))->y,
                                                                    ((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<struct ::FUN_005a8080 *>((node))->GetField()))->z, 1.0f)));
                                            }
                                        }
                                        if (0 != ((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c)))))
                                        {
                                            p1 = ((::fnv_006335d0::Light *)(reinterpret_cast<::TESAmmoInitCalls *>((node))->FUN_00923000()));
                                            reinterpret_cast<::FUN_0049ed90_shell *>((((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c))))))->FUN_0049ed90(p1->unk04 > p1->unk00);
                                            if (unk18)
                                            {
                                                ::FUN_005bf9a0((char *)(((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c))))), p1->unk00, p1->unk04);
                                                reinterpret_cast<::FUN_005bfbd0_Class *>((((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c))))))->FUN_005bfbd0(reinterpret_cast<::FUN_004e45e0_shell *>((node))->GetFieldE8Float());
                                            }
                                            if (!((*reinterpret_cast<unsigned char *>(&::DAT_011f941e))))
                                            {
                                                p3 = ::DAT_011f9190 / 3.75f;
                                                reinterpret_cast<::FUN_00633bf0_Class *>((((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c))))))->FUN_00633bf0(
                                                    (const ::NiPoint3 *)(const ::fnv_006335d0::NiPoint3 *)(((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::NiPoint3 *>((((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))))->ScaleTo((::NiPoint3 *)(::fnv_006335d0::NiPoint3 *)(&pNode), p3)))));
                                            }
                                            else
                                            {
                                                reinterpret_cast<::FUN_00633bf0_Class *>((((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c))))))->FUN_00633bf0((const ::NiPoint3 *)(const ::fnv_006335d0::NiPoint3 *)(((::fnv_006335d0::NiPoint3 *)(reinterpret_cast<::FUN_00624700_shell *>((node))->FUN_00624700()))));
                                            }
                                            len = reinterpret_cast<::FUN_009a5480_class *>((node))->GetFieldE4Float();
                                            reinterpret_cast<::FUN_00633c40_Class *>((((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c))))))->FUN_00633c40(reinterpret_cast<::FUN_009a5480_class *>((node))->GetFieldE4Float());
                                            reinterpret_cast<::FUN_00633c20_Class *>((((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c))))))->FUN_00633c20(p1->unk08, p1->unk0c);
                                            reinterpret_cast<::FUN_00633c60_Class *>((((::fnv_006335d0::Fog *)(::FUN_00559450((int *)&(unk0c))))))->FUN_00633c60((const ::NiPoint3 &)(*(NiPoint3*)reinterpret_cast<::BSMultiBoundRoom *>((node))->FUN_006ab360()));
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (unk18)
                    {
                        u = 0;
                        farv = ((::fnv_006335d0::BSFaceGenNiNode *)(::FUN_0045c670()))->v40();
                        u = ((::fnv_006335d0::BSFaceGenAnimationData *)(reinterpret_cast<::BSFaceGenNiNode *>((((::fnv_006335d0::BSFaceGenNiNode *)(::FUN_0045c670()))))->GetAnimationData()));
                        if (0 != u)
                        {
                            tmp = (*(const ::fnv_006335d0::NiFrustum *)&(reinterpret_cast<::NiCamera *>((void *)(u))->GetViewFrustum()));
                            if (farv != tmp.unk14)
                            {
                                tmp.unk14 = farv;
                                reinterpret_cast<::FUN_00507700_cls *>((u))->FUN_00507700(farv / tmp.unk10);
                                reinterpret_cast<::NiCamera *>((u))->UpdateViewFrustum((*(const ::NiFrustum *)(&tmp)));
                            }
                        }
                    }
                }
            }
        }
    }
}
}  // namespace fnv_006335d0

struct FUN_00633cc0_SkyObject
{
    FUN_00633cc0_SkyObject();
    ~FUN_00633cc0_SkyObject();
    virtual void vf();
};

struct FUN_00633cc0_ElemA
{
    void* m_pObject;
    FUN_00633cc0_ElemA();
    ~FUN_00633cc0_ElemA();
};

struct FUN_00633cc0_ElemB
{
    int unk0;
    int unk4;
    int unk8;
    FUN_00633cc0_ElemB();
};

struct FUN_00633cc0 : FUN_00633cc0_SkyObject
{
    int unk04;
    FUN_00633cc0_ElemA m_kPointA[4];
    FUN_00633cc0_ElemA m_kPointB[4];
    FUN_00633cc0_ElemB m_iThirdValue[4];
    unsigned short m_58;
    unsigned char m_5a;

    FUN_00633cc0();
    virtual void vf();
};

// Initializes the object: clears m_58, calls FUN_00633d90 and FUN_00634930, then sets m_5a to 0.
// @fnv 0x00633cc0
FUN_00633cc0::FUN_00633cc0() : m_58(0)
{
    reinterpret_cast<::fnv_00633d90::FUN_00633d90_Class *>(this)->FUN_00633d90();
    reinterpret_cast<::FUN_00634930_cls *>(this)->FUN_00634930();
    m_5a = 0;
}
