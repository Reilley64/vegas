#pragma once

#include "fnv/decl/FUN_0044a4c0.h"

// Native exception base identified by the shared throw/type information owner.
class FUN_00ec78e0 {
public:
    FUN_00ec78e0() noexcept;
    virtual ~FUN_00ec78e0() noexcept;

private:
    int state04_ = 0;
    int state08_ = 0;
};

// Complete error-message owner used by the SpeedTree parser callers.
struct FUN_00b096a0 : FUN_00ec78e0 {
    FUN_0044a4c0 message;

    explicit FUN_00b096a0(const FUN_0044a4c0& text);
    ~FUN_00b096a0() noexcept override;

    const char* what() const noexcept { return message.c_str(); }
};
