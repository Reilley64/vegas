// fallout_shared/pathfinding/pathbuilder_decls.h: declares PathingRequest, PathingSolution, TESRecipe, PathingLocationProxy

#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSSimpleArray_006cefa0.h"
#include "fnv/decl/FUN_006caa20_Class.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_011d7000.h"
class PathingRequest
{
  public:
    PathingLocation& GetOffsetC();
public:
    float GetCenterRadius();
};

class PathingSolution
{
  public:
    PathingInfoEntry* GetPathingInfoEntry(PathingInfoEntry&);
};

class RecipeCraftingInfo;
class TESRecipe
{
  public:
public:
    ::RecipeCraftingInfo *GetData();
};

class PathingLocationProxy
{
  public:
    bool FindContainingTriangle(FindTriangleForLocationFilter* filter);
    const NavMeshInfo* GetAssociatedNavMesh();
    TESObjectCELL* GetContainingCell();
};

class INISettingCollection;
template <> class SettingT<INISettingCollection>
{
  public:
    SETTING_VALUE* Bool();
};


union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    char* s;
};

class GlobalObject_00869f00
{
  public:
};
template <> class BSSimpleArray<NavMeshEdgeData, 1024>
{
  public:
    unsigned int data[5];
    BSSimpleArray(unsigned int, unsigned int, ScrapHeapBuffer*);
    ~BSSimpleArray();
    NavMeshEdgeData& FUN_006a1440(unsigned int);
};
