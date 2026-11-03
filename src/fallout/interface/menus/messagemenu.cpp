// fallout/interface/menus/messagemenu.cpp: DelStandIn, MessageMenu, MessageMenuHandler, KeyMenu and more (28 functions)

#include <new>
#include <cctype>
#include <cstdlib>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C764930ListMenu.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_0044a970_Cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_005103d0_cls.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_006bf8f0_Class.h"
#include "fnv/decl/FUN_006f23d0_Class.h"
#include "fnv/decl/FUN_00714f90_shell.h"
#include "fnv/decl/FUN_007a8960_cls.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1db20_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FontManager.h"
#include "fnv/decl/GO.h"
#include "fnv/decl/IntListBox.h"
#include "fnv/decl/Interface.h"
#include "fnv/decl/LBList.h"
#include "fnv/decl/LockExtraData.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESObjectDOOR.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk65a.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00579280__ReferenceView.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a1d9e0__FUN_00a1d9e0_shell.h"
#include "fnv/decl/xRefr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_007a8000.h"
#include "fnv/symbols_007a9000.h"
#include "fnv/symbols_007aa000.h"
#include "fnv/symbols_007d6000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01063000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_0119f000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "MessageMenu.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_00aa4c40_class.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00778000.h"

static const int kGetClassValue = 1001;

// @fnv 0x007a8aa0
int MessageMenu::GetClass()
{
    return kGetClassValue;
}


// @fnv 0x00703fe0
void __cdecl FUN_00703fe0(bool abDisable)
{
    ::fnv_007aa6b0::FUN_007aa6b0(abDisable);
}

struct Menu_007a8b10
{
    char pad[0x3c];
    virtual ~Menu_007a8b10();
};
struct Member_007a8b10
{
    char pad[4];
    ~Member_007a8b10();
};
struct FUN_007a8b10 : public Menu_007a8b10
{
    Member_007a8b10 m40;
    virtual ~FUN_007a8b10();
};
// Destructor that sets DAT_0119f348 to true, clears DAT_011da4f0, and if DAT_011da4ed is set, sets DAT_011da4ee to true.
// @fnv 0x007a8b10
FUN_007a8b10::~FUN_007a8b10()
{
    DAT_0119f348 = true;
    DAT_011da4f0 = 0;
    if (DAT_011da4ed)
        DAT_011da4ee = true;
}

namespace fnv_007a8df0 {
class Tile
{
  public:
    void Set(int, int);
};

class Interface
{
  public:
};

class PlayerCharacter
{
  public:
};


// @fnv 0x007a8df0
void __cdecl FUN_007a8df0()
{
    if ((*reinterpret_cast<void * *>(&::DAT_011da4f0)))
    {
        ((::fnv_007a8df0::Tile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<void * *>(&::DAT_011da4f0))))->FUN_00726070()))->Set(0x1772, 1);
        if (((int)(::FUN_00707ad0())))
            reinterpret_cast<::fnv_00a1d9e0::FUN_00a1d9e0_shell *>(((*reinterpret_cast<void * *>(&::DAT_011da4f0))))->FUN_00a1d9e0();
        else
            reinterpret_cast<::FUN_00a1d910_shell *>(((*reinterpret_cast<void * *>(&::DAT_011da4f0))))->FUN_00a1d910();

        if (::fnv_007050d0::FUN_007050d0() && !((bool)(::IsStartMenuFlag1Set())))
            ::SetDialogMenuActive(0);
    }
}
}  // namespace fnv_007a8df0

// @fnv 0x007a9280
char GetByteAtOffset56(char* pThis)
{
    return pThis[0x38];
}

class TESObjectREFR
{
  public:
};

template <> class BSSimpleArray<unsigned int, 1024>
{
  public:
    unsigned int& GetAt(unsigned int);
};


// Returns the element at index DAT_011da4f4 from g_011da53c if that index is below the object's flags, otherwise 0.
// @fnv 0x007a92a0
unsigned int __cdecl GetCurrentArrayElement()
{
    unsigned int uiResult = 0;
    if (DAT_011da4f4 < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<TESObjectREFR*>(&(*reinterpret_cast<::BSSimpleArray<unsigned int, 1024> *>(&::g_011da53c)))))->GetName())))
    {
        uiResult = (*reinterpret_cast<::BSSimpleArray<unsigned int, 1024> *>(&::g_011da53c)).GetAt(DAT_011da4f4);
    }
    return uiResult;
}

namespace fnv_007aa070 {
struct RecursiveLock;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct FUN_007aa070_shell : public MessageMenu
{
    void HandleTileSelection(int, Tile*);
};


class PerkForm;
template <class T> class ListBox
{
  public:
    T GetSelectedData(Tile*);
};

// Resolves a tile by ID when none is given, and for ID 7 stores the list-box result into a global and runs the selection callbacks.
// @fnv 0x007aa070
void FUN_007aa070_shell::HandleTileSelection(int aiID, Tile* apTarget)
{
    if (!apTarget && aiID >= 0 && aiID < 6)
    {
        apTarget = ((Tile**)&this->m_pTiles[0])[aiID];
    }
    if (aiID == 7 && apTarget)
    {
        *(unsigned char*)((char*)((void *)(::fnv_004b7210::FUN_004b7210())) + 0xe4) =
            (unsigned char)(int)((::fnv_007aa070::PerkForm *)(reinterpret_cast<::LBList *>((((ListBox<PerkForm*>*)((char*)this + 0x40))))->FindItemData((::Tile *)(apTarget))));
        ::DAT_011da4ed = true;
        if (((void *)(::GetCurrentArrayElement())) && *(void(__cdecl**)())((char*)((void *)(::GetCurrentArrayElement())) + 0x28))
        {
            (*(void(__cdecl**)())((char*)((void *)(::GetCurrentArrayElement())) + 0x28))();
        }
        ::DAT_011da4ed = false;
        if (::DAT_011da4ee)
        {
            ::DAT_011da4ee = false;
        }
        else
        {
            ::fnv_007aa530::CleanupGlobalObject();
        }
    }
}
}  // namespace fnv_007aa070

namespace fnv_007aa480 {
struct Elem_007aa480
{
    int Destroy(bool);
};
struct GlobalObject_007ab590
{
    unsigned int& GetAt(int);
    void Clear(bool);
};
// Iterates the global object's elements, calls Destroy(true) on each non-null one, then clears the object and resets DAT_011da4f4 to 0.
// @fnv 0x007aa480
void ClearAllElements()
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::fnv_007aa480::GlobalObject_007ab590 *>(&::g_011da53c))))->GetName())); i++)
    {
        Elem_007aa480* p;
        unsigned int v = ((unsigned int)(reinterpret_cast<::S3e60 *>(&((*reinterpret_cast<::fnv_007aa480::GlobalObject_007ab590 *>(&::g_011da53c))))->FUN_006a7ad0(i)));
        p = reinterpret_cast<Elem_007aa480*>(v);
        p ? p->Destroy(true) : 0;
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&((*reinterpret_cast<::fnv_007aa480::GlobalObject_007ab590 *>(&::g_011da53c))))->Clear(true);
    (*reinterpret_cast<int *>(&::DAT_011da4f4)) = 0;
}
}  // namespace fnv_007aa480

namespace fnv_007aa530 {
struct Elem_007aa530
{
    int Destroy(bool);
};
struct Obj_007aa530
{
    void PopulateFromMessageData();
};
struct GlobalObject_007ab590
{
    unsigned int& GetAt(int);
};
// @fnv 0x007aa530
void CleanupGlobalObject()
{
    unsigned int u;
    if (((int)(::GetCurrentArrayElement())))
    {
        u = ((unsigned int)(reinterpret_cast<::S3e60 *>(&((*reinterpret_cast<::fnv_007aa530::GlobalObject_007ab590 *>(&::g_011da53c))))->FUN_006a7ad0((*reinterpret_cast<int *>(&::DAT_011da4f4)))));
        Elem_007aa530* p;
        unsigned int v = u;
        p = reinterpret_cast<Elem_007aa530*>(v);
        p ? p->Destroy(true) : 0;
        reinterpret_cast<::FUN_006bf8f0_Class *>(&((*reinterpret_cast<::fnv_007aa530::GlobalObject_007ab590 *>(&::g_011da53c))))->FUN_006bf8f0((*reinterpret_cast<int *>(&::DAT_011da4f4)), true);
    }
    if (!((int)(::GetCurrentArrayElement())))
        ::fnv_007a8df0::FUN_007a8df0();
    else if ((*reinterpret_cast<::fnv_007aa530::Obj_007aa530 * *>(&::DAT_011da4f0)))
        (*reinterpret_cast<::fnv_007aa530::Obj_007aa530 * *>(&::DAT_011da4f0))->PopulateFromMessageData();
}
}  // namespace fnv_007aa530

namespace fnv_007aa6b0 {
struct GlobalObject2_0040c150
{
};
// Stores the flag in DAT_011da4ec and calls FUN_007a8df0 or FUN_007a8ba0/FUN_00709470 depending on DAT_011da4f0 and GetCurrentArrayElement.
// @fnv 0x007aa6b0
void FUN_007aa6b0(bool a)
{
    ::DAT_011da4ec = a;
    if (::DAT_011da4f0 && ::DAT_011da4ec)
        ::fnv_007a8df0::FUN_007a8df0();
    if (!::DAT_011da4f0 && !::DAT_011da4ec && ((int)(::GetCurrentArrayElement())))
    {
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_007aa6b0::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1)
            ::FUN_00709470(7, 0, 0, 0, 1);
        else
            ::fnv_007a8ba0::FUN_007a8ba0();
    }
}
}  // namespace fnv_007aa6b0

struct Al_007ab000
{
    char c;
};
struct Str_007ab000
{
    char data[0x1c];
    ~Str_007ab000();
    Str_007ab000(const Str_007ab000&, unsigned int, unsigned int, const Al_007ab000&);
    Str_007ab000 Substr(unsigned int _Off, unsigned int _Count) const;
};
// Returns a copy of the string constructed from this, _Off, _Count and the result of FUN_007ab230().
// @fnv 0x007ab000
Str_007ab000 Str_007ab000::Substr(unsigned int _Off, unsigned int _Count) const
{
    return Str_007ab000(*this, _Off, _Count, (*(::Al_007ab000 *)(reinterpret_cast<::Unk65a *>((void *)this)->FUN_007ab230({}))));
}

struct FUN_007abdb0_shell : public MessageMenu
{
    bool FUN_007abdb0();
};

// Checks the six int entries at offset 0x28 and returns true only if none of them is zero.
// @fnv 0x007abdb0
bool FUN_007abdb0_shell::FUN_007abdb0()
{
    for (int i = 0; i < 6; ++i)
    {
        if (*((int*)((char*)this + 0x28) + i) == 0)
            return false;
    }
    return true;
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_007a8ae0(unsigned int flags);
};
// Runs the destructor on this object, then frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x007a8ae0
void* DelStandIn::FUN_007a8ae0(unsigned int flags)
{
    reinterpret_cast<::FUN_007a8b10 *>((((DtorStandIn*)this)))->FUN_007a8b10::~FUN_007a8b10();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

namespace fnv_007aa500 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Calls the destructor, frees this when flags has bit 0 set, and returns this.
// @fnv 0x007aa500
void* DelStandIn::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_007a8960_cls *>((((DtorStandIn*)this)))->FUN_007a8960_cls::~FUN_007a8960_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_007aa500

struct StrMem
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    StrMem();
    ~StrMem();
};
class Tile
{
  public:
public:
    void Set(int, int);
public:
    static float GetInterfaceScale();
};
class Tile;
struct InterfaceManager
{
public:
    ::Tile *FUN_00586150();
public:
    static float UpdateInterfaceState();
};
struct FUN_007a8850
{
    StrMem strMessage;
    int iIcon;
    StrMem m_kTitle;
    StrMem strButtonText;
    bool bHasButtons;
    StrMem m_kSecondaryButtonText;
    int iButtonCount;
    int iType;
    StrMem strSound;
    bool bPauseGame;
    int iTileID;
    int iCallbackID;
    float fDisplayTime;
    float fBackgroundAlpha;
    int iFlags;
    FUN_007a8850();
};
// @fnv 0x007a8850
FUN_007a8850::FUN_007a8850()
{
    iIcon = 0;
    bHasButtons = false;
    iButtonCount = 0;
    iType = 0;
    bPauseGame = true;
    iTileID = -1;
    iCallbackID = -1;
    fDisplayTime = 0.0f;
    fBackgroundAlpha = reinterpret_cast<::TileListBoxCalls *>((((::Tile *)(reinterpret_cast<::MagicProjectile *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_004fd400()))))->GetFloat(FUN_00a01860("_background_fill_alpha"));
    iFlags = 0;
}

// @fnv 0x007a8de0
int FUN_007a8de0()
{
    return 1001;
}

extern char DAT_01202d54;

// @fnv 0x007aa6a0
void FUN_007aa6a0(unsigned char value)
{
    DAT_01202d54 = value;
}

namespace fnv_007aaf20 {
struct ArrSI
{
};

extern unsigned char DAT_011da594;

// @fnv 0x007aaf20
void __cdecl FUN_007aaf20(bool abFlag)
{
    if (abFlag)
    {
        ::DAT_011da4f4 = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::fnv_007aaf20::ArrSI *>(&::g_011da53c))))->GetName()));
        ::fnv_007a8df0::FUN_007a8df0();
        DAT_011da594 = (*reinterpret_cast<unsigned char *>(&::DAT_011da4ec));
        ::fnv_007aa6b0::FUN_007aa6b0(0);
    }
    else
    {
        ::DAT_011da4f4 = 0;
        ::fnv_007aa6b0::FUN_007aa6b0(DAT_011da594);
    }
}
}  // namespace fnv_007aaf20

struct Arr
{
    unsigned int* GetAt(int);
};

struct FUN_006f2270
{
    int m0;
    int m1;
    int m2;
    unsigned int* GetLast();
};

// @fnv 0x006f2270
unsigned int* FUN_006f2270::GetLast()
{
    return ((Arr*)this)->GetAt(m2 - 1);
}

struct FUN_007aafe0_Class
{
    void FUN_007aafe0(void* ap1, void* ap2);
};

// @fnv 0x007aafe0
void FUN_007aafe0_Class::FUN_007aafe0(void* pFirst, void* pSecond)
{
    reinterpret_cast<::FUN_005103d0_cls *>(this)->FindSubstring((char *)(void *)(&pFirst), (unsigned int)(pSecond), 1);
}

struct MessageMenuHandler
{
    void FUN_007ab0a0(void* first, void* second, void* third, unsigned int derivedValue);
    void FUN_007aaf80(void* first, void* second, void* third);
};


// Calls FUN_007ab0a0 with the three arguments and the value returned by FUN_0044a670(third).
// @fnv 0x007aaf80
void MessageMenuHandler::FUN_007aaf80(void* first, void* second, void* third)
{
    FUN_007ab0a0(first, second, third, ::FUN_0044a670((const char *)(third)));
}


struct FUN_007aafb0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int FUN_007aafb0(unsigned int arg);
};

// If arg exceeds unk14, calls FUN_00ec7c56; then returns the result of FUN_0044a970() plus arg.
// @fnv 0x007aafb0
int FUN_007aafb0_Class::FUN_007aafb0(unsigned int arg)
{
    if (arg > unk14)
    {
        std::abort();
    }

    do
    {
    } while (0);

    return ((int)(reinterpret_cast<::FUN_0044a970_Cls *>((this))->FUN_0044a970())) + arg;
}

namespace MessageCreation {
struct String
{
    char* data;
    unsigned short length, capacity;
    String(const char*);
    ~String();
    void FUN_00438390(const char*);
    void FUN_00404820(const char*);
};
struct Text
{
    unsigned int allocator;
    char buffer[16];
    unsigned int length, capacity;
    Text(const char*);
    ~Text();
    unsigned int FUN_007aafe0(char, unsigned int);
    Text Substr(unsigned int, unsigned int);
};
struct Message
{
    String message;
    char* icon;
    String title;
    String buttons;
    bool hasButtons;
    String hotkeys;
    int buttonCount, type;
    String sound;
    bool pause;
    int tileID, callback;
    float displayTime, alpha;
    unsigned int flags;
    Message();
};
void* FUN_00401000(unsigned int);
struct Messages
{
    Message** FUN_00877a30(unsigned int);
    Message** FUN_006f2270();
};
extern bool DAT_011da4ef;
struct Setting
{
};
// Builds a Message from the given title, text, icon, sound and buttons, inserts it into the message queue, and triggers the display update.
// @fnv 0x007a8e60
bool QueueMessage(const char* title, const char* message, const char* icon, const char* sound, int buttonCount,
                  bool hasButtons, int type, const char* firstButton, const char*** arguments, bool pause, int tileID,
                  int callback, float time, float alpha, float flags)
{
    Message* info = new Message;
    String buttonSlot11(firstButton);
    info->buttonCount = buttonCount;
    info->hasButtons = hasButtons;
    info->type = type;
    info->message.FUN_00438390(message);
    info->hotkeys.FUN_00438390(::DAT_01011584);
    info->title.FUN_00438390(title);
    info->sound.FUN_00438390(sound);
    info->pause = pause;
    info->tileID = tileID;
    info->callback = callback;
    info->displayTime = time * ::DAT_01017b70;
    if (alpha > ::_DAT_01012060)
        info->alpha = alpha * ::DAT_0101e568;
    info->flags = (unsigned int)flags;
    int iconLengthSlot11 = icon ? ((int)(::FUN_0044a670(icon))) : 0;
    if (iconLengthSlot11 > 0)
    {
        info->icon = new char[iconLengthSlot11 + 1];
        ::TaskQueueInterface::CopyStringToBuffer(info->icon, iconLengthSlot11 + 1, icon);
    }
    else
        info->icon = 0;
    while (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(buttonSlot11))->FUN_004048e0())) > 0)
    {
        Text text(((const char *)(::FUN_00559450((int *)&(buttonSlot11)))));
        unsigned int hotkeySlot0 = text.FUN_007aafe0('&', 0);
        if (hotkeySlot0 != ::g_010173f0)
        {
            info->hotkeys.FUN_00404820(::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(text.Substr(hotkeySlot0 + 1, 1))));
            reinterpret_cast<::MessageMenuHandler *>(&(text))->FUN_007aaf80((void *)(hotkeySlot0), (void *)(1), (void *)(::DAT_01011584));
        }
        if (::FUN_00408b20(::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(text)), ::DAT_01020770))
            info->buttons.FUN_00404820(::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(text)));
        info->buttons.FUN_00404820(::DAT_01063d7c);
        buttonSlot11.FUN_00438390((*arguments += 1)[-1]);
    }
    if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::MessageCreation::Messages *>(&::g_011da53c))))->GetName())))
    {
        for (unsigned int index = 0; index < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::MessageCreation::Messages *>(&::g_011da53c))))->GetName())); index++)
        {
            if (!((bool)(::GetByteAtOffset56((char *)((*(*reinterpret_cast<::MessageCreation::Messages *>(&::g_011da53c)).FUN_00877a30(index)))))) && ((bool)(::GetByteAtOffset56((char *)(info)))))
            {
                reinterpret_cast<::FUN_006f23d0_Class *>(&((*reinterpret_cast<::MessageCreation::Messages *>(&::g_011da53c))))->FUN_006f23d0(index, (void *&)(info));
                break;
            }
            else if (*(*reinterpret_cast<::MessageCreation::Messages *>(&::g_011da53c)).FUN_00877a30(index) == *((::MessageCreation::Message **)(reinterpret_cast<::FUN_006f2270 *>(&((*reinterpret_cast<::MessageCreation::Messages *>(&::g_011da53c))))->GetLast())))
            {
                reinterpret_cast<::FUN_00438690 *>(&((*reinterpret_cast<::MessageCreation::Messages *>(&::g_011da53c))))->FUN_007cb2e0((unsigned int *)&(info));
                break;
            }
        }
    }
    else
        reinterpret_cast<::FUN_00438690 *>(&((*reinterpret_cast<::MessageCreation::Messages *>(&::g_011da53c))))->FUN_007cb2e0((unsigned int *)&(info));
    if (!::DAT_011da4f0 && !::DAT_011da4ec && (!::fnv_007050d0::FUN_007050d0() || pause))
    {
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::MessageCreation::Setting *>(&::g_011c3ea4)))))) > 1)
            ::FUN_00709470(7, 0, 0, 0, 1);
        else
            ::fnv_007a8ba0::FUN_007a8ba0();
    }
    else
        DAT_011da4ef = true;
    return true;
}
}

struct KeyText
{
    int unk00, unk04, unk08;
};
struct KeyBinding
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    KeyText text;
    int type;
};
struct KeyString
{
    int allocator;
    union
    {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length, capacity;
    KeyString(const char*);
    ~KeyString();
};
struct KeyedList
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void* At(unsigned int, bool);
};
struct KeyMenu
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Select(int, void*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    KeyedList buttons;
    bool HandleKeyInput(int);
};
// @fnv 0x007aa110
bool KeyMenu::HandleKeyInput(int key)
{
    bool handled = false;
    if (GetCurrentArrayElement())
    {
        if (key == 1 && ((KeyBinding*)GetCurrentArrayElement())->type != 23)
        {
            Select(7, buttons.At(((unsigned int)(::GetRaceCount((char *)&(buttons)))) - 1, false));
            handled = true;
        }
        else if (key == 32)
        {
            Select(-1, ((void *)(::CallVirtualZero((::fnv_anon_startmenu::Dummy7d6e90 *)&(buttons)))));
            handled = true;
        }
        else if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(((KeyBinding*)GetCurrentArrayElement())->text))->FUN_004048e0())) > 0)
        {
            KeyString text(((const char *)(::FUN_00559450((int *)&(((KeyBinding*)GetCurrentArrayElement())->text)))));
            for (unsigned int index = 0; index < reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(text))->FUN_00825c00(); index++)
            {
                if (toupper(((char)(reinterpret_cast<::FUN_007aafb0_Class *>(&(text))->FUN_007aafb0(index)))) == toupper(key))
                {
                    Select(7, buttons.At(index, false));
                    handled = true;
                    break;
                }
            }
        }
    }
    return handled;
}

struct FUN_007aa2a0_shell : MessageMenu
{
    void UpdateMenuAction();
};
struct TimerCalls
{
};
struct TileCalls
{
};
struct MenuActionCalls
{
};
// @fnv 0x007aa2a0
void FUN_007aa2a0_shell::UpdateMenuAction()
{
    reinterpret_cast<::GameTimerRecord *>((reinterpret_cast<TimerCalls*>(&m_kTimerCalls)))->Update();
    static unsigned int lastCheckTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimerCalls*>(&m_kTimerCalls)))->FUN_00825c00();
    if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimerCalls*>(&m_kTimerCalls)))->FUN_00825c00() - lastCheckTime < 200)
        return;
    {
        lastCheckTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimerCalls*>(&m_kTimerCalls)))->FUN_00825c00();
        if (GetCurrentArrayElement())
        {
            if (static_cast<unsigned char>(GetByteAtOffset56(reinterpret_cast<char*>(GetCurrentArrayElement()))) == 0)
            {
                if (reinterpret_cast<::FUN_00a01230_shell *>((reinterpret_cast<TileCalls*>(m_pTiles[0])))->IsTraitNonZero(0xfa3))
                {
                    if (((int)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType())) == 4)
                    {
                        if (m_uiMessageCount == 0)
                        {
                            reinterpret_cast<::FUN_00a1db20_shell *>(this)->FUN_00a1db20();
                        }
                        else
                        {
                            ::fnv_007aa530::CleanupGlobalObject();
                            m_uiMessageCount = 0;
                        }
                    }
                    else
                    {
                        if (((int)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType())) == 1)
                        {
                            unsigned int message = GetCurrentArrayElement();
                            if (!m_uiMessageCount)
                                m_uiMessageCount = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimerCalls*>(&m_kTimerCalls)))->FUN_00825c00();
                            if (*reinterpret_cast<float*>(message + 0x44) > ::_DAT_01012060)
                            {
                                if (*reinterpret_cast<float*>(message + 0x44) <=
                                    (unsigned int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimerCalls*>(&m_kTimerCalls)))->FUN_00825c00() -
                                                   m_uiMessageCount))
                                {
                                    if (message == *reinterpret_cast<FUN_006f2270*>(&(*reinterpret_cast<::BSSimpleArray<unsigned int, 1024> *>(&::g_011da53c)))->GetLast())
                                    {
                                        reinterpret_cast<::Tile *>((reinterpret_cast<MenuActionCalls*>(reinterpret_cast<::Callees *>(this)->FUN_00726070())))->Set({}, {});
                                        ::fnv_007aa530::CleanupGlobalObject();
                                    }
                                    else
                                    {
                                        reinterpret_cast<::FUN_00a1d910_shell *>(this)->FUN_00a1d910();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

struct ActionMenuReference;
struct ActionMenuStoredString
{
    char* data;
    unsigned short size, capacity;
    void FUN_00438390(const char*);
    void FUN_00404820(const char*);
};
struct ActionMenuText
{
    char* data;
    unsigned unk04, unk08, unk0C, unk10, size, capacity;
    ActionMenuText(const char*);
    ~ActionMenuText();
    unsigned FUN_007aafe0(char, unsigned);
    ActionMenuText Substr(unsigned, unsigned);
};
struct ActionMenuInfo
{
    ActionMenuStoredString message;
    int icon;
    ActionMenuStoredString title, buttons;
    bool hasButtons;
    ActionMenuStoredString hotkeys;
    void (*callback)();
    int type;
    ActionMenuStoredString sound;
    int pause, tile, callbackId;
    float displayTime, backgroundAlpha;
    int flags;
    ActionMenuInfo();
};
struct ActionMenuSetting
{
};
struct ActionMenuCountSetting
{
};
struct ActionMenuBase
{
    unsigned FUN_00401170();
};
struct ActionMenuOwner
{
};
struct ActionMenuReference
{
};
struct ActionMenuAction
{
    virtual void Slot0();
    virtual int GetKind();
};
struct ActionMenuList
{
    bool FUN_008256d0();
};
struct ActionMenuEntry
{
    const char* label;
    int action;
    ActionMenuReference* reference;
};
template <class T> struct ActionMenuQueue
{
    void FUN_007cb2e0(T const&);
};
int FUN_0047b250(ActionMenuReference*);
// Builds an ActionMenuInfo with title, hotkeys and buttons from the list's actions and the reference's action type, queues entries and the menu, and opens it.
// @fnv 0x007aa720
bool BuildActionMenu(ActionMenuList* list, ActionMenuReference* reference)
{
    ActionMenuInfo* menu4 = new ActionMenuInfo;
    menu4->callback = ::fnv_007aae70::FUN_007aae70;
    menu4->hasButtons = false;
    menu4->type = 0;
    menu4->message.FUN_00438390(0);
    menu4->hotkeys.FUN_00438390(DAT_01011584);
    menu4->title.FUN_00438390(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ActionMenuSetting *>(&::g_011d2280))))->GetMenuTitle())));
    char label58[260];
    while (list && !list->FUN_008256d0())
    {
        ::TaskQueueInterface::CopyStringToBuffer(label58, 260, ((const char *)(reinterpret_cast<::Callees *>(((*((::ActionMenuAction **)(new ((void *)(list)) ::Vec3())))))->FUN_00726070())));
        if ((*((::ActionMenuAction **)(new ((void *)(list)) ::Vec3())))->GetKind() == 4)
        {
            if (!((const char *)(reinterpret_cast<::Callees *>(((*((::ActionMenuAction **)(new ((void *)(list)) ::Vec3())))))->FUN_00726070())) || !((int)(reinterpret_cast<::TESTopicInfoData *>(((*((::ActionMenuAction **)(new ((void *)(list)) ::Vec3())))))->GetLinkToList())))
            {
                list = ((::ActionMenuList *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                continue;
            }
            ActionMenuEntry* entry29 = new ActionMenuEntry;
            entry29->label = ((const char *)(reinterpret_cast<::Callees *>(((*((::ActionMenuAction **)(new ((void *)(list)) ::Vec3())))))->FUN_00726070()));
            entry29->action = ((int)(reinterpret_cast<::TESTopicInfoData *>(((*((::ActionMenuAction **)(new ((void *)(list)) ::Vec3())))))->GetLinkToList()));
            entry29->reference = reference;
            reinterpret_cast<::FUN_00438690 *>(&((*reinterpret_cast<::ActionMenuQueue< ::ActionMenuEntry *> *>(&::g_011da524))))->FUN_007cb2e0((unsigned int *)&(entry29));
            if (FUN_0044a670(label58) > 0)
            {
                ActionMenuText text6(label58);
                unsigned hotkey5 = text6.FUN_007aafe0('&', 0);
                if (hotkey5 != ::g_010173f0)
                {
                    menu4->hotkeys.FUN_00404820(::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(text6.Substr(hotkey5 + 1, 1))));
                    reinterpret_cast<::MessageMenuHandler *>(&(text6))->FUN_007aaf80((void *)(hotkey5), (void *)(1), (void *)(DAT_01011584));
                }
                if (FUN_00408b20(::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(text6)), DAT_01020770))
                {
                    menu4->buttons.FUN_00404820(::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(text6)));
                    menu4->buttons.FUN_00404820(DAT_01063d7c);
                }
            }
        }
        list = ((::ActionMenuList *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
    int action3 = reinterpret_cast<::fnv_00579280::ReferenceView *>((reference))->FUN_00579280();
    unsigned type22 = ((::ActionMenuBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))->FUN_00401170();
    ActionMenuOwner* owner15 = ((::ActionMenuOwner *)(reinterpret_cast<::FUN_00569160_shell *>((reference))->FUN_00569160()));
    ActionMenuBase* base7 = ((::ActionMenuBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
    if (action3 == 1 && reinterpret_cast<::xRefr *>((reference))->FUN_00579690())
    {
        ::TaskQueueInterface::CopyStringToBuffer(label58, 260, type22 == 42 ? ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ActionMenuSetting *>(&::g_011d3708))))->GetMenuTitle())) : ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ActionMenuSetting *>(&::g_011d4f48))))->GetMenuTitle())));
    }
    else if (action3 == 2 && (type22 == 42 || type22 == 43))
    {
        ::TaskQueueInterface::CopyStringToBuffer(label58, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ActionMenuSetting *>(&::g_011d38dc))))->GetMenuTitle())));
    }
    else if (action3 == 8 && type22 == 28)
    {
        bool isChair = FUN_0047b250(reference) == 1 || FUN_0047b250(reference) == 2;
        if (owner15 && reinterpret_cast<::LockExtraData *>((owner15))->IsLocked() && !reinterpret_cast<::OwnershipReferenceView *>((reference))->FUN_005785e0((::Actor *)((*reinterpret_cast<::ActionMenuReference * *>(&::_g_thePlayer))), true) &&
            (!base7 || !::TESObjectDOOR::ProcessDoorActivation((::TESObjectREFR *)(reference), (::Actor *)((*reinterpret_cast<::ActionMenuReference * *>(&::_g_thePlayer))), 0, 1)))
        {
            ::TaskQueueInterface::CopyStringToBuffer(label58, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ActionMenuSetting *>(&::g_011d45a0))))->GetMenuTitle())));
        }
        else
        {
            ::TaskQueueInterface::CopyStringToBuffer(label58, 260, isChair ? ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ActionMenuSetting *>(&::g_011d22b0))))->GetMenuTitle())) : ((const char *)(reinterpret_cast<::StartMenu *>((DAT_011d5160[action3]))->GetMenuTitle())));
        }
    }
    else if (action3 && action3 < 20)
    {
        ::TaskQueueInterface::CopyStringToBuffer(label58, 260, ((const char *)(reinterpret_cast<::StartMenu *>((DAT_011d5160[action3]))->GetMenuTitle())));
    }
    else if (action3 == 0)
    {
        ::TaskQueueInterface::CopyStringToBuffer(label58, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ActionMenuSetting *>(&::g_011d29f4))))->GetMenuTitle())));
    }
    if (FUN_0044a670(label58) > 0)
    {
        ActionMenuText text6(label58);
        unsigned hotkey5 = text6.FUN_007aafe0('&', 0);
        if (hotkey5 != ::g_010173f0)
        {
            menu4->hotkeys.FUN_00404820(::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(text6.Substr(hotkey5 + 1, 1))));
            reinterpret_cast<::MessageMenuHandler *>(&(text6))->FUN_007aaf80((void *)(hotkey5), (void *)(1), (void *)(DAT_01011584));
        }
        if (FUN_00408b20(::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(text6)), DAT_01020770))
        {
            menu4->buttons.FUN_00404820(::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(text6)));
            menu4->buttons.FUN_00404820(DAT_01063d7c);
        }
    }
    ActionMenuEntry* entry29 = new ActionMenuEntry;
    entry29->label = label58;
    entry29->action = 0;
    entry29->reference = reference;
    reinterpret_cast<::FUN_00438690 *>(&((*reinterpret_cast<::ActionMenuQueue< ::ActionMenuEntry *> *>(&::g_011da524))))->FUN_007cb2e0((unsigned int *)&(entry29));
    reinterpret_cast<::FUN_00438690 *>(&((*reinterpret_cast<::ActionMenuQueue< ::ActionMenuInfo *> *>(&::g_011da53c))))->FUN_007cb2e0((unsigned int *)&(menu4));
    if (!DAT_011da4f0 && !DAT_011da4ec)
    {
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ActionMenuCountSetting *>(&::g_011c3ea4)))))) > 1)
            ::FUN_00709470(7, 0, 0, 0, 1);
        else
            ::fnv_007a8ba0::FUN_007a8ba0();
    }
    return true;
}

namespace MessageMenuSetup {

struct MsgTile
{
};

struct MsgSize
{
    float x, y, z;
};

struct MsgFont
{
    MsgSize FUN_00a1b020(const char* apText, int aiFont, float afWidth, int aiFlags);
};

struct MsgSound
{
    unsigned int unk0, unk4, unk8;
    ~MsgSound();
};

struct MsgAudio
{
    MsgSound FUN_00ad7550(const char* apEditorID, int aiFlags);
};

struct MsgText
{
    char* pString;
    unsigned short usLength;
    unsigned short usCapacity;
};

struct MsgString
{
    char acData[0x1c];
    MsgString(const char* apText);
    ~MsgString();
    unsigned int FUN_005103a0(const char* apDelimiter, unsigned int auiStart);
    MsgString Substr(unsigned int auiStart, unsigned int auiLength);
};

struct MsgData
{
    MsgText kTitle;
    const char* pIcon;
    MsgText kText;
    MsgText kButtons;
    char cButtonBase;
    char pad1d[0xf];
    int iType;
    MsgText kSound;
    char pad38[4];
    int iX;
    int iY;
    char pad44[4];
    float fAlpha;
    unsigned int uiWidth;
};

struct MsgList
{
    virtual void l000();
    virtual void l001();
    virtual void l002();
    virtual void l003();
    virtual void l004();
    virtual void l005();
    virtual void l006();
    virtual void Clear();
};

struct MsgInterface
{
};

struct MsgMenu
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
    virtual int GetID();
    char pad04[0x24];
    MsgTile* m_pTiles[6];
    MsgList kButtons;
    void PopulateFromMessageData();
};


static const char s_szHorBuf[] = "_horbuf";
static const char s_szPopUp[] = "UIPopUpMessageWindow";
static const char s_szListItemText[] = "ListItemText";
static const char s_szMaxMenuWidth[] = "_MaxMenuWidth";
static const char s_szMinMenuWidth[] = "_MinMenuWidth";

// Populates message menu tiles and buttons, computes layout dimensions, and sets menu position and alpha from the current message data.
// @fnv 0x007a92e0
void MsgMenu::PopulateFromMessageData()
{
    if (!((::MessageMenuSetup::MsgData *)(::GetCurrentArrayElement())))
        return;
    MsgData* pMessagePtr = ((::MessageMenuSetup::MsgData *)(::GetCurrentArrayElement()));
    float fIconHeightIn = 0.0f;
    float fTheTextHeight = 0.0f;
    float fButtonsWidth = 0.0f;
    float fWidths = 0.0f;
    float fHorBuf = reinterpret_cast<::TileListBoxCalls *>((((::MessageMenuSetup::MsgTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(::FUN_00a01860(s_szHorBuf));
    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(pMessagePtr->kSound))->FUN_004048e0())) > 0 &&
        reinterpret_cast<::GO *>((void *)&(const ::MessageMenuSetup::MsgSound &)(((::MessageMenuSetup::MsgAudio *)(::FUN_00453a70()))->FUN_00ad7550(((const char *)(::FUN_00559450((int *)&(pMessagePtr->kSound)))), 0x121)))->IsNotEqual(-1))
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::MessageMenuSetup::MsgSound &)(((::MessageMenuSetup::MsgAudio *)(::FUN_00453a70()))->FUN_00ad7550(((const char *)(::FUN_00559450((int *)&(pMessagePtr->kSound)))), 0x121)))->FUN_00ad8830(0);
    else
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::MessageMenuSetup::MsgSound &)(((::MessageMenuSetup::MsgAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szPopUp, 0x121)))->FUN_00ad8830(0);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[3]))->FUN_00a01350(0xfc4, (char *)(((const char *)(::FUN_00559450((int *)&(pMessagePtr->kText))))), true);
    if (pMessagePtr->pIcon)
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[1]))->FUN_00a01350(0xfc4, (char *)(pMessagePtr->pIcon), true);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[1]))->Set(0xfa3, 1);
        float fIconWidth =
            pMessagePtr->uiWidth > 0 ? (float)pMessagePtr->uiWidth : reinterpret_cast<::TileListBoxCalls *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[1]))->GetFloat(0xfba);
        fIconHeightIn =
            ((::MessageMenuSetup::MsgFont *)(::FontManager::Instance()))->FUN_00a1b020(pMessagePtr->pIcon, 6, fIconWidth != 0.0 ? fIconWidth : ::DAT_01016970, 0).x;
        fIconHeightIn = fIconHeightIn + (pMessagePtr->uiWidth > 0 ? 0.0f : 100.0f);
    }
    else
    {
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[1]))->Set(0xfa3, 0);
    }
    MsgTile* pItemNew = 0;
    unsigned int uiPosNum = 0;
    int iMaxWidthCur = 0;
    float fListHeightTmp = 0.0f;
    int iIndex = 0;
    kButtons.Clear();
    if (((const char *)(::FUN_00559450((int *)&(pMessagePtr->kButtons)))))
    {
        MsgString kButtonText(((const char *)(::FUN_00559450((int *)&(pMessagePtr->kButtons)))));
        for (iIndex = 0; uiPosNum < reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(kButtonText))->FUN_00825c00() - 1; iIndex++)
        {
            MsgString kPart = kButtonText.Substr(uiPosNum, kButtonText.FUN_005103a0(::DAT_01063d7c, uiPosNum) - uiPosNum);
            if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(kPart))->FUN_00825c00() > 0)
            {
                MsgTile* pText = 0;
                pItemNew = ((::MessageMenuSetup::MsgTile *)(reinterpret_cast<::IntListBox *>(&((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->kButtons))->FUN_00764430(
                    pMessagePtr->cButtonBase + iIndex,
                    ::FUN_0044a560((::std::basic_string<char, ::std::char_traits<char>, ::std::allocator<char>> *)&(kButtonText.Substr(uiPosNum, kButtonText.FUN_005103a0(::DAT_01063d7c, uiPosNum) - uiPosNum))),
                    (int (*)(BoxItem *, BoxItem *))(0), (const char *)(0))));
                pText = ((::MessageMenuSetup::MsgTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pItemNew))->FUN_00a03da0((char *)(s_szListItemText))));
                reinterpret_cast<::Tile *>((pItemNew))->Set(0xfaa, 7);
                if (pText)
                {
                    float fItemWidth =
                        pMessagePtr->uiWidth > 0 ? (float)pMessagePtr->uiWidth : reinterpret_cast<::TileListBoxCalls *>((pText))->GetFloat(0xfba);
                    fItemWidth = fItemWidth != 0.0 ? fItemWidth : ::DAT_01016970;
                    iMaxWidthCur =
                        ::FUN_00647b70(iMaxWidthCur,
                                     (int)((::MessageMenuSetup::MsgFont *)(::FontManager::Instance()))->FUN_00a1b020(reinterpret_cast<::FUN_00a011f0_shell *>((pText))->FUN_00a011f0(0xfc4), 2, fItemWidth, 0).x);
                }
                fListHeightTmp = reinterpret_cast<::TileListBoxCalls *>((pItemNew))->GetFloat(0xfb0) + fListHeightTmp;
            }
            uiPosNum = kButtonText.FUN_005103a0(::DAT_01063d7c, uiPosNum);
            if (uiPosNum < reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(kButtonText))->FUN_00825c00() - 1)
                uiPosNum = uiPosNum + 1;
        }
    }
    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(pMessagePtr->kTitle))->FUN_004048e0())) > 0)
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[2]))->FUN_00a01350(0xfcc, (char *)(((const char *)(::FUN_00559450((int *)&(pMessagePtr->kTitle))))), true);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[2]))->Set(0xfa3, 1);
        if (pMessagePtr->uiWidth > 0)
            fTheTextHeight = ::FUN_0040ebd0(fTheTextHeight + 120.0, (float)pMessagePtr->uiWidth);
        else
            fTheTextHeight = fTheTextHeight + 120.0;
    }
    else
    {
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[2]))->Set(0xfa3, 0);
    }
    if (pMessagePtr->uiWidth > 0)
        fButtonsWidth = ::FUN_0040ebd0(iMaxWidthCur + 80.0, (float)pMessagePtr->uiWidth);
    else
        fButtonsWidth = iMaxWidthCur + 80.0;
    reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[4]))->FUN_00a012d0(0xfb0, fListHeightTmp, false);
    reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[4]))->FUN_00a012d0(0xfb1, fButtonsWidth, false);
    reinterpret_cast<::C764930ListMenu *>(&((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->kButtons))->RebuildVisibleTiles();
    if (pMessagePtr->uiWidth > 0)
        fButtonsWidth = ::FUN_0040ebd0(fHorBuf * 2 + fButtonsWidth, (float)pMessagePtr->uiWidth);
    else
        fButtonsWidth = fHorBuf * 2 + fButtonsWidth;
    float fMaxWidthCur = ::DAT_01016970;
    if (pMessagePtr->uiWidth > 0)
        fMaxWidthCur = ::InterfaceManager::UpdateInterfaceState() * (pMessagePtr->uiWidth / ::FUN_00706e50());
    else
        fMaxWidthCur = reinterpret_cast<::TileListBoxCalls *>((((::MessageMenuSetup::MsgTile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))))->FUN_00726070()))))->GetFloat(::FUN_00a01860(s_szMaxMenuWidth));
    fMaxWidthCur = fMaxWidthCur - fHorBuf * 2;
    if (reinterpret_cast<::FUN_00a01230_shell *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[2]))->IsTraitNonZero(0xfa3))
        fMaxWidthCur = fMaxWidthCur - 120.0;
    reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[3]))->FUN_00a012d0(0xfba, fMaxWidthCur, true);
    MsgSize kSizeFinal = ((::MessageMenuSetup::MsgFont *)(::FontManager::Instance()))->FUN_00a1b020(((const char *)(::FUN_00559450((int *)&(pMessagePtr->kText)))), 2,
                                                      reinterpret_cast<::TileListBoxCalls *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[3]))->GetFloat(0xfba), 0);
    fTheTextHeight = fHorBuf * 2 + kSizeFinal.x + fTheTextHeight;
    if (kSizeFinal.z > 1.0)
    {
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[1]))->Set(0xfb7, 1);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[3]))->Set(0xfb7, 1);
    }
    else
    {
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[1]))->Set(0xfb7, 2);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[3]))->Set(0xfb7, 2);
    }
    if (pMessagePtr->uiWidth == 0)
    {
        fWidths = ::FUN_00404010(fIconHeightIn, fTheTextHeight);
        fWidths = ::FUN_00404010(fWidths, fButtonsWidth);
        fWidths = ::FUN_0040ebd0(fWidths, reinterpret_cast<::TileListBoxCalls *>((((::MessageMenuSetup::MsgTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(::FUN_00a01860(s_szMaxMenuWidth)));
        fWidths = ::FUN_00404010(fWidths, reinterpret_cast<::TileListBoxCalls *>((((::MessageMenuSetup::MsgTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->GetFloat(::FUN_00a01860(s_szMinMenuWidth)));
    }
    else
    {
        fWidths = ::InterfaceManager::UpdateInterfaceState() * (pMessagePtr->uiWidth / ::FUN_00706e50());
        fWidths = ::FUN_0040ebd0(fWidths, ::InterfaceManager::UpdateInterfaceState() - ::FUN_007177c0() * 2);
    }
    reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[0]))->FUN_00a012d0(0xfb1, fWidths, true);
    ::DAT_0119f348 = pMessagePtr->iType == 0x17;
    reinterpret_cast<::Tile *>((((::MessageMenuSetup::MsgTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(0x1772, 0);
    reinterpret_cast<::Tile *>((((::MessageMenuSetup::MsgTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(0xfa3, 1);
    if (!((bool)(::GetByteAtOffset56((char *)(pMessagePtr)))))
    {
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[0]))->FUN_00a012d0(0xfa9, 0.0f, true);
        if (reinterpret_cast<::FUN_00714f90_shell *>((((::MessageMenuSetup::MsgInterface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00714f90(GetID()))
            ::FUN_00706fd0(GetID(), 1);
        float fScreenWidth = ::InterfaceManager::UpdateInterfaceState();
        float fMenuWidth = reinterpret_cast<::TileListBoxCalls *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[0]))->GetFloat(0xfb1);
        float fScreenHeight = ::FUN_00715da0();
        float fMenuHeightNew = reinterpret_cast<::TileListBoxCalls *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[0]))->GetFloat(0xfb0);
        float fXNew = (fScreenWidth - fMenuWidth) / 2.0;
        float fY = (fScreenHeight - fMenuHeightNew) / 2.0;
        if (pMessagePtr->iX > -1)
        {
            float fLeft = pMessagePtr->iX / ::FUN_00706e50() * fScreenWidth;
            fXNew = ::FUN_00404010(fLeft, ::FUN_007177c0());
            fXNew = ::FUN_0040ebd0(fXNew, fScreenWidth - fMenuWidth - ::FUN_007177c0());
        }
        if (pMessagePtr->iY > -1)
        {
            float fTop = pMessagePtr->iY / ::FUN_00706e20() * fScreenHeight;
            fY = ::FUN_00404010(fTop, ::fnv_00717820::FUN_00717820());
            fY = ::FUN_0040ebd0(fY, fScreenHeight - fMenuHeightNew - ::fnv_00717820::FUN_00717820());
        }
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[0]))->FUN_00a012d0(0xfa1, fXNew, true);
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[0]))->FUN_00a012d0(0xfa2, fY, true);
    }
    else
    {
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[0]))->FUN_00a012d0(0xfa9, 1.0f, true);
        if (!reinterpret_cast<::FUN_00714f90_shell *>((((::MessageMenuSetup::MsgInterface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00714f90(GetID()))
            ::FUN_00706fb0(GetID());
    }
    reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::MessageMenuSetup::MsgMenu * *>(&::DAT_011da4f0))->m_pTiles[5]))->FUN_00a012d0(0xfa9, pMessagePtr->fAlpha, true);
}

}

namespace fnv_007a8ba0 {

struct VDel
{
    virtual ~VDel();
};
struct Helper
{
    void FUN_0075a0d0(void* arg1, const char* arg2);
};


// Initializes the message menu interface from Data\Menus\message_menu.xml, configures its buttons and background, and returns success.
// @fnv 0x007a8ba0
bool __cdecl FUN_007a8ba0()
{
    InterfaceManager* B = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
    unsigned char flag = 0;
    VDel* pVDel = (VDel*)((void *)(::FUN_00a09030(::FUN_007a8de0())));
    if (pVDel != 0)
    {
        delete pVDel;
    }
    if (::fnv_007023c0::FUN_007023c0())
        flag = 1;
    Tile* pTile = reinterpret_cast<::fnv_00a01b00::TileLoader *>((((Helper*)((void *)(reinterpret_cast<::InterfaceManager *>((((Helper*)B)))->FUN_00586150())))))->FUN_00a01b00({});
    ::DAT_011da4f0 = ((int)(reinterpret_cast<::FUN_00a03c90_shell *>((((Helper*)pTile)))->FUN_00a03c90()));
    if (::DAT_011da4f0 != 0 &&
        ((int(*)(void*))((*(void***)::DAT_011da4f0)[13]))((void*)::DAT_011da4f0) == ::FUN_007a8de0())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((((Helper*)::DAT_011da4f0)))->FUN_00a1dc70((::TileMenu *)(pTile), 0);
        if (!((FUN_007abdb0_shell*)::DAT_011da4f0)->FUN_007abdb0())
        {
            ::FUN_0040fbe0();
            return false;
        }
        if (((double)(reinterpret_cast<::TileListBoxCalls *>((((Helper*)pTile)))->GetFloat(0xfa7))) == ::DAT_010704f0 ||
            ((double)(reinterpret_cast<::TileListBoxCalls *>((((Helper*)pTile)))->GetFloat(0xfa7))) == ::DAT_010704e8)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((((Helper*)pTile)))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), 1);
        }
        ((Helper*)((char*)::DAT_011da4f0 + 0x40))
            ->FUN_0075a0d0(*(void**)((char*)::DAT_011da4f0 + 0x38), "MM_ButtonTemplate");
        if (::GetCurrentArrayElement() != 0)
        {
            reinterpret_cast<::MessageMenuSetup::MsgMenu *>((((Helper*)::DAT_011da4f0)))->PopulateFromMessageData();
        }
        if (flag)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((((Helper*)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Helper*)(reinterpret_cast<::Callees *>((((Helper*)::DAT_011da4f0)))->FUN_00726070()))))->FUN_00a03da0((char *)((char*)"MM_Background"))))))->FUN_00a012d0(0xfa9, *(float*)(((void *)&(::FUN_00403e20((float *)(((Helper*)&(*reinterpret_cast<char *>(&::g_011d3bc8)))))))) * ::DAT_0101e568, 1);
        }
        if (((unsigned char)(::fnv_007050d0::FUN_007050d0())))
        {
            ::SetDialogMenuActive(1);
        }
        reinterpret_cast<::Menu *>((((Helper*)::DAT_011da4f0)))->SetMenuVisibility(0);
        ::Interface::SetHUDVisible(0);
        return true;
    }
    else
    {
        if (::DAT_011da4f0 != 0 && reinterpret_cast<::Callees *>((((Helper*)::DAT_011da4f0)))->FUN_00726070() != 0)
        {
            delete (VDel*)::DAT_011da4f0;
        }
    }
    return false;
}
}  // namespace fnv_007a8ba0


struct ArrSI
{
};
struct MessageQueueEntryView
{
    BSStringT<char> m_kMessageText;
    char* m_kTitle;
    BSStringT<char> m_kPrimaryButtonText;
    BSStringT<char> m_kTertiaryButtonText;
    char m_cButtonCount;
    BSStringT<char> m_kSecondaryButtonText;
    void(__cdecl* aCallback)();
    unsigned int m_uiMessageFlags;
};
struct MessageQueueComparisonArray
{
    MessageQueueEntryView** FUN_00877a30(int);
};
struct GlobalObject_00869f00
{
};
struct GlobalObject_007ab590;
class MessageHandler
{
  public:
    static MessageHandler* pHandler;
};
struct FUN_007aa500
{
    ~FUN_007aa500();
};

// @fnv 0x007aa5c0
void FUN_007aa5c0()
{
    if (::GetCurrentArrayElement())
    {
        unsigned int uiID = ((MessageQueueEntryView*)::GetCurrentArrayElement())->m_uiMessageFlags;
        reinterpret_cast<::FUN_00aa4c40_class *>((MessageHandler::pHandler))->FUN_00aa4c40(uiID);
        ::FUN_007aa6a0(true);
        for (unsigned int i = DAT_011da4f4; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&::g_011da53c)))->GetName())); i++)
        {
            if ((*((MessageQueueComparisonArray*)&::g_011da53c)->FUN_00877a30(i))->m_uiMessageFlags == uiID)
            {
                FUN_007aa500* pEntry = (FUN_007aa500*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&::g_011da53c)))->FUN_006a7ad0(i)));
                delete pEntry;
                reinterpret_cast<::FUN_006bf8f0_Class *>((((GlobalObject_00869f00*)&::g_011da53c)))->FUN_006bf8f0(i--, true);
            }
        }
    }
}

namespace fnv_007aae70 {

class ScriptLocals;
class TESBoundObject;
class Script
{
  public:
};
struct TESObjectREFR_acc
{
    bool Activate(TESObjectREFR*, bool, TESBoundObject*, int);
};
struct ArrSI
{
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct GlobalObject_007ab610;
struct PC7d;

struct PerkActivationEntry
{
    unsigned int uiButton;
    Script* pScript;
    TESObjectREFR* pRef;
};

// @fnv 0x007aae70
void FUN_007aae70()
{
    unsigned int ibuttonClicked;
    int icount;
    ibuttonClicked = ::ConsumeByteAtE4();
    if (ibuttonClicked != ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->GetName())) - 1)
    {
        reinterpret_cast<::FUN_005ac1e0_shell *>((((PerkActivationEntry*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->FUN_006a7ad0(ibuttonClicked))))
            ->pScript))->FUN_005ac1e0(
                ((PerkActivationEntry*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->FUN_006a7ad0(ibuttonClicked))))->pRef,
                (::ScriptLocals *)(::fnv_007aae70::ScriptLocals *)(0), 0, false);
    }
    else
    {
        icount = ::GetExtraDataShort(
            ((PerkActivationEntry*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->FUN_006a7ad0(ibuttonClicked))))->pRef);
        ((TESObjectREFR_acc*)((PerkActivationEntry*)((unsigned int)(reinterpret_cast<::S3e60 *>((((BSSimpleArray<unsigned int, 1024>*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->FUN_006a7ad0(ibuttonClicked))))
             ->pRef)
            ->Activate((TESObjectREFR*)(*reinterpret_cast<::fnv_007aae70::PC7d * *>(&::_g_thePlayer)), false, 0, icount);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)&(*reinterpret_cast<::fnv_007aae70::GlobalObject_007ab610 *>(&::g_011da524)))))->Clear(true);
}
}  // namespace fnv_007aae70
#include "generated/data/fallout/interface/menus/messagemenu.inc"
