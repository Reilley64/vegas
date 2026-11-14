// bscore/scrapheap_decls.h: declares ScrapHeapBuffer, ScrapHeapManager, Entry, MemoryManager

#include <windows.h>
#include "fnv/ScrapHeapBuffer.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/StateMachine.h"
#include "fnv/symbols_00aa5000.h"
#include "fnv/symbols_011f6000.h"
class ScrapHeapManager;

class RecursiveSpinLock
{
  public:
    unsigned int lockWord;
    unsigned int listCount;
};

class ScrapHeapManager
{
  public:
    struct Entry
    {
        char* buffer;
        unsigned int size;
    };

    Entry entries[64];
    unsigned int count;
    unsigned int totalSize;
    unsigned char padding[0x18];
    RecursiveSpinLock bufferLock;

    static ScrapHeapManager& Instance();
    void RemoveEntry(unsigned int index);
};

class IMemoryHeap;

class MemoryManager
{
  public:
};
