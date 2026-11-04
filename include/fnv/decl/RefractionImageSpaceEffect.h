#pragma once

class BSRenderedTexture;

class RefractionImageSpaceEffect {
public:
    // 0x00bd9380
    ::BSRenderedTexture *GetRefractionTexture(bool);
    // 0x00bd93d0
    RefractionImageSpaceEffect();
};
