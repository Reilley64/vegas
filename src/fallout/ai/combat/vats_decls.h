// fallout/ai/combat/vats_decls.h: declares Animation, TimeGlobal, PlayerCharacter, CameraPathManager, BGSCameraShot and more
#ifndef FNV_VATS_DECLS_H
#define FNV_VATS_DECLS_H


#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_0058d630_shell.h"
#include "fnv/decl/FUN_00639aa0_shell.h"
#include "fnv/decl/FUN_0088b030_shell.h"
#include "fnv/decl/FUN_0093e840_shell.h"
#include "fnv/decl/FUN_0095f530_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "layout_support.h"

class VATSCommand;
class Projectile;
class TESIdleForm;
class ImageSpaceModifierInstanceForm;
class ImageSpaceModifierInstanceRB;
class ShadowSceneLight;

class Animation
{
  public:
public:
    void SpecialIdleFree(bool, bool);
};

class TimeGlobal
{
  public:
};

// PC receiver view for the legacy VATS::Update identity. Its caller passes
// PlayerCharacter; the last write is at +0xE18 in the PC player layout.
class Animation;
class PlayerCharacter
{
  public:
    unsigned char layoutPadding0[0xE18];
    float fVATSTimer;
    unsigned char layoutPaddingE1C[0x34];
public:
    ::Animation *GetAnimation(bool) const;
};

class CameraPathManager
{
  public:
};
class InventoryStackRecord
{
  public:
};
class BGSCameraShot
{
  public:
    void ResetCameraShot();
    char _pdbpad_1[55];
    char Data_pad37_pad37_pad37[40];
    char spLocationNode_pad5f_pad5f_pad5f[4];
    char spTargetNode_pad63_pad63_pad63[4];
    void* m_pReference;
    char m_spPositionNode[4];
    char m_pSceneObject[4];
    char m_bUpdateNodePosition;
    bool m_bFlag74;
    bool m_bFlag75;
    char _pdbpad_77[1];
};
class NiPoint3Interpolator
{
  public:
    void CreateObject(int mode, bool force);
};

class VATS
{
  public:
    BSSimpleList<VATSCommand*> m_kCommandList;
    int eMode;
    BSSimpleList<BGSCameraShot*>* m_pCameraShotList;
    BGSCameraShot* pCamera;
    float m_fCameraTime;
    float m_fCameraDuration;
    Projectile* m_pSource;
    Projectile* m_pTargetProjectile;
    TESIdleForm* m_pIdleForm;
    ImageSpaceModifierInstanceForm* m_pImagespaceModifier;
    ImageSpaceModifierInstanceRB* pTransitionImagespaceMod;
    bool bIsPlayer;
    unsigned char layoutPadding31[3];
    NiPointer<ShadowSceneLight> m_spShadowSceneLight;
    bool m_bShadowLightEnabled;
    unsigned char layoutPadding39[3];
    int m_iShadowLightState;
    TESBoundObject* m_pCurrentWeaponObject;
    ExtraDataList* m_pWeaponExtraData;
    void Update(int mode, bool force);
    float GetModeTimeMultiplier();
public:
    void FUN_009c8950(bool, bool);
};

union SETTING_VALUE
{
  public:
    const char* str;
    int i;
    unsigned int u;
    float f;
    bool b;
    char c;
    unsigned char h;
};
class SettingT_GameSettingCollection_
{
  public:
};
class hkpCharacterContext
{
  public:
};


#endif
