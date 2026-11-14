#pragma once

struct SaveBuffer;

struct TESGridOwner {
public:
    // 0x00459490
    void SaveGridState(::SaveBuffer *);
};
