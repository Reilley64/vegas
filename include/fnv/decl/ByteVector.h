#pragma once

struct ByteInsertIterator;
struct ByteIterator;

struct ByteVector {
public:
    // 0x00ab3370
    void FUN_00ab3370(::ByteInsertIterator, unsigned int, const char &);
    // 0x00b0ecf0
    void FUN_00b0ecf0(::ByteIterator, unsigned int, const char &);
    // 0x00b0f3c0
    char *FUN_00b0f3c0(char *, unsigned int, const char &);
};
