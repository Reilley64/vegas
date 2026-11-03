#pragma once

// The first two members of ActorCombatGroup, both 32-bit, for units whose combat group stand-ins declare no fields.
// The 4-byte getter folded into 0x00726070 (BSSimpleList::GetNext) reads `unk04` when called on a combat group; the
// group strategies compare it with member counts.
struct CombatGroupFields
{
    unsigned int unk00;
    unsigned int unk04;
};
