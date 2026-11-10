// sdk/facegen/matrixvt_decls.h: declares FaceGenCoordinateValue, FR2MatrixVTCData, FaceGenCoordinateBasis
#ifndef ARMY_LUNA_2061_MATRIXVT_DECLS_H
#define ARMY_LUNA_2061_MATRIXVT_DECLS_H


#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/S_0060b3f0.h"
#include "fnv/decl/V_006578b0.h"
#include "fnv/symbols_00aaf000.h"
#include "matrixvt_types_FR2MatrixVTC_float_.h"
struct FaceGenCoordinateValue
{
  public:
    unsigned int value;
    unsigned int layoutPadding;
};

class FR2MatrixVTCData
{
  public:
    float* first;
    float* last;
    float* end;
    unsigned int layoutPadding0;
    unsigned int layoutPadding1;
    unsigned int layoutPadding2;
};

class FaceGenCoordinateBasis
{
  public:
    FaceGenCoordinateValue FUN_0060b370(unsigned int row, unsigned int col);
};

template <class T> struct FaceGenMatrix;

template <> struct FaceGenMatrix<float> : public FaceGenCoordinateBasis
{
  public:
    FR2MatrixVTCData data;
    unsigned int m_uiRowCount;
    unsigned int m_uiColumnCount;

    FaceGenMatrix(unsigned int rows, unsigned int cols);
    FaceGenMatrix(const FaceGenMatrix<float>& rhs);
    ~FaceGenMatrix();

    FaceGenMatrix<float>& operator=(const FaceGenMatrix<float>& rhs);
    FaceGenMatrix<float> operator*(const FaceGenMatrix<float>& rhs);
    float GetTrace();

    void FUN_00658f30(const FaceGenMatrix<float>& rhs);
};

float __cdecl SquareFloat(float value);

#endif
