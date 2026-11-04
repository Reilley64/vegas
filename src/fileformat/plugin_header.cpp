#include "fileformat/plugin_header.h"

#include "fileformat/byte_reader.h"
#include "fileformat/byte_writer.h"

#include <limits>

namespace fileformat
{

namespace
{

constexpr std::string_view format = "plugin header";

struct Subrecord
{
    std::string_view type;
    ByteReader data;
};

Subrecord ReadSubrecord(ByteReader& record)
{
    const std::string_view type = record.Tag("subrecord type");
    return {type, record.Sub(record.U16("subrecord size"), type)};
}

void WriteSubrecord(ByteWriter& record, std::string_view type, const ByteWriter& data)
{
    if (data.Size() > std::numeric_limits<std::uint16_t>::max())
        throw FormatError(std::string(format) + ": " + std::string(type) + ": is longer than 65535 bytes");
    record.Text(type);
    record.U16(static_cast<std::uint16_t>(data.Size()));
    record.Append(data.Bytes());
}

} // namespace

PluginHeader ReadPluginHeader(std::span<const std::byte> file)
{
    ByteReader record(file, format);
    if (record.Tag("record type") != "TES4")
        record.Fail("record type", "is not TES4");
    const std::uint32_t dataSize = record.U32("record data size");

    PluginHeader header{};
    header.flags = record.U32("record flags");
    header.formId = record.U32("record form ID");
    header.versionControlInfo = record.U32("record version control info");
    header.formVersion = record.U16("record form version");
    header.headerUnknown = record.U16("record header unknown");

    ByteReader data = record.Sub(dataSize, "record data");
    bool hasHedr = false;
    while (!data.AtEnd())
    {
        auto [type, field] = ReadSubrecord(data);
        if (type == "HEDR")
        {
            header.version = field.F32("HEDR version");
            header.recordCount = field.U32("HEDR record count");
            header.nextObjectId = field.U32("HEDR next object ID");
            field.Finish("HEDR");
            hasHedr = true;
        }
        else if (type == "CNAM")
            header.author = field.ZString("CNAM author");
        else if (type == "SNAM")
            header.description = field.ZString("SNAM description");
        else if (type == "MAST")
        {
            MasterFile& master = header.masters.emplace_back();
            master.name = field.ZString("MAST name");
            auto [sizeType, size] = ReadSubrecord(data);
            if (sizeType != "DATA")
                data.Fail("MAST", "is not followed by DATA");
            master.size = size.U64("DATA size value");
            size.Finish("DATA");
        }
        else if (type == "ONAM")
        {
            while (!field.AtEnd())
                header.overriddenForms.push_back(field.U32("ONAM form ID"));
        }
        else
            data.Fail(type, "is not a plugin header subrecord");
    }
    if (!hasHedr)
        data.Fail("HEDR", "is missing");
    return header;
}

std::vector<std::byte> WritePluginHeader(const PluginHeader& header)
{
    ByteWriter data;

    ByteWriter hedr;
    hedr.F32(header.version);
    hedr.U32(header.recordCount);
    hedr.U32(header.nextObjectId);
    WriteSubrecord(data, "HEDR", hedr);

    if (header.author)
    {
        ByteWriter cnam;
        cnam.ZString(*header.author);
        WriteSubrecord(data, "CNAM", cnam);
    }
    if (header.description)
    {
        ByteWriter snam;
        snam.ZString(*header.description);
        WriteSubrecord(data, "SNAM", snam);
    }
    for (const MasterFile& master : header.masters)
    {
        ByteWriter mast;
        mast.ZString(master.name);
        WriteSubrecord(data, "MAST", mast);
        ByteWriter size;
        size.U64(master.size);
        WriteSubrecord(data, "DATA", size);
    }
    if (!header.overriddenForms.empty())
    {
        ByteWriter onam;
        for (std::uint32_t form : header.overriddenForms)
            onam.U32(form);
        WriteSubrecord(data, "ONAM", onam);
    }

    ByteWriter record;
    record.Text("TES4");
    record.U32(static_cast<std::uint32_t>(data.Size()));
    record.U32(header.flags);
    record.U32(header.formId);
    record.U32(header.versionControlInfo);
    record.U16(header.formVersion);
    record.U16(header.headerUnknown);
    record.Append(data.Bytes());
    return record.Take();
}

} // namespace fileformat
