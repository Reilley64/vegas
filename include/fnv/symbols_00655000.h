#pragma once

#include <cstdint>

namespace fnv_00655320 { class BSFaceGenNiNode; }
namespace fnv_00655320 { struct FaceGenData; }
namespace fnv_006558b0 { class BSFaceGenNiNode; }
namespace fnv_006558b0 { struct FaceGenData; }
namespace fnv_00655fa0 { struct FaceGenData; }
namespace fnv_00655fa0 { class NiAVObject; }

// 0x00655270
std::uintptr_t FUN_00655270();
// 0x00655320
namespace fnv_00655320 { void BuildHairFaceGenNodes(::fnv_00655320::BSFaceGenNiNode **, ::fnv_00655320::BSFaceGenNiNode **, ::fnv_00655320::FaceGenData *, bool); }
// 0x006558b0
namespace fnv_006558b0 { void CreateEyeGeometry(::fnv_006558b0::BSFaceGenNiNode **, ::fnv_006558b0::BSFaceGenNiNode **, ::fnv_006558b0::FaceGenData *, bool); }
// 0x00655fa0
namespace fnv_00655fa0 { void ApplyFaceGenTextures(::fnv_00655fa0::NiAVObject *, ::fnv_00655fa0::FaceGenData *); }
