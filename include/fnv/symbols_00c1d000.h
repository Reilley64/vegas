#pragma once
#include <cstdint>

class NiD3DPass;
struct Arg3Obj;
struct Arg4Obj;
struct Arg5Obj;
struct NiPoint3;
template <class> class NiPointer;

// 0x00c1d230
void SkinVertex(::NiPoint3 *, ::NiPoint3 *, ::Arg3Obj *, ::Arg4Obj *, ::Arg5Obj *, intptr_t);
// 0x00c1d790
namespace sc1d790 { ::NiPointer< ::NiD3DPass> *FUN_00c1d790(unsigned int); }
