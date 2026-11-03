#pragma once

struct Se31d50_AnimParams;
struct Se31d50_PerTrack;
struct Se31d50_Raw;

struct Se31d50_Anim {
public:
    // 0x00e31d50
    void FUN_00e31d50(const ::Se31d50_Raw &, const ::Se31d50_PerTrack &, const ::Se31d50_AnimParams &);
};
