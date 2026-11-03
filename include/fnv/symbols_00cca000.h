#pragma once

class CCAA80Object;
struct MyObj;
struct OutS;

// 0x00ccaa30
void CopyHingeVectors(::MyObj *, int, ::OutS *);
// 0x00ccaa80
::CCAA80Object *CreateCCAA80Object();
