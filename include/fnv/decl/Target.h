#pragma once

class NiPoint3;
class Task;
struct ActorStand;
struct Context;
struct FUN_0076b630;
struct FileNames;
struct Ref;
struct StrArr;
struct TargetActor;

struct Target {
public:
    // 0x0044f3e0
    void FUN_0044f3e0();
    // 0x0045ac80
    void FUN_0045ac80();
    // 0x00498670
    void RemoveItemFromMap(::Ref *);
    // 0x004c7400
    ::FUN_0076b630 *SelectBestWeapon(::ActorStand *, float *, int, bool);
    // 0x004c8c10
    ::FUN_0076b630 *FUN_004c8c10(int, int);
    // 0x00604310
    bool FUN_00604310(const char *, char *, unsigned int);
    // 0x00650480
    bool FUN_00650480(::FileNames *);
    // 0x00697b70
    bool FindTriangleZ(const ::NiPoint3 &, float, float, float *);
    // 0x00785830
    void SetPage(int);
    // 0x007b1970
    bool FUN_007b1970(float, bool);
    // 0x00800ac0
    void FUN_00800ac0(::TargetActor *, int, bool);
    // 0x00903600
    int GetIntAt(unsigned int);
    // 0x00994050
    bool AdvanceActions(::Context *);
    // 0x00a87020
    void DisableEntry(unsigned int);
    // 0x00b2fdc0
    void FUN_00b2fdc0(unsigned short, unsigned int, unsigned short);
    // 0x00b690d0
    void FUN_00b690d0(::StrArr *);
    // 0x00b90670
    ::Target *FUN_00b90670(unsigned int);
    // 0x00c3fb50
    bool FUN_00c3fb50(::Task *);
    // 0x00c49700
    void CompactEntries();
    // 0x00c8f080
    void FUN_00c8f080();
    // 0x00d2c350
    int ComputeWeightedSum();
    // 0x00e8b630
    void FUN_00e8b630();
    // 0x00ead1e0
    void FUN_00ead1e0();
};
