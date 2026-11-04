#pragma once

class TESFile;
class TESForm;

class PackageEventActionData {
public:
    // 0x0067dd20
    void Load(::TESFile *);
    // 0x0067e190
    void InitItem(::TESForm *);
    // 0x00680890
    PackageEventActionData();
};
