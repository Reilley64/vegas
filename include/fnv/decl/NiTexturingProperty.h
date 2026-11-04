#pragma once

class NiFixedString;
template <class> class NiPointer;

class NiTexturingProperty {
public:
    // 0x00a6b410
    static void InitializePoint3();
    // 0x011f49ac
    static ::NiPointer< ::NiTexturingProperty> ms_pDefaultProperty;
    // 0x011f49b0
    static NiFixedString ms_kTextureMapNames[10];
};
