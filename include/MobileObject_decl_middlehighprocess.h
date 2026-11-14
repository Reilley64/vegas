// Source layout: MobileObject. PC corrections are in generate_headers.py.
#ifndef FNV_MOBILEOBJECT_H
#define FNV_MOBILEOBJECT_H

#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/symbols_00574000.h"
#include "layout_support.h"
#include "TESObjectREFR_decl_middlehighprocess.h"
struct BGSLoadFormBuffer;
struct SoundPlaybackHandle;
class TESPackage;
class bhkCharacterController;
class MobileObject : public TESObjectREFR
{
  public:
    BaseProcess* m_pBaseProcess;        // +0x68
    TESObjectREFR* m_pLinkedReference;  // +0x6C
    MobileObject* m_pMobileObject;      // +0x70
    float ProcessReferenceState;        // +0x74
    float ReferenceMobileState;         // +0x78
    bool m_bFirstFlag;                  // +0x7C
    bool m_bSecondBooleanValue;              // +0x7D
    bool m_bThirdFlag;                  // +0x7E
    bool m_bFourthBooleanValue;                // +0x7F
    bool m_bFifthFlag;                  // +0x80
    bool m_bSixthFlag;                  // +0x81
    bool m_bSeventhFlag;                // +0x82
    bool m_bEighthFlag;                 // +0x83
    char m_cCharacterValue;             // +0x84
    bool m_bNinthFlag;                  // +0x85
    bool m_bTenthFlag;                  // +0x86
    bool m_bThirdActorFlag;             // +0x87
    virtual void StartHighProcess(void);
    virtual void Unk_91(void);
    virtual void Unk_92(void);
    virtual void Unk_93(void);
    virtual void Unk_94(void);
    virtual void Unk_95(void);
    virtual void Unk_96(void);
    virtual void Unk_97(void);
    virtual void Unk_98(void);
    virtual void Unk_99(void);
    virtual void Unk_9A(float arg0);
    virtual void Unk_9B(void);
    virtual void Unk_9C(void);
    virtual void Unk_9D(void);
    virtual void Unk_9E(void);
    virtual void Unk_9F(void* arg0);
    virtual void Unk_A0(void);
    virtual void Unk_A1(void);
    virtual void Unk_A2(void);
    virtual void Unk_A3(void* arg0, bool arg1);
    virtual void Unk_A4(void);
    virtual void Unk_A5(void);
    virtual void Unk_A6(void);
    virtual void Unk_A7(void);
    virtual void Unk_A8(void);
    virtual void Unk_A9(void);
    virtual void Unk_AA(NiPoint3& arg0);
    virtual void Unk_AB(NiPoint3& result);
    virtual void Unk_AC(void);
    virtual void Unk_AD(void);
    virtual void Unk_AE(void);
    virtual float GetCurrentTargetDistance(bool ignoreImmobile);
    virtual void Unk_B0(void);
    virtual void SetFurnitureHeading(float heading);
    virtual TESObjectREFR* GetCurrentTarget();
    virtual void Unk_B3(void);
    virtual void Unk_B4(void);
    virtual void Unk_B5(void);
    virtual void Unk_B6(void);
    virtual void SetActorEssentialState(int value);
    virtual void Unk_B8(void);
    virtual void Unk_B9(void);
    virtual bool Unk_BA();
    virtual void Unk_BB(void);
    virtual void Unk_BC(void);
    virtual void Unk_BD(void);
    virtual void Unk_BE(void);
    virtual void Unk_BF(void);
    virtual void Unk_C0(void);
    void Revert(BGSLoadFormBuffer* buffer);
    bhkCharacterController* GetPhysicsCharacterController();
    bool IsActorDead();
    bool GetCharControllerFlag() const;
    SoundPlaybackHandle PlaySoundByEditorName(const char* editorName, bool loop, unsigned int flags, bool unused);
    void AdvanceMovement(float delta);
    float GetLooking() const;
    bool IsInDialogueWithPlayer() const;
    void ProcessAnimation();
    TESPackage* GetCurrentPackage() const;
    bool IsCombatStateActive() const;
    PROCESS_TYPE GetCurrentProcessLevel();
};
#endif
