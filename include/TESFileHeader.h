#ifndef FNV_FILE_HEADER_H
#define FNV_FILE_HEADER_H
#include "layout_support.h"
#pragma pack(push, 4)
class TESFileHeader
{
  public:
    float m_fRecordValue;                 // +0x0
    unsigned int m_uiFileRecordTotal;     // +0x4
    unsigned int m_uiThirdUnsignedValue;  // +0x8
};
#pragma pack(pop)
#endif
