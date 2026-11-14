#include "havok/hkBaseSystem.h"

namespace havok::base
{
File::File(hkMemoryAllocator& allocator, std::FILE* handle) : Reference(allocator), handle(handle)
{
    std::setvbuf(handle, buffer, _IOFBF, sizeof(buffer));
}
File::~File()
{
    if (handle)
        std::fclose(handle);
}
int File::Read(void* data, int bytes)
{
    if (!handle || bytes < 0)
        return 0;
    const int count = static_cast<int>(std::fread(data, 1, bytes, handle));
    if (count == 0)
        ok = false;
    return count;
}
int File::Write(const void* data, int bytes)
{
    if (!handle || bytes < 0)
        return 0;
    const int count = static_cast<int>(std::fwrite(data, 1, bytes, handle));
    if (count == 0)
    {
        ok = false;
        std::fclose(std::exchange(handle, nullptr));
    }
    return count;
}
bool File::Seek(long offset, int origin) { return !handle || std::fseek(handle, offset, origin) != 0; }
long File::Tell() const { return handle ? std::ftell(handle) : -1; }
File* FileSystem::Open(const char* name, const char* mode)
{
    if (!name)
        return nullptr;
    std::FILE* handle = std::fopen(name, mode);
    if (!handle)
        return nullptr;
    try
    {
        File* result = Reference::Create<File>(allocator, handle);
        if (!result)
            std::fclose(handle);
        return result;
    }
    catch (...) { std::fclose(handle); throw; }
}
File* FileSystem::OpenReader(const char* name) { return Open(name, "rb"); }
File* FileSystem::OpenWriter(const char* name) { return Open(name, "wb"); }
}
