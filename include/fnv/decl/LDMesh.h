#pragma once

struct LDFile;

struct LDMesh {
public:
    // 0x0069c8f0
    void ReadFromBuffer(char *, ::LDFile *, int);
};
