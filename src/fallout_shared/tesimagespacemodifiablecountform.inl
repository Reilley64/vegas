
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "tesimagespacemodifiablecountform_decls.h"
// @fnv 0x005820a0
void TESImageSpaceModifiableCountForm_6_::InitItem(TESForm* owner)
{
    for (unsigned int i = 0; i < 6; ++i) {
        if (m_pImageSpaceModifier[i]) {
            unsigned int formID = (unsigned int)(std::uintptr_t)m_pImageSpaceModifier[i];
            if (owner)
                ::ResolveFormID((unsigned int *)&(formID), owner->GetFile(-1));
            m_pImageSpaceModifier[i] = dynamic_cast<TESImageSpaceModifier*>(::FUN_004839c0(formID));
            if (!m_pImageSpaceModifier[i]) {
                if (owner) {
                    if (((BGSCameraPath*)owner)->HasNameForWarning())
                        ::FUN_005b5e40();
                    else
                        ::FUN_005b5e40();
                } else
                    ::FUN_005b5e40();
            }
        }
    }
}
