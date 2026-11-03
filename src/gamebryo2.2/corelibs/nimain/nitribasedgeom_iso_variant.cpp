
// src/gamebryo2.2/corelibs/nimain/nitribasedgeom_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/nimain/nitribasedgeom.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "fnv/decl/FUN_00a80580_cls.h"
#include "fnv/decl/FUN_00a80bf0_shell.h"
#include "fnv/decl/ViewerGeometry.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109e000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "nitribasedgeom_decls.h"

class GlobalObjectO2_00a7b610;

// @fnv 0x00a74790
const GlobalObjectO2_00a7b610* FUN_00a74790()
{
    return &g_011f4a48;
}


// @fnv 0x00a89790
extern "C" ::NiGeometry* FUN_00a89790(::NiGeometry* geometry, void*, unsigned int flags)
{
    *reinterpret_cast<void**>(geometry) = &DAT_0109ed94;
    reinterpret_cast<::FUN_00a80580_cls *>((geometry))->FUN_00a80580();
    if (flags & 1u)
        ::FUN_00aa1460(geometry, sizeof(*geometry));
    return geometry;
}

struct NiUpdateData
{
    float time;
    unsigned char unk04;
    unsigned char deferUpdate;
    unsigned char updateRequested;
};
struct FUN_00a59f90_holder
{
    void FUN_00a59f90(NiUpdateData& data, unsigned int value);
};
struct ParticleDownwardPassReceiver
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void dispatch(void* data);
    void FUN_00c1ad90(void* data, unsigned int value);
};
// @fnv 0x00c1ad90
void ParticleDownwardPassReceiver::FUN_00c1ad90(void* data, unsigned int value)
{
    NiUpdateData* update = (NiUpdateData*)data;
    if (update->deferUpdate != 0)
    {
        update->updateRequested = 1;
        return;
    }
    dispatch(data);
    ((FUN_00a59f90_holder*)this)->FUN_00a59f90(*(NiUpdateData*)data, value);
}

class NiStream;
class ParticleLinkEndpoint : public NiGeometry
{
  public:
// @fnv 0x00a74780
    void FUN_00a74780(NiStream& input)
    {
        reinterpret_cast<::NiGeometry *>(this)->LinkObject(input);
    }
};

void (ParticleLinkEndpoint::*linkEndpoint)(NiStream&) = &ParticleLinkEndpoint::FUN_00a74780;

class GlobalObjectO2_00a7b610;

// @fnv 0x00a89780
extern "C" GlobalObjectO2_00a7b610* __cdecl FUN_00a89780()
{
    return &g_011f5b70;
}

// Integrate after NiGeometry::NiGeometry(), before the existing final optimization-off boundary.
namespace TriGeomViewerDetail {
struct EntryArray
{
    void* vtable;
    char** data;
    unsigned short capacity;
    unsigned short end;
    unsigned short occupied;
    unsigned short growBy;


    void Append(char* const& entry)
    {
        const unsigned int position = end;
        if (position >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(position + growBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(position, (char *&)(entry));
    }
};

}

// @fnv 0x00a897c0
void FUN_00a897c0(TriGeomViewerDetail::EntryArray* entries)
{
    reinterpret_cast<::ViewerGeometry *>((entries))->FUN_00a80e70({});
    char* label = ::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f5b70)));
    entries->Append(label);
}

namespace LineLoadEntry {
class BinaryDataRecord;
class LineReceiver : public ::NiGeometry
{
  public:
    void FUN_00a9b180(BinaryDataRecord& stream);
};

// @fnv 0x00a9b180
void LineReceiver::FUN_00a9b180(BinaryDataRecord& stream)
{
    reinterpret_cast<::FUN_00a80bf0_shell *>(this)->FUN_00a80bf0((::GeomStream &)(stream));
}
}

class NiGeometryData;

class ParticleDataEndpoint : public ::NiGeometry
{
  public:
    virtual void FUN_00c1ad80(NiGeometryData*);
};

// @fnv 0x00c1ad80
void ParticleDataEndpoint::FUN_00c1ad80(NiGeometryData* replacement)
{
    reinterpret_cast<::NiGeometry *>(this)->ReplaceModelData(replacement);
}
