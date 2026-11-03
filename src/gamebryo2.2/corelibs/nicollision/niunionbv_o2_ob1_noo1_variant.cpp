
// src/gamebryo2.2/corelibs/nicollision/niunionbv_o2_ob1_noo1_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Oy /GS /EHsc /Gy /O2 /Ob1 (unit src/gamebryo2.2/corelibs/nicollision/niunionbv.cpp lists /MT /O1 /Oy /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// MSVC 2008 cl does not accept the .inl extension as a source file, so this identical unit is compiled as .cpp by the matcher; the .inl is the source of record.
//
//
// gamebryo2.2/corelibs/nicollision/niunionbv.inl
//
// Inline definitions for NiD3DShaderProgram: Nivid3D shader program
// wrappers over D3D9 GPU programs. A program object owns the compiled
// code block and the creator/device handles that produced it; the
// accessors below read out the stored descriptors.
//
// Standalone build: base chain sizes taken from the MSVC 2008 layout
// evidence - NiGPUProgram is 12 bytes and NiD3DShaderProgram is 44
// bytes, with m_uiProgramCodeSize at offset 20.
//
#include <new>
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/S00e9e860_Obj.h"
#include "fnv/decl/fnv_00e9edd0__NiShaderArrayOwner.h"
#include "fnv/symbols_011f6000.h"
typedef unsigned int NiUInt32;
class NiMemObject
{
};
class NiRefObject : public NiMemObject
{
  public:
    NiRefObject() : m_uiRefCount(0)
    {}

    virtual ~NiRefObject()
    {}

    virtual void DeleteThis()
    {
        delete this;
    }

  protected:
    NiUInt32 m_uiRefCount;
};
class NiGPUProgram : public NiRefObject
{
  public:
    enum ProgramType
    {
        PROGRAMTYPE_INVALID,
        PROGRAMTYPE_VERTEX,
        PROGRAMTYPE_PIXEL
    };

    ProgramType GetProgramType()
    {
        return m_iProgramType;
    }

  protected:
    ProgramType m_iProgramType;
};
class NiD3DShaderProgramCreator;
class Direct3DDeviceInterface;
class NiD3DRenderer;
class NiD3DRenderState;
class NiD3DShaderProgram : public NiGPUProgram
{
  public:
    NiUInt32 GetCodeSize() const;

  protected:
    char* m_pcProgramName;
    char* m_pcProfile;
    NiUInt32 m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    NiD3DRenderer* m_pShaderObject;
    NiD3DRenderState* m_pRenderState;
};
struct P03MM
{
};
typedef P03MM MemoryManager;
struct S
{
    S* FUN_00e9ee60(void*);
};
S* __fastcall FUN_00e9efb0(void* self);
// FUN_00e9ecc0 - 6-byte leaf stub of the retail binary.
//
// The original code is "mov eax, 4 ; ret": the function simply hands the
// constant 4 back to its caller.  A plain "return 4;" is folded by VC9 at the
// pack's /O1 into the shorter "push 4 ; pop eax ; ret" sequence, so the value
// is materialised from a relocated address expression instead.  That keeps
// the original six-byte "mov eax, <imm32> ; ret" shape byte for byte.
extern int g_fnv_00e9ecc0_value_anchor;
int FUN_00e9ecc0();

class ImageSpaceTexture;
struct Item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual ImageSpaceTexture* GetTexture();
};
struct TextureVTable
{
    void* vf00;
    void* vf04;
    void* vf08;
    void* vf0C;
    void* vf10;
    void* vf14;
    void* vf18;
    void* vf1C;
    void(__thiscall* Attach)(ImageSpaceTexture*, Item*);
};
class ImageSpaceTexture
{
  public:
    TextureVTable* vtable;
};
struct Source
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int GetType();
    unsigned int unk04;
    Item** m_items;
    unsigned short unk0C;
    unsigned short m_uiItemCount;
};
struct TexArray
{
    void SetAt(unsigned int i, ImageSpaceTexture*& t);
};
struct TexCache
{
    void FUN_00e9ecd0(Source* src);
    unsigned int unk00;
    TexArray m_textures;
};
// @fnv 0x00e9ecd0
void TexCache::FUN_00e9ecd0(Source* src)
{
    if (src->GetType() == 4)
    {
        reinterpret_cast<::S00e9e860_Obj *>(this)->FUN_00e9e860();
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_textures))->FUN_00a90180(src->m_uiItemCount);
        for (unsigned int i = 0; i < src->m_uiItemCount; i++)
        {
            Item* item = src->m_items[i];
            ImageSpaceTexture* value = item->GetTexture();
            TextureVTable* table = value->vtable;
            ImageSpaceTexture* tex = value;
            table->Attach(value, item);
            reinterpret_cast<::FUN_00a41520_cls *>(&(m_textures))->FUN_00ba3aa0(i, (::KeyPair **)&(tex));
        }
    }
}

struct Element365
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual int vf06();
};

struct Array365
{
    int unk00;
    int* unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;


    __forceinline void SetAt(unsigned int idx, int e)
    {
        if (idx >= unk0a)
        {
            unk0a = (unsigned short)(idx + 1);
            if (e)
                ++unk0c;
        }
        else if (e)
        {
            if (!unk04[idx])
                ++unk0c;
        }
        else
        {
            if (unk04[idx])
                --unk0c;
        }
        unk04[idx] = e;
    }
};

struct State365
{
    int unk00;
    Array365 arr;

    unsigned int unk14;
};

struct Source365
{
    int unk00;
    int unk04;
    Element365** unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned short GetSize() const
    {
        return unk0e;
    }

    State365* __thiscall FUN_00e9eef0();
};

// @fnv 0x00e9eef0
State365* __thiscall Source365::FUN_00e9eef0()
{
    State365* state = static_cast<State365*>(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(sizeof(State365)));

    unsigned int i = 0;
    if (state)
        state = ((::State365 *)(new ((void *)(state)) ::fnv_00e9edd0::NiShaderArrayOwner()));

    else
        state = 0;
    reinterpret_cast<::FUN_00a41520_cls *>(&(state->arr))->FUN_00a90180(GetSize());
    for (; i < GetSize(); i++)
        state->arr.SetAt(i, unk08[i]->vf06());
    return state;
}
