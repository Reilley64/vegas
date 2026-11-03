// fallout_shared/tescondition_decls.h: declares PackageList, TESFile, TESObjectREFR, MemoryManager, TESConditionItem and more
#ifndef TESCONDITION_DECLS_H
#define TESCONDITION_DECLS_H


#include "fnv/decl/Date.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_005ec040_stand.h"
#include "fnv/decl/S_006815d0.h"
#include "fnv/decl/s5693d0__Owner.h"
#include "fnv/symbols_00401000.h"
class TESPackage;
class PackageList
{
  public:
    void AddPackage(TESPackage*);
};
class TESForm;
class TESFile
{
  public:
};
class TESObjectREFR
{
  public:
};
class TESTopic;
template <class T> class BSSimpleList;
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class MemoryManager
{
  public:
};

class TESConditionItem
{
  public:
    char opaque[0x1C];
    TESConditionItem();
    ~TESConditionItem();
    void Load(TESFile* file);
    void InitItem(TESForm* form);
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target, bool& result);
};

class DecalDataDeleter
{
  public:
};

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    BSSimpleList(T& item);
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void AddHead(T& item);
    void RemoveHead();
};

class PerkEntryConditionSet
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target, bool& result, bool arg3);
    void InitItem(TESForm* form);
    bool Compare(PerkEntryConditionSet* other);
    void InitializeConditionItems();
    void Load(TESFile* file);
};
#endif
