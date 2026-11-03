
// src/fallout_shared/bgstextureusemap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgstextureusemap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BinaryWriter.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_00444ed0_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_0057c850_cls.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
struct FUN_004aa3d0_shell
{
    void FUN_004aa3d0(std::intptr_t a, char b);
    void SetValueAndCall(std::intptr_t a, std::intptr_t b, char c);
};

void FUN_004aa3d0_shell::FUN_004aa3d0(std::intptr_t a, char b)
{}

// Stores b into the object's first field and forwards a and c to FUN_004aa3d0.
// @fnv 0x004aa3a0
void FUN_004aa3d0_shell::SetValueAndCall(std::intptr_t aiArg, std::intptr_t aiValue, char c)
{
    *(int*)this = aiValue;
    FUN_004aa3d0(aiArg, c);
}

struct NiTMap
{
};

struct UnsignedIntegerRecord
{
    unsigned int m0;
    unsigned long m_ulSecondValue;
};

struct NiTMapContainer
{
    unsigned int m1;
    NiTMap m_kEntryMap;
    unsigned long FUN_004aa890();
};

// @fnv 0x004aa890
unsigned long NiTMapContainer::FUN_004aa890()
{
    unsigned long ulretsize = 0;
    void* iter = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(this->m_kEntryMap))->GetFirstPos();
    while (iter)
    {
        unsigned int key = 0;
        UnsignedIntegerRecord* pdata = 0;
        reinterpret_cast<::C6b7f20_Map *>(&(this->m_kEntryMap))->FUN_006b7f20((::C6b7f20_Node **)&(iter), (unsigned int *)&(key), (void **)&((void*&)pdata));
        if (pdata)
        {
            ulretsize += pdata->m_ulSecondValue;
        }
    }
    return ulretsize;
}

struct FUN_004a9850_shell
{
    ~FUN_004a9850_shell();
};
extern int _data_011c16bc;
struct FUN_004aa340
{
    int _m0;
    FUN_004a9850_shell _m1;
    void RemoveAllEntries();
    ~FUN_004aa340();
};
// @fnv 0x004aa340
FUN_004aa340::~FUN_004aa340()
{
    RemoveAllEntries();
}

struct FUN_004aa650_shell
{
    void FUN_004aa680();
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_004aa680, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004aa650
void* FUN_004aa650_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_004aa680();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004aa720_shell
{
    void AddEntry(int a, int b, int c);
};
// If the pointer stored at c is non-null, calls AddEntry on it with a, b and the value at c+4.
// @fnv 0x004aa6f0
void InvokeIfPresent(int aiArg1, int aiArg2, int apHolder)
{
    std::intptr_t pparam = apHolder;
    if (*(int*)pparam)
    {
        ((FUN_004aa720_shell*)*(std::intptr_t*)pparam)->AddEntry(aiArg1, aiArg2, *(int*)(pparam + 4));
    }
}

struct GO
{
    int m;
    GO(int);
    ~GO()
    {}
};
struct SL
{
    int a;
    int b;
    SL();
};
struct FUN_004aa830
{
    GO m0;
    int m4;
    SL m8;
    FUN_004aa830();
};
// @fnv 0x004aa830
FUN_004aa830::FUN_004aa830() : m0(0)
{}

namespace fnv_004aa680 {
struct GO
{
    virtual ~GO();
};
struct ListX
{
    ~ListX();
};
struct FUN_004aa680_shell
{
    GO base;
    char pad[4];
    ListX m_kNode;
    ~FUN_004aa680_shell();
};

// Destructor that calls RemoveAll on the embedded list before the object is destroyed.
// @fnv 0x004aa680
FUN_004aa680_shell::~FUN_004aa680_shell()
{
    reinterpret_cast<::FileMatchList *>(&(m_kNode))->RemoveAll();
}
}  // namespace fnv_004aa680

struct MapX
{
};

struct MyMap
{
};

// Iterates the map at this+4, calls DestroyIfFlagged(1) on each value, then clears the map with RemoveAll.
// @fnv 0x004aa5d0
void FUN_004aa340::RemoveAllEntries()
{
    void* iter = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((reinterpret_cast<MapX*>(&this->_m1)))->GetFirstPos();

    while (iter)
    {
        unsigned int pignore = 0;
        void* value = 0;

        reinterpret_cast<::C6b7f20_Map *>((reinterpret_cast<NiTMap*>(&this->_m1)))->FUN_006b7f20((::C6b7f20_Node **)&(iter), (unsigned int *)&(pignore), (void **)&(value));

        UnsignedIntegerRecord* pdata = reinterpret_cast<UnsignedIntegerRecord*>(value);
        UnsignedIntegerRecord* key = pdata;

        key ? reinterpret_cast<FUN_004aa650_shell*>(key)->DestroyIfFlagged(1) : 0;
    }

    reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<MyMap*>(&this->_m1)))->FUN_00438af0();
}


struct G2
{
    void AddHead(int* p);
};

struct LH
{
};

struct SetAtHelper
{
};

struct DummyPointerMap
{
};

struct GO_operator
{
    void operator=(void* value);
};

// Looks up or creates a FUN_004aa830 keyed by a in the map at this+4, sets its key and m4, then adds c to its list at offset 8 if absent.
// @fnv 0x004aa720
void FUN_004aa720_shell::AddEntry(int aiKey, int aiValue, int aiItem)
{
    FUN_004aa830* p;

    if (aiKey && aiItem)
    {
        p = 0;

        if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((reinterpret_cast<DummyPointerMap*>(reinterpret_cast<char*>(this) + 4)))->FUN_00853130(static_cast<unsigned int>(aiKey), (::fnv_00853130::CombatThreatRecord *&)(reinterpret_cast<unsigned int&>(p))) ||
            !p)
        {
            p = new FUN_004aa830;

            reinterpret_cast<::FUN_00844700_Class *>((reinterpret_cast<SetAtHelper*>(reinterpret_cast<char*>(this) + 4)))->FUN_00844700(static_cast<unsigned int>(aiKey), reinterpret_cast<std::uintptr_t>(p));

            reinterpret_cast<GO_operator*>(p)->operator=(reinterpret_cast<void*>(aiKey));

            p->m4 = aiValue;
        }

        if (!reinterpret_cast<::RefList *>((reinterpret_cast<LH*>(&p->m8.a)))->FUN_005f65d0((void **)&(reinterpret_cast<int&>(aiItem))))
        {
            reinterpret_cast<G2*>(&p->m8.a)->AddHead(&aiItem);
        }
    }
}

class NiAVObject;
struct NiNode
{
public:
    ::NiAVObject *GetAt(unsigned int);
};

struct LLD_Cell
{
};

struct GridCell
{
    LLD_Cell* m0;
};

struct CP_008c48d0
{
};

struct TES : public CP_008c48d0
{
    GridCell* FUN_00457050(int a, int b);
};

struct GlobalObject_0045cfe0
{
};


struct FUN_004aabb0_shell : public FUN_004aa3d0_shell
{
    void FUN_004aabb0(char a1);
};

// If a previous path exists, processes its cell; otherwise iterates the 5x5 grid around half the global int and processes each occupied cell.
// @fnv 0x004aabb0
void FUN_004aabb0_shell::FUN_004aabb0(char a1)
{
    LLD_Cell* inner5;
    unsigned int center3;
    unsigned int grid;
    unsigned int maxValue2;
    unsigned int fTargetUpperBound;
    unsigned int previousPath;
    GridCell* outer;
    LLD_Cell* cell;

    if (((::LLD_Cell *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetPrevPath())))
    {
        inner5 = ((::LLD_Cell *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetPrevPath()));
        this->SetValueAndCall(reinterpret_cast<std::intptr_t>(reinterpret_cast<::FUN_00545cb0_shell *>((inner5))->FUN_00545cb0()), reinterpret_cast<std::intptr_t>(inner5), a1);
    }
    else
    {
        maxValue2 = static_cast<unsigned int>(*((int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc))))) >> 1;
        grid = maxValue2 - 2;
        center3 = maxValue2 + 2;

        for (previousPath = grid; previousPath <= center3; ++previousPath)
        {
            for (fTargetUpperBound = grid; fTargetUpperBound <= center3; ++fTargetUpperBound)
            {
                outer = (*reinterpret_cast<::TES * *>(&::g_TES))->FUN_00457050(previousPath, fTargetUpperBound);
                if (outer->m0)
                {
                    cell = outer->m0;
                    this->SetValueAndCall(reinterpret_cast<std::intptr_t>(reinterpret_cast<::FUN_00545cb0_shell *>((cell))->FUN_00545cb0()), reinterpret_cast<std::intptr_t>(cell), a1);
                }
            }
        }
    }
}

struct NiRTTI
{
};
struct NiAVObject
{
};
extern const char str_0101f524[];

struct BSFadeNode
{
    void* FUN_0043b1b0();
public:
    unsigned int FUN_009ad610();
};
struct CastedObj
{
    virtual void vt_00();
    virtual void vt_01();
    virtual void vt_02();
    virtual void vt_03();
    virtual void vt_04();
    virtual void vt_05();
    virtual void vt_06();
    virtual void vt_07();
    virtual void vt_08();
    virtual void vt_09();
    virtual void vt_10();
    virtual void vt_11();
    virtual void vt_12();
    virtual void vt_13();
    virtual void vt_14();
    virtual void vt_15();
    virtual void vt_16();
    virtual void vt_17();
    virtual void vt_18();
    virtual void vt_19();
    virtual void vt_20();
    virtual void vt_21();
    virtual void vt_22();
    virtual void vt_23();
    virtual void vt_24();
    virtual void vt_25();
    virtual void vt_26();
    virtual void vt_27();
    virtual void vt_28();
    virtual void vt_29();
    virtual void vt_30();
    virtual void vt_31();
    virtual void vt_32();
    virtual void vt_33();
    virtual void vt_34();
    virtual void vt_35();
    virtual void vt_36();
    virtual void vt_37();
    virtual void vt_38();
    virtual BSFadeNode* vt_9c();
};
struct ElemObj
{
    virtual void vt_00();
    virtual void vt_01();
    virtual void vt_02();
    virtual void vt_03();
    virtual void vt_04();
    virtual void vt_05();
    virtual void vt_06();
    virtual void vt_07();
    virtual void vt_08();
    virtual void vt_09();
    virtual void vt_10();
    virtual void vt_11();
    virtual void vt_12();
    virtual void vt_13();
    virtual void vt_14();
    virtual void vt_15();
    virtual void vt_16();
    virtual void vt_17();
    virtual void vt_18();
    virtual void vt_19();
    virtual void vt_20();
    virtual void vt_21();
    virtual void vt_22();
    virtual void vt_23();
    virtual void vt_24();
    virtual void vt_25();
    virtual void vt_26();
    virtual void vt_27();
    virtual void vt_28();
    virtual void vt_29();
    virtual void vt_30();
    virtual void vt_31();
    virtual void vt_32();
    virtual void vt_33();
    virtual void vt_34();
    virtual void vt_35();
    virtual void vt_36();
    virtual void vt_37();
    virtual void vt_38();
    virtual void vt_39();
    virtual void vt_40();
    virtual void vt_41();
    virtual void vt_42();
    virtual void vt_43();
    virtual void vt_44();
    virtual void vt_45();
    virtual void vt_46();
    virtual void vt_47();
    virtual void vt_48();
    virtual void vt_49();
    virtual void vt_50();
    virtual void vt_51();
    virtual void vt_52();
    virtual void vt_53();
    virtual void vt_54();
    virtual void vt_55();
    virtual void vt_56();
    virtual void vt_57();
    virtual void vt_58();
    virtual void vt_59();
    virtual void vt_60();
    virtual void vt_61();
    virtual void vt_62();
    virtual void vt_63();
    virtual void vt_64();
    virtual void vt_65();
    virtual void vt_66();
    virtual void vt_67();
    virtual void vt_68();
    virtual void vt_69();
    virtual void vt_70();
    virtual void vt_71();
    virtual void vt_72();
    virtual void vt_73();
    virtual void vt_74();
    virtual void vt_75();
    virtual const char* vt_130();
};
struct TESForm_Proxy40e30
{
};
struct RefObj
{
};
struct TESRegionData;
template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList* m_pkNext;
    bool FUN_008256d0();
    T& GetItem();
    BSSimpleList* GetNext();
    unsigned int ItemsInList();
};
struct StrMem
{
    char* m_buf;
    int m_len;
    StrMem();
    ~StrMem();
};
struct BSFile
{
    virtual ~BSFile();
    BSFile(const char*, bool, unsigned int, bool);
    char m_fileName[0x104];
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
public:
    bool Open(bool, bool);
public:
    void Close();
};
struct TexUseMap
{
    unsigned int m1;
    NiTMap m_kEntryMap;
    bool FUN_004aa900(const char* name);
};
// @fnv 0x004aa900
bool TexUseMap::FUN_004aa900(const char* apFileName)
{
    bool result5 = false;
    BSFile file9(apFileName, true, 0x400, true);
    if (reinterpret_cast<::BSFile *>(&(file9))->Open(false, false))
    {
        result5 = true;
        void* posVal = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_kEntryMap))->GetFirstPos();
        while (posVal)
        {
            std::uintptr_t key5 = 0;
            void* value9 = 0;
            reinterpret_cast<::C6b7f20_Map *>(&(m_kEntryMap))->FUN_006b7f20((::C6b7f20_Node **)&(posVal), (unsigned int *)&(key5), (void **)&(value9));
            CastedObj* casted9 = (CastedObj*)((::NiAVObject *)(::FUN_00653270((const NiRTTI*)&(*reinterpret_cast<int *>(&::g_011f444c)), (::NiObject *)(::NiAVObject *)((NiAVObject*)key5))));
            if (casted9 && value9)
            {
                StrMem str5;
                ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&str5), "%s\t%d bytes\t%i users\r\n", casted9->vt_9c()->FUN_0043b1b0(),
                             ((UnsignedIntegerRecord*)value9)->m_ulSecondValue,
                             ((BSSimpleList<TESRegionData*>*)((char*)value9 + 8))->ItemsInList());
                reinterpret_cast<::BinaryWriter *>(&(file9))->FUN_00affbb0((const ::StreamString *)(void *)(&str5), 1);
                BSSimpleList<TESRegionData*>* listA = (BSSimpleList<TESRegionData*>*)((char*)value9 + 8);
                while (listA && !listA->FUN_008256d0())
                {
                    TESRegionData* elem9 = (listA->m_item);
                    listA = ((::BSSimpleList< ::TESRegionData *> *)(reinterpret_cast<::Callees *>((listA))->FUN_00726070()));
                    ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&str5), str_0101f524, ((const char *)(reinterpret_cast<::FUN_00440e30_This *>((((TESForm_Proxy40e30*)elem9)))->FUN_00440e30())),
                                 ((ElemObj*)elem9)->vt_130(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((RefObj*)elem9)))->FUN_0084e3a0())));
                    reinterpret_cast<::BinaryWriter *>(&(file9))->FUN_00affbb0((const ::StreamString *)(void *)(&str5), 1);
                }
                ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&str5), "\r\n");
                reinterpret_cast<::BinaryWriter *>(&(file9))->FUN_00affbb0((const ::StreamString *)(void *)(&str5), 1);
            }
        }
        reinterpret_cast<::BSFile *>(&(file9))->Close();
    }
    return result5;
}

namespace fnv_004aa3d0 {
struct TESForm;
struct WalkRef;
struct NiAVObject;

struct FormTypeHolder
{
    int GetFormType();
};
struct WalkRef
{
};
struct WalkFadeNode
{
};
struct WalkNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int IsFadeNode();
    unsigned int GetChildCount();
};
struct WalkProperty
{
    virtual void v00();
    unsigned int GetTypeTag();
};
typedef void (*WalkCallback)(int a, int b, int c);
struct WalkTexProperty : WalkProperty
{
};
struct WalkTexVT
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void ForEachTexture(WalkCallback cb, void* ctx);
    unsigned int GetTypeTag();
};
struct WalkGeometry
{
};
struct NiAVObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual WalkNode* IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual WalkGeometry* IsGeometry();
};
struct WalkRefMap
{
};
extern WalkRefMap* g_walkRefMap;
extern WalkRef* g_walkCurrentRef;


struct WalkCtx
{
    void* owner;
    int value;
};

struct TextureWalker
{
    int m0;
    void FUN_004aa3d0(NiAVObject* obj, bool b);
};

// Recursively walks a NiAVObject tree, tracking the current WalkRef from fade nodes and invoking a texture callback on geometry properties.
// @fnv 0x004aa3d0
void TextureWalker::FUN_004aa3d0(NiAVObject* obj, bool b)
{
    if (obj && !reinterpret_cast<::FUN_00456630_helper *>((obj))->FUN_00456610())
    {
        WalkNode* node = obj->IsSceneNode();
        if (node)
        {
            bool bSkip = false;
            bool bSet = false;
            WalkFadeNode* fade = 0;
            if (node->IsFadeNode())
                fade = (WalkFadeNode*)node;
            if (fade)
            {
                WalkRef* ref = ((::fnv_004aa3d0::WalkRef *)(reinterpret_cast<::BSFadeNode *>((fade))->FUN_009ad610()));
                if (g_walkRefMap)
                    reinterpret_cast<::FUN_0057c850_cls *>((g_walkRefMap))->FUN_0057c850(ref, &bSkip);
                if (ref && !bSkip)
                {
                    bool bType = false;
                    switch (((::fnv_004aa3d0::FormTypeHolder *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->GetFormType())
                    {
                    case 0x2a:
                    case 0x2b:
                    case 0x2c:
                    case 0x2d:
                        bType = true;
                    }
                    if (bType && !b || reinterpret_cast<::FUN_00444ed0_shell *>((ref))->FUN_00444ed0())
                        return;
                    bSet = true;
                    g_walkCurrentRef = ref;
                }
            }
            if (!bSkip)
            {
                unsigned int count = node->GetChildCount();
                for (unsigned int i = 0; i < count; i++)
                {
                    NiAVObject* child = ((::fnv_004aa3d0::NiAVObject *)(reinterpret_cast<::NiNode *>((node))->GetAt(i)));
                    reinterpret_cast<::FUN_004aa3d0_shell *>(this)->FUN_004aa3d0((std::intptr_t)(child), b);
                }
            }
            if (bSet)
                g_walkCurrentRef = 0;
        }
        else
        {
            WalkGeometry* geom = obj->IsGeometry();
            if (geom)
            {
                WalkTexVT* pProp = ((::fnv_004aa3d0::WalkTexVT *)(reinterpret_cast<::FUN_00a59d30_C *>((geom))->FUN_00a59d30(3)));
                WalkTexVT* tex = !pProp ? 0 : (reinterpret_cast<::BGSTerrainManager *>((pProp))->GetMinLevel() != -1 ? pProp : 0);
                if (tex)
                {
                    WalkCtx ctx;
                    ctx.owner = this;
                    ctx.value = g_walkCurrentRef ? (std::intptr_t)g_walkCurrentRef : m0;
                    tex->ForEachTexture(::InvokeIfPresent, &ctx);
                }
            }
        }
    }
}
}  // namespace fnv_004aa3d0

#include "generated/data/fallout_shared/bgstextureusemap.inc"
