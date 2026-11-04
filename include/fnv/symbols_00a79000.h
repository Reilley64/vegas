#pragma once

struct Format_a79310;
struct Format_a798c0;
struct Format_a79ef0;
struct Palette_a79310;
struct Palette_a798c0;
struct Palette_a79ef0;

// 0x00a79310
void FUN_00a79310(unsigned int, unsigned int, unsigned int, unsigned int *, ::Palette_a79310 *, ::Format_a79310 *, const unsigned char *);
// 0x00a798c0
void FUN_00a798c0(unsigned int, unsigned int, unsigned int, unsigned int *, ::Palette_a798c0 *, ::Format_a798c0 *, const unsigned char *);
// 0x00a79e20
void FUN_00a79e20(unsigned int, unsigned int, unsigned int, unsigned char *, void *, void *, const unsigned char *);
// 0x00a79ef0
void ConvertPalettizedToFormat(unsigned int, unsigned int, unsigned int, unsigned int *, ::Palette_a79ef0 *, ::Format_a79ef0 *, const unsigned char *);
