#pragma once

class AccumWIP;
class B644B0Owner;
struct AccumWIP;
struct B64440A2;
struct B644B0Shape;
struct BSBatchRendererView;
struct RSPacket;
struct RSResponse;
struct RSSettings;

// 0x00b64020
bool ProcessCommands(::RSSettings *, void *, void *, ::RSPacket *, ::RSResponse *);
// 0x00b64440
bool FUN_00b64440(::RSSettings *, ::B64440A2 *, void *, ::RSPacket *, ::RSResponse *);
// 0x00b64490
bool FUN_00b64490(void *, void *, void *, void *, void *);
// 0x00b644b0
bool AddEntriesToAccumulator(::B644B0Shape *, void *, int, ::B644B0Owner *);
// 0x00b64530
void FUN_00b64530(::AccumWIP *);
// 0x00b64e30
void FUN_00b64e30(::AccumWIP *);
// 0x00b64f20
void FUN_00b64f20(::BSBatchRendererView *, int, unsigned int);
