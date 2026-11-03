#pragma once

namespace CombatAssessment { struct Actor; }
namespace CombatAssessment { struct Time; }

namespace CombatAssessment {
struct Group {
public:
    // 0x009887b0
    void UpdateTargetPerception(::CombatAssessment::Actor *, ::CombatAssessment::Actor *, int *, ::CombatAssessment::Time *, bool *, bool *);
};
}
