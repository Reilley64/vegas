#ifndef FNV_AUTOMEMCONTEXT_H
#define FNV_AUTOMEMCONTEXT_H

// Allocation tags belong to the calling thread. A guard must stay on that
// thread, and nested guards must leave in reverse order of entry.
int GetTlsField();
namespace fnv_00404f30 { void FUN_00404f30(int context); }

class AutoMemContext
{
public:
    AutoMemContext() noexcept = default; // Inactive storage for explicit entry.
    AutoMemContext(int context, bool overridable, const char* file, int line) noexcept;
    explicit AutoMemContext(int context) noexcept;
    ~AutoMemContext() noexcept;

    AutoMemContext(const AutoMemContext&) = delete;
    AutoMemContext& operator=(const AutoMemContext&) = delete;
    AutoMemContext(AutoMemContext&&) = delete;
    AutoMemContext& operator=(AutoMemContext&&) = delete;

    void Enter(int context, bool overridable, const char* file, int line) noexcept;
    void Leave() noexcept;

private:
    int previousContext_ = 0;
    bool active_ = false;
};
#endif
