#pragma once

#include <cstddef>
#include <cstdint>

class Actor;
class TESForm;
class TESObjectREFR;

// Native save-game reader prefix. Its pointer has native width; stored save
// buffer extents remain the source format's unsigned 32-bit values.
class BGSLoadGameBuffer {
public:
    BGSLoadGameBuffer() noexcept;
    ~BGSLoadGameBuffer() noexcept;

    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();

    void SetBuffer(const void* buffer, std::size_t size, std::size_t position = 0) noexcept;
    // Existing 00848d50 ownership entry releases the installed buffer.
    void ResetReadPosition();
    const std::byte* GetCurrentBufferPointer() const noexcept;
    std::size_t RemainingBytes() const noexcept;
    bool TryReadRaw(void* destination, std::size_t size) noexcept;
    bool TryReadElementCount(std::uint32_t& count) noexcept;

protected:
    const std::byte* pBuffer;
    std::uint32_t iBufferSize;
    std::uint32_t m_uiReadOffset;
};
