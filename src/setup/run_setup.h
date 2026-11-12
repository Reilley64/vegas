#ifndef VEGAS_SETUP_RUN_SETUP_H
#define VEGAS_SETUP_RUN_SETUP_H

#include <filesystem>
#include <ostream>
#include <span>

namespace setup
{

// The executable of the original release that setup reads in the install
// folder.
inline constexpr char originalExecutableName[] = "FalloutNV.exe";

// The exit status of vegas-setup, one for each way it ends.
enum class SetupExit
{
    Installed = 0,            // the data pack was written, installed and read back
    Usage = 1,                // not exactly one argument, the install folder
    ExecutableMissing = 2,    // there is no FalloutNV.exe in the install folder
    ExecutableUnreadable = 3, // FalloutNV.exe cannot be opened or read
    NotAnExecutable = 4,      // fileformat::PeError: not a 32-bit x86 executable whose version can be read
    UnsupportedOriginal = 5,  // fileformat::UnsupportedOriginalError: not a supported original release
    DataUnreadable = 6,       // setup::ExtractError: a field of C1 cannot be read as stored
    WrittenPackRefused = 7,   // setup::StagedPackError: a defect of setup
    StagedWrite = 8,          // setup::InstallError, InstallProblem::StagedWrite
    StagedInvalid = 9,        // InstallProblem::StagedInvalid
    Replace = 10,             // InstallProblem::Replace
    Recheck = 11,             // InstallProblem::Recheck
};

// vegas-setup with the arguments after the program's name: the install
// folder only. Reads originalExecutableName there, prepares the data pack with
// PrepareDataPack and installs it beside the executable with
// InstallDataPack. Writes one line to `messages` that says how it ended and
// returns the status. Before the pack is prepared, nothing is written to the
// folder. FalloutNV.exe is never written. An allocation failure throws the
// standard exceptions.
SetupExit RunSetup(std::span<const std::filesystem::path> arguments, std::ostream& messages);

} // namespace setup

#endif
