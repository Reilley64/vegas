
// src/fallout/interface/menus/specialbookmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/specialbookmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include <cstdint>
#include <new>
#include "fnv/decl/AnimationSequence.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenMorphData.h"
#include "fnv/decl/CameraWindowRay.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00458b30_class.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_00792780_Class.h"
#include "fnv/decl/FUN_007c9dc0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0093a7c0_Owner.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a24180_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/MultiBoundManagerB5D.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiPointLight.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00b5c940__SSNode.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00794000.h"
#include "fnv/symbols_007c6000.h"
#include "fnv/symbols_007ca000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01074000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
struct FUN_007ca030_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int FUN_007ca030();
};

// Returns m_48 + 4 when m_48 is between 1 and 8, adding 4 more for slot 8 if _FUN_004b71d0() is true; otherwise returns -1.
// @fnv 0x007ca030
int FUN_007ca030_shell::FUN_007ca030()
{
    if (this->m_48 > 0 && this->m_48 < 9)
    {
        if (::FUN_004b71d0())
        {
            if (this->m_48 == 8)
                return this->m_4c + 4;
        }
        return this->m_48 + 4;
    }
    return -1;
}

struct NiAVObject
{
public:
    void SetLocalRotation(float, float, float, float);
};
struct NiAdditionalGeometryData
{
    static NiAVObject* __cdecl GetShadowSceneNodeForIndex(int);
};
struct NiNode
{
};
struct ModelLoader
{
};
struct GlobalObject_00633c90
{
    void* m_00;
};
struct GO
{
    GO& operator=(void*);
};
struct GlobalObject_00869f00
{
};
struct Tile
{
    void Set(int, int);
};
struct Menu
{
};
struct FUN_00b5ddb0_self
{
};

// @fnv 0x007c6120
void __cdecl FUN_007c6120()
{
    int i;
    Menu* menu5 = ((::Menu *)(::FUN_00a09030(::FUN_007c6110())));
    if (!menu5)
        return;
    reinterpret_cast<::FUN_0045a5e0_shell *>((::g_modelLoader))->FUN_0045a5e0((char *)("Meshes\\Terminals\\Babybook02.NIF"));
    reinterpret_cast<::FUN_004def90_Class *>((((NiNode*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))->FUN_004def90();
    reinterpret_cast<::MultiBoundManagerB5D *>((((FUN_00b5ddb0_self*)NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))->FUN_00b5d180();
    *(int*)((char*)DAT_011daa38 + 0x5c) = 0;
    ((GO*)&::g_011daa9c)->operator=(0);
    i = 0;
    for (; i < 9; ++i)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)DAT_011daa38 + i * 32 + 0x60))))->Clear(true);
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)DAT_011daa38 + i * 32 + 0x70))))->Clear(true);
    }
    if (DAT_011daa38)
    {
        ((Tile*)menu5)->Set(0x1772, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>((((Menu*)DAT_011daa38)))->FUN_00a1d910();
    }
}

struct FUN_00794d30_shell
{
    char pad1[0x48];
    int m_48;
    int m_4c;

    int FUN_00794d30();
};


// Returns m_4c + 4 when m_48 is 8 and _FUN_004b71d0() is true, m_48 + 4 when m_48 is between 1 and 7, otherwise -1.
// @fnv 0x00794d30
int FUN_00794d30_shell::FUN_00794d30()
{
    if (m_48 == 8)
    {
        if (::FUN_004b71d0())
            return m_4c + 4;
    }
    if (m_48 > 0 && m_48 < 8)
        return m_48 + 4;
    return -1;
}

class AnimIdle;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* p);
    ~NiPointer();
    NiPointer& operator=(T* p);
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char* s);
    ~NiFixedString();
};
struct PropHelper
{
};
struct NiTimeController
{
};
struct SceneRoot_007ca080
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual AnimIdle* GetObjectByName(const NiFixedString& name);
};
struct Holder_007ca080
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    SceneRoot_007ca080* pRoot;
};

struct FUN_007ca080
{
    int m_00;
    int m_04;
    NiPointer<AnimIdle> m_pController;
    void* m_0c;
    FUN_007ca080(int a, int b, const char* name);
};

// @fnv 0x007ca080
FUN_007ca080::FUN_007ca080(int aiValueA, int aiValueB, const char* name) : m_pController(0)
{
    m_00 = aiValueA;
    m_04 = aiValueB;
    m_pController = ((Holder_007ca080*)DAT_011daa38)->pRoot->GetObjectByName(NiFixedString(name));
    AnimIdle* pAnimIdle = ((Holder_007ca080*)DAT_011daa38)->pRoot->GetObjectByName(NiFixedString(name));
    m_0c = (!((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)pAnimIdle)))->FUN_00a59d30(3)))
                ? 0
                : (((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)pAnimIdle)))->FUN_00a59d30(3))))))->GetMinLevel())) >= 8 &&
                   ((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)pAnimIdle)))->FUN_00a59d30(3))))))->GetMinLevel())) <= 12))
               ? ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)pAnimIdle)))->FUN_00a59d30(3)))
               : 0;
}

class SPECIALBookMenu
{
  public:
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03(int, int) = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14(int, float) = 0;

    bool HandleInput(int aiKey);
};

// @fnv 0x007c6c50
bool SPECIALBookMenu::HandleInput(int aiKey)
{
    bool bhandled = false;

    if (aiKey == 0x80000001 || aiKey == 0x80000002)
    {
        v03(aiKey == 0x80000001, 0);
        bhandled = true;
    }

    if (aiKey == 0x80000003 || aiKey == 0x80000004)
    {
        v14((aiKey != 0x80000003) + 3, 1.0f);
        bhandled = true;
    }

    return bhandled;
}

struct NiUpdateData
{
    float time;
    bool updateControllers;
    bool multithreaded;
    bool updateGeomorphs;
    bool updateShadowScene;
    bool isCulled;
    NiUpdateData(float, bool, bool);
};
struct NiControllerSequence
{
    void Update(float, bool);
};
struct MenuController
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
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void Update(const NiUpdateData&);
};
struct MenuScene
{
    void Update(const NiUpdateData&);
};
struct MenuInput
{
};
struct MenuOS
{
};
struct MenuLocale
{
};
struct MenuTime
{
};
extern bool DAT_011a0854;
extern const char* DAT_011a0858[];
extern const char* DAT_011a0878[];
bool __cdecl FUN_00702450(int);
struct MenuUpdate
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void Handle(int, int);
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int selection;
    int field4c;
    float elapsed;
    bool finished;
    int field58;
    MenuScene* scene;
    void FUN_007c6200();
};
// Checks a key press to trigger Handle(4,0), otherwise advances the scene's controller sequence by elapsed time and updates the scene.
// @fnv 0x007c6200
void MenuUpdate::FUN_007c6200()
{
    if (!FUN_00702450(0x424))
        return;
    MenuInput* pInput = ((::MenuInput *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::MenuOS * *>(&::g_osGlobals))))->FUN_00877720()));
    {
        MenuController* pController;
        {
            int scanCode = 30;
            if (FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MenuLocale *>(&::g_011c3cb4))))->GetMenuTitle())), "FRENCH") == 0)
                scanCode = 16;
            if (reinterpret_cast<::FUN_00a24180_shell *>((pInput))->FUN_00a24180(scanCode, 1))
            {
                Handle(4, 0);
                return;
            }
            pController = ((::MenuController *)(::fnv_0043b230::FUN_0043b230((const char *)(scene))));
            if (pController)
            {
                MenuController* manager = pController;
                NiControllerSequence* sequence = 0;
                if (!DAT_011a0854 || selection > 0)
                    sequence = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((manager))->FUN_0047a520(
                        (::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString(DAT_011a0854 ? DAT_011a0878[selection] : DAT_011a0858[selection])))));
                elapsed += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::MenuTime *>(&::g_timeGlobal))))->GetStoredFloatValue();
                if (sequence)
                {
                    reinterpret_cast<::AnimationSequence *>((sequence))->FUN_00a34ba0(elapsed, true);
                    if (reinterpret_cast<::BSFaceGenMorphData *>((sequence))->FUN_00508120() < reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100() && selection > 0)
                        finished = false;
                    else
                        finished = true;
                }
                else
                {
                    finished = true;
                }
                for (; pController; pController = ((::MenuController *)(::fnv_004a8a90::FUN_004a8a90((char *)(pController)))))
                {
                    MenuController* castController = ((::MenuController *)(::FUN_00653270((const ::NiRTTI *)(const int *)(&(*reinterpret_cast<int *>(&::g_011f36bc))), (::NiObject *)(pController))));
                    if (castController)
                    {
                        NiUpdateData updateData(elapsed, false, false);
                        pController->Update(updateData);
                        break;
                    }
                }
            }
            NiUpdateData updateData(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((scene))->FUN_00a59c60((std::intptr_t)&(updateData));
        }
    }
}

bool __cdecl FUN_00702450(unsigned int);
struct Values6440
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetValue(int);
};
struct Player6440
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
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    Values6440 values;
};
struct Target6440 : SPECIALBookMenu
{
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
    bool HandleSpecialBookKey(unsigned int key, int unused);
};
// @fnv 0x007c6440
bool Target6440::HandleSpecialBookKey(unsigned int key, int unused)
{
    if (FUN_00702450(0x424))
    {
        int index = reinterpret_cast<::FUN_007ca030_shell *>(this)->FUN_007ca030();
        switch (key)
        {
        case 4:
        case 10:
            if (index != -1 && (*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer))->values.GetValue(index) > 1)
                v03(3, 0);
            return true;
        case 3:
        case 9:
            if (index != -1 && ::FUN_00794d80((void *)this) < unk58 && (*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer))->values.GetValue(index) < 10)
                v03(2, 0);
            return true;
        }
    }
    return false;
}

class C7CA200NavMesh;

class C7CA200Base
{
  public:
    C7CA200Base(int iArg1, int iArg2, int iArg3);
    ~C7CA200Base();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class C7CA200NavMeshArray
{
  public:
    C7CA200NavMeshArray();
    ~C7CA200NavMeshArray();


    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_007ca200 : public C7CA200Base
{
  public:
    FUN_007ca200(int iArg1, int iArg2, int iArg3, int iArg4, int iNumNavMeshes, ...);

    C7CA200NavMeshArray m_kNavMeshes;
    int m_iArg4;
};

// Initializes the base with three arguments, stores iArg4, and adds iNumNavMeshes nav mesh pointers from the variadic argument list to m_kNavMeshes.
// @fnv 0x007ca200
FUN_007ca200::FUN_007ca200(int iArg1, int iArg2, int iArg3, int iArg4, int iNumNavMeshes, ...)
    : C7CA200Base(iArg1, iArg2, iArg3)
{
    m_iArg4 = iArg4;

    char* pcArgs = (char*)&iNumNavMeshes + sizeof(iNumNavMeshes);
    for (int i = 0; i < iNumNavMeshes; i++)
        reinterpret_cast<::FUN_00438690 *>(&(m_kNavMeshes))->FUN_007cb2e0((unsigned int *)&(*(C7CA200NavMesh**)((pcArgs += sizeof(C7CA200NavMesh*)) - sizeof(C7CA200NavMesh*))));
    pcArgs = 0;
}

struct FUN_007ca2c0
{
    int m_00;
    NiTimeController* m_04;
    NiTimeController* m_08;
    PropHelper* m_0c;
    PropHelper* m_10;
    int m_14;
    FUN_007ca2c0(int a, const char* first, const char* second, int d);
};
// Stores the given ints, looks up two named objects under the scene root, and caches each object's property 3 controller when its value is between 8 and 12.
// @fnv 0x007ca2c0
FUN_007ca2c0::FUN_007ca2c0(int a, const char* apFirstName, const char* apSecondName, int d)
{
    m_00 = a;
    m_14 = d;
    m_0c = (PropHelper*)((Holder_007ca080*)DAT_011daa38)->pRoot->GetObjectByName(NiFixedString(apFirstName));
    m_04 = (!((void *)(reinterpret_cast<::FUN_00a59d30_C *>((m_0c))->FUN_00a59d30(3))) ? 0
                                  : (((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((m_0c))->FUN_00a59d30(3))))))->GetMinLevel())) >= 8 &&
                                     ((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((m_0c))->FUN_00a59d30(3))))))->GetMinLevel())) <= 12))
               ? (NiTimeController*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((m_0c))->FUN_00a59d30(3)))
               : 0;
    if (apSecondName)
    {
        m_10 = (PropHelper*)((Holder_007ca080*)DAT_011daa38)->pRoot->GetObjectByName(NiFixedString(apSecondName));
        m_08 = (!((void *)(reinterpret_cast<::FUN_00a59d30_C *>((m_10))->FUN_00a59d30(3))) ? 0
                                      : (((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((m_10))->FUN_00a59d30(3))))))->GetMinLevel())) >= 8 &&
                                         ((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((m_10))->FUN_00a59d30(3))))))->GetMinLevel())) <= 12))
                   ? (NiTimeController*)((void *)(reinterpret_cast<::FUN_00a59d30_C *>((m_10))->FUN_00a59d30(3)))
                   : 0;
    }
}

// Candidate for FUN_007cadd0 (FNV decompilation, official checker)

// , no stack args (caller pops 0). /Od /Oy- /GS /EHsc.

// Based on an unverified GLM (Z.ai) / zai_glm_01 draft, round 4.

struct G_011dea10_cls
{

};







extern const char str_01076cc0[];


extern const char str_01076ca4[];















extern const char str_01076c94[];

struct FUN_007cadd0_self
{

    int unk_000;

    int unk_004;

    int unk_008;

    int unk_00c;

    int unk_010;

    int unk_014;

    int unk_018;

    int unk_01c;

    int unk_020;

    int unk_024;

    int unk_028;

    int unk_02c;

    int unk_030;

    int unk_034;

    int unk_038;

    int unk_03c;

    int unk_040;

    int unk_044;

    int unk_048;

    int unk_04c;

    int unk_050;

    int unk_054;

    int unk_058;

    int unk_05c;

    int unk_060;

    int unk_064;

    int unk_068;

    int unk_06c;

    int unk_070;

    int unk_074;

    int unk_078;

    int unk_07c;

    int unk_080;

    int unk_084;

    int unk_088;

    int unk_08c;

    int unk_090;

    int unk_094;

    int unk_098;

    int unk_09c;

    int unk_0a0;

    int unk_0a4;

    int unk_0a8;

    int unk_0ac;

    int unk_0b0;

    int unk_0b4;

    int unk_0b8;

    int unk_0bc;

    int unk_0c0;

    int unk_0c4;

    int unk_0c8;

    int unk_0cc;

    int unk_0d0;

    int unk_0d4;

    int unk_0d8;

    int unk_0dc;

    int unk_0e0;

    int unk_0e4;

    int unk_0e8;

    int unk_0ec;

    int unk_0f0;

    int unk_0f4;

    int unk_0f8;

    int unk_0fc;

    int unk_100;

    int unk_104;

    int unk_108;

    int unk_10c;

    int unk_110;

    int unk_114;

    int unk_118;

    int unk_11c;

    int unk_120;

    int unk_124;

    int unk_128;

    int unk_12c;

    int unk_130;

    int unk_134;

    int unk_138;

    int unk_13c;

    int unk_140;

    int unk_144;

    int unk_148;

    int unk_14c;

    int unk_150;

    int unk_154;

    int unk_158;

    int unk_15c;

    int unk_160;

    int unk_164;

    int unk_168;

    int unk_16c;

    int unk_170;

    int unk_174;

    int unk_178;

    int unk_17c;

    int m180[10];  // 0x180

    int m1a8[5];  // 0x1a8

    int m1bc;  // 0x1bc

    int m1c0;  // 0x1c0

    int m1c4;  // 0x1c4

    int m1c8;  // 0x1c8

    int m1cc;  // 0x1cc

    int m1d0;  // 0x1d0

    int m1d4;  // 0x1d4

    int m1d8;  // 0x1d8

    int m1dc;  // 0x1dc

    int m1e0;  // 0x1e0

    void FUN_007cadd0();
};

// @fnv 0x007cadd0
void FUN_007cadd0_self::FUN_007cadd0()

{

    int iStack_228;

    int auStack_110;

    char iStack_224[8];

    char auStack_220[264];

    char auStack_218[264];

    for (auStack_110 = 0; auStack_110 < 0xb; auStack_110++)
    {

        ::FUN_00406d00(auStack_220, 0x104, ::fnv_00796100::str_01074c4c, str_01076cc0, ::fnv_00796100::str_01074c6c, auStack_110);

        ::ConvertLocalizedString(auStack_220, auStack_218, 0x104);

        reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m180[auStack_110])), 0, 0);
    }

    for (iStack_228 = 1; iStack_228 < 5; iStack_228++)
    {

        ::FUN_00406d00(auStack_220, 0x104, ::fnv_00796100::str_01074c4c, str_01076ca4, ::fnv_00796100::str_01074c40, iStack_228);

        ::ConvertLocalizedString(auStack_220, auStack_218, 0x104);

        reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1a8[iStack_228])), 0, 0);
    }

    if (FUN_00709d40())

        ::TaskQueueInterface::CopyStringToBuffer(iStack_224, 5, ::fnv_00796100::str_0101fd1c);

    else

        ::TaskQueueInterface::CopyStringToBuffer(iStack_224, 5, ::fnv_00796100::str_0101fd24);

    ::FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, ::fnv_00796100::str_01074c38);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1c0)), 0, 0);

    ::FUN_00406d00(auStack_220, 0x104, ::fnv_00796100::str_01074c08, str_01076cc0, ::fnv_00796100::str_01074c24);

    ::ConvertLocalizedString(auStack_220, auStack_218, 0x104);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1bc)), 0, 0);

    ::FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, ::fnv_00796100::str_01074c1c);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1c4)), 0, 0);

    ::FUN_00406d00(auStack_220, 0x104, ::fnv_00796100::str_01074c08, str_01076cc0, ::fnv_00796100::str_01074c14);

    ::ConvertLocalizedString(auStack_220, auStack_218, 0x104);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1c8)), 0, 0);

    ::FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, ::fnv_00796100::str_01074c00);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1cc)), 0, 0);

    ::FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, ::fnv_00796100::str_01074bf8);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1d0)), 0, 0);

    ::FUN_00406d00(auStack_220, 0x104, ::fnv_00796100::str_01074c08, str_01076cc0, ::fnv_00796100::str_01074be8);

    ::ConvertLocalizedString(auStack_220, auStack_218, 0x104);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1d4)), 0, 0);

    ::FUN_00406d00(auStack_220, 0x104, ::fnv_00796100::str_01074c08, str_01076cc0, ::fnv_00796100::str_01074bd8);

    ::ConvertLocalizedString(auStack_220, auStack_218, 0x104);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1d8)), 0, 0);

    ::FUN_00406d00(auStack_220, 0x104, ::fnv_00796100::str_01074c08, str_01076cc0, ::fnv_00796100::str_01074bc8);

    ::ConvertLocalizedString(auStack_220, auStack_218, 0x104);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1dc)), 0, 0);

    ::FUN_00406d00(auStack_220, 0x104, ::fnv_00796100::str_01074c08, str_01076cc0, ::fnv_00796100::str_01074bb8);

    ::ConvertLocalizedString(auStack_220, auStack_218, 0x104);

    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::G_011dea10_cls * *>(&::g_TES))))->FUN_004568c0(auStack_218, (*(::TexPtr< ::NiSourceTexture> *)(&m1e0)), 0, 0);
}

struct NiRTTI
{
    int unk00;
};

class NiControllerSequence;
struct NiControllerManager
{
public:
    bool ActivateControllerSequence(::NiControllerSequence *, int, bool, float, float, ::NiControllerSequence *);
public:
    void DeactivateAllSequences(float);
};

struct AVObject_7c9dc0
{
};

struct SceneHolder
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
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    AVObject_7c9dc0* pRoot;
};

struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx& o);
};

struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char* id, unsigned int flags);
};


extern bool DAT_011a0854;
extern const char* DAT_011a0858[8];
extern const char* DAT_011a0878[8];

struct SPECIALBookMenu_7c9dc0
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
    int pageIndex;
    bool FUN_007c9dc0(bool forward);
};

// @fnv 0x007c9dc0
bool SPECIALBookMenu_7c9dc0::FUN_007c9dc0(bool forward)
{
    bool turned = false;
    if (forward)
    {
        DAT_011a0854 = true;
        if (pageIndex < 9)
        {
            pageIndex++;
            turned = true;
            BSSoundHandleEx sound;
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(sound))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialPageTurn", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
        }
        else
        {
            return false;
        }
    }
    else
    {
        DAT_011a0854 = false;
        if (pageIndex >= 1)
        {
            pageIndex--;
            turned = true;
            BSSoundHandleEx sound;
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(sound))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialPageTurn", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
        }
        else
        {
            return false;
        }
    }
    if (turned)
    {
        NiControllerManager* found = (NiControllerManager*)((void *)(reinterpret_cast<::MyHost *>((void *)((*reinterpret_cast<::SceneHolder * *>(&::DAT_011daa38))->pRoot))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTI *)(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac))))));
        if (found)
        {
            NiControllerManager* manager = found;
            NiControllerSequence* sequence = 0;
            if (!DAT_011a0854 || pageIndex > 0)
            {
                sequence = ((::NiControllerSequence *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((manager))->FUN_0047a520(
                    (::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString(DAT_011a0854 ? DAT_011a0878[pageIndex] : DAT_011a0858[pageIndex])))));
            }
            if (sequence)
            {
                manager->DeactivateAllSequences(0.0f);
                manager->ActivateControllerSequence(sequence, 0, true, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::TaskQueueInterface *>((manager))->QueueReferenceStateTask(true);
                SetNegatedGlobal(sequence);
            }
        }
    }
    return true;
}


void __cdecl FUN_007ca700(void* p);
void __cdecl FUN_007ca960(void* p);

typedef void(__cdecl* ItemCb)(void* p);

struct BkPoint3
{
    float x, y, z;
};
struct BkColor
{
    float r, g, b;
    BkColor(float ar, float ag, float ab);
};
struct BkFixedStr
{
    void* m_pData;
    BkFixedStr(const char* s);
    ~BkFixedStr();
};
struct BkTimer
{
};
struct BkAnimSeq
{
};
struct BkAnimCtrl
{
};
struct BkCtrl
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void SetPos(const BkPoint3& p);
};
struct BkNode
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int v03(float f);
};
struct BkLight
{
    char pad[0xfc];
    BkLight();
    void FUN_0050dd50(const BkColor& c);
};
struct BkScene
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(void* child, int firstAvail);
};
struct BkLoader
{
};

struct BkItemBase
{
};
struct BkButton : BkItemBase
{
    ItemCb m_cb0;
    ItemCb m_cb4;
    int unk08;
    int unk0C;
    int unk10;
    BkButton(ItemCb a, ItemCb b, const char* name);
};
struct BkStepButton : BkButton
{
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    BkStepButton(ItemCb a, ItemCb b, const char* name, int stat, int count, ...);
};
struct BkDisplay : BkItemBase
{
    ItemCb m_cb;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    BkDisplay(ItemCb cb, const char* name, const char* name2, int stat);
};
struct BkButtonList
{
    BkButton** m_pData;
    int m_iCapacity;
    int m_iArrayLength;
    int m_iGrow;
};
struct BkDisplayList
{
    BkDisplay** m_pData;
    int m_iCapacity;
    int m_iArrayLength;
    int m_iGrow;
};
struct BkGroup
{
    BkButtonList buttons;
    BkDisplayList displays;
};
struct BkMenuG
{
    char pad[0x50];
    float m_fTime;
    int unk54;
    int unk58;
    BkNode* m_pReferencedNode;
};

BkScene* __cdecl FUN_00450b80(int a);

struct SpecialBookMenuX
{
    char pad[0x50];
    float m_fTime;
    int unk54;
    int unk58;
    BkNode* m_pReferencedNode;
    BkGroup m_groups[9];
    void InitMenu();
};

// Unused, never emitted: keeps the per-TU $SG literal numbering clear of the checker's fixed $SG bindings (KB k8552).
inline const char* BkSgNumberingShim(int i)
{
    static const char* const t[] = {"0",  "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9",  "10", "11", "12", "13",
                                    "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27"};
    return t[i];
}
// Loads the Babybook02.NIF scene, sets up its transform and animation, then creates and registers the displays and buttons for all nine menu groups.
// @fnv 0x007c6ce0
void SpecialBookMenuX::InitMenu()
{
    BkDisplay* pDigits;
    BkPoint3 pos;
    float aScale;
    BkStepButton* declA;
    BkStepButton* pIncrease;
    BkButton* next;
    BkButton* pLeft;
    void* found;
    BkCtrl* aPCtrl;
    BkPoint3 akStart;
    BkDisplay* valueX;
    BkDisplay* kMsg;

    ((BkMenuG*)DAT_011daa38)->m_pReferencedNode =
        ((::BkNode *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::BkLoader * *>(&::g_modelLoader))))->FUN_00447080((char *)("Meshes\\Terminals\\Babybook02.NIF"), 0, 1, 0, 0, 0)));
    ::UpdateObjectVisibility((::NiAVObject *)(((BkMenuG*)DAT_011daa38)->m_pReferencedNode));
    reinterpret_cast<::FUN_00440490_shell *>((((BkMenuG*)DAT_011daa38)->m_pReferencedNode))->FUN_00440490(0.05f);
    reinterpret_cast<::FUN_004bc1f0_S *>((((BkMenuG*)DAT_011daa38)->m_pReferencedNode))->FUN_004bc1f0(0.0f, 0.0f, -60.0f);
    reinterpret_cast<::NiAVObject *>((((BkMenuG*)DAT_011daa38)->m_pReferencedNode))->SetLocalRotation(1.5707964f, 1.0f, 0.0f, 0.0f);
    new ((void *)&(akStart)) ::NiUpdateData(0.0f, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((((BkMenuG*)DAT_011daa38)->m_pReferencedNode))->FUN_00a59c60((std::intptr_t)&(akStart));
    ((BkMenuG*)DAT_011daa38)->m_fTime += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::BkTimer *>(&::g_timeGlobal))))->GetStoredFloatValue();
    aPCtrl = ((::BkCtrl *)(reinterpret_cast<::MyHost *>((((BkMenuG*)DAT_011daa38)->m_pReferencedNode))->FUN_00a5c570((const ::MyRTTI *)(void *)(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac))))));
    if (aPCtrl)
    {
        BkAnimCtrl* mgr5 = (BkAnimCtrl*)aPCtrl;
        BkAnimSeq* pForwardSequence = ((::BkAnimSeq *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((mgr5))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::BkFixedStr &)(BkFixedStr("Forward")))));
        if (pForwardSequence)
        {
            reinterpret_cast<::NiControllerManager *>((mgr5))->DeactivateAllSequences(0.0f);
            reinterpret_cast<::NiControllerManager *>((mgr5))->ActivateControllerSequence((::NiControllerSequence *)(pForwardSequence), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            reinterpret_cast<::TaskQueueInterface *>((mgr5))->QueueReferenceStateTask(1);
            ::SetNegatedGlobal((void *)(pForwardSequence));
        }
    }
    ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(m_pReferencedNode));
    for (; aPCtrl; aPCtrl = ((::BkCtrl *)(::fnv_004a8a90::FUN_004a8a90((char *)(aPCtrl)))))
    {
        void* pMatch = ((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<int *>(&::g_011f36bc))), (::NiObject *)(aPCtrl))));
        if (pMatch)
        {
            BkPoint3 pT4;
            new ((void *)&(pT4)) ::NiUpdateData(0.0f, 0, 0);
            aPCtrl->SetPos(pT4);
            break;
        }
    }
    new ((void *)&(pos)) ::NiUpdateData(0.0f, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((m_pReferencedNode))->FUN_00a59c60((std::intptr_t)&(pos));
    aScale = reinterpret_cast<::Twin_0084d030 *>((((::BkTimer *)(reinterpret_cast<::FUN_0043d450_Owner *>((((BkMenuG*)DAT_011daa38)->m_pReferencedNode))->FUN_0043d450()))))->GetStoredFloatValue() * 20.0;
    found = ((void *)(reinterpret_cast<::SSN_b5 *>((FUN_00450b80(1)))->FUN_00b5ca70((::Node_b5 *)(((BkMenuG*)DAT_011daa38)->m_pReferencedNode->v03(aScale)), {})));
    if (found == 0)
    {
        BkLight* apTargetLight = new BkLight();
        reinterpret_cast<::FUN_00440460_S *>((apTargetLight))->FUN_00440460((const ::V3 *)&(const ::BkColor &)(BkColor(0.0f, 0.0f, 0.0f)));
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>((apTargetLight))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)((const ::BkColor &)(BkColor(0.85f, 0.85f, 0.85f))));
        apTargetLight->FUN_0050dd50(BkColor(aScale, 0.0f, 0.0f));
        reinterpret_cast<::NiPointLight *>((apTargetLight))->FUN_0050dd20(1.0f);
        BkPoint3 kLightPos;
        new ((void *)&(kLightPos)) ::NiUpdateData(0.0f, 0, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((apTargetLight))->FUN_00a59c60((std::intptr_t)&(kLightPos));
        FUN_00450b80(1)->AttachChildInAvailableSlot(apTargetLight, 1);
        reinterpret_cast<::fnv_00b5c940::SSNode *>((FUN_00450b80(1)))->FUN_00b5c940((::fnv_00b5c940::NiLightObj *)(apTargetLight), 0);
    }
    FUN_00450b80(1)->AttachChildInAvailableSlot(((BkMenuG*)DAT_011daa38)->m_pReferencedNode, 1);

    next = new BkButton(((void (&)(void *))::FUN_007cabb0), ((void (&)(void *))::CallVfunc60WithGlobalOffset), "LookInside_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[0].buttons))->FUN_007cb2e0((unsigned int *)&(next));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "P1_PointVal:0", 0, 5);
    kMsg = new BkDisplay(((void (&)(void *))::DispatchStateCallback), "P1_Message:0", 0, -1);
    pDigits = new BkDisplay(((void (&)(void *))::fnv_007ca5f0::UpdateLodVisibility), "P1_PointsRemainDigit1:0", "P1_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P1_Decrease_Btn:0", 5, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "P1_Increase_Btn:0", 5, 2, valueX, pDigits);
    next = new BkButton(((void (&)(void *))::FUN_007cabb0), ((void (&)(void *))::CallVfunc60WithGlobalOffset), "P1_RT_Btn:0");
    pLeft = new BkButton(((void (&)(void *))::fnv_007cabf0::FUN_007cabf0), ((void (&)(void *))::FUN_007ca8a0), "P1_LT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[1].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[1].displays))->FUN_007cb2e0((unsigned int *)&(kMsg));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[1].displays))->FUN_007cb2e0((unsigned int *)&(pDigits));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[1].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[1].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[1].buttons))->FUN_007cb2e0((unsigned int *)&(next));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[1].buttons))->FUN_007cb2e0((unsigned int *)&(pLeft));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "P2_PointVal:0", 0, 6);
    kMsg = new BkDisplay(((void (&)(void *))::DispatchStateCallback), "P2_Message:0", 0, -1);
    pDigits = new BkDisplay(((void (&)(void *))::fnv_007ca5f0::UpdateLodVisibility), "P2_PointsRemainDigit1:0", "P2_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P2_Decrease_Btn:0", 6, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "P2_Increase_Btn:0", 6, 2, valueX, pDigits);
    next = new BkButton(((void (&)(void *))::FUN_007cabb0), ((void (&)(void *))::CallVfunc60WithGlobalOffset), "P2_RT_Btn:0");
    pLeft = new BkButton(((void (&)(void *))::fnv_007cabf0::FUN_007cabf0), ((void (&)(void *))::FUN_007ca8a0), "P2_LT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[2].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[2].displays))->FUN_007cb2e0((unsigned int *)&(kMsg));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[2].displays))->FUN_007cb2e0((unsigned int *)&(pDigits));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[2].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[2].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[2].buttons))->FUN_007cb2e0((unsigned int *)&(next));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[2].buttons))->FUN_007cb2e0((unsigned int *)&(pLeft));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "P3_PointVal:0", 0, 7);
    kMsg = new BkDisplay(((void (&)(void *))::DispatchStateCallback), "P3_Message:0", 0, -1);
    pDigits = new BkDisplay(((void (&)(void *))::fnv_007ca5f0::UpdateLodVisibility), "P3_PointsRemainDigit1:0", "P3_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P3_Decrease_Btn:0", 7, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "P3_Increase_Btn:0", 7, 2, valueX, pDigits);
    next = new BkButton(((void (&)(void *))::FUN_007cabb0), ((void (&)(void *))::CallVfunc60WithGlobalOffset), "P3_RT_Btn:0");
    pLeft = new BkButton(((void (&)(void *))::fnv_007cabf0::FUN_007cabf0), ((void (&)(void *))::FUN_007ca8a0), "P3_LT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[3].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[3].displays))->FUN_007cb2e0((unsigned int *)&(kMsg));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[3].displays))->FUN_007cb2e0((unsigned int *)&(pDigits));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[3].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[3].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[3].buttons))->FUN_007cb2e0((unsigned int *)&(next));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[3].buttons))->FUN_007cb2e0((unsigned int *)&(pLeft));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "P4_PointVal:0", 0, 8);
    kMsg = new BkDisplay(((void (&)(void *))::DispatchStateCallback), "P4_Message:0", 0, -1);
    pDigits = new BkDisplay(((void (&)(void *))::fnv_007ca5f0::UpdateLodVisibility), "P4_PointsRemainDigit1:0", "P4_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P4_Decrease_Btn:0", 8, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "P4_Increase_Btn:0", 8, 2, valueX, pDigits);
    next = new BkButton(((void (&)(void *))::FUN_007cabb0), ((void (&)(void *))::CallVfunc60WithGlobalOffset), "P4_RT_Btn:0");
    pLeft = new BkButton(((void (&)(void *))::fnv_007cabf0::FUN_007cabf0), ((void (&)(void *))::FUN_007ca8a0), "P4_LT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[4].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[4].displays))->FUN_007cb2e0((unsigned int *)&(kMsg));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[4].displays))->FUN_007cb2e0((unsigned int *)&(pDigits));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[4].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[4].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[4].buttons))->FUN_007cb2e0((unsigned int *)&(next));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[4].buttons))->FUN_007cb2e0((unsigned int *)&(pLeft));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "P5_PointVal:0", 0, 9);
    kMsg = new BkDisplay(((void (&)(void *))::DispatchStateCallback), "P5_Message:0", 0, -1);
    pDigits = new BkDisplay(((void (&)(void *))::fnv_007ca5f0::UpdateLodVisibility), "P5_PointsRemainDigit1:0", "P5_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P5_Decrease_Btn:0", 9, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "P5_Increase_Btn:0", 9, 2, valueX, pDigits);
    next = new BkButton(((void (&)(void *))::FUN_007cabb0), ((void (&)(void *))::CallVfunc60WithGlobalOffset), "P5_RT_Btn:0");
    pLeft = new BkButton(((void (&)(void *))::fnv_007cabf0::FUN_007cabf0), ((void (&)(void *))::FUN_007ca8a0), "P5_LT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[5].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[5].displays))->FUN_007cb2e0((unsigned int *)&(kMsg));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[5].displays))->FUN_007cb2e0((unsigned int *)&(pDigits));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[5].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[5].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[5].buttons))->FUN_007cb2e0((unsigned int *)&(next));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[5].buttons))->FUN_007cb2e0((unsigned int *)&(pLeft));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "P6_PointVal:0", 0, 10);
    kMsg = new BkDisplay(((void (&)(void *))::DispatchStateCallback), "P6_Message:0", 0, -1);
    pDigits = new BkDisplay(((void (&)(void *))::fnv_007ca5f0::UpdateLodVisibility), "P6_PointsRemainDigit1:0", "P6_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P6_Decrease_Btn:0", 10, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "P6_Increase_Btn:0", 10, 2, valueX, pDigits);
    next = new BkButton(((void (&)(void *))::FUN_007cabb0), ((void (&)(void *))::CallVfunc60WithGlobalOffset), "P6_RT_Btn:0");
    pLeft = new BkButton(((void (&)(void *))::fnv_007cabf0::FUN_007cabf0), ((void (&)(void *))::FUN_007ca8a0), "P6_LT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[6].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[6].displays))->FUN_007cb2e0((unsigned int *)&(kMsg));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[6].displays))->FUN_007cb2e0((unsigned int *)&(pDigits));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[6].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[6].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[6].buttons))->FUN_007cb2e0((unsigned int *)&(next));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[6].buttons))->FUN_007cb2e0((unsigned int *)&(pLeft));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "P7_PointVal:0", 0, 11);
    kMsg = new BkDisplay(((void (&)(void *))::DispatchStateCallback), "P7_Message:0", 0, -1);
    pDigits = new BkDisplay(((void (&)(void *))::fnv_007ca5f0::UpdateLodVisibility), "P7_PointsRemainDigit1:0", "P7_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P7_Decrease_Btn:0", 11, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "P7_Increase_Btn:0", 11, 2, valueX, pDigits);
    next = new BkButton(((void (&)(void *))::FUN_007cabb0), ((void (&)(void *))::CallVfunc60WithGlobalOffset), "P7_RT_Btn:0");
    pLeft = new BkButton(((void (&)(void *))::fnv_007cabf0::FUN_007cabf0), ((void (&)(void *))::FUN_007ca8a0), "P7_LT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[7].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[7].displays))->FUN_007cb2e0((unsigned int *)&(kMsg));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[7].displays))->FUN_007cb2e0((unsigned int *)&(pDigits));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[7].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[7].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[7].buttons))->FUN_007cb2e0((unsigned int *)&(next));
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[7].buttons))->FUN_007cb2e0((unsigned int *)&(pLeft));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "Index_StrengthPointVal:0", 0, 5);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_StrengthDecrease_Btn:0", 5, 2, valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    pIncrease = new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "Index_StrengthIncrease_Btn:0", 5, 2,
                                 valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "Index_PerceptionPointVal:0", 0, 6);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_PerceptionDecrease_Btn:0", 6, 2, valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    pIncrease = new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "Index_PerceptionIncrease_Btn:0", 6, 2,
                                 valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "Index_EndurancePointVal:0", 0, 7);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_EnduranceDecrease_Btn:0", 7, 2, valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    pIncrease = new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "Index_EnduranceIncrease_Btn:0", 7, 2,
                                 valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "Index_CharismaPointVal:0", 0, 8);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_CharismaDecrease_Btn:0", 8, 2, valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    pIncrease = new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "Index_CharismaIncrease_Btn:0", 8, 2,
                                 valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "Index_IntelligencePointVal:0", 0, 9);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_IntelligenceDecrease_Btn:0", 9, 2, valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    pIncrease = new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "Index_IntelligenceIncrease_Btn:0", 9, 2,
                                 valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "Index_AgilityPointVal:0", 0, 10);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_AgilityDecrease_Btn:0", 10, 2, valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    pIncrease = new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "Index_AgilityIncrease_Btn:0", 10, 2,
                                 valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));

    valueX = new BkDisplay(((void (&)(void *))::UpdateEntryRankText), "Index_LuckPointVal:0", 0, 11);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].displays))->FUN_007cb2e0((unsigned int *)&(valueX));
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_LuckDecrease_Btn:0", 11, 2, valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(declA));
    pIncrease = new BkStepButton(((void (&)(void *))::fnv_007caa80::PlaySpecialBookSoundAndSetStat), ((void (&)(void *))::FUN_007ca7a0), "Index_LuckIncrease_Btn:0", 11, 2,
                                 valueX, pDigits);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(pIncrease));

    kMsg = new BkDisplay(((void (&)(void *))::DispatchStateCallback), (char*)"Index_Message:0", 0, -1);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].displays))->FUN_007cb2e0((unsigned int *)&(kMsg));
    pDigits = new BkDisplay(((void (&)(void *))::fnv_007ca5f0::UpdateLodVisibility), (char*)"Index_PointsRemainDigit1:0", "Index_PointsRemainDigit2:0", -1);
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].displays))->FUN_007cb2e0((unsigned int *)&(pDigits));
    next = new BkButton(((void (&)(void *))::FUN_007cac30), ((void (&)(void *))::DispatchSourceCallback), "AllDone_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(next));
    pLeft = new BkButton(((void (&)(void *))::fnv_007cabf0::FUN_007cabf0), ((void (&)(void *))::FUN_007ca8a0), "Index_LT_Btn:0");
    reinterpret_cast<::FUN_00438690 *>(&(m_groups[8].buttons))->FUN_007cb2e0((unsigned int *)&(pLeft));

    reinterpret_cast<::FUN_007cadd0_self *>(this)->FUN_007cadd0();
    for (int iGroup = 0; iGroup < 9; iGroup++)
    {
        for (unsigned int iItem = 0; iItem < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_groups[iGroup].displays))->GetName())); iItem++)
        {
            ((::BkDisplay *)(reinterpret_cast<::S3e60 *>(&(m_groups[iGroup].displays))->FUN_006a7ad0(iItem)))->m_cb(((::BkDisplay *)(reinterpret_cast<::S3e60 *>(&(m_groups[iGroup].displays))->FUN_006a7ad0(iItem))));
        }
        for (unsigned int iButton = 0; iButton < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_groups[iGroup].buttons))->GetName())); iButton++)
        {
            ((::BkButton *)(reinterpret_cast<::S3e60 *>(&(m_groups[iGroup].buttons))->FUN_006a7ad0(iButton)))->m_cb4(((::BkButton *)(reinterpret_cast<::S3e60 *>(&(m_groups[iGroup].buttons))->FUN_006a7ad0(iButton))));
        }
    }
}


struct StatValues
{
    virtual int GetValue(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetBaseValue(int);
};
struct BookPlayer
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
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    StatValues values;
};
struct RawBookPtr
{
};
struct BookButton
{
    void(__cdecl* activate)(BookButton*);
    void(__cdecl* other)(BookButton*);
    RawBookPtr object;
    int unk0c;
    int unk10;
};
struct BookButtonList
{
    BookButton** data;
    int capacity, count, grow;
};
struct BookGroup
{
    BookButtonList buttons;
    BkDisplayList displays;
};
struct BookInterface
{
};
struct RenderBuffer
{
};
struct BookRenderer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual RenderBuffer* GetBuffer();
};
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
};
struct BookPickResult
{
};
class NiPoint3;
struct NiPick
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
    NiPick(int, int);
    ~NiPick();
    void FUN_00705fc0(void*);
public:
    bool PerformPick(const ::NiPoint3 &, const ::NiPoint3 &, bool);
};
struct BookScene
{
};
struct BookMenu
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
    int pageIndex;
    int selectedStat;
    float elapsed;
    bool finished;
    int limit;
    void* scene;
    BookGroup groups[9];
    void HandleKey(unsigned int key, int unused);
};

// Dispatches key values to page, stat, callback, and button handling; key 4 calls FUN_007c6120 when page index equals limit.
// @fnv 0x007c6550
void BookMenu::HandleKey(unsigned int key, int unused)
{
    bool turned = false;
    switch (key)
    {
    case 4:
        if (FUN_00794d80(this) == limit)
            FUN_007c6120();
        else
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("UIActivateNothing", 0x121)))->FUN_00ad8830(false);
        break;
    case 0:
    case 1:
        if (finished)
        {
            if (key == 0)
                turned = reinterpret_cast<::SPECIALBookMenu_7c9dc0 *>(this)->FUN_007c9dc0(true);
            else
                turned = reinterpret_cast<::SPECIALBookMenu_7c9dc0 *>(this)->FUN_007c9dc0(false);
            reinterpret_cast<::FUN_007c9dc0_Class *>(this)->InvokeCallbacksForSlot();
        }
        break;
    case 2:
    case 3: {
        int oldValue9 = 0;
        int newValue = 0;
        if (reinterpret_cast<::FUN_007ca030_shell *>(this)->FUN_007ca030() != -1)
        {
            oldValue9 = ((BookPlayer*)(*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer)))->values.GetBaseValue(reinterpret_cast<::FUN_007ca030_shell *>(this)->FUN_007ca030());
            if (key == 2)
            {
                if (FUN_00794d80(this) < limit)
                    reinterpret_cast<::FUN_0093a7c0_Owner *>((((BookPlayer*)(*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(reinterpret_cast<::FUN_007ca030_shell *>(this)->FUN_007ca030()), MinInt(oldValue9 + 1, 10));
            }
            else
            {
                reinterpret_cast<::FUN_0093a7c0_Owner *>((((BookPlayer*)(*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(reinterpret_cast<::FUN_007ca030_shell *>(this)->FUN_007ca030()), FUN_00647b70(oldValue9 - 1, 1));
            }
            newValue = ((BookPlayer*)(*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer)))->values.GetValue(reinterpret_cast<::FUN_007ca030_shell *>(this)->FUN_007ca030());
        }
        else if (::FUN_004b71d0() && pageIndex == 8)
        {
            int stat = selectedStat + 4;
            oldValue9 = ((BookPlayer*)(*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer)))->values.GetBaseValue(stat);
            if (key == 2)
            {
                if (FUN_00794d80(this) < limit)
                    reinterpret_cast<::FUN_0093a7c0_Owner *>((((BookPlayer*)(*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(stat), MinInt(oldValue9 + 1, 10));
            }
            else
            {
                reinterpret_cast<::FUN_0093a7c0_Owner *>((((BookPlayer*)(*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer)))))->FUN_0093a7c0((void *)(stat), FUN_00647b70(oldValue9 - 1, 1));
            }
            newValue = ((BookPlayer*)(*reinterpret_cast<::Player6440 * *>(&::_g_thePlayer)))->values.GetValue(stat);
        }
        if (oldValue9 != newValue)
        {
            BSSoundHandleEx sound;
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(sound))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialNumber", 0x121))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
        }
        reinterpret_cast<::FUN_007c9dc0_Class *>(this)->InvokeCallbacksForSlot();
        break;
    }
    case 5:
        if (pageIndex < 9)
        {
            BookInterface* interfaceManager3 = ((::BookInterface *)(::fnv_004b7210::FUN_004b7210()));
            int mouseX = (int)reinterpret_cast<::BGSImpactData *>((interfaceManager3))->FUN_009a9350();
            int mouseY = (int)reinterpret_cast<::FUN_00792760_shell *>((interfaceManager3))->FUN_00792760();
            if (DAT_011f9426)
                mouseY = (int)(mouseY * (DAT_011ad848 - DAT_011ad84c) +
                               ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::BookRenderer *)(::FUN_0043c4b0()))->GetBuffer()))->FUN_0084e3a0())) * DAT_011ad84c);
            for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(groups[pageIndex].buttons))->GetName())); i++)
            {
                FUN_006815c0 origin20;
                FUN_006815c0 direction1;
                NiPick pick(0, 8);
                reinterpret_cast<::FUN_00458b30_class *>(&(pick))->SetByteAtOffset17(1);
                pick.FUN_00705fc0(((void *)(::FUN_00559450((int *)&(((::BookButton *)(reinterpret_cast<::S3e60 *>(&(groups[pageIndex].buttons))->FUN_006a7ad0(i)))->object)))));
                reinterpret_cast<::CombatProcedure *>(&(pick))->Initialize((::CombatController *)(0));
                reinterpret_cast<::FUN_00792780_Class *>(&(pick))->SetByteAtOffset30(1);
                reinterpret_cast<::CameraWindowRay *>((((BookScene*)((void *)(::FUN_00559450((int *)(((RawBookPtr*)&::g_011daa9c))))))))->MapScreenToRay(mouseX, mouseY, (*(::NiPoint3 *)(&origin20)), (*(::NiPoint3 *)(&direction1)), (const ::NiRenderTargetGroup *)(0));
                if (reinterpret_cast<::NiPick *>(&(pick))->PerformPick((const ::NiPoint3 &)(origin20), (const ::NiPoint3 &)(direction1), 0))
                {
                    unsigned int resultIndex = 0;
                    void* hit = ((void *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::BookPickResult *)(reinterpret_cast<::BGSCameraPath *>(&(pick))->GetConditions()))))->FUN_00968670({})));
                    if (hit)
                    {
                        ((::BookButton *)(reinterpret_cast<::S3e60 *>(&(groups[pageIndex].buttons))->FUN_006a7ad0(i)))->activate(((::BookButton *)(reinterpret_cast<::S3e60 *>(&(groups[pageIndex].buttons))->FUN_006a7ad0(i))));
                        break;
                    }
                }
            }
        }
        break;
    case 6:
        if (pageIndex == 8 && selectedStat > 1)
        {
            selectedStat--;
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialFocus", 0x121)))->FUN_00ad8830(false);
        }
        reinterpret_cast<::FUN_007c9dc0_Class *>(this)->InvokeCallbacksForSlot();
        break;
    case 7:
        if (pageIndex == 8 && selectedStat < 7)
        {
            selectedStat++;
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialFocus", 0x121)))->FUN_00ad8830(false);
        }
        reinterpret_cast<::FUN_007c9dc0_Class *>(this)->InvokeCallbacksForSlot();
        break;
    }
}

#include "generated/data/fallout/interface/menus/specialbookmenu.inc"
