
// tesobjectcell_ctx4_variant.cpp: context variant of src/fallout_shared/tesobjectcell.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <new>
#include <cstring>
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Cls.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00421a70_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_005516c0.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0085f850_class.h"
#include "fnv/decl/FUN_008727b0_Class.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Manager859.h"
#include "fnv/decl/SaveLoadGame_8495d0.h"
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00416be0__ResolveExtraOwner.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00858730__FUN_00858730_shell.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004ff000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();

class TESFile;
class TESForm
{
  public:
    virtual ~TESForm();
public:
    bool GetInitialized() const;
public:
    void SetInitializationState(bool);
public:
    ::TESFile *GetFile(int);
};
class BGSLightingTemplate : public TESForm
{
  public:
    virtual ~BGSLightingTemplate();
};
namespace CellLoading {

struct Cell;
struct Reference;
struct Node;
struct Pointer;

struct Name
{
    unsigned int unk0, unk4;
};
struct Extra
{
};

struct Vector
{
    float x, y, z;
};
struct Extras
{
};

struct Reference
{

    virtual void slot0();

    virtual void slot4();

    virtual void slot8();

    virtual void slotc();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual void slot20();

    virtual void slot24();

    virtual void slot28();

    virtual void slot2c();

    virtual void slot30();

    virtual void slot34();

    virtual void slot38();

    virtual void slot3c();

    virtual void slot40();

    virtual void slot44();

    virtual void slot48();

    virtual void slot4c();

    virtual void slot50();

    virtual void slot54();

    virtual void slot58();

    virtual void slot5c();

    virtual void slot60();

    virtual void slot64();

    virtual void slot68();

    virtual void slot6c();

    virtual void slot70();

    virtual void slot74();

    virtual void slot78();

    virtual void slot7c();

    virtual void slot80();

    virtual void slot84();

    virtual void Load();

    virtual void slot8c();

    virtual void slot90();

    virtual void slot94();

    virtual void slot98();

    virtual void slot9c();

    virtual void slota0();

    virtual void slota4();

    virtual void slota8();

    virtual void slotac();

    virtual void slotb0();

    virtual void slotb4();

    virtual void slotb8();

    virtual void slotbc();

    virtual void slotc0();

    virtual void slotc4();

    virtual void slotc8();

    virtual void slotcc();

    virtual void slotd0();

    virtual void slotd4();

    virtual void slotd8();

    virtual void slotdc();

    virtual void slote0();

    virtual void slote4();

    virtual void slote8();

    virtual void slotec();

    virtual void slotf0();

    virtual void slotf4();

    virtual void slotf8();

    virtual void slotfc();

    virtual void slot100();

    virtual void slot104();

    virtual void slot108();

    virtual void slot10c();

    virtual void slot110();

    virtual void slot114();

    virtual void slot118();

    virtual void slot11c();

    virtual void slot120();

    virtual void slot124();

    virtual void slot128();

    virtual void slot12c();

    virtual const char* Name();

};

struct Node
{
    bool FUN_008256d0();
};

struct Pointer
{
    Reference* object;
    Reference* FUN_00458b50();
    ~Pointer();
};
struct Collection
{
    Pointer FUN_00464f60(unsigned int);
};

struct World
{
};

struct Manager
{
};

extern char DAT_0102ece8, DAT_0102ec58, DAT_0102ebd0, DAT_0102eb60, DAT_0102eb10, DAT_01183028, DAT_0118a8d0;


struct Cell : Reference
{

    unsigned int unk4, unk8, unkc, unk10, unk14;
    CellLoading::Name editorName;
    unsigned int unk20, unk24;
    Extra extra;

    void FUN_00542d40();
};

// @fnv 0x00542d40
void Cell::FUN_00542d40()
{

    if (!reinterpret_cast<::TESForm *>(this)->GetInitialized())
    {

        int saved = ::FUN_0046e8a0();
        ::FUN_0043b2b0(1);
        ::FUN_004fffe0(0);
        reinterpret_cast<::fnv_00416be0::ResolveExtraOwner *>(&(extra))->FUN_00416be0((::TESForm *)(::CellLoading::Cell *)(this));
        if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
            reinterpret_cast<::TESFullName *>(&(editorName))->SetFullName((const char *)(0));
        reinterpret_cast<::TESForm *>(this)->SetInitializationState(1);

        if (((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(editorName))->FUN_00408da0())) && std::strlen(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(editorName))->FUN_00408da0()))) > 33)
            ::FUN_005b5e40();

        ::FUN_0043b2b0(0);
        int errors = ::FUN_0046e8a0();
        ::FUN_004fffe0(saved);

        if (errors)
        {
            Cell* other = ((::CellLoading::Cell *)(reinterpret_cast<::TESObjectCELL *>(this)->GetParentWorldSpace()));
            if (!reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior())
            {
                if (other)
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            else
                ::FUN_005b5e40();
        }

        if (((unsigned int)(reinterpret_cast<::FUN_00558b40_shell *>(this)->GetLightingTemplate())))
        {
            unsigned int handle = ((unsigned int)(reinterpret_cast<::FUN_00558b40_shell *>(this)->GetLightingTemplate()));
            ::ResolveFormID(&handle, (::TESFile *)(((int)(reinterpret_cast<::TESForm *>(this)->GetFile(-1)))));
            BGSLightingTemplate* resolved = dynamic_cast<BGSLightingTemplate*>(::FUN_004839c0(handle));
            reinterpret_cast<::fnv_00558b60::FUN_00558b60_shell *>(this)->FUN_00558b60((::fnv_00558b60::BGSLightingTemplate *)(resolved));
            if (!resolved && handle)
                ::FUN_005b5e40();
        }
    }

    bool oldState = reinterpret_cast<::FUN_004623f0_shell *>(((*reinterpret_cast<::CellLoading::World * *>(&::g_BGSSaveLoadGame))))->FUN_004623f0(false);
    Node* node = ((::CellLoading::Node *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
    Node* previous = 0;

    while (node && !node->FUN_008256d0())
    {
        Reference* reference = *((::CellLoading::Reference **)(new ((void *)(node)) ::Vec3()));
        if (!reinterpret_cast<::TESForm *>((reference))->GetInitialized())
        {
            reference->Load();
            reinterpret_cast<::fnv_00858730::FUN_00858730_shell *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_00858730((::TESForm *)(reference));
            reinterpret_cast<::SaveLoadGame_8495d0 *>(((*reinterpret_cast<::CellLoading::World * *>(&::g_BGSSaveLoadGame))))->ApplyUnloadedChanges((::TESForm *)(reference));
        }

        if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) == (*reinterpret_cast<void * *>(&::DAT_011ca254)))
            reinterpret_cast<::FUN_00421a70_shell *>((((::CellLoading::Extras *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_00421a70(((::CellLoading::Vector *)(reinterpret_cast<::TESRecipe *>((reference))->GetData()))->z * ::DAT_0101a6b0);

        if (!reinterpret_cast<::FUN_005516c0 *>(this)->IsCellPersistent() && ((::CellLoading::Cell *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget())) != this)
        {
            if (previous)
                node = ((::CellLoading::Node *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
            else
                node = ((::CellLoading::Node *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        }
        else
        {
            previous = node;
            node = ((::CellLoading::Node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
    }

    if (((::CellLoading::Collection *)(::FUN_0070ec90((char *)this))))
    {
        for (unsigned int i = 0; i < reinterpret_cast<::FUN_00620b80_shell *>((((::CellLoading::Collection *)(::FUN_0070ec90((char *)this)))))->GetReferenceFlags(); i++)
        {
            Pointer item = ((::CellLoading::Collection *)(::FUN_0070ec90((char *)this)))->FUN_00464f60(i);
            ((::CellLoading::Reference *)(::FUN_00559450((int *)&(item))))->Load();
            reinterpret_cast<::SaveLoadGame_8495d0 *>(((*reinterpret_cast<::CellLoading::World * *>(&::g_BGSSaveLoadGame))))->ApplyUnloadedChanges((::TESForm *)(::CellLoading::Reference *)(item.FUN_00458b50()));
        }
    }

    reinterpret_cast<::FUN_004623f0_shell *>(((*reinterpret_cast<::CellLoading::World * *>(&::g_BGSSaveLoadGame))))->FUN_004623f0(oldState);

    if (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
    {
        reinterpret_cast<::Manager859 *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_00859690((::Cell859 *)(::CellLoading::Cell *)(this));
        if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() && ((bool)(reinterpret_cast<::FUN_008727b0_Class *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_008727b0())))
        {
            bool state = reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->EvaluateCondition();
            reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(true);
            reinterpret_cast<::Cls *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_00858af0((::EntryListNode *)(0), (::Entry *)(0), 0);
            reinterpret_cast<::FUN_0085f850_class *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_0085f850(0);
            reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::CellLoading::Manager * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(state);
        }
    }
}

}
