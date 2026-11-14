#pragma once

namespace fnv_00ac2060 { template <class> class _Vector_const_iteratorS; }
namespace fnv_00ac2440 { struct Elem; }
namespace fnv_00ac2540 { struct FUN_00ac0530; }
struct CopyRecord;
struct Elem12;
struct FloatPair2290;
struct Quad21b0;
struct SpawnItem_cls;

// 0x00ac2060
namespace fnv_00ac2060 { int *FUN_00ac2060(::fnv_00ac2060::_Vector_const_iteratorS<int>, ::fnv_00ac2060::_Vector_const_iteratorS<int>, int *); }
// 0x00ac20d0
void FUN_00ac20d0(::Elem12 *, unsigned int, const ::Elem12 &);
// 0x00ac21b0
void FUN_00ac21b0(::Quad21b0 *, unsigned int, const ::Quad21b0 &);
// 0x00ac2290
void FUN_00ac2290(::FloatPair2290 *, unsigned int, const ::FloatPair2290 &);
// 0x00ac2370
void FUN_00ac2370(::SpawnItem_cls *, unsigned int, void *);
// 0x00ac2440
namespace fnv_00ac2440 { void FUN_00ac2440(::fnv_00ac2440::Elem *, unsigned int, const ::fnv_00ac2440::Elem &); }
// 0x00ac2540
namespace fnv_00ac2540 { void FUN_00ac2540(::fnv_00ac2540::FUN_00ac0530 *, unsigned int, const ::fnv_00ac2540::FUN_00ac0530 &); }
// 0x00ac2c20
::CopyRecord *CopyRecords(::CopyRecord *, ::CopyRecord *, ::CopyRecord *);
