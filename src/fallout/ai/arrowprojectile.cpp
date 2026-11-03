// src/fallout/ai/arrowprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/arrowprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_0085f810_shell.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/FUN_008d0240_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/fnv_005de0f0__FUN_005de0f0_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/symbols_011e0000.h"
#include <xmmintrin.h>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00632c30_Class.h"
#include "fnv/decl/FUN_00632c60_Class.h"
#include "fnv/decl/FUN_008cd6a0_Class.h"
#include "fnv/decl/FUN_00c7f690_cls.h"
#include "fnv/decl/Holder_cffa0.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S632.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/bhkFilter.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_0056d000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_008cf000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
class MobileObject
{
  public:
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
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
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
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
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
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31(int a);
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual bool Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73(int a, int b);
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual void Unk_7D();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual bool Unk_89();
};

class Projectile : public MobileObject
{
  public:
};

class ArrowProjectile : public Projectile
{
};

struct ProjectileNode;
bool FUN_008256d0(ProjectileNode* node);

struct ProjectileNode
{
};

class ActorPackageContext;
class BaseProcess
{
  public:
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
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
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
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
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
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual void Unk_7D();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual void Unk_8B();
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual void Unk_99();
    virtual void Unk_9A();
    virtual void Unk_9B();
    virtual void Unk_9C();
    virtual void Unk_9D();
    virtual void Unk_9E();
    virtual void Unk_9F();
    virtual void Unk_A0();
    virtual void Unk_A1();
    virtual void Unk_A2();
    virtual void Unk_A3();
    virtual void Unk_A4();
    virtual void Unk_A5();
    virtual void Unk_A6();
    virtual void Unk_A7();
    virtual void Unk_A8();
    virtual void Unk_A9();
    virtual void Unk_AA();
    virtual void Unk_AB();
    virtual void Unk_AC();
    virtual void Unk_AD();
    virtual void Unk_AE();
    virtual void Unk_AF();
    virtual void Unk_B0();
    virtual void Unk_B1();
    virtual void Unk_B2();
    virtual void Unk_B3();
    virtual void Unk_B4();
    virtual void Unk_B5();
    virtual void Unk_B6();
    virtual void Unk_B7();
    virtual void Unk_B8();
    virtual void Unk_B9();
    virtual void Unk_BA();
    virtual void Unk_BB();
    virtual void Unk_BC();
    virtual void Unk_BD();
    virtual void Unk_BE();
    virtual void Unk_BF();
    virtual void Unk_C0();
    virtual void Unk_C1();
    virtual void Unk_C2();
    virtual void Unk_C3();
    virtual void Unk_C4();
    virtual void Unk_C5();
    virtual void Unk_C6();
    virtual void Unk_C7();
    virtual void Unk_C8();
    virtual void Unk_C9();
    virtual void Unk_CA();
    virtual void Unk_CB();
    virtual void Unk_CC();
    virtual void Unk_CD();
    virtual void Unk_CE();
    virtual void Unk_CF();
    virtual void Unk_D0();
    virtual void Unk_D1();
    virtual void Unk_D2();
    virtual void Unk_D3();
    virtual void Unk_D4();
    virtual void Unk_D5();
    virtual void Unk_D6();
    virtual void Unk_D7();
    virtual void Unk_D8();
    virtual void Unk_D9();
    virtual void Unk_DA();
    virtual void Unk_DB();
    virtual void Unk_DC();
    virtual void Unk_DD();
    virtual void Unk_DE();
    virtual void Unk_DF();
    virtual void Unk_E0();
    virtual void Unk_E1();
    virtual void Unk_E2();
    virtual void Unk_E3();
    virtual void Unk_E4();
    virtual void Unk_E5();
    virtual void Unk_E6();
    virtual void Unk_E7();
    virtual void Unk_E8();
    virtual void Unk_E9();
    virtual void Unk_EA();
    virtual void Unk_EB();
    virtual void Unk_EC();
    virtual void Unk_ED();
    virtual void Unk_EE();
    virtual void Unk_EF();
    virtual void Unk_F0();
    virtual void Unk_F1();
    virtual void Unk_F2();
    virtual void Unk_F3();
    virtual void Unk_F4();
    virtual void Unk_F5();
    virtual void Unk_F6();
    virtual void Unk_F7();
    virtual void Unk_F8();
    virtual void Unk_F9();
    virtual void Unk_FA();
    virtual void Unk_FB();
    virtual void Unk_FC();
    virtual void Unk_FD();
    virtual void Unk_FE();
    virtual void Unk_FF();
    virtual void Unk_100();
    virtual void Unk_101();
    virtual void Unk_102();
    virtual void Unk_103();
    virtual void Unk_104();
    virtual void Unk_105();
    virtual void Unk_106();
    virtual void Unk_107();
    virtual void Unk_108();
    virtual void Unk_109();
    virtual void Unk_10A();
    virtual void Unk_10B();
    virtual void Unk_10C();
    virtual void Unk_10D();
    virtual void Unk_10E();
    virtual void Unk_10F();
    virtual void Unk_110();
    virtual void Unk_111();
    virtual void Unk_112();
    virtual void Unk_113();
    virtual void Unk_114();
    virtual void Unk_115();
    virtual void Unk_116();
    virtual void Unk_117();
    virtual void Unk_118();
    virtual void Unk_119();
    virtual void Unk_11A();
    virtual void Unk_11B();
    virtual void Unk_11C();
    virtual void Unk_11D();
    virtual void Unk_11E();
    virtual void Unk_11F();
    virtual void Unk_120();
    virtual void Unk_121();
    virtual void Unk_122();
    virtual void Unk_123();
    virtual void Unk_124();
    virtual void Unk_125();
    virtual void Unk_126();
    virtual void Unk_127();
    virtual void Unk_128();
    virtual void Unk_129();
    virtual void Unk_12A();
    virtual void Unk_12B();
    virtual void Unk_12C();
    virtual void Unk_12D();
    virtual void Unk_12E();
    virtual void Unk_12F();
    virtual void Unk_130();
    virtual void Unk_131();
    virtual void Unk_132();
    virtual void Unk_133();
    virtual void Unk_134();
    virtual void Unk_135();
    virtual void Unk_136();
    virtual void Unk_137();
    virtual void Unk_138();
    virtual void Unk_139();
    virtual void Unk_13A();
    virtual void Unk_13B();
    virtual void Unk_13C();
    virtual void Unk_13D();
    virtual void Unk_13E();
    virtual void Unk_13F();
    virtual void Unk_140();
    virtual void Unk_141();
    virtual void Unk_142();
    virtual void Unk_143();
    virtual void Unk_144();
    virtual void Unk_145();
    virtual void Unk_146();
    virtual void Unk_147();
    virtual void Unk_148();
    virtual void Unk_149();
    virtual void Unk_14A();
    virtual void Unk_14B();
    virtual void Unk_14C();
    virtual void Unk_14D();
    virtual void Unk_14E();
    virtual void Unk_14F();
    virtual void Unk_150();
    virtual void Unk_151();
    virtual void Unk_152();
    virtual void Unk_153();
    virtual void Unk_154();
    virtual void Unk_155();
    virtual void Unk_156();
    virtual void Unk_157();
    virtual void Unk_158();
    virtual void Unk_159();
    virtual void Unk_15A();
    virtual void Unk_15B();
    virtual void Unk_15C();
    virtual void Unk_15D();
    virtual void Unk_15E();
    virtual void Unk_15F();
    virtual void Unk_160();
    virtual void Unk_161();
    virtual void Unk_162();
    virtual void Unk_163();
    virtual void Unk_164();
    virtual void Unk_165();
    virtual void Unk_166();
    virtual void Unk_167();
    virtual void Unk_168();
    virtual void Unk_169();
    virtual void Unk_16A();
    virtual void Unk_16B();
    virtual void Unk_16C();
    virtual void Unk_16D();
    virtual void Unk_16E();
    virtual void Unk_16F();
    virtual void Unk_170();
    virtual void Unk_171();
    virtual void Unk_172();
    virtual void Unk_173();
    virtual void Unk_174();
    virtual void Unk_175();
    virtual void Unk_176();
    virtual void Unk_177();
    virtual void Unk_178();
    virtual void Unk_179();
    virtual void Unk_17A();
    virtual void Unk_17B();
    virtual void Unk_17C();
    virtual void Unk_17D();
    virtual void Unk_17E();
    virtual void Unk_17F();
    virtual void Unk_180();
    virtual void Unk_181();
    virtual void Unk_182();
    virtual void Unk_183();
    virtual void Unk_184();
    virtual void Unk_185();
    virtual void Unk_186();
    virtual void Unk_187();
    virtual void Unk_188();
    virtual void Unk_189();
    virtual void Unk_18A();
    virtual void Unk_18B();
    virtual void Unk_18C();
    virtual void Unk_18D();
    virtual void Unk_18E();
    virtual void Unk_18F();
    virtual void Unk_190();
    virtual void Unk_191();
    virtual void Unk_192();
    virtual void Unk_193();
    virtual void Unk_194();
    virtual void Unk_195();
    virtual void Unk_196();
    virtual void Unk_197();
    virtual void Unk_198();
    virtual void Unk_199();
    virtual void Unk_19A();
    virtual void Unk_19B();
    virtual void Unk_19C();
    virtual void Unk_19D();
    virtual void Unk_19E();
    virtual void Unk_19F();
    virtual void Unk_1A0();
    virtual void Unk_1A1();
    virtual void Unk_1A2();
    virtual void Unk_1A3();
    virtual void Unk_1A4();
    virtual void Unk_1A5();
    virtual void Unk_1A6();
    virtual void Unk_1A7();
    virtual void Unk_1A8();
    virtual void Unk_1A9();
    virtual void Unk_1AA();
    virtual void Unk_1AB();
    virtual ProjectileNode* Unk_1AC();
public:
    ::ActorPackageContext *GetCurrentProcessData();
};

class Actor : public MobileObject
{
  public:
};

struct ActorList
{
};

class ProcessLists
{
  public:
};
struct Vec3
{
    float x, y, z;
    Vec3 ApplyScaled(float f);
public:
    Vec3();
};


// @fnv 0x008cddd0
void FUN_008cddd0(MobileObject* owner, bool bFlag)
{
    if (owner == 0 || owner->Unk_89())
        return;

    bool bHigh = true;
    bool bLow = true;
    if (owner->Unk_40())
    {
        Actor* pActor = (Actor*)owner;
        BaseProcess* process = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture()));
        if (process)
        {
            if (process->Unk_1AC())
            {
                ProjectileNode* node = process->Unk_1AC();
                while (node && !FUN_008256d0(node))
                {
                    Projectile* projectile = *((::Projectile **)(((::Vec3 *)(void *)(node))));
                    if (projectile)
                    {
                        if (((::MobileObject *)(reinterpret_cast<::FUN_0085f810_shell *>((projectile))->FUN_0085f810())) == owner)
                        {
                            reinterpret_cast<::FUN_008d0240_Class *>((projectile))->FUN_008d0240();
                            if (!reinterpret_cast<::FUN_00440d80_shell *>((projectile))->FUN_00440d80())
                            {
                                if (bFlag)
                                    projectile->Unk_31(1);
                                else
                                    reinterpret_cast<::FUN_008cc6d0_class *>((projectile))->FUN_008cc6d0(3);
                            }
                        }
                        if (reinterpret_cast<::FUN_00440d80_shell *>((projectile))->FUN_00440d80())
                            projectile->Unk_73(0, 1);
                    }
                    node = ((::ProjectileNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
                }
                reinterpret_cast<::FileMatchList *>((process->Unk_1AC()))->RemoveAll();
            }
            if (((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((process))->FUN_0045cd60())) == 0)
            {
                bHigh = true;
                bLow = false;
            }
            else if (((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((process))->FUN_0045cd60())) == 1)
            {
                bHigh = false;
                bLow = true;
            }
        }
    }

    if (bHigh)
    {
        MobileObject* object = 0;
        for (unsigned int i = 0; i < reinterpret_cast<::FUN_005be5c0_shell *>((((::ActorList *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ProcessLists *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005be5c0(0); i++)
        {
            bool bStopped = false;
            object = ((::MobileObject *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::ActorList *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ProcessLists *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670(i)));
            if (object->Unk_89())
            {
                ArrowProjectile* arrow = dynamic_cast<ArrowProjectile*>(object);
                if (arrow)
                {
                    if (((::MobileObject *)(reinterpret_cast<::FUN_0085f810_shell *>((arrow))->FUN_0085f810())) == owner)
                    {
                        reinterpret_cast<::FUN_008d0240_Class *>((arrow))->FUN_008d0240();
                        if (!reinterpret_cast<::FUN_00440d80_shell *>((object))->FUN_00440d80())
                        {
                            if (bFlag)
                            {
                                arrow->Unk_31(1);
                                bStopped = true;
                            }
                            else
                            {
                                reinterpret_cast<::FUN_008cc6d0_class *>((arrow))->FUN_008cc6d0(3);
                            }
                        }
                    }
                    if (reinterpret_cast<::FUN_00440d80_shell *>((arrow))->FUN_00440d80())
                        arrow->Unk_73(0, 1);
                }
            }
        }
    }

    if (bLow)
    {
        MobileObject* object = 0;
        for (unsigned int i = reinterpret_cast<::fnv_005de0f0::FUN_005de0f0_shell *>((((::ActorList *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ProcessLists *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005de0f0(1);
             i < reinterpret_cast<::FUN_005be5c0_shell *>((((::ActorList *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ProcessLists *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005be5c0(1); i++)
        {
            bool bStopped = false;
            object = ((::MobileObject *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::ActorList *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ProcessLists *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670(i)));
            if (object->Unk_89())
            {
                ArrowProjectile* arrow = dynamic_cast<ArrowProjectile*>(object);
                if (arrow)
                {
                    if (((::MobileObject *)(reinterpret_cast<::FUN_0085f810_shell *>((arrow))->FUN_0085f810())) == owner)
                    {
                        reinterpret_cast<::FUN_008d0240_Class *>((arrow))->FUN_008d0240();
                        if (!reinterpret_cast<::FUN_00440d80_shell *>((object))->FUN_00440d80())
                        {
                            arrow->Unk_31(1);
                            bStopped = true;
                        }
                    }
                    if (reinterpret_cast<::FUN_00440d80_shell *>((arrow))->FUN_00440d80())
                        arrow->Unk_73(0, 1);
                }
            }
        }
    }
}


struct __declspec(align(16)) Vec4
{
    __m128 quad;
    Vec4();
};


struct Filter
{
    int v;
    Filter();
};

struct Shape;
struct EObj;
struct WorldObj
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void GetTransform(EObj*);
    Filter FUN_0043b4f0();
};

struct CollObj
{
};


struct EObj
{
    struct RawVector
    {
        __m128 quad;
    };
    RawVector storage[4];
    EObj();
    void FUN_00cb2240(void* g, void* f);
};

struct GObj
{
    struct RawVector
    {
        __m128 quad;
    };
    RawVector storage[4];
    GObj(EObj* e);
};


struct CSub
{
    __m128 quad;
};

struct __declspec(align(16)) CObj
{
    CSub m0;
    CSub m1;
    unsigned int flags20, filter24;
};

struct Sub2;
struct DObj;
struct ResObj
{
};

struct Sub2
{
    bool value;
};

struct __declspec(align(16)) DObj
{
    float normalX, normalY, normalZ, normalW;
    float fraction;
    int m_uiExtraInfo, unk18, unk1c;
    unsigned int shapeKeys[8];
    void* rootCollidable;
};

struct Shape
{
};

class NiAVObject;
struct NiNode
{
    unsigned int FUN_0043b480();
public:
    ::NiAVObject *GetAt(unsigned int);
};

struct P1Obj
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual NiNode* getNode();
};

// @fnv 0x008cfbc0
void* __cdecl FUN_008cfbc0(void* p1, Vec3 a, Vec3 b, float* p4, bool p5)
{
    bool flag = false;
    if (p1)
    {
        CollObj* coll = ((::CollObj *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(p1))));
        if (coll)
        {
            WorldObj* world = ((::WorldObj *)(::fnv_006fa820::FUN_006fa820((const char *)(coll))));
            Shape* shape = world ? ((::Shape *)(reinterpret_cast<::FUN_004ae6a0_shell *>((world))->FUN_004ae6a0())) : 0;
            if (shape)
            {
                if (reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::Filter &)(world->FUN_0043b4f0()))->FUN_0043b4d0() == 8)
                {
                    if (reinterpret_cast<::bhkFilter *>((void *)&(const ::Filter &)(world->FUN_0043b4f0()))->FUN_006240b0() != 0x12)
                    {
                        if (reinterpret_cast<::bhkFilter *>((void *)&(const ::Filter &)(world->FUN_0043b4f0()))->FUN_006240b0() != 0x13)
                        {
                            if (!p5 || reinterpret_cast<::bhkFilter *>((void *)&(const ::Filter &)(world->FUN_0043b4f0()))->FUN_006240b0() != 1)
                            {
                                Vec4 va;
                                ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&va)), (const ::fnv_004a3e00::NiPoint3 &)(a));
                                Vec4 vb;
                                ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&vb)), (const ::fnv_004a3e00::NiPoint3 &)((const ::Vec3 &)((*(::Vec3 *)(reinterpret_cast<::Point3Offset *>(&(a))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(b.ApplyScaled(*p4)), {}))))));
                                CObj oc;
                                reinterpret_cast<::S632 *>(&(oc))->FUN_00632ca0();
                                DObj od;
                                ::FUN_004a3d20((void *)&(od));
                                EObj oe;
                                if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_01267e64))), (::NiAVObject *)(coll)))
                                {
                                    CollObj* scaledColl = coll;
                                    if (!reinterpret_cast<::Holder_cffa0 *>((world))->FUN_008cffa0() || reinterpret_cast<::BSMultiBoundSphere *>((scaledColl))->GetRadius() == 1.0)
                                    {
                                        ::FromHK((*(::hkTransform *)(&oe)), (*(const ::NiTransform *)(((void *)(::FUN_00461130((intptr_t)(((P1Obj*)p1))))))));
                                        if (::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012683c8))), (::NiAVObject *)(world)))
                                        {
                                            WorldObj* transformedWorld = world;
                                            EObj of;
                                            GObj og(&oe);
                                            reinterpret_cast<::FUN_008cd6a0_Class *>(&(of))->FUN_008cd6a0(((void *)(reinterpret_cast<::BGSCameraPath *>((transformedWorld))->GetShotList())),
                                                            ((void *)(reinterpret_cast<::TESTopicInfo *>((transformedWorld))->GetAddTopicList())));
                                            oe.FUN_00cb2240(&og, &of);
                                        }
                                    }
                                    else
                                    {
                                        world->GetTransform(&oe);
                                    }
                                }
                                else
                                {
                                    world->GetTransform(&oe);
                                }
                                reinterpret_cast<::FUN_00c7f690_cls *>(&(oc.m0))->FUN_00c7f690((const ::S_00c7f690_M *)(::EObj *)(&oe), (const ::S_00c7f690_V *)(::Vec4 *)(&va));
                                reinterpret_cast<::FUN_00c7f690_cls *>(&(oc.m1))->FUN_00c7f690((const ::S_00c7f690_M *)(::EObj *)(&oe), (const ::S_00c7f690_V *)(::Vec4 *)(&vb));
                                Sub2 bt;
                                reinterpret_cast<::FUN_00632c30_Class *>((((::ResObj *)(::FUN_004ae750((void *)(shape))))))->ForwardToV8(&bt, &oc, &od);
                                Sub2 bt2;
                                if (reinterpret_cast<::FUN_005609f0_shell *>((((::Sub2 *)(reinterpret_cast<::FUN_00632c60_Class *>(&(od))->FUN_00632c60((::CalleeObj *)(::Sub2 *)(&bt2))))))->FUN_005609f0())
                                {
                                    *p4 *= od.fraction;
                                    flag = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        NiNode* node = ((P1Obj*)p1)->getNode();
        if (node)
        {
            unsigned int i;
            for (i = 0; i < node->FUN_0043b480(); i++)
            {
                void* childItem = ((void *)(node->GetAt(i)));
                void* r = FUN_008cfbc0(childItem, a, b, p4, p5);
                if (r)
                    return r;
            }
        }
    }
    if (flag)
        return p1;
    return 0;
}
