#pragma once

struct CellInput;
struct LockedRect;
struct RenderData;

// 0x00547830
int CreateAndClearRenderTarget(::CellInput *, ::RenderData **, ::LockedRect **);
