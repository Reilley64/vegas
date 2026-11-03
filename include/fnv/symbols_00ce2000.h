#pragma once
#include <cstdint>

struct FnvSpawnedObject;
struct Transform;
template <class> struct PointerParam;

// 0x00ce2a00
bool FUN_00ce2a00(int, ::FnvSpawnedObject *);
// 0x00ce2d10
void FUN_00ce2d10(const struct ::Transform *, ::PointerParam<const struct ::Transform>, const short *, int, struct ::Transform *);
// 0x00ce2f30
void FUN_00ce2f30();
// 0x00ce2f40
void FUN_00ce2f40(unsigned int, uintptr_t, unsigned int, int, unsigned int);
