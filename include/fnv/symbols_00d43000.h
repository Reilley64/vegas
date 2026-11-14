#pragma once

struct Agent;
struct CollisionAgentContext;
struct Input_d2e9;
struct S_00d43030_Agent;
struct S_00d43030_CdBody;
struct S_00d43030_CollisionInput;
struct S_00d43030_ContactMgr;
struct S_00d43dc0_CdBody;
struct S_00d43dc0_CdBodyPairCollector;
struct S_00d43dc0_CollisionInput;
class hkpCdBody;

// 0x00d43030
::S_00d43030_Agent *CreateTransformAgent(const ::S_00d43030_CdBody &, const ::S_00d43030_CdBody &, const ::S_00d43030_CollisionInput &, ::S_00d43030_ContactMgr *);
// 0x00d43120
void RegisterCallbacks(::Agent *);
// 0x00d432f0
void RunCollector(int, int, int, int);
// 0x00d43330
void RunSymmetricAgentFlipCollector(void *, void *, int, int);
// 0x00d43370
void FUN_00d43370(int, int, const ::Input_d2e9 *, int, int);
// 0x00d43960
void GetClosestPointsShapeCollection(const ::hkpCdBody *, const ::hkpCdBody *, const ::CollisionAgentContext *, void *);
// 0x00d43b90
void FUN_00d43b90(const ::hkpCdBody *, const ::hkpCdBody *, const ::CollisionAgentContext *, void *, void *);
// 0x00d43dc0
void FUN_00d43dc0(const ::S_00d43dc0_CdBody &, const ::S_00d43dc0_CdBody &, const ::S_00d43dc0_CollisionInput &, ::S_00d43dc0_CdBodyPairCollector &);
