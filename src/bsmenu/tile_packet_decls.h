// bsmenu/tile_packet_decls.h: declares Menu, TileListBoxCalls, Tile, Value, LoadingMenu
#ifndef TILE_PACKET_DECLS_H
#define TILE_PACKET_DECLS_H

#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a1d000.h"
class Menu
{
  public:
    char menuFields[0x1c];
    bool m_bIsSpecial;
    bool bUnk1d;
    char pad1e[0x6];
    int m_iMenuState;
};
class TileListBoxCalls
{
  public:
    float GetFloat(int);
};
// tile.cpp declares the class in tile_class.h. The copy below is for the units that include this
// header alone.
#ifndef FNV_BSMENU_TILE_CLASS_H
// Storage of the Tile members below; the tile.cpp stand-ins cast their addresses to the list,
// array, string and pointer types they use.
struct TileChildListStorage
{
    void* m_pHead;
    void* m_pTail;
    unsigned int m_uiCount;
};
struct TileValueArrayStorage
{
    void* m_pVtbl;
    void** m_ppData;
    unsigned int m_uiSize;
    unsigned int m_uiAllocSize;
};
struct TileNameStorage
{
    char* m_pString;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};
class Tile
{
  public:
    class Value;
    void* m_pVtbl;
    TileChildListStorage m_kChildren;
    TileValueArrayStorage m_kValues;
    TileNameStorage m_kName;
    Tile* m_pParent;
    void* m_spNode;
    unsigned int m_uiFlags;
    char unk34;
    bool m_bSpeechChallengeFailure;
    char tileUnknown36[0x1ec];
    unsigned short floatFlags;
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
    bool IsPointInside(float, float);
    bool GetSpeechChallengeFailure();
    void SetSpeechChallengeFailure(bool);
    void Set(int, int);
    void Set(int, unsigned int);
    bool IsMenuRendered();
    Value* GetValue(int);
    float GetFloat(int);
public:
    static bool IsSpecialTileName(const char *);
};
#endif
template <class T> class NiTPointerList;
template <> class NiTPointerList<Tile*>
{
  public:
    Tile*& GetPrev(NiTListItem<Tile*>*&);
};
class LoadingMenu
{
  public:
    char menuFields[0x222];
    unsigned short floatFlags;
    bool GetFloat(int);
};
#endif
