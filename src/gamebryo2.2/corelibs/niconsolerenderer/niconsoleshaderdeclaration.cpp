
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/DeclMap786.h"
#include "fnv/decl/FUN_00e78840_shell.h"
#include "fnv/symbols_010ee000.h"
struct NiRenderer
{
    void* m_auiShapeKeys[0x6e8 / 4];
    unsigned int m_maxStreamEntries;
};

struct BSFadeNode
{
    static void* operator new(size_t);
};


struct NiD3DVertexDeclaration
{
    void* m_vtbl;
    void* m_auiShapeKeys[0x2b / 4];
    void* m_pkVertexElements;
    void* m_pkD3DVertexDeclaration;
    char m_flag;
    virtual void vfn(int);
};

// @fnv 0x00e76700
NiD3DVertexDeclaration* FUN_00e76700(NiRenderer* renderer, unsigned int maxStreamEntries, unsigned int streamCount)
{
    if (streamCount > renderer->m_maxStreamEntries)
        return 0;

    NiD3DVertexDeclaration* pkShaderDeclaration = static_cast<NiD3DVertexDeclaration*>(BSFadeNode::operator new(0x38));
    if (pkShaderDeclaration)
    {
        reinterpret_cast<::FUN_00e78840_shell *>((pkShaderDeclaration))->Construct();
        *reinterpret_cast<void**>(pkShaderDeclaration) = &(*reinterpret_cast<void * *>(&::DAT_010ee70c));
        pkShaderDeclaration->m_auiShapeKeys[9] = 0;
        pkShaderDeclaration->m_pkVertexElements = 0;
        *reinterpret_cast<char*>(reinterpret_cast<char*>(pkShaderDeclaration) + 0x34) = 0;
        if (!((char)(reinterpret_cast<::DeclMap786 *>((pkShaderDeclaration))->FUN_00e78c60((::FUN_00e69660_shell *)(renderer), maxStreamEntries, streamCount))))
        {
            pkShaderDeclaration->vfn(1);
            pkShaderDeclaration = 0;
        }
    }
    else
    {
        pkShaderDeclaration = 0;
    }
    return pkShaderDeclaration;
}
