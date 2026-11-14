#pragma once

class BC66F10RefObject;
struct BC66F10Entry;
struct BhkPickData;
struct ControlledObj;
struct UpdateData;

// 0x00c66210
void FUN_00c66210();
// 0x00c66230
void FUN_00c66230(unsigned char);
// 0x00c66760
void FUN_00c66760(float, bool, bool);
// 0x00c66f10
bool AssignSystemGroup(::BC66F10RefObject *, ::BC66F10Entry *);
// 0x00c66fd0
char *FUN_00c66fd0(::BhkPickData *);
// 0x00c66ff0
void FUN_00c66ff0(::ControlledObj *, ::UpdateData *);
