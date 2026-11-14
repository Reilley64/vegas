// Unit-private PC declarations from public JohnnyGuitar TESObjectACTI.hpp.
// All component sizes and data members are retained; padding is natural x86 alignment.
#ifndef FNV_PROCESSLISTS_TESOBJECTACTI_H
#define FNV_PROCESSLISTS_TESOBJECTACTI_H

#include "processlists_TESBoundAnimObject.h"
#include "processlists_TESFullName.h"
#include "processlists_TESModelTextureSwap.h"
#include "processlists_TESScriptableForm.h"
#include "processlists_types_BGSDestructibleObjectForm.h"
#include "processlists_BGSOpenCloseForm.h"
struct TESWaterForm;
class BGSTalkingActivator;
class TESSound;
class TESObjectACTI : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public BGSDestructibleObjectForm,
                      public BGSOpenCloseForm
{
  public:
    TESObjectACTI();
    virtual ~TESObjectACTI();
    TESSound* m_pSoundEffect;                  // +0x74
    TESSound* m_pLoopSound;                    // +0x78
    TESSound* pRadioTemplate;                  // +0x7C
    TESWaterForm* m_pWaterForm;                // +0x80
    BGSTalkingActivator* m_pTalkingActivator;  // +0x84
    BSStringT<char> strActivationPrompt;       // +0x88
};
#endif
