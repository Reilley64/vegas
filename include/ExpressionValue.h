#ifndef FNV_EXPRESSIONOPERAND_H
#define FNV_EXPRESSIONOPERAND_H

#include "layout_support.h"
class ExpressionValue
{
  public:
    char Type;  // +0x0
    unsigned char layoutPadding1;
    unsigned short layoutPadding2;
    unsigned int layoutPadding4;
    union
    {
        long m_lIntegerValue;
        double m_dFloatingPointValue;
    };  // +0x8
};
#endif
