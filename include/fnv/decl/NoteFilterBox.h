#pragma once

class BGSNote;

struct NoteFilterBox {
public:
    // 0x007a2e30
    void ApplyNoteFilter(bool (*)(BGSNote *));
};
