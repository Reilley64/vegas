
// src/fallout/audio/impactmixer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/audio/impactmixer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/ActorMover.h"
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_00461bc0_cls.h"
#include "fnv/decl/FUN_00522520_shell.h"
#include "fnv/decl/FUN_00522540_shell.h"
#include "fnv/decl/FUN_0052d240_shell.h"
#include "fnv/decl/FUN_0053a630_Class.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00884730_shell.h"
#include "fnv/decl/FUN_008ba410_shell.h"
#include "fnv/decl/FUN_008ba440_shell.h"
#include "fnv/decl/FUN_00ad89b0_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FUN_00ad9030_shell.h"
#include "fnv/decl/FakeCell.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/SoundPlaybackManager.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/bhkCharacterListener.h"
#include "fnv/decl/bhkRigidBody_2.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/xLand.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_00839000.h"
#include "fnv/symbols_01000000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_01034000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include <new>
#include <cstring>
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/SoundPlayback.h"
#include "fnv/decl/SoundWrapper.h"
#include "fnv/symbols_0083a000.h"
#include "fnv/symbols_010c2000.h"
extern int DAT_011dd878;

// @fnv 0x00839da0
bool FUN_00839da0()
{
    return (DAT_011dd878 & 2) != 0;
}

extern int DAT_011dd878;

// @fnv 0x00839dc0
void FUN_00839dc0(bool abSet)
{
    int tmp;
    if (abSet)
        tmp = DAT_011dd878 | 2;
    else
        tmp = DAT_011dd878 & 0xfffffffd;
    DAT_011dd878 = tmp;
}

extern int DAT_011a17f8[0x24];

// @fnv 0x0083a910
int GetTypeValue(int aiType)
{
    if (aiType <= 0 || aiType >= 0x24)
        return 0;
    return DAT_011a17f8[aiType];
}

struct FUN_00acbb70_shell
{
    int FUN_00acbb70();
};

// @fnv 0x00acbb70
int FUN_00acbb70_shell::FUN_00acbb70()
{
    return 0;
}

struct FUN_008397d0_shell
{
    unsigned char GetByteAt7C6();
};

// @fnv 0x008397d0
unsigned char FUN_008397d0_shell::GetByteAt7C6()
{
    return ((unsigned char*)this)[0x7c6];
}

struct AutoMemHelper
{
    int m;
    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
};
// @fnv 0x00837520
void FUN_00837520()
{
    AutoMemHelper tempMemContext(0xB, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp",
                                 0x10F);
}

struct DummyFlags
{
};
struct FUN_00838750_shell
{
    bool FUN_00838750();
};
// Calls FUN_00621270 on the DummyFlags sub-object at offset 0x410 with DAT_01000000 and returns whether the result is non-zero.
// @fnv 0x00838750
bool FUN_00838750_shell::FUN_00838750()
{
    return ((int)(reinterpret_cast<::bhkCharacterListener *>((((DummyFlags*)((char*)this + 0x410))))->FUN_00621270((int)&DAT_01000000))) != 0;
}

struct FUN_00541570_shell
{
    char _pad[0x1c];
    unsigned char m_0x1c;
    unsigned int GetField1C();
};
// @fnv 0x00541570
unsigned int FUN_00541570_shell::GetField1C()
{
    return m_0x1c;
}

void __cdecl FUN_00839dc0(bool b);
// If the init check fails, calls FUN_00839dc0(true), then zeroes two ints and sets a float from DAT_01016970 for each of 20 slots.
// @fnv 0x00839d30
void __cdecl InitializeSlots()
{
    if (FUN_00839da0())
    {
        return;
        goto initialize;
    }
    FUN_00839dc0(true);
initialize:
    for (int i = 0; i < 20; ++i)
    {
        *(int*)((char*)&DAT_011dd878 + 0x188 + i * 0x24) = 0;
        *(int*)((char*)&DAT_011dd878 + 0x18c + i * 0x24) = 0;
        *(float*)((char*)&DAT_011dd878 + 0x190 + i * 0x24) = DAT_01016970;
    }
}

struct FUN_0063a3c0_cls
{
    int unk00;
    int unk04;

    FUN_0063a3c0_cls* FUN_0063a3c0(unsigned int auiFlags);
};

// Releases the base object and, if bit 0 of auiFlags is set, deletes this instance, then returns this.
// @fnv 0x0063a3c0
FUN_0063a3c0_cls* FUN_0063a3c0_cls::FUN_0063a3c0(unsigned int auiFlags)
{
    reinterpret_cast<::FUN_0052d240_shell *>(this)->FUN_0052d240();
    if (auiFlags & 1)
    {
        ::FUN_00401030(this);
    }
    return this;
}

struct NiPoint3
{
    float x, y, z;
public:
    ::NiPoint3 &Subtract(const ::NiPoint3 &);
public:
    float ComputeMagnitude() const;
};

struct SoundPlaybackHandle
{
    int unk00;
    int unk04;
    int unk08;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& kOther);
    bool FUN_00ad8830(int iFlags);
    void FUN_00ad8b60(float fX, float fY, float fZ);
public:
    bool SetPlaybackFrequency(float);
};

struct BGSSoundDescriptor;
struct BSAudioStandIn
{
    SoundPlaybackHandle FUN_00ad73b0(BGSSoundDescriptor* pkSound);
};

struct BGSImpactData
{
};

struct BGSImpactDataEntry
{
    BGSImpactData* pkImpact;
    int unk04[9];
};
extern BGSImpactDataEntry g_akImpactData_011dd670[];

struct TESWorldSpace;
struct FootstepActor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool IsActor();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3& GetPos();

};

struct MaterialRecord
{
};

struct NavQueryResult
{
    int unk00[6];
    unsigned char unk18;
    unsigned char unk19;
    unsigned short unk1a;
    int unk1c[8];
    unsigned short unk3c;
    unsigned short unk3e;
    int unk40[4];
    NavQueryResult();
};

struct CellNavInfo
{
};

struct FootstepCell
{
};

struct TESStandIn
{
};

struct DataHandlerStandIn
{
};

int __cdecl GetTypeValue(int iMaterial);

static const char s_szBabyLand[] = "FSTBabyLand";
extern const char g_szFootstepEnd[] = "";

// Resolves the footstep material and impact data for an actor, adjusts the position, and plays the corresponding first- or third-person footstep sound.
// @fnv 0x008391b0
void __cdecl PlayFootstepImpact(FootstepActor* pActor, int iMaterial)
{
    SoundPlaybackHandle kHandle_;
    BGSImpactData* pImpactX = 0;
    BGSImpactData* pImpact_ = 0;
    NiPoint3 kPosOut = pActor->GetPos();
    FootstepCell* pCell_ = ((::FootstepCell *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TESStandIn * *>(&::g_TES))))->GetPrevPath()));
    FootstepActor* pActorRef4 = 0;
    if (pActor->IsActor())
        pActorRef4 = pActor;
    else
        return;

    if (!pCell_)
        pCell_ = ((::FootstepCell *)(reinterpret_cast<::FUN_00461bc0_cls *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->FUN_00461bc0(kPosOut.x, kPosOut.y, ((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TESStandIn * *>(&::g_TES))))->GetHitSound())), {})));

    if (pActor->IsActor() && pCell_)
    {
        if ((reinterpret_cast<::TESObjectCELL *>((pCell_))->IsCellInterior() && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((pCell_))->FUN_004518e0()) || !reinterpret_cast<::TESObjectCELL *>((pCell_))->IsCellInterior())
        {
            if (!reinterpret_cast<::FUN_005a2030_shell *>((pActorRef4))->FUN_005a2030() && reinterpret_cast<::FUN_0057b0a0_shell *>((pActorRef4))->FUN_0057b0a0() > kPosOut.z)
                iMaterial = 8;
        }
    }

    if (iMaterial == 0x24 && !reinterpret_cast<::TESObjectCELL *>((pCell_))->IsCellInterior() && ((::CellNavInfo *)(reinterpret_cast<::S00546fb0_Cell *>((pCell_))->FUN_00546fb0())))
    {
        NavQueryResult kResult_2;
        reinterpret_cast<::xLand *>((((::CellNavInfo *)(reinterpret_cast<::S00546fb0_Cell *>((pCell_))->FUN_00546fb0()))))->FUN_0053b550((*(::xCoordData *)(&kResult_2)), (*(const ::xPoint3 *)(&kPosOut)), 1);
        MaterialRecord* pMaterialTmp = ((::MaterialRecord *)(reinterpret_cast<::FUN_0053a630_Class *>((((::CellNavInfo *)(reinterpret_cast<::S00546fb0_Cell *>((pCell_))->FUN_00546fb0()))))->FUN_0053a630(kResult_2.unk18, kResult_2.unk3c)));
        if (pMaterialTmp)
        {
            float m_fGlyphExtent = 0.0f;
            iMaterial = ((int)(reinterpret_cast<::FUN_00541570_shell *>((pMaterialTmp))->GetField1C()));
            if (reinterpret_cast<::FakeCell *>((pCell_))->FUN_005547c0((*(const ::NiPoint3 *)(&kPosOut)), (*(float *)(&m_fGlyphExtent))))
                kPosOut.z = m_fGlyphExtent;
        }
    }

    int iIndexZ = GetTypeValue(iMaterial);
    pImpactX = g_akImpactData_011dd670[iIndexZ].pkImpact;
    if (pActor == (*reinterpret_cast<::FootstepActor * *>(&::_g_thePlayer)) && ((bool)(reinterpret_cast<::FUN_008397d0_shell *>(((*reinterpret_cast<::FootstepActor * *>(&::_g_thePlayer))))->GetByteAt7C6())))
        pImpactX = ((::BGSImpactData *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->GetSoundByEditorID(s_szBabyLand)));

    bool bPlayerFirstPerson7 = false;
    if (pActor == (*reinterpret_cast<::FootstepActor * *>(&::_g_thePlayer)) && !::FUN_00524d10((bool *)((*reinterpret_cast<::FootstepActor * *>(&::_g_thePlayer)))))
        bPlayerFirstPerson7 = true;

    if (bPlayerFirstPerson7)
    {
        int iSound = 0x4109;
        if (pImpactX)
        {
            kHandle_ = ((::BSAudioStandIn *)(::FUN_00453a70()))->FUN_00ad73b0(((::BGSSoundDescriptor *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pImpactX))->FUN_0084e3a0())));
            reinterpret_cast<::FUN_00ad89e0_shell *>(&(kHandle_))->FUN_00ad89e0(0.95f - ::RandomFloat(0.0f, ::DAT_0101e2bc));
            kHandle_.FUN_00ad8830(0);
        }
        if (pImpact_)
        {
            kHandle_ = ((::BSAudioStandIn *)(::FUN_00453a70()))->FUN_00ad73b0(((::BGSSoundDescriptor *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pImpact_))->FUN_0084e3a0())));
            reinterpret_cast<::FUN_00ad89e0_shell *>(&(kHandle_))->FUN_00ad89e0(0.95f - ::RandomFloat(0.0f, ::DAT_0101e2bc));
            kHandle_.FUN_00ad8830(0);
        }
    }
    else
    {
        if (!::SoundPlaybackManager::CanPlaySoundAt((::TESSound *)(pImpactX), kPosOut, 1.0f) && !::SoundPlaybackManager::CanPlaySoundAt((::TESSound *)(pImpact_), kPosOut, 1.0f))
            return;
        int iSound2 = 0x410a;
        if (pImpactX)
        {
            kHandle_ = ((::BSAudioStandIn *)(::FUN_00453a70()))->FUN_00ad73b0(((::BGSSoundDescriptor *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pImpactX))->FUN_0084e3a0())));
            kHandle_.FUN_00ad8b60(kPosOut.x, kPosOut.y, kPosOut.z);
            reinterpret_cast<::FUN_00ad8f20_shell *>(&(kHandle_))->FUN_00ad8f20((::NiAVObject *)(void *)(pActor->Get3D()));
            reinterpret_cast<::FUN_00ad89e0_shell *>(&(kHandle_))->FUN_00ad89e0(0.95f - ::RandomFloat(0.0f, ::DAT_0101e2bc));
            kHandle_.FUN_00ad8830(0);
        }
        if (pImpact_)
        {
            kHandle_ = ((::BSAudioStandIn *)(::FUN_00453a70()))->FUN_00ad73b0(((::BGSSoundDescriptor *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pImpact_))->FUN_0084e3a0())));
            kHandle_.FUN_00ad8b60(kPosOut.x, kPosOut.y, kPosOut.z);
            reinterpret_cast<::FUN_00ad8f20_shell *>(&(kHandle_))->FUN_00ad8f20((::NiAVObject *)(void *)(pActor->Get3D()));
            reinterpret_cast<::FUN_00ad89e0_shell *>(&(kHandle_))->FUN_00ad89e0(0.95f - ::RandomFloat(0.0f, ::DAT_0101e2bc));
            kHandle_.FUN_00ad8830(0);
        }
    }
}

namespace fnv_00839ab0 {
struct BGSImpactDataStandIn;

struct DataHandlerFootstep
{
};

extern const char* g_apszFootstepTypes_011a18bc[10];
extern int g_aiMaterialFallback_011a17c4[13];


static const char s_szFootstepFormat[] = "FST%s%s";
static const char s_szDefaultFootstep[] = "FSTConcSolidWalkR";
extern const char g_szFootstepInitEnd[] = "";

// Builds each material/type footstep impact name, looks it up via the data handler with fallbacks, and stores the result in g_aapkFootstepImpacts_011dd650.
// @fnv 0x00839ab0
void __cdecl InitFootstepImpacts()
{
    if (::DAT_011dd85c)
        return;
    else
        ::DAT_011dd85c = 1;

    char acNameLoc[0x104];
    int iUnusedLoc = 0;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ::FUN_00406d00(acNameLoc, 0x103, s_szFootstepFormat, ((const char *)(::FUN_008374b0(i))), g_apszFootstepTypes_011a18bc[j]);
            (*reinterpret_cast<fnv_00839ab0::BGSImpactDataStandIn * (*)[13][10]>(&::DAT_011dd650))[i][j] = ((::fnv_00839ab0::BGSImpactDataStandIn *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_00839ab0::DataHandlerFootstep * *>(&::g_dataHandler))))->GetSoundByEditorID(acNameLoc)));
            if (!(*reinterpret_cast<fnv_00839ab0::BGSImpactDataStandIn * (*)[13][10]>(&::DAT_011dd650))[i][j] && g_aiMaterialFallback_011a17c4[i] != 13)
            {
                ::FUN_00406d00(acNameLoc, 0x103, s_szFootstepFormat, ((const char *)(::FUN_008374b0(g_aiMaterialFallback_011a17c4[i]))),
                             g_apszFootstepTypes_011a18bc[j]);
                (*reinterpret_cast<fnv_00839ab0::BGSImpactDataStandIn * (*)[13][10]>(&::DAT_011dd650))[i][j] = ((::fnv_00839ab0::BGSImpactDataStandIn *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_00839ab0::DataHandlerFootstep * *>(&::g_dataHandler))))->GetSoundByEditorID(acNameLoc)));
                if (!(*reinterpret_cast<fnv_00839ab0::BGSImpactDataStandIn * (*)[13][10]>(&::DAT_011dd650))[i][j] &&
                    g_aiMaterialFallback_011a17c4[g_aiMaterialFallback_011a17c4[i]] != 13)
                {
                    ::FUN_00406d00(acNameLoc, 0x103, s_szFootstepFormat,
                                 ((const char *)(::FUN_008374b0(g_aiMaterialFallback_011a17c4[g_aiMaterialFallback_011a17c4[i]]))),
                                 g_apszFootstepTypes_011a18bc[j]);
                    (*reinterpret_cast<fnv_00839ab0::BGSImpactDataStandIn * (*)[13][10]>(&::DAT_011dd650))[i][j] = ((::fnv_00839ab0::BGSImpactDataStandIn *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_00839ab0::DataHandlerFootstep * *>(&::g_dataHandler))))->GetSoundByEditorID(acNameLoc)));
                }
            }
            if (!(*reinterpret_cast<fnv_00839ab0::BGSImpactDataStandIn * (*)[13][10]>(&::DAT_011dd650))[i][j])
                (*reinterpret_cast<fnv_00839ab0::BGSImpactDataStandIn * (*)[13][10]>(&::DAT_011dd650))[i][j] = ((::fnv_00839ab0::BGSImpactDataStandIn *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_00839ab0::DataHandlerFootstep * *>(&::g_dataHandler))))->GetSoundByEditorID(s_szDefaultFootstep)));
        }
    }
}
}  // namespace fnv_00839ab0

struct SetObj
{
};
struct StrObj
{
};

extern double DAT_01073568;

static const char kStr_CStoneStatic[] = "CStoneStatic";
static const char kStr_CStoneSmall[] = "CStoneSmall";
static const char kStr_CStoneMedium[] = "CStoneMedium";
static const char kStr_CStoneLarge[] = "CStoneLarge";
static const char kStr_CEarthSmall[] = "CEarthSmall";
static const char kStr_CEarthMedium[] = "CEarthMedium";
static const char kStr_CEarthLarge[] = "CEarthLarge";
static const char kStr_CGrassSmall[] = "CGrassSmall";
static const char kStr_CGrassMedium[] = "CGrassMedium";
static const char kStr_CGrassLarge[] = "CGrassLarge";
static const char kStr_PHYGenericMetalStaticL[] = "PHYGenericMetalStaticL";
static const char kStr_PHYGenericMetalSmallL[] = "PHYGenericMetalSmallL";
static const char kStr_PHYGenericMetalMediumL[] = "PHYGenericMetalMediumL";
static const char kStr_PHYGenericMetalLargeL[] = "PHYGenericMetalLargeL";
static const char kStr_PHYGenericMetalStaticH[] = "PHYGenericMetalStaticH";
static const char kStr_PHYGenericMetalSmallH[] = "PHYGenericMetalSmallH";
static const char kStr_PHYGenericMetalMediumH[] = "PHYGenericMetalMediumH";
static const char kStr_PHYGenericMetalLargeH[] = "PHYGenericMetalLargeH";
static const char kStr_CWoodStatic[] = "CWoodStatic";
static const char kStr_CWoodSmall[] = "CWoodSmall";
static const char kStr_CWoodMedium[] = "CWoodMedium";
static const char kStr_CWoodLarge[] = "CWoodLarge";
static const char kStr_PHYGenericClothL[] = "PHYGenericClothL";
static const char kStr_PHYGenericClothH[] = "PHYGenericClothH";
static const char kStr_COrganicSmall[] = "COrganicSmall";
static const char kStr_PHYSkinSmallL[] = "PHYSkinSmallL";
static const char kStr_PHYSkinMediumL[] = "PHYSkinMediumL";
static const char kStr_PHYSkinLargeL[] = "PHYSkinLargeL";
static const char kStr_PHYSkinSmallH[] = "PHYSkinSmallH";
static const char kStr_PHYSkinMediumH[] = "PHYSkinMediumH";
static const char kStr_PHYSkinLargeH[] = "PHYSkinLargeH";
static const char kStr_CGlassSmall[] = "CGlassSmall";
static const char kStr_CGlassMedium[] = "CGlassMedium";
static const char kStr_CGlassLarge[] = "CGlassLarge";
static const char kStr_PHYChain[] = "PHYChain";
static const char kStr_CSpecialHeavyStone[] = "CSpecialHeavyStone";
static const char kStr_CSpecialHeavyMetal[] = "CSpecialHeavyMetal";
static const char kStr_CSpecialHeavyWood[] = "CSpecialHeavyWood";
static const char kStr_PHYGenericMetalHollowStatic[] = "PHYGenericMetalHollowStatic";
static const char kStr_PHYGenericMetalHollowSmall[] = "PHYGenericMetalHollowSmall";
static const char kStr_PHYGenericMetalHollowMedium[] = "PHYGenericMetalHollowMedium";
static const char kStr_PHYGenericMetalHollowLarge[] = "PHYGenericMetalHollowLarge";
static const char kStr_PHYGenericMetalSheetStatic[] = "PHYGenericMetalSheetStatic";
static const char kStr_PHYGenericMetalSheetSmall[] = "PHYGenericMetalSheetSmall";
static const char kStr_PHYGenericMetalSheetMedium[] = "PHYGenericMetalSheetMedium";
static const char kStr_PHYGenericMetalSheetLarge[] = "PHYGenericMetalSheetLarge";
static const char kStr_PHYVehicleMetalBodyL[] = "PHYVehicleMetalBodyL";
static const char kStr_PHYVehicleMetalBodyH[] = "PHYVehicleMetalBodyH";
static const char kStr_PHYVehicleMetalSolidL[] = "PHYVehicleMetalSolidL";
static const char kStr_PHYVehicleMetalSolidH[] = "PHYVehicleMetalSolidH";
static const char kStr_PHYVehicleMetalHollowL[] = "PHYVehicleMetalHollowL";
static const char kStr_PHYVehicleMetalHollowH[] = "PHYVehicleMetalHollowH";
static const char kStr_PHYBarrelL[] = "PHYBarrelL";
static const char kStr_PHYBarrelH[] = "PHYBarrelH";
static const char kStr_PHYBottleL[] = "PHYBottleL";
static const char kStr_PHYBottleH[] = "PHYBottleH";
static const char kStr_PHYCanSodaL[] = "PHYCanSodaL";
static const char kStr_PHYCanSodaH[] = "PHYCanSodaH";
static const char kStr_PHYWeaponPistolL[] = "PHYWeaponPistolL";
static const char kStr_PHYWeaponPistolH[] = "PHYWeaponPistolH";
static const char kStr_PHYWeaponRifleL[] = "PHYWeaponRifleL";
static const char kStr_PHYWeaponRifleH[] = "PHYWeaponRifleH";
static const char kStr_PHYShoppingCartL[] = "PHYShoppingCartL";
static const char kStr_PHYShoppingCartH[] = "PHYShoppingCartH";
static const char kStr_PHYLunchboxL[] = "PHYLunchboxL";
static const char kStr_PHYLunchboxH[] = "PHYLunchboxH";
static const char kStr_PHYBabyRattle[] = "PHYBabyRattle";
static const char kStr_PHYRubberBall[] = "PHYRubberBall";
static const char kStr_PHYBottlecaps[] = "PHYBottlecaps";
static const char kStr_PHYChainlink[] = "PHYChainlink";
static const char kStr_PHYTile[] = "PHYTile";
static const char kStr_PHYCarpet[] = "PHYCarpet";
static const char kStr_PHYTumbleweed[] = "PHYTumbleweed";

// Maps a material type and two size values to a material name string via DAT_011c3f2c->FUN_004616c0, returning the resulting id.
// @fnv 0x00839e00
int __cdecl FUN_00839e00(int aiMaterialType, float afSizeA, float afSizeB)
{
    int result = 0;

    switch (aiMaterialType)
    {
    case 0:
    case 15:
        if (afSizeA < DAT_01032980)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CStoneStatic)));
        }
        else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd9c8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CStoneSmall)));
        }
        else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd9b0)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CStoneMedium)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CStoneLarge)));
        }
        break;
    case 2:
        if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd918)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CEarthSmall)));
        }
        else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd9bc)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CEarthMedium)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CEarthLarge)));
        }
        break;
    case 4:
        if (afSizeA < DAT_01034208)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CGrassSmall)));
        }
        else if (afSizeA < DAT_01073568)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CGrassMedium)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CGrassLarge)));
        }
        break;
    case 5:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            if (afSizeA < DAT_01032980)
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalStaticL)));
            }
            else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8f4)))))))
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalSmallL)));
            }
            else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8cc)))))))
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalMediumL)));
            }
            else
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalLargeL)));
            }
        }
        else
        {
            if (afSizeA < DAT_01032980)
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalStaticH)));
            }
            else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8f4)))))))
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalSmallH)));
            }
            else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8cc)))))))
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalMediumH)));
            }
            else
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalLargeH)));
            }
        }
        break;
    case 9:
        if (afSizeA < DAT_01032980)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CWoodStatic)));
        }
        else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd930)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CWoodSmall)));
        }
        else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd9d8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CWoodMedium)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CWoodLarge)));
        }
        break;
    case 1:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericClothL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericClothH)));
        }
        break;
    case 6:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_COrganicSmall)));
        break;
    case 7:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd9a0)))))))
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYSkinSmallL)));
            }
            else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd924)))))))
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYSkinMediumL)));
            }
            else
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYSkinLargeL)));
            }
        }
        else
        {
            if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd9a0)))))))
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYSkinSmallH)));
            }
            else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd924)))))))
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYSkinMediumH)));
            }
            else
            {
                result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYSkinLargeH)));
            }
        }
        break;
    case 3:
        if (afSizeA < DAT_01034208)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CGlassSmall)));
        }
        else if (afSizeA < ::runtimeInitializationDouble5)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CGlassMedium)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CGlassLarge)));
        }
        break;
    case 8:
        if (afSizeA < DAT_01034208)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CWoodSmall)));
        }
        else if (afSizeA < ::runtimeInitializationDouble5)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CWoodMedium)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CWoodLarge)));
        }
        break;
    case 13:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYChain)));
        break;
    case 10:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CSpecialHeavyStone)));
        break;
    case 11:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CSpecialHeavyMetal)));
        break;
    case 12:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_CSpecialHeavyWood)));
        break;
    case 16:
        if (afSizeA < DAT_01032980)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalHollowStatic)));
        }
        else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8f4)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalHollowSmall)));
        }
        else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8cc)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalHollowMedium)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalHollowLarge)));
        }
        break;
    case 17:
        if (afSizeA < DAT_01032980)
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalSheetStatic)));
        }
        else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8f4)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalSheetSmall)));
        }
        else if (afSizeA < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8cc)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalSheetMedium)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYGenericMetalSheetLarge)));
        }
        break;
    case 18:
        break;
    case 19:
        result = 0;
        break;
    case 20:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYVehicleMetalBodyL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYVehicleMetalBodyH)));
        }
        break;
    case 21:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYVehicleMetalSolidL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYVehicleMetalSolidH)));
        }
        break;
    case 22:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYVehicleMetalHollowL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYVehicleMetalHollowH)));
        }
        break;
    case 23:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYBarrelL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYBarrelH)));
        }
        break;
    case 24:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYBottleL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYBottleH)));
        }
        break;
    case 25:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYCanSodaL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYCanSodaH)));
        }
        break;
    case 26:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYWeaponPistolL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYWeaponPistolH)));
        }
        break;
    case 27:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYWeaponRifleL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYWeaponRifleH)));
        }
        break;
    case 28:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYShoppingCartL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYShoppingCartH)));
        }
        break;
    case 29:
        if (afSizeB < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SetObj *>(&::g_011dd8e8)))))))
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYLunchboxL)));
        }
        else
        {
            result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYLunchboxH)));
        }
        break;
    case 30:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYBabyRattle)));
        break;
    case 31:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYRubberBall)));
        break;
    case 14:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYBottlecaps)));
        break;
    case 32:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYChainlink)));
        break;
    case 33:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYTile)));
        break;
    case 34:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYCarpet)));
        break;
    case 35:
        result = ((int)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::StrObj * *>(&::g_dataHandler))))->GetSoundByEditorID(kStr_PHYTumbleweed)));
        break;
    }
    return result;
}

struct S_0083a930_Point3
{
    float x;
    float y;
    float z;
};

struct S_0083a930_NiNode;
class TESSound;

struct S_0083a930_SoundHandle
{
    int unk0;
    int unk4;
    int unk8;
    S_0083a930_SoundHandle();
    ~S_0083a930_SoundHandle();
    S_0083a930_SoundHandle& operator=(const S_0083a930_SoundHandle& other);
    bool FUN_00ad8b60(float x, float y, float z);
    bool FUN_00ad8830(bool flag);
};

struct S_0083a930_Audio
{
    S_0083a930_SoundHandle FUN_00ad7480(const char* path, unsigned int flags, TESSound* sound);
};

class TESForm
{
  public:
    virtual void v000();
};

class TESBoundObject : public TESForm
{
};

class TESSound : public TESBoundObject
{
  public:
public:
    unsigned char GetField45();
};

class TESObjectWEAP : public TESBoundObject
{
  public:
};

struct S_0083a930_EntryData
{
};

struct S_0083a930_Process
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual S_0083a930_EntryData* GetWeaponInfo();  // +0x148
};

class TESObjectREFR
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual S_0083a930_NiNode* GetNode();  // +0x1d0
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual S_0083a930_Point3* GetPos();  // +0x1f4
};

class Actor : public TESObjectREFR
{
  public:
public:
    bool IsSneaking();
};

struct S_0083a930_Setting
{
};


// @fnv 0x0083a930
void PlayWeaponImpactSound(TESObjectREFR* ref, int type)
{
    AutoMemHelper ctx(0xb, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp", 0x6a3);
    S_0083a930_Point3 pos = *ref->GetPos();
    float value = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_0083a930_Setting *>(&::g_011dd900))))));
    bool bUnused = false;
    Actor* actor = dynamic_cast<Actor*>(ref);
    if (actor && ((::S_0083a930_Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())))
    {
        S_0083a930_SoundHandle sound;
        S_0083a930_EntryData* entry = ((::S_0083a930_Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetWeaponInfo();
        TESBoundObject* invObject = entry ? ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())) : 0;
        TESObjectWEAP* weapon = invObject ? dynamic_cast<TESObjectWEAP*>(invObject) : 0;
        if (weapon)
        {
            TESSound* snd = 0;
            switch (type)
            {
            case 9:
                snd = ((::TESSound *)(reinterpret_cast<::FUN_00522520_shell *>((weapon))->GetField238()));
                break;
            case 10:
                snd = ((::TESSound *)(reinterpret_cast<::FUN_00522540_shell *>((weapon))->GetField23C()));
                break;
            }
            if (!snd || !::SoundPlaybackManager::CanPlaySoundAt(snd, (*(::NiPoint3 *)&(const ::S_0083a930_Point3 &)(pos)), 1.0f))
                return;
            bool sneaking = actor->IsSneaking();
            if (actor == (*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))
            {
                sound = ((::S_0083a930_Audio *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(snd)), 0x80004101, snd);
            }
            else
            {
                sound = ((::S_0083a930_Audio *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(snd)), 0x4102, snd);
                sound.FUN_00ad8b60(pos.x, pos.y, pos.z);
                reinterpret_cast<::FUN_00ad8f20_shell *>(&(sound))->FUN_00ad8f20((::NiAVObject *)(::S_0083a930_NiNode *)(ref->GetNode()));
            }
            if (sneaking)
                reinterpret_cast<::FUN_00ad89e0_shell *>(&(sound))->FUN_00ad89e0(::DAT_010231a8);
            else
                reinterpret_cast<::FUN_00ad89e0_shell *>(&(sound))->FUN_00ad89e0(1.0f);
            sound.FUN_00ad8830(false);
        }
    }
}

struct FootstepQuery
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char materialKind;
    unsigned char unk19;
    unsigned short unk1a;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    unsigned short triangle;
    unsigned short unk3e;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    FootstepQuery();
};
struct NavOps
{
};
extern const char armorPowerRightName[];
extern const char armorPowerLeftName[];
extern const char armorRightName[];
extern const char armorLeftName[];
struct PointOps : NiPoint3
{
};
struct ListenerOps
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual const NiPoint3& GetPosition();
};
struct SoundOps
{
};
class TESCreature : public TESBoundObject
{
  public:
    SoundOps* FUN_005f92d0(int);
};
struct MaterialOps
{
};
struct SkinOps
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    MaterialOps material;
};
struct ActorOps
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual bool IsCreature();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool SuppressFootsteps(int);
};
struct AudioOps
{
    SoundPlaybackHandle FUN_00ad73b0(BGSSoundDescriptor*);
    SoundPlaybackHandle FUN_00ad7480(const char*, unsigned int, SoundOps*);
};
extern SoundOps* DAT_011dd860;
extern SoundOps* DAT_011dd864;
extern SoundOps* DAT_011dd868;
extern SoundOps* DAT_011dd86c;
struct FootstepEntry
{
    SoundOps* sounds[10];
};
// Selects a footstep sound for the given foot from the cell material and actor state, then plays it at the actor position or in first person.
// @fnv 0x00837cc0
void PlayFootstepSound(FootstepActor* apActor, int foot)
{
    bool pos;
    SoundOps* memory;
    float armor;
    AutoMemHelper range(11, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp", 735);
    if (FUN_00702360())
        return;
    NiPoint3 firstPerson = apActor->GetPos();
    SoundPlaybackHandle primary;
    SoundPlaybackHandle secondary;
    memory = 0;
    SoundOps* sound = 0;
    pos = false;
    float distance = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_0083a930_Setting *>(&::g_011dd900))))));
    if (((bool)(::FUN_00525420())))
        distance /= 2.0;
    armor = 0.0f;
    if (((::ListenerOps *)(reinterpret_cast<::MagicCaster_shell *>((((::AudioOps *)(::FUN_00453a70()))))->FUN_0044edb0())))
    {
        PointOps delta;
        static_cast<NiPoint3&>(delta) = ((::ListenerOps *)(reinterpret_cast<::MagicCaster_shell *>((((::AudioOps *)(::FUN_00453a70()))))->FUN_0044edb0()))->GetPosition();
        reinterpret_cast<::NiPoint3 *>(&(delta))->Subtract(firstPerson);
        armor = reinterpret_cast<::NiPoint3 *>(&(delta))->ComputeMagnitude();
        if (reinterpret_cast<::NiPoint3 *>(&(delta))->ComputeMagnitude() > distance)
            return;
    }
    if (apActor->IsActor())
    {
        ActorOps* actorOps =
            reinterpret_cast<ActorOps*>(dynamic_cast<Actor*>(reinterpret_cast<TESObjectREFR*>(apActor)));
        if (actorOps->SuppressFootsteps(0))
            return;
        if (actorOps->IsCreature())
        {
            TESBoundObject* base = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<ActorOps*>(apActor)))->FUN_007af430()));
            TESCreature* creature = dynamic_cast<TESCreature*>(base);
            SoundOps* creatureSound = creature->FUN_005f92d0(foot);
            memory = creatureSound;
            if (memory && armor <= reinterpret_cast<::TESSound *>((memory))->GetField45() * 100)
            {
                primary = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad73b0(((::BGSSoundDescriptor *)(reinterpret_cast<::FUN_0084e3a0_Class *>((memory))->FUN_0084e3a0())));
            }
            primary.FUN_00ad8b60(firstPerson.x, firstPerson.y, firstPerson.z);
            if (((void *)(reinterpret_cast<::FUN_00acbb70_shell *>((creature))->FUN_00acbb70())))
                reinterpret_cast<::FUN_00ad8f20_shell *>(&(primary))->FUN_00ad8f20((::NiAVObject *)(void *)(((void *)(reinterpret_cast<::FUN_00acbb70_shell *>((creature))->FUN_00acbb70()))));
            reinterpret_cast<::FUN_00ad89e0_shell *>(&(primary))->FUN_00ad89e0(0.98f);
            primary.FUN_00ad8830(0);
        }
        else
        {
            int materialIndex = 0;
            FootstepCell* cell = ((::FootstepCell *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TESStandIn * *>(&::g_TES))))->GetPrevPath()));
            if (!cell)
                cell =
                    ((::FootstepCell *)(reinterpret_cast<::FUN_00461bc0_cls *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->FUN_00461bc0(firstPerson.x, firstPerson.y, ((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TESStandIn * *>(&::g_TES))))->GetHitSound())), {})));
            bool soundType = false;
            bool movingActor = false;
            if (!reinterpret_cast<::FUN_005a2030_shell *>((actorOps))->FUN_005a2030() && cell && firstPerson.z < reinterpret_cast<::FUN_0057b0a0_shell *>((actorOps))->FUN_0057b0a0() &&
                ((reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior() && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((cell))->FUN_004518e0()) || !reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior()))
                soundType = true;
            ActorOps* material = actorOps;
            if (reinterpret_cast<::FUN_00838750_shell *>((((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((material))->FUN_009306d0()))))->FUN_00838750())
                movingActor = true;
            if (!((::FootstepCell *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TESStandIn * *>(&::g_TES))))->GetPrevPath())) && cell && ((::CellNavInfo *)(reinterpret_cast<::S00546fb0_Cell *>((cell))->FUN_00546fb0())))
            {
                MaterialRecord* result;
                FootstepQuery height;
                reinterpret_cast<::xLand *>((reinterpret_cast<NavOps*>(((::CellNavInfo *)(reinterpret_cast<::S00546fb0_Cell *>((cell))->FUN_00546fb0())))))->FUN_0053b550((*(::xCoordData *)(&height)), (*(const ::xPoint3 *)(&firstPerson)), 1);
                result = ((::MaterialRecord *)(reinterpret_cast<::FUN_0053a630_Class *>((((::CellNavInfo *)(reinterpret_cast<::S00546fb0_Cell *>((cell))->FUN_00546fb0()))))->FUN_0053a630(height.materialKind, height.triangle)));
                float record = 0.0f;
                materialIndex = 0;
                if (soundType)
                    materialIndex = 8;
                else if (material && ((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((material))->FUN_009306d0())) &&
                         ((int)(reinterpret_cast<::ActorMover *>(&(((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((material))->FUN_009306d0()))->material))->GetCurrentMoveModeType())) != 36)
                    materialIndex = ((int)(reinterpret_cast<::ActorMover *>(&(((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((material))->FUN_009306d0()))->material))->GetCurrentMoveModeType()));
                else if (result)
                {
                    materialIndex = ((int)(reinterpret_cast<::FUN_00541570_shell *>((result))->GetField1C()));
                    if (reinterpret_cast<::FakeCell *>((cell))->FUN_005547c0((*(const ::NiPoint3 *)(&firstPerson)), (*(float *)(&record))))
                        firstPerson.z = record;
                }
            }
            else
            {
                if (soundType)
                    materialIndex = 8;
                else if (material && ((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((material))->FUN_009306d0())))
                    materialIndex = ((int)(reinterpret_cast<::ActorMover *>(&(((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((material))->FUN_009306d0()))->material))->GetCurrentMoveModeType()));
            }
            if (foot > 1)
                foot -= 2;
            int special = foot == 0;
            int water = 0;
            if (reinterpret_cast<::Actor *>((actorOps))->IsSneaking())
                special = foot ? 4 : 5;
            else if (movingActor)
                special = foot ? 6 : 7;
            else if (reinterpret_cast<::FUN_00884730_shell *>((actorOps))->FUN_00884730())
                special = foot ? 2 : 3;
            water = GetTypeValue(materialIndex);
            memory = DAT_011dd650[water].sounds[special];
            if (reinterpret_cast<::FUN_008ba410_shell *>((actorOps))->FUN_008ba410())
            {
                if (!DAT_011dd860 || !DAT_011dd864)
                {
                    DAT_011dd864 =
                        reinterpret_cast<SoundOps*>(((::BGSImpactData *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->GetSoundByEditorID(armorPowerRightName))));
                    DAT_011dd860 =
                        reinterpret_cast<SoundOps*>(((::BGSImpactData *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->GetSoundByEditorID(armorPowerLeftName))));
                }
                sound = foot ? DAT_011dd860 : DAT_011dd864;
            }
            else if (reinterpret_cast<::FUN_008ba440_shell *>((actorOps))->FUN_008ba440())
            {
                if (!DAT_011dd868 || !DAT_011dd86c)
                {
                    DAT_011dd86c = reinterpret_cast<SoundOps*>(((::BGSImpactData *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->GetSoundByEditorID(armorRightName))));
                    DAT_011dd868 = reinterpret_cast<SoundOps*>(((::BGSImpactData *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->GetSoundByEditorID(armorLeftName))));
                }
                sound = foot ? DAT_011dd868 : DAT_011dd86c;
            }
            if (apActor == (*reinterpret_cast<::FootstepActor * *>(&::_g_thePlayer)) && !::FUN_00524d10((bool *)((*reinterpret_cast<::FootstepActor * *>(&::_g_thePlayer)))))
                pos = true;
            if (pos)
            {
                unsigned int flags = 0x4109;
                if (memory)
                {
                    primary = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(memory)), flags, memory);
                    reinterpret_cast<::FUN_00ad89e0_shell *>(&(primary))->FUN_00ad89e0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_0083a930_Setting *>(&::g_011dd988)))))));
                    primary.FUN_00ad8830(0);
                }
                if (sound)
                {
                    secondary = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(sound)), flags, sound);
                    reinterpret_cast<::FUN_00ad89e0_shell *>(&(secondary))->FUN_00ad89e0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_0083a930_Setting *>(&::g_011dd988)))))));
                    secondary.FUN_00ad8830(0);
                }
            }
            else
            {
                unsigned int flags = 0x410a;
                if (memory && armor <= reinterpret_cast<::TESSound *>((memory))->GetField45() * 100)
                {
                    primary = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(memory)), flags, memory);
                    primary.FUN_00ad8b60(firstPerson.x, firstPerson.y, firstPerson.z - 128.0);
                    if (apActor->Get3D())
                        reinterpret_cast<::FUN_00ad8f20_shell *>(&(primary))->FUN_00ad8f20((::NiAVObject *)(void *)(apActor->Get3D()));
                    reinterpret_cast<::FUN_00ad89e0_shell *>(&(primary))->FUN_00ad89e0(::RandomFloat(0.9f, 1.0f));
                    primary.FUN_00ad8830(0);
                }
                if (sound && armor <= reinterpret_cast<::TESSound *>((sound))->GetField45() * 100)
                {
                    secondary = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(sound)), flags, sound);
                    secondary.FUN_00ad8b60(firstPerson.x, firstPerson.y, firstPerson.z - 128.0);
                    if (apActor->Get3D())
                        reinterpret_cast<::FUN_00ad8f20_shell *>(&(secondary))->FUN_00ad8f20((::NiAVObject *)(void *)(apActor->Get3D()));
                    reinterpret_cast<::FUN_00ad89e0_shell *>(&(secondary))->FUN_00ad89e0(1.0 - ::RandomFloat(0.0f, ::DAT_0101e2bc));
                    secondary.FUN_00ad8830(0);
                }
            }
        }
    }
}

struct FUN_00ad8b60_h
{
    bool FUN_00ad8b60(float x, float y, float z);
};

struct FUN_00ad8830_shell : FUN_00ad8b60_h
{
    bool FUN_00ad8830(bool flag);
};

struct SH_00418890 : FUN_00ad8830_shell
{
    void FUN_copy(const void* src);
};

struct GlobalObject_0041a250 : SH_00418890
{
    int unk00;
    int unk04;
    int unk08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};

struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    ~BSSoundHandleEx();
};

class BSAudio
{
  public:
    BSSoundHandleEx FUN_00ad7480(const char* path, unsigned int flags, unsigned int sound);
    BSSoundHandleEx GetSoundHandleByEditorID(const char* name, unsigned int flags);
};

struct FUN_005224e0_class
{
    unsigned int GetField230();
};

struct FUN_00522df0_shell : FUN_005224e0_class
{
    int FUN_00446390();
};

struct NiPoint3_ext : NiPoint3
{
    NiPoint3_ext();
};


// @fnv 0x008397f0
void PlayBlockSound(int aUnused, FUN_00522df0_shell* pObject, float x0, float y0, float z0, float x1, float y1,
                    float z1)
{
    GlobalObject_0041a250 p;
    if (pObject != 0 && pObject->GetField230() != 0)
    {
        BSSoundHandleEx sound = ::FUN_00453a70()->FUN_00ad7480(::FUN_00511840((char *)(((TESSound*)pObject->GetField230()))), 0x182,
                                                                pObject->GetField230());
        p.FUN_copy(&sound);
    }
    else
    {
        int weaponType = (pObject != 0) ? pObject->FUN_00446390() : -1;
        switch (weaponType)
        {
        case -1:
            {
                BSSoundHandleEx sound = ::FUN_00453a70()->GetSoundHandleByEditorID("WPNBlockHand", 0x182);
                p.FUN_copy(&sound);
            }
            break;
        default:
            {
                BSSoundHandleEx sound = ::FUN_00453a70()->GetSoundHandleByEditorID("WPNBlockMelee", 0x182);
                p.FUN_copy(&sound);
            }
            break;
        }
    }
    NiPoint3_ext v;
    v.x = (float)(FUN_0040ebd0(x0, x1) + (FUN_00404010(x0, x1) - FUN_0040ebd0(x0, x1)) / 2.0);
    v.y = (float)(FUN_0040ebd0(y0, y1) + (FUN_00404010(y0, y1) - FUN_0040ebd0(y0, y1)) / 2.0);
    v.z = (float)(FUN_0040ebd0(z0, z1) + (FUN_00404010(z0, z1) - FUN_0040ebd0(z0, z1)) / 2.0);
    p.FUN_00ad8b60(v.x, v.y, v.z);
    p.FUN_00ad8830(false);
}

extern SoundOps* DAT_011dd870;
extern SoundOps* DAT_011dd874;
// Plays a footstep or jump sound for ref, choosing the material sound and optional armor/jump sound based on the surface and actor state.
// @fnv 0x00838780
void __cdecl FUN_00838780(TESObjectREFR* apRefr)
{
    AutoMemHelper memCtx5(11, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp", 941);
    if (FUN_00702360())
        return;
    S_0083a930_Point3 pos20 = *apRefr->GetPos();
    SoundPlaybackHandle handle12;
    SoundPlaybackHandle handle6;
    SoundOps* impact1 = 0;
    SoundOps* second9 = 0;
    bool isBaby9 = false;
    float scale2 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_0083a930_Setting *>(&::g_011dd900))))));
    if (((bool)(::FUN_00525420())))
        scale2 /= 2.0;
    float distBX = 0.0f;
    if (((::ListenerOps *)(reinterpret_cast<::MagicCaster_shell *>((((::AudioOps *)(::FUN_00453a70()))))->FUN_0044edb0())))
    {
        PointOps vec = *(PointOps*)&((::ListenerOps *)(reinterpret_cast<::MagicCaster_shell *>((((::AudioOps *)(::FUN_00453a70()))))->FUN_0044edb0()))->GetPosition();
        reinterpret_cast<::NiPoint3 *>(&(vec))->Subtract(*(NiPoint3*)&pos20);
        distBX = reinterpret_cast<::NiPoint3 *>(&(vec))->ComputeMagnitude();
        if (scale2 < reinterpret_cast<::NiPoint3 *>(&(vec))->ComputeMagnitude())
            return;
    }
    if (((FootstepActor*)apRefr)->IsActor())
    {
        ActorOps* pActor = (ActorOps*)dynamic_cast<Actor*>(apRefr);
        if (pActor->SuppressFootsteps(0))
            return;
        if (pActor->IsCreature())
        {
            TESBoundObject* bolt6 = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((ActorOps*)apRefr)))->FUN_007af430()));
            TESCreature* creature6 = dynamic_cast<TESCreature*>(bolt6);
            SoundOps* csnd = creature6->FUN_005f92d0(0x14);
            impact1 = csnd;
            if (impact1)
            {
                if ((float)(reinterpret_cast<::TESSound *>((impact1))->GetField45() * 100) >= distBX)
                {
                    handle12 = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad73b0(((::BGSSoundDescriptor *)(reinterpret_cast<::FUN_0084e3a0_Class *>((impact1))->FUN_0084e3a0())));
                }
            }
            reinterpret_cast<::FUN_00ad8b60_h *>(&(handle12))->FUN_00ad8b60(pos20.x, pos20.y, pos20.z);
            if (((void *)(reinterpret_cast<::FUN_00acbb70_shell *>((creature6))->FUN_00acbb70())))
                reinterpret_cast<::FUN_00ad8f20_shell *>(&(handle12))->FUN_00ad8f20((::NiAVObject *)(void *)(((void *)(reinterpret_cast<::FUN_00acbb70_shell *>((creature6))->FUN_00acbb70()))));
            reinterpret_cast<::FUN_00ad89e0_shell *>(&(handle12))->FUN_00ad89e0(0.98f);
            reinterpret_cast<::FUN_00ad8830_shell *>(&(handle12))->FUN_00ad8830(0);
        }
        else
        {
            int material6 = 0;
            FootstepCell* cell8 = ((::FootstepCell *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TESStandIn * *>(&::g_TES))))->GetPrevPath()));
            if (!cell8)
                cell8 = ((::FootstepCell *)(reinterpret_cast<::FUN_00461bc0_cls *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->FUN_00461bc0(pos20.x, pos20.y, ((::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TESStandIn * *>(&::g_TES))))->GetHitSound())), {})));
            bool flagWater6 = false;
            bool local2 = false;
            if (!reinterpret_cast<::FUN_005a2030_shell *>((pActor))->FUN_005a2030())
            {
                if (cell8 && pos20.z < reinterpret_cast<::FUN_0057b0a0_shell *>((pActor))->FUN_0057b0a0())
                {
                    if ((reinterpret_cast<::TESObjectCELL *>((cell8))->IsCellInterior() && reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((cell8))->FUN_004518e0()) || !reinterpret_cast<::TESObjectCELL *>((cell8))->IsCellInterior())
                        flagWater6 = true;
                }
            }
            ActorOps* pq = pActor;
            if (reinterpret_cast<::FUN_00838750_shell *>((((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pq))->FUN_009306d0()))))->FUN_00838750())
                local2 = true;
            if (!((::FootstepCell *)(reinterpret_cast<::BGSCameraPath *>(((*reinterpret_cast<::TESStandIn * *>(&::g_TES))))->GetPrevPath())) && cell8 && ((::CellNavInfo *)(reinterpret_cast<::S00546fb0_Cell *>((cell8))->FUN_00546fb0())))
            {
                FootstepQuery query4;
                reinterpret_cast<::xLand *>((((::CellNavInfo *)(reinterpret_cast<::S00546fb0_Cell *>((cell8))->FUN_00546fb0()))))->FUN_0053b550((*(::xCoordData *)((NavQueryResult*)&query4)), (*(const ::xPoint3 *)((NiPoint3*)&pos20)), 1);
                MaterialRecord* localA = ((::MaterialRecord *)(reinterpret_cast<::FUN_0053a630_Class *>((((::CellNavInfo *)(reinterpret_cast<::S00546fb0_Cell *>((cell8))->FUN_00546fb0()))))->FUN_0053a630(query4.materialKind, query4.triangle)));
                float heightStepB = 0.0f;
                material6 = 0;
                if (flagWater6)
                    material6 = 8;
                else if (pq && ((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pq))->FUN_009306d0())) && ((int)(reinterpret_cast<::ActorMover *>(&(((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pq))->FUN_009306d0()))->material))->GetCurrentMoveModeType())) != 0x24)
                    material6 = ((int)(reinterpret_cast<::ActorMover *>(&(((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pq))->FUN_009306d0()))->material))->GetCurrentMoveModeType()));
                else if (localA)
                {
                    material6 = ((int)(reinterpret_cast<::FUN_00541570_shell *>((localA))->GetField1C()));
                    if (reinterpret_cast<::FakeCell *>((cell8))->FUN_005547c0((*(const ::NiPoint3 *)((NiPoint3*)&pos20)), (*(float *)(&heightStepB))))
                        pos20.z = heightStepB;
                }
            }
            else
            {
                if (flagWater6)
                    material6 = 8;
                else if (pq && ((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pq))->FUN_009306d0())))
                    material6 = ((int)(reinterpret_cast<::ActorMover *>(&(((::SkinOps *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((pq))->FUN_009306d0()))->material))->GetCurrentMoveModeType()));
            }
            int idx11 = 9;
            int typeY = 0;
            typeY = GetTypeValue(material6);
            impact1 = DAT_011dd650[typeY].sounds[idx11];
            if (reinterpret_cast<::FUN_008ba410_shell *>((pActor))->FUN_008ba410())
            {
                if (!DAT_011dd874)
                    DAT_011dd874 = (SoundOps*)((::BGSImpactData *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->GetSoundByEditorID("FSTJumpPower")));
                second9 = DAT_011dd870;
            }
            else if (reinterpret_cast<::FUN_008ba440_shell *>((pActor))->FUN_008ba440())
            {
                if (!DAT_011dd870)
                    DAT_011dd870 = (SoundOps*)((::BGSImpactData *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::DataHandlerStandIn * *>(&::g_dataHandler))))->GetSoundByEditorID("FSTJumpArmor")));
                second9 = DAT_011dd870;
            }
            if (apRefr == (TESObjectREFR*)(*reinterpret_cast<::FootstepActor * *>(&::_g_thePlayer)))
            {
                if (!::FUN_00524d10((bool *)((*reinterpret_cast<::FootstepActor * *>(&::_g_thePlayer)))))
                    isBaby9 = true;
            }
            if (isBaby9)
            {
                int flags = 0x4109;
                if (impact1)
                {
                    handle12 = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(impact1)), flags, impact1);
                    reinterpret_cast<::FUN_00ad89e0_shell *>(&(handle12))->FUN_00ad89e0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_0083a930_Setting *>(&::g_011dd988)))))));
                    reinterpret_cast<::FUN_00ad8830_shell *>(&(handle12))->FUN_00ad8830(0);
                }
                if (second9)
                {
                    handle6 = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(second9)), flags, second9);
                    reinterpret_cast<::FUN_00ad89e0_shell *>(&(handle6))->FUN_00ad89e0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_0083a930_Setting *>(&::g_011dd988)))))));
                    reinterpret_cast<::FUN_00ad8830_shell *>(&(handle6))->FUN_00ad8830(0);
                }
            }
            else
            {
                int flags2 = 0x410a;
                if (!::SoundPlaybackManager::CanPlaySoundAt((TESSound*)impact1, (*(::NiPoint3 *)&(const ::S_0083a930_Point3 &)(pos20)), 1.0f) && !::SoundPlaybackManager::CanPlaySoundAt((TESSound*)second9, (*(::NiPoint3 *)&(const ::S_0083a930_Point3 &)(pos20)), 1.0f))
                    return;
                if (impact1)
                {
                    if ((float)(reinterpret_cast<::TESSound *>((impact1))->GetField45() * 100) >= distBX)
                    {
                        handle12 = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(impact1)), flags2, impact1);
                        reinterpret_cast<::FUN_00ad8b60_h *>(&(handle12))->FUN_00ad8b60(pos20.x, pos20.y, (float)(pos20.z - 128.0));
                        if (apRefr->GetNode())
                            reinterpret_cast<::FUN_00ad8f20_shell *>(&(handle12))->FUN_00ad8f20((::NiAVObject *)(void *)(apRefr->GetNode()));
                        reinterpret_cast<::FUN_00ad89e0_shell *>(&(handle12))->FUN_00ad89e0(::RandomFloat(0.9f, 1.0f));
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(handle12))->FUN_00ad8830(0);
                    }
                }
                if (second9)
                {
                    if ((float)(reinterpret_cast<::TESSound *>((second9))->GetField45() * 100) >= distBX)
                    {
                        handle6 = ((::AudioOps *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(second9)), flags2, second9);
                        reinterpret_cast<::FUN_00ad8b60_h *>(&(handle6))->FUN_00ad8b60(pos20.x, pos20.y, (float)(pos20.z - 128.0));
                        if (apRefr->GetNode())
                            reinterpret_cast<::FUN_00ad8f20_shell *>(&(handle6))->FUN_00ad8f20((::NiAVObject *)(void *)(apRefr->GetNode()));
                        reinterpret_cast<::FUN_00ad89e0_shell *>(&(handle6))->FUN_00ad89e0(1.0f - ::RandomFloat(0.0f, ::DAT_0101e2bc));
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(handle6))->FUN_00ad8830(0);
                    }
                }
            }
        }
    }
}

namespace ImpactSound {

typedef NiPoint3 ImpactPoint;

struct ImpactMemContext
{
    int iOldContext;
    ImpactMemContext(int aiContext, bool abPush, const char* apFile, int aiLine);
    ~ImpactMemContext();
};

struct ImpactTimer
{
    int iData;
    ImpactTimer();
    ~ImpactTimer();
};

struct ImpactFormType
{
    int iData;
    ImpactFormType();
};

struct ImpactObject
{
    ImpactFormType FUN_0043b4f0();
};

struct ImpactData
{
    ImpactPoint kPos;
    float fImpulse;
    int iUnk10;
    char cMaterialA;
    char cMaterialB;
    short sUnk16;
    unsigned int uiKey;
    ImpactObject* pObjectA;
    ImpactObject* pObjectB;
};

struct ImpactSoundForm
{
};

struct ImpactDataHandler
{
};

struct ImpactSoundHandle
{
    int m_uiSoundID;
    int iState;
    int iFlags;
    ImpactSoundHandle();
    ~ImpactSoundHandle();
    ImpactSoundHandle& operator=(const ImpactSoundHandle& arOther);
};

struct ImpactAudio
{
    ImpactSoundHandle FUN_00ad73b0(unsigned int auiFormID, unsigned int auiFlags);
};

struct ImpactHistory
{
};

struct ImpactIntSetting
{
};

struct ImpactClock
{
};



static const char kCollisionSourcePath[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp";
static const char s_szTimerName[] = "ImpactMixer::PlayCollisionSound";
static const char s_szShotgun[] = "PHYCasingShotgun";
static const char s_szPistol[] = "PHYCasingPistol";
static const char s_szRifle[] = "PHYCasingRifle";

// Selects impact sounds from collision materials and object masses, adjusts frequency and volume from impulse, and prunes impact history.
// @fnv 0x00837550
void FUN_00837550(ImpactData* apImpact)
{
    ImpactMemContext kMemContext(0xb, true, kCollisionSourcePath, 0x234);
    if (apImpact->pObjectA == apImpact->pObjectB && apImpact->pObjectA)
        return;
    static ImpactTimer s_kTimer;
    reinterpret_cast<::GlobalObject_0044fae0 *>(&(s_kTimer))->FUN_004538a0((int)(s_szTimerName));
    float fScaledImpulseRes = apImpact->fImpulse * 0.014287499710917473;
    float fWaterLevelItem = apImpact->fImpulse / ::DAT_010179e0;
    unsigned int uiFlagsTmp = 0;
    if (apImpact->cMaterialA == 0x24 && apImpact->cMaterialB == 6)
        fWaterLevelItem *= 4.0;
    {
        float fMassASample = apImpact->pObjectA ? reinterpret_cast<::bhkRigidBody *>((apImpact->pObjectA))->GetBodyMass() : 5.0f;
        float fMassOfB = apImpact->pObjectB ? reinterpret_cast<::bhkRigidBody *>((apImpact->pObjectB))->GetBodyMass() : 5.0f;
        bool bCasingVal = false;
        ImpactSoundForm* pSoundA = 0;
        ImpactSoundForm* pSoundBNew = 0;
        if ((apImpact->pObjectA && reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::ImpactSound::ImpactFormType &)(apImpact->pObjectA->FUN_0043b4f0()))->FUN_0043b4d0() == 0x19) ||
            (apImpact->pObjectB && reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::ImpactSound::ImpactFormType &)(apImpact->pObjectB->FUN_0043b4f0()))->FUN_0043b4d0() == 0x19))
            bCasingVal = true;
        if (!bCasingVal)
        {
            pSoundA = ((::ImpactSound::ImpactSoundForm *)(::FUN_00839e00(apImpact->cMaterialA, fMassASample, apImpact->fImpulse)));
            pSoundBNew = ((::ImpactSound::ImpactSoundForm *)(::FUN_00839e00(apImpact->cMaterialB, fMassOfB, apImpact->fImpulse)));
        }
        else
        {
            uiFlagsTmp = 0x80;
            float fMass = fMassASample > fMassOfB ? fMassASample : fMassOfB;
            if (fMass < 1.0)
                pSoundA = ((::ImpactSound::ImpactSoundForm *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::ImpactSound::ImpactDataHandler * *>(&::g_dataHandler))))->GetSoundByEditorID(s_szShotgun)));
            else if (::FUN_0040eb10(fMass, 2.0f, 0.25f))
                pSoundA = ((::ImpactSound::ImpactSoundForm *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::ImpactSound::ImpactDataHandler * *>(&::g_dataHandler))))->GetSoundByEditorID(s_szPistol)));
            else
                pSoundA = ((::ImpactSound::ImpactSoundForm *)(reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::ImpactSound::ImpactDataHandler * *>(&::g_dataHandler))))->GetSoundByEditorID(s_szRifle)));
            pSoundBNew = 0;
        }
        if (!::SoundPlaybackManager::CanPlaySoundAt((::TESSound *)(pSoundA), apImpact->kPos, 1.0f) && !::SoundPlaybackManager::CanPlaySoundAt((::TESSound *)(pSoundBNew), apImpact->kPos, 1.0f))
        {
            reinterpret_cast<::ActorTaskManager *>(&(s_kTimer))->WaitForTasksDuringRendering();
            return;
        }
        ImpactSoundHandle kHandleAResult;
        ImpactSoundHandle kHandleB;
        unsigned int uiNow = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ImpactSound::ImpactClock *>(&::g_timeGlobal))))->FUN_00825c00();
        unsigned int uiLastTime = 0;
        if (reinterpret_cast<::fnv_00853130::NiTMapBase *>(&((*reinterpret_cast<::ImpactSound::ImpactHistory *>(&::g_011dd948))))->FUN_00853130(apImpact->uiKey, (::fnv_00853130::CombatThreatRecord *&)(uiLastTime)) &&
            uiNow - uiLastTime < (unsigned int)*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ImpactSound::ImpactIntSetting *>(&::g_011dd968)))))))
        {
            reinterpret_cast<::ActorTaskManager *>(&(s_kTimer))->WaitForTasksDuringRendering();
            return;
        }
        else
        {
            reinterpret_cast<::FUN_00844700_Class *>(&((*reinterpret_cast<::ImpactSound::ImpactHistory *>(&::g_011dd948))))->FUN_00844700(apImpact->uiKey, uiNow);
        }
        if (pSoundA && !(apImpact->cMaterialA == 7 && apImpact->cMaterialB == 7))
            kHandleAResult =
                ((::ImpactSound::ImpactAudio *)(::FUN_00453a70()))->FUN_00ad73b0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pSoundA))->FUN_0084e3a0())), uiFlagsTmp | 2 | 0x100 | 0x4000);
        if (pSoundBNew && !(apImpact->cMaterialA == 7 && apImpact->cMaterialB == 7))
            kHandleB =
                ((::ImpactSound::ImpactAudio *)(::FUN_00453a70()))->FUN_00ad73b0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pSoundBNew))->FUN_0084e3a0())), uiFlagsTmp | 2 | 0x100 | 0x4000);
        unsigned int uiFrequencyVal =
            (unsigned int)((1.0 - (apImpact->fImpulse / 400.0 > 1.0 ? 1.0 : apImpact->fImpulse / 400.0)) * 3000.0);
        float fVolumeLoc = uiFrequencyVal < 0x5dc ? 1.0 : (uiFrequencyVal - 4500.0) / -3000.0;
        if (pSoundA)
        {
            reinterpret_cast<::FUN_00ad9030_shell *>(&(kHandleAResult))->FUN_00ad9030(0xff);
            reinterpret_cast<::FUN_00ad8b60_h *>(&(kHandleAResult))->FUN_00ad8b60(apImpact->kPos.x, apImpact->kPos.y, apImpact->kPos.z);
            reinterpret_cast<::FUN_00ad89b0_shell *>(&(kHandleAResult))->SetStaticAttenuation(uiFrequencyVal);
            reinterpret_cast<::SoundPlaybackHandle *>(&(kHandleAResult))->SetPlaybackFrequency(fVolumeLoc);
            reinterpret_cast<::FUN_00ad8830_shell *>(&(kHandleAResult))->FUN_00ad8830(false);
        }
        if (pSoundBNew)
        {
            reinterpret_cast<::FUN_00ad9030_shell *>(&(kHandleB))->FUN_00ad9030(0xff);
            reinterpret_cast<::FUN_00ad8b60_h *>(&(kHandleB))->FUN_00ad8b60(apImpact->kPos.x, apImpact->kPos.y, apImpact->kPos.z);
            reinterpret_cast<::FUN_00ad89b0_shell *>(&(kHandleB))->SetStaticAttenuation(uiFrequencyVal);
            reinterpret_cast<::SoundPlaybackHandle *>(&(kHandleB))->SetPlaybackFrequency(fVolumeLoc);
            reinterpret_cast<::FUN_00ad8830_shell *>(&(kHandleB))->FUN_00ad8830(false);
        }
        (*reinterpret_cast<::NiPoint3 *>(&::g_011dd958)) = apImpact->kPos;
    }
    int iMaxAge = *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::ImpactSound::ImpactIntSetting *>(&::g_011dd968)))))) * 4;
    void* pIter = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&((*reinterpret_cast<::ImpactSound::ImpactHistory *>(&::g_011dd948))))->GetFirstPos();
    int iNowCur = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ImpactSound::ImpactClock *>(&::g_timeGlobal))))->FUN_00825c00();
    unsigned int uiVisited = 0;
    while (pIter)
    {
        uiVisited++;
        unsigned int uiEntryKeyVal;
        int iEntryTime;
        reinterpret_cast<::C6b7f20_Map *>(&((*reinterpret_cast<::ImpactSound::ImpactHistory *>(&::g_011dd948))))->FUN_006b7f20((::C6b7f20_Node **)&(pIter), (unsigned int *)&(uiEntryKeyVal), (void **)&(iEntryTime));
        if (iNowCur - iEntryTime > iMaxAge)
        {
            reinterpret_cast<::NiTMap_S *>(&((*reinterpret_cast<::ImpactSound::ImpactHistory *>(&::g_011dd948))))->RemoveKey(uiEntryKeyVal);
            pIter = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&((*reinterpret_cast<::ImpactSound::ImpactHistory *>(&::g_011dd948))))->GetFirstPos();
        }
        if (uiVisited > 0x100)
        {
            reinterpret_cast<::FUN_00438af0_Class *>(&((*reinterpret_cast<::ImpactSound::ImpactHistory *>(&::g_011dd948))))->FUN_00438af0();
            pIter = 0;
        }
    }
    reinterpret_cast<::ActorTaskManager *>(&(s_kTimer))->WaitForTasksDuringRendering();
}

}

bool FUN_00839da0();
void FUN_00839dc0(bool b);
int GetTypeValue(int aiType);

struct MemoryManager
{
};
struct Point3
{
    float x;
    float y;
    float z;
    __forceinline Point3()
    {}
    __forceinline Point3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    __forceinline Point3 operator+(const Point3& o) const
    {
        return Point3(o.x + x, o.y + y, o.z + z);
    }
    __forceinline Point3 operator*(float s) const
    {
        return Point3(s * x, s * y, s * z);
    }
    Point3 FUN_00439ef0(const Point3& other) const
    {
        const Point3* self = this;
        return Point3(self->x - other.x, self->y - other.y, self->z - other.z);
    }
    Point3 FUN_004b3800(const Point3& axis) const
    {
        const Point3* self = this;
        return Point3(self->y * axis.z - self->z * axis.y, self->z * axis.x - self->x * axis.z,
                      self->x * axis.y - self->y * axis.x);
    }
};

struct FilterData
{
    unsigned int collisionLayer;
    unsigned int group;
    unsigned int flags;
    unsigned int subsystem;

};
extern void FUN_00401050(void* storage, unsigned int elementSize, unsigned int count,
                                   void(__cdecl* constructor)(void*));
extern void __cdecl FUN_004a7800(void* value);
extern void* __cdecl FUN_00aa13e0(unsigned int bytes);
struct FilterArray
{
    FilterData values[8];
    __forceinline FilterArray()
    {
        FUN_00401050(values, 16, 8, FUN_004a7800);
    }
};
struct CollisionShape
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
};
struct CollisionGenerator : CollisionShape
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    CollisionGenerator(unsigned int count, Point3* vertices, int unused, FilterData* _filters, int a, int b, int c,
                       int d, void* data);
};
// @fnv 0x00c55d50
CollisionShape* __cdecl FUN_00c55d50(Point3* start, Point3* end, float forwardExtent, float backwardExtent,
                                     float upExtent, float downExtent, FilterData* nearFilter, FilterData* farFilter)
{
    Point3* verticesX;
    verticesX = new Point3[8];
    Point3 directionX = ([&] { ::Point3 difference; reinterpret_cast<::FUN_00439ef0_class *>((void *)(start))->FUN_00439ef0((::NiPoint3 *)&difference, *(const ::NiPoint3 *)((::NiPoint3 *)&(*end))); return difference; }());
    Point3 verticalAxisB(0.0f, 0.0f, 1.0f);
    Point3 crossVal2 = directionX.FUN_004b3800(verticalAxisB);
    crossVal2.z = 0.0f;
    reinterpret_cast<::FUN_004a0c10_s *>(&(crossVal2))->FUN_004a0c10();
    Point3 forwardVectorB = crossVal2 * forwardExtent;
    Point3 reverseVector2 = crossVal2 * (-backwardExtent);
    Point3 offset(0.0f, 0.0f, upExtent);
    Point3 below2(0.0f, 0.0f, -downExtent);
    verticesX[0] = offset + (reverseVector2 + *end);
    verticesX[1] = offset + (forwardVectorB + *end);
    verticesX[2] = below2 + (reverseVector2 + *end);
    verticesX[3] = below2 + (forwardVectorB + *end);
    verticesX[4] = offset + (reverseVector2 + *start);
    verticesX[5] = offset + (forwardVectorB + *start);
    verticesX[6] = below2 + (reverseVector2 + *start);
    verticesX[7] = (*(::Point3 *)(reinterpret_cast<::Point3Offset *>((void *)(void *)&(const ::Point3 &)((forwardVectorB + *start)))->ProjectileLaunched((::NiPoint3 *)&(below2), {})));
    FilterData* _filters = 0;
    if (nearFilter || farFilter)
    {
        _filters = reinterpret_cast<FilterData*>(new FilterArray);
        if (nearFilter && !farFilter)
            farFilter = nearFilter;
        else if (farFilter && !nearFilter)
            nearFilter = farFilter;
        for (unsigned int indexC = 0; indexC < 4; ++indexC)
            _filters[indexC] = *farFilter;
        for (unsigned int index7 = 4; index7 < 8; ++index7)
            _filters[index7] = *nearFilter;
    }
    unsigned short* pData6 = new unsigned short[36];
    std::memmove(pData6, &(*reinterpret_cast<unsigned char *>(&::DAT_010c2c38)), 0x48);
    CollisionGenerator* shape2 = new CollisionGenerator(8, verticesX, 0, _filters, 0, 0, 0, 12, pData6);
    shape2->slot0e8();
    return shape2;
}
#include "generated/data/fallout/audio/impactmixer.inc"
#include "generated/data/fallout/audio/impactmixer_ob1_variant.inc"
