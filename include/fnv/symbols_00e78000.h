#pragma once

struct CopyStreamData;
struct FUN_00e79f40_Stream;
struct Stream78;
struct StreamCopyInfo;
struct StreamE788;
struct Stream_e78910;
struct StridedDataTransfer;

// 0x00e78060
int CopyStreamElements(::FUN_00e79f40_Stream *);
// 0x00e78210
unsigned int CopyIndexedRows(::StridedDataTransfer *);
// 0x00e783b0
unsigned int FUN_00e783b0(::StreamCopyInfo *);
// 0x00e78880
int FUN_00e78880(::StreamE788 *);
// 0x00e78910
int PackVertexColors(::Stream_e78910 *);
// 0x00e78a70
unsigned int FUN_00e78a70(::Stream_e78910 *);
// 0x00e78d50
int FUN_00e78d50(::CopyStreamData *);
// 0x00e78e30
unsigned int FUN_00e78e30(::Stream78 *);
// 0x00e78f80
unsigned int FUN_00e78f80(::Stream_e78910 *);
