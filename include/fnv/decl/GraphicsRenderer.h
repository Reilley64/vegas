#pragma once

class NiRenderTargetGroup;
enum _D3DFORMAT;

class GraphicsRenderer {
public:
    // 0x004dee10
    unsigned int GetRenderTargetWidth();
    // 0x004dee70
    unsigned int GetRenderTargetHeight();
    // 0x00a6fa30
    bool MapScreenCoordinates(unsigned int, unsigned int, float &, float &, ::NiRenderTargetGroup *);
    // 0x00b6b2a0
    bool BeginUsingRenderTargetGroup(::NiRenderTargetGroup *, unsigned int);
    // 0x00e76210
    static ::GraphicsRenderer *Create(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    // 0x00e7a9a0
    static const char *GetD3DFormatName(::_D3DFORMAT);
    // 0x00e8eeb0
    bool HasPendingPackets();
};
