#pragma once

struct CC1290Object;
struct FUN_00cc1d80_object;
struct Owner;
struct S_00cc10b0_Agent;

// 0x00cc10b0
void FUN_00cc10b0(::S_00cc10b0_Agent *);
// 0x00cc1160
void FUN_00cc1160(::Owner *);
// 0x00cc1290
::CC1290Object *CreateCC1290Object();
// 0x00cc1ef0
::FUN_00cc1d80_object *CreateObjectWithGlobal();
