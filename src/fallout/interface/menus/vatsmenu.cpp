// fallout/interface/menus/vatsmenu.cpp: VATSMenuX, VATSMenu, Vec2Tmp, StandIn and more (58 functions)

#include <cstdint>
#include "fnv/result_slot.h"
#include "fnv/simple_list_node_view.h"
#include "fnv/inventory_entry_fields.h"
#include <new>
#include <cstdio>
#include <cstdlib>
#include "fnv/decl/AGOwner.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AimPlayer.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/AudioClass_ae5680.h"
#include "fnv/decl/BGSDefaultObjectManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/CalcActor.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/FNVSearchOwner.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0044ac20_class.h"
#include "fnv/decl/FUN_00452df0_class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0046e8c0_class.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_00474a80_Class.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3c20.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_004e7560_shell.h"
#include "fnv/decl/FUN_004fe160_cls.h"
#include "fnv/decl/FUN_00524b40_class.h"
#include "fnv/decl/FUN_00524b60_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00576070_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595d10_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_005d8710_shell.h"
#include "fnv/decl/FUN_005e50f0_Obj.h"
#include "fnv/decl/FUN_005e5130_Class.h"
#include "fnv/decl/FUN_005e5190_Class.h"
#include "fnv/decl/FUN_00646020_shell.h"
#include "fnv/decl/FUN_0070ec70_class.h"
#include "fnv/decl/FUN_007242c0_shell.h"
#include "fnv/decl/FUN_00726090_cls.h"
#include "fnv/decl/FUN_0073ac90_shell.h"
#include "fnv/decl/FUN_0073b020_shell.h"
#include "fnv/decl/FUN_00800650_Class.h"
#include "fnv/decl/FUN_00800700_Class.h"
#include "fnv/decl/FUN_008009d0_cls.h"
#include "fnv/decl/FUN_00800a00_cls.h"
#include "fnv/decl/FUN_00800a90.h"
#include "fnv/decl/FUN_00800d10_class.h"
#include "fnv/decl/FUN_00800e50_Class.h"
#include "fnv/decl/FUN_00821640_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008d85e0_Class.h"
#include "fnv/decl/FUN_008d9140_Class.h"
#include "fnv/decl/FUN_00967090_t.h"
#include "fnv/decl/FUN_009ca500_shell.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a23390_t.h"
#include "fnv/decl/FUN_00a24180_shell.h"
#include "fnv/decl/FUN_00a24f10_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/GlobalObject_008c71b0.h"
#include "fnv/decl/HealthReferenceEntry.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MessageHUD.h"
#include "fnv/decl/MyList.h"
#include "fnv/decl/NiPoint3Interpolator.h"
#include "fnv/decl/P03Value.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/RemoveView.h"
#include "fnv/decl/RockItAmmoCountDetail__PlayerView.h"
#include "fnv/decl/S00a70ba0_Cam.h"
#include "fnv/decl/S50.h"
#include "fnv/decl/ScreenCamera.h"
#include "fnv/decl/SightActor.h"
#include "fnv/decl/SoundListView.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESHealthForm.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/UAMActor.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/VatsList9c9.h"
#include "fnv/decl/WORLD_SHELL.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_0050ebf0__FUN_0050ebf0_shell.h"
#include "fnv/decl/fnv_00522be0__FUN_00522be0_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_0070bc20__FUN_0070bc20_shell.h"
#include "fnv/decl/fnv_00726530__FUN_00726530_t.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008808a0__ActorProxy.h"
#include "fnv/decl/fnv_008b8e90__FUN_008b8e90_shell.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_008d3550__FaceActor.h"
#include "fnv/decl/fnv_00964260__SelActor.h"
#include "fnv/decl/fnv_009c9ae0__VATS9c9.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a07c60__FUN_00a07c60_shell.h"
#include "fnv/decl/fnv_00a07dc0__FUN_00a07dc0_shell.h"
#include "fnv/decl/fnv_00a07f30__FUN_00a07f30_shell.h"
#include "fnv/decl/fnv_00a07fc0__FUN_00a07fc0_shell.h"
#include "fnv/decl/fnv_00a09200__Value_00a09200.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/s54da20__Owner.h"
#include "fnv/decl/sa040a0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00475000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_004f6000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_0066d000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006d5000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_00770000.h"
#include "fnv/symbols_00772000.h"
#include "fnv/symbols_00774000.h"
#include "fnv/symbols_00779000.h"
#include "fnv/symbols_007eb000.h"
#include "fnv/symbols_007ec000.h"
#include "fnv/symbols_007ee000.h"
#include "fnv/symbols_007f0000.h"
#include "fnv/symbols_007f3000.h"
#include "fnv/symbols_007f4000.h"
#include "fnv/symbols_007f6000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_00952000.h"
#include "fnv/symbols_009a6000.h"
#include "fnv/symbols_009b4000.h"
#include "fnv/symbols_009b5000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_01035000.h"
#include "fnv/symbols_0106b000.h"
#include "fnv/symbols_0106f000.h"
#include "fnv/symbols_01071000.h"
#include "fnv/symbols_01077000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011a5000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "vatsmenu_decls.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/CameraWindowRay.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/fnv_004a3f90__T_.h"
#include "fnv/symbols_004a3000.h"
// Returns the difference between the result of the called function and the tile's float value at numFiltered.
// @fnv 0x00726660
unsigned int VATSMenu::Create()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)tile->GetFloat(numFiltered);
}

struct ItemListElement;
struct ItemList
{
    ItemListElement** FUN_006815c0();
    void FUN_0063f7b0();
};
struct ItemListContainer
{
    char pad[0x4];
    int unk04;
    ItemList items;
    ~ItemListContainer();
    char pad9[0x17];
    int unk20;
};
struct TargetList
{
    ItemListContainer** FUN_006815c0();
    void FUN_0063f7b0();
};
struct GlobalObject2_0096a2d0
{
    int x;
};

// Deletes every item in each target's item list, then deletes each target, until the global target list is empty.
// @fnv 0x007f6920
void FUN_007f6920()
{
    ItemListElement* pitem;
    ItemListContainer* ptarg;
    while (*((TargetList*)&::g_011db150)->FUN_006815c0())
    {
        ptarg = *((TargetList*)&::g_011db150)->FUN_006815c0();
        while (*ptarg->items.FUN_006815c0())
        {
            pitem = *ptarg->items.FUN_006815c0();
            delete pitem;
            ptarg->items.FUN_0063f7b0();
        }
        delete ptarg;
        ((TargetList*)&::g_011db150)->FUN_0063f7b0();
    }
}

struct FUN_007ebd30_This
{
    char pad[0x374];
    float fValue;
    float FUN_007ebd30();
};

// @fnv 0x007ebd30
float FUN_007ebd30_This::FUN_007ebd30()
{
    return fValue;
}


// @fnv 0x007f3bd0
void __cdecl FUN_007f3bd0(int aiValue)
{
    if (DAT_011db0d4)
    {
        *(char*)(*(intptr_t*)(&DAT_011db0d4) + 0xf8) = (char)aiValue;
    }
}

namespace fnv_007f5280 {

// Returns a pointer to the object at offset 0x11C of DAT_011db0d4 if it is non-null and its byte at 0x118 is set, otherwise null.
// @fnv 0x007f5280
void* __cdecl FUN_007f5280()
{
    void* v0;
    if ((*reinterpret_cast<int * *>(&::DAT_011db0d4)) != 0 && *(reinterpret_cast<unsigned char*>((*reinterpret_cast<int * *>(&::DAT_011db0d4))) + 0x118) != 0)
    {
        v0 = reinterpret_cast<int*>(reinterpret_cast<char*>((*reinterpret_cast<int * *>(&::DAT_011db0d4))) + 0x11C);
    }
    else
    {
        v0 = 0;
    }
    return v0;
}
}  // namespace fnv_007f5280

struct ArrSI
{
};
struct Caller007efa10
{
    void UpdateQueueEntry(int a1, int a2, int a3);
};
struct FUN_007ef710_This
{
    char _pad[0xF8];
    bool m_bFirstFlag;
    bool HandleKey(int aiKey);
};
// @fnv 0x007ef710
bool FUN_007ef710_This::HandleKey(int aiKey)
{
    if (aiKey == 0x42 || aiKey == 0x62)
    {
        if (((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->GetName())) == 2 && m_bFirstFlag)
            ((Caller007efa10*)this)->UpdateQueueEntry(0, 0, 0);
        return true;
    }
    return false;
}

struct Tile;
struct FUN_0070ec70_This
{
};
struct FUN_007ef760_Owner
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(int, int);
    void FUN_007ef760(int aiID, Tile* apTarget);
};
// Calls FUN_0070ec70 on the object from FUN_004b7210 and invokes vf3 with 2 if that value divided by -120 equals 1, otherwise 3.
// @fnv 0x007ef760
void FUN_007ef760_Owner::FUN_007ef760(int aiID, Tile* apTarget)
{
    if (((int)(reinterpret_cast<::FUN_0070ec70_class *>((((FUN_0070ec70_This*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0070ec70())) / -120 == 1)
        vf3(2, 0);
    else
        vf3(3, 0);
}

struct Vec2Tmp
{
    float x;
    float y;
    Vec2Tmp DivideBy(float) const;
};
// Returns a copy of this vector with x and y divided by scale.
// @fnv 0x007f2890
Vec2Tmp Vec2Tmp::DivideBy(float scale) const
{
    Vec2Tmp result = *this;
    result.x /= scale;
    result.y /= scale;
    return result;
}

struct TESObjectREFR
{
public:
    float GetBoundingRadius();
};
template <> struct BSSimpleList<ItemListContainer*>
{
    bool FUN_008256d0();
    ItemListContainer** FUN_006815c0();
};
struct StandIn
{
    BSSimpleList<ItemListContainer*>* FindListEntryForTarget(TESObjectREFR* apTarget);
};
struct Tile;
struct Menu
{
};
void __cdecl ShutdownVats();
// @fnv 0x007f4830
Tile* FUN_007f4830(Tile* apParent, char const* axName)
{
    Tile* ptile;
    if (DAT_011db0d4 == 0)
        return 0;
    ptile = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((Menu*)DAT_011db0d4)))->FUN_00a1ddb0(apParent, (char *)(axName), 0);
    if (ptile)
        return ptile;
    else
    {
        ::FUN_005b5e40(
            );
        ::fnv_007037e0::FUN_007037e0();
        ShutdownVats();
    }
    return 0;
}

struct Tile;
void __cdecl ShutdownVats();
// @fnv 0x007f4890
Tile* __cdecl FUN_007f4890(Tile* a1, char const* a2)
{
    Tile* result = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(a1), a2)));
    if (result != 0)
        return result;
    else
    {
        ::FUN_005b5e40(
            );
        ::fnv_007037e0::FUN_007037e0();
        ShutdownVats();
    }
    return 0;
}

struct AnimIdle
{
};
class GameTimerRecord
{
    char _d;
};
struct DAT_Pointee_7f4bb0
{
    char pad[0x10F];
    unsigned char flag;
    char pad2[4];
    int t;
};
// Returns true when DAT_011db0d4 is set, its flag is set, and GetSection() minus its t field exceeds 500.
// @fnv 0x007f4bb0
bool FUN_007f4bb0()
{
    if (DAT_011db0d4 == 0)
        return false;
    if (((DAT_Pointee_7f4bb0*)DAT_011db0d4)->flag)
    {
        if ((unsigned int)(((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((AnimIdle*)&::g_timeGlobal)))->FUN_00825c00())) - ((DAT_Pointee_7f4bb0*)DAT_011db0d4)->t) > 0x1F4)
            return true;
    }
    return false;
}

namespace fnv_007f4c00 {
struct AnimIdle
{
};
struct DAT_Obj
{
    char pad[0x110];
    unsigned char b;
    char pad2[3];
    int v;
};
// Returns true when DAT_011db0d4 is set, its byte flag is nonzero, and the section from g_timeGlobal minus its v field exceeds 0x1f4.
// @fnv 0x007f4c00
bool FUN_007f4c00()
{
    if (DAT_011db0d4 == 0)
        return false;
    if (((DAT_Obj*)DAT_011db0d4)->b && (unsigned int)(((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_007f4c00::AnimIdle *>(&::g_timeGlobal))))->FUN_00825c00())) - ((DAT_Obj*)DAT_011db0d4)->v) > 0x1f4)
        return true;
    return false;
}
}  // namespace fnv_007f4c00

struct Tile;
struct ListBox
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile* v5(int);
    Tile* FUN_007f6fb0();
};
// @fnv 0x007f6fb0
Tile* ListBox::FUN_007f6fb0()
{
    return v5(((int)(reinterpret_cast<::VATSMenu *>(this)->GetFilteredCount())) - 1);
}

struct FUN_007ebd10_This
{
    char pad[0x37c];
    float fValue;
    float FUN_007ebd10();
};

// @fnv 0x007ebd10
float FUN_007ebd10_This::FUN_007ebd10()
{
    return fValue;
}

struct FUN_007ef8b0_This
{
    char pad[0x10f];
    unsigned char flag;
    unsigned char pad2[4];
    int t;
    void FUN_007ef8b0(int aiID, Tile* apTarget);
};
// For IDs 2 and 3, if the corresponding flag is unset, stores the current AnimIdle section into t and sets that flag.
// @fnv 0x007ef8b0
void FUN_007ef8b0_This::FUN_007ef8b0(int aiID, Tile* apTarget)
{
    switch (aiID)
    {
    case 2:
        if (!flag)
        {
            t = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((AnimIdle*)&::g_timeGlobal)))->FUN_00825c00()));
            flag = 1;
        }
        break;
    case 3:
        if (!pad2[0])
        {
            t = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((AnimIdle*)&::g_timeGlobal)))->FUN_00825c00()));
            pad2[0] = 1;
        }
        break;
    }
}

struct FUN_007f4810_shell
{
    char pad[0x2b4];
    char byte_0x2b4;
    char GetByteAtOffset();
};

// @fnv 0x007f4810
char FUN_007f4810_shell::GetByteAtOffset()
{
    return byte_0x2b4;
}

struct FUN_007f5190_shell
{
    char pad[0x12c];
    unsigned int flags;
    bool IsFlag800Set() const;
};

// @fnv 0x007f5190
bool FUN_007f5190_shell::IsFlag800Set() const
{
    return (flags & 0x800) ? true : false;
}

struct SL
{
    SL();
};

struct FUN_007f6900_shell
{
    char pad[8];
    SL sl;
    FUN_007f6900_shell();
};

// @fnv 0x007f6900
FUN_007f6900_shell::FUN_007f6900_shell()
{}

struct GO
{
    void* p;
    GO& operator=(void*);
};
struct FUN_00800ed0_This
{
    char _pad[12];
    int cnt;
    int sel;
    struct Entry
    {
        int v;
        GO g;
    } arr[32];
    void FUN_00800ed0();
};
// Resets each of the cnt entries' value and pointer to zero, then sets cnt to 0 and sel to -1.
// @fnv 0x00800ed0
void FUN_00800ed0_This::FUN_00800ed0()
{
    for (int i = 0; i < cnt; ++i)
    {
        arr[i].v = 0;
        arr[i].g = 0;
    }
    cnt = 0;
    sel = -1;
}

struct OSGlobals
{
};
struct InputManager
{
};
struct HotkeyWheelDisplay
{
public:
    int SetHotkeyItem(int, int);
};

// @fnv 0x007eeb50
bool __cdecl FUN_007eeb50(int aiKey, bool abHeld, int aiEnabled)
{
    ::fnv_004b7210::FUN_004b7210();
    if (!::FUN_004b71d0())
    {
        void* pInput = ((void *)(reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720()));
        {
            int iState = !abHeld;
            switch (aiKey)
            {
            case 1:
                return reinterpret_cast<::ButtonDevice *>((((InputManager*)pInput)))->FUN_00a23a50(0, iState) && aiEnabled;
            case 2:
                return reinterpret_cast<::FUN_00a24180_shell *>((((HotkeyWheelDisplay*)pInput)))->FUN_00a24180(0x13, iState) || DAT_011db0b2;
            case 3:
                return reinterpret_cast<::FUN_00a24180_shell *>((((HotkeyWheelDisplay*)pInput)))->FUN_00a24180(0x21, iState) || DAT_011db0b3;
            }
        }
        return false;
    }
    int iButton = 0xe;
    switch (aiKey)
    {
    case 2:
        iButton = 0xc;
        break;
    case 3:
        iButton = 0xb;
        break;
    }
    if (abHeld)
        return !::fnv_00717a40::FUN_00717a40(iButton, 1);
    else
        return ::fnv_00717a40::FUN_00717a40(iButton, 1) == 2;
}

struct Actor;
struct FUN_007f3cf0_This : StandIn
{
    char pad[0x100 - sizeof(Menu)];
    TESObjectREFR* m_pTargetChance;
    BSSimpleList<ItemListContainer*>* FindEntryForRef();
};
struct StartMenu
{
    char const* GetMenuTitle();
};

extern StartMenu* DAT_01183aa0[];

// @fnv 0x007f0360
char const* FUN_007f0360(int aiIndex)
{
    return DAT_01183aa0[aiIndex]->GetMenuTitle();
}

struct NiPoint3
{
    float x;
    float y;
    float z;

public:
    bool FUN_004390c0(const ::NiPoint3 &);
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};

struct NiAVObject
{
    NiPoint3 GetWorldTranslation();
};

class BSFaceGenAnimationData;
struct BSFaceGenNiNode : public NiAVObject
{
    NiAVObject* GetAnimationData();
public:
    void SetAnimationData(::BSFaceGenAnimationData *);
    void SetApplyRotToParent(bool);
};


struct FUN_005df510_shell
{
    void FUN_005df510(unsigned int, float*);
};

struct FUN_007f51b0_shell
{
    void FUN_007f51b0(FUN_005df510_shell*);
};

struct Pt
{
    float x;
    float y;
    float z;
};

struct P3 : Pt
{
    P3 operator-(P3 const&) const;
};

struct TESObjectWEAP
{
    int GetWeaponType();
public:
    float FUN_00709430(bool);
};

struct A69C0Weapon
{
};


struct Setting_S
{
};

struct GameSettingCollection
{
};

template <class T> struct SettingT : Setting_S
{
};


struct G2
{
    void AddHead(int*);
};


struct ActH2
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();

    virtual P3* FUN_007f4f30_position();

    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();

    // Always returns true.
// @fnv 0x007f4f30
    virtual bool FUN_007f4f30_check()
    {
        return true;
    }

};

struct Sky : public ActH2
{
};

struct FUN_00452370_shell : public Sky
{
    bool FUN_00452370() const;
};

class TESActorBase;
struct Actor : public ActH2
{
public:
    ::TESActorBase *GetActorBase();
};



bool __cdecl FUN_007f4f30(FUN_00452370_shell* apTarget)
{
    float fDistance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::Pt &)((*(*reinterpret_cast<::Actor * *>(&::_g_thePlayer))->FUN_007f4f30_position() - *apTarget->FUN_007f4f30_position())))->ComputeMagnitude();

    if (((void *)(reinterpret_cast<::FUN_008a1710_shell *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_008a1710())) &&
        ::FUN_006450c0((::TESObjectWEAP *)(::A69C0Weapon *)(reinterpret_cast<A69C0Weapon*>(((void *)(reinterpret_cast<::FUN_008a1710_shell *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_008a1710()))))) &&
        fDistance > *((float *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting546)))))
    {
        return false;
    }

    if (apTarget->FUN_00452370() && apTarget->FUN_007f4f30_check())
    {
        {
            FUN_00452370_shell* target = apTarget;

            if (((::TESObjectWEAP *)(reinterpret_cast<::FUN_00476c90_Class *>((target))->FUN_00476c90())) &&
                (((::TESObjectWEAP *)(reinterpret_cast<::FUN_00476c90_Class *>((target))->FUN_00476c90()))->GetWeaponType() == 11 || ((::TESObjectWEAP *)(reinterpret_cast<::FUN_00476c90_Class *>((target))->FUN_00476c90()))->GetWeaponType() == 12))
            {
                return false;
            }

            if (FUN_00874480(reinterpret_cast<char*>(target)) != reinterpret_cast<std::intptr_t>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))
            {
                reinterpret_cast<G2*>(&::g_011db124)->AddHead(reinterpret_cast<int*>(&apTarget));
            }
        }
    }

    return false;
}

namespace fnv_007f5050 {
struct TESCreature
{
};

struct TESObjectWEAP
{
};

struct InventoryStackRecord : ArrSI
{
};

struct FUN_00646020_shell
{
};

struct TES
{
};

struct LogDateOwner
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual InventoryStackRecord* v82();
};


struct ActionPoints
{
    enum Action
    {
        Action_Invalid = 0
    };
};

struct Setting_S
{
};

struct GameSettingCollection
{
};

template <class T> struct SettingT : Setting_S
{
};


// Computes the number of shots per burst from the equipped weapon's ammo per shot, automatic flag and burst time settings, returning at least 1.
// @fnv 0x007f5050
unsigned char __cdecl GetBurstShotCount(ActionPoints::Action aeAction, bool abAllowLongBurst)
{
    int iNumAmmoPerShot;
    TESObjectWEAP* pweapon;
    float fburstTime;
    InventoryStackRecord* pweaponItem;
    unsigned char cshots;

    pweaponItem = static_cast<LogDateOwner*>(((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007f5050::TES * *>(&::_g_thePlayer))))->GetBaseTexture())))->v82();
    pweapon = reinterpret_cast<TESObjectWEAP*>(pweaponItem ? ((std::uintptr_t)(reinterpret_cast<::InventoryEntryFields *>((pweaponItem))->pObject)) : 0);
    iNumAmmoPerShot = pweapon ? reinterpret_cast<::FUN_00524b60_shell *>((pweapon))->GetByteAt102() : 0;

    cshots = 1;
    if (iNumAmmoPerShot > 0)
        cshots *= iNumAmmoPerShot;

    if (aeAction == 0 || (pweapon && !reinterpret_cast<::FUN_00524b40_class *>((pweapon))->FUN_00524b40()))
        return cshots;

    fburstTime = abAllowLongBurst && pweapon && reinterpret_cast<FUN_007f5190_shell*>(pweapon)->IsFlag800Set()
                     ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007f5050::SettingT< ::fnv_007f5050::GameSettingCollection> *>(&::originalRuntimeFloatSetting539))))))
                     : *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007f5050::SettingT< ::fnv_007f5050::GameSettingCollection> *>(&::originalRuntimeFloatSetting538))))));

    cshots = static_cast<unsigned char>(
        reinterpret_cast<::FUN_00821640_shell *>((reinterpret_cast<TESCreature*>(pweapon)))->FUN_00821640() * fburstTime *
        reinterpret_cast<::FUN_00646020_shell *>((reinterpret_cast<FUN_00646020_shell*>(pweapon)))->FUN_00646020(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((pweaponItem))->HasEffect(8)));

    if (!cshots)
        cshots = 1;

    return cshots;
}
}  // namespace fnv_007f5050

struct RaceX;
struct FormX;
struct AmmoListX;
struct DetectX;
struct WeaponX;

struct ElemX
{
};
struct RaceX
{
};
struct FormX
{
    WeaponX* FUN_0044ddc0();
};
struct AmmoListX
{
};
struct DetectX
{
    int iLevel;
    bool bDetected;
};

struct ActorValueOwnerX
{
    virtual void v000();
    virtual void v004();
    virtual int GetActorValue(int aeAV);
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual int GetBaseActorValue(int aeAV);
};
struct ActorBaseX
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual RaceX* GetRace();
};
struct ProcessX
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual FormX* GetEquippedWeapon();
    virtual AmmoListX* GetAmmoList();
};
struct ActorX
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual int IsAlive();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void* GetAnimation();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool IsDead(bool abArg);
    virtual bool IsCreature();
    char _pad04[0xa0];
    ActorValueOwnerX kAVOwner;
    void UpdateCamera(bool a1, bool a2);
};

struct ModListX
{
};
struct WeaponX
{
    char _pad00[0xa4];
    ModListX kMods;
    int GetWeaponType() const;
};

struct TileX;
struct TileChildrenX
{
};
struct TileX
{
    char _pad00[4];
    TileChildrenX kChildren;
};

template <class T> struct ListX
{
    T item;
    ListX* next;
    T& GetItem();
    bool IsEmpty();
    ListX* GetNext();
};

struct ChanceX
{
    char _pad00[0x20];
    int m_iActionValue;
    char _pad24[4];
    float fHitChance;
    char _pad2c;
    bool bCrippled;
    char _pad2e[2];
    intptr_t iHitCount;
};
struct TargetX
{
    char _pad00[8];
    ListX<ChanceX*> kLimbs;
};

struct CommandX
{
    int eAction;
    bool bFlag4;
    char _pad5[2];
    bool bFlag7;
    unsigned char ucShots;
    unsigned char ucExtra;
    char _padA[2];
    ActorX* pTarget;
    int m_iActionValue;
    char _pad14[0xc];
    float fAPCost;
    char _pad24[4];
    CommandX();
};

struct QueueX
{
    unsigned int GetSize();
};
struct VATSX
{
    void* targetsItem;
    void* targetsNext;
    unsigned int mode;
};

struct InputX
{
};
struct OSGlobalsX
{
};
struct InterfaceManagerX
{
};

struct EffectX
{
};
EffectX* xGetVATSEffect();

struct TimerX
{
};

struct SettingX
{
    const char* String();
    bool* Bool();
};

struct BSSoundHandleX
{
    unsigned int uiSoundID;
    bool m_bLooping;
    int eState;
    BSSoundHandleX();
    ~BSSoundHandleX();
    BSSoundHandleX& operator=(const BSSoundHandleX& arHandle);
};
struct AudioX
{
    BSSoundHandleX GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
};
struct AudioMgrX
{
};

struct UIMessageX
{
};

struct VATSMenuX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void HandleClick(int aiID, int aiArg);
    char _pad04[0x24];
    TileX* m_pTiles[32];
    char _padA8[0x38];
    float m_fOverrideActionPoints;
    float m_fValue1;
    float m_fValue2;
    float m_fValue3;
    float m_fValue4;
    float m_fValue5;
    bool m_bFirstFlag;
    bool m_bStateFlag1;
    bool m_bStateFlag2;
    bool m_bStateFlag3;
    float m_fHitChance;
    ChanceX* m_pTargetChance;
    bool m_bStateFlag4;
    char _pad105[3];
    ChanceX* m_pSelectedChance;
    bool m_bStateFlag5;
    bool m_bStateFlag9;
    bool m_bAdditionalStateFlag;
    bool m_bStateFlag10;
    bool m_bStateFlag6;
    char _pad111[3];
    unsigned int m_uiTargetCount;

    ListX<TargetX*>* FindListEntryForTarget(ActorX* apTarget);
    void UpdateLimbHighlight();
    void UpdateQueueEntry(CommandX* apCmd, bool abArg2, bool abArg3);
    float FUN_007f48e0();
    void UpdateHitChanceDisplay();
    void FUN_007f3070();
    bool FUN_007f28d0();
    ListX<ChanceX*>* FindEntryForRef();
    void UpdateLimbTiles();
    void Update();
};

extern bool xDAT_011a0b68;
extern int xDAT_011db180;

bool xFUN_00702450(int aiID);
void xFUN_00705780();
unsigned char xFUN_007f5050(int aiAction, int a2);

struct VATSMenu007ef830 : VATSMenu
{
    void FUN_007ef830(int aiID, int aiOther);
};

// @fnv 0x007ef830
void VATSMenu007ef830::FUN_007ef830(int aiID, int aiOther)
{
    ::fnv_004b7210::FUN_004b7210();
    if (::FUN_004b71d0())
    {
        return;
    }

    switch (aiID)
    {
    case 2:
    case 3:
    case 4:
    case 5:
    case 30:
    case 31:
        m_bAdditionalStateFlag = false;
        break;
    }
}

class C7F0500Ref
{
  public:
    virtual void vfunc000();
    virtual void vfunc001();
    virtual void vfunc002();
    virtual void vfunc003();
    virtual void vfunc004();
    virtual void vfunc005();
    virtual void vfunc006();
    virtual void vfunc007();
    virtual void vfunc008();
    virtual void vfunc009();
    virtual void vfunc00A();
    virtual void vfunc00B();
    virtual void vfunc00C();
    virtual void vfunc00D();
    virtual void vfunc00E();
    virtual void vfunc00F();
    virtual void vfunc010();
    virtual void vfunc011();
    virtual void vfunc012();
    virtual void vfunc013();
    virtual void vfunc014();
    virtual void vfunc015();
    virtual void vfunc016();
    virtual void vfunc017();
    virtual void vfunc018();
    virtual void vfunc019();
    virtual void vfunc01A();
    virtual void vfunc01B();
    virtual void vfunc01C();
    virtual void vfunc01D();
    virtual void vfunc01E();
    virtual void vfunc01F();
    virtual void vfunc020();
    virtual void vfunc021();
    virtual void vfunc022();
    virtual void vfunc023();
    virtual void vfunc024();
    virtual void vfunc025();
    virtual void vfunc026();
    virtual void vfunc027();
    virtual void vfunc028();
    virtual void vfunc029();
    virtual void vfunc02A();
    virtual void vfunc02B();
    virtual void vfunc02C();
    virtual void vfunc02D();
    virtual void vfunc02E();
    virtual void vfunc02F();
    virtual void vfunc030();
    virtual void vfunc031();
    virtual void vfunc032();
    virtual void vfunc033();
    virtual void vfunc034();
    virtual void vfunc035();
    virtual void vfunc036();
    virtual void vfunc037();
    virtual void vfunc038();
    virtual void vfunc039();
    virtual void vfunc03A();
    virtual void vfunc03B();
    virtual void vfunc03C();
    virtual void vfunc03D();
    virtual void vfunc03E();
    virtual void vfunc03F();
    virtual void vfunc040();
    virtual void vfunc041();
    virtual void vfunc042();
    virtual void vfunc043();
    virtual void vfunc044();
    virtual void vfunc045();
    virtual void vfunc046();
    virtual void vfunc047();
    virtual void vfunc048();
    virtual void vfunc049();
    virtual void vfunc04A();
    virtual void vfunc04B();
    virtual void vfunc04C();
    virtual void vfunc04D();
    virtual void vfunc04E();
    virtual void vfunc04F();
    virtual void vfunc050();
    virtual void vfunc051();
    virtual void vfunc052();
    virtual void vfunc053();
    virtual void vfunc054();
    virtual void vfunc055();
    virtual void vfunc056();
    virtual void vfunc057();
    virtual void vfunc058();
    virtual void vfunc059();
    virtual void vfunc05A();
    virtual void vfunc05B();
    virtual void vfunc05C();
    virtual void vfunc05D();
    virtual void vfunc05E();
    virtual void vfunc05F();
    virtual void vfunc060();
    virtual void vfunc061();
    virtual void vfunc062();
    virtual void vfunc063();
    virtual void vfunc064();
    virtual void vfunc065();
    virtual void vfunc066();
    virtual void vfunc067();
    virtual void vfunc068();
    virtual void vfunc069();
    virtual void vfunc06A();
    virtual void vfunc06B();
    virtual void vfunc06C();
    virtual void vfunc06D();
    virtual void vfunc06E();
    virtual void vfunc06F();
    virtual void vfunc070();
    virtual void vfunc071();
    virtual void vfunc072();
    virtual void vfunc073();
    virtual void vfunc074();
    virtual void vfunc075();
    virtual void vfunc076();
    virtual void vfunc077();
    virtual void vfunc078();
    virtual void vfunc079();
    virtual void vfunc07A();
    virtual void vfunc07B();
    virtual void vfunc07C();
    virtual NiPoint3* GetPos();
};



// Compares the player's distance to the objects referenced by pvA and pvB, returning -1, 1 or 0.
// @fnv 0x007f0500
int __cdecl FUN_007f0500(const void* pvA, const void* pvB)
{
    NiPoint3 kPlayerPos = *(*reinterpret_cast<::C7F0500Ref * *>(&::_g_thePlayer))->GetPos();
    float fLeftDist = ::GetAngleBetweenPoints(kPlayerPos, *(*(C7F0500Ref**)pvA)->GetPos());
    float fSecondDist = ::GetAngleBetweenPoints(kPlayerPos, *(*(C7F0500Ref**)pvB)->GetPos());
    if (fLeftDist < fSecondDist)
        return -1;
    else if (fSecondDist < fLeftDist)
        return 1;
    else
        return 0;
}

struct FUN_007f06d0_Tri
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

struct FUN_007f06d0_Src
{
    char pad[0x14];
    FUN_007f06d0_Tri tri;
    char pad2[0x2c - 0x20];
    unsigned char flag;
};

struct FUN_007f06d0_Node
{
    FUN_007f06d0_Node* FUN_006629f0();
};


struct FUN_007f06d0_cls
{
    bool FUN_007f06d0(FUN_007f06d0_Src* a1);
};

// @fnv 0x007f06d0
bool FUN_007f06d0_cls::FUN_007f06d0(FUN_007f06d0_Src* pSrc)
{
    FUN_007f06d0_Tri t = pSrc->tri;
    float f0 = 0.0f;
    float f6 = 0.0f;
    reinterpret_cast<::ScreenCamera *>((((FUN_007f06d0_Node*)((void *)(::FUN_0045c670())))->FUN_006629f0()))->ProjectToScreen(*(const ::NiPoint3 *)nullptr, *(float *)nullptr, *(float *)nullptr, {});
    bool ok8 = (!(f0 <= ::_DAT_01012060) && !(f6 <= ::_DAT_01012060) && !(f0 >= ::g_01012070) && !(f6 >= ::g_01012070))
                   ? true
                   : false;
    if (ok8)
    {
        pSrc->flag = 1;
        return true;
    }
    pSrc->flag = 0;
    return false;
}

// @fnv 0x007f3b40
void __cdecl FUN_007f3b40(int a1)
{
    if (DAT_011db0d4 == 0)
    {
        return;
    }
    {
        BSSimpleList<ItemListContainer*>* cur = (BSSimpleList<ItemListContainer*>*)&(*((StandIn*)DAT_011db0d4)
                                                ->FindListEntryForTarget((TESObjectREFR*)::DAT_011f21cc)
                                                ->FUN_006815c0())->items;
        while (cur != 0 && !cur->FUN_008256d0())
        {
            if (*((TargetList*)cur)->FUN_006815c0() != 0)
            {
                if ((*((TargetList*)cur)->FUN_006815c0())->unk20 == a1)
                {
                    *(ItemListContainer**)((char*)DAT_011db0d4 + 0x100) = *((TargetList*)cur)->FUN_006815c0();
                    break;
                }
            }
            cur = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
        }
    }
done:
    return;
}

struct ItemListElement
{
};
struct VATSLookupList
{
    bool FUN_008256d0();
};
struct VATSLookup
{
    int unk00;
    VATSLookupList items;
    bool FUN_007f7280(unsigned int index, bool byPosition);
};
extern const char DAT_01078e44[], DAT_01078e10[];
struct PtrHolder
{
    void* ptr;
    operator void*() const;
    PtrHolder& operator=(void*);
};
class GlobalObject_0044f440
{
  public:
};
struct FUN_004a4410_Class
{
    void* FUN_004a4410(unsigned int);
};
struct TargetActor
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* getNode();
};
struct Target
{
    unsigned int unk00;
    TargetActor* current;
    PtrHolder node;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    bool active;
    bool pending[16];
    bool enabled;
    unsigned short unk12a;
    FUN_004a4410_Class* firstObjects[16];
    FUN_004a4410_Class* secondObjects[16];
    bool secondPending[16];
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    int index;
    int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    bool flag2b4, flag2b5;
    void FUN_00800ac0(TargetActor*, int, bool);
};
// @fnv 0x00800ac0
void Target::FUN_00800ac0(TargetActor* actor, int slot, bool state)
{
    if (!actor)
        ::FUN_0040fbe0();
    else if (state)
        ::FUN_0040fbe0();
    void* newNode = actor ? actor->getNode() : 0;
    unk240 = 0;
    if (newNode != (void*)node && flag2b4)
    {
        flag2b4 = false;
        flag2b5 = false;
    }
    if (enabled && !flag2b4 && actor && actor->getNode() == (void*)node)
        reinterpret_cast<::FUN_00800650_Class *>(this)->FUN_00800650(*((float *)&(::FUN_00403e20((float *)&(g_011db6d8)))), *((float *)&(::FUN_00403e20((float *)&(g_011db750)))), true);
    active = state;
    if (active)
        pending[slot] = true;
    index = slot;
    current = actor;
    node = actor ? actor->getNode() : 0;
    pending[slot] = false;
    secondPending[slot] = false;
    if (slot != -1)
    {
        if (secondObjects[slot])
        {
            FUN_004a4410_Class* tmpA = secondObjects[slot];
            FUN_004a4410_Class* oldA = tmpA;
            oldA ? oldA->FUN_004a4410(1) : 0;
            secondObjects[slot] = 0;
        }
        if (firstObjects[slot])
        {
            FUN_004a4410_Class* oldB = firstObjects[slot];
            FUN_004a4410_Class* tmpB = oldB;
            tmpB ? tmpB->FUN_004a4410(1) : 0;
            firstObjects[slot] = 0;
        }
    }
}

struct WeaponPrompt
{
};
struct AVPrompt
{
    virtual void v0();
    virtual void v4();
    virtual int Get(int);
};
struct PlayerPrompt
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    AVPrompt values;
};
struct TargetPrompt
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual bool IsCreature();
};
struct PromptTile
{
    void SetInt(int, int);
};
struct PromptMenu
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    PromptTile* primary;
    PromptTile* secondary;
};
struct PromptSetting
{
    const char* String();
};

extern bool DAT_011db0cf, DAT_011db0d8;
extern float DAT_011db0bc, DAT_011db0c4;
// @fnv 0x007eb920
void __cdecl FUN_007eb920(WeaponPrompt* weapon)
{
    if (weapon && reinterpret_cast<::FUN_007ebd10_This *>((weapon))->FUN_007ebd10() > 0.0 &&
        reinterpret_cast<::FUN_007ebd30_This *>((weapon))->FUN_007ebd30() <= (*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer))->values.Get(((int)(reinterpret_cast<::FUN_008d85e0_Class *>((weapon))->GetUnk15C()))))
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PromptMenu*)DAT_011db0d4)->primary))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::fnv_00522be0::FUN_00522be0_shell *>((weapon))->FUN_00522be0()))), true);
        ((PromptMenu*)DAT_011db0d4)->primary->SetInt(0xfa3, 1);
        DAT_011db0cf = true;
        ((PromptMenu*)DAT_011db0d4)->secondary->SetInt(0xfa3, 0);
        DAT_011db0d8 = false;
        DAT_011db0bc = reinterpret_cast<::FUN_008d9140_Class *>((weapon))->GetField378();
        DAT_011db0b8 = reinterpret_cast<::FUN_007ebd10_This *>((weapon))->FUN_007ebd10();
        ::ApplyPerkModifiers(0x28, (::Actor *)((*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer))), weapon ? weapon : (*reinterpret_cast<::WeaponPrompt * *>(&::DAT_011ca278)), &DAT_011db0b8);
    }
    else if ((!weapon || (weapon && ((int)(reinterpret_cast<::FUN_008d85e0_Class *>((weapon))->GetUnk15C())) == 0x2d)) &&
             (*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer))->values.Get(0x2d) >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PromptSetting *>(&::originalRuntimeFloatSetting1077)))))))
    {
        bool creature = false;
        if (::DAT_011f21cc &&
            (((TargetPrompt*)::DAT_011f21cc)->IsCreature() ||
             (((TargetPrompt*)::DAT_011f21cc)->IsActor() && ((bool)(reinterpret_cast<::FUN_00437bd0_stub *>((((TargetPrompt*)::DAT_011f21cc)))->FUN_00437bd0())))))
        {
            creature = true;
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PromptMenu*)DAT_011db0d4)->primary))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::PromptSetting *>(&::g_011d2754)).String()), true);
            ((PromptMenu*)DAT_011db0d4)->primary->SetInt(0xfa3, 1);
        }
        else
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PromptMenu*)DAT_011db0d4)->primary))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::PromptSetting *>(&::g_011d46c0)).String()), true);
            ((PromptMenu*)DAT_011db0d4)->primary->SetInt(0xfa3, 1);
        }
        DAT_011db0cf = true;
        DAT_011db0bc = 1.0f;
        DAT_011db0b8 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PromptSetting *>(&::originalRuntimeFloatSetting1078))))));
        ::ApplyPerkModifiers(0x28, (::Actor *)((*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer))), weapon ? weapon : (*reinterpret_cast<::WeaponPrompt * *>(&::DAT_011ca278)), &DAT_011db0b8);
        if (!creature && (*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer))->values.Get(0x2d) >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PromptSetting *>(&::originalRuntimeFloatSetting1081)))))))
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((PromptMenu*)DAT_011db0d4)->secondary))->FUN_00a01350(0xfc4, (char *)((*reinterpret_cast<::PromptSetting *>(&::g_011d46d8)).String()), true);
            ((PromptMenu*)DAT_011db0d4)->secondary->SetInt(0xfa3, 1);
            DAT_011db0d8 = true;
            DAT_011db0c4 = 1.0f;
            DAT_011db0c0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::PromptSetting *>(&::originalRuntimeFloatSetting1084))))));
            ::ApplyPerkModifiers(0x28, (::Actor *)((*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer))), weapon ? weapon : (*reinterpret_cast<::WeaponPrompt * *>(&::DAT_011ca278)), &DAT_011db0c0);
        }
        else
        {
            ((PromptMenu*)DAT_011db0d4)->secondary->SetInt(0xfa3, 0);
            DAT_011db0d8 = false;
        }
    }
    else
    {
        ((PromptMenu*)DAT_011db0d4)->primary->SetInt(0xfa3, 0);
        DAT_011db0cf = false;
        ((PromptMenu*)DAT_011db0d4)->secondary->SetInt(0xfa3, 0);
        DAT_011db0cf = false;
    }
}

namespace VatsShutdown {
struct Actor;
struct Request;
struct Menu
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned char unkf8, unkf9, unkfa, closed;
};
struct Input
{
};
struct Tile
{
};
struct List
{
    bool FUN_008256d0();
};
struct Interface
{
};
struct State
{
};
struct Sound
{
    unsigned int unk0, unk4, unk8;
    Sound();
    ~Sound();
};
struct Audio
{
};
struct Setting
{
};
struct Request
{
    unsigned int type;
    unsigned char flag4, flag5, flag6, flag7;
    unsigned char mode, unk9, unka, unkb;
    Actor* actor;
    unsigned int action, unk14, unk18, unk1c, unk20;
    unsigned char flag24, unk25, unk26, unk27;
    Request();
};
struct Queue
{
    int FUN_005ae380();
};
struct Actor
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual ~Actor();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual bool Ready();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void Act(Actor*, int, int, int, int, int, int, int);
};
struct Wheel
{
};
Wheel* FUN_00705910();
extern unsigned char DAT_011db0cd;
extern const char DAT_01077d78[], DAT_01077d6c[];
}
namespace fnv_007ec3a0 {
struct Actor85;
struct Process85;
struct Weapon85
{
};
struct Item85
{
    Weapon85* FUN_0044ddc0();
};
struct Actor85
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
};
struct Process85
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual Item85* Weapon();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual bool Busy();
};
struct Limb85
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int part;
    int unk24;
    int unk28;
    unsigned short unk2c;
    bool flag;
    unsigned char unk2f;
};
struct LimbList85
{
    Limb85* item;
    LimbList85* next;
    bool FUN_008256d0();
    Limb85** FUN_006815c0();
};
struct Target85
{
    Actor85* actor;
    int type;
    LimbList85 limbs;
};
struct TargetList85
{
    Target85** FUN_006815c0();
};
struct Mode85
{
    void* targetsItem;
    void* targetsNext;
    int mode;
    int FUN_0044ddc0();
};
struct Menu85
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    float damage;
    Limb85* current;
    TargetList85* FindListEntryForTarget(Actor85*);
    int FUN_007f3bf0(int);
};
extern Actor85* DAT_011db0d0;
struct Sound85
{
    int unk00, unk04, unk08;
    Sound85();
    ~Sound85();
};
struct Audio85
{
    Sound85 FUN_00ad7550(const char*, int);
};
struct Highlight85
{
};
Highlight85* FUN_00705910();
// Refreshes the VATS target highlight and damage for the current target part, playing a select sound and updating the highlighted actor and part globals.
// @fnv 0x007ec3a0
void UpdateVatsTargetHighlight(bool force)
{
    if (((Menu85*)DAT_011db0d4))
    {
        TargetList85* target13 = ((Menu85*)DAT_011db0d4)->FindListEntryForTarget(((Actor85*)::DAT_011f21cc));
        if (force || (((std::intptr_t)(((Mode85*)&(*reinterpret_cast<int *>(&::g_011f2250)))->mode)) == 2 &&
                      (((Menu85*)DAT_011db0d4)->FUN_007f3bf0(::VATSCreateDAT_011a0b70) !=
                           ((Menu85*)DAT_011db0d4)->FUN_007f3bf0(((Menu85*)DAT_011db0d4)->current->part) ||
                       DAT_011db0d0 != ((Actor85*)::DAT_011f21cc))))
        {
            if (!force && DAT_011db0d0 == ((Actor85*)::DAT_011f21cc) && !((::fnv_007ec3a0::Process85 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007ec3a0::Actor85 * *>(&::_g_thePlayer))))->GetBaseTexture()))->Busy())
            {
                Sound85 sound;
                reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_007ec3a0::Sound85 &)(((::fnv_007ec3a0::Audio85 *)(::FUN_00453a70()))->FUN_00ad7550("UIVATSSelectTargetPart", 289))));
                reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(0);
            }
            ((Menu85*)DAT_011db0d4)->damage = reinterpret_cast<::VATSMenuX *>((((Menu85*)DAT_011db0d4)))->FUN_007f48e0();
            Actor85* actor4 = 0;
            if (target13 && *target13->FUN_006815c0() && (*target13->FUN_006815c0())->actor->IsActor())
                actor4 = (*target13->FUN_006815c0())->actor;
            Item85* item6 = ((::fnv_007ec3a0::Process85 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007ec3a0::Actor85 * *>(&::_g_thePlayer))))->GetBaseTexture()))->Weapon();
            Weapon85* weapon6 = item6 ? ((::fnv_007ec3a0::Weapon85 *)(reinterpret_cast<::Twin_0044ddc0 *>((item6))->GetName())) : 0;
            if (target13 && ((*target13->FUN_006815c0())->type == 2 || ((::fnv_007ec3a0::Process85 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007ec3a0::Actor85 * *>(&::_g_thePlayer))))->GetBaseTexture()))->Busy() ||
                             !weapon6 || ::FUN_006450c0((::TESObjectWEAP *)(weapon6))))
            {
                if (force ||
                    (((std::intptr_t)(((Mode85*)&(*reinterpret_cast<int *>(&::g_011f2250)))->mode)) == 2 && DAT_011db0d0 != ((Actor85*)::DAT_011f21cc)))
                {
                    if (((std::intptr_t)(((Mode85*)&(*reinterpret_cast<int *>(&::g_011f2250)))->mode)) == 3)
                        reinterpret_cast<::Target *>((FUN_00705910()))->FUN_00800ac0((::TargetActor *)((*target13->FUN_006815c0())->actor),
                                                     ((Menu85*)DAT_011db0d4)->current->part, 1);
                    else
                        reinterpret_cast<::Target *>((FUN_00705910()))->FUN_00800ac0((::TargetActor *)((*target13->FUN_006815c0())->actor), 15, 0);
                    DAT_011db0d0 = (*target13->FUN_006815c0())->actor;
                }
                ::VATSCreateDAT_011a0b70 = ((Menu85*)DAT_011db0d4)->current->part;
            }
            else if (actor4 && ((::fnv_007ec3a0::Process85 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor4))->GetBaseTexture())))
            {
                if (!((Menu85*)DAT_011db0d4)->current->flag && ((std::intptr_t)(((Mode85*)&(*reinterpret_cast<int *>(&::g_011f2250)))->mode)) == 3)
                    reinterpret_cast<::Target *>((FUN_00705910()))->FUN_00800ac0((::TargetActor *)(::fnv_007ec3a0::Actor85 *)(((Actor85*)::DAT_011f21cc)), ((Menu85*)DAT_011db0d4)->current->part, 1);
                else
                    reinterpret_cast<::Target *>((FUN_00705910()))->FUN_00800ac0((::TargetActor *)(::fnv_007ec3a0::Actor85 *)(((Actor85*)::DAT_011f21cc)), ((Menu85*)DAT_011db0d4)->current->part, 0);
                LimbList85* limb =
                    &(*((Menu85*)DAT_011db0d4)->FindListEntryForTarget(((Actor85*)::DAT_011f21cc))->FUN_006815c0())
                         ->limbs;
                while (limb && !limb->FUN_008256d0())
                {
                    if (((Menu85*)DAT_011db0d4)->FUN_007f3bf0((*limb->FUN_006815c0())->part) ==
                            ((Menu85*)DAT_011db0d4)->FUN_007f3bf0(((Menu85*)DAT_011db0d4)->current->part) &&
                        *limb->FUN_006815c0() != ((Menu85*)DAT_011db0d4)->current)
                        reinterpret_cast<::FUN_00800d10_class *>((FUN_00705910()))->AppendValue((*limb->FUN_006815c0())->part);
                    limb = ((::fnv_007ec3a0::LimbList85 *)(reinterpret_cast<::Callees *>((limb))->FUN_00726070()));
                }
                ::VATSCreateDAT_011a0b70 = ((Menu85*)DAT_011db0d4)->current->part;
                DAT_011db0d0 = ((Actor85*)::DAT_011f21cc);
            }
        }
    }
}
}  // namespace fnv_007ec3a0

struct InputProcessX;
struct RefX
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual InputProcessX* v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual int v116();
    unsigned int FUN_0044ddc0();
};
struct InputProcessX
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual RefX* v82();
};
struct PlayerX
{
};
struct SoundX
{
    int id;
    int flags;
    int state;
    SoundX();
    ~SoundX();
    SoundX& operator=(const SoundX&);
};
struct InputAudioX
{
    SoundX GetSoundHandleByEditorID(const char*, unsigned);
};
struct InputTileX
{
};
struct ItemX;
struct ItemsX
{
    void* data;
    ItemsX* next;
    bool FUN_008256d0();
};
struct InputTargetX
{
    RefX* ref;
    int type;
    ItemsX items;
    unsigned char special;
};
struct TargetsX
{
    bool FUN_008256d0();
    unsigned GetSize();
};
struct ItemX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    unsigned char unk2c;
    bool selected;
    bool queued;
    unsigned char unk2f;
    InputTileX* tile;
};
struct MenuX
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    bool heading;
    bool meters;
    bool lit;
    bool closing;
    float damage;
    ItemX* current;
    bool perk;
    unsigned char unk105;
    unsigned short unk106;
    ItemX* last;
    bool stick;
    bool targetStick;
    bool mouse;
    bool left;
    bool right;
    void HandleInput(int key, int held);
    ItemsX* FindListEntryByValue(int);
    TargetsX* FindListEntryForTarget(RefX*);
    void UpdateQueueEntry(int, int, int);
    void FUN_007f3070();
};

struct VatsX
{
    unsigned int FUN_0044ddc0();
};

bool FUN_007f4bb0();
void FUN_007f3bd0(int);
void FUN_00705780();

struct SortRef
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float GetCurrentTargetDistance(int);
};
struct Actor;

// Sorts two objects by the absolute angular difference between the player's heading and the direction from the player to each object's position.
// @fnv 0x007f0380
int __cdecl CompareByHeadingToPlayer(const void* apRefA, const void* apRefB)
{
    NiPoint3 kPlayerPosition = *((SortRef*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))->GetPos();
    float fPlayerRot = ((SortRef*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))->GetCurrentTargetDistance(0) * 57.2957763671875;
    float fHeadingToA = ::GetAngleBetweenPoints(kPlayerPosition, *(*(SortRef**)apRefA)->GetPos());
    float fHeadingToB = ::GetAngleBetweenPoints(kPlayerPosition, *(*(SortRef**)apRefB)->GetPos());
    float fDifference = std::abs(fPlayerRot - fHeadingToA);
    fHeadingToA = std::abs((float)(fDifference > 180.0 ? 360.0 - fDifference : fDifference));
    fDifference = std::abs(fPlayerRot - fHeadingToB);
    fHeadingToB = std::abs((float)(fDifference > 180.0 ? 360.0 - fDifference : fDifference));
    if (fHeadingToA < fHeadingToB)
        return -1;
    else if (fHeadingToA > fHeadingToB)
        return 1;
    else
        return 0;
}

struct VisPoint3
{
    float x;
    float y;
    float z;
};
struct VisCamera
{
};
struct VisCameraNode
{
    VisCamera* FUN_006629f0();
};

struct VisMarker
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    VisPoint3 kPos;
    int unk20;
    int unk24;
    int unk28;
    bool bHidden;
};
struct VisMarkerHolder
{
    int unk00;
    int unk04;
    struct VisNode* pFirst;
};
struct VisNode
{
    bool FUN_008256d0();
};
struct VisList
{
};

struct FUN_007f05b0_Menu
{
    VisList* FindListEntryForTarget(int aiID);
    bool HasVisibleMarkerOnScreen();
};

namespace fnv_007f07a0 {
struct FormX
{
    unsigned int FUN_0044ddc0();
};
struct TileX
{
    void FUN_00700320(int, int);
};
struct ChanceX
{
    char pad00[0x20];
    int f20;
    char pad24[0x2c - 0x24];
    unsigned char b2c;
    unsigned char b2d;
    char pad2e;
    unsigned char b2f;
    TileX* tile;
};
struct VTarget
{
    char pad00[4];
    int f04;
    char pad08[0x10 - 8];
    unsigned char b10;
    char pad11[3];
};
struct LimbX
{
    char pad00[0x20];
    int f20;
};
struct ProcX
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual FormX* vt148();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual bool vt1a8();
};
struct ActorX
{
};
struct InterpX
{
};
struct TimeG
{
};
struct Owner7
{
    char pad00[0xf8];
    unsigned char bF8;
    unsigned char bF9;
    char padFA[0x100 - 0xfa];
    LimbX* m_pTargetChance;
    BSSimpleList<ItemListContainer*>* FindListEntryForTarget(void*);
    void* FUN_007f3bf0(int);
    void UpdateLimbHighlight();
};
extern const char str_01077df4[];
extern const char str_01077de8[];
extern const char str_01077dd4[];
extern const char str_010734b8[];
// @fnv 0x007f07a0
void Owner7::UpdateLimbHighlight()
{
    static int sMeterPercent = ::FUN_00a00940(str_01077df4, -1);
    static int sLimbName = ::FUN_00a00940(str_01077de8, -1);
    static int sLimbNameVisible = ::FUN_00a00940(str_01077dd4, -1);
    static int sBrightness = ::FUN_00a00940(str_010734b8, -1);
    BSSimpleList<ItemListContainer*>* node7;
    BSSimpleList<ItemListContainer*>* list6;
    list6 = FindListEntryForTarget(::DAT_011f21cc);
    node7 = (BSSimpleList<ItemListContainer*>*)&(*list6->FUN_006815c0())->items;
    if (((std::uintptr_t)(reinterpret_cast<::InventoryEntryFields *>((((FormX*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->pObject)) == 1 || ((std::uintptr_t)(reinterpret_cast<::InventoryEntryFields *>((((FormX*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->pObject)) == 3 ||
        (((std::uintptr_t)(reinterpret_cast<::InventoryEntryFields *>((((FormX*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->pObject)) == 2 && !bF8))
    {
        while (node7 != 0 && !node7->FUN_008256d0())
        {
            if (reinterpret_cast<::TileListBoxCalls *>((((ChanceX*)*node7->FUN_006815c0())->tile))->GetFloat(0xfa9) > 0.0)
            {
                reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((((ChanceX*)*node7->FUN_006815c0())->tile))->RemoveFadeItemsForTile(0xfa9);
                reinterpret_cast<::FUN_00a012d0_t *>((((ChanceX*)*node7->FUN_006815c0())->tile))->FUN_00a012d0(0xfa9, 0.0f, true);
            }
            node7 = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070()));
        }
        bF9 = 0;
        return;
    }
    else if (bF9 == 1)
    {
        BSSimpleList<ItemListContainer*>* savedNodeA;
        FormX* formTmp;
        formTmp = ((::fnv_007f07a0::ProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007f07a0::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->vt148();
        uintptr_t typeC5;
        typeC5 = formTmp ? ((uintptr_t)(reinterpret_cast<::InventoryEntryFields *>((formTmp))->pObject)) : 0;
        bool flag4;
        flag4 = false;
        if (((VTarget*)*list6->FUN_006815c0())->f04 == 2 || ((::fnv_007f07a0::ProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007f07a0::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->vt1a8() || typeC5 == 0 ||
            ::FUN_006450c0((::TESObjectWEAP *)(((FormX*)typeC5))))
        {
            flag4 = true;
        }
        savedNodeA = 0;
        while (!flag4 && node7 != 0 && !node7->FUN_008256d0())
        {
            if (reinterpret_cast<::FUN_007f05b0_Menu *>(this)->HasVisibleMarkerOnScreen() ||
                (((ChanceX*)*node7->FUN_006815c0())->b2d == 0 && ((ChanceX*)*node7->FUN_006815c0())->b2c != 0 &&
                 ((ChanceX*)*node7->FUN_006815c0())->b2f != 0))
            {
                (*reinterpret_cast<unsigned char *>(&::fnv_00709d10::g_flag)) = 1;
                ((VTarget*)*list6->FUN_006815c0())->b10 = 0;
                if (((std::uintptr_t)(reinterpret_cast<::InventoryEntryFields *>((((FormX*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->pObject)) != 3)
                {
                    reinterpret_cast<::NiPoint3Interpolator *>((((InterpX*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->CreateObject(3, false);
                    DAT_011db0dc = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_007f07a0::TimeG *>(&::g_timeGlobal))))->FUN_00825c00();
                }
                return;
            }
            if (((ChanceX*)*node7->FUN_006815c0())->f20 == 1)
                savedNodeA = node7;
            node7 = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070()));
        }
        node7 = (BSSimpleList<ItemListContainer*>*)&(*list6->FUN_006815c0())->items;
        while (node7 != 0 && !node7->FUN_008256d0())
        {
            float fVal8;
            fVal8 = reinterpret_cast<::TileListBoxCalls *>((((ChanceX*)*node7->FUN_006815c0())->tile))->GetFloat(0xfa9);
            if (((ChanceX*)*node7->FUN_006815c0())->b2c != 0)
            {
                ((ChanceX*)*node7->FUN_006815c0())->b2f = 0;
                FormX* formC3;
                formC3 = ((::fnv_007f07a0::ProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007f07a0::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->vt148();
                uintptr_t typeC4;
                typeC4 = formC3 ? ((uintptr_t)(reinterpret_cast<::InventoryEntryFields *>((formC3))->pObject)) : 0;
                if (((::fnv_007f07a0::ProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007f07a0::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->vt1a8() || typeC4 == 0 || ::FUN_006450c0((::TESObjectWEAP *)(((FormX*)typeC4))))
                {
                    if ((savedNodeA != 0 && node7 == savedNodeA) || (savedNodeA == 0 && ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070())) == 0))
                    {
                        if (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((ChanceX*)*node7->FUN_006815c0())->tile))->FUN_00a07fc0(0xfa9))
                        {
                            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((ChanceX*)*node7->FUN_006815c0())->tile))->StartFade(0xfa9, 0.0f, 255.0f, 1.0f, 1);
                        }
                    }
                }
                else
                {
                    if (m_pTargetChance != (LimbX*)((ChanceX*)*node7->FUN_006815c0()) &&
                        (std::intptr_t)FUN_007f3bf0(((ChanceX*)*node7->FUN_006815c0())->f20) !=
                            (std::intptr_t)FUN_007f3bf0(m_pTargetChance->f20))
                    {
                        if ((fVal8 == reinterpret_cast<::fnv_00a07f30::FUN_00a07f30_shell *>((((ChanceX*)*node7->FUN_006815c0())->tile))->GetTraitFloat(0xfa9) &&
                             fVal8 != 255.0) ||
                            reinterpret_cast<::FNVSearchOwner *>((((ChanceX*)*node7->FUN_006815c0())->tile))->FindValueByKey(0xfa9) == 1)
                        {
                            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((ChanceX*)*node7->FUN_006815c0())->tile))->StartFade(0xfa9, fVal8, 255.0f, 0.2f, 0);
                        }
                    }
                    else
                    {
                        if (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((((ChanceX*)*node7->FUN_006815c0())->tile))->FUN_00a07fc0(0xfa9))
                        {
                            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((ChanceX*)*node7->FUN_006815c0())->tile))->StartFade(0xfa9, 0.0f, 255.0f, 1.0f, 1);
                        }
                    }
                }
            }
            else
            {
                if (reinterpret_cast<::fnv_00a07f30::FUN_00a07f30_shell *>((((ChanceX*)*node7->FUN_006815c0())->tile))->GetTraitFloat(0xfa9) > 0.0)
                {
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((((ChanceX*)*node7->FUN_006815c0())
                        ->tile))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((((ChanceX*)*node7->FUN_006815c0())->tile))->GetFloat(0xfa9), 0.0f,
                                          0.5f, 0);
                }
            }
        advance:
            ((ChanceX*)*node7->FUN_006815c0())
                ->tile->FUN_00700320(
                    sLimbNameVisible,
                    (std::intptr_t)((Owner7*)DAT_011db0d4)->FUN_007f3bf0(((Owner7*)DAT_011db0d4)->m_pTargetChance->f20) ==
                            (std::intptr_t)((Owner7*)DAT_011db0d4)->FUN_007f3bf0(((ChanceX*)*node7->FUN_006815c0())->f20)
                        ? 1
                        : 0);
            node7 = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070()));
        }
        return;
    }
    bF9 = 1;
    reinterpret_cast<::VATSMenuX *>(this)->UpdateLimbTiles();
}
}  // namespace fnv_007f07a0

struct TileX2 : TileX
{
};

struct VATSX2 : VATSX
{
};

struct QueueX2 : QueueX
{
    bool IsEmpty();
};

struct ActorX2 : ActorX
{
};

struct ActorSub30
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual bool v14();
};

struct ActorBaseStandIn : ActorBaseX
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    ActorSub30 sub30;
};


namespace fnv_007f1290 {

struct ListReader1290
{
    ChanceX** FUN_006815c0();
};
struct Actor1290
{
};
struct Form1290
{
};
struct Weapon1290
{
};
struct FUN_006dcd70
{
    float m00, m04, m08, m0c, m10, m14, m18, m1c, m20, m24;
    FUN_006dcd70(ActorX*);
    ~FUN_006dcd70();
};
struct Point1290
{
    float x, y, z;
};
struct TempSound1290
{
    void FUN_00407e00(int, bool);
};
struct TemporaryCommand1290
{
    int action;
    bool active;
    char shotCount;
    char extraShot;
    bool flag7;
    unsigned char shots;
    unsigned char extra;
    unsigned short unk0a;
    ActorX* target;
    int limb;
    TempSound1290* sound;
    int weaponIndex;
    int flags;
    float apCost;
};
struct VATSMenu1290 : VATSMenuX
{
    bool hasCalculated;
    TemporaryCommand1290 activeCommand;
    float CalculateVATSChance(ListReader1290* target);
};
struct ChanceTarget1290
{
    int m00, m04, m08, m0c, m10, m14, m18, m1c;
    int limb;
    float weight;
};
struct TargetMode1290
{
    int unk00;
    unsigned int mode;
};
struct Effect1290
{
};
float __cdecl GetHitChance(ActorValueOwnerX*, ActorX*, WeaponX*, float, float, float, int, int, float, float, float,
                           int);

// Computes the VATS hit chance for the current target, updates the active command and stores the chance on the target.
// @fnv 0x007f1290
float VATSMenu1290::CalculateVATSChance(ListReader1290* targetNode)
{
    float kResult = 0.0f;  // Accumulated hit chance.
    if (targetNode == 0)
        return kResult;
    ChanceX* target = *targetNode->FUN_006815c0();
    ListX<TargetX*>* kList = FindListEntryForTarget((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)));
    TargetX* targetX = *reinterpret_cast<TargetX**>(reinterpret_cast<ListReader1290*>(kList)->FUN_006815c0());
    FormX* entryB = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetEquippedWeapon();
    WeaponX* otherA = entryB ? ((::WeaponX *)(reinterpret_cast<::InventoryEntryFields *>((entryB))->pObject)) : 0;
    FormX* targetA = (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsActor() ? ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->GetBaseTexture()))->GetEquippedWeapon() : 0;
    float kScale = targetA ? reinterpret_cast<::FUN_004bcdb0_shell *>((((Form1290*)targetA)))->FUN_004bcdb0(1) / ::g_d100 : 1.0;
    WeaponX* weaponA = targetA ? ((::WeaponX *)(reinterpret_cast<::InventoryEntryFields *>((targetA))->pObject)) : 0;
    Effect1290* specialReference = 0;
    ElemX* entry = 0;
    if ((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsActor())
    {
        specialReference = (Effect1290*)((::ActorBaseX *)(reinterpret_cast<::Actor *>((((Actor1290*)(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))))->GetActorBase()))->GetRace();
        entry = ((::ElemX *)(reinterpret_cast<::FUN_005e50f0_Obj *>((specialReference))->GetValueByIndex(target->m_iActionValue)));
    }
    float boundX = 0.0f;  // Effective range.
    if (otherA && !(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))
    {
        boundX = reinterpret_cast<::fnv_0050ebf0::FUN_0050ebf0_shell *>((((Weapon1290*)otherA)))->FUN_0050ebf0() * 2.0f;
    }
    else
    {
        boundX = reinterpret_cast<::TESObjectREFR *>((((Actor1290*)(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))))->GetBoundingRadius() * 2.0f;
    }
    if (boundX < ::g_01012070)
        boundX = ::DAT_0101e704;
    kResult = GetHitChance(
        (*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)) ? &(*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))->kAVOwner : 0, (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)), otherA, kScale,
        ::GetActorReach((::A69C0Actor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))), (::A69C0Weapon *)(otherA)), otherA ? reinterpret_cast<::CalcActor *>((((Actor1290*)(*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))->GetCachedSpeed(3) : 1.0f,
        ((TargetMode1290*)targetX)->mode != 2 ? (intptr_t)entry : 0,
        ((TargetMode1290*)targetX)->mode != 2 ? (intptr_t)weaponA : 0, ((ChanceTarget1290*)target)->weight,
        ::FUN_009a64d0((::S_9a64d0_Ref *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))), (::S_9a64d0_Ref *)((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))), 0), boundX, 0);
    bool invalidX = false;
    if (!otherA || ::FUN_006450c0((::TESObjectWEAP *)(((Weapon1290*)otherA))))
    {
        FUN_006dcd70 pointB((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)));
        FUN_006dcd70 origin((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)));
        float minimum = ::DAT_01016970;
        if (!::FUN_006d5490((::RouteLocation *)(::fnv_007f1290::FUN_006dcd70 *)(&pointB), (::RouteLocation *)(::fnv_007f1290::FUN_006dcd70 *)(&origin), (void *)(0), &minimum, (::FUN_006abbb0 *)(0)))
            minimum = ::DAT_01016970;
        float valueX = reinterpret_cast<::NiPoint3 *>((void *)&(const ::fnv_007f1290::Point1290 &)((*(::fnv_007f1290::Point1290 *)(reinterpret_cast<::FUN_00439ef0_class *>((((Point1290*)((C7F0500Ref*)(*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))->GetPos())))->FUN_00439ef0((::NiPoint3 *)&(*(Point1290*)((C7F0500Ref*)(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))->GetPos()), *(const ::NiPoint3 *)nullptr)))))->ComputeMagnitude();
        if (valueX * ::DAT_01011590 < minimum)
            invalidX = true;
    }
    float maximumA = invalidX ? 0.0f : kResult;
    float effectsB = 0.0f;
    hasCalculated = true;
    reinterpret_cast<::FUN_009ca500_shell *>(&(activeCommand))->FUN_009ca500();
    activeCommand.limb = entry ? ((char)(reinterpret_cast<::FUN_005e5190_Class *>((entry))->GetByte63())) : -1;
    activeCommand.target = (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc));
    activeCommand.active = true;
    activeCommand.sound->FUN_00407e00(0x800, true);
    ::SetContextInfo((::n9b::Ctx *)(activeCommand.sound), (::n9b::Info *)(::fnv_007f1290::TemporaryCommand1290 *)(&activeCommand));
    ::ApplyPerkModifiers(8, (::Actor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))), otherA ? otherA : (*reinterpret_cast<::WeaponX * *>(&::DAT_011ca278)), (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)), &maximumA);
    ::ApplyPerkModifiers(0x21, (::Actor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))), &effectsB);
    m_bStateFlag4 = (effectsB != ::_DAT_01012060) ? true : false;
    if (maximumA > kResult)
        kResult = maximumA;
    if (target->fHitChance == ::_DAT_01012060 && kResult > ::_DAT_01012060)
        target->fHitChance = kResult;
    return kResult;
}
}  // namespace fnv_007f1290

namespace fnv_007f3d60 {
struct Actor
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool v64();
};
struct FUN_007f3d60_cls : StandIn
{
    unsigned int FUN_007f3bf0(int a);
    BSSimpleList<ItemListContainer*>* FindListEntryByValue(int a1);
};
// @fnv 0x007f3d60
BSSimpleList<ItemListContainer*>* FUN_007f3d60_cls::FindListEntryByValue(int aiValue)
{
    if (!((Actor*)::DAT_011f21cc)->v64())
    {
        return 0;
    }
    intptr_t head = (intptr_t)*this->FindListEntryForTarget(reinterpret_cast<TESObjectREFR*>(::DAT_011f21cc))->FUN_006815c0();
    if (head != 0)
    {
        BSSimpleList<ItemListContainer*>* cur = (BSSimpleList<ItemListContainer*>*)(head + 8);
        while (cur != 0 && !cur->FUN_008256d0())
        {
            if ((int)this->FUN_007f3bf0((*cur->FUN_006815c0())->unk20) == aiValue)
            {
                return cur;
            }
            cur = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
        }
    }
    return 0;
}
}  // namespace fnv_007f3d60

struct LimbM;
struct PointM
{
    float x, y, z;
    PointM operator-(const PointM&) const;
    bool operator==(const PointM&) const;
};
struct WeaponM
{
};
struct ItemM
{
    WeaponM* FUN_0044ddc0();
};
struct ProcessM
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual ItemM* current();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual bool special();
};
struct PosM
{
};
struct ActorM
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool check();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual PosM* position();
    void UpdateCamera(bool, bool);
};
struct LimbM
{
    int u00, u04, u08, u0c, u10;
    PointM pos;
    int limb;
    float value24, chance;
    bool active, done, started, failed;
};
struct LimbListM
{
    int item;
    int next;
    bool FUN_008256d0();
};
struct TargetM
{
    ActorM* actor;
    int type;
    LimbListM limbs;
    bool done;
};
struct TargetListM
{
    bool FUN_008256d0();
};
struct StateM
{
    int FUN_0044ddc0();
};
struct TimerM
{
};
struct EffectM
{
};
EffectM* FUN_00705910();
extern TargetM* mLast;
struct MenuM
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    bool heading, meters, lit, closing;
    float damage;
    LimbM* current;
    TargetListM* FindListEntryForTarget(ActorM*);
    LimbListM* FindListEntryByValue(int);
    bool UpdateVatsTargeting();
};
struct VATS_COMMAND_LIST
{
    int eAction;
    bool bFlag4, bFlag5, bFlag6, bFlag7;
    unsigned char ucShots, ucExtra;
    unsigned short flags;
    ActorX* pTarget;
    int m_iActionValue;
    int unk14, unk18, unk1c;
    float fAPCost;
    int unk24;
    VATS_COMMAND_LIST();
    ~VATS_COMMAND_LIST();
};
struct AttackQueueNode
{
    bool FUN_008256d0();
};
struct DamageActor : ActorX
{
};
struct HealthValueOwner
{
    virtual int GetValue(int av);
    virtual void v004();
    virtual int GetCurrentValue(int av);
};
struct WeaponTypeCall
{
    int FUN_00446390();
};

class NiPoint2
{
  public:
    NiPoint2();
    float x;
    float y;
public:
    ::NiPoint2 operator*(float) const;
};

class NiPoint3_ext
{
  public:
    NiPoint3_ext();
    float x;
    float y;
    float z;
};

class FUN_007f6820_cls
{
  public:
    NiPoint2 kPoint;
    NiPoint3_ext kPointCur;
    NiPoint3_ext kPointValue;
    int iUnk;
    float fUnk;
    float fUnkCur;
    bool bUnk2C;
    bool bUnk2D;
    bool bUnk2E;
    bool bUnk2F;
    int iUnkCur;
    float fUnkValue;
    bool bUnk;

    FUN_007f6820_cls();
};

// @fnv 0x007f6820
FUN_007f6820_cls::FUN_007f6820_cls()
{
    iUnk = -1;
    fUnk = 0.0f;
    fUnkCur = 0.0f;
    bUnk2C = false;
    bUnk2D = false;
    bUnk2E = true;
    bUnk2F = true;
    iUnkCur = 0;
    fUnkValue = 0.0f;
    bUnk = false;
}

struct ListItemTile;
struct ListItemValue
{
};
struct ListItemMenu
{
};
struct ListItemTile
{
};
struct ListItemData
{
    ListItemTile* tile;
    void* object;
    int index;
    ListItemData(ListItemTile* tile, void** object);
};
typedef int(__cdecl* ListItemCompare)(ListItemData*, ListItemData*);
struct ListItemEntries
{
    ListItemData* item;
    ListItemEntries* next;
};
struct ListBoxInsert
{
    void* vtable;
    ListItemEntries entries;
    ListItemTile* parent;
    int selected;
    int flags;
    const char* templateName;
    unsigned short itemCount;
    ListItemTile* AddItemTile(void* object, const char* text, ListItemCompare compare, const char* name);
};
struct B9C88A0Item
{
    ~B9C88A0Item();

    int m_iValue;
    char unk04;
    bool m_bFlag;
};

class B9C88A0List
{
  public:
    bool IsEmpty();

    void PopLastItem(int* piValue, bool* pbFlag);
};

struct Vec392
{
    float x, y;
    Vec392();
    Vec392 operator-(const Vec392&) const;
    Vec392 operator+(const Vec392&) const;
    Vec392 operator*(float) const;
    Vec392 DivideBy(float) const;
};
struct Point392
{
    float x, y, z;
    Point392();
};
struct Matrix392
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    Matrix392();
    Point392 operator*(const Point392&) const;
};
struct Tile392
{
};
struct Scene392
{
};
struct Part392
{
};
struct Race392
{
};
struct Actor392;
struct Process392
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual FormX* GetEquippedWeapon();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual Scene392* GetLimb(void*);
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual bool HasMeleeWeapon();
};
struct Actor392
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual Scene392* GetRoot();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void* GetLimbData();
};
struct Name392
{
};
struct Weapon392
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Name392 name;
};
struct Form392
{
    Weapon392* FUN_0044ddc0();
};
struct Limb392
{
    float x, y;
    Point392 projected;
    Point392 world;
    int limb;
    int unk24;
    float chance;
    bool visible, crippled, selected;
    Tile392* tile;
};
struct Target392
{
    Actor392* actor;
    int kind;
    ListX<Limb392*> limbs;
};
struct Menu392 : VATSMenuX
{
    bool flag118;
};
struct Base392
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual Race392* GetRace();
};
struct Ref392
{
};
struct ProjectionResult392
{
    ProjectionResult392* FUN_006629f0();
};
float FUN_00408840(float);
struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx& arHandle);
};

struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
public:
    void DisableAudioPlayback();
public:
    void SetAudioState(unsigned int);
};

struct PlayerCharacter : public Actor
{
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float GetAngleZ(int a1);
public:
    void UpdateCameraMode();
};


struct TargetSelectHelper
{
    void SelectTarget(bool a1);
};

extern int UNK_01077eac;
extern int UNK_01077e98;
struct GlobalManager
{
};
struct Tile
{
    void Set(int a1, int a2);
};
// Closes the VATS menu, plays sounds, queues action requests for the actors and resets the VATS queue and wheel state.
// @fnv 0x007ebd50
void ShutdownVats()
{
    namespace V = VatsShutdown;
    if (!(*reinterpret_cast<::VatsShutdown::Menu * *>(&::DAT_011db0d4)) || ((int)((*reinterpret_cast<::VatsShutdown::Menu * *>(&::DAT_011db0d4))->unk24)) != 1)
        return;
    if (!(*reinterpret_cast<::VatsShutdown::Menu * *>(&::DAT_011db0d4))->closed)
        reinterpret_cast<::BSAudio *>((((::VatsShutdown::Input *)(::FUN_00453a70()))))->DisableAudioPlayback();
    (*reinterpret_cast<::VatsShutdown::Menu * *>(&::DAT_011db0d4))->closed = 1;
    V::Tile* tile = ((::VatsShutdown::Tile *)(::FUN_00a09030((int)(((::FUN_007eb8c0()))))));
    if (!tile)
    {
        reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::VatsShutdown::Queue *>(&::g_011f2250))))->CreateObject(0, 0);
        (*reinterpret_cast<unsigned char *>(&::DAT_011a3b31)) = 0;
        return;
    }
    if ((*reinterpret_cast<::VatsShutdown::Menu * *>(&::DAT_011db0d4)))
    {
        if (!(*reinterpret_cast<::VatsShutdown::List *>(&::g_011db124)).FUN_008256d0())
            reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::VatsShutdown::List *>(&::g_011db124))))->RemoveAll();
        reinterpret_cast<::fnv_0070bc20::FUN_0070bc20_shell *>((((::VatsShutdown::Interface *)(::fnv_004b7210::FUN_004b7210()))))->UpdateActivatePick();
        reinterpret_cast<::BSAudio *>((((::VatsShutdown::Input *)(::FUN_00453a70()))))->SetAudioState(256);
        if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::VatsShutdown::State * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
        {
            V::Audio* audioSlot0 = ((::VatsShutdown::Audio *)(::FUN_00ad9060()));
            V::Sound soundSlot0;
            if ((*reinterpret_cast<::VatsShutdown::List *>(&::g_011db150)).FUN_008256d0())
                reinterpret_cast<::SoundPlaybackHandle *>(&(soundSlot0))->operator=((const ::SoundPlaybackHandle &)((const ::VatsShutdown::Sound &)((*(::VatsShutdown::Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((audioSlot0))->ResolveAudioHandle((::Handle_ae5680 *)(::DAT_01077d84), 289, {}))))));
            else
                reinterpret_cast<::SoundPlaybackHandle *>(&(soundSlot0))->operator=((const ::SoundPlaybackHandle &)((const ::VatsShutdown::Sound &)((*(::VatsShutdown::Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((audioSlot0))->ResolveAudioHandle((::Handle_ae5680 *)(V::DAT_01077d78), 289, {}))))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(soundSlot0))->FUN_00ad8830(0);
        }
        reinterpret_cast<::Tile *>((tile))->Set(6002, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>(((*reinterpret_cast<::VatsShutdown::Menu * *>(&::DAT_011db0d4))))->FUN_00a1d910();
    }
    if ((*reinterpret_cast<::VatsShutdown::Queue *>(&::g_011f2250)).FUN_005ae380())
    {
        V::Audio* audioSlot0 = ((::VatsShutdown::Audio *)(::FUN_00ad9060()));
        V::Sound soundSlot0;
        reinterpret_cast<::SoundPlaybackHandle *>(&(soundSlot0))->operator=((const ::SoundPlaybackHandle &)((const ::VatsShutdown::Sound &)((*(::VatsShutdown::Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((audioSlot0))->ResolveAudioHandle((::Handle_ae5680 *)(V::DAT_01077d6c), 289, {}))))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(soundSlot0))->FUN_00ad8830(0);
        float chanceASlot14 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::VatsShutdown::Setting *>(&::originalRuntimeFloatSetting550))))));
        float chanceBSlot0 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::VatsShutdown::Setting *>(&::originalRuntimeFloatSetting549))))));
        ::ApplyPerkModifiers(67, (::Actor *)((*reinterpret_cast<void * *>(&::_g_thePlayer))), &chanceASlot14);
        ::ApplyPerkModifiers(67, (::Actor *)((*reinterpret_cast<void * *>(&::_g_thePlayer))), &chanceBSlot0);
        if ((*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21e8)) && (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc)) && (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc))->Ready() && !reinterpret_cast<::FUN_0087f3d0_shell *>(((*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc))))->FUN_0087f3d0() &&
            chanceBSlot0 >= ::RandomFloat(0.0f, 1.0f))
        {
            void* perk = ((void *)(::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(8))));
            if (perk && !reinterpret_cast<::fnv_008b8e90::FUN_008b8e90_shell *>(((*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc))))->FUN_008b8e90((::fnv_008b8e90::TESFaction *)(perk)))
            {
                V::Request* action = new V::Request();
                action->action = 25;
                action->mode = 5;
                action->type = 3;
                action->flag6 = 1;
                action->actor = (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc));
                action->flag4 = 1;
                reinterpret_cast<::SoundListView *>(&((*reinterpret_cast<::VatsShutdown::Queue *>(&::g_011f2250))))->AddCommand((::SoundListEntry *)(action));
                (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21e8))->Act((*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc)), 0, 1, 1, 0, 0, 1, 0);
            }
        }
        if ((*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21ec)) && (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc)) && (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc))->Ready() && !reinterpret_cast<::FUN_0087f3d0_shell *>(((*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc))))->FUN_0087f3d0() &&
            chanceASlot14 >= ::RandomFloat(0.0f, 1.0f))
        {
            V::Request* action = new V::Request();
            action->action = 25;
            action->mode = 5;
            action->type = 3;
            action->flag24 = 1;
            action->actor = (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc));
            action->flag4 = 1;
            reinterpret_cast<::SoundListView *>(&((*reinterpret_cast<::VatsShutdown::Queue *>(&::g_011f2250))))->AddCommand((::SoundListEntry *)(action));
            (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21ec))->Act((*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21cc)), 0, 1, 1, 0, 0, 1, 0);
        }
        reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::VatsShutdown::Queue *>(&::g_011f2250))))->CreateObject(4, 0);
    }
    else
    {
        reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::VatsShutdown::Queue *>(&::g_011f2250))))->CreateObject(0, 0);
        (*reinterpret_cast<unsigned char *>(&::DAT_011a3b31)) = 0;
        if ((*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21e8)))
        {
            delete (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21e8));
            (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21e8)) = 0;
        }
        if ((*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21ec)))
        {
            delete (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21ec));
            (*reinterpret_cast<::VatsShutdown::Actor * *>(&::DAT_011f21ec)) = 0;
        }
    }
    reinterpret_cast<::Target *>((V::FUN_00705910()))->FUN_00800ac0((::TargetActor *)(0), -1, 0);
    reinterpret_cast<::FUN_00800ed0_This *>((V::FUN_00705910()))->FUN_00800ed0();
    V::DAT_011db0cd = 0;
}
// @fnv 0x007f6fe0
ListItemTile* ListBoxInsert::AddItemTile(void* object, const char* text, ListItemCompare compare, const char* name)
{
    if (parent && (templateName || name))
    {
        ListItemTile* tile = ((::ListItemTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::ListItemMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((parent))->FUN_00a03c90()))))->FUN_00a1ddb0((::Tile *)(parent), (char *)(name ? name : templateName), (::Tile *)(0))));
        ListItemValue* value7;
        if (!reinterpret_cast<::FUN_00a00f30_shell *>((tile))->FUN_00a00f30(4010))
            reinterpret_cast<::Tile *>((tile))->Set(4010, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(4036, (char *)(text), true);
        if (compare)
        {
            reinterpret_cast<::FUN_00470440 *>(&(entries))->FUN_007a7eb0((::BGSPerkEntry *)(::ListItemData *)(new ListItemData(tile, &object)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(compare));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_00726090_cls *>(this)->FUN_00726090();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(entries))->FUN_00905820((void *)&(const ::ListItemData *const &)(new ListItemData(tile, &object)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile));
                reinterpret_cast<::fnv_00726530::FUN_00726530_t *>(this)->FUN_00726530();
            }
            reinterpret_cast<::Tile *>((tile))->Set(4012, itemCount++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat(::FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)) > 0.0)
        {
            value7 = ((::ListItemValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((parent))->FindTraitValue(4016)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value7))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((value7))->FUN_00a09130(2000, (::Tile *)(tile), 4016);
            reinterpret_cast<::P03Value *>((value7))->AppendFloatAction(2003, reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat(::FUN_00a00940((*reinterpret_cast<const char (*)[]>((void *)&::kListBoxNumFiltered)), -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value7))->FUN_00a09410(0);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}
struct ActionData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int type;
    int unk24;
    int unk28;
    int unk2c;
    Tile* tile;
};
struct FUN_007f6e50_This
{
    void AssignActionTiles(TargetList* apTargets);
};
struct VATSMenu_007ef7b0 : VATSMenu
{
    void FUN_007ef7b0(int aiID, int aiArg);
};

// @fnv 0x007ef7b0
void VATSMenu_007ef7b0::FUN_007ef7b0(int aiID, int aiArg)
{
    ::fnv_004b7210::FUN_004b7210();
    if (::FUN_004b71d0())
        return;

    switch (aiID)
    {
    case 2:
    case 3:
    case 4:
    case 5:
    case 30:
    case 31:
        m_bAdditionalStateFlag = true;
        break;
    }
}

struct ItemQ
{
    int unk00, unk04, unk08, iA, iB;
};
struct NodeQ
{
    bool FUN_008256d0();
};
struct ListQ
{
};
struct OwnQ
{
    int GetConsecutiveMatchCount();
};
namespace VatsQueueText {

struct Sound
{
    unsigned int unk0, unk4, unk8;
    Sound();
    ~Sound();
    Sound& operator=(const Sound& arOther);
};

struct SoundSource
{
    Sound FUN_00ad7550(const char* apEditorID, int aiFlags);
};

struct VATSTarget
{
};

struct VATSAction
{
    int iType;
    char pad04[8];
    VATSTarget* pTarget;
    char pad10[0x10];
    float fAPCost;
};

struct VATSQueue
{
    int FUN_0044ddc0();
};

struct Weapon
{
    int FUN_00446390();
};

struct WeaponHolder
{
    Weapon* FUN_0044ddc0();
};

struct ObjectName
{
    void* FUN_0043b1b0();
};

struct CombatTarget
{
    ObjectName* FUN_00413f40();
};

struct LimbInfo
{
};

struct LimbName
{
};

struct Process
{
    virtual void p00();
    virtual void p01();
    virtual void p02();
    virtual void p03();
    virtual void p04();
    virtual void p05();
    virtual void p06();
    virtual void p07();
    virtual void p08();
    virtual void p09();
    virtual void p0a();
    virtual void p0b();
    virtual void p0c();
    virtual void p0d();
    virtual void p0e();
    virtual void p0f();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p1a();
    virtual void p1b();
    virtual void p1c();
    virtual void p1d();
    virtual void p1e();
    virtual void p1f();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p2a();
    virtual void p2b();
    virtual void p2c();
    virtual void p2d();
    virtual void p2e();
    virtual void p2f();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p3a();
    virtual void p3b();
    virtual void p3c();
    virtual void p3d();
    virtual void p3e();
    virtual void p3f();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p4a();
    virtual void p4b();
    virtual void p4c();
    virtual void p4d();
    virtual void p4e();
    virtual void p4f();
    virtual void p50();
    virtual void p51();
    virtual WeaponHolder* FUN_vt148();
    virtual void q00();
    virtual void q01();
    virtual void q02();
    virtual void q03();
    virtual void q04();
    virtual void q05();
    virtual void q06();
    virtual void q07();
    virtual void q08();
    virtual void q09();
    virtual void q0a();
    virtual void q0b();
    virtual void q0c();
    virtual void q0d();
    virtual void q0e();
    virtual void q0f();
    virtual void q10();
    virtual CombatTarget* FUN_vt190(int aiPart);
};

struct PartSource
{
    virtual void c00();
    virtual void c01();
    virtual void c02();
    virtual void c03();
    virtual void c04();
    virtual void c05();
    virtual void c06();
    virtual void c07();
    virtual void c08();
    virtual void c09();
    virtual void c0a();
    virtual void c0b();
    virtual void c0c();
    virtual void c0d();
    virtual void c0e();
    virtual void c0f();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c1a();
    virtual void c1b();
    virtual void c1c();
    virtual void c1d();
    virtual void c1e();
    virtual void c1f();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c2a();
    virtual void c2b();
    virtual void c2c();
    virtual void c2d();
    virtual void c2e();
    virtual void c2f();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c3a();
    virtual void c3b();
    virtual void c3c();
    virtual void c3d();
    virtual void c3e();
    virtual void c3f();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c4a();
    virtual void c4b();
    virtual void c4c();
    virtual void c4d();
    virtual void c4e();
    virtual void c4f();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual void c53();
    virtual void c54();
    virtual void c55();
    virtual void c56();
    virtual void c57();
    virtual void c58();
    virtual void c59();
    virtual void c5a();
    virtual void c5b();
    virtual void c5c();
    virtual void c5d();
    virtual void c5e();
    virtual void c5f();
    virtual LimbInfo* FUN_vt180();
};

struct VATSActor
{
    virtual void a00();
    virtual void a01();
    virtual void a02();
    virtual void a03();
    virtual void a04();
    virtual void a05();
    virtual void a06();
    virtual void a07();
    virtual void a08();
    virtual void a09();
    virtual void a0a();
    virtual void a0b();
    virtual void a0c();
    virtual void a0d();
    virtual void a0e();
    virtual void a0f();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a1a();
    virtual void a1b();
    virtual void a1c();
    virtual void a1d();
    virtual void a1e();
    virtual void a1f();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a2a();
    virtual void a2b();
    virtual void a2c();
    virtual void a2d();
    virtual void a2e();
    virtual void a2f();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a3a();
    virtual void a3b();
    virtual void a3c();
    virtual void a3d();
    virtual void a3e();
    virtual void a3f();
    virtual bool IsActor();
    virtual void b00();
    virtual void b01();
    virtual void b02();
    virtual void b03();
    virtual void b04();
    virtual void b05();
    virtual void b06();
    virtual void b07();
    virtual void b08();
    virtual void b09();
    virtual void b0a();
    virtual void b0b();
    virtual void b0c();
    virtual void b0d();
    virtual void b0e();
    virtual void b0f();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b1a();
    virtual void b1b();
    virtual void b1c();
    virtual void b1d();
    virtual void b1e();
    virtual void b1f();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b2a();
    virtual void b2b();
    virtual void b2c();
    virtual void b2d();
    virtual void b2e();
    virtual void b2f();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual int FUN_vt1e8();
};

struct PlayerLink
{
};

struct QueueTarget
{
    char pad00[4];
    int iKind;
};

struct TargetList
{
    QueueTarget** FUN_006815c0();
};

struct VATSTargets
{
    TargetList* FindListEntryForTarget(VATSActor* apActor);
};

struct GameText
{
    const char* FUN_00403df0();
};

extern intptr_t DAT_011db198;

struct Tile
{
};

struct QueueList
{
    char data[0x30];
};

struct LimbSelection
{
    char pad00[0x20];
    int m_iLimbIndex;
};

void FUN_00705780();
int __cdecl FUN_00406d50(char* apDest, unsigned int auiSize, const char* apSrc);

struct VATSMenuQueue
{
    char pad00[0x38];
    Tile* pAPTile;
    char pad3c[8];
    Tile* pQueueTile;
    char pad48[0x68];
    QueueList kQueue;
    float fCurrentAP;
    float fMaxAP;
    char pade8[0x18];
    LimbSelection* pLimbs;
    char pad104[4];
    int iSelected;

    int FUN_007f3bf0(int aiLimb);
    void UpdateQueueEntry(VATSAction* apAction, bool abAddEntry, bool abShowDetail);
};

// Adds an entry for apAction or removes the last queued item, updates AP, and refreshes queue tile text.
// @fnv 0x007efa10
void VATSMenuQueue::UpdateQueueEntry(VATSAction* apAction, bool abAddEntry, bool abShowDetail)
{
    if (apAction == 0)
    {
        iSelected = 0;
        float m_fPathingCostCur = ((::VatsQueueText::VATSAction *)(reinterpret_cast<::MyList *>(&((*reinterpret_cast<::VatsQueueText::VATSQueue *>(&::g_011f2250))))->FUN_009c71f0())) ? ((::VatsQueueText::VATSAction *)(reinterpret_cast<::MyList *>(&((*reinterpret_cast<::VatsQueueText::VATSQueue *>(&::g_011f2250))))->FUN_009c71f0()))->fAPCost : 0.0f;
        int iType = 0x16;
        bool bFlag = false;
        reinterpret_cast<::B9C88A0List *>(&((*reinterpret_cast<::VatsQueueText::VATSQueue *>(&::g_011f2250))))->PopLastItem(&iType, &bFlag);
        reinterpret_cast<::VATSMenuX *>(this)->UpdateLimbTiles();
        if (iType == 0x16 && ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::VatsQueueText::VATSQueue *>(&::g_011f2250))))->GetName())) == 2)
            FUN_00705780();
        if (!((bool)(::fnv_009526b0::FUN_009526b0())))
        {
            WeaponHolder* pHolder = ((::VatsQueueText::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VatsQueueText::PlayerLink * *>(&::_g_thePlayer))))->GetBaseTexture()))->FUN_vt148();
            Weapon* pWeapon = pHolder ? ((::VatsQueueText::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((pHolder))->GetName())) : 0;
            fCurrentAP = fCurrentAP + m_fPathingCostCur;
        }
        if (fCurrentAP > fMaxAP)
            fCurrentAP = fMaxAP;
        reinterpret_cast<::Tile *>((pQueueTile))->Set(0xfaf, 1);
        if (iType != 9)
        {
            Tile* pLast = ((::VatsQueueText::Tile *)(reinterpret_cast<::ListBox *>(&(kQueue))->FUN_007f6fb0()));
            if (pLast && !::FUN_00408b20(::FUN_0066ddc0(9), reinterpret_cast<::FUN_00a011f0_shell *>((pLast))->FUN_00a011f0(0xfc4)))
                reinterpret_cast<::VATSLookup *>(&(kQueue))->FUN_007f7280(::GetRaceCount((char *)&(kQueue)) - 1, false);
        }
        reinterpret_cast<::VATSLookup *>(&(kQueue))->FUN_007f7280(::GetRaceCount((char *)&(kQueue)) - 1, false);
        Sound kSoundCur;
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::VatsQueueText::Sound &)(kSoundCur))->operator=((const ::SoundPlaybackHandle &)((const ::VatsQueueText::Sound &)(((::VatsQueueText::SoundSource *)(::FUN_00453a70()))->FUN_00ad7550("UIMenuCancel", 0x121))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(kSoundCur))->FUN_00ad8830(0);
    }
    else
    {
        SoundSource* pAudio = ((::VatsQueueText::SoundSource *)(::FUN_00ad9060()));
        Sound kMoveSound;
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::VatsQueueText::Sound &)(kMoveSound))->operator=((const ::SoundPlaybackHandle &)((const ::VatsQueueText::Sound &)((*(::VatsQueueText::Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((pAudio))->ResolveAudioHandle((::Handle_ae5680 *)("UIVATSMove"), 0x121, {}))))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(kMoveSound))->FUN_00ad8830(0);
        TargetList* pTargetsCur = (*reinterpret_cast<::VatsQueueText::VATSTargets * *>(&::DAT_011db0d4))->FindListEntryForTarget((*reinterpret_cast<::VatsQueueText::VATSActor * *>(&::DAT_011f21cc)));
        WeaponHolder* pOwnerOut = ((::VatsQueueText::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VatsQueueText::PlayerLink * *>(&::_g_thePlayer))))->GetBaseTexture()))->FUN_vt148();
        Weapon* pQueueWeaponTmp = pOwnerOut ? ((::VatsQueueText::Weapon *)(reinterpret_cast<::Twin_0044ddc0 *>((pOwnerOut))->GetName())) : 0;
        Tile* pEntry;
        fCurrentAP = fCurrentAP - apAction->fAPCost;
        char acTextBase[260];
        if (::FUN_0066dde0(apAction->iType))
        {
            DAT_011db198++;
            if (::DAT_011a59f0 != -1 && (*reinterpret_cast<::VatsQueueText::VATSActor * *>(&::DAT_011f21cc))->IsActor() && pQueueWeaponTmp && !::FUN_006450c0((::TESObjectWEAP *)(pQueueWeaponTmp)) &&
                pQueueWeaponTmp->FUN_00446390() != 10)
            {
                LimbInfo* pLimbInfoTmp = ((::VatsQueueText::PartSource *)(reinterpret_cast<::Actor *>(((*reinterpret_cast<::VatsQueueText::VATSActor * *>(&::DAT_011f21cc))))->GetActorBase()))->FUN_vt180();
                LimbName* pLimb = (LimbName*)((void *)(reinterpret_cast<::FUN_005e5130_Class *>((pLimbInfoTmp))->FUN_005e5130(FUN_007f3bf0(pLimbs->m_iLimbIndex))));
                if (pLimb)
                {
                    ::TaskQueueInterface::CopyStringToBuffer(acTextBase, 260, reinterpret_cast<::FUN_0055d520_shell *>((apAction->pTarget))->FUN_0055d520());
                    FUN_00406d50(acTextBase, 260, ": ");
                    if (((const char *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((pLimb))->FUN_006838b0())))
                        FUN_00406d50(acTextBase, 260, ((const char *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((pLimb))->FUN_006838b0())));
                    else
                        FUN_00406d50(acTextBase, 260, "---");
                }
                else
                {
                    return;
                }
            }
            else if ((*pTargetsCur->FUN_006815c0())->iKind != 2)
            {
                CombatTarget* pTarget = ((::VatsQueueText::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::VatsQueueText::VATSActor * *>(&::DAT_011f21cc))))->GetBaseTexture()))->FUN_vt190((*reinterpret_cast<::VatsQueueText::VATSActor * *>(&::DAT_011f21cc))->FUN_vt1e8());
                if (pTarget && pQueueWeaponTmp && !::FUN_006450c0((::TESObjectWEAP *)(pQueueWeaponTmp)) &&
                    pQueueWeaponTmp->FUN_00446390() != 10)
                {
                    ::TaskQueueInterface::CopyStringToBuffer(acTextBase, 260, reinterpret_cast<::FUN_0055d520_shell *>((apAction->pTarget))->FUN_0055d520());
                    FUN_00406d50(acTextBase, 260, ": ");
                    if (pTarget->FUN_00413f40()->FUN_0043b1b0())
                        FUN_00406d50(acTextBase, 260, ::FUN_007f0360(2));
                    else
                        FUN_00406d50(acTextBase, 260, "---");
                }
                else
                {
                    ::TaskQueueInterface::CopyStringToBuffer(acTextBase, 260, reinterpret_cast<::FUN_0055d520_shell *>((apAction->pTarget))->FUN_0055d520());
                }
            }
            else
            {
                ::TaskQueueInterface::CopyStringToBuffer(acTextBase, 260, reinterpret_cast<::FUN_0055d520_shell *>((apAction->pTarget))->FUN_0055d520());
            }
            if (abShowDetail)
            {
                if (pQueueWeaponTmp && ((int)(reinterpret_cast<::FUN_008d85e0_Class *>((pQueueWeaponTmp))->GetUnk15C())) == 0x26)
                {
                    FUN_00406d50(acTextBase, 260, ": ");
                    FUN_00406d50(acTextBase, 260, ((const char *)(reinterpret_cast<::fnv_00522be0::FUN_00522be0_shell *>((pQueueWeaponTmp))->FUN_00522be0())));
                }
                else if (apAction->iType == 0x11)
                {
                    FUN_00406d50(acTextBase, 260, ": ");
                    FUN_00406d50(acTextBase, 260, (*reinterpret_cast<::VatsQueueText::GameText *>(&::g_011d46c0)).FUN_00403df0());
                }
                else if (apAction->iType == 0x15)
                {
                    FUN_00406d50(acTextBase, 260, ": ");
                    FUN_00406d50(acTextBase, 260, (*reinterpret_cast<::VatsQueueText::GameText *>(&::g_011d2754)).FUN_00403df0());
                }
                else if (apAction->iType == 0x14)
                {
                    FUN_00406d50(acTextBase, 260, ": ");
                    FUN_00406d50(acTextBase, 260, (*reinterpret_cast<::VatsQueueText::GameText *>(&::g_011d46d8)).FUN_00403df0());
                }
            }
            if (abAddEntry)
            {
                char acEntry[260];
                ::TaskQueueInterface::CopyStringToBuffer(acEntry, 260, acTextBase);
                pEntry = ((::VatsQueueText::Tile *)(reinterpret_cast<::ListBoxInsert *>(&(kQueue))->AddItemTile((void *)(DAT_011db198), (const char *)(0), (int (*)(ListItemData *, ListItemData *))(0), (const char *)(0))));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pEntry))->FUN_00a01350(0xfc4, (char *)(acEntry), true);
                DAT_011db198++;
                ::TaskQueueInterface::CopyStringToBuffer(acTextBase, 260, ::FUN_0066ddc0(9));
            }
        }
        else
        {
            DAT_011db198++;
            ::TaskQueueInterface::CopyStringToBuffer(acTextBase, 260, ::FUN_0066ddc0(apAction->iType));
        }
        char acLineTmp[260];
        ::TaskQueueInterface::CopyStringToBuffer(acLineTmp, 260, acTextBase);
        pEntry = ((::VatsQueueText::Tile *)(reinterpret_cast<::ListBoxInsert *>(&(kQueue))->AddItemTile((void *)(DAT_011db198), (const char *)(0), (int (*)(ListItemData *, ListItemData *))(0), (const char *)(0))));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pEntry))->FUN_00a01350(0xfc4, (char *)(acLineTmp), true);
    }
    if (::GetRaceCount((char *)&(kQueue)) == 0)
        reinterpret_cast<::Tile *>((pAPTile))->Set(0xfaf, 0);
    else
        reinterpret_cast<::Tile *>((pAPTile))->Set(0xfaf, 1);
}

}

struct AmmoPlayer
{
};
struct AmmoEntry
{
    WeaponX* FUN_0044ddc0();
};
struct AmmoWeapon
{
};
struct AmmoInventory
{
};
struct AmmoCommand
{
    int action;
    int unk04;
    unsigned char shots;
};
struct AmmoCommandNode
{
    bool FUN_008256d0();
};
struct AmmoQueue
{
};


namespace fnv_007f3070 {
struct AimVector
{
    float x, y, z;
    AimVector();
    AimVector(float, float, float);
};
struct AimMatrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    AimVector FUN_004b4500(const AimVector&);
};
struct AimTransform
{
    const AimMatrix& FUN_00461130();
};
struct AimCamera
{
    AimTransform* FUN_006629f0();
};
struct AimTile
{
};
struct AimLimb
{
    int unk00, unk04;
    AimVector position;
    int unk14, unk18, unk1c;
    int id;
    int unk24, unk28, unk2c;
    AimTile* tile;
    float angle;
};
struct AimLimbs
{
    AimLimb* data;
    AimLimbs* next;
    bool FUN_008256d0();
    AimLimb** FUN_006815c0();
};
struct AimWeapon
{
};
struct AimEntry
{
    AimWeapon* FUN_0044ddc0();
};
struct AimProcess
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual AimEntry* GetLoadedForm();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual bool IsMelee();
};
struct AimBodyData
{
    int unk00;
    int flags;
};
struct AimBody
{
};
struct AimActor
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual AimBody* GetBody();
};
struct AimTarget
{
    AimActor* actor;
    int type;
    AimLimbs limbs;
};
struct AimTargets
{
    AimTarget** FUN_006815c0();
};
struct AimInput
{
};
struct AimInputOwner
{
};
struct AimManager
{
};
struct AimMode
{
    int FUN_0044ddc0();
};
struct AimMenu
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    AimLimb* current;
    int unk104, unk108;
    bool stickReset;
    AimTargets* FindListEntryForTarget(void*);
    int FUN_007f3bf0(int);
    void FUN_007f3070();
};
// Updates the current aim limb selection based on aim mode, input stick state, and target body data, cycling through limbs on key input.
// @fnv 0x007f3070
void AimMenu::FUN_007f3070()
{
    AimInput* input5 = ((::fnv_007f3070::AimInput *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_007f3070::AimInputOwner * *>(&::g_osGlobals))))->FUN_00877720()));
    AimEntry* entry1 = ((::fnv_007f3070::AimProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007f3070::AimActor * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetLoadedForm();
    AimWeapon* weapon1 = entry1 ? ((::fnv_007f3070::AimWeapon *)(reinterpret_cast<::Twin_0044ddc0 *>((entry1))->GetName())) : 0;
    AimTargets* target20 = FindListEntryForTarget(::DAT_011f21cc);
    if (((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((AimMode*)&(*reinterpret_cast<int *>(&::g_011f2250)))))->GetName())) != 3 &&
        (((::fnv_007f3070::AimProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::fnv_007f3070::AimActor * *>(&::_g_thePlayer))))->GetBaseTexture()))->IsMelee() || (*target20->FUN_006815c0())->type == 2 || !weapon1 ||
         ::FUN_006450c0((::TESObjectWEAP *)(weapon1))))
    {
        if ((*target20->FUN_006815c0())->type == 2)
            ::DAT_011a59f0 = -1;
        else
        {
            AimBody* body8 = ((::fnv_007f3070::AimActor *)(reinterpret_cast<::Actor *>(((*target20->FUN_006815c0())->actor))->GetActorBase()))->GetBody();
            AimBodyData* data15 = ((::fnv_007f3070::AimBodyData *)(::FUN_006a9540((char *)(body8))));
            if (data15->flags)
                ::DAT_011a59f0 = 25;
            else
                ::DAT_011a59f0 = -1;
        }
    }
    else if ((((void *)(::fnv_004b7210::FUN_004b7210())), ::FUN_004b71d0()))
    {
        int horizontal8 = 0, vertical3 = 0;
        horizontal8 = reinterpret_cast<::FUN_00a23390_t *>((input5))->GetAxisState(0, 7);
        vertical3 = reinterpret_cast<::FUN_00a23390_t *>((input5))->GetAxisState(0, 8);
        int maximum26 = 32767;
        if (::std::abs(vertical3) < maximum26 / 4 && ::std::abs(horizontal8) < maximum26 / 4)
            stickReset = true;
        bool left9 = true;
        if (horizontal8 > 0)
            left9 = false;
        AimMatrix rotation18 = ((AimCamera*)((::BSFaceGenNiNode *)(::FUN_0045c670())))->FUN_006629f0()->FUN_00461130();
        AimVector direction19(0.0f, (float)-vertical3, (float)-horizontal8);
        direction19 = rotation18.FUN_004b4500(direction19);
        reinterpret_cast<::FUN_004a0c10_s *>(&(direction19))->FUN_004a0c10();
        if (stickReset &&
            (::std::abs(vertical3) > maximum26 * 3 / 4 || ::std::abs(horizontal8) > maximum26 * 3 / 4))
        {
            float bestAngle50 = ::DAT_0106b158;
            float bestDistance11 = ::DAT_01016970;
            int selection8 = ::DAT_011a59f0;
            AimLimbs* limb9 = &(*FindListEntryForTarget(::DAT_011f21cc)->FUN_006815c0())->limbs;
            AimLimb* original31 = current;
            bool found2 = false;
            while (limb9 && !limb9->FUN_008256d0())
            {
                AimVector delta14;
                delta14 = (*(::fnv_007f3070::AimVector *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(original31->position))->FUN_00439ef0((::NiPoint3 *)&((*limb9->FUN_006815c0())->position), *(const ::NiPoint3 *)nullptr)));
                float distance9 = reinterpret_cast<::NiPoint3 *>(&(delta14))->ComputeMagnitude();
                reinterpret_cast<::FUN_004a0c10_s *>(&(delta14))->FUN_004a0c10();
                float angle3 = ::FUN_004f6e40(reinterpret_cast<::FUN_004b6190_shell *>(&(direction19))->DotProduct((void *)&(delta14)));
                angle3 *= ::DAT_0102f248;
                AimLimbs* duplicate12 = 0;
                AimLimbs* scan5 = &(*FindListEntryForTarget(::DAT_011f21cc)->FUN_006815c0())->limbs;
                while (scan5 && !scan5->FUN_008256d0())
                {
                    if (FUN_007f3bf0((*scan5->FUN_006815c0())->id) == FUN_007f3bf0((*limb9->FUN_006815c0())->id))
                        duplicate12 = scan5;
                    scan5 = ((::fnv_007f3070::AimLimbs *)(scan5->next));
                }
                (*limb9->FUN_006815c0())->angle = angle3;
                if (angle3 < ::DAT_010357e8 && distance9 != ::_DAT_01012060 && distance9 < bestDistance11 && duplicate12 &&
                    *duplicate12->FUN_006815c0() == *limb9->FUN_006815c0())
                {
                    found2 = true;
                    bestDistance11 = distance9;
                    bestAngle50 = angle3;
                    selection8 = FUN_007f3bf0((*limb9->FUN_006815c0())->id);
                    stickReset = false;
                    reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((current->tile))->RemoveFadeItemsForTile(4009);
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((current->tile))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((current->tile))->GetFloat(4009), ::DAT_01023cd8, ::DAT_0101df44, 0);
                    current = *limb9->FUN_006815c0();
                }
                limb9 = ((::fnv_007f3070::AimLimbs *)(limb9->next));
            }
            if (!found2)
            {
                bestAngle50 = ::DAT_0106b158;
                limb9 = &(*FindListEntryForTarget(::DAT_011f21cc)->FUN_006815c0())->limbs;
                while (limb9 && !limb9->FUN_008256d0())
                {
                    AimLimbs* duplicateB53 = 0;
                    AimLimbs* scanB15 = &(*FindListEntryForTarget(::DAT_011f21cc)->FUN_006815c0())->limbs;
                    while (scanB15 && !scanB15->FUN_008256d0())
                    {
                        if (FUN_007f3bf0((*scanB15->FUN_006815c0())->id) == FUN_007f3bf0((*limb9->FUN_006815c0())->id))
                            duplicateB53 = scanB15;
                        scanB15 = ((::fnv_007f3070::AimLimbs *)(scanB15->next));
                    }
                    if ((*limb9->FUN_006815c0())->angle < bestAngle50 && original31 != *limb9->FUN_006815c0() &&
                        duplicateB53 && *duplicateB53->FUN_006815c0() == *limb9->FUN_006815c0())
                    {
                        bestAngle50 = (*limb9->FUN_006815c0())->angle;
                        selection8 = FUN_007f3bf0((*limb9->FUN_006815c0())->id);
                        stickReset = false;
                        reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((current->tile))->RemoveFadeItemsForTile(4009);
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((current->tile))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((current->tile))->GetFloat(4009), ::DAT_01023cd8, ::DAT_0101df44,
                                                    0);
                        current = *limb9->FUN_006815c0();
                    }
                    limb9 = ((::fnv_007f3070::AimLimbs *)(limb9->next));
                }
            }
            ::DAT_011a59f0 = selection8;
        }
    }
    else if (reinterpret_cast<::FUN_00a24180_shell *>((input5))->FUN_00a24180(17, 1) || ((int)(reinterpret_cast<::FUN_0070ec70_class *>((((AimManager*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0070ec70())) > ::_DAT_01012060)
    {
        while (true)
        {
            AimLimbs* cursor = &(*FindListEntryForTarget(::DAT_011f21cc)->FUN_006815c0())->limbs;
            while (cursor && !cursor->FUN_008256d0())
            {
                if (((::fnv_007f3070::AimLimbs *)(cursor->next)) && *cursor->FUN_006815c0() == current)
                {
                    current = *((::fnv_007f3070::AimLimbs *)(cursor->next))->FUN_006815c0();
                    break;
                }
                else if (!((::fnv_007f3070::AimLimbs *)(cursor->next)))
                    current = *(*FindListEntryForTarget(::DAT_011f21cc)->FUN_006815c0())->limbs.FUN_006815c0();
                cursor = ((::fnv_007f3070::AimLimbs *)(cursor->next));
            }
            ::DAT_011a59f0 = FUN_007f3bf0(current->id);
            if (reinterpret_cast<::FUN_00a01230_shell *>((current->tile))->IsTraitNonZero(4003))
                break;
        }
        ::fnv_007ec3a0::UpdateVatsTargetHighlight(0);
    }
    else if (reinterpret_cast<::FUN_00a24180_shell *>((input5))->FUN_00a24180(31, 1) || ((int)(reinterpret_cast<::FUN_0070ec70_class *>((((AimManager*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0070ec70())) < ::_DAT_01012060)
    {
        while (true)
        {
            AimLimbs* cursorB = &(*FindListEntryForTarget(::DAT_011f21cc)->FUN_006815c0())->limbs;
            while (cursorB && !cursorB->FUN_008256d0())
            {
                if (((::fnv_007f3070::AimLimbs *)(cursorB->next)) && *((::fnv_007f3070::AimLimbs *)(cursorB->next))->FUN_006815c0() == current)
                {
                    current = *cursorB->FUN_006815c0();
                    break;
                }
                else if (!((::fnv_007f3070::AimLimbs *)(cursorB->next)))
                    current = *cursorB->FUN_006815c0();
                cursorB = ((::fnv_007f3070::AimLimbs *)(cursorB->next));
            }
            ::DAT_011a59f0 = FUN_007f3bf0(current->id);
            if (reinterpret_cast<::FUN_00a01230_shell *>((current->tile))->IsTraitNonZero(4003))
                break;
        }
        ::fnv_007ec3a0::UpdateVatsTargetHighlight(0);
    }
}
}  // namespace fnv_007f3070

struct Obj548;
struct StepObj;
struct MidObj;
class NiPoint2;
struct Vec3
{
    float x;
    float y;
    float z;
    Vec3 ApplyScaled(float scale) const;
public:
    Vec3();
};
// Scans the g_011db150 list for the entry whose stored TESObjectREFR matches apTarget and returns it, or null if none matches.
// @fnv 0x007f3c90
BSSimpleList<ItemListContainer*>* StandIn::FindListEntryForTarget(TESObjectREFR* apTarget)
{
    BSSimpleList<ItemListContainer*>* piter;
    if (!apTarget)
        return 0;
    piter = (BSSimpleList<ItemListContainer*>*)&::g_011db150;
    while (piter && !piter->FUN_008256d0())
    {
        if (*(TESObjectREFR**)(*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(piter)->m_item))) == apTarget)
            return piter;
        piter = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((piter))->FUN_00726070()));
    }
    return 0;
}
// @fnv 0x007f3cf0
BSSimpleList<ItemListContainer*>* FUN_007f3cf0_This::FindEntryForRef()
{
    BSSimpleList<ItemListContainer*>* ptarget = FindListEntryForTarget((TESObjectREFR*)::DAT_011f21cc);
    BSSimpleList<ItemListContainer*>* piter = (BSSimpleList<ItemListContainer*>*)(void*)*(char**)(char*)((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(ptarget)->m_item)) + 8;
    while (piter && !piter->FUN_008256d0())
    {
        if ((TESObjectREFR*)((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(piter)->m_item))[0] == m_pTargetChance)
            return piter;
        piter = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((piter))->FUN_00726070()));
    }
    return 0;
}
// @fnv 0x007f51b0
void FUN_007f51b0_shell::FUN_007f51b0(FUN_005df510_shell* a1)
{
    NiPoint3 direction = ((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData()->GetWorldTranslation();

    NiPoint3 result;

    result.x = direction.y * direction.y + direction.z * direction.z;
    result.y = -direction.x * direction.y;
    result.z = -direction.x * direction.z;
    a1->FUN_005df510(0, &result.x);

    result.x = -direction.x * direction.y;
    result.y = direction.x * direction.x + direction.z * direction.z;
    result.z = -direction.y * direction.z;
    a1->FUN_005df510(1, &result.x);

    result.x = -direction.x * direction.z;
    result.y = -direction.y * direction.z;
    result.z = direction.x * direction.x + direction.y * direction.y;
    a1->FUN_005df510(2, &result.x);
}
// @fnv 0x007f7280
bool VATSLookup::FUN_007f7280(unsigned int index, bool byPosition)
{
    if (items.FUN_008256d0())
    {
        return false;
    }
    VATSLookupList* previous;
    VATSLookupList* current = this ? &items : 0;
    previous = this ? &items : 0;
    if (byPosition)
    {
        unsigned int counter = 0;
        while (current && counter++ != index)
        {
            previous = current;
            current = ((::VATSLookupList *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
        }
    }
    else
    {
        while (current && reinterpret_cast<::TileListBoxCalls *>(((**((::ItemListElement ***)(&reinterpret_cast<::SimpleListNodeView*>(current)->m_item)))))->GetFloat({}) != index)
        {
            previous = current;
            current = ((::VATSLookupList *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
        }
    }
    return reinterpret_cast<::RemoveView *>(this)->RemoveNodeFromList((::RemoveNode *)(current), (::RemoveNode *)(previous));
}
// Handles a VATS menu key press: updates left/right state, plays sounds, cycles the selected target and its items, and refreshes the menu.
// @fnv 0x007eecb0
void MenuX::HandleInput(int key, int held)
{
    RefX* item = ((::InputProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::PlayerX * *>(&::_g_thePlayer))))->GetBaseTexture()))->v82();
    uintptr_t flags = item ? ((uintptr_t)(reinterpret_cast<::InventoryEntryFields *>((item))->pObject)) : 0;
    if (left)
    {
        if (FUN_007f4bb0())
        {
            reinterpret_cast<::TargetSelectHelper *>(this)->SelectTarget(true);
            left = false;
            return;
        }
        left = false;
    }
    if (right)
    {
        if (::fnv_007f4c00::FUN_007f4c00())
        {
            reinterpret_cast<::TargetSelectHelper *>(this)->SelectTarget(false);
            right = false;
            return;
        }
        right = false;
    }
    SoundX sound7;
    ::fnv_004b7210::FUN_004b7210();
    if (::FUN_004b71d0() && !targetStick)
        return;
    ItemsX* weapon;
    TargetsX* target4 = reinterpret_cast<TargetsX*>(&::g_011db150);
    switch (key)
    {
    case 2:
        if (reinterpret_cast<TargetsX*>(&::g_011db150)->GetSize() <= 1)
        {
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::SoundX &)(sound7))->operator=((const ::SoundPlaybackHandle &)((const ::SoundX &)(((::InputAudioX *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIVATSEnterFail", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound7))->FUN_00ad8830(false);
            return;
        }
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::SoundX &)(sound7))->operator=((const ::SoundPlaybackHandle &)((const ::SoundX &)(((::InputAudioX *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIVATSSelectTarget", 0x121))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(sound7))->FUN_00ad8830(false);
        target4 = reinterpret_cast<TargetsX*>(&::g_011db150);
        while (target4 && !target4->FUN_008256d0())
        {
            weapon = &(*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->items;
            while (weapon && !weapon->FUN_008256d0() && (*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->tile)
            {
                reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>(((*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->tile))->RemoveFadeItemsForTile(0xfa9);
                reinterpret_cast<::Tile *>(((*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->tile))->Set(0xfa9, 0);
                weapon = ((::ItemsX *)(weapon->next));
            }
            target4 = ((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070()));
        }
        target4 = reinterpret_cast<TargetsX*>(&::g_011db150);
        while (target4)
        {
            if ((*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->ref && (*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->ref->v116() && ((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070())) &&
                (*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070())))->m_item)))->ref == (*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)))
            {
                (*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)) = (*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->ref;
                ItemsX* items = &(*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->items;
                ItemsX* found = FindListEntryByValue(0x1a);
                if ((*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->type == 1 && found)
                    reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(found)->m_item));
                else
                    reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(items)->m_item));
                break;
            }
            else if (!((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070())))
            {
                (*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)) = (*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->ref;
                ItemsX* found = FindListEntryByValue(0x1a);
                if ((*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->type == 1 && found)
                    reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(found)->m_item));
                else
                    reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(&((*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->items))->m_item));
            }
            target4 = ((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070()));
        }
        FUN_007f3bd0(0);
        if (!(*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))))->m_item)))->special)
        {
            ItemsX* weapon = &(*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))))->m_item)))->items;
            while (weapon && !weapon->FUN_008256d0())
            {
                (*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->selected = false;
                (*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->queued = false;
                weapon = ((::ItemsX *)(weapon->next));
            }
        }
        if (!(*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(&((*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))))->m_item)))->items))->m_item)))->tile)
            reinterpret_cast<::FUN_007f6e50_This *>(this)->AssignActionTiles((::TargetList *)(::TargetsX *)(FindListEntryForTarget((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)))));
        break;
    case 3:
        if (reinterpret_cast<TargetsX*>(&::g_011db150)->GetSize() <= 1)
        {
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::SoundX &)(sound7))->operator=((const ::SoundPlaybackHandle &)((const ::SoundX &)(((::InputAudioX *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIVATSEnterFail", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound7))->FUN_00ad8830(false);
            return;
        }
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::SoundX &)(sound7))->operator=((const ::SoundPlaybackHandle &)((const ::SoundX &)(((::InputAudioX *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIVATSSelectTarget", 0x121))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(sound7))->FUN_00ad8830(false);
        target4 = reinterpret_cast<TargetsX*>(&::g_011db150);
        while (target4 && !target4->FUN_008256d0())
        {
            weapon = &(*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->items;
            while (weapon && !weapon->FUN_008256d0() && (*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->tile)
            {
                reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>(((*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->tile))->RemoveFadeItemsForTile(0xfa9);
                reinterpret_cast<::Tile *>(((*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->tile))->Set(0xfa9, 0);
                weapon = ((::ItemsX *)(weapon->next));
            }
            target4 = ((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070()));
        }
        target4 = reinterpret_cast<TargetsX*>(&::g_011db150);
        while (target4)
        {
            if ((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)) == (*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->ref)
            {
                if (((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070())) && (*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070())))->m_item)))->ref &&
                    (*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070())))->m_item)))->ref->v116())
                {
                    (*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)) = (*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070())))->m_item)))->ref;
                    ItemsX* items = &(*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070())))->m_item)))->items;
                    ItemsX* found = FindListEntryByValue(0x1a);
                    if ((*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->type == 1 && found)
                        reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(found)->m_item));
                    else
                        reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(items)->m_item));
                    break;
                }
                else
                {
                    (*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)) = (*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<TargetsX*>(&::g_011db150))->m_item)))->ref;
                    ItemsX* found = FindListEntryByValue(0x1a);
                    if ((*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(target4)->m_item)))->type == 1 && found)
                        reinterpret_cast<MenuX*>(DAT_011db0d4)->current = *((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(found)->m_item));
                    else
                        reinterpret_cast<MenuX*>(DAT_011db0d4)->current =
                            *((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(&((*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<TargetsX*>(&::g_011db150))->m_item)))->items))->m_item));
                }
            }
            target4 = ((::TargetsX *)(reinterpret_cast<::Callees *>((target4))->FUN_00726070()));
        }
        FUN_007f3bd0(0);
        if (!(*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))))->m_item)))->special)
        {
            ItemsX* weapon = &(*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))))->m_item)))->items;
            while (weapon && !weapon->FUN_008256d0())
            {
                (*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->selected = false;
                (*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(weapon)->m_item)))->queued = false;
                weapon = ((::ItemsX *)(weapon->next));
            }
        }
        if (!(*((::ItemX **)(&reinterpret_cast<::SimpleListNodeView*>(&((*((::InputTargetX **)(&reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))))->m_item)))->items))->m_item)))->tile)
            reinterpret_cast<::FUN_007f6e50_This *>(this)->AssignActionTiles((::TargetList *)(::TargetsX *)(FindListEntryForTarget((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)))));
        break;
    case 4:
        if (!closing)
            FUN_00705780();
        break;
    case 30:
        if (!closing)
            DAT_011db0b2 = true;
        break;
    case 31:
        if (!closing)
            DAT_011db0b3 = true;
        break;
    case 5:
        if (!closing && ((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<VatsX*>(&(*reinterpret_cast<int *>(&::g_011f2250)))))->GetName())) == 2 && heading)
        {
            UpdateQueueEntry(0, 0, 0);
            reinterpret_cast<MenuX*>(DAT_011db0d4)->damage = reinterpret_cast<::VATSMenuX *>((reinterpret_cast<MenuX*>(DAT_011db0d4)))->FUN_007f48e0();
        }
        break;
    }
    if ((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)) && (*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))->v64())
        DAT_011a59f0 = 25;
    ::FUN_007eb920((::WeaponPrompt *)(flags));
    FUN_007f3070();
    if (((void *)(reinterpret_cast<::FUN_005d8710_shell *>((reinterpret_cast<VatsX*>(&(*reinterpret_cast<int *>(&::g_011f2250)))))->FUN_005d8710())) && (*reinterpret_cast<::RefX * *>(&::DAT_011f21cc)))
        reinterpret_cast<::fnv_009c9ae0::VATS9c9 *>((reinterpret_cast<VatsX*>(&(*reinterpret_cast<int *>(&::g_011f2250)))))->FUN_009c9ae0((::fnv_009c9ae0::ActorObj9c9 *)((*reinterpret_cast<::RefX * *>(&::DAT_011f21cc))));
}
// Walks the marker list, projecting each non-hidden marker's position to screen space and returning true if any lands inside the viewport.
// @fnv 0x007f05b0
bool FUN_007f05b0_Menu::HasVisibleMarkerOnScreen()
{
    VisList* pList;
    VisNode* pNode5;

    pList = FindListEntryForTarget((*reinterpret_cast<int *>(&::DAT_011f21cc)));
    pNode5 = (VisNode*)&((::VisMarkerHolder *)(reinterpret_cast<::SimpleListNodeView*>(pList)->m_item))->pFirst;
    while (pNode5 && !pNode5->FUN_008256d0())
    {
        if (!((::VisMarker *)(reinterpret_cast<::SimpleListNodeView*>(pNode5)->m_item))->bHidden)
        {
            VisPoint3 kPos2 = ((::VisMarker *)(reinterpret_cast<::SimpleListNodeView*>(pNode5)->m_item))->kPos;
            float fX2 = 0.0f;
            float fY3 = 0.0f;
            reinterpret_cast<::ScreenCamera *>((((::VisCameraNode *)(::FUN_0045c670()))->FUN_006629f0()))->ProjectToScreen((const ::NiPoint3 &)(kPos2), fX2, fY3, 1e-05f);
            bool bProjectedOnScreen = (!(fX2 <= 0.0) && !(fY3 <= 0.0) && !(fX2 >= 1.0) && !(fY3 >= 1.0)) ? true : false;
            if (bProjectedOnScreen)
                return true;
        }
        pNode5 = ((::VisNode *)(reinterpret_cast<::Callees *>((pNode5))->FUN_00726070()));
    }
    return false;
}
// Walks the list to the last node and, if it holds an item, copies its value and flag out, deletes the item and removes it.
// @fnv 0x009c88a0
void B9C88A0List::PopLastItem(int* piOutValue, bool* pbOutFlag)
{
    B9C88A0List* pkNode = this;
    while (pkNode && !pkNode->IsEmpty())
    {
        if (!((::B9C88A0List *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070())))
        {
            B9C88A0Item* pkItem = *((::B9C88A0Item **)(&reinterpret_cast<::SimpleListNodeView*>(pkNode)->m_item));
            *piOutValue = pkItem->m_iValue;
            *pbOutFlag = pkItem->m_bFlag;
            delete pkItem;
            reinterpret_cast<::ItemChangeListNode *>(this)->FUN_00905330((*(::InventoryStackRecord *const *)(&pkItem)));
            return;
        }
        pkNode = ((::B9C88A0List *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
    }
}
// Plays the UIVATSSelectTarget sound, then scans the target list for the nearest actor in the given direction and updates the VATS menu selection.
// @fnv 0x007f4c50
void TargetSelectHelper::SelectTarget(bool abReverse)
{
    BSSoundHandleEx soundHandle2;
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(soundHandle2))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("UIVATSSelectTarget", 0x121))));
    reinterpret_cast<::FUN_00ad8830_shell *>(&(soundHandle2))->FUN_00ad8830(false);

    BSSimpleList<ItemListContainer*>* iter = reinterpret_cast<BSSimpleList<ItemListContainer*>*>(&::g_011db150);
    float playerAngleDeg3 = reinterpret_cast<PlayerCharacter*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))->GetAngleZ(0) * 57.2957763671875;
    P3 playerPos7 = *reinterpret_cast<PlayerCharacter*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))->FUN_007f4f30_position();
    float bestAngle2 = (float)(abReverse ? -360 : 360);

    FormX* pEquippedA = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerCharacter*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->GetBaseTexture()))->GetEquippedWeapon();
    uintptr_t flags = (pEquippedA != 0) ? reinterpret_cast<uintptr_t>(((::WeaponX *)(reinterpret_cast<::InventoryEntryFields *>((pEquippedA))->pObject))) : 0;

    while (iter && !iter->FUN_008256d0())
    {
        float targetAngle2 = ::GetAngleBetweenPoints(
            (const ::NiPoint3 &)(playerPos7), (const ::NiPoint3 &)(*(*reinterpret_cast<Actor**>(*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(iter)->m_item))))->FUN_007f4f30_position()));
        float diff2 = playerAngleDeg3 - targetAngle2;
        diff2 = (diff2 > 180.0 ? diff2 - 360.0 : diff2);

        if ((diff2 < bestAngle2 && diff2 > 0.0 && !abReverse) || (diff2 > bestAngle2 && diff2 < 0.0 && abReverse))
        {
            bestAngle2 = diff2;
            ::DAT_011f21cc = *reinterpret_cast<Actor**>(*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(iter)->m_item)));
            ::FUN_007eb920((::WeaponPrompt *)(flags));

            BSSimpleList<ItemListContainer*>* itemIter2 = reinterpret_cast<BSSimpleList<ItemListContainer*>*>(&(*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(iter)->m_item)))->items);
            reinterpret_cast<VATSMenu*>(DAT_011db0d4)->m_pTargetChance = *((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(itemIter2)->m_item));

            while (itemIter2 && !itemIter2->FUN_008256d0())
            {
                if ((*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(iter)->m_item)))->unk04 == 1 &&
                    (*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(itemIter2)->m_item)))->unk20 == 1)
                {
                    reinterpret_cast<VATSMenu*>(DAT_011db0d4)->m_pTargetChance = *((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(itemIter2)->m_item));
                }
                itemIter2 = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((itemIter2))->FUN_00726070()));
            }
        }

        iter = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
    }
}
// For each entry in apTargets, creates a tile via FUN_00a1ddb0 and sets it to a value chosen by the action's type.
// @fnv 0x007f6e50
void FUN_007f6e50_This::AssignActionTiles(TargetList* apTargets)
{
    void* pTileBuffer = ((void *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(void *)(((void *)(::FUN_00a09030(0x420)))), (const char *)(void *)(&UNK_01077eac))));
    BSSimpleList<ItemListContainer*>* pEntry = (BSSimpleList<ItemListContainer*>*)&(*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(apTargets)->m_item)))->items;
    while (pEntry != 0 && !pEntry->FUN_008256d0())
    {
        ((ActionData*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pEntry)->m_item)))->tile =
            (Tile*)((void *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((GlobalManager*)DAT_011db0d4)))->FUN_00a1ddb0((::Tile *)(pTileBuffer), (char *)(void *)(&UNK_01077e98), (::Tile *)(0))));
        if (((ActionData*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pEntry)->m_item)))->tile != 0)
        {
            switch (((ActionData*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pEntry)->m_item)))->type)
            {
            case 0:
                ((ActionData*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pEntry)->m_item)))->tile->Set(0xfb7, 6);
                break;
            case -1:
            case 1:
            case 2:
            case 13:
                ((ActionData*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pEntry)->m_item)))->tile->Set(0xfb7, 5);
                break;
            case 3:
            case 4:
            case 7:
            case 8:
            case 9:
            case 14:
                ((ActionData*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pEntry)->m_item)))->tile->Set(0xfb7, 1);
                break;
            case 5:
            case 6:
            case 10:
            case 11:
            case 12:
                ((ActionData*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pEntry)->m_item)))->tile->Set(0xfb7, 4);
                break;
            }
        }
        pEntry = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((pEntry))->FUN_00726070()));
    }
}
// Walks a linked list of ItemQ pairs and returns the count of consecutive nodes where iA and iB match the next node.
// @fnv 0x007ef930
int OwnQ::GetConsecutiveMatchCount()
{
    int iCount = 0;
    NodeQ* pNode = ((::NodeQ *)(reinterpret_cast<::SimpleListNodeView*>(((ListQ*)&(*reinterpret_cast<int *>(&::g_011f2250))))->m_item));
    while (pNode && !pNode->FUN_008256d0())
    {
        bool bNext_pz = ((::NodeQ *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070())) != 0;
        ItemQ* pNext_vvak = bNext_pz ? *((::ItemQ **)(&reinterpret_cast<::SimpleListNodeView*>(((::NodeQ *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070())))->m_item)) : 0;
        ItemQ* pCur = *((::ItemQ **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item));
        if (bNext_pz)
        {
            if (pCur->iA == pNext_vvak->iA && pCur->iB == pNext_vvak->iB)
                iCount++;
            else
                iCount = 0;
        }
        else
            return iCount;
        pNode = ((::NodeQ *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return iCount;
}
// Updates VATS ammo meter tiles and returns whether a reload is needed based on the equipped weapon and queued commands.
// @fnv 0x007f28d0
bool VATSMenuX::FUN_007f28d0()
{
    FormX* equipped5 = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetEquippedWeapon();
    AmmoListX* ammoList2 = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetAmmoList();
    float clip3 = 0.0f;
    float reserve2 = 0.0f;
    m_fValue3 = 0.0f;
    m_fValue2 = 0.0f;
    bool _reload = false;
    if (equipped5)
    {
        WeaponX* weapon3 = ((::WeaponX *)(reinterpret_cast<::InventoryEntryFields *>((equipped5))->pObject));
        bool infinite5 = reinterpret_cast<::FUN_00474a80_Class *>(&(weapon3->kMods))->FUN_00474a80();
        float maxAmmo4 = (float)reinterpret_cast<::RockItAmmoCountDetail::PlayerView *>((reinterpret_cast<AmmoPlayer*>((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))->FUN_00969040();
        bool subtractClip4 = true;
        switch (weapon3->GetWeaponType())
        {
        case 10:
        case 11:
        case 13: {
            clip3 = (float)reinterpret_cast<::FUN_00524b60_shell *>((weapon3))->GetByteAt102();
            AmmoInventory* invThrown3 = ((::AmmoInventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))));
            int countThrown = reinterpret_cast<::FUN_004c8f30_shell *>((invThrown3))->FUN_004c8f30((intptr_t)(weapon3));
            reserve2 = countThrown - clip3;
            break;
        }
        default:
            if (infinite5)
            {
                reserve2 = 0.0f;
                clip3 = maxAmmo4;
            }
            else
            {
                AmmoInventory* inventory = ((::AmmoInventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))));
                int count9 = reinterpret_cast<::FUN_004c8f30_shell *>((inventory))->FUN_004c8f30((intptr_t)(((void *)(reinterpret_cast<::AmmoOwner *>((weapon3))->FUN_00525980((::AmmoActor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))))));
                if (reinterpret_cast<::TESObjectWEAP *>((reinterpret_cast<AmmoWeapon*>(weapon3)))->FUN_00709430(
                        ((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((reinterpret_cast<AmmoEntry*>(equipped5)))->HasEffect(6)))) > 0.0)
                {
                    reserve2 = (float)reinterpret_cast<::FUN_004fe160_cls *>((weapon3))->GetFlaggedValue(((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((reinterpret_cast<AmmoEntry*>(equipped5)))->HasEffect(2))));
                    subtractClip4 = false;
                }
                clip3 =
                    (float)(ammoList2
                                ? ((std::intptr_t)(reinterpret_cast<::Callees *>((ammoList2))->FUN_00726070()))
                                : (count9 > reinterpret_cast<::FUN_004fe160_cls *>((weapon3))->GetFlaggedValue(
                                                ((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((reinterpret_cast<AmmoEntry*>(equipped5)))->HasEffect(2))))
                                       ? reinterpret_cast<::FUN_004fe160_cls *>((weapon3))->GetFlaggedValue(((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((reinterpret_cast<AmmoEntry*>(equipped5)))->HasEffect(2))))
                                       : count9));
                if (subtractClip4)
                    reserve2 = count9 - clip3;
            }
            break;
        }
        m_fValue2 = clip3;
        m_fValue4 = clip3;
        m_fValue3 = reserve2;
        m_fValue5 = reserve2;
        AmmoCommandNode* node2 = ((::AmmoCommandNode *)(reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<AmmoQueue*>(&(*reinterpret_cast<::VATSX *>(&::g_011f2250))))->m_item));
        while (node2 && !node2->FUN_008256d0())
        {
            switch ((*((::AmmoCommand **)(&reinterpret_cast<::SimpleListNodeView*>(node2)->m_item)))->action)
            {
            case 9:
                m_fValue4 = FUN_0040ebd0(
                    m_fValue3,
                    infinite5 ? maxAmmo4
                              : (float)reinterpret_cast<::FUN_004fe160_cls *>((weapon3))->GetFlaggedValue(((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((reinterpret_cast<AmmoEntry*>(equipped5)))->HasEffect(2)))));
                m_fValue5 -= FUN_0040ebd0(
                    m_fValue3,
                    infinite5 ? maxAmmo4
                              : (float)reinterpret_cast<::FUN_004fe160_cls *>((weapon3))->GetFlaggedValue(((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((reinterpret_cast<AmmoEntry*>(equipped5)))->HasEffect(2)))));
                break;
            case 3:
            case 4:
            case 5:
            case 6:
                m_fValue4 = FUN_00404010(0.0f, (float)(m_fValue4 - (*((::AmmoCommand **)(&reinterpret_cast<::SimpleListNodeView*>(node2)->m_item)))->shots));
                if (m_fValue4 == 0.0)
                {
                    m_fValue4 =
                        FUN_0040ebd0(m_fValue5, infinite5 ? maxAmmo4
                                                          : (float)reinterpret_cast<::FUN_004fe160_cls *>((weapon3))->GetFlaggedValue(
                                                                ((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((reinterpret_cast<AmmoEntry*>(equipped5)))->HasEffect(2)))));
                    m_fValue5 -=
                        FUN_0040ebd0(m_fValue3, infinite5 ? maxAmmo4
                                                          : (float)reinterpret_cast<::FUN_004fe160_cls *>((weapon3))->GetFlaggedValue(
                                                                ((unsigned char)(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((reinterpret_cast<AmmoEntry*>(equipped5)))->HasEffect(2)))));
                    m_fValue5 = FUN_00404010(0.0f, m_fValue5);
                    _reload = true;
                }
                else
                    _reload = false;
                break;
            case 7:
            case 8:
                m_fValue4 = FUN_00404010(0.0f, (float)(m_fValue4 - 1.0));
                break;
            }
            node2 = ((::AmmoCommandNode *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070()));
        }
        if (((void *)(reinterpret_cast<::AmmoOwner *>((weapon3))->FUN_00525980((::AmmoActor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))))
        {
            reinterpret_cast<::Tile *>((m_pTiles[14]))->Set(0xfa3, 1);
            reinterpret_cast<::Tile *>((m_pTiles[15]))->Set(0xfc4, 1);
            reinterpret_cast<::Tile *>((m_pTiles[16]))->Set(0xfc4, 1);
            reinterpret_cast<::Tile *>((m_pTiles[16]))->Set(0xfa3, 1);
            ::fnv_007748b0::UpdateMeterTile(
                (::fnv_007748b0::Tile *)(m_pTiles[15]),
                FUN_0040ebd0(1.0f, FUN_00404010(0.0f, (float)(reinterpret_cast<::FUN_004bcdb0_shell *>((reinterpret_cast<AmmoEntry*>(equipped5)))->FUN_004bcdb0(0) /
                                                              (::TESHealthForm::GetBaseHealth((::TESForm *)(::WeaponX *)(((::WeaponX *)(reinterpret_cast<::InventoryEntryFields *>((equipped5))->pObject))))
                                                                   ? ::TESHealthForm::GetBaseHealth((::TESForm *)(::WeaponX *)(((::WeaponX *)(reinterpret_cast<::InventoryEntryFields *>((equipped5))->pObject))))
                                                                   : 1)))),
                0, 0, 0);
            reinterpret_cast<::Tile *>((m_pTiles[13]))->Set(0xfa3, 1);
        }
        else
        {
            reinterpret_cast<::Tile *>((m_pTiles[14]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((m_pTiles[15]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((m_pTiles[16]))->Set(0xfc4, 0);
            reinterpret_cast<::Tile *>((m_pTiles[16]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((m_pTiles[13]))->Set(0xfa3, 0);
            if (weapon3->GetWeaponType() == 10 || weapon3->GetWeaponType() == 11 || weapon3->GetWeaponType() == 13)
                reinterpret_cast<::Tile *>((m_pTiles[13]))->Set(0xfa3, 1);
        }
    }
    else
    {
        reinterpret_cast<::Tile *>((m_pTiles[14]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((m_pTiles[15]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((m_pTiles[16]))->Set(0xfc4, 0);
        reinterpret_cast<::Tile *>((m_pTiles[16]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((m_pTiles[13]))->Set(0xfa3, 0);
        m_fValue4 = 0.0f;
        m_fValue5 = 0.0f;
    }
    char text[16];
    ::FUN_00406d00(text, 16, "%i/%i", (int)m_fValue4, (int)m_fValue5);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[13]))->FUN_00a01350(0xfc4, (char *)(text), true);
    return _reload;
}
struct NodeC
{
    void* ApplyScaled(Vec3* a1, Vec3* a2, float a3);
};
struct NodeB
{
    Vec3 FUN_0045bba0();
};

struct GlobD
{
};
struct GlobC
{
    MidObj* FUN_00931ed0(void* a);
};

struct TargetListResetCalls
{
};

struct Chain43
{
};
struct Obj54
{
};
struct Obj6c
{
};
struct Refr
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual bool V100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual struct Node148* V148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual Obj54* V180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual int V190(int a);
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual bool V1a0(int a);
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual struct PosObj* V1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual int V1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual intptr_t V1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual bool V220();
    virtual bool V224();
    virtual void vf228();
    virtual bool V22c(int a);
    int FUN_00931850();
};
struct FUN_004759a0_First
{
};
struct PosObj
{
};
struct NodeB8
{
};
struct Node148
{
    NodeB8* FUN_0044ddc0();
};
struct Mgr
{
};
struct WS
{
};


struct ListHead
{
    void* item;
    ListHead* next;
    void FUN_005ae3d0(void* a1);
    bool FUN_008256d0();
};
struct TargetChildren
{
    void* item;
    TargetChildren* next;
    void FUN_005ae3d0(void* a1);
    bool FUN_008256d0();
};
struct FUN_007f6900_Record
{
    intptr_t f0;
    int f4;
    TargetChildren sub;
    bool f10;
    int f14;
    int f18;
    int f1c;
    char f20;
    char b21;
    char b22;
    char b23;
    FUN_007f6900_Record();
};
struct Obj60
{
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    Vec3 pos;
    int idx;
    int f24;
    float f28;
    char b2c;
    char b2d;
    char b2e;
    char b2f;
    int f30;
    int f34;
    int f38;
    Obj60* FUN_007f6820();
};

struct StepObj
{
};
struct MidObj
{
};
struct CountMid
{
};
struct CountNode
{
};
struct BigSubA
{
    int a00;
    int a04;
    int a08;
    int a0c;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
    int a24;
    int a28;
    int a2c;
};
struct BigSubB
{
    int b00;
    int b04;
    int b08;
    int b0c;
    int b10;
    int b14;
    int b18;
    int b1c;
    int b20;
    int b24;
    int b28;
    int b2c;
    int b30;
    int b34;
    int b38;
    int b3c;
    int b40;
    int b44;
    int b48;
    int b4c;
    int b50;
    int b54;
    int b58;
    int b5c;
};
struct BigSubC
{
    int c00;
    int c04;
    int c08;
    int c0c;
};
struct BigList
{
    __declspec(align(16)) BigSubA sub00;
    BigSubB sub30;
    BigSubC sub90;
    int fA0;
    int fA4;
    int fA8;
    char fAC;
    void FUN_004a3f70(int a);
};
struct Obj20c
{
    int f0;
};
struct Obj5b0
{
    __declspec(align(16)) float normalX;
    float normalY, normalZ, normalW;
    float fraction;
    unsigned int m_uiExtraInfo;
    unsigned int shapeKeys[8];
    int keyIndex;
    int unk3c, unk40, unk44, unk48, unk4c;
    intptr_t f50;
};
struct HitArray
{
    Obj5b0* data;
    int size;
    int capacityAndFlags;
    int storageAlignment;
    unsigned char localHitStorage[sizeof(Obj5b0) * 8];
};
struct hkpAllRayHitCollector
{
    float earlyOutHitFraction;
    int unk08, unk0c;
    HitArray hits;
    hkpAllRayHitCollector();
    virtual ~hkpAllRayHitCollector();
};
struct Refr;
void __cdecl FUN_007f6920();
struct Obj548
{
    virtual void x00();
    virtual void x04();
    virtual void x08();
    virtual void x0c();
    virtual void x10();
    virtual void x14();
    virtual void x18();
    virtual void x1c();
    virtual void x20();
    virtual void x24();
    virtual void x28();
    virtual void x2c();
    virtual void x30();
    virtual void x34();
    virtual void x38();
    virtual void x3c();
    virtual void x40();
    virtual void x44();
    virtual void x48();
    virtual void x4c();
    virtual void x50();
    virtual void x54();
    virtual void x58();
    virtual void x5c();
    virtual void x60();
    virtual void x64();
    virtual void x68();
    virtual void x6c();
    virtual void x70();
    virtual void x74();
    virtual void x78();
    virtual void x7c();
    virtual void x80();
    virtual void x84();
    virtual void x88();
    virtual void x8c();
    virtual void x90();
    virtual void x94();
    virtual void x98();
    virtual void x9c();
    virtual void xa0();
    virtual void xa4();
    virtual void xa8();
    virtual void xac();
    virtual void xb0();
    virtual void xb4();
    virtual void xb8();
    virtual void xbc();
    virtual void xc0();
    virtual void xc4();
    virtual bool V0c8(void* a);
};

struct TargetEntry
{
    Refr* reference;
    bool selected;
};
typedef NiPoint2 ScreenPoint;
// Filters references by probability and screen bounds, adds target-list records, and uses physics raycasts when visibility checks fail.
// @fnv 0x007f52c0
bool FUN_007f52c0()
{
    if (!((BSSimpleList<ItemListContainer*>*)&::g_011db150)->FUN_008256d0())
        return true;
    bool result = false;
    reinterpret_cast<::S00a70ba0_Cam *>((((NodeB*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())))->UpdateWorldToCamera();
    BSSimpleList<ItemListContainer*>* cur = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::FUN_00595d10_shell *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))))->FUN_00595d10()));
    float fBestProb = 0.0f;
    bool flag21 = reinterpret_cast<::TESObjectCELL *>((((::GlobD *)(reinterpret_cast<::LowProcess *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))))->GetTarget()))))->IsCellInterior();
    reinterpret_cast<::FileMatchList *>((reinterpret_cast<TargetListResetCalls*>(&::g_011db124)))->RemoveAll();
    while (cur && !cur->FUN_008256d0())
    {
        TargetEntry* target = (TargetEntry*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item));
        bool flag29 = true;
        if (target)
            flag29 = (((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((FUN_00475400((void*)((std::intptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target->reference))->FUN_007af430())))))->FUN_00726070())) &&
                      !reinterpret_cast<::FUN_00576070_shell *>((target->reference))->FUN_00576070())
                         ? 1
                         : 0;
        if (!target || (target && target->reference->V22c(0)) || !target->reference->V1d0() ||
            target->reference->FUN_00931850() || target->reference->V1a0(0) || flag29)
        {
            cur = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
            continue;
        }
        float prob = reinterpret_cast<::RefS *>((target->reference))->FUN_005723b0((::RefS *)((*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer))), 0, 0);
        if (prob < DAT_01011590 || prob > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting1261)))))) ||
            !reinterpret_cast<::SightActor *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))))->FUN_0088b880(1, (::SightActor *)(target->reference), 1, (int *)(0), 1))
        {
            cur = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
            continue;
        }
        if (prob > fBestProb)
            fBestProb = prob;
        Vec3 vec = *((::Vec3 *)(::FUN_0045bb80((intptr_t)(target->reference->V1d0()))));
        float fScreenX = 0.0f;
        float fScreenY = 0.0f;
        reinterpret_cast<::ScreenCamera *>((((NodeB*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())))->ProjectToScreen((*(const ::NiPoint3 *)(&vec)), (*(float *)(&fScreenX)), (*(float *)(&fScreenY)), ::DAT_010718c0);
        bool bVisible = !(fScreenX <= ::_DAT_01012060 || fScreenY <= ::_DAT_01012060 || fScreenX >= ::g_01012070 ||
                          fScreenY >= ::g_01012070)
                            ? true
                            : false;
        if (!bVisible)
        {
            Refr* base = ((::Refr *)(reinterpret_cast<::Actor *>((target->reference))->GetActorBase()));
            Obj54* pObj54 = base->V180();
            int** arr = ((int **)(::FUN_006a9540((char *)(pObj54))));
            for (int i = 0; i < 15; ++i)
            {
                if (arr[i])
                {
                    ScreenPoint vScreen;
                    Refr* actor = ((TargetEntry*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item)))->reference;
                    Obj6c* pObj6c = ((::Obj6c *)(::FUN_004aae30((::NiAVObject *)((std::intptr_t)actor->V1d0()), (::NiFixedString *)(((std::intptr_t)(::fnv_0043b230::FUN_0043b230((const char *)(((::Chain43 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((pObj54))->GetValueByIndex(i)))))))))));
                    if (pObj6c)
                    {
                        reinterpret_cast<::ScreenCamera *>((((NodeB*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())))->ProjectToScreen((*(const ::NiPoint3 *)(((::Vec3 *)(::FUN_0045bb80((intptr_t)(pObj6c)))))), (*(float *)(&vScreen.x)), (*(float *)(&vScreen.y)), ::DAT_010718c0);
                        if (vScreen.x > ::_DAT_01012060 && vScreen.y > ::_DAT_01012060 && vScreen.x < ::g_01012070 &&
                            vScreen.y < ::g_01012070)
                        {
                            bVisible = true;
                            result = true;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            result = true;
        }
        if (((flag21 && prob > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87))))))) ||
             (!flag21 && prob > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting101)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87)))))))) &&
            !bVisible)
        {
            cur = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
            continue;
        }
        if (target->reference->V1d0())
        {
            FUN_007f6900_Record* obj = new FUN_007f6900_Record;
            obj->f4 = 1;
            obj->f0 = (intptr_t)target->reference;
            obj->f10 = false;
            obj->f20 = ((TargetEntry*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item)))->selected;
            Refr* base2 = ((::Refr *)(reinterpret_cast<::Actor *>((((Refr*)obj->f0)))->GetActorBase()));
            Obj54* pObj54b = base2->V180();
            int** ppArrb = ((int **)(::FUN_006a9540((char *)(pObj54b))));
            for (int j = 0; j < 15; ++j)
            {
                if (ppArrb[j])
                {
                    Obj60* child = (Obj60*)new FUN_007f6820_cls;
                    child->b2c = false;
                    child->b2d = false;
                    child->b2e = false;
                    child->b2f = true;
                    child->pos = (*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO));
                    child->f28 = 0.0f;
                    child->idx = j;
                    obj->sub.FUN_005ae3d0(&child);
                }
            }
            int res190 = 0;
            if (((Refr*)obj->f0)->V100())
            {
                res190 = ((::Refr *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Refr*)obj->f0)))->GetBaseTexture()))->V190(((Refr*)obj->f0)->V1e8());
            }
            Node148* pNode148 = ((Refr*)obj->f0)->V100() ? ((::Refr *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((Refr*)obj->f0)))->GetBaseTexture()))->V148() : 0;
            NodeB8* pNodeB8 = pNode148 ? ((::NodeB8 *)(reinterpret_cast<::Twin_0044ddc0 *>((pNode148))->GetName())) : 0;
            if (res190 && pNodeB8 && !reinterpret_cast<::FUN_0046e8c0_class *>((pNodeB8))->FUN_0046e8c0())
            {
                Obj60* child2 = (Obj60*)new FUN_007f6820_cls;
                child2->b2c = false;
                child2->b2d = false;
                child2->b2e = false;
                child2->b2f = true;
                child2->pos = (*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO));
                child2->idx = 14;
                obj->sub.FUN_005ae3d0(&child2);
            }
            if (obj->sub.FUN_008256d0())
            {
                obj->f4 = 2;
                Obj60* child3 = (Obj60*)new FUN_007f6820_cls;
                child3->idx = -1;
                child3->b2c = false;
                child3->b2d = false;
                child3->b2e = false;
                child3->b2f = true;
                child3->pos = (*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO));
                obj->sub.FUN_005ae3d0(&child3);
            }
            ((ListHead*)&::g_011db150)->FUN_005ae3d0(&obj);
        }
        cur = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
    }
    if (fBestProb != ::_DAT_01012060)
        fBestProb = fBestProb + DAT_0102e430;
    if (((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))))->FUN_00575d70())))
    {
        reinterpret_cast<::WORLD_SHELL *>((((WS*)((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))))->FUN_00575d70())))))->ProcessCellsInRadius(
                (const ::NiPoint3 *)(((Refr*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))->V1f4()), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting101)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87)))))),
                (const ::NiPoint3 *)(((Refr*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))->V1f4()),
                *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting101)))))) *
                    *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87)))))), {}, {});
    }
    else
    {
        reinterpret_cast<::s54da20::Owner *>((((::GlobD *)(reinterpret_cast<::LowProcess *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))))->GetTarget()))))->FUN_0054da20(
                (::s54da20::Position *)(((Refr*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))->V1f4()), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting101)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87)))))),
                (::s54da20::Position *)(((Refr*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))->V1f4()),
                *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting101)))))) *
                    *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87)))))), {}, {});
    }
    BSSimpleList<ItemListContainer*>* pCurNode2 = (BSSimpleList<ItemListContainer*>*)&::g_011db124;
    while (pCurNode2 && !pCurNode2->FUN_008256d0())
    {
        float prob2 = reinterpret_cast<::RefS *>((((Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item)))))->FUN_005723b0((::RefS *)((*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer))), 0, 0);
        Refr* refr2 = (Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item));
        {
            if (refr2->V100() || ((Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item)))->V220() ||
                (fBestProb > ::_DAT_01012060 &&
                 fBestProb < reinterpret_cast<::RefS *>((((Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item)))))->FUN_005723b0((::RefS *)((*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer))), 0, 0)) ||
                reinterpret_cast<::FUN_00477ba0_shell *>((((Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item)))))->FUN_00477ba0() ||
                reinterpret_cast<::TESForm *>((((Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item)))))->GetDisabled() ||
                reinterpret_cast<::FUN_00440d80_shell *>((((Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item)))))->FUN_00440d80() ||
                (flag21 && prob2 > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87))))))) ||
                (!flag21 && prob2 > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting101)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87))))))) ||
                !reinterpret_cast<::FUN_00576070_shell *>((((Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item)))))->FUN_00576070())
            {
                pCurNode2 = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((pCurNode2))->FUN_00726070()));
                continue;
            }
        }
        {
            Refr* refr4 = (Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item));
            if (refr4->V224())
            {
                Refr* refr5 = (Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item));
                if (((void *)(::FUN_00874480((char *)(refr5)))) == (void*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))
                {
                    pCurNode2 = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((pCurNode2))->FUN_00726070()));
                    continue;
                }
            }
        }
        if (!reinterpret_cast<::FUN_00477ba0_shell *>((((Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item)))))->FUN_00477ba0())
        {
            FUN_007f6900_Record* obj2 = new FUN_007f6900_Record;
            obj2->f4 = 2;
            obj2->f0 = (intptr_t)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item));
            obj2->f10 = false;
            obj2->f20 = 0;
            Obj60* child4 = (Obj60*)new FUN_007f6820_cls;
            child4->idx = -1;
            child4->b2c = false;
            child4->b2d = false;
            child4->b2e = false;
            child4->b2f = true;
            child4->pos = (*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO));
            obj2->sub.FUN_005ae3d0(&child4);
            if (!result)
            {
                Refr* refr6 = (Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item));
                Vec3 vPos2 = *((::Vec3 *)(::FUN_0045bb80((intptr_t)(refr6->V1d0()))));
                float fScreenX2 = 0.0f;
                float fScreenY2 = 0.0f;
                reinterpret_cast<::ScreenCamera *>((((NodeB*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())))->ProjectToScreen((*(const ::NiPoint3 *)(&vPos2)), (*(float *)(&fScreenX2)), (*(float *)(&fScreenY2)), ::DAT_010718c0);
                bool visible = !(fScreenX2 <= ::_DAT_01012060 || fScreenY2 <= ::_DAT_01012060 || fScreenX2 >= ::g_01012070 ||
                                 fScreenY2 >= ::g_01012070)
                                   ? true
                                   : false;
                if (visible)
                {
                    BigList oBigList;
                    new ((void *)&(oBigList)) ::FUN_004a3c20();
                    Vec3 vOrigin;
                    Vec3 vUnused;
                    vOrigin = *((::Vec3 *)(::FUN_0045bb80((intptr_t)(((NodeB*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())))));
                    Obj20c oFilter;
                    new ((void *)&(oFilter)) ::GlobalObject_008c71b0(0);
                    reinterpret_cast<::FUN_004a39f0_shell *>(&(oFilter))->FUN_004a39f0(0x25);
                    int material;
                    reinterpret_cast<::FUN_0059ce80_shell *>(&(oFilter))->FUN_0059ce80((unsigned int)(((reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))->FUN_00931ed0(&material)))->FUN_004a3a20()))));
                    oBigList.FUN_004a3f70(oFilter.f0);
                    hkpAllRayHitCollector oCollector;
                    reinterpret_cast<::FUN_004a3fb0_shell *>(&(oBigList))->FUN_004a3fb0((::hkpAllRayHitCollector *)(void *)(&oCollector));
                    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(oBigList))->FUN_004a3da0(&vOrigin);
                    Refr* rayTarget = (Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item));
                    reinterpret_cast<::FUN_004a3eb0_shell *>(&(oBigList))->FUN_004a3eb0(((::StepObj *)(reinterpret_cast<::SimpleListNodeView*>(((::StepObj *)(reinterpret_cast<::FUN_0043d450_Owner *>((rayTarget->V1d0()))->FUN_0043d450())))->m_item)));
                    Refr* rayTarget2 = (Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item));
                    Vec3 direction;
                    reinterpret_cast<::Class_007f68a0 *>(&(oBigList))->FUN_007f68a0(
                        (*(const ::NiPoint3 *)(((void *)(reinterpret_cast<::FUN_00439ef0_class *>((((::StepObj *)(reinterpret_cast<::SimpleListNodeView*>(((::StepObj *)(reinterpret_cast<::FUN_0043d450_Owner *>((rayTarget2->V1d0()))->FUN_0043d450())))->m_item))))->FUN_00439ef0((::NiPoint3 *)(::Vec3 *)(&direction), (*(const ::NiPoint3 *)(&vOrigin))))))));
                    Obj548* physics = ((::Obj548 *)(reinterpret_cast<::FUN_004543c0_cls *>((((::GlobD *)(reinterpret_cast<::LowProcess *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))))->GetTarget()))))->FUN_004543c0()));
                    bool hit = physics->V0c8(&oBigList);
                    if (hit && ((::CountNode *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(oBigList))->FUN_008cdd90())))
                    {
                        for (int count = 0; !result && count < ((std::intptr_t)(reinterpret_cast<::Callees *>((((::CountMid *)(::FUN_00460140((std::intptr_t)(((::CountNode *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(oBigList))->FUN_008cdd90()))))))))->FUN_00726070()));
                             ++count)
                        {
                            Obj5b0 oContact;
                            reinterpret_cast<::S50 *>(&(oContact))->FUN_00696c30((::S50 *)(void *)(((void *)(reinterpret_cast<::FUN_004a46b0_class *>((((::CountMid *)(::FUN_00460140((std::intptr_t)(((::CountNode *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(oBigList))->FUN_008cdd90()))))))))->GetEntryAt(count)))));
                            int id = ((int)(::FUN_004b5820((::FormLike *)(oContact.f50))));
                            if (id)
                            {
                                Refr* rayTarget3 = (Refr*)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(pCurNode2)->m_item));
                                if (id == (std::intptr_t)rayTarget3->V1d0())
                                    result = true;
                            }
                        }
                    }
                }
            }
            ((ListHead*)&::g_011db150)->FUN_005ae3d0(&obj2);
        }
        pCurNode2 = ((::BSSimpleList<ItemListContainer*> *)(reinterpret_cast<::Callees *>((pCurNode2))->FUN_00726070()));
    }
    if (!result)
    {
        BigList oBigList2;
        new ((void *)&(oBigList2)) ::FUN_004a3c20();
        Vec3 vStart;
        Vec3 vUnused2;
        vStart = *((::Vec3 *)(::FUN_0045bb80((intptr_t)(((NodeB*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())))));
        Obj20c oFilter2;
        new ((void *)&(oFilter2)) ::GlobalObject_008c71b0(0);
        reinterpret_cast<::FUN_004a39f0_shell *>(&(oFilter2))->FUN_004a39f0(0x25);
        int material2;
        reinterpret_cast<::FUN_0059ce80_shell *>(&(oFilter2))->FUN_0059ce80((unsigned int)(((reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))->FUN_00931ed0(&material2)))->FUN_004a3a20()))));
        oBigList2.FUN_004a3f70(oFilter2.f0);
        hkpAllRayHitCollector oCollector2;
        reinterpret_cast<::FUN_004a3fb0_shell *>(&(oBigList2))->FUN_004a3fb0((::hkpAllRayHitCollector *)(void *)(&oCollector2));
        reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(oBigList2))->FUN_004a3da0(&vStart);
        reinterpret_cast<::FUN_004a3eb0_shell *>(&(oBigList2))->FUN_004a3eb0((void *)&(const ::Vec3 &)(((NodeB*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())->FUN_0045bba0()));
        reinterpret_cast<::Class_007f68a0 *>(&(oBigList2))->FUN_007f68a0(
            (const ::NiPoint3 &)((const ::Vec3 &)(((NodeB*)((::BSFaceGenNiNode *)(::FUN_0045c670()))->GetAnimationData())
                ->FUN_0045bba0()
                .ApplyScaled((flag21 ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87))))))
                                      : *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting101)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Mgr *>(&::originalRuntimeFloatSetting87)))))))))));
        Obj548* physics2 = ((::Obj548 *)(reinterpret_cast<::FUN_004543c0_cls *>((((::GlobD *)(reinterpret_cast<::LowProcess *>((((GlobC*)(*reinterpret_cast<::PlayerPrompt * *>(&::_g_thePlayer)))))->GetTarget()))))->FUN_004543c0()));
        bool hit2 = physics2->V0c8(&oBigList2);
        if (hit2 && ((::CountNode *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(oBigList2))->FUN_008cdd90())))
        {
            for (int count2 = 0; !result && count2 < ((std::intptr_t)(reinterpret_cast<::Callees *>((((::CountMid *)(::FUN_00460140((std::intptr_t)(((::CountNode *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(oBigList2))->FUN_008cdd90()))))))))->FUN_00726070())); ++count2)
            {
                Obj5b0 oContact2;
                reinterpret_cast<::S50 *>(&(oContact2))->FUN_00696c30((::S50 *)(void *)(((void *)(reinterpret_cast<::FUN_004a46b0_class *>((((::CountMid *)(::FUN_00460140((std::intptr_t)(((::CountNode *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(oBigList2))->FUN_008cdd90()))))))))->GetEntryAt(count2)))));
                intptr_t id2 = ((int)(::FUN_004b5820((::FormLike *)(oContact2.f50))));
                if (id2)
                {
                    Refr* found = ((::Refr *)(::FUN_0056f930((::NiAVObject *)(id2))));
                    if (found && ::fnv_004753d0::FUN_004753d0((void*)((std::intptr_t)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((found))->FUN_007af430()))) && found->V224())
                        result = true;
                }
            }
        }
    }
    if (!result)
        FUN_007f6920();
    return result;
}

struct Comp2
{
};
struct Comp
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual Comp* GetComp();
};
struct ActorView7
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual bool IsReady();
};
struct FUN_007f3bf0_cls
{
    int FUN_007f3bf0(int a1);
};
// @fnv 0x007ec810
void VATSMenuX::Update()
{
    if (m_bStateFlag3)
    {
        return;
    }
    if (::FUN_00a09030(0x423))
    {
        return;
    }
    if (!(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)) || !(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsAlive() || (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsDead(0) || (*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))->IsDead(0))
    {
        ::ShutdownVats();
        return;
    }
    if (!(*reinterpret_cast<::VATSMenuX * *>(&::DAT_011db0d4)) || !((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) || ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 4 || !xFUN_00702450(0x420))
    {
        if (!xFUN_00702450(0x420) && xDAT_011a0b68)
        {
            xDAT_011a0b68 = 0;
            reinterpret_cast<::Target *>((xGetVATSEffect()))->FUN_00800ac0((::TargetActor *)(0), -1, 0);
        }
        reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((m_pTiles[28]))->RemoveFadeItemsForTile(0x80000000);
        reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>(((*((::TileX **)(reinterpret_cast<::FUN_0073ac90_shell *>(&(m_pTiles[28]->kChildren))->FUN_0073ac90())))))->RemoveFadeItemsForTile(0x80000000);
        reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((m_pTiles[10]))->RemoveFadeItemsForTile(0x80000000);
        return;
    }
    if (((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(&(((::TargetX *)(reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->m_item))->kLimbs))->m_item))->iHitCount == 0)
    {
        reinterpret_cast<::FUN_007f6e50_This *>(this)->AssignActionTiles((::TargetList *)(::ListX< ::TargetX *> *)(FindListEntryForTarget((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))));
    }
    if (!xDAT_011a0b68)
    {
        ::fnv_007ec3a0::UpdateVatsTargetHighlight(1);
    }
    xDAT_011a0b68 = 1;
    if (::fnv_00703d50::FUN_00703d50())
    {
        return;
    }
    UpdateLimbHighlight();
    InputX* pInputA = ((::InputX *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OSGlobalsX * *>(&::g_osGlobals))))->FUN_00877720()));
    if (::FUN_004b71d0())
    {
        int iDeadZoneCur = ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 1 ? 0x1ea9 : 0x21f1;
        int iLeftXTwo54 = reinterpret_cast<::FUN_00a23390_t *>((pInputA))->GetAxisState(0, 7);
        int iLeftYZ = reinterpret_cast<::FUN_00a23390_t *>((pInputA))->GetAxisState(0, 8);
        int iRightXNum = reinterpret_cast<::FUN_00a23390_t *>((pInputA))->GetAxisState(0, 9);
        int iRightYTmp = reinterpret_cast<::FUN_00a23390_t *>((pInputA))->GetAxisState(0, 10);
        iLeftYZ = -iLeftYZ;
        iRightYTmp = -iRightYTmp;
        if (iRightXNum > 0x21f1)
        {
            if (!m_bStateFlag6)
            {
                m_uiTargetCount = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimerX *>(&::g_timeGlobal))))->FUN_00825c00()));
                m_bStateFlag6 = 1;
            }
        }
        else if (iRightXNum < -0x21f1)
        {
            if (!m_bStateFlag10)
            {
                m_uiTargetCount = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimerX *>(&::g_timeGlobal))))->FUN_00825c00()));
                m_bStateFlag10 = 1;
            }
        }
        else if (::std::abs(iRightXNum) < 0x21f1 && ::std::abs(iRightYTmp) < 0x21f1)
        {
            if (::fnv_007f4c00::FUN_007f4c00())
            {
                (*reinterpret_cast<::VATSMenuX * *>(&::DAT_011db0d4))->m_bStateFlag6 = 0;
                HandleClick(3, 0);
            }
            else if (m_bStateFlag6)
            {
                HandleClick(3, 0);
            }
            else if (::FUN_007f4bb0())
            {
                (*reinterpret_cast<::VATSMenuX * *>(&::DAT_011db0d4))->m_bStateFlag10 = 0;
                HandleClick(2, 0);
            }
            else if (m_bStateFlag10)
            {
                HandleClick(2, 0);
            }
            m_bStateFlag9 = 1;
        }
    }
    if ((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)) && (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsActor())
    {
        float fBaseHealthA68 = (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->kAVOwner.GetBaseActorValue(0x10);
        float fHealthOut44 = (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->kAVOwner.GetActorValue(0x10);
        float fRatioB = 0.0f;
        char acBufferOut70[256];
        if (fBaseHealthA68 > 0)
        {
            fRatioB = fHealthOut44 / fBaseHealthA68;
        }
        if (!(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsDead(0))
        {
            ::UpdateBarWidths((::BarTile *)(m_pTiles[26]), (::BarTile *)(m_pTiles[28]), fRatioB - m_fHitChance, fRatioB, 2, 2);
        }
        else
        {
            ::UpdateBarWidths((::BarTile *)(m_pTiles[26]), (::BarTile *)(m_pTiles[28]), fRatioB - m_fHitChance, fRatioB, 2, 0);
        }
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(reinterpret_cast<::FUN_0055d520_shell *>(((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->FUN_0055d520()), 1);
        reinterpret_cast<::Tile *>((m_pTiles[25]))->Set(0xfa3, 1);
        reinterpret_cast<::Tile *>((m_pTiles[26]))->Set(0xfa3, 1);
        reinterpret_cast<::Tile *>((m_pTiles[28]))->Set(0xfa3, 1);
        reinterpret_cast<::Tile *>((m_pTiles[27]))->Set(0xfa3, 1);
        reinterpret_cast<::Tile *>((m_pTiles[29]))->Set(0xfa3, 1);
        float fChanceX73 = ::GetActorValueWithPerkModifiers((::MobileObject *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))), (::Actor *)((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))));
        float fPerkB = 0.0f;
        ::ApplyPerkModifiers(0x2f, (::Actor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))), &fPerkB);
        if (fPerkB > 0)
        {
            ::std::sprintf(acBufferOut70, "%s\n %s:%d %s:%.2f", reinterpret_cast<::FUN_0055d520_shell *>(((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->FUN_0055d520(), (*reinterpret_cast<::SettingX *>(&::g_011d50b0)).String(),
                    (int)fHealthOut44, (*reinterpret_cast<::SettingX *>(&::g_011d396c)).String(), fChanceX73);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(acBufferOut70), 1);
        }
        else
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[29]))->FUN_00a01350(0xfc4, (char *)(reinterpret_cast<::FUN_0055d520_shell *>(((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->FUN_0055d520()), 1);
        }
        if (((::DetectX *)(reinterpret_cast<::FUN_00967090_t *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->FUN_00967090((::Actor *)((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))))) && ((::DetectX *)(reinterpret_cast<::FUN_00967090_t *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->FUN_00967090((::Actor *)((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))))->bDetected)
        {
            reinterpret_cast<::Tile *>((m_pTiles[29]))->Set(0xff4, 2);
            reinterpret_cast<::Tile *>((m_pTiles[25]))->Set(0xff4, 2);
            reinterpret_cast<::Tile *>((m_pTiles[26]))->Set(0xff4, 2);
            reinterpret_cast<::Tile *>((m_pTiles[28]))->Set(0xff4, 2);
            reinterpret_cast<::Tile *>((m_pTiles[27]))->Set(0xff4, 2);
        }
        else
        {
            reinterpret_cast<::Tile *>((m_pTiles[29]))->Set(0xff4, 1);
            reinterpret_cast<::Tile *>((m_pTiles[25]))->Set(0xff4, 1);
            reinterpret_cast<::Tile *>((m_pTiles[26]))->Set(0xff4, 1);
            reinterpret_cast<::Tile *>((m_pTiles[28]))->Set(0xff4, 1);
            reinterpret_cast<::Tile *>((m_pTiles[27]))->Set(0xff4, 1);
        }
    }
    else
    {
        reinterpret_cast<::Tile *>((m_pTiles[25]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((m_pTiles[26]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((m_pTiles[28]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((m_pTiles[27]))->Set(0xfa3, 0);
        reinterpret_cast<::Tile *>((m_pTiles[29]))->Set(0xfa3, 0);
    }
    float fAPRatioPtr = ::FUN_00647b70(0, (*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))->kAVOwner.GetBaseActorValue(0x10));
    if (fAPRatioPtr != 0)
    {
        fAPRatioPtr = ::FUN_00647b70(0, (*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))->kAVOwner.GetActorValue(0x10)) / fAPRatioPtr;
    }
    ::fnv_007748b0::UpdateMeterTile((::fnv_007748b0::Tile *)(m_pTiles[18]), fAPRatioPtr, 0, 0, 0);
    ::fnv_00779070::FUN_00779070((::fnv_00779070::CompassMovie *)(m_pTiles[23]), (::fnv_00779070::CompassTileList *)(m_pTiles[20]), (::fnv_00779070::CompassTileList *)(m_pTiles[21]), (::fnv_00779070::CompassTileList *)(m_pTiles[22]));
    int iRawB = ((int)(reinterpret_cast<::FUN_00a24f10_Class *>((pInputA))->FUN_00a24f10(0x10)));
    int iKeyTwo = iRawB >> 16;
    int iMidRes = (iRawB & 0xff00) >> 8;
    int iLowTwo = iRawB & 0xff;
    if (((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) != 4)
    {
        if (reinterpret_cast<::HotkeyWheelDisplay *>((pInputA))->SetHotkeyItem(0x10, 1) && ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) != 1)
        {
            if (!::FUN_004b71d0() || (iLowTwo != 10 && iLowTwo != 11 && iLowTwo != 0x11))
            {
                reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::VATSX *>(&::g_011f2250))))->CreateObject(1, 0);
                m_bStateFlag2 = 0;
            }
        }
        else if (!reinterpret_cast<::HotkeyWheelDisplay *>((pInputA))->SetHotkeyItem(0x10, 0) && ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 1)
        {
            reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::VATSX *>(&::g_011f2250))))->CreateObject(2, 0);
            m_bStateFlag2 = 1;
        }
    }
    reinterpret_cast<::AimPlayer *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->FUN_009445b0(reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimerX *>(&::g_timeGlobal))))->GetStoredFloatValue(), 0, (unsigned short *)(0), 0);
    if ((::FUN_00709d40() && (::fnv_00717a40::FUN_00717a40(10, 1) == 1 || ::fnv_00717a40::FUN_00717a40(6, 1) == 1)) ||
        (reinterpret_cast<::ButtonDevice *>((pInputA))->FUN_00a23a50(1, 1) && iMidRes != 1))
    {
        if ((!::FUN_004b71d0() && !m_bAdditionalStateFlag) ||
            (::FUN_004b71d0() && ::fnv_00717a40::FUN_00717a40(10, 1) == 1))
        {
            if (((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 2 && m_bFirstFlag)
            {
                UpdateQueueEntry(0, 0, 0);
                (*reinterpret_cast<::VATSMenuX * *>(&::DAT_011db0d4))->m_fHitChance = (*reinterpret_cast<::VATSMenuX * *>(&::DAT_011db0d4))->FUN_007f48e0();
            }
            UpdateHitChanceDisplay();
        }
    }
    if (!reinterpret_cast<::MenuM *>(this)->UpdateVatsTargeting())
    {
        return;
    }
    FormX* pEquippedNew = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetEquippedWeapon();
    WeaponX* pWeaponOld = pEquippedNew ? ((::WeaponX *)(reinterpret_cast<::InventoryEntryFields *>((pEquippedNew))->pObject)) : 0;
    bool bHasModsM = pWeaponOld ? reinterpret_cast<::FUN_00474a80_Class *>(&(pWeaponOld->kMods))->FUN_00474a80() : 0;
    FUN_007f3070();
    if (((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) != 4)
    {
        ::DAT_011dea34 = 0;
        reinterpret_cast<::fnv_00964260::SelActor *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->FUN_00964260();
        reinterpret_cast<::fnv_008d3550::FaceActor *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->UpdateFaceAnimation(reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimerX *>(&::g_timeGlobal))))->GetStoredFloatValue());
        reinterpret_cast<::UAMActor *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->FUN_008885e0((::UAMAnim *)(void *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))->GetAnimation()), 0.0f);
        (*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))->UpdateCamera(0, 0);
        reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->UpdateCameraMode();
        ::fnv_007ec3a0::UpdateVatsTargetHighlight(0);
        {
            InterfaceManagerX* pInterfaceTwo31 = ((::InterfaceManagerX *)(::fnv_004b7210::FUN_004b7210()));
            int iMenuDepthZ = reinterpret_cast<::InterfaceManager *>((pInterfaceTwo31))->FUN_00747d00();
            int iMenuModeIn = reinterpret_cast<::FUN_0073b020_shell *>((pInterfaceTwo31))->FUN_0073b020();
        }
        static int s_iScreenWidth = ::InterfaceManager::UpdateInterfaceState();
        static int s_iScreenHeight = ::FUN_00715da0();
        static int s_iSafeWidth = ::FUN_007177c0();
        static int s_iSafeHeight = ::fnv_00717820::FUN_00717820();
        if ((reinterpret_cast<::FUN_00a24180_shell *>((pInputA))->FUN_00a24180(0x12, 0) && iKeyTwo != 0x12) ||
            (::FUN_004b71d0() && ::fnv_00717a40::FUN_00717a40(9, 1) == 2 &&
             ((::QueueX *)(reinterpret_cast<::SimpleListNodeView*>(&((*reinterpret_cast<::VATSX *>(&::g_011f2250))))->m_item))->GetSize() > 0 && ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 2))
        {
            xFUN_00705780();
            return;
        }
        {
            int iModeNum76 = 0;
            if ((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))
            {
                if (::FUN_007eeb50(1, 0, iMidRes))
                {
                    xDAT_011db180 = iModeNum76 = 1;
                }
                else if (::FUN_007eeb50(2, 0, iMidRes))
                {
                    xDAT_011db180 = iModeNum76 = 2;
                }
                else if (::FUN_007eeb50(3, 0, iMidRes))
                {
                    xDAT_011db180 = iModeNum76 = 3;
                }
                else if (xDAT_011db180 && !::FUN_007eeb50(xDAT_011db180, 1, iMidRes))
                {
                    xDAT_011db180 = 0;
                }
            }
            else
            {
                xDAT_011db180 = 0;
            }
            ::DAT_011db0b2 = 0;
            ::DAT_011db0b3 = 0;
            if (reinterpret_cast<::sa040a0::Owner *>((m_pTiles[30]))->IsAllChildrenFlag0())
            {
                if (::DAT_011db0b8 > m_fOverrideActionPoints)
                {
                    reinterpret_cast<::Tile *>((m_pTiles[30]))->Set(0xfaf, 0);
                }
                else
                {
                    reinterpret_cast<::Tile *>((m_pTiles[30]))->Set(0xfaf, 1);
                }
            }
            else if (iModeNum76 == 2)
            {
                iModeNum76 = 0;
            }
            if (reinterpret_cast<::sa040a0::Owner *>((m_pTiles[31]))->IsAllChildrenFlag0())
            {
                if (::DAT_011db0c0 > m_fOverrideActionPoints)
                {
                    reinterpret_cast<::Tile *>((m_pTiles[31]))->Set(0xfaf, 0);
                }
                else
                {
                    reinterpret_cast<::Tile *>((m_pTiles[31]))->Set(0xfaf, 1);
                }
            }
            else if (iModeNum76 == 3)
            {
                iModeNum76 = 0;
            }
            float fCostX = ::GetObjectValue((::SpawnedObject *)(pWeaponOld));
            float fShownCostOut = fCostX;
            switch (iModeNum76)
            {
            case 2:
                fCostX = ::DAT_011db0b8;
                break;
            case 3:
                fCostX = ::DAT_011db0c0;
                break;
            }
            switch (xDAT_011db180)
            {
            case 2:
                fShownCostOut = ::DAT_011db0b8;
                break;
            case 3:
                fShownCostOut = ::DAT_011db0c0;
                break;
            }
            if (((bool)(::fnv_009526b0::FUN_009526b0())))
            {
                fCostX = 0.0f;
                fShownCostOut = 0.0f;
            }
            FUN_007f28d0();
            static int s_iBrightness = ::FUN_00a00940("_Brightness", -1);
            if ((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)) && fShownCostOut > m_fOverrideActionPoints && xDAT_011db180)
            {
                ::UpdateBarWidths((::BarTile *)(m_pTiles[9]), (::BarTile *)(m_pTiles[10]), fShownCostOut / m_fValue1, 0.0f, 1, 0);
            }
            else
            {
                ::UpdateBarWidths((::BarTile *)(m_pTiles[9]), (::BarTile *)(m_pTiles[10]), (m_fOverrideActionPoints - fShownCostOut) / m_fValue1,
                              m_fOverrideActionPoints / m_fValue1, 1, 0);
                reinterpret_cast<::Tile *>((m_pTiles[12]))->Set(0xfa3, 0);
            }
            if ((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)) && iModeNum76)
            {
                bool bBusy = !::FUN_004b71d0() && ::FUN_007f6af0((::Owner007f6af0 *)this);
                if (!bBusy && m_pTargetChance->fHitChance > 0)
                {
                    if ((::FUN_004b71d0() && ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 2) ||
                        (!::FUN_004b71d0() && ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 2 &&
                         (!m_bAdditionalStateFlag || iModeNum76 != 1)))
                    {
                        int iActionZ = ::FUN_0066dba0(pWeaponOld ? pWeaponOld->GetWeaponType() : 0);
                        unsigned char ucShotsA39 = xFUN_007f5050(iActionZ, 0);
                        if (ucShotsA39 >= m_fValue4 && pWeaponOld && ((void *)(reinterpret_cast<::AmmoOwner *>((pWeaponOld))->FUN_00525980((::AmmoActor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))) &&
                            reinterpret_cast<::FUN_004fe160_cls *>((pWeaponOld))->GetFlaggedValue(0) > 1)
                        {
                            fCostX += ::FUN_0066dca0(9, 1);
                        }
                        AmmoListX* pAmmoListOne = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetAmmoList();
                        bool bCanFireZ95 =
                            !pWeaponOld ? false
                                        : ((pWeaponOld->GetWeaponType() != 10 && pWeaponOld->GetWeaponType() != 13) ||
                                           (pAmmoListOne && (unsigned int)((std::intptr_t)(reinterpret_cast<::Callees *>((pAmmoListOne))->FUN_00726070())) >
                                                                ((::QueueX *)(reinterpret_cast<::SimpleListNodeView*>(&((*reinterpret_cast<::VATSX *>(&::g_011f2250))))->m_item))->GetSize()));
                        if ((!pWeaponOld || (pWeaponOld->GetWeaponType() != 10 && pWeaponOld->GetWeaponType() != 13) ||
                             bCanFireZ95) &&
                            (!bHasModsM || m_fValue5 + m_fValue4 > 0) && iActionZ != 0x16 &&
                            m_fOverrideActionPoints >= fCostX &&
                            (!pWeaponOld || !((void *)(reinterpret_cast<::AmmoOwner *>((pWeaponOld))->FUN_00525980((::AmmoActor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))) || m_fValue5 + m_fValue4 > 0) &&
                            (!pWeaponOld || !((void *)(reinterpret_cast<::AmmoOwner *>((pWeaponOld))->FUN_00525980((::AmmoActor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))) ||
                             (pAmmoListOne && ((std::intptr_t)(reinterpret_cast<::Callees *>((pAmmoListOne))->FUN_00726070())) > 0)) &&
                            (!FindEntryForRef() || (int)(((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(FindEntryForRef())->m_item))->fHitChance * 100.0) > 0))
                        {
                            CommandX* pCommandA55 = new CommandX;
                            void* pRaceItemNum =
                                (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsActor()
                                    ? ((void *)(reinterpret_cast<::FUN_005e5130_Class *>((((::ActorBaseX *)(reinterpret_cast<::Actor *>(((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->GetActorBase()))->GetRace()))->FUN_005e5130(::DAT_011a59f0)))
                                    : 0;
                            FormX* pTargetEquippedQ96 =
                                (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsActor() ? ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->GetBaseTexture()))->GetEquippedWeapon() : 0;
                            WeaponX* pTargetWeaponX4 = pTargetEquippedQ96 ? ((::WeaponX *)(reinterpret_cast<::InventoryEntryFields *>((pTargetEquippedQ96))->pObject)) : 0;
                            if (FindEntryForRef())
                            {
                                m_pSelectedChance = ((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(FindEntryForRef())->m_item));
                            }
                            bool bLimbSetNum = false;
                            if (!pWeaponOld || ::FUN_006450c0((::TESObjectWEAP *)(pWeaponOld)))
                            {
                                float fRandIn = ::RandomFloat(0.0f, 100.0f);
                                int iCountB = 0;
                                int iLimbOld = -1;
                                ListX<ChanceX*>* pNodeIn = &((::TargetX *)(reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->m_item))->kLimbs;
                                while (pNodeIn && !pNodeIn->IsEmpty())
                                {
                                    switch (((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(pNodeIn)->m_item))->m_iActionValue)
                                    {
                                    case 1:
                                    case 2:
                                        iLimbOld = ((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(pNodeIn)->m_item))->m_iActionValue;
                                        iCountB++;
                                        break;
                                    case 0:
                                    case 3:
                                    case 4:
                                    case 5:
                                    case 6:
                                        iCountB++;
                                        break;
                                    }
                                    pNodeIn = ((::ListX< ::ChanceX *> *)(reinterpret_cast<::Callees *>((pNodeIn))->FUN_00726070()));
                                }
                                if (!pWeaponOld && iModeNum76 == 2 && iLimbOld != -1)
                                {
                                    pCommandA55->m_iActionValue = reinterpret_cast<::FUN_007f3bf0_cls *>(this)->FUN_007f3bf0(iLimbOld);
                                    bLimbSetNum = true;
                                }
                                else if (iCountB > 0)
                                {
                                    float fStepX = 100.0 / iCountB;
                                    int iPickM99 = ::FUN_00404010(fRandIn, 1.0f) / fStepX;
                                    iCountB = 0;
                                    pNodeIn = &((::TargetX *)(reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->m_item))->kLimbs;
                                    while (pNodeIn && !pNodeIn->IsEmpty())
                                    {
                                        switch (((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(pNodeIn)->m_item))->m_iActionValue)
                                        {
                                        case 0:
                                        case 1:
                                        case 2:
                                        case 3:
                                        case 4:
                                        case 5:
                                        case 6:
                                            if (iCountB == iPickM99)
                                            {
                                                pCommandA55->m_iActionValue =
                                                    reinterpret_cast<::FUN_007f3bf0_cls *>(this)->FUN_007f3bf0(((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(pNodeIn)->m_item))->m_iActionValue);
                                                bLimbSetNum = true;
                                            }
                                            iCountB++;
                                            break;
                                        }
                                        pNodeIn = ((::ListX< ::ChanceX *> *)(reinterpret_cast<::Callees *>((pNodeIn))->FUN_00726070()));
                                    }
                                }
                            }
                            if (!bLimbSetNum)
                            {
                                pCommandA55->m_iActionValue = reinterpret_cast<::FUN_007f3bf0_cls *>(this)->FUN_007f3bf0(m_pTargetChance->m_iActionValue);
                            }
                            pCommandA55->ucShots = xFUN_007f5050(iActionZ, 0);
                            pCommandA55->ucExtra = ::FUN_00647b70(xFUN_007f5050(iActionZ, 1) - pCommandA55->ucShots, 0);
                            if (iModeNum76 == 2)
                            {
                                if (pWeaponOld && reinterpret_cast<::FUN_007ebd10_This *>((pWeaponOld))->FUN_007ebd10() > 0)
                                {
                                    pCommandA55->eAction = 0x10;
                                }
                                else if ((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsCreature())
                                {
                                    pCommandA55->eAction = 0x15;
                                }
                                else
                                {
                                    pCommandA55->eAction = 0x11;
                                }
                            }
                            else if (iModeNum76 == 3)
                            {
                                pCommandA55->eAction = 0x14;
                            }
                            else
                            {
                                pCommandA55->eAction = iActionZ;
                            }
                            pCommandA55->pTarget = (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc));
                            pCommandA55->fAPCost = fCostX;
                            float fThresholdA52 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting551)))))) * 100.0;
                            float fRollQ96 = ::RandomFloat(0.0f, 100.0f);
                            if (::VATSCreateDAT_011db0b0 && iActionZ == 0 && fRollQ96 <= fThresholdA52)
                            {
                                pCommandA55->bFlag7 = 1;
                            }
                            if (reinterpret_cast<::VatsList9c9 *>(&((*reinterpret_cast<::VATSX *>(&::g_011f2250))))->IsValidCommand((::VatsCmd9c9 *)(pCommandA55)) && (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsActor() && !bLimbSetNum)
                            {
                                RaceX* pRaceB70 = ((::ActorBaseX *)(reinterpret_cast<::Actor *>(((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->GetActorBase()))->GetRace();
                                void* pElement = ((void *)(reinterpret_cast<::FUN_005e5130_Class *>((pRaceB70))->FUN_005e5130(0x19)));
                                if (pElement)
                                {
                                    pCommandA55->m_iActionValue = 0x19;
                                }
                                else
                                {
                                    pElement = ((void *)(reinterpret_cast<::FUN_005e5130_Class *>((pRaceB70))->FUN_005e5130(0x1a)));
                                    if (pElement)
                                    {
                                        pCommandA55->m_iActionValue = 0x1a;
                                    }
                                    else
                                    {
                                        ElemX** ppElemsB2 = ((::ElemX **)(::FUN_006a9540((char *)(pRaceB70))));
                                        bool bFound96 = false;
                                        for (int iNew = 0; iNew < 15 && !bFound96; iNew++)
                                        {
                                            if (ppElemsB2[iNew])
                                            {
                                                pCommandA55->m_iActionValue = ((char)(reinterpret_cast<::FUN_005e5190_Class *>((ppElemsB2[iNew]))->GetByte63()));
                                                bFound96 = true;
                                            }
                                        }
                                    }
                                }
                            }
                            reinterpret_cast<::SoundListView *>(&((*reinterpret_cast<::VATSX *>(&::g_011f2250))))->AddCommand((::SoundListEntry *)(pCommandA55));
                            ListX<ChanceX*>* pLimbNodeRes38 = FindEntryForRef();
                            float fLimbChanceZ = pLimbNodeRes38 ? ((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(FindEntryForRef())->m_item))->fHitChance : 0.0f;
                            if (m_bStateFlag4)
                            {
                                int iShotsAtLimb = reinterpret_cast<::OwnQ *>(this)->GetConsecutiveMatchCount();
                                fLimbChanceZ += (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingX *>(&::g_011d4210)))))) * iShotsAtLimb) / 100.0;
                            }
                            pCommandA55->bFlag4 =
                                (*(*reinterpret_cast<::SettingX *>(&::g_011db114)).Bool() && FindEntryForRef()) ? true : ::RandomBoolean(fLimbChanceZ);
                            UpdateLimbTiles();
                            if (FUN_007f28d0() && pWeaponOld && pWeaponOld->GetWeaponType() != 10 &&
                                pWeaponOld->GetWeaponType() != 13 &&
                                reinterpret_cast<::FUN_004fe160_cls *>((pWeaponOld))->GetFlaggedValue(0) != reinterpret_cast<::FUN_00524b60_shell *>((pWeaponOld))->GetByteAt102() &&
                                m_fValue5 + m_fValue4 > 0)
                            {
                                UpdateQueueEntry(pCommandA55, 1, iModeNum76 != 1);
                            }
                            else
                            {
                                UpdateQueueEntry(pCommandA55, 0, iModeNum76 != 1);
                            }
                            if (m_fOverrideActionPoints < fCostX)
                            {
                                reinterpret_cast<::Tile *>((m_pTiles[7]))->Set(0xfaf, 0);
                            }
                            UpdateHitChanceDisplay();
                        }
                        else if (FindEntryForRef() && (int)(((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(FindEntryForRef())->m_item))->fHitChance * 100.0) <= 0 &&
                                 ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 2 && m_bFirstFlag)
                        {
                            BSSoundHandleX kSoundIn;
                            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleX &)(kSoundIn))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleX &)(((::AudioX *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIVATSEnterFail", 0x121))));
                            reinterpret_cast<::FUN_00ad8830_shell *>(&(kSoundIn))->FUN_00ad8830(0);
                            reinterpret_cast<::MessageHUD *>(((*reinterpret_cast<::UIMessageX * *>(&::g_pHudMainMenuInstance))))->AddMessage((*reinterpret_cast<::SettingX *>(&::g_011d3894)).String(), 2, (const char *)(0), (const char *)(0), 2.0f, 0);
                        }
                        else if (m_fOverrideActionPoints < fCostX)
                        {
                            AudioMgrX* pAudioMgrK = ((::AudioMgrX *)(::FUN_00ad9060()));
                            BSSoundHandleX kSoundIn;
                            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleX &)(kSoundIn))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleX &)((*(::BSSoundHandleX *)(reinterpret_cast<::AudioClass_ae5680 *>((pAudioMgrK))->ResolveAudioHandle((::Handle_ae5680 *)("UIVATSInsufficientAP"), 0x121, {}))))));
                            reinterpret_cast<::FUN_00ad8830_shell *>(&(kSoundIn))->FUN_00ad8830(0);
                            reinterpret_cast<::Tile *>((m_pTiles[12]))->Set(0xfa3, 1);
                        }
                        else if (m_fValue5 + m_fValue4 == 0)
                        {
                            reinterpret_cast<::MessageHUD *>(((*reinterpret_cast<::UIMessageX * *>(&::g_pHudMainMenuInstance))))->AddMessage((*reinterpret_cast<::SettingX *>(&::g_011d28c8)).String(), 2, (const char *)(0), (const char *)(0), 2.0f, 0);
                            BSSoundHandleX kSoundIn;
                            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleX &)(kSoundIn))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleX &)(((::AudioX *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIVATSEnterFail", 0x121))));
                            reinterpret_cast<::FUN_00ad8830_shell *>(&(kSoundIn))->FUN_00ad8830(0);
                        }
                        (*reinterpret_cast<::VATSMenuX * *>(&::DAT_011db0d4))->m_fHitChance = (*reinterpret_cast<::VATSMenuX * *>(&::DAT_011db0d4))->FUN_007f48e0();
                    }
                    else if (!::FUN_004b71d0() && ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 1 &&
                             !m_bAdditionalStateFlag)
                    {
                        ::FUN_007f6af0((::Owner007f6af0 *)this);
                    }
                }
                else if (!bBusy && m_pTargetChance->bCrippled && ((std::intptr_t)((*reinterpret_cast<::VATSX *>(&::g_011f2250)).mode)) == 2 && m_bFirstFlag)
                {
                    AudioMgrX* pAudioMgrK = ((::AudioMgrX *)(::FUN_00ad9060()));
                    BSSoundHandleX kSoundIn;
                    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleX &)(kSoundIn))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleX &)((*(::BSSoundHandleX *)(reinterpret_cast<::AudioClass_ae5680 *>((pAudioMgrK))->ResolveAudioHandle((::Handle_ae5680 *)("UIVATSInsufficientAP"), 0x121, {}))))));
                    reinterpret_cast<::FUN_00ad8830_shell *>(&(kSoundIn))->FUN_00ad8830(0);
                    if (m_pTargetChance->fHitChance == 0)
                    {
                        reinterpret_cast<::MessageHUD *>(((*reinterpret_cast<::UIMessageX * *>(&::g_pHudMainMenuInstance))))->AddMessage((*reinterpret_cast<::SettingX *>(&::g_011d3894)).String(), 2, (const char *)(0), (const char *)(0), 2.0f, 0);
                    }
                }
            }
            else if (!::FUN_004b71d0() && reinterpret_cast<::FUN_00a24180_shell *>((pInputA))->FUN_00a24180(0x1e, 1) &&
                     reinterpret_cast<::FUN_00a24180_shell *>((pInputA))->FUN_00a24180(0x1e, 3) && iKeyTwo != 0x1e)
            {
                HandleClick(2, 0);
            }
            else if (!::FUN_004b71d0() && reinterpret_cast<::FUN_00a24180_shell *>((pInputA))->FUN_00a24180(0x20, 1) &&
                     reinterpret_cast<::FUN_00a24180_shell *>((pInputA))->FUN_00a24180(0x20, 3) && iKeyTwo != 0x20)
            {
                HandleClick(3, 0);
            }
        }
    }
}
// @fnv 0x007f0ea0
void VATSMenuX::UpdateHitChanceDisplay()
{
    TargetX* target4;
    ListX<ChanceX*>* node_;
    ListX<TargetX*>* targets_2;
    ListX<ChanceX*>* nextNodeTmp;
    ChanceX* pItem;
    char buffer3[8];
    int count7;
    ChanceX* pOtherItem;

    targets_2 = this->FindListEntryForTarget((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)));
    target4 = ((::TargetX *)(reinterpret_cast<::SimpleListNodeView*>(targets_2)->m_item));
    node_ = &target4->kLimbs;
    while (node_ && !node_->IsEmpty())
    {
        pItem = ((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(node_)->m_item));
        nextNodeTmp = ((::ListX< ::ChanceX *> *)(reinterpret_cast<::Callees *>((node_))->FUN_00726070()));
        switch (pItem->m_iActionValue)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            while (nextNodeTmp && !nextNodeTmp->IsEmpty())
            {
                pOtherItem = ((::ChanceX *)(reinterpret_cast<::SimpleListNodeView*>(nextNodeTmp)->m_item));
                if (reinterpret_cast<::FUN_007f3bf0_cls *>((this))->FUN_007f3bf0(pItem->m_iActionValue) == reinterpret_cast<::FUN_007f3bf0_cls *>((this))->FUN_007f3bf0(pOtherItem->m_iActionValue))
                {
                    if (((TileX2*)pOtherItem->iHitCount) == 0)
                    {
                        reinterpret_cast<::FUN_007f6e50_This *>((this))->AssignActionTiles((::TargetList *)(::ListX< ::TargetX *> *)(this->FindListEntryForTarget((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))));
                    }
                    if (pOtherItem != pItem)
                    {
                        if (pOtherItem->m_iActionValue == 1)
                        {
                            reinterpret_cast<::Tile *>((((TileX2*)pItem->iHitCount)))->Set(0xfa3, 0);
                        }
                        else if (pItem->m_iActionValue == 1)
                        {
                            reinterpret_cast<::Tile *>((((TileX2*)pOtherItem->iHitCount)))->Set(0xfa3, 0);
                        }
                        else
                        {
                            reinterpret_cast<::Tile *>((((TileX2*)pOtherItem->iHitCount)))->Set(0xfa3, 0);
                        }
                    }
                    if (reinterpret_cast<::TileListBoxCalls *>((((TileX2*)pOtherItem->iHitCount)))->GetFloat(::FUN_00a00940("_MeterPercent", -1)) <
                        reinterpret_cast<::TileListBoxCalls *>((((TileX2*)pItem->iHitCount)))->GetFloat(::FUN_00a00940("_MeterPercent", -1)))
                    {
                        reinterpret_cast<::FUN_00a012d0_t *>((((TileX2*)pItem->iHitCount)))->FUN_00a012d0(::FUN_00a00940("_MeterPercent", -1),
                                       reinterpret_cast<::TileListBoxCalls *>((((TileX2*)pOtherItem->iHitCount)))->GetFloat(::FUN_00a00940("_MeterPercent", -1)),
                                       true);
                    }
                    if (pOtherItem->fHitChance > pItem->fHitChance)
                    {
                        pItem->fHitChance = pOtherItem->fHitChance;
                    }
                }
                nextNodeTmp = ((::ListX< ::ChanceX *> *)(reinterpret_cast<::Callees *>((nextNodeTmp))->FUN_00726070()));
            }
            break;
        }

        count7 =
            (!((QueueX2*)((::QueueX *)(reinterpret_cast<::SimpleListNodeView*>(&((*reinterpret_cast<::VATSX *>(&::g_011f2250))))->m_item)))->IsEmpty() &&
             ((::CommandX *)(reinterpret_cast<::MyList *>((((VATSX2*)&(*reinterpret_cast<::VATSX *>(&::g_011f2250)))))->FUN_009c71f0()))->m_iActionValue == reinterpret_cast<::FUN_007f3bf0_cls *>((this))->FUN_007f3bf0(pItem->m_iActionValue))
                ? reinterpret_cast<::OwnQ *>((this))->GetConsecutiveMatchCount() + 1
                : 0;

        if ((((::WeaponX *)(reinterpret_cast<::FUN_008a1710_shell *>((((ActorX2*)(*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))->FUN_008a1710())) == 0 ||
             ::FUN_006450c0((::TESObjectWEAP *)(::WeaponX *)(((::WeaponX *)(reinterpret_cast<::FUN_008a1710_shell *>((((ActorX2*)(*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))->FUN_008a1710()))))) &&
            (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsActor() && ((ActorBaseStandIn*)((::ActorBaseX *)(reinterpret_cast<::Actor *>(((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))))->GetActorBase())))->sub30.v14())
        {
            ::FUN_00406d00(buffer3, 8, "%i%%", 0);
            pItem->fHitChance = 0.0f;
        }
        else
        {
            if (count7 > 0 && this->m_bStateFlag4)
            {
                ::FUN_00406d00(
                    buffer3, 8, "%i%%",
                    ::FUN_00647b70(0, MinInt((int)(pItem->fHitChance * 100.0 + *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingX *>(&::g_011d4210)))))) * count7), 95)));
            }
            else
            {
                ::FUN_00406d00(buffer3, 8, "%i%%", ::FUN_00647b70(0, MinInt((int)(pItem->fHitChance * 100.0), 95)));
            }
        }

        if (((TileX2*)pItem->iHitCount) == 0)
        {
            reinterpret_cast<::FUN_007f6e50_This *>((this))->AssignActionTiles((::TargetList *)(::ListX< ::TargetX *> *)(this->FindListEntryForTarget((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))));
        }
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((TileX2*)pItem->iHitCount)))->FUN_00a01350(0xfc4, (char *)(buffer3), true);
        node_ = ((::ListX< ::ChanceX *> *)(reinterpret_cast<::Callees *>((node_))->FUN_00726070()));
    }
}
// Advances the VATS targeting sequence: lights/unlights targets, picks the current limb, evaluates limb hits and finishes the target when all limbs are resolved.
// @fnv 0x007f3e00
bool MenuM::UpdateVatsTargeting()
{
    int disabledVal;
    int aBIsOpen;
    LimbListM* aBFoundB;
    bool aBClose;
    LimbListM* aBBusy1;
    LimbM* limb7;
    float valueB2;
    LimbListM* prior2;
    bool refresh;
    LimbListM* header9;
    int count1;
    LimbListM* scan8;
    float aArrow;
    LimbListM* fill6;
    bool all5;
    LimbListM* iter14;
    bool aActorPos6;
    LimbListM* next4;
    LimbM* torsoVal;
    WeaponM* weaponItemA;
    ItemM* itemExtra8;
    TargetListM* a9;
    TargetM* target22;

    if (!(*reinterpret_cast<::ActorM * *>(&::DAT_011f21cc)) || closing)
        return false;
    if (((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::StateM *>(&::g_011f2250))))->GetName())) == 1)
    {
        if (!lit)
        {
            aBIsOpen = 1;
            reinterpret_cast<::FUN_0044ac20_class *>((FUN_00705910()))->FUN_0044ac20(&aBIsOpen);
            a9 = &(*reinterpret_cast<::TargetListM *>(&::g_011db150));
            while (a9 && !a9->FUN_008256d0())
            {
                reinterpret_cast<::FUN_00800e50_Class *>((FUN_00705910()))->FUN_00800d50((intptr_t)(((::TargetM *)(reinterpret_cast<::SimpleListNodeView*>(a9)->m_item))->actor));
                a9 = ((::TargetListM *)(reinterpret_cast<::Callees *>((a9))->FUN_00726070()));
            }
            lit = true;
        }
        reinterpret_cast<::FUN_00800e50_Class *>((FUN_00705910()))->FUN_00800e50((intptr_t)((*reinterpret_cast<::ActorM * *>(&::DAT_011f21cc))));
        return true;
    }
    else if (lit)
    {
        lit = false;
        reinterpret_cast<::Target *>((FUN_00705910()))->FUN_00800ac0((::TargetActor *)(::ActorM *)(0), 0, 0);
        reinterpret_cast<::FUN_00800ed0_This *>((FUN_00705910()))->FUN_00800ed0();
        disabledVal = 0;
        reinterpret_cast<::FUN_0044ac20_class *>((FUN_00705910()))->FUN_0044ac20(&disabledVal);
        ::fnv_007ec3a0::UpdateVatsTargetHighlight(1);
        return false;
    }
    target22 = ((::TargetM *)(reinterpret_cast<::SimpleListNodeView*>(FindListEntryForTarget((*reinterpret_cast<::ActorM * *>(&::DAT_011f21cc))))->m_item));
    if (target22)
    {
        itemExtra8 = ((::ProcessM *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorM * *>(&::_g_thePlayer))))->GetBaseTexture()))->current();
        weaponItemA = itemExtra8 ? ((::WeaponM *)(reinterpret_cast<::InventoryEntryFields *>((itemExtra8))->pObject)) : 0;
        if (!target22->done)
        {
            if (!((bool)(reinterpret_cast<::FUN_007f4810_shell *>((FUN_00705910()))->GetByteAtOffset())) && !::fnv_00709d10::g_flag)
            {
                reinterpret_cast<::FUN_00800700_Class *>((FUN_00705910()))->FUN_00800700();
                if (!target22->actor->check())
                {
                    reinterpret_cast<::Target *>((FUN_00705910()))->FUN_00800ac0((::TargetActor *)(target22->actor), 1, 1);
                    reinterpret_cast<::FUN_008009d0_cls *>((FUN_00705910()))->FUN_008009d0();
                }
            }
            if (true)
            {
                if (((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::StateM *>(&::g_011f2250))))->GetName())) != 3)
                {
                    reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::StateM *>(&::g_011f2250))))->CreateObject(3, false);
                    (*reinterpret_cast<unsigned int *>(&::fnv_007f07a0::DAT_011db0dc)) = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimerM *>(&::g_timeGlobal))))->FUN_00825c00();
                }
                else if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimerM *>(&::g_timeGlobal))))->FUN_00825c00() - (*reinterpret_cast<unsigned int *>(&::fnv_007f07a0::DAT_011db0dc)) > 2000)
                {
                    scan8 = &target22->limbs;
                    count1 = 0;
                    aArrow = 0;
                    while (scan8 && !scan8->FUN_008256d0())
                    {
                        if (((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(scan8)->m_item))->done)
                        {
                            ++count1;
                            aArrow += ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(scan8)->m_item))->chance;
                        }
                        scan8 = ((::LimbListM *)(reinterpret_cast<::Callees *>((scan8))->FUN_00726070()));
                    }
                    reinterpret_cast<::FUN_008009d0_cls *>((FUN_00705910()))->FUN_008009d0();
                    fill6 = &target22->limbs;
                    while (fill6 && !fill6->FUN_008256d0())
                    {
                        if (!((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(fill6)->m_item))->done)
                        {
                            if (((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(fill6)->m_item))->chance <= 0.0)
                                ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(fill6)->m_item))->chance = aArrow / count1;
                            ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(fill6)->m_item))->done = true;
                            ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(fill6)->m_item))->started = true;
                            ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(fill6)->m_item))->failed = false;
                        }
                        fill6 = ((::LimbListM *)(reinterpret_cast<::Callees *>((fill6))->FUN_00726070()));
                    }
                    (*reinterpret_cast<unsigned int *>(&::fnv_007f07a0::DAT_011db0dc)) = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimerM *>(&::g_timeGlobal))))->FUN_00825c00();
                }
                reinterpret_cast<::VATSMenuX *>(this)->FUN_007f28d0();
                next4 = &target22->limbs;
                torsoVal = 0;
                while (next4 && !next4->FUN_008256d0())
                {
                    if (((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(next4)->m_item))->limb == 0)
                        torsoVal = ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(next4)->m_item));
                    next4 = ((::LimbListM *)(reinterpret_cast<::Callees *>((next4))->FUN_00726070()));
                }
                next4 = &target22->limbs;
                while (next4 && !next4->FUN_008256d0())
                {
                    if (!((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(next4)->m_item))->done && !((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(next4)->m_item))->started &&
                        (!heading || ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(next4)->m_item))->active))
                        break;
                    next4 = ((::LimbListM *)(reinterpret_cast<::Callees *>((next4))->FUN_00726070()));
                }

                {
                    all5 = true;
                    iter14 = &target22->limbs;
                    while (iter14 && !iter14->FUN_008256d0())
                    {
                        if (!((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(iter14)->m_item))->done && ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(iter14)->m_item))->active)
                        {
                            all5 = false;
                            break;
                        }
                        iter14 = ((::LimbListM *)(reinterpret_cast<::Callees *>((iter14))->FUN_00726070()));
                    }
                    if (all5 && (!next4 || next4->FUN_008256d0()))
                    {
                        reinterpret_cast<::VATSMenuX *>(this)->UpdateHitChanceDisplay();
                        reinterpret_cast<::FUN_00800a90 *>((FUN_00705910()))->SetOcclusionDisabled();
                        header9 = FindListEntryByValue(25);
                        if (header9 &&
                            reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::PointM &)((((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(header9)->m_item))->pos - *((::PointM *)(::FUN_0045bb80((intptr_t)((*reinterpret_cast<::ActorM * *>(&::_g_thePlayer))->position())))))))->ComputeMagnitude() < 300.0 &&
                            target22 != mLast)
                            current = ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(header9)->m_item));
                        else if (target22 == mLast)
                        {
                            prior2 = FindListEntryByValue(::DAT_011a59f0);
                            current = prior2 ? ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(prior2)->m_item)) : ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(&(target22->limbs))->m_item));
                        }
                        else if (torsoVal)
                        {
                            ::DAT_011a59f0 = 26;
                            current = torsoVal;
                        }
                        else
                            ::DAT_011a59f0 = reinterpret_cast<::FUN_007f3bf0_cls *>(this)->FUN_007f3bf0(current->limb);
                        mLast = target22;
                        target22->done = true;
                        ::fnv_00709d10::g_flag = false;
                        reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::StateM *>(&::g_011f2250))))->CreateObject(2, false);
                        reinterpret_cast<::FUN_008009d0_cls *>((FUN_00705910()))->FUN_008009d0();
                        refresh = false;
                        if (target22->type == 2 || ((::ProcessM *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorM * *>(&::_g_thePlayer))))->GetBaseTexture()))->special() || !weaponItemA ||
                            ::FUN_006450c0((::TESObjectWEAP *)(weaponItemA)))
                            refresh = true;
                        if (refresh)
                            ::fnv_007ec3a0::UpdateVatsTargetHighlight(1);
                        reinterpret_cast<::fnv_007f07a0::Owner7 *>(this)->UpdateLimbHighlight();
                        return true;
                    }
                }
                if (next4 && ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(next4)->m_item)))
                {
                    current = ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(next4)->m_item));
                    if (!((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(next4)->m_item))->started)
                    {
                        ::fnv_007ec3a0::UpdateVatsTargetHighlight(1);
                        ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(next4)->m_item))->started = true;
                    }
                }
                aActorPos6 = true;
                iter14 = &target22->limbs;
                while (iter14 && !iter14->FUN_008256d0())
                {
                    limb7 = ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(iter14)->m_item));
                    valueB2 = 0;
                    if (limb7->started && reinterpret_cast<::FUN_00800a00_cls *>((FUN_00705910()))->GetRatioByIndex(limb7->limb, &valueB2))
                    {
                        limb7->value24 = valueB2;
                        if (reinterpret_cast<::NiPoint3 *>((void *)&(const ::PointM &)(limb7->pos))->FUN_004390c0((const ::NiPoint3 &)((*reinterpret_cast<::PointM *>((void *)&::NiPoint3::ZERO)))))
                            reinterpret_cast<::VATSMenuX *>(this)->UpdateLimbTiles();
                        if (!reinterpret_cast<::FUN_007f06d0_cls *>(this)->FUN_007f06d0((::FUN_007f06d0_Src *)(limb7)))
                        {
                            limb7->failed = true;
                            limb7->started = false;
                        }
                        else
                            limb7->done = true;
                        if (!limb7->done && limb7->active)
                            aActorPos6 = false;
                        reinterpret_cast<::fnv_007f1290::VATSMenu1290 *>(this)->CalculateVATSChance((::fnv_007f1290::ListReader1290 *)(iter14));
                        if (aActorPos6 && !((::LimbListM *)(reinterpret_cast<::Callees *>((iter14))->FUN_00726070())))
                        {
                            reinterpret_cast<::VATSMenuX *>(this)->UpdateHitChanceDisplay();
                            reinterpret_cast<::FUN_00800a90 *>((FUN_00705910()))->SetOcclusionDisabled();
                            aBBusy1 = FindListEntryByValue(25);
                            if (aBBusy1 &&
                                reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::PointM &)((((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(aBBusy1)->m_item))->pos - *((::PointM *)(::FUN_0045bb80((intptr_t)((*reinterpret_cast<::ActorM * *>(&::_g_thePlayer))->position())))))))->ComputeMagnitude() <
                                    300.0 &&
                                target22 != mLast)
                                current = ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(aBBusy1)->m_item));
                            else if (target22 == mLast)
                            {
                                aBFoundB = FindListEntryByValue(::DAT_011a59f0);
                                current = aBFoundB ? ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(aBFoundB)->m_item)) : ((::LimbM *)(reinterpret_cast<::SimpleListNodeView*>(&(target22->limbs))->m_item));
                            }
                            else if (torsoVal)
                            {
                                ::DAT_011a59f0 = 26;
                                current = torsoVal;
                            }
                            else
                                ::DAT_011a59f0 = reinterpret_cast<::FUN_007f3bf0_cls *>(this)->FUN_007f3bf0(current->limb);
                            mLast = target22;
                            reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::StateM *>(&::g_011f2250))))->CreateObject(2, false);
                            reinterpret_cast<::FUN_008009d0_cls *>((FUN_00705910()))->FUN_008009d0();
                            reinterpret_cast<::fnv_007f07a0::Owner7 *>(this)->UpdateLimbHighlight();
                            aBClose = false;
                            if (target22->type == 2 || ((::ProcessM *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorM * *>(&::_g_thePlayer))))->GetBaseTexture()))->special() || !weaponItemA ||
                                ::FUN_006450c0((::TESObjectWEAP *)(weaponItemA)))
                                aBClose = true;
                            if (aBClose)
                                ::fnv_007ec3a0::UpdateVatsTargetHighlight(1);
                            target22->done = true;
                            ::fnv_00709d10::g_flag = false;
                            return true;
                        }
                    }
                    iter14 = ((::LimbListM *)(reinterpret_cast<::Callees *>((iter14))->FUN_00726070()));
                }
                (*reinterpret_cast<::ActorM * *>(&::_g_thePlayer))->UpdateCamera(false, false);
                reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::ActorM * *>(&::_g_thePlayer))))->UpdateCameraMode();
                return true;
            }
        }
        else if (((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::StateM *>(&::g_011f2250))))->GetName())) == 3)
            reinterpret_cast<::NiPoint3Interpolator *>(&((*reinterpret_cast<::StateM *>(&::g_011f2250))))->CreateObject(2, false);
    }
    else
        return false;
    return true;
}
// @fnv 0x007f48e0
float VATSMenuX::FUN_007f48e0()
{
    if (!(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)) || !(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->IsActor())
        return 0.0f;
    float current = 0.0f;
    AttackQueueNode* nodeA = (AttackQueueNode*)((::QueueX *)(reinterpret_cast<::SimpleListNodeView*>(&((*reinterpret_cast<::VATSX *>(&::g_011f2250))))->m_item));
    while (nodeA && !nodeA->FUN_008256d0())
    {
        if ((*((::CommandX **)(&reinterpret_cast<::SimpleListNodeView*>(nodeA)->m_item)))->pTarget == (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))
        {
            float queuedDamage = ::FUN_009b4fe0((::SpawnObj *)(*((::CommandX **)(&reinterpret_cast<::SimpleListNodeView*>(nodeA)->m_item))));
            current -= reinterpret_cast<::fnv_008808a0::ActorProxy *>((((DamageActor*)(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))))->FUN_008808a0(-queuedDamage, (::Actor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))));
        }
        nodeA = ((::AttackQueueNode *)(reinterpret_cast<::Callees *>((nodeA))->FUN_00726070()));
    }
    FormX* objectTmp = ((::ProcessX *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))))->GetBaseTexture()))->GetEquippedWeapon();
    WeaponX* weapon4 = objectTmp ? ((::WeaponX *)(reinterpret_cast<::InventoryEntryFields *>((objectTmp))->pObject)) : 0;
    int key = weapon4 ? ((WeaponTypeCall*)weapon4)->FUN_00446390() : 0;
    int entryVal = ::FUN_0066dba0(key);
    VATS_COMMAND_LIST kItem;
    kItem.eAction = entryVal;
    kItem.bFlag4 = true;
    kItem.pTarget = (*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc));
    kItem.m_iActionValue = reinterpret_cast<::FUN_007f3bf0_cls *>(this)->FUN_007f3bf0(m_pTargetChance->m_iActionValue);
    kItem.ucShots = xFUN_007f5050(entryVal, 0);
    float valueTmp = ::FUN_009b4fe0((::SpawnObj *)(::CommandX *)((CommandX*)&kItem));
    current -= reinterpret_cast<::fnv_008808a0::ActorProxy *>((((DamageActor*)(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))))->FUN_008808a0(-valueTmp, (::Actor *)((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer))));
    if (!((HealthValueOwner*)&(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->kAVOwner)->GetCurrentValue(16))
        return 0.0f;
    if (current > ((HealthValueOwner*)&(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->kAVOwner)->GetCurrentValue(16))
    {
        return (float)((HealthValueOwner*)&(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->kAVOwner)->GetCurrentValue(16);
    }
    else
    {
        return current / ((HealthValueOwner*)&(*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->kAVOwner)->GetValue(16);
    }
}
// Projects each target limb to screen space, updates its tile labels and meters, hides off-screen limbs, and separates overlapping limb tiles.
// @fnv 0x007f1840
void VATSMenuX::UpdateLimbTiles()
{
    ListX<TargetX*>* node_2 = FindListEntryForTarget((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)));
    Target392* target = reinterpret_cast<Target392*>(((::TargetX *)(reinterpret_cast<::SimpleListNodeView*>(node_2)->m_item)));
    ListX<Limb392*>* entry = &target->limbs;
    float scaleB = 0.0f;
    Scene392* object4 = 0;
    Point392 positionVal;
    int x_2 = 0;
    int y6 = 0;
    static int centerX = (int)(::InterfaceManager::UpdateInterfaceState() / 2.0);
    static int centerY = (int)(::FUN_00715da0() / 2.0);
    static int minX = (int)(::FUN_007177c0() * 2.0 + 100.0);
    static int minY = (int)(::fnv_00717820::FUN_00717820() * 2.0 + 100.0);
    static int maxX = (int)(::InterfaceManager::UpdateInterfaceState() - minX - 50.0);
    static int maxY = (int)(::FUN_00715da0() - 2.0 * ::fnv_00717820::FUN_00717820() -
                            reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<Tile392*>((*reinterpret_cast<::VATSMenuX * *>(&::DAT_011db0d4))->m_pTiles[17])))->GetFloat(0xfb0) + 50.0);
    Form392* formTmp =
        reinterpret_cast<Form392*>(((::Process392 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<Actor392*>((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))->GetBaseTexture()))->GetEquippedWeapon());
    Weapon392* weapon7 = formTmp ? ((::Weapon392 *)(reinterpret_cast<::Twin_0044ddc0 *>((formTmp))->GetName())) : 0;
    entry = &target->limbs;
    while (entry && !entry->IsEmpty())
    {
        Race392* form2 = 0;
        Part392* parts3 = 0;
        Limb392* item2 = ((::Limb392 *)(reinterpret_cast<::SimpleListNodeView*>(entry)->m_item));
        if (target->kind == 2)
            object4 = target->actor->GetRoot();
        else if (item2->limb == 14)
        {
            Scene392* head = 0;
            if (reinterpret_cast<Actor392*>((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))->IsActor())
                head = ((::Process392 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<Actor392*>((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))))->GetBaseTexture()))
                           ->GetLimb(reinterpret_cast<Actor392*>((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))->GetLimbData());
            object4 = head;
        }
        else
        {
            form2 = ((::Base392 *)(reinterpret_cast<::Actor *>((reinterpret_cast<Ref392*>((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))))->GetActorBase()))->GetRace();
            parts3 = ((::Part392 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((form2))->GetValueByIndex(item2->limb)));
            if (parts3)
                object4 = ((::Scene392 *)(::FUN_004aae30((::NiAVObject *)(::Scene392 *)(reinterpret_cast<Actor392*>((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))->GetRoot()), (::NiFixedString *)(::fnv_0043b230::FUN_0043b230((const char *)(parts3))))));
        }
        if (object4)
        {
            positionVal = *((::Point392 *)(::FUN_0045bb80((intptr_t)(object4))));
            item2->world = positionVal;
            reinterpret_cast<::ScreenCamera *>((((::ProjectionResult392 *)(::FUN_0045c670()))->FUN_006629f0()))->ProjectToScreen(*(const ::NiPoint3 *)nullptr, *(float *)nullptr, *(float *)nullptr, {});
        }
        item2->x *= ::InterfaceManager::UpdateInterfaceState();
        item2->y = (1.0 - item2->y) * ::FUN_00715da0();
        Matrix392 matrix;
        reinterpret_cast<FUN_007f51b0_shell*>(this)->FUN_007f51b0(reinterpret_cast<FUN_005df510_shell*>(&matrix));
        item2->projected = matrix * item2->world;
        Form392* ba = reinterpret_cast<Actor392*>((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))->IsActor()
                          ? reinterpret_cast<Form392*>(
                                ((::Process392 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<Actor392*>((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc)))))->GetBaseTexture()))->GetEquippedWeapon())
                          : 0;
        float l = ba ? reinterpret_cast<::FUN_004bcdb0_shell *>((ba))->FUN_004bcdb0(1) / 100.0 : 1.0;
        Weapon392* weaponVal = ba ? ((::Weapon392 *)(reinterpret_cast<::Twin_0044ddc0 *>((ba))->GetName())) : 0;
        reinterpret_cast<Menu392*>(this)->flag118 = false;
        if (target->kind == 2 || ((::Process392 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<Actor392*>((*reinterpret_cast<::ActorX * *>(&::_g_thePlayer)))))->GetBaseTexture()))->HasMeleeWeapon() ||
            !weapon7 || ::FUN_006450c0((::TESObjectWEAP *)(weapon7)))
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((item2->tile))->FUN_00a01350(::FUN_00a00940("_LimbName", -1), (char *)(reinterpret_cast<::FUN_0055d520_shell *>((target->actor))->FUN_0055d520()), true);
            reinterpret_cast<::FUN_00a012d0_t *>((item2->tile))->FUN_00a012d0(
                ::FUN_00a00940("_MeterPercent", -1),
                FUN_0040ebd0(1.0f, FUN_00404010(0.0f, (float)(reinterpret_cast<::HealthReferenceEntry *>((target->actor))->FUN_00568ad0() / 100.0))), true);
        }
        else if (parts3)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((item2->tile))->FUN_00a01350(::FUN_00a00940("_LimbName", -1), (char *)(((const char *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((parts3))->FUN_006838b0()))), true);
            reinterpret_cast<::FUN_00a012d0_t *>((item2->tile))->FUN_00a012d0(
                ::FUN_00a00940("_MeterPercent", -1),
                FUN_0040ebd0(
                    1.0f, FUN_00404010(
                              0.0f, (float)((*reinterpret_cast<::ActorX * *>(&::DAT_011f21cc))->kAVOwner.GetActorValue(reinterpret_cast<::FUN_007f3bf0_cls *>(this)->FUN_007f3bf0(item2->limb)) / 100.0))),
                true);
        }
        else if (weaponVal)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((item2->tile))->FUN_00a01350(::FUN_00a00940("_LimbName", -1), (char *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(weaponVal->name))->FUN_00408da0()))), true);
            reinterpret_cast<::FUN_00a012d0_t *>((item2->tile))->FUN_00a012d0(
                ::FUN_00a00940("_MeterPercent", -1),
                FUN_0040ebd0(1.0f, FUN_00404010(0.0f, reinterpret_cast<::FUN_004bcdb0_shell *>((ba))->FUN_004bcdb0(0) / (::TESHealthForm::GetBaseHealth((::TESForm *)(::Weapon392 *)(((::Weapon392 *)(reinterpret_cast<::Twin_0044ddc0 *>((ba))->GetName()))))
                                                                                 ? ::TESHealthForm::GetBaseHealth((::TESForm *)(::Weapon392 *)(((::Weapon392 *)(reinterpret_cast<::Twin_0044ddc0 *>((ba))->GetName()))))
                                                                                 : 1))),
                true);
        }
        if (item2->x < 0.0 || item2->x > ::InterfaceManager::UpdateInterfaceState() || item2->y < 0.0 || item2->y > ::FUN_00715da0())
        {
            item2->visible = false;
            item2->crippled = false;
            item2->selected = false;
            reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((item2->tile))->RemoveFadeItemsForTile(0xfa9);
            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((item2->tile))->StartFade(0xfa9, reinterpret_cast<::TileListBoxCalls *>((item2->tile))->GetFloat(0xfa9), 0.0f, 0.5f, 0);
        }
        else
            item2->visible = true;
        entry = ((::ListX< ::Limb392 *> *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070()));
    }
    entry = &reinterpret_cast<Target392*>(((::TargetX *)(reinterpret_cast<::SimpleListNodeView*>(node_2)->m_item)))->limbs;
    while (entry && !entry->IsEmpty())
    {
        Limb392* item2 = ((::Limb392 *)(reinterpret_cast<::SimpleListNodeView*>(entry)->m_item));
        if (item2->visible)
        {
            switch (item2->limb)
            {
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 14:
                x_2 = (int)(item2->x + (item2->x > centerX ? 100 : -100));
                y6 = (int)(item2->y + (item2->y > centerY ? 50 : -50));
                break;
            case 1:
            case 2:
                x_2 = (int)item2->x;
                y6 = (int)(item2->y + (item2->y > centerY ? 100 : -100));
                break;
            default:
                x_2 = (int)item2->x;
                y6 = (int)item2->y;
                break;
            }
            x_2 = FUN_00647b70(minX, MinInt(maxX, x_2));
            y6 = FUN_00647b70(minY, MinInt(maxY, y6));
            reinterpret_cast<::Tile *>((item2->tile))->Set(0xfa1, x_2);
            reinterpret_cast<::Tile *>((item2->tile))->Set(0xfa2, y6);
            switch (item2->limb)
            {
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 14:
                if (x_2 < centerX)
                    reinterpret_cast<::Tile *>((item2->tile))->Set(0xfb7, 4);
                else
                    reinterpret_cast<::Tile *>((item2->tile))->Set(0xfb7, 1);
                break;
            }
        }
        entry = ((::ListX< ::Limb392 *> *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070()));
    }
    bool stateA = true;
    int j = 0;
    Vec392 v;
    Vec392 secondVal;
    Vec392 point;
    Vec392 size_2;
    size_2.x = 150.0f;
    size_2.y = 100.0f;
    while (stateA)
    {
        stateA = false;
        j++;
        entry = &reinterpret_cast<Target392*>(((::TargetX *)(reinterpret_cast<::SimpleListNodeView*>(node_2)->m_item)))->limbs;
        while (entry && !entry->IsEmpty())
        {
            Limb392* a = ((::Limb392 *)(reinterpret_cast<::SimpleListNodeView*>(entry)->m_item));
            ListX<Limb392*>* next = ((::ListX< ::Limb392 *> *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070()));
            while (next && !next->IsEmpty())
            {
                Limb392* b = ((::Limb392 *)(reinterpret_cast<::SimpleListNodeView*>(next)->m_item));
                v.x = reinterpret_cast<::TileListBoxCalls *>((a->tile))->GetFloat(0xfa1);
                v.y = reinterpret_cast<::TileListBoxCalls *>((a->tile))->GetFloat(0xfa2);
                secondVal.x = reinterpret_cast<::TileListBoxCalls *>((b->tile))->GetFloat(0xfa1);
                secondVal.y = reinterpret_cast<::TileListBoxCalls *>((b->tile))->GetFloat(0xfa2);
                if (FUN_00408840(v.x - secondVal.x) < size_2.x && FUN_00408840(v.y - secondVal.y) < size_2.y)
                {
                    if (reinterpret_cast<::FUN_00452df0_class *>((void *)&(v))->FUN_00452df0((float *)&(secondVal)))
                        secondVal.x += 1.0;
                    point.x = FUN_00408840(v.x - secondVal.x) / 2.0 + (v.x > secondVal.x ? secondVal.x : v.x);
                    point.y = FUN_00408840(v.y - secondVal.y) / 2.0 + (v.y > secondVal.y ? secondVal.y : v.y);
                    v = (v - point).DivideBy(reinterpret_cast<::FUN_004e7560_shell *>((void *)(void *)&(const ::Vec392 &)((v - point)))->NormalizeXY());
                    v = point + reinterpret_cast<const ::Vec392 &>(ResultSlot(reinterpret_cast<::NiPoint2 *>((void *)&(const ::Vec392 &)(v))->operator*((float)(reinterpret_cast<::FUN_00589850_Class *>((void *)&(size_2))->FUN_00589850() / 2.0))));
                    secondVal = (secondVal - point).DivideBy(reinterpret_cast<::FUN_004e7560_shell *>((void *)(void *)&(const ::Vec392 &)((secondVal - point)))->NormalizeXY());
                    secondVal = point + reinterpret_cast<const ::Vec392 &>(ResultSlot(reinterpret_cast<::NiPoint2 *>((void *)&(const ::Vec392 &)(secondVal))->operator*((float)(reinterpret_cast<::FUN_00589850_Class *>((void *)&(size_2))->FUN_00589850() / 2.0))));
                    v.x = FUN_00404010(minX, FUN_0040ebd0(maxX, v.x));
                    v.y = FUN_00404010(minY, FUN_0040ebd0(maxY, v.y));
                    secondVal.x = FUN_00404010(minX, FUN_0040ebd0(maxX, secondVal.x));
                    secondVal.y = FUN_00404010(minY, FUN_0040ebd0(maxY, secondVal.y));
                    reinterpret_cast<::FUN_00a012d0_t *>((a->tile))->FUN_00a012d0(0xfa1, v.x, true);
                    reinterpret_cast<::FUN_00a012d0_t *>((a->tile))->FUN_00a012d0(0xfa2, v.y, true);
                    reinterpret_cast<::FUN_00a012d0_t *>((b->tile))->FUN_00a012d0(0xfa1, secondVal.x, true);
                    reinterpret_cast<::FUN_00a012d0_t *>((b->tile))->FUN_00a012d0(0xfa2, secondVal.y, true);
                    stateA = true;
                }
                next = ((::ListX< ::Limb392 *> *)(reinterpret_cast<::Callees *>((next))->FUN_00726070()));
            }
            entry = ((::ListX< ::Limb392 *> *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070()));
        }
        if (j > 30)
            stateA = false;
    }
}
// Returns the value from the actor view's component for a1, or 0x1a if unavailable, or -1 when a1 is 0xe.
// @fnv 0x007f3bf0
int FUN_007f3bf0_cls::FUN_007f3bf0(int a1)
{
    if (::DAT_011f21cc == 0 || !((ActorView7*)::DAT_011f21cc)->IsReady())
    {
        return 0x1a;
    }
    Comp* pComp = ((::Comp *)(reinterpret_cast<::Actor *>((((ActorView7*)::DAT_011f21cc)))->GetActorBase()))->GetComp();
    if (pComp != 0)
    {
        Comp2* r = ((::Comp2 *)(reinterpret_cast<::FUN_005e50f0_Obj *>((pComp))->GetValueByIndex(a1)));
        if (r != 0)
            return ((char)(reinterpret_cast<::FUN_005e5190_Class *>((r))->GetByte63()));
    }
    if (a1 == 0xe)
        return -1;
    return 0x1a;
}



struct __declspec(align(16)) B006815c0
{
    char pad[16];
    B006815c0();
};



// @fnv 0x007f68a0
void Class_007f68a0::FUN_007f68a0(const NiPoint3& pt)
{
    B006815c0 vec;
    reinterpret_cast<::fnv_004a3f90::T_ *>(this)->ForwardToSubObject(((::B006815c0 *)&(::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&vec)), (const ::fnv_004a3e00::NiPoint3 &)(pt)))));
}

struct Point007f6af0
{
    float x, y, z;
    Point007f6af0();
    Point007f6af0 operator*(float) const;
};
struct Quest007f6af0
{
};
struct Light007f6af0
{
};
struct Anim007f6af0
{
};
struct Node007f6af0
{
};
extern float DAT_011a0b74;
struct Filter007f6af0
{
    int field_00;
    Filter007f6af0()
    {}
    Filter007f6af0(int);
    unsigned FUN_004a3a20();
};
struct Hit007f6af0
{
    int field_00[20];
    void* field_50;
    int field_54[3];
};
struct Hits007f6af0
{
};
struct Response007f6af0
{
};
struct __declspec(align(16)) Collector007f6af0
{
    int field_00[198];
    Collector007f6af0();
    virtual ~Collector007f6af0();
};
struct __declspec(align(16)) Ray007f6af0
{
    char field_00[176];
    Ray007f6af0();
    void FUN_004a3f70(int);
};
struct World007f6af0
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50(Ray007f6af0*);
};
struct PlayerFilter007f6af0
{
    int field_00;
    unsigned FUN_004a3a20();
};
struct Player007f6af0
{
    void FUN_00931ed0(PlayerFilter007f6af0*);
};
struct Owner007f6af0
{
    char field_00[0x10e];
    unsigned char field_10e;
};
// @fnv 0x007f6af0
bool FUN_007f6af0(Owner007f6af0* self)
{
    if (self->field_10e)
        return false;
    float distance = DAT_011a0b74;
    Point007f6af0 origin;
    Point007f6af0 direction;
    reinterpret_cast<::CameraWindowRay *>((((::Anim007f6af0 *)(reinterpret_cast<::BSFaceGenNiNode *>((((::Node007f6af0 *)(::FUN_0045c670()))))->GetAnimationData()))))->MapScreenToRay((int)reinterpret_cast<::BGSImpactData *>((((Light007f6af0*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_009a9350(),
                                                   (int)reinterpret_cast<::FUN_00792760_shell *>((((Quest007f6af0*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00792760(), (*(::NiPoint3 *)(&origin)),
                                                   (*(::NiPoint3 *)(&direction)), (const ::NiRenderTargetGroup *)(0));
    Ray007f6af0 ray;
    unsigned int mask = 0x140;
    ::ShadowLightData::SetTargetMaskForSelection(0x27, mask);
    PlayerFilter007f6af0 playerFilter;
    (*reinterpret_cast<::Player007f6af0 * *>(&::_g_thePlayer))->FUN_00931ed0(&playerFilter);
    Filter007f6af0 filter(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(filter))->FUN_004a39f0(0x27);
    reinterpret_cast<::FUN_0059ce80_shell *>(&(filter))->FUN_0059ce80(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(playerFilter))->FUN_004a3a20());
    ray.FUN_004a3f70(filter.field_00);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(ray))->FUN_004a3da0(&origin);
    reinterpret_cast<::Class_007f68a0 *>(&(ray))->FUN_007f68a0((const ::NiPoint3 &)((const ::Point007f6af0 &)(direction * distance)));
    Collector007f6af0 collector;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(ray))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::Collector007f6af0 *)(&collector));
    World007f6af0* world = ((::World007f6af0 *)(reinterpret_cast<::FUN_004543c0_cls *>((((void *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::Player007f6af0 * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
    world->v50(&ray);
    int unused = 0;
    for (int i = 0; i < ((std::intptr_t)(reinterpret_cast<::Callees *>((((::Hits007f6af0 *)(::FUN_00460140((std::intptr_t)(((::Response007f6af0 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->FUN_00726070())); ++i)
    {
        Hit007f6af0 hit;
        reinterpret_cast<::S50 *>(&(hit))->FUN_00696c30((::S50 *)(::Hit007f6af0 *)(((::Hit007f6af0 *)(reinterpret_cast<::FUN_004a46b0_class *>((((::Hits007f6af0 *)(::FUN_00460140((std::intptr_t)(((::Response007f6af0 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(ray))->FUN_008cdd90()))))))))->GetEntryAt(i)))));
        void* object = ((void *)(::FUN_004b5820((::FormLike *)(hit.field_50))));
        TESObjectREFR* ref = ::FUN_0056f930((::NiAVObject *)(object));
        if (object)
        {
            BSSimpleList<ItemListContainer*>* entry = ((StandIn*)self)->FindListEntryForTarget(ref);
            if (entry && *(ItemListContainer**)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(entry)->m_item)) == (*reinterpret_cast<::ItemListContainer * *>(&::DAT_011f21cc)))
            {
                return false;
            }
            else if (entry)
            {
                FUN_007f3bd0(0);
                reinterpret_cast<::fnv_007f07a0::Owner7 *>((self))->UpdateLimbHighlight();
                (*reinterpret_cast<::ItemListContainer * *>(&::DAT_011f21cc)) = *(ItemListContainer**)*((::ItemListContainer **)(&reinterpret_cast<::SimpleListNodeView*>(entry)->m_item));
                return true;
            }
            ref = 0;
        }
    }
    return false;
}
#include "generated/data/fallout/interface/menus/vatsmenu.inc"
#include "generated/data/fallout/interface/menus/vatsmenu_o2_variant_od_oy_noo2_variant.inc"
