// The water form owner's creation entry. See docs/water-form-storage.md.
#ifndef FNV_WATER_WATER_FORM_H
#define FNV_WATER_WATER_FORM_H

struct TESWaterForm;

namespace fnv::water
{
// Allocates one water form with the size of the complete type and constructs
// it. A caller that does not see the complete type cannot size the form.
::TESWaterForm* NewWaterForm();
}  // namespace fnv::water

#endif
