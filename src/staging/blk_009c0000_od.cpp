
// src/staging/blk_009c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include "fnv/game_timer.h"
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/ActorMovement__Mover.h"
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSCameraShot.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CameraState.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_004301b0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00444d00_Class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00497ca0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a3fe0_shell.h"
#include "fnv/decl/FUN_004a40a0_Class.h"
#include "fnv/decl/FUN_004a40c0_Class.h"
#include "fnv/decl/FUN_004a41c0.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_005081b0_shell.h"
#include "fnv/decl/FUN_00522ba0_obj.h"
#include "fnv/decl/FUN_0058b4d0_shell.h"
#include "fnv/decl/FUN_0058b4f0_shell.h"
#include "fnv/decl/FUN_0058bb50_shell.h"
#include "fnv/decl/FUN_0058ccf0_Class.h"
#include "fnv/decl/FUN_0058d4f0_cls.h"
#include "fnv/decl/FUN_0058d630_shell.h"
#include "fnv/decl/FUN_0058e790_S.h"
#include "fnv/decl/FUN_005ce9d0.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005e50f0_Obj.h"
#include "fnv/decl/FUN_005e5130_Class.h"
#include "fnv/decl/FUN_005ff160_shell.h"
#include "fnv/decl/FUN_006205a0_Class.h"
#include "fnv/decl/FUN_006233c0.h"
#include "fnv/decl/FUN_0062e150_cls.h"
#include "fnv/decl/FUN_00633c90.h"
#include "fnv/decl/FUN_0063f790_shell.h"
#include "fnv/decl/FUN_0068a810_class.h"
#include "fnv/decl/FUN_0068a830_shell.h"
#include "fnv/decl/FUN_0069cfe0_cls.h"
#include "fnv/decl/FUN_006e4820_class.h"
#include "fnv/decl/FUN_006e8f40_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0088b740_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008a7570_shell.h"
#include "fnv/decl/FUN_008aff10_obj.h"
#include "fnv/decl/FUN_008b70d0_shell.h"
#include "fnv/decl/FUN_00931d90_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00966980_shell.h"
#include "fnv/decl/FUN_00998a30_shell.h"
#include "fnv/decl/FUN_009c8640_shell.h"
#include "fnv/decl/FUN_009c8680_shell.h"
#include "fnv/decl/FUN_009c86b0_shell.h"
#include "fnv/decl/FUN_009c8e00_shell.h"
#include "fnv/decl/FUN_009c9280_shell.h"
#include "fnv/decl/FUN_009c95e0_VATS.h"
#include "fnv/decl/FUN_009c9920_shell.h"
#include "fnv/decl/FUN_009d1b50_shell.h"
#include "fnv/decl/FUN_00aa4db0_shell.h"
#include "fnv/decl/FUN_00acbb70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FakeHolder.h"
#include "fnv/decl/FnCls.h"
#include "fnv/decl/GlobalObject_008c71b0.h"
#include "fnv/decl/ImageSpaceModifierInstanceDOF.h"
#include "fnv/decl/ImageSpaceModifierInstanceForm.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/NiPoint3Interpolator.h"
#include "fnv/decl/OSInputGlobals.h"
#include "fnv/decl/Owner623.h"
#include "fnv/decl/Owner_58cbc0.h"
#include "fnv/decl/P3.h"
#include "fnv/decl/PlayerCharacterOps.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Procedure052.h"
#include "fnv/decl/ProcedureValue.h"
#include "fnv/decl/S0058b4a0.h"
#include "fnv/decl/S_009c8c40.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/ScreenSplatter.h"
#include "fnv/decl/Shot.h"
#include "fnv/decl/ShotThis.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Unk.h"
#include "fnv/decl/VATS.h"
#include "fnv/decl/VatsList9c9.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00490e40__FUN_00490e40_shell.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a40e0__FUN_004a40e0.h"
#include "fnv/decl/fnv_004a4220__FUN_004a4220Class.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_00529df0__FUN_00529df0_shell.h"
#include "fnv/decl/fnv_005de0a0__FUN_005de0a0_shell.h"
#include "fnv/decl/fnv_00623090__Host.h"
#include "fnv/decl/fnv_008a6840__FUN_008a6840_shell.h"
#include "fnv/decl/fnv_008a6970__FUN_008a6970_shell.h"
#include "fnv/decl/fnv_00950110__FUN_00950110_pc.h"
#include "fnv/decl/fnv_00997520__FUN_00997520_shell.h"
#include "fnv/decl/fnv_009a0560__FUN_009a0560_shell.h"
#include "fnv/decl/fnv_009c9ae0__VATS9c9.h"
#include "fnv/decl/fnv_00c741e0__FUN_00c741e0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004a1000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_005f2000.h"
#include "fnv/symbols_0066d000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_0070c000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_009c8000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0108e000.h"
#include "fnv/symbols_01090000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "../../include/layout_support.h"

template <class T>
T Point3Difference(const T& arFrom, const void* apSubtrahend)
{
    T kResult;
    reinterpret_cast<::FUN_00439ef0_class *>(const_cast<T*>(&arFrom))->FUN_00439ef0((::NiPoint3 *)&kResult, *(const ::NiPoint3 *)apSubtrahend);
    return kResult;
}

struct hkVector4;
struct FUN_009c1a50_shell
{
    void* FUN_009c1a50();
    void FUN_009c1a20(hkVector4 const& v);
};
// @fnv 0x009c1a20
void FUN_009c1a50_shell::FUN_009c1a20(hkVector4 const& aVector)
{
    ::SetNiPoint3FromHkVector4((::NiPoint3 &)(aVector), (*(const ::hkVector4 *)(FUN_009c1a50())));
}

struct FUN_009c8600_Class
{
    char pad[0x44];
    char unk44;
    bool FUN_009c8600();
};

// @fnv 0x009c8600
bool FUN_009c8600_Class::FUN_009c8600()
{
    return (((int*)&unk44)[0] & 8) ? true : false;
}

struct FUN_009c8620_class
{
    char pad[0x44];
    int unk44;
    bool IsFlagSet() const;
};

// @fnv 0x009c8620
bool FUN_009c8620_class::IsFlagSet() const
{
    return (unk44 & 0x10) ? true : false;
}

struct Flt
{
    operator unsigned int();
};
struct FUN_009c8660_Class
{
    char pad[0x64];
    char unk64;
    void FUN_009c8660();
};
// @fnv 0x009c8660
void FUN_009c8660_Class::FUN_009c8660()
{
    ((Flt*)&unk64)->operator unsigned int();
}


struct FUN_009ca6c0_class
{
    void FUN_009ca6c0();
};

// @fnv 0x009ca6c0
void FUN_009ca6c0_class::FUN_009ca6c0()
{
    *(const void**)this = &DAT_01090874;
}

struct FUN_009d1b30_class
{
    char pad[0x50];
    float unk50;
    float GetFloatAtOffset50() const;
};

// @fnv 0x009d1b30
float FUN_009d1b30_class::GetFloatAtOffset50() const
{
    return unk50;
}

struct FUN_006e4820_Class
{
};

struct FUN_009d3370_Class
{
    char pad[0x14];
    FUN_006e4820_Class unk14;
    void FUN_009d3370();
};

// @fnv 0x009d3370
void FUN_009d3370_Class::FUN_009d3370()
{
    reinterpret_cast<::FUN_006e4820_class *>(((&unk14)))->FUN_006e4820();
}

struct FUN_009d7c40_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
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
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    void* m_e8;
    void FUN_009d7c40();
};

// @fnv 0x009d7c40
void FUN_009d7c40_Class::FUN_009d7c40()
{
    reinterpret_cast<::fnv_009a0560::FUN_009a0560_shell *>(this)->FUN_009a0560((::fnv_009a0560::StageHolder *)(m_e8));
}

struct FUN_009d7c60_class
{
    char pad[0xe1];
    char unke1;
    char GetByteAtOffsetE1();
};

// @fnv 0x009d7c60
char FUN_009d7c60_class::GetByteAtOffsetE1()
{
    return unke1;
}

struct FUN_009d9f00_Class
{
    char pad[0x144];
    unsigned int unk144;
    unsigned int FUN_009d9f00();
};

// @fnv 0x009d9f00
unsigned int FUN_009d9f00_Class::FUN_009d9f00()
{
    return unk144;
}

struct FUN_009d9f40_Class
{
    char pad[0xe0];
    char unke0;
    void* FUN_009d9f40();
};

// @fnv 0x009d9f40
void* FUN_009d9f40_Class::FUN_009d9f40()
{
    return &unke0;
}

struct PathBuilder
{
    void* FUN_009dfd50();
    void* m_iWordAt00;
    void* m_iWordAt04;
    unsigned int m_8;
};

// @fnv 0x009dfd50
void* PathBuilder::FUN_009dfd50()
{
    return ((void *)(reinterpret_cast<::FUN_006e8f40_shell *>(this)->FUN_006e8f40((int)(m_8 - 1))));
}

struct InventoryStackRecord
{
    char pad[0x40];
    void* m_40;
    void* m_44;
    void SetPointers(void* a, void* b);
};

// @fnv 0x009c8a90
void InventoryStackRecord::SetPointers(void* pFirst, void* pSecond)
{
    m_40 = pFirst;
    m_44 = pSecond;
    reinterpret_cast<::VATS *>(this)->FUN_009c8950(true, true);
}

struct FUN_009c1aa0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    FUN_009c1aa0_Class& FUN_009c1aa0(FUN_009c1aa0_Class const& src);
    void FUN_009c1b00(int);
};
struct T_
{
};
struct FUN_009c1b00
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    float m_10;
    int m_14;
    int m_18;
    int m_1c;
    FUN_009c1b00* Set(FUN_009c1b00 const* s);
};
// Copies src into this: calls FUN_009c1b00 on src, copies 8 ints from offset 8 and m_40.
// @fnv 0x009c1aa0
FUN_009c1aa0_Class& FUN_009c1aa0_Class::FUN_009c1aa0(FUN_009c1aa0_Class const& aSource)
{
    reinterpret_cast<::FUN_009c1b00 *>(this)->Set((const ::FUN_009c1b00 *)((intptr_t)&aSource));
    for (unsigned int i = 0; i < 8; ++i)
        ((int*)this)[i + 8] = ((int*)&aSource)[i + 8];
    m_40 = aSource.m_40;
    return *this;
}
// @fnv 0x009c1b00
FUN_009c1b00* FUN_009c1b00::Set(FUN_009c1b00 const* apSource)
{
    reinterpret_cast<::AlignedVector *>((((T_*)this)))->FUN_004a3f10((*(const ::AlignedVector *)((void*)apSource)));
    m_10 = apSource->m_10;
    m_14 = apSource->m_14;
    for (unsigned int i = 0; i < 2; ++i)
        ((int*)this)[6 + i] = ((int*)apSource)[6 + i];
    return this;
}

extern int DAT_01090568;
extern int DAT_01090584;
extern int DAT_01090594;
struct Call741e0
{
};
struct FUN_009c6440_Class
{
    char pad[0x3e0];
    void* unk3e0;
    char pad3e4[0x2c];
    void* unk410;
    char pad414[0x23c];
    int unk650;
    void* FUN_009c6440(void* a, int b);
};
// @fnv 0x009c6440
void* FUN_009c6440_Class::FUN_009c6440(void* a, int aiStoredValue)
{
    new ((void *)(((Call741e0*)this))) ::fnv_00c741e0::FUN_00c741e0((::fnv_00c741e0::T741_Src *)(a));
    *(const void**)this = &DAT_01090594;
    unk3e0 = &DAT_01090584;
    unk410 = &DAT_01090568;
    unk650 = aiStoredValue;
    return this;
}

struct NiAVObject;
struct TESObjectREFR
{
public:
    bool IsLimbMissing(int);
};

// Converts object via FUN_00c7fa90 and, if the result is non-null, returns the TESObjectREFR obtained from it; otherwise returns null.
// @fnv 0x009c69e0
TESObjectREFR* GetReferenceFromObject(NiAVObject* object)
{
    TESObjectREFR* reference = 0;
    NiAVObject* converted = ((::NiAVObject *)(std::uintptr_t)(::FUN_00c7fa90((::S_Obj *)(object))));
    if (converted)
        reference = ::FUN_0056f930(converted);
    return reference;
}

extern unsigned char DAT_011f9424;

// @fnv 0x009c7190
void FUN_009c7190(unsigned char value)
{
    DAT_011f9424 = value;
}

extern unsigned char DAT_012677cc;

// @fnv 0x009c86a0
void FUN_009c86a0(unsigned char value)
{
    DAT_012677cc = value;
}

struct FUN_009ca4c0_shell
{
    void FreeStoredPointer();
};


struct FUN_009c8870_Class : FUN_009ca4c0_shell
{
    void* FUN_009c8870(unsigned int flags);
};

// Calls FreeStoredPointer, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x009c8870
void* FUN_009c8870_Class::FUN_009c8870(unsigned int flags)
{
    FreeStoredPointer();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct PathingAvoidNodeArray
{
    int x;
};
struct PathingRequestAvoidPointer
{
    PathingRequestAvoidPointer(PathingAvoidNodeArray*);
    ~PathingRequestAvoidPointer();
    PathingAvoidNodeArray* p;
    PathingRequestAvoidPointer& operator=(PathingRequestAvoidPointer const&);
};
struct FUN_009d7c80_Class
{
    bool FUN_009d7c80();
};
// @fnv 0x009d7c80
bool FUN_009d7c80_Class::FUN_009d7c80()
{
    PathingRequestAvoidPointer t(0);
    reinterpret_cast<::ProcedureValue *>(this)->UpdateOutput((::OutputValue *)(::PathingRequestAvoidPointer *)(&t));
    return reinterpret_cast<::Procedure052 *>(this)->UpdateMovementRequest((::Output052 *)(::PathingRequestAvoidPointer *)(&t));
}

struct SL
{
    SL();
    ~SL();
    int m_iWordAt00;
    int m_iWordAt04;
};
struct GO
{
    GO(intptr_t);
    ~GO();
    void operator=(void*);
    int m_34;
};

struct FUN_009c6a30 : SL
{
    int a_8;
    int a_c;
    int a_10;
    float a_14;
    float a_18;
    int a_1c;
    int a_20;
    int a_24;
    int a_28;
    int a_2c;
    int a_30;
    GO a_34;
    bool a_38;
    int a_3c;
    int a_40;
    int a_44;
    FUN_009c6a30();
};

// @fnv 0x009c6a30
FUN_009c6a30::FUN_009c6a30() : a_34(0)
{
    a_8 = 0;
    DAT_011f21b8 = 0;
    a_c = 0;
    a_10 = 0;
    a_14 = 0.0f;
    a_18 = 0.0f;
    a_1c = 0;
    a_20 = 0;
    a_24 = 0;
    a_28 = 0;
    a_2c = 0;
    a_34 = 0;
    a_38 = true;
    a_3c = 0;
    a_40 = 0;
    a_44 = 0;
}

struct CF845
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    CF845(int);
};

struct FUN_009c1a00_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    CF845* ConstructCF845(CF845* p);
};

// @fnv 0x009c1a00
CF845* FUN_009c1a00_Class::ConstructCF845(CF845* pObject)
{
    new ((void *)(pObject)) ::GlobalObject_008c71b0(m_24);
    return pObject;
}

struct NiPoint3
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;

    bool FUN_004390c0(NiPoint3 const&);
    NiPoint3 operator+(NiPoint3 const&) const;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};

struct FUN_0058d510_class
{
    NiPoint3* GetCameraPosition(NiPoint3*);
};

struct P09H
{
};

struct FUN_0070c3b0_Dummy
{
};



struct FUN_009c8ac0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_0058d510_class* m_10;

    NiPoint3* FUN_009c8ac0(NiPoint3*);
};

// @fnv 0x009c8ac0
NiPoint3* FUN_009c8ac0_class::FUN_009c8ac0(NiPoint3* result)
{
    NiPoint3 point = ::NiPoint3::ZERO;

    if (m_10)
    {
        NiPoint3 sourcePoint;
        point = *m_10->GetCameraPosition(&sourcePoint);
    }

    if (point.FUN_004390c0(::NiPoint3::ZERO))
    {
        NiPoint3 offset;
        NiPoint3 sum;
        point = *reinterpret_cast<::Point3Offset *>((void *)(((::NiPoint3 *)(::FUN_0045bb80(((std::intptr_t)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((void *)((*reinterpret_cast<::P09H * *>(&::DAT_011f21f0))))->FUN_0043fcd0())))))))->ProjectileLaunched(&sum, (::NiPoint3 *)(reinterpret_cast<::FUN_00416870_t *>(&(offset))->FUN_00416870(0.0f, 0.0f, FUN_0070c3b0((*reinterpret_cast<::FUN_0070c3b0_Dummy * *>(&::_g_thePlayer))))));
    }

    *result = point;
    return result;
}

extern int DAT_01090aec;
struct FUN_009ca680
{
    FUN_009ca680();
};
struct FUN_009cbad0 : FUN_009ca680
{
    const void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    float m_14;
    int m_18;
    int m_1c;
    FUN_009cbad0();
};
// Initializes the object: stores the address of DAT_01090aec and zeroes m_10, m_14 and m_1c.
// @fnv 0x009cbad0
FUN_009cbad0::FUN_009cbad0()
{
    m_iWordAt00 = &DAT_01090aec;
    m_10 = 0;
    m_14 = 0.0f;
    m_1c = 0;
}


struct CombatTargetTimestamp
{
    int m_iWordAt00;
    CombatTargetTimestamp(float value);
};

struct FUN_009d1b90_Class
{
    char m_iWordAt00[0xa4];
    int m_a4;

    void SetNegatedTimestamp();
};

// @fnv 0x009d1b90
void FUN_009d1b90_Class::SetNegatedTimestamp()
{
    CombatTargetTimestamp timestampValue(-DAT_01090e90);
    m_a4 = timestampValue.m_iWordAt00;
}

struct FUN_00997520_Class
{
};
struct FUN_009d7c00_Class
{
    char pad[0x128];
    FUN_00997520_Class sub;
    void ForwardToSub(std::intptr_t);
};
// @fnv 0x009d7c00
void FUN_009d7c00_Class::ForwardToSub(std::intptr_t aiValue)
{
    reinterpret_cast<::fnv_00997520::FUN_00997520_shell *>(&(sub))->FUN_00997520((const void *)(aiValue));
}

struct FUN_009c5ee0_sub
{
    unsigned int unk00;
};

struct FUN_009c5ee0_triple
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
};


class FUN_009c5ee0_cls
{
  public:
    unsigned int m_00;
    FUN_009c5ee0_sub m_04;
    FUN_009c5ee0_triple m_08;
    FUN_009c5ee0_cls* FUN_009c5ee0();
};

// Clears m_00, calls m_04.Init(0), copies DAT_011f426c into m_08, and returns this.
// @fnv 0x009c5ee0
FUN_009c5ee0_cls* FUN_009c5ee0_cls::FUN_009c5ee0()
{
    m_00 = 0;
    new ((void *)&(m_04)) ::FUN_00633c90((::G00559a40 *)(0));
    m_08 = (*reinterpret_cast<::FUN_009c5ee0_triple *>((void *)&::NiPoint3::ZERO));
    return this;
}

struct Vector3
{
    float x, y, z;
};
struct OrientationSource
{
};
struct OrientationObject
{
    void** vtable;
    void SetOrientationFromDirection(Vector3 input);
};
extern "C" float __cdecl FUN_00408840(float);
extern const double DAT_01018c00;
typedef void*(* GetContextFn)(OrientationObject*);
typedef float(* GetAngleFn)(OrientationObject*, int);
typedef void(* SetAngleFn)(OrientationObject*, float);
struct OrientationObject_Vtbl
{
    void* slots000[125];
    GetContextFn GetContext;
    void* slots126[175 - 126];
    GetAngleFn GetAngle;
    void* slot176;
    SetAngleFn SetAngle;
};
// @fnv 0x009c6030
void OrientationObject::SetOrientationFromDirection(Vector3 aDirection)
{
    Vector3 c;
    reinterpret_cast<::FUN_00439ef0_class *>(&(aDirection))->FUN_00439ef0((::NiPoint3 *)(::Vector3 *)(&c), (*(const ::NiPoint3 *)(((OrientationObject_Vtbl*)vtable)->GetContext(this))));
    Vector3 b = c;
    reinterpret_cast<::FUN_004a0c10_s *>(&(b))->FUN_004a0c10();
    float e = ((OrientationObject_Vtbl*)vtable)->GetAngle(this, 0);
    float d = reinterpret_cast<::MobileObject *>(this)->GetLooking();
    float a = reinterpret_cast<::FUN_00966980_shell *>((((::OrientationSource *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_00966980();
    if (a == ::_DAT_01012060)
    {
        d = -::FUN_004b1460(b.z / (1.0f - b.z * b.z));
    }
    e = ::GetDirectionAngle((const ::NiPoint3 *)(::Vector3 *)(&b));
    if (a == ::_DAT_01012060 || FUN_00408840(e - ((OrientationObject_Vtbl*)vtable)->GetAngle(this, 0)) <= DAT_01018c00)
    {
        ((OrientationObject_Vtbl*)vtable)->SetAngle(this, e);
    }
    reinterpret_cast<::FUN_00931d90_shell *>(this)->ClampLookAngle(d);
}

struct InputX
{
};
struct OSX
{
};
struct TimerX
{
};
struct SettingX
{
};
struct IdleX
{
};
struct IdleCtlX
{
};
struct IdlePtrX
{
};
struct SeqHolderX
{
};
struct AnimX
{
    char _pad00[0x124];
    IdlePtrX kIdle;
};
struct EntryX
{
};
struct ProcessX
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual EntryX* GetEquipped();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void* GetCombatTarget(int aiVoice);
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void* GetPartNode(int aiPart);
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void Unequip(int aiArg);
};
struct Obj3DX
{
};
struct ModelX
{
};
struct ActorBaseX
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual ModelX* GetModelFilePath();
};
struct RefX
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool IsDead(bool abArg);
    virtual bool IsKnocked();
    virtual bool IsSwimmingV();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void Update3D();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void ApplyRecoil(float afAmount);
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void Equip(void* apItem, int aiCount, unsigned char acMod, int aiArg);
};
struct PartDataX
{
    int iActionIndex[4];
    int iPart;
};
struct TopicX
{
    int iType;
    short sPad4;
    bool bSkip;
    bool bPad7;
    bool bPickResultFound;
    bool bPad9[3];
    RefX* pActor;
    int iPart;
    PartDataX* pPartData;
    int iPad18;
    int iPad1c;
    float fRecoil;
    bool bSkip2;
};
struct ShotSubX
{
};
struct ShotX
{
    char _pad00[0x30];
    ShotSubX kList;
    int HasTargetRef();
    void Update(float afTime);
};
struct ShotListX
{
};
struct CamDataX
{
};
struct CamMgrX
{
};
struct ImodX
{
    void Update(void* apList, float afStrength, float afMult, void* apTarget);
};
struct FadeX
{
};
struct TargetsX
{
    void Add(RefX* apActor);
};
struct TopicListX
{
    TopicX* pItem;
    TopicListX* pNext;
    bool IsEmpty();
};
struct DialogueCameraX : public TopicListX
{
    int iState;
    ShotListX* pShots;
    ShotX* pShot;
    float fShotTime;
    float fShotDelay;
    RefX* pSpeakerRef;
    RefX* m_pReference;
    IdleX* m_pIdleForm;
    ImodX* pImod;
    FadeX* pFade;
    int iPad30[3];
    int iPerk;
    void FUN_009c7240();
};
extern TopicX* xpLastTopic;
extern int xiTopicCount;
// @fnv 0x009c7240
void DialogueCameraX::FUN_009c7240()
{
    void* qObI;
    float qXGDO;
    bool qVar;
    void* qQirx;
    float qRBAdC;
    void* qVCM;
    Obj3DX* qoqcoe;
    void* qBMjHz;
    ModelX* qgqKr;
    RefX* qXSF;
    void* qfpzU;
    void* qZNIZJV;
    void* qOFvKuu;
    void* qhQRuW;
    void* qpydTG;
    bool qrUCJDN;
    bool qBLsiu;
    bool qAXSCg;
    bool qbfQdhM;
    ProcessX* qXMUYT;
    IdleCtlX* qpia;
    TopicX* qJDuOZ;
    InputX* qxQHW;
    float qfTOqo;

    ::FUN_009c86a0(iState == 4);
    if (iState != 4)
        return;
    if (!IsEmpty())
    {
        qJDuOZ = ((::TopicX *)(((::Vec3 *)(void *)this)));
        qxQHW = ((::InputX *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OSX * *>(&::g_osGlobals))))->FUN_00877720()));
        qXMUYT = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->GetBaseTexture()));
        qbfQdhM = false;
        (*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)) = qJDuOZ->pActor;
        if (pShot && reinterpret_cast<::FUN_0058d630_shell *>((pShot))->FUN_0058d630() && fShotDelay > 0.0)
        {
            fShotDelay -= ::fnv::timer::Seconds() / ::FUN_00716440();
            if (fShotDelay < 0.0)
            {
                fShotDelay = 0.0f;
                qAXSCg = true;
                while (qAXSCg && ::DAT_011f21b8 > ::GetField38((char *)(pShot)))
                    qAXSCg = reinterpret_cast<::FUN_009c9920_shell *>(this)->FUN_009c9920();
            }
        }
        else if (pShot && qJDuOZ != xpLastTopic)
        {
            reinterpret_cast<::CameraState *>((pShot))->ResetCameraState();
            ::DAT_011f21b8 = 0;
            pShot = 0;
            pShots = 0;
            fShotTime = 0.0f;
            fShotDelay = 0.0f;
        }
        if (pShot && fShotTime > 0.0)
        {
            fShotTime -= ::fnv::timer::Seconds() / ::FUN_00716440();
            if (fShotTime <= 0.0)
            {
                qbfQdhM = true;
                fShotTime = 0.0f;
                fShotDelay = 0.0f;
            }
        }
        if (!pShots || qbfQdhM)
        {
            qBLsiu = false;
            if (!pShots)
            {
                qBLsiu = true;
                reinterpret_cast<::FUN_009c8e00_shell *>(this)->FUN_009c8e00((::VATSCommand *)(qJDuOZ));
                if ((*reinterpret_cast<::CamDataX * *>(&::DAT_011f21c0)))
                {
                    (*reinterpret_cast<::CamDataX * *>(&::DAT_011f21dc)) = (*reinterpret_cast<::CamDataX * *>(&::DAT_011f21c0));
                }
                else if ((*reinterpret_cast<::CamDataX * *>(&::DAT_011f21c4)))
                {
                    (*reinterpret_cast<::CamDataX * *>(&::DAT_011f21dc)) = (*reinterpret_cast<::CamDataX * *>(&::DAT_011f21c4));
                    (*reinterpret_cast<::CamDataX * *>(&::DAT_011f21c4)) = 0;
                }
                else
                {
                    (*reinterpret_cast<::CamDataX * *>(&::DAT_011f21dc)) = ((::CamDataX *)(reinterpret_cast<::FUN_0058bb50_shell *>(((*reinterpret_cast<::CamMgrX * *>(&::DAT_011ca700))))->FUN_0058bb50((unsigned int)(std::uintptr_t)((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))), (unsigned int)(std::uintptr_t)(qJDuOZ->pActor))));
                }
                if ((*reinterpret_cast<::CamDataX * *>(&::DAT_011f21dc)))
                {
                    if (reinterpret_cast<::S0058b4a0 *>(((*reinterpret_cast<::CamDataX * *>(&::DAT_011f21dc))))->FUN_0058b4a0())
                        ::DAT_011f21c8 = 0;
                    else if (reinterpret_cast<::FUN_0058b4d0_shell *>(((*reinterpret_cast<::CamDataX * *>(&::DAT_011f21dc))))->FUN_0058b4d0())
                        ::DAT_011f21c8 = 1;
                    else if (reinterpret_cast<::FUN_0058b4f0_shell *>(((*reinterpret_cast<::CamDataX * *>(&::DAT_011f21dc))))->IsFlag2Set())
                        ::DAT_011f21c8 = 2;
                }
                else
                {
                    ::DAT_011f21c8 = 0;
                }
                if ((*reinterpret_cast<::CamDataX * *>(&::DAT_011f21dc)))
                    pShots = ((::ShotListX *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::CamDataX * *>(&::DAT_011f21dc))))->GetShotList()));
                else
                    pShots = 0;
            }
            if (pShots)
            {
                if (qbfQdhM)
                {
                    qrUCJDN = reinterpret_cast<::FUN_009c9920_shell *>(this)->FUN_009c9920();
                    if (!qrUCJDN)
                    {
                        if (((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0)) == (*reinterpret_cast<::RefX * *>(&::DAT_011f21e8)) && qJDuOZ->bSkip) || ((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0)) == (*reinterpret_cast<::RefX * *>(&::DAT_011f21ec)) && qJDuOZ->bSkip2))
                            qJDuOZ->bPickResultFound = false;
                        else
                            reinterpret_cast<::S_009c8c40 *>(this)->SetValue(0);
                    }
                }
                else
                {
                    pShot = (*((::ShotX **)(void *)(pShots)));
                    if (pShot && reinterpret_cast<::FUN_005081b0_shell *>((pShot))->GetFloatAtOffset58() > fShotDelay)
                        fShotDelay = reinterpret_cast<::FUN_005081b0_shell *>((pShot))->GetFloatAtOffset58();
                    if (pShot && reinterpret_cast<::FUN_009c8600_Class *>((pShot))->FUN_009c8600())
                        reinterpret_cast<::fnv_00950110::FUN_00950110_pc *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00950110(1);
                    else
                        ::DAT_011f21d3 = true;
                }
            }
            if (qBLsiu)
                reinterpret_cast<::FUN_009c9280_shell *>(this)->ExecuteVATSMeleeAttack((::VATSCommand *)(qJDuOZ));
            xpLastTopic = qJDuOZ;
            if (xiTopicCount > 1)
                xiTopicCount = 0;
        }
        qpia = ((::IdleCtlX *)(::FUN_00559450((int *)&(((::AnimX *)(reinterpret_cast<::FUN_008b70d0_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008b70d0()))->kIdle))));
        if (m_pIdleForm && (!qpia || ((::IdleX *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((qpia))->GetIconFormID())) != m_pIdleForm || (((intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((qpia))->GetName())) >= 2 && ((intptr_t)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((qpia))->FUN_00490e40())) == 0)))
        {
            reinterpret_cast<::FUN_00497ca0_shell *>((((::AnimX *)(reinterpret_cast<::FUN_008b70d0_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008b70d0()))))->FUN_00497ca0((::TESIdleForm *)(m_pIdleForm), reinterpret_cast<::FUN_005ff160_shell *>((m_pIdleForm))->GetFlagsMasked());
        }
        if (pShot)
        {
            if (!reinterpret_cast<::FUN_0058d630_shell *>((pShot))->FUN_0058d630())
            {
                reinterpret_cast<::FUN_009c95e0_VATS *>(this)->HandleCommand((::FUN_009c95e0_Command *)(qJDuOZ));
                if (pShot && (::DAT_011f21b8 >= ::GetField38((char *)(pShot)) || ::GetField38((char *)(pShot)) == 3))
                {
                    fShotTime = reinterpret_cast<::FUN_009d1b50_shell *>((pShot))->GetField54Float();
                    if (fShotTime <= 0.0010000000474974513)
                    {
                        fShotTime = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting540))))));
                        ::DAT_011f21d8 = 0.0f;
                    }
                    if (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::g_011ce368)))))) > fShotDelay)
                        fShotDelay = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::g_011ce368))))));
                    if (!qJDuOZ->pActor || (!((intptr_t)(reinterpret_cast<::Twin_00639b40 *>((pShot))->GetEntryPoint())) && qJDuOZ->iType != 0x12))
                    {
                        reinterpret_cast<::ShotThis *>((pShot))->SetupCamera((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0)), ::DAT_011f21c8);
                    }
                    else
                    {
                        reinterpret_cast<::ShotThis *>((pShot))->SetupCamera(qJDuOZ->pActor, ::DAT_011f21c8);
                    }
                    qZNIZJV = ((void *)(reinterpret_cast<::S_FUN_0045bc00 *>((((::SeqHolderX *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::AnimX *)(reinterpret_cast<::FUN_008b70d0_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008b70d0()))))->FUN_0084e3a0()))))->FUN_0045bc00(0)));
                    qpydTG = 0;
                    qhQRuW = 0;
                    qfpzU = 0;
                    if (reinterpret_cast<::FUN_0058d4f0_cls *>((pShot))->IsNotFlag4Set())
                    {
                        qpydTG = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->GetBaseTexture()))->GetCombatTarget(reinterpret_cast<::FUN_00acbb70_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_00acbb70());
                    }
                    if (qJDuOZ->pActor)
                    {
                        qhQRuW = qJDuOZ->pActor->Get3D();
                        if (qJDuOZ->pActor->IsActor())
                        {
                            qXSF = qJDuOZ->pActor;
                            qgqKr = ((::ActorBaseX *)(reinterpret_cast<::Actor *>((qXSF))->GetActorBase()))->GetModelFilePath();
                            if (qgqKr)
                            {
                                qBMjHz = ::FUN_006a9540((char *)(qgqKr));
                                qoqcoe = 0;
                                if (qJDuOZ->pPartData->iPart != -1)
                                {
                                    qoqcoe = ((::Obj3DX *)(reinterpret_cast<::FUN_005e5130_Class *>((qgqKr))->FUN_005e5130(qJDuOZ->iPart)));
                                    if (qoqcoe)
                                    {
                                        if (reinterpret_cast<::TESObjectREFR *>((qXSF))->IsLimbMissing(qJDuOZ->pPartData->iPart))
                                        {
                                            qVCM = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>((qXSF))->GetBaseTexture()))->GetPartNode(qJDuOZ->pPartData->iPart);
                                            if (qVCM)
                                                qfpzU = ((void *)(::FUN_004aae30((::NiAVObject *)(qVCM), (::NiFixedString *)(void *)(((void *)(::fnv_0043b230::FUN_0043b230((const char *)(qoqcoe))))))));
                                        }
                                        else
                                        {
                                            qfpzU = ((void *)(::FUN_004aae30((::NiAVObject *)(qhQRuW), (::NiFixedString *)(void *)(((void *)(::fnv_0043b230::FUN_0043b230((const char *)(qoqcoe))))))));
                                        }
                                    }
                                }
                                if (!qfpzU)
                                {
                                    qoqcoe = ((::Obj3DX *)(std::uintptr_t)(reinterpret_cast<::FUN_005e50f0_Obj *>((qgqKr))->GetValueByIndex(0)));
                                    if (qoqcoe)
                                        qfpzU = ((void *)(::FUN_004aae30((::NiAVObject *)(qhQRuW), (::NiFixedString *)(void *)(((void *)(::fnv_0043b230::FUN_0043b230((const char *)(qoqcoe))))))));
                                }
                            }
                        }
                    }
                    switch (((intptr_t)(reinterpret_cast<::Twin_00639b40 *>((pShot))->GetEntryPoint())))
                    {
                    case 0:
                        if (qpydTG)
                            reinterpret_cast<::Owner_58cbc0 *>((pShot))->SetNode((::Node_58cbc0 *)(qpydTG));
                        else
                            reinterpret_cast<::Owner_58cbc0 *>((pShot))->SetNode((::Node_58cbc0 *)(qZNIZJV));
                        break;
                    case 2:
                        if (qfpzU)
                            reinterpret_cast<::Owner_58cbc0 *>((pShot))->SetNode((::Node_58cbc0 *)(qfpzU));
                        else if (qhQRuW)
                            reinterpret_cast<::Owner_58cbc0 *>((pShot))->SetNode((::Node_58cbc0 *)(qhQRuW));
                        else if (qpydTG)
                            reinterpret_cast<::Owner_58cbc0 *>((pShot))->SetNode((::Node_58cbc0 *)(qpydTG));
                        else
                            reinterpret_cast<::Owner_58cbc0 *>((pShot))->SetNode((::Node_58cbc0 *)(qZNIZJV));
                        break;
                    case 1:
                        if (!((intptr_t)(reinterpret_cast<::FUN_009c8640_shell *>((pShot))->FUN_009c8640())))
                        {
                            if (pSpeakerRef)
                                reinterpret_cast<::Owner_58cbc0 *>((pShot))->SetNode((::Node_58cbc0 *)(void *)(pSpeakerRef->Get3D()));
                            else if (m_pReference)
                                reinterpret_cast<::Owner_58cbc0 *>((pShot))->SetNode((::Node_58cbc0 *)(void *)(m_pReference->Get3D()));
                            else if (qpydTG)
                                reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qpydTG));
                            else
                                reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qZNIZJV));
                        }
                        break;
                    }
                    switch (((intptr_t)(reinterpret_cast<::LowProcess *>((pShot))->GetTarget())))
                    {
                    case 0:
                        if (qpydTG)
                            reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qpydTG));
                        else
                            reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qZNIZJV));
                        break;
                    case 2:
                        if (qfpzU)
                            reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qfpzU));
                        else if (qhQRuW)
                            reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qhQRuW));
                        else if (qpydTG)
                            reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qpydTG));
                        else
                            reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qZNIZJV));
                        break;
                    case 1:
                        if (!pShot->HasTargetRef())
                        {
                            if (pSpeakerRef)
                            {
                                if (reinterpret_cast<::FUN_009c8620_class *>((pShot))->IsFlagSet() && reinterpret_cast<::FUN_00444d00_Class *>((pSpeakerRef))->FUN_00444d00(0x10))
                                {
                                    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((pSpeakerRef))->FUN_005de0a0(0x10, 0);
                                    pSpeakerRef->Update3D();
                                }
                                reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(void *)(pSpeakerRef->Get3D()));
                            }
                            else if (m_pReference)
                            {
                                if (reinterpret_cast<::FUN_009c8620_class *>((pShot))->IsFlagSet() && reinterpret_cast<::FUN_00444d00_Class *>((pSpeakerRef))->FUN_00444d00(0x10))
                                {
                                    reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>((m_pReference))->FUN_005de0a0(0x10, 0);
                                    m_pReference->Update3D();
                                }
                                reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(void *)(m_pReference->Get3D()));
                            }
                            else if (qpydTG)
                            {
                                reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qpydTG));
                            }
                            else
                            {
                                reinterpret_cast<::FUN_0058ccf0_Class *>((pShot))->SetSceneNode((::SceneNode *)(qZNIZJV));
                            }
                        }
                        break;
                    }
                    qOFvKuu = ((void *)(reinterpret_cast<::FUN_009c8680_shell *>((pShot))->FUN_009c8680()));
                    if (pImod)
                    {
                        reinterpret_cast<::fnv_00529df0::FUN_00529df0_shell *>((pImod))->FUN_00529df0((::TESImageSpaceModifier *)(void *)(reinterpret_cast<::Callees *>(&(pShot->kList))->FUN_00726070()), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting542)))))), 1.0f, (::NiAVObject *)(qOFvKuu));
                    }
                    else
                    {
                        pImod = ((::ImodX *)(::ImageSpaceModifierInstanceForm::Trigger((::TESImageSpaceModifier *)(void *)(reinterpret_cast<::Callees *>(&(pShot->kList))->FUN_00726070()), 1.0f, (::NiAVObject *)(qOFvKuu))));
                        if (pImod)
                            reinterpret_cast<::ImageSpaceModifierInstanceDOF *>((pImod))->FUN_005bbd60(true);
                    }
                    if (pShot && !reinterpret_cast<::FUN_0058d630_shell *>((pShot))->FUN_0058d630())
                        reinterpret_cast<::FUN_009c9920_shell *>(this)->FUN_009c9920();
                }
            }
            if (xbSlowMo && ::DAT_011ca730 == 0.0)
                ::DAT_011ca72c = ::DAT_011f21d4;
            ::DAT_011f21d4 += ::fnv::timer::Seconds() / ::FUN_00716440();
            ::DAT_011f21d8 += ::fnv::timer::Seconds() / ::FUN_00716440();
            if (::DAT_011f21d8 > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting540)))))))
                reinterpret_cast<::VATS *>(this)->FUN_009c8950(false, false);
            if (pShot && reinterpret_cast<::FUN_0058d630_shell *>((pShot))->FUN_0058d630())
            {
                if (::DAT_011f21d3)
                {
                    reinterpret_cast<::fnv_00950110::FUN_00950110_pc *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00950110(0);
                    ::DAT_011f21d3 = false;
                }
                reinterpret_cast<::Shot *>((pShot))->UpdateCamera(::DAT_011f21d4);
                if (xbSlowMo)
                    ::fnv::timer::SetMultiplier(0.0001f, false);
                else if (xpLastTopic && xpLastTopic->iType == 0x12)
                    ::fnv::timer::SetMultiplier(0.3f, false);
                else
                    ::fnv::timer::SetMultiplier(reinterpret_cast<::FUN_009d1b30_class *>((void *)(pShot))->GetFloatAtOffset50(), false);
                qRBAdC = ::DAT_011ca730;
                if (qRBAdC > 0.5)
                    qRBAdC = 1.0f - qRBAdC;
                reinterpret_cast<::FUN_0063f790_shell *>((pFade))->FUN_0063f790(qRBAdC * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting544)))))));
            }
            else
            {
                ::fnv::timer::SetMultiplier(1.0f, false);
            }
        }
        qfTOqo = 0.0f;
        if (::FUN_0066dde0(qJDuOZ->iType))
        {
            if (!reinterpret_cast<::VatsList9c9 *>(this)->IsValidCommand((::VatsCmd9c9 *)(qJDuOZ)) && !::FUN_0066de80(qJDuOZ->iType) && qJDuOZ->iType != 6 &&
                reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_008a7570() != 9 && reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_008a7570() != 0x11)
            {
                reinterpret_cast<::OSInputGlobals *>((qxQHW))->FUN_00a24280(6);
                ::DAT_011f21e4 = true;
            }
            else
            {
                ::DAT_011f21e4 = false;
            }
            if (!qJDuOZ->bPickResultFound)
            {
                qVar = false;
                if (!pShot || fShotDelay == 0.0)
                {
                    if (reinterpret_cast<::VatsList9c9 *>(this)->IsValidCommand((::VatsCmd9c9 *)(qJDuOZ)))
                    {
                        reinterpret_cast<::FUN_009c95e0_VATS *>(this)->HandleCommand((::FUN_009c95e0_Command *)(qJDuOZ));
                        if (reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == -1 || ::FUN_005f25d0(reinterpret_cast<::FUN_004301b0_shell *>((((::AnimX *)(reinterpret_cast<::FUN_008b70d0_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008b70d0()))))->FUN_004301b0(4)))
                            qVar = true;
                    }
                    else if (!m_pReference)
                    {
                        qVar = true;
                    }
                }
                if (qVar)
                {
                    qfTOqo = qJDuOZ->fRecoil;
                    reinterpret_cast<::FUN_009c86b0_shell *>(this)->FUN_009c86b0();
                    qJDuOZ = 0;
                }
            }
            qQirx = 0;
            if (qXMUYT->GetEquipped())
                qQirx = ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((qXMUYT->GetEquipped()))->GetName()));
        }
        else if (::DAT_011f21d2)
        {
            if (reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == -1)
            {
                qfTOqo = qJDuOZ->fRecoil;
                reinterpret_cast<::FUN_009c86b0_shell *>(this)->FUN_009c86b0();
                qJDuOZ = 0;
            }
        }
        else
        {
            switch (qJDuOZ->iType)
            {
            case 13:
                if (reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == -1)
                {
                    reinterpret_cast<::fnv_008a6840::FUN_008a6840_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a6840(!reinterpret_cast<::fnv_008a6970::FUN_008a6970_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a6970());
                    ::DAT_011f21d2 = true;
                }
                break;
            case 9:
                if (reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == -1)
                {
                    if (qXMUYT->GetEquipped())
                    {
                        (*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))->Equip(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((qXMUYT->GetEquipped()))->GetName())), 2, ((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((qXMUYT->GetEquipped()))->HasEffect(2))), 0);
                        qXMUYT->Unequip(0);
                    }
                    ::DAT_011f21d2 = true;
                }
                break;
            case 10:
            case 11:
                if (reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == -1)
                {
                    if (!(*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))->IsSwimmingV() && !(*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))->IsDead(false) && !(*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))->IsKnocked() &&
                        !reinterpret_cast<::FUN_00437bf0_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_00437bf0() && !((bool)(reinterpret_cast<::FUN_00437bd0_stub *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_00437bd0())))
                    {
                        if ((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0)) == (*reinterpret_cast<::RefX * *>(&::_g_thePlayer)))
                            reinterpret_cast<::PlayerCharacterOps *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_00966ea0(0x400, qJDuOZ->iType == 10);
                        else
                            reinterpret_cast<::FUN_005ce9d0 *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->SetFlag(qJDuOZ->iType == 10);
                    }
                    qfTOqo = qJDuOZ->fRecoil;
                    reinterpret_cast<::FUN_009c86b0_shell *>(this)->FUN_009c86b0();
                    qJDuOZ = 0;
                }
                break;
            }
        }
        if (qfTOqo > 0.0)
        {
            (*reinterpret_cast<::RefX * *>(&::_g_thePlayer))->ApplyRecoil(qfTOqo);
            qfTOqo = 0.0f;
        }
    }
    if (IsEmpty())
    {
        if (::DAT_011f21e0 == 0.0)
        {
            ::DAT_011f21e0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting543))))));
        }
        else
        {
            ::DAT_011f21e0 -= ::fnv::timer::Seconds() * ::FUN_009443f0() / ::FUN_00716440();
            if (::DAT_011f21e0 <= 0.0)
            {
                ::fnv::timer::SetMultiplier(1.0f, false);
                if ((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0)) == (*reinterpret_cast<::RefX * *>(&::DAT_011f21e8)) || (*reinterpret_cast<::RefX * *>(&::DAT_011f21f0)) == (*reinterpret_cast<::RefX * *>(&::DAT_011f21ec)) || reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == -1 ||
                    reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == 7 || reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == 9 ||
                    reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == 0xf || reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::DAT_011f21f0))))->FUN_008a7570() == 0x11)
                {
                    reinterpret_cast<::NiPoint3Interpolator *>(this)->CreateObject(0, false);
                    if (iPerk > 0)
                    {
                        qXGDO = 0.0f;
                        qObI = ((void *)(reinterpret_cast<::FUN_008a1710_shell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_008a1710()));
                        ::ApplyPerkModifiers(0x23, (::Actor *)((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))), qObI ? qObI : (*reinterpret_cast<void * *>(&::DAT_011ca278)), (*reinterpret_cast<::RefX * *>(&::_g_thePlayer)), &qXGDO);
                        if (qXGDO > 0.0)
                            reinterpret_cast<::FUN_0088b740_shell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_0088b740(0xc, qXGDO);
                        iPerk = 0;
                    }
                    ::DAT_011f21e0 = 0.0f;
                }
            }
            else
            {
                ::DAT_011f21d4 += ::fnv::timer::Seconds() / ::FUN_00716440();
                if (pShot && reinterpret_cast<::FUN_0058d630_shell *>((pShot))->FUN_0058d630())
                    reinterpret_cast<::Shot *>((pShot))->UpdateCamera(::DAT_011f21d4);
                if (xbSlowMo)
                    ::fnv::timer::SetMultiplier(0.0001f, false);
                else if (pShot && reinterpret_cast<::FUN_0058d630_shell *>((pShot))->FUN_0058d630())
                    ::fnv::timer::SetMultiplier(reinterpret_cast<::FUN_009d1b30_class *>((void *)(pShot))->GetFloatAtOffset50(), false);
                else
                    ::fnv::timer::SetMultiplier(1.0f, false);
                if (::DAT_011f21e4 && reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_008a7570() != 9 && reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->FUN_008a7570() != 0x11)
                    reinterpret_cast<::OSInputGlobals *>((((::InputX *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OSX * *>(&::g_osGlobals))))->FUN_00877720()))))->FUN_00a24280(6);
            }
        }
    }
    if ((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)) && ((intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())))
        reinterpret_cast<::fnv_009c9ae0::VATS9c9 *>(&((*reinterpret_cast<::TargetsX *>(&::g_011f2250))))->FUN_009c9ae0((::fnv_009c9ae0::ActorObj9c9 *)((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))));
}

class FUN_009c8b90_arg
{
  public:
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0C();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1C();
    virtual int v20();
    virtual int v24();
    virtual int v28();
    virtual int v2C();
    virtual int v30();
    virtual int v34();
    virtual int v38();
    virtual int v3C();
    virtual int v40();
    virtual int v44();
    virtual int v48();
    virtual int v4C();
    virtual int v50();
    virtual int v54();
    virtual int v58();
    virtual int v5C();
    virtual int v60();
    virtual int v64();
    virtual int v68();
    virtual int v6C();
    virtual int v70();
    virtual int v74();
    virtual int v78();
    virtual int v7C();
    virtual int v80();
    virtual int v84();
    virtual int v88();
    virtual int v8C();
    virtual int v90();
    virtual int v94();
    virtual int v98();
    virtual int v9C();
    virtual int vA0();
    virtual int vA4();
    virtual int vA8();
    virtual int vAC();
    virtual int vB0();
    virtual int vB4();
    virtual int vB8();
    virtual int vBC();
    virtual int vC0();
    virtual int vC4();
    virtual int vC8();
    virtual int vCC();
    virtual int vD0();
    virtual int vD4();
    virtual int vD8();
    virtual int vDC();
    virtual int vE0();
    virtual int vE4();
    virtual int vE8();
    virtual int vEC();
    virtual int vF0();
    virtual int vF4();
    virtual int vF8();
    virtual int vFC();
    virtual int v100();
    virtual int v104();
    virtual int v108();
    virtual int v10C();
    virtual int v110();
    virtual int v114();
    virtual int v118();
    virtual int v11C();
    virtual int v120();
    virtual int v124();
    virtual int v128();
    virtual int v12C();
    virtual int v130();
    virtual int v134();
    virtual int v138();
    virtual int v13C();
    virtual int v140();
    virtual int v144();
    virtual int v148();
    virtual int v14C();
    virtual int v150();
    virtual int v154();
    virtual int v158();
    virtual int v15C();
    virtual int v160();
    virtual int v164();
    virtual int v168();
    virtual int v16C();
    virtual int v170();
    virtual int v174();
    virtual int v178();
    virtual int v17C();
    virtual int v180();
    virtual int v184();
    virtual int v188();
    virtual int v18C();
    virtual int v190();
    virtual int v194();
    virtual int v198();
    virtual int v19C();
    virtual int v1A0();
    virtual int v1A4();
    virtual int v1A8();
    virtual int v1AC();
    virtual int v1B0();
    virtual int v1B4();
    virtual int v1B8();
    virtual int v1BC();
    virtual int v1C0();
    virtual int v1C4();
    virtual int v1C8();
    virtual int v1CC();
    virtual void* v1D0();
};

class FUN_009c8b90_sub
{
  public:
    void T(int v);
};

class FUN_009c8b90_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_009c8b90_sub* m_pEntryObject;
    int unk14;
    int unk18;
    FUN_009c8b90_arg* m_1c;
    void FUN_009c8b90(FUN_009c8b90_arg* a1);
};

// @fnv 0x009c8b90
void FUN_009c8b90_cls::FUN_009c8b90(FUN_009c8b90_arg* a1)
{
    if (m_pEntryObject != 0)
    {
        if (((intptr_t)(reinterpret_cast<::Twin_00639b40 *>((m_pEntryObject))->GetEntryPoint())) == 1)
        {
            if (a1 != 0)
            {
                reinterpret_cast<::Owner_58cbc0 *>((m_pEntryObject))->SetNode((::Node_58cbc0 *)(a1->v1D0()));
            }
            else
            {
                reinterpret_cast<::Owner_58cbc0 *>((m_pEntryObject))->SetNode((::Node_58cbc0 *)(0));
            }
        }
        if (((intptr_t)(reinterpret_cast<::LowProcess *>((m_pEntryObject))->GetTarget())) == 1)
        {
            if (a1 != 0)
            {
                reinterpret_cast<::FUN_0058ccf0_Class *>((m_pEntryObject))->SetSceneNode((::SceneNode *)(a1->v1D0()));
            }
            else
            {
                reinterpret_cast<::FUN_0058ccf0_Class *>((m_pEntryObject))->SetSceneNode((::SceneNode *)(0));
            }
        }
    }
    m_1c = a1;
}

struct Ret_9d1b70
{
    int m_v;
};
struct FUN_009d1b70_Class
{
    char pad_0[0xa4];
    Ret_9d1b70 m_a4;
    Ret_9d1b70 GetA4();
};
// @fnv 0x009d1b70
Ret_9d1b70 FUN_009d1b70_Class::GetA4()
{
    return m_a4;
}


struct FUN_009d4f50_vec
{
    float x, y, z;
};

struct FUN_009d4f50_vt
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual FUN_009d4f50_vec* v125();
};

struct FUN_009d4f50_obj
{
};

struct FUN_009d4f50_cls
{
    int unk00;
    FUN_009d4f50_obj* m_04;
    bool FUN_009d4f50();
};

// @fnv 0x009d4f50
bool FUN_009d4f50_cls::FUN_009d4f50()
{
    FUN_009d4f50_vec local24;
    FUN_009d4f50_vec local18;
    FUN_009d4f50_vec local0c;
    if (!reinterpret_cast<::FUN_00998a30_shell *>((m_04))->FUN_00998a30())
    {
        return false;
    }
    local18 = *((::FUN_009d4f50_vt *)(reinterpret_cast<::AlchemyItem *>((m_04))->FUN_004030b0()))->v125();
    local0c = *((::FUN_009d4f50_vt *)(std::uintptr_t)(::GetFieldBC((::FUN_0097ae90_Class *)(m_04))))->v125();
    reinterpret_cast<::FUN_00439ef0_class *>(&(local18))->FUN_00439ef0((::NiPoint3 *)(::FUN_009d4f50_vec *)(&local24), (*(const ::NiPoint3 *)(&local0c)));
    if (reinterpret_cast<::TESCombatStyle *>(&(local24))->UpdateCombatStyle() < DAT_0108e058)
    {
        return false;
    }
    return true;
}

struct LinkedObject
{
};

struct FUN_009d9ee0_Class
{
    char pad[0xb4];
    char unkb4;
    void FUN_009d9ee0(LinkedObject* linked);
};

// @fnv 0x009d9ee0
void FUN_009d9ee0_Class::FUN_009d9ee0(LinkedObject* linked)
{
    reinterpret_cast<::FUN_0069cfe0_cls *>((linked))->CopyElementsTo((::FUN_0069cfe0_Dst *)(void *)(&unkb4));
}

struct RefPtrStub
{
    void* m_pObject;
    RefPtrStub(void* object);
    ~RefPtrStub();
    RefPtrStub& operator=(void* object);
};

struct QueuePtrStub
{
    void* m_pObject;
    QueuePtrStub(void* object);
    ~QueuePtrStub();
    QueuePtrStub& operator=(void* object);
};

struct PathLocStub
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
    PathLocStub();
    ~PathLocStub();
};

class FUN_009dad00
{
  public:
    NiPoint3 pos04;
    NiPoint3 pos10;
    RefPtrStub ptr1C;
    RefPtrStub ptr20;
    int unk24;
    int unk28;
    int unk2C;
    QueuePtrStub queue30;
    int unk34;
    int unk38;
    int unk3C;
    unsigned short unk40;
    unsigned short unk42;
    PathLocStub loc44;
    int unk6C;
    char unk70;
    char unk71;
    char unk72;
    char unk73;
    char unk74;
    char unk75;
    char unk76;
    char unk77;
    char unk78;
    int unk7C;
    int unk80;
    int unk84;

    FUN_009dad00(int param);
    virtual ~FUN_009dad00();
};

// Initializes the object's fields: zeroes pointers and positions, stores param in unk28, sets unk34 to 0x101, calls Reset(0), and sets unk40/unk42 to 0xffff.
// @fnv 0x009dad00
FUN_009dad00::FUN_009dad00(int param)
    : pos04(::NiPoint3::ZERO), pos10(::NiPoint3::ZERO), ptr1C(0), ptr20(0), queue30(0), unk6C(0)
{
    unk28 = param;
    ptr1C = 0;
    ptr20 = 0;
    reinterpret_cast<::FakeHolder *>((void *)&(const ::QueuePtrStub &)(queue30))->AssignObject(0);
    unk24 = 0;
    unk2C = 0;
    unk34 = 0x101;
    reinterpret_cast<::ActorMovement::Mover *>(this)->SetEnabled(0);
    unk40 = 0xffff;
    unk42 = 0xffff;
    unk75 = 0;
    unk77 = 0;
    unk72 = 0;
    unk74 = 0;
    unk76 = 0;
    unk73 = 0;
    unk71 = 0;
    unk78 = 0;
    unk38 = 0;
    unk3C = 0;
    unk7C = 0;
    unk80 = 0;
    unk84 = 0;
}

extern void* DAT_0109231c;

struct FUN_009dfd70_Sub
{
    int unk00;

    FUN_009dfd70_Sub(int aFlag);
    ~FUN_009dfd70_Sub();
};

struct FUN_009dfd70_cls
{
    void* m_vptr;
    int m_04;
    int m_08;
    FUN_009dfd70_Sub m_0c;
    FUN_009dfd70_Sub m_10;

    FUN_009dfd70_cls(int aA, int aB);
};

// Initializes the object: sets the vtable pointer, stores aA in m_04 and aB in m_08, and default-constructs m_0c and m_10 with 0.
// @fnv 0x009dfd70
FUN_009dfd70_cls::FUN_009dfd70_cls(int aA, int aB) : m_vptr(&DAT_0109231c), m_04(aA), m_08(aB), m_0c(0), m_10(0)
{}

struct FUN_009dfe40_Sub
{
    int unk00;

    FUN_009dfe40_Sub(int aValue);
    ~FUN_009dfe40_Sub();
};

struct FUN_009dfe40_Tail
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    FUN_009dfe40_Tail(int aValue);
};

struct FUN_009dfe40_cls
{
    virtual ~FUN_009dfe40_cls();
    int m_04;
    int m_08;
    FUN_009dfe40_Sub m_0c;
    FUN_009dfe40_Tail m_10;

    FUN_009dfe40_cls(intptr_t a1, intptr_t a2, intptr_t a3, intptr_t a4);
};

// Initializes m_04, m_08, m_0c and m_10 from the four constructor arguments.
// @fnv 0x009dfe40
FUN_009dfe40_cls::FUN_009dfe40_cls(intptr_t aiField04, intptr_t aiField08, intptr_t aiSubValue, intptr_t aiTailValue)
    : m_04(aiField04), m_08(aiField08), m_0c(aiSubValue), m_10(aiTailValue)
{}

class SubObj_b4171
{
  public:
    unsigned int m_00;
    ~SubObj_b4171();
};

class FUN_009dfed0_cls
{
  public:
    virtual void Update();
    unsigned int m_04;
    unsigned int m_08;
    SubObj_b4171 m_0c;
    SubObj_b4171 m_10;
    ~FUN_009dfed0_cls();
};

// @fnv 0x009dfed0
FUN_009dfed0_cls::~FUN_009dfed0_cls()
{}

namespace fnv_009ca680 {
class FUN_009ca680
{
  public:
    int* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_009ca680();
};
// @fnv 0x009ca680
FUN_009ca680::FUN_009ca680()
{
    m_iWordAt00 = &::DAT_01090874;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
}
}  // namespace fnv_009ca680

class NiNode
{
  public:
    void IncRefCount();
    void DecRefCount();
};
struct FUN_009c6b30 : BSSimpleList<int>
{
    char pad[0x34 - 8];
    NiPointer<NiNode> m_spNode;
    ~FUN_009c6b30();
};
// @fnv 0x009c6b30
FUN_009c6b30::~FUN_009c6b30()
{
    reinterpret_cast<::BGSCameraShot *>(this)->ResetCameraShot();
}

namespace ProjectileImpact {

struct ImpPoint
{
    float x, y, z;
    ImpPoint();
    ImpPoint(float afX, float afY, float afZ);
};

struct ImpRotation
{
};

struct ImpCamera
{
};

struct ImpExtraList;

struct ImpTarget
{
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a00a();
    virtual void a00b();
    virtual void a00c();
    virtual void a00d();
    virtual void a00e();
    virtual void a00f();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void a019();
    virtual void a01a();
    virtual void a01b();
    virtual void a01c();
    virtual void a01d();
    virtual void a01e();
    virtual void a01f();
    virtual void a020();
    virtual void a021();
    virtual void a022();
    virtual void a023();
    virtual void a024();
    virtual void a025();
    virtual void a026();
    virtual void a027();
    virtual void a028();
    virtual void a029();
    virtual void a02a();
    virtual void a02b();
    virtual void a02c();
    virtual void a02d();
    virtual void a02e();
    virtual void a02f();
    virtual void a030();
    virtual void a031();
    virtual void a032();
    virtual void a033();
    virtual void a034();
    virtual void a035();
    virtual void a036();
    virtual void a037();
    virtual void a038();
    virtual void a039();
    virtual void a03a();
    virtual void a03b();
    virtual void a03c();
    virtual void a03d();
    virtual void a03e();
    virtual void a03f();
    virtual bool IsActor();
};

struct ImpSoundDesc
{
};

struct ImpTexture
{
    virtual void t000();
    virtual void t001();
    virtual void t002();
    virtual void t003();
    virtual void t004();
    virtual const char* FUN_vt14();
};

struct ImpImpact
{
    char pad00[0x18];
    ImpTexture kTexture;
    void* FUN_006733e0();
    unsigned char FUN_004a4140();
    unsigned char CallMemberAtOffset54();
    unsigned char FUN_004a4100();
    unsigned char FUN_004a41e0();
};

struct ImpImpactSet
{
};

struct ImpSurface
{
};

struct ImpHit
{
    char pad00[8];
    ImpSurface* pSurfaceInfo;
    int iMaterialIndex;
};

struct ImpHitList
{
};

struct ImpResults
{
    int iData[70];
    ImpResults();
    ~ImpResults();
};

struct ImpDecal
{
};

struct ImpCell
{
};

struct ImpMaterialSet
{
    virtual void s000();
    virtual void s001();
    virtual void s002();
    virtual void s003();
    virtual void s004();
    virtual void s005();
    virtual void s006();
    virtual void s007();
    virtual void s008();
    virtual void s009();
    virtual void s00a();
    virtual void s00b();
    virtual void s00c();
    virtual void s00d();
    virtual void s00e();
    virtual void s00f();
    virtual void s010();
    virtual void s011();
    virtual void s012();
    virtual void s013();
    virtual void s014();
    virtual void s015();
    virtual void s016();
    virtual void s017();
    virtual void s018();
    virtual void s019();
    virtual void s01a();
    virtual void s01b();
    virtual void s01c();
    virtual void s01d();
    virtual void s01e();
    virtual void s01f();
    virtual void s020();
    virtual void s021();
    virtual void s022();
    virtual void s023();
    virtual void s024();
    virtual void s025();
    virtual void s026();
    virtual void s027();
    virtual void s028();
    virtual void s029();
    virtual void s02a();
    virtual void s02b();
    virtual void s02c();
    virtual void s02d();
    virtual void s02e();
    virtual void s02f();
    virtual void s030();
    virtual void s031();
    virtual void s032();
    virtual void s033();
    virtual void s034();
    virtual void s035();
    virtual void s036();
    virtual void s037();
    virtual int FUN_vte0(int aiIndex);
};

struct ImpMaterial
{
    virtual void m000();
    virtual void m001();
    virtual void m002();
    virtual void m003();
    virtual void m004();
    virtual void m005();
    virtual void m006();
    virtual void m007();
    virtual void m008();
    virtual void m009();
    virtual void m00a();
    virtual void m00b();
    virtual void m00c();
    virtual void m00d();
    virtual void m00e();
    virtual void m00f();
    virtual void m010();
    virtual void m011();
    virtual void m012();
    virtual void m013();
    virtual void m014();
    virtual void m015();
    virtual void m016();
    virtual void m017();
    virtual void m018();
    virtual void m019();
    virtual void m01a();
    virtual void m01b();
    virtual void m01c();
    virtual void m01d();
    virtual void m01e();
    virtual void m01f();
    virtual void m020();
    virtual void m021();
    virtual void m022();
    virtual void m023();
    virtual void m024();
    virtual void m025();
    virtual void m026();
    virtual void m027();
    virtual void m028();
    virtual void m029();
    virtual void m02a();
    virtual void m02b();
    virtual void m02c();
    virtual void m02d();
    virtual void m02e();
    virtual void m02f();
    virtual void m030();
    virtual void m031();
    virtual void m032();
    virtual ImpMaterialSet* FUN_vtcc();
};

struct ImpSkin
{
    int iData;
    ImpSkin(void* apObject);
};

struct ImpAttach
{
};

struct ImpAttachHandle
{
    int iData[2];
    ImpAttachHandle();
};

struct ImpDecalParams
{
    ImpPoint kPosOut;
    ImpPoint kNormal;
    int iPad18[4];
    ImpAttach* pAttach;
    int iPad2c;
    void* m_pDecalData;
    int iPad34;
    float m_fGlyphWidthInPixels;
    float m_fGlyphExtent;
    float m_fProjectionDepth;
    float fPathHeading;
    int iPad48;
    float fParallax;
    int iPad50;
    float m_fShininess;
    float m_fSpecularStrength;
    int iPad5c;
    ImpPoint kColor;
    int iPad6c;
    unsigned char m_ucClipIdentifier;
    unsigned char ucPad71;
    unsigned char ucPad72;
    unsigned char ucFlagA;
    unsigned char ucFlagB;
    unsigned char ucFlagC;
    unsigned char ucFlagD;
    unsigned char ucPad77;
    unsigned char ucPad78;
    unsigned char ucSkinned;
    unsigned char ucPad7a;
    unsigned char ucPad7b;
    ImpDecalParams();
};

struct ImpDecalManager
{
};

struct ImpDecalSystem
{
};

struct ImpShooterProcess
{
    virtual void x000();
    virtual void x001();
    virtual void x002();
    virtual void x003();
    virtual void x004();
    virtual void x005();
    virtual void x006();
    virtual void x007();
    virtual void x008();
    virtual void x009();
    virtual void x00a();
    virtual void x00b();
    virtual void x00c();
    virtual void x00d();
    virtual void x00e();
    virtual void x00f();
    virtual void x010();
    virtual void x011();
    virtual void x012();
    virtual void x013();
    virtual void x014();
    virtual void x015();
    virtual void x016();
    virtual void x017();
    virtual void x018();
    virtual void x019();
    virtual void x01a();
    virtual void x01b();
    virtual void x01c();
    virtual void x01d();
    virtual void x01e();
    virtual void x01f();
    virtual void x020();
    virtual void x021();
    virtual void x022();
    virtual void x023();
    virtual void x024();
    virtual void x025();
    virtual void x026();
    virtual void x027();
    virtual void x028();
    virtual void x029();
    virtual void x02a();
    virtual void x02b();
    virtual void x02c();
    virtual void x02d();
    virtual void x02e();
    virtual void x02f();
    virtual void x030();
    virtual void x031();
    virtual void x032();
    virtual void x033();
    virtual void x034();
    virtual void x035();
    virtual void x036();
    virtual void x037();
    virtual void x038();
    virtual void x039();
    virtual void x03a();
    virtual void x03b();
    virtual void x03c();
    virtual void x03d();
    virtual void x03e();
    virtual void FUN_vtfc(struct ImpShooter* apShooter, ImpPoint kPosOut, int aiValue, int a4, int a5);
};

struct ImpShooter
{
};

struct ImpOwnerRef
{
};

struct ImpSound
{
    int iData[3];
    ~ImpSound();
};

struct ImpAudio
{
    ImpSound FUN_00ad7480(void* apSound, int aiFlags, ImpSoundDesc* apDesc);
};

struct ImpFloatSetting
{
};

float __cdecl FUN_00406cc0(float afValue);
ImpAttachHandle __cdecl FUN_00c85ef0(void* apObject, void* apType);
ImpPoint __cdecl FUN_004a3760(float afScale, const ImpPoint& arPoint);
void __cdecl FUN_006890b0(ImpCell* apCell, float afSize, const char* apTexture, ImpPoint kWorldPosition, ImpPoint kPos,
                          float afScale, int aiFlags, int a7);

struct ImpProjectile
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p00a();
    virtual void p00b();
    virtual void p00c();
    virtual void p00d();
    virtual void p00e();
    virtual void p00f();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p01a();
    virtual void p01b();
    virtual void p01c();
    virtual void p01d();
    virtual void p01e();
    virtual void p01f();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p02a();
    virtual void p02b();
    virtual void p02c();
    virtual void p02d();
    virtual void p02e();
    virtual void p02f();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p03a();
    virtual void p03b();
    virtual void p03c();
    virtual void p03d();
    virtual void p03e();
    virtual void p03f();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p04a();
    virtual void p04b();
    virtual void p04c();
    virtual void p04d();
    virtual void p04e();
    virtual void p04f();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual ImpOwnerRef* FUN_vt168();
    char pad04[0xf4];
    ImpImpactSet* pImpacts;
    char padfc[8];
    ImpRotation kRotationBasis;
    char pad105[0x1f];
    float m_fLifetime;

    void ApplyImpact(ImpTarget* apTarget, ImpPoint* apPos, ImpPoint* apNormal, intptr_t a4, int aiMaterial);
};

// Applies impact decals, splatter, and sounds to the target surface at apPos using pImpacts and aiMaterial.
// @fnv 0x009c20e0
void ImpProjectile::ApplyImpact(ImpTarget* apTarget, ImpPoint* apPos, ImpPoint* apNormal, intptr_t a4, int aiMaterial)
{
    bool bSplatterTmp = true;
    ImpPoint kDelta = Point3Difference(*(const ::ProjectileImpact::ImpPoint *)((void *)(apPos)), (const void *)&(*((::ProjectileImpact::ImpPoint *)(::FUN_0045bb80((std::intptr_t)(((::ProjectileImpact::ImpCamera *)(::FUN_00524c90()))))))));
    if (((bool)(::FUN_00525420())) || reinterpret_cast<::NiPoint3 *>((void *)&(kDelta))->ComputeMagnitude() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::ProjectileImpact::ImpFloatSetting *>(&::originalRuntimeFloatSetting642)))))) ||
        !::FUN_004b61d0((*(::NiPoint3 *)&(const ::ProjectileImpact::ImpPoint &)(*apPos)), (::NiCamera *)(::ProjectileImpact::ImpCamera *)(((::ProjectileImpact::ImpCamera *)(::FUN_00524c90()))), 32.0f))
        bSplatterTmp = false;
    if (!apTarget || !apTarget->IsActor())
    {
        if (apTarget)
        {
            ::FUN_005ac750((::TESForm *)(void *)(this), (::ExtraDataList *)(::ProjectileImpact::ImpExtraList *)(((::ProjectileImpact::ImpExtraList *)(reinterpret_cast<::FUN_005d43c0_ *>((apTarget))->FUN_005d43c0()))), 0x80);
            if (pImpacts)
                ::FUN_005ac750((::TESForm *)(pImpacts), (::ExtraDataList *)(::ProjectileImpact::ImpExtraList *)(((::ProjectileImpact::ImpExtraList *)(reinterpret_cast<::FUN_005d43c0_ *>((apTarget))->FUN_005d43c0()))), 0x100);
        }
        int iMaterial = aiMaterial;
        ImpImpact* pImpactTmp = pImpacts ? ((::ProjectileImpact::ImpImpact *)(std::uintptr_t)(reinterpret_cast<::FUN_00522ba0_obj *>((pImpacts))->FUN_00522ba0(iMaterial))) : 0;
        if (pImpactTmp)
        {
            void* m_pDecalData = pImpactTmp->FUN_006733e0();
            if (m_pDecalData)
            {
                ImpPoint kNormal = *apNormal;
                reinterpret_cast<::FUN_004a0c10_s *>(&(kNormal))->FUN_004a0c10();
                ImpPoint kPosOut = *apPos;
                if (m_fLifetime == 0.0)
                    m_fLifetime = ::RandomFloat(reinterpret_cast<::FUN_004a40a0_Class *>((pImpactTmp))->FUN_004a40a0(), reinterpret_cast<::FUN_004a40c0_Class *>((pImpactTmp))->GetModifierValue());
                ImpDecal* pNewDecal = ((::ProjectileImpact::ImpDecal *)(::ScreenSplatter::Activate(m_fLifetime, 1)));
                reinterpret_cast<::FUN_006233c0 *>((pNewDecal))->GetImpactDataForMaterial(0);
                reinterpret_cast<::Unk *>((pNewDecal))->FUN_004a1a10(8, 0);
                reinterpret_cast<::Unk *>((pNewDecal))->FUN_004a1a10(0x1d, 0);
                ImpCell* pCellPtr = ((::ProjectileImpact::ImpCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
                void* pCellNode = pCellPtr ? reinterpret_cast<::FUN_004543c0_cls *>((pCellPtr))->FUN_004543c0() : 0;
                if (pCellNode)
                {
                    reinterpret_cast<::Owner623 *>((pNewDecal))->FUN_006231a0((::NiNode623 *)(pCellNode));
                    ImpResults kResultsVal;
                    reinterpret_cast<::fnv_00623090::Host *>((pNewDecal))->FUN_00623090(apPos, (::fnv_00623090::Vir *)(::ProjectileImpact::ImpResults *)(&kResultsVal));
                    int iTheCount = ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((::ProjectileImpact::ImpHitList *)(reinterpret_cast<::TESTopicInfoData *>(&(kResultsVal))->GetLinkToList()))))->FUN_00726070()));
                    float fPathHeading = ((float)(::FUN_004a4240()));
                    unsigned char m_ucClipIdentifier = (int)FUN_00406cc0(::RandomFloat(0.0f, 4.0f));
                    ImpSurface* pLastSurface = 0;
                    for (int i = 0; i < iTheCount; i++)
                    {
                        ImpSurface* pSurfaceInfo = ((::ProjectileImpact::ImpHit *)(reinterpret_cast<::FUN_0062e150_cls *>((((::ProjectileImpact::ImpHitList *)(reinterpret_cast<::TESTopicInfoData *>(&(kResultsVal))->GetLinkToList()))))->FUN_0062e150(i)))->pSurfaceInfo;
                        if (pSurfaceInfo)
                        {
                            int iSurfaceMaterialCur = aiMaterial;
                            int iMaterialIndex = ((::ProjectileImpact::ImpHit *)(reinterpret_cast<::FUN_0062e150_cls *>((((::ProjectileImpact::ImpHitList *)(reinterpret_cast<::TESTopicInfoData *>(&(kResultsVal))->GetLinkToList()))))->FUN_0062e150(i)))->iMaterialIndex;
                            if (iMaterialIndex != -1)
                            {
                                ImpMaterial* pMaterial = ((::ProjectileImpact::ImpMaterial *)(std::uintptr_t)(::FUN_004a3a40((::TESObjectREFR *)(void *)(((void *)(::FUN_00559450((int *)(pSurfaceInfo))))))));
                                if (!pMaterial)
                                    continue;
                                ImpMaterialSet* pSet = pMaterial->FUN_vtcc();
                                if (pSet)
                                    iSurfaceMaterialCur = pSet->FUN_vte0(iMaterialIndex);
                            }
                            else
                            {
                                ImpMaterial* pSingle = ((::ProjectileImpact::ImpMaterial *)(std::uintptr_t)(::FUN_004a3a40((::TESObjectREFR *)(void *)(((void *)(::FUN_00559450((int *)(pSurfaceInfo))))))));
                                if (!pSingle)
                                    continue;
                                iSurfaceMaterialCur = reinterpret_cast<::FUN_006205a0_Class *>((pSingle))->FUN_006205a0();
                            }
                            if (iSurfaceMaterialCur == aiMaterial && pSurfaceInfo != pLastSurface)
                            {
                                pLastSurface = pSurfaceInfo;
                                bool bHasAnimation = ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::ProjectileImpact::ImpSkin &)(ImpSkin(((void *)(::FUN_0043b540((char *)(pSurfaceInfo)))))))->FUN_004a3a20())) == 1;
                                ImpAttach* pAttach = 0;
                                if (bHasAnimation)
                                {
                                    void* pSkinRoot = ::FUN_004b59f0(pSurfaceInfo);
                                    if (pSkinRoot)
                                    {
                                        ImpAttachHandle kAttachHandle = FUN_00c85ef0(pSkinRoot, &(*reinterpret_cast<char *>(&::g_011f4a20)));
                                        pAttach = ((::ProjectileImpact::ImpAttach *)(::FUN_00559450((int *)&(kAttachHandle))));
                                        if (pAttach && ((::ProjectileImpact::ImpAttach *)(reinterpret_cast<::FUN_009611e0_shell *>((pAttach))->FUN_009611e0())))
                                            pAttach = ((::ProjectileImpact::ImpAttach *)(reinterpret_cast<::FUN_009611e0_shell *>((pAttach))->FUN_009611e0()));
                                    }
                                }
                                else
                                {
                                    pAttach = ((::ProjectileImpact::ImpAttach *)(std::uintptr_t)(::FUN_00c7fa90((::S_Obj *)(pSurfaceInfo))));
                                }
                                void* pGeometryRef = ((void *)(::FUN_0056f930((::NiAVObject *)(pAttach))));
                                if (!bHasAnimation &&
                                    (!pGeometryRef || !::IsAcousticSpaceFormTypeAllowed((::Refr_C *)(pGeometryRef), 1)))
                                    continue;
                                ImpDecalManager* pManager = ((::ProjectileImpact::ImpDecalManager *)(reinterpret_cast<::FnCls *>(((*reinterpret_cast<::ProjectileImpact::ImpDecalSystem * *>(&::g_TES))))->FUN_004519d0((*(float *)&(const ::ProjectileImpact::ImpPoint &)(*apPos)), {}, {})));
                                ImpDecalParams kParamsCur;
                                kParamsCur.kPosOut = kPosOut;
                                kParamsCur.kNormal = kNormal;
                                kParamsCur.m_fGlyphWidthInPixels = m_fLifetime;
                                kParamsCur.m_fGlyphExtent = m_fLifetime;
                                kParamsCur.m_fProjectionDepth = reinterpret_cast<::FUN_008aff10_obj *>((pImpactTmp))->GetNestedValue();
                                kParamsCur.pAttach = pAttach;
                                kParamsCur.m_pDecalData = m_pDecalData;
                                kParamsCur.fPathHeading = fPathHeading;
                                kParamsCur.m_ucClipIdentifier = m_ucClipIdentifier;
                                kParamsCur.ucFlagC = pImpactTmp->FUN_004a4140();
                                kParamsCur.ucFlagB = pImpactTmp->CallMemberAtOffset54();
                                kParamsCur.ucFlagA = pImpactTmp->FUN_004a4100();
                                kParamsCur.fParallax = reinterpret_cast<::FUN_004a41c0 *>((pImpactTmp))->GetRadius();
                                kParamsCur.ucFlagD = pImpactTmp->FUN_004a41e0();
                                kParamsCur.m_fShininess = reinterpret_cast<::fnv_004a40e0::FUN_004a40e0 *>((pImpactTmp))->GetHealthRegeneration();
                                kParamsCur.m_fSpecularStrength = reinterpret_cast<::BGSImpactData *>((pImpactTmp))->FUN_009a9350();
                                kParamsCur.kColor = ImpPoint(
                                    (unsigned char)(reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((pImpactTmp))->GetNextFromSubobject() & 0xff) / 255.0,
                                    (unsigned char)(((unsigned short)reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((pImpactTmp))->GetNextFromSubobject() >> 8) & 0xff) /
                                        255.0,
                                    (unsigned char)((reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((pImpactTmp))->GetNextFromSubobject() >> 16) & 0xff) / 255.0);
                                if (iSurfaceMaterialCur == 3)
                                    kParamsCur.ucSkinned = 1;
                                reinterpret_cast<::FUN_004a3fe0_shell *>((pManager))->FUN_004a3fe0(&kParamsCur, 1, 0);
                            }
                        }
                    }
                    if (iTheCount > 0)
                        m_fLifetime = 0.0f;
                    pNewDecal = 0;
                }
            }
            if (bSplatterTmp)
            {
                const char* pTexture = pImpactTmp->kTexture.FUN_vt14();
                if (pTexture && *pTexture)
                {
                    ImpPoint kWorldPosition;
                    switch (((intptr_t)(reinterpret_cast<::BGSCameraPath *>((pImpactTmp))->GetPrevPath())))
                    {
                    case 0:
                        kWorldPosition = *apNormal;
                        reinterpret_cast<::FUN_004a0c10_s *>(&(kWorldPosition))->FUN_004a0c10();
                        break;
                    case 1:
                        kWorldPosition = (*(::ProjectileImpact::ImpPoint *)(reinterpret_cast<::P3 *>((void *)&(kRotationBasis))->FUN_004a0bd0({})));
                        reinterpret_cast<::FUN_004a0c10_s *>(&(kWorldPosition))->FUN_004a0c10();
                        break;
                    case 2: {
                        ImpPoint kForward = (*(::ProjectileImpact::ImpPoint *)(reinterpret_cast<::P3 *>((void *)&(kRotationBasis))->FUN_004a0bd0({})));
                        reinterpret_cast<::FUN_004a0c10_s *>(&(kForward))->FUN_004a0c10();
                        ImpPoint kSurface = *apNormal;
                        reinterpret_cast<::FUN_004a0c10_s *>(&(kSurface))->FUN_004a0c10();
                        kWorldPosition =
                            Point3Difference(*(const ::ProjectileImpact::ImpPoint *)((void *)(void *)&(const ::ProjectileImpact::ImpPoint &)(FUN_004a3760(2.0 * reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kSurface))->DotProduct((void *)&(kForward)), kSurface))), (const void *)&(kForward));
                        break;
                    }
                    default:
                        kWorldPosition = *apNormal;
                        reinterpret_cast<::FUN_004a0c10_s *>(&(kWorldPosition))->FUN_004a0c10();
                    }
                    FUN_006890b0(((::ProjectileImpact::ImpCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())), reinterpret_cast<::FUN_00508100_shell *>((pImpactTmp))->FUN_00508100(), pTexture, kWorldPosition, *apPos, 1.0f, 7,
                                 0);
                }
            }
            ImpOwnerRef* pOwnerResult = FUN_vt168();
            if (pOwnerResult && ((::ProjectileImpact::ImpShooter *)(::FUN_00559450((int *)(pOwnerResult)))))
            {
                ImpShooter* WeaponHitData = ((::ProjectileImpact::ImpShooter *)(::FUN_00559450((int *)(pOwnerResult))));
                if (((::ProjectileImpact::ImpShooterProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((WeaponHitData))->GetBaseTexture())))
                    ((::ProjectileImpact::ImpShooterProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((WeaponHitData))->GetBaseTexture()))->FUN_vtfc(WeaponHitData, *apPos, reinterpret_cast<::FUN_0058e790_S *>((pImpactTmp))->GetGlobalValue(), 0, 0);
            }
            ImpSoundDesc* SoundAssetTmp = ((::ProjectileImpact::ImpSoundDesc *)(std::uintptr_t)(reinterpret_cast<::FUN_0068a810_class *>((pImpactTmp))->GetField4C()));
            if (SoundAssetTmp)
            {
                ImpSound kSound = ((::ProjectileImpact::ImpAudio *)(::FUN_00453a70()))->FUN_00ad7480(((void *)(::FUN_00511840((char *)(SoundAssetTmp)))), 0x4102, SoundAssetTmp);
                reinterpret_cast<::FUN_00ad8b60_h *>(&(kSound))->FUN_00ad8b60(apPos->x, apPos->y, apPos->z);
                reinterpret_cast<::FUN_00ad8830_shell *>(&(kSound))->FUN_00ad8830(0);
            }
            ImpSoundDesc* pSound2New = ((::ProjectileImpact::ImpSoundDesc *)(reinterpret_cast<::FUN_0068a830_shell *>((pImpactTmp))->GetGrass()));
            if (pSound2New)
            {
                ImpSound kSound2 = ((::ProjectileImpact::ImpAudio *)(::FUN_00453a70()))->FUN_00ad7480(((void *)(::FUN_00511840((char *)(pSound2New)))), 0x4102, pSound2New);
                reinterpret_cast<::FUN_00ad8b60_h *>(&(kSound2))->FUN_00ad8b60(apPos->x, apPos->y, apPos->z);
                reinterpret_cast<::FUN_00ad8830_shell *>(&(kSound2))->FUN_00ad8830(0);
            }
        }
    }
}

}

#include "generated/data/staging/blk_009c0000_od.inc"

