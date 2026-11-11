// gamebryo2.2/corelibs/nimain/nishader.cpp: NiShader (10 functions)
// This unit owns NiPointer<T>::operator=(T*), so it takes the template from
// fnv/ni_pointer.h (docs/shared-ni-pointer.md).
#define FNV_SHARED_NI_POINTER

#include <windows.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0109b000.h"
#include "nishader_decls.h"
// @fnv 0x00a8f3d0
bool NiShader::Initialize()
{
    return m_bShaderEnabled = true;
}

#pragma optimize("", off)
// @fnv 0x0066b0d0
template <class T> NiPointer<T>& NiPointer<T>::operator=(T* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            reinterpret_cast<WaitableObject*>(m_pObject)->FUN_00401970();
        m_pObject = object;
        if (m_pObject)
            reinterpret_cast<::FUN_0040f6e0_class *>((reinterpret_cast<WaitableObject*>(m_pObject)))->FUN_0040f6e0();
    }
    return *this;
}
#pragma optimize("", on)

extern int DAT_0109f584;

struct FUN_00a8f4d0_shell
{
    int* volatile vtable;
    unsigned int instanceId;
    char* volatile text;
    FUN_00a8f4d0_shell* FUN_00a8f4d0(unsigned char flags);
};

// @fnv 0x00a8f4d0
FUN_00a8f4d0_shell* FUN_00a8f4d0_shell::FUN_00a8f4d0(unsigned char flags)
{
    vtable = &DAT_0109f584;
    char* stringData = text;
    if (stringData != DAT_0109b220)
        InterlockedDecrement(reinterpret_cast<volatile long*>(stringData - 8));
    vtable = &DAT_0101dce4;
    InterlockedDecrement(&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount)));
    if (flags & 1)
        FUN_00aa1460(this, 20);
    return this;
}

// @fnv 0x00a8f3e0
int FUN_00a8f3e0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    return 0;
}

// @fnv 0x00a8f3f0
int FUN_00a8f3f0(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return 0;
}

// @fnv 0x00a8f400
int FUN_00a8f400(int arg0, int arg1, int arg2, int arg3)
{
    return 0;
}

// @fnv 0x00a8f410
int FUN_00a8f410(int arg0, int arg1)
{
    return 0;
}

// @fnv 0x00a8f420
bool FUN_00a8f420(int a, int b, int c, int d, int e, int f)
{
    return false;
}

// @fnv 0x00a8f430
char FUN_00a8f430(int a, int b, int c, int d, int e)
{
    return 0;
}

// @fnv 0x00c9a420
bool FUN_00c9a420(void* unk00)
{
    return false;
}

// build/units.json gives NiPointer<T>::operator=(T*), one folded body at
// 0x0066b0d0, to this unit, so this unit emits it: for its own element type
// and for each element type that another unit requires. A pointee is forward
// declared with the key the requiring units use. docs/shared-ni-pointer.md
// says which element types are listed.
template NiPointer<NiAVObject>& NiPointer<NiAVObject>::operator=(NiAVObject*);
