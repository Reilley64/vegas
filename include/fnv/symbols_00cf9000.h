#pragma once

struct Context;
struct Entity;
struct hkpCdPointCollectorCF9;
struct hkpCollisionInputCF9;
struct hkpLinearCastInputCF9;

// 0x00cf92c0
void CollectLinearCast(::hkpLinearCastInputCF9 *, ::hkpCollisionInputCF9 *, ::hkpCdPointCollectorCF9 *);
// 0x00cf9c60
void FUN_00cf9c60(::Entity **, int, ::Context *);
