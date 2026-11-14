#ifndef VEGAS_FILEFORMAT_PE_FILE_H
#define VEGAS_FILEFORMAT_PE_FILE_H

#include "fileformat/format_error.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
#include <string>
#include <vector>

namespace fileformat
{

// What makes bytes fail as a 32-bit x86 Windows executable whose version
// resource can be read. The checks up to EntryPoint run in the order listed,
// except that the data-directory count, checked after the magic, also reports
// OptionalHeaderSize. The section checks, SectionOutOfFile to
// DuplicateSectionName, run in that order for each section in turn, so a
// problem in an earlier section is reported before any problem in a later
// one. The resource problems, after EntryPoint, are reported in the order the
// resource is walked: the directory, the type table, the name table, the
// language table, the data entry, the data and the VS_VERSIONINFO.
enum class PeProblem
{
    DosHeaderTruncated,       // fewer bytes than the 64-byte MS-DOS header
    DosMagic,                 // does not start with MZ
    PeHeaderTruncated,        // the PE signature and file header do not fit after their offset
    PeSignature,              // not PE and two zero bytes
    Machine,                  // not x86 (0x14C); every executable this project builds is 64-bit
    SectionCount,             // the file header counts no section, or more than the 96 Windows loads
    OptionalHeaderSize,       // too small for the PE32 fields and its data directories, or past the end
    OptionalHeaderMagic,      // not PE32 (0x10B)
    SectionTableTruncated,    // the section table runs past the end of the file
    SectionOutOfFile,         // a section's stored bytes start or end after the end of the file
    SectionVirtualSize,       // a section has bytes in the file but a virtual size of 0
    SectionBeyondSizeOfImage, // a section ends in memory after SizeOfImage
    SectionOrder,             // a section does not start in memory at or after the end of the one before
    DuplicateSectionName,     // two sections have the same name
    EntryPoint,               // the entry point is in no section
    NoVersionResource,        // no resource directory, or no resource of type 16 in it
    ResourceMalformed,        // a directory, entry or the data runs outside the stored bytes, or is nested wrongly
    VersionResourceAmbiguous, // more than one version resource or language
    VersionInfo,              // the data is not a VS_VERSIONINFO with a VS_FIXEDFILEINFO
};

// A FormatError that also says which check failed.
class PeError : public FormatError
{
  public:
    PeError(PeProblem problem, const std::string& message) : FormatError(message), problem(problem) {}

    PeProblem Problem() const { return problem; }

  private:
    PeProblem problem;
};

// One section header, with what it means for memory. Addresses are relative
// to the image base.
struct PeSection
{
    std::string name;              // up to 8 bytes, ending before the first zero byte
    std::uint32_t virtualAddress;  // where the section starts in memory
    std::uint32_t virtualSize;     // its bytes in memory
    std::uint32_t rawOffset;       // where its bytes start in the file
    std::uint32_t rawSize;         // its bytes in the file, as stored (usually rounded up to the file alignment)
    std::uint32_t storedBytes;     // the lesser of rawSize and virtualSize: the bytes of memory the file supplies
    std::uint32_t zeroBytes;       // virtualSize - storedBytes: the zero-initialised tail
    std::uint32_t characteristics; // as stored
};

// A 32-bit x86 Windows executable whose headers, sections and version
// resource were read. Section bytes are offered as stored and never changed:
// nothing is decompressed or decrypted.
//
// This identifies nothing by itself: a file version can be written into any
// executable. IdentifyOriginal compares the file version and a digest with
// the supported set.
struct PeFile
{
    std::uint32_t imageBase;                     // as stored
    std::uint32_t entryPoint;                    // relative to the image base
    std::size_t entrySection;                    // index of the section that holds the entry point
    bool steamStub;                              // the entry point is in a section named .bind
    std::array<std::uint16_t, 4> fileVersion;    // major, minor, patch, build, from VS_FIXEDFILEINFO
    std::array<std::uint16_t, 4> productVersion; // the same, for the product
    std::vector<PeSection> sections;             // in section table order
    std::vector<std::byte> bytes;                // the whole file

    // The section's first storedBytes bytes of the file. The span points into
    // `bytes`, so it is not offered on a temporary.
    std::span<const std::byte> StoredBytes(const PeSection& section) const&
    {
        return std::span<const std::byte>(bytes).subspan(section.rawOffset, section.storedBytes);
    }
    std::span<const std::byte> StoredBytes(const PeSection& section) const&& = delete;
};

// Reads the headers, the section table and the version resource of a 32-bit
// x86 Windows executable and takes ownership of its bytes. Throws PeError
// when the bytes are not one, or its version resource cannot be read. A
// 64-bit executable, such as the one this project builds for windows-x64, is
// refused with PeProblem::Machine.
PeFile ParsePeFile(std::vector<std::byte> file);

} // namespace fileformat

#endif
