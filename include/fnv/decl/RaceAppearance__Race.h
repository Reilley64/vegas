#pragma once

namespace RaceAppearance { struct NPC; }
namespace RaceAppearance { struct Output; }

namespace RaceAppearance {
struct Race {
public:
    // 0x006141f0
    void BuildAppearance(::RaceAppearance::NPC *, ::RaceAppearance::Output *, int, bool);
};
}
