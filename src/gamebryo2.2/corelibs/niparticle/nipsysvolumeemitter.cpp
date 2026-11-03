// gamebryo2.2/corelibs/niparticle/nipsysvolumeemitter.cpp: NiPSysVolumeEmitter (10 functions)

#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00c226a0_cls.h"
#include "fnv/decl/FUN_00c22780_shell.h"
#include "fnv/decl/NiPSysBoundUpdateModifier.h"
#include "fnv/decl/PositionState.h"
#include "fnv/decl/S_00c22530_Emitter.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01202000.h"
#include "nipsysvolumeemitter_match_types.h"

// @fnv 0x00c31b20
void NiPSysVolumeEmitter::LoadBinary(NiStream& stream)
{
    NiPSysEmitter::LoadBinary(stream);
    reinterpret_cast<::FUN_00a645b0_cls *>(&(stream))->FUN_00a645b0();
}

// @fnv 0x00c31b40
void NiPSysVolumeEmitter::LinkObject(NiStream& stream)
{
    reinterpret_cast<::NiPSysBoundUpdateModifier *>(this)->LinkObject(stream);
    m_pkEmitterObject = (NiAVObject*)stream.GetLoadedObject();
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
struct FUN_00c31c90_shell : public NiPSysVolumeEmitter
{
    void FUN_00c31c90(CloningProcess*);
};

class ShaderBufferRecord;
template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char*, T&);
};

struct NiPSysModifier_Fake : public NiPSysModifier
{
    void ProcessClone(CloningProcess&);
};

static inline void CallBaseProcessClone(NiPSysModifier* pThis, CloningProcess& kCloning)
{
    void (NiPSysModifier::*fn)(CloningProcess&) =
        (void(NiPSysModifier::*)(CloningProcess&)) & NiPSysModifier_Fake::ProcessClone;
    (pThis->*fn)(kCloning);
}

// @fnv 0x00c31c90
void FUN_00c31c90_shell::FUN_00c31c90(CloningProcess* kCloning)
{
    CallBaseProcessClone(this, *kCloning);
    NiObject* pkClone = 0;
    reinterpret_cast<::A54440Hash *>((((NiTStringPointerMap<ShaderBufferRecord*>*)kCloning->m_pCloneMap)))->FUN_00a53c30((::A54440Manager *)((const char*)this), (::A54440Manager **)&((ShaderBufferRecord*&)pkClone));
    NiPSysVolumeEmitter* pkDest = (NiPSysVolumeEmitter*)pkClone;
    if (m_pkEmitterObject)
    {
        if (reinterpret_cast<::A54440Hash *>((((NiTStringPointerMap<ShaderBufferRecord*>*)kCloning->m_pCloneMap)))->FUN_00a53c30((::A54440Manager *)((const char*)m_pkEmitterObject), (::A54440Manager **)&((ShaderBufferRecord*&)pkClone)))
        {
            pkDest->m_pkEmitterObject = (NiAVObject*)pkClone;
        }
        else
        {
            pkDest->m_pkEmitterObject = m_pkEmitterObject;
        }
    }
}

struct BSPSysArrayEmitter;
struct NiAVObject;
struct CloningProcess;
struct NiTransform;
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
struct FUN_00c31cf0_shell : public NiPSysVolumeEmitter
{
    void ComputeEmitterInitialPositionAndVelocity(NiPoint3*, NiPoint3*);
};

struct NiTransform
{
    int m_data[13];
    void CalculateInverse(NiTransform&);
    NiTransform operator*(NiTransform const&) const;
    void ResetToIdentity(void);
};

typedef void(* ComputeVolumeInitialPositionAndVelocity_t)(void*, NiTransform&, NiPoint3*, NiPoint3*);

// Builds the emitter-to-PSys transform from the emitter and target transforms (or identity) and calls the volume emitter's virtual compute function with it.
// @fnv 0x00c31cf0
void FUN_00c31cf0_shell::ComputeEmitterInitialPositionAndVelocity(NiPoint3* kPosition, NiPoint3* kMotionVelocity)
{
    if (m_pkEmitterObject)
    {
        NiTransform kEmitter = *(NiTransform*)((char*)m_pkEmitterObject + 0x68);
        NiTransform kPSys = *(NiTransform*)((char*)m_pkTarget + 0x68);
        NiTransform kInvPSys;
        kPSys.CalculateInverse(kInvPSys);
        NiTransform kEmitterToPSys = kInvPSys * kEmitter;
        ((ComputeVolumeInitialPositionAndVelocity_t)(*(int**)this)[0xb0 / 4])(this, kEmitterToPSys, kPosition,
                                                                              kMotionVelocity);
    }
    else
    {
        NiTransform kEmitterToPSys;
        kEmitterToPSys.ResetToIdentity();
        ((ComputeVolumeInitialPositionAndVelocity_t)(*(int**)this)[0xb0 / 4])(this, kEmitterToPSys, kPosition,
                                                                              kMotionVelocity);
    }
}


// @fnv 0x00c31bc0
char const* const* __cdecl FUN_00c31bc0()
{
    return &(*reinterpret_cast<const char *const *>(&::g_012027d8));
}


extern "C" void __cdecl operator delete(void*, size_t);

struct FUN_00c31c70_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};

// @fnv 0x00c31c70
void* FUN_00c31c70_shell::DestroyIfFlagged(unsigned int flags)
{
    static_cast<::PositionState *>(nullptr)->FUN_00c31750();
    if (flags & 1)
        operator delete(this, 0x58);
    return this;
}

struct FakeStream_00c31b60
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void At30(void*);
};
struct Stub_00c31b60
{
    char _pad[0x54];
    void* m_obj;
    void FUN_00c31b60(void* s);
};
// Calls FUN_00c22530 on s, then invokes the virtual At30 on s passing m_obj.
// @fnv 0x00c31b60
void Stub_00c31b60::FUN_00c31b60(void* s)
{
    reinterpret_cast<::S_00c22530_Emitter *>(this)->FUN_00c22530((*(::S_00c22530_Stream *)(s)));
    ((FakeStream_00c31b60*)s)->At30(m_obj);
}

struct FUN_00c31b80_This
{
    char _pad[0x54];
    void* m_pkEmitterObject;
    bool FUN_00c31b80(void* pkObject);
};
// @fnv 0x00c31b80
bool FUN_00c31b80_This::FUN_00c31b80(void* pkObject)
{
    FUN_00c31b80_This* pkDest = (FUN_00c31b80_This*)pkObject;
    if (!reinterpret_cast<::FUN_00c226a0_cls *>(this)->Equals((::FUN_00c226a0_cls *)(pkObject)))
        return false;
    if (m_pkEmitterObject)
    {
        if (!pkDest->m_pkEmitterObject)
            return false;
    }
    if (!m_pkEmitterObject)
    {
        if (pkDest->m_pkEmitterObject)
            return false;
    }
    return true;
}

struct NameArray_b9457
{
    char unk00[8];
    unsigned short m_usMax;
    unsigned short m_usNum;
    char unk0c[2];
    unsigned short m_usGrow;
};

struct NameHolder_b9457
{
    char unk00[8];
    void* m_pIntegerData;
};


struct FUN_00c31db0_cls
{
    char unk00[0x54];
    NameHolder_b9457* m_pHolder;
    void FUN_00c31db0(NameArray_b9457* arr);
};

// @fnv 0x00c31db0
void FUN_00c31db0_cls::FUN_00c31db0(NameArray_b9457* arr)
{
    reinterpret_cast<::FUN_00c22780_shell *>(this)->FUN_00c22780((::StrArr *)(arr));
    void* name = ((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_012027d8))))));
    unsigned int uiIndex = arr->m_usNum;
    if (uiIndex >= arr->m_usMax)
    {
        reinterpret_cast<::ViewerStrings *>((arr))->SetSize(uiIndex + arr->m_usGrow);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((arr))->SetAt(uiIndex, (*(char * *)(&name)));
    if (m_pHolder != 0)
    {
        void* holderVal = m_pHolder->m_pIntegerData;
        name = ((void *)(::fnv_00a7d5e0::FUN_00a7d5e0("Emitter Object", (const char *)(holderVal))));
        uiIndex = arr->m_usNum;
        if (uiIndex >= arr->m_usMax)
        {
            reinterpret_cast<::ViewerStrings *>((arr))->SetSize(uiIndex + arr->m_usGrow);
        }
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((arr))->SetAt(uiIndex, (*(char * *)(&name)));
    }
}

struct FUN_00c31bd0_base
{
    FUN_00c31bd0_base(const char* pcName, unsigned int uiOrder, float fSpeed, float fSpeedVar, float fDeclination,
                      float fDeclinationVar, float fPlanarAngle, float fPlanarAngleVar, RgbaColor kInitialColor,
                      float fInitialRadius, float fLifeSpan, float fLifeSpanVar, float fRadiusVar);
    virtual ~FUN_00c31bd0_base();
    unsigned int m_uiRefCount;
    NiFixedString m_kName;
    unsigned int m_uiUpdateOrder;
    NiParticleSystem* m_pkTarget;
    bool m_bModifierActive;
    float m_fEmissionSpeed;
    float m_fSpeedVariation;
    float m_fEmissionDeclination;
    float m_fDeclinationVariation;
    float m_fEmissionPlanarAngle;
    float m_fPlanarAngleVariation;
    RgbaColor m_kParticleColor;
    float m_fEmissionRadius;
    float m_fRadiusVariation;
    float m_fYValue;
    float m_fLifeSpanVariation;
    float m_fScale;
};

struct FUN_00c31bd0 : FUN_00c31bd0_base
{
    FUN_00c31bd0(const char* pcName, NiAVObject* pkEmitterObj, float fSpeed, float fSpeedVar, float fDeclination,
                 float fDeclinationVar, float fPlanarAngle, float fPlanarAngleVar, RgbaColor kInitialColor,
                 float fInitialRadius, float fLifeSpan, float fLifeSpanVar, float fRadiusVar);
    virtual ~FUN_00c31bd0();
    NiAVObject* m_pkEmitterObject;
};

FUN_00c31bd0::FUN_00c31bd0(const char* pcName, NiAVObject* pkEmitterObj, float fSpeed, float fSpeedVar,
                           float fDeclination, float fDeclinationVar, float fPlanarAngle, float fPlanarAngleVar,
                           RgbaColor kInitialColor, float fInitialRadius, float fLifeSpan, float fLifeSpanVar,
                           float fRadiusVar)
    // Constructs a particle system modifier by delegating to the base class and storing the emitter object pointer.
// @fnv 0x00c31bd0
    : FUN_00c31bd0_base(pcName, 1000, fSpeed, fSpeedVar, fDeclination, fDeclinationVar, fPlanarAngle, fPlanarAngleVar,
                        kInitialColor, fInitialRadius, fLifeSpan, fLifeSpanVar, fRadiusVar)
{
    m_pkEmitterObject = pkEmitterObj;
}
