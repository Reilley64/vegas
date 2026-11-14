#include "check.h"
#include "fileformat/fixture.h"
#include "fileformat/plugin_header.h"

#include <format>
#include <string>

namespace
{

Fixture PluginHeaderFixture()
{
    Fixture f;
    f.Text("record type", "TES4");
    f.Bytes("record data size", {0x86, 0x00, 0x00, 0x00});
    f.Bytes("record flags", {0x01, 0x00, 0x00, 0x00});
    f.Bytes("record form ID", {0x00, 0x00, 0x00, 0x00});
    f.Bytes("record version control info", {0xF5, 0xA3, 0x12, 0x00});
    f.Bytes("record form version", {0x0F, 0x00});
    f.Bytes("record header unknown", {0x02, 0x00});

    f.Text("HEDR type", "HEDR").Bytes("HEDR size", {0x0C, 0x00});
    f.Bytes("HEDR version", {0x1F, 0x85, 0xAB, 0x3F});
    f.Bytes("HEDR record count", {0xFC, 0x24, 0x01, 0x00});
    f.Bytes("HEDR next object ID", {0x2B, 0x0A, 0xFF, 0x00});

    f.Text("CNAM type", "CNAM").Bytes("CNAM size", {0x0A, 0x00});
    f.Text("CNAM author", "mcarofano").Bytes("CNAM terminator", {0x00});

    f.Text("SNAM type", "SNAM").Bytes("SNAM size", {0x0C, 0x00});
    f.Text("SNAM description", "Test plugin").Bytes("SNAM terminator", {0x00});

    f.Text("first MAST type", "MAST").Bytes("first MAST size", {0x0E, 0x00});
    f.Text("first MAST name", "FalloutNV.esm").Bytes("first MAST terminator", {0x00});
    f.Text("first DATA type", "DATA").Bytes("first DATA size", {0x08, 0x00});
    f.Bytes("first DATA size value", {0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01});

    f.Text("second MAST type", "MAST").Bytes("second MAST size", {0x0E, 0x00});
    f.Text("second MAST name", "DeadMoney.esm").Bytes("second MAST terminator", {0x00});
    f.Text("second DATA type", "DATA").Bytes("second DATA size", {0x08, 0x00});
    f.Bytes("second DATA size value", {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00});

    f.Text("ONAM type", "ONAM").Bytes("ONAM size", {0x08, 0x00});
    f.Bytes("ONAM first form ID", {0xB2, 0xA1, 0x00, 0x01});
    f.Bytes("ONAM second form ID", {0xD4, 0xC3, 0x00, 0x01});
    return f;
}

fileformat::PluginHeader FixtureValues()
{
    fileformat::PluginHeader header{};
    header.flags = 0x00000001;
    header.formId = 0x00000000;
    header.versionControlInfo = 0x0012A3F5;
    header.formVersion = 15;
    header.headerUnknown = 2;
    header.version = 1.34f;
    header.recordCount = 75004;
    header.nextObjectId = 0x00FF0A2B;
    header.author = "mcarofano";
    header.description = "Test plugin";
    header.masters = {{"FalloutNV.esm", 0x0102030405060708}, {"DeadMoney.esm", 0}};
    header.overriddenForms = {0x0100A1B2, 0x0100C3D4};
    return header;
}

void ReadsTheFixture(Checks& check)
{
    const fileformat::PluginHeader expected = FixtureValues();
    const fileformat::PluginHeader header = fileformat::ReadPluginHeader(PluginHeaderFixture().Data());

    check.Equal("record flags", expected.flags, header.flags);
    check.Equal("record form ID", expected.formId, header.formId);
    check.Equal("record version control info", expected.versionControlInfo, header.versionControlInfo);
    check.Equal("record form version", expected.formVersion, header.formVersion);
    check.Equal("record header unknown", expected.headerUnknown, header.headerUnknown);
    check.Equal("HEDR version", expected.version, header.version);
    check.Equal("HEDR record count", expected.recordCount, header.recordCount);
    check.Equal("HEDR next object ID", expected.nextObjectId, header.nextObjectId);
    check.Equal<std::string>("CNAM author", *expected.author, header.author.value_or("(absent)"));
    check.Equal<std::string>("SNAM description", *expected.description, header.description.value_or("(absent)"));
    check.Equal("MAST count", expected.masters.size(), header.masters.size());
    for (std::size_t i = 0; i < expected.masters.size() && i < header.masters.size(); ++i)
    {
        check.Equal(std::format("MAST {} name", i), expected.masters[i].name, header.masters[i].name);
        check.Equal(std::format("MAST {} DATA size value", i), expected.masters[i].size, header.masters[i].size);
    }
    check.Equal("ONAM form ID count", expected.overriddenForms.size(), header.overriddenForms.size());
    for (std::size_t i = 0; i < expected.overriddenForms.size() && i < header.overriddenForms.size(); ++i)
        check.Equal(std::format("ONAM form ID {}", i), expected.overriddenForms[i], header.overriddenForms[i]);
}

void WritesTheFixture(Checks& check)
{
    CheckBytes(check, PluginHeaderFixture(), fileformat::WritePluginHeader(FixtureValues()));
}

} // namespace

int main()
{
    Checks check("plugin header");
    check.Run("read", [&] { ReadsTheFixture(check); });
    check.Run("write", [&] { WritesTheFixture(check); });
    return check.ExitCode();
}
