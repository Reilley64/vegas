// Source layout: TESObjectREFR. PC corrections are in generate_headers.py.
#ifndef FNV_TESOBJECTREFR_H
#define FNV_TESOBJECTREFR_H

#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "processlists_layout_support.h"
#include "processlists_ExtraDataList.h"
#include "processlists_OBJ_REFR.h"
#include "processlists_TESChildCell.h"
#include "processlists_TESForm.h"
class BGSEncounterZone;
class ExtraRadioData;
class TESObjectREFR : public TESForm
{
  public:
    TESChildCell tESChildCellComponent;  // +0x18
    TESSound* m_pSoundForm;              // +0x1C
    PlacedObjectInfo data;                       // +0x20
    float m_fObjectScale;                     // +0x3C
    TESObjectCELL* m_pOwningCell;          // +0x40
    ExtraDataList m_kExtraDataCollection;               // +0x44
    CellDataNode* m_pRenderData;        // +0x64
    virtual void Unk_4E(void);
    virtual void Unk_4F(void);
    virtual void Unk_50(void);
    virtual void Unk_51(void);
    virtual bool CastShadows(void);
    virtual void Unk_53(void);
    virtual void Unk_54(void);
    virtual void Unk_55(void);
    virtual void Unk_56(void);
    virtual void Unk_57(void);
    virtual void Unk_58(void);
    virtual void Unk_59(void);
    virtual void Unk_5A(void);
    virtual void Unk_5B(void);
    virtual void Unk_5C(void);
    virtual void Unk_5D(void);
    virtual void Unk_5E(void);
    virtual TESObjectREFR* RemoveItem(TESForm* toRemove, ExtraDataList* extraList, unsigned int count,
                                      unsigned int unk3, unsigned int unk4, TESObjectREFR* destRef, unsigned int unk6,
                                      unsigned int unk7, unsigned int unk8, unsigned char unk9);
    virtual void Unk_60(void);
    virtual void Unk_61(void);
    virtual void Unk_62(void);
    virtual void Unk_63(void);
    virtual void AddItem(TESForm* item, ExtraDataList* xDataList, unsigned int Quantity);
    virtual void Unk_65(void);
    virtual void Unk_66(void);
    virtual void Unk_67(void);
    virtual bool GetIsChildSize(bool checkHeight);
    virtual unsigned int GetActorUnk0148(void);
    virtual void SetActorUnk0148(unsigned int arg0);
    virtual void Unk_6B(void);
    virtual void Unk_6C(void);
    virtual void Unk_6D(void);
    virtual void Unk_6E(void);
    virtual void Unk_6F(void);
    virtual void Unk_70(void);
    virtual void AnimateNiNode(void);
    virtual void GenerateNiNode(bool arg0);
    virtual void Set3D(NiNode* niNode, bool unloadArt);
    virtual NiNode* GetNiNode(void);
    virtual void Unk_75(void);
    virtual void Unk_76(void);
    virtual void Unk_77(void);
    virtual void Unk_78(void);
    virtual AnimData* GetAnimData(void);
    virtual ValidBip01Names* GetValidBip01Names(void);
    virtual ValidBip01Names* CallGetValidBip01Names(void);
    virtual void SetValidBip01Names(ValidBip01Names validBip01Names);
    virtual NiPoint3* GetPos(void) const;
    virtual void Unk_7E(unsigned int arg0);
    virtual void Unk_7F(void);
    virtual void Unk_80(unsigned int arg0);
    virtual void Unk_81(unsigned int arg0);
    virtual void Unk_82(void);
    virtual unsigned int Unk_83(void);
    virtual void Unk_84(unsigned int arg0);
    virtual unsigned int Unk_85(void);
    virtual bool IsCharacter(void);
    virtual bool Unk_87(void);
    virtual bool IsExplosion() const;
    virtual bool IsProjectile() const;
    virtual void Unk_8A(void);
    virtual bool IsDead(bool notEssential) const;  // PC vtable +0x22C
    virtual bool Unk_8C(void);
    virtual bool Unk_8D(void);
    virtual void Unk_8E(void);
    virtual void Unk_8F(void);
    enum
    {
        CHANGE_SCRIPT_VARIABLES = 0x80000000u
    };
    // Public PC declaration/address: JohnnyGuitar TESObjectREFR.cpp, 007AF430.
    // Public PC declarations/addresses: GetExtra 005D43C0; GetExtraData 00527080.
    BSExtraData* GetExtraData(unsigned char type) const;
public:
    ::BGSEncounterZone *FindEncounterZone();
public:
    ::ExtraRadioData *GetExtraRadioData();
public:
    const char *GetModelFilePath();
};
#endif
