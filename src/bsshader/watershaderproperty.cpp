
// src/bsshader/watershaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/watershaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <windows.h>
#include "fnv/decl/CopyObject.h"
#include "fnv/water_shader_property.h"
struct B6AB20Map
{
    virtual ~B6AB20Map();
};

struct B6AB20CloningProcess
{
    B6AB20CloningProcess(unsigned int uiHashSize);
    ~B6AB20CloningProcess()
    {
        delete m_pCloneMap;
        delete m_pProcessMap;
    }

    B6AB20Map* m_pCloneMap;
    B6AB20Map* m_pProcessMap;
    int m_eCloneCopyMode;
    int m_bExactType;
};

struct B6AB20Object
{
    void CloneToTarget(void* pkTarget);
};

// Creates a cloning process with hash size 0x101 and runs Process on pkTarget with it.
// @fnv 0x00b6ab20
void B6AB20Object::CloneToTarget(void* pkTarget)
{
    B6AB20CloningProcess kCloning(0x101);
    reinterpret_cast<::CopyObject *>(this)->FUN_00b6a6c0((::CopyObject *)(pkTarget), (std::intptr_t)&(kCloning));
}


// Initialises the object's fields to their default values: flags, floats, counters and the two integer fields set to 0x11 and 0xe.
// @fnv 0x00b6abb0
FUN_00b6abb0::FUN_00b6abb0()
{
    m_sp148 = 0;
    m_f6c = 1.0f;
    m_b7f = true;
    m_b80 = true;
    m_f70 = 0.0f;
    m_b81 = true;
    m_b60 = false;
    m_f124 = 1365.33f;
    m_b61 = false;
    m_b62 = false;
    m_b63 = false;
    m_f11c = 1.0f;
    m_i68 = 0;
    m_f120 = 1.0f;
    m_i64 = 0;
    m_b7d = false;
    m_b7e = false;
    m_b7c = false;
    m_i14c = 0;
    m_b82 = false;
    m_b83 = false;
    m_i84 = 0;
    m_i58 = 0x11;
    m_i1c = 0xe;
}
