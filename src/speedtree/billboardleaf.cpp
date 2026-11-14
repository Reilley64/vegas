#include "fnv/decl/FUN_0044a4c0.h"
#include "fnv/decl/FUN_00b09480.h"
#include "fnv/decl/FUN_00b3ed20_cls.h"
#include "fnv/decl/FUN_00b3ede0_shell.h"
#include "fnv/decl/FUN_00b40800_t.h"
#include "fnv/decl/S_00b3ed80.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
// src/speedtree/billboardleaf.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/billboardleaf.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00b28440_Class
{
    float m_v[3];
    FUN_00b28440_Class& Scale(float s);
    const float& operator[](int i) const;
};

inline const float& FUN_00b28440_Class::operator[](int i) const
{
    return m_v[i];
}

struct FUN_00b404c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char unk18;

    void FUN_00b404c0(const FUN_00b28440_Class* src, bool flag);
};

// @fnv 0x00b404c0
void FUN_00b404c0_cls::FUN_00b404c0(const FUN_00b28440_Class* src, bool flag)
{
    FUN_00b28440_Class v = *src;
    int i;
    if (flag)
    {
        v.Scale((float)((double)unk18 / 255.0));
    }
    for (i = 0; i < 3; ++i)
    {
        if (v.m_v[i] > 1.0)
        {
            v.m_v[i] = 1.0f;
        }
        if (v.m_v[i] < 0.0)
        {
            v.m_v[i] = 0.0f;
        }
    }
    unk14 = (int)(v[0] * 255.0) + ((int)(v[1] * 255.0) << 8) + ((int)(v[2] * 255.0) << 16) + 0xFF000000;
}

struct V3
{
    float x;
    float y;
    float z;
};

struct ByteVec
{
    void* i0;
    void* i4;
    void* i8;
    char* pFirst;
    char* pLast;
};

struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    V3 GetVector3();
};

inline void DeadEnd()
{
    int aiD[14];
}

inline void DeadTop()
{
    int aiD[63];
    aiD[5] = 0;
}

struct LeafQ
{
    int i0;
    V3 kA;
    unsigned char b10;
    int i14;
    unsigned char b18;
    V3 kB;
    int ai28[6];
    unsigned char b40;
    float f44;
    int i48;
    LeafQ();
    void SetA(const V3& v)
    {
        int aiE[8];
        kA = v;
    }
};

// @fnv 0x00b405c0
LeafQ* FUN_00b405c0(Parser* p)
{
    LeafQ* pLeaf = new LeafQ;
    int iToken = reinterpret_cast<::S_00b3ed80 *>((p))->GetNextElement();
    do
    {
        switch (iToken)
        {
        case 0x1b5e:
            pLeaf->i14 = reinterpret_cast<::FUN_00b3ede0_shell *>((p))->FUN_00b3ede0();
            break;
        case 0x1b5f:
            pLeaf->b10 = ((unsigned char)(reinterpret_cast<::FUN_00b40800_t *>((p))->GetNextChar()));
            break;
        case 0x1b60:
            pLeaf->b18 = ((unsigned char)(reinterpret_cast<::FUN_00b40800_t *>((p))->GetNextChar()));
            break;
        case 0x1b62:
            pLeaf->kB = p->GetVector3();
            break;
        case 0x1b63:
            pLeaf->b40 = ((unsigned char)(reinterpret_cast<::FUN_00b40800_t *>((p))->GetNextChar()));
            break;
        case 0x1b64:
            pLeaf->f44 = ((unsigned char)(reinterpret_cast<::FUN_00b40800_t *>((p))->GetNextChar())) / 255.0;
            break;
        case 0x1b65:
            pLeaf->i48 = reinterpret_cast<::S_00b3ed80 *>((p))->GetNextElement();
            break;
        case 0x1b67:
            pLeaf->SetA(p->GetVector3());
            break;
        case 0x1b68:
            reinterpret_cast<::FUN_00b3ed20_cls *>((p))->FUN_00b3ed20();
            break;
        default:
            throw FUN_00b09480("malformed billboard leaf", static_cast<unsigned char>(0));
        }
        iToken = reinterpret_cast<::S_00b3ed80 *>((p))->GetNextElement();
    } while (iToken != 0x1b5d);
    DeadEnd();
    return pLeaf;
}
