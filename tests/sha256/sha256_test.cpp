#include "check.h"

#include "mbedtls/sha256.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <format>
#include <fstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

// The SHA-256 of the mbedtls_sha256 target against NIST's byte-oriented test
// vectors: SHA256ShortMsg.rsp and SHA256Monte.rsp of the CAVP SHA test
// vectors, stored unchanged beside this file, and the examples of FIPS 180-2.
namespace
{

using Bytes = std::vector<unsigned char>;
using Digest = std::array<unsigned char, 32>;

Bytes FromHex(std::string_view hex)
{
    if (hex.size() % 2 != 0)
        throw std::runtime_error(std::format("odd hex length {}", hex.size()));
    const auto nibble = [](char c) -> unsigned char {
        if (c >= '0' && c <= '9')
            return static_cast<unsigned char>(c - '0');
        if (c >= 'a' && c <= 'f')
            return static_cast<unsigned char>(c - 'a' + 10);
        if (c >= 'A' && c <= 'F')
            return static_cast<unsigned char>(c - 'A' + 10);
        throw std::runtime_error(std::format("not a hex digit: {}", c));
    };
    Bytes bytes;
    for (std::size_t i = 0; i < hex.size(); i += 2)
        bytes.push_back(static_cast<unsigned char>(nibble(hex[i]) << 4 | nibble(hex[i + 1])));
    return bytes;
}

std::string ToHex(const Digest& digest)
{
    std::string hex;
    for (unsigned char byte : digest)
        hex += std::format("{:02x}", byte);
    return hex;
}

Digest DigestFromHex(std::string_view hex)
{
    const Bytes bytes = FromHex(hex);
    if (bytes.size() != 32)
        throw std::runtime_error(std::format("digest of {} bytes", bytes.size()));
    Digest digest{};
    std::copy(bytes.begin(), bytes.end(), digest.begin());
    return digest;
}

// One "Name = value" line of a response file, without its line end.
struct Field
{
    std::string name;
    std::string value;
};

std::vector<Field> ReadFields(const std::string& path)
{
    std::ifstream file(path, std::ios::binary);
    if (!file)
        throw std::runtime_error(std::format("cannot open {}", path));
    std::vector<Field> fields;
    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        const std::size_t equals = line.find(" = ");
        if (line.empty() || line[0] == '#' || line[0] == '[' || equals == std::string::npos)
            continue;
        fields.push_back({line.substr(0, equals), line.substr(equals + 3)});
    }
    return fields;
}

Digest OneShot(Checks& check, std::string_view name, const unsigned char* data, std::size_t size)
{
    Digest digest{};
    check.Equal(std::format("{}: one-shot result", name), 0, mbedtls_sha256(data, size, digest.data(), 0));
    return digest;
}

// The same message given to mbedtls_sha256_update in two parts, split at `split`.
Digest TwoParts(Checks& check, std::string_view name, const Bytes& message, std::size_t split)
{
    mbedtls_sha256_context context;
    mbedtls_sha256_init(&context);
    Digest digest{};
    check.Equal(std::format("{}: starts", name), 0, mbedtls_sha256_starts(&context, 0));
    check.Equal(std::format("{}: first update", name), 0, mbedtls_sha256_update(&context, message.data(), split));
    check.Equal(std::format("{}: second update", name), 0,
                mbedtls_sha256_update(&context, message.data() + split, message.size() - split));
    check.Equal(std::format("{}: finish", name), 0, mbedtls_sha256_finish(&context, digest.data()));
    mbedtls_sha256_free(&context);
    return digest;
}

// Every message of 0 to 64 bytes, hashed at once and split at every byte.
void ShortMessages(Checks& check, const std::string& folder)
{
    const std::vector<Field> fields = ReadFields(folder + "/SHA256ShortMsg.rsp");
    std::size_t vectors = 0;
    for (std::size_t i = 0; i + 2 < fields.size(); i += 3)
    {
        if (fields[i].name != "Len" || fields[i + 1].name != "Msg" || fields[i + 2].name != "MD")
            throw std::runtime_error(std::format("ShortMsg: unexpected field {}", fields[i].name));
        const std::size_t bits = std::stoul(fields[i].value);
        Bytes message = FromHex(fields[i + 1].value);
        // A message of length 0 is written as one zero byte.
        message.resize(bits / 8);
        const Digest expected = DigestFromHex(fields[i + 2].value);
        const std::string name = std::format("ShortMsg Len = {}", bits);
        check.Equal(name, ToHex(expected), ToHex(OneShot(check, name, message.data(), message.size())));
        for (std::size_t split = 0; split <= message.size(); ++split)
            check.Equal(std::format("{} split at {}", name, split), ToHex(expected),
                        ToHex(TwoParts(check, name, message, split)));
        ++vectors;
    }
    check.Equal("ShortMsg vectors", std::size_t{65}, vectors);
}

// The Monte Carlo test of the CAVP SHA validation system: each checkpoint
// hashes 1,000 messages of three digests, 96 bytes each.
void MonteCarlo(Checks& check, const std::string& folder)
{
    const std::vector<Field> fields = ReadFields(folder + "/SHA256Monte.rsp");
    if (fields.empty() || fields[0].name != "Seed")
        throw std::runtime_error("Monte: no seed");
    Digest seed = DigestFromHex(fields[0].value);
    std::size_t checkpoints = 0;
    for (std::size_t i = 1; i + 1 < fields.size(); i += 2)
    {
        if (fields[i].name != "COUNT" || fields[i + 1].name != "MD")
            throw std::runtime_error(std::format("Monte: unexpected field {}", fields[i].name));
        std::array<Digest, 3> last{seed, seed, seed};
        for (int round = 3; round < 1003; ++round)
        {
            Bytes message;
            for (const Digest& digest : last)
                message.insert(message.end(), digest.begin(), digest.end());
            last[0] = last[1];
            last[1] = last[2];
            last[2] = OneShot(check, "Monte", message.data(), message.size());
        }
        seed = last[2];
        check.Equal(std::format("Monte COUNT = {}", fields[i].value), fields[i + 1].value, ToHex(seed));
        ++checkpoints;
    }
    check.Equal("Monte checkpoints", std::size_t{100}, checkpoints);
}

// The SHA-256 examples of FIPS 180-2: one block, two blocks and one million
// times the letter a, hashed at once and in parts of 1,000 bytes.
void Examples(Checks& check)
{
    const std::string_view abc = "abc";
    check.Equal("abc", std::string("ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"),
                ToHex(OneShot(check, "abc", reinterpret_cast<const unsigned char*>(abc.data()), abc.size())));
    const std::string_view two = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    check.Equal("two blocks", std::string("248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1"),
                ToHex(OneShot(check, "two blocks", reinterpret_cast<const unsigned char*>(two.data()), two.size())));

    const std::string million = "cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0";
    const Bytes a(1000000, 'a');
    check.Equal("one million a", million, ToHex(OneShot(check, "one million a", a.data(), a.size())));
    mbedtls_sha256_context context;
    mbedtls_sha256_init(&context);
    Digest digest{};
    check.Equal("one million a: starts", 0, mbedtls_sha256_starts(&context, 0));
    for (std::size_t offset = 0; offset < a.size(); offset += 1000)
        check.Equal("one million a: update", 0, mbedtls_sha256_update(&context, a.data() + offset, 1000));
    check.Equal("one million a: finish", 0, mbedtls_sha256_finish(&context, digest.data()));
    mbedtls_sha256_free(&context);
    check.Equal("one million a in parts", million, ToHex(digest));
}

} // namespace

int main(int argc, char** argv)
{
    Checks check("sha256");
    if (argc != 2)
    {
        check.Fail("arguments", "expected the folder of the test vectors");
        return check.ExitCode();
    }
    const std::string folder = argv[1];
    check.Run("ShortMsg", [&] { ShortMessages(check, folder); });
    check.Run("Monte", [&] { MonteCarlo(check, folder); });
    check.Run("examples", [&] { Examples(check); });
    return check.ExitCode();
}
