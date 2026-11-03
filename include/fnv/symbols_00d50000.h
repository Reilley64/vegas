#pragma once

namespace fnv_00d50d60 { struct D50D60_Stream; }
struct FUN_00d503c0_src;
struct NiStream;
struct Runtime;
struct hkSchemeVecs;
struct hkVector4;

// 0x00d50000
void FUN_00d50000(int *, ::NiStream *);
// 0x00d503c0
void FUN_00d503c0(int **, void *, const void *, ::FUN_00d503c0_src *, void *, void *);
// 0x00d505c0
void FUN_00d505c0(int **, int *, void *, int *, int *, void *);
// 0x00d50d00
void FUN_00d50d00(int **, const void *, const void *, ::Runtime *, void *, void *);
// 0x00d50d60
namespace fnv_00d50d60 { void FUN_00d50d60(unsigned int **, const void *, const void *, ::fnv_00d50d60::D50D60_Stream *, const void *, void *); }
// 0x00d50e10
void FUN_00d50e10(int **, void *, const void *, void *, const void *, void *);
// 0x00d50ec0
void FUN_00d50ec0(int **, ::hkVector4 **, const void *, ::hkSchemeVecs *, const void *, void *);
