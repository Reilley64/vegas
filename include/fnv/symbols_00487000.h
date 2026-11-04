#pragma once

class BaseFormComponent;
class LeveledObject;
class TESFile;
class TESForm;
class TESFullName;
struct TESHealthForm_Dummy;
struct TESLeveledList;

// 0x00487050
void ReadFullName(::TESFullName *, ::TESFile *);
// 0x004871d0
void *FUN_004871d0(::BaseFormComponent *);
// 0x004872e0
::TESHealthForm_Dummy *GetHealthForm(::TESForm *);
// 0x00487420
void *FUN_00487420(void *);
// 0x00487ba0
::LeveledObject *InitLeveledObject(::LeveledObject *);
// 0x00487be0
::TESLeveledList *FUN_00487be0(::TESForm *);
// 0x00487f50
unsigned int DialogueRandom();
