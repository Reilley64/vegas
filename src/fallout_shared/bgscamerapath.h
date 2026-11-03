// Unit-local header for fallout_shared/bgscamerapath.cpp.
#ifndef FNV_BGSCAMERAPATH_UNIT_H
#define FNV_BGSCAMERAPATH_UNIT_H

#include <cstdint>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_005ffbf0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_011ca000.h"
#include "layout_support.h"
class TESConditionItem;
#include "PerkEntryConditionSet.h"
#include "TESForm.h"
class BGSCameraPath;
class BGSCameraShot;
class NiFormArray
{
  public:
    unsigned int GetIndexOfForm(TESForm*);
    TESForm*& FUN_00877a30(unsigned int index);
    void SetSize(unsigned int size, unsigned int* oldSize);
    void Compact();
    void SetFormAtIndex(unsigned int index, TESForm* form);
};
class CameraShotData;
class CameraShotData
{
  public:
    unsigned char cFlags;  // +0x0, 1 bytes
    // void __cdecl CameraShotData::*()
};
class TESConditionInit
{
  public:
    void InitItem(TESForm* form);
};
class BGSCameraPath : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    PerkEntryConditionSet Conditions;                         // +0x18, 8 bytes
    BSSimpleList<BGSCameraShot*> m_kCameraShotList;  // +0x20, 8 bytes
    CameraShotData data;                             // +0x28, 1 bytes
    unsigned char layoutPadding29[3];
    NiFormArray* m_pPathArray;           // +0x2C, 4 bytes
    BGSCameraPath* m_pFirstCameraPath;   // +0x30, 4 bytes
    BGSCameraPath* m_pSecondCameraPath;  // +0x34, 4 bytes
    BGSCameraPath();
    bool Load(TESFile*);
    bool HasMissingPathArray();
    NiFormArray* GetEntryObject();
    void ResetFormData();
    void ClearData();
    void AssignParentPath(BGSCameraPath* parent);
    virtual void InitItem();
    BGSCameraPath* GetPrevPath();
    void SetPathArray(NiFormArray* paths);
    int HasNameForWarning();
    BSSimpleList<BGSCameraShot*>* GetShotList();
    PerkEntryConditionSet* GetConditions();
};
class BGSCameraPath;
class CameraPathManager
{
  public:
public:
    static ::BGSCameraPath *GetTextureResourcePath();
};
class BGSImpactData
{
  public:
};
class FUN_005a71d0
{
  public:
    std::uintptr_t parent, previous;
};
class ScriptVariableInfo;
class TESTopicInfo;
template <class T> class NiTMallocInterface;
template <class T, class A> class NiTLargeArray;
template <> class NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >
{
  public:
    TESTopicInfo* RemoveAt(unsigned int);
};
template <> class BSSimpleList<ScriptVariableInfo*>
{
  public:
};
class CameraFileFormType
{
  public:
    ENUM_FORM_ID GetTESForm();
};
class TESSound;
class BGSAcousticSpace
{
  public:
};
class CameraCondition
{
  public:
    void Load(TESFile*);
};
#endif
