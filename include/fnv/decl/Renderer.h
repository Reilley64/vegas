#pragma once

struct Class87d40;
class NiGeometryData;
struct VertexRecord;

class Renderer {
public:
    // 0x00452540
    static bool CanRender();
    // 0x00b7dd50
    void FUN_00b7dd50();
    // 0x00e8c1e0
    ::VertexRecord *FUN_00e8c1e0(::NiGeometryData *, ::Class87d40 *, unsigned int, ::VertexRecord *, char *);
};
