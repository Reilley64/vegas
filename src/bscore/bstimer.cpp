// Native timer operations. Original identities are provenance, not offsets.
#include "GameTimerRecord.h"
#include "fnv/game_timer.h"
#include "fnv/decl/FUN_00aa50f0_Class.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <chrono>
#include <thread>
#endif

extern float DAT_011ac3a0;
extern float DAT_011ac3a4;
extern float DAT_011ac3ac;

unsigned int GameTimerTick()
{
#ifdef _WIN32
    return GetTickCount();
#else
    return static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count());
#endif
}

void GameTimerSleep(unsigned int milliseconds)
{
#ifdef _WIN32
    Sleep(milliseconds);
#else
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
#endif
}

// @fnv 0x00aa50f0
void GameTimerRecord::Init(unsigned int tick)
{
    m_ucFirstTimerByte = 0;
    m_fFirstTimerValue = 0.0f;
    m_fSecondTimerValue = 0.0f;
    fTimeSinceScaleStart = 0.0f;
    m_uiFirstTimerValue = 0;
    m_uiSecondTimerValue = tick;
    m_bFirstTimerFlag = false;
    m_bSecondTimerFlag = false;
}

void FUN_00aa50f0_Class::FUN_00aa50f0(unsigned int tick)
{
    Init(tick);
}

// @fnv 0x00aa5040
void GameTimerRecord::Enable()
{
    Resume(GameTimerTick());
}

void GameTimerRecord::Resume(unsigned int tick)
{
    if (m_ucFirstTimerByte && --m_ucFirstTimerByte == 0)
    {
        m_uiFirstTimerValue = tick - m_uiFirstTimerValue;
        m_uiSecondTimerValue = tick - m_uiSecondTimerValue;
    }
}

// @fnv 0x00aa50a0
void GameTimerRecord::FUN_00aa50a0()
{
    Pause(GameTimerTick());
}

void GameTimerRecord::Pause(unsigned int tick)
{
    if (m_ucFirstTimerByte++ == 0)
    {
        m_uiFirstTimerValue = tick - m_uiFirstTimerValue;
        m_uiSecondTimerValue = tick - m_uiSecondTimerValue;
    }
}

// @fnv 0x00771520
void GameTimerRecord::Update()
{
    Update(GameTimerTick(), GameTimerSleep);
}

// @fnv 0x00aa4ee0
void GameTimerRecord::Update(unsigned int tick, void (*sleep)(unsigned int))
{
    unsigned int time = tick - m_uiSecondTimerValue;
    if (m_ucFirstTimerByte)
    {
        fTimeSinceScaleStart = 0.0f;
        return;
    }
    // The accepted sentinel supplier is a zero-initialized double.
    if (m_fFirstTimerValue != 0.0f)
    {
        m_fSecondTimerValue += m_fFirstTimerValue;
        unsigned int wholeTicks = static_cast<unsigned int>(m_fSecondTimerValue);
        m_fSecondTimerValue -= wholeTicks;
        time = m_uiFirstTimerValue + wholeTicks;
        fTimeSinceScaleStart = m_fFirstTimerValue * static_cast<double>(0.001f);
    }
    else
    {
        unsigned int delta = time - m_uiFirstTimerValue;
        if (!delta)
        {
            m_bSecondTimerFlag = true;
            delta = 1;
        }
        else
        {
            m_bSecondTimerFlag = false;
            if (delta > 166)
                delta = 166;
        }
        if (delta < 10)
        {
            sleep(10 - delta);
            delta = 10;
        }
        fTimeSinceScaleStart = delta * static_cast<double>(0.001f);
    }
    m_uiFirstTimerValue = time;
    m_fFourthTimerValue = fTimeSinceScaleStart;
    fTimeSinceScaleStart *= DAT_011ac3a0;
}

// @fnv 0x0086d4c0
void GameTimerRecord::SetFrequency(unsigned int frequency)
{
    m_fFirstTimerValue = frequency ? 1000.0 / frequency : 0.0;
}

// @fnv 0x00aa4db0
void GameTimerRecord::SetMultiplier(float multiplier, bool immediate)
{
    DAT_011ac3a4 = multiplier;
    if (m_bFirstTimerFlag)
    {
        if (immediate)
            DAT_011ac3a0 = DAT_011ac3a4;
    }
    else if (multiplier != DAT_011ac3a0)
    {
        fTimeSinceScaleStart /= DAT_011ac3a0;
        DAT_011ac3a0 = multiplier;
        fTimeSinceScaleStart *= DAT_011ac3a0;
    }
}

// @fnv 0x00aa4e40
void FUN_00aa4e40()
{
    if (DAT_011ac3a0 < DAT_011ac3a4)
    {
        DAT_011ac3a0 = (1.0f + DAT_011ac3ac) * DAT_011ac3a0;
        if (DAT_011ac3a0 > DAT_011ac3a4)
            DAT_011ac3a0 = DAT_011ac3a4;
    }
    else if (DAT_011ac3a0 > DAT_011ac3a4)
    {
        DAT_011ac3a0 = (1.0f - DAT_011ac3ac) * DAT_011ac3a0;
        if (DAT_011ac3a0 < DAT_011ac3a4)
            DAT_011ac3a0 = DAT_011ac3a4;
    }
}

namespace
{
GameTimerRecord& GlobalTimer(unsigned int tick)
{
    // Approved native startup: complete static zero state, then one partial
    // initialization using the startup tick before any timer API consumer.
    static const bool started = [tick] { g_timeGlobal.Init(tick); return true; }();
    (void)started;
    return g_timeGlobal;
}

GameTimerRecord& GlobalTimer()
{
    return GlobalTimer(GameTimerTick());
}
}

namespace fnv::timer
{
void Start(unsigned int startupTick) { (void)GlobalTimer(startupTick); }
unsigned int Time() { return GlobalTimer().m_uiFirstTimerValue; }
unsigned int ElapsedSince(unsigned int timestamp) { return Time() - timestamp; }
unsigned int TimestampFromElapsed(unsigned int elapsed) { return Time() - elapsed; }
float Seconds() { return GlobalTimer().fTimeSinceScaleStart; }
float RealSeconds() { return GlobalTimer().m_fFourthTimerValue; }
float UnmodifiedSeconds() { return GlobalTimer().fTimeSinceScaleStart / DAT_011ac3a0; }
bool SecondsAreZero() { return GlobalTimer().m_bSecondTimerFlag; }
void Update() { Update(GameTimerTick(), GameTimerSleep); }
void Update(unsigned int tick, void (*sleep)(unsigned int)) { GlobalTimer(tick).Update(tick, sleep); }
void Pause() { Pause(GameTimerTick()); }
void Pause(unsigned int tick) { GlobalTimer(tick).Pause(tick); }
void Resume() { Resume(GameTimerTick()); }
void Resume(unsigned int tick) { GlobalTimer(tick).Resume(tick); }
void SetFrequency(unsigned int frequency) { GlobalTimer().SetFrequency(frequency); }
void SetUseGlobalMultiplierTarget(bool useTarget) { GlobalTimer().m_bFirstTimerFlag = useTarget; }
void SetMultiplier(float multiplier, bool immediate) { GlobalTimer().SetMultiplier(multiplier, immediate); }
}

// Legacy entry identities still used by local timers. They delegate to the
// same native record rather than reading a Tile or a load-buffer header.
struct FUN_00aa4db0_shell : GameTimerRecord { void FUN_00aa4db0(float, bool); };
void FUN_00aa4db0_shell::FUN_00aa4db0(float multiplier, bool immediate)
{
    SetMultiplier(multiplier, immediate);
}
struct FUN_00aa4ee0_t : GameTimerRecord { void FUN_00aa4ee0(unsigned int); };
void FUN_00aa4ee0_t::FUN_00aa4ee0(unsigned int tick)
{
    Update(tick, GameTimerSleep);
}

#include "generated/data/bscore/bstimer.inc"
