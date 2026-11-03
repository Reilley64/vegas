#pragma once

enum S5ba30_Result;
struct ByteFlag;
struct Edges;
struct FUN_00dd0530;
struct S5ba30_ConstraintInstance;
struct S5ba30_Entity;
template <class> struct ChainArray;
template <class> struct S5ba30_Array;

// 0x00e5b510
::FUN_00dd0530 *FUN_00e5b510(::Edges &, ::ByteFlag);
// 0x00e5b830
void CollectConnectedNodesAndEdges(::ChainArray<void *> *, void *, ::ChainArray<void *> *, ::ChainArray<void *> *);
// 0x00e5ba30
::S5ba30_Result FUN_00e5ba30(const ::S5ba30_Array< ::S5ba30_ConstraintInstance *> &, ::S5ba30_Entity *, ::S5ba30_Entity *, ::S5ba30_Array< ::S5ba30_Entity *> &, ::S5ba30_Array< ::S5ba30_ConstraintInstance *> &);
