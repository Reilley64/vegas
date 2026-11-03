#pragma once

// The leading fields of TESForm, for interface code that reaches a form through a stand-in type.
struct FormFields
{
    void* vtable;
    unsigned char m_ucFormType;
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
};
