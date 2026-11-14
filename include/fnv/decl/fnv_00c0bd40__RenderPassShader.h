#pragma once

namespace fnv_00c0bd40 { struct RenderContext; }
namespace fnv_00c0bd40 { struct ShaderPassEntry; }

namespace fnv_00c0bd40 {
struct RenderPassShader {
public:
    // 0x00c0bd40
    ::fnv_00c0bd40::ShaderPassEntry *SetupPass(int, ::fnv_00c0bd40::RenderContext *);
};
}
