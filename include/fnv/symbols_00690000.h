#pragma once

class NavMeshInfo;
class TESForm;
class TESWorldSpace;
struct DecompRefOwner;

// 0x00690800
::TESWorldSpace *FUN_00690800(const ::NavMeshInfo *);
// 0x00690830
::TESForm *FUN_00690830(const ::NavMeshInfo *);
// 0x00690890
void ProcessWithScopedRef(::DecompRefOwner *, void *);
