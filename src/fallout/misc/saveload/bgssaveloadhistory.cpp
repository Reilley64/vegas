// fallout/misc/saveload/bgssaveloadhistory.cpp: SaveLoadChangeHistory (12 functions)

#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_0084e320_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00864740_shell.h"
#include "fnv/decl/FUN_00865c40_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865e70_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0084b5c0__FUN_0084b5c0_Array.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00574000.h"
#include "bgssaveloadhistory_types_BGSSaveLoadHistory.h"
#include "bgssaveloadhistory_types_CombatTargetMap.h"
#include "bgssaveloadhistory_types_TaskQueueInterface.h"
#include "bgssaveloadhistory_decls.h"
#include <stdarg.h>
#include <new>

// Calls FUN_009a4250 on the map stored at this object's first pointer with history and returns whether it succeeded.
// @fnv 0x0084aad0
bool SaveLoadChangeHistory::MatchesHistory(SaveLoadChangeHistory* history)
{
    if (reinterpret_cast<BGSSaveLoadChangesMap*>(*reinterpret_cast<void**>(this))
            ->FUN_009a4250(reinterpret_cast<unsigned int>(history)))
        return true;
    return false;
}

// @fnv 0x0084dff0
void SaveLoadChangeHistory::AddNote(const char* format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    AddNoteWithArguments(format, arguments);
    va_end(arguments);
}

// Clears the field at offset 0xd68 and removes all entries from the BSSimpleList at offset 0x5fc.
// @fnv 0x00848e10
void SaveLoadChangeHistory::Init()
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xd68) = 0;
    reinterpret_cast<::FileMatchList *>((reinterpret_cast<BSSimpleList<ActorCause*>*>(reinterpret_cast<char*>(this) + 0x5fc)))->RemoveAll();
}

// Calls FUN_0084c2a0 twice, with (0, 12) and (1000, 1001), passing flags through to each call.
// @fnv 0x0084c270
void BGSSaveLoadHistory_Destroy(unsigned char flags)
{
    FUN_0084c2a0(0, 12, flags);
    FUN_0084c2a0(1000, 1001, flags);
}

// @fnv 0x0084e020
void SaveLoadChangeHistory::AddNoteWithArguments(const char* format, char* arguments)
{
    BGSSaveLoadHistoryNoteLocals locals;
    int length;
    if (!*reinterpret_cast<unsigned char*>(reinterpret_cast<SettingT<INISettingCollection>*>(0x11de0a4)->Bool()))
        return;
    length = FUN_00407000(locals.buffer, format, arguments);
    if (length > 0)
    {
        locals.allocation = static_cast<char*>(::operator new(length + 1));
        locals.note = locals.allocation;
        TaskQueueInterface::CopyStringToBuffer(locals.note, length + 1, locals.buffer);
        reinterpret_cast<::FUN_00438690 *>((reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&Notes)))->FUN_007cb2e0((unsigned int *)&(reinterpret_cast<NavMeshInfo*&>(locals.note)));
    }
}

// Reads a count and that many strings from a BGSLoadGameBuffer and appends each to the Notes array.
// @fnv 0x0084e190
void SaveLoadChangeHistory::Load(SaveLoadFile* file)
{
    BGSLoadGameBuffer buffer;
    reinterpret_cast<::FUN_00864740_shell *>(&(buffer))->ReadAndVerifySize(file);
    {
        BGSLoadGameBuffer* pBuffer = &buffer;
        {
            unsigned int count = 0;
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&count), 4);
            for (unsigned int i = 0; i < count; i++)
            {
                char* note = reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((pBuffer))->FUN_008649a0(0);
                reinterpret_cast<::FUN_00438690 *>((reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&Notes)))->FUN_007cb2e0(
                    (unsigned int *)&(reinterpret_cast<NavMeshInfo*&>(note)));
            }
        }
    }
}

struct HArr
{
    HArr();
    ~HArr();
};
struct FUN_0084ded0 : public HArr
{
    FUN_0084ded0();
};
// @fnv 0x0084ded0
FUN_0084ded0::FUN_0084ded0()
{
    reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>(this)->FUN_0084b5c0(0x40);
}

struct FUN_0084e2c0_shell : public SaveLoadChangeHistory
{
    void AddAllNotes(SaveLoadChangeHistory*);
};

struct HH84
{
};
// Iterates over the history's entry count, retrieves each string by index and passes it to AddNote.
// @fnv 0x0084e2c0
void FUN_0084e2c0_shell::AddAllNotes(SaveLoadChangeHistory* apHistory)
{
    unsigned int icount = reinterpret_cast<::FUN_00620b80_shell *>((reinterpret_cast<HH84*>(apHistory)))->GetReferenceFlags();
    for (unsigned int i = 0; i < icount; i++)
    {
        const char* pNote = ((const char *)(reinterpret_cast<::FUN_0084e320_Class *>((reinterpret_cast<HH84*>(apHistory)))->GetArrayElement(i)));
        AddNote(pNote);
    }
}

extern int _data_011c16bc;
struct FUN_00822630
{
    ~FUN_00822630();
};
struct FUN_0084df30 : FUN_00822630
{
    ~FUN_0084df30();
};
struct ArrSI
{
};
struct _Mem_20a4
{
};
struct FUN_0084df90_shell : ArrSI
{
    unsigned int& GetAt(int);
    void DeleteAllElements();
};
// @fnv 0x0084df30
FUN_0084df30::~FUN_0084df30()
{
    reinterpret_cast<::FUN_0084df90_shell *>(this)->DeleteAllElements();
}
// Deletes each element returned by GetAt up to GetFlags, then resets the container size to 0.
// @fnv 0x0084df90
void FUN_0084df90_shell::DeleteAllElements()
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())); i++)
        delete reinterpret_cast<void*>(((unsigned int)(reinterpret_cast<::S3e60 *>(this)->FUN_006a7ad0(i))));
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((reinterpret_cast<_Mem_20a4*>(this)))->FUN_006f2290(0, false);
}

struct FUN_0084e250_shell
{
    unsigned int& GetAt(int);
    void DeleteItemsFrom(unsigned int count);
};


// @fnv 0x0084e250
void FUN_0084e250_shell::DeleteItemsFrom(unsigned int uiStartIndex)
{
    int size = ((int)(reinterpret_cast<::FUN_00620b80_shell *>(this)->GetReferenceFlags()));
    if (uiStartIndex >= (unsigned int)size)
        return;
    for (unsigned int i = uiStartIndex; i < (unsigned int)size; ++i)
    {
        void* item = (void*)((unsigned int)(reinterpret_cast<::S3e60 *>(this)->FUN_006a7ad0(i)));
        ::FUN_00401030(item);
    }
    reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(this)->FUN_009a4320(uiStartIndex, (unsigned int)size - uiStartIndex);
}

class NavMeshInfo84E;
class SaveTarget84E;

class BGSSaveGameBuffer84E
{
  public:
    BGSSaveGameBuffer84E();
    ~BGSSaveGameBuffer84E();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class NavMeshInfoArray84E
{
  public:
    unsigned int GetSize();
    NavMeshInfo84E*& GetAt(int iIndex);
    void SaveTo(SaveTarget84E* pkTarget);
};

// Saves the array size and each NavMeshInfo element into a BGSSaveGameBuffer, then writes the buffer to pkTarget.
// @fnv 0x0084e0d0
void NavMeshInfoArray84E::SaveTo(SaveTarget84E* pkTarget)
{
    BGSSaveGameBuffer84E kBuffer;
    BGSSaveGameBuffer84E* pkBuffer6 = &kBuffer;

    unsigned int ItemUpdateArray = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer6))->FUN_00865e50(&ItemUpdateArray, 4, 0);
    for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; uiIndex++)
    {
        NavMeshInfo84E* pkInfo = ((::NavMeshInfo84E *)(reinterpret_cast<::S3e60 *>(this)->FUN_006a7ad0(uiIndex)));
        reinterpret_cast<::FUN_00865e70_shell *>((pkBuffer6))->FUN_00865e70((const char *)(pkInfo), 0);
    }

    reinterpret_cast<::FUN_00865c40_shell *>(&(kBuffer))->FUN_00865c40((::FUN_00846330_shell *)(pkTarget));
}
