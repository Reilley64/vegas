#pragma once

struct C749F0Entry;
struct C74QsTransform;
struct C74Transform;
struct DST;
struct SRC;

// 0x00c749f0
void CopyEntries(::C749F0Entry *, const ::C749F0Entry *, unsigned int);
// 0x00c74a70
float ClampedAcos(float);
// 0x00c74d50
::DST *FUN_00c74d50(::DST *, const ::SRC *);
// 0x00c74dd0
::C74QsTransform *FUN_00c74dd0(::C74QsTransform *, const ::C74Transform *);
// 0x00c74ea0
void *FUN_00c74ea0(unsigned int);
