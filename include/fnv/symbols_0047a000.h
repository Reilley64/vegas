#pragma once

class BGSOpenCloseForm;
class TESFile;
class TESForm;
class TESObjectREFR;
struct Arr;
struct NamedObject_47ab40;
struct Ref;
struct Ref_47ab40;
struct SArgs;
struct SequenceEvent;
struct TeleportableReference;

// 0x0047a110
void FUN_0047a110(::Arr *, ::SArgs);
// 0x0047a290
void FUN_0047a290(::TeleportableReference *, ::TESFile *);
// 0x0047a3a0
::BGSOpenCloseForm *GetOpenCloseForm(::TESForm *);
// 0x0047a560
void FUN_0047a560(::TESObjectREFR *, ::TESObjectREFR *, ::BGSOpenCloseForm *);
// 0x0047ab40
bool FUN_0047ab40(::Ref_47ab40 *, ::NamedObject_47ab40 *);
// 0x0047ac70
void ProcessOpenCloseEvent(::Ref *, ::SequenceEvent *);
