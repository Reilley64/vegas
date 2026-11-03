// fallout_shared/testexture.cpp: TESTexture, TESEyes, TESSkill (21 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00481230_stand.h"
#include "fnv/decl/FUN_00617ea0_shell.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040a000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_01183000.h"
#include "testexture_decls.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

// @fnv 0x0048e340
void TESTexture::InitializeComponent()
{
    if (((const char *)(::FUN_00559450((int *)&(FullNameComponent)))))
        reinterpret_cast<::TextString *>(&(FullNameComponent))->FUN_004037f0(0, 0);
}

// @fnv 0x0048e6c0
void TESTexture::ConvertTexturePath(const char* path, char* output)
{
    TaskQueueInterface::CopyStringToBuffer(output, 0x104, path);
    char* extension = FUN_0040ab30(output, '.');
    if (extension)
    {
        unsigned int prefixLength = extension - output;
        TaskQueueInterface::CopyStringToBuffer(extension, 0x104 - prefixLength, "_sk.dds");
    }
}

// @fnv 0x0048e270
TESTexture::TESTexture() : BaseFormComponent(), FullNameComponent()
{
    InitializeComponent();
}

// Reads the chunk data into a stack buffer, strips a leading backslash, and sets the texture's full name (or clears it when the chunk is empty).
// @fnv 0x0048e3d0
void TESTexture::ReadTextureData(TESTexture* texture, TESFile* file)
{
    if (!file || !texture)
        return;
    if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
    {
        char* buffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0);
        if (strlen(buffer) && buffer[0] == '\\')
        {
            unsigned int index = 0;
            for (; index < strlen(buffer); ++index)
                buffer[index] = buffer[index + 1];
        }
        reinterpret_cast<TESFullName*>(texture)->SetFullName(buffer);
    }
    else
    {
        reinterpret_cast<TESFullName*>(texture)->SetFullName(0);
    }
}

// Builds the normal-map path by replacing the extension of path with "_n.dds", stores it in result and returns the string.
// @fnv 0x0048e5b0
const char* TESTexture::NormalizeTextureFilePath(BSStringT<char>& result, const char* path)
{
    char* extension = 0;
    {
        char normalPath[260];
        char sourcePath[260];
        if (!path)
            return 0;
        TaskQueueInterface::CopyStringToBuffer(sourcePath, 260, path);
        extension = FUN_0040ab30(sourcePath, '.');
        if (!extension)
            return 0;
        *extension = 0;
        sprintf_s(normalPath, 260, "%s_n.dds", sourcePath);
        reinterpret_cast<::TextString *>(&(result))->FUN_004037f0(normalPath, 0);
        return ((const char *)(::FUN_00559450((int *)&(result))));
    }
}

struct BSS
{
    ~BSS();
};
struct TFH
{
};
struct FUN_0048e2e0
{
    virtual void v();
    BSS m;
    ~FUN_0048e2e0();
};
// @fnv 0x0048e2e0
FUN_0048e2e0::~FUN_0048e2e0()
{
    reinterpret_cast<::TESForm *>((((TFH*)this)))->ClearData();
}

// @fnv 0x0048e3b0
bool __cdecl IsChunkTypeIcon(int aChunk)
{
    if (aChunk == 0x4e4f4349)
        return true;
    return false;
}

// @fnv 0x0048e660
void __cdecl AppendNormalMapSuffix(const char* source, char* dest)
{
    TaskQueueInterface::CopyStringToBuffer(dest, 0x104, source);
    char* dot = FUN_0040ab30(dest, '.');
    if (dot != 0)
    {
        int offset = dot - dest;
        TaskQueueInterface::CopyStringToBuffer(dot, 0x104 - offset, "_n.dds");
    }
}

struct FUN_00487400_shell
{
    const char* FUN_00487400();
};

// @fnv 0x00487400
const char* FUN_00487400_shell::FUN_00487400()
{
    return "Textures";
}

struct FNStub
{
};

struct FUN_0048e580_shell : FNStub
{
    const char* FUN_0048e580(BSStringT<char>& result);
};

// @fnv 0x0048e580
const char* FUN_0048e580_shell::FUN_0048e580(BSStringT<char>& result)
{
    return TESTexture::NormalizeTextureFilePath(result, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((this))->FUN_00408da0())));
}

struct TESTexture_shell
{
    const char* FUN_0048e720();
};
// @fnv 0x0048e720
const char* TESTexture_shell::FUN_0048e720()
{
    return "Textures\\";
}

struct TESEyes
{
    void FUN_005fc1b0();
};
// @fnv 0x005fc1b0
void TESEyes::FUN_005fc1b0()
{
    ((char*)this)[0x30] = 0;
}

struct FUN_005fdc30_shell
{
    void FUN_005fdc30();
};

// @fnv 0x005fdc30
void FUN_005fdc30_shell::FUN_005fdc30()
{
    ((char*)this)[0x48] = 0;
}

struct TESSkill
{
    void FUN_00617e80();
};

// @fnv 0x00617e80
void TESSkill::FUN_00617e80()
{
    reinterpret_cast<::FUN_00617ea0_shell *>(this)->ResetState();
}

struct FUN_005eac70_shell
{
    void FUN_005eac70();
};

// Clears the bytes at offsets 0x38, 0x39 and 0x3C of this and sets the bytes at 0x3A and 0x3B to 1.
// @fnv 0x005eac70
void FUN_005eac70_shell::FUN_005eac70()
{
    *(unsigned char*)((char*)this + 0x38) = 0;
    *(unsigned char*)((char*)this + 0x39) = 0;
    *(unsigned char*)((char*)this + 0x3A) = 1;
    *(unsigned char*)((char*)this + 0x3B) = 1;
    *(unsigned char*)((char*)this + 0x3C) = 0;
}

struct FUN_00402c40_shell : public TESTexture
{
    void DestroyTexture();
};

// @fnv 0x00402c40
void FUN_00402c40_shell::DestroyTexture()
{
    reinterpret_cast<::FUN_0048e2e0 *>(this)->FUN_0048e2e0::~FUN_0048e2e0();
}

struct FUN_00487410_shell
{
    const char* GetLeafTexturePath();
};

// @fnv 0x00487410
const char* FUN_00487410_shell::GetLeafTexturePath()
{
    return "Data\\Textures\\Trees\\Leaves\\";
}

namespace fnv_0048e370 {
struct TESModel
{
    unsigned int GetModelLength() const;
};
struct FNStub
{
};
struct FUN_0048e370_shell
{
    void FUN_0048e370(unsigned int);
};
// If the model length is non-zero, calls FUN_004856f0 with the texture ID, the full name, and the model length plus one.
// @fnv 0x0048e370
void FUN_0048e370_shell::FUN_0048e370(unsigned int aeTextureID)
{
    if (((TESModel*)this)->GetModelLength())
        ::FUN_004856f0((void *)(std::uintptr_t)(aeTextureID), (void*)((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)this)))->FUN_00408da0())), (void *)(((TESModel*)this)->GetModelLength() + 1));
}
}  // namespace fnv_0048e370

namespace fnv_0048e4a0 {
struct BSStr
{
};
struct FNStub
{
};
struct FUN_0048e4a0_shell
{
    void CopyTextureName(BaseFormComponent* apCopyFC);
};
// Casts apCopyFC to TESTexture; if valid, stores its full name into the BSStr at offset 4 of this.
// @fnv 0x0048e4a0
void FUN_0048e4a0_shell::CopyTextureName(BaseFormComponent* apCopyFC)
{
    TESTexture* pcopy = dynamic_cast<TESTexture*>(apCopyFC);
    if (!pcopy)
        return;
    reinterpret_cast<::TextString *>((((BSStr*)((char*)this + 4))))->FUN_004037f0(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)pcopy)))->FUN_00408da0())), 0);
}
}  // namespace fnv_0048e4a0

namespace fnv_0048e4f0 {
struct FNStub
{
};
struct TESModel
{
    unsigned int GetModelLength();
};
struct FUN_0048e4f0_shell : TESModel
{
    bool FUN_0048e4f0(BaseFormComponent* apCompareFC);
};
// @fnv 0x0048e4f0
bool FUN_0048e4f0_shell::FUN_0048e4f0(BaseFormComponent* apCompareFC)
{
    TESTexture* pcompare = dynamic_cast<TESTexture*>(apCompareFC);
    if (!pcompare)
        return true;
    if (GetModelLength() || ((TESModel*)pcompare)->GetModelLength())
    {
        if (GetModelLength() != ((TESModel*)pcompare)->GetModelLength())
            return true;
        else if (::FUN_00404dc0(((char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)this)))->FUN_00408da0())), ((char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)pcompare)))->FUN_00408da0()))))
            return true;
    }
    return false;
}
}  // namespace fnv_0048e4f0


struct FUN_00480ef0_obj;

int __cdecl FUN_00ec43fb(FUN_00480ef0_obj* owner, int zero, char* name, char* table, int flags);

struct FUN_00480ef0_sub
{
};

struct FUN_00480ef0_obj
{
    int FUN_00401170();
    int FUN_005f0cc0();
};

// @fnv 0x00480ef0
std::intptr_t __cdecl FUN_00480ef0(FUN_00480ef0_obj* pOwner, std::intptr_t param)
{
    FUN_00480ef0_obj* found = (FUN_00480ef0_obj*)FUN_00ec43fb(pOwner, 0, (*reinterpret_cast<char (*)[]>(&::DAT_01183028)), (*reinterpret_cast<char (*)[]>(&::DAT_01183978)), 0);
    if (found == 0)
    {
        return 0;
    }
    if (param == 0)
    {
        return ((std::intptr_t)(reinterpret_cast<::FUN_00408da0_Class *>((((FUN_00480ef0_sub*)((char*)found + 0x8c))))->FUN_00408da0()));
    }
    FUN_00480ef0_obj* ref = ((::FUN_00480ef0_obj *)(reinterpret_cast<::OwnerLookupView *>((((FUN_00480ef0_obj*)param)))->FUN_00567790()));
    int valueX = 0;
    if (ref != 0 && ref->FUN_00401170() == 0x2a)
    {
        valueX = ref->FUN_005f0cc0();
    }
    return ((std::intptr_t)(reinterpret_cast<::FUN_00481230_stand *>((found))->FUN_00481230(valueX)));
}
