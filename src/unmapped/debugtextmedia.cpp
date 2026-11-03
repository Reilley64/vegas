// src/unmapped/debugtextmedia.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtextmedia.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include "fnv/decl/BGSSaveLoadFileEntry.h"
#include "fnv/decl/DirectoryIterator.h"
#include "fnv/decl/FUN_004de2d0_StandIn.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_006ea330_shell.h"
#include "fnv/decl/FUN_0075f8c0_shell.h"
#include "fnv/decl/FUN_007d5160_shell.h"
#include "fnv/decl/FUN_007d5180_shell.h"
#include "fnv/decl/FUN_00851f50_class.h"
#include "fnv/decl/FUN_00851fc0_shell.h"
#include "fnv/decl/FUN_00851ff0_class.h"
#include "fnv/decl/FUN_00852060_Class.h"
#include "fnv/decl/FUN_008526d0_shell.h"
#include "fnv/decl/FUN_00852700_Class.h"
#include "fnv/decl/FUN_008d85e0_Class.h"
#include "fnv/decl/FileSizeInfo.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_00851f10__BGSSaveLoadFileEntry.h"
#include "fnv/decl/fnv_00851f30__BGSSaveLoadFileEntry.h"
#include "fnv/decl/fnv_00851f60__FUN_00851f60_Class.h"
#include "fnv/decl/fnv_00851f90__FUN_00851f90_class.h"
#include "fnv/decl/fnv_00852030__FUN_00852030_Class.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_007d6000.h"
#include "fnv/symbols_0084c000.h"
#include "fnv/symbols_0084d000.h"
#include "fnv/symbols_00852000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011de000.h"
namespace fnv_00852080 {
// FUN_00852080 v3 - full Handle-scope transcription (worker4)
class GlobalObject_0045cf30
{
  public:
    unsigned char* FUN_00408d60();
};
int __cdecl FUN_00406d50(char* dst, unsigned int sz, const char* src);
extern const char saveExtension[];
int __cdecl FUN_004564f0(char* a, const char* b, int n);

class Finder
{
  public:
    Finder(char* p);
    ~Finder();
    void* searchHandle;
    unsigned int attributes;
    unsigned int creationLow, creationHigh;
    unsigned int accessLow, accessHigh;
    unsigned int writeLow, writeHigh;
    unsigned int sizeHigh, sizeLow;
    unsigned int reserved0, reserved1;
    char filename[260];
    char alternateFilename[14];
    char path[260];
    int status;
    int unk24c;
    int unk250;
    int unk254;
};
class Handle
{
  public:
    Handle(char* name, int a, int b, bool c);
    ~Handle();
    void* file;
    int mode;
    int flags;
    bool option;
    int unk10;
};
class SaveData
{
  public:
    SaveData(const char* name, int z, int v);
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
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
};
class InfoLike
{
  public:
};
class EntryLike
{
  public:
    EntryLike(char* name, int z);
    ~EntryLike();
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

};
class SingObj
{
  public:
    void* FUN_008526c0();
};
SingObj* __cdecl FUN_00af2640();
class VCall8
{
  public:
    virtual void s0();
    virtual void s1();
    virtual int v8(char* buf, int n);
};
class VCall20
{
  public:
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual int v20(int v);
};
class GlobalObject_0040c150
{
  public:
};

union SizePair
{
    __int64 value;
    struct
    {
        int low;
        int high;
    };
};

class ThisCls
{
  public:
    void* m_thispad;
    void FUN_00852080(int unused);
};

// Loops over files in the Saves directory and, for each save-extension file, reads it into a SaveData and fills an info entry for copying it to the target.
// @fnv 0x00852080
void ThisCls::FUN_00852080(int unused)
{
    int lenTmp7;
    unsigned char settingByte16;
    char buf127[0x104];

    settingByte16 = *(*reinterpret_cast<::fnv_00852080::GlobalObject_0045cf30 *>(&::g_011de308)).FUN_00408d60();
    reinterpret_cast<::FUN_004de2d0_StandIn *>(&((*reinterpret_cast<::fnv_00852080::GlobalObject_0045cf30 *>(&::g_011de308))))->FUN_004de2d0(0);
    FUN_00406d50(buf127, 0x104, "Saves");
    FUN_00406d50(buf127, 0x104, "/");
    Finder finder(buf127);
    unsigned char flag29;
    flag29 = 0;
    reinterpret_cast<::DirectoryIterator *>(&(finder))->NextEntry((*(bool *)(&flag29)));
    while (flag29 == 0)
    {
        if (reinterpret_cast<::FUN_00852700_Class *>(&(finder))->IsFlagged() == 1)
        {
            lenTmp7 = ((int)(::FUN_0044a670(((char *)(reinterpret_cast<::TESTopicInfo *>(&(finder))->GetAddTopicList())))));
            if (FUN_004564f0(((char *)(reinterpret_cast<::TESTopicInfo *>(&(finder))->GetAddTopicList())) + lenTmp7 - 4, saveExtension, 4) == 0)
            {
                {
                    char buf410[0x100];
                    EntryLike* entry3;
                    char buf313[0x108];
                    void* info8;
                    SizePair kPair1a12;
                    int val4a8;
                    SizePair pair2a;
                    char buf2[0x108];
                    ::FUN_00406d00(buf2, 0x104, "%s%s", buf127, ((char *)(reinterpret_cast<::TESTopicInfo *>(&(finder))->GetAddTopicList())));
                    Handle handle20(buf2, 0, 0, 0);
                    if (::FUN_00559450((int *)&(handle20)) == 0)
                    {
                        kPair1a12.low = 0;
                        kPair1a12.high = 0;
                        reinterpret_cast<::FileSizeInfo *>(&(handle20))->FUN_0065c290((*(::_LARGE_INTEGER *)(&kPair1a12.low)));
                        val4a8 = (int)new SaveData("SaveData", 0, kPair1a12.low);
                        info8 = ((void *)(reinterpret_cast<::FUN_0068efb0_shell *>((((InfoLike*)(void*)val4a8)))->FUN_0068efb0()));
                        pair2a.low = 0;
                        pair2a.high = 0;
                        reinterpret_cast<::FUN_008526d0_shell *>(&(handle20))->SetFromCall(
                            ((int)(reinterpret_cast<::FUN_008d85e0_Class *>((((InfoLike*)info8)))->GetUnk15C())), {}, {}, {});
                        if (::FUN_00559450((int *)&(handle20)) == 0)
                        {
                            ::FUN_00406d00(buf313, 0x104, "Copying the save game file to the target...\n\n");
                            FUN_00406d50(buf313, 0x104, buf2);
                            ((VCall8*)FUN_00af2640()->FUN_008526c0())->v8(buf313, 1000);
                            entry3 = new EntryLike(buf2, 0);
                            ::ReadSaveFileHeader((void *)(val4a8), (void *)((int)entry3));
                            reinterpret_cast<::FUN_006ea330_shell *>((entry3))->FUN_006ea330();
                            reinterpret_cast<::fnv_00851f60::FUN_00851f60_Class *>((((InfoLike*)info8)))->FUN_00851f60((unsigned int)("-SAVE-"));
                            if (((char *)(::FUN_007d6970((::BGSSaveLoadFileEntry *)(entry3)))) != 0 && ((int)(::FUN_0044a670(((char *)(::FUN_007d6970((::BGSSaveLoadFileEntry *)(entry3))))))) != 0)
                                reinterpret_cast<::fnv_00851f90::FUN_00851f90_class *>((((InfoLike*)info8)))->FUN_00851f90((unsigned int)(((char *)(::FUN_007d6970((::BGSSaveLoadFileEntry *)(entry3))))));
                            else
                                reinterpret_cast<::fnv_00851f90::FUN_00851f90_class *>((((InfoLike*)info8)))->FUN_00851f90((unsigned int)("Location"));
                            ::FUN_00406d00(
                                buf410, 0x100, "%s\n%s %d: %s\n%s: %s",
                                reinterpret_cast<::FUN_0075f8c0_shell *>((entry3))->FUN_0075f8c0() ? reinterpret_cast<::FUN_0075f8c0_shell *>((entry3))->FUN_0075f8c0() : (char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00852080::GlobalObject_0040c150 *>(&::g_011d4f78))))->GetMenuTitle())),
                                ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00852080::GlobalObject_0040c150 *>(&::g_011d3b2c))))->GetMenuTitle())), reinterpret_cast<::FUN_007d5160_shell *>((entry3))->FUN_007d5160(),
                                reinterpret_cast<::BGSSaveLoadFileEntry *>((entry3))->FUN_007d5140() ? reinterpret_cast<::BGSSaveLoadFileEntry *>((entry3))->FUN_007d5140() : "-", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00852080::GlobalObject_0040c150 *>(&::g_011d3954))))->GetMenuTitle())),
                                reinterpret_cast<::FUN_007d5180_shell *>((entry3))->FUN_007d5180() ? reinterpret_cast<::FUN_007d5180_shell *>((entry3))->FUN_007d5180() : (char*)((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00852080::GlobalObject_0040c150 *>(&::g_011d3954))))->GetMenuTitle())));
                            reinterpret_cast<::FUN_00851fc0_shell *>((((InfoLike*)info8)))->FUN_00851fc0((unsigned int)(buf410));
                            reinterpret_cast<::FUN_00851ff0_class *>((((InfoLike*)info8)))->FUN_00851ff0(((int)(reinterpret_cast<::BGSSaveLoadFileEntry *>((entry3))->FUN_00851ef0())), ((int)(reinterpret_cast<::fnv_00851f10::BGSSaveLoadFileEntry *>((entry3))->FUN_00851f10())),
                                               ((int)(reinterpret_cast<::FUN_008d85e0_Class *>((((InfoLike*)info8)))->GetUnk15C())) + ((int)(reinterpret_cast<::fnv_00851f30::BGSSaveLoadFileEntry *>((entry3))->FUN_00851f30())));
                            reinterpret_cast<::fnv_00852030::FUN_00852030_Class *>((((InfoLike*)info8)))->FUN_00852030((int)("DATA/SYSUTIL/SAVEBACK.PNG"));
                            reinterpret_cast<::FUN_00852060_Class *>((((InfoLike*)info8)))->SetValue((int)&((void (&)())::fnv_00852740::FUN_00852740));
                            delete entry3;
                            reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>(this)->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(val4a8));
                            ((VCall20*)reinterpret_cast<::FUN_00851f50_class *>((FUN_00af2640()))->FUN_00851f50())->v20((int)info8);
                            while (reinterpret_cast<::PatrolActorPackageData *>((((SingObj*)reinterpret_cast<::FUN_00851f50_class *>((FUN_00af2640()))->FUN_00851f50())))->IsPatrolling() == 1)
                                ::FUN_0040fca0(10);
                        }
                        else
                        {
                            ::FUN_0084cbd0(
                                "BGSSaveLoadManager::CopySaveGamesFromHost failed to read the save game file buffer %s.\n",
                                buf2);
                        }
                    }
                    else
                    {
                        ::FUN_0084cbd0(
                            "BGSSaveLoadManager::CopySaveGamesFromHost failed to open the save game file %s.\n", buf2);
                    }
                }
            }
        }
    next_iter:
        reinterpret_cast<::DirectoryIterator *>(&(finder))->NextEntry((*(bool *)(&flag29)));
    }
    reinterpret_cast<::FUN_004de2d0_StandIn *>(&((*reinterpret_cast<::fnv_00852080::GlobalObject_0045cf30 *>(&::g_011de308))))->FUN_004de2d0(settingByte16);
}
}  // namespace fnv_00852080

#include "generated/data/unmapped/debugtextmedia.inc"
