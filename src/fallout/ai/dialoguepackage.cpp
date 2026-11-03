// fallout/ai/dialoguepackage.cpp: DialoguePackage, DelStandIn, This, DialoguePackageState (18 functions)

#include "fnv/save_load_game_view.h"
#include <cstdint>
#include <new>
#include "fnv/decl/A90Cls.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/B83C270Conversation.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/CVConv.h"
#include "fnv/decl/Conversation.h"
#include "fnv/decl/ConversationLoad.h"
#include "fnv/decl/Conversation_Stub.h"
#include "fnv/decl/DialogueItem.h"
#include "fnv/decl/DialogueItemList.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00484d20_Class.h"
#include "fnv/decl/FUN_00484d40_Host.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00516bf0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_006727b0_shell.h"
#include "fnv/decl/FUN_00678fd0_shell.h"
#include "fnv/decl/FUN_006796c0_shell.h"
#include "fnv/decl/FUN_006797c0_shell.h"
#include "fnv/decl/FUN_00705b10_Dummy.h"
#include "fnv/decl/FUN_0083b9f0_shell.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0083c850.h"
#include "fnv/decl/FUN_0083c900_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a5cf0_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00934250_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8be0_shell.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Mid83b9a0.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/Package679120.h"
#include "fnv/decl/Package6798c0.h"
#include "fnv/decl/PackageCopy.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StandIn.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00679340__Package679.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0083c330__FUN_0083c330_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00adbfd0__FUN_00adbfd0_cls.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_008c1000.h"
#include "fnv/symbols_00935000.h"
#include "fnv/symbols_00936000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "dialoguepackage_decls.h"

// @fnv 0x004d52d0
BGSTerrainManager* LoadBGSTerrainManager(const NiPointer<NiNode>& apNode)
{
    return LoadBGSTerrainManager(reinterpret_cast<const char*>(apNode.operator->()));
}

// @fnv 0x009ee040
intptr_t FUN_009ee040(char* pThis)
{
    return *(int*)(pThis + 0xb0);
}

namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x009edd50
void* DelStandIn::Destroy(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct BSBound;
struct Date
{
    char b[0x24];
    ~Date();
};
struct Q
{
    ~Q();
};
struct FUN_006708b0
{
    virtual void Dummy();
    char pad[0x7c];
    ~FUN_006708b0();
};
struct PC7d
{
    char pad[0x208];
    void* f208;
    BSBound* GetObjectBounds();
    void SetBoundingBox(BSBound*);
};
struct FUN_009edf40 : public FUN_006708b0
{
    Date d;
    Q* p;
    ~FUN_009edf40();
};
// @fnv 0x009edf40
FUN_009edf40::~FUN_009edf40()
{
    if (this == (*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))->f208)
        (*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))->f208 = 0;
    if ((void*)this == (void*)reinterpret_cast<::MiddleHighProcess *>(((*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))))->GetObjectBounds())
        reinterpret_cast<::MiddleHighProcess *>(((*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))))->SetBoundingBox(0);
    delete p;
}

struct FUN_009edd30_shell
{
    bool IsPointerMatch(const void* p);
    unsigned int pad00[0x2c];
    void* unkb0;
};

// Returns whether p equals the pointer stored at offset 0xb0 of this object.
// @fnv 0x009edd30
bool FUN_009edd30_shell::IsPointerMatch(const void* apValue)
{
    return apValue == this->unkb0;
}

struct FUN_009ef510_shell
{
    unsigned char GetByteAtBC();
    char pad00[0xbc];
    unsigned char unkbc;
};

// @fnv 0x009ef510
unsigned char FUN_009ef510_shell::GetByteAtBC()
{
    return this->unkbc;
}

struct FUN_008e95c0_shell
{
    unsigned char m_ucUnknownByte[0xbf];
    bool m_bFlag;
    bool FUN_008e95c0();
};

// @fnv 0x008e95c0
bool FUN_008e95c0_shell::FUN_008e95c0()
{
    return m_bFlag;
}

struct SL
{
    SL();
    int _a;
    int _b;
};
struct FUN_0083b830 : SL
{
    int _c;
    FUN_0083b830();
};
// Initializes the _c member to 0.
// @fnv 0x0083b830
FUN_0083b830::FUN_0083b830()
{
    _c = 0;
}

struct DialoguePackage : TESForm
{
    void FUN_009ee060(TESForm* apCopy);
};
// Calls CopyFromPackage on apCopy, then dynamic_casts apCopy to DialoguePackage and stores the result in pcopy.
// @fnv 0x009ee060
void DialoguePackage::FUN_009ee060(TESForm* apCopy)
{
    reinterpret_cast<::PackageCopy *>(this)->CopyFromPackage(apCopy);
    DialoguePackage* pSourcePackage = dynamic_cast<DialoguePackage*>(apCopy);
}

namespace fnv_009ef530 {
struct MobileObject
{
};

struct FUN_009ef530_cls
{
    char pad[0x94];
    MobileObject* m_mobile;
    void FUN_009ef530();
};

// If m_mobile is set, calls FUN_00934250 on it.
// @fnv 0x009ef530
void FUN_009ef530_cls::FUN_009ef530()
{
    if (m_mobile)
        reinterpret_cast<::FUN_00934250_shell *>((m_mobile))->FUN_00934250();
}
}  // namespace fnv_009ef530

namespace fnv_009f01d0 {
class TESTopic;
class MobileObject;
class TESObjectREFR;
struct DialogueItem;
struct DialogueResponse;

struct FUN_006797c0_shell
{
};

struct BGSSaveFormBuffer
{
};

struct Conversation_Stub
{
};

struct FUN_0083c900_shell
{
};

struct DialoguePackage
{
    void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    char pad00[0x98];
    char unk98;
    char pad99[0x7];
    char unka0;
    char pada1[0x1b];
    char unkbc;
    char unkbd;
    char unkbe;
    char unkbf;
    char unkc0;
    char unkc1;
    char unkc2;
    char padc3[0x9];
    char unkcc;
};

// @fnv 0x009f01d0
void DialoguePackage::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    bool bhasConversation;

    reinterpret_cast<::FUN_006797c0_shell *>((((FUN_006797c0_shell*)this)))->FUN_006797c0((::FUN_006797c0_arg *)(apSaveGameBuffer));
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)((*(MobileObject**)((char*)this + 0x94))), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)((*(MobileObject**)((char*)this + 0xb0))), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)((*(MobileObject**)((char*)this + 0xb4))), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)((*(MobileObject**)((char*)this + 0xb8))), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)((*(TESObjectREFR**)((char*)this + 0x9c))), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)((*(TESTopic**)((char*)this + 0x8c))), 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(*(int*)((char*)this + 0x90)), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unk98), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unkbc), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unkbd), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unkbe), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unkbf), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unkc0), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unkc1), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(*(int*)((char*)this + 0xc4)), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(*(int*)((char*)this + 0xc8)), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unka0), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unkcc), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&(this->unkc2), 1, 0);
    bhasConversation = (*(Conversation_Stub**)((char*)this + 0xa4));
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&bhasConversation, 1, 0);
    if (bhasConversation)
    {
        short scurrentResponseIndex;
        short scurrentItemIndex;
        reinterpret_cast<::B83C270Conversation *>(((*(Conversation_Stub**)((char*)this + 0xa4))))->FUN_0083c270((::B83C270Buffer *)(apSaveGameBuffer));
        scurrentItemIndex =
            (*(DialogueItem**)((char*)this + 0xa8))
                ? reinterpret_cast<::Conversation_Stub *>(((*(Conversation_Stub**)((char*)this + 0xa4))))->FUN_0083ba50((::DialogueItem *)((*(DialogueItem**)((char*)this + 0xa8))))
                : -1;
        reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&scurrentItemIndex, 2, 0);
        scurrentResponseIndex = ((*(DialogueItem**)((char*)this + 0xa8)) && (*(DialogueResponse**)((char*)this + 0xac)))
                                    ? reinterpret_cast<::FUN_0083c900_shell *>((((FUN_0083c900_shell*)(*(DialogueItem**)((char*)this + 0xa8)))))->GetResponseIndex((::DialogueResponse *)((*(DialogueResponse**)((char*)this + 0xac))))
                                    : -1;
        reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&scurrentResponseIndex, 2, 0);
    }
}
}  // namespace fnv_009f01d0

namespace fnv_009ef560 {
struct TESSaveLoadGame
{
    void* GetHitSound();
};

struct SaveManager : public TESSaveLoadGame
{
};

struct Saver
{
};

struct Conversation
{
};

struct DialoguePackage : public Saver
{
    unsigned char padding[0xa3];
    Conversation* m_pkConversation;

    unsigned short FUN_009ef560();
};

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct Interface
{

};



// Accumulates the save size of the dialogue package from its saver, conversation and version-dependent fields, optionally logging the size and form details.
// @fnv 0x009ef560
unsigned short DialoguePackage::FUN_009ef560()
{
    unsigned short scurrentResponseIndex = 0;

    {
        unsigned short scurrentItemIndex;
        void* apSaveGameBuffer;
        TESForm* pForm;

        scurrentResponseIndex += reinterpret_cast<::FUN_00678fd0_shell *>(this)->FUN_00678fd0();
        scurrentItemIndex = scurrentResponseIndex;

        if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_009ef560::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
        {
            scurrentResponseIndex += 4;
            scurrentResponseIndex += 2;
        }

        scurrentResponseIndex += 4;

        if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_009ef560::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x6a)
        {
            scurrentResponseIndex += 1;
        }

        scurrentResponseIndex += 0x10;
        scurrentResponseIndex += 2;

        if (m_pkConversation)
        {
            scurrentResponseIndex += reinterpret_cast<::DialogueItemList *>((m_pkConversation))->FUN_0083bb30();
            scurrentResponseIndex += 2;
            scurrentResponseIndex += 2;
        }

        if (*(*reinterpret_cast<::fnv_009ef560::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool())
        {
            apSaveGameBuffer = (*reinterpret_cast<::fnv_009ef560::SaveManager * *>(&::g_TESSaveLoadGame))->GetHitSound();

            if (apSaveGameBuffer)
            {
                pForm = ::FUN_004839c0(*reinterpret_cast<unsigned int*>(apSaveGameBuffer));

                ::FUN_0040fbe0();
            }
            else
            {
                ::FUN_0040fbe0();
            }
        }
    }

    return scurrentResponseIndex;
}
}  // namespace fnv_009ef560

namespace fnv_009f0740 {
struct FUN_00679a90_shell
{
};

struct Conversation
{
};

struct DialoguePackage : public FUN_00679a90_shell
{
    unsigned char pad_0000[0x94];
    MobileObject* m_pkMobileObject;
    unsigned char pad_0098[4];
    TESObjectREFR* m_pkReference;
    unsigned char pad_00A0[4];
    Conversation* m_pkConversation;
    unsigned char pad_00A8[8];
    MobileObject* pActor;
    MobileObject* pTargetActor;
    MobileObject* m_pLinkedReference;

    void FUN_009f0740(BGSLoadFormBuffer*);
};


// Calls the base loader, resolves the stored form IDs to MobileObject/TESObjectREFR pointers, then loads the Conversation if present.
// @fnv 0x009f0740
void DialoguePackage::FUN_009f0740(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::A90Cls *>(this)->DispatchToSubobjects((intptr_t)(apLoadGameBuffer));

    m_pkMobileObject =
        m_pkMobileObject
            ? dynamic_cast<MobileObject*>(::FUN_004839c0((unsigned int)reinterpret_cast<std::uintptr_t>(m_pkMobileObject)))
            : 0;

    pActor = pActor ? dynamic_cast<MobileObject*>(::FUN_004839c0((unsigned int)reinterpret_cast<std::uintptr_t>(pActor))) : 0;

    pTargetActor = pTargetActor
                       ? dynamic_cast<MobileObject*>(::FUN_004839c0((unsigned int)reinterpret_cast<std::uintptr_t>(pTargetActor)))
                       : 0;

    m_pLinkedReference =
        m_pLinkedReference
            ? dynamic_cast<MobileObject*>(::FUN_004839c0((unsigned int)reinterpret_cast<std::uintptr_t>(m_pLinkedReference)))
            : 0;

    m_pkReference =
        m_pkReference ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)reinterpret_cast<std::uintptr_t>(m_pkReference)))
                      : 0;

    if (m_pkConversation)
    {
        reinterpret_cast<::Conversation *>((m_pkConversation))->FUN_0083c420(apLoadGameBuffer);
    }
}
}  // namespace fnv_009f0740

struct Obj114;
struct Handle114;
struct Vec114
{
    float x, y, z;
};
struct String114
{
    unsigned int data;
    unsigned int size;
    String114();            // 0x4037b0
    String114(String114*);  // 0x4047f0
    ~String114();           // 0x4037d0
    void FUN_00438470(String114*);
};
struct Handle114
{
    unsigned int a, b, c;
    Handle114(const Handle114&);  // 0x418900
    ~Handle114();                 // 0x483710
    Handle114& FUN_00ad7480();
};
struct Obj114
{
    virtual void virtual000();
    virtual void virtual004();
    virtual void virtual008();
    virtual void virtual00c();
    virtual void virtual010();
    virtual void virtual014();
    virtual void virtual018();
    virtual void virtual01c();
    virtual void virtual020();
    virtual void virtual024();
    virtual void virtual028();
    virtual void virtual02c();
    virtual void virtual030();
    virtual void virtual034();
    virtual void virtual038();
    virtual void virtual03c();
    virtual void virtual040();
    virtual void v44(Obj114*, int, int, int, int, int);
    virtual void virtual048();
    virtual void virtual04c();
    virtual void virtual050();
    virtual void virtual054();
    virtual void virtual058();
    virtual void virtual05c();
    virtual void virtual060();
    virtual void virtual064();
    virtual void virtual068();
    virtual void virtual06c();
    virtual void virtual070();
    virtual void virtual074();
    virtual void virtual078();
    virtual void virtual07c();
    virtual void virtual080();
    virtual void virtual084();
    virtual void virtual088();
    virtual void virtual08c();
    virtual void virtual090();
    virtual void virtual094();
    virtual void virtual098();
    virtual void virtual09c();
    virtual void virtual0a0();
    virtual void virtual0a4();
    virtual void virtual0a8();
    virtual void virtual0ac();
    virtual void virtual0b0();
    virtual void virtual0b4();
    virtual void virtual0b8();
    virtual void virtual0bc();
    virtual void virtual0c0();
    virtual void virtual0c4();
    virtual void virtual0c8();
    virtual void virtual0cc();
    virtual void virtual0d0();
    virtual void virtual0d4();
    virtual void virtual0d8();
    virtual void virtual0dc();
    virtual void virtual0e0();
    virtual void virtual0e4();
    virtual void virtual0e8();
    virtual void virtual0ec();
    virtual void virtual0f0();
    virtual void virtual0f4();
    virtual void virtual0f8();
    virtual void virtual0fc();
    virtual bool v100();
    virtual void virtual104();
    virtual void virtual108();
    virtual void virtual10c();
    virtual void virtual110();
    virtual void virtual114();
    virtual void virtual118();
    virtual bool v11c();
    virtual void virtual120();
    virtual void virtual124();
    virtual void virtual128();
    virtual void virtual12c();
    virtual void virtual130();
    virtual void virtual134();
    virtual void virtual138();
    virtual void virtual13c();
    virtual void virtual140();
    virtual void virtual144();
    virtual void virtual148();
    virtual void virtual14c();
    virtual void virtual150();
    virtual void virtual154();
    virtual void virtual158();
    virtual void virtual15c();
    virtual void virtual160();
    virtual void virtual164();
    virtual void virtual168();
    virtual void virtual16c();
    virtual void virtual170();
    virtual void virtual174();
    virtual void virtual178();
    virtual void virtual17c();
    virtual void virtual180();
    virtual void virtual184();
    virtual void virtual188();
    virtual void virtual18c();
    virtual void virtual190();
    virtual void virtual194();
    virtual void virtual198();
    virtual void virtual19c();
    virtual void virtual1a0();
    virtual void virtual1a4();
    virtual void virtual1a8();
    virtual void virtual1ac();
    virtual void virtual1b0();
    virtual void virtual1b4();
    virtual void virtual1b8();
    virtual void virtual1bc();
    virtual void virtual1c0();
    virtual void virtual1c4();
    virtual void virtual1c8();
    virtual void virtual1cc();
    virtual Obj114* v1d0();
    virtual void virtual1d4();
    virtual void virtual1d8();
    virtual void virtual1dc();
    virtual void virtual1e0();
    virtual Obj114* v1e4();
    virtual void virtual1e8();
    virtual void virtual1ec();
    virtual void virtual1f0();
    virtual Vec114& v1f4();
    virtual void virtual1f8();
    virtual void virtual1fc();
    virtual void v200(int);
    virtual void virtual204();
    virtual void virtual208();
    virtual void virtual20c();
    virtual void virtual210();
    virtual void virtual214();
    virtual void virtual218();
    virtual void virtual21c();
    virtual void virtual220();
    virtual void virtual224();
    virtual void virtual228();
    virtual bool v22c(int);
    virtual void virtual230();
    virtual void virtual234();
    virtual void virtual238();
    virtual void virtual23c();
    virtual void virtual240();
    virtual void virtual244();
    virtual void virtual248();
    virtual void virtual24c();
    virtual void virtual250();
    virtual void virtual254();
    virtual void virtual258();
    virtual void virtual25c();
    virtual void virtual260();
    virtual void virtual264();
    virtual void virtual268();
    virtual void virtual26c();
    virtual void virtual270();
    virtual void virtual274();
    virtual void virtual278();
    virtual void virtual27c();
    virtual void virtual280();
    virtual float v284(void*, Handle114*, Obj114*, Obj114*, void*, Obj114*, Obj114*, Obj114*, int, int, int, int, int);
    virtual void virtual288();
    virtual void virtual28c();
    virtual void virtual290();
    virtual void virtual294();
    virtual void virtual298();
    virtual void virtual29c();
    virtual void virtual2a0();
    virtual void virtual2a4();
    virtual void virtual2a8();
    virtual void virtual2ac();
    virtual void virtual2b0();
    virtual void virtual2b4();
    virtual void virtual2b8();
    virtual void virtual2bc();
    virtual void virtual2c0();
    virtual void virtual2c4();
    virtual void virtual2c8();
    virtual void virtual2cc();
    virtual void virtual2d0();
    virtual void virtual2d4();
    virtual void virtual2d8();
    virtual void virtual2dc();
    virtual void virtual2e0();
    virtual void virtual2e4();
    virtual bool v2e8();
    virtual void virtual2ec();
    virtual void virtual2f0();
    virtual void virtual2f4();
    virtual void virtual2f8();
    virtual void virtual2fc();
    virtual void virtual300();
    virtual void virtual304();
    virtual void virtual308();
    virtual void virtual30c();
    virtual void virtual310();
    virtual void virtual314();
    virtual void virtual318();
    virtual void virtual31c();
    virtual void virtual320();
    virtual void virtual324();
    virtual void virtual328();
    virtual void virtual32c();
    virtual void virtual330();
    virtual void virtual334();
    virtual void virtual338();
    virtual void virtual33c();
    virtual void virtual340();
    virtual void virtual344();
    virtual void virtual348();
    virtual void virtual34c();
    virtual void virtual350();
    virtual void virtual354();
    virtual void virtual358();
    virtual void virtual35c();
    virtual void virtual360();
    virtual void virtual364();
    virtual void virtual368();
    virtual bool v36c();
    virtual void virtual370();
    virtual void v374(int);
    virtual bool v378();
    virtual int v37c();
    virtual void v380(int);
    virtual void virtual384();
    virtual void virtual388();
    virtual void virtual38c();
    virtual void virtual390();
    virtual void virtual394();
    virtual void virtual398();
    virtual void virtual39c();
    virtual void virtual3a0();
    virtual void virtual3a4();
    virtual void virtual3a8();
    virtual void virtual3ac();
    virtual void virtual3b0();
    virtual void virtual3b4();
    virtual void virtual3b8();
    virtual void virtual3bc();
    virtual void virtual3c0();
    virtual void virtual3c4();
    virtual void virtual3c8();
    virtual void virtual3cc();
    virtual void virtual3d0();
    virtual void virtual3d4();
    virtual void virtual3d8();
    virtual void virtual3dc();
    virtual void virtual3e0();
    virtual void virtual3e4();
    virtual void virtual3e8();
    virtual void virtual3ec();
    virtual void virtual3f0();
    virtual void virtual3f4();
    virtual void virtual3f8();
    virtual void virtual3fc();
    virtual void virtual400();
    virtual void virtual404();
    virtual void virtual408();
    virtual void virtual40c();
    virtual void virtual410();
    virtual void virtual414();
    virtual void virtual418();
    virtual void virtual41c();
    virtual void virtual420();
    virtual void virtual424();
    virtual void virtual428();
    virtual void virtual42c();
    virtual void virtual430();
    virtual void virtual434();
    virtual void virtual438();
    virtual void virtual43c();
    virtual void virtual440();
    virtual void virtual444();
    virtual void virtual448();
    virtual void virtual44c();
    virtual void virtual450();
    virtual void virtual454();
    virtual void virtual458();
    virtual void virtual45c();
    virtual void virtual460();
    virtual void virtual464();
    virtual void virtual468();
    virtual void virtual46c();
    virtual void virtual470();
    virtual void virtual474();
    virtual void virtual478();
    virtual void virtual47c();
    virtual void virtual480();
    virtual void virtual484();
    virtual void virtual488();
    virtual void virtual48c();
    virtual void virtual490();
    virtual void virtual494();
    virtual void virtual498();
    virtual void virtual49c();
    virtual void virtual4a0();
    virtual void virtual4a4();
    virtual void virtual4a8();
    virtual void virtual4ac();
    virtual void virtual4b0();
    virtual void virtual4b4();
    virtual void virtual4b8();
    virtual void virtual4bc();
    virtual void virtual4c0();
    virtual void virtual4c4();
    virtual void virtual4c8();
    virtual void virtual4cc();
    virtual void virtual4d0();
    virtual void virtual4d4();
    virtual void virtual4d8();
    virtual void virtual4dc();
    virtual void virtual4e0();
    virtual void virtual4e4();
    virtual void virtual4e8();
    virtual void virtual4ec();
    virtual void virtual4f0();
    virtual void virtual4f4();
    virtual void virtual4f8();
    virtual void virtual4fc();
    virtual void virtual500();
    virtual void virtual504();
    virtual void virtual508();
    virtual void virtual50c();
    virtual void virtual510();
    virtual void virtual514();
    virtual void virtual518();
    virtual void virtual51c();
    virtual void virtual520();
    virtual void virtual524();
    virtual void virtual528();
    virtual void virtual52c();
    virtual void virtual530();
    virtual void virtual534();
    virtual void virtual538();
    virtual void virtual53c();
    virtual void virtual540();
    virtual void virtual544();
    virtual void virtual548();
    virtual void virtual54c();
    virtual void virtual550();
    virtual void virtual554();
    virtual void virtual558();
    virtual void virtual55c();
    virtual void virtual560();
    virtual void virtual564();
    virtual void virtual568();
    virtual void virtual56c();
    virtual void virtual570();
    virtual void virtual574();
    virtual void virtual578();
    virtual void virtual57c();
    virtual void virtual580();
    virtual void virtual584();
    virtual void virtual588();
    virtual void virtual58c();
    virtual void virtual590();
    virtual void virtual594();
    virtual void virtual598();
    virtual void virtual59c();
    virtual void virtual5a0();
    virtual void virtual5a4();
    virtual void virtual5a8();
    virtual void virtual5ac();
    virtual void virtual5b0();
    virtual void virtual5b4();
    virtual void virtual5b8();
    virtual void virtual5bc();
    virtual void virtual5c0();
    virtual void virtual5c4();
    virtual void virtual5c8();
    virtual void virtual5cc();
    virtual void virtual5d0();
    virtual void virtual5d4();
    virtual void virtual5d8();
    virtual void virtual5dc();
    virtual void virtual5e0();
    virtual void virtual5e4();
    virtual void virtual5e8();
    virtual void virtual5ec();
    virtual void virtual5f0();
    virtual void virtual5f4();
    virtual void virtual5f8();
    virtual void virtual5fc();
    virtual void virtual600();
    virtual void virtual604();
    virtual void virtual608();
    virtual void virtual60c();
    virtual void virtual610();
    virtual void virtual614();
    virtual void virtual618();
    virtual void virtual61c();
    virtual void virtual620();
    virtual void virtual624();
    virtual void virtual628();
    virtual void virtual62c();
    virtual void virtual630();
    virtual void v634(Obj114*);
    virtual void virtual638();
    virtual void virtual63c();
    virtual void virtual640();
    virtual void v644(int);
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
    unsigned char flag80;
    Handle114 PlaySoundByFormID(Obj114*, int, unsigned int, int);
};
struct Manager114
{
    Handle114 FUN_00ad7480(char*, unsigned int, int);
};
struct Setting114
{
    bool* FUN_00408d60();
};
struct Player114
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
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    void* process;
};
void __cdecl FUN_00705210(void*, Handle114, Vec114, Obj114*, int);
struct Dialogue114
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
    Handle114 sound;
    unsigned int unk8c;
    float delay;
    Obj114* current;
    bool active;
    unsigned char unk99;
    unsigned short unk9a;
    unsigned int unk9c;
    bool flagA0;
    unsigned char unka1;
    unsigned short unka2;
    Obj114 *list, *item, *response, *first, *second, *third;
    unsigned int unkbc;
    unsigned char unkc0;
    bool flagC1;
    unsigned short unkc2;
    Obj114* valueC4;
    Obj114* valueC8;
    bool ready;
    void FUN_009ee0a0(bool process);
};

// @fnv 0x009ee0a0
void Dialogue114::FUN_009ee0a0(bool process)
{
    bool started15 = false;
    bool reset26 = true;
    if ((current && !current->flag80) || ((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first))->GetBaseTexture()))->v11c())
        return;
    if (!active)
    {
        if (!item)
        {
            started15 = true;
            if (!list)
            {
                first->v200(1);
                second->v200(1);
                return;
            }
            if (((bool)(reinterpret_cast<::FUN_009ef510_shell *>(this)->GetByteAtBC())) && !flagC1)
            {
                ((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture()))->v644(1);
                ((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture()))->v634(first);
            }
            reinterpret_cast<::Mid83b9a0 *>((list))->FUN_0083b9a0();
            item = ((::Obj114 *)(reinterpret_cast<::DialogueItem *>((list))->GetActiveResponse()));
            if (item)
            {
                reinterpret_cast<::DialogueItem *>((item))->SelectDefaultResponseList();
                response = ((::Obj114 *)(reinterpret_cast<::DialogueItem *>((item))->GetActiveResponse()));
            }
            else
            {
                first->v200(1);
                if (!reinterpret_cast<::FUN_006727b0_shell *>(this)->FUN_006727b0())
                    second->v200(1);
            }
        }
        else if (response)
        {
            reinterpret_cast<::FUN_0083c7e0_shell *>((item))->FUN_0083c7e0();
            response = ((::Obj114 *)(reinterpret_cast<::DialogueItem *>((item))->GetActiveResponse()));
        }
        if (first)
        {
            if (!first->v2e8() && !first->v22c(0))
            {
                if (!response)
                {
                    reinterpret_cast<::FUN_0083b9f0_shell *>((list))->FUN_0083b9f0();
                    item = ((::Obj114 *)(reinterpret_cast<::DialogueItem *>((list))->GetActiveResponse()));
                }
            }
            else if (!response)
                item = 0;
        }
    }
    if (item)
    {
        if (!response)
        {
            reinterpret_cast<::DialogueItem *>((item))->SelectDefaultResponseList();
            response = ((::Obj114 *)(reinterpret_cast<::DialogueItem *>((item))->GetActiveResponse()));
            if (!response)
                ::FUN_005b5e40();
        }
        if (response)
        {
            Obj114* actor18 = ((::Obj114 *)(reinterpret_cast<::FUN_009611e0_shell *>((item))->FUN_009611e0()));
            if (actor18->v100())
            {
                Obj114* speaker23 = ((::Obj114 *)(reinterpret_cast<::FUN_009611e0_shell *>((item))->FUN_009611e0()));
                if (speaker23 && process)
                {
                    String114 text6;
                    if (current)
                    {
                        reinterpret_cast<::FUN_00934250_shell *>((current))->FUN_00934250();
                        current = 0;
                    }
                    bool speak13 = true;
                    if (((::Obj114 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((response))->FUN_007af430())) && ready)
                    {
                        Obj114* topic21 = ((::Obj114 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::Obj114 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((response))->FUN_007af430()))))->FUN_0084e3a0()));
                        Handle114 handle23 = speaker23->PlaySoundByFormID(topic21, 0, 0x40000102, 1);
                        Manager114* manager3 = ((::Manager114 *)(::FUN_00ad9060()));
                        reinterpret_cast<::fnv_00adbfd0::FUN_00adbfd0_cls *>((manager3))->FUN_00adbfd0((intptr_t)(((void *)(::FUN_00559450((int *)&(handle23))))), (intptr_t)(((void (&)())::fnv_00935cc0::FUN_00935cc0)), (std::intptr_t)(reinterpret_cast<::FUN_0084e3a0_Class *>((first))->FUN_0084e3a0()));
                        ready = false;
                        speak13 = false;
                    }
                    if (speak13 && ready)
                    {
                        text6.FUN_00438470(((::String114 *)(::FUN_00460140((intptr_t)(response)))));
                        if (!((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((speaker23))->GetBaseTexture()))->v37c() && !((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((speaker23))->GetBaseTexture()))->v36c() &&
                            *(*reinterpret_cast<::Setting114 *>(&::g_011e05ec)).FUN_00408d60() && !((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((speaker23))->GetBaseTexture()))->v378())
                        {
                            valueC4 = ((::Obj114 *)(reinterpret_cast<::Twin_0044ddc0 *>((response))->GetName()));
                            valueC8 = ((::Obj114 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((response))->FUN_0084e3a0()));
                            reinterpret_cast<::FUN_00705b10_Dummy *>(this)->Set((intptr_t)(valueC4));
                            if (item)
                                reinterpret_cast<::FUN_0083c850 *>((item))->AppendTopicInfo(0);
                            current = speaker23;
                            reinterpret_cast<::FUN_008a5cf0_shell *>((speaker23))->SetFlag86(((bool)(reinterpret_cast<::TESObjectCELL *>((response))->GetField24())));
                            float duration13 = speaker23->v284(
                                ((void *)(::FUN_00559450((int *)&(text6)))), &sound, ((::Obj114 *)(reinterpret_cast<::Twin_0044ddc0 *>((response))->GetName())), ((::Obj114 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((response))->FUN_0084e3a0())),
                                ((void *)(reinterpret_cast<::FUN_004048e0_cls *>((((::Obj114 *)(((::Vec3 *)(void *)(response))))))->FUN_004048e0())), ((::Obj114 *)(reinterpret_cast<::FUN_009611e0_shell *>((response))->FUN_009611e0())),
                                ((::Obj114 *)(reinterpret_cast<::BGSTerrainManager *>((response))->GetMinLevel())), second, 1, 0, 1, 1, flagA0);
                            if (third)
                            {
                                Obj114* data15 = ((::Obj114 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((third))->FUN_007af430()));
                                if (((::Obj114 *)(reinterpret_cast<::FUN_00516bf0_shell *>((data15))->FUN_00516bf0())) == speaker23)
                                {
                                    Obj114* target20 = second;
                                    if (second == third)
                                        target20 = first;
                                    current = third;
                                    reinterpret_cast<::FUN_008a5cf0_shell *>((third))->SetFlag86(((bool)(reinterpret_cast<::TESObjectCELL *>((response))->GetField24())));
                                    duration13 = third->v284(
                                        ((void *)(::FUN_00559450((int *)&(text6)))), &sound, ((::Obj114 *)(reinterpret_cast<::Twin_0044ddc0 *>((response))->GetName())),
                                        ((::Obj114 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((response))->FUN_0084e3a0())), ((void *)(reinterpret_cast<::FUN_004048e0_cls *>((((::Obj114 *)(((::Vec3 *)(void *)(response))))))->FUN_004048e0())),
                                        ((::Obj114 *)(reinterpret_cast<::FUN_009611e0_shell *>((response))->FUN_009611e0())), ((::Obj114 *)(reinterpret_cast<::BGSTerrainManager *>((response))->GetMinLevel())), target20, 0, 0, 0, 1, 1);
                                }
                            }
                            if (((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((speaker23))->GetBaseTexture()))->v36c())
                                active = true;
                            else
                            {
                                Manager114* manager228 = ((::Manager114 *)(::FUN_00ad9060()));
                                reinterpret_cast<::fnv_00adbfd0::FUN_00adbfd0_cls *>((manager228))->FUN_00adbfd0((intptr_t)(((void *)(::FUN_00559450((int *)&(sound))))), (intptr_t)(((void (&)())::FUN_00936ac0)), (std::intptr_t)(reinterpret_cast<::FUN_0084e3a0_Class *>((first))->FUN_0084e3a0()));
                                if (first != second)
                                    delay = 50.0f;
                                speaker23->flag80 = 0;
                            }
                            return;
                        }
                        else
                        {
                            if (((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((speaker23))->GetBaseTexture()))->v36c() && !((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((speaker23))->GetBaseTexture()))->v378())
                                return;
                            else
                            {
                                if (!*(*reinterpret_cast<::Setting114 *>(&::g_011e05ec)).FUN_00408d60() && item)
                                    reinterpret_cast<::FUN_0083c850 *>((item))->AppendTopicInfo(0);
                                current = speaker23;
                                reinterpret_cast<::FUN_008a5cf0_shell *>((speaker23))->SetFlag86(((bool)(reinterpret_cast<::TESObjectCELL *>((response))->GetField24())));
                                speaker23->v284(((void *)(::FUN_00559450((int *)&(text6)))), &sound, ((::Obj114 *)(reinterpret_cast<::Twin_0044ddc0 *>((response))->GetName())),
                                                ((::Obj114 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((response))->FUN_0084e3a0())), ((void *)(reinterpret_cast<::FUN_004048e0_cls *>((((::Obj114 *)(((::Vec3 *)(void *)(response))))))->FUN_004048e0())),
                                                ((::Obj114 *)(reinterpret_cast<::FUN_009611e0_shell *>((response))->FUN_009611e0())), ((::Obj114 *)(reinterpret_cast<::BGSTerrainManager *>((response))->GetMinLevel())), second, 1, 0, 0, 1,
                                                flagA0);
                                if (third)
                                {
                                    if (third)
                                    {
                                        Obj114* data218 = ((::Obj114 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((third))->FUN_007af430()));
                                        if (((::Obj114 *)(reinterpret_cast<::FUN_00516bf0_shell *>((data218))->FUN_00516bf0())) == speaker23)
                                        {
                                            Obj114* target24 = second;
                                            if (second == third)
                                                target24 = first;
                                            current = third;
                                            reinterpret_cast<::FUN_008a5cf0_shell *>((third))->SetFlag86(((bool)(reinterpret_cast<::TESObjectCELL *>((response))->GetField24())));
                                            third->v284(((void *)(::FUN_00559450((int *)&(text6)))), &sound, ((::Obj114 *)(reinterpret_cast<::Twin_0044ddc0 *>((response))->GetName())),
                                                        ((::Obj114 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((response))->FUN_0084e3a0())),
                                                        ((void *)(reinterpret_cast<::FUN_004048e0_cls *>((((::Obj114 *)(((::Vec3 *)(void *)(response))))))->FUN_004048e0())),
                                                        ((::Obj114 *)(reinterpret_cast<::FUN_009611e0_shell *>((response))->FUN_009611e0())), ((::Obj114 *)(reinterpret_cast<::BGSTerrainManager *>((response))->GetMinLevel())), target24, 0,
                                                        0, 0, 1, 1);
                                        }
                                    }
                                }
                                Manager114* manager334 = ((::Manager114 *)(::FUN_00ad9060()));
                                reinterpret_cast<::fnv_00adbfd0::FUN_00adbfd0_cls *>((manager334))->FUN_00adbfd0((intptr_t)(((void *)(::FUN_00559450((int *)&(sound))))), (intptr_t)(((void (&)())::FUN_00936ac0)), (std::intptr_t)(reinterpret_cast<::FUN_0084e3a0_Class *>((first))->FUN_0084e3a0()));
                                speaker23->flag80 = 0;
                                reset26 = false;
                                current = speaker23;
                                ((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((speaker23))->GetBaseTexture()))->v380(0);
                                active = false;
                                ((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((speaker23))->GetBaseTexture()))->v374(0);
                                if (first != second)
                                    delay = 2.0f;
                                Obj114* obj21 = current->v1e4();
                                Obj114* obj25 = second->v1e4();
                            }
                        }
                    }
                }
                if (reset26)
                {
                    if (((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first))->GetBaseTexture())))
                        ((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((first))->GetBaseTexture()))->v44(first, 0, 2, 0, 1, 1);
                    if (first != current && current && ((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((current))->GetBaseTexture())))
                        ((::Obj114 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((second))->GetBaseTexture()))->v44(second, 0, 2, 0, 1, 1);
                }
            }
            else if (actor18 && process)
            {
                char path27[512];
                String114 text22;
                String114 copy14(((::String114 *)(::FUN_00460140((intptr_t)(response)))));
                if (((void *)(::FUN_00559450((int *)(((::String114 *)(::FUN_00460140((intptr_t)(response)))))))))
                {
                    ::TaskQueueInterface::CopyStringToBuffer(path27, 512, (const char *)(void *)(((void *)(::FUN_00559450((int *)(((::String114 *)(::FUN_00460140((intptr_t)(response))))))))));
                    if (current)
                    {
                        reinterpret_cast<::FUN_00934250_shell *>((current))->FUN_00934250();
                        current = 0;
                    }
                    text22.FUN_00438470(((::String114 *)(::FUN_00460140((intptr_t)(response)))));
                    if (third)
                    {
                        Obj114* data310 = ((::Obj114 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((third))->FUN_007af430()));
                        reinterpret_cast<::FUN_008a5cf0_shell *>((third))->SetFlag86(((bool)(reinterpret_cast<::TESObjectCELL *>((response))->GetField24())));
                        current = third;
                        third->v284(((void *)(::FUN_00559450((int *)&(text22)))), &sound, ((::Obj114 *)(reinterpret_cast<::Twin_0044ddc0 *>((response))->GetName())), ((::Obj114 *)(reinterpret_cast<::FUN_0084e3a0_Class *>((response))->FUN_0084e3a0())),
                                    ((void *)(reinterpret_cast<::FUN_004048e0_cls *>((((::Obj114 *)(((::Vec3 *)(void *)(response))))))->FUN_004048e0())), ((::Obj114 *)(reinterpret_cast<::FUN_009611e0_shell *>((response))->FUN_009611e0())),
                                    ((::Obj114 *)(reinterpret_cast<::BGSTerrainManager *>((response))->GetMinLevel())), second, 0, 0, 0, 1, 1);
                        Manager114* manager45 = ((::Manager114 *)(::FUN_00ad9060()));
                        reinterpret_cast<::fnv_00adbfd0::FUN_00adbfd0_cls *>((manager45))->FUN_00adbfd0((intptr_t)(((void *)(::FUN_00559450((int *)&(sound))))), (intptr_t)(((void (&)())::FUN_00936ac0)), (std::intptr_t)(reinterpret_cast<::FUN_0084e3a0_Class *>((third))->FUN_0084e3a0()));
                        third->flag80 = 0;
                        reset26 = false;
                    }
                    else
                    {
                        unsigned int flags22 = 0x104;
                        flags22 |= 2;
                        reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->operator=((const ::SoundPlaybackHandle &)((const ::Handle114 &)(((::Manager114 *)(::FUN_00453a70()))->FUN_00ad7480(path27, flags22, 0))));
                        Vec114 position1 = actor18->v1f4();
                        reinterpret_cast<::FUN_00ad8be0_shell *>(&(sound))->FUN_00ad8be0(FUN_005790b0(), FUN_005790d0());
                        reinterpret_cast<::FUN_00ad8b60_h *>(&(sound))->FUN_00ad8b60(position1.x, position1.y, position1.z);
                        reinterpret_cast<::FUN_00ad8f20_shell *>(&(sound))->FUN_00ad8f20((::NiAVObject *)(::Obj114 *)(actor18->v1d0()));
                        reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->SchedulePlayback(1, 0);
                    }
                }
                if ((this == (*reinterpret_cast<::Player114 * *>(&::_g_thePlayer))->process || (*reinterpret_cast<unsigned char *>(&::DAT_011f122d))) && ((::Obj114 *)(reinterpret_cast<::DialogueItem *>((list))->GetActiveResponse())) &&
                    ((::Obj114 *)(reinterpret_cast<::DialogueItem *>((((::Obj114 *)(reinterpret_cast<::DialogueItem *>((list))->GetActiveResponse()))))->GetActiveResponse())) &&
                    ((void *)(::FUN_00559450((int *)(((::Obj114 *)(((::Vec3 *)(void *)(((::Obj114 *)(reinterpret_cast<::DialogueItem *>((((::Obj114 *)(reinterpret_cast<::DialogueItem *>((list))->GetActiveResponse()))))->GetActiveResponse())))))))))))
                {
                    if (*(*reinterpret_cast<::Setting114 *>(&::g_011d8928)).FUN_00408d60() || (actor18->v100() && ::FUN_008c1bc0((intptr_t)(actor18))))
                        FUN_00705210(((void *)(::FUN_00559450((int *)(((::Obj114 *)(((::Vec3 *)(void *)(((::Obj114 *)(reinterpret_cast<::DialogueItem *>((((::Obj114 *)(reinterpret_cast<::DialogueItem *>((list))->GetActiveResponse()))))->GetActiveResponse())))))))))), sound,
                                     actor18->v1f4(), second, 0);
                }
                if (delay <= 0.0 && second != actor18)
                    delay = 10.0f;
            }
        }
    }
    else
    {
        first->v200(1);
        if (!reinterpret_cast<::FUN_006727b0_shell *>(this)->FUN_006727b0())
            second->v200(1);
    }
}

struct Sound
{
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
    virtual int VCall130();
};
struct TESSound
{
    unsigned int m_00;
};
struct FUN_008579e0_shell
{
    void FUN_008579e0(void* buf, unsigned int n);
};
struct TimeGlobal : FUN_008579e0_shell
{
};
class TESSound;
struct EffectSetting : TimeGlobal
{
public:
    ::TESSound *GetHitSound();
};
struct TESSaveLoadGame : EffectSetting
{
};
class TESTopic : public TESForm
{
};
void* __cdecl FUN_00ec43fb(void* a, int b, void* c, void* d, int e);
extern char DAT_01093108;
extern void* DAT_01183028;
extern void* DAT_01184720;
struct SLObj
{
};
struct DialogueItem_shell
{
    int GetResponseByIndex(short a);
};
struct This
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48;
    int f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c, f80, f84, f88;
    void* f8c;
    int f90;
    int f94;
    unsigned char f98;
    int f9c;
    int fa0;
    intptr_t fa4;
    intptr_t fa8;
    int fac;
    int fb0;
    int fb4;
    void LoadSaveData();
};
// @fnv 0x009efa50
void This::LoadSaveData()
{
    reinterpret_cast<::fnv_00679340::Package679 *>(this)->FUN_00679340();
    {
        unsigned short w18 = 0;
        uintptr_t flag = 0;
        if (reinterpret_cast<::FUN_00862110_cls *>((::g_TESSaveLoadGame))->FUN_00862110())
        {
            unsigned int i;
            ::g_TESSaveLoadGame->FUN_008579e0(&i, 4);
            if (i != 0x424c4f4b)
            {
                TESSound* rec = ((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(::g_TESSaveLoadGame))));
                if (rec != 0)
                {
                    TESForm* pForm = ::FUN_004839c0(rec->m_00);
                    ::FUN_005b5e40();
                }
                else
                {
                    ::FUN_005b5e40();
                }
            }
            flag = reinterpret_cast<uintptr_t>(reinterpret_cast<SaveLoadGameView*>((::g_TESSaveLoadGame))->pBufferCursor);
            ::g_TESSaveLoadGame->FUN_008579e0(&w18, 2);
        }
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&f90, 4);
        if ((int)reinterpret_cast<::FUN_008df040_shell *>((::g_TESSaveLoadGame))->FUN_008df040() >= 0x6a)
        {
            reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&f98, 1);
        }
        unsigned int id;
        reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&id, 4);
        f94 = (int)id;
        unsigned int a18;
        reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&a18, 4);
        fb0 = (int)a18;
        unsigned int a10;
        reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&a10, 4);
        fb4 = (int)a10;
        unsigned int a14;
        reinterpret_cast<::FUN_00484d40_Host *>(this)->FUN_00484d40(&a14, 4);
        f8c = dynamic_cast<TESTopic*>(::FUN_004839c0(a14));
        if ((int)reinterpret_cast<::FUN_008df040_shell *>((::g_TESSaveLoadGame))->FUN_008df040() >= 0x20)
        {
            unsigned short w34;
            reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&w34, 2);
            if (w34 != 0)
            {
                fa4 = (intptr_t)new FUN_0083b830;
                reinterpret_cast<::ConversationLoad *>((((SLObj*)fa4)))->LoadFromSave();
                short w38;
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&w38, 2);
                if (w38 != -1)
                {
                    fa8 = ((intptr_t)(reinterpret_cast<::ConversationLoad *>((((SLObj*)fa4)))->FUN_0083bac0((unsigned short)w38)));
                }
                else
                {
                    fa8 = 0;
                }
                short w3c;
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&w3c, 2);
                fac = w3c;
                if (fa8 != 0 && w3c != -1)
                {
                    fac = ((DialogueItem_shell*)fa8)->GetResponseByIndex((unsigned short)w3c);
                }
                else
                {
                    fac = 0;
                }
            }
        }
        if ((int)reinterpret_cast<::FUN_008df040_shell *>((::g_TESSaveLoadGame))->FUN_008df040() < 0x20)
        {
            unsigned int a40;
            reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&a40, 4);
            fa4 = (int)a40;
            if (a40 != 0)
            {
                short w44;
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&w44, 2);
                fa8 = w44;
                short w48;
                reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&w48, 2);
                fac = w48;
            }
            else
            {
                fa8 = 0;
                fac = 0;
            }
        }
        if (reinterpret_cast<::FUN_00862110_cls *>((::g_TESSaveLoadGame))->FUN_00862110())
        {
            uintptr_t ts = reinterpret_cast<uintptr_t>(reinterpret_cast<SaveLoadGameView*>((::g_TESSaveLoadGame))->pBufferCursor);
            TESSound* tag = ((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(::g_TESSaveLoadGame))));
            if (tag != 0)
            {
                TESForm* snd = ::FUN_004839c0(tag->m_00);
                if (ts > w18 + flag)
                {
                    ::FUN_005b5e40();
                }
                else if (ts < w18 + flag)
                {
                    ::FUN_005b5e40();
                }
            }
            else
            {
                if (ts > w18 + flag)
                {
                    ::FUN_005b5e40();
                }
                else if (ts < w18 + flag)
                {
                    ::FUN_005b5e40();
                }
            }
        }
    }
}

namespace fnv_009eff60 {

class TESSaveLoadGame
{
  public:
};

class DialogueItem
{
  public:
    DialogueResponse* GetResponseByIndex(short index);
};

class Conversation
{
  public:
    DialogueItem* currentItem;
    Character* speaker;
    PlayerCharacter* listener;
    Conversation(Character* speaker, PlayerCharacter* listener, TESTopic* topic);
};

struct DialoguePackageState
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
    TESTopic* topic;
    unsigned int unk90;
    Actor* target;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    Conversation* conversation;
    DialogueItem* item;
    DialogueResponse* response;
    Actor* speaker;
    Actor* listener;

    void ResolveReferences();
};

// Resolves target, speaker and listener from stored IDs, then rebuilds the conversation, item and response from saved indices.
// @fnv 0x009eff60
void DialoguePackageState::ResolveReferences()
{
    reinterpret_cast<::FUN_006796c0_shell *>(this)->FUN_006796c0();
    // Serialized actor IDs are resolved in target, speaker, listener order.
    uintptr_t listenerID = (uintptr_t)target;
    target = dynamic_cast<Actor*>(::FUN_004839c0(listenerID));
    uintptr_t targetID;
    uintptr_t speakerID = (uintptr_t)speaker;
    speaker = dynamic_cast<Actor*>(::FUN_004839c0(speakerID));
    targetID = (uintptr_t)listener;
    listener = dynamic_cast<Actor*>(::FUN_004839c0(targetID));

    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_009eff60::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 32 && conversation)
        reinterpret_cast<::ListNode *>((conversation))->FUN_0083c220();
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_009eff60::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() < 32)
    {
        // Retain the saved conversation marker and its two serialized indices.
        Conversation* itemIndex = conversation;
        short oldConversation = (short)(uintptr_t)item;
        short responseIndex = (short)(uintptr_t)response;
        if (itemIndex)
        {
            conversation = new Conversation((Character*)speaker, (PlayerCharacter*)listener, topic);
            if (oldConversation != -1)
                item = ((::fnv_009eff60::DialogueItem *)(reinterpret_cast<::ConversationLoad *>((conversation))->FUN_0083bac0(oldConversation)));
            else
                item = 0;
            if (item && responseIndex != -1)
                response = item->GetResponseByIndex(responseIndex);
            else
                response = 0;
            reinterpret_cast<::StandIn *>((conversation))->FUN_0083c8a0((::DialogueResponse *)(item));
            reinterpret_cast<::StandIn *>((item))->FUN_0083c8a0(response);
        }
    }
}
}  // namespace fnv_009eff60

namespace fnv_009ef6e0 {
struct DialogueSaveRecord
{
    unsigned int formID;
    unsigned char type;
    unsigned char flags;
};
class DialogueSaveGameWriter
{
  public:
};
struct TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
class DialogueItem
{
  public:
};
class Conversation_Stub
{
  public:
};
class DialoguePackage
{
  public:
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
    TESForm* speaker;
    unsigned int state;
    TESForm* topic;
    unsigned char flags;
    unsigned int unk9C;
    unsigned int unkA0;
    Conversation_Stub* conversation;
    DialogueItem* item;
    DialogueResponse* response;
    TESForm* quest;
    TESForm* info;
    void FUN_009ef6e0();
};

// Writes the DialoguePackage state, topic, quest, info, speaker, conversation item and response indices to the save-game writer, then patches the block size.
// @fnv 0x009ef6e0
void DialoguePackage::FUN_009ef6e0()
{
    reinterpret_cast<::Package679120 *>(this)->SavePackage();
    unsigned short size5 = 0;    // blockSize
    unsigned short* offset = 0;  // blockStart
    // Initial save position.
    char* saved7 = reinterpret_cast<SaveLoadGameView*>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->pBufferCursor;
    if (*(*reinterpret_cast<::fnv_009ef6e0::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool())
        saved7 = reinterpret_cast<SaveLoadGameView*>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->pBufferCursor;
    if (reinterpret_cast<::FUN_00862110_cls *>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned int blockTag = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&blockTag, 4);
        offset = (unsigned short*)reinterpret_cast<SaveLoadGameView*>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->pBufferCursor;
        reinterpret_cast<::FUN_008579b0_shell *>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&size5, 2);
    }
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&state, 4);
    if (reinterpret_cast<::FUN_008df040_shell *>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_008df040() >= 106)
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&flags, 1);
    unsigned int form7 = 0;  // topicID
    if (topic)
        form7 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((topic))->FUN_0084e3a0()));
    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&form7), 4);
    unsigned int form2 = 0;
    if (quest)
        form2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((quest))->FUN_0084e3a0()));
    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&form2), 4);
    unsigned int formVal = 0;  // infoID
    if (info)
        formVal = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((info))->FUN_0084e3a0()));
    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&formVal), 4);
    unsigned int form5 = 0;  // speakerID
    if (speaker)
        form5 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((speaker))->FUN_0084e3a0()));
    reinterpret_cast<::FUN_00484d20_Class *>(this)->ForwardToSaveLoadGame((intptr_t)(&form5), 4);
    unsigned short countB = 0;  // count
    if (conversation)
        countB = reinterpret_cast<::DialogueItemList *>((conversation))->FUN_0083bb30();
    reinterpret_cast<::FUN_008579b0_shell *>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&countB, 2);
    if (countB)
    {
        reinterpret_cast<::CVConv *>((conversation))->SaveConversation();
        short itemIndex = -1;
        if (item)
            itemIndex = reinterpret_cast<::Conversation_Stub *>((conversation))->FUN_0083ba50((::DialogueItem *)(item));
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&itemIndex, 2);
        short responseIndex = -1;
        if (item && response)
            responseIndex = reinterpret_cast<::FUN_0083c900_shell *>((item))->GetResponseIndex(response);
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&responseIndex, 2);
    }
    if (*(*reinterpret_cast<::fnv_009ef6e0::GlobalObject_0045cf30 *>(&::g_011de4e8)).Bool())
    {
        uintptr_t end = reinterpret_cast<uintptr_t>(reinterpret_cast<SaveLoadGameView*>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->pBufferCursor);
        DialogueSaveRecord* record = ((::fnv_009ef6e0::DialogueSaveRecord *)(reinterpret_cast<::EffectSetting *>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->GetHitSound()));
        if (record)
        {
            TESForm* form = ::FUN_004839c0(record->formID);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        uintptr_t end = reinterpret_cast<uintptr_t>(reinterpret_cast<SaveLoadGameView*>((((DialogueSaveGameWriter*)(*reinterpret_cast<::fnv_009ef6e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->pBufferCursor);
        uintptr_t offset2 = (uintptr_t)offset;
        if (end > offset2 + 0xffff)
            ::FUN_005b5e40();
        *offset = (unsigned short)(end - offset2);
    }
}
}  // namespace fnv_009ef6e0

namespace fnv_009f0460 {
struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
};
struct List0083b830SV
{
    int a, b, c;
    List0083b830SV();
};
struct DlgItemX
{
    void* GetResponseByIndex(unsigned short i);
};
struct TESPackage
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
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
    void LoadGame(BGSLoadFormBuffer* buf);
};
struct FUN_009f0460_class : TESPackage
{
    TESTopic* m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    char ma0;
    char ma1, ma2, ma3;
    List0083b830SV* ma4;
    DlgItemX* ma8;
    void* mac;
    int mb0;
    int mb4;
    int mb8;
    char mbc, mbd, mbe, mbf, mc0, mc1, mc2, pc3;
    int mc4;
    int mc8;
    char mcc;
    void FUN_009f0460(BGSLoadFormBuffer* buf);
};
// Loads the base package, reads fields from the buffer, and conditionally loads a list with two indexed selections.
// @fnv 0x009f0460
void FUN_009f0460_class::FUN_009f0460(BGSLoadFormBuffer* apSaveBuffer)
{
    reinterpret_cast<::Package6798c0 *>(this)->LoadPackage((::LoadBuffer6798c0 *)(apSaveBuffer));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apSaveBuffer))->FUN_008648e0((unsigned int *)(void *)(&m94));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apSaveBuffer))->FUN_008648e0((unsigned int *)(void *)(&mb0));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apSaveBuffer))->FUN_008648e0((unsigned int *)(void *)(&mb4));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apSaveBuffer))->FUN_008648e0((unsigned int *)(void *)(&mb8));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apSaveBuffer))->FUN_008648e0((unsigned int *)(void *)(&m9c));
    m8c = dynamic_cast<TESTopic*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apSaveBuffer))->FUN_008648a0()));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m90), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m98), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mbc), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mbd), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mbe), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mbf), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mc0), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mc1), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mc4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mc8), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ma0), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mcc), 1);
    if (apSaveBuffer->GetVersion() >= 3)
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&mc2), 1);
    bool b = false;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&b), 1);
    if (b)
    {
        ma4 = new List0083b830SV();
        reinterpret_cast<::fnv_0083c330::FUN_0083c330_shell *>((ma4))->FUN_0083c330((::fnv_0083c330::BGSLoadFormBuffer *)(apSaveBuffer));
        short i1 = -1;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&i1), 2);
        if (i1 != -1)
            ma8 = (DlgItemX*)reinterpret_cast<::ConversationLoad *>((ma4))->FUN_0083bac0(i1);
        short i2 = -1;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apSaveBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&i2), 2);
        if (ma8 && i2 != -1)
            mac = ma8->GetResponseByIndex(i2);
    }
}
}  // namespace fnv_009f0460

#include "generated/data/fallout/ai/dialoguepackage.inc"
