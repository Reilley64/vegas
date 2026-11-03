
// tesobjectcell_ctx2_variant.cpp: context variant of src/fallout_shared/tesobjectcell.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00544630_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00547440_Class.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00759d80_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/SwapBlock.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0041c390__ExtraDataList2.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0054def0__S.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/decl/fnv_0058f180__FUN_0058f180.h"
#include "fnv/decl/loader__List.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0041c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();

// ---- candidate ----
struct SL
{
    int item;
    SL* next;
};

class AnimGroup
{
  public:
};

class NiControllerSequence
{
  public:
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void v24(void* p);
};

class TESAnimGroup;
class BSAnimGroupSequence : public NiControllerSequence
{
public:
    ::TESAnimGroup *GetAnimGroup() const;
};

class Holder
{
  public:
    Holder(int, int);
    virtual ~Holder();
    char** GetFlag(unsigned int i);
    int m0, m1, m2;
};

struct Q1
{
    int v;
    int q0;
    int q1;
    int r0;
    int r1;
    int r2;
};
struct Q2
{
    const char* msg;
    int r0;
};
struct Q3
{
    int kind;
    int kind2;
    int r0;
};
struct Q4
{
    NiControllerSequence* ref;
    int r0;
    int r1;
    int r2;
    int r3;
    int r4;
};

extern void*(* DAT_00fdf28c)(int, int, int, void*);

class LockCtx
{
  public:
    char pad[0xc];
    int m_iThirdValue;
    void FUN_004d8b90(int arg1, NiControllerSequence* arg2);
};

// @fnv 0x004d8b90
void LockCtx::FUN_004d8b90(int arg1, NiControllerSequence* arg2)
{
    if (arg2)
    {
        Q1 k;
        Q2 ba;
        Q3 b;
        Q4 q;
        Holder* f = new Holder(0x80, 0x80);
        const char* s;
        k.q0 = 0xffff0002;
        k.q1 = 0x27;
        q.ref = arg2;
        s = 0;
        switch (((int)(reinterpret_cast<::LowProcess *>((arg2))->GetActiveCombatTarget())))
        {
        case 0:
            s = "INACTIVE";
            break;
        case 1:
            s = "ANIMATING";
            break;
        case 2:
            s = "EASEIN";
            break;
        case 3:
            s = "EASEOUT";
            break;
        case 4:
            s = "TRANSSOURCE";
            break;
        case 5:
            s = "TRANSDEST";
            break;
        case 6:
            s = "MORPHSOURCE";
            break;
        }
        BSAnimGroupSequence* cf = dynamic_cast<BSAnimGroupSequence*>(arg2);
        bool p;
        bool h;
        bool a;
        h = false;
        a = false;
        p = false;
        if (cf)
        {
            h = ((bool)(reinterpret_cast<::FUN_00759d80_Class *>((((::AnimGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((cf))->GetAnimGroup()))))->FUN_00759d80()));
            a = ((bool)(::GetMaxOfTwoBytes((unsigned char *)(((::AnimGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((cf))->GetAnimGroup()))))));
            p = ((bool)(::GetMaxByte((unsigned char *)(((::AnimGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((cf))->GetAnimGroup()))))));
        }
        char eb[0x100];
        if (h)
        {
            ::FUN_00406d00(eb, 0x100, "%s: %s, Count: %d, Blend: %0.2f", ((::SL *)(reinterpret_cast<::TESTopicInfoData *>((arg2))->GetLinkToList()))->item, s,
                      ((char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((arg2))->FUN_0084e3a0())), (double)h / 30.0);
        }
        else if (a || p)
        {
            ::FUN_00406d00(eb, 0x100, "%s: %s, Count: %d, BlendIn: %0.2f, BlendOut: %0.2f", ((::SL *)(reinterpret_cast<::TESTopicInfoData *>((arg2))->GetLinkToList()))->item,
                      s, ((char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((arg2))->FUN_0084e3a0())), (double)a / 30.0, (double)p / 30.0);
        }
        else
        {
            ::FUN_00406d00(eb, 0x100, "%s: %s, Count: %d", ((::SL *)(reinterpret_cast<::TESTopicInfoData *>((arg2))->GetLinkToList()))->item, s, ((char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((arg2))->FUN_0084e3a0())));
        }
        ba.msg = ((const char *)(::FUN_00464f30((int)(eb))));
        b.kind = 5;
        b.kind2 = b.kind;
        k.v = arg1;
        k.v = (int)DAT_00fdf28c(m_iThirdValue, 0x1100, 0, &k.v);
        arg1 = k.v;
        arg2->v24(f);
        unsigned int i;
        for (i = 0; i < reinterpret_cast<::FUN_00658930_class *>((f))->GetShortAtOffsetA(); i++)
        {
            ba.msg = ((const char *)(::FUN_00464f30((int)(*f->GetFlag(i)))));
            b.kind = 6;
            b.kind2 = b.kind;
            DAT_00fdf28c(m_iThirdValue, 0x1100, 0, &k.v);
        }
        ::FUN_005e03d0((::NiTArray_Layout *)(f));
        delete f;
    }
}

extern "C" void* __cdecl _alloca(unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct CellFile
{
    void ReadChunkInt(void*);
};
struct CellForm
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void LoadBound(CellFile*);
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void SetEditorId(char*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
};
struct CellFullName
{
    virtual void Slot0();
    unsigned int stringData, stringLength;
};
struct FUN_0058efd0
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    FUN_0058efd0();
};
struct CellExtra
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct CellString
{
    unsigned int data, size;
};
struct CellExterior
{
};
struct CellInterior
{
};
struct CellEnvironment
{
};
struct CellLoader : CellForm, CellFullName
{
    unsigned char flags;
    unsigned char unk25, unk26, unk27;
    CellExtra extra;
    unsigned int unk48, unk4c, waterHeight, unk54;
    CellString name;
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
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int lightingTemplate, lightingInheritance;
    bool FUN_005422d0(CellFile* file);
};
// @fnv 0x005422d0
bool CellLoader::FUN_005422d0(CellFile* file)
{
    unsigned char formTypeSlot15 = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formTypeSlot15 != 0x39)
        return false;
    void* savedSourceSlot15 = 0;
    if (reinterpret_cast<::TESFile *>((file))->IsMasterFile())
        savedSourceSlot15 = ((void *)(reinterpret_cast<::TESFile *>((file))->GetOffset()));
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    do
    {
        int chunk = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0();
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* editorId = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorId), 512);
            SetEditorId(editorId);
            break;
        }
        case 0x444e424f:  // OBND
        {
            LoadBound(file);
            break;
        }
        case 0x4c4c5546:  // FULL
        {
            ::ReadFullName((::TESFullName *)(::CellFullName *)(static_cast<CellFullName*>(this)), (::TESFile *)(file));
            break;
        }
        case 0x41505058:  // XPPA
        case 0x42475258:  // XRGB
        case 0x424c4758:  // XGLB
        case 0x424d4c58:  // XLMB
        case 0x434d4158:  // XAMC
        case 0x434f4c58:  // XLOC
        case 0x43524d58:  // XMRC
        case 0x44415258:  // XRAD
        case 0x44455358:  // XSED
        case 0x44475258:  // XRGD
        case 0x444f4c58:  // XLOD
        case 0x444f5058:  // XPOD
        case 0x44504158:  // XAPD
        case 0x44524f58:  // XORD
        case 0x44525058:  // XPRD
        case 0x44525358:  // XSRD
        case 0x45535558:  // XUSE
        case 0x46525358:  // XSRF
        case 0x47484358:  // XCHG
        case 0x47525458:  // XTRG
        case 0x49435058:  // XPCI
        case 0x494d4558:  // XEMI
        case 0x49525458:  // XTRI
        case 0x4b4e5258:  // XRNK
        case 0x4b524d41:  // AMRK
        case 0x4b524d4d:  // MMRK
        case 0x4b524d58:  // XMRK
        case 0x4c444558:  // XEDL
        case 0x4c455458:  // XTEL
        case 0x4c4f5358:  // XSOL
        case 0x4c535058:  // XPSL
        case 0x4c545058:  // XPTL
        case 0x4d414e52:  // RNAM
        case 0x4d434358:  // XCCM
        case 0x4d434c58:  // XLCM
        case 0x4d494358:  // XCIM
        case 0x4d495458:  // XTIM
        case 0x4d4c4358:  // XCLM
        case 0x4d525058:  // XPRM
        case 0x4d545258:  // XRTM
        case 0x4e535058:  // XPSN
        case 0x4e574f58:  // XOWN
        case 0x4e5a4558:  // XEZN
        case 0x4f424d58:  // XMBO
        case 0x4f445258:  // XRDO
        case 0x4f4d4358:  // XCMO
        case 0x4f4f5258:  // XROO
        case 0x4f544158:  // XATO
        case 0x50424d58:  // XMBP
        case 0x50434f58:  // XOCP
        case 0x50444e58:  // XNDP
        case 0x504c4358:  // XCLP
        case 0x504c4858:  // XHLP
        case 0x50534558:  // XESP
        case 0x50564e58:  // XNVP
        case 0x52424d58:  // XMBR
        case 0x52434158:  // XACR
        case 0x52434458:  // XDCR
        case 0x524b4c58:  // XLKR
        case 0x524c4358:  // XCLR
        case 0x524d5258:  // XRMR
        case 0x52504158:  // XAPR
        case 0x52575058:  // XPWR
        case 0x53414358:  // XCAS
        case 0x53424958:  // XIBS
        case 0x53445258:  // XRDS
        case 0x53524858:  // XHRS
        case 0x54434158:  // XACT
        case 0x54454358:  // XCET
        case 0x544c4858:  // XHLT
        case 0x544c5758:  // XWLT
        case 0x544d4158:  // XAMT
        case 0x544d4358:  // XCMT
        case 0x544e4358:  // XCNT
        case 0x54574358:  // XCWT
        case 0x57544c58:  // XLTW
        {
            reinterpret_cast<::loader::List *>(&(extra))->LoadExtraData((::loader::File *)(file), this);
            break;
        }
        case 0x574c4358:  // XCLW
        {
            file->ReadChunkInt(&waterHeight);
            break;
        }
        case 0x46504d49:  // IMPF
        case 0x53504d49:  // IMPS
        {
            ::FUN_0058efd0* imageSpace = ((::FUN_0058efd0 *)(::FUN_0041c460((::BaseExtraList *)(((::CellExtra *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))));
            if (!imageSpace)
            {
                imageSpace = new ::FUN_0058efd0;
                reinterpret_cast<::fnv_0041c390::ExtraDataList2 *>((((::CellExtra *)(reinterpret_cast<::FUN_004610d0_shell *>(this)->GetExtraDataList()))))->FUN_0041c390(imageSpace);
            }
            reinterpret_cast<::fnv_0058f180::FUN_0058f180 *>((imageSpace))->Load((::TESFile *)(file));
            break;
        }
        case 0x504d544c:  // LTMP
        {
            unsigned int templateId = 0;
            file->ReadChunkInt(&templateId);
            lightingTemplate = templateId;
            break;
        }
        case 0x4d414e58:  // XNAM
        {
            unsigned int textSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            if (textSize)
            {
                char* text = (char*)_alloca(textSize);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(text), textSize);
                reinterpret_cast<::TESFullName *>(&(name))->SetFullName(text);
            }
            break;
        }
        case 0x4d414e4c:  // LNAM
        {
            file->ReadChunkInt(&lightingInheritance);
            break;
        }
        case 0x41544144:  // DATA
        {
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 4)
            {
                unsigned int oldFlags = 0;
                file->ReadChunkInt(&oldFlags);
                flags = (unsigned char)oldFlags;
            }
            else
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&flags), 1);
            if (!(flags & 1))
                flags |= 2;
            if ((flags & 1) && (flags & 0x80))
                reinterpret_cast<::FUN_00547440_Class *>(this)->FUN_00547440(DAT_01016970);
            if (!((bool)(reinterpret_cast<::TESObjectCELL *>(((*reinterpret_cast<::CellEnvironment * *>(&::g_dataHandler))))->FUN_00542d20())))
                flags &= ~0x40;
            reinterpret_cast<::FUN_00544630_shell *>(this)->ResetCellData();
            if (reinterpret_cast<::TESObjectCELL *>(this)->IsCellInterior() && savedSourceSlot15)
                reinterpret_cast<::fnv_0054def0::S *>(this)->SetInteriorDataValue((int)(savedSourceSlot15));
            break;
        }
        case 0x434c4358:  // XCLC
        {
            CellExterior* exterior = ((::CellExterior *)(reinterpret_cast<::FUN_005445d0_shell *>(this)->FUN_005445d0()));
            if (exterior)
            {
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired() && reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() != 12)
                    reinterpret_cast<::S_00462230 *>((exterior))->FUN_00462230();
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(exterior), 12);
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                    reinterpret_cast<::S_00462230 *>((exterior))->FUN_00462230();
            }
            break;
        }
        case 0x4c4c4358:  // XCLL
        {
            CellInterior* interior = ((::CellInterior *)(reinterpret_cast<::FUN_00544600_shell *>(this)->FUN_00544600()));
            if (interior)
            {
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired() && reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() != 44)
                    reinterpret_cast<::SwapBlock *>((interior))->SwapBytes();
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(interior), 44);
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                    reinterpret_cast<::SwapBlock *>((interior))->SwapBytes();
            }
            break;
        }
        }
    } while (reinterpret_cast<::TESFile *>((file))->NextChunk());
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(false);
    return true;
}
