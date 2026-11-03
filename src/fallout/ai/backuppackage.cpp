
// src/fallout/ai/backuppackage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/backuppackage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/A90Cls.h"
#include "fnv/decl/Actor.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00672fc0_shell.h"
#include "fnv/decl/FUN_00678fd0_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_009ed330.h"
#include "fnv/decl/LocationDescriptor.h"
#include "fnv/decl/Package679120.h"
#include "fnv/decl/Package6798c0.h"
#include "fnv/decl/PackageEx.h"
#include "fnv/decl/PackageTargetRecord.h"
#include "fnv/decl/Script.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_00671d30__FUN_00671d30_shell.h"
#include "fnv/decl/fnv_00679340__Package679.h"
#include "fnv/decl/fnv_0067a1b0__FUN_0067a1b0_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00670000.h"
struct FUN_00679a90_shell
{
};

struct FUN_009ed010_shell
{
    void ForwardToBase(void* apBuffer);
};

// @fnv 0x009ed010
void FUN_009ed010_shell::ForwardToBase(void* apBuffer)
{
    reinterpret_cast<::A90Cls *>((((FUN_00679a90_shell*)this)))->DispatchToSubobjects((int)(apBuffer));
}

struct BackUpPackage
{
    virtual ~BackUpPackage();
    void FUN_009ed330();
    void* DestroyOrFree(unsigned int flags);
};

void BackUpPackage::FUN_009ed330()
{}

// Calls FUN_009ed330, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x009ed0a0
void* BackUpPackage::DestroyOrFree(unsigned int flags)
{
    reinterpret_cast<::FUN_009ed330 *>(this)->FUN_009ed330::~FUN_009ed330();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006797c0_arg;
struct FUN_006797c0_shell
{
public:
    void FUN_006797c0(::FUN_006797c0_arg *);
};

struct BGSSaveFormBuffer
{
};

struct FUN_009edb60_shell : public BackUpPackage
{
    void FUN_009edb60(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x009edb60
void FUN_009edb60_shell::FUN_009edb60(BGSSaveFormBuffer* apBuffer)
{
    ((FUN_006797c0_shell*)this)->FUN_006797c0((::FUN_006797c0_arg *)(apBuffer));
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x80, 0xc, 0);
}

struct BGSLoadFormBuffer
{
};
enum PACKAGE_PROCEDURE_TYPE;
struct TESPackage
{
public:
    void SetMustReachLocation(bool);
public:
    void SetMustComplete(bool);
public:
    void SetProcedureType(::PACKAGE_PROCEDURE_TYPE);
};
struct BackUpPackageProxy : TESPackage
{
    void LoadGameWithBackup(BGSLoadFormBuffer*);
};
// Calls TESPackage::LoadGame on the buffer, then reads 12 bytes from the buffer into the object at offset 0x80.
// @fnv 0x009edb90
void BackUpPackageProxy::LoadGameWithBackup(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::Package6798c0 *>(this)->LoadPackage((::LoadBuffer6798c0 *)(apLoadGameBuffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x80)), 12);
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};

struct Saver
{
};

struct TESSound
{
    unsigned int formID;
    unsigned char byte04;
    unsigned char flags;
};

struct TESForm
{
    virtual void V000()
    {}
    virtual void V001()
    {}
    virtual void V002()
    {}
    virtual void V003()
    {}
    virtual void V004()
    {}
    virtual void V005()
    {}
    virtual void V006()
    {}
    virtual void V007()
    {}
    virtual void V008()
    {}
    virtual void V009()
    {}
    virtual void V010()
    {}
    virtual void V011()
    {}
    virtual void V012()
    {}
    virtual void V013()
    {}
    virtual void V014()
    {}
    virtual void V015()
    {}
    virtual void V016()
    {}
    virtual void V017()
    {}
    virtual void V018()
    {}
    virtual void V019()
    {}
    virtual void V020()
    {}
    virtual void V021()
    {}
    virtual void V022()
    {}
    virtual void V023()
    {}
    virtual void V024()
    {}
    virtual void V025()
    {}
    virtual void V026()
    {}
    virtual void V027()
    {}
    virtual void V028()
    {}
    virtual void V029()
    {}
    virtual void V030()
    {}
    virtual void V031()
    {}
    virtual void V032()
    {}
    virtual void V033()
    {}
    virtual void V034()
    {}
    virtual void V035()
    {}
    virtual void V036()
    {}
    virtual void V037()
    {}
    virtual void V038()
    {}
    virtual void V039()
    {}
    virtual void V040()
    {}
    virtual void V041()
    {}
    virtual void V042()
    {}
    virtual void V043()
    {}
    virtual void V044()
    {}
    virtual void V045()
    {}
    virtual void V046()
    {}
    virtual void V047()
    {}
    virtual void V048()
    {}
    virtual void V049()
    {}
    virtual void V050()
    {}
    virtual void V051()
    {}
    virtual void V052()
    {}
    virtual void V053()
    {}
    virtual void V054()
    {}
    virtual void V055()
    {}
    virtual void V056()
    {}
    virtual void V057()
    {}
    virtual void V058()
    {}
    virtual void V059()
    {}
    virtual void V060()
    {}
    virtual void V061()
    {}
    virtual void V062()
    {}
    virtual void V063()
    {}
    virtual void V064()
    {}
    virtual void V065()
    {}
    virtual void V066()
    {}
    virtual void V067()
    {}
    virtual void V068()
    {}
    virtual void V069()
    {}
    virtual void V070()
    {}
    virtual void V071()
    {}
    virtual void V072()
    {}
    virtual void V073()
    {}
    virtual void V074()
    {}
    virtual void V075()
    {}
    virtual const char* GetName()
    {
        return 0;
    }
};

struct TESSaveLoadGame
{
};

struct SaveManager : public TESSaveLoadGame
{
};

struct Interface
{
};

SaveManager* DAT_011de45c;
GlobalObject_0045cf30 g_011de4e8;


struct FUN_009ed5f0_shell : public Saver
{
    unsigned short FUN_009ed5f0();
};

// @fnv 0x009ed5f0
unsigned short FUN_009ed5f0_shell::FUN_009ed5f0()
{
    unsigned short usSaveSize = 0;
    unsigned short usOldSize;

    usSaveSize += reinterpret_cast<::FUN_00678fd0_shell *>(this)->FUN_00678fd0();
    usOldSize = usSaveSize;

    if (reinterpret_cast<::FUN_00862110_cls *>((DAT_011de45c))->FUN_00862110())
    {
        usSaveSize += 4;
        usSaveSize += 2;
    }

    usSaveSize += 0xC;

    if (*g_011de4e8.Bool())
    {
        TESSound* m_pContactSound = reinterpret_cast<::EffectSetting *>((DAT_011de45c))->GetHitSound();
        if (m_pContactSound)
        {
            TESForm* pForm = ::FUN_004839c0(m_pContactSound->formID);
            ::FUN_0040fbe0(
                );
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }

    return usSaveSize;
}

struct Member80_9ed030
{
    Member80_9ed030();
};

struct Base_9ed030
{
    virtual void v00();
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
    Base_9ed030();
    ~Base_9ed030();
};

struct FUN_009ed030 : Base_9ed030
{
    Member80_9ed030 m_80;

    FUN_009ed030();
    virtual void v00();
};

// Initializes the object by constructing its base and member subobjects; the body itself is empty.
// @fnv 0x009ed030
FUN_009ed030::FUN_009ed030()
{}

struct HeaderProxy
{
    unsigned int id;
    unsigned char unk04, unk05, unk06, unk07, unk08;
};
struct SaveProxy
{
};
struct OwnerProxy
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
    void SaveBackupPackage();
};
// @fnv 0x009ed700
void OwnerProxy::SaveBackupPackage()
{
    reinterpret_cast<::Package679120 *>(this)->SavePackage();
    unsigned short a = 0;
    unsigned short* p = 0;
    char* i = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveProxy*)DAT_011de45c)))->FUN_00825c00()));
    if (*g_011de4e8.Bool())
        i = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveProxy*)DAT_011de45c)))->FUN_00825c00()));
    if (reinterpret_cast<::FUN_00862110_cls *>((((SaveProxy*)DAT_011de45c)))->FUN_00862110())
    {
        unsigned int tag = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>((((SaveProxy*)DAT_011de45c)))->FUN_008579b0(&tag, 4);
        p = (unsigned short*)((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveProxy*)DAT_011de45c)))->FUN_00825c00()));
        reinterpret_cast<::FUN_008579b0_shell *>((((SaveProxy*)DAT_011de45c)))->FUN_008579b0(&a, 2);
    }
    unsigned short s = 0;
    char* h = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveProxy*)DAT_011de45c)))->FUN_00825c00()));
    reinterpret_cast<::FUN_008579b0_shell *>((((SaveProxy*)DAT_011de45c)))->FUN_008579b0(&s, 2);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>(this)->FUN_00484ce0(&unk80, 12);
    if (*g_011de4e8.Bool())
    {
        char* header = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveProxy*)DAT_011de45c)))->FUN_00825c00()));
        HeaderProxy* end = ((::HeaderProxy *)(reinterpret_cast<::EffectSetting *>((((SaveProxy*)DAT_011de45c)))->GetHitSound()));
        if (end)
        {
            TESForm* form = ::FUN_004839c0(end->id);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>((((SaveProxy*)DAT_011de45c)))->FUN_00862110())
    {
        char* finalend = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((SaveProxy*)DAT_011de45c)))->FUN_00825c00()));
        char* saved = (char*)p;
        if (finalend > saved + 65535)
            ::FUN_005b5e40();
        *p = (unsigned short)(finalend - saved);
    }
}

struct Actor897;
struct PackageLocation897
{
    int kind;
    int radius;
    Actor897* reference;
    PackageLocation897();
    ~PackageLocation897();
};
struct PackageTargetObj
{
    int kind;
    int count;
    void* target;
    int flags;
    PackageTargetObj();
    ~PackageTargetObj();
};
struct PackageData897
{
};
struct Package897 : TESPackage
{
};
struct Process897
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void* GetPackageContext();
};
struct ActorBase897
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
    SaveProxy data;
};
struct Actor897 : TESForm
{
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void StartPackage(Package897*, int, int);
    void FUN_00897bd0(void*);
};
// Builds a package with location and target data, applies it to the actor's process context, then starts it on the actor.
// @fnv 0x00897bd0
void Actor897::FUN_00897bd0(void* unused)
{
    Package897* value = ((::Package897 *)(::CreatePackageByType(14)));
    reinterpret_cast<::PackageEx *>((value))->SetPackageType(14);
    reinterpret_cast<::TESPackage *>((value))->SetMustReachLocation(false);
    reinterpret_cast<::TESPackage *>((value))->SetMustComplete(false);
    PackageLocation897* location = new PackageLocation897;
    reinterpret_cast<::LocationDescriptor *>((location))->FUN_0067f3c0((::TESObjectREFR *)(::Actor897 *)(this));
    reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((value))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(location));
    delete location;
    PackageTargetObj* target = new PackageTargetObj;
    reinterpret_cast<::FUN_00672fc0_shell *>((value))->FUN_00672fc0((::PackageTargetRecord *)(target));
    reinterpret_cast<::TESPackage *>((value))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(41));
    reinterpret_cast<::PackageTargetRecord *>((((::PackageData897 *)(reinterpret_cast<::Script *>((value))->GetData()))))->SetTargetKind({});
    reinterpret_cast<::PackageTargetRecord *>((((::PackageData897 *)(reinterpret_cast<::Script *>((value))->GetData()))))->SetTargetObjectReference({});
    void* contextTmp = ((::Process897 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->GetPackageContext();
    if (contextTmp)
        reinterpret_cast<::fnv_0067a1b0::FUN_0067a1b0_shell *>((value))->FUN_0067a1b0((::TESPackage *)(contextTmp));
    reinterpret_cast<::TESRegionGrassObject *>((((::PackageData897 *)(reinterpret_cast<::Script *>((value))->GetData(reinterpret_cast<::Actor *>(this)->GetActorBase()->data))->FUN_00825c00())))))->AssignLandTexture({});
    delete target;
    ((::Process897 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->V010();
    StartPackage(value, 1, 1);
}

struct LoadHeader
{
    unsigned int formID;
    unsigned char version;
    unsigned char flags0, flags1, flags2, flags3;
    unsigned char type;
};
struct PackageReader : OwnerProxy
{
    void LoadPackageBlock();
};
struct LoadManager
{
};
// Reads a 4-byte block marker and a 2-byte size, then reports block header, overrun and underrun errors against the loaded buffer.
// @fnv 0x009ed8d0
void PackageReader::LoadPackageBlock()
{
    reinterpret_cast<::fnv_00679340::Package679 *>(this)->FUN_00679340();
    unsigned short usBlockSize = 0;
    char* pBlockStart = 0;
    if (reinterpret_cast<::FUN_00862110_cls *>((((LoadManager*)DAT_011de45c)))->FUN_00862110())
    {
        unsigned int uiBlockMarker;
        reinterpret_cast<::FUN_008579e0_shell *>((((LoadManager*)DAT_011de45c)))->FUN_008579e0(&uiBlockMarker, 4);
        if (uiBlockMarker != 0x424c4f4b)
        {
            LoadHeader* header = ((::LoadHeader *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((LoadManager*)DAT_011de45c)))));
            if (header)
            {
                TESForm* form = ::FUN_004839c0(header->formID);
                ::FUN_005b5e40(
                    );
            }
            else
            {
                ::FUN_005b5e40(
                    );
            }
        }
        pBlockStart = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((LoadManager*)DAT_011de45c)))->FUN_00825c00()));
        reinterpret_cast<::FUN_008579e0_shell *>((((LoadManager*)DAT_011de45c)))->FUN_008579e0(&usBlockSize, 2);
    }
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>(this)->FUN_00484d00(&unk80, 12);
    if (reinterpret_cast<::FUN_00862110_cls *>((((LoadManager*)DAT_011de45c)))->FUN_00862110())
    {
        char* header = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((LoadManager*)DAT_011de45c)))->FUN_00825c00()));
        LoadHeader* pBlockHeader = ((::LoadHeader *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((LoadManager*)DAT_011de45c)))));
        if (pBlockHeader)
        {
            TESForm* form = ::FUN_004839c0(pBlockHeader->formID);
            if (header > pBlockStart + usBlockSize)
            {
                ::FUN_005b5e40(
                    );
            }
            else if (header < pBlockStart + usBlockSize)
            {
                ::FUN_005b5e40(
                    );
            }
        }
        else
        {
            if (header > pBlockStart + usBlockSize)
            {
                ::FUN_005b5e40(
                    );
            }
            else if (header < pBlockStart + usBlockSize)
            {
                ::FUN_005b5e40(
                    );
            }
        }
    }
}
