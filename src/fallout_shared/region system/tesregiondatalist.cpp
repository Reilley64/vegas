// fallout_shared/region system/tesregiondatalist.cpp: RegionDataList (4 functions)

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/GList.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_004f2000.h"
class TESRegionData;

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    unsigned int ItemsInList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void RemoveHead();
};

class TESRegionData
{
  public:
    virtual ~TESRegionData();
};

class RegionDataList : public BSSimpleList<TESRegionData*>
{
  protected:
    bool m_bDataFlag;

  public:
    void Clear();
};

// @fnv 0x004f3400
void RegionDataList::Clear()
{
    TESRegionData* pkRegionData = 0;
    while (ItemsInList() != 0)
    {
        pkRegionData = ((::TESRegionData *)(new ((void *)this) ::Vec3()));
        RemoveHead();
        if (m_bDataFlag)
            delete pkRegionData;
    }
}

struct SeqObj
{
};
struct NodeTmp
{
};
struct Dummy
{
    void FUN_004f2480(unsigned char, unsigned char);
};
// Walks the region data list from GetName and calls FUN_004f24e0 on each non-null entry with a1 and a2.
// @fnv 0x004f2480
void Dummy::FUN_004f2480(unsigned char aucArg1, unsigned char aucArg2)
{
    BSSimpleList<TESRegionData*>* pcurrent = ((::BSSimpleList< ::TESRegionData *> *)(reinterpret_cast<::TESTopicInfoData *>((((SeqObj*)this)))->GetLinkToList()));
    while (pcurrent)
    {
        if (((::TESRegionData *)((void *)(((NodeTmp*)pcurrent)))))
            ::FUN_004f24e0((::TESSound *)(((::TESRegionData *)((void *)(((NodeTmp*)pcurrent))))), aucArg1, aucArg2);
        pcurrent = ((::BSSimpleList< ::TESRegionData *> *)(reinterpret_cast<::Callees *>((((NodeTmp*)pcurrent)))->FUN_00726070()));
    }
}

struct ListX
{
    ~ListX();
};
struct FUN_004f3360 : ListX
{
    ~FUN_004f3360();
};
// @fnv 0x004f3360
FUN_004f3360::~FUN_004f3360()
{
    ((RegionDataList*)(void*)this)->Clear();
}

struct ProbeBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual unsigned int v10();
};

class FUN_004f33c0_cls
{
  public:
    void FUN_005ae3d0(ProbeBase** appProbe);

    bool FUN_004f33c0(ProbeBase* apProbe);
};

// @fnv 0x004f33c0
bool FUN_004f33c0_cls::FUN_004f33c0(ProbeBase* apProbe)
{
    if (apProbe == 0 || ((int)(reinterpret_cast<::GList *>(this)->FUN_004f35b0(apProbe->v10()))))
    {
        return false;
    }
    FUN_005ae3d0(&apProbe);
    return true;
}
