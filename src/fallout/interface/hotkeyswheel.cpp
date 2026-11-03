// fallout/interface/hotkeyswheel.cpp: Wheel, HotkeyWheelUpdate, HWShell (9 functions)

#include <cstdint>
#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/BGSDefaultObjectManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/FUN_004bddd0_shell.h"
#include "fnv/decl/FUN_004be2d0_shell.h"
#include "fnv/decl/FUN_0088c650_shell.h"
#include "fnv/decl/FUN_008a7570_shell.h"
#include "fnv/decl/FUN_00950030_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a23e10_Class.h"
#include "fnv/decl/FUN_00a24180_shell.h"
#include "fnv/decl/InputManager245.h"
#include "fnv/decl/InventoryChangesIter.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004bf660__InventoryOwner.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/s88c790__Actor.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00479000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "hotkeyswheel_decls.h"

// @fnv 0x00701740
bool HotkeyWheelDisplay::GetVisible()
{
    return reinterpret_cast<::FUN_00a01230_shell *>((reinterpret_cast<Tile*>(m_pWheelTile)))->IsTraitNonZero(0xFA3);
}

// @fnv 0x00701610
void HotkeyWheelDisplay::Initialize(Tile* parent)
{
    BSStringT<char> itemName;
    if (!parent)
    {
        ::FUN_005b5e40();
        return;
    }

    m_pWheelTile = parent;
    for (int i = 0; i < 8; ++i)
    {
        ::FUN_00406f60((::FUN_00406f90_this *)&(itemName), DAT_0106ea94, i);
        m_ppHotkeySlotTiles[i] = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((reinterpret_cast<Tile*>(m_pWheelTile)))->FUN_00a03da0((char *)(((const char *)(::FUN_00559450((int *)&(itemName))))));
    }

    m_iTileValueIdAtOffset2C = ::FUN_00a00940(DAT_0106ea84, -1);
    m_iTileValueIdAtOffset30 = ::FUN_00a00940(DAT_0106ea74, -1);
    m_bHasHotkeySelection = false;
    reinterpret_cast<Tile*>(m_pWheelTile)->Set(m_iTileValueIdAtOffset2C, 0xffffffff);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((reinterpret_cast<Tile*>(m_pWheelTile)))->FUN_00a01350(m_iTileValueIdAtOffset30, (char *)(::DAT_01011584), true);
}

// @fnv 0x00a24660
int HotkeyWheelDisplay::SetHotkeyItem(int key, int state)
{
    if (key < 28)
    {
        int result = 0;
        if (DAT_011f35c8)
            result = reinterpret_cast<::InputManager245 *>(this)->FUN_00a24560(3, controller[key], state);
        else
        {
            for (int device = 0; device < 2; ++device)
            {
                if (keyboard[device][key] != 255)
                    result += reinterpret_cast<::InputManager245 *>(this)->FUN_00a24560(device, keyboard[device][key], state);
            }
        }
        if (key == 14 && result > 0)
        {
            bool flagWasSet;
            if (flags & HotkeySuppressedMask())
            {
                flags ^= HotkeySuppressedMask();
                flagWasSet = true;
            }
            else
                flagWasSet = false;
            if (flagWasSet)
            {
                result = 0;
                if (state == 0 || state == 1)
                    flags |= HotkeySuppressedMask();
            }
        }
        return result;
    }
    if (!DAT_011f35c8)
    {
        switch (key)
        {
        case 28:
            if (reinterpret_cast<::FUN_00a24180_shell *>(this)->FUN_00a24180(1, 1) || reinterpret_cast<::FUN_00a23e10_Class *>(this)->FUN_00a23e10(6, 1))
                return 1;
            break;
        case 29:
            return reinterpret_cast<::FUN_00a24180_shell *>(this)->FUN_00a24180(41, 1);
            break;
        case 30:
            return reinterpret_cast<::FUN_00a24180_shell *>(this)->FUN_00a24180(183, 1);
        }
    }
    else if (key == 28)
    {
        if (reinterpret_cast<::FUN_00a23e10_Class *>(this)->FUN_00a23e10(6, 1))
            return 1;
    }
    return 0;
}


struct S_00701e00_Owner
{
};

struct S_00701e00_Item
{
};

struct S_00701e00_Class
{
    S_00701e00_Owner* unk00;
    S_00701e00_Item* unk04[7];
    void* unk20;
    unsigned char unk24;
    int unk28;
    int unk2c;
    int unk30;

    void FUN_00701e00(int index);
};

// Updates the owner with unk2c and a per-index item pointer (or a default), then stores index in unk28 and sets unk24 to 1 when index is non-negative.
// @fnv 0x00701e00
void S_00701e00_Class::FUN_00701e00(int index)
{
    reinterpret_cast<::Tile *>((unk00))->Set(unk2c, index);

    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((unk00))->FUN_00a01350(unk30, (char *)(void *)((index >= 0 && index != 1) ? ((void *)(reinterpret_cast<::FUN_00a011f0_shell *>((unk04[index]))->FUN_00a011f0(0xfc4))) : (void*)&(*reinterpret_cast<char *>((void *)&::DAT_01011584))),
                        1);

    if (index >= 0)
    {
        unk28 = index;
        unk24 = 1;
    }
}


// Returns 1 if HotkeyWheelProbeA succeeds and any of HotkeyWheelProbeB(2/1/4/3, 0) is not -1, otherwise 0.
// @fnv 0x00702140
unsigned char FUN_00702140()
{
    int result;
    if (::FUN_00709d40() && (::fnv_00717a40::FUN_00717a40(2, 0) != -1 || ::fnv_00717a40::FUN_00717a40(1, 0) != -1 ||
                                ::fnv_00717a40::FUN_00717a40(4, 0) != -1 || ::fnv_00717a40::FUN_00717a40(3, 0) != -1))
        result = 1;
    else
        result = 0;
    return result;
}

struct Form
{
    int FUN_00401170();
};
struct Data
{
};
struct Entry
{
    Entry* FUN_004459e0(bool);
};
struct Inventory
{
};
struct Process
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
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580(int, int, int);
};
struct ActorValues
{
    virtual int v00();
    virtual int v04();
    virtual int v08(int);
    virtual int v0c();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1c(int);
};
struct Player
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
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
};
struct Setting
{
};

struct Wheel
{
    void FUN_00701e80();
};
class HotkeyStringCalls
{
  public:
    BSStringT<char>& FUN_00438390(const char*);
    BSStringT<char>& FUN_00404820(const char*);
};

class TESForm
{
};
class TESBoundObject : public TESForm
{
};

class InventoryItem
{
  public:
    void* FUN_004459e0(int);
};

class TESObjectREFR;

class TESObjectREFR;
class InventoryChanges
{
  public:
public:
    static ::InventoryChanges *CreateForReference(::TESObjectREFR *);
};
// @fnv 0x00701e80
void Wheel::FUN_00701e80()
{
    Inventory* inv3 = ((::Inventory *)(::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))));
    Entry* entry5 = inv3 ? ((::Entry *)(reinterpret_cast<::InventoryChangesIter *>((inv3))->FindEntryWithExtraListType(*(int*)((char*)this + 0x28)))) : 0;
    void* extra = entry5 && ((::Data *)(::FUN_00559450((int *)(entry5)))) ? *((void **)(&reinterpret_cast<::SimpleListNodeView*>(((::Data *)(::FUN_00559450((int *)(entry5)))))->m_item)) : 0;
    bool ammo4 =
        (entry5 && ((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry5))->GetName()))->FUN_00401170() == 0x28 && ::FUN_004c0bf0((::TESObjectWEAP *)(((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry5))->GetName()))))) ? 1 : 0;
    if (!*((unsigned char*)this + 0x24) || !inv3 || !entry5)
        return;
    if (reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_008a7570() != -1 && ((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry5))->GetName()))->FUN_00401170() == 0x18)
        return;
    if (reinterpret_cast<::FUN_008a7570_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_008a7570() != -1 && ((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry5))->GetName()))->FUN_00401170() == 0x28)
        return;
    if (((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry5))->GetName())) == ((::Form *)(::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0)))) && ((ActorValues*)((char*)(*reinterpret_cast<::Player * *>(&::_g_thePlayer)) + 0xa4))->v08(0x10) ==
                                                         ((ActorValues*)((char*)(*reinterpret_cast<::Player * *>(&::_g_thePlayer)) + 0xa4))->v1c(0x10))
    {
        ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::Setting *>(&::g_011d2af0))))->IsDLCAvailable()))), 0, (int)(0), (int)(0), DAT_010162c0, false);
        return;
    }
    else
    {
        if (!reinterpret_cast<::FUN_004bddd0_shell *>((entry5))->FUN_004bddd0(false))
            reinterpret_cast<::FUN_0088c650_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_0088c650((::TESBoundObject *)(::Form *)(((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry5))->GetName()))), ammo4 ? ((int)(reinterpret_cast<::Callees *>((entry5))->FUN_00726070())) : 1, (::ExtraDataList *)(extra), 0, 0, 1);
        else
            reinterpret_cast<::s88c790::Actor *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_0088c790((int)(((::Form *)(reinterpret_cast<::Twin_0044ddc0 *>((entry5))->GetName()))), ammo4 ? ((int)(reinterpret_cast<::Callees *>((entry5))->FUN_00726070())) : 1, (intptr_t)(extra), 0, 0, 1);
    }
    reinterpret_cast<::FUN_00950030_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_00950030();
    ((::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetBaseTexture()))->v580(1, 0, 0);
    (*reinterpret_cast<::Player * *>(&::_g_thePlayer))->v3c4();
    Entry* cleanup4 = entry5;
    Entry* target = cleanup4;
    target ? target->FUN_004459e0(true) : 0;
}

namespace BGSEquipType {
enum EQUIP_TYPE
{
};
EQUIP_TYPE GetEquipType(TESForm*);
}


static const char str_InterfaceIcons[] = "Interface\\Icons\\";
static const char str_HotKeyIcon[] = "_HotKeyIcon";
static const char str_HotKeyAssigned[] = "_HotKeyAssigned";
static const char str_FormatCount[] = "%s (%d)";

struct HotkeyWheelUpdate : HotkeyWheelDisplay
{
    void FUN_007017b0();
};
// @fnv 0x00701760
void HotkeyWheelDisplay::SetVisible(bool visible)
{
    if (visible)
    {
        reinterpret_cast<::HotkeyWheelUpdate *>(this)->FUN_007017b0();
        reinterpret_cast<Tile*>(m_pWheelTile)->Set(0xFA3, 1);
    }
    else
        reinterpret_cast<Tile*>(m_pWheelTile)->Set(0xFA3, 0);
}

// Updates hotkey slot tiles with item icons, assigned state, and count labels from the player's inventory changes.
// @fnv 0x007017b0
void HotkeyWheelUpdate::FUN_007017b0()
{
    InventoryChanges* invChanges2 = ::InventoryChanges::CreateForReference((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)));
    BSStringT<char> str3;
    if (invChanges2)
    {
        InventoryItem** items7 = ((::InventoryItem **)(reinterpret_cast<::fnv_004bf660::InventoryOwner *>((invChanges2))->CollectEntriesByRank(0, 7)));
        for (int i = 0; i < 8; ++i)
        {
            if (i == 1)
                continue;
            InventoryItem* item3 = items7[i];
            if (item3)
            {
                reinterpret_cast<HotkeyStringCalls&>(str3).FUN_00438390(str_InterfaceIcons);
                reinterpret_cast<HotkeyStringCalls&>(str3).FUN_00404820(
                    ::fnv_00479540::GetMenuIconName(BGSEquipType::GetEquipType(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item3))->GetName())))));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_ppHotkeySlotTiles[i]))->FUN_00a01350(FUN_00a01860(str_HotKeyIcon), (char *)(((const char *)(::FUN_00559450((int *)&(str3))))), true);
                this->m_ppHotkeySlotTiles[i]->Set(FUN_00a01860(str_HotKeyAssigned), 1);
                if (((std::intptr_t)(reinterpret_cast<::Callees *>((item3))->FUN_00726070())) > 1)
                {
                    ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&str3), str_FormatCount, reinterpret_cast<::FUN_004be2d0_shell *>((item3))->GetTargetFullName(), ((std::intptr_t)(reinterpret_cast<::Callees *>((item3))->FUN_00726070())));
                }
                else
                {
                    reinterpret_cast<HotkeyStringCalls&>(str3).FUN_00438390(reinterpret_cast<::FUN_004be2d0_shell *>((item3))->GetTargetFullName());
                }
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_ppHotkeySlotTiles[i]))->FUN_00a01350(0xfc4, (char *)(((const char *)(::FUN_00559450((int *)&(str3))))), true);
            }
            else
            {
                this->m_ppHotkeySlotTiles[i]->Set(FUN_00a01860(str_HotKeyAssigned), 0);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((this->m_ppHotkeySlotTiles[i]))->FUN_00a01350(0xfc4, (char *)(""), true);
            }
        }
        for (int j_ = 0; j_ < 8; ++j_)
        {
            InventoryItem* t3 = items7[j_];
            InventoryItem* t2 = t3;
            t2 ? t2->FUN_004459e0(1) : 0;
        }
        delete items7;
    }
}

struct TileCall
{
};

struct TimeGlobal
{
};

struct HWShell : HotkeyWheelDisplay
{
    int FUN_00701bd0(int index);
};


extern "C" int DAT_0119f33c;
extern "C" unsigned int DAT_011d88f4;

// Determines the active hotkey wheel slot from probe states or a direct index, updates the stored selection and timestamp, and triggers a tile change when needed.
// @fnv 0x00701bd0
int HWShell::FUN_00701bd0(int index)
{
    int result5 = -1;
    if (index == 1)
        return -1;
    if (!FUN_004b71d0())
    {
        if (index >= 0)
            result5 = index;
        ((S_00701e00_Class*)this)->FUN_00701e00(result5);
    }
    else
    {
        if (index < 0)
        {
            int vAB = ::fnv_00717a40::FUN_00717a40(2, 0);
            int vB3 = ::fnv_00717a40::FUN_00717a40(1, 0);
            int vC7 = ::fnv_00717a40::FUN_00717a40(4, 0);
            int vD = ::fnv_00717a40::FUN_00717a40(3, 0);
            bool bA2 = vAB == 2 || vAB == 0;
            bool bB = vB3 == 2 || vB3 == 0;
            bool bC4 = vC7 == 2 || vC7 == 0;
            bool bD_ = vD == 2 || vD == 0;
            if (bA2)
            {
                if (bC4)
                    result5 = 5;
                else if (bD_)
                    result5 = 7;
                else
                    result5 = 6;
            }
            else if (bB)
            {
                if (bC4)
                    result5 = 0;
                else if (bD_)
                    result5 = 2;
            }
            else if (bC4)
                result5 = 3;
            else if (bD_)
                result5 = 4;
        }
        int cur = (int)reinterpret_cast<::TileListBoxCalls *>((((TileCall*)this->m_pWheelTile)))->GetFloat(this->m_iTileValueIdAtOffset2C);
        if (result5 != cur)
        {
            if (result5 != DAT_0119f33c)
            {
                DAT_0119f33c = result5;
                DAT_011d88f4 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
            }
            if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() - DAT_011d88f4 > DAT_0101b268 || result5 == -1 || cur == -1)
                ((S_00701e00_Class*)this)->FUN_00701e00(result5);
        }
    }
    return result5;
}

#include "generated/data/fallout/interface/hotkeyswheel.inc"
