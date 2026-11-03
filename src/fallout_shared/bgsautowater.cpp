
// src/fallout_shared/bgsautowater.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsautowater.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/CleanupOwner.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00439680_class.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_0045cb90_cls.h"
#include "fnv/decl/FUN_0049db00_Class.h"
#include "fnv/decl/FUN_0049db30_Class.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_0049f190_Class.h"
#include "fnv/decl/FUN_0049f510.h"
#include "fnv/decl/FUN_0049f560_Holder.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_00547770_shell.h"
#include "fnv/decl/FUN_00580130_shell.h"
#include "fnv/decl/FUN_00586300_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_00633ba0_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/LandForm.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/NiPosData.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/PlaneArray.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/S_00c4e0a0_Class.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaterRef.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_0049f210__FUN_0049f210_class.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0049c000.h"
#include "fnv/symbols_0049d000.h"
#include "fnv/symbols_0049e000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_006b9000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0106c000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011cc000.h"
struct NiProperty
{
    virtual ~NiProperty();
};
struct NiStencilProperty : NiProperty
{
    virtual ~NiStencilProperty();
    void* FUN_0049ed40(unsigned int);
};
extern "C" void __cdecl FUN_0049ed70(NiStencilProperty*);

struct Flag512Receiver
{
};

struct FUN_0049ed90_shell : Flag512Receiver
{
    void FUN_0049ed90(bool bAlpha);
};

// @fnv 0x0049ed90
void __thiscall FUN_0049ed90_shell::FUN_0049ed90(bool bAlpha)
{
    reinterpret_cast<::FUN_00633ba0_Class *>((this))->FUN_00633ba0(bAlpha, 1);
}

struct NiObjectNET
{
    void FUN_00439360(unsigned short, unsigned int, unsigned int);
    void FUN_0049edb0(unsigned short argument0);
};

// Forwards the given texture slot to FUN_00439360 with flags 0xf000 and value 0xc.
// @fnv 0x0049edb0
void NiObjectNET::FUN_0049edb0(unsigned short argument0)
{
    FUN_00439360(argument0, 0xf000, 0xc);
}

namespace fnv_0049ede0 {
struct NiObjectNET
{
};

struct FUN_0049ede0_shell : NiObjectNET
{
    void FUN_0049ede0(unsigned short argument0);
};

// Calls FUN_00439360 with argument0, 0x380 and 7.
// @fnv 0x0049ede0
void FUN_0049ede0_shell::FUN_0049ede0(unsigned short argument0)
{
    reinterpret_cast<::NiObjectNET *>(this)->FUN_00439360(argument0, 0x380, 7);
}
}  // namespace fnv_0049ede0

namespace fnv_0049ee10 {
struct NiObjectNET
{
    void FUN_0049ee10(unsigned short argument0);
};

// @fnv 0x0049ee10
void NiObjectNET::FUN_0049ee10(unsigned short ausValue)
{
    reinterpret_cast<::NiObjectNET *>(this)->FUN_00439360(ausValue, 0x70, 4);
}
}  // namespace fnv_0049ee10

namespace fnv_0049ee30 {
struct NiObjectNET
{
    void FUN_0049ee30(unsigned short a);
};

// Calls FUN_00439360 with the given unsigned short and the constants 0xc00 and 0xa.
// @fnv 0x0049ee30
void NiObjectNET::FUN_0049ee30(unsigned short a)
{
    reinterpret_cast<::NiObjectNET *>(this)->FUN_00439360(a, 0xc00, 0xa);
}
}  // namespace fnv_0049ee30

struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void SetEnabledFlag(bool enabled);
};

void TaskQueueInterface::SetTaskFlagDWord(bool, unsigned int)
{}

// @fnv 0x0049ee80
void TaskQueueInterface::SetEnabledFlag(bool enabled)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(enabled, 0x8000);
}

struct FUN_004392c0_shell
{
    void FUN_004392c0();
};

extern void* DAT_0101e07c;

struct FUN_0049ed70_shell : NiStencilProperty
{
    void FUN_0049ed70();
};
// @fnv 0x0049ed40
void* NiStencilProperty::FUN_0049ed40(unsigned int flags)
{
    reinterpret_cast<::FUN_0049ed70_shell *>((this))->FUN_0049ed70();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x24);
    return this;
}

// @fnv 0x0049ed70
void FUN_0049ed70_shell::FUN_0049ed70()
{
    *reinterpret_cast<void**>(this) = &DAT_0101e07c;
    reinterpret_cast<FUN_004392c0_shell*>(this)->FUN_004392c0();
}

// Clears the bits in flags at offset 0x18 and inserts value shifted by shift into them.
// @fnv 0x00439360
void NiObjectNET::FUN_00439360(unsigned short value, unsigned int uiMask, unsigned int shift)
{
    *(unsigned short*)((char*)this + 0x18) =
        (*(unsigned short*)((char*)this + 0x18) & ~(unsigned short)uiMask) | (value << (unsigned short)shift);
}

struct FUN_0049ee60_shell : TaskQueueInterface
{
    void FUN_0049ee60(bool enabled);
};

// @fnv 0x0049ee60
void FUN_0049ee60_shell::FUN_0049ee60(bool enabled)
{
    SetEnabledFlag(enabled);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    bool FUN_004390c0(const ::NiPoint3 &);
};

struct FUN_0049eea0_shell
{
    char pad[0x30];
    NiPoint3 m_kPoint;
    void FUN_0049eea0(const NiPoint3& arPoint);
};

// @fnv 0x0049eea0
void FUN_0049eea0_shell::FUN_0049eea0(const NiPoint3& arPoint)
{
    m_kPoint = arPoint;
}

struct Vec2
{
    float x;
    float y;
    Vec2(float px, float py);
};

struct FUN_0049eed0_item
{
    NiPoint3* FUN_006a7af0();
};

struct FUN_0049eed0_list
{
};

struct FUN_0049eed0_target
{
};

// Iterates the list's items, builds a Vec2 from each item's NiPoint3 x/y, and returns true if the target accepts any of them.
// @fnv 0x0049eed0
bool AnyPointInListMatches(FUN_0049eed0_list* apList, FUN_0049eed0_target* apTarget)
{
    for (int i8 = 0; i8 < ((int)(reinterpret_cast<::ActorMover *>((apList))->GetCurrentMoveModeType())); i8++)
    {
        NiPoint3 p2 = *((::FUN_0049eed0_item *)(::FUN_00559450((int *)(apList))))->FUN_006a7af0();
        Vec2 v(p2.x, p2.y);
        if (reinterpret_cast<::S_00c4e0a0_Class *>((apTarget))->ContainsMatchingTriple((*(int *)&(const ::Vec2 &)(v)), {}))
        {
            return true;
        }
    }
    return false;
}

struct MeshPoint
{
    float x, y, z;
    MeshPoint* FUN_00416870(float, float, float);
};
struct FUN_00a69990
{
    float x, y, z, w;
    FUN_00a69990(const MeshPoint&, const MeshPoint&);
};
struct FUN_0049f1c0
{
    MeshPoint* data;
    int size;
    int capacity;
    int allocator;
    FUN_0049f1c0();
    ~FUN_0049f1c0();
    MeshPoint& FUN_006a1440(int);
};
struct FUN_0049f640
{
    FUN_0049f1c0* data;
    int size;
    int capacity;
    int allocator;
    FUN_0049f640();
    ~FUN_0049f640();
    FUN_0049f1c0& FUN_00558dd0(int) const;
};
struct ScriptProgram
{
};
struct MeshMode
{
};
struct MeshInput
{
};
extern unsigned short DAT_0118ae90[];
extern unsigned short DAT_0118ae92[];
extern unsigned short DAT_0118ae94[];
// Builds triangle geometry from the mesh's vertex data, clipping against a plane and collecting boundary edges into DAT_011c57ac.
// @fnv 0x0049c930
void BuildMeshBoundaryGeometry(MeshInput* pMeshInput)
{
    ScriptProgram* mesh = ((::ScriptProgram *)(reinterpret_cast<::S00546fb0_Cell *>((pMeshInput))->FUN_00546fb0()));
    float height = reinterpret_cast<::FUN_005471e0_shell *>((pMeshInput))->FUN_005471e0();
    if (!DAT_011c57ac)
        DAT_011c57ac = new FUN_0049f1c0;
    else
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((DAT_011c57ac))->Clear(true);
    if (mesh)
    {
        bool active8 = reinterpret_cast<::FUN_0045cb90_cls *>((mesh))->FUN_0045cb90();
        if (!active8)
            reinterpret_cast<::LandForm *>((mesh))->FUN_00535b90(0);
        FUN_0049f640 _list1;
        for (int i = 0; i < 4; i++)
        {
            FUN_0049f1c0 temporary;
            reinterpret_cast<::PlaneArray *>(&(_list1))->FUN_0049f690(i, (const ::PlaneElem &)(temporary));
        }
        bool offset6 = false;
        float _saved = 0.0f;
        if (((::MeshMode *)(reinterpret_cast<::TESObjectCELL *>((pMeshInput))->GetParentWorldSpace())) && ((unsigned char)(reinterpret_cast<::FUN_00586300_shell *>((((::MeshMode *)(reinterpret_cast<::TESObjectCELL *>((pMeshInput))->GetParentWorldSpace()))))->IsFlag80Set())))
        {
            _saved = reinterpret_cast<::FUN_0049db00_Class *>((mesh))->FUN_0049db00();
            offset6 = true;
        }
        MeshPoint** _readObject = ((::MeshPoint **)(reinterpret_cast<::FUN_0049db30_Class *>((mesh))->GetSecondPointer()));
        for (int side = 0; side < 4; side++)
        {
            for (int triangle = 0; triangle < 1019; triangle++)
            {
                unsigned short _type = DAT_0118ae90[triangle];
                unsigned short _item = DAT_0118ae92[triangle];
                unsigned short _color = DAT_0118ae94[triangle];
                MeshPoint _cross = _readObject[side][_type];
                MeshPoint _delta = _readObject[side][_item];
                MeshPoint _point = _readObject[side][_color];
                if (offset6)
                {
                    _cross.z += _saved;
                    _delta.z += _saved;
                    _point.z += _saved;
                }
                if (reinterpret_cast<::NiPlane *>(&(_cross))->operator==((const ::NiPlane &)(_delta)) && reinterpret_cast<::NiPlane *>(&(_cross))->operator==((const ::NiPlane &)(_point)) && reinterpret_cast<::NiPlane *>(&(_delta))->operator==((const ::NiPlane &)(_point)))
                {
                    MeshPoint origin6;
                    origin6.FUN_00416870(0.0f, 0.0f, height);
                    MeshPoint normalVal;
                    normalVal.FUN_00416870(0.0f, 0.0f, 1.0f);
                    FUN_00a69990 _created(normalVal, origin6);
                    unsigned short count8 = 0;
                    bool _done = false;
                    bool _active = false;
                    int _bound = ((int)(::GetCellCornerFlags((::Cell *)(pMeshInput), (*(::Pt *)&(const ::MeshPoint &)(_cross)))));
                    int aCount2 = ((int)(::GetCellCornerFlags((::Cell *)(pMeshInput), (*(::Pt *)&(const ::MeshPoint &)(_delta)))));
                    int _current = ((int)(::GetCellCornerFlags((::Cell *)(pMeshInput), (*(::Pt *)&(const ::MeshPoint &)(_point)))));
                    MeshPoint _orient;
                    new ((void *)&(_orient)) ::Vec3();
                    int result3 = ::FUN_006b9a10((const ::S006b9a10_Pt &)(_cross), (const ::S006b9a10_Pt &)(_delta), (const ::S006b9a10_Pt &)(origin6), (const ::S006b9a10_Pt &)(normalVal), (::S006b9a10_Pt &)(_orient));
                    if (result3 == 1)
                    {
                        if (reinterpret_cast<::NiPoint3 *>(&(_cross))->FUN_004390c0((const ::NiPoint3 &)(_orient)) || reinterpret_cast<::NiPoint3 *>(&(_delta))->FUN_004390c0((const ::NiPoint3 &)(_orient)))
                            _done = true;
                        reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                        ++count8;
                        if ((_bound & 1) && (aCount2 & 1))
                            reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(0)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                        else if ((_bound & 2) && (aCount2 & 2))
                            reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(1)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                        else if ((_bound & 4) && (aCount2 & 4))
                            reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(2)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                        else if ((_bound & 8) && (aCount2 & 8))
                            reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(3)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                    }
                    else if (result3 == -1)
                    {
                        _active = true;
                        reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                        reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                        count8 += 2;
                    }
                    result3 = ::FUN_006b9a10((const ::S006b9a10_Pt &)(_cross), (const ::S006b9a10_Pt &)(_point), (const ::S006b9a10_Pt &)(origin6), (const ::S006b9a10_Pt &)(normalVal), (::S006b9a10_Pt &)(_orient));
                    if (result3 == 1)
                    {
                        bool add = true;
                        if (reinterpret_cast<::NiPoint3 *>(&(_cross))->FUN_004390c0((const ::NiPoint3 &)(_orient)) || reinterpret_cast<::NiPoint3 *>(&(_point))->FUN_004390c0((const ::NiPoint3 &)(_orient)))
                        {
                            if (_done || _active)
                                add = false;
                            else
                                _done = true;
                        }
                        if (add)
                        {
                            reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                            ++count8;
                            if ((_bound & 1) && (_current & 1))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(0)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                            else if ((_bound & 2) && (_current & 2))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(1)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                            else if ((_bound & 4) && (_current & 4))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(2)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                            else if ((_bound & 8) && (_current & 8))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(3)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                        }
                    }
                    else if (result3 == -1)
                    {
                        _active = true;
                        for (int discard = 0; discard < count8; discard++)
                            reinterpret_cast<::FUN_0049f510 *>((DAT_011c57ac))->FUN_0049f510_m();
                        reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                        reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                        count8 = 2;
                    }
                    result3 = ::FUN_006b9a10((const ::S006b9a10_Pt &)(_delta), (const ::S006b9a10_Pt &)(_point), (const ::S006b9a10_Pt &)(origin6), (const ::S006b9a10_Pt &)(normalVal), (::S006b9a10_Pt &)(_orient));
                    if (result3 == 1)
                    {
                        bool addThird = true;
                        if (reinterpret_cast<::NiPoint3 *>(&(_delta))->FUN_004390c0((const ::NiPoint3 &)(_orient)) || (reinterpret_cast<::NiPoint3 *>(&(_point))->FUN_004390c0((const ::NiPoint3 &)(_orient)) && (_done || _active)))
                            addThird = false;
                        if (addThird)
                        {
                            reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                            ++count8;
                            if ((aCount2 & 1) && (_current & 1))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(0)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                            else if ((aCount2 & 2) && (_current & 2))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(1)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                            else if ((aCount2 & 4) && (_current & 4))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(2)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                            else if ((aCount2 & 8) && (_current & 8))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(3)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_orient));
                        }
                    }
                    else if (result3 == -1)
                    {
                        _active = true;
                        for (int discardThird = 0; discardThird < count8; discardThird++)
                            reinterpret_cast<::FUN_0049f510 *>((DAT_011c57ac))->FUN_0049f510_m();
                        reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                        reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                        count8 = 2;
                    }
                    if (count8 != 2)
                    {
                        for (int discardAll = 0; discardAll < count8; discardAll++)
                            reinterpret_cast<::FUN_0049f510 *>((DAT_011c57ac))->FUN_0049f510_m();
                    }
                    if (_bound == 9)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_cross)) == 2)
                        {
                            _cross.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(0)))->ContainsPlane((const ::NiPlane &)(_cross)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(0)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(3)))->ContainsPlane((const ::NiPlane &)(_cross)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(3)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                        }
                    }
                    else if (_bound == 10)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_cross)) == 2)
                        {
                            _cross.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(1)))->ContainsPlane((const ::NiPlane &)(_cross)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(1)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(3)))->ContainsPlane((const ::NiPlane &)(_cross)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(3)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                        }
                    }
                    else if (_bound == 5)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_cross)) == 2)
                        {
                            _cross.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(0)))->ContainsPlane((const ::NiPlane &)(_cross)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(0)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(2)))->ContainsPlane((const ::NiPlane &)(_cross)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(2)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                        }
                    }
                    else if (_bound == 6)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_cross)) == 2)
                        {
                            _cross.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(1)))->ContainsPlane((const ::NiPlane &)(_cross)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(1)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(2)))->ContainsPlane((const ::NiPlane &)(_cross)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(2)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_cross));
                        }
                    }
                    if (aCount2 == 9)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_delta)) == 2)
                        {
                            _delta.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(0)))->ContainsPlane((const ::NiPlane &)(_delta)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(0)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(3)))->ContainsPlane((const ::NiPlane &)(_delta)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(3)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                        }
                    }
                    else if (aCount2 == 10)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_delta)) == 2)
                        {
                            _delta.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(1)))->ContainsPlane((const ::NiPlane &)(_delta)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(1)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(3)))->ContainsPlane((const ::NiPlane &)(_delta)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(3)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                        }
                    }
                    else if (aCount2 == 5)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_delta)) == 2)
                        {
                            _delta.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(0)))->ContainsPlane((const ::NiPlane &)(_delta)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(0)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(2)))->ContainsPlane((const ::NiPlane &)(_delta)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(2)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                        }
                    }
                    else if (aCount2 == 6)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_delta)) == 2)
                        {
                            _delta.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(1)))->ContainsPlane((const ::NiPlane &)(_delta)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(1)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(2)))->ContainsPlane((const ::NiPlane &)(_delta)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(2)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_delta));
                        }
                    }
                    if (_current == 9)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_point)) == 2)
                        {
                            _point.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(0)))->ContainsPlane((const ::NiPlane &)(_point)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(0)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(3)))->ContainsPlane((const ::NiPlane &)(_point)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(3)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                        }
                    }
                    else if (_current == 10)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_point)) == 2)
                        {
                            _point.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(1)))->ContainsPlane((const ::NiPlane &)(_point)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(1)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(3)))->ContainsPlane((const ::NiPlane &)(_point)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(3)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                        }
                    }
                    else if (_current == 5)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_point)) == 2)
                        {
                            _point.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(0)))->ContainsPlane((const ::NiPlane &)(_point)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(0)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(2)))->ContainsPlane((const ::NiPlane &)(_point)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(2)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                        }
                    }
                    else if (_current == 6)
                    {
                        if (reinterpret_cast<::NiCamera *>(&(_created))->ClassifyPoint((const ::NiPoint3 *)(const ::MeshPoint *)(&_point)) == 2)
                        {
                            _point.z = height;
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(1)))->ContainsPlane((const ::NiPlane &)(_point)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(1)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                            if (!reinterpret_cast<::FUN_0049f190_Class *>(&(_list1.FUN_00558dd0(2)))->ContainsPlane((const ::NiPlane &)(_point)))
                                reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>(&(_list1.FUN_00558dd0(2)))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_point));
                        }
                    }
                }
            }
        }
        if (!active8)
            reinterpret_cast<::CleanupOwner *>((mesh))->FUN_00536d80();
        for (int boundary = 0; boundary < 4; boundary++)
        {
            if (boundary == 0 || boundary == 1)
                reinterpret_cast<::FUN_0049f560_Holder *>(&(_list1.FUN_00558dd0(boundary)))->CallWithTwelve((int)(((bool (&)(const MeshPoint &, const MeshPoint &))::FUN_0049c800)));
            else
                reinterpret_cast<::FUN_0049f560_Holder *>(&(_list1.FUN_00558dd0(boundary)))->CallWithTwelve((int)(((bool (&)(const MeshPoint &, const MeshPoint &))::FUN_0049c7b0)));
            for (int pair = 0; pair < ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(_list1.FUN_00558dd0(boundary)))->GetName())); pair += 2)
            {
                if (((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(_list1.FUN_00558dd0(boundary)))->GetName())) > pair + 1)
                {
                    reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_list1.FUN_00558dd0(boundary).FUN_006a1440(pair)));
                    reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((DAT_011c57ac))->AddItem((const ::fnv_0049f210::NiPoint3 &)(_list1.FUN_00558dd0(boundary).FUN_006a1440(pair + 1)));
                }
            }
        }
    }
}

struct NiPoint2
{
    float x, y;
    NiPoint2(float x, float y);
};
struct Pt
{
    float x, y, z;
    Pt& operator+=(const NiPoint3& other);
};
struct CellOrigin
{
    NiPoint3 FUN_00535b30(bool interior);
};
struct Cell
{
};
// Offsets point by the cell origin, compares it against the four cell corners and returns a bitmask of which edges/corners it matches.
// @fnv 0x0049ef60
unsigned int __cdecl GetCellCornerFlags(Cell* cell, Pt point)
{
    unsigned int f = 0;  // Edge mask: west=1, east=2, north=4, south=8.
    // Translate the point into the cell's coordinate system.
    NiPoint3 i = ((::CellOrigin *)(reinterpret_cast<::S00546fb0_Cell *>((cell))->FUN_00546fb0()))->FUN_00535b30(false);
    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::Pt &)(point))->FUN_0063c8a0((void *)&(i));
    // Cell corners: p=southwest, a=southeast, s=northwest, h=northeast.
    NiPoint2 p(float(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX() << 12), float(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY() << 12));
    NiPoint2 a(float((reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX() << 12) + 4096), float(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY() << 12));
    NiPoint2 s(float(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX() << 12), float((reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY() << 12) + 4096));
    NiPoint2 h(float((reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX() << 12) + 4096), float((reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY() << 12) + 4096));
    if (point.x == p.x && point.y == p.y)
        f |= 9;
    else if (point.x == a.x && point.y == a.y)
        f |= 10;
    else if (point.x == s.x && point.y == s.y)
        f |= 5;
    else if (point.x == h.x && point.y == h.y)
        f |= 6;
    else if (point.x == p.x)
        f |= 1;
    else if (point.x == a.x)
        f |= 2;
    else if (point.y == p.y)
        f |= 8;
    else if (point.y == h.y)
        f |= 4;
    return f;
}

// Adapted from earlier contributor's unverified source; revised using official checker.
struct NiMemObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class NiFixedString
{
    void* m_00;

  public:
    NiFixedString(const char*);
    ~NiFixedString();
};
struct AutoMemHelper
{
    int m_00;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct FUN_00416870_t
{
    float x;
    float y;
    float z;
    FUN_00416870_t* FUN_00416870(float, float, float);
};
struct UpdData
{
    float m_00;
    bool m_04;
    float m_08;
};
struct AVObj
{
};
struct NodeObj
{
    ~NodeObj();
    int FUN_0049e3e0(unsigned int);
};
struct BufObj
{
    float x;
    float y;
    float z;
    FUN_00416870_t* FUN_00535b30();
};
struct WaterForm
{
};
struct ParamObj
{
};
struct Mgr
{
    void* FUN_0049f590(void**);
};
struct SettingObj
{
    unsigned char* FUN_00408d60();
};
namespace std {
float abs(float);
}
struct FUN_0055a2f0
{
    virtual void vslot00();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot0a();
    virtual void vslot0b();
    virtual void vslot0c();
    virtual void vslot0d();
    virtual void vslot0e();
    virtual void vslot0f();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot1a();
    virtual void vslot1b();
    virtual void vslot1c();
    virtual void vslot1d();
    virtual void vslot1e();
    virtual void vslot1f();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot2a();
    virtual void vslot2b();
    virtual void vslot2c();
    virtual void vslot2d();
    virtual void vslot2e();
    virtual void vslot2f();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35();
    virtual void vslot36();
    virtual void vslot37();
    virtual void vslot38();
    virtual void vslot39();
    virtual void vslot3a();
    virtual void vslot3b();
    virtual void vslot3c();
    virtual void vslot3d();
    virtual void vslot3e();
    virtual void vslot3f();
    virtual void vslot40();
    virtual void vslot41();
    virtual void vslot42();
    virtual void vslot43();
    virtual void vslot44();
    virtual void vslot45();
    virtual void vslot46();
    virtual void vslot47();
    virtual void vslot48();
    virtual void vslot49();
    virtual void vslot4a();
    virtual void vslot4b();
    virtual void vslot4c();
    virtual void vslot4d();
    virtual void vslot4e();
    virtual void vslot4f();
    virtual void vslot50();
    virtual void vslot51();
    virtual void vslot52();
    virtual void vslot53();
    virtual void vslot54();
    virtual void vslot55();
    virtual void vslot56();
    virtual void vslot57();
    virtual void vslot58();
    virtual void vslot59();
    virtual void vslot5a();
    virtual void vslot5b();
    virtual void vslot5c();
    virtual void vslot5d();
    virtual void vslot5e();
    virtual void vslot5f();
    virtual void vslot60();
    virtual void vslot61();
    virtual void vslot62();
    virtual void vslot63();
    virtual void vslot64();
    virtual void vslot65();
    virtual void vslot66();
    virtual void vslot67();
    virtual void vslot68();
    virtual void vslot69();
    virtual void vslot6a();
    virtual void vslot6b();
    virtual void vslot6c();
    virtual void vslot6d();
    virtual void vslot6e();
    virtual void vslot6f();
    virtual void vslot70();
    virtual void vslot71();
    virtual void vslot72();
    virtual void FUN_vt1cc(void*, bool);
    FUN_0055a2f0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
};
struct FUN_00b6abb0 : NiMemObject
{
    FUN_00b6abb0();
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
};
struct FUN_0049ec80 : NiMemObject
{
    FUN_0049ec80();
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
};
struct BSFadeNode : NiMemObject
{
    virtual void vslot00();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot0a();
    virtual void vslot0b();
    virtual void vslot0c();
    virtual void vslot0d();
    virtual void vslot0e();
    virtual void vslot0f();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot1a();
    virtual void vslot1b();
    virtual void vslot1c();
    virtual void vslot1d();
    virtual void vslot1e();
    virtual void vslot1f();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot2a();
    virtual void vslot2b();
    virtual void vslot2c();
    virtual void vslot2d();
    virtual void vslot2e();
    virtual void vslot2f();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35();
    virtual void vslot36();
    virtual void FUN_vtdc(void*, bool);
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    BSFadeNode();
};
struct FUN_00c37ec0 : NiMemObject
{
    virtual void vslot00();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot0a();
    virtual void vslot0b();
    virtual void vslot0c();
    virtual void vslot0d();
    virtual void vslot0e();
    virtual void vslot0f();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot1a();
    virtual void vslot1b();
    virtual void vslot1c();
    virtual void vslot1d();
    virtual void vslot1e();
    virtual void vslot1f();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot2a();
    virtual void vslot2b();
    virtual void vslot2c();
    virtual void vslot2d();
    virtual void FUN_vtb8(void*);
    FUN_00c37ec0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
};
struct BSMultiBound : NiMemObject
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    BSMultiBound();
    void FUN_004addc0(void*);
};
struct FUN_00c46970 : NiMemObject
{
    virtual void vslot00();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot0a();
    virtual void vslot0b();
    virtual void vslot0c();
    virtual void vslot0d();
    virtual void vslot0e();
    virtual void vslot0f();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot1a();
    virtual void vslot1b();
    virtual void vslot1c();
    virtual void vslot1d();
    virtual void vslot1e();
    virtual void vslot1f();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot2a();
    virtual void vslot2b();
    virtual void vslot2c();
    virtual void vslot2d();
    virtual void vslot2e();
    virtual void vslot2f();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35();
    virtual void vslot36();
    virtual void FUN_vtdc(void*, bool);
    FUN_00c46970();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
};

// @fnv 0x0049e410
void __cdecl CreateAutoWaterNode(ParamObj* a0)
{
    AutoMemHelper aex(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSAutoWater.cpp", 717);
    void* s;
    {
        void* i;
        bool pForm;
        FUN_00416870_t ptB;
        {
            NodeObj* nodeX;
            if (0 != (*reinterpret_cast<::Mgr * *>(&::DAT_011c57b0)))
            {
                ptB.FUN_00416870((*(::BufObj *)(reinterpret_cast<::S00546fb0_Cell *>((a0))->FUN_00546fb0())).FUN_00535b30()->x, (*(::BufObj *)(reinterpret_cast<::S00546fb0_Cell *>((a0))->FUN_00546fb0())).FUN_00535b30()->y,
                                 reinterpret_cast<::FUN_005471e0_shell *>((a0))->FUN_005471e0());
                pForm = false;
                s = ((void *)(::FUN_00559450((int *)((*reinterpret_cast<::Mgr * *>(&::DAT_011c57b0))))));
                i = 0;
                while (0 != s)
                {
                    i = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(((*reinterpret_cast<::Mgr * *>(&::DAT_011c57b0))))->DereferenceIfNotNull((int **)(s))));
                    if (!!s)
                    {
                        nodeX = *(NodeObj**)((void *)(reinterpret_cast<::FUN_006317a0_struct *>(((*reinterpret_cast<::Mgr * *>(&::DAT_011c57b0))))->AddEight((int)(s))));
                        if (((::AVObj *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((nodeX))->FUN_0056c7f0())) != 0 && ((::AVObj *)(::fnv_004a8a90::FUN_004a8a90((char *)(nodeX)))) != 0)
                        {
                            {
                                FUN_00416870_t n;
                                {
                                    FUN_00416870_t pt44;
                                    {
                                        float minZ;
                                        {
                                            float maxY;
                                            {
                                                BSMultiBound* p6c;
                                                {
                                                    AVObj* bufA;
                                                    {
                                                        UpdData res;
                                                        {
                                                            FUN_00416870_t* verts;
                                                            {
                                                                float val;
                                                                {
                                                                    FUN_0049ec80* minY;
                                                                    {
                                                                        BSFadeNode* p80;
                                                                        {
                                                                            FUN_00c46970* oldNode2;
                                                                            {
                                                                                float minX;
                                                                                {
                                                                                    FUN_00c37ec0* p7c;
                                                                                    {
                                                                                        FUN_00b6abb0* geom;
                                                                                        {
                                                                                            FUN_0055a2f0* p84;
                                                                                            {
                                                                                                float p50;
                                                                                                {
                                                                                                    float n7c;
                                                                                                    {
                                                                                                        int b;
                                                                                                        {
                                                                                                            FUN_00416870_t
                                                                                                                oldNode;
                                                                                                            ::AssignFixedString((char *)(((::AVObj *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((nodeX))->FUN_0056c7f0()))), 
                                                                                                                    (int)&(const ::NiFixedString &)(NiFixedString(
                                                                                                                        "AutoWaterNode")), {});
                                                                                                            ::AssignFixedString((char *)(((::AVObj *)(::fnv_004a8a90::FUN_004a8a90((char *)(nodeX))))), 
                                                                                                                    (int)&(const ::NiFixedString &)(NiFixedString(
                                                                                                                        "AutoWater")), {});
                                                                                                            p84 =
                                                                                                                new FUN_0055a2f0;
                                                                                                            geom =
                                                                                                                new FUN_00b6abb0;
                                                                                                            reinterpret_cast<::FUN_00439410_cls *>((((::AVObj *)(::fnv_004a8a90::FUN_004a8a90((char *)(nodeX))))))->FUN_00439410(
                                                                                                                    (::ArgObject *)(geom));
                                                                                                            ::BSShaderManager::UpdateObjectTypeRecurse(
                                                                                                                (::NiAVObject *)(void *)(((::AVObj *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((nodeX))->FUN_0056c7f0()))),
                                                                                                                0, 0);
                                                                                                            minY =
                                                                                                                new FUN_0049ec80;
                                                                                                            reinterpret_cast<::fnv_0049ee30::NiObjectNET *>((minY))->FUN_0049ee30(
                                                                                                                3);
                                                                                                            reinterpret_cast<::FUN_00439410_cls *>((((::AVObj *)(::fnv_004a8a90::FUN_004a8a90((char *)(nodeX))))))->FUN_00439410(
                                                                                                                    (::ArgObject *)(minY));
                                                                                                            reinterpret_cast<::Fn575690 *>((p84))->FUN_00575690(
                                                                                                                ((void *)(reinterpret_cast<::FUN_00580130_shell *>((((::WaterForm *)(reinterpret_cast<::FUN_00547770_shell *>((a0))->FUN_00547770()))))->FUN_00580130())));
                                                                                                            p80 =
                                                                                                                new BSFadeNode;
                                                                                                            reinterpret_cast<::FUN_0049ee60_shell *>((p80))->FUN_0049ee60(
                                                                                                                true);
                                                                                                            p84->FUN_vt1cc(
                                                                                                                p80,
                                                                                                                true);
                                                                                                            reinterpret_cast<::FUN_00440460_S *>((p80))->FUN_00440460(
                                                                                                                (const ::V3 *)&(ptB));
                                                                                                            ((FUN_0049eea0_shell*)
                                                                                                                 p84)
                                                                                                                ->FUN_0049eea0(
                                                                                                                    *(NiPoint3*)&ptB);
                                                                                                            p7c =
                                                                                                                new FUN_00c37ec0;
                                                                                                            val = 0.0f;
                                                                                                            maxY = 0.0f;
                                                                                                            n7c = 0.0f;
                                                                                                            minX = 0.0f;
                                                                                                            p50 = 0.0f;
                                                                                                            minZ = 0.0f;
                                                                                                            bufA =
                                                                                                                ((::AVObj *)(::fnv_004a8a90::FUN_004a8a90((char *)(nodeX))));
                                                                                                            verts =
                                                                                                                (FUN_00416870_t*)((int)(reinterpret_cast<::FUN_0049ec60 *>((bufA))->GetNext()));
                                                                                                            for (
                                                                                                                b = 0;
                                                                                                                b <
                                                                                                                (int)reinterpret_cast<::FUN_00456650_shell *>((void *)(bufA))->FUN_00456650();
                                                                                                                b++)
                                                                                                            {
                                                                                                                oldNode = verts
                                                                                                                    [b];
                                                                                                                if (0 <
                                                                                                                    b)
                                                                                                                {
                                                                                                                    val = FUN_0040ebd0(
                                                                                                                        val,
                                                                                                                        oldNode
                                                                                                                            .x);
                                                                                                                    maxY = FUN_0040ebd0(
                                                                                                                        maxY,
                                                                                                                        oldNode
                                                                                                                            .y);
                                                                                                                    n7c = FUN_0040ebd0(
                                                                                                                        n7c,
                                                                                                                        oldNode
                                                                                                                            .z);
                                                                                                                    minX = FUN_00404010(
                                                                                                                        minX,
                                                                                                                        oldNode
                                                                                                                            .x);
                                                                                                                    p50 = FUN_00404010(
                                                                                                                        p50,
                                                                                                                        oldNode
                                                                                                                            .y);
                                                                                                                    minZ = FUN_00404010(
                                                                                                                        minZ,
                                                                                                                        oldNode
                                                                                                                            .z);
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                    minX =
                                                                                                                        oldNode
                                                                                                                            .x;
                                                                                                                    val =
                                                                                                                        minX;
                                                                                                                    p50 =
                                                                                                                        oldNode
                                                                                                                            .y;
                                                                                                                    maxY =
                                                                                                                        p50;
                                                                                                                    minZ =
                                                                                                                        oldNode
                                                                                                                            .z;
                                                                                                                    n7c =
                                                                                                                        minZ;
                                                                                                                }
                                                                                                            }
                                                                                                            pt44.FUN_00416870(
                                                                                                                (float)std::abs((
                                                                                                                    float)((minX -
                                                                                                                            val) /
                                                                                                                           2.0)),
                                                                                                                (float)std::abs((
                                                                                                                    float)((p50 -
                                                                                                                            maxY) /
                                                                                                                           2.0)),
                                                                                                                (float)std::abs((
                                                                                                                    float)((minZ -
                                                                                                                            n7c) /
                                                                                                                           2.0)));
                                                                                                            n.FUN_00416870(
                                                                                                                minX -
                                                                                                                    pt44.x,
                                                                                                                p50 -
                                                                                                                    pt44.y,
                                                                                                                minZ -
                                                                                                                    pt44.z);
                                                                                                            reinterpret_cast<::FUN_0063c8a0_shell *>(&(n))->FUN_0063c8a0(
                                                                                                                &ptB);
                                                                                                            p7c->FUN_vtb8(
                                                                                                                &n);
                                                                                                            reinterpret_cast<::FUN_00439680_class *>((p7c))->FUN_00439680(
                                                                                                                (const ::NiPoint3 &)(pt44));
                                                                                                            p6c =
                                                                                                                new BSMultiBound;
                                                                                                            p6c->FUN_004addc0(
                                                                                                                p7c);
                                                                                                            oldNode2 =
                                                                                                                new FUN_00c46970;
                                                                                                            reinterpret_cast<::BSFaceGenNiNode *>((oldNode2))->SetAnimationData(
                                                                                                                    (::BSFaceGenAnimationData *)(p6c));
                                                                                                            p80->FUN_vtdc(
                                                                                                                oldNode2,
                                                                                                                true);
                                                                                                            oldNode2->FUN_vtdc(
                                                                                                                ((::AVObj *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((nodeX))->FUN_0056c7f0())),
                                                                                                                true);
                                                                                                            new ((void *)&(res)) ::NiUpdateData(
                                                                                                                0.0f,
                                                                                                                false,
                                                                                                                false);
                                                                                                            reinterpret_cast<::FUN_00a59c60_cls *>((p80))->FUN_00a59c60(
                                                                                                                (int)(&res));
                                                                                                            reinterpret_cast<::CellView *>((a0))->FUN_00548230(
                                                                                                                (::RefView *)(p84),
                                                                                                                false);
                                                                                                            reinterpret_cast<::TESForm *>((p84))->NotifySaveLoadGameOfFormChange();
                                                                                                            if (*(*reinterpret_cast<::SettingObj *>(&::g_011cc5a8))
                                                                                                                        .FUN_00408d60() !=
                                                                                                                    0 &&
                                                                                                                !pForm)
                                                                                                            {
                                                                                                                reinterpret_cast<::WaterRef *>((p84))->FUN_0056c8f0();
                                                                                                                pForm =
                                                                                                                    true;
                                                                                                            }
                                                                                                            delete nodeX;
                                                                                                            nodeX = 0;
                                                                                                            (*reinterpret_cast<::Mgr * *>(&::DAT_011c57b0))
                                                                                                                ->FUN_0049f590(
                                                                                                                    &s);
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    s = i;
                }
            }
        }
    }
}


struct S006b9a10_Pt
{
    float x, y, z;
    S006b9a10_Pt* FUN_00439e90(S006b9a10_Pt& out, S006b9a10_Pt* src) const;
};

float __cdecl FUN_00408840(float v);
S006b9a10_Pt* __cdecl FUN_004a3760(S006b9a10_Pt& tmp, float t, const S006b9a10_Pt& v1);

__declspec(noinline) S006b9a10_Pt* __cdecl FUN_004a3760(S006b9a10_Pt& tmp, float t, const S006b9a10_Pt& v1)
{
    return &tmp;
}

__declspec(noinline) S006b9a10_Pt* S006b9a10_Pt::FUN_00439e90(S006b9a10_Pt& out, S006b9a10_Pt* src) const
{
    return src;
}

// Computes the intersection of the line through p0 and p1 with the plane defined by p2 and p3, writing the result to out.
// @fnv 0x006b9a10
int __cdecl FUN_006b9a10(const S006b9a10_Pt& apStart, const S006b9a10_Pt& apEnd, const S006b9a10_Pt& apPlanePoint,
                         const S006b9a10_Pt& apPlaneNormal, S006b9a10_Pt& out)
{
    float f3 = ::DAT_0106c288;
    S006b9a10_Pt v1;
    S006b9a10_Pt v6;
    float f2;
    float f28;
    float f6;
    S006b9a10_Pt tmp5;
    S006b9a10_Pt v7;

    reinterpret_cast<::FUN_00439ef0_class *>((void *)&(apEnd))->FUN_00439ef0((::NiPoint3 *)&(v1), (const ::NiPoint3 &)(apStart));
    reinterpret_cast<::FUN_00439ef0_class *>((void *)&(apStart))->FUN_00439ef0((::NiPoint3 *)&(v6), (const ::NiPoint3 &)(apPlanePoint));
    f28 = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(apPlaneNormal))->DotProduct((void *)&(v1));
    f2 = -reinterpret_cast<::FUN_004b6190_shell *>((void *)&(apPlaneNormal))->DotProduct((void *)&(v6));
    if (f3 > FUN_00408840(f28))
    {
        if (f2 == ::_DAT_01012060)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    f6 = f2 / f28;
    if (f6 < ::_DAT_01012060 || f6 > ::g_01012070)
    {
        return 0;
    }
    out = *((::S006b9a10_Pt *)(reinterpret_cast<::Point3Offset *>((void *)&(apStart))->ProjectileLaunched((::NiPoint3 *)&(v7), (::NiPoint3 *)(::S006b9a10_Pt *)(((::S006b9a10_Pt *)(::NiPosData::ComputePositionAtTime((::NiPoint3 *)&(tmp5), f6, (const ::NiPoint3 *)&(v1))))))));
    return 1;
}

struct MobileObjectCellAccess
{
};
struct NiTPointerListBase
{
    void FUN_004ed900();
};

// Builds auto-water boundary geometry and creates the auto-water node for the given mesh input.
// @fnv 0x0049c860
void FUN_0049c860(MeshInput* apMeshInput)
{
    AutoMemHelper context(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSAutoWater.cpp", 83);
    if (!apMeshInput || !reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)(reinterpret_cast<MobileObjectCellAccess*>(apMeshInput)))->FUN_004518e0())
        return;
    if (DAT_011c57ac)
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((DAT_011c57ac))->Clear(true);
    if ((*reinterpret_cast<::Mgr * *>(&::DAT_011c57b0)))
        reinterpret_cast<NiTPointerListBase*>((*reinterpret_cast<::Mgr * *>(&::DAT_011c57b0)))->FUN_004ed900();
    BuildMeshBoundaryGeometry(apMeshInput);
    ::BuildWaterSurfaces((::CellView *)(apMeshInput));
    CreateAutoWaterNode(reinterpret_cast<ParamObj*>(apMeshInput));
}
