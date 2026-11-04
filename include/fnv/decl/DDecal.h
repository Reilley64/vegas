#pragma once

struct DBone;
struct DGeometry;
struct DNewPartition;
struct DPoint;

struct DDecal {
public:
    // 0x00685ef0
    void BuildDecalGeometry();
    // 0x00687d90
    void CreateDecalGeometry(::DGeometry *, unsigned short, unsigned short, ::DPoint *, ::DPoint *, unsigned short *, ::DBone *, ::DNewPartition *, unsigned short *);
};
