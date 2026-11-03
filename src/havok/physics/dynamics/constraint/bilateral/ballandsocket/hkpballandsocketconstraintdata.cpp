
// src/havok/physics/dynamics/constraint/bilateral/ballandsocket/hkpballandsocketconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/ballandsocket/hkpballandsocketconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00d21000.h"
#include "havok/hkpBallAndSocketConstraintDataAtoms.h"
#include "havok/hkpConstraintData.h"
#include "fnv/symbols_0104e000.h"
struct hkpBallAndSocketConstraintData : public hkpConstraintData
{
    char padC[0x4];
    hkpBallAndSocketConstraintDataAtoms m_kBridgeAtoms;  // +0x10
    void FUN_00d54210(::GenericConstraintAtomScheme* a) const;
};
struct FUN_00d541f0_class : hkpBallAndSocketConstraintData
{
    void FUN_00d541f0(int index);
};

// @fnv 0x00d541f0
void FUN_00d541f0_class::FUN_00d541f0(int aiBitIndex)
{
    m_kBridgeAtoms.m_kBallSocket.m_ucBodiesToNotify = (hkUint8)(1 << aiBitIndex);
}

// @fnv 0x00d54210
void hkpBallAndSocketConstraintData::FUN_00d54210(::GenericConstraintAtomScheme* a) const
{
    ::FUN_00d21a60(reinterpret_cast<const ::hkpConstraintAtom *>(&m_kBridgeAtoms), 0x38, a);
}

struct FUN_00d54230_class : hkpBallAndSocketConstraintData
{
    void FUN_00d54230(char a, int* b);
};
// If a is zero and the ball-socket breach impulse equals DAT_0104e138, writes 0 and 0 to b; otherwise writes 3 and 0x18.
// @fnv 0x00d54230
void FUN_00d54230_class::FUN_00d54230(char abCondition, int* pOut)
{
    if (!abCondition && m_kBridgeAtoms.m_kBallSocket.m_usFlags == DAT_0104e138)
    {
        pOut[1] = 0;
        pOut[0] = 0;
    }
    else
    {
        pOut[1] = 3;
        pOut[0] = 0x18;
    }
}

struct FUN_00d541d0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    float unk44;
    void FUN_00d541d0(float value);
};

// @fnv 0x00d541d0
void FUN_00d541d0_class::FUN_00d541d0(float value)
{
    unk44 = value;
}

struct FUN_00d54200_class : hkpBallAndSocketConstraintData
{
    unsigned char FUN_00d54200();
};
// @fnv 0x00d54200
unsigned char FUN_00d54200_class::FUN_00d54200()
{
    return m_kBridgeAtoms.m_kBallSocket.m_ucBodiesToNotify >> 1;
}

struct D54270Bool
{
    char m_cBooleanValue;

    D54270Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct D54270Object
{
    virtual D54270Bool FUN_00d54270() const;
};

// @fnv 0x00d54270
D54270Bool D54270Object::FUN_00d54270() const
{
    return true;
}

struct FUN_00d541e0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    float unk44;

    float FUN_00d541e0();
};

// @fnv 0x00d541e0
float FUN_00d541e0_class::FUN_00d541e0()
{
    return unk44;
}

// @fnv 0x00d54280
int __cdecl FUN_00d54280()
{
    return 0;
}
