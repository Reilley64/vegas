// fallout_shared/tesattributes.h: declares BaseFormComponent, TESAttributes
#ifndef FNV_TASK_TESATTRIBUTES_H
#define FNV_TASK_TESATTRIBUTES_H

#include "layout_support.h"

class BaseFormComponent
{
  public:
    BaseFormComponent();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};

class TESAttributes : public BaseFormComponent
{
  public:
    unsigned char cAttribute[7];  // +0x4, 7 bytes
    unsigned char layoutPaddingB[1];

    TESAttributes();
    void InitializeComponent();
};


#endif
