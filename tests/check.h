#ifndef VEGAS_TESTS_CHECK_H
#define VEGAS_TESTS_CHECK_H

#include <cstdio>
#include <exception>
#include <format>
#include <string>
#include <string_view>

// Collects failures for one test program. Each message names the format and
// the field, so a failure points at what broke.
class Checks
{
  public:
    explicit Checks(std::string_view format) : format(format) {}

    template <typename T>
    void Equal(std::string_view field, const T& expected, const T& actual)
    {
        if (!(expected == actual))
            Fail(field, std::format("expected {}, got {}", expected, actual));
    }

    void Fail(std::string_view field, std::string_view message)
    {
        std::fprintf(stderr, "%s: %.*s: %.*s\n", format.c_str(), static_cast<int>(field.size()), field.data(),
                     static_cast<int>(message.size()), message.data());
        ++failures;
    }

    template <typename Test>
    void Run(std::string_view test, Test&& body)
    {
        try
        {
            body();
        }
        catch (const std::exception& error)
        {
            Fail(test, std::format("threw: {}", error.what()));
        }
    }

    int ExitCode() const { return failures == 0 ? 0 : 1; }

  private:
    std::string format;
    int failures = 0;
};

#endif
