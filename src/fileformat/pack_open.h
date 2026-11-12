#ifndef VEGAS_FILEFORMAT_PACK_OPEN_H
#define VEGAS_FILEFORMAT_PACK_OPEN_H

#include "fileformat/original_identity.h"
#include "fileformat/pack_validation.h"

#include <filesystem>
#include <span>
#include <stdexcept>
#include <string>

namespace fileformat
{

// Why the file of a data pack could not be read. Its bytes were never seen,
// so it is not a FormatError.
enum class PackOpenProblem
{
    Missing,    // there is no file at the path
    Unreadable, // there is something at the path, but its bytes could not be read
};

class PackOpenError : public std::runtime_error
{
  public:
    PackOpenError(PackOpenProblem problem, const std::string& message)
        : std::runtime_error(message), problem(problem)
    {
    }

    PackOpenProblem Problem() const { return problem; }

  private:
    PackOpenProblem problem;
};

// The step a later startup calls: reads the whole file at `path` and returns
// CheckPackOriginal of its bytes. Each failure is reported before the engine
// can use a byte of the pack:
//
// - PackOpenError when the file is missing or cannot be read;
// - PackStructureError when its bytes are not a well-formed container,
//   including an unsupported envelope, catalogue, native data contract or
//   build target revision and a payload outside the file;
// - UnsupportedOriginalError when the original it records is not one of
//   `supported`.
//
// Only the file at `path` is read: no executable and no other file. Where the
// path and the supported set come from is the caller's. The result is an
// OriginalCheckedPack, which is not a complete pack and does not allow the
// engine to start. An allocation failure throws the standard exceptions, not
// one of these.
OriginalCheckedPack OpenPack(const std::filesystem::path& path, std::span<const OriginalIdentity> supported);

} // namespace fileformat

#endif
