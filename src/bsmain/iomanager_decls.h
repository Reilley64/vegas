// bsmain/iomanager_decls.h: declares IOManager, IOTask
#ifndef IOMANAGER_DECLS_H
#define IOMANAGER_DECLS_H

#include "fnv/decl/FUN_0043cc80_shell.h"
#include "fnv/decl/FUN_0043d6b0_shell.h"
#include "fnv/decl/FUN_0043dbb0_shell.h"
#include "fnv/decl/FUN_0043dc30_shell.h"
#include "fnv/decl/fnv_0043dc10__FUN_0043dc10_shell.h"
#include "fnv/symbols_01202000.h"
struct IOManager
{
  public:
    void SubmitTask();
};
class IOTask
{
  public:
    void GenerateKey();
};
#endif
