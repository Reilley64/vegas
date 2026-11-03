
// shadowscenenode_od_variant_ctxr_variant.cpp: rename variant for 0x006056f0 (integration 2026-10-30): the unit's skeleton with strncmp renamed, whose names are bound elsewhere.
// src/bsshader/shadowscenenode_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/shadowscenenode.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CamLook.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_00503650_shell.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00602130_shell.h"
#include "fnv/decl/FUN_00613970_shell.h"
#include "fnv/decl/FUN_00613b20_shell.h"
#include "fnv/decl/FUN_00733fd0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00b9bc50_t.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/MultiBoundOwner.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/S00b5d9f0_Owner.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/TESNPC.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_Cam_00712e60.h"
#include "fnv/decl/fnv_006044e0__FUN_006044e0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00655000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_0104a000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01203000.h"
#include "shadowscenenode_local.h"
struct FUN_00c5b5a0_cls
{
    int FUN_00c5b5a0(int idx);
};
extern "C" char DAT_01070c70;
struct Rect2180
{
    float x[4];
    Rect2180(float, float, float, float);
};
struct Frustum2180
{
    float left, right, top, bottom, nearz, farz;
    bool ortho;
    Frustum2180(bool);
};
struct Point2180
{
    float x, y, z;
    Point2180(float, float, float);
};
struct Update2180
{
    int data[3];
};
struct String2180
{
    int value;
    String2180(const char*);
    ~String2180();
};
struct Setting2180
{
};
struct Provider2180
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual float get();
};
struct FUN_00a712f0
{
    int bytes[0x114 / 4];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_00a712f0();
};
struct Target2180
{
    FUN_00a712f0* FUN_007c2180();
};
extern "C" int __cdecl strncmp_r006056f0(const char*, const char*, unsigned int);

struct UpdateObject;
struct UpdateList
{
    unsigned vtable;
    unsigned buffer;
    unsigned size;
    unsigned capacity;
};
struct LocalNodePtr
{
    UpdateObject* root;
    LocalNodePtr(UpdateObject*);
    ~LocalNodePtr();
};
struct NodeRecord
{
    unsigned first;
    unsigned second;
    unsigned third;
    unsigned fourth;
    unsigned fifth;
    unsigned sixth;
    unsigned seventh;
    unsigned eighth;
};
struct UpdatePacket
{
    NodeRecord records[4];
    unsigned identity;
    unsigned region;
    float weight;
    unsigned flags;
    unsigned sex;
    UpdateList primary;
    UpdateList secondary;
    UpdateList names;
    UpdateList nodes;
    bool enabled;
    bool dirty;
    unsigned short unknownD6;
    unsigned unknownD8;
    unsigned unknownDC;
    unsigned unknownE0;
    unsigned tailE4;
    unsigned tailE8;
    UpdatePacket();
    ~UpdatePacket();
};
struct UpdateObject
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual UpdateObject* GetList();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual UpdateObject* GetNode();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual bool IsReady();
    virtual void SetReady(bool);
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual UpdateObject* GetRenderNode(int);
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual UpdateObject* GetRoot();
    const char* FUN_0043b1b0();
    bool FUN_008256d0();
};
struct NodePointer
{
    UpdateObject* root;
    NodePointer& FUN_0066b0d0(UpdateObject*);
};
struct RefList
{
    UpdateObject* item;
    RefList* next;
};
struct UpdateOwner
{
    unsigned unknown000;
    unsigned unknown004;
    unsigned unknown008;
    unsigned unknown00C;
    unsigned unknown010;
    unsigned unknown014;
    unsigned unknown018;
    unsigned unknown01C;
    unsigned unknown020;
    unsigned unknown024;
    unsigned unknown028;
    unsigned unknown02C;
    unsigned unknown030;
    unsigned unknown034;
    unsigned unknown038;
    unsigned unknown03C;
    unsigned unknown040;
    unsigned unknown044;
    unsigned unknown048;
    unsigned unknown04C;
    unsigned unknown050;
    unsigned unknown054;
    unsigned unknown058;
    unsigned unknown05C;
    unsigned unknown060;
    unsigned unknown064;
    unsigned unknown068;
    unsigned unknown06C;
    unsigned unknown070;
    unsigned unknown074;
    unsigned unknown078;
    unsigned unknown07C;
    unsigned unknown080;
    unsigned unknown084;
    unsigned unknown088;
    unsigned unknown08C;
    unsigned unknown090;
    unsigned unknown094;
    unsigned unknown098;
    unsigned unknown09C;
    unsigned unknown0A0;
    unsigned unknown0A4;
    unsigned unknown0A8;
    unsigned unknown0AC;
    unsigned unknown0B0;
    unsigned unknown0B4;
    unsigned unknown0B8;
    unsigned unknown0BC;
    unsigned unknown0C0;
    unsigned unknown0C4;
    unsigned unknown0C8;
    unsigned unknown0CC;
    unsigned unknown0D0;
    unsigned unknown0D4;
    unsigned unknown0D8;
    unsigned unknown0DC;
    unsigned unknown0E0;
    unsigned unknown0E4;
    unsigned unknown0E8;
    unsigned unknown0EC;
    unsigned unknown0F0;
    unsigned unknown0F4;
    unsigned unknown0F8;
    unsigned unknown0FC;
    unsigned unknown100;
    unsigned unknown104;
    unsigned unknown108;
    RefList references;
    unsigned unknown114;
    unsigned unknown118;
    unsigned unknown11C;
    unsigned unknown120;
    unsigned unknown124;
    unsigned unknown128;
    unsigned unknown12C;
    unsigned unknown130;
    unsigned unknown134;
    unsigned unknown138;
    unsigned unknown13C;
    unsigned unknown140;
    unsigned unknown144;
    unsigned unknown148;
    unsigned unknown14C;
    unsigned unknown150;
    unsigned unknown154;
    unsigned unknown158;
    unsigned unknown15C;
    unsigned unknown160;
    unsigned unknown164;
    unsigned unknown168;
    unsigned unknown16C;
    unsigned unknown170;
    unsigned unknown174;
    unsigned unknown178;
    unsigned unknown17C;
    unsigned unknown180;
    unsigned unknown184;
    unsigned unknown188;
    unsigned unknown18C;
    unsigned unknown190;
    unsigned unknown194;
    unsigned unknown198;
    unsigned unknown19C;
    unsigned unknown1A0;
    unsigned unknown1A4;
    unsigned unknown1A8;
    unsigned unknown1AC;
    unsigned unknown1B0;
    unsigned unknown1B4;
    unsigned unknown1B8;
    unsigned unknown1BC;
    unsigned unknown1C0;
    NodePointer previous;
    NodePointer current;
    unsigned FUN_005f0cc0();
    void FUN_00603ad0(UpdatePacket&);
    void FUN_006056f0(UpdateObject* object);
};
extern unsigned DAT_0101f5f8;
extern "C" int __cdecl strncmp_r006056f0(const char*, const char*, unsigned);
// @fnv 0x006056f0
void UpdateOwner::FUN_006056f0(UpdateObject* object)
{
    if (!object || !::IsSettingEnabled())
        return;
    UpdateObject* rootNode = object->GetRoot();
    unsigned entry = 0;
    UpdateObject* currentNode = ((::UpdateObject *)(::FUN_00559450((int *)&(current.FUN_0066b0d0(object->GetRenderNode(0))))));
    UpdateObject* found = ((::UpdateObject *)(::FUN_004aae30((::NiAVObject *)(rootNode), (::NiFixedString *)(::FUN_00605d40(0)))));
    UpdateObject* node = found ? found->GetNode() : 0;
    if (!node || !currentNode)
        return;
    UpdateObject* nested;
    UpdateObject* list;
    UpdateObject* root;
    unsigned count;
    UpdateObject* key;
    if (!currentNode->IsReady())
    {
        found = ((::UpdateObject *)(::FUN_004aae30((::NiAVObject *)(rootNode), (::NiFixedString *)(&DAT_0101f5f8))));
        if (found)
        {
            nested = found->GetList();
            if (nested)
            {
                found = ((::UpdateObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((nested))->FUN_0045bc00(0)));
                if (found)
                {
                    list = found->GetList();
                    if (list)
                    {
                        entry = ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((list))->FUN_00453470()));
                        for (unsigned i = 0; i < entry; i++)
                        {
                            found = ((::UpdateObject *)(reinterpret_cast<::NiNode *>((list))->GetAt(i)));
                            root = found ? found->GetNode() : 0;
                            if (root)
                            {
                                count = ((unsigned int)(reinterpret_cast<::FUN_00a59d30_C *>((root))->FUN_00a59d30(2)));
                                key = ((::UpdateObject *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<unsigned int *>(&::g_011f4a5c))), (::NiObject *)(count))));
                                if (key && !strncmp_r006056f0(((::UpdateObject *)(reinterpret_cast<::TESTopicInfoData *>((key))->GetLinkToList()))->FUN_0043b1b0(), &(*reinterpret_cast<char *>((void *)&::g_011d348c_arg1)), 4))
                                {
                                    if (::MatchGeometryVertices((::Geometry *)(root), (::Geometry *)(node), ::fnv_00c88020::DAT_01016248, true, 0))
                                    {
                                        currentNode->SetReady(true);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    entry = ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((nested))->FUN_00453470()));
                    for (unsigned j = 0; j < entry; j++)
                    {
                        found = ((::UpdateObject *)(reinterpret_cast<::NiNode *>((nested))->GetAt(j)));
                        root = found ? found->GetNode() : 0;
                        if (root)
                        {
                            count = ((unsigned int)(reinterpret_cast<::FUN_00a59d30_C *>((root))->FUN_00a59d30(2)));
                            key = ((::UpdateObject *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<unsigned int *>(&::g_011f4a5c))), (::NiObject *)(count))));
                            if (key && !strncmp_r006056f0(((::UpdateObject *)(reinterpret_cast<::TESTopicInfoData *>((key))->GetLinkToList()))->FUN_0043b1b0(), &(*reinterpret_cast<char *>((void *)&::g_011d348c_arg1)), 4))
                            {
                                if (::MatchGeometryVertices((::Geometry *)(root), (::Geometry *)(node), ::fnv_00c88020::DAT_01016248, true, 0))
                                {
                                    currentNode->SetReady(true);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (((::UpdateObject *)(reinterpret_cast<::Callees *>(&(references))->FUN_00726070())))
    {
        UpdatePacket packet;
        packet.identity = ((unsigned int)(reinterpret_cast<::TESNPC *>(this)->GetHair()));
        packet.weight = reinterpret_cast<::FUN_00602130_shell *>(this)->FUN_00602130();
        packet.flags = ((unsigned int)(reinterpret_cast<::MiddleHighProcess *>(this)->GetAnimation()));
        packet.sex = FUN_005f0cc0();
        packet.region = reinterpret_cast<::FUN_004169d0_shell *>(this)->FUN_004169d0();
        FUN_00603ad0(packet);
        if (!packet.flags && ((::UpdateObject *)(reinterpret_cast<::FUN_00503650_shell *>((((::UpdateObject *)(reinterpret_cast<::Callees *>(&(references))->FUN_00726070()))))->FUN_00503650())) &&
            !((::UpdateObject *)(reinterpret_cast<::FUN_00503650_shell *>((((::UpdateObject *)(reinterpret_cast<::Callees *>(&(references))->FUN_00726070()))))->FUN_00503650()))->FUN_008256d0())
            packet.flags = *((unsigned int *)(new ((void *)(((::UpdateObject *)(reinterpret_cast<::FUN_00503650_shell *>((((::UpdateObject *)(reinterpret_cast<::Callees *>(&(references))->FUN_00726070()))))->FUN_00503650())))) ::Vec3()));
        for (unsigned k = 0; k < 8; k++)
        {
            reinterpret_cast<::S_0060ba10 *>(&(packet.primary))->FUN_0096a610((int)&(const unsigned int &)(((unsigned int)(reinterpret_cast<::FUN_00613970_shell *>((((::UpdateObject *)(reinterpret_cast<::Callees *>(&(references))->FUN_00726070()))))->FUN_00613970(FUN_005f0cc0(), k)))));
            reinterpret_cast<::S_0060ba10 *>(&(packet.secondary))->FUN_0096a610((int)&(const unsigned int &)(((unsigned int)(reinterpret_cast<::FUN_00613b20_shell *>((((::UpdateObject *)(reinterpret_cast<::Callees *>(&(references))->FUN_00726070()))))->GetBodyPartTexture(FUN_005f0cc0(), k)))));
            reinterpret_cast<::Callees *>(&(references))->FUN_00726070();
            reinterpret_cast<::S_0060ba10 *>(&(packet.names))->FUN_0096a610((int)&(const unsigned int &)((unsigned)::FUN_00605d40(k)));
            reinterpret_cast<::Callees *>(&(references))->FUN_00726070();
            if (((bool)(::FUN_00605d50())))
            {
                LocalNodePtr ptr(0);
                reinterpret_cast<::fnv_006044e0::FUN_006044e0_shell *>(this)->CreatePartTexture(k, (void *)&(ptr));
                reinterpret_cast<::S_0060ba10 *>(&(packet.nodes))->FUN_0060ba10((int)&(ptr));
            }
        }
        reinterpret_cast<::Callees *>(&(references))->FUN_00726070();
        packet.enabled = ((bool)(::FUN_00605d50()));
        ::fnv_00655fa0::ApplyFaceGenTextures((::fnv_00655fa0::NiAVObject *)(::UpdateObject *)(((::UpdateObject *)(::FUN_00559450((int *)&(previous))))), (::fnv_00655fa0::FaceGenData *)&(packet));
        ::fnv_00655fa0::ApplyFaceGenTextures((::fnv_00655fa0::NiAVObject *)(::UpdateObject *)(((::UpdateObject *)(::FUN_00559450((int *)&(current))))), (::fnv_00655fa0::FaceGenData *)&(packet));
    }
}
