#pragma once

class ActorPackageContext;
struct BGSLoadFormBuffer;
class TESPackage;

class BaseProcess {
public:
    // 0x00717e50
    ::ActorPackageContext *GetCurrentProcessData();
    // 0x00859670
    ::TESPackage *GetOneTimePackage();
    // 0x008d03a0
    void StopPackage();
    // 0x008d1050
    void ApplyLoadBuffer(::BGSLoadFormBuffer *);
};
