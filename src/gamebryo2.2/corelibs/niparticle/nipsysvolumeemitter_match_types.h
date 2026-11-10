// independently confirmed PC canonical declarations. The emitter pointer at
// +0x54 is corroborated by the covered PC LinkObject disassembly.
// Direct qualified calls only; this header does not assert complete vtable slots.
#ifndef FNV_NIPSYSVOLUMEEMITTER_MATCH_TYPES_H
#define FNV_NIPSYSVOLUMEEMITTER_MATCH_TYPES_H

#include "fnv/decl/FUN_00a645b0_cls.h"
#include "layout_support.h"
#include "NiFixedString.h"
#include "NiObject.h"
class NiAVObject;
struct NiStream;
struct RgbaColor;
class NiPSysEmitter;
struct NiPSysModifier;
class NiPSysVolumeEmitter;
struct NiParticleSystem;
struct NiPSysModifier : public NiObject
{
  public:
    NiFixedString m_kName;         // +0x8, 4 bytes
    unsigned int m_uiUpdateOrder;  // +0xC, 4 bytes
    NiParticleSystem* m_pkTarget;  // +0x10, 4 bytes
    bool m_bModifierActive;        // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
struct RgbaColor
{
  public:
    float r;  // +0x0, 4 bytes
    float g;  // +0x4, 4 bytes
    float b;  // +0x8, 4 bytes
    float a;  // +0xC, 4 bytes
};
class NiPSysEmitter : public NiPSysModifier
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    float m_fEmissionSpeed;         // +0x18, 4 bytes
    float m_fSpeedVariation;        // +0x1C, 4 bytes
    float m_fEmissionDeclination;   // +0x20, 4 bytes
    float m_fDeclinationVariation;  // +0x24, 4 bytes
    float m_fEmissionPlanarAngle;   // +0x28, 4 bytes
    float m_fPlanarAngleVariation;  // +0x2C, 4 bytes
    RgbaColor m_kParticleColor;     // +0x30, 16 bytes
    float m_fEmissionRadius;        // +0x40, 4 bytes
    float m_fRadiusVariation;       // +0x44, 4 bytes
    float m_fYValue;                // +0x48, 4 bytes
    float m_fLifeSpanVariation;     // +0x4C, 4 bytes
    float m_fScale;                 // +0x50, 4 bytes
};
class NiPSysVolumeEmitter : public NiPSysEmitter
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    NiAVObject* m_pkEmitterObject;  // +0x54, 4 bytes
};
// Only out-of-line interfaces used by this unit. No NiStream layout is accessed.
struct NiStream
{
  public:
    NiObject* GetLoadedObject();
};
#endif
