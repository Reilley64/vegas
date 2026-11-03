#ifndef FNV_FORM_H
#define FNV_FORM_H
#include "layout_support.h"
#pragma pack(push, 4)
class FormRecordHeader
{
  public:
    unsigned int form;                    // +0x0
    unsigned int length;                  // +0x4
    unsigned int flags;                   // +0x8
    unsigned int iFormID;                 // +0xC
    unsigned int m_uiVersionControlInfo;  // +0x10
    unsigned short m_usFormVersion;       // +0x14
    unsigned short m_usHeaderUnknown;     // +0x16
};
#pragma pack(pop)
#endif
