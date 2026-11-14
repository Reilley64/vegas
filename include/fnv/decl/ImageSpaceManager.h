#pragma once

struct NiPoint2;
struct RgbaColor;
enum ImageSpaceManager__ImageSpaceEffectEnum;

struct ImageSpaceManager {
public:
    // 0x004e3270
    static ::ImageSpaceManager *FUN_004e3270();
    // 0x00b8b000
    void SetRadialBlurParameters(float, float, float, float, float, const ::NiPoint2 &);
    // 0x00b8b0d0
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    // 0x00b8b130
    void ApplyDepthOfFieldParamModifierWeather(float, unsigned int, float, float, float);
    // 0x00b8b390
    bool IsEffectActive(::ImageSpaceManager__ImageSpaceEffectEnum);
    // 0x00b8b3f0
    void PrepareEndOfFrameEffects();
    // 0x00b8b540
    void ApplyTintColorParamModifier(::RgbaColor &);
    // 0x00b8b5c0
    void ApplyTintColorParamModifierWeather(::RgbaColor &);
    // 0x00b8b610
    void SetFadeColorParamModifier(::RgbaColor &);
    // 0x00b8b690
    void ApplyFadeColorParamModifierWeather(::RgbaColor &);
    // 0x00b8b6e0
    void ApplyRadialBlurParamModifierWeather(float, float, float, float, float, const ::NiPoint2 &);
    // 0x00b8b9a0
    void BeginParamModifiers();
    // 0x00b8c170
    void CreateMenuBackgroundGeometry();
};
