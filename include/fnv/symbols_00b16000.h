#pragma once

namespace fnv_00b138c0 { struct RangeTag; }
namespace fnv_00b157e0 { struct Entry24; }
namespace fnv_00b157e0 { struct EntryAllocator; }
namespace fnv_00b169c0 { struct EUMB; }
namespace fnv_00b16a10 { struct EUMB; }
namespace fnv_00b16dc0 { struct ElemMOVE; }
namespace fnv_00b16dc0 { template <class> class allocatorS; }
namespace fnv_00b16ec0 { struct E6EC0; }
namespace fnv_00b16ec0 { struct _Range_checked_iterator_tagS; }
namespace fnv_00b16ec0 { struct _Undefined_move_tagS; }
namespace fnv_00b16ec0 { struct random_access_iterator_tagS; }
struct PartitionBounds;
struct S_b16cd0;
struct SortEntry;
struct SortPred_b16b60;
struct SortPredicate;

// 0x00b16950
namespace fnv_00b138c0 { void FUN_00b16950(unsigned int, unsigned int, unsigned int, unsigned int, ::fnv_00b138c0::RangeTag); }
// 0x00b169c0
namespace fnv_00b169c0 { ::fnv_00b169c0::EUMB *FUN_00b169c0(::fnv_00b169c0::EUMB *, ::fnv_00b169c0::EUMB *, ::fnv_00b169c0::EUMB *); }
// 0x00b16a10
namespace fnv_00b16a10 { ::fnv_00b16a10::EUMB *FUN_00b16a10(::fnv_00b16a10::EUMB *, ::fnv_00b16a10::EUMB *, ::fnv_00b16a10::EUMB *); }
// 0x00b16a60
namespace fnv_00b0f410 { int *FUN_00b16a60(int *, int *, int *); }
// 0x00b16b00
int *FUN_00b16b00(unsigned int, int);
// 0x00b16b60
void FUN_00b16b60(::SortEntry **, ::SortEntry **, int, ::SortPred_b16b60);
// 0x00b16cd0
void CopyStructArray(::S_b16cd0 *, unsigned int, ::S_b16cd0 *);
// 0x00b16dc0
namespace fnv_00b16dc0 { ::fnv_00b16dc0::ElemMOVE *FUN_00b16dc0(::fnv_00b16dc0::ElemMOVE *, ::fnv_00b16dc0::ElemMOVE *, ::fnv_00b16dc0::ElemMOVE *, ::fnv_00b16dc0::allocatorS< ::fnv_00b16dc0::ElemMOVE> &); }
// 0x00b16e40
namespace fnv_00b157e0 { ::fnv_00b157e0::Entry24 *FUN_00b16e40(::fnv_00b157e0::Entry24 *, ::fnv_00b157e0::Entry24 *, ::fnv_00b157e0::Entry24 *, ::fnv_00b157e0::EntryAllocator &); }
// 0x00b16ec0
namespace fnv_00b16ec0 { ::fnv_00b16ec0::E6EC0 *FUN_00b16ec0(::fnv_00b16ec0::E6EC0 *, ::fnv_00b16ec0::E6EC0 *, ::fnv_00b16ec0::E6EC0 *, ::fnv_00b16ec0::random_access_iterator_tagS, ::fnv_00b16ec0::_Undefined_move_tagS, ::fnv_00b16ec0::_Range_checked_iterator_tagS); }
// 0x00b16f70
::PartitionBounds FUN_00b16f70(::SortEntry **, ::SortEntry **, ::SortPredicate);
