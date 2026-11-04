#pragma once

class NiStream;

class NiTransform {
public:
    // 0x004b4880
    void CalculateInverse(::NiTransform &);
    // 0x0062c250
    ::NiTransform operator*(const ::NiTransform &) const;
    // 0x00a86bf0
    void ResetToIdentity();
    // 0x00a86c80
    void LoadBinary(::NiStream &);
};
