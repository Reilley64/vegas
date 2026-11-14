#pragma once

struct NiFrustum;
struct NiStream;
struct NiUpdateData;
struct NiPoint3;

class NiCamera {
public:
    // 0x0045bbe0
    const ::NiFrustum &GetViewFrustum() const;
    // 0x0049da80
    int ClassifyPoint(const ::NiPoint3 *);
    // 0x006447f0
    float GetMaxFarNearRatio() const;
    // 0x00a6faf0
    void UpdateViewFrustum(const ::NiFrustum &);
    // 0x00a70b40
    void UpdateWorldBound();
    // 0x00a711b0
    void UpdateWorldData(::NiUpdateData &);
    // 0x00a711d0
    void LinkObject(::NiStream &);
};
