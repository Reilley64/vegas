// bsmenu/menu.h: declares MenuValueDescriptor
#ifndef FNV_BSMENU_MENU_H
#define FNV_BSMENU_MENU_H
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_011f6000.h"
#include "menu_decls.h"
class MenuValueDescriptor
{
  public:
    unsigned int m_uiValueId;
    char* m_pName;
    ~MenuValueDescriptor();
};
// @fnv 0x00a0be70
MenuValueDescriptor::~MenuValueDescriptor()
{
    if (m_pName)
    {
        void* pointer = m_pName;
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pointer);
    }
    m_pName = 0;
}
#endif
