#pragma once

struct DArray;
struct DMember;
struct DOutArray;

struct DReader {
public:
    // 0x00dc1d30
    int ReadArray(::DOutArray *, ::DMember *, ::DArray *);
};
