#pragma once

struct AnimationReference;
struct AnimationTile;
struct VisibilityTile;

// 0x00719440
void UnpackBytes(unsigned int, unsigned int *, unsigned int *, unsigned int *, unsigned int *);
// 0x00719580
void FUN_00719580(::VisibilityTile *);
// 0x00719790
void UpdateAnimationTileFade(::AnimationTile *, ::AnimationTile *, ::AnimationTile *, ::AnimationReference *, bool);
// 0x00719ae0
bool FUN_00719ae0(void *);
