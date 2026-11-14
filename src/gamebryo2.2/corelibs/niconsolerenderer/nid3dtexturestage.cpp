#include "fnv/d3d_texture_stage_state.h"

void D3DTextureStageState::Reset() noexcept
{
    m_stage = {};
    m_sampler = {};
}

bool D3DTextureStageState::SetStageValue(unsigned int slot, std::uintptr_t value, Group group) noexcept
{
    if (slot >= m_stage.size())
        return false;
    m_stage[slot] = {value, group, true, false};
    return true;
}

bool D3DTextureStageState::GetStageValue(unsigned int slot, std::uintptr_t& value, Group& group) const noexcept
{
    if (slot >= m_stage.size() || !m_stage[slot].enabled)
        return false;
    value = m_stage[slot].value;
    group = m_stage[slot].group;
    return true;
}

bool D3DTextureStageState::SetSamplerValue(unsigned int slot, unsigned int value, Group group,
                                         bool flagged) noexcept
{
    if (slot >= m_sampler.size())
        return false;
    m_sampler[slot] = {value, group, true, flagged};
    return true;
}

bool D3DTextureStageState::GetSamplerValue(unsigned int slot, unsigned int& value, Group& group,
                                         bool& flagged) const noexcept
{
    if (slot >= m_sampler.size() || !m_sampler[slot].enabled)
        return false;
    value = m_sampler[slot].value;
    group = m_sampler[slot].group;
    flagged = m_sampler[slot].flagged;
    return true;
}

unsigned int D3DTextureStageState::StageCount(Group group) const noexcept
{
    unsigned int count = 0;
    for (const auto& slot : m_stage)
        count += slot.enabled && slot.group == group;
    return count;
}

unsigned int D3DTextureStageState::SamplerCount(Group group) const noexcept
{
    unsigned int count = 0;
    for (const auto& slot : m_sampler)
        count += slot.enabled && slot.group == group;
    return count;
}

unsigned int D3DTextureStageState::FlaggedSamplerCount() const noexcept
{
    unsigned int count = 0;
    for (const auto& slot : m_sampler)
        count += slot.enabled && slot.flagged;
    return count;
}

std::size_t D3DTextureStageState::CollectStageCommands(unsigned int stage,
    const std::array<unsigned int, 8>& keys, std::span<StageCommand, 8> output) const noexcept
{
    std::size_t count = 0;
    for (std::size_t i = 0; i < m_stage.size(); ++i)
        if (m_stage[i].enabled)
            output[count++] = {stage, keys[i], m_stage[i].value};
    return count;
}

std::size_t D3DTextureStageState::CollectSamplerCommands(unsigned int stage,
    const std::array<unsigned int, 5>& keys, std::span<SamplerCommand, 5> output) const noexcept
{
    std::size_t count = 0;
    for (std::size_t i = 0; i < m_sampler.size(); ++i)
        if (m_sampler[i].enabled)
            output[count++] = {stage, keys[i], m_sampler[i].value};
    return count;
}
