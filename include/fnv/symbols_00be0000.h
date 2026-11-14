#pragma once

class BeamStage;
namespace fnv_00be0fe0 { class FUN_00be0b30; }
struct _D3DXMACRO;

// 0x00be0c00
void FUN_00be0c00(const char *, char *);
// 0x00be0cf0
void ConfigureBeamStage(::BeamStage *, unsigned int, unsigned int, unsigned int, bool);
// 0x00be0dc0
void BuildCachePath(char *, const char *, const char *);
// 0x00be0fe0
namespace fnv_00be0fe0 { ::fnv_00be0fe0::FUN_00be0b30 *FUN_00be0fe0(const char *, ::_D3DXMACRO *, const char *, const char *); }
