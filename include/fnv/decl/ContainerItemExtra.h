#pragma once

class TESFile;

class ContainerItemExtra {
public:
    // 0x0040e690
    ContainerItemExtra();
    // 0x0040e780
    bool Load(::TESFile *);
    // 0x0040e920
    bool Compare(::ContainerItemExtra *);
    // 0x0040e980
    void Copy(::ContainerItemExtra *);
    // 0x0040e9c0
    bool IsDefault();
    // 0x0058f880
    void *InitContainerItemExtra(int);
};
