#pragma once

namespace SimpleQuad { class ByteAnswer; }
namespace SimpleQuad { struct PCast; }
namespace SimpleQuad { struct PCollector; }
namespace SimpleQuad { struct PTree; }
struct CommandRecord;
struct ContactVectors;
struct Header;
struct Input;
struct VelocityBody;
struct VelocityVector;

// 0x00df2040
void FUN_00df2040(int, int, const char *, char *);
// 0x00df21c0
void WriteInputHeader(::Input *, void *, ::Header **);
// 0x00df22f0
int ValidateHavokKeyCode(bool *);
// 0x00df2510
float FUN_00df2510(const ::VelocityBody *, const ::VelocityBody *, const ::VelocityVector *, const ::VelocityVector *, const ::ContactVectors *);
// 0x00df25f0
void FUN_00df25f0(void *, ::CommandRecord *, int);
// 0x00df2750
extern "C" ::SimpleQuad::ByteAnswer FUN_00df2750(const ::SimpleQuad::PTree *, ::SimpleQuad::PCast &, ::SimpleQuad::PCollector *, float);
