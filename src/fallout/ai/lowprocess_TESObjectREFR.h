// fallout/ai/lowprocess_TESObjectREFR.h: declares TESObjectREFR
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00568680_shell.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_00569250_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00575770_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_00565870__FUN_00565870_shell.h"
#include "fnv/decl/fnv_005692a0__FUN_005692a0_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00573000.h"
struct ExtraRadioData;
class LockExtraData;
class ExtraLock;
// Source layout: TESObjectREFR. PC corrections are in generate_headers.py.
#ifndef FNV_TESOBJECTREFR_H
#define FNV_TESOBJECTREFR_H
#include "layout_support.h"
#include "lowprocess_ExtraDataList.h"
#include "PlacedObjectInfo.h"
#include "TESChildCell.h"
#include "lowprocess_TESForm.h"
class TESObjectREFR : public TESForm
{
  public:
    ExtraRadioData* GetExtraRadioData();
    int IsLocked();
    const NiPoint3* FUN_00430830();

    bool Activate(TESObjectREFR*, bool, TESBoundObject*, int);

    TESChildCell tESChildCellComponent;  // +0x18
    TESSound* m_pSoundForm;              // +0x1C
    PlacedObjectInfo data;                       // +0x20
    float m_fObjectScale;                     // +0x3C
    TESObjectCELL* m_pOwningCell;          // +0x40
    ExtraDataList m_kExtraDataCollection;               // +0x44
    CellDataNode* m_pRenderData;        // +0x64
    virtual void Unk_4E(void);
    virtual void Unk_4F(void);
    virtual void vfn_140();
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
    virtual const NiPoint3 vfn_16c();
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
    virtual bool vfn_218();
    virtual bool Unk_87(void);
    virtual bool Unk_88(void);
    virtual void Unk_89(void);
    virtual void Unk_8A(void);
    virtual bool vfn_22c(bool);
    virtual bool Unk_8C(void);
    virtual bool Unk_8D(void);
    virtual void Unk_8E(void);
    virtual void Unk_8F(void);
    enum
    {
        CHANGE_SCRIPT_VARIABLES = 0x80000000u
    };
};
#endif
