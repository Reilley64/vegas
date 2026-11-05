#pragma once

class TESPackage;
class ActorPackageData;
class TESObjectREFR;
class BGSLoadFormBuffer;
class ActorPackageContext
{
  public:
    TESPackage* pPackage;     // +0x0
    ActorPackageData* pData;  // +0x4
    TESObjectREFR* pTarget;   // +0x8
    int m_iPackageValue;      // +0xC
    float m_fPackageValue;    // +0x10
    unsigned int iFlags;      // +0x14

    // 0x008c5ef0
    void Clear();
    // 0x008c6080
    void SetPackageAndTarget(TESPackage* apPackage, TESObjectREFR* apTarget);
    // 0x008c6730
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    // 0x008c6b20
    void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);
};
