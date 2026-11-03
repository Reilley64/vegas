#pragma once

class TESForm;
class TESObjectREFR;
enum PACKAGE_OBJECT_TYPE;
enum PACK_TARG_TYPE;

class PackageTargetRecord {
public:
    // 0x00519b00
    int GetTargetKind();
    // 0x00680020
    ::TESObjectREFR *GetReferenceTarget();
    // 0x00680050
    ::TESForm *GetTargetForm();
    // 0x00680080
    ::PACKAGE_OBJECT_TYPE GetTargetObjectType();
    // 0x006800b0
    void SetTargetKind(::PACK_TARG_TYPE);
    // 0x00680110
    void SetTargetObjectReference(::TESObjectREFR *);
    // 0x00680170
    void FUN_00680170(void *);
    // 0x006803b0
    void InitItem(::TESForm *);
};
