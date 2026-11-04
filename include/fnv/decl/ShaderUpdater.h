#pragma once

struct ShaderEntryTable;
struct ShaderInterface;

struct ShaderUpdater {
public:
    // 0x00c0bae0
    void UpdateShaderEntry(::ShaderEntryTable *, ::ShaderInterface *, int);
};
