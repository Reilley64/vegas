// gamebryo2.2/corelibs/nianimation/niinterpolator.cpp: NiInterpolator, NiKeyBasedInterpolator (8 functions)

#include <new>
#include "fnv/decl/A5D6E0This.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011f4000.h"
#include "niinterpolator_decls.h"

// @fnv 0x00a56ff0
NiInterpolator::NiInterpolator() : m_fLastTime(::DAT_01015f5c)
{
    m_pVTable = NiInterpolator_VTable;
}

struct BSBlendTreadTransfInterpolator;
class NiBlendInterpolator;
struct CloningProcess;
struct NiObjectNET;
struct NiQuatTransform;
struct NiStream;
struct FUN_00a57030_shell : public NiInterpolator
{
    void GetKeyTimeRange(float*, float*);
};

// @fnv 0x00a57030
void FUN_00a57030_shell::GetKeyTimeRange(float* fBeginKeyTime, float* fEndKeyTime)
{
    *fBeginKeyTime = 0.0f;
    *fEndKeyTime = 0.0f;
}


// @fnv 0x00a57070
const char* const* __cdecl FUN_00a57070()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f4200));
}

class NiRefObject
{
  public:
    virtual ~NiRefObject();
};
extern void* NiInterpolator_VTable[];
struct NiKeyBasedInterpolator : public NiRefObject
{
    void FUN_00a57010();
};
// @fnv 0x00a57010
void NiKeyBasedInterpolator::FUN_00a57010()
{
    *reinterpret_cast<void**>(this) = NiInterpolator_VTable;
    reinterpret_cast<class ::FUN_00a5d3d0 *>(this)->FUN_00a5d3d0::~FUN_00a5d3d0();
}

template <class T> class NiTMallocInterface
{
};
template <class T, class A> class NiTPrimitiveArray
{
  public:
    char _0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    char _1[2];
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
// Appends the string returned by _FUN_00a7d330(g_011f36fc_arg1) to pkStrings, growing the array when full.
// @fnv 0x00a570b0
void FUN_00a570b0(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >* pkStrings)
{
    reinterpret_cast<::A5D6E0This *>((pkStrings))->AppendCameraPathEntries({});
    char* pcString = ::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f4200)));
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMaxSize = pkStrings->m_usMaxSize;
    if (uiSize >= uiMaxSize)
    {
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(uiSize + pkStrings->m_usGrowBy);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(uiSize, pcString);
}

// Reconstructed: 26-byte stdcall wrapper that grabs an object from a
// factory-like helper and calls one virtual on it (vtable slot 0xD0).
class NiAnimTarget
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
};


// @fnv 0x00a57050
NiAnimTarget* FUN_00a57050(int a, int b)
{
    NiAnimTarget* p = (NiAnimTarget*)((void *)(static_cast<::CloneSourceA5d6 *>(nullptr)->FUN_00a5d680()));
    p->v52();
    return p;
}

// @fnv 0x00a57020
char FUN_00a57020(int a, int b, int c)
{
    return 0;
}

struct FUN_00a57080_Owner
{
    void* Destroy(unsigned int);
};
// Sets the vtable to NiInterpolator, calls the NiRefObject destructor, and frees the object when a1 has bit 0 set.
// @fnv 0x00a57080
void* FUN_00a57080_Owner::Destroy(unsigned int auiFlags)
{
    *(void**)this = (void*)NiInterpolator_VTable;
    reinterpret_cast<class ::FUN_00a5d3d0 *>((((NiRefObject*)this)))->FUN_00a5d3d0::~FUN_00a5d3d0();
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0xc);
    return this;
}
