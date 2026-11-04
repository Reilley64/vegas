#pragma once

// The leading data members of TESForm (as in TESForm.h), for units whose TESForm stand-ins declare no fields. The
// 32-bit getter folded into 0x0084e3a0 reads `iFormID` when called on a form.
struct FormFields
{
    void* vtable;
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
};
