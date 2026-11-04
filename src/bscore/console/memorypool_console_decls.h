// bscore/console/memorypool_console_decls.h: declares MemoryPool
#ifndef MEMORYPOOL_CONSOLE_DECLS_H
#define MEMORYPOOL_CONSOLE_DECLS_H

#include <windows.h>
class MemoryPool
{
  public:
    const char* pDescription;
    char* m_pPoolBase;
    bool CommitPage(unsigned int pageIndex, char*& page);
};
#endif
