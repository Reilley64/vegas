#pragma once

class Tile;
namespace ActorValue { enum Index; }

// 0x007df4e0
namespace fnv_007df4e0 { void UpdateStatsMenuLevelText(); }
// 0x007df9c0
int MapIndexToCode(int);
// 0x007dfb00
void UpdateActorValueTile(::Tile *, ::ActorValue::Index);
// 0x007dfc60
void FUN_007dfc60(::Tile *, int);
// 0x007dfc90
void PlayPipboyPageSound(bool);
