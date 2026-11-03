#pragma once

struct FNV_Plane;
struct FNV_Proc;
struct FNV_Vec3;

struct FNV_Owner {
public:
    // 0x00c47150
    bool CheckProcStateAndPlane(::FNV_Vec3, ::FNV_Proc *, ::FNV_Plane *);
};
