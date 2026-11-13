#include "check.h"
#include "fileformat/pack_catalogue.h"
#include "fileformat/pack_validation.h"
#include "fileformat/pack_writer.h"
#include "fileformat/supported_release.h"
#include "fnv/main_window_class.h"

#include <array>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <format>
#include <span>
#include <string_view>
#include <type_traits>
#include <vector>

namespace
{

// The owner's storage is the catalogue's declaration itself, so its capacity
// is the entry's.
static_assert(std::is_same_v<decltype(fnv::startup::PublishedMainWindowClass()), const fileformat::MainWindowClass&>);

// The one writer takes a validated pack: no bytes, no structure, no name.
static_assert(std::is_invocable_v<decltype(&fnv::startup::PublishMainWindowClass), const fileformat::ValidatedPack&>);
static_assert(
    !std::is_invocable_v<decltype(&fnv::startup::PublishMainWindowClass), const fileformat::MainWindowClass&>);
static_assert(!std::is_invocable_v<decltype(&fnv::startup::PublishMainWindowClass), std::span<const std::byte>>);

// Made-up class names: none is a string of the original release.
constexpr std::string_view firstClass = "test window class";
constexpr std::string_view secondClass = "other window class";

// A complete pack of catalogue version 2 holding `className` and made-up C1
// strings. It records the supported release's identity: it is compared, not
// proved.
fileformat::ValidatedPack Validated(std::string_view className)
{
    std::vector<std::byte> payload(140);
    payload[0] = std::byte{'m'};
    std::vector<std::byte> classPayload(256);
    for (std::size_t i = 0; i < className.size(); ++i)
        classPayload[i] = static_cast<std::byte>(className[i]);
    const std::array<fileformat::PackWriteEntry, 2> entries{
        {{{'I', 'N', 'S', 'T'}, 1, payload}, {{'W', 'N', 'D', 'C'}, 1, classPayload}}};
    return fileformat::ValidatePack(
        fileformat::WritePackStructure(supported_release::version, supported_release::Sha256(), entries));
}

void ExpectPublished(Checks& checks, std::string_view test, std::string_view expected)
{
    std::array<char, 256> wanted{};
    std::memcpy(wanted.data(), expected.data(), expected.size());
    if (fnv::startup::PublishedMainWindowClass().className != wanted)
        checks.Fail(test, std::format("expected \"{}\" and zeros to the end of the field", expected));
}

} // namespace

int main(int argc, char** argv)
{
    if (argc == 2 && std::strcmp(argv[1], "--read-unpublished") == 0)
    {
        std::fprintf(stderr, "read-unpublished\n");
        fnv::startup::PublishedMainWindowClass();
        return 0;
    }

    Checks checks("main window class");
    checks.Run("publish", [&] {
        fnv::startup::PublishMainWindowClass(Validated(firstClass));
        ExpectPublished(checks, "publish", firstClass);
    });
    checks.Run("publish again", [&] {
        fnv::startup::PublishMainWindowClass(Validated(secondClass));
        ExpectPublished(checks, "publish again", secondClass);
    });
    checks.Run("the same storage", [&] {
        const fileformat::MainWindowClass* before = &fnv::startup::PublishedMainWindowClass();
        fnv::startup::PublishMainWindowClass(Validated(firstClass));
        if (&fnv::startup::PublishedMainWindowClass() != before)
            checks.Fail("storage", "a publication moved the owner's storage");
        ExpectPublished(checks, "the same storage", firstClass);
    });
    return checks.ExitCode();
}
