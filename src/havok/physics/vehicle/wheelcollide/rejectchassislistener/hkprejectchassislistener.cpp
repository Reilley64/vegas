
// src/havok/physics/vehicle/wheelcollide/rejectchassislistener/hkprejectchassislistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/rejectchassislistener/hkprejectchassislistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010c9000.h"
#include "havok/hkpRejectChassisListener.h"
#include "havok/hkpCollidable.h"

struct FUN_00e360f0
{
    void* m_pVTable;
    int m_unk0;
    void* m_pListener;
    ~FUN_00e360f0();
};
// @fnv 0x00e360f0
FUN_00e360f0::~FUN_00e360f0()
{
    m_pListener = &(*reinterpret_cast<void * *>(&::DAT_010c925c));
    m_pVTable = &::DAT_0102e388;
}

// The phantom overlap event: phantom, collidable, and the accept/reject result.
struct FUN_00e36100_Event
{
    void* m_pPhantom;
    const hkpCollidable* m_pCollidable;
    int m_iCollidableResult;
};

// The listener interface inside hkpRejectChassisListener (its pad8 vtable), followed by the chassis collidable.
struct FUN_00e36100_StandIn
{
    void* m_pInterfaceVTable;
    const void* m_pChassisCollidable;
    void FUN_00e36100(FUN_00e36100_Event* pArg);
};

// Rejects the collidable when it is the chassis or is not an entity.
// @fnv 0x00e36100
void FUN_00e36100_StandIn::FUN_00e36100(FUN_00e36100_Event* pArg)
{
    if (pArg->m_pCollidable == m_pChassisCollidable || pArg->m_pCollidable->m_kBroadPhaseHandle.m_type != 1)
        pArg->m_iCollidableResult = 1;
}

// @fnv 0x00e360e0
void FUN_00e360e0(int arg)
{}

// FUN_00dfbd70: this-adjusting thunk {adjustor 8} for the virtual FunAdjust_Host::FUN_00dfbd70
// reached through its secondary copy (shim base). The final overrider's body lives in its own
// translation unit, so it is only declared here.

struct FunAdjust_Plat
{
    void* m_unk00;
    virtual void vf0_aux(int* pArg);
};

struct FunAdjust_Host
{
    void* m_unk00;
    virtual void FUN_00dfbd70(int* pArg);
};

struct FunAdjust_Shim : FunAdjust_Host
{
    void* m_unk04;
};

struct FunAdjust_Derived : FunAdjust_Plat, FunAdjust_Host, FunAdjust_Shim
{
    FunAdjust_Derived();
// @fnv 0x00dfbd70
    void FUN_00dfbd70(int* pArg);
    void* m_unk10;
};

FunAdjust_Derived::FunAdjust_Derived()
{}


class hkObjdfbd40 : public hkpRejectChassisListener
{
  public:
    hkObjdfbd40* FUN_00dfbd40(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, static_cast<hkObjdfbd40*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return m_usMemSizeAndFlags;
    }
    void FUN_00e360f0() throw();
};

// Calls FUN_00e360f0, then calls operator delete on this if bit 0 of uiFlags is set, and returns this.
// @fnv 0x00dfbd40
hkObjdfbd40* hkObjdfbd40::FUN_00dfbd40(unsigned int uiFlags) throw()
{
    reinterpret_cast<::FUN_00e360f0 *>((this))->FUN_00e360f0::~FUN_00e360f0();
    if (uiFlags & 1)
        hkObjdfbd40::operator delete(this);
    return this;
}
