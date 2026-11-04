// Authored header for fallout_shared/extradataobjects.cpp hand matches.
//
// BSExtraData is declared locally (not included from the canonical tree)
// because the canonical BSExtraData.h carries layout only, while every Extra
// constructor below must invoke the base initializer BSExtraData(etype) (the
// 0x0040ec80 call that stores the base vtable, the type tag and a null next
// pointer before the derived vtable store). Request: promote
// BSExtraData(unsigned char) into the canonical BSExtraData.h so this local
// declaration can be replaced by the canonical include; layouts here are
// identical to the canonical ones.
//
// with their layout asserts; only matched member-function declarations are
// existed), so its two members come from the 0x00414010 ctor bytes (8-byte
// construction: pointer at +0x0, float at +0x4) and the operator new(8)
// construction sites. Each Extra class declares its virtual destructor so
// the compiler emits the vtable store the originals contain.
#ifndef FNV_EXTRADATAOBJECTS_H
#define FNV_EXTRADATAOBJECTS_H

#include "layout_support.h"

class TESObjectREFR;
class TESObjectCELL;
class TESGlobal;
class TESKey;
class Script;
class ScriptLocals;
class RagDollData;
class Point3Offset;
class TESForm;

class BSExtraData
{
  public:
    // Promoted form: the compiler vptr occupies +0x0, so the explicit
    unsigned char m_ucExtraDataType;  // +0x4
    unsigned char layoutPadding5[3];
    BSExtraData* pNext;  // +0x8

    virtual ~BSExtraData();
    BSExtraData(unsigned char aEtype);
};

// 8-byte activation record. Proved by the 0x00414010 ctor (stores a pointer
// at +0x0 and +0.0f at +0x4, no base construction) and by operator new(8)
// construction sites that fill +0x0 with a reference and link the record
// into a child list.
class ReferenceFloatEntry
{
  public:
    TESObjectREFR* m_pWorldReferenceInfo;  // +0x0, 4 bytes
    float m_fDelay;               // +0x4, 4 bytes

    ReferenceFloatEntry();
};

// matched member-function declaration is added.
class LockExtraData
{
  public:
    unsigned char m_uiLockState;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    TESKey* pKey;  // +0x4, 4 bytes
    char cFlags;   // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    unsigned int m_uiLockDifficulty;  // +0xC, 4 bytes
    unsigned int m_uiLockValue;       // +0x10, 4 bytes

    void SetLocked(bool aLocked);
};

// matched member-function declarations are added.
class ExtraUsedMarkers : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned int m_uiUsedMarkerFlags;  // +0xC, 4 bytes

    virtual ~ExtraUsedMarkers();
    void SetUsedMarker(unsigned int aMarker, bool aUsed);
};

class ExtraAction : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned char eAction;  // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    TESObjectREFR* m_pActionReference;  // +0x10, 4 bytes

    virtual ~ExtraAction();
    ExtraAction();
};

class ExtraGlobal : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    TESGlobal* pGlobalForm;  // +0xC, 4 bytes

    virtual ~ExtraGlobal();
    ExtraGlobal(TESGlobal* aGlobal);
};

class ExtraCount : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    short iCount;  // +0xC, 2 bytes
    unsigned char layoutPaddingE[2];

    virtual ~ExtraCount();
    ExtraCount(short aCount);
};

class ExtraScript : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    Script* pScript;          // +0xC, 4 bytes
    ScriptLocals* m_pLocals;  // +0x10, 4 bytes

    virtual ~ExtraScript();
    ExtraScript(Script* aScript);
};

class ExtraLeveledItem : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    int iIndex;             // +0xC, 4 bytes
    bool m_bIsLeveledItem;  // +0x10, 1 bytes
    unsigned char layoutPadding11[3];

    virtual ~ExtraLeveledItem();
    ExtraLeveledItem(int aIndex);
};

class ExtraPersistentCell : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    TESObjectCELL* m_pCell;  // +0xC, 4 bytes

    virtual ~ExtraPersistentCell();
    ExtraPersistentCell(TESObjectCELL* aCell);
};

class ExtraRagDollData : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    RagDollData* m_pRagDollData;  // +0xC, 4 bytes

    virtual ~ExtraRagDollData();
    ExtraRagDollData();
};

class ExtraReservedMarkers : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned int m_uiReservedMarkers;  // +0xC, 4 bytes

    virtual ~ExtraReservedMarkers();
    ExtraReservedMarkers();
};

class ExtraStartingWorldOrCell : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    TESForm* m_pStartingWorldOrCell;  // +0xC, 4 bytes

    virtual ~ExtraStartingWorldOrCell();
    ExtraStartingWorldOrCell();
};

class ExtraMultiBoundData : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    Point3Offset* pBound;  // +0xC, 4 bytes

    virtual ~ExtraMultiBoundData();
    ExtraMultiBoundData();
};
#endif
