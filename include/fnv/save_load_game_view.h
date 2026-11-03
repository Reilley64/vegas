#pragma once

// The save game object behind g_TESSaveLoadGame, as far as the save and load code reads it directly: the cursor
// into the current save or load buffer. The release build reads it through the folded 4-byte getter at 0x00825c00.
struct SaveLoadGameView
{
    char pad00[0x14];
    char *pBufferCursor;
};
