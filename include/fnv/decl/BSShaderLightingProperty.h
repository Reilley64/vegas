#pragma once

class CloningProcess;
class ShadowSceneLight;

class BSShaderLightingProperty {
public:
    // 0x00b70490
    ::ShadowSceneLight *GetFirstAttachedLight(void *&);
    // 0x00b70590
    ::ShadowSceneLight *GetFirstActiveLight(void *&);
    // 0x00b71300
    void ClearLights();
    // 0x00b713c0
    void CopyMemberData(::BSShaderLightingProperty *, ::CloningProcess &);
};
