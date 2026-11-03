// gamebryo2.2/corelibs/nimain/nigeometry.cpp: NiGeometry, NiAVObject, GeomStub, ViewerGeometry and more (23 functions)

#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/A5a260Object.h"
#include "fnv/decl/AVObjectA5A4.h"
#include "fnv/decl/BA3760Object.h"
#include "fnv/decl/Bound88.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/Dummy_00cc0760.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004a51d0_shell.h"
#include "fnv/decl/FUN_00a59f00_cls.h"
#include "fnv/decl/FUN_00a5a140_cls.h"
#include "fnv/decl/FUN_00a5ad00_shell.h"
#include "fnv/decl/FUN_00a5d430_Class.h"
#include "fnv/decl/FUN_00a62660_cls.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/LinkObjectA5.h"
#include "fnv/decl/LoadObject.h"
#include "fnv/decl/LoadedNode.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Owner62B.h"
#include "fnv/decl/PropHelper.h"
#include "fnv/decl/S_00a7fea0_Class.h"
#include "fnv/decl/fnv_00a59ec0__S59ec0.h"
#include "fnv/decl/fnv_00a5a900__Obj00a5a900.h"
#include "fnv/decl/fnv_00a5c290__FUN_00a5c290_shell.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00a89960__WorkerProperties.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a26000.h"
#include "fnv/symbols_00a5a000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a92000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_011f6000.h"
#include "nigeometry_decls.h"

// @fnv 0x00a89ab0
NiGeometry* NiGeometry::CopyMemberData()
{
    unsigned int* fields = (unsigned int*)this;
    fields[0] = 0;
    fields[1] = 0;
    fields[2] = 0;
    fields[3] = 0;
    fields[4] = 0;
    fields[5] = 0;
    fields[6] = 0;
    reinterpret_cast<::fnv_00a89960::WorkerProperties *>(this)->FUN_00a89960();
    return this;
}

// @fnv 0x00a7fd90
void NiGeometry::OnVisible(NiCullingProcess& process)
{
    process.Append(this);
}

// @fnv 0x00a80b50
void NiGeometry::LinkObject(NiStream& stream)
{
    reinterpret_cast<::LoadedNode *>(this)->ReadFromStream((::LoadedStream *)&(stream));
    m_spGeometryData = (NiGeometryData*)stream.GetLoadedObject();
    m_spSkinningInstance = stream.GetLoadedObject();
}

// @fnv 0x00a80680
void NiGeometry::ReplaceModelData(NiGeometryData* data)
{
    if (data)
    {
        if (m_spCollisionObject)
        {
            struct State
            {
                float value;
                unsigned char flag0;
                unsigned char flag1;
                unsigned char flag2;
                unsigned char flag3;
                unsigned char flag4;
            } state;
            m_spCollisionObject->Unk25();
            state.value = 0.0f;
            state.flag0 = 0;
            state.flag1 = 0;
            state.flag2 = 0;
            state.flag3 = 0;
            state.flag4 = 0;
            m_spCollisionObject->Unk24(&state);
        }
        m_spGeometryData = data;
    }
}

// @fnv 0x00a80820
void NiGeometry::UpdatePropertiesDownwardPass(NiPropertyState* state)
{
    reinterpret_cast<::FUN_00a5a140_cls *>(this)->FUN_00a5a140((int)(state));
    reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)0x011f42a0)))->FUN_0040fbf0((char *)(0));
    NiPropertyState* propertyState = (NiPropertyState*)((char*)this + 0x9c);
    *propertyState = *state;
    NiPropertyNode* node = *(NiPropertyNode**)((char*)this + 0x24);
    while (node)
    {
        NiProperty* property = NiPropertyNode::GetNext(node);
        if (property && property->GetType() <= 7)
            ((NiPropertyState*)((char*)this + 0x9c))->m_kProperties[property->GetType()] = property;
    }
    if (--DAT_011f42a4 == 0)
        DAT_011f42a0 = 0;
    FinalUpdate(true);
}

// @fnv 0x00a5ac90
void NiAVObject::FUN_00a5ac90(NiAVObject* dest, CloningProcess& process)
{
    reinterpret_cast<::fnv_00a5c290::FUN_00a5c290_shell *>((((NiObjectNET*)this)))->FUN_00a5c290((NiObjectNET*)dest, (::fnv_00a5c290::CloningProcess *)&(process));
    dest->m_flags = this->m_flags | 0x80000;
    dest->m_kLocalTransform = this->m_kLocalTransform;
    if (*(unsigned int*)((char*)this + 0x2c))
        ::FUN_00a5abe0((::FUN_00a5abe0_owner *)this, dest, (void *volatile)((char*)&this->m_kProperties));
    if (m_spCollisionObject)
        reinterpret_cast<::Owner62B *>((dest))->AttachTarget(m_spCollisionObject->Clone(process));
}

// Copies the previous world bound, and if flags 19/13 conditions or a zero radius apply, allocates or updates m_worldBound and refreshes the flag bit 22.
// @fnv 0x00a80710
void NiGeometry::UpdateWorldBound()
{
    NiBound* world = m_worldBound;
    const NiBound& current = PreviousBound(world);
    NiBound previous;
    unsigned int* dst = (unsigned int*)&previous;
    const unsigned int* __restrict src = (const unsigned int*)&current;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    unsigned int& flags = m_flags;
    if (!(GetFlag19() && !GetFlag13()) && previous.radius != 0.0f)
        return;
    {
        if (!world)
        {
            NiBound* allocated = (NiBound*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(16);
            SetWorldBound(allocated);
            reinterpret_cast<::FUN_004a51d0_shell *>((m_worldBound))->FUN_004a51d0((void *)&(NiPoint3::ZERO), 0.0f);
        }
        if (m_spSkinningInstance)
        {
            ((NiScreenLODData*)m_spSkinningInstance.m_pObject)->UpdateScreenBound((*(::NiBound *)((NiLODNode*)m_worldBound)));
            reinterpret_cast<::S_00a7fea0_Class *>((m_worldBound))->TransformPoint((const ::S_00a7fea0_Xf &)(this->m_worldTransform));
        }
        else
        {
            m_worldBound->Update(*(NiBound*)((char*)m_spGeometryData.m_pObject + 0x10),
                                 this->m_worldTransform);
        }
        unsigned int savedFlags = flags;
        if ((unsigned char)(savedFlags >> 22) & 1)
        {
            if (((bool)(::FUN_00a92660((const float *)(m_worldBound), (int)&(previous), {}))))
                savedFlags |= 0x400000;
            else
                savedFlags &= ~0x400000;
            flags = savedFlags;
        }
    }
}

// @fnv 0x00a80a10
void NiGeometry::ProcessClone(CloningProcess& process)
{
    reinterpret_cast<::fnv_00a59ec0::S59ec0 *>(this)->FUN_00a59ec0((::fnv_00a59ec0::CloningProcess &)(process));

    ShaderBufferRecord* clone = 0;
    reinterpret_cast<::A54440Hash *>((process.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)((const char*)this), (::A54440Manager **)&(clone));
    NiGeometry* geometryClone = (NiGeometry*)clone;
    if (m_spSkinningInstance)
    {
        if (reinterpret_cast<::A54440Hash *>((process.m_pCloneMap))->FUN_00a53c30((::A54440Manager *)((const char*)m_spSkinningInstance.m_pObject), (::A54440Manager **)&(clone)))
            *(NiPointer<NiAVObject>*)&geometryClone->m_spSkinningInstance = (NiAVObject*)clone;
        else
        {
            *(NiPointer<NiAVObject>*)&geometryClone->m_spSkinningInstance =
                (NiAVObject*)m_spSkinningInstance.m_pObject->Clone(process);
            m_spSkinningInstance.m_pObject->ProcessClone(process);
        }
    }
    NiD3DShaderInterface* shader = 0;
    if ((unsigned int)m_shader != (unsigned int)shader)
    {
        unsigned char exactType = NiIsExactKindOf(&(*reinterpret_cast<::NiRTTI *>(&::g_011f5d08)), m_shader);
        if (exactType != (unsigned char)(unsigned int)shader)
        {
            void* memory = ::operator new(sizeof(NiD3DShaderInterface));
            if ((unsigned int)memory != (unsigned int)shader)
                shader = new (memory) NiD3DShaderInterface;
            ::AssignFixedString((char *)(((NiAVObject*)shader)), (int)&((*(const ::NiFixedString *)&(reinterpret_cast<::FUN_00a62660_cls *>((((NiTexture*)m_shader)))->FUN_00a62660()))), {});
            reinterpret_cast<::BA3760Object *>((((NonActorMagicCaster*)shader)))->FUN_00ba3760((int)((MagicItem*)((const char *)(reinterpret_cast<::Dummy_00cc0760 *>((((NiD3DShaderProgram*)m_shader)))->FUN_00cc0760()))));
            geometryClone->m_shader = shader;
        }
        else
        {
            geometryClone->m_shader = m_shader;
            m_shader->Attach(geometryClone);
            reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)0x011f42a0)))->FUN_0040fbf0((char *)((const char*)shader));
            geometryClone->ApplyPropertyState(*(NiPropertyState*)((char*)this + 0x9c));
            if (--DAT_011f42a4 == 0)
                DAT_011f42a0 = (unsigned int)shader;
        }
    }
}

struct NiAccumulator;
struct NiD3DShaderDeclaration;
struct NiDynamicEffectState;
struct NiRenderer;
struct NiShader;
struct NiTriShape;
struct NiTriStrips;
struct FUN_00a80610_shell : public NiGeometry
{
    void FUN_00a80610(NiRenderer*);
};

struct DummyController
{
    void OnPreDisplayIterate()
    {
        for (DummyController* pkCtrl = this; pkCtrl != 0; pkCtrl = *(DummyController**)((char*)pkCtrl + 0x30))
        {
            (*(void(**)(DummyController*))(*(int*)pkCtrl + 0xa8))(pkCtrl);
        }
    }
};

// Stores a pointer to this object's offset 0x9c into the renderer and, if the controller at this+0xc exists, runs its pre-display iterate.
// @fnv 0x00a80610
void FUN_00a80610_shell::FUN_00a80610(NiRenderer* pkRenderer)
{
    *(void**)((char*)pkRenderer + 0xc) = (char*)&this->m_uiContentCount;
    DummyController* pkController = *(DummyController**)&this->unk0c;
    if (pkController)
        pkController->OnPreDisplayIterate();
}

struct BSStripParticleSystem;
struct NiAccumulator;
struct RgbaColor;
struct NiD3DShaderDeclaration;
struct NiDynamicEffectState;
struct NiPSysModifier;
struct NiParticleSystem;
struct NiParticles;
struct NiQuaternion;
struct NiRenderer;
struct NiShader;
struct NiTriShape;
struct NiTriStrips;
struct NiUpdateData;
struct FUN_00a80650_shell : public NiGeometry
{
    void FUN_00a80650(NiRenderer*);
};

// Stores a pointer to this+0x9C in the renderer and calls the virtual at offset 0xA8 on each node in the linked list at this+0x0C.
// @fnv 0x00a80650
void FUN_00a80650_shell::FUN_00a80650(NiRenderer* pkRenderer)
{
    *(char**)((char*)pkRenderer + 0x0C) = (char*)&this->m_uiContentCount;
    void* pNode = this->unk0c;
    while (pNode)
    {
        (*(void(**)(void*))(*(int*)pNode + 0xA8))(pNode);
        pNode = *(void**)((char*)pNode + 0x30);
    }
}

struct BSResizableTriShape;
struct NiRenderer;
struct NiTriBasedGeom;
struct NiTriShape;
struct blob16
{
    char b[16];
};
struct FUN_00a808f0_shell : public NiGeometry
{
    void UpdateSelectiveUpdateFlags(bool*, bool, bool*);
};

struct FUN_00a5a450_helper
{
};

// Calls FUN_00a5a450, then if the field at offset 0xbc is nonzero sets flags 4 and 2 at 0x30, sets *bSelectiveUpdate true and *bRigid false.
// @fnv 0x00a808f0
void FUN_00a808f0_shell::UpdateSelectiveUpdateFlags(bool* bSelectiveUpdate, bool bSelectiveUpdateTransforms,
                                                    bool* bRigid)
{
    reinterpret_cast<::AVObjectA5A4 *>((((FUN_00a5a450_helper*)this)))->FUN_00a5a450((*(bool *)(bSelectiveUpdate)), bSelectiveUpdateTransforms, (*(bool *)(bRigid)));
    if (*(int*)((char*)this + 0xbc) != 0)
    {
        this->m_flags |= 4;
        *bSelectiveUpdate = true;
        this->m_flags |= 2;
        *bRigid = false;
    }
}

namespace fnv_00a80930 {
struct FourComponentFloatVector;
struct BSPackedAdditionalGeometryData;
struct BSResizableTriShape;
struct GeometryDeviceType;
struct Direct3DDeviceInterface;
struct COMBaseInterface;
struct GeometryRelatedType;
struct NiDX9BufferManager;
struct Direct3DRenderState;
struct Direct3D9RenderSystem;
struct COMUnknownInterface;
struct RenderableGeometry;
struct Direct3D;
struct Ni2DBuffer;
struct NiAccumulator;
struct RgbaColor;
struct NiD3DGeometryGroupManager;
struct NiD3DPixelShader;
struct NiD3DShaderDeclaration;
struct NiD3DVertexShader;
struct NiDepthStencilBuffer;
struct NiDynamicEffect;
struct NiDynamicEffectState;
struct NiDynamicGeometryGroup;
struct GeometryObject;
struct NiFragmentMaterial;
struct NiGeometryBufferData;
struct GeometryVertexData;
struct GeometryContainer;
struct GeometryBufferView;
struct NiLines;
struct LevelOfDetailNode;
struct NiMaterialProperty;
struct NiPalette;
struct NiParticles;
struct NiParticlesData;
struct NiPixelData;
struct NiPixelFormat;
struct NiPoint2;
struct NiRenderTargetGroup;
struct NiRenderedCubeMap;
struct NiRenderedTexture;
struct NiRenderer;
struct RendererSupportType;
struct NiScreenTexture;
struct NiShader;
struct NiSkinData;
struct NiSkinInstance;
struct NiSkinPartition;
struct NiSourceCubeMap;
struct NiSourceTexture;
struct NiTimeController;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct NiUnsharedGeometryGroup;
struct NiUpdateData;
struct NiVBChip;
struct VertexBufferRelatedType;
struct IndexBufferManager;
struct ShaderPassRenderer;
struct ShaderPassRenderContext;
struct GraphicsRenderer;
struct RendererShaderPassContext;
struct NiD3DVertexDeclaration;
struct Direct3DPresentationState;
struct Direct3DRendererState;
struct VertexDeclarationLayout;
struct _D3DPRESENT_PARAMETERS_;
struct Direct3DResourceRecord;
struct _D3DVERTEXELEMENT9;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct FUN_00a80930_shell : public NiGeometry
{
    void FUN_00a80930(bool);
};

struct TimeCtrlView
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
    virtual bool IsTargetCtrl();
    char pad[0x2c];
    TimeCtrlView* next;
};
struct RendererView
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
    virtual unsigned int GetFlags();
};
struct SkinView
{
    char pad[0xc];
    void* partition;
};
struct ConsStub
{
    void SetDataConsistency(int);
};
struct NiRenderer
{
    static RendererView* ms_pRenderer;
};
// Scans the controller list and skin partition, then passes a consistency flag (0x4000 or 0) to the object at offset 0xb8.
// @fnv 0x00a80930
void FUN_00a80930_shell::FUN_00a80930(bool bTool)
{
    int eConsistency = 0x4000;
    TimeCtrlView* pkController = *(TimeCtrlView**)&this->unk0c;
    while (pkController)
    {
        if (pkController->IsTargetCtrl())
        {
            eConsistency = 0;
            break;
        }
        pkController = pkController->next;
    }
    SkinView* pkSkin = *(SkinView**)&this->m_spSkinningInstance.m_pObject;
    if (pkSkin)
    {
        if (bTool)
        {
            if (!pkSkin->partition)
                eConsistency = 0;
        }
        else if (!pkSkin->partition)
        {
            eConsistency = 0;
        }
        else
        {
            RendererView* pkRenderer = NiRenderer::ms_pRenderer;
            if (pkRenderer && !(pkRenderer->GetFlags() & 2))
                eConsistency = 0;
        }
    }
    ((ConsStub*)*(void**)&this->m_spGeometryData.m_pObject)->SetDataConsistency(eConsistency);
}
}  // namespace fnv_00a80930

struct RegObj
{
    virtual void a00();
    virtual void a01();
    virtual void a02();
    virtual void a03();
    virtual void a04();
    virtual void a05();
    virtual void a06();
    virtual void a07();
    virtual void a08();
    virtual void a09();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void vReg(NiStream&);
};
struct FUN_00a80430_Holder
{
    bool FUN_00a80430(NiStream&);
};
// Calls FUN_00a59f00 on kStream, then invokes vReg on the RegObj at offset 0xb8 and, if present, the one at 0xbc; returns false if the first call fails.
// @fnv 0x00a80430
bool FUN_00a80430_Holder::FUN_00a80430(NiStream& kStream)
{
    if (!reinterpret_cast<::FUN_00a59f00_cls *>(this)->FUN_00a59f00((void *)&(kStream)))
        return false;
    (*(RegObj**)((char*)this + 0xb8))->vReg(kStream);
    RegObj* pSecondRegObj = *(RegObj**)((char*)this + 0xbc);
    if (pSecondRegObj)
        pSecondRegObj->vReg(kStream);
    return true;
}

struct FUN_00a80530_shell : public NiGeometry
{
    void* FUN_00a80530();
};


// @fnv 0x00a80530
void* FUN_00a80530_shell::FUN_00a80530()
{
    return (void*)&(*reinterpret_cast<const char *const *>(&::g_011f4acc));
}

struct NiRenderer
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void UnkF0(void*);
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void Unk100(void*);
    virtual void Unk104(void*);
};
struct BaseStub
{
};
struct GeomStub : BaseStub
{
    void FUN_00a809b0(NiRenderer*);
};
// @fnv 0x00a809b0
void GeomStub::FUN_00a809b0(NiRenderer* pkRenderer)
{
    reinterpret_cast<::PropHelper *>(this)->FUN_00a59e50(pkRenderer);
    pkRenderer->UnkF0(*(void**)((char*)this + 0xb8));
    void* p = *(void**)((char*)this + 0xbc);
    if (p)
    {
        pkRenderer->Unk104(p);
        pkRenderer->Unk100(*(void**)((char*)*(void**)((char*)this + 0xbc) + 0xc));
    }
}

namespace fnv_00a7ff60 {
struct BSResizableTriShape;
struct NiRenderer;
struct NiTriBasedGeom;
struct NiTriShape;
struct blob16
{
    char b[16];
};
struct FUN_00a7ff60_shell : public NiGeometry
{
    void FUN_00a7ff60();
};

// stand-in for the object stored at this+0xb8 (NiGeometryData-like), virtual slot 0xa0
struct FUN_00a7ff60_data
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
    virtual void CalculateNormals();
};

// @fnv 0x00a7ff60
void FUN_00a7ff60_shell::FUN_00a7ff60()
{
    ((FUN_00a7ff60_data*)(*(void**)&this->m_spGeometryData.m_pObject))->CalculateNormals();
}
}  // namespace fnv_00a7ff60

struct S_00a80470_Data;

struct S_00a80470_Controller
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
    virtual bool FUN_00a805c0(S_00a80470_Controller*);
};

struct S_00a80470_Data
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
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    S_00a80470_Controller* unkB8;
    S_00a80470_Controller* unkBC;
};

struct S_00a80470_Owner : public S_00a80470_Data
{
    bool FUN_00a80470(S_00a80470_Data*);
};

// @fnv 0x00a80470
bool S_00a80470_Owner::FUN_00a80470(S_00a80470_Data* apData)
{
    if (!reinterpret_cast<::A5a260Object *>(this)->FUN_00a5a260((::A5a260CompareBase *)(apData)))
        return false;

    S_00a80470_Controller* thisBC = this->unkBC;
    S_00a80470_Controller* argBC = apData->unkBC;

    bool argIsNull = (argBC == 0);
    bool bThisBCNull = (thisBC == 0);
    if (bThisBCNull != argIsNull)
        return false;

    if (thisBC != 0)
    {
        if (!thisBC->FUN_00a805c0(argBC))
            return false;
    }

    S_00a80470_Controller* pThisB8 = this->unkB8;
    S_00a80470_Controller* other = apData->unkB8;
    bool bResult = pThisB8->FUN_00a805c0(other);
    return bResult;
}

struct ViewerStrings
{
    void* vtable;
    char** entries;
    unsigned short capacity, count, effectiveSize, growBy;
    void FUN_0096ad30(unsigned int);
    void Add(char* text)
    {
        unsigned int index = count;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, text);
    }
};
struct NamedRTTI
{
    const char* name;
    const char* GetName() const
    {
        return name;
    }
};
struct SkinPartition
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
};
struct SkinInstanceInfo : NiObject
{
    unsigned int unk08;
    SkinPartition* partition;
};
struct ViewerGeometry : NiGeometry
{
    void FUN_00a80e70(ViewerStrings*);
};
// @fnv 0x00a80e70
void ViewerGeometry::FUN_00a80e70(ViewerStrings* strings)
{
    reinterpret_cast<::FUN_00a5ad00_shell *>(this)->FUN_00a5ad00((::Stream *)(strings));
    strings->Add(FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f4acc))));
    strings->Add(::FUN_00a7d5a0("GeomData", (void *)(static_cast<NiGeometryData*>(m_spGeometryData))));
    NiD3DShaderInterface* shader = m_shader;
    if (shader)
        strings->Add(::fnv_00a7d5e0::FUN_00a7d5e0("shader", reinterpret_cast<NamedRTTI*>(shader->GetRTTI())->GetName()));
    SkinInstanceInfo* skin = static_cast<SkinInstanceInfo*>(m_spSkinningInstance.m_pObject);
    if (skin && skin->partition)
        strings->Add(FUN_00a7d510("skin partitions", skin->partition->GetCount()));
}


struct GeomFixedString
{
    char* m_handle;
    GeomFixedString() throw()
    {
        m_handle = ::DAT_0109b220;
    }
    ~GeomFixedString() throw()
    {
        if (m_handle != ::DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_handle - 8));
    }
};

struct GeomBinaryStream
{
    typedef unsigned int(__cdecl* ReadFn)(GeomBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    ReadFn m_pfnRead;
    unsigned int Read(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                      unsigned int uiNumComponents) throw()
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void BinaryStreamLoad(GeomBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls) throw()
{
    unsigned int uiSize = sizeof(T);
    pkIstr->Read(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}

struct GeomStream;

struct GeomStream
{
    unsigned int GetFileVersion() const
    {
        return m_uiNifVersion;
    }
    template <class T> void LoadRaw(T& value) throw()
    {
        BinaryStreamLoad(m_pUnderlyingStream, &value, 1);
    }
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int m_uiNifVersion;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    GeomBinaryStream* m_pUnderlyingStream;
};

struct FUN_00a80bf0_shell : public NiGeometry
{
    void FUN_00a80bf0(GeomStream& kStream);
};

// @fnv 0x00a80bf0
void FUN_00a80bf0_shell::FUN_00a80bf0(GeomStream& kStream)
{
    reinterpret_cast<::LoadObject *>(this)->FUN_00a5a510((::LoadStream &)((NiStream&)kStream));

    reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
    reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();

    if (kStream.GetFileVersion() >= 0x14020005)
    {
        unsigned int uiNumMaterials = 0;
        kStream.LoadRaw(uiNumMaterials);
        for (unsigned int i = 0; i < uiNumMaterials; i++)
        {
            GeomFixedString kMaterialName;
            reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(kMaterialName));
            unsigned int uiMaterialExtraData;
            kStream.LoadRaw(uiMaterialExtraData);
        }
        unsigned int uiActiveMaterial;
        kStream.LoadRaw(uiActiveMaterial);
    }
    else if (kStream.GetFileVersion() >= 0x05000015)
    {
        bool bHasShader = false;
        kStream.LoadRaw(bHasShader);
        if (bHasShader)
        {
            GeomFixedString kShaderName;
            if (kStream.GetFileVersion() < 0x14010001)
                reinterpret_cast<::Cls_a64ea0 *>(&(kStream))->FUN_00a64ea0((char **)&(kShaderName));
            else
                reinterpret_cast<::fnv_00a64df0::FUN_00a64df0_Stream *>(&(kStream))->FUN_00a64df0((::fnv_00a64df0::NiFixedString &)(kShaderName));
            unsigned int uiImplementation;
            ::FUN_00a26df0((::MyStream *)&(kStream), (void *)&(uiImplementation));
        }
    }

    if (kStream.GetFileVersion() >= 0x14020007)
    {
        bool m_bDataDirty = false;
        kStream.LoadRaw(m_bDataDirty);
    }
}

struct ReaderStub
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiPosition;
    unsigned int unk08;
    int(__cdecl* m_pRead)(ReaderStub*, void*, unsigned int, unsigned int*, unsigned int);
    template <class T> void LoadValue(T& value)
    {
        unsigned int uiElem = sizeof(T);
        m_uiPosition += m_pRead(this, &value, sizeof(T), &uiElem, 1);
    }
};
class StreamStub
{
  public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void vfn_30(void* value);
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
    ReaderStub* m_pkReader;
};
class GeometryStub
{
  public:
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
    void* m_spGeometryData;
    void* m_spSkinningInstance;
    void FUN_00a80db0(StreamStub& stream);
};
template <class T> void LoadStreamValue(StreamStub& stream, T& value)
{
    ReaderStub* reader = stream.m_pkReader;
    unsigned int uiElem = sizeof(T);
    reader->m_uiPosition += reader->m_pRead(reader, &value, uiElem, &uiElem, 1);
}
// @fnv 0x00a80db0
void GeometryStub::FUN_00a80db0(StreamStub& stream)
{
    reinterpret_cast<::fnv_00a5a900::Obj00a5a900 *>(this)->FUN_00a5a900((::fnv_00a5a900::NiStream &)(stream));
    stream.vfn_30(m_spGeometryData);
    stream.vfn_30(m_spSkinningInstance);
    unsigned int uiData0 = 0;
    stream.m_pkReader->LoadValue(uiData0);
    {
        unsigned int uiData1 = 0;
        stream.m_pkReader->LoadValue(uiData1);
    }
    unsigned char ucData2 = 0;
    stream.m_pkReader->LoadValue(ucData2);
}

class NiObjectNET_stub
{
  public:
    void FUN_00a7fdc0(int);
};

// @fnv 0x00a7fdc0
void NiObjectNET_stub::FUN_00a7fdc0(int a1)
{
    reinterpret_cast<::LinkObjectA5 *>(this)->FUN_00a5c6a0((*(::NiStream *)(a1)));
}

class GeometryBase804e0
{
  public:
    GeometryBase804e0() throw();
    virtual void Slot00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
};
class PropertyState804e0
{
  public:
    PropertyState804e0() throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};
class FUN_00a804e0 : public GeometryBase804e0
{
  public:
    FUN_00a804e0(NiGeometryData* data);
    PropertyState804e0 m_propertyState;
    NiGeometryData* m_modelData;
    NiObject* m_skinInstance;
    NiD3DShaderInterface* m_shader;
};

// Constructor that stores the NiGeometryData pointer, increments its reference count if non-null, and nulls m_skinInstance and m_shader.
// @fnv 0x00a804e0
FUN_00a804e0::FUN_00a804e0(NiGeometryData* apModelData) : m_modelData(apModelData)
{
    if (apModelData)
        InterlockedIncrement((long volatile*)&apModelData->m_uiRefCount);
    m_skinInstance = 0;
    m_shader = 0;
}

struct WideProduct
{
    const float& a;
    const float& b;
    WideProduct(const float& x, const float& y) : a(x), b(y)
    {}
    operator double() const
    {
        return a * b;
    }
};
struct S00a7ff70_P3
{
    float x, y, z;
    S00a7ff70_P3()
    {}
    S00a7ff70_P3(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
    {}
    S00a7ff70_P3 operator+(const S00a7ff70_P3& p) const
    {
        return S00a7ff70_P3(x + p.x, y + p.y, z + p.z);
    }
    S00a7ff70_P3 operator-(const S00a7ff70_P3& p) const
    {
        return S00a7ff70_P3(x - p.x, y - p.y, z - p.z);
    }
    S00a7ff70_P3 operator/(float s) const
    {
        float inv = 1.0f / s;
        return S00a7ff70_P3(inv * x, inv * y, inv * z);
    }
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    ThreeByThreeMatrix FUN_0043f8d0(const ThreeByThreeMatrix& o) const;
    ThreeByThreeMatrix FUN_00a588a0(const ThreeByThreeMatrix& o) const;
    S00a7ff70_P3 operator*(const S00a7ff70_P3& p) const
    {
        return S00a7ff70_P3(m_afEntries[0][0] * p.x + m_afEntries[0][1] * p.y + m_afEntries[0][2] * p.z,
                            m_afEntries[1][0] * p.x + m_afEntries[1][1] * p.y + m_afEntries[1][2] * p.z,
                            m_afEntries[2][0] * p.x + m_afEntries[2][1] * p.y + m_afEntries[2][2] * p.z);
    }
    S00a7ff70_P3 FirstProduct(const S00a7ff70_P3& p) const
    {
        return S00a7ff70_P3(m_afEntries[0][0] * p.x + m_afEntries[0][1] * p.y + WideProduct(m_afEntries[0][2], p.z),
                            WideProduct(m_afEntries[1][0], p.x) + m_afEntries[1][1] * p.y + m_afEntries[1][2] * p.z,
                            WideProduct(m_afEntries[2][0], p.x) + m_afEntries[2][1] * p.y + m_afEntries[2][2] * p.z);
    }
public:
    ::ThreeByThreeMatrix operator+(const ::ThreeByThreeMatrix &) const;
public:
    bool Inverse(::ThreeByThreeMatrix &);
};
inline S00a7ff70_P3 operator*(const S00a7ff70_P3& p, const ThreeByThreeMatrix& m)
{
    return S00a7ff70_P3(m.m_afEntries[0][0] * p.x + m.m_afEntries[1][0] * p.y + m.m_afEntries[2][0] * p.z,
                        m.m_afEntries[0][1] * p.x + m.m_afEntries[1][1] * p.y + m.m_afEntries[2][1] * p.z,
                        m.m_afEntries[0][2] * p.x + m.m_afEntries[1][2] * p.y + m.m_afEntries[2][2] * p.z);
}
__declspec(noinline) ThreeByThreeMatrix ThreeByThreeMatrix::FUN_0043f8d0(const ThreeByThreeMatrix& o) const
{
    ThreeByThreeMatrix result;
    result.m_afEntries[0][0] = m_afEntries[0][0] * o.m_afEntries[0][0] + m_afEntries[0][1] * o.m_afEntries[1][0] +
                               m_afEntries[0][2] * o.m_afEntries[2][0];
    result.m_afEntries[0][1] = m_afEntries[0][0] * o.m_afEntries[0][1] + m_afEntries[0][1] * o.m_afEntries[1][1] +
                               m_afEntries[0][2] * o.m_afEntries[2][1];
    result.m_afEntries[0][2] = m_afEntries[0][0] * o.m_afEntries[0][2] + m_afEntries[0][1] * o.m_afEntries[1][2] +
                               m_afEntries[0][2] * o.m_afEntries[2][2];
    result.m_afEntries[1][0] = m_afEntries[1][0] * o.m_afEntries[0][0] + m_afEntries[1][1] * o.m_afEntries[1][0] +
                               m_afEntries[1][2] * o.m_afEntries[2][0];
    result.m_afEntries[1][1] = m_afEntries[1][0] * o.m_afEntries[0][1] + m_afEntries[1][1] * o.m_afEntries[1][1] +
                               m_afEntries[1][2] * o.m_afEntries[2][1];
    result.m_afEntries[1][2] = m_afEntries[1][0] * o.m_afEntries[0][2] + m_afEntries[1][1] * o.m_afEntries[1][2] +
                               m_afEntries[1][2] * o.m_afEntries[2][2];
    result.m_afEntries[2][0] = m_afEntries[2][0] * o.m_afEntries[0][0] + m_afEntries[2][1] * o.m_afEntries[1][0] +
                               m_afEntries[2][2] * o.m_afEntries[2][0];
    result.m_afEntries[2][1] = m_afEntries[2][0] * o.m_afEntries[0][1] + m_afEntries[2][1] * o.m_afEntries[1][1] +
                               m_afEntries[2][2] * o.m_afEntries[2][1];
    result.m_afEntries[2][2] = m_afEntries[2][0] * o.m_afEntries[0][2] + m_afEntries[2][1] * o.m_afEntries[1][2] +
                               m_afEntries[2][2] * o.m_afEntries[2][2];
    return result;
}

struct S00a7ff70_Xf
{
    ThreeByThreeMatrix m_kOrientation;
    S00a7ff70_P3 m_kTranslation;
    float m_fScale;
};
struct S00a7ff70_Sub
{
    int unk00;
};
struct S00a7ff70_Data
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
    virtual unsigned short GetActiveVertexQuantity();
    int unk04;
    int unk08;
    int unk0c;
    S00a7ff70_Sub m_sub;
    int unk14;
    int unk18;
    int unk1c;
    S00a7ff70_P3* m_pkVertex;
    S00a7ff70_P3* m_pkNormal;
};
struct S00a7ff70_Geom : NiAVObject
{
    S00a7ff70_Data* m_spGeometryData;
    const S00a7ff70_Xf& Local() const
    {
        return *(const S00a7ff70_Xf*)&m_kLocalTransform;
    }
    void FUN_00a7ff70(const ThreeByThreeMatrix& kMat, const S00a7ff70_P3& kTrn, bool bOnLeft);
};
// Updates vertex and normal arrays using kMat and kTrn, with a different calculation when bOnLeft is true, then calls FUN_00a7ee30.
// @fnv 0x00a7ff70
void S00a7ff70_Geom::FUN_00a7ff70(const ThreeByThreeMatrix& kMat, const S00a7ff70_P3& kTrn, bool bOnLeft)
{
    unsigned short usVertices = m_spGeometryData->GetActiveVertexQuantity();
    S00a7ff70_P3* pkVertex = m_spGeometryData->m_pkVertex;
    S00a7ff70_P3* pkNormal = m_spGeometryData->m_pkNormal;
    unsigned short i;
    if (bOnLeft)
    {
        const ThreeByThreeMatrix& kRot = Local().m_kOrientation.FUN_00a588a0(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(kMat))->operator+(Local().m_kOrientation));
        S00a7ff70_P3 kTrans =
            ((kTrn + kMat * Local().m_kTranslation - Local().m_kTranslation) * Local().m_kOrientation) /
            Local().m_fScale;
        if (pkVertex)
        {
            for (i = 0; i < usVertices; i++)
                pkVertex[i] = kRot.FirstProduct(pkVertex[i]) + kTrans;
        }
        if (pkNormal)
        {
            ThreeByThreeMatrix kInv;
            reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(kRot))->Inverse(kInv);
            for (i = 0; i < usVertices; i++)
                pkNormal[i] = pkNormal[i] * kInv;
        }
    }
    else
    {
        if (pkVertex)
        {
            for (i = 0; i < usVertices; i++)
                pkVertex[i] = kMat * pkVertex[i] + kTrn;
        }
        if (pkNormal)
        {
            ThreeByThreeMatrix kInv;
            reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(kMat))->Inverse(kInv);
            for (i = 0; i < usVertices; i++)
                pkNormal[i] = pkNormal[i] * kInv;
        }
    }
    reinterpret_cast<::Bound88 *>(&(m_spGeometryData->m_sub))->ComputeBoundingSphere(usVertices, (const ::Vec88 *)(pkVertex));
}

#include "generated/data/gamebryo2.2/corelibs/nimain/nigeometry.inc"
