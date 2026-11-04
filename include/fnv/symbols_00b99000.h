#pragma once

#include <cstdint>

class BSBatchRenderer__PassList;
namespace fnv_00b99110 { struct DrawPass; }
namespace fnv_00b994f0 { struct Pass_b994f0; }
struct BSBatchRenderer_View_00b99bc0;
struct FUN_00b99390_S;
struct FUN_00b99890_List;
struct PassGroup_Layout;

// 0x00b99110
namespace fnv_00b99110 { void FUN_00b99110(::fnv_00b99110::DrawPass *, bool, bool, bool); }
// 0x00b99390
void SetShaderPass(unsigned int, ::FUN_00b99390_S *);
// 0x00b994f0
namespace fnv_00b994f0 { void FUN_00b994f0(::fnv_00b994f0::Pass_b994f0 *, unsigned int, bool, bool, bool); }
// 0x00b99840
void FUN_00b99840(void *, int, void *const *);
// 0x00b99890
void PushFront(::FUN_00b99890_List *, int, unsigned int *);
// 0x00b998f0
void FUN_00b998f0();
// 0x00b99990
void ClearPassList(::BSBatchRenderer__PassList *, int);
// 0x00b99a10
void FUN_00b99a10(char *, int, std::intptr_t, char);
// 0x00b99a50
void ClearPassGroups(::PassGroup_Layout *, int, bool);
// 0x00b99bc0
void ClearAllGroups(::BSBatchRenderer_View_00b99bc0 *, int, int);
