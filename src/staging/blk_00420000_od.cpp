
// src/staging/blk_00420000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include <new>
#include <cstring>
#include <cmath>
#include <intrin.h>
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040ec80_cls.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_0040fe80_shell.h"
#include "fnv/decl/FUN_00410020_t.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0041d390_shell.h"
#include "fnv/decl/FUN_0042e010_ExtraLock.h"
#include "fnv/decl/FUN_00435de0_ctor.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_0049fa20_List.h"
#include "fnv/decl/FUN_004b0460_class.h"
#include "fnv/decl/FUN_004fbf00_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00761540_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00898280.h"
#include "fnv/decl/FUN_00935ae0_t.h"
#include "fnv/decl/FUN_0094db80_shell.h"
#include "fnv/decl/Flag512Receiver.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/Holder0042f780.h"
#include "fnv/decl/Host096d450.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_0066e2b0_Class.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaitableObject.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00420440__FUN_00420440_shell.h"
#include "fnv/decl/fnv_00422c20__FUN_0042dec0_shell.h"
#include "fnv/decl/fnv_00436180__FUN_00436180.h"
#include "fnv/decl/fnv_004363c0__FUN_004363c0.h"
#include "fnv/decl/fnv_004364e0__FUN_004364e0.h"
#include "fnv/decl/fnv_00436600__FUN_00436600.h"
#include "fnv/decl/fnv_00436720__FUN_00436720.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00565480__RefPersistsStandin.h"
#include "fnv/decl/fnv_00569880__FUN_00569880_cls.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040b000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00433000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005f3000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "../../include/layout_support.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_00575700__RefrV.h"
#include "fnv/symbols_00439000.h"
#include "fnv/symbols_0043a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_006b3000.h"

struct BaseExtraList
{
};

struct FUN_004216d0_shell
{
    bool FUN_004216d0();
};

// @fnv 0x004216d0
bool FUN_004216d0_shell::FUN_004216d0()
{
    return reinterpret_cast<::FUN_0040fe80_shell *>((((BaseExtraList*)this)))->HasExtraType(0x2e);
}

struct FUN_0042ce90_class
{
    char pad[0x28];
    int unk28;
    bool FUN_0042ce90() const;
};

// @fnv 0x0042ce90
bool FUN_0042ce90_class::FUN_0042ce90() const
{
    return (unk28 & 8) ? true : false;
}

namespace fnv_0042e040 {
struct BaseExtraList
{
    void RemoveExtra(unsigned char);
};

void BaseExtraList::RemoveExtra(unsigned char)
{}

struct FUN_0042e040_shell
{
    void FUN_0042e040();
};

// @fnv 0x0042e040
void FUN_0042e040_shell::FUN_0042e040()
{
    reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>((((BaseExtraList*)this)))->RemoveExtra(0x4d);
}
}  // namespace fnv_0042e040

namespace fnv_0042e110 {
struct BSExtraData;
struct BaseExtraList
{
};
struct FUN_0042e110 : BaseExtraList
{
    BSExtraData* GetExtraData();
};
// @fnv 0x0042e110
BSExtraData* FUN_0042e110::GetExtraData()
{
    BSExtraData* result = ((::fnv_0042e110::BSExtraData *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x55)));
    return result;
}
}  // namespace fnv_0042e110

extern "C" void* __cdecl DAT_010159e8;

struct FUN_0042f4e0_class
{
    void* m_vtbl;
    void* FUN_0042f4e0(void* arg);
};

struct FUN_0042ff10_cls
{
    bool FUN_0042ff30(const void** apOther);
};

// @fnv 0x0042ff10
bool FUN_0042ff10(FUN_0042ff10_cls* pTarget, const void** apOther)
{
    return pTarget->FUN_0042ff30(apOther);
}

extern int DAT_01015a08;
struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_0042ff80();
};
// @fnv 0x0042ff80
void GlobalObject_00869f00::FUN_0042ff80()
{
    *(void**)this = &DAT_01015a08;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

extern void* DAT_01015968;

struct BSExtraData
{
    virtual ~BSExtraData();
};

struct FUN_00435ef0 : public BSExtraData
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    void FUN_00435ef0_init();
};

// Sets the vtable pointer, zeroes the field at offset 0xc, then calls the BSExtraData destructor.
// @fnv 0x00435ef0
void FUN_00435ef0::FUN_00435ef0_init()
{
    *reinterpret_cast<void**>(this) = &DAT_01015968;
    this->b = 0;
    ::FUN_0040ecb0((int *)(this));
}

struct FUN_006815c0
{
};

struct FUN_00437dd0_Class
{
    char pad[0x20];
    FUN_006815c0 unk20;
    void* FUN_00437dd0();
};

// @fnv 0x00437dd0
void* FUN_00437dd0_Class::FUN_00437dd0()
{
    return *(void**)(((void *)(new ((void *)(&unk20)) ::Vec3())));
}

extern int DAT_01015fbc;
struct FUN_004383b0_Class
{
    void* p;
    void* FUN_004383b0(void* a);
};
extern "C" void __cdecl FUN_00438820(void*);
extern char DAT_01015fdc;

struct FUN_004383e0_class
{
    void* p;
    void* FUN_004383e0(void* a);
};

// Calls FUN_00438820 with this and a, sets p to the address of DAT_01015fdc, and returns this.
// @fnv 0x004383e0
void* FUN_004383e0_class::FUN_004383e0(void* apArg)
{
    ((void(*)(void*, void*))FUN_00438820)(this, apArg);
    p = &DAT_01015fdc;
    return this;
}


struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_00438570();
};

// @fnv 0x00438570
AX* AX::FUN_00438570()
{
    *reinterpret_cast<const void**>(this) = &DAT_01015ffc;
    FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_004385a0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_004385a0Class
{
    void FUN_004385a0();
};
// @fnv 0x004385a0
void FUN_004385a0Class::FUN_004385a0()
{
    *(void**)this = &::DAT_01015ffc;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_004385a0

extern int DAT_01016010;
struct BSSimpleArrayShell
{
    void FUN_00438a60(unsigned int, unsigned int);
    BSSimpleArrayShell* FUN_004385c0();
};
// @fnv 0x004385c0
BSSimpleArrayShell* BSSimpleArrayShell::FUN_004385c0()
{
    *reinterpret_cast<int**>(this) = &DAT_01016010;
    FUN_00438a60(0, 0);
    return this;
}

namespace fnv_00438690 {

struct GlobalObject_00869f00
{
    int* p;
    void Clear(bool);
    void FUN_00438690();
};

// @fnv 0x00438690
void GlobalObject_00869f00::FUN_00438690()
{
    p = &::DAT_01016024;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_00438690


struct FUN_00438940_Item
{
    char pad[8];
    char unk08;
};

struct FUN_00438940_Class
{
    void FUN_00438940(void* p);
};

// Sets byte 8 of p to 0, then passes p to Deallocate.
// @fnv 0x00438940
void FUN_00438940_Class::FUN_00438940(void* p)
{
    static_cast<FUN_00438940_Item*>(p)->unk08 = 0;
    void* tmp = p;
    ::FUN_00401030(tmp);
}

struct FUN_00438b90_class
{
    char pad[8];
    int unk08;
    int unk0c;
    char FUN_00438b90();
};

// @fnv 0x00438b90
char FUN_00438b90_class::FUN_00438b90()
{
    if (unk08 == unk0c)
        return 1;
    return 0;
}

struct FUN_00591300_shell
{
    void FUN_00591300();
};

struct FUN_00438bf0_shell : FUN_00591300_shell
{
    void FUN_00438bf0();
};

// @fnv 0x00438bf0
void FUN_00438bf0_shell::FUN_00438bf0()
{
    FUN_00591300();
}

struct FUN_00438f10_Class
{
    char pad[0xc];
    unsigned char unk0c;
    bool FUN_00438f10();
};

// @fnv 0x00438f10
bool FUN_00438f10_Class::FUN_00438f10()
{
    if (unk0c & 4)
        return true;
    else
        return false;
}

struct FUN_00438f30_Class
{
    unsigned int FUN_00438f30();
};

// @fnv 0x00438f30
unsigned int FUN_00438f30_Class::FUN_00438f30()
{
    return *(unsigned short*)(this + 0xe);
}

struct FUN_004392c0_shell
{
    void FUN_004392c0();
    void FUN_00439320();
};

// @fnv 0x00439320
void FUN_004392c0_shell::FUN_00439320()
{
    FUN_004392c0();
}

struct NiObjectNET
{
    void FUN_00439360(unsigned short a, unsigned int b, unsigned int c);
    void FUN_00439340(unsigned short a);
public:
    void SetFlags(unsigned short);
};

// @fnv 0x00439340
void NiObjectNET::FUN_00439340(unsigned short a)
{
    FUN_00439360(a, 0x1e, 1);
}

namespace fnv_00439390 {
struct NiObjectNET
{
    void FUN_00439390(unsigned short a);
};

// Calls FUN_00439360 with the given unsigned short and the constants 0x1e0 and 5.
// @fnv 0x00439390
void NiObjectNET::FUN_00439390(unsigned short ausValue)
{
    reinterpret_cast<::NiObjectNET *>(this)->FUN_00439360(ausValue, 0x1e0, 5);
}
}  // namespace fnv_00439390

struct NiPoint3
{
    float x, y, z;
};

struct FUN_00439680_class
{
    char pad[0x18];
    NiPoint3 unk18;
    void FUN_00439680(const NiPoint3& p);
};

// Stores the given NiPoint3 into the object at offset 0x18.
// @fnv 0x00439680
void FUN_00439680_class::FUN_00439680(const NiPoint3& aPoint)
{
    unk18 = aPoint;
}

struct FUN_0043b260_Class
{
    char pad[0x18];
    unsigned short m_0018;
    bool FUN_0043b260(unsigned short* pArg);
};

// Compares the 16-bit value at offset 0x18 of this object with the same field of pArg and returns whether they are equal.
// @fnv 0x0043b260
bool FUN_0043b260_Class::FUN_0043b260(unsigned short* pOther)
{
    return m_0018 == reinterpret_cast<FUN_0043b260_Class*>(pOther)->m_0018;
}

struct TaskQueueInterface
{
    void FUN_0043b350(bool enabled);
};

// @fnv 0x0043b350
void TaskQueueInterface::FUN_0043b350(bool enabled)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(enabled, 0x80);
}

struct TESForm
{
public:
    void ClearData();
    virtual ~TESForm();
};

struct TESObjectTREE
{
    TESForm* GetData();
};

struct FUN_0043b5b0_shell
{
    void FUN_0043b5b0();
};

// @fnv 0x0043b5b0
void FUN_0043b5b0_shell::FUN_0043b5b0()
{
    reinterpret_cast<::FUN_004534f0_shell *>((((TESObjectTREE*)this)->GetData()))->FUN_004534f0(1);
}

struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* FUN_0043ba10(FUN_0043ba10_shell*);
};

struct FUN_0043b9f0_shell
{
    char pad[8];
    FUN_0043ba10_shell unk08;
    void FUN_0043b9f0(FUN_0043ba10_shell* p);
};

// @fnv 0x0043b9f0
void FUN_0043b9f0_shell::FUN_0043b9f0(FUN_0043ba10_shell* p)
{
    unk08.FUN_0043ba10(p);
}

struct GO
{
    void* operator=(void*);
};

struct FUN_0043baa0_class
{
    char pad[0x74];
    GO unk74;
    void FUN_0043baa0(void* p);
};

// @fnv 0x0043baa0
void FUN_0043baa0_class::FUN_0043baa0(void* p)
{
    unk74 = p;
}


struct FUN_0043fab0_class
{
    char pad[0x120];
    unsigned char unk120;
    bool FUN_0043fab0();
};

// @fnv 0x0043fab0
bool FUN_0043fab0_class::FUN_0043fab0()
{
    return ((bool)(::fnv_0044ae10::FUN_0044ae10(unk120)));
}

extern "C" void* __cdecl _NiFreeAlias(void*);
extern int DAT_01015a1c;

struct FUN_0042fee0_cls : NiTPointerMap<int, int>
{
    void FUN_0042fee0();
};

// Resets the vtable pointer, removes all entries from the map, and frees the pointer stored at offset 8.
// @fnv 0x0042fee0
void FUN_0042fee0_cls::FUN_0042fee0()
{
    *(void**)this = &DAT_01015a1c;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

extern int DAT_01015f24;

struct BE
{
    BE(unsigned char);
};

struct FUN_00436ac0 : BE
{
    char pad[0xc];
    int unk0c;
    FUN_00436ac0();
};

// Initialises the base with tag 0x55, installs the vtable pointer from DAT_01015f24, and zeroes the field at offset 0xc.
// @fnv 0x00436ac0
FUN_00436ac0::FUN_00436ac0() : BE(0x55)
{
    *reinterpret_cast<int**>(this) = &DAT_01015f24;
    unk0c = 0;
}

namespace fnv_00438780 {

struct NiTPointerMap_00438780
{
    void* m_pVTable;
    int m_nSize;
    void* m_pData;
    void RemoveAll();
    void FUN_00438780();
};

// Sets the vtable pointer, removes all entries, and frees the data buffer via _NiFreeAlias.
// @fnv 0x00438780
void NiTPointerMap_00438780::FUN_00438780()
{
    m_pVTable = &(*reinterpret_cast<void * *>(&::DAT_01016038));
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    _NiFreeAlias(m_pData);
}
}  // namespace fnv_00438780

struct NavMeshPtr
{
    void* FUN_0042ffa0(unsigned int flags);
};
// Calls FUN_0042fa40, then deallocates this if the flags bit 0 is set, and returns this.
// @fnv 0x0042ffa0
void* NavMeshPtr::FUN_0042ffa0(unsigned int flags)
{
    ::FUN_0042fa40((void *)(this));
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0042ffd0_cls : public FUN_0042fee0_cls
{
    void* FUN_0042ffd0(unsigned int flags);
};

// Calls the base cleanup, then frees this object when the flags bit 0 is set, and returns this.
// @fnv 0x0042ffd0
void* FUN_0042ffd0_cls::FUN_0042ffd0(unsigned int flags)
{
    FUN_0042fee0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00435ec0 : public BE
{
    void* vtbl;
    int a;
    int b;
    void* p;
    FUN_00435ec0(void* a);
};
// Initialises the object with base value 0x46, sets its vtable to DAT_01015968 and stores the passed pointer in p.
// @fnv 0x00435ec0
FUN_00435ec0::FUN_00435ec0(void* a) : BE(0x46)
{
    vtbl = &DAT_01015968;
    p = a;
}

struct FUN_00435f20_class : public BE
{
    const char* m_pName;
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    float m_fValue;
    FUN_00435f20_class(float f);
};
// @fnv 0x00435f20
FUN_00435f20_class::FUN_00435f20_class(float f) : BE(0x48)
{
    m_pName = "P_C";
    m_fValue = f;
}

struct FUN_00435f80_shell
{
    void FUN_00435f80();
};
struct FUN_00435f50_class : FUN_00435f80_shell
{
    void* FUN_00435f50(unsigned int flags);
};
extern "C" void* DAT_01015974;
struct FUN_00436090 : public BE
{
    void* vtbl;
    int a;
    int b;
    unsigned char c;
    FUN_00436090(unsigned char);
};
// @fnv 0x00436090
FUN_00436090::FUN_00436090(unsigned char x) : BE(0x4e)
{
    vtbl = &DAT_01015974;
    c = x;
}

struct FUN_00436150_Class
{
    void* FUN_00436150(unsigned int flags);
};
// @fnv 0x00436150
void* FUN_00436150_Class::FUN_00436150(unsigned int flags)
{
    reinterpret_cast<::fnv_00436180::FUN_00436180 *>(this)->fnv_00436180::FUN_00436180::~FUN_00436180();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00436390_Class
{
    void* FUN_00436390(unsigned int flags);
};

// @fnv 0x00436390
void* FUN_00436390_Class::FUN_00436390(unsigned int flags)
{
    reinterpret_cast<::fnv_004363c0::FUN_004363c0 *>(this)->fnv_004363c0::FUN_004363c0::~FUN_004363c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004364b0_Class
{
    void* FUN_004364b0(unsigned int flags);
};
// Calls FUN_004364e0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x004364b0
void* FUN_004364b0_Class::FUN_004364b0(unsigned int flags)
{
    reinterpret_cast<::fnv_004364e0::FUN_004364e0 *>(this)->fnv_004364e0::FUN_004364e0::~FUN_004364e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004365d0_class
{
    void* FUN_004365d0(unsigned int flags);
};
// Calls FUN_00436600, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004365d0
void* FUN_004365d0_class::FUN_004365d0(unsigned int flags)
{
    reinterpret_cast<::fnv_00436600::FUN_00436600 *>(this)->fnv_00436600::FUN_00436600::~FUN_00436600();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void FUN_00436720();

struct FUN_004366f0_class
{
    void FUN_00436720();
    void* FUN_004366f0(unsigned int flags);
};

// Calls FUN_00436720, frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004366f0
void* FUN_004366f0_class::FUN_004366f0(unsigned int flags)
{
    reinterpret_cast<::fnv_00436720::FUN_00436720 *>(this)->fnv_00436720::FUN_00436720::~FUN_00436720();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00436af0_Class
{
    void FUN_00436bb0();
    void* FUN_00436af0(unsigned int flags);
};
void __cdecl FUN_00438720(FUN_004383b0_Class*);
struct FUN_00438410_Class
{
    void* FUN_00438720();
    void* FUN_00438410(unsigned int flags);
};
struct FUN_004388a0_Class
{
    void* FUN_004388a0();
};
struct FUN_00438440_Class
{
    void* FUN_00438440(unsigned int flags);
};
void FUN_004385a0();
struct FUN_00438970_class
{
    void FUN_004385a0();
    void* FUN_00438970(unsigned int flags);
};
// @fnv 0x00438970
void* FUN_00438970_class::FUN_00438970(unsigned int flags)
{
    reinterpret_cast<::fnv_004385a0::FUN_004385a0Class *>(this)->FUN_004385a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004389a0_Class
{
    void* FUN_004385f0();
    void* FUN_004389a0(unsigned int flags);
};
// Calls FUN_004385f0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004389a0
void* FUN_004389a0_Class::FUN_004389a0(unsigned int flags)
{
    FUN_004385f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00438780_Class
{
    void* FUN_00438a00(unsigned int flags);
};
// @fnv 0x00438a00
void* FUN_00438780_Class::FUN_00438a00(unsigned int flags)
{
    reinterpret_cast<::fnv_00438780::NiTPointerMap_00438780 *>(this)->FUN_00438780();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00438900_class
{
    void* vtbl;
    int count;
    void* data;
    int unk0c;
    void FUN_00438900();
};

struct FUN_00438a30_class
{
    void* FUN_00438a30(unsigned int flags);
};

// Calls FUN_00438900 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x00438a30
void* FUN_00438a30_class::FUN_00438a30(unsigned int flags)
{
    ((FUN_00438900_class*)this)->FUN_00438900();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct PointerFlagNode
{
};
struct FUN_004207e0Class
{
    PointerFlagNode* FUN_004207e0();
    void FUN_00420da0(unsigned int);
};
// @fnv 0x00420da0
void FUN_004207e0Class::FUN_00420da0(unsigned int a1)
{
    PointerFlagNode* p = FUN_004207e0();
    if (p)
        reinterpret_cast<::ItemChangeListNode *>((p))->FUN_00905330((::InventoryStackRecord *const &)(a1));
}

struct Flt
{
    operator unsigned int();
};
struct Holder00420dd0_Extra : BSExtraData
{
    char pad[8];
    Flt unk0c;
};
struct Holder00420dd0
{
    unsigned int FUN_00420dd0();
};
// @fnv 0x00420dd0
unsigned int Holder00420dd0::FUN_00420dd0()
{
    BSExtraData* e = reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x78);
    if (e)
        return (unsigned int)(static_cast<Holder00420dd0_Extra*>(e)->unk0c);
    return 0;
}


struct FUN_0042cba0_class : public BE
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    FUN_0042cba0_class();
};

// Initialises the object with base value 0x6e, sets its vtbl to DAT_01015998, and zeroes fields c and d.
// @fnv 0x0042cba0
FUN_0042cba0_class::FUN_0042cba0_class() : BE(0x6e)
{
    vtbl = (void*)&DAT_01015998;
    c = 0;
    d = 0;
}

struct FHolder_42cbe0 : BE
{
    char pad[0xc];
    int unk0c;
    void* FUN_0042cbe0();
};
// Initialises the object with BE(0x70), installs the vtable pointer DAT_010151fc, zeroes the field at offset 0xc, and returns this.
// @fnv 0x0042cbe0
void* FHolder_42cbe0::FUN_0042cbe0()
{
    reinterpret_cast<::FUN_0040ec80_cls *>((this))->init(0x70);
    *(void**)this = (void*)&DAT_010151fc;
    unk0c = 0;
    return this;
}

struct FUN_0042cc10_class
{
    int m0;
    int m4;
    float m8;
    FUN_0042cc10_class* FUN_0042cc10();
};
// Initialises the object's fields to zero, -1 and -1.0f, then returns this.
// @fnv 0x0042cc10
FUN_0042cc10_class* FUN_0042cc10_class::FUN_0042cc10()
{
    m0 = 0;
    m4 = -1;
    m8 = -1.0f;
    return this;
}

struct FUN_00432470 : public BSExtraData
{
    int x;
    int y;
    int z;
    FUN_00432470(int v);
    ~FUN_00432470();
};
struct ExtraListHelper
{
};
struct FUN_0042dee0_shell
{
    void FUN_0042dee0(intptr_t v);
};
// Looks up extra data of type 0x4d; if absent, creates a new FUN_00432470 with v and adds it, otherwise stores v at offset 0xc.
// @fnv 0x0042dee0
void FUN_0042dee0_shell::FUN_0042dee0(intptr_t aiValue)
{
    BSExtraData* extra = reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((((ExtraListHelper*)this)))->FUN_00410220(0x4d);
    if (!extra)
    {
        extra = new FUN_00432470(aiValue);
        reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>((((ExtraListHelper*)this)))->FUN_0040ff60(extra);
    }
    else
    {
        static_cast<FUN_00432470*>(extra)->z = aiValue;
    }
}

struct ExtraDataList
{
};
struct ExtraLock
{
    ~ExtraLock();
};
struct FUN_0042df90_Extra
{
    char pad[0xc];
    ExtraLock* unk0c;
};
struct FUN_0042df90_shell
{
    ExtraLock* FUN_0042df90(intptr_t a);
};
struct FUN_0042e210_Class : public BE
{
    void* vtbl;
    int a;
    int b;
    intptr_t c;
    intptr_t d;
    FUN_0042e210_Class(intptr_t x, intptr_t y);
};
// Initializes the object with base BE(0x5b), sets vtbl to DAT_01015980, and stores x into c and y into d.
// @fnv 0x0042e210
FUN_0042e210_Class::FUN_0042e210_Class(intptr_t x, intptr_t y) : BE(0x5b)
{
    vtbl = &DAT_01015980;
    c = x;
    d = y;
}

extern void* DAT_010159bc;
struct FUN_0042e650_class : BE
{
    void* vtbl;
    int a;
    int b;
    unsigned char c;
    FUN_0042e650_class(unsigned char c);
};
// Initialises the object with base value 0x8e, sets its vtbl to DAT_010159bc and stores c in field c.
// @fnv 0x0042e650
FUN_0042e650_class::FUN_0042e650_class(unsigned char aucValue) : BE(0x8e)
{
    vtbl = &DAT_010159bc;
    this->c = aucValue;
}

struct G00559a40
{
};
struct NiAVObject
{
    char pad[0x1c];
    G00559a40 unk1c;
};
struct FUN_0042fdc0_class
{
    NiAVObject* m_pObject;
    NiAVObject* FUN_0042fdc0(NiAVObject** arg);
};
// @fnv 0x0042fdc0
NiAVObject* FUN_0042fdc0_class::FUN_0042fdc0(NiAVObject** apObject)
{
    if (m_pObject != *apObject)
    {
        if (m_pObject)
            reinterpret_cast<::WaitableObject *>((&m_pObject->unk1c))->FUN_00401970();
        m_pObject = *apObject;
        if (m_pObject)
            reinterpret_cast<::FUN_0040f6e0_class *>((&m_pObject->unk1c))->FUN_0040f6e0();
    }
    return (NiAVObject*)this;
}


struct FUN_0042fe10_class
{
    void* m_pName;
    unsigned int m_uiCount;
    void* m_pData;
    unsigned int m_uiSize;
    void* FUN_0042fe10(uintptr_t count);
};
// Calls FUN_0042fe10 on arg, sets m_vtbl to &DAT_010159e8, and returns this.
// @fnv 0x0042f4e0
void* FUN_0042f4e0_class::FUN_0042f4e0(void* arg)
{
    reinterpret_cast<::FUN_0042fe10_class *>(this)->FUN_0042fe10((uintptr_t)(arg));
    m_vtbl = &DAT_010159e8;
    return this;
}

// @fnv 0x0042fe10
void* FUN_0042fe10_class::FUN_0042fe10(uintptr_t count)
{
    m_pName = &DAT_01015a1c;
    m_uiCount = count;
    m_uiSize = 0;
    unsigned int size = m_uiCount * 4;
    m_pData = ::FUN_00aa1070(size);
    ::FUN_00403d30(m_pData, 0, m_uiCount * 4);
    return this;
}

struct FUN_0042ff80_s
{
};
struct FUN_0042ff50_host : FUN_0042ff80_s
{
    void* FUN_0042ff50(unsigned int flags);
};
// Calls FUN_0042ff80, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0042ff50
void* FUN_0042ff50_host::FUN_0042ff50(unsigned int flags)
{
    reinterpret_cast<::GlobalObject_00869f00 *>(this)->FUN_0042ff80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


// If the object at p is not _EmptyFS, obtains a value via FUN_00438210 and passes it to FinishScriptRunLock.
// @fnv 0x004381d0
void FUN_004381d0(void* p)
{
    if (*(void**)p == (*reinterpret_cast<void * *>(&::DAT_0109b220)))
        return;
    void* r = ((void *)(::FUN_00438210((intptr_t *)(p))));
    ::WaitForSingleObjectEx((long *)(r));
}

// @fnv 0x00438210
intptr_t __cdecl FUN_00438210(intptr_t* p)
{
    return *p - 8;
}

struct FUN_00438660_class
{
    void* vtable;
    FUN_00438660_class* FUN_00438660();
};
// Sets the vtable to DAT_01016024, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00438660
FUN_00438660_class* FUN_00438660_class::FUN_00438660()
{
    vtable = &DAT_01016024;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return this;
}

extern void* DAT_01016058;

// @fnv 0x00438900
void FUN_00438900_class::FUN_00438900()
{
    *reinterpret_cast<void**>(this) = &DAT_01016058;
    if (data)
    {
        void* p = data;
        ::FUN_00401030(p);
    }
}

struct FNStub
{
};
struct TESModel
{
    unsigned int GetModelLength();
};
struct TESSound
{
};
struct FUN_00438c10_Class : public FNStub
{
    char pad[0xc];
    unsigned char unk0c;
    unsigned short unk0e;
    TESSound* unk10;
    void FUN_00438c10();
};
// @fnv 0x00438c10
void FUN_00438c10_Class::FUN_00438c10()
{
    FUN_004858f0(0x4d414e46, unk0c);
    ::FUN_004856f0((void *)(0x4c4c5546), (void*)((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(this)->FUN_00408da0())), (void *)(uintptr_t)(((TESModel*)this)->GetModelLength() + 1));
    ::FUN_00485950((void *)(0x4d414e54), unk0e);
    if (unk10)
    {
        unsigned int r = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((unk10))->FUN_0084e3a0()));
        ::FUN_00485910(0x31494d57, r);
    }
}

struct FUN_00438f90_Class
{
    void FUN_00438f90();
};
struct Unk_00439120
{
    int m0;
    int m4;
    int m8;
    void FUN_00439120(Unk_00439120* p);
};
// Copies the contents of the object pointed to by p into this object when p is non-null.
// @fnv 0x00439120
void Unk_00439120::FUN_00439120(Unk_00439120* apSource)
{
    if (apSource)
        *this = *apSource;
}

struct S_00439150
{
    bool FUN_00439150();
};
// @fnv 0x00438f90
void FUN_00438f90_Class::FUN_00438f90()
{
    if (reinterpret_cast<::S_00439150 *>(this)->FUN_00439150())
        return;
    ::FUN_00485710((void *)(0x4f424d58), (unsigned int*)this, (void *)(3));
}
// @fnv 0x00439150
bool S_00439150::FUN_00439150()
{
    if (reinterpret_cast<::NiPlane *>(this)->operator==((const ::NiPlane &)(*(const NiPoint3*)&DAT_011c3ae4)))
    {
        return false;
    }
    return true;
}

struct MyPoint439180
{
    float x;
    float y;
    float z;
    MyPoint439180* FUN_00439180(float);
};
// Multiplies x, y and z by fScalar and returns this.
// @fnv 0x00439180
MyPoint439180* MyPoint439180::FUN_00439180(float fScalar)
{
    x *= fScalar;
    y *= fScalar;
    z *= fScalar;
    return this;
}

struct Mat9
{
    int v[9];
};
struct FUN_004396b0_class
{
    char _pad[0x24];
    Mat9 m;
    void FUN_004396b0(const Mat9& src);
};
// Copies the 9-element matrix src into the object's m field.
// @fnv 0x004396b0
void FUN_004396b0_class::FUN_004396b0(const Mat9& aMatrix)
{
    m = aMatrix;
}

struct FUN_00439f50_class
{
    void FUN_00439f50(unsigned int col, NiPoint3* out);
};
// Reads three floats at offsets col*4, col*4+0xc and col*4+0x18 from this into out as x, y and z.
// @fnv 0x00439f50
void FUN_00439f50_class::FUN_00439f50(unsigned int uiColumn, NiPoint3* out)
{
    out->x = *(float*)((char*)this + uiColumn * 4);
    out->y = *(float*)((char*)this + uiColumn * 4 + 0xc);
    out->z = *(float*)((char*)this + uiColumn * 4 + 0x18);
}

struct Helper62d0
{
    void* operator=(const void*);
};
struct Node
{
    void* p;
    char pad04[4];
    Helper62d0 unk08;
};
struct ScriptPool
{
    Node* FUN_0049fa80();
    void FUN_00439fd0(const void* arg);
};
// Gets a node from the pool, assigns arg to the node's field at offset 8, then releases the node back to the pool.
// @fnv 0x00439fd0
void ScriptPool::FUN_00439fd0(const void* arg)
{
    Node* p = FUN_0049fa80();
    p->unk08.operator=(arg);
    reinterpret_cast<::FUN_0049fa20_List *>(this)->FUN_0049fa20((::FUN_0049fa20_Node *)(p));
}

struct TESSaveLoadGame
{
};

struct FUN_0043a9a0_class
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned int i;
    unsigned int j;
    unsigned int k;
    unsigned int l;
    unsigned int m;
    unsigned int n;
    unsigned int o;
    unsigned int p;
    unsigned int q;
    unsigned int r;
    unsigned int s;
    unsigned int t;
    unsigned int u;
    unsigned int v;
    unsigned int w;
    unsigned int x;
    unsigned int y;
    unsigned int z;
    void FUN_0043a9a0();
};

// @fnv 0x0043a9a0
void FUN_0043a9a0_class::FUN_0043a9a0()
{
    reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((char*)&this->b, 0xc);
    reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((char*)&this->e, 0xc);
    unsigned int v;
    reinterpret_cast<::FUN_00857aa0 *>((g_TESSaveLoadGame))->ValidateFormIDArray(&v, 4);
    a = v;
}

namespace fnv_0043b250 {
struct Flt
{
    operator unsigned int();
};
extern Flt DAT_011f4438;
// @fnv 0x0043b250
unsigned int __cdecl FUN_0043b250()
{
    return DAT_011f4438;
}
}  // namespace fnv_0043b250

namespace fnv_0043b2a0 {
struct Flt
{
    operator unsigned int();
};
extern Flt DAT_011f4444;

// @fnv 0x0043b2a0
unsigned int __cdecl FUN_0043b2a0()
{
    return DAT_011f4444;
}
}  // namespace fnv_0043b2a0

struct S_0043b320
{
    char _pad0[0x38];
    TaskQueueInterface** arr;
    void FUN_0043b320(unsigned short a, TaskQueueInterface* b);
};
// Stores b in arr[a] and, when b is non-null, calls b->FUN_0043b350(true).
// @fnv 0x0043b320
void S_0043b320::FUN_0043b320(unsigned short usIndex, TaskQueueInterface* pTaskQueue)
{
    arr[usIndex] = pTaskQueue;
    if (pTaskQueue)
        pTaskQueue->FUN_0043b350(true);
}

namespace fnv_0043ba60 {
// @fnv 0x0043ba60
void __cdecl FUN_0043ba60(int* p)
{
    void* v;
    if (*p == (*reinterpret_cast<int *>(&::DAT_0109b220)))
    {
    }
    else
    {
        v = ((void *)(::FUN_00438210((intptr_t *)(p))));
        ::FUN_0040b460((unsigned int *)(v));
    }
}
}  // namespace fnv_0043ba60

struct FUN_00435820 : public BSExtraData
{
    FUN_00435820();
    ~FUN_00435820();
    char m_data[8];
    GO unk0c;
    char pad0d[3];
};
struct FUN_00420e00_cls : public BaseExtraList
{
    void FUN_00420e00(void* p);
};
// Stores p in the extra data of type 0x78, creating and adding it if absent, or removes that extra data when p is null.
// @fnv 0x00420e00
void FUN_00420e00_cls::FUN_00420e00(void* apData)
{
    if (apData)
    {
        FUN_00435820* e = (FUN_00435820*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x78);
        if (e)
        {
            e->unk0c.operator=(apData);
        }
        else
        {
            e = new FUN_00435820;
            e->unk0c.operator=(apData);
            reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(e);
        }
    }
    else
    {
        reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>(this)->RemoveExtra(0x78);
    }
}

struct FUN_00421600_Class
{
    void FUN_00421600(unsigned char val);
};
// Stores val in the byte at offset 0xc of extra data 0x4e, creating a new FUN_00436090 extra if none exists.
// @fnv 0x00421600
void FUN_00421600_Class::FUN_00421600(unsigned char aucValue)
{
    BSExtraData* extra = reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x4e);
    if (extra)
        reinterpret_cast<FUN_00436090*>(extra)->c = aucValue;
    else
    {
        extra = (BSExtraData*)new FUN_00436090(aucValue);
        reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(extra);
    }
}

extern int DAT_01015cd8;
struct ListX
{
    void* m_pInventoryEntryData;
    void* m_pNext;
    void* m_pListObject;
    ~ListX();
};
struct FUN_00433830 : public BSExtraData
{
    void* m_pData;
    int m_iFlags;
    ListX m_kEntryList;
    ~FUN_00433830();
};
// @fnv 0x00433830
FUN_00433830::~FUN_00433830()
{
    ::FUN_00433750((::ListNode *)(::ListX *)(&m_kEntryList));
}

struct FUN_00438820_Class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00438820_Class(int c);
};
// Sets the vtable, stores the count, and, when count is nonzero, allocates count*4 zeroed bytes into data.
// @fnv 0x00438820
FUN_00438820_Class::FUN_00438820_Class(int aiCount)
{
    vtbl = &DAT_01016058;
    count = aiCount;
    pad = 0;
    if (aiCount)
    {
        unsigned int size = count * 4;
        void* p3 = ::FUN_00401000(size);
        data = p3;
        ::std::memset(data, 0, count * 4);
    }
}

struct BaseExtraList2
{
};
struct TESLeveledList
{
    void FUN_0042e680(unsigned char type);
};
struct FUN_0042e5a0_class
{
    void FUN_0042e5a0(unsigned char type);
};
// @fnv 0x0042e5a0
void FUN_0042e5a0_class::FUN_0042e5a0(unsigned char type)
{
    BSExtraData* extra = reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((((BaseExtraList2*)this)))->FUN_00410220(0x8e);
    if (!extra)
    {
        extra = (BSExtraData*)new FUN_0042e650_class(type);
        reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>((((BaseExtraList2*)this)))->FUN_0040ff60(extra);
    }
    else
    {
        ((TESLeveledList*)extra)->FUN_0042e680(type);
    }
}

struct FUN_004386b0_Class
{
    void* p;
    unsigned int count;
    void* data;
    int unk0c;
    void* FUN_004386b0(void* a);
};
// Calls FUN_004386b0 with a, sets p to the address of DAT_01015fbc, and returns this.
// @fnv 0x004383b0
void* FUN_004383b0_Class::FUN_004383b0(void* apArg)
{
    reinterpret_cast<::FUN_004386b0_Class *>(this)->FUN_004386b0(apArg);
    p = &DAT_01015fbc;
    return this;
}
// Stores a pointer and a count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x004386b0
void* FUN_004386b0_Class::FUN_004386b0(void* auiCount)
{
    p = &DAT_01016038;
    count = (unsigned int)(std::uintptr_t)auiCount;
    unk0c = 0;
    unsigned int size = count << 2;
    data = ::FUN_00aa1070(size);
    ::FUN_00403d30(data, 0, count << 2);
    return this;
}

struct NiPoint3Set
{
};
struct FUN_00439ef0_class : public NiPoint3
{
    NiPoint3* FUN_00439ef0(NiPoint3* a, const NiPoint3& b);
};
// Subtracts b from this NiPoint3, stores the result in a, and returns a.
// @fnv 0x00439ef0
NiPoint3* FUN_00439ef0_class::FUN_00439ef0(NiPoint3* apResult, const NiPoint3& arSubtrahend)
{
    reinterpret_cast<::FUN_00416870_t *>((((NiPoint3Set*)apResult)))->FUN_00416870(x - arSubtrahend.x, y - arSubtrahend.y, z - arSubtrahend.z);
    return apResult;
}

struct NiInterpController
{
    static const unsigned short INVALID_INDEX;
};
struct FUN_0043b3b0_class
{
    char pad00[0x38];
    uintptr_t* m_puiArray;
    unsigned short m_usCount;
    unsigned short FUN_0043b3b0(uintptr_t value);
};
// Scans the array at offset 0x38 up to the count at 0x3c and returns the index of the first element equal to value, or INVALID_INDEX if none matches.
// @fnv 0x0043b3b0
unsigned short FUN_0043b3b0_class::FUN_0043b3b0(uintptr_t value)
{
    unsigned short i = 0;
    for (; i < m_usCount; ++i)
    {
        if (m_puiArray[i] == value)
            return i;
    }
    return NiInterpController::INVALID_INDEX;
}

struct G2
{
    void AddHead(int* pValue);
};

struct LH
{
    bool IsInList(int& value);
};

struct FUN_00420440_Class
{
};

struct FUN_00416b80
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;

    FUN_00416b80();
};

struct FUN_00420c10_Linked
{
    char pad[8];
    LH unk08;
};

struct FUN_00420c10_Class : public FUN_004207e0Class
{
    void FUN_00420c10(int value);
};


// Ensures the object exists when value is nonzero, then adds value to the list at offset 8 if it is not already present.
// @fnv 0x00420c10
void FUN_00420c10_Class::FUN_00420c10(int value)
{
    if (!this->FUN_004207e0() && value)
    {
        reinterpret_cast<::fnv_00420440::FUN_00420440_shell *>((((FUN_00420440_Class*)this)))->FUN_00420440((::MagicItem *)(void *)(new FUN_00416b80()));
    }

    FUN_00420c10_Linked* m_pLinkedReference = reinterpret_cast<FUN_00420c10_Linked*>(this->FUN_004207e0());
    if (!reinterpret_cast<::RefList *>((&m_pLinkedReference->unk08))->FUN_005f65d0((void **)&(value)))
    {
        reinterpret_cast<G2*>(&m_pLinkedReference->unk08)->AddHead(&value);
    }
}

struct FUN_0042cca0 : public BSExtraData
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    virtual ~FUN_0042cca0();
};
// @fnv 0x0042cca0
FUN_0042cca0::~FUN_0042cca0()
{}

struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct FUN_0042dff0_shell
{
    char pad[0xc];
    BSSimpleListTESRaceSize unk0c;
    int FUN_0042dff0();
};
// @fnv 0x0042df90
ExtraLock* FUN_0042df90_shell::FUN_0042df90(intptr_t a)
{
    ExtraLock* p = 0;
    ExtraDataList* e = (ExtraDataList*)reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((((ExtraDataList*)this)))->FUN_00410220(0x4d);
    if (e && (p = reinterpret_cast<FUN_0042df90_Extra*>(e)->unk0c) && ((bool)(reinterpret_cast<::FUN_0042dff0_shell *>((p))->FUN_0042dff0())))
        reinterpret_cast<::FUN_0042e010_ExtraLock *>((p))->FUN_0042e010(a);
    return p;
}
// @fnv 0x0042dff0
int FUN_0042dff0_shell::FUN_0042dff0()
{
    return unk0c.GetSize() == 0 ? 1 : 0;
}

struct FUN_0042e130_Base
{
};

struct FUN_0042e130_shell : FUN_0042e130_Base
{
    void FUN_0042e130();
};

// @fnv 0x0042e130
void FUN_0042e130_shell::FUN_0042e130()
{
    reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>(this)->RemoveExtra(0x55);
}

struct FUN_0042e6d0 : public BSExtraData
{
    virtual ~FUN_0042e6d0();
};
// @fnv 0x0042e6d0
FUN_0042e6d0::~FUN_0042e6d0()
{}

struct NavMeshArr
{
    ~NavMeshArr();
    void* FUN_0042f510(unsigned int flags);
};

NavMeshArr::~NavMeshArr()
{}

// Runs the destructor and, when flags has bit 0 set, deallocates the object; returns this.
// @fnv 0x0042f510
void* NavMeshArr::FUN_0042f510(unsigned int flags)
{
    ::FUN_0042f830((::FUN_0042f830_struct *)(this));
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BSSimpleArrayActor
{
    void* m_vtbl;
    int* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void Clear(bool);
    void FUN_0042f5f0(unsigned int count, bool clear);
};

struct BSSimpleArrayActor_Vtbl
{
    void* slot0;
    int* (*Grow)(BSSimpleArrayActor*, unsigned int);
};

struct FUN_0042fc00_shell
{
    void FUN_0042fc00(void* count, unsigned int size);
};

struct BSSimpleArrayShell_FUN_00430000
{
    void FUN_00430000(void* data, unsigned int count);
};

struct FUN_0072ba80_shell
{
public:
    void FUN_0072ba80(void *, unsigned int);
};

// @fnv 0x0042f5f0
void BSSimpleArrayActor::FUN_0042f5f0(unsigned int count, bool clear)
{
    if (count == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(clear);
    }
    else if (count > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            m_data = static_cast<BSSimpleArrayActor_Vtbl*>(m_vtbl)->Grow(this, count);
            m_pRayCursor = count;
        }
        else
        {
            reinterpret_cast<FUN_0042fc00_shell*>(this)->FUN_0042fc00(reinterpret_cast<void*>(count), m_iElementCount);
            m_pRayCursor = count;
        }

        reinterpret_cast<BSSimpleArrayShell_FUN_00430000*>(this)->FUN_00430000(m_data + m_iElementCount, count - m_iElementCount);
        m_iElementCount = count;
    }
    else if (count < m_iElementCount)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(m_data + count),
                                                                  m_iElementCount - count);
        m_iElementCount = count;

        if (clear && count <= m_pRayCursor / 4)
        {
            reinterpret_cast<FUN_0042fc00_shell*>(this)->FUN_0042fc00(reinterpret_cast<void*>(count), count);
            m_pRayCursor = count;
        }
    }
    else
    {
        reinterpret_cast<BSSimpleArrayShell_FUN_00430000*>(this)->FUN_00430000(m_data + m_iElementCount, count - m_iElementCount);
        m_iElementCount = count;
    }
}

struct AC_0042f730
{
    void* vtbl;
    void FUN_0042f760();
};

// @fnv 0x0042f760
void AC_0042f730::FUN_0042f760()
{
    if (vtbl)
        reinterpret_cast<::S_0066e2b0_Class *>((((AC_0042f730*)vtbl)))->FUN_0066e2b0();
}

// @fnv 0x0042ff30
bool FUN_0042ff10_cls::FUN_0042ff30(const void** apOther)
{
    return reinterpret_cast<::FUN_004b0460_class *>(this)->FUN_004b0460(apOther);
}

struct BSExtraDataHelper
{
    virtual ~BSExtraDataHelper();
};
struct FUN_00435f80 : public BSExtraDataHelper
{
    virtual ~FUN_00435f80();
};
// Calls FUN_00435f80, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00435f50
void* FUN_00435f50_class::FUN_00435f50(unsigned int flags)
{
    reinterpret_cast<::FUN_00435f80 *>(this)->FUN_00435f80::~FUN_00435f80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00435f80
FUN_00435f80::~FUN_00435f80()
{}

struct FUN_004362a0
{
    ~FUN_004362a0();
    void* FUN_00436270(unsigned int flags);
};

// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00436270
void* FUN_004362a0::FUN_00436270(unsigned int flags)
{
    FUN_004362a0::~FUN_004362a0();

    if (flags & 1)
        ::FUN_00401030(this);

    return this;
}

struct FUN_00436bb0 : public BSExtraData
{
    virtual ~FUN_00436bb0();
};
// @fnv 0x00436af0
void* FUN_00436af0_Class::FUN_00436af0(unsigned int flags)
{
    reinterpret_cast<::FUN_00436bb0 *>(this)->FUN_00436bb0::~FUN_00436bb0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00436bb0
FUN_00436bb0::~FUN_00436bb0()
{}

namespace fnv_004385f0 {
struct BSSimpleArrayActor
{
    void* m_vtbl;
    void Clear(bool);
};
struct FUN_004385f0_Class
{
    void FUN_004385f0();
};
// @fnv 0x004385f0
void FUN_004385f0_Class::FUN_004385f0()
{
    *(void**)this = &DAT_01016010;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((BSSimpleArrayActor*)this)))->Clear(true);
}
}  // namespace fnv_004385f0

struct FUN_0043a080_Node
{
    FUN_0043a080_Node* next;
    int field2;
    int field3;
};

extern int DAT_01188f7c;
extern void* DAT_011c5f54;

// @fnv 0x0043a080
void FUN_0043a080()
{
    DAT_011c5f58 = new FUN_0043a080_Node[DAT_01188f7c];

    FUN_0043a080_Node* index = (FUN_0043a080_Node*)DAT_011c5f58 + DAT_01188f7c - 1;
    index->next = 0;

    unsigned int uiIndex = 1;
    do
    {
        index = (FUN_0043a080_Node*)DAT_011c5f58 + uiIndex;
        index->next = index + 1;
    } while (uiIndex++ < DAT_01188f7c - 2);

    if (DAT_011c5f54 != 0)
    {
        ((FUN_0043a080_Node*)DAT_011c5f58)->next = (FUN_0043a080_Node*)DAT_011c5f54;
        DAT_011c5f54 = DAT_011c5f58;
    }
    else
    {
        DAT_011c5f54 = DAT_011c5f58;
        ((FUN_0043a080_Node*)DAT_011c5f54)->next = 0;
    }

    DAT_011c5f58 = (FUN_0043a080_Node*)DAT_011c5f58 + 1;
}

struct Date
{
    ~Date();
public:
    void *FUN_007b3fa0(unsigned int);
};
struct FUN_0043b5f0_cls : TESObjectTREE
{
    void FUN_0043b5f0();
};
// @fnv 0x0043b5f0
void FUN_0043b5f0_cls::FUN_0043b5f0()
{
    reinterpret_cast<::TESForm *>((((Date*)GetData())))->ClearData();
}

struct ExtraListShell
{
    void FUN_004216b0();
};
// @fnv 0x004216b0
void ExtraListShell::FUN_004216b0()
{
    reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>(this)->RemoveExtra(0x4E);
}

extern "C" void* DAT_0101598c;

struct FUN_0040ecb0
{
    virtual ~FUN_0040ecb0();
    int unk04;
    int unk08;
};

struct FUN_0042f780
{
    int unk00;
    int unk04;
    int unk08;
    ~FUN_0042f780();
};

struct FUN_0042cb30 : public FUN_0040ecb0
{
    FUN_0042f780 unk0c;
    virtual ~FUN_0042cb30();
};

// Destructor for FUN_0042cb30 that resets its unk0c member by calling Init(0).
// @fnv 0x0042cb30
FUN_0042cb30::~FUN_0042cb30()
{
    reinterpret_cast<::Holder0042f780 *>(&(unk0c))->FUN_0042f780((::AC_0042f730 *)(0));
}

class BSString42C
{
  public:
    BSString42C();
    ~BSString42C();

    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMaxLen;
};

class BSExtraData42C
{
  public:
    BSExtraData42C(unsigned char ucType);
    virtual ~BSExtraData42C();

    unsigned char m_ucType;
    BSExtraData42C* m_pkNext;
};

class FUN_0042ccc0 : public BSExtraData42C
{
  public:
    FUN_0042ccc0();
    virtual ~FUN_0042ccc0();

    BSString42C m_kFirst;
    BSString42C m_kSecond;
};

// Constructs a BSExtraData42C-derived extra-data object of type 0x8f holding two BSString42C members.
// @fnv 0x0042ccc0
FUN_0042ccc0::FUN_0042ccc0() : BSExtraData42C(0x8f)
{}

struct FUN_00436b20
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_00436b20(uintptr_t a, uintptr_t b);
};
struct FUN_0042e060_class
{
    void FUN_0042e060(uintptr_t a, uintptr_t b);
};
// Removes the existing 0x55-type entry, allocates a new FUN_00436b20 from a and b, and installs it via FUN_0040ff60.
// @fnv 0x0042e060
void FUN_0042e060_class::FUN_0042e060(uintptr_t a, uintptr_t b)
{
    void* pEntry = ((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x55)));
    if (pEntry)
        reinterpret_cast<::FUN_00410020_t *>(this)->FUN_00410020((::BSExtraData *)(pEntry), true);
    pEntry = new FUN_00436b20(a, b);
    reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60((::BSExtraData *)(pEntry));
}


struct B42FA60Entry
{
    int unk00;
    B42FA60Entry();
};

class B42FA60Allocator
{
  public:
    void FUN_0042fa60(B42FA60Entry* pkArray, unsigned int ItemUpdateArray);
};

// Constructs each B42FA60Entry in the array in place using placement new.
// @fnv 0x0042fa60
void B42FA60Allocator::FUN_0042fa60(B42FA60Entry* pkArray, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkArray[i]) B42FA60Entry;
}

class B42FE80MapBase
{
  public:
    virtual ~B42FE80MapBase();
    int m_uiHashSize;
    void** m_ppkHashTable;
    int m_uiCount;
};

class FUN_0042fe80_Map : public B42FE80MapBase
{
  public:
    virtual ~FUN_0042fe80_Map();
    void RemoveAll();
};

// @fnv 0x0042fe80
FUN_0042fe80_Map::~FUN_0042fe80_Map()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_004300a0
{
    void* m_uiFilterValue;
    FUN_004300a0();
};
// Default-constructs count FUN_004300a0 objects in place at data.
// @fnv 0x00430000
void BSSimpleArrayShell_FUN_00430000::FUN_00430000(void* data, unsigned int count)
{
    for (unsigned int index = 0; index < count; ++index)
    {
        new (&static_cast<FUN_004300a0*>(data)[index]) FUN_004300a0;
    }
}

struct SpawnedSub
{
    ~SpawnedSub();
};

struct SpawnedBase
{
    int unk00;
    int unk04;
    int unk08;
    ~SpawnedBase();
};

struct FUN_00435ce0_cls : public SpawnedBase
{
    SpawnedSub m_0c;
    ~FUN_00435ce0_cls();
};

// Destructor for FUN_00435ce0_cls that destroys its SpawnedSub member and base SpawnedBase.
// @fnv 0x00435ce0
FUN_00435ce0_cls::~FUN_00435ce0_cls()
{}

struct FloatSlot
{
    unsigned int m_bits;
};

struct FloatHolder
{
    float m_f;
};

struct FloatList
{
    int unk00;
};

struct FloatGlobal
{
    int unk00;
};


class FUN_00435d40_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FloatList m_0c;
    void FUN_00435d40();
};

struct FUN_00435e40_key
{
    unsigned int m_v;
};
struct FUN_00435e40_arr
{
    unsigned int* GetAt(unsigned int i);
};
struct FUN_00435e40_flt
{
};
struct FUN_00435e40_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00435e40_arr m_0c;
    void FUN_00435e40();
};
// Iterates m_0c, evaluates each entry's key and removes entries whose Eval() exceeds the float at DAT_011cd580.
// @fnv 0x00435e40
void FUN_00435e40_cls::FUN_00435e40()
{
    for (unsigned int i = 0; i < ((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_0c))->GetName())); i++)
    {
        FUN_00435e40_key key;
        key.m_v = *((unsigned int *)(reinterpret_cast<::S3e60 *>(&(m_0c))->FUN_006a7ad0(i)));
        if (((double)(reinterpret_cast<::FUN_00435e00_t *>(&(key))->FUN_00435e00())) > *((float *)&(::FUN_00403e20((float *)(((FUN_00435e40_flt*)&(*reinterpret_cast<char *>(&::originalRuntimeFloatSetting130))))))))
        {
            reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(&(m_0c))->FUN_009a4320(i, 1);
            i--;
        }
    }
}

struct Vec3Sub
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    Vec3Sub();
};
struct SlottedSource
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
    virtual Vec3Sub* GetVariedData();
};
struct RootCtorCls
{
    virtual void v0();
    RootCtorCls(unsigned int sizeInit);
    ~RootCtorCls();
};
struct FUN_00435fa0_cls : RootCtorCls
{
    virtual void v0();
    int unk04;
    int unk08;
    Vec3Sub m_kPointA;
    Vec3Sub m_kPointB;
    Vec3Sub m_iThirdValue;
    FUN_00435fa0_cls(SlottedSource* pSrc);
};

// @fnv 0x00435fa0
FUN_00435fa0_cls::FUN_00435fa0_cls(SlottedSource* apSource) : RootCtorCls(0x4c)
{
    if (apSource != 0)
    {
        m_kPointA = *((::Vec3Sub *)(reinterpret_cast<::TESRecipe *>((apSource))->GetData()));
        m_kPointB = *apSource->GetVariedData();
        m_iThirdValue = m_kPointB;
    }
}

struct Arg12
{
    int unk00;
    int unk04;
    int unk08;
    ~Arg12();
    void Release();
};

struct EhGuard
{
    ~EhGuard()
    {}
};

struct Base4f
{
    virtual void Tick();
    int unk04;
    int unk08;
    Base4f(int flags);
    ~Base4f();
};

struct Member12
{
    Member12();
    ~Member12();
};

struct FUN_004360c0_cls : public Base4f
{
    virtual void Update();
    Member12 m_0c;

    FUN_004360c0_cls(Arg12 value);
};

// Initializes the base with flags 0x4f and assigns the given Arg12 value to m_0c.
// @fnv 0x004360c0
FUN_004360c0_cls::FUN_004360c0_cls(Arg12 value) : Base4f(0x4f), m_0c()
{
    reinterpret_cast<::SoundPlaybackHandle *>(&(m_0c))->operator=((const ::SoundPlaybackHandle &)(value));
}

struct Base_004361e0
{
    virtual void v00();
    int unk04;
    int unk08;
    Base_004361e0(int aValue);
    ~Base_004361e0();
};

struct Arg12_004361e0
{
    int unk00;
    int unk04;
    int unk08;
    ~Arg12_004361e0();
};

struct Member_004361e0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Member_004361e0();
    ~Member_004361e0();
    void Add(Arg12_004361e0* pArg);
};

struct FUN_004361e0 : Base_004361e0
{
    Member_004361e0 m_0C;

    FUN_004361e0(Arg12_004361e0 aArg);
    virtual void v00();
};

// Initializes the base with 0x7d and adds the passed argument to the member at offset 0x0C.
// @fnv 0x004361e0
FUN_004361e0::FUN_004361e0(Arg12_004361e0 aArg) : Base_004361e0(0x7d)
{
    reinterpret_cast<::SoundPlaybackHandle *>(&(m_0C))->operator=((*(const ::SoundPlaybackHandle *)(&aArg)));
}

struct ParamBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Release();
    ~ParamBlock();
};

class ChildMember
{
  public:
    ChildMember();
    ~ChildMember();
};

class NodeBase
{
  public:
    NodeBase(int kind);
    virtual void v00();
    ~NodeBase();
    unsigned int unk04;
    unsigned int unk08;
};

class FUN_00436660 : public NodeBase
{
  public:
    FUN_00436660(ParamBlock p);
    virtual void v00();
    ChildMember m_pChildAtom;
};

// Constructs a NodeBase of kind 0x87 and attaches the given ParamBlock to its ChildMember.
// @fnv 0x00436660
FUN_00436660::FUN_00436660(ParamBlock aParamBlock) : NodeBase(0x87)
{
    reinterpret_cast<::SoundPlaybackHandle *>(&(m_pChildAtom))->operator=((*(const ::SoundPlaybackHandle *)(&aParamBlock)));
}

struct CloneCell;
struct CloneSound;

struct CloneChildCell
{
    virtual CloneCell* GetPersistentCell();
};

struct CloneCell
{
};

struct CloneExtraList
{
};

struct CloneSource
{
    char pad00[0x18];
    CloneChildCell kChildCell;
};

struct CloneProcess
{
};

struct CloneRef
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void SetParentCell(CloneCell* pCell);
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
    int unk034;
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
    CloneRef();
    void FUN_00575700(NiPoint3 kAngle);
};

struct CloneLowProcess : CloneProcess
{
    int unk000;
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
    int unk034;
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
    int unk0B0;
    CloneLowProcess();
};
struct CloneMiddleLowProcess : CloneLowProcess
{
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    CloneMiddleLowProcess();
};
struct CloneMiddleHighProcess : CloneMiddleLowProcess
{
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    CloneMiddleHighProcess();
};
struct CloneHighProcess : CloneMiddleHighProcess
{
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    CloneHighProcess();
};

struct CloneProcessLists
{
};

struct CloneFactory
{
    CloneRef* FUN_00436780(void* pBase, CloneSource* pSource);
};

// Allocates a CloneRef from pSource, copies its data, sets its parent cell, and attaches a process matching the player's process level.
// @fnv 0x00436780
CloneRef* CloneFactory::FUN_00436780(void* pBase, CloneSource* pSource)
{
    CloneRef* pRef = 0;
    if (pSource)
    {
        pRef = new CloneRef;
        reinterpret_cast<::Fn575690 *>((pRef))->FUN_00575690(pBase);
        reinterpret_cast<::fnv_00565480::RefPersistsStandin *>((pRef))->FUN_00565480(reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((pSource))->FUN_005653d0());
        reinterpret_cast<::Reference *>((pRef))->FUN_00575830((::Position *)&(*((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((pSource))->GetAddTopicList()))));
        pRef->FUN_00575700((*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((pSource))->GetData())));
        reinterpret_cast<::FUN_004fbf00_shell *>((pRef))->FUN_004fbf00((::TESSound *)(pSource));
        reinterpret_cast<::FUN_00898280 *>((pRef))->SetFlag(true);
        reinterpret_cast<::FUN_00935ae0_t *>((pRef))->FUN_00935ae0();
        if (((::CloneCell *)(reinterpret_cast<::LowProcess *>((pSource))->GetTarget())) && reinterpret_cast<::TESObjectCELL *>((((::CloneCell *)(reinterpret_cast<::LowProcess *>((pSource))->GetTarget()))))->IsCellInterior())
        {
            pRef->SetParentCell(((::CloneCell *)(reinterpret_cast<::LowProcess *>((pSource))->GetTarget())));
        }
        else
        {
            CloneCell* pCell = pSource->kChildCell.GetPersistentCell();
            if (pCell)
                reinterpret_cast<::FUN_0041d390_shell *>((((::CloneExtraList *)(reinterpret_cast<::FUN_005d43c0_ *>((pRef))->FUN_005d43c0()))))->FUN_0041d390((::TESObjectCELL *)(pCell));
            else
                pRef->SetParentCell(((::CloneCell *)(reinterpret_cast<::LowProcess *>((pSource))->GetTarget())));
        }
        CloneProcess* pPlayerProcess = ((::CloneProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::CloneRef * *>(&::_g_thePlayer))))->GetBaseTexture()));
        if (pPlayerProcess)
        {
            CloneProcess* pProcess = 0;
            switch (((int)(uintptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((pPlayerProcess))->FUN_0045cd60())))
            {
            case 3:
                pProcess = new CloneLowProcess;
                break;
            case 2:
                pProcess = new CloneMiddleLowProcess;
                break;
            case 1:
                pProcess = new CloneMiddleHighProcess;
                break;
            case 0:
                pProcess = new CloneHighProcess;
                break;
            }
            reinterpret_cast<::MiddleHighProcess *>((pRef))->SetFaceAnimationData((::TargetDoorController *)(pProcess));
            reinterpret_cast<::Host096d450 *>(&((*reinterpret_cast<::CloneProcessLists *>(&::g_011e0e80))))->FUN_0096d450((::MobileObject *)(pRef), ((int)(uintptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((pProcess))->FUN_0045cd60())), false, false, (::MobileObject *)(false));
        }
    }
    return pRef;
}

struct GcItem
{
};

struct GcNode
{
    ~GcNode();
};

struct GcBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    virtual ~GcBase();
};

class FUN_00437d10 : public GcBase
{
  public:
    GcNode m_pChildAtom;
    virtual ~FUN_00437d10();
};

// @fnv 0x00437d10
FUN_00437d10::~FUN_00437d10()
{
    for (GcNode* pos = &m_pChildAtom; pos != 0; pos = ((::GcNode *)(reinterpret_cast<::Callees *>((pos))->FUN_00726070())))
    {
        GcItem* val = *((::GcItem **)(new ((void *)(pos)) ::Vec3()));
        GcItem* cur = val;
        cur ? ((uintptr_t)(reinterpret_cast<::Date *>((cur))->FUN_007b3fa0(1))) : 0;
        *((::GcItem **)(new ((void *)(pos)) ::Vec3())) = 0;
    }
}

class FUN_00438610_cls
{
  public:
    unsigned int m_unk00;
    unsigned int* m_pData;
    int FUN_00438610(unsigned int* value);
};
// @fnv 0x00435d40
void FUN_00435d40_cls::FUN_00435d40()
{
    reinterpret_cast<::FUN_00435e40_cls *>(this)->FUN_00435e40();
    int n = ((int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_0c))->GetName()));
    if (n > 0)
    {
        FloatSlot v;
        v.m_bits = *((unsigned int *)(reinterpret_cast<::S3e60 *>(&(m_0c))->FUN_006a7ad0(n - 1)));
        if (reinterpret_cast<::FUN_00435e00_t *>(&(v))->FUN_00435e00() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatGlobal *>(&::originalRuntimeFloatSetting131)))))))
            return;
    }
    FloatHolder h;
    reinterpret_cast<::FUN_00435de0_ctor *>(&(h))->FUN_00435de0(FUN_00435dd0());
    reinterpret_cast<::FUN_00438610_cls *>(&(m_0c))->FUN_00438610((unsigned int *)(::FloatHolder *)(&h));
}

// Appends the value to the end of the array, growing it by one, and returns the index where it was stored.
// @fnv 0x00438610
int FUN_00438610_cls::FUN_00438610(unsigned int* value)
{
    unsigned int index = reinterpret_cast<::FUN_00761540_cls *>(this)->FUN_00761540();
    reinterpret_cast<::BSSimpleArrayShell_FUN_00430000 *>(this)->FUN_00430000(m_pData + index, 1);
    m_pData[index] = *(volatile unsigned int*)value;
    return index;
}

class Base_438720
{
  public:
    virtual ~Base_438720();
    int unk04;
};

class FUN_00438720_cls : public Base_438720
{
  public:
    virtual ~FUN_00438720_cls();
};
// Calls FUN_00438720, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00438410
void* FUN_00438410_Class::FUN_00438410(unsigned int flags)
{
    reinterpret_cast<::FUN_00438720_cls *>(this)->FUN_00438720_cls::~FUN_00438720_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00438720
FUN_00438720_cls::~FUN_00438720_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>((this))->FUN_00438af0();
}

struct NiSpawnBase
{
    NiSpawnBase();
    ~NiSpawnBase()
    {}
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

NiSpawnBase::NiSpawnBase()
{}

class FUN_004391c0 : public NiSpawnBase
{
  public:
    FUN_004391c0();
    virtual void v00();
    void Init4(unsigned int a);
    unsigned short m_0018;
};

// @fnv 0x004391c0
FUN_004391c0::FUN_004391c0()
{
    m_0018 = 0;
    reinterpret_cast<::FUN_0049ed90_shell *>(this)->FUN_0049ed90(0);
    reinterpret_cast<::NiObjectNET *>(this)->FUN_00439340(6);
    reinterpret_cast<::fnv_00439390::NiObjectNET *>(this)->FUN_00439390(7);
    reinterpret_cast<::Flag512Receiver *>(this)->SetFlag512(0);
    reinterpret_cast<::NiObjectNET *>(this)->SetFlags(0);
    reinterpret_cast<::FUN_0094db80_shell *>(this)->FUN_0094db80(0);
}

// NiProperty's constructor: calls the primary base constructor, installs the
// class vtable pointer, then returns `this`.
struct NiPropertyBase
{
    NiPropertyBase();
    virtual void v00();
};

struct FUN_00439260 : public NiPropertyBase
{
    FUN_00439260();
};

// @fnv 0x00439260
FUN_00439260::FUN_00439260()
{}

struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
class TESObjectREFR
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual int v125();
    Matrix FUN_0056fa00();
};
class NiMemObject
{
  public:
};
struct Bound : NiMemObject
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void SetScale(int);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
struct FUN_00c37ec0 : Bound
{
    FUN_00c37ec0();
};
struct FUN_00c36310 : Bound
{
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    FUN_00c36310();
};
class BSMultiBound : public NiMemObject
{
  public:
    int unk00, unk04, unk08, unk0c;
    BSMultiBound();
    void FUN_004addc0(Bound*);
};
// @fnv 0x00439490
BSMultiBound* __cdecl FUN_00439490(TESObjectREFR* reference)
{
    BSMultiBound* result = 0;
    if (reference)
    {
        Bound* pBound = 0;
        if (std::abs((*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(reference))->GetData())).x) < 0.01f &&
            std::abs((*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(reference))->GetData())).y) < 0.01f &&
            std::abs((*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(reference))->GetData())).z) < 0.01f)
        {
            pBound = new FUN_00c37ec0;
            reinterpret_cast<::FUN_00439680_class *>((pBound))->FUN_00439680((*(const ::NiPoint3 *)(reinterpret_cast<::fnv_00569880::FUN_00569880_cls *>((reference))->FUN_00569880())));
        }
        else
        {
            pBound = new FUN_00c36310;
            reinterpret_cast<::FUN_004396b0_class *>((pBound))->FUN_004396b0((const ::Mat9 &)((const ::Matrix &)(reference->FUN_0056fa00())));
            reinterpret_cast<::FUN_00439680_class *>((pBound))->FUN_00439680((*(const ::NiPoint3 *)(reinterpret_cast<::fnv_00569880::FUN_00569880_cls *>((reference))->FUN_00569880())));
        }
        pBound->SetScale(reference->v125());
        result = new BSMultiBound;
        result->FUN_004addc0(pBound);
    }
    return result;
}

// @fnv 0x0043b290
int __cdecl FUN_0043b290()
{
    return (int)11u;
}

static long InterlockedCompareExchangeImport(long volatile* Destination, long Exchange, long Comparand)
{
    return _InterlockedCompareExchange(Destination, Exchange, Comparand);
}

typedef long(* InterlockedCompareExchange_t)(long volatile*, long, long);

InterlockedCompareExchange_t DAT_00fdf1bc = InterlockedCompareExchangeImport;

// @fnv 0x0043b460
long __cdecl FUN_0043b460(long volatile* apDestination, long aiComparand, long aiExchange)
{
    return DAT_00fdf1bc(apDestination, aiExchange, aiComparand);
}

struct ObjB4037
{
};

struct Sub4037
{
    ObjB4037** FUN_006815c0();
    void FUN_00726c60(int* a);
    void FUN_0063f7b0();
};

struct Host00437df0
{
    char m_auiShapeKeys[0x20];
    Sub4037 m_sub;
    void FUN_00437df0();
};

// Calls FUN_007b3fa0(true) on the object returned by m_sub.FUN_006815c0 if non-null, then FUN_00726c60(&d) and FUN_0063f7b0 on m_sub.
// @fnv 0x00437df0
void Host00437df0::FUN_00437df0()
{
    ObjB4037* a = *((::ObjB4037 **)(new ((void *)&(m_sub)) ::Vec3()));
    ObjB4037* b5;
    int d;
    b5 = a;
    (void)(b5 != 0 ? (void*)reinterpret_cast<::Date *>((b5))->FUN_007b3fa0(true) : 0);
    d = 0;
    m_sub.FUN_00726c60(&d);
    m_sub.FUN_0063f7b0();
}

class NiTMapBase438
{
  public:
    virtual ~NiTMapBase438();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_004388a0 : public NiTMapBase438
{
  public:
    virtual ~FUN_004388a0();
};
// @fnv 0x00438440
void* FUN_00438440_Class::FUN_00438440(unsigned int flags)
{
    reinterpret_cast<::FUN_004388a0 *>((((FUN_004388a0_Class*)this)))->FUN_004388a0::~FUN_004388a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004388a0
FUN_004388a0::~FUN_004388a0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct AnimPoint3
{
    float x, y, z;
};
struct AnimMatrix3
{
    float m[9];
};

struct AnimMemObject
{
};

struct AnimSource
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void* GetSourceData();
    AnimMatrix3 FUN_0056fa00();
};

struct AnimInterpolator : AnimMemObject
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void SetSource(void* apData);
};

struct AnimPointInterpolator : AnimInterpolator
{
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    AnimPointInterpolator();
};

struct AnimTransformInterpolator : AnimInterpolator
{
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44;
    AnimTransformInterpolator();
};

struct AnimBlendData : AnimMemObject
{
    int unk00, unk04, unk08, unk0C;
    AnimBlendData();
    void SetInterpolator(AnimInterpolator* apInterp);
};

struct AnimController : AnimMemObject
{
    int unk00;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    int unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0;
    int unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0;
    int unkE4, unkE8;
    AnimController();
};

// @fnv 0x004396e0
AnimController* __cdecl FUN_004396e0(AnimSource* apSource)
{
    AnimController* pController = 0;
    if (apSource)
    {
        AnimBlendData* pData;
        AnimInterpolator* pInterp = 0;
        if (std::abs((*(const ::AnimPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(apSource))->GetData())).x) < 0.01f &&
            std::abs((*(const ::AnimPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(apSource))->GetData())).y) < 0.01f && std::abs((*(const ::AnimPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(apSource))->GetData())).z) < 0.01f)
        {
            pInterp = new AnimPointInterpolator;
            reinterpret_cast<::FUN_00439680_class *>((pInterp))->FUN_00439680((const ::NiPoint3 &)((*(const ::AnimPoint3 *)(reinterpret_cast<::fnv_00569880::FUN_00569880_cls *>((apSource))->FUN_00569880()))));
        }
        else
        {
            pInterp = new AnimTransformInterpolator;
            reinterpret_cast<::FUN_004396b0_class *>((pInterp))->FUN_004396b0((const ::Mat9 &)((const ::AnimMatrix3 &)(apSource->FUN_0056fa00())));
            reinterpret_cast<::FUN_00439680_class *>((pInterp))->FUN_00439680((const ::NiPoint3 &)((*(const ::AnimPoint3 *)(reinterpret_cast<::fnv_00569880::FUN_00569880_cls *>((apSource))->FUN_00569880()))));
        }
        pInterp->SetSource(apSource->GetSourceData());
        pController = new AnimController;
        pData = new AnimBlendData;
        pData->SetInterpolator(pInterp);
        reinterpret_cast<::BSFaceGenNiNode *>((pController))->SetAnimationData((::BSFaceGenAnimationData *)(pData));
    }
    return pController;
}

struct RefCountedObject
{
    void IncRefCount();
    void DecRefCount();
};

struct FUN_0043b750
{
    void* m_pBuffer;
    NiPointer<RefCountedObject> m_pHeadNode;
    NiPointer<RefCountedObject> m_iSecondInteger;
    int m_unk0c;
    int m_unk10;

    ~FUN_0043b750();
};

// Frees m_pBuffer and clears the two reference-counted pointers.
// @fnv 0x0043b750
FUN_0043b750::~FUN_0043b750()
{
    void* pBuffer = m_pBuffer;
    ::FUN_00401030(pBuffer);
    m_pHeadNode = 0;
    m_iSecondInteger = 0;
}

class NiFixedString
{
  public:
    NiFixedString(const char* pcString);
    ~NiFixedString();
    const char* m_kHandle;
};

class NameSource
{
  public:
    const char* FUN_0043b1b0();
};
class NamedObject
{
  public:
};
class AttachedNode
{
};
class AttachTarget
{
  public:
};

class NamedObjectPtr
{
  public:
    NamedObject* m_pObject;
      // NiPointer<T>::operator T*
};
class AttachedNodePtr
{
  public:
    AttachedNode* m_pObject;
                       // NiPointer<T>::operator T*
    AttachedNodePtr& FUN_0066b0d0(AttachedNode* pkNode);  // NiPointer<T>::operator=
};

const char* __cdecl FUN_0043b9d0(const char* pcString, int iChar);

class NamedObjectLoader
{
  public:
    int unk00;
    NamedObjectPtr m_pReferencedObject;  // +0x04
    AttachedNodePtr m_spNode;            // +0x08
    void FUN_0043b7e0(const char* pcName);
};

// @fnv 0x0043b7e0
void NamedObjectLoader::FUN_0043b7e0(const char* pcName)
{
    if (!((::NamedObject *)(::FUN_00559450((int *)&(m_pReferencedObject)))))
        return;
    const char* pcPath = ((::NameSource *)(reinterpret_cast<::TESTopicInfoData *>((((::NamedObject *)(::FUN_00559450((int *)&(m_pReferencedObject))))))->GetLinkToList()))->FUN_0043b1b0();
    if (pcPath)
    {
        const char* pcSep = FUN_0043b9d0(pcPath, '_');
        if (pcSep)
        {
            char acBuffer[260];
            ::__memcpy(acBuffer, pcPath, pcSep - pcPath);
            acBuffer[pcSep - pcPath] = 0;
            reinterpret_cast<::FUN_0043b9f0_shell *>((((::NamedObject *)(::FUN_00559450((int *)&(m_pReferencedObject))))))->FUN_0043b9f0((::FUN_0043ba10_shell *)&(const ::NiFixedString &)(NiFixedString(acBuffer)));
        }
    }
    m_spNode.FUN_0066b0d0(((::AttachedNode *)(::fnv_005f3a20::FUN_005f3a20((::fnv_005f3a20::NiControllerSequenceEx *)(::NamedObject *)(((::NamedObject *)(::FUN_00559450((int *)&(m_pReferencedObject))))), pcName))));
    if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011c7d74))), (::NiAVObject *)(::NamedObject *)(((::NamedObject *)(::FUN_00559450((int *)&(m_pReferencedObject)))))))
        reinterpret_cast<::FUN_0043baa0_class *>((((::AttachTarget *)(reinterpret_cast<::StrOwner *>(this)->FUN_007fa950()))))->FUN_0043baa0(((::AttachedNode *)(::FUN_00559450((int *)&(m_spNode)))));
    reinterpret_cast<::FUN_0043b9f0_shell *>((((::NamedObject *)(::FUN_00559450((int *)&(m_pReferencedObject))))))->FUN_0043b9f0((::FUN_0043ba10_shell *)&(const ::NiFixedString &)(NiFixedString(pcName)));
}

class MenuTopic;

class ExtraBase437510
{
  public:
    virtual ~ExtraBase437510();
    unsigned char m_ucType;
    void* m_pkNext;
    ExtraBase437510(unsigned char type);
};

class FUN_00437510 : public ExtraBase437510
{
  public:
    BSSimpleList<BSSimpleList<MenuTopic*>*>* m_pTopics;
    FUN_00437510(BSSimpleList<MenuTopic*>* topics);
    ~FUN_00437510();
};

// Constructs an extra of type 0x73 holding a new list and adds the given topics list to it.
// @fnv 0x00437510
FUN_00437510::FUN_00437510(BSSimpleList<MenuTopic*>* topics) : ExtraBase437510(0x73)
{
    m_pTopics = new BSSimpleList<BSSimpleList<MenuTopic*>*>;
    m_pTopics->AddHead(topics);
}

struct FUN_00438df0
{
    void* vtbl;
    int unk4;
    int unk8;
    char unk0c;
    unsigned short unk0e;
    int unk10;
    void FUN_00438df0_copy(FUN_00438df0* src);
};

// @fnv 0x00438df0
void FUN_00438df0::FUN_00438df0_copy(FUN_00438df0* apSource)
{
    ((void(*)(void*, FUN_00438df0*))(*((void***)this))[2])(this, apSource);
    unk0c = apSource->unk0c;
    unk0e = apSource->unk0e;
    unk10 = apSource->unk10;
}

struct ListArg436
{
    void* m_pFirstNode;
    void* m_pTail;
    int m_uiItemCount;
    ~ListArg436();
};

class ExtraBase436
{
  public:
    ExtraBase436(unsigned char ucType);
    virtual ~ExtraBase436();
    unsigned char m_ucType;
    ExtraBase436* m_pkNext;
};

struct ExtraList436
{
    ExtraList436();
    ~ExtraList436();
    int m_data;
};

class FUN_00436300 : public ExtraBase436
{
  public:
    FUN_00436300(ListArg436 kList);
    virtual ~FUN_00436300();
    ExtraList436 m_kList;
};

// Constructs an ExtraBase436 with type 0x8a and copies the supplied ListArg436 into m_kList.
// @fnv 0x00436300
FUN_00436300::FUN_00436300(ListArg436 kList) : ExtraBase436(0x8a)
{
    reinterpret_cast<::SoundPlaybackHandle *>(&(m_kList))->operator=((*(const ::SoundPlaybackHandle *)(&kList)));
}

struct ExtraDataBase436540
{
    virtual void Slot00();
    unsigned int unk04;
    void* unk08;
    ExtraDataBase436540(unsigned char type);
    ~ExtraDataBase436540();
};

struct Value436540
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Value436540();
    ~Value436540();
    Value436540& operator=(const Value436540& other);
};

struct FUN_00436540 : ExtraDataBase436540
{
    Value436540 m_uiFilterValue;
    FUN_00436540(Value436540 value);
};

// @fnv 0x00436540
FUN_00436540::FUN_00436540(Value436540 value) : ExtraDataBase436540(0x86)
{
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::Value436540 &)(m_uiFilterValue))->operator=((const ::SoundPlaybackHandle &)(value));
}

struct Val42CE30
{
    void* p;
    Val42CE30();
};

struct C42CE30
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
    Val42CE30 m_kValue;
    Val42CE30 FUN_0042ce30();
};

// @fnv 0x0042ce30
Val42CE30 C42CE30::FUN_0042ce30()
{
    return m_kValue;
}

struct Guard430
{
    ~Guard430();
};
Guard430::~Guard430()
{}
struct FUN_00436b20_Ref
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
    virtual NiPoint3* v125();
};
namespace FNV {
struct FUN_00436b20 : BE
{
    Guard430 m_guard;
    unsigned int unk04;
    unsigned int unk08;
    CloneRef* unk0c;
    FUN_00436b20(uintptr_t first, uintptr_t second);
};
// Sets the vtable pointer, stores the result of FUN_00436780(first, second) in unk0c, then calls FUN_00575830 on it with second's v125() point.
// @fnv 0x00436b20
FUN_00436b20::FUN_00436b20(uintptr_t first, uintptr_t second) : BE(0x55)
{
    *(void**)this = (void*)&DAT_01015f24;
    unk0c = ((CloneFactory*)this)->FUN_00436780((void*)first, (CloneSource*)second);
    reinterpret_cast<::Reference *>((unk0c))->FUN_00575830((::Position *)&(*((FUN_00436b20_Ref*)second)->v125()));
}
}

struct FUN_00438690
{
    ~FUN_00438690();
};
struct FUN_004389d0 : FUN_00438690
{
    virtual ~FUN_004389d0();
};
// Empty destructor for FUN_004389d0, inheriting from FUN_00438690.
// @fnv 0x004389d0
FUN_004389d0::~FUN_004389d0()
{}

namespace fnv_00436420 {
struct Arg
{
    int a;
    ~Arg();
};
struct Member
{
    int x, y, z;
    Member();
    ~Member();
};
struct Base
{
    Base(int n);
    ~Base();
    virtual void v0();
    int p, q;
};
struct FUN_00436420 : Base
{
    Member m;
    FUN_00436420(Arg a, int b, int c);
    virtual void v0();
};
// Constructs the object by calling the Base constructor with 0x83 and assigning the Arg parameter to the Member field m.
// @fnv 0x00436420
FUN_00436420::FUN_00436420(Arg a, int aiUnused1, int aiUnused2) : Base(0x83)
{
    reinterpret_cast<::SoundPlaybackHandle *>(&(m))->operator=((const ::SoundPlaybackHandle &)(a));
}
}  // namespace fnv_00436420

extern "C" void _fnv_zlib_memset(void* p, int c, unsigned int n);

class FUN_0043a9f0_C
{
  public:
    TESObjectREFR* m_pkRef;

    void FUN_0043a9f0();
};

// @fnv 0x0043a9f0
void FUN_0043a9f0_C::FUN_0043a9f0()
{
    unsigned int auiFormId = (unsigned int)(uintptr_t)m_pkRef;
    if (auiFormId)
        m_pkRef = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(auiFormId));
}

#include "generated/data/staging/blk_00420000_od.inc"
