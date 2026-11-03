#ifndef VEGAS_FILEFORMAT_COMPRESSION_H
#define VEGAS_FILEFORMAT_COMPRESSION_H

#include <cstddef>
#include <memory>
#include <span>

struct z_stream_s;

namespace fileformat
{

enum class InflateStatus
{
    More,  // the stream needs more input or more room for output
    End,   // the stream has ended
    Error, // the stream is corrupt
};

// The zlib stream a reader of compressed records or BSA files keeps. Reset
// starts the next stream on it. Like the original release, it does not check
// the Adler-32 trailer at the end of a stream.
class Inflater
{
  public:
    Inflater();
    ~Inflater();
    Inflater(const Inflater&) = delete;
    Inflater& operator=(const Inflater&) = delete;

    void Reset();

    // Inflates from the front of `input` into the front of `output`, then
    // drops the bytes it read from `input` and the bytes it wrote from `output`.
    InflateStatus Inflate(std::span<const std::byte>& input, std::span<std::byte>& output);

  private:
    std::unique_ptr<z_stream_s> stream;
};

// Deflates `input` into `output` as one zlib stream at the default level and
// returns its size, or 0 when it doesn't fit.
std::size_t Deflate(std::span<const std::byte> input, std::span<std::byte> output);

} // namespace fileformat

#endif
