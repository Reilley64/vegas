// fallout_shared/sky/sun.cpp: Sun, NiPick, A6A0Sun (11 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/Candidate.h"
#include "fnv/decl/F940Owner.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_00458b30_class.h"
#include "fnv/decl/FUN_004769c0_shell.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004bc280_S.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_00596030_cls.h"
#include "fnv/decl/FUN_00632d20_shell.h"
#include "fnv/decl/FUN_006366b0_shell.h"
#include "fnv/decl/FUN_006427a0_Class.h"
#include "fnv/decl/FUN_006427c0_Class.h"
#include "fnv/decl/FUN_00642890_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00bb0180_shell.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiPointLight.h"
#include "fnv/decl/NiTriGeom2.h"
#include "fnv/decl/TESObjectTREE.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_00544910__FUN_00544910_shell.h"
#include "fnv/decl/fnv_00544970__FUN_00544970_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00baf3c0__FUN_00baf3c0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_004dd000.h"
#include "fnv/symbols_004e2000.h"
#include "fnv/symbols_004ea000.h"
#include "fnv/symbols_00514000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00595000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00966000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_0104f000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011de000.h"
#include "sun_decls.h"
// Initializes the Sun object's fields to zero and creates a BSShaderAccumulator for SunMode, disabling occlusion tests.
// @fnv 0x006404f0
Sun::Sun()
{
    m_pRootNode = 0;
    m_pFirstSceneObject = 0;
    m_pSecondSceneObject = 0;
    m_pThirdSceneObject = 0;
    m_pFourthSceneObject = 0;
    m_pMenuLight = 0;
    m_pSunGlarePick = 0;
    m_fSunGlareIntensity = 0.0f;
    bDoOcclusionTests = false;
    m_pSunShaderAccumulator = reinterpret_cast<NiAVObject*>(new BSShaderAccumulator(BSShaderManager::SunMode, 1, 1));
}

// @fnv 0x00461110
int FUN_00461110(int param_1)
{
    return param_1 + 0x78;
}

// @fnv 0x00514f30
int FUN_00514f30(int this_ptr)
{
    return this_ptr + 0xC0;
}

struct NiPick
{
    virtual ~NiPick();
    void* ScalarDeletingDestructor(unsigned int flags);
};

// Destroys the NiPick object and, when flags has bit 0 set, frees its memory via operator delete; returns this.
// @fnv 0x006407e0
void* NiPick::ScalarDeletingDestructor(unsigned int flags)
{
    NiPick::~NiPick();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00640670_shell
{
    void FUN_006406a0();
    void* FUN_00640670(unsigned int);
};
struct FUN_00642660_shell
{
    float m_data[3][3];
    void SetMatrixElement(int a, int b, float v);
};
// @fnv 0x00642660
void FUN_00642660_shell::SetMatrixElement(int aiRow, int aiColumn, float afValue)
{
    m_data[aiRow][aiColumn] = afValue;
}

namespace fnv_00640810 {
struct BSMaterialEmittanceMultController;
struct BSRefractionFirePeriodController;
struct BSRefractionStrengthController;
struct BSShaderNoLightingProperty;
struct BSShaderPPLightingProperty;
struct BSShaderProperty;
struct BSShaderTextureSet;
struct NiAVObject;
struct NiAlphaController;
struct NiMaterialColorController;
struct NiNode;
struct NiStream;
struct SkyShaderProperty;
struct TallGrassShaderProperty;
struct TileShaderProperty;
struct VolumetricFogShaderProperty;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct NiMemObject
{
    char _pad_0[1];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
struct RgbaColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, RgbaColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, RgbaColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
    float a;
};
struct ShaderPropertyConversionData
{
    void Convert(NiAVObject*, unsigned int);
    void CheckTextureAlphas();
    void AddShaderProperty(NiAVObject*);
    void AddMaterialProperty(NiAVObject*);
    void AddAlphaProperty(NiAVObject*);
    BSShaderProperty* GetShaderProperty();
    void SetupShaderFlags(BSShaderProperty*, NiAVObject*);
    void SetupTexturesPPLightingShader(BSShaderPPLightingProperty*);
    void SetupDataPPLightingShader(BSShaderPPLightingProperty*);
    void SetupTexturesNoLightingShader(BSShaderNoLightingProperty*);
    void SetupDataVolumetricFogShader(VolumetricFogShaderProperty*);
    void SetupTexturesTallGrassShader(TallGrassShaderProperty*);
    void SetupTexturesSkyShader(SkyShaderProperty*);
    void SetupDataSkyShader(SkyShaderProperty*);
    void SetupTexturesTileShader(TileShaderProperty*);
    bool IsValidProperty(NiAVObject*, BSShaderProperty*);
    int m_iShaderType;
    char m_kAmbientColor[12];
    char m_kDiffuseColor[12];
    float m_fShininess;
    float fAlpha;
    float m_fEmittanceMultiplier;
    NiMaterialColorController* m_pAmbientColorController;
    NiMaterialColorController* m_pDiffuseColorController;
    NiAlphaController* m_pAlphaController;
    BSMaterialEmittanceMultController* m_pEmittanceMultiplierController;
    bool m_bHasMaterialProperty;
    char _pad_39[3];
    int m_iShaderFlags1;
    int m_iShaderFlags2;
    bool m_bHasAlphaProperty;
    char _pad_45[3];
    int m_iShaderOption;
    unsigned char m_uiShaderOptionByte;
    bool m_bShaderFeature1;
    bool m_bShaderFeature2;
    bool m_bShaderFeature3;
    bool m_bShaderFeature4;
    bool m_bShaderFeature5;
    bool m_bShaderFeature6;
    bool m_bShaderFeatureActive;
    bool m_bShaderFeature8;
    bool m_bShaderFeature9;
    bool m_bShaderFeature10;
    bool m_bShaderFeature11;
    float m_fValueBeforeTextureCount;
    bool m_bShaderFeature12;
    char _pad_5d[3];
    int m_iTextureCount;
    BSRefractionStrengthController* m_pRefractionStrengthController;
    BSRefractionFirePeriodController* m_pRefractionFirePeriodController;
    bool m_bShaderFeature13;
    bool m_bShaderFeature14;
    char _pad_6e[2];
    float m_fRefractionStrength;
    float m_fRefractionFirePeriod;
    char m_kSpecularColor[12];
    float m_fShaderParameter1;
    bool m_bShaderFeature15;
    bool m_bShaderFeature16;
    bool m_bShaderFeature17;
    char _pad_8b[1];
    float m_fShaderParameter2;
    int m_iShaderOptionIndex;
    bool m_bShaderFeature18;
    char _pad_95[3];
    RgbaColor m_kEmissiveColor;
    BSShaderTextureSet* m_pTextureSet;
    char m_cTrailingBytes[7];
    char _pad_b3[1];
    int m_iShaderDataFlags;
};
struct NiPoint2
{
    static struct blob8 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float Dot(void*);
    float Unitize();
    static void LoadBinary(NiStream*, NiPoint2*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint2*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float x;
    float y;
};
struct FUN_00640810_shell : public Sun
{
    void FUN_00640810(NiNode*);
};

namespace _ {
struct SunPoint3 : NiPoint3
{
    SunPoint3();
    SunPoint3(float, float, float);
};
struct SunPoint2 : NiPoint2
{
    SunPoint2();
    SunPoint2(float, float);
};
struct SunColorA : RgbaColor
{
    SunColorA();
    SunColorA(float, float, float, float);
};
struct SkyObject
{
};
struct NiMemObject
{
};
}

struct NiColor
{
    float r, g, b;
};
struct C3;

struct NiAVObject : _::NiMemObject
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void vfn_00b4();
    virtual void vfn_00b8();
    virtual void vfn_00bc();
    virtual void vfn_00c0();
    virtual void vfn_00c4();
    virtual void vfn_00c8();
    virtual void vfn_00cc();
    virtual void vfn_00d0();
    virtual void vfn_00d4();
    virtual void vfn_00d8();
    char _pad_04[0x98];
};
struct NiNode : NiAVObject
{
    virtual void AttachChildInAvailableSlot(NiAVObject* pkChild, bool abFirstAvailableSlot);
    char _pad_9c[0x10];
};
struct FUN_0051cf00 : NiNode
{
    FUN_0051cf00();
    char _pad_ac[0x8];
};
struct NiTriBasedGeom : NiAVObject
{
    char _pad_9c[0x24];
};
struct NiTriShape : NiTriBasedGeom
{
    NiTriShape(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, void* pkColor, NiPoint2* pkTexture,
               unsigned short usNumTextureSets, unsigned int eNBTMethod, unsigned short usTriangles,
               unsigned short* pusTriList);
    char _pad_c0[0x4];
};
struct NiPointLight : NiAVObject
{
    char _pad_9c[0x58];
};
struct NiDirectionalLight : NiPointLight
{
    NiDirectionalLight();
    char _pad_f4[0x8];
};
struct FUN_004bc280_S
{
};
struct GlobalObject_00e98f20
{
    GlobalObject_00e98f20(int, int);
    char _pad_00[0x34];
};
struct QuantityData
{
};
struct TESObjectREFR
{
};
struct FUN_00632d20_shell
{
};
struct RadioSignal
{
};
struct FUN_00baf3c0_S
{
};
struct FUN_00bb0180_S
{
};
struct NP
{
    NP& operator=(void*);
};
struct Flt
{
    operator unsigned int() const;
};
struct Setting_S
{
};


struct FUN_00640810_t
{
    void FUN_00640810(NiNode* apSkyRoot);
};

// @fnv 0x00640810
void FUN_00640810_t::FUN_00640810(NiNode* apSkyRoot)
{
    NiPoint3* psunNormals;
    NiPoint3* pglareNormals;
    RgbaColor* psunColors;
    unsigned short* sglareVertOrder;
    NiPoint3* pglareVertices;
    RgbaColor* pglareColors;
    ShaderPropertyConversionData bsshaderdata;
    unsigned short* ssunVertOrder;
    NiPoint3* psunVertices;
    NiPoint2* psunTexture;
    NiPoint2* pglareTexture;

    reinterpret_cast<::F940Owner *>((((_::SkyObject*)(Sun*)this)))->CreateSortAdjustNode((::F940Parent *)(apSkyRoot));

    psunVertices = new _::SunPoint3[4];
    psunVertices[0] = _::SunPoint3(-1.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce7c)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce7c)))))), 0.0f);
    psunVertices[1] = _::SunPoint3(-1.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce7c)))))), -1.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce7c)))))), 0.0f);
    psunVertices[2] = _::SunPoint3(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce7c)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce7c)))))), 0.0f);
    psunVertices[3] = _::SunPoint3(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce7c)))))), -1.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce7c)))))), 0.0f);

    psunNormals = new _::SunPoint3[4];
    psunNormals[0] = (*reinterpret_cast<::fnv_00640810::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    psunNormals[1] = (*reinterpret_cast<::fnv_00640810::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    psunNormals[2] = (*reinterpret_cast<::fnv_00640810::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    psunNormals[3] = (*reinterpret_cast<::fnv_00640810::NiPoint3 *>((void *)&::NiPoint3::ZERO));

    pglareVertices = new _::SunPoint3[4];
    pglareVertices[0] = _::SunPoint3(-1.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce50)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce50)))))), 0.0f);
    pglareVertices[1] = _::SunPoint3(-1.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce50)))))), -1.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce50)))))), 0.0f);
    pglareVertices[2] = _::SunPoint3(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce50)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce50)))))), 0.0f);
    pglareVertices[3] = _::SunPoint3(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce50)))))), -1.0 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00640810::Setting_S *>(&::g_011cce50)))))), 0.0f);

    pglareNormals = new _::SunPoint3[4];
    pglareNormals[0] = (*reinterpret_cast<::fnv_00640810::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    pglareNormals[1] = (*reinterpret_cast<::fnv_00640810::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    pglareNormals[2] = (*reinterpret_cast<::fnv_00640810::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    pglareNormals[3] = (*reinterpret_cast<::fnv_00640810::NiPoint3 *>((void *)&::NiPoint3::ZERO));

    {
        _::SunColorA defaultColor(1.0f, 0.0f, 0.0f, 1.0f);

        psunColors = new _::SunColorA[4];
        psunColors[0] = defaultColor;
        psunColors[1] = defaultColor;
        psunColors[2] = defaultColor;
        psunColors[3] = defaultColor;

        pglareColors = new _::SunColorA[4];
        pglareColors[0] = defaultColor;
        pglareColors[1] = defaultColor;
        pglareColors[2] = defaultColor;
        pglareColors[3] = defaultColor;
    }

    psunTexture = new _::SunPoint2[4];
    psunTexture[0] = _::SunPoint2(0.0f, 0.0f);
    psunTexture[1] = _::SunPoint2(0.0f, 1.0f);
    psunTexture[2] = _::SunPoint2(1.0f, 0.0f);
    psunTexture[3] = _::SunPoint2(1.0f, 1.0f);

    pglareTexture = new _::SunPoint2[4];
    pglareTexture[0] = _::SunPoint2(0.0f, 0.0f);
    pglareTexture[1] = _::SunPoint2(0.0f, 1.0f);
    pglareTexture[2] = _::SunPoint2(1.0f, 0.0f);
    pglareTexture[3] = _::SunPoint2(1.0f, 1.0f);

    ssunVertOrder = (unsigned short*)::FUN_00aa1070(sizeof(unsigned short) * 6);
    ssunVertOrder[0] = 0;
    ssunVertOrder[1] = 1;
    ssunVertOrder[2] = 2;
    ssunVertOrder[3] = 2;
    ssunVertOrder[4] = 1;
    ssunVertOrder[5] = 3;

    sglareVertOrder = (unsigned short*)::FUN_00aa1070(sizeof(unsigned short) * 6);
    sglareVertOrder[0] = 0;
    sglareVertOrder[1] = 1;
    sglareVertOrder[2] = 2;
    sglareVertOrder[3] = 2;
    sglareVertOrder[4] = 1;
    sglareVertOrder[5] = 3;

    (NP&)((Sun*)this)->m_pThirdSceneObject =
        new NiTriShape(4, psunVertices, psunNormals, psunColors, psunTexture, 1, 0, 2, ssunVertOrder);
    reinterpret_cast<::TaskQueueInterface *>((((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pThirdSceneObject)))->FUN_004902f0(true);

    (NP&)((Sun*)this)->m_pFirstSceneObject = new FUN_0051cf00;
    reinterpret_cast<::TaskQueueInterface *>((((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pFirstSceneObject)))->FUN_004902f0(true);
    reinterpret_cast<::NiTriGeom2 *>((((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pFirstSceneObject)))->FUN_0051d000(2);
    ((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pFirstSceneObject)
        ->AttachChildInAvailableSlot((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pThirdSceneObject, true);

    (NP&)((Sun*)this)->m_pFourthSceneObject =
        new NiTriShape(4, pglareVertices, pglareNormals, pglareColors, pglareTexture, 1, 0, 2, sglareVertOrder);
    reinterpret_cast<::TaskQueueInterface *>((((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pFourthSceneObject)))->FUN_004902f0(true);

    (NP&)((Sun*)this)->m_pSecondSceneObject = new FUN_0051cf00;
    reinterpret_cast<::TaskQueueInterface *>((((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pSecondSceneObject)))->FUN_004902f0(true);
    reinterpret_cast<::NiTriGeom2 *>((((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pSecondSceneObject)))->FUN_0051d000(2);
    reinterpret_cast<::FUN_00440490_shell *>((((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pSecondSceneObject)))->FUN_00440490(((Sun*)this)->m_fSunGlareIntensity);
    ((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pSecondSceneObject)
        ->AttachChildInAvailableSlot((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pFourthSceneObject, true);

    ((NiNode*)(unsigned int)(const Flt&)((Sun*)this)->m_pRootNode)
        ->AttachChildInAvailableSlot((FUN_0051cf00*)(unsigned int)(const Flt&)((Sun*)this)->m_pFirstSceneObject, true);

    (NP&)((Sun*)this)->m_pMenuLight = new NiDirectionalLight;
    reinterpret_cast<::NiPointLight *>((((NiDirectionalLight*)(unsigned int)(const Flt&)((Sun*)this)->m_pMenuLight)))->FUN_0050dd20(1.0f);
    reinterpret_cast<::FUN_004bc280_S *>((((FUN_004bc280_S*)(unsigned int)(const Flt&)((Sun*)this)->m_pMenuLight)))->FUN_004bc280((const ::C3 *)(const ::fnv_00640810::C3 *)((const C3*)&(*reinterpret_cast<::fnv_00640810::NiColor *>(&::DAT_011a9b7c))));
    reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((((NiDirectionalLight*)(unsigned int)(const Flt&)((Sun*)this)->m_pMenuLight)))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)((const NiPoint3&)(*reinterpret_cast<::fnv_00640810::NiColor *>(&::DAT_011a9b7c))));
    ((NiNode*)(unsigned int)(const Flt&)((Sun*)this)->m_pRootNode)
        ->AttachChildInAvailableSlot((NiDirectionalLight*)(unsigned int)(const Flt&)((Sun*)this)->m_pMenuLight, true);

    ((Sun*)this)->m_pSunGlarePick = new GlobalObject_00e98f20(0, 8);
    reinterpret_cast<::FUN_00537e90 *>((((QuantityData*)((Sun*)this)->m_pSunGlarePick)))->SetQuantity(1);
    reinterpret_cast<::TESRegionGrassObject *>((((TESObjectREFR*)((Sun*)this)->m_pSunGlarePick)))->AssignLandTexture((::TESLandTexture *)(1));
    reinterpret_cast<::FUN_00632d20_shell *>((((FUN_00632d20_shell*)((Sun*)this)->m_pSunGlarePick)))->FUN_00632d20(true);
    reinterpret_cast<::FUN_00458b30_class *>((((RadioSignal*)((Sun*)this)->m_pSunGlarePick)))->SetByteAtOffset17(1);

    new ((void *)(((FUN_00baf3c0_S*)&bsshaderdata))) ::fnv_00baf3c0::FUN_00baf3c0();
    bsshaderdata.m_iShaderType = 6;
    bsshaderdata.m_iShaderOptionIndex = 0;
    reinterpret_cast<::FUN_00bb0180_shell *>((((FUN_00bb0180_S*)&bsshaderdata)))->AddProperties((::NiAVObject *)(::fnv_00640810::NiAVObject *)((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pThirdSceneObject), 1);
    bsshaderdata.m_iShaderOptionIndex = 1;
    reinterpret_cast<::FUN_00bb0180_shell *>((((FUN_00bb0180_S*)&bsshaderdata)))->AddProperties((::NiAVObject *)(::fnv_00640810::NiAVObject *)((NiTriShape*)(unsigned int)(const Flt&)((Sun*)this)->m_pFourthSceneObject), 1);
}
}  // namespace fnv_00640810

namespace fnv_00641830 {
struct Actor;
struct Atmosphere;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSFile;
struct BSFogProperty;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct Clouds;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImageSpaceModifierInstanceForm;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct Moon;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiDirectionalLight;
struct NiFogProperty;
struct NiNode;
struct NiPick;
struct NiRenderedTexture;
struct NiStream;
struct Precipitation;
struct SeenData;
struct Sky;
struct SkyTextureManager;
struct Stars;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectREFR;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWeather;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
struct FUN_00641830_shell : public Sun
{
    void UpdateSun(Sky*, float);
};

struct TES;
struct C3;
struct V3;
struct NiNode_00558310;
namespace H {
struct AutoMemContext
{
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
    int pad;
};
struct ThreeByThreeMatrix
{
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
    void SetYRotation(float);
    float m[9];
};
struct SkyObject
{
};
struct NiPoint3
{
    void ComputeMagnitude();
};
}
struct Setting_S
{
};
struct GlobalObject_0044f440
{
};
struct Flt
{
    operator unsigned int() const;
};
struct RgbaColor
{
    RgbaColor(float, float, float, float);
    float r, g, b, a;
};
struct P3
{
};
struct TESObjectTREE
{
};
struct TESDataHandler
{
};
struct NiAVObject
{
};
struct FUN_00440460_S
{
};
struct BGSTerrainManager
{
};
struct BSAudio
{
};
struct Sky
{
    bool IsFlag4Set();
};
struct FUN_00476980_S
{
};
struct CP_008c48d0
{
};
struct FUN_004a0c90_shell
{
};
struct FUN_004bc280_S
{
};
struct NiPointLight
{
    void FUN_0050dd50(const NiPoint3&);
};
struct TESWeather
{
    float GetWeatherData(int, float, float);
};
struct KFModel
{
};
struct EffectSetting
{
};
struct AnimIdle
{
};
struct PropHelper
{
};
struct Cell_S
{
};
struct Sun_S
{
    void* pad[8];
    float m_fSunGlareIntensity;
};
extern float DAT_0104f2a8;

// @fnv 0x00641830
void FUN_00641830_shell::UpdateSun(Sky* apSky, float afSecondsPassed)
{
    H::AutoMemContext tempMemContext(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sun.cpp",
                                     300);
    NiPoint3 newLoc = (*reinterpret_cast<::fnv_00641830::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    float fhour = ::GetFieldEC((const char*)apSky);
    reinterpret_cast<::FUN_008d0600_s *>((((H::SkyObject*)this)))->FUN_008d0600((int)(apSky), afSecondsPassed);
    if (((int)(reinterpret_cast<::FUN_00476c90_Class *>((apSky))->FUN_00476c90())) == 0)
    {
        H::ThreeByThreeMatrix lightDir = (*reinterpret_cast<::fnv_00641830::H::ThreeByThreeMatrix *>(&::DAT_011a9448));
        TESObjectCELL* pcell = (*reinterpret_cast<::fnv_00641830::TES * *>(&::g_TES)) ? ((::fnv_00641830::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)(*reinterpret_cast<::fnv_00641830::TES * *>(&::g_TES)))))->GetPrevPath())) : 0;
        if (pcell)
        {
            H::ThreeByThreeMatrix rotmat;
            new ((void *)(&rotmat)) ::Vec3();
            reinterpret_cast<::FUN_004a0c90_shell *>((((FUN_004a0c90_shell*)&lightDir)))->FUN_004a0c90(reinterpret_cast<::fnv_00544910::FUN_00544910_shell *>((((Cell_S*)pcell)))->FUN_00544910() * ::DAT_01023128);
            reinterpret_cast<::ThreeByThreeMatrix *>(&(rotmat))->SetYRotation(reinterpret_cast<::fnv_00544970::FUN_00544970_shell *>((((Cell_S*)pcell)))->FUN_00544970() * ::DAT_01023128);
            lightDir = lightDir * rotmat;
        }
        else
        {
            reinterpret_cast<::FUN_00642660_shell *>(&(lightDir))->SetMatrixElement(1, 0, DAT_0104f2a8);
            reinterpret_cast<::FUN_00642660_shell *>(&(lightDir))->SetMatrixElement(2, 0, DAT_0104f2a8);
        }
        reinterpret_cast<::FUN_0043fa80_s *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0x1c))))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(lightDir));
        reinterpret_cast<::FUN_004bc280_S *>((((FUN_004bc280_S*)(unsigned int)*(Flt*)((char*)this + 0x1c))))->FUN_004bc280((const ::C3 *)(const ::fnv_00641830::C3 *)(((::fnv_00641830::C3 *)(::FUN_004ea950((int)(((TESDataHandler*)apSky)))))));
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(*((::fnv_00641830::NiPoint3 *)(reinterpret_cast<::TESObjectTREE *>((((TESObjectTREE*)apSky)))->GetData()))));
        ((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))
            ->FUN_0050dd50(*((::fnv_00641830::NiPoint3 *)(::FUN_00514f30((int)(((TESDataHandler*)apSky))))));
    }
    else if (((int)(reinterpret_cast<::FUN_00476c90_Class *>((apSky))->FUN_00476c90())) == 1)
    {
        H::ThreeByThreeMatrix lightDir = (*reinterpret_cast<::fnv_00641830::H::ThreeByThreeMatrix *>(&::DAT_011a9448));
        TESObjectCELL* pcell = (*reinterpret_cast<::fnv_00641830::TES * *>(&::g_TES)) ? ((::fnv_00641830::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)(*reinterpret_cast<::fnv_00641830::TES * *>(&::g_TES)))))->GetPrevPath())) : 0;
        if (pcell)
        {
            H::ThreeByThreeMatrix rotmat;
            new ((void *)(&rotmat)) ::Vec3();
            reinterpret_cast<::FUN_004a0c90_shell *>((((FUN_004a0c90_shell*)&lightDir)))->FUN_004a0c90(reinterpret_cast<::fnv_00544910::FUN_00544910_shell *>((((Cell_S*)pcell)))->FUN_00544910() * ::DAT_01023128);
            reinterpret_cast<::ThreeByThreeMatrix *>(&(rotmat))->SetYRotation(reinterpret_cast<::fnv_00544970::FUN_00544970_shell *>((((Cell_S*)pcell)))->FUN_00544970() * ::DAT_01023128);
            lightDir = lightDir * rotmat;
        }
        else
        {
            reinterpret_cast<::FUN_00642660_shell *>(&(lightDir))->SetMatrixElement(1, 0, DAT_0104f2a8);
            reinterpret_cast<::FUN_00642660_shell *>(&(lightDir))->SetMatrixElement(2, 0, DAT_0104f2a8);
        }
        reinterpret_cast<::FUN_0043fa80_s *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0x1c))))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(lightDir));
        reinterpret_cast<::FUN_004bc280_S *>((((FUN_004bc280_S*)(unsigned int)*(Flt*)((char*)this + 0x1c))))->FUN_004bc280((const ::C3 *)(const ::fnv_00641830::C3 *)(((::fnv_00641830::C3 *)(::FUN_004ea950((int)(((TESDataHandler*)apSky)))))));
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(*((::fnv_00641830::NiPoint3 *)(reinterpret_cast<::TESObjectTREE *>((((TESObjectTREE*)apSky)))->GetData()))));
        ((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))
            ->FUN_0050dd50(*((::fnv_00641830::NiPoint3 *)(::FUN_00514f30((int)(((TESDataHandler*)apSky))))));
    }
    else if (((int)(reinterpret_cast<::FUN_00476c90_Class *>((apSky))->FUN_00476c90())) == 3 || ((int)(reinterpret_cast<::FUN_00476c90_Class *>((apSky))->FUN_00476c90())) == 2)
    {
        reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 4))))->QueueActorDisarm(!reinterpret_cast<::FUN_006366b0_shell *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 4))))->FUN_006366b0());
        float fSunriseBegin = (::fnv_00595f50::FUN_00595f50((::fnv_00595f50::Sky *)(char *)((char*)apSky)) + ::FUN_00595ea0((char*)apSky)) / 2.0;
        float fSunsetEnd = (reinterpret_cast<::FUN_00596030_cls *>((apSky))->FUN_00596030() + ::fnv_00595fc0::FUN_00595fc0((char*)apSky)) / 2.0;
        float fhalftrans = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting82)))))) * ::DAT_01011588;
        float fAlphaInBegin = fSunriseBegin - fhalftrans;
        float fAlphaInEnd = fSunriseBegin + fhalftrans;
        float fAlphaOutBegin = fSunsetEnd - fhalftrans;
        float fAlphaOutEnd = fSunsetEnd + fhalftrans;
        float fDiscAlpha = 1.0f;
        if (!(fAlphaInBegin <= fhour && fhour <= fAlphaOutEnd))
        {
            fDiscAlpha = 0.0f;
        }
        else if (fAlphaInBegin < fhour && fhour < fAlphaInEnd)
        {
            fDiscAlpha = (fhour - fAlphaInBegin) / (fAlphaInEnd - fAlphaInBegin);
        }
        else if (fAlphaOutBegin < fhour && fhour < fAlphaOutEnd)
        {
            fDiscAlpha = 1.0f - (fhour - fAlphaOutBegin) / (fAlphaOutEnd - fAlphaOutBegin);
        }
        TESWeather* pCurr = (TESWeather*)((void *)(reinterpret_cast<::MagicCaster_shell *>((((BSAudio*)apSky)))->FUN_0044edb0()));
        TESWeather* pLast = (TESWeather*)((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((AnimIdle*)apSky)))->FUN_00825c00()));
        float fCurrPct = ::FUN_006447d0((const char*)apSky);
        float fGlareAlpha = (pCurr ? pCurr->GetWeatherData(4, fCurrPct * fDiscAlpha, 0.0f) : fDiscAlpha) +
                            (pLast ? pLast->GetWeatherData(4, (1.0f - fCurrPct) * fDiscAlpha, 0.0f) : 0.0f);
        void* pshadeProperty =
            ((((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x10))))->FUN_00a59d30(3))) == 0)
                 ? 0
                 : (reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x10))))->FUN_00a59d30(3))))))->GetMinLevel() == 13))
                ? ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x10))))->FUN_00a59d30(3)))
                : 0;
        if (pshadeProperty)
        {
            *(RgbaColor*)((char*)pshadeProperty + 0x60) =
                RgbaColor(((float *)(::FUN_00461110((int)(((TESDataHandler*)apSky)))))[0],
                          ((float *)(::FUN_00461110((int)(((TESDataHandler*)apSky)))))[1],
                          ((float *)(::FUN_00461110((int)(((TESDataHandler*)apSky)))))[2], fDiscAlpha);
        }
        pshadeProperty =
            ((((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x14))))->FUN_00a59d30(3))) == 0)
                 ? 0
                 : (reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x14))))->FUN_00a59d30(3))))))->GetMinLevel() == 13))
                ? ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)(unsigned int)*(Flt*)((char*)this + 0x14))))->FUN_00a59d30(3)))
                : 0;
        if (pshadeProperty)
        {
            *(RgbaColor*)((char*)pshadeProperty + 0x60) =
                RgbaColor(((float *)(::FUN_00461110((int)(((TESDataHandler*)apSky)))))[0],
                          ((float *)(::FUN_00461110((int)(((TESDataHandler*)apSky)))))[1],
                          ((float *)(::FUN_00461110((int)(((TESDataHandler*)apSky)))))[2], fGlareAlpha);
        }
        {
            float fxNewAim = 0.0f;
            H::ThreeByThreeMatrix newSunRot = (*reinterpret_cast<::fnv_00641830::H::ThreeByThreeMatrix *>(&::DAT_011a9448));
            float ftemp;
            NiPoint3 ksundirection;
            if (fAlphaInBegin < fhour && fhour < fAlphaOutEnd)
            {
                ftemp = (fhour - fAlphaInBegin) / (fAlphaOutEnd - fAlphaInBegin);
                fxNewAim = (1.0 - 2.0 * ftemp) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting83))))));
            }
            else if (fhour >= fAlphaOutEnd)
            {
                ftemp = (fhour - fAlphaOutEnd) / (24.0 - (fAlphaOutEnd - fAlphaInBegin));
                fxNewAim = (2.0 * ftemp - 1.0) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting83))))));
            }
            else if (fhour <= fAlphaInBegin)
            {
                ftemp = (24.0 - fAlphaOutEnd + fhour) / (24.0 - (fAlphaOutEnd - fAlphaInBegin));
                fxNewAim = (2.0 * ftemp - 1.0) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting83))))));
            }
            newLoc.x = fxNewAim;
            newLoc.y = reinterpret_cast<::FUN_00450410_Class *>((((GlobalObject_0044f440*)&(*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting84)))))->FUN_00450410();
            newLoc.z = ::FUN_00408860(reinterpret_cast<::FUN_00450410_Class *>((((GlobalObject_0044f440*)&(*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting83)))))->FUN_00450410()) -
                       ::FUN_00408860(fxNewAim);
            reinterpret_cast<::FUN_00440460_S *>((((FUN_00440460_S*)(unsigned int)*(Flt*)((char*)this + 4))))->FUN_00440460((const ::V3 *)(const ::fnv_00641830::V3 *)((const V3*)&newLoc));
            reinterpret_cast<::FUN_00440460_S *>((((FUN_00440460_S*)(unsigned int)*(Flt*)((char*)this + 0xc))))->FUN_00440460((const ::V3 *)(const ::fnv_00641830::V3 *)((const V3*)&newLoc));
            reinterpret_cast<::FUN_00416870_t *>((((P3*)&ksundirection)))->FUN_00416870(-fxNewAim, reinterpret_cast<::FUN_00450410_Class *>((((GlobalObject_0044f440*)&(*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting84)))))->FUN_00450410(),
                      reinterpret_cast<::FUN_00450410_Class *>((((GlobalObject_0044f440*)&(*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting85)))))->FUN_00450410());
            reinterpret_cast<::FUN_004a0c10_s *>((((H::NiPoint3*)&ksundirection)))->FUN_004a0c10();
            reinterpret_cast<::FUN_004769c0_shell *>((((FUN_00476980_S*)&newSunRot)))->FUN_004769c0(0, (float *)((int)&ksundirection));
            reinterpret_cast<::FUN_0043fa80_s *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0x1c))))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(newSunRot));
            reinterpret_cast<::FUN_004bc280_S *>((((FUN_004bc280_S*)(unsigned int)*(Flt*)((char*)this + 0x1c))))->FUN_004bc280((const ::C3 *)(const ::fnv_00641830::C3 *)(((::fnv_00641830::C3 *)(::FUN_004ea950((int)(((TESDataHandler*)apSky)))))));
            reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(*((::fnv_00641830::NiPoint3 *)(reinterpret_cast<::TESObjectTREE *>((((TESObjectTREE*)apSky)))->GetData()))));
            ((NiPointLight*)(unsigned int)*(Flt*)((char*)this + 0x1c))
                ->FUN_0050dd50(*((::fnv_00641830::NiPoint3 *)(::FUN_00514f30((int)(((TESDataHandler*)apSky))))));
        }
        if ((*reinterpret_cast<::fnv_00641830::TES * *>(&::g_TES)) && reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<::fnv_00641830::TES * *>(&::g_TES))))->FUN_0084e3a0())
        {
            NiPoint3 origin = *((::fnv_00641830::NiPoint3 *)&(reinterpret_cast<::NiAVObject *>((((TESDataHandler*)((::fnv_00641830::NiAVObject *)(::FUN_00558310((::NiNode_00558310 *)(::fnv_00641830::NiNode_00558310 *)(((::fnv_00641830::NiNode_00558310 *)(::FUN_0045c670())))))))))->FUN_0043c490()));
            NiPoint3 direction = newLoc;
            float fscaleChange = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting81)))))) * afSecondsPassed;
            reinterpret_cast<::FUN_004a0c10_s *>((((H::NiPoint3*)&direction)))->FUN_004a0c10();
            bool bblocked =
                reinterpret_cast<::FUN_006427c0_Class *>((((Sun_S*)this)))->FUN_006427c0() >= 1.0 || (((void *)(::FUN_0070ec90((char *)(((EffectSetting*)(*reinterpret_cast<::fnv_00641830::TES * *>(&::g_TES))))))), ((bool)(::FUN_004e2180())));
            float fscale = ::fnv_004dd130::FUN_004dd130(1.0f - reinterpret_cast<::FUN_006427c0_Class *>((((Sun_S*)this)))->FUN_006427c0(), ::DAT_010162c0);
            reinterpret_cast<::FUN_00642890_Class *>((((Sun_S*)this)))->FUN_00642890();
            if (bblocked || fscale < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting80)))))))
            {
                if (((Sun_S*)this)->m_fSunGlareIntensity - fscaleChange < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00641830::Setting_S *>(&::originalRuntimeFloatSetting80)))))))
                {
                    reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))))->QueueActorDisarm(true);
                    ((Sun_S*)this)->m_fSunGlareIntensity = 0.0f;
                }
                else
                {
                    reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))))->QueueActorDisarm(false);
                    ((Sun_S*)this)->m_fSunGlareIntensity -= fscaleChange;
                    reinterpret_cast<::FUN_00440490_shell *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))))->FUN_00440490(((Sun_S*)this)->m_fSunGlareIntensity);
                }
            }
            else
            {
                if (((Sun_S*)this)->m_fSunGlareIntensity + fscaleChange >= fscale ||
                    ((Sun_S*)this)->m_fSunGlareIntensity >= fscale)
                {
                    ((Sun_S*)this)->m_fSunGlareIntensity = fscale;
                }
                else
                {
                    ((Sun_S*)this)->m_fSunGlareIntensity += fscaleChange;
                }
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))))->QueueActorDisarm(false);
                reinterpret_cast<::FUN_00440490_shell *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))))->FUN_00440490(((Sun_S*)this)->m_fSunGlareIntensity);
            }
            if (!reinterpret_cast<::FUN_006366b0_shell *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))))->FUN_006366b0())
            {
                reinterpret_cast<::TaskQueueInterface *>((((NiAVObject*)(unsigned int)*(Flt*)((char*)this + 0xc))))->QueueActorDisarm(true);
            }
        }
        if (apSky->IsFlag4Set())
        {
            reinterpret_cast<::TaskQueueInterface *>((((::fnv_00641830::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>((((KFModel*)this)))->GetRegionMapName()))))->QueueActorDisarm(true);
        }
        else
        {
            reinterpret_cast<::TaskQueueInterface *>((((::fnv_00641830::NiAVObject *)(reinterpret_cast<::TESRegionDataMap *>((((KFModel*)this)))->GetRegionMapName()))))->QueueActorDisarm(false);
        }
    }
}
}  // namespace fnv_00641830

struct FUN_00642680_shell
{
    float m_data[3][3];
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
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
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    unsigned int unk118;
    bool IsFlag4Set();
};

// @fnv 0x00642680
bool FUN_00642680_shell::IsFlag4Set()
{
    return 0 < (unk118 & 4);
}

struct SunGlarePick
{
    ~SunGlarePick();
};

class FUN_006406a0 : public SkyObject
{
  public:
    virtual ~FUN_006406a0();
    NiPointer<NiAVObject> m_pFirstSceneObject, m_pSecondSceneObject, m_pThirdSceneObject, m_pFourthSceneObject;
    SunGlarePick* m_pSunGlarePick;
    NiPointer<NiAVObject> m_pMenuLight;
    float m_fSunGlareIntensity;
    bool bDoOcclusionTests;
    NiPointer<NiAVObject> m_pSunShaderAccumulator;
};
// @fnv 0x00640670
void* FUN_00640670_shell::FUN_00640670(unsigned int flags)
{
    reinterpret_cast<::FUN_006406a0 *>((this))->FUN_006406a0::~FUN_006406a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x006406a0
FUN_006406a0::~FUN_006406a0()
{
    m_pRootNode = 0;
    m_pFirstSceneObject = 0;
    m_pSecondSceneObject = 0;
    m_pThirdSceneObject = 0;
    m_pFourthSceneObject = 0;
    m_pMenuLight = 0;
    if (m_pSunGlarePick)
        delete m_pSunGlarePick;
    m_pSunShaderAccumulator = 0;
}

// Sun update: with a world and enabled, point the glare at the new target and run its update at a scaled time step.


class AutoMemHelper
{
  public:
    AutoMemHelper(int aiMemoryContext, bool bPush, const char* pcFile, int iLine);
    ~AutoMemHelper();

    int m_iContext;
};

class A6A0World
{
  public:
};

class A6A0Target
{
  public:
};

class A6A0Ref
{
  public:
    void Reset(void* pvObject);
};

class A6A0Sun
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    bool m_bEnableState;
    unsigned char unk25;
    unsigned char unk26;
    unsigned char unk27;
    A6A0Ref m_kRoomNode;

    void FUN_006426a0(void* pvArg0, A6A0Target* pkTarget, void* pvArg1);
};

// @fnv 0x006426a0
void A6A0Sun::FUN_006426a0(void* pvArg0, A6A0Target* pkTarget, void* pvArg1)
{
    AutoMemHelper kMem(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sun.cpp", 0x222);
    if (((::A6A0World *)(::fnv_006fa820::FUN_006fa820((const char *)this))) && m_bEnableState)
    {
        A6A0Target* pkCurrent = pkTarget;
        if (pkCurrent)
        {
            m_kRoomNode.Reset(pkTarget);
            A6A0World* pkWorld = ((::A6A0World *)(::fnv_006fa820::FUN_006fa820((const char *)this)));
            reinterpret_cast<::FUN_006427a0_Class *>((pkWorld))->SetValue((float)(reinterpret_cast<::FUN_008d01e0_Class *>((pkWorld))->FUN_008d01e0() / ::DAT_0104f2f0));
            reinterpret_cast<::Candidate *>((pkCurrent))->RenderGeometryPass(pkWorld, (unsigned int)(pvArg0), pvArg1);
            reinterpret_cast<::FUN_006427a0_Class *>((pkWorld))->SetValue((float)(reinterpret_cast<::FUN_008d01e0_Class *>((pkWorld))->FUN_008d01e0() * ::DAT_0104f2f0));
        }
    }
}

#include "generated/data/fallout_shared/sky/sun.inc"
