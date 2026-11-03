
// src/fallout/interface/animatingtext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/animatingtext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_006ffda0_cls.h"
#include "fnv/decl/FUN_00700270_class.h"
#include "fnv/decl/fnv_00a0a300__TileValueStr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00559000.h"
struct Str6a70
{
    Str6a70& operator=(const char*);
};
struct FUN_00759f20_shell
{
    FUN_00759f20_shell* AssignString(const char* s);
};
// Assigns the string s to this object, calls FUN_006ffda0, and returns this.
// @fnv 0x00759f20
FUN_00759f20_shell* FUN_00759f20_shell::AssignString(const char* apString)
{
    *(Str6a70*)this = apString;
    reinterpret_cast<::FUN_006ffda0_cls *>(this)->FUN_006ffda0();
    return this;
}

struct TwTile
{
    char pad00[8];
    float m_fAlpha;
    void FUN_00a0a270(float fValue, int iPropagate);
};

struct TwTypewriter
{
    char pad00[8];
    TwTile* m_pkText;
    TwTile* m_pkCursor;
    unsigned int m_uiInterval;
    unsigned int m_uiBlinkOn;
    unsigned int m_uiBlinkOff;
    unsigned int m_uiNextTime;
    unsigned int m_uiNextBlink;
    char* m_pString;
    char pad28;
    bool m_bDone;

    bool FUN_007000b0();
    bool FUN_007000d0();
    void FUN_006ffea0();
};

// Advances the typewriter text and cursor blink when the interval elapses, copying characters into the buffer and marking the effect done at the end.
// @fnv 0x006ffea0
void TwTypewriter::FUN_006ffea0()
{
    if (FUN_007000b0() && ((unsigned int)(::FUN_00457fe0())) >= m_uiNextTime && !m_bDone)
    {
        if (m_pkCursor && !FUN_007000d0())
            m_pkCursor->FUN_00a0a270(1.0f, 1);
        if (m_pkCursor && m_pkText && !((const char *)(::FUN_00559450((int *)this))))
            m_pkCursor->FUN_00a0a270(0.0f, 1);
        if (m_pkText && m_pString && reinterpret_cast<::FUN_00700270_class *>(this)->operator==((intptr_t)(m_pString)))
        {
            int iStartTmp = ((int)(::FUN_0044a670(m_pString)));
            unsigned int uiCountZ = m_uiNextTime ? (((unsigned int)(::FUN_00457fe0())) - m_uiNextTime) / m_uiInterval + 1 : 1;
            if (uiCountZ > ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(this)->FUN_004048e0())) - iStartTmp)
            {
                uiCountZ = ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(this)->FUN_004048e0())) - iStartTmp;
                m_bDone = true;
            }
            ::__memcpy(m_pString + iStartTmp, ((const char *)(::FUN_00559450((int *)this))) + iStartTmp, uiCountZ);
            reinterpret_cast<::fnv_00a0a300::TileValueStr *>((m_pkText))->SetString(m_pString, 1);
        }
        else
        {
            m_bDone = true;
        }
        m_uiNextTime = ((unsigned int)(::FUN_00457fe0())) + m_uiInterval;
    }
    if (FUN_007000d0() && ((unsigned int)(::FUN_00457fe0())) >= m_uiNextBlink)
    {
        if (m_pkCursor->m_fAlpha == 1.0)
        {
            m_pkCursor->FUN_00a0a270(0.0f, 1);
            m_uiNextBlink = ((unsigned int)(::FUN_00457fe0())) + m_uiBlinkOff;
        }
        else
        {
            m_pkCursor->FUN_00a0a270(1.0f, 1);
            m_uiNextBlink = ((unsigned int)(::FUN_00457fe0())) + m_uiBlinkOn;
        }
    }
}

// FUN_00700110: thiscall, /Od /GS, guarded float-state updates on member m_0c.
struct ObjC
{
    void FUN_00a0a270(float v, int flag);
};
struct ObjD
{
};


struct FUN_00700110_cls
{
    int unk00;
    int unk04;
    ObjD* m_08;
    ObjC* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    char* m_24;
    unsigned char unk28;
    unsigned char m_29;

    bool FUN_007000b0();
    bool FUN_007000d0();
    void FUN_00700110();
};

// @fnv 0x00700110
void FUN_00700110_cls::FUN_00700110()
{
    if (FUN_007000b0())
    {
        if (m_29 == 0)
        {
            if (m_0c != 0)
            {
                if (!FUN_007000d0())
                {
                    m_0c->FUN_00a0a270(1.0f, 1);
                }
            }
            if (m_0c != 0 && m_08 != 0 && ::FUN_00559450((int *)this) == 0)
            {
                m_0c->FUN_00a0a270(0.0f, 1);
            }
            if (m_08 != 0 && m_24 != 0)
            {
                ::__memcpy((void *)(m_24), (const void *)(::FUN_00559450((int *)this)), ((int)(::FUN_0044a670((const char *)(::FUN_00559450((int *)this))))));
                reinterpret_cast<::fnv_00a0a300::TileValueStr *>((m_08))->SetString((const char *)(m_24), 1);
                m_29 = 1;
            }
        }
    }
}
