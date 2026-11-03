#pragma once

class NiPoint3;
namespace fnv_00bbba00 { struct ShaderTransform; }
struct DummyVTable;
struct Lighting30Packet4;
struct M_bbb890;
struct Obj_bbb890;

// 0x00bbb790
void ApplyLighting30Packet(const ::Lighting30Packet4 *, bool);
// 0x00bbb890
void UpdateTransformedPosition(::M_bbb890, ::Obj_bbb890 *);
// 0x00bbba00
namespace fnv_00bbba00 { void UpdateShaderMatrices(int, const ::fnv_00bbba00::ShaderTransform *); }
// 0x00bbbcf0
void UpdatePositionOffset(const ::NiPoint3 &);
// 0x00bbbda0
void FUN_00bbbda0(const char *);
// 0x00bbbdf0
void FUN_00bbbdf0(void *, int, char *);
// 0x00bbbe30
void FUN_00bbbe30(void *, int, ::DummyVTable *);
// 0x00bbbe80
namespace fnv_00bbbe80 { void UpdateFogPlanes(); }
