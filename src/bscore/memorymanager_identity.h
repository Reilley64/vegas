// bscore/memorymanager_identity.h: declares TESActorBase, Actor, TESFile, BSExtraData, BaseExtraList and more
#ifndef FNV_MEMORYMANAGER_IDENTITY_H
#define FNV_MEMORYMANAGER_IDENTITY_H


#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/symbols_00401000.h"
class PerkEntryConditionSet;

enum SEX
{
    SEX_MALE = 0,
    SEX_FEMALE = 1
};

enum SEX;
class TESActorBase
{
  public:
public:
    ::SEX GetSex() const;
};

class Actor
{
  public:
    TESActorBase* GetActorBase();
    SEX GetSex();
};


class TESFile
{
  public:
    unsigned char layoutPadding0[0x420];
    char* m_pDecompressedFormBuffer;
    unsigned int m_uiAuxBufferSize;
};

class BSExtraData
{
  public:
    unsigned char layoutPadding0[12];
};

class BaseExtraList
{
  public:
};

class ExtraHealth : public BSExtraData
{
  public:
    float fHealthPercent;
    ExtraHealth(float health);
};

class ExtraDataList : public BaseExtraList
{
  public:
    void SetExtraHealth(float health);
};

class TESQuest
{
  public:
    PerkEntryConditionSet* GetConditions();
};

class TESActorBaseData
{
  public:
    unsigned char layoutPadding0[4];
    unsigned int m_uiActorFlags;
    bool GetFlag(unsigned int flag) const;
};

#endif
