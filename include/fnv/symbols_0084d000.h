#pragma once
#include <cstdint>

#include <cstdint>

class NiTexture;
class SaveLoadFile;
struct HeaderFile;

// 0x0084d4b0
void FUN_0084d4b0(::HeaderFile *);
// 0x0084d8c0
int ReadSaveHeader(::SaveLoadFile *);
// 0x0084da90
char *GetCombinedValue(std::intptr_t);
// 0x0084dab0
void ReadSaveFileHeader(void *, void *);
// 0x0084dda0
::NiTexture *LoadScreenshotTexture(::SaveLoadFile *, unsigned int, unsigned int, unsigned int);
