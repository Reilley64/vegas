#pragma once

struct ScriptRecord;

struct ScriptRecordList {
public:
    // 0x00e3df60
    ::ScriptRecord *FindByTypeAndOccurrence(int, int);
};
