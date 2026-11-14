// bsshader/beamshader_pass.h: declares BeamTextureState, BeamStage, D3DRenderStateGroup, BeamRefPointer, NiD3DPass and more
#ifndef BEAMSHADER_PASS_H
#define BEAMSHADER_PASS_H

#include "fnv/decl/FUN_00e7ecd0_cls.h"
#include "fnv/decl/LightSlots.h"
#include "fnv/decl/StageSet.h"
#include "fnv/decl/StateGroup.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_00e7e000.h"
#include "NiRefObject.h"
class BeamTextureState
{
  public:
};
class BeamStage
{
  public:
    unsigned char pad0[0x10];
    BeamTextureState* state;
    unsigned char pad14[0x4c];
    unsigned int refs;
    void IncRefCount()
    {
        ++refs;
    }
    void DecRefCount()
    {
        if (--refs == 0)
            reinterpret_cast<::FUN_00e7ecd0_cls *>(this)->FUN_00e7ecd0();
    }
};
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int, unsigned int, bool);
};
class BeamRefPointer
{
  public:
    NiRefObject* object;
    void operator=(NiRefObject* p)
    {
        if (object != p)
        {
            if (object)
                object->DecRefCount();
            object = p;
            if (object)
                object->IncRefCount();
        }
    }
};
class NiD3DPass
{
  public:
    unsigned char pad0[0x14];
    unsigned int stages;
    unsigned int count;
    unsigned int GetStageCount() const
    {
        return count;
    }
    unsigned char pad1c[0x14];
    D3DRenderStateGroup* group;
    unsigned char pad34[0x10];
    BeamRefPointer pixel;
    unsigned char pad48[0x14];
    BeamRefPointer vertex;
    unsigned char pad60[4];
    unsigned int refs;
    void IncRefCount()
    {
        ++refs;
    }
    void DecRefCount()
    {
        if (--refs == 0)
            DestroyPass();
    }
    void DestroyPass();
    static void CreateD3DPass(NiPointer<NiD3DPass>&);
    void SetRenderState(unsigned int a, unsigned int b, bool c)
    {
        if (!group)
            group = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        reinterpret_cast<::StateGroup *>((group))->SetNodeValue(a, b, c);
    }
};
class BeamPassPointer
{
  public:
    NiD3DPass* object;
    BeamPassPointer() : object(0)
    {}
    ~BeamPassPointer()
    {
        if (object)
            object->DecRefCount();
    }
    void operator=(NiD3DPass* const& p)
    {
        if (object != p)
        {
            if (object)
                object->DecRefCount();
            object = p;
            if (object)
                object->IncRefCount();
        }
    }
};
class BeamStagePointer
{
  public:
    BeamStage* object;
    BeamStagePointer() : object(0)
    {}
    ~BeamStagePointer()
    {
        if (object)
            object->DecRefCount();
    }
};
class BeamPassShader
{
  public:
    unsigned char padding[0xb4];
    NiPointer<NiD3DPass> pass;
    NiRefObject* vertex;
    NiRefObject* pixel;
    void SetupPass();
    bool InitializePass();
};
#endif
