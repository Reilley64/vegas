
// src/staging/blk_00580000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include <new>
#include <cstring>
#include "fnv/decl/BGSCameraShot.h"
#include "fnv/decl/BSMultiBoundRoom.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047b4d0_Class.h"
#include "fnv/decl/FUN_004f00e0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/Holder5934d0.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/StrMem.h"
#include "fnv/decl/TESForm.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00554000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0058b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_01033000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01186000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "../../include/layout_support.h"

struct FUN_004fc990_t
{
    void FUN_004fc990(int, bool);
};

struct FUN_00580310_t
{
    void SetFlag400(bool b);
};

// @fnv 0x00580310
void FUN_00580310_t::SetFlag400(bool abEnabled)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(0x400, abEnabled);
}

namespace fnv_00580540 {
struct FUN_004fc990_t
{
};

struct FUN_00580540_t
{
    void SetValue(int value);
};

// @fnv 0x00580540
void FUN_00580540_t::SetValue(int value)
{
    reinterpret_cast<::FUN_004fc990_t *>((reinterpret_cast<FUN_004fc990_t*>(this)))->FUN_004fc990(2, reinterpret_cast<bool&>(value));
}
}  // namespace fnv_00580540

namespace fnv_00580560 {
struct FUN_004fc990_t
{
    void SetFlag80(bool argument0);
};

// @fnv 0x00580560
void FUN_004fc990_t::SetFlag80(bool abEnabled)
{
    reinterpret_cast<::FUN_004fc990_t *>(this)->FUN_004fc990(0x80, abEnabled);
}
}  // namespace fnv_00580560

namespace fnv_00580580 {
struct FUN_004fc990_t
{
};
struct FUN_00580580_t
{
    void SetFlag100(bool a);
};
// @fnv 0x00580580
void FUN_00580580_t::SetFlag100(bool abEnabled)
{
    reinterpret_cast<::FUN_004fc990_t *>((((FUN_004fc990_t*)this)))->FUN_004fc990(0x100, abEnabled);
}
}  // namespace fnv_00580580

namespace fnv_005805a0 {
struct FUN_004fc990_t
{
};

struct FUN_005805a0_t
{
    void SetFlag8000000(bool argument0);
};

// @fnv 0x005805a0
void FUN_005805a0_t::SetFlag8000000(bool abEnabled)
{
    reinterpret_cast<::FUN_004fc990_t *>((((FUN_004fc990_t*)this)))->FUN_004fc990(0x8000000, abEnabled);
}
}  // namespace fnv_005805a0

struct FUN_00581fb0_Class
{
    void FUN_00581fb0(int index, int value);
};

// @fnv 0x00581fb0
void FUN_00581fb0_Class::FUN_00581fb0(int index, int value)
{
    *(int*)((char*)this + index * 4 + 4) = value;
}

struct FUN_005822a0_cls
{
    int FUN_005822a0(int index);
};

// @fnv 0x005822a0
int FUN_005822a0_cls::FUN_005822a0(int index)
{
    return *(int*)((char*)this + index * 4 + 4);
}

extern int DAT_01031fcc;
struct FUN_00588fd0Class
{
    void FUN_005891c0(int);
    int* FUN_00588fd0(int a);
};
// Calls FUN_005891c0 with a, stores the address of DAT_01031fcc into this, and returns this.
// @fnv 0x00588fd0
int* FUN_00588fd0Class::FUN_00588fd0(int a)
{
    FUN_005891c0(a);
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01031fcc);
    return reinterpret_cast<int*>(this);
}

struct FUN_0058bc00_obj
{
};

// @fnv 0x0058b830
void FUN_0058b830(FUN_0058bc00_obj* this_ptr)
{
    ::FUN_0058bc00((::FUN_0058bc00_obj *)(this_ptr));
}

struct FUN_0058cac0_Class
{
    unsigned int* pFlags;
    bool IsFlag20Set() const;
};

// @fnv 0x0058cac0
bool FUN_0058cac0_Class::IsFlag20Set() const
{
    return (*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0x44) & 0x20) ? true : false;
}

struct FUN_00573eb0_Class
{
    int FUN_0058cae0();
};

// @fnv 0x0058cae0
int FUN_00573eb0_Class::FUN_0058cae0()
{
    return ((int)(reinterpret_cast<::FUN_0047b4d0_Class *>(this)->FUN_0047b4d0(0x20)));
}

struct FUN_0058cba0_class
{
    enum Flag
    {
        FLAG_NONE = 0
    };
    bool FUN_0058cba0(Flag flag);
};

// @fnv 0x0058cba0
bool FUN_0058cba0_class::FUN_0058cba0(Flag flag)
{
    return (*(int*)((char*)this + 0x58) & (int)flag) != 0;
}

struct FUN_0058ccd0_class
{
    bool IsFlagSet() const;
};

// @fnv 0x0058ccd0
bool FUN_0058ccd0_class::IsFlagSet() const
{
    return (((int*)((char*)this + 0x44))[0] & 1) ? true : false;
}

struct FUN_0058ce30_Class
{
    bool IsFlag2Set() const;
};

// @fnv 0x0058ce30
bool FUN_0058ce30_Class::IsFlag2Set() const
{
    return ((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0x44) & 2) != 0) ? true
                                                                                                           : false;
}

extern int DAT_01033470;
struct FUN_0058f820_class
{
    int m_iWordAt00;
    int FUN_0058f820(int a);
};

struct FUN_00591a00_Class
{
    char* CopyString(const char* src);
};

// Copies src into the object's storage with ___insecure_strcpy and returns a pointer to that storage.
// @fnv 0x00591a00
char* FUN_00591a00_Class::CopyString(const char* apSource)
{
    ::FUN_004046f0(reinterpret_cast<char*>(this), apSource);
    return reinterpret_cast<char*>(this);
}

struct FUN_00591a20_Class
{
    int IsFlagBit4Set();
};

// @fnv 0x00591a20
int FUN_00591a20_Class::IsFlagBit4Set()
{
    return ((*(int*)((char*)this + 4)) & 0x10) ? 1 : 0;
}

struct FUN_00594d20_Class
{
    int FUN_00594d20();
};

// @fnv 0x00594d20
int FUN_00594d20_Class::FUN_00594d20()
{
    return *(int*)((char*)this + 0x200) == -1;
}

struct FUN_00594d40_class
{
    void ResetField();
};

// @fnv 0x00594d40
void FUN_00594d40_class::ResetField()
{
    *(int*)((char*)this + 0x200) = 0xffffffff;
}

struct FUN_00598020_Class
{
    unsigned char GetByteAtOffset55();
};

// @fnv 0x00598020
unsigned char FUN_00598020_Class::GetByteAtOffset55()
{
    return ((const unsigned char*)this)[0x37];
}

extern int DAT_0103200c;
struct FUN_00589190 : NiTPointerMap<int, int>
{
    void Init();
};
// Sets the map's vtable pointer, removes all entries, and frees the pointer stored at offset 8.
// @fnv 0x00589190
void FUN_00589190::Init()
{
    *(int*)((char*)this + 0) = (int)&DAT_0103200c;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

struct FUN_00589030_Class
{
    void* FUN_00589030(unsigned int flags);
};

struct FUN_00580680_Class
{
    virtual ~FUN_00580680_Class();
    virtual void FUN_00580680(int a);
};

// @fnv 0x00580680
void FUN_00580680_Class::FUN_00580680(int a)
{
    if (this == (FUN_00580680_Class*)a)
    {
        *(int*)((char*)this + 0x80) = 0;
        (*(void(*)(FUN_00580680_Class*, int))(*(int**)this)[0x4c / 4])(this, 0x80000000);
    }
    else
    {
        *(int*)((char*)this + 0x80) = a;
        (*(void(*)(FUN_00580680_Class*, int))(*(int**)this)[0x48 / 4])(this, 0x80000000);
    }
}

struct BFC_s
{
    BFC_s();
};
extern int DAT_01031838;
struct S82000
{
};
struct FUN_00581fd0 : BFC_s
{
    FUN_00581fd0();
};
struct FUN_00582000_Class
{
    int m_iWordAt00;
    int m_cByteAtOffset1[6];
    void ClearArray();
};
// Sets the object's vtable pointer to DAT_01031838, then calls ClearArray on this.
// @fnv 0x00581fd0
FUN_00581fd0::FUN_00581fd0()
{
    *(int*)this = (int)&DAT_01031838;
    reinterpret_cast<::FUN_00582000_Class *>((((S82000*)this)))->ClearArray();
}

// @fnv 0x00582000
void FUN_00582000_Class::ClearArray()
{
    for (unsigned int i = 0; i < 6; ++i)
        m_cByteAtOffset1[i] = 0;
}

struct TESSound
{
};
struct FUN_00582040_Class
{
    void ReleaseSoundSlots();
};
// @fnv 0x00582040
void FUN_00582040_Class::ReleaseSoundSlots()
{
    for (unsigned int i = 0; i < 6; ++i)
    {
        if (((int*)this)[i + 1])
        {
            int v = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESSound*)((int*)this)[i + 1])))->FUN_0084e3a0()));
            ::FUN_00485910(0x44414900 + i, v);
        }
    }
}

struct TESWeatherList
{
    void ClearWeatherSounds();
};
struct SL
{
    SL();
    ~SL();
};
struct FUN_005822c0 : SL
{
    FUN_005822c0();
    TESWeatherList weather;
};
// @fnv 0x005822c0
FUN_005822c0::FUN_005822c0()
{
    weather.ClearWeatherSounds();
}

// @fnv 0x00582be0
int __cdecl CompareSecondElement(unsigned int* pFirst, unsigned int* pSecond)
{
    int iResult;
    if (pFirst[1] > pSecond[1])
        iResult = -1;
    else
        iResult = pFirst[1] < pSecond[1];
    return iResult;
}


// Returns 1 for characters 0x39 and 0x44, otherwise delegates to FUN_005548a0 with the same character.
// @fnv 0x00588a60
unsigned char __cdecl FUN_00588a60(unsigned char a)
{
    if (a == 0x39)
        return 1;
    if (a == 0x44)
        return 1;
    return ((unsigned char)(::FUN_005548a0(a)));
}

struct FUN_00589230_t
{
    void FUN_00589230();
};

struct FUN_00589060_t
{
    void* FUN_00589060(unsigned int flags);
};

struct Helper89330
{
};
struct FUN_00589090_Cls
{
    void* FUN_00589090(unsigned int flags);
};
struct FUN_005890c0
{
    int* pVTable;
    unsigned int uiSize;
    void* pMem;
    unsigned int ItemUpdateArray;
    FUN_005890c0(unsigned int size);
};
// Sets the vtable, stores size, allocates size*4 bytes with NiMalloc and zeroes them with memset.
// @fnv 0x005890c0
FUN_005890c0::FUN_005890c0(unsigned int size)
{
    pVTable = &DAT_0103200c;
    uiSize = size;
    ItemUpdateArray = 0;
    unsigned int uiAllocBytes = uiSize * 4;
    pMem = ::FUN_00aa1070(uiAllocBytes);
    ::FUN_00403d30(pMem, 0, uiSize * 4);
}

namespace fnv_005891c0 {
void* __cdecl memset(void* dst, int c, unsigned int n);
struct FUN_005891c0_Class
{
    int* pVTable;
    int count;
    int* pData;
    int zero;
    FUN_005891c0_Class(int n);
};
// Sets the vtable, stores n as count, allocates count*4 bytes, zeroes the buffer and stores it in pData.
// @fnv 0x005891c0
FUN_005891c0_Class::FUN_005891c0_Class(int aiCount)
{
    pVTable = &::DAT_0103202c;
    count = aiCount;
    zero = 0;
    int size = count * 4;
    pData = (int*)::FUN_00aa1070(size);
    ::FUN_00403d30(pData, 0, count * 4);
}
}  // namespace fnv_005891c0

struct FUN_00589290_Class
{
    void FUN_00589290();
};
// @fnv 0x00589290
void FUN_00589290_Class::FUN_00589290()
{
    *(void**)this = (void*)&DAT_0103202c;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(*((void**)(((char*)this) + 8)));
}

namespace fnv_005892c0 {
extern "C" void* memset(void*, int, unsigned int);
struct FUN_005892c0_t
{
    void* InitArray(unsigned int count);
};
// Sets the vtable, stores count, allocates count*4 bytes with NiMalloc, zeroes the buffer, and returns this.
// @fnv 0x005892c0
void* FUN_005892c0_t::InitArray(unsigned int count)
{
    unsigned int size;
    *(int*)this = (int)&::DAT_0103204c;
    ((unsigned int*)this)[1] = count;
    ((unsigned int*)this)[3] = 0;
    size = ((unsigned int*)this)[1] << 2;
    ((unsigned int*)this)[2] = (unsigned int)::FUN_00aa1070(size);
    memset(*(void**)((unsigned int*)this + 2), 0, ((unsigned int*)this)[1] << 2);
    return this;
}
}  // namespace fnv_005892c0

struct FUN_00589390_Holder
{
    void FUN_00589390();
};
// @fnv 0x00589390
void FUN_00589390_Holder::FUN_00589390()
{
    *(int*)this = (int)&DAT_0103204c;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)((char*)this + 8));
}

struct FUN_005893c0Class
{
    void* InitAndMaybeFree(unsigned int flags);
};
// Calls Init on this object, then frees this if bit 0 of flags is set, and returns this.
// @fnv 0x005893c0
void* FUN_005893c0Class::InitAndMaybeFree(unsigned int flags)
{
    ((FUN_00589190*)this)->Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_005893f0_Class
{
    void* FUN_005893f0(unsigned int flags);
};

// @fnv 0x005893f0
void* FUN_005893f0_Class::FUN_005893f0(unsigned int flags)
{
    reinterpret_cast<::FUN_00589290_Class *>(this)->FUN_00589290();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00589420_Class
{
    void* FUN_00589420(unsigned int flags);
};

// @fnv 0x00589420
void* FUN_00589420_Class::FUN_00589420(unsigned int flags)
{
    reinterpret_cast<::FUN_00589390_Holder *>(this)->FUN_00589390();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_00589850_Class
{
    float m_iWordAt00;
    float m_cByteAtOffset1;
    float FUN_00589850();
};

// @fnv 0x00589850
float FUN_00589850_Class::FUN_00589850()
{
    return FUN_004579e0(this->m_iWordAt00 * this->m_iWordAt00 + this->m_cByteAtOffset1 * this->m_cByteAtOffset1);
}

struct FUN_004726b0_class
{
    int FUN_004726b0();
};
struct FUN_00589890_Class
{
    bool FUN_00589890(FUN_004726b0_class* apData);
};
// @fnv 0x00589890
bool FUN_00589890_Class::FUN_00589890(FUN_004726b0_class* apData)
{
    if (!apData)
        return false;
    if (apData->FUN_004726b0() != 0x4b524d4d)
        return false;
    return true;
}

struct NiFormArray
{
    unsigned int GetIndexOfForm(TESForm*);
};
struct FUN_0058b680_Class
{
    unsigned int FUN_0058b680(TESForm* form);
};
// @fnv 0x0058b680
unsigned int FUN_0058b680_Class::FUN_0058b680(TESForm* form)
{
    unsigned int result = 0xFFFFFFFF;
    if (reinterpret_cast<NiFormArray**>(reinterpret_cast<char*>(this) + 0x2C)[0])
        result = reinterpret_cast<NiFormArray**>(reinterpret_cast<char*>(this) + 0x2C)[0]->GetIndexOfForm(form);
    return result;
}

struct TESSound;
struct TESTopicInfo;
struct FUN_0058b630_shell
{
    TESSound* GetCameraPathAt(unsigned int index);
};
struct NiTLargeArray_TESTopicInfo
{
    TESTopicInfo* RemoveAt(unsigned int index);
    void Compact();
};
struct TES
{
};
struct FUN_0058b6c0_shell
{
    void RemoveSoundAt(unsigned int index);
};
// @fnv 0x0058b6c0
void FUN_0058b6c0_shell::RemoveSoundAt(unsigned int index)
{
    TESSound* next;
    TESSound* prev;
    if (*(unsigned int*)((char*)this + 0x2c))
    {
        next = ((FUN_0058b630_shell*)this)->GetCameraPathAt(index + 1);
        prev = ((FUN_0058b630_shell*)this)->GetCameraPathAt(index - 1);
        if (next)
            reinterpret_cast<::LowProcess *>((((TES*)next)))->SetCurrentBoundObject((::TESBoundObject *)(prev));
        ((NiTLargeArray_TESTopicInfo*)*(unsigned int*)((char*)this + 0x2c))->RemoveAt(index);
        ((NiTLargeArray_TESTopicInfo*)*(unsigned int*)((char*)this + 0x2c))->Compact();
    }
}

struct Holder680
{
};
struct Holder6c0
{
};
struct Holder730
{
    char _pad[0x2c];
    int m_2c;
    void FUN_0058b730(int);
};
// If a1 and m_2c are both nonzero, calls FUN_0058b680 with a1 and passes its result to RemoveSoundAt.
// @fnv 0x0058b730
void Holder730::FUN_0058b730(int a1)
{
    int v;
    if (a1 != 0 && m_2c != 0)
    {
        v = ((int)(reinterpret_cast<::FUN_0058b680_Class *>((((Holder680*)this)))->FUN_0058b680((::TESForm *)(a1))));
        reinterpret_cast<::FUN_0058b6c0_shell *>((((Holder6c0*)this)))->RemoveSoundAt(v);
    }
}

namespace fnv_0058b770 {
struct NiFormArray
{
    NiFormArray();
    ~NiFormArray();
};
struct BGSCameraPath;
struct NiTPrimitiveArray_BGSCameraPath
{
    NiTPrimitiveArray_BGSCameraPath(unsigned int, unsigned int);
    ~NiTPrimitiveArray_BGSCameraPath();
};
struct FUN_0058b770 : public NiFormArray
{
    char pad[0x18 - sizeof(NiFormArray) + 1];
    NiTPrimitiveArray_BGSCameraPath arr;
    FUN_0058b770();
};
// @fnv 0x0058b770
FUN_0058b770::FUN_0058b770() : arr(0, 1)
{}
}  // namespace fnv_0058b770

namespace fnv_0058bc60 {

struct FUN_0058bc60_Class
{
    void* FUN_0058bc60(unsigned int flags);
};

// @fnv 0x0058bc60
void* FUN_0058bc60_Class::FUN_0058bc60(unsigned int flags)
{
    ::FUN_0058bc00((::FUN_0058bc00_obj *)(((FUN_0058bc00_obj*)this)));
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0058bc60

void FUN_0058b830(FUN_0058bc00_obj* this_ptr);
struct FUN_0058bc90_Holder
{
    void* FUN_0058bc90(unsigned int flags);
};
// @fnv 0x0058bc90
void* FUN_0058bc90_Holder::FUN_0058bc90(unsigned int flags)
{
    FUN_0058b830((FUN_0058bc00_obj*)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0058cb60_Class
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned short m_8;
    unsigned int m_iThirdValue;
    int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned char m_1c;
    int m_20;
    int FUN_0058cb60(unsigned int* a, int* b, unsigned char* c);
};
// Writes m_8, m_10 and m_1c to the three output pointers and returns m_20.
// @fnv 0x0058cb60
int FUN_0058cb60_Class::FUN_0058cb60(unsigned int* a, int* piValue, unsigned char* c)
{
    *a = m_8;
    *piValue = m_10;
    *c = m_1c;
    return m_20;
}

struct FUN_0058f7f0_Class
{
    int* FUN_0058f7f0(int a);
};

// Returns a pointer to the entry at offset 0x30 plus a*0x1e if its first byte is nonzero, otherwise returns 0.
// @fnv 0x0058f7f0
int* FUN_0058f7f0_Class::FUN_0058f7f0(int aiIndex)
{
    if (*(char*)((char*)this + 0x30 + aiIndex * 0x1e))
        return (int*)((char*)this + 0x30 + aiIndex * 0x1e);
    return 0;
}


struct FUN_0058f850_class
{
    void FUN_0058f900();
    void* FUN_0058f850(unsigned int flags);
};

extern int DAT_01033490;
struct FUN_0058f960_Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    void FUN_0058f960();
};
// @fnv 0x0058f960
void FUN_0058f960_Obj::FUN_0058f960()
{
    m_iWordAt00 = (int)&DAT_01033490;
    if (m_8 != 0)
    {
        void* p = m_8;
        ::FUN_00401030(p);
    }
}

struct FUN_0058f9a0_Class
{
    void FUN_0058f960();
    void* FUN_0058f9a0(unsigned int flags);
};
// Calls FUN_0058f960, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0058f9a0
void* FUN_0058f9a0_Class::FUN_0058f9a0(unsigned int flags)
{
    reinterpret_cast<::FUN_0058f960_Obj *>(this)->FUN_0058f960();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BSS
{
    char c[8];
    ~BSS();
};
struct PerkEntryConditionSet
{
    ~PerkEntryConditionSet();
};
struct FUN_00591170 : BSS
{
    PerkEntryConditionSet cond;
    ~FUN_00591170();
};
// Destructor that destroys the contained condition object and the base object.
// @fnv 0x00591170
FUN_00591170::~FUN_00591170()
{}

namespace fnv_005912d0 {
struct BFC_s
{
    int vf;
    BFC_s();
};
struct StrMem
{
    StrMem();
};
extern int DAT_01033ab8;
struct TESSoundFile : BFC_s
{
    StrMem s;
    TESSoundFile* FUN_005912d0();
};
// Initialises the object: calls the base constructor, sets the vtable pointer to DAT_01033ab8, constructs s, and returns this.
// @fnv 0x005912d0
TESSoundFile* TESSoundFile::FUN_005912d0()
{
    ::FUN_00402d30((int *)(this));
    *(int*)this = (int)&DAT_01033ab8;
    new ((void *)&(s)) ::StrMem();
    return this;
}
}  // namespace fnv_005912d0

extern unsigned int DAT_011ca87c;

// Returns the pointer stored at index in the array DAT_011ca880 if index is within DAT_011ca87c, otherwise returns 0.
// @fnv 0x005922a0
void* FUN_005922a0(unsigned int index)
{
    return index >= 0 && index < DAT_011ca87c ? (*reinterpret_cast<void ** *>(&::DAT_011ca880))[index] : 0;
}

// Returns true when aiType is 1 and the int at aiParam+4 is one of 0,1,2,3,9,10; otherwise false.
// @fnv 0x00594d60
bool IsValidTypeValue(int aiParam, int aiType)
{
    bool bResult = false;
    if (aiType == 1)
    {
        int iValue = *(int*)(aiParam + 4);
        switch (iValue)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 9:
        case 10:
            bResult = true;
            break;
        }
    }
    return bResult;
}

class TESFile
{
  public:
    bool NextChunk();
    bool GetChunkData(unsigned int* p);
};
class TESFullName;
class TESFullNameLoader
{
  public:
};
struct AudioMarkerData_589600
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_iThirdValue;
    unsigned int m_10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int m_24;
    char m_28;
    bool LoadFromFile(TESFile* apFile);
};
// @fnv 0x00589600
bool AudioMarkerData_589600::LoadFromFile(TESFile* apFile)
{
    if (!apFile)
        return false;
    if (reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0() != 0x4b524d4d)
        return false;
    unsigned int uiChunkValue = 0;
    if (!apFile->NextChunk())
        return false;
    if (reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0() == 0x4c4c5546)
        ::ReadFullName((TESFullName*)this, apFile);
    else
        return false;
    if (!apFile->NextChunk())
        return false;
    if (reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0() == 0x4d414e43)
    {
        apFile->GetChunkData(&uiChunkValue);
        m_24 = uiChunkValue;
    }
    else
        return false;
    if (!apFile->NextChunk())
        return false;
    if (reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0() == 0x4d414e42)
    {
        apFile->GetChunkData(&uiChunkValue);
        m_28 = uiChunkValue == 1;
    }
    else
        return false;
    if (!apFile->NextChunk())
        return false;
    if (reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0() == 0x4d414e4d)
        apFile->GetChunkData(&m_iThirdValue);
    else
        return false;
    if (!apFile->NextChunk())
        return false;
    if (reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0() == 0x4d414e4e)
        apFile->GetChunkData(&m_10);
    else
        return false;
    return true;
}

struct ContainerItemExtra
{
    void* pVTable;
    int iCount;
    void* pItem;
    int m_0c;
    void* InitContainerItemExtra(int count);
};
// @fnv 0x0058f820
int FUN_0058f820_class::FUN_0058f820(int a)
{
    reinterpret_cast<::ContainerItemExtra *>(this)->InitContainerItemExtra(a);
    m_iWordAt00 = (int)&DAT_01033470;
    return (int)this;
}
// Sets the vtable, stores count, zeroes m_0c, and if count is nonzero allocates count*4 bytes for pItem and zero-fills them.
// @fnv 0x0058f880
void* ContainerItemExtra::InitContainerItemExtra(int count)
{
    this->pVTable = &DAT_01033490;
    this->iCount = count;
    this->m_0c = 0;
    if (count)
    {
        unsigned int sz3 = this->iCount * 4;
        void* p2 = ::FUN_00401000(sz3);
        this->pItem = p2;
        std::memset(this->pItem, 0, this->iCount * 4);
    }
    return this;
}

struct Flt
{
    operator unsigned int();
};
struct FUN_0058cb00_Class
{
    char _pad[0x2c];
    intptr_t FUN_0058cb00(unsigned int* a, int* b, unsigned char* c);
};
// If the field at offset 0x2c is nonzero, forwards a, b and c to FUN_0058cb60 on that object; otherwise zeroes all three outputs and returns 0.
// @fnv 0x0058cb00
intptr_t FUN_0058cb00_Class::FUN_0058cb00(unsigned int* puiValue, int* piValue, unsigned char* pbValue)
{
    if ((unsigned int)*(Flt*)((char*)this + 0x2c))
        return ((FUN_0058cb60_Class*)(unsigned int)*(Flt*)((char*)this + 0x2c))
            ->FUN_0058cb60(puiValue, piValue, pbValue);
    *puiValue = 0;
    *piValue = 0;
    *pbValue = 0;
    return 0;
}

struct FNStub
{
    unsigned char m_auiShapeKeys[0x0c];
};

struct TESModel : FNStub
{
    unsigned int GetModelLength();
    float m_0c;
    float m_10;
    unsigned char m_pad14[0x10];
    int m_24;
    unsigned char m_28;

    void WriteToStream();
};


// @fnv 0x00589560
void TESModel::WriteToStream()
{
    ::FUN_004856f0((void *)(0x4c4c5546), ((char *)(reinterpret_cast<::FUN_00408da0_Class *>(this)->FUN_00408da0())), (void *)(GetModelLength() + 1));

    if (m_24 != 0)
        ::FUN_00485910(0x4d414e43, m_24);

    ::FUN_00485910(0x4d414e42, m_28 != 0);
    ::FUN_00485910(0x4d414e4d, m_0c);
    ::FUN_00485910(0x4d414e4e, m_10);
}

extern "C" void* __cdecl FUN_00ec43fb(int input, int mode, const void* type, const void* name, int flags);

struct ControllerArchive : FUN_00581fb0_Class
{
    void LoadControllerArchive(int source);
};

// Loads an archive from source and copies six entries into the base object via FUN_00581fb0.
// @fnv 0x005821b0
void ControllerArchive::LoadControllerArchive(int source)
{
    FUN_005822a0_cls* loaded = static_cast<FUN_005822a0_cls*>(FUN_00ec43fb(source, 0, &DAT_01183040, &DAT_01186ab0, 0));
    if (loaded == 0)
        return;
    for (unsigned int i = 0; i < 6; ++i)
    {
        FUN_00581fb0(i, loaded->FUN_005822a0(i));
    }
}

namespace fnv_00582220 {
FUN_005822a0_cls* __cdecl FUN_00ec43fb(int key, int zero, void* first, void* second, int trailing);
struct FUN_00582220_Class : FUN_005822a0_cls
{
    bool IsNotEqual(int key);
};
// Compares this object against the result of FUN_00ec43fb for the given key over six indices, returning true if any differ or no comparison exists.
// @fnv 0x00582220
bool FUN_00582220_Class::IsNotEqual(int key)
{
    FUN_005822a0_cls* comparison = FUN_00ec43fb(key, 0, &(*reinterpret_cast<int *>(&::DAT_01183040)), &(*reinterpret_cast<int *>(&::DAT_01186ab0)), 0);
    if (!comparison)
    {
        return true;
    }
    for (unsigned int index = 0; index < 6; ++index)
    {
        if (FUN_005822a0(index) != comparison->FUN_005822a0(index))
        {
            return true;
        }
    }
    return false;
}
}  // namespace fnv_00582220

class MapDtorWrap_b9454 : public NiTPointerMap<int, int>
{
  public:
    virtual void unk00();
    ~MapDtorWrap_b9454();
};

class FUN_00589130_cls : public MapDtorWrap_b9454
{
  public:
    virtual ~FUN_00589130_cls();
};
// Calls FUN_00589130, frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00589030
void* FUN_00589030_Class::FUN_00589030(unsigned int flags)
{
    reinterpret_cast<::FUN_00589130_cls *>(this)->FUN_00589130_cls::~FUN_00589130_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that clears all entries from the underlying NiTPointerMap by calling RemoveAll.
// @fnv 0x00589130
FUN_00589130_cls::~FUN_00589130_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<NiTPointerMap<int, int>*>(this)))->FUN_00438af0();
}

struct FUN_00589230_Base
{
    virtual ~FUN_00589230_Base();
};

struct FUN_00589230 : FUN_00589230_Base
{
    virtual ~FUN_00589230();
};
// Calls FUN_00589230 on this, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00589060
void* FUN_00589060_t::FUN_00589060(unsigned int flags)
{
    reinterpret_cast<::FUN_00589230 *>((((FUN_00589230_t*)this)))->FUN_00589230::~FUN_00589230();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00589230
FUN_00589230::~FUN_00589230()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct Base_589330
{
    virtual ~Base_589330();
    int unk04;
    int unk08;
};

class FUN_00589330_cls : public Base_589330
{
  public:
    int unk0C;

    virtual ~FUN_00589330_cls();
};
// @fnv 0x00589090
void* FUN_00589090_Cls::FUN_00589090(unsigned int flags)
{
    reinterpret_cast<::FUN_00589330_cls *>((((Helper89330*)this)))->FUN_00589330_cls::~FUN_00589330_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor of FUN_00589330_cls that calls FUN_00438af0 before the base destructor runs.
// @fnv 0x00589330
FUN_00589330_cls::~FUN_00589330_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_00591300
{
    ~FUN_00591300();
};

struct FUN_0046ffb0
{
    ~FUN_0046ffb0();
};

class FUN_00589500 : public FUN_00591300
{
  public:
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
    FUN_0046ffb0 member2c;

    ~FUN_00589500();
};

// Empty destructor for the class; destroys the base subobject and the member at offset 0x2c.
// @fnv 0x00589500
FUN_00589500::~FUN_00589500()
{}

struct S_00589770_Class;

typedef void(* S_00589770_VFn)(S_00589770_Class*, S_00589770_Class*);

struct S_00589770_Class
{
    S_00589770_VFn* pVTable;
    int unk04;
    int unk08;
    float unk0c;
    float unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned char unk28;

    void CopyFrom(S_00589770_Class* arg);
};

// @fnv 0x00589770
void S_00589770_Class::CopyFrom(S_00589770_Class* pSource)
{
    this->pVTable[2](this, pSource);

    this->unk24 = pSource->unk24;
    this->unk28 = pSource->unk28;
    this->unk0c = pSource->unk0c;
    this->unk10 = pSource->unk10;
}

void FUN_0058b830(FUN_0058bc00_obj* this_ptr);

struct FUN_0058b450
{
    ~FUN_0058b450();
};

struct FUN_0058b7d0 : FUN_0058b450
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_0058bc00_obj m_18;

    ~FUN_0058b7d0();
};

// @fnv 0x0058b7d0
FUN_0058b7d0::~FUN_0058b7d0()
{
    FUN_0058b830(&m_18);
}

void* __cdecl FUN_0096afc0(unsigned int size);

struct FUN_0058bcc0
{
    virtual ~FUN_0058bcc0();
    void* m_04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;

    FUN_0058bcc0(unsigned short a1, unsigned short a2);
};

// Initializes the object with two unsigned shorts, zeroes two fields, and allocates m_08 bytes into m_04 when m_08 is nonzero.
// @fnv 0x0058bcc0
FUN_0058bcc0::FUN_0058bcc0(unsigned short ausValue, unsigned short a2)
{
    m_08 = ausValue;
    m_0e = a2;
    m_0a = 0;
    m_0c = 0;
    if (m_08 > 0)
        m_04 = FUN_0096afc0(m_08);
    else
        m_04 = 0;
}

struct Mat3_58cbc0
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
};

struct Node_58cbc0
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
    Node_58cbc0(unsigned short usChildren);
};

struct NodePtr_58cbc0
{
    Node_58cbc0* m_pObject;
    NodePtr_58cbc0& operator=(Node_58cbc0* pObj);
    operator Node_58cbc0*() const;
};

struct Source_58cbc0
{
    Mat3_58cbc0 GetRotation();
};



struct Owner_58cbc0
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
    NodePtr_58cbc0 m_pController;
    int unk64;
    Source_58cbc0* pSource;

    void SetNode(Node_58cbc0* pNode);
};

// @fnv 0x0058cbc0
void Owner_58cbc0::SetNode(Node_58cbc0* pNode)
{
    if (reinterpret_cast<::FUN_0058ccd0_class *>((void *)this)->IsFlagSet())
    {
        m_pController = pNode;
    }
    else if (pNode)
    {
        m_pController = new Node_58cbc0(0);
        if (pSource)
        {
            reinterpret_cast<::FUN_0043fa80_s *>((((Node_58cbc0*)m_pController)))->FUN_0043fa80((const ::ThreeByThreeMatrix &)((const ::Mat3_58cbc0 &)(pSource->GetRotation())));
        }
        reinterpret_cast<::FUN_004f00e0_shell *>((((Node_58cbc0*)m_pController)))->FUN_004f00e0(((void *)(::FUN_0045bb80((int)(pNode)))));
    }
    ::DAT_011e07c3 = true;
}

struct NP
{
    void* object;
    NP& operator=(void*);
};
struct ModelComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* Name();
};
class ModelLoader
{
  public:
};
class TESRace;
class BSSimpleListTESRaceSize
{
  public:
    int GetSize();
};
struct BSSoundHandleEx
{
    unsigned int soundID;
    unsigned int state;
    unsigned int flags;
    ~BSSoundHandleEx();
};
class BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
struct CameraState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ModelComponent model;
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
    NP node60;
    NP node64;
    int unk68;
    NP node6c;
    NP node70;
    unsigned char unk74;
    bool active;
    void ResetCameraState();
};
// @fnv 0x0058ce50
void CameraState::ResetCameraState()
{
    node60 = 0;
    node64 = 0;
    unk68 = 0;
    node70 = 0;
    active = false;
    if (::FUN_00559450((int *)&(node6c)))
    {
        node6c = 0;
        reinterpret_cast<::FUN_0045a5e0_shell *>((::g_modelLoader))->FUN_0045a5e0((char *)(model.Name()));
    }
    if (DAT_011ca729 && !(*reinterpret_cast<::BSSimpleListTESRaceSize *>(&::g_011f2250)).GetSize())
    {
        DAT_011ca729 = false;
        BSSoundHandleEx sound = ::FUN_00453a70()->GetSoundHandleByEditorID("UIVATSCameraOut", 0x121);
        reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
    }
}

struct FUN_00483370
{
    virtual ~FUN_00483370();
    unsigned int formType;
    unsigned int formFlags;
    unsigned int formId;
    unsigned int formVersion;
    unsigned int formData;
    FUN_00483370();
};
struct FUN_00402c20
{
    virtual ~FUN_00402c20();
    FUN_00402c20();
};
struct FUN_00590210 : FUN_00483370, FUN_00402c20
{
    FUN_00590210();
    virtual ~FUN_00590210();
};
// Initializes the object by calling FUN_00483710 and then FUN_004f15a0 with a count of 5.
// @fnv 0x00590210
FUN_00590210::FUN_00590210()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(5);
}

struct FUN_00591200_base0
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ~FUN_00591200_base0();
    FUN_00591200_base0();
};

struct FUN_00591200_base1
{
    virtual void v00();
    int unk04;
    int unk08;
    FUN_00591200_base1();
    ~FUN_00591200_base1();
};

struct FUN_00591200_member
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00591200_member();
    ~FUN_00591200_member();
};


struct FUN_00591200_cls : FUN_00591200_base0, FUN_00591200_base1
{
    float m_24;
    FUN_00591200_member m_28;

    FUN_00591200_cls();
};

// Initializes the object by calling Setup with 0x66 and then assigning g_00591200_const to m_24.
// @fnv 0x00591200
FUN_00591200_cls::FUN_00591200_cls()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x66);
    m_24 = ::runtimeFloatSettingDefault313;
}

struct EntryRec_cls
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;
};

struct FUN_00594c80_cls
{
    EntryRec_cls m_entries[0x20];
    int m_uiItemCount;
    void AddEntry(EntryRec_cls e);
};

// Increments the entry count and stores the given entry at that index in m_entries.
// @fnv 0x00594c80
void FUN_00594c80_cls::AddEntry(EntryRec_cls aEntry)
{
    m_uiItemCount = m_uiItemCount + 1;
    m_entries[m_uiItemCount] = aEntry;
}

struct FUN_00594cd0_Entry
{
    int field00;
    int field04;
    int field08;
    int field0c;
};

struct FUN_00594cd0_Class
{
    FUN_00594cd0_Entry entries[32];
    unsigned int count;

    FUN_00594cd0_Entry* PopEntry(FUN_00594cd0_Entry* result);
};

// Copies the entry at index count into result, then decrements count.
// Copies entries[count] to *result, decrements count, and returns result.
// @fnv 0x00594cd0
FUN_00594cd0_Entry* FUN_00594cd0_Class::PopEntry(FUN_00594cd0_Entry* result)
{
    *result = entries[count];
    count = count - 1;
    return result;
}

struct FUN_006ab360_t
{
};

// @fnv 0x0059ae10
int __cdecl FUN_0059ae10(void* apLeft, void* apRight)
{
    int y;
    int x;
    x = *((int *)(reinterpret_cast<::BSMultiBoundRoom *>((((FUN_006ab360_t*)*(void**)apLeft)))->FUN_006ab360()));
    y = *((int *)(reinterpret_cast<::BSMultiBoundRoom *>((((FUN_006ab360_t*)*(void**)apRight)))->FUN_006ab360()));
    if (x > y)
    {
        return 1;
    }
    else
    {
        if (x < y)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

struct Form_58bd30
{
    virtual ~Form_58bd30();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    Form_58bd30();
};
struct Model_58bd30
{
    virtual ~Model_58bd30();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    Model_58bd30();
};
struct ISMForm_58bd30
{
    virtual void v00();
    unsigned int unk04;
    ISMForm_58bd30();
};
struct NodePtr_58bd30
{
    void* m_pObject;
    NodePtr_58bd30(void* object);
    ~NodePtr_58bd30();
    NodePtr_58bd30& operator=(void* object);
};
struct FUN_0058bd30 : Form_58bd30, Model_58bd30, ISMForm_58bd30
{
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    NodePtr_58bd30 node60;
    NodePtr_58bd30 node64;
    int unk68;
    NodePtr_58bd30 node6c;
    NodePtr_58bd30 node70;
    unsigned char unk74;
    bool unk75;
    bool unk76;
    FUN_0058bd30();
    virtual ~FUN_0058bd30();
};

// Initializes the form: sets form type 0x5b, calls Reset, clears the node pointers and unk68, and sets unk74 to 0xff with unk75/unk76 false.
// @fnv 0x0058bd30
FUN_0058bd30::FUN_0058bd30() : node60(0), node64(0), node6c(0), node70(0)
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x5b);
    reinterpret_cast<::BGSCameraShot *>(this)->ResetFormData();
    node60 = 0;
    node64 = 0;
    node6c = 0;
    unk68 = 0;
    node70 = 0;
    unk74 = 0xff;
    unk75 = false;
    unk76 = false;
}

struct FNVKeywordEntry
{
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
    unsigned char flag3;
    unsigned char flag4;
    char text[3];
};
extern FNVKeywordEntry DAT_0118cad0[16];
extern char DAT_0118cad5[];
struct FNVTokenParser
{
    int ParseToken(char** input, char* output, unsigned int* type, unsigned char countLeading,
                              int* leadingCount);
};
// @fnv 0x00593870
int FNVTokenParser::ParseToken(char** input, char* output, unsigned int* type, unsigned char countLeading,
                                          int* leadingCount)
{
    int size;
    char* pRead = *input;
    char* dest = output;
    bool beginning = true;
    char c;
    *type = 16;
    while (*pRead != 0 && *pRead < '!')
    {
        ++pRead;
        if (countLeading != 0 && leadingCount != 0)
            ++*leadingCount;
    }
    while (*pRead != 0)
    {
        c = *pRead;
        short id = *reinterpret_cast<short*>(pRead + 1);
        if (c == 'X' && id >= 0x1000 && id < 0x1280)
        {
            short length = *reinterpret_cast<short*>(pRead + 3);
            length += 5;
            memcpy(dest, pRead, length);
            dest += length;
            pRead += length;
            break;
        }
        else if (c == 's' || c == 'l' || c == 'f' || c == 'G' || c == 'Z' || c == 'r')
        {
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            if (c == 'r')
            {
                beginning = false;
            }
            else
            {
                break;
            }
        }
        else if (c == 'n')
        {
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            break;
        }
        else if (c == 'z')
        {
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            *dest = *pRead;
            ++dest;
            ++pRead;
            break;
        }
        else if (c == '"')
        {
            *dest = c;
            ++dest;
            ++pRead;
            while (*pRead != 0 && *pRead != '"')
            {
                *dest = *pRead;
                ++dest;
                ++pRead;
            }
            if (*pRead == '"')
            {
                *dest = *pRead;
                ++dest;
                ++pRead;
            }
            break;
        }
        else
        {
            if (c == ' ' || c == '\t')
                break;
            bool i = false;
            bool s = false;
            FNVKeywordEntry* a = DAT_0118cad0;
            unsigned int h;
            unsigned int p;
            for (h = 0; h < 16; ++h)
            {
                const char* keyword = a->text;
                i = true;
                for (p = 0; *keyword != 0; ++p)
                {
                    if (*keyword != pRead[p])
                    {
                        i = false;
                        break;
                    }
                    else
                    {
                        s = true;
                        ++keyword;
                    }
                }
                if (i)
                    break;
                ++a;
            }
            *type = h;
            if (i)
            {
                if (beginning)
                {
                    const char* matchedText = DAT_0118cad5 + *type * 8;
                    for (p = 0; *matchedText != 0; ++p)
                    {
                        *dest = *matchedText;
                        ++dest;
                        ++matchedText;
                        ++pRead;
                    }
                }
                else
                {
                    *type = 16;
                }
                break;
            }
            else if (s)
                reinterpret_cast<::Holder5934d0 *>(this)->SetError(5);
            *dest = c;
            ++dest;
            beginning = false;
            ++pRead;
        }
    }
    *dest = 0;
    *input = pRead;
    size = dest - output;
    return size;
}

class FUN_0058f960
{
  public:
    virtual ~FUN_0058f960();

};

class FUN_0058f900 : public FUN_0058f960
{
  public:
    virtual ~FUN_0058f900();
};
// Calls FUN_0058f900, then frees this object with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0058f850
void* FUN_0058f850_class::FUN_0058f850(unsigned int flags)
{
    reinterpret_cast<::FUN_0058f900 *>(this)->FUN_0058f900::~FUN_0058f900();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0058f900
FUN_0058f900::~FUN_0058f900()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

#include "generated/data/staging/blk_00580000_od.inc"
