// fallout_shared/bipedanim_decls.h: declares NiPoint3, CloningProcess, NiFixedString, NiMemObject, NiObject and more
#ifndef BIPEDANIM_DECLS_H
#define BIPEDANIM_DECLS_H

#include <new>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSXFlags.h"
#include "fnv/decl/BipedWeaponRemoval.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CloneSourceA5d6.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_004303e0_Class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_004700d0_class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00504e60_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00572160_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0065a970_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008b0bd0_shell.h"
#include "fnv/decl/FUN_00950b30_Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a5be90_shell.h"
#include "fnv/decl/Fake_FUN_004a2020.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiObjectD510.h"
#include "fnv/decl/QueueHelper.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/W_0043b4f0.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004436c0__FUN_004436c0_Class.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00567050__FUN_00567050_shell.h"
#include "fnv/decl/fnv_00571760__Actor.h"
#include "fnv/decl/fnv_006148f0__FUN_006148f0_shell.h"
#include "fnv/decl/fnv_006149b0__RaceTexture.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008b0b00__FUN_008b0b00_cls.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00441000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00491000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004ab000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00572000.h"
#include "fnv/symbols_00577000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e4000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6c000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01199000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
struct NiUpdateData;
class BSShaderPPLightingProperty;
class NiTexture;
class NiSourceTexture;
class QueuedFile;
struct QueuedHelmet;
class TESBipedModelForm;
class NiNode;
class NiAVObject;
class BSFadeNode;
class NiTriBasedGeom;
class NiProperty;
class NiExtraData;
class NiSkinData;
class NiSkinPartition;
class NiGeometryData;
class NiSkinInstance;
class TESObjectREFR;
class TESObjectWEAP;
class BSFaceGenModel;
class BipedAnim;
class TESModel;
class TESModelTextureSwap;
class TESBoundObject;
class TESRace;
class TESNPC;
class ExtraDataList;
class ExtraDismemberedLimbs;
struct Animation;
class InventoryStackRecord;
class BaseProcess;
class BGSBipedModelList;
enum BIPED_BONE
{
    BIPED_BONE_WEAPON = 1
};
enum BIPED_OBJECT
{
    BIPED_HEAD = 0,
    BIPED_WEAPON = 5,
    BIPED_COUNT = 20
};
enum SEX
{
    SEX_MALE,
    SEX_FEMALE
};
enum ENUM_FORM_ID
{
    FORM_NPC = 42
};
enum IO_TASK_PRIORITY
{
    TASK_DEFAULT = 0
};
struct NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
struct ThreeByThreeMatrix
{
  public:
    float entry[3][3];
    ThreeByThreeMatrix();
    void SetYRotation(float);
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
public:
    ::ThreeByThreeMatrix operator+(const ::ThreeByThreeMatrix &) const;
};
struct CloningProcess
{
  public:
    void* cloneMap;
    void* processMap;
    int copyType;
    char appendChar;
    NiPoint3 scale;
    CloningProcess(float);
    ~CloningProcess();
};
template <class T> class NiPointer
{
  public:
    T* p;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T*);
    NiPointer& operator=(const NiPointer&);
};
template <class T> class BSStringT
{
  public:
    T* data;
    unsigned short length, capacity;
    BSStringT();
    BSStringT(const T*);
    ~BSStringT();
    int __cdecl PrintfString(const char*, ...);
    operator const T*() const;
    void FUN_004afad0();
};
class NiFixedString
{
  public:
    const char* data;
    NiFixedString(const char*);
    ~NiFixedString();
    operator const char*() const;
};
namespace oldstd {
template <class T> struct vector
{
    unsigned int unk00;
    void* unk04;
    unsigned int unk08;
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
};
}
template <class T> struct FaceGenMatrix
{
  public:
    oldstd::vector<T> kData;
    unsigned int uiRowCount, uiColCount;
    FaceGenMatrix();
    ~FaceGenMatrix();
};
typedef FaceGenMatrix<float> FaceGenCoord;
class NiMemObject
{
  public:
};
struct NiObject : public NiMemObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual NiNode* IsSceneNode();
    virtual BSFadeNode* IsFadeNode();
    virtual void vfn_14();
    virtual NiTriBasedGeom* IsGeometry();
    virtual NiTriBasedGeom* IsTriBasedGeom();
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
    virtual void UpdateDownwardPass(const NiUpdateData&, unsigned int);
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
    unsigned int refCount;
    NiObject* CloneObject(CloningProcess&);
};
class NiTimeController;
struct NiObjectNET : public NiObject
{
  public:
public:
    void GetNumChildren();
};
class NiAVObject : public NiObjectNET
{
  public:
    NiNode* GetParent();
    NiExtraData* GetExtraData(const NiFixedString&);
};
class NiAVObject;
class NiNode : public NiAVObject
{
  public:
    virtual void AddObject(NiAVObject*, bool);
    virtual void AddObjectAt(unsigned int, NiAVObject*);
    virtual void RemoveObject2(NiAVObject*, NiAVObject**);
    virtual void RemoveObject(NiAVObject*);
    unsigned char nodeFields[0xa4];
    NiNode(unsigned short);
    unsigned int FUN_0043b480();
public:
    ::NiAVObject *GetAt(unsigned int);
};
class BSFadeNode : public NiNode
{
  public:
    void* FUN_0043b1b0();
    void SetFadeMode(int);
};
class NiGeometryData : public NiObject
{
};
class NiGeometry : public NiAVObject
{
  public:
};
class NiTriBasedGeom : public NiGeometry
{
  public:
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void ReplaceModelData(NiGeometryData*);
};
class TESForm
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
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
    virtual bool Unk_2B();
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
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetEditorID();
    ENUM_FORM_ID GetFormType() const;
};
class TESBoundObject : public TESForm
{
};
template <class> struct FaceGenMatrix;
class TESNPC : public TESBoundObject
{
  public:
    TESRace* GetRace();
    SEX GetSex(bool);
public:
    void GetFaceGenCoords(FaceGenMatrix<float> (&)[2][2]);
};
class TESObjectWEAP : public TESForm
{
  public:
    bool GetHideBackpack();
    bool GetHasModScope();
};
class TESModel
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual const char* GetModelFilePath();
    virtual void vfn_18();
    virtual TESModelTextureSwap* GetAsModelTextureSwap();
    unsigned char modelFields[20];
    unsigned int GetModelLength() const;
};
class TESModelTextureSwap : public TESModel
{
  public:
    void ApplyTextureSwaps(NiAVObject*);
};
class InventoryStackRecord
{
  public:
    void SetEquipmentState(bool, bool);
    ~InventoryStackRecord();
    TESObjectWEAP* GetObject();
    void* Destroy(unsigned int);
    unsigned char GetWeaponCategory();
    bool SetEquipmentState(unsigned char, float&);
};
class BaseProcess
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
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
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual InventoryStackRecord* GetWeaponInfo();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual NiNode* GetWeaponNode(bool);
    virtual NiNode* GetQuiverNode(bool);
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void UpdateWeaponDrawn(bool, BipedAnim*, Animation*, TESObjectREFR*);
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void SetWeaponModelChanged(bool);
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual NiNode* GetWeaponNode(bool);
    virtual NiNode* GetQuiverNode(bool);
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* GetNiNode_v();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual BipedAnim* GetBipedAnim();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual bool IsCreature();
};
class Actor : public TESObjectREFR
{
  public:
    bool IsAlert();
    void SetAimingWeapon(bool, bool, bool);
    bool IsInIdleState();
};
struct Animation;
struct Biped;
class PlayerCharacter : public Actor
{
  public:
    bool IsAlert();
    void SetAimingWeapon(bool, bool, bool);
public:
    ::Animation *GetAnimation(bool) const;
public:
    ::Biped *FUN_00950b00(bool);
};
class ExtraDismemberedLimbs
{
  public:
};
struct InventoryChanges;
class ExtraDataList
{
  public:
    InventoryChanges* GetContainerChangeData();
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};
struct ModelLoader
{
  public:
};
class TES
{
  public:
    NiObject* CreateDeepCopySameTextures(NiObject*, CloningProcess&);
};
class TESSaveLoadGame
{
  public:
};
class BSFaceGenModel
{
  public:
};
class TESFullName
{
  public:
public:
    void SetFullName(const char *);
};
enum SEX;
class TESActorBase
{
  public:
    SEX GetSex() const;
public:
    ::SEX GetSex();
};
class TESRace : public TESForm
{
  public:
    bool GetBipedObjectModelPath(TESNPC*, BIPED_OBJECT, char*);
    void BuildBodyTexturePath(TESNPC*, char*);
    unsigned char raceFields[0x14];
    TESFullName fullName;
    TESModel* GetBipedObjectModel(SEX, BIPED_OBJECT);
};
class INISettingCollection;
union SETTING_VALUE
{
    bool b;
    int i;
    float f;
};
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
class BipedAnimBone
{
  public:
    unsigned char cFlags;
    NiNode* pParent;
};
class BipedAnimObject
{
  public:
    TESForm* pParent;
    TESModel* m_pModel;
    NiAVObject* m_pSceneObject;
    bool bHasAnimation;
};
class BipedAnim
{
  public:
    void FUN_004abd30(IO_TASK_PRIORITY priority, NiPointer<QueuedHelmet>& queuedHelmet, QueuedFile* file);
    NiNode* root;
    BipedAnimBone bone[5];
    BipedAnimObject object[20];
    BipedAnimObject m_kPreviousObjects[20];
    float m_fFadeAlpha;
    TESObjectREFR* m_pActor;
    void ProcessQueuedHelmet(IO_TASK_PRIORITY, NiPointer<QueuedHelmet>&, QueuedFile*);
    void QueueBipedObjectLoads(unsigned int, IO_TASK_PRIORITY, QueuedFile*);
    void LoadBipedObject(TESNPC*, BIPED_OBJECT, IO_TASK_PRIORITY, QueuedFile*);
    void CompleteModelLoadTask();
    NiNode* GetBoneNode(BIPED_BONE);
    void AttachFaceGenNode();
    void SetBipedVisibility(bool);
    NiAVObject* PrepareBipedModel(NiNode*, BIPED_OBJECT, bool, bool, BSFaceGenModel*);
    NiAVObject* AttachBipedModel(NiNode*, NiNode*, BIPED_OBJECT, bool, bool, BSFaceGenModel*);
    static void AttachFaceGenNode(NiNode*, NiNode*, NiNode*, BipedAnim*, BIPED_OBJECT, BSFaceGenModel*);
    bool IsSlotHidden(BIPED_OBJECT);
    void UpdateBipedWeapon(TESObjectWEAP*, unsigned char);
    void ClearBipedObject(BipedAnimObject*, bool, TESForm*);
    static bool CanLoadHiddenBipedObjects();
    static void ApplyReferenceExtraData(NiNode*, NiNode*, BIPED_OBJECT, TESObjectREFR*);
    static BSShaderPPLightingProperty* FindLightingShaderProperty(NiAVObject*);
    static BIPED_OBJECT GetBipedObjectFromShaderProperty(NiAVObject*, BSShaderPPLightingProperty*);
    bool IsModelPathMatch(TESModel*, char*);
    TESModel* GetModelForSlot(BIPED_OBJECT, TESModel*);
    void RemovePartsByParent(TESForm*);
    void SetBipedObject(TESForm*, TESModel*, BIPED_OBJECT);
    void UpdateRaceSex(TESRace*, SEX);
};
extern int DAT_01188be8[20];
extern const char* DAT_01188b98[20];
bool IsObjectProcessable(NiObject*);
int __cdecl Warning(const char*, ...);
class DialogMenuInterfaceCalls
{
  public:
};
struct Interface
{
  public:
    static void SetHUDVisible(bool);
    static void InitGunScope(TESModel*);
};
template <class T> class NiTNewInterface
{
};
template <class T, class A> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* data;
    unsigned short capacity, size, count, grow;
    NiTArray(unsigned short, unsigned short);
    unsigned int Add(const T&);
};
class TileWorkList
{
  public:
};
class NiExtraData
{
  public:
    unsigned char prefix[0x34];
    TileWorkList children;
};
class NiSkinData : public NiObject
{
  public:
    unsigned int GetBoneCount();
};
class NiSkinPartition : public NiObject
{
};
class NiSkinInstance : public NiObject
{
  public:
    NiSkinPartition* GetSkinPartition();
    void FUN_004addc0(NiSkinPartition*);
    void SetRootParent(NiNode*);
};
const NiFixedString& FUN_004ab220();
NiAVObject* FUN_004ade00(NiNode*, const NiFixedString&);
void FUN_004add50(char*, const char*, unsigned int);
template <class T> unsigned int BSStringLength(const T*);

struct InventoryChanges
{
  public:
};
class SceneObjectLookup
{
  public:
    static NiAVObject* GetObjectByName(NiAVObject*, const char*);
};
struct ShadowSceneNode
{
  public:
    void RemoveObject(NiAVObject*);
    void AddObject(NiAVObject*);
};
class VATS
{
public:
    void FUN_009c8950(bool, bool);
};
class TESDataHandler
{
  public:
};
class BGSListForm;
class BGSBipedModelList
{
  public:
    static BGSBipedModelList* GetBipedModelList(TESForm*);
};

class NiStringExtraData : public NiExtraData
{
  public:
    const NiFixedString& GetString();
};
struct NiRTTI
{
};
class SkyShaderProperty;
const NiFixedString& FUN_004ae780();
struct NiUpdateData
{
  public:
    float time;
    bool updateControllers;
    bool multithreaded;
    bool updateGeom;
    bool updateBounds;
    bool sceneGraphChange;
    NiUpdateData(float, bool, bool);
};
class TimeGlobal
{
  public:
};
class bhkShape
{
};
class bhkFilter
{
  public:
    unsigned int value;
};
class bhkWorldObject
{
  public:
    bhkFilter FUN_0043b4f0();
};
struct bhkCollisionObject
{
  public:
    static bhkCollisionObject* GetFromNiAVObject(NiAVObject*);
};
class NiTexture : public NiObject
{
};
class NiSourceTexture : public NiTexture
{
  public:
};
class BSShaderPPLightingProperty
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
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
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void SetTexture(int, NiTexture*);
    virtual void SetNormalTexture(int, NiTexture*);
    bool GetFlag(int);
    int GetType();
    void SetFlag(int, bool);
};
NiTexture* FUN_004af8a0();
class TESForm;
class TESBipedModelForm
{
  public:
    virtual void vfn_0();
    BSFaceGenModel* FUN_00480ce0();
    unsigned int m_uiBipedModelFlags;
    unsigned char m_ucBipedModelData;
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap worldModel[2];
    bool HasBipedModel(BIPED_OBJECT, bool, BGSBipedModelList*);
public:
    static ::TESBipedModelForm *GetFormAsBipedModel(const ::TESForm *);
};
extern int DAT_01188b88[3];
extern const char* DAT_01188c38[5];
extern TESModel DAT_011c5d10[20];
extern SettingT<INISettingCollection> DAT_011d5a10, DAT_011d5a44;
unsigned int FUN_004af350();
int FUN_004af340();
class BSPackedTask;
struct TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
public:
    void QueueActorDisarm(bool);
public:
    static ::TaskQueueInterface *GetSingleton();
public:
    void ProcessPackedTask(const ::BSPackedTask &);
};
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FILE_MISSING = 0
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};
class ActorTaskManager
{
  public:
    void WaitForTasksDuringRendering();
};
extern ActorTaskManager DAT_011c5cf0;
void FUN_00577e20(NiNode*);
struct BipedSkinNameMatch
{
    const char* name;
    BIPED_OBJECT slot;
};
struct BipedRenderProperties
{
    NiProperty* material;
    NiProperty* alpha;
    BSShaderPPLightingProperty* shader;
};
struct BipedAttachmentTarget
{
    NiExtraData* metadata;
    NiNode* parent;
};
class TESTopic;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList<T>* GetNext();
};
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class NiTimeController
{
  public:
};
class NiTexture;
template <class> class NiPointer;
class BSShaderManager
{
  public:
    static void BuildTexturePath(char*, const char*, const char*, bool);
public:
    static void GetTexture(const char *, bool, ::NiPointer< ::NiTexture> &, bool, bool);
};
struct Animation
{
  public:
};
struct BipedWeaponEntry
{
    float value;
    TESObjectWEAP* weapon;
    InventoryStackRecord* entry;
};
struct BipedModelClone
{
    NiNode* model;
    NiObject* copy;
    NiNode* pNode;
};
struct BipedSkinAttachment
{
    NiNode* attachNode;
    BSFaceGenModel* face;
};
struct BipedSkinBoneMetadata
{
    NiExtraData* extra;
    NiExtraData* bones;
};
struct BipedSkinnedChild
{
    NiTriBasedGeom* geom;
    NiAVObject* child;
    NiSkinInstance* skin;
};
struct BipedSkinBoneBinding
{
    NiAVObject** boneArray;
    unsigned int count;
    NiAVObject* pBone;
};
#endif

struct BipedWeaponOwner
{
    BipedAnim* biped;
    Actor* actor;
    BaseProcess* process;
};
struct BipedEquippedWeapon
{
    TESObjectWEAP* weapon;
    InventoryChanges* changes;
};
struct BipedWeaponSearch
{
    NiNode* search;
    NiNode* found;
    NiNode* root;
};

struct BipedGeometryChild
{
    NiTriBasedGeom* geometry;
    NiAVObject* child;
};

class TESQuest;
class TESHairRaceResult;
class BGSPerkEntry;
class TESQuest;
class BGSQuestObjective
{
  public:
public:
    void SetOwner(::TESQuest *);
};
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};
class TESHairCanBeNPCData
{
  public:
};
class TESSpellList
{
  public:
    BSSimpleList<InventoryStackRecord*>* GetOffsetC();
};

// These object and string getters are identical folded functions in the PC executable.
#define BIPED_OBJECT_NAME(object) (*(const NiFixedString*)((TESTopicInfoData*)(object))->GetLinkToList())
#define BIPED_STRING_TEXT(value) ((const char*)((BSFadeNode*)&(value))->FUN_0043b1b0())
#define BIPED_OBJECT_TEXT(object) BIPED_STRING_TEXT(BIPED_OBJECT_NAME(object))
#define BIPED_EXTRA_STRING(extra) (*(const NiFixedString*)((TESSpellList*)(extra))->GetOffsetC())

struct BipedSkinTextureTarget
{
    TESNPC* npc;
    BIPED_OBJECT slot;
};

class GlobalObject_0045cf30
{
};
extern GlobalObject_0045cf30 g_011d5a10;
struct GlobalObject_0044fae0
{
public:
    void FUN_004538a0(int);
};
extern GlobalObject_0044fae0 g_011c5cf0;
// The canonical initializer name denotes the same 16-byte child array.
class GlobalObject_004aff00
{
  public:
    void* vtable;
    NiPointer<NiAVObject>* data;
    unsigned short capacity, size, count, grow;
    GlobalObject_004aff00(int, int);
    ~GlobalObject_004aff00();
};

typedef NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > > BipedChildArray;

// Canonical RTTI alias bound to the NPC descriptor used by this cast.
class TESFaction : public TESForm
{
};
