#pragma once

namespace fnv_00e57620 { struct KnotVector; }
namespace fnv_00e57620 { template <class> struct ElevationArray; }
struct FloatArray;
struct FloatArrayRef;
struct FloatVector;
struct InputFloats;
struct InputVertices;
struct MarkBounds;
struct VertexVector;

// 0x00e57210
int FUN_00e57210(::FloatArrayRef *, int);
// 0x00e57370
int RemoveAdjacentDuplicates(::FloatArray *, int);
// 0x00e57490
bool *FUN_00e57490(bool *, int, int, ::MarkBounds *, int, ::MarkBounds *, float);
// 0x00e57620
namespace fnv_00e57620 { char *FitSpline(char *, int, int, ::fnv_00e57620::ElevationArray< ::fnv_00e57620::KnotVector> *, ::fnv_00e57620::ElevationArray<float> *, int, ::fnv_00e57620::ElevationArray< ::fnv_00e57620::KnotVector> *, ::fnv_00e57620::ElevationArray<float> *, float, float); }
// 0x00e57d60
void ProcessGeometryPasses(int, const ::InputVertices *, const ::InputFloats *, void *, int, float, int &, ::FloatVector &, ::VertexVector &);
