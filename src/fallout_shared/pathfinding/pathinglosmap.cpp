
// src/fallout_shared/pathfinding/pathinglosmap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathinglosmap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/DecalStub.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_005582d0_shell.h"
#include "fnv/decl/FUN_0068f0a0_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_006d7ee0_shell.h"
#include "fnv/decl/FUN_006d8970_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/NiTObjectArrayA47.h"
#include "fnv/decl/S2f850.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_004bc450__FUN_004bc450_S.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00c58000.h"
struct PathingLOSMap
{
    virtual ~PathingLOSMap();
    void* DestroyAndFree(unsigned int flags);
};


namespace fnv_006e1610 {
struct DummyPointerMap
{
};

struct PathingLOSMap
{
    char* pTriangleScores;
    char* GetTriangleScore(std::uintptr_t aNavMeshID);
};

// Looks up aNavMeshID in the map at this+8 and returns a pointer into the buffer at this+0x18 offset by the stored offset, or null if not found.
// @fnv 0x006e1610
char* PathingLOSMap::GetTriangleScore(std::uintptr_t aNavMeshID)
{
    unsigned int ioffset;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)((char*)this + 8))))->FUN_00853130(aNavMeshID, (::fnv_00853130::CombatThreatRecord *&)(ioffset)))
        return ((char**)((char*)this + 0x18))[0] + ioffset;
    else
        return 0;
}
}  // namespace fnv_006e1610

struct DummyPointerMap
{
};

struct FUN_006e1650_shell
{
    DummyPointerMap m_map;  // at offset 8
    void GetMapValue(unsigned int a, unsigned int& b);
};

// Calls GetAt on the DummyPointerMap at offset 8 of this object, passing a and b through.
// @fnv 0x006e1650
void FUN_006e1650_shell::GetMapValue(unsigned int uiKey, unsigned int& ruiValue)
{
    reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)((char*)this + 8))))->FUN_00853130(uiKey, (::fnv_00853130::CombatThreatRecord *&)(ruiValue));
}

// Returns the smaller of the two char arguments.
// @fnv 0x006e1f80
char MinChar(char a, char b)
{
    char result;
    if (a < b)
        result = a;
    else
        result = b;
    return result;
}

// Returns the larger of the two char arguments.
// @fnv 0x006e1fb0
char MaxChar(char acFirst, char acSecond)
{
    char c;
    if (acFirst > acSecond)
        c = acFirst;
    else
        c = acSecond;
    return c;
}

struct NiTArray
{
};

struct FUN_006e1fe0_shell
{
    void SetArraySize(unsigned int aSize);
};

// @fnv 0x006e1fe0
void FUN_006e1fe0_shell::SetArraySize(unsigned int aSize)
{
    reinterpret_cast<::NiTObjectArrayA47 *>((((NiTArray*)(this + 0x9c))))->FUN_0060bef0(aSize);
}

namespace fnv_006e2050 {
struct DummyPointerMap
{
};

struct PathingLOSMap
{
    DummyPointerMap m_map;
    bool HasNavMeshEntry(unsigned int aiNavMeshID);
};

// Looks up aiNavMeshID in the map at offset 8 and returns whether GetAt found an entry.
// @fnv 0x006e2050
bool PathingLOSMap::HasNavMeshEntry(unsigned int aiNavMeshID)
{
    unsigned int idummy;
    return reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)((char*)this + 8))))->FUN_00853130(aiNavMeshID, (::fnv_00853130::CombatThreatRecord *&)(idummy));
}
}  // namespace fnv_006e2050

struct ArrHelper
{
};
struct Script
{
};
struct FUN_006e1770_shell
{
    bool FUN_006e1770(std::uintptr_t a, std::uintptr_t b);
};
namespace fnv_006e2000 {
struct Script
{
};
struct FUN_006d7ee0_shell
{
};
struct FUN_006d8970_shell
{
};
struct FUN_006e2000_shell
{
    void ClampNonPositiveTextChars();
};
// Iterates over the text characters and sets each character whose value is <= 0 to 0x7f.
// @fnv 0x006e2000
void FUN_006e2000_shell::ClampNonPositiveTextChars()
{
    for (unsigned int i = 0; i < ((int)(reinterpret_cast<::BGSMessageInitAccess *>((((Script*)this)))->GetIconFormID())); ++i)
    {
        if (reinterpret_cast<::FUN_006d7ee0_shell *>((((FUN_006d7ee0_shell*)this)))->GetByteAt(i) <= 0)
            reinterpret_cast<::FUN_006d8970_shell *>((((FUN_006d8970_shell*)this)))->SetByteAt((int)i, 0x7f);
    }
}
}  // namespace fnv_006e2000

struct PathingLOSBase
{
    virtual ~PathingLOSBase();
    unsigned int unk04;
};

struct LOSSub08
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~LOSSub08();
};

struct LOSHeap
{
    unsigned int unk00;
};

struct LOSMember1C
{
    unsigned int unk00;
};

struct FUN_006e1470 : PathingLOSBase
{
    LOSSub08 m_08;
    LOSHeap* m_18;
    LOSMember1C m_1c;

    virtual ~FUN_006e1470();
};
// Runs the destructor and, when flags has bit 0 set, frees the object with operator delete, then returns this.
// @fnv 0x006e1440
void* PathingLOSMap::DestroyAndFree(unsigned int flags)
{
    reinterpret_cast<::FUN_006e1470 *>((this))->::FUN_006e1470::~FUN_006e1470();
    if (flags & 1)
        operator delete(this, 0x50);
    return this;
}

// Destructor that deletes m_18 if non-null, then calls ReleaseMember on m_1c.
// @fnv 0x006e1470
FUN_006e1470::~FUN_006e1470()
{
    if (m_18 != 0)
    {
        delete m_18;
    }
    ::FUN_0042f830((::FUN_0042f830_struct *)&(m_1c));
}

struct NavMesh;

struct NavMeshPtr
{
public:
    ::NavMeshPtr &operator=(const ::NavMeshPtr &);
};

class NavMeshTriangle;
struct NavMesh
{
public:
    ::NavMeshTriangle *GetTriangle(unsigned short);
};

struct NavMeshCollection
{
    NavMeshPtr& FUN_00877a30(unsigned int i);
};

struct MapHelper
{
};

struct Shell1c
{
};

struct FUN_006e1500_class
{
    void* vtable;
    char pad_04[4];
    MapHelper m_map;
    char pad_0c[0x0c];
    char* m_pData;
    Shell1c m_shell1c;
    char pad_20[0x0c];
    unsigned int m_uTotalCount;

    bool BuildNavMeshMap(NavMeshCollection* pArray);
};

// Clears the total count, maps each array entry's navmesh id to a running offset, sums sizes, then allocates and fills m_pData with 0x7f.
// @fnv 0x006e1500
bool FUN_006e1500_class::BuildNavMeshMap(NavMeshCollection* pNavMeshArray)
{
    unsigned int i;
    unsigned int j2;
    m_uTotalCount = 0;
    for (i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pNavMeshArray))->GetName())); i++)
    {
        reinterpret_cast<::FUN_00844700_Class *>(&(m_map))->FUN_00844700(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::NavMesh *)(::FUN_00559450((int *)&(pNavMeshArray->FUN_00877a30(i)))))))->FUN_0084e3a0())), m_uTotalCount);
        m_uTotalCount += ::FUN_00558200((char *)(((::NavMesh *)(::FUN_00559450((int *)&(pNavMeshArray->FUN_00877a30(i)))))));
        reinterpret_cast<::S2f850 *>(&(m_shell1c))->AppendValue(pNavMeshArray->FUN_00877a30(i));
    }
    if (m_pData)
    {
        delete m_pData;
    }
    m_pData = new char[m_uTotalCount];
    for (j2 = 0; j2 < m_uTotalCount; j2++)
    {
        m_pData[j2] = 0x7f;
    }
    return true;
}

struct SeqEntry
{
};

struct SeqList
{
    SeqEntry* FUN_00877a30(unsigned int index);
};

struct SubMatcher
{
};

struct SpawnedTarget
{
};

struct FUN_006e1670_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    char FUN_006e1670(unsigned int limit, SpawnedTarget* target, unsigned short* outOffset);
};
// Returns false if the helper at offset 0x1c reports true; otherwise scans text entries and returns true on the first non-positive char whose lookup succeeds.
// @fnv 0x006e1770
bool FUN_006e1770_shell::FUN_006e1770(std::uintptr_t a, std::uintptr_t b)
{
    if (reinterpret_cast<::FUN_0076b610_Class *>((void *)(((const ArrHelper*)((char*)this + 0x1c))))->FUN_0076b610())
        return false;
    for (unsigned int i = 0; i < ((int)(reinterpret_cast<::BGSMessageInitAccess *>((((Script*)this)))->GetIconFormID())); ++i)
    {
        char cChar = reinterpret_cast<::FUN_006d7ee0_shell *>((((Script*)this)))->GetByteAt(i);
        if (cChar > 0)
            continue;
        unsigned char d = reinterpret_cast<::FUN_006e1670_cls *>((((Script*)this)))->FUN_006e1670(i, (::SpawnedTarget *)(a), (unsigned short *)(b));
        if (d)
            return true;
    }
    return false;
}

// Scans the sequence list, measuring each entry's script length; when a length exceeds limit, stores the remaining offset and passes the previous entry to target.
// @fnv 0x006e1670
char FUN_006e1670_cls::FUN_006e1670(unsigned int limit, SpawnedTarget* target, unsigned short* outOffset)
{
    unsigned int i;
    unsigned int accum;
    if (reinterpret_cast<::FUN_0076b610_Class *>((void *)(((ArrHelper*)&this->unk1c)))->FUN_0076b610())
    {
        return 0;
    }

    i = 0;
    for (accum = 0; accum < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((SeqList*)&this->unk1c)))->GetName())); accum++)
    {
        unsigned int len;
        Script* script = ((::Script *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SeqEntry *)(::FUN_00559450((int *)(((SeqList*)&this->unk1c)->FUN_00877a30(accum)))))))->FUN_0084e3a0()));
        if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((((SubMatcher*)&this->unk08)))->FUN_00853130((std::uintptr_t)(script), (*(::fnv_00853130::CombatThreatRecord * *)(&len))))
        {
            return 0;
        }
        if (len > limit)
        {
            *outOffset = (unsigned short)(limit - i);
            reinterpret_cast<::NavMeshPtr *>((target))->operator=((*(const ::NavMeshPtr *)(((SeqList*)&this->unk1c)->FUN_00877a30(accum - 1))));
            return 1;
        }
        else
        {
            i = len;
        }
    }
    *outOffset = (unsigned short)(limit - i);
    reinterpret_cast<::NavMeshPtr *>((target))->operator=((*(const ::NavMeshPtr *)(((SeqList*)&this->unk1c)->FUN_00877a30(accum - 1))));
    return 1;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3();
    NiPoint3(float x, float y, float z);
};

struct NiColor
{
    float r;
    float g;
    float b;
};

struct ImageSpaceEffectParam
{
    float m0;
    float m1;
    float m2;
    float m3;
    ImageSpaceEffectParam(float a, float b, float c, float d);
};

class NiMemObject
{
  public:
};

class NiObject : public NiMemObject
{
  public:
    virtual ~NiObject();
};

class NiAVObject : public NiObject
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
};

class NiUpdateData
{
  public:
    float time;
    bool updateControllers;
    bool unk05;
    int unk08;
    NiUpdateData(float time = 0.0f, bool updateControllers = false, bool unk05 = false);
};

class NiNode : public NiAVObject
{
  public:
    virtual unsigned int AttachChildInAvailableSlot(NiAVObject* child, bool firstAvail = false);
};

class NiSortAdjustNode : public NiNode
{
  public:
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
    int unka4;
    int unka8;
    NiSortAdjustNode(int mode = 0);
};

class NiProperty : public NiObject
{
  public:
};

class NiAlphaProperty : public NiProperty
{
  public:
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    NiAlphaProperty();
};

class NiMaterialProperty : public NiProperty
{
  public:
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
    NiMaterialProperty();
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* pObject = 0);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
};

struct NavMeshTriangle
{
};

struct NavMeshEx : NavMesh
{
};

class NavMeshLocalPtr
{
  public:
    void* m_ptr;
    NavMeshLocalPtr();
    ~NavMeshLocalPtr();
    operator NavMeshEx*() const;
    NavMeshEx* operator->() const;
};

struct FUN_004bc1f0_S
{
    void FUN_004bc1f0(float a, float b, float c);
};

NiAVObject* __cdecl FUN_004b3570(NiPoint3, NiPoint3, NiPoint3, const ImageSpaceEffectParam*, int);

struct ScriptClass : Script
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
    float f3c;
    float f40;
    float f44;
    float f48;

    NiSortAdjustNode* CreateSortAdjustNode();
};

// @fnv 0x006e1800
NiSortAdjustNode* ScriptClass::CreateSortAdjustNode()
{
    NiSortAdjustNode* rootNode = new NiSortAdjustNode(0);
    NiPointer<NiAlphaProperty> spA(new NiAlphaProperty());
    reinterpret_cast<::FUN_0049ed90_shell *>(((spA).operator->()))->FUN_0049ed90(true);
    NiPointer<NiMaterialProperty> spB(new NiMaterialProperty());
    NiPoint3 kWhite(1.0f, 1.0f, 1.0f);
    reinterpret_cast<::fnv_004bc450::FUN_004bc450_S *>(((spB).operator->()))->FUN_004bc450((const ::fnv_004bc450::C3 *)(const ::NiColor *)((const NiColor*)&kWhite));
    reinterpret_cast<::DecalStub *>(((spB).operator->()))->FUN_0068c9f0(0.75f);
    reinterpret_cast<::FUN_00439410_cls *>((rootNode))->FUN_00439410((::ArgObject *)(::NiObject *)(spA));
    reinterpret_cast<::FUN_00439410_cls *>((rootNode))->FUN_00439410((::ArgObject *)(::NiObject *)(spB));

    char highest = (char)0x81;
    char low = (char)0x7f;
    for (unsigned int i = 0; i < (unsigned int)((int)(reinterpret_cast<::BGSMessageInitAccess *>((this))->GetIconFormID())); ++i)
    {
        char c = reinterpret_cast<::FUN_006d7ee0_shell *>((this))->GetByteAt(i);
        if (c == 0x7f)
            continue;
        highest = MaxChar(highest, c);
        low = MinChar(low, c);
    }

    reinterpret_cast<::FUN_006e1fe0_shell *>((rootNode))->SetArraySize((unsigned int)((int)(reinterpret_cast<::BGSMessageInitAccess *>((this))->GetIconFormID())) + 10);

    for (unsigned int j = 0; j < (unsigned int)((int)(reinterpret_cast<::BGSMessageInitAccess *>((this))->GetIconFormID())); ++j)
    {
        NavMeshLocalPtr p2;
        unsigned short p0;
        if (!(unsigned char)reinterpret_cast<::FUN_006e1670_cls *>((this))->FUN_006e1670(j, (::SpawnedTarget *)(&p2), (unsigned short *)(&p0)))
            continue;
        char a = reinterpret_cast<::FUN_006d7ee0_shell *>((this))->GetByteAt(j);
        if (a == 0x7f)
            continue;
        float p = (a < 0) ? ((float)a / low * 0.5 + 0.5) : 0.0;
        float h1 = (a > 0) ? ((float)a / highest * 0.5 + 0.5) : 0.0;
        ImageSpaceEffectParam h0(p, h1, 0.0f, 0.75f);
        NiPoint3 cf[3];
        NavMeshTriangle* h = reinterpret_cast<::NavMesh *>(((p2).operator->()))->GetTriangle(p0);
        if (!reinterpret_cast<::FUN_00691140_shell *>((h))->FUN_00691140(0x20))
        {
            for (unsigned int k = 0; k < 3; ++k)
            {
                cf[k] = *((::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>(((p2).operator->()))->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((h))->FUN_005582d0(k))));
                cf[k].z += 5.0;
            }
            NiPointer<NiAVObject> spC(FUN_004b3570(cf[0], cf[1], cf[2], &h0, 1));
            rootNode->AttachChildInAvailableSlot(spC, 1);
        }
    }

    if (this->f48 != 0.0)
    {
        NiSortAdjustNode* p4 = new NiSortAdjustNode(0);
        ImageSpaceEffectParam vec(1.0f, 1.0f, 0.0f, 0.5f);
        for (unsigned int m = 0; m < 5; ++m)
        {
            void* ac = ::fnv_00c58f00::FUN_00c58f00(this->f48, 0x24, (::fnv_00c58f00::Vec4Item *)(void *)(&vec));
            ((FUN_004bc1f0_S*)ac)->FUN_004bc1f0(this->f3c, this->f40, (float)((double)m * 25.0 + this->f44));
            p4->AttachChildInAvailableSlot((NiAVObject*)ac, 1);
        }
        void* ac1 = ((void *)(::FUN_00c58d30(16.0f, 16.0f, 400.0f, 10, 10, (std::intptr_t)(&vec))));
        reinterpret_cast<::FUN_00440460_S *>((((NiSortAdjustNode*)ac1)))->FUN_00440460((const ::V3 *)&(*(const NiPoint3*)&this->f3c));
        p4->AttachChildInAvailableSlot((NiAVObject*)ac1, 1);
        ::fnv_004b6e90::AttachLightingPropertyRecursive((::NiAVObject *)(p4));
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(p4), 0, 0);
        rootNode->AttachChildInAvailableSlot(p4, 1);
    }

    reinterpret_cast<::FUN_00a5a040_Class *>((rootNode))->FUN_00a5a040();
    NiUpdateData updateData(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((rootNode))->FUN_00a59c60((std::intptr_t)&(updateData));
    return rootNode;
}
