#ifndef ARMY_LUNA_2061_MATRIXVT_HPP
#define ARMY_LUNA_2061_MATRIXVT_HPP


#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/S_0060b3f0.h"
#include "fnv/decl/V_006578b0.h"
#include "fnv/symbols_00aaf000.h"
#include "matrixvt_decls.h"
#include <string.h>


// @fnv 0x006581e0
FaceGenMatrix<float>& FaceGenMatrix<float>::operator=(const FaceGenMatrix<float>& rhs)
{
    if (this == &rhs)
        return *this;

    m_uiRowCount = rhs.m_uiRowCount;
    m_uiColumnCount = rhs.m_uiColumnCount;
    reinterpret_cast<::S_0060b3f0 *>(&(data))->FUN_0060b3f0(m_uiRowCount * m_uiColumnCount);
    memcpy(((float *)(reinterpret_cast<::V_006578b0 *>((void *)this)->FUN_006578b0(0))), ((float *)(reinterpret_cast<::V_006578b0 *>((void *)&(rhs))->FUN_006578b0(0))), m_uiRowCount * m_uiColumnCount * sizeof(float));
    return *this;
}

// @fnv 0x006588a0
float FaceGenMatrix<float>::GetTrace()
{
    float result = 0.0f;
    unsigned int row = 0;
    for (; row < m_uiRowCount; ++row)
    {
        unsigned int col = 0;
        for (; col < m_uiColumnCount; ++col)
        {
            result += SquareFloat(*((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(FUN_0060b370(row, col)))->FUN_00629ab0({}))));
        }
    }
    return result;
}

// @fnv 0x00658360
FaceGenMatrix<float> FaceGenMatrix<float>::operator*(const FaceGenMatrix<float>& rhs)
{
    unsigned int k;
    {
    unsigned int i;
    if (m_uiColumnCount == rhs.m_uiRowCount)
    {
    }
    else
    {
        ::ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x113);
    }

    FaceGenMatrix<float> result(m_uiRowCount, rhs.m_uiColumnCount);
    i = 0;
    for (; i < m_uiRowCount; ++i)
    {
        unsigned int j = 0;
        for (; j < rhs.m_uiColumnCount; ++j)
        {
            *const_cast<float*>(((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(result.FUN_0060b370(i, j)))->FUN_00629ab0({})))) = 0.0f;

            k = 0;
            for (; k < m_uiColumnCount; ++k)
            {
                *const_cast<float*>(((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(result.FUN_0060b370(i, j)))->FUN_00629ab0({}))))
                    += *((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(FUN_0060b370(i, k)))->FUN_00629ab0({})))
                     * *((const float *)&(reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::FaceGenCoordinateValue &)(const_cast<FaceGenMatrix<float>&>(rhs).FUN_0060b370(k, j)))->FUN_00629ab0({})));
            }
        }
    }
    return result;
    }
}

#endif
