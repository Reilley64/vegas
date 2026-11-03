// gamebryo2.2/corelibs/nimain/nirefobject.cpp: NiRefObject, ScrapHeapTaskQueue (2 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "NiRefObject.h"
#pragma optimize("gty", on)
// @fnv 0x00cfcc20
void NiRefObject::DeleteThis()
{
    delete this;
}
#pragma optimize("", off)
#include "nirefobject_queue.h"
// Acquires the lock, enqueues command, releases the lock, and returns the enqueue result.
// @fnv 0x009054a0
bool ScrapHeapTaskQueue::QueueCall(void* command)
{
    bool result;
    while (true)
    {
        if (FUN_0043b460(&lock, 0, 1) == 0)
        {
            reinterpret_cast<void(__cdecl*)()>(&((void (&)(BGSLoadGameBuffer *))::FUN_0040fbe0))();
            result = Enqueue(command);
            reinterpret_cast<void(__cdecl*)()>(&((void (&)(BGSLoadGameBuffer *))::FUN_0040fbe0))();
            FUN_0043b460(&lock, 1, 0);
            break;
        }
    }
    return result;
}
