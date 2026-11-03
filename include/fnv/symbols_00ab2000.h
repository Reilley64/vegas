#pragma once

#include <cstdint>

namespace ImageReaderTypes { template <class, class, class> class basic_string; }
namespace ImageReaderTypes { template <class> class allocator; }
namespace ImageReaderTypes { template <class> struct char_traits; }
namespace fnv_00ab2490 { struct FUN_0065ecd0_class; }
namespace fnv_00ab2580 { struct EgmElem; }
struct FillElem6;
struct Images;
struct PointAlloc;
struct ShortPoint;

// 0x00ab2210
::ShortPoint *FUN_00ab2210(::ShortPoint *, ::ShortPoint *, ::ShortPoint *);
// 0x00ab2260
::ShortPoint *FUN_00ab2260(::ShortPoint *, ::ShortPoint *, ::ShortPoint *, ::PointAlloc &);
// 0x00ab22e0
::ShortPoint *FUN_00ab22e0(::ShortPoint *, ::ShortPoint *, ::ShortPoint *);
// 0x00ab2380
void FUN_00ab2380(std::intptr_t, std::intptr_t, std::intptr_t, unsigned char);
// 0x00ab23c0
void FUN_00ab23c0(char *, unsigned int, const ::FillElem6 *);
// 0x00ab2490
namespace fnv_00ab2490 { void FUN_00ab2490(::fnv_00ab2490::FUN_0065ecd0_class *, unsigned int, const ::fnv_00ab2490::FUN_0065ecd0_class &); }
// 0x00ab2580
namespace fnv_00ab2580 { ::fnv_00ab2580::EgmElem *FUN_00ab2580(::fnv_00ab2580::EgmElem *, ::fnv_00ab2580::EgmElem *, ::fnv_00ab2580::EgmElem *); }
// 0x00ab2640
bool FUN_00ab2640(const ::ImageReaderTypes::basic_string<char, ::ImageReaderTypes::char_traits<char>, ::ImageReaderTypes::allocator<char>> &, unsigned int *, ::Images *, ::Images *);
