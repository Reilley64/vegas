#pragma once

class CF4840Saver;
class CF4BC0Object;
class CF4BC0Stream;
class F4A30Node;
class F4A30Result;
struct hkReferencedObject;

// 0x00cf4790
const char *GetConstraintTypeName(int);
// 0x00cf4840
::CF4840Saver *CreateSaver(unsigned int);
// 0x00cf4a30
::F4A30Result *CreateF4A30Result(::F4A30Node *, void *);
// 0x00cf4af0
::hkReferencedObject *FUN_00cf4af0(::CF4BC0Stream &);
// 0x00cf4bc0
void FUN_00cf4bc0(::CF4BC0Stream &, ::CF4BC0Object *);
