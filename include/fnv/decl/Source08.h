#pragma once

class InventoryStackRecord;
struct Proxy08;
struct StrArr;
struct Target08;
template <class> class BSSimpleList;

struct Source08 {
public:
    // 0x004584d0
    void *FUN_004584d0(::Proxy08 *);
    // 0x00482b00
    ::BSSimpleList< ::InventoryStackRecord *> *CopyUniqueObjects();
    // 0x00bafaf0
    void CopyToTarget(::Target08 *);
    // 0x00c255b0
    void FUN_00c255b0(::StrArr *);
};
