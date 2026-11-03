// fallout_shared/region system/tesregion.cpp: TESRegion, RegionProxy, OwnQ (12 functions)

#include <new>
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00485130_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f77c0_shell.h"
#include "fnv/decl/FUN_004f80c0_shell.h"
#include "fnv/decl/FUN_00526ae0_class.h"
#include "fnv/decl/FUN_005827d0_list.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/GList.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004f81e0__FUN_004f81e0_shell.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
#include "tesregion_TESRegion.h"
#include "tesregion_TESRegionDataList.h"
#include "tesregion_TESRegionPointList.h"
#include "tesregion_data_types.h"
#include "tesregion_load.h"

// Clears the region's data list and deletes every point list held in the point list queue.
// @fnv 0x004f0ef0
void TESRegion::ClearData()
{
    if (m_pRegionDataList)
        m_pRegionDataList->Clear();
    if (pRegionPointList)
    {
        RegionPointList* pointList = (pRegionPointList->m_item);
        while (pointList)
        {
            pRegionPointList->RemoveHead();
            delete pointList;
            pointList = (pRegionPointList->m_item);
        }
    }
}

// @fnv 0x004f0f80
void TESRegion::InitItem()
{
    TESWorldSpace* world;
    BSSimpleList<TESRegionData*>* data;
    if (GetInitialized())
        return;
    {
        unsigned int worldID = (unsigned int)((::TESWorldSpace *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((void *)this)->FUN_007af430()));
        ::ResolveFormID((unsigned int *)&(worldID), GetFile(-1));
        world = dynamic_cast<TESWorldSpace*>(::FUN_004839c0(worldID));
    }
    if (world)
        AssignWorldSpace(world);
    SetInitializationState(true);
    data = ((::RegionDataList *)(reinterpret_cast<::FUN_009611e0_shell *>((void *)this)->FUN_009611e0()));
    while (data && (data->m_item))
    {
        (data->m_item)->Initialize(this);
        data = ((::BSSimpleList< ::TESRegionData *> *)(reinterpret_cast<::Callees *>((data))->FUN_00726070()));
    }
}

struct FUN_00740940_shell : public TESDataHandler
{
    TESRegionDataManager* GetRegionDataManager();
};
// Loads a TESRegion from a TESFile: reads the EDID/OBND/WNAM/RPLI/RPLD chunks and region-type subrecords, then prunes invalid point lists.
// @fnv 0x004f0b10
bool TESRegion::Load(TESFile* file)
{
    struct ReferenceItemCountEntry
    {
        RegionPointList* invalid;
        BSSimpleList<RegionPointList*>* lists;
        unsigned int distance;
        unsigned int worldID;
        char* editorID;
        int chunk;
        RegionPointList* pointList;
        char padding0, padding1, padding2;
        unsigned char type;
    } loadState;
    loadState.type = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    loadState.pointList = 0;
    if (loadState.type != 55)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    while (loadState.chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (loadState.chunk)
        {
        case 0x44494445: {
            loadState.editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(loadState.editorID), 512);
            SetEditorID_AtRuntime(loadState.editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4d414e57: {
            loadState.worldID = 0;
            file->GetChunkData(&loadState.worldID);
            AssignWorldSpace((TESWorldSpace*)loadState.worldID);
            break;
        }
        case 0x494c5052: {
            loadState.distance = 0;
            file->GetChunkData(&loadState.distance);
            loadState.pointList = new RegionPointList(true);
            reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>((loadState.pointList))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(loadState.distance));
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::RegionPointList *> *)(reinterpret_cast<::BGSTerrainManager *>((void *)this)->GetMinLevel()))))->FUN_00905820((void *)&(loadState.pointList));
            break;
        }
        case 0x444c5052:
            if (loadState.pointList)
                loadState.pointList->ReadPointsFromFile(file);
            break;
        case 0x424f4452:
        case 0x42534452:
        case 0x44494452:
        case 0x44534452:
        case 0x444d4452:
        case 0x49534452:
        case 0x504d4452:
        case 0x4e4c4452:
        case 0x4a4f4452:
        case 0x4e4f4349:
        case 0x544f4452:
        case 0x53474452:
        case 0x54414452:
        case 0x54574452:
            reinterpret_cast<::FUN_00740940_shell *>((((TESRegionLoadHandler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetRegionDataManager()->Load(file, this);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    loadState.lists = ((::BSSimpleList< ::RegionPointList *> *)(reinterpret_cast<::BGSTerrainManager *>((void *)this)->GetMinLevel()));
    while (loadState.lists && (loadState.lists->m_item))
    {
        if (!reinterpret_cast<::fnv_004f81e0::FUN_004f81e0_shell *>(((loadState.lists->m_item)))->FUN_004f81e0(true))
        {
            loadState.invalid = (loadState.lists->m_item);
            reinterpret_cast<::ItemChangeListNode *>((((TESRegionLoadList*)((::BSSimpleList< ::RegionPointList *> *)(reinterpret_cast<::BGSTerrainManager *>((void *)this)->GetMinLevel())))))->FUN_00905330((::InventoryStackRecord *const &)(loadState.invalid));
            delete loadState.invalid;
            loadState.lists = ((::BSSimpleList< ::RegionPointList *> *)(reinterpret_cast<::BGSTerrainManager *>((void *)this)->GetMinLevel()));
        }
        else
            loadState.lists = ((::BSSimpleList< ::RegionPointList *> *)(reinterpret_cast<::Callees *>((loadState.lists))->FUN_00726070()));
    }
    return true;
}

// @fnv 0x00740940
TESRegionDataManager* FUN_00740940_shell::GetRegionDataManager()
{
    return *(TESRegionDataManager**)((char*)this + 0x624);
}


// @fnv 0x004f10b0
void FUN_004f10b0(char* param_1)
{
    reinterpret_cast<::FUN_005827d0_list *>((param_1 + 8))->FUN_005827d0();
}

struct FUN_004f0890_shell
{
    void FUN_004f08c0();
    void* DestroyIfFlagged(unsigned int);
};
struct NiPoint3
{
    float x, y, z;
};
struct SoundPlaybackHandle
{
};
struct SL
{
    void* a;
    void* b;
    SL();
};
struct RDL_004f3330
{
    void* a;
    void* b;
    void* c;
    RDL_004f3330(bool);
public:
    ::RDL_004f3330 *FUN_004f3470(::RDL_004f3330 *);
};

struct FUN_004f0770 : public TESForm
{
    RDL_004f3330* m_pRegionDataList;
    SL* pRegionPointList;
    void* m_pContainingWorldspace;
    void* m_pRegionWeather;
    float fWeatherChance;
    NiPoint3 m_kDiffuseColor;
    FUN_004f0770();
    ~FUN_004f0770();
};

// Initialises the object: zeroes the point, allocates two members, sets form type 0x37, clears two pointers and sets a float to -1.
// @fnv 0x004f0770
FUN_004f0770::FUN_004f0770()
{
    reinterpret_cast<::FUN_00416870_t *>(&(m_kDiffuseColor))->FUN_00416870(0.0f, 0.0f, 0.0f);
    m_pRegionDataList = new RDL_004f3330(true);
    pRegionPointList = new SL;
    reinterpret_cast<::FUN_004f15a0_shell *>((((SoundPlaybackHandle*)this)))->FUN_004f15a0(0x37);
    m_pContainingWorldspace = 0;
    m_pRegionWeather = 0;
    fWeatherChance = -1.0f;
}

class FUN_00483630 : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    TESFile* firstSourceFile;
    BSSimpleList<TESFile*>* nextSourceFile;
    ~FUN_00483630();
};
class FUN_004f08c0 : public FUN_00483630
{
  public:
    RegionDataList* m_pRegionDataList;
    BSSimpleList<RegionPointList*>* pRegionPointList;
    TESWorldSpace* m_pContainingWorldspace;
    TESWeather* m_pRegionWeather;
    float fWeatherChance;
    NiColor m_kDiffuseColor;
    virtual ~FUN_004f08c0();
};
// Calls FUN_004f08c0 on this, deletes this when bit 0 of flags is set, and returns this.
// @fnv 0x004f0890
void* FUN_004f0890_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004f08c0 *>((this))->FUN_004f08c0::~FUN_004f08c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004f08c0
FUN_004f08c0::~FUN_004f08c0()
{
    if (m_pRegionDataList != 0)
    {
        delete m_pRegionDataList;
    }
    if (pRegionPointList != 0)
    {
        RegionPointList* pointList = (pRegionPointList->m_item);
        while (pointList != 0)
        {
            pRegionPointList->RemoveHead();
            delete pointList;
            pointList = (pRegionPointList->m_item);
        }
        delete pRegionPointList;
    }
}

struct PointProxy
{
};
struct ListProxy
{
    void FUN_005ae3d0(PointProxy* const&);
};
struct DataProxy
{
};
struct RegionProxy : FUN_004f0770
{
    RegionProxy* FUN_004f10d0(RegionProxy*);
};
// Copies this region into destination (allocating one if null), copying its data and each list node's point proxy.
// @fnv 0x004f10d0
RegionProxy* RegionProxy::FUN_004f10d0(RegionProxy* destination)
{
    RegionProxy* result = destination ? destination : (RegionProxy*)new FUN_004f0770;
    ListProxy* pNode = ((::ListProxy *)(reinterpret_cast<::BGSTerrainManager *>(this)->GetMinLevel()));
    reinterpret_cast<::FUN_00485130_shell *>(this)->WarnCopyUnsupported((::TESForm *)(result));
    reinterpret_cast<::RDL_004f3330 *>((((::DataProxy *)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0()))))->FUN_004f3470((::RDL_004f3330 *)(::DataProxy *)(((::DataProxy *)(reinterpret_cast<::FUN_009611e0_shell *>((result))->FUN_009611e0()))));
    while (pNode && ((::PointProxy *)((void *)(pNode))))
    {
        ((::ListProxy *)(reinterpret_cast<::BGSTerrainManager *>((result))->GetMinLevel()))->FUN_005ae3d0(((::PointProxy *)(reinterpret_cast<::FUN_004f80c0_shell *>((((::PointProxy *)((void *)(pNode)))))->CloneRegionPointList((::RegionPointList *)(0)))));
        pNode = ((::ListProxy *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return result;
}

struct S_004f1300_Item
{
};

struct S_004f1300_Base0
{
    virtual void vfn00();
};

struct S_004f1300_Holder : S_004f1300_Base0, BSSimpleList<S_004f1300_Item*>
{
};

struct S_004f1300_Mgr
{
};

struct S_004f1300_Save
{
};


// @fnv 0x004f1300
void __cdecl FUN_004f1300()
{
    unsigned short m_usPassCountLocal = 0;
    unsigned short* pusCount4 = ((unsigned short *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::S_004f1300_Save * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::S_004f1300_Save * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&m_usPassCountLocal, 2);

    BSSimpleList<S_004f1300_Item*>* pNodeX = ((::S_004f1300_Holder *)(reinterpret_cast<::FUN_004169d0_shell *>(((*reinterpret_cast<::S_004f1300_Mgr * *>(&::g_dataHandler))))->FUN_004169d0()));
    while (pNodeX && !pNodeX->IsEmpty())
    {
        S_004f1300_Item* pItem = (pNodeX->m_item);
        int iID2 = 0;
        float fSecondFunctionValue = 0.0f;
        if (pItem)
        {
            iID2 = reinterpret_cast<::FUN_0084e3a0_Class *>((pItem))->FUN_0084e3a0();
            fSecondFunctionValue = reinterpret_cast<::FUN_00526ae0_class *>((pItem))->FUN_00526ae0();
        }
        reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::S_004f1300_Save * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&iID2), 4);
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::S_004f1300_Save * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&fSecondFunctionValue, 4);
        m_usPassCountLocal++;
        pNodeX = ((::BSSimpleList< ::S_004f1300_Item *> *)(reinterpret_cast<::Callees *>((pNodeX))->FUN_00726070()));
    }
    *pusCount4 = m_usPassCountLocal;
}

class TESRegionDataWeather : public TESRegionData
{
  public:
    virtual ~TESRegionDataWeather();
};

class B4F1050DataList
{
  public:
};

void* B4F1050GetWeatherTypes(TESRegionDataWeather* pkWeather);

class B4F1050Region
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B4F1050DataList* m_pkDataList;
    int unk1C;
    int unk20;
    void* m_pvWeatherTypes;

    void FUN_004f1050();
};

// Clears m_pvWeatherTypes, then if m_pkDataList exists, gets the type-3 region data and stores its weather types.
// @fnv 0x004f1050
void B4F1050Region::FUN_004f1050()
{
    m_pvWeatherTypes = 0;
    if (m_pkDataList)
    {
        TESRegionDataWeather* pkWeather = dynamic_cast<TESRegionDataWeather*>(((::TESRegionData *)(reinterpret_cast<::GList *>((m_pkDataList))->FUN_004f35b0(3))));
        if (pkWeather)
            m_pvWeatherTypes = B4F1050GetWeatherTypes(pkWeather);
    }
}

struct RefQ
{
};
struct ElemQ
{
};
struct VElemQ
{
    virtual void v0();
    virtual void Save();
};
struct LstAQ
{
    bool FUN_008256d0();
};
struct LstBQ
{
    bool FUN_008256d0();
};
struct OwnQ
{
    void FUN_004f0a40();
};
// Calls FUN_004855a0, passes a reference-derived ID to FUN_00485910, traverses two lists calling FUN_004f77c0 and Save on their elements, then calls FUN_00485680.
// @fnv 0x004f0a40
void OwnQ::FUN_004f0a40()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    RefQ* pRef_gmplt = ((::RefQ *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()));
    if (pRef_gmplt)
    {
        unsigned int uiID_ldrt = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pRef_gmplt))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e57, uiID_ldrt);
    }
    LstAQ* pIterA_kkeo = ((::LstAQ *)(reinterpret_cast<::BGSTerrainManager *>(this)->GetMinLevel()));
    while (pIterA_kkeo && !pIterA_kkeo->FUN_008256d0())
    {
        reinterpret_cast<::FUN_004f77c0_shell *>(((*((::ElemQ **)((void *)(pIterA_kkeo))))))->FUN_004f77c0();
        pIterA_kkeo = ((::LstAQ *)(reinterpret_cast<::Callees *>((pIterA_kkeo))->FUN_00726070()));
    }
    LstBQ* pIterB_jeqla = ((::LstBQ *)(reinterpret_cast<::FUN_009611e0_shell *>(this)->FUN_009611e0()));
    while (pIterB_jeqla && !pIterB_jeqla->FUN_008256d0())
    {
        (*((::VElemQ **)((void *)(pIterB_jeqla))))->Save();
        pIterB_jeqla = ((::LstBQ *)(reinterpret_cast<::Callees *>((pIterB_jeqla))->FUN_00726070()));
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}
