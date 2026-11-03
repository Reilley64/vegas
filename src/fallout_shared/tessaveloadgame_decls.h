// fallout_shared/tessaveloadgame_decls.h: declares TESForm, ChangesMap, TESSaveLoadGame, BSTaskManagerThread
#pragma once

#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00c42dd0.h"
class TESForm
{
  public:
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
public:
    bool GetDisabled() const;
};
class TESObjectREFR;
template <class K, class V> class NiTPointerMap
{
  public:
    bool GetAt(K, V&) const;
};
class ChangesMap : public NiTPointerMap<unsigned int, TESObjectREFR*>
{
  public:
    bool HasFormChanges(TESForm*, bool);
};
class BGSNote;
class BGSCameraShot;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    bool IsInList(T&);
    void Remove(T const&);
};
class TESSaveLoadGame
{
  public:
    ChangesMap* changes;
    char pad[0x10];
    void* unk14;
    char pad18[0x8];
    void* unk20;
    char pad24[0x10];
    BSSimpleList<BGSNote*> deferred;
    TESObjectREFR* QueueRemoveReferenceChange(unsigned int);
    void HasFormChanges(TESForm*, bool);
    void FinalizeForm(TESForm*);
};
class BSTaskManagerThread
{
  public:
    void* table;
    char pad[0x2c];
    void* manager;
    BSTaskManagerThread(void*, unsigned int);
};
extern void* DAT_010c1740[];

extern const char DAT_010c1748[];
