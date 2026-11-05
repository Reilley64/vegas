#include "havok/hkBaseSystem.h"

#include <algorithm>
#include <cstdio>

namespace havok::base
{
// @fnv 0x00d2b640
Error::Error(hkMemoryAllocator& allocator, ErrorCallback callback, void* user)
    : Reference(allocator), resource(allocator), disabled(&resource), sections(&resource),
      callback(callback), user(user) {}

bool Error::IsEnabled(int id) const
{
    return std::find(disabled.begin(), disabled.end(), id) == disabled.end();
}
void Error::SetEnabled(int id, bool enabled)
{
    auto found = std::find(disabled.begin(), disabled.end(), id);
    if (enabled && found != disabled.end())
        disabled.erase(found);
    else if (!enabled && found == disabled.end())
        disabled.push_back(id);
}
void Error::EnableAll() { disabled.clear(); }
void Error::BeginSection(int id, const char*) { sections.push_back(id); }
void Error::EndSection()
{
    if (!sections.empty())
        sections.pop_back();
}
int Error::Message(int mode, int id, const char* message, const char* file, int line)
{
    if (id == -1 && !sections.empty())
        id = sections.back();
    if (!IsEnabled(id))
        return 0;
    const char* kind = "";
    switch (mode)
    {
    case 0: kind = "Report"; break;
    case 1: kind = "Warning"; break;
    case 2: kind = "Assert"; break;
    case 3: kind = "Error"; break;
    }
    char buffer[2048];
    if (id == 0 && !file)
        std::snprintf(buffer, sizeof(buffer), "%s\n", message);
    else
        std::snprintf(buffer, sizeof(buffer), "%s(%d): [0x%08X] %s : %s\n",
            file ? file : "", line, static_cast<unsigned int>(id), kind, message);
    buffer[sizeof(buffer) - 1] = '\0';
    callback(buffer, user);
    // Stack capture is a native external boundary, not a legacy tracer receiver.
    if (mode == 2 || mode == 3)
    {
        extern void WriteStackTrace(ErrorCallback, void*);
        WriteStackTrace(callback, user);
        return 1;
    }
    return 0;
}
}
