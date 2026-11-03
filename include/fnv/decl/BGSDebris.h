#pragma once

class DebrisModelEntry;
template <class> class BSSimpleList;

class BGSDebris {
public:
    // 0x00409140
    ::BSSimpleList< ::DebrisModelEntry *> *GetDataList();
    // 0x004f9e30
    void ClearData();
};
