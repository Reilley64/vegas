// fallout_shared/pathfinding/pathingavoidnode.cpp: NavMesh, NavMeshTriangleReference, AvoidNodeList (4 functions)

#include "fnv/decl/FUN_004941c0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00558dd0_class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "pathingavoidnode_decls.h"
// @fnv 0x005582f0
NavMeshTriangle* NavMesh::GetTriangle(unsigned short index)
{
    return ((::NavMeshTriangle *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>(&(triangles))->FUN_00558dd0(index)));
}
// @fnv 0x006a78d0
NavMeshTriangle* NavMeshTriangleReference::FUN_006a78d0() const
{
    return mesh->GetTriangle(triangle);
}

class Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
class SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
class NiQuaternion;
class TESForm;
class TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct PathingAvoidanceNode
{
    float GetAvoidanceAtPoint(NiPoint3*);
    int GetType();
    void* GetPoint1();
    void* GetPoint2();
    float GetRadius();
    float GetCost();
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    char m_kLocation[12];
    char TwoComponentVector[12];
    float fRadius;
    float m_fPathingCostCur;
    int eType;
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
struct FUN_006dc910_shell : public PathingAvoidanceNode
{
    void LoadPathingAvoidNode(BGSLoadFormBuffer*);
};

struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    void ReadTypedData(void*, unsigned int);
};

// Reads a type byte, two floats and a 12-byte block from the load buffer, plus a second 12-byte block when the type is 1.
// @fnv 0x006dc910
void FUN_006dc910_shell::LoadPathingAvoidNode(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned char ctype = 0;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ctype), 1);
    eType = ctype;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&fRadius), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fPathingCostCur), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_kLocation), 12);
    if (eType == 1)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&TwoComponentVector), 12);
    }
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3 operator+(const NiPoint3&) const;
    NiPoint3 operator*(float) const;
    NiPoint3& operator+=(const NiPoint3&);
public:
    float GetLengthSquared();
public:
    static const ::NiPoint3 ZERO;
};

struct AvoidanceVectorData
{
    NiPoint3 point1;
    NiPoint3 point2;
    float fRadius;
    float m_fPathingCostCur;
    int eType;
};

struct AvoidNodeList
{
    float FUN_006dc9f0(const NiPoint3& point, NiPoint3& outDir);
};

// @fnv 0x006dc9f0
float AvoidNodeList::FUN_006dc9f0(const NiPoint3& point, NiPoint3& outDir)
{
    float fValueSum = 0.0f;
    outDir = ::NiPoint3::ZERO;
    float fCostSum = 0.0f;
    unsigned int count8 = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
    if (count8 > 0)
    {
        for (unsigned int aI = 0; aI < count8; aI++)
        {
            AvoidanceVectorData* pNode = ((::AvoidanceVectorData *)(reinterpret_cast<::S3e60 *>(this)->FUN_006a1400(aI)));
            float fCost3 = pNode->m_fPathingCostCur;
            NiPoint3 closestPoint = pNode->point1;
            if (pNode->eType == 1)
            {
                NiPoint3 segmentDir = pNode->point2 - pNode->point1;
                NiPoint3 toPoint = point - pNode->point1;
                float fDot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(toPoint))->DotProduct((void *)&(segmentDir));
                if (fDot < 0.0)
                {
                    closestPoint = pNode->point1;
                }
                else if (fDot > reinterpret_cast<::TESCombatStyle *>((void *)&(segmentDir))->UpdateCombatStyle())
                {
                    closestPoint = pNode->point2;
                }
                else
                {
                    float fSegLen = reinterpret_cast<::NiPoint3 *>((void *)&(segmentDir))->GetLengthSquared();
                    closestPoint = pNode->point1 + reinterpret_cast<::Point3_0053d280 *>((void *)(void *)&(const ::NiPoint3 &)((segmentDir * fDot)))->FUN_0053d280(fSegLen);
                }
            }
            reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(outDir))->FUN_0063c8a0((void *)&(const ::NiPoint3 &)(closestPoint * fCost3));
            fValueSum += pNode->fRadius;
            fCostSum += fCost3;
        }
        reinterpret_cast<::FUN_004941c0_shell *>(&(outDir))->ScaleByInverse(fCostSum);
    }
    return fValueSum;
}
