#pragma once

class NavMesh;
struct IW;
struct USW;

// 0x00698060
int FindTriangleEdge(::NavMesh *, ::USW, ::IW, ::IW, ::IW, ::IW);
// 0x006985c0
void *ConstructWithVector(void *);
