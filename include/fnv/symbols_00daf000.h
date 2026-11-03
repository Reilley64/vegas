#pragma once

struct ContactCache;
struct ContactContext;
struct ContactManager;
struct ContactManifold;
struct ContactRecord;
struct IterativeSweep_hkpCdBody;
struct IterativeSweep_hkpCdPointCollector;
struct IterativeSweep_hkpLinearCastCollisionInput;
struct S_00dad4d0_Key;

// 0x00daf1e0
int FUN_00daf1e0(::ContactManifold *, void *, void *, void *, ::ContactContext *, ::S_00dad4d0_Key *, ::ContactRecord *, ::ContactCache *, ::ContactManager *, int);
// 0x00daf8e0
void FUN_00daf8e0(const ::IterativeSweep_hkpCdBody *, const ::IterativeSweep_hkpCdBody *, const ::IterativeSweep_hkpLinearCastCollisionInput *, ::IterativeSweep_hkpCdPointCollector *, ::IterativeSweep_hkpCdPointCollector *);
