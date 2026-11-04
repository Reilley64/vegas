#pragma once

class TESForm;
class TESPackage;

class PackageList {
public:
    // 0x0067e420
    void AddPackage(::TESPackage *);
    // 0x0067e560
    void InitItem(::TESForm *);
};
