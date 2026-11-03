#pragma once

class NiAVObject;
class NiRTTI;

class NiShader {
public:
    // 0x004b5a50
    static ::NiAVObject *DynamicCast(::NiAVObject *);
    // 0x00b4f580
    ::NiShader *DynamicCast(const ::NiRTTI *);
};
