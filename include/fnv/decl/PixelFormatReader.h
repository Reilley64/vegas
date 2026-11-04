#pragma once

struct PixelStream;

class PixelFormatReader {
public:
    // 0x00a7ced0
    void ReadFromStream(::PixelStream &);
};
