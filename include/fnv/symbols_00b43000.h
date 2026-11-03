#pragma once

namespace fnv_00b43090 { struct E3090; }
namespace fnv_00b43090 { struct _Range_checked_iterator_tagS; }
namespace fnv_00b43090 { struct _Undefined_move_tagS; }
namespace fnv_00b43090 { struct random_access_iterator_tagS; }
namespace std { template <class> class allocator; }
struct Alloc8;
struct CopyElement;
struct Elem8;
struct SpawnedPair;

// 0x00b43010
::Elem8 *FUN_00b43010(::Elem8 *, ::Elem8 *, ::Elem8 *, ::Alloc8 &);
// 0x00b43090
namespace fnv_00b43090 { ::fnv_00b43090::E3090 *MoveBackwardOpt(::fnv_00b43090::E3090 *, ::fnv_00b43090::E3090 *, ::fnv_00b43090::E3090 *, ::fnv_00b43090::random_access_iterator_tagS, ::fnv_00b43090::_Undefined_move_tagS, ::fnv_00b43090::_Range_checked_iterator_tagS); }
// 0x00b431e0
::CopyElement *FUN_00b431e0(::CopyElement *, ::CopyElement *, ::CopyElement *, std::allocator< ::CopyElement> &);
// 0x00b43230
::SpawnedPair *FUN_00b43230(const ::SpawnedPair *, const ::SpawnedPair *, ::SpawnedPair *);
// 0x00b435f0
void SeedRandomSamples(long);
