// fallout_shared/teleportdata.cpp: BaseProcess, QuantityData, Thing, RefHandle and more (22 functions)
#include <new>
#include <cmath>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00410020_t.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_00544390_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00578870__FUN_00578870_Class.h"
#include "fnv/decl/fnv_006f4ed0__PathingLocation.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_009dcd40__Mover.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/decl/s575ca0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0055a000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011de000.h"
#include "teleportdata_decls.h"
#include "teleportdata_types_DoorTeleportData.h"

// @fnv 0x00717e50
ActorPackageContext* BaseProcess::GetCurrentProcessData(void)
{
    return &m_kProcessData;
}

// @fnv 0x008b3bb0
TESForm* TeleportableReference::GetTeleportDestinationForm(void)
{
    return ((::TESForm *)(reinterpret_cast<::fnv_009dcd40::Mover *>((((DoorTeleportSpaceOwner*)this)->receiver))->FUN_009dcd40()));
}

// @fnv 0x0043a320
TESWorldSpace* TeleportableReference::GetTeleportWorldspace(void)
{
    TESWorldSpace* result = 0;
    if (m_pLinkedDoorReference)
    {
        DoorCell* cell = (DoorCell*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((m_pLinkedDoorReference))->GetTarget()));
        if (cell)
            result = reinterpret_cast<::TESObjectCELL *>((cell))->GetParentWorldSpace();
        else
        {
            cell = ((DoorCellProvider*)((char*)m_pLinkedDoorReference + 0x18))->vfn_0();
            if (cell)
                result = reinterpret_cast<::TESObjectCELL *>((cell))->GetParentWorldSpace();
        }
    }
    return result;
}

// @fnv 0x0043a210
void TeleportableReference::SetLinkedDoorReference(TESObjectREFR* reference, bool set)
{
    DoorCell* cell;
    if (reference)
    {
        cell = FUN_0043a2b0();
        if (cell && cell->GetOwner())
            reinterpret_cast<::FUN_00544390_shell *>((cell))->SetFlag40(set);
        cell = (DoorCell*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget()));
        if (cell && cell->GetOwner())
            reinterpret_cast<::FUN_00544390_shell *>((cell))->SetFlag40(set);
    }
}

// @fnv 0x0043a2b0
DoorCell* TeleportableReference::FUN_0043a2b0(void)
{
    if (m_pLinkedDoorReference)
        return (DoorCell*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((m_pLinkedDoorReference))->GetTarget()));
    return 0;
}

template <int N> struct EndianSizeTag
{
};


struct FUN_00414030_shell
{
    void SwapEndian();
};
// @fnv 0x0043a4e0
void TeleportableReference::Load(TESFile* file)
{
    if (file && ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x4c455458)
    {
        DoorTeleportLoadData data;
        ::FUN_0055a400((::ReferenceIntersectionData *)&(data));
        memset(&data, 0, 32);
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data), 32);
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_00414030_shell *>(&(data))->SwapEndian();
        m_pLinkedDoorReference = data.door;
        position = data.position;
        rotation = data.rotation;
        cFlags = data.flags;
    }
}

// Swaps the byte order of seven consecutive 4-byte integers starting at this object's address using BSEndian.
// @fnv 0x00414030
void FUN_00414030_shell::SwapEndian()
{
    ::FUN_00401080((int*)this);
    ::FUN_00401080((int*)this + 1);
    ::FUN_00401080((int*)this + 2);
    ::FUN_00401080((int*)this + 3);
    ::FUN_00401080((int*)this + 4);
    ::FUN_00401080((int*)this + 5);
    ::FUN_00401080((int*)this + 6);
}

struct BSExtraData
{
    int m_iType;
    int m_uiLogicalSize;
    int m_iValue;
    int m_iPad;
};

struct FUN_00431ae0 : public BSExtraData
{
    FUN_00431ae0(int value);
};

struct ExtraListRemover
{
};

struct FUN_004197d0_shell : public BaseExtraList
{
    void SetExtraDataValue(std::intptr_t value);
};

// Sets the value of extra data type 0x22, removing it when zero or creating and adding it when absent.
// @fnv 0x004197d0
void FUN_004197d0_shell::SetExtraDataValue(std::intptr_t value)
{
    BSExtraData* extra = reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x22);
    if (extra)
    {
        if (!value)
        {
            reinterpret_cast<::FUN_00410020_t *>((((ExtraListRemover*)this)))->FUN_00410020(extra, true);
        }
        else
        {
            extra->m_iPad = value;
        }
    }
    else if (value)
    {
        extra = new FUN_00431ae0(value);
        reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(extra);
    }
}

extern float DAT_01016450;
struct R6815c0
{
};

// Sets the first four bytes and the byte at offset 0x1c to zero, then assigns two NiPoint3 values built from DAT_01016450.
// @fnv 0x0043a160
TeleportableReference* FUN_0043a160(TeleportableReference* self)
{
    NiPoint3 a;
    NiPoint3 b;
    (void *)(((R6815c0*)&self->position.x));
    (void *)(((R6815c0*)&self->rotation.x));
    *(int*)self = 0;
    (*(char*)&self->cFlags) = 0;
    self->position = *((::NiPoint3 *)(reinterpret_cast<::FUN_00416870_t *>((&a))->FUN_00416870(DAT_01016450, DAT_01016450, DAT_01016450)));
    self->rotation = *((::NiPoint3 *)(reinterpret_cast<::FUN_00416870_t *>((&b))->FUN_00416870(DAT_01016450, DAT_01016450, DAT_01016450)));
    return self;
}

struct FUN_0043a280_shell
{
    char pad[0x10];
    NiPoint3 m_vec;
    void SetVec(const NiPoint3& arVec);
};

// Assigns arVec to m_vec.
// @fnv 0x0043a280
void FUN_0043a280_shell::SetVec(const NiPoint3& arVec)
{
    m_vec = arVec;
}

struct BSStr
{
};
extern const char $SG4382[];
struct FUN_00578870_host
{
};
struct FUN_0043a2e0_host
{
    FUN_00578870_host* m;
    void SetString(BSStr*);
};
// If m is non-null, calls m->FUN_00578870(a); otherwise calls a->Set($SG4382, 0).
// @fnv 0x0043a2e0
void FUN_0043a2e0_host::SetString(BSStr* apStr)
{
    if (m)
        reinterpret_cast<::fnv_00578870::FUN_00578870_Class *>((m))->FUN_00578870((*(::fnv_00578870::BSStr *)(apStr)));
    else
        reinterpret_cast<::TextString *>((apStr))->FUN_004037f0($SG4382, 0);
}

struct UnkArg
{
    void FUN_0043a3c0(ActorPackageContext*, int);
};
struct UnkThis : BaseProcess
{
    UnkArg* FUN_0043a390(UnkArg*);
};
struct FUN_0043a3c0
{
    NiPoint3 Point;
    TESForm* m_pPathingCell;
    FUN_0043a3c0(const NiPoint3& aPoint, TESForm* aSpace);
};

// @fnv 0x0043a3c0
FUN_0043a3c0::FUN_0043a3c0(const NiPoint3& aPoint, TESForm* aSpace)
{
    Point = aPoint;
    m_pPathingCell = aSpace;
}

struct Callee_575ca0
{
};
struct Caller_43a3f0
{
    Callee_575ca0* p;
    int FUN_0043a3f0();
};
// Calls a->FUN_0043a3c0 with GetCurrentProcessData() and FUN_0043a3f0(), then returns a.
// @fnv 0x0043a390
UnkArg* UnkThis::FUN_0043a390(UnkArg* apArg)
{
    new ((void *)(apArg)) ::FUN_0043a3c0((*(const ::NiPoint3 *)(GetCurrentProcessData())), (::TESForm *)(reinterpret_cast<::Caller_43a3f0 *>(this)->FUN_0043a3f0()));
    return apArg;
}
// Returns the result of calling FUN_00575ca0 on p when p is non-null, otherwise returns 0.
// @fnv 0x0043a3f0
int Caller_43a3f0::FUN_0043a3f0()
{
    return p ? ((int)(reinterpret_cast<::s575ca0::Owner *>((p))->FUN_00575ca0())) : 0;
}


struct FUN_0043a420_shell : public DoorTeleportLoadData
{
    void FUN_0043a420();
};

// Copies the door FormID, position, rotation, and flags into data, conditionally calls SwapEndian, and passes data to _FUN_00485990.
// @fnv 0x0043a420
void FUN_0043a420_shell::FUN_0043a420()
{
    DoorTeleportLoadData data;

    if (!door)
        return;

    ::FUN_0055a400((::ReferenceIntersectionData *)&(data));
    memset(&data, 0, sizeof(data));

    *reinterpret_cast<unsigned int*>(&data.door) = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((door))->FUN_0084e3a0()));
    data.position = position;
    data.rotation = rotation;
    data.flags = flags;

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00414030_shell *>(&(data))->SwapEndian();

    ::AppendChunk(0x4c455458, &data, sizeof(data));

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00414030_shell *>(&(data))->SwapEndian();
}

struct Flt
{
    operator unsigned int();
};
struct QuantityData
{
    char _pad[0x1C];
    unsigned char byte1C;
    void CopyFrom(void*);
};
// @fnv 0x0043a810
void QuantityData::CopyFrom(void* apOther)
{
    reinterpret_cast<::FUN_00537e90 *>(this)->SetQuantity(((Flt*)apOther)->operator unsigned int());
    reinterpret_cast<::fnv_006f4ed0::PathingLocation *>(this)->FUN_006f4ed0((const ::fnv_006f4ed0::NiPoint3 *)(::ActorPackageContext *)(((BaseProcess*)apOther)->GetCurrentProcessData()));
    reinterpret_cast<::FUN_0043a280_shell *>(this)->SetVec((*(const ::NiPoint3 *)(((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((std::intptr_t)(((TESForm*)apOther))))))));
    byte1C = ((QuantityData*)apOther)->byte1C;
}

struct GO
{
    operator unsigned int() const;
};

struct Call_439090
{
};

struct FUN_0043a860_shell
{
    bool FUN_0043a860(TeleportableReference* apCompare);
};

// Returns true if the GO value, process data, source files, or the byte at offset 0x1c differ between this and apCompare.
// @fnv 0x0043a860
bool FUN_0043a860_shell::FUN_0043a860(TeleportableReference* apCompare)
{
    if (reinterpret_cast<GO*>(this)->operator unsigned int() !=
        reinterpret_cast<GO*>(apCompare)->operator unsigned int())
        return true;

    if (reinterpret_cast<::NiPlane *>((reinterpret_cast<Call_439090*>(reinterpret_cast<BaseProcess*>(this)->GetCurrentProcessData())))->operator==((*(const ::NiPlane *)(reinterpret_cast<BaseProcess*>(apCompare)->GetCurrentProcessData()))))
        return true;

    if (reinterpret_cast<::NiPlane *>((reinterpret_cast<Call_439090*>(((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((std::intptr_t)(reinterpret_cast<TESForm*>(this))))))))->operator==((*(const ::NiPlane *)(((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((std::intptr_t)(reinterpret_cast<TESForm*>(apCompare)))))))))
        return true;

    if (*(reinterpret_cast<unsigned char*>(this) + 0x1c) != apCompare->cFlags)
        return true;

    return false;
}

struct FUN_0043a8f0_shell
{
    unsigned short FUN_0043a8f0();
};

// Returns 0x1c, computed by adding 0xc, 0xc, and 4 to an unsigned short initialized to zero.
// @fnv 0x0043a8f0
unsigned short FUN_0043a8f0_shell::FUN_0043a8f0()
{
    unsigned short v = 0;
    v += 0xc;
    v += 0xc;
    v += 4;
    return v;
}

class Other
{
  public:
};

class TESSaveLoadGame
{
  public:
};


struct Thing
{
    Other* m_object;
    char m_data04[12];
    char m_data10[12];
    void Save();
};

// Saves the 12-byte data blocks and the form ID of m_object to the save stream via TESSaveLoadGame.
// @fnv 0x0043a930
void Thing::Save()
{
    reinterpret_cast<::FUN_008579b0_shell *>((::g_TESSaveLoadGame))->FUN_008579b0(m_data04, 0xc);
    reinterpret_cast<::FUN_008579b0_shell *>((::g_TESSaveLoadGame))->FUN_008579b0(m_data10, 0xc);
    int formID = 0;
    if (m_object != 0)
        formID = reinterpret_cast<::FUN_0084e3a0_Class *>((m_object))->FUN_0084e3a0();
    reinterpret_cast<::C857A10Buffer *>((::g_TESSaveLoadGame))->FUN_00857a10((const unsigned int *)(void *)(&formID), 4);
}


namespace s835fe0 {

struct RefHandle
{
    TESObjectREFR* m_pkRef;

    void ResolveRef(void* pvUnused);
};

// Replaces m_pkRef with the result of FUN_004839c0 cast to TESObjectREFR, or null if m_pkRef is null.
// @fnv 0x00835fe0
void RefHandle::ResolveRef(void* pvUnused)
{
    m_pkRef = m_pkRef ? dynamic_cast<TESObjectREFR*>(FUN_004839c0((unsigned int)m_pkRef)) : 0;
}

}

struct CoordinateTriple
{
    bool FUN_00527a00();
};

bool CoordinateTriple::FUN_00527a00()
{
    return false;
}

struct TESObjectREFR_ext : public TESObjectREFR
{
    bool GetReferencePersistence();
};

bool TESObjectREFR_ext::GetReferencePersistence()
{
    return false;
}

// Returns true when either called predicate is true; otherwise returns false.
// @fnv 0x009a96f0
bool FUN_009a96f0(TESObjectREFR* refr, CoordinateTriple* location)
{
    if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((((TESObjectREFR_ext*)refr)))->FUN_005653d0())
        return true;
    if (location->FUN_00527a00())
        return true;
    return false;
}

struct FUN_0043a590_shell : public TeleportableReference
{
    bool FUN_0043a590(TESForm*);
};


struct TeleportFormTypeName
{
    const char* name;
    int unk04;
    int unk08;
};


// Resolves the linked door, checks its form type, and resets position or rotation to zero when their checks fail.
// @fnv 0x0043a590
bool FUN_0043a590_shell::FUN_0043a590(TESForm* form)
{
    unsigned int formID = (unsigned int)m_pLinkedDoorReference;
    ::ResolveFormID(&formID, form->GetFile(-1));
    m_pLinkedDoorReference = dynamic_cast<TESObjectREFR*>(FUN_004839c0(formID));
    if (!m_pLinkedDoorReference)
    {
        ::FUN_005b5e40();
        return false;
    }
    if (reinterpret_cast<::TESForm *>((void *)(((TESFormTypeView*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_pLinkedDoorReference))->FUN_007af430())))))->GetFormType() != 0x1C)
    {
        ::FUN_005b5e40();
        m_pLinkedDoorReference = 0;
        return false;
    }
    if (!std::isfinite(position.x) || !std::isfinite(position.y) || !std::isfinite(position.z) ||
        std::isnan(position.x) || std::isnan(position.y) || std::isnan(position.z))
    {
        ::FUN_005b5e40();
        position = NiPoint3::ZERO;
    }
    if (!std::isfinite(rotation.x) || !std::isfinite(rotation.y) || !std::isfinite(rotation.z) ||
        std::isnan(rotation.x) || std::isnan(rotation.y) || std::isnan(rotation.z))
    {
        ::FUN_005b5e40();
        rotation = NiPoint3::ZERO;
    }
    return true;
}

#include "generated/data/fallout_shared/teleportdata.inc"
