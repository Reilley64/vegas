#pragma once

namespace dtorb181 { template <class> struct GvConstIterator; }
namespace dtorb181 { template <class> struct GvIterator; }
struct FrondPoint;

struct FrondPointAppend {
public:
    // 0x00b1e4c0
    void FUN_00b1e4c0(const ::FrondPoint &);
    // 0x00b1fab0
    ::dtorb181::GvIterator< ::FrondPoint> FUN_00b1fab0(::dtorb181::GvConstIterator< ::FrondPoint>, const ::FrondPoint &);
};
