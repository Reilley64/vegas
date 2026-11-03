#ifndef FNV_NIMATRIX3_H
#define FNV_NIMATRIX3_H

#include "layout_support.h"
#include "NiPoint3.h"
class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];  // +0x0
    ThreeByThreeMatrix()
    {}
    NiPoint3 operator*(const NiPoint3& point) const;
    void SetZRotation(float angle);
    void MakeAxisAngleRotation(float angle, float x, float y, float z);
    ThreeByThreeMatrix Transpose();
    void GetRow(unsigned int row, NiPoint3& point);
};
#endif
