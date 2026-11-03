// fallout_shared/pathfinding/navmeshinfomap.cpp: NavMeshInfoMap, WorkerNavMap, std, NavMeshInfo and more (26 functions)

#include <malloc.h>
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00460340_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005a8040_class.h"
#include "fnv/decl/FUN_0068f6b0_shell.h"
#include "fnv/decl/FUN_00693d30_shell.h"
#include "fnv/decl/FUN_00695370_class.h"
#include "fnv/decl/FUN_006986d0_cls.h"
#include "fnv/decl/FUN_0069dfb0_class.h"
#include "fnv/decl/FUN_0069e090_class.h"
#include "fnv/decl/FUN_006b4880_Class.h"
#include "fnv/decl/FUN_006b48f0_shell.h"
#include "fnv/decl/FUN_006b4b50_shell.h"
#include "fnv/decl/FUN_006b7eb0_t.h"
#include "fnv/decl/FUN_006b8060_class.h"
#include "fnv/decl/FUN_006b8160_class.h"
#include "fnv/decl/FUN_006bf8f0_Class.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NavInfo.h"
#include "fnv/decl/NavMeshInfoSaveShell.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESFormSortProxy.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00484730__FUN_00484730_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00697590__FUN_00697590_shell.h"
#include "fnv/decl/fnv_006b4e10__FUN_006b4e10_shell.h"
#include "fnv/decl/fnv_006b5a90__FUN_006b5a90_shell.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_0084b5c0__FUN_0084b5c0_Array.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00690000.h"
#include "fnv/symbols_00695000.h"
#include "fnv/symbols_0069b000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_01011000.h"
#include "navmeshinfomap_decls.h"

// Scans every outer/inner map entry and returns false if any NavMeshInfoArray with more than one element has fewer than size-1 entries with bounds.
// @fnv 0x006b7cb0
bool NavMeshInfoMap::ValidateNavMeshInfoArrays()
{
    bool bResult = true;
    void* pOuterPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_kNavMeshInfoArraysByWorldspace))->GetFirstPos();
    while (pOuterPos)
    {
        OuterPair outer;
        reinterpret_cast<::C6b7f20_Map *>(&(m_kNavMeshInfoArraysByWorldspace))->FUN_006b7f20((::C6b7f20_Node **)&(pOuterPos), (unsigned int *)&(outer.uiOuterKey), (void **)&(outer.pInnerMapRaw));
        void* pInnerPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((CellKeyMap*)outer.pInnerMapRaw)))->GetFirstPos();
        while (pInnerPos)
        {
            unsigned int uiInnerKey;
            void* pArrayRaw;
            reinterpret_cast<::C6b7f20_Map *>((((CellKeyMap*)outer.pInnerMapRaw)))->FUN_006b7f20((::C6b7f20_Node **)&(pInnerPos), (unsigned int *)&(uiInnerKey), (void **)&(pArrayRaw));
            if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((NavMeshInfoArray*)pArrayRaw)))->GetName())) > 1)
            {
                InnerCounts counts;
                counts.uiValid = 0;
                for (counts.uiIndex = 0; counts.uiIndex < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((NavMeshInfoArray*)pArrayRaw)))->GetName())); counts.uiIndex++)
                {
                    if (((::NavMeshBounds *)(reinterpret_cast<::LowProcess *>((((::NavMeshInfo *)(reinterpret_cast<::S3e60 *>((((NavMeshInfoArray*)pArrayRaw)))->FUN_006a7ad0((int)counts.uiIndex)))))->GetPackageObjectType())))
                        counts.uiValid++;
                }
                if (counts.uiValid < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((NavMeshInfoArray*)pArrayRaw)))->GetName())) - 1)
                    bResult = false;
            }
        }
    }
    return bResult;
}

namespace std {
float abs(float value);
}

struct NavMeshValidation
{
    unsigned int id;
    void* info;
    TESForm* parent;
};

// Validates each NavMeshInfo entry, warns and deletes entries with missing parent space or bad approx location, otherwise links parent and initializes it.
// @fnv 0x006b63c0
void NavMeshInfoMap::InitItem()
{
    void* pPos;
    {
        NavMeshInfoArray DeleteArray;
        pPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_kNavMeshInfosByFormID))->GetFirstPos();
        while (pPos)
        {
            bool bDelete;
            {
                NavMeshValidation entry;
                reinterpret_cast<::C6b7f20_Map *>(&(m_kNavMeshInfosByFormID))->FUN_006b7f20((::C6b7f20_Node **)&(pPos), (unsigned int *)&(entry.id), (void **)&(entry.info));
                bDelete = false;
                entry.parent = ::FUN_004839c0(((NavMeshInfo*)entry.info)->m_uiParentSpaceID);
                if (!entry.parent)
                {
                    ::FUN_005b5e40();
                    bDelete = true;
                }
                if (std::abs(((NavMeshInfo*)entry.info)->approxZ) > 1.0e14f)
                {
                    ::FUN_005b5e40();
                    bDelete = true;
                }
                if (bDelete)
                {
                    reinterpret_cast<::FUN_00438690 *>(&(DeleteArray))->FUN_007cb2e0((unsigned int *)&((NavMeshInfo*&)entry.info));
                }
                else
                {
                    ((NavMeshInfo*)entry.info)->m_pParentSpace = entry.parent;
                    InsertNavMeshInfo((NavMeshInfo*)entry.info);
                }
                if (!m_bKeepNavMeshLoaded)
                    ((NavMeshInfo*)entry.info)->ReleaseNavMesh();
            }
        }
        for (unsigned int uiIndex = 0; uiIndex < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(DeleteArray))->GetName())); uiIndex++)
        {
            reinterpret_cast<::NiTMap_S *>(&(m_kNavMeshInfosByFormID))->RemoveKey(((unsigned int)(::FUN_00559450((int *)(DeleteArray[uiIndex])))));
            delete DeleteArray[uiIndex];
        }
        m_bKeepNavMeshLoaded = true;
        ValidateNavMeshInfoArrays();
    }
}

// @fnv 0x006b46a0
NavMeshInfo::NavMeshInfo()
{
    uiFlags = 0;
    m_uiNavMeshID = 0;
    m_uiParentSpaceID = 0;
    m_pParentSpace = 0;
    m_uiPathingFlags = 0xdeaddead;
    m_kNavMeshPosition = NiPoint3::ZERO;
    pBounds = 0;
    m_pLocationNavMesh = 0;
    m_fStoredValue = 0.0f;
}

// @fnv 0x006b5c30
NavMeshInfoMap::NavMeshInfoMap()
    : m_bNavMeshInfoArraysValid(false), m_kNavMeshInfosByFormID(10009), m_kNavMeshInfoArraysByWorldspace(103),
      m_bKeepNavMeshLoaded(false)
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_NAVMESHINFOMAP)));
}

extern int DAT_01031fac;

struct FUN_006b7d90_arg
{
    unsigned int val;
};


// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006b7d90
int* FUN_006b7d90(int* self, FUN_006b7d90_arg aArg)
{
    reinterpret_cast<::FUN_006b7eb0_t *>((self))->FUN_006b7eb0((*(int *)&(const ::FUN_006b7d90_arg &)(aArg)));
    *self = (int)&DAT_01031fac;
    return self;
}

namespace fnv_006b7dc0 {
extern int DAT_01031fac;

struct FUN_006b7dc0_arg
{
    unsigned int val;
};


// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006b7dc0
int* FUN_006b7dc0(int* self, FUN_006b7dc0_arg aArg)
{
    reinterpret_cast<::FUN_006b8060_class *>((self))->FUN_006b8060((*(int *)&(const ::fnv_006b7dc0::FUN_006b7dc0_arg &)(aArg)));
    *self = (int)&DAT_01031fac;
    return self;
}
}  // namespace fnv_006b7dc0

namespace fnv_006b7df0 {
extern int DAT_01031fac;

struct FUN_006b7df0_arg
{
    unsigned int val;
};


// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006b7df0
int* FUN_006b7df0(int* self, FUN_006b7df0_arg aArg)
{
    reinterpret_cast<::FUN_006b8160_class *>((self))->FUN_006b8160((*(int *)&(const ::fnv_006b7df0::FUN_006b7df0_arg &)(aArg)));
    *self = (int)&DAT_01031fac;
    return self;
}
}  // namespace fnv_006b7df0

struct FUN_006b5d80_shell : public NavMeshInfoMap
{
    bool LoadNavMeshInfoMap(TESFile*);
};

struct NavMeshVertexMap
{
};
struct DummyPointerMap
{
};
struct ArrSI
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct Pathing
{
    NavMeshInfo* FindReferenceByFormId(unsigned int);
};
struct TESRecipe
{
};

// @fnv 0x006b5d80
bool FUN_006b5d80_shell::LoadNavMeshInfoMap(TESFile* apFile)
{
    int ifileVersionNumber;
    AutoMemContext tempMemContext(
        (MEM_CONTEXT)0x2e, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshInfoMap.cpp", 0x5c);
    if (this->m_bKeepNavMeshLoaded)
    {
        void* it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((NavMeshVertexMap*)((char*)this + 0x1c))))->GetFirstPos();
        while (it)
        {
            unsigned int navmeshID;
            NavMeshInfo* pinfo;
            reinterpret_cast<::C6b7f20_Map *>((((NiTPointerMap<unsigned int, void*>*)((char*)this + 0x1c))))->FUN_006b7f20((::C6b7f20_Node **)&(it), (unsigned int *)&(navmeshID), (void **)&((void*&)pinfo));
            for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&pinfo->doors)))->GetName())); i++)
                *((Arr*)&pinfo->doors)->GetAt(i) = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*(TESForm**)((Arr*)&pinfo->doors)->GetAt(i))))->FUN_0084e3a0()));
        }
        this->m_bKeepNavMeshLoaded = false;
    }
    int ibuffersize = 0x9b0;
    void* pchunkdata = ::FUN_00401000(ibuffersize);
    unsigned char formid = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((apFile))->FUN_00472660()));
    if (formid != 0x38)
        return false;
    unsigned int thisID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)this)))->FUN_0084e3a0()));
    reinterpret_cast<::S00485110 *>((((TESForm*)this)))->CallWithThis((::T00485110 *)(apFile));
    ifileVersionNumber = 1;
    do
    {
        switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())))
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pMessage), 0x200);
            ((TESForm*)this)->SetEditorID_AtRuntime(pMessage);
            break;
        }
        case 0x444e424f:
            ((TESForm*)this)->readOBNDSubRecord(apFile);
            break;
        case 0x5245564e:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(void *)(&ifileVersionNumber), 0);
            if (apFile->IsEndianConversionRequired())
                ::FUN_00401080(&ifileVersionNumber);
            if (ifileVersionNumber < 5)
                this->m_bNavMeshInfoArraysValid = true;
            break;
        case 0x494d564e: {
            int ichunksize = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
            if (ichunksize > ibuffersize)
            {
                ::FUN_00401030(pchunkdata);
                ibuffersize = ichunksize;
                pchunkdata = ::FUN_00401000(ibuffersize);
            }
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pchunkdata), ichunksize);
            NavMeshInfo* pnewInfo = new NavMeshInfo;
            reinterpret_cast<::FUN_006b4b50_shell *>((pnewInfo))->LoadNavMeshInfo((char*)pchunkdata, apFile, ifileVersionNumber);
            NavMeshInfo* poldInfo = ((Pathing*)this)->FindReferenceByFormId(((unsigned int)(::FUN_00559450((int *)(pnewInfo)))));
            if (poldInfo)
            {
                NavMeshPtr sppreviousNavMesh;
                bool bhasNavMesh = poldInfo->AcquireNavMesh(sppreviousNavMesh);
                BSSimpleArray<NavMeshInfo*, 1024> oldadjacentNavMeshes;
                BSSimpleArray<NavMeshInfo*, 1024> oldpreferredAdjacentNavMeshes;
                BSSimpleArray<TESObjectREFR*, 1024> oldconnectedDoors;
                poldInfo->adjacent.CopyTo(&oldadjacentNavMeshes);
                poldInfo->preferred.CopyTo(&oldpreferredAdjacentNavMeshes);
                poldInfo->doors.CopyTo(&oldconnectedDoors);
                pnewInfo->CopyTo(poldInfo);
                if (bhasNavMesh)
                    reinterpret_cast<::FUN_005a8040_class *>((((TESRecipe*)poldInfo)))->SetField54(((unsigned int)(::FUN_00559450((int *)(((NavMeshInfo*)&sppreviousNavMesh))))));
                oldadjacentNavMeshes.CopyTo(&poldInfo->adjacent);
                oldpreferredAdjacentNavMeshes.CopyTo(&poldInfo->preferred);
                oldconnectedDoors.CopyTo(&poldInfo->doors);
                delete pnewInfo;
            }
            else
            {
                reinterpret_cast<::FUN_00844700_Class *>((((DummyPointerMap*)((char*)this + 0x1c))))->FUN_00844700(((unsigned int)(::FUN_00559450((int *)(pnewInfo)))), (unsigned int)pnewInfo);
            }
            break;
        }
        case 0x4943564e: {
            int ichunksize = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
            if (ichunksize > ibuffersize)
            {
                ::FUN_00401030(pchunkdata);
                ibuffersize = ichunksize;
                pchunkdata = ::FUN_00401000(ibuffersize);
            }
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pchunkdata), ichunksize);
            char* pchunkPointer = (char*)pchunkdata;
            unsigned int infoID = *(unsigned int*)pchunkPointer;
            if (apFile->IsEndianConversionRequired())
                ::FUN_00401080((int *)(unsigned int *)(&infoID));
            ::ResolveFormID((unsigned int *)&(infoID), apFile);
            pchunkPointer += 4;
            NavMeshInfo* pinfo;
            if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)((char*)this + 0x1c))))->FUN_00853130(infoID, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)pinfo)))
                return false;
            if (ifileVersionNumber >= 5)
                pinfo->LoadSerializedData(pchunkPointer, apFile, ifileVersionNumber);
            break;
        }
        }
    } while (apFile->NextChunk());
    ::FUN_00401030(pchunkdata);
    return true;
}

struct NavMeshInfoMapShell
{
    void* FUN_006b5d00();
    void* FUN_006b5cd0(unsigned int flags);
};

struct MapX
{
};
struct NiTMap
{
};
struct TESFormCall
{
};
struct FUN_006b68b0_shell
{
    void SetAlteredAndRevertNavMeshes(bool abVal);
};
// Calls SetAltered with abVal; when abVal is false, iterates the map at offset 0x1c and reverts each NavMeshInfo.
// @fnv 0x006b68b0
void FUN_006b68b0_shell::SetAlteredAndRevertNavMeshes(bool abVal)
{
    reinterpret_cast<::fnv_00484730::FUN_00484730_shell *>((((TESFormCall*)this)))->FUN_00484730(abVal);
    if (!abVal)
    {
        void* it;
        unsigned int navmeshID;
        NavMeshInfo* pinfo;
        it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)((char*)this + 0x1c))))->GetFirstPos();
        while (it)
        {
            reinterpret_cast<::C6b7f20_Map *>((((NiTMap*)((char*)this + 0x1c))))->FUN_006b7f20((::C6b7f20_Node **)&(it), (unsigned int *)&(navmeshID), (void **)&((void*&)pinfo));
            reinterpret_cast<::FUN_004534f0_shell *>((((TESFormCall*)pinfo)))->FUN_004534f0(0);
        }
    }
}

int _FNV_GetFormType(TESForm* apForm);
struct FUN_00484020_shell
{
};
struct FUN_006b6910_shell
{
    bool FUN_006b6910(TESForm* apForm);
};
// Returns true if apForm's form type is 0x43, otherwise delegates to IsLessThan.
// @fnv 0x006b6910
bool FUN_006b6910_shell::FUN_006b6910(TESForm* apForm)
{
    if (_FNV_GetFormType(apForm) == 0x43)
        return true;
    return reinterpret_cast<::TESFormSortProxy *>((((FUN_00484020_shell*)this)))->IsLessThan(apForm);
}

namespace fnv_006b7850 {
struct FUN_006b7850_shell : public NavMeshInfoMap
{
    void* FUN_006b7850(TESWorldSpace*, int);
};

struct DummyPointerMap
{
};
// Looks up the worldspace's map by form ID, then the cell's entry by prepared key, returning the stored info pointer or null.
// @fnv 0x006b7850
void* FUN_006b7850_shell::FUN_006b7850(TESWorldSpace* apWorldSpace, int aiCellKey)
{
    DummyPointerMap* worldspaceMap;
    void* infoarray;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(reinterpret_cast<DummyPointerMap*>(reinterpret_cast<char*>(this) + 0x2C)))->FUN_00853130(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(apWorldSpace)))->FUN_0084e3a0())),
                     (::fnv_00853130::CombatThreatRecord *&)(reinterpret_cast<unsigned int&>(worldspaceMap))))
        return 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(worldspaceMap))->FUN_00853130(((unsigned int)(::FUN_00464f30(aiCellKey))), (::fnv_00853130::CombatThreatRecord *&)(reinterpret_cast<unsigned int&>(infoarray))))
        return 0;
    return infoarray;
}
}  // namespace fnv_006b7850

namespace fnv_006b7910 {
struct MapX
{
};
struct NiTMap
{
};
struct _Mem_20a4
{
};
struct HArr
{
};
struct FUN_006b7910_shell
{
    void FUN_006b7910(BSSimpleArray<void*, 1024>* arr);
};
// @fnv 0x006b7910
void FUN_006b7910_shell::FUN_006b7910(BSSimpleArray<void*, 1024>* pArray)
{
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((((_Mem_20a4*)pArray)))->FUN_006f2290(0, false);
    reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>((((HArr*)pArray)))->FUN_0084b5c0(0x800);
    void* it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)((char*)this + 0x1c))))->GetFirstPos();
    while (it)
    {
        void* pinfo;
        unsigned int navmeshID;
        reinterpret_cast<::C6b7f20_Map *>((((NiTMap*)((char*)this + 0x1c))))->FUN_006b7f20((::C6b7f20_Node **)&(it), (unsigned int *)&(navmeshID), (void **)&(pinfo));
        reinterpret_cast<::FUN_00438690 *>((pArray))->FUN_007cb2e0((unsigned int *)&(pinfo));
    }
}
}  // namespace fnv_006b7910

namespace fnv_006b78b0 {
struct DummyPointerMap
{
};
struct Holder
{
    char _pad[0x2c];
    DummyPointerMap m;
    unsigned int LookupScriptMessageValue(const char*);
};
// Looks up two map entries: one at key 0, then one keyed by PrepareScriptMessage(s), returning the second value or 0 if either lookup fails.
// @fnv 0x006b78b0
unsigned int Holder::LookupScriptMessageValue(const char* pcScriptMessage)
{
    unsigned int uiValue;
    {
        unsigned int uiMapPtr;
        if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&(m))->FUN_00853130(0, (::fnv_00853130::CombatThreatRecord *&)(uiMapPtr)))
            return 0;
        if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)uiMapPtr)))->FUN_00853130((unsigned int)((const char *)(::FUN_00464f30((int)(pcScriptMessage)))), (::fnv_00853130::CombatThreatRecord *&)(uiValue)))
            return 0;
        return uiValue;
    }
}
}  // namespace fnv_006b78b0

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_006b7fd0_class
{
    FUN_006b7fd0_class();
    ~FUN_006b7fd0_class();
};
struct FUN_006b80d0_Class
{
    FUN_006b80d0_Class();
    ~FUN_006b80d0_Class();
};
struct FUN_006b5d00 : Base5a
{
    char _004[0x18];
    FUN_006b7fd0_class _01c;
    char _024[0xf];
    FUN_006b80d0_Class _02c;
    virtual ~FUN_006b5d00();
};
namespace fnv_006b77e0 {
struct TESObjectCELL
{
    bool IsInterior();
};
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct DoorH
{
    void* GetParentWorldSpace();
};
struct FUN_006b77e0_shell
{
    int FUN_006b77e0(TESObjectCELL*);
};
// @fnv 0x006b77e0
int FUN_006b77e0_shell::FUN_006b77e0(TESObjectCELL* cell)
{
    if (!cell)
        return 0;
    if (cell->IsInterior())
        return ((int)(reinterpret_cast<::fnv_006b78b0::Holder *>(this)->LookupScriptMessageValue((const char *)(cell))));
    else
        return ((int)(reinterpret_cast<::fnv_006b7850::FUN_006b7850_shell *>(this)->FUN_006b7850((::TESWorldSpace *)(void *)(((DoorH*)cell)->GetParentWorldSpace()),
                            ::PackShortPair((short)((CellH*)cell)->GetCellGridX(), (short)((CellH*)cell)->GetCellGridY()))));
}
}  // namespace fnv_006b77e0

struct TESWorldSpaceStandIn : public TESWorldSpace
{
};

struct NavMeshInfoStandIn : public NavMeshInfo
{
    TESObjectCELL* FUN_006b7770();
};

struct FormView
{
    unsigned int FUN_00401170();
};
struct FormArray
{
    FormView** FUN_00877a30(unsigned int);
};
struct InfoView
{
};
class NavMesh
{
  public:
};
struct PtrView
{
    NavMesh* FUN_00559450();
};
struct VirtualView
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50(int);
};
struct WorkerNavMap : NavMeshInfoMap
{
    void ValidateNavMeshes();
    bool FUN_006b6580();
};
// @fnv 0x006b6580
bool WorkerNavMap::FUN_006b6580()
{
    if (!reinterpret_cast<::FUN_00460340_shell *>(this)->FUN_00460340())
        return true;
    FormView* formTmp;
    unsigned int i5;
    unsigned int total4 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<::FormArray * *>(&::TESForm::ms_pAllForms))))->FUN_0084e3a0()));
    unsigned int count4 = 0;
    for (i5 = 0; i5 < total4; i5++)
    {
        formTmp = *(*reinterpret_cast<::FormArray * *>(&::TESForm::ms_pAllForms))->FUN_00877a30(i5);
        if (formTmp->FUN_00401170() == 0x43)
            count4++;
    }
    if (count4 == 0)
    {
        bool found6 = false;
        void* pos4 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_kNavMeshInfosByFormID))->GetFirstPos();
        while (pos4)
        {
            unsigned int keyTmp;
            void* value5;
            reinterpret_cast<::C6b7f20_Map *>(&(m_kNavMeshInfosByFormID))->FUN_006b7f20((::C6b7f20_Node **)&(pos4), (unsigned int *)&(keyTmp), (void **)&(value5));
            if (reinterpret_cast<::FUN_0047c850 *>((((InfoView*)value5)))->EvaluateCondition())
            {
                found6 = true;
                break;
            }
        }
        if (!found6)
        {
            ((VirtualView*)this)->f50(0);
            return true;
        }
    }
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_kNavMeshInfosByFormID))->GetFirstPos();
    while (position)
    {
        unsigned int key3;
        void* valueVal;
        reinterpret_cast<::C6b7f20_Map *>(&(m_kNavMeshInfosByFormID))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(key3), (void **)&(valueVal));
        NavMeshPtr mesh8;
        if (((NavMeshInfo*)valueVal)->AcquireNavMesh(mesh8) && reinterpret_cast<::FUN_00460340_shell *>((((::NavMesh *)(::FUN_00559450((int *)(((PtrView*)&mesh8)))))))->FUN_00460340() &&
            !reinterpret_cast<::FUN_00440d80_shell *>((((::NavMesh *)(::FUN_00559450((int *)(((PtrView*)&mesh8)))))))->FUN_00440d80())
            reinterpret_cast<::FUN_006986d0_cls *>((((::NavMesh *)(::FUN_00559450((int *)(((PtrView*)&mesh8)))))))->FUN_006986d0();
    }
    ValidateNavMeshes();
    return true;
}

struct NavigationRequest
{
    int stored;
    int FUN_006b6390(bool enable);
};
struct BoundNavigationMap
{
};
struct ScopedNavPointer
{
    void* current;
    void FUN_0042fb00();
    void FUN_0042fa40();
    void* FUN_00559450(int index);
    ScopedNavPointer()
    {
        FUN_0042fb00();
    }
    ~ScopedNavPointer()
    {
        FUN_0042fa40();
    }
};
struct ActiveResolver
{
};
struct VerifiedPath
{
};
struct NavigationOwner
{
    virtual void UnknownVirtual00() = 0;
    virtual void UnknownVirtual01() = 0;
    virtual void UnknownVirtual02() = 0;
    virtual void UnknownVirtual03() = 0;
    virtual void UnknownVirtual04() = 0;
    virtual void UnknownVirtual05() = 0;
    virtual void UnknownVirtual06() = 0;
    virtual void UnknownVirtual07() = 0;
    virtual void UnknownVirtual08() = 0;
    virtual void UnknownVirtual09() = 0;
    virtual void UnknownVirtual10() = 0;
    virtual void UnknownVirtual11() = 0;
    virtual void UnknownVirtual12() = 0;
    virtual void UnknownVirtual13() = 0;
    virtual void UnknownVirtual14() = 0;
    virtual void UnknownVirtual15() = 0;
    virtual void UnknownVirtual16() = 0;
    virtual void UnknownVirtual17() = 0;
    virtual void UnknownVirtual18() = 0;
    virtual void UnknownVirtual19() = 0;
    virtual void UnknownVirtual20() = 0;
    virtual void UnknownVirtual21() = 0;
    virtual void UnknownVirtual22() = 0;
    virtual void UnknownVirtual23() = 0;
    virtual void UnknownVirtual24() = 0;
    virtual void UnknownVirtual25() = 0;
    virtual void UnknownVirtual26() = 0;
    virtual void UnknownVirtual27() = 0;
    virtual void UnknownVirtual28() = 0;
    virtual void UnknownVirtual29() = 0;
    virtual void UnknownVirtual30() = 0;
    virtual void UnknownVirtual31() = 0;
    virtual void UnknownVirtual32() = 0;
    virtual void UnknownVirtual33() = 0;
    virtual void UnknownVirtual34() = 0;
    virtual void UnknownVirtual35() = 0;
    virtual void UnknownVirtual36() = 0;
    virtual void UnknownVirtual37() = 0;
    virtual void UnknownVirtual38() = 0;
    virtual void UnknownVirtual39() = 0;
    virtual void UnknownVirtual40() = 0;
    virtual void UnknownVirtual41() = 0;
    virtual void UnknownVirtual42() = 0;
    virtual void UnknownVirtual43() = 0;
    virtual void UnknownVirtual44() = 0;
    virtual void UnknownVirtual45() = 0;
    virtual void UnknownVirtual46() = 0;
    virtual void UnknownVirtual47() = 0;
    virtual void UnknownVirtual48() = 0;
    virtual void UnknownVirtual49() = 0;
    virtual void SetNavigationState(int);
    void ActivateNavigationEntry(int identifier);
};
unsigned int FUN_006b7b30(NavMeshInfo*);
struct InfoArray
{
    virtual ~InfoArray();
    unsigned int FUN_00719b20(NavMeshInfo* const&, unsigned int, bool (*)(NavMeshInfo*&, NavMeshInfo*&));
    void FUN_006bf8f0(unsigned int, bool);
};
struct InnerMap
{
    virtual ~InnerMap();
};
struct OuterMap
{
};
struct MapOwner : NavMeshInfoMap
{
    void FUN_006b7b70(NavMeshInfo*);
};

struct NavMeshInfoSaveStandIn : public NavMeshInfo
{
};

struct NavMeshInfoMapSaveStandIn : public NavMeshInfoMap
{
    void SaveNavMeshInfoMap();
};

// Starts a save, writes the REVN version, then writes an IMVN info chunk and an ICVN index chunk for each navmesh entry, and ends the save.
// @fnv 0x006b6740
void NavMeshInfoMapSaveStandIn::SaveNavMeshInfoMap()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    ::FUN_00485910('REVN', 11);

    void* pos2 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_kNavMeshInfosByFormID))->GetFirstPos();
    while (pos2)
    {
        unsigned int key;
        void* info3;
        reinterpret_cast<::C6b7f20_Map *>(&(m_kNavMeshInfosByFormID))->FUN_006b7f20((::C6b7f20_Node **)&(pos2), (unsigned int *)&(key), (void **)&(info3));
        unsigned int sizeB = reinterpret_cast<::FUN_006b4880_Class *>((((NavMeshInfoSaveStandIn*)info3)))->GetSerializedSize();
        char* buffer_ = (char*)::FUN_00401000(sizeB);
        reinterpret_cast<::FUN_006b48f0_shell *>((((NavMeshInfoSaveStandIn*)info3)))->WriteToChunkBuffer(buffer_);
        ::AppendChunk('IMVN', buffer_, sizeB);
        ::FUN_00401030(buffer_);
    }

    pos2 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_kNavMeshInfosByFormID))->GetFirstPos();
    while (pos2)
    {
        unsigned int key3;
        void* info6;
        reinterpret_cast<::C6b7f20_Map *>(&(m_kNavMeshInfosByFormID))->FUN_006b7f20((::C6b7f20_Node **)&(pos2), (unsigned int *)&(key3), (void **)&(info6));
        unsigned int size2 = ((int)(reinterpret_cast<::fnv_006b4e10::FUN_006b4e10_shell *>((((NavMeshInfoSaveStandIn*)info6)))->FUN_006b4e10())) + 4;
        char* bufferVal = (char*)::FUN_00401000(size2);
        char* cur3 = bufferVal;
        unsigned int id5 = ((unsigned int)(::FUN_00559450((int *)(((NavMeshInfoSaveStandIn*)info6)))));
        if (((bool)(::FUN_00401500())))
        {
            ::FUN_00401080((int *)(unsigned int *)(&id5));
        }
        *(unsigned int*)cur3 = id5;
        cur3 += 4;
        reinterpret_cast<::NavMeshInfoSaveShell *>((((NavMeshInfoSaveStandIn*)info6)))->SaveToBuffer(cur3);
        ::AppendChunk('ICVN', bufferVal, size2);
        ::FUN_00401030(bufferVal);
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct CellKeyStand
{
    bool IsEmpty();
};
struct Dummy_0069b080;
struct FUN_006b6990_vslot
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8(bool arg);
};
struct FUN_006b6990_shell : public NavMeshInfoMap
{
    void FUN_006b6990(unsigned int id);
};
// @fnv 0x006b6990
void FUN_006b6990_shell::FUN_006b6990(unsigned int id)
{
    unsigned int info;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(&m_kNavMeshInfosByFormID)))->FUN_00853130(id, (::fnv_00853130::CombatThreatRecord *&)(info)))
    {
        reinterpret_cast<::NiTMap_S *>((reinterpret_cast<CellKeyMap*>(&m_kNavMeshInfosByFormID)))->RemoveKey(id);
        if (!IsFieldCZero(reinterpret_cast<Dummy_0069b080*>(&m_kNavMeshInfoArraysByWorldspace)))
        {
            reinterpret_cast<::MapOwner *>(this)->FUN_006b7b70((::NavMeshInfo *)(info));
        }
        reinterpret_cast<FUN_006b6990_vslot*>(this)->vfn_c8(true);
    }
}

template <class V> struct FUN_006b6b20_Map
{
    virtual ~FUN_006b6b20_Map();
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*& rpPos, unsigned int& ruiKey, V& rkValue);
    void FUN_00438af0();
};
struct FUN_006b6b20_FormVT
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32(bool abValue);
};
struct FUN_006b6b20_shell : public NavMeshInfoMap
{
    void ClearNavMeshInfoMaps();
};
// @fnv 0x006b5cd0
void* NavMeshInfoMapShell::FUN_006b5cd0(unsigned int flags)
{
    reinterpret_cast<::FUN_006b5d00 *>(this)->::FUN_006b5d00::~FUN_006b5d00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that calls ClearNavMeshInfoMaps before the object is torn down.
// @fnv 0x006b5d00
FUN_006b5d00::~FUN_006b5d00()
{
    reinterpret_cast<::FUN_006b6b20_shell *>(this)->ClearNavMeshInfoMaps();
}
struct CellNavMeshInfoArray
{
    virtual ~CellNavMeshInfoArray();
};
typedef FUN_006b6b20_Map<CellNavMeshInfoArray*> CellNavMeshInfoMap;
// Deletes every NavMeshInfo in the first map and every CellNavMeshInfoMap with its arrays in the second, clears both maps, then calls Unk_32(true).
// @fnv 0x006b6b20
void FUN_006b6b20_shell::ClearNavMeshInfoMaps()
{
    void* pPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((FUN_006b6b20_Map<NavMeshInfo*>*)&m_kNavMeshInfosByFormID)))->GetFirstPos();
    while (pPos)
    {
        unsigned int uiKey;
        NavMeshInfo* pInfo;
        reinterpret_cast<::C6b7f20_Map *>((((FUN_006b6b20_Map<NavMeshInfo*>*)&m_kNavMeshInfosByFormID)))->FUN_006b7f20((::C6b7f20_Node **)&(pPos), (unsigned int *)&(uiKey), (void **)&(pInfo));
        delete pInfo;
    }
    reinterpret_cast<::FUN_00438af0_Class *>((((FUN_006b6b20_Map<NavMeshInfo*>*)&m_kNavMeshInfosByFormID)))->FUN_00438af0();
    pPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((FUN_006b6b20_Map<CellNavMeshInfoMap*>*)&m_kNavMeshInfoArraysByWorldspace)))->GetFirstPos();
    while (pPos)
    {
        unsigned int uiCellKey;
        CellNavMeshInfoMap* pCellNavMeshInfoMap;
        reinterpret_cast<::C6b7f20_Map *>((((FUN_006b6b20_Map<CellNavMeshInfoMap*>*)&m_kNavMeshInfoArraysByWorldspace)))->FUN_006b7f20((::C6b7f20_Node **)&(pPos), (unsigned int *)&(uiCellKey), (void **)&(pCellNavMeshInfoMap));
        void* pInnerPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((pCellNavMeshInfoMap))->GetFirstPos();
        while (pInnerPos)
        {
            unsigned int uiInfoKey;
            CellNavMeshInfoArray* pArray;
            reinterpret_cast<::C6b7f20_Map *>((pCellNavMeshInfoMap))->FUN_006b7f20((::C6b7f20_Node **)&(pInnerPos), (unsigned int *)&(uiInfoKey), (void **)&(pArray));
            delete pArray;
        }
        delete pCellNavMeshInfoMap;
    }
    reinterpret_cast<::FUN_00438af0_Class *>((((FUN_006b6b20_Map<CellNavMeshInfoMap*>*)&m_kNavMeshInfoArraysByWorldspace)))->FUN_00438af0();
    ((FUN_006b6b20_FormVT*)this)->Unk_32(true);
}

struct NavMesh;
struct NavMeshInfo;
struct NavMeshPtr;
struct MeshInfoArray;
struct GridArray;
struct CellView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual const char* GetEditorID();
};

struct MeshInfoArray
{
    void* vtable;
    NavMeshInfo** items;
    unsigned int count;
    unsigned int capacity;
    unsigned int FUN_0044ddc0();
    NavMeshInfo** FUN_00877a30(unsigned int);
    void FUN_006bf8f0(unsigned int, bool);
    unsigned int FUN_00719b20(NavMeshInfo* const&, unsigned int, bool(__cdecl*)(NavMeshInfo*&, NavMeshInfo*&));
};
struct GridArray
{
    void* vtable;
    void* items;
    unsigned int count;
    unsigned int capacity;
    GridArray();
    ~GridArray();
    unsigned int FUN_0044ddc0();
    void** FUN_00877a30(unsigned int);
    void FUN_007cb2e0(void*);
};
struct InfoNav : NavMeshInfo
{

};

struct DataMatch
{
    unsigned int key;
    NavMeshInfo* info;
    bool FUN_0069e090();
};
struct GridRecord
{
    void* unk00;
    NavMeshInfo* info;
};
struct CleanupMap
{
};
struct GridLookup
{
};
struct GridMap
{
    GridMap();
    ~GridMap();
    NavMesh* FUN_00559450();
};
struct LinkChecker
{
    void* vtable;
    void* buffer;
    unsigned int size;
    unsigned int capacity;
    LinkChecker();
    ~LinkChecker();
};
struct NavMeshInfoMapData
{
    void* vtable;
    unsigned int hashSize;
    void* hashTable;
    unsigned int count;
    void* FUN_004b9ba0();
    void FUN_006b7f20(void**, unsigned int*, NavMeshInfo**);
};

extern char DAT_0106c0d8[];
extern char DAT_0106c078[];
extern char DAT_0106c008[];
extern char DAT_0106bfa8[];
extern char DAT_0106bf18[];
extern char DAT_0106be98[];
extern char DAT_0106be20[];
extern char DAT_0106bdb0[];
struct LocalList
{
    void* vtable;
    NavMeshInfo** buffer;
    unsigned int size;
    unsigned int cap;
    LocalList();
    ~LocalList();
    unsigned int FUN_0044ddc0();
    NavMeshInfo** FUN_00877a30(unsigned int);
    void FUN_007cb2e0(void*);
    unsigned int FUN_00719b20(NavMeshInfo* const&, unsigned int, bool(__cdecl*)(NavMeshInfo*&, NavMeshInfo*&));
};
struct InfoResolver
{
    unsigned int id;
    NavMeshInfo* info;
    bool FUN_0069e090();
};
struct PointerReference
{
    NavMeshInfo* p;
    NavMeshInfo* FUN_00559450();
    int FUN_006b6390(bool);
};
// Iterates the nav mesh map, warns about and collects invalid meshes, checks adjacency, preferred links and doors, and cleans up the collected meshes.
// @fnv 0x006b6c60
void WorkerNavMap::ValidateNavMeshes()
{
    void* iterator;
    {
        LocalList invalidatedList;
        {
            InfoNav* meshInfo;
            {
                unsigned int identifier;
                iterator = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_kNavMeshInfosByFormID))->GetFirstPos();
                while (iterator)
                {
                    reinterpret_cast<::C6b7f20_Map *>(&(m_kNavMeshInfosByFormID))->FUN_006b7f20((::C6b7f20_Node **)&(iterator), (unsigned int *)&(identifier), (void **)&((void*&)meshInfo));
                    if (!((int)(::FUN_00690830((const ::NavMeshInfo *)(meshInfo)))))
                    {
                        ::FUN_005b5e40();
                        reinterpret_cast<::FUN_00438690 *>(&(invalidatedList))->FUN_007cb2e0((unsigned int *)(void *)(&meshInfo));
                    }
                    else if (!reinterpret_cast<::FUN_0069dfb0_class *>((meshInfo))->HasNonZeroAtOffset54())
                    {
                        ::FUN_005b5e40();
                        ::RemoveNavMeshId((unsigned int)(meshInfo));
                        reinterpret_cast<::FUN_00438690 *>(&(invalidatedList))->FUN_007cb2e0((unsigned int *)(void *)(&meshInfo));
                    }
                    else
                    {
                        NavMeshPtr activeMesh;
                        {
                            if (!reinterpret_cast<::NavMeshInfo *>((meshInfo))->AcquireNavMesh((*(::NavMeshPtr *)(&activeMesh))))
                            {
                                ::FUN_005b5e40(
                                    );
                                reinterpret_cast<::FUN_00438690 *>(&(invalidatedList))->FUN_007cb2e0((unsigned int *)(void *)(&meshInfo));
                                continue;
                            }
                            if (reinterpret_cast<::FUN_00440d80_shell *>((((::NavMesh *)(::FUN_00559450((int *)&(activeMesh))))))->FUN_00440d80())
                                reinterpret_cast<::FUN_00438690 *>(&(invalidatedList))->FUN_007cb2e0((unsigned int *)(void *)(&meshInfo));
                            for (unsigned int k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshInfo->adjacent))->GetName())); ++k)
                            {
                                bool invalid = false;
                                if (*((MeshInfoArray*)&meshInfo->adjacent)->FUN_00877a30(k))
                                {
                                    if (!FUN_00693d70((unsigned int)((::NavMesh *)(::FUN_00559450((int *)(((PtrView*)*((MeshInfoArray*)&meshInfo->adjacent)
                                                                         ->FUN_00877a30(k))))))))
                                        invalid = true;
                                }
                                else
                                    invalid = true;
                                if (invalid)
                                {
                                    ::FUN_005b5e40();
                                    reinterpret_cast<::FUN_006bf8f0_Class *>((((InfoArray*)&meshInfo->adjacent)))->FUN_006bf8f0(k, true);
                                    --k;
                                }
                            }
                            for (unsigned int k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshInfo->preferred))->GetName())); ++k)
                            {
                                bool invalid = false;
                                if (*((MeshInfoArray*)&meshInfo->preferred)->FUN_00877a30(k))
                                {
                                    if (!FUN_00693d70((unsigned int)((::NavMesh *)(::FUN_00559450((int *)(((PtrView*)*((MeshInfoArray*)&meshInfo->preferred)
                                                                         ->FUN_00877a30(k))))))))
                                        invalid = true;
                                }
                                else
                                    invalid = true;
                                if (invalid)
                                {
                                    ::FUN_005b5e40();
                                    reinterpret_cast<::FUN_006bf8f0_Class *>((((InfoArray*)&meshInfo->preferred)))->FUN_006bf8f0(k, true);
                                    --k;
                                }
                            }
                            LocalList neighborList;
                            if (((int)(::FUN_00690800((const ::NavMeshInfo *)(meshInfo)))))
                            {
                                short gridX, gridY;
                                ::SplitUInt32(meshInfo->m_uiPathingFlags, (unsigned short *)(short *)(&gridX), (unsigned short *)(short *)(&gridY));
                                for (int x = gridX - 1; x <= gridX + 1; ++x)
                                {
                                    for (int y = gridY - 1; y <= gridY + 1; ++y)
                                    {
                                        if (x == gridX && y == gridY)
                                            continue;
                                        MeshInfoArray* pCellMeshes =
                                            ((::MeshInfoArray *)(reinterpret_cast<::fnv_006b7850::FUN_006b7850_shell *>((((GridLookup*)this)))->FUN_006b7850((::TESWorldSpace *)(::NavMesh *)((NavMesh*)((::FUN_00690800((const ::NavMeshInfo *)(meshInfo))))),
                                                               ((unsigned int)(::PackShortPair((unsigned short)x, (unsigned short)y))))));
                                        if (pCellMeshes)
                                            for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((pCellMeshes))->GetName())); ++i)
                                                reinterpret_cast<::FUN_00438690 *>(&(neighborList))->FUN_007cb2e0((unsigned int *)(void *)(((::NavMeshInfo **)(reinterpret_cast<::S3e60 *>((pCellMeshes))->FUN_006a7ad0(i)))));
                                    }
                                }
                            }
                            NavMeshPtr meshPtr;
                            if (reinterpret_cast<::NavMeshInfo *>((meshInfo))->AcquireNavMesh((*(::NavMeshPtr *)(&meshPtr))))
                            {
                                bool corrupt = false;
                                {
                                    for (unsigned int k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshInfo->adjacent))->GetName())); ++k)
                                    {
                                        NavMeshInfo* record = *((MeshInfoArray*)&meshInfo->adjacent)->FUN_00877a30(k);
                                        LinkChecker linkChecker;
                                        reinterpret_cast<::fnv_00697590::FUN_00697590_shell *>((((GridMap*)((::NavMesh *)(::FUN_00559450((int *)&(meshPtr)))))))->CollectTrianglesForDoor((unsigned int)(record), (::fnv_00697590::BSSimpleArrayActor *)(void *)(&linkChecker));
                                        if (reinterpret_cast<::FUN_0076b610_Class *>(&(linkChecker))->FUN_0076b610())
                                        {
                                            ::FUN_005b5e40();
                                            corrupt = true;
                                            break;
                                        }
                                    }
                                    for (unsigned int k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshInfo->preferred))->GetName())); ++k)
                                    {
                                        NavMeshInfo* record = *((MeshInfoArray*)&meshInfo->preferred)->FUN_00877a30(k);
                                        LinkChecker linkChecker;
                                        reinterpret_cast<::fnv_00697590::FUN_00697590_shell *>((((GridMap*)((::NavMesh *)(::FUN_00559450((int *)&(meshPtr)))))))->CollectTrianglesForDoor((unsigned int)(record), (::fnv_00697590::BSSimpleArrayActor *)(void *)(&linkChecker));
                                        if (reinterpret_cast<::FUN_0076b610_Class *>(&(linkChecker))->FUN_0076b610())
                                        {
                                            ::FUN_005b5e40();
                                            corrupt = true;
                                            break;
                                        }
                                    }
                                    unsigned int count = reinterpret_cast<::FUN_00695370_class *>((((GridMap*)((::NavMesh *)(::FUN_00559450((int *)&(meshPtr)))))))->GetArrFlags();
                                    for (unsigned int k = 0; k < count; ++k)
                                    {
                                        unsigned int size;
                                        if (reinterpret_cast<::FUN_0069e090_class *>((((DataMatch*)&(
                                                 (GridRecord*)((void *)(reinterpret_cast<::FUN_00693d30_shell *>((((GridMap*)((::NavMesh *)(::FUN_00559450((int *)&(meshPtr)))))))->GetEdge((unsigned short)k))))
                                                 ->info)))->FUN_0069e090())
                                        {
                                            NavMeshInfo* other =
                                                ((GridRecord*)((void *)(reinterpret_cast<::FUN_00693d30_shell *>((((GridMap*)((::NavMesh *)(::FUN_00559450((int *)&(meshPtr)))))))->GetEdge((unsigned short)k))))
                                                    ->info;
                                            bool missing = true;
                                            size = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshInfo->adjacent))->GetName()));
                                            for (unsigned int i = 0; i < size; ++i)
                                                if (*((MeshInfoArray*)&meshInfo->adjacent)->FUN_00877a30(i) == other)
                                                {
                                                    missing = false;
                                                    break;
                                                }
                                            size = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshInfo->preferred))->GetName()));
                                            for (unsigned int i = 0; i < size; ++i)
                                                if (*((MeshInfoArray*)&meshInfo->preferred)->FUN_00877a30(i) == other)
                                                {
                                                    missing = false;
                                                    break;
                                                }
                                            if (missing)
                                            {
                                                if (neighborList.FUN_00719b20(other, 0, ((bool (&)(NavMeshInfo *&, NavMeshInfo *&))::FUN_009a3830)) !=
                                                    (unsigned int)-1)
                                                {
                                                    ::FUN_005b5e40();
                                                    corrupt = true;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    for (unsigned int k = 0; k < reinterpret_cast<::fnv_006b5a90::FUN_006b5a90_shell *>((((GridMap*)((::NavMesh *)(::FUN_00559450((int *)&(meshPtr)))))))->FUN_006b5a90(); ++k)
                                    {
                                        NavMeshInfo** other = (NavMeshInfo**)((void *)(reinterpret_cast<::FUN_0068f6b0_shell *>((((GridMap*)((::NavMesh *)(::FUN_00559450((int *)&(meshPtr)))))))->FUN_0068f6b0((unsigned short)k)));
                                        if (((InfoArray*)&meshInfo->doors)->FUN_00719b20(*other, 0, ((bool (&)(NavMeshInfo *&, NavMeshInfo *&))::FUN_009a3830)) ==
                                            (unsigned int)-1)
                                        {
                                            ::FUN_005b5e40();
                                            corrupt = true;
                                            break;
                                        }
                                    }
                                    for (unsigned int k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshInfo->doors))->GetName())); ++k)
                                    {
                                        NavMeshInfo* other = *((MeshInfoArray*)&meshInfo->doors)->FUN_00877a30(k);
                                        {
                                            bool linkChecker = false;
                                            for (unsigned int i = 0; i < reinterpret_cast<::fnv_006b5a90::FUN_006b5a90_shell *>((((GridMap*)((::NavMesh *)(::FUN_00559450((int *)&(meshPtr)))))))->FUN_006b5a90();
                                                 ++i)
                                            {
                                                if (*(NavMeshInfo**)((void *)(reinterpret_cast<::FUN_0068f6b0_shell *>((((GridMap*)((::NavMesh *)(::FUN_00559450((int *)&(meshPtr)))))))->FUN_0068f6b0((unsigned short)i))) == other)
                                                {
                                                    linkChecker = true;
                                                    break;
                                                }
                                            }
                                            if (!linkChecker)
                                            {
                                                ::FUN_005b5e40();
                                                corrupt = true;
                                                break;
                                            }
                                        }
                                    }
                                }
                                if (corrupt)
                                    reinterpret_cast<::NavInfo *>((meshInfo))->InitializeFromMeshSource((::MeshSource *)(::NavMesh *)(((::NavMesh *)(::FUN_00559450((int *)&(meshPtr))))));
                            }
                        }
                    }
                }
                for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(invalidatedList))->GetName())); ++i)
                {
                    reinterpret_cast<::FUN_006b6990_shell *>((((CleanupMap*)this)))->FUN_006b6990((unsigned int)(((::NavMesh *)(::FUN_00559450((int *)(((PtrView*)*invalidatedList.FUN_00877a30(i))))))));
                    NavMeshInfo* info = *invalidatedList.FUN_00877a30(i);
                    NavMeshInfo* current = info;
                    current ? ((NavigationRequest*)current)->FUN_006b6390(true) : 0;
                }
            }
        }
    }
}

using ::TESObjectCELL;
class TESObjectCELL : public ::TESForm
{
  public:
    virtual ~TESObjectCELL();
};


struct InteriorCellLookup : public ::NavMeshInfo
{
    ::TESObjectCELL* FUN_006b77b0();
};
// Registers info in the per-parent NavMeshInfoArray for its cell key, creating the inner map and array as needed, and skips if already present.
// @fnv 0x006b7980
void NavMeshInfoMap::InsertNavMeshInfo(NavMeshInfo* info)
{
    struct CellKeyLookup
    {
        void* innerMap;
        unsigned int parentID;
        unsigned int cellKey;
    } lookup;
    lookup.cellKey = FUN_006b7b30(info);
    if (reinterpret_cast<::InteriorCellLookup *>((info))->FUN_006b77b0())
        lookup.parentID = 0;
    else
        lookup.parentID = info->m_uiParentSpaceID;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&(m_kNavMeshInfoArraysByWorldspace))->FUN_00853130(lookup.parentID, (::fnv_00853130::CombatThreatRecord *&)(lookup.innerMap)))
    {
        unsigned int hashSize = 103;
        if (!lookup.parentID)
        {
            hashSize = 1009;
        }
        else
        {
            TESWorldSpace* world = (TESWorldSpace*)::FUN_004839c0(lookup.parentID);
            if (world && !world->GetSmallWorld())
                hashSize = 1009;
        }
        lookup.innerMap = new NiTPointerMap<unsigned int, NavMeshInfoArray*>(hashSize);
        reinterpret_cast<::FUN_00844700_Class *>(&(m_kNavMeshInfoArraysByWorldspace))->FUN_00844700(lookup.parentID, (unsigned int)(lookup.innerMap));
    }
    NavMeshInfoArray* array;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((NiTPointerMap<unsigned int, NavMeshInfoArray*>*)lookup.innerMap)))->FUN_00853130(lookup.cellKey, (::fnv_00853130::CombatThreatRecord *&)(array)))
    {
        array = new NavMeshInfoArray;
        reinterpret_cast<::FUN_00844700_Class *>((((NiTPointerMap<unsigned int, NavMeshInfoArray*>*)lookup.innerMap)))->FUN_00844700(lookup.cellKey, (unsigned int)(array));
    }
    if (array->Find(info, 0, ((bool (&)(NavMeshInfo *&, NavMeshInfo *&))::FUN_009a3830)) != (unsigned int)-1)
        return;
    reinterpret_cast<::FUN_00438690 *>((array))->FUN_007cb2e0((unsigned int *)&(info));
}
// @fnv 0x006b7770
TESObjectCELL* NavMeshInfoStandIn::FUN_006b7770()
{
    TESWorldSpace* worldSpace = ::FUN_00690800((const ::NavMeshInfo *)this);
    if (worldSpace)
    {
        return reinterpret_cast<::TESWorldSpace *>((static_cast<TESWorldSpaceStandIn*>(worldSpace)))->GetCellByKey(static_cast<unsigned int>(m_uiPathingFlags));
    }
    else
    {
        return reinterpret_cast<::InteriorCellLookup *>((reinterpret_cast<NavMeshInfo*>(this)))->FUN_006b77b0();
    }
}
// @fnv 0x006b6a00
void NavigationOwner::ActivateNavigationEntry(int identifier)
{
    NavigationRequest* entry;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((reinterpret_cast<BoundNavigationMap*>(reinterpret_cast<char*>(this) + 0x1c)))->FUN_00853130(identifier, (*(::fnv_00853130::CombatThreatRecord * *)(&entry))))
    {
        reinterpret_cast<::MapOwner *>(this)->FUN_006b7b70((::NavMeshInfo *)(entry));
        bool isAccepted = false;
        ScopedNavPointer pointer;
        if (reinterpret_cast<::NavMeshInfo *>((entry))->AcquireNavMesh((*(::NavMeshPtr *)(&pointer))))
        {
            VerifiedPath* active = reinterpret_cast<VerifiedPath*>(
                ((void *)(reinterpret_cast<::TESForm *>((reinterpret_cast<ActiveResolver*>(((void *)(::FUN_00559450((int *)&(pointer)))))))->GetFile({}))));
            if (active && reinterpret_cast<::TESFile *>((active))->IsMasterFile())
                isAccepted = true;
        }
        {
            NavigationRequest* selected = entry;
            NavigationRequest* target = selected;
            target ? target->FUN_006b6390(true) : 0;
        }
        reinterpret_cast<::NiTMap_S *>((reinterpret_cast<BoundNavigationMap*>(reinterpret_cast<char*>(this) + 0x1c)))->RemoveKey(identifier);
        if (isAccepted)
            SetNavigationState(1);
    }
}
// @fnv 0x006b7b70
void MapOwner::FUN_006b7b70(NavMeshInfo* info)
{
    unsigned int parent = FUN_006b7b30(info);
    unsigned int map;
    if (reinterpret_cast<::InteriorCellLookup *>((info))->FUN_006b77b0())
        map = 0;
    else
        map = info->m_uiParentSpaceID;
    InnerMap* array;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>(&(reinterpret_cast<OuterMap&>(m_kNavMeshInfoArraysByWorldspace)))->FUN_00853130(map, (::fnv_00853130::CombatThreatRecord *&)(array)))
        return;
    InfoArray* index;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((array))->FUN_00853130(parent, (::fnv_00853130::CombatThreatRecord *&)(index)))
        return;
    unsigned int key = index->FUN_00719b20(info, 0, ((bool (&)(NavMeshInfo *&, NavMeshInfo *&))::FUN_009a3830));
    if (key == -1)
        return;
    reinterpret_cast<::FUN_006bf8f0_Class *>((index))->FUN_006bf8f0(key, true);
    if (reinterpret_cast<::FUN_0076b610_Class *>((index))->FUN_0076b610())
    {
        reinterpret_cast<::NiTMap_S *>((array))->RemoveKey(parent);
        delete index;
        if (::IsFieldCZero((::Dummy_0069b080 *)(array)))
        {
            reinterpret_cast<::NiTMap_S *>(&(reinterpret_cast<OuterMap&>(m_kNavMeshInfoArraysByWorldspace)))->RemoveKey(map);
            delete array;
        }
    }
}

// Casts the TESForm* returned by FUN_00690830(this) to TESObjectCELL*.
// @fnv 0x006b77b0
::TESObjectCELL* InteriorCellLookup::FUN_006b77b0()
{
    return dynamic_cast< ::TESObjectCELL*>(FUN_00690830(this));
}

#include "generated/data/fallout_shared/pathfinding/navmeshinfomap.inc"
