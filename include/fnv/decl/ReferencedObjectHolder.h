#pragma once

struct ReferencedObjectHolder {
public:
    // Borrowed native object identity. Lookup reads its native vptr word, not
    // a fabricated legacy registry interface or serialized address.
    void* m_pObject = nullptr;
    // 0x00d477a0
    void *FUN_00d477a0();
};
