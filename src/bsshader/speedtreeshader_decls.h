// bsshader/speedtreeshader_decls.h: declares NiD3DShaderConstantMap, SpeedTreeLeafShaderConstantMapSetup
#ifndef SPEEDTREESHADER_DECLS_H
#define SPEEDTREESHADER_DECLS_H

#include "fnv/symbols_01200000.h"
class NiD3DShaderConstantMap
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual unsigned int vfn_08(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*,
                                unsigned int, unsigned int, const void*, bool);
};
class SpeedTreeLeafShaderConstantMapSetup
{
  public:
    static void ConfigureShaderConstantMap(NiD3DShaderConstantMap*, int);
};
#endif
