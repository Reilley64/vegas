
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/FG_00659100_cls.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_0064dda0_cls.h"
#include "fnv/decl/FUN_0065dfd0_class.h"
#include "fnv/decl/FUN_0065fd10_class.h"
#include "fnv/decl/S_006590c0.h"
#include "fnv/decl/_Dummy_0044a170.h"
#include "fnv/decl/fnv_0065f550__FUN_0065f550_Class.h"
#include "fnv/decl/fnv_0065fd40__FUN_0065fd40_class.h"
struct S_00658260_D
{
    int unk00;
    int unk04;
};
struct S_00658260_E
{
    int unk00;
    int unk04;
};
struct S_00658260_F
{
    int unk00;
};
struct S_00658260_H
{
    int unk00;
};
struct S_00658260_G
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct S_00658260_A
{
    S_00658260_A(int a, int b);
    S_00658260_A(const S_00658260_A& o);
    ~S_00658260_A();
    int unk00;
    int unk04;
};

struct S_00658260_B
{
    int unk00;
    int unk04;
};

struct S_00658260_C
{
    float* Slot();
    int unk00;
    int unk04;
};

struct S_00658260_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m18;
    int m1c;


    S_00658260_A BuildScaledValues(float scale);
};

// Iterates x over GetF(&info), writes each value times scale into it.Slot(), and returns a copy of a built from m18 and m1c.
// @fnv 0x00658260
S_00658260_A S_00658260_Owner::BuildScaledValues(float scale)
{
    S_00658260_F info;
    S_00658260_H obj;
    S_00658260_E arr;
    S_00658260_D ent;
    S_00658260_B x;
    S_00658260_A a(m18, m1c);
    S_00658260_G aa;
    S_00658260_C it;
    for (reinterpret_cast<::FUN_0065fd10_class *>(this)->FUN_0065fd10((::FUN_0065e000_class *)(::S_00658260_B *)(&x)), reinterpret_cast<::_Dummy_0044a170 *>(&(a))->FUN_0044a170((::_Out_0044a170 *)(void *)(&it)); reinterpret_cast<::FUN_0065dfd0_class *>(&(x))->FUN_0065dfd0(reinterpret_cast<std::intptr_t>(reinterpret_cast<::fnv_0065fd40::FUN_0065fd40_class *>(this)->FUN_0065fd40((::fnv_0065fd40::FUN_0065e000_class *)(::S_00658260_F *)(&info)))); reinterpret_cast<::FG_00659100_cls *>(&(x))->FUN_00659100((::FG_00659100_pair *)(::S_00658260_D *)(&ent), 0), reinterpret_cast<::S_006590c0 *>(&(it))->CopyPairTo(&arr, 0))
    {
        *it.Slot() = (float)(*((float *)(reinterpret_cast<::FUN_0064dda0_cls *>(&(x))->FUN_0064dda0())) * scale);
    }
    return a;
}

struct Cursor
{
    void* unk00;
    void* unk04;
};

struct Iterator
{
    void* unk00;
    void* unk04;
    float* FUN_0064dbd0();
};

class Mgr
{
  public:
    Mgr* ScaleAll(float scale);
};

// Iterates over the manager's entries and multiplies each entry's float value by scale, returning this.
// @fnv 0x00658650
Mgr* Mgr::ScaleAll(float scale)
{
    Iterator iter;
    Cursor key;
    Cursor currentPos;
    for (reinterpret_cast<::_Dummy_0044a170 *>((this))->FUN_0044a170((::_Out_0044a170 *)(::Iterator *)(&iter)); reinterpret_cast<::FUN_0065dfd0_class *>(&(iter))->FUN_0065dfd0(reinterpret_cast<std::intptr_t>(reinterpret_cast<::fnv_0065f550::FUN_0065f550_Class *>((this))->CallWithSelf((::fnv_0065f550::_Out_0044a170 *)(::Cursor *)(&key)))); reinterpret_cast<::S_006590c0 *>(&(iter))->CopyPairTo(&currentPos, 0))
    {
        *iter.FUN_0064dbd0() *= scale;
    }
    return this;
}

struct A87A0Element
{
    void* m_pMatrix;
    unsigned int m_uiPosition;

};

class A87A0Matrix
{
  public:
    A87A0Matrix(unsigned int uiRows, unsigned int uiCols);
    A87A0Matrix(const A87A0Matrix& kOther);
    ~A87A0Matrix();

    A87A0Element At(unsigned int uiRow, unsigned int uiCol);

    A87A0Matrix Transpose();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_uiRows;
    unsigned int m_uiCols;
};

// Builds a matrix with rows and columns swapped and copies each element from At(i, j) into At(j, i).
// @fnv 0x006587a0
A87A0Matrix A87A0Matrix::Transpose()
{
    A87A0Matrix kResult(m_uiCols, m_uiRows);
    for (unsigned int i = 0; i < m_uiRows; i++)
    {
        for (unsigned int j = 0; j < m_uiCols; j++)
            reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::A87A0Element &)(kResult.At(j, i)))->FUN_00629ab0({}) = reinterpret_cast<::FUN_00629ab0_shell *>((void *)&(const ::A87A0Element &)(At(i, j)))->FUN_00629ab0({});
    }
    return kResult;
}
