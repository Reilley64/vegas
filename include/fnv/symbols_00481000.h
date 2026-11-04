#pragma once

class TESForm;
class TESObject;
class TESObjectREFR;
struct FUN_004895b0_model;
struct TESForm;
struct TESModelTextureSwap;
struct TESObjectREFR;

// 0x00481010
::FUN_004895b0_model *FUN_00481010(::TESForm *, ::TESObjectREFR *);
// 0x00481090
::TESModelTextureSwap *GetBipedModelTextureSwap(::TESForm *, ::TESObjectREFR *);
// 0x004812f0
char *FUN_004812f0(const char *, const char *);
// 0x00481f10
bool FUN_00481f10(::TESObject *);
