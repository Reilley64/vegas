#pragma once
#include <cstdint>

class Sdedf10_Vector4;
struct FourPointArray;
struct Obj;
struct Owner;
struct Sdedf10_Geometry;
struct Sdedf10_IFunction;
struct Sdedf10_TypeIsPod;
struct Vec4Array;
struct VertexArray;
template <class, class> struct Sdedf10_Array;

// 0x00dedbb0
bool FUN_00dedbb0(::Owner *, intptr_t, ::Vec4Array *, ::Obj *);
// 0x00dedcf0
void FUN_00dedcf0(const ::VertexArray &, ::FourPointArray &);
// 0x00dedf10
bool FUN_00dedf10(const ::Sdedf10_Geometry &, intptr_t, ::Sdedf10_Array< ::Sdedf10_Vector4, ::Sdedf10_TypeIsPod> &, intptr_t, int, const ::Sdedf10_IFunction *);
