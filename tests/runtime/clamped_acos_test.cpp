#include "check.h"
#include "fnv/symbols_00c74000.h"

#include <bit>
#include <cmath>
#include <cstdint>
#include <limits>

int main()
{
    Checks checks("runtime.clamped_acos");
    const float pi = 3.1415927f;
    const float infinity = std::numeric_limits<float>::infinity();
    const float inside = std::nextafter(1.0f, 0.0f);
    const float outside = std::nextafter(1.0f, infinity);
    auto exact = [&](const char* name, float expected, float input) {
        checks.Equal(name, std::bit_cast<std::uint32_t>(expected),
                     std::bit_cast<std::uint32_t>(ClampedAcos(input)));
    };
    exact("positive boundary", 0.0f, 1.0f);
    exact("negative boundary uses canonical pi", pi, -1.0f);
    exact("positive adjacent outside", 0.0f, outside);
    exact("negative adjacent outside", pi, -outside);
    exact("positive out of range", 0.0f, 2.0f);
    exact("negative out of range", pi, -2.0f);
    exact("positive maximum", 0.0f, std::numeric_limits<float>::max());
    exact("negative maximum", pi, -std::numeric_limits<float>::max());
    exact("positive infinity", 0.0f, infinity);
    exact("negative infinity", pi, -infinity);
    exact("positive zero", pi / 2.0f, 0.0f);
    exact("negative zero", pi / 2.0f, -0.0f);

    for (float input : {inside, -inside, 0.5f, -0.5f})
    {
        const float angle = ClampedAcos(input);
        checks.Equal("in-range angle", true, angle > 0.0f && angle < pi);
        checks.Equal("in-range cosine round trip", true,
                     std::fabs(std::cos(angle) - input) <= std::numeric_limits<float>::epsilon());
    }
    checks.Equal("positive adjacent inside is not clamped", true, ClampedAcos(inside) > 0.0f);
    checks.Equal("negative adjacent inside is not clamped", true, ClampedAcos(-inside) < pi);
    for (float input : {std::numeric_limits<float>::quiet_NaN(), -std::numeric_limits<float>::quiet_NaN()})
        checks.Equal("unordered input remains NaN", true, std::isnan(ClampedAcos(input)));
    return checks.ExitCode();
}
