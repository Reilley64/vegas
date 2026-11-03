
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/TMapStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0044f000.h"
#include "fnv/symbols_0045d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00877000.h"
#include "fnv/symbols_00c33000.h"
#include "fnv/symbols_00c3b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "SettingT.h"

extern void* DAT_0101772c;
struct FUN_0044f600_class
{
    void* vtbl;
    void FUN_0044f700();
    void* InitializeVtbl();
};
struct FUN_00877a10_Class
{
    void FUN_00877a10();
};
struct FUN_0044f620_class
{
    void* FUN_0044f620(unsigned int flags);
};
// Calls FUN_00877a10 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0044f620
void* FUN_0044f620_class::FUN_0044f620(unsigned int flags)
{
    ((FUN_00877a10_Class*)this)->FUN_00877a10();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_0044f6d0 {
struct FUN_00877a10_Class
{
    void FUN_0044f650();
    void* FUN_0044f6d0(unsigned int flags);
};
// Calls FUN_0044f650, then deallocates this object if bit 0 of flags is set, and returns this.
// @fnv 0x0044f6d0
void* FUN_00877a10_Class::FUN_0044f6d0(unsigned int flags)
{
    FUN_0044f650();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0044f6d0

// Setting constructors for 4-byte values and floats share their code with other classes' two-field constructors
// (0x00404920, 0x0040e130), so only the bool form has an address of its own.
Setting::Setting(const char* key, int value)
{
    uValue.i = value;
    pKey = key;
}

Setting::Setting(const char* key, char* value)
{
    uValue.str = value;
    pKey = key;
}

Setting::Setting(const char* key, const char* value)
{
    uValue.str = value;
    pKey = key;
}

Setting::Setting(const char* key, float value)
{
    uValue.f = value;
    pKey = key;
}

// @fnv 0x0045cfb0
Setting::Setting(const char* key, bool value)
{
    uValue.b = value;
    pKey = key;
}

// @fnv 0x00404950
Setting::~Setting()
{
    if (pKey && *pKey == 'S')
        ::FUN_00401030(const_cast<char*>(pKey));
}

template <> GameSettingCollection* SettingT<GameSettingCollection>::GetCollection()
{
    return ::GetGameSettingCollection();
}

template <> SettingCollection_011f35a4* SettingT<SettingCollection_011f35a4>::GetCollection()
{
    return static_cast<SettingCollection_011f35a4*>(::FUN_0045d180());
}

template <> SettingCollection_01204368* SettingT<SettingCollection_01204368>::GetCollection()
{
    return static_cast<SettingCollection_01204368*>(::FUN_00877950());
}

void FUN_00632e30();
extern void* DAT_011cc694;

// @fnv 0x00632e20
void* FUN_00632e20()
{
    FUN_00632e30();
    return DAT_011cc694;
}

template <> SettingCollection_011cc694* SettingT<SettingCollection_011cc694>::GetCollection()
{
    return static_cast<SettingCollection_011cc694*>(FUN_00632e20());
}

// @fnv 0x0040c150
template <> SettingT<GameSettingCollection>::SettingT(const char* key, const char* value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// Same code as the const char* form (0x0040c150).
template <> SettingT<GameSettingCollection>::SettingT(const char* key, int value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

template <> SettingT<GameSettingCollection>::SettingT(const char* key, float value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x00404a00
template <> SettingT<GameSettingCollection>::~SettingT()
{
    GetCollection()->Remove(this);
}

// @fnv 0x0045cfe0
template <> SettingT<INISettingCollection>::SettingT(const char* key, const char* value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// Same code as the const char* form (0x0045cfe0).
template <> SettingT<INISettingCollection>::SettingT(const char* key, int value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x0044f440
template <> SettingT<INISettingCollection>::SettingT(const char* key, float value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x0045cf30
template <> SettingT<INISettingCollection>::SettingT(const char* key, bool value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x0044f4f0
template <> SettingT<INISettingCollection>::~SettingT()
{
    GetCollection()->Remove(this);
}

// @fnv 0x004a4a40
template <> SettingT<SettingCollection_011f35a4>::SettingT(const char* key, const char* value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// Same code as the const char* form (0x004a4a40).
template <> SettingT<SettingCollection_011f35a4>::SettingT(const char* key, int value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x0045d060
template <> SettingT<SettingCollection_011f35a4>::SettingT(const char* key, float value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x004de2f0
template <> SettingT<SettingCollection_011f35a4>::SettingT(const char* key, bool value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x0045d110
template <> SettingT<SettingCollection_011f35a4>::~SettingT()
{
    GetCollection()->Remove(this);
}

// @fnv 0x00719c00
template <> SettingT<INIPrefSettingCollection>::SettingT(const char* key, int value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x004de370
template <> SettingT<INIPrefSettingCollection>::SettingT(const char* key, float value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x00709f00
template <> SettingT<INIPrefSettingCollection>::SettingT(const char* key, bool value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x004de420
template <> SettingT<INIPrefSettingCollection>::~SettingT()
{
    GetCollection()->Remove(this);
}

// @fnv 0x00633000
template <> SettingT<SettingCollection_011cc694>::SettingT(const char* key, const char* value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x00632ee0
template <> SettingT<SettingCollection_011cc694>::SettingT(const char* key, float value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

// @fnv 0x00632f90
template <> SettingT<SettingCollection_011cc694>::~SettingT()
{
    GetCollection()->Remove(this);
}

template <> SettingT<SettingCollection_01204368>::SettingT(const char* key, const char* value) : Setting(key, value)
{
    GetCollection()->Add(this);
}

template <> SettingT<SettingCollection_01204368>::~SettingT()
{
    GetCollection()->Remove(this);
}

extern int _data_011c16bc;
extern char const str_010121d0[];

struct AutoMemHelper
{
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
    void* padding;
};

struct Setting;


struct SettingCollectionMap : SettingCollection<Setting>
{
    ::fnv_00853130::NiTMapBase m_kSettingMap;

    void AddSetting(Setting*);
};

// @fnv 0x00404de0
void SettingCollectionMap::AddSetting(Setting* apSetting)
{
    AutoMemHelper tempMemContext(9, true, ::str_01012220, 539);

    if (apSetting && reinterpret_cast<::Twin_0044ddc0*>(apSetting)->GetName())
    {
        ::fnv_00853130::CombatThreatRecord* existing;
        const char* name = reinterpret_cast<::Twin_0044ddc0*>(apSetting)->GetName();
        if (m_kSettingMap.FUN_00853130(reinterpret_cast<std::uintptr_t>(name), existing))
        {
            ::fnv_00c335a0::FUN_00c335a0(str_010121d0, reinterpret_cast<::Twin_0044ddc0*>(apSetting)->GetName());
        }
        else
        {
            reinterpret_cast<::TMapStandIn*>(&m_kSettingMap)
                ->InsertOrUpdate(reinterpret_cast<std::uintptr_t>(reinterpret_cast<::Twin_0044ddc0*>(apSetting)->GetName()),
                                 reinterpret_cast<TESGlobal*>(apSetting));
        }
    }
}

namespace fnv_00c335a0 {
#include <stdarg.h>


// @fnv 0x00c335a0
int FUN_00c335a0(const char* pcFormat, ...)
{
    va_list args;
    va_start(args, pcFormat);
    int iResult = ::FUN_00c3be40();
    va_end(args);
    return iResult;
}
}  // namespace fnv_00c335a0

struct SettingName
{
};
struct SettingNode
{
};
struct SettingStore : SettingNode
{
    bool FUN_008256d0();
    void FUN_005ae3d0(SettingName**);
};
struct Registry : SettingCollection<Setting>
{
    BSSimpleList<SettingName*> m_kSettingList;

    void AddSettingKey(SettingName*);
};
// @fnv 0x0044f770
void Registry::AddSettingKey(SettingName* key)
{
    AutoMemHelper scope(9, true, ::g_ac5E0200SourceFile, 765);
    if (!reinterpret_cast<SettingStore*>(&m_kSettingList)->FUN_008256d0())
    {
        BSSimpleList<SettingName*>* position = &m_kSettingList;
        while (position)
        {
            SettingName* entry = position->m_item;
            if (FUN_00404dc0(reinterpret_cast<::Twin_0044ddc0*>(entry)->GetName(), reinterpret_cast<::Twin_0044ddc0*>(key)->GetName()) == 0)
            {
                ::fnv_00c335a0::FUN_00c335a0("DEFAULT: Setting key '%s' already used in list.\nSetting keys must be unique.\n",
                                             reinterpret_cast<::Twin_0044ddc0*>(key)->GetName());
                return;
            }
            position = static_cast<BSSimpleList<SettingName*>*>(reinterpret_cast<::Callees*>(position)->FUN_00726070());
        }
    }
    reinterpret_cast<SettingStore*>(&m_kSettingList)->FUN_005ae3d0(&key);
}


struct DataListEntry
{
};
struct EntryEnumerator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual bool v14(Setting* setting);
    bool FUN_00404d30();
    DataListEntry* FUN_0044fac0(DataListEntry* current);
    bool FUN_0044f9c0();
};
// @fnv 0x0044f9c0
bool EntryEnumerator::FUN_0044f9c0()
{
    AutoMemHelper guard(9, true, ::g_ac5E0200SourceFile, 0x357);
    bool succeeded = FUN_00404d30();
    if (succeeded)
    {
        DataListEntry* current = ((::DataListEntry *)(::FUN_0044faa0((char *)this)));
        while (current != 0)
        {
            Setting* item = reinterpret_cast<BSSimpleList<Setting*>*>(current)->m_item;
            if (item != 0)
            {
                succeeded = succeeded & v14(item);
            }
            current = FUN_0044fac0(current);
        }
    }
    return succeeded;
}

class FUN_0044f650 : public SettingCollection<Setting>
{
  public:
    BSSimpleList<Setting*> settings;
    virtual ~FUN_0044f650();
};
// Removes all entries from the settings list during destruction of the SettingCollection subclass.
// @fnv 0x0044f650
FUN_0044f650::~FUN_0044f650()
{
    reinterpret_cast<::FileMatchList *>(&(settings))->RemoveAll();
}

class FUN_00404d00_class
{
  public:
    FUN_00404d00_class();
    virtual ~FUN_00404d00_class();
    char unk004[0x108];
};

class StrList
{
  public:
    StrList();
    void* m_pkHead;
    void* m_pkTail;
};

class FUN_0044f700 : public FUN_00404d00_class
{
  public:
    StrList m_kList;

    FUN_0044f700();
    virtual ~FUN_0044f700();
};
// @fnv 0x0044f600
void* FUN_0044f600_class::InitializeVtbl()
{
    new ((void *)this) ::FUN_0044f700();
    vtbl = &DAT_0101772c;
    return this;
}

// Default constructor for a container that holds a StrList member.
// @fnv 0x0044f700
FUN_0044f700::FUN_0044f700()
{}

#include "generated/data/unmapped/setting.inc"
