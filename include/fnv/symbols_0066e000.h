#pragma once

class ActorValueOwner;
class E6D0SaveBuffer;
namespace ActorValue { enum Index; }
namespace ActorValue { enum Section; }
struct BGSLoadGameBuffer;
struct DetectionViewData;
struct FUN_0066eea0_Object;

// 0x0066e100
void FUN_0066e100(unsigned int);
// 0x0066e330
::DetectionViewData *FindStateByValue(int);
// 0x0066e6d0
void SaveE6D0Items(::E6D0SaveBuffer *);
// 0x0066e750
void FUN_0066e750(::BGSLoadGameBuffer *);
// 0x0066e810
void UpdateOrRemoveItems(int);
// 0x0066e920
void *FUN_0066e920(int);
// 0x0066e950
namespace ActorValue { const char *GetActorValueName(::ActorValue::Index); }
// 0x0066e9b0
const char *GetActorValueDescription(::ActorValue::Index);
// 0x0066e9f0
const char *FUN_0066e9f0(::ActorValue::Index);
// 0x0066ea20
const char *GetWeaponSkillIconPath(int);
// 0x0066eac0
const char *FUN_0066eac0(::ActorValue::Index);
// 0x0066eb00
const char *FUN_0066eb00(::ActorValue::Index);
// 0x0066eb40
int FindEntryIndexByName(const char *);
// 0x0066ec10
namespace ActorValue { ::ActorValue::Index GetActorValueForSectionIndex(::ActorValue::Section, char); }
// 0x0066ec80
namespace ActorValue { unsigned char ToArrayIndex(int, ::ActorValue::Index); }
// 0x0066ecf0
namespace ActorValue { unsigned int GetCountForSection(::ActorValue::Section); }
// 0x0066ed60
namespace ActorValue { bool TryGetActorValue(::ActorValueOwner *, ::ActorValue::Index, float &); }
// 0x0066ee10
namespace ActorValue { bool HasActorValueChangedCallback(::ActorValue::Index); }
// 0x0066ee50
namespace ActorValue { void NotifyActorValueChanged(::ActorValueOwner *, ::ActorValue::Index, float, float, ::ActorValueOwner *); }
// 0x0066eea0
float FUN_0066eea0(::FUN_0066eea0_Object *, int, float);
// 0x0066efd0
void FUN_0066efd0(int);
