#pragma once

class BaseFormComponent;
class TESForm;
class TESObject;

class TESContainer {
public:
    // 0x00481610
    TESContainer();
    // 0x00481680
    ~TESContainer();
    // 0x00481bb0
    void InitItem(::TESForm *);
    // 0x00481c80
    void CopyFromBase(::BaseFormComponent *);
    // 0x00481eb0
    bool HasObjectOfType(::TESObject *);
    // 0x00481f30
    static bool IsValidContainerType(unsigned char);
    // 0x00482a90
    int GetObjectCount(::TESObject *);
};
