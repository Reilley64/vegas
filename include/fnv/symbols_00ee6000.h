#pragma once
#include <cstdint>

struct D3DXIMAGE_INFO;
struct D3DXMACRO;
struct D3DXMATRIX;
struct D3DXPLANE;
struct D3DXVECTOR4;
struct EE6E40ConstantTable;
struct ID3DXBuffer;
struct ID3DXConstantTable;
struct ID3DXInclude;
struct in_addr;
struct sockaddr;

// 0x00ee6d9e
int FUN_00ee6d9e(unsigned int, int, int, const char *, int);
// 0x00ee6da4
char *FUN_00ee6da4(::in_addr);
// 0x00ee6daa
unsigned short FUN_00ee6daa(unsigned short);
// 0x00ee6db0
std::uintptr_t FUN_00ee6db0(std::uintptr_t, ::sockaddr *, int *);
// 0x00ee6db6
void FUN_00ee6db6();
// 0x00ee6dbc
void FUN_00ee6dbc();
// 0x00ee6dc2
void FUN_00ee6dc2();
// 0x00ee6dc8
::D3DXPLANE *FUN_00ee6dc8(::D3DXPLANE *, const ::D3DXPLANE *, const ::D3DXMATRIX *);
// 0x00ee6dce
void *FUN_00ee6dce(void *, const void *);
// 0x00ee6dd4
void FUN_00ee6dd4();
// 0x00ee6dda
void FUN_00ee6dda();
// 0x00ee6de0
void *FUN_00ee6de0(void *, const void *, const void *);
// 0x00ee6de6
int FUN_00ee6de6(void *, const void *, const void *, void *, const void *, const void *, unsigned int, unsigned int);
// 0x00ee6dec
void *FUN_00ee6dec(void *, const void *);
// 0x00ee6df2
void FUN_00ee6df2();
// 0x00ee6df8
void *FUN_00ee6df8(void *, const void *, const void *);
// 0x00ee6dfe
::D3DXMATRIX *FUN_00ee6dfe(::D3DXMATRIX *, const ::D3DXMATRIX *, const ::D3DXMATRIX *);
// 0x00ee6e04
void *FUN_00ee6e04(void *, unsigned int, unsigned int, unsigned int);
// 0x00ee6e0a
long FUN_00ee6e0a(const char *, unsigned int, const ::D3DXMACRO *, ::ID3DXInclude *, const char *, const char *, unsigned long, ::ID3DXBuffer **, ::ID3DXBuffer **, ::ID3DXConstantTable **);
// 0x00ee6e10
void FUN_00ee6e10();
// 0x00ee6e16
long FUN_00ee6e16(void *, const void *, unsigned int, void **);
// 0x00ee6e1c
int FUN_00ee6e1c(void *, const void *, unsigned int, void **);
// 0x00ee6e22
long FUN_00ee6e22(const void *, unsigned int, ::D3DXIMAGE_INFO *);
// 0x00ee6e28
long FUN_00ee6e28(void *, int);
// 0x00ee6e2e
void FUN_00ee6e2e();
// 0x00ee6e34
::D3DXVECTOR4 *FUN_00ee6e34(::D3DXVECTOR4 *, const ::D3DXVECTOR4 *, const ::D3DXMATRIX *);
// 0x00ee6e3a
long FUN_00ee6e3a(unsigned long, ::ID3DXBuffer **);
// 0x00ee6e40
long FUN_00ee6e40(const unsigned long *, ::EE6E40ConstantTable **);
// 0x00ee6e46
long FUN_00ee6e46(const char *, const ::D3DXMACRO *, ::ID3DXInclude *, const char *, const char *, unsigned long, ::ID3DXBuffer **, ::ID3DXBuffer **, ::ID3DXConstantTable **);
// 0x00ee6e4c
long FUN_00ee6e4c(const char *, const void *, void *, unsigned int, void **, void **);
// 0x00ee6e52
void FUN_00ee6e52();
