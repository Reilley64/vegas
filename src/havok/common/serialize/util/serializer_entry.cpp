#include "havok/Dictionary.h"
#include "fnv/decl/ReferencedObjectHolder.h"
#include <stdexcept>
#include <cstring>
#include <algorithm>
#include "havok/hkRootLevelContainer.h"
#include "havok/hkRootLevelContainerNamedVariant.h"

std::size_t havok::serialize::ReplayLoadStream::Read(std::span<std::byte> out)
{
    if (out.empty()) return 0;
    if (position < prefix.size())
    {
        const auto count = std::min(out.size(), prefix.size() - position);
        std::memcpy(out.data(), prefix.data() + position, count);
        position += count; return count;
    }
    const auto count = source.Read(out);
    if (count > out.size()) throw std::runtime_error("serializer stream exceeded requested extent");
    position += count; return count;
}
void havok::serialize::ReplayLoadStream::Seek(bool)
{
    throw std::runtime_error("sequential replay stream does not support seek");
}
// @fnv 0x00d48d30
S_Obj* FUN_00d48d30(havok::serialize::LoadStream* stream, havok::serialize::LoadError* error,
    const havok::serialize::SerializeOptions* options) noexcept
{
    using namespace havok::serialize;
    try
    {
        if (!stream || !options) throw std::invalid_argument("serializer requires stream and native domain");
        if (error) error->set(0, "");
        std::byte header[64]{};
        auto magic = std::span(header).first(8);
        std::size_t at = 0;
        while (at < magic.size())
        {
            const auto count = stream->Read(std::span(magic).subspan(at));
            if (!count || count > magic.size() - at) throw std::runtime_error("truncated serializer header");
            at += count;
        }
        ReplayLoadStream dictionaryInput(magic, *stream);
        if (magic[0] == std::byte{0x1e} && magic[1] == std::byte{0x0d} &&
            magic[2] == std::byte{0xb0} && magic[3] == std::byte{0xca})
        {
            auto dictionary = dictionary::Read(dictionaryInput);
            S_PH source(dictionary::Convert(dictionary, options->classes, options->types, AcquirePackfileSupplier()));
            S_Dom domain(options->classes);
            S_00dc4710_Cls builder(domain);
            return builder.FUN_00dc4710(&source, &options->types, error);
        }
        while (at < sizeof(header))
        {
            const auto count = stream->Read(std::span(header).subspan(at));
            if (!count || count > sizeof(header) - at) throw std::runtime_error("truncated packfile format header");
            at += count;
        }
        LoadFormat format;
        std::copy_n(header + 16, 4, format.layout.begin());
        const char* version = reinterpret_cast<const char*>(header + 40);
        const char* end = std::find(version, version + 16, '\0');
        if (end == version + 16) throw std::runtime_error("unterminated packfile version");
        format.version = std::string_view(version, std::size_t(end - version));
        ReplayLoadStream packfileInput(header, *stream);
        return FUN_00d48840(&packfileInput, format, error, &options->classes, &options->types, options->packfiles);
    }
    catch (const std::exception& failure)
    {
        if (error) try { error->set(3, failure.what()); } catch (...) {}
    }
    catch (...) { if (error) try { error->set(3, "serializer native construction failed"); } catch (...) {} }
    return nullptr;
}

// @fnv 0x00d48f00
S_Obj* fnv_00d48f00::FUN_00d48f00(std::span<const std::byte> bytes,
    havok::serialize::LoadError* error, const havok::serialize::SerializeOptions* options) noexcept
{
    havok::serialize::MemoryLoadStream stream(bytes);
    return FUN_00d48d30(&stream, error, options);
}

// @fnv 0x00cc0850
const void* FUN_00cc0850(havok::serialize::LoadStream* input, const havok::serialize::SerializeOptions* options,
    const hkClass* primary, S_Obj** owner, havok::serialize::LoadError* error) noexcept
{
    try
    {
        if (!owner)
            throw std::invalid_argument("root-container lookup requires output ownership");
        *owner = nullptr;
        if (!primary || !primary->m_name || !options)
            throw std::invalid_argument("root-container lookup requires native primary class and output ownership");
        std::unique_ptr<S_Obj> resource(FUN_00d48d30(input, error, options));
        if (!resource) return nullptr;
        auto root = resource->Root();
        const auto* expected = options->classes.Find("hkRootLevelContainer");
        if (!root || !expected || &root->Class() != expected || expected->m_iObjectSize != sizeof(hkRootLevelContainer))
            throw std::runtime_error("loaded root has no native hkRootLevelContainer contract");
        const auto* container = static_cast<const hkRootLevelContainer*>(root->Address());
        const auto& variants = container->m_kNamedVariants;
        if (variants.m_iElementCount < 0 || (variants.m_iElementCount && !variants.m_data))
            throw std::runtime_error("invalid native root-container variants");
        const void* found = nullptr;
        for (int i = 0; i < variants.m_iElementCount && !found; ++i)
        {
            const auto& variant = variants.m_data[i];
            ReferencedObjectHolder referenced{variant.m_pReferencedResource};
            const auto* registered = static_cast<const hkClass*>(referenced.FUN_00d477a0());
            const char* className = registered ? registered->m_name : variant.m_pClassName;
            if (className && std::strcmp(className, primary->m_name) == 0)
                found = variant.m_pReferencedResource;
        }
        for (const char* name : {"SnapshotSave", "hkpPhysicsData"})
            for (int i = 0; i < variants.m_iElementCount && !found; ++i)
            {
                const auto& variant = variants.m_data[i];
                if (variant.m_name && std::strcmp(variant.m_name, name) == 0) found = variant.m_pReferencedResource;
            }
        if (!found) throw std::runtime_error("root-container has no requested class or fallback name");
        *owner = resource.release(); // selected pointer shares the actual resource's cleanup owner
        return found;
    }
    catch (const std::exception& failure)
    {
        if (error) try { error->set(3, failure.what()); } catch (...) {}
    }
    catch (...) { if (error) try { error->set(3, "root-container lookup failed"); } catch (...) {} }
    return nullptr;
}
