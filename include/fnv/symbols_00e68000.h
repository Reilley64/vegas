#pragma once

struct CopyPixels;
struct CopySurface;
struct FnvDevice;
struct FnvOutput;
struct FnvSource;
struct TextureAccessor;

// 0x00e68150
void FUN_00e68150(::CopyPixels *, unsigned int, ::CopySurface *, unsigned int);
// 0x00e683d0
void FUN_00e683d0(::TextureAccessor *, unsigned int, ::CopySurface *, unsigned int);
// 0x00e68ef0
::FnvOutput *FUN_00e68ef0(::FnvSource *, ::FnvDevice *);
