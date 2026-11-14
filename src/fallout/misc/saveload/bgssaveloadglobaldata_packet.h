// fallout/misc/saveload/bgssaveloadglobaldata_packet.h: declares TES, ScreenSplatter, ScreenCustomSplatter, BSPortal, ImageSpaceModifierInstanceDOF and more
#ifndef BGSSAVELOADGLOBALDATA_PACKET_H
#define BGSSAVELOADGLOBALDATA_PACKET_H


#include "fnv/decl/CombatThreatMap.h"
#include "fnv/decl/FUN_00459840_shell.h"
#include "fnv/decl/FUN_0063f790_shell.h"
#include "fnv/decl/FUN_006694c0_shell.h"
#include "fnv/decl/GridHolder.h"
#include "fnv/decl/TESObjectTREE.h"
#include "fnv/decl/fnv_00459750__FUN_00459750_cls.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00993440__FUN_00993440_shell.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0045a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004d6000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00836000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
struct BGSLoadGameBuffer;
class ImageSpaceModifierInstance;
class NiAVObject;
class NiTexture;
class NiNode;
class BGSPerkEntry;
template <class T> class NiPointer
{
  public:
    T* pointer;
    NiPointer(T*);
    ~NiPointer();
    T* operator->() const;
};
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList* GetNext();
    void Remove(const NiPointer<NiAVObject>&);
};
struct NiPoint3;
class TES
{
  public:
public:
    int FindCellAtPosition(const ::NiPoint3 *, bool);
};
class ScreenSplatter
{
  public:
    static void Clear();
};
class ScreenCustomSplatter
{
  public:
    static void Clear();
};
class BSPortal
{
  public:
    ~BSPortal();
};
class ImageSpaceModifierInstanceDOF
{
  public:
};
class ImageSpaceModifierInstance
{
  public:
public:
    static float GetTime();
};
class CombatManager
{
  public:
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
};
struct Interface
{
  public:
};

struct BGSLoadGameBuffer
{
  public:
    virtual unsigned char GetVersion();
};
class TESForm
{
  public:
    virtual void vfn_0();
};
class TESImageSpaceModifier : public TESForm
{
};
class NiAVObject
{
};
class ImageSpaceModifierInstanceForm
{
  public:
    static ImageSpaceModifierInstanceForm* Trigger(TESImageSpaceModifier*, float, NiAVObject*);
};

class GlobalObject_0096d020
{
};
class MagicItem;
class MagicCaster
{
  public:
    virtual void SetSelectedMagicItem(MagicItem*);
};

void FUN_0084cd40(BGSLoadGameBuffer*);
void FUN_008368b0(BGSLoadGameBuffer*);
struct Sky
{
  public:
    static Sky* GetInstance();
    void LoadGame(BGSLoadGameBuffer*);
};
class SoundPlaybackManager
{
  public:
    static void LoadGame(BGSLoadGameBuffer*);
};

#endif
