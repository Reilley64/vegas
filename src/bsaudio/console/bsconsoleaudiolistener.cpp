
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_011f6000.h"
struct NiPoint3
{
    float x, y, z;
};

struct BSAudioListener
{
    int m_unk00;
    NiPoint3 m_vContactPosition;
    NiPoint3& FUN_00aeaad0();
};

// @fnv 0x00aeaad0
NiPoint3& BSAudioListener::FUN_00aeaad0()
{
    return m_vContactPosition;
}

namespace fnv_00aeaaf0 {
struct NiPoint3
{
    float x, y, z;
};

struct BSAudioListener
{
    char pad00[0x10];
    NiPoint3 m_kVelocity;
    NiPoint3* FUN_00aeaaf0();
};

// @fnv 0x00aeaaf0
NiPoint3* BSAudioListener::FUN_00aeaaf0()
{
    return &m_kVelocity;
}
}  // namespace fnv_00aeaaf0

namespace fnv_00aeab10 {
struct NiPoint3
{
    float x, y, z;
};

struct BSAudioListener
{
    char pad00[0x1c];
    NiPoint3 m_kOrientation;
    NiPoint3& FUN_00aeab10();
};

// @fnv 0x00aeab10
NiPoint3& BSAudioListener::FUN_00aeab10()
{
    return m_kOrientation;
}
}  // namespace fnv_00aeab10

namespace fnv_00aeab30 {
struct BSAudioListener
{
    char pad[0x40];
    float m_fDistanceScale;
    void FUN_00aeab30(float afGain);
};

// @fnv 0x00aeab30
void BSAudioListener::FUN_00aeab30(float afGain)
{
    m_fDistanceScale = afGain;
}
}  // namespace fnv_00aeab30

namespace fnv_00aeab90 {
struct BSAudioListener
{
    char pad00[0x3c];
    float m_fRolloffFactor;
    void SetRolloffFactor(float afRolloffFactor);
};

// @fnv 0x00aeab90
void BSAudioListener::SetRolloffFactor(float afRolloffFactor)
{
    m_fRolloffFactor = afRolloffFactor;
}
}  // namespace fnv_00aeab90

struct MemoryManager
{
};
extern int DAT_010a3bb4;
struct BSAudioListenerShell
{
    void* m_pVtable;
    char _pad[0x40];
    unsigned int _m44;
    void* Destroy(unsigned int);
};
// Sets the vtable pointer, clears _m44, and deallocates this when a1 has bit 0 set; returns this.
// @fnv 0x00aeabb0
void* BSAudioListenerShell::Destroy(unsigned int auiFlags)
{
    m_pVtable = &DAT_010a3bb4;
    _m44 = 0;
    if (auiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}
