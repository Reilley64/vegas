#pragma once

#include <cstddef>
#include <cstdint>
#include <mutex>

class NiGlobalStringTable {
public:
    NiGlobalStringTable() noexcept = default;
    NiGlobalStringTable(const NiGlobalStringTable&) = delete;
    NiGlobalStringTable& operator=(const NiGlobalStringTable&) = delete;

    // 0x004f31b0: retained source entry.
    void AddString() noexcept;

    // 0x00a5b690 and the shared handle lifecycle.
    static char* AddString(const char* text) noexcept;
    static bool Retain(const char* handle) noexcept;
    static bool Release(const char* handle) noexcept;
    static bool Initialize() noexcept;
    static bool Shutdown() noexcept;
    static char* EmptyString() noexcept;

    static const void* Identity() noexcept;
    static const void* NodeIdentity(const char* handle) noexcept;
    static bool Owns(const char* handle) noexcept;
    static std::uint32_t RefCount(const char* handle) noexcept;
    static std::uint32_t Length(const char* handle) noexcept;
    static std::size_t LiveNodeCount() noexcept;

private:
    struct Node;
    static constexpr std::size_t BucketCount = 0x201;

    Node* FindLocked(const char* text, std::uint32_t length, std::size_t bucket) noexcept;
    Node** FindHandleLinkLocked(const char* handle) noexcept;

    std::mutex lock_{};
    Node* buckets_[BucketCount]{};
    std::size_t liveNodeCount_ = 0;
    bool initialized_ = false;
    unsigned int m_uiLockCount = 0;
};

// Source startup/shutdown entries for the one table owner.
void FUN_00a5b630();
bool ShutdownGlobalStringTable() noexcept;
