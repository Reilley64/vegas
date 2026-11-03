#ifndef FNV_CEXPRESSION_H
#define FNV_CEXPRESSION_H

#include "fnv/symbols_00559000.h"
#include "layout_support.h"
#include "ExpressionValue.h"
class ExpressionEvaluator
{
  public:
    EXPRESSION_ERROR m_eExpressionError;               // +0x0
    char m_sExpression[512];                           // +0x4
    char m_sExpressionBuffer[512];                     // +0x204
    Stack<ExpressionOperator, 64> m_kOperatorStack;  // +0x404
    Stack<ExpressionValue, 32> m_kOperandStack;      // +0x508
    ExpressionEvaluator();
    ~ExpressionEvaluator();
    double Eval(const char* data, TESObjectREFR* reference, TESObjectREFR* container, Script* script,
                ScriptLocals* locals, int length, bool skip);
    EXPRESSION_ERROR ExpressionError();
};
#endif
