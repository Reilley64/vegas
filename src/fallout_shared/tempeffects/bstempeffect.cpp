// fallout_shared/tempeffects/bstempeffect.cpp: SandBoxActorPackageData, BSTempEffect (14 functions)

#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011de000.h"
#include "bstempeffect_decls.h"

// @fnv 0x009f3a30
PTYPE SandBoxActorPackageData::GetPackageType()
{
    return PTYPE_SANDBOX;
}

// @fnv 0x006827b0
BSTempEffect::BSTempEffect(TESObjectCELL* cell, float lifetime)
{
    pCell = cell;
    m_fParticleParameter5 = lifetime;
    m_fFirstFloatValue = 0.0f;
    bInitialized = false;
}

struct FUN_00682860_shell : public BSTempEffect
{
    void FUN_00682860();
};

extern const void* vftable_BSTempEffect;

// Resets the vtable pointer and fields at offsets 0x8, 0xc, 0x10 and 0x14, then calls FUN_00a5d3d0 on this.
// @fnv 0x00682860
void FUN_00682860_shell::FUN_00682860()
{
    *(const void**)this = &vftable_BSTempEffect;
    *(int*)((char*)this + 0xc) = 0;
    this->m_fParticleParameter5 = 0.0f;
    this->m_fFirstFloatValue = 0.0f;
    *(char*)&this->bInitialized = 0;
    reinterpret_cast<class ::FUN_00a5d3d0 *>((this))->FUN_00a5d3d0::~FUN_00a5d3d0();
}

struct BGSEntryPointFunctionData;
struct TESFile;
struct TESForm;
struct TESLevItem;
struct FUN_009cbb10_shell : public BSTempEffect
{
    int FUN_009cbb10();
};

// @fnv 0x009cbb10
int FUN_009cbb10_shell::FUN_009cbb10()
{
    return 3;
}


struct FUN_00682800_shell
{
    const char* const* GetRTTI() const;
};

// @fnv 0x00682800
const char* const* FUN_00682800_shell::GetRTTI() const
{
    return &(*reinterpret_cast<const char *const *>(&::g_011d6a44));
}

struct FUN_006828e0_shell
{
    unsigned short FUN_006828e0();
};

// @fnv 0x006828e0
unsigned short FUN_006828e0_shell::FUN_006828e0()
{
    unsigned short usSize = 0;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    return usSize;
}

struct BGSLoadFormBuffer
{
};

struct FUN_00682a80_shell
{
    void FUN_00682a80(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x00682a80
void FUN_00682a80_shell::FUN_00682a80(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 8)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x10)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x14)), 1);
}

struct FUN_00682810_shell
{
    void FUN_00682810();
};

// @fnv 0x00682810
void FUN_00682810_shell::FUN_00682810()
{
    *(char*)((char*)this + 0x14) = 1;
}

namespace fnv_00682830 {
struct FUN_00682860_shell
{
};
struct FUN_00682830_shell : BSTempEffect
{
    void* FUN_00682830(unsigned int);
};
// @fnv 0x00682830
void* FUN_00682830_shell::FUN_00682830(unsigned int flags)
{
    reinterpret_cast<::FUN_00682860_shell *>((reinterpret_cast<FUN_00682860_shell*>(this)))->FUN_00682860();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x18);
    return this;
}
}  // namespace fnv_00682830

struct FUN_006828a0_shell
{
    char _00[8];
    float m_fParticleParameter5;
    char _0c[4];
    float m_fFirstFloatValue;
    bool FUN_006828a0(float afTimeDelta);
};
// @fnv 0x006828a0
bool FUN_006828a0_shell::FUN_006828a0(float afTimeDelta)
{
    m_fFirstFloatValue += afTimeDelta;
    if (m_fFirstFloatValue > m_fParticleParameter5)
        return false;
    return true;
}

struct BGSSaveFormBuffer
{
};
struct Holder00682a30
{
    void FUN_00682a30(BGSSaveFormBuffer*);
};
// Writes the 4-byte fields at offsets 8 and 16 and the 1-byte field at offset 20 of this object into apSaveGameBuffer.
// @fnv 0x00682a30
void Holder00682a30::FUN_00682a30(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 8), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 16), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((void*)((char*)this + 20), 1, 0);
}

struct SoundH
{
    void* pBase;
    unsigned int m_uiReadOffset;
    void* pCell;
};

struct TESSaveLoadGame
{
};


struct FUN_00682920_shell : ::BSTempEffect
{
    void FUN_00682920();
};

// @fnv 0x00682920
void FUN_00682920_shell::FUN_00682920()
{
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0((char*)&this->m_fParticleParameter5, 4);
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0((char*)&this->m_fFirstFloatValue, 4);
    SoundH* apSaveGameBuffer = 0;
    if (*(void**)&this->pCell)
    {
        apSaveGameBuffer = (SoundH*)((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((SoundH*)*(void**)&this->pCell)))->FUN_0084e3a0()));
    }
    reinterpret_cast<::C857A10Buffer *>((g_TESSaveLoadGame))->FUN_00857a10((const unsigned int *)((std::intptr_t)&apSaveGameBuffer), 4);
}

class NiNode;

class TESForm
{
  public:
    virtual ~TESForm()
    {}
};

class TESObjectCELL : public TESForm
{
  public:
};

struct FUN_00682990_LoadShim
{
};

struct FUN_00682990_SGLShim
{
};


struct FUN_00682990_shell : ::BSTempEffect
{
    bool FUN_00682990();
};

// @fnv 0x00682990
// @fnv 0x00682990
bool FUN_00682990_shell::FUN_00682990()
{
    bool result = true;
    unsigned int formID;

    reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<FUN_00682990_LoadShim*>((*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(reinterpret_cast<void*>(reinterpret_cast<char*>(&this->m_fParticleParameter5)), 4);
    reinterpret_cast<::FUN_008579e0_shell *>((reinterpret_cast<FUN_00682990_LoadShim*>((*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(reinterpret_cast<void*>(reinterpret_cast<char*>(&this->m_fFirstFloatValue)), 4);
    reinterpret_cast<::FUN_00857aa0 *>((reinterpret_cast<FUN_00682990_SGLShim*>((*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->ValidateFormIDArray(&formID, 4);

    this->pCell =
        dynamic_cast<TESObjectCELL*>(FUN_004839c0(formID));

    if (!this->pCell ||
        !reinterpret_cast<::FUN_00545cb0_shell *>(((this->pCell)))->FUN_00545cb0())
        result = false;

    return result;
}
