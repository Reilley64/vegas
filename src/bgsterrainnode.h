// BGSTerrainNode unit-local declarations.
//
// The distant-terrain node/manager layouts below are copied verbatim from the
// NiPoint3/Setting/AutoMemContext extras follow the accepted
// gameplayformulas.cpp / actionpoints.cpp / bstempeffectsimpledecal precedents:
// canonical headers omit the vanilla accessors, so the TU-local declarations
// carry them.
#ifndef FNV_BGSTERRAINNODE_LOCAL_H
#define FNV_BGSTERRAINNODE_LOCAL_H


#include <cstring>
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011d8000.h"
#include "layout_support.h"
#include <float.h>
#include <stddef.h>

class BGSTerrainManager;
class BGSTerrainNode;
class BGSTerrainChunk;
class BGSDistantObjectBlock;
class BGSDistantTreeBlock;

class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
    NiPoint3();
    NiPoint3(float xPos, float yPos, float zPos);
    NiPoint3 operator-(const NiPoint3& point) const;
public:
    float ComputeMagnitude() const;
};

class BGSTerrainManager
{
  public:
    void* m_pWorldSpace;
    unsigned int GetMinLevel();
};

union SETTING_VALUE
{
  public:
    const char* str;  // +0x0
    int i;            // +0x0
    unsigned int u;   // +0x0
    float f;          // +0x0
    bool b;           // +0x0
    char c;           // +0x0
    unsigned char h;  // +0x0
};

class GameSettingCollection
{
};

class SettingT_GameSettingCollection_
{
  public:
    SettingT_GameSettingCollection_();
    ~SettingT_GameSettingCollection_();
    SETTING_VALUE* Bool();
};


class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;  // +0x0
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, int line);
    ~AutoMemContext();
};


enum BGSTerrainNode__PARENT_POSITION
{
    BGSTerrainNode__PARENT_POSITION_PP_TOPLEVEL = 0,
    BGSTerrainNode__PARENT_POSITION_PP_UPPER_LEFT = 1,
    BGSTerrainNode__PARENT_POSITION_PP_UPPER_RIGHT = 2,
    BGSTerrainNode__PARENT_POSITION_PP_LOWER_LEFT = 3,
    BGSTerrainNode__PARENT_POSITION_PP_LOWER_RIGHT = 4
};

class BGSTerrainNode
{
  public:
    BGSTerrainManager* pManager;  // +0x0, 4 bytes
    unsigned int iLevel;          // +0x4, 4 bytes
    short m_sX;                   // +0x8, 2 bytes
    short m_sY;                   // +0xA, 2 bytes
    bool m_bWithinMaximumLevel;   // +0xC, 1 bytes
    bool m_bNodeStateFlag;        // +0xD, 1 bytes
    unsigned char layoutPaddingE[2];
    BGSTerrainChunk* pChunk;           // +0x10, 4 bytes
    BGSDistantObjectBlock* pBlock;     // +0x14, 4 bytes
    BGSDistantTreeBlock* pTrees;       // +0x18, 4 bytes
    NiNode* m_pSceneNode;              // +0x1C, 4 bytes
    BGSTerrainNode* pChildren[4];      // +0x20, 16 bytes
    BGSTerrainNode* pParent;           // +0x30, 4 bytes
    NiPoint3 Center;                   // +0x34, 12 bytes
    float m_fNodeRadius;               // +0x40, 4 bytes
    float m_fSplitDistance;            // +0x44, 4 bytes
    float m_fMorphStartDistance;       // +0x48, 4 bytes
    float m_fMorphEndDistance;         // +0x4C, 4 bytes
    unsigned int TerrainNodeData;      // +0x50, 4 bytes
    bool m_bFlagBeforeParentPosition;  // +0x54, 1 bytes
    unsigned char layoutPadding55[3];
    BGSTerrainNode__PARENT_POSITION m_eParentPosition;  // +0x58, 4 bytes
    bool m_bPersistent;                                 // +0x5C, 1 bytes
    bool m_bNodeInitialized;                            // +0x5D, 1 bytes
    unsigned char layoutPadding5E[2];
    BGSTerrainNode(BGSTerrainManager* pManagerArg, BGSTerrainNode* pParentArg, short sX, short sY, unsigned int uiSize,
                   bool bPersistentArg);
};
#endif
