
#include "fnv/symbols_011a9000.h"
struct RgbaColor
{
  public:
    float r, g, b, a;
};
class NiPSysPositionModifier
{
  public:
    NiPSysPositionModifier();
    virtual void LoadBinary(struct NiStream&);
    unsigned char modifier[0x14];
};
class NiPSysEmitter : public NiPSysPositionModifier
{
  public:
    NiPSysEmitter();
    virtual void LoadBinary(struct NiStream&);
    float speed, speedVar, declination, declinationVar, planarAngle, planarAngleVar;
    RgbaColor color;
    float radius, radiusVar, lifespan, lifespanVar, unknown;
};
struct NiStream;
class NiPSysVolumeEmitter : public NiPSysEmitter
{
  public:
    virtual void LoadBinary(struct NiStream&);
    void* emitterObject;
public:
    void LinkObject(::NiStream &);
};
class NiPSysBoxEmitter : public NiPSysVolumeEmitter
{
  public:
    virtual void LoadBinary(struct NiStream&);
    float width, height, depth;
};
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadFloat(float& value)
    {
        unsigned int size = 4;
        position += read(this, &value, 4, &size, 1);
    }
};
struct NiStream
{
  public:
    unsigned char data[0x24c];
    NiBinaryStream* input;
};
