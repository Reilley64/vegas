#pragma once

namespace CameraPass { struct Input; }

namespace CameraPass {
struct Camera {
public:
    // 0x004a04c0
    void UpdateCamera(::CameraPass::Input *);
};
}
