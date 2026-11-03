#pragma once

class ArchiveFile;
namespace fnv_00afa750 { struct ArchiveFileEntryStand; }

namespace fnv_00afa750 {
struct ArchiveStand {
public:
    // 0x00afa750
    ::ArchiveFile *CreateArchiveFile(::fnv_00afa750::ArchiveFileEntryStand *, unsigned int, unsigned int);
};
}
