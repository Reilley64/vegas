#pragma once

class hkMemoryAllocator;

class InlineStorageString
{
  public:
    InlineStorageString(const char* first = nullptr, const char* second = nullptr,
                        const char* third = nullptr, const char* fourth = nullptr,
                        const char* fifth = nullptr, const char* sixth = nullptr);
    InlineStorageString(const InlineStorageString& other);
    InlineStorageString(const char* text, int length);
    ~InlineStorageString();
    InlineStorageString& operator=(const InlineStorageString& other);
    InlineStorageString& operator=(const char* text);
    InlineStorageString& operator+=(const char* text);

    const char* cString() const { return m_data; }
    int getLength() const { return m_iElementCount - 1; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AppendStrings(const char*, const char*, const char*, const char*, const char*, const char*);
    void Append(const char* text, int length = -1);
    void Clear();
    void AssignStrings(const char*, const char*, const char*, const char*, const char*, const char*);
    void TrimToDirectory();
    int FUN_00d62190(const char* from, const char* to, int replaceAll);

    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_kStorage[128];

  private:
    void Reserve(int count);
    void SetLength(int length);
    hkMemoryAllocator* allocator = nullptr;
};

const char* FUN_00d2b360(const char* path, InlineStorageString* result);
