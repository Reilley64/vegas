#pragma once

struct BuildCatalog;
struct BuildInput;
struct BuildOutput;

struct BuildProcess {
public:
    // 0x006bc3e0
    bool Build(::BuildOutput *, ::BuildInput *, ::BuildCatalog *);
};
