#pragma once

struct AVObj;
struct Walker;

// 0x00b57420
void InitRenderSystem();
// 0x00b579e0
void UpdateShaderProperty(::AVObj *, bool, bool, bool);
// 0x00b57c60
void CopyMaterialPropertyRecursive(::Walker *);
