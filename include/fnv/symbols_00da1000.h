#pragma once

struct ScriptProgram;
struct hkGeometry;
struct hkTransform;
struct hkVector4;
template <class> struct MeshArray;

// 0x00da12b0
void FUN_00da12b0(::ScriptProgram *, float, bool, ::MeshArray<int> *, ::MeshArray<int> *);
// 0x00da16d0
void FUN_00da16d0(const ::hkVector4 &, const ::hkVector4 &, float, int, int, const ::hkTransform &, ::hkGeometry *&);
