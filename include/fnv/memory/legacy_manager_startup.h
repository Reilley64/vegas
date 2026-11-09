#pragma once

#include <exception>

namespace fnv::memory {
// Full legacy startup cannot yet establish native pool/range/recovery and
// callback receivers. This is a failure, never a successful heap-only startup.
class MemoryManagerStartupUnavailable final : public std::exception {
public:
    const char* what() const noexcept override {
        return "MemoryManager full startup requires native pool and callback bindings";
    }
};
[[noreturn]] bool RequireJoinedMemoryManagerStartup();
}

// These are the original startup table and constructor, NOT a native owner or
// a layout view of MemoryManager. The admission check runs before any table
// supplier, callback, TLS write, or shell-to-owner connection can execute.
void* AllocateAA3880(unsigned int);
void CheckMemoryForLegacyStartup();
struct TableBaseAA3880 {
    TableBaseAA3880(unsigned int count);
    virtual ~TableBaseAA3880();
    unsigned int m_uiCount;
    void** m_ppvData;
    unsigned int m_uiAllocatedCapacity;
};
struct TableAA3880 : TableBaseAA3880 {
    TableAA3880();
    virtual ~TableAA3880();
};
struct FUN_00aa3880 {
    [[noreturn]] FUN_00aa3880();
    bool m_bShaderEnabled;
    char unk01;
    short m_sCount;
    short m_sIndex;
    short unk06;
    int m_iFlags;
    void* m_apSlots[66];
    TableAA3880 m_kTable;
    int m_iActive;
    bool m_bEnableState;
    bool m_bVisible;
    char unk12A;
    char unk12B;
    int m_iFirst;
    int m_iSecond;
    int m_iThird;
};
