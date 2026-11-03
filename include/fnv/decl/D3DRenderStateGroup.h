#pragma once

struct D3DRenderStateGroup {
public:
    // 0x00e7f5d0
    static ::D3DRenderStateGroup *GetCurrentRenderStateGroup();
    // 0x00e7f6b0
    static void ReleaseRenderStateGroup(::D3DRenderStateGroup *);
};
