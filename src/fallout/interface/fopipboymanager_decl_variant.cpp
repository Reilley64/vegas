
// src/fallout/interface/fopipboymanager_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x007f8720: the skeleton of src/fallout/interface/fopipboymanager.cpp
// with declarations corrected to what the original code does (fopipboymanager_decls.h: FOPipboyManager += bool FUN_007f8720(bool press, bool release, float& x, float& y, int& button); NiAVObject* FUN_007fa950();; fopipboymanager_decls.h: class NiPoint3 { public: float x,y,z; NiPoint3(flo -> class NiPoint3 { public: float x,y,z; NiPoint3(flo; fopipboymanager_de). Move the function to its real unit once
// that unit declares it this way.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/CameraWindowRay.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DecalStub.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00444020_Class.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_00458b30_class.h"
#include "fnv/decl/FUN_004bc280_S.h"
#include "fnv/decl/FUN_004dc540_shell.h"
#include "fnv/decl/FUN_0050c630_helper.h"
#include "fnv/decl/FUN_006b0570_shell.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_00792780_Class.h"
#include "fnv/decl/FUN_007f7fb0_Class.h"
#include "fnv/decl/FUN_007f7fe0_cls.h"
#include "fnv/decl/FUN_00810530_c.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00965580_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ba8ab0_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_0050c660__FUN_0050c660_shell.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_0050c000.h"
#include "fnv/symbols_0050d000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fopipboymanager_decls_decl_fopipboymanager.h"

class NiPoint2
{
  public:
    float x, y;
};
class NiPoint3;
class NiPick
{
  public:
    class Record
    {
      public:
        NiPointer<NiAVObject> object;
        NiPointer<NiNode> proxy;
        NiPoint3 intersect;
        float distance;
        unsigned short triangle, vertices[3];
        float texture[2];
        NiPoint3 normal;
        float color[4];
        NiAVObject* FUN_00458b50();
    };
    class Results
    {
      public:
        virtual ~Results();
        Record** data;
        unsigned short capacity, size, effective, grow;
        unsigned int valid;
    };
    int pickType, sortType, intersectType, coordinateType;
    bool frontOnly, observeCull;
    NiPointer<NiAVObject> root;
    Results results;
    Record* last;
    bool returnTexture, returnNormal, smoothNormal, returnColor;
    NiPick(int, int);
    ~NiPick();
public:
    void FUN_00705fc0(void *);
public:
    bool PerformPick(const ::NiPoint3 &, const ::NiPoint3 &, bool);
};
class NiCamera
{
  public:
};
class SceneGraph
{
  public:
};
extern int DAT_011a0ba0;
// @fnv 0x007f8720
bool FOPipboyManager::FUN_007f8720(bool press, bool release, float& x, float& y, int& button)
{
    bool result = false;
    Interface* ui = ((::Interface *)(::fnv_004b7210::FUN_004b7210()));
    if (!((::NiAVObject *)(reinterpret_cast<::StrOwner *>(this)->FUN_007fa950())) || !(NiAVObject*)m_cPipBoyButtonAvailability[0] ||
        !(NiAVObject*)m_cPipBoyButtonAvailability[1] || !(NiAVObject*)m_cPipBoyButtonAvailability[2])
        return false;
    if (FUN_007178a0() && ::InterfaceManager::IsInterfaceMenuActive() && (NiNode*)m_pPipBoyObject0)
    {
        NiPoint3 origin;
        NiPoint3 c;
        NiPick b(0, 8);
        reinterpret_cast<::FUN_00458b30_class *>(&(b))->SetByteAtOffset17(true);
        reinterpret_cast<::NiPick *>(&(b))->FUN_00705fc0(((::NiAVObject *)(reinterpret_cast<::StrOwner *>(this)->FUN_007fa950())));
        reinterpret_cast<::CombatProcedure *>(&(b))->Initialize((::CombatController *)(0));
        reinterpret_cast<::FUN_00792780_Class *>(&(b))->SetByteAtOffset30(true);
        NiCamera* a = ((::NiCamera *)(reinterpret_cast<::BSFaceGenNiNode *>((((::SceneGraph *)(::FUN_0045c670()))))->GetAnimationData()));
        reinterpret_cast<::CameraWindowRay *>((a))->MapScreenToRay((int)reinterpret_cast<::BGSImpactData *>((ui))->FUN_009a9350(), (int)reinterpret_cast<::FUN_00792760_shell *>((ui))->FUN_00792760(), origin, c, (const ::NiRenderTargetGroup *)(false));
        if (reinterpret_cast<::NiPick *>(&(b))->PerformPick(origin, c, false))
        {
            unsigned int firstIndex = 0;
            NiPick::Record* hit = ((::NiPick::Record *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::NiPick::Results *)(reinterpret_cast<::BGSCameraPath *>(&(b))->GetConditions()))))->FUN_00968670(firstIndex)));
            if (hit && hit->FUN_00458b50() == ((::NiAVObject *)(reinterpret_cast<::StrOwner *>(this)->FUN_007fa950())))
            {
                NiPoint2 horizontal = *((const ::NiPoint2 *)(reinterpret_cast<::BGSCameraPath *>((hit))->GetShotList()));
                float scale = ((double)(::FUN_00706e20()));
                float uv = scale * (double)1.333333f;
                x = horizontal.x * uv;
                y = horizontal.y * scale;
                result = true;
            }
        }
        if (press || release)
        {
            int selected = -1;
            reinterpret_cast<::CombatProcedure *>(&(b))->Initialize((::CombatController *)(0));
            reinterpret_cast<::FUN_00792780_Class *>(&(b))->SetByteAtOffset30(false);
            for (int i = 0; i < 3; i++)
            {
                reinterpret_cast<::NiPick *>(&(b))->FUN_00705fc0(m_cPipBoyButtonAvailability[i]);
                reinterpret_cast<::CameraWindowRay *>((((::NiCamera *)(reinterpret_cast<::BSFaceGenNiNode *>((((::SceneGraph *)(::FUN_0045c670()))))->GetAnimationData()))))->MapScreenToRay((int)reinterpret_cast<::BGSImpactData *>((ui))->FUN_009a9350(), (int)reinterpret_cast<::FUN_00792760_shell *>((ui))->FUN_00792760(), origin,
                                                               c, (const ::NiRenderTargetGroup *)(false));
                if (reinterpret_cast<::NiPick *>(&(b))->PerformPick(origin, c, false))
                {
                    unsigned int hit = 0;
                    NiPick::Record* hitIndex = ((::NiPick::Record *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::NiPick::Results *)(reinterpret_cast<::BGSCameraPath *>(&(b))->GetConditions()))))->FUN_00968670(hit)));
                    if (hitIndex)
                    {
                        if (press)
                            DAT_011a0ba0 = i;
                        else
                            selected = i;
                    }
                }
            }
            if (release && selected == DAT_011a0ba0)
            {
                button = selected + 1;
                DAT_011a0ba0 = -1;
            }
        }
    }
    return result;
}

#include "generated/data/fallout/interface/fopipboymanager_decl_variant.inc"
