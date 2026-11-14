#pragma once

struct DDA7C0Geometry;

struct DDA7C0OStream {
public:
    // 0x00dda7c0
    void WriteGeometry(const ::DDA7C0Geometry &);
};
