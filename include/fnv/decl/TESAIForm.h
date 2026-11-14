#pragma once

class Actor;
class BaseFormComponent;
class TESPackage;
struct PackedRecordData;
template <class> class BSSimpleList;

class TESAIForm {
public:
    // 0x0047ed10
    void InitializeComponent();
    // 0x0047ede0
    void FreeDataComponent();
    // 0x0047ee00
    void SetAggression(unsigned char, bool);
    // 0x0047ee30
    unsigned char GetAssistance();
    // 0x0047eed0
    void SetConfidence(unsigned char, bool);
    // 0x0047ef00
    void SetEnergy(unsigned char, bool);
    // 0x0047ef30
    unsigned char GetResponsibility();
    // 0x0047ef50
    void SetResponsibility(unsigned char, bool);
    // 0x0047ef80
    void SetAIMood(unsigned char);
    // 0x0047efb0
    void SetServiceFlags(unsigned int, bool);
    // 0x0047f020
    void SetTrainingSkill(int);
    // 0x0047f0b0
    void CopyAIDataFromAIDATA(::PackedRecordData *);
    // 0x0047f190
    void BaseFormRecord(::BaseFormComponent *);
    // 0x0047f1e0
    void CopyAISettings(::TESAIForm *);
    // 0x0047f2d0
    void CopyAIPackageList(const ::TESAIForm *);
    // 0x0047f590
    static void FindAvailablePackages(::Actor *, ::BSSimpleList< ::TESPackage *> *, float, float);
};
