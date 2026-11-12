// For the tests that run FalloutNV.exe.
//
// falloutnv_pack_fixture PATH MUTEX writes a complete synthetic data pack of
// catalogue version 1 to PATH whose mutex name is MUTEX. It records the
// supported release's identity, so it claims that identity: it is compared,
// not proved. Its other strings are made up; none is a string of the original
// release.
//
// falloutnv_pack_fixture --check MUTEX makes the calls of the single-instance
// check that main makes, CreateMutexA on MUTEX and the decision with the real
// remote-session query, but records the message box instead of showing it.
// It writes one line that names the decision and exits with its code:
// "single-instance check: Continue" and 0 when main would go on with no
// message box, "single-instance check: RemoteSession" and 3, or
// "single-instance check: AlreadyRunning" and 4. Its mutex handle closes when
// it exits.
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_writer.h"
#include "fileformat/supported_release.h"
#include "fnv/single_instance_check.h"

#include <array>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string_view>
#include <vector>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

namespace
{
constexpr std::array<std::size_t, 4> fieldBytes{20, 60, 8, 52};

bool IsRemoteSession()
{
    return GetSystemMetrics(SM_REMOTESESSION) != 0;
}

int RecordBox(const char* text, const char*, unsigned int)
{
    std::printf("the message box would show: %s\n", text);
    return 1;
}

int Check(std::string_view mutexName)
{
    fileformat::SingleInstanceStrings strings{};
    std::memcpy(strings.mutexName.data(), mutexName.data(), mutexName.size());
    std::memcpy(strings.firstMessageText.data(), "fixture first message", 21);
    std::memcpy(strings.messageCaption.data(), "Fixture", 7);
    std::memcpy(strings.secondMessageText.data(), "fixture second message", 22);
    CreateMutexA(nullptr, FALSE, strings.mutexName.data());
    switch (fnv::startup::CheckSingleInstance(strings, GetLastError(), IsRemoteSession, RecordBox))
    {
    case fnv::startup::SingleInstanceOutcome::Continue:
        std::printf("single-instance check: Continue\n");
        return 0;
    case fnv::startup::SingleInstanceOutcome::RemoteSession:
        std::printf("single-instance check: RemoteSession\n");
        return 3;
    case fnv::startup::SingleInstanceOutcome::AlreadyRunning:
        std::printf("single-instance check: AlreadyRunning\n");
        return 4;
    }
    return 1;
}

int Write(const char* path, std::string_view mutexName)
{
    const std::array<std::string_view, 4> texts{mutexName, "fixture first message", "Fixture",
                                                "fixture second message"};
    std::vector<std::byte> payload;
    for (std::size_t i = 0; i < texts.size(); ++i)
    {
        for (const char c : texts[i])
            payload.push_back(static_cast<std::byte>(c));
        payload.resize(payload.size() + fieldBytes[i] - texts[i].size());
    }
    const std::array<fileformat::PackWriteEntry, 1> entries{{{{'I', 'N', 'S', 'T'}, 1, payload}}};
    const std::vector<std::byte> pack =
        fileformat::WritePackStructure(supported_release::version, supported_release::Sha256(), entries);
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    out.write(reinterpret_cast<const char*>(pack.data()), static_cast<std::streamsize>(pack.size()));
    out.close();
    if (!out)
    {
        std::fprintf(stderr, "falloutnv_pack_fixture: the pack could not be written\n");
        return 1;
    }
    return 0;
}
}

int main(int argc, char** argv)
{
    if (argc != 3 || std::strlen(argv[2]) >= fieldBytes[0])
    {
        std::fprintf(stderr, "usage: falloutnv_pack_fixture PATH|--check MUTEX (MUTEX below 20 bytes)\n");
        return 2;
    }
    if (std::strcmp(argv[1], "--check") == 0)
        return Check(argv[2]);
    return Write(argv[1], argv[2]);
}
