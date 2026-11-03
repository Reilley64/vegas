// fallout_shared/teleportdata_decls.h: declares DoorTeleportLoadData, BaseProcess, DoorTeleportSpaceReceiver, DoorTeleportSpaceOwner, DoorCell and more
#ifndef FNV_TELEPORTDATA_DECLS_H
#define FNV_TELEPORTDATA_DECLS_H
#include <cmath>
#include <cstring>
#include "fnv/decl/FUN_00544390_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_009dcd40__Mover.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0055a000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_01187000.h"
#include "ActorPackageContext.h"
#include "TESForm.h"
#include "NiPoint3.h"
#include "TESFile.h"
struct DoorTeleportLoadData
{
    TESObjectREFR* door;
    NiPoint3 position;
    NiPoint3 rotation;
    unsigned char flags;
};
class BaseProcess
{
  public:
    char layoutPrefix[4];
    ActorPackageContext m_kProcessData;
    ActorPackageContext* GetCurrentProcessData(void);
};
class DoorTeleportSpaceReceiver
{
  public:
};
struct DoorTeleportSpaceOwner
{
    unsigned char padding[0x190];
    DoorTeleportSpaceReceiver* receiver;
};
class DoorCell
{
  public:
    TESForm* GetOwner(void);
};
class DoorCellProvider
{
  public:
    virtual DoorCell* vfn_0(void);
};
class TESFormLookup
{
  public:
    static TESForm* GetFormByID(unsigned int formID);
};
class TESFormTypeView
{
  public:
};
extern "C"
{
    void FNV_DynamicCast(void);
    extern const char FNV_NoDoor[];
    extern const char FNV_InvalidDoor[];
    extern const char FNV_BadLocation[];
    extern const char FNV_BadAngle[];
}
#endif
