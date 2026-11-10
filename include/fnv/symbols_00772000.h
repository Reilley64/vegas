#pragma once

struct NiPoint3;
namespace fnv_007728f0 { struct RegionDisplayInfo; }
struct HealthActor;
struct MarkerEvent772;
class NiAVObject;

// 0x007721a0
::NiAVObject *FUN_007721a0(char *);
// 0x00772840
float GetAngleBetweenPoints(const ::NiPoint3 &, const ::NiPoint3 &);
// 0x007728f0
namespace fnv_007728f0 { void ShowRegionData(const ::fnv_007728f0::RegionDisplayInfo *); }
// 0x00772aa0
void UpdateMapMarkerHUD(::MarkerEvent772 *);
// 0x00772c30
namespace fnv_00772c30 { void SetHoldText(const char *); }
// 0x00772d10
void UpdateTargetHealthHUD(::HealthActor *, unsigned char);
