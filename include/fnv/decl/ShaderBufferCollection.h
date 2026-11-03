#pragma once

class ShaderBufferRecord;

class ShaderBufferCollection {
public:
    // 0x00b7fac0
    ::ShaderBufferRecord *Get(const char *);
    // 0x00b7fd50
    ~ShaderBufferCollection();
};
