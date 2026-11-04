
// src/staging/blk_00520000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/FNv53b450_Source.h"
#include "fnv/decl/FUN_00401210_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0044edd0_owner.h"
#include "fnv/decl/FUN_0044f420_class.h"
#include "fnv/decl/FUN_00453490_shell.h"
#include "fnv/decl/FUN_00454b90_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00474920_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b5020_shell.h"
#include "fnv/decl/FUN_004bc5f0_shell.h"
#include "fnv/decl/FUN_00516cd0_class.h"
#include "fnv/decl/FUN_00527fc0_cls.h"
#include "fnv/decl/FUN_005287e0_shell.h"
#include "fnv/decl/FUN_00528870_shell.h"
#include "fnv/decl/FUN_0052d240_shell.h"
#include "fnv/decl/FUN_00534050_Class.h"
#include "fnv/decl/FUN_00534080_Class.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006665a0_shell.h"
#include "fnv/decl/FUN_006ebde0_shell.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00906570_Class.h"
#include "fnv/decl/InventoryIterOwner.h"
#include "fnv/decl/LandObject.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/SaveLoadCallerShell.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/VertOwner.h"
#include "fnv/decl/fnv_00528ce0__FUN_00528ce0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_0044e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01202000.h"
#include "../../include/layout_support.h"

struct FUN_005224c0_Class
{
    char pad[0x22c];
    unsigned int unk22c;
    unsigned int GetField22C();
};

// @fnv 0x005224c0
unsigned int FUN_005224c0_Class::GetField22C()
{
    return unk22c;
}

struct FUN_005224e0_class
{
    char pad[0x230];
    unsigned int unk230;
    unsigned int GetField230();
};

// @fnv 0x005224e0
unsigned int FUN_005224e0_class::GetField230()
{
    return unk230;
}

struct FUN_00524b40_class
{
    char pad[0x100];
    unsigned char unk100;
    bool FUN_00524b40();
};

// @fnv 0x00524b40
bool FUN_00524b40_class::FUN_00524b40()
{
    return unk100 & 2;
}

struct FUN_00526ae0_class
{
    char pad[0x28];
    float unk28;
    float FUN_00526ae0() const;
};

// @fnv 0x00526ae0
float FUN_00526ae0_class::FUN_00526ae0() const
{
    return unk28;
}

struct FUN_00527740_class
{
    char pad[0xc];
    int unk0c;
    int unk10;
    char unk14;
    void FUN_00527740();
};

// Clears the int fields at offsets 0x0c and 0x10 and the byte at 0x14 of this object to zero.
// @fnv 0x00527740
void FUN_00527740_class::FUN_00527740()
{
    unk0c = 0;
    unk10 = 0;
    unk14 = 0;
}

struct BSTreeNode;
struct TESObjectREFR;

template <class Key, class Node> struct LockFreeMap
{
    LockFreeMap(unsigned int a, unsigned int b, unsigned int c);
};

struct FUN_00527e30
{
    LockFreeMap<TESObjectREFR*, BSTreeNode*> m;
    FUN_00527e30();
};

// @fnv 0x00527e30
FUN_00527e30::FUN_00527e30() : m(2, 0x25, 0xc)
{}

struct TESQueuedCellManager
{
    void FUN_00528540();
};

// @fnv 0x00528540
void TESQueuedCellManager::FUN_00528540()
{
    reinterpret_cast<::FUN_00527fc0_cls *>(this)->SubmitQueuedItems();
}


struct FUN_0052a980_Class
{
    int FUN_0052a980(char* dst);
};

// @fnv 0x0052a980
int FUN_0052a980_Class::FUN_0052a980(char* pcBuffer)
{
    return ::FUN_00406d00(pcBuffer, 0x800, "  Temp");
}

struct FUN_0052d180_cls
{
    void FUN_0052d180();
};

void FUN_0052d180_cls::FUN_0052d180()
{}

struct FUN_0052d160_cls
{
    void* FUN_0052d160();
};

// @fnv 0x0052d160
void* FUN_0052d160_cls::FUN_0052d160()
{
    ((FUN_0052d180_cls*)this)->FUN_0052d180();
    return this;
}

struct NiBound
{
    NiBound();
};

NiBound::NiBound()
{}

struct FUN_0052d200
{
    NiBound b;
    FUN_0052d200();
};

// @fnv 0x0052d200
FUN_0052d200::FUN_0052d200()
{}

struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
};

struct FUN_0052d220_obj : public FUN_0052d240_obj
{
    void DestroyBase();
};

// @fnv 0x0052d220
void FUN_0052d220_obj::DestroyBase()
{
    reinterpret_cast<::FUN_0052d240_shell *>(this)->FUN_0052d240();
}

struct NiObjectNET
{
    void FUN_00439360(unsigned short a, unsigned int b, unsigned int c);
    void FUN_00533fb0(unsigned short a);
};

// @fnv 0x00533fb0
void NiObjectNET::FUN_00533fb0(unsigned short a)
{
    FUN_00439360(a, 0xe, 1);
}

struct FUN_008256d0_shell_base
{
    bool FUN_008256d0();
};
struct FUN_00537b50_shell
{
    char pad[0xac];
    FUN_008256d0_shell_base unkac;
    bool FUN_00537b50();
};
// Returns the negation of the result of calling FUN_008256d0 on the object at this+0xac.
// @fnv 0x00537b50
bool FUN_00537b50_shell::FUN_00537b50()
{
    return !unkac.FUN_008256d0();
}

struct Base537
{
    Base537* FUN_00537b80();
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    float m_iThirdValue;
};

struct GO
{
    GO& operator=(void*);
};

struct FUN_00539f20_Class
{
    char pad[0xd0];
    GO m;
    void FUN_00539f20(void*);
};

// @fnv 0x00539f20
void FUN_00539f20_Class::FUN_00539f20(void* p)
{
    m.operator=(p);
}

extern void* DAT_0102cfa0;

struct FUN_005278a0
{
    void* vtbl;
    void* a;
    void* b;
    void DoIt();
};

// Sets the vtable to DAT_0102cfa0, clears the map via RemoveAll, then frees b with NiFreeAlias.
// @fnv 0x005278a0
void FUN_005278a0::DoIt()
{
    vtbl = &DAT_0102cfa0;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(b);
}


struct FUN_005289b0_Class
{
    int m_field00;
    int m_field04;
    int m_field08;
    int m_field0c;
    void FUN_005289b0(void* p);
};

// Loops calling FUN_0040fca0(0) while the object's m_field0c is 3 or 5.
// @fnv 0x005289b0
void FUN_005289b0_Class::FUN_005289b0(void* pObject)
{
    while (((FUN_005289b0_Class*)pObject)->m_field0c == 3 || ((FUN_005289b0_Class*)pObject)->m_field0c == 5)
        FUN_0040fca0(0);
}

struct FUN_00526ef0_Class
{
    void* Destroy(unsigned int flags);
};
struct FUN_005277a0_Class
{
    void FUN_00527840();
    void* FUN_005277a0(unsigned int flags);
};

struct FUN_00528be0_Class
{
    void FUN_00528be0();
};
struct FUN_00528e10_Class
{
    void* FUN_00528e10(unsigned int flags);
};
// @fnv 0x00528e10
void* FUN_00528e10_Class::FUN_00528e10(unsigned int flags)
{
    ((FUN_00528be0_Class*)this)->FUN_00528be0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00529330_Class
{
};
struct FUN_00529300_Class
{
    void* FUN_00529300(unsigned int flags);
};
struct FUN_005293c0_Class
{
    void* FUN_005293c0(unsigned int flags);
};
// @fnv 0x005293c0
void* FUN_005293c0_Class::FUN_005293c0(unsigned int flags)
{
    reinterpret_cast<::FUN_0044f420_class *>(this)->FUN_0044f420();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct GameTimerRecord
{
};
struct TESSound
{
};
struct MapH
{
};
struct FUN_00526c40_Class
{
    char pad[0x10];
    unsigned int unk10;
    int unk14;
    bool RemoveSound(TESSound*);
};
// @fnv 0x00526c40
bool FUN_00526c40_Class::RemoveSound(TESSound* apSound)
{
    if (reinterpret_cast<::NiTMap_S *>((((MapH*)this)))->RemoveKey(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apSound))->FUN_0084e3a0()))))
    {
        --unk10;
        unk14 = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(g_timeGlobal))->FUN_00825c00()));
        return true;
    }
    return false;
}

struct BGSLoadedReferenceCollection;
// @fnv 0x00526eb0
void FUN_00526eb0()
{
    FUN_00526ef0_Class* b;
    FUN_00526ef0_Class* a;
    void* c;
    b = (FUN_00526ef0_Class*)::DAT_011c95c8;
    a = b;
    if (a)
        c = a->Destroy(1);
    else
        c = 0;
    ::DAT_011c95c8 = 0;
}

struct FUN_005271b0_Class
{
    char m_auiShapeKeys[0x48];
    char m_field48;
    char m_field70;
    char* GetFieldByType(uintptr_t type);
};

// Returns a pointer to the member at offset 0x48 for type 0x29 or at offset 0x30 for type 0x28, otherwise null.
// @fnv 0x005271b0
char* FUN_005271b0_Class::GetFieldByType(uintptr_t type)
{
    switch (type)
    {
    case 0x29:
        return (char*)&this->m_field48;
    case 0x28:
        return (char*)&this->m_auiShapeKeys[48];
    default:
        return 0;
    }
}

struct InventoryStackRecord
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    InventoryStackRecord();
};
struct FUN_00527270 : public InventoryStackRecord
{
    int m_iThirdValue;
    int m_10;
    unsigned char m_14;
    FUN_00527270();
};
// @fnv 0x00527270
FUN_00527270::FUN_00527270()
{
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

namespace fnv_00527350 {
struct BGSLoadedReferenceCollection;
struct MapX
{
};
struct ScriptS
{
};
struct FUN_005271b0_Class
{
};
struct FUN_00527350
{
    void* vtbl;
    int f4;
    int f8;
    void* fc;
    int f10;
    int f14;
    void* f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    char f34;
    void FUN_00527350_Init();
};
// Clears f10, f14 and f34, resolves fc from DAT_011c95c8 (falling back to GetHeader), then stores GetFirstPos() into f18.
// @fnv 0x00527350
void FUN_00527350::FUN_00527350_Init()
{
    f10 = 0;
    f14 = 0;
    f34 = 0;
    fc = ((void *)(reinterpret_cast<::FUN_005271b0_Class *>((((FUN_005271b0_Class*)(*reinterpret_cast<::fnv_00527350::BGSLoadedReferenceCollection * *>(&::DAT_011c95c8)))))->GetFieldByType((uintptr_t)(vtbl))));
    if (!fc)
        fc = ((void *)(reinterpret_cast<::BGSCameraPath *>((((ScriptS*)(*reinterpret_cast<::fnv_00527350::BGSLoadedReferenceCollection * *>(&::DAT_011c95c8)))))->GetConditions()));
    f18 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)fc)))->GetFirstPos();
}
}  // namespace fnv_00527350

struct FUN_005277d0_Class
{
    void* vtbl;
    unsigned int size;
    void* data;
    void* next;
    FUN_005277d0_Class* InitBuffer(unsigned int size);
};
// Sets the vtable, stores size, clears next, allocates size*4 bytes with NiMalloc, zeroes them, and returns this.
// @fnv 0x005277d0
FUN_005277d0_Class* FUN_005277d0_Class::InitBuffer(unsigned int size)
{
    vtbl = &DAT_0102cfa0;
    this->size = size;
    next = 0;
    unsigned int uiByteCount = this->size * 4;
    data = ::FUN_00aa1070(uiByteCount);
    ::FUN_00403d30(data, 0, this->size * 4);
    return this;
}

struct FUN_005278d0_Class
{
    void* FUN_005278d0(unsigned int flags);
};
// Calls DoIt on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x005278d0
void* FUN_005278d0_Class::FUN_005278d0(unsigned int flags)
{
    ((FUN_005278a0*)this)->DoIt();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct IOTask
{
    virtual void Dummy();
    IOTask(int a);
    char _pad[20];
};
struct FUN_00527c00 : public IOTask
{
    int m_18;
    int m_1c;
    FUN_00527c00(int a, int b);
};
// Initializes the IOTask base with 0 and stores the two constructor arguments into m_18 and m_1c.
// @fnv 0x00527c00
FUN_00527c00::FUN_00527c00(int aiValue18, int aiValue1c) : IOTask(0)
{
    m_18 = aiValue18;
    m_1c = aiValue1c;
}

struct Caller27f90
{
    void* FUN_00527f90(unsigned int flags);
};
// If the global TESQueuedCellManager exists, calls its FUN_00527f90 with flags 1 and clears the global pointer.
// @fnv 0x00527f40
void __cdecl FUN_00527f40()
{
    TESQueuedCellManager* pManager;
    TESQueuedCellManager* pManagerCopy;
    if (::DAT_011c9618)
    {
        void* r;
        pManager = ::DAT_011c9618;
        pManagerCopy = pManager;
        if (pManagerCopy)
            r = ((Caller27f90*)pManagerCopy)->FUN_00527f90(1);
        else
            r = 0;
        ::DAT_011c9618 = 0;
    }
}

struct FUN_00527f90_Holder
{
    void FUN_00527e50();
    void* FUN_00527f90(unsigned int);
};
struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};
struct FUN_00449f80_Class
{
    void* FUN_00449f80(void* a, void* b, unsigned char c);
};
struct FUN_0044c000_Class
{
    unsigned char FUN_0044c000();
};
struct FUN_00528b60_Class
{
    char pad[0x20];
    RecursiveSpinLock unk20;
    unsigned char LockedCall(void* a, void* b, unsigned char c);
};
// Locks the object at offset 0x20, calls FUN_00449f80 then FUN_0044c000 on its result, unlocks, and returns that result.
// @fnv 0x00528b60
unsigned char FUN_00528b60_Class::LockedCall(void* a, void* b, unsigned char c)
{
    unsigned char r;
    reinterpret_cast<::FUN_0040fbf0_shell *>(((&unk20)))->FUN_0040fbf0((char *)(0));
    r = ((FUN_0044c000_Class*)((FUN_00449f80_Class*)this)->FUN_00449f80(a, b, c))->FUN_0044c000();
    unk20.FUN_0040fba0();
    return r;
}

extern int DAT_0102d078;
struct FUN_00528c70_Class
{
    void* vtbl;
    int m_kPointA;
    int m_kPointB;
    char m_iThirdValue;
    FUN_00528c70_Class();
};
// Initializes the object's vtable pointer and zeroes its three data members.
// @fnv 0x00528c70
FUN_00528c70_Class::FUN_00528c70_Class()
{
    vtbl = &DAT_0102d078;
    m_kPointA = 0;
    m_kPointB = 0;
    m_iThirdValue = 0;
}

struct FUN_0052cfc0_Rect
{
    int v0;
    int v1;
    int v2;
    int v3;
};
struct FUN_0052cfc0_Class
{
    int pad;
    FUN_0052cfc0_Rect rect;
    void FUN_0052cfc0(FUN_0052cfc0_Rect* p);
};
// Copies the four ints of the passed rect into this object's rect field.
// @fnv 0x0052cfc0
void FUN_0052cfc0_Class::FUN_0052cfc0(FUN_0052cfc0_Rect* apRect)
{
    rect = *apRect;
}

template <int N> struct EndianSizeTag
{
};


struct FUN_00535aa0_Class
{
    unsigned short unk00;
    char pad02[0x2];
    unsigned int unk04;
    void FUN_00535aa0();
};

// @fnv 0x00535aa0
void FUN_00535aa0_Class::FUN_00535aa0()
{
    ::FUN_00407a90((short *)&unk00);
    ::FUN_00401080((int *)&unk04);
}

struct CallCls537
{
};
struct Cl537
{
    int m_iWordAt00;
    int m_iWordAt04;
    Cl537* FUN_00537bb0();
};
// @fnv 0x00537b80
Base537* Base537::FUN_00537b80()
{
    reinterpret_cast<::Cl537 *>(this)->FUN_00537bb0();
    m_8 = 0;
    m_iThirdValue = 1.0f;
    return this;
}
// @fnv 0x00537bb0
Cl537* Cl537::FUN_00537bb0()
{
    reinterpret_cast<::FUN_004b5020_shell *>((((CallCls537*)this)))->FUN_004b5020();
    m_iWordAt04 = 0;
    return this;
}

struct FUN_00527e30_Alloc
{
    char m[0x40];
    FUN_00527e30_Alloc();
};
// @fnv 0x00527eb0
void __cdecl InitQueuedCellManager()
{
    if (!::DAT_011c9618)
        ::DAT_011c9618 = (TESQueuedCellManager*)new FUN_00527e30_Alloc;
}

struct FUN_005285c0_Node
{
    void* unk00;
    void* unk04;
    void* unk08;
    int unk0c;
    char unk10;
};

struct FUN_005285c0_Class
{
    void* FUN_005285c0(void* a, void* b, void* c);
};
// Allocates a 0x14-byte object storing a, b and c in its first three fields, zeroing the byte at 0x10 and the int at 0xC, and returns it or null if a is null.
// @fnv 0x005285c0
void* FUN_005285c0_Class::FUN_005285c0(void* a, void* b, void* c)
{
    void* p = 0;
    if (a)
    {
        void* t = ::FUN_00401000(sizeof(FUN_005285c0_Node));
        p = t;
        FUN_005285c0_Node* node = static_cast<FUN_005285c0_Node*>(p);
        node->unk08 = a;
        node->unk00 = b;
        node->unk04 = c;
        node->unk10 = 0;
        node->unk0c = 0;
    }
    return p;
}

extern unsigned int _data_011c16bc;

struct AutoMemHelper
{
    int m_auiShapeKeys;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};

struct FUN_00526c90
{
    unsigned char m_auiShapeKeys[0xc0];
    FUN_00526c90();
};


// @fnv 0x00526e10
void FUN_00526e10()
{
    AutoMemHelper context(
        0x2c, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSLoadedReferenceCollection.cpp", 0x58);

    ::DAT_011c95c8 = reinterpret_cast<BGSLoadedReferenceCollection*>(new FUN_00526c90);
}

struct FUN_005272b0_ItemChange
{
};

struct FUN_005272b0_Class
{
    void ClearAndDestroy();
};

// @fnv 0x005272b0
void FUN_005272b0_Class::ClearAndDestroy()
{
    *(void**)this = 0;
    reinterpret_cast<::FUN_004bc5f0_shell *>((reinterpret_cast<FUN_005272b0_ItemChange*>(this)))->FUN_004bc5f0();
}

struct FUN_005285a0_Class
{
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
    virtual void CallVirtual17();
};
// @fnv 0x005285a0
void FUN_005285a0_Class::CallVirtual17()
{
    ((void(*)(void*))(*(void***)this)[17])(this);
}

class Sub24_b5481
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    ~Sub24_b5481();
};

class FUN_00526d50_cls
{
  public:
    Sub24_b5481 m_00;
    Sub24_b5481 m_18;
    Sub24_b5481 m_30;
    Sub24_b5481 m_48;
    Sub24_b5481 m_60;
    Sub24_b5481 m_78;
    Sub24_b5481 m_90;
    Sub24_b5481 m_a8;
    ~FUN_00526d50_cls();
};
// Calls FUN_00526d50, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00526ef0
void* FUN_00526ef0_Class::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00526d50_cls *>(this)->FUN_00526d50_cls::~FUN_00526d50_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor for the class; destroys its eight Sub24_b5481 members in reverse order.
// @fnv 0x00526d50
FUN_00526d50_cls::~FUN_00526d50_cls()
{}

struct C5271F0Change
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char unk14;
    C5271F0Change();
    ~C5271F0Change();
};

struct FUN_005271f0
{
    int m_iOwner;
    int m_iArrayLength;
    int m_iType;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C5271F0Change m_kChange;
    FUN_005271f0(int owner, int type);
};

// @fnv 0x005271f0
FUN_005271f0::FUN_005271f0(int owner, int type) : m_iOwner(owner), m_iArrayLength(0), m_iType(type)
{
    reinterpret_cast<::fnv_00527350::FUN_00527350 *>(this)->FUN_00527350_Init();
}

// The game object whose byte at +4 is read by FUN_00401170 (a plain
// member of the game's own shell class, so a stand-in with the same shape is
// enough: the call is ECX-based and its result is a plain int).
struct FNV_FormType
{
    unsigned char unk04;
    int GetFormType();
};

// The sub-object that lives at +0x1c of the complete object.  It owns a
// non-trivial destructor, which is what gives the constructor its exception
// frame and the single state transition (0 -> -1) around the body.
struct FNV_Sub5272d0
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    unsigned char m_14;
    FNV_Sub5272d0();
    ~FNV_Sub5272d0();
};

struct FUN_005272d0_Class
{
    int m_00;
    FNV_FormType* m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    FNV_Sub5272d0 m_1c;
    unsigned char m_34;
    ~FUN_005272d0_Class();
    FUN_005272d0_Class(FNV_FormType* p, int q);
    void FUN_00527350();
};

// Constructor initializes m_00 from p->GetFormType(), stores p and q, then calls FUN_00527350.
// @fnv 0x005272d0
FUN_005272d0_Class::FUN_005272d0_Class(FNV_FormType* apForm, int q) : m_00(apForm->GetFormType()), m_04(apForm), m_08(q)
{
    reinterpret_cast<::fnv_00527350::FUN_00527350 *>(this)->FUN_00527350_Init();
}

class Base_b9015
{
  public:
    virtual ~Base_b9015();
    unsigned int unk04;
    unsigned int unk08;
};

class Cleanup_b9015
{
  public:
    void Cleanup();
};

class FUN_00527840 : public Base_b9015
{
  public:
    virtual ~FUN_00527840();
};
// Calls FUN_00527840, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x005277a0
void* FUN_005277a0_Class::FUN_005277a0(unsigned int flags)
{
    reinterpret_cast<::FUN_00527840 *>(this)->FUN_00527840::~FUN_00527840();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor for FUN_00527840 that calls DoCleanup().
// @fnv 0x00527840
FUN_00527840::~FUN_00527840()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_00528be0
{
    ~FUN_00528be0();
};

struct FUN_00527e50 : FUN_00528be0
{
    ~FUN_00527e50();
};
// Calls FUN_00527e50, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00527f90
void* FUN_00527f90_Holder::FUN_00527f90(unsigned int flags)
{
    reinterpret_cast<::FUN_00527e50 *>(this)->FUN_00527e50::~FUN_00527e50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00527e50
FUN_00527e50::~FUN_00527e50()
{
    reinterpret_cast<::FUN_00527fc0_cls *>(this)->SubmitQueuedItems();
}

struct FUN_005287e0_Class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct Query
{
    void* vtbl;
    int m_kPointA;
    int m_kPointB;
    char m_iThirdValue;
    Query();
    ~Query();
};
struct Handle
{
    FUN_005287e0_Class* value;
    Handle(int);
    ~Handle();
};
struct Controller
{
    void ProcessQueries();
};
// Loops over queries until one finishes, and for each successful query whose handle value passes a check, calls its v5 method.
// @fnv 0x00528110
void Controller::ProcessQueries()
{
    Query query;
    while (!((unsigned char)(reinterpret_cast<::FUN_006ebde0_shell *>(&(query))->FUN_006ebde0())))
    {
        unsigned int x = 0;
        Handle y(0);
        if (((unsigned char)(reinterpret_cast<::FUN_00906570_Class *>(this)->AdvanceRequest((::Request9065 *)(::Query *)(&query), (void **)(unsigned int *)(&x), &y, 1))))
        {
            if (((unsigned char)(reinterpret_cast<::FUN_005287e0_shell *>((((::FUN_005287e0_Class *)(::FUN_00559450((int *)&(y))))))->FUN_005287e0())))
            {
                ((::FUN_005287e0_Class *)(::FUN_00559450((int *)&(y))))->v5();
            }
        }
    }
}

struct Holder_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct Local_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Local_cls();
    ~Local_cls();
};

struct Obj20_cls
{
    int m_00;
    Obj20_cls(int a);
    ~Obj20_cls();
};


struct FUN_005282d0_cls
{
    void FUN_005282d0();
};

// @fnv 0x005282d0
void FUN_005282d0_cls::FUN_005282d0()
{
    Local_cls a;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(a))->FUN_006ebde0())
    {
        int b = 0;
        Obj20_cls o4(0);
        if (reinterpret_cast<::FUN_00906570_Class *>(this)->AdvanceRequest((::Request9065 *)(::Local_cls *)(&a), (void **)(int *)(&b), &o4, 1))
        {
            (*reinterpret_cast<::FUN_005289b0_Class * *>(&::DAT_01202d98))->FUN_005289b0(((::Holder_cls *)(::FUN_00559450((int *)&(o4)))));
            if (reinterpret_cast<::FUN_005287e0_shell *>((((::Holder_cls *)(::FUN_00559450((int *)&(o4))))))->FUN_005287e0())
            {
                ((::Holder_cls *)(::FUN_00559450((int *)&(o4))))->v5();
            }
        }
    }
}

namespace fnv_005283c0 {
struct TESObjectCELL;

struct QWorldSpace
{
};

class TES
{
  public:
};

struct QIOTask
{
    virtual void v0();
    QIOTask(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct QCellTask : public QIOTask
{
    intptr_t m_18;
    intptr_t m_1c;
    QCellTask(intptr_t a, intptr_t b);
};

struct QTaskPtr
{
    QIOTask* p;
    QTaskPtr(QIOTask* t);
    ~QTaskPtr();
    operator QIOTask*() const;
};

class IOManager
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void AddTask(QIOTask* task);
};


struct QCellQueue
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Insert(int key, QTaskPtr* ptr, int flag);
    void FUN_005283c0(QWorldSpace* ws, intptr_t x, intptr_t y);
};

// @fnv 0x005283c0
void QCellQueue::FUN_005283c0(QWorldSpace* ws, intptr_t x, intptr_t y)
{
    if (!ws)
        return;
    TESObjectCELL* cellVal = ((::fnv_005283c0::TESObjectCELL *)(reinterpret_cast<::TESWorldSpace *>((ws))->GetCellAtGridPosition(x, y)));
    if (cellVal && reinterpret_cast<::FUN_00453490_shell *>(((*reinterpret_cast<::fnv_005283c0::TES * *>(&::g_TES))))->FUN_00453490((::TESObjectCELL *)(cellVal)))
    {
        reinterpret_cast<::FUN_00454b90_shell *>(((*reinterpret_cast<::fnv_005283c0::TES * *>(&::g_TES))))->AddCellToBuffer((::TESObjectCELL *)(cellVal));
        return;
    }
    if (reinterpret_cast<::SaveLoadCallerShell *>(this)->CallSaveLoadWithHandle(x, y))
        return;
    void* entry7 = reinterpret_cast<::FUN_005285c0_Class *>(this)->FUN_005285c0(ws, (void *)(x), (void *)(y));
    if (entry7)
    {
        QTaskPtr ptr(new QCellTask((intptr_t)this, (intptr_t)entry7));
        int key = ::PackShortPair((unsigned short)x, (unsigned short)y);
        bool ok6 = Insert(key, &ptr, 1);
        (*reinterpret_cast<::fnv_005283c0::IOManager * *>(&::DAT_01202d98))->AddTask(ptr);
    }
}
}  // namespace fnv_005283c0


class AutoMemContext
{
  public:
    int unk00;
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pFile, int iLine);
    ~AutoMemContext();
};

struct QueuedRefPtr
{
    void* p;
    QueuedRefPtr& operator=(void* rhs);
};

struct NodeLink
{
    void* p;
    void Clear();
};

struct QueuedNode
{
    int unk00;
    QueuedRefPtr ref;
    NodeLink next;
};

struct QueuedOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    QueuedOwner(int data);
    ~QueuedOwner();
};

struct QueuedMap
{
    int unk00;
    int unk04;
    unsigned int bucketCount;
    NodeLink* buckets;
    int unk10;
    QueuedOwner* owner;
    int count;
    int unk1C;
    RecursiveSpinLock lock;
    void FUN_00528e40(bool abFreeNodes);
};

// Under a task-overhead memory context, locks the map, deletes the owner, frees all bucket nodes, and optionally recreates the owner with the saved data.
// @fnv 0x00528e40
void QueuedMap::FUN_00528e40(bool abFreeNodes)
{
    AutoMemContext kMemContext(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true, kThreadSafeStructuresSourceFile, 0x42c);
    if (owner == 0)
        return;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    int data = ::FUN_00559450((int *)(owner));
    delete owner;
    owner = 0;
    count = 0;
    for (unsigned int i = 0; i < bucketCount; i++)
    {
        QueuedNode* node = (QueuedNode*)(intptr_t)::ClearLowBit((int *)&(buckets[i]));
        reinterpret_cast<::FUN_006665a0_shell *>(&(buckets[i]))->FUN_006665a0();
        while (node)
        {
            QueuedNode* nextNode = (QueuedNode*)(intptr_t)::ClearLowBit((int *)&(node->next));
            reinterpret_cast<::FUN_006665a0_shell *>(&(node->next))->FUN_006665a0();
            reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::QueuedRefPtr &)(node->ref))->FUN_006f74f0((::ObjA *)(void *)(0));
            reinterpret_cast<::FUN_0044edd0_owner *>(this)->DispatchAndDelete((::FUN_0044edd0_Disposable *)(node));
            node = nextNode;
        }
    }
    if (!abFreeNodes)
        owner = new QueuedOwner(data);
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
}

struct FloatSettings
{
    unsigned int field_00;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
    unsigned int field_10;
    unsigned int field_14;
    float field_18;
    float field_1c;
    float field_20;
    float field_24;
    float field_28;
    float field_2c;
    float field_30;
    float field_34;
    float field_38;
    float field_3c;
    float field_40;
    float field_44;
    float field_48;
    float field_4c;
    float field_50;
    float field_54;
    float field_58;
    float field_5c;
    float field_60;
    float field_64;
    float field_68;
    float field_6c;
    float field_70;
    float field_74;
    float field_78;
    float field_7c;
    float field_80;
    float field_84;
    float field_88;
    float field_8c;
    float field_90;
    float field_94;
    float field_98;
    void InitDefaults();
};
// Assigns a fixed set of float constants to the fields from field_18 through field_98.
// @fnv 0x0052b780
void FloatSettings::InitDefaults()
{
    field_18 = 0.5f;
    field_1c = 7.0f;
    field_24 = 1.0f;
    field_28 = 1.0f;
    field_2c = 1.0f;
    field_30 = 2.25f;
    field_34 = 0.22499999404f;
    field_38 = 1.0f;
    field_3c = 0.0f;
    field_40 = 0.0f;
    field_44 = 1.5f;
    field_48 = 1.5f;
    field_4c = 1.0f;
    field_20 = 1.0f;
    field_54 = 0.0299999993294f;
    field_5c = 0.20000000298f;
    field_58 = 0.699999988079f;
    field_60 = 0.5f;
    field_64 = 0.5f;
    field_68 = 0.019999999553f;
    field_78 = 2.5f;
    field_6c = 0.209999993443f;
    field_70 = 0.5f;
    field_74 = 0.77999997139f;
    field_88 = 1.0f;
    field_80 = 0.5f;
    field_84 = 1.0f;
    field_7c = 1.0f;
    field_98 = 0.0f;
    field_8c = 1.0f;
    field_90 = 1.0f;
    field_94 = 1.0f;
}

class FUN_00537bf0_base
{
  public:
    virtual ~FUN_00537bf0_base();
    FUN_00537bf0_base();
};

class FUN_00537bf0_sub
{
  public:
    FUN_00537bf0_sub(int a, int b);
    ~FUN_00537bf0_sub();
    unsigned int m_unk00;
    unsigned int m_unk04;
};

class FUN_00537bf0 : public FUN_00537bf0_base
{
  public:
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned short m_iOwnerObjectOffset;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    FUN_00537bf0_sub m_sub;
    FUN_00537bf0(unsigned short id);
    virtual ~FUN_00537bf0();
};

// @fnv 0x00537bf0
FUN_00537bf0::FUN_00537bf0(unsigned short id) : m_sub(0, 1)
{
    m_unk08 = 0;
    m_iOwnerObjectOffset = id;
    m_unk10 = 0;
    m_unk14 = 0;
    ::FUN_005e03d0((::NiTArray_Layout *)&(m_sub));
    m_unk18 = 0;
}

// FUN_00539f40 : returns the VALUE of a global (mov eax,[0x11f94bc]).
// The module is unoptimised, so the frame is kept even with no locals.

// @fnv 0x00539f40
int __cdecl FUN_00539f40()
{
    return g_00539f40;
}

namespace fnv_00526c90 {
struct C90List
{
    C90List();
    ~C90List();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct FUN_00526c90
{
    FUN_00526c90();

    C90List m_kList0;
    C90List m_kList1;
    C90List m_kList2;
    C90List m_kList3;
    C90List m_kList4;
    C90List m_kList5;
    C90List m_kList6;
    C90List m_kList7;
};

// Default constructor; the eight C90List members are constructed implicitly.
// @fnv 0x00526c90
FUN_00526c90::FUN_00526c90()
{}
}  // namespace fnv_00526c90

struct Ref;
struct Form;
struct Changes;
struct Form
{
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
    virtual bool IsSpecial();
    int FNV_GetFormType();
};
struct Ref
{
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
    virtual bool IsExcluded();
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
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool IsActor(int);
};
struct Changes
{
};
struct EntryState
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
};
struct Entries
{
};
struct Map
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
};
struct State
{
    int type;
    Form* filter;
    void* context;
    Map* map;
    Ref* current;
    Entries* entries;
    void* pos;
    EntryState state;
    unsigned char stage;
};
struct Collection
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    Map first;
    Map second;
    Map third;
    Map fourth;
    Map fifth;
    bool FindNextRef(State*, Ref**, Ref**, unsigned int);
};
// Walks the collection's maps by stage and flags, skipping disabled, deleted, excluded or filtered refs, and returns the next matching ref and its item.
// @fnv 0x005273c0
bool Collection::FindNextRef(State* state, Ref** result, Ref** item, unsigned int flags)
{
    while (state->map)
    {
        if (state->current)
        {
            Ref* entry7 = 0;
            while (reinterpret_cast<::InventoryIterOwner *>((state->entries))->AdvanceInventoryIterator((::IterState *)(::EntryState *)(&state->state), (void **)(::Ref **)(&entry7), 1))
            {
                if (state->filter)
                {
                    if (((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry7))->GetName())) != state->filter)
                        continue;
                }
                else
                {
                    if (((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry7))->GetName()))->FNV_GetFormType() != state->type)
                        continue;
                }
                if (!reinterpret_cast<::Callees *>((entry7))->FUN_00726070())
                    continue;
                *result = state->current;
                *item = entry7;
                return true;
            }
            reinterpret_cast<::FUN_00527740_class *>(&(state->state))->FUN_00527740();
            state->entries = 0;
            state->current = 0;
        }
        while (!state->pos)
        {
            switch (state->stage)
            {
            case 0:
                if (flags & 1)
                    state->map = &fourth;
                break;
            case 1:
                if (flags & 6)
                    state->map = &fifth;
                break;
            case 2:
                state->map = 0;
                return false;
            }
            state->stage++;
            if (state->map)
                state->pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((state->map))->GetFirstPos();
        }
        bool tempSwap6 = state->stage > 0;
        bool container7 = true;
        if (state->map == &first)
            container7 = false;
        while (state->pos)
        {
            unsigned int key = 0;
            Ref* ref = 0;
            reinterpret_cast<::C6b7f20_Map *>((state->map))->FUN_006b7f20((::C6b7f20_Node **)&(state->pos), (unsigned int *)&(key), (void **)&(ref));
            if (reinterpret_cast<::TESForm *>((ref))->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((ref))->FUN_00440d80())
                continue;
            if (ref->IsExcluded() || ((::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->IsSpecial())
                continue;
            if (reinterpret_cast<::FUN_00401210_shell *>((ref))->HasFlag() && !(flags & 8))
                continue;
            if (!tempSwap6)
            {
                if (state->filter)
                {
                    if (state->filter != ((::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())))
                        continue;
                }
                else if (!container7)
                {
                    if (state->type != ((::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FNV_GetFormType())
                        continue;
                }
                *result = ref;
                *item = 0;
                return true;
            }
            else
            {
                if (state->map == &fifth)
                {
                    bool actors = (flags & 2) ? true : false;
                    bool others = (flags & 4) ? true : false;
                    if (actors != others)
                    {
                        if (ref->IsActor(0) == !actors)
                            continue;
                    }
                }
                else if (((::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->FNV_GetFormType() == 0x1b)
                {
                    Form* baseTmp = ((::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
                    if (!reinterpret_cast<::FUN_00516cd0_class *>((baseTmp))->CanUseLockedRef((::TESObjectREFR *)(ref), (::Actor *)(state->context), 0))
                        continue;
                }
                state->entries = ((::Entries *)(reinterpret_cast<::ExtraDataList *>((((::Changes *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()))))->GetContainerChangeData()));
                if (state->entries)
                    state->current = ref;
                break;
            }
        }
    }
    return false;
}


struct ArrayItem
{
    int m_iWordAt00;
    void* m_iWordAt04;
};

struct ElemCls
{
};

struct Cls
{
    void* m_iWordAt00;
    unsigned long m_iWordAt04;
    ArrayItem* m_8;
    void FUN_00529330();
};
// Calls FUN_00529330 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00529300
void* FUN_00529300_Class::FUN_00529300(unsigned int flags)
{
    reinterpret_cast<::Cls *>((((FUN_00529330_Class*)this)))->FUN_00529330();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00529330
void Cls::FUN_00529330()
{
    unsigned int i = 0;
    for (; i < ((unsigned int)(::FUN_00559450((int *)(this)))); ++i)
    {
        void* t = this->m_8[i].m_iWordAt04;
        void* t2 = t;
        t2 ? reinterpret_cast<::FUN_005293c0_Class *>((((ElemCls*)t2)))->FUN_005293c0(1) : 0;
    }
    {
        void* p = this->m_8;
        ::FUN_00401030(p);
    }
    ::FUN_0044e360(this->m_iWordAt04);
}

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
    NiPoint3 operator+(const NiPoint3&) const;
    NiPoint3 operator*(float) const;
    bool FUN_004390c0(const NiPoint3&);
    NiPoint3& Subtract(const NiPoint3&);
public:
    ::NiPoint3 CrossProduct(const ::NiPoint3 &) const;
};
NiPoint3 operator*(float, const NiPoint3&);
struct TerrainInput
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int region;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    unsigned int position, edgeA, u, c;
    bool flipA, flipB;
};
struct TerrainOwner
{
    bool ComputeTerrainNormalAndTangent(TerrainInput*, NiPoint3*, NiPoint3*);
};
// Computes a terrain normal and tangent at input->position, blending edge/u/c samples by flip flags, and returns true.
// @fnv 0x0053caf0
bool TerrainOwner::ComputeTerrainNormalAndTangent(TerrainInput* input, NiPoint3* normal, NiPoint3* tangent)
{
    NiPoint3 origin;
    NiPoint3 position;
    reinterpret_cast<::FNv53b450_Source *>(this)->FUN_0053b450((::FNv53b450_Point *)&position, (unsigned char)input->region, (unsigned short)input->position, 0, 0);
    reinterpret_cast<::LandObject *>(this)->FUN_00534240(input->region, input->position, (::LandPoint3 *)&(origin));
    NiPoint3 location;
    location = NiPoint3(reinterpret_cast<::FUN_00534050_Class *>(this)->FUN_00534050() + 2048.0, ((float)(reinterpret_cast<::FUN_00534080_Class *>(this)->FUN_00534080())) + 2048.0, 0.0f);
    NiPoint3 center = origin + location;
    center.z = 0.0f;
    if (center.FUN_004390c0(position))
    {
        reinterpret_cast<::VertOwner *>(this)->FUN_00534390(input->region, input->position, (::VertPt &)(*normal));
        *tangent = *normal;
    }
    else
    {
        float blended = FUN_004b1520(position.x, 128.0f) / 128.0;
        float pointB = FUN_004b1520(position.y, 128.0f) / 128.0;
        NiPoint3 edgeA;
        NiPoint3 u;
        NiPoint3 c;
        NiPoint3 v = DAT_011a9484;
        reinterpret_cast<::VertOwner *>(this)->FUN_00534390(input->region, input->edgeA, (::VertPt &)(edgeA));
        reinterpret_cast<::VertOwner *>(this)->FUN_00534390(input->region, input->u, (::VertPt &)(u));
        reinterpret_cast<::VertOwner *>(this)->FUN_00534390(input->region, input->c, (::VertPt &)(c));
        if (!input->flipA && !input->flipB)
            v = ((1.0f - blended) * u + blended * edgeA) * (1.0f - pointB) + pointB * c;
        if (!input->flipA && input->flipB)
            v = ((1.0f - blended) * edgeA + blended * c) * pointB + (1.0f - pointB) * u;
        if (input->flipA && !input->flipB)
            v = ((1.0f - blended) * edgeA + blended * u) * (1.0f - pointB) + pointB * c;
        if (input->flipA && input->flipB)
            v = ((1.0f - blended) * c + blended * edgeA) * pointB + (1.0f - pointB) * u;
        *normal = v;
        reinterpret_cast<::FUN_004a0c10_s *>((normal))->FUN_004a0c10();
        NiPoint3 a;
        NiPoint3 pointC;
        NiPoint3 edgeB;
        NiPoint3 b;
        reinterpret_cast<::LandObject *>(this)->FUN_00534240(input->region, input->edgeA, (::LandPoint3 *)&(a));
        reinterpret_cast<::LandObject *>(this)->FUN_00534240(input->region, input->u, (::LandPoint3 *)&(pointC));
        a.Subtract(pointC);
        reinterpret_cast<::LandObject *>(this)->FUN_00534240(input->region, input->edgeA, (::LandPoint3 *)&(edgeB));
        reinterpret_cast<::LandObject *>(this)->FUN_00534240(input->region, input->c, (::LandPoint3 *)&(b));
        edgeB.Subtract(b);
        if ((input->flipA && !input->flipB) || (!input->flipA && input->flipB))
            *tangent = reinterpret_cast<::NiPoint3 *>(&(a))->CrossProduct(edgeB);
        else
            *tangent = reinterpret_cast<::NiPoint3 *>(&(edgeB))->CrossProduct(a);
    }
    return true;
}

struct QueryState175
{
    void* vtable;
    unsigned current;
    unsigned cursor;
    unsigned char complete;
    QueryState175();
    ~QueryState175();
};
struct Head175
{
    void* value;
    Head175(int);
    ~Head175();
};
struct Manager175
{
};
struct FUN_005281f0_Class
{
    int FUN_005281f0();
};
// @fnv 0x005281f0
int FUN_005281f0_Class::FUN_005281f0()
{
    int count = 0;
    QueryState175 query;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(query))->FUN_006ebde0())
    {
        int currentValue = 0;
        Head175 itemHead(0);
        if (reinterpret_cast<::FUN_00906570_Class *>(this)->AdvanceRequest((::Request9065 *)(::QueryState175 *)(&query), (void **)(int *)(&currentValue), &itemHead, 1))
        {
            if (!reinterpret_cast<::FUN_00528870_shell *>((reinterpret_cast<Manager175*>((*reinterpret_cast<::FUN_005289b0_Class * *>(&::DAT_01202d98)))))->RunQueuedTask((::QueuedTask *)(void *)(((void *)(::FUN_00559450((int *)&(itemHead))))), (void *)(0)))
                ++count;
        }
    }
    return count;
}

class NiObject
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual NiObject* slot9(int a, int b);
};

struct FUN_00528bb0_class
{
    NiObject* m_obj;
    void FUN_00528bb0(int arg);
};

// Calls slot9(arg, arg) on m_obj and passes the result to FUN_00528ce0 on this.
// @fnv 0x00528bb0
void FUN_00528bb0_class::FUN_00528bb0(int arg)
{
    reinterpret_cast<::fnv_00528ce0::FUN_00528ce0_shell *>((reinterpret_cast<NiObject*>(this)))->FUN_00528ce0(m_obj->slot9(arg, arg), {});
}

namespace QueueReconstruction528be0 {
struct QueueBase528be0
{
    virtual void Slot00();
    ~QueueBase528be0();
};

struct FUN_00528be0 : QueueBase528be0
{
    void* unk04;
    unsigned int unk08;
    void* m_buckets;
    ~FUN_00528be0();
};

// Calls FUN_00528e40(true), then passes m_buckets and unk04 to FUN_00401030.
// @fnv 0x00528be0
FUN_00528be0::~FUN_00528be0()
{
    reinterpret_cast<::QueuedMap *>(this)->FUN_00528e40(true);
    void* buckets = m_buckets;
    ::FUN_00401030(buckets);
    void* buffer = unk04;
    ::FUN_00401030(buffer);
}

}

class TESAmmo;
class BGSAmmoForm
{
  public:
};
struct AmmoProcess
{
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
    virtual Ref* GetLeft();
    virtual Ref* GetRight();
};
struct AmmoActor
{
};
extern "C" void* __cdecl _FNV_DynamicCast(void*, int, void*, void*, int);
struct AmmoOwner
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    BGSAmmoForm ammo;
    Form* FUN_00525980(AmmoActor* actor);
};
// Returns the right-hand Form if it differs from the left one and passes the dynamic cast; otherwise returns the ammo helper's result.
// @fnv 0x00525980
Form* AmmoOwner::FUN_00525980(AmmoActor* actor)
{
    if (actor && ((::AmmoProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && ((::AmmoProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetRight())
    {
        Form* right3 = ((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((((::AmmoProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetRight()))->GetName()));
        Form* left5 = ((::AmmoProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetLeft() ? ((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((((::AmmoProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetLeft()))->GetName())) : 0;
        if (right3 != left5)
        {
            void* casted = _FNV_DynamicCast(right3, 0, &DAT_01183108, &DAT_011840c4, 0);
            if (casted)
                return right3;
        }
    }
    return (Form*)((::TESAmmo *)(reinterpret_cast<::FUN_00474920_shell *>(&(ammo))->GetFormOrScriptForm()));
}

struct Obj
{
};
struct Thing
{
    char pad[0x118];
    int m_uiFilterValue;
    intptr_t GetOrFallback(intptr_t arg);
};
// @fnv 0x00525a90
intptr_t Thing::GetOrFallback(intptr_t arg)
{
    Obj* result = ((::Obj *)(reinterpret_cast<::AmmoOwner *>(this)->FUN_00525980((::AmmoActor *)(arg))));
    if (result != 0)
    {
        int value = reinterpret_cast<::MiddleLowProcess *>((result))->GetProcessInteger();
        if (value != 0)
            return value;
    }
    return m_uiFilterValue;
}

struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float r, float g, float b, float a);
};
struct _ref_006815c0
{
    _ref_006815c0();
    ~_ref_006815c0();
};
struct FUN_0052d180 : _ref_006815c0
{
    int pad;
    RgbaColor c;
    FUN_0052d180();
};
// @fnv 0x0052d180
FUN_0052d180::FUN_0052d180() : c(0.0f, 0.0f, 0.0f, 0.0f)
{}
