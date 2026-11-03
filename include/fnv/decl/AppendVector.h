#pragma once

namespace dtorb181 { template <class> struct GvConstIterator; }
namespace dtorb181 { template <class> struct GvIterator; }
struct AppendElement;

struct AppendVector {
public:
    // 0x00b1e640
    void FUN_00b1e640(const struct ::AppendElement &);
    // 0x00b1fd50
    ::dtorb181::GvIterator< struct ::AppendElement> FUN_00b1fd50(::dtorb181::GvConstIterator< struct ::AppendElement>, const struct ::AppendElement &);
};
