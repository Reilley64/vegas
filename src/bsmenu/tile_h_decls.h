// bsmenu/tile_h_decls.h: declares NiFixedString, Tile, Tile__MenuStringMap, Tile__TileTemplate, Tile__BuildStorage and more
#ifndef FNV_TILE_H_DECLS_H
#define FNV_TILE_H_DECLS_H

#include "fnv/decl/ExtraDataObject.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a0c190.h"
#include "fnv/decl/FUN_00a0d1b0_cls.h"
#include "fnv/decl/fnv_00a1e1d0__A1E1D0_Holder.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_01094000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_011f6000.h"
#include "MemoryManager.h"
class NiFixedString
{
  public:
    char* m_kHandle;
};

extern float DAT_01094c4c;
extern const char DAT_01093f80[];
extern "C" int __cdecl _stricmp(const char*, const char*);
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
extern "C" int __cdecl tolower(int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class Tile
{
    static bool IsSpecialTileName(const char*);
};

class Tile__MenuStringMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int uiHashTableSize;
    bool IsKeysEqual(const char* left, const char* right);
};

class NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___
{
  public:
    unsigned int m_data[3];
    void RemoveAll();
};

class Tile__TileTemplate
{
  public:
    NiFixedString StringProvider;
    void* pParent;
    NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___ xList;
    void Clear();
    ~Tile__TileTemplate();
};

class Tile__BuildStorage
{
  public:
    Tile__TileTemplate* pTemplate;
};

extern void FUN_00f1d2eb();
extern void FUN_00f1e4f0();
extern const char DAT_010954cc[];
class NiNode;
class NiExtraData
{
  public:
    void* vtable;
    unsigned int refs;
    char* name;
};
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
class NiAVObject
{
  public:
};
class Tile__Extra : public NiExtraData
{
  public:
    Tile* pTile;
    NiNode* pNode;
    Tile__Extra(Tile*, NiNode*);
};
#endif
