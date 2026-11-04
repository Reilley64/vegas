#pragma once

struct FUN_009a7f00_obj;
struct NiPoint3;
struct S_009a7670_P3;
struct SceneRef;
struct ShotActor;
struct SightReference;
struct TESObjectREFR;
struct Vec3;
struct Vec3Arg;

// 0x009a7580
unsigned char FUN_009a7580(void *, void *, ::FUN_009a7f00_obj *, ::NiPoint3 *, unsigned char *, ::S_009a7670_P3 *, float);
// 0x009a7670
bool FUN_009a7670(void *, void *, ::FUN_009a7f00_obj *, ::S_009a7670_P3, ::S_009a7670_P3, ::S_009a7670_P3, unsigned char *, ::S_009a7670_P3 *, float);
// 0x009a7940
bool FUN_009a7940(::SightReference *, ::SightReference *, const ::NiPoint3 &, const ::NiPoint3 &, int, int);
// 0x009a7c60
float ComputeLaunchAngle(float, float, float, float, bool);
// 0x009a7d50
void FUN_009a7d50(::SceneRef *, ::Vec3Arg, float, unsigned char);
// 0x009a7e00
float ComputeProjectileFlightTime(::ShotActor *, ::Vec3, ::Vec3, bool, float);
// 0x009a7f00
float FUN_009a7f00(::FUN_009a7f00_obj *, float);
// 0x009a7fa0
float GetScaleOrHeightDelta(::TESObjectREFR *, int);
