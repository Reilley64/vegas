// fallout_shared/pathfinding/pathinglocation_decls.h: declares TESForm, TESObjectCELL, PathingLocation, NavMeshInfo, TESWorldSpace and more

#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_006a9520_Class.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0068f000.h"
#include "fnv/symbols_006dd000.h"
#define NiPoint3 NiPoint3Layout
#define BSSimpleArray BSSimpleArrayLayout
#define NiPointer NiPointerLayout
#define TESObjectCELL TESObjectCELLLayout
#define PathingLocation PathingLocationLayout
#include "PathingLocation.h"
#undef PathingLocation
#undef TESObjectCELL
#undef BSSimpleArray
#undef NiPointer
#undef NiPoint3
#include "pathinglocation_templates.h"
class TESObjectCELL;
struct BGSLoadGameBuffer;
class TESForm
{
  public:
    virtual void vfn_0();
public:
    bool GetDisabled() const;
};
class TESWorldSpace;
class TESObjectCELL : public TESForm
{
  public:
    bool IsOutdoorCell();
public:
    bool IsCellInterior() const;
public:
    int GetCellGridX();
public:
    int GetCellGridY();
public:
    ::TESWorldSpace *GetParentWorldSpace();
};

struct PathingLocation
{
  public:
    void** m_ppVirtualMethodTable;
    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    const BSSimpleArray<NavMeshInfo_const*, 1024>* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    unsigned char layoutPadding27[1];

    PathingLocation();
    void LoadGame(BGSLoadGameBuffer*);
    bool HasPathingLocation();
    bool HasValidTriangle();
    void ResetLocation();
    TESObjectCELL* GetContainingCell();
    bool ResolveNavMesh(NavMeshPtr&);
    bool FindNavMeshTriangle(NavMeshPtr&, unsigned short&);
    PathingLocation(const NiPoint3&, TESObjectREFR*);
    PathingLocation& operator=(const PathingLocation&);
    void SetLocationData(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
public:
    bool HasValidTriangle_006dd6a0();
};

class NavMeshInfo
{
  public:
    unsigned char layoutPadding0[0xC];
    unsigned int uiUnk0C;
    bool ResolveNavMesh(NavMeshPtr&);
};

class TESWorldSpace : public TESForm
{
  public:
    TESObjectCELL* GetCellByKey(unsigned int);
};

class TESObjectREFR
{
  public:
};

class LowProcess
{
  public:
    TESObjectREFR* GetTarget();
    int GetPackageObjectType();
};

class InventoryStackRecord;

#include "pathinglocation_packet.h"
