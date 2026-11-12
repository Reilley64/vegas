#include "fileformat/pack_open.h"

#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <memory>
#include <utility>
#include <vector>

#ifdef _WIN32
#include <share.h>
#endif

namespace fileformat
{

namespace
{

struct CloseFile
{
    void operator()(std::FILE* file) const { std::fclose(file); }
};

std::unique_ptr<std::FILE, CloseFile> OpenForReading(const std::filesystem::path& path)
{
    errno = 0;
#ifdef _WIN32
    // The wide name, so a path outside the ANSI code page still opens. Others
    // may read the file meanwhile but not write it.
    std::FILE* file = _wfsopen(path.c_str(), L"rb", _SH_DENYWR);
#else
    std::FILE* file = std::fopen(path.c_str(), "rb");
#endif
    if (file == nullptr && errno == ENOENT)
        throw PackOpenError(PackOpenProblem::Missing, "data pack: file: does not exist");
    if (file == nullptr)
        throw PackOpenError(PackOpenProblem::Unreadable, "data pack: file: cannot be opened for reading");
    return std::unique_ptr<std::FILE, CloseFile>(file);
}

// Reads to the end of the file, so the size used is the number of bytes read,
// not one taken before reading.
std::vector<std::byte> ReadAll(std::FILE* file)
{
    constexpr std::size_t chunkBytes = std::size_t{1} << 20;
    std::vector<std::byte> bytes;
    std::size_t size = 0;
    for (;;)
    {
        bytes.resize(size + chunkBytes);
        const std::size_t read = std::fread(bytes.data() + size, 1, chunkBytes, file);
        size += read;
        if (read != chunkBytes)
            break;
    }
    if (std::ferror(file) != 0)
        throw PackOpenError(PackOpenProblem::Unreadable, "data pack: file: cannot be read");
    bytes.resize(size);
    return bytes;
}

} // namespace

OriginalCheckedPack OpenPack(const std::filesystem::path& path)
{
    std::vector<std::byte> bytes = ReadAll(OpenForReading(path).get());
    return CheckPackOriginal(std::move(bytes));
}

ValidatedPack OpenAndValidatePack(const std::filesystem::path& path)
{
    std::vector<std::byte> bytes = ReadAll(OpenForReading(path).get());
    return ValidatePack(std::move(bytes));
}

} // namespace fileformat
