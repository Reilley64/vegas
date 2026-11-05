#include "havok/ErrorDiagnostics.h"
#include "fnv/decl/FUN_00cd0a60.h"
#include "check.h"
#include <string>
#include <stdexcept>

#ifdef _WIN32
unsigned long DAT_0126835c;
#endif
namespace havok::diagnostics
{
int breaks = 0;
void Breakpoint() { ++breaks; }
}
void Receive(const char* text, void* user) { *static_cast<std::string*>(user) += text; }

void ReferenceDiagnostic(Checks& checks)
{
    FUN_00cd0a60 memory;
    auto* router = memory.MainInit(0, 1);
    std::string messages;
    fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages);
    auto* files = havok::base::GetFileSystem();
    files->AddReference();
    auto* error = havok::base::GetError();
    const int before = havok::diagnostics::breaks;
    ReportReferenceCountError(*files, "native file-system caller");
    checks.Equal("native reference diagnostic breaks", before + 1, havok::diagnostics::breaks);
    checks.Equal("native reference count is read through complete owner", true,
        messages.find("with ref count of 2 in native file-system caller.") != std::string::npos);
    checks.Equal("reference diagnostic keeps error code", true,
        messages.starts_with(".\\System\\Error\\hkError.cpp(33): [0x2C66F2D8] Error : "));
    checks.Equal("diagnostic temporary reference released", 1, error->GetReferenceCount());
    checks.Equal("diagnostic leaves object references unchanged", 2, files->GetReferenceCount());
    error->SetEnabled(0x2c66f2d8, false);
    messages.clear();
    ReportReferenceCountError(*files, "disabled diagnostic");
    checks.Equal("disabled reference diagnostic does not log", true, messages.empty());
    checks.Equal("disabled reference diagnostic does not break", before + 1, havok::diagnostics::breaks);
    files->RemoveReference();
    ShutdownIfInitialized();
    memory.MainQuit(1);
}

struct ShutdownMessages
{
    std::string text;
    FUN_00cd0a60* memory;
    bool called = false;
    bool refused = false;
};
void ShutdownFromCallback(const char* text, void* user)
{
    auto& state = *static_cast<ShutdownMessages*>(user);
    state.text += text;
    if (!state.called)
    {
        state.called = true;
        ShutdownIfInitialized();
        state.refused = !state.memory->TryMainQuit();
    }
}
void CallbackLifetime(Checks& checks)
{
    FUN_00cd0a60 memory;
    auto* router = memory.MainInit(0, 1);
    ShutdownMessages messages{{}, &memory};
    fnv_00cbbb10::FUN_00cbbb10(router, ShutdownFromCallback, &messages);
    FUN_00cb1750("callback shutdown");
    checks.Equal("actual fatal caller invokes callback", true, messages.called);
    checks.Equal("callback clears base publication", false, havok::base::IsInitialized());
    checks.Equal("temporary error reference prevents allocator destruction", true, messages.refused);
    checks.Equal("fatal caller releases final error reference", true, memory.TryMainQuit());
}
void UninitializedDiagnostic(Checks& checks)
{
    bool rejected = false;
    const int before = havok::diagnostics::breaks;
    try { FUN_00cb1750("no owner"); }
    catch (const std::logic_error&) { rejected = true; }
    checks.Equal("diagnostic requires initialized owners", true, rejected);
    checks.Equal("precondition failure is not a debugger event", before, havok::diagnostics::breaks);
}

int main()
{
    Checks checks("runtime.havok_diagnostic_consumers");
    FUN_00cd0a60 memory;
    auto* router = memory.MainInit(0, 1);
    std::string messages;
    fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages);
    auto* error = havok::base::GetError();
    error->SetEnabled(0x2636fe25, false);
    FUN_00cb1750("disabled fatal");
    checks.Equal("disabled production fatal does not break", 0, havok::diagnostics::breaks);
    checks.Equal("disabled production fatal does not log", true, messages.empty());
    error->SetEnabled(0x2636fe25, true);
    FUN_00cb1750("solver failure");
    checks.Equal("production fatal breaks once", 1, havok::diagnostics::breaks);
    checks.Equal("production fatal keeps source code and line", true,
        messages.starts_with(".\\System\\Error\\hkError.cpp(40): [0x2636FE25] Error : solver failure\n"));
    ShutdownIfInitialized();
    memory.MainQuit(1);
    ReferenceDiagnostic(checks);
    CallbackLifetime(checks);
    UninitializedDiagnostic(checks);
    return checks.ExitCode();
}
