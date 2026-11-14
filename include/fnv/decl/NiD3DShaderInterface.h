#pragma once

class GraphicsRenderer;

class NiD3DShaderInterface {
public:
    // 0x00e818d0
    void SetShaderObject(::GraphicsRenderer *);
    // 0x00e81940
    static unsigned int InitializeShaderRenderer(::GraphicsRenderer *);
    // 0x00e81a90
    bool Initialize();
};
