#pragma once

#include "fnv/decl/FUN_00b096a0.h"

// Non-owning pointer value used by this exception family. The source
// constructor only stores the supplied pointer and has no matching release
// edge. Copies therefore preserve the observed pointer, while destruction is
// deliberately a no-op. The pointee must outlive every exception copy.
class FUN_0044a310Pointer {
public:
    explicit FUN_0044a310Pointer(void* value) noexcept;
    FUN_0044a310Pointer(const FUN_0044a310Pointer&) noexcept = default;
    FUN_0044a310Pointer& operator=(const FUN_0044a310Pointer&) noexcept = default;
    ~FUN_0044a310Pointer() noexcept = default;

    void* get() const noexcept { return value_; }

private:
    void* value_;
};

class FUN_0044a310 : public FUN_00ec78e0 {
public:
    FUN_0044a310Pointer m_kMember;

    // 0x0044a310
    explicit FUN_0044a310(void* value);
    FUN_0044a310(const FUN_0044a310& other);
    FUN_0044a310& operator=(const FUN_0044a310&) = default;
    ~FUN_0044a310() noexcept override;
};
