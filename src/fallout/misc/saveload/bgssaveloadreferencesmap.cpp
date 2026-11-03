// fallout/misc/saveload/bgssaveloadreferencesmap.cpp: BGSSaveLoadReferencesMap, BGSCellNumericIDArrayMap (10 functions)

#include "fnv/form_fields.h"
#include "fnv/simple_array_item.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00843750_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0084e6a0_shell.h"
#include "fnv/decl/FUN_00852fa0_class.h"
#include "fnv/decl/FormBufferContext.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/ReconstructMapHelper.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/SaveLoadGame_8495d0.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_0084e000.h"
#include "fnv/symbols_0084f000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_011dd000.h"
#include "bgssaveloadreferencesmap_decls.h"

// @fnv 0x00852B60
void BGSSaveLoadReferencesMap::Clear()
{
    reinterpret_cast<::FUN_00438af0_Class *>(&(m_kReferenceIDMap))->FUN_00438af0();
    m_kCellReferences.Clear();
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_kWorldspaceCellReferenceMaps))->GetFirstPos();
    while (position)
    {
        struct WorldspaceReferences
        {
            BGSCellNumericIDArrayMap* referencesMap;
            unsigned int worldspaceID;
        } entry;
        entry.worldspaceID = 0;
        entry.referencesMap = 0;
        reinterpret_cast<::C6b7f20_Map *>(&(m_kWorldspaceCellReferenceMaps))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(entry.worldspaceID), (void **)&(entry.referencesMap));
        delete entry.referencesMap;
    }
    reinterpret_cast<::FUN_00438af0_Class *>(&(m_kWorldspaceCellReferenceMaps))->FUN_00438af0();
}

// @fnv 0x008528D0
void BGSCellNumericIDArrayMap::Clear()
{
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (position)
    {
        struct CellReferenceIDs
        {
            BSSimpleArray<unsigned int, 1024>* referenceIDs;
            unsigned int cellKey;
        } entry;
        entry.cellKey = 0;
        entry.referenceIDs = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(entry.cellKey), (void **)&(entry.referenceIDs));
        delete entry.referenceIDs;
    }
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct OL4A
{
    OL4A(int);
    ~OL4A();
    int d[4];
};
struct OL4B
{
    OL4B();
    ~OL4B();
    int d[4];
};
struct OL4C
{
    OL4C(int);
    ~OL4C();
    int d[4];
};
struct FUN_00852a70
{
    OL4A a;
    OL4B b;
    OL4C c;
    FUN_00852a70();
};
// Initializes members a and c with 0x25 and default-constructs b.
// @fnv 0x00852a70
FUN_00852a70::FUN_00852a70() : a(0x25), c(0x25)
{}

struct FUN_00852870_cls
{
    void FUN_00852870();
};

struct FUN_00852840_shell : FUN_00852870_cls
{
    void* FUN_00852840(unsigned int flags);
};

struct LS3de0
{
    unsigned int Find(unsigned int&, unsigned int, bool(__cdecl*)(int const*, int const*));
};
struct DummyPointerMap
{
};

struct FUN_00852a10_shell : DummyPointerMap
{
    void RemoveReference(unsigned int a1, unsigned int a2);
};

// @fnv 0x00852a10
void FUN_00852a10_shell::RemoveReference(unsigned int auiKey, unsigned int a2)
{
    unsigned int icellKey = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(this))->FUN_00853130(auiKey, (::fnv_00853130::CombatThreatRecord *&)(icellKey)))
    {
        unsigned int idx = reinterpret_cast<LS3de0*>(icellKey)->Find(a2, 0, ::FUN_009a3830);
        if (idx != 0xFFFFFFFF)
        {
            reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>((reinterpret_cast<LS3de0*>(icellKey)))->FUN_009a4320(idx, 1);
        }
    }
}

struct Base52810
{
};
extern int DAT_0107fef4;
struct Cls52810 : Base52810
{
    void* FUN_00852810();
};
// Calls FUN_00852fa0 with 0x25, stores &DAT_0107fef4 into the object's first field, and returns this.
// @fnv 0x00852810
void* Cls52810::FUN_00852810()
{
    reinterpret_cast<::FUN_00852fa0_class *>(this)->FUN_00852fa0(0x25);
    *(void**)this = (void*)&DAT_0107fef4;
    return this;
}

struct NiPoint3;
struct WsH
{
};
struct FUN_00852cd0_shell
{
    void RemoveReferenceFromCell(unsigned int aiCellID, unsigned int aiReferenceID, NiPoint3 const& arPos);
};
// Looks up the numeric ID array for aiCellID and removes the reference keyed by the world coordinate of arPos.
// @fnv 0x00852cd0
void FUN_00852cd0_shell::RemoveReferenceFromCell(unsigned int aiCellID, unsigned int aiReferenceID,
                                                 NiPoint3 const& arPos)
{
    BSSimpleArray<unsigned int, 1024>* pnumericIDArray = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)((char*)this + 0x20))))->FUN_00853130(aiCellID, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)pnumericIDArray)))
    {
        unsigned int uiCoordKey;
        uiCoordKey = ::FUN_00587440((const ::NiPoint3 *)&(arPos));
        ((FUN_00852a10_shell*)pnumericIDArray)->RemoveReference(uiCoordKey, aiReferenceID);
    }
}

struct S00852950
{
};
struct SetAtHelper
{
};
struct FUN_00852c00_shell : FUN_00852840_shell
{
    void AddReferenceToCell(unsigned int aiCellID, unsigned int aiReferenceID, NiPoint3 const& arPos);
};
struct PSM3
{
    PSM3();
    ~PSM3();
    int d[4];
};
struct BSSimpleArrayActor
{
};
struct FUN_00852950_shell : DummyPointerMap
{
    unsigned int GetOrCreateEntryAdd(unsigned int aiKey, void* apValue);
};
// Looks up or creates the per-cell OL4B map for aiCellID, then inserts aiReferenceID under the key derived from arPos.
// @fnv 0x00852c00
void FUN_00852c00_shell::AddReferenceToCell(unsigned int aiCellID, unsigned int aiReferenceID, NiPoint3 const& arPos)
{
    OL4B* pNumericIDArray = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)((char*)this + 0x20))))->FUN_00853130(aiCellID, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)pNumericIDArray)))
    {
        pNumericIDArray = new OL4B;
        reinterpret_cast<::FUN_00844700_Class *>((((SetAtHelper*)((char*)this + 0x20))))->FUN_00844700(aiCellID, (unsigned int)pNumericIDArray);
    }
    int key = ::FUN_00587440((const ::NiPoint3 *)&(arPos));
    reinterpret_cast<::FUN_00852950_shell *>((((S00852950*)pNumericIDArray)))->GetOrCreateEntryAdd(key, (void *)(aiReferenceID));
}
// Looks up aiKey in the map; if absent, allocates a PSM3 and stores it, then adds apValue to the entry and returns the result.
// @fnv 0x00852950
unsigned int FUN_00852950_shell::GetOrCreateEntryAdd(unsigned int aiKey, void* apValue)
{
    void* pEntry = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)this)->FUN_00853130(aiKey, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)pEntry)))
    {
        pEntry = new PSM3;
        reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(aiKey, (unsigned int)pEntry);
    }
    return reinterpret_cast<::FUN_00438690 *>((((BSSimpleArrayActor*)pEntry)))->FUN_007cb2e0((unsigned int *)&(apValue));
}

struct B852AE0MapA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~B852AE0MapA();
};

struct B852AE0MapB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~B852AE0MapB();
};

struct B852AE0Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~B852AE0Base();
};

// BGSSaveLoadReferencesMap destructor
class FUN_00852ae0 : public B852AE0Base
{
  public:
    B852AE0MapA m_kMapA;
    B852AE0MapB m_kMapB;

    ~FUN_00852ae0();
};

// @fnv 0x00852ae0
FUN_00852ae0::~FUN_00852ae0()
{
    reinterpret_cast<::BGSSaveLoadReferencesMap *>(this)->Clear();
}

struct Loader2e40
{
};
struct Change2e40
{
    int key;
    Loader2e40 loader;
};
struct Changes2e40
{
    Change2e40* FUN_009a4250(unsigned int);
};
struct Host2e40
{
};
int __cdecl FUN_0084e730(unsigned int, int, int);
struct Info2e40
{
    int unk00, unk04, cellID, x, y, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Info2e40();
};
struct Forms2e40
{
};
struct Target2e40
{
    void FUN_00852e40(unsigned int, Forms2e40*);
};
// @fnv 0x00852D20
void BGSSaveLoadReferencesMap::LoadCellReferences(TESObjectCELL* cell, BGSReconstructFormsInAllFilesMap* forms)
{
    struct CellReferences
    {
        BGSCellNumericIDArrayMap* referencesMap;
        unsigned int cellKey;
    } cellReferences;
    cellReferences.referencesMap = 0;
    cellReferences.cellKey = 0;
    if (cell->IsCellInterior())
    {
        cellReferences.cellKey = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((cell))->FUN_0084e3a0()));
        cellReferences.referencesMap = &m_kCellReferences;
    }
    else
    {
        cellReferences.cellKey = ::PackShortPair(cell->GetCellGridX(), cell->GetCellGridY());
        reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&(m_kWorldspaceCellReferenceMaps))->FUN_00853130(reinterpret_cast<::FormFields *>(cell->GetParentWorldSpace())->iFormID, (::fnv_00853130::CombatThreatRecord *&)(cellReferences.referencesMap));
    }
    if (cellReferences.referencesMap)
    {
        BSSimpleArray<unsigned int, 1024>* referenceIDs = 0;
        if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((cellReferences.referencesMap))->FUN_00853130(cellReferences.cellKey, (::fnv_00853130::CombatThreatRecord *&)(referenceIDs)))
        {
            for (unsigned int index = 0; index < SimpleArraySize(referenceIDs); ++index)
                reinterpret_cast<::Target2e40 *>(this)->FUN_00852e40(SimpleArrayItem<unsigned int>(referenceIDs, index), (::Forms2e40 *)(forms));
            reinterpret_cast<::NiTMap_S *>((cellReferences.referencesMap))->RemoveKey(cellReferences.cellKey);
            delete referenceIDs;
        }
    }
}
// @fnv 0x00852e40
void Target2e40::FUN_00852e40(unsigned int uiRefID, Forms2e40* forms)
{
    Change2e40* change = ((::Changes2e40 *)(::FUN_00559450((int *)((*reinterpret_cast<::Host2e40 * *>(&::g_BGSSaveLoadGame))))))->FUN_009a4250(uiRefID);
    if (change)
    {
        int iChangeType = FUN_0084e730(uiRefID, 0x3a, change->key);
        if (iChangeType != 5 && iChangeType != 6)
        {
            FUN_00845cc0(
                "SAVELOAD: Ref %08X is in the references map but is neither a created reference or a moved reference",
                uiRefID);
            return;
        }
        if (!((void *)(::FUN_00559450((int *)&(change->loader)))))
        {
            FUN_00845cc0(
                "SAVELOAD: Ref %08X is in the references map but there is no unloaded buffer for it in the changes map",
                uiRefID);
            return;
        }
        Info2e40 changeInfo;
        ::FUN_0084e930((::BGSLoadFormBuffer *)(void *)(((void *)(reinterpret_cast<::FormBufferContext *>(&(change->loader))->FUN_00866390()))), (::INITIAL_DATA_TYPE)(iChangeType), &changeInfo);
        if (iChangeType == 5)
        {
            TESObjectCELL* cell = ((::TESObjectCELL *)(::ResolveReferenceForm(uiRefID, (::ReferencePlacementData *)(::Info2e40 *)(&changeInfo), (::TESForm *)(false))));
            if (cell)
                reinterpret_cast<::SaveLoadGame_8495d0 *>(((*reinterpret_cast<::Host2e40 * *>(&::g_BGSSaveLoadGame))))->ApplyUnloadedChanges((::TESForm *)(cell));
        }
        else
        {
            TESObjectCELL* interior = 0;
            TESWorldSpace* world = 0;
            if (reinterpret_cast<::FUN_0084e6a0_shell *>(&(changeInfo))->FUN_0084e6a0((*(::TESObjectCELL * *)(&interior)), (*(::TESWorldSpace * *)(&world))))
            {
                if (interior)
                    reinterpret_cast<::FUN_00843750_shell *>((forms))->FUN_00843750((::FUN_00843750_Form *)(interior), uiRefID, false);
                else
                    reinterpret_cast<::ReconstructMapHelper *>((forms))->FUN_008438b0((::ExtendedForm *)(world), changeInfo.x, changeInfo.y, uiRefID, false);
            }
            else
            {
                FUN_00845cc0("CELLS: Could not find cell or worldspace %08X for moved reference %08X",
                             changeInfo.cellID, uiRefID);
            }
        }
    }
}

class FUN_008531b0
{
  public:
    virtual ~FUN_008531b0();

};

class FUN_00852870 : public FUN_008531b0
{
  public:
    virtual ~FUN_00852870();
};
// Calls FUN_00852870, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00852840
void* FUN_00852840_shell::FUN_00852840(unsigned int flags)
{
    reinterpret_cast<::FUN_00852870 *>(this)->FUN_00852870::~FUN_00852870();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// The destructor calls FUN_008528d0.
// @fnv 0x00852870
FUN_00852870::~FUN_00852870()
{
    reinterpret_cast<::BGSCellNumericIDArrayMap *>(this)->Clear();
}
