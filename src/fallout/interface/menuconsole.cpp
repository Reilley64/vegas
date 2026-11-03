// fallout/interface/menuconsole.cpp: ConsoleManager, ListHead, ConsoleDisplay, DumpConsole (13 functions)

#include <cstring>
#include "fnv/decl/A0F8Self.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ConsoleText.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00473180_shell.h"
#include "fnv/decl/FUN_00501c10_cls.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005abe50_shell.h"
#include "fnv/decl/FUN_005bd580_cls.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_007023a0_shell.h"
#include "fnv/decl/FUN_0070ecf0_shell.h"
#include "fnv/decl/FUN_0071d010_Class.h"
#include "fnv/decl/FUN_0071dca0_cls.h"
#include "fnv/decl/FUN_0071dec0.h"
#include "fnv/decl/FUN_0071e0f0_cls.h"
#include "fnv/decl/FUN_00720f90_shell.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a087d0_shell.h"
#include "fnv/decl/LoadBook.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/Mgr20.h"
#include "fnv/decl/S71df20.h"
#include "fnv/decl/ScriptCompileAndRun.h"
#include "fnv/decl/SearchText.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/fnv_00457070__FUN_00457070_shell.h"
#include "fnv/decl/fnv_005bd5c0__FUN_005bd5c0_shell.h"
#include "fnv/decl/fnv_00714fd0__FUN_00714fd0_shell.h"
#include "fnv/decl/fnv_0071d380__FUN_0071d380_t.h"
#include "fnv/decl/fnv_00720e00__FakeMgr.h"
#include "fnv/decl/fnv_00720e60__FUN_00720e60_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a0de80__FUN_00a0de80_cls.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00456000.h"
#include "fnv/symbols_00469000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005cb000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_0071d000.h"
#include "fnv/symbols_007cb000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a0d000.h"
#include "fnv/symbols_00a10000.h"
#include "fnv/symbols_00a1c000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "menuconsole_idle.h"
#include "menuconsole_decls.h"

ConsoleManager* ConsoleManager::pInstance = 0;

// @fnv 0x0071b0e0
void ConsoleManager::Init()
{
    m_pScriptCompiler = new ScriptCompiler;
}

// Returns the singleton instance, creating and initialising it first when bCreate is true and it does not yet exist.
// @fnv 0x0071b160
ConsoleManager* ConsoleManager::Instance(bool bCreate)
{
    if (!pInstance && bCreate)
    {
        pInstance = new ConsoleManager;
        pInstance->Init();
        return pInstance;
    }
    else
        return pInstance;
}


class GlobalObject_0048f200
{
  public:
    char pad[12];
    GlobalObject_0048f200();
    ~GlobalObject_0048f200();
};

struct DummyFont
{
};

struct DummyFontManager
{
};


struct GlobalObject_0048f200_d0071b020 : GlobalObject_0048f200
{
    ~GlobalObject_0048f200_d0071b020();
};
struct FUN_0071af10
{
    int f00;
    GlobalObject_0048f200_d0071b020 f04;
    GlobalObject_0048f200_d0071b020 f10;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    char f38;
    char f39;
    char f3a;
    char f3b;
    int f3c;
    char pad40[0x7d0];
    char f810[0x104];

    FUN_0071af10();
};

// @fnv 0x0071af10
FUN_0071af10::FUN_0071af10()
{
    f39 = 0;
    f00 = 0;
    f24 = 0;
    f38 = 0;
    f1c = 0;
    f2c = (int)reinterpret_cast<::FUN_005bd580_cls *>((((::DummyFont *)(reinterpret_cast<::fnv_005bd5c0::FUN_005bd5c0_shell *>((((::DummyFontManager *)(::FontManager::Instance()))))->FUN_005bd5c0(((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8d38))))))->i - 1)))))->FUN_005bd580() + 3;
    f30 = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8d44))))))->i;
    f34 = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8d08))))))->i;
    f3a = 0;
    f3c = 0;
    ::FUN_00403d30(f810, 0, 0x104);
}

struct FUN_0071d750_shell
{
    void ClearField();
};

// @fnv 0x0071d750
void FUN_0071d750_shell::ClearField()
{
    ((int*)this)[0x3c] = 0;
}

struct ListNode
{
    ListNode* next;
};
struct ListHead
{
    ListNode* head;
    ListNode* tail;
    int count;
    void Clear();
};
// @fnv 0x0071e070
void ListHead::Clear()
{
    ListNode* pkNode = head;
    while (pkNode != 0)
    {
        ListNode* pkTemp = pkNode;
        pkNode = pkNode->next;
        reinterpret_cast<::FUN_0071e0f0_cls *>(this)->FUN_0071e0f0((const char *)(pkTemp));
    }
    count = 0;
    head = 0;
    tail = 0;
}

struct FUN_0071b020_shell
{
    void FUN_0071b020();
};

// @fnv 0x0071b020
void FUN_0071b020_shell::FUN_0071b020()
{
    reinterpret_cast<::FUN_0071dec0 *>(this)->FUN_0071dec0::~FUN_0071dec0();
}

void FUN_00703310(int);
struct ArrSI
{
};
struct FUN_0071d770_shell : public ConsoleManager
{
    void FUN_0071d770();
};
namespace fnv_0071d620 {
struct Interface
{
};

struct ArrSI
{
};

struct FUN_00a0de80_shell
{
};

struct FUN_0071d750_shell
{
};

extern const char $SG3295[];


struct FUN_0071d620_shell : public InterfaceManager
{
    unsigned char layoutPadding[0x30];
    int m_iConsoleX;
    int m_iConsoleY;
    char cVisible;

    void FUN_0071d620(char acState);
};

// @fnv 0x0071d620
void FUN_0071d620_shell::FUN_0071d620(char acState)
{
    char cold_state;
    cold_state = cVisible;
    cVisible = acState;

    if ((acState > 0) != (cold_state > 0))
    {
        if (acState > 0)
        {
            ::FUN_0040fbe0();

            if (reinterpret_cast<::FUN_007023a0_shell *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007023a0())
            {
                reinterpret_cast<::A0F8Self *>((((::DebugText *)(::FUN_00a0d9e0(true)))))->FUN_00a0f8b0("|", (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f,
                                                 ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8d38))))))->i, (::A0F8Color *)(0));

                reinterpret_cast<::fnv_0071d380::FUN_0071d380_t *>(this)->ClampIndexByDelta(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(reinterpret_cast<char*>(this) + 4)))->GetName())));
            }
            else
            {
                reinterpret_cast<::A0F8Self *>((((::DebugText *)(::FUN_00a0d9e0(true)))))->FUN_00a0f8b0($SG3295, (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f, 0, (::A0F8Color *)(0));
            }

            reinterpret_cast<ConsoleManager*>(this)->ResetOutputState();
        }
        else
        {
            ::FUN_0040fbe0();
            reinterpret_cast<::fnv_00a0de80::FUN_00a0de80_cls *>((reinterpret_cast<FUN_00a0de80_shell*>(((::DebugText *)(::FUN_00a0d9e0(true))))))->FUN_00a0de80();
            reinterpret_cast<::FUN_0071d750_shell *>((reinterpret_cast<FUN_0071d750_shell*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->ClearField();
        }
    }
}
}  // namespace fnv_0071d620

// Destructor: free the owned decal data; the two lists are destroyed afterwards.

class B040DecalData
{
  public:
    ~B040DecalData();
    int unk00;
};

class B040List
{
  public:
    ~B040List();
    int unk00;
    int unk04;
    int unk08;
};

class FUN_0071b040
{
  public:
    ~FUN_0071b040();

    B040DecalData* m_pkDecalData;
    B040List m_kFirst;
    B040List m_kSecond;
};

// Destructor that deletes m_pkDecalData if it is non-null.
// @fnv 0x0071b040
FUN_0071b040::~FUN_0071b040()
{
    if (m_pkDecalData)
        delete m_pkDecalData;
}

struct ConsoleLine
{
};
struct ConsoleLines
{
    void* head;
    void* tail;
    int count;
};
struct ConsoleTextRenderer
{
};
struct ConsoleDisplay
{
    void* compiler;
    ConsoleLines strings, inputs;
    int m_iCommandHistoryPosition, m_iScrollPosition, m_iOutputLineCount, menuMode, iConsoleLineSpacing, m_iConsoleX,
        m_iConsoleY;
    void DrawConsoleLines();
};
// @fnv 0x0071d770
void FUN_0071d770_shell::FUN_0071d770()
{
    if (cVisible > 0)
    {
        reinterpret_cast<::A0F8Self *>((((::DebugText *)(::FUN_00a0d9e0(true)))))->FUN_00a0f8b0("|", (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f,
                                         ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8d38))))))->i, (::A0F8Color *)(0));
        reinterpret_cast<::fnv_0071d380::FUN_0071d380_t *>((((InterfaceManager*)this)))->ClampIndexByDelta(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 4))))->GetName())));
        reinterpret_cast<::ConsoleDisplay *>(this)->DrawConsoleLines();
        FUN_00703310(0);
    }
}
// Draws the visible console string lines, padding with blank lines when the first visible index is negative, then advancing through the list.
// @fnv 0x0071d410
void ConsoleDisplay::DrawConsoleLines()
{
    void* node = ((void *)(::FUN_00559450((int *)&(strings))));
    int lineY = m_iConsoleY - ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8cfc))))))->i * iConsoleLineSpacing;
    int lastLine = m_iOutputLineCount;
    int lineIndex = lastLine - ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8cfc))))))->i;
    while (lineIndex < 0)
    {
        reinterpret_cast<::A0F8Self *>((((::ConsoleTextRenderer *)(::FUN_00a0d9e0(1)))))->FUN_00a0f8b0(0, (float)m_iConsoleX, (float)lineY, 1, -1, ::DAT_01012054, 0, (::A0F8Color *)(0));
        ++lineIndex;
        lineY += iConsoleLineSpacing;
    }
    for (int skipped = 0; skipped < lineIndex; ++skipped)
        node = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(strings))->DereferenceIfNotNull((int **)(node))));
    while (lineIndex < lastLine)
    {
        reinterpret_cast<::A0F8Self *>((((::ConsoleTextRenderer *)(::FUN_00a0d9e0(1)))))->FUN_00a0f8b0(((const char *)(::FUN_00559450((int *)(((::ConsoleLine *)(reinterpret_cast<::FUN_006317a0_struct *>(&(strings))->AddEight((int)(node)))))))), (float)m_iConsoleX, (float)lineY, 1, -1,
                                      ::DAT_01012054, ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8d38))))))->i, (::A0F8Color *)(0));
        node = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(strings))->DereferenceIfNotNull((int **)(node))));
        ++lineIndex;
        lineY += iConsoleLineSpacing;
    }
}

void ToggleGlobalFlag();

class FUN_0071d580_probe
{
  public:
};

class FUN_0071d580_cls
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
    int unk2c;
    int unk30;
    int unk34;
    signed char m_38;

    bool FUN_0071d580();
};

// @fnv 0x0071d580
bool FUN_0071d580_cls::FUN_0071d580()
{
    ToggleGlobalFlag();
    if (m_38 == 0)
    {
        reinterpret_cast<::fnv_0071d620::FUN_0071d620_shell *>(this)->FUN_0071d620(1);
        return true;
    }
    else
    {
        if (m_38 == 1 && reinterpret_cast<::FUN_0070ecf0_shell *>((((FUN_0071d580_probe*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->IsFlag4Set())
        {
            if (reinterpret_cast<::InterfaceManager *>((((FUN_0071d580_probe*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->GetMenuStackEntry(0) == 3 &&
                reinterpret_cast<::InterfaceManager *>((((FUN_0071d580_probe*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->GetMenuStackEntry(1) == 0)
            {
                reinterpret_cast<::fnv_0071d620::FUN_0071d620_shell *>(this)->FUN_0071d620(2);
            }
            else
            {
                reinterpret_cast<::fnv_0071d620::FUN_0071d620_shell *>(this)->FUN_0071d620(0);
            }
        }
        else
        {
            reinterpret_cast<::fnv_0071d620::FUN_0071d620_shell *>(this)->FUN_0071d620(0);
        }
    }
    return false;
}

struct DumpName
{
    const char* FUN_0043b1b0();
};
struct DumpTexture
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
    virtual DumpName* v9c();
};
struct DumpRTTI
{
};
struct DumpSetting
{
    bool* FUN_00408d60();
};
struct DumpFullName
{
};
struct DumpWorld
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DumpFullName name;
};
struct DumpCell
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DumpFullName name;
};
struct DumpTES
{
};
struct DumpConsole
{
    void DumpLoadedTextures();
};
// @fnv 0x0071b210
bool ConsoleManager::Idle(int aiKeyCode)
{
    if (cVisible <= 0 || !reinterpret_cast<::FUN_007023a0_shell *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007023a0())
        return false;

    struct InputState
    {
        int length;
        int key;
    } state;
    state.key = aiKeyCode;
    if (state.key)
    {
        char text[2048];
        int cursor;
        char rawText[2048];
        reinterpret_cast<::SearchText *>((((::DebugText *)(::FUN_00a0d9e0(true)))))->FUN_00a103e0(rawText, (float)m_iConsoleX, (float)m_iConsoleY, 1);
        ::FUN_005cbd90(text, (void *)(rawText), (void *)(2046));
        state.length = 0;
        while (text[state.length])
            state.length++;
        if (text[state.length - 1] == '|')
        {
            state.length--;
            text[state.length] = 0;
        }
        for (cursor = 0; cursor < state.length; cursor++)
        {
            if (text[cursor] == '|')
                break;
        }
        if (cursor == state.length)
        {
            text[cursor] = '|';
            state.length++;
        }
        if (state.key == (int)0x80000008)
        {
            for (int i = 0; i < state.length + 1; i++)
            {
                if (text[i] == '|')
                {
                    text[i] = text[i + 1];
                    text[i + 1] = '|';
                }
            }
            for (int i = 0; i < state.length + 1; i++)
            {
                if (text[i] == '\n')
                {
                    if (text[i - 1] == '-')
                    {
                        for (int j = i - 1; j < state.length + 1; j++)
                            text[j] = text[j + 2];
                    }
                    else
                        text[i] = ' ';
                }
                if (text[i] == '\n')
                    text[i] = ' ';
            }
            if (text[0])
            {
                DAT_011d8ce4 = true;
                InterfaceManager* manager = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
                reinterpret_cast<::fnv_0071d380::FUN_0071d380_t *>((reinterpret_cast<InterfaceManager*>(this)))->ClampIndexByDelta(
                    ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kOutputLines)))->GetName())));
                ::FUN_0071d030((::Outer *)(::ConsoleManager *)(this), text);
                BSStringT<char> line(text);
                reinterpret_cast<::S71df20 *>(&(m_kCommandHistory))->AssignString((const ::BSStringTCharAssign &)(line));
                m_iCommandHistoryPosition = 0;
                ((::DebugText *)(::FUN_00a0d9e0(true)))->Print("|", (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f,
                                                 ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8d38))))))->i);
                if (!FUN_0071cff0(text, "dof", 3))
                {
                    float distance = 0.0f;
                    sscanf(text, "dof %f", &distance);
                    NiFrustum frustum =
                        reinterpret_cast<NiCamera*>(
                            reinterpret_cast<BSFaceGenNiNode*>(((::NiNode *)(reinterpret_cast<::StrOwner *>((reinterpret_cast<SkyObject*>(manager)))->FUN_007fa950())))
                                ->GetAnimationData())
                            ->GetViewFrustum();
                    frustum.m_fFarPlane = distance;
                    reinterpret_cast<NiCamera*>(
                        reinterpret_cast<BSFaceGenNiNode*>(((::NiNode *)(reinterpret_cast<::StrOwner *>((reinterpret_cast<SkyObject*>(manager)))->FUN_007fa950())))
                            ->GetAnimationData())
                        ->UpdateViewFrustum(frustum);
                }
                else if (!FUN_0071cff0(text, "usz", 3))
                {
                    struct ConsoleSize
                    {
                        int y;
                        int x;
                    } size;
                    size.x = 0;
                    size.y = 0;
                    sscanf(text, "usz %i %i", &size.x, &size.y);
                    ::fnv_007030c0::FUN_007030c0(size.x, size.y);
                }
                else if (!_mbsicmp((const unsigned char*)text, (const unsigned char*)"clr") ||
                         !::FUN_00469880((void *)((const unsigned char*)text), (void *)((const unsigned char*)"cls")))
                {
                    reinterpret_cast<::ListHead *>(&(m_kOutputLines))->Clear();
                    m_iOutputLineCount = 0;
                    reinterpret_cast<::ConsoleDisplay *>(this)->DrawConsoleLines();
                }
                else if (!_mbsicmp((const unsigned char*)text, (const unsigned char*)"tag"))
                {
                    TESObjectREFR* reference = ((::TESObjectREFR *)(::FUN_007031c0((int)(manager))));
                    if (reference)
                    {
                        BSStringT<char> label;
                        ::FUN_00406f60((::FUN_00406f90_this *)&(label), "\"%s\" (%08x)", reinterpret_cast<::FUN_0055d520_shell *>((reference))->FUN_0055d520(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reference))->FUN_0084e3a0())));
                        void* node = ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<unsigned char *>(&::g_011f4428))), (::NiObject *)(::NiNode *)(reference->GetNiNode_v()))));
                        if (!node)
                            node = ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<unsigned char *>(&::g_011f4428))), (::NiObject *)(::NiNode *)(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reference->GetNiNode_v()))->FUN_009611e0()))))));
                        ::FUN_00a10c00((::NiObject *)(node), ((const char *)(::FUN_00559450((int *)&(label)))), 0, -1.0f);
                    }
                }
                else if (!FUN_0071cff0(text, "reload strings", 14))
                {
                    delete ((::Tile *)(reinterpret_cast<::MagicProjectile *>((manager))->FUN_004fd400()));
                    ::fnv_00a1ca20::RemoveMenuEntries("Data\\Menus\\globals.xml", 0);
                    Tile* tile = reinterpret_cast<::fnv_00a01b00::TileLoader *>((manager->FUN_00586150()))->FUN_00a01b00((void *)("Data\\Menus\\globals.xml"));
                    reinterpret_cast<::FUN_00a087d0_shell *>((tile))->FUN_00a087d0(0, 0);
                    manager->FUN_00500a20(tile);
                }
                else if (!FUN_0071cff0(text, "reload HUDReticle", 17))
                    ::FUN_00a1c800();
                else if (!FUN_0071cff0(text, "reload HUDSafeZone", 18))
                {
                    ::FUN_00a1c800();
                    ::fnv_007038e0::FUN_007038e0(3);
                }
                else if (!_mbsicmp((const unsigned char*)text, (const unsigned char*)"reload mainmenu"))
                {
                    ::FUN_00a1c800();
                    delete ((::Menu *)(::FUN_00a09030(FUN_0070ede0())));
                    ::InitStartMenu(false, false);
                }
                else if (!FUN_0071cff0(text, "reload ", 7))
                {
                    ::FUN_00a1c800();
                    char menuName[1024];
                    sscanf(text, "reload %s", menuName);
                    if (menuName[0] != '&')
                    {
                        int i = 0;
                        while (menuName[i])
                            i++;
                        menuName[i + 2] = 0;
                        menuName[i + 1] = ';';
                        while (i > 0)
                        {
                            menuName[i] = menuName[i - 1];
                            i--;
                        }
                        menuName[0] = '&';
                    }
                    reinterpret_cast<::Mgr20 *>((MenuSystem::Instance(true)))->FUN_00720aa0(::FUN_00a01860(menuName));
                }
                else if (!FUN_0071cff0(text, "delete ", 7))
                {
                    char menuName[1024];
                    sscanf(text, "delete %s", menuName);
                    reinterpret_cast<::fnv_00720e00::FakeMgr *>((MenuSystem::Instance(true)))->DestroyMenuByClass(::FUN_00a01860(menuName));
                }
                else if (!FUN_0071cfd0(text, "front", 5))
                    ::FUN_0071d030((::Outer *)(::ConsoleManager *)(this), "Frontmost: %s",
                                 reinterpret_cast<Tile*>(((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(
                                                             reinterpret_cast<::fnv_00720e60::FUN_00720e60_shell *>((MenuSystem::Instance(true)))->FindTopMenu())))->FUN_00726070())))
                                     ->FUN_00700300());
                else if (!FUN_0071cfd0(text, "stack", 5))
                {
                    int i = 0;
                    while (manager->GetMenuStackEntry(i++))
                        ::FUN_0071d030((::Outer *)(::ConsoleManager *)(this), "%i: %i", i, manager->GetMenuStackEntry(i));
                }
                else if (!FUN_0071cfd0(text, "visible", 7))
                {
                    int menu = 0;
                    sscanf(text, "visible %i", &menu);
                    ::FUN_0071d030((::Outer *)(::ConsoleManager *)(this), "Is Visible: %i", reinterpret_cast<::FUN_00720f90_shell *>((MenuSystem::Instance(true)))->FUN_00720f90(menu));
                }
                else if (!FUN_0071cfd0(text, "exit menus", 10))
                {
                    int menu = manager->GetTopEnterStackEntry();
                    while (menu)
                    {
                        reinterpret_cast<::fnv_00714fd0::FUN_00714fd0_shell *>((manager))->RemoveFromStack(menu, false);
                        menu = manager->GetTopEnterStackEntry();
                    }
                }
                else if (!FUN_0071cfd0(text, "emergency texture release", 25))
                {
                    ::fnv_00703920::FUN_00703920();
                    ::FUN_0071d030((::Outer *)(::ConsoleManager *)(this), "First change release of hidden textures activated.");
                }
                else if (!FUN_0071cfd0(text, "set trait", 9))
                {
                    struct TileTraitEdit
                    {
                        int trait;
                        float value;
                        Tile* tile;
                    } edit;
                    edit.value = 0.0f;
                    {
                        char traitName[128];
                        char tileName[128];
                        sscanf(text, "set trait %s %s %f", tileName, traitName, &edit.value);
                        edit.tile = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(0), tileName)));
                        edit.trait = ::FUN_00a01860(traitName);
                        if (edit.tile && edit.trait > 0)
                        {
                            ::FUN_0071d030((::Outer *)(::ConsoleManager *)(this), "Trait set.");
                            reinterpret_cast<::FUN_00a012d0_t *>((edit.tile))->FUN_00a012d0(edit.trait, edit.value, true);
                        }
                        else if (edit.tile)
                            reinterpret_cast<::ConsoleText *>(this)->FUN_0071d0a0("Unknown trait '%s'", (char *)(traitName));
                        else
                            reinterpret_cast<::ConsoleText *>(this)->FUN_0071d0a0("Can't find tile '%s'", (char *)(tileName));
                    }
                }
                else if (!FUN_0071cfd0(text, "depth", 5))
                {
                    ::FUN_0071d030((::Outer *)(::ConsoleManager *)(this), "Max Depth: %i", (int)Tile::GetInterfaceScale());
                    ::FUN_0071d030((::Outer *)(::ConsoleManager *)(this), "Cursor Depth: %i",
                                 (int)reinterpret_cast<TileListBoxCalls*>(
                                     ((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((reinterpret_cast<TESResponse*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0045cd60())))
                                     ->GetFloat(4013));
                }
                else if (!FUN_0071cfd0(text, "new fonts", 9))
                    reinterpret_cast<::FUN_0071d010_Class *>((::FontManager::Instance()))->SetByteAtOffset20({});
                else if (!FUN_0071cfd0(text, "old fonts", 9))
                    reinterpret_cast<::FUN_0071d010_Class *>((::FontManager::Instance()))->SetByteAtOffset20({});
                else if (!FUN_0071cfd0(text, "iso", 3))
                {
                    bool first = false;
                    bool second = false;
                    if (text[3] == '1')
                        first = true;
                    if (text[4] == '1')
                        second = true;
                    ::fnv_00702c80::FUN_00702c80(first, second);
                }
                else if (!FUN_0071cfd0(text, "restore menus", 13))
                    UpdateMenuTileVisibility();
                else if (!FUN_0071cfd0(text, "use workbook", 12))
                {
                    TileMenu* tileMenu = dynamic_cast<TileMenu*>(reinterpret_cast<Tile*>(((::Menu *)(::FUN_00a09030(1026)))));
                    if (tileMenu)
                    {
                        BookMenu* book = dynamic_cast<BookMenu*>(
                            reinterpret_cast<Menu*>(((::TESActorBase *)(reinterpret_cast<::Twin_00639b40 *>((reinterpret_cast<TESTopicInfo*>(tileMenu)))->GetEntryPoint()))));
                        if (book)
                            reinterpret_cast<::LoadBook *>((book))->LoadBookFile();
                    }
                    else
                        ::FUN_0071d030((::Outer *)(::ConsoleManager *)(this), "You must open a book (or scroll) before using the workbook.");
                }
                else if (!FUN_0071cfd0(text, "dump textures", 13))
                    reinterpret_cast<::DumpConsole *>(this)->DumpLoadedTextures();
                else if (!FUN_0071cfd0(text, "bat", 3))
                {
                    char filename[128];
                    filename[0] = ""[0];
                    std::memset(filename + 1, 0, 127);
                    sscanf(text, "bat %s", filename);
                    if (!strlen(filename))
                        ::FUN_00703c00("You must enter a filename.", {});
                    else
                    {
                        char primaryName[260];
                        primaryName[0] = ""[0];
                        std::memset(primaryName + 1, 0, 259);
                        {
                            struct BatchFileState
                            {
                                BSFile* file;
                                unsigned int filenameLength;
                            } batch;
                            {
                                char alternateName[260];
                                alternateName[0] = ""[0];
                                std::memset(alternateName + 1, 0, 259);
                                strcat_s(primaryName, 260, filename);
                                batch.file = new BSFile(primaryName, NiFile::READ_ONLY, 16384, false);
                                batch.filenameLength = ::FUN_0044a670(filename);
                                if (!batch.file || !batch.file->vfn_20(false, false))
                                {
                                    if (batch.filenameLength <= 4 ||
                                        _mbsnicmp((const unsigned char*)(filename + batch.filenameLength - 4),
                                                  (const unsigned char*)".txt", 4))
                                    {
                                        delete batch.file;
                                        TaskQueueInterface::CopyStringToBuffer(alternateName, 260, primaryName);
                                        strcat_s(alternateName, 260, ".txt");
                                        batch.file = new BSFile(alternateName, NiFile::READ_ONLY, 16384, false);
                                    }
                                }
                                if (!batch.file || !batch.file->vfn_20(false, false))
                                {
                                    if (::FUN_0044a670(alternateName))
                                        ::FUN_00703c00("Neither file '%s' or '%s' could be opened.", primaryName);
                                    else
                                        ::FUN_00703c00("The file '%s' could not be opened.", primaryName);
                                }
                                else
                                {
                                    char batchLine[2600];
                                    while (batch.file->vfn_34(batchLine, 2600, '\r'))
                                    {
                                        for (int i = 0; i < strlen(batchLine); i++)
                                            if (batchLine[i] == '\n')
                                                batchLine[i] = ' ';
                                        if (strlen(batchLine) > 1)
                                        {
                                            ::FUN_00703c00("> %s", batchLine);
                                            Script script;
                                            script.NotifySaveLoadGameOfFormChange();
                                            reinterpret_cast<::FUN_005abe50_shell *>(&(script))->FUN_005abe50((char *)(batchLine));
                                            reinterpret_cast<::ScriptCompileAndRun *>(&(script))->FUN_005ac400(m_pScriptCompiler, COMPILER_NAME_CONSOLE,
                                                                     ((::TESObjectREFR *)(::FUN_007031c0((int)(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))));
                                        }
                                    }
                                }
                                if (batch.file)
                                    delete batch.file;
                            }
                        }
                    }
                }
                else if (!FUN_0071cfd0(text, "rbat", 3))
                {
                    if (!m_bRecordingBatch)
                    {
                        ::FUN_00703c00("Batch Recording Started.", {});
                        ::FUN_00703c00("Use rbat {filename} to save batch file or rbat with no filename to cancel.", {});
                        m_bRecordingBatch = true;
                        m_iBatchCommandCount = 0;
                        for (int i = 0; i < 20; i++)
                            ::FUN_004046f0(m_aacCommandHistory[i], "");
                    }
                    else
                    {
                        char filename[128];
                        filename[0] = ""[0];
                        std::memset(filename + 1, 0, 127);
                        sscanf(text, "rbat %s", filename);
                        if (!strlen(filename))
                            ::FUN_00703c00("No filename specified; recording cancelled.", {});
                        else if (m_iBatchCommandCount <= 0)
                            ::FUN_00703c00("No commands recorded; recording cancelled.", {});
                        else
                        {
                            BSFile* file = new BSFile(filename, NiFile::WRITE_ONLY, 4096, true);
                            if (!file || !file->vfn_20(false, false))
                                ::FUN_00703c00("The file '%s' could not be opened.", filename);
                            else
                            {
                                for (int i = 0; i < m_iBatchCommandCount; i++)
                                {
                                    char batchLine[100];
                                    ::FUN_00406d00(batchLine, 100, "%s\r\n", m_aacCommandHistory[i]);
                                    reinterpret_cast<::FUN_00473180_shell *>((file))->FUN_00473180((void *)(batchLine), ::FUN_0044a670(batchLine));
                                }
                                file->Close();
                                ::FUN_00703c00("Batch file '%s' created.", filename);
                            }
                            if (file)
                                delete file;
                        }
                        m_bRecordingBatch = false;
                        m_iBatchCommandCount = 0;
                    }
                }
                else
                {
                    if (m_bRecordingBatch)
                    {
                        if (m_iBatchCommandCount < 20)
                        {
                            ::FUN_004046f0(m_aacCommandHistory[m_iBatchCommandCount++], text);
                            ::FUN_00703c00("Recorded.", {});
                        }
                        else
                            ::FUN_00703c00("Recording full; command ignored. Use rbat to cancel or rbat {filename} to save.", {});
                    }
                    for (int i = 0; i < strlen(text); i++)
                        if (text[i] == '\n')
                            text[i] = ' ';
                    Script script;
                    script.NotifySaveLoadGameOfFormChange();
                    reinterpret_cast<::FUN_005abe50_shell *>(&(script))->FUN_005abe50((char *)(text));
                    reinterpret_cast<::ScriptCompileAndRun *>(&(script))->FUN_005ac400(m_pScriptCompiler, COMPILER_NAME_CONSOLE, ((::TESObjectREFR *)(::FUN_007031c0((int)(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))));
                }
            }
        }
        else
        {
            {
                int i;
                {
                    bool found;
                    if (state.key == (int)0x80000000)
                    {
                        if (state.length && cursor)
                        {
                            state.length--;
                            int i = cursor;
                            while (i < state.length)
                            {
                                text[i] = text[i + 1];
                                i++;
                            }
                            text[state.length] = 0;
                            text[cursor - 1] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000007)
                    {
                        if (cursor < state.length)
                        {
                            state.length--;
                            int i = cursor;
                            while (i < state.length)
                            {
                                text[i] = text[i + 1];
                                i++;
                            }
                            text[state.length] = 0;
                            text[cursor] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000009)
                    {
                        reinterpret_cast<::fnv_0071d380::FUN_0071d380_t *>((reinterpret_cast<InterfaceManager*>(this)))->ClampIndexByDelta(-((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8cfc))))))->i + 1);
                        reinterpret_cast<::ConsoleDisplay *>(this)->DrawConsoleLines();
                    }
                    else if (state.key == (int)0x8000000a)
                    {
                        reinterpret_cast<::fnv_0071d380::FUN_0071d380_t *>((reinterpret_cast<InterfaceManager*>(this)))->ClampIndexByDelta(((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8cfc))))))->i - 1);
                        reinterpret_cast<::ConsoleDisplay *>(this)->DrawConsoleLines();
                    }
                    else if (state.key == (int)0x8000000a)
                    {
                        reinterpret_cast<::fnv_0071d380::FUN_0071d380_t *>((reinterpret_cast<InterfaceManager*>(this)))->ClampIndexByDelta(((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8cfc))))))->i - 1);
                        reinterpret_cast<::ConsoleDisplay *>(this)->DrawConsoleLines();
                    }
                    else if (state.key == (int)0x80000003)
                    {
                        if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kCommandHistory)))->GetName())))
                        {
                            m_iCommandHistoryPosition++;
                            m_iCommandHistoryPosition = MinInt(
                                m_iCommandHistoryPosition,
                                ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kCommandHistory)))->GetName())) -
                                    1);
                            void* position =
                                ((void *)(::FUN_00559450((int *)(reinterpret_cast<
                                    const NiTListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >*>(
                                    &m_kCommandHistory)))));
                            for (int i = 0; i < m_iCommandHistoryPosition; i++)
                                position = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(m_kCommandHistory))->DereferenceIfNotNull((int **)(position))));
                            sprintf(text, "%s", ((const char *)(::FUN_00559450((int *)&(m_kCommandHistory.AddEight(position))))));
                        }
                    }
                    else if (state.key == (int)0x80000004)
                    {
                        if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kCommandHistory)))->GetName())))
                        {
                            m_iCommandHistoryPosition--;
                            m_iCommandHistoryPosition = FUN_00647b70(m_iCommandHistoryPosition, 0);
                            BSStringT<char> line;
                            {
                                void* position = 0;
                                if (m_iCommandHistoryPosition)
                                {
                                    position =
                                        ((void *)(::FUN_00559450((int *)(reinterpret_cast<const NiTListBase<NiTPointerAllocator<unsigned int>,
                                                                           NiPointer<NiProperty> >*>(&m_kCommandHistory)))));
                                    for (int i = 0; i < m_iCommandHistoryPosition; i++)
                                        position = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(m_kCommandHistory))->DereferenceIfNotNull((int **)(position))));
                                }
                                if (position)
                                    reinterpret_cast<::FUN_00501c10_cls *>((void *)&(const ::BSStringT<char> &)(line))->CallAndReturnSelf((int)&(m_kCommandHistory.AddEight(position)));
                                else
                                    line = "";
                                sprintf(text, "%s", ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(line))->FUN_004048e0())) ? ((const char *)(::FUN_00559450((int *)&(line)))) : "");
                            }
                        }
                    }
                    else if (state.key == (int)0x80000001)
                    {
                        if (state.length && cursor)
                        {
                            text[cursor] = text[cursor - 1];
                            text[cursor - 1] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000002)
                    {
                        if (state.length && cursor + 1 < state.length)
                        {
                            text[cursor] = text[cursor + 1];
                            text[cursor + 1] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000005)
                    {
                        if (state.length && cursor)
                        {
                            for (int i = cursor; i > 0; i--)
                                text[i] = text[i - 1];
                            text[0] = '|';
                        }
                    }
                    else if (state.key == (int)0x80000006)
                    {
                        if (state.length && cursor + 1 < state.length)
                        {
                            for (int i = cursor; i < state.length - 1; i++)
                                text[i] = text[i + 1];
                            text[state.length - 1] = '|';
                        }
                    }
                    else
                    {
                        text[cursor] = (char)state.key;
                        state.length++;
                        int i = state.length;
                        while (i > cursor)
                        {
                            text[i + 1] = text[i];
                            i--;
                        }
                        text[state.length + 1] = 0;
                        text[cursor + 1] = '|';
                    }
                    found = false;
                    i = 0;
                    while (text[i])
                    {
                        if (text[i] == '|')
                        {
                            found = true;
                            break;
                        }
                        i++;
                    }
                    if (!found)
                    {
                        text[i] = '|';
                        text[i + 1] = 0;
                    }
                }
            }
            BSStringT<char> line(text);
            if (!((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&m_kCommandHistory)))->GetName())))
                reinterpret_cast<::S71df20 *>(&(m_kCommandHistory))->AssignString((const ::BSStringTCharAssign &)(line));
            else
            {
                m_kCommandHistory.PopFront();
                reinterpret_cast<::S71df20 *>(&(m_kCommandHistory))->AssignString((const ::BSStringTCharAssign &)(line));
            }
            ((::DebugText *)(::FUN_00a0d9e0(true)))->Print(text, (float)m_iConsoleX, (float)m_iConsoleY, 1, -1, -1.0f,
                                             ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8d38))))))->i);
        }
    }
    return true;
}
// @fnv 0x0071d800
void DumpConsole::DumpLoadedTextures()
{
    DumpTexture* a0[200];
    {
        DumpTexture* a1;
        int a2;
        unsigned int a3;
        int a4, a5, a6;
        unsigned int a7;
        BSFile* a8;
        DumpTexture* a9;
        ::FUN_00403d30(a0, 0, sizeof(a0));
        a1 = ((::DumpTexture *)(::FUN_00456510()));
        while (a1)
        {
            if (::FUN_0043b300((const ::NiRTTI *)(const ::DumpRTTI *)(&(*reinterpret_cast<::DumpRTTI *>(&::g_011f444c))), (::NiAVObject *)(a1)))
            {
                a9 = a1;
                a7 = reinterpret_cast<::ActorMover *>((a9))->GetCurrentMoveModeType();
                if (a7 && (*(*reinterpret_cast<::DumpSetting *>(&::g_011dec98)).FUN_00408d60() || !reinterpret_cast<::FUN_0071dca0_cls *>(this)->HasMenusPath((::PathSource *)(a9))))
                {
                    a5 = -1;
                    for (a4 = 0; a4 < 200 && a5 == -1; a4++)
                    {
                        if (!a0[a4])
                            a5 = a4;
                        else
                        {
                            a3 = reinterpret_cast<::ActorMover *>((a0[a4]))->GetCurrentMoveModeType();
                        }
                    }
                    if (a5 != -1)
                    {
                        for (a2 = 199; a2 > a5; a2--)
                            a0[a2] = a0[a2 - 1];
                        a0[a5] = a9;
                    }
                }
            }
            a1 = ((::DumpTexture *)(reinterpret_cast<::BGSMessageInitAccess *>((a1))->GetIconFormID()));
        }
        a8 = new BSFile("textures.txt", NiFile::WRITE_ONLY, 0x1000, true);
        if (!a8 || !a8->vfn_20(false, false))
        {
            ::FUN_00703c00("The file textures.txt could not be opened.", {});
            return;
        }
        a6 = 0;
        {
            char buffer[1024];
            ::FUN_00406d00(
                buffer, 1024,
                "Texture dump for cell: %s grid: (%d, %d) worldspace: %s \n---------------------------------------\n",
                ((::DumpCell *)(reinterpret_cast<::fnv_00457070::FUN_00457070_shell *>(((*reinterpret_cast<::DumpTES * *>(&::g_TES))))->FUN_00457070())) ? ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::DumpCell *)(reinterpret_cast<::fnv_00457070::FUN_00457070_shell *>(((*reinterpret_cast<::DumpTES * *>(&::g_TES))))->FUN_00457070()))->name))->FUN_00408da0())) : "{unknown}", ((int)(reinterpret_cast<::ActorMover *>(((*reinterpret_cast<::DumpTES * *>(&::g_TES))))->GetCurrentMoveModeType())),
                ((int)(reinterpret_cast<::FUN_0045cd60_shell *>(((*reinterpret_cast<::DumpTES * *>(&::g_TES))))->FUN_0045cd60())),
                ((::DumpCell *)(reinterpret_cast<::fnv_00457070::FUN_00457070_shell *>(((*reinterpret_cast<::DumpTES * *>(&::g_TES))))->FUN_00457070())) ? (((::DumpWorld *)(reinterpret_cast<::TESObjectCELL *>((((::DumpCell *)(reinterpret_cast<::fnv_00457070::FUN_00457070_shell *>(((*reinterpret_cast<::DumpTES * *>(&::g_TES))))->FUN_00457070()))))->GetParentWorldSpace()))
                                             ? ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::DumpWorld *)(reinterpret_cast<::TESObjectCELL *>((((::DumpCell *)(reinterpret_cast<::fnv_00457070::FUN_00457070_shell *>(((*reinterpret_cast<::DumpTES * *>(&::g_TES))))->FUN_00457070()))))->GetParentWorldSpace()))->name))->FUN_00408da0()))
                                             : "{unknown}")
                                      : "{unknown}");
            reinterpret_cast<::FUN_00473180_shell *>((a8))->FUN_00473180((void *)(buffer), ::FUN_0044a670(buffer));
            {
                for (int k = 0; k < 200 && a0[k]; k++)
                {
                    const char* a7;
                    unsigned int name;
                    name = reinterpret_cast<::ActorMover *>((a0[k]))->GetCurrentMoveModeType();
                    a7 = a0[k]->v9c()->FUN_0043b1b0();
                    reinterpret_cast<::FUN_00473180_shell *>((a8))->FUN_00473180((void *)(buffer), ::FUN_0044a670(buffer));
                }
            }
            ::FUN_00406d00(buffer, 1024, "---------------------------------------\nTotal memory: %dkb", a6);
            reinterpret_cast<::FUN_00473180_shell *>((a8))->FUN_00473180((void *)(buffer), ::FUN_0044a670(buffer));
            a8->Close();
            ::FUN_00703c00("200 largest loaded textures dumped to the file textures.txt.", {});
        }
    }
}

#include "generated/data/fallout/interface/menuconsole.inc"
