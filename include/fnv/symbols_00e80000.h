#pragma once

struct ArrayElementE80390;
struct ModelMatrix3;
struct ModelPoint3;
struct ModelRendererView;
struct ModelXformState;

// 0x00e80020
void *FUN_00e80020(void *, int, unsigned int, unsigned int);
// 0x00e80150
namespace fnv_00e80150 { void FUN_00e80150(); }
// 0x00e80390
::ArrayElementE80390 *FUN_00e80390(unsigned int);
// 0x00e803f0
void ClearSpawnedObject();
// 0x00e80570
void FUN_00e80570();
// 0x00e80620
void FUN_00e80620();
// 0x00e80630
void FUN_00e80630();
// 0x00e80690
void ResetGlobalString();
// 0x00e80860
void SetShadowWorldView(const ::ModelMatrix3 *, const ::ModelPoint3 *, ::ModelXformState *, bool, const ::ModelRendererView *);
// 0x00e80a50
void FUN_00e80a50(const ::ModelMatrix3 *, const ::ModelPoint3 *, ::ModelXformState *, bool, const ::ModelRendererView *);
// 0x00e80c50
void UpdateWorldViewMatrix(const ::ModelMatrix3 *, const ::ModelPoint3 *, ::ModelXformState *, bool, const ::ModelRendererView *);
// 0x00e80de0
void SetWorldViewFromShadow(const ::ModelMatrix3 *, const ::ModelPoint3 *, ::ModelXformState *, bool, const ::ModelRendererView *);
// 0x00e80f70
void SetWorldViewMatrix(const ::ModelMatrix3 *, const ::ModelPoint3 *, ::ModelXformState *, bool, const ::ModelRendererView *);
