#pragma once

class InventoryEntry;
class NiNode;
struct ArgStruct;
struct EntryEx;
struct ListNode;
struct QHeadPtrDest;
struct tchunk;
template <class> class NiPointer;

struct TargetClass {
public:
    // 0x004eedd0
    int FUN_004eedd0(int, int);
    // 0x0052a9b0
    void FUN_0052a9b0(const ::NiPointer< ::NiNode> &);
    // 0x0072f120
    ::InventoryEntry *FindMatchingEntry(::ListNode *, ::EntryEx *);
    // 0x00906c10
    bool FUN_00906c10(int, void **, ::QHeadPtrDest *);
    // 0x00b30da0
    void ClearOuter();
    // 0x00c85770
    ::TargetClass *Clear();
    // 0x00cbcbd0
    void FUN_00cbcbd0(void *);
    // 0x00cbd520
    void FUN_00cbd520(::ArgStruct *);
    // 0x00d871e0
    bool *FUN_00d871e0(bool *);
    // 0x00db7860
    int FUN_00db7860();
    // 0x00dd8010
    void InsertChunk(::tchunk *, int);
};
