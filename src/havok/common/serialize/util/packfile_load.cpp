#include "havok/PackfileLoad.h"
#include <algorithm>
#include <cstring>
#include <limits>
#include <stdexcept>

namespace havok::serialize
{
std::size_t MemoryLoadStream::Read(std::span<std::byte> output)
{
    const auto count = std::min(output.size(), bytes.size() - position);
    if (count) std::memcpy(output.data(), bytes.data() + position, count);
    position += count;
    return count;
}
// Native reconstruction of the actual reader's seek/read and chunked-read
// branches. Storage is ordinary C++ ownership, not an allocator-layout view.
void FUN_00d48680(LoadStream& input, std::vector<std::byte>& buffer)
{
    constexpr auto maximum = static_cast<std::size_t>(std::numeric_limits<int>::max());
    if (input.CanSeek())
    {
        input.Seek(true);
        const auto bytes = input.Tell();
        if (bytes > maximum) throw std::length_error("packfile input too large");
        buffer.resize(bytes);
        input.Seek(false);
        std::size_t at = 0;
        while (at < bytes)
        {
            auto remaining = std::span(buffer).subspan(at);
            const auto read = input.Read(remaining);
            if (!read || read > remaining.size()) throw std::runtime_error("incomplete packfile stream");
            at += read;
        }
    }
    else
    {
        std::array<std::byte, 0x20000> chunk;
        for (;;)
        {
            const auto read = input.Read(chunk);
            if (read > chunk.size() || read > maximum - buffer.size()) throw std::length_error("invalid packfile stream size");
            if (!read) break;
            buffer.insert(buffer.end(), chunk.begin(), chunk.begin() + static_cast<std::ptrdiff_t>(read));
        }
    }
}
// True production caller extracted from hkserializeutil. The old typed body is
// removed there; its caller now supplies the retained deprecated capability.
Resource* FUN_00d48760(LoadStream& input, const LoadFormat& format, LoadError* error,
    const TypeRegistry& types, const LoadPolicy& policy) noexcept try
{
    if (format.type == 2)
    {
        if (format.layout != policy.layout)
        {
            if (error) { error->status = 3; error->message = "Packfile layout does not match the loader"; }
            return nullptr;
        }
        if (format.version == policy.version)
        {
            std::vector<std::byte> buffer;
            FUN_00d48680(input, buffer);
            return static_cast<Resource*>(CreateResourceFromArray(buffer.data(), reinterpret_cast<void*>(buffer.size()),
                const_cast<TypeRegistry*>(&types), error));
        }
    }
    if (policy.deprecated)
    {
        auto* resource = policy.deprecated(input, format, error);
        if (!resource && error && error->status == 0) error->set(3, "deprecated packfile construction rejected");
        return resource;
    }
    if (error) error->set(3, "packfile format/version has no supported loader");
    return nullptr;
}
catch (const std::exception& failure)
{
    if (error)
    {
        error->status = 3;
        try { error->message = failure.what(); } catch (...) { error->message.clear(); }
    }
    return nullptr;
}
catch (...)
{
    if (error)
    {
        error->status = 3;
        try { error->message = "packfile loading failed"; } catch (...) { error->message.clear(); }
    }
    return nullptr;
}
}
