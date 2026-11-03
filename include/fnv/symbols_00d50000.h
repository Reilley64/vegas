#pragma once

namespace fnv_00d50d60 { struct D50D60_Stream; }
struct FUN_00d503c0_src;
struct Runtime;
struct hkSchemeVecs;
struct hkVector4;

// 0x00d50000
void FUN_00d50000(int *, int);
// 0x00d503c0
void FUN_00d503c0(int, int, int, ::FUN_00d503c0_src *, void *, void *);
// 0x00d505c0
void FUN_00d505c0(int **, int *, void *, int *, int *, int);
// 0x00d50d00
void FUN_00d50d00(int **, int, int, ::Runtime *, void *, void *);
// 0x00d50d60
namespace fnv_00d50d60 { void FUN_00d50d60(unsigned int **, int, int, ::fnv_00d50d60::D50D60_Stream *, int, int); }
// 0x00d50e10
void FUN_00d50e10(int, int, int, void *, int, int);
// 0x00d50ec0
void FUN_00d50ec0(int **, ::hkVector4 **, int, ::hkSchemeVecs *, int, int);
