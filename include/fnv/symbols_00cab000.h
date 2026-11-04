#pragma once

struct RNG_cabbd0;

// 0x00cabb00
unsigned int PackBytesBigEndian(unsigned char, unsigned char, unsigned char, unsigned char);
// 0x00cabb30
unsigned int PackColorBigEndian(float, float, float, float);
// 0x00cabbd0
unsigned int FUN_00cabbd0(::RNG_cabbd0 *);
