
// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/FUN_006212c0_shell.h"
#include "fnv/decl/FUN_00c7f690_cls.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00c936a0_World.h"
#include "fnv/decl/FUN_00cd2d80.h"
#include "fnv/decl/PhRemoveListener.h"
#include "fnv/decl/PhantomBounds.h"
#include "fnv/decl/PhantomS.h"
#include "fnv/decl/WorldC92C.h"
#include "fnv/decl/hkOwnerXd07de0.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00e36000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010c4000.h"
#include "havok/hkpVehicleLinearCastWheelCollide.h"
#include "havok/hkpVehicleLinearCastWheelCollideWheelState.h"
#include "havok/hkpWorldObject.h"

struct LCHitObj
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    float m_fHitDistance;
};
struct LCHit
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    LCHitObj* m_obj;
    int m_2c;
    int m_valid;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
};
struct LCWheelCollideStandIn
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int getNumHits(int);
    LCHitObj* FUN_00e36250(int iWheel, LCHit* pHits);
};

// @fnv 0x00e36250
LCHitObj* LCWheelCollideStandIn::FUN_00e36250(int iWheel, LCHit* pHits)
{
    int numHits = getNumHits(iWheel);
    LCHitObj* nearest = 0;
    for (int i = 0; i < numHits; i++)
    {
        const LCHit& rHit = pHits[i];
        if (rHit.m_valid)
        {
            LCHitObj* pHitObj = rHit.m_obj;
            if (!nearest || pHitObj->m_fHitDistance < nearest->m_fHitDistance)
                nearest = pHitObj;
        }
    }
    return nearest;
}

struct FUN_00e363a0_Wheel
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    char pad04[0xcc];
    void* m_overlappingCollidablesData;  // +0xd0, hkpAabbPhantom::m_overlappingCollidables
    int m_overlappingCollidablesSize;    // +0xd4
};

struct FUN_00e363a0_StandIn : LCWheelCollideStandIn
{
    unsigned int FUN_00e363a0(unsigned char wheelIndex);
};

// Calls the virtual function at vtable offset 0x28 on the phantom of wheel wheelIndex and returns the size of its overlapping-collidables array.
// @fnv 0x00e363a0
unsigned int FUN_00e363a0_StandIn::FUN_00e363a0(unsigned char wheelIndex)
{
    const hkpVehicleLinearCastWheelCollide* self = reinterpret_cast<const hkpVehicleLinearCastWheelCollide*>(this);
    FUN_00e363a0_Wheel* wheel = reinterpret_cast<FUN_00e363a0_Wheel*>(self->m_kWheelStates.m_data[wheelIndex].m_pPhantom);
    wheel->v28();
    return (unsigned int)wheel->m_overlappingCollidablesSize;
}

struct FUN_00c936a0_host
{
};

struct COMBaseInterface : public FUN_00c936a0_host
{
};

struct FUN_00e36870_host : hkpVehicleLinearCastWheelCollide
{
    void FUN_00e36870(COMBaseInterface*);
};

// Iterates the wheel states and passes each state's first dword to p->FUN_00c936a0.
// @fnv 0x00e36870
void FUN_00e36870_host::FUN_00e36870(COMBaseInterface* apHost)
{
    int count = m_kWheelStates.m_iElementCount;

    if (count > 0)
    {
        for (int i = 0; i < count; ++i)
        {
            void* value = m_kWheelStates.m_data[i].m_pPhantom;
            reinterpret_cast<::FUN_00c936a0_World *>((apHost))->FUN_00c936a0((::hkpPhantom *)(value));
        }
    }
}

struct FUN_00c92c70_Class
{
};

struct FUN_00e368a0_Class : hkpVehicleLinearCastWheelCollide
{
    void FUN_00e368a0();
};
// Iterates the wheel states, calling FUN_00c92c70 on each phantom's world.
// @fnv 0x00e368a0
void FUN_00e368a0_Class::FUN_00e368a0()
{
    int count = m_kWheelStates.m_iElementCount;
    if (count > 0)
    {
        hkpVehicleLinearCastWheelCollideWheelState* state = m_kWheelStates.m_data;
        do
        {
            hkpWorldObject* p = (hkpWorldObject*)state->m_pPhantom;
            FUN_00c92c70_Class* q = (FUN_00c92c70_Class*)p->m_pOwningWorld;
            reinterpret_cast<::WorldC92C *>((q))->FUN_00c92c70((::ActionC92C *)(p));
            ++state;
            count--;
        } while (count != 0);
    }
}

struct FUN_00e368d0_Target
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* m_2c;
};

struct FUN_00e368d0_Elem
{
    FUN_00e368d0_Target* m_00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

struct FUN_00e368d0_Class
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
    FUN_00e368d0_Elem* m_10;
    int m_14;

    void SetTargetArg(void* arg);
};

// Stores arg in m_0c and, for each of m_14 elements, writes arg into the element's target m_2c when the target is non-null.
// @fnv 0x00e368d0
void FUN_00e368d0_Class::SetTargetArg(void* arg)
{
    int count = m_14;
    m_0c = arg;
    for (int i = 0; i < count; i++)
    {
        FUN_00e368d0_Target* t = m_10[i].m_00;
        if (t != 0)
        {
            t->m_2c = arg;
        }
    }
}

void __cdecl FUN_00e36900();
// @fnv 0x00e36aa0
void __cdecl FUN_00e36aa0()
{
    FUN_00e36900();
}

inline hkBaseObject::~hkBaseObject()
{}

struct FUN_00d1df70
{
    virtual void v00() throw();
};

struct DummyBase1
{
    int a, b;
};

struct hkpPhantomOverlapListener
{
    int dummy;
};

struct FUN_00e360f0 : public DummyBase1, public hkpPhantomOverlapListener
{
    int d;
    ~FUN_00e360f0() throw();
};

class hkpPhantom : public FUN_00d1df70
{
  public:
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

struct WheelState
{
    hkpPhantom* m_pPhantom;
    FUN_00d1df70* m_pCollisionShape;
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
};


struct WheelStatesArray
{
    WheelState* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    inline ~WheelStatesArray() throw()
    {
        hkMemoryRouter* mem = &hkMemoryRouter::getInstance();
        hkMemoryAllocator* router = mem->m_heap;
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if (!(cap & 0x80000000))
        {
            router->bufFree(this->m_data, (cap & 0x3fffffff) * sizeof(WheelState));
        }
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }
};

class FUN_00e36b80 : public hkpVehicleWheelCollide
{
  public:
    int m_uiWheelCount;
    WheelStatesArray m_kWheelStates;
    FUN_00e360f0 m_kRejectChassisListener;
    float m_fMaxExtraPenetration;
    float m_fMaxExtraPenetrationAgainstFixed;

    virtual ~FUN_00e36b80() throw();
};

// @fnv 0x00e36b80
FUN_00e36b80::~FUN_00e36b80() throw()
{
    int numWheels = this->m_kWheelStates.m_iElementCount;
    for (int i = 0; i < numWheels; ++i)
    {
        WheelState* ws = &this->m_kWheelStates.m_data[i];
        reinterpret_cast<::hkReferencedObjectC905 *>((ws->m_pCollisionShape))->FUN_00c905b0();
        hkpPhantom* phantom = ws->m_pPhantom;
        if (this->m_usMemSizeAndFlags != 0 && phantom->m_usMemSizeAndFlags != 0)
        {
            reinterpret_cast<::PhRemoveListener *>((phantom))->FUN_00d07c80(&this->m_kRejectChassisListener);
        }
        reinterpret_cast<::hkReferencedObjectC905 *>((phantom))->FUN_00c905b0();
    }
}

namespace fnv_00e36e20 {

template <typename T> struct hkArrayE36E
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    void GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(hkMemoryRouter::getInstance().heap(), n);
        m_iElementCount = n;
    }
};

class hkReferencedObjectE36E
{
  public:
    virtual ~hkReferencedObjectE36E() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

};

class hkpPhantomOverlapListenerE36E
{
  public:
    virtual ~hkpPhantomOverlapListenerE36E() throw();
};

class hkpCollidableE36E;

class hkpRigidBodyE36E
{
  public:
    char m_acUnk00[0x10];
    char m_kCollidable[0x10];

    const hkpCollidableE36E* getCollidable() const
    {
        return (const hkpCollidableE36E*)m_kCollidable;
    }
};

class hkpPhantomE36E : public hkReferencedObjectE36E
{
  public:
};

class hkpShapeE36E : public hkReferencedObjectE36E
{
};

class hkpRejectChassisListenerE36E : public hkReferencedObjectE36E, public hkpPhantomOverlapListenerE36E
{
  public:
    const hkpCollidableE36E* m_pChassisCollidable;
};

struct hkpVehicleLinearCastWheelCollideWheelStateE36E
{
    hkpPhantomE36E* m_pPhantom;
    hkpShapeE36E* m_pCollisionShape;
    char m_acUnk08[0x58];
};

class hkpVehicleLinearCastWheelCollideE36E : public hkReferencedObjectE36E
{
  public:
    hkBool m_bWheelCollisionEnabled;
    hkUint8 m_type;
    hkUint32 m_uiWheelCount;
    hkArrayE36E<hkpVehicleLinearCastWheelCollideWheelStateE36E> m_kWheelStates;
    hkpRejectChassisListenerE36E m_kRejectChassisListener;
    hkReal m_fMaxExtraPenetration;
    hkReal m_fMaxExtraPenetrationAgainstFixed;

    hkpVehicleLinearCastWheelCollideE36E* CloneWithChassis(const hkpRigidBodyE36E& kNewChassis,
                                                           const hkArrayE36E<hkpPhantomE36E*>& kNewPhantoms) const
        throw();
};

class FUN_00e36b20 : public hkpVehicleLinearCastWheelCollideE36E
{
  public:
    static __forceinline void* operator new(size_t uiSize) throw()
    {
        hkReferencedObjectE36E* p = (hkReferencedObjectE36E*)hkMemoryRouter::getInstance().heap().blockAlloc(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
    FUN_00e36b20() throw();
};

// @fnv 0x00e36e20
hkpVehicleLinearCastWheelCollideE36E* hkpVehicleLinearCastWheelCollideE36E::CloneWithChassis(
    const hkpRigidBodyE36E& kNewChassis, const hkArrayE36E<hkpPhantomE36E*>& kNewPhantoms) const throw()
{
    hkpVehicleLinearCastWheelCollideE36E* pkNew = new FUN_00e36b20();
    const int iNumWheels = m_kWheelStates.GetLogicalSize();
    pkNew->m_kWheelStates.SetSizeAndGrow(iNumWheels);
    for (hkUint8 i = 0; i < iNumWheels; i++)
    {
        hkpVehicleLinearCastWheelCollideWheelStateE36E& kWheelState = pkNew->m_kWheelStates[i];
        kWheelState.m_pCollisionShape = m_kWheelStates[i].m_pCollisionShape;
        reinterpret_cast<::FUN_00c90510_class *>((kWheelState.m_pCollisionShape))->FUN_00c90510();
        hkpPhantomE36E* pkPhantom = kNewPhantoms[i];
        kWheelState.m_pPhantom = pkPhantom;
        reinterpret_cast<::FUN_00c90510_class *>((pkPhantom))->FUN_00c90510();
        reinterpret_cast<::PhRemoveListener *>((pkPhantom))->FUN_00d07c80((hkpRejectChassisListenerE36E*)&m_kRejectChassisListener);
        reinterpret_cast<::hkOwnerXd07de0 *>((pkPhantom))->FUN_00d07de0(&pkNew->m_kRejectChassisListener);
        pkNew->m_kRejectChassisListener.m_pChassisCollidable = kNewChassis.getCollidable();
    }
    pkNew->m_uiWheelCount = m_uiWheelCount;
    pkNew->m_fMaxExtraPenetration = m_fMaxExtraPenetration;
    pkNew->m_fMaxExtraPenetrationAgainstFixed = m_fMaxExtraPenetrationAgainstFixed;
    return pkNew;
}
}  // namespace fnv_00e36e20

struct LCWheelData
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned char unk20;
};

struct LCVehicleCtx
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    LCWheelData* unk1c;
};

__declspec(align(16)) struct LCWheelCastOut
{
    unsigned int u00, u04, u08, u0c, u10, u14, u18, u1c;
    unsigned int u20, u24, u28, u2c, u30, u34, u38, u3c;
    unsigned int u40, u44, u48, u4c, u50, u54, u58, u5c;
    unsigned int u60, u64, u68, u6c;
};

struct LCWheelResult
{
    unsigned int r00, r04, r08, r0c, r10, r14, r18, r1c;
    unsigned int r20, r24, r28, r2c, r30, r34, r38, r3c;
    unsigned int r40, r44, r48, r4c, r50, r54, r58, r5c;
};

class LCLinearCastCollide
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void wheelUpdate(LCVehicleCtx* vehicle, unsigned char iWheel, LCWheelResult* results);
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual char* castQuery(char* found, LCVehicleCtx* vehicle, unsigned char iWheel, LCWheelCastOut* out);
    virtual void applyHit(LCVehicleCtx* vehicle, unsigned char iWheel, LCWheelCastOut* out, LCWheelResult* results);
    virtual void noHit(LCVehicleCtx* vehicle, unsigned char iWheel, LCWheelResult* results);

    void UpdateAllWheels(int unkArg, LCVehicleCtx* vehicle, LCWheelResult* results);
};

// Iterates over each wheel of the vehicle, queries the cast, applies hit or no-hit results, and updates the wheel state.
// @fnv 0x00e361b0
void LCLinearCastCollide::UpdateAllWheels(int aiUnused, LCVehicleCtx* vehicle, LCWheelResult* results)
{
    LCWheelCastOut output;
    unsigned char i;
    char found;
    const unsigned char numWheels = vehicle->unk1c->unk20;

    for (i = 0; i < numWheels; i++)
    {
        char* status = castQuery(&found, vehicle, i, &output);
        if (*status != 0)
            applyHit(vehicle, i, &output, results);
        else
            noHit(vehicle, i, results);
        wheelUpdate(vehicle, i, results);
        results++;
    }
}

template <class T> struct hkArrayE363
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct hkpWheelStateE363
{
    unsigned int unk00, unk04, unk08, unk0C;
};

class hkBaseObjectE363
{
  public:
    virtual ~hkBaseObjectE363() throw();
};

class hkReferencedObjectE363 : public hkBaseObjectE363
{
  public:
    virtual ~hkReferencedObjectE363() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpVehicleLinearCastWheelCollideE363 : public hkReferencedObjectE363
{
  public:
    virtual ~hkpVehicleLinearCastWheelCollideE363() throw();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual int getNumHits(unsigned char ucWheel) const;

    int GetTotalHits() const;

    unsigned char m_bWheelCollisionEnabled;
    unsigned char m_type;
    unsigned int unk0C;
    hkArrayE363<hkpWheelStateE363> m_kWheelStates;
};

// Sums the hit counts of all wheels in m_kWheelStates by calling getNumHits for each wheel index and returns the total.
// @fnv 0x00e36360
int hkpVehicleLinearCastWheelCollideE363::GetTotalHits() const
{
    int iTotal = 0;
    const int iNumWheels = m_kWheelStates.GetLogicalSize();
    for (unsigned char i = 0; i < iNumWheels; ++i)
    {
        iTotal += getNumHits(i);
    }
    return iTotal;
}

#include "fnv/symbols_simd.h"



struct hkVector4E366
{
    __m128 m_vComponents;

    hkVector4E366()
    {}
    hkVector4E366(const hkVector4E366& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4E366& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setNeg4(const hkVector4E366& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    void setXYZ(const hkVector4E366& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, _mm_unpackhi_ps(v.m_vComponents, m_vComponents), 0xc4);
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct hkpVehicleSuspensionWheelParamsE366
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    float m_fRestLength;
    unsigned int unk24, unk28, unk2C;
};

struct hkpVehicleSuspensionE366
{
    unsigned int unk00, unk04;
    hkpVehicleSuspensionWheelParamsE366* m_kWheelParams;
};

struct hkpVehicleWheelInfoE366
{
    hkVector4E366 m_vContactPoint[6];
    hkVector4E366 m_vContactPointVelocity;
    hkVector4E366 m_vContactNormal;
    hkVector4E366 m_vHardPointWs;
    hkVector4E366 m_spinAxisCs;
    hkVector4E366 m_vSuspensionDirectionWs;
    hkVector4E366 m_steeringOrientationCs[2];
    hkVector4E366 unkD0;
};

struct hkpVehicleInstanceE366
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30;
    hkpVehicleSuspensionE366* m_pSuspension;
    unsigned int unk38, unk3C, unk40, unk44;
    hkpVehicleWheelInfoE366* m_kWheelInfoArray;
};

struct hkContactPointE366
{
    hkVector4E366 m_vContactPosition;
    hkVector4E366 m_vSeparatingNormal;
};

struct CollisionDetectionWheelOutputE366
{
    hkContactPointE366 m_vContactPoint;
    float m_fSuspensionLength;
    unsigned int m_uiContactShapeKeys;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    float m_fContactFriction;
    float m_fValueAtOffset4C;
    float m_fValueAtOffset50;
};

struct hkpVehicleRayCastWheelCollideE366
{
    static void RayCastWheelCollide(const hkpVehicleInstanceE366* pkVehicle, unsigned char ucWheelNum,
                                              CollisionDetectionWheelOutputE366& kCdInfo);
};

// Copies contact point velocity, writes negated hard point components to the separating normal, and stores the wheel rest length.
// @fnv 0x00e36670
void hkpVehicleRayCastWheelCollideE366::RayCastWheelCollide(const hkpVehicleInstanceE366* pkVehicle,
                                                                      unsigned char ucWheelNum,
                                                                      CollisionDetectionWheelOutputE366& kCdInfo)
{
    const float fRestLength = pkVehicle->m_pSuspension->m_kWheelParams[ucWheelNum].m_fRestLength;
    const hkpVehicleWheelInfoE366& kWheel = pkVehicle->m_kWheelInfoArray[ucWheelNum];
    kCdInfo.m_uiContactShapeKeys = 0;
    kCdInfo.m_fContactFriction = fRestLength;
    kCdInfo.m_fValueAtOffset4C = 0.0f;
    kCdInfo.m_vContactPoint.m_vContactPosition = kWheel.m_vContactPointVelocity;
    hkVector4E366 kNormal;
    kNormal.setNeg4(kWheel.m_vHardPointWs);
    kCdInfo.m_vContactPoint.m_vSeparatingNormal.setXYZ(kNormal);
    kCdInfo.m_fSuspensionLength = 0.0f;
    kCdInfo.m_fValueAtOffset50 = 1.0f;
    kCdInfo.m_vContactPoint.m_vSeparatingNormal(3) = fRestLength;
}

struct __declspec(align(16)) FUN_00e36900_V
{
    union
    {
        __m128 vec;
        struct
        {
            float x, y, z, w;
        };
    };
    void FUN_00c7f640(void* ws, void* src);
};

class FUN_00e36900_Wrap : public hkpVehicleLinearCastWheelCollide
{
  public:
    void FUN_00e36900(int unused, unsigned char wheelIndex, FUN_00e36900_V* result);
};

// Passes result and the wheel state at wheelIndex through two helpers with z zeroed in between, and stores the final vector in result.
// @fnv 0x00e36900
void FUN_00e36900_Wrap::FUN_00e36900(int unused, unsigned char wheelIndex, FUN_00e36900_V* result)
{
    FUN_00e36900_V second;
    FUN_00e36900_V first;

    void* ws = (char*)m_kWheelStates.m_data + wheelIndex * 0x60 + 0x10;

    reinterpret_cast<::FUN_00c7f690_cls *>(&(first))->FUN_00c7f690((const ::S_00c7f690_M *)(ws), (const ::S_00c7f690_V *)(result));

    first.z = 0.0f;

    second.FUN_00c7f640(ws, &first);

    result->vec = second.vec;
}

__declspec(align(16)) struct hkAabb_36950
{
    float m_minX;
    float m_minY;
    float m_minZ;
    float m_maxX;
    float m_maxY;
    float m_maxZ;
};

struct FUN_00cf24a0_host_36950
{
};

struct FUN_00e36950_WheelState_36950
{
    FUN_00cf24a0_host_36950* m_object;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

struct FUN_00e36950_host_36950
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00e36950_WheelState_36950* unk10;
    int unk14;

    void UpdateWheelAabb(const void* vehicle);
};



struct __declspec(align(16)) LCAVec4
{
    hkReal v[4];
};


struct __declspec(align(16)) LCCastInput
{
    LCAVec4 m_vTo;
    volatile hkReal m_10;
    volatile hkReal m_14;
    hkUint32 m_18;
    hkUint32 m_1c;
    const hkUint8* m_20;
    hkReal m_24;
    hkUint32 m_28;
    hkUint32 m_2c;
    hkUint32 m_30;
    hkUint32 m_34;
    hkUint32 m_38;
    hkUint32 m_3c;
    hkUint32 m_40;
    hkUint32 m_44;
    hkUint32 m_48;
    hkReal m_4c;
    hkInt32 m_50;
    hkUint32 m_54;
    hkUint32 m_58;
    hkUint32 m_5c;
    hkUint32 m_60;
    hkUint32 m_64;
    hkUint32 m_68;
    hkUint32 m_6c;
    hkUint32 m_70;
    hkUint32 m_74;
    hkUint32 m_78;
    hkUint32 m_7c;
    hkUint32 m_80;
    hkUint32 m_84;
    hkUint32 m_88;
    hkUint32 m_8c;
    hkUint32 m_90;
    hkUint32 m_94;
    hkUint32 m_98;
    hkUint32 m_9c;
};

struct FUN_00e369d0_Result
{
    hkUint32 m_00;
    hkUint32 m_04;
    hkUint32 m_08;
    hkUint32 m_0c;
    hkUint32 m_10;
    hkUint32 m_14;
    hkUint32 m_18;
    hkUint32 m_uiCollisionFilterData;
    hkUint32 m_20;
    hkUint32 m_24;
    hkUint32 m_28;
    hkUint32 m_2c;
    hkUint32 m_30;
    hkUint32 m_34;
    hkUint32 m_38;
    hkUint32 m_3c;
    hkUint32 m_40;
    hkUint32 m_44;
    hkUint32 m_48;
    hkUint32 m_4c;
};

struct FUN_00cf2880_Shape
{
};

struct FUN_006212c0_Context
{
};

struct FUN_00e369d0_Class : public hkpVehicleLinearCastWheelCollide
{
  public:
    void CastWheel(hkUint8* hitOut, const void* b, hkUint8 wheelIndex, void* context);
};

// Casts the wheel's shape, writes a hit flag byte through hitOut, and on a hit passes the cast data to context via FUN_006212c0.
// @fnv 0x00e369d0
void FUN_00e369d0_Class::CastWheel(hkUint8* hitOut, const void* b, hkUint8 wheelIndex, void* context)
{
    hkpVehicleLinearCastWheelCollideWheelState* pWheelState = &m_kWheelStates.m_data[wheelIndex];

    FUN_00e369d0_Result result;
    new ((void *)&(result)) ::FUN_00cd2d80(pWheelState->m_pCollisionShape, &pWheelState->m_kMotionTransform, 0);
    result.m_uiCollisionFilterData = m_uiWheelCount;

    LCCastInput input;
    input.m_10 = ::DAT_0104da4c;
    input.m_14 = ::DAT_0104da4c;
    __m128 tmp = *reinterpret_cast<const __m128*>(&pWheelState->m_vTo);
    input.m_10 = m_fMaxExtraPenetration;
    input.m_14 = m_fMaxExtraPenetrationAgainstFixed;
    input.m_4c = ::DAT_0104da48;
    *reinterpret_cast<__m128*>(&input.m_vTo) = tmp;
    input.m_24 = ::DAT_0104da48;
    input.m_20 = &(*reinterpret_cast<unsigned char *>(&::DAT_010c476c));
    input.m_50 = 0;

    reinterpret_cast<::PhantomS *>((reinterpret_cast<FUN_00cf2880_Shape*>(pWheelState->m_pPhantom)))->FUN_00cf2880((const ::CollidableS *)(::FUN_00e369d0_Result *)(&result), (*(const ::LinCastInputS *)(&input)), (void *)(&input.m_20), (void *)(0));

    if (input.m_50 != 0)
    {
        reinterpret_cast<::FUN_006212c0_shell *>((((FUN_006212c0_Context*)(*(void* volatile*)&context))))->FUN_006212c0(&input.m_30);
        hkUint8* __restrict pHitOut = *(hkUint8* volatile*)&hitOut;
        *pHitOut = 1;
    }
    else
    {
        hkUint8* __restrict h0 = *(hkUint8* volatile*)&hitOut;
        *h0 = 0;
    }
}



namespace hkRouterE36 {

}

class hkReferencedObjectE36
{
  public:
};

template <class T> class hkArrayE36
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newCap = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkMemoryRouter::getInstance().heap(), n);
        m_iElementCount = n;
    }
};

struct WheelStateE36
{
    int unk00;
    hkReferencedObjectE36* m_pPhantom;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
};

struct hkpVehicleDataE36
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned char m_iWheelCount;
};

struct hkpVehicleInstanceE36
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    hkpVehicleDataE36* m_data;
};

class hkpVehicleRayCastWheelCollideE36
{
  public:
    int unk00, unk04, unk08, unk0C;
    hkArrayE36<WheelStateE36> m_kWheelStates;

    void SetWheelPhantoms(const hkpVehicleInstanceE36* vehicle, const hkArrayE36<hkReferencedObjectE36*>& phantoms);
};

// Resizes m_kWheelStates to the vehicle's wheel count and stores each phantom in its wheel state, calling FUN_00c90510 on each phantom.
// @fnv 0x00e36c30
void hkpVehicleRayCastWheelCollideE36::SetWheelPhantoms(const hkpVehicleInstanceE36* vehicle,
                                                        const hkArrayE36<hkReferencedObjectE36*>& phantoms)
{
    int numWheels = vehicle->m_data->m_iWheelCount;
    m_kWheelStates.SetSizeAndGrow(numWheels);
    for (unsigned char i = 0; i < numWheels; i++)
    {
        m_kWheelStates[i].m_pPhantom = phantoms[i];
        reinterpret_cast<::FUN_00c90510_class *>((phantoms[i]))->FUN_00c90510();
    }
}


namespace fnvc_adapt {

}


template <typename T> struct hkArrayE36C
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    void GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(hkMemoryRouter::getInstance().heap(), n);
        m_iElementCount = n;
    }
};

class hkReferencedObjectE36C
{
  public:
    virtual ~hkReferencedObjectE36C() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpPhantomOverlapListenerE36C
{
  public:
    virtual ~hkpPhantomOverlapListenerE36C() throw();
};

class hkpCollidableE36C;

class hkpRigidBodyE36C
{
  public:
    char m_acUnk00[0x10];
    char m_kCollidable[0x10];

    const hkpCollidableE36C* getCollidable() const
    {
        return (const hkpCollidableE36C*)m_kCollidable;
    }
};

struct __declspec(align(16)) hkVector4E36C
{
    float x, y, z, w;
};

struct hkAabbE36C
{
    hkVector4E36C m_kMinimumCorner;
    hkVector4E36C m_kMaximumCorner;
};

class hkpPhantomE36C : public hkReferencedObjectE36C
{
  public:
};

class FUN_00cf2cb0 : public hkpPhantomE36C
{
  public:
    static __forceinline void* operator new(size_t, void* pvMem) throw()
    {
        return pvMem;
    }
    static __forceinline void* operator new(size_t uiSize) throw()
    {
        hkReferencedObjectE36C* p =
            (hkReferencedObjectE36C*)hkMemoryRouter::getInstance().heap().blockAlloc(uiSize);
        p->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
    FUN_00cf2cb0(const hkAabbE36C& kAabb, hkUint32 uiCollisionFilterInfo) throw();

    char m_acUnk08[0xd8];
};

class hkpShapeE36C : public hkReferencedObjectE36C
{
};

class hkpRejectChassisListenerE36C : public hkReferencedObjectE36C, public hkpPhantomOverlapListenerE36C
{
  public:
    const hkpCollidableE36C* m_pChassisCollidable;
};

struct hkpVehicleLinearCastWheelCollideWheelStateE36C
{
    hkpPhantomE36C* m_pPhantom;
    hkpShapeE36C* m_pCollisionShape;
    char m_acUnk08[0x58];
};

struct hkpVehicleDataWheelComponentParamsE36C
{
    hkReal m_fSphereRadius;
    hkReal m_fViscosityFriction;
    hkReal m_fMaxFriction;
    hkReal m_fSlipAngle;
    hkReal m_fSlipVelocity;
    hkReal m_fMaxContactBodyAcceleration;
    hkReal m_fForceFeedbackMultiplier;
    hkReal m_fMaxFrictionForce;
    hkReal m_fFrictionEqualizer;
    hkInt8 m_iAxle;
};

struct hkpVehicleDataE36C
{
    char m_acUnk00[0x20];
    hkUint8 m_iWheelCount;
    char m_acUnk21[0x6b];
    hkArrayE36C<hkpVehicleDataWheelComponentParamsE36C> m_kWheelParams;
};

struct hkpVehicleInstanceE36C
{
    char m_acUnk00[0x18];
    hkpRigidBodyE36C* m_pChassisCollidable;
    hkpVehicleDataE36C* m_data;

    hkpRigidBodyE36C* getChassis() const
    {
        return m_pChassisCollidable;
    }
};

class hkpVehicleLinearCastWheelCollideE36C : public hkReferencedObjectE36C
{
  public:
    hkBool m_bWheelCollisionEnabled;
    hkUint8 m_type;
    hkUint32 m_uiWheelCount;
    hkArrayE36C<hkpVehicleLinearCastWheelCollideWheelStateE36C> m_kWheelStates;
    hkpRejectChassisListenerE36C m_kRejectChassisListener;
    hkReal m_fMaxExtraPenetration;
    hkReal m_fMaxExtraPenetrationAgainstFixed;

    void InitializeWheelCollisions(const hkpVehicleInstanceE36C* pkVehicle) throw();
};


class hkBaseObjE36B
{
  public:
    virtual ~hkBaseObjE36B() throw();
};

class hkRefObjE36B : public hkBaseObjE36B
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjE36B() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkRefObjE36B() throw();
};

class hkIfaceE36B
{
  public:
    hkIfaceE36B() throw()
    {}
    virtual ~hkIfaceE36B() throw();
};

template <class T> class hkArrayE36B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE36B() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkToleranceE36B : public hkRefObjE36B, public hkIfaceE36B
{
  public:
    int unk0C;
    float m_tolerance0;
    float m_tolerance1;

    hkToleranceE36B() throw()
    {}
    virtual ~hkToleranceE36B() throw();
};

class FUN_00e36b20 : public hkRefObjE36B
{
  public:
    unsigned char m_08;
    unsigned char m_09;
    int unk0C;
    hkArrayE36B<void*> m_ppData;
    hkToleranceE36B m_fScalar;

    FUN_00e36b20() throw();
    virtual ~FUN_00e36b20() throw();
};

// Initializes the scalar tolerance to 1.192092896e-07f, sets m_08 to 0 and m_09 to 2.
// @fnv 0x00e36b20
FUN_00e36b20::FUN_00e36b20() throw()
{
    m_fScalar.m_tolerance0 = 1.192092896e-07f;
    m_fScalar.m_tolerance1 = 1.192092896e-07f;
    m_08 = 0;
    m_09 = 2;
}

struct __declspec(align(16)) Vector4E36120
{
    float x;
    float y;
    float z;
    float w;
    __m128& Vector4f()
    {
        return *reinterpret_cast<__m128*>(this);
    }
    const __m128& Vector4f() const
    {
        return *reinterpret_cast<const __m128*>(this);
    }
    void set(float fX, float fY, float fZ, float fW)
    {
        Vector4f() = _mm_setr_ps(fX, fY, fZ, fW);
    }
    void setNeg4(const Vector4E36120& v)
    {
        Vector4f() = _mm_xor_ps(::DAT_010c4c00, v.Vector4f());
    }
};
struct MemoryE36120
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};
struct ContextE36120
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MemoryE36120* m_pkMemory;
};
ContextE36120* GetContextE36120();
struct ShapeE36120
{
    static void* operator new(size_t nbytes) throw()
    {
        ContextE36120* pkContext = GetContextE36120();
        ShapeE36120* pkShape = static_cast<ShapeE36120*>(pkContext->m_pkMemory->allocateChunk(nbytes));
        pkShape->m_usMemSize = (unsigned short)nbytes;
        return pkShape;
    }
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSize;
    unsigned short m_usRefCount;
};
struct CapsuleE36120 : public ShapeE36120
{
    CapsuleE36120(const Vector4E36120& kA, const Vector4E36120& kB, float fRadius, float fExtra) throw();
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

// @fnv 0x00e36120
ShapeE36120* FUN_00e36120(float afHeight, float fRadius)
{
    Vector4E36120 kTop;
    kTop.set(::DAT_01011d78, ::DAT_01011d78, afHeight * 0.5, ::DAT_01011d78);
    Vector4E36120 kBottom;
    kBottom.setNeg4(kTop);
    return new CapsuleE36120(kTop, kBottom, fRadius, 0.0f);
}


struct __declspec(align(16)) hkVector4E363
{
    float x, y, z, w;
    const __m128& getQuad() const
    {
        return *(const __m128*)&x;
    }
    __m128& getQuad()
    {
        return *(__m128*)&x;
    }
    void operator=(const hkVector4E363& v)
    {
        getQuad() = v.getQuad();
    }
};

struct hkTransformE363
{
    hkVector4E363 m_kColumn0;
    hkVector4E363 m_kColumn1;
    hkVector4E363 m_kColumn2;
    hkVector4E363 m_vTranslation;
    const hkVector4E363& getTranslation() const
    {
        return m_vTranslation;
    }
};

struct hkpShapeE363;
struct hkpCollidableE363;

class hkpAabbPhantomE363 : public hkpPhantom
{
  public:
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void V9() throw();
    virtual void RemoveOverlappingBody() throw();
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    hkArrayE363<hkpCollidableE363*> m_ppOverlappingCollidables;
};

struct FUN_00d01a60
{
    int m_minX;
    int m_minY;
    int m_minZ;
    unsigned char m_expansionMinX;
    unsigned char m_expansionMinY;
    unsigned char m_expansionMinZ;
    unsigned char m_ucExpansionShift;
    int m_maxX;
    int m_maxY;
    int m_maxZ;
    unsigned char m_expansionMaxX;
    unsigned char m_expansionMaxY;
    unsigned char m_expansionMaxZ;
    unsigned char m_ucUnknownByte;
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    void* m_pChildShapeAabbs;
    void* m_pChildShapeKeys;

    FUN_00d01a60() throw();
};

struct hkpTypedBroadPhaseHandleE363
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;

    __forceinline hkpTypedBroadPhaseHandleE363(int iType)
    {
        m_iOwnerObjectOffset = 0;
        m_type = (char)iType;
        m_uiCollisionFilterData = 0;
        m_ucObjectQualityType = (char)0xff;
        m_iOwnerOffset = 0x7f;
    }
    void SetOwnerPointer(void* pvOwner)
    {
        m_iOwnerOffset = (char)((char*)pvOwner - (char*)this);
    }
};

struct hkpCollidableE363
{
    const hkpShapeE363* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCollidableE363* m_parent;
    char m_iOwnerOffset;
    char m_uiForceCollideOntoPpu;
    short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandleE363 m_kBroadPhaseHandle;
    FUN_00d01a60 m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;

    __forceinline hkpCollidableE363(const hkpShapeE363* pkShape, const hkTransformE363* pkTransform, int iType = 0)
        : m_pCollisionShape(pkShape), m_uiCollisionShapeKey(0xffffffff), m_pMotionState(pkTransform), m_parent(0),
          m_iOwnerOffset(0), m_kBroadPhaseHandle(iType)
    {
        m_fAllowedPenetrationDepth = -1.0f;
        m_kBroadPhaseHandle.SetOwnerPointer(this);
        m_uiForceCollideOntoPpu = 0;
        m_uiShapeSizeOnSpu = 0;
    }
};

struct hkpRootCdPointE363
{
    hkVector4E363 m_vContactPosition;
    hkVector4E363 m_vHitNormal;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
};

struct hkpPairLinearCastCommandE363
{
    hkVector4E363 m_vFrom;
    hkVector4E363 m_vTo;
    const hkpCollidableE363* m_pCollidableA;
    const hkpCollidableE363* m_pCollidableB;
    hkpRootCdPointE363* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    hkpRootCdPointE363* m_pStartPointResultBuffer;
    int m_iStartPointResultCount;
    int m_iStartPointResultCapacity;
};

struct hkpVehicleLinearCastWheelCollideWheelStateE363
{
    hkpAabbPhantomE363* m_pPhantom;
    const hkpShapeE363* m_pCollisionShape;
    int m_08;
    int m_0c;
    hkTransformE363 m_kMotionTransform;
    hkVector4E363 m_vTo;
};

struct hkpVehicleInstanceE363;
struct hkpCollisionFilterE363;

class LinearCastCommandBuilder : public hkpVehicleLinearCastWheelCollideE363
{
  public:
    int FUN_00e363d0(const hkpVehicleInstanceE363* pkVehicle, const hkpCollisionFilterE363* pkFilter,
                     hkpCollidableE363* pkCollidableStorage, hkpPairLinearCastCommandE363* pkCommandStorage,
                     hkpRootCdPointE363* pkOutputStorage) const throw();
};

// Fills one linear cast command for each collidable overlapping each wheel's phantom, creating a collidable per wheel, and returns the command count.
// @fnv 0x00e363d0
int LinearCastCommandBuilder::FUN_00e363d0(const hkpVehicleInstanceE363* pkVehicle,
                                           const hkpCollisionFilterE363* pkFilter,
                                           hkpCollidableE363* pkCollidableStorage,
                                           hkpPairLinearCastCommandE363* pkCommandStorage,
                                           hkpRootCdPointE363* pkOutputStorage) const throw()
{
    int iNumCommands = 0;
    const int iNumWheels = m_kWheelStates.GetLogicalSize();
    for (char i = 0; i < iNumWheels; ++i)
    {
        const hkpVehicleLinearCastWheelCollideWheelStateE363& kWheelState =
            ((const hkpVehicleLinearCastWheelCollideWheelStateE363*)m_kWheelStates.m_data)[i];
        if (pkCollidableStorage)
            new (pkCollidableStorage) hkpCollidableE363(kWheelState.m_pCollisionShape, &kWheelState.m_kMotionTransform);

        kWheelState.m_pPhantom->RemoveOverlappingBody();
        const hkArrayE363<hkpCollidableE363*>& kOverlapping = kWheelState.m_pPhantom->m_ppOverlappingCollidables;
        const int iNumOverlapping = kOverlapping.GetLogicalSize();
        for (char j = 0; j < iNumOverlapping; ++j)
        {
            ++iNumCommands;
            hkpPairLinearCastCommandE363& kCommand = *pkCommandStorage;
            kCommand.m_pCollidableA = pkCollidableStorage;
            kCommand.m_pCollidableB = kOverlapping.m_data[j];
            kCommand.m_vFrom = kWheelState.m_kMotionTransform.getTranslation();
            kCommand.m_vTo = kWheelState.m_vTo;
            kCommand.m_pResultBuffer = pkOutputStorage;
            kCommand.m_iResultCount = 1;
            kCommand.m_iResultCapacity = 0;
            kCommand.m_iStartPointResultCount = 0;
            ++pkOutputStorage;
            ++pkCommandStorage;
        }
        ++pkCollidableStorage;
    }
    return iNumCommands;
}

class WheelPhantomCollector : public hkpVehicleLinearCastWheelCollideE36C
{
  public:
    void FUN_00e36ab0(hkArray<hkpPhantomE36C*>* output);
};
// Iterates wheel states and appends each wheel's phantom pointer to the output array, growing it when needed.
// @fnv 0x00e36ab0
void WheelPhantomCollector::FUN_00e36ab0(hkArray<hkpPhantomE36C*>* output)
{
    const int wheelCount = m_kWheelStates.GetLogicalSize();
    for (int wheel = 0; wheel < wheelCount; ++wheel)
    {
        hkpPhantomE36C* phantom = m_kWheelStates[wheel].m_pPhantom;
        hkMemoryRouter* memory = &hkMemoryRouter::getInstance();
        if (output->m_iElementCount == (output->m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(memory->m_heap), (::AudioStream *)(output), sizeof(phantom));
        hkpPhantomE36C** slot = output->m_data + output->m_iElementCount;
        __assume(slot != 0);
        new (slot) hkpPhantomE36C*(phantom);
        ++output->m_iElementCount;
    }
}

// Moved from hkpvehiclelinearcastwheelcollide_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
void __cdecl FUN_00e36aa0();



struct FUN_00ca0c40_host
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    float m_fSlipAngle;  // at 0x90
    void FUN_00ca0c40(const hkVector4& point, hkVector4& velOut);
};

struct CollidableStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;  // at 0x10
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_cBroadPhaseType;  // at 0x18
    char unk19;
    char unk1a;
    char unk1b;
};

struct HitStandIn
{
    __m128 m_vContactPoint;
    union
    {
        __m128 m_contactNormal;
        struct
        {
            float m_nx;
            float m_ny;
            float m_nz;
            float m_fHitDistance;
        };
    };
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
    CollidableStandIn* m_kCollidable;  // at 0x48
    unsigned int m_uiCollisionShapeKey;           // at 0x4c
};

struct WheelCollideOutputStandIn
{
    __m128 m_vContactPoint;
    __m128 m_contactNormal;
    float m_fSlipAngle;
    FUN_00ca0c40_host* m_pUserData;
    unsigned int m_uiCollisionShapeKey;
    int m_hardpointIndex;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    float m_suspensionLength;
    float m_suspensionClosingVelocity;
    float m_invSuspensionClosingVelocity;
};

struct WheelSuspensionInfoStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float m_fRestLength;  // at 0x20
    int unk24;
    int unk28;
    int unk2c;  // sizeof = 0x30
};

struct SuspensionStandIn
{
    int unk00;
    int unk04;
    WheelSuspensionInfoStandIn* m_wheelData;  // at 0x08
};

struct WheelStateStandIn
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    __m128 m_dir;  // at 0x80
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;  // sizeof = 0xe0
};

struct VehicleDataStandIn
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
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    float m_pFreeList;  // at 0x84
};

struct VehicleInstanceStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00ca0c40_host* m_pChassisCollidable;  // at 0x18
    VehicleDataStandIn* m_data;               // at 0x1c
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    SuspensionStandIn* m_pSuspension;  // at 0x34
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    WheelStateStandIn* m_kWheelStates;  // at 0x48
};

extern "C" void _ReadWriteBarrier(void);

inline float dot3(__m128 a, __m128 b)
{
    __m128 mul = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(mul, mul, 0x55);
    __m128 z = _mm_shuffle_ps(mul, mul, 0xaa);
    __m128 sum = _mm_add_ss(y, mul);
    sum = _mm_add_ss(z, sum);
    float res;
    _mm_store_ss(&res, sum);
    return res;
}

// @fnv 0x00e36510
void FUN_00e36510(VehicleInstanceStandIn* vehicle, unsigned char wheelIndex, HitStandIn* hit,
                            WheelCollideOutputStandIn* out)
{
    float velChassis = vehicle->m_pSuspension->m_wheelData[wheelIndex].m_fRestLength;
    WheelStateStandIn* velGround = &vehicle->m_kWheelStates[wheelIndex];

    out->m_vContactPoint = hit->m_vContactPoint;
    out->m_contactNormal = hit->m_contactNormal;

    FUN_00ca0c40_host* val;
    CollidableStandIn* i;
    i = hit->m_kCollidable;
    if (i->m_cBroadPhaseType == 1)
    {
        val = (FUN_00ca0c40_host*)((char*)i + i->m_iOwnerOffset);
    }
    else
    {
        val = 0;
    }
    out->m_pUserData = val;
    out->m_fSlipAngle = val->m_fSlipAngle;
    out->m_uiCollisionShapeKey = hit->m_uiCollisionShapeKey;
    out->m_hardpointIndex = -1;
    out->m_suspensionLength = hit->m_fHitDistance * velChassis;

    float pObj;
    pObj = dot3(velGround->m_dir, out->m_contactNormal);
    if (pObj < -vehicle->m_data->m_pFreeList)
    {
        hkVector4 z;
        hkVector4 len;
        vehicle->m_pChassisCollidable->FUN_00ca0c40((const hkVector4&)out->m_vContactPoint, len);
        out->m_pUserData->FUN_00ca0c40((const hkVector4&)out->m_vContactPoint, z);
        __m128 idx;
        idx = _mm_load_ps(&z.x);
        __m128 wheelState;
        wheelState = _mm_load_ps(&len.x);
        float vc;
        vc = dot3(_mm_sub_ps(wheelState, idx), out->m_contactNormal);
        float q;
        q = (float)(-1.0 / pObj);
        out->m_suspensionClosingVelocity = q * vc;
        out->m_invSuspensionClosingVelocity = q;
    }
    else
    {
        out->m_suspensionClosingVelocity = 0.0f;
        out->m_invSuspensionClosingVelocity = 1.0f / vehicle->m_data->m_pFreeList;
    }
}

// Moved from hkpvehiclelinearcastwheelcollide_rtm_variant.cpp (VEGAS-15).
#include "fnv/symbols_00d26000.h"
void __cdecl ResizeAudioStream(void* heap, void* arr, int elementSize);


struct E367_Vehicle : hkpVehicleInstanceE36C
{
    unsigned int unk20, unk24, unk28, unk2C, unk30;
    hkpVehicleSuspensionE366* m_pSuspension;
};

class E367_Class : public hkpVehicleLinearCastWheelCollide
{
  public:
    void FUN_00e36700(const E367_Vehicle* vehicle, unsigned char wheelIndex, hkAabbE36C& output);
};

// @fnv 0x00e36700
void E367_Class::FUN_00e36700(const E367_Vehicle* vehicle, unsigned char wheelIndex, hkAabbE36C& output)
{
    int index = wheelIndex;
    const hkpVehicleDataWheelComponentParamsE36C* wheel = vehicle->m_data->m_kWheelParams.m_data + index;
    const hkpVehicleSuspensionWheelParamsE366* suspension = vehicle->m_pSuspension->m_kWheelParams + index;

    double zero = 0.0;
    float halfHeight = static_cast<float>((suspension->m_fRestLength + wheel->m_fSphereRadius) * 0.5);
    float halfWidth = static_cast<float>(0.5 * wheel->m_fMaxFriction);
    Vector4E36120 extents;
    extents.set(wheel->m_fSphereRadius, halfHeight, halfWidth, 0.0f);
    Vector4E36120 center;
    center.set(0.0f, -halfHeight, 0.0f, 0.0f);

    const void* transform = &m_kWheelStates.m_data[index].m_kMotionTransform;
    ::FUN_00d26230((*(const ::hkTransformD262 *)(transform)), (*(const ::hkVector4D262 *)(&extents)), (*(const ::hkVector4D262 *)(&center)), zero,
                 (*(::hkAabbD262 *)(&output)));
}

// Moved from hkpvehiclelinearcastwheelcollide_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/RotationRows.h"
void FUN_00e36510(VehicleInstanceStandIn* vehicle, unsigned char wheelIndex, HitStandIn* hit,
                            WheelCollideOutputStandIn* out);


namespace WheelStateUpdate {

struct __declspec(align(16)) LcQuat
{
    float x, y, z, w;
};

struct LcRotation
{
    __m128 m_kColumn0, m_kColumn1, m_kColumn2;
};

struct LcTransform
{
    LcRotation m_rotation;
    __m128 m_vTranslation;
};

struct LcWheelInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    __m128 m_vContactPointVelocity;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    __m128 m_vHardPointWs;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    LcQuat m_steeringOrientation;
    __m128 unkC0;
    __m128 unkD0;
};

struct LcWheelState
{
    void* m_pPhantom;
    void* m_pCollisionShape;
    int unk08;
    int unk0C;
    LcTransform m_kMotionTransform;
    __m128 m_vTo;
};

struct LcSuspensionWheel
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_fRestLength;
    int unk24;
    int unk28;
    int unk2C;
};

struct LcSuspension
{
    int unk00;
    int unk04;
    LcSuspensionWheel* m_kWheelParams;
};

struct LcChassis
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    LcQuat m_rotation;
};

struct LcVehicle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    LcChassis* m_pChassisCollidable;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    LcSuspension* m_pSuspension;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    LcWheelInfo* m_kWheelInfoArray;
};

struct WheelCollide
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LcWheelState* m_kWheelStates;
    void FUN_00e367d0(LcVehicle* vehicle, unsigned char wheelNum);
};

static inline __m128 splat(const float& r)
{
    __m128 q = _mm_load_ss((const float*)&r);
    return _mm_shuffle_ps(q, q, 0);
}

// @fnv 0x00e367d0
void WheelCollide::FUN_00e367d0(LcVehicle* vehicle, unsigned char wheelNum)
{
    LcWheelInfo& wheelInfo = vehicle->m_kWheelInfoArray[wheelNum];
    LcWheelState& wheelState = m_kWheelStates[wheelNum];

    LcQuat rotation;
    ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(rotation), nullptr, (const ::fnv_00c66320::__m128 *)((&vehicle->m_pChassisCollidable->m_rotation)), (const ::fnv_00c66320::__m128 *)(const void *)(&wheelInfo.m_steeringOrientation));

    LcTransform& transform = wheelState.m_kMotionTransform;
    reinterpret_cast<::RotationRows *>(&(transform.m_rotation))->FUN_00cb2d90(&rotation);
    transform.m_vTranslation = wheelInfo.m_vContactPointVelocity;

    __m128 length = splat(vehicle->m_pSuspension->m_kWheelParams[wheelNum].m_fRestLength);
    wheelState.m_vTo = _mm_add_ps(_mm_mul_ps(length, wheelInfo.m_vHardPointWs), wheelInfo.m_vContactPointVelocity);
}

}

// For each wheel state, fetch its AABB and push it into the associated object via FUN_00cf24a0.
// @fnv 0x00e36950
void FUN_00e36950_host_36950::UpdateWheelAabb(const void* vehicle)
{
    int count = unk14;
    unsigned char stateIndex = 0;

    if (count > 0)
    {
        do
        {
            reinterpret_cast<::WheelStateUpdate::WheelCollide *>(this)->FUN_00e367d0((::WheelStateUpdate::LcVehicle *)(vehicle), stateIndex);

            hkAabb_36950 aabb;
            reinterpret_cast<::E367_Class *>(this)->FUN_00e36700((const ::E367_Vehicle *)(vehicle), stateIndex, (*(::hkAabbE36C *)(&aabb)));

            reinterpret_cast<::PhantomBounds *>((unk10[stateIndex].m_object))->FUN_00cf24a0((*(const ::hkAabb *)(&aabb)));

            ++stateIndex;
        } while (stateIndex < count);
    }
}

// Creates wheel shapes if none exist, sets the chassis collidable on the reject listener, and builds a phantom per wheel from its AABB.
// @fnv 0x00e36cc0
void hkpVehicleLinearCastWheelCollideE36C::InitializeWheelCollisions(const hkpVehicleInstanceE36C* pkVehicle) throw()
{
    const int iNumWheels = pkVehicle->m_data->m_iWheelCount;

    if (m_kWheelStates.GetLogicalSize() == 0)
    {
        m_kWheelStates.SetSizeAndGrow(iNumWheels);
        for (hkUint8 i = 0; i < iNumWheels; i++)
        {
            m_kWheelStates[i].m_pCollisionShape = ((::hkpShapeE36C *)(::FUN_00e36120(pkVehicle->m_data->m_kWheelParams[i].m_fMaxFriction, pkVehicle->m_data->m_kWheelParams[i].m_fSphereRadius)));
        }
    }

    m_kRejectChassisListener.m_pChassisCollidable = pkVehicle->getChassis()->getCollidable();

    for (hkUint8 i = 0; i < iNumWheels; i++)
    {
        reinterpret_cast<::WheelStateUpdate::WheelCollide *>(this)->FUN_00e367d0((::WheelStateUpdate::LcVehicle *)(pkVehicle), i);
        hkAabbE36C kAabb;
        reinterpret_cast<::E367_Class *>(this)->FUN_00e36700((const ::E367_Vehicle *)(pkVehicle), i, kAabb);
        void* pvMem = FUN_00cf2cb0::operator new(sizeof(FUN_00cf2cb0));
        const unsigned int uiElapsedMilliseconds = i * sizeof(hkpVehicleLinearCastWheelCollideWheelStateE36C);
        hkpPhantomE36C* pkPhantom = new (pvMem) FUN_00cf2cb0(kAabb, m_uiWheelCount);
        *(hkpPhantomE36C**)((char*)m_kWheelStates.m_data + uiElapsedMilliseconds) = pkPhantom;
        reinterpret_cast<::hkOwnerXd07de0 *>(((*(hkpPhantomE36C**)((char*)m_kWheelStates.m_data + uiElapsedMilliseconds))))->FUN_00d07de0(&m_kRejectChassisListener);
    }
}
