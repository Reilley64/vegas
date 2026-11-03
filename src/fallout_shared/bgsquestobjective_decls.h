// fallout_shared/bgsquestobjective_decls.h: declares BGSQuestObjective
#ifndef BGSQUESTOBJECTIVE_DECLS_H
#define BGSQUESTOBJECTIVE_DECLS_H

#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/symbols_01011000.h"
class TESForm;
class TESQuest;
class TESObjectREFR;
class RegionObjectEntry
{
  public:
    void InitItem(TESForm*);
public:
    ::TESObjectREFR *GetReference(bool);
};
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
};
template <class T> class BSStringT
{
  public:
    char storage[8];
    BSStringT& operator=(const char*);
};
class BGSQuestObjective
{
  public:
    void* vtable;
    unsigned int iIndex;
    BSStringT<char> m_kDisplayText;
    TESQuest* m_pOwnerQuest;
    char targetList[8];
    unsigned char bInitialized;
    char pad[3];
    unsigned int state;
    BGSQuestObjective();
    void Initialize();
    void InitItem(TESQuest*);
};
#endif
