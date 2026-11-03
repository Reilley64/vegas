#pragma once

namespace AccumTaskDetail { class AccumTaskReceiver; }
namespace AccumTaskDetail { class NiRefObject; }
namespace AccumTaskDetail { class TaskArg1; }
namespace RenderStageWait { struct ThreadStages; }

// 0x00ba3130
namespace RenderStageWait { extern "C" void FUN_00ba3130(::RenderStageWait::ThreadStages *, void *, int, int); }
// 0x00ba3190
namespace fnv_00ba3190 { void FUN_00ba3190(); }
// 0x00ba3390
namespace AccumTaskDetail { void FUN_00ba3390(::AccumTaskDetail::AccumTaskReceiver *, void *, ::AccumTaskDetail::NiRefObject *, ::AccumTaskDetail::TaskArg1 *, ::AccumTaskDetail::NiRefObject *, void *, void *, ::AccumTaskDetail::NiRefObject *, unsigned int, unsigned int, void *); }
// 0x00ba3b10
void SetEffectParamAt(char *, int, unsigned int, int, int);
