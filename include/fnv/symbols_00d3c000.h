#pragma once

class hkpCdBody;
class hkpCdPointCollector;
struct CollisionAgentContext;
struct D3C380_Obj;
struct Registry;
struct S_00d3c440_Body;
struct S_00d3c440_Collector;

// 0x00d3c010
void RegisterHandlers(::Registry *);
// 0x00d3c380
::D3C380_Obj *CreateD3C380Obj(int, int, int, int);
// 0x00d3c400
void FUN_00d3c400(int, int, int, int);
// 0x00d3c440
void FUN_00d3c440(const ::S_00d3c440_Body *, const ::S_00d3c440_Body *, int, ::S_00d3c440_Collector *);
// 0x00d3c590
void ForwardToD3C440(int, int, int, int);
// 0x00d3cc00
void FUN_00d3cc00(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdPointCollector &);
// 0x00d3cef0
void FUN_00d3cef0(::Registry *);
// 0x00d3cfc0
void FUN_00d3cfc0(int, int, int, int);
