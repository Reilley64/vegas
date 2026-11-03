#pragma once

struct GeomArray;
struct GeomNode;

struct GeomCollector {
public:
    // 0x00ca0f00
    void CollectShaderNodes(::GeomNode *, ::GeomArray *);
};
