
// src/gamebryo2.2/corelibs/nianimation/nicontrollersequence_fpfast_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy /fp:fast (unit src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstdint>
#include <windows.h>
#include <cmath>
#include <cstring>
#include "fnv/decl/A31500Item.h"
#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/A5d470Class.h"
#include "fnv/decl/ActiveArray.h"
#include "fnv/decl/CloneSequence.h"
#include "fnv/decl/Cls_a64ea0.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a30540_cls.h"
#include "fnv/decl/FUN_00a31260_StandIn.h"
#include "fnv/decl/FUN_00a32290_Cls.h"
#include "fnv/decl/FUN_00a41410_cls.h"
#include "fnv/decl/FUN_00a5d2f0_class.h"
#include "fnv/decl/FUN_00a641f0_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiControllerSequenceT.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a30640__NiControllerSequence.h"
#include "fnv/decl/fnv_00a32330__SequenceArrays.h"
#include "fnv/decl/fnv_00a64df0__FUN_00a64df0_Stream.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a32000.h"
#include "fnv/symbols_00a47000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01014000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01044000.h"
#include "fnv/symbols_01047000.h"
#include "fnv/symbols_0105a000.h"
#include "fnv/symbols_01096000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
const char* const* __cdecl FUN_00a31730();
struct BaseH
{
    virtual ~BaseH();
};
struct NiControllerSequence : BaseH
{
    void* FUN_00a35820(unsigned int);
public:
    NiControllerSequence();
};
struct FUN_00a30580_shell
{
    bool IsNotInChain(void* arg);
};
struct MM_00a34450
{
};
extern int DAT_01096620;
struct FUN_00a34450_shell
{
    void* FUN_00a34450(unsigned int);
};
struct NiBinaryStream
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pv, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = uiBytes;
        m_uiStreamFlags += m_pfnWrite(this, pv, uiBytes, &uiComponentSize, 1);
    }
};
class NiObject;
struct NiStream
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void SaveLinkID(const void* pkObject);
    unsigned char m_auiShapeKeys[0x24c];
    NiBinaryStream* m_pBackingStream;
public:
    ::NiObject *GetLoadedObject();
public:
    ::NiObject *DeserializeObject();
};
struct NiObject
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
};
struct SeqInterpArrayItem
{
    void* m_spControllerInterpolator;
    void* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned char m_auiShapeKeys[2];
};
struct SeqIDTag
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
};
struct FUN_00a33bf0_s : NiObject
{
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    SeqInterpArrayItem* m_pInterpArray;
    SeqIDTag* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    unsigned char m_pad34[0xc];
    void* m_pkOwnerManager;
    unsigned char m_pad44[0x18];
    char* m_kAccumulationRootName;
    unsigned char m_pad60[0xc];
    void** m_pkAnimNotes;
    unsigned short m_usNumAnimNotes;
    void SaveToStream(NiStream& kStream);
};
struct FUN_00a2e420_shell
{
    unsigned char FUN_00a2e420(float);
};
struct FUN_00a30540_shell
{
};
struct FUN_00a35030_shell : NiControllerSequence
{
    unsigned char SetEaseOut(float fEaseOutTime, bool bTransition);
};
struct FUN_00a30900_shell
{
    void FUN_00a30900(char m_ucRegionPriority);
};
struct A51BF0Base
{
    static void* __cdecl operator new(size_t);
};
struct FUN_00a316a0_shell
{
};
extern char DAT_01096584;
extern int(* DAT_00fdf1c4)(void*);
struct NiRefObject
{
    ~NiRefObject();
};
struct FUN_00a31500_shell
{
};
struct FUN_00a315b0_shell
{
};
struct FUN_00a31740_shell
{
};
struct FUN_00a35640_shell
{
    void FUN_00a35640();
};
struct RefBase
{
    virtual void First()
    {}
    virtual void Release()
    {}
};
void __cdecl FUN_00ec65a6(char* c, unsigned int b, const char* a);
struct FUN_00a307c0_entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};
struct FUN_00a307c0_item
{
    const char* name;
    const char* ctrl;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};
struct FUN_00a307c0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_00a307c0_entry* m_14;
    FUN_00a307c0_item* m_18;
    void GetEntryText(unsigned int idx, char* out);
};
struct S_00a30880_RefObject
{
    virtual ~S_00a30880_RefObject()
    {}
    virtual void V01()
    {}

    long m_lRefCount;
};
struct S_00a30880_Base
{
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void V18()
    {}
    virtual void V19()
    {}
    virtual void V20()
    {}
    virtual void V21()
    {}
    virtual void V22()
    {}
    virtual void V23()
    {}
    virtual void V24()
    {}
    virtual void V25()
    {}
    virtual void V26()
    {}
    virtual void V27()
    {}
    virtual void V28()
    {}
    virtual void V29()
    {}
    virtual void V30()
    {}
    virtual void V31()
    {}
    virtual void V32()
    {}
    virtual void V33()
    {}
    virtual void V34()
    {}

    virtual void Target(float fValue, unsigned int uiFlags)
    {}
};
struct S_00a30880_Item
{
    void* m_spControllerInterpolator;
    S_00a30880_RefObject* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned char m_auiShapeKeys[2];
};
struct S_00a30880_Foo : S_00a30880_Base
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    S_00a30880_Item* m_pInterpArray;
    void* unk18;
    float unk1c;
    void* unk20;
    unsigned int unk24;
    float unk28;
    float unk2c;
    float unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;

    void ReleaseItems();
};
struct SequenceA30970 : NiObject
{
    char* name08;
    unsigned int arraySize0c;
    unsigned int arrayGrow10;
    SeqInterpArrayItem* interpolators14;
    SeqIDTag* tags18;
    float weight1c;
    void* textKeys20;
    int cycleType24;
    float frequency28;
    float begin2c;
    float end30;
    float lastTime34;
    float accumulated38;
    float scaled3c;
    float FUN_00a30970(float time, bool update);
};
struct FUN_00a30c80_shell
{
    bool FUN_00a30c80(void* arg);
};
struct FUN_00a30cc0_target
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual bool V23(void* pOther);
};
struct FUN_00a30cc0_cls
{
    FUN_00a30cc0_target* m_pKey0;
    FUN_00a30cc0_target* m_pKey4;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char m_bFlag0D;

    unsigned char Equals(FUN_00a30cc0_cls* other);
};
struct StreamView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(char*&);
};
struct RefView
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
    virtual bool v21(StreamView&);
};
struct ObjectView
{
    int vtable;
    int refs;
};
struct ItemView
{
    RefView* interpolator;
    RefView* controller;
    void* blend;
    unsigned int settings;
};
struct TagView
{
    char* object;
    char* property;
    char* type;
    char* controller;
    char* interpolator;
};
struct SequenceView : ObjectView
{
    char* name;
    unsigned int count;
    unsigned int grow;
    ItemView* items;
    TagView* tags;
    float weight;
    RefView* text;
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
    char* root;
    int unk60;
    int unk64;
    int unk68;
    RefView** notes;
    unsigned short noteCount;
    bool FUN_00a30ea0(StreamView&);
};
struct FixedStr
{
    char* m_handle;
    FixedStr() : m_handle((char*)(*reinterpret_cast<void * *>(&::DAT_0109b220)))
    {}
    static void AcquireReference(char* h)
    {
        if (h != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            InterlockedIncrement((long*)(h - 8));
    }
    static void DecRef(char* h)
    {
        if (h != (*reinterpret_cast<void * *>(&::DAT_0109b220)))
            InterlockedDecrement((long*)(h - 8));
    }
    FixedStr& operator=(const FixedStr& o)
    {
        char* h = o.m_handle;
        if (m_handle != h)
        {
            AcquireReference(h);
            DecRef(m_handle);
            m_handle = h;
        }
        return *this;
    }
};
struct FUN_00a312d0
{
    FixedStr m_kAVObjectName;
    FixedStr m_kPropertyType;
    FixedStr m_kCtlrType;
    FixedStr m_kCtlrID;
    FixedStr m_kInterpolatorID;
    FUN_00a312d0(const FixedStr& a, const FixedStr& b, const FixedStr& c, const FixedStr& d, const FixedStr& e);
};
extern int(* DAT_00fdf1c4)(void*);
struct S_00aa4060_Class
{
};
struct FUN_00a315b0_Elem
{
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;
};
class FUN_00a315b0_Base
{
  public:
};
class FUN_00a315b0_cls
{
  public:
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;

    FUN_00a315b0_cls* FUN_00a315b0(unsigned char acFlags);
};
struct a31740_Ref
{
    virtual void v00();
    virtual void Release();
    int refCount;
};
struct a31740_Mem
{
};
struct FUN_00a31740_cls
{
    a31740_Ref* m_pReference;

    void* FUN_00a31740(unsigned char acFlags);
};
extern int(* DAT_00fdf1c0)(void*);
extern int(* DAT_00fdf1c4)(void*);
struct FUN_00a317e0_ref
{
    virtual ~FUN_00a317e0_ref();
    virtual void DeleteThis();
    int m_uiRefCount;
};
struct FUN_00a317e0_interp
{
    void* m_spControllerInterpolator;
    void* unk04;
    void* unk08;
    void* unk0C;
};
struct FUN_00a317e0_tag
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
};
struct FUN_00a317e0_t
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    FUN_00a317e0_interp* m_pInterpArray;
    FUN_00a317e0_tag* m_pkIDTags;

    void AssignInterpolatorRef(int index, FUN_00a317e0_ref** output);
};
struct RefObj
{
    virtual void V00();
    virtual void Release();
    long m_iObjectReferenceCount;
};
struct SlotEntry
{
    RefObj* m_pEntryObject;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned char m_unk0c;
    unsigned char m_flag0d;
    unsigned char m_unk0e;
    unsigned char m_unk0f;
};
struct SlotInfo
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
};
struct FUN_00a32bc0_cls
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_uiItemCount;
    unsigned int m_unk10;
    SlotEntry* m_pSlots;
    SlotInfo* m_pInfos;

    int AssignSlot(RefObj* p1, unsigned int p2, unsigned char p3);
};
struct FUN_00a34480_obj
{
    virtual void V00();
    virtual void V01();
    virtual FUN_00a34480_obj* V02();
    FUN_00a34480_obj* m_pNext;
    unsigned short m_word08;
    unsigned short unk0a;
    float m_f0c;
};
struct FUN_00a34480_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned short m_word24;
    unsigned short unk26;
    float m_f28;

    bool AssignControllers(void* a1, FUN_00a34480_obj* a2);
    bool FUN_00a34480(void* a1, FUN_00a34480_obj* a2);
};
extern char DAT_01096678, DAT_0109666c;
extern char DAT_01096664, DAT_01044c94, DAT_01044c90, DAT_0109665c;
extern char DAT_01096654, DAT_01096648, DAT_0109663c;
extern char DAT_01096630, DAT_01096624;
struct OutputArray
{
    void* unk00;
    void** data;
    unsigned short capacity;
    unsigned short length;
    unsigned short populated;
    unsigned short growth;
    void Append(void* value)
    {
        unsigned int index = length;
        if (index >= capacity)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(index + growth);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(index, (*(char * *)(&value)));
    }
};
struct ControlItem
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned char unk0c;
    unsigned char priority;
    unsigned short unk0e;
};
struct TagItem
{
    const char* first;
    const char* second;
    const char* third;
    const char* fourth;
    const char* fifth;
};
void* __cdecl FormatStringWithType(const char*, void*);
struct Position
{
    unsigned int i;
    unsigned int tagOffset;
};
struct Sequence
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned int itemCount;
    void* unk10;
    ControlItem* controls;
    TagItem* tags;
    float mainWeight;
    void* unk20;
    void* interp;
    float fadeIn;
    float fadeOut;
    float duration;
    float offset;
    float rate;
    float extra3c;
    void* unk40;
    void* name;
    float start;
    float end;
    float total;
    void FUN_00a34540(OutputArray* output);
};
static const float g_fSeqNegInfinity = -3.402823466e+38f;
struct SeqA34f20;
struct SeqPtrArray
{
};
struct SeqOwner
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
    SeqPtrArray m_kPlayingSequences;
};
struct SeqA34f20
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    char* m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    void* m_pInterpArray;
    void* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fScaledLastTime;
    SeqOwner* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    float m_fDestinationFrame;
    SeqA34f20* m_pkTimeSyncSequence;


    __forceinline bool SetState(int eState)
    {
        bool bWasInactive = m_eAnimationState == 0;
        m_eAnimationState = eState;
        if (bWasInactive)
        {
            reinterpret_cast<::ActiveArray *>(&(m_pkOwnerManager->m_kPlayingSequences))->FindOrAdd((void *const &)((const ::SeqA34f20 *const &)(this)));
        }
        return bWasInactive;
    }

    bool StartSequence(char m_ucRegionPriority, bool bStartOver, float fWeight, float fEaseInTime,
                       SeqA34f20* pkTimeSyncSeq, bool bTransition);
};
struct SomeObjectB3718
{
    virtual void V00();
    virtual void V01();
    virtual void V02(void* pv, unsigned int ItemUpdateArray, int iFlag);
};
struct HolderB3718
{
    SomeObjectB3718* m_pEntryObject;
};
struct FUN_00a30750_shell
{
    char* m_kPointA[5];
    void FUN_00a30750();
};
struct EqObj
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
    virtual bool equal(EqObj* other);
};
struct TCEq
{
};
struct SeqTagCmp
{
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    bool equal(const SeqTagCmp& x) const
    {
        return a == x.a && b == x.b && c == x.c && d == x.d && e == x.e;
    }
};
struct SeqTK
{
    EqObj* p;
    operator EqObj*() const
    {
        return p;
    }
    EqObj* operator->() const
    {
        return p;
    }
};
struct SeqEqStand : SequenceA30970
{
    SeqTK& textKeys()
    {
        return *(SeqTK*)&textKeys20;
    }
    EqObj* owner40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    void* root5c;
    unsigned char FUN_00a30fb0(SeqEqStand* other);
};
extern const char str_01020fd4[];
extern const char str_01020fc8[];
extern const char str_01020fc0[];
extern const char str_01020fb8[];
extern const char str_01020fac[];
extern const char str_01020fa0[];
extern const char str_01020f94[];
extern const char str_0109655c[];
struct S_00a31140_Allocator
{
};
extern "C" void __cdecl FUN_00ec623a(void*, const char*, const char*, const char*);
void* __cdecl FormatStringWithType(const char* arg1, void* arg2);
// Copy a group of five ref-counted fixed strings (the ref count sits 8 bytes before the text).
class A1400FixedString
{
  public:
    A1400FixedString& operator=(const A1400FixedString& kOther)
    {
        if (m_pcHandle != kOther.m_pcHandle)
        {
            char* pcNew = kOther.m_pcHandle;
            if (pcNew != ::DAT_0109b220)
                InterlockedIncrement((long volatile*)(pcNew - 8));
            if (m_pcHandle != ::DAT_0109b220)
                InterlockedDecrement((long volatile*)(m_pcHandle - 8));
            m_pcHandle = pcNew;
        }
        return *this;
    }

    char* m_pcHandle;
};
class A1400StringGroup
{
  public:
    A1400FixedString m_kName0;
    A1400FixedString m_kName1;
    A1400FixedString m_kName2;
    A1400FixedString m_kName3;
    A1400FixedString m_kName4;

    A1400StringGroup& FUN_00a31400(const A1400StringGroup& kOther);
};
struct IStreamA33a50
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(IStreamA33a50*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* pv, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = uiBytes;
        m_uiStreamFlags += m_pfnRead(this, pv, uiBytes, &uiComponentSize, 1);
    }
};
struct StreamA33a50
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    unsigned int m_uiNifVersion;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    IStreamA33a50* m_pUnderlyingStream;
};
struct IDTagA33a50
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
    void ReadFromStream(StreamA33a50& kStream, unsigned int& uiPaletteLink);
};
struct AnimationSequence;
struct UpdateActiveArray
{
};
struct UpdateNote
{
    int unk00;
    int unk04;
    int unk08;
    float time;
};
struct UpdateNoteManager
{
};
struct UpdateOwner
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
    UpdateActiveArray active;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    UpdateNoteManager* noteManager;
};
struct AnimationSequence : S_00a30880_Base
{
    unsigned int refs;
    char* name;
    unsigned int count;
    unsigned int grow;
    void* interpolators;
    void* tags;
    float weight;
    void* keys;
    int cycle;
    float frequency;
    float begin;
    float end;
    float lastTime;
    float weightedTime;
    float scaledTime;
    UpdateOwner* owner;
    int state;
    float offset;
    float startTime;
    float endTime;
    float destFrame;
    AnimationSequence* partner;
    char* root;
    int unk60;
    int unk64;
    short noteIndex;
    unsigned short unk6a;
    UpdateNote** notes;
    unsigned short noteCount;
    float GetMorphedTime(AnimationSequence*, float);
    void FUN_00a34ba0(float time, bool update);
    __forceinline bool SetState(int value)
    {
        bool inactive = state == 0;
        state = value;
        if (inactive)
        {
            AnimationSequence* self = this;
            reinterpret_cast<::ActiveArray *>(&(owner->active))->FindOrAdd((void *const &)(self));
        }
        return inactive;
    }
};
struct RefObject
{
    virtual void Virtual0();
    virtual void Release();
    volatile long referenceCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
};
struct NiPointerRef
{
    RefObject* m_pObject;
    void operator=(RefObject* p)
    {
        RefObject* pOld = m_pObject;
        RefObject* pNew = p;
        if (pOld != pNew)
        {
            if (pOld)
                pOld->DecRefCount();
            m_pObject = pNew;
            if (pNew)
                pNew->IncRefCount();
        }
    }
};
struct NiItem
{
    unsigned int m0;
    NiPointerRef object4;
    unsigned int m8;
    unsigned int mc;
};
struct NiSequenceSource
{
    unsigned int unk00;
    unsigned int type04;
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
    unsigned int versionD8;
};
struct SequenceLink : NiObject
{
    unsigned int unk08;
    unsigned int count0c;
    unsigned int unk10;
    NiItem* items14;
    unsigned int unk18;
    unsigned int unk1c;
    NiPointerRef object20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    RefObject* object40;
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
    NiPointerRef* objects6c;
    unsigned short count70;
    void LinkSequenceSource(NiSequenceSource*);
};
extern int(* DAT_00fdf1c0)(void*);
struct A33950RefObject
{
    virtual void Unused();
    virtual void Release();
    volatile long refCount;
};
struct A33950BinaryInput
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* readFn)(A33950BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* destination, unsigned int bytes)
    {
        unsigned int componentSize = bytes;
        position += readFn(this, destination, bytes, &componentSize, 1);
    }
};
struct A33950Stream
{
    unsigned int& Version()
    {
        return *(unsigned int*)((char*)this + 0xd8);
    }
    unsigned int& Count()
    {
        return *(unsigned int*)((char*)this + 4);
    }
    A33950BinaryInput* Input()
    {
        return *(A33950BinaryInput**)((char*)this + 0x24c);
    }
};
struct A33950Object
{
    A33950RefObject* first;
    A33950RefObject* second;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char flag0d;
    void LoadFromStream(A33950Stream* stream);
};
struct FUN_00a344f0_cls
{
    void* FUN_00a344f0(unsigned int param);
};
struct FUN_00a350d0_seq : SeqA34f20
{
    bool FUN_00a350d0(SeqA34f20* pkTarget, float fTime, float m_fTimeout, int iPriority, float fSeqWeight,
                      float fTargetWeight, SeqA34f20* pkPartner);
};


struct MemoryManager
{
};


struct SeqFixedString
{
    char* m_kHandle;

    SeqFixedString() : m_kHandle((char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
    {}
    SeqFixedString& operator=(const SeqFixedString& kString)
    {
        if (m_kHandle != kString.m_kHandle)
        {
            char* kHandle = kString.m_kHandle;
            if (kHandle != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
                InterlockedIncrement((long volatile*)(kHandle - 8));
            if (m_kHandle != (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220)))
                InterlockedDecrement((long volatile*)(m_kHandle - 8));
            m_kHandle = kHandle;
        }
        return *this;
    }
};

struct SeqFixedHandle
{
    char* m_kHandle;
};

struct SeqNiObject
{
    SeqNiObject();
    virtual ~SeqNiObject();
    unsigned int m_uiRefCount;
};

struct SeqInterpItem
{
    void* m_spControllerInterpolator;
    void* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned short m_usFlags;

    SeqInterpItem();
    ~SeqInterpItem();
    static void* operator new[](size_t uiSize)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(uiSize);
    }
};

struct SeqTag
{
    SeqFixedString m_kAVObjectName;
    SeqFixedString m_kPropertyType;
    SeqFixedString m_kCtlrType;
    SeqFixedString m_kCtlrID;
    SeqFixedString m_kInterpolatorID;

    SeqTag();
    ~SeqTag();
    static void* operator new[](size_t uiSize)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(uiSize);
    }
};

struct SeqRefObj
{
    void* vt;
    unsigned int m_uiRefCount;
};
struct SeqPtr
{
    SeqRefObj* m_pObject;
    SeqPtr(SeqRefObj* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            InterlockedIncrement((long volatile*)&m_pObject->m_uiRefCount);
    }
};
struct ControllerSequence : SeqNiObject
{
    SeqFixedString m_kName;
    unsigned int m_uiNumControlledBlocks;
    unsigned int m_uiNumIDTags;
    SeqInterpItem* m_pInterpArray;
    SeqTag* m_pkSeqTagArray;
    float m_fWeight;
    SeqPtr m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency;
    float m_fFirstKeyTime;
    float m_fLastKeyTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fScaledLastTime;
    void* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset;
    float m_fStartTime;
    float m_fEndTime;
    float m_fDestinationFrame;
    void* m_pkTimeSyncSequence;
    SeqFixedHandle m_kAccumulationRootName;
    void* m_pkAccumulationRoot;
    void* m_spStringPalette;
    short m_sCurAnimNIdx;
    void* m_spAnimNotes;
    unsigned short m_usNumNotes;
    bool m_bRemoveActivatorsOnDeactivate;

    ControllerSequence(const SeqFixedString& kName, unsigned int uiArraySize, unsigned int uiArrayGrowBy);
    virtual ~ControllerSequence();
};

// @fnv 0x00a32a10
ControllerSequence::ControllerSequence(const SeqFixedString& kName, unsigned int uiArraySize,
                                       unsigned int uiArrayGrowBy)
    : m_uiNumControlledBlocks(uiArraySize), m_uiNumIDTags(uiArrayGrowBy), m_pInterpArray(0), m_pkSeqTagArray(0),
      m_fWeight(1.0f), m_fFrequency(1.0f), m_fFirstKeyTime(DAT_01096548)
{
    m_eAnimationCycleType = 0;
    m_pkOwnerManager = 0;
    float fInvalid = DAT_01015f5c;
    m_eAnimationState = 0;
    m_fLastKeyTime = fInvalid;
    m_fLastTime = fInvalid;
    m_fWeightAdjustedLastTime = fInvalid;
    m_fScaledLastTime = fInvalid;
    m_fSequenceOffset = fInvalid;
    m_fStartTime = fInvalid;
    m_fEndTime = fInvalid;
    m_fDestinationFrame = fInvalid;
    m_pkTimeSyncSequence = 0;
    m_kAccumulationRootName.m_kHandle = (char*)(*reinterpret_cast<intptr_t *>(&::DAT_0109b220));
    m_pkAccumulationRoot = 0;
    m_spStringPalette = 0;
    m_sCurAnimNIdx = -1;
    m_spAnimNotes = 0;
    m_usNumNotes = 0;
    m_bRemoveActivatorsOnDeactivate = false;
    m_kName = kName;
    if (m_uiNumControlledBlocks > 0)
    {
        m_pInterpArray = new SeqInterpItem[m_uiNumControlledBlocks];
        m_pkSeqTagArray = new SeqTag[m_uiNumControlledBlocks];
    }
}

#include "generated/data/gamebryo2.2/corelibs/nianimation/nicontrollersequence_fpfast_noehsc_variant.inc"
