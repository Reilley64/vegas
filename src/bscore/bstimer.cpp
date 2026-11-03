// bscore/bstimer.cpp: free functions (4 functions)

#include <windows.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa4ee0_t.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_011ac000.h"
#include "GameTimerRecord.h"

// The engine tick-count helper lives outside this unit; the PC build resolves

// kernel32 tick count, reached directly through the import address table.

// Decrements the reference count and, when it reaches zero, records elapsed tick counts for two timestamps.
// @fnv 0x00aa5040
void GameTimerRecord::Enable()
{
    if (m_ucFirstTimerByte)
    {
        if (--m_ucFirstTimerByte == 0)
        {
            unsigned int uiTickCount = GetTickCount();
            m_uiFirstTimerValue = uiTickCount - m_uiFirstTimerValue;
            m_uiSecondTimerValue = uiTickCount - m_uiSecondTimerValue;
        }
    }
}

// @fnv 0x00771520
void GameTimerRecord::Update()
{
    reinterpret_cast<::FUN_00aa4ee0_t *>(this)->FUN_00aa4ee0(((unsigned int)(::FUN_00457fe0())));
}

struct FUN_00aa4db0_shell : public GameTimerRecord
{
    void FUN_00aa4db0(float, bool);
};

extern float DAT_011ac3a4;

// @fnv 0x00aa4db0
void FUN_00aa4db0_shell::FUN_00aa4db0(float afMult, bool abNow)
{
    bool bUseGlobal = *(bool*)((char*)this + 0x1c);
    if (bUseGlobal)
    {
        DAT_011ac3a4 = afMult;
        if (abNow)
        {
            DAT_011ac3a0 = DAT_011ac3a4;
        }
    }
    else
    {
        DAT_011ac3a4 = afMult;
        if (afMult == DAT_011ac3a0)
        {
            return;
        }
        *(float*)((char*)this + 0xc) /= DAT_011ac3a0;
        DAT_011ac3a0 = afMult;
        *(float*)((char*)this + 0xc) *= DAT_011ac3a0;
    }
}

extern float DAT_011ac3a4;
extern float DAT_011ac3ac;

// Moves DAT_011ac3a0 toward DAT_011ac3a4 by a fraction of DAT_011ac3ac, clamping so it does not overshoot the target.
// @fnv 0x00aa4e40
void FUN_00aa4e40()
{
    if (DAT_011ac3a0 < DAT_011ac3a4)
    {
        DAT_011ac3a0 = (1.0f + DAT_011ac3ac) * DAT_011ac3a0;
        if (DAT_011ac3a0 > DAT_011ac3a4)
        {
            DAT_011ac3a0 = DAT_011ac3a4;
        }
    }
    else if (DAT_011ac3a0 > DAT_011ac3a4)
    {
        DAT_011ac3a0 = (1.0f - DAT_011ac3ac) * DAT_011ac3a0;
        if (DAT_011ac3a0 < DAT_011ac3a4)
        {
            DAT_011ac3a0 = DAT_011ac3a4;
        }
    }
}
