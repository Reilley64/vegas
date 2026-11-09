#pragma once

#include <cstddef>

// Canonical native owner for the SpeedTree/parser narrow string family.
// Fifteen characters plus the terminator stay in the object. Larger values are
// owned by the production MemoryManager allocation domain.
struct FUN_0044a4c0 {
    using size_type = std::size_t;
    static constexpr size_type small_capacity = 15;

    FUN_0044a4c0() noexcept;
    // 0x0044a4c0
    FUN_0044a4c0(const char* text);
    FUN_0044a4c0(const FUN_0044a4c0& other);
    FUN_0044a4c0(FUN_0044a4c0&& other) noexcept;
    ~FUN_0044a4c0() noexcept;

    FUN_0044a4c0& operator=(const FUN_0044a4c0& other);
    FUN_0044a4c0& operator=(FUN_0044a4c0&& other) noexcept;
    FUN_0044a4c0& operator=(const char* text);

    FUN_0044a4c0& assign(const char* text);
    FUN_0044a4c0& assign(const char* text, size_type count);
    FUN_0044a4c0& assign(const FUN_0044a4c0& other, unsigned int offset, unsigned int count);
    FUN_0044a4c0& Assign(const char* text) { return assign(text); }
    FUN_0044a4c0& AssignChars(const char* text, unsigned int count) { return assign(text, count); }
    FUN_0044a4c0& AssignSubstring(const FUN_0044a4c0& other, unsigned int offset, unsigned int count);

    FUN_0044a4c0& append(const char* text);
    FUN_0044a4c0& append(const char* text, size_type count);
    FUN_0044a4c0& append(const FUN_0044a4c0& other);

    void clear() noexcept;
    void reserve(size_type requested);
    void resize(size_type requested, char value = '\0');
    void swap(FUN_0044a4c0& other) noexcept;

    char* data() noexcept;
    const char* data() const noexcept;
    const char* c_str() const noexcept { return data(); }
    size_type size() const noexcept { return size_; }
    size_type length() const noexcept { return size_; }
    size_type capacity() const noexcept { return capacity_; }
    bool empty() const noexcept { return size_ == 0; }
    bool uses_small_buffer() const noexcept { return capacity_ == small_capacity; }

    int compare(const FUN_0044a4c0& other) const noexcept;
    int compare(const char* text) const noexcept;
    int Compare(const FUN_0044a4c0& other) const noexcept { return compare(other); }
    int ComparePart(unsigned int offset, unsigned int count, const char* text, unsigned int textCount) const;

    // Existing path-normalization entry. Its producer is outside this bounded
    // lifecycle repair; keeping the declaration preserves its real call edge.
    FUN_0044a4c0 FUN_00b09f90();

private:
    union Storage {
        char small[small_capacity + 1];
        char* pointer;
        constexpr Storage() : small{} {}
    } storage_{};
    size_type size_ = 0;
    size_type capacity_ = small_capacity;

    static size_type checked_capacity(size_type required, size_type current);
    static char* allocate(size_type capacity);
    static void release(char* memory) noexcept;
    void retire_heap() noexcept;
    void reset_small() noexcept;
    void move_from(FUN_0044a4c0& other) noexcept;
};

inline bool operator==(const FUN_0044a4c0& left, const FUN_0044a4c0& right) noexcept
{
    return left.compare(right) == 0;
}

inline bool operator!=(const FUN_0044a4c0& left, const FUN_0044a4c0& right) noexcept
{
    return !(left == right);
}

inline bool operator==(const FUN_0044a4c0& left, const char* right) noexcept
{
    return left.compare(right) == 0;
}

inline bool operator!=(const FUN_0044a4c0& left, const char* right) noexcept
{
    return !(left == right);
}

FUN_0044a4c0 FUN_00ad4210(const FUN_0044a4c0& left, const char* right);
FUN_0044a4c0 FUN_00ad42e0(const FUN_0044a4c0& left, const FUN_0044a4c0& right);
