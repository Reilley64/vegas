#pragma once

struct ExportAlloc;
struct ExportRecord;
template <class, class> struct ExportList;

struct ExportSection {
public:
    // 0x00e02f60
    void ReadRecords(const void *, ::ExportList< ::ExportRecord, ::ExportAlloc> &) const;
};
