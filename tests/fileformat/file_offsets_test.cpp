#include "check.h"
#include "runtime/crt.h"

#include <array>
#include <cstdint>
#include <cstdio>
#include <memory>

#ifdef _WIN32
#include <io.h>
#include <windows.h>
#include <winioctl.h>
#endif

int main()
{
    Checks checks("file offsets");
    checks.Run("sparse file beyond 4 GiB", [&] {
        std::unique_ptr<std::FILE, decltype(&std::fclose)> file(std::tmpfile(), &std::fclose);
        checks.Equal("temporary file opens", true, file != nullptr);
        if (!file)
            return;
#ifdef _WIN32
        DWORD returned = 0;
        HANDLE handle = reinterpret_cast<HANDLE>(_get_osfhandle(_fileno(file.get())));
        BOOL sparse = DeviceIoControl(handle, FSCTL_SET_SPARSE, nullptr, 0, nullptr, 0, &returned, nullptr);
        checks.Equal("mark temporary file sparse", TRUE, sparse);
        if (!sparse)
            return;
#endif
        constexpr std::int64_t offset = 0x100000025LL;
        constexpr std::array<unsigned char, 6> expected{0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc};
        checks.Equal("seek beyond 4 GiB", 0, fnv::crt::fseek(file.get(), offset, SEEK_SET));
        checks.Equal("tell beyond 4 GiB", offset, fnv::crt::ftell(file.get()));
        checks.Equal("write marker", expected.size(), std::fwrite(expected.data(), 1, expected.size(), file.get()));
        checks.Equal("tell includes buffered write", std::int64_t{0x10000002bLL}, fnv::crt::ftell(file.get()));
        checks.Equal("size includes buffered write", std::int64_t{0x10000002bLL}, fnv::crt::file_size(file.get()));
        checks.Equal("size preserves position", std::int64_t{0x10000002bLL}, fnv::crt::ftell(file.get()));
        checks.Equal("seek relative to end", 0, fnv::crt::fseek(file.get(), -6, SEEK_END));
        std::array<unsigned char, 6> actual{};
        checks.Equal("read marker prefix", std::size_t{2}, std::fread(actual.data(), 1, 2, file.get()));
        checks.Equal("tell after buffered read", std::int64_t{0x100000027LL}, fnv::crt::ftell(file.get()));
        checks.Equal("size after buffered read", std::int64_t{0x10000002bLL}, fnv::crt::file_size(file.get()));
        checks.Equal("size preserves buffered read position", std::int64_t{0x100000027LL}, fnv::crt::ftell(file.get()));
        checks.Equal("read remaining marker", std::size_t{4}, std::fread(actual.data() + 2, 1, 4, file.get()));
        checks.Equal("marker matches", true, expected == actual);
        checks.Equal("seek back relative to current", 0, fnv::crt::fseek(file.get(), -6, SEEK_CUR));
        checks.Equal("tell after relative seek", offset, fnv::crt::ftell(file.get()));
        checks.Equal("seek to sparse hole", 0, fnv::crt::fseek(file.get(), offset - 1, SEEK_SET));
        checks.Equal("hole reads as zero", 0, std::fgetc(file.get()));
    });
    return checks.ExitCode();
}
