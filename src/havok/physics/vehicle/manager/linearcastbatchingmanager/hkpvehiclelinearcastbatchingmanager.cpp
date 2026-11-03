
// src/havok/physics/vehicle/manager/linearcastbatchingmanager/hkpvehiclelinearcastbatchingmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/manager/linearcastbatchingmanager/hkpvehiclelinearcastbatchingmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"

#include <windows.h>
#include "fnv/decl/VUC_StepInstance.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkpVehicleLinearCastBatchingManager.h"

struct FUN_00e42fe0
{
    int GetCount();
};

struct FUN_00e43060
{
    void DoWork(int a, int b, int* out);
};

struct FUN_00e43010
{
    int ConvertReferences(int numVehicles);
};
struct FUN_00e42fe0_counted
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual int GetCount() = 0;
};

struct FUN_00e42fe0_vehicle
{
    unsigned char pad[0x3c];
    FUN_00e42fe0_counted* counted;
};

struct FUN_00e42fe0_impl
{
    virtual void f00() = 0;
    void* field04;
    FUN_00e42fe0_vehicle** vehicles;
    int count;

    int FUN_00e42fe0();
};
// Computes four aligned offsets from GetCount() and the 16-bit count at this+0x14, writes them to out, and advances a by each padding.
// @fnv 0x00e43060
void FUN_00e43060::DoWork(int iBaseOffset, int iUnused, int* paiOffsets)
{
    int iCount = reinterpret_cast<::FUN_00e42fe0_impl *>((((FUN_00e42fe0*)this)))->FUN_00e42fe0();
    unsigned int n = *(unsigned short*)((char*)this + 0x14);
    unsigned int pad = ((unsigned int)(n * 5) << 4) + 0xf;
    pad &= 0xfffffff0u;
    paiOffsets[0] = iBaseOffset;
    iBaseOffset += pad;
    unsigned int pad2 = ((unsigned int)iCount * 0x70) + 0xf;
    pad2 &= 0xfffffff0u;
    unsigned int pad3 = ((unsigned int)iCount << 6) + 0xf;
    pad3 &= 0xfffffff0u;
    paiOffsets[1] = iBaseOffset;
    iBaseOffset += pad3;
    paiOffsets[2] = iBaseOffset;
    iBaseOffset += pad2;
    paiOffsets[3] = iBaseOffset;
}
// Computes a 16-byte-aligned total from the object's count, a 16-bit field at offset 0x14, the count again, and numVehicles.
// @fnv 0x00e43010
int FUN_00e43010::ConvertReferences(int numVehicles)
{
    int count = reinterpret_cast<::FUN_00e42fe0_impl *>((((FUN_00e42fe0*)this)))->FUN_00e42fe0();
    unsigned int a = (unsigned int)(unsigned short)*(unsigned short*)((char*)this + 0x14);
    int iTotal = ((a * 5) << 4) + 0xf;
    iTotal &= 0xfffffff0;
    int iCountSize = count * 0x70 + 0xf;
    iCountSize &= 0xfffffff0;
    iTotal += iCountSize;
    int iCountSize2 = (count << 6) + 0xf;
    iCountSize2 &= 0xfffffff0;
    iTotal += iCountSize2;
    int iVehicleSize = (numVehicles << 4) + 0xf;
    iVehicleSize &= 0xfffffff0;
    iTotal += iVehicleSize;
    return iTotal;
}

// Sums GetCount() over all vehicles in the array and returns the total.
// @fnv 0x00e42fe0
int FUN_00e42fe0_impl::FUN_00e42fe0()
{
    int total = 0;
    for (int i = 0; i < count; ++i)
        total += vehicles[i]->counted->GetCount();
    return total;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
typedef unsigned long DWORD;


struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

struct AllocV;
struct CharacterBufferState
{
    char* m_pCur;
    DWORD unk04, unk08, unk0c;
    AllocV* m_pSharedOwner;
    AllocV& heap()
    {
        return *m_pSharedOwner;
    }
};



struct AllocV
{
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void Free(void* p, unsigned int size);
};

struct HkArr
{
    char* m_data;
    int m_iElementCount;
    int m_cap;
    int getCapacity() const
    {
        return m_cap & 0x3fffffff;
    }
    void reserve(AllocV& a, int n);
    void SetSizeAndGrow(AllocV& a, int n)
    {
        reserve(a, n);
        m_iElementCount = n;
    }
};


inline void HkArr::reserve(AllocV& a, int n)
{
    if (getCapacity() < n)
    {
        int cap2 = 2 * getCapacity();
        int newSize = (n < cap2) ? cap2 : n;
        ::FUN_00c908c0((::SpawnedObject *)&(a), (::SpawnedArray *)(void *)(this), newSize, 0x60);
    }
}

struct Counted433
{
    virtual void u00();
    virtual void u01();
    virtual void u02();
    virtual void u03();
    virtual void u04();
    virtual void u05();
    virtual void u06();
    virtual void u07();
    virtual void u08();
    virtual void u09();
    virtual void u10();
    virtual void M11(void* veh, unsigned char j, char* elem);
    virtual void u12();
    virtual int M13(unsigned char j);
    virtual void u14();
    virtual int M15(unsigned char j, void* ptr);
    virtual void u16();
    virtual void M17(void* veh, unsigned char j, int res, char* elem);
    virtual void M18(void* veh, unsigned char j, char* elem);
};

struct VehData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned char m_iWheelCount;
};

struct Vehicle433
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    VehData* m_data1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    Counted433* m_counted;
};

static __forceinline void S00e43320_timerB(const char* name, volatile DWORD& tick)
{
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    ProfRec* pRec = pBuf->m_pCur;
    if (pRec < pBuf->m_pRecordEnd)
    {
        pRec->m_pName = name;
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }
}

static __forceinline void S00e43320_timer(const char* name)
{
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    ProfRec* pRec = pBuf->m_pCur;
    if (pRec < pBuf->m_pRecordEnd)
    {
        pRec->m_pName = name;
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }
}

struct Slot433
{
    HkArr m_aiIndexedValues;
    char* m_saved;
};

struct Out433
{
    int m_00;
    char* m_04;
    int m_08;
    int m_0c;
};

struct S00e43320_Mgr
{
    void* vtbl;
    int unk04;
    Vehicle433** m_ppVehicles;
    int m_uiItemCount;
    void FUN_00e43060(void* a, void* b, Out433* out);
    void FUN_00e43320(void* param1, void* param2, void* param3);
};

// Iterates over m_ppVehicles, gathers per-wheel data via Counted433, and calls FUN_00e39030 on each vehicle with the collected array.
// @fnv 0x00e43320
void S00e43320_Mgr::FUN_00e43320(void* param1, void* param2, void* param3)
{
    int i;
    {
        ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
        ProfRec* pRec = pBuf->m_pCur;
        if (pRec < pBuf->m_pRecordEnd)
        {
            pRec->m_pName = "TtDoVehicles";
            _ReadWriteBarrier();
            *(volatile unsigned*)&i = (unsigned)__rdtsc();
            pRec->m_iTick = *(volatile unsigned*)&i;
            pBuf->m_pCur = pRec + 1;
        }
    }
    Out433 out;
    S00e43320_Mgr* self = this;
    int count = self->m_uiItemCount;
    reinterpret_cast<::FUN_00e43060 *>(this)->DoWork((int)(param3), (int)(param2), (int *)(::Out433 *)(&out));
    char* savedVal = out.m_04;
    Slot433 slot;
    HkArr& arr = slot.m_aiIndexedValues;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_cap = (int)0x80000000;
    CharacterBufferState* ar = static_cast<CharacterBufferState*>(::FUN_00c85750());
    char* scratch = ar->m_pCur;
    ar->m_pCur = (char*)scratch + 0x600;
    arr.m_data = scratch;
    arr.m_cap = (int)0x80000010;
    slot.m_saved = scratch;
    {
        for (i = 0; i < count; i++)
        {
            Vehicle433* veh = self->m_ppVehicles[i];
            int numWheels = veh->m_data1c->m_iWheelCount;
            arr.SetSizeAndGrow(static_cast<CharacterBufferState*>(::FUN_00c85750())->heap(), numWheels);
            Counted433* counted = veh->m_counted;
            unsigned char j = 0;
            if (numWheels > 0)
            {
                for (; j < numWheels; j++)
                {
                    int res = counted->M15(j, savedVal);
                    if (res)
                        counted->M17(veh, j, res, arr.m_data + j * 96);
                    else
                        counted->M18(veh, j, arr.m_data + j * 96);
                    counted->M11(veh, j, arr.m_data + j * 96);
                    savedVal += counted->M13(j) * 64;
                }
            }
            reinterpret_cast<::VUC_StepInstance *>((self->m_ppVehicles[i]))->FUN_00e39030((*(const ::VUC_StepInfo *)(param1)), arr.m_data);
        }
    }
    S00e43320_timer("Et");
    char* saved = slot.m_saved;
    if (saved == arr.m_data)
        arr.m_iElementCount = 0;
    static_cast<CharacterBufferState*>(::FUN_00c85750())->m_pCur = saved;
    {
        CharacterBufferState* ar5 = static_cast<CharacterBufferState*>(::FUN_00c85750());
        AllocV* alloc = ar5->m_pSharedOwner;
        int cap = arr.m_cap;
        arr.m_iElementCount = 0;
        if (!(cap & (int)0x80000000))
            alloc->Free(arr.m_data, (cap & 0x3fffffff) * 96);
    }
}

// Moved from hkpvehiclelinearcastbatchingmanager_ctx_variant.cpp (VEGAS-15).

// hkpvehiclelinearcastbatchingmanager_ctx_variant.cpp: context variant of src/havok/physics/vehicle/manager/linearcastbatchingmanager/hkpvehiclelinearcastbatchingmanager.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/havok/physics/vehicle/manager/linearcastbatchingmanager/hkpvehiclelinearcastbatchingmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/manager/linearcastbatchingmanager/hkpvehiclelinearcastbatchingmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <intrin.h>
#include "fnv/decl/D04B90World.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00d05000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_0104d000.h"

struct E430B0Coll
{
	int unk00;
	int unk04;
	int unk08;
	int unk0c;
	int unk10;
	int unk14;
	int unk18;
	int unk1c;
	int unk20;
	int unk24;
	int unk28;
	int unk2c;
	int unk30;
	int unk34;
	int unk38;
	int unk3c;
	int unk40;
	int unk44;
	int unk48;
	int unk4c;
};
struct E430B0Cmd
{
	int unk00;
	int unk04;
	int unk08;
	int unk0c;
	int unk10;
	int unk14;
	int unk18;
	int unk1c;
	int unk20;
	int unk24;
	int unk28;
	int unk2c;
	int unk30;
	int unk34;
	int unk38;
	int unk3c;
};
struct E430B0Out
{
	int unk00;
	int unk04;
	int unk08;
	int unk0c;
	int unk10;
	int unk14;
	int unk18;
	int unk1c;
	int unk20;
	int unk24;
	int unk28;
	int unk2c;
	int unk30;
	int unk34;
	int unk38;
	int unk3c;
	int unk40;
	int unk44;
	int unk48;
	int unk4c;
	int unk50;
	int unk54;
	int unk58;
	int unk5c;
	int unk60;
	int unk64;
	int unk68;
	int unk6c;
};

struct E430B0Hdr { int numTasks; int unk04; int unk08; int unk0c; };

struct E430B0Mon
{
	void* start;
	char* end;
	void* capacity;
	char* limit;
};

struct E430B0VehicleData
{
	int unk00;
	int unk04;
	int unk08;
	int unk0c;
	int unk10;
	int unk14;
	int unk18;
	int unk1c;
	unsigned char numWheels;
};

struct E430B0Wheel
{
	virtual void v00() = 0;
	virtual void v01() = 0;
	virtual void v02() = 0;
	virtual void v03() = 0;
	virtual void v04() = 0;
	virtual void v05() = 0;
	virtual void v06() = 0;
	virtual void v07() = 0;
	virtual void v08() = 0;
	virtual void v09() = 0;
	virtual void v0a() = 0;
	virtual void v0b() = 0;
	virtual void v0c() = 0;
	virtual void v0d() = 0;
	virtual int PerformWheelRaycast(void* vehicle, void* filter, E430B0Coll* collidable, E430B0Cmd* command, E430B0Out* output) = 0;
};

struct E430B0Vehicle
{
	int unk00;
	int unk04;
	int unk08;
	int unk0c;
	int unk10;
	int unk14;
	int unk18;
	E430B0VehicleData* data;
	int unk20;
	int unk24;
	int unk28;
	int unk2c;
	int unk30;
	int unk34;
	int unk38;
	E430B0Wheel* wheelCollide;
};

struct E430B0World
{
	int unk00, unk04, unk08, unk0c;
	int unk10, unk14, unk18, unk1c;
	int unk20, unk24, unk28, unk2c;
	int unk30, unk34, unk38, unk3c;
	int unk40, unk44, unk48, unk4c;
	int unk50, unk54, unk58, unk5c;
	int unk60, unk64, unk68, unk6c;
	int unk70, unk74;
	void* collisionInput;
	void* collisionFilter;
};


struct E430B0Batch
{
	E430B0Coll* collidable;
	E430B0Cmd* command;
	E430B0Out* output;
	E430B0Hdr* headers;
};

struct E430B0BaseJob
{
	unsigned char subType;
	unsigned char jobType;
	unsigned char spuType;
	unsigned char unk03;
	unsigned short size;
	short affinity;

	E430B0BaseJob(unsigned char t, unsigned char st, unsigned short sz)
	{
		subType = st;
		jobType = t;
		spuType = 2;
		size = sz;
		affinity = -1;
	}
};

struct E430B0QueryJob : public E430B0BaseJob
{
	int unk08;
	int unk0c;
	void* semaphore;
	E430B0Hdr* header;
	void* collisionInput;
	int* jobDoneFlag;

	E430B0QueryJob(unsigned char st, unsigned short sz) : E430B0BaseJob(2, st, sz)
	{
		jobDoneFlag = 0;
	}
};

__declspec(align(16)) struct E430B0Job : public E430B0QueryJob
{
	float tolerance;
	float maxExtraPenetration;
	float earlyOutDistance;
	int maxIterations;
	int numCommandsPerTask;
	E430B0Cmd* commandArray;
	int numCommands;
	int unk3c;

	E430B0Job(void* input, E430B0Hdr* jobHeader, E430B0Cmd* cmds, int n, void* sem, int perTask)
		: E430B0QueryJob(3, 0x40)
	{
		tolerance = 0.0f;
		maxExtraPenetration = ::DAT_0104da4c;
		earlyOutDistance = 0.01f;
		collisionInput = input;
		semaphore = sem;
		commandArray = cmds;
		header = jobHeader;
		numCommandsPerTask = perTask;
		numCommands = n;
		maxIterations = 10;
		header->numTasks = (n - 1) / perTask + 1;
	}
};

struct FUN_00d05db0_class
{
};

struct FUN_00d04b90_class
{
};

struct E430B0Mgr
{
	int unk00;
	int unk04;
	E430B0Vehicle** vehicles;
	int count;

	int FUN_00e430b0(E430B0World* world, int filterSize, int numJobs, FUN_00d04b90_class* jobQueue, void* semaphore, void* buffer);
};

static inline void E430B0Timer(E430B0Mon* mon, const char* name)
{
	char* cur = mon->end;
	if (cur < mon->limit)
	{
		*(const char**)cur = name;
		unsigned int stamp;
		stamp = static_cast<unsigned int>(__rdtsc());
		*(unsigned int*)(cur + 4) = stamp;
		mon->end = cur + 12;
	}
}

// @fnv 0x00e430b0
int E430B0Mgr::FUN_00e430b0(E430B0World* world, int filterSize, int numJobs, FUN_00d04b90_class* jobQueue, void* semaphore, void* buffer)
{

	E430B0Timer((E430B0Mon*)TlsGetValue(DAT_0126835c), "TtBuildAndAddLinearCastJobs");

	void* filter = world->collisionFilter;
	int vehicleCount = count;
	const int& countRef = vehicleCount;
	E430B0Batch batch;
	((FUN_00e43060*)this)->DoWork((int)buffer, numJobs, (int*)&batch);

	int total = 0;
	E430B0Timer((E430B0Mon*)TlsGetValue(DAT_0126835c), "TtBuildCommands");

	E430B0Coll* collidable = batch.collidable;
	E430B0Cmd* command = batch.command;
	E430B0Out* output = batch.output;
	for (int i = 0; i < countRef; ++i)
	{
		E430B0Vehicle* vehicle = vehicles[i];
		int n = vehicle->wheelCollide->PerformWheelRaycast(vehicle, filter, collidable, command, output);
		collidable += vehicle->data->numWheels;
		total += n;
		command += n;
		output += n;
	}

	E430B0Timer((E430B0Mon*)TlsGetValue(DAT_0126835c), "Et");

	if (numJobs >= total)
	{
		numJobs = total;
	}
	int perJob = total / numJobs;
	int rem = total % numJobs;

	E430B0Cmd* cmdPtr = batch.command;
	E430B0Hdr* header = batch.headers;
	for (int j = 0; j < numJobs; ++j)
	{
		int n = perJob + (j < rem);
		E430B0Job job(world->collisionInput, header, cmdPtr, n, semaphore, 128);
		::FUN_00d05db0();
		reinterpret_cast<::D04B90World *>((jobQueue))->AddObjectCopy((const ::D04B90Object *)(void *)(&job), (void *)(1));
		cmdPtr += n;
		header++;
	}

	E430B0Timer((E430B0Mon*)TlsGetValue(DAT_0126835c), "Et");
	return numJobs;
}
