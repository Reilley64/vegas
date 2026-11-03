// fallout_shared/packagetarget.cpp: PackageTargetRecord, LocationDescriptor, Script, SaveDataStub (21 functions)

#include <cstdint>
#include <cstring>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_0063f790_shell.h"
#include "fnv/decl/FUN_0067f140_shell.h"
#include "fnv/decl/FUN_0067f1c0_shell.h"
#include "fnv/decl/FUN_0067f1f0_shell.h"
#include "fnv/decl/FUN_0067f410_shell.h"
#include "fnv/decl/FUN_0067f430_shell.h"
#include "fnv/decl/FUN_0067f460_shell.h"
#include "fnv/decl/FUN_0067f4b0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_0067ff10__FUN_0067ff10_Class.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011de000.h"
#include "Script.h"
#include "packagetarget_decls.h"
#include "packagetarget_types_PackageLocation.h"
#include "packagetarget_types_PACK_TARG_TYPE.h"
#include "packagetarget_types_PackageTarget.h"

// @fnv 0x00519b00
int PackageTargetRecord::GetTargetKind()
{
    return (PACK_TARG_TYPE)m_uiTargetType;
}

// @fnv 0x006800b0
void PackageTargetRecord::SetTargetKind(PACK_TARG_TYPE aeTargetType)
{
    if (m_uiTargetType != aeTargetType)
    {
        m_uiTargetType = (unsigned char)aeTargetType;
        switch (m_uiTargetType)
        {
        case PACK_TARG_TYPE_PTT_REFERENCE:
            m_pWorldReferenceInfo = 0;
            break;
        case PACK_TARG_TYPE_PTT_OBJECT:
            m_pWorldReferenceInfo = 0;
            break;
        case PACK_TARG_TYPE_PTT_TYPE:
            m_pWorldReferenceInfo = 0;
            break;
        }
    }
}

// Returns the target reference if the target type is PACK_TARG_TYPE_PTT_REFERENCE, otherwise returns null.
// @fnv 0x00680020
TESObjectREFR* PackageTargetRecord::GetReferenceTarget()
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_REFERENCE)
        return m_pWorldReferenceInfo;
    else
        return 0;
}

// If the package target type is PACK_TARG_TYPE_PTT_REFERENCE, stores the given reference as the target.
// @fnv 0x00680110
void PackageTargetRecord::SetTargetObjectReference(TESObjectREFR* reference)
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_REFERENCE)
        m_pWorldReferenceInfo = reference;
}

// Returns pObject when the target type is PACK_TARG_TYPE_PTT_OBJECT, otherwise returns null.
// @fnv 0x00680050
TESForm* PackageTargetRecord::GetTargetForm()
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_OBJECT)
        return pObject;
    else
        return 0;
}

// @fnv 0x00680080
PACKAGE_OBJECT_TYPE PackageTargetRecord::GetTargetObjectType()
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_TYPE)
        return eObjType;
    else
        return (PACKAGE_OBJECT_TYPE)0;
}

// Copies location data from source into this object when copy is set or source's location type is valid, dispatching on the location type.
// @fnv 0x0067f4d0
void LocationDescriptor::Copy(LocationDescriptor* source, bool copy)
{
    if (source != 0)
    {
        if (copy || source->GetLocType() != PACK_LOC_TYPE_INVALID)
        {
            reinterpret_cast<::FUN_0067f140_shell *>(this)->FUN_0067f140((*(int *)&(const ::PACK_LOC_TYPE &)(source->GetLocType())));
            switch (m_ucLocationType)
            {
            case 0:
                reinterpret_cast<::FUN_0067f1f0_shell *>(this)->FUN_0067f1f0(reinterpret_cast<::FUN_0067f1c0_shell *>((source))->FUN_0067f1c0());
                FUN_0067f3c0(source->GetLocationReference());
                break;
            case 1:
                reinterpret_cast<::FUN_0067f410_shell *>(this)->FUN_0067f410(source->GetLocationCellReference());
                break;
            case 4:
                reinterpret_cast<::FUN_0067f1f0_shell *>(this)->FUN_0067f1f0(reinterpret_cast<::FUN_0067f1c0_shell *>((source))->FUN_0067f1c0());
                reinterpret_cast<::FUN_0067f460_shell *>(this)->SetValue((int)((TESForm*)((::TESBoundObject *)(reinterpret_cast<::FUN_0067f430_shell *>((source))->GetLocationObject()))));
                break;
            case 5:
                reinterpret_cast<::FUN_0067f1f0_shell *>(this)->FUN_0067f1f0(reinterpret_cast<::FUN_0067f1c0_shell *>((source))->FUN_0067f1c0());
                reinterpret_cast<::FUN_0067f4b0_class *>(this)->FUN_0067f4b0((*(int *)&(const ::PACKAGE_OBJECT_TYPE &)(source->GetObjectType())));
                break;
            case 2:
            case 3:
            case 7:
                reinterpret_cast<::FUN_0067f1f0_shell *>(this)->FUN_0067f1f0(reinterpret_cast<::FUN_0067f1c0_shell *>((source))->FUN_0067f1c0());
                break;
            case 6:
                reinterpret_cast<::FUN_0067f1f0_shell *>(this)->FUN_0067f1f0(reinterpret_cast<::FUN_0067f1c0_shell *>((source))->FUN_0067f1c0());
                break;
            }
        }
    }
}

// @fnv 0x00671d10
char* Script::GetData()
{
    return m_data;
}

// Resolves the stored form ID against the owner's file and looks up the package target reference or object, warning if it is missing.
// @fnv 0x006803b0
void PackageTargetRecord::InitItem(TESForm* owner)
{
    std::uintptr_t formID = (std::uintptr_t)pTargetForm;
    ::ResolveFormID((unsigned int *)&(formID), owner->GetFile(-1));
    switch (m_uiTargetType)
    {
    case 0:
        m_pWorldReferenceInfo = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(formID));
        if (!m_pWorldReferenceInfo)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            else
                ::FUN_005b5e40();
        }
        break;
    case 1:
        pObject = ::FUN_004839c0(formID);
        if (!pObject)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            else
                ::FUN_005b5e40();
        }
        break;
    }
}

// Sets the byte at pThis to 2 and zeroes the int, int and float fields at offsets 4, 8 and 12, then returns pThis.
// @fnv 0x0067ff70
void* FUN_0067ff70(void* pThis)
{
    *(unsigned char*)pThis = 2;
    *((int*)pThis + 1) = 0;
    *((int*)pThis + 2) = 0;
    *((float*)pThis + 3) = 0.0f;
    return pThis;
}

struct PTFile
{
    unsigned char m_uiTargetType;
    char pad[3];
    unsigned int iFormID;
    int iValue;
    float m_fTargetValue;
};
struct FUN_0067ffa0_cls
{
    unsigned char m_uiTargetType;
    char pad[3];
    unsigned int ref;
    FUN_0067ffa0_cls* LoadFromPTFile(PTFile* f);
};
// @fnv 0x0067ffa0
FUN_0067ffa0_cls* FUN_0067ffa0_cls::LoadFromPTFile(PTFile* apFile)
{
    reinterpret_cast<::PackageTargetRecord *>(this)->SetTargetKind((::PACK_TARG_TYPE)(apFile->m_uiTargetType));
    reinterpret_cast<::TESRegionGrassObject *>(this)->AssignLandTexture((::TESLandTexture *)(apFile->iValue));
    reinterpret_cast<::FUN_0063f790_shell *>(this)->FUN_0063f790(apFile->m_fTargetValue);
    switch (m_uiTargetType)
    {
    case 0:
    case 1:
        ref = apFile->iFormID;
        break;
    case 2:
        ref = apFile->iFormID;
        break;
    }
    return this;
}

struct FUN_00680140_shell : public PackageTargetRecord
{
    void SetObjectTarget(TESForm*);
};

// If the package target type is PTT_OBJECT, stores apObj in pObject.
// @fnv 0x00680140
void FUN_00680140_shell::SetObjectTarget(TESForm* apObj)
{
    if (GetTargetKind() == PACK_TARG_TYPE_PTT_OBJECT)
        pObject = apObj;
}

struct ArrSI
{
};

struct Twin_0084d030
{
    float GetStoredFloatValue(void);
};

struct FUN_00680220_shell : PackageTargetRecord
{
    bool Compare(PackageTargetRecord* apCompare);
};

// Returns true if apCompare is null or any of the compared values differ; returns false when all compared values match.
// @fnv 0x00680220
bool FUN_00680220_shell::Compare(PackageTargetRecord* apCompare)
{
    if (apCompare == 0)
        return true;
    if (this->GetTargetKind() != apCompare->GetTargetKind())
        return true;
    if (this->GetReferenceTarget() != apCompare->GetReferenceTarget())
        return true;
    if (this->GetTargetForm() != apCompare->GetTargetForm())
        return true;
    if (this->GetTargetObjectType() != apCompare->GetTargetObjectType())
        return true;
    if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName())) != ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)apCompare)))->GetName())))
        return true;
    if (((Twin_0084d030*)this)->GetStoredFloatValue() != ((Twin_0084d030*)apCompare)->GetStoredFloatValue())
        return true;
    return false;
}

struct ChunkPayload16
{
};
struct FormValueEntry
{
    unsigned char m_uiTargetType;
    unsigned int iFormID;
    int iValue;
    float m_fTargetValue;
};
struct FUN_006802f0_shell : PackageTargetRecord
{
    void FUN_006802f0(int chunk);
};

// @fnv 0x006802f0
void FUN_006802f0_shell::FUN_006802f0(int chunk)
{
    FormValueEntry record;
    memset(&record, 0, 16);
    record.iValue = this->iValue;
    record.m_fTargetValue = this->m_fTargetValue;
    record.m_uiTargetType = this->m_uiTargetType;
    switch (this->m_uiTargetType)
    {
    case 2:
        record.iFormID = this->GetTargetObjectType();
        break;
    case 0:
    case 1:
        if (this->pObject)
            record.iFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->pObject))->FUN_0084e3a0()));
        break;
    }
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_0067ff10::FUN_0067ff10_Class *>((((ChunkPayload16*)&record)))->FUN_0067ff10();
    ::AppendChunk(chunk, &record, 16);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_0067ff10::FUN_0067ff10_Class *>((((ChunkPayload16*)&record)))->FUN_0067ff10();
}

struct FUN_00680520_cls : public PackageTargetRecord
{
    unsigned short FUN_00680520();
};

// @fnv 0x00680520
unsigned short FUN_00680520_cls::FUN_00680520()
{
    unsigned short usSize = 0;
    usSize += 1;
    usSize += 4;
    usSize += 4;
    switch (m_uiTargetType)
    {
    case 3:
        break;
    case 0:
    case 1:
        usSize += 4;
        break;
    case 2:
        usSize += 4;
        break;
    default:;
    }
    return usSize;
}

// Save-game write of a target record: type byte, two values, then the type-specific target.

class C80720Form;

class C80720SaveBuffer
{
  public:
};

class C80720Target
{
  public:
    unsigned char m_ucType;
    union
    {
        C80720Form* m_pkForm;
        int m_iValue;
    };
    int m_iData1;
    int m_iData2;

    void SaveToBuffer(C80720SaveBuffer* pkBuffer);
};

// Writes the type byte, m_iData1 and m_iData2 to the buffer, then saves the form, value or nothing depending on m_ucType.
// @fnv 0x00680720
void C80720Target::SaveToBuffer(C80720SaveBuffer* pkBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(this, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_iData1, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_iData2, 4, 0);
    switch (m_ucType)
    {
        break;
    case 0:
    case 1:
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pkBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pkForm), 0);
        break;
    case 2:
        reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&m_iValue, 4, 0);
        break;
    }
}

struct S_006807b0_Stream
{
};
struct S_006807b0_Target : PackageTargetRecord
{
    void FUN_006807b0(S_006807b0_Stream* s);
};
// @fnv 0x006807b0
void S_006807b0_Target::FUN_006807b0(S_006807b0_Stream* pStream)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pStream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(this), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pStream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iValue), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pStream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fTargetValue), 4);
    switch (m_uiTargetType)
    {
        break;
    case 0:
    case 1:
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((pStream))->FUN_008648e0((unsigned int *)(void *)(&pTargetForm));
        break;
    case 2:
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pStream))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pTargetForm), 4);
        break;
    }
}

struct FUN_00680830_shell : PackageTargetRecord
{
    void FUN_00680830(void* unused);
};

// @fnv 0x00680830
void FUN_00680830_shell::FUN_00680830(void* unused)
{
    switch (m_uiTargetType)
    {
    case PACK_TARG_TYPE_PTT_REFERENCE:
    case PACK_TARG_TYPE_PTT_OBJECT:
        pTargetForm = pTargetForm ? ::FUN_004839c0((unsigned int)pTargetForm) : 0;
        break;
    }
}

struct C680590Form
{
};

struct TESSaveLoadGame
{
};


struct C680590Target
{
    unsigned char m_ucType;
    union
    {
        C680590Form* m_pkForm;
        int m_iValue;
    };
    int m_iData1;
    int m_iData2;

    void SaveLoad();
};

// @fnv 0x00680590
void C680590Target::SaveLoad()
{
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&m_ucType, 1);
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&m_iData1, 4);
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&m_iData2, 4);

    switch (m_ucType)
    {
        break;
    case 0:
    case 1: {
        unsigned int uiResult = 0;
        if (m_pkForm)
        {
            uiResult = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pkForm))->FUN_0084e3a0()));
        }
        reinterpret_cast<::C857A10Buffer *>((g_TESSaveLoadGame))->FUN_00857a10((const unsigned int *)(&uiResult), 4);
    }
    break;
    case 2:
        reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&m_iValue, 4);
        break;
    }
}


struct FUN_006806e0_target : PackageTargetRecord
{
    void ResolveTargetForm();
};

// For reference or object target types, replaces pTargetForm with the TESForm resolved from its formID via FUN_004839c0.
// @fnv 0x006806e0
void FUN_006806e0_target::ResolveTargetForm()
{
    switch (m_uiTargetType)
    {
    case PACK_TARG_TYPE_PTT_REFERENCE:
    case PACK_TARG_TYPE_PTT_OBJECT:
        unsigned int formID = reinterpret_cast<unsigned int>(pTargetForm);
        pTargetForm = FUN_004839c0(formID);
    }
}

struct SaveLoadStub
{
};
struct SaveDataStub
{
    unsigned char type;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00680640();
};
// @fnv 0x00680640
void SaveDataStub::FUN_00680640()
{
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(this, 1);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&unk08, 4);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&unk0C, 4);
    switch (type)
    {
        break;
    case 0:
    case 1: {
        int value;
        reinterpret_cast<::FUN_00857aa0 *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->ValidateFormIDArray((unsigned int *)(void *)(&value), 4);
        unk04 = value;
    }
    break;
    case 2:
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&unk04, 4);
        break;
    }
}
