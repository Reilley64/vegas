// fallout_shared/bgsdecalmanager.cpp: BGSDecalManager, BSA_, PD_, M3_ and more (61 functions)

#include <cstdint>
#include <windows.h>
#include <new>
#include <cstdlib>
#include <cstring>
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/BSRenderedTexture.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ConsoleDisplay.h"
#include "fnv/decl/DecalCaster.h"
#include "fnv/decl/DecalSetup.h"
#include "fnv/decl/DumpConsole.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00456630_Class.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a0d60_Class.h"
#include "fnv/decl/FUN_004a0d90_Class.h"
#include "fnv/decl/FUN_004a0db0_class.h"
#include "fnv/decl/FUN_004a0dd0_cls.h"
#include "fnv/decl/FUN_004a2cf0.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_004a47b0.h"
#include "fnv/decl/FUN_004e3d00_shell.h"
#include "fnv/decl/FUN_004ed8c0_shell.h"
#include "fnv/decl/FUN_00507b20Class.h"
#include "fnv/decl/FUN_0050d100_shell.h"
#include "fnv/decl/FUN_0057c590_Class.h"
#include "fnv/decl/FUN_00621c90_Class.h"
#include "fnv/decl/FUN_0068de30_holder.h"
#include "fnv/decl/FUN_0068dea0_cls.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00c4edb0_Class.h"
#include "fnv/decl/ImpactTask.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiTPointerListBase.h"
#include "fnv/decl/ObsList.h"
#include "fnv/decl/Owner623.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Pool.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/decl/S_0082f1f0_Lock.h"
#include "fnv/decl/S_00c4ed70_Class.h"
#include "fnv/decl/ScreenSplatter.h"
#include "fnv/decl/ScriptList.h"
#include "fnv/decl/TESQuest.h"
#include "fnv/decl/TileSetHelper.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00631540__TargetClass.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004a1000.h"
#include "fnv/symbols_004a2000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_00c82000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01203000.h"
#include "bgsdecalmanager_decls.h"
#include "bgsdecalmanager_types_BGSDecalManager.h"
#include "bgsdecalmanager_types_BSTempEffectSimpleDecal.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include <xmmintrin.h>
#include "fnv/decl/FUN_00c46270_Class.h"
#include "fnv/decl/NavEntryOwner.h"
#include "fnv/decl/S694a0.h"
#include "fnv/decl/S_00a59e00.h"
#include "fnv/decl/TreeEvaluator.h"
#include "fnv/decl/WorkerS694a0.h"
#include "fnv/decl/fnv_00c49100__ActorTable.h"
#include "fnv/symbols_00a29000.h"

// @fnv 0x00460140
intptr_t FUN_00460140(intptr_t apBase)
{
    return apBase + 0x10;
}

struct NiStream;
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
class NiPoint3;
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
public:
    void GetRow(unsigned int, ::NiPoint3 &);
};
struct FUN_004769c0_shell : public ThreeByThreeMatrix
{
    void FUN_004769c0(unsigned int, float*);
};

// @fnv 0x004769c0
void FUN_004769c0_shell::FUN_004769c0(unsigned int uiCol, float* col)
{
    ((float(*)[3])m_afEntries)[0][uiCol] = col[0];
    ((float(*)[3])m_afEntries)[1][uiCol] = col[1];
    ((float(*)[3])m_afEntries)[2][uiCol] = col[2];
}

class Date
{
  public:
    ~Date();
};

int CallNestedAtOffset80(void*);

// @fnv 0x004a0370
void FUN_004a0370(char* pThis)
{
    ::fnv_0082f1b0::FUN_0082f1b0(pThis + 0x80);
    if (CallNestedAtOffset80(pThis) == 1)
    {
        ((Date*)pThis)->Date::~Date();
    }
}

namespace fnv_004a03c0 {
struct RecursiveLock
{
};
struct Date
{
    ~Date();
};
struct DD : Date
{
    int CallNestedAtOffset80();
    void FUN_004a03c0();
};
// @fnv 0x004a03c0
void DD::FUN_004a03c0()
{
    if (CallNestedAtOffset80() == 1)
        Date::~Date();
    reinterpret_cast<::S_0082f1f0_Lock *>((((RecursiveLock*)((char*)this + 0x80))))->FUN_0082f1f0();
}
}  // namespace fnv_004a03c0

struct P3
{
    float x, y, z;
    P3* FUN_004a0bd0(P3*);
};
// Writes the negated x, y and z components into out and returns out.
// @fnv 0x004a0bd0
P3* P3::FUN_004a0bd0(P3* out)
{
    reinterpret_cast<::FUN_00416870_t *>((out))->FUN_00416870(-x, -y, -z);
    return out;
}

// @fnv 0x004a0d10
void* FUN_004a0d10(char* pThis)
{
    return pThis + 0x100;
}

template <> class NiPointer<NiNode>
{
  public:
    NiNode* m_pObject;
    NiPointer<NiNode>& operator=(NiNode*);
};

struct FUN_004a0fd0_shell
{
    char pad[0xc4];
    NiPointer<NiNode> m_pController;
    void FUN_004a0fd0(NiNode* apNode);
};

// @fnv 0x004a0fd0
void FUN_004a0fd0_shell::FUN_004a0fd0(NiNode* apNode)
{
    m_pController = apNode;
}

struct BSA_
{
    void FUN_004a1020(void*);
};
// @fnv 0x004a1020
void BSA_::FUN_004a1020(void* p)
{
    *(void**)((char*)this + 0x194) = p;
}

struct FUN_004a1040_Helper
{
    char pad[0x19c];
    int field_19c;
    void Set(int val);
};

// @fnv 0x004a1040
void FUN_004a1040_Helper::Set(int val)
{
    field_19c = val;
}

struct Fake_FUN_004a2020
{
    char pad[0x20];
    unsigned int ulFlags[2];
    bool GetFlag(unsigned int aiFlag) const;
};

static bool (Fake_FUN_004a2020::*pfn_FUN_004a2020)(unsigned int) const = &Fake_FUN_004a2020::GetFlag;

// Tests whether the bit for aiFlag is set in the ulFlags bit array, indexing by aiFlag>>5 and masking with 1<<(aiFlag%32).
// @fnv 0x004a2020
bool Fake_FUN_004a2020::GetFlag(unsigned int aiFlag) const
{
    unsigned int uiindex = aiFlag >> 5;
    unsigned int uibit = aiFlag % 32;
    unsigned int uimask = 1 << uibit;
    return (ulFlags[uiindex] & uimask) > 0;
}

class BGSTerrainManager
{
  public:
    unsigned int GetMinLevel();
};

// Returns 0 for a null pointer, otherwise returns whether GetMinLevel() is between 1 and 12.
// @fnv 0x004a2c20
int __cdecl FUN_004a2c20(BGSTerrainManager* apShaderProp)
{
    if (!apShaderProp)
    {
        return 0;
    }
    int itp = apShaderProp->GetMinLevel();
    return itp >= 1 && itp <= 12;
}

struct __declspec(align(16)) VectorComponentValue
{
    char pad[16];
};

struct hkVector4
{
    VectorComponentValue& FUN_00458700(VectorComponentValue&, int) const;
};

struct NiPoint3_local
{
    float x, y, z;
};

// Reads components 0, 1 and 2 of arhkV into arNiP.x, arNiP.y and arNiP.z and returns arNiP.
// @fnv 0x004a3970
NiPoint3_local& __cdecl FUN_004a3970(NiPoint3_local& arNiPoint, const hkVector4& arHkVector)
{
    VectorComponentValue t0, t1, t2;
    arNiPoint.x = reinterpret_cast<::S004586d0_Obj *>((void *)&(arHkVector.FUN_00458700(t0, 0)))->FUN_004586d0();
    arNiPoint.y = reinterpret_cast<::S004586d0_Obj *>((void *)&(arHkVector.FUN_00458700(t1, 1)))->FUN_004586d0();
    arNiPoint.z = reinterpret_cast<::S004586d0_Obj *>((void *)&(arHkVector.FUN_00458700(t2, 2)))->FUN_004586d0();
    return arNiPoint;
}

struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
struct FUN_004a39f0_shell : public CFilter
{
    void FUN_004a39f0(int);
};

// Clears the low 7 bits of iFilter and stores the low 7 bits of aeLayer into them.
// @fnv 0x004a39f0
void FUN_004a39f0_shell::FUN_004a39f0(int aeLayer)
{
    iFilter &= ~0x7f;
    iFilter |= (aeLayer & 0x7f);
}

namespace fnv_004a3a20 {
struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
struct FUN_004a3a20_shell : public CFilter
{
    unsigned int FUN_004a3a20();
};

// @fnv 0x004a3a20
unsigned int FUN_004a3a20_shell::FUN_004a3a20()
{
    return (iFilter >> 16) & 0xFFFF;
}
}  // namespace fnv_004a3a20

class TESObjectREFR
{
  public:
};

// Returns the flags of apRef, or 0 when apRef is null.
// @fnv 0x004a3a40
unsigned int __cdecl FUN_004a3a40(TESObjectREFR* apRef)
{
    return apRef ? ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((apRef))->GetName())) : 0;
}

void FUN_004a3b70(void*);

struct Base_004a3b30
{
    int pad[3];
    Base_004a3b30();
    virtual ~Base_004a3b30();
};

struct Member_004a4730
{
    Member_004a4730(int);
    ~Member_004a4730();
};

struct FUN_004a3a70 : Base_004a3b30
{
    Member_004a4730 m;
    FUN_004a3a70();
    virtual ~FUN_004a3a70();
};

// Initializes the base subobject, constructs member m with 0, then calls FUN_004a3b70 on this.
// @fnv 0x004a3a70
FUN_004a3a70::FUN_004a3a70() : m(0)
{
    FUN_004a3b70(this);
}

namespace fnv_004a3da0 {
struct NiAVObject;
struct FourComponentNumericValue;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct blob16
{
    char b[16];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
struct FUN_004a3da0_shell : public BhkPickData
{
    void FUN_004a3da0(void*);
};

struct __declspec(align(16)) hkVector4
{
    char m_vComponents[16];
};

struct FUN_0056d340_helper
{
    void FUN_0056d340(hkVector4&);
};


// Converts the NiPoint3 at arFrom into a hkVector4 and passes it to FUN_0056d340 on this object.
// @fnv 0x004a3da0
void FUN_004a3da0_shell::FUN_004a3da0(void* arFrom)
{
    hkVector4 hkv;
    ((FUN_0056d340_helper*)this)->FUN_0056d340((*(::fnv_004a3da0::hkVector4 *)&(::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(hkv), (const ::fnv_004a3e00::NiPoint3 &)(*(const NiPoint3*)arFrom)))));
}
}  // namespace fnv_004a3da0

struct T_
{
};
struct PD_
{
    void ForwardToSubObject(void*);
    void FUN_004a3f40(void*);
};
// Calls ForwardToSubObject with the result of FUN_00458b20, then forwards p to FUN_004a3f10 on the object at this+0x10.
// @fnv 0x004a3f40
void PD_::FUN_004a3f40(void* p)
{
    ForwardToSubObject(FUN_00458b20());
    reinterpret_cast<::AlignedVector *>((((T_*)((char*)this + 0x10))))->FUN_004a3f10((*(const ::AlignedVector *)(p)));
}

struct Flt
{
    int v;
    operator unsigned int() const;
};
// @fnv 0x004a3f70
void FUN_004a3f70(char* self, Flt f)
{
    *(unsigned int*)(self + 0x24) = (unsigned int)f;
}

struct NiAVObject;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
struct FUN_004a3fb0_shell : public BhkPickData
{
    void FUN_004a3fb0(hkpAllRayHitCollector*);
};

// @fnv 0x004a3fb0
void FUN_004a3fb0_shell::FUN_004a3fb0(hkpAllRayHitCollector* apCollector)
{
    m_pAllCollector = apCollector;
    m_pClosestCollector = 0;
}

struct NiSourceTexture;
struct ScriptCompiler;
struct ConsoleManager
{
    static void Release();
    ScriptCompiler* QConsoleCompiler();
    void Init();
    void DoThis(char*);
    bool Idle(int);
    void PrintFormatted(char*, ...);
    void PrintFormatted(char*, char*);
    void ScrollBy(int);
    bool GetLastMenuMode();
    int GetConsoleLineSpacing();
    void SetOutputFilename(char*);
    void WriteToOutputFile(char*);
    bool IsOutputFileEnabled();
    bool IsVisible();
    void SetVisible(char);
    void OnEnterMenuMode();
    void OnLeaveMenuMode();
    bool ShouldDumpTexture(NiSourceTexture*);
    void* __vecDelDtor(unsigned int);
    ScriptCompiler* m_pScriptCompiler;
    char m_kOutputLines[12];
    char m_kCommandHistory[12];
    int m_iCommandHistoryPosition;
    int m_iScrollPosition;
    int m_iOutputLineCount;
    bool m_bVisible;
    char _pad_29[3];
    int iConsoleLineSpacing;
    int m_iConsoleX;
    int m_iConsoleY;
    char cVisible;
    bool bIsActive;
    bool m_bRecordingBatch;
    char _pad_3b[1];
    int m_iBatchCommandCount;
    char m_aacCommandHistory[2000];
    char m_acOutputFilename[260];
};
struct FUN_004a4020_shell : public ConsoleManager
{
    bool FUN_004a4020();
};

// @fnv 0x004a4020
bool FUN_004a4020_shell::FUN_004a4020()
{
    return cVisible > 0;
}

struct M3_
{
    void FUN_004b4660(unsigned int, float, float, float);
};
// @fnv 0x004b4660
void M3_::FUN_004b4660(unsigned int uiIndex, float afValue0, float afValue1, float afValue2)
{
    *(float*)((char*)this + uiIndex * 4) = afValue0;
    *(float*)((char*)this + uiIndex * 4 + 12) = afValue1;
    *(float*)((char*)this + uiIndex * 4 + 24) = afValue2;
}

struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool FUN_0056d340(uintptr_t f);
};
// @fnv 0x0056d340
bool S3e60::FUN_0056d340(uintptr_t auiFlag)
{
    return GetFlag(auiFlag);
}

namespace fnv_008cdd90 {
struct NiAVObject;
struct hkVector4;
struct hkpAllRayHitCollector;
struct hkpClosestRayHitCollector;
struct hkpPhantom;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct WorldRayCastInput
{
    char m_vFrom[16];
    char m_vTo[16];
    char m_bEnableShapeCollectionFilter[1];
    char _pad_21[3];
    unsigned int m_uiFilterInfo;
    char _pad_28[8];
};
struct RayCastHitResult
{
    struct blob1 DidHit();
    void reset();
    char m_vHitNormal[16];
    float m_fHitFraction;
    int m_iExtraInfo;
    char m_auiShapeKeys[8];
};
struct ShapeRayCastOutput : public RayCastHitResult
{
    void changeLevel(int);
    void setKey(unsigned int);
    void reset();
    void _reset();
    char m_uiShapeKeys[32];
    int m_uiShapeKeyIndex;
    char _pad_44[12];
};
struct WorldRayCastOutput : public ShapeRayCastOutput
{
    struct blob1 DidHit();
    void reset();
    void* m_pRootCollidable;
    char _pad_54[12];
};
struct BhkPickData : public WorldRayCastInput, public WorldRayCastOutput
{
    hkpRigidBody* GethkRigidBody();
    hkpPhantom* GethkPhantom();
    void CalcHitPoint(hkVector4*);
    void CalcHitPoint(NiPoint3*);
    NiAVObject* GetNiAVObject();
    void GetFrom(NiPoint3*);
    void GetTo(NiPoint3*);
    void* GethkFrom();
    void* GethkTo();
    void SetFrom(void*);
    void SetTo(void*);
    void SetFilter(struct blob4);
    struct blob4 GetFilter();
    void GetLength(NiPoint3*);
    void* GethkLength();
    void SetLength(void*);
    bool QLength();
    void SetClosestCollector(hkpClosestRayHitCollector*);
    hkpClosestRayHitCollector* GetClosestCollector();
    void SetAllCollector(hkpAllRayHitCollector*);
    hkpAllRayHitCollector* GetAllCollector();
    void SetAabbCache(char*);
    char* GetAabbCache();
    bool GetPickFailed();
    void CalcTo();
    char m_kCollisionFilter[16];
    char* m_pAabbCache;
    hkpClosestRayHitCollector* m_pClosestCollector;
    hkpAllRayHitCollector* m_pAllCollector;
    bool m_bPickFailed;
    char _pad_ad[3];
};
struct FUN_008cdd90_shell : public BhkPickData
{
    hkpAllRayHitCollector* FUN_008cdd90();
};

// @fnv 0x008cdd90
hkpAllRayHitCollector* FUN_008cdd90_shell::FUN_008cdd90()
{
    return m_pAllCollector;
}
}  // namespace fnv_008cdd90

struct BSCompoundFrustum;
struct BSFadeNode;
struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct NiAVObject;
struct NiAccumulator;
struct NiCullingProcess;
struct NiGeometry;
struct NiLines;
struct NiNode;
struct NiParticles;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct NiVisibleArray;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;

struct GO
{
    GO(int);
};
struct FUN_00a69400
{
    FUN_00a69400(NiVisibleArray*);
    virtual ~FUN_00a69400();
    char pad04[0x8c];
};
class FUN_004a0eb0 : public FUN_00a69400
{
  public:
    int i90;
    char pad94[0x28];
    int ibc;
    int ic0;
    GO go;
    FUN_004a0eb0(NiVisibleArray* apVisibleSet);
    virtual ~FUN_004a0eb0();
};
// @fnv 0x004a0eb0
FUN_004a0eb0::FUN_004a0eb0(NiVisibleArray* apVisibleSet) : FUN_00a69400(apVisibleSet), i90(0), ibc(0), ic0(0), go(0)
{}

struct FUN_004a4440
{
    ~FUN_004a4440();
};
struct FUN_004a3ae0
{
    virtual ~FUN_004a3ae0();
    char pad04[0xc];
};
class FUN_004a3bc0 : public FUN_004a3ae0
{
  public:
    FUN_004a4440 hits;
    virtual ~FUN_004a3bc0();
};
// @fnv 0x004a3bc0
FUN_004a3bc0::~FUN_004a3bc0()
{}


struct FUN_004a0f50_shell
{
    int* GetGlobalIntPtr();
};

// @fnv 0x004a0f50
int* FUN_004a0f50_shell::GetGlobalIntPtr()
{
    return &(*reinterpret_cast<int *>(&::g_012030a8));
}

struct GlobalObject_0044f440
{
};

GlobalObject_0044f440 g_011c77a8;

// @fnv 0x004a19f0
float FUN_004a19f0()
{
    return reinterpret_cast<::FUN_00450410_Class *>(&(g_011c77a8))->FUN_00450410();
}

namespace fnv_004a1a00 {
struct GlobalObject_0044f440
{
};

GlobalObject_0044f440 g_011c7588;

// @fnv 0x004a1a00
void __cdecl FUN_004a1a00()
{
    reinterpret_cast<::FUN_00450410_Class *>(&(g_011c7588))->FUN_00450410();
}
}  // namespace fnv_004a1a00


// @fnv 0x004a1a30
void FUN_004a1a30(int __this)
{
    reinterpret_cast<class ::FUN_004a47b0 *>((__this))->FUN_004a47b0::~FUN_004a47b0();
}

// @fnv 0x004a3b50
void FUN_004a3b50(void* thisPtr)
{
    ((float*)thisPtr)[1] = 1.0f;
}

struct FUN_00acbb70_shell
{
    void FUN_00acbb70();
};

void FUN_00acbb70_shell::FUN_00acbb70()
{}

struct FUN_004a03a0_shell
{
    void CallNestedAtOffset80();
};

// @fnv 0x004a03a0
void FUN_004a03a0_shell::CallNestedAtOffset80()
{
    ((FUN_00acbb70_shell*)((char*)this + 0x80))->FUN_00acbb70();
}

struct FUN_004a0d30_shell
{
    char m_auiShapeKeys[0x34];
    NiPoint3 m_kPoint;
    NiPoint3& FUN_004a0d30(NiPoint3& akDest);
};

// Copies the stored NiPoint3 into akDest and returns akDest.
// @fnv 0x004a0d30
NiPoint3& FUN_004a0d30_shell::FUN_004a0d30(NiPoint3& akDest)
{
    akDest = m_kPoint;
    return akDest;
}

struct NiPoint3_Set
{
};

// Multiplies pA and pB component-wise, stores the result into pDest via Set, and returns pDest.
// @fnv 0x004a1f90
NiPoint3* MultiplyComponents(NiPoint3* pResult, const NiPoint3* pLeft, const NiPoint3* pRight)
{
    reinterpret_cast<::FUN_00416870_t *>((((NiPoint3_Set*)pResult)))->FUN_00416870(pLeft->x * pRight->x, pLeft->y * pRight->y, pLeft->z * pRight->z);
    return pResult;
}

extern int DAT_0101e594;

struct FUN_004a3ae0_shell
{
    void FUN_004a3ae0();
};

// @fnv 0x004a3ae0
void FUN_004a3ae0_shell::FUN_004a3ae0()
{
    *(std::intptr_t*)this = (std::intptr_t)&DAT_0101e594;
}

extern int DAT_0101e594;
void FUN_004a3b50(void*);

struct FUN_004a3b30_shell
{
    int* m_vftable;
    void* InitializeVftable();
};

// @fnv 0x004a3b30
void* FUN_004a3b30_shell::InitializeVftable()
{
    m_vftable = &DAT_0101e594;
    FUN_004a3b50(this);
    return this;
}

void FUN_004a3b50(void* p);

// @fnv 0x004a3b70
void FUN_004a3b70(void* p)
{
    reinterpret_cast<::FUN_00621c90_Class *>(((char*)p + 0x10))->FUN_00626870();
    FUN_004a3b50(p);
}

namespace fnv_004a3f90 {
struct T_
{
    void ForwardToSubObject(void*);
};

// @fnv 0x004a3f90
void T_::ForwardToSubObject(void* apParam)
{
    reinterpret_cast<::AlignedVector *>((((T_*)((char*)this + 0x90))))->FUN_004a3f10((*(const ::AlignedVector *)(apParam)));
}
}  // namespace fnv_004a3f90

namespace bsrandom_singleton {
struct MersenneTwister
{
    static MersenneTwister* __cdecl GetRandomGenerator(void);
    void AddGeometryDecal(void* a, int b, char c);
};
}

struct FUN_004a3fe0_shell
{
    void FUN_004a3fe0(void* a, int b, char c);
};

// @fnv 0x004a3fe0
void FUN_004a3fe0_shell::FUN_004a3fe0(void* pObject, int b, char c)
{
    if (*(int*)((char*)pObject + 0x48) == 0)
    {
        *(std::intptr_t*)((char*)pObject + 0x48) = (std::intptr_t)this;
    }
    bsrandom_singleton::MersenneTwister::GetRandomGenerator()->AddGeometryDecal(pObject, b, c);
}

struct FUN_0049f560_Holder
{
    int _00;
    std::intptr_t _04;
    int _08;
    void CallWithTwelve(std::intptr_t);
};
// Calls FUN_00ec6f20 with the holder's _04 and _08 fields, the constant 12, and a1.
// @fnv 0x0049f560
void FUN_0049f560_Holder::CallWithTwelve(std::intptr_t a1)
{
    std::qsort((void *)(_04), _08, 12, (int (*)(const void *, const void *))(a1));
}

void __cdecl FUN_004a0010();
struct S004a03f0
{
    void CleanupDecalEmitters();
};
// @fnv 0x0049fff0
void FUN_0049fff0(BGSDecalManager* p)
{
    FUN_004a0010();
    p->RenderDecals();
    ((S004a03f0*)p)->CleanupDecalEmitters();
}

struct StandIn
{
    void* FUN_004a0490(unsigned int);
};
// Calls FUN_004a2cf0, then if bit 0 of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x004a0490
void* StandIn::FUN_004a0490(unsigned int flags)
{
    reinterpret_cast<::FUN_004a2cf0 *>(this)->FUN_004a2cf0::~FUN_004a2cf0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BSCullingProcess
{
    void* FUN_004a0ff0(unsigned int flags);
};
struct Unk
{
    void FUN_004a1a10(int, unsigned char);
};
// @fnv 0x004a1a10
void Unk::FUN_004a1a10(int aiArg, unsigned char b)
{
    ::SetSelectionMask(0x27, aiArg, b);
}

namespace fnv_004a3b00 {
struct FUN_004a3ae0
{
    virtual ~FUN_004a3ae0();
    void* DestroyAndFree(unsigned int);
};
// Runs the destructor and, when bit 0 of flags is set, deallocates this object; returns this.
// @fnv 0x004a3b00
void* FUN_004a3ae0::DestroyAndFree(unsigned int flags)
{
    reinterpret_cast<::FUN_004a3ae0_shell *>((this))->FUN_004a3ae0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_004a3b00

namespace fnv_004a3b90 {
struct FUN_004a3bc0
{
    virtual ~FUN_004a3bc0();
};
struct XHolder : FUN_004a3bc0
{
    void* DestroyAndMaybeDeallocate(unsigned int);
};
// Runs the base destructor, then frees this object via _Deallocate when bit 0 of flags is set, and returns this.
// @fnv 0x004a3b90
void* XHolder::DestroyAndMaybeDeallocate(unsigned int flags)
{
    reinterpret_cast<::FUN_004a3bc0 *>((this))->::FUN_004a3bc0::~FUN_004a3bc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_004a3b90

struct FUN_004a0350_shell
{
    char bUnk2d;
    char GetByteAt2D();
};
// @fnv 0x004a0030
void BGSDecalManager::RenderDecals()
{
    if (((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&m_kSimpleDecalList)))->GetName())) > 0)
    {
        ::FUN_004a0370((char *)(FUN_0043c4b0()));
        struct IteratorState
        {
            unsigned int previous;
            std::uintptr_t position;
        } iterator;
        iterator.position = reinterpret_cast<std::uintptr_t>(static_cast<BSFaceGenAnimationData*>(
            *reinterpret_cast<NiPointer<BSFaceGenAnimationData>*>(&m_kSimpleDecalList)));
        while (iterator.position != 0)
        {
            iterator.previous = iterator.position;
            BSTempEffectSimpleDecal* decal = reinterpret_cast<BSTempEffectSimpleDecal*>(
                static_cast<BSFaceGenAnimationData*>(reinterpret_cast<NiPointer<BSFaceGenAnimationData>&>(
                    (*(::NiPointer< ::NiProperty> *)(reinterpret_cast<::ListStandIn *>((reinterpret_cast<NiTPointerListBaseT<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >*>(
                        &m_kSimpleDecalList)))->FUN_0057cbe0((int **)&(reinterpret_cast<void*&>(iterator.position))))))));
            if (decal != 0)
            {
                if (decal->m_bNeedsManagerUpdate)
                {
                    RemoveDecal(decal);
                    decal->m_bNeedsManagerUpdate = false;
                }

                if (decal->m_pRenderQuery != 0)
                {
                    if (reinterpret_cast<::FUN_0068de30_holder *>((decal))->ReleaseTextureObject())
                    {
                        if (decal->m_uiTextureReferenceCount > 0)
                        {
                            if (*(*reinterpret_cast<::ProcessLists *>(&::g_011c5904)).GetLifeStateControlFlag())
                                ::FUN_005b5e40();
                            reinterpret_cast<DecalVtableCall*>(decal)->vfn_8c();
                        }
                        else
                        {
                            if (*(*reinterpret_cast<::ProcessLists *>(&::g_011c5904)).GetLifeStateControlFlag())
                                ::FUN_005b5e40();
                            decal->bWasPlaying = true;
                        }
                    }
                }
                else
                {
                    reinterpret_cast<DecalVtableCall*>(decal)->vfn_8c();
                }

                if (decal->m_bTextureDirty && !decal->bWasPlaying)
                    reinterpret_cast<::DecalSetup *>((decal))->Initialize();

                if (decal->bWasPlaying)
                {
                    if (((bool)(reinterpret_cast<::FUN_004a0350_shell *>((decal))->GetByteAt2D())))
                    {
                        ++DAT_011c57ec;
                        if (*(*reinterpret_cast<::ProcessLists *>(&::g_011c5904)).GetLifeStateControlFlag())
                            ::FUN_005b5e40();

                        if (DAT_011c57f4 & 1)
                        {
                            ImageSpaceEffectParam color(0.0f, 1.0f, 0.0f, 1.0f);
                            reinterpret_cast<::FUN_0068dea0_cls *>((decal))->UpdateDebugDecalBox((const ::xColorA *)&(reinterpret_cast<RgbaColor&>(color)), true);
                        }
                        if (DAT_011c57f4 & 2)
                        {
                            ImageSpaceEffectParam color(0.0f, 1.0f, 0.0f, 0.25f);
                            reinterpret_cast<::FUN_0068dea0_cls *>((decal))->UpdateDebugDecalBox((const ::xColorA *)&(reinterpret_cast<RgbaColor&>(color)), false);
                        }
                    }
                    else if (DAT_011c57f4 & 0x10)
                    {
                        if (DAT_011c57f4 & 1)
                        {
                            ImageSpaceEffectParam color(1.0f, 0.0f, 0.0f, 1.0f);
                            reinterpret_cast<::FUN_0068dea0_cls *>((decal))->UpdateDebugDecalBox((const ::xColorA *)&(reinterpret_cast<RgbaColor&>(color)), true);
                        }
                        if (DAT_011c57f4 & 2)
                        {
                            ImageSpaceEffectParam color(1.0f, 0.0f, 0.0f, 0.25f);
                            reinterpret_cast<::FUN_0068dea0_cls *>((decal))->UpdateDebugDecalBox((const ::xColorA *)&(reinterpret_cast<RgbaColor&>(color)), false);
                        }
                    }
                    reinterpret_cast<NiTPointerListBaseT<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >*>(
                        &m_kSimpleDecalList)
                        ->RemovePos(reinterpret_cast<void*&>(iterator.previous));
                }
            }
        }
        FUN_0043c4b0()->FinishScene();
    }
}

// @fnv 0x004a0350
char FUN_004a0350_shell::GetByteAt2D()
{
    return *(char*)((char*)this + 0x2d);
}

struct FUN_00456630_helper
{
public:
    bool FUN_00456610();
};

struct FUN_004a19d0_shell
{
    void FUN_004a19d0();
};

// @fnv 0x004a19d0
void FUN_004a19d0_shell::FUN_004a19d0()
{
    reinterpret_cast<::FUN_00456630_Class *>((reinterpret_cast<FUN_00456630_helper*>(this)))->FUN_00456630(0x400);
}

namespace fnv_004a1a50 {
struct M788
{
};
struct bsrandom_singleton
{
    struct MersenneTwister
    {
        static bsrandom_singleton::MersenneTwister* GetRandomGenerator();
    };
};
// @fnv 0x004a1a50
void __cdecl FUN_004a1a50(void* apEmitter)
{
    if (apEmitter)
        reinterpret_cast<::FUN_004ed8c0_shell *>((((M788*)((char*)bsrandom_singleton::MersenneTwister::GetRandomGenerator() + 0x14))))->FUN_004ed8c0((int *)(void *)(&apEmitter));
}
}  // namespace fnv_004a1a50

namespace fnv_004a0330 {
struct Flt
{
    operator unsigned int() const;
};

struct FUN_004a0330_shell
{
    char pad[0x10c];
    Flt f;
    unsigned int FUN_004a0330();
};

// @fnv 0x004a0330
unsigned int FUN_004a0330_shell::FUN_004a0330()
{
    return static_cast<unsigned int>(f);
}
}  // namespace fnv_004a0330

struct NiGeometryData
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
};
struct NiGeometry
{
    void FUN_004a1ff0();
};
// Calls FUN_005495f0 to get the geometry data and then invokes its v42 method.
// @fnv 0x004a1ff0
void NiGeometry::FUN_004a1ff0()
{
    ((::NiGeometryData *)(::fnv_005495f0::FUN_005495f0((const char *)this)))->v42();
}

namespace fnv_004a2c00 {
struct GO
{
    GO& operator=(void*);
};

struct FUN_004a2c00_shell
{
    char pad[0x34];
    GO m_go;
    void AssignGo(void* arg);
};

// @fnv 0x004a2c00
void FUN_004a2c00_shell::AssignGo(void* arg)
{
    m_go = arg;
}
}  // namespace fnv_004a2c00

struct FUN_004a3cc0_Class
{
    FUN_004a3cc0_Class* FUN_004a3cc0(void);
};

struct Holder
{
};


struct FUN_004a3c20
{
    FUN_004a3c20();
    ~FUN_004a3c20();
};

// Constructor: initializes subobjects at offsets 0x00, 0x30 and 0x90, then zeroes fields at 0xa0, 0xa4, 0xa8 and 0xac.
// @fnv 0x004a3c20
FUN_004a3c20::FUN_004a3c20()
{
    ((FUN_004a3cc0_Class*)((char*)this + 0x00))->FUN_004a3cc0();
    FUN_004a3d00((char*)this + 0x30);
    new ((void *)(((Holder*)((char*)this + 0x90)))) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)((Holder*)FUN_00458b20())));
    *(int*)((char*)this + 0xa0) = 0;
    *(int*)((char*)this + 0xa4) = 0;
    *(int*)((char*)this + 0xa8) = 0;
    *(char*)((char*)this + 0xac) = 0;
}

struct StatefulObject
{
    ~StatefulObject();
};

struct DecalEmitterNode
{
    StatefulObject* emitter;
    DecalEmitterNode* next;
};

struct BGSDecalEmitterList
{
    DecalEmitterNode* head;
    DecalEmitterNode* tail;
    unsigned int count;
    void FUN_0049f590(DecalEmitterNode** cursor);
};

struct PendingDecalList
{
    void* head;
    void* tail;
    unsigned int count;
};

struct DecalCleanupOwner
{
    void* queryTexture;
    unsigned int clearQueryTexture;
    PendingDecalList pendingSimpleDecals;
    BGSDecalEmitterList decalEmitters;
    void CleanupDecalEmitters();
};

// Walks the decal emitter list, calls FUN_004a2d50 on each emitter, and deletes those for which FUN_004f1540 returns true.
// @fnv 0x004a03f0
void DecalCleanupOwner::CleanupDecalEmitters()
{
    DecalEmitterNode* cursor = ((::DecalEmitterNode *)(::FUN_00559450((int *)&(decalEmitters))));
    while (cursor != 0)
    {
        DecalEmitterNode* previous = cursor;
        StatefulObject* emitter = *((::StatefulObject **)(reinterpret_cast<::ListStandIn *>(&(decalEmitters))->FUN_0057cbe0((int **)(::DecalEmitterNode **)(&cursor))));
        if (emitter != 0)
        {
            reinterpret_cast<::ImpactTask *>((emitter))->FUN_004a2d50();
            if (reinterpret_cast<::PatrolActorPackageData *>((emitter))->IsPatrolling())
            {
                decalEmitters.FUN_0049f590(&previous);
                delete emitter;
                emitter = 0;
            }
        }
    }
}

class FUN_004a0f60_sub
{
  public:
    ~FUN_004a0f60_sub();
};

class FUN_004a0f60_base
{
  public:
    virtual void Update();
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
    unsigned int unk44;
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
    unsigned int unk74;
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
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    virtual ~FUN_004a0f60_base();
};

class FUN_004a0f60_cls : public FUN_004a0f60_base
{
  public:
    FUN_004a0f60_sub m_c4;
    virtual ~FUN_004a0f60_cls();
};
// Calls FUN_004a0f60, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004a0ff0
void* BSCullingProcess::FUN_004a0ff0(unsigned int flags)
{
    reinterpret_cast<::FUN_004a0f60_cls *>(this)->FUN_004a0f60_cls::~FUN_004a0f60_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor of the class; destroys the embedded m_c4 sub-object and the base.
// @fnv 0x004a0f60
FUN_004a0f60_cls::~FUN_004a0f60_cls()
{}

namespace CameraPass {
struct Vec
{
    float x, y, z;
    Vec ApplyScaled(float);
};
struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    Matrix FUN_0043f8d0(const Matrix&);
};
void FUN_00c4b600(Matrix*, Vec);
struct Frustum
{
    float left, right, top, bottom, nearValue, farValue;
    bool ortho;
    Frustum(int);
};
struct Update
{
    unsigned int unk0, unk4, unk8;
    Update(float, int, int);
};
struct Color
{
    float r, g, b, a;
    Color(float, float, float, float);
};
struct Name
{
    const char* FUN_0043b1b0();
};
struct Ref
{
};
struct Query
{
    unsigned int unk0;
    Query();
};
struct Input
{
    unsigned int unk0, unk4, unk8, unkc, unk10, unk14;
    char unk18, unk19, unk1a;
    bool alternate;
    Query* query;
};
struct Scene
{
    Vec FUN_0045bba0();
};
struct ScenePtr
{
    Scene* ptr;
};
struct Node
{
};
struct NodePtr
{
    Node* ptr;
};
struct Render
{
};
struct RenderPtr
{
    Render* ptr;
    void FUN_0066b0d0(Render*);
};
struct Factory
{
};
struct Resource
{
};
struct Cull
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unk44;
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
    unsigned int unk74;
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
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    Cull(int);
    ~Cull();
};
struct Setting
{
    bool* FUN_00408d60();
};
extern char DAT_0101e298, DAT_0101e274, DAT_0101e24c, DAT_0101e1f8;
struct World
{
};
struct Camera
{
    RenderPtr render;
    unsigned int unk4, unk8, unkc, unk10, unk14, unk18, unk1c;
    NodePtr node;
    ScenePtr scene;
    void UpdateCamera(Input*);
};
// @fnv 0x004a04c0
void Camera::UpdateCamera(Input* input)
{
    Vec directionSlot1Slot0 = (*(::CameraPass::Vec *)&(reinterpret_cast<::FUN_004a0d60_Class *>((input))->FUN_004a0d60(*(::NiPoint3 *)nullptr)));
    reinterpret_cast<::FUN_004a0c10_s *>(&(directionSlot1Slot0))->FUN_004a0c10();
    reinterpret_cast<::MyPoint439180 *>(&(directionSlot1Slot0))->FUN_00439180(::DAT_0101b268);
    Vec originSlot13 = (*(::CameraPass::Vec *)(reinterpret_cast<::Point3Offset *>((void *)&(const ::CameraPass::Vec &)((*(::CameraPass::Vec *)&(reinterpret_cast<::FUN_004a0d30_shell *>((input))->FUN_004a0d30(*(::NiPoint3 *)nullptr)))))->ProjectileLaunched((::NiPoint3 *)&(directionSlot1Slot0), {})));
    Matrix rotationSlot17Slot12;
    FUN_00c4b600(&rotationSlot17Slot12, (*(::CameraPass::Vec *)(reinterpret_cast<::P3 *>(&(directionSlot1Slot0))->FUN_004a0bd0({}))));
    Matrix scaleSlot22Slot0Slot10;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(scaleSlot22Slot0Slot10))->FUN_004a0c90(reinterpret_cast<::FUN_004e3d00_shell *>((input))->FUN_004e3d00());
    rotationSlot17Slot12 = scaleSlot22Slot0Slot10.FUN_0043f8d0(rotationSlot17Slot12);
    Vec column0Slot30Slot0;
    Vec column1Slot41Slot18;
    reinterpret_cast<::ThreeByThreeMatrix *>(&(rotationSlot17Slot12))->GetRow(0, (::NiPoint3 &)(column0Slot30Slot0));
    reinterpret_cast<::ThreeByThreeMatrix *>(&(rotationSlot17Slot12))->GetRow(1, (::NiPoint3 &)(column1Slot41Slot18));
    reinterpret_cast<::ThreeByThreeMatrix *>(&(rotationSlot17Slot12))->GetRow(2, (::NiPoint3 &)(directionSlot1Slot0));
    Matrix basisSlot28Slot36;
    reinterpret_cast<::FUN_004769c0_shell *>(&(basisSlot28Slot36))->FUN_004769c0(0, (float *)&(directionSlot1Slot0));
    reinterpret_cast<::FUN_004769c0_shell *>(&(basisSlot28Slot36))->FUN_004769c0(1, (float *)&(column0Slot30Slot0));
    reinterpret_cast<::FUN_004769c0_shell *>(&(basisSlot28Slot36))->FUN_004769c0(2, (float *)&(column1Slot41Slot18));
    Vec startSlot14Slot30;
    Vec endSlot11;
    float widthSlot15Slot25 = (reinterpret_cast<::FUN_00507b20Class *>((input))->FUN_00507b20() / ::DAT_01011590) * (1.0f / reinterpret_cast<::FUN_008d01e0_Class *>((((::CameraPass::Ref *)(reinterpret_cast<::fnv_004a0330::FUN_004a0330_shell *>((input))->FUN_004a0330()))))->FUN_008d01e0());
    float heightSlot21 = (reinterpret_cast<::FUN_004a0d90_Class *>((input))->GetField11C() / ::DAT_01011590) * (1.0f / reinterpret_cast<::FUN_008d01e0_Class *>((((::CameraPass::Ref *)(reinterpret_cast<::fnv_004a0330::FUN_004a0330_shell *>((input))->FUN_004a0330()))))->FUN_008d01e0());
    float farPlaneSlot12Slot43 = reinterpret_cast<::FUN_004a0db0_class *>((input))->GetFloatAt120() + DAT_0101e2c0;
    Frustum frustumSlot18Slot39(0);
    frustumSlot18Slot39.ortho = true;
    frustumSlot18Slot39.nearValue = ::DAT_0101e2bc;
    frustumSlot18Slot39.left = -widthSlot15Slot25;
    frustumSlot18Slot39.right = widthSlot15Slot25;
    frustumSlot18Slot39.top = heightSlot21;
    frustumSlot18Slot39.bottom = -heightSlot21;
    frustumSlot18Slot39.farValue = farPlaneSlot12Slot43;
    reinterpret_cast<::FUN_00440460_S *>((((::CameraPass::Scene *)(::FUN_00559450((int *)&(scene))))))->FUN_00440460((const ::V3 *)&(originSlot13));
    reinterpret_cast<::FUN_0043fa80_s *>((((::CameraPass::Scene *)(::FUN_00559450((int *)&(scene))))))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(basisSlot28Slot36));
    reinterpret_cast<::NiCamera *>((((::CameraPass::Scene *)(::FUN_00559450((int *)&(scene))))))->UpdateViewFrustum((const ::NiFrustum &)(frustumSlot18Slot39));
    Update updateSlot12(0.0f, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((((::CameraPass::Scene *)(::FUN_00559450((int *)&(scene))))))->FUN_00a59c60((std::intptr_t)(&updateSlot12));
    void* lineSlot0Slot21;
    if (::DAT_011c57f4 & 4)
    {
        startSlot14Slot30 = originSlot13;
        endSlot11 = (*(::CameraPass::Vec *)(reinterpret_cast<::Point3Offset *>(&(originSlot13))->ProjectileLaunched((::NiPoint3 *)&(const ::CameraPass::Vec &)(((::CameraPass::Scene *)(::FUN_00559450((int *)&(scene))))->FUN_0045bba0().ApplyScaled(farPlaneSlot12Slot43)), {})));
        lineSlot0Slot21 =
            ((void *)(::fnv_004b3890::FUN_004b3890((const class ::FUN_006815c0 &)(startSlot14Slot30), (const ::fnv_004b3890::FUN_004a7800 &)((const ::CameraPass::Color &)(Color(0.0f, 0.0f, 1.0f, 1.0f))), (const class ::FUN_006815c0 &)(endSlot11), (const ::fnv_004b3890::FUN_004a7800 &)((const ::CameraPass::Color &)(Color(1.0f, 0.0f, 0.0f, 1.0f))), 1)));
        reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::CameraPass::World * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(lineSlot0Slot21), ::DAT_01018f5c);
    }
    if (*(*reinterpret_cast<::CameraPass::Setting *>(&::g_011c5904)).FUN_00408d60())
    {
        Vec look = ((::CameraPass::Scene *)(::FUN_00559450((int *)&(scene))))->FUN_0045bba0();
        ::FUN_005b5e40();
        ::FUN_005b5e40();
        ::FUN_005b5e40();
        ::FUN_005b5e40();
    }
    if (!((::CameraPass::Render *)(::FUN_00559450((int *)&(render)))))
        render.FUN_0066b0d0(((::CameraPass::Render *)(((::Pool *)(std::intptr_t)(::FUN_004a0ea0()))->FUN_00b6e110((::std::uintptr_t)(::FUN_004a0e90()), 0x33, 0, 0, 0))));
    if (input->alternate)
        ::FUN_00b6b8d0(7, (::NiRenderTargetGroup *)(void *)(((void *)(reinterpret_cast<::BSRenderedTexture *>((((::CameraPass::Render *)(::FUN_00559450((int *)&(render))))))->GetGroup()))));
    else
        ::FUN_00b6b8d0(0, (::NiRenderTargetGroup *)(void *)(((void *)(reinterpret_cast<::BSRenderedTexture *>((((::CameraPass::Render *)(::FUN_00559450((int *)&(render))))))->GetGroup()))));
    input->query = new Query;
    reinterpret_cast<::S_00c4ed70_Class *>((input->query))->FUN_00c4ed70();
    reinterpret_cast<::FUN_004a0dd0_cls *>((((::CameraPass::Resource *)(::FUN_0043c4b0()))))->FUN_004a0dd0({});
    Cull cullSlot18Slot33(0);
    reinterpret_cast<::FUN_004a0fd0_shell *>(&(cullSlot18Slot33))->FUN_004a0fd0((::NiNode *)(::CameraPass::Node *)(((::CameraPass::Node *)(::FUN_00559450((int *)&(node))))));
    reinterpret_cast<::BSA_ *>((((::CameraPass::Node *)(::FUN_00559450((int *)&(node))))))->FUN_004a1020(((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))));
    reinterpret_cast<::FUN_004a1040_Helper *>((((::CameraPass::Node *)(::FUN_00559450((int *)&(node))))))->Set(15);
    ::FUN_00b6bee0(((::CameraPass::Scene *)(::FUN_00559450((int *)&(scene)))), ((::CameraPass::Ref *)(reinterpret_cast<::fnv_004a0330::FUN_004a0330_shell *>((input))->FUN_004a0330())), (::BSShaderAccumulator *)(::CameraPass::Cull *)(&cullSlot18Slot33));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(::CameraPass::Scene *)(((::CameraPass::Scene *)(::FUN_00559450((int *)&(scene))))), (::BSShaderAccumulator *)(::CameraPass::Node *)(((::CameraPass::Node *)(::FUN_00559450((int *)&(node))))), 0);
    reinterpret_cast<::FUN_004a0fd0_shell *>(&(cullSlot18Slot33))->FUN_004a0fd0((::NiNode *)(::CameraPass::Node *)(0));
    reinterpret_cast<::FUN_00c4edb0_Class *>((input->query))->FUN_00c4edb0();
    ::BSRenderedTexture::EndAllAndResetRendererState();
}
}

struct TESForm
{
    unsigned int GetFormType();
};
class Refr_C
{
  public:
};

// Returns false when the reference's acoustic space form type is 35, 42, 43 or 51; otherwise returns true.
// @fnv 0x004a1060
bool __cdecl IsAcousticSpaceFormTypeAllowed(Refr_C* apRef, int aiArg)
{
    int iUnused = aiArg;
    switch (((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))->GetFormType())
    {
    case 35:
    case 42:
    case 43:
    case 51:
        return false;
    }
    return true;
}


namespace DecalAdd {

struct DecalPoint
{
    float x, y, z;
    DecalPoint ApplyScaled(float afScale) const;
};

union DecalTicks
{
    struct
    {
        unsigned int LowPart;
        int HighPart;
    };
    __int64 QuadPart;
};

struct DecalRotation
{
};

struct DecalBound
{
    float fData[4];
};

struct DecalNode
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual DecalNode* GetNode();
    bool FUN_004a19d0();
};

struct DecalHolder
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
    virtual DecalNode* Get3D();
};

struct DecalPlayer
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
    virtual DecalPoint* GetPos();
};

struct DecalRequest
{
    DecalPoint kPos;
    DecalPoint kWorldPosition;
    char pad18[0xc];
    DecalHolder* pHolder;
    DecalNode* pTarget;
    char pad2c[0xc];
    float m_fGlyphWidthInPixels;
    float m_fGlyphExtent;
    char pad40[8];
    DecalNode* pParent;
    char pad4c[0x25];
    unsigned char bRefresh;
    char pad72[5];
    unsigned char bForce;
};

struct DecalHitList
{
    int iData[3];
    DecalHitList();
    ~DecalHitList();
    int FUN_0049c680(DecalNode** appNode, int aiFlags);
};

struct DecalEmitter
{
    int FUN_00622f80(DecalRequest* apRequest, const DecalPoint& arPos, float afRange);
};

struct DecalMemContext
{
    int iOldContext;
    DecalMemContext(int aiContext, bool abPush, const char* apFile, int aiLine);
    ~DecalMemContext();
};

struct DecalBoolSetting
{
    unsigned char* FUN_00408d60();
};
struct DecalIntSetting
{
};

extern DecalEmitter* DAT_011c57e0;

float __cdecl FUN_004a1a00();

static const char s_szSourceFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSDecalManager.cpp";
static const char s_szSimpleDecal[] = "DECAL: Simple Decal Instantiated";
static const char s_szTiming[] = "AddGeometryDecalRecurse: Ticks: %I64d, Microseconds: %f";
static const char s_szSkinLimit[] = "DECAL: Reached Max Skin Decal Limit! : %d";

struct DecalManager
{
    int iPad00;
    bool m_bDecalsEnabled;

    void FUN_004a1a70(DecalRequest* apRequest);
    void FUN_004a2070(DecalRequest* apRequest);
    void AddGeometryDecal(DecalRequest* apRequest, int aiType, bool abForce);
};

// Handles decal requests by type, checking distance and force flags in some cases and processing collision hits in another.
// @fnv 0x004a10d0
void DecalManager::AddGeometryDecal(DecalRequest* apRequest, int aiType, bool abForce)
{
    __int64 llEnd;
    DecalPoint kCameraIn;
    float fDistance;
    __int64 llFrequencyCount;
    int iUnused;
    DecalTicks kStartNext;
    double dFrequency;
    DecalMemContext kMemContextRef(7, true, s_szSourceFile, 0x1b8);
    m_bDecalsEnabled = true;
    switch (aiType)
    {
    case 1:
        if (*(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c5834)).FUN_00408d60() && apRequest->pTarget && !apRequest->pTarget->FUN_004a19d0())
        {
            kCameraIn = *(*reinterpret_cast<::DecalAdd::DecalPlayer * *>(&::_g_thePlayer))->GetPos();
            fDistance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::DecalAdd::DecalPoint &)((*(::DecalAdd::DecalPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(apRequest->kPos))->FUN_00439ef0((::NiPoint3 *)&(kCameraIn), *(const ::NiPoint3 *)nullptr)))))->ComputeMagnitude();
            dFrequency = 1000.0;
            iUnused = 0;
            kStartNext.LowPart = 0;
            char acBuffer[256];
            __int64 llTicks;
            if (*(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c5884)).FUN_00408d60())
            {
                QueryPerformanceFrequency((LARGE_INTEGER*)&llFrequencyCount);
                dFrequency = llFrequencyCount * 1e-06;
                QueryPerformanceCounter((LARGE_INTEGER*)&kStartNext.QuadPart);
            }
            if (::FUN_004a19f0() >= fDistance || apRequest->bForce || abForce)
            {
                if (*(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c5904)).FUN_00408d60())
                    ::FUN_005b5e40();
                FUN_004a1a70(apRequest);
            }
            if (*(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c5884)).FUN_00408d60())
            {
                QueryPerformanceCounter((LARGE_INTEGER*)&llEnd);
                llTicks = llEnd - kStartNext.QuadPart;
                ::FUN_00406d00(acBuffer, 0xff, s_szTiming, llTicks, llTicks / dFrequency);
                ::FUN_0040fbe0();
            }
        }
        break;
    case 4:
        if (*(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c5834)).FUN_00408d60() && apRequest->pTarget && !apRequest->pTarget->FUN_004a19d0())
        {
            apRequest->bRefresh = 1;
            FUN_004a1a70(apRequest);
        }
        break;
    case 2:
        if (*(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c58bc)).FUN_00408d60() && apRequest->pTarget && !apRequest->pTarget->FUN_004a19d0())
        {
            DecalPoint kEyeOut = *(*reinterpret_cast<::DecalAdd::DecalPlayer * *>(&::_g_thePlayer))->GetPos();
            DecalBound kBound = *((::DecalAdd::DecalBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((apRequest->pTarget))->FUN_0043d450()));
            float fBoundDistance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::DecalAdd::DecalPoint &)((*(::DecalAdd::DecalPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((::DecalAdd::DecalPoint *)((void *)&(kBound)))))->FUN_00439ef0((::NiPoint3 *)&(kEyeOut), *(const ::NiPoint3 *)nullptr)))))->ComputeMagnitude() - reinterpret_cast<::Twin_0084d030 *>(&(kBound))->GetStoredFloatValue();
            if ((FUN_004a1a00() >= fBoundDistance && (*reinterpret_cast<unsigned int *>(&::DAT_011c57f0)) < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::DecalAdd::DecalIntSetting *>(&::g_011c58e4))))))) || abForce)
                FUN_004a2070(apRequest);
            else if ((*reinterpret_cast<unsigned int *>(&::DAT_011c57f0)) >= *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::DecalAdd::DecalIntSetting *>(&::g_011c58e4)))))) && *(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c5904)).FUN_00408d60())
                ::FUN_005b5e40();
        }
        else if (*(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c58bc)).FUN_00408d60() && apRequest->pHolder)
        {
            DecalPoint kViewerNew = *(*reinterpret_cast<::DecalAdd::DecalPlayer * *>(&::_g_thePlayer))->GetPos();
            DecalBound kHolderBoundCur = *((::DecalAdd::DecalBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((apRequest->pHolder->Get3D()))->FUN_0043d450()));
            float fHolderDistance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::DecalAdd::DecalPoint &)((*(::DecalAdd::DecalPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((::DecalAdd::DecalPoint *)((void *)&(kHolderBoundCur)))))->FUN_00439ef0((::NiPoint3 *)&(kViewerNew), *(const ::NiPoint3 *)nullptr)))))->ComputeMagnitude() -
                                    reinterpret_cast<::Twin_0084d030 *>(&(kHolderBoundCur))->GetStoredFloatValue();
            DecalNode* pObject = apRequest->pHolder->Get3D();
            DecalNode* pNode = pObject ? pObject->GetNode() : 0;
            if (pNode && !pObject->FUN_004a19d0())
            {
                apRequest->pTarget = pNode;
                if ((FUN_004a1a00() >= fHolderDistance && (*reinterpret_cast<unsigned int *>(&::DAT_011c57f0)) < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::DecalAdd::DecalIntSetting *>(&::g_011c58e4))))))) || abForce)
                    FUN_004a2070(apRequest);
                else if ((*reinterpret_cast<unsigned int *>(&::DAT_011c57f0)) >= *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::DecalAdd::DecalIntSetting *>(&::g_011c58e4)))))) && *(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c5904)).FUN_00408d60())
                    ::FUN_005b5e40();
            }
        }
        else if (*(*reinterpret_cast<::DecalAdd::DecalBoolSetting *>(&::g_011c5834)).FUN_00408d60())
        {
            reinterpret_cast<::FUN_004a0c10_s *>(&(apRequest->kWorldPosition))->FUN_004a0c10();
            if (!DAT_011c57e0)
                DAT_011c57e0 = ((::DecalAdd::DecalEmitter *)(::ScreenSplatter::Activate(::FUN_00404010(apRequest->m_fGlyphExtent, apRequest->m_fGlyphWidthInPixels), 1)));
            reinterpret_cast<::Unk *>((DAT_011c57e0))->FUN_004a1a10(8, 0);
            reinterpret_cast<::Unk *>((DAT_011c57e0))->FUN_004a1a10(0x1d, 0);
            reinterpret_cast<::Owner623 *>((DAT_011c57e0))->FUN_006231a0((::NiNode623 *)(void *)(reinterpret_cast<::FUN_004543c0_cls *>((apRequest->pParent))->FUN_004543c0()));
            int iCount = DAT_011c57e0->FUN_00622f80(
                apRequest, (*(::DecalAdd::DecalPoint *)(reinterpret_cast<::Point3Offset *>((void *)&(apRequest->kPos))->ProjectileLaunched((::NiPoint3 *)&(const ::DecalAdd::DecalPoint &)(apRequest->kWorldPosition.ApplyScaled(80.0f)), {}))), 32.0f);
            if (iCount == 0)
            {
                DecalPoint kNewDir =
                    (*(::DecalAdd::DecalPoint *)(reinterpret_cast<::Point3Offset *>((void *)&(apRequest->kWorldPosition))->ProjectileLaunched((::NiPoint3 *)&(const ::DecalAdd::DecalPoint &)((*(::DecalAdd::DecalPoint *)(reinterpret_cast<::P3 *>((void *)&((*reinterpret_cast<::DecalAdd::DecalRotation *>((void *)&::DAT_011a9484))))->FUN_004a0bd0({}))).ApplyScaled(2.0f)), {})));
                reinterpret_cast<::FUN_004a0c10_s *>(&(kNewDir))->FUN_004a0c10();
                apRequest->kWorldPosition = kNewDir;
                iCount = DAT_011c57e0->FUN_00622f80(apRequest, (*(::DecalAdd::DecalPoint *)(reinterpret_cast<::Point3Offset *>((void *)&(apRequest->kPos))->ProjectileLaunched((::NiPoint3 *)&(const ::DecalAdd::DecalPoint &)(kNewDir.ApplyScaled(80.0f)), {}))),
                                                    32.0f);
            }
            DecalHitList kHits;
            for (int i = 0; i < iCount; i++)
            {
                DecalPoint kHitPos;
                DecalPoint kHitNormal;
                DecalNode* pHitTmp = ((::DecalAdd::DecalNode *)(reinterpret_cast<::DecalCaster *>((DAT_011c57e0))->GetCollisionFlags(i)));
                if (pHitTmp)
                {
                    reinterpret_cast<::TileSetHelper *>((DAT_011c57e0))->SetTileSetValues(i, (std::intptr_t)(&kHitPos), (std::intptr_t)(&kHitNormal));
                    reinterpret_cast<::FUN_004a0c10_s *>(&(kHitNormal))->FUN_004a0c10();
                    void* m_pShaderGeometry = ((void *)(::FUN_0056f930((::NiAVObject *)(pHitTmp))));
                    if (pHitTmp->FUN_004a19d0() || !m_pShaderGeometry ||
                        !::IsAcousticSpaceFormTypeAllowed((::Refr_C *)(m_pShaderGeometry), 1))
                        continue;
                    if (!kHits.FUN_0049c680(&pHitTmp, 0))
                    {
                        apRequest->kPos = kHitPos;
                        apRequest->kWorldPosition = kHitNormal;
                        apRequest->pTarget = pHitTmp;
                        FUN_004a1a70(apRequest);
                        reinterpret_cast<::ScriptList *>(&(kHits))->FUN_0076b660((unsigned int *)(::DecalAdd::DecalNode **)(&pHitTmp));
                    }
                }
            }
            reinterpret_cast<::NiTPointerListBaseRaw *>(&(kHits))->FUN_004ed900();
        }
        break;
    }
}

}

// 0x004a1a70   /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall (ret 4), bool return.
extern "C" char DAT_011c7d34[];
extern "C" char DAT_0101e420[];
extern "C" char DAT_0101e450[];
extern "C" char DAT_0101e468[];
extern "C" char DAT_0101e474[];
extern "C" char DAT_0101e47c[];
extern "C" char DAT_0101e484[];
extern "C" char DAT_0101e490[];

int FUN_00ec8a19(const char* text, const char* prefix, int len);

struct XObj
{
};
struct XItem
{
};
struct XList
{
    void* FUN_0043b1b0();
};
struct XObj3D
{
};
struct XNet
{
};
struct XNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    unsigned int FUN_0043b480();
    unsigned short FUN_004a1ff0();
    char pad4[0xac - 4];
    XList* m_ac;
};
struct XTopicInfo
{
    unsigned int FUN_0043b480();
};
struct XMenuTopic
{
};
struct XSetting
{
    unsigned char* Bool();
};
struct XGA
{
};

struct XRef
{
    char pad00[0x28];
    XNode* m28;
    char pad2c[0x0c];
    float m38;
    float m3c;
    char pad40[8];
    void* m48;
    char pad4c[0x10];
    float m5c;
    char pad60[0x12];
    unsigned char m72;
    char pad73[0x39];
    XList* m_ac;
};

struct XDoor;
struct XLoc
{
    XLoc(XDoor* d);
    ~XLoc();
    char pad[4];
};
struct XDoor
{
    XDoor(XObj* p, float f, XRef* r);
    char pad0[0x1a];
    unsigned char m1a;
    unsigned char m1b;
    char pad2[0x144 - 0x1c];
};
struct XNL
{
};
struct XMgr
{
    char pad0[4];
    unsigned char m4;
    char pad5[3];
    XNL m8;
    bool FUN_004a1a70(XRef* ref);
};

struct NiPoint3Sq : NiPoint3
{
};

// Checks conditions on ref and related nodes, may construct an XDoor, and calls FUN_0057c590 when ref->m48 is non-null.
// @fnv 0x004a1a70
bool XMgr::FUN_004a1a70(XRef* ref)
{
    const char* pName4;
    XNode* p9;
    XObj3D* objVal;
    XTopicInfo* info2;
    unsigned int i5;
    XNode* av_;
    XList* list;
    XObj* a5;
    XObj* b_;
    XNode* p4;
    XDoor* door3;
    XNode* hit2;
    bool foundVal;

    if (DAT_011c57e4 >= *((int *)&(::FUN_0043d4d0((int *)(((XSetting*)&(*reinterpret_cast<char *>(&::g_011c5890))))))))
    {
        if (((XSetting*)&(*reinterpret_cast<char *>(&::g_011c5904)))->Bool()[0])
            ::FUN_005b5e40();
        return false;
    }
    if (ref->m28)
    {
        pName4 = (const char*)((::XList *)(reinterpret_cast<::TESTopicInfoData *>((ref->m28))->GetLinkToList()))->FUN_0043b1b0();
        if (pName4 != 0 && (std::strncmp(pName4, DAT_0101e484, 10) == 0 || std::strncmp(pName4, DAT_0101e47c, 5) == 0 ||
                            std::strncmp(pName4, DAT_0101e474, 7) == 0 || std::strncmp(pName4, DAT_0101e468, 9) == 0 ||
                            FUN_00ec8a19(pName4, &DAT_0101e460, 5) == 0 || FUN_00ec8a19(pName4, DAT_0101e450, 15) == 0))
            return true;
        if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_011f4a20))), (::NiAVObject *)(ref->m28)) && !reinterpret_cast<::FUN_00456630_helper *>((ref->m28))->FUN_00456610())
        {
            p9 = ref->m28;
            if (p9 != 0)
            {
                objVal = ((::XObj3D *)(::fnv_0043b230::FUN_0043b230((const char *)(((::XNet *)(reinterpret_cast<::FUN_0050d100_shell *>((p9))->FUN_0050d100()))))));
                if (objVal != 0 && reinterpret_cast<::Fake_FUN_004a2020 *>((objVal))->GetFlag(0x1a))
                    return true;
            }
            info2 = ((::XTopicInfo *)(reinterpret_cast<::FUN_009611e0_shell *>((((XMenuTopic*)ref->m28)))->FUN_009611e0()));
            hit2 = 0;
            foundVal = false;
            if (info2 != 0)
            {
                for (i5 = 0; i5 < info2->FUN_0043b480(); i5++)
                {
                    av_ = ((::XNode *)(reinterpret_cast<::NiNode *>((info2))->GetAt(i5)));
                    if (av_ != 0)
                    {
                        if (::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(const void *)(&DAT_011c7d34), (const ::fnv_0045bad0::NiObject *)(av_)))
                        {
                            foundVal = true;
                            hit2 = av_;
                            break;
                        }
                    }
                }
            }
            else
            {
                return false;
            }
            if (foundVal && ref->m5c > ::_DAT_01012060)
            {
                list = hit2->m_ac;
                while (list != 0 && !reinterpret_cast<::ObsList *>((list))->FUN_004a4460())
                {
                    a5 = ((::XObj *)(::FUN_00559450((int *)(((::XItem *)((void *)(list)))))));
                    b_ = a5;
                    list = ((::XList *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                    NiPoint3 pt9;
                    reinterpret_cast<::FUN_004a0d30_shell *>((b_))->FUN_004a0d30(pt9);
                    float f9 = reinterpret_cast<::FUN_00507b20Class *>((b_))->FUN_00507b20();
                    NiPoint3 v7 = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(ref))->FUN_00439ef0((::NiPoint3 *)&(pt9), *(const ::NiPoint3 *)nullptr)));
                    v7 = (*(::NiPoint3Sq *)(::MultiplyComponents((::NiPoint3 *)&(v7), (const ::NiPoint3 *)&(v7), {})));
                    float qA;
                    if (ref->m38 > ref->m3c)
                        qA = ref->m38;
                    else
                        qA = ref->m3c;
                    double d = qA + f9;
                    d = d * d;
                    if (v7.x + v7.y + v7.z <= d / ref->m5c)
                        return false;
                }
            }
            DAT_011c57e4++;
            if (((XSetting*)&(*reinterpret_cast<char *>(&::g_011c5904)))->Bool()[0])
                ::FUN_005b5e40();
            door3 = new XDoor((XObj*)hit2, reinterpret_cast<::FUN_00450410_Class *>((((XGA*)&(*reinterpret_cast<char *>(&::g_011c5874)))))->FUN_00450410(), ref);
            p4 = ref->m28;
            if (p4->FUN_004a1ff0() > 0x3e8 && ((XSetting*)&(*reinterpret_cast<char *>(&::g_011c58a8)))->Bool()[0] && ref->m72)
            {
                door3->m1a = 1;
                door3->m1b = m4;
                m4 = 0;
            }
            if (ref->m48)
                reinterpret_cast<::FUN_0057c590_Class *>(&(m8))->FUN_0057c590((::Node *)&(const ::XLoc &)(door3));
        }
        else if (ref->m28->v3())
        {
            XNode* n2 = ref->m28;
            unsigned int _i2;
            XNode* child8;
            if (n2 != 0 && reinterpret_cast<::FUN_00456630_helper *>((n2))->FUN_00456610())
                return true;
            _i2 = 0;
            while (_i2 < n2->FUN_0043b480())
            {
                child8 = ((::XNode *)(reinterpret_cast<::NiNode *>((n2))->GetAt(_i2)));
                if (child8 != 0)
                {
                    ref->m28 = child8;
                    FUN_004a1a70(ref);
                }
                _i2++;
            }
        }
    }
    return true;
}

#include <string.h>
namespace fnv_004a2070 {
struct DObj;
struct DArg;
struct DPtr;
struct DProp;
struct DArray;
struct CStringProvider;
struct DVec
{
    float x, y, z;
};
struct DUpdate
{
    float time;
    bool updateControllers, multithreaded;
    unsigned unk08;
    DUpdate(float, bool, bool);
};
struct DObj
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual DObj* IsSceneNode();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual DObj* IsGeometry();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Virtual8c();
    virtual void Unk24();
    virtual void Unk25();
    virtual DObj* Virtual98(bool);
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk2a();
    virtual void Unk2b();
    virtual void Unk2c();
    virtual void Unk2d();
    virtual void Unk2e();
    virtual void Unk2f();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Virtualdc(DObj*, bool);
    void AssignFixedString(CStringProvider*);
};
struct CStringProvider
{
    const char* FUN_0043b1b0();
};
struct DPtr
{
    DObj* ptr;
    DPtr(DObj*);
    ~DPtr();
    DPtr& FUN_0066b0d0(DObj*);
};
struct DArray
{
    unsigned FUN_0043b480();
};
struct DProp
{
};
struct DList
{
};
struct DNode : DObj
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    DList* effects;
    unsigned unkb0;
    DNode(DArray*, bool);
};
struct DOneArg
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk40();
    virtual void Unk41();
    virtual void Unk42();
    virtual void Unk43();
    virtual void Unk44();
    virtual void Unk45();
    virtual void Unk46();
    virtual void Unk47();
    virtual void Unk48();
    virtual void Unk49();
    virtual void Unk50();
    virtual void Unk51();
    virtual void Unk52();
    virtual void Unk53();
    virtual void Unk54();
    virtual void Virtualdc(DObj*);
    void AssignFixedString(CStringProvider*);
};
struct DSkin : DOneArg
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    DSkin(unsigned);
};
struct DEffect : DObj
{
    unsigned unk4;
    unsigned unk8;
    unsigned unkc;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    DEffect(unsigned, float, DArg*, DObj*, DVec, DVec, float, float, unsigned);
};
struct DParentInterface
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unka();
    virtual void Unkb();
    virtual void Unkc();
    virtual void Unkd();
    virtual void Unke();
    virtual void Unkf();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Get(unsigned, DPtr&);
};
struct DParent
{
    unsigned unk0, unk4, unk8, unkc, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    DParentInterface interface30;
};
struct DArg
{
    DVec origin, normal;
    unsigned unk18, unk1c, unk20, unk24;
    DObj* object;
    DArray* children;
    DParent* parent;
    int tries;
    float scale;
    unsigned unk3c, unk40;
    float rotation;
    unsigned flags, unk4c;
    DOneArg* skin;
    unsigned unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
};
struct DSetting
{
    bool* FUN_00408d60();
};
extern unsigned DAT_011c7d34;
struct DManager
{
};
struct DWork
{
    bool FUN_004a2070(DArg*);
};
// Checks limits and object conditions, may create decal effects, and returns a status.
// @fnv 0x004a2070
bool DWork::FUN_004a2070(DArg* arg)
{
    if (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_004a2070::DSetting *>(&::g_011c5874)))))) <= 0.0)
        return false;
    if (::DAT_011c57e8 >= *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_004a2070::DSetting *>(&::g_011c5858)))))))
    {
        if (*(*reinterpret_cast<::ProcessLists *>(&::g_011c5904)).GetLifeStateControlFlag())
            ::FUN_005b5e40();
        return true;
    }
    DPtr original(0);
    if (arg->parent)
    {
        DPtr p(0);
        arg->parent->interface30.Get(0, p);
        DObj* parent = ((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(p))));
        if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<unsigned int *>(&::g_011f444c))), (::NiAVObject *)(parent)))
            original.FUN_0066b0d0(parent);
    }
    if (!((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(original)))))
        return false;
    if (arg->object)
    {
        const char* name = ((::fnv_004a2070::CStringProvider *)(reinterpret_cast<::TESTopicInfoData *>((arg->object))->GetLinkToList()))->FUN_0043b1b0();
        if (name)
        {
            if (!strncmp(name, "Decal", 5) || !strncmp(name, "FaceGen", 7) || !strncmp(name, "Bip01", 5) ||
                !strncmp(name, "BSFaceGen", 9) || !strncmp(name, "Hair", 4))
                return true;
        }
        if (reinterpret_cast<::FUN_00456630_helper *>((arg->object))->FUN_00456610())
            return true;
        if (arg->object->IsGeometry())
        {
            DObj* geometry = arg->object;
            if (arg->tries <= 0)
            {
                DProp* data = ((::fnv_004a2070::DProp *)(reinterpret_cast<::FUN_00a59d30_C *>((geometry))->FUN_00a59d30(3)));
                void* prop = reinterpret_cast<::AlchemyItem *>((geometry))->FUN_004030b0();
                if (data && prop)
                {
                    DPtr effect(0);
                    if (((void *)(::fnv_0043fad0::FUN_0043fad0((const char *)(geometry)))))
                    {
                        DArray* array = ((::fnv_004a2070::DArray *)(reinterpret_cast<::FUN_009611e0_shell *>((arg->object))->FUN_009611e0()));
                        DNode* selected = 0;
                        for (unsigned i = 0; i < array->FUN_0043b480(); ++i)
                        {
                            DObj* child = ((::fnv_004a2070::DObj *)(reinterpret_cast<::NiNode *>((array))->GetAt(i)));
                            if (child && ::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(const void *)(&DAT_011c7d34), (const ::fnv_0045bad0::NiObject *)(child)))
                            {
                                selected = (DNode*)child;
                                break;
                            }
                        }
                        if (!selected)
                            selected = new DNode(array, true);
                        else
                        {
                            if (((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((selected))->FUN_00453470())) >= (unsigned)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_004a2070::DSetting *>(&::g_011c589c)))))))
                                return true;
                        }
                        ++::DAT_011c57e8;
                        if (*(*reinterpret_cast<::ProcessLists *>(&::g_011c5904)).GetLifeStateControlFlag())
                            ::FUN_005b5e40();
                        DPtr decal(new DEffect(arg->flags, reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_004a2070::DSetting *>(&::g_011c5874))))->FUN_00450410(), arg, geometry, arg->origin,
                                               arg->normal, arg->scale, arg->rotation, arg->unk6c));
                        bool accepted = false;
                        ((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(decal))))->Virtual8c();
                        if (((std::intptr_t)(reinterpret_cast<::TESQuest *>((((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(decal))))))->GetScriptLocalData())) > 0)
                        {
                            if (!arg->skin)
                            {
                                arg->skin = new DSkin(0);
                                ::AssignFixedString((char *)(arg->skin), (std::intptr_t)(((::fnv_004a2070::CStringProvider *)(::FUN_004a2c60()))), {});
                                selected->Virtualdc((DObj*)arg->skin, true);
                                ++::DAT_011c57f0;
                                if (*(*reinterpret_cast<::ProcessLists *>(&::g_011c5904)).GetLifeStateControlFlag())
                                    ::FUN_005b5e40();
                            }
                            arg->skin->Virtualdc(((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(decal))))->Virtual98(true));
                            reinterpret_cast<::fnv_004a2c00::FUN_004a2c00_shell *>((((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(decal))))))->AssignGo((DObj*)arg->skin);
                            reinterpret_cast<::fnv_00631540::TargetClass *>((selected->effects))->FUN_00631540((const ::NiPointer< ::NiNode> &)((const ::fnv_004a2070::DPtr &)(((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(decal)))))));
                            DUpdate update(0.0f, false, false);
                            reinterpret_cast<::FUN_00a59c60_cls *>((selected))->FUN_00a59c60((std::intptr_t)&(update));
                            reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::fnv_004a2070::DManager *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(::fnv_004a2070::DObj *)(((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(decal))))));
                            effect.FUN_0066b0d0(((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(decal)))));
                        }
                        else
                            return true;
                    }
                    if (arg->children)
                    {
                        DObj* a = 0;
                        unsigned found = 0;
                        while (found < arg->children->FUN_0043b480() && !a)
                        {
                            DObj* child = ((::fnv_004a2070::DObj *)(reinterpret_cast<::NiNode *>((arg->children))->GetAt(found)));
                            if (child)
                            {
                                if (child->IsGeometry())
                                    a = child;
                                else if (child->IsSceneNode())
                                {
                                    DArray* uiIndex = (DArray*)child;
                                    unsigned pArray = 0;
                                    while (pArray < uiIndex->FUN_0043b480() && !a)
                                    {
                                        DObj* candidate = ((::fnv_004a2070::DObj *)(reinterpret_cast<::NiNode *>((uiIndex))->GetAt(pArray)));
                                        if (candidate && candidate->IsGeometry())
                                            a = candidate;
                                        ++pArray;
                                    }
                                }
                            }
                            ++found;
                        }
                        if (a)
                        {
                            DProp* data2 = ((::fnv_004a2070::DProp *)(reinterpret_cast<::FUN_00a59d30_C *>((a))->FUN_00a59d30(3)));
                            void* prop2 = reinterpret_cast<::AlchemyItem *>((a))->FUN_004030b0();
                            if (data2 && prop2)
                            {
                                DProp* shader = ::FUN_004a2c20((::BGSTerrainManager *)(data2)) ? data2 : 0;
                                if (shader)
                                {
                                    DPtr additional(0);
                                    if (((void *)(::fnv_0043fad0::FUN_0043fad0((const char *)(geometry)))))
                                    {
                                        DEffect* pRawEffect =
                                            new DEffect(arg->flags, reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::fnv_004a2070::DSetting *>(&::g_011c5874))))->FUN_00450410(), arg, a, arg->origin,
                                                        (*(::fnv_004a2070::DVec *)(reinterpret_cast<::P3 *>((void *)&(arg->normal))->FUN_004a0bd0({}))), 1.0f, arg->rotation, arg->unk6c);
                                        additional.FUN_0066b0d0(pRawEffect);
                                        pRawEffect->Virtual8c();
                                    }
                                    if (((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(additional)))))
                                        reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::fnv_004a2070::DManager *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(::fnv_004a2070::DObj *)(((::fnv_004a2070::DObj *)(::FUN_00559450((int *)&(additional))))));
                                }
                            }
                        }
                    }
                }
                if (arg->tries >= 0)
                    return false;
                else
                    return true;
            }
            else
            {
                --arg->tries;
                return true;
            }
        }
        else if (arg->object->IsSceneNode())
        {
            DArray* pArray = (DArray*)arg->object;
            unsigned uiIndex = 0;
            while (uiIndex < pArray->FUN_0043b480())
            {
                DObj* child = ((::fnv_004a2070::DObj *)(reinterpret_cast<::NiNode *>((pArray))->GetAt(uiIndex)));
                if (child)
                {
                    arg->object = child;
                    bool result = FUN_004a2070(arg);
                    if (!result && arg->object)
                    {
                        if (arg->skin)
                        {
                            DArray* array = ((::fnv_004a2070::DArray *)(reinterpret_cast<::FUN_009611e0_shell *>((arg->object))->FUN_009611e0()));
                            DNode* selected = 0;
                            for (unsigned d = 0; d < array->FUN_0043b480(); ++d)
                            {
                                DObj* entry = ((::fnv_004a2070::DObj *)(reinterpret_cast<::NiNode *>((array))->GetAt(d)));
                                if (entry && ::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(const void *)(&DAT_011c7d34), (const ::fnv_0045bad0::NiObject *)(entry)))
                                {
                                    selected = (DNode*)entry;
                                    break;
                                }
                            }
                            if (selected)
                                selected->Virtualdc((DObj*)arg->skin, true);
                        }
                        return false;
                    }
                }
                ++uiIndex;
            }
        }
    }
    return true;
}
}  // namespace fnv_004a2070



struct AlignedVector_o2_od_oy_noo2
{
    __m128 value;
    void FUN_004a3f10(const AlignedVector_o2_od_oy_noo2& source);
};

// @fnv 0x004a3f10
void AlignedVector_o2_od_oy_noo2::FUN_004a3f10(const AlignedVector_o2_od_oy_noo2& source)
{
    value = source.value;
}

struct HostV;

struct ObjV
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(), v32(), v33(),
        v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49(), v50(), v51(), v52();
    virtual void Attach(HostV* pkHost);
    char pad04[0x2c];
    unsigned int m_uiValue1;
    bool TestFlag(unsigned int uiMask) const
    {
        return (m_uiValue1 & uiMask) != 0;
    }
};

struct CtrlV
{
    char pad[0x28];
    int m_i28;
    bool IsEmpty() const
    {
        return m_i28 == 0;
    }
};

struct HostV
{
    char pad[0x8c];
    void* m_pv8c;
    int m_iFadeIndex;
    char pad94[0x2c];
    CtrlV* m_pkCtrl;
    bool HasX() const
    {
        return (bool)m_pv8c;
    }
    void FUN_00c4ee90(ObjV* pkObj);
};

// @fnv 0x00c4ee90
void HostV::FUN_00c4ee90(ObjV* pkObj)
{
    if (m_iFadeIndex != 2 && m_iFadeIndex != 1)
    {
        ObjV* pkTmp = pkObj;
        if (pkTmp->TestFlag(0x1000))
        {
            if (!pkTmp->TestFlag(0x100000))
                pkObj->Attach(this);
        }
        else if (!m_pkCtrl || m_pkCtrl->IsEmpty() || m_iFadeIndex == 3)
        {
            if (pkObj->TestFlag(0x800) || !HasX())
                pkObj->Attach(this);
            else
                reinterpret_cast<::WorkerS694a0 *>(this)->FUN_00a694e0((::NiAVObject *)(pkObj));
        }
        else if (pkObj->TestFlag(0x800) || ((!m_pkCtrl || m_pkCtrl->IsEmpty()) && !HasX()))
        {
            pkObj->Attach(this);
        }
        else
        {
            std::intptr_t iState = ((std::intptr_t)(reinterpret_cast<::NavEntryOwner *>((m_pkCtrl))->BuildEntryValueArray()));
            if (reinterpret_cast<::TreeEvaluator *>((m_pkCtrl))->FUN_00c491a0((::TreeQuery *)(pkObj)))
                pkObj->Attach(this);
            reinterpret_cast<::fnv_00c49100::ActorTable *>((m_pkCtrl))->SetActorList((int *)(iState));
        }
    }
    else if (m_iFadeIndex == 1)
    {
        pkObj->Attach(this);
    }
}

class NiCullingProcess;

class NiNodeX;

class NiObj
{
  public:
    virtual void vf00();
    virtual void DeleteThis();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c(NiNodeX* n);
    long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class NiNodeX : public NiObj
{
  public:
};

class NiAVObject
{
  public:
};

class SceneMgr;

class SceneMgr
{
  public:
    int unk00;
    int unk04;
    NiNodeX* unk08;
};

inline NiNodeX* GetRoot()
{
    SceneMgr* m = (*reinterpret_cast<::SceneMgr * *>(&::NiRenderer::ms_pRenderer));
    int u1;
    int u2;
    return m->unk08;
}

class Accum : public NiObj
{
};

class AccPtr
{
  public:
    NiObj* m_pObject;
    __forceinline AccPtr(NiObj* o = 0)
    {
        m_pObject = o;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~AccPtr()
    {
        int u3;
        int u4;
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    __forceinline NiObj* operator->()
    {
        return m_pObject;
    }
    __forceinline operator NiObj*()
    {
        return m_pObject;
    }
    AccPtr& FUN_0066b0d0(NiNodeX* p);
};

class NiCullingProcess
{
  public:
    virtual void vf00();
    int unk04;
    int unk08;
    NiNodeX* unk0c;
    void FUN_00c4f070(NiNodeX* a, NiAVObject* b, int c);
};

// @fnv 0x00c4f070
void NiCullingProcess::FUN_00c4f070(NiNodeX* a, NiAVObject* b, int c)
{
    if (!a || !b)
        return;
    unk0c = a;
    reinterpret_cast<::S694a0 *>(this)->FUN_00a694a0((char*)unk0c + 0xdc);
    int saved = 0;
    if (c)
    {
        saved = unk08;
        unk08 = c;
    }
    AccPtr sp;
    if (!unk08)
    {
        reinterpret_cast<::FUN_00c46270_Class *>(&(sp))->AssignRefCounted((*(const ::FUN_00c46270_Class *)((char*)this + 0xc4)));
        if (!sp)
            sp.FUN_0066b0d0(GetRoot());
        if (sp)
            sp->vf8c(a);
    }
    reinterpret_cast<::S_00a59e00 *>((b))->FUN_00a59e00((::S_00a59e00_Arg *)&(*this));
    if (c)
        unk08 = saved;
}

class NiFixedString
{
  public:
    const char* m_kHandle;
    operator const char*() const
    {
        return m_kHandle;
    }
};

class NiGeometry_ob1
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    NiFixedString m_kName;
    const char* GetName() const
    {
        return m_kName;
    }
};

class NiAccumulator
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual bool RegisterObject(NiGeometry_ob1* pkGeom);
};

template <class T> class NiPtr
{
  public:
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

class BSCullingProcess_ob1 : public NiCullingProcess
{
  public:
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAc, unkB0, unkB4, unkB8, unkBc;
    int unkC0;
    NiPtr<NiAccumulator> m_acRendererDataA;

    void FUN_00c4f1d0(NiGeometry_ob1& kVisible);
};

// @fnv 0x00c4f1d0
void BSCullingProcess_ob1::FUN_00c4f1d0(NiGeometry_ob1& kVisible)
{
    bool bRegistered = false;
    if (m_acRendererDataA)
    {
        if (m_acRendererDataA->RegisterObject(&kVisible))
            bRegistered = true;
    }
    if (!bRegistered)
    {
        ::FUN_00a29680();
    }
}

#include "generated/data/fallout_shared/bgsdecalmanager.inc"
