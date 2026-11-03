#pragma once

class hkBoolR;
class hkpCdBody;
class hkpRayHitCollector;
struct ShapeRayCastQuery;

class SampledHeightRayCastView {
public:
    // 0x00d24b50
    void FUN_00d24b50(const ::ShapeRayCastQuery &, const ::hkpCdBody &, ::hkBoolR, float, ::hkpRayHitCollector &) const;
};
