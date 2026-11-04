#pragma once

class NiTexture;
class ShadowSceneNode;

class FORenderedMenu {
public:
    // 0x0063d040
    void GetCurrentTimeMilliseconds();
    // 0x007fb150
    void StartBurst(float, float, float);
    // 0x007fc150
    void OnMenuOpen();
    // 0x007fc2b0
    void SetDefaultTexture(::NiTexture *);
    // 0x007fc400
    bool CreateMenuLight(const char *, ::ShadowSceneNode *);
};
