// gamebryo2.2/corelibs/nimain/console/nimatrix3_decls.h: declares NiPoint3, NiPlane, NiAVObject, NiTransform, NiPosData
#ifndef FNV_NIMATRIX3_DECLS_H
#define FNV_NIMATRIX3_DECLS_H


#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00416000.h"
#include "fnv/symbols_01017000.h"
struct NiPoint3
{
  public:
    NiPoint3();
    NiPoint3 operator+(const NiPoint3&) const;
    float x;
    float y;
    float z;
};

struct ThreeByThreeMatrix
{
  public:
    float m_afEntries[9];
    ThreeByThreeMatrix();
    ThreeByThreeMatrix(const NiPoint3&, const NiPoint3&, const NiPoint3&);
    ThreeByThreeMatrix Transpose();
    bool Inverse(ThreeByThreeMatrix&);
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
    NiPoint3 operator*(const NiPoint3&) const;

    void SetYRotation(float);
    void MakeAxisAngleRotation(float, float, float, float);
    void GetRow(unsigned int row, NiPoint3& point);
    bool operator==(const ThreeByThreeMatrix& matrix) const;
    ThreeByThreeMatrix operator+(const ThreeByThreeMatrix& matrix) const;
};

class InventoryStackRecord;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
};

struct NiPlane
{
  public:
    NiPoint3 normal;
    float constant;
    NiPlane(const NiPoint3&, float);
};
class NiAVObject
{
  public:
    char pad[0x34];
    ThreeByThreeMatrix rotation;
    char extra[0x10];
    ThreeByThreeMatrix worldRotation;
    NiPoint3 GetWorldTranslation();
    void SetLocalRotation(float, float, float, float);
};
class NiTransform
{
  public:
    ThreeByThreeMatrix rotation;
    NiPoint3 translation;
    float scale;
    NiTransform();
    NiTransform operator*(const NiTransform&) const;
};
class NiPosData
{
  public:
    static NiPoint3* ComputePositionAtTime(NiPoint3*, float, const NiPoint3*);
    static NiPoint3 ComputePositionAtTime(float, const NiPoint3&);
};
#endif
