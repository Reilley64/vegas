#pragma once

class hkStatisticsCollectorD922;
class hkTargetD922;
class hkTargetD922B;
class hkTargetD92A;
namespace fnv_00d925b0 { struct hkpSimpleContactConstraintAtom; }
struct D92740Block;
struct DispatchTarget;
struct FUN_00d92250_holder;
struct FUN_00d92270_Dispatch;
struct FUN_00d922e0_Iface;
struct FUN_00d92380_holder;
struct FUN_00d92380_vec;
struct S00d92900_Atom;
struct S00d92900_Data;
struct S00d92900_QueryIn;
struct S_00d92690;
struct hkpAgent3InputD923;
struct hkpAgentDataD923;
struct hkpAgentEntryD922;
struct hkpAgentEntryD923;

// 0x00d921c0
char *FUN_00d921c0(char *, const char *);
// 0x00d921d0
int FUN_00d921d0(const signed char *);
// 0x00d921e0
void InvokeDispatch(void *, ::DispatchTarget **, void *, int);
// 0x00d92200
void FUN_00d92200(void *, ::hkTargetD922B **, void *, void *, void *, void *, void *);
// 0x00d92230
void AddChildAgent2ToCollector(void *, const ::hkpAgentEntryD922 *, void *, ::hkStatisticsCollectorD922 *);
// 0x00d92250
void CallObjectVirtual(void *, ::FUN_00d92250_holder *, int);
// 0x00d92270
int DispatchVirtualCall(int, ::FUN_00d92270_Dispatch **, float, float, int);
// 0x00d922a0
void FUN_00d922a0(void *, ::hkTargetD92A **, void *);
// 0x00d922c0
void FUN_00d922c0(void *, ::hkTargetD922 **, void *);
// 0x00d922e0
void *CallIfaceMethod(int, ::FUN_00d922e0_Iface **, int);
// 0x00d92300
::hkpAgentDataD923 *CreateAgent(const ::hkpAgent3InputD923 &, ::hkpAgentEntryD923 *, ::hkpAgentDataD923 *);
// 0x00d92380
int *CallVirtualWithVectorArgs(::FUN_00d92380_vec *, int, ::FUN_00d92380_holder *, int, int);
// 0x00d923b0
void FUN_00d923b0(void *);
// 0x00d92440
int RoundUpToBucketSize(int);
// 0x00d92510
::D92740Block *AllocateBlock(int, int, int, int);
// 0x00d925b0
namespace fnv_00d925b0 { void FUN_00d925b0(::fnv_00d925b0::hkpSimpleContactConstraintAtom *, const ::fnv_00d925b0::hkpSimpleContactConstraintAtom *); }
// 0x00d92690
::S_00d92690 *FUN_00d92690(::S_00d92690 *, bool *);
// 0x00d92740
::D92740Block *ShrinkBlockIfSparse(::D92740Block *, int, bool *);
// 0x00d92900
void FUN_00d92900(::S00d92900_Data *, const ::S00d92900_QueryIn *, ::S00d92900_Atom *, int);
