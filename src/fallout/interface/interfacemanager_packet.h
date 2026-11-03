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
    char padding[0x110];
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
template <class T, int N> class BSSimpleArray
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
