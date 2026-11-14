#include "havok/hkBaseSystem.h"
#include "havok/hkMonitorStream.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cbb000.h"

#include <memory>

namespace havok::base
{
namespace
{
Error* error = nullptr;
FileSystem* fileSystem = nullptr;
}
bool IsInitialized() { return error != nullptr && fileSystem != nullptr; }
Error* GetError() { return error; }
FileSystem* GetFileSystem() { return fileSystem; }
}

namespace fnv_00cbbb10
{
// @fnv 0x00cbbb10
int FUN_00cbbb10(hkMemoryRouter* router, havok::base::ErrorCallback callback, void* user)
{
    using namespace havok::base;
    if (IsInitialized())
        return 0;
    if (!router || !router->m_heap || !callback)
        return -1;
    auto release = [](Reference* owner) { if (owner) owner->RemoveReference(); };
    std::unique_ptr<FileSystem, decltype(release)> files(Reference::Create<FileSystem>(router->heap()), release);
    if (!files)
        return -1;
    std::unique_ptr<Error, decltype(release)> errors(Reference::Create<Error>(router->heap(), callback, user), release);
    if (!errors || FUN_00cbb930(router) != 0)
        return -1;
    fileSystem = files.release();
    error = errors.release();
    return 0;
}
}

// @fnv 0x00cbbcb0
int ShutdownIfInitialized()
{
    using namespace havok::base;
    if (!IsInitialized())
        return 0;
    Error* errors = std::exchange(error, nullptr);
    FileSystem* files = std::exchange(fileSystem, nullptr);
    if (errors)
        errors->RemoveReference();
    if (files)
        files->RemoveReference();
    FUN_00cbb990();
    return 0;
}

// @fnv 0x00cbb930
int FUN_00cbb930(void* value)
{
    void* previous = FUN_00c85750();
    if (previous != value && havok::base::GetMonitor())
        return -1;
    SetThreadLocalValue(value);
    try { fnv_00cb0db0::FUN_00cb0db0(); }
    catch (...) { SetThreadLocalValue(previous); throw; }
    return 0;
}

// @fnv 0x00cbb990
extern "C" int FUN_00cbb990()
{
    auto* monitor = havok::base::GetMonitor();
    if (monitor)
        fnv_00cb0df0::FUN_00cb0df0(monitor);
    SetThreadLocalValue(nullptr);
    return 0;
}
