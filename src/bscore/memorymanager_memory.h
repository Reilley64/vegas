#pragma once

#include "fnv/decl/MemoryManager.h"
#include "fnv/ScrapHeapBuffer.h"
#include "MemoryPool.h"
#include "IMemoryHeap.h"
#include "layout_support.h"

extern MemoryManager g_memoryManager;
enum { kMinimumPoolBlockSize = 8, kPoolAddressRegionShift = 24 };
