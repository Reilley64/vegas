#pragma once

struct NiStreamFake;

struct PartitionSave {
public:
    // 0x00a830d0
    void WriteToStream(::NiStreamFake &);
};
