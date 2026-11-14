#pragma once

struct LongRayBool;
struct LongRayCode;
struct LongRayInput;
struct LongRayQueryFloat;
struct LongRayQueryInt;
struct MoppCode;
struct RayCollector;
struct RayInput;

struct LongRayVm {
public:
    // 0x00dd1f30
    void FUN_00dd1f30(const ::LongRayQueryInt *, const unsigned char *, ::LongRayQueryFloat *, int);
    // 0x00dd2df0
    ::LongRayBool FUN_00dd2df0(const void *, const ::LongRayCode *, const ::LongRayInput &, void *);
    // 0x00dd2ed0
    void FUN_00dd2ed0(const void *, const ::MoppCode *, const ::RayInput &, const void *, ::RayCollector *);
};
