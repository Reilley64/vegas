#pragma once

namespace fnv_00a30330 { struct Ctl; }
namespace fnv_00a303a0 { struct Stream; }
struct Stream;

// 0x00a30330
namespace fnv_00a30330 { ::fnv_00a30330::Ctl *CreateCtl(); }
// 0x00a30370
void FUN_00a30370(::Stream *, const void *);
// 0x00a303a0
namespace fnv_00a303a0 { void FUN_00a303a0(::fnv_00a303a0::Stream *, const void *); }
// 0x00a305b0
int NiSprintf(char *, unsigned int, const char *, ...);
