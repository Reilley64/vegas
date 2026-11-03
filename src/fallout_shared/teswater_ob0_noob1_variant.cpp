
// src/fallout_shared/teswater_ob0_noob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob0 /GF (unit src/fallout_shared/teswater.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /Ob1 /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/C00c66300.h"
#include "fnv/decl/C6B540Manager.h"
#include "fnv/decl/Controller.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_00452df0_class.h"
#include "fnv/decl/FUN_00452e50_class.h"
#include "fnv/decl/FUN_00452e90_Class.h"
#include "fnv/decl/FUN_0045c780_shell.h"
#include "fnv/decl/FUN_0045c840_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_005281f0_Class.h"
#include "fnv/decl/FUN_005282d0_cls.h"
#include "fnv/decl/FUN_005285a0_Class.h"
#include "fnv/decl/FUN_0068a830_shell.h"
#include "fnv/decl/FUN_00c66310_class.h"
#include "fnv/decl/GridRefresh__Grid.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S457d70.h"
#include "fnv/decl/S_004ed780.h"
#include "fnv/decl/Shell451.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WS458200_Shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00452490__FUN_00452490_shell.h"
#include "fnv/decl/fnv_00452ed0__FUN_00452ed0_shell.h"
#include "fnv/decl/fnv_00454d50__FUN_00454d50_shell.h"
#include "fnv/decl/fnv_00457070__FUN_00457070_shell.h"
#include "fnv/decl/fnv_00457be0__OwnerProxy.h"
#include "fnv/decl/fnv_004581e0__FUN_004581e0_Class.h"
#include "fnv/decl/fnv_005283c0__QCellQueue.h"
#include "fnv/decl/fnv_006271b0__Owner.h"
#include "fnv/decl/fnv_00628da0__LoadedAreaBound.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/s4e5e50__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00451000.h"
#include "fnv/symbols_00452000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_0049e000.h"
#include "fnv/symbols_0062f000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f9000.h"
#include "teswater_decls.h"
#include "teswater_work.h"

void* __cdecl operator new(unsigned int uiSize);
void* __cdecl operator new[](unsigned int uiSize);
void __cdecl operator delete(void* pvMem);
void __cdecl operator delete[](void* pvMem);


struct C4E7770AutoMemHelper
{
    C4E7770AutoMemHelper(int iType, bool bFlag, const char* pcFile, int iLine);
    ~C4E7770AutoMemHelper();

    int m_uiLogicalSize;
};

extern const char g_ac4E7770AlphaSetting[];

class C4E7770Point3
{
  public:
    C4E7770Point3();
    C4E7770Point3(float fX, float fY, float fZ);

    float x;
    float y;
    float z;
};

class C4E7770Point2
{
  public:
    C4E7770Point2();
    C4E7770Point2(float fX, float fY);

    float x;
    float y;
};

class C4E7770ColorA
{
  public:
    C4E7770ColorA();
    C4E7770ColorA(float fR, float fG, float fB, float fA);

    float r;
    float g;
    float b;
    float a;
};

class C4E7770Setting
{
  public:
    C4E7770Setting(const char* pcName, float fValue);
    ~C4E7770Setting();


    int unk00;
    int unk04;
    int unk08;
};

class C4E7770TriShapeData
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);

    C4E7770TriShapeData(unsigned short usVertices, C4E7770Point3* pkVertex, C4E7770Point3* pkNormal,
                        C4E7770ColorA* pkColor, C4E7770Point2* pkTexture, unsigned short usNumTextureSets,
                        unsigned int eNBTMethod, unsigned short usTriangles, unsigned short* pusTriList);

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
};

class C4E7770QuadFactory
{
  public:
    C4E7770TriShapeData* FUN_004e7770(float m_fGlyphWidthInPixels, float m_fGlyphExtent, int iUnused, unsigned int uiTiles,
                                      bool bGenerateNormals, bool bColors);
};

// @fnv 0x004e7770
C4E7770TriShapeData* C4E7770QuadFactory::FUN_004e7770(float m_fGlyphWidthInPixels, float m_fGlyphExtent, int iUnused, unsigned int uiTiles,
                                                      bool bGenerateNormals, bool bColors)
{
    C4E7770Point3* pkNormalsDir;
    C4E7770Point2* pkTexCoordsUV;
    C4E7770TriShapeData* pkShapeData;
    C4E7770Point3* pkVerticesQuad;
    float fTilesTile;
    unsigned short* pusTriangles;
    C4E7770ColorA* pkColors;
    C4E7770AutoMemHelper kMemHelperMem(0x1d, true, ::fnv_004eaa00::DAT_0102301c, 0xbac);

    pkVerticesQuad = new C4E7770Point3[4];
    if (!pkVerticesQuad)
        return 0;
    pkVerticesQuad[0] = C4E7770Point3(m_fGlyphWidthInPixels / 2.0, m_fGlyphExtent / 2.0, 0.0f);
    pkVerticesQuad[1] = C4E7770Point3(-m_fGlyphWidthInPixels / 2.0, m_fGlyphExtent / 2.0, 0.0f);
    pkVerticesQuad[2] = C4E7770Point3(-m_fGlyphWidthInPixels / 2.0, -m_fGlyphExtent / 2.0, 0.0f);
    pkVerticesQuad[3] = C4E7770Point3(m_fGlyphWidthInPixels / 2.0, -m_fGlyphExtent / 2.0, 0.0f);

    static C4E7770Point3 s_kNormal(0.0f, 0.0f, 1.0f);

    pkTexCoordsUV = new C4E7770Point2[4];
    if (!pkTexCoordsUV)
    {
        delete[] pkVerticesQuad;
        return 0;
    }

    pusTriangles = (unsigned short*)::FUN_00aa1070(6 * sizeof(unsigned short));
    if (!pusTriangles)
    {
        delete[] pkVerticesQuad;
        delete[] pkTexCoordsUV;
        return 0;
    }
    pusTriangles[0] = 0;
    pusTriangles[1] = 1;
    pusTriangles[2] = 2;
    pusTriangles[3] = 0;
    pusTriangles[4] = 2;
    pusTriangles[5] = 3;

    pkNormalsDir = 0;
    if (bGenerateNormals)
    {
        pkNormalsDir = new C4E7770Point3[4];
        if (pkNormalsDir)
        {
            pkNormalsDir[0] = s_kNormal;
            pkNormalsDir[1] = s_kNormal;
            pkNormalsDir[2] = s_kNormal;
            pkNormalsDir[3] = s_kNormal;
        }
    }

    pkColors = 0;
    if (bColors)
    {
        pkColors = new C4E7770ColorA[4];
        if (pkColors)
        {
            static C4E7770Setting s_kAlpha(g_ac4E7770AlphaSetting, 1.0f);
            if (*((float *)&(::FUN_00403e20((float *)&(s_kAlpha)))) > 1.0)
                reinterpret_cast<::S_004ed780 *>(&(s_kAlpha))->FUN_004ed780(1.0f);
            else if (*((float *)&(::FUN_00403e20((float *)&(s_kAlpha)))) < 0.0)
                reinterpret_cast<::S_004ed780 *>(&(s_kAlpha))->FUN_004ed780(0.0f);
            pkColors[0] = C4E7770ColorA(1.0f, 1.0f, 1.0f, reinterpret_cast<::FUN_00450410_Class *>(&(s_kAlpha))->FUN_00450410());
            pkColors[1] = C4E7770ColorA(1.0f, 1.0f, 1.0f, reinterpret_cast<::FUN_00450410_Class *>(&(s_kAlpha))->FUN_00450410());
            pkColors[2] = C4E7770ColorA(1.0f, 1.0f, 1.0f, reinterpret_cast<::FUN_00450410_Class *>(&(s_kAlpha))->FUN_00450410());
            pkColors[3] = C4E7770ColorA(1.0f, 1.0f, 1.0f, reinterpret_cast<::FUN_00450410_Class *>(&(s_kAlpha))->FUN_00450410());
        }
    }

    fTilesTile = 1.0f;
    if (uiTiles != 1)
        fTilesTile = (float)uiTiles;
    pkTexCoordsUV[0] = C4E7770Point2(fTilesTile, 0.0f);
    pkTexCoordsUV[1] = C4E7770Point2(0.0f, 0.0f);
    pkTexCoordsUV[2] = C4E7770Point2(0.0f, fTilesTile);
    pkTexCoordsUV[3] = C4E7770Point2(fTilesTile, fTilesTile);

    pkShapeData =
        new C4E7770TriShapeData(4, pkVerticesQuad, pkNormalsDir, pkColors, pkTexCoordsUV, 1, 0, 2, pusTriangles);
    if (!pkShapeData)
    {
        delete[] pkVerticesQuad;
        delete[] pkNormalsDir;
        delete[] pkTexCoordsUV;
        delete[] pusTriangles;
        delete[] pkColors;
    }
    return pkShapeData;
}
