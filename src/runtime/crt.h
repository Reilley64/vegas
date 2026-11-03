#ifndef VEGAS_RUNTIME_CRT_H
#define VEGAS_RUNTIME_CRT_H

#include <cstddef>
#include <cstdint>
#include <cstdio>

// Project versions of the Microsoft C runtime functions that the original
// release calls and that have no standard C or C++ equivalent. Each one keeps
// the Microsoft function's results for the inputs the game passes. Where the
// Microsoft function would call the invalid parameter handler, these return
// the error code that function documents instead.
namespace fnv::crt
{

// strcpy_s, strcat_s, strncpy_s, memcpy_s, memmove_s: 0 on success, otherwise
// an errno value (EINVAL, ERANGE, or STRUNCATE for a truncated strncpy_s).
int strcpy_s(char* destination, std::size_t size, const char* source);
int strcat_s(char* destination, std::size_t size, const char* source);
inline constexpr std::size_t truncate = static_cast<std::size_t>(-1); // _TRUNCATE
inline constexpr int truncated = 80;                                   // STRUNCATE
int strncpy_s(char* destination, std::size_t size, const char* source, std::size_t count);
int memcpy_s(void* destination, std::size_t size, const void* source, std::size_t count);
int memmove_s(void* destination, std::size_t size, const void* source, std::size_t count);

// _stricmp, _strnicmp, _wcsicmp and _strlwr_s in the "C" locale: only A-Z
// change case, and letters compare as lowercase.
int stricmp(const char* left, const char* right);
int strnicmp(const char* left, const char* right, std::size_t count);
int wcsicmp(const wchar_t* left, const wchar_t* right);
int strlwr_s(char* text, std::size_t size);

std::uint16_t byteswap_ushort(std::uint16_t value);
std::uint32_t byteswap_ulong(std::uint32_t value);
std::uint64_t byteswap_uint64(std::uint64_t value);

// _splitpath_s and _makepath_s. Both separators, '\\' and '/', end a folder.
// A null output with size 0 skips that part.
int splitpath_s(const char* path, char* drive, std::size_t driveSize, char* dir, std::size_t dirSize, char* name,
                std::size_t nameSize, char* ext, std::size_t extSize);
int makepath_s(char* path, std::size_t size, const char* drive, const char* dir, const char* name, const char* ext);

char* strtok_s(char* text, const char* delimiters, char** context);

// _gcvt as the original release's runtime writes it: a whole number keeps its
// decimal point ("12.") and an exponent has three digits ("1.23e+006").
char* gcvt(double value, int digits, char* buffer);

// wcstombs_s in the "C" locale. converted counts the terminator.
int wcstombs_s(std::size_t* converted, char* destination, std::size_t size, const wchar_t* source, std::size_t count);

// The compiler's array helpers (`eh vector constructor iterator` and friends):
// they run a constructor, copy constructor or destructor on each of count
// elements of size bytes. If a constructor throws, the elements already built
// are destroyed in reverse order and the exception continues.
void vector_constructor(void* array, std::size_t size, int count, void (*construct)(void*), void (*destroy)(void*));
void vector_copy_constructor(void* destination, void* source, std::size_t size, int count,
                             void (*copy)(void*, void*), void (*destroy)(void*));
void vector_destructor(void* array, std::size_t size, int count, void (*destroy)(void*));

int fopen_s(std::FILE** file, const char* path, const char* mode);
// _access: 0 when the path exists (and for mode 2, is writable), otherwise -1.
int access(const char* path, int mode);
// _getcwd: the current folder, or null when it does not fit in size.
char* getcwd(char* buffer, int size);

// The parts of _stat's result the game reads.
struct FileStatus
{
    std::uint64_t size;
    std::int64_t modified; // last write time, in seconds since 1970-01-01 UTC
};
// _stat: 0 and the file's status, or -1 when the path does not name a file.
int stat(const char* path, FileStatus* status);

} // namespace fnv::crt

#endif
