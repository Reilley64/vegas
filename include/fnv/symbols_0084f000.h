#pragma once

class FNVU64Source;
class ReferencePlacementData;
class TESForm;

// 0x0084f840
bool FUN_0084f840(int);
// 0x0084f860
bool FUN_0084f860(int);
// 0x0084f8e0
::TESForm *ResolveReferenceForm(unsigned int, ::ReferencePlacementData *, ::TESForm *);
// 0x0084fbe0
int CompareU64Values(::FNVU64Source *, ::FNVU64Source *);
// 0x0084fd30
namespace fnv_0084fd30 { void FUN_0084fd30(); }
