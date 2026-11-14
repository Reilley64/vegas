#pragma once

class BSMultiBound;
class TESObjectREFR;
struct AnimController;
struct AnimSource;
struct BoundRef;

// 0x00439490
::BSMultiBound *FUN_00439490(::TESObjectREFR *);
// 0x004396e0
::AnimController *FUN_004396e0(::AnimSource *);
// 0x00439940
bool BoundIntersectsCell(::BoundRef *, int, int);
