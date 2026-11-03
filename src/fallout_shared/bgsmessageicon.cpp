// fallout_shared/bgsmessageicon.cpp: BGSMessageIcon, TESModelTextureSwap, ThisStandIn (11 functions)

#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00402d50.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a470_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "bgsmessageicon_decls.h"
// @fnv 0x0047a220
void BGSMessageIcon::ClearComponent()
{
    reinterpret_cast<::FUN_00402d50 *>(&(Icon))->FUN_00402d50::~FUN_00402d50();
}

// @fnv 0x0048a3d0
TESModelTextureSwap::TESModelTextureSwap()
{
    reinterpret_cast<::FUN_0048a470_shell *>(this)->FUN_0048a470();
}

struct FUN_0047a130 : public BaseFormComponent
{
    FUN_0047a130();
    void InitIcon();
    TESIcon Icon;
};
// Constructs the component and calls InitIcon to initialize it.
// @fnv 0x0047a130
FUN_0047a130::FUN_0047a130()
{
    InitIcon();
}

struct TESFile;
struct NiPoint3Stub
{
    float x, y, z;
};
struct TeleportableReference
{
};
struct TexHelper
{
};
// @fnv 0x0047a290
void __cdecl FUN_0047a290(TeleportableReference* pObject, TESFile* pFile)
{
    ::TESTexture::ReadTextureData((TESTexture*)&(*(const ::NiPoint3Stub *)(reinterpret_cast<::BaseProcess *>((pObject))->GetCurrentProcessData())), pFile);
}

struct FUN_0047a380_shell : public BGSMessageIcon
{
    void FUN_0047a380(char*);
};

class TESFullName
{
  public:
    void SetFullName(const char*);
};

// @fnv 0x0047a380
void FUN_0047a380_shell::FUN_0047a380(char* apTexture)
{
    reinterpret_cast<TESFullName*>(&this->Icon)->SetFullName(apTexture);
}

struct FUN_0047a1a0 : BaseFormComponent
{
    TESIcon Icon;
    ~FUN_0047a1a0();
};
// @fnv 0x0047a1a0
FUN_0047a1a0::~FUN_0047a1a0()
{
    ((BGSMessageIcon*)this)->ClearComponent();
}

struct FNStub
{
};
struct BGSTESTexture
{
    unsigned int GetModelLength() const;
};
struct FUN_0047a240_shell : ::BGSMessageIcon
{
    void FUN_0047a240(std::uintptr_t);
};
// @fnv 0x0047a240
void FUN_0047a240_shell::FUN_0047a240(std::uintptr_t a1)
{
    if (((BGSTESTexture*)&this->Icon)->GetModelLength())
        ::FUN_004856f0((void *)(a1), (void*)((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(((FNStub*)&this->Icon)))->FUN_00408da0())),
                     (void *)(((BGSTESTexture*)&this->Icon)->GetModelLength() + 1));
}

namespace fnv_0047a2b0 {
struct FUN_0047a300_shell
{
    char* FUN_0047a300();
};
struct FUN_0047a380_shell
{
};
struct FUN_0047a2b0_shell
{
    void FUN_0047a2b0(BaseFormComponent*);
};
// @fnv 0x0047a2b0
void FUN_0047a2b0_shell::FUN_0047a2b0(BaseFormComponent* component)
{
    BGSMessageIcon* msgIcon = dynamic_cast<BGSMessageIcon*>(component);
    if (!msgIcon)
        return;
    reinterpret_cast<::FUN_0047a380_shell *>((((FUN_0047a380_shell*)this)))->FUN_0047a380(((FUN_0047a300_shell*)msgIcon)->FUN_0047a300());
}
}  // namespace fnv_0047a2b0

struct Caller300
{
    const char* FUN_0047a300();
};
struct ThisStandIn
{
    bool FUN_0047a320(BaseFormComponent*);
};
// @fnv 0x0047a320
bool ThisStandIn::FUN_0047a320(BaseFormComponent* apComponent)
{
    BGSMessageIcon* icon = dynamic_cast<BGSMessageIcon*>(apComponent);
    if (!icon)
        return true;
    if (::FUN_00404dc0(((Caller300*)this)->FUN_0047a300(), ((Caller300*)icon)->FUN_0047a300()))
        return true;
    return false;
}

namespace fnv_0047a300 {
struct FNStub
{
};

struct FUN_0047a300_shell : FNStub
{
    const char* FUN_0047a300();
};

// @fnv 0x0047a300
const char* FUN_0047a300_shell::FUN_0047a300()
{
    return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<FNStub*>(reinterpret_cast<char*>(this) + 4)))->FUN_00408da0()));
}
}  // namespace fnv_0047a300

// InitIcon - /Od module.
//
// The owning class is FUN_0047a130 : public BaseFormComponent, and BaseFormComponent
// is a 4-byte polymorphic base (its vptr sits at offset 0).  FUN_0047a130 therefore
// holds its TESIcon member at offset 4.
//
// The original body is a virtual call on that member, dispatched through slot 0 of
// the member's vtable, with the member address (this + 4) passed as the callee's
// 'this' pointer in ECX:
//
//   mov  ecx, [ebp-4]      ; this
//   add  ecx, 4            ; &this->Icon
//   mov  eax, [ebp-4]      ; this
//   mov  edx, [eax+4]      ; the member's vptr
//   mov  eax, [edx]        ; vtable slot 0
//   call eax
// @fnv 0x0047a200
void FUN_0047a130::InitIcon()
{
    Icon.Init();
}
