// fallout_shared/gridcell.cpp: GridCellArray, UnnamedHolder, GridCellArrayStandin, GridCellArray_Target and more (43 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSRenderedTexture.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CamLook.h"
#include "fnv/decl/CellTarget.h"
#include "fnv/decl/CellUpdateView.h"
#include "fnv/decl/FUN_004186f0_shell.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00438230_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004bcf00_stand.h"
#include "fnv/decl/FUN_005477f0_Class.h"
#include "fnv/decl/FUN_00552840_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/Land.h"
#include "fnv/decl/Manager.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/Pool.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/Surface.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/fnv_0049ee30__NiObjectNET.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_0053fa40__HostMesh53.h"
#include "fnv/decl/fnv_00552970__FUN_00552970_Call.h"
#include "fnv/decl/fnv_005538e0__Cell5538.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00451000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004ba000.h"
#include "fnv/symbols_004bc000.h"
#include "fnv/symbols_004f2000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_00554000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fd000.h"
class TESObjectLAND;

class TESObjectCELL
{
  public:
};

class TESObjectLAND
{
  public:
};

class GridCell
{
  public:
    TESObjectCELL* pCell;
};

class GridArray
{
  public:
    virtual void* Destroy(bool doFree);
    virtual void Fn_01(void);
    virtual void Fn_02(void);
    virtual void Fn_03(void);
    virtual bool SetPosXY(int posX, int posY);
    virtual void Fn_05(unsigned int arg1, unsigned int arg2);
    virtual void UnloadCellAtGridXY(unsigned int gridX, unsigned int gridY);
    virtual void SetGridAtXYToNull(unsigned int gridX, unsigned int gridY);
    virtual void Init(void);
    int iHorizontalPixelCenterObj;
    int iCenterPixelY;
    unsigned int uiDimension;
};

class GridCellArray : public GridArray
{
  public:
    virtual void Init(void);
    GridCell* m_pGridCells;
    GridCell* Get(unsigned int gridX, unsigned int gridY);
    void Detach(unsigned int gridX, unsigned int gridY);
    void ReleaseGridCells(void);
};

// @fnv 0x004ba5e0
void GridCellArray::Init(void)
{
    GridArray::Init();
    ::FUN_00541b80();
}

// Returns the grid cell at (gridX, gridY) if both are within the array dimension, otherwise returns null.
// @fnv 0x004ba490
GridCell* GridCellArray::Get(unsigned int gridX, unsigned int gridY)
{
    unsigned int dimension = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
    if (gridX >= dimension || gridY >= dimension)
        return 0;
    return &m_pGridCells[((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) * gridX + gridY];
}

// Detaches the grid cell at (gridX, gridY) if it has a cell, then nulls that grid slot.
// @fnv 0x004ba6b0
void GridCellArray::Detach(unsigned int gridX, unsigned int gridY)
{
    GridCell* gridCell = Get(gridX, gridY);
    if (gridCell->pCell)
    {
        reinterpret_cast<::CellTarget *>((gridCell->pCell))->FUN_00552bd0(true);
        SetGridAtXYToNull(gridX, gridY);
    }
}

// @fnv 0x004ba8d0
void GridCellArray::ReleaseGridCells(void)
{
    unsigned int dimension = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
    for (unsigned int gridX = 0; gridX < dimension; ++gridX)
    {
        for (unsigned int gridY = 0; gridY < dimension; ++gridY)
        {
            GridCell* gridCell = Get(gridX, gridY);
            if (gridCell && gridCell->pCell)
            {
                reinterpret_cast<::Surface *>((reinterpret_cast<::S00546fb0_Cell *>((gridCell->pCell))->FUN_00546fb0()))->FUN_005400e0();
            }
        }
    }
}

struct V3
{
    float x, y, z;
};
struct FUN_00440460_S
{
    char pad[0x58];
    V3 t;
    void FUN_00440460(const V3* k);
};
// Copies the V3 pointed to by k into the t member.
// @fnv 0x00440460
void FUN_00440460_S::FUN_00440460(const V3* k)
{
    t = *k;
}

// @fnv 0x004bae00
bool FUN_004bae00(const char* pThis)
{
    return *(const bool*)(pThis + 0x16);
}

struct FUN_004baec0_shell : public GridCellArray
{
    void FUN_004baec0();
};

class BSRenderedTexture;
class NiNode;

class BSTextureManager
{
  public:
};

template <class T> class BSStringT
{
  public:
    operator const char*() const;
};

template <class T> class NiPointer
{
  public:
    NiPointer<T>& operator=(T*);
};

extern char DAT_01189184;

// @fnv 0x004baec0
void FUN_004baec0_shell::FUN_004baec0()
{
    if (reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x24)->operator const char*())
    {
        ::FUN_00451570((void *)(0));
        reinterpret_cast<::Manager *>((((::BSTextureManager *)(::FUN_004a0ea0()))))->FUN_00b6da10((::Item *)(::BSRenderedTexture *)(reinterpret_cast<BSRenderedTexture*>(const_cast<char*>(
            reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0x24)->operator const char*()))));
        reinterpret_cast<NiPointer<NiNode>*>(reinterpret_cast<char*>(this) + 0x24)->operator=(0);
        DAT_01189184 = 1;
    }
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3(float, float, float);
public:
    static const ::NiPoint3 ZERO;
};
struct FUN_004bc1f0_S
{
    char pad[0x58];
    NiPoint3 t;
    void FUN_004bc1f0(float x, float y, float z);
};
// Stores the given x, y and z into the t point of this object.
// @fnv 0x004bc1f0
void FUN_004bc1f0_S::FUN_004bc1f0(float x, float y, float z)
{
    t = NiPoint3(x, y, z);
}

struct C3
{
    float r, g, b;
};
struct NiDynamicEffect
{
    void IncRevisionID();
};
struct FUN_004bc280_S : NiDynamicEffect
{
    char pad[0xc8];
    C3 c;
    void FUN_004bc280(const C3* k);
};
// Copies the C3 value pointed to by k into c, then calls IncRevisionID.
// @fnv 0x004bc280
void FUN_004bc280_S::FUN_004bc280(const C3* apColor)
{
    c = *apColor;
    IncRevisionID();
}

namespace fnv_004bc2e0 {
struct NiStream;
struct NiMemObject
{
    char _pad_0[1];
};
struct NiColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, NiColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
};

class NiDynamicEffect
{
  public:
    void SetEffectColor(const NiColor& color);
};

// Stores the given NiColor at offset 0xD4 of this object and increments the revision ID.
// @fnv 0x004bc2e0
void NiDynamicEffect::SetEffectColor(const NiColor& color)
{
    *reinterpret_cast<NiColor*>(reinterpret_cast<char*>(this) + 0xD4) = color;
    reinterpret_cast<::NiDynamicEffect *>(this)->IncRevisionID();
}
}  // namespace fnv_004bc2e0

class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag(void);
};


// @fnv 0x004bc400
unsigned char FUN_004bc400()
{
    return *(*reinterpret_cast<::ProcessLists *>(&::g_011c75a4)).GetLifeStateControlFlag();
}

namespace fnv_004bc450 {
struct C3
{
    float r, g, b;
};
struct FUN_004bc450_S
{
    char pad[0x28];
    C3 c;
    void FUN_004bc480(int);
    void FUN_004bc450(const C3* k);
};
// Copies the C3 value pointed to by k into the c member and calls FUN_004bc480 with 1.
// @fnv 0x004bc450
void FUN_004bc450_S::FUN_004bc450(const C3* apColor)
{
    c = *apColor;
    FUN_004bc480(1);
}
}  // namespace fnv_004bc450

class _Dummy_004bc4a0
{
  public:
    char _pad[0x84];
    bool m_bAccumulate;
    void SetAccumulate(bool abTF);
};

// @fnv 0x004bc4a0
void _Dummy_004bc4a0::SetAccumulate(bool abTF)
{
    m_bAccumulate = abTF;
}

struct FUN_004ba5a0_shell : GridCellArray
{
    bool IsOutdoorCell(unsigned int aiX, unsigned int aiY);
};

struct FUN_004ba5a0_cell_helper
{
};

// @fnv 0x004ba5a0
bool FUN_004ba5a0_shell::IsOutdoorCell(unsigned int aiX, unsigned int aiY)
{
    GridCell* pgridcell = Get(aiX, aiY);
    if (pgridcell->pCell)
        return ::FUN_00450ff0((void *)(((FUN_004ba5a0_cell_helper*)pgridcell->pCell)));
    return false;
}


// @fnv 0x004bc3d0
void FUN_004bc3d0(int aiEnabledPasses)
{
    ::fnv_005bf7b0::DAT_011f91d8 = aiEnabledPasses;
}


// @fnv 0x004bc3e0
int __cdecl FUN_004bc3e0()
{
    return ::fnv_005bf7b0::DAT_011f91d8;
}

struct Flt
{
    operator unsigned int(void) const;
};


// @fnv 0x004bc3f0
unsigned int FUN_004bc3f0()
{
    return (*reinterpret_cast<::Flt *>(&::g_011c73b4)).operator unsigned int();
}

extern float DAT_011fd878;

// @fnv 0x004bc420
void __cdecl FUN_004bc420(float afValue1, float afValue2)
{
    DAT_011fd874 = afValue1;
    DAT_011fd878 = afValue2;
}

extern float DAT_011fd880;

// @fnv 0x004bc440
void FUN_004bc440(float value)
{
    DAT_011fd880 = value;
}

struct FUN_004ba700_shell : public GridCellArray
{
    void ClearTileExtraPair(unsigned int aiX, unsigned int aiY);
};

// Clears the grid cell at (aiX, aiY) by nulling its pCell and the byte at offset 0x20 of this.
// @fnv 0x004ba700
void FUN_004ba700_shell::ClearTileExtraPair(unsigned int aiX, unsigned int aiY)
{
    GridCell* pgridcell = Get(aiX, aiY);
    pgridcell->pCell = 0;
    ((char*)this)[0x20] = 0;
}

struct UnnamedCaller
{
    void FUN_004ba400();
};
struct UnnamedHolder
{
    void* FUN_004ba3d0(unsigned int flags);
};
struct GridCellArrayStandin : public GridCellArray
{
    void SetCellAt(unsigned int aiX, unsigned int aiY, TESObjectCELL* apCell);
};
// Stores apCell into the grid cell at (aiX, aiY), or clears that cell when apCell is null.
// @fnv 0x004ba550
void GridCellArrayStandin::SetCellAt(unsigned int aiX, unsigned int aiY, TESObjectCELL* apCell)
{
    GridCell* pgridcell;
    if (apCell)
    {
        pgridcell = Get(aiX, aiY);
        pgridcell->pCell = apCell;
    }
    else
    {
        SetGridAtXYToNull(aiX, aiY);
    }
}

struct DH
{
};
struct FUN_004b9e90_shell
{
    void CallVirtualMethod2();
};
void FUN_00541c00();
struct FUN_004ba600_shell
{
    void FUN_004ba600();
};
// Calls CallVirtualMethod2 on this, then calls FUN_00541c00 if g_dataHandler->FUN_004226e0() returns true.
// @fnv 0x004ba600
void FUN_004ba600_shell::FUN_004ba600()
{
    ((FUN_004b9e90_shell*)this)->CallVirtualMethod2();
    if (reinterpret_cast<::FUN_004226e0_shell *>((g_dataHandler))->FUN_004226e0())
        FUN_00541c00();
}

struct FUN_004ba630_shell : public GridCellArray
{
    bool SetGridCellPosition(int aiX, int aiY);
};

struct FUN_004b9f10_shell : public GridCellArray
{
    bool ShiftToCell(int aiX, int aiY);
};


// @fnv 0x004ba630
bool FUN_004ba630_shell::SetGridCellPosition(int aiX, int aiY)
{
    bool bretval = false;
    if (reinterpret_cast<FUN_004b9f10_shell*>(this)->ShiftToCell(aiX, aiY))
    {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x14) = static_cast<float>(aiX << 12);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x18) = static_cast<float>(aiY << 12);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1c) = 0.0f;
        ::fnv_005546a0::FUN_005546a0(reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x14));
        bretval = true;
        *reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0x20) = 0;
    }
    return bretval;
}

struct FUN_004ba740_shell : public GridCellArray
{
    void SetCellAtXY(unsigned int, unsigned int, GridCell*);
    void SetFrom(unsigned int, unsigned int, unsigned int, unsigned int);
};
// @fnv 0x004ba740
void FUN_004ba740_shell::SetFrom(unsigned int aiX1, unsigned int aiY1, unsigned int aiX2, unsigned int aiY2)
{
    SetCellAtXY(aiX2, aiY2, Get(aiX1, aiY1));
}

struct S : public GridCellArray
{
    void SetCellAtXY(unsigned int, unsigned int, GridCell*);
    void SwapCells(unsigned int, unsigned int, unsigned int, unsigned int);
};
// Copies the cell at (aiX1, aiY1) into a temporary, then swaps the cells at the two coordinate pairs via SetCellAtXY.
// @fnv 0x004ba770
void S::SwapCells(unsigned int aiX1, unsigned int aiY1, unsigned int aiX2, unsigned int aiY2)
{
    GridCell tempgridcell;
    GridCell* pgc;
    pgc = Get(aiX1, aiY1);
    tempgridcell = *pgc;
    SetCellAtXY(aiX1, aiY1, Get(aiX2, aiY2));
    SetCellAtXY(aiX2, aiY2, &tempgridcell);
}

class NiNode;
struct FUN_00552970_Call
{
};
struct GridCellArray_Target : public GridCellArray
{
    void FUN_004ba960(NiNode* apRoot, unsigned int aiX, unsigned int aiY);
};
// Gets the grid cell at (aiX, aiY) and, if it has a cell, forwards apRoot to that cell's UpdateCellScene.
// @fnv 0x004ba960
void GridCellArray_Target::FUN_004ba960(NiNode* apRoot, unsigned int aiX, unsigned int aiY)
{
    GridCell* pgridcell;
    pgridcell = Get(aiX, aiY);
    if (pgridcell->pCell)
        reinterpret_cast<::fnv_00552970::FUN_00552970_Call *>((((FUN_00552970_Call*)pgridcell->pCell)))->UpdateCellScene(apRoot);
}

struct Arr
{
    unsigned int* GetAt(int);
};
struct KFModel
{
};
struct CLS_004bc240
{
    char _pad[0x1c];
    Arr arr;
    void* FUN_004bc240();
};
// @fnv 0x004bc240
void* CLS_004bc240::FUN_004bc240()
{
    KFModel* p = *(KFModel**)arr.GetAt(0);
    if (p)
        return ((void *)(reinterpret_cast<::TESRegionDataMap *>((p))->GetRegionMapName()));
    else
        return 0;
}

struct FUN_004bc480_shell
{
    unsigned char pad_00_44[0x44];
    unsigned int m_44;
    void FUN_004bc480(int arg);
};

// @fnv 0x004bc480
void FUN_004bc480_shell::FUN_004bc480(int arg)
{
    ++m_44;
}

struct bhkWorld;
struct ExtraDataList
{
    void FUN_00554960(bool);
public:
    bool HasExtraDataType0x2F();
};
bool FUN_004bae00(char const*);
struct FUN_004bad40_shell : GridCellArray
{
    void FUN_004bad40();
};
struct CellExt
{
};
// @fnv 0x004bad40
void FUN_004bad40_shell::FUN_004bad40()
{
    bhkWorld* pWorld = ((::bhkWorld *)(::FUN_00451010()));
    if (pWorld)
    {
        bool b = !FUN_004bae00((const char*)pWorld);
        for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())); ++i)
            for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())); ++j)
            {
                GridCell* cell = Get(i, j);
                if (cell->pCell && ::FUN_00450ff0((void *)(((CellExt*)cell->pCell))))
                    ((ExtraDataList*)cell->pCell)->FUN_00554960(b);
            }
    }
}

struct FUN_005549d0_shell
{
    void FUN_005549d0(bool);
};
struct FUN_004bae20_shell : GridCellArray
{
    void FUN_004bae20(bool detach);
};
struct CellHelper
{
};
// @fnv 0x004bae20
void FUN_004bae20_shell::FUN_004bae20(bool detach)
{
    CellHelper* world = (CellHelper*)((void *)(::FUN_00451010()));
    if (world)
    {
        for (unsigned int x = 0; x < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())); ++x)
        {
            for (unsigned int y = 0; y < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())); ++y)
            {
                GridCell* cell = Get(x, y);
                if (cell->pCell && ::FUN_00450ff0((void *)(((CellHelper*)cell->pCell))))
                    ((FUN_005549d0_shell*)cell->pCell)->FUN_005549d0(detach);
            }
        }
    }
}

struct FUN_00553820_shell
{
};
struct FUN_004baba0_shell : GridCellArray
{
    void FUN_004baba0();
};
// Iterates every grid cell and calls FUN_00553820 on each cell's pCell when it is non-null.
// @fnv 0x004baba0
void FUN_004baba0_shell::FUN_004baba0()
{
    unsigned int i;
    for (i = 0; i < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())); i++)
    {
        unsigned int j;
        for (j = 0; j < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())); j++)
        {
            GridCell* cell = Get(i, j);
            if (cell->pCell)
                ::fnv_00553820::FUN_00553820((::TESObjectCELL *)(reinterpret_cast<FUN_00553820_shell*>(cell->pCell)));
        }
    }
}

struct CellOwner
{
};
struct GridCellArraySize
{
};
struct FUN_004bac20_shell : GridCellArray
{
    void FUN_004bac20();
};
// Iterates every grid cell and calls PlayCellSoundEffects on each cell's pCell when both the cell and its pCell are non-null.
// @fnv 0x004bac20
void FUN_004bac20_shell::FUN_004bac20()
{
    for (unsigned int x = 0; x < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((GridCellArraySize*)this)))->FUN_0084e3a0())); ++x)
    {
        for (unsigned int y = 0; y < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((GridCellArraySize*)this)))->FUN_0084e3a0())); ++y)
        {
            GridCell* cell = Get(x, y);
            if (cell && cell->pCell)
                reinterpret_cast<::fnv_005538e0::Cell5538 *>((((CellOwner*)cell->pCell)))->PlayCellSoundEffects();
        }
    }
}

namespace fnv_004baca0 {
struct CellExt
{
};
struct FakeCell
{
};
struct LAND_x
{
};
struct GridCellArrayHelper
{
    void FUN_004baca0(bool abShow);
};

// Iterates every grid cell and, for cells whose cell has a LAND, calls FUN_0053fa40 with abShow.
// @fnv 0x004baca0
void GridCellArrayHelper::FUN_004baca0(bool abShow)
{
    for (unsigned int x = 0; x < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())); ++x)
    {
        for (unsigned int y = 0; y < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())); ++y)
        {
            GridCell* pgridcell = reinterpret_cast<::GridCellArray *>(this)->Get(x, y);
            if (pgridcell->pCell && ::FUN_00450ff0((void *)(reinterpret_cast<CellExt*>(pgridcell->pCell))))
            {
                TESObjectLAND* pland = reinterpret_cast<::S00546fb0_Cell *>((reinterpret_cast<FakeCell*>(pgridcell->pCell)))->FUN_00546fb0();
                if (pland)
                    reinterpret_cast<::fnv_0053fa40::HostMesh53 *>((reinterpret_cast<LAND_x*>(pland)))->FUN_0053fa40(abShow);
            }
        }
    }
}
}  // namespace fnv_004baca0

struct AutoMemHelper
{
    int m_eMemoryContext;

    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
};

typedef AutoMemHelper AutoMemContext;

struct FakeCell : public TESObjectCELL
{
};

struct FUN_005535f0_shell
{
    void FUN_005535f0();
};

extern char const str_010206c0[];


struct FUN_004ba7d0_shell : public GridCellArray
{
    void FUN_004ba7d0();
};

// @fnv 0x004ba7d0
void FUN_004ba7d0_shell::FUN_004ba7d0()
{
    if (*reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x20))
        return;

    unsigned int idim;
    AutoMemContext tempMemContext(0x1b, true, str_010206c0, 0x10d);

    idim = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0()));
    for (unsigned int ix = 0; ix < idim; ++ix)
    {
        for (unsigned int iy = 0; iy < idim; ++iy)
        {
            GridCell* pgc = Get(ix, iy);
            if (pgc && pgc->pCell)
            {
                reinterpret_cast<::Land *>((reinterpret_cast<::S00546fb0_Cell *>((static_cast<FakeCell*>(pgc->pCell)))->FUN_00546fb0()))->FUN_005374f0();

                reinterpret_cast<FUN_005535f0_shell*>(pgc->pCell)->FUN_005535f0();
            }
        }
    }

    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x20) = true;
}


extern bool DAT_011c642c;

struct Zt5Cell
{
};

struct GridCellArrayRef
{
};

struct FUN_004ba9a0_shell : public GridCellArray
{
    void UpdateCellGrid(float value);
};

// @fnv 0x004ba9a0
void FUN_004ba9a0_shell::UpdateCellGrid(float value)
{
    GridCell* idim;
    unsigned int idimedge;
    unsigned int x;
    unsigned int y;
    bool bupdate;
    unsigned int pgridcell;

    ::fnv_00554780::CallIfPresent();

    y = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<GridCellArrayRef*>(this)))->FUN_0084e3a0()));
    pgridcell = y - 1;

    DAT_011c642c = !DAT_011c642c;

    for (x = 0; x < y; ++x)
    {
        for (idimedge = 0; idimedge < y; ++idimedge)
        {
            bupdate = true;

            if (x == 0 || idimedge == 0 || x == pgridcell || idimedge == pgridcell)
            {
                if ((x ^ idimedge) & 1)
                    bupdate = false;

                if (DAT_011c642c)
                    bupdate = !bupdate;
            }

            idim = Get(x, idimedge);

            if (idim->pCell != 0)
            {
                reinterpret_cast<::CellUpdateView *>((reinterpret_cast<Zt5Cell*>(idim->pCell)))->FUN_00551890(value, !bupdate);
            }
        }
    }
}

extern unsigned int _data_011c16bc;

struct GO
{
    unsigned int value;

    GO(int arg);
    ~GO();
    operator unsigned int(void) const;
};

struct FUN_004bc320_shell
{
    unsigned char _pad_0[0x30];
    GO m_textures[1];

    unsigned int FUN_004bc320(int aiIndex);
};

// Returns the unsigned int value of the texture at aiIndex, or 0 when this is null.
// @fnv 0x004bc320
unsigned int FUN_004bc320_shell::FUN_004bc320(int aiIndex)
{
    return (this ? m_textures[aiIndex] : GO(0)).operator unsigned int();
}


struct FUN_0045cec0
{
    ~FUN_0045cec0();
};

struct FUN_004b9e50
{
    virtual ~FUN_004b9e50();
};

struct FUN_004ba400 : FUN_004b9e50
{
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    FUN_0045cec0 m_24;


    virtual ~FUN_004ba400();
};
// @fnv 0x004ba3d0
void* UnnamedHolder::FUN_004ba3d0(unsigned int flags)
{
    reinterpret_cast<::FUN_004ba400 *>((((UnnamedCaller*)this)))->FUN_004ba400::~FUN_004ba400();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Calls FUN_004ba600 and FUN_004baec0, then deallocates the pointer stored in m_10.
// @fnv 0x004ba400
FUN_004ba400::~FUN_004ba400()
{
    reinterpret_cast<::FUN_004ba600_shell *>(this)->FUN_004ba600();
    reinterpret_cast<::FUN_004baec0_shell *>(this)->FUN_004baec0();
    void* p = m_10;
    ::FUN_00401030(p);
}

namespace fnv_004ba4e0 {
class TESObjectCELL;

struct S : public GridCellArray
{
    void SetCellAtXY(unsigned int, unsigned int, GridCell*);
};

// Stores the cell pointer from apCell into the grid at (aiX, aiY) if in bounds, or clears that grid slot when apCell is null.
// @fnv 0x004ba4e0
void S::SetCellAtXY(unsigned int aiX, unsigned int aiY, GridCell* apCell)
{
    unsigned int dim = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
    if (aiX >= dim || aiY >= dim)
    {
        return;
    }
    if (apCell != 0)
    {
        m_pGridCells[((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) * aiX + aiY].pCell = apCell->pCell;
    }
    else
    {
        SetGridAtXYToNull(aiX, aiY);
    }
}
}  // namespace fnv_004ba4e0

struct FUN_004baab0_shell : public GridCellArray
{
    void FUN_004baab0();
};

struct FUN_00552840_cell
{
};

extern bool DAT_011c642d;

// Flips DAT_011c642d, then for each grid cell on the border whose checkerboard parity matches, calls FUN_00552840 on the cell's pCell if non-null.
// @fnv 0x004baab0
void FUN_004baab0_shell::FUN_004baab0()
{
    unsigned int dim = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0()));
    unsigned int last = dim - 1;
    DAT_011c642d = !DAT_011c642d;
    for (unsigned int i = 0; i < dim; i++)
    {
        for (unsigned int j = 0; j < dim; j++)
        {
            bool flag = true;
            if (i == 0 || j == 0 || i == last || j == last)
            {
                if (((i ^ j) & 1) != 0)
                {
                    flag = false;
                }
                if (DAT_011c642d)
                {
                    flag = !flag;
                }
            }
            if (flag)
            {
                GridCell* cell = this->Get(i, j);
                if (cell->pCell != 0)
                {
                    reinterpret_cast<::FUN_00552840_cls *>((reinterpret_cast<FUN_00552840_cell*>(cell->pCell)))->FUN_00552840();
                }
            }
        }
    }
}

struct InventoryItem
{
};
struct LinkedEntry
{
};
struct FUN_004bcc30_List
{
    LinkedEntry* first;
    int FUN_004bcc30();
};
// Walks the linked entries and sums the short value of each item whose check returns true, stopping at the first null entry or null item pointer.
// @fnv 0x004bcc30
int FUN_004bcc30_List::FUN_004bcc30()
{
    LinkedEntry* pEntry = first;
    int total = 0;
    while (pEntry && *((::InventoryItem **)((void *)(pEntry))))
    {
        InventoryItem* item = *((::InventoryItem **)((void *)(pEntry)));
        if (item && reinterpret_cast<::ExtraDataList *>((item))->HasExtraDataType0x2F())
        {
            total += reinterpret_cast<::FUN_00418770_shell *>((item))->FUN_00418770();
        }
        pEntry = ((::LinkedEntry *)(reinterpret_cast<::Callees *>((pEntry))->FUN_00726070()));
    }
    return total;
}

struct TESBoundObject
{
    virtual ~TESBoundObject();
};
struct TESObjectWEAP : TESBoundObject
{
};
struct HealthForm4bcdb0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int GetHealth();
};
struct HealthExtra4bcdb0
{
};
struct HealthList4bcdb0
{
};
struct FUN_004bcdb0_shell
{
    HealthList4bcdb0* m_pkExtendData;
    int m_iArrayLength;
    TESBoundObject* m_pkForm;
    float FUN_004bcdb0(bool bPercent);
};
// @fnv 0x004bcdb0
float FUN_004bcdb0_shell::FUN_004bcdb0(bool bPercent)
{
    HealthForm4bcdb0* pkHealth = ((::HealthForm4bcdb0 *)(::GetHealthForm((::TESForm *)(m_pkForm))));
    if (pkHealth)
    {
        TESObjectWEAP* pkWeapon5 = dynamic_cast<TESObjectWEAP*>(m_pkForm);
        int m_uiHealthValue = pkHealth->GetHealth();
        if (pkWeapon5)
            m_uiHealthValue = reinterpret_cast<::FUN_004bcf00_stand *>((pkWeapon5))->GetModdedValue(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>(this)->HasEffect(10));
        HealthList4bcdb0* pkList2 = m_pkExtendData;
        if (pkList2 && ((::HealthExtra4bcdb0 *)((void *)(pkList2))))
        {
            HealthExtra4bcdb0* pkExtra = ((::HealthExtra4bcdb0 *)((void *)(pkList2)));
            if (pkExtra && reinterpret_cast<::FUN_004186f0_shell *>((pkExtra))->FUN_004186f0() != -1.0)
            {
                if (!bPercent)
                    return reinterpret_cast<::FUN_004186f0_shell *>((pkExtra))->FUN_004186f0();
                else
                    return FUN_0040ebd0(::DAT_01016410, reinterpret_cast<::FUN_004186f0_shell *>((pkExtra))->FUN_004186f0() / m_uiHealthValue) * ::g_d100;
            }
            else
            {
                if (!bPercent)
                    return m_uiHealthValue;
                else
                    return ::DAT_01016410;
            }
        }
        else
        {
            if (!bPercent)
                return m_uiHealthValue;
            else
                return ::DAT_01016410;
        }
    }
    return DAT_01012054;
}

struct Pt3
{
    float x, y, z;
    Pt3();
    Pt3(float, float, float);
};
struct Pt2
{
    float x, y;
    Pt2();
    Pt2(float, float);
};
struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};

struct NiFrustum
{
    float m_fLeftBound, m_fRightBound, m_fTopBound, m_fBottomBound, m_fNearPlane, m_fFarPlane;
    bool m_bOrthographic;
    NiFrustum(bool);
};

struct NiUpdateData
{
    float fTime;
    int a, b;
    NiUpdateData(float, bool, bool);
};

struct IDev
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual long SetFoo(int);
};

struct Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual IDev* GetDev();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void SetBackground(const void*);
    virtual void v44();
    virtual void GetBackground(void*);
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void SetFlag(int);
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(Obj*, int);


    void SetColB(void*);
};

struct NiNodeX : Obj
{
    unsigned int unk04[(0xac - 4) / 4];
    NiNodeX(unsigned int);
};
struct TriData : Obj
{
    unsigned int unk04[(0x50 - 4) / 4];
    TriData(unsigned int, Pt3*, Pt3*, void*, Pt2*, unsigned int, unsigned int, unsigned int, unsigned int,
            unsigned short*, unsigned short*);
};
struct TexProp : Obj
{
    unsigned int unk04[(0x80 - 4) / 4];
    TexProp();
};
struct TriStrips : Obj
{
    unsigned int unk04[(0xc4 - 4) / 4];
    TriStrips(Obj*);
};
struct Camera : Obj
{
    unsigned int unk04[(0x114 - 4) / 4];
    Camera();
};
struct Light : Obj
{
    unsigned int unk04[(0xfc - 4) / 4];
    Light();
};
struct MatProp : Obj
{
    unsigned int unk04[(0x4c - 4) / 4];
    MatProp();
};
struct StencilProp : Obj
{
    unsigned int unk04[(0x24 - 4) / 4];
    StencilProp();
};
struct RTex : Obj
{
    unsigned int unk04[(0x280 - 4) / 4];
    RTex(unsigned int, unsigned int, unsigned int);
};

struct VisArray
{
    unsigned int unk00[0xc4 / 4];
    VisArray(int);
    ~VisArray();
};

struct TexMgr
{
};

struct LoadInfo
{
    int a;
    int iFlag;
};

struct Cell
{
};

struct GCell
{
    Cell* pCell;
};

struct ObjPtr
{
    Obj* p;
    ObjPtr(Obj*);
    ~ObjPtr();
    ObjPtr& operator=(Obj*);
    Obj* operator->() const;
};

struct Holder
{
};


extern char DAT_01189184;

struct Grid
{
    void* vtbl;
    int iHorizontalPixelCenterObj;
    int iCenterPixelY;
    unsigned int uiDimension;
    GCell* m_pGridCells;
    float fX;
    float fY;
    int unk1c;
    int unk20;
    ObjPtr spRT;

    void FUN_004baf10();
};

// Builds a grid of textured cell meshes, sets up an orthographic camera and light, and renders the scene into a render target texture.
// @fnv 0x004baf10
void Grid::FUN_004baf10()
{
    Obj* pStencil4;
    Obj* pMat8;
    IDev* pDev4;
    Obj* pTailB;
    Pt3* pValueVal;
    unsigned short* pTrisA;
    Pt2* puVal;
    unsigned short* _pLens;
    Pt3* pNewA;
    unsigned int uiDimVal;
    bool bAllEmpty7;
    float fHalf5;
    AutoMemContext ctx(0x20, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\GridCell.cpp", 0x220);
    int iResult;
    LoadInfo* pInfo9;
    Obj* PPTmp = 0;
    ObjPtr m_pMenuLightParameters(0);
    unsigned int i;
    unsigned int julietz59_2;
    ObjPtr sp5_2(0);
    ObjPtr spCamera4(0);
    float aFHalfDim;
    ObjPtr spData3(0);
    ObjPtr spData_(0);
    float fSize6;
    NiFrustum kFrustumVal(false);
    bool bAllLoaded7;
    ObjPtr spCameraVal(0);
    Obj* pTexVal;
    Pt3 kPos3;
    RgbaColor kColorA(0.0f, 0.0f, 0.0f, 0.0f);
    Cell* pCam9;
    uiDimVal = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
    bAllEmpty7 = true;
    bAllLoaded7 = true;
    DAT_01189184 = 0;
    if (!::FUN_004bc400())
        return;
    fSize6 = (float)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) << 12);
    fHalf5 = 2048.0 - fSize6 / 2.0;
    ::FUN_004bc420((*(float *)&(const ::Pt2 &)(Pt2(fX + fHalf5, fY + fHalf5))), {});
    ::FUN_004bc440(fSize6);
    ::FUN_004bc3d0(::FUN_004bc3e0() | 0x20);
    if (uiDimVal == 0 || ((::Obj *)(::FUN_004bc3f0())) == 0)
    {
        ::FUN_004bc3d0(::FUN_004bc3e0() & ~0x20);
        ::FUN_00451570((void *)(0));
        return;
    }
    aFHalfDim = uiDimVal / 2.0;
    kPos3.y = aFHalfDim * -1.0;
    kPos3.x = kPos3.y;
    kPos3.z = 0.0f;
    m_pMenuLightParameters = new NiNodeX(0);

    pValueVal = new Pt3[4];
    pValueVal[0] = Pt3(0.0f, 0.0f, 0.0f);
    pValueVal[1] = Pt3(1.0f, 0.0f, 0.0f);
    pValueVal[2] = Pt3(1.0f, 1.0f, 0.0f);
    pValueVal[3] = Pt3(0.0f, 1.0f, 0.0f);

    pNewA = new Pt3[4];
    pNewA[0] = pNewA[1] = pNewA[2] = pNewA[3] = (*reinterpret_cast<::Pt3 *>((void *)&::DAT_011a9484));

    puVal = new Pt2[4];
    puVal[0] = Pt2(0.0f, 0.0f);
    puVal[1] = Pt2(1.0f, 0.0f);
    puVal[2] = Pt2(1.0f, 1.0f);
    puVal[3] = Pt2(0.0f, 1.0f);

    pTrisA = (unsigned short*)::FUN_00aa1070(8);
    pTrisA[0] = 1;
    pTrisA[1] = 0;
    pTrisA[2] = 2;
    pTrisA[3] = 3;
    _pLens = (unsigned short*)::FUN_00aa1070(2);
    _pLens[0] = 4;

    spData3 = new TriData(4, pValueVal, pNewA, 0, puVal, 1, 0, 2, 1, _pLens, pTrisA);

    for (i = 0; i < uiDimVal; i++)
    {
        for (julietz59_2 = 0; julietz59_2 < uiDimVal; julietz59_2++)
        {
            PPTmp = 0;
            pCam9 = ((::GCell *)(reinterpret_cast<::GridCellArray *>(this)->Get(i, julietz59_2)))->pCell;
            if (pCam9)
            {
                iResult = reinterpret_cast<::FUN_005477f0_Class *>((pCam9))->FUN_005477f0((int)(&pTexVal), (int)(&pInfo9));
                if (pTexVal && pInfo9 && pInfo9->iFlag)
                {
                    pTailB = ((::Obj *)(reinterpret_cast<::ActorMover *>((pTexVal))->GetCurrentMoveModeType()));
                    pDev4 = pTailB->GetDev();
                    pDev4->SetFoo(0);
                    pInfo9->iFlag = 0;
                }
                if (iResult == 1 && pTexVal)
                {
                    PPTmp = new TexProp();
                    reinterpret_cast<::FUN_00438230_Class *>((PPTmp))->FUN_00438230((::NiNode *)(pTexVal));
                    PPTmp->SetFlag(0);
                    bAllEmpty7 = bAllLoaded7 = false;
                }
                else if (iResult == 2)
                {
                    bAllLoaded7 = false;
                }
            }
            if (!PPTmp)
            {
                kPos3.y += 1.0;
                bAllEmpty7 = false;
                continue;
            }
            spCamera4 = new TriStrips(spData3.operator->());
            reinterpret_cast<::FUN_00440460_S *>(((spCamera4).operator->()))->FUN_00440460((const ::V3 *)(const ::Pt3 *)(&kPos3));
            reinterpret_cast<::FUN_00439410_cls *>(((spCamera4).operator->()))->FUN_00439410((::ArgObject *)(PPTmp));
            ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(::Obj *)(spCamera4.operator->()), 0, 0);
            m_pMenuLightParameters->AttachChildInAvailableSlot(spCamera4.operator->(), 1);
            kPos3.y += 1.0;
        }
        kPos3.x += 1.0;
        kPos3.y = aFHalfDim * -1.0;
    }

    if (bAllEmpty7)
    {
        ::FUN_00451570((void *)(((unsigned int)(reinterpret_cast<::CLS_004bc240 *>((((::Holder *)(::GetDefaultFullMaskTextureProperty()))))->FUN_004bc240()))));
        return;
    }
    else if (bAllLoaded7)
    {
        ::FUN_004bc3d0(::FUN_004bc3e0() & ~0x20);
        ::FUN_00451570((void *)(0));
        return;
    }

    sp5_2 = new NiNodeX(0);
    spData_ = new Camera();
    sp5_2->AttachChildInAvailableSlot(spData_.operator->(), 1);
    reinterpret_cast<::FUN_004bc1f0_S *>(((sp5_2).operator->()))->FUN_004bc1f0(0.0f, 0.0f, 1.0f);
    NiUpdateData kUninitB(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((sp5_2).operator->()))->FUN_00a59c60((std::intptr_t)(&kUninitB));
    reinterpret_cast<::CamLook *>(((spData_).operator->()))->SetLookAt((*(const ::CamPoint *)(&(*reinterpret_cast<char *>((void *)&::NiPoint3::ZERO)))), (*(const ::CamPoint *)(&(*reinterpret_cast<char *>(&::DAT_011a9478)))));
    NiUpdateData kUnlock(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((spData_).operator->()))->FUN_00a59c60((std::intptr_t)(&kUnlock));
    NiUpdateData kUiCopy1(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((sp5_2).operator->()))->FUN_00a59c60((std::intptr_t)(&kUiCopy1));

    kFrustumVal.m_bOrthographic = true;
    kFrustumVal.m_fBottomBound = kFrustumVal.m_fLeftBound = aFHalfDim * -1.0;
    kFrustumVal.m_fTopBound = kFrustumVal.m_fRightBound = aFHalfDim;
    kFrustumVal.m_fNearPlane = 1.0f;
    kFrustumVal.m_fFarPlane = 2.0f;
    reinterpret_cast<::NiCamera *>(((spData_).operator->()))->UpdateViewFrustum((*(const ::NiFrustum *)(&kFrustumVal)));

    spCameraVal = new Light();
    reinterpret_cast<::FUN_004bc280_S *>(((spCameraVal).operator->()))->FUN_004bc280((const ::C3 *)(void *)(&(*reinterpret_cast<char *>(&::DAT_011a9b7c))));
    reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>(((spCameraVal).operator->()))->SetEffectColor((*(const ::fnv_004bc2e0::NiColor *)(&(*reinterpret_cast<char *>(&::DAT_011a9b7c)))));
    ::FUN_00a89af0((std::intptr_t)((spCameraVal).operator->()));

    pMat8 = new MatProp();
    reinterpret_cast<::FUN_004534f0_shell *>((pMat8))->FUN_004534f0((unsigned int)(&(*reinterpret_cast<char *>(&::DAT_011a9b7c))));
    reinterpret_cast<::FUN_004534f0_shell *>((pMat8))->FUN_004534f0((unsigned int)(&(*reinterpret_cast<char *>(&::DAT_011a9b7c))));
    reinterpret_cast<::fnv_004bc450::FUN_004bc450_S *>((pMat8))->FUN_004bc450((const ::fnv_004bc450::C3 *)(void *)(&(*reinterpret_cast<char *>(&::DAT_011a9b7c))));
    reinterpret_cast<::FUN_00439410_cls *>(((m_pMenuLightParameters).operator->()))->FUN_00439410((::ArgObject *)(pMat8));

    pStencil4 = new StencilProp();
    reinterpret_cast<::fnv_0049ee30::NiObjectNET *>((pStencil4))->FUN_0049ee30(3);
    reinterpret_cast<::FUN_00439410_cls *>(((m_pMenuLightParameters).operator->()))->FUN_00439410((::ArgObject *)(pStencil4));

    if (reinterpret_cast<::_FUN_00822510_Class *>(&(spRT))->operator==(0))
    {
        spRT = ((::Obj *)(reinterpret_cast<::Pool *>((((::TexMgr *)(::FUN_004a0ea0()))))->FUN_00b6e110((std::uintptr_t)(((void *)(::FUN_0043c4b0()))), {}, {}, {}, {})));
    }
    ((::Obj *)(::FUN_004bc3f0()))->GetBackground(&kColorA);
    ((::Obj *)(::FUN_004bc3f0()))->SetBackground(&(*reinterpret_cast<char *>(&::DAT_011a9bd0)));
    reinterpret_cast<::FUN_00a5a040_Class *>(((m_pMenuLightParameters).operator->()))->FUN_00a5a040();
    NiUpdateData kUiMaxRow(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((m_pMenuLightParameters).operator->()))->FUN_00a59c60((std::intptr_t)(&kUiMaxRow));
    NiUpdateData kUiLock1(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((sp5_2).operator->()))->FUN_00a59c60((std::intptr_t)(&kUiLock1));
    NiUpdateData kUiCopy2(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((spData_).operator->()))->FUN_00a59c60((std::intptr_t)(&kUiCopy2));
    VisArray kVis(0);
    ObjPtr spMeshB(new RTex(0x63, 1, 0x2f7));
    reinterpret_cast<::FUN_004a0fd0_shell *>(&(kVis))->FUN_004a0fd0((::NiNode *)(::Obj *)(spMeshB.operator->()));
    reinterpret_cast<::_Dummy_004bc4a0 *>(((spMeshB).operator->()))->SetAccumulate(false);
    ::FUN_00b6b8d0(7, (::NiRenderTargetGroup *)(((unsigned int)(reinterpret_cast<::BSRenderedTexture *>(((spRT).operator->()))->GetGroup()))));
    ::FUN_00b6bee0(spData_.operator->(), m_pMenuLightParameters.operator->(), (::BSShaderAccumulator *)(::VisArray *)(&kVis));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(::Obj *)(spData_.operator->()), (::BSShaderAccumulator *)(::Obj *)(spMeshB.operator->()), 0);
    ::BSRenderedTexture::EndAllAndResetRendererState();
    reinterpret_cast<::FUN_004a0fd0_shell *>(&(kVis))->FUN_004a0fd0((::NiNode *)(::Obj *)(0));
    spMeshB = 0;
    ::FUN_00451570((void *)(reinterpret_cast<::FUN_004bc320_shell *>(((spRT).operator->()))->FUN_004bc320(0)));
    reinterpret_cast<::_Dummy_004bc4a0 *>((((::Obj *)(::FUN_00b4f5c0()))))->SetAccumulate(true);
    ((::Obj *)(::FUN_004bc3f0()))->SetBackground(&kColorA);
}

#include "generated/data/fallout_shared/gridcell.inc"
