#pragma once

class TaskTarget;
struct ArgStruct;
struct CastJob;
struct CastSettings;
struct CollisionAgentContext;
struct ContextHandle;
struct KdJob2;
struct KdJob;
struct KdQueue2;
struct KdQueue;
struct Obj_df7a90;
struct SDF7_JobQueueEntry;
struct S_00df7010_Input;
struct S_00df7010_Output;

// 0x00df7010
void ExecuteMoppAabbQuery(::S_00df7010_Output *, const ::S_00df7010_Input *);
// 0x00df7760
void FUN_00df7760(const ::CastSettings *, const ::CollisionAgentContext *, ::CastJob *, intptr_t);
// 0x00df79d0
void FUN_00df79d0(void *, ::TaskTarget *);
// 0x00df7a90
int FUN_00df7a90(int, int, ::Obj_df7a90 *);
// 0x00df7ad0
int SplitJob(void *, void *, ::SDF7_JobQueueEntry &, ::SDF7_JobQueueEntry &);
// 0x00df7c00
int ExecuteJob(::KdQueue2 *, ::KdJob2 *);
// 0x00df7d60
int FinishJobWithPair(::KdQueue *, ::KdJob *);
// 0x00df7e20
int BuildKdTreeDistributed(::ContextHandle, ::ArgStruct *, ...);
