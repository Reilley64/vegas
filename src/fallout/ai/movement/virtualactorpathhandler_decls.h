#ifndef VIRTUALACTORPATHHANDLER_DECLS_H
#define VIRTUALACTORPATHHANDLER_DECLS_H


#include "fnv/decl/FUN_0087b190_shell.h"
#include "fnv/decl/FUN_0087b650_shell.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_011de000.h"
template <class T> class PathingRef
{
  public:
    T* m_pObject;
    void Reset(void*);
    operator T*() const;
};

class VirtualActorPathHandlerVtableCaller
{
  public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual int Slot3(float);
};

struct NiPlane;
class Actor;
struct NiPoint3;
class TESObjectREFR;
class TESBoundObject;
class PlayerCharacter;
class ActorPackageContext;
struct LocationDescriptor;
class BaseProcess;

class AIThreadManager
{
  public:
    static bool IsConditionMet();
};

class UseDoorCalls
{
  public:
    void SetLocationOnReference(NiPoint3&);
    void* FUN_005c3420();
    void* FUN_00439ef0(void*, void*);
    float GetSquaredXYLength();
};


class EditorIDDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual const char* GetEditorID();
};

class RefCall
{
  public:
    bool Activate(TESObjectREFR*, bool, TESBoundObject*, int);
    bool FUN_00474cb0();
    const char* GetFullName();
};

class FullNameCall
{
  public:
    const char* GetFullName();
};

class BaseProcessCall
{
  public:
    ActorPackageContext* GetCurrentProcessData();
};

class ProcessLevelCall
{
  public:
    unsigned int GetProcessTier();
};

class PlayerCall
{
  public:
    bool IsSleepingOrResting();
};

struct BGSLoadFormBuffer
{
  public:
};

extern unsigned int VirtualActorPathHandler_vtbl;

#endif
