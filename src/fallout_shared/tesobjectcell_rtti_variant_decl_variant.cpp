
// src/fallout_shared/tesobjectcell_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x005434d0: the skeleton of src/fallout_shared/tesobjectcell_rtti_variant.cpp
// with declarations corrected to what the original code does (tesobjectcell_packet_rtti_variant.h: public: virtual ~TESObjectCELL(); -> public: virtual ~TESObjectCELL(); virtual void Vir; tesobjectcell_packet_rtti_variant.h: TESObjectCELL += bool FUN_005434d0(struct FormGroupQuery* group); bool IsFormTypeBelowThreshold(struct FormGroupQuery* group); unsigned int FUN_00544). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tesobjectcell_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectCELL, TESObjectREFR, TESWorldSpace). The skeleton of src/fallout_shared/tesobjectcell.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_0041d390_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00437b90_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_004523c0_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00484150_shell.h"
#include "fnv/decl/FUN_005194d0_shell_base.h"
#include "fnv/decl/FUN_00519500_class.h"
#include "fnv/decl/FUN_005441b0_S.h"
#include "fnv/decl/FUN_00544210_shell.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_005455c0_cls.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00548700_Class.h"
#include "fnv/decl/FUN_005516c0.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_00564e60_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0087b400_shell.h"
#include "fnv/decl/FUN_00885a30_Class.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/LodGrid.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/ML.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/PlayerCharacter.h"
#include "fnv/decl/ProcessLists.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/WorldSpaceRefShell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00545560__FUN_00545560Class.h"
#include "fnv/decl/fnv_00548880__FNV_Cell.h"
#include "fnv/decl/fnv_0054ca90__Cell.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/decl/fnv_005656d0__Thing.h"
#include "fnv/decl/fnv_0056a250__FUN_0056a250_shell.h"
#include "fnv/decl/fnv_005728c0__FUN_005728c0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_00548000.h"
#include "fnv/symbols_0054a000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "tesobjectcell_packet_rtti_variant_decl_tesobjectcell_rtti_variant.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();
class CellView;
class MobileObject : public TESObjectREFR
{
};
class RefView : public TESObjectREFR
{
  public:
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual bool IsActor();  // +0x100
    virtual void v0x41();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void Unk_1c4();  // +0x1c4
    virtual void v072();
    virtual void Unk_1cc(int iA, int iB);  // +0x1cc
    virtual void* GetNode3D();             // +0x1d0
    virtual void v0x75();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void SetParentCell(CellView* pkCell);  // +0x228
    virtual void v0x8b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void Unk_240();  // +0x240
    virtual void v091();
    virtual void v092();
    virtual void Unk_24c();  // +0x24c

      // GetDisabled
      // GetParentCell
};
class RefExtra
{
  public:
};
struct RefList
{
    void FUN_005ae3d0(RefView*& rpkRef);  // AddHead
      // IsInList
public:
    bool FUN_005f65d0(void **);
};
class CellNavHandler
{
  public:
};
class CellDataHandler
{
  public:
};
class CellTES
{
  public:
};
class CellPlayer
{
  public:
};
// IsSleepingOrResting
class CellSaveLoad
{
  public:
};
class CellModelLoader
{
  public:
};
class CellProcessLists
{
  public:
};
class CellNodeMap
{
  public:
};
class CellTaskQueue
{
  public:
};
class CellView
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void Unk_0c8(int iValue);  // +0xc8
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    unsigned short m_usPersistentCount;  // +0xa8
    unsigned short unkaa;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    void* m_pkNavMeshes;  // +0xc4

      // CellRefLockEnter
      // CellRefLockLeave
      // RemoveReference
      // IsInterior
    void FUN_00548230(RefView* pkRef, bool bArg);
};
enum ENUM_FORM_ID;
class TESForm
{
  public:
    virtual ~TESForm();
public:
    ::ENUM_FORM_ID GetFormType() const;
public:
    bool GetDisabled() const;
};
class TESObject : public TESForm
{
};
class TESBoundObject : public TESObject
{
};
class TESObjectDOOR : public TESBoundObject
{
  public:
};
class ReferenceList
{
  public:
    TESObjectREFR* item;
    ReferenceList* next;
    ReferenceList();
    ~ReferenceList();
    bool IsEmpty();
    TESObjectREFR*& GetItem();
    ReferenceList* GetNext();
    void Append(TESObjectREFR*& reference);
};
// Verified native methods use only their typed receiver in ECX.

struct FormGroupQuery
{
    unsigned int tag, unk04, value, kind;
};
// @fnv 0x005434d0
bool TESObjectCELL::FUN_005434d0(FormGroupQuery* group)
{

    bool matched = false;

    if (group && group->tag == ::fnv_00543df0::kGroupFormType)
    {

        switch (group->kind)
        {

        case 0:
            matched = reinterpret_cast<::FUN_00484150_shell *>(this)->IsFormTypeBelowThreshold((::FormRecordHeader *)(group));
            break;

        case 2:

            if (IsCellInterior() && reinterpret_cast<::FUN_005441b0_S *>(this)->FUN_005441b0() < group->value)

                matched = true;

            break;

        case 3:

            if (IsCellInterior() && reinterpret_cast<::FUN_00544210_shell *>(this)->FUN_00544210() < group->value)

                matched = true;

            break;

        case 6:
        case 8:
        case 9: {

            TESObjectCELL* cell = dynamic_cast<TESObjectCELL*>(FUN_004839c0(group->value));

            if (cell)

                matched = MatchForm(cell);

            break;
        }

        case 4:

            if (!IsCellInterior())
            {

                if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
                    matched = true;

                else if (reinterpret_cast<::FUN_005441b0_S *>(this)->FUN_005441b0() < group->value)
                    matched = true;
            }
            else
                matched = true;

            break;

        case 5:

            if (!IsCellInterior())
            {

                if (reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent())
                    matched = true;

                else if (reinterpret_cast<::FUN_00544210_shell *>(this)->FUN_00544210() < group->value)
                    matched = true;
            }
            else
                matched = true;

            break;

        case 1:

            if (!IsCellInterior())
            {

                TESWorldSpace* world = dynamic_cast<TESWorldSpace*>(FUN_004839c0(group->value));

                if (world)

                    matched = MatchForm(world);
            }
            else
                matched = true;

            break;

        case 7:
            matched = true;
            break;
        }
    }

    return matched;
}
