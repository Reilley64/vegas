
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
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00c33000.h"
#include "fnv/symbols_00c3b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "Setting.h"

extern void __cdecl FUN_0044f700();
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

struct FUN_00404920
{
    FUN_00404920(int, int);
    ~FUN_00404920();
};
struct GameSettingCollection
{
    virtual void v0();
    virtual void v1(void*);
};
struct FUN_0040e0b0
{
    virtual void v0();
    virtual void v1(void*);
    static const void* vftable;
};
struct FUN_0040c150 : FUN_00404920
{
    FUN_0040c150(int a, int b);
};
// @fnv 0x0040c150
FUN_0040c150::FUN_0040c150(int aiArg1, int aiArg2) : FUN_00404920(aiArg1, aiArg2)
{
    *(int*)this = (int)&FUN_0040e0b0::vftable;
    ::GetGameSettingCollection()->v1(this);
}

struct FUN_0040e130
{
    FUN_0040e130(int, float);
    ~FUN_0040e130();
    virtual void v0();
    virtual void v1(void*);
};
struct FUN_0044f440 : FUN_0040e130
{
    FUN_0044f440(int a, float b);
    virtual void v0();
    virtual void v1(void*);
};
struct FUN_0044f560
{
    static void* __cdecl GetCollection();
    virtual void v0();
    virtual void v1(void*);
};
// @fnv 0x0044f440
FUN_0044f440::FUN_0044f440(int aiValue, float afValue) : FUN_0040e130(aiValue, afValue)
{
    ((FUN_0044f560*)FUN_0044f560::GetCollection())->v1(this);
}

extern int _data_011c16bc;
extern char const str_010121d0[];

struct AutoMemHelper
{
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
    void* padding;
};

struct ArrSI
{
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct TESGlobalMap
{
};

struct Setting;


struct SettingCollectionMap
{
    void* padding[67];

    void AddSetting(Setting*);
};

// @fnv 0x00404de0
void SettingCollectionMap::AddSetting(Setting* apSetting)
{
    AutoMemHelper tempMemContext(9, true, ::str_01012220, 539);

    if (apSetting && ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(apSetting)))->GetName())))
    {
        unsigned int key;
        if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((reinterpret_cast<DummyPointerMap*>(reinterpret_cast<char*>(this) + 0x10c)))->FUN_00853130(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(apSetting)))->GetName())), (::fnv_00853130::CombatThreatRecord *&)(key)))
        {
            ::fnv_00c335a0::FUN_00c335a0(str_010121d0, ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(apSetting)))->GetName())));
        }
        else
        {
            reinterpret_cast<::TMapStandIn *>((reinterpret_cast<TESGlobalMap*>(reinterpret_cast<char*>(this) + 0x10c)))->InsertOrUpdate((unsigned int)(reinterpret_cast<char const*>(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(apSetting)))->GetName())))),
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
struct Registry
{
    void AddSettingKey(SettingName*);
};
// @fnv 0x0044f770
void Registry::AddSettingKey(SettingName* key)
{
    AutoMemHelper scope(9, true, ::g_ac5E0200SourceFile, 765);
    if (!((SettingStore*)((char*)this + 0x10c))->FUN_008256d0())
    {
        SettingNode* position = (SettingNode*)((char*)this + 0x10c);
        while (position)
        {
            SettingName* entry = *((::SettingName **)(new ((void *)(position)) ::Vec3()));
            if (FUN_00404dc0((const char*)reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName(), (const char*)reinterpret_cast<::Twin_0044ddc0 *>((key))->GetName()) == 0)
            {
                ::fnv_00c335a0::FUN_00c335a0("DEFAULT: Setting key '%s' already used in list.\nSetting keys must be unique.\n",
                             (const char*)reinterpret_cast<::Twin_0044ddc0 *>((key))->GetName());
                return;
            }
            position = ((::SettingNode *)(reinterpret_cast<::Callees *>((position))->FUN_00726070()));
        }
    }
    ((SettingStore*)((char*)this + 0x10c))->FUN_005ae3d0(&key);
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
    virtual bool v14(int data);
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
            if (*((int *)(new ((void *)(current)) ::Vec3())) != 0)
            {
                succeeded = succeeded & v14(*((int *)(new ((void *)(current)) ::Vec3())));
            }
            current = FUN_0044fac0(current);
        }
    }
    return succeeded;
}

template <class T> class SettingCollection
{
  public:
    virtual ~SettingCollection();
    char path[260];
    void* handle;
};
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
