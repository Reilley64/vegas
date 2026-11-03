#pragma once

class Target;
struct ExecutionContext;
struct Frame;
struct Handler_cls;
struct Job;
struct PairCommand;
struct QueryInput;
struct QueryJob;
struct Scheduler;
struct WorkQueue;

// 0x00df6440
void FUN_00df6440(::Handler_cls *, int);
// 0x00df6460
void FUN_00df6460(void **);
// 0x00df6850
void ProcessAabbTree(::Target *, ::Frame *);
// 0x00df6950
void ProcessWorkQueue(::ExecutionContext *, ::WorkQueue *);
// 0x00df6e00
void FUN_00df6e00(const ::QueryJob *, const ::QueryInput *, ::PairCommand *, int);
// 0x00df6f80
void FUN_00df6f80(::Scheduler *, ::Job *);
