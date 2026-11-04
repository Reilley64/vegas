#pragma once

struct ClassInfo;
struct LoadedObjectReg;
struct PtrMap;
struct VtableClassReg;

// 0x00e4afe0
void *FUN_00e4afe0(const void *, const ::ClassInfo &, ::PtrMap *, ::VtableClassReg *, ::LoadedObjectReg *, int);
