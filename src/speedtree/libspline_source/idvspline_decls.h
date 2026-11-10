// speedtree/libspline_source/idvspline_decls.h: declares Script, IdvSplineToken, IdvSplineInputCursor
#ifndef IDVSPLINE_DECLS_H
#define IDVSPLINE_DECLS_H

#include <stddef.h>
#include <cstdlib>
#include <cstring>
#include "fnv/decl/FNVTokenParser.h"
#include "fnv/decl/FUN_00594c80_cls.h"
#include "fnv/decl/FUN_00594cd0_Class.h"
#include "fnv/decl/FUN_00594d20_Class.h"
#include "fnv/decl/FUN_00594d40_class.h"
#include "fnv/decl/Holder5934d0.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
class TESObjectREFR;
struct ScriptLocals;
class Script
{
  public:
    static bool GetValue(double&, const char*, unsigned int&, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                         bool);
};
template <class T, unsigned int Capacity> class Stack
{
  public:
    T items[Capacity];
    int top;
};
enum EXPRESSION_ERROR
{
    EXPRESSION_ERROR_ERROR_EXPRESSION_NOERROR = 0,
    EXPRESSION_ERROR_ERROR_EXPRESSION_OUTOFMEMORY = 1,
    EXPRESSION_ERROR_ERROR_EXPRESSION_STACKOVERFLOW = 2,
    EXPRESSION_ERROR_ERROR_EXPRESSION_STACKUNDERFLOW = 3,
    EXPRESSION_ERROR_ERROR_EXPRESSION_DIVIDEBYZERO = 4,
    EXPRESSION_ERROR_ERROR_EXPRESSION_SYNTAX = 5,
    EXPRESSION_ERROR_ERROR_EXPRESSION_BADOBJECTPOINTER = 6,
    EXPRESSION_ERROR_ERROR_EXPRESSION_COUNT = 7,
};
enum ExpressionOperator
{
    EXPRESSION_OPERATORS_EXP_LEFTPAREN = 0,
    EXPRESSION_OPERATORS_EXP_RIGHTPAREN = 1,
    EXPRESSION_OPERATORS_EXP_AND = 2,
    EXPRESSION_OPERATORS_EXP_OR = 3,
    EXPRESSION_OPERATORS_EXP_LESSEQUAL = 4,
    EXPRESSION_OPERATORS_EXP_LESS = 5,
    EXPRESSION_OPERATORS_EXP_GREATEREQUAL = 6,
    EXPRESSION_OPERATORS_EXP_GREATER = 7,
    EXPRESSION_OPERATORS_EXP_EQUAL = 8,
    EXPRESSION_OPERATORS_EXP_NOTEQUAL = 9,
    EXPRESSION_OPERATORS_EXP_SUBTRACT = 10,
    EXPRESSION_OPERATORS_EXP_ADD = 11,
    EXPRESSION_OPERATORS_EXP_MULTIPLY = 12,
    EXPRESSION_OPERATORS_EXP_DIVIDE = 13,
    EXPRESSION_OPERATORS_EXP_MODULUS = 14,
    EXPRESSION_OPERATORS_EXP_UNARYMINUS = 15,
    EXPRESSION_OPERATORS_EXP_COUNT = 16,
};

class ExpressionValue
{
  public:
    char Type;
    union
    {
        long m_lIntegerValue;
        double m_dFloatingPointValue;
    };
};

// The stack helpers have no identified PC names in the identity catalog.
template <> class Stack<ExpressionValue, 32>
{
  public:
    ExpressionValue items[32];
    int top;
    void AddEntry(ExpressionValue value);
};

class ExpressionEvaluator
{
  public:
    EXPRESSION_ERROR m_eExpressionError;
    char m_sExpression[512];
    char m_sExpressionBuffer[512];
    Stack<ExpressionOperator, 64> m_kOperatorStack;
    Stack<ExpressionValue, 32> m_kOperandStack;
    double Eval(const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, int, bool);
};
struct IdvSplineToken
{
    ExpressionOperator type;
    char* text;
};
struct IdvSplineInputCursor
{
    int consumed;
    const char* data;
};
#endif
