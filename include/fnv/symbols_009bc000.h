#pragma once

struct NiPoint3;
struct P062Ammo;
struct P062Object;

// 0x009bca60
::P062Object *CreateProjectile(::P062Ammo *, ::P062Object *, ::P062Object *, ::P062Object *, ::NiPoint3, float, float, void *, int, bool, bool, float, float, void *);
