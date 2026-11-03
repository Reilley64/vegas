#pragma once

namespace addb18 { struct GvElem; }
namespace addb18 { template <class> struct GvConstIterator; }
namespace addb18 { template <class> struct GvIterator; }

struct AppendGuideVector {
public:
    // 0x00b1db40
    void FUN_00b1db40(const ::addb18::GvElem &);
    // 0x00b1dc50
    ::addb18::GvIterator< ::addb18::GvElem> FUN_00b1dc50(::addb18::GvConstIterator< ::addb18::GvElem>, const ::addb18::GvElem &);
};
