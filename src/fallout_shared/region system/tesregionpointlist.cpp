// fallout_shared/region system/tesregionpointlist.cpp: RegionPointList, TESObjectCELL, PointList (14 functions)

#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0041bbd0_shell.h"
#include "fnv/decl/FUN_0041bce0_class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f7130_cls.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004f7230__FUN_004f7230_Class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004f7000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
class TESFile;

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    ~BSSimpleList();
    void AddHead(T& item);
};

class NiPoint2
{
  public:
    float x;
    float y;
    NiPoint2();
};

class RegionPoint
{
  public:
    NiPoint2 Point;
    RegionPoint(const NiPoint2& apPoint);
};

struct TESRegionPointList__ScaleResult
{
};

class TESFile
{
  public:
    bool IsEndianConversionRequired();
};


template <int Value> struct EndianSizeTag
{
};

enum
{
    CHUNK_ID_RPLD_ID = 1145851986,
};

const char kInvalidRegionPointListLabel[] = "Invalid Region Point List data in file \"%s\".";

// Adjacent chunk-size/point-count pair. The two values share one 8-byte
// stack slot with the count first, which plain sequential locals do not
// reproduce under the recorded flags, so they are kept in one aggregate.
struct TESRegionPointListLoadCounts
{
    unsigned int uiPointCount;
    unsigned int uiChunkSize;
};

class RegionPointList : public BSSimpleList<RegionPoint*>
{
  public:
    TESRegionPointList__ScaleResult* m_pScaleResult;  // +0x8
    bool m_bOwnsPointMemory;                          // +0xC
    unsigned char layoutPaddingD[3];
    NiPoint2 m_kMinimums;                  // +0x10
    NiPoint2 Maximums;                     // +0x18
    unsigned int m_uiDistanceInsideAtMax;  // +0x20
    unsigned int iCount;                   // +0x24
    ~RegionPointList();
    bool ReadPointsFromFile(TESFile* apFile);
};

// Reads an RPLD chunk of NiPoint2 pairs, endian-swaps them, wraps each in a point object, updates bounds and adds it to the list.
// @fnv 0x004f79f0
bool RegionPointList::ReadPointsFromFile(TESFile* apFile)
{
    if (!apFile || ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())) != CHUNK_ID_RPLD_ID)
        return false;
    TESRegionPointListLoadCounts counts;
    counts.uiChunkSize = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
    counts.uiPointCount = counts.uiChunkSize >> 3;
    if (counts.uiChunkSize % 8 != 0)
    {
        ::FUN_005b5e40();
        return false;
    }
    if (counts.uiChunkSize != 0 && counts.uiPointCount != 0)
    {
        NiPoint2* pElementBuffer = new NiPoint2[counts.uiPointCount];
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pElementBuffer), counts.uiChunkSize);
        iCount = 0;
        for (unsigned int i = 0; i < counts.uiPointCount; i++)
        {
            if (apFile->IsEndianConversionRequired())
            {
                ::FUN_00401080((int *)(float *)(&pElementBuffer[i].x));
                ::FUN_00401080((int *)(float *)(&pElementBuffer[i].y));
            }
            RegionPoint* pPoint = new RegionPoint(pElementBuffer[i]);
            if (m_kMinimums.x > reinterpret_cast<::CombatTargetTimestamp *>((pPoint))->FUN_006a7f50())
                m_kMinimums.x = reinterpret_cast<::CombatTargetTimestamp *>((pPoint))->FUN_006a7f50();
            if (m_kMinimums.y > reinterpret_cast<::TimeoutTimer *>((pPoint))->FUN_006b9130())
                m_kMinimums.y = reinterpret_cast<::TimeoutTimer *>((pPoint))->FUN_006b9130();
            if (Maximums.x < reinterpret_cast<::CombatTargetTimestamp *>((pPoint))->FUN_006a7f50())
                Maximums.x = reinterpret_cast<::CombatTargetTimestamp *>((pPoint))->FUN_006a7f50();
            if (Maximums.y < reinterpret_cast<::TimeoutTimer *>((pPoint))->FUN_006b9130())
                Maximums.y = reinterpret_cast<::TimeoutTimer *>((pPoint))->FUN_006b9130();
            AddHead(pPoint);
            iCount++;
        }
        delete[] pElementBuffer;
        return true;
    }
    return false;
}

// Deletes the given region point list object.
// @fnv 0x004f0a10
void TESRegionPointList_Delete(RegionPointList* pointList)
{
    delete pointList;
}

#include "tesregionpointlist_cell.h"
// @fnv 0x00547110
TESRegionList* TESObjectCELL::GetRegionList(bool create)
{
    TESRegionList* result = 0;
    if (IsCellInterior())
        return 0;
    result = ((::TESRegionList *)(std::uintptr_t)(reinterpret_cast<::FUN_0041bce0_class *>(&(extraData))->FUN_0041bce0()));
    if (!result && create)
    {
        result = new TESRegionList(0);
        reinterpret_cast<::FUN_0041bbd0_shell *>(&(extraData))->SetRegionList((::RegionList *)(result));
    }
    return result;
}

struct FUN_004f7dd0_shell : public RegionPointList
{
    void FUN_004f7dd0();
};
// @fnv 0x004f7740
RegionPointList::~RegionPointList()
{
    reinterpret_cast<::FUN_004f7dd0_shell *>(this)->FUN_004f7dd0();
    if (m_pScaleResult)
        delete m_pScaleResult;
}

class BSThread
{
  public:
};

RegionPoint*& _ref_006815c0(void* pThis);
void _ref_0063f7b0(void* pThis);

// @fnv 0x004f7dd0
void FUN_004f7dd0_shell::FUN_004f7dd0()
{
    RegionPoint* pdelete = 0;
    while (reinterpret_cast<::ActorMover *>((reinterpret_cast<BSThread*>(this)))->GetCurrentMoveModeType() > 0)
    {
        pdelete = _ref_006815c0(this);
        _ref_0063f7b0(this);
        iCount = iCount - 1;
        if (pdelete != 0 && m_bOwnsPointMemory)
        {
            delete pdelete;
        }
    }
    iCount = 0;
    m_kMinimums.y = 3.4028234663852886e+38f;
    m_kMinimums.x = 3.4028234663852886e+38f;
    Maximums.y = ::DAT_01015f5c;
    Maximums.x = ::DAT_01015f5c;
}

namespace fnv_004f81e0 {
struct FUN_004f81e0_shell : public RegionPointList
{
    bool FUN_004f81e0(bool);
};

struct BSThread
{
};
struct FUN_004f8220_stub
{
    bool FUN_004f8220(bool);
};
// Returns false if abMinPointsTest is set and GetThreadID() is below 3, or if FUN_004f8220(true) returns true; otherwise returns true.
// @fnv 0x004f81e0
bool FUN_004f81e0_shell::FUN_004f81e0(bool abMinPointsTest)
{
    if ((abMinPointsTest && reinterpret_cast<::ActorMover *>((((BSThread*)this)))->GetCurrentMoveModeType() < 3) || ((FUN_004f8220_stub*)this)->FUN_004f8220(true))
        return false;
    return true;
}
}  // namespace fnv_004f81e0

RegionPoint*& _ref_006815c0(void* pThis);
void _ref_0063f7b0(void* pThis);

class TESRegionPointDist : public RegionPoint
{
  public:
};

struct FUN_004f7ca0_shell : public RegionPointList
{
    bool AddPoint(RegionPoint* apPoint, float afMinDistance);
};


struct FUN_004f7e80_shell : public RegionPointList
{
    float FUN_004f7e80();
};

RegionPoint*& _ref_006815c0(void* pThis);
float FUN_006a7f50(RegionPoint* pPoint);

// @fnv 0x004f7e80
float FUN_004f7e80_shell::FUN_004f7e80()
{
    float fMinValue = ::DAT_01016970;
    void* node2 = this;
    if (::_DAT_010231b0 > m_kMinimums.x)
    {
        return m_kMinimums.x;
    }
    while (node2 != 0 && _ref_006815c0(node2) != 0)
    {
        if (fMinValue > reinterpret_cast<::CombatTargetTimestamp *>((_ref_006815c0(node2)))->FUN_006a7f50())
        {
            fMinValue = reinterpret_cast<::CombatTargetTimestamp *>((_ref_006815c0(node2)))->FUN_006a7f50();
        }
        node2 = reinterpret_cast<::Callees *>((node2))->FUN_00726070();
    }
    return fMinValue;
}

namespace fnv_004f7fa0 {

struct RegionPointNode : BSSimpleList<RegionPoint*>
{
};

struct FUN_004f7fa0_shell : RegionPointList
{
    float GetMinimumY();
};

// @fnv 0x004f7fa0
float FUN_004f7fa0_shell::GetMinimumY()
{
    float minimumY = ::DAT_01016970;
    RegionPointNode* current = (RegionPointNode*)this;

    if (m_kMinimums.y < ::_DAT_010231b0)
    {
        return m_kMinimums.y;
    }

    while (current && _ref_006815c0(current))
    {
        if (reinterpret_cast<::TimeoutTimer *>((_ref_006815c0(current)))->FUN_006b9130() < minimumY)
        {
            minimumY = reinterpret_cast<::TimeoutTimer *>((_ref_006815c0(current)))->FUN_006b9130();
        }
        current = ((::fnv_004f7fa0::RegionPointNode *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
    }
    return minimumY;
}
}  // namespace fnv_004f7fa0

struct FUN_004f8030_shell : RegionPointList
{
    float GetMaxY();
};
// Returns Maximums.y if it exceeds DAT_010241b0, otherwise scans the list for the largest GetY() value, defaulting to DAT_01015f5c.
// @fnv 0x004f8030
float FUN_004f8030_shell::GetMaxY()
{
    float fMaximum = ::DAT_01015f5c;
    BSSimpleList<RegionPoint*>* pkPoint = this;
    if (Maximums.y > ::DAT_010241b0)
        return Maximums.y;
    while (pkPoint && _ref_006815c0(pkPoint))
    {
        if (fMaximum < reinterpret_cast<::TimeoutTimer *>((_ref_006815c0(pkPoint)))->FUN_006b9130())
            fMaximum = reinterpret_cast<::TimeoutTimer *>((_ref_006815c0(pkPoint)))->FUN_006b9130();
        pkPoint = ((::BSSimpleList< ::RegionPoint *> *)(reinterpret_cast<::Callees *>((pkPoint))->FUN_00726070()));
    }
    return fMaximum;
}

struct TESRegionPointList_ref : RegionPointList
{
    TESRegionPointList_ref(bool owns);
};
struct TESRegionPoint_ref : RegionPoint
{
};
struct FUN_004f80c0_shell : RegionPointList
{
    RegionPointList* CloneRegionPointList(RegionPointList* out);
};
// Builds a TESRegionPointList_ref from the points of the current list, cloning each point when the result owns its points, and returns it.
// @fnv 0x004f80c0
RegionPointList* FUN_004f80c0_shell::CloneRegionPointList(RegionPointList* apOutList)
{
    FUN_004f80c0_shell* current = this;
    RegionPointList* result = apOutList ? apOutList : new TESRegionPointList_ref(m_bOwnsPointMemory);
    RegionPoint* clonedPoint = 0;
    while (current != 0)
    {
        if (result->m_bOwnsPointMemory)
        {
            clonedPoint = ((::RegionPoint *)(reinterpret_cast<::FUN_004f7130_cls *>((reinterpret_cast<TESRegionPoint_ref*>(_ref_006815c0(current))))->FUN_004f7130((::SpawnedObject *)(0))));
            if (!reinterpret_cast<::FUN_004f7ca0_shell *>((reinterpret_cast<TESRegionPointList_ref*>(result)))->AddPoint(clonedPoint, 0.0f))
            {
                delete clonedPoint;
            }
        }
        else
        {
            reinterpret_cast<::FUN_004f7ca0_shell *>((reinterpret_cast<TESRegionPointList_ref*>(result)))->AddPoint(_ref_006815c0(current), 0.0f);
        }
        current =
            reinterpret_cast<FUN_004f80c0_shell*>(((::TESRegionPointList_ref *)(reinterpret_cast<::Callees *>((reinterpret_cast<TESRegionPointList_ref*>(current)))->FUN_00726070())));
    }
    return result;
}

struct PointNode
{
};
struct PointList : PointNode
{
    bool FUN_004f8220(bool);
};
// Adds apPoint to the list if it is at least afMinDistance from the region point, updates bounds and count, and returns whether it was added.
// @fnv 0x004f7ca0
bool FUN_004f7ca0_shell::AddPoint(RegionPoint* apPoint, float afMinDistance)
{
    if (!apPoint)
    {
        return false;
    }
    if (_ref_006815c0(this))
    {
        if (reinterpret_cast<::fnv_004f7230::FUN_004f7230_Class *>((((TESRegionPointDist*)_ref_006815c0(this))))->SquaredDistanceTo((::fnv_004f7230::RegionPoint *)(apPoint)) <
            afMinDistance * afMinDistance)
        {
            return false;
        }
    }
    AddHead(apPoint);
    if (reinterpret_cast<::PointList *>(this)->FUN_004f8220(false))
    {
        _ref_0063f7b0(this);
        return false;
    }
    iCount++;
    if (reinterpret_cast<::CombatTargetTimestamp *>((apPoint))->FUN_006a7f50() < m_kMinimums.x)
    {
        m_kMinimums.x = reinterpret_cast<::CombatTargetTimestamp *>((apPoint))->FUN_006a7f50();
    }
    if (reinterpret_cast<::TimeoutTimer *>((apPoint))->FUN_006b9130() < m_kMinimums.y)
    {
        m_kMinimums.y = reinterpret_cast<::TimeoutTimer *>((apPoint))->FUN_006b9130();
    }
    if (reinterpret_cast<::CombatTargetTimestamp *>((apPoint))->FUN_006a7f50() > Maximums.x)
    {
        Maximums.x = reinterpret_cast<::CombatTargetTimestamp *>((apPoint))->FUN_006a7f50();
    }
    if (reinterpret_cast<::TimeoutTimer *>((apPoint))->FUN_006b9130() > Maximums.y)
    {
        Maximums.y = reinterpret_cast<::TimeoutTimer *>((apPoint))->FUN_006b9130();
    }
    return true;
}
// Walks the point list and returns true if any four consecutive points pass the FUN_004f7310 test, wrapping to the head when closed.
// @fnv 0x004f8220
bool PointList::FUN_004f8220(bool closed)
{
    bool p = false;
    if (reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType() < 4)
        return false;
    PointNode* c = this;
    PointNode* j = ((::PointNode *)(reinterpret_cast<::Callees *>((c))->FUN_00726070()));
    PointNode* e = ((::PointNode *)(reinterpret_cast<::Callees *>((j))->FUN_00726070()));
    PointNode* l = ((::PointNode *)(reinterpret_cast<::Callees *>((e))->FUN_00726070()));
    while (((::PointNode *)(reinterpret_cast<::Callees *>((j))->FUN_00726070())))
    {
        e = ((::PointNode *)(reinterpret_cast<::Callees *>((j))->FUN_00726070()));
        if (e)
            l = ((::PointNode *)(reinterpret_cast<::Callees *>((e))->FUN_00726070()));
        else
            l = 0;
        p = false;
        do
        {
            if (!l)
            {
                if (closed && c != this)
                {
                    l = this;
                    p = true;
                }
                else
                    p = true;
            }
            if (c && j && e && l &&
                ::FUN_004f7310((::Point *)(*((::RegionPoint **)((void *)(c)))), (::Point *)(*((::RegionPoint **)((void *)(j)))), (::Point *)(*((::RegionPoint **)((void *)(e)))), (::Point *)(*((::RegionPoint **)((void *)(l))))))
                return true;
            e = l;
            if (l)
                l = ((::PointNode *)(reinterpret_cast<::Callees *>((l))->FUN_00726070()));
        } while (!p);
        c = j;
        j = ((::PointNode *)(reinterpret_cast<::Callees *>((j))->FUN_00726070()));
    }
    return false;
}

#include <string.h>
struct RegionPointAccess : RegionPoint
{
};
struct RegionNode : PointNode
{
    bool FUN_008256d0();
};
struct FUN_004f77c0_shell : RegionPointList
{
    void FUN_004f77c0();
};
// Calls FUN_00485910 with the distance value, then conditionally calls FUN_00485710 with the collected points.
// @fnv 0x004f77c0
void FUN_004f77c0_shell::FUN_004f77c0()
{
    ::FUN_00485910(0x494c5052, m_uiDistanceInsideAtMax);
    RegionNode* node = reinterpret_cast<RegionNode*>(this);
    if (!node->FUN_008256d0())
    {
        unsigned int points = 0;
        unsigned int count = 0;
        unsigned int capacity = 1024;
        NiPoint2* blocks = new NiPoint2[capacity * sizeof(NiPoint2)];
        while (node && !node->FUN_008256d0())
        {
            blocks[points] = (*(::NiPoint2 *)((void *)(static_cast<RegionPointAccess*>(*((::RegionPoint **)((void *)(node)))))));
            ++points;
            if (points >= capacity)
            {
                ++count;
                capacity = (count + 1) * 1024;
                NiPoint2* oldPoints = blocks;
                blocks = new NiPoint2[capacity * sizeof(NiPoint2)];
                memcpy(blocks, oldPoints, points * sizeof(NiPoint2));
                delete[] oldPoints;
            }
            node = ((::RegionNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        if (points)
            ::FUN_00485710((void *)(0x444c5052), blocks, (void *)(std::uintptr_t)(points * 2));
        delete[] blocks;
    }
}

typedef BSSimpleList<RegionPoint*> RegionPointNode;

RegionPoint*& _ref_006815c0(void* pThis);
float FUN_006a7f50(void* pThis);

struct FUN_004f7f10_cls : public RegionPointList
{
    float FUN_004f7f10();
};

// @fnv 0x004f7f10
float FUN_004f7f10_cls::FUN_004f7f10()
{
    float best3 = ::DAT_01015f5c;
    RegionPointNode* pNode = (RegionPointNode*)this;
    if ((double)this->Maximums.x > ::DAT_010241b0)
    {
        return this->Maximums.x;
    }
    while (pNode != 0 && _ref_006815c0(pNode) != 0)
    {
        if (best3 < reinterpret_cast<::CombatTargetTimestamp *>((_ref_006815c0(pNode)))->FUN_006a7f50())
        {
            best3 = reinterpret_cast<::CombatTargetTimestamp *>((_ref_006815c0(pNode)))->FUN_006a7f50();
        }
        pNode = ((::BSSimpleList< ::RegionPoint *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return best3;
}
