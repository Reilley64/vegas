// fallout/misc/garbagecollector.cpp: GarbageCollector (22 functions)

#include "fnv/tls.h"
#include <cstdint>
#include "fnv/decl/Animation.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/ControllerOwner.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00445430_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004aaf10_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_006bf8f0_Class.h"
#include "fnv/decl/FUN_0078d200_cls.h"
#include "fnv/decl/FUN_008691d0_cls.h"
#include "fnv/decl/FUN_00869640_StrArr.h"
#include "fnv/decl/FUN_00878360_Class.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/PtrArrayView.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/_FUN_0052aa80_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_00564d80__ArrSI.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00c5ac00__ArrObj.h"
#include "fnv/symbols_00446000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00452000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00869000.h"
#include "fnv/symbols_00fdf000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_01272000.h"
#include "garbagecollector_packet.h"
#include "original_garbagecollector.h"

const char kGarbageCollectorRemoveLabel[] = "GarbageCollector::Remove(TESObjectREFR)";

// Locks the garbage collector, removes the reference from both garbage lists if present, then unlocks it.
// @fnv 0x00868270
void GarbageCollector::Remove(TESObjectREFR* reference)
{
    ::LockGlobalObject(kGarbageCollectorRemoveLabel);
    unsigned int size = reinterpret_cast<::FUN_00658930_class *>(&((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874))))->GetShortAtOffsetA();
    for (unsigned int index = 0; index < size; ++index)
    {
        if ((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874)).GetAt(index) == reference)
        {
            reinterpret_cast<::FUN_008691d0_cls *>(&((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874))))->RemoveAt(index);
            break;
        }
    }
    size = reinterpret_cast<::FUN_00658930_class *>(&((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de8bc))))->GetShortAtOffsetA();
    for (unsigned int index = 0; index < size; ++index)
    {
        if ((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de8bc)).GetAt(index) == reference)
        {
            reinterpret_cast<::FUN_008691d0_cls *>(&((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de8bc))))->RemoveAt(index);
            break;
        }
    }
    ::fnv_00867f80::FUN_00867f80();
}

// @fnv 0x0040fc90
void GarbageCollector::QueryCurrentThread(bool)
{
    GetCurrentThreadId();
}

const char kGarbageCollectorClearTempEffectsLabel[] = "GarbageCollector::ClearTempEffects()";
// @fnv 0x00868d10
void GarbageCollector::ClearTempEffects()
{
    if (reinterpret_cast<::FUN_00658930_class *>(&(g_011de828))->GetShortAtOffsetA() && g_modelLoader->FUN_00868250())
    {
        ::LockGlobalObject(kGarbageCollectorClearTempEffectsLabel);
        reinterpret_cast<::fnv_00c5ac00::ArrObj *>(&(g_011de828))->FUN_004dffa0();
        reinterpret_cast<::FUN_004aaf10_shell *>((g_modelLoader))->FUN_004aaf10();
        ::fnv_00867f80::FUN_00867f80();
    }
}

const char kGarbageCollectorUpdateLabel[] = "GarbageCollector::Update()";
struct NavMeshPtr
{
    operator NavMesh*() const;
    NavMesh* FUN_00458b50();
};
struct TwoPointerRecord
{
    TwoPointerRecord(unsigned int, const char*);
    ~TwoPointerRecord();
    unsigned int id;
    unsigned int startTime;
};

// @fnv 0x00868790
void __cdecl AddNavMeshToGarbageCollector(NavMeshPtr& apNavMesh)
{
    TwoPointerRecord tempAutoEvent(0x20, "GarbageCollector::Add(NavMeshPtr)");
    reinterpret_cast<::FUN_0040f6e0_class *>(&(((NavMesh*)apNavMesh)->debug))->FUN_0040f6e0();
    if (::g_tlsBlock.flag298)
    {
        NavMesh* mesh = apNavMesh.FUN_00458b50();
        reinterpret_cast<::FUN_00438690 *>(&(g_011de924))->FUN_007cb2e0((unsigned int *)&(mesh));
    }
    else
    {
        NavMesh* mesh = apNavMesh.FUN_00458b50();
        reinterpret_cast<::FUN_00438690 *>(&(g_011de898))->FUN_007cb2e0((unsigned int *)&(mesh));
    }
}

struct Flt
{
    operator unsigned int() const;
};
bool __cdecl HasFlags(int);
bool __cdecl BSSpinLockGlobalTryLock();
extern GlobalObject_00869db0 g_011de858;
extern bool DAT_011de958;

// @fnv 0x00868d70
void FUN_00868d70(bool abTryLock)
{
    if (DAT_011de958)
        return;
    bool bLocked = true;
    if (abTryLock)
        bLocked = ::fnv_00867f70::FUN_00867f70();
    else
        ::LockGlobalObject("GarbageCollector::ClearAll()");
    if (bLocked)
    {
        DAT_011de958 = true;
        bool bWasCollecting = ::g_tlsBlock.flag298;
        ::g_tlsBlock.flag298 = false;
        if (!HasFlags(0x10) && BSSpinLockGlobalTryLock())
        {
            reinterpret_cast<::fnv_00c5ac00::ArrObj *>(&(g_011de828))->FUN_004dffa0();
            FUN_00452530();
        }
        if (!HasFlags(8) && g_modelLoader->FUN_00868250())
        {
            unsigned int icount = reinterpret_cast<::FUN_00658930_class *>(&(g_011de808))->GetShortAtOffsetA();
            for (unsigned int i = 0; i < icount; i++)
            {
                GarbageCollectorDeleteA* pobject = g_011de808.GetAt(i);
                delete pobject;
            }
            ::FUN_005e03d0((::NiTArray_Layout *)&(g_011de808));
            reinterpret_cast<::FUN_004aaf10_shell *>((g_modelLoader))->FUN_004aaf10();
        }
        if (!HasFlags(4) && g_modelLoader->FUN_00868250())
        {
            unsigned int icount = reinterpret_cast<::FUN_00658930_class *>(&(g_011de910))->GetShortAtOffsetA();
            for (unsigned int i = 0; i < icount; i++)
            {
                GarbageCollectorDeleteB* pobject = g_011de910.GetAt(i);
                delete pobject;
            }
            ::FUN_005e03d0((::NiTArray_Layout *)&(g_011de910));
            reinterpret_cast<::FUN_004aaf10_shell *>((g_modelLoader))->FUN_004aaf10();
        }
        if (!HasFlags(2))
        {
            for (unsigned int i = 0; i < reinterpret_cast<::FUN_00658930_class *>(&(g_011de888))->GetShortAtOffsetA(); i++)
            {
                if ((const Flt&)g_011de888.GetAt(i))
                    g_011de888.GetAt(i).object->RemoveGarbageMark();
            }
            reinterpret_cast<::fnv_00c5ac00::ArrObj *>(&(g_011de888))->FUN_004dffa0();
        }
        if (!HasFlags(1) && g_modelLoader->FUN_00868250())
        {
            while (reinterpret_cast<::FUN_00658930_class *>(&((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874))))->GetShortAtOffsetA())
            {
                TESObjectREFR* pref = (*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874)).GetAt(0);
                delete pref;
            }
            ::FUN_005e03d0((::NiTArray_Layout *)(((NiTPrimitiveArray_unsigned_int_*)&(*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874)))));
            reinterpret_cast<::FUN_004aaf10_shell *>((g_modelLoader))->FUN_004aaf10();
        }
        if (!HasFlags(0x20))
        {
            for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(g_011de924))->GetName())); i++)
                g_011de924.GetAt(i)->debug.FUN_00401970();
            reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(g_011de924))->Clear(true);
        }
        ::g_tlsBlock.flag298 = bWasCollecting;
        if (::g_tlsBlock.flag298)
        {
            ::ForEachNavMesh((::GlobalObject_004aff00 *)(void *)(&(*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de8bc))), (::Caller008693c0 *)(void *)(&(*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874))));
            ::FUN_005e03d0((::NiTArray_Layout *)(((NiTPrimitiveArray_unsigned_int_*)&(*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de8bc)))));
            ::FUN_00869420((::RefList *)(void *)(&g_011de848), (::RefList *)(void *)(&g_011de888));
            reinterpret_cast<::fnv_00c5ac00::ArrObj *>(&(g_011de848))->FUN_004dffa0();
            ::ForEachNavMesh((::GlobalObject_004aff00 *)(void *)(&g_011de838), (::Caller008693c0 *)(void *)(&g_011de910));
            ::FUN_005e03d0((::NiTArray_Layout *)&(g_011de838));
            ::FUN_00869560((::Arr *)(void *)(&g_011de858), (::FUN_008693f0_Class *)(void *)(&g_011de828));
            reinterpret_cast<::fnv_00c5ac00::ArrObj *>(&(g_011de858))->FUN_004dffa0();
            ::CopyNonNullElements((::GlobalObject_00869f00 *)(void *)(&g_011de898), (::GlobalObject_00869f00 *)(void *)(&g_011de924));
            reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(g_011de898))->Clear(true);
        }
        DAT_011de958 = false;
        ::fnv_00867f80::FUN_00867f80();
    }
}

struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};

struct GlobalObject_0096a2d0
{
};


// @fnv 0x00867f50
void __cdecl LockGlobalObject(const char* apLabel)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(::g_011de8e0))->FUN_0040fbf0((char *)(apLabel));
}

namespace fnv_00867f70 {
struct RecursiveSpinLock
{
};
// @fnv 0x00867f70
bool __cdecl FUN_00867f70()
{
    return reinterpret_cast<::FUN_0078d200_cls *>(&((*reinterpret_cast<::fnv_00867f70::RecursiveSpinLock *>(&::g_011de8e0))))->FUN_0078d200();
}
}  // namespace fnv_00867f70

namespace fnv_00867f80 {
struct RecursiveSpinLock
{
};

struct GlobalObject_0096a2d0
{
    RecursiveSpinLock lock;
};


// @fnv 0x00867f80
void FUN_00867f80()
{
    reinterpret_cast<::RecursiveSpinLock *>(&((*reinterpret_cast<::fnv_00867f80::GlobalObject_0096a2d0 *>(&::g_011de8e0)).lock))->FUN_0040fba0();
}
}  // namespace fnv_00867f80

struct FUN_00868210_shell
{
    int m_00;
    unsigned char m_04;
    void ClearBitsAndUnlockGC();
};

extern int DAT_011de804;

// If m_04 is zero, clears the bits of m_00 in DAT_011de804, then unlocks the garbage collector.
// @fnv 0x00868210
void FUN_00868210_shell::ClearBitsAndUnlockGC()
{
    if (m_04 == 0)
    {
        DAT_011de804 = ~m_00 & DAT_011de804;
    }
    ::fnv_00867f80::FUN_00867f80();
}

void __cdecl FUN_00868770(int* a, int b);

struct FUN_00868740_shell
{
    void FUN_00868740();
};

// @fnv 0x00868740
void FUN_00868740_shell::FUN_00868740()
{
    FUN_00868770(reinterpret_cast<int*>(this) + 1, *(reinterpret_cast<int*>(this) + 1) | 0x40000000);
}

struct FUN_008681c0_shell
{
    int m_00;
    unsigned char m_04;
    FUN_008681c0_shell* InitFlags(int, const char*);
};
// Stores a in m_00, locks the garbage collector with b, sets m_04 from the overlap of DAT_011de804 and a, then ORs a into DAT_011de804.
// @fnv 0x008681c0
FUN_008681c0_shell* FUN_008681c0_shell::InitFlags(int aiFlags, const char* apName)
{
    m_00 = aiFlags;
    ::LockGlobalObject(apName);
    m_04 = (DAT_011de804 & aiFlags) != 0;
    DAT_011de804 |= aiFlags;
    return this;
}

struct S_00868ce0
{
    int m_00;
    int m_04;
    void FUN_00868ce0();
};
// @fnv 0x00868850
void GarbageCollector::Update()
{
    ::LockGlobalObject(kGarbageCollectorUpdateLabel);
    struct QueueBudget
    {
        unsigned int multiplier;
        unsigned int size;
        unsigned int remaining;
    } budget;
    budget.size = 0;
    budget.remaining = 0;
    budget.multiplier = 1;
    if (reinterpret_cast<::FUN_00878360_Class *>((FUN_00446ef0()))->FUN_00878360())
        budget.multiplier = 2;
    if (reinterpret_cast<::FUN_00658930_class *>(&(g_011de808))->GetShortAtOffsetA())
    {
        if (g_modelLoader->FUN_00868250())
        {
            budget.size = reinterpret_cast<::FUN_00658930_class *>(&(g_011de808))->GetShortAtOffsetA();
            budget.remaining = budget.multiplier * 10;
            while (budget.size && budget.remaining)
            {
                --budget.size;
                --budget.remaining;
                GarbageCollectorDeleteA* object = g_011de808.GetAt(budget.size);
                reinterpret_cast<::PtrArrayView *>(&(g_011de808))->FUN_009e98d0(budget.size);
                delete object;
            }
            reinterpret_cast<::FUN_004aaf10_shell *>((g_modelLoader))->FUN_004aaf10();
        }
    }
    else if (reinterpret_cast<::FUN_00658930_class *>(&(g_011de910))->GetShortAtOffsetA())
    {
        if (g_modelLoader->FUN_00868250())
        {
            budget.size = reinterpret_cast<::FUN_00658930_class *>(&(g_011de910))->GetShortAtOffsetA();
            budget.remaining = budget.multiplier * 10;
            while (budget.size && budget.remaining)
            {
                --budget.size;
                --budget.remaining;
                GarbageCollectorDeleteB* object = g_011de910.GetAt(budget.size);
                reinterpret_cast<::PtrArrayView *>(&(g_011de910))->FUN_009e98d0(budget.size);
                delete object;
            }
            reinterpret_cast<::FUN_004aaf10_shell *>((g_modelLoader))->FUN_004aaf10();
        }
    }
    else if (reinterpret_cast<::FUN_00658930_class *>(&(g_011de838))->GetShortAtOffsetA())
    {
        ::ForEachNavMesh((::GlobalObject_004aff00 *)(void *)(&g_011de838), (::Caller008693c0 *)(void *)(&g_011de910));
        ::FUN_005e03d0((::NiTArray_Layout *)&(g_011de838));
    }
    else if (reinterpret_cast<::FUN_00658930_class *>(&(g_011de888))->GetShortAtOffsetA())
    {
        budget.size = reinterpret_cast<::FUN_00658930_class *>(&(g_011de888))->GetShortAtOffsetA();
        budget.remaining = budget.multiplier * 10;
        while (budget.size && budget.remaining)
        {
            --budget.size;
            --budget.remaining;
            GarbageCollectorObjectPtr object = g_011de888.RemoveAt(budget.size);
            if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)&(object))->operator!=(0))
                reinterpret_cast<::S_00868ce0 *>((object.object))->FUN_00868ce0();
        }
    }
    else if (reinterpret_cast<::FUN_00658930_class *>(&(g_011de848))->GetShortAtOffsetA())
    {
        ::FUN_00869420((::RefList *)(void *)(&g_011de848), (::RefList *)(void *)(&g_011de888));
        reinterpret_cast<::fnv_00c5ac00::ArrObj *>(&(g_011de848))->FUN_004dffa0();
    }
    else if (reinterpret_cast<::FUN_00658930_class *>(&((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874))))->GetShortAtOffsetA())
    {
        if (g_modelLoader->FUN_00868250())
        {
            budget.size = reinterpret_cast<::FUN_00658930_class *>(&((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874))))->GetShortAtOffsetA();
            budget.remaining = budget.multiplier * 20;
            unsigned int special = 1;
            while (budget.size && budget.remaining && special)
            {
                --budget.size;
                --budget.remaining;
                TESObjectREFR* object = (*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874)).GetAt(0);
                if (object->vfn_100() || reinterpret_cast<::fnv_00564d80::ArrSI *>((object))->FUN_00564d80())
                    --special;
                delete object;
            }
            reinterpret_cast<::FUN_004aaf10_shell *>((g_modelLoader))->FUN_004aaf10();
        }
    }
    else if (reinterpret_cast<::FUN_00658930_class *>(&((*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de8bc))))->GetShortAtOffsetA())
    {
        ::ForEachNavMesh((::GlobalObject_004aff00 *)(void *)(&(*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de8bc))), (::Caller008693c0 *)(void *)(&(*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de874))));
        ::FUN_005e03d0((::NiTArray_Layout *)(reinterpret_cast<NiTPrimitiveArray_unsigned_int_*>(&(*reinterpret_cast<::NiTObjectArray< ::TESObjectREFR *> *>(&::g_011de8bc)))));
    }
    else if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(g_011de924))->GetName())))
    {
        budget.size = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(g_011de924))->GetName()));
        budget.remaining = budget.multiplier * 5;
        while (budget.size && budget.remaining)
        {
            --budget.size;
            --budget.remaining;
            g_011de924.GetAt(0)->debug.FUN_00401970();
            reinterpret_cast<::FUN_006bf8f0_Class *>(&(g_011de924))->FUN_006bf8f0(0, true);
        }
    }
    else if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(g_011de898))->GetName())))
    {
        ::CopyNonNullElements((::GlobalObject_00869f00 *)(void *)(&g_011de898), (::GlobalObject_00869f00 *)(void *)(&g_011de924));
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(g_011de898))->Clear(true);
    }
    ::fnv_00867f80::FUN_00867f80();
}
// Clears bit 30 of m_04 and passes the result to FUN_00868770 along with the address of m_04.
// @fnv 0x00868ce0
void S_00868ce0::FUN_00868ce0()
{
    FUN_00868770(&m_04, m_04 & 0xBFFFFFFF);
}

struct FUN_008693c0_shell
{
    unsigned char _00[10];
    unsigned short m_0A;
    void FUN_008693c0(std::intptr_t a);
};
// Forwards the value to FUN_00869640 together with the field at offset 0x0A.
// @fnv 0x008693c0
void FUN_008693c0_shell::FUN_008693c0(std::intptr_t aiValue)
{
    reinterpret_cast<::FUN_00869640_StrArr *>(this)->FUN_00869640(m_0A, (*(char * *)(aiValue)));
}

struct Caller008693c0
{
};
// Iterates over apArray's elements, and for each non-null NavMesh calls apObj->FUN_008693c0 with a pointer to it.
// @fnv 0x008694c0
void __cdecl ForEachNavMesh(GlobalObject_004aff00* apArray, Caller008693c0* apObj)
{
    unsigned int i;
    for (i = 0; i < reinterpret_cast<::FUN_00658930_class *>((apArray))->GetShortAtOffsetA(); i++)
    {
        NavMesh* cur;
        cur = ((GlobalObject_00869f00*)apArray)->GetAt(i);
        if (cur != 0)
        {
            reinterpret_cast<::FUN_008693c0_shell *>((apObj))->FUN_008693c0((int)(&cur));
        }
    }
}

struct ProxyArray
{
};
// Iterates over a's elements, retrieves each NavMesh via FUN_006a7ad0, and adds the non-null ones to b.
// @fnv 0x00869510
void CopyNonNullElements(GlobalObject_00869f00* apSource, GlobalObject_00869f00* apDest)
{
    unsigned int i;
    for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apSource))->GetName())); i++)
    {
        NavMesh* v;
        v = ((::NavMesh *)(reinterpret_cast<::S3e60 *>((((ProxyArray*)apSource)))->FUN_006a7ad0(i)));
        if (v)
            reinterpret_cast<::FUN_00438690 *>((apDest))->FUN_007cb2e0((unsigned int *)&(v));
    }
}

struct FUN_0050f5a0_struct
{
    void FUN_0050f5a0();
};
struct FUN_00572160_shell
{
    void FUN_00572160();
};
// @fnv 0x00572160
void FUN_00572160_shell::FUN_00572160()
{
    unsigned int i;
    unsigned int count = reinterpret_cast<::FUN_00658930_class *>((((GlobalObject_004aff00*)((char*)this + 0x9c))))->GetShortAtOffsetA();
    for (i = 0; i < count; ++i)
    {
        unsigned int effect = (Flt&)((GlobalObject_00869f00*)((char*)this + 0x9c))->GetAt(i);
        if (effect)
            ((FUN_0050f5a0_struct*)effect)->FUN_0050f5a0();
    }
    reinterpret_cast<::fnv_00c5ac00::ArrObj *>((((GlobalObject_004aff00*)((char*)this + 0x9c))))->FUN_004dffa0();
}

// @fnv 0x00868770
void __cdecl FUN_00868770(int* a, int b)
{
    (*reinterpret_cast<void (**)(void *, void *)>(&::DAT_00fdf0e4))(a, (void*)b);
}

struct GO
{
    int m_00;
    GO(int);
    ~GO();
};
struct FUN_008693f0_Class
{
    void FUN_008693f0(int);
};
// Constructs a GO from ai and passes it to FUN_008693f0 on g_011de828 or g_011de858 depending on DAT_tlsFlag.
// @fnv 0x00868490
void __cdecl FUN_00868490(int aiEffect)
{
    TwoPointerRecord e(0x10, "GarbageCollector::Add(BSTempEffect)");
    if (::g_tlsBlock.flag298)
    {
        GO p(aiEffect);
        ((FUN_008693f0_Class*)&g_011de828)->FUN_008693f0((int)&p);
    }
    else
    {
        GO p(aiEffect);
        ((FUN_008693f0_Class*)&g_011de858)->FUN_008693f0((int)&p);
    }
}

struct BGSSaveLoadGame
{
};


// @fnv 0x00868560
void __cdecl FUN_00868560(GarbageCollectorDeleteB* apObject)
{
    TwoPointerRecord autoEvent(4, "GarbageCollector::Add(BipedAnim)");

    if (!::g_tlsBlock.flag298 || (g_BGSSaveLoadGame != 0 && reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((g_BGSSaveLoadGame))->FUN_0042ce10()))
    {
        if (g_modelLoader->FUN_00868250())
        {
            delete apObject;
            reinterpret_cast<::FUN_004aaf10_shell *>((g_modelLoader))->FUN_004aaf10();
        }
        else
        {
            reinterpret_cast<FUN_008693c0_shell*>(&g_011de838)->FUN_008693c0(reinterpret_cast<int>(&apObject));
        }
    }
    else
    {
        reinterpret_cast<FUN_008693c0_shell*>(&g_011de910)->FUN_008693c0(reinterpret_cast<int>(&apObject));
    }
}

extern GlobalObject_004aff00 g_011de848;
extern GlobalObject_004aff00 g_011de888;

template <> class NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >
{
  public:
    unsigned int Add(const NiPointer<NiAVObject>& object);
};

// Calls FUN_00868740 on apObject if non-null, then adds it to one of two global NiTArray lists depending on bCollecting.
// @fnv 0x00868660
void FUN_00868660(NiAVObject* apObject)
{
    TwoPointerRecord autoEvent(2, "GarbageCollector::Add(NiAVObject)");

    if (apObject)
    {
        reinterpret_cast<FUN_00868740_shell*>(apObject)->FUN_00868740();
    }

    if (::g_tlsBlock.flag298)
    {
        GO object(reinterpret_cast<int>(apObject));
        reinterpret_cast<NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >*>(&g_011de888)
            ->Add(reinterpret_cast<const NiPointer<NiAVObject>&>(object));
    }
    else
    {
        GO object(reinterpret_cast<int>(apObject));
        reinterpret_cast<NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >*>(&g_011de848)
            ->Add(reinterpret_cast<const NiPointer<NiAVObject>&>(object));
    }
}

struct AnimationManager
{
};
struct TimeController
{
};
struct SceneObject
{
};
struct AnimationObject
{
};
struct AnimationLoader
{
};
struct AnimationQueue
{
};
// @fnv 0x00868330
void AddAnimationToGarbageCollector(AnimationObject* object)
{
    TwoPointerRecord event(8, "GarbageCollector::Add(Animation)");
    reinterpret_cast<::Animation *>((object))->FUN_0048ff50();
    if (((::AnimationManager *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((object))->FUN_00496940())))
        reinterpret_cast<::NiControllerManager *>((((::AnimationManager *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((object))->FUN_00496940()))))->DeactivateAllSequences(0.0f);
    SceneObject* pRoot = ((::SceneObject *)(reinterpret_cast<::TESRegionDataMap *>((object))->GetRegionMapName()));
    if (pRoot)
    {
        TimeController* controller = ((::TimeController *)(reinterpret_cast<::MyHost *>((pRoot))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f36bc))))));
        if (controller)
            reinterpret_cast<::ControllerOwner *>((pRoot))->FUN_00a5c480((::NiTimeController *)(controller));
        controller = ((::TimeController *)(reinterpret_cast<::MyHost *>((pRoot))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f36e4))))));
        if (controller)
            reinterpret_cast<::ControllerOwner *>((pRoot))->FUN_00a5c480((::NiTimeController *)(controller));
    }
    reinterpret_cast<::FUN_00445430_cls *>((((AnimationLoader*)g_modelLoader)))->FUN_00445430((unsigned int)(object));
    if (!::g_tlsBlock.flag298 || (g_BGSSaveLoadGame && reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((g_BGSSaveLoadGame))->FUN_0042ce10()))
    {
        delete (GarbageCollectorDeleteA*)object;
    }
    else
    {
        reinterpret_cast<::FUN_008693c0_shell *>((((AnimationQueue*)&g_011de808)))->FUN_008693c0((int)(&object));
    }
}

#include "generated/data/fallout/misc/garbagecollector.inc"
