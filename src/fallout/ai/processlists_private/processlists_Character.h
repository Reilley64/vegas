// Source layout: Character. PC corrections are in generate_headers.py.
#ifndef FNV_CHARACTER_H
#define FNV_CHARACTER_H

#include "processlists_layout_support.h"
#include "processlists_Actor.h"
class Character : public Actor
{
  public:
    BipedAnim* pBiped;      // +0x1B4
    float m_fFirstResetValue;     // +0x1B8
    float m_fSecondValue;  // +0x1BC
    bool m_bTrespassing;    // +0x1C0
    bool m_bActorGuard;     // +0x1C1
    unsigned char layoutPadding1C2[2];
    float m_fThirdValue;  // +0x1C4
    virtual void Unk_137(void);
    virtual void Unk_138(void);
};
#endif
