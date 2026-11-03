
// src/fallout/ai/actor_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Ob1 /Oy- /GS /EHsc /Gy (unit src/fallout/ai/actor.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include <windows.h>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_0098adb0_shell.h"
#include "fnv/decl/FUN_009c8d60_t.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00895110__PickActor.h"
#include "fnv/decl/fnv_0089f580__ActorStub.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_01203000.h"
#include "Actor.h"

struct ArrowScale
{
    float value;
};
struct ArrowMemory
{
};
extern ArrowMemory _g_memoryManager;
struct ArrowPoint
{
    float x, y, z;
    ArrowPoint* FUN_00c5a800(ArrowPoint* result) const;
};
struct ArrowColor
{
    float r, g, b, a;
};
struct ArrowMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct ArrowString
{
    char* value;
    __forceinline ArrowString(const char* text)
    {
        if (!text)
            value = DAT_0109b220;
        else
            value = ::NiGlobalStringTable::AddString(text);
    }
    __forceinline ~ArrowString()
    {
        if (value == DAT_0109b220)
            return;
        long* count = ((long*)value) - 2;
        InterlockedDecrement(count);
    }
};
struct ArrowGeometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    ArrowMatrix rotation;
    ArrowPoint translation;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    ArrowGeometry(unsigned short, ArrowPoint*, ArrowColor*, void*, void*, void*, unsigned char*);
};
__forceinline void ReserveMathWork()
{
    int mathState;
}
__forceinline void ScaleDirection(ArrowPoint& out, const ArrowPoint& n, float factor)
{
    ArrowPoint v = {n.x * factor, n.y * factor, n.z * factor};
    out.x = v.x;
    out.y = v.y;
    out.z = v.z;
}
__forceinline void ConstructPointsBody(ArrowPoint* const& memory)
{
    long side = 5;
    ArrowPoint* green0 = memory;
    while (--side >= 0)
        green0 += 1;
}
__forceinline void ConstructPoints(ArrowPoint* const& memory)
{
    ReserveMathWork();
    ConstructPointsBody(memory);
}
__forceinline void PerpendicularScale(ArrowPoint& out, const ArrowPoint& n, ArrowPoint& temp, float factor)
{
    ArrowMatrix coordinateFrame;
    {
        const ArrowPoint* point = n.FUN_00c5a800(&temp);
        ArrowPoint v6 = {point->x * factor, point->y * factor, point->z * factor};
        out.x = v6.x;
        out.y = v6.y;
        out.z = v6.z;
    }
}
__forceinline void ScaleHead(ArrowPoint& out, const ArrowPoint& n)
{
    ArrowPoint v = {n.x * ::DAT_01016264, n.y * ::DAT_01016264, n.z * ::DAT_01016264};
    out.x = v.x;
    out.y = v.y;
    out.z = v.z;
}
__forceinline void SetComponents(ArrowPoint& out, float x, float y, float z)
{
    out.x = x;
    out.y = y;
    out.z = z;
}
__forceinline void SubtractPoint(ArrowPoint& out, const ArrowPoint& head, const ArrowPoint& side)
{
    SetComponents(out, head.x - side.x, head.y - side.y, head.z - side.z);
}
__forceinline void AddPoint(ArrowPoint& out, const ArrowPoint& head, const ArrowPoint& side)
{
    ArrowPoint v = {side.x + head.x, side.y + head.y, side.z + head.z};
    out.x = v.x;
    out.y = v.y;
    out.z = v.z;
}
__forceinline void ConstructColors(ArrowColor* const& memory)
{
    int side = 6;
    ArrowColor* green0 = memory;
    while (--side >= 0)
    {
        green0->r = 0;
        green0->g = 0;
        green0->b = 0;
        green0->a = 0;
        green0 += 1;
    }
}
// @fnv 0x00c59a50
ArrowGeometry* __cdecl FUN_00c59a50(const ArrowPoint& direction, const ArrowColor* color)
{
    ArrowPoint n3;
    float q;
    ArrowPoint* connections;
    ArrowPoint left5;
    ArrowPoint _geometry;
    ArrowColor* normalizedC;
    ArrowPoint head;
    ArrowGeometry* vertices5;
    unsigned char* vertexResult;
    {
        ArrowPoint* pForm2;
        ArrowPoint differenceD;
        ArrowPoint* vertexAllocation2;
        ArrowPoint originJ;
        ArrowPoint X8;
        ArrowPoint z3;
        ArrowPoint colors;
        ArrowPoint s;
        ArrowColor* constructionResult;
        ArrowColor* aColorResult;
        ArrowColor aX;
        ArrowColor green8;
        ArrowColor c;
        unsigned char* connectionResult4;
        n3 = direction;
        q = reinterpret_cast<::NiPoint3 *>((void *)&(n3))->ComputeMagnitude();
        if (q < 8.0)
        {
            ReserveMathWork();
            ScaleDirection(differenceD, n3, 8.0 / q);
            n3 = differenceD;
            q = reinterpret_cast<::NiPoint3 *>((void *)&(n3))->ComputeMagnitude();
        }
        vertexAllocation2 = (ArrowPoint*)reinterpret_cast<::MemoryManagerStandIn *>(&(_g_memoryManager))->FUN_00aa3e40(60);
        pForm2 = vertexAllocation2 ? (ConstructPoints(vertexAllocation2), vertexAllocation2) : 0;
        connections = pForm2;
        originJ.x = 0;
        originJ.y = 0;
        originJ.z = 0;
        connections[0] = originJ;
        PerpendicularScale(_geometry, n3, X8, q * 0.15000000596046448);
        ScaleHead(s, n3);
        head = s;
        SubtractPoint(colors, head, _geometry);
        left5 = colors;
        AddPoint(z3, head, _geometry);
        head = z3;
        connections[1] = n3;
        connections[2] = head;
        connections[3] = n3;
        connections[4] = left5;
        if (!color)
            color = &(*reinterpret_cast<::ArrowColor *>(&::DAT_012032f8));
        constructionResult = (ArrowColor*)reinterpret_cast<::MemoryManagerStandIn *>(&(_g_memoryManager))->FUN_00aa3e40(96);
        aColorResult = constructionResult ? (ConstructColors(constructionResult), constructionResult) : 0;
        normalizedC = aColorResult;
        normalizedC[0] = *color;
        normalizedC[1] = *color;
        aX.r = 0;
        aX.g = 1;
        aX.b = 0;
        aX.a = 1;
        normalizedC[2] = aX;
        green8.r = 0;
        green8.g = 1;
        green8.b = 0;
        green8.a = 1;
        normalizedC[3] = green8;
        c.r = 0;
        c.g = 1;
        c.b = 0;
        c.a = 1;
        normalizedC[4] = c;
        connectionResult4 = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>(&(_g_memoryManager))->FUN_00aa3e40(6);
        vertexResult = connectionResult4;
        vertexResult[0] = 1;
        vertexResult[1] = 0;
        vertexResult[2] = 1;
        vertexResult[3] = 1;
        vertexResult[4] = 0;
        vertices5 = new ArrowGeometry(5, connections, normalizedC, 0, 0, 0, vertexResult);
        vertices5->translation = (*reinterpret_cast<::ArrowPoint *>((void *)&::NiPoint3::ZERO));
        vertices5->rotation = (*reinterpret_cast<::ArrowMatrix *>(&::DAT_011a9448));
        ::AssignFixedString((char *)(vertices5), (int)&(const ::ArrowString &)(ArrowString("BSTestObjects DirArrow")), {});
        return vertices5;
    }
}

#include "generated/data/fallout/ai/actor_ob1_variant.inc"
