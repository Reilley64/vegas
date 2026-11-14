#pragma once

class TESForm;
struct FixupStream;

struct FixupList {
public:
    // 0x0042ceb0
    void FixupReferences(::FixupStream *, ::TESForm *);
};
