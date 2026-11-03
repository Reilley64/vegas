#pragma once

class ShadowSceneLight;
namespace fnv_00b70de0 { struct WaterStub; }
struct Dummy_00b70290;
struct FUN_00b70600_list;
struct FUN_00b70600_node;
struct FUN_00b70600_obj;
struct FUN_00b70790_owner;
struct Light_b70700;
struct ListItem_b70700;
struct List_00b702e0;
struct Node_00b702e0;
struct Node_00b70340;
struct Obj_00b70340;
struct WaterStub;
template <class> class NiTListItem;

// 0x00b70260
void FUN_00b70260();
// 0x00b70290
void FUN_00b70290(::Dummy_00b70290 *, int, int);
// 0x00b702e0
void MoveNodeBefore(::List_00b702e0 *, int, ::Node_00b702e0 *, ::Node_00b702e0 *);
// 0x00b70340
bool FindNodeByItemValue(::Obj_00b70340 *, int, void *, int, ::Node_00b70340 **);
// 0x00b70600
::FUN_00b70600_obj *FUN_00b70600(::FUN_00b70600_list *, int, ::FUN_00b70600_node **);
// 0x00b70680
::ShadowSceneLight *FUN_00b70680(::NiTListItem< ::ShadowSceneLight *> *&);
// 0x00b70700
::Light_b70700 *FUN_00b70700(::ListItem_b70700 *&);
// 0x00b70790
unsigned int FUN_00b70790(::FUN_00b70790_owner *);
// 0x00b707d0
int FUN_00b707d0(void *);
// 0x00b70820
void UpdateWaterTint(unsigned int, ::WaterStub *, float);
// 0x00b70de0
namespace fnv_00b70de0 { void ApplyWaterLighting(unsigned int, ::fnv_00b70de0::WaterStub *, float); }
