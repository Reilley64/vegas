#pragma once

// A combat world state condition (a key and the value it must have), as combat goals and actions read it. The
// getters folded into 0x00559450 and 0x00726070 read `iKey` and `iValue` when called on a condition.
struct CombatWorldStateCondFields
{
    int iKey;
    int iValue;
};
