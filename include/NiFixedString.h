#ifndef FNV_NIFIXEDSTRING_H
#define FNV_NIFIXEDSTRING_H

#include <cstdint>

class NiGlobalStringTable;

// One native handle type. The named aliases are source-observed names for the
// same handle slot; none is an independent legacy layout.
class NiFixedString
{
public:
    union {
        char* m_kHandle;
        char* data;
        char* text;
        char* value;
        char* m_pString;
        char* m_pcString;
        char* m_psz;
        char* m_str;
        char* m_sString;
        char* m_data;
        void* m_00;
        std::uintptr_t f0;
        std::uintptr_t v;
    };

    NiFixedString() noexcept;
    NiFixedString(const char* text);
    NiFixedString(const NiFixedString& other);
    NiFixedString(NiFixedString&& other) noexcept;
    ~NiFixedString() noexcept;

    NiFixedString& operator=(const char* text);
    NiFixedString& operator=(const NiFixedString& other);
    NiFixedString& operator=(NiFixedString&& other) noexcept;

    operator const char*() const noexcept { return m_kHandle; }
    operator const void*() const noexcept { return m_kHandle; }
    bool operator==(const char* other) const noexcept;
    bool operator==(const NiFixedString& other) const noexcept { return m_kHandle == other.m_kHandle; }
    bool operator!=(const NiFixedString& other) const noexcept { return !(*this == other); }

    bool Exists() const noexcept;
    int IsNotEmpty() const noexcept;
    unsigned int GetLength() const noexcept;
    unsigned int GetRefCount() const noexcept;
    bool Equals(char* other) const noexcept;
    bool EqualsNoCase(char* other) const noexcept;
    bool Contains(char* other) const noexcept;
    bool HasSuffix(char* other) const noexcept;
    void Init() noexcept;
    void Assign(const char* text);
    void Clear() noexcept;
    void Release() noexcept;
    void AssignInternedString(const NiFixedString& text);

    // Existing source entries retained outside this bounded owner.
    void* FUN_004b9900(unsigned int);
    void FUN_00761760(int*, unsigned int);
};

static_assert(sizeof(NiFixedString) == sizeof(char*));

#endif
