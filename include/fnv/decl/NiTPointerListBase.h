#pragma once

struct NiRefObject;
template <class> struct NiPointer;
template <class> struct NiTListItem;

struct NiTPointerListBase {
public:
    // 0x004ed900
    void FUN_004ed900();
    // 0x00559c30
    void FUN_00559c30();
    // 0x00c5bfb0
    ::NiPointer< ::NiRefObject> FUN_00c5bfb0(::NiTListItem< ::NiPointer< ::NiRefObject>> *&);
};
