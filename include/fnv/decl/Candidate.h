#pragma once

struct NiPoint3;
struct SaveLocal;

struct Candidate {
public:
    // 0x006957f0
    void ComputeBounds(::NiPoint3 &, ::NiPoint3 &);
    // 0x009ebfe0
    void SaveToStream(::SaveLocal *);
    // 0x00a964c0
    void FUN_00a964c0(unsigned short);
    // 0x00b64bf0
    void RenderGeometryPass(void *, unsigned int, void *);
    // 0x00b902f0
    void *FUN_00b902f0(unsigned int);
    // 0x00cd2470
    void *FindOrAddPointer(void *);
    // 0x00d2bf70
    void *OpenFile(const char *);
};
