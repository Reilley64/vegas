#pragma once

class TESForm;

class BGSListForm {
public:
    // 0x0058fb00
    void ClearData();
    // 0x00590010
    void IncludeForm(::TESForm *);
    // 0x00591b70
    BGSListForm();
};
