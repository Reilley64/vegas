// Source layout: BGSPerkEntry. PC corrections are in generate_headers.py.
#ifndef FNV_BGSPERKENTRY_H
#define FNV_BGSPERKENTRY_H

#include "layout_support.h"
class BGSPerkEntry
{
  public:
    unsigned char m_ucRank;               // +0x4
    unsigned char m_ucRegionPriority;  // +0x5
    unsigned short layoutPadding6;
    virtual bool CheckConditionFilters(unsigned int count, TESForm** subjects);
    virtual unsigned char GetFunction();
    virtual void* GetFunctionData();
    virtual void InitItem(TESForm* form);
    virtual void Save();
    virtual bool Load(TESFile* file);
    virtual void Copy(BGSPerkEntry* entry);
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void ClearData();
    virtual ~BGSPerkEntry();
};
#endif
