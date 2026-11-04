#pragma once

#include <cstdint>

class CCAA80Object;
struct MyObj;
struct OutS;

// 0x00ccaa30
void CopyHingeVectors(::MyObj *, intptr_t, ::OutS *);
// 0x00ccaa80
::CCAA80Object *CreateCCAA80Object();
