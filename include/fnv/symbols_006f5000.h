#pragma once

struct LodObject;
struct TESWorldSpace;

// 0x006f55f0
void FormatLODBlockFileName(char *, ::TESWorldSpace *, int, short, short);
// 0x006f5640
void BuildLODBlockFilePath(char *, ::TESWorldSpace *, int, short, short);
// 0x006f5690
void BuildLODBlockFileName(char *, ::TESWorldSpace *, int, short, short);
// 0x006f56e0
void BuildStingerNifPath(char *, ::TESWorldSpace *, int, short, short);
// 0x006f5730
void FormatStingerBlockPath(char *, ::TESWorldSpace *, int, short, short);
// 0x006f5840
void FUN_006f5840();
// 0x006f58e0
void SetObjectVisible(::LodObject *, bool);
