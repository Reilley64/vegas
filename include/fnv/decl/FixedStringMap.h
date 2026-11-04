#pragma once

class NiFixedString;
class NiObjPtr;
struct MapItem;

class FixedStringMap {
public:
    // 0x00ee8f10
    void GetNextEntry(::MapItem *&, ::NiFixedString &, ::NiObjPtr &);
};
