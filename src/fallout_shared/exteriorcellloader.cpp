
// src/fallout_shared/exteriorcellloader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/exteriorcellloader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/DeletionDataHandler.h"
#include "fnv/decl/FUN_00449190_cls.h"
#include "fnv/decl/FUN_00451250_shell.h"
#include "fnv/decl/FUN_00451cd0_shell.h"
#include "fnv/decl/FUN_00461330_shell.h"
#include "fnv/decl/FUN_00528560_Host.h"
#include "fnv/decl/FUN_0053f440_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00545cf0_Cls.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_0092c870_shell.h"
#include "fnv/decl/FUN_00961f30_Class.h"
#include "fnv/decl/FUN_00c3fca0_Class.h"
#include "fnv/decl/LandForm.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/WorldCellLoader.h"
#include "fnv/decl/fnv_00440640__FUN_00449a20_cls.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_0053fa40__HostMesh53.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00449000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_0049c000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011de000.h"
struct IOManager
{
    void SubmitTask();
};

struct ExteriorCellLoaderTask : IOManager
{
    void FUN_00527ce0();
};

// @fnv 0x00527ce0
void __thiscall ExteriorCellLoaderTask::FUN_00527ce0()
{
    SubmitTask();
}

struct IntPoint2D
{
    int iX;
    int iY;
};

struct IOTask
{
};

struct FUN_00527df0_shell
{
    IOTask m_IOTask;
    IntPoint2D* m_pGridCoordinates;
    bool GetDescription(char* apDescription, unsigned int aiBufferSize);
};


// Formats the cell coordinates of the task's cell into apDescription using _sprintf_s and returns true.
// @fnv 0x00527df0
bool FUN_00527df0_shell::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    ::FUN_00406d00(apDescription, aiBufferSize, "ExteriorCellLoaderTask for cell ( %i, %i )",
               ((IntPoint2D*)*(int*)((char*)this + 0x1c))->iX, ((IntPoint2D*)*(int*)((char*)this + 0x1c))->iY);
    return true;
}

struct FUN_00528790_shell
{
    char bUnk96;
    char GetUnk60Byte();
};

// @fnv 0x00528790
char FUN_00528790_shell::GetUnk60Byte()
{
    return *reinterpret_cast<char*>(this + 0x60);
}

struct FUN_005287e0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    bool FUN_005287e0();
};

// @fnv 0x005287e0
bool FUN_005287e0_shell::FUN_005287e0()
{
    return m_0c == 5;
}

extern int DAT_0102d078;

struct FUN_00528800_shell
{
    int m_val;
    void FUN_00528800();
};

// @fnv 0x00528800
void FUN_00528800_shell::FUN_00528800()
{
    m_val = (int)&DAT_0102d078;
}

struct FUN_00528820_shell
{
    void ClearField();
};

// @fnv 0x00528820
void FUN_00528820_shell::ClearField()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) = 0;
}


struct FUN_00440640_shell
{
};

struct FUN_00527c70_shell
{
    char* m_00;
    char* m_1c;
    void FUN_00527c70();
};

// Sets m_00 to "@|R", deallocates the pointer at offset 0x1c, then calls FUN_00440640 on this.
// @fnv 0x00527c70
void FUN_00527c70_shell::FUN_00527c70()
{
    m_00 = "@|R";
    char* p = *(char**)((char*)this + 0x1c);
    ::FUN_00401030(p);
    reinterpret_cast<::fnv_00440640::FUN_00449a20_cls *>((((FUN_00440640_shell*)this)))->FUN_00440640();
}

struct NiNode
{
};
struct TESObjectCELL
{
public:
    void FUN_005571a0(bool);
};

struct FUN_00454b90_shell
{
    int m_00;
    void AddCellToBuffer(TESObjectCELL* apCell);
};

struct FUN_005287b0_shell
{
    void FUN_005287b0(TESObjectCELL* apCell);
};

// If apCell is non-null and its FUN_00545cb0() node is non-null, calls AddCellToBuffer on the global g_TES object with apCell.
// @fnv 0x005287b0
void FUN_005287b0_shell::FUN_005287b0(TESObjectCELL* apCell)
{
    if (apCell)
    {
        if (reinterpret_cast<::FUN_00545cb0_shell *>((apCell))->FUN_00545cb0())
        {
            ((FUN_00454b90_shell*)(g_TES))->AddCellToBuffer(apCell);
        }
    }
}

struct TES
{
};
struct DH
{
};
struct TESWorldSpace
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};
struct FUN_00527d80_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    TESWorldSpace* m_1c;
    void FUN_00527d80(int, int);
};
// @fnv 0x00527d80
void FUN_00527d80_shell::FUN_00527d80(int, int)
{
    if (m_1c->m_0c && reinterpret_cast<::TESCallHelper *>((((TES*)g_TES)))->IsCellBuffered((TESObjectCELL*)m_1c->m_0c, false))
        reinterpret_cast<::DeletionDataHandler *>((g_dataHandler))->DeleteObject((::DeletionObject *)(::TESObjectCELL *)((TESObjectCELL*)m_1c->m_0c));
    reinterpret_cast<::FUN_00528560_Host *>((((TESWorldSpace*)m_18)))->GetCellAtGridCoord(m_1c->m_00, m_1c->m_04);
}

struct FUN_00528840_shell : public FUN_00528800_shell
{
    void* FUN_00528840(unsigned int flags);
};

// Calls FUN_00528800, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00528840
void* FUN_00528840_shell::FUN_00528840(unsigned int flags)
{
    FUN_00528800();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct LoaderDummy
{
};
struct CellRefDummy
{
};
struct MyCellEx
{
    char _pad[0xC];
    CellRefDummy* pObj;
};
struct FUN_00527cb0_shell
{
    char _pad[0x18];
    LoaderDummy* pLoader;
    IntPoint2D* m_pGridCoordinates;
    void FUN_00527cb0();
};

struct FUN_00527d00_shell
{
    char _pad[0x18];
    FUN_005287b0_shell* pLoader;
    char* m_pGridCoordinates;
    void FUN_00527d00();
};

// @fnv 0x00527d00
void FUN_00527d00_shell::FUN_00527d00()
{
    if (!FUN_00449130((int*)this))
    {
        if (*(int*)(m_pGridCoordinates + 0xc) != 0)
        {
            if (*(unsigned char*)(m_pGridCoordinates + 0x10) != 0)
            {
                pLoader->FUN_005287b0((TESObjectCELL*)*(int*)(m_pGridCoordinates + 0xc));
            }
        }
    }
    *(char*)(m_pGridCoordinates + 0x10) = 0;
    reinterpret_cast<::FUN_00528560_Host *>((((TESWorldSpace*)pLoader)))->GetCellAtGridCoord(*(int*)(m_pGridCoordinates), *(int*)(m_pGridCoordinates + 4));
}

struct CellEffects;
struct NiPoint2
{
    float x;
    float y;
};
struct WorldSpaceAccess : TESWorldSpace
{
};
struct NodeEffects : NiNode
{
};
struct CellEffects : TESObjectCELL
{
};
struct GameWorld : TES
{
};
struct GlobalSettings
{
    unsigned char* __thiscall FUN_00408d60();
};
struct CellLoadData : IntPoint2D
{
    WorldSpaceAccess* worldSpace;
    CellEffects* cell;
    bool loaded;
};
struct CellLoader
{
    void __thiscall FUN_00528620(CellLoadData* data);
};
// @fnv 0x00527cb0
void FUN_00527cb0_shell::FUN_00527cb0()
{
    reinterpret_cast<::CellLoader *>((pLoader))->FUN_00528620((::CellLoadData *)(m_pGridCoordinates));
    reinterpret_cast<::TESObjectCELL *>((((MyCellEx*)m_pGridCoordinates)->pObj))->FUN_005571a0(1);
}
// @fnv 0x00528620
void CellLoader::FUN_00528620(CellLoadData* pLoadData)
{
    if (pLoadData != 0)
    {
        if (pLoadData->cell == 0)
            pLoadData->cell = ((::CellEffects *)(reinterpret_cast<::WorldCellLoader *>((pLoadData->worldSpace))->FUN_00585b30(pLoadData->iX, pLoadData->iY)));
        if (pLoadData->cell == 0)
            pLoadData->cell = ((::CellEffects *)(reinterpret_cast<::FUN_00461330_shell *>(((*reinterpret_cast<::GameWorld * *>(&::g_dataHandler))))->FUN_00461330((const char *)(0), pLoadData->iX, pLoadData->iY, (::TESWorldSpace *)(pLoadData->worldSpace))));
        reinterpret_cast<::FUN_00545cf0_Cls *>((pLoadData->cell))->GetOrCreateWidget();
        NodeEffects* pNode = ((::NodeEffects *)(reinterpret_cast<::S00546fb0_Cell *>((pLoadData->cell))->FUN_00546fb0()));
        if (pNode != 0)
        {
            reinterpret_cast<::LandForm *>((pNode))->FUN_00535b90(true);
            reinterpret_cast<::fnv_0053fa40::HostMesh53 *>((pNode))->FUN_0053fa40((*reinterpret_cast<::FUN_00528790_shell * *>(&::g_TES))->GetUnk60Byte());
        }
        if (!((bool)(reinterpret_cast<::FUN_00451cd0_shell *>((pLoadData->cell))->FUN_00451cd0())))
        {
            NiPoint2 position;
            reinterpret_cast<::FUN_0053f440_shell *>((((::NodeEffects *)(reinterpret_cast<::S00546fb0_Cell *>((pLoadData->cell))->FUN_00546fb0()))))->FUN_0053f440();
            reinterpret_cast<::FUN_00451250_shell *>((pLoadData->cell))->SetFlag2(position.x < reinterpret_cast<::FUN_005471e0_shell *>((pLoadData->cell))->FUN_005471e0());
            if (*(*reinterpret_cast<::GlobalSettings *>(&::g_011c7adc)).FUN_00408d60() && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((pLoadData->cell))->FUN_004518e0() && !((bool)(reinterpret_cast<::FUN_00451cd0_shell *>((pLoadData->cell))->FUN_00451cd0())))
            {
                ::FUN_0049c860((::MeshInput *)(pLoadData->cell));
            }
            reinterpret_cast<::FUN_00961f30_Class *>((pLoadData->cell))->SetByteAt54(true);
        }
        pLoadData->loaded = true;
    }
}

struct QueuedTask
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Run(int eState, void* pArg);
    int m_04;
    int m_08;
    int m_eAnimationState;
};
struct FUN_00528870_shell
{
    bool RunQueuedTask(QueuedTask* pTask, void* pArg);
};

// @fnv 0x00528870
bool FUN_00528870_shell::RunQueuedTask(QueuedTask* pTask, void* pArg)
{
    while (true)
    {
        int eState = pTask->m_eAnimationState;
        switch (eState)
        {
        case 0:
            if (reinterpret_cast<::FUN_00449190_cls *>((pTask))->SetState(eState, 6))
            {
                pTask->Run(eState, pArg);
                return true;
            }
            break;
        case 1:
            if (reinterpret_cast<::FUN_00449190_cls *>((pTask))->SetState(eState, 6))
            {
                reinterpret_cast<::FUN_0092c870_shell *>((pTask))->FUN_0092c870();
                reinterpret_cast<::FUN_00c3fca0_Class *>(this)->FUN_0044e050((::InputValues *)(pTask));
                pTask->Run(eState, pArg);
                ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(pTask));
                return true;
            }
            break;
        case 2:
            while (pTask->m_eAnimationState == 3)
                FUN_0040fca0(0);
            break;
        case 3:
        case 4:
            return false;
        case 5:
            if (reinterpret_cast<::FUN_00449190_cls *>((pTask))->SetState(eState, 6))
            {
                pTask->Run(eState, pArg);
                return true;
            }
            break;
        case 6:
            return true;
        default:
            return true;
        }
    }
    return true;
}

struct CellLoaderDeletingTask : FUN_00527c70_shell
{
    void* __thiscall FUN_00527c40(unsigned int aiFlags);
};

// Calls FUN_00527c70, deallocates this when aiFlags bit 0 is set, and returns this.
// @fnv 0x00527c40
void* __thiscall CellLoaderDeletingTask::FUN_00527c40(unsigned int aiFlags)
{
    FUN_00527c70();
    if (aiFlags & 1)
        ::FUN_00401030(this);
    return this;
}
