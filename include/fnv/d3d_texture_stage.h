#pragma once

#include "fnv/d3d_texture_stage_state.h"
#include <cstddef>

class NiTexture;
class D3DTextureStagePool;

// Owns a shader global-constant reference and its interned name, not the
// legacy StringRefHolder object. The shader factory must outlive this owner.
class D3DStageTransformConstant
{
  public:
    D3DStageTransformConstant() noexcept = default;
    ~D3DStageTransformConstant() noexcept;
    bool Acquire(const char* name, unsigned int type, unsigned int bytes,
                 const void* data) noexcept;
    void Reset() noexcept;
    const char* GetName() const noexcept { return m_name; }
    D3DStageTransformConstant(const D3DStageTransformConstant&) = delete;
    D3DStageTransformConstant& operator=(const D3DStageTransformConstant&) = delete;

  private:
    char* m_name = nullptr;
};

// Complete native owner. No original-release binary layout is implied.
// Texture is borrowed. State and transform constant are owned by value.
class BeamStage
{
  public:
    explicit BeamStage(NiTexture* borrowedTexture = nullptr) noexcept;
    ~BeamStage() noexcept;
    unsigned int GetStageIndex() const noexcept { return stageIndex; }
    void SetStageIndex(unsigned int index) noexcept { stageIndex = index; }
    NiTexture* GetTexture() const noexcept { return texture; }
    void SetTexture(NiTexture* borrowedTexture) noexcept { texture = borrowedTexture; }
    void IncRefCount() noexcept;
    void DecRefCount() noexcept;
    void Reset() noexcept;

    void ApplyPairToState(unsigned int);
    void SetClampMode(int);
    bool ApplyRenderStateChanges(bool);
    void ApplyState();
    void SendDeviceCommands(bool);
    void BindTexture();

    int clampMode = 0;
    unsigned int stageIndex = 0;
    NiTexture* texture = nullptr;
    unsigned int mode = 0;
    D3DTextureStageState state;
    unsigned int textureTransformFlags = 0;
    D3DStageTransformConstant textureTransform;
    float transform[16]{};
    unsigned short transformFlags = 0;
    bool transformEnabled = false;

    static void* operator new(std::size_t);
    static void operator delete(void*) noexcept;
    enum class ArrayDomain { engine, ni };
    static void* operator new[](std::size_t);
    static void* operator new[](std::size_t, ArrayDomain);
    static void operator delete[](void*) noexcept;
    static void operator delete[](void*, ArrayDomain) noexcept;
    BeamStage(const BeamStage&) = delete;
    BeamStage& operator=(const BeamStage&) = delete;

  private:
    friend class D3DTextureStagePool;
    D3DTextureStagePool* m_poolOrigin = nullptr;
    unsigned int m_refCount = 0;
    bool m_checkedOut = false;
};

BeamStage* CreateD3DTextureStages(unsigned int count);

struct D3DTextureStageBlock
{
    explicit D3DTextureStageBlock(unsigned int count);
    ~D3DTextureStageBlock() noexcept;
    BeamStage* GetAt(unsigned int index) noexcept;
    BeamStage* items;
    unsigned int count;
    D3DTextureStageBlock* next = nullptr;
    static void* operator new(std::size_t);
    static void operator delete(void*) noexcept;
    D3DTextureStageBlock(const D3DTextureStageBlock&) = delete;
    D3DTextureStageBlock& operator=(const D3DTextureStageBlock&) = delete;
};

// Externally serialized. Acquire transfers one reference. Ref-zero returns to
// this exact pool; Shutdown refuses while any stage is checked out.
class D3DTextureStagePool
{
  public:
    D3DTextureStagePool() noexcept = default;
    ~D3DTextureStagePool() noexcept;
    BeamStage* Acquire();
    bool Shutdown() noexcept;
    unsigned int Available() const noexcept { return m_available; }
    unsigned int Total() const noexcept { return m_total; }
    static void* operator new(std::size_t);
    static void operator delete(void*) noexcept;
    D3DTextureStagePool(const D3DTextureStagePool&) = delete;
    D3DTextureStagePool& operator=(const D3DTextureStagePool&) = delete;

  private:
    friend class BeamStage;
    void Return(BeamStage*) noexcept;
    void Grow();
    BeamStage** m_entries = nullptr;
    D3DTextureStageBlock* m_blocks = nullptr;
    unsigned int m_available = 0;
    unsigned int m_total = 0;
    unsigned int m_growth = 8;
};
