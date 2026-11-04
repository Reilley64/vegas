// gamebryo2.2/corelibs/niparticle/nipsysplanarcollider_decls.h: declares NiBinaryStream, NiStream, NiColor
#ifndef NIPSYSPLANARCOLLIDER_DECLS_H
#define NIPSYSPLANARCOLLIDER_DECLS_H

#include <windows.h>
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "nipsysplanarcollider_types_NiPSysPlanarCollider.h"
struct NiBinaryStream
{
    unsigned unused;
    unsigned position;
    unsigned(__cdecl* read)(NiBinaryStream*, void*, unsigned, unsigned*, unsigned);
    void Read(void* buffer, unsigned bytes)
    {
        unsigned size;
        position += read(this, buffer, bytes, (size = bytes, &size), 1);
    }
};
class NiObject;
class NiStream
{
  public:
    char padding[0x24c];
    NiBinaryStream* input;
public:
    ::NiObject *GetLoadedObject();
};
class NiStream;
class NiColor
{
  public:
    void LoadBinary(NiStream&);
public:
    void SaveBinary(::NiStream &);
};
inline void PlanarReadFloat(NiStream& stream, float& value)
{
    stream.input->Read(&value, 4);
}
#endif
