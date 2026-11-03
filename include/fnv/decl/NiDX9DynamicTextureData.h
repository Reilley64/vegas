#pragma once

struct DynamicTextureStandIn;
struct NiPixelFormatStandIn;

struct NiDX9DynamicTextureData {
public:
    // 0x00e90340
    const ::NiPixelFormatStandIn *FUN_00e90340(::DynamicTextureStandIn *, bool);
};
