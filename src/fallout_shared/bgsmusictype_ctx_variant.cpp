
// bgsmusictype_ctx_variant.cpp: context variant of src/fallout_shared/bgsmusictype.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00591a20_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00462000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00944000.h"
#include "music_local.h"
#include <malloc.h>

#include <windows.h>


class AutoMemHelper
{
  public:
    int unk00;
    AutoMemHelper(int context, bool leave, const char* file, int line);
    ~AutoMemHelper();
};

class BSDirectoryIterator
{
  public:
    void* m_hFindHandle;
    _WIN32_FIND_DATAA m_findData;
    BGSMusicType::MusicTrack m_path;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    BSDirectoryIterator(const char* path);
    ~BSDirectoryIterator();
    int Next(bool* outDone);
};

class MusicFileBuilder : public BGSMusicType
{
  public:
    void FUN_005917b0();
};

// @fnv 0x005917b0
void MusicFileBuilder::FUN_005917b0()
{
    AutoMemHelper memContext(11, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSMusicType.cpp", 352);
    const char* soundFile5 = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)this)->FUN_00408da0()));
    char path5[260];
    char fullPathA[260];
    ::FUN_00406d00(path5, 0x104, "%s\\%s", "Data\\Music", soundFile5);
    const char* ext_2 = ".mp3";
    bool done4 = false;
    BSDirectoryIterator iter(path5);
    int res3 = iter.Next(&done4);
    while (!done4 && res3 == 0)
    {
        if (!((bool)(reinterpret_cast<::FUN_00591a20_Class *>(&(iter))->IsFlagBit4Set())) && ((const char *)(reinterpret_cast<::TESTopicInfo *>(&(iter))->GetAddTopicList())))
        {
            char fileExt[260];
            FUN_00462d40(((const char *)(reinterpret_cast<::TESTopicInfo *>(&(iter))->GetAddTopicList())), 0, 0, 0, 0, 0, 0, fileExt, 0x104);
            if (FUN_00404dc0(fileExt, ext_2) == 0)
            {
                ::FUN_00406d00(fullPathA, 0x104, "%s%s", path5, ((const char *)(reinterpret_cast<::TESTopicInfo *>(&(iter))->GetAddTopicList())));
                MusicTrack* entry = new MusicTrack(fullPathA);
                m_kMusicFiles.AddHead(entry);
            }
        }
        res3 = iter.Next(&done4);
    }
}
