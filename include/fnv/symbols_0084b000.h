#pragma once

class SaveLoadFile;
struct BGSSaveFormBuffer;

// 0x0084bb50
int ScanRefsInRange(void *, unsigned int, unsigned int);
// 0x0084bc20
void LoadGlobalDataRanges(::SaveLoadFile *, unsigned int);
// 0x0084bcd0
bool FUN_0084bcd0(unsigned int, ::BGSSaveFormBuffer *);
