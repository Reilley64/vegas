#pragma once

struct IDirect3DIndexBuffer9Like;

class NiDX9IndexBufferManager {
public:
    // 0x00e8f520
    ::IDirect3DIndexBuffer9Like *ResizeTempLineConnectivityIB(unsigned int, const unsigned char *, unsigned int *, unsigned int, int);
};
