
// fallout_shared/distant terrain system/bgsterrainnode.cpp
// BGSTerrainNode::BGSTerrainNode (0x006fd210).
//
// Recursive distant-terrain quad-tree node constructor: nulls the payload
// pointers, derives the node center/corner radius from the base cell and
// level size, subdivides while above the manager minimum, then derives the
// split/morph distances from the [TerrainManager] INI mults.

#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Block.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Cls6fabc0.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FE550Area.h"
#include "fnv/decl/FOPipboyManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00464df0_shell.h"
#include "fnv/decl/FUN_00485bc0_class.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00529ea0_shell.h"
#include "fnv/decl/FUN_00557d30_class.h"
#include "fnv/decl/FUN_006f5800_shell.h"
#include "fnv/decl/FUN_006f5ca0_cls.h"
#include "fnv/decl/FUN_006f6070_shell.h"
#include "fnv/decl/FUN_006f76b0_cls.h"
#include "fnv/decl/FUN_006fb150_shell.h"
#include "fnv/decl/FUN_006fb6e0_shell.h"
#include "fnv/decl/FUN_006fb760_shell.h"
#include "fnv/decl/FUN_006fb940_shell.h"
#include "fnv/decl/FUN_006fbfe0_shell.h"
#include "fnv/decl/FUN_006fca40_Class.h"
#include "fnv/decl/FUN_006fe520_shell.h"
#include "fnv/decl/FUN_006fe620_cls.h"
#include "fnv/decl/FUN_006fe920_Class.h"
#include "fnv/decl/FUN_00759d80_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a86ff0_shell.h"
#include "fnv/decl/FUN_00a872d0_shell.h"
#include "fnv/decl/HitRect.h"
#include "fnv/decl/NodeVisitor.h"
#include "fnv/decl/OwnerX.h"
#include "fnv/decl/S00a87040_Obj.h"
#include "fnv/decl/S_006f6370_Mgr.h"
#include "fnv/decl/S_006fe6d0.h"
#include "fnv/decl/S_006fe780_Foo.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Target006fac.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Unk00586340.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_006f5970__LodVisitor.h"
#include "fnv/decl/fnv_006f6270__BlockLoader.h"
#include "fnv/decl/fnv_006f6540__FUN_006f6540_cls.h"
#include "fnv/decl/fnv_006f91a0__FUN_006f91a0_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006f7000.h"
#include "fnv/symbols_006fe000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "bgsterrainnode.h"

const char kBGSTerrainNodeFileLabel[] =
    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSTerrainNode.cpp";
const int kBGSTerrainNodeCtorLine = 76;
const char kInvalidMorphDistances[] =
    "MODELS: Morph distances are invalid.  Please ensure that fMorphDistanceMult is less than fSplitDistanceMult under [TerrainManager] in the INI (or delete both)";

// Initializes a terrain node: stores manager/parent/level/coords, computes center and distances, and recursively creates four child nodes unless at min level.
// @fnv 0x006fd210
BGSTerrainNode::BGSTerrainNode(BGSTerrainManager* pManagerArg, BGSTerrainNode* pParentArg, short sX, short sY,
                               unsigned int uiSize, bool bPersistentArg)
{
    AutoMemContext fCornerX(MEM_CONTEXT_MEM_CONTEXT_LODMANAGER, true, kBGSTerrainNodeFileLabel,
                            kBGSTerrainNodeCtorLine);
    m_bNodeInitialized = true;
    pChunk = 0;
    pBlock = 0;
    pTrees = 0;
    pManager = pManagerArg;
    pParent = pParentArg;
    iLevel = uiSize;
    m_sX = sX;
    m_sY = sY;
    for (int i = 0; i < 4; i++)
        pChildren[i] = 0;
    if (uiSize <= ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((pManager))->FUN_009611e0())))
        m_bWithinMaximumLevel = true;
    else
        m_bWithinMaximumLevel = false;
    float fCenterX = (float)(iLevel << 12);
    float fCornerY = m_sX * 4096.0 + fCenterX * 0.5;
    float fZ = m_sY * 4096.0 + fCenterX * 0.5;
    float fMin = m_sX * 4096.0;
    float kCtx = m_sY * 4096.0;
    NiPoint3 corner(fMin, kCtx, 0.0f);
    Center = NiPoint3(fCornerY, fZ, 0.0f);
    m_fNodeRadius = reinterpret_cast<::NiPoint3 *>((void *)&(const ::NiPoint3 &)((Center - corner)))->ComputeMagnitude();
    m_bPersistent = bPersistentArg;
    if (uiSize > pManager->GetMinLevel())
    {
        unsigned int uH = iLevel >> 1;
        short sMX = m_sX + (iLevel >> 1);
        short sMid = m_sY + (iLevel >> 1);
        bool bChildPersistent = false;
        if ((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8760)).Bool()->b && uH == ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((pManager))->FUN_009611e0())))
            bChildPersistent = true;
        pChildren[0] = new BGSTerrainNode(pManager, this, m_sX, m_sY, uH, bChildPersistent);
        pChildren[1] = new BGSTerrainNode(pManager, this, m_sX, sMid, uH, bChildPersistent);
        pChildren[2] = new BGSTerrainNode(pManager, this, sMX, m_sY, uH, bChildPersistent);
        pChildren[3] = new BGSTerrainNode(pManager, this, sMX, sMid, uH, bChildPersistent);
        pChildren[0]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_UPPER_LEFT;
        pChildren[1]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_LOWER_LEFT;
        pChildren[2]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_UPPER_RIGHT;
        pChildren[3]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_LOWER_RIGHT;
        m_fSplitDistance = m_fNodeRadius * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d86e0))))))->f;
    }
    else
    {
        memset(pChildren, 0, sizeof(pChildren));
        m_fSplitDistance = 0.0f;
    }
    if (pParent)
    {
        m_fMorphStartDistance = pParent->m_fNodeRadius * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d8754))))))->f;
        m_fMorphEndDistance = pParent->m_fNodeRadius * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d86d4))))))->f;
        if (m_fMorphEndDistance > m_fMorphStartDistance)
            ::FUN_005b5e40();
    }
    else
    {
        m_fMorphStartDistance = FLT_MIN;
        m_fMorphEndDistance = FLT_MAX;
        m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_TOPLEVEL;
    }
    m_bNodeStateFlag = false;
}

struct BSSimpleListX
{
    bool IsEmpty();
};
struct FileX
{
};
struct FUN_00485b60
{
    unsigned int Go();
};
// Calls FUN_00485bc0, checks whether the first file's list is non-empty, and ORs that flag into bit 24 of the result.
// @fnv 0x00485b60
unsigned int FUN_00485b60::Go()
{
    char flag;
    unsigned int result;
    FileX* file;
    result = ((unsigned int)(reinterpret_cast<::FUN_00485bc0_class *>(this)->FUN_00485bc0()));
    flag = 0;
    file = ((::FileX *)(reinterpret_cast<::TESForm *>(this)->GetFile(0)));
    if (!((::BSSimpleListX *)(reinterpret_cast<::FUN_00464df0_shell *>((file))->FUN_00464df0()))->IsEmpty())
        flag = 1;
    result |= flag << 24;
    return result;
}

struct FUN_006fca40
{
};
struct FUN_006fd7b0
{
};
struct FUN_006fd750
{
    void Unload();
};

// @fnv 0x006fd8e0
int __cdecl FUN_006fd8e0()
{
    return (*reinterpret_cast<int *>(&::DAT_011d8670));
}

void __cdecl operator delete(void*);
struct FUN_006fa420
{
public:
    ~FUN_006fa420();
};
struct FUN_006fd8f0
{
    void* Del(unsigned int flags);
};
// Calls Dtor on this object, frees it with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006fd8f0
void* FUN_006fd8f0::Del(unsigned int flags)
{
    reinterpret_cast<::FUN_006fa420 *>((((FUN_006fa420*)this)))->FUN_006fa420::~FUN_006fa420();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_006f5370
{
public:
    ~FUN_006f5370();
};
struct FUN_006fd920
{
    void* Del(unsigned int flags);
};
// Calls Dtor on this object, frees it with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006fd920
void* FUN_006fd920::Del(unsigned int flags)
{
    reinterpret_cast<::FUN_006f5370 *>((((FUN_006f5370*)this)))->FUN_006f5370::~FUN_006f5370();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_006f76b0
{
};
struct FUN_006fd950
{
    void* Del(unsigned int flags);
};
// Calls Dtor on this, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006fd950
void* FUN_006fd950::Del(unsigned int flags)
{
    reinterpret_cast<::FUN_006f76b0_cls *>((((FUN_006f76b0*)this)))->FUN_006f76b0_cls::~FUN_006f76b0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006fd980_shell;
struct Mgr
{
};
void FUN_006f83f0();
struct FUN_006fd980_shell
{
    Mgr* pManager;
    int f4, f8;
    char fc;
    char m_bNodeStateFlag;
    char fe, ff;
    void* pChunk;
    void* pBlock;
    int f18, f1c;
    FUN_006fd980_shell* pChildren[4];
    void FUN_006fd7b0(int a);
    void FUN_006fd980(int a);
};
struct NiObj;
struct GO
{
    NiObj* p;
    GO(int p);
    ~GO();
    operator NiObj*() const;
};
struct FUN_006fe280_shell
{
    int f0;
    GO m;
    NiObj* GetNiObj(bool b);
};
// Returns a NiObj pointer: a null-initialized GO when b is true, otherwise the stored m member.
// @fnv 0x006fe280
NiObj* FUN_006fe280_shell::GetNiObj(bool abNull)
{
    return (abNull ? GO(0) : m);
}

struct FUN_006ff0a0
{
    bool Chk(int idx);
};
struct Ent
{
    int a;
    void* b;
    int c;
    int d;
    int e;
};
// Returns true when the Ent at index idx in the array at this+0xc4 has a null b pointer.
// @fnv 0x006ff0a0
bool FUN_006ff0a0::Chk(int aiIndex)
{
    return (*(Ent**)((char*)this + 0xc4))[aiIndex].b == 0;
}

struct NiPoint2
{
    float x, y;
    NiPoint2(float a, float b);
};
struct FUN_006ff210_shell
{
    char pad[0x58];
    int mode;
    NiPoint2 FUN_006ff210();
};
// Returns a NiPoint2 chosen from the mode field: (0.5,0), (0.5,0.5), (0,0) or (0,0.5), defaulting to (0,0).
// @fnv 0x006ff210
NiPoint2 FUN_006ff210_shell::FUN_006ff210()
{
    float x, y;
    switch (mode)
    {
    case 1:
        x = 0.5f;
        y = 0.0f;
        break;
    case 3:
        x = 0.5f;
        y = 0.5f;
        break;
    case 2:
        x = 0.0f;
        y = 0.0f;
        break;
    case 4:
        x = 0.0f;
        y = 0.5f;
        break;
    default:
        x = y = 0.0f;
        break;
    }
    return NiPoint2(x, y);
}

namespace fnv_006ff2c0 {
struct NiNode
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void SetBool(int a, int b, int c) = 0;
};
struct Tile
{
};
struct NiPoint2
{
    float x, y;
};
struct Chunk
{
};
struct Holder
{
    int f0, f4, f8, fc;
    Chunk* chunk;
};
struct AnimIdle
{
};
struct FUN_006ff2c0_shell
{
    char pad[0x10];
    Tile* tile;
    char pad2[0x30 - 0x14];
    Holder* holder;
    char pad3[0x50 - 0x34];
    int section;
    bool flag;
    NiPoint2 FUN_006ff210();
    void UpdateTileFromChunk();
};
// @fnv 0x006ff2c0
void FUN_006ff2c0_shell::UpdateTileFromChunk()
{
    int c;
    NiNode* b;
    int a;
    c = reinterpret_cast<::Cls6fabc0 *>((holder->chunk))->FUN_006fabc0(0);
    a = reinterpret_cast<::Cls6fabc0 *>((holder->chunk))->FUN_006fabc0(1);
    b = ((::fnv_006ff2c0::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((tile))->FUN_0056c7f0()));
    if (b)
    {
        b->SetBool(0, 1, c);
        b->SetBool(1, 1, a);
        NiPoint2 pt = FUN_006ff210();
        section = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_006ff2c0::AnimIdle *>(&::g_timeGlobal))))->FUN_00825c00()));
        reinterpret_cast<::FUN_006fb940_shell *>((b))->FUN_006fb940(pt.x, pt.y, 0.0f);
        flag = true;
    }
}
}  // namespace fnv_006ff2c0

struct NiNode
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void SetBool(int a, int b, int c) = 0;
};
struct Tile
{
};
struct Tile;
struct FUN_006ff380_shell
{
    int f0, f4, f8, fc;
    Tile* tile;
    int f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48, f4c, f50;
    char flag;
    void FUN_006ff380();
};
// @fnv 0x006ff380
void FUN_006ff380_shell::FUN_006ff380()
{
    NiNode* node;
    flag = 0;
    node = ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((tile))->FUN_0056c7f0()));
    if (node)
    {
        reinterpret_cast<::FUN_006fb940_shell *>((node))->FUN_006fb940(0.0f, 0.0f, 1.0f);
        node->SetBool(0, 1, 0);
        node->SetBool(1, 1, 0);
    }
}

namespace fnv_006ff4c0 {
struct Inner
{
};
struct Mgr
{
};
struct Block
{
};
struct FUN_006ff4c0_shell
{
    Mgr* pManager;
    unsigned int iLevel;
    unsigned short m_sX;
    unsigned short m_sY;
    int fc, f10;
    Block* pBlock;
    int f18, f1c;
    FUN_006ff4c0_shell* pChildren[4];
    void ProcessBlock();
};
// @fnv 0x006ff4c0
void FUN_006ff4c0_shell::ProcessBlock()
{
    if (((unsigned int)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) == reinterpret_cast<::ActorMover *>((pManager))->GetCurrentMoveModeType() && pBlock)
    {
        reinterpret_cast<::fnv_006f6270::BlockLoader *>((pBlock))->FUN_006f6270((void *)(((unsigned int)(::FUN_00559450((int *)(((::fnv_006ff4c0::Inner *)(::FUN_00559450((int *)this)))))))), (void *)(iLevel), m_sX, m_sY);
    }
    else if (((unsigned int)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) > reinterpret_cast<::ActorMover *>((pManager))->GetCurrentMoveModeType())
    {
        for (int i = 0; i < 4; i++)
        {
            if (pChildren[i])
                pChildren[i]->ProcessBlock();
        }
    }
}
}  // namespace fnv_006ff4c0

struct FUN_006fda10_shell
{
    void* pad0[4];
    FUN_006fd8f0* pChunk;  // +0x10
    void* pad14[3];
    FUN_006fda10_shell* pChildren[4];  // +0x20
    char pad30[0x2c];
    bool m_bPersistent;  // +0x5c

    void FUN_006fda10();
};

// @fnv 0x006fda10
void FUN_006fda10_shell::FUN_006fda10()
{
    int i;

    if (pChunk && m_bPersistent)
    {
        FUN_006fd8f0* b = pChunk;
        FUN_006fd8f0* a = b;
        a ? a->Del(1) : 0;
        pChunk = 0;
    }

    for (i = 0; i < 4; i++)
    {
        if (pChildren[i])
            pChildren[i]->FUN_006fda10();
    }
}

struct AnimIdle
{
};

struct GameTimerRecord : AnimIdle
{
};

struct GlobalObject_0045cfe0
{
};

struct FUN_006ff3f0_shell : FUN_006ff380_shell
{
    void FUN_006ff3f0();
};

// @fnv 0x006ff3f0
void FUN_006ff3f0_shell::FUN_006ff3f0()
{
    unsigned int delta;
    unsigned int section = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(g_timeGlobal))->FUN_00825c00()));
    delta = section - f50;

    if (!tile || !((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((tile))->FUN_0056c7f0())))
        return;

    if (delta > (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011d8740)))))
    {
        FUN_006ff380();
    }
    else
    {
        float f = (double)delta / (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&(::g_011d8740))));
        NiPoint2 pt = ((FUN_006ff210_shell*)this)->FUN_006ff210();
        reinterpret_cast<::FUN_006fb940_shell *>((((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((tile))->FUN_0056c7f0()))))->FUN_006fb940(pt.x, pt.y, f);
    }
}

struct ClearPartA
{
    int unk00;
    ~ClearPartA();
};
struct ClearPartB
{
    int unk00;
    ~ClearPartB();
};
struct ClearPartC
{
    int unk00;
    ~ClearPartC();
};
struct ClearFlagHolder
{
    int unk00;
    int unk04;
    int unk08;
    char cUnk0C;
    bool bActive;
};
int __cdecl FUN_006fd8e0();

struct FUN_006fd7b0_Owner
{
    int m_uiClearFlags;
    int unk04;
    int unk08;
    bool bInitialized;
    ClearPartA* pPartA;
    ClearPartB* pPartB;
    ClearPartC* pPartC;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    ClearFlagHolder* pFlagHolder;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    bool bCheckOwner;

    void FUN_006fd7b0(unsigned int auiFlags);
};
// Calls Go(7), then for each of the four pointers at offset 0x20 calls Del(1) on the non-null ones.
// @fnv 0x006fd750
void FUN_006fd750::Unload()
{
    reinterpret_cast<::FUN_006fd7b0_Owner *>((((FUN_006fd7b0*)this)))->FUN_006fd7b0(7);
    for (int i = 0; i < 4; i++)
    {
        FUN_006fca40* c = ((FUN_006fca40**)((char*)this + 0x20))[i];
        FUN_006fca40* p = c;
        p ? reinterpret_cast<::FUN_006fca40_Class *>((p))->FUN_006fca40(1) : 0;
    }
}
// @fnv 0x006fd980
void FUN_006fd980_shell::FUN_006fd980(int aiFlags)
{
    if (pChunk || pBlock)
        reinterpret_cast<::FUN_006fd7b0_Owner *>(this)->FUN_006fd7b0(aiFlags);
    for (int i = 0; i < 4; i++)
    {
        if (pChildren[i])
            pChildren[i]->FUN_006fd980(aiFlags);
    }
    m_bNodeStateFlag = 0;
    if (aiFlags & 4)
    {
        if (this == ((::FUN_006fd980_shell *)(reinterpret_cast<::Callees *>((pManager))->FUN_00726070())))
            FUN_006f83f0();
    }
}

// Deletes pPartA/pPartB/pPartC according to auiFlags bits, conditionally keeping pPartA, and clears pFlagHolder->bActive.
// @fnv 0x006fd7b0
void FUN_006fd7b0_Owner::FUN_006fd7b0(unsigned int auiFlags)
{
    if (bInitialized && pPartA && (auiFlags & 1))
    {
        if (!bCheckOwner || m_uiClearFlags != FUN_006fd8e0() || auiFlags == 7)
        {
            delete pPartA;
            pPartA = 0;
        }
        else
            reinterpret_cast<::FUN_006fb6e0_shell *>((pPartA))->SetAllAppCulled();
    }
    if (pPartB && (auiFlags & 2))
    {
        delete pPartB;
        pPartB = 0;
    }
    if (pPartC && (auiFlags & 4))
    {
        delete pPartC;
        pPartC = 0;
    }
    if (pFlagHolder)
        pFlagHolder->bActive = false;
}

struct TerrainUpdate;
struct SceneUpdate
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual SceneUpdate* CastNode(int) = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void Refresh() = 0;
};
struct WorldUpdate
{
};
struct TerrainMgrUpdate
{
};
struct ChunkUpdate
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c;
    ChunkUpdate(TerrainUpdate*, unsigned int, short, short);
};
struct WorldRefUpdate
{
};
struct TESUpdate
{
};
struct GlobalObject_0044f440
{
};
struct TerrainUpdate
{
    TerrainMgrUpdate* manager;
    unsigned int level;
    short cellX, cellY;
    bool hasGeometry, childrenLoaded;
    unsigned char f0e, f0f;
    ChunkUpdate* chunk;
    void* block;
    void* trees;
    SceneUpdate* scene;
    TerrainUpdate* children[4];
    TerrainUpdate* parent;
    float x, y, z, radius, split, startMorph, endMorph;
    unsigned int fadeStart;
    bool fading;
    unsigned char f55, f56, f57;
    int position;
    bool persistent, splitNode;
    unsigned char f5e, f5f;
    void UpdateTerrainNode(void*, bool);
    void FUN_006fd7b0(int);
    void UpdateVisibility(SceneUpdate*);
};
// Recursively updates a terrain node: decides split vs geometry state, creates or refreshes its chunk, and updates child nodes and scene objects.
// @fnv 0x006fdaa0
void TerrainUpdate::UpdateTerrainNode(void* arg, bool update)
{
    AutoMemContext context4((MEM_CONTEXT)35, true, kBGSTerrainNodeFileLabel, 284);
    bool below2 = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((manager))->FUN_009611e0())) < level;
    bool splitNow2 = reinterpret_cast<::FE550Area *>(this)->FUN_006fe550((const ::FE550Point3 *)(arg));
    if (splitNow2 && ((bool)(reinterpret_cast<::FUN_006fb150_shell *>(this)->GetByteAtOffset5C())) && chunk && !((bool)(reinterpret_cast<::FUN_00759d80_Class *>((chunk))->FUN_00759d80())))
        reinterpret_cast<::Target006fac *>((chunk))->FUN_006facb0();
    if (below2 || splitNow2)
    {
        splitNode = true;
        if (((bool)(reinterpret_cast<::FUN_006fb150_shell *>(this)->GetByteAtOffset5C())) && !chunk)
            chunk = new ChunkUpdate(this, level, cellX, cellY);
        for (int childIndex2 = 0; childIndex2 < 4; childIndex2++)
        {
            if (children[childIndex2])
                children[childIndex2]->UpdateTerrainNode(arg, update);
        }
        if (chunk && reinterpret_cast<::FUN_006fe920_Class *>(this)->FUN_006fe920(true))
        {
            for (int loadedIndex2 = 0; loadedIndex2 < 4; loadedIndex2++)
            {
                if (children[loadedIndex2]->chunk && reinterpret_cast<::FOPipboyManager *>((children[loadedIndex2]->chunk))->IsUnk28Set())
                    reinterpret_cast<::fnv_006ff2c0::FUN_006ff2c0_shell *>((children[loadedIndex2]))->UpdateTileFromChunk();
            }
            reinterpret_cast<::FUN_006fd7b0_Owner *>(this)->FUN_006fd7b0(1);
        }
        if (reinterpret_cast<::FUN_006fe920_Class *>(this)->FUN_006fe920(true))
            childrenLoaded = true;
    }
    else if (hasGeometry)
    {
        SceneUpdate* oldRoot = chunk ? ((::SceneUpdate *)(reinterpret_cast<::StrOwner *>((chunk))->FUN_007fa950())) : 0;
        splitNode = false;
        if (!chunk)
            chunk = new ChunkUpdate(this, level, cellX, cellY);
        else
        {
            bool unusedState5 = false;
            if (reinterpret_cast<::FOPipboyManager *>((chunk))->IsUnk28Set() && ((bool)(reinterpret_cast<::FUN_00759d80_Class *>((chunk))->FUN_00759d80())) && ((bool)(reinterpret_cast<::FUN_006fb150_shell *>(this)->GetByteAtOffset5C())))
                reinterpret_cast<::FUN_006fb760_shell *>((chunk))->FUN_006fb760();
            if (reinterpret_cast<::FOPipboyManager *>((chunk))->IsUnk28Set() && !((bool)(reinterpret_cast<::FUN_00759d80_Class *>((chunk))->FUN_00759d80())) && (!parent || reinterpret_cast<::FUN_006fe920_Class *>((parent))->FUN_006fe920(true)))
            {
                reinterpret_cast<::Target006fac *>((chunk))->FUN_006facb0();
                reinterpret_cast<::FUN_00507700_cls *>((((::SceneUpdate *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((chunk))->FUN_0056c7f0()))))->FUN_00507700((float)((level / 4.0) * *((float *)&(::FUN_00403e20((float *)&(::g_011d86f8))))));
                SceneUpdate* root7 = ((::SceneUpdate *)(reinterpret_cast<::TESRegionDataMap *>((((::WorldRefUpdate *)(::FUN_00559450((int *)this)))))->GetRegionMapName()));
                reinterpret_cast<::TaskQueueInterface *>((root7))->SetTaskFlag2000(false);
                root7->Refresh();
                reinterpret_cast<::TaskQueueInterface *>((root7))->SetTaskFlag2000(true);
            }
        }
        if (((bool)(reinterpret_cast<::FUN_00759d80_Class *>((chunk))->FUN_00759d80())) && childrenLoaded)
        {
            for (int unloadIndex4 = 0; unloadIndex4 < 4; unloadIndex4++)
                if (children[unloadIndex4])
                    reinterpret_cast<::FUN_006fd980_shell *>((children[unloadIndex4]))->FUN_006fd980(1);
            childrenLoaded = false;
        }
        if (oldRoot && ((::WorldUpdate *)(::FUN_00559450((int *)(((::WorldRefUpdate *)(::FUN_00559450((int *)this))))))) != ((::WorldUpdate *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TESUpdate * *>(&::g_TES))))->GetHitSound())))
        {
            WorldUpdate* worldVal = ((::WorldUpdate *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TESUpdate * *>(&::g_TES))))->GetHitSound()));
            if (reinterpret_cast<::Unk00586340 *>((worldVal))->FUN_00586340(1) && !reinterpret_cast<::Unk00586340 *>((worldVal))->FUN_00586340(0) && reinterpret_cast<::HitRect *>(this)->FUN_006fede0())
                reinterpret_cast<::TaskQueueInterface *>((oldRoot))->QueueActorDisarm(true);
        }
        if (update && chunk)
        {
            SceneUpdate* geometryB = ((::SceneUpdate *)(reinterpret_cast<::TESRegionDataMap *>((chunk))->GetRegionMapName()));
            SceneUpdate* objects3 = ((::SceneUpdate *)(::fnv_0043b230::FUN_0043b230((const char *)(chunk))));
            if (geometryB)
                UpdateVisibility(geometryB->CastNode(0));
            if (objects3)
                UpdateVisibility(objects3->CastNode(0));
        }
    }
}

extern const char kBGSTerrainNodeFileLabel[];

class BGSDistantTreeBlock
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48;
    BGSDistantTreeBlock(BGSTerrainNode* pNode, unsigned int uiTreeBlockIndex, unsigned short sX, unsigned short sY);
    ~BGSDistantTreeBlock();
};

struct TerrainSceneX
{
};


struct TerrainNodeX : BGSTerrainNode
{
    void FUN_006fe330(int iArg);
};

// @fnv 0x006fe330
void TerrainNodeX::FUN_006fe330(int iArg)
{
    AutoMemContext kMemContext((MEM_CONTEXT)0x25, true, kBGSTerrainNodeFileLabel, 0x1ed);
    if (((unsigned int)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) == ((unsigned int)(::fnv_006fe510::FUN_006fe510())))
    {
        if (!((bool)(::FUN_006fe540())))
        {
            ::LoadTreeLodResources((::Fake076 *)(((const char *)(::FUN_00559450((int *)(((::TerrainSceneX *)(::FUN_00559450((int *)this)))))))));
        }
        if (reinterpret_cast<::S_006fe780_Foo *>(this)->FUN_006fe780((const ::FUN_00452dc0 *)(iArg)))
        {
            if (pTrees == 0)
            {
                pTrees = new BGSDistantTreeBlock(this, iLevel, m_sX, m_sY);
            }
            else if (pTrees != 0)
            {
                if (((bool)(reinterpret_cast<::FUN_006fe520_shell *>((pTrees))->GetByteAtOffset48())))
                {
                    reinterpret_cast<::OwnerX *>((pTrees))->FUN_006f8c40();
                    reinterpret_cast<::fnv_006f91a0::FUN_006f91a0_shell *>((pTrees))->FUN_006f91a0();
                }
            }
        }
        else if (pTrees != 0)
        {
            delete pTrees;
            pTrees = 0;
        }
    }
    else if (((unsigned int)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) > ((unsigned int)(::fnv_006fe510::FUN_006fe510())))
    {
        for (int i = 0; i < 4; i++)
        {
            if (pChildren[i] != 0)
            {
                ((TerrainNodeX*)pChildren[i])->FUN_006fe330(iArg);
            }
        }
    }
}

namespace fnv_006ff0d0 {
class TESObjectCELL;

class TESWorldSpaceX
{
  public:
};

class TES
{
  public:
};

class TerrainVisibility
{
  public:
};

class TerrainNodeX
{
  public:
    void* pManager;
    unsigned int iLevel;
    short m_sX;
    short m_sY;
    void UpdateVisibility(TerrainVisibility* pVisArg, int unused);
};

// @fnv 0x006ff0d0
void TerrainNodeX::UpdateVisibility(TerrainVisibility* pVisibility, int unused)
{
    TESWorldSpaceX* pWorld = ((::fnv_006ff0d0::TESWorldSpaceX *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_006ff0d0::TES * *>(&::g_TES))))->GetHitSound()));
    TerrainVisibility* pVis3 = pVisibility;
    if (pVis3)
    {
        if (reinterpret_cast<::HitRect *>(this)->FUN_006fede0())
        {
            for (unsigned int i = 0; i < iLevel; i++)
            {
                for (unsigned int j_ = 0; j_ < iLevel; j_++)
                {
                    if (iLevel * i + j_ < reinterpret_cast<::FUN_006fbfe0_shell *>((pVis3))->GetFlagOrValue())
                    {
                        int x5 = m_sX + i;
                        int y3 = m_sY + j_;
                        unsigned int idx5 = iLevel * i + j_;
                        TESObjectCELL* pCell4 = ((::fnv_006ff0d0::TESObjectCELL *)(reinterpret_cast<::TESWorldSpace *>((pWorld))->GetCellAtGridPosition(x5, y3)));
                        if (!reinterpret_cast<::FUN_006ff0a0 *>((pVis3))->Chk(idx5) && reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::fnv_006ff0d0::TES * *>(&::g_TES))))->IsCellBuffered((::TESObjectCELL *)(pCell4), true))
                            reinterpret_cast<::Target *>((pVis3))->DisableEntry(idx5);
                        else
                            reinterpret_cast<::FUN_00a86ff0_shell *>((pVis3))->SetEntryActive(idx5);
                    }
                }
            }
            reinterpret_cast<::S00a87040_Obj *>((pVis3))->FinalizeEntries();
        }
        else
        {
            reinterpret_cast<::FUN_00a872d0_shell *>((pVis3))->ResetRecordSelection();
        }
    }
}
}  // namespace fnv_006ff0d0

extern "C" char DAT_0106e4e0;
struct FUN_00404eb0
{
    int x;
    FUN_00404eb0(int, bool, char*, int);
    ~FUN_00404eb0();
};
struct Thread006f
{
};
struct Ret006f
{
};
struct Node006f;
struct FUN_006f5160
{
    char data[0x2c];
    FUN_006f5160(Node006f*, int, unsigned short, unsigned short, bool);
    ~FUN_006f5160();
    void* FUN_006fd920(unsigned);
};
struct Node006f
{
    Thread006f* thread;
    int f4;
    unsigned short f8, fa;
    int fc, f10;
    FUN_006f5160* block;
    int f18, f1c;
    Node006f* children[4];
    void UpdateBlock(int, bool);
};
struct NodeObj
{
};
struct GridObj
{
    bool FUN_006ff0a0(int idx);
};
struct ObjA
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual GridObj* v10();
};
struct GetterObj
{
};
struct BlockObj
{
};
struct MgrObj
{
};
struct FeeNode
{
    int f00;
    unsigned int count;
    short baseX;
    short baseY;
    char f0C;
    char f0D;
    short f0E;
    void* pChunk;
    BlockObj* pBlock;
    void FUN_006fee90(int a);
};
// @fnv 0x006fdfc0
void Node006f::UpdateBlock(int a, bool abFlag)
{
    FUN_00404eb0 guard(0x24, true, &DAT_0106e4e0, 0x1ae);
    if (((unsigned int)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) == reinterpret_cast<::ActorMover *>((thread))->GetCurrentMoveModeType())
    {
        if (reinterpret_cast<::FUN_006fe620_cls *>(this)->FUN_006fe620((::Vec2 *)(a)))
        {
            bool flag = reinterpret_cast<::S_006fe6d0 *>(this)->FUN_006fe6d0((const ::S_006fe6d0_Vec2 *)(a));
            if (!block)
            {
                block = new FUN_006f5160(this, f4, f8, fa, flag);
            }
            else if (block && ((void *)(reinterpret_cast<::FUN_006fe280_shell *>((block))->GetNiObj(false))))
            {
                if (reinterpret_cast<::FUN_00529ea0_shell *>((block))->FUN_00529ea0())
                    reinterpret_cast<::FUN_006f5ca0_cls *>((block))->FUN_006f5ca0();
                if (abFlag)
                    reinterpret_cast<::FeeNode *>(this)->FUN_006fee90(false);
            }
            if (block)
            {
                if (reinterpret_cast<::FUN_006f6070_shell *>((block))->GetByteAtOffset35() && flag)
                    reinterpret_cast<::S_006f6370_Mgr *>((block))->ResetAndCreateTask((::TESWorldSpace *)(::Ret006f *)(((::Ret006f *)(::FUN_00559450((int *)(((::Ret006f *)(::FUN_00559450((int *)this)))))))), f4, f8, fa);
                else if (!reinterpret_cast<::FUN_006f6070_shell *>((block))->GetByteAtOffset35() && !flag)
                    reinterpret_cast<::fnv_006f6540::FUN_006f6540_cls *>((block))->FUN_006f6540(((::Ret006f *)(::FUN_00559450((int *)(((::Ret006f *)(::FUN_00559450((int *)this))))))), (void *)(f4), f8, fa);
            }
            if (reinterpret_cast<::TESObjectCELL *>((block))->GetField24())
                reinterpret_cast<::Block *>((block))->FUN_006f5af0();
        }
        else if (block)
        {
            delete block;
            block = 0;
        }
    }
    else if (((unsigned int)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) > reinterpret_cast<::ActorMover *>((thread))->GetCurrentMoveModeType())
    {
        for (int i = 0; i < 4; ++i)
        {
            if (children[i])
                children[i]->UpdateBlock(a, abFlag);
        }
    }
}
// @fnv 0x006fee90
void FeeNode::FUN_006fee90(int a)
{
    GetterObj* getter5 = ((::GetterObj *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::MgrObj * *>(&::g_TES))))->GetHitSound()));
    GridObj* grid;
    if (pBlock)
    {
        if (((::ObjA *)(reinterpret_cast<::FUN_006fe280_shell *>((pBlock))->GetNiObj(0))))
        {
            grid = ((::ObjA *)(reinterpret_cast<::FUN_006fe280_shell *>((pBlock))->GetNiObj(0)))->v10();
            if (reinterpret_cast<::HitRect *>(this)->FUN_006fede0())
            {
                if (grid)
                {
                    unsigned int i;
                    for (i = 0; i < count; i++)
                    {
                        unsigned int j_;
                        for (j_ = 0; j_ < count; j_++)
                        {
                            if ((unsigned int)(count * i + j_) < reinterpret_cast<::FUN_006fbfe0_shell *>((grid))->GetFlagOrValue())
                            {
                                int x4 = baseX + i;
                                int y3 = baseY + j_;
                                int idx4 = count * i + j_;
                                NodeObj* node = ((::NodeObj *)(reinterpret_cast<::TESWorldSpace *>((getter5))->GetCellAtGridPosition(x4, y3)));
                                if (!reinterpret_cast<::FUN_006ff0a0 *>((grid))->Chk(idx4) && reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::MgrObj * *>(&::g_TES))))->IsCellBuffered((::TESObjectCELL *)(node), 1) &&
                                    ((bool)(reinterpret_cast<::FUN_00557d30_class *>((node))->FUN_00557d30())))
                                {
                                    reinterpret_cast<::Target *>((grid))->DisableEntry(idx4);
                                }
                                else
                                {
                                    reinterpret_cast<::FUN_00a86ff0_shell *>((grid))->SetEntryActive(idx4);
                                }
                            }
                        }
                    }
                    reinterpret_cast<::S00a87040_Obj *>((grid))->FinalizeEntries();
                }
            }
            else
            {
                if (grid)
                {
                    reinterpret_cast<::FUN_00a872d0_shell *>((grid))->ResetRecordSelection();
                }
            }
        }
    }
    if (pBlock)
    {
        if (((void *)(reinterpret_cast<::FUN_006f5800_shell *>((pBlock))->GetSelectedValue(1))))
        {
            if (reinterpret_cast<::HitRect *>(this)->FUN_006fede0())
            {
                reinterpret_cast<::fnv_006f5970::LodVisitor *>((pBlock))->UpdateLodVisibility(
                    (::fnv_006f5970::LodObject *)(void *)(((void *)(reinterpret_cast<::FUN_006f5800_shell *>((pBlock))->GetSelectedValue(1)))), {}, {}, {});
            }
            else
            {
                reinterpret_cast<::NodeVisitor *>((pBlock))->VisitNodeTree((::SceneNode *)(void *)(((void *)(reinterpret_cast<::FUN_006f5800_shell *>((pBlock))->GetSelectedValue(1)))));
            }
        }
    }
}

#include "generated/data/bgsterrainnode.inc"
