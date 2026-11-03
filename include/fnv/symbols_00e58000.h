#pragma once
#include <cstdint>

class CE588A0Vector;
class E87E0Matrix;
namespace fnv_00e589e0 { struct FUN_00e587b0_Class; }
struct E589Destination;
struct E589ScaledValues;
struct E589Values;
struct E58E80Object;
struct FUN_00e587b0_Class;
struct FUN_00e58880_Class;
struct Float4;
struct S00e58310_Point;
struct SolverMatrix;
struct SolverVector;
template <class> struct S00e58310_Array;

// 0x00e58310
void FUN_00e58310(int, const ::S00e58310_Array< ::S00e58310_Point> &, const ::S00e58310_Array<float> &, int, float, int &, ::S00e58310_Array<float> &, ::S00e58310_Array< ::S00e58310_Point> &);
// 0x00e58440
void FUN_00e58440(int, const float *, const ::Float4 *, int, float, int *, float *, int *, ::Float4 *);
// 0x00e58740
void FUN_00e58740(int, intptr_t, intptr_t, int, float, intptr_t, intptr_t, intptr_t, intptr_t);
// 0x00e588a0
float DotProduct(::CE588A0Vector *, ::CE588A0Vector *);
// 0x00e58900
void FUN_00e58900(::E589Destination *, ::E589Values *, const float *, ::E589ScaledValues *);
// 0x00e58960
void FUN_00e58960(::FUN_00e587b0_Class *, float *, ::FUN_00e58880_Class *);
// 0x00e589a0
void FUN_00e589a0(::FUN_00e587b0_Class *, ::FUN_00e58880_Class *);
// 0x00e589e0
namespace fnv_00e589e0 { void NegateElements(::fnv_00e589e0::FUN_00e587b0_Class *); }
// 0x00e58e80
::E87E0Matrix *FUN_00e58e80(intptr_t, intptr_t, ::E58E80Object *, const ::E87E0Matrix &);
// 0x00e58f10
bool *ConjugateGradientSolve(bool *, ::SolverMatrix *, ::SolverVector *, ::SolverVector *, int, float);
