
#include <new>
#include <cstring>
#include "fnv/decl/Actor.h"
#include "fnv/decl/ActorDeletionQueue.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/CreatureEquipment.h"
#include "fnv/decl/Dfcfa0Manager.h"
#include "fnv/decl/FUN_00437b90_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_00471f80_shell.h"
#include "fnv/decl/FUN_00472000_class.h"
#include "fnv/decl/FUN_00472150_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_005441b0_S.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/FUN_00550890_shell.h"
#include "fnv/decl/FUN_00565450_shell.h"
#include "fnv/decl/FUN_005ca4f0_shell.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_00692480.h"
#include "fnv/decl/FUN_0069b8a0_cls.h"
#include "fnv/decl/FUN_006f3170_Class.h"
#include "fnv/decl/FUN_00841250_cls.h"
#include "fnv/decl/FUN_00843150_shell.h"
#include "fnv/decl/FUN_00843170_shell.h"
#include "fnv/decl/FUN_008431c0_Class.h"
#include "fnv/decl/FUN_00844590.h"
#include "fnv/decl/FUN_00844690_class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_00844970_class.h"
#include "fnv/decl/FUN_00845610_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00869600_Class.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00aa54a0_s.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/Outer.h"
#include "fnv/decl/SHStub.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/StandIn.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESNPC.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Walker8.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00567490__ScaleReference.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00486000.h"
#include "fnv/symbols_00544000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_00846000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0107e000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011e0000.h"
#include "bgsreconstructformsinallfilesmap_decls.h"

// Empty destructor for the reconstruct-forms-in-all-files map object.
// @fnv 0x00843540
FormChangeMap::~FormChangeMap()
{}

// @fnv 0x008455b0
BGSSaveLoadChangesMap::~BGSSaveLoadChangesMap()
{
    reinterpret_cast<::FUN_00845610_shell *>(this)->DeleteAllChanges();
}

// @fnv 0x008434d0
BGSReconstructFormsInAllFilesMap::~BGSReconstructFormsInAllFilesMap()
{
    Clear();
}

// @fnv 0x008433d0
BGSReconstructFormsInAllFilesMap::BGSReconstructFormsInAllFilesMap()
    : BGSReconstructFormsInAllFilesMapBase(0x25), m_kFormChangeMap(), iCount(0)
{}

struct S3240
{
    char pad[0x10];
    void Resize(int, int);
    void FUN_00843240();
};
// Deletes every file map returned by GetNext, then clears the pointer map, calls FUN_00843240 and resets iCount to 0.
// @fnv 0x008435a0
void BGSReconstructFormsInAllFilesMap::Clear()
{
    void* position = GetFirstPos();
    while (position)
    {
        TESFile* file = 0;
        BGSReconstructFormsInFileMap* map = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(file), (void **)&(map));
        delete map;
    }
    reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(this)))->FUN_00438af0();
    reinterpret_cast<::S3240 *>(&(m_kFormChangeMap))->FUN_00843240();
    iCount = 0;
}
// Calls Resize(0, 1) on this and on the object at offset 0x10.
// @fnv 0x00843240
void S3240::FUN_00843240()
{
    Resize(0, 1);
    reinterpret_cast<S3240*>(reinterpret_cast<char*>(this) + 0x10)->Resize(0, 1);
}

struct FUN_00843bb0_shell : public FormChangeMap
{
    unsigned int GetCombinedFlags();
};

struct TESObjectREFR_GetFlags_caller : public TESObjectREFR
{
};

// Returns the sum of the flags from the TESObjectREFR at offset 0x0 and the one at offset 0x10.
// @fnv 0x00843bb0
unsigned int FUN_00843bb0_shell::GetCombinedFlags()
{
    return ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_caller*)((char*)this + 0x0))))->GetName())) +
           ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR_GetFlags_caller*)&this->m_kSpecialFormChanges)))->GetName()));
}

extern int DAT_01031fac;

struct FUN_00844130_arg
{
    unsigned int val;
};

void FUN_005890c0(int* self, FUN_00844130_arg a);

// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00844130
int* FUN_00844130(int* self, FUN_00844130_arg a)
{
    FUN_005890c0(self, a);
    *self = (int)&DAT_01031fac;
    return self;
}

extern int DAT_0107ed08;

class SaveGameSizeState
{
  public:
    void RecordRequestedSize(unsigned int, unsigned int);
};

// @fnv 0x00844a90
void* SaveGameSizeStateConstructor(void* pThis)
{
    *reinterpret_cast<int**>(pThis) = &DAT_0107ed08;
    reinterpret_cast<SaveGameSizeState*>(pThis)->RecordRequestedSize(0, 0);
    return pThis;
}

class GlobalObject_00869f00
{
  public:
};

extern int DAT_0107ed08;

// @fnv 0x00844ac0
void FUN_00844ac0(GlobalObject_00869f00* _this)
{
    *(int**)_this = &DAT_0107ed08;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((_this))->Clear(true);
}


struct FUN_009a5df0
{
    virtual void dummy();
    ~FUN_009a5df0();
};

struct FUN_00844e20 : FUN_009a5df0
{
    ~FUN_00844e20();
};

// Destructor that forwards to DeleteAllEntries with this as the argument.
// @fnv 0x00844e20
FUN_00844e20::~FUN_00844e20()
{
    reinterpret_cast<::FUN_00438af0_Class *>((this))->FUN_00438af0();
}

struct ScrapHeapBuffer
{
};
struct OffsetData
{
    unsigned int iOffset;
    void* m_pFormLookupMap;
};
struct FUN_006db9b0_s
{
    char pad[0x10];
    ScrapHeapBuffer* m_pAllocator;
    OffsetData* AllocateOffsetData(unsigned int aiSizeInItem);
};
// @fnv 0x006db9b0
OffsetData* FUN_006db9b0_s::AllocateOffsetData(unsigned int aiSizeInItem)
{
    OffsetData* pnewBuffer;
    pnewBuffer = (OffsetData*)reinterpret_cast<::FUN_00aa54a0_s *>((m_pAllocator))->FUN_00aa54a0(aiSizeInItem * 8, DAT_010a2720);
    return pnewBuffer;
}

struct FUN_00841320_shell
{
    void FUN_00841320(int arg);
};

// @fnv 0x00841320
void FUN_00841320_shell::FUN_00841320(int arg)
{
    *(int*)((char*)this + 0x10) |= arg;
}

struct FUN_00844070_standin
{
};

struct FUN_00842180 : FUN_00844070_standin
{
    void* vtable;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0C;
    void* field_10;
    void* field_14;
    unsigned int field_18;

    FUN_00842180();
};

extern void* DAT_0107e9d0;

struct FUN_00844fc0_shell
{
    void* FUN_00844fc0(int arg);
};

// Allocates arg << 3 bytes via operator new and returns the pointer.
// @fnv 0x00844fc0
void* FUN_00844fc0_shell::FUN_00844fc0(int arg)
{
    void* p = ::FUN_00401000(arg << 3);
    return p;
}

struct BGSReconstructFormsMap
{
    void FUN_008411f0();
    void* FUN_008411c0(unsigned int flags);
};


struct BGSReconstructCellsMap
{
    void FUN_008413a0();
    void* FUN_00841370(unsigned int flags);
};



struct BGSReconstructCellSubBlocksMap
{
    virtual ~BGSReconstructCellSubBlocksMap();
    void* ScalarDeletingDestructor(unsigned int flags);
};

struct S006950d0
{
    unsigned int GetElement(unsigned int);
};

struct FUN_00844160_shell
{
    unsigned int FUN_00844160(unsigned int);
};

// @fnv 0x00844160
unsigned int FUN_00844160_shell::FUN_00844160(unsigned int a)
{
    return ((S006950d0*)this)->GetElement(a);
}

namespace fnv_00844180 {

struct FUN_00844180_shell
{
    void FUN_00844470();
    void* FUN_00844180(unsigned int flags);
};

// Calls FUN_00844470, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00844180
void* FUN_00844180_shell::FUN_00844180(unsigned int flags)
{
    FUN_00844470();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00844180


struct FUN_00844270_shell : BGSReconstructFormsInAllFilesMapBase
{
    void* FUN_00844270(unsigned int flags);
};

// @fnv 0x00844270
void* FUN_00844270_shell::FUN_00844270(unsigned int flags)
{
    reinterpret_cast<::FUN_00844e20 *>(this)->FUN_00844e20::~FUN_00844e20();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00845260_holder
{
};

struct FUN_00844500_shell
{
    void ForwardToHolder();
};

// @fnv 0x00844500
void FUN_00844500_shell::ForwardToHolder()
{
    reinterpret_cast<::FUN_0069b8a0_cls *>((((FUN_00845260_holder*)((char*)this + 0xc))))->CreateObj_00845260();
}

namespace fnv_00844fa0 {
struct GlobalObject_00869f00
{
    void* m_p;
};


struct FUN_00844fa0_shell
{
    void* m_p;
    void InitGlobalObject();
};

// @fnv 0x00844fa0
void FUN_00844fa0_shell::InitGlobalObject()
{
    m_p = &::DAT_0107ed50;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_00844fa0

struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
struct FUN_00416870_shell : public NiPoint3
{
    void FUN_00416870(float, float, float);
};

struct FUN_00416870_t : public NiPoint3
{
    FUN_00416870_t* FUN_00416870(float, float, float);
};
// Sets the point's x, y and z components from the three arguments and returns this.
// @fnv 0x00416870
FUN_00416870_t* FUN_00416870_t::FUN_00416870(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
    return this;
}

struct FUN_00844040
{
    virtual void Unused();
    int m04;
    int m08;
    int m0C;
    FUN_00844040(int);
};
struct FUN_00841190 : FUN_00844040
{
    int m10;
    FUN_00841190();
};
// Initializes the base with 0x25 and sets m10 to 0.
// @fnv 0x00841190
FUN_00841190::FUN_00841190() : FUN_00844040(0x25)
{
    m10 = 0;
}

namespace fnv_00841340 {
struct FUN_00844070_standin
{
    void FUN_00844070(int);
};
extern int DAT_0107e950;
struct FUN_00841340_standin : FUN_00844070_standin
{
    void* FUN_00841340();
};
// Calls FUN_00844070 with 0x25, stores the address of DAT_0107e950 into this, and returns this.
// @fnv 0x00841340
void* FUN_00841340_standin::FUN_00841340()
{
    FUN_00844070(0x25);
    *(int*)this = (int)&DAT_0107e950;
    return this;
}
}  // namespace fnv_00841340

struct FUN_00452420_shell
{
    bool GetFlag(unsigned int) const;
};
struct FUN_00841660_shell : BGSReconstructFormsInAllFilesMap
{
    bool HasFileMapWithFlag(unsigned int aiFlags);
};
// Iterates the map's entries and returns true if any file map's GetFlag(aiFlags) is set.
// @fnv 0x00841660
bool FUN_00841660_shell::HasFileMapWithFlag(unsigned int aiFlags)
{
    void* it;
    BGSReconstructFormsInFileMap* pformsMap;
    TESFile* icellKey;
    it = GetFirstPos();
    while (it != 0)
    {
        icellKey = 0;
        pformsMap = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(it), (unsigned int *)&(icellKey), (void **)&(pformsMap));
        if (((FUN_00452420_shell*)pformsMap)->GetFlag(aiFlags))
            return true;
    }
    return false;
}

struct FUN_008440a0
{
    FUN_008440a0(int);
};
extern int DAT_0107e970;
struct FUN_008416c0 : FUN_008440a0
{
    FUN_008416c0();
};
// @fnv 0x008416c0
FUN_008416c0::FUN_008416c0() : FUN_008440a0(0x25)
{
    *(int*)this = (int)&DAT_0107e970;
}

namespace fnv_00841990 {
struct BGSReconstructCellsMap
{
};
struct BGSReconstructCellSubBlocksMap
{
    bool HasCellWithFlag(unsigned int);
};
// Iterates the map's entries and returns true as soon as a contained cells map reports the given flags via HasFileMapWithFlag.
// @fnv 0x00841990
bool BGSReconstructCellSubBlocksMap::HasCellWithFlag(unsigned int aiFlags)
{
    void* it;
    unsigned int pFile;
    BGSReconstructCellsMap* pcellsMap;
    it = ((BGSReconstructFormsInAllFilesMap*)this)->GetFirstPos();
    while (it != 0)
    {
        pFile = 0;
        pcellsMap = 0;
        reinterpret_cast<::C6b7f20_Map *>((((BGSReconstructFormsInAllFilesMap*)this)))->FUN_006b7f20((::C6b7f20_Node **)&(it), (unsigned int *)&((TESFile*&)pFile), (void **)&((BGSReconstructFormsInFileMap*&)pcellsMap));
        if (reinterpret_cast<::FUN_00841660_shell *>((pcellsMap))->HasFileMapWithFlag(aiFlags))
            return true;
    }
    return false;
}
}  // namespace fnv_00841990

struct FUN_008440d0
{
    virtual void Unk();
    int _04;
    int _08;
    int _0C;
    FUN_008440d0(int);
};
struct FUN_008419f0 : FUN_008440d0
{
    int _10;
    bool _14;
    FUN_008419f0(bool);
};
// Initializes the base with 0x25, sets _10 to 0 and stores the bool argument in _14.
// @fnv 0x008419f0
FUN_008419f0::FUN_008419f0(bool a) : FUN_008440d0(0x25)
{
    _10 = 0;
    _14 = a;
}

struct BGSReconstructCellBlocksMap
{
    void FUN_00841a60();
    void* FUN_00841a30(unsigned int);
};
struct Base00841ea0
{
};
extern int DAT_0107e9b0;
struct FUN_00841ea0 : Base00841ea0
{
    FUN_00841ea0();
};
struct BGSReconstructWorldSpacesMap
{
    void* FUN_00841ed0(unsigned int);
};
struct Host008421c0
{
    void FUN_008421f0();
    void* FUN_008421c0(unsigned int);
};
// @fnv 0x008421c0
void* Host008421c0::FUN_008421c0(unsigned int flags)
{
    FUN_008421f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_008432e0 {
struct ArrSI
{
};
struct FUN_00844160_shell
{
};
struct FUN_008432e0_Host
{
    unsigned int FUN_008432e0(unsigned int);
};
// @fnv 0x008432e0
unsigned int FUN_008432e0_Host::FUN_008432e0(unsigned int auiIndex)
{
    unsigned int flags = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName()));
    if (auiIndex < flags)
    {
        return reinterpret_cast<::FUN_00844160_shell *>((((FUN_00844160_shell*)this)))->FUN_00844160(auiIndex);
    }
    else
    {
        return reinterpret_cast<::FUN_00844160_shell *>((((FUN_00844160_shell*)((char*)this + 16))))->FUN_00844160(auiIndex - flags);
    }
}
}  // namespace fnv_008432e0

namespace fnv_00843330 {
struct ArrSI
{
    unsigned int GetElementAt(unsigned int);
};
struct FUN_00844160_shell
{
};
// Returns the element at index from this array if index is below GetFlags(), otherwise from the array at offset 0x10 with index minus flags.
// @fnv 0x00843330
unsigned int ArrSI::GetElementAt(unsigned int index)
{
    unsigned int flags = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
    if (index < flags)
    {
        return *(unsigned int*)reinterpret_cast<::FUN_00844160_shell *>((((FUN_00844160_shell*)this)))->FUN_00844160(index);
    }
    else
    {
        return *(unsigned int*)reinterpret_cast<::FUN_00844160_shell *>((((FUN_00844160_shell*)((char*)this + 0x10))))->FUN_00844160(index - flags);
    }
}
}  // namespace fnv_00843330

struct Base00844c90
{
    char data[16];
    void FUN_00844c90(unsigned int, int);
};
struct ArrSI : Base00844c90
{
    Base00844c90 second;
    bool FUN_00843380(unsigned int);
};
// @fnv 0x00843380
bool ArrSI::FUN_00843380(unsigned int auiIndex)
{
    unsigned int flags = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
    if (auiIndex < flags)
    {
        FUN_00844c90(auiIndex, 1);
    }
    else
    {
        second.FUN_00844c90(auiIndex - flags, 1);
    }
    return true;
}

class TESFile;
class TESForm;
template <typename T> class BSSimpleList;
unsigned int __cdecl GetOwnerFileByID(unsigned int);
struct FUN_00485b60
{
};
struct TESDataHandlerSaveLoad
{
};
struct FUN_00843fe0_Holder
{
    TESFile* FUN_00843fe0(BSSimpleList<TESFile*>* apFileList, unsigned int aiFormID);
};
// @fnv 0x00843fe0
TESFile* FUN_00843fe0_Holder::FUN_00843fe0(BSSimpleList<TESFile*>* apFileList, unsigned int aiFormID)
{
    TESFile* pfile;
    TESForm* pform;
    pform = ::FUN_004839c0(aiFormID);
    if (pform)
    {
        return reinterpret_cast<::TESForm *>((((FUN_00485b60*)pform)))->GetFile(-1);
    }
    pfile = (TESFile*)GetOwnerFileByID(aiFormID);
    if (pfile)
    {
        return pfile;
    }
    return reinterpret_cast<::TESDataHandler *>((((TESDataHandlerSaveLoad*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetCompiledFileByIndex(aiFormID >> 24);
}

namespace fnv_00844040 {
extern int DAT_0107eba8;
struct S008442a0
{
    void FUN_008442a0(int);
};
struct FUN_00844040
{
    int vfptr;
    FUN_00844040(int);
};
// Calls FUN_008442a0 on this with a, then sets vfptr to the address of DAT_0107eba8.
// @fnv 0x00844040
FUN_00844040::FUN_00844040(int a)
{
    ((S008442a0*)this)->FUN_008442a0(a);
    vfptr = (int)&DAT_0107eba8;
}
}  // namespace fnv_00844040

extern int DAT_0107ebc8;
struct S_844070
{
    S_844070* FUN_00844070(int);
};
// Calls the base constructor with 0x25, installs the vtable, and zeroes fields at offsets 0x10, 0x14 and 0x18.
// @fnv 0x00842180
FUN_00842180::FUN_00842180()
{
    reinterpret_cast<::S_844070 *>(this)->FUN_00844070(0x25);
    vtable = &DAT_0107e9d0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
}
// Calls FUN_00844590 with a, stores the address of DAT_0107ebc8 into this, and returns this.
// @fnv 0x00844070
S_844070* S_844070::FUN_00844070(int a)
{
    new ((void *)this) ::FUN_00844590(a);
    *(int*)this = (int)&DAT_0107ebc8;
    return this;
}

extern int DAT_0107ebe8;
struct C008440a0
{
    int m0;
    C008440a0* FUN_008440a0(int);
};
// Calls FUN_00844690 with a, stores the address of DAT_0107ebe8 in m0, and returns this.
// @fnv 0x008440a0
C008440a0* C008440a0::FUN_008440a0(int a)
{
    reinterpret_cast<::FUN_00844690_class *>(this)->FUN_00844690(a);
    m0 = (int)&DAT_0107ebe8;
    return this;
}

extern int DAT_0107ec08;
struct S008440d0
{
    int field0;
    void FUN_00844870(int);
    S008440d0* FUN_008440d0(int);
};
// Calls FUN_00844870 with a, stores the address of DAT_0107ec08 in field0, and returns this.
// @fnv 0x008440d0
S008440d0* S008440d0::FUN_008440d0(int a)
{
    FUN_00844870(a);
    field0 = (int)&DAT_0107ec08;
    return this;
}

extern int DAT_0107ec28;
struct C844100
{
    int* f0;
    C844100* FUN_00844100(int);
};
// Calls FUN_00844100 with 0x25, then stores the address of DAT_0107e9b0 into the object's first field.
// @fnv 0x00841ea0
FUN_00841ea0::FUN_00841ea0()
{
    reinterpret_cast<::C844100 *>(this)->FUN_00844100(0x25);
    *(int*)this = (int)&DAT_0107e9b0;
}
// Calls FUN_00844970 with a, sets f0 to point at DAT_0107ec28, and returns this.
// @fnv 0x00844100
C844100* C844100::FUN_00844100(int a)
{
    new ((void *)this) ::FUN_00844970_class(a);
    f0 = &DAT_0107ec28;
    return this;
}

struct UnnamedClass008441b0
{
    void FUN_00844600();
    void* FUN_008441b0(unsigned int);
};
struct Fake8441e0
{
    void FUN_008447e0();
    void* FUN_008441e0(unsigned int);
};
struct UnknownClass
{
    void FUN_008448e0();
    void* FUN_00844210(unsigned int);
};
struct C844240
{
    void* FUN_00844240(unsigned int);
};
extern int DAT_0107ec68;
struct Unk008444d0
{
    void* _0;
    int _4;
    void* _8;
    void FUN_008444d0();
};
// Sets the vtable pointer, clears the pointer map, and frees the _8 allocation.
// @fnv 0x008444d0
void Unk008444d0::FUN_008444d0()
{
    *(void**)this = (void*)&DAT_0107ec68;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<unsigned int, unsigned int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(_8);
}

extern int DAT_0107ed1c;
struct S_00844e80
{
    int _0;
    int _4;
    void* _8;
    void FUN_00844e80();
};
// @fnv 0x00844e80
void S_00844e80::FUN_00844e80()
{
    *(void**)this = (void*)&DAT_0107ed1c;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<unsigned int, unsigned int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(this->_8);
}

namespace fnv_00844eb0 {
struct S5460
{
    unsigned int unk0;
    unsigned int FUN_00845460();
};
struct SaveGameSizeState : public S5460
{
    struct Elem
    {
        unsigned int a;
        unsigned int b;
    }* arr;
    unsigned int FUN_00844eb0(Elem* p);
};
// @fnv 0x00844eb0
unsigned int SaveGameSizeState::FUN_00844eb0(Elem* apElem)
{
    unsigned int idx = FUN_00845460();
    reinterpret_cast<::Walker8 *>(this)->ConstructArray((::Pair8 *)((unsigned int)&arr[idx]), 1);
    arr[idx] = *apElem;
    return idx;
}
}  // namespace fnv_00844eb0

namespace fnv_00845050 {
struct OffsetData
{
    int _0;
    int _1;
};
struct ArrSI
{
    unsigned int _pad[4];
};
struct ScrapHeapBuffer
{
};
struct BSScrapArray : ArrSI
{
    ScrapHeapBuffer* m_pAllocator;
    OffsetData* ReallocateBuffer(OffsetData*, unsigned int);
};
// Allocates a new buffer of aiNewSizeInItem items, copies GetFlags() items from apBuffer into it, frees apBuffer and returns the new buffer.
// @fnv 0x00845050
OffsetData* BSScrapArray::ReallocateBuffer(OffsetData* apBuffer, unsigned int aiNewSizeInItem)
{
    OffsetData* pnewBuffer = (OffsetData*)reinterpret_cast<::FUN_00aa54a0_s *>((m_pAllocator))->FUN_00aa54a0(aiNewSizeInItem * sizeof(OffsetData), ::DAT_010a2720);
    ::__memcpy(pnewBuffer, apBuffer, ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())) * sizeof(OffsetData));
    reinterpret_cast<::SHStub *>((m_pAllocator))->FUN_00aa5610(apBuffer);
    return pnewBuffer;
}
}  // namespace fnv_00845050

struct MyVal
{
    unsigned int a;
    unsigned int b;
};
struct MyItem
{
    void* f0;
    unsigned int f4;
    MyVal f8;
};
struct MyHost
{
    void FUN_00993b30(MyItem* pkItem, unsigned int key, MyVal val);
};
// Stores key into pkItem->f4 and val into pkItem->f8.
// @fnv 0x00993b30
void MyHost::FUN_00993b30(MyItem* pkItem, unsigned int key, MyVal val)
{
    pkItem->f4 = key;
    pkItem->f8 = val;
}

extern int DAT_0107ec68;

struct FUN_008442a0_shell
{
    int* p1;
    int p2;
    void* p3;
    int p4;
    int FUN_008442a0(int n);
};

// @fnv 0x008442a0
int FUN_008442a0_shell::FUN_008442a0(int aiCount)
{
    p1 = &DAT_0107ec68;
    p2 = aiCount;
    p4 = 0;
    int iByteSize = p2 * 4;
    p3 = ::FUN_00aa1070(iByteSize);
    memset(p3, 0, p2 * 4);
    return (int)this;
}

extern int DAT_0107ed1c;

struct FUN_00844db0_shell
{
    void* p;
    int count;
    void* data;
    int pad;
    FUN_00844db0_shell* FUN_00844db0(int param);
};

// Sets p to DAT_0107ed1c, stores param in count, allocates count*4 bytes into data, zeroes them, and returns this.
// @fnv 0x00844db0
FUN_00844db0_shell* FUN_00844db0_shell::FUN_00844db0(int aiCount)
{
    unsigned int size;
    p = &DAT_0107ed1c;
    count = aiCount;
    pad = 0;
    size = count << 2;
    data = ::FUN_00aa1070(size);
    memset(data, 0, count << 2);
    return this;
}

struct S00844c20
{
    char _pad[16];
};
struct H00843be0 : S00844c20
{
    S00844c20 sub;
    void FUN_00843be0(unsigned int);
};
namespace fnv_00841e20 {
struct FUN_00452420_shell
{
};
struct FUN_00841990_shell
{
};
struct FUN_00841e20_shell : public BGSReconstructFormsInAllFilesMap
{
    bool HasFlagInAnyFile(unsigned int flags);
};
// @fnv 0x00841e20
bool FUN_00841e20_shell::HasFlagInAnyFile(unsigned int flags)
{
    if (*(unsigned int*)&this->m_kFormChangeMap && reinterpret_cast<::FUN_00452420_shell *>((void *)(((FUN_00452420_shell*)(*(void**)&this->m_kFormChangeMap))))->GetFlag(flags))
        return true;
    void* it = GetFirstPos();
    while (it)
    {
        TESFile* file = 0;
        BGSReconstructFormsInFileMap* map = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(it), (unsigned int *)&(file), (void **)&(map));
        if (reinterpret_cast<::fnv_00841990::BGSReconstructCellSubBlocksMap *>((((FUN_00841990_shell*)map)))->HasCellWithFlag(flags))
            return true;
    }
    return false;
}
}  // namespace fnv_00841e20

__declspec(thread) unsigned int DAT_00843c10_tls;

struct FUN_00843c10_shell
{
    void SetFlag4(bool bSet);
};

// @fnv 0x00843c10
void FUN_00843c10_shell::SetFlag4(bool bSet)
{
    if (bSet)
        DAT_00843c10_tls |= 4;
    else
        DAT_00843c10_tls &= 0xfffffffb;
}

extern int DAT_0107ec08;
struct FUN_00844940_class
{
    virtual ~FUN_00844940_class();
};
struct FUN_008448e0 : public FUN_00844940_class
{
    virtual ~FUN_008448e0();
};
// Calls FUN_008448e0, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00844210
void* UnknownClass::FUN_00844210(unsigned int flags)
{
    reinterpret_cast<::FUN_008448e0 *>(this)->FUN_008448e0::~FUN_008448e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x008448e0
FUN_008448e0::~FUN_008448e0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct S5460
{
};
struct FUN_00844c20_shell
{
    void SetCount(unsigned int);
};
// Calls SetCount on the base and on the sub object with the same argument.
// @fnv 0x00843be0
void H00843be0::FUN_00843be0(unsigned int auiValue)
{
    reinterpret_cast<::FUN_00844c20_shell *>(this)->SetCount(auiValue);
    reinterpret_cast<::FUN_00844c20_shell *>(&(sub))->SetCount(auiValue);
}

// If idx differs from the stored count, shrinks the array to idx elements, calls FUN_006a2770 with idx and the new count, then stores idx as the count.
// @fnv 0x00844c20
void FUN_00844c20_shell::SetCount(unsigned int idx)
{
    if (idx == *(unsigned int*)((char*)this + 0xc))
        return;
    if (idx < *(unsigned int*)((char*)this + 8))
    {
        ((FUN_0072ba80_shell*)this)
            ->FUN_0072ba80((char*)*(void**)((char*)this + 4) + idx * 8, *(unsigned int*)((char*)this + 8) - idx);
        *(unsigned int*)((char*)this + 8) = idx;
    }
    reinterpret_cast<::StandIn *>((((S5460*)this)))->FUN_006a2770(idx, *(unsigned int*)((char*)this + 8));
    *(unsigned int*)((char*)this + 0xc) = idx;
}

namespace fnv_00844ff0 {
struct GlobalObject_00869f00
{
};
struct FUN_00844fa0_class
{
    virtual ~FUN_00844fa0_class();
};
struct FUN_00844ff0 : FUN_00844fa0_class, GlobalObject_00869f00
{
    virtual ~FUN_00844ff0();
};
// Destructor that calls Clear(true) on the GlobalObject base subobject of this instance.
// @fnv 0x00844ff0
FUN_00844ff0::~FUN_00844ff0()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}
}  // namespace fnv_00844ff0

namespace fnv_00841580 {
extern unsigned int _data_011c16bc;

struct TESWorldSpace
{
};

struct SetAtHelper
{
};

struct DummyPointerMap : public SetAtHelper
{
    void SetAtCoordinates(unsigned int, short, short, unsigned int, unsigned int, unsigned int);
};

struct FUN_00841190
{
    int data[5];
    FUN_00841190(void);
};

// Looks up a value by worldspace coordinates, allocating and inserting a new FUN_00841190 if absent, then calls ProcessRef on it with a, b, c.
// @fnv 0x00841580
void DummyPointerMap::SetAtCoordinates(unsigned int, short x, short y, unsigned int auiArg1, unsigned int auiArg2,
                                       unsigned int auiArg3)
{
    int value = ::PackShortPair(x, y);
    unsigned int key = 0;

    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>(this)->FUN_00853130(value, (::fnv_00853130::CombatThreatRecord *&)(key)))
    {
        key = (unsigned int)new FUN_00841190;
        reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(value, key);
    }

    reinterpret_cast<::FUN_00841250_cls *>((reinterpret_cast<FUN_00841190*>(key)))->ProcessRef((::FUN_00841250_ref *)(auiArg1), (void *)(auiArg2), auiArg3);
}
}  // namespace fnv_00841580

struct FUN_00544210_shell
{
    unsigned int FUN_00544210();
};

struct DummyPointerMap
{
};

struct SetAtHelper : public DummyPointerMap
{
    void GetOrCreateAndDispatch(FUN_00544210_shell*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00841460_shell
{
    void FUN_00841460(FUN_00544210_shell*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00841340 : public FUN_00841460_shell
{
    unsigned char data[16];
    FUN_00841340();
};

FUN_00841340::FUN_00841340()
{}

void FUN_00841460_shell::FUN_00841460(FUN_00544210_shell* param1, unsigned int param2, unsigned int param3,
                                      unsigned int param4)
{}

// Looks up the entry for param1's key, creating a new FUN_00841340 if absent, then forwards param1-param4 to its FUN_00841460.
// @fnv 0x008417e0
void SetAtHelper::GetOrCreateAndDispatch(FUN_00544210_shell* pKeySource, unsigned int param2, unsigned int param3,
                                         unsigned int param4)
{
    unsigned int uiKey = pKeySource->FUN_00544210();
    unsigned int uiEntry = 0;

    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((this))->FUN_00853130(uiKey, (::fnv_00853130::CombatThreatRecord *&)(uiEntry)))
    {
        uiEntry = (unsigned int)new FUN_00841340;
        reinterpret_cast<::FUN_00844700_Class *>((this))->FUN_00844700(uiKey, uiEntry);
    }

    ((FUN_00841460_shell*)uiEntry)->FUN_00841460(pKeySource, param2, param3, param4);
}

namespace fnv_008418b0 {


struct FUN_00841340
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;

    FUN_00841340();
};

struct SetAtHelper
{
};

struct DummyPointerMap : public SetAtHelper
{
};

struct FUN_008418b0_shell : public DummyPointerMap
{
    void GetOrCreateEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x008418b0
void FUN_008418b0_shell::GetOrCreateEntry(unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                                          unsigned int arg5, unsigned int arg6)
{
    unsigned int key = ::FUN_005442c0(arg2, arg3);
    FUN_00841340* value = 0;

    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>(this)->FUN_00853130(key, (::fnv_00853130::CombatThreatRecord *&)(value)))
    {
        value = new FUN_00841340;
        reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(key, (unsigned int)(value));
    }

    reinterpret_cast<::fnv_00841580::DummyPointerMap *>((value))->SetAtCoordinates(arg1, arg2, arg3, arg4, arg5, arg6);
}
}  // namespace fnv_008418b0

namespace fnv_00841fc0 {

struct DoorH
{
};

struct SoundH
{
};

struct DummyPointerMap
{
};

struct SetAtHelper : DummyPointerMap
{
};

struct FUN_008419f0
{
    unsigned int field0;
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;
    unsigned int field4;
    unsigned int field5;

    FUN_008419f0(bool);
    void ProcessEntry(DoorH*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00841fc0_class : SetAtHelper
{
    void FUN_00841fc0(DoorH*, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x00841fc0
void FUN_00841fc0_class::FUN_00841fc0(DoorH* door, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    void* id;
    unsigned int value;
    unsigned int worldSpace;

    id = ((void *)(reinterpret_cast<::TESObjectCELL *>((door))->GetParentWorldSpace()));
    value = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<SoundH*>(id)))->FUN_0084e3a0()));
    worldSpace = 0;

    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>(this)->FUN_00853130(value, (::fnv_00853130::CombatThreatRecord *&)(worldSpace)))
    {
        worldSpace = reinterpret_cast<unsigned int>(new FUN_008419f0(true));
        reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(value, worldSpace);
    }

    reinterpret_cast<FUN_008419f0*>(worldSpace)->ProcessEntry(door, arg1, arg2, arg3);
}
}  // namespace fnv_00841fc0

namespace fnv_008420a0 {
struct FUN_008419f0
{
    unsigned char data[24];

    FUN_008419f0(bool);

    void ReconstructFormEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

struct SetAtHelper
{
};

struct DummyPointerMap : public SetAtHelper
{
};



struct FUN_008420a0_class : public DummyPointerMap
{
    void FUN_008420a0(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

// @fnv 0x008420a0
void FUN_008420a0_class::FUN_008420a0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4,
                                      unsigned int a5, unsigned int a6)
{
    unsigned int map = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((a1))->FUN_0084e3a0()));
    FUN_008419f0* object = 0;

    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>(this)->FUN_00853130(map, (::fnv_00853130::CombatThreatRecord *&)(object)))
    {
        object = new FUN_008419f0(true);
        reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(map, (unsigned int)(object));
    }

    object->ReconstructFormEntry(a1, a2, a3, a4, a5, a6);
}
}  // namespace fnv_008420a0

namespace fnv_00842600 {

struct TESObjectCELL
{
};

struct FUN_008419f0
{
    char padding[0x18];
    FUN_008419f0(bool);
};

struct FUN_00841ea0
{
    char padding[0x10];
    FUN_00841ea0();
};

struct FUN_00841b20_standin
{
    void ProcessEntry(TESObjectCELL*, int, int, int);
};

struct FUN_00841fc0_standin
{
};

struct FUN_00842600_shell
{
    void ProcessCell(TESObjectCELL*, int, int, int);
};

// Dispatches the cell to an interior or exterior handler, lazily allocating it, then increments a counter at offset 0x18.
// @fnv 0x00842600
void FUN_00842600_shell::ProcessCell(TESObjectCELL* cell, int aiArg1, int aiArg2, int aiArg3)
{
    if (reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior())
    {
        if (!*reinterpret_cast<FUN_00841b20_standin**>(reinterpret_cast<char*>(this) + 0x10))
        {
            *reinterpret_cast<FUN_00841b20_standin**>(reinterpret_cast<char*>(this) + 0x10) =
                reinterpret_cast<FUN_00841b20_standin*>(new FUN_008419f0(false));
        }

        reinterpret_cast<FUN_00841b20_standin*>(
            *reinterpret_cast<FUN_00841b20_standin**>(reinterpret_cast<char*>(this) + 0x10))
            ->ProcessEntry(cell, aiArg1, aiArg2, aiArg3);
    }
    else
    {
        if (!*reinterpret_cast<FUN_00841fc0_standin**>(reinterpret_cast<char*>(this) + 0x14))
        {
            *reinterpret_cast<FUN_00841fc0_standin**>(reinterpret_cast<char*>(this) + 0x14) =
                reinterpret_cast<FUN_00841fc0_standin*>(new FUN_00841ea0());
        }

        reinterpret_cast<::fnv_00841fc0::FUN_00841fc0_class *>((reinterpret_cast<FUN_00841fc0_standin*>(
            *reinterpret_cast<FUN_00841fc0_standin**>(reinterpret_cast<char*>(this) + 0x14))))->FUN_00841fc0((::fnv_00841fc0::DoorH *)(cell), aiArg1, aiArg2, aiArg3);
    }

    ++*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18);
}
}  // namespace fnv_00842600

namespace fnv_00842730 {

struct FUN_00841ea0
{
    int _unused[4];

    FUN_00841ea0();
};

struct FUN_00842730_shell
{
    char _padding[0x14];
    FUN_00841ea0* _object;
    int _count;

    void EnsureObjectAndCall(int, int, int, int, int, int);
};

// Allocates the object if null, forwards the six arguments to its method, and increments the count.
// @fnv 0x00842730
void FUN_00842730_shell::EnsureObjectAndCall(int a, int b, int c, int d, int e, int f)
{
    if (_object == 0)
    {
        _object = new FUN_00841ea0;
    }

    reinterpret_cast<::fnv_008420a0::FUN_008420a0_class *>((_object))->FUN_008420a0(a, b, c, d, e, f);

    _count += 1;
}
}  // namespace fnv_00842730

namespace fnv_00843630 {

struct TESFormCallProxy
{
};

struct TESFormRefProxy
{
};

struct VirtualBase : TESForm
{
    virtual void vfn_61()
    {}
    virtual void vfn_62()
    {}
    virtual void vfn_63()
    {}
    virtual void vfn_64()
    {}
    virtual void vfn_65()
    {}
    virtual void vfn_66()
    {}
    virtual void vfn_67()
    {}
    virtual void vfn_68()
    {}
    virtual void vfn_69()
    {}
    virtual void vfn_70()
    {}
    virtual void vfn_71()
    {}
    virtual void vfn_72()
    {}
    virtual void vfn_73()
    {}
    virtual void vfn_74()
    {}
    virtual void vfn_75()
    {}
    virtual char const* vfn_76()
    {
        return 0;
    }
};

struct DummyPointerMap
{
};

struct SetAtHelper
{
};

struct FUN_00842180
{
    unsigned char data[0x1c];

    FUN_00842180();
};

FUN_00842180::FUN_00842180()
{}

struct MapCallProxy
{
    void FUN_00842310(TESForm*, unsigned int);
};

struct FUN_00843630_shell : BGSReconstructFormsInAllFilesMap
{
    void FUN_00843630(TESForm*, unsigned int);
};

// Adds apForm to the per-file map keyed by its TESFile, creating the entry if missing, then increments iCount; logs an error when the form has no file.
// @fnv 0x00843630
void FUN_00843630_shell::FUN_00843630(TESForm* apForm, unsigned int aiFlags)
{
    BGSReconstructFormsInFileMap* pformsInFileMap;
    TESFile* pfile;

    if (!apForm)
        return;

    pfile = reinterpret_cast<::TESForm *>((reinterpret_cast<TESFormCallProxy*>(apForm)))->GetFile(-1);

    if (!pfile)
    {
        ::FUN_00845cc0("Form %08X %s with type %s and no file passed to BGSReconstructFormsInAllFilesMap::AddForm()",
                         ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESFormRefProxy*>(apForm)))->FUN_0084e3a0())),
                         reinterpret_cast<VirtualBase*>(apForm)->vfn_76(),
                         ((const char *)(reinterpret_cast<::FUN_00440e30_This *>((reinterpret_cast<TESFormCallProxy*>(apForm)))->FUN_00440e30())));
        return;
    }

    pformsInFileMap = 0;

    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((reinterpret_cast<DummyPointerMap*>(this)))->FUN_00853130(reinterpret_cast<unsigned int>(pfile),
                                                         (::fnv_00853130::CombatThreatRecord *&)(reinterpret_cast<unsigned int&>(pformsInFileMap))))
    {
        pformsInFileMap = reinterpret_cast<BGSReconstructFormsInFileMap*>(new FUN_00842180());

        reinterpret_cast<::FUN_00844700_Class *>((reinterpret_cast<SetAtHelper*>(this)))->FUN_00844700(reinterpret_cast<unsigned int>(pfile),
                                                    reinterpret_cast<unsigned int>(pformsInFileMap));
    }

    reinterpret_cast<MapCallProxy*>(pformsInFileMap)->FUN_00842310(apForm, aiFlags);

    ++iCount;
}
}  // namespace fnv_00843630

namespace fnv_00844c90 {
struct FUN_00692480
{
};

struct FUN_006c8a30_Class
{
};

struct FUN_006f3170_Class
{
};

struct FUN_0072ba80_shell
{
};

struct FUN_00869600_Class
{
};

struct FUN_00844c90_shell
{
    // Virtual destructor for the shell object; empty body.
// @fnv 0x00844c90
    virtual ~FUN_00844c90_shell()
    {}
    virtual char* GetArray(unsigned int) = 0;

    char* m_items;
    unsigned int m_uiItemCount;
    unsigned int m_uiFilterValue;

    void FUN_00844c90(unsigned int, bool);
};

void FUN_00844c90_shell::FUN_00844c90(unsigned int index, bool useArray)
{
    char* array;

    if (useArray && reinterpret_cast<::FUN_006f3170_Class *>((reinterpret_cast<FUN_006f3170_Class*>(this)))->FUN_006f3170())
    {
        unsigned int count = reinterpret_cast<::FUN_00869600_Class *>((reinterpret_cast<FUN_00869600_Class*>(this)))->FUN_00869600();
        array = GetArray(count);

        reinterpret_cast<::FUN_00692480 *>((reinterpret_cast<FUN_00692480*>(this)))->Method(array, m_items, index);
        reinterpret_cast<::FUN_0072ba80_shell *>((reinterpret_cast<FUN_0072ba80_shell*>(this)))->FUN_0072ba80(m_items + index * 8, 1);

        reinterpret_cast<::FUN_00692480 *>((reinterpret_cast<FUN_00692480*>(this)))->Method(array + index * 8, m_items + index * 8 + 8, m_uiItemCount - 1);

        ::FUN_006a8500((::DummyClass_006a8500 *)(reinterpret_cast<FUN_006c8a30_Class*>(this)));
        m_items = array;
        m_uiFilterValue = count;
    }
    else
    {
        reinterpret_cast<::FUN_0072ba80_shell *>((reinterpret_cast<FUN_0072ba80_shell*>(this)))->FUN_0072ba80(m_items + index * 8, 1);

        reinterpret_cast<::FUN_00692480 *>((reinterpret_cast<FUN_00692480*>(this)))->Method(m_items + index * 8, m_items + index * 8 + 8,
                                                      m_uiItemCount - index - 1);
    }

    --m_uiItemCount;
}
}  // namespace fnv_00844c90

namespace fnv_00841b20 {

struct FUN_005441b0_S
{
};

struct FUN_00565450_shell
{
    virtual bool v00() = 0;
    virtual bool v01() = 0;
    virtual bool v02() = 0;
    virtual bool v03() = 0;
    virtual bool v04() = 0;
    virtual bool v05() = 0;
    virtual bool v06() = 0;
    virtual bool v07() = 0;
    virtual bool v08() = 0;
    virtual bool v09() = 0;
    virtual bool v10() = 0;
    virtual bool v11() = 0;
    virtual bool v12() = 0;
    virtual bool v13() = 0;
    virtual bool v14() = 0;
    virtual bool v15() = 0;
    virtual bool v16() = 0;
    virtual bool v17() = 0;
    virtual bool v18() = 0;
    virtual bool v19() = 0;
    virtual bool v20() = 0;
    virtual bool v21() = 0;
    virtual bool v22() = 0;
    virtual bool v23() = 0;
    virtual bool v24() = 0;
    virtual bool v25() = 0;
    virtual bool v26() = 0;
    virtual bool v27() = 0;
    virtual bool v28() = 0;
    virtual bool v29() = 0;
    virtual bool v30() = 0;
    virtual bool v31() = 0;
    virtual bool v32() = 0;
    virtual bool v33() = 0;
    virtual bool v34() = 0;
    virtual bool v35() = 0;
    virtual bool v36() = 0;
    virtual bool v37() = 0;
    virtual bool v38() = 0;
    virtual bool v39() = 0;
    virtual bool v40() = 0;
    virtual bool v41() = 0;
    virtual bool v42() = 0;
    virtual bool v43() = 0;
    virtual bool v44() = 0;
    virtual bool v45() = 0;
    virtual bool v46() = 0;
    virtual bool v47() = 0;
    virtual bool v48() = 0;
    virtual bool v49() = 0;
    virtual bool v50() = 0;
    virtual bool v51() = 0;
    virtual bool v52() = 0;
    virtual bool v53() = 0;
    virtual bool v54() = 0;
    virtual bool v55() = 0;
    virtual bool v56() = 0;
    virtual bool v57() = 0;
    virtual bool v58() = 0;
    virtual bool v59() = 0;
    virtual bool FUN_00841b20_virtual() = 0;

};

struct FUN_00841190
{
    unsigned char data[0x14];

    FUN_00841190(void);
};

struct FUN_008416c0
{
    unsigned char data[0x10];

    FUN_008416c0(void);
};

struct DummyPointerMap
{
};

struct SetAtHelper
{
};

struct FUN_00841b20_shell
{
    unsigned char padding[0x10];
    FUN_00841190* form;
    unsigned char flag;

    void ProcessEntry(FUN_005441b0_S*, FUN_00565450_shell*, unsigned int, unsigned int);
};

// @fnv 0x00841b20
void FUN_00841b20_shell::ProcessEntry(FUN_005441b0_S* first, FUN_00565450_shell* second, unsigned int third,
                                      unsigned int fourth)
{
    if (flag && second && second->FUN_00841b20_virtual())
    {
        FUN_00565450_shell* shell = second;

        if (reinterpret_cast<::FUN_00565450_shell *>((shell))->FUN_00565450())
        {
            if (!form)
                form = new FUN_00841190();

            reinterpret_cast<::FUN_00841250_cls *>((form))->ProcessRef((::FUN_00841250_ref *)(second), (void *)(third), fourth);
            return;
        }
    }

    unsigned int key = reinterpret_cast<::FUN_005441b0_S *>((first))->FUN_005441b0();
    unsigned int value = 0;

    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((reinterpret_cast<DummyPointerMap*>(this)))->FUN_00853130(key, (::fnv_00853130::CombatThreatRecord *&)(value)))
    {
        value = reinterpret_cast<unsigned int>(new FUN_008416c0());
        reinterpret_cast<::FUN_00844700_Class *>((reinterpret_cast<SetAtHelper*>(this)))->FUN_00844700(key, value);
    }

    reinterpret_cast<::SetAtHelper *>((reinterpret_cast<FUN_008416c0*>(value)))->GetOrCreateAndDispatch((::FUN_00544210_shell *)(first), (unsigned int)(second), third, fourth);
}
}  // namespace fnv_00841b20

namespace fnv_00844ae0 {
struct FUN_0072ba80_shell
{
};

struct S5460
{
};

struct SaveGameSizeState
{
};

struct BSSimpleArrayActor
{
    typedef void*(* Allocator)(BSSimpleArrayActor*, unsigned int);

    struct VTable
    {
        void* vftableEntry;
        Allocator allocator;
    };

    VTable* m_ppVirtualMethodTable;
    unsigned char* m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void Resize(unsigned int, bool);
};

// @fnv 0x00844ae0
void BSSimpleArrayActor::Resize(unsigned int size, bool clear)
{
    if (size == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((this))->Clear(clear);
        return;
    }

    if (size > this->m_pRayCursor)
    {
        if (this->m_pRayCursor == 0)
        {
            this->m_data = static_cast<unsigned char*>(this->m_ppVirtualMethodTable->allocator(this, size));
            this->m_pRayCursor = size;
        }
        else
        {
            reinterpret_cast<::StandIn *>((reinterpret_cast<S5460*>(this)))->FUN_006a2770(size, this->m_iElementCount);
            this->m_pRayCursor = size;
        }

        reinterpret_cast<::Walker8 *>((reinterpret_cast<SaveGameSizeState*>(this)))->ConstructArray(
            (::Pair8 *)(reinterpret_cast<unsigned int>(this->m_data + this->m_iElementCount * 8)), size - this->m_iElementCount);
        this->m_iElementCount = size;
    }
    else if (size < this->m_iElementCount)
    {
        reinterpret_cast<::FUN_0072ba80_shell *>((reinterpret_cast<FUN_0072ba80_shell*>(this)))->FUN_0072ba80(reinterpret_cast<char*>(this->m_data + size * 8),
                                                                  this->m_iElementCount - size);
        this->m_iElementCount = size;

        if (clear && size <= this->m_pRayCursor / 4)
        {
            reinterpret_cast<::StandIn *>((reinterpret_cast<S5460*>(this)))->FUN_006a2770(size, size);
            this->m_pRayCursor = size;
        }
    }
    else
    {
        reinterpret_cast<::Walker8 *>((reinterpret_cast<SaveGameSizeState*>(this)))->ConstructArray(
            (::Pair8 *)(reinterpret_cast<unsigned int>(this->m_data + this->m_iElementCount * 8)), size - this->m_iElementCount);
        this->m_iElementCount = size;
    }
}
}  // namespace fnv_00844ae0

class B411F0MapBase
{
  public:
    virtual ~B411F0MapBase();


    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_008411f0 : public B411F0MapBase
{
  public:
    virtual ~FUN_008411f0();
};
// Calls FUN_008411f0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x008411c0
void* BGSReconstructFormsMap::FUN_008411c0(unsigned int flags)
{
    reinterpret_cast<::FUN_008411f0 *>((this))->FUN_008411f0::~FUN_008411f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x008411f0
FUN_008411f0::~FUN_008411f0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_008413a0_item
{
    virtual void* Free(unsigned int flags);
};

struct FUN_008413a0_base
{
    virtual ~FUN_008413a0_base();
    void GetNext(void*& pos, unsigned int& key, FUN_008413a0_item*& val);
};

struct FUN_008413a0 : FUN_008413a0_base
{
    virtual ~FUN_008413a0();
};
// @fnv 0x00841370
void* BGSReconstructCellsMap::FUN_00841370(unsigned int flags)
{
    reinterpret_cast<::FUN_008413a0 *>(this)->FUN_008413a0::~FUN_008413a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Iterates the container's entries and frees each item with flags 1.
// @fnv 0x008413a0
FUN_008413a0::~FUN_008413a0()
{
    void* pos2 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (pos2 != 0)
    {
        unsigned int key = 0;
        FUN_008413a0_item* data2 = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(pos2), (unsigned int *)&(key), (void **)&(data2));
        FUN_008413a0_item* tmp4 = data2;
        FUN_008413a0_item* val = tmp4;
        (val != 0) ? val->Free(1) : 0;
    }
}

struct ValueItem
{
    virtual ~ValueItem();
};
struct BaseMap
{
    virtual ~BaseMap();
    void FUN_008447e0();
};
struct FUN_00841720 : BaseMap
{
    virtual ~FUN_00841720();
};
// Destroys the object, frees its storage with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008416f0
void* BGSReconstructCellSubBlocksMap::ScalarDeletingDestructor(unsigned int flags)
{
    reinterpret_cast<::FUN_00841720 *>(this)->FUN_00841720::~FUN_00841720();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Iterates the map via FUN_004b9ba0/FUN_006b7f20, deleting each ValueItem until the position is null.
// @fnv 0x00841720
FUN_00841720::~FUN_00841720()
{
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (position != 0)
    {
        ValueItem* item;
        {
            unsigned int key = 0;
            item = 0;
            reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)(void **)(&position), &key, (void **)(::ValueItem **)(&item));
        }
        delete item;
    }
}

struct FUN_00401170_shell
{
    unsigned int FUN_00401170();
};

struct FUN_00844eb0_shell
{
    void FUN_00844eb0(ChangedFormRecord* apData);
};

struct FUN_00843270_shell : public FormChangeMap
{
    void FUN_00843270(ChangedFormRecord* apData);
};

// Dispatches apData to one of two handlers depending on whether its form is a reference or has type 0x39 or 0x41.
// @fnv 0x00843270
void FUN_00843270_shell::FUN_00843270(ChangedFormRecord* apData)
{
    if (!apData->pForm->GetIsReference() && ((FUN_00401170_shell*)apData->pForm)->FUN_00401170() != 0x39 &&
        ((FUN_00401170_shell*)apData->pForm)->FUN_00401170() != 0x41)
    {
        ((FUN_00844eb0_shell*)&m_kOrdinaryFormChanges)->FUN_00844eb0(apData);
    }
    else
    {
        ((FUN_00844eb0_shell*)&m_kSpecialFormChanges)->FUN_00844eb0(apData);
    }
}

struct FNV_ValuePair
{
    unsigned int data1;
    unsigned int data2;
};
struct FNV_MapEntry
{
    FNV_MapEntry* next;
    unsigned int key;
    FNV_ValuePair data;
};

class FNV_BucketMap
{
  public:
    virtual void OnDestroy();
    virtual unsigned int GetBucket(unsigned int key);
    virtual bool IsEqual(unsigned int key, unsigned int entryKey);
    virtual void InitializeEntry(FNV_MapEntry* entry, unsigned int key, FNV_ValuePair value);
    virtual void ReservedSlot();
    virtual FNV_MapEntry* NewEntry();

    unsigned int bucketCount;
    FNV_MapEntry** buckets;
    unsigned int entryCount;

    void SetValue(unsigned int key, FNV_ValuePair value);
};

// Looks up the entry for key in its bucket and overwrites its value, or creates, initializes and prepends a new entry and increments entryCount.
// @fnv 0x00844310
void FNV_BucketMap::SetValue(unsigned int key, FNV_ValuePair valuePair)
{
    unsigned int bucketIndex = GetBucket(key);
    FNV_MapEntry* entry = buckets[bucketIndex];
    unsigned int visited = 0;
    while (entry)
    {
        ++visited;
        if (IsEqual(key, entry->key))
        {
            entry->data = valuePair;
            return;
        }
        entry = entry->next;
    }
    entry = NewEntry();
    InitializeEntry(entry, key, valuePair);
    entry->next = buckets[bucketIndex];
    buckets[bucketIndex] = entry;
    entryCount += 1;
}

struct Base00844660
{
    virtual ~Base00844660();
};

struct FUN_00844600 : Base00844660
{
    virtual ~FUN_00844600();
};
// Calls FUN_00844600, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x008441b0
void* UnnamedClass008441b0::FUN_008441b0(unsigned int flags)
{
    reinterpret_cast<::FUN_00844600 *>(this)->FUN_00844600::~FUN_00844600();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls FUN_00438af0 before the object is destroyed.
// @fnv 0x00844600
FUN_00844600::~FUN_00844600()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct Base
{
    virtual ~Base();
};

struct FUN_008447e0 : Base
{
    virtual ~FUN_008447e0();
};
// Calls FUN_008447e0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008441e0
void* Fake8441e0::FUN_008441e0(unsigned int flags)
{
    reinterpret_cast<::FUN_008447e0 *>((this))->FUN_008447e0::~FUN_008447e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that clears the NiTPointerMap by calling RemoveAll.
// @fnv 0x008447e0
FUN_008447e0::~FUN_008447e0()
{
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
}

struct FUN_00844a40
{
    virtual ~FUN_00844a40();
};

struct FUN_008449e0_cls : public FUN_00844a40
{
    virtual ~FUN_008449e0_cls();
};
// Calls FUN_008449e0, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00844240
void* C844240::FUN_00844240(unsigned int flags)
{
    reinterpret_cast<::FUN_008449e0_cls *>((this))->FUN_008449e0_cls::~FUN_008449e0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x008449e0
FUN_008449e0_cls::~FUN_008449e0_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

class TESGlobal
{
};

struct FormContext
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual const char* GetDisplayName();
};

struct FormTypeReader
{
    unsigned int FUN_00401170();
};

extern char DAT_01014168[];
extern char DAT_01014100[];

struct FUN_0040e7f0_owner
{
    TESForm* primary;
    TESGlobal* secondary;
    void ResolveFormReferences(FormContext* context);
};

// Resolves primary and secondary form references through the file context, logging failures and clearing secondary when primary is null.
// @fnv 0x0040e7f0
void FUN_0040e7f0_owner::ResolveFormReferences(FormContext* context)
{
    if (primary != 0)
    {
        unsigned int numericID = (unsigned int)primary;
        ResolveFormID(&numericID, reinterpret_cast<::TESForm *>((context))->GetFile(-1));
        primary = ::FUN_004839c0(numericID);
        if (primary == 0)
        {
            ::FUN_005b5e40();
        }
    }

    if (primary != 0)
    {
        if (((FormTypeReader*)primary)->FUN_00401170() == 42 && secondary != 0)
        {
            unsigned int uiSecondaryID = (unsigned int)secondary;
            ResolveFormID(&uiSecondaryID, reinterpret_cast<::TESForm *>((context))->GetFile(-1));
            secondary = dynamic_cast<TESGlobal*>(::FUN_004839c0(uiSecondaryID));
            if (secondary == 0)
            {
                ::FUN_005b5e40();
            }
        }
    }
    else
    {
        secondary = 0;
    }
}

struct ReconstructCellBlock
{
    virtual ~ReconstructCellBlock();
};
struct FUN_00841a60 : FUN_008448e0
{
    virtual ~FUN_00841a60();
};
// Calls FUN_00841a60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00841a30
void* BGSReconstructCellBlocksMap::FUN_00841a30(unsigned int flags)
{
    reinterpret_cast<::FUN_00841a60 *>(this)->FUN_00841a60::~FUN_00841a60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00841a60
FUN_00841a60::~FUN_00841a60()
{
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (position)
    {
        unsigned int key = 0;
        ReconstructCellBlock* pEntry = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)(void **)(&position), &key, (void **)(::ReconstructCellBlock **)(&pEntry));
        delete pEntry;
    }
}

struct FormWithSaveCheck : TESForm
{
};
struct ReconstructEntry
{
};
struct ReconstructedCellStorage : FUN_008416c0
{
    unsigned int recordID;
    void* owner;
    unsigned int flags;
    unsigned int count;
};
int __cdecl GetCellCoordKey(int, int);
struct SaveLoadDispatcher
{
    int state00, state04, state08, state0c;
    ReconstructEntry* helper10;
    void ReconstructFormEntry(int, int, int, FormWithSaveCheck*, int, int);
};
// If form is a reference with a save check, forwards it to helper10; otherwise looks up or creates a ReconstructEntry for the handle and reconstructs the entry.
// @fnv 0x00841ca0
void SaveLoadDispatcher::ReconstructFormEntry(int value, int formID, int context, FormWithSaveCheck* form, int flag,
                                              int offset)
{
    int handle3;
    FormWithSaveCheck* referenceForm;
    ReconstructEntry* entry7;
    if (form != 0 && form->GetIsReference() && (referenceForm = form, reinterpret_cast<::FUN_00565450_shell *>((referenceForm))->FUN_00565450()))
    {
        if (helper10 == 0)
            helper10 = (ReconstructEntry*)new FUN_00841190;
        reinterpret_cast<::FUN_00841250_cls *>((helper10))->ProcessRef((::FUN_00841250_ref *)(form), (void *)(flag), offset);
    }
    else
    {
        handle3 = GetCellCoordKey(formID, context);
        entry7 = 0;
        if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>(this)->FUN_00853130(handle3, (*(::fnv_00853130::CombatThreatRecord * *)(&entry7))))
        {
            entry7 = (ReconstructEntry*)new ReconstructedCellStorage;
            reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(handle3, (unsigned int)(entry7));
        }
        reinterpret_cast<::fnv_008418b0::FUN_008418b0_shell *>((entry7))->GetOrCreateEntry(value, formID, context, (unsigned int)(form), flag, offset);
    }
}

namespace fnv_008421f0 {
struct BGSCellNumericIDArrayMap
{
    virtual ~BGSCellNumericIDArrayMap();
};
struct FUN_00844600
{
    unsigned int m_uiHashSize;
    void* m_ppHashTable;
    unsigned int m_uiCount;
    virtual ~FUN_00844600();
};
struct FUN_008421f0 : FUN_00844600
{
    BGSCellNumericIDArrayMap* m_pFirst;
    BGSCellNumericIDArrayMap* m_pSecond;
    virtual ~FUN_008421f0();
};
// Iterates the hash table deleting each BGSCellNumericIDArrayMap entry, then deletes m_pFirst and m_pSecond.
// @fnv 0x008421f0
FUN_008421f0::~FUN_008421f0()
{
    void* pPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (pPos)
    {
        unsigned int uiKey = 0;
        BGSCellNumericIDArrayMap* pItem = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(pPos), (unsigned int *)&(uiKey), (void **)&(pItem));
        delete pItem;
    }
    delete m_pFirst;
    delete m_pSecond;
}
}  // namespace fnv_008421f0


struct RegPoint
{
    float x, y, z;
    RegPoint();
};

struct RegRef;

struct RegLand
{
};

struct RegRef
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual int GetFormType();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual bool IsReference();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual bool GetPosition(RegPoint* apPos, RegPoint* apRot, int* apIndex, int aiUnk);
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual const RegPoint& GetPos();
};

struct RegList
{
    int unk00, unk04, unk08, unk0C, unk10;
    RegList();
};

struct RegFormTypeEntry
{
    int iKey;
    int unk04;
    int unk08;
};

struct RegManager
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    int iCount;

    void FUN_00842310(RegRef* apRef, int aiArg);
};

// Registers a reference by form type: resolves its cell/world position or land cell and dispatches to the matching registration routine.
// @fnv 0x00842310
void RegManager::FUN_00842310(RegRef* apRef, int aiArg)
{
    int iType9 = apRef->GetFormType();
    if (apRef->IsReference())
    {
        RegRef* pRef6 = apRef;
        RegPoint _kPos;
        RegPoint kRotX;
        int iIndex6 = 0;
        void* pWorldX = 0;
        void* pCellB = 0;
        if (pRef6->GetPosition(&_kPos, &kRotX, &iIndex6, 0))
            ::GetCellAndWorldspaceForForm((::TESForm *)(iIndex6), (*(::TESObjectCELL * *)(&pWorldX)), (*(::TESWorldSpace * *)(&pCellB)));
        else if ((pCellB = ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((pRef6))->FUN_00575d70()))) != 0)
            _kPos = pRef6->GetPos();
        else
            pWorldX = ((void *)(reinterpret_cast<::LowProcess *>((pRef6))->GetTarget()));
        if (pCellB)
        {
            int iX8 = FUN_00406d90(_kPos.x) >> 12;
            int kIY = FUN_00406d90(_kPos.y) >> 12;
            reinterpret_cast<::fnv_00842730::FUN_00842730_shell *>(this)->EnsureObjectAndCall((int)(pCellB), iX8, kIY, (int)(apRef), 0, aiArg);
        }
        else if (pWorldX)
            reinterpret_cast<::fnv_00842600::FUN_00842600_shell *>(this)->ProcessCell((::fnv_00842600::TESObjectCELL *)(pWorldX), (int)(apRef), 0, aiArg);
    }
    else if (iType9 == 0x43)
    {
        RegRef* pLandRef3 = apRef;
        RegLand* pLand4 = ((::RegLand *)(reinterpret_cast<::ActorMover *>((pLandRef3))->GetCurrentMoveModeType()));
        void* pLandCell9 = pLand4 ? ((void *)(reinterpret_cast<::TESObjectCELL *>((pLand4))->GetParentWorldSpace())) : 0;
        if (pLandCell9)
            reinterpret_cast<::fnv_00842730::FUN_00842730_shell *>(this)->EnsureObjectAndCall((int)(pLandCell9), reinterpret_cast<::TESObjectCELL *>((pLand4))->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>((pLand4))->GetCellGridY(), (int)(apRef), 0, aiArg);
        else if (pLand4)
            reinterpret_cast<::fnv_00842600::FUN_00842600_shell *>(this)->ProcessCell((::fnv_00842600::TESObjectCELL *)(pLand4), (int)(apRef), 0, aiArg);
    }
    else if (iType9 == 0x39)
        reinterpret_cast<::fnv_00842600::FUN_00842600_shell *>(this)->ProcessCell((::fnv_00842600::TESObjectCELL *)(apRef), (int)(apRef), 0, aiArg);
    else if (iType9 == 0x41)
        ;
    else
    {
        int iKey8 = (*reinterpret_cast<RegFormTypeEntry (*)[]>(&::DAT_01187008))[apRef->GetFormType()].iKey;
        RegList* pList5 = 0;
        if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>(this)->FUN_00853130(iKey8, (*(::fnv_00853130::CombatThreatRecord * *)(&pList5))))
        {
            pList5 = new RegList;
            reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(iKey8, (unsigned int)(pList5));
        }
        reinterpret_cast<::FUN_00841250_cls *>((pList5))->ProcessRef((::FUN_00841250_ref *)(apRef), (void *)(0), aiArg);
        iCount++;
    }
}


struct ExtendedForm : TESForm
{

    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual void vfn_64();
    virtual void vfn_65();
    virtual void vfn_66();
    virtual void vfn_67();
    virtual void vfn_68();
    virtual void vfn_69();
    virtual void vfn_70();
    virtual void vfn_71();
    virtual void vfn_72();
    virtual void vfn_73();
    virtual void vfn_74();
    virtual void vfn_75();
    virtual const char* GetFormDisplayName();
};

struct ExtendedFileMap : FUN_00842180
{
};

struct ReconstructMapHelper : BGSReconstructFormsInAllFilesMap
{
    void FUN_008438b0(ExtendedForm* form, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5);
};

// Resolves the form's source file, creates or fetches its ExtendedFileMap, adds the reference to it, and increments iCount; logs an error if no file is found.
// @fnv 0x008438b0
void ReconstructMapHelper::FUN_008438b0(ExtendedForm* form, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                                        unsigned int arg5)
{
    if (!form)
        return;

    TESFile* file = reinterpret_cast<::FUN_00843fe0_Holder *>((this))->FUN_00843fe0(((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((std::intptr_t)(form)))), arg4);
    if (!file)
    {
        FUN_00845cc0("Worldspace %08X %s with no file passed to BGSReconstructFormsInAllFilesMap::AddReference()",
                     ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())), form->GetFormDisplayName());
        return;
    }

    ExtendedFileMap* subMap = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((this))->FUN_00853130((unsigned int)(file), (::fnv_00853130::CombatThreatRecord *&)(subMap)))
    {
        subMap = new ExtendedFileMap();
        reinterpret_cast<::FUN_00844700_Class *>((this))->FUN_00844700((unsigned int)(file), (unsigned int)(subMap));
    }
    reinterpret_cast<::fnv_00842730::FUN_00842730_shell *>((subMap))->EnsureObjectAndCall((int)(form), arg2, arg3, 0, arg4, arg5);
    ++this->iCount;
}

namespace fnv_00843c90 {
struct SceneNode
{
};
struct ObjectBaseView
{
};
struct ReferenceView;
struct EnableState
{
};
struct WorldSpaceView
{
};
struct ActorBaseView
{
};
struct ProcessView
{
    virtual ~ProcessView();
};
struct FUN_00906dc0 : ProcessView
{
    FUN_00906dc0();
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2c;
    unsigned int field_30;
    unsigned int field_34;
    unsigned int field_38;
    unsigned int field_3c;
    unsigned int field_40;
    unsigned int field_44;
    unsigned int field_48;
    unsigned int field_4c;
    unsigned int field_50;
    unsigned int field_54;
    unsigned int field_58;
    unsigned int field_5c;
    unsigned int field_60;
    unsigned int field_64;
    unsigned int field_68;
    unsigned int field_6c;
    unsigned int field_70;
    unsigned int field_74;
    unsigned int field_78;
    unsigned int field_7c;
    unsigned int field_80;
    unsigned int field_84;
    unsigned int field_88;
    unsigned int field_8c;
    unsigned int field_90;
    unsigned int field_94;
    unsigned int field_98;
    unsigned int field_9c;
    unsigned int field_a0;
    unsigned int field_a4;
    unsigned int field_a8;
    unsigned int field_ac;
    unsigned int field_b0;
};
struct SecondaryForm
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void Reset(int);
};
struct ExtendedForm : TESForm
{
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
    unsigned int field_2c;
    virtual void slot61();
    virtual bool IsSecondaryForm();
};
struct MultipleForm : ExtendedForm, SecondaryForm
{
};
struct ReferenceView : ExtendedForm
{
    virtual bool IsMobile();
    virtual bool IsActor();
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
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual SceneNode* GetSceneNode();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual bool IsCreature();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void InitializeProcess();
    int FUN_00931850();
};
struct ActorDeletionQueue
{
};
struct SaveLoadView
{
};
struct ReconstructDataView : ChangedFormRecord
{
};
struct NavInfoView
{
};
struct NavFormView : TESForm
{
    int FUN_00401170();
};
struct ReconstructionWorker
{
    void ReconstructForm(ReconstructDataView* data);
};
// @fnv 0x00843c90
void ReconstructionWorker::ReconstructForm(ReconstructDataView* data)
{
    if (data->pForm->GetIsReference())
    {
        ReferenceView* reference = (ReferenceView*)data->pForm;
        SceneNode* sceneNode = reference->GetSceneNode();
        if (sceneNode && reinterpret_cast<::FUN_009cdae0_shell *>((sceneNode))->GetFloatAt64() != reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((reference))->FUN_00567400())
            reinterpret_cast<::fnv_00567490::ScaleReference *>((reference))->FUN_00567490(reinterpret_cast<::TESObjectREFR *>((reference))->GetScale());
        if (reinterpret_cast<::TESActorBaseData *>((data))->GetFlag(8) && reinterpret_cast<::FUN_00549580_shell *>((void *)(((::fnv_00843c90::ObjectBaseView *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()))))->FUN_00549580() && reinterpret_cast<::TESForm *>((reference))->GetDisabled())
        {
            WorldSpaceView* world = ((::fnv_00843c90::WorldSpaceView *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((reference))->FUN_00575d70()));
            if (world)
                reinterpret_cast<::Dfcfa0Manager *>((((::fnv_00843c90::EnableState *)(reinterpret_cast<::TESWorldSpace *>((world))->GetWorldTerrainManager()))))->FUN_006fcfa0({}, {});
        }
        if (reference->IsMobile())
        {
            ReferenceView* mobile = reference;
            if (reinterpret_cast<::FUN_00437b90_shell *>((mobile))->FUN_00437b90())
            {
                if (reinterpret_cast<::TESActorBaseData *>((data))->GetFlag(8) && ((::fnv_00843c90::ProcessView *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile))->GetBaseTexture())))
                {
                    reinterpret_cast<::ActorDeletionQueue *>(&((*reinterpret_cast<::fnv_00843c90::ActorDeletionQueue *>(&::g_011e0e80))))->FUN_0096d470((::MobileObject *)(mobile), mobile->FUN_00931850());
                    delete ((::fnv_00843c90::ProcessView *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile))->GetBaseTexture()));
                    reinterpret_cast<::MiddleHighProcess *>((mobile))->SetFaceAnimationData((::TargetDoorController *)(::fnv_00843c90::ProcessView *)(0));
                }
            }
            else if (!((::fnv_00843c90::ProcessView *)(reinterpret_cast<::BSShaderNoLightingProperty *>((mobile))->GetBaseTexture())))
            {
                reinterpret_cast<::MiddleHighProcess *>((mobile))->SetFaceAnimationData((::TargetDoorController *)(::fnv_00843c90::ProcessView *)(new FUN_00906dc0));
                mobile->InitializeProcess();
            }
            if (mobile->IsActor())
            {
                ReferenceView* actor = mobile;
                reinterpret_cast<::Outer *>((((SaveLoadView*)::g_BGSSaveLoadGame)))->FUN_0084a520((::ParamOwner *)(actor));
                if (reinterpret_cast<::TESActorBaseData *>((data))->GetFlag(8) && actor->GetSceneNode())
                {
                    if (actor->IsCreature())
                    {
                        ActorBaseView* creatureBase = ((::fnv_00843c90::ActorBaseView *)(reinterpret_cast<::Actor *>((actor))->GetActorBase()));
                        reinterpret_cast<::CreatureEquipment *>((creatureBase))->FUN_005f9e00((::TESObjectREFR *)(actor), true, true, true);
                    }
                    else
                    {
                        ActorBaseView* npcBase = ((::fnv_00843c90::ActorBaseView *)(reinterpret_cast<::Actor *>((actor))->GetActorBase()));
                        reinterpret_cast<::TESNPC *>((npcBase))->FUN_006047c0((::TESObjectREFR *)(actor), true, true, false, true);
                    }
                }
            }
        }
    }
    else if (((ExtendedForm*)data->pForm)->IsSecondaryForm())
    {
        MultipleForm* form = (MultipleForm*)data->pForm;
        SecondaryForm* secondary = form;
        secondary->Reset(0);
    }
    else if (((NavFormView*)data->pForm)->FUN_00401170() == 0x43)
    {
        NavFormView* pNavForm = (NavFormView*)data->pForm;
        if (((::fnv_00843c90::NavInfoView *)(reinterpret_cast<::FUN_0068efb0_shell *>((pNavForm))->FUN_0068efb0())))
            reinterpret_cast<::TESForm *>((((::fnv_00843c90::NavInfoView *)(reinterpret_cast<::FUN_0068efb0_shell *>((pNavForm))->FUN_0068efb0()))))->SetCollisionDisabled(reinterpret_cast<::TESForm *>((pNavForm))->GetDisabled());
    }
}
}  // namespace fnv_00843c90

class B844F00Allocator;

class B844F00MemoryManager
{
  public:
};


class B844F00Base
{
  public:
    B844F00Base();
    virtual ~B844F00Base();


    int unk04;
    int unk08;
    int unk0C;
    B844F00Allocator* m_pHeapAllocator;
};

class FUN_00844f00_cls : public B844F00Base
{
  public:
    FUN_00844f00_cls(int iSize, int iGrowBy, B844F00Allocator* pkAllocator);
    virtual ~FUN_00844f00_cls();
};

// Stores the given allocator, or the memory manager's default allocator when none is given, then calls Init with the size and grow-by values.
// @fnv 0x00844f00
FUN_00844f00_cls::FUN_00844f00_cls(int iSize, int iGrowBy, B844F00Allocator* pkAllocator)
{
    m_pHeapAllocator = pkAllocator ? pkAllocator : ((::B844F00Allocator *)(reinterpret_cast<::MemoryManager *>((((::B844F00MemoryManager *)(::FUN_00401020()))))->GetGeneralAllocator()));
    reinterpret_cast<::SaveGameSizeState *>(this)->RecordRequestedSize(iSize, iGrowBy);
}

struct Val8443
{
    int a;
    int b;
};
struct Item8443
{
    Item8443* m_pkNext;
    unsigned int m_key;
    Val8443 m_val;
};
class FUN_8443Map
{
  public:
    virtual ~FUN_8443Map();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int key1, unsigned int key2);
    unsigned int m_uiHashSize;
    Item8443** m_ppkHashTable;
    bool Lookup(unsigned int key, Val8443& val);
};
// Hashes the key, walks the bucket chain comparing keys, and copies the matching item's value into val, returning whether a match was found.
// @fnv 0x008443f0
bool FUN_8443Map::Lookup(unsigned int key, Val8443& val)
{
    unsigned int uiIndex = KeyToHashIndex(key);
    Item8443* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (IsKeysEqual(key, pkItem->m_key))
        {
            val = pkItem->m_val;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

class FUN_008444d0
{
  public:
    virtual ~FUN_008444d0();
};
class FUN_00844470 : public FUN_008444d0
{
  public:
    virtual ~FUN_00844470();
};
// Destructor that calls FUN_00438af0 before the object is destroyed.
// @fnv 0x00844470
FUN_00844470::~FUN_00844470()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

// Prior reconstruction by another contributor (2026-10-23); unverified; attribution retained.

struct RebuildFile;

struct RebuildForm
{
};

struct RebuildMap;

struct RebuildResult
{

    RebuildForm* form;
    RebuildMap* recordC;

    RebuildResult();
    RebuildResult(RebuildForm*, RebuildMap*);

};

struct RebuildHeader
{
    unsigned int type, sizeXA, label, group, formId4;
};

struct RebuildFile
{



};

struct RebuildMap
{



};

struct RebuildQueue
{

    unsigned int unk00, unk04, unk08, unk0c, unk10;

    RebuildQueue();
    ~RebuildQueue();


};

struct RebuildCoordinates
{
    int x, y, z;
    RebuildCoordinates();
};

struct RebuildOutput
{
};

struct RebuildLoader
{
};







extern unsigned int DAT_011873c8;



struct RebuildRoot : RebuildMap
{

    unsigned int unk00, unk04, unk08, unk0c;

    RebuildMap* defaultMap;
    RebuildMap* worlds;
    unsigned int count;

    void RebuildForms(RebuildFile*, RebuildOutput*);
};
// @fnv 0x008439e0
void BGSReconstructFormsInAllFilesMap::BuildMap()
{
    struct LocalState
    {
        ChangedFormRecord* reconstructForm;
        unsigned int reconstructIndex;
        ChangedFormRecord* initializeForm;
        unsigned int initializeIndex;
        TESForm* form;
        ChangedFormRecord* removedForm;
        unsigned int removeIndex;
        TESFile* threadSafeFile;
        BGSReconstructFormsInFileMap* map;
        TESFile* file;
        unsigned char padding0;
        unsigned char padding1;
        unsigned char padding2;
        bool wasLocked;
        unsigned int size;
        void* position;
    } state;

    reinterpret_cast<::FUN_00843c10_shell *>((::g_BGSSaveLoadGame))->SetFlag4(true);
    reinterpret_cast<::H00843be0 *>(&(m_kFormChangeMap))->FUN_00843be0(iCount);
    state.wasLocked = reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004516b0();
    reinterpret_cast<::FUN_00550890_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->SetBoolAt61a(true);

    state.position = GetFirstPos();
    while (state.position)
    {
        state.file = 0;
        state.map = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(state.position), (unsigned int *)&(state.file), (void **)&(state.map));
        state.threadSafeFile = state.file->GetParentTESFile();
        reinterpret_cast<::RebuildRoot *>((state.map))->RebuildForms((::RebuildFile *)(state.threadSafeFile), (::RebuildOutput *)(::FormChangeMap *)(&m_kFormChangeMap));
    }

    reinterpret_cast<::FUN_00550890_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->SetBoolAt61a(state.wasLocked);

    state.removeIndex = 0;
    for (; state.removeIndex < reinterpret_cast<::FUN_00843bb0_shell *>(&(m_kFormChangeMap))->GetCombinedFlags(); ++state.removeIndex)
    {
        state.removedForm = m_kFormChangeMap.FUN_008432e0(state.removeIndex);
        if (state.removedForm->pForm->GetIsReference())
        {
            state.form = state.removedForm->pForm;
            if (!((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<TESObjectREFR*>(state.form)))->FUN_007af430())))
            {
                reinterpret_cast<::ArrSI *>(&(m_kFormChangeMap))->FUN_00843380(state.removeIndex);
                --state.removeIndex;
            }
        }
    }

    state.size = reinterpret_cast<::FUN_00843bb0_shell *>(&(m_kFormChangeMap))->GetCombinedFlags();
    state.initializeIndex = 0;
    for (; state.initializeIndex < state.size; ++state.initializeIndex)
    {
        state.initializeForm = m_kFormChangeMap.FUN_008432e0(state.initializeIndex);
        if (!reinterpret_cast<::TESForm *>((void *)(reinterpret_cast<TESFormInitFlag*>(state.initializeForm->pForm)))->GetInitialized())
            state.initializeForm->pForm->InitItem();
    }

    state.reconstructIndex = 0;
    for (; state.reconstructIndex < state.size; ++state.reconstructIndex)
    {
        state.reconstructForm = m_kFormChangeMap.FUN_008432e0(state.reconstructIndex);
        AddFormFlagEntry(state.reconstructForm);
    }

    reinterpret_cast<::FUN_00843c10_shell *>((::g_BGSSaveLoadGame))->SetFlag4(false);
}

// Walks a RebuildFile, resolving world/block/record context and reconstructing forms into output, queueing pending results as needed.
// @fnv 0x008427f0
void RebuildRoot::RebuildForms(RebuildFile* file, RebuildOutput* output)

{

    if (!count)
        return;

    reinterpret_cast<::FUN_00471f80_shell *>((file))->ResetFileState(true);

    RebuildHeader* pData7 = ((::RebuildHeader *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));

    while (pData7->type == DAT_01187014)
        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

    RebuildMap* world8 = 0;

    RebuildMap* block3 = 0;

    RebuildMap* subBlock = 0;

    RebuildMap* recordC = 0;

    unsigned int idA = 0;
    unsigned int formId4 = 0;

    (*reinterpret_cast<::RebuildForm * *>(&::DAT_011c3f30)) = 0;

    bool cached = reinterpret_cast<::TESFile *>((file))->GetOptimizedFile();

    unsigned int restoredA = 0;

    RebuildQueue queued3;

    unsigned int next4 = 0;

    unsigned int groupEndA = 0;

    bool pending4 = false;

    while (pData7->type && restoredA < count)
    {

        RebuildResult result;

        if (pData7->type == ::fnv_00543df0::kGroupFormType)
        {

            if (pData7->label == DAT_011872b4 || pData7->label == (*reinterpret_cast<unsigned int *>((void *)&::fnv_00543f50::str_01187314)))
            {

                world8 = 0;

                bool isWorld = pData7->label == (*reinterpret_cast<unsigned int *>((void *)&::fnv_00543f50::str_01187314));

                if (isWorld)
                {

                    if (worlds)
                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

                    else
                        reinterpret_cast<::TESFile *>((file))->IsGroupOpen();
                }
                else
                {

                    if (defaultMap)
                    {
                        world8 = defaultMap;
                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
                    }

                    else
                        reinterpret_cast<::TESFile *>((file))->IsGroupOpen();
                }

                block3 = 0;
                subBlock = 0;
                recordC = 0;
            }
            else if (pData7->group)
            {

                switch (pData7->group)
                {

                case 1: {

                    unsigned int id = pData7->label;

                    ::ResolveFormID(&id, (::TESFile *)(file));

                    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((worlds))->FUN_00853130(id, (*(::fnv_00853130::CombatThreatRecord * *)(&world8))))
                    {

                        if (cached && reinterpret_cast<::fnv_00841e20::FUN_00841e20_shell *>((world8))->HasFlagInAnyFile(5))
                            reinterpret_cast<::FUN_008431c0_Class *>(&(queued3))->ConstructAndForward((void *)(pData7->formId4), 0);

                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
                    }
                    else
                        reinterpret_cast<::TESFile *>((file))->IsGroupOpen();

                    block3 = 0;
                    subBlock = 0;
                    recordC = 0;
                }
                break;

                case 2:
                case 4:

                    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((world8))->FUN_00853130(pData7->label, (*(::fnv_00853130::CombatThreatRecord * *)(&block3))))
                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

                    else
                        reinterpret_cast<::TESFile *>((file))->IsGroupOpen();

                    subBlock = 0;
                    recordC = 0;

                    break;

                case 3:
                case 5:

                    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((block3))->FUN_00853130(pData7->label, (*(::fnv_00853130::CombatThreatRecord * *)(&subBlock))))
                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

                    else
                        reinterpret_cast<::TESFile *>((file))->IsGroupOpen();

                    recordC = 0;

                    break;

                case 6:

                    if (recordC)
                    {

                        bool persistent = reinterpret_cast<::FUN_00452420_shell *>((recordC))->GetFlag(2);

                        bool temp = reinterpret_cast<::FUN_00452420_shell *>((recordC))->GetFlag(4);

                        if (cached && !idA && temp)
                        {

                            reinterpret_cast<::FUN_008431c0_Class *>(&(queued3))->ConstructAndForward((void *)(pData7->formId4), recordC);
                            temp = false;
                        }

                        if (persistent || temp)
                            reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

                        else
                            reinterpret_cast<::TESFile *>((file))->IsGroupOpen();
                    }
                    else
                        reinterpret_cast<::TESFile *>((file))->IsGroupOpen();

                    break;

                case 8:

                    if (reinterpret_cast<::FUN_00452420_shell *>((recordC))->GetFlag(2))
                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

                    else
                        reinterpret_cast<::TESFile *>((file))->IsGroupOpen();

                    break;

                case 9:

                    if (reinterpret_cast<::FUN_00452420_shell *>((recordC))->GetFlag(4))
                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

                    else
                        reinterpret_cast<::TESFile *>((file))->IsGroupOpen();

                    break;

                default:
                    reinterpret_cast<::TESFile *>((file))->IsGroupOpen();
                }
            }
            else
            {

                if (reinterpret_cast<::fnv_00853130::NiTMapBase *>(this)->FUN_00853130(pData7->label, (*(::fnv_00853130::CombatThreatRecord * *)(&recordC))))
                    reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

                else
                    reinterpret_cast<::TESFile *>((file))->IsGroupOpen();
            }
        }
        else if (pData7->type == (*reinterpret_cast<unsigned int *>((void *)&::fnv_00543f50::str_01187314)))
        {

            idA = pData7->group;

            reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
        }
        else if (pData7->type == DAT_011872b4)
        {

            if (subBlock)
            {

                formId4 = pData7->group;

                unsigned int key = formId4;

                if (world8 && reinterpret_cast<::FUN_00843150_shell *>((world8))->FUN_00843150())
                {

                    RebuildCoordinates coords9;

                    ::FUN_00403d30(&coords9, 0, 12);

                    unsigned int type3 = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()));

                    while (type3)
                    {

                        if (type3 == 0x434c4358)
                        {

                            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&coords9), 12);

                            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                                reinterpret_cast<::S_00462230 *>(&(coords9))->FUN_00462230();

                            break;
                        }
                        type3 = reinterpret_cast<::TESFile *>((file))->NextChunk() ? ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) : 0;
                    }

                    reinterpret_cast<::FUN_00472000_class *>((file))->SkipCurrentForm();

                    key = ((unsigned int)(::PackShortPair((unsigned short)coords9.x, (unsigned short)coords9.y)));
                }

                (*reinterpret_cast<::RebuildForm * *>(&::DAT_011c3f30)) = 0;

                if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((subBlock))->FUN_00853130(key, (*(::fnv_00853130::CombatThreatRecord * *)(&recordC))))
                {

                    if (reinterpret_cast<::FUN_00452420_shell *>((recordC))->GetFlag(1))
                    {

                        reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::RebuildLoader * *>(&::g_dataHandler))))->ConstructObject((::TESFile *)(file), 0, (::TESForm *)(::RebuildForm *)(0), false);

                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

                        RebuildForm* form = ((::RebuildForm *)(::FUN_004839c0(formId4)));

                        if (form)
                        {

                            RebuildResult cell(form, ((::RebuildMap *)(reinterpret_cast<::MagicCaster_shell *>((recordC))->FUN_0044edb0())));

                            reinterpret_cast<::FUN_00843270_shell *>((output))->FUN_00843270((::ChangedFormRecord *)(::RebuildResult *)(&cell));
                        }
                        else
                            FUN_00845cc0("Cell with Form ID %08X was not able to be reconstructed", formId4);

                        ++restoredA;
                    }
                    else
                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
                }
                else
                    reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
            }
            else
            {

                recordC = ((::RebuildMap *)(reinterpret_cast<::MagicCaster_shell *>((world8))->FUN_0044edb0()));

                formId4 = pData7->group;

                (*reinterpret_cast<::RebuildForm * *>(&::DAT_011c3f30)) = 0;

                reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
            }
        }
        else if (pData7->type == DAT_011873c8)
        {

            unsigned int id = pData7->group;

            if (id == -1 || id == -2)
            {

                if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(queued3))->GetName())))
                {

                    result = *((::RebuildResult *)(reinterpret_cast<::FUN_00844160_shell *>(&(queued3))->FUN_00844160(next4++)));

                    pending4 = true;
                }
                else
                    pData7->type = 0;
            }
            else
                reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
        }
        else
        {

            RebuildResult item;

            unsigned int id = pData7->group;

            reinterpret_cast<::FUN_00841320_shell *>((recordC))->FUN_00841320(0x10000);

            if (reinterpret_cast<::FUN_8443Map *>((recordC))->Lookup(id, (*(::Val8443 *)(&item))))
            {

                if (formId4 && (!(*reinterpret_cast<::RebuildForm * *>(&::DAT_011c3f30)) || ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<::RebuildForm * *>(&::DAT_011c3f30))))->FUN_0084e3a0())) != formId4))
                    (*reinterpret_cast<::RebuildForm * *>(&::DAT_011c3f30)) = ((::RebuildForm *)(::FUN_004839c0(formId4)));

                reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::RebuildLoader * *>(&::g_dataHandler))))->ConstructObject((::TESFile *)(file), 0, (::TESForm *)(item.form), true);

                reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);

                if (!item.form)
                    item.form = ((::RebuildForm *)(::FUN_004839c0(id)));

                if (item.form)
                    reinterpret_cast<::FUN_00843270_shell *>((output))->FUN_00843270((::ChangedFormRecord *)(::RebuildResult *)(&item));

                else
                    FUN_00845cc0("Form %08X with type %s was not able to be reconstructed", id,
                                 ::GetStringForByte((unsigned char)(((const char *)(::FindFormEnumIndex(pData7->type))))));

                ++restoredA;
            }
            else
                reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
        }

        if (groupEndA && groupEndA <= reinterpret_cast<::TESFile *>((file))->GetOffset())
        {

            if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(queued3))->GetName())) > next4)
                result = *((::RebuildResult *)(reinterpret_cast<::FUN_00844160_shell *>(&(queued3))->FUN_00844160(next4++)));

            else
                pData7->type = 0;
        }

        if (reinterpret_cast<::FUN_005ca4f0_shell *>(&(result))->FUN_005ca4f0())
        {

            reinterpret_cast<::TESOffsetWorker *>((file))->FUN_004723a0((unsigned int)(result.form));

            unsigned int sizeXA = 0;

            unsigned int key17 = 0;

            if (pData7->group == 1)
            {

                key17 = pData7->label;

                sizeXA = pData7->sizeXA;

                reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
            }
            else
                sizeXA = pData7->sizeXA;

            world8 = 0;
            block3 = 0;
            subBlock = 0;
            recordC = 0;
            formId4 = 0;
            idA = 0;

            groupEndA = reinterpret_cast<::TESFile *>((file))->GetOffset() + sizeXA;

            if (key17)
            {

                idA = key17;

                reinterpret_cast<::fnv_00853130::NiTMapBase *>((worlds))->FUN_00853130(idA, (*(::fnv_00853130::CombatThreatRecord * *)(&world8)));
            }
            else
            {

                recordC = result.recordC;

                formId4 = pData7->label;
            }

            reinterpret_cast<::FUN_00843170_shell *>(&(result))->ClearFields();

            if (idA && pData7->group == 9)
                reinterpret_cast<::TESFile *>((file))->IsGroupOpen();
        }
    }

    (*reinterpret_cast<::RebuildForm * *>(&::DAT_011c3f30)) = 0;
}

struct MapValue41f
{
    virtual ~MapValue41f();
};
struct MapBase41f
{
    virtual ~MapBase41f();
};
struct MapOwner841 : MapBase41f
{
    virtual ~MapOwner841();
};
// Calls FUN_00841f00, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00841ed0
void* BGSReconstructWorldSpacesMap::FUN_00841ed0(unsigned int flags)
{
    reinterpret_cast<::MapOwner841 *>(this)->MapOwner841::~MapOwner841();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Iterates the map via FUN_004b9ba0 and FUN_006b7f20, deleting each MapValue41f data entry.
// @fnv 0x00841f00
MapOwner841::~MapOwner841()
{
    void* pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(this)->GetFirstPos();
    while (pos)
    {
        unsigned int key = 0;
        MapValue41f* data = 0;
        reinterpret_cast<::C6b7f20_Map *>(this)->FUN_006b7f20((::C6b7f20_Node **)&(pos), (unsigned int *)&(key), (void **)&(data));
        delete data;
    }
}

struct ReconstructCellEntry : FUN_00841190
{
};

struct ReconstructCell
{
};


struct ReconstructCellMap
{
};

struct BGSReconstructCellsMapImpl : ReconstructCellMap
{
    void FUN_00841460(ReconstructCell* apCell, ReconstructCell* apOther, unsigned int auiArg1, unsigned int auiArg2);
};

// Computes a key for apCell, creates a ReconstructCellEntry in the map if missing, then adds flags or stores apOther with auiArg1 and auiArg2.
// @fnv 0x00841460
void BGSReconstructCellsMapImpl::FUN_00841460(ReconstructCell* apCell, ReconstructCell* apOther, unsigned int auiArg1,
                                              unsigned int auiArg2)
{
    unsigned int uiKey4 = 0;
    if (reinterpret_cast<::TESObjectCELL *>((apCell))->IsCellInterior())
        uiKey4 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apCell))->FUN_0084e3a0()));
    else
        uiKey4 = ::PackShortPair(reinterpret_cast<::TESObjectCELL *>((apCell))->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>((apCell))->GetCellGridY());

    ReconstructCellEntry* pEntry = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)this)->FUN_00853130(uiKey4, (::fnv_00853130::CombatThreatRecord *&)(pEntry)))
    {
        pEntry = (ReconstructCellEntry*)new FUN_00841190;
        reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(uiKey4, (unsigned int)(pEntry));
    }

    if (apCell == apOther)
    {
        reinterpret_cast<::FUN_00841320_shell *>((pEntry))->FUN_00841320(1);
        reinterpret_cast<::FUN_00841320_shell *>((pEntry))->FUN_00841320(auiArg2);
    }
    else
    {
        reinterpret_cast<::FUN_00841250_cls *>((pEntry))->ProcessRef((::FUN_00841250_ref *)(apOther), (void *)(auiArg1), auiArg2);
    }
}

struct FUN_00843750_Form : public TESForm
{
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual const char* GetEditorID();
};
struct FUN_00842600_shell : public FUN_00842180
{
};
struct FUN_00843750_shell : public BGSReconstructFormsInAllFilesMap
{
    void FUN_00843750(FUN_00843750_Form* apRef, unsigned int auiArg1, unsigned int auiArg2);
};
// Adds a form reference to the per-file map, creating the map if needed, and increments iCount.
// @fnv 0x00843750
void FUN_00843750_shell::FUN_00843750(FUN_00843750_Form* apRef, unsigned int auiArg1, unsigned int auiArg2)
{
    if (!apRef)
        return;
    TESFile* pFile = 0;
    if (reinterpret_cast<::TESObjectCELL *>((apRef))->IsCellInterior())
        pFile = ((FUN_00843fe0_Holder*)this)->FUN_00843fe0(((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((std::intptr_t)(apRef)))), auiArg1);
    else
        pFile = ((FUN_00843fe0_Holder*)this)->FUN_00843fe0(((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((std::intptr_t)(((::FUN_00843750_Form *)(reinterpret_cast<::TESObjectCELL *>((apRef))->GetParentWorldSpace())))))), auiArg1);
    if (!pFile)
    {
        FUN_00845cc0("Cell %08X %s with no file passed to BGSReconstructFormsInAllFilesMap::AddReference()",
                     ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apRef))->FUN_0084e3a0())), apRef->GetEditorID());
        return;
    }
    FUN_00842180* pFileMap = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)this)->FUN_00853130((unsigned int)(pFile), (::fnv_00853130::CombatThreatRecord *&)(pFileMap)))
    {
        pFileMap = new FUN_00842180;
        reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700((unsigned int)(pFile), (unsigned int)(pFileMap));
    }
    reinterpret_cast<::fnv_00842600::FUN_00842600_shell *>((((FUN_00842600_shell*)pFileMap)))->ProcessCell((::fnv_00842600::TESObjectCELL *)(apRef), 0, auiArg1, auiArg2);
    iCount++;
}


struct ReconstructMapDeletingView : BGSReconstructFormsInAllFilesMap
{
    void* FUN_00843440(unsigned int flags);
};

// Destroys the BGSReconstructFormsInAllFilesMap base and deallocates the object when flags has bit 0 set.
// @fnv 0x00843440
void* ReconstructMapDeletingView::FUN_00843440(unsigned int flags)
{
    BGSReconstructFormsInAllFilesMap::~BGSReconstructFormsInAllFilesMap();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

#include "generated/data/fallout/misc/saveload/bgsreconstructformsinallfilesmap.inc"
