#ifndef FNV_BSTASKMANAGER_H
#define FNV_BSTASKMANAGER_H
#include "fnv/decl/FUN_004405b0_S.h"
#include "bstaskmanager_types.h"

// @fnv 0x00440540
IOTask::IOTask(IO_TASK_PRIORITY priority) : BSTask<__int64>()
{
    reinterpret_cast<::FUN_004405b0_S *>(this)->FUN_004405b0((*(unsigned char *)&(priority)));
}
#endif
