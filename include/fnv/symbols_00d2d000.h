#pragma once

class hkAabb;
class hkTransform;
struct hkVector4;
class hkpCdBody;
struct Agent;
struct FUN_00cfbd60_Obj;
struct GskAgentInput;
struct Interface;
struct LessU32;
struct Src;
struct ValueSource;

// 0x00d2d3e0
void CallWithValueSource(void *, void *, int, ::ValueSource **, int, int, int);
// 0x00d2d430
struct Hdr;
void FUN_00d2d430(void *, ::Hdr *, char **, ::Agent *);
// 0x00d2d480
void FUN_00d2d480(void *, void *, float, float, void **);
// 0x00d2d4b0
void FUN_00d2d4b0(::Interface **);
// 0x00d2d4c0
void *GetSpawnedObjectPointer(void **);
// 0x00d2d4f0
int FUN_00d2d4f0(const ::hkpCdBody &, const ::hkpCdBody &, const ::hkTransform &, const ::hkVector4 &, const ::GskAgentInput &, ::hkAabb *, unsigned int *, int);
// 0x00d2d890
char *FUN_00d2d890(char *, int, char *, int, void *);
// 0x00d2da20
void FUN_00d2da20(::FUN_00cfbd60_Obj *);
// 0x00d2da70
extern "C" void QuickSortRange(unsigned int *, int, int, ::LessU32);
// 0x00d2daf0
void FUN_00d2daf0(int, int, ::Src *, int, int);
// 0x00d2dc70
void FUN_00d2dc70(::Agent *);
// 0x00d2dd50
extern "C" void FUN_00d2dd50(void *, void *, void *, void *);
// 0x00d2df50
void *FUN_00d2df50(int, int, int, int);
