#pragma once

class _ULARGE_INTEGER;
struct TESRecordHeader;
template <class> class BSSimpleList;

class TESFile {
public:
    // 0x00401680
    bool IsEndianConversionRequired();
    // 0x00462270
    ::TESRecordHeader *GetRecordHeader();
    // 0x00467bb0
    unsigned int GetOffset();
    // 0x00470b90
    ::BSSimpleList< ::_ULARGE_INTEGER *> *GetMasterDataList();
    // 0x00471c20
    bool IsMasterFile();
    // 0x00471ca0
    bool GetOptimizedFile();
    // 0x004720d0
    void ClearCurrentChunk();
    // 0x00472100
    bool IsCurrentFormCompressed();
    // 0x004724c0
    unsigned int GetOffsetChunk();
    // 0x004726f0
    bool NextChunk();
    // 0x00473250
    unsigned char GetFileCompileIndex();
    // 0x00473660
    bool IsGroupOpen();
    // 0x004739b0
    ::TESFile *GetParentTESFile();
};
