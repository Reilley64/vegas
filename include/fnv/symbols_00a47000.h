#pragma once
class NiStream;

class NiGPUProgram;
struct BinaryDataRecord;
struct FUN_00a471d0_Stream;
struct Obj00a47600;
struct Result;
struct S_00a47150_Obj;
struct Stream;
template <class> class NiPointer;

// 0x00a47150
::S_00a47150_Obj *FUN_00a47150();
// 0x00a471d0
void FUN_00a471d0(::FUN_00a471d0_Stream *, unsigned char *, unsigned int);
// 0x00a47360
struct FUN_00a47360_shell { void FUN_00a47360(::NiStream &); };
// 0x00a47380
void *FUN_00a47380();
// 0x00a47600
void ReleaseObjectArray(::Obj00a47600 **);
// 0x00a47ce0
::Result *CreateResultFromStreamObject(::Stream *, unsigned int, const char *);
// 0x00a47f20
namespace fnv_00a47f20 { void *FUN_00a47f20(); }
// 0x00a47f40
void GetGPUProgram(::BinaryDataRecord *, unsigned int, ::NiPointer< ::NiGPUProgram> &, void *);
