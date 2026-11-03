#include "fileformat/compression.h"

#include <zlib.h>

#include <new>

namespace fileformat
{

Inflater::Inflater() : stream(std::make_unique<z_stream>())
{
    if (inflateInit(stream.get()) != Z_OK)
        throw std::bad_alloc();
    inflateValidate(stream.get(), 0);
}

Inflater::~Inflater()
{
    inflateEnd(stream.get());
}

void Inflater::Reset()
{
    inflateReset(stream.get());
}

InflateStatus Inflater::Inflate(std::span<const std::byte>& input, std::span<std::byte>& output)
{
    stream->next_in = reinterpret_cast<Bytef*>(const_cast<std::byte*>(input.data()));
    stream->avail_in = static_cast<uInt>(input.size());
    stream->next_out = reinterpret_cast<Bytef*>(output.data());
    stream->avail_out = static_cast<uInt>(output.size());
    const int result = inflate(stream.get(), Z_NO_FLUSH);
    input = input.last(stream->avail_in);
    output = output.last(stream->avail_out);

    switch (result)
    {
    case Z_STREAM_END:
        return InflateStatus::End;
    case Z_OK:
    case Z_BUF_ERROR:
        return InflateStatus::More;
    default:
        return InflateStatus::Error;
    }
}

std::size_t Deflate(std::span<const std::byte> input, std::span<std::byte> output)
{
    uLongf size = static_cast<uLongf>(output.size());
    if (compress(reinterpret_cast<Bytef*>(output.data()), &size, reinterpret_cast<const Bytef*>(input.data()),
                 static_cast<uLong>(input.size())) != Z_OK)
        return 0;
    return size;
}

} // namespace fileformat
