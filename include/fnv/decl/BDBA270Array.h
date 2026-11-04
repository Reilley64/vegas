#pragma once

class BDBA270Allocator;
struct BDBA270Element;

class BDBA270Array {
public:
    // 0x00dba270
    void Splice(::BDBA270Allocator &, int, int, const ::BDBA270Element *, int);
};
