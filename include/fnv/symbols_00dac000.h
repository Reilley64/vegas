#pragma once

struct FUN_00daad40_solver;
struct FUN_00dabf10;
struct GskNode;
struct S_00dac2b0_Body;
struct S_00dac2b0_Collector;
struct hkVector4DAC0;
struct hkpCdBodyDAC0;
struct hkpCollisionInputDAC0;

// 0x00dac020
void FUN_00dac020(const ::hkpCdBodyDAC0 &, const ::hkpCdBodyDAC0 &, const ::hkpCollisionInputDAC0 &, ::FUN_00daad40_solver *, ::hkVector4DAC0 &);
// 0x00dac2b0
void TestGsk(const ::S_00dac2b0_Body &, const ::S_00dac2b0_Body &, const void *, ::S_00dac2b0_Collector &);
// 0x00dacc00
::FUN_00dabf10 *FUN_00dacc00(::GskNode *, ::GskNode *, const void *, void *);
