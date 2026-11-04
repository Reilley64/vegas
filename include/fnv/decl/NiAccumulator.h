#pragma once

class NiCamera;

class NiAccumulator {
public:
    // 0x00aa0fe0
    void ClearCamera();
    // 0x00d47a40
    void SetSortingCamera(const ::NiCamera *);
};
