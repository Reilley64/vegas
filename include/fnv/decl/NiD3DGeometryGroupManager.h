#pragma once

class Direct3DDeviceInterface;
class VertexDeclarationLayout;

class NiD3DGeometryGroupManager {
public:
    // 0x00e88c20
    void FUN_00e88c20(bool);
    // 0x00e88eb0
    static ::NiD3DGeometryGroupManager *Create(::Direct3DDeviceInterface *, ::VertexDeclarationLayout *);
};
