
// src/fallout_shared/pathfinding/pathingrequestsafestraightline.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestsafestraightline.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_004036b0_Class.h"
#include "fnv/decl/FUN_006d3b20_Class.h"
#include "fnv/decl/fnv_006e5f00__PathingRequestClosePoint.h"
#include "fnv/decl/fnv_006e5f50__PathingRequestClosePoint.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00aa1000.h"
struct PathingRequestSafeStraightLine
{
    virtual ~PathingRequestSafeStraightLine();
    void* FUN_006e5fd0(unsigned int flags);
};


// @fnv 0x006e5fd0
void* PathingRequestSafeStraightLine::FUN_006e5fd0(unsigned int flags)
{
    reinterpret_cast<::FUN_006d3b20_Class *>((this))->DestroyPathingRequest();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xbc);
    return this;
}

struct FUN_006e60c0_shell
{
    void FUN_006e60c0(int);
};

// @fnv 0x006e60c0
void FUN_006e60c0_shell::FUN_006e60c0(int a1)
{
    *(int*)((char*)this + 0xb8) = *(int*)((char*)this + 0xb8);
}

struct BGSSaveFormBuffer
{
};
struct Host_006e60e0
{
    void SaveToBuffer(BGSSaveFormBuffer*);
};
// @fnv 0x006e60e0
void Host_006e60e0::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::fnv_006e5f00::PathingRequestClosePoint *>(this)->FUN_006e5f00((::fnv_006e5f00::BGSSaveFormBuffer *)(apSaveGameBuffer));
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)((char*)this + 0xb8)), 0);
}

struct BGSLoadFormBuffer
{
};
struct FUN_006e5f50_shell
{
};
struct FUN_006e6110_shell : public PathingRequestSafeStraightLine
{
    void FUN_006e6110(BGSLoadFormBuffer* buffer);
};
// Calls the base load routine on buffer, then loads the field at offset 0xb8 from the buffer.
// @fnv 0x006e6110
void FUN_006e6110_shell::FUN_006e6110(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_006e5f50::PathingRequestClosePoint *>((reinterpret_cast<FUN_006e5f50_shell*>(this)))->FUN_006e5f50((::fnv_006e5f50::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)((char*)this + 0xb8));
}

struct PathingRequest
{
    void CopyTo(PathingRequest*);
};
struct FUN_006e6080_cls
{
    char _pad[0xB8];
    int pTarget;
    void FUN_006e6080(PathingRequest* apDest);
};
// @fnv 0x006e6080
void FUN_006e6080_cls::FUN_006e6080(PathingRequest* apDest)
{
    PathingRequestSafeStraightLine* pdest = (PathingRequestSafeStraightLine*)apDest;
    ((PathingRequest*)this)->CopyTo((PathingRequest*)pdest);
    ((FUN_006e60c0_shell*)pdest)->FUN_006e60c0(this->pTarget);
}

struct S_004036b0
{
};
struct FUN_006e3fb0_base
{
    FUN_006e3fb0_base(int);
    virtual ~FUN_006e3fb0_base();
};
struct FUN_006e6010 : FUN_006e3fb0_base
{
    char _pad[0xB4];
    int pTarget;
    FUN_006e6010(std::intptr_t ai);
    ~FUN_006e6010();
};
// Constructs the base with ai and stores the result of FUN_004036b0 called on ai into pTarget.
// @fnv 0x006e6010
FUN_006e6010::FUN_006e6010(std::intptr_t ai) : FUN_006e3fb0_base(ai)
{
    pTarget = ((int)(reinterpret_cast<::FUN_004036b0_Class *>((((S_004036b0*)(void*)ai)))->FUN_004036b0()));
}

class TESForm
{
  public:
    virtual ~TESForm();
};
class TESObjectREFR : public TESForm
{
};
struct Holder_006e6140
{
    void ResolveReference(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x006e6140
void Holder_006e6140::ResolveReference(BGSLoadFormBuffer* apLoadGameBuffer)
{
    *(TESObjectREFR**)((char*)this + 0xb8) = (*(TESObjectREFR**)((char*)this + 0xb8))
                                                 ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0(
                                                       (unsigned int)(std::uintptr_t)*(TESObjectREFR**)((char*)this + 0xb8)))
                                                 : 0;
}
