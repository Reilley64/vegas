#include "havok/TokenReader.h"

namespace fnv_00dcc8e0
{
namespace TokenParsing {
static __declspec(noinline) void SkipWhitespace(TokenStream* stream)
{
    char storage[64];
    char* buffer = reinterpret_cast<char*>(storage);
    stream->v07(64);
    int n = stream->v04(buffer, 64);
    while (n != 0)
    {
        int i = 0;
        while (i < n)
        {
            char c = buffer[i];
            if (c != ' ' && c != '\t' && c != '\r' && c != '\n')
            {
                stream->v08();
                stream->v05(i);
                return;
            }
            ++i;
        }
        stream->v07(64);
        n = stream->v04(buffer, 64);
    }
}
}


// Reads a whitespace-delimited token from the stream into the owner's buffer, appending a null terminator, and returns this.
// @fnv 0x00dcc8e0
TokenReader* TokenReader::ReadToken(InlineStorageString* owner)
{
    owner->Clear();
    TokenParsing::SkipWhitespace(m_08);
    m_08->v07(1);
    auto readChar = [this] {
        char value;
        return m_08->v04(&value, 1) ? static_cast<int>(value) : -1;
    };
    int c = readChar();
    while (c != -1 && c != ' ' && c != '\t' && c != '\r' && c != '\n')
    {
        const char value = static_cast<char>(c);
        owner->Append(&value, 1);
        m_08->v07(1);
        c = readChar();
    }
    m_08->v08();
    return this;
}
}
