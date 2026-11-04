#pragma once

namespace MapLookupDetail { struct Allocator; }
namespace MapLookupDetail { template <class, class, class> class basic_string; }
namespace record_model { struct BxStrTraits; }

namespace MapLookupDetail {
struct LookupMap {
public:
    // 0x00b39210
    int &FUN_00b39210(const ::MapLookupDetail::basic_string<char, ::record_model::BxStrTraits, ::MapLookupDetail::Allocator> &);
};
}
