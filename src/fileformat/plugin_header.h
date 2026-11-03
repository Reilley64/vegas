#ifndef VEGAS_FILEFORMAT_PLUGIN_HEADER_H
#define VEGAS_FILEFORMAT_PLUGIN_HEADER_H

#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
#include <string>
#include <vector>

namespace fileformat
{

struct MasterFile
{
    std::string name;   // MAST
    std::uint64_t size; // DATA
};

// The TES4 record at the start of every plugin.
struct PluginHeader
{
    std::uint32_t flags;
    std::uint32_t formId;
    std::uint32_t versionControlInfo;
    std::uint16_t formVersion;
    std::uint16_t headerUnknown;

    // HEDR
    float version;
    std::uint32_t recordCount;
    std::uint32_t nextObjectId;

    std::optional<std::string> author;      // CNAM
    std::optional<std::string> description; // SNAM
    std::vector<MasterFile> masters;
    std::vector<std::uint32_t> overriddenForms; // ONAM
};

// Reads the plugin header from the start of a plugin file. Throws FormatError
// when the bytes are not a plugin header.
PluginHeader ReadPluginHeader(std::span<const std::byte> file);

std::vector<std::byte> WritePluginHeader(const PluginHeader& header);

} // namespace fileformat

#endif
