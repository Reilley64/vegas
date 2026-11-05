#pragma once

#include "havok/hkBaseSystem.h"

namespace havok::diagnostics
{
// A diagnostic may call user code which shuts down base publication.
class ErrorReference
{
  public:
    ErrorReference();
    ~ErrorReference();
    ErrorReference(const ErrorReference&) = delete;
    ErrorReference& operator=(const ErrorReference&) = delete;
    havok::base::Error& Get() const { return *error; }
  private:
    havok::base::Error* error;
};

// External debugger boundary. Tests may replace it, never the error owner.
void Breakpoint();
}

void FUN_00cb1750(const char* message);
void ReportReferenceCountError(const havok::base::Reference& object, const char* context);
