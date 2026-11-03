#pragma once

namespace PageMeshes { struct Layout; }
namespace PageMeshes { struct Node; }

namespace PageMeshes {
struct Builder {
public:
    // 0x00a19060
    void BuildPage(::PageMeshes::Node *, ::PageMeshes::Layout *);
};
}
