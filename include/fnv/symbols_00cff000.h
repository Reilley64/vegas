#pragma once

class ContactPointEvent;
class hkpConstraintOwnerCFT;
struct CFFCF0Owner;
struct Class_00cffab0;
struct ProfOwner;
struct ProfOwner_cffa00;
struct TaskOwner;
struct TrackSectors;
struct World833;
struct hkpAgentNnTrackCFF2;
struct hkpProcessCollisionInputCFT;

// 0x00cff290
void FUN_00cff290(::hkpAgentNnTrackCFF2 *, ::hkpAgentNnTrackCFF2 *);
// 0x00cff3c0
void FUN_00cff3c0(::hkpConstraintOwnerCFT *, ::TrackSectors &, const ::hkpProcessCollisionInputCFT &);
// 0x00cffa00
void FUN_00cffa00(::ProfOwner_cffa00 *);
// 0x00cffab0
void FUN_00cffab0(::Class_00cffab0 *);
// 0x00cffcf0
void FUN_00cffcf0(::CFFCF0Owner *);
// 0x00cffda0
void InvokeMotionTypeCallbacks(::TaskOwner *);
// 0x00cffe50
void DeleteCallbacks(::ProfOwner *);
// 0x00cfff00
void FUN_00cfff00(::World833 *, ::ContactPointEvent *);
// 0x00cfffb0
void FUN_00cfffb0(void *, void *);
