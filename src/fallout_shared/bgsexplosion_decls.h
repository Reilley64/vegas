// fallout_shared/bgsexplosion_decls.h: declares TESFormInitFlag, TESObjectLIGH, CombatProcedure, BGSImpactData, EndianConvertibleData and more
#ifndef FNV_BGSEXPLOSION_DECLS_H
#define FNV_BGSEXPLOSION_DECLS_H

#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008ac890_shell.h"
#include "fnv/decl/IntFieldContainer.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005b5000.h"
#include "TESForm.h"

struct TESFormInitFlag : public TESForm
{
};

class TESObjectLIGH : public TESForm
{
};

class TESFileChunkData16
{
  public:
};

struct CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController* controller);
};

class BGSImpactData
{
  public:
    char _pdbpad_1[47];
    char Data_pad2f_pad2f_pad2f[24];
    void* m_pDecalTextureSet;
    void* m_pPrimaryImpactSound;
    void* m_pSecondaryImpactSound;
    char ImpactDecalInfo[36];
};

class EndianConvertibleData
{
  public:
};
class TESSound : public TESForm
{
};
class BGSImpactData;
class BGSImpactDataSet : public TESForm
{
public:
    ::BGSImpactData *GetImpactDataForMaterial(int);
};

class EffectSetting
{
  public:
    unsigned char bgsexplosion_padding[0x80];
    TESSound* bgsexplosion_castSound;
    TESSound* bgsexplosion_boltSound;
    TESSound* GetCastSound();
    void SetBoltSound(TESSound* sound);
};

class MagicItem;

class MagicCaster
{
  public:
};

class PlayerMover
{
  public:
    unsigned int GetActorStateFlags();
};

#endif
