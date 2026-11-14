#pragma once

struct FUN_P;
struct HkBody;
struct HkCollector;
struct HkInput;

// 0x00e88d00
bool FUN_00e88d00(::FUN_P *);
// 0x00e88dc0
bool ProcessCollector(::HkCollector *, ::HkBody *, ::HkInput *, bool, int, int);
