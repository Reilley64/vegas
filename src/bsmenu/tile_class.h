// bsmenu/tile_class.h: the class Tile, as its owning unit tile.cpp declares it.
// docs/shared-tile.md has the evidence for every line and what stays open.
#ifndef FNV_BSMENU_TILE_CLASS_H
#define FNV_BSMENU_TILE_CLASS_H

#include <cstddef>

class NiNode;
struct TileShaderProperty;

// Storage of four members of Tile. tile.cpp casts their addresses to the list, array, string and
// pointer types it uses, and defines their destructors beside the destructor of Tile.
struct TileChildListStorage
{
    void* m_pHead;
    void* m_pTail;
    unsigned int m_uiCount;
    ~TileChildListStorage();
};
struct TileValueArrayStorage
{
    void* m_pVtbl;
    void** m_ppData;
    unsigned int m_uiSize;
    unsigned int m_uiAllocSize;
    ~TileValueArrayStorage();
};
struct TileNameStorage
{
    char* m_pString;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
    ~TileNameStorage();
};
struct TileNodeStorage
{
    void* m_pObject;
    ~TileNodeStorage();
};

class Tile
{
  public:
    class Value;

    // The constructor's function row, 0x00709860, is in tile3d_h_unit.cpp under another class
    // name. Nothing defines this name yet.
    Tile();

    // The ten slots of the virtual table, in order. Slots 1, 2, 3, 4 and 6 have no body: the
    // repository does not show which function the table of Tile holds in them.
    virtual ~Tile();
    virtual void Init(Tile*, const char*, Tile*);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetImageTag();
    virtual bool IsPointInside(float, float);
    virtual Tile* SetTraitValue(int, float, const char*);
    virtual void FUN_00a0b020();
    virtual TileShaderProperty* FUN_00a0b1f0();
    virtual void ApplyAlphaAndColorToChildren(NiNode*, float, void*);

    TileChildListStorage m_kChildren;
    TileValueArrayStorage m_kValues;
    TileNameStorage m_kName;
    Tile* m_pParent;
    TileNodeStorage m_spNode;
    unsigned int m_uiFlags;
    // tile.cpp never reads or writes this byte. Its name and type are those of the other copies.
    bool m_bFlagAfterUiFlags;
    bool m_bSpeechChallengeFailure;

    class Value
    {
      public:
        int m_iValueId;
        Tile* pTile;
        float fValue;
        char* pcValue;
        void* pAction;
        __forceinline float GetFloat()
        {
            return fValue;
        }
    };
    static float GetInterfaceScale();
    bool GetSpeechChallengeFailure();
    void SetSpeechChallengeFailure(bool);
    void Set(int, int);
    void Set(int, unsigned int);
    bool IsMenuRendered();
    static bool IsSpecialTileName(const char*);
};

#if defined(_WIN64)
// The table pointer and the fields that tile.cpp reads and writes through the class. The class has
// virtual functions, so the compiler supports offsetof on it only conditionally and says so.
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#endif
static_assert(sizeof(Tile) == 96);
static_assert(alignof(Tile) == 8);
static_assert(offsetof(Tile, m_kChildren) == 8);
static_assert(offsetof(Tile, m_kChildren.m_pTail) == 16);
static_assert(offsetof(Tile, m_kChildren.m_uiCount) == 24);
static_assert(offsetof(Tile, m_kValues) == 32);
static_assert(offsetof(Tile, m_kValues.m_ppData) == 40);
static_assert(offsetof(Tile, m_kValues.m_uiSize) == 48);
static_assert(offsetof(Tile, m_kName) == 56);
static_assert(offsetof(Tile, m_kName.m_usLength) == 64);
static_assert(offsetof(Tile, m_pParent) == 72);
static_assert(offsetof(Tile, m_spNode) == 80);
static_assert(offsetof(Tile, m_uiFlags) == 88);
static_assert(offsetof(Tile, m_bSpeechChallengeFailure) == 93);
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
#endif

#endif
