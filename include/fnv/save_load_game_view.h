#pragma once

// The save game object behind g_TESSaveLoadGame, as far as the save and load code reads it directly: the cursor
// into the current save or load buffer. The release build reads it through the folded 4-byte getter at 0x00825c00.
struct SaveLoadGameView
{
    char pad00[0x14];
    char *pBufferCursor;
};

// The leading data members of BGSSaveLoadGame (g_BGSSaveLoadGame). The release build reads the form ID map through
// the folded 4-byte getter at 0x0044ddc0 (Twin_0044ddc0::GetName) and the save load history through the one at
// 0x00441110 (BGSTerrainManager::GetMinLevel).
struct BGSSaveLoadGameView
{
    void* pFormChangesMap;
    void* unused04;
    void* pFormIDMap;
    void* unused0C;
    void* pReferencesMap;
    void* unused14;
    void* unused18;
    void* pSaveLoadHistory;
};
