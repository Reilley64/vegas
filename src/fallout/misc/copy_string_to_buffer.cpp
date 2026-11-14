// TaskQueueInterface::CopyStringToBuffer, in a unit of its own so that a
// link that reaches it loads no other code (VEGAS-128). It was defined in
// src/fallout/misc/taskqueueinterface.cpp. The class comes from
// include/fnv/decl/TaskQueueInterface.h, which declares the member with the
// same parameters; the body uses no field of the class.
#include "runtime/crt.h"
#include "fnv/decl/TaskQueueInterface.h"

// @fnv 0x00406d30
void TaskQueueInterface::CopyStringToBuffer(char* apBuffer, unsigned int auiSize, const char* apSource)
{
    fnv::crt::strcpy_s(apBuffer, auiSize, apSource);
}
