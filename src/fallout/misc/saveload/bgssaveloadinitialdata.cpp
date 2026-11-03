// fallout/misc/saveload/bgssaveloadinitialdata.cpp: BGSSaveLoadInitialDataPacket, ReferencePlacementData, BGSNumericIDIndex3 (20 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0041d390_shell.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_0046a010_shell.h"
#include "fnv/decl/FUN_004fe1d0_cls.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0063ef00_Class.h"
#include "fnv/decl/FUN_0084a580_shell.h"
#include "fnv/decl/FUN_0084e340_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0084e3c0_Class.h"
#include "fnv/decl/FUN_0084e420_class.h"
#include "fnv/decl/FUN_0084e460_t.h"
#include "fnv/decl/FUN_0084e4f0_cls.h"
#include "fnv/decl/FUN_0084e580_class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/FormIDConverter.h"
#include "fnv/decl/HandlerView.h"
#include "fnv/decl/Holder0084.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/SLGame84a880.h"
#include "fnv/decl/SaveLoadFile.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00546b10__FUN_00546b10_class.h"
#include "fnv/decl/fnv_00562de0__FUN_00562de0_cls.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00565480__RefPersistsStandin.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0084a810__FUN_0084a810_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00421000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00562000.h"
#include "fnv/symbols_00564000.h"
#include "fnv/symbols_00573000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_00846000.h"
#include "fnv/symbols_0084e000.h"
#include "fnv/symbols_0084f000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "bgssaveloadinitialdata_packet.h"

// @fnv 0x0084e700
INITIAL_DATA_TYPE BGSSaveLoadInitialDataPacket::DetermineInitialDataType(TESForm* apForm, FormChangeMask eChangeFlags)
{
    return DetermineInitialDataType(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apForm))->FUN_0084e3a0())), apForm->GetFormType(), eChangeFlags);
}

// @fnv 0x00849280
ReferencePlacementData::ReferencePlacementData()
{}

// @fnv 0x0084e610
bool ReferencePlacementData::GetCellAndWorld(TESObjectCELL*& apCell, TESWorldSpace*& apWorld)
{
    bool bResult;
    TESForm* apForm = ::FUN_004839c0(m_uiLocationFormID);
    bResult = GetCellAndWorldspaceForForm(apForm, apCell, apWorld);
    if (apWorld)
    {
        int x = ::FUN_00406d90(Location.x) >> 12;
        int y = ::FUN_00406d90(Location.y) >> 12;
        apCell = apWorld->GetCellAtGridPosition(x, y);
    }
    return bResult;
}

unsigned int __cdecl FUN_0084e830(int);

// @fnv 0x0084e800
unsigned int __cdecl FUN_0084e800(int aeType)
{
    unsigned int isize = FUN_0084e830(aeType);
    isize += 1;
    return isize;
}

unsigned int __cdecl FUN_0084e830(int);
int __cdecl FUN_0084e930(void*, int, void*);

struct BGSLoadFormBuffer_Accessor : public BGSLoadFormBuffer
{
};

// If aeType is non-zero, reads isize bytes from apFile into pbuffer and passes them with aeType and apInitialDataBuffer to FUN_0084e930; returns 0 for aeType 0.
// @fnv 0x0084e8c0
int __cdecl LoadFormData(BGSLoadFormBuffer* apFile, int aeType, void* apInitialDataBuffer)
{
    unsigned int isize;
    char pbuffer[128];

    if (aeType == 0)
        return 0;

    isize = FUN_0084e830(aeType);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((BGSLoadFormBuffer_Accessor*)apFile)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(pbuffer), isize);
    return FUN_0084e930(pbuffer, aeType, apInitialDataBuffer);
}

extern bool DAT_011a2231[];

// @fnv 0x0084f840
bool __cdecl FUN_0084f840(int aeType)
{
    return DAT_011a2231[aeType * 3];
}

extern bool DAT_011a2232[];

// @fnv 0x0084f860
bool __cdecl FUN_0084f860(int aeType)
{
    return DAT_011a2232[aeType * 3];
}

struct BGSNumericIDIndex3
{
    unsigned char a;
    unsigned char b;
    unsigned char c;
};
// Sets the three bytes of the BGSNumericIDIndex3 to zero and returns the object.
// @fnv 0x0084eaf0
BGSNumericIDIndex3* ClearNumericIDIndex(BGSNumericIDIndex3* self)
{
    self->a = 0;
    self->b = 0;
    self->c = 0;
    return self;
}

namespace fnv_0084eb20 {
struct BGSNumericIDIndex3
{
    BGSNumericIDIndex3* FUN_0084eb20();
    void FUN_0084eac0();
};
struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};

// Calls FUN_0084eac0 on this object, then ClearNumericIDIndex on the sub-object at offset 0x1C, and returns this.
// @fnv 0x0084eb20
BGSNumericIDIndex3* BGSNumericIDIndex3::FUN_0084eb20()
{
    FUN_0084eac0();
    ((Dummy84eaf0*)((char*)this + 0x1C))->ClearNumericIDIndex();
    return this;
}
}  // namespace fnv_0084eb20

struct FUN_0084f880_shell
{
    int m_kPointA;                // +0x00
    int m_kPointB;                // +0x04
    int m_iThirdValue;                // +0x08
    int m_iFourthElementInteger;                // +0x0C
    int m_usTrailingValue;  // +0x10
    int m_f;                // +0x14
    int m_g;                // +0x18
    int m_h;                // +0x1C
    int m_i;                // +0x20
    int m_iUnknownValue;    // +0x24
    unsigned int m_flags;   // +0x28
    void SetFlag10(bool value);
};

// Sets or clears bit 0x10 in m_flags according to value.
// @fnv 0x0084f880
void FUN_0084f880_shell::SetFlag10(bool abSet)
{
    if (abSet)
        m_flags |= 0x10;
    else
        m_flags &= ~0x10;
}

struct FUN_0084f8c0_shell
{
    void FUN_0084f8c0(void* value);
};
// Loads a cell or reference change record from the save buffer and applies its location, angle and cell/worldspace to the form.
// @fnv 0x0084f330
INITIAL_DATA_TYPE BGSSaveLoadInitialDataPacket::LoadInitialDataForForm(BGSLoadFormBuffer* apBuffer, TESForm* apForm,
                                                                       FormChangeMask eChangeFlags)
{
    INITIAL_DATA_TYPE eType = DetermineInitialDataType(apForm, eChangeFlags);
    if (::FUN_0084f860((*(int *)&(eType))))
    {
        CellDetachTimeData kCellData;
        LoadFormData(apBuffer, eType, &kCellData);
        TESObjectCELL* pLocationCell = (TESObjectCELL*)apForm;
        reinterpret_cast<::fnv_00546b10::FUN_00546b10_class *>((pLocationCell))->UpdateCellExtraData((::BSExtraData *)(kCellData.m_uiDetachTime), true);
    }
    else if (::FUN_0084f840((*(int *)&(eType))))
    {
        ReferencePlacementData kRefData;
        LoadFormData(apBuffer, eType, &kRefData);
        TESWorldSpace* pWorld = 0;
        TESObjectCELL* pLocationCell = 0;
        kRefData.GetCellAndWorld(pLocationCell, pWorld);
        TESObjectREFR* m_pWorldReferenceInfo = (TESObjectREFR*)apForm;
        switch (eType)
        {
        case INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE: {
            TESBoundObject* pBound =
                dynamic_cast<TESBoundObject*>(::FUN_004839c0(kRefData.m_uiBaseFormID));
            if (kRefData.m_ucFlags & 4)
            {
                reinterpret_cast<::Reference *>((m_pWorldReferenceInfo))->FUN_00575830((::Position *)&(kRefData.Location));
                m_pWorldReferenceInfo->SetReferencePosition(kRefData.Angle);
                if (pLocationCell)
                    m_pWorldReferenceInfo->vfn_228(pLocationCell);
                else if (pWorld)
                    reinterpret_cast<::FUN_0041d390_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((m_pWorldReferenceInfo))->FUN_005d43c0()))))->FUN_0041d390(((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((pWorld))->GetPrevPath())));
            }
            else
            {
                reinterpret_cast<::HandlerView *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->PlaceObjectReference(pBound, (::NiPoint3 *)&(kRefData.Location), (::NiPoint3 *)&(kRefData.Angle), pLocationCell,
                                                        pWorld, m_pWorldReferenceInfo, (const char *)(::BGSPrimitive *)(0), (::TESForm *)(void *)(0));
            }
            if (!pLocationCell && !pWorld)
            {
                ::FUN_00845cc0(DAT_0107f938, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWorldReferenceInfo))->FUN_0084e3a0())), kRefData.m_uiBaseFormID,
                           pBound ? ((const char *)(reinterpret_cast<::FUN_00440e30_This *>((pBound))->FUN_00440e30())) : DAT_01015890);
                reinterpret_cast<::FUN_0046a010_shell *>((m_pWorldReferenceInfo))->FUN_0046a010(0);
                reinterpret_cast<::Holder0084 *>((::g_BGSSaveLoadGame))->CallVirtualWithOne((::Fake0084 *)(m_pWorldReferenceInfo));
                ((TESRecipe*)apBuffer)->SetRequiredSkill((::ActorValue::Index)(0));
                return eType;
            }
            ::fnv_00562020::FUN_00562020((::TESObjectREFR *)(m_pWorldReferenceInfo));
            if (m_pWorldReferenceInfo->IsActor())
                reinterpret_cast<::FUN_0084a580_shell *>((::g_BGSSaveLoadGame))->RemoveActorFromMap((::Actor *)(m_pWorldReferenceInfo));
            break;
        }
        case INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION:
        case INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE:
            if (m_pWorldReferenceInfo == ::_g_thePlayer)
            {
                if (!reinterpret_cast<::FUN_0063ef00_Class *>((::g_BGSSaveLoadGame))->FUN_0063ef00())
                {
                    m_pWorldReferenceInfo->SetReferencePosition(kRefData.Angle);
                    reinterpret_cast<::Reference *>((m_pWorldReferenceInfo))->FUN_00575830((::Position *)&(kRefData.Location));
                }
            }
            else
            {
                m_pWorldReferenceInfo->SetReferencePosition(kRefData.Angle);
                reinterpret_cast<::Reference *>((m_pWorldReferenceInfo))->FUN_00575830((::Position *)&(kRefData.Location));
            }
            ::fnv_00562020::FUN_00562020((::TESObjectREFR *)(m_pWorldReferenceInfo));
            if (m_pWorldReferenceInfo != ::_g_thePlayer)
            {
                if (pLocationCell && pLocationCell->IsCellInterior())
                {
                    if (pLocationCell != ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((m_pWorldReferenceInfo))->GetTarget())))
                        ::fnv_00573800::FUN_00573800((::fnv_00573800::MoveRef *)(m_pWorldReferenceInfo), (::fnv_00573800::MoveCell *)(pLocationCell), (::fnv_00573800::MoveWorld *)(::TESWorldSpace *)(0));
                }
                else if (pWorld)
                {
                    if ((pLocationCell && (pLocationCell == ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((m_pWorldReferenceInfo))->GetTarget())) ||
                                           reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->IsCellBuffered(pLocationCell, false))) ||
                        reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((m_pWorldReferenceInfo))->FUN_005653d0())
                    {
                        if (!pLocationCell || pLocationCell != ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((m_pWorldReferenceInfo))->GetTarget())))
                            ::fnv_00573800::FUN_00573800((::fnv_00573800::MoveRef *)(m_pWorldReferenceInfo), (::fnv_00573800::MoveCell *)(::TESObjectCELL *)(0), (::fnv_00573800::MoveWorld *)(pWorld));
                    }
                    else
                    {
                        ::FUN_00845cc0(DAT_0107f8d0, m_pWorldReferenceInfo->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWorldReferenceInfo))->FUN_0084e3a0())), pWorld->GetName(),
                                   ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pWorld))->FUN_0084e3a0())));
                        reinterpret_cast<::FUN_0084f880_shell *>((apBuffer))->SetFlag10(1);
                    }
                }
                else
                {
                    ::FUN_00845cc0(DAT_0107f894, kRefData.m_uiLocationFormID, m_pWorldReferenceInfo->GetName(),
                               ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pWorldReferenceInfo))->FUN_0084e3a0())));
                }
                if (m_pWorldReferenceInfo->vfn_1d0() && (!pLocationCell || !reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->IsCellBuffered(pLocationCell, false)))
                {
                    m_pWorldReferenceInfo->vfn_1cc(0, 0);
                }
                else if (m_pWorldReferenceInfo->vfn_1d0() && m_pWorldReferenceInfo->IsActor())
                {
                    m_pWorldReferenceInfo->vfn_1c4();
                }
            }
            if (m_pWorldReferenceInfo->IsActor())
            {
                TESObjectREFR* pActor = m_pWorldReferenceInfo;
                reinterpret_cast<::FUN_0084a580_shell *>((::g_BGSSaveLoadGame))->RemoveActorFromMap((::Actor *)(pActor));
                if (eType == INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE && !pActor->vfn_290())
                {
                    TESForm* pOriginal = ::FUN_004839c0(kRefData.m_uiOriginalBaseFormID);
                    reinterpret_cast<::FUN_0084f8c0_shell *>((pActor))->FUN_0084f8c0(pOriginal);
                }
            }
            break;
        }
        if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>(&(eChangeFlags))->FUN_004280f0(4))
            reinterpret_cast<::fnv_0084a810::FUN_0084a810_shell *>((::g_BGSSaveLoadGame))->FUN_0084a810(2, (::fnv_0084a810::BGSLoadFormBuffer *)(apBuffer), (::TESForm *)(0));
    }
    else if (eType != INITIAL_DATA_TYPE_INITIAL_DATA_NONE)
    {
        ::FUN_00845cc0(DAT_0107f86c, eType);
    }
    return eType;
}

// @fnv 0x0084f8c0
void FUN_0084f8c0_shell::FUN_0084f8c0(void* value)
{
    *(void**)((char*)this + 0x170) = value;
}

struct FUN_0084e6a0_shell
{
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    bool FUN_0084e6a0(TESObjectCELL*& cell, TESWorldSpace*& world);
};

// @fnv 0x0084e6a0
bool FUN_0084e6a0_shell::FUN_0084e6a0(TESObjectCELL*& cell, TESWorldSpace*& world)
{
    TESForm* form = ::FUN_004839c0(f8);
    bool bResolved = GetCellAndWorldspaceForForm(form, cell, world);
    if (world)
    {
        cell = reinterpret_cast<TESWorldSpace*>(world)->GetCellAtGridPosition(fC, f10);
    }
    return bResolved;
}

extern "C" char DAT_011a2230[];

// @fnv 0x0084e830
unsigned int FUN_0084e830(int aiIndex)
{
    return (unsigned char)DAT_011a2230[aiIndex * 3];
}

struct Dummy84eaf0
{
    void ClearNumericIDIndex();
    char _pad[3];
};
struct S84eac0
{
    char _pad[12];
};
struct Outer84eac0 : Dummy84eaf0
{
    S84eac0 m1;
    S84eac0 m2;
    Outer84eac0* FUN_0084eac0();
};
// Calls ClearNumericIDIndex, then invokes _ref_006815c0 on m1 and m2, and returns this.
// @fnv 0x0084eac0
Outer84eac0* Outer84eac0::FUN_0084eac0()
{
    Dummy84eaf0::ClearNumericIDIndex();
    return this;
}

namespace fnv_0084eb50 {
struct Dummy84eaf0
{
    void ClearNumericIDIndex();
};
struct Base84eac0
{
};
struct S84eb50
{
    char _pad[0x1B];
    Dummy84eaf0 m;
    S84eb50* FUN_0084eb50();
};
// Calls the base FUN_0084eac0, then calls ClearNumericIDIndex on member m, and returns this.
// @fnv 0x0084eb50
S84eb50* S84eb50::FUN_0084eb50()
{
    reinterpret_cast<::Outer84eac0 *>((((Base84eac0*)this)))->FUN_0084eac0();
    m.ClearNumericIDIndex();
    return this;
}
}  // namespace fnv_0084eb50

class GameFileBuf
{
  public:
};

unsigned int __cdecl FUN_0084e800(int aeType);
int __cdecl FUN_0084e930(void* apBuffer, int aeType, void* apInitialDataBuffer);

// @fnv 0x0084e850
unsigned int __cdecl FUN_0084e850(GameFileBuf* apFile, int aeType, void* apInitialDataBuffer)
{
    char acBuffer[128];
    if (aeType == 0)
    {
        return 0;
    }
    volatile unsigned int uiModule3 = FUN_0084e800(aeType);
    reinterpret_cast<::SaveLoadFile *>((apFile))->Read(acBuffer, uiModule3);
    return (unsigned int)FUN_0084e930(acBuffer, aeType, apInitialDataBuffer);
}

struct ReferenceAccess
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual bool IsReference();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void SetFormID(unsigned int, bool);
};
struct DataHandlerAccess
{
};
struct SaveLoadAccess
{
};
struct ProjectileAccess
{
};
struct ExtraAccess
{
};
struct FUN_009abf30 : TESObjectREFR
{
    FUN_009abf30();
    unsigned int unk04;
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
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
};
extern const char DAT_0107fa20[];
extern const char DAT_0107f9b8[];

// @fnv 0x0084f8e0
TESForm* __cdecl ResolveReferenceForm(unsigned int formID, ReferencePlacementData* data, TESForm* existing)
{
    TESForm* form = existing;
    {
        unsigned char flags;
        {
            if (!form)
                form = FUN_004839c0(formID);
            if (reinterpret_cast<::BSShaderRenderUtility *>((((DataHandlerAccess*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->IsRenderTargetId(data->m_uiBaseFormID))
                data->m_uiBaseFormID = 0;
            TESBoundObject* bound = dynamic_cast<TESBoundObject*>(FUN_004839c0(data->m_uiBaseFormID));
            if (!bound)
            {
                FUN_00845cc0(DAT_0107fa20, data->m_uiBaseFormID, formID);
                return 0;
            }
            if (form)
            {
                bool remove = false;
                if (!((ReferenceAccess*)form)->IsReference())
                    remove = true;
                else
                {
                    ReferenceAccess* ref = (ReferenceAccess*)form;
                    {
                        TESBoundObject* current = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
                        if (current != bound)
                        {
                            if (!ref->IsActor() || ((::TESBoundObject *)(::FUN_004216f0((::BaseExtraList *)(((ExtraAccess*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))))) != bound)
                                remove = true;
                        }
                    }
                }
                if (remove)
                {
                    reinterpret_cast<::SLGame84a880 *>((((SaveLoadAccess*)::g_BGSSaveLoadGame)))->FUN_0084a880(form);
                    form = 0;
                }
            }
            flags = data->m_ucFlags;
            if (!form)
            {
                TESObjectREFR* created = 0;
                {
                    int type = 58;
                    switch (bound->GetFormType())
                    {
                    case ENUM_FORM_ID_CREA_ID:
                        type = 60;
                        break;
                    case ENUM_FORM_ID_NPC__ID:
                        type = 59;
                        break;
                    case ENUM_FORM_ID_PROJ_ID: {
                        ProjectileAccess* projectile = (ProjectileAccess*)bound;
                        type = reinterpret_cast<::FUN_004fe1d0_cls *>((projectile))->GetKindCode();
                        break;
                    }
                    case ENUM_FORM_ID_EXPL_ID:
                        created = new FUN_009abf30;
                        break;
                    }
                    if (flags & 4)
                        type = 22;
                    if (flags & 3)
                    {
                        if (!created)
                            created = FUN_00564480((unsigned char)type, true);
                        reinterpret_cast<::Fn575690 *>((((ReferenceAccess*)created)))->FUN_00575690(bound);
                        ((ReferenceAccess*)created)->SetFormID(formID, true);
                        form = created;
                    }
                    else
                        FUN_00845cc0(DAT_0107f9b8, flags, formID, data->m_uiBaseFormID, data->m_uiLocationFormID);
                }
            }
            if (form && (flags & 2))
            {
                ReferenceAccess* deleted = (ReferenceAccess*)form;
                reinterpret_cast<::fnv_00565480::RefPersistsStandin *>((deleted))->FUN_00565480(true);
            }
            if (form)
                reinterpret_cast<::FUN_0046a010_shell *>((((TESObjectREFR*)form)))->FUN_0046a010(1);
        }
    }
    return form;
}


class BGSSaveFormBuffer
{
  public:
};

struct BGSSaveLoadGame_Accessor : public BGSSaveLoadGame
{
};

struct BGSSaveLoadGame_SubAccessor
{
};

struct FUN_00853570_shell
{
    void WriteFormIDBytes(unsigned int);
};

struct FUN_00546af0_shell
{
    unsigned int FUN_00546af0();
};

struct TESObjectCELL_Accessor : public TESObjectCELL
{
};

struct StandaloneREFR
{
    virtual void _v_0();
    virtual void _v_4();
    virtual void _v_8();
    virtual void _v_c();
    virtual void _v_10();
    virtual void _v_14();
    virtual void _v_18();
    virtual void _v_1c();
    virtual void _v_20();
    virtual void _v_24();
    virtual void _v_28();
    virtual void _v_2c();
    virtual void _v_30();
    virtual void _v_34();
    virtual void _v_38();
    virtual void _v_3c();
    virtual void _v_40();
    virtual void _v_44();
    virtual void _v_48();
    virtual void _v_4c();
    virtual void _v_50();
    virtual void _v_54();
    virtual void _v_58();
    virtual void _v_5c();
    virtual void _v_60();
    virtual void _v_64();
    virtual void _v_68();
    virtual void _v_6c();
    virtual void _v_70();
    virtual void _v_74();
    virtual void _v_78();
    virtual void _v_7c();
    virtual void _v_80();
    virtual void _v_84();
    virtual void _v_88();
    virtual void _v_8c();
    virtual void _v_90();
    virtual void _v_94();
    virtual void _v_98();
    virtual void _v_9c();
    virtual void _v_a0();
    virtual void _v_a4();
    virtual void _v_a8();
    virtual void _v_ac();
    virtual void _v_b0();
    virtual void _v_b4();
    virtual void _v_b8();
    virtual void _v_bc();
    virtual void _v_c0();
    virtual void _v_c4();
    virtual void _v_c8();
    virtual void _v_cc();
    virtual void _v_d0();
    virtual void _v_d4();
    virtual void _v_d8();
    virtual void _v_dc();
    virtual void _v_e0();
    virtual void _v_e4();
    virtual void _v_e8();
    virtual void _v_ec();
    virtual bool vfn_f0();
    virtual void _v_f4();
    virtual void _v_f8();
    virtual bool vfn_fc();
    virtual bool IsActor();
    virtual void _v_104();
    virtual void _v_108();
    virtual void _v_10c();
    virtual void _v_110();
    virtual void _v_114();
    virtual void _v_118();
    virtual void _v_11c();
    virtual void _v_120();
    virtual void _v_124();
    virtual void _v_128();
    virtual void _v_12c();
    virtual const char* GetName();
    virtual void _v_134();
    virtual bool vfn_138(NiPoint3&, NiPoint3&, TESForm*&, bool);
    virtual void _v_13c();
    virtual void _v_140();
    virtual void _v_144();
    virtual void _v_148();
    virtual void _v_14c();
    virtual void _v_150();
    virtual void _v_154();
    virtual void _v_158();
    virtual void _v_15c();
    virtual void _v_160();
    virtual void _v_164();
    virtual void _v_168();
    virtual void _v_16c();
    virtual void _v_170();
    virtual void _v_174();
    virtual void _v_178();
    virtual void _v_17c();
    virtual void _v_180();
    virtual void _v_184();
    virtual void _v_188();
    virtual void _v_18c();
    virtual void _v_190();
    virtual void _v_194();
    virtual void _v_198();
    virtual void _v_19c();
    virtual void _v_1a0();
    virtual void _v_1a4();
    virtual void _v_1a8();
    virtual void _v_1ac();
    virtual void _v_1b0();
    virtual void _v_1b4();
    virtual void _v_1b8();
    virtual void _v_1bc();
    virtual void _v_1c0();
    virtual void _v_1c4();
    virtual void _v_1c8();
    virtual void _v_1cc();
    virtual void* vfn_1d0();
    virtual void _v_1d4();
    virtual void _v_1d8();
    virtual void _v_1dc();
    virtual void _v_1e0();
    virtual void _v_1e4();
    virtual void _v_1e8();
    virtual void _v_1ec();
    virtual void _v_1f0();
    virtual NiPoint3* vfn_1f4();
};

class MobileObject
{
  public:
};

struct S_00422b90
{
    char* FUN_00422b90();
};

struct BGSSaveGameBuffer;
class FakeBGSLoadGameSubBuffer
{
  public:
public:
    void WriteToSaveGameBuffer(::BGSSaveGameBuffer *);
};

class CF845 : public FakeBGSLoadGameSubBuffer
{
  public:
    void* unk0;
    CF845(char*);
};

struct BGSChangeFlags_s
{
};


struct ExteriorCellCharData
{
    unsigned short worldID;
    char cellX;
    char cellY;
    unsigned int detachTime;
};

struct ExteriorCellShortData
{
    unsigned short worldID;
    short cellX;
    short cellY;
    unsigned short detachTimeLow;
    unsigned short detachTimeHigh;
};

struct Byte4
{
    unsigned char a, b, c, d;
};
struct Byte12
{
    Byte4 p0, p1, p2;
};

struct RefLocData
{
    unsigned char id0, id1, id2;
    Byte12 pos;
    Byte12 rot;
};

struct CreatedRefInitialData
{
    RefLocData base;
    unsigned char flags;
    unsigned char bound0, bound1, bound2;
    CreatedRefInitialData* FUN_0084eb20();
};

struct MovedRefInitialData
{
    RefLocData base;
    unsigned char orig0, orig1, orig2;
    short originalCellX;
    short originalCellY;
    MovedRefInitialData* FUN_0084eb50();
};

// Determines the initial-data type for a form, writes the matching cell or reference record to the save buffer, and optionally saves extra data.
// @fnv 0x0084eb80
INITIAL_DATA_TYPE __cdecl FUN_0084eb80(BGSSaveFormBuffer* apFile, TESForm* apForm, FormChangeMask eChangeFlags)
{
    INITIAL_DATA_TYPE eType = BGSSaveLoadInitialDataPacket::DetermineInitialDataType(apForm, eChangeFlags);
    switch (eType)
    {
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_CHAR: {
        ExteriorCellCharData data;
        TESObjectCELL_Accessor* cell = (TESObjectCELL_Accessor*)apForm;
        data.worldID = ((unsigned short)(reinterpret_cast<::FormIDConverter *>((((BGSSaveLoadGame_SubAccessor*)((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((BGSSaveLoadGame_Accessor*)::g_BGSSaveLoadGame)))->FUN_0084e3a0())))))->RegisterFormID(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<::TESObjectCELL *>((cell))->GetParentWorldSpace()))->FUN_0084e3a0())))));
        data.cellX = (char)((short)(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX()));
        data.cellY = (char)((short)(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY()));
        data.detachTime = ((FUN_00546af0_shell*)cell)->FUN_00546af0();
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50((void *)(&data), sizeof(data), 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_SHORT: {
        ExteriorCellShortData data;
        TESObjectCELL_Accessor* cell = (TESObjectCELL_Accessor*)apForm;
        data.worldID = ((unsigned short)(reinterpret_cast<::FormIDConverter *>((((BGSSaveLoadGame_SubAccessor*)((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((BGSSaveLoadGame_Accessor*)::g_BGSSaveLoadGame)))->FUN_0084e3a0())))))->RegisterFormID(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<::TESObjectCELL *>((cell))->GetParentWorldSpace()))->FUN_0084e3a0())))));
        data.cellX = ((short)(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX()));
        data.cellY = ((short)(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY()));
        *(unsigned int*)&data.detachTimeLow = ((FUN_00546af0_shell*)cell)->FUN_00546af0();
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50((void *)(&data), sizeof(data), 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_INTERIOR_CELL: {
        TESObjectCELL_Accessor* pCell = (TESObjectCELL_Accessor*)apForm;
        unsigned int detachTime = ((FUN_00546af0_shell*)pCell)->FUN_00546af0();
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50((void *)(&detachTime), sizeof(detachTime), 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION: {
        StandaloneREFR* pRefr = (StandaloneREFR*)apForm;
        TESForm* cell = (TESForm*)((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((pRefr))->FUN_00575d70()));
        if (!cell)
        {
            cell = (TESForm*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pRefr))->GetTarget()));
        }
        NiPoint3 pos3 = *((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((pRefr))->GetAddTopicList()));
        NiPoint3 rot_2 = *((::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((pRefr))->GetData()));
        if (!cell)
        {
            if (!pRefr->vfn_138(pos3, rot_2, cell, false))
            {
                cell = (TESForm*)((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((StandaloneREFR*)::_g_thePlayer))->FUN_00575d70()));
                if (!cell)
                {
                    cell = (TESForm*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((((StandaloneREFR*)::_g_thePlayer)))->GetTarget()));
                }
                pos3 = *((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((pRefr))->GetAddTopicList()));
                rot_2 = *((::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((pRefr))->GetData()));
            }
        }
        RefLocData refData;
        reinterpret_cast<::Outer84eac0 *>(&(refData))->FUN_0084eac0();
        ((FUN_00853570_shell*)&refData)->WriteFormIDBytes(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((cell))->FUN_0084e3a0())));
        *(NiPoint3*)&refData.pos = pos3;
        *(NiPoint3*)&refData.rot = rot_2;
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50((void *)(&refData), 0x1b, 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE: {
        StandaloneREFR* pRefr = (StandaloneREFR*)apForm;
        TESForm* kLoc = (TESForm*)((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((pRefr))->FUN_00575d70()));
        if (!kLoc)
        {
            kLoc = (TESForm*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pRefr))->GetTarget()));
        }
        CreatedRefInitialData createdRefData;
        createdRefData.FUN_0084eb20();
        ((FUN_00853570_shell*)&createdRefData)->WriteFormIDBytes(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((kLoc))->FUN_0084e3a0())));
        *(NiPoint3*)&createdRefData.base.pos = *pRefr->vfn_1f4();
        *(NiPoint3*)&createdRefData.base.rot = *((::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((pRefr))->GetData()));
        TESBoundObject* baseObject3 = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRefr))->FUN_007af430()));
        if (pRefr->IsActor() && reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((((BGSChangeFlags_s*)&eChangeFlags)))->FUN_004280f0(0x40000))
        {
            TESBoundObject* boundObj4 = ((::TESBoundObject *)(::FUN_004216f0((::BaseExtraList *)(::ExtraDataList *)(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((pRefr))->FUN_005d43c0()))))));
            if (boundObj4)
            {
                baseObject3 = boundObj4;
            }
        }
        ((FUN_00853570_shell*)&createdRefData.bound0)->WriteFormIDBytes(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((baseObject3))->FUN_0084e3a0())));
        createdRefData.flags = 1;
        if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((pRefr))->FUN_005653d0())
        {
            createdRefData.flags |= 2;
        }
        if (pRefr->vfn_fc())
        {
            StandaloneREFR* aTalkingRef = pRefr;
            if (((bool)(::FUN_00574900((const unsigned char *)(((MobileObject*)aTalkingRef))))))
            {
                createdRefData.flags |= 4;
            }
        }
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50((void *)(&createdRefData), 0x1f, 0);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE: {
        StandaloneREFR* pRefr = (StandaloneREFR*)apForm;
        TESForm* locMain = (TESForm*)((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((pRefr))->FUN_00575d70()));
        if (!locMain)
        {
            locMain = (TESForm*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pRefr))->GetTarget()));
        }
        NiPoint3 pos3 = *((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((pRefr))->GetAddTopicList()));
        NiPoint3 rot_2 = *((::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((pRefr))->GetData()));
        if (!locMain)
        {
            if (!pRefr->vfn_138(pos3, rot_2, locMain, false))
            {
                locMain = (TESForm*)((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((StandaloneREFR*)::_g_thePlayer))->FUN_00575d70()));
                if (!locMain)
                {
                    locMain = (TESForm*)((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((((StandaloneREFR*)::_g_thePlayer)))->GetTarget()));
                }
                pos3 = *((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((pRefr))->GetAddTopicList()));
                rot_2 = *((::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((pRefr))->GetData()));
            }
        }
        MovedRefInitialData movedRefDataTmp;
        movedRefDataTmp.FUN_0084eb50();
        ((FUN_00853570_shell*)&movedRefDataTmp)->WriteFormIDBytes(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((locMain))->FUN_0084e3a0())));
        *(NiPoint3*)&movedRefDataTmp.base.pos = pos3;
        *(NiPoint3*)&movedRefDataTmp.base.rot = rot_2;
        NiPoint3 editorPos;
        NiPoint3 editorRot5;
        TESForm* editorCell = 0;
        if (pRefr->vfn_138(editorPos, editorRot5, editorCell, false))
        {
            ((FUN_00853570_shell*)&movedRefDataTmp.orig0)->WriteFormIDBytes(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((editorCell))->FUN_0084e3a0())));
            movedRefDataTmp.originalCellX = (short)(::FUN_00406d90(editorPos.x) >> 12);
            movedRefDataTmp.originalCellY = (short)(::FUN_00406d90(editorPos.y) >> 12);
        }
        else
        {
            movedRefDataTmp.originalCellX = 0;
            movedRefDataTmp.originalCellY = 0;
            FUN_00845cc0("EDITOR: Could not get editor location for reference '%s' (%08X) of type '%s' (%08X)",
                         pRefr->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pRefr))->FUN_0084e3a0())), ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRefr))->FUN_007af430()))->GetName(),
                         ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRefr))->FUN_007af430()))))->FUN_0084e3a0())));
        }
        reinterpret_cast<::FUN_00865e50_shell *>((apFile))->FUN_00865e50((void *)(&movedRefDataTmp), 0x22, 0);
        break;
    }
    }

    if (((StandaloneREFR*)apForm)->vfn_f0() && reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((((BGSChangeFlags_s*)&eChangeFlags)))->FUN_004280f0(4))
    {
        StandaloneREFR* pRefr = (StandaloneREFR*)apForm;
        CF845 holder_(((S_00422b90*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((pRefr))->FUN_005d43c0())))->FUN_00422b90());
        if (pRefr->vfn_1d0() || !((void *)(::FUN_00559450((int *)&(holder_)))))
        {
            unsigned int offsetBefore6;
            unsigned int bookmark8 = reinterpret_cast<::FUN_00865f20_shell *>((apFile))->FUN_00865f20();
            offsetBefore6 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apFile))->FUN_0084e3a0()));
            reinterpret_cast<::fnv_00562de0::FUN_00562de0_cls *>((pRefr))->FUN_00562de0((::fnv_00562de0::TargetRef *)(apFile));
            unsigned int offsetAfter = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apFile))->FUN_0084e3a0()));
            reinterpret_cast<::FUN_00865ff0_shell *>((apFile))->FUN_00865ff0(offsetAfter - offsetBefore6, bookmark8);
        }
        else
        {
            reinterpret_cast<::FakeBGSLoadGameSubBuffer *>(&(holder_))->WriteToSaveGameBuffer((::BGSSaveGameBuffer *)(apFile));
        }
    }

    return eType;
}

#include <string.h>
unsigned int FUN_0084e830(int);
unsigned int FUN_0084e800(int);
struct ExtCellCharData
{
    int unk00;
    int unk04;
};
struct ExtCellShortData
{
    int unk00;
    int unk04;
    int unk08;
};
struct IntCellData
{
    int unk00;
};

struct CreatedRefData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    CreatedRefData* FUN_0084eb20();
};
struct MovedRefData
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
    MovedRefData* FUN_0084eb50();
};
struct InitDataA
{
};
struct InitDataB
{
};
struct InitDataC
{
};
struct InitDataD
{
};
struct InitDataE
{
};
struct InitDataF
{
};
// Copies a type-sized block from a BGSLoadFormBuffer into a matching data struct and dispatches it to the appropriate InitData handler.
// @fnv 0x0084e930
void FUN_0084e930(BGSLoadFormBuffer* pBuffer, INITIAL_DATA_TYPE eType, void* pData)
{
    unsigned int uiSize = FUN_0084e830(eType);
    switch (eType)
    {
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_CHAR: {
        ExtCellCharData kData;
        memcpy(&kData, pBuffer, uiSize);
        InitDataA* pInit = (InitDataA*)pData;
        reinterpret_cast<::FUN_0084e340_Class *>((pInit))->FUN_0084e340((const char *)(::ExtCellCharData *)(&kData));
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_SHORT: {
        ExtCellShortData kData;
        memcpy(&kData, pBuffer, uiSize);
        InitDataB* p = (InitDataB*)pData;
        reinterpret_cast<::FUN_0084e3c0_Class *>((p))->LoadFromSaveEntry((const ::SaveEntryData *)(::ExtCellShortData *)(&kData));
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_INTERIOR_CELL: {
        IntCellData kData;
        memcpy(&kData, pBuffer, uiSize);
        InitDataC* p = (InitDataC*)pData;
        reinterpret_cast<::FUN_0084e420_class *>((p))->ResetFromValue((int *)(::IntCellData *)(&kData));
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION: {
        RefLocData kData;
        reinterpret_cast<::Outer84eac0 *>(&(kData))->FUN_0084eac0();
        memcpy(&kData, pBuffer, uiSize);
        InitDataD* pInit = (InitDataD*)pData;
        reinterpret_cast<::FUN_0084e460_t *>((pInit))->FUN_0084e460((uintptr_t)(&kData));
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE: {
        CreatedRefData kData;
        kData.FUN_0084eb20();
        memcpy(&kData, pBuffer, uiSize);
        InitDataE* p = (InitDataE*)pData;
        reinterpret_cast<::FUN_0084e4f0_cls *>((p))->FUN_0084e4f0(&kData);
        break;
    }
    case INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE: {
        MovedRefData kData;
        kData.FUN_0084eb50();
        memcpy(&kData, pBuffer, uiSize);
        InitDataF* p = (InitDataF*)pData;
        reinterpret_cast<::FUN_0084e580_class *>((p))->FUN_0084e580(&kData);
        break;
    }
    }
    FUN_0084e800(eType);
}

#include "generated/data/fallout/misc/saveload/bgssaveloadinitialdata.inc"
