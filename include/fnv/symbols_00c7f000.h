#pragma once
#include <cstdint>

struct PhysicsBody;
struct S00c7fcc0_Obj;
struct S00c7fcc0_Out;
struct S_00c7fb50_portal;
struct S_Obj;
struct SearchObject;
struct XRef;

// 0x00c7f900
void FUN_00c7f900(char *, char *, unsigned int);
// 0x00c7fa90
int FUN_00c7fa90(::S_Obj *);
// 0x00c7fb50
::S_00c7fb50_portal *FUN_00c7fb50(::S_00c7fb50_portal *);
// 0x00c7fcc0
bool FUN_00c7fcc0(::S00c7fcc0_Obj *, intptr_t, ::S00c7fcc0_Out *, bool);
// 0x00c7ff40
::PhysicsBody *FindPhysicsBodyByLayer(::SearchObject *, unsigned int);
// 0x00c7ffd0
int FUN_00c7ffd0(::XRef *);
