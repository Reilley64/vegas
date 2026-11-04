#pragma once

class BGSCameraShot;
class PerkEntryConditionSet;
template <class> class BSSimpleList;

class BGSCameraPath {
public:
    // 0x00474cb0
    int HasNameForWarning();
    // 0x00500940
    ::PerkEntryConditionSet *GetConditions();
    // 0x0058a650
    void ClearData();
    // 0x005f36f0
    ::BGSCameraPath *GetPrevPath();
    // 0x005f4bb0
    void AssignParentPath(::BGSCameraPath *);
    // 0x00891170
    ::BSSimpleList< ::BGSCameraShot *> *GetShotList();
};
