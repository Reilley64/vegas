#pragma once

namespace fnv_00849d00 { struct FormIDConverter; }
namespace fnv_00849d00 { struct LoadFormBufferH; }
namespace fnv_00849d00 { class SaveLoadFile; }

namespace fnv_00849d00 {
struct BGSSaveLoadGameImpl {
public:
    // 0x00849d00
    unsigned int LoadFormData(::fnv_00849d00::SaveLoadFile *, ::fnv_00849d00::LoadFormBufferH *, ::fnv_00849d00::FormIDConverter *);
};
}
