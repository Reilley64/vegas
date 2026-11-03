#pragma once

struct ContactList;
struct Entry48;
struct Entry;
struct Flt;
struct Groups;
struct Input;
struct Item;
struct Link;
struct Param;
struct Sink;
struct Sound;
struct TESIdleForm;
template <class, class> struct NiTPrimitiveArray;
template <class> struct NiTMallocInterface;

class Owner {
public:
    // 0x004d7d70
    void *GetByIndex(unsigned int);
    // 0x0050c840
    void *DestroyIfFlagged(unsigned int);
    // 0x0053d2e0
    bool FUN_0053d2e0(int, int, int);
    // 0x00623230
    ::TESIdleForm *GetIdleForm();
    // 0x0069e3b0
    bool BuildGroups(::Input *, ::Groups *);
    // 0x006efd80
    bool CheckLinkCrossing(::Link *, ::Link *, bool);
    // 0x006f6150
    void UpdateReferences(bool);
    // 0x0076b6a0
    void FUN_0076b6a0(::Flt *);
    // 0x007a22d0
    int *FindItemData(int *);
    // 0x008026b0
    void FUN_008026b0();
    // 0x008c64d0
    void FUN_008c64d0(unsigned int, unsigned int);
    // 0x008ca040
    void CallMidVirtualB();
    // 0x0095f6c0
    void FUN_0095f6c0(float);
    // 0x00a51d80
    void AppendColorACPHandleStrings(::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *);
    // 0x00a59f50
    void SetSlot(::Param *);
    // 0x00a76a60
    void FUN_00a76a60(::Item *);
    // 0x00ad1960
    ::Entry48 *FUN_00ad1960(int, int, int, int, bool);
    // 0x00adcd80
    void AddSound(::Sound *);
    // 0x00b5fd60
    void FUN_00b5fd60();
    // 0x00c06f80
    void InitShaderConstantMaps();
    // 0x00c51700
    void FUN_00c51700(int);
    // 0x00c67bc0
    void ClearReferences();
    // 0x00ca4f80
    void FUN_00ca4f80(::Sink *);
    // 0x00ca85f0
    void FUN_00ca85f0(unsigned int);
    // 0x00cab0e0
    void FUN_00cab0e0(int, int, float);
    // 0x00ce1420
    int FUN_00ce1420(void *, int, float);
    // 0x00cf5ea0
    ::Owner *FUN_00cf5ea0();
    // 0x00d04a80
    void FUN_00d04a80(int, int);
    // 0x00d86b40
    int GetTagValue();
    // 0x00d87c20
    void FUN_00d87c20(int, bool);
    // 0x00d97070
    void FUN_00d97070(void *);
    // 0x00d9bef0
    unsigned short *AppendElement(unsigned short);
    // 0x00d9e000
    unsigned int FUN_00d9e000();
    // 0x00db1990
    void FUN_00db1990(::ContactList *, ::Input *, float);
    // 0x00def3d0
    volatile unsigned char *CheckPairAgainstThreshold(volatile unsigned char *, int, int);
    // 0x00e7b190
    ::Entry *FUN_00e7b190(unsigned int, unsigned int, unsigned int, unsigned int *);
};
