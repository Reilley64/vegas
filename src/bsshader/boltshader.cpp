#include <cstdint>
#include <cstddef>
// bsshader/boltshader.cpp: BoltShader (9 functions)

#include "fnv/decl/A72BB0_DataStreamOwner.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/D3DRenderStateGroup.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a51d0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a726a0_cls.h"
#include "fnv/decl/FUN_00a72ca0_Class.h"
#include "fnv/decl/FUN_00e7ecd0_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiGPUProgramOwner.h"
#include "fnv/decl/StageSet.h"
#include "fnv/decl/StateGroup.h"
#include "fnv/decl/fnv_00bc0f80__FUN_00bc0f80.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00bc0000.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_00e76000.h"
#include "fnv/symbols_00e7e000.h"
#include "fnv/symbols_011ae000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01201000.h"
#include "boltshader_decls.h"

// Creates a shader declaration, configures its entries via vfn_08c/vfn_094, builds a BoltShader from it, and runs its setup calls before returning it.
// @fnv 0x00bc10e0
BSShader* BoltShader::CreateShader()
{
    BoltShader* shader = 0;
    NiD3DVertexDeclaration* declaration = ::FUN_00e76700(DAT_011f9508, 5, 1);
    BoltShaderDeclarationCalls* declarationCalls = (BoltShaderDeclarationCalls*)declaration;

    declarationCalls->vfn_08c((std::uintptr_t)shader, (unsigned int)shader, (unsigned int)shader, 2, (unsigned int)shader);
    declarationCalls->vfn_08c(1, 3, 3, 2, (unsigned int)shader);
    declarationCalls->vfn_08c(2, 5, 4, 3, (unsigned int)shader);
    declarationCalls->vfn_08c(3, 7, 5, 1, (unsigned int)shader);
    declarationCalls->vfn_094((unsigned int)shader, 4, 6, 0x80000000, (unsigned int)shader, 10, 1,
                              (unsigned int)shader);
    declarationCalls->vfn_0b4();

    shader = new BoltShader(declaration);
    BoltShaderCalls* shaderCalls = (BoltShaderCalls*)shader;
    shaderCalls->vfn_04c();
    shaderCalls->vfn_13c();
    shaderCalls->vfn_140();
    shaderCalls->vfn_11c();
    shaderCalls->vfn_0c0(declaration);
    return shader;
}

class NiD3DPass
{
  public:
    static void __cdecl CreateD3DPass(NiPointer<NiD3DPass>&);
public:
    void DestroyPass();
};

void ConfigurePassRenderStates(char* pThis);

// Ensures the NiD3DPass pointer at pThis+0x168 is set, then calls ConfigurePassRenderStates(pThis) and returns true.
// @fnv 0x00bc1570
bool EnsurePassAndUpdate(char* pThis)
{
    NiPointer<NiD3DPass>& pass = *(NiPointer<NiD3DPass>*)(pThis + 0x168);
    if (!pass.m_pObject)
        NiD3DPass::CreateD3DPass(pass);
    ConfigurePassRenderStates(pThis);
    return true;
}

struct X
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00bc0f80, then if f has bit 1 set calls _delete on this with size 0x194, and returns this.
// @fnv 0x00bc1540
void* X::DestroyIfFlagged(unsigned int auiFlags)
{
    reinterpret_cast<::fnv_00bc0f80::FUN_00bc0f80 *>(this)->fnv_00bc0f80::FUN_00bc0f80::~FUN_00bc0f80();
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0x194);
    return this;
}

struct FUN_00bc1b90_shell
{
    char pad[0x178];
    int m_178;
    bool FUN_00bc1b90(int value);
};

// @fnv 0x00bc1b90
bool FUN_00bc1b90_shell::FUN_00bc1b90(int value)
{
    m_178 = value;
    return 1;
}

namespace fnv_00bc1210 {
class BeamStage;
struct OMRef
{
    virtual void V0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct OMRefPtr
{
    OMRef* m_pObject;
    OMRefPtr& operator=(OMRef* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
class D3DRenderStateGroup
{
  public:
    void SetRenderState(unsigned int, unsigned int, bool);
};
struct StageReturn
{
    char pad[0x60];
    unsigned int m_uiRefCount;
    static unsigned int OMDec(unsigned int& v)
    {
        --v;
        return v;
    }
    void DecRefCount()
    {
        if (OMDec(m_uiRefCount) == 0)
            reinterpret_cast<::FUN_00e7ecd0_cls *>(this)->FUN_00e7ecd0();
    }
};
class NiD3DPass
{
  public:
    char pad0[0x14];
    unsigned int m_uiStageMask;
    unsigned int m_uiNumberOfStages;
    char pad1c[0x14];
    D3DRenderStateGroup* m_pRenderStateGroup;
    char pad34[0x10];
    OMRefPtr m_spPixelShaderObject;
    char pad48[0x14];
    OMRefPtr m_spVertexShaderObject;
    char pad60[4];
    unsigned int m_uiRefCount;
    unsigned int GetStageCount() const
    {
        return m_uiNumberOfStages;
    }
    void IncRefCount()
    {
        ++m_uiRefCount;
    }
    void SetRenderState(unsigned int uiState, unsigned int uiValue)
    {
        if (!m_pRenderStateGroup)
            m_pRenderStateGroup = ((::fnv_00bc1210::D3DRenderStateGroup *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
        reinterpret_cast<::StateGroup *>((m_pRenderStateGroup))->SetNodeValue(uiState, uiValue, true);
    }
};
struct OMPassPtr
{
    NiD3DPass* m_pObject;
    OMPassPtr() : m_pObject(0)
    {}
    ~OMPassPtr()
    {
        if (--m_pObject->m_uiRefCount == 0)
            reinterpret_cast<::NiD3DPass *>((m_pObject))->DestroyPass();
    }
    OMPassPtr& operator=(const OMPassPtr& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject && --m_pObject->m_uiRefCount == 0)
                reinterpret_cast<::NiD3DPass *>((m_pObject))->DestroyPass();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiD3DPass* operator->() const
    {
        return m_pObject;
    }
};
struct OMStagePtr
{
    StageReturn* m_pObject;
    OMStagePtr() : m_pObject(0)
    {}
    ~OMStagePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    operator BeamStage*() const
    {
        return (BeamStage*)m_pObject;
    }
};
struct FUN_00bc1210_t
{
    void ConfigurePassRenderStates();
};
// Copies the pass from this+0x168, creates a stage if it has none, assigns two refs from this+0x18c/0x190, then sets a series of render states.
// @fnv 0x00bc1210
void FUN_00bc1210_t::ConfigurePassRenderStates()
{
    OMPassPtr spRenderPass;
    OMStagePtr spStage;
    spRenderPass = *(OMPassPtr*)((char*)this + 0x168);
    if (spRenderPass->GetStageCount() < 1)
    {
        ::AssignStageFromPool((::StageReturn *&)(spStage.m_pObject));
        ::ConfigureBeamStage((::BeamStage *)(::fnv_00bc1210::BeamStage *)(spStage), 0, 1, 2, true);
        reinterpret_cast<::StageSet *>(((spRenderPass).operator->()))->FUN_00e802b0(spRenderPass->m_uiStageMask, (::Stage321 *)(::fnv_00bc1210::BeamStage *)(spStage));
    }
    spRenderPass->m_spVertexShaderObject = *(OMRef**)((char*)this + 0x18c);
    spRenderPass->m_spPixelShaderObject = *(OMRef**)((char*)this + 0x190);
    spRenderPass->SetRenderState(0x16, 1);
    spRenderPass->SetRenderState(0xa8, 0xf);
    spRenderPass->SetRenderState(0x1b, 1);
    spRenderPass->SetRenderState(0x13, 5);
    spRenderPass->SetRenderState(0x14, 2);
    spRenderPass->SetRenderState(0xf, 0);
    spRenderPass->SetRenderState(0x34, 0);
    spRenderPass->SetRenderState(7, 1);
    spRenderPass->SetRenderState(0x17, 4);
    spRenderPass->SetRenderState(0xe, 0);
}
}  // namespace fnv_00bc1210

struct FUN_00bc1950_shell : public BoltShader
{
    void InitShaderConstantMaps();
};

struct BSFadeNode
{
};
struct NiD3DShaderConstantMap : BSFadeNode
{
    NiD3DShaderConstantMap(void*, int);
    virtual void Slot0();
    virtual void DeleteThis();
    virtual unsigned int AddEntry(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*,
                                  unsigned int, unsigned int, void*, bool);
    long m_lRefCount;
    char pad[0x3c];
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }
};
struct ConstMapPtr
{
    NiD3DShaderConstantMap* m_pObject;
    ConstMapPtr& operator=(NiD3DShaderConstantMap* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiD3DShaderConstantMap* operator->() const
    {
        return m_pObject;
    }
    bool operator==(const NiD3DShaderConstantMap* p) const
    {
        return m_pObject == p;
    }
};
extern unsigned int DAT_01201f50;

// Creates the vertex and pixel shader constant maps if missing and registers their entries, caching a bolt-data entry count in DAT_01201f50.
// @fnv 0x00bc1950
void FUN_00bc1950_shell::InitShaderConstantMaps()
{
    char* self = (char*)this;
    ConstMapPtr& spVS = *(ConstMapPtr*)(self + 0x34);
    ConstMapPtr& spPS = *(ConstMapPtr*)(self + 0x30);
    if (spVS == 0)
    {
        spVS = new NiD3DShaderConstantMap(*(void**)(self + 0x18), 0);
        spVS->AddEntry("WorldViewProjTranspose", 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
        spVS->AddEntry("fVars", 0x10000009, 0, 4, 4, "", 0x40, 4, self + 0x128, false);
        spVS->AddEntry("EyePosition", 0x10000007, 0, 8, 1, "", 0x10, 4, self + 0x118, false);
        if (DAT_01201f50 == 0)
            DAT_01201f50 = (::DAT_011f91c0 >= 2) ? 0xeb : 0x4b;
        spVS->AddEntry("bolt data", 0x10000009, 0, 0xe, DAT_01201f50, "", DAT_01201f50 * 16, 4, *(void**)(self + 0x70),
                       false);
    }
    if (spPS == 0)
    {
        spPS = new NiD3DShaderConstantMap(*(void**)(self + 0x18), 2);
        spPS->AddEntry("CoreColor", 0x10000007, 0, 0, 1, "", 0x10, 4, self + 0x16c, false);
        spPS->AddEntry("GlowColor", 0x10000007, 0, 1, 1, "", 0x10, 4, self + 0x17c, false);
    }
}

extern int DAT_01201f54;

struct Prop_bc18d0
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
    virtual void v39(void* pkClone);
    int unk[6];
    int m_iType1c;
};

struct Obj_bc18d0
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
    virtual void AttachChild55(Obj_bc18d0* pkChild, bool abFirstAvailableSlot);
};

Obj_bc18d0* __cdecl FUN_00bc15a0();

// Clones a node from FUN_00bc15a0, attaches it to pkNode, gets property type 3, and if its m_iType1c is 0xf increments DAT_01201f54 and calls v39 on it.
// @fnv 0x00bc18d0
Prop_bc18d0* __cdecl FUN_00bc18d0(Obj_bc18d0* pkNode)
{
    if (pkNode)
    {
        Obj_bc18d0* pkClone = ((::Obj_bc18d0 *)(reinterpret_cast<::CloneSourceA5d6 *>((FUN_00bc15a0()))->FUN_00a5d680()));
        pkNode->AttachChild55(pkClone, true);
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(pkClone), 0, 0);
        Prop_bc18d0* pkProp = ((::Prop_bc18d0 *)(reinterpret_cast<::FUN_00a59d30_C *>((pkClone))->FUN_00a59d30(3)));
        int bIsShaderType = 0;
        if (pkProp)
            bIsShaderType = (pkProp->m_iType1c == 0xf);
        Prop_bc18d0* pkShaderProp = bIsShaderType ? pkProp : 0;
        if (pkShaderProp)
        {
            FUN_00bc15a0();
            ++DAT_01201f54;
            pkShaderProp->v39(pkClone);
            return pkShaderProp;
        }
    }
    return 0;
}

struct Fn1470Result
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_1c;
};

struct Fn1470Item
{
};

struct Fn1470Ref
{
    virtual void v00();
    virtual void Destroy();
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_04) == 0)
            Destroy();
    }
    long m_04;
};

struct Fn1470Owner
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
    virtual void Slot3c(unsigned int index);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    Fn1470Item** m_a0;
    unsigned int unka4;
    unsigned short m_a8;
};

extern int DAT_01201f54;

// Calls Slot3c for each matching result; when the counter is nonpositive, releases and clears the global reference and resets the counter.
// @fnv 0x00bc1470
void __cdecl FUN_00bc1470(Fn1470Owner* pOwner, Fn1470Result* pWanted)
{
    if (pOwner == 0 || pWanted == 0)
    {
        return;
    }
    unsigned int i = 0;
    if (0 < pOwner->m_a8)
    {
        do
        {
            Fn1470Item* item = pOwner->m_a0[i];
            Fn1470Result* r;
            if (item != 0)
            {
                r = ((::Fn1470Result *)(reinterpret_cast<::FUN_00a59d30_C *>((item))->FUN_00a59d30(3)));
            }
            else
            {
                r = 0;
            }
            unsigned int bMatch;
            if (r == 0)
            {
                bMatch = 0;
            }
            else
            {
                bMatch = (r->m_1c == 0xf);
            }
            Fn1470Result* v = bMatch ? r : 0;
            if (v != 0 && v == pWanted)
            {
                pOwner->Slot3c(i);
            }
            i++;
        } while (i < pOwner->m_a8);
    }
    if (--DAT_01201f54 > 0)
    {
        return;
    }
    if ((*reinterpret_cast<::Fn1470Ref * *>(&::DAT_01201f58)) != 0)
    {
        (*reinterpret_cast<::Fn1470Ref * *>(&::DAT_01201f58))->DecRefCount();
        (*reinterpret_cast<::Fn1470Ref * *>(&::DAT_01201f58)) = 0;
    }
    DAT_01201f54 = 0;
}


struct MemoryManager
{
};

struct IndexU16
{
    unsigned short value;
};


class NiPoint3
{
  public:
    float x, y, z;
};

class FUN_00ba63e0 : public NiObject
{
  public:
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    FUN_00ba63e0(unsigned short, unsigned int);
};

struct NiBound
{
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
    NiBound(const NiBound& b)
    {
        *this = b;
    }
    void SetRadius(float radius)
    {
        m_fBoundRadius = radius;
    }
    void SetCenterAndRadius(const NiPoint3& c, float r)
    {
        m_kCenter = c;
        m_fBoundRadius = r;
    }
};

class FUN_00a7b630 : public NiObject
{
  public:
    int unk08;
    int unk0c;
    NiBound m_kBound;
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
    FUN_00a7b630(unsigned short, NiPoint3*, void*, void*, void*, void*, int, unsigned short, unsigned short*);
};

class NiAVObject : public NiObject
{
  public:
};

class FUN_00a74480 : public NiAVObject
{
  public:
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    FUN_00a7b630* m_spGeometryData;
    int unkbc;
    int unkc0;
    FUN_00a74480(FUN_00a7b630*);
    const NiBound& GetModelBound() const
    {
        return m_spGeometryData->m_kBound;
    }
    void SetModelBound(const NiBound& bound)
    {
        m_spGeometryData->m_kBound = bound;
    }
};

class NiProperty : public NiObject
{
  public:
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

class FUN_00bc1d40 : public NiProperty
{
  public:
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
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
    FUN_00bc1d40();
};

extern unsigned int DAT_01201f50;
struct Fn1470Ref;

// The file declares the cached shape as a raw pointer; it is used as a NiPointer here.
static inline NiPointer<FUN_00a74480>& CachedShape()
{
    return reinterpret_cast<NiPointer<FUN_00a74480>&>((*reinterpret_cast<::Fn1470Ref * *>(&::DAT_01201f58)));
}

inline unsigned int GetSegmentCount()
{
    if (!DAT_01201f50)
    {
        DAT_01201f50 = (DAT_011f91c0 < 2 ? 0 : 0xa0) + 0x4b;
    }
    return DAT_01201f50;
}

// Returns the cached object or creates one from repeated quad vertex and index data and stores it in the cache.
// @fnv 0x00bc15a0
Obj_bc18d0* FUN_00bc15a0()
{
    if (CachedShape())
        return (Obj_bc18d0*)(FUN_00a74480*)CachedShape();

    unsigned int uSegments = GetSegmentCount();
    if (!uSegments)
        return (Obj_bc18d0*)uSegments;

    unsigned int uTotal = DAT_011ae61c * uSegments;
    unsigned int usNumTriangles = (unsigned short)(uTotal + uTotal);
    unsigned int usNumVertices = (unsigned short)(uTotal * 4);

    NiPoint3* pVertices = new NiPoint3[(unsigned short)usNumVertices];
    unsigned short* pIndices = (unsigned short*)new IndexU16[(unsigned short)usNumTriangles * 3];

    if (uTotal > 0)
    {
        float z = 0.0f;
        NiPoint3 kP0 = {-1.0f, -1.0f, z};
        NiPoint3 kP1 = {1.0f, -1.0f, z};
        NiPoint3 kP2 = {1.0f, 1.0f, z};
        NiPoint3 kP3 = {-1.0f, 1.0f, z};

        for (unsigned int i = 0; i < uTotal; ++i)
        {
            unsigned int base = i * 4;
            NiPoint3* pV = pVertices + i * 4;
            unsigned short* pI = pIndices + i * 6;
            pV[0] = kP0;
            pV[1] = kP1;
            pV[2] = kP2;
            pV[3] = kP3;
            pI[0] = base;
            pI[1] = base + 1;
            pI[2] = base + 2;
            pI[3] = base + 3;
            pI[4] = base;
            pI[5] = base + 2;
        }
    }

    FUN_00a7b630* pkData = new FUN_00a7b630(usNumVertices, pVertices, 0, 0, 0, 0, 0, usNumTriangles, pIndices);

    FUN_00ba63e0* pkExt = new FUN_00ba63e0(usNumVertices, 1);
    reinterpret_cast<::FUN_00a72ca0_Class *>((pkExt))->FUN_00a72ca0(1);
    reinterpret_cast<::A72BB0_DataStreamOwner *>((pkExt))->FUN_00a72bb0(0, GetOrCreateTable(), (unsigned short)usNumVertices * 4, 1);
    reinterpret_cast<::FUN_00a726a0_cls *>((pkExt))->FUN_00a726a0(0, 0, 0, (void *)(1), usNumVertices, 4, 4);

    reinterpret_cast<::NiGPUProgramOwner *>((pkData))->SetProgram((::NiGPUProgram *)(pkExt));

    FUN_00a74480* pkShape = new FUN_00a74480(pkData);

    NiBound kBound = pkShape->GetModelBound();
    reinterpret_cast<::FUN_004a51d0_shell *>(&(pkShape->m_spGeometryData->m_kBound))->FUN_004a51d0((void *)&(kBound.m_kCenter), 2048.0f);

    reinterpret_cast<::FUN_00439410_cls *>((pkShape))->FUN_00439410((::ArgObject *)(::NiObject *)(new FUN_00bc1d40()));

    CachedShape() = pkShape;
    return (Obj_bc18d0*)(FUN_00a74480*)CachedShape();
}

#include "generated/data/bsshader/boltshader.inc"
