#pragma once

struct Body;
struct Input;
struct MotionPacket;
struct PenetrationCollector;
struct S_00d389f0_Dispatcher;

// 0x00d3a8c0
void FUN_00d3a8c0(::Body *, ::Body *, ::Input *, ::PenetrationCollector *);
// 0x00d3abc0
void FUN_00d3abc0(::S_00d389f0_Dispatcher *);
// 0x00d3ac80
void FUN_00d3ac80(const void *, const void *, const ::MotionPacket *, void *, void *);
