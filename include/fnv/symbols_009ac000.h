#pragma once

struct NiPoint3;
struct TargetMatrix;
struct TargetRef;

// 0x009ac9c0
::TargetRef *CreateProjectileRef(void *, ::TargetRef *, ::TargetRef *, int, ::NiPoint3, ::TargetMatrix);
