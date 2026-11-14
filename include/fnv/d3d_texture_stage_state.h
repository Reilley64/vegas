#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>

// Native state storage. Slot indices are already mapped by the caller.
class D3DTextureStageState
{
  public:
    enum class Group { first, second };
    struct StageCommand
    {
        unsigned int stage;
        unsigned int key;
        std::uintptr_t value;
    };
    struct SamplerCommand
    {
        unsigned int stage;
        unsigned int key;
        unsigned int value;
    };

    D3DTextureStageState() noexcept = default;
    void Reset() noexcept;
    bool SetStageValue(unsigned int slot, std::uintptr_t value, Group) noexcept;
    bool GetStageValue(unsigned int slot, std::uintptr_t& value, Group&) const noexcept;
    bool SetSamplerValue(unsigned int slot, unsigned int value, Group, bool flagged) noexcept;
    bool GetSamplerValue(unsigned int slot, unsigned int& value, Group&, bool& flagged) const noexcept;
    unsigned int StageCount(Group group) const noexcept;
    unsigned int SamplerCount(Group group) const noexcept;
    unsigned int FlaggedSamplerCount() const noexcept;
    // Produces the finite commands from e89250/e892d0 without invoking an ABI.
    std::size_t CollectStageCommands(unsigned int stage, const std::array<unsigned int, 8>& keys,
                                    std::span<StageCommand, 8> output) const noexcept;
    std::size_t CollectSamplerCommands(unsigned int stage, const std::array<unsigned int, 5>& keys,
                                      std::span<SamplerCommand, 5> output) const noexcept;

  private:
    template<class T> struct Slot
    {
        T value{};
        Group group = Group::first;
        bool enabled = false;
        bool flagged = false;
    };
    std::array<Slot<std::uintptr_t>, 8> m_stage{};
    std::array<Slot<unsigned int>, 5> m_sampler{};
};
