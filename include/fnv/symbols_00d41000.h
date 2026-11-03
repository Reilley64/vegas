#pragma once

class SpawnedObject;
struct AlignedVec;
struct D41FD0CollisionDispatcher;
struct FUN_00d41830_table;
struct InputData;
struct Input_s;
struct Output;
struct Output_s;
struct Request;
struct ResultData;
struct S_00d417b0_Obj;
struct Table;
struct hkpGskCache_s;

// 0x00d417b0
void RemoveEntryById(int, ::S_00d417b0_Obj *, short);
// 0x00d417f0
void InsertSlotId(int, ::Table *, unsigned short);
// 0x00d41830
int FindEntryByKey(int, ::FUN_00d41830_table *, unsigned short);
// 0x00d41860
extern "C" void *FUN_00d41860_impl(void *, void *, void *, void *);
// 0x00d418b0
void ForwardToTarget(void *, void *, void *, void *, void *);
// 0x00d418d0
void *DispatchInputRecord(::InputData *, unsigned char *, ::ResultData *);
// 0x00d41930
void FUN_00d41930(::Input_s *, const void *, ::hkpGskCache_s *, ::Output_s *);
// 0x00d41a30
void *FUN_00d41a30(::Request *, unsigned char *, ::ResultData *, ::AlignedVec *, ::Output *);
// 0x00d41ec0
void FUN_00d41ec0(int *);
// 0x00d41f00
void FUN_00d41f00(::SpawnedObject *, int, int);
// 0x00d41f50
void *CreateSpawnObject(int, int, int, int);
// 0x00d41fd0
void RegisterStaticCollisionAgent(::D41FD0CollisionDispatcher *);
