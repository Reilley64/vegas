#pragma once

class BGSBipedModelList;
class BSFaceGenModel;
class BipedAnim;
class TESForm;
enum BIPED_OBJECT;
enum SEX;

class TESBipedModelForm {
public:
    // 0x004802f0
    TESBipedModelForm();
    // 0x00480750
    void InitItem(::TESForm *);
    // 0x00480af0
    bool HasBipedModel(::BIPED_OBJECT, bool, ::BGSBipedModelList *);
    // 0x00480bd0
    void SetBipedModel(::BipedAnim *, ::SEX, ::BIPED_OBJECT);
    // 0x00480ce0
    ::BSFaceGenModel *FUN_00480ce0();
    // 0x00480d10
    bool IsPowerArmor();
    // 0x00480db0
    static ::TESBipedModelForm *GetFormAsBipedModel(const ::TESForm *);
    // 0x004c0bd0
    bool GetIsHeavyArmor() const;
};
