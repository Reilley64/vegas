#pragma once
#include <cstdint>

class CE7C500PixelFormat;
struct PixelTemplate;
struct S_00e7c610_Object;

// 0x00e7c1e0
::PixelTemplate &GetPixelTemplateForFormat(int, ::PixelTemplate &);
// 0x00e7c500
::CE7C500PixelFormat *CreatePixelFormat(int);
// 0x00e7c610
void FUN_00e7c610(float *, ::S_00e7c610_Object *);
// 0x00e7cc50
void FUN_00e7cc50(int *, int);
// 0x00e7cca0
unsigned char FUN_00e7cca0(int *);
// 0x00e7ccf0
int FUN_00e7ccf0(unsigned int);
// 0x00e7cd40
int FUN_00e7cd40();
// 0x00e7cec0
void FUN_00e7cec0();
// 0x00e7cf00
void FUN_00e7cf00(void *);
