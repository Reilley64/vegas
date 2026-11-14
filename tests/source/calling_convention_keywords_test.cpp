#include "check.h"

#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <filesystem>
#include <format>
#include <fstream>
#include <iterator>
#include <string>
#include <string_view>
#include <vector>

// VEGAS-12: no __thiscall, __fastcall or __stdcall keyword in game code. Game
// code is every C and C++ file under src/ and include/, src/generated
// included. The one-underscore spellings, which clang-cl accepts as the same
// keywords, count too. A keyword in a comment, a string or character literal
// or a raw string is not code and is not counted; a macro from a system or SDK
// header, such as WINAPI, is not written in game code and is not seen. A raw
// string that does not end fails the file rather than hiding its rest. Blind
// spots: a keyword spelled with a line splice inside it, or put together by
// token pasting, passes; so do attribute spellings such as
// __attribute__((stdcall)).
namespace
{

namespace fs = std::filesystem;

struct Keyword
{
    int line;
    std::string word;
};

struct Scan
{
    std::vector<Keyword> keywords;
    // The line of a raw string that does not end, or 0. The scan stops there.
    int unterminatedRawString = 0;
};

bool IsIdentifierChar(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c == '$';
}

bool IsDigit(char c) { return c >= '0' && c <= '9'; }

bool IsCallingConvention(std::string_view word)
{
    for (std::string_view keyword : {"__stdcall", "__thiscall", "__fastcall", "_stdcall", "_thiscall", "_fastcall"})
        if (word == keyword)
            return true;
    return false;
}

// Every calling-convention keyword in the code of one file, with its line.
Scan FindKeywords(std::string_view text)
{
    Scan scan;
    std::vector<Keyword>& found = scan.keywords;
    int line = 1;
    std::size_t i = 0;
    const std::size_t n = text.size();
    const auto at = [&](std::size_t k) { return k < n ? text[k] : '\0'; };
    // Skips a quoted literal that starts at i; it ends at its closing quote or,
    // unterminated, at the end of the line.
    const auto skipQuoted = [&](char quote) {
        ++i;
        while (i < n && text[i] != quote && text[i] != '\n')
        {
            if (text[i] == '\\' && at(i + 1) == '\r' && at(i + 2) == '\n')
            {
                ++line;
                i += 2;
            }
            else if (text[i] == '\\' && i + 1 < n)
            {
                if (text[i + 1] == '\n')
                    ++line;
                ++i;
            }
            ++i;
        }
        if (i < n && text[i] == quote)
            ++i;
    };
    while (i < n)
    {
        const char c = text[i];
        if (c == '\n')
        {
            ++line;
            ++i;
        }
        else if (c == '/' && at(i + 1) == '/')
        {
            // A line comment goes on over a backslash at the end of its line.
            while (i < n && text[i] != '\n')
            {
                if (text[i] == '\\' && at(i + 1) == '\n')
                {
                    ++line;
                    ++i;
                }
                else if (text[i] == '\\' && at(i + 1) == '\r' && at(i + 2) == '\n')
                {
                    ++line;
                    i += 2;
                }
                ++i;
            }
        }
        else if (c == '/' && at(i + 1) == '*')
        {
            i += 2;
            while (i < n && !(text[i] == '*' && at(i + 1) == '/'))
            {
                if (text[i] == '\n')
                    ++line;
                ++i;
            }
            i = std::min(n, i + 2);
        }
        else if (c == '"' || c == '\'')
        {
            skipQuoted(c);
        }
        else if (IsDigit(c) || (c == '.' && IsDigit(at(i + 1))))
        {
            // A number, with its digit separators and exponent signs.
            while (i < n)
            {
                const char d = text[i];
                if (IsIdentifierChar(d) || d == '.')
                    ++i;
                else if (d == '\'' && IsIdentifierChar(at(i + 1)))
                    i += 2;
                else if ((d == '+' || d == '-') &&
                         (text[i - 1] == 'e' || text[i - 1] == 'E' || text[i - 1] == 'p' || text[i - 1] == 'P'))
                    ++i;
                else
                    break;
            }
        }
        else if (IsIdentifierChar(c))
        {
            const std::size_t start = i;
            while (i < n && IsIdentifierChar(text[i]))
                ++i;
            const std::string_view word = text.substr(start, i - start);
            if (at(i) == '"' && (word == "R" || word == "LR" || word == "uR" || word == "UR" || word == "u8R"))
            {
                // A raw string: R"delimiter( ... )delimiter". The delimiter
                // has at most 16 characters and no space, parenthesis,
                // backslash or control character. A raw string with no
                // opening parenthesis after a valid delimiter, or with no
                // closing one, fails the file: the scan stops there.
                std::size_t open = i + 1;
                while (open < n && open - i - 1 <= 16 && text[open] != '(' && text[open] != ')' &&
                       text[open] != '\\' && static_cast<unsigned char>(text[open]) > ' ')
                    ++open;
                const std::size_t end =
                    at(open) == '(' && open - i - 1 <= 16
                        ? text.find(std::format("){}\"", text.substr(i + 1, open - i - 1)), open + 1)
                        : std::string_view::npos;
                if (end == std::string_view::npos)
                {
                    scan.unterminatedRawString = line;
                    break;
                }
                const std::size_t stop = end + (open - i - 1) + 2;
                line += static_cast<int>(std::count(text.begin() + static_cast<std::ptrdiff_t>(i),
                                                    text.begin() + static_cast<std::ptrdiff_t>(stop), '\n'));
                i = stop;
            }
            else if (IsCallingConvention(word))
            {
                found.push_back({line, std::string(word)});
            }
        }
        else
        {
            ++i;
        }
    }
    return scan;
}

bool IsSourceFile(const fs::path& path)
{
    std::string extension = path.extension().string();
    std::transform(extension.begin(), extension.end(), extension.begin(),
                   [](unsigned char c) { return static_cast<char>(c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c); });
    for (std::string_view known : {".h", ".hh", ".hpp", ".hxx", ".inl", ".ipp", ".inc", ".c", ".cc", ".cpp", ".cxx"})
        if (extension == known)
            return true;
    return false;
}

void CheckScanner(Checks& checks)
{
    struct Case
    {
        std::string_view name;
        std::string_view text;
        std::vector<int> lines;
        int unterminatedRawString = 0;
    };
    const std::vector<Case> cases = {
        {"declaration", "void __stdcall f(void *);", {1}},
        {"pointer", "extern void (__stdcall *p)(void *);", {1}},
        {"cast", "(*reinterpret_cast<void(__stdcall* const**)(void*)>(this))[2](d);", {1}},
        {"all three", "int __thiscall a();\nint __fastcall b();\nint __stdcall c();", {1, 2, 3}},
        {"one underscore", "void _stdcall f();\nvoid _fastcall g();\nvoid _thiscall h();", {1, 2, 3}},
        {"line comment", "// __stdcall\nint x;", {}},
        {"block comment", "/* __fastcall\n __thiscall */ int x;\nvoid __stdcall f();", {3}},
        {"continued line comment", "// a \\\n __stdcall\nvoid __stdcall f();", {3}},
        {"string", "const char* s = \"__thiscall \\\" __stdcall\"; void __fastcall f();", {1}},
        {"character", "char q = '\"'; void __stdcall f();", {1}},
        {"raw string", "auto s = R\"x(__stdcall)\" )x\"; void __stdcall f();", {1}},
        {"prefixed string", "auto s = L\"__stdcall\"; auto t = u8\"__fastcall\";", {}},
        {"digit separator", "int a = 1'000; void __fastcall f();", {1}},
        {"part of a name", "int my__stdcall; int __stdcallx; int __stdcall_; int x__fastcall;", {}},
        {"other conventions", "void __cdecl f(); void __vectorcall g(); void WINAPI h();", {}},
        {"line numbers", "a\n/*\n*/ b\n\"\"\n__thiscall", {5}},
        {"crlf line numbers", "a\r\n/*\r\n*/ b\r\n\"\"\r\n__thiscall", {5}},
        {"string continued by lf", "const char* s = \"a\\\n__stdcall\"; void __stdcall f();", {2}},
        {"string continued by crlf", "const char* s = \"a\\\r\n__stdcall\"; void __stdcall f();", {2}},
        {"character continued by crlf", "char c = '\\\r\n_'; void __fastcall f();", {2}},
        {"raw string over lines", "auto s = R\"(\n__stdcall\n)\";\nvoid __stdcall f();", {4}},
        {"raw string, empty delimiter", "auto s = LR\"(__stdcall)\"; void __stdcall f();", {1}},
        {"raw string, no parenthesis", "void __fastcall f();\nauto s = R\"x;\nvoid __stdcall g();", {1}, 2},
        {"raw string, long delimiter", "auto s = R\"abcdefghijklmnopq(x)abcdefghijklmnopq\";", {}, 1},
        {"raw string, space in delimiter", "auto s = R\"a b(x)a b\"; void __stdcall f();", {}, 1},
        {"raw string, not closed", "auto s = u8R\"x(__stdcall)\";\nvoid __stdcall f();", {}, 1},
        {"raw string, last character", "R\"", {}, 1},
    };
    for (const Case& c : cases)
    {
        const Scan scan = FindKeywords(c.text);
        std::vector<int> lines;
        for (const Keyword& keyword : scan.keywords)
            lines.push_back(keyword.line);
        if (lines != c.lines)
            checks.Fail(std::format("scanner {}", c.name),
                        std::format("expected {} keyword(s), found {}", c.lines.size(), lines.size()));
        if (scan.unterminatedRawString != c.unterminatedRawString)
            checks.Fail(std::format("scanner {}", c.name),
                        std::format("expected an unterminated raw string at line {}, found line {}",
                                    c.unterminatedRawString, scan.unterminatedRawString));
    }
}

struct Site
{
    std::string file;
    int line;
    std::string message;
};

void CheckGameCode(Checks& checks, const fs::path& root)
{
    std::size_t files = 0;
    std::size_t keywords = 0;
    std::vector<Site> found;
    for (const fs::path& top : {root / "src", root / "include"})
    {
        if (!fs::is_directory(top))
        {
            checks.Fail("game code", std::format("{} is not a folder", top.generic_string()));
            continue;
        }
        for (auto it = fs::recursive_directory_iterator(top); it != fs::recursive_directory_iterator(); ++it)
        {
            if (!it->is_regular_file() || !IsSourceFile(it->path()))
                continue;
            std::ifstream in(it->path(), std::ios::binary);
            const std::string text{std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};
            if (!in && !in.eof())
            {
                checks.Fail("game code", std::format("cannot read {}", it->path().generic_string()));
                continue;
            }
            ++files;
            const std::string file = fs::relative(it->path(), root).generic_string();
            const Scan scan = FindKeywords(text);
            for (const Keyword& keyword : scan.keywords)
                found.push_back({file, keyword.line, std::format("{}:{}: {}", file, keyword.line, keyword.word)});
            keywords += scan.keywords.size();
            if (scan.unterminatedRawString != 0)
                found.push_back(
                    {file, scan.unterminatedRawString, std::format("{}: unterminated raw string", file)});
        }
    }
    // By file, then by line as a number.
    std::stable_sort(found.begin(), found.end(), [](const Site& a, const Site& b) {
        return a.file != b.file ? a.file < b.file : a.line < b.line;
    });
    for (const Site& site : found)
        checks.Fail("game code", site.message);
    // Fails closed: a root that is not the repository scans no file.
    if (files == 0)
        checks.Fail("game code", "no C or C++ file was scanned");
    std::printf("%zu files scanned, %zu calling-convention keyword(s), %zu unterminated raw string(s)\n", files,
                keywords, found.size() - keywords);
}

} // namespace

int main(int argc, char** argv)
{
    Checks checks("calling convention keywords");
    if (argc != 2)
    {
        checks.Fail("usage", "calling_convention_keywords_test <repository root>");
        return checks.ExitCode();
    }
    checks.Run("scanner", [&] { CheckScanner(checks); });
    checks.Run("game code", [&] { CheckGameCode(checks, fs::path(argv[1])); });
    return checks.ExitCode();
}
