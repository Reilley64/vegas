#pragma once
#include <cstdint>

struct TreeChunk;

// 0x00dd8310
unsigned int GetMaxChunkSize(::TreeChunk *, uintptr_t);
