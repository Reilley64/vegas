
// src/fallout/interface/menus/mapmenu_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0079af30: the skeleton of src/fallout/interface/menus/mapmenu.cpp
// with declarations corrected to what the original code does (mapmenu_decls.h: MapMenu += void FUN_0079af30(); void UpdateLocalMap(); void RefreshMap(); void UpdateQuestObjectiveList(); void RefreshNotesList(); void RefreshChallengeList(); void FUN_0079b460(bool a); void SetNote(BGSNote* note); void RefreshRadioList();; mapmenu_decls.h: void FUN_007a1a70(); void FUN_007a1c90(); void). Move the function to its real unit once
// that unit declares it this way.

#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DialogMenuAudioCalls.h"
#include "fnv/decl/F7E0Picker.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00569060_shell.h"
#include "fnv/decl/FUN_00588e40_shell.h"
#include "fnv/decl/FUN_0059e400_shell.h"
#include "fnv/decl/FUN_005e8d40_shell.h"
#include "fnv/decl/FUN_005e9300_Host.h"
#include "fnv/decl/FUN_0061f170_cls.h"
#include "fnv/decl/FUN_007312e0_shell.h"
#include "fnv/decl/FUN_007700d0_cls.h"
#include "fnv/decl/FUN_00798400_shell.h"
#include "fnv/decl/FUN_00798420_shell.h"
#include "fnv/decl/FUN_00798ad0_shell.h"
#include "fnv/decl/FUN_00799dc0_class.h"
#include "fnv/decl/FUN_0079c090_shell.h"
#include "fnv/decl/FUN_0079c380_shell.h"
#include "fnv/decl/FUN_0079c450_shell.h"
#include "fnv/decl/FUN_007a4c50_shell.h"
#include "fnv/decl/FUN_007a5a30_Host.h"
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
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/ListBoxEnable.h"
#include "fnv/decl/ListBoxStandIn_7a3580.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MapView.h"
#include "fnv/decl/MenuItem7A3.h"
#include "fnv/decl/MyHack.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/NotesMapMenu.h"
#include "fnv/decl/Obj_009529d0.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S_00a04150_Class.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SoundPlayback.h"
#include "fnv/decl/SoundWrapper.h"
#include "fnv/decl/StringHolder.h"
#include "fnv/decl/TESObjectCELL_Ext.h"
#include "fnv/decl/Target600.h"
#include "fnv/decl/TileFloatList.h"
#include "fnv/decl/TileOwnerW.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Unk00796f90.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00578870__FUN_00578870_Class.h"
#include "fnv/decl/fnv_007993d0__NoteMenu.h"
#include "fnv/decl/fnv_0079b460__FUN_0079b460_shell.h"
#include "fnv/decl/fnv_0079b8e0__FUN_0079b8e0_shell.h"
#include "fnv/decl/fnv_0079bea0__FUN_0079bea0_Shell.h"
#include "fnv/decl/fnv_0079cdb0__MMMenu.h"
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
#include "fnv/symbols_007a1000.h"
#include "fnv/symbols_007fa000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
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
#include "mapmenu_decls_decl_mapmenu.h"
// @fnv 0x007a1930
template <> void ListBox<TESQuest*>::ClearSelection(bool notify)
{
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950((unsigned int)(0), notify);
}

// @fnv 0x0079af30
void MapMenu::FUN_0079af30()
{
    int selected = -1;
    Tile* index = 0;
    reinterpret_cast<::ListBoxEnable *>(&(m_kQuestListBox))->FUN_007a2350(false);
    reinterpret_cast<::FUN_007a4c50_shell *>(&(m_kObjectiveListBox))->SetEnabledTrait(false);
    reinterpret_cast<::MenuItem7A3 *>(&(m_kNoteListBox))->FUN_007a30e0(false);
    reinterpret_cast<::FUN_007a5a30_Host *>(&(m_kNoteListBox))->FUN_007a5a30(false);
    reinterpret_cast<::TileOwnerW *>(&(m_kChallengeListBox))->FUN_007a59a0(false);
    reinterpret_cast<::FUN_007a5a30_Host *>(&(m_kChallengeListBox))->FUN_007a5a30(false);
    DAT_011da368->m_pTiles[11]->Set(0xfaf, 1);
    DAT_011da368->m_pTiles[12]->Set(0xfa3, 1);
    DAT_011da368->m_pTiles[18]->Set(0xfa3, 0);
    DAT_011da368->m_pTiles[21]->Set(0xfa3, 0);
    switch (DAT_011da368->m_iMapDisplayMode)
    {
    case 32:
        DAT_011da368->m_pMapTile = DAT_011da368->m_pTiles[2];
        if (!FUN_007a1750())
            reinterpret_cast<::MapView *>((DAT_011da368))->UpdateLocalMap();
        break;
    case 33:
        DAT_011da368->m_pMapTile = DAT_011da368->m_pTiles[4];
        reinterpret_cast<::fnv_0079cdb0::MMMenu *>((DAT_011da368))->RefreshMap();
        break;
    case 34:
        reinterpret_cast<::fnv_0079b8e0::FUN_0079b8e0_shell *>((DAT_011da368))->UpdateQuestObjectiveList();
        break;
    case 35:
        DAT_011da368->m_pTiles[18]->Set(0xfa3, 1);
        if (!DAT_011da36d)
        {
            reinterpret_cast<::FUN_007312e0_shell *>(&(DAT_011da368->m_kNoteListBox))->FUN_007312e0();
            reinterpret_cast<::NotesMapMenu *>((DAT_011da368))->RefreshNotesList();
            if (m_pSelectedNote && !DAT_011da36d)
            {
                Tile* noteTile = ((::Tile *)(reinterpret_cast<::Owner *>(&(m_kNoteListBox))->FindItemData((int *)&(m_pSelectedNote))));
                reinterpret_cast<::fnv_007993d0::NoteMenu *>(this)->SetNote((::fnv_007993d0::NoteInput *)(m_pSelectedNote));
                if (noteTile)
                    noteTile->Set(DAT_011da348, 1);
            }
            reinterpret_cast<::ListBoxStandIn_7a3580 *>(&(DAT_011da368->m_kNoteListBox))->UpdateScrollSelection(true);
        }
        reinterpret_cast<::Target600 *>((DAT_011da368))->RefreshChallengeList();
        reinterpret_cast<::fnv_0079b460::FUN_0079b460_shell *>(this)->FUN_0079b460(false);
        break;
    case 36:
        DAT_011da368->m_pTiles[12]->Set(0xfa3, 0);
        selected =
            (int)(m_kMapMarkerListBox.GetSelectedTile() ? reinterpret_cast<::TileListBoxCalls *>((m_kMapMarkerListBox.GetSelectedTile()))->GetFloat(0xfac)
                                                        : -1.0f);
        reinterpret_cast<::fnv_0079bea0::FUN_0079bea0_Shell *>((DAT_011da368))->RefreshRadioList();
        index = m_kMapMarkerListBox.GetTileAt(selected, false);
        if (index)
            reinterpret_cast<::FocusManager *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00715860((::FocusTile *)(index), 0xfc3, 1);
        m_kMapMarkerListBox.ScrollToHighlight();
        break;
    }
}
