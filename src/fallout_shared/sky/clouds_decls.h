// fallout_shared/sky/clouds_decls.h: declares NiFixedString, NiColor, RgbaColor, NiProperty, NiTimeController and more
#ifndef FNV_CLOUDS_DECLS_H
#define FNV_CLOUDS_DECLS_H

#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/F940Owner.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004536e0_Class.h"
#include "fnv/decl/FUN_00476c90_Class.h"
#include "fnv/decl/FUN_0050d100_shell.h"
#include "fnv/decl/FUN_0051b8c0_shell.h"
#include "fnv/decl/FUN_006347a0_Class.h"
#include "fnv/decl/FUN_006347c0_Class.h"
#include "fnv/decl/FUN_00634830_cls.h"
#include "fnv/decl/FUN_00634850_Class.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00bae930_Class.h"
#include "fnv/decl/FUN_00c3a8a0_cls.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_01200000.h"
class NiNode;
class NiGeometry;
class NiTexture;
class Sky;
class TESWeather;
class NiProperty;
class SkyShaderProperty;
class NiTimeController;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen, sMaxLen;
    BSStringT();
    ~BSStringT();
    BSStringT& operator=(const T*);
    BSStringT& operator+=(const T*);
    operator const T*() const;
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
class NiColor
{
  public:
    float r, g, b;
};
class RgbaColor
{
  public:
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};
class NiProperty
{
};
class NiTimeController
{
  public:
};
class NiObjectNET
{
  public:
};
class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual NiGeometry* vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
};
class NiGeometry : public NiAVObject
{
  public:
};
class CloudsColorController : public NiTimeController
{
  public:
    unsigned char layoutPadding[0x60];
    RgbaColor color;
};
class SkyShaderProperty : public NiProperty
{
  public:
    void SetTexture(NiTexture*);
};
class TESTexture1024
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual const char* vfn_18();
    unsigned int GetModelLength() const;
};
class TESWeather
{
  public:
};
class Sky
{
  public:
};
class SkyObject
{
  public:
    void** m_ppVirtualMethodTable;
    NiPointer<NiNode> m_pRootNode;
};
class Clouds : public SkyObject
{
  public:
    NiPointer<NiGeometry> m_pCloudLayerGeometry[4];
    NiPointer<NiTexture> m_pCloudLayerTexture[4];
    NiColor pColors[4];
    unsigned short m_usCloudCount;
    bool bForceUpdate;
    void Initialize(NiNode*);
    void Update(Sky*, float);
    void SetCloudCount(int);
};
union SETTING_VALUE
{
    float f;
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
};
struct NiRTTI;
void AddToFloatArray(unsigned short, float);
class SkyTextureManager
{
  public:
    static void LoadTextureFromPath(NiPointer<NiTexture>*, const char*);
};
class BSShaderManager
{
  public:
    static void GetTexture(const char*, bool, NiPointer<NiTexture>&, bool, bool);
};

class NiAVObject;
class NiNode : public NiAVObject
{
  public:
    virtual void AddObject(NiAVObject*, bool);
public:
    ::NiAVObject *GetAt(unsigned int);
};
class NiStream
{
  public:
    virtual ~NiStream();
    unsigned char layoutPadding[0x5c0];
};
class BSNodeReferences;
class BSStream : public NiStream
{
  public:
    void* m_pObjectNameMap;
    NiPointer<BSNodeReferences> m_spNodeReferences;
    BSStream();
    virtual ~BSStream();
};
class Model
{
  public:
    char* pFilename;
    int BackgroundTask, m_iActualRefCount;
    NiPointer<NiNode> m_spNode;
    Model(const char*, BSStream*, bool, bool);
    ~Model();
};
#endif
