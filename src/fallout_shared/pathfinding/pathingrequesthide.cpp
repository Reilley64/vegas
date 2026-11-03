
// src/fallout_shared/pathfinding/pathingrequesthide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequesthide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/decl/FUN_006d2c00_shell.h"
#include "fnv/decl/FUN_006e3230_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00885bd0_St.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00984000.h"
#include "fnv/symbols_00aa1000.h"
struct PathingRequestHide
{
    virtual ~PathingRequestHide();
    void* Destroy(unsigned int flags);
};

struct FUN_006e2620
{
    ~FUN_006e2620();
    char _pad[0xB0];
};
struct _Mem_2064
{
    ~_Mem_2064();
};
struct FUN_006e55e0 : FUN_006e2620
{
    _Mem_2064 _m;
    ~FUN_006e55e0();
};
// Runs the destructor and, when flags has bit 0 set, frees the object with _delete; returns this.
// @fnv 0x006e55a0
void* PathingRequestHide::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_006e55e0 *>((this))->::FUN_006e55e0::~FUN_006e55e0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xdc);
    return this;
}
// Destroys the object, running the base destructor and the destructor of the embedded member.
// @fnv 0x006e55e0
FUN_006e55e0::~FUN_006e55e0()
{}

struct BGSSaveFormBuffer
{
};
struct StandIn5740
{
    void FUN_006e5740(BGSSaveFormBuffer*);
};
struct ThreatLocStandIn
{
    virtual void SaveGame(BGSSaveFormBuffer*);
};
// Calls FUN_006e3230, saves the object at offset 0xB0, then writes 4 bytes from offset 0xD8 to the save buffer.
// @fnv 0x006e5740
void StandIn5740::FUN_006e5740(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_006e3230_shell *>(this)->FUN_006e3230(apSaveGameBuffer);
    ((ThreatLocStandIn*)((char*)this + 0xB0))->SaveGame(apSaveGameBuffer);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 0xD8), 4, 0);
}

struct BGSLoadFormBuffer
{
};
struct PathingRequest
{
    char _pad[0xB0];
    void LoadGame(BGSLoadFormBuffer*);
public:
    void CopyTo(::PathingRequest *);
};
struct PathingLocation
{
    virtual void Dummy();
    virtual void LoadGame(BGSLoadFormBuffer*);
public:
    ::PathingLocation &operator=(const ::PathingLocation &);
};
struct MyHide : PathingRequest
{
    PathingLocation m_kHideLocation;
    char _pad2[0x24];
    int unkD8;
    void FUN_006e5790(BGSLoadFormBuffer*);
};
// Loads the base PathingRequest and the embedded PathingLocation from the buffer, then reads 4 bytes into unkD8.
// @fnv 0x006e5790
void MyHide::FUN_006e5790(BGSLoadFormBuffer* apLoadGameBuffer)
{
    PathingRequest::LoadGame(apLoadGameBuffer);
    m_kHideLocation.LoadGame(apLoadGameBuffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unkD8), 4);
}

namespace fnv_006e56f0 {
struct PathingLocation
{
    PathingLocation& operator=(const PathingLocation&);
};

struct PathingRequest
{
};

struct PathingRequestHide : PathingRequest
{
    unsigned char pad0[0xb0];
    PathingLocation m_Location;
    float m_fHideDistance;
    unsigned char pad1[0x20];
    float unkd8;
    void FUN_006e56f0(PathingRequest* apDest);
};

// Copies the base PathingRequest, then copies m_Location and the float at offset 0xd8 into the destination.
// @fnv 0x006e56f0
void PathingRequestHide::FUN_006e56f0(PathingRequest* apDest)
{
    PathingRequestHide* pdest = static_cast<PathingRequestHide*>(apDest);
    reinterpret_cast<::PathingRequest *>(this)->CopyTo((::PathingRequest *)(pdest));
    reinterpret_cast<::PathingLocation *>((void *)&(const ::fnv_006e56f0::PathingLocation &)(pdest->m_Location))->operator=((const ::PathingLocation &)(m_Location));
    pdest->unkd8 =
        this->unkd8;
}
}  // namespace fnv_006e56f0

class B6E5640Location
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;

    B6E5640Location();
    ~B6E5640Location();
    B6E5640Location& operator=(const B6E5640Location& kOther);
};

class B6E5640Actor
{
  public:
};

struct B6E5640Path
{
    int unk00;

};

class B6E5640Base
{
  public:
    B6E5640Base(B6E5640Actor* pkActor);
    virtual ~B6E5640Base();

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    B6E5640Path m_kPath;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
};

class FUN_006e5640 : public B6E5640Base
{
  public:
    B6E5640Location m_kLocation;
    int unk0D0;
    int unk0D4;
    float m_fBoundRadius;

    FUN_006e5640(B6E5640Actor* pkActor);
    virtual ~FUN_006e5640();
};

// @fnv 0x006e5640
FUN_006e5640::FUN_006e5640(B6E5640Actor* pkActor) : B6E5640Base(pkActor)
{
    reinterpret_cast<::PathingLocation *>((void *)&(const ::B6E5640Location &)(m_kLocation))->operator=((const ::PathingLocation &)(*((::B6E5640Location *)(::FUN_00984230((char *)(pkActor))))));
    m_fBoundRadius = reinterpret_cast<::FUN_00885bd0_St *>((pkActor))->FUN_00885bd0();
    reinterpret_cast<::FUN_006d2c00_shell *>(&(m_kPath))->FUN_006d2c00();
}
