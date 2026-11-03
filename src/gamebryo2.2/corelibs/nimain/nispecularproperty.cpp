
// src/gamebryo2.2/corelibs/nimain/nispecularproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nispecularproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00a62a40_this.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a5d000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_011f5000.h"
extern int DAT_010a02e4;
struct BSFadeNode
{
    static void* __cdecl operator new(size_t);
};
struct NiObject : BSFadeNode
{
};
struct CloningProcess
{
};
struct NiProperty : NiObject
{
    int _v;
    char _d[20];
    NiProperty() throw();
};
struct NiCullingProperty
{
};
struct NiSpecularProperty : NiProperty
{
    unsigned short m_uiObjectFlags;
    NiSpecularProperty() throw()
    {
        *(void**)this = (void*)&DAT_010a02e4;
        m_uiObjectFlags = 0;
    }
    NiObject* FUN_00a95110(CloningProcess&);
};
// @fnv 0x00a95110
NiObject* NiSpecularProperty::FUN_00a95110(CloningProcess& kCloning)
{
    NiSpecularProperty* pkObject = new NiSpecularProperty;
    ::FUN_00a5d7a0();
    pkObject->m_uiObjectFlags = m_uiObjectFlags;
    return pkObject;
}



struct FUN_00a951f0_list
{
    int unk00;
    int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
};

struct FUN_00a951f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char m_18;
    void FUN_00a951f0(FUN_00a951f0_list* list);
};

// @fnv 0x00a951f0
void FUN_00a951f0_cls::FUN_00a951f0(FUN_00a951f0_list* list)
{
    reinterpret_cast<::FUN_00a62a40_this *>(this)->AppendString((::StrArr *)(list));
    unsigned int item = ((unsigned int)(::FUN_00a7d330((const char *)((*reinterpret_cast<unsigned int *>(&::g_011f5ecc))))));
    unsigned int count = list->m_0a;
    if (count >= list->m_08)
        reinterpret_cast<::ViewerStrings *>((list))->SetSize(count + list->m_0e);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((list))->SetAt(count, (*(char * *)(&item)));

    unsigned char ucSpecFlag = m_18;
    ucSpecFlag &= 1;
    *(volatile unsigned char*)&item = ucSpecFlag;
    unsigned int result = ((unsigned int)(::FUN_00a7d370("m_bSpec", *(volatile unsigned int*)&item)));
    *(volatile unsigned int*)&item = result;

    count = list->m_0a;
    if (count >= list->m_08)
        reinterpret_cast<::ViewerStrings *>((list))->SetSize(count + list->m_0e);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((list))->SetAt(count, (*(char * *)(&item)));
}
