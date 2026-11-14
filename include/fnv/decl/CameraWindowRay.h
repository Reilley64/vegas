#pragma once

struct NiPoint3;
class NiRenderTargetGroup;

struct CameraWindowRay {
public:
    // 0x00a71080
    bool MapScreenToRay(long, long, ::NiPoint3 &, ::NiPoint3 &, const ::NiRenderTargetGroup *);
};
