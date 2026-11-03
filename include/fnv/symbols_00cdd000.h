#pragma once

struct Hierarchy;
struct S_00cdd390_Table;
struct S_00cdd600_Bone;
struct S_00cdd600_Obj;
struct S_00cdd600_Out;

// 0x00cdd390
short FindIndexByKey(::S_00cdd390_Table *, const void *, int (*)(const void *, const void *));
// 0x00cdd410
void MarkHierarchyDescendants(::Hierarchy *, int, unsigned char *, unsigned char);
// 0x00cdd600
void MultiplyBoneScales(::S_00cdd600_Obj *, ::S_00cdd600_Bone *, int, ::S_00cdd600_Out);
// 0x00cddcf0
void CallWithGlobal(int, int, int, int);
// 0x00cddef0
void FUN_00cddef0(void *, void *, void *, void *);
