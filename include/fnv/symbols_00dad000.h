#pragma once

struct S_00dad4d0_Key;
struct S_00dad4d0_Set;
struct S_00dad640_Set;
struct S_00dad640_Target;

// 0x00dad4d0
bool FindAndPromoteEntry(::S_00dad4d0_Set *, ::S_00dad4d0_Key *);
// 0x00dad640
void ReleaseAllEntries(::S_00dad640_Set *, ::S_00dad640_Target *, void *);
