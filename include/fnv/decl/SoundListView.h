#pragma once

struct SoundListEntry;

struct SoundListView {
public:
    // 0x009aa2b0
    void AddSoundEntry(float *, float *);
    // 0x009c71a0
    void AddCommand(::SoundListEntry *);
};
