#pragma once

class TESActorBase;
namespace fnv_00657010 { struct NiAVObject; }
struct QueryObject;
struct QueuedFile;
struct _vec_60;

// 0x00657010
namespace fnv_00657010 { void SetGeometryCompressFlags(::fnv_00657010::NiAVObject *, unsigned int, unsigned int); }
// 0x006570e0
void FUN_006570e0(::QueryObject *);
// 0x00657150
void QueueFaceGenAssets(::TESActorBase *, int, ::QueuedFile *);
// 0x00657a30
unsigned int FUN_00657a30(const ::_vec_60 *);
// 0x00657bc0
int FUN_00657bc0(int);
