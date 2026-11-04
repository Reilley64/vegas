#pragma once

struct EC0280Device;
struct FUN_00ec0460_cls;
struct FUN_00ec0720_Device;

// 0x00ec0280
void DrawTexturedQuad(::EC0280Device *, float, float, float, float, int, int);
// 0x00ec0460
void FUN_00ec0460(::FUN_00ec0460_cls *);
// 0x00ec0720
void FUN_00ec0720(::FUN_00ec0720_Device *, float, float, float, float, int, int);
