#pragma once

class BDD80Geometry;

class BDD80ShaderProperty {
public:
    // 0x00bddd80
    int AddRenderPass(::BDD80Geometry *, int, unsigned short *, unsigned char, bool *, bool, int, int, int, int, int, bool, int);
};
