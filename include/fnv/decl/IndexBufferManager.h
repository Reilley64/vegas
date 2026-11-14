#pragma once

class COMBaseInterface;

class IndexBufferManager {
public:
    // 0x00e8f200
    ::COMBaseInterface *PackBuffer(const unsigned short *, unsigned int, unsigned int, ::COMBaseInterface *, unsigned int &, unsigned long, unsigned int);
};
