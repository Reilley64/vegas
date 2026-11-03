// fallout_shared/tessaveloadgame.cpp: TESSaveLoadGame, NiTPointerMap_Standin, Holder, ChangesMap and more (142 functions)

#include <windows.h>
#include <new>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/B88B7F0Process.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSLoadFormBuffer.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Calendar.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Cell550.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_0041b320_shell.h"
#include "fnv/decl/FUN_0041cd70_shell.h"
#include "fnv/decl/FUN_0041d460_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_00446ff0.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00453980_shell.h"
#include "fnv/decl/FUN_00459470_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0046a010_shell.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_00473070Class.h"
#include "fnv/decl/FUN_00473080_Class.h"
#include "fnv/decl/FUN_00473180_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00483c70_shell.h"
#include "fnv/decl/FUN_00485b30_shell.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_00546af0_shell.h"
#include "fnv/decl/FUN_00555bc0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005757d0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0063e940_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084c580_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00854e40_Class.h"
#include "fnv/decl/FUN_00854e70_class.h"
#include "fnv/decl/FUN_00856300_cls.h"
#include "fnv/decl/FUN_00857210_shell.h"
#include "fnv/decl/FUN_00857230_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_00857ba0_shell.h"
#include "fnv/decl/FUN_008586d0_class.h"
#include "fnv/decl/FUN_00858aa0_shell.h"
#include "fnv/decl/FUN_00859120_cls.h"
#include "fnv/decl/FUN_0085fbd0_class.h"
#include "fnv/decl/FUN_0085fed0_Class.h"
#include "fnv/decl/FUN_00863db0_class.h"
#include "fnv/decl/FUN_00863e30_struct.h"
#include "fnv/decl/FUN_00864160.h"
#include "fnv/decl/FUN_00933790Class.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00c3db60.h"
#include "fnv/decl/FUN_00c3fca0_Class.h"
#include "fnv/decl/FUN_00c42b60_class.h"
#include "fnv/decl/FUN_00c42dd0.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/HandlerView.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/OwnQ.h"
#include "fnv/decl/P09A.h"
#include "fnv/decl/PLTempEffectSaver.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/RestoreBuffer.h"
#include "fnv/decl/S00c3fce0_cls.h"
#include "fnv/decl/S457d70.h"
#include "fnv/decl/S86a0.h"
#include "fnv/decl/S_0064dac0.h"
#include "fnv/decl/S_00c3e490.h"
#include "fnv/decl/SaveBlockOwner.h"
#include "fnv/decl/SaveLoadList.h"
#include "fnv/decl/SaveProcessLists.h"
#include "fnv/decl/SaveSizeOwner.h"
#include "fnv/decl/Sky.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESQuest.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/W004702f0.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00446f70__FUN_00446f70_Cl.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00578870__FUN_00578870_Class.h"
#include "fnv/decl/fnv_0063e9f0__FUN_0063e9f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00851cb0__S00851cd0.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_008a8150__FUN_008a8150_shell.h"
#include "fnv/decl/fnv_009754f0__FUN_009754f0_shell.h"
#include "fnv/decl/s85ac30__RefLoader.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_004f1000.h"
#include "fnv/symbols_00526000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00573000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00856000.h"
#include "fnv/symbols_00878000.h"
#include "fnv/symbols_00890000.h"
#include "fnv/symbols_0093a000.h"
#include "fnv/symbols_009ee000.h"
#include "fnv/symbols_00a5f000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aff000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_0105a000.h"
#include "fnv/symbols_01063000.h"
#include "fnv/symbols_01080000.h"
#include "fnv/symbols_01081000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_01186000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011a2000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "tessaveloadgame_decls.h"
#include <cstddef>
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00855220_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/TaskThreadResume.h"
#include "fnv/decl/Worker.h"
#include "fnv/symbols_01272000.h"
// Looks up the TESObjectREFR stored in this pointer map under the given id and returns it, or null if absent.
// @fnv 0x00855100
TESObjectREFR* TESSaveLoadGame::QueueRemoveReferenceChange(unsigned int id)
{
    TESObjectREFR* result = 0;
    reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((NiTPointerMap<unsigned int, TESObjectREFR*>*)this)))->FUN_00853130(id, (::fnv_00853130::CombatThreatRecord *&)(result));
    return result;
}
// @fnv 0x00856c70
void TESSaveLoadGame::HasFormChanges(TESForm* form, bool clear)
{
    if (!reinterpret_cast<::FUN_004077c0_shell *>((void *)(form))->FUN_004077c0())
        changes->HasFormChanges(form, clear);
}
// Removes the given TESForm from the deferred list if it is present.
// @fnv 0x0085a410
void TESSaveLoadGame::FinalizeForm(TESForm* form)
{
    if (reinterpret_cast<::RefList *>(&(deferred))->FUN_005f65d0((void **)&((BGSNote*&)form)))
        reinterpret_cast<::ItemChangeListNode *>((((BSSimpleList<BGSCameraShot*>*)&deferred)))->FUN_00905330((::InventoryStackRecord *const &)((BGSCameraShot* const&)form));
}
// Initializes the task manager thread: calls FUN_00c42dd0 with arg and DAT_010c1748, then stores DAT_010c1740 in table and owner in manager.
// @fnv 0x00c3ee70
BSTaskManagerThread::BSTaskManagerThread(void* owner, unsigned int arg)
{
    new ((void *)this) ::FUN_00c42dd0(arg, DAT_010c1748);
    table = DAT_010c1740;
    manager = owner;
}

struct S006b81d0
{
    bool IsKeyEqual(unsigned int key1, unsigned int key2);
};
// @fnv 0x006b81d0
bool S006b81d0::IsKeyEqual(unsigned int key1, unsigned int key2)
{
    return key1 == key2;
}

struct S006c6a60
{
    unsigned int pad;
    unsigned int size;
    unsigned int GetIndexForKey(unsigned int key);
};
// @fnv 0x006c6a60
unsigned int S006c6a60::GetIndexForKey(unsigned int key)
{
    return key % size;
}

struct ChangeData
{
    void NotifyFormIDChanged(unsigned int);
    void ClearFormChangeFlags(unsigned int);
    void SetBuffer(void*);
    void* GetBuffer();
    unsigned int GetFlags();
    void SetFlags(unsigned int);
    void SetChange(unsigned int);
    void* __vecDelDtor(unsigned int);
    unsigned int iFlags;
    void* pBuffer;
};
struct FUN_00855220_shell : public ChangesMap
{
    bool FUN_00855220(unsigned int, bool);
};
// @fnv 0x008551f0
bool ChangesMap::HasFormChanges(TESForm* form, bool clear)
{
    return reinterpret_cast<::FUN_00855220_shell *>(this)->FUN_00855220(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())), clear);
}

struct LoadingHelper00855220
{
};
struct RemoveAtHelper00855220
{
};
struct Chg00855220
{
    int a;
    int b;
};
extern int DAT_01080514;
struct Dummy_00863390
{
    void FUN_00863390(int);
};

// @fnv 0x008552b0
int* FUN_008552b0(Dummy_00863390* apObject)
{
    apObject->FUN_00863390(0x25);
    *(int*)apObject = (int)&DAT_01080514;
    return (int*)apObject;
}

namespace fnv_008553e0 {
extern int DAT_01080514;
struct Dummy_00863390
{
    void FUN_00863390(int);
};

// Calls FUN_00863390 with 0x25, stores the address of DAT_01080514 into the object, and returns the object pointer.
// @fnv 0x008553e0
int* FUN_008553e0(Dummy_00863390* apObject)
{
    apObject->FUN_00863390(0x25);
    *(int*)apObject = (int)&DAT_01080514;
    return (int*)apObject;
}
}  // namespace fnv_008553e0

namespace fnv_00855550 {
extern int DAT_01080514;
struct Dummy_00863390
{
    void FUN_00863390(int);
};

// Calls FUN_00863390 with 0x25, stores the address of DAT_01080514 into the object, and returns the object pointer.
// @fnv 0x00855550
int* FUN_00855550(Dummy_00863390* apObject)
{
    apObject->FUN_00863390(0x25);
    *(int*)apObject = (int)&DAT_01080514;
    return (int*)apObject;
}
}  // namespace fnv_00855550

// @fnv 0x00856850
void CopyByteToOffset80(char* pBuffer)
{
    pBuffer[0x80] = pBuffer[0x75];
}

struct NiTMapItem_00863840
{
    NiTMapItem_00863840* m_pkNext;
    unsigned int m_key;
    void* m_val;
};

struct ArgItem_00863840
{
    NiTMapItem_00863840* pkItem;
};
struct ArgKey_00863840
{
    unsigned int key;
};
struct ArgVal_00863840
{
    void* val;
};

// @fnv 0x00863840
void SetMapItemKeyValue(void* pThis, ArgItem_00863840 pkItem, ArgKey_00863840 key, ArgVal_00863840 val)
{
    pkItem.pkItem->m_key = key.key;
    pkItem.pkItem->m_val = val.val;
}

struct NiTLargeArray
{
    unsigned int SetAtGrow(unsigned int, const unsigned int&);
};
struct S00863d90
{
    unsigned int a, b, c;
    unsigned int cnt;
    void FUN_00863d90(const unsigned int& e);
};
// Appends the given element to the array at index cnt via SetAtGrow.
// @fnv 0x00863d90
void S00863d90::FUN_00863d90(const unsigned int& auiElement)
{
    ((NiTLargeArray*)this)->SetAtGrow(cnt, auiElement);
}

struct Elem00c3e7d0
{
};
struct S00c3e7d0
{
    char pad[0x44];
    volatile long a44;
    volatile long a48;
    unsigned int a4c;
    Elem00c3e7d0** a50;
    bool ReleaseAndCleanup();
};
// If a48 is nonzero, decrements it; when it reaches zero, waits for a44 to equal a4c, then calls FUN_00446ff0 on each of a4c elements and decrements a44.
// @fnv 0x00c3e7d0
bool S00c3e7d0::ReleaseAndCleanup()
{
    if (a48 == 0)
        return false;
    if (InterlockedDecrement(&a48) == 0)
    {
        while (a44 != a4c)
            Sleep(1);
        for (unsigned int i = 0; i < a4c; i++)
        {
            reinterpret_cast<::FUN_00446ff0 *>((a50[i]))->FUN_00446ff0_();
            InterlockedDecrement(&a44);
        }
        {
            int u1, u2, u3;
        }
        return true;
    }
    return false;
}

namespace fnv_007065c0 {
struct FUN_008df040_shell
{
    unsigned char FUN_008df040(void);
};


// @fnv 0x007065c0
unsigned short __cdecl FUN_007065c0(void)
{
    unsigned short v = 0;
    v += 4;
    v += 4;
    if (((FUN_008df040_shell*)::g_TESSaveLoadGame)->FUN_008df040() >= 0x5d)
        v += 1;
    return v;
}
}  // namespace fnv_007065c0

struct InteriorCellNewReferencesMap
{
    void* FUN_008552e0(unsigned int flags);
};


// Compares the values at index 5 of two unsigned short arrays, returning -1, 1, or 0.
// @fnv 0x00855b60
int CompareByIndex5(unsigned short* ausLeft, unsigned short* ausRight)
{
    int result;
    if (ausLeft[5] > ausRight[5])
        result = -1;
    else
        result = (ausLeft[5] < ausRight[5]) ? 1 : 0;
    return result;
}

namespace fnv_00858700 {

struct FUN_00858700
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    void* m_ptr;
    void DoIt(void* arg);
};

// Deallocates arg via _Deallocate and sets m_ptr to null.
// @fnv 0x00858700
void FUN_00858700::DoIt(void* arg)
{
    ::FUN_00401030(arg);
    m_ptr = 0;
}
}  // namespace fnv_00858700


// @fnv 0x00860e00
void FUN_00860e00(void* apFirst, void* apSecond)
{
    std::strpbrk((char *)(apFirst), (const char *)(apSecond));
}

struct FUN_00861610_Class
{
    char m_auiShapeKeys[0x5c];
    int* m_field5C;
    int GetRangeBetweenEntries(int arg, int arg2);
};

// Returns the difference between the element at index arg+1 and the element at index arg in the array pointed to by m_field5C.
// @fnv 0x00861610
int FUN_00861610_Class::GetRangeBetweenEntries(int aiIndex, int aiUnused)
{
    return m_field5C[aiIndex + 1] - m_field5C[aiIndex];
}

struct FUN_008620f0
{
    unsigned char m_0x74;
    unsigned char m_0x75;
    void Init();
};

// @fnv 0x008620f0
void FUN_008620f0::Init()
{
    ((unsigned char*)this)[0x74] = 0;
    ((unsigned char*)this)[0x75] = 0x7d;
}

struct FUN_008634e0
{
    void* FUN_00863860();
    void* DeleteThis(unsigned int flags);
};

// Calls FUN_00863860, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008634e0
void* FUN_008634e0::DeleteThis(unsigned int flags)
{
    FUN_00863860();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00863540 {

struct FUN_00863540_class
{
    void FUN_00863cd0();
    void* FUN_00863540(unsigned int flags);
};

// Calls FUN_00863cd0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00863540
void* FUN_00863540_class::FUN_00863540(unsigned int flags)
{
    FUN_00863cd0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00863540

struct FUN_00863c90_Class
{
    bool IsEqual(unsigned char a, unsigned char b);
};

// @fnv 0x00863c90
bool FUN_00863c90_Class::IsEqual(unsigned char aucLeft, unsigned char aucRight)
{
    return aucLeft == aucRight;
}

struct ActorCombatGroup;

struct NiTMallocInterface
{
};

extern int DAT_01081f98;

struct FUN_00863d60_obj
{
    int field0;
    ActorCombatGroup** field4;
    void FUN_00863d60();
};

// Sets field0 to the address of DAT_01081f98, then deallocates field4 via NiTMallocInterface::Deallocate.
// @fnv 0x00863d60
void FUN_00863d60_obj::FUN_00863d60()
{
    field0 = reinterpret_cast<int>(&DAT_01081f98);
    ::FUN_004ede70(field4);
}

struct FUN_00855130_This
{
    TESObjectREFR* FUN_00855130(TESForm* arg);
};

// @fnv 0x00855130
TESObjectREFR* FUN_00855130_This::FUN_00855130(TESForm* pForm)
{
    return ((TESSaveLoadGame*)this)->QueueRemoveReferenceChange(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pForm))->FUN_0084e3a0())));
}

struct FUN_00863480Class
{
    void FUN_00863640();
    void* FUN_00863480(unsigned int flags);
};


// Calls FUN_00863640, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00863480
void* FUN_00863480Class::FUN_00863480(unsigned int flags)
{
    FUN_00863640();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00863c70_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int ModuloByDivisor(unsigned char a);
};

// @fnv 0x00863c70
int FUN_00863c70_Class::ModuloByDivisor(unsigned char a)
{
    return a % (unsigned int)m_iWordAt04;
}



struct NiTPointerMap_Standin
{
    void* m_ppVirtualMethodTable;
    void* m_unknown;
    void* m_ptr;
    void RemoveAll();
    void ClearAndFree();
};

void NiTPointerMap_Standin::RemoveAll()
{}

// @fnv 0x00863d30
void NiTPointerMap_Standin::ClearAndFree()
{
    m_ppVirtualMethodTable = &DAT_01081f78;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(m_ptr);
}

namespace fnv_00484ce0 {
struct TESSaveLoadGameHelper
{
    void FUN_00484ce0(void* form, int flag);
};


// Forwards the form and flag to the save/load game's FUN_008579b0 handler.
// @fnv 0x00484ce0
void TESSaveLoadGameHelper::FUN_00484ce0(void* form, int flag)
{
    reinterpret_cast<::FUN_008579b0_shell *>((((TESSaveLoadGameHelper*)::g_TESSaveLoadGame)))->FUN_008579b0(form, flag);
}
}  // namespace fnv_00484ce0

namespace fnv_00484d00 {
struct FUN_008579e0_shell
{
    void FUN_008579e0(void* buffer, unsigned int size);
};


struct FUN_00484d00_shell
{
    void FUN_00484d00(void* buffer, unsigned int size);
};

// @fnv 0x00484d00
void FUN_00484d00_shell::FUN_00484d00(void* buffer, unsigned int size)
{
    reinterpret_cast<FUN_008579e0_shell*>(::g_TESSaveLoadGame)->FUN_008579e0(buffer, size);
}
}  // namespace fnv_00484d00

struct FUN_008586a0_class
{
    void ForwardToFUN_00857b50(int a, int b, int c);
};

struct FUN_00862370_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    void* m_7c;
    void* m_80;
    void* m_84;
    void* m_88;
    int* m_8c;
    int* GetOrCreatePointer();
};

extern int DAT_01081e30;
struct FUN_00863360
{
    void* FUN_00863361(int);
};
extern int DAT_01081e50;
struct FUN_00863390_class
{
    int m;
    void FUN_008636d0(int);
    int FUN_00863390(int a);
};
// Calls FUN_008636d0 with a, stores the address of DAT_01081e50 in m, and returns this.
// @fnv 0x00863390
int FUN_00863390_class::FUN_00863390(int a)
{
    FUN_008636d0(a);
    m = (int)&DAT_01081e50;
    return (int)this;
}

struct FUN_008633f0_class
{
    void* p;
    void* FUN_008633f0(void* a);
    void FUN_008638f0(void* a);
};

extern void* DAT_01081e90;

extern int DAT_01081eb0;

struct FUN_00863420_class
{
    void* vfn_0;
    void FUN_008639f0(int a);
    FUN_00863420_class* FUN_00863420(int a);
};

// Calls FUN_008639f0 with a, sets vfn_0 to &DAT_01081eb0, and returns this.
// @fnv 0x00863420
FUN_00863420_class* FUN_00863420_class::FUN_00863420(int a)
{
    FUN_008639f0(a);
    vfn_0 = &DAT_01081eb0;
    return this;
}

extern "C" void __cdecl FUN_00863e30(int);
extern int DAT_01081ed0;

struct FUN_00863450_Class
{
    int FUN_00863e30(int);
    int InitWithGlobal(int a);
};

// Calls FUN_00863e30 with a, stores the address of DAT_01081ed0 into this, and returns this.
// @fnv 0x00863450
int FUN_00863450_Class::InitWithGlobal(int a)
{
    reinterpret_cast<::FUN_00863e30_struct *>(this)->FUN_00863e30(a);
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01081ed0);
    return reinterpret_cast<int>(this);
}

extern int DAT_01081ef8;
struct MyMap
{
};
struct FUN_008636a0 : MyMap
{
    int* vtbl;
    void* data;
    void* alias;
    void Init();
};
// @fnv 0x008636a0
void FUN_008636a0::Init()
{
    vtbl = (int*)&DAT_01081ef8;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(alias);
}

struct FUN_00863cb0_Class
{
    void FUN_00863cb0(int a, char b, int c);
};

// @fnv 0x00863cb0
void FUN_00863cb0_Class::FUN_00863cb0(int a, char b, int aiValue)
{
    ((char*)a)[4] = b;
    ((int*)a)[2] = aiValue;
}

struct FUN_00c3ea10_stub
{
};
void FUN_00c3fce0(void*);
struct IOManager
{
    void FUN_00c3fce0();
    void FUN_00c3e380();
};
namespace fnv_00858730 {
struct ChangeData
{
    void NotifyFormIDChanged(unsigned int);
    void ClearFormChangeFlags(unsigned int);
    void SetBuffer(void*);
    void* GetBuffer();
    unsigned int GetFlags();
    void SetFlags(unsigned int);
    void SetChange(unsigned int);
    void* __vecDelDtor(unsigned int);
    unsigned int iFlags;
    void* pBuffer;
};
struct FUN_00858730_shell : public TESSaveLoadGame
{
    bool FUN_00858730(TESForm*);
};

struct FUN_00485d50_slg
{
};
struct FUN_00855130_This
{
};
struct FUN_00855150_s
{
    void FUN_00855150(TESForm*, unsigned int);
};
struct FUN_008579e0_shell
{
    void FUN_008579e0(void*, unsigned int);
};
struct ATM
{
};
struct GlobalObject_0044fae0;
int FNV_GetFormType(TESForm*);
struct Fake440e30
{
};
struct FormTypeInfo_s
{
    const char* pName;
    int a;
    int b;
};
struct Flt
{
    operator unsigned int();
};
struct GridArray_s
{
};
struct SLGStub
{
    void FUN_00861ee0(unsigned char);
    void FUN_00858700(void*);
};
struct BufferHeader_s
{
    int a;
    int b;
    int c;
};
class TESSound;
struct EffectSetting
{
    void SetBoltSound(TESSound*);
};
struct FUN_004534f0_shell
{
};
struct FUN_0046a010_shell
{
};
struct FormV
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
    virtual void LoadGame(unsigned int, int);
};
struct FUN_00863e00
{
    FUN_00863e00(int, int);
    char pad[0x18];
};
struct FUN_00857280
{
    FUN_00857280(TESForm*, unsigned int, int, unsigned char);
    char pad[0x10];
};
class TESTopicInfo;
template <class T> class NiTMallocInterface;
template <class T, class A> class NiTLargeArray
{
  public:
    unsigned int Add(const T&);
};
struct TESRaceForm
{
};
struct LoadFormHeader_s
{
    unsigned short size;
    unsigned char type;
    unsigned char version;
};

// @fnv 0x00858730
bool FUN_00858730_shell::FUN_00858730(TESForm* apForm)
{
    if (!reinterpret_cast<::FUN_0047c850 *>((((FUN_00485d50_slg*)this)))->EvaluateCondition())
        return false;
    ChangeData* pchange2 = (ChangeData*)reinterpret_cast<::FUN_00855130_This *>((((FUN_00855130_This*)changes)))->FUN_00855130(apForm);
    if (pchange2)
    {
        void* ptempbuffer = reinterpret_cast<::Callees *>((((GridArray_s*)pchange2)))->FUN_00726070();
        if (ptempbuffer)
        {
            int _ibufferOverrun;
            unsigned int iflags;
            unsigned int isize;
            BufferHeader_s bufferHeader4;
            bool brestore;
            LoadFormHeader_s formHeader;

            reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_00858730::ATM *>(&::g_011de494))))->FUN_004538a0((int)"TESSaveLoadGame::LoadForm");
            this->unk14 = ptempbuffer;
            ((FUN_008579e0_shell*)::g_TESSaveLoadGame)->FUN_008579e0(&formHeader, 4);
            if (FNV_GetFormType(apForm) != formHeader.type)
            {
                char pmessageA[260];
                std::sprintf(
                    pmessageA,
                    "Load Error: Form with ID %08X was saved with form type %s, but currently has form type %s.  Its loading will be skipped.",
                    ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apForm))->FUN_0084e3a0())), (*reinterpret_cast<fnv_00858730::FormTypeInfo_s (*)[]>((void *)&::FNV_FormTypeNames))[formHeader.type].pName, ((const char *)(reinterpret_cast<::FUN_00440e30_This *>((((Fake440e30*)apForm)))->FUN_00440e30())));
                changes->HasFormChanges(apForm, true);
                this->unk14 = 0;
                reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_00858730::ATM *>(&::g_011de494))))->WaitForTasksDuringRendering();
                return false;
            }
            isize = formHeader.size;
            iflags = *(Flt*)pchange2;
            iflags = reinterpret_cast<::FUN_00859120_cls *>((((SLGStub*)this)))->ClearRefrFlag(apForm, iflags);
            ((SLGStub*)this)->FUN_00861ee0(formHeader.version);
            reinterpret_cast<::FUN_00858aa0_shell *>(&(bufferHeader4))->FUN_00858aa0((unsigned short *)(void *)(&formHeader), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apForm))->FUN_0084e3a0())), iflags);
            ((EffectSetting*)this)->SetBoltSound((TESSound*)&bufferHeader4);
            brestore = reinterpret_cast<::FUN_0047c850 *>((((FUN_00485d50_slg*)this)))->EvaluateCondition();
            reinterpret_cast<::FUN_004534f0_shell *>((((FUN_004534f0_shell*)this)))->FUN_004534f0(1);
            reinterpret_cast<::FUN_0046a010_shell *>((((FUN_0046a010_shell*)apForm)))->FUN_0046a010(true);
            reinterpret_cast<::s85ac30::RefLoader *>((((SLGStub*)this)))->LoadChange(apForm, iflags);
            ((FormV*)apForm)->LoadGame(iflags, 0);
            reinterpret_cast<::FUN_004534f0_shell *>((((FUN_004534f0_shell*)this)))->FUN_004534f0(brestore);
            ((EffectSetting*)this)->SetBoltSound(0);
            ::CopyByteToOffset80((char*)this);
            if (this->unk20 == 0)
                *(FUN_00863e00**)&this->unk20 = new FUN_00863e00(0x32, 0x32);
            reinterpret_cast<::S00863d90 *>(((*(NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >**)&this->unk20)))->FUN_00863d90((const unsigned int &)((const ::fnv_00858730::TESTopicInfo *const &)((TESTopicInfo*)new FUN_00857280(apForm, iflags, 0, formHeader.version))));
            _ibufferOverrun = *(char**)&this->unk14 - ((char*)ptempbuffer + isize + 4);
            reinterpret_cast<::fnv_00858700::FUN_00858700 *>((((SLGStub*)this)))->DoIt(ptempbuffer);
            reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)pchange2)))->Initialize((::CombatController *)(0));
            if (*(unsigned int*)((char*)this + 0x54))
            {
                ((FUN_00855150_s*)changes)->FUN_00855150(apForm, *(unsigned int*)((char*)this + 0x54));
                *(unsigned int*)((char*)this + 0x54) = 0;
            }
            reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_00858730::ATM *>(&::g_011de494))))->WaitForTasksDuringRendering();
            return true;
        }
    }
    return false;
}
}  // namespace fnv_00858730

extern int DAT_01081e70;
struct S8633
{
    void FUN_008637d0(int);
    S8633* FUN_008633c0(int);
};
// Calls FUN_008637d0 with a, sets the object's vtable pointer to DAT_01081e70, and returns this.
// @fnv 0x008633c0
S8633* S8633::FUN_008633c0(int a)
{
    FUN_008637d0(a);
    *(void**)this = (void*)&DAT_01081e70;
    return this;
}

extern int DAT_01081ef0;
struct BaseStub
{
};
struct FUN_008635a0 : BaseStub
{
    FUN_008635a0(unsigned int, unsigned int);
};
// @fnv 0x008635a0
FUN_008635a0::FUN_008635a0(unsigned int a, unsigned int b)
{
    new ((void *)this) ::FUN_00864160(a, b);
    *(void**)this = (void*)&DAT_01081ef0;
}

namespace fnv_008637a0 {
struct MyMap
{
    void FUN_008637a0();
};
// @fnv 0x008637a0
void MyMap::FUN_008637a0()
{
    *(void**)this = (void*)&::fnv_008636d0::DAT_01081f18;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)((char*)this + 8));
}
}  // namespace fnv_008637a0

namespace fnv_008638c0 {
struct MyMap
{
    int m0;
    int m4;
};
struct Holder : MyMap
{
    void* m8;
    void FUN_008638c0();
};
// @fnv 0x008638c0
void Holder::FUN_008638c0()
{
    *(int*)this = (int)&::fnv_008637d0::DAT_01081f38;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(m8);
}
}  // namespace fnv_008638c0

namespace fnv_008639c0 {
struct MyMap
{
    int _0;
};
struct Holder : public MyMap
{
    void* _4;
    void* _8;
    void FUN_008639c0();
};
// @fnv 0x008639c0
void Holder::FUN_008639c0()
{
    *(void**)this = (void*)&::DAT_01081f58;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(_8);
}
}  // namespace fnv_008639c0

namespace fnv_00855660 {
struct FUN_00863420_class
{
    void* m_pVirtualFunctionTable;
    char m[0xc];
    FUN_00863420_class(int);
};
struct SL
{
    void* m_pObject;
    char m[4];
    SL();
};
struct FUN_00855660
{
    FUN_00863420_class* m_pVirtualFunctionTable;
    SL* m_pObject;
    FUN_00855660();
};

// Allocates a FUN_00863420_class with argument 0x25 and an SL, storing both in the object's fields.
// @fnv 0x00855660
FUN_00855660::FUN_00855660()
{
    m_pVirtualFunctionTable = new FUN_00863420_class(0x25);
    m_pObject = new SL;
}
}  // namespace fnv_00855660

struct AutoMemHelper
{
    int m_uiLogicalSize;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct ContainerItemExtra
{
    int m_iExtraID;
    char* m_pString;
};
struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
struct G2
{
    void AddHead(int*);
};
struct FUN_008558a0
{
    void SetExtraDataString(int iExtraID, const char* pString);
};
// @fnv 0x008558a0
void FUN_008558a0::SetExtraDataString(int iExtraID, const char* pString)
{
    AutoMemHelper kHelper4(17, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSaveLoadGame.cpp",
                           615);
    ContainerItemExtra* pExtra;
    unsigned int uiSize;
    pExtra = new ContainerItemExtra;
    pExtra->m_iExtraID = iExtraID;
    uiSize = ::FUN_0044a670(pString) + 1;
    pExtra->m_pString = static_cast<char*>(::FUN_00401000(uiSize));
    TaskQueueInterface::CopyStringToBuffer(pExtra->m_pString, uiSize, pString);
    ((G2*)*(int**)((char*)this + 4))->AddHead((int*)&pExtra);
}

struct MobileObject
{
};
struct FUN_00857bd0
{
    void Init(unsigned int);
};
struct FUN_00857aa0 : FUN_00857bd0
{
    unsigned int FUN_00861c00(unsigned int);
    bool ValidateFormIDArray(unsigned int* apFormID, unsigned int aiSize);
};
namespace fnv_00858570 {
struct FUN_008558a0_class
{
    void FUN_008558a0(void*, const char*);
};
struct FUN_008586a0_class
{
    void FUN_00857b50(int, void**, int);
};
struct FUN_00858600_class
{
    void* FUN_00858600(void*);
};
struct FUN_00858700_class
{
    void FUN_00858700(void*);
};
struct FUN_009755b0_class
{
};
struct FUN_009756c0_class
{
};
struct FUN_00858570_class
{
    void LoadTempEffectsList(int apFile);
};
// @fnv 0x00858570
void FUN_00858570_class::LoadTempEffectsList(int apFile)
{
    void* ptempBuffer = ((void *)(reinterpret_cast<::SaveProcessLists *>((((FUN_009755b0_class*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_009755b0()));
    ((FUN_008586a0_class*)this)->FUN_00857b50(apFile, &ptempBuffer, 4);
    if (ptempBuffer)
    {
        if (*(void**)((char*)this + 0x44))
            reinterpret_cast<::FUN_008558a0 *>((((FUN_008558a0_class*)*(void**)((char*)this + 0x44))))->SetExtraDataString((int)(ptempBuffer), "Temp Effects List");
        void* ptempBuffer2 = ((FUN_00858600_class*)this)->FUN_00858600(ptempBuffer);
        reinterpret_cast<::PLTempEffectSaver *>((((FUN_009756c0_class*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->SaveTempEffects();
        reinterpret_cast<::FUN_008586a0_class *>((((FUN_008586a0_class*)this)))->ForwardToFUN_00857b50(apFile, (int)(ptempBuffer2), (int)ptempBuffer);
        reinterpret_cast<::fnv_00858700::FUN_00858700 *>((((FUN_00858700_class*)this)))->DoIt(ptempBuffer2);
    }
}
}  // namespace fnv_00858570

struct PlayerCharacter
{
};
struct FUN_008616f0_shell
{
    bool FUN_008616f0();
};
// @fnv 0x008616f0
bool FUN_008616f0_shell::FUN_008616f0()
{
    if (reinterpret_cast<::FUN_004f8960_shell *>((::_g_thePlayer))->FUN_004f8960() == 2 || reinterpret_cast<::FUN_004f8960_shell *>((::_g_thePlayer))->FUN_004f8960() == 1)
        return false;
    if (::FUN_0093a740((::FUN_0093a740_s *)(::_g_thePlayer)))
        return false;
    if (((bool)(::IsStartMenuFlag1Set())))
        return true;
    int emenuEnum = ::fnv_007023c0::FUN_007023c0();
    if (emenuEnum != 0 && emenuEnum != 3)
        return false;
    emenuEnum = ::fnv_00702640::FUN_00702640();
    if (emenuEnum != 0 && emenuEnum != 3)
        return false;
    return true;
}

namespace fnv_00861780 {
struct DataHandler
{
};
struct LH
{
};
struct G2
{
    void AddHead(int*);
};

struct FUN_00861780_StandIn
{
    void Add(TESForm* form);
};

// Warns if form is null or not created, otherwise adds its form ID to the list at offset 0x2c if not already present.
// @fnv 0x00861780
void FUN_00861780_StandIn::Add(TESForm* form)
{
    if (form == 0)
    {
        ::FUN_005b5e40();
    }
    else if (!reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::fnv_00861780::DataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0()))))
    {
        ::FUN_005b5e40();
    }
    else
    {
        int id = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0()));
        if (!reinterpret_cast<::RefList *>((((LH*)((char*)this + 0x2c))))->FUN_005f65d0((void **)&(id)))
        {
            int iFormIDToAdd = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0()));
            ((G2*)((char*)this + 0x2c))->AddHead(&iFormIDToAdd);
        }
    }
}
}  // namespace fnv_00861780

struct FUN_00862430_vec
{
    float x, y, z;
};
struct FUN_00862430_cls
{
    bool HasInvalidComponents(FUN_00862430_vec* v);
};
// Returns true if any component of v is non-finite or NaN, otherwise false.
// @fnv 0x00862430
bool FUN_00862430_cls::HasInvalidComponents(FUN_00862430_vec* pVec)
{
    if (!std::isfinite(pVec->x) || !std::isfinite(pVec->y) || !std::isfinite(pVec->z) || std::isnan(pVec->x) ||
        std::isnan(pVec->y) || std::isnan(pVec->z))
        return true;
    return false;
}

namespace fnv_008632a0 {

struct TESTopicInfo;

template <class T> struct NiTMallocInterface;

template <class T, class A> class NiTLargeArray
{
  public:
    unsigned int Add(T&);
};

struct NiTLargePrimitiveArray
{
    char data[0x18];
    NiTLargePrimitiveArray(unsigned int, unsigned int);
    ~NiTLargePrimitiveArray();
};

struct FUN_008632a0_slg : TESSaveLoadGame
{
    void AddLoadingTopic(TESTopicInfo*);
};

// When loading, lazily creates the topic array at this+0xb0 and adds pTopic to it.
// @fnv 0x008632a0
void FUN_008632a0_slg::AddLoadingTopic(TESTopicInfo* pTopic)
{
    if (!reinterpret_cast<::FUN_0047c850 *>(this)->EvaluateCondition())
        return;
    if (!*((NiTLargePrimitiveArray**)((char*)this + 0xb0)))
        *((NiTLargePrimitiveArray**)((char*)this + 0xb0)) = new NiTLargePrimitiveArray(0x4e20, 0x7d0);
    reinterpret_cast<::S00863d90 *>((((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)*(
         (NiTLargePrimitiveArray**)((char*)this + 0xb0)))))->FUN_00863d90((const unsigned int &)(pTopic));
}
}  // namespace fnv_008632a0

struct BSFile
{
public:
    void Close();
};
struct FUN_00857b50_slg : TESSaveLoadGame
{
    int FUN_00857b50(BSFile*, const char*, unsigned int);
};
// Calls FUN_00857b50 with the three integer arguments a, b and c.
// @fnv 0x008586a0
void FUN_008586a0_class::ForwardToFUN_00857b50(int a, int b, int c)
{
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(a), (const char *)(b), c);
}

// @fnv 0x00857b50
int FUN_00857b50_slg::FUN_00857b50(BSFile* file, const char* name, unsigned int size)
{
    if (reinterpret_cast<::FUN_0047c850 *>(this)->EvaluateCondition())
    {
        *(unsigned int*)((char*)this + 0x94) += size;
        return size;
    }
    int result = ((int)(reinterpret_cast<::FUN_00473180_shell *>((file))->FUN_00473180((void *)(name), size)));
    return result;
}

struct DataHandler
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_00861c00
{
    unsigned int GetID(unsigned int id);
};
// Copies aiSize bytes from the object's buffer into apFormID, remaps each form ID when talking, calls Init, and returns whether any nonzero ID became zero.
// @fnv 0x00857aa0
bool FUN_00857aa0::ValidateFormIDArray(unsigned int* apFormID, unsigned int aiSize)
{
    bool bforcedToZero = false;
    __memcpy(apFormID, *(void**)((char*)this + 0x14), aiSize);
    if (((bool)(::FUN_00574900((const unsigned char *)(reinterpret_cast<MobileObject*>(this))))))
    {
        unsigned int icount = aiSize / 4;
        for (unsigned int i = 0; i < icount; ++i)
        {
            unsigned int iformID = reinterpret_cast<::FUN_00861c00 *>(this)->GetID(apFormID[i]);
            if (apFormID[i] != 0 && iformID == 0)
                bforcedToZero = true;
            apFormID[i] = iformID;
        }
    }
    Init(aiSize);
    return bforcedToZero;
}
// @fnv 0x00861c00
unsigned int FUN_00861c00::GetID(unsigned int id)
{
    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(id))
        return id;
    if (id > ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)(*(void**)((char*)this + 0x78)))))->FUN_0084e3a0())))
        return 0;
    unsigned int result = *((Arr*)(*(void**)((char*)this + 0x78)))->GetAt(id);
    return result;
}

namespace fnv_00861cd0 {
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_00861cd0Class
{
    unsigned int FUN_00861cd0(unsigned short index);
};

// Returns 0 if index exceeds the form ID at this+0x7c, otherwise returns the element at index from the array at this+0x7c.
// @fnv 0x00861cd0
unsigned int FUN_00861cd0Class::FUN_00861cd0(unsigned short index)
{
    if (index > ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)(*(unsigned int*)((char*)this + 0x7c)))))->FUN_0084e3a0())))
        return 0;
    unsigned int result = *((Arr*)(*(unsigned int*)((char*)this + 0x7c)))->GetAt(index);
    return result;
}
}  // namespace fnv_00861cd0

extern int DAT_01081ef8;

struct FUN_008635d0_t
{
    void* m_pVTable;
    int m_iArrayLength;
    void* m_pData;
    int m_iDummy;
    FUN_008635d0_t(int iCount);
};
// Calls FUN_008635d0 with a, stores the address of DAT_01081e30 at this, and returns this.
// @fnv 0x00863360
void* FUN_00863360::FUN_00863361(int a)
{
    new ((void *)this) ::FUN_008635d0_t(a);
    *reinterpret_cast<void**>(this) = &DAT_01081e30;
    return this;
}

// Sets the vtable, stores iCount, allocates iCount*4 bytes and zeroes them into m_pData.
// @fnv 0x008635d0
FUN_008635d0_t::FUN_008635d0_t(int iCount)
{
    m_pVTable = &DAT_01081ef8;
    m_iArrayLength = iCount;
    m_iDummy = 0;
    unsigned int uiSize = m_iArrayLength * 4;
    m_pData = ::FUN_00aa1070(uiSize);
    ::FUN_00403d30(m_pData, 0, m_iArrayLength * 4);
}

namespace fnv_00863640 {
struct MyMap
{
    virtual ~MyMap();
};
struct FUN_008636a0
{
    ~FUN_008636a0();
};
struct FUN_00863640 : public MyMap
{
    virtual ~FUN_00863640();
};
// Destructor that calls RemoveAll to clear the map's contents.
// @fnv 0x00863640
FUN_00863640::~FUN_00863640()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}
}  // namespace fnv_00863640

namespace fnv_008636d0 {

struct FUN_008636d0
{
    int* vtbl;
    int count;
    void* data;
    int pad;
    FUN_008636d0(int n);
};

// Sets the vtable, stores the element count, allocates count*4 bytes and zero-fills them.
// @fnv 0x008636d0
FUN_008636d0::FUN_008636d0(int aiCount)
{
    vtbl = &DAT_01081f18;
    count = aiCount;
    pad = 0;
    unsigned int size = count << 2;
    data = ::FUN_00aa1070(size);
    ::FUN_00403d30(data, 0, count << 2);
}
}  // namespace fnv_008636d0

namespace fnv_008637d0 {
struct FUN_008637d0
{
    void** vtbl;
    unsigned int count;
    void* buf;
    unsigned int m;
    FUN_008637d0(unsigned int n);
};
// Sets the vtable, stores the count, allocates count*4 bytes, and zeroes the buffer.
// @fnv 0x008637d0
FUN_008637d0::FUN_008637d0(unsigned int auiCount)
{
    vtbl = (void**)&DAT_01081f38;
    count = auiCount;
    m = 0;
    unsigned int uiSize = count << 2;
    buf = ::FUN_00aa1070(uiSize);
    ::FUN_00403d30(buf, 0, count << 2);
}
}  // namespace fnv_008637d0

namespace fnv_00863860 {
extern int DAT_01081e70;
struct MyMap
{
};
struct FUN_008638c0_Class
{
    virtual ~FUN_008638c0_Class();
};
struct FUN_00863860 : FUN_008638c0_Class
{
    virtual ~FUN_00863860();
};
// Destructor that calls RemoveAll on the map stored at the start of the object.
// @fnv 0x00863860
FUN_00863860::~FUN_00863860()
{
    reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)this)))->FUN_00438af0();
}
}  // namespace fnv_00863860


struct FUN_008638f0
{
    void* m_pVTable;
    unsigned int m_uiSize;
    void* m_pData;
    unsigned int m_uiCount;
    FUN_008638f0(unsigned int uiSize);
};
// Calls FUN_008638f0 on a, sets p to the address of DAT_01081e90, and returns this.
// @fnv 0x008633f0
void* FUN_008633f0_class::FUN_008633f0(void* apArg)
{
    new ((void *)this) ::FUN_008638f0((unsigned int)(apArg));
    p = &DAT_01081e90;
    return this;
}

// Sets the vtable, stores uiSize, allocates uiSize*4 bytes for m_pData, zeroes them, and sets m_uiCount to 0.
// @fnv 0x008638f0
FUN_008638f0::FUN_008638f0(unsigned int uiSize)
{
    m_pVTable = &DAT_01081f58;
    m_uiSize = uiSize;
    m_uiCount = 0;
    unsigned int uiBytes = m_uiSize * 4;
    m_pData = ::FUN_00aa1070(uiBytes);
    ::FUN_00403d30(m_pData, 0, m_uiSize * 4);
}

namespace fnv_008639f0 {
struct FUN_008639f0
{
    void* pVTable;
    unsigned int ItemUpdateArray;
    void* pBuffer;
    void* pElement0;
    FUN_008639f0(unsigned int);
};
// Sets the vtable, stores count, allocates count*4 bytes, and zeroes the buffer.
// @fnv 0x008639f0
FUN_008639f0::FUN_008639f0(unsigned int count)
{
    unsigned int uiSize;
    pVTable = &::DAT_01081f78;
    ItemUpdateArray = count;
    pElement0 = 0;
    uiSize = ItemUpdateArray * 4;
    pBuffer = ::FUN_00aa1070(uiSize);
    ::FUN_00403d30(pBuffer, 0, ItemUpdateArray * 4);
}
}  // namespace fnv_008639f0

struct FUN_00c3e860_t
{
    int SumArrayUpToCount(unsigned int);
};
// Sums the int array at this+0x54 from index 0 through count inclusive and returns the total.
// @fnv 0x00c3e860
int FUN_00c3e860_t::SumArrayUpToCount(unsigned int count)
{
    int total = 0;
    for (unsigned int i = 0; i <= count; ++i)
        total = (*(int**)((char*)this + 0x54))[i] + total;
    return total;
}

struct FUN_00854ed0_standin
{
    void* FUN_00854ed0(unsigned int flags);
};


struct FUN_00854e10
{
    void FUN_00854e10_();
    void* FUN_00854fe0(unsigned int flags);
};
// @fnv 0x00855220
bool FUN_00855220_shell::FUN_00855220(unsigned int aiFormID, bool abForceRemove)
{
    Chg00855220* pchange;
    if (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
        return false;
    pchange = (Chg00855220*)((TESSaveLoadGame*)this)->QueueRemoveReferenceChange(aiFormID);
    if (pchange)
    {
        if (pchange->b == 0 || abForceRemove)
        {
            reinterpret_cast<::NiTMap_S *>((((RemoveAtHelper00855220*)this)))->RemoveKey(aiFormID);
            Chg00855220* t1 = pchange;
            Chg00855220* t2 = t1;
            t2 ? reinterpret_cast<::FUN_00854e10 *>((t2))->FUN_00854fe0(1) : 0;
        }
        return true;
    }
    return false;
}


// @fnv 0x00854fe0
void* FUN_00854e10::FUN_00854fe0(unsigned int flags)
{
    FUN_00854e10_();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct ExteriorCellNewReferencesMap
{
    void FUN_00855440();
    void* FUN_00855410(unsigned int flags);
};


struct NumericIDBufferMap
{
    void* FUN_00855580(unsigned int flags);
};


struct BaseS
{
    BaseS();
    char m_ucUnknownByte[12];
};

struct FUN_008572f0
{
    FUN_008572f0();
};

struct FUN_00857320
{
    int m_uiFilterValue;
    BaseS m_base;
    FUN_008572f0 m_kMemberDescriptor;

    FUN_00857320();
};

// @fnv 0x00857320
FUN_00857320::FUN_00857320() : m_uiFilterValue(0), m_base(), m_kMemberDescriptor()
{}

namespace fnv_008578b0 {
struct RefList
{
};

struct BSFile
{
    virtual ~BSFile();
};

struct FUN_008578b0_Class
{
    char padding[0x70];
    RefList* pRefList;

    void ReleaseFile(BSFile* file, int type);
};

// @fnv 0x008578b0
void FUN_008578b0_Class::ReleaseFile(BSFile* file, int type)
{
    if (!file)
        return;

    switch (type)
    {
    case 0:
    case 1:
    case 3:
        if (pRefList)
        {
            int value = reinterpret_cast<int>(file);
            reinterpret_cast<::ItemChangeListNode *>((pRefList))->FUN_00905330((::InventoryStackRecord *const &)(value));
        }
        delete file;
        break;

    case 2:
        reinterpret_cast<::BSFile *>((file))->Close();
        break;
    }
}
}  // namespace fnv_008578b0

namespace fnv_anon_00858480 {}
using namespace fnv_anon_00858480;
namespace fnv_anon_00858480 {
class BSFile
{
};

class TESGlobal : public TESForm
{
  public:
};

class BSSimpleListTESRaceSize
{
  public:
    int GetSize();
};

class GlobalListNode : public BSSimpleListTESRaceSize
{
  public:
};

class TESDataHandler
{
  public:
};

class EmptyClass
{
};

class FUN_008558a0
{
  public:
};

class FUN_008586a0_class
{
  public:
};

class TESSaveLoadGame
{
  public:
    void* FUN_00858600(unsigned int);
    void FUN_00858700(void*);
    void FUN_00857a10(int, int);
    void FUN_00858480(BSFile*);
};


// @fnv 0x00858480
void TESSaveLoadGame::FUN_00858480(BSFile* apFile)
{
    GlobalListNode* pglobals4;
    unsigned short icount3;
    unsigned short isize9;
    void* ptempBuffer2;

    pglobals4 = ((::fnv_anon_00858480::GlobalListNode *)(::FUN_00461190((int)((*reinterpret_cast<::fnv_anon_00858480::TESDataHandler * *>(&::g_dataHandler))))));
    icount3 = static_cast<unsigned short>(pglobals4->GetSize());
    isize9 = static_cast<unsigned short>(icount3 * 8 + 2);

    ptempBuffer2 = this->FUN_00858600(isize9);
    reinterpret_cast<::FUN_008579b0_shell *>((this))->FUN_008579b0(&icount3, 2);

    while (pglobals4)
    {
        {
            TESGlobal* pglobal;
            unsigned int iglobalID2;
            float fvalue6;

            pglobal = *((::fnv_anon_00858480::TESGlobal **)(new ((void *)(pglobals4)) ::Vec3()));
            if (pglobal)
            {
                iglobalID2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pglobal))->FUN_0084e3a0()));
                fvalue6 = reinterpret_cast<::FUN_00526ac0_shell *>((pglobal))->FUN_00526ac0();
                this->FUN_00857a10(reinterpret_cast<int>(&iglobalID2), 4);
                reinterpret_cast<::FUN_008579b0_shell *>((this))->FUN_008579b0(&fvalue6, 4);
            }
        }
        pglobals4 = ((::fnv_anon_00858480::GlobalListNode *)(reinterpret_cast<::Callees *>((pglobals4))->FUN_00726070()));
    }

    reinterpret_cast<::FUN_008586a0_class *>((reinterpret_cast<FUN_008586a0_class*>(this)))->ForwardToFUN_00857b50(reinterpret_cast<int>(apFile),
                                                                       reinterpret_cast<int>(ptempBuffer2), isize9);

    reinterpret_cast<::fnv_00858700::FUN_00858700 *>((this))->DoIt(ptempBuffer2);

    if (*reinterpret_cast<EmptyClass**>(reinterpret_cast<unsigned char*>(this) + 0x44))
    {
        reinterpret_cast<::FUN_008558a0 *>((reinterpret_cast<FUN_008558a0*>(*reinterpret_cast<EmptyClass**>(reinterpret_cast<unsigned char*>(this) + 0x44))))->SetExtraDataString(isize9, "Global Variables");
    }
}
}

namespace fnv_0085a3d0 {
class G2
{
  public:
    void AddHead(int*);
};

class LH
{
  public:
};

class TESSaveLoadGameStandIn
{
  public:
    void AddFormToList(TESForm* apForm);
};

// If apForm is not already in the list at offset 0x34, adds it to the head of that list.
// @fnv 0x0085a3d0
void TESSaveLoadGameStandIn::AddFormToList(TESForm* apForm)
{
    if (!reinterpret_cast<::RefList *>((reinterpret_cast<LH*>(reinterpret_cast<char*>(this) + 0x34)))->FUN_005f65d0((void **)&(reinterpret_cast<int&>(apForm))))
    {
        reinterpret_cast<G2*>(reinterpret_cast<char*>(this) + 0x34)->AddHead(reinterpret_cast<int*>(&apForm));
    }
}
}  // namespace fnv_0085a3d0

namespace fnv_00861d10 {
class BSFile
{
};

class Arr : public TESForm
{
  public:
    unsigned int* GetAt(int);
};

class FUN_008558a0
{
  public:
};

class FUN_008586a0_class
{
  public:
};


class TESSaveLoadGame_standin : public FUN_008586a0_class
{
  public:
    char padding_00[0x44];
    FUN_008558a0* m_pSaveGameEntry;
    char padding_48[0x30];
    Arr* m_pLoadingFormRecordHeader;
    Arr* m_pSavingFormIDEntry;

    void WriteFormIDArrays(BSFile*);
};

// @fnv 0x00861d10
void TESSaveLoadGame_standin::WriteFormIDArrays(BSFile* apFile)
{
    unsigned int isize;
    unsigned int uiCount2;

    isize = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pLoadingFormRecordHeader))->FUN_0084e3a0()));
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(reinterpret_cast<int>(apFile)), (const char *)(reinterpret_cast<int>(&isize)), 4);

    {
        unsigned int i;

        for (i = 0; i < isize; ++i)
        {
            unsigned int iformID;

            iformID = *m_pLoadingFormRecordHeader->GetAt(i);
            reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(reinterpret_cast<int>(apFile)), (const char *)(reinterpret_cast<int>(&iformID)), 4);
        }
    }

    uiCount2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pSavingFormIDEntry))->FUN_0084e3a0()));
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(reinterpret_cast<int>(apFile)), (const char *)(reinterpret_cast<int>(&uiCount2)), 4);

    {
        unsigned int i;

        for (i = 0; i < uiCount2; ++i)
        {
            unsigned int iformID;

            iformID = *m_pSavingFormIDEntry->GetAt(i);
            reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(reinterpret_cast<int>(apFile)), (const char *)(reinterpret_cast<int>(&iformID)), 4);
        }
    }

    {
        char acBuffer[260];

        if (m_pSaveGameEntry)
        {
            (::FUN_00406d00)(acBuffer, 0x104, "Numeric ID Array(%i)", isize);
            reinterpret_cast<::FUN_008558a0 *>((m_pSaveGameEntry))->SetExtraDataString(isize * 4 + 4, acBuffer);

            (::FUN_00406d00)(acBuffer, 0x104, "WorldSpace ID Array(%i)", uiCount2);
            reinterpret_cast<::FUN_008558a0 *>((m_pSaveGameEntry))->SetExtraDataString(uiCount2 * 4 + 4, acBuffer);
        }
    }
}
}  // namespace fnv_00861d10

struct TES
{
};

struct Interface
{
    static bool __cdecl IsGamePaused();
};

struct LLD_TESHelper
{
    void FUN_00861ea0();
};

extern unsigned int DAT_011de464;


// @fnv 0x00861ea0
void LLD_TESHelper::FUN_00861ea0()
{
    if (GetTickCount() > DAT_011de464 + 0xbb8)
    {
        if (!Interface::IsGamePaused())
        {
            reinterpret_cast<::S457d70 *>((reinterpret_cast<TES*>(g_TES)))->FUN_00457d70(1, (::Form457 *)(0), 0);
        }
    }
}

namespace fnv_00862150 {
struct FUN_00862150File
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual const char* GetPath() = 0;
};

struct FUN_00862150StandIn
{
    char padding[0x1C4];
    char* queuedWeaponPath;

    void FUN_00862150(FUN_00862150File* file);
};


class TaskQueueInterface
{
  public:
};

// @fnv 0x00862150
void FUN_00862150StandIn::FUN_00862150(FUN_00862150File* file)
{
    if (queuedWeaponPath)
    {
        ::FUN_00401030(queuedWeaponPath);
        queuedWeaponPath = 0;
    }

    if (file != 0)
    {
        if (::FUN_008905f0(reinterpret_cast<bool*>(file)) != 0)
        {
            const char* currentPath = file->GetPath();
            char* found = ::FUN_004812f0(currentPath, "\\");

            while (found)
            {
                currentPath = found + 1;
                found = ::FUN_004812f0(currentPath, "\\");
            }

            char queuedName[260];
            ::TaskQueueInterface::CopyStringToBuffer(queuedName, 260, currentPath);

            int queuedNameLength = ((int)(::FUN_0044a670(queuedName)));
            queuedName[queuedNameLength - 4] = 0;

            int allocationSize = ((int)(::FUN_0044a670(queuedName))) + 1;
            queuedWeaponPath = static_cast<char*>(::FUN_00401000(allocationSize));

            ::TaskQueueInterface::CopyStringToBuffer(queuedWeaponPath, allocationSize, queuedName);
        }
    }
}
}  // namespace fnv_00862150

struct FUN_00863510Class
{
    void FUN_00863960();
    void* FUN_00863510(unsigned int flags);
};


// Calls FUN_00863960, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00863510
void* FUN_00863510Class::FUN_00863510(unsigned int flags)
{
    FUN_00863960();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00863ea0_StandIn
{
    void FUN_00863ea0();
};

struct FUN_00863570_StandIn : public FUN_00863ea0_StandIn
{
    void* FUN_00863570(unsigned int flags);
};


struct FUN_00c41330_holder
{
};

struct FUN_00c3ea10_holder
{
    void FUN_00c3ea10();
};
// @fnv 0x00c3e380
void IOManager::FUN_00c3e380()
{
    reinterpret_cast<::S00c3fce0_cls *>(this)->FUN_00c3fce0();
    reinterpret_cast<::FUN_00c3ea10_holder *>((((FUN_00c3ea10_stub**)((char*)this + 0x64))[0]))->FUN_00c3ea10();
}

class FUN_00854f00_base
{
  public:
    virtual ~FUN_00854f00_base();
};

class FUN_00854f00_cls : public FUN_00854f00_base
{
  public:
    virtual ~FUN_00854f00_cls();
};
// @fnv 0x00854ed0
void* FUN_00854ed0_standin::FUN_00854ed0(unsigned int flags)
{
    reinterpret_cast<::FUN_00854f00_cls *>(this)->FUN_00854f00_cls::~FUN_00854f00_cls();

    if (flags & 1)
        ::FUN_00401030(this);

    return this;
}

struct Form_00855010
{
};
struct Guard_00855010
{
    int unk00;
    Guard_00855010(int a, int b, const char* file, int line);
    ~Guard_00855010();
};
struct Node_00855010
{
    unsigned int unk00;
    unsigned int unk04;
    Node_00855010();
};
struct FUN_00855010_cls
{
    void* GetOrCreateNode(void* a1, unsigned int a2);
};

Guard_00855010::Guard_00855010(int a, int b, const char* file, int line)
{}
Guard_00855010::~Guard_00855010()
{}
Node_00855010::Node_00855010()
{}

// Looks up a node for the form via FUN_00853130, creates and registers one if missing, then calls FUN_00854e40 with a2 and returns it.
// @fnv 0x00855010
void* FUN_00855010_cls::GetOrCreateNode(void* pForm, unsigned int uiValue)
{
    void* out = ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<Form_00855010*>(pForm)))->FUN_0084e3a0()));
    Node_00855010* r1;
    {
        bool found = reinterpret_cast<::fnv_00853130::NiTMapBase *>(this)->FUN_00853130((unsigned int)(out), (*(::fnv_00853130::CombatThreatRecord * *)(&r1)));
        if (!found)
        {
            Guard_00855010 g(0x11, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSaveLoadGame.cpp",
                             0x104);
            r1 = new Node_00855010;
            reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700((unsigned int)(out), (unsigned int)(r1));
        }
    }
    reinterpret_cast<::FUN_00854e40_Class *>((r1))->FUN_00854e40(uiValue);
    return r1;
}

struct Cell00855310
{
};

struct Base00855310
{
    virtual ~Base00855310();
};

struct FUN_00855310_cls : Base00855310
{
    virtual ~FUN_00855310_cls();
};
// Calls FUN_00855310, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008552e0
void* InteriorCellNewReferencesMap::FUN_008552e0(unsigned int flags)
{
    reinterpret_cast<::FUN_00855310_cls *>(this)->FUN_00855310_cls::~FUN_00855310_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00855310
FUN_00855310_cls::~FUN_00855310_cls()
{
    void* node7;
    unsigned int b8;
    Cell00855310* c3;

    node7 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (node7 != 0)
    {
        c3 = 0;
        b8 = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)(void **)(&node7), &b8, (void **)(::Cell00855310 **)(&c3));
        if (c3 != 0)
        {
            reinterpret_cast<::FileMatchList *>((c3))->RemoveAll();
            Cell00855310* t = c3;
            Cell00855310* u = t;
            (u != 0) ? ((unsigned int)(reinterpret_cast<::W004702f0 *>((u))->FUN_004702f0(1))) : 0;
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct ScopeLock_855970
{
    unsigned int m_unk00;
    ScopeLock_855970(int a, int b, const char* file, int line);
    ~ScopeLock_855970();
};

struct Key_855970
{
    Key_855970();
    unsigned int unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned short unk0a;
};

struct Owner_855970
{
};

struct FUN_00855970_cls
{
    Owner_855970 owner;
    void ApplyKeyWithFlags(Key_855970* src, unsigned short flags);
};

struct SubObj572
{
    void FUN_008572f0();
};

struct FUN_008572c0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    SubObj572 m_08;
    FUN_008572c0_cls* FUN_008572c0();
};

class B8572F0Member
{
  public:
    B8572F0Member();

    int unk00;
    int unk04;
    int unk08;
};

class FUN_008572f0_cls
{
  public:
    FUN_008572f0_cls();

    int m_iArrayLength;
    B8572F0Member m_kFirst;
    B8572F0Member m_kSecond;
};
// Clears m_00 and m_04 to zero, calls FUN_008572f0 on m_08, and returns this.
// @fnv 0x008572c0
FUN_008572c0_cls* FUN_008572c0_cls::FUN_008572c0()
{
    m_00 = 0;
    m_04 = 0;
    new ((void *)&(m_08)) ::FUN_008572f0_cls();
    return this;
}

// @fnv 0x008572f0
FUN_008572f0_cls::FUN_008572f0_cls() : m_iArrayLength(0)
{}

class C857370
{
  public:
};
class C8578b0
{
  public:
};
class C857950
{
  public:
    void FUN_00857950(int* a, int b);
};


extern int DAT_01183028;
extern "C" int __cdecl FUN_00ec43fb(unsigned int a, unsigned int b, void* c, void* d, unsigned int e);

struct FUN_0085a450_cls
{
    int FUN_0085a450(unsigned int a1, unsigned int a2);
};

// Calls FUN_00ec43fb twice with DAT_01183028 and DAT_011841cc/DAT_01183fb4, then returns a code derived from a2 and the results.
// @fnv 0x0085a450
int FUN_0085a450_cls::FUN_0085a450(unsigned int a1, unsigned int auiFlags)
{
    int r1 = FUN_00ec43fb(a1, 0, &DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_011841cc)), 0);
    if (r1 == 0)
    {
        int r2 = FUN_00ec43fb(a1, 0, &DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_01183fb4)), 0);
        if (r2 != 0)
        {
            if ((auiFlags & 0) != 0)
                return 4;
            else
            {
                if ((auiFlags & 0) != 0)
                    return 6;
                else
                    return 0;
            }
        }
    }
    if (r1 != 0)
    {
        if ((auiFlags & 0) != 0)
            return 0x24;
        if ((auiFlags & 6) != 0)
        {
            if ((auiFlags & 0) != 0)
                return 0x2c;
            else
                return 0x1c;
        }
        if ((auiFlags & 0) != 0)
            return 4;
    }
    return 0;
}

struct FUN_0085b240_ref
{
};
struct FUN_0085b240_node
{
};
struct FUN_0085b240_att
{
};
struct FUN_0085b240_mgr
{
};

struct FUN_0085b240_cls
{
    unsigned int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c, m_40;
    int m_44;
    void WritePluginList(FUN_0085b240_ref* a1);
};

// @fnv 0x0085b240
void FUN_0085b240_cls::WritePluginList(FUN_0085b240_ref* a1)
{
    unsigned char i;
    unsigned char flag9 = ((unsigned char)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::FUN_0085b240_mgr * *>(&::g_dataHandler))))->GetCompiledFileCount()));
    int iStartPos = 0;
    unsigned char flagA;
    if (this->m_44 != 0)
    {
        iStartPos = ::FUN_004720a0((char *)(a1));
    }
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(a1), (const char *)(void *)(&flag9), 1);
    for (i = 0; i < flag9; i++)
    {
        FUN_0085b240_node* pNode = ((::FUN_0085b240_node *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::FUN_0085b240_mgr * *>(&::g_dataHandler))))->GetCompiledFileByIndex(i)));
        {
            void* pData = ((void *)(reinterpret_cast<::BGSCameraPath *>((pNode))->GetShotList()));
            flagA = ((unsigned char)(::FUN_0044a670((const char *)(pData))));
            reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(a1), (const char *)(void *)(&flagA), 1);
            reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(a1), (const char *)(pData), flagA);
        }
    }
    if (this->m_44 != 0)
    {
        reinterpret_cast<::FUN_008558a0 *>((reinterpret_cast<FUN_0085b240_att*>(this->m_44)))->SetExtraDataString(::FUN_004720a0((char *)(a1)) - iStartPos, "Plugin List");
    }
}

struct Collection_00861c60
{
    unsigned int* FUN_00877a30(unsigned int index);
    unsigned short FUN_00863d90(const unsigned int& value);
};
struct FUN_00861c60_shell
{
    unsigned int unknown_0;
    unsigned int unknown_4;
    unsigned int unknown_8;
    unsigned int unknown_c;
    unsigned int unknown_10;
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    Collection_00861c60* collection;
    unsigned short FUN_00861c60(unsigned int value);
};
// @fnv 0x00861c60
unsigned short FUN_00861c60_shell::FUN_00861c60(unsigned int value)
{
    unsigned int count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((collection))->FUN_0084e3a0()));
    for (unsigned int index = 0; index < count; ++index)
    {
        unsigned int currentValue = *collection->FUN_00877a30(index);
        if (currentValue == value)
            return static_cast<unsigned short>(index);
    }
    return collection->FUN_00863d90(value);
}

extern "C" char DAT_01081cf0[];

struct FUN_00861ee0_Class
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
    unsigned char unk80;

    void FUN_00861ee0(unsigned char value);
};

// If value is below 0x13, calls FUN_005b5e40 with DAT_01081cf0, value and 0x13, then stores value in unk80.
// @fnv 0x00861ee0
void FUN_00861ee0_Class::FUN_00861ee0(unsigned char value)
{
    if (value < 0x13)
        ::FUN_005b5e40();

    unk80 = value;
}

struct NiPoint3
{
    float x, y, z;
public:
    static const ::NiPoint3 ZERO;
};

class TESWorldSpace;
class TESObjectCELL
{
  public:
public:
    bool IsCellInterior() const;
public:
    int GetCellGridX();
public:
    int GetCellGridY();
public:
    ::TESWorldSpace *GetParentWorldSpace();
};

struct TES_861f20
{
};

struct TESBoundObject;
struct TESWorldSpace;

struct TESObjectREFR_861f20
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual NiPoint3* GetPos();
};

struct DataHandler_861f20
{
};

extern int DAT_011de500;


struct TESSaveLoadGame_861f20
{
    void FUN_00861f20(int aiType);
};

struct FUN_008df040_cls
{
    unsigned char FUN_008df040();
};


struct FUN_00862110_cls
{
    int unk00;
    bool FUN_00862110();
};

// @fnv 0x00862110
bool FUN_00862110_cls::FUN_00862110()
{
    if ((*reinterpret_cast<::FUN_008df040_cls * *>(&::g_TESSaveLoadGame))->FUN_008df040() >= 0x1f)
    {
        if ((*reinterpret_cast<::FUN_008df040_cls * *>(&::g_TESSaveLoadGame))->FUN_008df040() < 0x5a)
        {
            return true;
        }
    }
    return false;
}

struct Rec8623
{
    void* form;
};

struct Map8623
{
    Rec8623** At(unsigned int index);
    void RemoveAt(unsigned int index);
};


struct TESSL8623
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    Map8623* m_changes;
    void FUN_008623a0(void* form);
};

// Scans m_changes for the record whose form matches form, removes it from the map and deletes it.
// @fnv 0x008623a0
void TESSL8623::FUN_008623a0(void* form)
{
    if (m_changes != 0)
    {
        unsigned int count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_changes))->FUN_0084e3a0()));
        for (unsigned int i = 0; i < count; i++)
        {
            Rec8623* rec = *m_changes->At(i);
            if (rec != 0 && rec->form == form)
            {
                m_changes->RemoveAt(i);
                Rec8623* del = rec;
                ::FUN_00401030(del);
                return;
            }
        }
    }
}

struct FUN_008634b0_Class
{
    void FUN_00863740();
    void* FUN_008634b0(unsigned int flags);
};
struct FUN_00863a60_Node
{
    FUN_00863a60_Node* next;
    unsigned char key;
    int value;
};

struct FUN_00863a60_Class
{
    virtual void vf00();
    virtual int vf04(int index);
    virtual bool vf08(int key, unsigned char nodeKey);
    virtual void vf0c(void* node, unsigned char key, int value);
    virtual void vf10();
    virtual void* vf14();

    int unk04;
    FUN_00863a60_Node** nodes;
    int count;

    void FUN_00863a60(unsigned char key, int value);
};

// Empty inline virtual stub; the class's first vtable slot, defined with no body.
// @fnv 0x00863a60
inline void FUN_00863a60_Class::vf00()
{}
inline int FUN_00863a60_Class::vf04(int)
{
    return 0;
}
inline bool FUN_00863a60_Class::vf08(int, unsigned char)
{
    return false;
}
inline void FUN_00863a60_Class::vf0c(void*, unsigned char, int)
{}
inline void FUN_00863a60_Class::vf10()
{}
inline void* FUN_00863a60_Class::vf14()
{
    return 0;
}

void FUN_00863a60_Class::FUN_00863a60(unsigned char key, int value)
{
    int counter = this->vf04(key);
    FUN_00863a60_Node* node = this->nodes[counter];
    int index = 0;

    while (node != 0)
    {
        ++index;

        if (this->vf08(key, node->key))
        {
            node->value = value;
            return;
        }

        node = node->next;
    }

    node = static_cast<FUN_00863a60_Node*>(this->vf14());
    this->vf0c(node, key, value);
    node->next = this->nodes[counter];
    this->nodes[counter] = node;
    ++this->count;
}

struct FUN_00863b40_Node
{
    FUN_00863b40_Node* next;
    unsigned char key;
    int value;
};

struct FUN_00863b40_Class
{
    virtual void vf00();
    virtual int vf04(unsigned char key);
    virtual bool vf08(unsigned char key, unsigned char nodeKey);

    int unk04;
    FUN_00863b40_Node** nodes;

    bool FUN_00863b40(unsigned char key, int* result);
};

// @fnv 0x00863b40
inline void FUN_00863b40_Class::vf00()
{}
inline int FUN_00863b40_Class::vf04(unsigned char)
{
    return 0;
}
inline bool FUN_00863b40_Class::vf08(unsigned char, unsigned char)
{
    return false;
}

bool FUN_00863b40_Class::FUN_00863b40(unsigned char key, int* result)
{
    int counter = this->vf04(key);
    FUN_00863b40_Node* node = this->nodes[counter];

    while (node != 0)
    {
        if (this->vf08(key, node->key))
        {
            *result = node->value;
            return true;
        }

        node = node->next;
    }

    return false;
}

struct Item_00863bc0
{
    Item_00863bc0* m_pkNext;
    unsigned char m_key;
    unsigned int m_val;
};

struct Map_00863bc0
{
    virtual void Vfn0() = 0;
    virtual unsigned int Hash(unsigned char key) = 0;
    unsigned int m_uiCount;
    Item_00863bc0** m_ppBuckets;
    void GetNextItem(Item_00863bc0*& item, unsigned char& key, unsigned int& val);
};

// Outputs the item's key and value, then advances item to the next chained item or the next non-empty bucket, or null.
// @fnv 0x00863bc0
void Map_00863bc0::GetNextItem(Item_00863bc0*& item, unsigned char& key, unsigned int& val)
{
    Item_00863bc0* pkItem = item;
    unsigned int uiIndex;
    key = pkItem->m_key;
    val = pkItem->m_val;
    if (pkItem->m_pkNext != 0)
    {
        item = pkItem->m_pkNext;
        return;
    }
    uiIndex = Hash(pkItem->m_key);
    uiIndex++;
    for (; uiIndex < m_uiCount; uiIndex++)
    {
        pkItem = m_ppBuckets[uiIndex];
        if (pkItem != 0)
        {
            item = pkItem;
            return;
        }
    }
    item = 0;
}

class B63CD0MapBase
{
  public:
    virtual ~B63CD0MapBase();


    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00863cd0 : public B63CD0MapBase
{
  public:
    virtual ~FUN_00863cd0();
};

// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x00863cd0
FUN_00863cd0::~FUN_00863cd0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

// FUN_00c3e340
struct FUN_00c3e340_cls
{
    char pad_00[0x80];
    void(* m_pFn)();
    void FUN_00c3e340();
};

// Calls m_pFn if ReleaseAndCleanup returns true and m_pFn is non-null.
// @fnv 0x00c3e340
void FUN_00c3e340_cls::FUN_00c3e340()
{
    if (reinterpret_cast<::S00c3e7d0 *>((this))->ReleaseAndCleanup() && this->m_pFn != 0)
    {
        this->m_pFn();
    }
}

class C3E3A0Table
{
  public:
    int FUN_00c3e3a0(__int64 iKey);
};

// @fnv 0x00c3e3a0
int C3E3A0Table::FUN_00c3e3a0(__int64 iKey)
{
    unsigned char m_ucClipIdentifier = (unsigned char)(iKey >> 16);
    return m_ucClipIdentifier * (((unsigned char)(iKey >> 56) + 4) % 20);
}

// FUN_00c3e3f0 : thiscall member (1 stack parameter), /Od.
// Calls a member helper on this, then when the flag parameter has bit 0 set it
// hands this to the spawn heap manager, and finally returns this.

struct FUN_00c3e3f0_cls
{
    FUN_00c3e3f0_cls* FUN_00c3e3f0(int iFlags);
};

struct SpawnHeap_cls
{
};


// @fnv 0x00c3e3f0
FUN_00c3e3f0_cls* FUN_00c3e3f0_cls::FUN_00c3e3f0(int iFlags)
{
    reinterpret_cast<::FUN_00c3db60 *>((this))->FUN_00c3db60::~FUN_00c3db60();
    if (iFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<SpawnHeap_cls*>(&(*reinterpret_cast<char *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

struct Elem00c3e420
{
};

struct Container00c3e420
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    Elem00c3e420** items;
    unsigned int count;
    bool FUN_00c3e420(int arg);
};

// Iterates the container's items and returns true as soon as an item's FUN_00c3e490(arg) check succeeds, otherwise false.
// @fnv 0x00c3e420
bool Container00c3e420::FUN_00c3e420(int arg)
{
    for (unsigned int i = 0; i < count; i++)
    {
        int depth;
        int max;
        int node;
        int pos;
        int state;
        int str;
        int addr;
        int item;
        int src;
        int delta;
        int result;
        bool b = reinterpret_cast<::S_00c3e490 *>((items[i]))->FUN_00c3e490(arg);
        if (b)
        {
            v2();
            return true;
        }
    }
    return false;
}

class ChangeEntry854f60
{
  public:
    ~ChangeEntry854f60();

    int unk00;
    int unk04;
};

class ChangesMap854f60
{
  public:
};

class ChangesMapOwner854f60 : public ChangesMap854f60
{
  public:
    void DeleteAllEntries();
};
// Destructor that calls DeleteAllEntries before the object is destroyed.
// @fnv 0x00854f00
FUN_00854f00_cls::~FUN_00854f00_cls()
{
    reinterpret_cast<::ChangesMapOwner854f60 *>(this)->DeleteAllEntries();
}

// Iterates the map's entries, deletes each ChangeEntry, then calls RemoveAll to clear the map.
// @fnv 0x00854f60
void ChangesMapOwner854f60::DeleteAllEntries()
{
    void* pkPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (pkPos)
    {
        ChangeEntry854f60* pkChange = 0;
        unsigned int auiFormId = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(pkPos), (unsigned int *)&(auiFormId), (void **)&(pkChange));
        delete pkChange;
    }
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct RefItem
{
    unsigned int unk00;
};

struct RefListNode
{
    ~RefListNode();
};

struct CellRefMapBase
{
    virtual ~CellRefMapBase();
};

struct FUN_00855440 : CellRefMapBase
{
    virtual ~FUN_00855440();
};
// @fnv 0x00855410
void* ExteriorCellNewReferencesMap::FUN_00855410(unsigned int flags)
{
    reinterpret_cast<::FUN_00855440 *>(this)->FUN_00855440::~FUN_00855440();

    if (flags & 1)
        ::FUN_00401030(this);

    return this;
}

// Destructor: walks every entry of the map, deletes each RefItem and its RefListNode list, then clears the map.
// @fnv 0x00855440
FUN_00855440::~FUN_00855440()
{
    void* pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (pos)
    {
        RefListNode* list = 0;
        unsigned int key = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(pos), (unsigned int *)&(key), (void **)&(list));
        RefListNode* node = list;
        if (list)
        {
            while (node)
            {
                RefItem* item = ((::RefItem *)(new ((void *)(node)) ::Vec3()));
                if (item)
                    delete item;
                node = ((::RefListNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            }
            reinterpret_cast<::FileMatchList *>((list))->RemoveAll();
            delete list;
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct Base008555b0
{
    virtual ~Base008555b0();
};

struct FUN_008555b0_cls : Base008555b0
{
    virtual ~FUN_008555b0_cls();
};
// Calls FUN_008555b0, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00855580
void* NumericIDBufferMap::FUN_00855580(unsigned int flags)
{
    reinterpret_cast<::FUN_008555b0_cls *>(this)->FUN_008555b0_cls::~FUN_008555b0_cls();

    if (flags & 1)
        ::FUN_00401030(this);

    return this;
}

// @fnv 0x008555b0
FUN_008555b0_cls::~FUN_008555b0_cls()
{
    void* node7;
    unsigned int b8;
    void* c3;

    node7 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (node7 != 0)
    {
        c3 = 0;
        b8 = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)(void **)(&node7), &b8, &c3);
        if (c3 != 0)
        {
            ::FUN_00401030(c3);
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct CellItem;
struct OwnedBuffer
{
    void* m_pData;
    void* m_pBuffer;
};
struct List_009e03e0
{
    void* m_item;
    List_009e03e0* m_pkNext;
    ~List_009e03e0();
    void*& FUN_006815c0();
};
class NiTMap
{
  public:
    virtual ~NiTMap();
};
struct FUN_00855730_shell
{
    NiTMap* m_pMapObject;
    List_009e03e0* m_pEntries;
    void DestroyMapAndLists();
};
// Iterates the map's entries, deleting each list's items and the list, then deletes the map and frees the buffers in the second list.
// @fnv 0x00855730
void FUN_00855730_shell::DestroyMapAndLists()
{
    void* posCur = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((m_pMapObject))->GetFirstPos();
    while (posCur)
    {
        unsigned char key;
        List_009e03e0* pList;
        reinterpret_cast<::Map_00863bc0 *>((m_pMapObject))->GetNextItem((::Item_00863bc0 *&)(posCur), key, (unsigned int &)(pList));
        List_009e03e0* pIter_ = pList;
        if (pList)
        {
            while (pIter_)
            {
                CellItem* pItem = (CellItem*)((void *)(new ((void *)(pIter_)) ::Vec3()));
                pIter_ = ((::List_009e03e0 *)(reinterpret_cast<::Callees *>((pIter_))->FUN_00726070()));
                if (pItem)
                    delete pItem;
            }
            reinterpret_cast<::FileMatchList *>((pList))->RemoveAll();
            delete pList;
        }
    }
    delete m_pMapObject;
    List_009e03e0* pIter = m_pEntries;
    if (m_pEntries)
    {
        while (pIter)
        {
            OwnedBuffer* pBuf = (OwnedBuffer*)((void *)(new ((void *)(pIter)) ::Vec3()));
            if (pBuf)
            {
                ::FUN_00401030(pBuf->m_pBuffer);
                delete pBuf;
            }
            pIter = ((::List_009e03e0 *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>((m_pEntries))->RemoveAll();
        delete m_pEntries;
    }
}


struct FUN_006815c0
{
    unsigned int itemId;
    unsigned int flags;
    unsigned int next;
    FUN_006815c0();
};

struct FUN_0096a2d0
{
    unsigned int first;
    unsigned int second;
    FUN_0096a2d0();
};

struct ReferenceMap
{
};

struct FUN_00855a20_This
{
    ReferenceMap* references;
    void AddReferenceRecord(const FUN_006815c0* input);
};
// Copies the key fields from src into a local key, stores flags into its unk0a, and applies it to owner under a scope lock.
// @fnv 0x00855970
void FUN_00855970_cls::ApplyKeyWithFlags(Key_855970* pSrcKey, unsigned short flags)
{
    ScopeLock_855970 lock(0x11, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESSaveLoadGame.cpp",
                          0x276);
    Key_855970 key;
    *(unsigned int*)&key.unk05 = *(unsigned int*)&pSrcKey->unk05;
    key.unk00 = pSrcKey->unk00;
    key.unk04 = pSrcKey->unk04;
    key.unk09 = pSrcKey->unk09;
    key.unk0a = flags;
    reinterpret_cast<::FUN_00855a20_This *>(&(owner))->AddReferenceRecord((const class ::FUN_006815c0 *)(::Key_855970 *)(&key));
}

// @fnv 0x00855a20
void FUN_00855a20_This::AddReferenceRecord(const FUN_006815c0* apRecord)
{
    AutoMemHelper frame9(0x11, true, (*reinterpret_cast<const char (*)[]>(&::SaveManager::DAT_010804c8)), 0x286);
    FUN_006815c0* record = new FUN_006815c0;
    *record = *apRecord;
    unsigned char id8 = (unsigned char)record->flags;
    FUN_0096a2d0* bucket6;
    bool found4 = reinterpret_cast<::FUN_00863b40_Class *>((references))->FUN_00863b40(id8, (int *)(::FUN_0096a2d0 **)(&bucket6));
    if (!found4)
    {
        bucket6 = new FUN_0096a2d0;
        reinterpret_cast<::FUN_00863a60_Class *>((references))->FUN_00863a60(id8, (int)(bucket6));
    }
    reinterpret_cast<::FUN_00470440 *>((bucket6))->FUN_007a7eb0((::BGSPerkEntry *)(record), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(CompareByIndex5));
}

namespace SaveManager {
struct String
{
    unsigned int unk0, unk4;
    String();
    ~String();
};
struct Changes
{
    unsigned int unk0, unk4, unk8, unkc;
    Changes();
};
struct References
{
    unsigned int unk0, unk4, unk8, unkc;
    References();
};
struct Forms
{
    unsigned int unk0, unk4, unk8, unkc;
    Forms();
};
struct Entries
{
    unsigned int unk0, unk4, unk8, unkc;
    Entries();
};
struct Array
{
    unsigned int unk0, unk4, unk8, unkc, unk10, unk14;
    Array(unsigned int, unsigned int);
    void FUN_00864240(unsigned int, const unsigned int&);
};
struct Scope
{
    unsigned int unk0;
    Scope(int, int, const char*, int);
    ~Scope();
};
struct FUN_00856380;
struct FUN_00856380
{
    Changes* changes;
    unsigned int unk4;
    References* refs;
    Forms* forms;
    Forms* otherForms;
    unsigned int unk14;
    unsigned int unk18;
    bool b1c;
    char unk1d, unk1e, unk1f;
    unsigned int unk20;
    String s24;
    String s2c;
    String s34;
    String s3c;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    Entries* e58;
    Entries* e5c;
    Entries* e60;
    Entries* e64;
    String s68;
    unsigned int unk70;
    bool b74, b75;
    char unk76, unk77;
    Array* a78;
    Array* a7c;
    char unk80;
    bool b81;
    char unk82, unk83;
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
    bool bac, bad, bae, baf;
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
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    FUN_00856380();
    void FUN_008620f0();
};
// Initialises the save manager singleton: allocates changes, references, forms, entries and arrays, zeroes fields, and calls FUN_008620f0 and CopyByteToOffset80.
// @fnv 0x00856380
FUN_00856380::FUN_00856380()
    : unk4(0), refs(0), forms(0), unk14(0), unk18(0), b1c(false), unk20(0), unk44(0), unk50(0), unk54(0), unk70(0),
      b74(false), b75(false), b81(true), unk84(0), unk88(0), unk8c(0), unk90(0), unk94(0), unka8(0), bac(false),
      bad(false), bae(false), baf(false), unkb0(0), unk1c4(0)
{
    Scope scope(0x11, 1, &DAT_010804c8, 0x35f);
    (*reinterpret_cast<::SaveManager::FUN_00856380 * *>(&::g_TESSaveLoadGame)) = this;
    changes = new Changes;
    refs = new References;
    forms = new Forms;
    otherForms = new Forms;
    e58 = new Entries;
    e5c = new Entries;
    e60 = new Entries;
    e64 = new Entries;
    a78 = new Array(100, 50);
    a78->FUN_00864240(0, 0);
    a7c = new Array(5, 1);
    a7c->FUN_00864240(0, 0);
    ::FUN_00403d30(&unk98, 0, 16);
    reinterpret_cast<::FUN_008620f0 *>(this)->Init();
    ::CopyByteToOffset80((char *)this);
}
}

namespace fnv_00856870 {
struct OwnedObject856870
{
    virtual ~OwnedObject856870();
};
struct IntList
{
    unsigned int value;
    IntList* next;
    ~IntList();
};
struct List_009e03e0
{
    ~List_009e03e0();
    bool FUN_008256d0();
    OwnedObject856870** FUN_006815c0();
};
struct FUN_00856870
{
    ~FUN_00856870();
    OwnedObject856870* field00;
    unsigned int field04;
    OwnedObject856870* field08;
    OwnedObject856870* field0c;
    OwnedObject856870* field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    IntList field24;
    IntList field2c;
    IntList field34;
    IntList field3c;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    char* field50;
    unsigned int field54;
    OwnedObject856870* field58;
    OwnedObject856870* field5c;
    OwnedObject856870* field60;
    OwnedObject856870* field64;
    IntList field68;
    List_009e03e0* field70;
    unsigned int field74;
    OwnedObject856870* field78;
    OwnedObject856870* field7c;
    unsigned int field80;
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    unsigned int fielda4;
    unsigned int fielda8;
    unsigned int fieldac;
    unsigned int fieldb0;
    unsigned int fieldb4;
    unsigned int fieldb8;
    unsigned int fieldbc;
    unsigned int fieldc0;
    unsigned int fieldc4;
    unsigned int fieldc8;
    unsigned int fieldcc;
    unsigned int fieldd0;
    unsigned int fieldd4;
    unsigned int fieldd8;
    unsigned int fielddc;
    unsigned int fielde0;
    unsigned int fielde4;
    unsigned int fielde8;
    unsigned int fieldec;
    unsigned int fieldf0;
    unsigned int fieldf4;
    unsigned int fieldf8;
    unsigned int fieldfc;
    unsigned int field100;
    unsigned int field104;
    unsigned int field108;
    unsigned int field10c;
    unsigned int field110;
    unsigned int field114;
    unsigned int field118;
    unsigned int field11c;
    unsigned int field120;
    unsigned int field124;
    unsigned int field128;
    unsigned int field12c;
    unsigned int field130;
    unsigned int field134;
    unsigned int field138;
    unsigned int field13c;
    unsigned int field140;
    unsigned int field144;
    unsigned int field148;
    unsigned int field14c;
    unsigned int field150;
    unsigned int field154;
    unsigned int field158;
    unsigned int field15c;
    unsigned int field160;
    unsigned int field164;
    unsigned int field168;
    unsigned int field16c;
    unsigned int field170;
    unsigned int field174;
    unsigned int field178;
    unsigned int field17c;
    unsigned int field180;
    unsigned int field184;
    unsigned int field188;
    unsigned int field18c;
    unsigned int field190;
    unsigned int field194;
    unsigned int field198;
    unsigned int field19c;
    unsigned int field1a0;
    unsigned int field1a4;
    unsigned int field1a8;
    unsigned int field1ac;
    unsigned int field1b0;
    unsigned int field1b4;
    unsigned int field1b8;
    unsigned int field1bc;
    unsigned int field1c0;
    void* field1c4;
};
// Destructor that deletes owned objects in fields, drains and deletes field70's list, frees field1c4, and cleans up the field24 and field2c lists.
// @fnv 0x00856870
FUN_00856870::~FUN_00856870()
{
    if (field00)
        delete field00;
    if (field08)
        delete field08;
    if (field0c)
        delete field0c;
    if (field10)
        delete field10;
    if (field50)
        delete field50;
    if (field58)
        delete field58;
    if (field5c)
        delete field5c;
    if (field60)
        delete field60;
    if (field64)
        delete field64;
    if (field78)
    {
        reinterpret_cast<::FUN_00863db0_class *>((field78))->ClearItems();
        delete field78;
    }
    if (field7c)
    {
        reinterpret_cast<::FUN_00863db0_class *>((field7c))->ClearItems();
        delete field7c;
    }
    if (field1c4)
        ::FUN_00401030(field1c4);
    if (field70)
    {
        while (!field70->FUN_008256d0())
        {
            OwnedObject856870* item = *((::fnv_00856870::OwnedObject856870 **)(new ((void *)(field70)) ::Vec3()));
            reinterpret_cast<::ItemChangeListNode *>((field70))->FUN_00905330((*(::InventoryStackRecord *const *)(&item)));
            delete item;
        }
        delete field70;
    }
    reinterpret_cast<::FileMatchList *>(&(field24))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(field2c))->RemoveAll();
}
}  // namespace fnv_00856870

struct SaveFile
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual char* GetName();
    virtual void v1c();
    virtual void Seek(int, int);
    SaveFile(const char*, int, unsigned int, bool);
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
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
};
struct SaveSetting
{
    const char* String();
};
int strcat_s(char*, unsigned int, const char*);
struct FileFinderStub
{
    static int Exist(const char*, char*, unsigned int, unsigned int);
};
struct SaveOwner
{
    void BuildSaveFilename(char*);
    SaveFile* OpenSaveFile(SaveFile*, const char*, unsigned int);
};
// @fnv 0x00857950
void C857950::FUN_00857950(int* pObject, int b)
{
    int* p;
    if (pObject == 0)
        return;
    p = ((int *)(reinterpret_cast<::SaveOwner *>((((C857370*)this)))->OpenSaveFile((::SaveFile *)(pObject), (const char *)(b), 3)));
    if (p == 0)
        p = pObject;
    ::FUN_00aff0b0((const char *)((*(int(**)(int*))(*(int**)p + 6))(p)));
    reinterpret_cast<::fnv_008578b0::FUN_008578b0_Class *>((((C8578b0*)this)))->ReleaseFile((::fnv_008578b0::BSFile *)(p), 3);
}
// Builds the save file path from the name and settings, rotates .bak backups, then opens or seeks a SaveFile according to mode.
// @fnv 0x00857370
SaveFile* SaveOwner::OpenSaveFile(SaveFile* file, const char* name, unsigned int mode)
{
    SaveFile* result2;
    char pathX[260];
    if (file)
    {
        ::TaskQueueInterface::CopyStringToBuffer(pathX, 260, file->GetName());
    }
    else
    {
        char basename9[260];
        if (!name)
            BuildSaveFilename(basename9);
        else
            ::TaskQueueInterface::CopyStringToBuffer(basename9, 260, name);
        ::FUN_00406d00(pathX, 260, "%s%s%s.ess", ((char *)(::FUN_004dc110())), ((const char *)(::FUN_00464f30((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SaveSetting *>(&::g_011c3f74))))->GetMenuTitle())))))),
                  basename9);
        if (mode == 0)
        {
            char directory6[260];
            ::TaskQueueInterface::CopyStringToBuffer(directory6, 260, ((char *)(::FUN_004dc110())));
            strcat_s(directory6, 260, ((const char *)(::FUN_00464f30((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SaveSetting *>(&::g_011c3f74))))->GetMenuTitle())))))));
            CreateDirectoryA(directory6, 0);
            int kBackupCount = 1;
            if (kBackupCount > 10)
                kBackupCount = 10;
            for (int backup = kBackupCount - 1; backup >= 0; --backup)
            {
                char destination3[260];
                char source_[260];
                ::TaskQueueInterface::CopyStringToBuffer(source_, 260, ((char *)(::FUN_004dc110())));
                strcat_s(source_, 260, ((const char *)(::FUN_00464f30((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SaveSetting *>(&::g_011c3f74))))->GetMenuTitle())))))));
                strcat_s(source_, 260, basename9);
                for (int suffix = 0; suffix < backup; ++suffix)
                    strcat_s(source_, 260, ".bak");
                ::TaskQueueInterface::CopyStringToBuffer(destination3, 260, source_);
                strcat_s(destination3, 260, ".bak");
                if (backup == 0)
                    ::TaskQueueInterface::CopyStringToBuffer(source_, 260, pathX);
                if (FileFinderStub::Exist(source_, 0, 0, -1))
                {
                    if (FileFinderStub::Exist(destination3, 0, 0, -1))
                        DeleteFileA(destination3);
                    std::rename(source_, destination3);
                }
            }
        }
    }
    switch (mode)
    {
    case 0:
        if (file)
        {
            unsigned int lengthX;
            char shortName[260];
            char* tail2 = FUN_0040ab30(file->GetName(), 92) + 1;
            ::TaskQueueInterface::CopyStringToBuffer(shortName, 260, tail2);
            lengthX = ::FUN_0044a670(shortName);
            if (lengthX > 4 && !fnv::crt::strnicmp(shortName + lengthX - 4, ".ess", 4))
                shortName[lengthX - 4] = 0;
            reinterpret_cast<::C857950 *>(this)->FUN_00857950((int *)(file), 0);
            if (!fnv::crt::strnicmp(shortName, "Save ", 5) || FUN_004812f0(shortName, "autosave"))
                result2 = OpenSaveFile(0, 0, 0);
            else
                result2 = OpenSaveFile(0, shortName, 0);
        }
        else
        {
            result2 = new SaveFile(pathX, 1, 0x20000, false);
        }
        break;
    case 1: {
        result2 = new SaveFile(pathX, 0, 0x20000, false);
        result2->Seek(0, 0);
        break;
    }
    case 2:
        result2 = file;
        result2->Seek(0, 0);
        break;
    case 3:
        result2 = file;
        break;
    default:
        result2 = file;
        break;
    }
    return result2;
}

class C857A10Buffer
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char* m_pcCursor;

    void FUN_00857a10(const unsigned int* puiData, unsigned int uiSize);
};

namespace ChangeValidation {
struct Actor;
}
class TESPackage
{
  public:
    virtual void packageVirtual();
};
class DialoguePackage : public TESPackage
{
  public:
};
namespace ChangeValidation {
struct Form;
struct Reference;
struct Cell;
struct World;
struct Process;
struct Point
{
    float x, y, z;
};
extern char DAT_01183028;
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct Base
{
};
struct Cell
{
};
struct World
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
    virtual void* v20c();
};
struct Reference
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
    virtual bool v100();
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
    virtual Point v170();
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
    virtual bool v22c(int);
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
    virtual World* v294();
    virtual Cell* v298();
};
struct Actor : Reference
{
};
struct Changes
{
    unsigned int UpdateFormFlags(Form*, unsigned int);
};
// Adjusts the flags of a form based on its cell or reference, clearing or setting bits for cell bounds, actor process, dialogue package and editor location.
// @fnv 0x008591b0
unsigned int Changes::UpdateFormFlags(Form* form, unsigned int flags)
{
    flags = reinterpret_cast<::FUN_00859120_cls *>(this)->ClearRefrFlag((::TESForm *)(form), flags);
    Reference* reference = (Reference*)FUN_00ec43fb(form, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &::DAT_011841cc, 0);
    Cell* cell = (Cell*)dynamic_cast<::TESObjectCELL *>(reinterpret_cast<::TESForm *>(form));
    if (cell)
    {
        if ((flags & 0x80000000) && !((int)(reinterpret_cast<::FUN_00555bc0_shell *>((cell))->FindSeenData())))
            flags &= 0x7fffffff;
        if (!reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
        {
            flags &= ~0u;
            int x = reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX();
            int y = reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY();
            if (x <= 127 && x >= -128 && y <= 127 && y >= -128)
                flags &= ~0u;
            else
                flags |= 0;
        }
    }
    else if (reference)
    {
        flags &= ~0u;
        if ((flags & 0x20) && (!((::ChangeValidation::Base *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0())) || !((void *)(reinterpret_cast<::ExtraDataList *>((((::ChangeValidation::Base *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->GetContainerChangeData()))))
            flags &= ~0x20u;
        Actor* actor = (Actor*)FUN_00ec43fb(reference, 0, &::DAT_011841cc, &::DAT_011846d4, 0);
        if (actor)
        {
            if (flags & 0)
            {
                if (!((::ChangeValidation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) || !((::ChangeValidation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->v20c())
                    flags &= ~0u;
            }
            else if (((::ChangeValidation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && ((::ChangeValidation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->v20c())
                flags |= 0;
            flags &= ~0u;
            if (((::ChangeValidation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && ((void *)(reinterpret_cast<::BaseProcess *>((((::ChangeValidation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))))->GetOneTimePackage())))
                flags |= ((unsigned int)(reinterpret_cast<::FUN_00933790Class *>((actor))->GetZero((const char *)(void *)(((void *)(reinterpret_cast<::BaseProcess *>((((::ChangeValidation::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))))->GetOneTimePackage()))))));
            if (flags & 0)
            {
                DialoguePackage* package = dynamic_cast<DialoguePackage*>(reinterpret_cast<::FUN_009344a0_shell *>((actor))->FUN_009344a0());
                if (package)
                {
                    if (((::ChangeValidation::Actor *)(::FUN_009ee040((char *)(package)))) != actor)
                        flags &= ~0u;
                    else
                        flags |= 0;
                }
            }
            if (reinterpret_cast<::P09A *>((actor))->FUN_008aad40(flags))
                flags |= 4;
            else if (!actor->v22c(0))
                flags &= ~4u;
        }
        flags &= ~0u;
        if (!(flags & 0) && (flags & 6) && !reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((reference))->FUN_005653d0() && reference != (*reinterpret_cast<::ChangeValidation::Reference * *>(&::_g_thePlayer)))
        {
            Reference* movableSlot1 = 0;
            if (reference->v100())
                movableSlot1 = reference;
            Cell* editorCellSlot11 = movableSlot1 ? movableSlot1->v298() : 0;
            World* worldSlot0 = movableSlot1 ? movableSlot1->v294() : 0;
            if (worldSlot0 || editorCellSlot11)
            {
                Point position = movableSlot1 ? movableSlot1->v170() : (*reinterpret_cast<::ChangeValidation::Point *>((void *)&::NiPoint3::ZERO));
                if (editorCellSlot11)
                {
                    if (editorCellSlot11 != ((::ChangeValidation::Cell *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget())))
                        flags |= 0;
                }
                else if (worldSlot0)
                {
                    if (worldSlot0 && worldSlot0 != ((::ChangeValidation::World *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((reference))->FUN_00575d70())))
                        flags |= 0;
                    else
                    {
                        int columnSlot12 = ::FUN_00406d90(position.x) >> 12;
                        int rowSlot22 = ::FUN_00406d90(position.y) >> 12;
                        editorCellSlot11 = ((::ChangeValidation::Cell *)(reinterpret_cast<::TESWorldSpace *>((worldSlot0))->GetCellAtGridPosition(columnSlot12, rowSlot22)));
                        if (editorCellSlot11 != ((::ChangeValidation::Cell *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget())))
                            flags |= 0;
                    }
                }
            }
            else if (((::ChangeValidation::Cell *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget())) && !reinterpret_cast<::TESObjectCELL *>((((::ChangeValidation::Cell *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget()))))->IsCellInterior())
            {
                if (movableSlot1)
                    ::FUN_005b5e40();
                Point locationSlot24 = reference->v170();
                int column2Slot10 = ::FUN_00406d90(locationSlot24.x) >> 12;
                int row2Slot1 = ::FUN_00406d90(locationSlot24.y) >> 12;
                worldSlot0 = ((::ChangeValidation::World *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((reference))->FUN_00575d70()));
                editorCellSlot11 = ((::ChangeValidation::Cell *)(reinterpret_cast<::TESWorldSpace *>((worldSlot0))->GetCellAtGridPosition(column2Slot10, row2Slot1)));
                if (editorCellSlot11 != ((::ChangeValidation::Cell *)(reinterpret_cast<::LowProcess *>((reference))->GetTarget())))
                    flags |= 0;
            }
        }
    }
    return flags;
}
}

namespace fnv_0085b320 {
struct SaveForm
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
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
    virtual unsigned short GetSaveSize(unsigned int);
};
struct SavePackage
{
};
struct SaveProcess
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
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
    virtual void slot100();
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
    virtual SavePackage* GetRunOncePackage();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual SavePackage* GetInterruptPackage();
};
struct SaveTrespass
{
};
struct SaveBase
{
    int FUN_00401170();
};
struct SaveRefr
{
};
struct SaveMobile
{
};
struct SaveActor
{
};
struct SaveQuest
{
};
extern const int DAT_01183028;
void* FUN_00ec43fb(void*, int, const void*, const void*, int);
int FUN_00406d50(char*, unsigned int, const char*);
struct SaveFormatter
{
    void FormatChangeFlags(char*, SaveForm*, unsigned int, unsigned char, bool);
};
// Builds a text report of a form's save change flags, listing each set flag with its size delta or a detailed flag name.
// @fnv 0x0085b320
void SaveFormatter::FormatChangeFlags(char* buffer, SaveForm* form, unsigned int flags, unsigned char type,
                                      bool details)
{
    ::TaskQueueInterface::CopyStringToBuffer(buffer, 500, "");
    if (form)
        flags = reinterpret_cast<::ChangeValidation::Changes *>(this)->UpdateFormFlags((::ChangeValidation::Form *)(form), flags);
    unsigned short baseSize = 0;
    if (!details && form)
        baseSize = form->GetSaveSize(0);
    SaveRefr* refr = static_cast<SaveRefr*>(FUN_00ec43fb(form, 0, &::DAT_01183028, &(*reinterpret_cast<const int *>(&::DAT_011841cc)), 0));
    SaveMobile* mobile2 = static_cast<SaveMobile*>(FUN_00ec43fb(form, 0, &::DAT_01183028, &(*reinterpret_cast<const int *>(&::DAT_01184920)), 0));
    SaveActor* actor = static_cast<SaveActor*>(FUN_00ec43fb(form, 0, &::DAT_01183028, &(*reinterpret_cast<const int *>(&::DAT_011846d4)), 0));
    {
        char text[50];
        if (mobile2)
        {
            int level = -1;
            if (((::fnv_0085b320::SaveProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile2))->GetBaseTexture())))
                level = ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::fnv_0085b320::SaveProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile2))->GetBaseTexture()))))->FUN_0045cd60()));
            switch (level)
            {
            case -1:
                if (details)
                    ::FUN_00406d00(text, 50, "Process Level: None\r\n");
                else
                    ::FUN_00406d00(text, 50, "None(%i)", baseSize);
                break;
            case 3:
                if (details)
                    ::FUN_00406d00(text, 50, "Process Level: Low\r\n");
                else
                    ::FUN_00406d00(text, 50, "Low(%i)", baseSize);
                break;
            case 2:
                if (details)
                    ::FUN_00406d00(text, 50, "Process Level: Middle Low\r\n");
                else
                    ::FUN_00406d00(text, 50, "Mid Low(%i)", baseSize);
                break;
            case 1:
                if (details)
                    ::FUN_00406d00(text, 50, "Process Level: Middle High\r\n");
                else
                    ::FUN_00406d00(text, 50, "Mid High(%i)", baseSize);
                break;
            case 0:
                if (details)
                    ::FUN_00406d00(text, 50, "Process Level: High\r\n");
                else
                    ::FUN_00406d00(text, 50, "High(%i)", baseSize);
                break;
            }
            if (!details)
            {
                while (::FUN_0044a670(text) < 25)
                    FUN_00406d50(text, 50, " ");
                FUN_00406d50(text, 50, " ");
            }
            FUN_00406d50(buffer, 500, text);
        }
        else if (baseSize && !details)
        {
            ::FUN_00406d00(text, 50, "Base(%i)", baseSize);

            while (::FUN_0044a670(text) < 25)
                FUN_00406d50(text, 50, " ");
            FUN_00406d50(text, 50, " ");
            FUN_00406d50(buffer, 500, text);
        }
        if (flags & 0x1)
        {
            if (details)
                FUN_00406d50(buffer, 500, "CHANGE_FORM_FLAGS\r\n");
            else
            {
                ::FUN_00406d00(text, 50, "Form Flags(%i)", form ? form->GetSaveSize(0x1) - baseSize : 0);

                while (::FUN_0044a670(text) < 25)
                    FUN_00406d50(text, 50, " ");
                FUN_00406d50(text, 50, " ");
                FUN_00406d50(buffer, 500, text);
            }
        }
        if (type == 42 || type == 43)
        {
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_HEALTH\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Base Health(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_ATTRIBUTES\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Base Attributes(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_DATA\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Base Data(%i)", form ? form->GetSaveSize(0x2) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x10)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_SPELLLIST\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Spell List(%i)", form ? form->GetSaveSize(0x10) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_FACTIONS\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Factions(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_MODIFIERS\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Base Modifiers(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_AIDATA\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "AI Data(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x20)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_ACTOR_BASE_FULLNAME\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Full Name(%i)", form ? form->GetSaveSize(0x20) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (type == 42)
            {
                if (flags & 0x200)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_NPC_SKILLS\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Skills(%i)", form ? form->GetSaveSize(0x200) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_NPC_COMBATSTYLE\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Combat Style(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_NPC_FAME\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Fame(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
            }
            else if (type == 43)
            {
                if (flags & 0x200)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_CREATURE_SKILLS\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Skills(%i)", form ? form->GetSaveSize(0x200) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_CREATURE_COMBATSTYLE\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Combat Style(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
            }
        }
        else if (type == 71)
        {
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_QUEST_FLAGS\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Quest Flags(%i)", form ? form->GetSaveSize(0x2) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x80000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_QUEST_STAGES\r\n");
                else
                {

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x40000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_QUEST_SCRIPT\r\n");
                else
                {
                    SaveQuest* quest = static_cast<SaveQuest*>(FUN_00ec43fb(form, 0, &::DAT_01183028, &::DAT_01186500, 0));
                    if (!quest || ((void *)(reinterpret_cast<::TESQuest *>((quest))->GetScriptLocalData())))
                    {
                        ::FUN_00406d00(text, 50, "Quest Script(%i)", form ? form->GetSaveSize(0x40000000) - baseSize : 0);
                    }
                    else if (form)
                    {
                        ::FUN_00406d00(text, 50, "Quest Script(No longer has script locals)");
                    }

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 70)
        {
            if (flags & 0x80000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_TOPIC_SAIDONCE\r\n");
                else
                {

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 73)
        {
            if (flags & 0x80000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_PACKAGE_NEVER_RUN\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Never Run Flag(%i)", form ? form->GetSaveSize(0x80000000) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x40000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_PACKAGE_WAITING\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Waiting Flag(%i)", form ? form->GetSaveSize(0x40000000) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 57)
        {
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_FLAGS\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Cell Flags(%i)", form ? form->GetSaveSize(0x2) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if ((flags & 0) && (flags & 0))
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_CREATED\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Cell Created(%i)", form ? ((unsigned short)(reinterpret_cast<::FUN_0085a450_cls *>(this)->FUN_0085a450((unsigned int)(form), 0x0))) : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x80000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_SEENDATA\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Seen Data(%i)", form ? form->GetSaveSize(0x80000000) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x40000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_DETACHTIME\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Detach Time(%i)", form ? form->GetSaveSize(0x40000000) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x8)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_OWNERSHIP\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Ownership(%i)", form ? form->GetSaveSize(0x8) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x4)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CELL_FULLNAME\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Full Name(%i)", form ? form->GetSaveSize(0x4) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 8)
        {
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_FACTION_FLAGS\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Faction Flags(%i)", form ? form->GetSaveSize(0x2) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x4)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_FACTION_REACTIONS\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Faction Reactions(%i)", form ? form->GetSaveSize(0x4) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 25)
        {
            if (flags & 0x20)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_BOOK_TEACHES_SKILL\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Book Skill(%i)", form ? form->GetSaveSize(0x20) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
        }
        else if (type == 58 || type == 59 || type == 60 || type == 61 || type == 62 || type == 63 || type == 105 ||
                 type == 64)
        {
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_CREATED_NEW_REFERENCE\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Created(%i)", form ? ((unsigned short)(reinterpret_cast<::FUN_0085a450_cls *>(this)->FUN_0085a450((unsigned int)(form), 0x0))) : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGEFLAG_REFR_CELL_CHANGED\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Cell Changed(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x2)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_MOVE\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Moved(%i)", form ? ((unsigned short)(reinterpret_cast<::FUN_0085a450_cls *>(this)->FUN_0085a450((unsigned int)(form), 0x2))) : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x4)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_HAVOK_MOVE\r\n");
                else
                {
                    if (flags & 2)
                    {
                        ::FUN_00406d00(text, 50, "Havok Moved(%i)", form ? form->GetSaveSize(0x4) - baseSize : 0);
                    }
                    else
                    {
                        ::FUN_00406d00(text, 50, "Havok Moved(%i)",
                                     form ? ((unsigned short)(reinterpret_cast<::FUN_0085a450_cls *>(this)->FUN_0085a450((unsigned int)(form), 4))) + form->GetSaveSize(4) - baseSize : 0);
                    }

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGEFLAG_REFR_HAD_HAVOK_MOVE_FLAG\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Had Havok Move Flag(%i)", 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_OBLIVION_FLAG\r\n");
                else
                {
                    if (flags & 6)
                    {
                        ::FUN_00406d00(text, 50, "Oblivion Flag(0)");
                    }
                    else
                    {
                        ::FUN_00406d00(text, 50, "Oblivion Flag(%i)", form ? ((unsigned short)(reinterpret_cast<::FUN_0085a450_cls *>(this)->FUN_0085a450((unsigned int)(form), 0x0))) : 0);
                    }

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x10000000)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_ANIMATION\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Animation(%i)", form ? form->GetSaveSize(0x10000000) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x10)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_SCALE\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Scale(%i)", form ? form->GetSaveSize(0x10) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_ALL_EXTRA\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "All Extra(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_DISABLE_STATE\r\n");
                else
                {
                    if (refr)
                    {
                        if (reinterpret_cast<::TESForm *>((refr))->GetDisabled())
                        {
                            ::FUN_00406d00(text, 50, "Disabled(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);
                        }
                        else
                        {
                            ::FUN_00406d00(text, 50, "Enabled(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);
                        }
                    }
                    else
                    {
                        ::FUN_00406d00(text, 50, "Disabled/Enabled(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);
                    }

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_EXTRA_LEVELED_CREATURE\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Leveled Creature(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x20)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_INVENTORY\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Inventory(%i)", form ? form->GetSaveSize(0x20) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_EXTRA_SCRIPT\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Script(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (flags & 0x0)
            {
                if (details)
                    FUN_00406d50(buffer, 500, "CHANGE_REFR_EXTRA_SAVEDMOVEMENTDATA\r\n");
                else
                {
                    ::FUN_00406d00(text, 50, "Movement Extra(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                    while (::FUN_0044a670(text) < 25)
                        FUN_00406d50(text, 50, " ");
                    FUN_00406d50(text, 50, " ");
                    FUN_00406d50(buffer, 500, text);
                }
            }
            if (type == 59 || type == 60)
            {
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_EQUIPMENT\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Equipment(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x200000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_DAMAGE_MODIFIERS\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Damage Modifiers(%i)",
                                     form ? form->GetSaveSize(0x200000) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x800000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_PERMANENT_MODIFIERS\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Script Modifiers(%i)",
                                     form ? form->GetSaveSize(0x800000) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x100000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_TEMP_MODIFIERS\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Temp Modifiers(%i)", form ? form->GetSaveSize(0x100000) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    unsigned int packageID = 0;
                    if (actor && ((::fnv_0085b320::SaveProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && ((::fnv_0085b320::SaveProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetRunOncePackage())
                        packageID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_0085b320::SaveProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetRunOncePackage()))->FUN_0084e3a0()));
                    if (details)
                    {
                        ::FUN_00406d00(text, 50, "CHANGE_ACTOR_RUNONCE_PACKAGE %08X\r\n", packageID);
                    }
                    else
                    {
                        ::FUN_00406d00(text, 50, "Run Once %08X(%i)", packageID,
                                     form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                    }
                    FUN_00406d50(buffer, 500, text);
                }
                if (flags & 0x0)
                {
                    unsigned int packageID = 0;
                    if (actor && ((::fnv_0085b320::SaveTrespass *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0())) && ((::fnv_0085b320::SavePackage *)(reinterpret_cast<::FUN_0041cd70_shell *>((((::fnv_0085b320::SaveTrespass *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0()))))->FUN_0041cd70())))
                        packageID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_0085b320::SavePackage *)(reinterpret_cast<::FUN_0041cd70_shell *>((((::fnv_0085b320::SaveTrespass *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0()))))->FUN_0041cd70()))))->FUN_0084e3a0()));
                    if (details)
                    {
                        ::FUN_00406d00(text, 50, "CHANGE_ACTOR_EXTRA_TRESPASS_PACKAGE %08X\r\n", packageID);
                    }
                    else
                    {
                        ::FUN_00406d00(text, 50, "Trespass %08X(%i)", packageID,
                                     form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                    }
                    FUN_00406d50(buffer, 500, text);
                }
                if (flags & 0x0)
                {
                    unsigned int packageID = 0;
                    if (actor && ((::fnv_0085b320::SaveProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && ((::fnv_0085b320::SaveProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetInterruptPackage())
                        packageID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_0085b320::SaveProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetInterruptPackage()))->FUN_0084e3a0()));
                    if (details)
                    {
                        ::FUN_00406d00(text, 50, "CHANGE_ACTOR_INTERRUPT_PACKAGE %08X\r\n", packageID);
                    }
                    else
                    {
                        char packageName2[264];
                        unsigned int packageFlags = 0;
                        if (flags & 0)
                            packageFlags = packageFlags;
                        ::TaskQueueInterface::CopyStringToBuffer(packageName2, 260, "Interrupt");
                        if (actor && reinterpret_cast<::B88B7F0Process *>((actor))->GetPackageTypeName())
                            ::TaskQueueInterface::CopyStringToBuffer(packageName2, 260, reinterpret_cast<::B88B7F0Process *>((actor))->GetPackageTypeName());
                        ::FUN_00406d00(text, 50, "%s %08X(%i)", packageName2, packageID,
                                     form ? form->GetSaveSize(packageFlags) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                    }
                    FUN_00406d50(buffer, 500, text);
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_NONSAVED_PACKAGE\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Non-saved Package(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x80000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_DISPOSITION_MODIFIERS\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Disp Modifiers(%i)", form ? form->GetSaveSize(0x80000) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_EXTRA_OBLIVION_ENTRY\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Oblivion Entry(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_EXTRA_INVESTMENTGOLD\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Investment Gold(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x400)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_LIFESTATE\r\n");
                    else
                    {
                        unsigned int oldSize = form ? form->GetSaveSize(flags & 4) : 0;
                        unsigned int changeFlags2 = (flags & 4) + 1024;
                        ::FUN_00406d00(text, 50, "Life State(%i)", form ? form->GetSaveSize(changeFlags2) - oldSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_ACTOR_EXTRA_PERSUASION\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Persuasion(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (type == 59)
                {
                    if (flags & 0x0)
                    {
                        if (details)
                            FUN_00406d50(buffer, 500, "CHANGE_CHARACTER_EXTRA_CRIMEGOLD\r\n");
                        else
                        {
                            ::FUN_00406d00(text, 50, "Crime Gold(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                            while (::FUN_0044a670(text) < 25)
                                FUN_00406d50(text, 50, " ");
                            FUN_00406d50(text, 50, " ");
                            FUN_00406d50(buffer, 500, text);
                        }
                    }
                }
            }
            else
            {
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_MAPMARKER_EXTRA_FLAGS\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Map Marker Flags(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_MAGIC\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Extra Magic(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x1000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_LOCK\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Lock(%i)", form ? form->GetSaveSize(0x1000) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_OWNER\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Owner(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_GLOBAL\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Global Owner(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EXTRA_RANK\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Rank Owner(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x0)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGEFLAG_OBJECT_DROPPED_NON_QUEST_ITEM\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Dropped Item Flag(%i)", form ? form->GetSaveSize(0x0) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x200000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OBJECT_EMPTY\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Empty Flag(%i)", form ? form->GetSaveSize(0x200000) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (!refr || (((::fnv_0085b320::SaveBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((refr))->FUN_007af430())) && ((::fnv_0085b320::SaveBase *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((refr))->FUN_007af430()))->FUN_00401170() == 28))
                {
                    if (flags & 0x20000)
                    {
                        if (details)
                            FUN_00406d50(buffer, 500, "CHANGE_DOOR_EXTRA_TELEPORT\r\n");
                        else
                        {
                            ::FUN_00406d00(text, 50, "Teleport(%i)", form ? form->GetSaveSize(0x20000) - baseSize : 0);

                            while (::FUN_0044a670(text) < 25)
                                FUN_00406d50(text, 50, " ");
                            FUN_00406d50(text, 50, " ");
                            FUN_00406d50(buffer, 500, text);
                        }
                    }
                }
                if (flags & 0x800000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OPEN_STATE\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Open State(%i)", form ? form->GetSaveSize(0x800000) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
                if (flags & 0x400000)
                {
                    if (details)
                        FUN_00406d50(buffer, 500, "CHANGE_OPEN_DEFAULT_STATE\r\n");
                    else
                    {
                        ::FUN_00406d00(text, 50, "Default Open State(%i)",
                                     form ? form->GetSaveSize(0x400000) - baseSize : 0);

                        while (::FUN_0044a670(text) < 25)
                            FUN_00406d50(text, 50, " ");
                        FUN_00406d50(text, 50, " ");
                        FUN_00406d50(buffer, 500, text);
                    }
                }
            }
        }
    }
}
}  // namespace fnv_0085b320

struct SaveMetadataFile
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(unsigned int offset, unsigned int origin);
};
struct SaveTimestamp
{
    unsigned short year, month, weekday, day, hour, minute, second, milliseconds;
};
struct SaveFormatSetting
{
    const char* String();
};
struct SaveMetadataReader
{
    int ReadTexture(const char*, void*, unsigned int*, char*, unsigned short*, char*, float*, SaveTimestamp*,
                    unsigned int*, unsigned int*);
    int ReadSaveMetadata(const char*, unsigned int*, char*, char*, char*, char*, char*, char*, unsigned int*, bool);
};
namespace SaveThumbnail {
struct Identity
{
    unsigned int a, b, c, d;
};
struct File
{
    Identity GetLastWriteTime();
};
struct Game
{
    unsigned char FUN_008df040();
};
struct Setting
{
};
struct PixelFormat
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
};
struct PixelData
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
    PixelData(unsigned int, unsigned int, const PixelFormat&, unsigned int, unsigned int);
};
struct Preferences
{
    int format, mipmap, alpha;
    Preferences();
};
struct FixedString
{
    const char* value;
    FixedString(const char*);
    ~FixedString();
    const char* FUN_0043b1b0();
};
extern const char DAT_01081adc[];
struct Texture
{
};
struct Reader
{
    void* FUN_00858600(unsigned int);
    void FUN_00858700(void*);
    void FUN_008579e0(void*, unsigned int);
    void FUN_00857bd0(unsigned int);
    Texture* ReadTexture(File*, unsigned int, unsigned int*, char*, unsigned short*, char*, float*, Identity*,
                         unsigned int*, unsigned int*);
};
// Reads a texture record from the file: flags, name, level, location, game time, identity and image data, builds a PixelData and returns the created Texture.
// @fnv 0x00860390
Texture* Reader::ReadTexture(File* file, unsigned int size, unsigned int* puiFlags, char* pcName,
                             unsigned short* pusLevel, char* pcLocation, float* pfGameTime, Identity* identity,
                             unsigned int* puiNumber, unsigned int* puiImageSize)
{
    void* buffer5 = FUN_00858600(size);
    reinterpret_cast<::FUN_008586d0_class *>(this)->FUN_008586d0((int)(file), (int)(buffer5), size);
    if ((*reinterpret_cast<::SaveThumbnail::Game * *>(&::g_TESSaveLoadGame))->FUN_008df040() >= 56)
    {
        unsigned int flagsValue;
        FUN_008579e0(&flagsValue, 4);
        if (puiFlags)
            *puiFlags = flagsValue;
    }
    if ((*reinterpret_cast<::SaveThumbnail::Game * *>(&::g_TESSaveLoadGame))->FUN_008df040() < 56 && puiFlags)
        *puiFlags = 0;
    unsigned char length3;
    FUN_008579e0(&length3, 1);
    if (pcName)
        FUN_008579e0(pcName, length3);
    else
        reinterpret_cast<::FUN_00857bd0 *>(this)->Init(length3);
    unsigned short levelValue6 = 0;
    if ((*reinterpret_cast<::SaveThumbnail::Game * *>(&::g_TESSaveLoadGame))->FUN_008df040() >= 52)
        FUN_008579e0(&levelValue6, 2);
    if (pusLevel)
        *pusLevel = levelValue6;
    FUN_008579e0(&length3, 1);
    if (pcLocation)
    {
        if (length3)
            FUN_008579e0(pcLocation, length3);
        else
            ::TaskQueueInterface::CopyStringToBuffer(pcLocation, 300, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SaveThumbnail::Setting *>(&::g_011d4fcc))))->GetMenuTitle())));
    }
    else if (length3)
        reinterpret_cast<::FUN_00857bd0 *>(this)->Init(length3);
    float time;
    FUN_008579e0(&time, 4);
    if (pfGameTime)
        *pfGameTime = time;
    unsigned int count3 = 0;
    if ((*reinterpret_cast<::SaveThumbnail::Game * *>(&::g_TESSaveLoadGame))->FUN_008df040() >= 29)
        FUN_008579e0(&count3, 4);
    if (puiNumber)
        *puiNumber = count3;
    Identity id8;
    ::FUN_00403d30(&id8, 0, 16);
    if ((*reinterpret_cast<::SaveThumbnail::Game * *>(&::g_TESSaveLoadGame))->FUN_008df040() >= 56)
        FUN_008579e0(&id8, 16);
    if ((*reinterpret_cast<::SaveThumbnail::Game * *>(&::g_TESSaveLoadGame))->FUN_008df040() < 56)
        id8 = file->GetLastWriteTime();
    if (identity)
        *identity = id8;
    Texture* texture4 = 0;
    unsigned int dataSize;
    FUN_008579e0(&dataSize, 4);
    if (dataSize)
    {
        if (puiImageSize)
        {
            unsigned int width;
            FUN_008579e0(&width, 4);
            unsigned int height8;
            FUN_008579e0(&height8, 4);
            *puiImageSize = height8;
            if ((*reinterpret_cast<::SaveThumbnail::Game * *>(&::g_TESSaveLoadGame))->FUN_008df040() < 46)
                reinterpret_cast<::FUN_00857bd0 *>(this)->Init(36);
            PixelFormat format = (*reinterpret_cast<::SaveThumbnail::PixelFormat *>((void *)&::DAT_011aa2e8));
            PixelData* pixels3 = new PixelData(width, width, format, 1, 1);
            FUN_008579e0(((void *)(reinterpret_cast<::S_0064dac0 *>((pixels3))->FUN_0064dac0(0, 0))), width * height8 * 3);
            Preferences preferences;
            preferences.format = 2;
            preferences.alpha = 0;
            preferences.mipmap = 0;
            texture4 = ((::SaveThumbnail::Texture *)(::fnv_00a5ff10::FUN_00a5ff10((::fnv_00a5ff10::RefCounted *)(pixels3), (void *)(FixedString(DAT_01081adc).FUN_0043b1b0()), (const ::fnv_00a5ff10::OwnerTriple *)&(preferences))));
            reinterpret_cast<::FUN_0040f6e0_class *>((texture4))->FUN_0040f6e0();
        }
        else
            reinterpret_cast<::FUN_00857bd0 *>(this)->Init(dataSize);
    }
    reinterpret_cast<::fnv_00858700::FUN_00858700 *>(this)->DoIt(buffer5);
    return texture4;
}
}

namespace fnv_008607e0 {
struct SaveFilePath
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual const char* Path();
};
struct SavePrefix
{
};
extern const char DAT_01081aec[], DAT_010345e0[], DAT_010806b0[];
struct SaveNameParser
{
    bool ParseSaveName(SaveFilePath*, int*, char*, char*);
};
// Parses a save file name into an optional save number, location string and play time, returning false when the name does not match the expected format.
// @fnv 0x008607e0
bool SaveNameParser::ParseSaveName(SaveFilePath* file, int* piNumber, char* location, char* playingTime)
{
    char buffer[260];
    {
        const char* filename = ::FUN_0040ab30((char *)(file->Path()), '\\') + 1;
        const char* time = ::FUN_004812f0(filename, DAT_01081aec);
        const char* separator_2 = ::FUN_004812f0(filename, DAT_010345e0);
        if (!time || !separator_2 || std::strncmp(filename, DAT_010806a8, 5))
            return false;
        if (piNumber)
        {
            unsigned int length = separator_2 - (filename + 5);
            ::FUN_004add50((char *)(buffer), (const char *)(const void *)(filename + 5), length);
            buffer[length] = 0;
            *piNumber = std::atoi(buffer);
        }
        if (location || playingTime)
        {
            const char* previous4 = 0;
            const char* last2 = 0;
            const char* cursor = filename;
            while ((cursor = ::FUN_004812f0(cursor + 1, (*reinterpret_cast<const char (*)[]>(&::fnv_00ac9790::DAT_01063cd8)))) != 0)
            {
                previous4 = last2;
                last2 = cursor;
            }
            if (!previous4 || !last2)
                return false;
            if (location)
            {
                char locationBuffer[260];
                previous4 += 2;
                unsigned int length = ::FUN_0044a670(filename);
                while (*previous4 != ' ' && previous4 < filename + length)
                    previous4++;
                length = last2 - previous4;
                ::FUN_004add50((char *)(locationBuffer), (const char *)(previous4), length);
                locationBuffer[length] = 0;
                ::FUN_00406d00(location, 255, ::DAT_0101996c, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_008607e0::SavePrefix *>(&::g_011d2028))))->GetMenuTitle())), locationBuffer);
            }
            if (playingTime)
            {
                ::TaskQueueInterface::CopyStringToBuffer(playingTime, 255, time + 13);
                char* extension = (char*)::FUN_004812f0(playingTime, DAT_010806b0);
                if (extension)
                    *extension = 0;
                for (unsigned int index = 0; index < ::FUN_0044a670(playingTime); index++)
                    if (playingTime[index] == '.')
                        playingTime[index] = ':';
            }
        }
    }
    return true;
}
}  // namespace fnv_008607e0

namespace fnv_00860ae0 {
template <class T> struct BSStringT
{
    T* data;
    unsigned short length, capacity;
    BSStringT();
    ~BSStringT();
    const T* FUN_00559450();
};
struct SaveLocation
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot4a();
    virtual void slot4b();
    virtual const char* Name();
};
struct SavePlayer
{
};
struct SaveSetting
{
};
extern const char DAT_01081b44[], DAT_01081b08[], DAT_01081afc[], DAT_010806b8[];
extern char* __cdecl FUN_00860e00(char*, const char*);
extern int __cdecl FUN_00456a20(const char*, int, int, int);
struct SaveNamer
{
    void BuildSaveFilename(char*);
};
// @fnv 0x00860ae0
void SaveNamer::BuildSaveFilename(char* output)
{
    char suffix_[5];
    const char* location;
    const char* name;
    char filename[260];
    if (!output)
        return;
    {
        bool available9 = true;
        BSStringT<char> locationString9;
        unsigned int counter = 0;
        unsigned int hours;
        unsigned int minutes5;
        name = reinterpret_cast<::FUN_0055d520_shell *>(((*reinterpret_cast<::fnv_00860ae0::SavePlayer * *>(&::_g_thePlayer))))->FUN_0055d520();
        reinterpret_cast<::fnv_00578870::FUN_00578870_Class *>(((*reinterpret_cast<::fnv_00860ae0::SavePlayer * *>(&::_g_thePlayer))))->FUN_00578870((*(::fnv_00578870::BSStr *)(&locationString9)));
        location = ((const char *)(::FUN_00559450((int *)&(locationString9))));
        if (!location)
        {
            if (((::fnv_00860ae0::SaveLocation *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_00860ae0::SavePlayer * *>(&::_g_thePlayer))))->GetTarget())))
                location = ((::fnv_00860ae0::SaveLocation *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_00860ae0::SavePlayer * *>(&::_g_thePlayer))))->GetTarget()))->Name();
            else
                location = ::DAT_01011584;
        }

        do
        {
            if (counter == 0)
                ::TaskQueueInterface::CopyStringToBuffer(suffix_, 5, ::DAT_01011584);
            else
                ::FUN_00406d00(suffix_, 5, DAT_01081b44, counter + 1);
            unsigned int elapsed4 = ((unsigned int)(reinterpret_cast<::fnv_00851cb0::S00851cd0 *>(((*reinterpret_cast<::fnv_00860ae0::SavePlayer * *>(&::_g_thePlayer))))->GetField790()));
            hours = elapsed4 / 3600000;
            elapsed4 -= hours * 3600000;
            minutes5 = elapsed4 / 60000;
            elapsed4 -= minutes5 * 60000;
            unsigned int seconds = elapsed4 / 1000;
            char fullPath[260];
            ::FUN_00406d00(filename, 260, DAT_01081b08, ((int)(reinterpret_cast<::FUN_00862370_class *>(this)->GetOrCreatePointer())), name, location,
                         reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::fnv_00860ae0::SavePlayer * *>(&::_g_thePlayer))))->FUN_0087f9f0(), hours, minutes5, seconds, suffix_);
            char* bad3 = 0;
            char* cursorA = filename;
            while ((bad3 = FUN_00860e00(cursorA, DAT_01081afc)) != 0)
            {
                if (*bad3 == '"')
                    *bad3 = 39;
                else
                    *bad3 = ' ';
                cursorA = bad3 + 1;
            }
            ::FUN_00406d00(fullPath, 260, DAT_010806b8, ((const char *)(::FUN_004dc110())), ((const char *)(::FUN_00464f30((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00860ae0::SaveSetting *>(&::g_011c3f74))))->GetMenuTitle())))))),
                         filename);
            available9 = !FUN_00456a20(fullPath, 0, 0, -1);
            counter++;
        } while (!available9);
        ::TaskQueueInterface::CopyStringToBuffer(output, 260, filename);
    }
}
}  // namespace fnv_00860ae0

struct SaveGameString
{
    char* text;
    unsigned short length, capacity;
    SaveGameString();
    ~SaveGameString();
    operator const char*() const;
};
extern char* DAT_011a2224;
extern const char g_quicksaveName[];
extern const char DAT_0107fae0[];
extern const char headerLabel[];
struct PlayerHeader
{
};
struct PlaceHeader
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual const char* GetName();
};
struct CalendarHeader
{
};
struct TimeHeader
{
    unsigned short year, month, dayOfWeek, day, hour, minute, second, milliseconds;
};
struct PixelHeader
{
    virtual ~PixelHeader();
};
struct IOHeader
{
};
struct HeaderLog
{
};
struct SaveHeader
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
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
    HeaderLog* log;
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
    unsigned char version, revision;
    unsigned short unk76;
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
    void WriteSaveHeader(void* file, const char* name);
};
struct NumericArray
{
    unsigned int* FUN_00877a30(unsigned int index);
    unsigned int FUN_00863d90(const unsigned int& value);
};
struct FUN_00861b70_Class
{
    unsigned int FindOrAddValue(unsigned int value);
};
// Copies uiSize>>2 32-bit values from puiData into the buffer, byte-swapping each when IsSwapping() is true and advancing the cursor by 4 per value.
// @fnv 0x00857a10
void C857A10Buffer::FUN_00857a10(const unsigned int* puiData, unsigned int uiSize)
{
    unsigned int ItemUpdateArray = uiSize >> 2;
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        unsigned int uiValue;
        if (((bool)(::FUN_00574900((const unsigned char *)this))))
            uiValue = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(puiData[i]);
        else
            uiValue = puiData[i];
        __memcpy(m_pcCursor, &uiValue, 4);
        reinterpret_cast<::FUN_00857bd0 *>(this)->Init(4);
    }
}
// @fnv 0x00861b70
unsigned int FUN_00861b70_Class::FindOrAddValue(unsigned int value)
{
    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(value))
    {
        return value;
    }
    unsigned int count = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*(NumericArray**)((char*)this + 0x78))))->FUN_0084e3a0()));
    for (unsigned int index = 0; index < count; ++index)
    {
        unsigned int current = *(*(NumericArray**)((char*)this + 0x78))->FUN_00877a30(index);
        if (current == value)
        {
            return index;
        }
    }
    return (*(NumericArray**)((char*)this + 0x78))->FUN_00863d90(value);
}

struct FUN_004fd380_shell
{
    void* FUN_004fd380();
};
struct Stub8622Ext
{
};
struct Stub8622Lt
{
};
bool FUN_008256d0(void* node);
struct Stub8622Self : FUN_00862370_class
{
    int* InitMaxValue();
};
// Returns m_8c, calling InitMaxValue first to initialize it if it is null.
// @fnv 0x00862370
int* FUN_00862370_class::GetOrCreatePointer()
{
    if (m_8c == 0)
        reinterpret_cast<::Stub8622Self *>(this)->InitMaxValue();
    return m_8c;
}
// Walks the node chain, tracks the largest value returned by FUN_0085fed0, then calls Init and CopyByteToOffset80 and stores nMax+1 in m_8c.
// @fnv 0x008622a0
int* Stub8622Self::InitMaxValue()
{
    void* apTargetLight = ((FUN_004fd380_shell*)this)->FUN_004fd380();
    bool bHadNull = false;
    if (!apTargetLight)
    {
        reinterpret_cast<::SaveLoadList *>((((Stub8622Ext*)this)))->LoadSaveFiles();
        apTargetLight = ((FUN_004fd380_shell*)this)->FUN_004fd380();
        bHadNull = true;
    }
    unsigned int nMax = 0;
    unsigned int nValue;
    while (apTargetLight && !FUN_008256d0(apTargetLight))
    {
        reinterpret_cast<::FUN_0085fed0_Class *>((((Stub8622Ext*)this)))->FUN_0085fed0((::FUN_0085fed0_Object *)(*(int*)((void *)(new ((void *)(((Stub8622Lt*)apTargetLight))) ::Vec3()))), (int)(&nValue), (char *)(0), (const char *)(0), 0);
        if (nValue > nMax)
        {
            nMax = nValue;
        }
        apTargetLight = reinterpret_cast<::Callees *>((apTargetLight))->FUN_00726070();
    }
    if (bHadNull)
    {
        reinterpret_cast<::FUN_0085fbd0_class *>((((Stub8622Ext*)this)))->DeleteAllItems();
    }
    ((FUN_008620f0*)this)->Init();
    CopyByteToOffset80((char*)this);
    return m_8c = (int*)(nMax + 1);
}

struct B006815c0
{
    float x, y, z;
    B006815c0();
};
struct Extra624
{
};
struct Ref624
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual B006815c0 GetStartingAngle();
    virtual B006815c0 GetStartingPosition();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual const B006815c0& GetPosition();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
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
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual bool HasStartingLocation();
    virtual void* GetStartingWorld();
    virtual void* GetStartingCell();
    void FUN_00575700(B006815c0);
};
struct Repair624
{
    void FUN_008624e0(Ref624* reference);
};
extern const char DAT_01081de8[];
extern const char DAT_01081d98[];
// @fnv 0x008624e0
void Repair624::FUN_008624e0(Ref624* reference)
{
    if (reference)
    {
        B006815c0 rotation;
        B006815c0 position;
        rotation = reference->GetPosition();
        position = (*(const ::B006815c0 *)(reinterpret_cast<::TESRecipe *>((reference))->GetData()));
        if (reinterpret_cast<::FUN_00862430_cls *>(this)->HasInvalidComponents((::FUN_00862430_vec *)(::B006815c0 *)(&rotation)))
        {
            ::FUN_005b5e40();
            Ref624* actor = 0;
            if (reference->IsActor())
                actor = reference;
            if (actor && actor->HasStartingLocation())
            {
                void* cell = actor ? actor->GetStartingCell() : 0;
                void* world = actor ? actor->GetStartingWorld() : 0;
                if (cell || world)
                {
                    reinterpret_cast<::Reference *>((reference))->FUN_00575830((::Position *)&(const ::B006815c0 &)(actor->GetStartingPosition()));
                    reinterpret_cast<::FUN_005757d0_shell *>((reference))->FUN_005757d0(actor->GetStartingAngle().z);
                    ::fnv_00573800::FUN_00573800((::fnv_00573800::MoveRef *)(reference), (::fnv_00573800::MoveCell *)(cell), (::fnv_00573800::MoveWorld *)(world));
                }
            }
            else if (((void *)(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>((((::Extra624 *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00410220(15))))
            {
                B006815c0 startRotation = reference->GetStartingPosition();
                B006815c0 uiTimestamp = reference->GetStartingAngle();
                reinterpret_cast<::Reference *>((reference))->FUN_00575830((::Position *)&(startRotation));
                reference->FUN_00575700(uiTimestamp);
                void* form = ((void *)(reinterpret_cast<::FUN_0041b320_shell *>((((::Extra624 *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_0041b320()));
                if (form)
                {
                    void* parentCell = (void*)((int)(std::uintptr_t)(dynamic_cast<::TESObjectCELL *>(reinterpret_cast<::TESForm *>((unsigned int)form))));
                    void* parentWorld = (void*)((int)(std::uintptr_t)(dynamic_cast<::TESWorldSpace *>(reinterpret_cast<::TESForm *>((unsigned int)form))));
                    if (parentCell || parentWorld)
                        ::fnv_00573800::FUN_00573800((::fnv_00573800::MoveRef *)(reference), (::fnv_00573800::MoveCell *)(parentCell), (::fnv_00573800::MoveWorld *)(parentWorld));
                }
            }
            else
            {
                reinterpret_cast<::Reference *>((reference))->FUN_00575830((::Position *)&((*reinterpret_cast<::B006815c0 *>((void *)&::NiPoint3::ZERO))));
            }
        }
        if (reinterpret_cast<::FUN_00862430_cls *>(this)->HasInvalidComponents((::FUN_00862430_vec *)(::B006815c0 *)(&position)))
        {
            ::FUN_005b5e40();
            reference->FUN_00575700((*reinterpret_cast<::B006815c0 *>((void *)&::NiPoint3::ZERO)));
        }
    }
}

struct ExpiredCellCoordinates
{
    int x;
    int y;
};
struct ExpiredCellList
{
    ExpiredCellCoordinates* item;
    ExpiredCellList* next;
    ExpiredCellList();
    ~ExpiredCellList();
    ExpiredCellCoordinates** FUN_006815c0();
    void FUN_005ae3d0(ExpiredCellCoordinates*&);
    void FUN_0063f7b0();
};
struct ExpiredChangeData
{
    unsigned int flags;
    void* buffer;
};
struct ExpiredChangesMap
{
    void* vtable;
    unsigned int hashSize;
    void* buckets;
    unsigned int count;
    ExpiredChangesMap(unsigned int);
    ~ExpiredChangesMap();
    void FUN_00855150(void*, unsigned int);
};
struct ExpiredCellMap
{
    void* vtable;
    unsigned int hashSize;
    void* buckets;
    unsigned int count;
    ExpiredCellMap(unsigned int);
    ~ExpiredCellMap();
};
struct ExpiredWorld
{
};
struct ExpiredCell
{
    unsigned int FUN_00401170();
};
struct ExpiredReference
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual ~ExpiredReference();
    unsigned int FUN_00401170();
};
struct ExpiredSaveHeader
{
    unsigned short size;
    unsigned char type;
    unsigned char version;
};
struct ExpiredCellSmall
{
    unsigned short world;
    signed char x;
    signed char y;
};
struct ExpiredCellLarge
{
    unsigned short world;
    short x;
    short y;
};
struct ExpiredMove
{
    unsigned int parent;
    float x;
    float y;
    float z;
    float rotationX;
    float rotationY;
    float rotationZ;
    ExpiredMove();
};
struct ExpiredMoveWithFlags
{
    unsigned int flags;
    unsigned int unknown;
    unsigned int parent;
    float x;
    float y;
    float z;
    float rotationX;
    float rotationY;
    float rotationZ;
    ExpiredMoveWithFlags();
};
struct ExpiredMoveWithExtra
{
    unsigned int flags;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int parent;
    float x;
    float y;
    float z;
    float rotationX;
    float rotationY;
    float rotationZ;
    ExpiredMoveWithExtra();
};
struct ExpiredCalendar
{
};
struct ExpiredSaveLoadGame
{
    ExpiredChangesMap* changes;
    void* unknown04;
    void* unknown08;
    void* unknown0c;
    void* unknown10;
    void* currentBuffer;
    unsigned int FUN_00861c00(unsigned int);
    void PurgeExpiredCellChanges();
};
// NiTMap destructor: remove all entries, then the base map destructor frees the hash table.

class F3740MapBase
{
  public:
    virtual ~F3740MapBase();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00863740 : public F3740MapBase
{
  public:
    virtual ~FUN_00863740();
};
// Calls FUN_00863740, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008634b0
void* FUN_008634b0_Class::FUN_008634b0(unsigned int flags)
{
    reinterpret_cast<::FUN_00863740 *>(this)->FUN_00863740::~FUN_00863740();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x00863740
FUN_00863740::~FUN_00863740()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct RequestValue
{
    unsigned int first, second;
};

struct FUN_00c3e690_Req
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    volatile long m_0c;
    RequestValue value;
};

class FUN_00c3e690_cls
{
  public:
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
// @fnv 0x00c3e690
    virtual void v18(FUN_00c3e690_Req* apRequest)
    {}
    bool FUN_00c3e690(FUN_00c3e690_Req* p, RequestValue value);
};

bool FUN_00c3e690_cls::FUN_00c3e690(FUN_00c3e690_Req* p, RequestValue value)
{
    long v = p->m_0c;
    if (v == 0)
    {
        p->value = value;
        return true;
    }
    else if (v < 3)
    {
        bool ok = InterlockedCompareExchange(&p->m_0c, 2, v) == v;
        if (ok)
        {
            reinterpret_cast<::FUN_00c3fca0_Class *>(this)->FUN_0044e050((::InputValues *)(p));
            p->value = value;
            bool ok2 = InterlockedCompareExchange(&p->m_0c, 0, 2) == 2;
            if (ok2)
            {
                v18(p);
            }
            return true;
        }
    }
    return false;
}


extern unsigned char DAT_01202df0;

struct ArrSI
{
};

struct FUN_00c3e750_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    volatile long a44;
    volatile long a48;
    unsigned int a4c;
    ArrSI** a50;

    bool FUN_00c3e750();
};

// Sets DAT_01202df0 to 0; if the increment of a48 reaches 1, waits for a44 to clear, then calls FUN_00446f70 on each a50 element and increments a44.
// @fnv 0x00c3e750
bool FUN_00c3e750_Class::FUN_00c3e750()
{
    unsigned int index;

    {
        unsigned int index;
    }

    {
        unsigned int index;
    }

    {
        unsigned int index;
    }

    DAT_01202df0 = 0;

    if (InterlockedIncrement(&this->a48) == 1)
    {
        while (this->a44 != 0)
        {
            Sleep(1);
        }

        for (index = 0; index < this->a4c; ++index)
        {
            reinterpret_cast<::fnv_00446f70::FUN_00446f70_Cl *>((this->a50[index]))->FUN_00446f70();
            InterlockedIncrement(&this->a44);
        }

        return true;
    }

    return false;
}

struct Cmd61
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};
struct Node61
{
    Cmd61** FUN_006815c0();
};
struct List61 : Node61
{
};
struct Map61
{
};
class Own61
{
  public:
    int pad[4];
    Map61* m_10;
    void* RemoveCommand(const char* key, int a, int b);
};
// Looks up key in m_10, scans the list for a command matching a and b, removes and deletes it, and returns its stored pointer.
// @fnv 0x00861640
void* Own61::RemoveCommand(const char* key, int a, int b)
{
    List61* list;
    if (!m_10)
        return 0;
    {
        bool found;
        Node61* it;
        found = reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(m_10))->FUN_00853130((unsigned int)(key), (::fnv_00853130::CombatThreatRecord *&)(list));
        if (!found)
            return 0;
        it = list;
        while (it)
        {
            Cmd61* cmd = *((::Cmd61 **)(new ((void *)(it)) ::Vec3()));
            if (cmd && a == cmd->m_iWordAt04 && b == cmd->m_8)
            {
                void* r = cmd->m_iWordAt00;
                reinterpret_cast<::ItemChangeListNode *>((list))->FUN_00905330((::InventoryStackRecord *const &)(cmd));
                delete cmd;
                return r;
            }
            it = ((::Node61 *)(reinterpret_cast<::Callees *>((it))->FUN_00726070()));
        }
    }
    return 0;
}

struct ObjA
{
    int unk00, unk04;
    volatile long count;
};
struct Ptr
{
    ObjA* p;
};
struct Node
{
    Node* next;
    Ptr value;
};
struct Queue
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void dec();
    Node* head;
    Node* tail;
public:
    void FUN_00c41330(bool);
};
// Sets the count at offset 0xc to 0, then calls FUN_00c41330(0) on each of the first count elements of the array at offset 4.
// @fnv 0x00c3ea10
void FUN_00c3ea10_holder::FUN_00c3ea10()
{
    unsigned int i;
    *(int*)((char*)this + 0xc) = 0;
    for (i = 0; i < *(unsigned int*)((char*)this + 8); ++i)
    {
        reinterpret_cast<::Queue *>((((FUN_00c41330_holder**)*(void**)((char*)this + 4))[i]))->FUN_00c41330(0);
    }
}
struct Worker
{
    Queue* queue;
    volatile unsigned long* hazardHead;
    volatile unsigned long* hazardNext;
    bool TryDequeue(Ptr* output);
};
// Pops the queue head with hazard-pointer protection, copies its value into output, retires the node and returns whether an item was dequeued.
// @fnv 0x00c3ea60
bool Worker::TryDequeue(Ptr* output)
{
    Node* volatile head = 0;
    while (true)
    {
        head = queue->head;
        *hazardHead = (unsigned long)head;
        if (head != queue->head)
            continue;
        int A2;
        int A5Kz9;
        int A;
        (void)&A2;
        (void)&A5Kz9;
        (void)&A;
        Node* tailNode = queue->tail;
        Node* volatile next = head->next;
        *hazardNext = (unsigned long)next;
        if (head != queue->head)
            continue;
        if (!next)
        {
            *hazardHead = 0;
            if (output->p != 0)
            {
                if (output->p)
                    ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(output->p));
                output->p = 0;
                if (output->p)
                {
                    ObjA* object = output->p;
                    InterlockedIncrement(&object->count);
                }
            }
            return false;
        }
        if (head == tailNode)
        {
            Node* value2 = next;
            Node* volatile* location = &queue->tail;
            bool success3 =
                InterlockedCompareExchange((volatile long*)location, (long)value2, (long)tailNode) == (long)tailNode;
            continue;
        }
        {
            Ptr* source = &next->value;
            ObjA* object;
            int A5KzC;
            int A5KzF;
            int A9Qx9;
            (void)&A5KzC;
            (void)&A5KzF;
            (void)&A9Qx9;
            if (output->p != source->p)
            {
                if (output->p)
                    ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(output->p));
                output->p = source->p;
                if (output->p)
                {
                    object = output->p;
                    InterlockedIncrement(&object->count);
                }
            }
        }
        {
            Node* expected = head;
            Node* value = next;
            Node* volatile* location4 = &queue->head;
            bool successTmp =
                InterlockedCompareExchange((volatile long*)location4, (long)value, (long)expected) == (long)expected;
            if (successTmp)
            {
                int A5KzC;
                int A5KzF;
                int A9Qx9;
                (void)&A5KzC;
                (void)&A5KzF;
                (void)&A9Qx9;
                queue->dec();
                {
                    Ptr* output = &next->value;
                    ObjA* obj2;
                    if (output->p != 0)
                    {
                        if (output->p)
                            ::fnv_0044dd60::FUN_0044dd60((::fnv_0044dd60::VirtualDeletable *)(output->p));
                        output->p = 0;
                        if (output->p)
                        {
                            obj2 = output->p;
                            InterlockedIncrement(&obj2->count);
                        }
                    }
                }
                break;
            }
        }
    }
    *hazardHead = 0;
    *hazardNext = 0;
    reinterpret_cast<::FUN_00c42b60_class *>(this)->FUN_00c3f090((::Node090 *)(head));
    return true;
}

namespace fnv_00855150 {
struct FUN_00855130_This
{
};
struct Chg00855220
{
};
struct FUN_00855150_cls
{
    bool FUN_00855150(TESForm* form, unsigned int flags);
};

struct GlobalObj0047c850
{
};

struct RefCalls00855150
{
};

struct FormCalls00855150
{
};

// @fnv 0x00855150
bool FUN_00855150_cls::FUN_00855150(TESForm* form, unsigned int flags)
{
    if (reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::fnv_00855150::GlobalObj0047c850 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
    {
        return false;
    }
    TESObjectREFR* ref = reinterpret_cast<::FUN_00855130_This *>((((FUN_00855130_This*)this)))->FUN_00855130(form);
    if (ref != 0)
    {
        reinterpret_cast<::FUN_00854e70_class *>((((RefCalls00855150*)ref)))->FUN_00854e70(flags);
        if (::FUN_00559450((int *)(((RefCalls00855150*)ref))) == 0)
        {
            reinterpret_cast<::NiTMap_S *>((this))->RemoveKey(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((FormCalls00855150*)form)))->FUN_0084e3a0())));
            TESObjectREFR* a4 = ref;
            TESObjectREFR* b = a4;
            (void)(b ? reinterpret_cast<::FUN_00854e10 *>((((Chg00855220*)b)))->FUN_00854fe0(1) : (void*)0);
        }
        return true;
    }
    return false;
}
}  // namespace fnv_00855150

namespace fnv_00861820 {
class FormX
{
  public:
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10();
    virtual void F2c();
    char FUN_00401170();
};
extern "C" void* __cdecl FUN_00ec43fb(void* p, long off, void* src, void* dst, int isRef);
extern char DAT_01183028, DAT_01183108, DAT_01183060, DAT_011839b4;
class EnchX
{
  public:
};
struct ListX
{
};

struct FUN_006815c0
{
    unsigned int uiID;
    char cType;
    char c5, c6, c7, c8, c9;
    unsigned short usSize;
    FUN_006815c0();
};

typedef FUN_006815c0 EntryX;
struct ChangesX
{
};
struct NodeX
{
    unsigned int* FUN_006815c0();
};
struct BufX;
class SelfX
{
  public:
    char pad[0x2c];
    NodeX m2c;
    char pad2[0x44 - 0x2c - 1];
    ChangesX* m44;
    void FUN_00861820(BufX* pBuf);
};
// @fnv 0x00861820
void SelfX::FUN_00861820(BufX* pBuf)
{
    unsigned int uiCount_ggbd = 0;
    NodeX* pkNode_dhyats = &m2c;
    while (pkNode_dhyats)
    {
        unsigned int uiID = *((unsigned int *)(new ((void *)(pkNode_dhyats)) ::Vec3()));
        FormX* pkForm = ((::fnv_00861820::FormX *)(::FUN_004839c0(uiID)));
        if (pkForm)
        {
            FormX* pkBound = (FormX*)FUN_00ec43fb(pkForm, 0, &DAT_01183028, &DAT_01183108, 0);
            FormX* pkSpell = (FormX*)FUN_00ec43fb(pkForm, 0, &DAT_01183028, &DAT_01183060, 0);
            EnchX* pkEnch_db = (EnchX*)FUN_00ec43fb(pkForm, 0, &DAT_01183028, &DAT_011839b4, 0);
            if (pkEnch_db && !((::fnv_00861820::FormX *)(reinterpret_cast<::Callees *>((pkEnch_db))->FUN_00726070())))
            {
                pkNode_dhyats = ((::fnv_00861820::NodeX *)(reinterpret_cast<::Callees *>((pkNode_dhyats))->FUN_00726070()));
                continue;
            }
            if (pkEnch_db && ((::fnv_00861820::FormX *)(reinterpret_cast<::Callees *>((pkEnch_db))->FUN_00726070())) &&
                reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::fnv_00861820::ListX * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_00861820::FormX *)(reinterpret_cast<::Callees *>((pkEnch_db))->FUN_00726070()))))->FUN_0084e3a0()))))
                uiCount_ggbd++;
            if (pkBound || pkSpell)
                uiCount_ggbd++;
        }
        pkNode_dhyats = ((::fnv_00861820::NodeX *)(reinterpret_cast<::Callees *>((pkNode_dhyats))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(pBuf), (const char *)(void *)(&uiCount_ggbd), 4);
    if (!uiCount_ggbd)
        return;
    pkNode_dhyats = &m2c;
    while (pkNode_dhyats)
    {
        unsigned int uiFormID_wk = *((unsigned int *)(new ((void *)(pkNode_dhyats)) ::Vec3()));
        FormX* pkObj = ((::fnv_00861820::FormX *)(::FUN_004839c0(uiFormID_wk)));
        if (pkObj)
        {
            FormX* pkBoundObj_ai = (FormX*)FUN_00ec43fb(pkObj, 0, &DAT_01183028, &DAT_01183108, 0);
            FormX* pkSpellItem = (FormX*)FUN_00ec43fb(pkObj, 0, &DAT_01183028, &DAT_01183060, 0);
            if (pkBoundObj_ai || pkSpellItem)
            {
                EnchX* pkEnchForm_siup = (EnchX*)FUN_00ec43fb(pkObj, 0, &DAT_01183028, &DAT_011839b4, 0);
                if (pkEnchForm_siup)
                {
                    FormX* pkEnchItem = ((::fnv_00861820::FormX *)(reinterpret_cast<::Callees *>((pkEnchForm_siup))->FUN_00726070()));
                    if (!pkEnchItem)
                    {
                        ::FUN_005b5e40(
                            );
                        pkNode_dhyats = ((::fnv_00861820::NodeX *)(reinterpret_cast<::Callees *>((pkNode_dhyats))->FUN_00726070()));
                        continue;
                    }
                    if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::fnv_00861820::ListX * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkEnchItem))->FUN_0084e3a0()))))
                    {
                        pkEnchItem->F2c();
                        unsigned int uiEnchSize = ((unsigned int)(reinterpret_cast<::FUN_00473080_Class *>((pkEnchItem))->GetGlobalValue()));
                        reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(pBuf), (const char *)(void *)(reinterpret_cast<::FUN_00473070Class *>((pkEnchItem))->GetGlobalPointer()), uiEnchSize);
                        if (m44)
                        {
                            EntryX kEnchEntry;
                            kEnchEntry.cType = pkEnchItem->FUN_00401170();
                            kEnchEntry.uiID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkEnchItem))->FUN_0084e3a0()));
                            kEnchEntry.usSize = (unsigned short)uiEnchSize;
                            *(unsigned int*)&kEnchEntry.c5 = 0;
                            reinterpret_cast<::FUN_00855a20_This *>((m44))->AddReferenceRecord((const class ::FUN_006815c0 *)(::fnv_00861820::FUN_006815c0 *)(&kEnchEntry));
                        }
                        reinterpret_cast<::FUN_00485b30_shell *>((pkEnchItem))->ResetGlobalPointer();
                    }
                }
                pkObj->F2c();
                unsigned int uiSize = ((unsigned int)(reinterpret_cast<::FUN_00473080_Class *>((pkObj))->GetGlobalValue()));
                reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(pBuf), (const char *)(void *)(reinterpret_cast<::FUN_00473070Class *>((pkObj))->GetGlobalPointer()), uiSize);
                if (m44)
                {
                    EntryX kEntry;
                    kEntry.cType = pkObj->FUN_00401170();
                    kEntry.uiID = uiFormID_wk;
                    kEntry.usSize = (unsigned short)uiSize;
                    *(unsigned int*)&kEntry.c5 = 0;
                    reinterpret_cast<::FUN_00855a20_This *>((m44))->AddReferenceRecord((const class ::FUN_006815c0 *)(::fnv_00861820::FUN_006815c0 *)(&kEntry));
                }
                reinterpret_cast<::FUN_00485b30_shell *>((pkObj))->ResetGlobalPointer();
            }
        }
        pkNode_dhyats = ((::fnv_00861820::NodeX *)(reinterpret_cast<::Callees *>((pkNode_dhyats))->FUN_00726070()));
    }
}
}  // namespace fnv_00861820

namespace fnv_00863960 {
struct NiTPointerMap_Standin
{
};
struct FUN_00863ff0_class
{
    void FUN_008639c0();
    virtual ~FUN_00863ff0_class()
    {
        FUN_008639c0();
    }
};
struct FUN_00863960 : FUN_00863ff0_class
{
    virtual ~FUN_00863960();
};
// Calls RemoveAll through a NiTPointerMap_Standin pointer.
// @fnv 0x00863960
FUN_00863960::~FUN_00863960()
{
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap_Standin*)this)))->FUN_00438af0();
}
}  // namespace fnv_00863960

class FUN_00863f00
{
  public:
    virtual ~FUN_00863f00();

};

class FUN_00863ea0 : public FUN_00863f00
{
  public:
    virtual ~FUN_00863ea0();
};
// @fnv 0x00863570
void* FUN_00863570_StandIn::FUN_00863570(unsigned int flags)
{
    reinterpret_cast<::FUN_00863ea0 *>((this))->FUN_00863ea0::~FUN_00863ea0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Calls FUN_00438af0 before returning.
// @fnv 0x00863ea0
FUN_00863ea0::~FUN_00863ea0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

namespace fnv_004f12b0 {
struct RegionListSize
{
    int FUN_005ae380();
};
struct RegionList
{
    int unk00;
    RegionListSize entries;
};
struct DataHandlerSize
{
};
// Returns 2 plus eight times the value returned by the region-list entry-count method.
// @fnv 0x004f12b0
unsigned short FUN_004f12b0()
{
    unsigned short v = 0;
    v += 2;
    RegionList* q = ((::fnv_004f12b0::RegionList *)(reinterpret_cast<::FUN_004169d0_shell *>(((*reinterpret_cast<::fnv_004f12b0::DataHandlerSize * *>(&::g_dataHandler))))->FUN_004169d0()));
    v += q->entries.FUN_005ae380() * 8;
    return v;
}
}  // namespace fnv_004f12b0

namespace fnv_00858030 {
struct Vec58030
{
    int x;
    int y;
    int z;
};
struct Ref58030
{
};
struct DH58030
{
};
struct TES58030
{
    Ref58030* FUN_004fd3e0();
};
struct Player58030
{
};
struct Global58030
{
};
struct Sky58030
{
};
struct Field58030
{
    void FUN_008558a0(int id, const char* name);
};
struct Host58030
{
    char unk00[0x44];
    Field58030* f44;
    int FUN_00858600(int id);
    void FUN_00858700(int x);
    void FUN_00858030(int aParam);
};

// Writes save data for the player, world, process lists, sky, HUD, interface, and regions into the save stream.
// @fnv 0x00858030
void Host58030::FUN_00858030(int aParam)
{
    int v48;

    int v444;
    int v405;
    int v3c4;
    int v38;
    int v34;
    Ref58030* pCell_;
    int v2c;
    int v282;
    unsigned short w4;
    int v20;
    int v1c;
    int v182;
    int v14;
    Vec58030 vec;
    Ref58030* pWorld;

    v20 = ((int)(reinterpret_cast<::FUN_0084c580_shell *>(((*reinterpret_cast<::fnv_00858030::DH58030 * *>(&::g_dataHandler))))->GetField208()));
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&v20), 4);
    v282 = reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<::fnv_00858030::TES58030 * *>(&::g_TES))->FUN_004fd3e0()))->FUN_0084e3a0();
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&v282), 4);
    v1c = ((int)(reinterpret_cast<::ActorMover *>(((*reinterpret_cast<::fnv_00858030::TES58030 * *>(&::g_TES))))->GetCurrentMoveModeType()));
    v2c = ((int)(reinterpret_cast<::FUN_0045cd60_shell *>(((*reinterpret_cast<::fnv_00858030::TES58030 * *>(&::g_TES))))->FUN_0045cd60()));
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&v1c), 4);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&v2c), 4);

    pWorld = ((::fnv_00858030::Ref58030 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((*reinterpret_cast<::fnv_00858030::Player58030 * *>(&::_g_thePlayer))))->FUN_00575d70()));
    pCell_ = ((::fnv_00858030::Ref58030 *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::fnv_00858030::Player58030 * *>(&::_g_thePlayer))))->GetTarget()));
    if (pWorld == 0 && pCell_ == 0)
        ::FUN_0040fbe0();
    v14 = 0;
    if (pWorld != 0)
        v14 = reinterpret_cast<::FUN_0084e3a0_Class *>((pWorld))->FUN_0084e3a0();
    else if (pCell_ != 0)
        v14 = reinterpret_cast<::FUN_0084e3a0_Class *>((pCell_))->FUN_0084e3a0();
    vec = *((::fnv_00858030::Vec58030 *)(reinterpret_cast<::TESTopicInfo *>(((*reinterpret_cast<::fnv_00858030::Player58030 * *>(&::_g_thePlayer))))->GetAddTopicList()));
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&v14), 4);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&vec), 12);
    reinterpret_cast<::fnv_anon_00858480::TESSaveLoadGame *>(this)->FUN_00858480((::fnv_anon_00858480::BSFile *)(aParam));

    w4 = reinterpret_cast<::SaveSizeOwner *>(((*reinterpret_cast<::fnv_00858030::TES58030 * *>(&::g_TES))))->FUN_00459100();
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&w4), 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            reinterpret_cast<::FUN_008558a0 *>((f44))->SetExtraDataString(w4, "TES Class");
        v34 = FUN_00858600(w4);
        reinterpret_cast<::SaveBlockOwner *>(((*reinterpret_cast<::fnv_00858030::TES58030 * *>(&::g_TES))))->WriteSaveBlock();
        reinterpret_cast<::FUN_008586a0_class *>(this)->ForwardToFUN_00857b50(aParam, v34, w4);
        reinterpret_cast<::fnv_00858700::FUN_00858700 *>(this)->DoIt((void *)(v34));
    }

    w4 = reinterpret_cast<::OwnQ *>(&((*reinterpret_cast<::fnv_00858030::Global58030 *>(&::g_011e0e80))))->GetTotalSize();
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&w4), 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            reinterpret_cast<::FUN_008558a0 *>((f44))->SetExtraDataString(w4, "Process Lists Class");
        v38 = FUN_00858600(w4);
        reinterpret_cast<::fnv_009754f0::FUN_009754f0_shell *>(&((*reinterpret_cast<::fnv_00858030::Global58030 *>(&::g_011e0e80))))->FUN_009754f0();
        reinterpret_cast<::FUN_008586a0_class *>(this)->ForwardToFUN_00857b50(aParam, v38, w4);
        reinterpret_cast<::fnv_00858700::FUN_00858700 *>(this)->DoIt((void *)(v38));
    }

    w4 = reinterpret_cast<::FUN_0063e940_shell *>((((::fnv_00858030::Sky58030 *)(::Sky::GetInstance()))))->FUN_0063e940();
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&w4), 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            reinterpret_cast<::FUN_008558a0 *>((f44))->SetExtraDataString(w4, "Sky/Weather");
        v3c4 = FUN_00858600(w4);
        reinterpret_cast<::fnv_0063e9f0::FUN_0063e9f0_shell *>((((::fnv_00858030::Sky58030 *)(::Sky::GetInstance()))))->FUN_0063e9f0();
        reinterpret_cast<::FUN_008586a0_class *>(this)->ForwardToFUN_00857b50(aParam, v3c4, w4);
        reinterpret_cast<::fnv_00858700::FUN_00858700 *>(this)->DoIt((void *)(v3c4));
    }

    v182 = 0;
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&v182), 4);
    reinterpret_cast<::fnv_00861820::SelfX *>(this)->FUN_00861820((::fnv_00861820::BufX *)(aParam));
    w4 = 0;
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&w4), 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            reinterpret_cast<::FUN_008558a0 *>((f44))->SetExtraDataString(w4, "HUD Reticle");
        v405 = FUN_00858600(w4);
        reinterpret_cast<::FUN_008586a0_class *>(this)->ForwardToFUN_00857b50(aParam, v405, w4);
        reinterpret_cast<::fnv_00858700::FUN_00858700 *>(this)->DoIt((void *)(v405));
    }

    w4 = ::fnv_007065c0::FUN_007065c0();
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&w4), 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            reinterpret_cast<::FUN_008558a0 *>((f44))->SetExtraDataString(w4, "Interface");
        v444 = FUN_00858600(w4);
        ::SaveMenuTabStates();
        reinterpret_cast<::FUN_008586a0_class *>(this)->ForwardToFUN_00857b50(aParam, v444, w4);
        reinterpret_cast<::fnv_00858700::FUN_00858700 *>(this)->DoIt((void *)(v444));
    }

    w4 = ::fnv_004f12b0::FUN_004f12b0();
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(aParam), (const char *)(void *)(&w4), 2);
    if (w4 != 0)
    {
        if (f44 != 0)
            reinterpret_cast<::FUN_008558a0 *>((f44))->SetExtraDataString(w4, "Regions");
        v48 = FUN_00858600(w4);
        ::FUN_004f1300();
        reinterpret_cast<::FUN_008586a0_class *>(this)->ForwardToFUN_00857b50(aParam, v48, w4);
        reinterpret_cast<::fnv_00858700::FUN_00858700 *>(this)->DoIt((void *)(v48));
    }
}
}  // namespace fnv_00858030

enum MEM_CONTEXT
{
    MC_11 = 0x11
};
struct AutoMemContext
{
    int unk00;
    AutoMemContext(MEM_CONTEXT, bool, const char*, unsigned int);
    ~AutoMemContext();
};
extern const char DAT_01080750[];

struct SaveMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* buffer;
    void* FUN_00858600(unsigned int);
};

// Allocates size bytes with operator new and calls FUN_0040fbe0 if the returned pointer is null.
// @fnv 0x00858600
void* SaveMemory::FUN_00858600(unsigned int size)
{
    AutoMemContext context(MC_11, true, (*reinterpret_cast<const char (*)[]>(&::SaveManager::DAT_010804c8)), 0x103a);
    buffer = ::FUN_00401000(size);
    if (!buffer)
        ::FUN_0040fbe0();
    return buffer;
}

struct FUN_0085a2e0_Class
{
    ChangesMap* changes;
    void* unknown_04;
    void* unknown_08;
    void* unknown_0C;
    void* unknown_10;
    void* unknown_14;
    void* unknown_18;
    void* unknown_1C;
    void* unknown_20;
    void* unknown_24;
    void* unknown_28;
    void* unknown_2C;
    void* unknown_30;
    BSSimpleList<BGSNote*> deferred;
    void FUN_0085a2e0(TESForm*);
};

extern const char DAT_010809a0[];
struct IDSource0085a2e0
{
};
struct FormCall0085a2e0
{
};
struct FormIdOne0085a2e0
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void SetFormID(unsigned int);
};
struct FormIdTwo0085a2e0
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void SetFormID(unsigned int, unsigned int);
};
struct FormSlot77_0085a2e0
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void Call(unsigned int);
};
struct DeferredAdd0085a2e0
{
    void FUN_005ae3d0(BGSNote**);
};
// Checks form changes, assigns an ID, and for non-temporary non-cell forms calls methods and adds the form to deferred if absent.
// @fnv 0x0085a2e0
void FUN_0085a2e0_Class::FUN_0085a2e0(TESForm* form)
{
    if (!reinterpret_cast<::FUN_0047c850 *>((reinterpret_cast<FormCall0085a2e0*>(this)))->EvaluateCondition())
        ::FUN_005b5e40();
    changes->HasFormChanges(form, true);
    int bIsCell = ((int)(std::uintptr_t)(dynamic_cast<::TESObjectCELL *>(reinterpret_cast<::TESForm *>(form))));
    if (reinterpret_cast<::FUN_004077c0_shell *>((void *)(form))->FUN_004077c0() || bIsCell)
    {
        reinterpret_cast<FormIdOne0085a2e0*>(form)->SetFormID(
            ((int)(reinterpret_cast<::TESDataHandler *>((reinterpret_cast<IDSource0085a2e0*>((*reinterpret_cast<::FUN_0085b240_mgr * *>(&::g_dataHandler)))))->GetNextID())));
    }
    else
    {
        reinterpret_cast<FormIdTwo0085a2e0*>(form)->SetFormID(0, 1);
        reinterpret_cast<::FUN_00483c70_shell *>((reinterpret_cast<FormCall0085a2e0*>(form)))->FUN_00483c70();
        reinterpret_cast<FormSlot77_0085a2e0*>(form)->Call(reinterpret_cast<unsigned int>(DAT_01011584));
        if (!reinterpret_cast<::RefList *>(&(deferred))->FUN_005f65d0((void **)&(reinterpret_cast<BGSNote*&>(form))))
            reinterpret_cast<DeferredAdd0085a2e0*>(&deferred)->FUN_005ae3d0(reinterpret_cast<BGSNote**>(&form));
    }
}

struct NiBinaryStream
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Seek(int offset, int origin);
};
extern char* DAT_011a2224;
extern const char DAT_01081bbc[];
extern const char DAT_01081b50[];
void CopyByteToOffset80(char*);
struct SaveLoadManager
{
    unsigned char FUN_008df040();
};
struct InventoryMenuSetting
{
};
struct SaveHeaderReader
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned char majorVersion;
    unsigned char minorVersion;
    unsigned short unknown76;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int fileOffset;
    unsigned int unknown94;
    unsigned char identifier[16];
    unsigned int identifierTail;
    unsigned int FUN_00860e20(NiBinaryStream* stream, bool loadIdentifier);
};
// Reads save metadata from a file or supplied object, formats level, time, playtime and date strings, and returns the parse result.
// @fnv 0x008600b0
int SaveMetadataReader::ReadSaveMetadata(const char* path, unsigned int* number, char* name, char* levelText,
                                         char* location, char* timeText, char* dateText, char* playedText,
                                         unsigned int* extra, bool suppliedFile)
{
    SaveMetadataFile* entryB = 0;
    if (!suppliedFile)
        entryB = ((::SaveMetadataFile *)(reinterpret_cast<::SaveOwner *>(this)->OpenSaveFile((::SaveFile *)(path), (const char *)(0), 2)));
    else
        entryB = (SaveMetadataFile*)path;
    void* object4 = 0;
    if (entryB && ::FUN_008905f0((bool *)(entryB)))
        object4 = ((void *)(reinterpret_cast<::SaveHeaderReader *>(this)->FUN_00860e20((::NiBinaryStream *)(entryB), 0)));
    if (!object4)
    {
        if (number)
            *number = 0;
        if (name)
            ::TaskQueueInterface::CopyStringToBuffer(name, 300, "");
        if (levelText)
            ::TaskQueueInterface::CopyStringToBuffer(levelText, 300, "");
        if (location)
            ::TaskQueueInterface::CopyStringToBuffer(location, 300, "");
        if (timeText)
            ::TaskQueueInterface::CopyStringToBuffer(timeText, 300, "");
        if (dateText)
            ::TaskQueueInterface::CopyStringToBuffer(dateText, 300, "");
        if (playedText)
            ::TaskQueueInterface::CopyStringToBuffer(playedText, 300, "");
        if (extra)
            *extra = 0;
        if (!suppliedFile)
            reinterpret_cast<::fnv_008578b0::FUN_008578b0_Class *>(this)->ReleaseFile((::fnv_008578b0::BSFile *)(entryB), 2);
        return false;
    }
    unsigned short count = 0;
    float time = 0.0f;
    SaveTimestamp time6;
    unsigned int time_;
    int result_ = ReadTexture(path, object4, number, name, &count, location, &time, &time6, &time_, extra);
    if (levelText)
        ::FUN_00406d00(levelText, 300, "%s %i", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SaveFormatSetting *>(&::g_011d2028))))->GetMenuTitle())), count);
    if (timeText)
        ::FUN_00406d00(timeText, 300, "%s %i", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SaveFormatSetting *>(&::g_011d4624))))->GetMenuTitle())), (unsigned int)time);
    if (playedText)
    {
        unsigned int countTmp = time_ / 3600000;
        time_ -= countTmp * 3600000;
        unsigned int time4 = time_ / 60000;
        time_ -= time4 * 60000;
        unsigned int second7 = time_ / 1000;
        ::FUN_00406d00(playedText, 300, "%02i:%02i:%02i", countTmp, time4, second7);
    }
    if (dateText)
        ::FUN_00406d00(dateText, 300, "%d/%d/%02d %02d:%02d", time6.month, time6.day, time6.year, time6.hour, time6.minute);
    entryB->Seek(0, (*reinterpret_cast<unsigned int *>(&::DAT_010a2480)));
    if (!suppliedFile)
        reinterpret_cast<::fnv_008578b0::FUN_008578b0_Class *>(this)->ReleaseFile((::fnv_008578b0::BSFile *)(entryB), 2);
    return result_;
}
// Reads header data from the stream, may seek to 0xd000, and checks the loaded version fields.
// @fnv 0x00860e20
unsigned int SaveHeaderReader::FUN_00860e20(NiBinaryStream* stream, bool loadIdentifier)
{
    char header[260];
    fileOffset = 0;
    if (!reinterpret_cast<::FUN_00857ba0_shell *>(this)->ReadFromStream(stream, header, ::FUN_0044a670(DAT_011a2224)))
        return 0;
    if (header[0])
    {
        if (std::strncmp(header, DAT_01081bbc, 4) == 0)
        {
            stream->Seek(0xd000, (*reinterpret_cast<unsigned int *>(&::DAT_010a2480)));
            fileOffset = 0xd000;
            reinterpret_cast<::FUN_00857ba0_shell *>(this)->ReadFromStream(stream, header, ::FUN_0044a670(DAT_011a2224));
        }
        if (std::strncmp(header, DAT_011a2224, ::FUN_0044a670(DAT_011a2224)) != 0)
            return 0;
    }
    else
    {
        stream->Seek(0, (*reinterpret_cast<unsigned int *>(&::DAT_010a2480)));
    }
    {
        unsigned int result;
        reinterpret_cast<::FUN_00857ba0_shell *>(this)->ReadFromStream(stream, &majorVersion, 1);
        reinterpret_cast<::FUN_00857ba0_shell *>(this)->ReadFromStream(stream, &minorVersion, 1);
        CopyByteToOffset80(reinterpret_cast<char*>(this));
        if (reinterpret_cast<SaveLoadManager*>((*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))->FUN_008df040() >= 0x52)
        {
            if (loadIdentifier)
            {
                reinterpret_cast<::FUN_00857ba0_shell *>(this)->ReadFromStream(stream, identifier, 16);
                reinterpret_cast<::FUN_00857ba0_shell *>(this)->ReadFromStream(stream, &identifierTail, 4);
            }
            else
            {
                stream->Seek(20, DAT_010a2484);
            }
        }
        if (reinterpret_cast<SaveLoadManager*>((*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))->FUN_008df040() < 0x52 && loadIdentifier)
        {
            FUN_00403d30(identifier, 255, 16);
            identifierTail = -1;
        }
        reinterpret_cast<::FUN_00857ba0_shell *>(this)->ReadFromStream(stream, &result, 4);
        if (majorVersion || (loadIdentifier && minorVersion != 125 && minorVersion < 19))
        {
            char messageBuffer[520];
            (sprintf)(messageBuffer, DAT_01081b50, majorVersion, minorVersion, 0, 125);
            reinterpret_cast<::FUN_004534f0_shell *>((reinterpret_cast<SaveLoadManager*>((*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_004534f0(1);
            char response = ::FUN_00704010(messageBuffer, 1, 5, (int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d34f8))))->GetMenuTitle()))), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d3684))))->GetMenuTitle())), 0);
            reinterpret_cast<::FUN_004534f0_shell *>((reinterpret_cast<SaveLoadManager*>((*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_004534f0(0);
            if (response == 2)
                result = -1;
        }
        return result;
    }
}

struct SaveGameFile56
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void Vf(int, int);
    virtual int Vg();
};

struct SaveGameMap56
{
};

struct SettingString
{
};

class GlobalObject_0040c150;


struct FUN_008579e0_shell
{
    void FUN_008579e0(void*, unsigned int);
};
// Disables save loading, collects expired cell change records into a map, removes matching change entries, frees the map, and restores the previous enabled state.
// @fnv 0x008627b0
void ExpiredSaveLoadGame::PurgeExpiredCellChanges()
{
    bool wasEnabled = ((bool)(reinterpret_cast<::BGSLoadFormBuffer *>(this)->GetVersion()));
    reinterpret_cast<::fnv_008a8150::FUN_008a8150_shell *>(this)->FUN_008a8150(false);
    ExpiredCellMap expired(37);
    unsigned int currentTime = reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::ExpiredCalendar *>(&::g_011de7b8))))->GetGameHoursPassed();
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((changes))->GetFirstPos();
    while (position)
    {
        ExpiredChangeData* i = 0;
        unsigned int e = 0;
        reinterpret_cast<::C6b7f20_Map *>((changes))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(e), (void **)&(i));
        unsigned int j = ((unsigned int)(::FUN_00559450((int *)(i))));
        ExpiredCellCoordinates p;
        p.x = 0x7fffffff;
        p.y = 0x7fffffff;
        if (j & 0x40000000)
        {
            unsigned int resetTime = 0;
            if (((char *)(reinterpret_cast<::Callees *>((i))->FUN_00726070())))
            {
                currentBuffer = ((char *)(reinterpret_cast<::Callees *>((i))->FUN_00726070()));
                ExpiredSaveHeader header;
                reinterpret_cast<::FUN_008579e0_shell *>((((ExpiredSaveLoadGame*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&header, 4);
                if (header.type == 0x39 && header.version >= 0x5b)
                {
                    if (j & 0)
                    {
                        ExpiredCellSmall cell;
                        reinterpret_cast<::FUN_008579e0_shell *>((((ExpiredSaveLoadGame*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&cell, 4);
                        e = reinterpret_cast<::fnv_00861cd0::FUN_00861cd0Class *>(this)->FUN_00861cd0(cell.world);
                        p.x = cell.x;
                        p.y = cell.y;
                    }
                    else if (j & 0)
                    {
                        ExpiredCellLarge cell;
                        reinterpret_cast<::FUN_008579e0_shell *>((((ExpiredSaveLoadGame*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&cell, 6);
                        e = reinterpret_cast<::fnv_00861cd0::FUN_00861cd0Class *>(this)->FUN_00861cd0(cell.world);
                        p.x = cell.x;
                        p.y = cell.y;
                    }
                    reinterpret_cast<::FUN_008579e0_shell *>(this)->FUN_008579e0(&resetTime, 4);
                }
                currentBuffer = 0;
            }
            else
            {
                ExpiredReference* form = ((::ExpiredReference *)(::FUN_004839c0(e)));
                if (form && form->FUN_00401170() == 0x39)
                {
                    ExpiredCell* cell = (ExpiredCell*)form;
                    resetTime = reinterpret_cast<::FUN_00546af0_shell *>((cell))->FUN_00546af0();
                    if (!reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
                    {
                        e = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::ExpiredWorld *)(reinterpret_cast<::TESObjectCELL *>((cell))->GetParentWorldSpace()))))->FUN_0084e3a0()));
                        p.x = reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX();
                        p.y = reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY();
                    }
                }
            }
            if (resetTime && currentTime - resetTime > ((unsigned int)(::fnv_00526100::FUN_00526100())))
            {
                ExpiredCellCoordinates* storedCoordinates = 0;
                if (p.x != 0x7fffffff)
                {
                    storedCoordinates = new ExpiredCellCoordinates;
                    __memcpy(storedCoordinates, &p, 8);
                    ExpiredCellList* cells = 0;
                    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>(&(expired))->FUN_00853130(e, (::fnv_00853130::CombatThreatRecord *&)(cells)))
                    {
                        cells = new ExpiredCellList;
                        reinterpret_cast<::FUN_00844700_Class *>(&(expired))->FUN_00844700(e, (unsigned int)(cells));
                    }
                    cells->FUN_005ae3d0(storedCoordinates);
                }
                else
                {
                    reinterpret_cast<::FUN_00844700_Class *>(&(expired))->FUN_00844700(e, (unsigned int)(0));
                }
            }
        }
    }
    position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((changes))->GetFirstPos();
    while (position)
    {
        ExpiredChangeData* s = 0;
        unsigned int f = 0;
        reinterpret_cast<::C6b7f20_Map *>((changes))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(f), (void **)&(s));
        unsigned int cf = ((unsigned int)(::FUN_00559450((int *)(s))));
        unsigned int a = 0;
        int q = 0x7fffffff;
        int i = 0x7fffffff;
        ExpiredReference* h = 0;
        unsigned int eb = 0;
        ExpiredSaveHeader p;
        p.size = 0;
        if (((char *)(reinterpret_cast<::Callees *>((s))->FUN_00726070())))
        {
            currentBuffer = ((char *)(reinterpret_cast<::Callees *>((s))->FUN_00726070()));
            reinterpret_cast<::FUN_008579e0_shell *>((((ExpiredSaveLoadGame*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&p, 4);
            eb = p.type;
            if (eb == 0x3a || eb == 0x3b || eb == 0x3c || eb == 0x3d || eb == 0x3e || eb == 0x3f || eb == 0x69 ||
                eb == 0x40)
            {
                if (cf & 0)
                {
                    ExpiredMoveWithFlags move;
                    reinterpret_cast<::FUN_008579e0_shell *>((((ExpiredSaveLoadGame*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&move, 0x24);
                    a = move.parent;
                    q = (int)move.x >> 12;
                    i = (int)move.y >> 12;
                }
                else if (cf & 6)
                {
                    if (cf & 0)
                    {
                        ExpiredMoveWithExtra move;
                        reinterpret_cast<::FUN_008579e0_shell *>((((ExpiredSaveLoadGame*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&move, 0x2c);
                        a = move.parent;
                        q = (int)move.x >> 12;
                        i = (int)move.y >> 12;
                    }
                    else
                    {
                        ExpiredMove move;
                        reinterpret_cast<::FUN_008579e0_shell *>((((ExpiredSaveLoadGame*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&move, 0x1c);
                        a = move.parent;
                        q = (int)move.x >> 12;
                        i = (int)move.y >> 12;
                    }
                }
                a = reinterpret_cast<::FUN_00861c00 *>(this)->GetID(a);
            }
            currentBuffer = 0;
        }
        else
        {
            ExpiredReference* form = ((::ExpiredReference *)(::FUN_004839c0(f)));
            if (form)
            {
                eb = form->FUN_00401170();
                if (eb == 0x3a || eb == 0x3b || eb == 0x3c || eb == 0x3d || eb == 0x3e || eb == 0x3f || eb == 0x69 ||
                    eb == 0x40)
                {
                    h = form;
                    ExpiredCell* cell = ((::ExpiredCell *)(reinterpret_cast<::LowProcess *>((h))->GetTarget()));
                    if (cell)
                    {
                        if (reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
                        {
                            a = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((cell))->FUN_0084e3a0()));
                            q = 0;
                            i = 0;
                        }
                        else
                        {
                            a = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::ExpiredWorld *)(reinterpret_cast<::TESObjectCELL *>((cell))->GetParentWorldSpace()))))->FUN_0084e3a0()));
                            q = reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX();
                            i = reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY();
                        }
                    }
                }
            }
        }
        if (a && q != 0x7fffffff && i != 0x7fffffff)
        {
            ExpiredCellList* cells = 0;
            if (reinterpret_cast<::fnv_00853130::NiTMapBase *>(&(expired))->FUN_00853130(a, (::fnv_00853130::CombatThreatRecord *&)(cells)))
            {
                bool reset = false;
                if (!cells)
                {
                    reset = true;
                }
                else
                {
                    while (cells && *((::ExpiredCellCoordinates **)(new ((void *)(cells)) ::Vec3())))
                    {
                        ExpiredCellCoordinates* coordinates = *((::ExpiredCellCoordinates **)(new ((void *)(cells)) ::Vec3()));
                        if (coordinates && coordinates->x == q && coordinates->y == i)
                        {
                            reset = true;
                            break;
                        }
                        cells = ((::ExpiredCellList *)(reinterpret_cast<::Callees *>((cells))->FUN_00726070()));
                    }
                }
                if (reset)
                {
                    if ((cf & 4) && !(cf & 0) && !(cf & 2))
                    {
                        if (cf == 4)
                        {
                            reinterpret_cast<::FUN_00855220_shell *>((changes))->FUN_00855220(f, true);
                        }
                        else
                        {
                            if (((char *)(reinterpret_cast<::Callees *>((s))->FUN_00726070())))
                            {
                                char* b = ((char *)(reinterpret_cast<::Callees *>((s))->FUN_00726070()));
                                unsigned int l = 0;
                                cf &= ~4;
                                cf = cf;
                                if (cf & 0)
                                {
                                    cf = cf;
                                    l = 0x2c;
                                }
                                else
                                {
                                    l = 0x1c;
                                }
                                p.size -= l;
                                unsigned int ba = p.size;
                                if (cf & 0)
                                    p.size += 4;
                                void* k = reinterpret_cast<::SaveMemory *>(this)->FUN_00858600(p.size + 4);
                                reinterpret_cast<::FUN_008579b0_shell *>((((ExpiredSaveLoadGame*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&p, 4);
                                if (cf & 0)
                                {
                                    unsigned int storedWorld = a;
                                    reinterpret_cast<::FUN_008579b0_shell *>((((ExpiredSaveLoadGame*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&storedWorld, 4);
                                }
                                reinterpret_cast<::FUN_008579b0_shell *>(this)->FUN_008579b0(b + l + 4, ba);
                                ::FUN_00401030(b);
                                reinterpret_cast<::CombatProcedure *>((s))->Initialize((::CombatController *)(k));
                                reinterpret_cast<::FUN_00537e90 *>((s))->SetQuantity(cf);
                                currentBuffer = 0;
                            }
                            else if (h)
                            {
                                changes->FUN_00855150(h, 4);
                            }
                        }
                        if (h)
                            reinterpret_cast<::RestoreBuffer *>(this)->FUN_00857d10((::RefAccess *)(h), false);
                    }
                    if ((eb == 0x3b || eb == 0x3c) && reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::DataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(f))
                    {
                        reinterpret_cast<::FUN_00855220_shell *>((changes))->FUN_00855220(f, true);
                        if (h)
                        {
                            delete h;
                            h = 0;
                        }
                    }
                    if (eb == 0x3a || eb == 0x3d || eb == 0x3e || eb == 0x3f || eb == 0x69 || eb == 0x40)
                    {
                        if (cf & 0)
                        {
                            reinterpret_cast<::FUN_00855220_shell *>((changes))->FUN_00855220(f, true);
                            if (h)
                            {
                                delete h;
                                h = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(expired))->GetFirstPos();
    while (position)
    {
        ExpiredCellList* p = 0;
        unsigned int j = 0;
        reinterpret_cast<::C6b7f20_Map *>(&(expired))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(j), (void **)&(p));
        if (p)
        {
            ExpiredCellList* node = p;
            while (node && *((::ExpiredCellCoordinates **)(new ((void *)(node)) ::Vec3())))
            {
                delete *((::ExpiredCellCoordinates **)(new ((void *)(node)) ::Vec3()));
                node->FUN_0063f7b0();
            }
            delete p;
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>(&(expired))->FUN_00438af0();
    reinterpret_cast<::fnv_008a8150::FUN_008a8150_shell *>(this)->FUN_008a8150(wasEnabled);
}

struct TESSound;
struct EffectSetting
{
};

struct FUN_00c3e310_shell
{
    void FUN_00c3e310();
};
// @fnv 0x00861130
void SaveHeader::WriteSaveHeader(void* file, const char* name)
{
    reinterpret_cast<::FUN_008620f0 *>(this)->Init();
    ::CopyByteToOffset80((char *)this);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(DAT_011a2224), ::FUN_0044a670(DAT_011a2224));
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&version), 1);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&revision), 1);
    if (!unka8)
    {
        GetSystemTime(&unk98);
        unka8 = revision;
    }
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&unk98), 16);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&unka8), 4);
    const char* _c = reinterpret_cast<::FUN_0055d520_shell *>(((*reinterpret_cast<::PlayerHeader * *>(&::_g_thePlayer))))->FUN_0055d520();
    unsigned char _f = ::FUN_0044a670(_c) + 1;
    unsigned short _b2 = reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::PlayerHeader * *>(&::_g_thePlayer))))->FUN_0087f9f0();
    SaveGameString _local2;
    reinterpret_cast<::fnv_00578870::FUN_00578870_Class *>(((*reinterpret_cast<::PlayerHeader * *>(&::_g_thePlayer))))->FUN_00578870((*(::fnv_00578870::BSStr *)(&_local2)));
    const char* _h = _local2;
    if (!_h)
        _h = ((::PlaceHeader *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::PlayerHeader * *>(&::_g_thePlayer))))->GetTarget()))->GetName();
    unsigned char _c0 = 0;
    if (_h)
        _c0 = ::FUN_0044a670(_h) + 1;
    float _b = reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::CalendarHeader *>(&::g_011de7b8))))->GetGameDaysPassed() + ((double)(reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::CalendarHeader *>(&::g_011de7b8))))->GetGameTime())) / 24.0;
    TimeHeader _n;
    GetLocalTime(&_n);
    unsigned int _image = 0;
    int _ap = 256;
    int _cb_ = 256;
    PixelHeader* _g = 0;
    unsigned int _a = 0;
    if (!reinterpret_cast<::FUN_0047c850 *>(this)->EvaluateCondition())
    {
        reinterpret_cast<::FUN_00c3e340_cls *>(((*reinterpret_cast<::IOHeader * *>(&::DAT_01202d98))))->FUN_00c3e340();
        _g = ((::PixelHeader *)(::FUN_00878f60(&_ap, &_cb_, (const char *)(0))));
        reinterpret_cast<::FUN_00c3e310_shell *>(((*reinterpret_cast<::IOHeader * *>(&::DAT_01202d98))))->FUN_00c3e310();
        if (_g)
        {
            _a = reinterpret_cast<::FUN_00861610_Class *>((_g))->GetRangeBetweenEntries(0, 0);
            _image = _a + 8;
        }
    }
    else
    {
        float aspect = (float)FUN_004dc200() / ((int)(::FUN_004dc1f0()));
        int scaledHeight = (int)aspect * _cb_;
        _image = _ap * scaledHeight * 3 + 8;
    }
    unsigned int _play3 = ((unsigned int)(reinterpret_cast<::fnv_00851cb0::S00851cd0 *>(((*reinterpret_cast<::PlayerHeader * *>(&::_g_thePlayer))))->GetField790()));
    unsigned int _heading = _f + _c0 + _image + 36;
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_heading), 4);
    if (!reinterpret_cast<::FUN_0047c850 *>(this)->EvaluateCondition() && (!name || (!((int)(std::uintptr_t)(std::strstr((char *)(name), "quicksave"))) && !((int)(std::uintptr_t)(std::strstr((char *)(name), "autosave"))))))
    {
        unsigned int saveNumber = ((unsigned int)(reinterpret_cast<::FUN_00862370_class *>(this)->GetOrCreatePointer()));
        reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&saveNumber), 4);
        unk8c = unk8c + 1;
    }
    else
    {
        unsigned int saveNumberZero = 0;
        reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&saveNumberZero), 4);
    }
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_f), 1);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(_c), _f);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_b2), 2);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_c0), 1);
    if (_h)
        reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(_h), _c0);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_b), 4);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_play3), 4);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_n), 16);
    reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_image), 4);
    if (!reinterpret_cast<::FUN_0047c850 *>(this)->EvaluateCondition())
    {
        if (_g)
        {
            reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_ap), 4);
            reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(&_cb_), 4);
            reinterpret_cast<::FUN_00857b50_slg *>(this)->FUN_00857b50((::BSFile *)(file), (const char *)(const void *)(((void *)(reinterpret_cast<::S_0064dac0 *>((_g))->FUN_0064dac0(0, 0)))), _a);
            delete _g;
        }
    }
    else
        unk94 = unk94 + _image;
    if (log)
        reinterpret_cast<::FUN_008558a0 *>((log))->SetExtraDataString(_heading, "Save Game Header");
}

struct IOManager;
extern const char DAT_0107fae0[];


struct Rec56
{
    int a;
    char b;
    char c0;
    char c1;
    char c2;
    char c3;
    char d;
    char unk0A;
    char unk0B;
    Rec56();
};

union WordBuf
{
    unsigned int u;
    struct
    {
        char b0;
        char b1;
        char b2;
        char b3;
    };
};

struct Obj44
{
    int unk00;
    int unk04;
    Obj44();
    ~Obj44();
    void FUN_00855ba0(int);
};

struct FormObj : public SaveGameFile56
{
};

struct FUN_00401170_s
{
    char FUN_00401170();
};

struct Obj56
{
    virtual void Va();
    virtual void Vb();
    virtual void Vc();
    virtual void Vd();
    virtual void Ve();
    virtual void Vf();
    virtual void Vg2();
    virtual void Vh();
    virtual void Vi();
    virtual void Vj();
    virtual void Vk();
    virtual void Vl();
    virtual void Vm();
    virtual void Vn();
    virtual void Vo();
    virtual void Vp();
    virtual void Vq();
    virtual void Vr();
    virtual void Vs();
    virtual void Vt();
    virtual unsigned short Vu(int);
    virtual void Vv();
    virtual void Vw(int);
};

struct FUN_00485d50_slg
{
};

struct FUN_008df040_shell
{
    char FUN_008df040();
};

struct Cls56
{
    SaveGameMap56* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    Obj44* m_44;
    void FUN_0085a520(Obj56*, int);
    void FUN_00858700(void*);
    bool FUN_00856ca0(int, int, unsigned char);
};
// @fnv 0x00861f20
void TESSaveLoadGame_861f20::FUN_00861f20(int aiType)
{
    if (aiType == 4 || aiType == 5)
    {
        if (aiType == 5)
        {
            TESBoundObject* pObj8;
            unsigned int kUiCount;
            unsigned int iA;
            TESObjectCELL* pCell9;
            unsigned int j3;
            TESObjectREFR_861f20* pRef3;
            NiPoint3 kPos;
            kUiCount = ((unsigned int)(reinterpret_cast<::FUN_00453980_shell *>((((TES_861f20*)g_TES)))->GetGlobalInt()));
            if (((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((((TES_861f20*)g_TES)))->GetPrevPath())))
                kUiCount = 1;
            for (iA = 0; iA < kUiCount; iA++)
            {
                pCell9 = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((((TES_861f20*)g_TES)))->GetPrevPath()));
                if (!pCell9)
                    pCell9 = ((::TESObjectCELL *)(reinterpret_cast<::FUN_00459470_Class *>((((TES_861f20*)g_TES)))->FUN_00459470(iA)));
                if (pCell9)
                    reinterpret_cast<::Cell550 *>((pCell9))->FUN_0054b5b0();
            }
            pObj8 = ::g_pLockpickItem;
            for (j3 = 0; j3 < 5; j3++)
            {
                pRef3 = ((::TESObjectREFR_861f20 *)(reinterpret_cast<::HandlerView *>(((*reinterpret_cast<::DataHandler_861f20 * *>(&::g_dataHandler))))->PlaceObjectReference(pObj8, (*reinterpret_cast<::TESObjectREFR_861f20 * *>(&::_g_thePlayer))->GetPos(), (::NiPoint3 *)&((*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>(((*reinterpret_cast<::TESObjectREFR_861f20 * *>(&::_g_thePlayer))))->GetData()))),
                                               (::TESObjectCELL *)(void *)(((void *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::TESObjectREFR_861f20 * *>(&::_g_thePlayer))))->GetTarget((*reinterpret_cast<::TESObjectREFR_861f20 * *>(&::_g_thePlayer))))->FUN_00575d70())))), (::TESWorldSpace *)(0),
                                               (::TESObjectREFR *)(0), (const char *)(0), {})));
                kPos = *pRef3->GetPos();
                kPos.z += 1000.0;
                reinterpret_cast<::Reference *>((pRef3))->FUN_00575830((::Position *)&(kPos));
            }
        }
        if (DAT_011de500 % 50 == 0)
        {
            char acName[260];
            ::FUN_00406d00(acName, 260, "Test All Cells %i.ess", DAT_011de500);
            reinterpret_cast<::Cls56 *>(this)->FUN_00856ca0(0, (int)(acName), 1);
        }
        DAT_011de500++;
    }
}

// Checks the path when saving, writes the header and plugin list, processes map entries, and releases the file when saving.
// @fnv 0x00856ca0
bool Cls56::FUN_00856ca0(int aiFileHandle, int apSavePath, unsigned char p2)
{
    void* mapPos;
    FormObj* pForm;
    AutoMemContext helper(static_cast<MEM_CONTEXT>(0x11), true, (*reinterpret_cast<const char (*)[]>(&::SaveManager::DAT_010804c8)), 0x466);
    int filePos2;
    int seekPos;
    int recs;
    int rTmp;

    if (!reinterpret_cast<::FUN_0047c850 *>((((FUN_00485d50_slg*)this)))->EvaluateCondition() && !reinterpret_cast<::FUN_008616f0_shell *>(this)->FUN_008616f0())
    {
        if (apSavePath == 0 || FUN_00408b20((const char*)apSavePath, DAT_0107fae0) != 0)
        {
            ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::DownloadableContentManager *>((((SettingString*)&g_011d2364)))->IsDLCAvailable()))), 0, (int)(::g_011cba18_arg1), (int)(0), 2.0f, false);
            return false;
        }
    }
    ((FUN_00c3e310_shell*)(*reinterpret_cast<::IOHeader * *>(&::DAT_01202d98)))->FUN_00c3e310();
    ((::ExpiredSaveLoadGame*)this)->PurgeExpiredCellChanges();
    pForm = 0;
    if (!reinterpret_cast<::FUN_0047c850 *>((((FUN_00485d50_slg*)this)))->EvaluateCondition())
    {
        pForm = (FormObj*)((::SaveOwner*)this)->OpenSaveFile((::SaveFile*)aiFileHandle, (const char*)apSavePath, 0);
    }
    if (p2)
    {
        m_44 = new Obj44();
    }
    ((::FUN_008620f0*)this)->Init();
    ::CopyByteToOffset80((char*)this);
    ((::SaveHeader*)this)->WriteSaveHeader(pForm, (const char*)apSavePath);
    ((::FUN_0085b240_cls*)this)->WritePluginList((::FUN_0085b240_ref*)pForm);
    seekPos = 0;
    if (!reinterpret_cast<::FUN_0047c850 *>((((FUN_00485d50_slg*)this)))->EvaluateCondition())
    {
        seekPos = (int)((unsigned int)(::FUN_004720a0((char *)(pForm))));
    }
    rTmp = 0;
    reinterpret_cast<::FUN_00857b50_slg *>((((::FUN_008586a0_class*)this)))->FUN_00857b50((::BSFile *)((int)pForm), (const char *)((int)&rTmp), 4);
    reinterpret_cast<::FUN_00857b50_slg *>((((::FUN_008586a0_class*)this)))->FUN_00857b50((::BSFile *)((int)pForm), (const char *)((int)&rTmp), 4);
    reinterpret_cast<::fnv_00858030::Host58030 *>(this)->FUN_00858030((int)(pForm));
    recs = 0;
    mapPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((m_00))->GetFirstPos();
    while (mapPos)
    {
        void* value1 = 0;
        unsigned int mapKey = 0;
        reinterpret_cast<::C6b7f20_Map *>((m_00))->FUN_006b7f20((::C6b7f20_Node **)&(mapPos), (unsigned int *)&(mapKey), (void **)&(value1));
        if (mapKey && value1)
        {
            m_14 = (int)reinterpret_cast<::Callees *>((value1))->FUN_00726070();
            int refVal = ::FUN_00559450((int *)(value1));
            Rec56 recData;
            recData.a = (int)mapKey;
            *(int*)&recData.c0 = refVal;
            recData.d = ((FUN_008df040_shell*)this)->FUN_008df040();
            if (m_14)
            {
                WordBuf wordBuf;
                ((FUN_008579e0_shell*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))->FUN_008579e0(&wordBuf, 4);
                recData.b = wordBuf.b2;
                recData.d = wordBuf.b3;
                reinterpret_cast<::FUN_00857b50_slg *>((((::FUN_008586a0_class*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_00857b50((::BSFile *)((int)pForm), (const char *)((int)&recData), 10);
                recs++;
                reinterpret_cast<::FUN_00857b50_slg *>((((::FUN_008586a0_class*)this)))->FUN_00857b50((::BSFile *)((int)pForm), (const char *)((int)&wordBuf), 2);
                if ((unsigned short)wordBuf.u)
                {
                    reinterpret_cast<::FUN_00857b50_slg *>((((::FUN_008586a0_class*)this)))->FUN_00857b50((::BSFile *)((int)pForm), (const char *)(m_14), (unsigned short)wordBuf.u);
                }
                if (m_44)
                {
                    ((::FUN_00855970_cls*)m_44)->ApplyKeyWithFlags((::Key_855970*)&recData, (unsigned short)wordBuf.u);
                }
                m_14 = 0;
            }
            else
            {
                Obj56* obj = (Obj56*)((void *)(::FUN_004839c0(mapKey)));
                if (obj)
                {
                    recData.b = ((FUN_00401170_s*)obj)->FUN_00401170();
                    *(int*)&recData.c0 = ((::ChangeValidation::Changes*)this)
                                             ->UpdateFormFlags((::ChangeValidation::Form*)obj, *(int*)&recData.c0);
                    reinterpret_cast<::FUN_00857b50_slg *>((((::FUN_008586a0_class*)(*reinterpret_cast<::LoadingHelper00855220 * *>(&::g_TESSaveLoadGame)))))->FUN_00857b50((::BSFile *)((int)pForm), (const char *)((int)&recData), 10);
                    recs++;
                    reinterpret_cast<::FUN_00857230_shell *>((((EffectSetting*)this)))->SetSound((TESSound*)&recData);
                    unsigned short soundVal = obj->Vu(*(int*)&recData.c0);
                    soundVal += ((unsigned short)(reinterpret_cast<::FUN_0085a450_cls *>(this)->FUN_0085a450((unsigned int)(obj), *(int*)&recData.c0)));
                    reinterpret_cast<::FUN_00857b50_slg *>((((::FUN_008586a0_class*)this)))->FUN_00857b50((::BSFile *)((int)pForm), (const char *)((int)&soundVal), 2);
                    if (soundVal)
                    {
                        void* tempObj = reinterpret_cast<::SaveMemory *>(this)->FUN_00858600(soundVal);
                        FUN_0085a520(obj, *(int*)&recData.c0);
                        obj->Vw(*(int*)&recData.c0);
                        ((::FUN_008586a0_class*)this)->ForwardToFUN_00857b50((int)pForm, (int)tempObj, soundVal);
                        reinterpret_cast<::fnv_00858700::FUN_00858700 *>(this)->DoIt(tempObj);
                    }
                    reinterpret_cast<::FUN_00857230_shell *>((((EffectSetting*)this)))->SetSound(0);
                    if (m_44)
                    {
                        ((::FUN_00855970_cls*)m_44)->ApplyKeyWithFlags((::Key_855970*)&recData, soundVal);
                    }
                }
            }
        }
    }
    ((::fnv_00858570::FUN_00858570_class*)this)->LoadTempEffectsList((int)pForm);
    filePos2 = 0;
    if (!reinterpret_cast<::FUN_0047c850 *>((((FUN_00485d50_slg*)this)))->EvaluateCondition())
    {
        filePos2 = (int)((unsigned int)(::FUN_004720a0((char *)(pForm))));
    }
    ((::fnv_00861d10::TESSaveLoadGame_standin*)this)->WriteFormIDArrays((::fnv_00861d10::BSFile*)pForm);
    if (!reinterpret_cast<::FUN_0047c850 *>((((FUN_00485d50_slg*)this)))->EvaluateCondition())
    {
        pForm->Vf(seekPos, (int)(*reinterpret_cast<unsigned int *>(&::DAT_010a2480)));
        reinterpret_cast<::FUN_00857b50_slg *>((((::FUN_008586a0_class*)this)))->FUN_00857b50((::BSFile *)((int)pForm), (const char *)((int)&filePos2), 4);
        reinterpret_cast<::FUN_00857b50_slg *>((((::FUN_008586a0_class*)this)))->FUN_00857b50((::BSFile *)((int)pForm), (const char *)((int)&recs), 4);
    }
    if (m_44)
    {
        int vcallRes = pForm->Vg();
        m_44->FUN_00855ba0(vcallRes);
        delete m_44;
        m_44 = 0;
    }
    if (!reinterpret_cast<::FUN_0047c850 *>((((FUN_00485d50_slg*)this)))->EvaluateCondition())
    {
        reinterpret_cast<::FUN_00857210_shell *>((pForm))->FUN_00857210();
        reinterpret_cast<::fnv_00862150::FUN_00862150StandIn *>(this)->FUN_00862150((::fnv_00862150::FUN_00862150File *)(pForm));
        ((::fnv_008578b0::FUN_008578b0_Class*)this)->ReleaseFile((::fnv_008578b0::BSFile*)pForm, 0);
    }
    reinterpret_cast<::FUN_00c3e340_cls *>(((*reinterpret_cast<::IOHeader * *>(&::DAT_01202d98))))->FUN_00c3e340();
    return true;
}

namespace SaveInitialData85A520 {
struct SavePoint85A520
{
    float x, y, z;
};
class SaveForm85A520
{
  public:
    virtual void v00();
};
class SaveCell85A520 : public SaveForm85A520
{
  public:
};
struct SaveExtra85A520
{
};
struct SaveProcess85A520
{
};
struct SaveEffect85A520
{
};
struct SaveMagic85A520
{
};
class TESObjectREFR85A520 : public SaveForm85A520
{
  public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual const char* GetName();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual SavePoint85A520 GetEditorPosition();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
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
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
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
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
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
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual void va4();
    virtual SaveForm85A520* va5();
    virtual SaveForm85A520* va6();
};
class SaveMobile85A520 : public TESObjectREFR85A520
{
  public:
};
class ArrowProjectile85A520 : public TESObjectREFR85A520
{
};
class MagicProjectile85A520 : public TESObjectREFR85A520
{
  public:
};
class Actor85A520 : public SaveMobile85A520
{
};
struct LocationRecord85A520
{
    unsigned int cell;
    SavePoint85A520 position;
    SavePoint85A520 rotation;
    void FUN_008572f0();
};
struct ReferenceRecord85A520
{
    int type;
    unsigned int base;
    LocationRecord85A520 savedLocation;
};
struct MoveRecord85A520
{
    unsigned int cell;
    SavePoint85A520 editorPosition;
    LocationRecord85A520 savedLocation;
    void FUN_00857320();
};
struct SmallCellRecord85A520
{
    unsigned short id;
    unsigned char x, y;
};
struct LargeCellRecord85A520
{
    unsigned short id, x, y;
};
struct SaveStream85A520
{
};
extern "C" void* _FNV_DynamicCast(void*, int, void*, void*, int);
extern int DAT_01183028;
extern const char DAT_01080ba8[];
extern const char DAT_01080b38[];
extern const char DAT_01080ae8[];
extern const char DAT_01080a90[];
extern const char DAT_01080a40[];
extern const char DAT_010809e8[];
namespace SaveWarning85A520 {
}
struct SaveHandler85A520
{
    void FUN_0085a520(SaveForm85A520*, unsigned int);
};
// When flags & 6 is nonzero, writes the parent's position, rotation, and resolved cell ID as a 28-byte record.
// @fnv 0x0085a520
void SaveHandler85A520::FUN_0085a520(SaveForm85A520* form, unsigned int flags)
{
    TESObjectREFR85A520* parent = (TESObjectREFR85A520*)_FNV_DynamicCast(form, 0, &::DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_011841cc)), 0);
    if (!parent)
    {
        SaveCell85A520* cell = (SaveCell85A520*)dynamic_cast<::TESObjectCELL *>(reinterpret_cast<::TESForm *>(form));
        if (cell)
        {
            if (flags & 0)
            {
                SmallCellRecord85A520 small;
                small.id = reinterpret_cast<::FUN_00861c60_shell *>(this)->FUN_00861c60(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveInitialData85A520::SaveForm85A520 *)(reinterpret_cast<::TESObjectCELL *>((cell))->GetParentWorldSpace()))))->FUN_0084e3a0())));
                small.x = (unsigned char)((unsigned short)(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX()));
                small.y = (unsigned char)((unsigned short)(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY()));
                reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream85A520*)(*reinterpret_cast<::FUN_008df040_cls * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&small, 4);
            }
            else if (flags & 0)
            {
                LargeCellRecord85A520 large;
                large.id = reinterpret_cast<::FUN_00861c60_shell *>(this)->FUN_00861c60(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveInitialData85A520::SaveForm85A520 *)(reinterpret_cast<::TESObjectCELL *>((cell))->GetParentWorldSpace()))))->FUN_0084e3a0())));
                large.x = ((unsigned short)(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX()));
                large.y = ((unsigned short)(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY()));
                reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream85A520*)(*reinterpret_cast<::FUN_008df040_cls * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&large, 6);
            }
        }
        return;
    }
    LocationRecord85A520 savedLocation;
    new ((void *)&(savedLocation)) ::FUN_008572f0_cls();
    SaveCell85A520* pRef = ((::SaveInitialData85A520::SaveCell85A520 *)(reinterpret_cast<::LowProcess *>((parent))->GetTarget()));
    SaveForm85A520* world = 0;
    if (pRef)
        world = ((::SaveInitialData85A520::SaveForm85A520 *)(reinterpret_cast<::TESObjectCELL *>((pRef))->GetParentWorldSpace()));
    if (world)
        savedLocation.cell = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((world))->FUN_0084e3a0())));
    else if (pRef)
        savedLocation.cell = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pRef))->FUN_0084e3a0())));
    else
    {
        if (!reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((parent))->FUN_005653d0())
            ::FUN_005b5e40();
        if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((parent))->FUN_005653d0() && !((::SaveInitialData85A520::SaveCell85A520 *)(reinterpret_cast<::FUN_0041d460_shell *>((((::SaveInitialData85A520::SaveExtra85A520 *)(reinterpret_cast<::FUN_005d43c0_ *>((parent))->FUN_005d43c0()))))->FUN_0041d460())))
            ::FUN_005b5e40();
        SaveMobile85A520* mobile = (SaveMobile85A520*)_FNV_DynamicCast(parent, 0, &(*reinterpret_cast<int *>(&::DAT_011841cc)), &(*reinterpret_cast<int *>(&::DAT_01184920)), 0);
        if (mobile && ((::SaveInitialData85A520::SaveProcess85A520 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile))->GetBaseTexture())))
        {
            if (((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::SaveInitialData85A520::SaveProcess85A520 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile))->GetBaseTexture()))))->FUN_0045cd60())) == 0)
                ::FUN_005b5e40();
            else if (((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::SaveInitialData85A520::SaveProcess85A520 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile))->GetBaseTexture()))))->FUN_0045cd60())) == 1)
                ::FUN_005b5e40();
        }
    }
    savedLocation.position = (*(::SaveInitialData85A520::SavePoint85A520 *)(reinterpret_cast<::TESTopicInfo *>((parent))->GetAddTopicList()));
    savedLocation.rotation = (*(::SaveInitialData85A520::SavePoint85A520 *)(reinterpret_cast<::TESRecipe *>((parent))->GetData()));
    if (flags & 0)
    {
        ReferenceRecord85A520 world;
        reinterpret_cast<::FUN_008572c0_cls *>(&(world))->FUN_008572c0();
        if (((::SaveInitialData85A520::SaveForm85A520 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((parent))->FUN_007af430())))
            world.base = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveInitialData85A520::SaveForm85A520 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((parent))->FUN_007af430()))))->FUN_0084e3a0())));
        world.savedLocation = savedLocation;
        ArrowProjectile85A520* savedLocation =
            (ArrowProjectile85A520*)_FNV_DynamicCast(parent, 0, &(*reinterpret_cast<int *>(&::DAT_011841cc)), &(*reinterpret_cast<int *>(&::DAT_011a28e0)), 0);
        MagicProjectile85A520* pRef =
            (MagicProjectile85A520*)_FNV_DynamicCast(parent, 0, &(*reinterpret_cast<int *>(&::DAT_011841cc)), &DAT_011a0e88, 0);
        if (reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((parent))->FUN_005653d0())
        {
            world.type = 3;
            if (world.savedLocation.cell == 0)
            {
                SaveCell85A520* persistent = ((::SaveInitialData85A520::SaveCell85A520 *)(reinterpret_cast<::FUN_0041d460_shell *>((((::SaveInitialData85A520::SaveExtra85A520 *)(reinterpret_cast<::FUN_005d43c0_ *>((parent))->FUN_005d43c0()))))->FUN_0041d460()));
                SaveForm85A520* pWorld = ((::SaveInitialData85A520::SaveForm85A520 *)(reinterpret_cast<::TESObjectCELL *>((persistent))->GetParentWorldSpace()));
                world.savedLocation.cell = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pWorld))->FUN_0084e3a0())));
            }
        }
        else if (savedLocation)
            world.type = 1;
        else if (pRef)
        {
            world.type = 2;
            world.base = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::S86a0 *>((((::SaveInitialData85A520::SaveEffect85A520 *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((::SaveInitialData85A520::SaveMagic85A520 *)(reinterpret_cast<::InterfaceManager *>((pRef))->FUN_00586150()))))->FUN_00825c00()))))->FUN_004086a0())));
        }
        reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream85A520*)(*reinterpret_cast<::FUN_008df040_cls * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&world, 36);
    }
    else if (flags & 6)
    {
        if (flags & 0)
        {
            MoveRecord85A520 cellA;
            new ((void *)&(cellA)) ::FUN_00857320();
            TESObjectREFR85A520* actor = 0;
            if (parent->IsActor())
                actor = parent;
            SaveForm85A520* move = actor ? actor->va6() : 0;
            SaveForm85A520* cellB = actor ? actor->va5() : 0;
            if (cellB || move)
            {
                cellA.editorPosition = actor ? actor->GetEditorPosition() : (*reinterpret_cast<::SaveInitialData85A520::SavePoint85A520 *>((void *)&::NiPoint3::ZERO));
                if (cellB)
                    cellA.cell = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((cellB))->FUN_0084e3a0())));
                else if (move)
                    cellA.cell = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((move))->FUN_0084e3a0())));
            }
            else
            {
                Actor85A520* point = (Actor85A520*)_FNV_DynamicCast(parent, 0, &(*reinterpret_cast<int *>(&::DAT_011841cc)), &(*reinterpret_cast<int *>(&::DAT_011846d4)), 0);
                if (point)
                    ::FUN_005b5e40();
                cellA.editorPosition = parent->GetEditorPosition();
                cellA.cell = 0;
                if (((::SaveInitialData85A520::SaveCell85A520 *)(reinterpret_cast<::LowProcess *>((parent))->GetTarget())))
                {
                    if (reinterpret_cast<::TESObjectCELL *>((((::SaveInitialData85A520::SaveCell85A520 *)(reinterpret_cast<::LowProcess *>((parent))->GetTarget()))))->IsCellInterior())
                        cellA.cell = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveInitialData85A520::SaveCell85A520 *)(reinterpret_cast<::LowProcess *>((parent))->GetTarget()))))->FUN_0084e3a0())));
                    else if (((::SaveInitialData85A520::SaveForm85A520 *)(reinterpret_cast<::TESObjectCELL *>((((::SaveInitialData85A520::SaveCell85A520 *)(reinterpret_cast<::LowProcess *>((parent))->GetTarget()))))->GetParentWorldSpace())))
                        cellA.cell = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveInitialData85A520::SaveForm85A520 *)(reinterpret_cast<::TESObjectCELL *>((((::SaveInitialData85A520::SaveCell85A520 *)(reinterpret_cast<::LowProcess *>((parent))->GetTarget()))))->GetParentWorldSpace()))))->FUN_0084e3a0())));
                }
            }
            cellA.savedLocation = savedLocation;
            reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream85A520*)(*reinterpret_cast<::FUN_008df040_cls * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&cellA, 44);
        }
        else
            reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream85A520*)(*reinterpret_cast<::FUN_008df040_cls * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&savedLocation, 28);
    }
    else if (flags & 0)
    {
        SaveCell85A520* world = ((::SaveInitialData85A520::SaveCell85A520 *)(reinterpret_cast<::LowProcess *>((parent))->GetTarget()));
        unsigned int id;
        SaveForm85A520* p = ((::SaveInitialData85A520::SaveForm85A520 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((parent))->FUN_00575d70()));
        if (p)
            id = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p))->FUN_0084e3a0())));
        else if (world)
            id = reinterpret_cast<::FUN_00861b70_Class *>(this)->FindOrAddValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((world))->FUN_0084e3a0())));
        else
            ::FUN_005b5e40();
        reinterpret_cast<::FUN_008579b0_shell *>((((SaveStream85A520*)(*reinterpret_cast<::FUN_008df040_cls * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&id, 4);
    }
}

}

namespace ChangeReport {

struct Form
{

    virtual void slot0();

    virtual void slot4();

    virtual void slot8();

    virtual void slotc();

    virtual void slot10();

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

    virtual void slot100();

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

    virtual const char* Name();
};
struct FullName
{
};
struct NamedForm
{
};

struct Entry
{
    unsigned int id;
    unsigned char type, flags0, flags1, flags2, flags3, version;
    unsigned short size;
};

struct Node
{
    Entry** FUN_006815c0();
};

struct Unknown
{
    unsigned int size, value;
};
struct UnknownNode
{
    Unknown** FUN_006815c0();
};

struct Map
{
};

struct File
{
    unsigned int unk0, unk4, unk8, unkc, unk10;
    File(const char*, int, int, int);
    ~File();
};

struct Stats
{
    int count, total;
    unsigned short smallest, largest;
    Stats();
};

struct Type
{
    unsigned int unk0;
    const char* name;
    unsigned int unk8;
};

struct Manager
{
};

int FUN_00406d50(char*, unsigned int, const char*);
int FUN_00456a20(const char*, int, int, int);

extern char DAT_01039788;

extern char DAT_01080428;


extern char DAT_01063d04;

extern char DAT_01044aec;

extern char DAT_0108041c;

extern char DAT_01080414;

extern char DAT_01080670;

extern char DAT_0104469c;

extern char DAT_01080668;


extern char DAT_010803e4;



extern char DAT_01080648;

extern char DAT_0108063c;

extern char DAT_010805d8;

extern char DAT_010805c4;

extern char DAT_01080254;

extern char DAT_01080570;

struct Main
{
    Map* map;
    UnknownNode* others;
    void FUN_00855ba0(const char*);
};

// Writes per-type form counts and size statistics, unknown-entry sizes and values, and overall totals to a file.
// @fnv 0x00855ba0
void Main::FUN_00855ba0(const char* filename)
{

    char pathSlot0[260];
    ::TaskQueueInterface::CopyStringToBuffer(pathSlot0, 260, filename);
    FUN_00406d50(pathSlot0, 260, &DAT_01039788);
    if (FUN_00456a20(pathSlot0, 0, 0, -1))
        ::FUN_00aff0b0(pathSlot0);

    File fileSlot15(pathSlot0, 1, 2, 0);
    if (::FUN_00559450((int *)&(fileSlot15)))
        return;

    Stats allSlot12;
    char buffer[520];
    ::FUN_00406d00(buffer, 520, &DAT_01080670, &DAT_01080414, &DAT_0108041c, &DAT_01044aec, &DAT_01063d04, &(*reinterpret_cast<char *>((void *)&::g_011d4e34_arg1)),
                 &DAT_01080428);
    reinterpret_cast<::FUN_00856300_cls *>(this)->FUN_00856300((::ProbeTarget *)(::ChangeReport::File *)(&fileSlot15), (int)(buffer));

    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((map))->GetFirstPos();
    while (position)
    {
        Node* listSlot16;
        unsigned char type;
        reinterpret_cast<::Map_00863bc0 *>((map))->GetNextItem((*(::Item_00863bc0 * *)(&position)), (*(unsigned char *)(&type)), (*(unsigned int *)(&listSlot16)));
        Node* node = listSlot16;
        char typeNameSlot0[10];

        if (!type)
            ::FUN_00406d00(typeNameSlot0, 10, &DAT_0104469c);
        else if (type == 121)
            ::FUN_00406d00(typeNameSlot0, 10, &DAT_01080668);
        else
            ::FUN_00406d00(typeNameSlot0, 10, &(*reinterpret_cast<char *>((void *)&::DAT_01019f08)), DAT_01187000[type].name);

        ::FUN_00406d00(buffer, 520, &DAT_010803e4, typeNameSlot0);
        unsigned __int64 lengthSlot33 = ::FUN_0044a670(buffer);
        reinterpret_cast<::FUN_00856300_cls *>(this)->FUN_00856300((::ProbeTarget *)(::ChangeReport::File *)(&fileSlot15), (int)(buffer));
        Stats statsSlot13;

        while (node)
        {
            Entry* entry = *((::ChangeReport::Entry **)(new ((void *)(node)) ::Vec3()));
            if (entry)
            {
                Form* formSlot19 = ((::ChangeReport::Form *)(::FUN_004839c0(entry->id)));
                if (entry->size > statsSlot13.largest)
                    statsSlot13.largest = entry->size;
                if (entry->size < statsSlot13.smallest)
                    statsSlot13.smallest = entry->size;
                statsSlot13.total += entry->size;
                statsSlot13.count++;

                char descriptionSlot0[500];
                reinterpret_cast<::fnv_0085b320::SaveFormatter *>(((*reinterpret_cast<::ChangeReport::Manager * *>(&::g_TESSaveLoadGame))))->FormatChangeFlags(descriptionSlot0, (::fnv_0085b320::SaveForm *)(formSlot19), *(unsigned int*)&entry->flags0, entry->type,
                                           0);
                const char* name = 0;
                FullName* fullSlot10 = (FullName*)::SaveInitialData85A520::_FNV_DynamicCast(
                    formSlot19, 0, &::DAT_01183028, &(*reinterpret_cast<char *>(&::DAT_01183158)), 0);
                NamedForm* namedSlot10 = (NamedForm*)::SaveInitialData85A520::_FNV_DynamicCast(
                    formSlot19, 0, &::DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_011841cc)), 0);

                if (formSlot19)
                {
                    if (namedSlot10)
                        name = reinterpret_cast<::FUN_0055d520_shell *>((namedSlot10))->FUN_0055d520();
                    if (fullSlot10 && (!name || !::FUN_00408b20(name, &(*reinterpret_cast<char *>((void *)&::DAT_01011584)))))
                        name = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((fullSlot10))->FUN_00408da0()));
                    if (!name || !::FUN_00408b20(name, &(*reinterpret_cast<char *>((void *)&::DAT_01011584))))
                        name = formSlot19->Name();
                    ::FUN_00406d00(buffer, 520, &DAT_01080648, entry->id, entry->size, *(unsigned int*)&entry->flags0,
                                 entry->version, name, descriptionSlot0);
                }
                else
                    ::FUN_00406d00(buffer, 520, &DAT_01080648, entry->id, entry->size, *(unsigned int*)&entry->flags0,
                                 entry->version, &DAT_0108063c, descriptionSlot0);

                reinterpret_cast<::FUN_00856300_cls *>(this)->FUN_00856300((::ProbeTarget *)(::ChangeReport::File *)(&fileSlot15), (int)(buffer));
            }

            node = ((::ChangeReport::Node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }

        ::FUN_00406d00(buffer, 520, &DAT_010805d8, typeNameSlot0, statsSlot13.count, typeNameSlot0, statsSlot13.total,
                     typeNameSlot0, statsSlot13.smallest, typeNameSlot0, statsSlot13.largest, typeNameSlot0,
                     (float)statsSlot13.total / statsSlot13.count);
        reinterpret_cast<::FUN_00856300_cls *>(this)->FUN_00856300((::ProbeTarget *)(::ChangeReport::File *)(&fileSlot15), (int)(buffer));

        if (statsSlot13.largest > allSlot12.largest)
            allSlot12.largest = statsSlot13.largest;
        if (statsSlot13.smallest < allSlot12.smallest)
            allSlot12.smallest = statsSlot13.smallest;
        allSlot12.total += statsSlot13.total;
        allSlot12.count += statsSlot13.count;
    }

    reinterpret_cast<::FUN_00856300_cls *>(this)->FUN_00856300((::ProbeTarget *)(::ChangeReport::File *)(&fileSlot15), (int)(&DAT_010805c4));
    UnknownNode* unknownNodeSlot24 = others;
    while (unknownNodeSlot24)
    {
        Unknown* unknown = *((::ChangeReport::Unknown **)(new ((void *)(unknownNodeSlot24)) ::Vec3()));
        if (unknown)
        {
            ::FUN_00406d00(buffer, 520, &DAT_01080254, unknown->size, unknown->value);
            reinterpret_cast<::FUN_00856300_cls *>(this)->FUN_00856300((::ProbeTarget *)(::ChangeReport::File *)(&fileSlot15), (int)(buffer));
            allSlot12.total += unknown->size;
        }
        unknownNodeSlot24 = ((::ChangeReport::UnknownNode *)(reinterpret_cast<::Callees *>((unknownNodeSlot24))->FUN_00726070()));
    }

    ::FUN_00406d00(buffer, 520, &DAT_01080570, allSlot12.count, allSlot12.total, allSlot12.smallest, allSlot12.largest,
                 (float)allSlot12.total / allSlot12.count);
    reinterpret_cast<::FUN_00856300_cls *>(this)->FUN_00856300((::ProbeTarget *)(::ChangeReport::File *)(&fileSlot15), (int)(buffer));
}

}

class FormMethods77
{
  public:
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
    virtual void SetID(unsigned int, int);
    int unk04, unk08, unk0c, unk10, unk14;
};
struct CreatedForm77
{
    virtual void v00();
    int unk04, unk08, unk0c, unk10, unk14;
};
struct TESBoundObject : public TESForm
{
  public:
    int FUN_00401170();
};
class TESObjectREFR : public TESForm
{
  public:
};
struct NPC77 : CreatedForm77
{
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
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    NPC77();
};
struct Creature77 : CreatedForm77
{
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
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    Creature77();
};
struct Reference77 : CreatedForm77
{
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
    Reference77();
};
struct Projectile77 : CreatedForm77
{
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
    Projectile77();
};
struct Missile77 : CreatedForm77
{
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
    Missile77();
};
struct Beam77 : CreatedForm77
{
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
    Beam77();
};
struct Flame77 : CreatedForm77
{
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
    Flame77();
};

enum MEM_CONTEXT;

struct Record77
{
    int type;
    unsigned int object, location;
};
struct Save77
{
    TESForm* FUN_00859a90(unsigned int, Record77*);
};
// Looks up or creates a TESForm from the record and initializes it according to its type.
// @fnv 0x00859a90
TESForm* Save77::FUN_00859a90(unsigned int id, Record77* record)
{
    AutoMemContext scope6(static_cast<MEM_CONTEXT>(49), true, (*reinterpret_cast<const char (*)[]>(&::SaveManager::DAT_010804c8)), 0x133b);
    TESForm* pForm = (TESForm*)((::ExpiredReference *)(::FUN_004839c0(id)));
    TESBoundObject* bound28 = 0;
    if (record->type != 2)
    {
        bound28 = dynamic_cast<TESBoundObject*>((TESForm*)((::ExpiredReference *)(::FUN_004839c0(record->object))));
        if (!bound28)
        {
            ::FUN_005b5e40();
            return 0;
        }
    }
    if (pForm)
    {
        TESObjectREFR* reference = dynamic_cast<TESObjectREFR*>(pForm);
        if (!reference || (record->type != 0 && record->type != 3) || ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) != bound28)
        {
            reinterpret_cast<::FUN_0085a2e0_Class *>(this)->FUN_0085a2e0(pForm);
            pForm = 0;
        }
    }
    if (!pForm)
    {
        if (record->type == 0 || record->type == 3)
        {
            switch (bound28->FUN_00401170())
            {
            case 42:
                pForm = (TESForm*)new NPC77;
                break;
            case 43:
                pForm = (TESForm*)new Creature77;
                break;
            default:
                pForm = (TESForm*)new Reference77;
                break;
            }
            TESObjectREFR* reference = dynamic_cast<TESObjectREFR*>(pForm);
            reinterpret_cast<::Fn575690 *>((reference))->FUN_00575690(bound28);
            ((FormMethods77*)pForm)->SetID(id, 1);
        }
        else if (record->type == 1)
        {
            pForm = (TESForm*)new Projectile77;
            TESObjectREFR* reference = dynamic_cast<TESObjectREFR*>(pForm);
            reinterpret_cast<::Fn575690 *>((reference))->FUN_00575690(bound28);
            ((FormMethods77*)pForm)->SetID(id, 1);
        }
        else if (record->type == 2)
        {
            TESForm* projectile = 0;
            switch (record->object)
            {
            case 0:
                projectile = (TESForm*)new Missile77;
                break;
            case 3:
                projectile = (TESForm*)new Beam77;
                break;
            case 1:
                projectile = (TESForm*)new Flame77;
                break;
            }
            pForm = projectile;
            ((FormMethods77*)pForm)->SetID(id, 1);
        }
        else
            ::FUN_005b5e40(
                );
    }
    if (pForm)
        reinterpret_cast<::FUN_0046a010_shell *>((((FormMethods77*)pForm)))->FUN_0046a010(1);
    return pForm;
}



// Constructor: base list (10 slots, grow 1, entry size 0x78), counters cleared, a helper object
// allocated through the class operator new, and the first entry's payload cached.
struct MemoryManagerL
{
};

struct EntryL
{
    unsigned int m_00;
    unsigned int m_04;
    void* m_pData;
};

struct BaseListL
{
    void* m_vtbl;
    unsigned int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c, m_40, m_44,
        m_48, m_4c;
    EntryL** m_ppEntries;
    unsigned int m_54, m_58, m_5c;
    BaseListL(int, int, int);
    ~BaseListL();
    EntryL* GetAt(unsigned int i)
    {
        return m_ppEntries[i];
    }
    void* GetDataAt(unsigned int i)
    {
        return m_ppEntries[i]->m_pData;
    }
};

struct HelperL
{
    unsigned int m_00, m_04, m_08, m_0c;
    HelperL(int, int, int);
};

extern int DAT_010c1604;

struct FUN_00c3da50 : BaseListL
{
    void* m_pFirstData;
    HelperL* m_pHelper;
    unsigned int m_68, m_6c, m_70, m_74, m_78, m_7c, m_80;
    FUN_00c3da50();
};

// @fnv 0x00c3da50
FUN_00c3da50::FUN_00c3da50() : BaseListL(10, 1, 120)
{
    m_vtbl = &DAT_010c1604;
    m_70 = 0;
    m_78 = 0;
    m_6c = 0;
    m_7c = 0;
    m_80 = 0;
    m_68 = 6;
    m_pHelper = new HelperL(6, 7, 8);
    m_pFirstData = GetDataAt(0);
}

extern "C" void FUN_0044dd60(void* p);

extern "C" long InterlockedCompareExchange(long volatile* dest, long exchange, long comparand);

class BSSpinLockS
{
  public:
    unsigned int threadID;
    int lockCount;
    void Unlock()
    {
        if (--lockCount == 0)
            threadID = 0;
    }
};

struct Node006c6fe0
{
    Node006c6fe0* next;
    void* value;
};

struct Ops006c6fe0
{
    Node006c6fe0* node;
    Ops006c6fe0* next;
    Ops006c6fe0* tail;
    void notify(void* owner);
};

struct C006c6fe0
{
    Ops006c6fe0* ops;
    Ops006c6fe0** published;
    Node006c6fe0** pending;
    bool TryDequeue()
    {
        Ops006c6fe0* cur;
        Ops006c6fe0* tail;
        Node006c6fe0* node;
        Node006c6fe0* old;
        long expected;
        long result;
        long current;
        long compare;
        long outcome;
        bool ok;
        for (;;)
        {
            cur = ops->next;
            *published = cur;
            if (cur != ops->next)
                continue;
            tail = ops->tail;
            node = cur->node;
            *pending = node;
            if (cur->next != cur)
                continue;
            if (node == 0)
            {
                *published = 0;
                old = *pending;
                if (old != 0)
                {
                    FUN_0044dd60(old->value);
                    *pending = 0;
                }
                return false;
            }
            if (cur == tail)
            {
                expected = 0;
                result = InterlockedCompareExchange((long volatile*)&ops->tail, (long)node, expected);
                if (result != 0)
                    continue;
                continue;
            }
            current = (long)cur;
            compare = (long)tail;
            outcome = InterlockedCompareExchange((long volatile*)&cur->next, current, compare);
            ok = outcome == current;
            if (!ok)
                continue;
            ops->notify(this);
            return true;
        }
    }
};

struct C00449f80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* unk14;
    C006c6fe0* FUN_00449f80(unsigned int a);
};

struct S_00c3e490_ob1 : C00449f80
{
    int unk18;
    int unk1c;
    BSSpinLockS m_lock;
    bool FUN_00c3e490(unsigned int a);
};

// @fnv 0x00c3e490
bool S_00c3e490_ob1::FUN_00c3e490(unsigned int a)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_lock))->FUN_0040fbf0((char *)(0));
    bool r = reinterpret_cast<::Worker *>((FUN_00449f80(a)))->TryDequeue({});
    m_lock.Unlock();
    return r;
}

struct MemoryManager
{
};

inline unsigned int GetCurrentContext()
{
    return ::currentAllocationContext;
}

inline void SetCurrentContext(unsigned int context)
{
    ::currentAllocationContext = context;
}

struct HeapContextGuard
{
    unsigned int previous;
    HeapContextGuard(unsigned int context)
    {
        previous = GetCurrentContext();
        SetCurrentContext(context);
    }
    ~HeapContextGuard()
    {
        SetCurrentContext(previous);
    }
};

inline void* operator new[](std::size_t n, MemoryManager*)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&(g_memoryManager))->FUN_00aa3e40(n);
}

inline void* operator new(std::size_t n, MemoryManager*)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&(g_memoryManager))->FUN_00aa3e40(n);
}

void operator delete(void*, MemoryManager*);

struct ArchiveFileManager
{
    virtual ~ArchiveFileManager()
    {}
};

struct Pair20
{
    int a;
    int b;
    Pair20()
    {
        a = 0;
        b = 0;
    }
};

struct FUN_00c42180
{
    int a, b, c, d;
    FUN_00c42180(unsigned int);
};

struct PointerEntry
{
    void* value;
    void Clear()
    {
        PointerEntry* self = this;
        self->value = 0;
    }
};

__forceinline void InitializeLoop(PointerEntry* cursor, int remaining)
{
    while (--remaining >= 0)
    {
        cursor->Clear();
        ++cursor;
    }
}
__forceinline PointerEntry* InitializeEntries(PointerEntry* allocation, const unsigned int& count)
{
    return allocation ? (InitializeLoop(allocation, count), allocation) : 0;
}

struct FUN_00c3ec80 : ArchiveFileManager
{
    void** unk04;
    unsigned int unk08;
    void** unk0c;
    unsigned int unk10;
    FUN_00c42180* unk14;
    int unk18;
    int unk1c;
    Pair20 unk20;
    FUN_00c3ec80(unsigned int a, unsigned int b, unsigned int c);
    virtual ~FUN_00c3ec80();
};

// @fnv 0x00c3ec80
FUN_00c3ec80::FUN_00c3ec80(unsigned int a, unsigned int b, unsigned int c)
{
    HeapContextGuard context4_2(6);
    unk18 = 0;
    unk08 = b;
    unsigned int count2 = unk08;
    PointerEntry* entries3 = InitializeEntries((PointerEntry*)new (&g_memoryManager) void*[count2], count2);
    unk0c = (void**)entries3;
    unk04 = new (&g_memoryManager) void*[a * 3];
    unk10 = c;
    unk14 = new (&g_memoryManager) FUN_00c42180(a);
}

class MemoryManagerC4
{
  public:
};

template <class T> inline void ZeroArrayC4(T* pkArray, unsigned int ItemUpdateArray)
{
    memset(pkArray, 0, ItemUpdateArray * sizeof(T));
}

class BaseQueueC4
{
  public:
    BaseQueueC4(unsigned int uiTotal, unsigned int ItemUpdateArray, unsigned int uiStride);
    virtual ~BaseQueueC4();
    char m_acPad[0x40 - 4];
};

class FUN_00c3e4f0;

class WorkerC4
{
  public:
    WorkerC4(FUN_00c3e4f0* pkOwner, unsigned int uiID);
    char m_acData[0x34];
};

class FUN_00c3e4f0 : public BaseQueueC4
{
  public:
    FUN_00c3e4f0(unsigned int uiReserved, unsigned int uiWorkers, unsigned int uiSlots);
    virtual ~FUN_00c3e4f0();
    bool m_bStopped;
    unsigned int m_uiCount44;
    unsigned int m_uiCount48;
    unsigned int m_uiWorkers;
    WorkerC4** m_ppkWorkers;
    void** m_ppvSlots;
    unsigned int m_uiCount58;
};

// @fnv 0x00c3e4f0
FUN_00c3e4f0::FUN_00c3e4f0(unsigned int uiReserved, unsigned int uiWorkers, unsigned int uiSlots)
    : BaseQueueC4(uiReserved + uiWorkers, uiSlots, 0xc)
{
    m_bStopped = false;
    m_uiCount44 = 0;
    m_uiCount48 = 0;
    m_uiWorkers = uiWorkers;
    m_ppvSlots = new void*[uiSlots];
    ZeroArrayC4(m_ppvSlots, uiSlots);
    m_uiCount58 = 0;
    m_ppkWorkers = new WorkerC4*[m_uiWorkers];
    for (unsigned int i = 0; i < m_uiWorkers; i++)
    {
        m_ppkWorkers[i] = new WorkerC4(this, i + 2);
        reinterpret_cast<::TaskThreadResume *>((m_ppkWorkers[i]))->FUN_00c42f50();
    }
}

namespace fnv_00c3e8b0 {
struct ThreadDataC3
{
    char m_acPad[0x2b4];
    int m_iMemContext;
};

inline int GetMemContextC3()
{
    return (*reinterpret_cast<::fnv_00c3e8b0::ThreadDataC3 *>(&::g_tlsBlock)).m_iMemContext;
}

inline void SetMemContextC3(int aiMemoryContext)
{
    (*reinterpret_cast<::fnv_00c3e8b0::ThreadDataC3 *>(&::g_tlsBlock)).m_iMemContext = aiMemoryContext;
}

class MemContextScopeC3
{
  public:
    inline MemContextScopeC3(int aiMemoryContext)
    {
        m_iOld = GetMemContextC3();
        SetMemContextC3(aiMemoryContext);
    }
    inline ~MemContextScopeC3()
    {
        SetMemContextC3(m_iOld);
    }
    int m_iOld;
};

class MemoryManagerC3
{
  public:
};


class IOQueueC3
{
  public:
    IOQueueC3(void* pvA, void* pvB);
    char m_acData[0x40];
};

class FUN_00c3e8b0
{
  public:
    FUN_00c3e8b0(unsigned int uiSize, void* pvA, void* pvB);
    virtual ~FUN_00c3e8b0();
    IOQueueC3** m_ppkQueues;
    unsigned int m_uiSize;
    unsigned int m_uiCount;
};

extern const void* const g_apvLockFreePriorityQueueVtblC3[];

// @fnv 0x00c3e8b0
FUN_00c3e8b0::FUN_00c3e8b0(unsigned int uiSize, void* pvA, void* pvB)
{
    MemContextScopeC3 kScope(6);
    m_uiCount = 0;
    m_uiSize = uiSize;
    m_ppkQueues = new IOQueueC3*[m_uiSize];
    for (unsigned int i = 0; i < m_uiSize; i++)
        m_ppkQueues[i] = new IOQueueC3(pvA, pvB);
}
}

#include "generated/data/fallout_shared/tessaveloadgame.inc"
