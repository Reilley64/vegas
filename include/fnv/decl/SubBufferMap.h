#pragma once

class TESForm;
struct SubBufferValue;

struct SubBufferMap {
public:
    // 0x00865730
    void GetNextEntry(void *&, ::TESForm *&, ::SubBufferValue &) const;
};
