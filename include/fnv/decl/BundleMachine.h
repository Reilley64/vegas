#pragma once

class ShapeContainer;
class Vec4Comp;
struct RayBundleInput;
struct RayBundleOutput;
struct TreeCode;

class BundleMachine {
public:
    // 0x00dd4870
    ::Vec4Comp FUN_00dd4870(const ::ShapeContainer *, const ::TreeCode *, const ::RayBundleInput &, ::RayBundleOutput &, const ::Vec4Comp &);
};
