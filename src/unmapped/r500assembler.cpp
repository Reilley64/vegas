
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <windows.h>
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_00b00260.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_0085f000.h"
#include "fnv/symbols_011c3000.h"
struct BSFile
{
    virtual ~BSFile();
};

struct FUN_0085fbb0 : public BSFile
{
    void Method_0085fbb0();
};

// @fnv 0x0085fbb0
void FUN_0085fbb0::Method_0085fbb0()
{
    BSFile::~BSFile();
}

struct FindData_t
{
    unsigned long dwFileAttributes;
    unsigned long ftCreationTime[2];
    unsigned long ftLastAccessTime[2];
    unsigned long ftLastWriteTime[2];
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};
struct _WIN32_FIND_DATAA;
struct DebrisData;
struct StartMenu
{
    const char* GetMenuTitle();
};
struct AEList
{
};
struct SL
{
    void* a;
    void* b;
    SL();
};
struct FUN_0085fb40
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    FUN_0085fb40(const char* path, int mode, int bufSize);
};
struct SaveLoadList
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    SL* list;
    void LoadSaveFiles();
};
extern "C" char DAT_01081a5c;

struct SpawnedObject
{
    void* volatile vfptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned char m_158;
    SpawnedObject* FUN_0085fb40(const char* a1, int a2, int a3);
};

// @fnv 0x0085fb40
SpawnedObject* SpawnedObject::FUN_0085fb40(const char* a1, int a2, int a3)
{
    new ((void *)(this)) ::FUN_00b00260(a1, a2, a3, 0);
    vfptr = &DAT_01081a5c;
    this->m_158 = 0;
    return this;
}

struct Item
{
    virtual ~Item();
};

struct ListNode
{
    Item* m_item;
    ListNode* m_pkNext;
};

struct List
{
    ~List();
};

struct FUN_0085fbd0_class
{
    char pad[0x70];
    List* m_kNode;

    void DeleteAllItems();
};
// @fnv 0x0085f900
void SaveLoadList::LoadSaveFiles()
{
    char path[260];
    {
        char fullPath[260];
        {
            FUN_0085fb40* file;
            {
                FindData_t findData;
                {
                    void* handle;
                    if (list)
                        reinterpret_cast<::FUN_0085fbd0_class *>(this)->DeleteAllItems();
                    list = new SL;
                    lstrcpyA(path, ((char *)(::FUN_004dc110())));
                    lstrcatA(path, ((const char *)(::FUN_00464f30(reinterpret_cast<std::intptr_t>((*reinterpret_cast<::StartMenu *>(&::g_011c3f74)).GetMenuTitle())))));
                    lstrcatA(path, "*.ess");
                    handle = FindFirstFileA(path, (_WIN32_FIND_DATAA*)&findData);
                    if (handle != (void*)-1)
                    {
                        do
                        {
                            if (findData.nFileSizeHigh || findData.nFileSizeLow)
                            {
                                ::FUN_00406d00(fullPath, 260, "%s%s%s", ((char *)(::FUN_004dc110())),
                                           ((const char *)(::FUN_00464f30(reinterpret_cast<std::intptr_t>((*reinterpret_cast<::StartMenu *>(&::g_011c3f74)).GetMenuTitle())))), findData.cFileName);
                                file = new FUN_0085fb40(fullPath, 0, 0x20000);
                                reinterpret_cast<::FUN_00470440 *>((((AEList*)list)))->FUN_007a7eb0((::BGSPerkEntry *)(::DebrisData *)((DebrisData*)file), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(((int (&)(DebrisData *, DebrisData *))::CompareFileWriteTimes)));
                            }
                        } while (FindNextFileA(handle, (_WIN32_FIND_DATAA*)&findData));
                        FindClose(handle);
                    }
                }
            }
        }
    }
}

// Iterates the list, deletes each item, clears the list, deletes the list, and nulls the pointer.
// @fnv 0x0085fbd0
void FUN_0085fbd0_class::DeleteAllItems()
{
    if (m_kNode)
    {
        ListNode* node = (ListNode*)m_kNode;
        while (node)
        {
            Item* item = node->m_item;
            if (item)
            {
                delete item;
            }
            node = ((::ListNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>((m_kNode))->RemoveAll();
        delete m_kNode;
        m_kNode = 0;
    }
}


struct SaveGameFileDeleteEntry85 : public FUN_0085fbb0
{
    void* FUN_0085fb80(unsigned int flags);
};

// Calls Method_0085fbb0 of the base, deletes this when bit 0 of flags is set, and returns this.
// @fnv 0x0085fb80
void* SaveGameFileDeleteEntry85::FUN_0085fb80(unsigned int flags)
{
    FUN_0085fbb0::Method_0085fbb0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
