// fallout/ai/combat/combatthreatmap.cpp: CombatThreatMap, DelStandIn, ThreatMap (8 functions)

#include <cstdint>
#include "fnv/decl/Anim490.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_009a5270_class.h"
#include "fnv/decl/FUN_009a5780_cls.h"
#include "fnv/decl/FUN_00aa5ff0_Class.h"
#include "fnv/decl/Fn9a4f40.h"
#include "fnv/decl/Lock00aa62c0.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/Target_009a4710.h"
#include "fnv/decl/ThreatMapInit.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0108d000.h"
#include "fnv/symbols_011f4000.h"
#include "combatthreatmap_ctor_decls.h"

// Iterates the map's entries, calls LoadGame on each threat, and deletes and removes entries whose TESForm pointer is null.
// @fnv 0x009a5c40
void CombatThreatMap::ApplyLoadBuffer(BGSLoadGameBuffer* buffer)
{
    // A traversal cursor keeps its current key and continuation together.
    // Both are real values consumed by GetNext; there is no emulated frame.
    struct ThreatCursor
    {
        unsigned int key;
        void* position;
    } cursor;
    cursor.position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (cursor.position)
    {
        CombatThreatRecord* threat = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(cursor.position), (unsigned int *)&(cursor.key), (void **)&(threat));
        if (threat)
        {
            reinterpret_cast<::Fn9a4f40 *>((threat))->FUN_009a4f40((intptr_t)(buffer));
            if (!static_cast<TESForm*>(*threat))
            {
                delete threat;
                reinterpret_cast<::NiTMap_S *>(this)->RemoveKey(cursor.key);
            }
        }
    }
}

// Constructs a CombatThreatMap: initializes the base, stamp, mode and object, then calls InitThreatObjects.
// @fnv 0x00991080
CombatThreatMap::CombatThreatMap() : FUN_00993960(0, 1), stamp(-DAT_0108d9b0), mode(1), object(0)
{
    reinterpret_cast<::ThreatMapInit *>(this)->InitThreatObjects();
}


struct FUN_009a5df0
{
    virtual void dummy();
    ~FUN_009a5df0();
};

struct FUN_009a5050 : FUN_009a5df0
{
    ~FUN_009a5050();
};

// Destructor that forwards to DeleteAllEntries with this as the argument.
// @fnv 0x009a5050
FUN_009a5050::~FUN_009a5050()
{
    reinterpret_cast<::FUN_009a5270_class *>((this))->DeleteAllEntries();
}

struct MagicProjectile
{
};
template <class K, class V> struct NiTPointerMap
{
    void GetNext(void*&, K&, V&);
};
struct FUN_009a5cd0_cls
{
    void ProcessAllProjectiles(intptr_t dt);
};
// Iterates the map and calls Process(dt) on each non-null MagicProjectile value.
// @fnv 0x009a5cd0
void FUN_009a5cd0_cls::ProcessAllProjectiles(intptr_t aiDeltaTime)
{
    MagicProjectile* p;
    unsigned int id;
    void* it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (it)
    {
        p = 0;
        reinterpret_cast<::C6b7f20_Map *>((((NiTPointerMap<unsigned int, void*>*)this)))->FUN_006b7f20((::C6b7f20_Node **)&(it), (unsigned int *)&(id), (void **)&((void*&)p));
        if (p)
            reinterpret_cast<::FUN_004534f0_shell *>((p))->FUN_004534f0(aiDeltaTime);
    }
}

namespace fnv_009a5020 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Runs the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009a5020
void* DelStandIn::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_009a5050 *>((((DtorStandIn*)this)))->FUN_009a5050::~FUN_009a5050();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_009a5020

struct NiBound;
struct FUN_0043d450_Owner
{
    NiBound* FUN_0043d450();
    unsigned int pad00[0x8];
    void* unk20;
};
// Returns the bound stored at offset 0x20 of this object, or the global DAT_011f4288 when that pointer is null.
// @fnv 0x0043d450
NiBound* FUN_0043d450_Owner::FUN_0043d450()
{
    NiBound* pBound = (*(NiBound**)&this->unk20) ? (*(NiBound**)&this->unk20) : &::g_defaultBound;
    return pBound;
}

struct BGSLoadFormBuffer
{
};

struct KFModel;

struct Animation
{
};

struct Flt
{
    int pad;
    operator unsigned int();
};

struct FUN_00497c10_struct
{
    char pad0[8];
    unsigned int field_08;
    unsigned int field_0C;
    Flt field_10;
    unsigned int field_14;

    void LoadAnimationData(BGSLoadFormBuffer* buffer, Animation* anim);
};

// Reads three 4-byte fields from the buffer, defaults field_08 to 1 when zero, and adds an animation when field_08 is 2 and field_10 is nonzero.
// @fnv 0x00497c10
void FUN_00497c10_struct::LoadAnimationData(BGSLoadFormBuffer* buffer, Animation* anim)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field_08), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field_0C), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&field_14), 4);
    if (field_08 == 0)
    {
        field_08 = 1;
    }
    if (field_08 == 2 && (unsigned int)field_10)
    {
        reinterpret_cast<::Anim490 *>((anim))->AddModel((::Model490 *)(::KFModel *)((KFModel*)(uintptr_t)field_10), false);
    }
}

struct Pt3
{
    float x, y, z;
};
struct Stamp
{
    float value;
    Stamp(float);
};
struct Threat
{
};
struct ThreatLock
{
    void Lock();
};

struct ThreatMap
{
    int vtable;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    ThreatLock lock;
    float EvaluateThreats(Pt3 pos, intptr_t arg, float delay, float a, Stamp since, float b);
};

// Locks the map, sums each threat's Evaluate result for threats newer than since, clamps the total to 1.0, unlocks and returns it.
// @fnv 0x009a5670
float ThreatMap::EvaluateThreats(Pt3 pos, intptr_t arg, float delay, float a, Stamp since, float b)
{
    reinterpret_cast<::FUN_00aa5ff0_Class *>(&(lock))->FUN_00aa5ff0();
    float fTotal = 0;
    float fTime = 0;
    if (delay < ::_DAT_01012060)
        fTime = delay;
    else
        fTime = FUN_00435dd0() + delay;
    void* iter = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (iter)
    {
        unsigned int key = 0;
        Threat* threat3 = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(iter), (unsigned int *)&(key), (void **)&(threat3));
        if (reinterpret_cast<::CombatTargetTimestamp *>((void *)&(const struct ::Stamp &)((*(struct ::Stamp *)(reinterpret_cast<::FUN_009a5780_cls *>((threat3))->FUN_009a5780({})))))->FUN_006a7f50() <= reinterpret_cast<::CombatTargetTimestamp *>(&(since))->FUN_006a7f50())
            continue;
        float fValue = reinterpret_cast<::Target_009a4710 *>((threat3))->ComputeFalloff((const ::Pt_009a4710 &)(pos), (::Ctx_009a4710 *)(arg), fTime, a, b);
        fTotal += fValue;
        if (fTotal > 1.0)
        {
            fTotal = 1.0f;
            break;
        }
    }
    reinterpret_cast<::Lock00aa62c0 *>(&(lock))->FUN_00aa62c0();
    return fTotal;
}
