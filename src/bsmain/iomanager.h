
#include "fnv/decl/FUN_0043cc80_shell.h"
#include "fnv/decl/FUN_0043d6b0_shell.h"
#include "fnv/decl/FUN_0043dbb0_shell.h"
#include "fnv/decl/FUN_0043dc30_shell.h"
#include "fnv/decl/fnv_0043dc10__FUN_0043dc10_shell.h"
#include "fnv/symbols_01202000.h"
#include "iomanager_decls.h"
// @fnv 0x0043d690
void IOManager::SubmitTask()
{
    reinterpret_cast<::FUN_0043d6b0_shell *>((::DAT_01202d98))->FUN_0043d6b0((::QHeadLocal *)(::IOManager *)(this));
}
// @fnv 0x0043db70
void IOTask::GenerateKey()
{
    reinterpret_cast<::FUN_0043dbb0_shell *>(this)->SetRequestParams(3, reinterpret_cast<::FUN_0043dc30_shell *>(this)->InitScriptRunLockTask(), reinterpret_cast<::FUN_0043cc80_shell *>(this)->FUN_0043cc80(), reinterpret_cast<::fnv_0043dc10::FUN_0043dc10_shell *>(this)->FUN_0043dc10());
}
