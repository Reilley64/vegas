// fallout/interface/interfacemanager_packet.h: declares Interface, InterfaceManager, TESEnchantableForm, MiddleHighProcess, NiPoint2 and more

#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_004a4020_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00a25560_Class.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_011de000.h"
class NiNode;
class FOPipboyManager;
class TESForm;
class Interface
{
  public:
    enum enumGamepadButtons
    {
        ButtonZero
    };
public:
    ::FOPipboyManager *GetPipboyManager();
public:
    static void SetQuestTarget(::TESForm *, bool);
public:
    static bool IsInterfaceActive();
public:
    static float GetFourthInterfaceFloat();
public:
    static bool IsInterfaceOpen();
};
enum GAMEPAD_BUTTON
{
    GamepadZero
};
class Tile;
class FORenderedMenu;
class Tile;
class InterfaceManager
{
  public:
    char padding[0xc];
    int unk0c;
    char pad10[0x2];
    char unk12;
    char unk13;
    char pad14[0x4];
    int unk18;
    char pad1c[0x4];
    unsigned char unk20;
    char pad21[0x57];
    int unk78;
    char pad7c[0x1];
    bool unk7d;
    char pad7e[0x2];
    void* unk80;
    void* unk84;
    char pad88[0x14];
    void* unk9c;
    void* unka0;
    void* unka4;
    float unka8;
    char padac[0x10];
    void* unkbc;
    char padc0[0x8];
    bool unkc8;
    char padc9[0x3];
    void* unkcc;
    void* unkd0;
    char padd4[0x8];
    bool unkdc;
    char paddd[0x10];
    bool unked;
    char padee[0xe];
    void* unkfc;
    void* unk100;
    char pad104[0xc];
    union
    {
        struct
        {
            int unusedStackSlot;
            int enterStack[10];
        };
        int previousStack[11];
    };
    int GetMenuStackEntry(int);
    int GetTopEnterStackEntry();
    void AddTileIfAbsent(Tile*);
    static float UpdateInterfaceState();
    static void SendGamepadButton(Interface::enumGamepadButtons);
    static GAMEPAD_BUTTON ConvertGamepadButton(Interface::enumGamepadButtons);
    static bool IsInterfaceMenuActive();
public:
    ::Tile *FUN_00586150();
public:
    ::FORenderedMenu *GetActiveRenderedMenu();
};
enum MagicSystem__CastingType
{
    CastingTypeZero
};
class TESEnchantableForm
{
  public:
};
class TargetDoorController;
class MiddleHighProcess
{
  public:
    char padding[0xe4];
    TESEnchantableForm enchantable;
    void SetRunOncePackageIndex(int);
public:
    void AddDeferredHideLimb(::TargetDoorController *);
};
class TESIdleForm;
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int Add(T&);
    bool FUN_009962f0(T&);
};
class GlobalObject_00719b80 : public BSSimpleArray<TESIdleForm*, 1024>
{
};
extern GlobalObject_00719b80 g_011d8b44;
class NiPoint2
{
  public:
    float x, y;
    NiPoint2 operator*(float) const;
};
class BGSPerkEntry;
class EffectSetting;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList* GetNext();
    unsigned int ItemsInList();
};

class InputManager
{
  public:
public:
    void FUN_00a253d0();
};
class OSGlobals
{
  public:
};
extern const double DAT_0106e7f8;

template <class T> class BSStringT
{
  public:
    const char* String();
};
template <class T> class NiTPointerAllocator
{
};
template <class A, class T> class NiTPointerListBase
{
  public:
    T& GetNext(void*&);
};
class BSOcclusionPlane;
class SystemColorManager
{
  public:
    class SystemColor;
    SystemColor* Find(int);
};
class Tile
{
  public:
public:
    void Set(int, int);
public:
    void Set(int, unsigned int);
public:
    void SetSpeechChallengeFailure(bool);
};
class ConsoleManager
{
  public:
    static ConsoleManager* Instance(bool);
public:
    bool Idle(int);
public:
    static ::ConsoleManager *pInstance;
};
