#pragma once

namespace fnv_00ddc160 { class DDC160Interface; }
struct DDCE80Bool;
struct DDCE80Point;
struct Flag;
struct Item;
struct S_00ddcb90_Base2;
struct Shape;
struct Vec4;
struct hkInspectProcess;

// 0x00ddc160
namespace fnv_00ddc160 { ::fnv_00ddc160::DDC160Interface *CreateImpl(void *); }
// 0x00ddc1a0
::hkInspectProcess *CreateStatisticsProcess();
// 0x00ddcb90
::S_00ddcb90_Base2 *FUN_00ddcb90();
// 0x00ddcbc0
namespace fnv_00ddcbc0 { void FUN_00ddcbc0(); }
// 0x00ddcda0
::Flag FUN_00ddcda0(::Item *, ::Item *);
// 0x00ddcdd0
unsigned int FUN_00ddcdd0(unsigned int, unsigned int, unsigned int);
// 0x00ddcdf0
int ExtractBitField(unsigned short, char);
// 0x00ddce80
::DDCE80Bool AreZDiffering(const ::DDCE80Point &, const ::DDCE80Point &);
// 0x00ddcf60
volatile unsigned char *FUN_00ddcf60(volatile unsigned char *, const ::Vec4 *, const ::Vec4 *, const ::Shape *);
