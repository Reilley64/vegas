
// src/fallout_shared/bgsequiptype_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00479570: the skeleton of src/fallout_shared/bgsequiptype.cpp
// that unit declares it this way.

#include "fnv/decl/TESFullName.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_01186000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
#include "bgsequiptype_decls_decl_bgsequiptype.h"

struct IconString
{
    char* data;
    unsigned short length, capacity;
};
class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
class TESTexture : public BaseFormComponent
{
  public:
    IconString textureName;
};
class TESIcon : public TESTexture
{
};
class BGSMenuIcon : public TESForm, public TESIcon
{
  public:
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
    virtual void SetFormID(unsigned int id, int flag);
    virtual void v12c();
    virtual void v130();
    virtual void SetEditorID(const char* name);
    BGSMenuIcon();
};
class TESDataHandler
{
  public:
    bool AddFormToDataHandler(TESForm* form);
};
int __cdecl FUN_00406d50(char*, unsigned int, const char*);
// @fnv 0x00479570
void FUN_00479570()
{
    static unsigned int prefixLength = FUN_0044a670("MenuIconEquipType");
    for (int i = 0; i < 14; ++i)
    {
        unsigned int formIDB = i + 0x258;
        BGSMenuIcon* entry = dynamic_cast<BGSMenuIcon*>(::FUN_004839c0(formIDB));
        if (!entry)
        {
            entry = new BGSMenuIcon;
            entry->SetFormID(formIDB, 1);
            char buffer[260];
            ::TaskQueueInterface::CopyStringToBuffer(buffer, 260, "MenuIconEquipType");
            FUN_00406d50(buffer, 260, (*reinterpret_cast<const char * (*)[14]>((void *)&::DAT_011869bc))[i]);
            entry->SetEditorID(buffer);
            ::TaskQueueInterface::CopyStringToBuffer(buffer, 260, "TypeIcons\\hot_keys_icon_");
            FUN_00406d50(buffer, 260, (*reinterpret_cast<const char * (*)[14]>((void *)&::DAT_011869bc))[i]);
            FUN_00406d50(buffer, 260, ".dds");
            reinterpret_cast<::TESFullName *>((entry))->SetFullName(buffer);
            (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->AddFormToDataHandler(entry);
        }
        DAT_011c4b54[i] = entry;
    }
}
