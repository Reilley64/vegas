#include "runtime/crt.h"

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <system_error>
#include <cstdlib>
#include <string>
#include <utility>

namespace fnv::crt
{

namespace
{

// The length of text, but at most limit: text need not be terminated within limit.
std::size_t BoundedLength(const char* text, std::size_t limit)
{
    std::size_t length = 0;
    while (length < limit && text[length] != '\0')
        ++length;
    return length;
}

template <typename Char>
Char Lower(Char c)
{
    return c >= 'A' && c <= 'Z' ? static_cast<Char>(c - 'A' + 'a') : c;
}

// Compares at most count characters as lowercase, like the Microsoft functions:
// the result is the difference of the first lowercased characters that differ.
template <typename Char, typename Unsigned>
int CompareLower(const Char* left, const Char* right, std::size_t count)
{
    for (std::size_t i = 0; i < count; ++i)
    {
        int l = static_cast<Unsigned>(Lower(left[i]));
        int r = static_cast<Unsigned>(Lower(right[i]));
        if (l != r || l == 0)
            return l - r;
    }
    return 0;
}

bool IsSeparator(char c)
{
    return c == '\\' || c == '/';
}

// Copies length characters of text into an output part of splitpath_s.
int CopyPart(char* part, std::size_t size, const char* text, std::size_t length)
{
    if (part == nullptr)
        return size == 0 ? 0 : EINVAL;
    if (length >= size)
        return ERANGE;
    std::memcpy(part, text, length);
    part[length] = '\0';
    return 0;
}

// Appends length characters to path at *used, keeping room for the terminator.
bool Append(char* path, std::size_t size, std::size_t& used, const char* text, std::size_t length)
{
    if (used + length >= size)
        return false;
    std::memcpy(path + used, text, length);
    used += length;
    return true;
}

} // namespace

int strcpy_s(char* destination, std::size_t size, const char* source)
{
    if (destination == nullptr || size == 0)
        return EINVAL;
    if (source == nullptr)
    {
        destination[0] = '\0';
        return EINVAL;
    }
    std::size_t length = std::strlen(source);
    if (length >= size)
    {
        destination[0] = '\0';
        return ERANGE;
    }
    std::memcpy(destination, source, length + 1);
    return 0;
}

int strcat_s(char* destination, std::size_t size, const char* source)
{
    if (destination == nullptr || size == 0)
        return EINVAL;
    std::size_t used = BoundedLength(destination, size);
    if (source == nullptr || used == size)
    {
        destination[0] = '\0';
        return EINVAL;
    }
    if (strcpy_s(destination + used, size - used, source) != 0)
    {
        destination[0] = '\0';
        return ERANGE;
    }
    return 0;
}

int strncpy_s(char* destination, std::size_t size, const char* source, std::size_t count)
{
    if (count == 0 && destination == nullptr && size == 0)
        return 0;
    if (destination == nullptr || size == 0)
        return EINVAL;
    if (source == nullptr)
    {
        destination[0] = '\0';
        return count == 0 ? 0 : EINVAL;
    }
    std::size_t length = BoundedLength(source, count == truncate ? size : count);
    if (count == truncate && length == size)
    {
        std::memcpy(destination, source, size - 1);
        destination[size - 1] = '\0';
        return truncated;
    }
    if (length >= size)
    {
        destination[0] = '\0';
        return ERANGE;
    }
    std::memcpy(destination, source, length);
    destination[length] = '\0';
    return 0;
}

int memcpy_s(void* destination, std::size_t size, const void* source, std::size_t count)
{
    if (count == 0)
        return 0;
    if (destination == nullptr)
        return EINVAL;
    if (source == nullptr || count > size)
    {
        std::memset(destination, 0, size);
        return source == nullptr ? EINVAL : ERANGE;
    }
    std::memcpy(destination, source, count);
    return 0;
}

int memmove_s(void* destination, std::size_t size, const void* source, std::size_t count)
{
    if (count == 0)
        return 0;
    if (destination == nullptr || source == nullptr)
        return EINVAL;
    if (count > size)
        return ERANGE;
    std::memmove(destination, source, count);
    return 0;
}

int stricmp(const char* left, const char* right)
{
    return CompareLower<char, unsigned char>(left, right, static_cast<std::size_t>(-1));
}

int strnicmp(const char* left, const char* right, std::size_t count)
{
    return CompareLower<char, unsigned char>(left, right, count);
}

int wcsicmp(const wchar_t* left, const wchar_t* right)
{
    return CompareLower<wchar_t, wchar_t>(left, right, static_cast<std::size_t>(-1));
}

int strlwr_s(char* text, std::size_t size)
{
    if (text == nullptr)
        return EINVAL;
    std::size_t length = BoundedLength(text, size);
    if (length == size)
    {
        if (size > 0)
            text[0] = '\0';
        return EINVAL;
    }
    for (std::size_t i = 0; i < length; ++i)
        text[i] = Lower(text[i]);
    return 0;
}

std::uint16_t byteswap_ushort(std::uint16_t value)
{
    return static_cast<std::uint16_t>((value >> 8) | (value << 8));
}

std::uint32_t byteswap_ulong(std::uint32_t value)
{
    return (std::uint32_t{byteswap_ushort(static_cast<std::uint16_t>(value))} << 16) | byteswap_ushort(static_cast<std::uint16_t>(value >> 16));
}

std::uint64_t byteswap_uint64(std::uint64_t value)
{
    return (std::uint64_t{byteswap_ulong(static_cast<std::uint32_t>(value))} << 32) | byteswap_ulong(static_cast<std::uint32_t>(value >> 32));
}

int splitpath_s(const char* path, char* drive, std::size_t driveSize, char* dir, std::size_t dirSize, char* name,
                std::size_t nameSize, char* ext, std::size_t extSize)
{
    if (path == nullptr)
        return EINVAL;
    std::size_t driveLength = path[0] != '\0' && path[1] == ':' ? 2 : 0;
    const char* rest = path + driveLength;
    const char* fileStart = rest;
    for (const char* p = rest; *p != '\0'; ++p)
        if (IsSeparator(*p))
            fileStart = p + 1;
    const char* end = fileStart + std::strlen(fileStart);
    const char* dot = std::strrchr(fileStart, '.');
    const char* extStart = dot != nullptr ? dot : end;

    int results[] = {
        CopyPart(drive, driveSize, path, driveLength),
        CopyPart(dir, dirSize, rest, static_cast<std::size_t>(fileStart - rest)),
        CopyPart(name, nameSize, fileStart, static_cast<std::size_t>(extStart - fileStart)),
        CopyPart(ext, extSize, extStart, static_cast<std::size_t>(end - extStart)),
    };
    for (int result : results)
    {
        if (result != 0)
        {
            for (auto [part, size] : {std::pair{drive, driveSize}, {dir, dirSize}, {name, nameSize}, {ext, extSize}})
                if (part != nullptr && size > 0)
                    part[0] = '\0';
            return result;
        }
    }
    return 0;
}

int makepath_s(char* path, std::size_t size, const char* drive, const char* dir, const char* name, const char* ext)
{
    if (path == nullptr || size == 0)
        return EINVAL;
    std::size_t used = 0;
    bool fits = true;
    if (drive != nullptr && drive[0] != '\0')
    {
        fits = fits && Append(path, size, used, drive, 1) && Append(path, size, used, ":", 1);
    }
    if (dir != nullptr && dir[0] != '\0')
    {
        std::size_t length = std::strlen(dir);
        fits = fits && Append(path, size, used, dir, length);
        if (!IsSeparator(dir[length - 1]))
            fits = fits && Append(path, size, used, "\\", 1);
    }
    if (name != nullptr)
        fits = fits && Append(path, size, used, name, std::strlen(name));
    if (ext != nullptr && ext[0] != '\0')
    {
        if (ext[0] != '.')
            fits = fits && Append(path, size, used, ".", 1);
        fits = fits && Append(path, size, used, ext, std::strlen(ext));
    }
    if (!fits)
    {
        path[0] = '\0';
        return ERANGE;
    }
    path[used] = '\0';
    return 0;
}

char* strtok_s(char* text, const char* delimiters, char** context)
{
    char* start = text != nullptr ? text : *context;
    start += std::strspn(start, delimiters);
    if (*start == '\0')
    {
        *context = start;
        return nullptr;
    }
    char* end = start + std::strcspn(start, delimiters);
    if (*end != '\0')
        *end++ = '\0';
    *context = end;
    return start;
}

char* gcvt(double value, int digits, char* buffer)
{
    char text[64];
    std::snprintf(text, sizeof(text), "%.*g", digits, value);
    char* exponent = std::strchr(text, 'e');
    std::string mantissa(text, exponent != nullptr ? exponent : text + std::strlen(text));
    if (mantissa.find('.') == std::string::npos)
        mantissa += '.';
    if (exponent != nullptr)
    {
        int power = std::atoi(exponent + 1);
        char suffix[16];
        std::snprintf(suffix, sizeof(suffix), "e%c%03d", power < 0 ? '-' : '+', power < 0 ? -power : power);
        mantissa += suffix;
    }
    std::memcpy(buffer, mantissa.c_str(), mantissa.size() + 1);
    return buffer;
}

int wcstombs_s(std::size_t* converted, char* destination, std::size_t size, const wchar_t* source, std::size_t count)
{
    if (converted != nullptr)
        *converted = 0;
    if (destination == nullptr || source == nullptr)
        return EINVAL;
    std::size_t length = 0;
    while (length < count && source[length] != L'\0')
        ++length;
    if (length >= size)
    {
        if (size > 0)
            destination[0] = '\0';
        return ERANGE;
    }
    for (std::size_t i = 0; i < length; ++i)
    {
        if (source[i] > 0xFF)
        {
            destination[0] = '\0';
            return EILSEQ;
        }
        destination[i] = static_cast<char>(source[i]);
    }
    destination[length] = '\0';
    if (converted != nullptr)
        *converted = length + 1;
    return 0;
}

void vector_constructor(void* array, std::size_t size, int count, void (*construct)(void*), void (*destroy)(void*))
{
    char* element = static_cast<char*>(array);
    int built = 0;
    try
    {
        for (; built < count; ++built)
            construct(element + built * size);
    }
    catch (...)
    {
        vector_destructor(array, size, built, destroy);
        throw;
    }
}

void vector_copy_constructor(void* destination, void* source, std::size_t size, int count,
                             void (*copy)(void*, void*), void (*destroy)(void*))
{
    char* to = static_cast<char*>(destination);
    char* from = static_cast<char*>(source);
    int built = 0;
    try
    {
        for (; built < count; ++built)
            copy(to + built * size, from + built * size);
    }
    catch (...)
    {
        vector_destructor(destination, size, built, destroy);
        throw;
    }
}

void vector_destructor(void* array, std::size_t size, int count, void (*destroy)(void*))
{
    char* element = static_cast<char*>(array);
    while (count > 0)
        destroy(element + --count * size);
}

int fopen_s(std::FILE** file, const char* path, const char* mode)
{
    if (file == nullptr)
        return EINVAL;
    errno = 0;
    *file = std::fopen(path, mode);
    return *file != nullptr ? 0 : (errno != 0 ? errno : EINVAL);
}

int access(const char* path, int mode)
{
    std::error_code error;
    std::filesystem::file_status status = std::filesystem::status(path, error);
    if (error || !std::filesystem::exists(status))
        return -1;
    if ((mode & 2) != 0 && (status.permissions() & std::filesystem::perms::owner_write) == std::filesystem::perms::none)
        return -1;
    return 0;
}

char* getcwd(char* buffer, int size)
{
    std::error_code error;
    std::string folder = std::filesystem::current_path(error).string();
    if (error || buffer == nullptr || size <= 0 || folder.size() >= static_cast<std::size_t>(size))
        return nullptr;
    std::memcpy(buffer, folder.c_str(), folder.size() + 1);
    return buffer;
}

} // namespace fnv::crt
