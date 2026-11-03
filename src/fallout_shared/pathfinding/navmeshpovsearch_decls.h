// fallout_shared/pathfinding/navmeshpovsearch_decls.h: declares NiPoint3, NavMeshBounds, SineCosine, CircularArc, Sphere and more

#include "fnv/decl/A06F0Key.h"
#include "fnv/decl/FUN_004941c0_shell.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/symbols_00401000.h"
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};
class ParentSpaceNode;
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    int data[4];
    template <int M> void CopyTo(BSSimpleArray<T, M>*);
    void CopyRecordsTo(BSSimpleArray*);
};
class NavMeshBounds
{
  public:
    NiPoint3 min, max;
    BSSimpleArray<unsigned short, 1024> triangles;
    BSSimpleArray<ParentSpaceNode, 1024> parents;
    void CopyTo(NavMeshBounds*);
};
class SineCosine
{
  public:
    float fCos, fSin;
    SineCosine operator-(const SineCosine&) const;
};
class CircularArc
{
  public:
    SineCosine start, end;
    int direction;
    bool FUN_006a0660(const SineCosine&) const;
public:
    float GetLength(float);
};
class Sphere
{
  public:
    NiPoint3 Center;
    float fRadius;
};
enum ANGLE_DIRECTION
{
    CLOCKWISE,
    COUNTERCLOCKWISE
};
class SphereTangent
{
  public:
    ANGLE_DIRECTION direction;
    SineCosine start, end;
};
class SphereTangents
{
  public:
    int count;
    SphereTangent tangents[2];
};
class NavMeshPOVSearch
{
  public:
    static int FindSphereTangents(const Sphere&, const Sphere&, ANGLE_DIRECTION, SphereTangents&);
};
