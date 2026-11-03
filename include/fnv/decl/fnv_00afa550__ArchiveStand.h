#pragma once

class ArchiveFile;

namespace fnv_00afa550 {
struct ArchiveStand {
public:
    // 0x00afa550
    ::ArchiveFile *OpenFile(int, int, int, const char *);
};
}
