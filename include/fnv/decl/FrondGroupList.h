#pragma once

namespace dtorb181 { struct GvElemV; }
namespace dtorb181 { template <class> struct GvConstIterator; }
namespace dtorb181 { template <class> struct GvIterator; }
namespace dtorb181 { template <class> struct GvVector; }

struct FrondGroupList {
public:
    // 0x00b1df80
    void FUN_00b1df80(const ::dtorb181::GvVector< ::dtorb181::GvElemV> &);
    // 0x00b1f460
    ::dtorb181::GvIterator< ::dtorb181::GvVector< ::dtorb181::GvElemV>> FUN_00b1f460(::dtorb181::GvConstIterator< ::dtorb181::GvVector< ::dtorb181::GvElemV>>, const ::dtorb181::GvVector< ::dtorb181::GvElemV> &);
};
