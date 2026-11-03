#pragma once

template <class> class NiPointer;

class NiD3DPass {
public:
    // 0x00b80040
    void SetAlphaBlendMode(unsigned int, unsigned int, bool);
    // 0x00e7eb00
    bool ApplyRenderStateChanges(bool);
    // 0x00e7f0f0
    ::NiD3DPass *SetD3DDevice(unsigned int);
    // 0x00e80190
    void DestroyPass();
    // 0x00e804d0
    static void CreateD3DPass(::NiPointer< ::NiD3DPass> &);
};
