// fallout_shared/bgscamerashot.cpp: BGSCameraShot, CameraShot, ShotThis, Shot (16 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/CameraState.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00573eb0_Class.h"
#include "fnv/decl/FUN_0058cac0_Class.h"
#include "fnv/decl/FUN_0058cb00_Class.h"
#include "fnv/decl/FUN_0058ccd0_class.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0095edf0_cls.h"
#include "fnv/decl/FUN_009ca410_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/GraphicsRenderer.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ListHolder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_00a592c0_Matrix3.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/ThisShell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00950110__FUN_00950110_pc.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00529000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00a58000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "bgscamerashot_decls.h"
#include "bgscamerashot_types_BGSCameraShot.h"

// @fnv 0x0058bf50
void BGSCameraShot::ResetFormData()
{
    Data.m_eAction = BGSCameraShot__CAM_ACTION_CA_HIT;
    Data.pInputFile = BGSCameraShot__CAM_OBJECT_CO_TARGET;
    Data.m_eAttacker = BGSCameraShot__CAM_OBJECT_CO_ATTACKER;
    Data.m_fTimeMultiplier = 1.0f;
    Data.m_fMinTime = 0.0f;
    Data.m_fTargetPercent = 0.0f;
    Data.iFlags = 3;
    Data.fMaxTime = 0.0f;
    Data.m_fCameraValue1 = 0.0f;
    Data.m_fCameraValue2 = 0.0f;
}

// @fnv 0x0058c550
void BGSCameraShot::InitItem()
{
    if (GetInitialized())
        return;
    TESImageSpaceModifiableForm::InitItem(this);
    if (Data.m_fTimeMultiplier < *reinterpret_cast<const double*>(0x01032980))
    {
        ::FUN_005b5e40();
        Data.m_fTimeMultiplier = *reinterpret_cast<const float*>(0x0101e2bc);
    }
    SetInitializationState(true);
}

// @fnv 0x009c6ba0
void BGSCameraShot::ResetCameraShot()
{
    reinterpret_cast<::FUN_009ca410_shell *>((((VATS*)this)))->ProcessVATSCommands();
    if (((CameraTargetResetFields*)this)->node)
        reinterpret_cast<::CameraState *>((((CameraTargetResetFields*)this)->node))->ResetCameraState();
    ((CameraTargetResetFields*)this)->field0c = 0;
    ((CameraTargetResetFields*)this)->node = 0;
    ((CameraTargetResetFields*)this)->f14 = 0.0f;
    ((CameraTargetResetFields*)this)->f18 = 0.0f;
    if (((CameraTargetResetFields*)this)->a)
    {
        ::FUN_005293f0((::ImageSpaceModifierInstance *)(((CameraTargetResetFields*)this)->a));
        ((CameraTargetResetFields*)this)->a = 0;
    }
    if (((CameraTargetResetFields*)this)->b)
    {
        ::FUN_005293f0((::ImageSpaceModifierInstance *)(((CameraTargetResetFields*)this)->b));
        ((CameraTargetResetFields*)this)->b = 0;
    }
}

template <int N> struct EndianSizeTag
{
};

struct FUN_0058c2e0_shell
{
    int field_0x00;
    int field_0x04;
    int field_0x08;
    int field_0x0c;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    void FUN_0058c2e0();
};

// Byte-swaps all eight 32-bit fields of the object via BSEndian, in the order 0x10, 0x14, 0x00, 0x04, 0x08, 0x0c, 0x18, 0x1c.
// @fnv 0x0058c2e0
void FUN_0058c2e0_shell::FUN_0058c2e0()
{
    ::FUN_00401080(&field_0x10);
    ::FUN_00401080(&field_0x14);
    ::FUN_00401080(&field_0x00);
    ::FUN_00401080(&field_0x04);
    ::FUN_00401080(&field_0x08);
    ::FUN_00401080(&field_0x0c);
    ::FUN_00401080(&field_0x18);
    ::FUN_00401080(&field_0x1c);
}

struct FUN_0058be60_host
{
    void FUN_0058be90();
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_005e78f0_t
{
};
struct FUN_0058bfc0_shell
{
    void CopyFromCameraShot(TESForm*);
};
// Casts apCopy to BGSCameraShot, returns if it fails, then copies the base form and 0x28 bytes from offset 0x38 into this.
// @fnv 0x0058bfc0
void FUN_0058bfc0_shell::CopyFromCameraShot(TESForm* apCopy)
{
    BGSCameraShot* pcopy;
    pcopy = dynamic_cast<BGSCameraShot*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0((TESForm*)pcopy);
    __memcpy((char*)this + 0x38, (char*)&pcopy->Data, 0x28);
}

struct Flt
{
    operator unsigned int() const;
};
struct FUN_0048cee0_shell
{
    char data[0x18];
    int FUN_0048cee0();
};
struct FUN_0058d630_shell
{
    char pad0[0x18];
    FUN_0048cee0_shell model;
    char pad1[8];
    int field_38;
    char pad2[0x30];
    Flt flt;
    bool FUN_0058d630();
};
// @fnv 0x0058d630
bool FUN_0058d630_shell::FUN_0058d630()
{
    if (field_38 == 3)
        return false;
    if (model.FUN_0048cee0() == 0)
        return true;
    if ((unsigned int)flt != 0)
        return true;
    return false;
}

struct FUN_005e79a0_t
{
};
struct FUN_0058c020_shell
{
    bool FUN_0058c020(TESForm*);
};
int _memcmp(const void*, const void*, unsigned int);
// @fnv 0x0058c020
bool FUN_0058c020_shell::FUN_0058c020(TESForm* apCompare)
{
    BGSCameraShot* pCameraShot = dynamic_cast<BGSCameraShot*>(apCompare);
    if (!pCameraShot)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(pCameraShot))
        return true;
    if (_memcmp(reinterpret_cast<char*>(this) + 0x38, reinterpret_cast<char*>(&pCameraShot->Data), 0x28))
        return true;
    return false;
}

struct FUN_004855a0
{
};
struct FUN_004891d0_obj
{
};
struct FUN_00487450_shell
{
    void FUN_00487450();
};
struct FUN_00485680
{
};
struct FUN_00485e00_shell
{
};

struct FUN_0058c4d0_shell
{
    void FUN_0058c4d0();
};

struct FUN_0058c3c0_shell
{
    int field_0x00;
    int field_0x04;
    int field_0x08;
    int field_0x0c;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    int field_0x20;
    int field_0x24;

    void FUN_0058c3c0();
};
// Reads a BGSCameraShot record from a TESFile: validates the form type, then parses EDID, OBND, MODL/MODT, MNAM and DATA chunks into the shot's data.
// @fnv 0x0058c090
bool BGSCameraShot::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((((TESFileFormInt*)file)))->FUN_00472660() != 0x5b)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int chunk;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x4d414e4d: {
            unsigned int modifier = 0;
            file->GetChunkData(&modifier);
            ((CombatProcedure*)static_cast<TESImageSpaceModifiableForm *>(this))->Initialize((CombatController*)modifier);
            break;
        }
        case 0x41544144:
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 32)
            {
                CameraShotLegacyData legacyData;
                memset(&legacyData, 0, 32);
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((BGSImpactData*)this)))->FUN_004861f0(file, &legacyData, 32);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_0058c2e0_shell *>(&(legacyData))->FUN_0058c2e0();
                Data.m_eAction = (BGSCameraShot__CAM_ACTION)legacyData.action;
                Data.pInputFile = (BGSCameraShot__CAM_OBJECT)legacyData.location;
                Data.m_eAttacker = (BGSCameraShot__CAM_OBJECT)legacyData.target;
                Data.iFlags = legacyData.flags;
                Data.m_fMinTime = legacyData.playerMult;
                Data.m_fTimeMultiplier = legacyData.globalMult;
                Data.fMaxTime = legacyData.maxTime;
                Data.m_fCameraValue1 = legacyData.minTime;
            }
            else
            {
                memset(&Data, 0, 40);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), 40);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_0058c3c0_shell *>(&(Data))->FUN_0058c3c0();
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
// @fnv 0x0058c4d0
void FUN_0058c4d0_shell::FUN_0058c4d0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_004891d0_cls *>((((FUN_004891d0_obj*)((char*)this + 0x18))))->WriteToBuffer((char *)(0x4C444F4D), (void *)(0x54444F4D));
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_0058c3c0_shell *>((((BGSCameraShot__CAMERA_SHOT_DATA*)((char*)this + 0x38))))->FUN_0058c3c0();
    reinterpret_cast<::SDSaveForm *>((((FUN_00485e00_shell*)this)))->FUN_00485e20((const void *)((int)((char*)this + 0x38)), 0x28);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_0058c3c0_shell *>((((BGSCameraShot__CAMERA_SHOT_DATA*)((char*)this + 0x38))))->FUN_0058c3c0();
    ((FUN_00487450_shell*)((char*)this + 0x30))->FUN_00487450();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

// Byte-swaps each of the ten 32-bit fields of the object via BSEndian.
// @fnv 0x0058c3c0
void FUN_0058c3c0_shell::FUN_0058c3c0()
{
    ::FUN_00401080(&field_0x10);
    ::FUN_00401080(&field_0x14);
    ::FUN_00401080(&field_0x18);
    ::FUN_00401080(&field_0x00);
    ::FUN_00401080(&field_0x04);
    ::FUN_00401080(&field_0x08);
    ::FUN_00401080(&field_0x0c);
    ::FUN_00401080(&field_0x1c);
    ::FUN_00401080(&field_0x20);
    ::FUN_00401080(&field_0x24);
}

struct BaseA_b4203
{
    virtual ~BaseA_b4203();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct BaseB_b4203
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    ~BaseB_b4203();
};

struct BaseC_b4203
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

struct MemberA_b4203
{
    unsigned int unk00;
    ~MemberA_b4203();
};

struct MemberB_b4203
{
    unsigned int unk00;
    unsigned int unk04;
    ~MemberB_b4203();
};

class FUN_0058be90 : public BaseA_b4203, public BaseB_b4203, public BaseC_b4203
{
  public:
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    MemberA_b4203 m_60;
    MemberB_b4203 m_64;
    MemberA_b4203 m_6c;
    MemberA_b4203 m_70;
    virtual ~FUN_0058be90();
};
// Calls FUN_0058be90, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0058be60
void* FUN_0058be60_host::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0058be90 *>((this))->FUN_0058be90::~FUN_0058be90();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0058be90
FUN_0058be90::~FUN_0058be90()
{
    reinterpret_cast<::CameraState *>(this)->ResetCameraState();
}

// Stand-in owner class for IsNotFlag4Set.
// The original reads a 32-bit flag field at this+0x44 and returns a bool.
struct FUN_0058d4f0_cls
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
    bool IsNotFlag4Set();
};

// @fnv 0x0058d4f0
bool FUN_0058d4f0_cls::IsNotFlag4Set()
{
    return (unk44 & 4) == 0 ? true : false;
}

// NiPoint3: the canonical class (include/NiPoint3.h, via TESObjectREFR.h)
struct Rotation
{
};
struct CameraNode
{
    const NiPoint3& FUN_0045bb80();
};
struct NodePointer
{
};
struct VATSLocation
{
    NiPoint3 FUN_009c9fe0(float);
};
struct CameraShot : BGSCameraShot
{
    NiPoint3 GetCameraPosition();
};
// @fnv 0x0058d510
NiPoint3 CameraShot::GetCameraPosition()
{
    NiPoint3 position = ::NiPoint3::ZERO;
    if (reinterpret_cast<::TESGrass *>(this)->GetLowestAllowedSlope() > 0.0)
    {
        position = (*reinterpret_cast<::VATSLocation *>(&::g_011f2250)).FUN_009c9fe0(reinterpret_cast<::TESGrass *>(this)->GetLowestAllowedSlope());
    }
    else if (((::CameraNode *)(::FUN_00559450((int *)(((NodePointer*)&m_pTargetNode))))))
    {
        position = ((::CameraNode *)(::FUN_00559450((int *)(((NodePointer*)&m_pTargetNode)))))->FUN_0045bb80();
    }
    if (m_bUpdateNodePosition == 1 && ((::CameraNode *)(::FUN_00559450((int *)(((NodePointer*)&m_spPositionNode))))))
    {
        reinterpret_cast<::S_00a592c0_Matrix3 *>((((::Rotation *)(::FUN_006a9540((char *)(((::CameraNode *)(::FUN_00559450((int *)(((NodePointer*)&m_spPositionNode)))))))))))->DecomposeToEulerAngles((*(float *)(&DAT_011ca738)), (*(float *)(&DAT_011ca73c)), (*(float *)(&DAT_011ca740)));
    }
    else
    {
        DAT_011ca738 = 0.0f;
        DAT_011ca73c = 0.0f;
        DAT_011ca740 = 0.0f;
    }
    return position;
}

// SetupCamera v01 - worker10 one-pass transcription (history draw, fnvrec v1.1)
extern float DAT_011ca734;
extern NiPoint3 DAT_011ca7a8;
extern NiPoint3 DAT_011ca75c;


struct SubObj390c0
{
};
struct CamNodeX
{
};
struct NodePtrObj
{
    void* m_pObject;
    void FUN_0066b0d0(void*);
};
struct ModelLoader
{
};
struct ModelSub
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual const char* vfn_14();
    unsigned int FUN_0048cee0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
struct LookupObj
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2a();
    virtual void Unk_2b();
    virtual void Unk_2c();
    virtual void Unk_2d();
    virtual void Unk_2e();
    virtual void Unk_2f();
    virtual void Unk_30();
    virtual int vfn_c4(int);
};
struct Lookup2
{
};
struct St28
{
    int f00;
    float f04;
    float f08;
    int f0c;
    int f10;
    int f14;
    int f18;
};
struct FoundObj
{
};
struct Obj20
{
    int m_00;
    int m_04;
    int m_08;
};
struct BSSoundHandleEx
{
    int m_00;
    int m_04;
    int m_08;
    ~BSSoundHandleEx();
};
struct BSAudio
{
    BSSoundHandleEx FUN_00ad7550(const char*, unsigned int);
};
struct Glob79c
{
};
struct VatsSub
{
    bool FUN_0058cba0(int);
};
struct VatsState
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    VatsSub* sub14;
};
struct VATSObj
{
};
struct PlayerObj
{
};

struct ShotThis
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ModelSub model;
    int unk30;
    int unk34;
    int dataAction;
    int dataLocation;
    int dataTarget;
    unsigned int dataFlags;
    float dataPlayerMult;
    float dataTargetMult;
    float dataGlobalMult;
    float dataMaxTime;
    float dataMinTime;
    float dataTargetPct;
    NodePtrObj m_pLocationNode;
    NodePtrObj m_pTargetNode;
    void* m_pReference;
    NodePtrObj m_spPositionNode;
    NodePtrObj m_pSceneObject;
    signed char m_bUpdateNodePosition;
    unsigned char m_bFlag74;
    unsigned char m_bFlag75;
    unsigned char pad77;
    void SetupCamera(void*, int);
};

struct NiPoint3Ex;
struct NiPoint3;
struct M3
{
    float m[9];
};
struct Frus
{
    float left;
    float right;
    float top;
    float bottom;
    float nearPlane;
    float farPlane;
    bool orthographic;
};
struct NiUpdateData
{
    float a;
    int b;
    int c;
    NiUpdateData(float, bool, bool);
};
// Loads the VATS camera model, validates its NiCamera child and FOV, stores param1, and updates camera globals and sounds based on param2 and dataAction.
// @fnv 0x0058c5d0
void ShotThis::SetupCamera(void* param1, int iMode)
{
    void* myFoundPtr;
    if (model.FUN_0048cee0())
    {
        m_spPositionNode.FUN_0066b0d0((void*)((int)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080((char *)(model.vfn_14()), 0, 1, 1, 0, 0))));
    }
    myFoundPtr = ((::CamNodeX *)(::FUN_00559450((int *)&(m_spPositionNode))))
                     ? ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f4a18))), (::NiObject *)(void *)((void*)((int)(reinterpret_cast<::S_FUN_0045bc00 *>((((::CamNodeX *)(::FUN_00559450((int *)&(m_spPositionNode))))))->FUN_0045bc00(0)))))))
                     : 0;
    if (!myFoundPtr)
    {
        ::FUN_005b5e40(
            );
        m_spPositionNode.FUN_0066b0d0(0);
        reinterpret_cast<::FUN_0045a5e0_shell *>((::g_modelLoader))->FUN_0045a5e0((char *)(model.vfn_14()));
    }
    if (((::CamNodeX *)(::FUN_00559450((int *)&(m_spPositionNode)))))
    {
        Obj20 auxPtr;
        new ((void *)&(auxPtr)) ::NiUpdateData(DAT_011f21d4, 1, 0);
        if (reinterpret_cast<::FUN_0058cac0_Class *>(this)->IsFlag20Set())
        {
            ::FUN_004b70f0((::NiNode *)(void *)(((::CamNodeX *)(::FUN_00559450((int *)&(m_spPositionNode))))), -DAT_011f21d4);
        }
        reinterpret_cast<::FUN_00a59c60_cls *>((((::CamNodeX *)(::FUN_00559450((int *)&(m_spPositionNode))))))->FUN_00a59c60((int)(&auxPtr));
        if ((signed char)m_bUpdateNodePosition == -1 && !m_bFlag75)
        {
            void* queriedVal = ((void *)(reinterpret_cast<::MyHost *>((((::CamNodeX *)(::FUN_00559450((int *)&(m_spPositionNode))))))->FUN_00a5c570((const ::MyRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f3714))))));
            if (queriedVal)
            {
                void* clonePtr = queriedVal;
                int held2 = ((LookupObj*)clonePtr)->vfn_c4(0);
                void* altObj2Val = ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f3e50))), (::NiObject *)(void *)((void*)held2))));
                void* myAltPtr = 0;
                if (altObj2Val)
                {
                    int resA;
                    int chkBPtr;
                    unsigned char flagCX;
                    int answer = reinterpret_cast<::FUN_0058cb00_Class *>((((Lookup2*)altObj2Val)))->FUN_0058cb00((unsigned int *)(int *)(&resA), &chkBPtr, &flagCX);
                    (void)answer;
                    if (resA)
                    {
                        m_bUpdateNodePosition = 1;
                    }
                }
                else
                {
                    myAltPtr = ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f3e48))), (::NiObject *)(void *)((void*)held2))));
                }
                if (myAltPtr && ((bool)(reinterpret_cast<::FUN_00573eb0_Class *>((((Lookup2*)myAltPtr)))->FUN_0058cae0())))
                {
                    m_bUpdateNodePosition = 1;
                }
                if ((signed char)m_bUpdateNodePosition == -1)
                {
                    m_bUpdateNodePosition = 0;
                }
            }
        }
        if (reinterpret_cast<::NiPoint3 *>((((::SubObj390c0 *)&(reinterpret_cast<::NiAVObject *>((((::CamNodeX *)(::FUN_00559450((int *)&(m_spPositionNode))))))->FUN_0043c490()))))->FUN_004390c0(::NiPoint3::ZERO))
        {
            ::FUN_005b5e40();
        }
        St28 attrs2;
        attrs2 = *((::St28 *)&(reinterpret_cast<::NiCamera *>((((FoundObj*)myFoundPtr)))->GetViewFrustum()));
        if (attrs2.f08 / attrs2.f04 < (double)0.74f)
        {
            ::FUN_005b5e40();
        }
    }
    m_pReference = param1;
    (*reinterpret_cast<unsigned char *>(&::DAT_011e07c3)) = 1;
    switch (iMode)
    {
    case 0:
        (*reinterpret_cast<unsigned char *>(&::xbSlowMo)) = 1;
        DAT_011ca734 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Glob79c *>(&::g_011ca79c))))));
        break;
    case 1:
        (*reinterpret_cast<unsigned char *>(&::xbSlowMo)) = 0;
        break;
    case 2:
        if (dataAction == 3)
        {
            (*reinterpret_cast<unsigned char *>(&::xbSlowMo)) = 1;
            if (dataMinTime > 0.0f)
            {
                DAT_011ca734 = dataMinTime;
            }
            else
            {
                DAT_011ca734 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Glob79c *>(&::g_011ca79c))))));
            }
        }
        break;
    }
    DAT_011ca72c = 0.0f;
    DAT_011ca730 = 0.0f;
    DAT_011ca7a8 = ::NiPoint3::ZERO;
    DAT_011ca75c = ::NiPoint3::ZERO;
    VatsState* vatsPtr2 = ((::VatsState *)(reinterpret_cast<::ListHolder *>((((VATSObj*)&(*reinterpret_cast<::VATSLocation *>(&::g_011f2250)))))->FUN_009c71c0()));
    if (vatsPtr2 && !(*reinterpret_cast<unsigned char *>(&::DAT_011ca729)) &&
        (vatsPtr2->sub14->FUN_0058cba0(4) || vatsPtr2->sub14->FUN_0058cba0(8) || vatsPtr2->sub14->FUN_0058cba0(0x10)))
    {
        if (dataAction == 2)
        {
            (*reinterpret_cast<unsigned char *>(&::DAT_011ca729)) = 1;
            BSSoundHandleEx camIn2 = ::FUN_00453a70()->FUN_00ad7550("UIVATSCameraIn", 0x121);
            reinterpret_cast<::FUN_00ad8830_shell *>(&(camIn2))->FUN_00ad8830(false);
        }
    }
    else
    {
        if ((*reinterpret_cast<unsigned char *>(&::DAT_011ca729)) && dataAction != 2)
        {
            (*reinterpret_cast<unsigned char *>(&::DAT_011ca729)) = 0;
            BSSoundHandleEx bannerOutPtr = ::FUN_00453a70()->FUN_00ad7550("UIVATSCameraOut", 0x121);
            reinterpret_cast<::FUN_00ad8830_shell *>(&(bannerOutPtr))->FUN_00ad8830(false);
        }
    }
    reinterpret_cast<::FUN_0095edf0_cls *>(((*reinterpret_cast<::PlayerObj * *>(&::_g_thePlayer))))->SyncHolderValue();
}
struct Host56
{
};
struct Rot56
{
};
struct Node60
{
    const NiPoint3& FUN_0045bb80();
};
struct Prop
{
};
struct Anim
{
};
struct MidX
{
};
struct Node6c
{
};
struct NiPtr60
{
    Node60* object;
};
struct NiPtr6c
{
    Node6c* object;
};
struct Rend
{
};
struct GObj
{
    virtual void w000();
    virtual void w001();
    virtual void w002();
    virtual void w003();
    virtual void w004();
    virtual void w005();
    virtual void w006();
    virtual void w007();
    virtual void w008();
    virtual void w009();
    virtual void w010();
    virtual void w011();
    virtual void w012();
    virtual void w013();
    virtual void w014();
    virtual void w015();
    virtual void w016();
    virtual void w017();
    virtual void w018();
    virtual void w019();
    virtual void w020();
    virtual void w021();
    virtual void w022();
    virtual void w023();
    virtual void w024();
    virtual void w025();
    virtual void w026();
    virtual void w027();
    virtual void w028();
    virtual void w029();
    virtual void w030();
    virtual void w031();
    virtual void w032();
    virtual void w033();
    virtual void w034();
    virtual void w035();
    virtual void w036();
    virtual void w037();
    virtual void w038();
    virtual void w039();
    virtual void w040();
    virtual void w041();
    virtual void w042();
    virtual void w043();
    virtual void w044();
    virtual void w045();
    virtual void w046();
    virtual void w047();
    virtual void w048();
    virtual void w049();
    virtual void w050();
    virtual void w051();
    virtual void w052();
    virtual void w053();
    virtual void w054();
    virtual void w055();
    virtual void w056();
    virtual void w057();
    virtual void w058();
    virtual void w059();
    virtual void w060();
    virtual void w061();
    virtual void w062();
    virtual void w063();
    virtual void w064();
    virtual void w065();
    virtual void w066();
    virtual void w067();
    virtual void w068();
    virtual void w069();
    virtual void w070();
    virtual void w071();
    virtual void w072();
    virtual void w073();
    virtual void w074();
    virtual void w075();
    virtual void w076();
    virtual void w077();
    virtual void w078();
    virtual void w079();
    virtual void w080();
    virtual void w081();
    virtual void w082();
    virtual void w083();
    virtual void w084();
    virtual void w085();
    virtual void w086();
    virtual void w087();
    virtual void w088();
    virtual void w089();
    virtual void w090();
    virtual void w091();
    virtual void w092();
    virtual void w093();
    virtual void w094();
    virtual void w095();
    virtual void w096();
    virtual void w097();
    virtual void w098();
    virtual void w099();
    virtual void w100();
    virtual void w101();
    virtual void w102();
    virtual void w103();
    virtual void w104();
    virtual void w105();
    virtual void w106();
    virtual void w107();
    virtual void w108();
    virtual void w109();
    virtual void w110();
    virtual void w111();
    virtual void w112();
    virtual void w113();
    virtual void w114();
    virtual void w115();
    virtual void w116();
    virtual void w117();
    virtual void w118();
    virtual void w119();
    virtual void w120();
    virtual void w121();
    virtual void w122();
    virtual void w123();
    virtual void w124();
    virtual void w125();
    virtual void w126();
    virtual void w127();
    virtual void w128();
    virtual void w129();
    virtual void w130();
    virtual void w131();
    virtual void w132();
    virtual void w133();
    virtual void w134();
    virtual void w135();
    virtual void w136();
    virtual void w137();
    virtual void w138();
    virtual bool Check22c(int);
};
class LenShell;
class PtOp
{
  public:
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3&) const;
    LenShell* FUN_00439ef0();
};

class NiPoint3_helper
{
  public:
    NiPoint3Ex operator*(float) const;
};
class PtSub
{
  public:
    NiPoint3& operator-=(const NiPoint3&);
};
class PtTest
{
  public:
};
class LenShell
{
  public:
    float FUN_00457990();
};
extern NiPoint3 DAT_011ca77c;
extern NiPoint3 DAT_011ca75c;
extern NiPoint3 DAT_011ca7a8;
extern float DAT_011ca734;
struct NiPoint3Ex
{
    float x;
    float y;
    float z;
    NiPoint3Ex operator-(const NiPoint3&) const;
    NiPoint3Ex operator+(const NiPoint3Ex&) const;
};
struct Shot
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
    int unk34;
    int f38;
    int f3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    NiPtr60 m60;
    int f64;
    Host56* f68;
    NiPtr6c m6c;
    int f70;
    char c74;
    unsigned char c75;
    char c76;
    char c77;
    NiPoint3Ex GetCameraPosition();
    void UpdateCamera(float);
};
// Updates the camera node with NiUpdateData, adjusts its position and frustum, and tracks camera-in transition progress.
// @fnv 0x0058cf60
void Shot::UpdateCamera(float afTime)
{
    if (!((::Node6c *)(::FUN_00559450((int *)&(m6c)))))
        return;
    NiUpdateData upd(afTime, true, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((::Node6c *)(::FUN_00559450((int *)&(m6c))))))->FUN_00a59c60((int)&(upd));
    DAT_011ca77c = reinterpret_cast<::NiAVObject *>((((::Node6c *)(::FUN_00559450((int *)&(m6c))))))->FUN_0043c490();
    NiPoint3 pt = DAT_011ca77c;
    if (c75 && !reinterpret_cast<GObj*>((*reinterpret_cast<::PlayerObj * *>(&::_g_thePlayer)))->Check22c(0))
        reinterpret_cast<::fnv_00950110::FUN_00950110_pc *>((reinterpret_cast<GObj*>((*reinterpret_cast<::PlayerObj * *>(&::_g_thePlayer)))))->FUN_00950110(1);
    else
    {
        if (reinterpret_cast<::FUN_0058ccd0_class *>(this)->IsFlagSet())
        {
            if (!reinterpret_cast<::FUN_0058d4f0_cls *>(this)->IsNotFlag4Set() || f68 == 0 || f3c != 2)
            {
                NiPoint3 tmpA = pt;
                ::FUN_00a582f0((const float *)&(const ::M3 &)(::FUN_0056fa00((char *)((*reinterpret_cast<::Host56 * *>(&::DAT_011f21f0))))), (const float *)(void *)(&::NiPoint3::ZERO), 1, (const ::Point314 *)&(tmpA), (::Point314 *)&(pt));
            }
            else
            {
                NiPoint3 tmpB = pt;
                ::FUN_00a582f0((const float *)&(const ::M3 &)(::FUN_0056fa00((char *)(f68))), (const float *)(void *)(&::NiPoint3::ZERO), 1, (const ::Point314 *)&(tmpB), (::Point314 *)&(pt));
            }
        }
        else if (((::Node60 *)(::FUN_00559450((int *)&(m60)))))
        {
            NiPoint3 tmpC = pt;
            ::FUN_00a582f0((const float *)(::Host56 *)(((::Host56 *)(::FUN_006a9540((char *)(((::Node60 *)(::FUN_00559450((int *)&(m60))))))))), (const float *)(void *)(&::NiPoint3::ZERO), 1, (const ::Point314 *)&(tmpC), (::Point314 *)&(pt));
        }
        if (((::Node60 *)(::FUN_00559450((int *)&(m60)))))
        {
            bool bReset = false;
            if (reinterpret_cast<::NiPoint3 *>((((PtTest*)&DAT_011ca75c)))->FUN_004390c0(::NiPoint3::ZERO))
            {
                DAT_011ca75c = DAT_011e0808;
                bReset = true;
            }
            NiPoint3 kPos = ((::Node60 *)(::FUN_00559450((int *)&(m60))))->FUN_0045bb80();
            reinterpret_cast<::FUN_0063c8a0_shell *>((((PtSub*)&pt)))->FUN_0063c8a0-=((void *)&(kPos));
            reinterpret_cast<::ThisShell *>((reinterpret_cast<GObj*>((*reinterpret_cast<::PlayerObj * *>(&::_g_thePlayer)))))->FUN_0094a0c0(&pt, &kPos, 0);
            DAT_011e0808 = pt;
            if ((*reinterpret_cast<unsigned char *>(&::xbSlowMo)))
            {
                *(NiPoint3Ex*)&DAT_011ca7a8 = *(NiPoint3Ex*)&DAT_011e0808 - DAT_011ca75c;
                if (reinterpret_cast<::NiPoint3 *>((void *)(((NiPoint3Ex*)&DAT_011ca7a8)))->ComputeMagnitude() <= *((float *)&(::FUN_00403e20((float *)(void *)(&(*reinterpret_cast<float *>(&::originalRuntimeFloatSetting38)))))))
                {
                    (*reinterpret_cast<unsigned char *>(&::xbSlowMo)) = 0;
                    DAT_011ca72c = 0.0f;
                }
                else if (f38 == 0)
                {
                    (*reinterpret_cast<unsigned char *>(&::xbSlowMo)) = 0;
                    DAT_011ca72c = 0.0f;
                }
                else
                {
                    if (bReset && !(*reinterpret_cast<unsigned char *>(&::DAT_011ca729)))
                    {
                        BSSoundHandleEx snd = ::FUN_00453a70()->FUN_00ad7550("UIVATSCameraIn", 0x121);
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(snd))->FUN_00ad8830(false);
                    }
                    DAT_011ca730 = (1.0f / DAT_011ca734) * (afTime - DAT_011ca72c);
                    if (DAT_011ca730 >= 1.0)
                    {
                        (*reinterpret_cast<unsigned char *>(&::xbSlowMo)) = 0;
                        DAT_011ca72c = 0.0f;
                    }
                    else
                        *(NiPoint3Ex*)&DAT_011e0808 =
                            *(NiPoint3Ex*)&DAT_011ca75c + ((NiPoint3_helper*)&DAT_011ca7a8)->operator*(DAT_011ca730);
                }
            }
            Prop* pCam = ((::Prop *)(reinterpret_cast<::S_FUN_0045bc00 *>((((::Node6c *)(::FUN_00559450((int *)&(m6c))))))->FUN_0045bc00(0)));
            if (pCam)
            {
                Frus kOrigFrustum = (*(const ::Frus *)&(reinterpret_cast<::NiCamera *>((pCam))->GetViewFrustum()));
                Anim* pMainCamera = ((::Anim *)(reinterpret_cast<::BSFaceGenNiNode *>((((::MidX *)(::FUN_0045c670()))))->GetAnimationData()));
                Frus kFrustum = (*(const ::Frus *)&(reinterpret_cast<::NiCamera *>((pMainCamera))->GetViewFrustum()));
                float scale =
                    (double)reinterpret_cast<::GraphicsRenderer *>((((::Rend *)(::FUN_0043c4b0()))))->GetRenderTargetWidth() / (double)reinterpret_cast<::GraphicsRenderer *>((((::Rend *)(::FUN_0043c4b0()))))->GetRenderTargetHeight() / 1.3333334f;
                kFrustum.left = kOrigFrustum.left * scale;
                kFrustum.right = kOrigFrustum.right * scale;
                kFrustum.top = kOrigFrustum.top;
                kFrustum.bottom = kOrigFrustum.bottom;
                reinterpret_cast<::NiCamera *>((pMainCamera))->UpdateViewFrustum((*(const ::NiFrustum *)(&kFrustum)));
            }
        }
    }
    if (reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3Ex &)((GetCameraPosition() - pt)))->ComputeMagnitude() <= *((float *)&(::FUN_00403e20((float *)(void *)(&(*reinterpret_cast<float *>(&::originalRuntimeFloatSetting39)))))))
        c75 = 1;
}
