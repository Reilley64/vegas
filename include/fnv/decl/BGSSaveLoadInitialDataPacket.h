#pragma once

class BGSLoadFormBuffer;
class FormChangeMask;
class TESForm;
enum INITIAL_DATA_TYPE;

class BGSSaveLoadInitialDataPacket {
public:
    // 0x0084f330
    static ::INITIAL_DATA_TYPE LoadInitialDataForForm(::BGSLoadFormBuffer *, ::TESForm *, ::FormChangeMask);
};
