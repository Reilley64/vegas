#pragma once
#include <cstdint>

struct AxisData;
struct E0C150Stream;
struct FUN_00e0d000;
struct PixelSource;
struct S_Flag;
struct Se0e0c0_FrameInfo;
struct Se0e0c0_Input;
struct Se0e0c0_Node;
struct Se0e0c0_SampleInfo;
template <class> struct Se0e0c0_Array;
template <class> struct Se0e0c0_ArrayBase;

// 0x00e0e0c0
void FUN_00e0e0c0(const ::Se0e0c0_ArrayBase< ::Se0e0c0_Node *> &, const ::Se0e0c0_Input &, ::Se0e0c0_ArrayBase< ::Se0e0c0_Array< ::Se0e0c0_FrameInfo>> &, int *&, int &, ::Se0e0c0_SampleInfo *);
// 0x00e0e470
void FUN_00e0e470(intptr_t, ::PixelSource *, intptr_t, ::E0C150Stream *, intptr_t);
// 0x00e0e630
::FUN_00e0d000 *FUN_00e0e630(const char *, const char *, ::AxisData *, const char *, ::S_Flag);
