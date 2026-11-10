
// src/staging/blk_00be0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include <windows.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/D3DRenderStateGroup.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00e7ecd0_cls.h"
#include "fnv/decl/StageSet.h"
#include "fnv/decl/StateGroup.h"
#include "fnv/decl/fnv_00be0f10__ShaderDerived.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_00e7e000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_011fb000.h"
#include "fnv/symbols_011fc000.h"
#include "fnv/symbols_011fd000.h"
#include "fnv/symbols_011fe000.h"
#include "../../include/layout_support.h"

class NiD3DPass
{
  public:
    static void __cdecl CreateD3DPass(NiPointer<NiD3DPass>&);
public:
    void DestroyPass();
};
// @fnv 0x00be08e0
bool FUN_00be08e0(char* self, int)
{
    NiD3DPass::CreateD3DPass(*(NiPointer<NiD3DPass>*)(self + 0x5c));
    return true;
}

class SubTarget
{
  public:
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
    virtual int v39(void* pObj);
};

class SubOwner
{
  public:
};

// @fnv 0x00be08c0
int DispatchSubTarget(SubOwner* self)
{
    SubTarget* sub = ((::SubTarget *)(reinterpret_cast<::FUN_00a59d30_C *>((self))->FUN_00a59d30(3)));
    return sub->v39(self);
}

struct PassBase
{
    virtual void OnRelease();
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
    PassBase(void* owner, unsigned int mode);
};

struct FUN_00be08f0 : PassBase
{
    unsigned int unk2c;
    FUN_00be08f0(void* owner);
    virtual void OnRelease();
};

// Constructs a PassBase-derived object in mode 2 and initialises its extra field to zero.
// @fnv 0x00be08f0
FUN_00be08f0::FUN_00be08f0(void* owner) : PassBase(owner, 2), unk2c(0)
{}


struct FNVNiD3DPassStandIn
{
    void* FUN_00be2290(unsigned int flags);
};

// Calls FUN_00be0f10, then if bit 0 of flags is set calls FUN_00aa1460 on this with size 0x6c, and returns this.
// @fnv 0x00be2290
void* FNVNiD3DPassStandIn::FUN_00be2290(unsigned int flags)
{
    reinterpret_cast<::fnv_00be0f10::ShaderDerived *>(this)->fnv_00be0f10::ShaderDerived::~ShaderDerived();

    if (flags & 1)
        FUN_00aa1460(this, 0x6c);

    return this;
}

struct RefObject
{
    virtual void slot0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};
struct ShaderRefPointer
{
    RefObject* object;
    __forceinline void operator=(RefObject* value)
    {
        RefObject* old = object;
        if (old != value)
        {
            if (old && InterlockedDecrement(&old->m_iObjectReferenceCount) == 0)
                old->DeleteThis();
            object = value;
            if (value)
                InterlockedIncrement(&value->m_iObjectReferenceCount);
        }
    }
};
struct RenderStateBlock
{
};
struct ShaderStage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
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
    int references;
    __forceinline void Release()
    {
        --references;
        if (references == 0)
            reinterpret_cast<::FUN_00e7ecd0_cls *>(this)->FUN_00e7ecd0();
    }
};
struct ShaderStagePointer
{
    ShaderStage* object;
    ShaderStagePointer() : object(0)
    {}
    ~ShaderStagePointer()
    {
        if (object)
            object->Release();
    }
};
struct ShaderPass
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int stageCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    RenderStateBlock* state;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    ShaderRefPointer pixelShader;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ShaderRefPointer vertexShader;
    unsigned int unk60;
    int references;
    __forceinline unsigned int Count()
    {
        return stageCount;
    }
    __forceinline RenderStateBlock* GetState()
    {
        if (!state)
            state = ((::RenderStateBlock *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
        return state;
    }
};
struct ShaderPassPointer
{
    ShaderPass* object;
    ShaderPassPointer() : object(0)
    {}
    ~ShaderPassPointer()
    {
        if (object && --object->references == 0)
            reinterpret_cast<::NiD3DPass *>((object))->DestroyPass();
    }
    __forceinline void operator=(ShaderPass* const& value)
    {
        if (object != value)
        {
            if (object && --object->references == 0)
                reinterpret_cast<::NiD3DPass *>((object))->DestroyPass();
            object = value;
            if (object)
                ++object->references;
        }
    }
    __forceinline ShaderPass* operator->()
    {
        return object;
    }
};
extern RefObject* DAT_011fddec;
extern RefObject* DAT_011fddf0;
extern RefObject* DAT_011fddf4;
extern RefObject* DAT_011fddf8;
extern RefObject* DAT_011fddfc;
extern RefObject* DAT_011fdae8;
extern RefObject* DAT_011fdaec;
extern RefObject* DAT_011fdaf0;
extern RefObject* DAT_011fdaf4;
extern RefObject* DAT_011fdaf8;
extern RefObject* DAT_011fdafc;
// @fnv 0x00bea040
void InitDefaultShaderPasses()
{
    ShaderPassPointer pass;
    ShaderStagePointer stage;
    pass = (*reinterpret_cast<::ShaderPass * *>(&::fnv_00bfc860::DAT_011fe244));
    if (pass->Count() < 2)
    {
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 0, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 1, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
    }
    pass->vertexShader = DAT_011fddec;
    pass->pixelShader = DAT_011fdae8;
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(27, 0, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(15, 0, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(7, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(23, 4, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(14, 1, 1);
    DAT_011fcecc = 128;
    DAT_011fc2ec = 12;
    DAT_011fb70c = 128;
    DAT_011fab2c = 12;
    pass = (*reinterpret_cast<::ShaderPass * *>(&::fnv_00bfc860::DAT_011fe7c0));
    if (pass->Count() < 2)
    {
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 0, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 1, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
    }
    pass->vertexShader = DAT_011fddf0;
    pass->pixelShader = DAT_011fdaec;
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(27, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(19, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(20, 6, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(15, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(25, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(24, 0, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(7, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(23, 4, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(14, 0, 1);
    DAT_011fd448 = 128;
    DAT_011fc868 = 12;
    DAT_011fbc88 = 128;
    DAT_011fb0a8 = 4;
    pass = (*reinterpret_cast<::ShaderPass * *>(&::fnv_00bfc860::DAT_011fe7bc));
    if (pass->Count() < 2)
    {
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 0, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 1, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
    }
    pass->vertexShader = DAT_011fddf4;
    pass->pixelShader = DAT_011fdaf0;
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(19, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(20, 2, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(15, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(25, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(24, 0, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(7, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(23, 4, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(14, 0, 1);
    DAT_011fd444 = 0;
    DAT_011fc864 = 8;
    pass = (*reinterpret_cast<::ShaderPass * *>(&::fnv_00bfc860::DAT_011fe7c8));
    if (pass->Count() < 2)
    {
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 0, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 1, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
    }
    pass->vertexShader = DAT_011fddf4;
    pass->pixelShader = DAT_011fdaf4;
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(27, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(19, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(20, 2, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(15, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(25, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(24, 0, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(7, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(23, 4, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(14, 0, 1);
    DAT_011fd450 = 0;
    DAT_011fc870 = 8;
    pass = (*reinterpret_cast<::ShaderPass * *>(&::fnv_00bfc860::DAT_011fe7b4));
    if (pass->Count() < 2)
    {
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 0, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 1, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
    }
    pass->vertexShader = DAT_011fddf8;
    pass->pixelShader = DAT_011fdaf8;
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(19, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(20, 2, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(15, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(25, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(24, 0, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(7, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(23, 4, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(14, 0, 1);
    DAT_011fb70c = 128;
    DAT_011fd43c = 128;
    DAT_011fc85c = 8;
    pass = (*reinterpret_cast<::ShaderPass * *>(&::fnv_00bfc860::DAT_011fe7cc));
    if (pass->Count() < 2)
    {
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 0, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
        ::AssignStageFromPool((*(::StageReturn * *)(&stage)));
        ::ConfigureBeamStage((::BeamStage *)(stage.object), 1, 1, 2, true);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(stage.object));
    }
    pass->vertexShader = DAT_011fddfc;
    pass->pixelShader = DAT_011fdafc;
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(27, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(19, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(20, 2, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(15, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(25, 5, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(24, 0, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(7, 1, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(23, 4, 1);
    reinterpret_cast<::StateGroup *>((pass->GetState()))->SetNodeValue(14, 0, 1);
    DAT_011fd454 = 128;
    DAT_011fc874 = 8;
}

namespace fnv_00beb830 {
struct RenderObject
{
    virtual void Unused();
    virtual void DeleteThis();
    volatile long references;
    void IncRefCount()
    {
        InterlockedIncrement(&references);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&references))
            DeleteThis();
    }
};
struct RenderState
{
};
struct StageReturn
{
    unsigned int unk00;
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
    unsigned int references;
    void IncRefCount()
    {
        ++references;
    }
    void DecRefCount()
    {
        if (--references == 0)
            reinterpret_cast<::FUN_00e7ecd0_cls *>(this)->FUN_00e7ecd0();
    }
};
struct ShaderPassEntry
{
    unsigned int unk00;
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
    RenderState* unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    NiPointer<RenderObject> unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    NiPointer<RenderObject> unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int GetStageCount() const
    {
        return unk18;
    }
    void IncRefCount()
    {
        ++unk64;
    }
    void DecRefCount()
    {
        if (--unk64 == 0)
            reinterpret_cast<::NiD3DPass *>(this)->DestroyPass();
    }
};
extern NiPointer<ShaderPassEntry> DAT_011fe010;
extern NiPointer<ShaderPassEntry> DAT_011fe014;
extern NiPointer<ShaderPassEntry> DAT_011fe018;
extern RenderObject* DAT_011fdb04;
extern unsigned int DAT_011fcc98, DAT_011fcc9c, DAT_011fcca0;
extern unsigned int DAT_011fc0b8, DAT_011fc0bc, DAT_011fc0c0;
// @fnv 0x00beb830
void __cdecl FUN_00beb830()
{
    NiPointer<ShaderPassEntry> pass;
    NiPointer<StageReturn> stage;
    pass = DAT_011fe010;
    if (pass->GetStageCount() < 1)
    {
        ::AssignStageFromPool((::StageReturn *&)(stage.m_pObject));
        ::ConfigureBeamStage((::BeamStage *)(::fnv_00beb830::StageReturn *)(stage), 0, 1, 2, 1);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(::fnv_00beb830::StageReturn *)(stage));
    }
    pass->unk5c = (*reinterpret_cast<::fnv_00beb830::RenderObject * *>(&::fnv_00b79de0::DAT_011fdd88));
    pass->unk44 = DAT_011fdb04;
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(27, 0, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(15, 0, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(7, 1, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(23, 4, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(14, 1, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(168, 3, 1);
    DAT_011fcc98 = 0;
    DAT_011fc0b8 = 4;
    pass = DAT_011fe014;
    if (pass->GetStageCount() < 1)
    {
        ::AssignStageFromPool((::StageReturn *&)(stage.m_pObject));
        ::ConfigureBeamStage((::BeamStage *)(::fnv_00beb830::StageReturn *)(stage), 0, 1, 2, 1);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(::fnv_00beb830::StageReturn *)(stage));
    }
    pass->unk5c = (*reinterpret_cast<::fnv_00beb830::RenderObject * *>(&::fnv_00b79de0::DAT_011fdd88));
    pass->unk44 = DAT_011fdb04;
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(27, 0, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(15, 1, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(7, 1, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(23, 4, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(14, 1, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(168, 3, 1);
    DAT_011fcc9c = 0;
    DAT_011fc0bc = 4;
    pass = DAT_011fe018;
    if (pass->GetStageCount() < 1)
    {
        ::AssignStageFromPool((::StageReturn *&)(stage.m_pObject));
        ::ConfigureBeamStage((::BeamStage *)(::fnv_00beb830::StageReturn *)(stage), 0, 1, 2, 1);
        reinterpret_cast<::StageSet *>(((pass).operator->()))->FUN_00e802b0(pass->unk14, (::Stage321 *)(::fnv_00beb830::StageReturn *)(stage));
    }
    pass->unk5c = (*reinterpret_cast<::fnv_00beb830::RenderObject * *>(&::DAT_011fde04));
    pass->unk44 = DAT_011fdb04;
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(27, 0, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(15, 0, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(7, 1, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(23, 4, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(14, 1, 1);
    if (!pass->unk30)
        pass->unk30 = ((::fnv_00beb830::RenderState *)(::D3DRenderStateGroup::GetCurrentRenderStateGroup()));
    reinterpret_cast<::StateGroup *>((pass->unk30))->SetNodeValue(168, 3, 1);
    DAT_011fcca0 = 2048;
    DAT_011fc0c0 = 4;
}
}  // namespace fnv_00beb830

struct C0
{
    char pad00[0x2c];
    int unk2c;
    int FUN_00be0b10();
};

// @fnv 0x00be0b10
int C0::FUN_00be0b10()
{
    return unk2c;
}

#include "generated/data/staging/blk_00be0000_o2.inc"
