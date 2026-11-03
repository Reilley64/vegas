#pragma once

struct Arg3;
struct Arg;
struct C_00e8f010;
struct TwoComponentVector;
struct VBEntry;

struct ThisObj {
public:
    // 0x00683c10
    void BuildSkinPartitions();
    // 0x00a63cb0
    void SetFlagsRecursively(::Arg *);
    // 0x00e72aa0
    bool BuildPacketEntries(void *, void *, ::Arg3 *, void *, void *, void *);
    // 0x00e8c570
    ::VBEntry *FUN_00e8c570(::C_00e8f010 *, unsigned short, const ::TwoComponentVector *, const float *, const unsigned int *, unsigned int, ::VBEntry *, void *);
};
