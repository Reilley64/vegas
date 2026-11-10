#pragma once

struct ScrapHeapBuffer
{
  public:
    char* m_pHeapBase;
    char* m_pCurrentPosition;
    char* m_pBufferLimit;
    void* m_pBufferHeader;
    unsigned int m_uiBufferSize;

    ScrapHeapBuffer();
    ~ScrapHeapBuffer();
    void Init(unsigned int size);
};
