#pragma once

class ReworkPoint;
struct Point;
struct Pt3;
struct ReworkBox;

// 0x00ea3950
bool FUN_00ea3950(float, const void *, const void *, const void *, const void *, float *, ::Pt3 *, bool, ::Pt3 *, ::Pt3 *);
// 0x00ea3c50
bool FUN_00ea3c50(float, const void *, const void *, const void *, const void *, float *, ::Point *, bool, ::Point *, ::Point *);
// 0x00ea3d60
bool FUN_00ea3d60(float, const ::ReworkBox &, const ::ReworkPoint &, const ::ReworkPoint &, const ::ReworkPoint &, const ::ReworkPoint &, const ::ReworkPoint &, float &, ::ReworkPoint &, bool, ::ReworkPoint &, ::ReworkPoint &);
