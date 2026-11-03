#include "check.h"
#include "runtime/crt.h"

#include <cerrno>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <stdexcept>
#include <string>

namespace
{

void StringCopies(Checks& checks)
{
    char buffer[8] = "xxxxxxx";
    checks.Equal("strcpy_s result", 0, fnv::crt::strcpy_s(buffer, sizeof(buffer), "abc"));
    checks.Equal("strcpy_s text", std::string("abc"), std::string(buffer));

    checks.Equal("strcpy_s too long", ERANGE, fnv::crt::strcpy_s(buffer, 4, "abcd"));
    checks.Equal("strcpy_s too long clears", std::string(), std::string(buffer));

    fnv::crt::strcpy_s(buffer, sizeof(buffer), "ab");
    checks.Equal("strcat_s result", 0, fnv::crt::strcat_s(buffer, sizeof(buffer), "cde"));
    checks.Equal("strcat_s text", std::string("abcde"), std::string(buffer));
    checks.Equal("strcat_s too long", ERANGE, fnv::crt::strcat_s(buffer, sizeof(buffer), "fgh"));
    checks.Equal("strcat_s too long clears", std::string(), std::string(buffer));

    checks.Equal("strncpy_s count", 0, fnv::crt::strncpy_s(buffer, sizeof(buffer), "abcdef", 3));
    checks.Equal("strncpy_s count text", std::string("abc"), std::string(buffer));
    checks.Equal("strncpy_s truncate", fnv::crt::truncated,
                 fnv::crt::strncpy_s(buffer, 4, "abcdef", fnv::crt::truncate));
    checks.Equal("strncpy_s truncate text", std::string("abc"), std::string(buffer));
    checks.Equal("strncpy_s too long", ERANGE, fnv::crt::strncpy_s(buffer, 4, "abcdef", 5));
    checks.Equal("strncpy_s too long clears", std::string(), std::string(buffer));
}

void MemoryCopies(Checks& checks)
{
    char buffer[6] = "abcde";
    checks.Equal("memmove_s overlap", 0, fnv::crt::memmove_s(buffer + 1, 5, buffer, 4));
    checks.Equal("memmove_s overlap text", std::string("aabcd"), std::string(buffer));
    checks.Equal("memmove_s too long", ERANGE, fnv::crt::memmove_s(buffer, 2, "xyz", 3));
    checks.Equal("memmove_s too long keeps", std::string("aabcd"), std::string(buffer));

    checks.Equal("memcpy_s", 0, fnv::crt::memcpy_s(buffer, 6, "xy", 2));
    checks.Equal("memcpy_s text", std::string("xybcd"), std::string(buffer));
    checks.Equal("memcpy_s too long", ERANGE, fnv::crt::memcpy_s(buffer, 3, "1234", 4));
    checks.Equal("memcpy_s too long clears", std::string(), std::string(buffer));
}

void CaseInsensitiveText(Checks& checks)
{
    checks.Equal("stricmp equal", 0, fnv::crt::stricmp("Data\\Meshes", "data\\MESHES"));
    checks.Equal("stricmp order", true, fnv::crt::stricmp("apple", "BANANA") < 0);
    checks.Equal("stricmp lowercases before comparing", true, fnv::crt::stricmp("_", "A") < 0);
    checks.Equal("strnicmp prefix", 0, fnv::crt::strnicmp("Reload Strings", "reload ", 7));
    checks.Equal("strnicmp differs", true, fnv::crt::strnicmp("front", "STACK", 5) < 0);
    checks.Equal("wcsicmp", 0, fnv::crt::wcsicmp(L"NoCloud", L"nocloud"));

    char text[] = "Textures\\Sky.DDS";
    checks.Equal("strlwr_s", 0, fnv::crt::strlwr_s(text, sizeof(text)));
    checks.Equal("strlwr_s text", std::string("textures\\sky.dds"), std::string(text));
    checks.Equal("strlwr_s unterminated", EINVAL, fnv::crt::strlwr_s(text, 4));
}

void ByteSwaps(Checks& checks)
{
    checks.Equal("byteswap_ushort", std::uint16_t{0x3412}, fnv::crt::byteswap_ushort(0x1234));
    checks.Equal("byteswap_ulong", std::uint32_t{0x78563412}, fnv::crt::byteswap_ulong(0x12345678));
    checks.Equal("byteswap_uint64", std::uint64_t{0xEFCDAB8967452301}, fnv::crt::byteswap_uint64(0x0123456789ABCDEF));
}

void Paths(Checks& checks)
{
    char drive[3], dir[64], name[32], ext[16];
    checks.Equal("splitpath_s", 0,
                 fnv::crt::splitpath_s("C:\\Games\\FNV/Data\\FalloutNV.esm.bak", drive, sizeof(drive), dir,
                                       sizeof(dir), name, sizeof(name), ext, sizeof(ext)));
    checks.Equal("splitpath_s drive", std::string("C:"), std::string(drive));
    checks.Equal("splitpath_s dir", std::string("\\Games\\FNV/Data\\"), std::string(dir));
    checks.Equal("splitpath_s name", std::string("FalloutNV.esm"), std::string(name));
    checks.Equal("splitpath_s ext", std::string(".bak"), std::string(ext));

    checks.Equal("splitpath_s no drive", 0,
                 fnv::crt::splitpath_s("meshes\\armor", nullptr, 0, dir, sizeof(dir), name, sizeof(name), ext, sizeof(ext)));
    checks.Equal("splitpath_s no drive dir", std::string("meshes\\"), std::string(dir));
    checks.Equal("splitpath_s no ext name", std::string("armor"), std::string(name));
    checks.Equal("splitpath_s no ext", std::string(), std::string(ext));
    checks.Equal("splitpath_s small buffer", ERANGE,
                 fnv::crt::splitpath_s("a\\b.txt", nullptr, 0, nullptr, 0, name, 1, nullptr, 0));

    char path[64];
    checks.Equal("makepath_s", 0, fnv::crt::makepath_s(path, sizeof(path), "C", "Saves", "Save 1", "fos"));
    checks.Equal("makepath_s text", std::string("C:Saves\\Save 1.fos"), std::string(path));
    checks.Equal("makepath_s separators kept", 0, fnv::crt::makepath_s(path, sizeof(path), nullptr, "Data/", "x", ".esp"));
    checks.Equal("makepath_s separators kept text", std::string("Data/x.esp"), std::string(path));
    checks.Equal("makepath_s too long", ERANGE, fnv::crt::makepath_s(path, 4, nullptr, nullptr, "long", nullptr));
}

void Tokens(Checks& checks)
{
    char text[] = " a,b ,,c ";
    char* context = nullptr;
    std::string found;
    for (char* token = fnv::crt::strtok_s(text, " ,", &context); token != nullptr;
         token = fnv::crt::strtok_s(nullptr, " ,", &context))
        found += std::string("[") + token + "]";
    checks.Equal("strtok_s", std::string("[a][b][c]"), found);
}

void Conversions(Checks& checks)
{
    char text[32];
    checks.Equal("gcvt fraction", std::string("3.5"), std::string(fnv::crt::gcvt(3.5, 5, text)));
    checks.Equal("gcvt whole number keeps the point", std::string("12."), std::string(fnv::crt::gcvt(12.0, 5, text)));
    checks.Equal("gcvt exponent has three digits", std::string("1.23e+006"),
                 std::string(fnv::crt::gcvt(1234567.0, 3, text)));

    std::size_t converted = 0;
    checks.Equal("wcstombs_s", 0, fnv::crt::wcstombs_s(&converted, text, sizeof(text), L"Rex", 3));
    checks.Equal("wcstombs_s text", std::string("Rex"), std::string(text));
    checks.Equal("wcstombs_s count includes the terminator", std::size_t{4}, converted);
    checks.Equal("wcstombs_s too long", ERANGE, fnv::crt::wcstombs_s(&converted, text, 3, L"Rex", 3));
}

std::string g_events;

void Construct(void* element)
{
    char* c = static_cast<char*>(element);
    if (*c == 'x')
        throw std::runtime_error("construct");
    g_events += std::string("+") + *c;
}

void Destroy(void* element)
{
    g_events += std::string("-") + *static_cast<char*>(element);
}

void CopyElement(void* destination, void* source)
{
    *static_cast<char*>(destination) = static_cast<char>(*static_cast<char*>(source) + 1);
}

void ArrayIterators(Checks& checks)
{
    char elements[3] = {'a', 'b', 'c'};
    g_events.clear();
    fnv::crt::vector_constructor(elements, 1, 3, Construct, Destroy);
    checks.Equal("vector_constructor order", std::string("+a+b+c"), g_events);

    g_events.clear();
    fnv::crt::vector_destructor(elements, 1, 3, Destroy);
    checks.Equal("vector_destructor reverse order", std::string("-c-b-a"), g_events);

    char failing[3] = {'a', 'b', 'x'};
    g_events.clear();
    bool threw = false;
    try
    {
        fnv::crt::vector_constructor(failing, 1, 3, Construct, Destroy);
    }
    catch (const std::runtime_error&)
    {
        threw = true;
    }
    checks.Equal("vector_constructor rethrows", true, threw);
    checks.Equal("vector_constructor unwinds", std::string("+a+b-b-a"), g_events);

    char copies[3] = {};
    g_events.clear();
    fnv::crt::vector_copy_constructor(copies, elements, 1, 3, CopyElement, Destroy);
    checks.Equal("vector_copy_constructor", std::string("bcd"), std::string(copies, 3));
}

void Files(Checks& checks)
{
    std::filesystem::path path = std::filesystem::temp_directory_path() / "vegas_runtime_test.txt";
    std::FILE* file = nullptr;
    checks.Equal("fopen_s", 0, fnv::crt::fopen_s(&file, path.string().c_str(), "w"));
    checks.Equal("fopen_s file", true, file != nullptr);
    std::fclose(file);
    checks.Equal("access existing", 0, fnv::crt::access(path.string().c_str(), 0));

    file = std::fopen(path.string().c_str(), "w");
    std::fputs("twelve bytes", file);
    std::fclose(file);
    // 2010-10-19 00:00:00 UTC, the original release's date.
    std::chrono::sys_seconds released{std::chrono::seconds(1287446400)};
#if defined(_LIBCPP_VERSION) // libc++ has no clock_cast yet
    std::filesystem::last_write_time(path, std::chrono::file_clock::from_sys(released));
#else
    std::filesystem::last_write_time(path, std::chrono::clock_cast<std::chrono::file_clock>(released));
#endif
    fnv::crt::FileStatus status{};
    checks.Equal("stat existing", 0, fnv::crt::stat(path.string().c_str(), &status));
    checks.Equal("stat size", std::uint64_t{12}, status.size);
    checks.Equal("stat modified", std::int64_t{1287446400}, status.modified);

    std::filesystem::remove(path);
    checks.Equal("stat missing", -1, fnv::crt::stat(path.string().c_str(), &status));
    checks.Equal("access missing", -1, fnv::crt::access(path.string().c_str(), 0));
    checks.Equal("fopen_s missing", ENOENT, fnv::crt::fopen_s(&file, path.string().c_str(), "r"));
    checks.Equal("fopen_s missing file", true, file == nullptr);

    char folder[1024];
    checks.Equal("getcwd", std::filesystem::current_path().string(), std::string(fnv::crt::getcwd(folder, sizeof(folder))));
    checks.Equal("getcwd too small", true, fnv::crt::getcwd(folder, 1) == nullptr);
}

} // namespace

int main()
{
    Checks checks("runtime");
    checks.Run("string copies", [&] { StringCopies(checks); });
    checks.Run("memory copies", [&] { MemoryCopies(checks); });
    checks.Run("case-insensitive text", [&] { CaseInsensitiveText(checks); });
    checks.Run("byte swaps", [&] { ByteSwaps(checks); });
    checks.Run("paths", [&] { Paths(checks); });
    checks.Run("tokens", [&] { Tokens(checks); });
    checks.Run("conversions", [&] { Conversions(checks); });
    checks.Run("array iterators", [&] { ArrayIterators(checks); });
    checks.Run("files", [&] { Files(checks); });
    return checks.ExitCode();
}
