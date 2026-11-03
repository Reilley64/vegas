#pragma once

struct S00d386c0_CdBody;
struct S00d386c0_CdPointCollector;
struct S00d386c0_CollisionInput;
struct S_00d389f0_Dispatcher;
struct hkpCdBody;
struct hkpCdBodyPairCollector;

// 0x00d38130
void FUN_00d38130(const ::hkpCdBody &, const ::hkpCdBody &, const void *, ::hkpCdBodyPairCollector &);
// 0x00d386c0
void FUN_00d386c0(const ::S00d386c0_CdBody &, const ::S00d386c0_CdBody &, const ::S00d386c0_CollisionInput &, ::S00d386c0_CdPointCollector &);
// 0x00d389f0
void FUN_00d389f0(::S_00d389f0_Dispatcher *);
// 0x00d38ac0
void FUN_00d38ac0(void *, void *, void *, int);
// 0x00d38ed0
void FUN_00d38ed0(int, int, int, int);
