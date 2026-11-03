
// src/staging/blk_00820000_od_decl_variant.cpp - declaration variant unit created 2026-10-24 by decl_variants.py for paused function 0x0083d8b0: the skeleton of src/staging/blk_00820000_od.cpp
// with declarations corrected to what the original code does (layout_support.h: BSStringT(); ~BSStringT(); -> BSStringT(); BSStringT(const BSStringT&); ~BSStrin). Move the function to its real unit once
// that unit declares it this way.

// src/staging/blk_00820000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include <windows.h>
#include <objbase.h>
#include "fnv/decl/B83C270Conversation.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BasePinStub.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FORenderedMenu.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004615d0_shell.h"
#include "fnv/decl/FUN_00462d80_shell.h"
#include "fnv/decl/FUN_005215a0_shell.h"
#include "fnv/decl/FUN_00522440_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_0082f260_cls.h"
#include "fnv/decl/FUN_0083c750.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_009fdc10.h"
#include "fnv/decl/FUN_00ad78e0_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89b0_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8ad0_s.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8be0_shell.h"
#include "fnv/decl/FUN_00ad8c20_h.h"
#include "fnv/decl/FUN_00ad8c70_Class.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FUN_00ad9030_shell.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/ParticleEmitter.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/Radio652.h"
#include "fnv/decl/S2f760.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_00522470.h"
#include "fnv/decl/S_0082f1f0_Lock.h"
#include "fnv/decl/S_8c4f10_Cls.h"
#include "fnv/decl/SoundPlaybackManager.h"
#include "fnv/decl/SoundWrapper.h"
#include "fnv/decl/StandIn.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00454b10__TESObjectCELL.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_005de0f0__FUN_005de0f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0083b710__FUN_0083b710_cls.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/fnv_00ad8e20__FUN_00ad8e20_h.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e3000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_0082d000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00831000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_00839000.h"
#include "fnv/symbols_0083a000.h"
#include "fnv/symbols_00890000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_0107c000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "../../include/layout_support_decl_blk_00820000_od.h"
struct FUN_00821620_Class
{
    void FUN_00821620(float value);
};
struct FUN_00821680_Class
{
    float FUN_00821680() const;
};
struct FUN_008216a0_class
{
    float GetValue() const;
};
struct FUN_00824080_Class
{
    bool IsFlag200Set();
};
struct FUN_00827200_class
{
    void FUN_00cb26e0(int);
    FUN_00827200_class* FUN_00827200(int a);
};
struct FUN_0082d660_class
{
    char GetByteAtOffset44();
};
struct FUN_0082d6a0_Class
{
    unsigned short GetShortAt(int index);
};
struct FUN_0082d6c0_class
{
    unsigned short GetShortAtOffset5A();
};
struct FUN_0082d720_Class
{
    unsigned int FUN_0082d720();
};
extern int DAT_0107ca44;
void __cdecl InitArray(int);
struct FUN_0082ee80_class
{
    int* m_p;
    void InitArray(int);
    FUN_0082ee80_class* InitializeWithGlobal(int a);
};
struct FUN_0082f140_class
{
    void FUN_0082f140();
};
struct FUN_0082f190_class
{
    void FUN_0082f190();
};
struct RecursiveLock
{
};
struct CBSAStream
{
    void FUN_0082f1d0();
};
struct FUN_0082f520Class
{
    void* p;
    void* FUN_0082f520(void* v);
};
struct FUN_00831e00_class
{
    int IsFlagSet();
};
struct FUN_00831f40_Class
{
    void FUN_00831f40(int a, int b);
};
struct FUN_008321c0_Class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void FUN_008321c0();
};
struct BGSLoadFormBuffer
{
};
struct FUN_00836240
{
};
struct FUN_00836630
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};
extern int DAT_011a1888[];
void FUN_00837500();
extern "C" void* DAT_0107d9c4;
struct FUN_0083b5e0_class
{
    void* m_ptr;
    void InitBuffer(int);
    void* FUN_0083b5e0(int a);
};
struct S7010
{
};
struct FUN_0083dea0_class
{
    unsigned int FUN_0083dea0();
};
extern void* DAT_0107ca64;
struct FUN_0082efb0
{
    void FUN_0082efb0_init();
};
struct FUN_00438690
{
    ~FUN_00438690();
};
struct FUN_00822630
{
    ~FUN_00822630();
};
struct FUN_008224b0_Class
{
    FUN_00822630 a;
    int pad[3];
    FUN_00438690 b;
    ~FUN_008224b0_Class();
};
struct GO
{
    ~GO();
    GO* FUN_008228f0(unsigned int flags);
};
struct FUN_0082eee0_class
{
    void* InitArray(int size);
};
struct FUN_00831f80_class
{
    void* FUN_00831f80(unsigned int flags);
};
extern int DAT_0107cd54;
extern int DAT_0107cd6c;
extern int DAT_0107cdac;
struct FUN_00831fb0_class
{
    void* vtbl;
    int a;
    int b;
    int c;
    int d;
    void FUN_00831fb0();
};
struct BGSSaveFormBuffer
{
};
struct FUN_00836600_class
{
    void FUN_00836600(BGSLoadFormBuffer* buffer);
};
struct FUN_00837280_Class
{
    char FUN_00837280();
};
struct FUN_0083b740_Class
{
    void* FUN_0083b740(unsigned int flags);
};
struct SoundPlaybackHandle
{
    int x;
    int y;
    int z;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
public:
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
public:
    bool IsValid() const;
public:
    bool Release();
};
struct FUN_0083b770
{
    SoundPlaybackHandle a;
    SoundPlaybackHandle b;
    FUN_0083b770();
};
struct Date
{
    ~Date();
};
struct FUN_0083b7d0
{
    Date a;
    int b;
    int c;
    Date d;
    ~FUN_0083b7d0();
};
struct FUN_0083c750_class
{
    void* FUN_0083c720(unsigned int flags);
};
enum ENUM_FORM_ID;
struct TESForm
{
    virtual ~TESForm();
public:
    ::ENUM_FORM_ID GetFormType() const;
};
struct TESObjectREFR : TESForm
{
    virtual ~TESObjectREFR();
};
struct FUN_0083d0d0_Class
{
    void RefreshObjectRef(int a);
};
struct WeatherEntry
{
    int a;
    int b;
    int c;
    WeatherEntry();
};
struct G2
{
    void AddHead(WeatherEntry**);
};
struct FUN_00824290_class
{
    void AddWeatherEntry(int a, int b, int c);
};
struct SoundDataDummy
{
    char pad[28];
    int a;
    int b;
};
struct TESSound
{
public:
    unsigned char GetField45();
};
bool FUN_0082d740(TESSound* self, int* outA, int* outB);
struct BSAudio
{
};
struct EffectSetting
{
};
struct TESObject
{
};
struct SndX
{
    int a, b, c;
    void Stop();
};
struct SndItem
{
    TESObject* obj;
    SndX first;
    SndX second;
    bool active;
};
struct ContNode
{
};
bool FUN_008256d0(ContNode*);
struct Q
{
    ~Q();
};
struct S_00836470
{
    Q* m_p;
    int m_iWordAt04;
    unsigned int m_uiCommandId;
    int m_uiItemCount;
    int m_10;
    int m_14;
    ContNode m_kNode;
    void UpdateSoundItems(int);
};
struct TESTopic : TESForm
{
    virtual ~TESTopic();
};
struct TESTopicInfo : TESForm
{
    virtual ~TESTopicInfo();
};
struct TESQuest : TESForm
{
    virtual ~TESQuest();
};
struct BGSLoadGameBuffer
{
};
struct FUN_0083d1e0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    FUN_0083d1e0();
};
struct DialogueResponseList
{
    FUN_0083d1e0* item;
    DialogueResponseList* next;
    void AddTail(FUN_0083d1e0* const& data);
};
struct DialogueItem_shell
{
    DialogueResponseList responses;
    unsigned int unk08;
    TESTopicInfo* topicInfo;
    TESTopic* topic;
    TESQuest* quest;
    unsigned int speaker;
    void LoadDialogueItem(BGSLoadFormBuffer* buffer);
};
struct ListX
{
    ~ListX();
};
struct FUN_00836030_class
{
    Q* a;
    Q* b;
    int pad[4];
    ListX c;
    ~FUN_00836030_class();
};
struct SL
{
    SL();
    int alignment;
};
struct FUN_00822a40_Class
{
    int* vtbl;
    unsigned char flag4;
    unsigned char flag5;
    SL sl;

    FUN_00822a40_Class();
};
extern int DAT_0107bc28;
struct FUN_0080d930
{
    ~FUN_0080d930();
};
struct FUN_00825740 : FUN_0080d930
{
    ~FUN_00825740();
};
struct BE
{
    void* vtable;
    void* field_04;
    void* field_08;

    BE(unsigned char value);
    ~BE();
};
struct BCaster_S
{
    void* vtable;
    void* field_04;
    void* field_08;

    BCaster_S();
    ~BCaster_S();
};
extern int DAT_0107be2c;
extern int DAT_0107be80;
extern int _data_011c16bc;
struct FUN_00825a10 : BE
{
    BCaster_S m_caster;
    int m_18;
    int m_1c;
    int m_20;

    FUN_00825a10();
};
extern int DAT_0107bf1c;
struct MagicCaster;
struct MagicItem;
struct EffectItem;
struct ActiveEffect
{
    void* vtbl;
    ActiveEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};
struct FUN_008260b0 : ActiveEffect
{
    FUN_008260b0(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};
struct FUN_0082b370
{
    unsigned char _pad[0x4c];
    FUN_0082b370(int a, int b, int c);
};
FUN_0082b370* CreateFUN0082b370(int a, int b, int c);
struct FUN_0082cf80
{
    unsigned char m_data[0x48];
    FUN_0082cf80(int, int, int);
};
void* __cdecl CreateFUN0082cf80(int a, int b, int c);
struct FUN_0082d6e0_Class
{
    unsigned char GetHighByteOfField4E();
};
struct GlobalObject_0082ee80
{
    ~GlobalObject_0082ee80();
    GlobalObject_0082ee80* FUN_0082eeb0(unsigned int flags);
};
struct FUN_0082efb0_Ext : FUN_0082efb0
{
    FUN_0082efb0* FUN_0082efe0(unsigned int flags);
};
struct FUN_0082f160_class : public FUN_0082f140_class
{
    void* FUN_0082f160(unsigned int flags);
};
struct FUN_0082f260_class
{
    void* FUN_0082f210(unsigned int flags);
};
struct FUN_00831de0_Class
{
    char m_00[0x14];
    FUN_00831e00_class m_14;
    int ForwardToMember();
};
typedef void(* FUN_00831eb0_callback)(void*, int, int);
struct FUN_00831ee0_class
{
    virtual void FUN_00831ee0_virtual0();
    virtual void FUN_00831ee0_virtual1();
};
struct BSSimpleListEx
{
    virtual ~BSSimpleListEx();
};
struct FUN_00837480 : BSSimpleListEx
{
    void* DeleteThis(unsigned int flags);
};
struct GlobalObject_0083b5e0
{
    ~GlobalObject_0083b5e0();
    void* FUN_0083b610(unsigned int flags);
};
struct BSStr
{
};
struct BGSLoadGameBufferHelper
{
};
struct TESIdleForm : TESForm
{
    virtual ~TESIdleForm()
    {}
};
struct FUN_0083d740_Class
{
    void FUN_0083d740(BGSLoadGameBuffer* buffer);
};
struct Str6a70
{
    Str6a70& operator=(char const*);
};
struct BGSLoadGameBufferLoadStringHelper
{
};
struct BGSLoadFormBufferHelper
{
};
extern void* _DAT_01183028;
struct FUN_0083fbe0_Class
{
    void FUN_0083fbe0(BGSLoadGameBuffer* buffer);
};
// FUN_00822440 - 0x00822440, 99 bytes.
//
// The constructor of the game class that owns
//   +0x00  BSSimpleArray<void*, 0xEAA>   (vftable 0x0107b84c, ctor 0x00822600,
//                                          dtor 0x00822630)
//   +0x10  BSSimpleArray<int, 0xEAA>     (vftable 0x01016024, ctor 0x00438660,
//                                          dtor 0x00438690)
//   +0x20  int                           (zeroed by the constructor)
//
// The class itself is NOT polymorphic: the original's constructor never writes
// a vftable pointer of its own, the vtable at +0x00 comes from the
// BSSimpleArray<void*> MEMBER constructor at 0x00822600.  The matching
// destructor is 0x008224b0; it destroys the members in reverse order
// (0x00438690 at +0x10 first, then 0x00822630 at +0x00).
//
// The original's code:
//   push ebp / mov ebp,esp / push -1 / push __ehhandler$ / mov eax,fs:[0] /
//   push eax / push ecx / mov eax,[__security_cookie] / xor eax,ebp /
//   push eax / lea eax,[ebp-0xc] / mov fs:[0],eax
//   mov  [ebp-0x10],ecx                 ; the /Od home slot of `this`
//   mov  ecx,[ebp-0x10] / call 0x822600 ; BSSimpleArray<void*> ctor
//   mov  dword ptr [ebp-4],0           ; EH state variable
//   mov  ecx,[ebp-0x10] / add ecx,0x10 / call 0x438660 ; BSSimpleArray<int> ctor
//   mov  eax,[ebp-0x10] / mov dword ptr [eax+0x20],0
//   mov  dword ptr [ebp-4],-1          ; EH state variable
//   mov  eax,[ebp-0x10] / mov ecx,[ebp-0xc] / mov fs:[0],ecx /
//   pop ecx / mov esp,ebp / pop ebp / ret
//
// The class name has to carry the FUN_00822440 tag (the constructor's mangled
// name is the only symbol the checker can find), so the destructor is DECLARED
// but never defined: an undefined destructor is never emitted into the object
// file, which keeps exactly ONE defined function symbol carrying the tag.
// Stand-in for BSSimpleArray<void*, 0xEAA>.
struct FnvSimpleArrayPtr
{
    void** m_ppVirtualMethodTable;
    void* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    FnvSimpleArrayPtr();
    ~FnvSimpleArrayPtr();
};
// Stand-in for BSSimpleArray<int, 0xEAA>.
struct FnvSimpleArrayInt
{
    void** m_ppVirtualMethodTable;
    int* m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    FnvSimpleArrayInt();
    ~FnvSimpleArrayInt();
};
struct FUN_00822440_Class
{
    FnvSimpleArrayPtr m_arrPtr;  // +0x00
    FnvSimpleArrayInt m_arrInt;  // +0x10
    int m_unk20;                 // +0x20
    FUN_00822440_Class();
    ~FUN_00822440_Class();
};
struct PrimaryBase_b5774
{
    virtual ~PrimaryBase_b5774();
    unsigned int unk04;
    unsigned int unk08;
};
struct SecondaryBase_b5774
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ~SecondaryBase_b5774();
};
struct GlobalMgr_b5774
{
};
struct Holder_b5774
{
    void Release();
};
class FUN_00825b60 : public PrimaryBase_b5774, public SecondaryBase_b5774
{
  public:
    Holder_b5774* m_20;
    virtual ~FUN_00825b60();
};
struct S_00825ea0_A
{
    unsigned char unk04;
    int unk08;
    S_00825ea0_A(unsigned char c);
    virtual ~S_00825ea0_A();
};
struct S_00825ea0_B
{
    unsigned char unk04;
    unsigned char unk05;
    int unk08;
    int unk0c;
    S_00825ea0_B();
    virtual ~S_00825ea0_B();
};
struct S_00825ea0_P
{
    int unk00;
    int unk04;
    S_00825ea0_P();
};
struct FUN_00825ea0 : S_00825ea0_A, S_00825ea0_B
{
    int unk1c;
    S_00825ea0_P unk20;
    FUN_00825ea0();
    virtual ~FUN_00825ea0();
};
struct SoundDataEx
{
    unsigned int unk00;
    unsigned int flags;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
};
struct TESSoundEx : TESSound
{
};
struct DataHandler
{
};
int strcpy_s(char* dest, unsigned int size, const char* src);
struct Base_82efb0
{
    virtual ~Base_82efb0();
};
struct FUN_0082ef50 : public Base_82efb0
{
    void RemoveAll();
    virtual ~FUN_0082ef50();
};
extern "C" void* __cdecl FUN_00afdf20(const char*, int, int, int);
struct FNVHandle
{
    virtual ~FNVHandle();
};
struct FUN_0082f240
{
    FUN_0082f240();
    virtual ~FUN_0082f240();
};
struct FUN_0044fae0
{
    FUN_0044fae0();
    ~FUN_0044fae0();
    unsigned int state00;
    unsigned int state04;
    unsigned int state08;
    unsigned int state0c;
    unsigned int state10;
    unsigned int state14;
    unsigned int state18;
    unsigned int state1c;
    unsigned int state20;
};
struct FUN_0082f010 : FUN_0082f240
{
    char path[0x104];
    FNVHandle* handle;
    FUN_0044fae0 lock;
    unsigned __int64 counter;
    FUN_0082f010(const char* pathName);
    virtual ~FUN_0082f010();
};
struct ProbeTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14(int a, int b);
};
class FUN_0082f310_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    ProbeTarget* m_108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    __int64 m_128;
    __int64 m_130;

  public:
    int FUN_0082f310(__int64 value);
};
struct StreamLock
{
    void* m_cs;
    StreamLock(void* cs);
    ~StreamLock();
};
struct StreamFile
{
};
struct ArchiveStream
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
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
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
    StreamFile* file;
    int lock;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    __int64 size;
    __int64 pos;
    int FUN_0082f3c0(void* buffer, unsigned int count, int unused, unsigned int* bytesRead);
};
// FUN_0082f6c0 @ 0x0082f6c0 (size 150)
// Base-object destructor of a thread-like class: clears the "running" flag bit,
// signals the object at +0x34, waits for the worker thread to leave, closes its
// handle, then runs the base class destructor.
struct FUN_00aa63c0
{
    virtual ~FUN_00aa63c0();
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
};
struct FUN_0082f6c0 : FUN_00aa63c0
{
    void* unk30;
    int unk34;
    int unk38;
    unsigned int unk3C;

    virtual ~FUN_0082f6c0();
};
struct FUN_0082f9c0_obj
{
    virtual int unk00(int a);
};
int FUN_00831f70(int unused);
// PlayWeaponSound v2 (worker11): pack types reused; extra callees via shell classes
struct NiPoint3
{
    float x, y, z;
    NiPoint3();
public:
    static const ::NiPoint3 ZERO;
};
struct Vec3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& rhs) const;
public:
    Vec3();
};
struct AudioPlaybackHandle;
struct SndXShell
{
};
struct Entry
{
    SndX ch0;
    SndX ch1;
    void* f18;
    unsigned int f1c;
    float f20;
};
struct GlobalObject_0041a250
{
    int f00, f04, f08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};
struct AudioPlaybackHandle
{
    int f00, f04, f08;
    ~AudioPlaybackHandle();
};
struct BSAudioShell
{
};
struct TESSoundShell
{
};
struct Weap
{
};
struct VObj1d0
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
    virtual void* VCall1d0();
};
struct VObj148
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
    virtual void* VCall148();
};
struct ProcResult
{
};
struct Cell
{
};
struct Player
{
};
struct ListObj
{
};
struct SettingObj
{
};
bool __cdecl FUN_00839da0();
extern Entry DAT_011dd9e8[20];
class B3B6B0MapBase
{
  public:
    virtual ~B3B6B0MapBase();

    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_0083b6b0 : public B3B6B0MapBase
{
  public:
    virtual ~FUN_0083b6b0();
};
struct FUN_0083da30_cls
{
    int m_00;

    int ApplyMaskedOffset(int aValue);
};
struct EffectTime
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
    float time38;
    unsigned int unk3C, unk40, unk44;
    float time48;
};
struct EffectHandle
{
};
struct SpellTimes
{
};
struct EffectCollection
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};
struct FUN_008216c0_shell
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    bool reset;
    unsigned int unk2C;
    SpellTimes* spell;
    float time;
    EffectCollection effects;
    EffectHandle active;
    void UpdateEffectTimes();
};
// Minimal declarations for the process list and its polymorphic entries.
class MobileObject
{
  public:
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual bool IsActor();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual bool IsMagicProjectile();
};
class Actor : public MobileObject
{
  public:
};
class MagicProjectile : public MobileObject
{
  public:
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void UpdateCaster(BCaster_S* caster);
};
struct MobileObjectProcessArray
{
};
struct ProcessRegistry
{
};
struct CasterUpdate : BE, BCaster_S
{
    void UpdateCasters();
};
struct SoundFormData
{
    unsigned char ucMinAtten;
    unsigned char ucMaxAtten;
    unsigned char ucStaticAtten;
    unsigned char ucPad03;
    unsigned int uiFlags;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct SoundForm
{
};
struct GameSound
{
};
class Thread82F
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual unsigned int GetPosition();

};
class Stream82F
{
  public:
    unsigned __int64 GetStreamPosition(unsigned __int64* puiPosition);

    void* m_ppVirtualMethodTable;
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
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
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
    Thread82F* m_pBackgroundLoadThread;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    unsigned __int64 m_uiPosition;
};
struct AudGuid
{
    unsigned long d0;
    unsigned long d1;
    unsigned long d2;
    unsigned long d3;
};
struct IAudUnk
{
    virtual long QueryInterface(const AudGuid& iid, void** out);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};
struct IAudGraph : IAudUnk
{
    virtual long AddFilter(IAudUnk* filter, const wchar_t* name);
};
struct IAudBuilder : IAudUnk
{
    virtual long v0C();
    virtual long v10();
    virtual long v14();
    virtual long v18();
    virtual long v1C();
    virtual long v20();
    virtual long v24();
    virtual long v28();
    virtual long v2C();
    virtual long Render(IAudUnk* pin);
};
struct IAudDispatch : IAudUnk
{
    virtual long d0C();
    virtual long d10();
    virtual long d14();
    virtual long d18();
};
struct IAudBasicAudio : IAudDispatch
{
    virtual long put_Volume(long volume);
};
struct IAudControl : IAudDispatch
{
    virtual long Run();
    virtual long Pause();
    virtual long Stop();
};
struct IAudPosition : IAudDispatch
{
    virtual long get_Duration(double* len);
    virtual long put_CurrentPosition(double t);
    virtual long get_CurrentPosition(double* t);
};
struct IAudEvent : IAudDispatch
{
    virtual long e1C();
    virtual long GetEvent(long* code, long* p1, long* p2, long timeout);
    virtual long e24();
    virtual long e28();
    virtual long e2C();
    virtual long FreeEventParams(long code, long p1, long p2);
};
struct AudMediaType
{
    AudGuid majortype;
    AudGuid subtype;
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
    AudMediaType();
    ~AudMediaType();
};
struct AudReader
{
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    AudReader(char* path);
    virtual ~AudReader();
    bool IsOpen();
};
struct AudPinBase
{
    virtual void p00();
    int unk04;
    int unk08;
};
struct AudPin : AudPinBase, IAudUnk
{
};
struct AudFilterBase
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0C();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual AudPin* GetPin(int index);
    int unk04;
    int unk08;
};
struct AudFilter : AudFilterBase, IAudUnk
{
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
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    AudFilter(AudReader* reader, AudMediaType* mt, long* hr);
};
struct AudSetting
{
};
struct AudTimer
{
    void Reset();
};
extern int DAT_011dd370;
extern void* DAT_011dd3b0;
extern AudGuid DAT_0107cae8;
extern AudGuid DAT_0107caf8;
extern AudGuid DAT_0107cb18;
extern AudGuid DAT_01093c0c;
extern AudGuid DAT_01093b5c;
extern AudGuid DAT_0107cad8;
extern AudGuid DAT_0107caa8;
extern AudGuid DAT_0107cac8;
extern AudGuid DAT_0107cab8;
extern float DAT_011dd300;
extern float DAT_011dd304;
extern float DAT_011dd308;
extern char DAT_011dd310;
extern float DAT_011dd338;
extern float DAT_011dd33c;
extern float DAT_011dd340;
extern char DAT_011dd311;
struct FUN_00831f10_Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
};
struct SaveFormBufferEx : BGSSaveFormBuffer
{
    unsigned int GetPosition();
};
struct SoundForm;
struct SoundEntry
{
    SoundForm* form;
};
struct SoundListNode
{
};
struct SoundQueue
{
};
struct SoundTimer
{
    SoundQueue* m_queue;
    int unk04;
    unsigned int m_uiStartTime;
    int m_fAnimationDuration;
    unsigned char m_flag10;
    unsigned char m_flag11;
    int unk14;
    SoundListNode m_kNode;
    void FUN_00836110(SaveFormBufferEx* buffer);
};

// These declarations name the existing BSStringT ABI accessors omitted from
// the supplied class declaration; they add no storage or replacement bodies.
struct StringAccess530
{
};
struct BraceString530 : BSStringT<char>
{
    BSStringT<char> FUN_0083d8b0();
};
// @fnv 0x0083d8b0
BSStringT<char> BraceString530::FUN_0083d8b0()
{
    unsigned int output6 = 0;  // next output character
    int depth_ = 0;            // nesting depth
    unsigned int index4;       // input character index
    BSStringT<char> result;
    reinterpret_cast<::TextString *>(&(result))->FUN_004037f0(((const char *)(::FUN_00559450((int *)this))), 0);
    for (index4 = 0; index4 < ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((StringAccess530*)this)))->FUN_004048e0())); ++index4)
    {
        if (((const char *)(::FUN_00559450((int *)this)))[index4] == '{')
        {
            ++depth_;
        }
        else if (((const char *)(::FUN_00559450((int *)this)))[index4] == '}')
        {
            depth_ = depth_ == 0 ? 0 : depth_ - 1;
        }
        if (depth_ == 0)
        {
            if (((const char *)(::FUN_00559450((int *)this)))[index4] != '}')
            {
                *((char *)(reinterpret_cast<::FUN_0083da30_cls *>((((StringAccess530*)&result)))->ApplyMaskedOffset(output6))) = ((const char *)(::FUN_00559450((int *)this)))[index4];
                ++output6;
            }
        }
    }
    if (output6 < ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((StringAccess530*)&result)))->FUN_004048e0())))
    {
        *((char *)(reinterpret_cast<::FUN_0083da30_cls *>((((StringAccess530*)&result)))->ApplyMaskedOffset(output6))) = 0;
    }
    result.SetLength(output6);
    return result;
}
