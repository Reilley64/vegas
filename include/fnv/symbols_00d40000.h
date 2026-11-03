#pragma once

class hkpCollisionDispatcherD40;
struct BoxAgentRegistry;
struct Cache;
struct Callback;
struct FNVFlags;
struct FNVPair;
struct Input;
struct Output;
struct Pair;
struct Parameters;
struct State;
struct VecArg;

// 0x00d40130
void FUN_00d40130(::hkpCollisionDispatcherD40 *);
// 0x00d401d0
void *FUN_00d401d0(void *, void *, void *, void *);
// 0x00d406c0
void FUN_00d406c0(::Input *, ::Input *, ::Parameters *, struct ::Callback *);
// 0x00d40910
void FUN_00d40910(::BoxAgentRegistry *);
// 0x00d40b90
int ConvertPairFlags(::FNVPair *, int, ::FNVFlags *);
// 0x00d40d80
::Cache *FUN_00d40d80(::Pair *, ::State *, ::Cache *, ::VecArg, ::Output *);
