
// src/fallout_shared/tesobjectcell_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x005571a0: the skeleton of src/fallout_shared/tesobjectcell.cpp
// with declarations corrected to what the original code does (tesobjectcell_packet.h: class TESForm; class NiNode; -> class TESForm { public: virtual void TESFormV00();; tesobjectcell_packet.h: class TESObjectREFR { public: static BGSEncounterZ -> class TESObjectREFR : public TESForm { public: sta; tesobjectcell_packet.h: T& GetItem(); BSSimpleList* GetNext();). Move the function to its real unit once
// that unit declares it this way.

#include <new>
#include "fnv/decl/B56B250Ref.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_005651e0_shell.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/LodGrid.h"
#include "fnv/decl/ML.h"
#include "fnv/decl/Ref3.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "tesobjectcell_packet_decl_tesobjectcell.h"
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();

class TES
{
  public:
};
struct ModelLoader
{
};
class TESBoundObject : public TESForm
{
};
class TESObjectSTAT : public TESBoundObject
{
};
// @fnv 0x005571a0
void TESObjectCELL::FUN_005571a0(bool active)
{
    CellRefLockEnter();
    void* list = ((void *)(reinterpret_cast<::LodGrid *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00458be0((::LodCell *)(::TESObjectCELL *)(this), (::LodPoint *)(0))));
    BSSimpleList<TESObjectREFR*>* terrain = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (terrain)
    {
        TESObjectREFR* reference = ((::TESObjectREFR *)(new ((void *)(terrain)) ::Vec3()));
        if (reference && (((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == DAT_011ca238 || ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == DAT_011ca230))
        {
            if (!reference->GetNiNode() || reinterpret_cast<::FUN_005651e0_shell *>((reference))->FUN_005651e0())
            {
                if (!reference->GetDisabled() && !reinterpret_cast<::FUN_00440d80_shell *>((reference))->FUN_00440d80() && (!active || reinterpret_cast<::B56B250Ref *>((reference))->FUN_0056b250()))
                    reinterpret_cast<::ML *>((::g_modelLoader))->FUN_00444850((::Ref *)(reference), (int)(list), 1);
            }
            else
            {
                if (reference->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((reference))->FUN_00440d80())
                    reference->Set3D(0, true);
            }
        }
        terrain = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((terrain))->FUN_00726070()));
    }
    terrain = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    while (terrain)
    {
        TESObjectREFR* other = ((::TESObjectREFR *)(new ((void *)(terrain)) ::Vec3()));
        if (other && ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((other))->FUN_007af430())) != DAT_011ca238 && ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((other))->FUN_007af430())) != DAT_011ca230)
        {
            if (!other->GetNiNode() || reinterpret_cast<::FUN_005651e0_shell *>((other))->FUN_005651e0())
            {
                if (!other->GetDisabled() && !reinterpret_cast<::FUN_00440d80_shell *>((other))->FUN_00440d80() && (!active || reinterpret_cast<::B56B250Ref *>((other))->FUN_0056b250()))
                    reinterpret_cast<::ML *>((::g_modelLoader))->FUN_00444850((::Ref *)(other), (int)(list), 1);
            }
            else
            {
                if (other->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((other))->FUN_00440d80())
                    other->Set3D(0, false);
            }
        }
        terrain = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((terrain))->FUN_00726070()));
    }
    ::FUN_00541ae0((char *)this);
}
