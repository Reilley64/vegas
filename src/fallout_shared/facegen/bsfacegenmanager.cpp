// fallout_shared/facegen/bsfacegenmanager.cpp: BSFaceGenManager, FGModelCache, BSFaceGenModelMap_t, TESRace and more (111 functions)

#include <new>
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenModel.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderPPLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DecalStub.h"
#include "fnv/decl/ExtraOwnerB.h"
#include "fnv/decl/FR2MatrixVTCData.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00449610.h"
#include "fnv/decl/FUN_0044a970_Cls.h"
#include "fnv/decl/FUN_0044ac20_class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004538e0_Class.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_004adde0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00534570_shell.h"
#include "fnv/decl/FUN_005ca4f0_shell.h"
#include "fnv/decl/FUN_00601800_shell.h"
#include "fnv/decl/FUN_0060b860_Cls.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_0063f790_shell.h"
#include "fnv/decl/FUN_0064dbd0_Class.h"
#include "fnv/decl/FUN_0064dda0_cls.h"
#include "fnv/decl/FUN_0064de50_class.h"
#include "fnv/decl/FUN_0064fe10_cls.h"
#include "fnv/decl/FUN_00657880_class.h"
#include "fnv/decl/FUN_00657be0_class.h"
#include "fnv/decl/FUN_00657cd0_cls.h"
#include "fnv/decl/FUN_00657d50_cls.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00658aa0_class.h"
#include "fnv/decl/FUN_00659c70_shell.h"
#include "fnv/decl/FUN_0065a910_shell.h"
#include "fnv/decl/FUN_0065a970_shell.h"
#include "fnv/decl/FUN_0065c090_shell.h"
#include "fnv/decl/FUN_0065c110_t.h"
#include "fnv/decl/FUN_0065cc50_Class.h"
#include "fnv/decl/FUN_0065cea0_class.h"
#include "fnv/decl/FUN_0065dfd0_class.h"
#include "fnv/decl/FUN_00662460_shell.h"
#include "fnv/decl/FUN_00662820_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0094db80_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a673d0_shell.h"
#include "fnv/decl/FanControlsV7.h"
#include "fnv/decl/Flag512Receiver.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Map62d0.h"
#include "fnv/decl/MeshLoader.h"
#include "fnv/decl/Mgr.h"
#include "fnv/decl/Mgr_e74120.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/RaceAppearance__Race.h"
#include "fnv/decl/S00a67410.h"
#include "fnv/decl/S9fb0.h"
#include "fnv/decl/S_0060b980.h"
#include "fnv/decl/S_0064dac0.h"
#include "fnv/decl/S_006503b0_Owner.h"
#include "fnv/decl/S_0082f1f0_Lock.h"
#include "fnv/decl/TESModelTextureSwap.h"
#include "fnv/decl/TESNPC.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Unk060b8a0.h"
#include "fnv/decl/V_006578b0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/VecStandIn.h"
#include "fnv/decl/_Dummy_0044a170.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/fnv_004436c0__FUN_004436c0_Class.h"
#include "fnv/decl/fnv_00448080__Owner448.h"
#include "fnv/decl/fnv_00540570__FUN_00540570_Owner.h"
#include "fnv/decl/fnv_006505d0__FUN_006505d0_class.h"
#include "fnv/decl/fnv_0065bf80__FUN_0065bf80_shell.h"
#include "fnv/decl/fnv_0065c400__FUN_0065c400_t.h"
#include "fnv/decl/fnv_0065f550__FUN_0065f550_Class.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0098ddd0__FUN_0098ddd0_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00aac170__Sub_00aabdb0.h"
#include "fnv/decl/s44b130__Lock.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00449000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00604000.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_00607000.h"
#include "fnv/symbols_00615000.h"
#include "fnv/symbols_00650000.h"
#include "fnv/symbols_00651000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00655000.h"
#include "fnv/symbols_00656000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a5f000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aaa000.h"
#include "fnv/symbols_00aaf000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_00afd000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01200000.h"
#include "bsfacegenmanager_decls.h"
// @fnv 0x006521e0
FaceGenCoordinates* BSFaceGenManager::GetFaceGenCoordinates()
{
    return &GetFaceGenManager()->coords;
}

// @fnv 0x00651b30
BSFaceGenManager* BSFaceGenManager::GetFaceGenManager()
{
    if (!DAT_011d59e8)
        FUN_006519f0();
    return DAT_011d59e8;
}

// @fnv 0x006131a0
BGSTextureModel* TESRace::GetBodyTextureModel(int sex)
{
    return &models[sex];
}

// @fnv 0x00652110
BSFaceGenModelMap* BSFaceGenManager::GetModelMap()
{
    if (!DAT_011d59e8)
        return 0;
    return DAT_011d59e8->cache;
}

// If values and count are non-zero, zeroes count floats in the values array.
// @fnv 0x00653e20
void BSFaceGenManager::NormalizeFaceGenValues(float* values, unsigned int count)
{
    if (!values || !count)
        return;
    memset(values, 0, count * 4);
}

// Returns SEX based on the base flag when the form type is NPC_FORM, otherwise SEX_NONE.
// @fnv 0x005f0cc0
SEX TESActorBase::GetSex() const
{
    if (GetFormType() == NPC_FORM)
        return static_cast<SEX>(base.GetFlag(1) ? 1 : 0);
    return SEX_NONE;
}

// Resizes the three coordinate arrays in coords to 50, 30 and 50 entries respectively, returning early if coords is null.
// @fnv 0x006521f0
void BSFaceGenManager::InitializeFaceGenCoordinates(FaceGenCoordinates* coords)
{
    if (!coords)
        return;
    reinterpret_cast<::FR2MatrixVTCData *>(&(reinterpret_cast<FaceGenCoordArray*>(coords)[0]))->SetDimensions(50, true);
    reinterpret_cast<::FR2MatrixVTCData *>(&(reinterpret_cast<FaceGenCoordArray*>(coords)[1]))->SetDimensions(30, true);
    reinterpret_cast<::FR2MatrixVTCData *>(&(reinterpret_cast<FaceGenCoordArray*>(coords)[2]))->SetDimensions(50, true);
}

// Copies DAT_0104aad0 into dest, then appends DAT_0119b734[part] for part 0 or 1 (else index 0), and returns dest.
// @fnv 0x00657820
char* BSFaceGenManager::BuildFaceGenPartPath(char* dest, int part)
{
    ::FUN_004046f0(dest, DAT_0104aad0);
    if (part > -1 && part < 2)
        FUN_00ec6380(dest, DAT_0119b734[part]);
    else
        FUN_00ec6380(dest, DAT_0119b734[0]);
    return dest;
}

// If values and count are non-zero, either zeroes count floats or sets each to DAT_01016970.
// @fnv 0x00653dc0
void BSFaceGenManager::ApplyFaceGenValues(float* values, unsigned int count, bool zero)
{
    if (!values || !count)
        return;
    if (zero)
        memset(values, 0, count * 4);
    else
        for (unsigned int i = 0; i < count; i++)
            values[i] = DAT_01016970;
}

// Destructor for FaceGenPaletteEntry; performs no work.
// @fnv 0x0043ebb0
FaceGenPaletteEntry::~FaceGenPaletteEntry()
{}

namespace std {
template <class _Elem> struct char_traits;
template <class _Ty> class allocator;
template <class _Elem, class _Traits, class _Ax> class basic_string
{
  public:
    char* _Myptr();
};
}

// @fnv 0x0044a560
char* FUN_0044a560(std::basic_string<char, std::char_traits<char>, std::allocator<char> >* pThis)
{
    return reinterpret_cast<::FUN_0044a970_Cls *>((pThis))->FUN_0044a970();
}

struct Struct_004b0680
{
    Struct_004b0680(float* p);
};
struct FUN_0060b370_shell
{
    char pad[0x1c];
    unsigned int cols;
    Struct_004b0680 FUN_0060b370(int i);
};
// Returns a Struct_004b0680 wrapping the element pointer at row i, computed as the base of column 0 plus i times cols.
// @fnv 0x0060b370
Struct_004b0680 FUN_0060b370_shell::FUN_0060b370(int aiRow)
{
    return Struct_004b0680(((float *)(reinterpret_cast<::V_006578b0 *>((void *)this)->FUN_006578b0(0))) + aiRow * cols);
}

extern int DAT_01065678;

struct Dummy658aa0
{
};

// @fnv 0x0064fd80
void* FUN_0064fd80(void* pThis)
{
    *(int**)pThis = &DAT_01065678;
    reinterpret_cast<::FUN_00658aa0_class *>((((Dummy658aa0*)((char*)pThis + 4))))->Initialize(0x25, 1);
    for (unsigned int cnt = 0; cnt < 2; ++cnt)
    {
        ((unsigned int*)((char*)pThis + 0x18))[cnt] = 0x10000000;
    }
    *((unsigned char*)pThis + 0x20) = 0;
    return pThis;
}


struct NiMemObject
{
    static void __cdecl operator delete(void*, unsigned int);
};

struct FUN_00650170_thiscall
{
    void* DestroyIfFlagged(unsigned int flags);
};

struct NiNode;
struct EBase
{
    int a;
    int b;
    ~EBase();
};
struct FUN_006501a0_shell : EBase
{
    NiPointer<NiNode> sp;
    ~FUN_006501a0_shell();
};
// Calls FUN_00659b50 on this, then deletes this via NiMemObject::operator delete when flags has bit 1 set, and returns this.
// @fnv 0x00650170
void* FUN_00650170_thiscall::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_006501a0_shell *>((this))->FUN_006501a0_shell::~FUN_006501a0_shell();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}
// @fnv 0x006501a0
FUN_006501a0_shell::~FUN_006501a0_shell()
{}

template <typename T> struct BSStringT
{
    operator const char*() const;
};

// Returns the string held by the BSStringT pointer stored at pThis+0xC, or null if that pointer is null.
// @fnv 0x00650600
const char* FUN_00650600(char* pThis)
{
    return *reinterpret_cast<BSStringT<char>**>(pThis + 0xC)
               ? static_cast<const char*>(**reinterpret_cast<BSStringT<char>**>(pThis + 0xC))
               : 0;
}

struct FUN_006508e0_shell
{
    char pad[0x18];
    int arr[4];
    void FUN_00650ba0(int);
    void SetArrayValue(int i, int v);
};
// Stores v into arr[i] and then calls FUN_00650ba0(0).
// @fnv 0x006508e0
void FUN_006508e0_shell::SetArrayValue(int aiIndex, int aiValue)
{
    arr[aiIndex] = aiValue;
    FUN_00650ba0(0);
}

struct Dummy_00650910
{
    int pad[6];
    int arr[1];
    int GetArrayElement(int idx);
};

// @fnv 0x00650910
int Dummy_00650910::GetArrayElement(int idx)
{
    return arr[idx];
}

template <class T> struct FaceGenMatrix
{
    char d[0x20];
    FaceGenMatrix();
    ~FaceGenMatrix();
};
struct FUN_00651520
{
    FaceGenMatrix<float> a[2];
    FaceGenMatrix<float> b;
    FaceGenMatrix<float> c[2];
    FUN_00651520();
};
// @fnv 0x00651520
FUN_00651520::FUN_00651520()
{}

namespace fnv_00651630 {
template <class T> class FaceGenMatrix
{
  public:
    FaceGenMatrix();
};

// @fnv 0x00651630
void* FUN_00651630(FaceGenMatrix<float>* pThis)
{
    new ((void *)(pThis)) ::FUN_00449610();
    return pThis;
}
}  // namespace fnv_00651630

void FUN_ehvec_ctor(void*, unsigned int, int, void*, void*);
void FUN_ctor();

// @fnv 0x00651670
void* FUN_00651670(void* p)
{
    FUN_ehvec_ctor(p, 0x20, 2, &FUN_ctor, &((void (&)())::FUN_00449680));
    return p;
}

struct FUN_006516c0_class
{
    char _pad[0x70];
    bool m_bNoConvert;
    void SetNoConvert(bool abTF);
};

// Actually, instructions say: "Define it as a free function named exactly FUN_006516c0. If it is a method (this pointer in ecx, callee pops stack arguments with ret N) write a free function with whose first parameter is the this pointer and whose second parameter is an unused int (for edx), then the real arguments."
// Wait: in MSVC /Od, a function with (void* this_ptr, int edx, bool abTF) will spill BOTH ecx and edx to the stack! `push ecx; push ecx; mov [ebp-8], edx; mov [ebp-4], ecx;`
// Let's check how only `ecx` is spilled: if edx is NOT named or not a parameter? No, always has 2 register params if there are >=2 integer params, EXCEPT if the first parameter is 64-bit, or if there is only 1 register parameter (i.e. the second param is passed on stack, e.g., a struct by value of size 1, 2, or 4!).
struct _stack_bool
{
    bool v;
};

// @fnv 0x006516c0
void FUN_006516c0(char* pThis, _stack_bool abTF)
{
    *reinterpret_cast<bool*>(pThis + 0x70) = abTF.v;
}

namespace fnv_006516e0 {
template <class T> struct FaceGenMatrix
{
    char d[0x20];
    FaceGenMatrix();
    ~FaceGenMatrix();
};
struct M657a80
{
    char d[0x18];
    M657a80();
    ~M657a80();
};
struct M657b50
{
    char d[0x10];
    M657b50();
};
struct FUN_006516e0
{
    char pad[8];
    FaceGenMatrix<float> m[4];
    M657a80 a;
    M657b50 b;
    FUN_006516e0();
};
// @fnv 0x006516e0
FUN_006516e0::FUN_006516e0()
{}
}  // namespace fnv_006516e0

void __cdecl FUN_00657960();
void __cdecl FUN_006579d0();
void compiler_eh_vector_destructor_iterator(void*, unsigned int, int, void(__cdecl*)(), void(__cdecl*)());

// @fnv 0x006517e0
void* DestroyVectorElements(void* pThis)
{
    compiler_eh_vector_destructor_iterator(pThis, 0x18, 4, FUN_00657960, FUN_006579d0);
    return pThis;
}

enum MEM_CONTEXT
{
};

struct Sol;
struct AutoMemContext
{
    int pad;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
struct Sol
{
    char pad[0x10];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Sol();
};
struct SolPtr
{
    Sol* p;
    SolPtr(Sol*);
    ~SolPtr();
    SolPtr& operator=(Sol*);
};
class BSFaceGenModelMap
{
  public:
    char pad[0x24];
    BSFaceGenModelMap();
};
struct GO45CFE0
{
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
BSFaceGenManager* FUN_00650ea0(void*);

struct BSFaceGenManager_006519f0
{
    char pad[0x11a4];
    BSFaceGenManager_006519f0()
    {
        FUN_00650ea0(this);
    }
};

// Creates a BSFaceGenManager singleton into DAT_011d59e8 if it is not already set, under an AutoMemContext.
// @fnv 0x006519f0
void FUN_006519f0()
{
    AutoMemContext context(static_cast<MEM_CONTEXT>(0x37), true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp",
                           0x316);
    if (DAT_011d59e8)
        return;

    DAT_011d59e8 = reinterpret_cast<BSFaceGenManager*>(new BSFaceGenManager_006519f0());
}


// If DAT_011d59e8 and the pointer at offset 0x1194 are non-null, calls FUN_006503b0 on that pointer.
// @fnv 0x00651e30
void FUN_00651e30()
{
    if (!DAT_011d59e8)
    {
        return;
    }
    if (!*(void**)&DAT_011d59e8->cache)
    {
        return;
    }
    reinterpret_cast<::S_006503b0_Owner *>((*(void**)&DAT_011d59e8->cache))->FUN_006503b0();
}

void ClearModelTextures(void*);

// If DAT_011d59e8 is set and its field at offset 0x1194 is non-null, calls ClearModelTextures on that field.
// @fnv 0x00651f40
void FUN_00651f40()
{
    if (DAT_011d59e8 != 0 && *(void**)&DAT_011d59e8->cache != 0)
        ClearModelTextures(*(void**)&DAT_011d59e8->cache);
}

struct GlobalObject_0044fae0
{
};
// @fnv 0x00652140
void FUN_00652140()
{
    reinterpret_cast<::FUN_004538e0_Class *>(&(::g_011d5a9c))->FUN_004538e0(0);
    DAT_011d59dc = DAT_011d59dc + 1;
}

namespace fnv_00652160 {
struct GlobalObject_0044fae0
{
};


// Calls FUN_0044b130 on g_011d5a9c; if it returns true, increments DAT_011d59dc, and returns that result.
// @fnv 0x00652160
bool FUN_00652160()
{
    bool bresult = reinterpret_cast<::s44b130::Lock *>(&((*reinterpret_cast<::fnv_00652160::GlobalObject_0044fae0 *>(&::g_011d5a9c))))->FUN_0044b130();
    if (bresult == true)
    {
        ::DAT_011d59dc += 1;
    }
    return bresult;
}
}  // namespace fnv_00652160

namespace fnv_00652190 {
class RecursiveLock
{
  public:
    void Leave(void);
};


// @fnv 0x00652190
void __cdecl FUN_00652190(void)
{
    reinterpret_cast<::S_0082f1f0_Lock *>(&((*reinterpret_cast<::fnv_00652190::RecursiveLock *>(&::g_011d5a9c))))->FUN_0082f1f0();
    ::DAT_011d59dc--;
}
}  // namespace fnv_00652190

struct Sub_00aabdb0
{
};

// @fnv 0x00652440
float __cdecl FUN_00652440(int apCoord, int aeFanAttribute, int aeFanType)
{
    return reinterpret_cast<::FanControlsV7 *>((((Sub_00aabdb0*)&BSFaceGenManager::GetFaceGenManager()->rest[176])))->FUN_00aabdb0(0, aeFanAttribute, aeFanType, (const ::ImagePairV7 *)(apCoord));
}

namespace fnv_006529a0 {
class Calendar
{
  public:
};

class BGSTerrainManager
{
  public:
};

template <typename T> class FaceGenMatrix
{
  public:
    void SetDimensions(unsigned int, unsigned int);
    FaceGenMatrix<T>& operator=(FaceGenMatrix<T> const&);
};

// @fnv 0x006529a0
void __cdecl FUN_006529a0(FaceGenCoordArray (*apCopyFromCoord)[2], FaceGenCoordArray (*apCopyToCoord)[2],
                          bool abGeometryOnly, bool abTextureOnly)
{
    if (!apCopyFromCoord || !apCopyToCoord)
        return;

    for (int etype = 0; etype < 2; ++etype)
    {
        for (int esymm = 0; esymm < 2; ++esymm)
        {
            if (((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((Calendar*)&apCopyFromCoord[etype][esymm])))->FUN_009611e0())) &&
                reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)&apCopyFromCoord[etype][esymm])))->GetMinLevel())
            {
                reinterpret_cast<::FR2MatrixVTCData *>((((FaceGenMatrix<float>*)&apCopyToCoord[etype][esymm])))->SetDimensions(((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((Calendar*)&apCopyFromCoord[etype][esymm])))->FUN_009611e0())),
                                    reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)&apCopyFromCoord[etype][esymm])))->GetMinLevel());
                if ((abGeometryOnly && etype == 0) || (abTextureOnly && etype == 1) ||
                    (abGeometryOnly == abTextureOnly))
                {
                    *(FaceGenMatrix<float>*)&apCopyToCoord[etype][esymm] =
                        *(const FaceGenMatrix<float>*)&apCopyFromCoord[etype][esymm];
                }
            }
            else
            {
                reinterpret_cast<::FR2MatrixVTCData *>((((FaceGenMatrix<float>*)&apCopyToCoord[etype][esymm])))->SetDimensions(0, 0);
            }
        }
    }
}
}  // namespace fnv_006529a0

class NiNode;

NiNode* __cdecl GetNodeFromGeometry(void*);
void* __cdecl DynamicCastByRTTI(void*, NiNode*);

// @fnv 0x00653230
void* __cdecl FUN_00653230(void* apGeom)
{
    NiNode* pGeometryNode = GetNodeFromGeometry(apGeom);
    if (pGeometryNode == 0)
    {
        return 0;
    }
    return DynamicCastByRTTI(&(*reinterpret_cast<int *>(&::g_011d5bb8)), pGeometryNode);
}

struct NiNode;

NiNode* __cdecl GetNodeFromGeometry(void*);
void* __cdecl DynamicCastByRTTI(void*, NiNode*);

// @fnv 0x00653300
void* __cdecl FUN_00653300(void* apGeom)
{
    NiNode* pGeometryNode = GetNodeFromGeometry(apGeom);
    if (pGeometryNode == 0)
    {
        return 0;
    }
    return DynamicCastByRTTI(&(*reinterpret_cast<int *>(&::g_011d5ba8)), pGeometryNode);
}

class NiFixedString;
class NiExtraData;
class NiAVObject
{
  public:
    NiExtraData* GetExtraData(NiFixedString const&);
};

const NiFixedString& __cdecl FUN_00653460();

// Returns the extra data named by FUN_00653460 from apGeom, or null if apGeom is null.
// @fnv 0x00653430
NiExtraData* __cdecl GetExtraDataIfPresent(NiAVObject* apGeom)
{
    return apGeom ? apGeom->GetExtraData(FUN_00653460()) : 0;
}

namespace fnv_00653470 {
template <class T> struct BSStringT
{
    operator const T*() const;
};
struct GeometryVertexBuffer : BSStringT<char>
{
    int a;
    int b;
    int c;
    GeometryVertexBuffer();
};
struct NiGeometryData
{
};
struct NiGeometry
{
};
struct Morph653
{
};
Morph653* __cdecl FUN_00653300(NiGeometry*);
void __cdecl FUN_00653340(NiGeometry*, GeometryVertexBuffer*);
// @fnv 0x00653470
void FUN_00653470(NiGeometry* apGeom, float afModifierValue)
{
    if (!apGeom || afModifierValue < ::_DAT_01012060)
        return;
    Morph653* pMorph = FUN_00653300(apGeom);
    if (!pMorph)
        return;
    if (reinterpret_cast<::NiGeometryData *>((((::fnv_00653470::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(apGeom))))))->IsGeometryDataStreamable(true))
    {
        GeometryVertexBuffer iter;
        reinterpret_cast<::S00a67410 *>((((::fnv_00653470::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(apGeom))))))->FUN_00a67410((::BSFaceGenMorphData *)&(iter));
        FUN_00653340(apGeom, &iter);
        if ((const char*)iter)
        {
            reinterpret_cast<::FUN_00662460_shell *>((pMorph))->FUN_00662460((int)(apGeom), 0, afModifierValue);
        }
        reinterpret_cast<::FUN_00a673d0_shell *>((((::fnv_00653470::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(apGeom))))))->FUN_00a673d0();
    }
}
}  // namespace fnv_00653470

// Maps the input value 1-7 to a slot index (0,1,2,3,4,13) and returns -1 for any other value.
// @fnv 0x00653cf0
int __cdecl FUN_00653cf0(int aiValue)
{
    switch (aiValue)
    {
    case 1:
        return 0;
    case 2:
        return 0;
    case 3:
        return 1;
    case 5:
        return 2;
    case 4:
        return 3;
    case 6:
        return 4;
    case 7:
        return 13;
    default:
        return -1;
    }
}


// @fnv 0x00653d70
void __cdecl SplitSignedDifference(float afValueA, float afValueB, float* param_3, float* param_4)
{
    float diff = afValueA * -1.0 + afValueB;
    if (diff >= ::_DAT_01012060)
    {
        *param_3 = 0.0f;
        *param_4 = diff;
    }
    else
    {
        *param_3 = diff * -1.0;
        *param_4 = 0.0f;
    }
}

struct NP
{
    int p;
    ~NP();
};
struct GO633 : NP
{
    GO633(int);
};
struct S654
{
    NP FUN_0057c5d0(GO633&);
    void ForwardToSubobject(int v);
};
// Constructs a GO633 from v and passes it to FUN_0057c5d0 on the S654 subobject at offset 0x24.
// @fnv 0x00654640
void S654::ForwardToSubobject(int aiValue)
{
    GO633 a(aiValue);
    ((S654*)((char*)this + 0x24))->FUN_0057c5d0(a);
}

template <typename T> class BSSimpleList;
class RegionObjectEntry;

class BGSQuestObjective
{
  public:
};

struct FUN_00656d80_this
{
    char pad[0x24];
    BGSQuestObjective* pObj;
};

// Returns the target list of the stored BGSQuestObjective, or null if no objective is set.
// @fnv 0x00656d80
BSSimpleList<RegionObjectEntry*>* GetObjectiveTargetList(FUN_00656d80_this* pThis)
{
    if (pThis->pObj)
    {
        return ((::BSSimpleList< ::RegionObjectEntry *> *)(reinterpret_cast<::NonActorMagicTarget *>((pThis->pObj))->GetActiveEffectList()));
    }
    else
    {
        return 0;
    }
}

struct V3
{
    int a;
    int b;
    int c;
};
struct FUN_00656fd0_shell
{
    V3* p;
    void CopyV3(V3* out);
};
// Copies the V3 value pointed to by p into out.
// @fnv 0x00656fd0
void FUN_00656fd0_shell::CopyV3(V3* out)
{
    V3* y;
    V3* x = p;
    y = x;
    *out = *y;
}

namespace fnv_00657010 {
struct NiTriBasedGeom;
struct NiProperty;
struct NiAVObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual NiTriBasedGeom* vGeom();
};
struct NiGeometryData
{
    void SetDataConsistency(int);
};
struct NiGeometry : NiAVObject
{
};
struct NiSkinInstance;
struct NiTriBasedGeom : NiGeometry
{
};
struct BSShader
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual int vProp(NiAVObject*, NiProperty*);
};
struct AlchemyItem
{
};
struct NiRenderer
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void vDraw(NiAVObject*, int, int, int);
};
// @fnv 0x00657010
void SetGeometryCompressFlags(NiAVObject* apObj, unsigned int aiShaderIndex, unsigned int aiCompressFlags)
{
    if (apObj)
    {
        NiTriBasedGeom* pgeom = apObj->vGeom();
        if (pgeom)
        {
            if (((::fnv_00657010::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(pgeom)))))
            {
                reinterpret_cast<::NiGeometryData *>((((::fnv_00657010::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(pgeom))))))->SetCompressFlags(aiCompressFlags);
                ((::fnv_00657010::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(pgeom))))->SetDataConsistency(0);
                if (!((::fnv_00657010::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(pgeom)))))
                {
                    BSShader* pshader = ((::fnv_00657010::BSShader *)(reinterpret_cast<::AlchemyItem *>((((AlchemyItem*)pgeom)))->FUN_004030b0()));
                    if (pshader)
                    {
                        NiRenderer* r = ((::fnv_00657010::NiRenderer *)(::FUN_0043c4b0()));
                        r->vDraw(pgeom, 0, 0, pshader->vProp(pgeom, ((::fnv_00657010::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pgeom))->FUN_00a59d30(3)))));
                        reinterpret_cast<::Mgr_e74120 *>((((::fnv_00657010::NiRenderer *)(::FUN_0043c4b0()))))->FUN_00e74120();
                    }
                }
            }
        }
    }
}
}  // namespace fnv_00657010

struct _elem_60
{
    char pad[0x3c];
};

struct _vec_60
{
    int pad0;
    int pad1;
    int pad2;
    _elem_60* first;
    _elem_60* last;
};

// @fnv 0x00657a30
unsigned int FUN_00657a30(const _vec_60* apVec)
{
    return apVec->last - apVec->first;
}

struct OpaqueDataBlock
{
    char pad[0x3c];
};
unsigned int FUN_00ec7c56();
struct FUN_00657a50_shell
{
    char pad[0xc];
    OpaqueDataBlock* first;
    OpaqueDataBlock* FUN_00657a50(unsigned int i);
};
// Returns a pointer to the element at index i after bounds-checking it against the count from FUN_00657a30.
// @fnv 0x00657a50
OpaqueDataBlock* FUN_00657a50_shell::FUN_00657a50(unsigned int uiIndex)
{
    if (!(uiIndex < ::FUN_00657a30((const ::_vec_60 *)this)))
        FUN_00ec7c56();
    do
    {
    } while (0);
    return first + uiIndex;
}

// @fnv 0x006591f0
float SquareFloat(float afValue)
{
    return afValue * afValue;
}

struct VIter
{
    float* p0;
    void* p1;
    VIter& operator=(const VIter&);
};
struct VIterD : public VIter
{
};
struct FloatVec
{
    VIter FUN_00657c50(VIter, const float&);
    void PushBack(const float& _Val);
    char pad[0x10];
    float* _Mylast;
};

// @fnv 0x006578e0
void FloatVec::PushBack(const float& afValue)
{
    if (((unsigned int)(reinterpret_cast<::FUN_00662820_shell *>((void *)this)->FUN_00662820())) < ((unsigned int)(reinterpret_cast<::FUN_0060b860_Cls *>((void *)this)->FUN_0060b860())))
        _Mylast = ((float *)(reinterpret_cast<::Unk060b8a0 *>(this)->FUN_0060b8a0((int)(_Mylast), 1, (int)&(afValue))));
    else
        FUN_00657c50((*(::VIterD *)(reinterpret_cast<::fnv_0065f550::FUN_0065f550_Class *>(this)->CallWithSelf({}))), afValue);
}

namespace fnv_00655fa0 {
struct TESEyes;
struct TESHair;
struct TESModel;
struct NiMemObject
{
    char _pad_0[1];
};
struct FaceGenData
{
    void* __vecDelDtor(unsigned int);
    char m_kFaceGenCoordinates[96];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    int m_eSex;
    char m_kModelObjectsItem[16];
    char pTexture[16];
    char m_kTexturePaths[16];
    char m_kFaceGenTextures[16];
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    char _pad_b6[2];
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    int m_eFaceGenLOD;
    char Accessories[8];
};
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};

struct NiAVObject;
struct BGSTerrainManager
{
};
struct BSFadeNode
{
    BSFadeNode(const char*);
    ~BSFadeNode();
    char* m_kHandle;
};
struct BSS
{
    BSS();
    ~BSS();
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
};
struct GO
{
    GO(int);
    ~GO();
    void* m_pObject;
};
struct AutoMemContextLocal
{
    AutoMemContextLocal(int, bool, const char*, int);
    ~AutoMemContextLocal();
    int iPrevious;
};
struct StrMem
{
};
struct Str6a70
{
    Str6a70& operator=(const char*);
};
struct BSStringAppend
{
    BSStringAppend& operator+=(const char*);
};
struct Flt
{
    operator unsigned int() const;
};
struct NiFixedStringConv
{
    operator const char*() const;
};
struct NiAVObjectHelper
{
};
struct NiUpdateDataInit
{
    void Init(float, bool, bool);
};
struct RgbaColor
{
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};
struct NiNodeHelper
{
};
struct FaceGenCoordinates;
struct BSFaceGenModel
{
};
struct BSShaderManager
{
};
struct TES
{
};
struct TESTexture
{
    static const char* NormalizeTextureFilePath(BSS&, const char*);
};
struct FNStub
{
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct GlobalObject_004aff00
{
};
struct PropHelper
{
};
struct CellLightingTemplate
{
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
struct LightPropHelper
{
    void FUN_00441130(int, bool);
};
struct TextureFormatHelper
{
};
float FUN_00652440(FaceGenData*, int, int);
void FUN_00652140();
void FUN_00652190();
int FUN_00653880(BSS*, int, unsigned char, const char*);
unsigned int _strlen(const char*);
int __strnicmp(const char*, const char*, unsigned int);
struct NodeCalls
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
    virtual NiAVObject* GetObjectByName(const BSFadeNode&);
};
struct ObjCalls
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual NiAVObject* GetGeometry();
};
struct LightPropCalls
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
    virtual void Refresh();
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
    virtual void SetTexture3(int, int, void*);
    virtual void v0f4();
    virtual void v0f8();
    virtual void SetTexture2(int, void*);
    virtual void SetTexture(int, void*);
};
struct ModelCalls
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void GetNormalName(void*);
};

// Applies facegen texture coordinates and shader properties to an NPC model node, then updates its child nodes and geometry.
// @fnv 0x00655fa0
void ApplyFaceGenTextures(NiAVObject* apNode, FaceGenData* arNpcData)
{
    AutoMemContextLocal tempMemContext(
        0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0xc2a);
    BSFadeNode leftEye("FaceGenEyeLeft");
    BSFadeNode rightEye("FaceGenEyeRight");
    BSFadeNode headAccessory("FaceGenAccessory");
    BSFadeNode hair(DAT_0104aad0);
    BSS filename;
    BSS fileEGM;
    BSS fileDDS;
    BSS fileDetail;
    NiAVObject* pobj;
    BSS fileNormal;
    GO sptexNormal(0);
    GO sptexBaseMod(0);
    GO sptexDetailMod(0);
    unsigned int ishaderindex = 0;
    bool bspecular = false;
    char cage;
    char tmp[260];
    LightPropCalls* pshaderpropLighting;
    NiAVObject* pgeom;
    NiAVObject* pmodelFG;
    void* pshaderprop;
    NiUpdateData UpdateData;

    FUN_00652140();
    if (apNode == 0 || arNpcData == 0)
    {
        FUN_00652190();
        return;
    }
    cage = (char)::FUN_00406ce0(FUN_00652440(arNpcData, 0, 0));
    ::TaskQueueInterface::CopyStringToBuffer(tmp, 0x104, "Textures\\");
    for (unsigned int ipart = 0; ipart < 8; ipart++)
    {
        reinterpret_cast<::TextString *>((((StrMem*)&fileDetail)))->FUN_004037f0("", 0);
        if (ipart == 6 || ipart == 7)
            continue;
        if (ipart == 0 || ipart == 1)
            ishaderindex = 0xe;
        else
            ishaderindex = 1;
        if (*((Arr*)&arNpcData->m_kTexturePaths[0])->GetAt(ipart) == 0 ||
            *((Arr*)&arNpcData->m_kFaceGenTextures[0])->GetAt(ipart) == 0)
            continue;
        pobj = ((NodeCalls*)apNode)
                   ->GetObjectByName(BSFadeNode((const char*)*((Arr*)&arNpcData->bFaceGenTexturing)->GetAt(ipart)));
        if (pobj == 0)
            continue;
        pgeom = ((ObjCalls*)pobj)->GetGeometry();
        if (pgeom == 0)
            continue;
        pmodelFG = ((::fnv_00655fa0::NiAVObject *)(::BSFaceGenModel::GetFaceGenModelNode((::NiAVObject *)(pgeom))));
        if (pmodelFG == 0)
            continue;
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(pobj), false, false);
        pshaderprop = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)pobj)))->FUN_00a59d30(3)));
        if ((pshaderpropLighting =
                 (LightPropCalls*)((pshaderprop == 0 ? 0
                                                     : ((int)reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)pshaderprop)))->GetMinLevel() >= 8 &&
                                                        (int)reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)pshaderprop)))->GetMinLevel() <= 12))
                                       ? pshaderprop
                                       : 0)) == 0)
            continue;
        if (reinterpret_cast<::FUN_00658930_class *>((((GlobalObject_004aff00*)&arNpcData->Accessories[0])))->GetShortAtOffsetA() && *((bool*)arNpcData + 0xd4))
            *(Helper62d0*)&sptexBaseMod = *(void* const*)((Arr*)&arNpcData->Accessories[0])->GetAt(ipart);
        if (ipart == 0 && cage >= 0 &&
            FUN_00653880(&fileDetail, *(int*)((char*)arNpcData + 0x90), (unsigned char)cage,
                         ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)*((Arr*)&arNpcData->m_kFaceGenTextures[0])->GetAt(ipart))))->FUN_00408da0()))))
        {
            if (reinterpret_cast<::FUN_00658930_class *>((((GlobalObject_004aff00*)&arNpcData->Accessories[0])))->GetShortAtOffsetA() == 0 ||
                *(Flt*)((Arr*)&arNpcData->Accessories[0])->GetAt(ipart) == 0)
                reinterpret_cast<::BSFaceGenModel *>((((BSFaceGenModel*)pmodelFG)))->ApplyTextureCoordinate((::FaceGenCoordinates *)(::fnv_00655fa0::FaceGenCoordinates *)((FaceGenCoordinates*)arNpcData), (::NiPointer< ::NiTexture> &)(sptexBaseMod), ::FUN_006151d0());
            reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00655fa0::TES * *>(&::g_TES))))->FUN_004568c0((const char*)(unsigned int)*(Flt*)&fileDetail, (::TexPtr< ::NiSourceTexture> &)(sptexDetailMod), true, true);
            TESTexture::NormalizeTextureFilePath(fileNormal, (const char*)(unsigned int)*(Flt*)&fileDetail);
        }
        else
        {
            if (reinterpret_cast<::FUN_00658930_class *>((((GlobalObject_004aff00*)&arNpcData->Accessories[0])))->GetShortAtOffsetA() == 0 ||
                *(Flt*)((Arr*)&arNpcData->Accessories[0])->GetAt(ipart) == 0)
                reinterpret_cast<::BSFaceGenModel *>((((BSFaceGenModel*)pmodelFG)))->ApplyTextureCoordinate((::FaceGenCoordinates *)(::fnv_00655fa0::FaceGenCoordinates *)((FaceGenCoordinates*)arNpcData), (::NiPointer< ::NiTexture> &)(sptexBaseMod), ::FUN_006151d0());
            BSS tempstr;
            ((ModelCalls*)*((Arr*)&arNpcData->m_kFaceGenTextures[0])->GetAt(ipart))->GetNormalName(&tempstr);
            if ((unsigned int)*(Flt*)&tempstr)
            {
                *(Str6a70*)&fileNormal = "Textures\\";
                *(BSStringAppend*)&fileNormal += (const char*)(unsigned int)*(Flt*)&tempstr;
            }
        }
        if ((unsigned int)*(Flt*)&fileNormal)
            reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00655fa0::TES * *>(&::g_TES))))->FUN_004568c0((const char*)(unsigned int)*(Flt*)&fileNormal, (::TexPtr< ::NiSourceTexture> &)(sptexNormal), true, true);
        if ((unsigned int)*(Flt*)&sptexNormal)
        {
            pshaderpropLighting->SetTexture(0, (void*)(unsigned int)*(Flt*)&sptexNormal);
            int eFormat = ((int)(reinterpret_cast<::Callees *>((((TextureFormatHelper*)((void *)(::GetObjectiveTargetList((::FUN_00656d80_this *)(void *)((void*)(unsigned int)*(Flt*)&sptexNormal)))))))->FUN_00726070()));
            bspecular = (eFormat == 5 || eFormat == 6 || eFormat == 1);
            ((LightPropHelper*)pshaderpropLighting)->FUN_00441130(0, bspecular);
        }
        else if (((int)(reinterpret_cast<::fnv_00540570::FUN_00540570_Owner *>((((LightPropHelper*)pshaderpropLighting)))->GetFltValue(0))) == 0)
        {
            pshaderpropLighting->SetTexture(0, ((void *)(::fnv_00656db0::FUN_00656db0())));
        }
        if (*((bool*)arNpcData + 0xd4) && ishaderindex == 0xe)
        {
            pshaderpropLighting->SetTexture2(1, (void*)(unsigned int)*(Flt*)&sptexBaseMod);
            pshaderpropLighting->SetTexture(
                1, (unsigned int)*(Flt*)&sptexDetailMod ? (void*)(unsigned int)*(Flt*)&sptexDetailMod : ((void *)(::FUN_004af8a0())));
            ((LightPropHelper*)pshaderpropLighting)->FUN_00441130(0xa, true);
            void* pmatprop = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)pobj)))->FUN_00a59d30(2)));
            if (pmatprop && reinterpret_cast<::BGSImpactData *>((((CellLightingTemplate*)pmatprop)))->FUN_009a9350() < 1.0)
                reinterpret_cast<::DecalStub *>((((LightPropHelper*)pmatprop)))->FUN_00654700(4.0f);
            if ((unsigned int)*(Flt*)&fileNormal)
            {
                char pfilename[260];
                char ptexfilename[260];
                ::FUN_00406d00(ptexfilename, 0x104, ::DAT_01019f08, (const char*)(unsigned int)*(Flt*)&fileNormal);
                ::BSShaderManager::BuildTexturePath(pfilename, ptexfilename, "_sk", true);
                if (pfilename[0])
                {
                    GO spTempSourceTexture(0);
                    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00655fa0::TES * *>(&::g_TES))))->FUN_004568c0(pfilename, (::TexPtr< ::NiSourceTexture> &)(spTempSourceTexture), true, true);
                    pshaderpropLighting->SetTexture3(2, 0, (void*)(unsigned int)*(Flt*)&spTempSourceTexture);
                }
            }
        }
        *(Helper62d0*)&sptexBaseMod = reinterpret_cast<void* const&>(((NP_0081c630*)&sptexDetailMod)->operator=(0));
        ((NP_0081c630*)&sptexNormal)->operator=(0);
        unsigned int icompress = 1;
        ::fnv_00657010::SetGeometryCompressFlags((::fnv_00657010::NiAVObject *)(pobj), ishaderindex, icompress);
        pshaderpropLighting->Refresh();
    }
    for (unsigned int i = 0; i < (unsigned int)reinterpret_cast<::FUN_00453470_shell *>((((NiNodeHelper*)apNode)))->FUN_00453470(); i++)
    {
        NiAVObject* pchild = ((::fnv_00655fa0::NiAVObject *)(reinterpret_cast<::NiNode *>((((NiNodeHelper*)apNode)))->GetAt(i)));
        if (pchild)
        {
            unsigned int icompress = 1;
            if (::FUN_009a3830((const int *)&((*(::fnv_00655fa0::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((((NiAVObjectHelper*)pchild)))->GetLinkToList()))), (const int *)&(leftEye)) ||
                ::FUN_009a3830((const int *)&((*(::fnv_00655fa0::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((((NiAVObjectHelper*)pchild)))->GetLinkToList()))), (const int *)&(rightEye)))
            {
                icompress = 0;
                ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(pchild), false, false);
            }
            else if (__strnicmp(*(NiFixedStringConv*)&(*(::fnv_00655fa0::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((((NiAVObjectHelper*)pchild)))->GetLinkToList())),
                                *(NiFixedStringConv*)&hair, _strlen(*(NiFixedStringConv*)&hair)) == 0 ||
                     ::FUN_009a3830((const int *)&((*(::fnv_00655fa0::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((((NiAVObjectHelper*)pchild)))->GetLinkToList()))), (const int *)&(headAccessory)))
            {
                ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(pchild), false, false);
                void* pgeomdata = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)pchild)))->FUN_00a59d30(3)));
                LightPropCalls* pchildgeom;
                if ((pchildgeom =
                         (LightPropCalls*)((pgeomdata == 0 ? 0
                                                           : (int)reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)pgeomdata)))->GetMinLevel() == 8)
                                               ? pgeomdata
                                               : 0)) != 0)
                {
                    unsigned int uiColor = *(unsigned int*)((char*)arNpcData + 0x84);
                    *(RgbaColor*)((char*)pchildgeom + 0x84) =
                        RgbaColor((float)((unsigned char)(uiColor & 0xff) / 255.0),
                                  (float)((unsigned char)(((unsigned short)uiColor >> 8) & 0xff) / 255.0),
                                  (float)((unsigned char)((uiColor >> 16) & 0xff) / 255.0), 1.0f);
                    pchildgeom->Refresh();
                }
                else
                {
                    LightPropCalls* eNBTmethod;
                    if ((eNBTmethod =
                             (LightPropCalls*)((pgeomdata == 0
                                                    ? 0
                                                    : (int)reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)pgeomdata)))->GetMinLevel() == 12)
                                                   ? pgeomdata
                                                   : 0)) != 0)
                    {
                        unsigned int uiColor = *(unsigned int*)((char*)arNpcData + 0x84);
                        *(RgbaColor*)((char*)eNBTmethod + 0x84) =
                            RgbaColor((float)((unsigned char)(uiColor & 0xff) / 255.0),
                                      (float)((unsigned char)(((unsigned short)uiColor >> 8) & 0xff) / 255.0),
                                      (float)((unsigned char)((uiColor >> 16) & 0xff) / 255.0), 1.0f);
                        eNBTmethod->Refresh();
                    }
                }
            }
            ::fnv_00657010::SetGeometryCompressFlags((::fnv_00657010::NiAVObject *)(pchild), ishaderindex, icompress);
        }
    }
    reinterpret_cast<::FUN_00a5a040_Class *>((((NiAVObjectHelper*)apNode)))->FUN_00a5a040();
    new ((void *)(((NiUpdateDataInit*)&UpdateData))) ::NiUpdateData(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((NiNodeHelper*)apNode)))->FUN_00a59c60((int)&(UpdateData));
    FUN_00652190();
}
}  // namespace fnv_00655fa0

struct QueuedFile;
struct TESModel;
struct TESRace;
struct TESHair;
struct TESEyes;
struct BGSHeadPart;

struct StrMem
{
    StrMem();
    ~StrMem();
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
};
struct FNStub
{
};
struct Flt
{
    operator unsigned int() const;
};
struct Arr
{
    unsigned int* GetAt(int);
    char data[16];
};
struct TESTexture
{
    static void ConvertTexturePath(const char*, char*);
};
struct ModelLoader
{
};
struct FUN_004ac110_shell
{
    TESRace* FUN_004ac110();
};
struct FUN_006141f0_shell
{
};
struct FUN_00604310_shell
{
    bool FUN_00604310(int, char*, unsigned int);
};
struct FUN_0048cee0_shell
{
    int FUN_0048cee0();
};
struct HPList
{
    char data[8];
};
float __cdecl FUN_00652440(void*, int, int);
int __cdecl strcat_s(char*, unsigned int, const char*);
void __cdecl AppendNormalMapSuffix(const char*, char*);
int __cdecl FUN_00653880(void*, int, char, const char*);

namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
    int m_eMemoryContext;
};
struct FaceGenData
{
    FaceGenData();
    ~FaceGenData();
    char m_kFaceGenCoordinates[0x80];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    int m_eSex;
    Arr m_kModelObjectsItem;
    Arr pTexture;
    char m_kTexturePaths[16];
    char m_kFaceGenTextures[16];
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    char _pad[2];
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    int m_eFaceGenLOD;
    HPList Accessories;
};
}

// Builds face-gen data for an actor and queues eye, hair, head-part and part textures/models with the model loader at the given priority.
// @fnv 0x00657150
void __cdecl QueueFaceGenAssets(TESActorBase* apNPC, int aePriority, QueuedFile* apParent)
{
    lc1::AutoMemContext tempMemContext(
        0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0xe38);
    lc1::FaceGenData faceGenData;
    reinterpret_cast<::RaceAppearance::Race *>((((FUN_006141f0_shell*)((FUN_004ac110_shell*)apNPC)->FUN_004ac110())))->BuildAppearance((::RaceAppearance::NPC *)(apNPC), (::RaceAppearance::Output *)(void *)(&faceGenData), (*(int *)&(const ::SEX &)(apNPC->GetSex())), true);
    if (!&faceGenData)
        return;
    char cage = (char)FUN_00406ce0(FUN_00652440(&faceGenData, 0, 0));
    if (faceGenData.pEyes)
    {
        char pTexturePath[260];
        ::TaskQueueInterface::CopyStringToBuffer(pTexturePath, 260, "Textures\\");
        strcat_s(pTexturePath, 260, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)faceGenData.pEyes + 0x24))))->FUN_00408da0())));
        reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((::g_modelLoader))->LoadTexture(pTexturePath, (void *)(aePriority), apParent);
    }
    else
    {
        reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((::g_modelLoader))->LoadTexture("Textures\\Characters\\Eyes\\EyeDefault.dds", (void *)(aePriority), apParent);
    }
    if (faceGenData.m_pHair)
    {
        reinterpret_cast<::QueueModelHolder *>((::g_modelLoader))->FUN_00443d30((int)(faceGenData.m_pHair ? (TESModel*)((char*)faceGenData.m_pHair + 0x24) : 0),
                                           aePriority, (int)(apParent), 0, false, false, true);
        char pTexturePath[260];
        ::TaskQueueInterface::CopyStringToBuffer(pTexturePath, 260, "Textures\\");
        strcat_s(pTexturePath, 260, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)faceGenData.m_pHair + 0x3c))))->FUN_00408da0())));
        reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((::g_modelLoader))->LoadTexture(pTexturePath, (void *)(aePriority), apParent);
        reinterpret_cast<::MeshLoader *>((::g_modelLoader))->LoadMesh((::MeshSource *)(::TESModel *)(faceGenData.m_pHair ? (TESModel*)((char*)faceGenData.m_pHair + 0x24) : 0), aePriority,
                                apParent, 9);
    }
    char pheadModTexture[260];
    if (((FUN_00604310_shell*)apNPC)->FUN_00604310(0, pheadModTexture, 260))
        reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((::g_modelLoader))->LoadTexture(pheadModTexture, (void *)(aePriority), apParent);
    unsigned int ipart = 0;
    for (ipart = 0; ipart < 8; ++ipart)
    {
        if (ipart == 6 || ipart == 7)
            continue;
        if (!*faceGenData.m_kModelObjectsItem.GetAt(ipart) || !*faceGenData.pTexture.GetAt(ipart))
            continue;
        int ishaderindex = 1;
        if (ipart == 0 || ipart == 1)
            ishaderindex = 14;
        StrMem fileDetail;
        char ptextureName[260];
        ::TaskQueueInterface::CopyStringToBuffer(ptextureName, 260, "Textures\\");
        strcat_s(ptextureName, 260, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)*faceGenData.pTexture.GetAt(ipart))))->FUN_00408da0())));
        reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((::g_modelLoader))->LoadTexture(ptextureName, (void *)(aePriority), apParent);
        if (ipart == 0 && cage >= 0 &&
            FUN_00653880(&fileDetail, faceGenData.m_eSex, cage,
                         ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)*faceGenData.pTexture.GetAt(ipart))))->FUN_00408da0()))))
        {
            ::TaskQueueInterface::CopyStringToBuffer(ptextureName, 260, (const char*)(unsigned int)*(Flt*)&fileDetail);
            reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((::g_modelLoader))->LoadTexture(ptextureName, (void *)(aePriority), apParent);
        }
        char pnormalFileName[260];
        AppendNormalMapSuffix(ptextureName, pnormalFileName);
        reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((::g_modelLoader))->LoadTexture(pnormalFileName, (void *)(aePriority), apParent);
        if (faceGenData.bFaceGenTexturing && ishaderindex == 14)
        {
            char pskinFileName[260];
            TESTexture::ConvertTexturePath(ptextureName, pskinFileName);
            reinterpret_cast<::fnv_004436c0::FUN_004436c0_Class *>((::g_modelLoader))->LoadTexture(pskinFileName, (void *)(aePriority), apParent);
        }
    }
    for (ipart = 0; ipart < 8; ++ipart)
    {
        TESModel* pmodel = (TESModel*)*faceGenData.m_kModelObjectsItem.GetAt(ipart);
        if (pmodel && ((FUN_0048cee0_shell*)pmodel)->FUN_0048cee0())
        {
            reinterpret_cast<::QueueModelHolder *>((::g_modelLoader))->FUN_00443d30((int)(pmodel), aePriority, (int)(apParent), 0, false, false, true);
            reinterpret_cast<::MeshLoader *>((::g_modelLoader))->LoadMesh((::MeshSource *)(pmodel), aePriority, apParent, ipart);
            reinterpret_cast<::fnv_00448080::Owner448 *>((::g_modelLoader))->LoadTaskFromPath((::fnv_00448080::Task448 *)(pmodel), aePriority, apParent, ipart);
        }
    }
    HPList* pheadPartList = &faceGenData.Accessories;
    while (pheadPartList)
    {
        BGSHeadPart* pheadPart = *((::BGSHeadPart **)(new ((void *)(pheadPartList)) ::Vec3()));
        if (pheadPart && ((FUN_0048cee0_shell*)((char*)pheadPart + 0x24))->FUN_0048cee0())
        {
            reinterpret_cast<::QueueModelHolder *>((::g_modelLoader))->FUN_00443d30((int)(pheadPart ? (TESModel*)((char*)pheadPart + 0x24) : 0), aePriority,
                                               (int)(apParent), 0, false, false, true);
            reinterpret_cast<::MeshLoader *>((::g_modelLoader))->LoadMesh((::MeshSource *)(::TESModel *)(pheadPart ? (TESModel*)((char*)pheadPart + 0x24) : 0), aePriority, apParent, ipart);
            reinterpret_cast<::fnv_00448080::Owner448 *>((::g_modelLoader))->LoadTaskFromPath((::fnv_00448080::Task448 *)(::TESModel *)(pheadPart ? (TESModel*)((char*)pheadPart + 0x24) : 0), aePriority, apParent,
                                            ipart);
        }
        pheadPartList = ((::HPList *)(reinterpret_cast<::Callees *>((pheadPartList))->FUN_00726070()));
    }
}

struct BSFaceGenModel;
struct ModelHelper
{
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
    operator ModelHelper*() const;
};
struct FGEntry
{
    char pad[8];
    void* model;
    unsigned int tick;
};
struct GO
{
    void* p;
    GO(int);
    ~GO();
    operator FGEntry*() const;
};
struct FGModelMap
{
};
void FUN_00652140();
void FUN_00652190();

struct FGModelCache
{
    char pad[4];
    FGModelMap map;
    char pad2[0x1b];
    bool loaded;
    void FUN_00650ba0(int);
    bool FUN_00650200(void* key, Helper62d0* out);
};

// @fnv 0x00650200
bool FGModelCache::FUN_00650200(void* key, Helper62d0* out)
{
    FUN_00652140();
    GO entry(0);
    bool res = false;
    if (reinterpret_cast<::Map62d0 *>(&(map))->FUN_006c62d0((unsigned int)(key), (void **)&(entry)))
    {
        static_cast<FGEntry*>(entry)->tick = ((unsigned int)(::FUN_00457fe0()));
        *out = static_cast<FGEntry*>(entry)->model;
        FUN_00650ba0(reinterpret_cast<int>(static_cast<FGEntry*>(entry)));
        reinterpret_cast<::fnv_0065bf80::FUN_0065bf80_shell *>((static_cast<ModelHelper*>(*out)))->EnsureMorphData();
        reinterpret_cast<::BSFaceGenModel *>((static_cast<ModelHelper*>(*out)))->LoadFaceGenTexture();
        loaded = true;
        res = true;
    }
    FUN_00652190();
    return res;
}

namespace fnv_00650930 {
struct ModelHelper
{
    unsigned int FUN_0065c490();
};
struct Helper62d0
{
    operator ModelHelper*() const;
};
struct FGEntry
{
    char pad[8];
    Helper62d0 model;
};
struct GO
{
    void* p;
    GO(int);
    ~GO();
    operator FGEntry*() const;
};
struct NavMeshVertexMap
{
};
struct Map62d0
{
};
void FUN_00652140();
void FUN_00652190();

struct FGMapOwner
{
    char pad[4];
    NavMeshVertexMap map;
    unsigned int GetModelValueSum(int which);
};

// Iterates the map's positions, accumulating either GetEGMSize or FUN_0065c490 results from each entry's model based on which, and returns the sum.
// @fnv 0x00650930
unsigned int FGMapOwner::GetModelValueSum(int aiMode)
{
    void* pos2;
    unsigned int id6 = 0;
    GO ptr(0);
    unsigned int result3 = 0;
    FUN_00652140();
    pos2 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(map))->GetFirstPos();
    while (pos2)
    {
        reinterpret_cast<::Map62d0 *>((reinterpret_cast<Map62d0*>(&map)))->FUN_00559120((::MapItem62d0 *&)(pos2), (void *&)(id6), (::Helper62d0 &)(ptr));
        switch (aiMode)
        {
        case 0:
            result3 += reinterpret_cast<::FUN_0065c110_t *>((static_cast<ModelHelper*>(static_cast<FGEntry*>(ptr)->model)))->GetEGMSize();
            break;
        case 1:
            result3 += static_cast<ModelHelper*>(static_cast<FGEntry*>(ptr)->model)->FUN_0065c490();
            break;
        }
    }
    FUN_00652190();
    return result3;
}
}  // namespace fnv_00650930

namespace fnv_00650ea0 {
struct NiMemObject
{
    char _pad_0[1];
};
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct OpaqueDataBlock
{
    void* __vecDelDtor(unsigned int);
    char ctl[24];
    char label[28];
};
struct FUN_00650ea0_shell : public BSFaceGenManager
{
    void FUN_00650ea0(void*);
};

namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int aeMemoryContext, bool bPush, const char* pFile, int iLine);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}

struct NarrowString
{
    NarrowString(const char* pName);
    ~NarrowString();
    void* _Alval;
    char _Bx[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};

class NiFixedString
{
  public:
    NiFixedString(const char* pcString);
    ~NiFixedString();
    operator const char*() const;
    char* m_kHandle;
};

template <class T> class NiPtr
{
  public:
    NiPtr(T* pObject = 0);
    ~NiPtr();
    NiPtr& operator=(T* pObject);
    T* operator->() const;
    T* m_pObject;
};

class NiPixelFormat
{
  public:
    char data[0x44];
};

class NiPixelData
{
  public:
    static void* operator new(unsigned int stSize);
    static void operator delete(void* pMem, unsigned int);
    NiPixelData(unsigned int uiWidth, unsigned int uiHeight, const NiPixelFormat& kFormat, unsigned int uiMipmapLevels,
                unsigned int uiNumFaces);
    void FUN_006516c0(bool bValue);
    char data[0x74];
};

class FaceGenAlphaProperty
{
  public:
    static void* operator new(unsigned int stSize);
    static void operator delete(void* pMem, unsigned int);
    FaceGenAlphaProperty();
    char data[0x1c];
};

struct TextureFormatPreferences
{
    int ePixelLayout;
    int eAlphaFmt;
    int eMipMapped;
};

struct FgMatrixDims
{
};

struct FaceGenCoordArr
{
    char data[0x20];
};

struct FaceGenSam
{
    FaceGenSam();
    ~FaceGenSam();
    unsigned int uiGeo;
    unsigned int uiTex;
    FaceGenCoordArr coords[2][2];
    char rest[0x30];
};

struct FaceGenCtlVec
{
    char data[0x18];
};

struct FaceGenCtls
{
    FaceGenCtls();
    ~FaceGenCtls();
    FaceGenCtlVec ctl[2][2];
};

struct FaceGenModels
{
    FaceGenModels();
    ~FaceGenModels();
    char data[0x106c];
};


class FUN_00650ea0_BSFaceGenManager
{
  public:
    FUN_00650ea0_BSFaceGenManager();

    FaceGenSam m_kSam;
    FaceGenCtls m_kCtls;
    FaceGenModels m_kModels;
    unsigned int m_auiInfo[4];
    BSFaceGenModelMap* m_pModelCache;
    NiPtr<FaceGenAlphaProperty> m_spAlpha;
    NiPtr<NiTexture> m_spBaseTexture;
    NiPtr<NiTexture> m_spDetailTexture;
};

// Constructs the manager: loads the CTL file, sizes coordinate arrays, creates the alpha property and default base/detail textures, and sets DAT_011d59e0.
// @fnv 0x00650ea0
FUN_00650ea0_BSFaceGenManager::FUN_00650ea0_BSFaceGenManager()
{
    NiPixelData* pdetailpixeldata;
    unsigned char* pdecalpixels;
    lc1::AutoMemContext tempMemContext(
        55, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 692);
    NiPixelData* pbasepixeldata;
    unsigned char* pbasepixels;
    OpaqueDataBlock* pctl = 0;

    if (!::fnv_00aaa7d0::FUN_00aaa7d0((const ::fnv_00aaa7d0::std::basic_string<char, ::fnv_00aaa7d0::std::char_traits<char>, ::fnv_00aaa7d0::std::allocator<char>> &)((const ::fnv_00650ea0::NarrowString &)("FACEGEN\\SI.CTL")), (unsigned int *)(::fnv_00650ea0::FaceGenSam *)(&m_kSam), &m_kSam.uiTex, (unsigned int (*)[2])(m_auiInfo), (::fnv_00aaa7d0::FractalReaderA *)(::fnv_00650ea0::FaceGenCtls *)(&m_kCtls), (::fnv_00aaa7d0::FractalReaderB *)(::fnv_00650ea0::FaceGenModels *)(&m_kModels)))
    {
        if (!::fnv_00aaa7d0::FUN_00aaa7d0((const ::fnv_00aaa7d0::std::basic_string<char, ::fnv_00aaa7d0::std::char_traits<char>, ::fnv_00aaa7d0::std::allocator<char>> &)((const ::fnv_00650ea0::NarrowString &)("FACEGEN\\SI.CTL")), (unsigned int *)(::fnv_00650ea0::FaceGenSam *)(&m_kSam), &m_kSam.uiTex, (unsigned int (*)[2])(m_auiInfo), (::fnv_00aaa7d0::FractalReaderA *)(::fnv_00650ea0::FaceGenCtls *)(&m_kCtls), (::fnv_00aaa7d0::FractalReaderB *)(::fnv_00650ea0::FaceGenModels *)(&m_kModels)))
        {
            ::FUN_005b5e40();
        }
    }

    for (unsigned int i = 0; i < 2; ++i)
    {
        for (unsigned int j = 0; j < 2; ++j)
        {
            if (::FUN_00657a30((const ::_vec_60 *)&(m_kCtls.ctl[i][j])))
            {
                pctl = ((::fnv_00650ea0::OpaqueDataBlock *)(reinterpret_cast<::FUN_00657a50_shell *>(&(m_kCtls.ctl[i][j]))->FUN_00657a50(0)));
                if (pctl)
                {
                    reinterpret_cast<::FR2MatrixVTCData *>(&(m_kSam.coords[i][j]))->SetDimensions(reinterpret_cast<::BGSTerrainManager *>((void *)(reinterpret_cast<const FgMatrixDims*>(pctl->ctl)))->GetMinLevel(),
                                               ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((void *)(reinterpret_cast<const FgMatrixDims*>(pctl->ctl)))->FUN_009611e0())));
                }
            }
            else
            {
                reinterpret_cast<::FR2MatrixVTCData *>(&(m_kSam.coords[i][j]))->SetDimensions(0, 0);
            }
        }
    }

    m_pModelCache = 0;

    m_spAlpha = new FaceGenAlphaProperty;
    reinterpret_cast<::Flag512Receiver *>(((m_spAlpha).operator->()))->SetFlag512(true);
    reinterpret_cast<::NiObjectNET *>(((m_spAlpha).operator->()))->SetFlags(4);
    reinterpret_cast<::FUN_0094db80_shell *>(((m_spAlpha).operator->()))->FUN_0094db80(100);

    pbasepixeldata = new NiPixelData(32, 32, (*reinterpret_cast<const ::fnv_00650ea0::NiPixelFormat *>(&::gNiPoint3StartupSrc)), 1, 1);
    pbasepixels = ((unsigned char *)(reinterpret_cast<::S_0064dac0 *>((pbasepixeldata))->FUN_0064dac0(0, 0)));
    memset(pbasepixels, 128, 4096);
    reinterpret_cast<::NiGlobalStringTable *>((pbasepixeldata))->AddString();
    pbasepixeldata->FUN_006516c0(true);
    m_spBaseTexture = ((::NiTexture *)(::fnv_00a5ff10::FUN_00a5ff10((::fnv_00a5ff10::RefCounted *)(pbasepixeldata), (void *)(NiFixedString("DefaultBaseModFaceGenTexture")), (const ::fnv_00a5ff10::OwnerTriple *)&((*reinterpret_cast<::fnv_00650ea0::TextureFormatPreferences *>(&::DAT_011a9598))))));

    pdetailpixeldata = new NiPixelData(32, 32, (*reinterpret_cast<const ::fnv_00650ea0::NiPixelFormat *>(&::gNiPoint3StartupSrc)), 1, 1);
    pdecalpixels = ((unsigned char *)(reinterpret_cast<::S_0064dac0 *>((pdetailpixeldata))->FUN_0064dac0(0, 0)));
    for (int i = 0; i < 1024; ++i)
    {
        pdecalpixels[i * 4] = 62;
        pdecalpixels[i * 4 + 1] = 65;
        pdecalpixels[i * 4 + 2] = 62;
        pdecalpixels[i * 4 + 3] = 64;
    }
    reinterpret_cast<::NiGlobalStringTable *>((pdetailpixeldata))->AddString();
    pdetailpixeldata->FUN_006516c0(true);
    m_spDetailTexture = ((::NiTexture *)(::fnv_00a5ff10::FUN_00a5ff10((::fnv_00a5ff10::RefCounted *)(pdetailpixeldata), (void *)(NiFixedString("DefaultDetailModFaceGenTexture")), (const ::fnv_00a5ff10::OwnerTriple *)&((*reinterpret_cast<::fnv_00650ea0::TextureFormatPreferences *>(&::DAT_011a9598))))));

    (*reinterpret_cast<bool *>(&::DAT_011d59e0)) = true;
}
}  // namespace fnv_00650ea0

namespace fnv_00651450 {
struct FUN_00651520
{
    int b[0xa0 / 4];
    FUN_00651520();
    ~FUN_00651520();
};
struct FUN_00651630
{
    int b[0x28 / 4];
    FUN_00651630();
    ~FUN_00651630();
};
struct FUN_00651670
{
    int b[0x48 / 4];
    FUN_00651670();
    ~FUN_00651670();
};
template <class T> struct FaceGenMatrix
{
    int b[0x20 / 4];
    FaceGenMatrix();
    ~FaceGenMatrix();
};

struct FUN_00651450
{
    bool initialized;
    FUN_00651520 m_kFaceGenRecords[5];
    FUN_00651630 attr[20];
    FUN_00651670 race[25];
    FaceGenMatrix<float> basis[20];
    FUN_00651450();
};

// Initializes the object by setting the initialized flag to false; the member arrays are default-constructed.
// @fnv 0x00651450
FUN_00651450::FUN_00651450() : initialized(false)
{}
}  // namespace fnv_00651450

namespace fnv_00651e70 {
struct BSFaceGenModel;
struct FGModelPtr
{
    operator BSFaceGenModel*() const;
};
struct FGHolder
{
    char pad[8];
    FGModelPtr model;
};
struct GO
{
    void* p;
    GO(int);
    ~GO();
    operator FGHolder*() const;
};
struct BSFaceGenModelHelper
{
};
struct NavMeshVertexMap
{
};
struct Map62d0
{
};
struct FGManagerView
{
    char pad[4];
    NavMeshVertexMap map;
    void ClearModelTextures();
};
void FUN_00652140();
void FUN_00652190();

// Calls FUN_00652140, iterates positions from map, clears texture data on each model found, then calls FUN_00652190.
// @fnv 0x00651e70
void FGManagerView::ClearModelTextures()
{
    FUN_00652140();
    void* pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(map))->GetFirstPos();
    while (pos)
    {
        unsigned int id = 0;
        GO ptr(0);
        reinterpret_cast<::Map62d0 *>((reinterpret_cast<Map62d0*>(&map)))->FUN_00559120((::MapItem62d0 *&)(pos), (void *&)(id), (::Helper62d0 &)(ptr));
        if (ptr)
        {
            BSFaceGenModel* model = static_cast<FGHolder*>(ptr)->model;
            if (model)
                reinterpret_cast<::BSFaceGenModel *>((reinterpret_cast<BSFaceGenModelHelper*>(model)))->ClearTextureData();
        }
    }
    FUN_00652190();
}
}  // namespace fnv_00651e70

namespace fnv_00651f70 {
namespace lc1 {
struct AutoMemContext
{
    int ctxId;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
}
struct FaceGenImpl
{
    bool FUN_00650480(int);
};
struct FaceGenMgrView
{
    char pad[0x1194];
    FaceGenImpl* impl;
};

// Checks that the FaceGen manager and its impl exist, then forwards param_1 to impl->FUN_00650480 and returns its result.
// @fnv 0x00651f70
bool FUN_00651f70(int aiArg)
{
    lc1::AutoMemContext ctx(
        0x38, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0x44c);
    if (!DAT_011d59e8)
        return false;
    if (!reinterpret_cast<FaceGenMgrView*>(DAT_011d59e8)->impl)
        return false;
    return reinterpret_cast<FaceGenMgrView*>(DAT_011d59e8)->impl->FUN_00650480(aiArg);
}
}  // namespace fnv_00651f70

namespace fnv_00652040 {
namespace lc1 {
struct AutoMemContext
{
    int ctxId;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
}
struct FaceGenImpl
{
    bool TouchCachedModel(int);
};
struct FaceGenMgrView
{
    char pad[0x1194];
    FaceGenImpl* impl;
};

// Checks that the FaceGen manager and its implementation exist, then forwards param_1 to the implementation's TouchCachedModel and returns its result.
// @fnv 0x00652040
bool FUN_00652040(int aiArg)
{
    lc1::AutoMemContext ctx(
        0x39, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0x45a);
    if (!DAT_011d59e8)
        return false;
    if (!reinterpret_cast<FaceGenMgrView*>(DAT_011d59e8)->impl)
        return false;
    return reinterpret_cast<FaceGenMgrView*>(DAT_011d59e8)->impl->TouchCachedModel(aiArg);
}
}  // namespace fnv_00652040

namespace fnv_00653520 {
struct StrMem
{
    operator const char*() const;
};
struct TaskQueueInterface
{
};

// @fnv 0x00653520
const char* BuildEgmFilename(StrMem* aOutFilename, const char* apModel, int aeHairPart)
{
    char porigFilename[260];
    char pfinalFilename[260];
    char* pextension = 0;

    if (!apModel)
        return 0;
    ::TaskQueueInterface::CopyStringToBuffer(porigFilename, 260, apModel);
    pextension = ::FUN_0040ab30(porigFilename, 0x2e);
    if (!pextension)
        return 0;
    *pextension = 0;
    switch (aeHairPart)
    {
    case 0:
    case 1:
        ::FUN_00406d00(pfinalFilename, 260, "%s%s.egm", porigFilename, ::DAT_0119b734[aeHairPart]);
        break;
    default:
        ::FUN_00406d00(pfinalFilename, 260, "%s.egm", porigFilename);
        break;
    }
    reinterpret_cast<::TextString *>((aOutFilename))->FUN_004037f0(pfinalFilename, 0);
    return *aOutFilename;
}
}  // namespace fnv_00653520

struct BSStr
{
    operator const char*() const;
};

// @fnv 0x006537d0
const char* __cdecl GetModelEgtFilename(BSStr* aOutFilename, const char* apModel)
{
    char porigFilename[260];
    char pfinalFilename[260];
    char* pextension = 0;
    if (!apModel)
        return 0;
    ::TaskQueueInterface::CopyStringToBuffer(porigFilename, 260, apModel);
    pextension = FUN_0040ab30(porigFilename, '.');
    if (!pextension)
        return 0;
    *pextension = 0;
    ::FUN_00406d00(pfinalFilename, 260, "%s.egt", porigFilename);
    reinterpret_cast<::TextString *>((aOutFilename))->FUN_004037f0(pfinalFilename, 0);
    return *aOutFilename;
}

struct NPX
{
    void* p;
    NPX(int);
    ~NPX();
    operator unsigned int() const;
};

// Returns the value stored at offset 0x1198 of DAT_011d59e8, or 0 when DAT_011d59e8 is null.
// @fnv 0x00655270
unsigned int __cdecl FUN_00655270()
{
    return (unsigned int)(DAT_011d59e8 ? *(NPX*)((char*)DAT_011d59e8 + 0x1198) : NPX(0));
}

namespace fnv_00655320 {
struct NiPoint3;
struct NiStream;
struct TESEyes;
struct TESHair;
struct TESModel;
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct NiMemObject
{
    char _pad_0[1];
};
struct FaceGenData
{
    void* __vecDelDtor(unsigned int);
    char m_kFaceGenCoordinates[96];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    int m_eSex;
    char m_kModelObjectsItem[16];
    char pTexture[16];
    char m_kTexturePaths[16];
    char m_kFaceGenTextures[16];
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    char _pad_b6[2];
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    int m_eFaceGenLOD;
    char Accessories[8];
};
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};

class BSFaceGenNiNode;
class NiSourceTexture;
class NiTriBasedGeom;
template <class T> class BSStringT
{
  public:
    BSStringT();
    ~BSStringT();
    operator const T*() const;
    int __cdecl PrintfString(const char* apFormat, ...);
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
};
template <> class NiPointer<NiSourceTexture>
{
  public:
    NiPointer(NiSourceTexture* apObject);
    ~NiPointer();
    operator NiSourceTexture*() const;
    NiPointer<NiSourceTexture>& operator=(NiSourceTexture* apObject);
    NiSourceTexture* m_pObject;
};
template <> class NiPointer<NiTriBasedGeom>
{
  public:
    NiPointer(NiTriBasedGeom* apObject);
    ~NiPointer();
    operator NiTriBasedGeom*() const;
    NiPointer<NiTriBasedGeom>& operator=(NiTriBasedGeom* apObject);
    NiTriBasedGeom* m_pObject;
};
namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int aeContext, bool abCheck, const char* apFile, int aiLine);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}
struct B006815c0
{
    B006815c0();
    float m_afEntries[3][3];
};
struct FNStub
{
};
struct PropHelper
{
};
struct NiTriBasedGeomSkinQuery
{
};
namespace fx {
struct NiFixedString
{
    NiFixedString(const char* apString);
    ~NiFixedString();
    const char* m_kHandle;
};
}
class TES
{
  public:
};
class BSFaceGenModel;
class BSFileEntry;
class NiObject;
class NiSourceTexture;
class NiTriBasedGeom;
class NiShadeProperty;
class NiFixedString;
struct FaceGenData;
struct TESHair;
struct V3;
extern V3 _NiPoint3_ZERO;
enum ArchiveType
{
    ARCHIVE_TYPE_ALL = 0
};
struct FileNameHash
{
    FileNameHash();
    unsigned int iData[2];
};
struct ArchiveManager
{
};
struct FUN_0065a910_shell
{
};
struct FUN_00440460_S
{
};
struct FUN_0043fa80_s
{
};
struct NiGeometryCullSI
{
};
struct NiObjectNET
{
};
struct NiAVObject_Attach
{
};
struct NiTriBasedGeomSkinSI
{
};
struct NiPropertyTypeSI
{
};
const char* __cdecl BuildEgmFilename(BSStringT<char>* apOut, const char* apModel, int aePart);
const char* __cdecl BuildTriPathAndSet(BSStringT<char>* apOut, const char* apModel, int aePart);
BSFaceGenModel* __cdecl GetOrCreateFaceGenModel(const char* apEGM, const char* apModel, const char* apTRI, int a4,
                                                int a5, int aePart, int a7);
void __cdecl FUN_00653470(NiTriBasedGeom* apShape, float afLength);
class TESModelDispatch
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual const char* GetModelFilePath();
};
class NiNodeAttachDispatch
{
  public:
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
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
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
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
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
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void AttachChildInAvailableSlot(NiTriBasedGeom* apChild, bool abFirstAvail);
};
class ShaderPropertyTextureDispatch
{
  public:
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
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
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
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
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
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
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
    virtual void Slot3A();
    virtual void Slot3B();
    virtual void SetTexture(int a1, int a2, NiSourceTexture* apTexture);
};

// @fnv 0x00655320
void BuildHairFaceGenNodes(BSFaceGenNiNode** apOutNodeBiped, BSFaceGenNiNode** apOutNodeSkinned, FaceGenData* aNpcData,
                           bool abForceNoSkinning)
{
    lc1::AutoMemContext tempMemContext(
        0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0xb3b);
    BSStringT<char> filename;
    BSStringT<char> fileEGM;
    BSStringT<char> fileTRI;
    BSStringT<char> fileEGT;
    BSStringT<char> fileFIM;
    NiPointer<NiSourceTexture> sptexBase(0);
    NiPointer<NiTriBasedGeom> spshape(0);
    B006815c0 matrot;
    reinterpret_cast<::ThreeByThreeMatrix *>((((ThreeByThreeMatrix*)&matrot)))->SetYRotation(-1.5707964f);
    if (*(TESHair**)((char*)aNpcData + 0x80))
    {
        for (int ehairPart = 0; ehairPart < 2; ehairPart++)
        {
            ::FUN_00406f60((::FUN_00406f90_this *)&(filename), 
                "Meshes\\%s",
                ((TESModelDispatch*)((char*)*(TESHair**)((char*)aNpcData + 0x80) + 0x24))->GetModelFilePath());
            const char* pegm = BuildEgmFilename(&fileEGM, filename, ehairPart);
            const char* ptri = BuildTriPathAndSet(&fileTRI, filename, ehairPart);
            BSFaceGenModel* pmodelFG = 0;
            FileNameHash dirHash;
            FileNameHash fileHash;
            ::HashPathComponents(pegm, (::FileNameHash *)&(dirHash), (::FileNameHash *)&(fileHash));
            BSFileEntry* pEntry = ((::fnv_00655320::BSFileEntry *)(::fnv_00af6540::FindFileEntryInArchives((*(int *)&(const ::fnv_00655320::ArchiveType &)(ARCHIVE_TYPE_ALL)), (::fnv_00af6540::FileNameHash &)(dirHash), (::fnv_00af6540::FileNameHash &)(fileHash), pegm)));
            if (!pEntry)
            {
                if (ehairPart == 0)
                {
                    pegm = BuildEgmFilename(&fileEGM, filename, -1);
                    ptri = BuildTriPathAndSet(&fileTRI, filename, -1);
                    pmodelFG = GetOrCreateFaceGenModel(pegm, filename, ptri, 0, 1, ehairPart, 0);
                    ehairPart = 2;
                }
            }
            else
            {
                pmodelFG = GetOrCreateFaceGenModel(pegm, filename, ptri, 0, 1, ehairPart, 0);
            }
            if (pmodelFG)
                reinterpret_cast<::FUN_0065a910_shell *>((((FUN_0065a910_shell*)pmodelFG)))->FUN_0065a910(aNpcData, &spshape);
            if (spshape)
            {
                if (ehairPart == 1)
                    reinterpret_cast<::TaskQueueInterface *>((((NiGeometryCullSI*)(NiTriBasedGeom*)spshape)))->QueueActorDisarm(true);
                char tempHairName[32];
                ::AssignFixedString((char *)(((NiObjectNET*)(NiTriBasedGeom*)spshape)), (int)&(const ::fnv_00655320::fx::NiFixedString &)(fx::NiFixedString(BSFaceGenManager::BuildFaceGenPartPath(tempHairName, ehairPart))), {});
                FUN_00653470(spshape, *(float*)((char*)aNpcData + 0x88));
                ::FUN_00406f60((::FUN_00406f90_this *)&(filename), "Textures\\%s",
                                 ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)((char*)*(TESHair**)((char*)aNpcData + 0x80) + 0x3c))))->FUN_00408da0())));
                reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00655320::TES * *>(&::g_TES))))->FUN_004568c0(filename, (::TexPtr< ::NiSourceTexture> &)(sptexBase), false, false);
                if (sptexBase)
                {
                    ShaderPropertyTextureDispatch* pshaderprop;
                    NiShadeProperty* pprop = (NiShadeProperty*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)(NiTriBasedGeom*)spshape)))->FUN_00a59d30(3)));
                    if ((pshaderprop =
                             (ShaderPropertyTextureDispatch*)((pprop == 0
                                                                   ? 0
                                                                   : (((int)(reinterpret_cast<::BGSTerrainManager *>((((NiPropertyTypeSI*)pprop)))->GetMinLevel())) >= 8 &&
                                                                      ((int)(reinterpret_cast<::BGSTerrainManager *>((((NiPropertyTypeSI*)pprop)))->GetMinLevel())) <= 12))
                                                                  ? pprop
                                                                  : 0)) != 0)
                        pshaderprop->SetTexture(0, 0, sptexBase);
                }
                if (!((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)(NiTriBasedGeom*)spshape)))->FUN_00a59d30(0))))
                    reinterpret_cast<::FUN_00439410_cls *>((((NiAVObject_Attach*)(NiTriBasedGeom*)spshape)))->FUN_00439410((::ArgObject *)(::fnv_00655320::NiObject *)(((::fnv_00655320::NiObject *)(::FUN_00655270()))));
                if (((void *)(::fnv_0043fad0::FUN_0043fad0((const char *)(((NiTriBasedGeomSkinQuery*)(NiTriBasedGeom*)spshape))))))
                {
                    if (abForceNoSkinning)
                    {
                        reinterpret_cast<::FUN_004adde0_shell *>((((NiTriBasedGeomSkinSI*)(NiTriBasedGeom*)spshape)))->FUN_004adde0((::NiNode *)(void *)(0));
                        reinterpret_cast<::FUN_00440460_S *>((((FUN_00440460_S*)(NiTriBasedGeom*)spshape)))->FUN_00440460((const ::V3 *)(const ::fnv_00655320::V3 *)(&_NiPoint3_ZERO));
                        reinterpret_cast<::FUN_0043fa80_s *>((((FUN_0043fa80_s*)(NiTriBasedGeom*)spshape)))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(*(ThreeByThreeMatrix*)&matrot));
                        ((NiNodeAttachDispatch*)*apOutNodeBiped)->AttachChildInAvailableSlot(spshape, true);
                    }
                    else
                    {
                        ((NiNodeAttachDispatch*)*apOutNodeSkinned)->AttachChildInAvailableSlot(spshape, true);
                    }
                }
                else
                {
                    reinterpret_cast<::FUN_0043fa80_s *>((((FUN_0043fa80_s*)(NiTriBasedGeom*)spshape)))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(*(ThreeByThreeMatrix*)&matrot));
                    ((NiNodeAttachDispatch*)*apOutNodeBiped)->AttachChildInAvailableSlot(spshape, true);
                }
            }
            pmodelFG = 0;
            spshape = 0;
            sptexBase = 0;
        }
    }
}
}  // namespace fnv_00655320

namespace fnv_006558b0 {
struct NiPoint3;
struct NiStream;
struct TESEyes;
struct TESHair;
struct TESModel;
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct NiMemObject
{
    char _pad_0[1];
};
struct FaceGenData
{
    void* __vecDelDtor(unsigned int);
    char m_kFaceGenCoordinates[96];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    int m_eSex;
    char m_kModelObjectsItem[16];
    char pTexture[16];
    char m_kTexturePaths[16];
    char m_kFaceGenTextures[16];
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    char _pad_b6[2];
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    int m_eFaceGenLOD;
    char Accessories[8];
};
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};

namespace lc1 {
struct AutoMemContext
{
    int m_eMemoryContext;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
}
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
    int __cdecl PrintfString(const char*, ...);
    operator const T*() const;
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct NiPoint3
{
    float x, y, z;
    static const NiPoint3 ZERO;
};
namespace PC {
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    ThreeByThreeMatrix();
    void SetYRotation(float);
};
}
class NiSourceTexture;
class NiSkinInstance;
class NiAVObject
{
  public:
};
class NiShadeProperty
{
  public:
};
class NiTriBasedGeom : public NiAVObject
{
  public:
};
template <> class NiPointer<NiSourceTexture>
{
  public:
    NiSourceTexture* m_pObject;
    NiPointer(NiSourceTexture*);
    ~NiPointer();
    NiPointer& operator=(NiSourceTexture*);
    operator NiSourceTexture*() const;
};
template <> class NiPointer<NiTriBasedGeom>
{
  public:
    NiTriBasedGeom* m_pObject;
    NiPointer(NiTriBasedGeom*);
    ~NiPointer();
    NiPointer& operator=(NiTriBasedGeom*);
    operator NiTriBasedGeom*() const;
    NiTriBasedGeom* operator->() const;
};
struct TESModel
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual const char* GetModelFilePath();
};
struct TESEyesFormBase
{
    char pad[0x24];
};
struct TESTexture
{
    char pad[0xc];
};
struct TESEyes : public TESEyesFormBase, public TESTexture
{
};
class BSShaderPPLightingProperty
{
  public:
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
    virtual void SetTexture(int, int, NiSourceTexture*);
};
class BSFaceGenNiNode
{
  public:
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
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
};
class BSFaceGenModel
{
  public:
};
class TES
{
  public:
};
BSFaceGenModel* __cdecl GetOrCreateFaceGenModel(const char*, const char*, const char*, int, bool, int, int);
const char* __cdecl BuildEgmFilename(BSStringT<char>&, const char*, int);
const char* __cdecl BuildTriPathAndSet(BSStringT<char>&, const char*, int);

// Builds the left and right eye geometry from the NPC's eye models, applies the eye texture, and attaches each shape to the biped or skinned node.
// @fnv 0x006558b0
void __cdecl CreateEyeGeometry(BSFaceGenNiNode** apOutNodeBiped, BSFaceGenNiNode** apOutNodeSkinned,
                               FaceGenData* aNpcData, bool abForceNoSkinning)
{
    lc1::AutoMemContext tempMemContext(
        0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0xba7);
    BSStringT<char> filename;
    BSStringT<char> fileEGM;
    BSStringT<char> fileTRI;
    BSStringT<char> fileEGT;
    BSStringT<char> fileFIM;
    NiPointer<NiSourceTexture> sptexBase(0);
    NiPointer<NiTriBasedGeom> spshape(0);
    PC::ThreeByThreeMatrix matrot;
    BSFaceGenModel* pmodelFG = 0;
    reinterpret_cast<::ThreeByThreeMatrix *>(&(matrot))->SetYRotation(-1.5707964f);
    if (*(TESModel**)((char*)aNpcData + 0xd8))
    {
        ::FUN_00406f60((::FUN_00406f90_this *)&(filename), "Meshes\\%s", (*(TESModel**)((char*)aNpcData + 0xd8))->GetModelFilePath());
        pmodelFG = GetOrCreateFaceGenModel(BuildEgmFilename(fileEGM, filename, -1), filename,
                                           BuildTriPathAndSet(fileTRI, filename, -1), 0, true, -1, 0);
        if (pmodelFG)
            reinterpret_cast<::FUN_0065a910_shell *>((pmodelFG))->FUN_0065a910(aNpcData, (void *)&(spshape));
        if (spshape)
        {
            ::AssignFixedString((char *)((spshape).operator->()), (int)&(const ::fnv_006558b0::NiFixedString &)(NiFixedString("FaceGenEyeLeft")), {});
            if (*(TESEyes**)((char*)aNpcData + 0x8c))
            {
                ::FUN_00406f60((::FUN_00406f90_this *)&(filename), "Textures\\%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(((*(TESEyes**)((char*)aNpcData + 0x8c))))->FUN_00408da0())));
                reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_006558b0::TES * *>(&::g_TES))))->FUN_004568c0(filename, (::TexPtr< ::NiSourceTexture> &)(sptexBase), false, false);
            }
            else
            {
                reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_006558b0::TES * *>(&::g_TES))))->FUN_004568c0("Textures\\Characters\\Eyes\\EyeDefault.dds", (::TexPtr< ::NiSourceTexture> &)(sptexBase), false, false);
            }
            if (sptexBase)
            {
                NiShadeProperty* pprop = ((::fnv_006558b0::NiShadeProperty *)(reinterpret_cast<::FUN_00a59d30_C *>(((spshape).operator->()))->FUN_00a59d30(3)));
                BSShaderPPLightingProperty* pshaderprop;
                if (pshaderprop = (pprop == 0 ? 0 : (((int)(reinterpret_cast<::BGSTerrainManager *>((pprop))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((pprop))->GetMinLevel())) <= 12))
                                      ? (BSShaderPPLightingProperty*)pprop
                                      : 0)
                    pshaderprop->SetTexture(0, 0, sptexBase);
            }
            if (((::fnv_006558b0::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)((spshape).operator->())))))
            {
                if (abForceNoSkinning)
                {
                    reinterpret_cast<::FUN_004adde0_shell *>(((spshape).operator->()))->FUN_004adde0((::NiNode *)(::fnv_006558b0::NiSkinInstance *)(0));
                    reinterpret_cast<::FUN_00440460_S *>(((spshape).operator->()))->FUN_00440460((const ::V3 *)&(NiPoint3::ZERO));
                    reinterpret_cast<::FUN_0043fa80_s *>(((spshape).operator->()))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(matrot));
                    (*apOutNodeBiped)->AttachChildInAvailableSlot(spshape, true);
                }
                else
                {
                    (*apOutNodeSkinned)->AttachChildInAvailableSlot(spshape, true);
                }
            }
            else
            {
                reinterpret_cast<::FUN_0043fa80_s *>(((spshape).operator->()))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(matrot));
                (*apOutNodeBiped)->AttachChildInAvailableSlot(spshape, true);
            }
        }
        pmodelFG = 0;
        spshape = 0;
        sptexBase = 0;
    }
    if (*(TESModel**)((char*)aNpcData + 0xdc))
    {
        ::FUN_00406f60((::FUN_00406f90_this *)&(filename), "Meshes\\%s", (*(TESModel**)((char*)aNpcData + 0xdc))->GetModelFilePath());
        pmodelFG = GetOrCreateFaceGenModel(BuildEgmFilename(fileEGM, filename, -1), filename,
                                           BuildTriPathAndSet(fileTRI, filename, -1), 0, true, -1, 0);
        if (pmodelFG)
            reinterpret_cast<::FUN_0065a910_shell *>((pmodelFG))->FUN_0065a910(aNpcData, (void *)&(spshape));
        if (spshape)
        {
            ::AssignFixedString((char *)((spshape).operator->()), (int)&(const ::fnv_006558b0::NiFixedString &)(NiFixedString("FaceGenEyeRight")), {});
            if (*(TESEyes**)((char*)aNpcData + 0x8c))
            {
                ::FUN_00406f60((::FUN_00406f90_this *)&(filename), "Textures\\%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(((*(TESEyes**)((char*)aNpcData + 0x8c))))->FUN_00408da0())));
                reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_006558b0::TES * *>(&::g_TES))))->FUN_004568c0(filename, (::TexPtr< ::NiSourceTexture> &)(sptexBase), false, false);
            }
            else
            {
                reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_006558b0::TES * *>(&::g_TES))))->FUN_004568c0("Textures\\Characters\\Eyes\\EyeDefault.dds", (::TexPtr< ::NiSourceTexture> &)(sptexBase), false, false);
            }
            if (sptexBase)
            {
                NiShadeProperty* pprop = ((::fnv_006558b0::NiShadeProperty *)(reinterpret_cast<::FUN_00a59d30_C *>(((spshape).operator->()))->FUN_00a59d30(3)));
                BSShaderPPLightingProperty* pshaderprop;
                if (pshaderprop = (pprop == 0 ? 0 : (((int)(reinterpret_cast<::BGSTerrainManager *>((pprop))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((pprop))->GetMinLevel())) <= 12))
                                      ? (BSShaderPPLightingProperty*)pprop
                                      : 0)
                    pshaderprop->SetTexture(0, 0, sptexBase);
            }
            if (((::fnv_006558b0::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)((spshape).operator->())))))
            {
                if (abForceNoSkinning)
                {
                    reinterpret_cast<::FUN_004adde0_shell *>(((spshape).operator->()))->FUN_004adde0((::NiNode *)(::fnv_006558b0::NiSkinInstance *)(0));
                    reinterpret_cast<::FUN_00440460_S *>(((spshape).operator->()))->FUN_00440460((const ::V3 *)&(NiPoint3::ZERO));
                    reinterpret_cast<::FUN_0043fa80_s *>(((spshape).operator->()))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(matrot));
                    (*apOutNodeBiped)->AttachChildInAvailableSlot(spshape, true);
                }
                else
                {
                    (*apOutNodeSkinned)->AttachChildInAvailableSlot(spshape, true);
                }
            }
            else
            {
                reinterpret_cast<::FUN_0043fa80_s *>(((spshape).operator->()))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(matrot));
                (*apOutNodeBiped)->AttachChildInAvailableSlot(spshape, true);
            }
        }
        pmodelFG = 0;
        spshape = 0;
        sptexBase = 0;
    }
}
}  // namespace fnv_006558b0

namespace fnv_00653340 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct NiMemObject
{
    char _pad_0[1];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
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
struct FourComponentNumericValue
{
    char u[16];
};

struct NiAVObject;
struct NiExtraData;
struct NiGeometryData;
struct Flt
{
    operator unsigned int() const;
};
struct NiGeometry
{
};
struct TriBasedGeomHelper
{
};
struct ScrapMultiMapHelper
{
    void SetPoint(NiPoint3 const&);
};
struct GeomDataHelper
{
};
NiExtraData* __cdecl GetExtraDataIfPresent(NiAVObject*);

// @fnv 0x00653340
void FUN_00653340(NiAVObject* apGeom, NiPoint3* apPoint)
{
    NiExtraData* base = GetExtraDataIfPresent(apGeom);
    if (!base)
        return;
    if (!reinterpret_cast<Flt*>(apPoint)->operator unsigned int())
        return;
    NiPoint3 iter = *apPoint;
    unsigned int aI = 0;
    NiPoint3* pSource = reinterpret_cast<NiPoint3*>(reinterpret_cast<::FUN_0084e3a0_Class *>((base))->FUN_0084e3a0());
    for (; aI < reinterpret_cast<::FUN_00456650_shell *>((reinterpret_cast<TriBasedGeomHelper*>(apGeom)))->FUN_00456650(); ++aI, ++pSource)
    {
        reinterpret_cast<ScrapMultiMapHelper*>(&iter)->SetPoint(*pSource);
        reinterpret_cast<::FUN_00657be0_class *>((reinterpret_cast<ScrapMultiMapHelper*>(&iter)))->AddToA();
    }
    if (((int)(reinterpret_cast<::FUN_0049ec60 *>((apGeom))->GetNext())))
        reinterpret_cast<::NiGeometryData *>((reinterpret_cast<GeomDataHelper*>(((::fnv_00653340::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)(reinterpret_cast<NiGeometry*>(apGeom))))))))->SetDirtyFlags(1);
}
}  // namespace fnv_00653340

struct BSFaceGenMorphData
{
    char m_data[0x34];
    float fUnknown;
    float FUN_00508120();
};

// @fnv 0x00508120
float BSFaceGenMorphData::FUN_00508120()
{
    return fUnknown;
}

namespace fnv_0064ffd0 {
struct GO
{
    void* m_pObject;
    GO(int);
    ~GO();
};
struct NP
{
    NP& operator=(void*);
};
struct Flt
{
    operator unsigned int() const;
};
struct SpObst
{
    void* m_pObject;
    SpObst(unsigned int*);
    SpObst(const SpObst&);
    ~SpObst();
};
struct BSFadeNode
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_00650100 : BSFadeNode
{
    unsigned int m_uiRefCount;
    const char* pcKey;
    void* m_pRenderedNodeEntry;
    unsigned int ulFadeStartTimeTick;
    FUN_00650100();
};
struct MapH
{
    void InsertOrUpdate(unsigned int, SpObst);
};
struct FGModelCache
{
    void FUN_00650ba0(int);
    void FUN_0064ffd0(const char* apcKey, void* apModel);
};
void FUN_00652140();
void FUN_00652190();

// @fnv 0x0064ffd0
void FGModelCache::FUN_0064ffd0(const char* apcKey, void* apModel)
{
    FUN_00652140();
    GO spentry(0);
    if (!apModel)
    {
        reinterpret_cast<::NiTMap_S *>((((MapH*)((char*)this + 4))))->RemoveKey((unsigned int)apcKey);
        FUN_00652190();
        return;
    }
    (NP&)spentry = new FUN_00650100();
    *(NP*)((unsigned int)(Flt&)spentry + 8) = apModel;
    *(unsigned int*)((unsigned int)(Flt&)spentry + 0xc) = ((unsigned int)(::FUN_00457fe0()));
    ((MapH*)((char*)this + 4))->InsertOrUpdate((unsigned int)apcKey, SpObst((unsigned int*)&spentry));
    FUN_00650ba0((Flt&)spentry);
    FUN_00652190();
}
}  // namespace fnv_0064ffd0

namespace fnv_00650780 {
struct GO
{
    void* m_pObject;
    GO(int);
    ~GO();
};
struct Flt
{
    operator unsigned int() const;
};
struct FGModelMap
{
};
struct TaskQueueInterface
{
};
int __cdecl strcat_s(char*, unsigned int, const char*);
void FUN_00652140();
void FUN_00652190();

struct BSFaceGenModelMap_t
{
    bool FUN_00650780(const char* apKey);
};

// Looks up apKey in the model map, retries with a .egm extension if missing, and returns true when an entry is found.
// @fnv 0x00650780
bool BSFaceGenModelMap_t::FUN_00650780(const char* apKey)
{
    if (!apKey || !*apKey)
        return false;
    bool bres = false;
    GO spentry(0);
    FUN_00652140();
    if (!reinterpret_cast<::Map62d0 *>((((FGModelMap*)((char*)this + 4))))->FUN_006c62d0((unsigned int)((void*)apKey), (void **)&(spentry)))
    {
        char* pext;
        char ptemp[260];
        ::TaskQueueInterface::CopyStringToBuffer(ptemp, 260, apKey);
        pext = ::FUN_0040ab30(ptemp, '.');
        if (pext)
        {
            *pext = 0;
            strcat_s(ptemp, 260, ".egm");
            reinterpret_cast<::Map62d0 *>((((FGModelMap*)((char*)this + 4))))->FUN_006c62d0((unsigned int)(ptemp), (void **)&(spentry));
        }
    }
    if ((Flt&)spentry)
    {
        reinterpret_cast<::fnv_0065c400::FUN_0065c400_t *>((*(Flt*)((unsigned int)(Flt&)spentry + 8)))->FUN_0065c400();
        bres = true;
    }
    FUN_00652190();
    return bres;
}
}  // namespace fnv_00650780

namespace fnv_00650ba0 {
struct Flt
{
    operator unsigned int() const;
};
struct Dummy_00650910
{
};
void FUN_00652140();
void FUN_00652190();
unsigned int FUN_0065c490(unsigned int);

struct BSFaceGenModelMap_t : Dummy_00650910
{
    void FUN_00650ba0(void* aspNewEntry);
    void FUN_00650cb0(unsigned int, void*);
};

// @fnv 0x00650ba0
void BSFaceGenModelMap_t::FUN_00650ba0(void* aspNewEntry)
{
    unsigned int size;
    unsigned int cnt;
    unsigned int totalSizePrev;
    unsigned int totalSize;
    size = 0;
    FUN_00652140();
    for (cnt = 0; cnt < 2; cnt++)
    {
        if (aspNewEntry)
        {
            switch (cnt)
            {
            case 0:
                if (reinterpret_cast<::FUN_0065c110_t *>((*(Flt*)((char*)aspNewEntry + 8)))->GetEGMSize() > 0)
                    continue;
                size = 10;
                break;
            case 1:
                if (FUN_0065c490(*(Flt*)((char*)aspNewEntry + 8)) > 0)
                    continue;
                size = 10;
                break;
            default:
                size = 0;
            }
        }
        totalSize = totalSizePrev = reinterpret_cast<::fnv_00650930::FGMapOwner *>(this)->GetModelValueSum(cnt);
        while (totalSize + size > reinterpret_cast<::Dummy_00650910 *>(this)->GetArrayElement(cnt))
        {
            totalSizePrev = totalSize;
            FUN_00650cb0(cnt, aspNewEntry);
            totalSize = reinterpret_cast<::fnv_00650930::FGMapOwner *>(this)->GetModelValueSum(cnt);
            if (totalSize == totalSizePrev)
                break;
        }
    }
    FUN_00652190();
}
}  // namespace fnv_00650ba0

namespace fnv_00651830 {
template <class T> struct FaceGenMatrix
{
    T* pData;
    unsigned int uiRows;
    unsigned int uiCols;
    unsigned int uiRowStride;
    unsigned int uiColStride;
    unsigned int uiSize;
    unsigned int uiCapacity;
    unsigned int uiFlags;
    ~FaceGenMatrix();
};

struct FUN_006515b0
{
    FaceGenMatrix<float> kSymmetric;
    FaceGenMatrix<float> kAsymmetric;
    FaceGenMatrix<float> kTexture;
    FaceGenMatrix<float> kGeometry;
    FaceGenMatrix<float> kDetail;
    ~FUN_006515b0();
};

struct FUN_00651650
{
    unsigned int uiID;
    unsigned int uiFlags;
    FaceGenMatrix<float> kCoord;
    ~FUN_00651650();
};

struct FUN_006516a0
{
    unsigned int uiID;
    unsigned int uiFlags;
    FaceGenMatrix<float> kSymmetric;
    FaceGenMatrix<float> kAsymmetric;
    ~FUN_006516a0();
};

struct FUN_00651830
{
    unsigned int uiVersion;
    FUN_006515b0 kModes[5];
    FUN_00651650 kLinear[20];
    FUN_006516a0 kMorphs[25];
    FaceGenMatrix<float> kCoords[20];
    ~FUN_00651830();
};

// @fnv 0x00651830
FUN_00651830::~FUN_00651830()
{}
}  // namespace fnv_00651830

namespace fnv_00652900 {
template <class T> struct FaceGenMatrix
{
    T* pData;
    unsigned int uiRows;
    unsigned int uiCols;
    unsigned int uiRowStride;
    unsigned int uiColStride;
    unsigned int uiSize;
    unsigned int uiCapacity;
    unsigned int uiFlags;
    bool FUN_00657880(const FaceGenMatrix* apOther) const;
};

// @fnv 0x00652900
bool FUN_00652900(const FaceGenMatrix<float> (*apCoord1)[2], FaceGenMatrix<float> (*apCoord2)[2])
{
    int etype;
    int esymm;
    if (!apCoord1 && !apCoord2)
        return true;
    if (!apCoord1 || !apCoord2)
        return false;
    for (etype = 0; etype < 2; etype++)
    {
        for (esymm = 0; esymm < 2; esymm++)
        {
            if (reinterpret_cast<::FUN_00657880_class *>((void *)&(apCoord1[etype][esymm]))->operator==((int)(&apCoord2[etype][esymm])))
                return true;
        }
    }
    return false;
}
}  // namespace fnv_00652900

namespace fnv_00653460 {

// @fnv 0x00653460
void* __cdecl FUN_00653460()
{
    return DAT_011d5b8c;
}
}  // namespace fnv_00653460

namespace fnv_00653620 {
template <class T> struct BSStringT;
struct BSStr
{
};
struct Flt
{
    operator unsigned int() const;
};
struct TaskQueueInterface
{
};

// @fnv 0x00653620
unsigned int GetModelNifFilename(BSStringT<char>& aOutFilename, const char* apModel)
{
    char porigFilename[260];
    char ptemp[260];
    char* pextension = 0;
    if (!apModel)
        return 0;
    ::TaskQueueInterface::CopyStringToBuffer(porigFilename, 260, apModel);
    pextension = ::FUN_0040ab30(porigFilename, '.');
    if (!pextension)
        return 0;
    *pextension = 0;
    ::FUN_00406d00(ptemp, 260, "%s.nif", porigFilename);
    reinterpret_cast<::TextString *>(&(((BSStr&)aOutFilename)))->FUN_004037f0(ptemp, 0);
    return (Flt&)aOutFilename;
}
}  // namespace fnv_00653620

namespace fnv_00653880 {
template <class T> struct BSStringT
{
    int PrintfString(const char*, ...);
};
struct BSStr
{
};
struct Flt
{
    operator unsigned int() const;
};
struct TaskQueueInterface
{
};
struct FileNameHash
{
    unsigned int uiLow;
    unsigned int uiHigh;
    FileNameHash();
};
struct BSFileEntry;
enum ArchiveType
{
    ARCHIVE_TYPE_MESHES,
    ARCHIVE_TYPE_TEXTURES
};
struct ArchiveManager
{
};

// @fnv 0x00653880
unsigned int FUN_00653880(BSStringT<char>& aOutFilename, int aeSex, unsigned char acAge, const char* apModel)
{
    char porigFilename[260];
    int iage;
    char cgender;
    char* pextension = 0;
    iage = acAge;
    cgender = 'M';
    if (!apModel || iage > 100 || aeSex >= 2)
        return 0;
    ::TaskQueueInterface::CopyStringToBuffer(porigFilename, 260, apModel);
    pextension = ::FUN_0040ab30(porigFilename, '.');
    if (!pextension)
        return 0;
    *pextension = 0;
    if (aeSex == 1)
        cgender = 'F';
    ::FUN_00406f60((::FUN_00406f90_this *)&(aOutFilename), "Textures\\%s%c%d.ddx", porigFilename, cgender, iage);
    FileNameHash dirHash;
    FileNameHash fileHash;
    ::HashPathComponents((const char*)(unsigned int)(Flt&)aOutFilename, (::FileNameHash *)&(dirHash), (::FileNameHash *)&(fileHash));
    BSFileEntry* pFile = ((::fnv_00653880::BSFileEntry *)(::fnv_00af6540::FindFileEntryInArchives((*(int *)&(const ::fnv_00653880::ArchiveType &)(ARCHIVE_TYPE_TEXTURES)), (::fnv_00af6540::FileNameHash &)(dirHash), (::fnv_00af6540::FileNameHash &)(fileHash),
                                                       (const char*)(unsigned int)(Flt&)aOutFilename)));
    if (pFile)
        return (Flt&)aOutFilename;
    iage = iage / 10 * 10;
    do
    {
        ::FUN_00406f60((::FUN_00406f90_this *)&(aOutFilename), "Textures\\%s%c%d.dds", porigFilename, cgender, iage);
        pFile = ((::fnv_00653880::BSFileEntry *)(::fnv_00af6540::FindFileEntryInArchives((*(int *)&(const ::fnv_00653880::ArchiveType &)(ARCHIVE_TYPE_TEXTURES)), (::fnv_00af6540::FileNameHash &)(dirHash), (::fnv_00af6540::FileNameHash &)(fileHash),
                                              (const char*)(unsigned int)(Flt&)aOutFilename)));
        if (pFile)
            return (Flt&)aOutFilename;
    } while ((iage -= 10) >= 0);
    reinterpret_cast<::TextString *>(&(((BSStr&)aOutFilename)))->FUN_004037f0("", 0);
    return 0;
}
}  // namespace fnv_00653880

namespace fnv_00653c40 {
template <class T> struct BSStringT;
struct BSStr
{
};
struct Flt
{
    operator unsigned int() const;
};
struct TaskQueueInterface
{
};

// @fnv 0x00653c40
unsigned int BuildModelFilename(BSStringT<char>& aOutFilename, const char* apModel)
{
    char porigFilename[260];
    char ptemp[260];
    char* pextension = 0;
    if (!apModel)
        return 0;
    ::TaskQueueInterface::CopyStringToBuffer(porigFilename, 260, apModel);
    pextension = ::FUN_0040ab30(porigFilename, '_');
    if (!pextension)
        return (unsigned int)apModel;
    *pextension = 0;
    ::FUN_00406d00(ptemp, 260, "%s.nif", porigFilename);
    reinterpret_cast<::TextString *>(&(((BSStr&)aOutFilename)))->FUN_004037f0(ptemp, 0);
    return (Flt&)aOutFilename;
}
}  // namespace fnv_00653c40


// @fnv 0x00aafb90
void __cdecl ReportAssertionViolation(const char* apSource, int aiLine)
{
    ::FUN_005b5e40();
}

namespace fnv_006536d0 {
struct TaskQueueInterface
{
};
struct Flt
{
    operator unsigned int() const;
};
struct StrMem : Flt
{
};

// Strips the extension from path, builds a .tri path (with a suffix for index 0 or 1), stores it in str and returns its value.
// @fnv 0x006536d0
unsigned int __cdecl BuildTriPathAndSet(StrMem* str, const char* path, int index)
{
    char szBase[260];
    char szFull[260];
    char* pExt2 = 0;

    if (!path)
        return 0;
    ::TaskQueueInterface::CopyStringToBuffer(szBase, 260, path);
    pExt2 = ::FUN_0040ab30(szBase, 46);
    if (!pExt2)
        return 0;
    *pExt2 = 0;
    switch (index)
    {
    case 0:
    case 1:
        ::FUN_00406d00(szFull, 260, "%s%s.tri", szBase, DAT_0119b734[index]);
        break;
    default:
        ::FUN_00406d00(szFull, 260, "%s.tri", szBase);
        break;
    }
    reinterpret_cast<::TextString *>((str))->FUN_004037f0(szFull, 0);
    return *str;
}
}  // namespace fnv_006536d0

namespace fnv_006521b0 {
struct _vec_60
{
    char data[0x60];
};

// Indexes into the face gen manager's array at offset 0xb8 by a*0x30+b*0x18, calls FUN_00657a30 on that entry and returns the result minus one.
// @fnv 0x006521b0
unsigned int __cdecl FUN_006521b0(int a, int b)
{
    return ::FUN_00657a30((const ::_vec_60 *)(const ::fnv_006521b0::_vec_60 *)((const _vec_60*)(((char*)&BSFaceGenManager::GetFaceGenManager()->rest[80]) + a * 0x30 + b * 0x18))) -
           1;
}
}  // namespace fnv_006521b0

struct Tile
{
};

struct FUN_007b3810Class
{
    Tile* m_tile;
    void FUN_007b3810(const char* a1);
};

// If m_tile and a1 are non-null, calls m_tile->Set with id 0x1009, the string a1 and true.
// @fnv 0x007b3810
void FUN_007b3810Class::FUN_007b3810(const char* a1)
{
    if (m_tile && a1)
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_tile))->FUN_00a01350(0x1009, (char *)(a1), true);
}

namespace fnv_00651650 {
struct FaceGenMatrix
{
    ~FaceGenMatrix();
};

struct FUN_00651650 : FaceGenMatrix
{
    ~FUN_00651650();
};

// @fnv 0x00651650
FUN_00651650::~FUN_00651650()
{}
}  // namespace fnv_00651650

struct FUN_00aac170_This
{
};
// @fnv 0x006524e0
void __cdecl FUN_006524e0(int aiArg4, int aiArg2, int aiArg3)
{
    reinterpret_cast<::fnv_00aac170::Sub_00aabdb0 *>((((FUN_00aac170_This*)&BSFaceGenManager::GetFaceGenManager()->rest[176])))->FUN_00aac170(0, aiArg2, (const float *)(aiArg3), (::fnv_00aac170::OutputMatrix *)(aiArg4));
}

struct FUN_0065e000_class
{
    int FUN_0065da80(int, int);
};
struct FUN_0065fd10_class
{
    int _p[3];
    int _f;
    FUN_0065e000_class* FUN_0065fd10(FUN_0065e000_class*);
};
// Calls FUN_0065da80 on a with this object's _f and this pointer, then returns a.
// @fnv 0x0065fd10
FUN_0065e000_class* FUN_0065fd10_class::FUN_0065fd10(FUN_0065e000_class* a)
{
    a->FUN_0065da80(_f, (int)this);
    return a;
}

namespace fnv_0065fd40 {
struct FUN_0065e000_class
{
};
struct FUN_0065fd40_class
{
    char pad[16];
    int f10;
    FUN_0065e000_class* FUN_0065fd40(FUN_0065e000_class*);
};
// Calls FUN_0065da80 on a with f10 and this, then returns a.
// @fnv 0x0065fd40
FUN_0065e000_class* FUN_0065fd40_class::FUN_0065fd40(FUN_0065e000_class* a)
{
    reinterpret_cast<::FUN_0065e000_class *>((a))->FUN_0065da80(f10, (int)this);
    return a;
}
}  // namespace fnv_0065fd40

float __cdecl FUN_00652440(int, int, int);
void __cdecl FUN_006524e0(int, int, int);

// Reads both fan attribute values for a coordinate and fan type, overrides the selected attribute with afValue, then applies the pair.
// @fnv 0x00652470
void FUN_00652470(int apCoord, int aeFanAttribute, int aeFanType, float afValue)
{
    int i;
    float values[2];
    for (i = 0; i < 2; i++)
    {
        if (i == aeFanAttribute)
            values[i] = afValue;
        else
            values[i] = FUN_00652440(apCoord, i, aeFanType);
    }
    FUN_006524e0(apCoord, aeFanType, (int)values);
}

namespace fnv_00656db0 {
struct GO
{
    operator unsigned int() const;
};


// @fnv 0x00656db0
unsigned int FUN_00656db0()
{
    return (*reinterpret_cast<::fnv_00656db0::GO *>(&::DAT_011f9510)).operator unsigned int();
}
}  // namespace fnv_00656db0

struct Target
{
    Target* FUN_0064fde0(unsigned int flags);
};
// @fnv 0x0064fde0
Target* Target::FUN_0064fde0(unsigned int flags)
{
    reinterpret_cast<::FUN_0064fe10_cls *>(this)->FUN_0064fe10_cls::~FUN_0064fe10_cls();
    if (flags & 1)
        FUN_00401030(this);
    return this;
}

struct FaceGenModel
{
};

template <class T> struct ModelPtr
{
    T* m_pObject;
    ModelPtr(T* p);
    ~ModelPtr();
    operator T*() const;
};

struct FaceGenCacheEntry
{
    int unk00;
    int unk04;
    ModelPtr<FaceGenModel> m_pRenderedNodeEntry;
    unsigned int uiTick;
};

struct FGModelKey
{
};

struct FaceGenCacheEntryMap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

unsigned int BSStringLength(const char* apString);
void FUN_00652140();
void FUN_00652190();

struct FaceGenModelCacheX
{
    int unk00;
    FaceGenCacheEntryMap kMap;
    int unk14;
    int unk18;
    int unk1C;
    bool bChanged;
    bool TouchCachedModel(FGModelKey* apKey);
};

// Looks up the entry for the key's primary or secondary name, refreshes its tick, moves it to the front, touches its model and marks the cache changed.
// @fnv 0x00650630
bool FaceGenModelCacheX::TouchCachedModel(FGModelKey* apKey)
{
    ModelPtr<FaceGenCacheEntry> spEntry(0);
    if (!apKey || !::FUN_00650600((char *)(apKey)) || !BSStringLength(::FUN_00650600((char *)(apKey))))
        return false;
    bool bResultTmp = false;
    FUN_00652140();
    if (reinterpret_cast<::Map62d0 *>(&(kMap))->FUN_006c62d0((unsigned int)(::FUN_00650600((char *)(apKey))), (void **)&(spEntry)) ||
        (((const char *)(reinterpret_cast<::fnv_006505d0::FUN_006505d0_class *>((apKey))->GetFloatValue())) && reinterpret_cast<::Map62d0 *>(&(kMap))->FUN_006c62d0((unsigned int)(((const char *)(reinterpret_cast<::fnv_006505d0::FUN_006505d0_class *>((apKey))->GetFloatValue()))), (void **)&(spEntry))))
    {
        ((FaceGenCacheEntry*)spEntry)->uiTick = ((unsigned int)(::FUN_00457fe0()));
        reinterpret_cast<::fnv_00650ba0::BSFaceGenModelMap_t *>(this)->FUN_00650ba0(spEntry);
        reinterpret_cast<::BSFaceGenModel *>((((FaceGenModel*)((FaceGenCacheEntry*)spEntry)->m_pRenderedNodeEntry)))->LoadFaceGenTexture();
        bChanged = true;
        bResultTmp = true;
    }
    FUN_00652190();
    return bResultTmp;
}

bool FUN_00652160();
void FUN_00652140();
void FUN_00652190();

struct FGCacheModel
{
    int GetRefCount();
};

struct FGCacheModelPtr
{
    FGCacheModel* m_pObject;
    operator FGCacheModel*() const;
    FGCacheModel* operator->() const;
};

struct FGCacheEntry
{
    int unk00;
    int unk04;
    FGCacheModelPtr m_pRenderedNodeEntry;
};

struct FGCacheEntryPtr
{
    FGCacheEntry* m_pObject;
    FGCacheEntryPtr(FGCacheEntry* apObject);
    ~FGCacheEntryPtr();
    operator FGCacheEntry*() const;
};

struct FGCacheMap
{
};

struct FaceGenModelCache650
{
    int unk00;
    FGCacheMap kMap;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    bool bHasData;
    void PurgeUnusedModels(bool abForce);
};

// @fnv 0x00650a30
void FaceGenModelCache650::PurgeUnusedModels(bool abForce)
{
    unsigned int uiKey4 = 0;
    FGCacheEntryPtr spEntry(0);
    bool bLocked = abForce;
    bool bStillHasData;
    void* pPos3;
    if (!abForce)
        bLocked = FUN_00652160();
    else
        FUN_00652140();
    if (bLocked)
    {
        bStillHasData = false;
        pPos3 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(kMap))->GetFirstPos();
        while (pPos3)
        {
            reinterpret_cast<::Map62d0 *>(&(kMap))->FUN_00559120((::MapItem62d0 *&)(pPos3), (void *&)(uiKey4), (::Helper62d0 &)(spEntry));
            if (((int)(reinterpret_cast<::Callees *>(((((FGCacheEntry*)spEntry)->m_pRenderedNodeEntry).operator->()))->FUN_00726070())) == 1)
            {
                reinterpret_cast<::NiTMap_S *>(&(kMap))->RemoveKey(uiKey4);
            }
            else if ((FGCacheEntry*)spEntry && (FGCacheModel*)((FGCacheEntry*)spEntry)->m_pRenderedNodeEntry)
            {
                if (!reinterpret_cast<::FUN_0065c090_shell *>(((((FGCacheEntry*)spEntry)->m_pRenderedNodeEntry).operator->()))->FUN_0065c090())
                    bStillHasData = true;
                reinterpret_cast<::BSFaceGenModel *>(((((FGCacheEntry*)spEntry)->m_pRenderedNodeEntry).operator->()))->ClearTextureData();
            }
        }
        if (!bStillHasData)
            bHasData = false;
        FUN_00652190();
    }
}

struct FGModel650
{
};

template <class T> class NiPtr650
{
  public:
    T* m_pObject;
    NiPtr650(T* p);
    ~NiPtr650();
    operator T*() const;
    bool operator==(T* p) const;
    NiPtr650& operator=(const NiPtr650& o);
};

struct FGEntry650
{
    int unk00;
    int unk04;
    NiPtr650<FGModel650> m_pRenderedNodeEntry;
    unsigned int uiLastUsed;
};

struct FGMap650
{
};

void FUN_00652140();
void FUN_00652190();

struct FGCache650
{
    int unk00;
    FGMap650 kMap;
    void FUN_00650cb0(int aeType, FGEntry650* apExclude);
};

struct FUN_006515b0_Elem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;

    ~FUN_006515b0_Elem();
};

struct FUN_006515b0
{
    FUN_006515b0_Elem unk00[2];
    FUN_006515b0_Elem unk40;
    FUN_006515b0_Elem unk60[2];

    ~FUN_006515b0();
};

// Empty destructor for the structure; the member destructors run automatically.
// @fnv 0x006515b0
FUN_006515b0::~FUN_006515b0()
{}

struct FUN_00651810_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    ~FUN_00651810_Elem();
};

struct FUN_00651810_cls
{
    FUN_00651810_Elem m_aiIndexedValues[4];

    ~FUN_00651810_cls();
};

// @fnv 0x00651810
FUN_00651810_cls::~FUN_00651810_cls()
{}

struct FaceGenMgrShell
{
    void* Destroy(int flag);
};

// If DAT_011d59e8 is set, calls Destroy(1) on it and then clears DAT_011d59e8.
// @fnv 0x00651ab0
void __cdecl FUN_00651ab0()
{
    if (DAT_011d59e8 != 0)
    {
        BSFaceGenManager* mgr = DAT_011d59e8;
        FaceGenMgrShell* kObj = (FaceGenMgrShell*)mgr;
        void* result;
        if (kObj != 0)
        {
            result = kObj->Destroy(1);
        }
        else
        {
            result = 0;
        }
        DAT_011d59e8 = 0;
    }
}

void __cdecl operator delete(void*);

struct FUN_00651b00_class
{
    void FUN_006518e0();
    FUN_00651b00_class* Destroy(unsigned int flags);
};

// Calls FUN_006518e0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00651b00
FUN_00651b00_class* FUN_00651b00_class::Destroy(unsigned int flags)
{
    FUN_006518e0();
    if (flags & 1)
    {
        ::FUN_00401030(this);
    }
    return this;
}

struct FG652_Obj90
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void* GetVal();
};
struct FG652_ED
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
    virtual struct FG652_Applier* GetApplier();
};
struct FG652_Child
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void* GetGeom();
};
struct FG652_Mat
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    FG652_Mat();
    ~FG652_Mat();
};
struct FG652_Node
{
    unsigned int FUN_0043b480();
};
struct FG652_Applier
{
};
struct FG652_List
{
};
struct FG652_Name
{
};
struct FG652_NPC
{
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
    FG652_List list;
    void* FUN_005f0cc0();
};
float __cdecl GetMorphCoordinateValue(FG652_Mat*, int, int, int);
void __cdecl FUN_00652320(FG652_Mat*, int, int, int, float);
void __cdecl FUN_00652e00(void*, void*, void*, void*);
extern bool DAT_011d59e1;

struct FG652_Actor
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
    virtual FG652_Node* GetNode3D(int);
    virtual FG652_Node* GetNode1st(int);
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual FG652_Obj90* GetObj90();
};

// @fnv 0x00652510
void FUN_00652510(FG652_Actor* apActor)
{
    FG652_NPC* pNPC4 = ((::FG652_NPC *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apActor))->FUN_007af430()));
    FG652_Obj90* p9 = apActor->GetObj90();
    void* pVal5 = p9 ? p9->GetVal() : 0;
    FG652_Mat kA[4];
    FG652_Mat kB9[4];
    FG652_Mat kC3[4];
    reinterpret_cast<::TESNPC *>((pNPC4))->GetFaceGenCoords((FaceGenMatrix<float> (&)[2][2])(kA));
    reinterpret_cast<::TESNPC *>((pNPC4))->GetFaceGenCoords((FaceGenMatrix<float> (&)[2][2])(kB9));
    float fAge8 = GetMorphCoordinateValue(kA, 0, 0, DAT_011d59f0);
    if (DAT_011d59e1)
    {
        fAge8 += (double)0.1f;
        if (fAge8 >= 10.0)
            DAT_011d59e1 = false;
    }
    else
    {
        fAge8 -= (double)0.1f;
        if (fAge8 <= -10.0)
            DAT_011d59e1 = true;
    }
    FUN_00652320(kB9, 0, 0, DAT_011d59f0, fAge8);
    FUN_00652e00(kA, kB9, kC3, 0);
    FG652_Node* pNodeVal = apActor->GetNode3D(0);
    for (int i4 = 0; i4 < 2; i4++)
    {
        unsigned int uiCount_2 = pNodeVal->FUN_0043b480();
        for (unsigned int jX = 0; jX < uiCount_2; jX++)
        {
            FG652_Child* pChild4 = ((::FG652_Child *)(reinterpret_cast<::NiNode *>((pNodeVal))->GetAt(jX)));
            void* aPGeom = pChild4 ? pChild4->GetGeom() : 0;
            if (!aPGeom)
                continue;
            FG652_ED* pED4 = (FG652_ED*)((void *)(::GetGeomExtraData((::NiTriBasedGeom *)(aPGeom))));
            FG652_Applier* pApp3 = pED4 ? pED4->GetApplier() : 0;
            if (!pApp3)
                continue;
            reinterpret_cast<::FUN_0065a970_shell *>((pApp3))->ApplyMorphs((::FaceGenCoordinate *)(kC3), (::NiTriBasedGeom *)(aPGeom), 0);
        }
        pNodeVal = apActor->GetNode1st(0);
    }
    FUN_00652e00(((void *)(reinterpret_cast<::S9fb0 *>((((::FG652_Name *)(reinterpret_cast<::Callees *>(&(pNPC4->list))->FUN_00726070()))))->FUN_005d9fb0({}))), pNPC4->FUN_005f0cc0(), kB9, reinterpret_cast<::FUN_00601800_shell *>((pNPC4))->FUN_00601800());
}

struct MatrixProxy
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    void FUN_006581e0(MatrixProxy*);
};
// @fnv 0x00652e00
void FUN_00652e00(MatrixProxy (*a)[2], MatrixProxy (*b)[2], MatrixProxy (*out)[2], bool copy)
{
    if (!a || !b || !out)
        return;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            unsigned int cols = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(&(a[i][j]))->FUN_009611e0()));
            unsigned int rows = reinterpret_cast<::BGSTerrainManager *>(&(a[i][j]))->GetMinLevel();
            if (cols && rows)
            {
                reinterpret_cast<::FR2MatrixVTCData *>(&(out[i][j]))->SetDimensions(cols, rows);
                if (i == 1 && copy)
                {
                    out[i][j].FUN_006581e0(&a[i][j]);
                }
                else
                {
                    unsigned int count = cols * rows;
                    reinterpret_cast<::VecStandIn *>(&(out[i][j]))->FUN_0044a0a0();
                    for (unsigned int k = 0; k < count; ++k)
                    {
                        float bv = *((float *)(reinterpret_cast<::V_006578b0 *>(&(a[i][j]))->FUN_006578b0(k)));
                        float av = *((float *)(reinterpret_cast<::V_006578b0 *>(&(b[i][j]))->FUN_006578b0(k)));
                        reinterpret_cast<::FloatVec *>(&(out[i][j]))->PushBack(av - bv);
                    }
                }
            }
            else
            {
                reinterpret_cast<::FR2MatrixVTCData *>(&(out[i][j]))->SetDimensions(0, 0);
            }
        }
    }
}

namespace fnv_00653120 {
struct NiNode;
struct NiAVObjectLike
{
    void** vtable;
};
extern "C" NiNode* __cdecl GetHandleObject(void*);
typedef NiAVObjectLike*(* FUN_00653120_vfunc_type)(NiAVObjectLike*);
typedef NiNode*(* FUN_00653180_type)(void*);
// Resolves apGeom to an object, calls its vtable slot at 0x94, and returns the resulting node or null.
// @fnv 0x00653120
NiNode* __cdecl GetNodeFromGeometry(void* apGeom)
{
    NiAVObjectLike* pNode = ((::fnv_00653120::NiAVObjectLike *)(::GetGeomExtraData((::NiTriBasedGeom *)(apGeom))));
    NiNode* pObject;
    if (pNode != 0 && ((FUN_00653120_vfunc_type)pNode->vtable[0x94 / 4])(pNode) != 0)
    {
        pObject = ((FUN_00653180_type)GetHandleObject)(((FUN_00653120_vfunc_type)pNode->vtable[0x94 / 4])(pNode));
    }
    else
    {
        pObject = 0;
    }
    return pObject;
}
}  // namespace fnv_00653120

struct C6533F0Point3
{
    float x;
    float y;
    float z;
};

class C6533F0Holder
{
  public:
    C6533F0Point3* m_pkPoint;

    void SetPoint(const C6533F0Point3& kPoint);
};

// Copies the given point into the object pointed to by m_pkPoint.
// @fnv 0x006533f0
void C6533F0Holder::SetPoint(const C6533F0Point3& akPoint)
{
    C6533F0Point3* pkPoint = m_pkPoint;
    C6533F0Point3* pkValue = pkPoint;
    *pkValue = akPoint;
}

class B6579D0Base
{
  public:
    int unk00;

    ~B6579D0Base();
};

class FUN_006579d0 : public B6579D0Base
{
  public:

    ~FUN_006579d0();
};

// @fnv 0x006579d0
FUN_006579d0::~FUN_006579d0()
{
    reinterpret_cast<::FUN_00657d50_cls *>(this)->FUN_00657d50();
}

void __cdecl ReportAssertionViolation(const char* apSource, int aiLine);

struct MatIter
{
    float* p0;
    void* p1;
    MatIter(const MatIter&);
    MatIter operator++(int);
    bool operator!=(const MatIter&) const;
    const float& operator*() const;
};

struct MatView
{
    float* p0;
    void* p1;
    MatView(const MatView&);
    MatView operator++(int);
    float& operator*();
};

struct FgMatrixVT
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_uiRowCount;
    unsigned int m_uiColumnCount;
    FgMatrixVT(unsigned int r, unsigned int c);
    FgMatrixVT(const FgMatrixVT&);
    ~FgMatrixVT();
    FgMatrixVT FUN_00658500(const FgMatrixVT& other) const;
};

// Asserts matching dimensions, then returns a new matrix whose elements are the element-wise sum of this matrix and other.
// @fnv 0x00658500
FgMatrixVT FgMatrixVT::FUN_00658500(const FgMatrixVT& other) const
{
    (m_uiRowCount == other.m_uiRowCount && m_uiColumnCount == other.m_uiColumnCount)
        ? (void)0
        : ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x16d);
    FgMatrixVT result(m_uiRowCount, m_uiColumnCount);
    MatView out4 = (*(::MatView *)(reinterpret_cast<::_Dummy_0044a170 *>(&(result))->FUN_0044a170({})));
    MatIter a2 = (*(::MatIter *)(reinterpret_cast<::FUN_0065fd10_class *>((void *)this)->FUN_0065fd10({})));
    MatIter b = (*(::MatIter *)(reinterpret_cast<::FUN_0065fd10_class *>((void *)&(other))->FUN_0065fd10({})));
    for (; reinterpret_cast<::FUN_0065dfd0_class *>((void *)&(const ::MatIter &)(a2))->FUN_0065dfd0((int)&(const ::MatIter &)((*(::MatIter *)(reinterpret_cast<::fnv_0065fd40::FUN_0065fd40_class *>((void *)this)->FUN_0065fd40({}))))); a2++, b++, out4++)
        reinterpret_cast<::FUN_0064dbd0_Class *>((void *)&(const ::MatView &)(out4))->FUN_0064dbd0() = reinterpret_cast<::FUN_0064dda0_cls *>((void *)&(const ::MatIter &)(a2))->FUN_0064dda0() + reinterpret_cast<::FUN_0064dda0_cls *>((void *)&(const ::MatIter &)(b))->FUN_0064dda0();
    return result;
}

// Reconstructed function FUN_00659100
// Copies a 2-dword pair out of the object, refreshes the object through a
// member helper and stores the saved pair into the caller supplied buffer.

struct FG_00659100_pair
{
    int m_uiX;
    int m_uiY;
};

struct FG_00659100_cls
{
    FG_00659100_pair m_pair;
    void FUN_00659190();
    FG_00659100_pair* FUN_00659100(FG_00659100_pair* pOut, int iUnused);
};

// Copies m_pair to a local, calls FUN_00659190, writes the saved pair to pOut and returns pOut.
// @fnv 0x00659100
FG_00659100_pair* FG_00659100_cls::FUN_00659100(FG_00659100_pair* pOutPair, int iUnused)
{
    FG_00659100_pair tmp = this->m_pair;

    this->FUN_00659190();

    *pOutPair = tmp;

    return pOutPair;
}

void FG_00659100_cls::FUN_00659190()
{}

struct SegThing
{
    int m_00;
};

struct SegItem
{
    int pad[4];
    SegThing t;
};

struct SegRange
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct SegElem
{
    int m_00;
    SegRange sub;
};

struct SegHolder
{
    int pad[2];
    SegElem* m_08;
};

struct FUN_0065c490_cls
{
    int pad[3];
    SegHolder* m_0c;
    unsigned int FUN_0065c490();
};
// Scans the map for an entry whose model reports unused for the given type, picks the one with the oldest uiLastUsed, releases it, and returns nothing.
// @fnv 0x00650cb0
void FGCache650::FUN_00650cb0(int aeType, FGEntry650* apExclude)
{
    void* pKey = 0;
    void* pBestKey9 = 0;
    NiPtr650<FGEntry650> _spEntry(0);
    NiPtr650<FGEntry650> spBest2(0);
    unsigned int uiNow5 = ((unsigned int)(::FUN_00457fe0()));
    FUN_00652140();
    unsigned int uiUnused8;
    void* pPosVal = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(kMap))->GetFirstPos();
    while (pPosVal)
    {
        reinterpret_cast<::Map62d0 *>(&(kMap))->FUN_00559120((::MapItem62d0 *&)(pPosVal), pKey, (::Helper62d0 &)(_spEntry));
        if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::NiPtr650< ::FGEntry650> &)(_spEntry))->operator==((int)(apExclude)))
            continue;
        switch (aeType)
        {
        case 0:
            uiUnused8 = reinterpret_cast<::FUN_0065c110_t *>((((FGModel650*)((FGEntry650*)_spEntry)->m_pRenderedNodeEntry)))->GetEGMSize();
            break;
        case 1:
            uiUnused8 = reinterpret_cast<::FUN_0065c490_cls *>((((FGModel650*)((FGEntry650*)_spEntry)->m_pRenderedNodeEntry)))->FUN_0065c490();
            break;
        default:
            uiUnused8 = 0;
            break;
        }
        if (!uiUnused8)
            continue;
        if (!(FGEntry650*)spBest2)
        {
            spBest2 = _spEntry;
            pBestKey9 = pKey;
        }
        else if (uiNow5 - ((FGEntry650*)_spEntry)->uiLastUsed > uiNow5 - ((FGEntry650*)spBest2)->uiLastUsed)
        {
            spBest2 = _spEntry;
            pBestKey9 = pKey;
        }
    }
    if ((FGEntry650*)spBest2)
    {
        switch (aeType)
        {
        case 0:
            reinterpret_cast<::FUN_0065c090_shell *>((((FGModel650*)((FGEntry650*)spBest2)->m_pRenderedNodeEntry)))->FUN_0065c090();
            break;
        case 1:
            reinterpret_cast<::BSFaceGenModel *>((((FGModel650*)((FGEntry650*)spBest2)->m_pRenderedNodeEntry)))->ClearTextureData();
            break;
        }
    }
    FUN_00652190();
}

// Sums a base 0x34 plus per-range counts times 0x58 and per-item values times 3 across two ranges, returning the total.
// @fnv 0x0065c490
unsigned int FUN_0065c490_cls::FUN_0065c490()
{
    unsigned int i;
    unsigned int total = 0;
    if (m_0c != 0 && m_0c->m_08 != 0)
    {
        total = 0x34;
        for (i = 0; i < 2; i++)
        {
            total += ((unsigned int)(reinterpret_cast<::FUN_0065cea0_class *>(&((*(SegRange*)((char*)(&m_0c->m_08->sub) + i * 0x18))))->FUN_0065cea0())) * 0x58;
            for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::FUN_0065cea0_class *>(&((*(SegRange*)((char*)(&m_0c->m_08->sub) + i * 0x18))))->FUN_0065cea0())); j++)
            {
                total += reinterpret_cast<::FUN_0065cc50_Class *>(&(((::SegItem *)(reinterpret_cast<::Holder *>(&((*(SegRange*)((char*)(&m_0c->m_08->sub) + i * 0x18))))->FUN_0065cec0(j)))->t))->FUN_0065cc50() * 3;
            }
        }
    }
    return total;
}

void FUN_0065ee50_Helper(void* p, unsigned int size, int count, void (*dtor)());

struct FUN_006516a0_class
{
    void FUN_006516a0();
};

// @fnv 0x006516a0
void FUN_006516a0_class::FUN_006516a0()
{
    FUN_0065ee50_Helper(this, 0x20, 2, ((void (&)())::FUN_00449680));
}

struct FaceGenCoordElement
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    ~FaceGenCoordElement();
};

struct FaceGenVectorMember
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    ~FaceGenVectorMember();
};

struct FaceGenFinalMember
{
    unsigned int unk00;
    ~FaceGenFinalMember();
};

struct FUN_00651760
{
    unsigned int unk00;
    unsigned int unk04;
    FaceGenCoordElement m_kCoordinateElements[4];
    FaceGenVectorMember m_secondary;
    FaceGenFinalMember m_final;
    ~FUN_00651760();
};

// Destructor for a structure holding four FaceGenCoordElement entries, a FaceGenVectorMember and a FaceGenFinalMember.
// @fnv 0x00651760
FUN_00651760::~FUN_00651760()
{}

struct FgMat652
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int m_uiRowCount;
    unsigned int m_uiColumnCount;
    ~FgMat652();
    FgMat652 Scaled(float afScale) const;
};
struct FanCtl652
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
    FgMat652 GetMatrix() const;
};
struct FanVec652
{
    int unk00;
    int unk04;
    int unk08;
    FanCtl652* first;
    FanCtl652* last;
    FanCtl652* end;
    unsigned int size() const;
};
struct FGMgr652
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
    FanVec652 fans[2][2];
};

struct FUN_00406f90_this;
struct HashB8
{
    int a;
    int b;
};
char* __cdecl strchr(char* apStr, int aiChar);

// @fnv 0x00653a10
const char* __cdecl FUN_00653a10(BSStr* aStr, const char* apModel)
{
    StrMem iter;
    char* dot = 0;
    char* us = 0;
    char buf5[0x104];
    char buf2[0x104];
    HPList hashA;
    HashB8 hashB;
    int r6;

    if (apModel == 0)
        return 0;
    ::TaskQueueInterface::CopyStringToBuffer(buf5, 0x104, apModel);
    us = strchr(buf5, '_');
    if (us != 0)
    {
        reinterpret_cast<::TextString *>((aStr))->FUN_004037f0(buf5, 0);
        return apModel;
    }
    dot = FUN_0040ab30(buf5, '.');
    if (dot == 0)
        return apModel;
    *dot = 0;
    ::FUN_00406d00(buf2, 0x104, "%s_50.NIF", buf5);
    reinterpret_cast<::TextString *>((aStr))->FUN_004037f0(buf2, 0);
    FUN_00406f60((FUN_00406f90_this*)&iter, "Meshes\\%s", (const char*)*aStr);
    new ((void *)(&hashA)) ::Vec3();
    new ((void *)((HPList*)&hashB)) ::Vec3();
    ::HashPathComponents(((const char *)(::FUN_00559450((int *)((const BSStringT<char>*)&iter)))), (::FileNameHash *)(::HPList *)(&hashA), (::FileNameHash *)(::HPList *)((HPList*)&hashB));
    r6 = ((int)(::fnv_00af6540::FindFileEntryInArchives(0, (*(::fnv_00af6540::FileNameHash *)(&hashA)), (*(::fnv_00af6540::FileNameHash *)((HPList*)&hashB)), ((const char *)(::FUN_00559450((int *)((const BSStringT<char>*)&iter)))))));
    if (r6 == 0)
        return 0;
    return *aStr;
}

namespace fnv_00654720 {
struct NiFixedString
{
    const char* text;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct NiPoint3
{
    float x, y, z;
};
struct ThreeByThreeMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ThreeByThreeMatrix();
};
struct FileNameHash
{
    unsigned int low, high;
    FileNameHash();
};
struct FG547Property
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
    virtual void Apply(int, int, void*);
    void FUN_00441130(int, int);
};
struct FG547Node
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
    virtual void Attach(FG547Node*, int);
};
struct FG547Model
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual const char* Path();
    int FUN_0048cee0();
};
struct FG547Part
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
    FG547Model model;
};
struct FG547List
{
    FG547Part* data;
    FG547List* next;
};
struct FG547Array
{
    int unk00, unk04, unk08, unk0c;
    FG547Model** FUN_00877a30(unsigned int);
};
struct FG547Data
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
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    FG547Array models;
    FG547Array textures;
    FG547Array names;
    int unkc4, unkc8, unkcc, unkd0;
    bool texturing;
    bool player;
    short unkd6;
    void* leftEye;
    void* rightEye;
    int lod;
    FG547List accessories;
};
struct FG547Cache
{
};
struct FG547PointerOps
{
    void FUN_0066b0d0(int);
};
struct FG547Setting
{
    bool* FUN_00408d60();
};
struct FG547TextureLoader
{
};
struct NiExtraData
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct FUN_00a75650 : NiExtraData
{
    FUN_00a75650();
};
// Constructor maps to the game's property constructor.
struct FG547NewProperty
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
    void FUN_00a75650();
};
extern const char DAT_01065720[], DAT_01019710[], DAT_010657f8[], DAT_010657e4[];
extern const NiPoint3 DAT_011f426c;
void FUN_00653a10(StrMem*, const char*);
const char* BuildEgmFilename(StrMem*, const char*, int);
const char* BuildTriPathAndSet(StrMem*, const char*, int);
FG547Cache* GetOrCreateFaceGenModel(const char*, const char*, const char*, const char*, int, int, int);
FG547Property* FUN_00653270(const char*, FG547Property*);

// @fnv 0x00654720
bool __cdecl BuildCharacterParts(FG547Node** root, FG547Node** alternate, FG547Data* data, bool firstPerson)
{
    AutoMemContext textureObject((MEM_CONTEXT)0x37, true, DAT_01065720, 0xa48);
    FG547Cache* unusedPath = 0;
    GO context(0);
    GO accessory(0);
    FG547Node* cached = 0;
    FG547Node* fallbackPath = 0;
    ThreeByThreeMatrix hair;
    StrMem model;
    StrMem texture;
    StrMem primary;
    StrMem modelPath;
    StrMem rotation;
    StrMem meshPath;
    reinterpret_cast<::ThreeByThreeMatrix *>(&(hair))->SetYRotation(-1.5707963705062866f);
    for (unsigned int part = 0; part < 8; ++part)
    {
        if (!reinterpret_cast<::FUN_00658930_class *>(&(data->models))->GetShortAtOffsetA() || !*data->models.FUN_00877a30(part) ||
            !(*data->models.FUN_00877a30(part))->FUN_0048cee0())
            continue;
        if (!reinterpret_cast<::FUN_00658930_class *>(&(data->textures))->GetShortAtOffsetA() || !*data->textures.FUN_00877a30(part) ||
            !(*data->textures.FUN_00877a30(part))->FUN_0048cee0())
            continue;
        ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&model), DAT_01019710, (*data->models.FUN_00877a30(part))->Path());
        if (data->lod == 0 && part == 0)
        {
            FUN_00653a10(&meshPath, (const char*)*(BSStringT<char>*)&model);
            int fallback = 0;
            if ((const char*)*(BSStringT<char>*)&meshPath)
            {
                FileNameHash hash1;
                FileNameHash hash2;
                ::HashPathComponents((const char*)*(BSStringT<char>*)&meshPath, (::FileNameHash *)(::fnv_00654720::FileNameHash *)(&hash1), (::FileNameHash *)(::fnv_00654720::FileNameHash *)(&hash2));
                fallback = ((int)(::fnv_00af6540::FindFileEntryInArchives(0, (*(::fnv_00af6540::FileNameHash *)(&hash1)), (*(::fnv_00af6540::FileNameHash *)(&hash2)), (const char*)*(BSStringT<char>*)&meshPath)));
            }
            if (fallback)
                FUN_00653a10(&model, (const char*)*(BSStringT<char>*)&model);
        }
        const char* auxiliary = 0;
        switch (part)
        {
        case 0:
            if (data->player || *(*reinterpret_cast<::fnv_00654720::FG547Setting *>(&::g_011d5adc)).FUN_00408d60())
                auxiliary = GetModelEgtFilename((BSStr*)&modelPath, (const char*)*(BSStringT<char>*)&model);
            unusedPath = GetOrCreateFaceGenModel(
                BuildEgmFilename(&texture, (const char*)*(BSStringT<char>*)&model, -1),
                (const char*)*(BSStringT<char>*)&model,
                BuildTriPathAndSet(&primary, (const char*)*(BSStringT<char>*)&model, -1), auxiliary, 1, -1, 0);
            break;
        case 1:
            unusedPath = GetOrCreateFaceGenModel(
                BuildEgmFilename(&texture, (const char*)*(BSStringT<char>*)&model, -1),
                (const char*)*(BSStringT<char>*)&model,
                BuildTriPathAndSet(&primary, (const char*)*(BSStringT<char>*)&model, -1),
                GetModelEgtFilename((BSStr*)&modelPath, (const char*)*(BSStringT<char>*)&model), 1, -1, 0);
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            unusedPath = GetOrCreateFaceGenModel(
                BuildEgmFilename(&texture, (const char*)*(BSStringT<char>*)&model, -1),
                (const char*)*(BSStringT<char>*)&model,
                BuildTriPathAndSet(&primary, (const char*)*(BSStringT<char>*)&model, -1), 0, 1, -1, 0);
            break;
        }
        if (!unusedPath)
            continue;
        if (!reinterpret_cast<::FUN_0065a910_shell *>((unusedPath))->FUN_0065a910(data, &accessory) || !(FG547Node*)(FGEntry*)accessory)
            continue;
        ::AssignFixedString((char *)(((FG547Node*)(FGEntry*)accessory)), (int)&(const ::fnv_00654720::NiFixedString &)(NiFixedString((const char*)*data->names.FUN_00877a30(part))), {});
        if (part == 0)
            cached = (FG547Node*)(FGEntry*)accessory;
        if (part == 1)
            fallbackPath = (FG547Node*)(FGEntry*)accessory;
        ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&model), DAT_010657f8, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)*data->textures.FUN_00877a30(part))))->FUN_00408da0())));
        reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_00654720::FG547TextureLoader * *>(&::g_TES))))->FUN_004568c0((const char*)*(BSStringT<char>*)&model, (::TexPtr< ::NiSourceTexture> &)(context), false, false);
        if ((FGEntry*)context)
        {
            FG547Property* shader = ((::fnv_00654720::FG547Property *)(reinterpret_cast<::FUN_00a59d30_C *>((((FG547Node*)(FGEntry*)accessory)))->FUN_00a59d30(3)));
            FG547Property* base =
                (!shader ? false : ((int)(reinterpret_cast<::BGSTerrainManager *>((shader))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((shader))->GetMinLevel())) <= 12) ? shader : 0;
            if (base)
                base->Apply(0, 0, (FGEntry*)context);
        }
        if (part == 4 || part == 3)
        {
            if (((::fnv_00654720::FG547Property *)(reinterpret_cast<::FUN_00a59d30_C *>((((FG547Node*)(FGEntry*)accessory)))->FUN_00a59d30(0))))
                reinterpret_cast<::ExtraOwnerB *>((((FG547Node*)(FGEntry*)accessory)))->FUN_00a5b230(0);
            reinterpret_cast<::FUN_00439410_cls *>((((FG547Node*)(FGEntry*)accessory)))->FUN_00439410((::ArgObject *)(void *)((void*)FUN_00655270()));
        }
        if (part == 0 || part == 1)
        {
            FG547Property* shader = ((::fnv_00654720::FG547Property *)(reinterpret_cast<::FUN_00a59d30_C *>((((FG547Node*)(FGEntry*)accessory)))->FUN_00a59d30(::FUN_004af350())));
            FG547Property* base = shader;
            if (base)
                ::AssignFixedString((char *)(base), (int)&(*((::fnv_00654720::NiFixedString *)(::FUN_006041c0()))), {});
            else
            {
                base = (FG547Property*)new FUN_00a75650;
                ::AssignFixedString((char *)(base), (int)&(*((::fnv_00654720::NiFixedString *)(::FUN_006041c0()))), {});
                reinterpret_cast<::FUN_00439410_cls *>((((FG547Node*)(FGEntry*)accessory)))->FUN_00439410((::ArgObject *)(base));
            }
        }
        if (((void *)(::fnv_0043fad0::FUN_0043fad0((const char *)(((FG547Node*)(FGEntry*)accessory))))))
        {
            if (firstPerson)
            {
                reinterpret_cast<::FUN_004adde0_shell *>((((FG547Node*)(FGEntry*)accessory)))->FUN_004adde0((::NiNode *)(void *)(0));
                reinterpret_cast<::FUN_00440460_S *>((((FG547Node*)(FGEntry*)accessory)))->FUN_00440460((const ::V3 *)&(DAT_011f426c));
                reinterpret_cast<::FUN_0043fa80_s *>((((FG547Node*)(FGEntry*)accessory)))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(hair));
                (*root)->Attach((FG547Node*)(FGEntry*)accessory, 1);
                FG547Property* shader = ((::fnv_00654720::FG547Property *)(reinterpret_cast<::FUN_00a59d30_C *>((((FG547Node*)(FGEntry*)accessory)))->FUN_00a59d30(3)));
                FG547Property* base = FUN_00653270((*reinterpret_cast<const char (*)[]>(&::g_01200464)), shader);
                if (base)
                    base->FUN_00441130(1, 0);
            }
            else
                (*alternate)->Attach((FG547Node*)(FGEntry*)accessory, 1);
        }
        else
        {
            reinterpret_cast<::FUN_0043fa80_s *>((((FG547Node*)(FGEntry*)accessory)))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(hair));
            (*root)->Attach((FG547Node*)(FGEntry*)accessory, 1);
        }
        FG547Property* base = ((::fnv_00654720::FG547Property *)(reinterpret_cast<::FUN_00a59d30_C *>((((FG547Node*)(FGEntry*)accessory)))->FUN_00a59d30(3)));
        FG547Property* checked = base;
        FG547Property* shader =
            (!checked ? false : ((int)(reinterpret_cast<::BGSTerrainManager *>((checked))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((checked))->GetMinLevel())) <= 12) ? checked : 0;
        if (shader)
            reinterpret_cast<::BSShaderPPLightingProperty *>((shader))->EnsureNormalMap();
        unusedPath = 0;
        ((FG547PointerOps*)&context)->FUN_0066b0d0(0);
        ((FG547PointerOps*)&accessory)->FUN_0066b0d0(0);
    }
    if (::IsSettingEnabled() && cached && fallbackPath)
        ::MatchGeometryVertices((::Geometry *)(cached), (::Geometry *)(fallbackPath), 0.10000000149f, 0, 0);
    if (data->unk80)
        ::fnv_00655320::BuildHairFaceGenNodes((::fnv_00655320::BSFaceGenNiNode **)(root), (::fnv_00655320::BSFaceGenNiNode **)(alternate), (::fnv_00655320::FaceGenData *)(data), firstPerson);
    if (data->leftEye && data->rightEye)
        ::fnv_006558b0::CreateEyeGeometry((::fnv_006558b0::BSFaceGenNiNode **)(root), (::fnv_006558b0::BSFaceGenNiNode **)(alternate), (::fnv_006558b0::FaceGenData *)(data), firstPerson);
    FG547List* node = &data->accessories;
    while (node && *((::fnv_00654720::FG547Part **)(new ((void *)(node)) ::Vec3())))
    {
        ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&model), DAT_01019710, (*((::fnv_00654720::FG547Part **)(new ((void *)(node)) ::Vec3())))->model.Path());
        unusedPath = GetOrCreateFaceGenModel(BuildEgmFilename(&texture, (const char*)*(BSStringT<char>*)&model, -1),
                                             (const char*)*(BSStringT<char>*)&model,
                                             BuildTriPathAndSet(&primary, (const char*)*(BSStringT<char>*)&model, -1),
                                             0, 1, -1, 1);
        if (unusedPath && reinterpret_cast<::FUN_0065a910_shell *>((unusedPath))->FUN_0065a910(data, &accessory) && (FG547Node*)(FGEntry*)accessory)
        {
            reinterpret_cast<::FUN_0043fa80_s *>((((FG547Node*)(FGEntry*)accessory)))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(hair));
            (*root)->Attach((FG547Node*)(FGEntry*)accessory, 1);
            reinterpret_cast<::TESModelTextureSwap *>(&((*((::fnv_00654720::FG547Part **)(new ((void *)(node)) ::Vec3())))->model))->ApplyTextureSwaps((::NiAVObject *)(::fnv_00654720::FG547Node *)((FG547Node*)(FGEntry*)accessory));
            ::AssignFixedString((char *)(((FG547Node*)(FGEntry*)accessory)), (int)&(const ::fnv_00654720::NiFixedString &)(NiFixedString(DAT_010657e4)), {});
        }
        node = ((::fnv_00654720::FG547List *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return true;
}
}  // namespace fnv_00654720

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3 operator+(const NiPoint3&) const;
    NiPoint3 operator-(const NiPoint3&) const;
    float Dot(const NiPoint3&) const;
public:
    static const ::NiPoint3 ZERO;
};
NiPoint3 __cdecl operator*(float, const NiPoint3&);
struct PointIterator
{
    const NiPoint3* points;
    unsigned int stride;
    unsigned int position;
};
struct BoundingSphere
{
};
// @fnv 0x00656dc0
void __cdecl ComputeBoundingSphere(BoundingSphere* sphere, PointIterator* points, int count)
{
    if (count <= 0)
    {
        reinterpret_cast<::fnv_0098ddd0::FUN_0098ddd0_shell *>((sphere))->FUN_0098ddd0((void *)&(::NiPoint3::ZERO));
        reinterpret_cast<::FUN_0063f790_shell *>((sphere))->FUN_0063f790(0.0f);
        return;
    }
    // Local spellings and scopes preserve the original MSVC9 stack layout.
    PointIterator second;    // Iterator for the radius pass.
    PointIterator i;         // Iterator for the coordinate-extrema pass.
    int center;              // Point index for both passes.
    NiPoint3 point;          // Bounding-sphere center.
    float first = 0.0f;      // Greatest squared distance from the center.
    NiPoint3 maximum;        // Minimum coordinate on each axis.
    NiPoint3 radiusSquared;  // Current point.
    reinterpret_cast<::FUN_00534570_shell *>((points))->FUN_00534570(0, maximum);
    {
        NiPoint3 minimum = maximum;  // Upper corner; maximum is the lower corner.
        i = *points;
        for (center = 1; center < count; ++center, reinterpret_cast<::FUN_00657be0_class *>(&(i))->AddToA())
        {
            reinterpret_cast<::FUN_00656fd0_shell *>(&(i))->CopyV3((::V3 *)(::NiPoint3 *)(&radiusSquared));
            if (maximum.x > radiusSquared.x)
                maximum.x = radiusSquared.x;
            if (maximum.y > radiusSquared.y)
                maximum.y = radiusSquared.y;
            if (maximum.z > radiusSquared.z)
                maximum.z = radiusSquared.z;
            if (minimum.x < radiusSquared.x)
                minimum.x = radiusSquared.x;
            if (minimum.y < radiusSquared.y)
                minimum.y = radiusSquared.y;
            if (minimum.z < radiusSquared.z)
                minimum.z = radiusSquared.z;
        }
        point = 0.5f * (maximum + minimum);
        second = *points;
        for (center = 0; center < count; ++center, reinterpret_cast<::FUN_00657be0_class *>(&(second))->AddToA())
        {
            reinterpret_cast<::FUN_00656fd0_shell *>(&(second))->CopyV3((::V3 *)(::NiPoint3 *)(&radiusSquared));
            float distanceSquared;
            {
                NiPoint3 delta = radiusSquared - point;
                distanceSquared = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(delta))->DotProduct((void *)&(delta));
            }
            if (distanceSquared > first)
                first = distanceSquared;
        }
        reinterpret_cast<::fnv_0098ddd0::FUN_0098ddd0_shell *>((sphere))->FUN_0098ddd0((void *)&(point));
        reinterpret_cast<::FUN_0063f790_shell *>((sphere))->FUN_0063f790(FUN_004579e0(first));
    }
}

struct TemporaryAllocator
{
    int value;
    TemporaryAllocator();
    TemporaryAllocator(const TemporaryAllocator&);
};
struct CoordinateArrayBase
{
    CoordinateArrayBase(TemporaryAllocator allocator);
    ~CoordinateArrayBase();
};
struct FUN_00657960 : CoordinateArrayBase
{
    FUN_00657960();
};
// Constructs the object with a default TemporaryAllocator and initializes it by calling ReserveEntries with 0.
// @fnv 0x00657960
FUN_00657960::FUN_00657960() : CoordinateArrayBase(TemporaryAllocator())
{
    reinterpret_cast<::FUN_00657cd0_cls *>(this)->ReserveEntries(0);
}

struct MxConstIter
{
    float* m_p0;
    void* m_p1;
    bool operator!=(const MxConstIter& o) const;
};
struct MxIter
{
    float* m_p0;
    void* m_p1;
    MxIter operator++(int);
    bool operator!=(const MxIter& o) const;
    float& operator*() const;
};

void __cdecl ReportAssertionViolation(const char* msg, int line);

struct FUN_006586c0_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    unsigned int m_rows;
    unsigned int m_cols;
    MxIter end();
    FUN_006586c0_cls* AddMatrix(FUN_006586c0_cls* other);
};
// @fnv 0x00652320
void __cdecl FUN_00652320(FG652_Mat* apMat, int aeAttr, int aeType, int aiIndex, float afValue)
{
    if (apMat && (unsigned int)aiIndex < ::FUN_00657a30((const ::_vec_60 *)&(((::FGMgr652 *)(::BSFaceGenManager::GetFaceGenManager()))->fans[aeAttr][aeType])))
    {
        float fOrig = GetMorphCoordinateValue(apMat, aeAttr, aeType, aiIndex);
        float fChange = afValue - fOrig;
        reinterpret_cast<::FUN_006586c0_cls *>(&(((FgMat652(*)[2])apMat)[aeAttr][aeType]))->AddMatrix(
            (::FUN_006586c0_cls *)&(const ::FgMat652 &)(((::FanCtl652 *)(reinterpret_cast<::FUN_00657a50_shell *>(&(((::FGMgr652 *)(::BSFaceGenManager::GetFaceGenManager()))->fans[aeAttr][aeType]))->FUN_00657a50(aiIndex)))->GetMatrix().Scaled(fChange)));
    }
}

// @fnv 0x006586c0
FUN_006586c0_cls* FUN_006586c0_cls::AddMatrix(FUN_006586c0_cls* other)
{
    if (m_rows == other->m_rows && m_cols == other->m_cols)
    {
    }
    else
    {
        ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x24f);
    }
    MxIter a = (*(::MxIter *)(reinterpret_cast<::_Dummy_0044a170 *>(this)->FUN_0044a170({})));
    MxConstIter b5 = (*(::MxConstIter *)(reinterpret_cast<::FUN_0065fd10_class *>((void *)(other))->FUN_0065fd10({})));
    for (; reinterpret_cast<::FUN_0065dfd0_class *>((void *)&(const ::MxIter &)(a))->FUN_0065dfd0((int)&(const ::MxIter &)((*(::MxIter *)(reinterpret_cast<::fnv_0065f550::FUN_0065f550_Class *>(this)->CallWithSelf({}))))) && reinterpret_cast<::FUN_0065dfd0_class *>((void *)&(const ::MxConstIter &)(b5))->FUN_0065dfd0((int)&(const ::MxConstIter &)((*(::MxConstIter *)(reinterpret_cast<::fnv_0065fd40::FUN_0065fd40_class *>((void *)(other))->FUN_0065fd40({}))))); a++, (*(::MxConstIter *)(reinterpret_cast<::FG_00659100_cls *>(&(b5))->FUN_00659100((::FG_00659100_pair *)(0), {}))))
    {
        reinterpret_cast<::FUN_0064dbd0_Class *>((void *)&(const ::MxIter &)(a))->FUN_0064dbd0() += double(((const float)(reinterpret_cast<::FUN_0064dda0_cls *>((void *)&(b5))->FUN_0064dda0())));
    }
    return this;
}

struct S_0065da80_bounds
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct S_0044ac20_class
{
};

unsigned int FUN_00ec7c56();

// @fnv 0x0065da80
int FUN_0065e000_class::FUN_0065da80(int value, int pBounds)
{
    reinterpret_cast<::FUN_0064de50_class *>((this))->FUN_0064de50();

    if (pBounds == 0 || reinterpret_cast<S_0065da80_bounds*>(pBounds)->unk0c > static_cast<unsigned int>(value) ||
        static_cast<unsigned int>(value) >
            static_cast<unsigned int>(reinterpret_cast<S_0065da80_bounds*>(pBounds)->unk10))
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (0);

    reinterpret_cast<::FUN_0044ac20_class *>((reinterpret_cast<S_0044ac20_class*>(this)))->FUN_0044ac20((const int *)(pBounds));

    reinterpret_cast<int*>(this)[1] = value;

    return reinterpret_cast<int>(this);
}

class CoordArray : public FaceGenCoordArray
{
  public:
    void FUN_006581e0(CoordArray*);
    float FUN_006588a0();
};

void FUN_006529a0(CoordArray a1[2][2], CoordArray a2[2][2], int a3, int a4);

// For each of the 2x2 CoordArray slots, combines a1 and a2 into a3 (or copies one source), optionally scaling the result when a5 is exceeded.
// @fnv 0x00652af0
void FUN_00652af0(CoordArray a1[2][2], CoordArray a2[2][2], CoordArray a3[2][2], bool a4, float a5)
{
    if (!a3 || (!a1 && !a2))
        return;

    if (!a1)
    {
        FUN_006529a0(a2, a3, 0, 0);
        return;
    }
    else if (!a2)
    {
        FUN_006529a0(a1, a3, 0, 0);
        return;
    }

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            unsigned int var_c = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>(&(a1[i][j]))->FUN_009611e0()));
            unsigned int var_10 = reinterpret_cast<::BGSTerrainManager *>(&(a1[i][j]))->GetMinLevel();
            if (var_c != 0 && var_10 != 0)
            {
                reinterpret_cast<::FR2MatrixVTCData *>(&(a3[i][j]))->SetDimensions(var_c, var_10);
                if (i == 1 && a4)
                {
                    a3[i][j].FUN_006581e0(&a1[i][j]);
                    if (a5 > 0.0)
                    {
                        float var_14 = FUN_004019b0(a3[i][j].FUN_006588a0() / (float)var_c);
                        if (var_14 > a5)
                        {
                            reinterpret_cast<::Mgr *>(&(a3[i][j]))->ScaleAll(a5 / var_14);
                        }
                    }
                }
                else
                {
                    unsigned int var_18 = var_c * var_10;
                    reinterpret_cast<::VecStandIn *>(&(a3[i][j]))->FUN_0044a0a0();
                    for (unsigned int k = 0; k < var_18; ++k)
                    {
                        float sum = *((float *)(reinterpret_cast<::V_006578b0 *>(&(a1[i][j]))->FUN_006578b0(k)));
                        float var_28 = *((float *)(reinterpret_cast<::V_006578b0 *>(&(a2[i][j]))->FUN_006578b0(k)));
                        reinterpret_cast<::FloatVec *>(&(a3[i][j]))->PushBack(sum + var_28);
                    }
                    if (a5 > 0.0)
                    {
                        float f2 = FUN_004019b0(a3[i][j].FUN_006588a0() / (float)var_c);
                        if (f2 > a5)
                        {
                            reinterpret_cast<::Mgr *>(&(a3[i][j]))->ScaleAll(a5 / f2);
                        }
                    }
                }
            }
            else
            {
                reinterpret_cast<::FR2MatrixVTCData *>(&(a3[i][j]))->SetDimensions(0, 0);
            }
        }
    }
}

struct FaceGenCoordinateValue
{
    float* m_pfValues;
    unsigned int m_uiCount;
    FaceGenCoordinateValue(const FaceGenCoordinateValue&);
};

struct FaceGenCoordinateBasis
{
    void* m_pResource;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiStride;
    ~FaceGenCoordinateBasis();
    FaceGenCoordinateValue FUN_0060b370(unsigned int uiIndex);
};

struct FaceGenMorph
{
    FaceGenCoordinateBasis FUN_00658360(char* pcCoords);
};

struct FaceGenMorphArray
{
    int unk00;
    int unk04;
    int unk08;
    FaceGenMorph* m_pBegin;
    FaceGenMorph* m_pRecordEnd;
    int unk14;
};

struct FaceGenModelData
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    FaceGenMorphArray m_aakMorphs[2][2];
};


// Returns the first coordinate value of a morph at uiIndex for the given pcCoords, or 0.0f if out of range or pcCoords is null.
// @fnv 0x00652230
float GetMorphCoordinateValue(char* pcCoords, unsigned int uiRenderPassIndex, unsigned int uiSub, unsigned int uiIndex)
{
    float fValue = 0.0f;
    if (pcCoords)
    {
        if (uiIndex < ::FUN_00657a30((const ::_vec_60 *)&(((::FaceGenModelData *)(::BSFaceGenManager::GetFaceGenManager()))->m_aakMorphs[uiRenderPassIndex][uiSub])))
        {
            fValue = reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)((*(::FaceGenMorph *)(reinterpret_cast<::FUN_00657a50_shell *>(&(((::FaceGenModelData *)(::BSFaceGenManager::GetFaceGenManager()))
                         ->m_aakMorphs[uiRenderPassIndex][uiSub]))->FUN_00657a50(uiIndex)))
                         .FUN_00658360(pcCoords + uiRenderPassIndex * 0x40 + uiSub * 0x20)
                         .FUN_0060b370(0)))->FUN_00629ab0(0);
        }
    }
    return fValue;
}

// 0x00651b50 - BSFaceGenManager.cpp helper


// Looks up a Sol face-gen model in the BSFaceGenManager cache by a1 or a4, creating and caching a new one via FUN_00659c70 when a5 is true and no entry exists.
// @fnv 0x00651b50
Sol* GetOrCreateFaceGenModel(char* a1, char* a2, char* a3, char* a4, bool abCreateIfMissing, int a6, bool a7)
{
    AutoMemContext mem(0x37, true,
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0x3e5);
    SolPtr ref(0);

    if (a1 == 0 && a4 == 0)
        return 0;

    if (BSFaceGenManager::GetFaceGenManager()->cache == 0)
    {
        BSFaceGenManager::GetFaceGenManager()->cache = new BSFaceGenModelMap;
        reinterpret_cast<::FUN_006508e0_shell *>((BSFaceGenManager::GetFaceGenManager()->cache))->SetArrayValue(0, (int)(((char *)(reinterpret_cast<::TESObjectCELL *>(&((*reinterpret_cast<::GO45CFE0 *>(&::g_011d59f4))))->GetCellStandValue()))));
        reinterpret_cast<::FUN_006508e0_shell *>((BSFaceGenManager::GetFaceGenManager()->cache))->SetArrayValue(1, (int)(((char *)(reinterpret_cast<::TESObjectCELL *>(&((*reinterpret_cast<::GO45CFE0 *>(&::g_011d5afc))))->GetCellStandValue()))));
    }

    if (a1)
    {
        if (reinterpret_cast<::FGModelCache *>((BSFaceGenManager::GetFaceGenManager()->cache))->FUN_00650200(a1, (::Helper62d0 *)(::SolPtr *)(&ref)))
        {
            if (a4)
            {
                if (!((unsigned int)(::FUN_00650600((char *)(((::Sol *)(::FUN_00559450((int *)&(ref)))))))))
                    reinterpret_cast<::BSFaceGenModel *>((((::Sol *)(::FUN_00559450((int *)&(ref))))))->LoadFaceGenTexture((const char *)(a4));
            }
            return ((::Sol *)(::FUN_00559450((int *)&(ref))));
        }
    }
    else if (a4)
    {
        if (reinterpret_cast<::FGModelCache *>((BSFaceGenManager::GetFaceGenManager()->cache))->FUN_00650200(a4, (::Helper62d0 *)(::SolPtr *)(&ref)))
            return ((::Sol *)(::FUN_00559450((int *)&(ref))));
    }

    if (abCreateIfMissing)
    {
        ref = new Sol;
        if (reinterpret_cast<::FUN_00659c70_shell *>((((::Sol *)(::FUN_00559450((int *)&(ref))))))->FUN_00659c70(a1, a2, a3, a4, a6, a7))
        {
            reinterpret_cast<::fnv_0064ffd0::FGModelCache *>((BSFaceGenManager::GetFaceGenManager()->cache))->FUN_0064ffd0((const char *)(a1 ? a1 : a4), ((::Sol *)(::FUN_00559450((int *)&(ref)))));
        }
        else
        {
            ref = 0;
        }
    }

    return ((::Sol *)(::FUN_00559450((int *)&(ref))));
}

struct FUN_00659190_class
{
    void* unk00;
    unsigned int unk04;


    FUN_00659190_class* FUN_00659190();
};

// Calls two checks, increments a field by 4, and returns this.
// @fnv 0x00659190
FUN_00659190_class* FUN_00659190_class::FUN_00659190()
{
    if (!reinterpret_cast<::FUN_005ca4f0_shell *>(this)->FUN_005ca4f0())
        FUN_00ec7c56();

    do
    {
    } while (0);

    if (unk04 >= *reinterpret_cast<unsigned int*>(((unsigned char *)(reinterpret_cast<::S_0060b980 *>(this)->FUN_0060b980())) + 0x10))
        FUN_00ec7c56();

    do
    {
    } while (0);

    unk04 += 4;
    return this;
}

namespace fnv_006518e0 {
void FUN_00651e30();
struct Cache
{
    virtual ~Cache();
};
struct Base
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    ~Base();
};
struct Coordinates
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    ~Coordinates();
};
struct Data
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int unk02b4;
    unsigned int unk02b8;
    unsigned int unk02bc;
    unsigned int unk02c0;
    unsigned int unk02c4;
    unsigned int unk02c8;
    unsigned int unk02cc;
    unsigned int unk02d0;
    unsigned int unk02d4;
    unsigned int unk02d8;
    unsigned int unk02dc;
    unsigned int unk02e0;
    unsigned int unk02e4;
    unsigned int unk02e8;
    unsigned int unk02ec;
    unsigned int unk02f0;
    unsigned int unk02f4;
    unsigned int unk02f8;
    unsigned int unk02fc;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030c;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031c;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032c;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033c;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034c;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035c;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036c;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037c;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038c;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039c;
    unsigned int unk03a0;
    unsigned int unk03a4;
    unsigned int unk03a8;
    unsigned int unk03ac;
    unsigned int unk03b0;
    unsigned int unk03b4;
    unsigned int unk03b8;
    unsigned int unk03bc;
    unsigned int unk03c0;
    unsigned int unk03c4;
    unsigned int unk03c8;
    unsigned int unk03cc;
    unsigned int unk03d0;
    unsigned int unk03d4;
    unsigned int unk03d8;
    unsigned int unk03dc;
    unsigned int unk03e0;
    unsigned int unk03e4;
    unsigned int unk03e8;
    unsigned int unk03ec;
    unsigned int unk03f0;
    unsigned int unk03f4;
    unsigned int unk03f8;
    unsigned int unk03fc;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040c;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041c;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042c;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043c;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044c;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045c;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046c;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047c;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048c;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049c;
    unsigned int unk04a0;
    unsigned int unk04a4;
    unsigned int unk04a8;
    unsigned int unk04ac;
    unsigned int unk04b0;
    unsigned int unk04b4;
    unsigned int unk04b8;
    unsigned int unk04bc;
    unsigned int unk04c0;
    unsigned int unk04c4;
    unsigned int unk04c8;
    unsigned int unk04cc;
    unsigned int unk04d0;
    unsigned int unk04d4;
    unsigned int unk04d8;
    unsigned int unk04dc;
    unsigned int unk04e0;
    unsigned int unk04e4;
    unsigned int unk04e8;
    unsigned int unk04ec;
    unsigned int unk04f0;
    unsigned int unk04f4;
    unsigned int unk04f8;
    unsigned int unk04fc;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050c;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051c;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052c;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053c;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054c;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055c;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056c;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057c;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058c;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059c;
    unsigned int unk05a0;
    unsigned int unk05a4;
    unsigned int unk05a8;
    unsigned int unk05ac;
    unsigned int unk05b0;
    unsigned int unk05b4;
    unsigned int unk05b8;
    unsigned int unk05bc;
    unsigned int unk05c0;
    unsigned int unk05c4;
    unsigned int unk05c8;
    unsigned int unk05cc;
    unsigned int unk05d0;
    unsigned int unk05d4;
    unsigned int unk05d8;
    unsigned int unk05dc;
    unsigned int unk05e0;
    unsigned int unk05e4;
    unsigned int unk05e8;
    unsigned int unk05ec;
    unsigned int unk05f0;
    unsigned int unk05f4;
    unsigned int unk05f8;
    unsigned int unk05fc;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060c;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061c;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062c;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063c;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064c;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065c;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066c;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067c;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068c;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069c;
    unsigned int unk06a0;
    unsigned int unk06a4;
    unsigned int unk06a8;
    unsigned int unk06ac;
    unsigned int unk06b0;
    unsigned int unk06b4;
    unsigned int unk06b8;
    unsigned int unk06bc;
    unsigned int unk06c0;
    unsigned int unk06c4;
    unsigned int unk06c8;
    unsigned int unk06cc;
    unsigned int unk06d0;
    unsigned int unk06d4;
    unsigned int unk06d8;
    unsigned int unk06dc;
    unsigned int unk06e0;
    unsigned int unk06e4;
    unsigned int unk06e8;
    unsigned int unk06ec;
    unsigned int unk06f0;
    unsigned int unk06f4;
    unsigned int unk06f8;
    unsigned int unk06fc;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070c;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071c;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072c;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073c;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074c;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075c;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076c;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077c;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078c;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079c;
    unsigned int unk07a0;
    unsigned int unk07a4;
    unsigned int unk07a8;
    unsigned int unk07ac;
    unsigned int unk07b0;
    unsigned int unk07b4;
    unsigned int unk07b8;
    unsigned int unk07bc;
    unsigned int unk07c0;
    unsigned int unk07c4;
    unsigned int unk07c8;
    unsigned int unk07cc;
    unsigned int unk07d0;
    unsigned int unk07d4;
    unsigned int unk07d8;
    unsigned int unk07dc;
    unsigned int unk07e0;
    unsigned int unk07e4;
    unsigned int unk07e8;
    unsigned int unk07ec;
    unsigned int unk07f0;
    unsigned int unk07f4;
    unsigned int unk07f8;
    unsigned int unk07fc;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080c;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081c;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082c;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083c;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084c;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085c;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086c;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087c;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088c;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089c;
    unsigned int unk08a0;
    unsigned int unk08a4;
    unsigned int unk08a8;
    unsigned int unk08ac;
    unsigned int unk08b0;
    unsigned int unk08b4;
    unsigned int unk08b8;
    unsigned int unk08bc;
    unsigned int unk08c0;
    unsigned int unk08c4;
    unsigned int unk08c8;
    unsigned int unk08cc;
    unsigned int unk08d0;
    unsigned int unk08d4;
    unsigned int unk08d8;
    unsigned int unk08dc;
    unsigned int unk08e0;
    unsigned int unk08e4;
    unsigned int unk08e8;
    unsigned int unk08ec;
    unsigned int unk08f0;
    unsigned int unk08f4;
    unsigned int unk08f8;
    unsigned int unk08fc;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090c;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091c;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092c;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093c;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094c;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095c;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096c;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097c;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098c;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099c;
    unsigned int unk09a0;
    unsigned int unk09a4;
    unsigned int unk09a8;
    unsigned int unk09ac;
    unsigned int unk09b0;
    unsigned int unk09b4;
    unsigned int unk09b8;
    unsigned int unk09bc;
    unsigned int unk09c0;
    unsigned int unk09c4;
    unsigned int unk09c8;
    unsigned int unk09cc;
    unsigned int unk09d0;
    unsigned int unk09d4;
    unsigned int unk09d8;
    unsigned int unk09dc;
    unsigned int unk09e0;
    unsigned int unk09e4;
    unsigned int unk09e8;
    unsigned int unk09ec;
    unsigned int unk09f0;
    unsigned int unk09f4;
    unsigned int unk09f8;
    unsigned int unk09fc;
    unsigned int unk0a00;
    unsigned int unk0a04;
    unsigned int unk0a08;
    unsigned int unk0a0c;
    unsigned int unk0a10;
    unsigned int unk0a14;
    unsigned int unk0a18;
    unsigned int unk0a1c;
    unsigned int unk0a20;
    unsigned int unk0a24;
    unsigned int unk0a28;
    unsigned int unk0a2c;
    unsigned int unk0a30;
    unsigned int unk0a34;
    unsigned int unk0a38;
    unsigned int unk0a3c;
    unsigned int unk0a40;
    unsigned int unk0a44;
    unsigned int unk0a48;
    unsigned int unk0a4c;
    unsigned int unk0a50;
    unsigned int unk0a54;
    unsigned int unk0a58;
    unsigned int unk0a5c;
    unsigned int unk0a60;
    unsigned int unk0a64;
    unsigned int unk0a68;
    unsigned int unk0a6c;
    unsigned int unk0a70;
    unsigned int unk0a74;
    unsigned int unk0a78;
    unsigned int unk0a7c;
    unsigned int unk0a80;
    unsigned int unk0a84;
    unsigned int unk0a88;
    unsigned int unk0a8c;
    unsigned int unk0a90;
    unsigned int unk0a94;
    unsigned int unk0a98;
    unsigned int unk0a9c;
    unsigned int unk0aa0;
    unsigned int unk0aa4;
    unsigned int unk0aa8;
    unsigned int unk0aac;
    unsigned int unk0ab0;
    unsigned int unk0ab4;
    unsigned int unk0ab8;
    unsigned int unk0abc;
    unsigned int unk0ac0;
    unsigned int unk0ac4;
    unsigned int unk0ac8;
    unsigned int unk0acc;
    unsigned int unk0ad0;
    unsigned int unk0ad4;
    unsigned int unk0ad8;
    unsigned int unk0adc;
    unsigned int unk0ae0;
    unsigned int unk0ae4;
    unsigned int unk0ae8;
    unsigned int unk0aec;
    unsigned int unk0af0;
    unsigned int unk0af4;
    unsigned int unk0af8;
    unsigned int unk0afc;
    unsigned int unk0b00;
    unsigned int unk0b04;
    unsigned int unk0b08;
    unsigned int unk0b0c;
    unsigned int unk0b10;
    unsigned int unk0b14;
    unsigned int unk0b18;
    unsigned int unk0b1c;
    unsigned int unk0b20;
    unsigned int unk0b24;
    unsigned int unk0b28;
    unsigned int unk0b2c;
    unsigned int unk0b30;
    unsigned int unk0b34;
    unsigned int unk0b38;
    unsigned int unk0b3c;
    unsigned int unk0b40;
    unsigned int unk0b44;
    unsigned int unk0b48;
    unsigned int unk0b4c;
    unsigned int unk0b50;
    unsigned int unk0b54;
    unsigned int unk0b58;
    unsigned int unk0b5c;
    unsigned int unk0b60;
    unsigned int unk0b64;
    unsigned int unk0b68;
    unsigned int unk0b6c;
    unsigned int unk0b70;
    unsigned int unk0b74;
    unsigned int unk0b78;
    unsigned int unk0b7c;
    unsigned int unk0b80;
    unsigned int unk0b84;
    unsigned int unk0b88;
    unsigned int unk0b8c;
    unsigned int unk0b90;
    unsigned int unk0b94;
    unsigned int unk0b98;
    unsigned int unk0b9c;
    unsigned int unk0ba0;
    unsigned int unk0ba4;
    unsigned int unk0ba8;
    unsigned int unk0bac;
    unsigned int unk0bb0;
    unsigned int unk0bb4;
    unsigned int unk0bb8;
    unsigned int unk0bbc;
    unsigned int unk0bc0;
    unsigned int unk0bc4;
    unsigned int unk0bc8;
    unsigned int unk0bcc;
    unsigned int unk0bd0;
    unsigned int unk0bd4;
    unsigned int unk0bd8;
    unsigned int unk0bdc;
    unsigned int unk0be0;
    unsigned int unk0be4;
    unsigned int unk0be8;
    unsigned int unk0bec;
    unsigned int unk0bf0;
    unsigned int unk0bf4;
    unsigned int unk0bf8;
    unsigned int unk0bfc;
    unsigned int unk0c00;
    unsigned int unk0c04;
    unsigned int unk0c08;
    unsigned int unk0c0c;
    unsigned int unk0c10;
    unsigned int unk0c14;
    unsigned int unk0c18;
    unsigned int unk0c1c;
    unsigned int unk0c20;
    unsigned int unk0c24;
    unsigned int unk0c28;
    unsigned int unk0c2c;
    unsigned int unk0c30;
    unsigned int unk0c34;
    unsigned int unk0c38;
    unsigned int unk0c3c;
    unsigned int unk0c40;
    unsigned int unk0c44;
    unsigned int unk0c48;
    unsigned int unk0c4c;
    unsigned int unk0c50;
    unsigned int unk0c54;
    unsigned int unk0c58;
    unsigned int unk0c5c;
    unsigned int unk0c60;
    unsigned int unk0c64;
    unsigned int unk0c68;
    unsigned int unk0c6c;
    unsigned int unk0c70;
    unsigned int unk0c74;
    unsigned int unk0c78;
    unsigned int unk0c7c;
    unsigned int unk0c80;
    unsigned int unk0c84;
    unsigned int unk0c88;
    unsigned int unk0c8c;
    unsigned int unk0c90;
    unsigned int unk0c94;
    unsigned int unk0c98;
    unsigned int unk0c9c;
    unsigned int unk0ca0;
    unsigned int unk0ca4;
    unsigned int unk0ca8;
    unsigned int unk0cac;
    unsigned int unk0cb0;
    unsigned int unk0cb4;
    unsigned int unk0cb8;
    unsigned int unk0cbc;
    unsigned int unk0cc0;
    unsigned int unk0cc4;
    unsigned int unk0cc8;
    unsigned int unk0ccc;
    unsigned int unk0cd0;
    unsigned int unk0cd4;
    unsigned int unk0cd8;
    unsigned int unk0cdc;
    unsigned int unk0ce0;
    unsigned int unk0ce4;
    unsigned int unk0ce8;
    unsigned int unk0cec;
    unsigned int unk0cf0;
    unsigned int unk0cf4;
    unsigned int unk0cf8;
    unsigned int unk0cfc;
    unsigned int unk0d00;
    unsigned int unk0d04;
    unsigned int unk0d08;
    unsigned int unk0d0c;
    unsigned int unk0d10;
    unsigned int unk0d14;
    unsigned int unk0d18;
    unsigned int unk0d1c;
    unsigned int unk0d20;
    unsigned int unk0d24;
    unsigned int unk0d28;
    unsigned int unk0d2c;
    unsigned int unk0d30;
    unsigned int unk0d34;
    unsigned int unk0d38;
    unsigned int unk0d3c;
    unsigned int unk0d40;
    unsigned int unk0d44;
    unsigned int unk0d48;
    unsigned int unk0d4c;
    unsigned int unk0d50;
    unsigned int unk0d54;
    unsigned int unk0d58;
    unsigned int unk0d5c;
    unsigned int unk0d60;
    unsigned int unk0d64;
    unsigned int unk0d68;
    unsigned int unk0d6c;
    unsigned int unk0d70;
    unsigned int unk0d74;
    unsigned int unk0d78;
    unsigned int unk0d7c;
    unsigned int unk0d80;
    unsigned int unk0d84;
    unsigned int unk0d88;
    unsigned int unk0d8c;
    unsigned int unk0d90;
    unsigned int unk0d94;
    unsigned int unk0d98;
    unsigned int unk0d9c;
    unsigned int unk0da0;
    unsigned int unk0da4;
    unsigned int unk0da8;
    unsigned int unk0dac;
    unsigned int unk0db0;
    unsigned int unk0db4;
    unsigned int unk0db8;
    unsigned int unk0dbc;
    unsigned int unk0dc0;
    unsigned int unk0dc4;
    unsigned int unk0dc8;
    unsigned int unk0dcc;
    unsigned int unk0dd0;
    unsigned int unk0dd4;
    unsigned int unk0dd8;
    unsigned int unk0ddc;
    unsigned int unk0de0;
    unsigned int unk0de4;
    unsigned int unk0de8;
    unsigned int unk0dec;
    unsigned int unk0df0;
    unsigned int unk0df4;
    unsigned int unk0df8;
    unsigned int unk0dfc;
    unsigned int unk0e00;
    unsigned int unk0e04;
    unsigned int unk0e08;
    unsigned int unk0e0c;
    unsigned int unk0e10;
    unsigned int unk0e14;
    unsigned int unk0e18;
    unsigned int unk0e1c;
    unsigned int unk0e20;
    unsigned int unk0e24;
    unsigned int unk0e28;
    unsigned int unk0e2c;
    unsigned int unk0e30;
    unsigned int unk0e34;
    unsigned int unk0e38;
    unsigned int unk0e3c;
    unsigned int unk0e40;
    unsigned int unk0e44;
    unsigned int unk0e48;
    unsigned int unk0e4c;
    unsigned int unk0e50;
    unsigned int unk0e54;
    unsigned int unk0e58;
    unsigned int unk0e5c;
    unsigned int unk0e60;
    unsigned int unk0e64;
    unsigned int unk0e68;
    unsigned int unk0e6c;
    unsigned int unk0e70;
    unsigned int unk0e74;
    unsigned int unk0e78;
    unsigned int unk0e7c;
    unsigned int unk0e80;
    unsigned int unk0e84;
    unsigned int unk0e88;
    unsigned int unk0e8c;
    unsigned int unk0e90;
    unsigned int unk0e94;
    unsigned int unk0e98;
    unsigned int unk0e9c;
    unsigned int unk0ea0;
    unsigned int unk0ea4;
    unsigned int unk0ea8;
    unsigned int unk0eac;
    unsigned int unk0eb0;
    unsigned int unk0eb4;
    unsigned int unk0eb8;
    unsigned int unk0ebc;
    unsigned int unk0ec0;
    unsigned int unk0ec4;
    unsigned int unk0ec8;
    unsigned int unk0ecc;
    unsigned int unk0ed0;
    unsigned int unk0ed4;
    unsigned int unk0ed8;
    unsigned int unk0edc;
    unsigned int unk0ee0;
    unsigned int unk0ee4;
    unsigned int unk0ee8;
    unsigned int unk0eec;
    unsigned int unk0ef0;
    unsigned int unk0ef4;
    unsigned int unk0ef8;
    unsigned int unk0efc;
    unsigned int unk0f00;
    unsigned int unk0f04;
    unsigned int unk0f08;
    unsigned int unk0f0c;
    unsigned int unk0f10;
    unsigned int unk0f14;
    unsigned int unk0f18;
    unsigned int unk0f1c;
    unsigned int unk0f20;
    unsigned int unk0f24;
    unsigned int unk0f28;
    unsigned int unk0f2c;
    unsigned int unk0f30;
    unsigned int unk0f34;
    unsigned int unk0f38;
    unsigned int unk0f3c;
    unsigned int unk0f40;
    unsigned int unk0f44;
    unsigned int unk0f48;
    unsigned int unk0f4c;
    unsigned int unk0f50;
    unsigned int unk0f54;
    unsigned int unk0f58;
    unsigned int unk0f5c;
    unsigned int unk0f60;
    unsigned int unk0f64;
    unsigned int unk0f68;
    unsigned int unk0f6c;
    unsigned int unk0f70;
    unsigned int unk0f74;
    unsigned int unk0f78;
    unsigned int unk0f7c;
    unsigned int unk0f80;
    unsigned int unk0f84;
    unsigned int unk0f88;
    unsigned int unk0f8c;
    unsigned int unk0f90;
    unsigned int unk0f94;
    unsigned int unk0f98;
    unsigned int unk0f9c;
    unsigned int unk0fa0;
    unsigned int unk0fa4;
    unsigned int unk0fa8;
    unsigned int unk0fac;
    unsigned int unk0fb0;
    unsigned int unk0fb4;
    unsigned int unk0fb8;
    unsigned int unk0fbc;
    unsigned int unk0fc0;
    unsigned int unk0fc4;
    unsigned int unk0fc8;
    unsigned int unk0fcc;
    unsigned int unk0fd0;
    unsigned int unk0fd4;
    unsigned int unk0fd8;
    unsigned int unk0fdc;
    unsigned int unk0fe0;
    unsigned int unk0fe4;
    unsigned int unk0fe8;
    unsigned int unk0fec;
    unsigned int unk0ff0;
    unsigned int unk0ff4;
    unsigned int unk0ff8;
    unsigned int unk0ffc;
    unsigned int unk1000;
    unsigned int unk1004;
    unsigned int unk1008;
    unsigned int unk100c;
    unsigned int unk1010;
    unsigned int unk1014;
    unsigned int unk1018;
    unsigned int unk101c;
    unsigned int unk1020;
    unsigned int unk1024;
    unsigned int unk1028;
    unsigned int unk102c;
    unsigned int unk1030;
    unsigned int unk1034;
    unsigned int unk1038;
    unsigned int unk103c;
    unsigned int unk1040;
    unsigned int unk1044;
    unsigned int unk1048;
    unsigned int unk104c;
    unsigned int unk1050;
    unsigned int unk1054;
    unsigned int unk1058;
    unsigned int unk105c;
    unsigned int unk1060;
    unsigned int unk1064;
    unsigned int unk1068;
    unsigned int unk106c;
    unsigned int unk1070;
    unsigned int unk1074;
    unsigned int unk1078;
    ~Data();
};
struct Ptr
{
    void* object;
    ~Ptr();
};
struct FUN_006518e0 : Base
{
    Coordinates coords;
    Data data;
    Cache* cache;
    Ptr p1198, p119c, p11a0;
    ~FUN_006518e0();
};
// Destroys the object, purging unused models from the cache before deleting it and nulling the pointer.
// @fnv 0x006518e0
FUN_006518e0::~FUN_006518e0()
{
    FUN_00651e30();
    if (cache)
        reinterpret_cast<::FaceGenModelCache650 *>((cache))->PurgeUnusedModels(false);
    delete cache;
    cache = 0;
}
}  // namespace fnv_006518e0
