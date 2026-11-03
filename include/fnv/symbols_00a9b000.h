#pragma once

enum NiShaderAttributeDesc_AttributeType;
struct NiAlphaAccumulator;
struct StrArr;

// 0x00a9b140
void FUN_00a9b140();
// 0x00a9b150
void *FUN_00a9b150();
// 0x00a9b1a0
void FUN_00a9b1a0();
// 0x00a9b2e0
void FUN_00a9b2e0(::StrArr *);
// 0x00a9b330
void *FUN_00a9b330();
// 0x00a9b360
void FUN_00a9b360();
// 0x00a9b4b0
::NiAlphaAccumulator *CreateNiAlphaAccumulator();
// 0x00a9bbf0
unsigned int FUN_00a9bbf0(unsigned int, unsigned int);
// 0x00a9bcd0
::NiShaderAttributeDesc_AttributeType GetAttributeTypeForMapping(unsigned int, unsigned int &, unsigned int &);
