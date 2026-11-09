#pragma once

#include "fnv/decl/FUN_00b096a0.h"

class FUN_0044a500 {
public:
    explicit FUN_0044a500(void* value);

    void* unk00;
};

class FUN_0044a310 : public FUN_00ec78e0 {
public:
    FUN_0044a500 m_kMember;

    // 0x0044a310
    explicit FUN_0044a310(void* value);
    ~FUN_0044a310() noexcept override;
};
