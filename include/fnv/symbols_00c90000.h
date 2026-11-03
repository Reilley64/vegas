#pragma once

namespace fnv_00c909d0 { struct hkMemoryAllocator; }
struct AudioAllocator;
struct AudioStream;
struct SpawnedArray;
struct SpawnedObject;

// 0x00c90410
void FUN_00c90410(int);
// 0x00c90490
void EnterTlsGuard();
// 0x00c904e0
void FUN_00c904e0();
// 0x00c90670
void FUN_00c90670(const void *, int, int);
// 0x00c90740
void FUN_00c90740(void *, int, int);
// 0x00c908c0
void FUN_00c908c0(::SpawnedObject *, ::SpawnedArray *, int, int);
// 0x00c90940
void ResizeAudioStream(::AudioAllocator *, ::AudioStream *, int);
// 0x00c909d0
namespace fnv_00c909d0 { void FUN_00c909d0(::fnv_00c909d0::hkMemoryAllocator &, void *, int, void *, int); }
