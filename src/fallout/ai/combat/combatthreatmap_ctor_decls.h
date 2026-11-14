// fallout/ai/combat/combatthreatmap_ctor_decls.h: declares CombatThreatRecord, ReadWriteLock, CombatThreatMap
#ifndef FNV_ASTRA_COMBATTHREATMAP_H
#define FNV_ASTRA_COMBATTHREATMAP_H

#include <stddef.h>
#include "fnv/decl/Fn9a4f40.h"
#include "fnv/decl/ThreatMapInit.h"
#include "fnv/symbols_0108d000.h"
class TESForm;
struct BGSLoadGameBuffer;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const;
};
// Prefix-only PC view, inferred from the folded NiPointer conversion called on
// the threat address itself. No sizeof/new/member-destruction operation on a
// CombatThreatRecord is emitted here; its real destructor remains external.
class CombatThreatRecord : public NiPointer<TESForm>
{
  public:
    ~CombatThreatRecord();
};
template <class K, class V> class NiTMapItem;
template <class T> class DFALL;
template <class Allocator, class K, class V> class NiTMapBase
{
  public:
    unsigned int vtable;
    unsigned int m_uiHashSize;
    NiTMapItem<K, V>** m_ppkHashTable;
    struct MapEntryCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;
    void* GetFirstPos();
    void GetNext(void*&, K&, V&);
    bool RemoveAt(K);
};
template <class K, class V> class NiTMap : public NiTMapBase<DFALL<NiTMapItem<K, V> >, K, V>
{
};
class ReadWriteLock
{
  public:
    volatile unsigned int m_uiLockState;
    unsigned int m_uiWriterThreadId;
};
struct CombatTargetTimestamp
{
  public:
    float value;
    CombatTargetTimestamp(float);
public:
    float FUN_006a7f50() const;
};
class FUN_00906f60
{
  public:
    unsigned int data[2];
    FUN_00906f60();
};
class NiAVObject;
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    NiPointer(NiAVObject*);
    ~NiPointer();
};
class FUN_00993960 : public NiTMap<unsigned int, CombatThreatRecord*>
{
  public:
    ReadWriteLock Lock;
    unsigned int padding[2];
    FUN_00993960(int, int);
    ~FUN_00993960();
};
class CombatThreatMap : public FUN_00993960
{
  public:
    CombatTargetTimestamp stamp;
    FUN_00906f60 pair1, pair2;
    unsigned int mode;
    NiPointer<NiAVObject> object;
    CombatThreatMap();
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
};
#endif
