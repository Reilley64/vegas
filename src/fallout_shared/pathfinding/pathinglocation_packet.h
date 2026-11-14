
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/fnv_00696a50__FUN_00696a50_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_006dd000.h"
#include "fnv/symbols_006df000.h"
#include "fnv/symbols_0106c000.h"
#include "fnv/symbols_011de000.h"
class FindTriangleForLocationFilter;
class PathingLocationProxy : public PathingLocation
{
  public:
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    TESObjectCELL* GetContainingCell();
    const NavMeshInfo* GetAssociatedNavMesh();
};

class PathingLocationArray
{
  public:
    void ConstructItems(PathingLocation*, unsigned int);
};

struct BGSLoadGameBuffer
{
  public:
};
struct BGSLoadFormBuffer
{
  public:
};
class TESObjectREFR;
class Pathing
{
  public:
public:
    ::TESObjectREFR *FindReferenceByFormId(unsigned int);
};
class TES
{
  public:
};
const BSSimpleArray<NavMeshInfo_const*, 1024>* FUN_006d6f40(TESObjectCELL*);
const BSSimpleArray<NavMeshInfo_const*, 1024>* ForwardToPathing(TESWorldSpace*, unsigned int);
struct NavMeshPtr
{
  public:
    void* pointer;
    NavMeshPtr();
    ~NavMeshPtr();
};
class NiNode : public TESForm
{
};
class NavMeshBounds
{
  public:
    NiPoint3 FUN_0069c070(const NiPoint3&);
};
class NiFormArray
{
  public:
    TESForm*& FUN_00877a30(unsigned int);
};
class PathBuilderDetailedPathInfos : public BSSimpleArray<unsigned int, 1024>
{
  public:
    PathBuilderDetailedPathInfos();
    ~PathBuilderDetailedPathInfos();
};

class NavMesh
{
  public:
};
