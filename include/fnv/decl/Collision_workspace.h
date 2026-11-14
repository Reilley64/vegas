#pragma once

struct Collision_hit;
struct Collision_mat;
struct Collision_vcls;
struct Collision_vector;
struct SmallBool;

struct Collision_workspace {
public:
    // 0x00da9b30
    ::SmallBool FUN_00da9b30(::Collision_vcls *, ::Collision_vcls *, ::Collision_mat *, ::Collision_vector *, ::Collision_hit *);
};
