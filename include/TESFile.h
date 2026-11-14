// Source layout: TESFile. PC corrections are in generate_headers.py.
#ifndef FNV_TESFILE_H
#define FNV_TESFILE_H
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "layout_support.h"
#include "TESFileHeader.h"
#include "FormRecordHeader.h"
#include "_FILETIME.h"
#include "_WIN32_FIND_DATAA.h"
class TESFile
{
  public:
    TES_RETURN_CODE m_eReturnCode;                                // +0x0
    TESFile* m_pThreadSafeParent;                                 // +0x4
    NiTPointerMap<unsigned int, TESFile*>* m_pThreadSafeFileMap;  // +0x8
    BSFile* m_pSecondaryFile;                                     // +0xC
    BSFile* m_pFile;                                              // +0x10
    TESBitArrayFile* m_pBitArrayFile1;                            // +0x14
    TESBitArrayFile* m_pBitArrayFile2;                            // +0x18
    TESBitArrayFile* m_pBitArrayFile3;                            // +0x1C
    char m_acFilename[260];                                       // +0x20
    char m_acPath[260];                                           // +0x124
    char* m_pBuffer;                                              // +0x228
    unsigned int m_uiBufferAllocSize;                             // +0x22C
    unsigned int m_uiReadPosition;                                // +0x230
    unsigned int m_uiBufferSize;                                  // +0x234
    TESObjectCELL* m_pCurrentCell;                                // +0x238
    unsigned int m_uiFormCount;                                   // +0x23C
    FormRecordHeader m_kRecordInfo;                                           // +0x240
    CHUNK_ID m_eChunkID;                                          // +0x258
    unsigned int m_uiChunkSize;                                   // +0x25C
    unsigned int m_uiChunkOffset;                                 // +0x260
    unsigned int m_uiRecordSize;                                  // +0x264
    unsigned int m_uiRecordOffset;                                // +0x268
    unsigned int m_uiCurrentOffset;                               // +0x26C
    FormRecordHeader m_kChunkInfo;                                            // +0x270
    unsigned int m_uiChunkValue1;                                 // +0x288
    unsigned int m_uiChunkValue2;                                 // +0x28C
    BSSimpleList<TESFileGroup*> m_kRecordList;                      // +0x290
    bool m_bIsLoading;                                            // +0x298
    bool m_bIsSaving;                                             // +0x299
    bool m_bHasCurrentGroup;                                      // +0x29A
    unsigned char layoutPadding29B;
    _WIN32_FIND_DATAA m_kFindData;                   // +0x29C
    TESFileHeader m_kFileMetadata;                     // +0x3DC
    unsigned int m_uiFileCount;                      // +0x3E8
    BSSimpleList<char*> m_kFilenameList;             // +0x3EC
    BSSimpleList<_ULARGE_INTEGER*> m_kFileSizeList;  // +0x3F4
    unsigned int m_uiTESFileCount;                   // +0x3FC
    TESFile** m_ppTESFiles;                          // +0x400
    _FILETIME m_kLastWriteTime;                      // +0x404
    unsigned char m_ucCompileIndex;                  // +0x40C
    unsigned char layoutPadding40D;
    unsigned short layoutPadding40E;
    BSStringT<char> m_kCreator;       // +0x410
    BSStringT<char> m_kSummary;       // +0x418
    char* m_pDecompressedFormBuffer;  // +0x420
    unsigned int m_uiAuxBufferSize;   // +0x424
    bool m_bIsMaster;                 // +0x428
    bool m_bOptimizedFile;            // +0x429
    bool m_bIsDLC;                    // +0x42A
    unsigned char layoutPadding42B;
    TESFile* GetParentTESFile();
    TESFile* GetThreadSafeRootFile();
    TESFile* GetFileForThread(unsigned int threadID);
    bool IsEndianConversionRequired();
    bool IsCurrentFormCompressed();
    TESFile(const char* path, const char* filename, NiFile::OpenMode openMode);
    bool IsMasterFile();
    void SetMasterFile(bool master);
    unsigned char GetFileCompileIndex();
    void SetCompileIndex(unsigned char index);
    void SetThreadSafeParent(TESFile* parent);
    bool OpenTESFile(NiFile::OpenMode openMode, bool closeOverride);
    void InitializeComponent();
    unsigned char GetTESForm();
    bool GetChunkData(unsigned int* value);
    bool NextChunk();
    unsigned int GetOffset();
public:
    bool GetOptimizedFile();
};
#endif
