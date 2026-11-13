#ifndef VEGAS_SETUP_PREPARE_PACK_H
#define VEGAS_SETUP_PREPARE_PACK_H

#include "fileformat/pack_validation.h"

#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>

// Setup's preparation of a data pack from the executable of an original
// release (ADR 0001; VEGAS-13; docs/setup.md).
namespace setup
{

// Why a field cannot be read from an identified executable as stored. The
// fields are checked in catalogue order, C1's four and then the main window
// class's, so a problem of an earlier field is reported first.
//
// For a C1 field the problems NoSection to KnownString are checked in the
// order listed. The main window class's string is reached through a stored
// pointer: NoSection to ZeroTail are checked for the four bytes of the
// pointer ("class name pointer" in the message), then RelocationTable and
// NoRelocation, then for the string it points to ("class name string")
// NoSection to NotInitializedData, WritableSection, ZeroTail and
// NoTerminator.
enum class ExtractProblem
{
    NoSection,          // no section holds the field's first byte in memory, or it is below the image base
    SteamStubSection,   // the section is .bind, SteamStub's
    CodeSection,        // the section is marked as code or as executable
    NotInitializedData, // the section is not marked as initialized data
    ZeroTail,           // the field's bytes run past the section's stored bytes, into its zero tail or beyond
    NoTerminator,       // no zero byte within the field's capacity
    KnownString,        // the string is not the text of the recipe literal at its address
    RelocationTable,    // the base relocation table is not stored in one section, or a block of it is malformed
    NoRelocation,       // no 32-bit (HIGHLOW) base relocation covers the pointer
    WritableSection,    // the pointer's target is in a section marked as writable, not read-only
};

// Thrown when a field cannot be read. The message names the field.
class ExtractError : public std::runtime_error
{
  public:
    ExtractError(ExtractProblem problem, const std::string& message) : std::runtime_error(message), problem(problem) {}

    ExtractProblem Problem() const { return problem; }

  private:
    ExtractProblem problem;
};

// Thrown when the pack setup wrote is refused by the check that follows the
// writing. Setup writes only what the validator accepts, so this is a defect
// of setup, not of the executable.
class StagedPackError : public std::logic_error
{
  public:
    using std::logic_error::logic_error;
};

// A data pack as setup prepared it: the bytes to install and the values the
// complete validator decoded from them.
struct PreparedPack
{
    std::vector<std::byte> bytes;
    fileformat::ValidatedPack validated;
};

// Prepares the data pack of catalogue version 2 from the bytes of an
// executable. In order:
//
// 1. fileformat::ParsePeFile; throws fileformat::PeError. A 64-bit
//    executable, such as the one this project builds, is refused there.
// 2. The SHA-256 of the bytes it parsed, in one operation.
// 3. fileformat::IdentifyOriginal against the source's supported set;
//    throws fileformat::UnsupportedOriginalError.
// 4. Reads C1's four fields at the recipe ranges of
//    single_instance_ranges.h, then the main window class through the
//    pointer of main_window_class_range.h; throws ExtractError. Each string
//    is copied through its first zero byte and its field is filled with
//    zeros: no byte after the zero byte is copied.
// 5. fileformat::WritePackStructure with the identified original.
// 6. fileformat::ValidatePack of the written bytes; throws StagedPackError.
//
// No set is a parameter: the supported set is the source's, and no form of
// this function under src/ takes one. The tests run steps 1 to 5 against a
// set of their own, through staged_pack.h, never step 6. Nothing is
// decrypted. Strings and the pointer are read only from the stored bytes of
// a data section; the base relocation table is read where the header's data
// directory places it, in the stored bytes of one section.
// An allocation failure throws the standard exceptions.
PreparedPack PrepareDataPack(std::vector<std::byte> executable);

} // namespace setup

#endif
