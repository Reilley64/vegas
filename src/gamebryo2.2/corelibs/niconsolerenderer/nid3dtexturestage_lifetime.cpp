#include "fnv/d3d_texture_stage.h"
#include "NiFixedString.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include <atomic>
#include <cstdint>
#include <exception>
#include <limits>
#include <memory>
#include <new>

namespace
{
enum class StageDomain { engine, niArray, niScalar };
struct alignas(BeamStage) StageAllocation
{
    void* originalBase;
    StageDomain domain;
    std::size_t nativeExtent;
    std::size_t alignment;
};

void* AllocateStages(std::size_t bytes, StageDomain domain)
{
    constexpr auto alignment = alignof(StageAllocation);
    constexpr auto overhead = sizeof(StageAllocation) + alignment - 1;
    constexpr auto limit = static_cast<std::size_t>((std::numeric_limits<int>::max)());
    if (bytes > limit - overhead)
        throw std::bad_array_new_length();
    const auto total = bytes + overhead;
    void* raw = domain == StageDomain::engine ? FUN_00401000(static_cast<unsigned int>(total)) :
        domain == StageDomain::niArray ? FUN_00aa1420(total) : FUN_00aa13e0(total);
    if (!raw)
        throw std::bad_alloc();
    void* aligned = static_cast<char*>(raw) + sizeof(StageAllocation);
    auto space = total - sizeof(StageAllocation);
    std::align(alignment, bytes, aligned, space);
    auto* allocation = reinterpret_cast<StageAllocation*>(aligned) - 1;
    ::new (allocation) StageAllocation{raw, domain, sizeof(BeamStage), alignof(BeamStage)};
    return aligned;
}

void ReleaseStages(void* compilerBase) noexcept
{
    if (!compilerBase)
        return;
    auto* allocation = static_cast<StageAllocation*>(compilerBase) - 1;
    void* original = allocation->originalBase;
    const auto extent = static_cast<unsigned int>(allocation->nativeExtent);
    if (allocation->domain == StageDomain::engine)
        FUN_00401030(original);
    else if (allocation->domain == StageDomain::niArray)
        FUN_00aa1490(original, extent);
    else
        FUN_00aa1460(original, extent);
}

void ChangeStringReference(char* name, int amount) noexcept
{
    // Existing global-string-table handle format (a5b690), not BeamStage layout.
    if (name && name != DAT_0109b220)
        std::atomic_ref<std::int32_t>(*reinterpret_cast<std::int32_t*>(name - 8))
            .fetch_add(amount, std::memory_order_relaxed);
}

void* AllocateEngine(std::size_t bytes)
{
    if (bytes > (std::numeric_limits<unsigned int>::max)())
        throw std::bad_array_new_length();
    void* raw = FUN_00401000(static_cast<unsigned int>(bytes));
    if (!raw)
        throw std::bad_alloc();
    return raw;
}
}

D3DStageTransformConstant::~D3DStageTransformConstant() noexcept { Reset(); }

bool D3DStageTransformConstant::Acquire(const char* name, unsigned int type,
                                      unsigned int bytes, const void* data) noexcept
{
    if (!name)
        return false;
    char* handle = NiGlobalStringTable::AddString(name);
    if (!handle)
        return false;
    NiFixedString key;
    key.m_kHandle = handle;
    if (!AcquireGlobalConstantEntry(&key, type, bytes, reinterpret_cast<std::uintptr_t>(data)))
    {
        ChangeStringReference(handle, -1);
        return false;
    }
    Reset();
    m_name = handle;
    return true;
}

void D3DStageTransformConstant::Reset() noexcept
{
    if (!m_name)
        return;
    NiFixedString temporary;
    temporary.m_kHandle = m_name;
    ChangeStringReference(m_name, 1);
    RemoveGlobalConstant(&temporary);
    ChangeStringReference(m_name, -1);
    ChangeStringReference(m_name, -1);
    m_name = nullptr;
}

BeamStage::BeamStage(NiTexture* borrowedTexture) noexcept : texture(borrowedTexture) {}
BeamStage::~BeamStage() noexcept { Reset(); }

void BeamStage::Reset() noexcept
{
    texture = nullptr;
    state.Reset();
    textureTransform.Reset();
    clampMode = 0;
    stageIndex = 0;
    mode = 0;
    textureTransformFlags = 0;
    transformFlags = 0;
    transformEnabled = false;
    // The old reset leaves transform data dormant. Native construction starts
    // it at zero; return preserves that payload while disabling its use.
}

void BeamStage::IncRefCount() noexcept
{
    if (m_refCount == (std::numeric_limits<unsigned int>::max)())
        std::terminate();
    ++m_refCount;
}

void BeamStage::DecRefCount() noexcept
{
    if (!m_refCount)
        std::terminate();
    if (--m_refCount)
        return;
    if (m_poolOrigin)
    {
        Reset();
        m_poolOrigin->Return(this);
    }
    else
        delete this;
}

void* BeamStage::operator new(std::size_t bytes) { return AllocateStages(bytes, StageDomain::niScalar); }
void BeamStage::operator delete(void* raw) noexcept { ReleaseStages(raw); }
void* BeamStage::operator new[](std::size_t bytes) { return AllocateStages(bytes, StageDomain::niArray); }
void* BeamStage::operator new[](std::size_t bytes, ArrayDomain domain)
{
    return AllocateStages(bytes, domain == ArrayDomain::engine ? StageDomain::engine : StageDomain::niArray);
}
void BeamStage::operator delete[](void* raw) noexcept { ReleaseStages(raw); }
void BeamStage::operator delete[](void* raw, ArrayDomain) noexcept { ReleaseStages(raw); }

BeamStage* CreateD3DTextureStages(unsigned int count)
{
    const auto domain = count ? BeamStage::ArrayDomain::ni : BeamStage::ArrayDomain::engine;
    return new(domain) BeamStage[count];
}

D3DTextureStageBlock::D3DTextureStageBlock(unsigned int size)
    : items(size ? CreateD3DTextureStages(size) : nullptr), count(size) {}
D3DTextureStageBlock::~D3DTextureStageBlock() noexcept { delete[] items; }
BeamStage* D3DTextureStageBlock::GetAt(unsigned int index) noexcept
{
    return index < count ? items + index : nullptr;
}
void* D3DTextureStageBlock::operator new(std::size_t bytes) { return AllocateEngine(bytes); }
void D3DTextureStageBlock::operator delete(void* raw) noexcept { FUN_00401030(raw); }
void* D3DTextureStagePool::operator new(std::size_t bytes) { return AllocateEngine(bytes); }
void D3DTextureStagePool::operator delete(void* raw) noexcept { FUN_00401030(raw); }

void D3DTextureStagePool::Grow()
{
    constexpr auto limit = static_cast<unsigned int>((std::numeric_limits<int>::max)());
    if (m_growth > limit - m_total || m_total + m_growth > limit / sizeof(BeamStage*))
        throw std::bad_array_new_length();
    const auto total = m_total + m_growth;
    auto** entries = static_cast<BeamStage**>(FUN_00aa1070(total * sizeof(BeamStage*)));
    if (!entries)
        throw std::bad_alloc();
    D3DTextureStageBlock* block;
    try { block = new D3DTextureStageBlock(m_growth); }
    catch (...)
    {
        FUN_00aa10f0(entries);
        throw;
    }
    for (unsigned int i = 0; i < m_available; ++i)
        entries[i] = m_entries[i];
    for (unsigned int i = 0; i < m_growth; ++i)
    {
        BeamStage* stage = block->GetAt(i);
        stage->m_poolOrigin = this;
        entries[m_available + i] = stage;
    }
    FUN_00aa10f0(m_entries);
    m_entries = entries;
    m_available += m_growth;
    m_total = total;
    if (m_growth <= limit / 2)
        m_growth *= 2;
    block->next = m_blocks;
    m_blocks = block;
}

BeamStage* D3DTextureStagePool::Acquire()
{
    if (!m_available)
        Grow();
    BeamStage* stage = m_entries[0];
    m_entries[0] = m_entries[--m_available];
    stage->m_checkedOut = true;
    stage->IncRefCount();
    return stage;
}

void D3DTextureStagePool::Return(BeamStage* stage) noexcept
{
    if (stage->m_poolOrigin != this || !stage->m_checkedOut || m_available == m_total)
        std::terminate();
    stage->m_checkedOut = false;
    m_entries[m_available++] = stage;
}

bool D3DTextureStagePool::Shutdown() noexcept
{
    if (m_available != m_total)
        return false;
    while (m_blocks)
    {
        auto* block = m_blocks;
        m_blocks = block->next;
        delete block;
    }
    FUN_00aa10f0(m_entries);
    m_entries = nullptr;
    m_available = m_total = 0;
    m_growth = 8;
    return true;
}

D3DTextureStagePool::~D3DTextureStagePool() noexcept
{
    if (!Shutdown())
        std::terminate();
}
