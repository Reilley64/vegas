#pragma once

namespace fnv_00e0d640 { struct FUN_00e0d640_buf; }
namespace fnv_00e0d640 { struct FUN_00e0d640_cfg; }
namespace fnv_00e0fec0 { struct AggObj; }
namespace fnv_00e0fec0 { struct TimerObj; }
struct AnimationTimingInfo;
struct FloatArray;
struct FrameInfoArrays;
struct MonNodeList;
struct PrintConfig;
struct PrintNode;
struct PrintStream;

// 0x00e0d280
void FUN_00e0d280(void *, void *, int, int, float);
// 0x00e0d2c0
void FUN_00e0d2c0(::PrintStream *, ::PrintNode *, int, const int, const int, ::PrintConfig *);
// 0x00e0d640
namespace fnv_00e0d640 { void FUN_00e0d640(int, int, int, ::fnv_00e0d640::FUN_00e0d640_buf *, ::fnv_00e0d640::FUN_00e0d640_cfg *); }
// 0x00e0d880
namespace fnv_00e0fec0 { void FUN_00e0d880(::fnv_00e0fec0::AggObj *, ::fnv_00e0fec0::TimerObj *); }
// 0x00e0dd30
void FUN_00e0dd30(const ::MonNodeList &, const ::AnimationTimingInfo &, const ::FrameInfoArrays &, float &, ::FloatArray &);
