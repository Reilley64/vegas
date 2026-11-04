#pragma once

namespace ShaderDraw { struct Bound; }
namespace ShaderDraw { struct Geometry; }
namespace ShaderDraw { struct PassInfo; }

namespace ShaderDraw {
struct Shader {
public:
    // 0x00bb1f60
    void FUN_00bb1f60(::ShaderDraw::Geometry *, int, int, ::ShaderDraw::PassInfo *, int, int, ::ShaderDraw::Bound *);
};
}
