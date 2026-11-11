// gamebryo2.2/corelibs/niconsolerenderer/nid3ddefaultshader_decls.h: declares NiFixedString, NiGlobalStringTable, NiD3DShader
#ifndef NID3DDEFAULTSHADER_DECLS_H
#define NID3DDEFAULTSHADER_DECLS_H
#include <windows.h>
#include "fnv/symbols_0109b000.h"
#pragma intrinsic(_ReadWriteBarrier)
class NiFixedString
{
  public:
    char* m_handle;
};
struct NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
extern void* const DAT_010eecac[];
class NiD3DShader
{
  public:
    NiD3DShader();
    void* const* vtable;
    unsigned int referenceCount;
    NiFixedString name;
    unsigned char padding0c[0x4];
    bool unk10;
    unsigned char pad11[0xf];
    bool bestImplementation;
    unsigned char padding21[3];
    bool usesRenderState;
    bool usesLightState;
    unsigned char padding26[2];
    void* shaderDeclaration;
    void* renderStateGroup;
    void* pixelConstantMap;
    void* vertexConstantMap;
    unsigned int currentPass;
    unsigned char padding3c[20];
};
class NiD3DDefaultShader : public NiD3DShader
{
  public:
    NiD3DDefaultShader();
    unsigned int field50, field54, field58;
};
#endif
