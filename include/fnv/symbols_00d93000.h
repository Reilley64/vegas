#pragma once

struct Caller;
struct Globals;
struct Job;
struct Queue;
struct S93ba0_Job;
struct S93ba0_Output;
struct S93ba0_Owner;
struct TargetClass;
struct Worker;

// 0x00d931a0
int AccumulateShapes(::Worker **, ::TargetClass *, ::Caller *);
// 0x00d93380
int FUN_00d93380(::Globals *, ::Queue *, ::Job *);
// 0x00d93ba0
int FUN_00d93ba0(::S93ba0_Owner *, ::S93ba0_Output *, ::S93ba0_Job *);
