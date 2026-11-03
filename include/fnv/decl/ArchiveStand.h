#pragma once

struct ArchiveFileEntryStand;

struct ArchiveStand {
public:
    // 0x00afb2a0
    bool IsFileEntryValid(::ArchiveFileEntryStand *, bool);
};
