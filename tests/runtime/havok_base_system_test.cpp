#include "havok/hkBaseSystem.h"
#include "havok/hkMonitorStream.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/decl/FUN_00cd0a60.h"
#include "check.h"
#include <string>
#include <thread>
#include <array>
#ifdef _WIN32
// The external OS TLS index boundary is isolated from unrelated generated owners.
unsigned long DAT_0126835c;
#endif

struct Messages { std::string text; };
void Receive(const char* text, void* user)
{
    static_cast<Messages*>(user)->text += text;
}

class FaultAllocator final : public hkMemoryAllocator
{
  public:
    explicit FaultAllocator(hkMemoryAllocator& real) : real(real) {}
    int failAt = -1;
    bool throws = false;
    int calls = 0;
    int live = 0;
    void* blockAlloc(int bytes) override
    {
        if (calls++ == failAt)
        {
            if (throws)
                throw std::bad_alloc();
            return nullptr;
        }
        void* block = real.blockAlloc(bytes);
        if (block)
            ++live;
        return block;
    }
    void blockFree(void* block, int bytes) override
    {
        if (block)
            --live;
        real.blockFree(block, bytes);
    }
    void getMemoryStatistics(MemoryStatistics& out) override { real.getMemoryStatistics(out); }
    int getAllocatedSize(const void* block, int bytes) override { return real.getAllocatedSize(block, bytes); }
    void resetPeakMemoryStatistics() override { real.resetPeakMemoryStatistics(); }
  private:
    hkMemoryAllocator& real;
};

void Rollback(Checks& checks)
{
    for (bool throws : {false, true})
        for (int failAt = 0; failAt < 3; ++failAt)
        {
            FUN_00cd0a60 memory;
            auto* router = memory.MainInit(0, 1);
            hkMemoryAllocator* heap = router->m_heap;
            hkMemoryAllocator* debug = router->m_debug;
            FaultAllocator faults(*heap);
            router->m_heap = &faults;
            router->m_debug = &faults;
            faults.failAt = failAt;
            faults.throws = throws;
            Messages messages;
            bool failed = false;
            try { failed = fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages) != 0; }
            catch (const std::bad_alloc&) { failed = true; }
            checks.Equal("production allocation failure reported", true, failed);
            checks.Equal("failure publishes no base owner", false, havok::base::IsInitialized());
            checks.Equal("failure publishes no monitor", true, havok::base::GetMonitor() == nullptr);
            checks.Equal("failure releases acquired owners", 0, faults.live);
            checks.Equal("failure restores router TLS", true, FUN_00c85750() == nullptr);
            faults.failAt = -1;
            checks.Equal("same router can retry", 0, fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages));
            ShutdownIfInitialized();
            checks.Equal("retry shutdown releases every owner", 0, faults.live);
            router->m_heap = heap;
            router->m_debug = debug;
            memory.MainQuit(1);
        }
}

class MonitorAllocator final : public hkMemoryAllocator
{
  public:
    explicit MonitorAllocator(hkMemoryAllocator& real) : real(real) {}
    bool failBuffer = false;
    bool throwBuffer = false;
    int requested = 0;
    int adjusted = 0;
    int live = 0;
    int frees = 0;
    int freedBytes = 0;
    void* blockAlloc(int bytes) override
    {
        void* block = real.blockAlloc(bytes);
        if (block)
            ++live;
        return block;
    }
    void blockFree(void* block, int bytes) override
    {
        if (block)
            --live;
        real.blockFree(block, bytes);
    }
    void* bufAlloc(int& bytes) override
    {
        requested = bytes;
        if (throwBuffer)
            throw std::bad_alloc();
        if (failBuffer)
            return nullptr;
        // Exercise the production in/out allocation extent, not a monitor double.
        bytes += 37;
        void* block = real.bufAlloc(bytes);
        adjusted = bytes;
        if (block)
            ++live;
        return block;
    }
    void bufFree(void* block, int bytes) override
    {
        ++frees;
        freedBytes = bytes;
        if (block)
            --live;
        real.bufFree(block, bytes);
    }
    void getMemoryStatistics(MemoryStatistics& out) override { real.getMemoryStatistics(out); }
    int getAllocatedSize(const void* block, int bytes) override { return real.getAllocatedSize(block, bytes); }
    void resetPeakMemoryStatistics() override { real.resetPeakMemoryStatistics(); }
  private:
    hkMemoryAllocator& real;
};

void MonitorResize(Checks& checks)
{
    FUN_00cd0a60 memory;
    auto* router = memory.MainInit(0, 1);
    auto* debug = router->m_debug;
    MonitorAllocator boundary(*debug);
    router->m_debug = &boundary;
    Messages messages;
    fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages);
    auto* monitor = havok::base::GetMonitor();
    checks.Equal("actual entry supplies monitor allocator", true, &monitor->allocator == &boundary);
    ResizeBuffer(monitor, 257);
    checks.Equal("resize requests caller capacity", 257, boundary.requested);
    checks.Equal("resize stores adjusted capacity", boundary.adjusted, monitor->capacity);
    checks.Equal("adjusted storage end", true, monitor->m_08 == monitor->m_00 + boundary.adjusted);
    checks.Equal("reserved monitor tail", true, monitor->m_0c == monitor->m_08 - 0x20);
    char* original = monitor->m_00;
    int originalCapacity = monitor->capacity;
    monitor->m_00[0] = 'a';
    monitor->m_04 = monitor->m_00 + 1;
    for (bool throws : {false, true})
    {
        boundary.failBuffer = !throws;
        boundary.throwBuffer = throws;
        bool rejected = false;
        try { ResizeBuffer(monitor, 1025); }
        catch (const std::bad_alloc&) { rejected = true; }
        checks.Equal("resize allocation failure propagates", true, rejected);
        checks.Equal("failed resize preserves storage", true, monitor->m_00 == original);
        checks.Equal("failed resize preserves position", true, monitor->m_04 == original + 1);
        checks.Equal("failed resize preserves end", true, monitor->m_08 == original + originalCapacity);
        checks.Equal("failed resize preserves tail", true, monitor->m_0c == original + originalCapacity - 0x20);
        checks.Equal("failed resize preserves extent", originalCapacity, monitor->capacity);
        checks.Equal("failed resize preserves content", 'a', monitor->m_00[0]);
        checks.Equal("failed resize does not release buffer", 0, boundary.frees);
    }
    boundary.failBuffer = false;
    boundary.throwBuffer = false;
    ResizeBuffer(monitor, 1025);
    checks.Equal("replacement allocated before old release", true, monitor->m_00 != original);
    checks.Equal("replacement releases old buffer", 1, boundary.frees);
    checks.Equal("replacement returns exact old adjusted extent", originalCapacity, boundary.freedBytes);
    checks.Equal("replacement resets position", true, monitor->m_04 == monitor->m_00);
    checks.Equal("replacement stores adjusted extent", boundary.adjusted, monitor->capacity);
    checks.Equal("replacement updates end", true, monitor->m_08 == monitor->m_00 + boundary.adjusted);
    checks.Equal("replacement updates reserved tail", true, monitor->m_0c == monitor->m_08 - 0x20);
    ResizeBuffer(monitor, 1);
    checks.Equal("small resize reserves minimum tail", 0x20, boundary.requested);
    checks.Equal("small resize keeps tail in storage", true, monitor->m_0c >= monitor->m_00);
    const int lastCapacity = monitor->capacity;
    ShutdownIfInitialized();
    checks.Equal("shutdown returns exact final extent", lastCapacity, boundary.freedBytes);
    checks.Equal("shutdown frees monitor owner and buffer", 0, boundary.live);
    router->m_debug = debug;
    checks.Equal("monitor release permits allocator shutdown", true, memory.TryMainQuit());
}

void RetainedReferences(Checks& checks)
{
    FUN_00cd0a60 memory;
    hkMemoryRouter* router = memory.MainInit(0, 1);
    Messages messages;
    fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages);
    auto* error = havok::base::GetError();
    auto* files = havok::base::GetFileSystem();
    error->AddReference();
    files->AddReference();
    std::array<std::thread, 4> users;
    for (auto& user : users)
        user = std::thread([error] {
            for (int i = 0; i < 1000; ++i)
            {
                error->AddReference();
                error->RemoveReference();
            }
        });
    for (auto& user : users)
        user.join();
    checks.Equal("concurrent native reference lifetime", 2, error->GetReferenceCount());
    checks.Equal("live base prevents allocator shutdown", false, memory.TryMainQuit());
    ShutdownIfInitialized();
    checks.Equal("base releases its error reference", 1, error->GetReferenceCount());
    checks.Equal("base releases its file-system reference", 1, files->GetReferenceCount());
    checks.Equal("retained owners prevent allocator shutdown", false, memory.TryMainQuit());
    error->Message(0, 0, "after shutdown", nullptr, 0);
    checks.Equal("retained callback survives TLS clear", std::string("after shutdown\n"), messages.text);
    error->RemoveReference();
    files->RemoveReference();
    checks.Equal("last reference permits memory shutdown", true, memory.TryMainQuit());
}


void ErrorPolicies(Checks& checks)
{
    FUN_00cd0a60 memory;
    auto* router = memory.MainInit(0, 1);
    Messages messages;
    fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages);
    auto* error = havok::base::GetError();
    error->SetEnabled(42, false);
    error->BeginSection(42, "disabled section");
    checks.Equal("disabled section does not break", 0,
        error->Message(3, -1, "hidden", "test.cpp", 7));
    checks.Equal("disabled message has no callback", true, messages.text.empty());
    error->EnableAll();
    error->Message(1, -1, "visible", "test.cpp", 7);
    checks.Equal("section supplies warning id", std::string("test.cpp(7): [0x0000002A] Warning : visible\n"), messages.text);
    error->EndSection();
    messages.text.clear();
    checks.Equal("assert requests break", 1, error->Message(2, 0, "assertion", nullptr, 0));
    checks.Equal("assert callback retains text", true, messages.text.starts_with("assertion\n"));
    messages.text.clear();
    std::string longMessage(3000, 'x');
    error->Message(0, 0, longMessage.c_str(), nullptr, 0);
    checks.Equal("bounded error text", std::size_t(2047), messages.text.size());
    ShutdownIfInitialized();
    memory.MainQuit(1);
}

void RepeatedInitialization(Checks& checks)
{
    FUN_00cd0a60 memory;
    auto* router = memory.MainInit(0, 1);
    Messages first;
    Messages second;
    for (int i = 0; i < 3; ++i)
    {
        checks.Equal("base initializes on retained memory", 0,
            fnv_00cbbb10::FUN_00cbbb10(router, Receive, &first));
        auto* error = havok::base::GetError();
        checks.Equal("repeated init succeeds", 0,
            fnv_00cbbb10::FUN_00cbbb10(router, Receive, &second));
        checks.Equal("repeated init preserves owner", true, error == havok::base::GetError());
        error->Message(0, 0, "once", nullptr, 0);
        checks.Equal("repeated init preserves callback data", true, second.text.empty());
        ShutdownIfInitialized();
        ShutdownIfInitialized();
        checks.Equal("repeat shutdown clears TLS", true, FUN_00c85750() == nullptr);
    }
    checks.Equal("three initialization lifetimes", std::string("once\nonce\nonce\n"), first.text);
    memory.MainQuit(1);
}

void FileLifetime(Checks& checks, const char* path)
{
    FUN_00cd0a60 memory;
    auto* router = memory.MainInit(0, 1);
    Messages messages;
    fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages);
    auto* files = havok::base::GetFileSystem();
    auto* writer = files->OpenWriter(path);
    checks.Equal("native file owner opens writer", true, writer != nullptr);
    if (!writer)
        return;
    checks.Equal("native buffered write", 5, writer->Write("hello", 5));
    writer->RemoveReference();
    auto* reader = files->OpenReader(path);
    checks.Equal("native file owner opens reader", true, reader != nullptr);
    if (!reader)
        return;
    ShutdownIfInitialized();
    checks.Equal("open file prevents allocator destruction", false, memory.TryMainQuit());
    char text[6]{};
    checks.Equal("file survives base shutdown", 5, reader->Read(text, 5));
    checks.Equal("file content", std::string("hello"), std::string(text));
    checks.Equal("native file position", 5L, reader->Tell());
    checks.Equal("native seek returns source success value", false, reader->Seek(0, SEEK_SET));
    checks.Equal("failed seek returns source failure value", true, reader->Seek(-1, SEEK_SET));
    reader->RemoveReference();
    checks.Equal("file release permits allocator shutdown", true, memory.TryMainQuit());
    std::remove(path);
}

void FailedWriter(Checks& checks, const char* path)
{
    FUN_00cd0a60 memory;
    auto* router = memory.MainInit(0, 1);
    Messages messages;
    fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages);
    auto* writer = havok::base::GetFileSystem()->OpenWriter(path);
    checks.Equal("failed-writer fixture opens", true, writer != nullptr);
    if (writer)
    {
        checks.Equal("zero write returns zero", 0, writer->Write("", 0));
        checks.Equal("zero write invalidates writer", false, writer->IsOk());
        checks.Equal("closed writer rejects later write", 0, writer->Write("late", 4));
        char text[4]{};
        checks.Equal("closed file rejects read", 0, writer->Read(text, 4));
        checks.Equal("closed file rejects seek", true, writer->Seek(0, SEEK_SET));
        checks.Equal("closed file has no position", -1L, writer->Tell());
        writer->RemoveReference();
        auto* reader = havok::base::GetFileSystem()->OpenReader(path);
        checks.Equal("closed writer content fixture opens", true, reader != nullptr);
        if (reader)
        {
            checks.Equal("failed writer never accepts later data", 0, reader->Read(text, 4));
            reader->RemoveReference();
        }
    }
    ShutdownIfInitialized();
    checks.Equal("failed writer release frees allocator", true, memory.TryMainQuit());
    std::remove(path);
}

int main(int argc, char** argv)
{
    Checks checks("runtime.havok_base_system");
    FUN_00cd0a60 memory;
    hkMemoryRouter* router = memory.MainInit(0, 1);
    Messages messages;
    checks.Equal("actual base caller initializes", 0,
        fnv_00cbbb10::FUN_00cbbb10(router, Receive, &messages));
    auto* monitor = havok::base::GetMonitor();
    checks.Equal("monitor published by actual caller", true, monitor != nullptr);
    ResizeBuffer(monitor, 257);
    checks.Equal("monitor has writable storage", true, monitor->m_00 != nullptr);
    auto* error = havok::base::GetError();
    checks.Equal("native error published", true, error != nullptr);
    checks.Equal("report does not break", 0, error->Message(0, 0, "hello", nullptr, 0));
    checks.Equal("typed callback receives user data", std::string("hello\n"), messages.text);
    ShutdownIfInitialized();
    checks.Equal("native owners cleared", false, havok::base::IsInitialized());
    checks.Equal("monitor released before allocator", true, havok::base::GetMonitor() == nullptr);
    memory.MainQuit(1);
    Rollback(checks);
    MonitorResize(checks);
    RetainedReferences(checks);
    ErrorPolicies(checks);
    RepeatedInitialization(checks);
    if (argc == 2)
    {
        FileLifetime(checks, argv[1]);
        FailedWriter(checks, argv[1]);
    }
    else
        checks.Fail("file-system seam", "a scratch output path is required");
    return checks.ExitCode();
}
