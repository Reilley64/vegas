// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NORMAL_H
#define FNV_NORMAL_H

#include "layout_support.h"
class Normal;
class PosGen;
class Random;
class SymGen;
class Random
{
  public:
    virtual ~Random();
    virtual float Next();
    virtual char* Name();
    virtual float Density(float value) const;
    static float Raw();
    static void Set(double value);
    // Random
    // void __cdecl Random::*(double)
    // double __cdecl Random::*()
    // void __cdecl Random::*(long)
    // long __cdecl Random::*()
    // float __cdecl Random::*()
    // Random& __cdecl Random::*(const Random&)
    // void __cdecl Random::*()
};
class PosGen : public Random
{
  public:
    PosGen();
    virtual ~PosGen();
    void Build(bool ready);
    // base Random at +0x0, size 4
    float xi;           // +0x4, 4 bytes
    float* sx;          // +0x8, 4 bytes
    float* m_pYValues;  // +0xC, 4 bytes
    bool NotReady;      // +0x10, 1 bytes
    unsigned char layoutPadding11[3];
    // PosGen
    // void __cdecl PosGen::*()
    // char* __cdecl PosGen::*()
    // float __cdecl PosGen::*()
    // void __cdecl PosGen::*(bool)
    // PosGen& __cdecl PosGen::*(const PosGen&)
    // void __cdecl PosGen::*()
};
class SymGen : public PosGen
{
  public:
    virtual ~SymGen();
    // base PosGen at +0x0, size 20
    // char* __cdecl SymGen::*()
    // float __cdecl SymGen::*()
    // SymGen
    // void __cdecl SymGen::*()
    // SymGen& __cdecl SymGen::*(const SymGen&)
    // void __cdecl SymGen::*()
};
class Normal : public SymGen
{
  public:
    Normal();
    virtual ~Normal();
    float Density(float value) const;
    // base SymGen at +0x0, size 20
    // Normal
    // void __cdecl Normal::*()
    // char* __cdecl Normal::*()
    // float __cdecl Normal::*(float)
    // Normal& __cdecl Normal::*(const Normal&)
    // void __cdecl Normal::*()
};
#endif
