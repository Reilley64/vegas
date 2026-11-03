
// src/staging/blk_00b60000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00b60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00b60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include <cstring>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/NiRenderer.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_00b79000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_011fc000.h"
#include "fnv/symbols_011fd000.h"
#include "fnv/symbols_011fe000.h"
#include "fnv/symbols_0126f000.h"
#include "../../include/layout_support.h"

#include <string.h>
struct __declspec(align(16)) Matrix132
{
    float m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44;
};
struct Entry132
{
    unsigned int unk00, unk04;
    unsigned char enabled;
};
struct Object132
{
    unsigned int unk00, unk04, unk08, unk0c;
    Matrix132 transform;
    unsigned int unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c;
    unsigned int unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    unsigned int unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac;
    unsigned int unk0b0, unk0b4, unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc;
    unsigned int unk0d0, unk0d4, unk0d8, unk0dc, unk0e0, unk0e4, unk0e8;
    unsigned char unk0ec;
    unsigned char special;
};
struct Group132
{
    unsigned int unk00, unk04;
    unsigned char unk08, count;
    unsigned short unk0a;
    Object132** objects;
};
struct Vector132
{
    float x, y, z;
};
struct Context132
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    unsigned int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    unsigned int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    unsigned int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    unsigned int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    unsigned int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    unsigned int unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    unsigned int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    unsigned int unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    unsigned int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    unsigned int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    unsigned int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c;
    unsigned int unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    unsigned int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc;
    unsigned int unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc;
    unsigned int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    unsigned int unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c;
    unsigned int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c;
    unsigned int unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    unsigned int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c;
    unsigned int unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4, unk4b8, unk4bc;
    unsigned int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc;
    unsigned int unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc;
    unsigned int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c;
    unsigned int unk520, unk524, unk528, unk52c, unk530, unk534, unk538, unk53c;
    unsigned int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c;
    unsigned int unk560, unk564, unk568, unk56c, unk570, unk574, unk578, unk57c;
    unsigned int unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c;
    unsigned int unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8, unk5bc;
    unsigned int unk5c0, unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc;
    unsigned int unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4, unk5f8, unk5fc;
    unsigned int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c;
    unsigned int unk620, unk624, unk628, unk62c, unk630, unk634, unk638, unk63c;
    unsigned int unk640, unk644, unk648, unk64c, unk650, unk654, unk658, unk65c;
    unsigned int unk660, unk664, unk668, unk66c, unk670, unk674, unk678, unk67c;
    unsigned int unk680, unk684, unk688, unk68c, unk690, unk694, unk698, unk69c;
    unsigned int unk6a0, unk6a4, unk6a8, unk6ac, unk6b0, unk6b4, unk6b8, unk6bc;
    unsigned int unk6c0, unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc;
    unsigned int unk6e0, unk6e4, unk6e8, unk6ec, unk6f0, unk6f4, unk6f8, unk6fc;
    unsigned int unk700, unk704, unk708, unk70c, unk710, unk714, unk718, unk71c;
    unsigned int unk720, unk724, unk728, unk72c, unk730, unk734, unk738, unk73c;
    unsigned int unk740, unk744, unk748, unk74c, unk750, unk754, unk758, unk75c;
    unsigned int unk760, unk764, unk768, unk76c, unk770, unk774, unk778, unk77c;
    unsigned int unk780, unk784, unk788, unk78c, unk790, unk794, unk798, unk79c;
    unsigned int unk7a0, unk7a4, unk7a8, unk7ac, unk7b0, unk7b4, unk7b8, unk7bc;
    unsigned int unk7c0, unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc;
    unsigned int unk7e0, unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8, unk7fc;
    unsigned int unk800, unk804, unk808, unk80c, unk810, unk814, unk818, unk81c;
    unsigned int unk820, unk824, unk828, unk82c, unk830, unk834, unk838, unk83c;
    unsigned int unk840, unk844, unk848, unk84c, unk850, unk854, unk858, unk85c;
    unsigned int unk860, unk864, unk868, unk86c, unk870, unk874, unk878, unk87c;
    unsigned int unk880, unk884, unk888, unk88c, unk890, unk894, unk898, unk89c;
    unsigned int unk8a0, unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8, unk8bc;
    unsigned int unk8c0, unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc;
    unsigned int unk8e0, unk8e4, unk8e8, unk8ec, unk8f0, unk8f4, unk8f8, unk8fc;
    unsigned int unk900, unk904, unk908, unk90c, unk910, unk914, unk918, unk91c;
    unsigned int unk920, unk924, unk928, unk92c, unk930, unk934, unk938, unk93c;
    Matrix132 transform;
};
struct Owner132
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Context132* context;
    void FUN_00b7b730(Group132*, unsigned int, int, const char*);
};
// @fnv 0x00b7b730
void Owner132::FUN_00b7b730(Group132* group, unsigned int slot, int skipLoad, const char* name)
{
    Matrix132 matrix, result, temporary;
    if (!(*reinterpret_cast<::Entry132 * *>(&::DAT_011febdc))->enabled)
        return;
    if (!group->objects || (group->count > 0u && group->objects[0] && group->objects[0]->special) ||
        (slot >= 0x244 && slot <= 0x24b) || (slot >= 0x2d8 && slot <= 0x2ef) || slot == 0xfe || slot == 0x10b)
    {
        temporary = context->transform;
        ::FUN_00ee6dd4();
        return;
    }
    Group132* geometry = (*reinterpret_cast<::Group132 * *>(&::DAT_011f91e0));
    if (!geometry->objects || group->count <= 0u)
        return;
    matrix.m12 = matrix.m13 = matrix.m14 = matrix.m21 = matrix.m23 = matrix.m24 = matrix.m31 = matrix.m32 = matrix.m34 =
        matrix.m41 = matrix.m42 = matrix.m43 = 0.0f;
    matrix.m11 = matrix.m22 = matrix.m33 = matrix.m44 = 1.0f;
    result.m11 = result.m22 = result.m33 = result.m44 = 1.0f;
    result.m12 = result.m13 = result.m14 = result.m21 = result.m23 = result.m24 = result.m31 = result.m32 = result.m34 =
        result.m41 = result.m42 = result.m43 = 0.0f;
    if (!skipLoad)
        ::FUN_00b799a0((float *)(::Matrix132 *)(&matrix), name);
    matrix.m41 += (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).x;
    matrix.m42 += (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).y;
    matrix.m43 += (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).z;
    ::FUN_00ee6de0(&temporary, &matrix, &geometry->objects[0]->transform);
    result = temporary;
    ::FUN_00ee6dd4();
    memmove(&(*reinterpret_cast<::Matrix132 *>((void *)&::DAT_011fecc8)), &result, sizeof(result));
}

struct IDirect3DDevice9;
struct IDirect3DDevice9Vtbl
{
    void* slots[55];
    long(* SetClipPlane)(IDirect3DDevice9*, unsigned long, const float*);
};
struct IDirect3DDevice9
{
    IDirect3DDevice9Vtbl* lpVtbl;
};

struct __declspec(align(16)) ClipMatrix
{
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
};
struct __declspec(align(16)) ClipPlane16
{
    float x, y, z, d;
};
struct Vec3
{
    float x, y, z;
};
struct ClipPlane
{
    Vec3 n;
    float d;
};
struct ClipState
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned int unk140;
    ClipPlane planes[6];
    unsigned int unk1a4;
    ClipPlane cachedPlanes[6];
    bool cacheValid;
};
struct GeomStub
{
    ClipState* clip;
};
struct ClipRenderer
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    unsigned int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    unsigned int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    unsigned int unk280, unk284;
    struct DevWrap
    {
        IDirect3DDevice9* dev;
        void SetClipPlane(int i, const float* p)
        {
            dev->lpVtbl->SetClipPlane(dev, i, p);
        }
    } wrap;
};
struct ClipRenderData
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned int unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned int unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned int unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned int unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    unsigned int unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned int unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    unsigned int unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    unsigned int unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    unsigned int unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    unsigned int unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    unsigned int unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    unsigned int unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    unsigned int unk320, unk324, unk328, unk32c, unk330, unk334, unk338, unk33c;
    unsigned int unk340, unk344, unk348, unk34c, unk350, unk354, unk358, unk35c;
    unsigned int unk360, unk364, unk368, unk36c, unk370, unk374, unk378, unk37c;
    unsigned int unk380, unk384, unk388, unk38c, unk390, unk394, unk398, unk39c;
    unsigned int unk3a0, unk3a4, unk3a8, unk3ac, unk3b0, unk3b4, unk3b8, unk3bc;
    unsigned int unk3c0, unk3c4, unk3c8, unk3cc, unk3d0, unk3d4, unk3d8, unk3dc;
    unsigned int unk3e0, unk3e4, unk3e8, unk3ec, unk3f0, unk3f4, unk3f8, unk3fc;
    unsigned int unk400, unk404, unk408, unk40c, unk410, unk414, unk418, unk41c;
    unsigned int unk420, unk424, unk428, unk42c, unk430, unk434, unk438, unk43c;
    unsigned int unk440, unk444, unk448, unk44c, unk450, unk454, unk458, unk45c;
    unsigned int unk460, unk464, unk468, unk46c, unk470, unk474, unk478, unk47c;
    unsigned int unk480, unk484, unk488, unk48c, unk490, unk494, unk498, unk49c;
    unsigned int unk4a0, unk4a4, unk4a8, unk4ac, unk4b0, unk4b4, unk4b8, unk4bc;
    unsigned int unk4c0, unk4c4, unk4c8, unk4cc, unk4d0, unk4d4, unk4d8, unk4dc;
    unsigned int unk4e0, unk4e4, unk4e8, unk4ec, unk4f0, unk4f4, unk4f8, unk4fc;
    unsigned int unk500, unk504, unk508, unk50c, unk510, unk514, unk518, unk51c;
    unsigned int unk520, unk524, unk528, unk52c, unk530, unk534, unk538, unk53c;
    unsigned int unk540, unk544, unk548, unk54c, unk550, unk554, unk558, unk55c;
    unsigned int unk560, unk564, unk568, unk56c, unk570, unk574, unk578, unk57c;
    unsigned int unk580, unk584, unk588, unk58c, unk590, unk594, unk598, unk59c;
    unsigned int unk5a0, unk5a4, unk5a8, unk5ac, unk5b0, unk5b4, unk5b8, unk5bc;
    unsigned int unk5c0, unk5c4, unk5c8, unk5cc, unk5d0, unk5d4, unk5d8, unk5dc;
    unsigned int unk5e0, unk5e4, unk5e8, unk5ec, unk5f0, unk5f4, unk5f8, unk5fc;
    unsigned int unk600, unk604, unk608, unk60c, unk610, unk614, unk618, unk61c;
    unsigned int unk620, unk624, unk628, unk62c, unk630, unk634, unk638, unk63c;
    unsigned int unk640, unk644, unk648, unk64c, unk650, unk654, unk658, unk65c;
    unsigned int unk660, unk664, unk668, unk66c, unk670, unk674, unk678, unk67c;
    unsigned int unk680, unk684, unk688, unk68c, unk690, unk694, unk698, unk69c;
    unsigned int unk6a0, unk6a4, unk6a8, unk6ac, unk6b0, unk6b4, unk6b8, unk6bc;
    unsigned int unk6c0, unk6c4, unk6c8, unk6cc, unk6d0, unk6d4, unk6d8, unk6dc;
    unsigned int unk6e0, unk6e4, unk6e8, unk6ec, unk6f0, unk6f4, unk6f8, unk6fc;
    unsigned int unk700, unk704, unk708, unk70c, unk710, unk714, unk718, unk71c;
    unsigned int unk720, unk724, unk728, unk72c, unk730, unk734, unk738, unk73c;
    unsigned int unk740, unk744, unk748, unk74c, unk750, unk754, unk758, unk75c;
    unsigned int unk760, unk764, unk768, unk76c, unk770, unk774, unk778, unk77c;
    unsigned int unk780, unk784, unk788, unk78c, unk790, unk794, unk798, unk79c;
    unsigned int unk7a0, unk7a4, unk7a8, unk7ac, unk7b0, unk7b4, unk7b8, unk7bc;
    unsigned int unk7c0, unk7c4, unk7c8, unk7cc, unk7d0, unk7d4, unk7d8, unk7dc;
    unsigned int unk7e0, unk7e4, unk7e8, unk7ec, unk7f0, unk7f4, unk7f8, unk7fc;
    unsigned int unk800, unk804, unk808, unk80c, unk810, unk814, unk818, unk81c;
    unsigned int unk820, unk824, unk828, unk82c, unk830, unk834, unk838, unk83c;
    unsigned int unk840, unk844, unk848, unk84c, unk850, unk854, unk858, unk85c;
    unsigned int unk860, unk864, unk868, unk86c, unk870, unk874, unk878, unk87c;
    unsigned int unk880, unk884, unk888, unk88c, unk890, unk894, unk898, unk89c;
    unsigned int unk8a0, unk8a4, unk8a8, unk8ac, unk8b0, unk8b4, unk8b8, unk8bc;
    unsigned int unk8c0, unk8c4, unk8c8, unk8cc, unk8d0, unk8d4, unk8d8, unk8dc;
    unsigned int unk8e0, unk8e4, unk8e8, unk8ec, unk8f0, unk8f4, unk8f8, unk8fc;
    unsigned int unk900, unk904, unk908, unk90c, unk910, unk914, unk918, unk91c;
    unsigned int unk920, unk924, unk928, unk92c, unk930, unk934, unk938, unk93c;
    unsigned int unk940, unk944, unk948, unk94c, unk950, unk954, unk958, unk95c;
    unsigned int unk960, unk964, unk968, unk96c, unk970, unk974, unk978, unk97c;
    ClipMatrix view;
    ClipMatrix projection;
};
struct ClipManager
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014;
    ClipRenderData* renderer;
    void FUN_00b7be00(unsigned int state);
};

// @fnv 0x00b7be00
void ClipManager::FUN_00b7be00(unsigned int state)
{
    if (state >= 0x231 && state <= 0x234)
    {
        ClipState* clip = (ClipState*)(*reinterpret_cast<::Group132 * *>(&::DAT_011f91e0))->objects[0];
        if (!clip->cacheValid)
        {
            ClipMatrix view = renderer->view;
            ClipPlane* pSrc = clip->planes;
            float d1 = view._11 * (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).x + view._21 * (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).y + view._31 * (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).z;
            view._41 = -d1;
            float d2 = view._12 * (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).x + view._22 * (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).y + view._32 * (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).z;
            view._42 = -d2;
            float d3 = view._13 * (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).x + view._23 * (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).y + view._33 * (*reinterpret_cast<::Vector132 *>(&::DAT_011f474c)).z;
            view._43 = -d3;
            ClipMatrix projection = renderer->projection;
            ClipMatrix transform;
            ClipMatrix inverse;
            ClipPlane16 transformed[6];
            ::FUN_00ee6de0((Matrix132*)&transform, (const Matrix132*)&view, (const Matrix132*)&projection);
            ::FUN_00ee6dda();
            ::FUN_00ee6dd4();

            for (int i = 0; i < 6; ++i)
            {
                Vec3 n = pSrc[i].n;
                ClipPlane16 plane;
                plane.x = n.x;
                plane.y = n.y;
                plane.z = n.z;
                plane.d = -pSrc[i].d;
                ClipPlane16 outPlane;
                ::FUN_00ee6dce(&plane, &plane);
                ::FUN_00ee6dc8((::D3DXPLANE *)(::ClipPlane16 *)(&outPlane), (const ::D3DXPLANE *)(const ::ClipPlane16 *)(&plane), (const ::D3DXMATRIX *)(const ::ClipMatrix *)(&transform));
                transformed[i].x = outPlane.x;
                transformed[i].y = outPlane.y;
                transformed[i].z = outPlane.z;
                transformed[i].d = outPlane.d;
            }
            ClipRenderer* r1 = (*reinterpret_cast<::ClipRenderer * *>(&::NiRenderer::ms_pRenderer));
            int i = 0;
            ClipRenderer::DevWrap* w1 = &r1->wrap;
            for (; i < 6; ++i)
                w1->SetClipPlane(i, &transformed[i].x);
            std::memmove(clip->cachedPlanes, transformed, sizeof(transformed));
            clip->cacheValid = true;
        }
        else
        {
            ClipPlane* pCached = clip->cachedPlanes;
            ClipRenderer* r2 = (*reinterpret_cast<::ClipRenderer * *>(&::NiRenderer::ms_pRenderer));
            int i = 0;
            ClipRenderer::DevWrap* w2 = &r2->wrap;
            for (; i < 6; ++i)
                w2->SetClipPlane(i, &pCached[i].n.x);
        }
    }
}

class ShaderConstantDevice
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual void Slot76();
    virtual void Slot77();
    virtual void Slot78();
    virtual void Slot79();
    virtual void Slot80();
    virtual void Slot81();
    virtual void Slot82();
    virtual void Slot83();
    virtual void Slot84();
    virtual void Slot85();
    virtual void Slot86();
    virtual void Slot87();
    virtual void Slot88();
    virtual void Slot89();
    virtual void Slot90();
    virtual void Slot91();
    virtual void Slot92();
    virtual void Slot93();
    virtual long SetVertexShaderConstantF(unsigned int, const float*, unsigned int);
};

class NiShaderConstantMapEntry
{
  public:
    void* m_pVtbl;
    unsigned int m_uiRefCount;
    bool m_bEnableState;
};

class NiD3DShaderConstantMap
{
  public:
    virtual void Func00();
    virtual void Func04();
    virtual void Func08();
    virtual void Func0C();
    virtual void Func10();
    virtual void Func14();
    virtual void Func18();
    virtual void Func1C();
    virtual void Func20();
    virtual void Update();
};

struct NiColor
{
    float r;
    float g;
    float b;
};

struct BSFogProperty
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiColor m_kFogTint;
    float m_fNearPlane;
    float m_fFarPlane;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    float m_fPower;
};

struct D3DXVECTOR4
{
    float x;
    float y;
    float z;
    float w;
    D3DXVECTOR4()
    {}
    D3DXVECTOR4(float fx, float fy, float afDepth, float fw)
    {
        x = fx;
        y = fy;
        z = afDepth;
        w = fw;
    }
};

struct GeometryState
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int m_iShaderConstants;
};

struct DeviceHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ShaderConstantDevice* m_pDirectInputDevice;
};

struct RendererData
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    DeviceHolder* m_pDeviceHolder;
};

struct ShaderGeometryGroup
{
    GeometryState* current;
};


class BSShaderPass
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float* m_pfConstants;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    NiD3DShaderConstantMap* m_pkPixelConstantMap;
    NiD3DShaderConstantMap* m_pkVertexConstantMap;

    void FUN_00b7b450(unsigned int uiPass);
};

// @fnv 0x00b7b450
void BSShaderPass::FUN_00b7b450(unsigned int uiPass)
{
    if (uiPass == 0x250 || uiPass == 0x251)
        return;

    int i;
    for (i = 0; i < 22; i++)
    {
        NiShaderConstantMapEntry* pkEntry = (*reinterpret_cast<NiShaderConstantMapEntry * (*)[22]>(&::DAT_011febd8))[i];
        if (pkEntry)
            pkEntry->m_bEnableState = ((*reinterpret_cast<unsigned int (*)[]>(&::DAT_011fcc80))[uiPass] & (1 << (i + 1))) != 0;
    }
    for (i = 0; i < 22; i++)
    {
        NiShaderConstantMapEntry* pkEntry = (*reinterpret_cast<NiShaderConstantMapEntry * (*)[22]>(&::DAT_011fec30))[i];
        if (pkEntry)
            pkEntry->m_bEnableState = ((*reinterpret_cast<unsigned int (*)[]>(&::DAT_011fc0a0))[uiPass] & (1 << (i + 1))) != 0;
    }

    m_pkVertexConstantMap->Update();
    m_pkPixelConstantMap->Update();

    if ((*reinterpret_cast<::NiShaderConstantMapEntry * *>(&::DAT_011febf8))->m_bEnableState)
    {
        BSFogProperty* pkFog = ::FUN_00b55520(DAT_011f91c4);
        if (pkFog)
        {
            float fNear = pkFog->m_fNearPlane;
            float fFar = pkFog->m_fFarPlane;
            float m_fAlpha = pkFog->m_fPower;
            if (fFar == 0.0f && fNear == 0.0f)
            {
                (*reinterpret_cast<::D3DXVECTOR4 *>((void *)&::DAT_011FA280)) = D3DXVECTOR4(500000.0f, 0.0f, 0.0f, 0.0f);
                (*reinterpret_cast<::D3DXVECTOR4 *>((void *)&::DAT_011FA290)) = (*reinterpret_cast<::D3DXVECTOR4 *>(&::DAT_011a9bd0));
            }
            else
            {
                NiColor kColor = pkFog->m_kFogTint;
                (*reinterpret_cast<::D3DXVECTOR4 *>((void *)&::DAT_011FA280)) = D3DXVECTOR4(fFar, fFar - fNear, m_fAlpha, 0.0f);
                (*reinterpret_cast<::D3DXVECTOR4 *>((void *)&::DAT_011FA290)) = D3DXVECTOR4(kColor.r, kColor.g, kColor.b, 0.0f);
            }
        }
    }

    if (((ShaderGeometryGroup*)(*reinterpret_cast<::Group132 * *>(&::DAT_011f91e0)))->current->m_iShaderConstants)
    {
        Matrix132 kWorld;
        ::FUN_00ee6dd4();
        ShaderConstantDevice* pkDevice = (*reinterpret_cast<::RendererData * *>(&::DAT_0126f74c))->m_pDeviceHolder->m_pDirectInputDevice;
        pkDevice->SetVertexShaderConstantF(1, &kWorld.m11, 4);
    }

    if ((*reinterpret_cast<::NiShaderConstantMapEntry * *>(&::DAT_011febf8))->m_bEnableState)
    {
        (*reinterpret_cast<::D3DXVECTOR4 *>((void *)&::DAT_011fd9b8)) = (*reinterpret_cast<::D3DXVECTOR4 *>(&::DAT_011a9bd0));
        (*reinterpret_cast<::D3DXVECTOR4 *>((void *)&::DAT_011fd9c8)) = (*reinterpret_cast<::D3DXVECTOR4 *>(&::DAT_011a9bd0));
        (*reinterpret_cast<::D3DXVECTOR4 *>((void *)&::DAT_011fd9d8)) = (*reinterpret_cast<::D3DXVECTOR4 *>(&::DAT_011a9bd0));
    }
}
