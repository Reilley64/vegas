// fallout_shared/sky/skytexturemanager.cpp: SkyTextureManager, SkyTask (5 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00905c30.h"
#include "fnv/decl/FUN_00c3cee0_shell.h"
#include "fnv/decl/QRequest.h"
#include "fnv/decl/fnv_00c3cf60__FUN_00c3cf60_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00af4000.h"
#include "fnv/symbols_01202000.h"
#include "skytexturemanager_decls.h"
#include "AutoMemContext.h"

// @fnv 0x0063fb70
void SkyTextureManager::LoadTextureFromPath(NiPointer<NiTexture>* texture, const char* fileName)
{
    struct TextureRequest
    {
        SkyTask* task;
        const char* path;
    } request;
    char standardizedPath[260];
    request.path = 0;
    if (fileName)
    {
        CleanPath(fileName, standardizedPath, sizeof(standardizedPath));
        request.path = standardizedPath;
    }
    request.task = new SkyTask(texture, fileName);
    ::DAT_01202d98->Unk_12(request.task);
}

// Creates a sky memory context and requests the sky texture via BSShaderManager::GetTexture using GetFileName().
// @fnv 0x0063fac0
void SkyTask::Run()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\sky\\SkyTextureManager.cpp", 50);
    BSShaderManager::GetTexture(((char *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())), true, *apTextureOutput, true, false);
}

extern unsigned int _data_011c16bc;
struct QBase
{
    virtual ~QBase();
    char p[0x2c];
    QBase(int);
};
struct FUN_0063fa10 : public QBase
{
    void* spTexture;
    FUN_0063fa10(void* tex, const char* name);
    virtual ~FUN_0063fa10();
};
// @fnv 0x0063fa10
FUN_0063fa10::FUN_0063fa10(void* apTexture, const char* name) : QBase(3)
{
    spTexture = apTexture;
    reinterpret_cast<::FUN_00c3cee0_shell *>(this)->FUN_00c3cee0((char *)(name));
    reinterpret_cast<::fnv_00c3cf60::FUN_00c3cf60_shell *>(this)->LookupFileEntryByArchive(1);
}

struct FUN_00c3d0e0_stub
{
};

struct FUN_0063fb40_shell
{
    bool GetDescription(char*, unsigned int);
};

// @fnv 0x0063fb40
bool FUN_0063fb40_shell::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    return reinterpret_cast<::QRequest *>((((FUN_00c3d0e0_stub*)this)))->FUN_00c3d0e0(apDescription, aiBufferSize, "skytask");
}

struct FUN_0063fa90_shell
{
    void* DeleteIfFlagged(unsigned int);
};
// Calls FUN_00905c30, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0063fa90
void* FUN_0063fa90_shell::DeleteIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00905c30 *>(this)->FUN_00905c30::~FUN_00905c30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
