#pragma once

namespace fnv_00ad47f0 { namespace std { template <class, class> class basic_ostream; } }
namespace fnv_00ad47f0 { namespace std { template <class> struct char_traits; } }
namespace plus2ad4 { struct BxString; }
namespace plusad42 { struct BxString; }
namespace std { class locale; }
namespace std { template <class, class, class> class codecvt; }
struct Input;
struct StrQ;
struct StringOstream;
template <class> struct BasicText;

// 0x00ad4210
::plusad42::BxString FUN_00ad4210(const ::plusad42::BxString &, const char *);
// 0x00ad42e0
::plus2ad4::BxString FUN_00ad42e0(const ::plus2ad4::BxString &, const ::plus2ad4::BxString &);
// 0x00ad43a0
::Input &FUN_00ad43a0(::Input &, ::BasicText<char> &);
// 0x00ad47f0
namespace fnv_00ad47f0 { ::fnv_00ad47f0::std::basic_ostream<char, ::fnv_00ad47f0::std::char_traits<char>> &FUN_00ad47f0(::fnv_00ad47f0::std::basic_ostream<char, ::fnv_00ad47f0::std::char_traits<char>> &, const char *); }
// 0x00ad4ba0
::StringOstream &FUN_00ad4ba0(::StringOstream &, const ::StrQ &);
// 0x00ad4fd0
const ::std::codecvt<char, char, int> &FUN_00ad4fd0(const ::std::locale &);
