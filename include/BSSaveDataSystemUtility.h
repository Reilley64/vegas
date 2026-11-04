// Source layout: BSSaveDataSystemUtility. PC corrections are in generate_headers.py.
#ifndef FNV_BSSAVEDATASYSTEMUTILITY_H
#define FNV_BSSAVEDATASYSTEMUTILITY_H

#include "layout_support.h"
#include "BSSaveDataSystemUtility__SaveDataEntry.h"
class BSSaveDataSystemUtility
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0
    bool bIsActive;   // +0x4
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSSaveDataOperationEntry* m_pOperationContext;                   // +0x8
    BSSaveDataSystemUtility__SaveDataEntry m_kSaveDataEntry;            // +0xC
    BSSaveDataSystemUtility__OPERATION m_eOperation;                    // +0x2C
    BSSaveDataSystemUtility__RESULT m_eResult;                          // +0x30
    BSSaveDataSystemUtility__RESULT m_eSecondResult;                    // +0x34
    BSSaveDataSystemUtility__RESULT m_eThirdResult;                     // +0x38
    BSSaveDataSystemUtility__RESULT_FAILED_REASON m_eFailedReason;      // +0x3C
    unsigned int m_uiResultCount;                                       // +0x40
    void___cdecl__BSSaveDataSystemUtility__RESULT_* m_pResultCallback;  // +0x44
    void Destroy();
};
#endif
