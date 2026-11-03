
// mapmenu_ctx_variant.cpp: context variant of src/fallout/interface/menus/mapmenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <new>
#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DialogMenuAudioCalls.h"
#include "fnv/decl/F7E0Picker.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00569060_shell.h"
#include "fnv/decl/FUN_00586210_shell.h"
#include "fnv/decl/FUN_00586440_shell.h"
#include "fnv/decl/FUN_00588e40_shell.h"
#include "fnv/decl/FUN_0059e400_shell.h"
#include "fnv/decl/FUN_005e8d40_shell.h"
#include "fnv/decl/FUN_005e9300_Host.h"
#include "fnv/decl/FUN_0061f170_cls.h"
#include "fnv/decl/FUN_007700d0_cls.h"
#include "fnv/decl/FUN_00798400_shell.h"
#include "fnv/decl/FUN_00798420_shell.h"
#include "fnv/decl/FUN_00798ad0_shell.h"
#include "fnv/decl/FUN_00799dc0_class.h"
#include "fnv/decl/FUN_0079c090_shell.h"
#include "fnv/decl/FUN_0079c380_shell.h"
#include "fnv/decl/FUN_0079c450_shell.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_009c8640_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a013d0_shell.h"
#include "fnv/decl/FUN_00a01440_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FlagS.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MyHack.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/Obj_009529d0.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S_00a04150_Class.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SoundPlayback.h"
#include "fnv/decl/SoundWrapper.h"
#include "fnv/decl/StringHolder.h"
#include "fnv/decl/TESObjectCELL_Ext.h"
#include "fnv/decl/TileFloatList.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Unk00796f90.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00578870__FUN_00578870_Class.h"
#include "fnv/decl/fnv_007993d0__NoteMenu.h"
#include "fnv/decl/fnv_0079b460__FUN_0079b460_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0093d660__TravelObject.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a07dc0__FUN_00a07dc0_shell.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_0079a000.h"
#include "fnv/symbols_0079b000.h"
#include "fnv/symbols_0079c000.h"
#include "fnv/symbols_0079f000.h"
#include "fnv/symbols_007fa000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a1c000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "mapmenu_decls.h"
// @fnv 0x007a1930
template <> void ListBox<TESQuest*>::ClearSelection(bool notify)
{
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950((unsigned int)(0), notify);
}

struct TESFullName
{
};

class PathingLocation
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    PathingLocation();
    PathingLocation(const NiPoint3*, TESWorldSpace*);
    ~PathingLocation();
    PathingLocation& operator=(const PathingLocation&);
public:
    bool HasPathingLocation();
};

class TESWorldSpaceCustom : public TESWorldSpace
{
  public:
    int unk10;
    int unk14;
    TESFullName fullName;

};

class TESDataHandler
{
  public:
};


extern "C" int __cdecl _mbsnicmp(const char*, const char*, size_t);

// @fnv 0x007984d0
TESWorldSpace* MapMenu::FUN_007984d0(NiPoint3 pt)
{
    TESWorldSpace* result5 = 0;
    float maxDist = 3.402823466e+38F;
    for (BSSimpleList<TESWorldSpace*>* node2 = ((::BSSimpleList< ::TESWorldSpace *> *)(::FUN_00460140((int)((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))); node2 && ((::TESWorldSpace *)(new ((void *)(node2)) ::Vec3()));
         node2 = ((::BSSimpleList< ::TESWorldSpace *> *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070())))
    {
        TESWorldSpaceCustom* ws4 = (TESWorldSpaceCustom*)((::TESWorldSpace *)(new ((void *)(node2)) ::Vec3()));
        const char* name = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(ws4->fullName))->FUN_00408da0()));
        NiPoint3 ptCopy3 = pt;
        PathingLocation loc4;
        if (!name || !*name || ::FUN_004b75a0(name, "test") == name || reinterpret_cast<::FUN_00586210_shell *>((ws4))->HasFlag2())
        {
            continue;
        }
        reinterpret_cast<::FUN_00588e40_shell *>((ws4))->TransformWorldPoint((::Pt3 *)&(ptCopy3), true);
        loc4 = PathingLocation(&ptCopy3, ws4);
        if (reinterpret_cast<::PathingLocation *>(&(loc4))->HasPathingLocation() && this->m_pCurrentWorldspace && ws4)
        {
            if (::FUN_0044a670(reinterpret_cast<::FUN_00586440_shell *>((((TESWorldSpaceCustom*)this->m_pCurrentWorldspace)))->FUN_00586440()) < 31 ||
                ::FUN_0044a670(reinterpret_cast<::FUN_00586440_shell *>((ws4))->FUN_00586440()) < 31)
            {
                continue;
            }
            if (_mbsnicmp(reinterpret_cast<::FUN_00586440_shell *>((((TESWorldSpaceCustom*)this->m_pCurrentWorldspace)))->FUN_00586440() + 29,
                          reinterpret_cast<::FUN_00586440_shell *>((ws4))->FUN_00586440() + 29, 3) == 0)
            {
                result5 = ws4;
                break;
            }
        }
    }
    if (!result5)
    {
        result5 = ((::TESWorldSpace *)(new ((void *)(((::BSSimpleList< ::TESWorldSpace *> *)(::FUN_00460140((int)((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))))) ::Vec3()));
    }
    return result5;
}
