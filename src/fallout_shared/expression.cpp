// fallout_shared/expression.cpp: ExpressionConverter (10 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNVTokenParser.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00594d40_class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00594000.h"
#include "fnv/symbols_0118c000.h"
#include "expression_decls.h"
#include "ExpressionEvaluator.h"

// Initializes the character and operand stacks and sets the error state to zero.
// @fnv 0x00593490
ExpressionEvaluator::ExpressionEvaluator()
{
    ::FUN_00594b60((void *)(reinterpret_cast<ExpressionCharStackInit*>(&m_kOperatorStack)));
    ::InitStack((::Dummy_00594c60 *)(reinterpret_cast<ExpressionOperandStackInit*>(&m_kOperandStack)));
    m_eExpressionError = static_cast<EXPRESSION_ERROR>(0);
}

// @fnv 0x00594b60
void* __fastcall FUN_00594b60(void* pThis)
{
    *(int*)((char*)pThis + 0x100) = -1;
    return pThis;
}

struct Dummy_00594c60
{
    char pad[0x200];
    int top;
    Dummy_00594c60* __thiscall ctor();
};

__declspec(noinline) Dummy_00594c60* __thiscall Dummy_00594c60::ctor()
{
    this->top = -1;
    return this;
}

// @fnv 0x00594c60
int __fastcall InitStack(Dummy_00594c60* _this)
{
    _this->top = -1;
    return (int)_this;
}

struct FUN_00594b80_shell
{
    void PushInt(int arg);
};

// Increments the counter at index 0x40 and stores arg at the slot indexed by the new counter value.
// @fnv 0x00594b80
void FUN_00594b80_shell::PushInt(int aiValue)
{
    ++((int*)this)[0x40];
    ((int*)this)[((int*)this)[0x40]] = aiValue;
}

struct FUN_00594c40_shell
{
    void ResetIndex();
};

// @fnv 0x00594c40
void FUN_00594c40_shell::ResetIndex()
{
    *(int*)((char*)this + 0x100) = 0xffffffff;
}

struct Interface
{
};
struct Holder5934d0
{
    int err;
    void SetError(int);
};
// @fnv 0x005934d0
void Holder5934d0::SetError(int aiErrorCode)
{
    err = aiErrorCode;
    ::FUN_0040fbe0();
}

struct FUN_00594c00_shell
{
    int FUN_00594c00();
};

// @fnv 0x00594c00
int FUN_00594c00_shell::FUN_00594c00()
{
    return *(int*)((char*)this + 0x100) == -1;
}

struct FUN_00594c20_shell
{
    char pad[0x100];
    int m_100;
    bool FUN_00594c20();
};

// @fnv 0x00594c20
bool FUN_00594c20_shell::FUN_00594c20()
{
    return m_100 + 1 == 0x40;
}

struct S_00594bc0
{
    int unk00[64];
    int unk100;

    int FUN_00594bc0();
};

// Returns the int at unk00 indexed by unk100, then decrements unk100.
// @fnv 0x00594bc0
int S_00594bc0::FUN_00594bc0()
{
    return unk00[unk100--];
}

struct OperatorInfo
{
    signed char priority;
    char text[7];
};
extern OperatorInfo DAT_0118cad4[];
struct OpStack
{
    int items[64];
    int top;
    int pop();
    void push(int);
};
struct OperandValue
{
    int type;
    int metadata;
    double value;
};
struct OperandStack
{
    OperandValue items[32];
    int top;
};
struct ExpressionConverter
{
    int error;
    char infix[512];
    char postfix[512];
    OpStack operators;
    OperandStack operands;
    char* ConvertToPostfix(const char*, unsigned int*);
};
// Converts the infix expression in data to postfix in postfix using an operator stack, returning postfix and setting length, or 0 on error.
// @fnv 0x00593500
char* ExpressionConverter::ConvertToPostfix(const char* pInfix, unsigned int* puiLength)
{
    char token[64];
    {
        int count2 = 0;
        bool operand5;
        error = 0;
        reinterpret_cast<::FUN_00594c40_shell *>(&(operators))->ResetIndex();
        reinterpret_cast<::FUN_00594d40_class *>(&(operands))->ResetField();
        char* input = infix;
        char bracket = '(';
        *input = bracket;
        input++;
        ::__memcpy(input, pInfix, *puiLength);
        input += *puiLength;
        bracket = ')';
        *input = bracket;
        input++;
        *input = 0;
        input++;
        input = infix;
        char* output2 = postfix;
        *output2 = 0;
        operand5 = false;
        int kind_;
        do
        {
            kind_ = 16;
            count2 = reinterpret_cast<::FNVTokenParser *>(this)->ParseToken(&input, token, (unsigned int *)(int *)(&kind_), 0, (int *)(0));
            if (count2)
            {
                if (kind_ < 16)
                {
                    switch (kind_)
                    {
                    case 0:
                        if (!((int)(reinterpret_cast<::FUN_00594c20_shell *>(&(operators))->FUN_00594c20())))
                            reinterpret_cast<::FUN_00594b80_shell *>(&(operators))->PushInt(0);
                        else
                        {
                            reinterpret_cast<::Holder5934d0 *>(this)->SetError(2);
                            return 0;
                        }
                        break;
                    case 1:
                        if (!reinterpret_cast<::FUN_00594c00_shell *>(&(operators))->FUN_00594c00())
                        {
                            int popped;
                            while (popped = reinterpret_cast<::S_00594bc0 *>(&(operators))->FUN_00594bc0())
                            {
                                *output2 = ' ';
                                output2++;
                                int textLength = ::FUN_0044a670(DAT_0118cad4[popped].text);
                                ::__memcpy(output2, DAT_0118cad4[popped].text, textLength);
                                output2 += textLength;
                            }
                        }
                        else
                        {
                            reinterpret_cast<::Holder5934d0 *>(this)->SetError(5);
                            return 0;
                        }
                        break;
                    case 10:
                        if (!operand5)
                            kind_ = 15;
                    default:
                        while (!reinterpret_cast<::FUN_00594c00_shell *>(&(operators))->FUN_00594c00())
                        {
                            int popped = reinterpret_cast<::S_00594bc0 *>(&(operators))->FUN_00594bc0();
                            if (DAT_0118cad4[popped].priority >= DAT_0118cad4[kind_].priority)
                            {
                                *output2 = ' ';
                                output2++;
                                int textLength = ::FUN_0044a670(DAT_0118cad4[popped].text);
                                ::__memcpy(output2, DAT_0118cad4[popped].text, textLength);
                                output2 += textLength;
                            }
                            else
                            {
                                reinterpret_cast<::FUN_00594b80_shell *>(&(operators))->PushInt(popped);
                                break;
                            }
                        }
                        if (!((int)(reinterpret_cast<::FUN_00594c20_shell *>(&(operators))->FUN_00594c20())))
                            reinterpret_cast<::FUN_00594b80_shell *>(&(operators))->PushInt(kind_);
                        else
                        {
                            reinterpret_cast<::Holder5934d0 *>(this)->SetError(2);
                            return 0;
                        }
                        break;
                    }
                }
                else
                {
                    *output2 = ' ';
                    output2++;
                    ::__memcpy(output2, token, count2);
                    output2 += count2;
                }
            }
            if (kind_ == 16)
                operand5 = true;
            else if (kind_ < 16 && kind_ > 1)
                operand5 = false;
        } while (count2);
        *output2 = 0;
        if (!reinterpret_cast<::FUN_00594c00_shell *>(&(operators))->FUN_00594c00())
        {
            reinterpret_cast<::Holder5934d0 *>(this)->SetError(5);
            return 0;
        }
        else
        {
            *puiLength = output2 - postfix;
            return postfix;
        }
    }
}
