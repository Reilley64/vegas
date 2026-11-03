#pragma once

struct NiRefObject;
template <class> struct NiPointer;
template <class> struct NiTListItem;

// The untyped view of NiTPointerListBase<Alloc, T>, whose folded member functions (0x004ed900 RemoveAll, 0x00559c30) the game calls for every element type.
struct NiTPointerListBaseRaw {
public:
    // 0x004ed900
    void FUN_004ed900();
    // 0x00559c30
    void FUN_00559c30();
    // 0x00c5bfb0
    ::NiPointer< ::NiRefObject> FUN_00c5bfb0(::NiTListItem< ::NiPointer< ::NiRefObject>> *&);
};
