#include "fnv/d3d_texture_stage_state.h"
#include <cstdlib>
#include <limits>

static void Require(bool condition)
{
    if (!condition)
        std::abort();
}

int main()
{
    using State = D3DTextureStageState;
    using Group = State::Group;
    State state;
    const Group groups[] = {Group::first, Group::second};
    std::uintptr_t value = 99;
    Group group = Group::second;
    unsigned int sampler = 99;
    bool flagged = true;
    for (unsigned int slot = 0; slot < 8; ++slot)
        Require(!state.GetStageValue(slot, value, group));
    for (unsigned int slot = 0; slot < 5; ++slot)
        Require(!state.GetSamplerValue(slot, sampler, group, flagged));
    Require(value == 99 && sampler == 99 && flagged && group == Group::second);

    for (unsigned int slot = 0; slot < 8; ++slot)
    {
        for (Group selected : groups)
        {
            Require(state.SetStageValue(slot, slot + 1, selected));
            Require(state.GetStageValue(slot, value, group));
            Require(value == slot + 1 && group == selected);
            Require(state.StageCount(Group::first) + state.StageCount(Group::second) == slot + 1);
            Require(state.StageCount(Group::first) == (selected == Group::first ? 1u : 0u));
            Require(state.StageCount(Group::second) == slot + (selected == Group::second ? 1u : 0u));
            Require(state.SetStageValue(slot, slot + 1, selected));
            Require(state.StageCount(Group::first) + state.StageCount(Group::second) == slot + 1);
        }
    }
    // Every slot/group/flag combination replaces one value, never adds occupancy.
    for (unsigned int slot = 0; slot < 5; ++slot)
    {
        for (Group selected : groups)
            for (bool selectedFlag : {false, true})
            {
                Require(state.SetSamplerValue(slot, slot + 10, selected, selectedFlag));
                Require(state.GetSamplerValue(slot, sampler, group, flagged));
                Require(sampler == slot + 10 && group == selected && flagged == selectedFlag);
                Require(state.SamplerCount(Group::first) + state.SamplerCount(Group::second) == slot + 1);
                Require(state.FlaggedSamplerCount() == slot + (selectedFlag ? 1 : 0));
            }
    }
    for (unsigned int bad : {8u, std::numeric_limits<unsigned int>::max()})
    {
        Require(!state.SetStageValue(bad, 0, Group::first));
        Require(!state.GetStageValue(bad, value, group));
    }
    for (unsigned int bad : {5u, std::numeric_limits<unsigned int>::max()})
    {
        Require(!state.SetSamplerValue(bad, 0, Group::first, false));
        Require(!state.GetSamplerValue(bad, sampler, group, flagged));
    }
    Require(state.StageCount(Group::first) + state.StageCount(Group::second) == 8);
    Require(state.SamplerCount(Group::first) + state.SamplerCount(Group::second) == 5);
    Require(state.FlaggedSamplerCount() == 5);

    const std::array<unsigned int, 8> stageKeys{8, 7, 6, 5, 4, 3, 2, 1};
    const std::array<unsigned int, 5> samplerKeys{15, 14, 13, 12, 11};
    std::array<State::StageCommand, 8> stageCommands{};
    std::array<State::SamplerCommand, 5> samplerCommands{};
    Require(state.CollectStageCommands(3, stageKeys, stageCommands) == 8);
    Require(state.CollectSamplerCommands(4, samplerKeys, samplerCommands) == 5);
    for (unsigned int slot = 0; slot < 8; ++slot)
        Require(stageCommands[slot].stage == 3 && stageCommands[slot].key == stageKeys[slot] &&
                stageCommands[slot].value == slot + 1);
    for (unsigned int slot = 0; slot < 5; ++slot)
        Require(samplerCommands[slot].stage == 4 && samplerCommands[slot].key == samplerKeys[slot] &&
                samplerCommands[slot].value == slot + 10);

    state.Reset();
    state.Reset();
    Require(state.StageCount(Group::first) == 0 && state.StageCount(Group::second) == 0);
    Require(state.SamplerCount(Group::first) == 0 && state.SamplerCount(Group::second) == 0);
    Require(state.FlaggedSamplerCount() == 0);
    Require(state.CollectStageCommands(3, stageKeys, stageCommands) == 0);
    Require(state.CollectSamplerCommands(4, samplerKeys, samplerCommands) == 0);
    for (unsigned int slot = 0; slot < 8; ++slot)
        Require(!state.GetStageValue(slot, value, group));
    for (unsigned int slot = 0; slot < 5; ++slot)
        Require(!state.GetSamplerValue(slot, sampler, group, flagged));
    // Dispatch a sparse zero value and a pointer-width value without truncation.
    Require(state.SetStageValue(7, std::numeric_limits<std::uintptr_t>::max(), Group::first));
    Require(state.SetStageValue(2, 0, Group::second));
    Require(state.CollectStageCommands(9, stageKeys, stageCommands) == 2);
    Require(stageCommands[0].key == stageKeys[2] && stageCommands[0].value == 0);
    Require(stageCommands[1].key == stageKeys[7] &&
            stageCommands[1].value == std::numeric_limits<std::uintptr_t>::max());
    Require(state.SetSamplerValue(4, 0, Group::first, false));
    Require(state.CollectSamplerCommands(9, samplerKeys, samplerCommands) == 1);
    Require(samplerCommands[0].key == samplerKeys[4] && samplerCommands[0].value == 0);
}
